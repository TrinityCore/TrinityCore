// file      : XMLSchema/Writer.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: Writer.hpp 95832 2012-06-06 13:09:50Z johnnyw $

#ifndef XMLSCHEMA_WRITER_HPP
#define XMLSCHEMA_WRITER_HPP

#include <sstream>

#include <ace/XML_Utils/XSCRT/Writer.hpp>

#include <ace/XML_Utils/XMLSchema/Types.hpp>
#include <ace/XML_Utils/XMLSchema/Traversal.hpp>

#include <iostream>

namespace XMLSchema
{
  namespace Writer
  {
    template <typename T, typename C>
    struct FundamentalType : Traversal::Traverser<T>,
                             virtual XSCRT::Writer<C>
    {
      FundamentalType (XSCRT::XML::Element<C>& e)
          : XSCRT::Writer<C> (e)
      {
      }

      using XSCRT::Writer<C>::top_;
      using XSCRT::Writer<C>::attr_;

      virtual void
      traverse (T const& o)
      {
        using namespace XSCRT::XML;

        std::basic_ostringstream<C> os;

        os << o;

        if (Attribute<C>* a = attr_ ())
        {
          a->value (os.str ());
        }
        else
        {
          top_().value (os.str ());
        }
      }

    protected:
      virtual void
      traverse (T &t)
      {
        Traversal::Traverser<T>::traverse (t);
      }

      FundamentalType ()
      {
      }
    };

    template<typename C>
    struct FundamentalType <XSCRT::FundamentalType<bool>, C> :
      Traversal::Traverser<XSCRT::FundamentalType<bool> >,
      virtual XSCRT::Writer<C>
    {
      FundamentalType (XSCRT::XML::Element<C> &e)
        : XSCRT::Writer<C> (e)
      {
      }

      using XSCRT::Writer<C>::top_;
      using XSCRT::Writer<C>::attr_;

      virtual void
      traverse (XSCRT::FundamentalType<bool> const &o)
      {
        using namespace XSCRT::XML;

        std::basic_ostringstream<C> os;

        if (o)
          {
            os << "true";
          }
        else
          {
            os << "false";
          }

        if (Attribute<C>* a = attr_ ())
        {
          a->value (os.str ());
        }
        else
        {
          top_().value (os.str ());
        }
      }

    protected:
      virtual void
      traverse (XSCRT::FundamentalType<bool> &t)
      {
        Traversal::Traverser<XSCRT::FundamentalType<bool> >::traverse (t);
      }

      FundamentalType ()
      {
      }
    };


    template <typename C>
    struct IDREF : Traversal::Traverser<XMLSchema::IDREF<C> >,
                   virtual XSCRT::Writer<C>
    {
      IDREF (XSCRT::XML::Element<C>& e)
          : XSCRT::Writer<C> (e)
      {
      }

      virtual void
      traverse (
        typename Traversal::Traverser<XMLSchema::IDREF<C> >::Type const& o)
      {
        using namespace XSCRT::XML;

        if (Attribute<C>* a = XSCRT::Writer<C>::attr_ ())
        {
          a->value (o.id ());
        }
        else
        {
          XSCRT::Writer<C>::top_().value (o.id ());
        }
      }

    protected:

      virtual void
      traverse (typename Traversal::Traverser<XMLSchema::IDREF<C> >::Type &o)
      {
        Traversal::Traverser<XMLSchema::IDREF<C> >::traverse (o);
      }

      IDREF ()
      {
      }
    };
  }
}

#include <ace/XML_Utils/XMLSchema/Writer.ipp>

#endif  // XMLSCHEMA_WRITER_HPP
