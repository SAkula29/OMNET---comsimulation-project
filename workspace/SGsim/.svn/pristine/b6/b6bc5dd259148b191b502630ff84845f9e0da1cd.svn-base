//
// Generated file, do not edit! Created by opp_msgc 4.4 from apps/PMUValues.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PMUValues_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(PMUValues);

PMUValues::PMUValues(const char *name, int kind) : ::cMessage(name,kind)
{
    this->ctime_var = 0;
    this->pmuID_var = 0;
    this->iD_var = 0;
    this->timeStep_var = 0;
    this->voltageValue1_var = 0;
    this->voltageAngle1_var = 0;
    this->voltageValue2_var = 0;
    this->voltageAngle2_var = 0;
    this->voltageValue3_var = 0;
    this->voltageAngle3_var = 0;
    this->currentValue1_var = 0;
    this->currentAngle1_var = 0;
    this->currentValue2_var = 0;
    this->currentAngle2_var = 0;
    this->currentValue3_var = 0;
    this->currentAngle3_var = 0;
}

PMUValues::PMUValues(const PMUValues& other) : ::cMessage(other)
{
    copy(other);
}

PMUValues::~PMUValues()
{
}

PMUValues& PMUValues::operator=(const PMUValues& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PMUValues::copy(const PMUValues& other)
{
    this->ctime_var = other.ctime_var;
    this->pmuID_var = other.pmuID_var;
    this->iD_var = other.iD_var;
    this->timeStep_var = other.timeStep_var;
    this->voltageValue1_var = other.voltageValue1_var;
    this->voltageAngle1_var = other.voltageAngle1_var;
    this->voltageValue2_var = other.voltageValue2_var;
    this->voltageAngle2_var = other.voltageAngle2_var;
    this->voltageValue3_var = other.voltageValue3_var;
    this->voltageAngle3_var = other.voltageAngle3_var;
    this->currentValue1_var = other.currentValue1_var;
    this->currentAngle1_var = other.currentAngle1_var;
    this->currentValue2_var = other.currentValue2_var;
    this->currentAngle2_var = other.currentAngle2_var;
    this->currentValue3_var = other.currentValue3_var;
    this->currentAngle3_var = other.currentAngle3_var;
}

void PMUValues::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->ctime_var);
    doPacking(b,this->pmuID_var);
    doPacking(b,this->iD_var);
    doPacking(b,this->timeStep_var);
    doPacking(b,this->voltageValue1_var);
    doPacking(b,this->voltageAngle1_var);
    doPacking(b,this->voltageValue2_var);
    doPacking(b,this->voltageAngle2_var);
    doPacking(b,this->voltageValue3_var);
    doPacking(b,this->voltageAngle3_var);
    doPacking(b,this->currentValue1_var);
    doPacking(b,this->currentAngle1_var);
    doPacking(b,this->currentValue2_var);
    doPacking(b,this->currentAngle2_var);
    doPacking(b,this->currentValue3_var);
    doPacking(b,this->currentAngle3_var);
}

void PMUValues::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->ctime_var);
    doUnpacking(b,this->pmuID_var);
    doUnpacking(b,this->iD_var);
    doUnpacking(b,this->timeStep_var);
    doUnpacking(b,this->voltageValue1_var);
    doUnpacking(b,this->voltageAngle1_var);
    doUnpacking(b,this->voltageValue2_var);
    doUnpacking(b,this->voltageAngle2_var);
    doUnpacking(b,this->voltageValue3_var);
    doUnpacking(b,this->voltageAngle3_var);
    doUnpacking(b,this->currentValue1_var);
    doUnpacking(b,this->currentAngle1_var);
    doUnpacking(b,this->currentValue2_var);
    doUnpacking(b,this->currentAngle2_var);
    doUnpacking(b,this->currentValue3_var);
    doUnpacking(b,this->currentAngle3_var);
}

simtime_t PMUValues::getCtime() const
{
    return ctime_var;
}

void PMUValues::setCtime(simtime_t ctime)
{
    this->ctime_var = ctime;
}

const char * PMUValues::getPmuID() const
{
    return pmuID_var.c_str();
}

void PMUValues::setPmuID(const char * pmuID)
{
    this->pmuID_var = pmuID;
}

int PMUValues::getID() const
{
    return iD_var;
}

void PMUValues::setID(int iD)
{
    this->iD_var = iD;
}

double PMUValues::getTimeStep() const
{
    return timeStep_var;
}

void PMUValues::setTimeStep(double timeStep)
{
    this->timeStep_var = timeStep;
}

double PMUValues::getVoltageValue1() const
{
    return voltageValue1_var;
}

void PMUValues::setVoltageValue1(double voltageValue1)
{
    this->voltageValue1_var = voltageValue1;
}

double PMUValues::getVoltageAngle1() const
{
    return voltageAngle1_var;
}

void PMUValues::setVoltageAngle1(double voltageAngle1)
{
    this->voltageAngle1_var = voltageAngle1;
}

double PMUValues::getVoltageValue2() const
{
    return voltageValue2_var;
}

void PMUValues::setVoltageValue2(double voltageValue2)
{
    this->voltageValue2_var = voltageValue2;
}

double PMUValues::getVoltageAngle2() const
{
    return voltageAngle2_var;
}

void PMUValues::setVoltageAngle2(double voltageAngle2)
{
    this->voltageAngle2_var = voltageAngle2;
}

double PMUValues::getVoltageValue3() const
{
    return voltageValue3_var;
}

void PMUValues::setVoltageValue3(double voltageValue3)
{
    this->voltageValue3_var = voltageValue3;
}

