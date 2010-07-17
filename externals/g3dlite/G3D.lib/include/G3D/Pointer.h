/** 
  @file Pointer.h
 
  @maintainer Morgan McGuire, graphics3d.com
 
  @created 2007-05-16
  @edited  2007-06-22

  Copyright 2000-2007, Morgan McGuire.
  All rights reserved.
 */
#ifndef G3D_POINTER_H
#define G3D_POINTER_H

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

   <pre>
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
   </pre>

   <i>Note:</i> Because of the way that dereference is implemented, you cannot pass <code>*p</code> through a function
   that takes varargs (...), e.g., <code>printf("%d", *p)</code> will produce a compile-time error.  Instead use
   <code>printf("%d",(bool)*p)</code> or <code>printf("%d", p.getValue())</code>.
   
 */
template<class ValueType>
class Pointer {
private:

    class Interface {
    public:
        virtual ~Interface() {};
        virtual void set(ValueType b) = 0;
        virtual ValueType get() const = 0;
        virtual Interface* clone() const = 0;
    };

    class Memory : public Interface {
    private:

        ValueType* value;

    public:
        
        Memory(ValueType* value) : value(value) {
            debugAssert(value != NULL);
        }

        virtual void set(ValueType v) {
            *value = v;
        }

        virtual ValueType get() const {
            return *value;
        }

        virtual Interface* clone() const {
            return new Memory(value);
        }
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
            (object->*setMethod)(v);
        }

        virtual ValueType get() const {
            return (object->*getMethod)();
        }

        virtual Interface* clone() const {
            return new Accessor(object, getMethod, setMethod);
        }
    };


    template<class T, typename GetMethod, typename SetMethod>
    class RefAccessor : public Interface {
    private:

        ReferenceCountedPointer<T>         object;
        GetMethod   getMethod;
        SetMethod   setMethod;

    public:
        
        RefAccessor(
            const ReferenceCountedPointer<T>& object, 
            GetMethod getMethod, 
            SetMethod setMethod) : object(object), getMethod(getMethod), setMethod(setMethod) {

            debugAssert(object != NULL);
        }

        virtual void set(ValueType v) {
            (object.pointer()->*setMethod)(v);
        }

        virtual ValueType get() const {
            return (object.pointer()->*getMethod)();
        }

        virtual Interface* clone() const {
            return new RefAccessor(object, getMethod, setMethod);
        }
    };


    Interface* interface;

public:

    Pointer() : interface(NULL) {};

    /** Allows implicit cast from real pointer */
    Pointer(ValueType* v) : interface(new Memory(v)) {}

    // Assignment
    inline Pointer& operator=(const Pointer& r) {
        delete interface;
        if (r.interface != NULL) {
            interface = r.interface->clone();
        } else {
            interface = NULL;
        }
        return this[0];
    }

    Pointer(const Pointer& p) : interface(NULL) {
        this[0] = p;
    }

    template<class Class>
    Pointer(const ReferenceCountedPointer<Class>& object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        interface(new RefAccessor<Class, ValueType (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}

    template<class Class>
    Pointer(const ReferenceCountedPointer<Class>& object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        interface(new RefAccessor<Class, const ValueType& (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}

    template<class Class>
    Pointer(const ReferenceCountedPointer<Class>& object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        interface(new RefAccessor<Class, ValueType (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    template<class Class>
    Pointer(const ReferenceCountedPointer<Class>& object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        interface(new RefAccessor<Class, const ValueType& (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    template<class Class>
    Pointer(Class* object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        interface(new Accessor<Class, const ValueType& (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    template<class Class>
    Pointer(Class* object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(const ValueType&)) : 
        interface(new Accessor<Class, ValueType (Class::*)() const, void (Class::*)(const ValueType&)>(object, getMethod, setMethod)) {}

    template<class Class>
    Pointer(Class* object,
            const ValueType& (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        interface(new Accessor<Class, const ValueType& (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}

    template<class Class>
    Pointer(Class* object,
            ValueType (Class::*getMethod)() const,
            void (Class::*setMethod)(ValueType)) : 
        interface(new Accessor<Class, ValueType (Class::*)() const, void (Class::*)(ValueType)>(object, getMethod, setMethod)) {}

    ~Pointer() {
        delete interface;
    }

    inline const ValueType getValue() const {
        debugAssert(interface != NULL);
        return interface->get();
    }

    inline void setValue(const ValueType& v) {
        debugAssert(interface != NULL);
        interface->set(v);
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

}

#endif
