// -*- C++ -*-
//
// $Id: Time_Value_T.inl 96061 2012-08-16 09:36:07Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator += (const ACE_Time_Value &tv)
{
  this->ACE_Time_Value::operator +=(tv);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator += (time_t tv)
{
  this->ACE_Time_Value::operator +=(tv);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator = (const ACE_Time_Value_T<TIME_POLICY> &tv)
{
  this->time_policy_ = tv.time_policy_;
  this->ACE_Time_Value::operator =(tv);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator = (const ACE_Time_Value &tv)
{
  this->ACE_Time_Value::operator =(tv);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator = (time_t tv)
{
  this->ACE_Time_Value::operator =(tv);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator -= (const ACE_Time_Value &tv)
{
  this->ACE_Time_Value::operator -=(tv);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator -= (time_t tv)
{
  this->ACE_Time_Value::operator -=(tv);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator *= (double d)
{
  this->ACE_Time_Value::operator *=(d);
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> ACE_Time_Value_T<TIME_POLICY>::operator++ (int)
{
  ACE_Time_Value_T<TIME_POLICY> tv (*this);
  ++*this;
  return tv;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator++ (void)
{
  this->ACE_Time_Value::operator ++();
  return *this;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> ACE_Time_Value_T<TIME_POLICY>::operator-- (int)
{
  ACE_Time_Value_T<TIME_POLICY> tv (*this);
  --*this;
  return tv;
}

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY> &ACE_Time_Value_T<TIME_POLICY>::operator-- (void)
{
  this->ACE_Time_Value::operator --();
  return *this;
}

ACE_END_VERSIONED_NAMESPACE_DECL
