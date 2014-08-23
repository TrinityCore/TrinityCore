/** 
  \file Pointer.h
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  \created 2007-05-16
  \edited  2012-10-06

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */
#ifndef G3D_Pointer_h
#define G3D_Pointer_h

#include "G3D/debugAssert.h"
#include "G3D/ReferenceCount.h"

namespace G3D {

/**
   Acts like a pointer to a value of type ValueType (i.e.,
   ValueType*), but can operate through accessor methods as well as on
   a value in memory.  This is useful for implementing scripting
   languages and other applications that need to connect existing APIs
   by reference.

   Because the accessors require values to be passed by value (instead of by reference)
   this is primarily useful for objects whose memory size is small.

   \code
   class Foo {
   public:
      void setEnabled(bool b);
      bool getEnabled() const;
   };

   Foo  f;
   bool b;
   
   Pointer<bool> p1(&b);
   Pointer<bool> p2(&f, &Foo::getEnabled, &Foo::setEnabled);

   *p1 = true;
   *p2 = false;
   *p2 = *p1; \/\/ Value assignment
   p2 = p1; \/\/ Pointer aliasing

   \/\/ Or, equivalently:
   p1.setValue(true);
   p2.setValue(false);

   p2.setValue(p1.getValue());
   p2 = p1;
   \endcode

   <i>Note:</i> Because of the way that dereference is implemented, you cannot pass <code>*p</code> through a function
   that takes varargs (...), e.g., <code>printf("%d", *p)</code> will produce a compile-time error.  Instead use
   <code>printf("%d",(bool)*p)</code> or <code>printf("%d", p.getValue())</code>.

   \cite McGuire, GUIs for Real-time Programs, using Universal Pointers, SIGGRAPH 2008 Poster.
 */
template<typename ValueType>
class Pointer {
private:

    class Interface {
    public:
        virtual ~Interface() {};
        virtual void set(ValueType b) = 0;
        virtual ValueType get() const = 0;
        virtual Interface* clone() const = 0;
        virtual bool isNull() const = 0;
    };

    class Memory : public Interface {
    private:

        ValueType* value;

    public:
        
        Memory(ValueType* value) : value(value) {}

        virtual void set(ValueType v) {
            *value = v;
        }

        virtual ValueType get() const {
            return *value;
        }

        virtual Interface* clone() const {
            return new Memory(value);
        }

        virtual bool isNull() const {
            return value == NULL;
        }
    };

    template<typename GetMethod, typename SetMethod>
    class FcnAccessor : public Interface {
    private:

        GetMethod   getMethod;
        SetMethod   setMethod;

    public:
        
        FcnAccessor(GetMethod getMethod, SetMethod setMethod) : getMethod(getMethod), setMethod(setMethod) {
        }

        virtual void set(ValueType v) {
            if (setMethod) {
                (*setMethod)(v);
            }
        }

        virtual ValueType get() const {
            return (*getMethod)();
        }

        virtual Interface* clone() const {
            return new FcnAccessor(getMethod, setMethod);
        }

        virtual bool isNull() const { return false; }
    };

    template<class T, typename GetMethod, typename SetMethod>
    class Accessor : public Interface {
    private:

        T*          object;
        GetMethod   getMethod;
        SetMethod   setMethod;

    public:
        
        Accessor(T* object, 
                 GetMethod getMethod, 
                 SetMethod setMethod) : object(object), getMethod(getMethod), setMethod(setMethod) {
            debugAssert(object != NULL);
        }

        virtual void set(ValueType v) {
            if (setMethod) {
                (object->*setMethod)(v);
            }
        }

        virtual ValueType get() const {
            return (object->*getMethod)();
        }

        virtual Interface* clone() const {
            return new Accessor(object, getMethod, setMethod);
        }

        virtual bool isNull() const {
            return object == NULL;
        }
    };


    template<class T, typename GetMethod, typename SetMethod>
    class SharedAccessor : public Interface {
    private:

        shared_ptr<T>   object;
        GetMethod       getMethod;
        SetMethod       setMethod;

    public:
        
        SharedAccessor
           (const shared_ptr<T>& object, 
            GetMethod getMethod, 
            SetMethod setMethod) : object(object), getMethod(getMethod), setMethod(setMethod) {

            debugAssert(object != NULL);
        }

        virtual void set(ValueType v) {
            if (setMethod) {
                (object.get()->*setMethod)(v);
            }
        }

        virtual ValueType get() const {
            return (object.get()->*getMethod)();
        }

        virtual Interface* clone() const {
            return new SharedAccessor(object, getMethod, setMethod);
        }

        virtual bool isNull() const {
            return (bool)object;
        }
    };

    Interface* m_interface;

public:

    Pointer() : m_interface(NULL) {};

    /** Allows implicit cast from real pointer */
    Pointer(ValueType* v) : m_interface(new Memory(v)) {}

    inline bool isNull() const {
        return (m_interface == NULL) || m_interface->isNull();
    }

    // Assignment
    inline Pointer& operator=(const Pointer& r) {
        delete m_interface;
        if (r.m_interface != NULL) {
            m_interface = r.m_interface->clone();
        } else {
            m_interface = NULL;
        }
        return this[0];
    }

    Pointer(const Pointer& p) : m_interface(NULL) {
        this[0] = p;
    }


    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(const shared_ptr<Class>& object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        m_interface(new SharedAccessor<Class, ValueType (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}

    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(const shared_ptr<Class>& object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        m_interface(new SharedAccessor<Class, const ValueType& (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}


    /** \param setMethod May be NULL */
    Pointer(ValueType (*getMethod)(),
            void (*setMethod)(ValueType)) : 
        m_interface(new FcnAccessor<ValueType (*)(), void (*)(ValueType)>(getMethod, setMethod)) {}

    /** \param setMethod May be NULL */
    Pointer(const ValueType& (*getMethod)(),
            void (*setMethod)(ValueType)) : 
        m_interface(new FcnAccessor<const ValueType& (*)(), void (*)(ValueType)>(getMethod, setMethod)) {}


    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(const shared_ptr<Class>& object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        m_interface(new SharedAccessor<Class, ValueType (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(const shared_ptr<Class>& object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        m_interface(new SharedAccessor<Class, const ValueType& (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(Class* object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        m_interface(new Accessor<Class, const ValueType& (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(Class* object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        m_interface(new Accessor<Class, ValueType (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(Class* object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        m_interface(new Accessor<Class, const ValueType& (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}

    /** \param setMethod May be NULL */
    template<class Class>
    Pointer(Class* object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        m_interface(new Accessor<Class, ValueType (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}

    ~Pointer() {
        delete m_interface;
    }

    inline const ValueType getValue() const {
        debugAssert(m_interface != NULL);
        return m_interface->get();
    }

    /** \brief Assign a value to the referenced element.
        If this Pointer was initialized with a NULL setMethod, the call is ignored */
    inline void setValue(const ValueType& v) {
        debugAssert(m_interface != NULL);
        m_interface->set(v);
    }

    class IndirectValue {
    private:

        friend class Pointer;
        Pointer* pointer;
        IndirectValue(Pointer* p) : pointer(p) {}

    public:

        void operator=(const ValueType& v) {
            pointer->setValue(v);
        }

        operator ValueType() const {
            return pointer->getValue();
        }

    };

    inline IndirectValue operator*() {
        return IndirectValue(this);
    }

    inline const ValueType operator*() const {
        return getValue();
    }
};

template<class T>
bool isNull(const Pointer<T>& p) {
    return p.isNull();
}

template<class T>
bool notNull(const Pointer<T>& p) {
    return ! p.isNull();
}

}

#endif