double PMUValues::getVoltageAngle3() const
{
    return voltageAngle3_var;
}

void PMUValues::setVoltageAngle3(double voltageAngle3)
{
    this->voltageAngle3_var = voltageAngle3;
}

double PMUValues::getCurrentValue1() const
{
    return currentValue1_var;
}

void PMUValues::setCurrentValue1(double currentValue1)
{
    this->currentValue1_var = currentValue1;
}

double PMUValues::getCurrentAngle1() const
{
    return currentAngle1_var;
}

void PMUValues::setCurrentAngle1(double currentAngle1)
{
    this->currentAngle1_var = currentAngle1;
}

double PMUValues::getCurrentValue2() const
{
    return currentValue2_var;
}

void PMUValues::setCurrentValue2(double currentValue2)
{
    this->currentValue2_var = currentValue2;
}

double PMUValues::getCurrentAngle2() const
{
    return currentAngle2_var;
}

void PMUValues::setCurrentAngle2(double currentAngle2)
{
    this->currentAngle2_var = currentAngle2;
}

double PMUValues::getCurrentValue3() const
{
    return currentValue3_var;
}

void PMUValues::setCurrentValue3(double currentValue3)
{
    this->currentValue3_var = currentValue3;
}

double PMUValues::getCurrentAngle3() const
{
    return currentAngle3_var;
}

void PMUValues::setCurrentAngle3(double currentAngle3)
{
    this->currentAngle3_var = currentAngle3;
}

class PMUValuesDescriptor : public cClassDescriptor
{
  public:
    PMUValuesDescriptor();
    virtual ~PMUValuesDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PMUValuesDescriptor);

PMUValuesDescriptor::PMUValuesDescriptor() : cClassDescriptor("PMUValues", "cMessage")
{
}

PMUValuesDescriptor::~PMUValuesDescriptor()
{
}

bool PMUValuesDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PMUValues *>(obj)!=NULL;
}

const char *PMUValuesDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PMUValuesDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount(object) : 16;
}

unsigned int PMUValuesDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<16) ? fieldTypeFlags[field] : 0;
}

const char *PMUValuesDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "ctime",
        "pmuID",
        "iD",
        "timeStep",
        "voltageValue1",
        "voltageAngle1",
        "voltageValue2",
        "voltageAngle2",
        "voltageValue3",
        "voltageAngle3",
        "currentValue1",
        "currentAngle1",
        "currentValue2",
        "currentAngle2",
        "currentValue3",
        "currentAngle3",
    };
    return (field>=0 && field<16) ? fieldNames[field] : NULL;
}

int PMUValuesDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "ctime")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pmuID")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "iD")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStep")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltageValue1")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltageAngle1")==0) return base+5;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltageValue2")==0) return base+6;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltageAngle2")==0) return base+7;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltageValue3")==0) return base+8;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltageAngle3")==0) return base+9;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentValue1")==0) return base+10;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentAngle1")==0) return base+11;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentValue2")==0) return base+12;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentAngle2")==0) return base+13;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentValue3")==0) return base+14;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentAngle3")==0) return base+15;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PMUValuesDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "string",
        "int",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<16) ? fieldTypeStrings[field] : NULL;
}

const char *PMUValuesDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PMUValuesDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PMUValues *pp = (PMUValues *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PMUValuesDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PMUValues *pp = (PMUValues *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getCtime());
        case 1: return oppstring2string(pp->getPmuID());
        case 2: return long2string(pp->getID());
        case 3: return double2string(pp->getTimeStep());
        case 4: return double2string(pp->getVoltageValue1());
        case 5: return double2string(pp->getVoltageAngle1());
        case 6: return double2string(pp->getVoltageValue2());
        case 7: return double2string(pp->getVoltageAngle2());
        case 8: return double2string(pp->getVoltageValue3());
        case 9: return double2string(pp->getVoltageAngle3());
        case 10: return double2string(pp->getCurrentValue1());
        case 11: return double2string(pp->getCurrentAngle1());
        case 12: return double2string(pp->getCurrentValue2());
        case 13: return double2string(pp->getCurrentAngle2());
        case 14: return double2string(pp->getCurrentValue3());
        case 15: return double2string(pp->getCurrentAngle3());
        default: return "";
    }
}

bool PMUValuesDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PMUValues *pp = (PMUValues *)object; (void)pp;
    switch (field) {
        case 0: pp->setCtime(string2double(value)); return true;
        case 1: pp->setPmuID((value)); return true;
        case 2: pp->setID(string2long(value)); return true;
        case 3: pp->setTimeStep(string2double(value)); return true;
        case 4: pp->setVoltageValue1(string2double(value)); return true;
        case 5: pp->setVoltageAngle1(string2double(value)); return true;
        case 6: pp->setVoltageValue2(string2double(value)); return true;
        case 7: pp->setVoltageAngle2(string2double(value)); return true;
        case 8: pp->setVoltageValue3(string2double(value)); return true;
        case 9: pp->setVoltageAngle3(string2double(value)); return true;
        case 10: pp->setCurrentValue1(string2double(value)); return true;
        case 11: pp->setCurrentAngle1(string2double(value)); return true;
        case 12: pp->setCurrentValue2(string2double(value)); return true;
        case 13: pp->setCurrentAngle2(string2double(value)); return true;
        case 14: pp->setCurrentValue3(string2double(value)); return true;
        case 15: pp->setCurrentAngle3(string2double(value)); return true;
        default: return false;
    }
}

const char *PMUValuesDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<16) ? fieldStructNames[field] : NULL;
}

void *PMUValuesDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PMUValues *pp = (PMUValues *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


