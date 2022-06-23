//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SGSimInterface.h"

using namespace std;

Define_Module(SGSimInterface);

void SGSimInterface::initialize()
{

    // Build CLSID

    hr = CLSIDFromString(clsidStr, &clsid);
    if(FAILED(hr)) {
        cerr << "SGSimInterface: failed to create CLSID" << endl;
        endSimulation();
    }


    // Build IID

    if(FAILED(IIDFromString(iidIDSSStr, &iidIDSS))) {
        cerr << "SGSimInterface: failed to create iidDSS" << endl;
        endSimulation();
    }


    // Initialize COM

    if(S_OK != CoInitialize(0)) {
        cerr << "SGSimInterface: couldnt initliaze COM" << endl;
        endSimulation();
    }


    // get pointers to IDSS interface and IDs of functions, poperties and other interfaces in IDSS
    // i.e. Text, ActiveCircuit, AllowForms

    if(S_OK != CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, iidIDSS, (LPVOID*)&pIDSS)) {
        cerr << "SGSimInterface: pointer to IDSS not retrieved!" << endl;
        endSimulation();
    }

    if(S_OK != pIDSS->GetIDsOfNames(IID_NULL, &start, 1, LOCALE_USER_DEFAULT, &startID)) {
        cerr << "SGSimInterface: couldnt find function Start in IDSS" << endl;
        endSimulation();
    }

    hr = pIDSS->GetIDsOfNames(IID_NULL, &activeCircuit, 1, LOCALE_USER_DEFAULT, &activeCircuitID);

    if(S_OK != hr) {
        cerr << "SGSimInterface: couldnt find property ActiveCircuit in IDSS" << endl;
        cerr << hr << endl;
        endSimulation();
    }

    if(S_OK != pIDSS->GetIDsOfNames(IID_NULL, &text, 1, LOCALE_USER_DEFAULT, &textID)) {
        cerr << "SGSimInterface: couldnt find property Text in IDSS" << endl;
        endSimulation();
    }

    if(S_OK != pIDSS->GetIDsOfNames(IID_NULL, &allowForms, 1, LOCALE_USER_DEFAULT, &allowFormsID)) {
        cerr << "SGSimInterface: couldnt find property AllowForms in IDSS" << endl;
        endSimulation();
    }



    // initializing stuff

    if(invokeStart() != 0) {
        cerr << "SGSimInterface: unable to invoke function start" << endl;
        endSimulation();
    }


    // get pointer to IText interface and its properties
    // i.e. Command, Result

    pIText = getDispInterfaceFromIDSS(textID);
    if(pIText == NULL) {
        cerr << "SGSimInterface: unable to retrieve IText" << endl;
        endSimulation();
    }
    if(S_OK != pIText->GetIDsOfNames(IID_NULL, &command, 1, LOCALE_USER_DEFAULT, &commandID)) {
        cerr << "SGSimInterface: couldnt find property Command in IText" << endl;
        endSimulation();
    }
    if(S_OK != pIText->GetIDsOfNames(IID_NULL, &result, 1, LOCALE_USER_DEFAULT, &resultID)) {
        cerr << "SGSimInterface: couldnt find property Command in IText" << endl;
        endSimulation();
    }


    // get pointer to ICircuit and its properties
    // i.e. Losses, Linelosses, ISolution, ActiveBus, ActiveCktElement, SetActiveElement

    pICircuit = getDispInterfaceFromIDSS(activeCircuitID);
    if(pICircuit == NULL) {
        cerr << "SGSimInterface: unable to retrieve ICircuit" << endl;
        endSimulation();
    }
    if(S_OK != pICircuit->GetIDsOfNames(IID_NULL, &losses, 1, LOCALE_USER_DEFAULT, &lossesID)) {
        cerr << "SGSimInterface: couldnt find property Losses in ICircuit" << endl;
        endSimulation();
    }
    if(S_OK != pICircuit->GetIDsOfNames(IID_NULL, &lineLosses, 1, LOCALE_USER_DEFAULT, &lineLossesID)) {
        cerr << "SGSimInterface: couldnt find property Losses in ICircuit" << endl;
        endSimulation();
    }
    if(S_OK != pICircuit->GetIDsOfNames(IID_NULL, &solution, 1, LOCALE_USER_DEFAULT, &solutionID)) {
        cerr << "SGSimInterface: couldnt find property Solution in ICircuit" << endl;
        endSimulation();
    }
    if(S_OK != pICircuit->GetIDsOfNames(IID_NULL, &activeBus, 1, LOCALE_USER_DEFAULT, &activeBusID)) {
        cerr << "SGSimInterface: couldnt find property ActiveBus in ICircuit" << endl;
        endSimulation();
    }
    if(S_OK != pICircuit->GetIDsOfNames(IID_NULL, &activeCktElement, 1, LOCALE_USER_DEFAULT, &activeCktElementID)) {
        cerr << "SGSimInterface: couldnt find property ActiveCktElement in ICircuit" << endl;
        endSimulation();
    }

    if(S_OK != pICircuit->GetIDsOfNames(IID_NULL, &setActiveElement, 1, LOCALE_USER_DEFAULT, &setActiveElementID)) {
        cerr << "SGSimInterface: couldnt find function SetActiveElement in ICircuit" << endl;
        endSimulation();
    }


    // get pointer to ICktElement and its properties
    // i.e. Voltages, Currents, Powers

    pICktElement = getDispInterfaceFromICircuit(activeCktElementID);
    if(pICircuit == NULL) {
        cerr << "SGSimInterface: unable to retrieve ICktElement" << endl;
        endSimulation();
    }
    if(S_OK != pICktElement->GetIDsOfNames(IID_NULL, &voltages, 1, LOCALE_USER_DEFAULT, &voltagesID)) {
        cerr << "SGSimInterface: couldnt find property Voltages in ICktElement" << endl;
        endSimulation();
    }
    if(S_OK != pICktElement->GetIDsOfNames(IID_NULL, &currents, 1, LOCALE_USER_DEFAULT, &currentsID)) {
        cerr << "SGSimInterface: couldnt find property Currents in ICktElement" << endl;
        endSimulation();
    }
    if(S_OK != pICktElement->GetIDsOfNames(IID_NULL, &powers, 1, LOCALE_USER_DEFAULT, &powersID)) {
        cerr << "SGSimInterface: couldnt find property Powers in ICktElement" << endl;
        endSimulation();
    }

    // get pointer to ISolution

    pISolution = getDispInterfaceFromICircuit(solutionID);
    if(pISolution == NULL) {
        cerr << "SGSimInterface: unable to retrieve ISolution" << endl;
        endSimulation();
    }
}

