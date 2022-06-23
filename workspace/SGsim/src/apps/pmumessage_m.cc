//
// Generated file, do not edit! Created by opp_msgc 4.4 from apps/pmumessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "pmumessage_m.h"

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




Register_Class(pmumessage);

pmumessage::pmumessage(const char *name, int kind) : ::cPacket(name,kind)
{
    this->pmuID_var = 0;
    this->timeStep_var = 0;
    for (unsigned int i=0; i<1024; i++)
        this->data_frm_var[i] = 0;
    this->pmusize_var = 0;
    this->ctime_var = 0;
    this->source_var = 0;
    this->destination_var = 0;
    this->hops_var = 0;
}

pmumessage::pmumessage(const pmumessage& other) : ::cPacket(other)
{
    copy(other);
}

pmumessage::~pmumessage()
{
}

pmumessage& pmumessage::operator=(const pmumessage& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void pmumessage::copy(const pmumessage& other)
{
    this->pmuID_var = other.pmuID_var;
    this->timeStep_var = other.timeStep_var;
    for (unsigned int i=0; i<1024; i++)
        this->data_frm_var[i] = other.data_frm_var[i];
    this->pmusize_var = other.pmusize_var;
    this->ctime_var = other.ctime_var;
    this->source_var = other.source_var;
    this->destination_var = other.destination_var;
    this->hops_var = other.hops_var;
}

void pmumessage::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->pmuID_var);
    doPacking(b,this->timeStep_var);
    doPacking(b,this->data_frm_var,1024);
    doPacking(b,this->pmusize_var);
    doPacking(b,this->ctime_var);
    doPacking(b,this->source_var);
    doPacking(b,this->destination_var);
    doPacking(b,this->hops_var);
}

void pmumessage::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->pmuID_var);
    doUnpacking(b,this->timeStep_var);
    doUnpacking(b,this->data_frm_var,1024);
    doUnpacking(b,this->pmusize_var);
    doUnpacking(b,this->ctime_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->destination_var);
    doUnpacking(b,this->hops_var);
}

const char * pmumessage::getPmuID() const
{
    return pmuID_var.c_str();
}

void pmumessage::setPmuID(const char * pmuID)
{
    this->pmuID_var = pmuID;
}

double pmumessage::getTimeStep() const
{
    return timeStep_var;
}

void pmumessage::setTimeStep(double timeStep)
{
    this->timeStep_var = timeStep;
}

unsigned int pmumessage::getData_frmArraySize() const
{
    return 1024;
}

unsigned char pmumessage::getData_frm(unsigned int k) const
{
    if (k>=1024) throw cRuntimeError("Array of size 1024 indexed by %lu", (unsigned long)k);
    return data_frm_var[k];
}

void pmumessage::setData_frm(unsigned int k, unsigned char data_frm)
{
    if (k>=1024) throw cRuntimeError("Array of size 1024 indexed by %lu", (unsigned long)k);
    this->data_frm_var[k] = data_frm;
}

int pmumessage::getPmusize() const
{
    return pmusize_var;
}

void pmumessage::setPmusize(int pmusize)
{
    this->pmusize_var = pmusize;
}

simtime_t pmumessage::getCtime() const
{
    return ctime_var;
}

void pmumessage::setCtime(simtime_t ctime)
{
    this->ctime_var = ctime;
}

int pmumessage::getSource() const
{
    return source_var;
}

void pmumessage::setSource(int source)
{
    this->source_var = source;
}

int pmumessage::getDestination() const
{
    return destination_var;
}

void pmumessage::setDestination(int destination)
{
    this->destination_var = destination;
}

int pmumessage::getHops() const
{
    return hops_var;
}

void pmumessage::setHops(int hops)
{
    this->hops_var = hops;
}

class pmumessageDescriptor : public cClassDescriptor
{
  public:
    pmumessageDescriptor();
    virtual ~pmumessageDescriptor();

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

Register_ClassDescriptor(pmumessageDescriptor);

pmumessageDescriptor::pmumessageDescriptor() : cClassDescriptor("pmumessage", "cPacket")
{
}

pmumessageDescriptor::~pmumessageDescriptor()
{
}

bool pmumessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<pmumessage *>(obj)!=NULL;
}

const char *pmumessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int pmumessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int pmumessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *pmumessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pmuID",
        "timeStep",
        "data_frm",
        "pmusize",
        "ctime",
        "source",
        "destination",
        "hops",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int pmumessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pmuID")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStep")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "data_frm")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "pmusize")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "ctime")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+6;
    if (fieldName[0]=='h' && strcmp(fieldName, "hops")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *pmumessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "double",
        "unsigned char",
        "int",
        "simtime_t",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *pmumessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int pmumessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    pmumessage *pp = (pmumessage *)object; (void)pp;
    switch (field) {
        case 2: return 1024;
        default: return 0;
    }
}

std::string pmumessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    pmumessage *pp = (pmumessage *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getPmuID());
        case 1: return double2string(pp->getTimeStep());
        case 2: return ulong2string(pp->getData_frm(i));
        case 3: return long2string(pp->getPmusize());
        case 4: return double2string(pp->getCtime());
        case 5: return long2string(pp->getSource());
        case 6: return long2string(pp->getDestination());
        case 7: return long2string(pp->getHops());
        default: return "";
    }
}

bool pmumessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    pmumessage *pp = (pmumessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setPmuID((value)); return true;
        case 1: pp->setTimeStep(string2double(value)); return true;
        case 2: pp->setData_frm(i,string2ulong(value)); return true;
        case 3: pp->setPmusize(string2long(value)); return true;
        case 4: pp->setCtime(string2double(value)); return true;
        case 5: pp->setSource(string2long(value)); return true;
        case 6: pp->setDestination(string2long(value)); return true;
        case 7: pp->setHops(string2long(value)); return true;
        default: return false;
    }
}

const char *pmumessageDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *pmumessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    pmumessage *pp = (pmumessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


