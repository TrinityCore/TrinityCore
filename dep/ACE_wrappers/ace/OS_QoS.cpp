//=============================================================================
///**
// *  @file   OS_QoS.cpp
// *
// *  $Id: OS_QoS.cpp 80826 2008-03-04 14:51:23Z wotte $
// *
// *  @brief  Contains OS specific data structures for QoS networking.
// *
// *  @author Craig Rodrigues  <crodrigu@bbn.com>
// */
//=============================================================================
#include "ace/OS_QoS.h"
#include "ace/OS_NS_errno.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_Flow_Spec::ACE_Flow_Spec (unsigned long token_rate,
                              unsigned long token_bucket_size,
                              unsigned long peak_bandwidth,
                              unsigned long latency,
                              unsigned long delay_variation,
                              ACE_SERVICE_TYPE service_type,
                              unsigned long max_sdu_size,
                              unsigned long minimum_policed_size,
                              int ttl,
                              int priority)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->TokenRate = token_rate;
  this->TokenBucketSize = token_bucket_size;
  this->PeakBandwidth = peak_bandwidth;
  this->Latency = latency;
  this->DelayVariation = delay_variation;
#if defined(ACE_HAS_WINSOCK2_GQOS)
  this->ServiceType = service_type;
  this->MaxSduSize = max_sdu_size;
  this->MinimumPolicedSize = minimum_policed_size;
#else
  ACE_UNUSED_ARG (service_type);
  ACE_UNUSED_ARG (max_sdu_size);
  ACE_UNUSED_ARG (minimum_policed_size);
#endif /* ACE_HAS_WINSOCK2_GQOS */
  ACE_UNUSED_ARG (ttl);
  ACE_UNUSED_ARG (priority);
#else
  this->token_rate_ = token_rate;
  this->token_bucket_size_ = token_bucket_size;
  this->peak_bandwidth_ = peak_bandwidth;
  this->latency_ = latency;
  this->delay_variation_ = delay_variation;
  this->service_type_ = service_type;
  this->max_sdu_size_ = max_sdu_size;
  this->minimum_policed_size_ = minimum_policed_size;
  this->ttl_ = ttl;
  this->priority_ = priority;
#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}
ACE_Flow_Spec::ACE_Flow_Spec (void)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  this->TokenRate = 0;
  this->TokenBucketSize = 0;
  this->PeakBandwidth = 0;
  this->Latency = 0;
  this->DelayVariation = 0;
#if defined(ACE_HAS_WINSOCK2_GQOS)
  this->ServiceType = 0;
  this->MaxSduSize = 0;
  this->MinimumPolicedSize = 0;
#endif /* ACE_HAS_WINSOCK2_GQOS */
#else
  this->token_rate_ = 0;
  this->token_bucket_size_ = 0;
  this->peak_bandwidth_ = 0;
  this->latency_ = 0;
  this->delay_variation_ = 0;
  this->service_type_ = 0;
  this->max_sdu_size_ = 0;
  this->minimum_policed_size_ = 0;
  this->ttl_ = 0;
  this->priority_ = 0;
#endif /* defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) */
}
unsigned long
ACE_Flow_Spec::token_rate (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->TokenRate;
#else
  return this->token_rate_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::token_rate (unsigned long tr)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->TokenRate = tr;
#else
  this->token_rate_ = tr;
#endif /* ACE_HAS_WINSOCK2 */
}
unsigned long
ACE_Flow_Spec::token_bucket_size (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->TokenBucketSize;
#else
  return this->token_bucket_size_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::token_bucket_size (unsigned long tbs)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->TokenBucketSize = tbs;
#else
  this->token_bucket_size_ = tbs;
#endif /* ACE_HAS_WINSOCK2 */
}
unsigned long
ACE_Flow_Spec::peak_bandwidth (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->PeakBandwidth;
#else
  return this->peak_bandwidth_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::peak_bandwidth (unsigned long pb)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->PeakBandwidth = pb;
#else
  this->peak_bandwidth_ = pb;
#endif /* ACE_HAS_WINSOCK2 */
}
unsigned long
ACE_Flow_Spec::latency (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->Latency;
#else
  return this->latency_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::latency (unsigned long l)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->Latency = l;
#else
  this->latency_ = l;
#endif /* ACE_HAS_WINSOCK2 */
}
unsigned long
ACE_Flow_Spec::delay_variation (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return this->DelayVariation;
#else
  return this->delay_variation_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::delay_variation (unsigned long dv)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->DelayVariation = dv;
#else
  this->delay_variation_ = dv;
#endif /* ACE_HAS_WINSOCK2 */
}
ACE_SERVICE_TYPE
ACE_Flow_Spec::service_type (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  return this->ServiceType;
#else
  return this->service_type_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::service_type (ACE_SERVICE_TYPE st)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  this->ServiceType = st;
#else
  this->service_type_ = st;
#endif /* ACE_HAS_WINSOCK2 */
}
unsigned long
ACE_Flow_Spec::max_sdu_size (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  return this->MaxSduSize;
#else
  return this->max_sdu_size_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::max_sdu_size (unsigned long mss)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  this->MaxSduSize = mss;
#else
  this->max_sdu_size_ = mss;
#endif /* ACE_HAS_WINSOCK2 */
}
unsigned long
ACE_Flow_Spec::minimum_policed_size (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  return this->MinimumPolicedSize;
#else
  return this->minimum_policed_size_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::minimum_policed_size (unsigned long mps)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  this->MinimumPolicedSize = mps;
#else
  this->minimum_policed_size_ = mps;
#endif /* ACE_HAS_WINSOCK2 */
}
int
ACE_Flow_Spec::ttl (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_NOTSUP_RETURN (-1);
#else
  return this->ttl_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::ttl (int t)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_UNUSED_ARG (t);
  // TBD...
#else
  this->ttl_ = t;
#endif /* ACE_HAS_WINSOCK2 */
}
int
ACE_Flow_Spec::priority (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_NOTSUP_RETURN (-1);
#else
  return this->priority_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_Flow_Spec::priority (int p)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0) && \
    defined (ACE_HAS_WINSOCK2_GQOS)
  ACE_UNUSED_ARG (p);
  // TBD...
