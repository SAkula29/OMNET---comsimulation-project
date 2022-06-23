//
// Generated file, do not edit! Created by opp_msgc 4.4 from apps/BATControl.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "BATControl_m.h"

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




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("MessageType1");
    if (!e) enums.getInstance()->add(e = new cEnum("MessageType1"));
    e->insert(CONT_CHARGE, "CONT_CHARGE");
    e->insert(CONT_DISCHARGE, "CONT_DISCHARGE");
    e->insert(CONT_IDLE, "CONT_IDLE");
);

Register_Class(BATControl);

BATControl::BATControl(const char *name, int kind) : ::cPacket(name,kind)
{
    this->type_var = 0;
    this->source_var = 0;
    this->time_var = 0;
    this->var_var = 0;
    this->kw_var = 0;
    this->voltage_var = 0;
}

BATControl::BATControl(const BATControl& other) : ::cPacket(other)
{
    copy(other);
}

BATControl::~BATControl()
{
}

BATControl& BATControl::operator=(const BATControl& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void BATControl::copy(const BATControl& other)
{
    this->type_var = other.type_var;
    this->source_var = other.source_var;
    this->time_var = other.time_var;
    this->var_var = other.var_var;
    this->kw_var = other.kw_var;
    this->voltage_var = other.voltage_var;
}

void BATControl::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->source_var);
    doPacking(b,this->time_var);
    doPacking(b,this->var_var);
    doPacking(b,this->kw_var);
    doPacking(b,this->voltage_var);
}

void BATControl::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->time_var);
    doUnpacking(b,this->var_var);
    doUnpacking(b,this->kw_var);
    doUnpacking(b,this->voltage_var);
}

int BATControl::getType() const
{
    return type_var;
}

void BATControl::setType(int type)
{
    this->type_var = type;
}

const char * BATControl::getSource() const
{
    return source_var.c_str();
}

void BATControl::setSource(const char * source)
{
    this->source_var = source;
}

simtime_t BATControl::getTime() const
{
    return time_var;
}

void BATControl::setTime(simtime_t time)
{
    this->time_var = time;
}

double BATControl::getVar() const
{
    return var_var;
}

void BATControl::setVar(double var)
{
    this->var_var = var;
}

double BATControl::getKw() const
{
    return kw_var;
}

void BATControl::setKw(double kw)
{
    this->kw_var = kw;
}

double BATControl::getVoltage() const
{
    return voltage_var;
}

void BATControl::setVoltage(double voltage)
{
    this->voltage_var = voltage;
}

class BATControlDescriptor : public cClassDescriptor
{
  public:
    BATControlDescriptor();
    virtual ~BATControlDescriptor();

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

Register_ClassDescriptor(BATControlDescriptor);

BATControlDescriptor::BATControlDescriptor() : cClassDescriptor("BATControl", "cPacket")
{
}

BATControlDescriptor::~BATControlDescriptor()
{
}

bool BATControlDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BATControl *>(obj)!=NULL;
}

const char *BATControlDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BATControlDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int BATControlDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *BATControlDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "source",
        "time",
        "var",
        "kw",
        "voltage",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int BATControlDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "time")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "var")==0) return base+3;
    if (fieldName[0]=='k' && strcmp(fieldName, "kw")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "voltage")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BATControlDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "simtime_t",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *BATControlDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MessageType1";
            return NULL;
        default: return NULL;
    }
}

int BATControlDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BATControl *pp = (BATControl *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BATControlDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BATControl *pp = (BATControl *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return oppstring2string(pp->getSource());
        case 2: return double2string(pp->getTime());
        case 3: return double2string(pp->getVar());
        case 4: return double2string(pp->getKw());
        case 5: return double2string(pp->getVoltage());
        default: return "";
    }
}

bool BATControlDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BATControl *pp = (BATControl *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setSource((value)); return true;
        case 2: pp->setTime(string2double(value)); return true;
        case 3: pp->setVar(string2double(value)); return true;
        case 4: pp->setKw(string2double(value)); return true;
        case 5: pp->setVoltage(string2double(value)); return true;
        default: return false;
    }
}

const char *BATControlDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *BATControlDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BATControl *pp = (BATControl *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


