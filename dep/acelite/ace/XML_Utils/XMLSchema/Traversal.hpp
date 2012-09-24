// file      : XMLSchema/Traversal.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: Traversal.hpp 95832 2012-06-06 13:09:50Z johnnyw $

#ifndef XMLSCHEMA_TRAVERSAL_HPP
#define XMLSCHEMA_TRAVERSAL_HPP

#include <ace/XML_Utils/XSCRT/Traversal.hpp>
#include <ace/XML_Utils/XMLSchema/Types.hpp>

namespace XMLSchema
{
  namespace Traversal
  {
    // Automatic traversal of IDREFs.
    //
    //
    struct IDREF :
    XSCRT::Traversal::Traverser<XMLSchema::IDREF_Base, XSCRT::Type>
    {
      virtual void
      traverse (XMLSchema::IDREF_Base& r)
      {
        if (r.get ()) dispatch (*(r.get ()));
      }

      virtual void
      traverse (XMLSchema::IDREF_Base const& r)
      {
        if (r.get ()) dispatch (*(r.get ()));
      }
    };


    template <typename T>
    struct Traverser : XSCRT::Traversal::Traverser<T, XSCRT::Type>
    {
    };

    typedef Traverser<byte> byte;
    typedef Traverser<unsignedByte> unsignedByte;

    typedef Traverser<short_> short_;
    typedef Traverser<unsignedShort> unsignedShort;

    typedef Traverser<int_> int_;
    typedef Traverser<unsignedInt> unsignedInt;

    typedef Traverser<long_> long_;
    typedef Traverser<unsignedLong> unsignedLong;

    typedef Traverser<boolean> boolean;

    typedef Traverser<float_> float_;
    typedef Traverser<double_> double_;

    template <typename C>
    struct string : Traverser<XMLSchema::string<C> >
    {
    };

    template <typename C>
    struct ID : Traverser<XMLSchema::ID<C> >
    {
    };

    template <typename C>
    struct anyURI : Traverser <XMLSchema::anyURI<C> >
    {
    };
  }
}

#include <ace/XML_Utils/XMLSchema/Traversal.ipp>

#endif  // XMLSCHEMA_TRAVERSAL_HPP
