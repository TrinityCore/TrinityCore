// -*-C++-*-
//
//$Id: Caching_Strategies_T.inl 80826 2008-03-04 14:51:23Z wotte $

//////////////////////////////////////////////////////////////////////////////////

#include "ace/OS_Memory.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::ACE_Caching_Strategy_Adapter (IMPLEMENTATION *implementation,
                                                                                                         bool delete_implementation)
  : implementation_ (implementation),
    delete_implementation_ (delete_implementation)
{
  if (this->implementation_ == 0)
    {
      ACE_NEW (this->implementation_,
               IMPLEMENTATION);
      this->delete_implementation_ = true;
    }
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::~ACE_Caching_Strategy_Adapter (void)
{
  if (this->delete_implementation_)
    {
      delete this->implementation_;
      this->delete_implementation_ = false;
      this->implementation_ = 0;
    }
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE ATTRIBUTES
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::attributes (void)
{
  return this->implementation_->attributes ();
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE double
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::purge_percent (void)
{
  return this->implementation_->purge_percent ();
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE void
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::purge_percent (double percentage)
{
  this->implementation_->purge_percent (percentage);
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE int
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::notify_bind (int result,
                                                                                        const ATTRIBUTES &attr)
{
  return this->implementation_->notify_bind (result,
                                             attr);
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE int
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::notify_find (int result,
                                                                                        ATTRIBUTES &attr)
{
  return this->implementation_->notify_find (result,
                                             attr);
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE int
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::notify_unbind (int result,
                                                                                          const ATTRIBUTES &attr)
{
  return this->implementation_->notify_unbind (result,
                                               attr);
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE int
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::notify_trybind (int result,
                                                                                           ATTRIBUTES &attr)
{
  return this->implementation_->notify_trybind (result,
                                                attr);
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE int
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::notify_rebind (int result,
                                                                                          const ATTRIBUTES &attr)
{
  return this->implementation_->notify_rebind (result,
                                               attr);
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE IMPLEMENTATION &
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::implementation (void)
{
  return *this->implementation_;
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE CACHING_UTILITY &
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::caching_utility (void)
{
  return this->implementation_->caching_utility ();
}

template<class ATTRIBUTES, class CACHING_UTILITY, class IMPLEMENTATION> ACE_INLINE void
ACE_Caching_Strategy_Adapter<ATTRIBUTES, CACHING_UTILITY, IMPLEMENTATION>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Caching_Strategy_Adapter::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

//////////////////////////////////////////////////////////////////////////////////

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE ATTRIBUTES
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::attributes (void)
{
  return this->timer_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE double
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (void)
{
  return this->purge_percent_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (double percentage)
{
  this->purge_percent_ = percentage;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_bind (
  int result,
  const ATTRIBUTES & /* attr */)
{
  if (result == 0)
    ++this->timer_;

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_find (
  int result,
  ATTRIBUTES &attr)
{
  if (result == 0)
    {
      attr = this->timer_;
      ++this->timer_;
    }

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_unbind (
  int result,
  const ATTRIBUTES & /* attr */)
{
  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_trybind (
  int result,
  ATTRIBUTES & /* attr */)
{
  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_rebind (
  int result,
  const ATTRIBUTES & /* attr */)
{
  if (result == 0)
    ++this->timer_;

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE CACHING_UTILITY &
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::caching_utility (void)
{
  return this->caching_utility_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_LRU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_LRU_Caching_Strategy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("timer_ = %d "), this->timer_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

//////////////////////////////////////////////////////////////////////////////////

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE ATTRIBUTES
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::attributes (void)
{
  return 0;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE double
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (void)
{
  return this->purge_percent_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (double percentage)
{
  this->purge_percent_ = percentage;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_bind (int result,
                                                                    const ATTRIBUTES & /* attr */)
{

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_find (int result,
                                                                    ATTRIBUTES &attr)
{
  if (result == 0)
    ++attr;

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_trybind (int result,
                                                                       ATTRIBUTES & /* attr */)
{
  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_rebind (int result,
                                                                      const ATTRIBUTES & /* attr */)
{
  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_unbind (int result,
                                                                      const ATTRIBUTES & /* attr */)
{
  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE CACHING_UTILITY &
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::caching_utility (void)
{
  return this->caching_utility_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_LFU_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_LFU_Caching_Strategy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

//////////////////////////////////////////////////////////////////////////////////////

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE ATTRIBUTES
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::attributes (void)
{
  return this->order_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE double
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (void)
{
  return this->purge_percent_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (double percentage)
{
  this->purge_percent_ = percentage;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_bind (int result,
                                                                     const ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  if (result == 0)
    ++this->order_;

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_find (int result,
                                                                     ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_unbind (int result,
                                                                       const ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_trybind (int result,
                                                                        ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_rebind (int result,
                                                                       const ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  if (result == 0)
    ++this->order_;

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE CACHING_UTILITY &
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::caching_utility (void)
{
  return this->caching_utility_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_FIFO_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_FIFO_Caching_Strategy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("order_ = %d "), this->order_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

//////////////////////////////////////////////////////////////////////////////////

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE ATTRIBUTES
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::attributes (void)
{
  return 0;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE double
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (void)
{
  return 0;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::purge_percent (double percentage)
{
  ACE_UNUSED_ARG (percentage);
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_bind (int result,
                                                                     const ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_find (int result,
                                                                     ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_unbind (int result,
                                                                       const ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_trybind (int result,
                                                                        ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE int
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::notify_rebind (int result,
                                                                       const ATTRIBUTES &attr)
{
  ACE_UNUSED_ARG (attr);

  return result;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE CACHING_UTILITY &
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::caching_utility (void)
{
  return this->caching_utility_;
}

template<class ATTRIBUTES, class CACHING_UTILITY> ACE_INLINE void
ACE_Null_Caching_Strategy<ATTRIBUTES, CACHING_UTILITY>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Null_Caching_Strategy::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

//////////////////////////////////////////////////////////////////////////////////
