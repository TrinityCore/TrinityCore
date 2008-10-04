// $Id: ATM_QoS.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/ATM_QoS.h"

ACE_RCSID(ace, ATM_QoS, "$Id: ATM_QoS.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if defined (ACE_HAS_ATM)

#if !defined (__ACE_INLINE__)
#include "ace/ATM_QoS.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_FORE_ATM_XTI) || defined (ACE_HAS_FORE_ATM_WS2)
#define BHLI_MAGIC "FORE_ATM"
// This is line rate in cells/s for an OC-3 MM interface.
const long ACE_ATM_QoS::LINE_RATE = 353207;
const int ACE_ATM_QoS::OPT_FLAGS_CPID = 0x1;
const int ACE_ATM_QoS::OPT_FLAGS_PMP = 0x2;
const int ACE_ATM_QoS::DEFAULT_SELECTOR = 0x99;
const int ACE_ATM_QoS::DEFAULT_PKT_SIZE = 8192;
#elif defined (ACE_HAS_LINUX_ATM)
//pbrandao:for Linux:
//pbrandao:for now stick with current definitions
//pbrandao:see if later need to change
const long ACE_ATM_QoS::LINE_RATE = 353207;
const int ACE_ATM_QoS::OPT_FLAGS_CPID = 0x1;
const int ACE_ATM_QoS::OPT_FLAGS_PMP = 0x2;
const int ACE_ATM_QoS::DEFAULT_SELECTOR = 0x99;
const int ACE_ATM_QoS::DEFAULT_PKT_SIZE = 8192;
#else
const long ACE_ATM_QoS::LINE_RATE = 0L;
const int ACE_ATM_QoS::OPT_FLAGS_CPID = 0;
const int ACE_ATM_QoS::OPT_FLAGS_PMP = 0;
const int ACE_ATM_QoS::DEFAULT_SELECTOR = 0x0;
const int ACE_ATM_QoS::DEFAULT_PKT_SIZE = 0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */

ACE_ALLOC_HOOK_DEFINE(ACE_ATM_QoS)

ACE_ATM_QoS::ACE_ATM_QoS (int pktSize)
{
  ACE_TRACE ("ACE_ATM_QoS::ACE_ATM_QoS");
#if defined (ACE_HAS_LINUX_ATM)
    ACE_OS::memset(&qos_, 0, sizeof(qos_));
    qos_.aal = ATM_PROTOCOL_DEFAULT;
    qos_.rxtp.traffic_class = ATM_ANYCLASS;
    qos_.rxtp.max_sdu = pktSize;
    qos_.txtp.traffic_class = ATM_ANYCLASS;
    qos_.txtp.max_sdu = pktSize;
#else
    ACE_UNUSED_ARG (pktSize);
#endif /* ACE_HAS_LINUX_ATM */
}

ACE_ATM_QoS::ACE_ATM_QoS(int rate,
                         int pktSize)
{
  ACE_TRACE( "ACE_ATM_QoS::ACE_ATM_QoS" );
#if defined (ACE_HAS_FORE_ATM_WS2)
  AAL_PARAMETERS_IE ie_aalparams;
  ATM_TRAFFIC_DESCRIPTOR_IE ie_td;
  ATM_BROADBAND_BEARER_CAPABILITY_IE ie_bbc;
  ATM_QOS_CLASS_IE ie_qos;
  Q2931_IE *ie_ptr;
  int size;

  // Setting up cbr parameters ...
  ie_aalparams.AALType = AALTYPE_5;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.ForwardMaxCPCSSDUSize
    = pktSize; // was 1516;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.BackwardMaxCPCSSDUSize
    = pktSize; // was 1516;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.Mode = AAL5_MODE_MESSAGE;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.SSCSType = AAL5_SSCS_NULL;

  size = sizeof(Q2931_IE_TYPE) + sizeof(ULONG) + sizeof(AAL_PARAMETERS_IE);

  ie_td.Forward.PeakCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Forward.PeakCellRate_CLP01 = rate;
  ie_td.Forward.SustainableCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Forward.SustainableCellRate_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Forward.MaxBurstSize_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Forward.MaxBurstSize_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Forward.Tagging = SAP_FIELD_ABSENT;

  ie_td.Backward.PeakCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Backward.PeakCellRate_CLP01 = rate;
  ie_td.Backward.SustainableCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Backward.SustainableCellRate_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Backward.MaxBurstSize_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Backward.MaxBurstSize_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Backward.Tagging = SAP_FIELD_ABSENT;

  ie_td.BestEffort = 0; // Note: this must be set to zero for CBR.

  size += sizeof( Q2931_IE_TYPE )
    + sizeof( ULONG )
    + sizeof( ATM_TRAFFIC_DESCRIPTOR_IE );

  ie_bbc.BearerClass = BCOB_X;
  ie_bbc.TrafficType = TT_CBR;
  ie_bbc.TimingRequirements = TR_END_TO_END;
  ie_bbc.ClippingSusceptability = CLIP_NOT;
  ie_bbc.UserPlaneConnectionConfig = UP_P2P;

  size += sizeof( Q2931_IE_TYPE )
    + sizeof( ULONG )
    + sizeof( ATM_BROADBAND_BEARER_CAPABILITY_IE );

  ie_qos.QOSClassForward = QOS_CLASS1;
  ie_qos.QOSClassBackward = QOS_CLASS1; // This may not be really used
  // since we do only simplex data xfer.

  size += sizeof(Q2931_IE_TYPE) + sizeof(ULONG) + sizeof(ATM_QOS_CLASS_IE);

  qos_.ProviderSpecific.buf = (char *) ACE_OS::malloc(size);
  if (qos_.ProviderSpecific.buf == 0) {
    ACE_ERROR((LM_ERROR,
               ACE_TEXT ("ACE_ATM_QoS::ACE_ATM_QoS: Unable to allocate %d bytes for qos_.ProviderSpecific.buf\n"),
               size));
    return;
  }
  qos_.ProviderSpecific.len = size;
  ACE_OS::memset(qos_.ProviderSpecific.buf, 0, size);

  ie_ptr = (Q2931_IE *) qos_.ProviderSpecific.buf;
  ie_ptr->IEType = IE_AALParameters;
  ie_ptr->IELength = sizeof( Q2931_IE_TYPE )
    + sizeof( ULONG )
    + sizeof( AAL_PARAMETERS_IE );
  ACE_OS::memcpy(ie_ptr->IE, &ie_aalparams, sizeof(AAL_PARAMETERS_IE));

  ie_ptr = (Q2931_IE *) ((char *)ie_ptr + ie_ptr->IELength);
  ie_ptr->IEType = IE_TrafficDescriptor;
  ie_ptr->IELength = sizeof( Q2931_IE_TYPE )
    + sizeof( ULONG )
    + sizeof( ATM_TRAFFIC_DESCRIPTOR_IE );
  ACE_OS::memcpy(ie_ptr->IE, &ie_td, sizeof(ATM_TRAFFIC_DESCRIPTOR_IE));

  ie_ptr = (Q2931_IE *) ((char *)ie_ptr + ie_ptr->IELength);
  ie_ptr->IEType = IE_BroadbandBearerCapability;
  ie_ptr->IELength = sizeof( Q2931_IE_TYPE )
    + sizeof( ULONG )
    + sizeof( ATM_BROADBAND_BEARER_CAPABILITY_IE );
  ACE_OS::memcpy(ie_ptr->IE,
                 &ie_bbc,
                 sizeof(ATM_BROADBAND_BEARER_CAPABILITY_IE));

  ie_ptr = (Q2931_IE *) ((char *)ie_ptr + ie_ptr->IELength);
  ie_ptr->IEType = IE_QOSClass;
  ie_ptr->IELength = sizeof( Q2931_IE_TYPE )
    + sizeof( ULONG )
    + sizeof( ATM_QOS_CLASS_IE );
  ACE_OS::memcpy(ie_ptr->IE, &ie_qos, sizeof(ATM_QOS_CLASS_IE));

  //    qos_.SendingFlowspec.TokenRate = 0xffffffff;
  //    qos_.SendingFlowspec.TokenBucketSize = 0xffffffff;
  //    qos_.SendingFlowspec.PeakBandwidth = 0xffffffff;
  //    qos_.SendingFlowspec.Latency = 0xffffffff;
  //    qos_.SendingFlowspec.DelayVariation = 0xffffffff;
  //    qos_.SendingFlowspec.ServiceType = SERVICETYPE_BESTEFFORT;
  // This will most probably be ignored by the service provider.
  //    qos_.SendingFlowspec.MaxSduSize = 0xffffffff;
  //    qos_.SendingFlowspec.MinimumPolicedSize = 0xffffffff;

  //    qos_.ReceivingFlowspec.TokenRate = 0xffffffff;
  //    qos_.ReceivingFlowspec.TokenBucketSize = 0xffffffff;
  //    qos_.ReceivingFlowspec.PeakBandwidth = 0xffffffff;
  //    qos_.ReceivingFlowspec.Latency = 0xffffffff;
  //    qos_.ReceivingFlowspec.DelayVariation = 0xffffffff;
  //    qos_.ReceivingFlowspec.ServiceType = SERVICETYPE_BESTEFFORT;
  // This will most probably be ignored by the service provider.
  //    qos_.ReceivingFlowspec.MaxSduSize = 0xffffffff;
  //    qos_.ReceivingFlowspec.MinimumPolicedSize = 0;

  ACE_Flow_Spec send_fspec( 0xffffffff,
                            0xffffffff,
                            0xffffffff,
                            0xffffffff,
                            0xffffffff,
                            SERVICETYPE_BESTEFFORT,
                            // This will most probably ignored by SP.
                            0xffffffff,
                            0xffffffff,
                            15,
                            ACE_DEFAULT_THREAD_PRIORITY ),
    recv_fspec( 0xffffffff,
                0xffffffff,
                0xffffffff,
                0xffffffff,
                0xffffffff,
                SERVICETYPE_BESTEFFORT,
                // This will most probably ignored by SP.
                0xffffffff,
                0,
                15,
                ACE_DEFAULT_THREAD_PRIORITY );

  qos_.sending_flowspec (send_fspec);
  qos_.receiving_flowspec (recv_fspec);
#elif defined (ACE_HAS_FORE_ATM_XTI)
  ACE_UNUSED_ARG (rate);
  ACE_UNUSED_ARG (pktSize);
#elif defined (ACE_HAS_LINUX_ATM)
  ACE_OS::memset(&qos_,
                 0,
                 sizeof(qos_));
  qos_.aal = ATM_PROTOCOL_DEFAULT;
  qos_.rxtp.max_sdu = pktSize;

  if (rate > 0) {
    qos_.rxtp.pcr = rate;
    qos_.rxtp.traffic_class = ATM_CBR;
    qos_.txtp.traffic_class = ATM_CBR;
    qos_.txtp.pcr = rate;
  }
  else {
    qos_.rxtp.traffic_class = ATM_UBR;
    qos_.txtp.traffic_class = ATM_UBR;
  }

  qos_.txtp.max_sdu = pktSize;
#else
  ACE_UNUSED_ARG (rate);
#endif /* ACE_HAS_FORE_ATM_WS2 || ACE_HAS_FORE_ATM_XTI || ACE_HAS_LINUX_ATM */
}

void
ACE_ATM_QoS::set_cbr_rate (int rate,
                           int pktSize)
{
  ACE_TRACE ("ACE_ATM_QoS::set_cbr_rate");
#if defined (ACE_HAS_FORE_ATM_WS2)
  /*
  AAL_PARAMETERS_IE ie_aalparams;
  ATM_TRAFFIC_DESCRIPTOR_IE ie_td;
  ATM_BROADBAND_BEARER_CAPABILITY_IE ie_bbc;
  ATM_QOS_CLASS_IE ie_qos;
  Q2931_IE *ie_ptr;
  int size;
  */

  ACE_OS::printf( "ATM_QoS(set_cbr_rate): set rate to %d c/s\n", rate );

  // Setting up cbr parameters ...
  /*
  FORE has changed this - we no longer specify QoS this way
  ie_aalparams.AALType = AALTYPE_5;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.ForwardMaxCPCSSDUSize
    = pktSize; // was 1516;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.BackwardMaxCPCSSDUSize
    = pktSize; // was 1516;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.Mode = AAL5_MODE_MESSAGE;
  ie_aalparams.AALSpecificParameters.AAL5Parameters.SSCSType = AAL5_SSCS_NULL;

  size = sizeof(Q2931_IE_TYPE) + sizeof(ULONG) + sizeof(AAL_PARAMETERS_IE);

  ie_td.Forward.PeakCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Forward.PeakCellRate_CLP01 = rate;
  ie_td.Forward.SustainableCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Forward.SustainableCellRate_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Forward.MaxBurstSize_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Forward.MaxBurstSize_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Forward.Tagging = SAP_FIELD_ABSENT;

  ie_td.Backward.PeakCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Backward.PeakCellRate_CLP01 = rate;
  ie_td.Backward.SustainableCellRate_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Backward.SustainableCellRate_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Backward.MaxBurstSize_CLP0 = SAP_FIELD_ABSENT;
  ie_td.Backward.MaxBurstSize_CLP01 = SAP_FIELD_ABSENT;
  ie_td.Backward.Tagging = SAP_FIELD_ABSENT;

  ie_td.BestEffort = 0; // Note: this must be set to zero for CBR.

  size += sizeof( Q2931_IE_TYPE ) +
          sizeof( ULONG ) +
          sizeof( ATM_TRAFFIC_DESCRIPTOR_IE );

  ie_bbc.BearerClass = BCOB_X;
  ie_bbc.TrafficType = TT_CBR;
  ie_bbc.TimingRequirements = TR_END_TO_END;
  ie_bbc.ClippingSusceptability = CLIP_NOT;
  ie_bbc.UserPlaneConnectionConfig = UP_P2P;

  size += sizeof(Q2931_IE_TYPE) +
          sizeof(ULONG) +
          sizeof(ATM_BROADBAND_BEARER_CAPABILITY_IE);

  ie_qos.QOSClassForward = QOS_CLASS1;
  ie_qos.QOSClassBackward = QOS_CLASS1; // This may not be really used
  // since we only simplex data xfer.

  size += sizeof(Q2931_IE_TYPE) + sizeof(ULONG) + sizeof(ATM_QOS_CLASS_IE);

  qos_.ProviderSpecific.buf = (char *) ACE_OS::malloc(size);
  if (qos_.ProviderSpecific.buf == 0) {
    ACE_ERROR((LM_ERROR,
               ACE_TEXT ("ACE_ATM_QoS::ACE_ATM_QoS: Unable to allocate %d bytes for qos_.ProviderSpecific.buf\n"),
               size));
    return;
  }
  qos_.ProviderSpecific.len = size;
  ACE_OS::memset(qos_.ProviderSpecific.buf, 0, size);

  ie_ptr = (Q2931_IE *) qos_.ProviderSpecific.buf;
  ie_ptr->IEType = IE_AALParameters;
  ie_ptr->IELength = sizeof( Q2931_IE_TYPE ) +
                     sizeof( ULONG ) +
                     sizeof( AAL_PARAMETERS_IE );
  ACE_OS::memcpy(ie_ptr->IE, &ie_aalparams, sizeof(AAL_PARAMETERS_IE));

  ie_ptr = (Q2931_IE *) ((char *)ie_ptr + ie_ptr->IELength);
  ie_ptr->IEType = IE_TrafficDescriptor;
  ie_ptr->IELength = sizeof( Q2931_IE_TYPE ) +
                     sizeof( ULONG ) +
                     sizeof( ATM_TRAFFIC_DESCRIPTOR_IE );
  ACE_OS::memcpy(ie_ptr->IE, &ie_td, sizeof(ATM_TRAFFIC_DESCRIPTOR_IE));

  ie_ptr = (Q2931_IE *) ((char *)ie_ptr + ie_ptr->IELength);
  ie_ptr->IEType = IE_BroadbandBearerCapability;
  ie_ptr->IELength = sizeof( Q2931_IE_TYPE ) +
                     sizeof( ULONG ) +
                     sizeof( ATM_BROADBAND_BEARER_CAPABILITY_IE );
  ACE_OS::memcpy( ie_ptr->IE,
                  &ie_bbc,
                  sizeof( ATM_BROADBAND_BEARER_CAPABILITY_IE ));

  ie_ptr = (Q2931_IE *) ((char *)ie_ptr + ie_ptr->IELength);
  ie_ptr->IEType = IE_QOSClass;
  ie_ptr->IELength = sizeof(Q2931_IE_TYPE) + sizeof(ULONG) +
                     sizeof(ATM_QOS_CLASS_IE);
  ACE_OS::memcpy(ie_ptr->IE, &ie_qos, sizeof(ATM_QOS_CLASS_IE));
  */

  const int BYTES_PER_ATM_CELL = 53;
  ACE_OS::memset(&qos_, 0, sizeof(ATM_QoS));
  // Setting the token rate sets the minimum rate. 3 Mbits/sec seems too high.
  //  Certainly for Vaudeville audio, we only need about 1000 c/s which is
  //  424000 bits/sec which is 53000 bytes/sec.
  //qos_.SendingFlowspec.TokenRate = 3*(1024*128);      // 3Mbits/sec
  qos_.SendingFlowspec.TokenRate = 53000;               // 1000 cells/sec
  qos_.SendingFlowspec.TokenBucketSize = 32*1024;       // our block size
  //ourQos.SendingFlowspec.PeakBandwidth = ourQos.SendingFlowspec.TokenRate;
  qos_.SendingFlowspec.ServiceType = SERVICETYPE_GUARANTEED;
  // Peak bandwidth is in bytes/sec. The rate is specified in cells/sec so
  //  we need to convert from cells/sec to bytes/sec (i.e., multiply by 53).
  qos_.SendingFlowspec.PeakBandwidth = rate * BYTES_PER_ATM_CELL;
  qos_.SendingFlowspec.Latency = -1;    // we don't care too much
  qos_.SendingFlowspec.DelayVariation = -1; // we don't care too much
  // no provider-specific data allowed on ATM
  qos_.ProviderSpecific.buf=0;
  qos_.ProviderSpecific.len=0;
  // unidirectional P2MP; we don't need to setup the Receiving flowspec

  //qos_.SendingFlowspec.TokenRate = 0xffffffff;
  //qos_.SendingFlowspec.TokenBucketSize = 0xffffffff;
  //qos_.SendingFlowspec.PeakBandwidth = 0xffffffff;
  //qos_.SendingFlowspec.Latency = 0xffffffff;
  //qos_.SendingFlowspec.DelayVariation = 0xffffffff;
  //qos_.SendingFlowspec.ServiceType = SERVICETYPE_BESTEFFORT;
  // This will most probably be ignored by the service provider.
  //qos_.SendingFlowspec.MaxSduSize = 0xffffffff;
  //qos_.SendingFlowspec.MinimumPolicedSize = 0xffffffff;

  //qos_.ReceivingFlowspec.TokenRate = 0xffffffff;
  //qos_.ReceivingFlowspec.TokenBucketSize = 0xffffffff;
  //qos_.ReceivingFlowspec.PeakBandwidth = 0xffffffff;
  //qos_.ReceivingFlowspec.Latency = 0xffffffff;
  //qos_.ReceivingFlowspec.DelayVariation = 0xffffffff;
  //qos_.ReceivingFlowspec.ServiceType = SERVICETYPE_BESTEFFORT;
  // This will most probably be ignored by the service provider.
  //qos_.ReceivingFlowspec.MaxSduSize = 0xffffffff;
  //qos_.ReceivingFlowspec.MinimumPolicedSize = 0;

  /*
  ACE_Flow_Spec send_fspec( 0xffffffff,
                            0xffffffff,
                            0xffffffff,
                            0xffffffff,
                            0xffffffff,
                            SERVICETYPE_BESTEFFORT,
                            // This will most probably ignored by SP.
                            0xffffffff,
                            0xffffffff,
                            15,
                            ACE_DEFAULT_THREAD_PRIORITY ),
  recv_fspec( 0xffffffff,
              0xffffffff,
              0xffffffff,
              0xffffffff,
              0xffffffff,
              SERVICETYPE_BESTEFFORT,
              // This will most probably ignored by SP.
              0xffffffff,
              0,
              15,
              ACE_DEFAULT_THREAD_PRIORITY );

  qos_.sending_flowspec( send_fspec );
  qos_.receiving_flowspec( recv_fspec );
  */
#elif defined (ACE_HAS_FORE_ATM_XTI)
  ACE_UNUSED_ARG (rate);
  ACE_UNUSED_ARG (pktSize);
#elif defined (ACE_HAS_LINUX_ATM)
  ACE_UNUSED_ARG (pktSize);

  qos_.rxtp.traffic_class = ATM_CBR;
  qos_.rxtp.pcr = rate;
  qos_.txtp.traffic_class = ATM_CBR;
  qos_.txtp.pcr = rate;
#else
  ACE_UNUSED_ARG (rate);
#endif /* ACE_HAS_FORE_ATM_WS2 || ACE_HAS_FORE_ATM_XTI || ACE_HAS_LINUX_ATM */
}

void
ACE_ATM_QoS::set_rate (ACE_HANDLE fd,
                       int rate,
                       int flags)
{
  ACE_TRACE ("ACE_ATM_QoS::set_rate");
#if defined (ACE_HAS_FORE_ATM_WS2) || defined (ACE_HAS_LINUX_ATM)
  set_cbr_rate( rate );

  ACE_UNUSED_ARG( fd );
  ACE_UNUSED_ARG( flags );
#elif defined (ACE_HAS_FORE_ATM_XTI)
  long optlen = 0;
  qos_.buf = construct_options(fd,
                               rate,
                               flags,
                               &optlen);
  qos_.len = optlen;
#else
  ACE_UNUSED_ARG (rate);
#endif /* ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM || ACE_HAS_FORE_ATM_XTI */
}

char*
ACE_ATM_QoS::construct_options (ACE_HANDLE fd,
                                int rate,
                                int flags,
                                long *len)
{
#if defined (ACE_HAS_FORE_ATM_WS2) || defined (ACE_HAS_LINUX_ATM)
  ACE_UNUSED_ARG (fd);
  ACE_UNUSED_ARG (rate);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (len);
  return (0);
#elif defined (ACE_HAS_FORE_ATM_XTI)
  struct t_opthdr *popt;
  char *buf;
  int qos_cells;
  struct t_info info;

  if (ACE_OS::t_getinfo (fd, &info) == -1)
    {
      ACE_OS::t_error ("t_getinfo");
      return 0;
    }

  buf = (char *) ACE_OS::malloc (info.options);

  if (buf == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Unable to allocate %d bytes for options\n"),
                       info.options),
                      0);

  popt = (struct t_opthdr *) buf;

  if (flags & OPT_FLAGS_CPID)
    {
      // This constructs the T_ATM_ORIG_ADDR option, which is used to
      // signal the UNI 3.1 Calling Party ID Information Element.
      t_atm_addr *source_addr;

      popt->len = sizeof (struct t_opthdr) + sizeof (t_atm_addr);
      popt->level = T_ATM_SIGNALING;
      popt->name = T_ATM_ORIG_ADDR;
      popt->status = 0;

      source_addr =
        (t_atm_addr *)((char *) popt + sizeof (struct t_opthdr));

      source_addr->address_format = T_ATM_ENDSYS_ADDR;
      source_addr->address_length = ATMNSAP_ADDR_LEN;

      ATMSAPAddress local_addr;
      struct t_bind boundaddr;

      boundaddr.addr.maxlen = sizeof(local_addr);
      boundaddr.addr.buf = (char *) &local_addr;

      //if (ACE_OS::t_getprotaddr(fd, &boundaddr, 0) < 0) {
      if (ACE_OS::t_getname(fd,
                            &boundaddr.addr,
                            LOCALNAME) < 0)
        {
          ACE_OS::t_error("t_getname (local_address)");
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("Can't get local address!\n")));
          ACE_OS::free (buf);
          return 0;
        }

      ACE_OS::memcpy(source_addr->address,
                     local_addr.sap.t_atm_sap_addr.address,
                     ATMNSAP_ADDR_LEN);

      popt = T_OPT_NEXTHDR (buf, info.options , popt);
    }

  // This constructs all options necessary (bearer cap., QoS, and
  // Traffic Descriptor) to signal for a CBR connection with the
  // specified QoS in kbit/sec., and/or specify a PMP connection.

  // For FORE 200e cards, the adapter shapes traffic to CBR with rate
  // equal to PCR CLP=0+1 (traffic.forward.PCR_all_traffic)

  qos_cells = (rate * 1000) / (48*8);

  if ((qos_cells > 0 && qos_cells < LINE_RATE)
      || (ACE_BIT_ENABLED (flags, OPT_FLAGS_PMP)))
    {
      struct t_atm_bearer *bearer;
      struct t_atm_traffic *traffic;

      // T_ATM_BEARER_CAP: Broadband bearer capability
      popt->len = sizeof (struct t_opthdr) + sizeof (struct t_atm_bearer);
      popt->level = T_ATM_SIGNALING;
      popt->name = T_ATM_BEARER_CAP;
      popt->status = 0;

      bearer = (struct t_atm_bearer *)((char *) popt +
                                       sizeof (struct t_opthdr));
      bearer->bearer_class = T_ATM_CLASS_X;

      if (qos_cells)
        {
          bearer->traffic_type = T_ATM_CBR;
          bearer->timing_requirements = T_ATM_END_TO_END;
        }
      else
        {
          bearer->traffic_type   = 0; // UBR
          bearer->timing_requirements = 0;
        }
      bearer->clipping_susceptibility = T_ATM_NULL;

      if (ACE_BIT_ENABLED (flags, OPT_FLAGS_PMP))
        bearer->connection_configuration = T_ATM_1_TO_MANY;
      else
        bearer->connection_configuration = T_ATM_1_TO_1;

      popt = T_OPT_NEXTHDR (buf, info.options, popt);

      // T_ATM_TRAFFIC: traffic descriptor
      popt->len = sizeof (struct t_opthdr) + sizeof (struct t_atm_traffic);
      popt->level = T_ATM_SIGNALING;
      popt->name = T_ATM_TRAFFIC;
      popt->status = 0;

      traffic = (struct t_atm_traffic *)((char *) popt +
                                         sizeof (struct t_opthdr));

      traffic->forward.PCR_high_priority = T_ATM_ABSENT;
      traffic->forward.PCR_all_traffic = qos_cells ? qos_cells : LINE_RATE;
      traffic->forward.SCR_high_priority = T_ATM_ABSENT;
      traffic->forward.SCR_all_traffic = T_ATM_ABSENT;
      traffic->forward.MBS_high_priority = T_ATM_ABSENT;
      traffic->forward.MBS_all_traffic = T_ATM_ABSENT;
      traffic->forward.tagging = T_NO;

      traffic->backward.PCR_high_priority = T_ATM_ABSENT;
      traffic->backward.PCR_all_traffic =
        (ACE_BIT_ENABLED (flags, OPT_FLAGS_PMP))
        ? 0 : qos_cells ? qos_cells : LINE_RATE;
      traffic->backward.SCR_high_priority = T_ATM_ABSENT;
      traffic->backward.SCR_all_traffic = T_ATM_ABSENT;
      traffic->backward.MBS_high_priority = T_ATM_ABSENT;
      traffic->backward.MBS_all_traffic = T_ATM_ABSENT;
      traffic->backward.tagging = T_NO;

      traffic->best_effort = qos_cells ? T_NO : T_YES;

      popt = T_OPT_NEXTHDR (buf,
                            info.options,
                            popt);
    }

  if (qos_cells > 0 && qos_cells < LINE_RATE)
    {
      struct t_atm_qos *qos;

      // T_ATM_QOS: Quality of Service
      popt->len = sizeof (struct t_opthdr) + sizeof (struct t_atm_qos);
      popt->level = T_ATM_SIGNALING;
      popt->name = T_ATM_QOS;
      popt->status = 0;

      qos = (struct t_atm_qos *)((char *) popt + sizeof (struct t_opthdr));
      qos->coding_standard = T_ATM_ITU_CODING;
      qos->forward.qos_class = T_ATM_QOS_CLASS_1;
      qos->backward.qos_class = T_ATM_QOS_CLASS_1;

      popt = T_OPT_NEXTHDR (buf, info.options, popt);
    }

  // Return actual size of options and option buffer to user.
  *len = (char *) popt - buf;

  return buf;
#else
  ACE_UNUSED_ARG (fd);
  ACE_UNUSED_ARG (rate);
  ACE_UNUSED_ARG (flag);
  ACE_UNUSED_ARG (len);
  return (0);
#endif /* ACE_HAS_FORE_ATM_WS2 */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_ATM */

