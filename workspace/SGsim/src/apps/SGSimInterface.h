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

#ifndef _SGSimInterface_H
#define _SGSimInterface_H

#include <omnetpp.h>
#include "stdio.h"
#include "Shlobj.h"
#include "objbase.h"
#include "stdlib.h"
#include "ccdata.h"
#include "string"

using namespace std;

class SGSimInterface
        : public cSimpleModule
{
    public:
        virtual void runCommand(char * cmd);                            // implemented
        virtual double getTotalLosses();                                // implemented
        virtual double getLineLosses();                                 // implemented
        virtual double getEnergyActiveObject(char * activeObject);      // implemented
        virtual AllValues getValuesActiveObject(char * activeObject);   // implemented

    private:
        HRESULT hr;
        DISPPARAMS params;
        EXCEPINFO excepinfo;
        VARIANT returnValues;
        UINT nArgErr;
        VARIANT Arguments[1];

        // OpenDSSengine ID
        CLSID clsid;

        // used interface pointers
        IDispatch* pIDSS;
        IDispatch* pIText;
        IDispatch* pICircuit;
        IDispatch* pISolution;
        IDispatch* pICktElement;
        /* Obsolete
        IDispatch* pIMonitors;
        IDispatch* pIBus;
        */

        // used interface IDS
        IID iidIDSS;
        /*Not needed
        IID iidIText;
        IID iidICircuit;
        IID iidISolution;
        IID iidIMonitors;
        IID iidIBus;
        */

        // names of functions and properties that will be used from IDSS
        OLECHAR* start = L"Start";
        OLECHAR* activeCircuit = L"ActiveCircuit";
        OLECHAR* text = L"Text";
        OLECHAR* allowForms = L"AllowForms";

        // names of functions and properties that will be used from ICircuit
        OLECHAR* losses = L"Losses";
        OLECHAR* lineLosses = L"LineLosses";
        OLECHAR* solution = L"Solution";
        OLECHAR* activeBus = L"ActiveBus";
        OLECHAR* setActiveElement = L"SetActiveElement";
        OLECHAR* activeCktElement = L"ActiveCktElement";

        // names of functions and properties that will be used from IText
        OLECHAR* command = L"Command";
        OLECHAR* result = L"Result";

        // names of functions and properties that will be used from ICktElement
        OLECHAR* voltages = L"Voltages";
        OLECHAR* currents = L"Currents";
        OLECHAR* powers = L"Powers";

        // these functions' and properties' dispatch IDs
        DISPID startID;
        DISPID activeCircuitID;
        DISPID textID;
        DISPID allowFormsID;
        DISPID lossesID;
        DISPID lineLossesID;
        DISPID solutionID;
        DISPID activeBusID;
        DISPID setActiveElementID;
        DISPID activeCktElementID;
        DISPID commandID;
        DISPID resultID;
        DISPID voltagesID;
        DISPID currentsID;
        DISPID powersID;


    protected:
        wchar_t* clsidStr = L"{6FE9D1B8-C064-4877-94C0-F13882ADBDB6}";
        wchar_t* iidIDSSStr = L"{14644AD0-4909-48FF-B624-24E8C38D1AED}";
        /* Not needed
        wchar_t* iidITextStr = L"{0513A8DC-2C0D-4648-8BD7-2130B82C05FA}";
        wchar_t* iidICircuitStr = L"{32441C6D-7A27-4164-B5B0-FA054300C217}";
        wchar_t* iidISolutionStr = L"{F2332365-962A-4DF4-9D1E-218E0B0F2CEF}";
        wchar_t* iidIMonitorsStr = L"{5C339E44-C583-445C-91D1-3B1E49CAD6B0}";
        wchar_t* iidIBusStr = L"{E5B78C35-88F8-495F-8CD1-EBB5D90ED228}";
        wchar_t* libidStr = L"{8BFDE413-245A-4514-B151-B16DCC243796}";
        */

        virtual void initialize();

        // call the Start function in the initialized IDSS object
        virtual int invokeStart();

        // call the SetActiveObject function in ICircuit
        virtual int invokeSetActiveElement(char * activeObject);

        //retrieve the pointer to the dispatch interface with the id dispid from IDSS
        virtual IDispatch* getDispInterfaceFromIDSS(DISPID dispid);

        //retrieve the pointer to the dispatch interface with the id dispid from ICircuit
        virtual IDispatch* getDispInterfaceFromICircuit(DISPID dispid);

        // retrieve the property Result from ICircuit
        virtual string getResult();

        // retrieve the property with the given dispid from ICktElement. This is only possible for the properties Voltages, Currents and Powers (dispids 7-9)
        virtual double * getPropertyFromICktElement(DISPID dispID);

        // set the Command property in IText to cmd
        virtual int setCommand(char * cmd);

        // set the property AllowForms to false in IDSS
        virtual int prohibitForms();

        // clear all structs that are used for passing arguments
        virtual void clearParameters();

        virtual void finish();
};
#endif

