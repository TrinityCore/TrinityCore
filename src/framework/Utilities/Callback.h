/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef TRINITY_CALLBACK_H
#define TRINITY_CALLBACK_H
/// ------------ BASE CLASSES ------------
namespace Trinity
{
    template < class Class, typename ParamType1 = void, typename ParamType2 = void, typename ParamType3 = void, typename ParamType4 = void >
    class _Callback
    {
        protected:
            typedef void (Class::*Method)(ParamType1, ParamType2, ParamType3, ParamType4);
            Class *m_object;
            Method m_method;
            ParamType1 m_param1;
            ParamType2 m_param2;
            ParamType3 m_param3;
            ParamType4 m_param4;
            void _Execute() { (m_object->*m_method)(m_param1, m_param2, m_param3, m_param4); }
        public:
            _Callback(Class *object, Method method, ParamType1 param1, ParamType2 param2, ParamType3 param3, ParamType4 param4)
                : m_object(object), m_method(method), m_param1(param1), m_param2(param2), m_param3(param3), m_param4(param4) {}
            _Callback(_Callback < Class, ParamType1, ParamType2, ParamType3, ParamType4> const& cb)
                : m_object(cb.object), m_method(cb.m_method), m_param1(cb.m_param1), m_param2(cb.m_param2), m_param3(cb.m_param3), m_param4(cb.m_param4) {}
    };
    template < class Class, typename ParamType1, typename ParamType2, typename ParamType3 >
    class _Callback < Class, ParamType1, ParamType2, ParamType3 >
    {
        protected:
            typedef void (Class::*Method)(ParamType1, ParamType2, ParamType3);
            Class *m_object;
            Method m_method;
            ParamType1 m_param1;
            ParamType2 m_param2;
            ParamType3 m_param3;
            void _Execute() { (m_object->*m_method)(m_param1, m_param2, m_param3); }
        public:
            _Callback(Class *object, Method method, ParamType1 param1, ParamType2 param2, ParamType3 param3)
                : m_object(object), m_method(method), m_param1(param1), m_param2(param2) {}
            _Callback(_Callback < Class, ParamType1, ParamType2, ParamType3 > const& cb)
                : m_object(cb.object), m_method(cb.m_method), m_param1(cb.m_param1), m_param2(cb.m_param2), m_param3(cb.m_param3) {}
    };
    template < class Class, typename ParamType1, typename ParamType2 >
    class _Callback < Class, ParamType1, ParamType2 >
    {
        protected:
            typedef void (Class::*Method)(ParamType1, ParamType2);
            Class *m_object;
            Method m_method;
            ParamType1 m_param1;
            ParamType2 m_param2;
            void _Execute() { (m_object->*m_method)(m_param1, m_param2); }
        public:
            _Callback(Class *object, Method method, ParamType1 param1, ParamType2 param2)
                : m_object(object), m_method(method), m_param1(param1), m_param2(param2) {}
            _Callback(_Callback < Class, ParamType1, ParamType2 > const& cb)
                : m_object(cb.m_object), m_method(cb.m_method), m_param1(cb.m_param1), m_param2(cb.m_param2) {}
    };
    template < class Class, typename ParamType1 >
    class _Callback < Class, ParamType1 >
    {
        protected:
            typedef void (Class::*Method)(ParamType1);
            Class *m_object;
            Method m_method;
            ParamType1 m_param1;
            void _Execute() { (m_object->*m_method)(m_param1); }
        public:
            _Callback(Class *object, Method method, ParamType1 param1)
                : m_object(object), m_method(method), m_param1(param1) {}
            _Callback(_Callback < Class, ParamType1 > const& cb)
                : m_object(cb.m_object), m_method(cb.m_method), m_param1(cb.m_param1) {}
    };
    template < class Class >
    class _Callback < Class >
    {
        protected:
            typedef void (Class::*Method)();
            Class *m_object;
            Method m_method;
            void _Execute() { (m_object->*m_method)(); }
        public:
            _Callback(Class *object, Method method)
                : m_object(object), m_method(method) {}
            _Callback(_Callback < Class > const& cb)
                : m_object(cb.m_object), m_method(cb.m_method) {}
    };
    /// ---- Statics ----
    template < typename ParamType1 = void, typename ParamType2 = void, typename ParamType3 = void, typename ParamType4 = void >
    class _SCallback
    {
        protected:
            typedef void (*Method)(ParamType1, ParamType2, ParamType3, ParamType4);
            Method m_method;
            ParamType1 m_param1;
            ParamType2 m_param2;
            ParamType3 m_param3;
            ParamType4 m_param4;
            void _Execute() { (*m_method)(m_param1, m_param2, m_param3, m_param4); }
        public:
            _SCallback(Method method, ParamType1 param1, ParamType2 param2, ParamType3 param3, ParamType4 param4)
                : m_method(method), m_param1(param1), m_param2(param2), m_param3(param3), m_param4(param4) {}
            _SCallback(_SCallback < ParamType1, ParamType2, ParamType3, ParamType4> const& cb)
                : m_method(cb.m_method), m_param1(cb.m_param1), m_param2(cb.m_param2), m_param3(cb.m_param3), m_param4(cb.m_param4) {}
    };
    template < typename ParamType1, typename ParamType2, typename ParamType3 >
    class _SCallback < ParamType1, ParamType2, ParamType3 >
    {
        protected:
            typedef void (*Method)(ParamType1, ParamType2, ParamType3);
            Method m_method;
            ParamType1 m_param1;
            ParamType2 m_param2;
            ParamType3 m_param3;
            void _Execute() { (*m_method)(m_param1, m_param2, m_param3); }
        public:
            _SCallback(Method method, ParamType1 param1, ParamType2 param2, ParamType3 param3)
                : m_method(method), m_param1(param1), m_param2(param2), m_param3(param3) {}
            _SCallback(_SCallback < ParamType1, ParamType2, ParamType3 > const& cb)
                : m_method(cb.m_method), m_param1(cb.m_param1), m_param2(cb.m_param2), m_param3(cb.m_param3) {}
    };
    template < typename ParamType1, typename ParamType2 >
    class _SCallback < ParamType1, ParamType2 >
    {
        protected:
            typedef void (*Method)(ParamType1, ParamType2);
            Method m_method;
            ParamType1 m_param1;
            ParamType2 m_param2;
            void _Execute() { (*m_method)(m_param1, m_param2); }
        public:
            _SCallback(Method method, ParamType1 param1, ParamType2 param2)
                : m_method(method), m_param1(param1), m_param2(param2) {}
            _SCallback(_SCallback < ParamType1, ParamType2 > const& cb)
                : m_method(cb.m_method), m_param1(cb.m_param1), m_param2(cb.m_param2) {}
    };
    template < typename ParamType1 >
    class _SCallback < ParamType1 >
    {
        protected:
            typedef void (*Method)(ParamType1);
            Method m_method;
            ParamType1 m_param1;
            void _Execute() { (*m_method)(m_param1); }
        public:
            _SCallback(Method method, ParamType1 param1)
                : m_method(method), m_param1(param1) {}
            _SCallback(_SCallback < ParamType1 > const& cb)
                : m_method(cb.m_method), m_param1(cb.m_param1) {}
    };
    template < >
    class _SCallback < >
    {
        protected:
            typedef void (*Method)();
            Method m_method;
            void _Execute() { (*m_method)(); }
        public:
            _SCallback(Method method)
                : m_method(method) {}
            _SCallback(_SCallback <> const& cb)
                : m_method(cb.m_method) {}
    };
}
/// --------- GENERIC CALLBACKS ----------
namespace Trinity
{
    class ICallback
    {
        public:
            virtual void Execute() = 0;
            virtual ~ICallback() {}
    };
    template < class CB >
    class _ICallback : public CB, public ICallback
    {
        public:
            _ICallback(CB const& cb) : CB(cb) {}
            void Execute() { CB::_Execute(); }
    };
    template < class Class, typename ParamType1 = void, typename ParamType2 = void, typename ParamType3 = void, typename ParamType4 = void >
    class Callback :
        public _ICallback< _Callback < Class, ParamType1, ParamType2, ParamType3, ParamType4 > >
    {
        private:
            typedef _Callback < Class, ParamType1, ParamType2, ParamType3, ParamType4 > C4;
        public:
            Callback(Class *object, typename C4::Method method, ParamType1 param1, ParamType2 param2, ParamType3 param3, ParamType4 param4)
                : _ICallback< C4 >(C4(object, method, param1, param2, param3, param4)) {}
    };
    template < class Class, typename ParamType1, typename ParamType2, typename ParamType3 >
    class Callback < Class, ParamType1, ParamType2, ParamType3 > :
        public _ICallback< _Callback < Class, ParamType1, ParamType2, ParamType3 > >
    {
        private:
            typedef _Callback < Class, ParamType1, ParamType2, ParamType3 > C3;
        public:
            Callback(Class *object, typename C3::Method method, ParamType1 param1, ParamType2 param2, ParamType3 param3)
                : _ICallback< C3 >(C3(object, method, param1, param2, param3)) {}
    };
    template < class Class, typename ParamType1, typename ParamType2 >
    class Callback < Class, ParamType1, ParamType2 > :
        public _ICallback< _Callback < Class, ParamType1, ParamType2 > >
    {
        private:
            typedef _Callback < Class, ParamType1, ParamType2 > C2;
        public:
            Callback(Class *object, typename C2::Method method, ParamType1 param1, ParamType2 param2)
                : _ICallback< C2 >(C2(object, method, param1, param2)) {}
    };
    template < class Class, typename ParamType1 >
    class Callback < Class, ParamType1 > :
        public _ICallback< _Callback < Class, ParamType1 > >
    {
        private:
            typedef _Callback < Class, ParamType1 > C1;
        public:
            Callback(Class *object, typename C1::Method method, ParamType1 param1)
                : _ICallback< C1 >(C1(object, method, param1)) {}
    };
    template < class Class >
    class Callback < Class > : public _ICallback< _Callback < Class > >
    {
        private:
            typedef _Callback < Class > C0;
        public:
            Callback(Class *object, typename C0::Method method)
                : _ICallback< C0 >(C0(object, method)) {}
    };
}
/// ---------- QUERY CALLBACKS -----------
class QueryResult;
namespace Trinity
{
    class IQueryCallback
    {
        public:
            virtual void Execute() = 0;
            virtual ~IQueryCallback() {}
            virtual void SetResult(QueryResult* result) = 0;
            virtual QueryResult* GetResult() = 0;
    };
    template < class CB >
    class _IQueryCallback : public CB, public IQueryCallback
    {
        public:
            _IQueryCallback(CB const& cb) : CB(cb) {}
            void Execute() { CB::_Execute(); }
            void SetResult(QueryResult* result) { CB::m_param1 = result; }
            QueryResult* GetResult() { return CB::m_param1; }
    };
    template < class Class, typename ParamType1 = void, typename ParamType2 = void, typename ParamType3 = void >
    class QueryCallback :
        public _IQueryCallback< _Callback < Class, QueryResult*, ParamType1, ParamType2, ParamType3 > >
    {
        private:
            typedef _Callback < Class, QueryResult*, ParamType1, ParamType2, ParamType3 > QC3;
        public:
            QueryCallback(Class *object, typename QC3::Method method, QueryResult* result, ParamType1 param1, ParamType2 param2, ParamType3 param3)
                : _IQueryCallback< QC3 >(QC3(object, method, result, param1, param2, param3)) {}
    };
    template < class Class, typename ParamType1, typename ParamType2 >
    class QueryCallback < Class, ParamType1, ParamType2 > :
        public _IQueryCallback< _Callback < Class, QueryResult*, ParamType1, ParamType2 > >
    {
        private:
            typedef _Callback < Class, QueryResult*, ParamType1, ParamType2 > QC2;
        public:
            QueryCallback(Class *object, typename QC2::Method method, QueryResult* result, ParamType1 param1, ParamType2 param2)
                : _IQueryCallback< QC2 >(QC2(object, method, result, param1, param2)) {}
    };
    template < class Class, typename ParamType1 >
    class QueryCallback < Class, ParamType1 > :
        public _IQueryCallback< _Callback < Class, QueryResult*, ParamType1 > >
    {
        private:
            typedef _Callback < Class, QueryResult*, ParamType1 > QC1;
        public:
            QueryCallback(Class *object, typename QC1::Method method, QueryResult* result, ParamType1 param1)
                : _IQueryCallback< QC1 >(QC1(object, method, result, param1)) {}
    };
    template < class Class >
    class QueryCallback < Class > : public _IQueryCallback< _Callback < Class, QueryResult* > >
    {
        private:
            typedef _Callback < Class, QueryResult* > QC0;
        public:
            QueryCallback(Class *object, typename QC0::Method method, QueryResult* result)
                : _IQueryCallback< QC0 >(QC0(object, method, result)) {}
    };
    /// ---- Statics ----
    template < typename ParamType1 = void, typename ParamType2 = void, typename ParamType3 = void >
    class SQueryCallback :
        public _IQueryCallback< _SCallback < QueryResult*, ParamType1, ParamType2, ParamType3 > >
    {
        private:
            typedef _SCallback < QueryResult*, ParamType1, ParamType2, ParamType3 > QC3;
        public:
            SQueryCallback(typename QC3::Method method, QueryResult* result, ParamType1 param1, ParamType2 param2, ParamType3 param3)
                : _IQueryCallback< QC3 >(QC3(method, result, param1, param2, param3)) {}
    };
    template < typename ParamType1, typename ParamType2 >
    class SQueryCallback < ParamType1, ParamType2 > :
        public _IQueryCallback< _SCallback < QueryResult*, ParamType1, ParamType2 > >
    {
        private:
            typedef _SCallback < QueryResult*, ParamType1, ParamType2 > QC2;
        public:
            SQueryCallback(typename QC2::Method method, QueryResult* result, ParamType1 param1, ParamType2 param2)
                : _IQueryCallback< QC2 >(QC2(method, result, param1, param2)) {}
    };
    template < typename ParamType1 >
    class SQueryCallback < ParamType1 > :
        public _IQueryCallback< _SCallback < QueryResult*, ParamType1 > >
    {
        private:
            typedef _SCallback < QueryResult*, ParamType1 > QC1;
        public:
            SQueryCallback(typename QC1::Method method, QueryResult* result, ParamType1 param1)
                : _IQueryCallback< QC1 >(QC1(method, result, param1)) {}
    };
    template < >
    class SQueryCallback < > : public _IQueryCallback< _SCallback < QueryResult* > >
    {
        private:
            typedef _SCallback < QueryResult* > QC0;
        public:
            SQueryCallback(QC0::Method method, QueryResult* result)
                : _IQueryCallback< QC0 >(QC0(method, result)) {}
    };
}
#endif

