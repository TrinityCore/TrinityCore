// -*- C++ -*-
//==========================================================================
/**
 *  @file Value_Ptr.h
 *
 *  $Id: Value_Ptr.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  Value_Ptr implementation based on code in Herb Sutter's book "More
 *  Exceptional C++".
 *
 *  @author Ossama Othman <ossama@dre.vanderbilt.edu>
 */
//==========================================================================
#ifndef ACE_VALUE_PTR_H
#define ACE_VALUE_PTR_H
#include "ace/config-lite.h"
#include <algorithm>
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  /**
   * @struct VP_traits
   *
   * @brief @c Value_Ptr traits template structure.
   *
   * The @c Value_Ptr template class delegates some operations to this
   * template traits structure.
   *
   * Specialize this trait template if cloning through copy
   * construction is not sufficient.  For example, to avoid slicing
   * when copying an object through a base class pointer, one can
   * implement a virtual "clone" method that can be used to
   * polymorphically invoke the appropriate cloning operation(s).
   * That virtual method would then be invoked by the @c VP_traits\<\>
   * specialization.
   */
  template <typename T>
  struct VP_traits
  {
    /// Copy the given object.
    static T * clone (T const * p) { return new T (*p); }
  };
  /**
   * @class Value_Ptr
   *
   * @brief Smart pointer implementation designed for use as a class
   *        member.
   *
   * Using a @c std::auto_ptr\<\> as a class member is sometimes
   * problematic since ownership of memory is transferred when copying
   * such members.  This @c Value_Ptr class is explicitly designed to
   * avoid such problems by performing copies of the underlying object
   * rather than transfer ownership.  This, for example, allows it to
   * be readily used as a member in classes placed inside STL
   * containers.
   *
   * @see Item 31 in "More Exceptional C++" by Herb Sutter.
   */
  template <typename T>
  class Value_Ptr
  {
  public:
    /// Constructor.
    explicit Value_Ptr (T * p = 0) : p_ (p) { }
    /// Destructor.
    ~Value_Ptr (void) { delete this->p_; }
    /// Deference operator.
    T & operator* (void) const { return *this->p_; }
    /// Pointer operator.
    T * operator-> (void) const { return this->p_; }
    /// Non-throwing swap operation used to make assignment strongly
    /// exception-safe.
    /**
     * @note As implemented, the swap operation may not work correctly
     *       for @c auto_ptr\<\>s, but why would one use an @c
     *       auto_ptr\<\> as the template argument for this particular
     *       template class!?
     */
    void swap (Value_Ptr & other) { std::swap (this->p_, other.p_); }
    /// Copy constructor.
    Value_Ptr (Value_Ptr const & other)
      : p_ (create_from (other.p_)) { }
    /// Assignment operator.
    Value_Ptr & operator= (Value_Ptr const & other)
    {
      // Strongly exception-safe.
      Value_Ptr temp (other);
      this->swap (temp);
      return *this;
    }
#ifndef ACE_LACKS_MEMBER_TEMPLATES
    // Compiler can't handle member templates so we lose converting
    // copy operations.
    /// Converting copy constructor.
    template <typename U>
    Value_Ptr (Value_Ptr<U> const & other)
      : p_ (create_from (other.p_)) { }
    /// Converting assignment operator.
    template <typename U>
    Value_Ptr & operator= (Value_Ptr<U> const & other)
    {
      // Strongly exception-safe.
      Value_Ptr temp (other);
      this->swap (temp);
      return *this;
    }
#endif  /* !ACE_LACKS_MEMBER_TEMPLATES */
  private:
#ifndef ACE_LACKS_MEMBER_TEMPLATES
    /// Copying method invoked when copy constructing.
    template <typename U>
    T * create_from (U const * p) const
    {
      return p ? VP_traits<U>::clone (p) : 0;
    }
#else
    // Compiler can't handle member templates so we lose converting
    // copy operations.
    /// Copying method invoked when copy constructing.
    T * create_from (T const * p) const
    {
      return p ? VP_traits<T>::clone (p) : 0;
    }
#endif  /* !ACE_LACKS_MEMBER_TEMPLATES */
  private:
#ifndef ACE_LACKS_MEMBER_TEMPLATES
    template <typename U> friend class Value_Ptr;
#endif  /* !ACE_LACKS_MEMBER_TEMPLATES */
    /// Object owned by this @c Value_Ptr.
    T * p_;
  };
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif  /* ACE_VALUE_PTR_H */