void SGSimInterface::runCommand(char *cmd)
{
    if(prohibitForms() != 0) {
        cerr << "SGSimInterface: unable to invoke function prohibitForms" << endl;
        endSimulation();
    }
    else if (setCommand(cmd) != 0) {
        cerr << "SGSimInterface: unable to invoke function setCommand" << endl;
        endSimulation();
    }
    else {
        cout << "SGSimInterface: successfully ran command >>>  " << cmd << "  <<<" << endl;
    }
}

double SGSimInterface::getTotalLosses() {

    double* losses;

    if(prohibitForms() != 0) {
        cerr << "SGSimInterface: unable to invoke function prohibitForms" << endl;
        endSimulation();
    }
    clearParameters();
    params.cNamedArgs = 0;
    params.cArgs = 0;


    // get Losses from ICircuit

    if(S_OK == pICircuit->Invoke(lossesID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params, &returnValues , &excepinfo, &nArgErr)) {

        SAFEARRAY * safe = returnValues.parray;
        VARTYPE vt;
        SafeArrayGetVartype(safe, &vt);
        void* pData;
        if(vt == VT_R8) {
            SafeArrayAccessData(safe, &pData);
            SafeArrayUnaccessData(safe);
        }

        losses = (double *) pData;

        cout << "TotalLosses: " << *losses << endl;

        return *losses;
    }
    else {
        cerr << "SGSimInterface: unable to retrieve Losses from ICircuit";
        endSimulation();
        return -1;
    }
}

double SGSimInterface::getLineLosses() {

    double* lineLosses;
    if(prohibitForms() != 0) {
        cerr << "SGSimInterface: unable to invoke function prohibitForms" << endl;
        endSimulation();
    }
    clearParameters();
    params.cNamedArgs = 0;
    params.cArgs = 0;


    // get LineLosses from ICircuit

    if(S_OK == pICircuit->Invoke(lineLossesID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params, &returnValues , &excepinfo, &nArgErr)) {

        SAFEARRAY * safe = returnValues.parray;
        VARTYPE vt;
        SafeArrayGetVartype(safe, &vt);
        void* pData;
        if(vt == VT_R8) {
            SafeArrayAccessData(safe, &pData);
            SafeArrayUnaccessData(safe);
        }

        lineLosses = (double *) pData;

        return *lineLosses;
    }
    else {
        cerr << "SGSimInterface: unable to retrieve LineLosses from ICircuit";
        endSimulation();
        return -1;
    }
}

