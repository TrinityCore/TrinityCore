// file      : XSCRT/ExtendedTypeInfo.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: ExtendedTypeInfo.hpp 95802 2012-05-31 12:37:36Z johnnyw $

#ifndef XSCRT_EXTENDED_TYPE_INFO_HPP
#define XSCRT_EXTENDED_TYPE_INFO_HPP

#include <map>
#include <vector>
#include <typeinfo>

namespace XSCRT
{
  //
  //
  //
  class TypeId
  {
  public:
    template<typename T>
    TypeId (T const& t);

    TypeId (std::type_info const& tid);

  public:
    bool
    operator == (TypeId const& other) const;

    bool
    operator != (TypeId const& other) const;

    bool
    operator < (TypeId const& other) const;

    /*
    friend std::ostream&
    operator << (std::ostream& os, TypeId const& t);
    */

  public:
    char const*
    name () const
    {
      return tid_->name ();
    }

  private:
    std::type_info const* tid_;
  };


  //
  //
  //
  class ExtendedTypeInfo
  {
  public:

    //
    //
    //
    struct Access
    {
      enum Value
      {
        private_,
        protected_,
        public_
      };
    };


    //
    //
    //
    class BaseInfo
    {
    public:
      BaseInfo (Access::Value access, bool virtual_base, TypeId const& tid);

    public:
      ExtendedTypeInfo const&
      type_info () const;

      Access::Value
      access () const;

      bool
      virtual_base () const;

    private:
      TypeId tid_;
      mutable ExtendedTypeInfo const* ti_;
      bool virtual_base_;
      Access::Value access_;
    };

  private:
    typedef
    std::vector<BaseInfo>
    BaseInfoList;

  public:
    typedef
    BaseInfoList::const_iterator
    BaseIterator;

  public:
    ExtendedTypeInfo (TypeId const& tid);

    TypeId
    type_id () const;

    BaseIterator
    begin_base () const;

    BaseIterator
    end_base () const;

    void
    add_base (Access::Value access, bool virtual_base, TypeId const& tid);

  private:
    TypeId tid_;
    BaseInfoList base_;
  };

  typedef
  std::map<TypeId, ExtendedTypeInfo>
  ExtendedTypeInfoMap;


  ExtendedTypeInfoMap&
  extended_type_info_map ();


  class NotAvailable {};


  template<typename T>
  ExtendedTypeInfo const&
  extended_type_info (T const& t)
  {
    return extended_type_info (typeid (t));
  }

  template<typename T>
  ExtendedTypeInfo const&
  extended_type_info ()
  {
    return extended_type_info (typeid (T));
  }

  //@@ Had to use function template specialization because VC6
  //   cannot handle simply overloaded functions.
  //

  template <>
  inline
  ExtendedTypeInfo const&
  extended_type_info<TypeId> (TypeId const& tid)
  {
    ExtendedTypeInfoMap::const_iterator i (
      extended_type_info_map ().find (tid));

    if (i == extended_type_info_map ().end ()) throw NotAvailable ();

    return i->second;
  }

  template <>
  inline
  ExtendedTypeInfo const&
  extended_type_info<std::type_info> (std::type_info const& tid)
  {
    return extended_type_info (TypeId (tid));
  }
}

#include <ace/XML_Utils/XSCRT/ExtendedTypeInfo.ipp>

#endif  // XSCRT_EXTENDED_TYPE_INFO_HPP
