// -*- C++ -*-
//
// $Id: Auto_Functor.inl 92386 2010-10-28 07:44:37Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename X, typename Functor> ACE_INLINE
ACE_Utils::Auto_Functor_Ref<X,Functor>::
Auto_Functor_Ref(X * p, Functor f)
  : p_(p)
  , f_(f)
{
}

template<typename X, typename Functor> ACE_INLINE
ACE_Utils::Auto_Functor<X,Functor>::Auto_Functor(X * p, Functor f)
  : p_(p)
  , f_(f)
{
}

template<typename X, typename Functor> ACE_INLINE
ACE_Utils::Auto_Functor<X,Functor>::Auto_Functor(Auto_Functor & rhs)
  : p_(rhs.release())
  , f_(rhs.f_)
{
}

template<typename X, typename Functor>
ACE_INLINE ACE_Utils::Auto_Functor<X,Functor>&
ACE_Utils::Auto_Functor<X,Functor>:: operator=(Auto_Functor & rhs)
{
  reset(rhs.release());
  f_ = rhs.f_;
  return *this;
}

template<typename X, typename Functor> template<typename Y> ACE_INLINE
ACE_Utils::Auto_Functor<X,Functor>::Auto_Functor(Auto_Functor<Y,Functor>& rhs)
  : p_(rhs.release())
  , f_(rhs.f_)
{
}

template<typename X, typename Functor> template<typename Y>
ACE_INLINE ACE_Utils::Auto_Functor<X,Functor>&
ACE_Utils::Auto_Functor<X,Functor>::operator=(Auto_Functor<Y,Functor>& rhs)
{
  reset(rhs.release());
  return *this;
}

template<typename X, typename Functor> ACE_INLINE X &
ACE_Utils::Auto_Functor<X,Functor>::operator*() const
{
  return *p_;
}

template<typename X, typename Functor>
ACE_INLINE X *
ACE_Utils::Auto_Functor<X,Functor>::operator->() const
{
  return p_;
}

template<typename X, typename Functor>
ACE_INLINE X *
ACE_Utils::Auto_Functor<X,Functor>::get()
{
  return p_;
}

template<typename X, typename Functor>
ACE_INLINE X *
ACE_Utils::Auto_Functor<X,Functor>::release()
{
  X * tmp = p_;
  p_ = 0;
  return tmp;
}

template<typename X, typename Functor>
ACE_INLINE Functor const &
ACE_Utils::Auto_Functor<X,Functor>::functor() const
{
  return f_;
}

template<typename X, typename Functor> ACE_INLINE
ACE_Utils::Auto_Functor<X,Functor>::Auto_Functor(Auto_Functor_Ref<X,Functor> rhs)
  : p_(rhs.p_)
  , f_(rhs.f_)
{
}

template<typename X, typename Functor>
ACE_INLINE ACE_Utils::Auto_Functor<X,Functor> &
ACE_Utils::Auto_Functor<X,Functor>::operator=(Auto_Functor_Ref<X,Functor> rhs)
{
  if(rhs.p_ != p_)
  {
    reset(rhs.p_);
    f_ = rhs.f_;
  }
  return *this;
}

template<typename X, typename Functor> template<typename Y> ACE_INLINE
ACE_Utils::Auto_Functor<X,Functor>::operator ACE_Utils::Auto_Functor_Ref<Y,Functor>()
{
  return ACE_Utils::Auto_Functor_Ref<Y,Functor>(release(), f_);
}

template<typename X, typename Functor> template<typename Y> ACE_INLINE
ACE_Utils::Auto_Functor<X,Functor>::operator ACE_Utils::Auto_Functor<Y,Functor>()
{
  return ACE_Utils::Auto_Functor<Y,Functor>(release(), f_);
}

ACE_END_VERSIONED_NAMESPACE_DECL