double SGSimInterface::getEnergyActiveObject(char* activeObject) {

    double energyv = 0;

    if(prohibitForms() != 0) {
        cerr << "SGSimInterface: unable to invoke function prohibitForms" << endl;
        endSimulation();
    }
    else if (invokeSetActiveElement(activeObject) != 0) {
        cerr << "SGSimInterface: unable to invoke function SetActiveObject for " << activeObject << endl;
        endSimulation();
    }


    // build command for to set with activeObject

    string str = string("? Storage.") + activeObject + ".kWhstored";
    char *cmd = new char[str.length() + 1];
    strcpy(cmd, str.c_str());
    cout << "after stringcopy: " << cmd << endl;


    // set command and get result

    if (setCommand(cmd) != 0) {
        cerr << "SGSimInterface: unable to invoke function setCommand" << endl;
        endSimulation();
    }
    else {
        cout << "SGSimInterface:  set command to >> " << cmd << endl;

        string result = getResult();

        cout << "SGSimInterface: result of getEnergyActiveObject() = " << result.c_str() << endl;

        energyv = atof(result.c_str());

    }

    return energyv;
}

AllValues SGSimInterface::getValuesActiveObject(char * activeObject){

    if(prohibitForms() != 0) {
        cerr << "SGSimInterface: unable to invoke function prohibitForms" << endl;
        endSimulation();
    }
    else if (invokeSetActiveElement(activeObject) != 0) {
        cerr << "SGSimInterface: unable to invoke function SetActiveObject for " << activeObject << endl;
        endSimulation();
    }


    // update pointer of ICktElement dispatch interface to ActiveCktElement property in ICircuit

    pICktElement = getDispInterfaceFromICircuit(activeCktElementID);
    if(pICktElement == NULL) {
        cerr << "SGSimInterface: unable to retrieve ISolution" << endl;
        endSimulation();
    }

    double * voltages = getPropertyFromICktElement(voltagesID);
    double * currents = getPropertyFromICktElement(currentsID);
    double * powers = getPropertyFromICktElement(powersID);

    AllValues allValues;

    allValues.V1r = voltages[0];
    allValues.V1i = voltages[1];
    allValues.V2r = voltages[2];
    allValues.V2i = voltages[3];
    allValues.V3r = voltages[4];
    allValues.V3i = voltages[5];
    allValues.P1 = powers[0];
    allValues.Q1 = powers[1];
    allValues.P2 = powers[2];
    allValues.Q2 = powers[3];
    allValues.P3 = powers[4];
    allValues.Q3 = powers[5];
    allValues.I1r = currents[0];
    allValues.I1i = currents[1];
    allValues.I2r = currents[2];
    allValues.I2i = currents[3];
    allValues.I3r = currents[4];
    allValues.I3i = currents[5];

    return allValues;
}

int SGSimInterface::invokeStart()
{
    clearParameters();
    params.rgvarg = Arguments;
    params.cNamedArgs = 0;
    params.cArgs = 1;
    params.rgvarg[0].vt = VT_INT;
    params.rgvarg[0].intVal = 0;
    if(S_OK == pIDSS->Invoke(startID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &returnValues , &excepinfo, &nArgErr)) {
        return 0;
    }
    else {
        return -1;
    }
}

int SGSimInterface::invokeSetActiveElement(char* activeObject) {

    clearParameters();
    params.rgvarg = Arguments;
    params.cNamedArgs = 0;
    params.cArgs = 1;

    // create wchar* from parameter activeObject

    WCHAR *wactiveObject;
    int nChars = MultiByteToWideChar(CP_ACP, 0, activeObject, -1, NULL, 0);
    wactiveObject = new WCHAR[nChars];
    MultiByteToWideChar(CP_ACP, 0, activeObject, -1, (LPWSTR)wactiveObject, nChars);


    // create BSTR from wchar*

    BSTR wactiveObject2 = SysAllocString(wactiveObject);                    // Need to free string again? SysAllocFree()

    params.rgvarg[0].vt = VT_BSTR;
    params.rgvarg[0].bstrVal = wactiveObject2;
    if(S_OK == pICircuit->Invoke(setActiveElementID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &returnValues , &excepinfo, &nArgErr)) {
        return 0;
    }
    else {
        return -1;
    }
}

IDispatch* SGSimInterface::getDispInterfaceFromIDSS(DISPID dispid) {
    clearParameters();
    params.cNamedArgs = 0;
    params.cArgs = 0;
    if(S_OK == pIDSS->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params, &returnValues , &excepinfo, &nArgErr)) {
        return returnValues.pdispVal;
    }
    else {
        return NULL;
    }
}

