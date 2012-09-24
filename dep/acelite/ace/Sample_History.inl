// -*- C++ -*-
// $Id: Sample_History.inl 95747 2012-05-13 17:14:12Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_Sample_History::sample (ACE_UINT64 value)
{
  if (this->sample_count_ >= this->max_samples_)
    return -1;

  this->samples_[this->sample_count_++] = value;
  return 0;
}

ACE_INLINE ACE_UINT64
ACE_Sample_History::get_sample (size_t i) const
{
  if (this->sample_count_ <= i)
    return 0;

  return this->samples_[i];
}

ACE_INLINE size_t
ACE_Sample_History::max_samples (void) const
{
  return this->max_samples_;
}

ACE_INLINE size_t
ACE_Sample_History::sample_count (void) const
{
  return this->sample_count_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
