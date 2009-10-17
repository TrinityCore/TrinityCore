// -*- C++ -*-
//
// $Id: Stream.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <ACE_SYNCH_DECL> ACE_INLINE ACE_Module<ACE_SYNCH_USE> *
ACE_Stream<ACE_SYNCH_USE>::head (void)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::head");
  return this->stream_head_;
}
template <ACE_SYNCH_DECL> ACE_INLINE ACE_Module<ACE_SYNCH_USE> *
ACE_Stream<ACE_SYNCH_USE>::tail (void)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::tail");
  return this->stream_tail_;
}
template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Stream<ACE_SYNCH_USE>::wait (void)
{
  ACE_TRACE ("ACE_Stream<ACE_SYNCH_USE>::wait");
  return this->final_close_.wait ();
}
template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Stream_Iterator<ACE_SYNCH_USE>::next (const ACE_Module<ACE_SYNCH_USE> *&mod)
{
  ACE_TRACE ("ACE_Stream_Iterator<ACE_SYNCH_USE>::next");
  mod = this->next_;
  return this->next_ != 0;
}
template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Stream_Iterator<ACE_SYNCH_USE>::done (void) const
{
  ACE_TRACE ("ACE_Stream_Iterator<ACE_SYNCH_USE>::done");
  return this->next_ == 0;
}
template <ACE_SYNCH_DECL> int
ACE_Stream_Iterator<ACE_SYNCH_USE>::advance (void)
{
  ACE_TRACE ("ACE_Stream_Iterator<ACE_SYNCH_USE>::advance");
  this->next_ = this->next_->next ();
  return this->next_ != 0;
}
ACE_END_VERSIONED_NAMESPACE_DECL