#else
  this->priority_ = p;
#endif /* ACE_HAS_WINSOCK2 */
}
ACE_QoS::ACE_QoS (void)
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
#else
  : sending_flowspec_ (0),
    receiving_flowspec_ (0)
#endif /* ACE_HAS_WINSOCK2 */
{
}
ACE_Flow_Spec*
ACE_QoS::sending_flowspec (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return &((ACE_Flow_Spec &) this->SendingFlowspec);
#else
  return this->sending_flowspec_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_QoS::sending_flowspec (ACE_Flow_Spec *fs)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->SendingFlowspec = (FLOWSPEC) (*fs);
#else
  this->sending_flowspec_ = fs;
#endif /* ACE_HAS_WINSOCK2 */
}
ACE_Flow_Spec*
ACE_QoS::receiving_flowspec (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return &((ACE_Flow_Spec &) this->ReceivingFlowspec);
#else
  return receiving_flowspec_;
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_QoS::receiving_flowspec (ACE_Flow_Spec *fs)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->ReceivingFlowspec = (FLOWSPEC) (*fs);
#else
  this->receiving_flowspec_ = fs;
#endif /* ACE_HAS_WINSOCK2 */
}
iovec
ACE_QoS::provider_specific (void) const
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  return (iovec&) this->ProviderSpecific;
#else
  ACE_NOTSUP_RETURN (iovec ());
#endif /* ACE_HAS_WINSOCK2 */
}
void
ACE_QoS::provider_specific (const iovec &ps)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  this->ProviderSpecific = (WSABUF) ((iovec &) ps);
#else
  ACE_UNUSED_ARG (ps);
#endif /* ACE_HAS_WINSOCK2 */
}
ACE_QoS_Params::ACE_QoS_Params (iovec *caller_data,
                                iovec *callee_data,
                                ACE_QoS *socket_qos,
                                ACE_QoS *group_socket_qos,
                                unsigned long flags)
  : caller_data_ (caller_data),
    callee_data_ (callee_data),
    socket_qos_ (socket_qos),
    group_socket_qos_ (group_socket_qos),
    flags_ (flags)
{
}
iovec *
ACE_QoS_Params::caller_data (void) const
{
  return this->caller_data_;
}
void
ACE_QoS_Params::caller_data (iovec *cd)
{
  this->caller_data_ = cd;
}
iovec *
ACE_QoS_Params::callee_data (void) const
{
  return this->callee_data_;
}
void
ACE_QoS_Params::callee_data (iovec *cd)
{
  this->callee_data_ = cd;
}
ACE_QoS *
ACE_QoS_Params::socket_qos (void) const
{
  return this->socket_qos_;
}
void
ACE_QoS_Params::socket_qos (ACE_QoS *sq)
{
  this->socket_qos_ = sq;
}
ACE_QoS *
ACE_QoS_Params::group_socket_qos (void) const
{
  return this->group_socket_qos_;
}
void
ACE_QoS_Params::group_socket_qos (ACE_QoS *gsq)
{
  this->group_socket_qos_ = gsq;
}
unsigned long
ACE_QoS_Params::flags (void) const
{
  return this->flags_;
}
void
ACE_QoS_Params::flags (unsigned long f)
{
  this->flags_ = f;
}
ACE_Accept_QoS_Params::ACE_Accept_QoS_Params (ACE_QOS_CONDITION_FUNC qos_condition_callback,
                                              unsigned long callback_data)
  : qos_condition_callback_ (qos_condition_callback),
    callback_data_ (callback_data)
{
}
ACE_QOS_CONDITION_FUNC
ACE_Accept_QoS_Params::qos_condition_callback (void) const
{
  return this->qos_condition_callback_;
}
void
ACE_Accept_QoS_Params::qos_condition_callback (ACE_QOS_CONDITION_FUNC qcc)
{
  this->qos_condition_callback_ = qcc;
}
unsigned long
ACE_Accept_QoS_Params::callback_data (void) const
{
  return this->callback_data_;
}
void
ACE_Accept_QoS_Params::callback_data (unsigned long cd)
{
  this->callback_data_ = cd;
}
ACE_END_VERSIONED_NAMESPACE_DECL

