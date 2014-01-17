// file      : XSCRT/XMLSchema.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: XMLSchema.hpp 95802 2012-05-31 12:37:36Z johnnyw $

#ifndef XSCRT_XMLSCHEMA_HPP
#define XSCRT_XMLSCHEMA_HPP

#include <string>
// #include <iostream> //@@ tmp

#include "ace/XML_Utils/XMLSchema/XSCRT/Elements.hpp"

namespace XMLSchema
{
  typedef XSCRT::FundamentalType<signed char> byte;
  typedef XSCRT::FundamentalType<unsigned char> unsignedByte;

  typedef XSCRT::FundamentalType<short> short_;
  typedef XSCRT::FundamentalType<unsigned short> unsignedShort;

  typedef XSCRT::FundamentalType<int> int_;
  typedef XSCRT::FundamentalType<unsigned int> unsignedInt;

  typedef XSCRT::FundamentalType<long long> long_;
  typedef XSCRT::FundamentalType<unsigned long long> unsignedLong;

  //@@ It would be nice to use some arbitrary-length integer class.
  //
  typedef long_ decimal;
  typedef decimal integer;
  typedef integer nonPositiveInteger;
  typedef integer nonNegativeInteger;
  typedef nonNegativeInteger positiveInteger;
  typedef nonPositiveInteger negativeInteger;


  typedef XSCRT::FundamentalType<bool> boolean;

  typedef XSCRT::FundamentalType<float> float_;
  typedef XSCRT::FundamentalType<double> double_;

  // Just to make GCC 3.3 and other broken compilers shutup.
  //
  using std::basic_string;


  template <typename C>
  class string : public XSCRT::Type, public basic_string<C>
  {
  protected:
    typedef basic_string<C> Base__ ;

  public:

    //@@ VC6 does not inject XSCRT::Type into the scope so I have
    //   to qualify it all the time.
    //

    string ()
    {
    }

    string (XSCRT::XML::Element<C> const& e)
        : Base__ (e.value ())
    {
    }

    string (XSCRT::XML::Attribute<C> const& a)
        : Base__ (a.value ())
    {
    }

    string (Base__ const& x)
        : Base__ (x)
    {
    }

    string&
    operator= (Base__ const& x)
    {
      static_cast<Base__&> (*this) = x;
      return *this;
    }
  };


  template <typename C>
  class normalizedString : public string<C>
  {
  protected:
    typedef typename string<C>::Base__ Base__;

  public:
    normalizedString ()
    {
    }

    normalizedString (XSCRT::XML::Element<C> const& e)
        : string<C> (e)
    {
    }

    normalizedString (XSCRT::XML::Attribute<C> const& a)
        : string<C> (a)
    {
    }

    normalizedString (Base__ const& x)
        : string<C> (x)
    {
    }

    normalizedString&
    operator= (Base__ const& x)
    {
      static_cast<Base__&> (*this) = x;
      return *this;
    }
  };


  template <typename C>
  class token : public normalizedString<C>
  {
  protected:
    typedef typename normalizedString<C>::Base__ Base__;

  public:
    token ()
    {
    }

    token (XSCRT::XML::Element<C> const& e)
        : normalizedString<C> (e)
    {
    }

    token (XSCRT::XML::Attribute<C> const& a)
        : normalizedString<C> (a)
    {
    }

    token (Base__ const& x)
        : normalizedString<C> (x)
    {
    }

    token&
    operator= (Base__ const& x)
    {
      static_cast<Base__&> (*this) = x;
      return *this;
    }
  };


  template <typename C>
  class NMTOKEN : public token<C>
  {
  protected:
    typedef typename token<C>::Base__ Base__;

  public:
    NMTOKEN ()
    {
    }

    NMTOKEN (XSCRT::XML::Element<C> const& e)
        : token<C> (e)
    {
    }

    NMTOKEN (XSCRT::XML::Attribute<C> const& a)
        : token<C> (a)
    {
    }

    NMTOKEN (Base__ const& x)
        : token<C> (x)
    {
    }

    NMTOKEN&
    operator= (Base__ const& x)
    {
      static_cast<Base__&> (*this) = x;
      return *this;
    }
  };

  template <typename C>
  class Name: public token<C>
  {
  protected:
    typedef typename token<C>::Base__ Base__;

  public:
    Name()
    {
    }

    Name(XSCRT::XML::Element<C> const& e)
        : token<C> (e)
    {
    }

    Name(XSCRT::XML::Attribute<C> const& a)
        : token<C> (a)
    {
    }

    Name(Base__ const& x)
        : token<C> (x)
    {
    }

    Name&
    operator= (Base__ const& x)
    {
      static_cast<Base__&> (*this) = x;
      return *this;
    }
  };


  template <typename C>
  class NCName: public Name<C>
  {
  protected:
    typedef typename Name<C>::Base__ Base__;

  public:
    NCName()
    {
    }

    NCName(XSCRT::XML::Element<C> const& e)
        : Name<C> (e)
    {
    }

    NCName(XSCRT::XML::Attribute<C> const& a)
        : Name<C> (a)
    {
    }

    NCName(Base__ const& x)
        : Name<C> (x)
    {
    }

    NCName&
    operator= (Base__ const& x)
    {
      static_cast<Base__&> (*this) = x;
      return *this;
    }
  };

  template <typename C>
  class QName: public Name<C>
  {
  protected:
    typedef typename Name<C>::Base__ Base__;

  public:
    QName()
    {
    }

    QName(XSCRT::XML::Element<C> const& e)
        : Name<C> (e)
    {
    }

