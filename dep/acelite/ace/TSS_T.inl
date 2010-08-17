// -*- C++ -*-
//
// $Id: TSS_T.inl 91124 2010-07-19 11:54:35Z vzykov $

#include "ace/Thread.h"
#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if !(defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION)))

template <class TYPE> ACE_INLINE
ACE_TSS<TYPE>::ACE_TSS (TYPE *type)
  : type_ (type)
{
}

template <class TYPE> ACE_INLINE int
ACE_TSS<TYPE>::ts_init (void)
{
  return 0;
}

template <class TYPE> ACE_INLINE TYPE *
ACE_TSS<TYPE>::ts_object (void) const
{
  return this->type_;
}

template <class TYPE> ACE_INLINE TYPE *
ACE_TSS<TYPE>::ts_object (TYPE *type)
{
  this->type_ = type;
  return this->type_;
}

template <class TYPE> ACE_INLINE TYPE *
ACE_TSS<TYPE>::ts_get (void) const
{
  return this->type_;
}

#else

# if defined (ACE_HAS_THR_C_DEST)
template <class TYPE> ACE_INLINE ACE_TSS_Adapter *
ACE_TSS<TYPE>::ts_value (void) const
{
  // Get the tss adapter from thread-specific storage
  void *temp = 0;
  if (ACE_Thread::getspecific (this->key_, &temp) == -1)
    {
      return 0; // This should not happen!
    }
  return static_cast <ACE_TSS_Adapter *> (temp);
}
# else
template <class TYPE> ACE_INLINE TYPE *
ACE_TSS<TYPE>::ts_value (void) const
{
  void *temp = 0;
  if (ACE_Thread::getspecific (this->key_, &temp) == -1)
    {
      return 0; // This should not happen!
    }
  return static_cast <TYPE *> (temp);
}
# endif /* ACE_HAS_THR_C_DEST */

# if defined (ACE_HAS_THR_C_DEST)
template <class TYPE> ACE_INLINE int
ACE_TSS<TYPE>::ts_value (ACE_TSS_Adapter *new_tss_adapter) const
{
  if (ACE_Thread::setspecific (this->key_,
                               (void *) new_tss_adapter) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("ACE_Thread::setspecific() failed!")));
      return -1;
    }

  return 0;
}
# else
template <class TYPE> ACE_INLINE int
ACE_TSS<TYPE>::ts_value (TYPE *new_ts_obj) const
{
  if (ACE_Thread::setspecific (this->key_, (void *) new_ts_obj) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("ACE_Thread::setspecific() failed!")));
      return -1;
    }

  return 0;
}
# endif /* ACE_HAS_THR_C_DEST */

#endif /* ! (defined (ACE_HAS_THREADS) && (defined (ACE_HAS_THREAD_SPECIFIC_STORAGE) || defined (ACE_HAS_TSS_EMULATION))) */

ACE_END_VERSIONED_NAMESPACE_DECL
