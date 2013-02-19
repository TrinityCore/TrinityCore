// file      : XMLSchema/TypeInfo.tpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: TypeInfo.tpp 91814 2010-09-17 08:33:40Z johnnyw $

namespace XMLSchema
{
  //@@ VC6
  //
  template<typename T>
  void
  add_info (XSCRT::ExtendedTypeInfoMap& map, T*)
  {
    using XSCRT::TypeId;
    using XSCRT::ExtendedTypeInfo;

    TypeId id (typeid (T));
    ExtendedTypeInfo info (id);

    info.add_base (ExtendedTypeInfo::Access::public_,
                   false,
                   typeid (XSCRT::Type));

    map.insert (std::make_pair (id, info));
  }


  template <typename C>
  inline
  TypeInfoInitializer<C>::
  TypeInfoInitializer (XSCRT::ExtendedTypeInfoMap& map)
  {
    using XSCRT::TypeId;
    using XSCRT::ExtendedTypeInfo;

    // XSCRT::Type
    //
    {
      TypeId id (typeid (XSCRT::Type));
      map.insert (std::make_pair (id, ExtendedTypeInfo (id)));
    }

    //@@ VC6

    add_info<byte> (map, 0);
    add_info<unsignedByte> (map, 0);

    add_info<short_> (map, 0);
    add_info<unsignedShort> (map, 0);

    add_info<int_> (map, 0);
    add_info<unsignedInt> (map, 0);

    add_info<long_> (map, 0);
    add_info<unsignedLong> (map, 0);

    add_info<boolean> (map, 0);

    add_info<float_> (map, 0);;
    add_info<double_> (map, 0);

    add_info<string<C> > (map, 0);

    add_info<normalizedString<C> > (map, 0);
    add_info<token<C> > (map, 0);
    add_info<NMTOKEN<C> > (map, 0);
    add_info<Name<C> > (map, 0);
    add_info<NCName<C> > (map, 0);
    add_info<QName<C> > (map, 0);

    add_info<ID<C> > (map, 0);

    // IDREF_Base
    //
    {
      TypeId id (typeid (IDREF_Base));
      ExtendedTypeInfo info (id);

      info.add_base (ExtendedTypeInfo::Access::public_,
                     false,
                     typeid (XSCRT::Type));

      map.insert (std::make_pair (id, info));
    }

    // IDREF
    //
    {
      TypeId id (typeid (IDREF<C>));
      ExtendedTypeInfo info (id);

      info.add_base (ExtendedTypeInfo::Access::public_,
                     false,
                     typeid (IDREF_Base));

      map.insert (std::make_pair (id, info));
    }
  }
}
