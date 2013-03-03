// file      : XMLSchema/Types.hpp
// author    : Boris Kolpackov <boris@dre.vanderbilt.edu>
// cvs-id    : $Id: Types.hpp 95832 2012-06-06 13:09:50Z johnnyw $

#ifndef XMLSCHEMA_TYPES_HPP
#define XMLSCHEMA_TYPES_HPP

#include <string>
#include "ace/XML_Utils/XSCRT/Elements.hpp"

#include "ace/Basic_Types.h"
/**
 * @@ HACK: VC7
 *
 * Disabled the warning about using this in the base member initialization section.
 * Our use in this file is fine.
 */
#ifdef _MSC_VER
# pragma warning ( disable: 4355 )
#endif
namespace XMLSchema
{
  typedef XSCRT::FundamentalType<ACE_INT8> byte;
  typedef XSCRT::FundamentalType<ACE_UINT8> unsignedByte;

  typedef XSCRT::FundamentalType<ACE_INT16> short_;
  typedef XSCRT::FundamentalType<ACE_UINT16> unsignedShort;

  typedef XSCRT::FundamentalType<ACE_INT32> int_;
  typedef XSCRT::FundamentalType<ACE_UINT32> unsignedInt;

  typedef XSCRT::FundamentalType<ACE_INT64> long_;
  typedef XSCRT::FundamentalType<ACE_UINT64> unsignedLong;

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
    //    typedef ACE_Refcounted_Auto_Ptr < string, ACE_Null_Mutex > _ptr;

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

    string (C const* x)
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

    normalizedString (C const* x)
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

    token (C const* x)
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

    NMTOKEN (C const* x)
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

    Name (C const* x)
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

    NCName (C const* x)
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

    QName (C const* x)
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

    virtual ~IdentityProvider (void)
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

    ID (C const* x)
        : NCName<C> (x), id_provider_ (*this)
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
      if (NCName<C>::container () != this && !empty ())
      {
        //std::wcerr << "registering " << container ()
        //           << " as '" << *this
        //           << "' on " << container () << std::endl;
        NCName<C>::container ()->register_id (id_provider_,
                                              NCName<C>::container ());
      }
    }

    void
    unregister_id ()
    {
      if (NCName<C>::container () != this && !empty ())
      {
        //std::wcerr << "un-registering " << container ()
        //           << " as '" << *this
        //           << "' on " << container () << std::endl;
        NCName<C>::container ()->unregister_id (id_provider_);
      }
    }

  private:
    IdentityProvider<C> id_provider_;
  };

  struct IDREF_Base : public XSCRT::Type
  {
    virtual XSCRT::Type const*
    get () const = 0;

    virtual XSCRT::Type*
    get () = 0;
  };

  template <typename C>
  class IDREF : public IDREF_Base
  {
  public:
    typedef C CDR_Type__;
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
      : XMLSchema::IDREF_Base (),
        id_ (x.id_), id_provider_ (id_)
    {
    }

    IDREF (basic_string<C> const& id)
        : id_ (id), id_provider_ (id_)
    {
    }

    IDREF (C const* id)
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
    NCName<C>
    id () const
    {
      return id_;
    }

  public:
    XSCRT::Type const*
    operator-> () const
    {
      return get ();
    }

    XSCRT::Type*
    operator-> ()
    {
      return get ();
    }

    XSCRT::Type const&
    operator* () const
    {
      return *(get ());
    }

    XSCRT::Type&
    operator* ()
    {
      return *(get ());
    }

    virtual XSCRT::Type const*
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

    virtual XSCRT::Type*
    get ()
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
    typedef void (IDREF::*bool_convertable)();

    operator bool_convertable () const
    {
      return get () ? &IDREF::true_ : 0;
    }

  private:
    void true_ ()
    {
    }

  private:
    NCName<C> id_;
    IdentityProvider<C> id_provider_;
  };

  template <typename C>
  class anyURI : public XSCRT::Type, public basic_string <C>
  {
  protected:
    typedef basic_string <C> Base__ ;

  public:
    // Trait for marshaling string
    typedef C CDR_Type__;

    //@@ VC6 does not inject XSCRT::Type into the scope so I have
    //   to qualify it all the time.
    //

    anyURI (void)
    {
    }

    anyURI (XSCRT::XML::Element<C> const& e)
        : Base__ (e.value ())
    {
    }

    anyURI (XSCRT::XML::Attribute<C> const& a)
        : Base__ (a.value ())
    {
    }

    anyURI (Base__ const& x)
        : Base__ (x)
    {
    }

    anyURI (C const * x)
        : Base__ (x)
    {
    }

    anyURI (const anyURI& s)
      : Base__ (s)
    {

    }

    anyURI & operator= (Base__ const& x)
    {
      static_cast <Base__ &> (*this) = x;
      return *this;
    }
  };
}

#include "ace/XML_Utils/XMLSchema/Types.ipp"

#endif  // XMLSCHEMA_TYPES_HPP