    QName(XSCRT::XML::Attribute<C> const& a)
        : Name<C> (a)
    {
    }

    QName(Base__ const& x)
        : Name<C> (x)
    {
    }

    QName&
    operator= (Base__ const& x)
    {
      static_cast<Base__&> (*this) = x;
      return *this;
    }
  };

  template <typename C>
  struct IdentityProvider : XSCRT::IdentityProvider
  {
    IdentityProvider (NCName<C> const& id)
        : id_ (id)
    {
    }

    virtual bool
    before (XSCRT::IdentityProvider const& y) const
    {
      return id_ < dynamic_cast<IdentityProvider const&> (y).id_;
    }

  private:
    NCName<C> const& id_;

  private:
    IdentityProvider (IdentityProvider const&);

    IdentityProvider&
    operator= (IdentityProvider const&);
  };


  template <typename C>
  class ID : public NCName<C>
  {
  protected:
    typedef typename NCName<C>::Base__ Base__;

  public:
    ~ID()
    {
      unregister_id ();
    }

    ID ()
        : id_provider_ (*this)
    {
    }

    ID (XSCRT::XML::Element<C> const& e)
        : NCName<C> (e), id_provider_ (*this)
    {
    }

    ID (XSCRT::XML::Attribute<C> const& a)
        : NCName<C> (a), id_provider_ (*this)
    {
    }

    ID (ID const& x)
        :  NCName<C> (x), id_provider_ (*this)
    {
    }

    ID (Base__ const& x)
        :  NCName<C> (x), id_provider_ (*this)
    {
    }

    ID&
    operator= (Base__ const& x)
    {
      unregister_id ();

      static_cast<NCName<C>&>(*this) = x;

      register_id ();

      return *this;
    }

    ID&
    operator= (ID const& x)
    {
      unregister_id ();

      static_cast<NCName<C>&>(*this) = static_cast<NCName<C> const&>(x);

      register_id ();

      return *this;
    }

  public:
    using NCName<C>::container;

    virtual void
    container (XSCRT::Type* c)
    {
      unregister_id ();

      NCName<C>::container (c);

      register_id ();
    }

  private:
    using NCName<C>::empty;
    using NCName<C>::root;

    void
    register_id ()
    {
      if (container () != this && !empty ())
      {
        //std::wcerr << "registering " << container ()
        //           << " as '" << *this
        //           << "' on " << container () << std::endl;
        container ()->register_id (id_provider_, container ());
      }
    }

    void
    unregister_id ()
    {
      if (container () != this && !empty ())
      {
        //std::wcerr << "un-registering " << container ()
        //           << " as '" << *this
        //           << "' on " << container () << std::endl;
        container ()->unregister_id (id_provider_);
      }
    }

  private:
    IdentityProvider<C> id_provider_;
  };

  struct IDREF_Base : public XSCRT::Type
  {
    virtual XSCRT::Type*
    get () const = 0;
  };

  template <typename C>
  class IDREF : public IDREF_Base
  {
  public:
    IDREF ()
        : id_provider_ (id_)
    {
    }

    IDREF (XSCRT::XML::Element<C> const& e)
        : id_ (e), id_provider_ (id_)
    {
    }

    IDREF (XSCRT::XML::Attribute<C> const& a)
        : id_ (a), id_provider_ (id_)
    {
    }

    IDREF (IDREF const& x)
        : id_ (x.id_), id_provider_ (id_)
    {
    }

    IDREF (basic_string<C> const& id)
        : id_ (id), id_provider_ (id_)
    {
    }

    IDREF&
    operator= (IDREF const& x)
    {
      id_ = x.id_;
      return *this;
    }

    IDREF&
    operator= (basic_string<C> const& x)
    {
      id_ = x;
      return *this;
    }

  public:
    XSCRT::Type*
    operator-> () const
    {
      return get ();
    }

    XSCRT::Type&
    operator* () const
    {
      return *(get ());
    }

    virtual XSCRT::Type*
    get () const
    {
      if (!id_.empty () && container () != this)
      {
        return root ()->lookup_id (id_provider_);
      }
      else
      {
        return 0;
      }
    }

    // conversion to bool
    //
    typedef XSCRT::Type* (IDREF::*bool_convertable)() const;

    operator bool_convertable () const
    {
      return get () ? &IDREF::operator-> : 0;
    }

  private:
    NCName<C> id_;
    IdentityProvider<C> id_provider_;
  };
}

// Traversal
//
//

#include "ace/XML_Utils/XSCRT/Traversal.hpp"

namespace XMLSchema
{
  namespace Traversal
  {
    template <typename T>
    struct Traverser : XSCRT::Traversal::Traverser<T, XSCRT::Type>,
                       XSCRT::Traversal::Traverser<IDREF_Base, XSCRT::Type>
    {
      typedef
      T
      Type;

      virtual void
      traverse (XMLSchema::IDREF_Base& r)
      {
        if (r.get ()) dispatch (*(r.get ()));
      }
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
  }
}


// ExtendedTypeInfo for XML Schema types
//
//

#include "ace/XML_Utils/XSCRT/ExtendedTypeInfo.hpp"

namespace XMLSchema
{
  template <typename C>
  struct TypeInfoInitializer
  {
    TypeInfoInitializer (XSCRT::ExtendedTypeInfoMap&);
  };
}

#include "ace/XML_Utils/XSCRT/XMLSchema.ipp"
#include "ace/XML_Utils/XSCRT/XMLSchema.tpp"

#endif  // XSCRT_XMLSCHEMA_HPP
