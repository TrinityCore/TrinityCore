// -*- C++ -*-
//
// $Id: Basic_Stats.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Basic_Stats::ACE_Basic_Stats (void)
  : samples_count_ (0)
  , min_ (0)
  , min_at_ (0)
  , max_ (0)
  , max_at_ (0)
  , sum_ (0)
{
}

ACE_INLINE ACE_UINT32
ACE_Basic_Stats::samples_count (void) const
{
  return this->samples_count_;
}

ACE_INLINE void
ACE_Basic_Stats::sample (ACE_UINT64 value)
{
  ++this->samples_count_;

  if (this->samples_count_ == 1u)
    {
      this->min_ = value;
      this->min_at_ = this->samples_count_;
      this->max_ = value;
      this->max_at_ = this->samples_count_;
    }
  else
    {
      if (this->min_ > value)
        {
          this->min_ = value;
          this->min_at_ = this->samples_count_;
        }
      if (this->max_ < value)
        {
          this->max_ = value;
          this->max_at_ = this->samples_count_;
        }
    }

  this->sum_ += value;
}

ACE_END_VERSIONED_NAMESPACE_DECL
