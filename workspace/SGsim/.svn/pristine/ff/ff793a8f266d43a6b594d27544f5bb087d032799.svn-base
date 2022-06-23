//
// Generated file, do not edit! Created by opp_msgc 4.4 from apps/SmartData.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SmartData_m.h"

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




Register_Class(SmartData);

SmartData::SmartData(const char *name, int kind) : ::cPacket(name,kind)
{
    this->source_var = 0;
    this->time_var = 0;
    this->demand_var = 0;
    this->supply_var = 0;
    this->aPower_var = 0;
    this->rPower_var = 0;
    this->voltage_var = 0;
}

SmartData::SmartData(const SmartData& other) : ::cPacket(other)
{
    copy(other);
}

SmartData::~SmartData()
{
}

SmartData& SmartData::operator=(const SmartData& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SmartData::copy(const SmartData& other)
{
    this->source_var = other.source_var;
    this->time_var = other.time_var;
    this->demand_var = other.demand_var;
    this->supply_var = other.supply_var;
    this->aPower_var = other.aPower_var;
    this->rPower_var = other.rPower_var;
    this->voltage_var = other.voltage_var;
}

void SmartData::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->source_var);
    doPacking(b,this->time_var);
    doPacking(b,this->demand_var);
    doPacking(b,this->supply_var);
    doPacking(b,this->aPower_var);
    doPacking(b,this->rPower_var);
    doPacking(b,this->voltage_var);
}

void SmartData::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->time_var);
    doUnpacking(b,this->demand_var);
    doUnpacking(b,this->supply_var);
    doUnpacking(b,this->aPower_var);
    doUnpacking(b,this->rPower_var);
    doUnpacking(b,this->voltage_var);
}

const char * SmartData::getSource() const
{
    return source_var.c_str();
}

void SmartData::setSource(const char * source)
{
    this->source_var = source;
}

simtime_t SmartData::getTime() const
{
    return time_var;
}

void SmartData::setTime(simtime_t time)
{
    this->time_var = time;
}

double SmartData::getDemand() const
{
    return demand_var;
}

void SmartData::setDemand(double demand)
{
    this->demand_var = demand;
}

double SmartData::getSupply() const
{
    return supply_var;
}

void SmartData::setSupply(double supply)
{
    this->supply_var = supply;
}

double SmartData::getAPower() const
{
    return aPower_var;
}

void SmartData::setAPower(double aPower)
{
    this->aPower_var = aPower;
}

double SmartData::getRPower() const
{
    return rPower_var;
}

void SmartData::setRPower(double rPower)
{
    this->rPower_var = rPower;
}

double SmartData::getVoltage() const
{
    return voltage_var;
}

void SmartData::setVoltage(double voltage)
{
    this->voltage_var = voltage;
}

class SmartDataDescriptor : public cClassDescriptor
{
  public:
    SmartDataDescriptor();
    virtual ~SmartDataDescriptor();

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

Register_ClassDescriptor(SmartDataDescriptor);

SmartDataDescriptor::SmartDataDescriptor() : cClassDescriptor("SmartData", "cPacket")
{
}

SmartDataDescriptor::~SmartDataDescriptor()
{
}

bool SmartDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SmartData *>(obj)!=NULL;
}

const char *SmartDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SmartDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int SmartDataDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *SmartDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "source",
        "time",
        "demand",
        "supply",
        "aPower",
        "rPower",
        "voltage",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int SmartDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "time")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "demand")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "supply")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "aPower")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "rPower")==0) return base+5;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltage")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SmartDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "simtime_t",
        "double",
        "double",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *SmartDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SmartDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SmartData *pp = (SmartData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SmartDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SmartData *pp = (SmartData *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSource());
        case 1: return double2string(pp->getTime());
        case 2: return double2string(pp->getDemand());
        case 3: return double2string(pp->getSupply());
        case 4: return double2string(pp->getAPower());
        case 5: return double2string(pp->getRPower());
        case 6: return double2string(pp->getVoltage());
        default: return "";
    }
}

bool SmartDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SmartData *pp = (SmartData *)object; (void)pp;
    switch (field) {
        case 0: pp->setSource((value)); return true;
        case 1: pp->setTime(string2double(value)); return true;
        case 2: pp->setDemand(string2double(value)); return true;
        case 3: pp->setSupply(string2double(value)); return true;
        case 4: pp->setAPower(string2double(value)); return true;
        case 5: pp->setRPower(string2double(value)); return true;
        case 6: pp->setVoltage(string2double(value)); return true;
        default: return false;
    }
}

const char *SmartDataDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *SmartDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SmartData *pp = (SmartData *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


