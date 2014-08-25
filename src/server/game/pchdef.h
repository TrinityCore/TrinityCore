#ifndef PCHDEF_H_
#define PCHDEF_H_

class ObjectGuid
{
    public:                                                 // constructors
        ObjectGuid() : m_guid(0) {}
        ObjectGuid(uint64 guid) : m_guid(guid) {}
        ObjectGuid(const ObjectGuid& other) : m_guid(other.m_guid) {}
        operator uint64() const { return m_guid; }
        void Set(uint64 guid) { m_guid = guid; }
        void Clear() { m_guid = 0; }
        uint64   GetRawValue() const { return m_guid; }
        bool IsEmpty()             const { return m_guid == 0;                                }

        bool operator! () const { return IsEmpty(); }
        bool operator== (ObjectGuid const& guid) const { return GetRawValue() == guid.GetRawValue(); }
        bool operator!= (ObjectGuid const& guid) const { return GetRawValue() != guid.GetRawValue(); }
        bool operator< (ObjectGuid const& guid) const { return GetRawValue() < guid.GetRawValue(); }

    private:                                                // fields
        uint64 m_guid;
        static ObjectGuid const Null;
};

ByteBuffer& operator<< (ByteBuffer& buf, ObjectGuid const& guid);
ByteBuffer& operator>> (ByteBuffer& buf, ObjectGuid&       guid);

#endif /* PCHDEF_H_ */
