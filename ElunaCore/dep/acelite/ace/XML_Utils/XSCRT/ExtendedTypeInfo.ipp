// file      : XSCRT/ExtendedTypeInfo.ipp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: ExtendedTypeInfo.ipp 86462 2009-08-12 13:31:27Z wotte $


/*
 *  @@HACK: Visual Studio.
 *  I think the return value for operator== for type_info
 *  in VC7 (perhaps others) is int when is should be bool.
 *  This causes a warning about converting the return value from
 *  int to bool.
 */
#ifdef _MSC_VER
# pragma warning( disable: 4800 )
#endif

namespace XSCRT
{
  // TypeId
  //
  //
  inline
  TypeId::
  TypeId (std::type_info const& tid)
      : tid_ (&tid)
  {
  }

  inline
  bool TypeId::
  operator == (TypeId const& other) const
  {
    return *tid_ == *other.tid_;
  }

  inline
  bool TypeId::
  operator != (TypeId const& other) const
  {
    return *tid_ != *other.tid_;
  }

  inline
  bool TypeId::
  operator < (TypeId const& other) const
  {
    return tid_->before (*other.tid_);
  }


  // ExtendedTypeInfo::BaseInfo
  //
  //

  inline
  ExtendedTypeInfo::BaseInfo::
  BaseInfo (Access::Value access, bool virtual_base, TypeId const& tid)
      : tid_ (tid),
        ti_ (0),
        virtual_base_ (virtual_base),
        access_ (access)
  {
  }

  inline
  ExtendedTypeInfo const& ExtendedTypeInfo::BaseInfo::
  type_info () const
  {
    if (ti_ == 0) ti_ = &(extended_type_info (tid_));

    return *ti_;
  }


  inline
  ExtendedTypeInfo::Access::Value ExtendedTypeInfo::BaseInfo::
  access () const
  {
    return access_;
  }

  inline
  bool ExtendedTypeInfo::BaseInfo::
  virtual_base () const
  {
    return virtual_base_;
  }


  // ExtendedTypeInfo
  //
  //
  inline
  ExtendedTypeInfo::
  ExtendedTypeInfo (TypeId const& tid)
      : tid_ (tid)
  {
  }

  inline
  TypeId ExtendedTypeInfo::
  type_id () const
  {
    return tid_;
  }

  inline
  ExtendedTypeInfo::BaseIterator ExtendedTypeInfo::
  begin_base () const
  {
    return base_.begin ();
  }


  inline
  ExtendedTypeInfo::BaseIterator ExtendedTypeInfo::
  end_base () const
  {
    return base_.end ();
  }

  inline
  void ExtendedTypeInfo::
  add_base (Access::Value access, bool virtual_base, TypeId const& tid)
  {
    base_.push_back (BaseInfo (access, virtual_base, tid));
  }

  // ExtendedTypeInfoMap
  //
  //

  inline
  ExtendedTypeInfoMap&
  extended_type_info_map ()
  {
    static ExtendedTypeInfoMap extended_type_info_map_;

    return extended_type_info_map_;
  }
}