IDispatch* SGSimInterface::getDispInterfaceFromICircuit(DISPID dispid) {
    clearParameters();
    params.cNamedArgs = 0;
    params.cArgs = 0;
    if(S_OK == pICircuit->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params, &returnValues , &excepinfo, &nArgErr)) {
        return returnValues.pdispVal;
    }
    else {
        return NULL;
    }
}

string SGSimInterface::getResult() {

    clearParameters();
    params.cNamedArgs = 0;
    params.cArgs = 0;

    if(S_OK == pIText->Invoke(resultID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params, &returnValues , &excepinfo, &nArgErr)) {

        // turn BSTR into WCHAR*

        BSTR resultBSTR = returnValues.bstrVal;
        int size = SysStringLen(resultBSTR) +1;
        wchar_t * wstr = new wchar_t[size];
        wcscpy(wstr, resultBSTR);


        // turn WCHAR* into string

        int sizeNeeded = WideCharToMultiByte(CP_ACP, 0, &wstr[0], size, NULL, 0, NULL, NULL);           // "size" correct??
        string result(sizeNeeded, 0);
        WideCharToMultiByte(CP_ACP, 0, &wstr[0], size, &result[0], sizeNeeded, NULL, NULL);

        return result;
    }
    else {
        cerr << "SGSimInterface: unable to retrieve Result from IText";
        endSimulation();
        return string();
    }
}

double * SGSimInterface::getPropertyFromICktElement(DISPID dispID) {

    if(dispID < 7 || dispID > 9) {

        cerr << "SGSimInterface: You tried to call getPropertyFromICktElement with wrong dispID (" << dispID << "). You have to use the value for either Voltages, Currents or Powers (7-9)" << endl;
        endSimulation();
        return NULL;
    }
    else {

        // get values for property with DISPID dispID

        double * values;
        clearParameters();
        params.cNamedArgs = 0;
        params.cArgs = 0;

        if(S_OK == pICktElement->Invoke(dispID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &params, &returnValues , &excepinfo, &nArgErr)) {

            SAFEARRAY * safe = returnValues.parray;
            VARTYPE vt;
            SafeArrayGetVartype(safe, &vt);
            void* pData;
            if(vt == VT_R8) {
                SafeArrayAccessData(safe, &pData);
                SafeArrayUnaccessData(safe);
            }

            values = (double *) pData;

            return values;

        }
        else {
            cerr << "SGSimInterface: unable to retrieve property with id " << dispID << " from ICktElement";
            endSimulation();
            return NULL;
        }
    }
}

int SGSimInterface::setCommand(char * cmd) {
    clearParameters();
    params.rgvarg = Arguments;
    params.cNamedArgs = 1;
    params.cArgs = 1;


    // create wchar* from parameter cmd

    WCHAR *wcmd;
    int nChars = MultiByteToWideChar(CP_ACP, 0, cmd, -1, NULL, 0);
    wcmd = new WCHAR[nChars];
    MultiByteToWideChar(CP_ACP, 0, cmd, -1, (LPWSTR)wcmd, nChars);


    // create BSTR from wchar*

    BSTR wcmd2 = SysAllocString(wcmd);

    params.rgvarg[0].vt = VT_BSTR;
    params.rgvarg[0].bstrVal = wcmd2;
    DISPID propertyputID = DISPID_PROPERTYPUT;
    params.rgdispidNamedArgs = &propertyputID;
    if(S_OK == pIText->Invoke(commandID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT, &params, &returnValues , &excepinfo, &nArgErr)) {
        return 0;
    }
    else {
        return -1;
    }
}

int SGSimInterface::prohibitForms() {
    clearParameters();
    params.rgvarg = Arguments;
    params.cNamedArgs = 1;
    params.cArgs = 1;
    params.rgvarg[0].vt = VT_BOOL;
    params.rgvarg[0].boolVal = false;
    DISPID propertyputID = DISPID_PROPERTYPUT;
    params.rgdispidNamedArgs = &propertyputID;
    if(S_OK == pIDSS->Invoke(allowFormsID, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT, &params, &returnValues , &excepinfo, &nArgErr)) {
        return 0;
    }
    else {
        cerr << hr << endl;
        return -1;
    }
}

void SGSimInterface::clearParameters() {
    memset(&params, 0 , sizeof(DISPPARAMS));
    VariantInit(&returnValues);
    memset(&excepinfo, 0, sizeof(EXCEPINFO));
    nArgErr = 0;
    VariantInit(&Arguments[0]);
}

void SGSimInterface::finish() {
    pIDSS->Release();
    CoUninitialize();
}
