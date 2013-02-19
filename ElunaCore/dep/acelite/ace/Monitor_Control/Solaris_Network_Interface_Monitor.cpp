// $Id: Solaris_Network_Interface_Monitor.cpp 91813 2010-09-17 07:52:52Z johnnyw $

#include "ace/Monitor_Control/Solaris_Network_Interface_Monitor.h"

#if defined (ACE_HAS_KSTAT)

#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
{
  namespace Monitor_Control
  {
    Solaris_Network_Interface_Monitor::Solaris_Network_Interface_Monitor (
      const ACE_TCHAR *lookup_str)
      : value_ (0UL),
        start_ (0UL),
        lookup_str_ (lookup_str)
    {
      this->init ();
    }

    void
    Solaris_Network_Interface_Monitor::update_i (void)
    {
      this->access_kstats (this->value_);
      this->value_ -= this->start_;
    }

    void
    Solaris_Network_Interface_Monitor::clear_impl (void)
    {
      this->init ();
    }

    void
    Solaris_Network_Interface_Monitor::init (void)
    {
      unsigned long i;

      for (i = 0UL; i < MAX_LO_INTERFACES; ++i)
        {
          this->value_array_lo_[i] = 0UL;
        }

      for (i = 0UL; i < MAX_HME_INTERFACES; ++i)
        {
          this->value_array_hme_[i] = 0UL;
        }

      this->access_kstats (this->start_);
    }

    void
    Solaris_Network_Interface_Monitor::access_kstats (
      ACE_UINT64 &which_member)
    {
      this->kstats_ = kstat_open ();

      if (this->kstats_ == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("opening kstats file failed\n")));
          return;
        }

      this->kstat_id_ = this->kstats_->kc_chain_id;
      int status = 0;

      while (true)
        {
          /// We have to sum the network interfaces manually.
          for (this->kstat_ = this->kstats_->kc_chain;
               this->kstat_ != 0;
               this->kstat_ = this->kstat_->ks_next)
            {
              if (ACE_OS::strcmp (this->kstat_->ks_class, "net") != 0)
                {
                  continue;
                }

              unsigned long ks_instance = this->kstat_->ks_instance;

              if (ACE_OS::strcmp (this->kstat_->ks_module, "lo") == 0)
                {
                  /// Interfaces 'lo' have only packet counters.
                  if (this->lookup_str_ == ACE_TEXT ("obytes")
                      || this->lookup_str_ == ACE_TEXT ("rbytes"))
                    {
                      continue;
                    }

                  status = this->check_ks_module (ks_instance,
                                                  MAX_LO_INTERFACES,
                                                  "MAX_LO_INTERFACES",
                                                  this->value_array_lo_,
                                                  which_member);

                  if (status == -1)
                    {
                      /// Unrecoverable error, diagnostic already output.
                      (void) kstat_close (this->kstats_);
                      return;
                    }
                  else if (status == 1)
                    {
                      /// The kstat_id changed underneath us, start over.
                      break;
                    }
                }
              else if (ACE_OS::strcmp (this->kstat_->ks_module, "hme") == 0
                       || ACE_OS::strcmp (this->kstat_->ks_module, "bge") == 0)
                {
                  status = this->check_ks_module (ks_instance,
                                                  MAX_HME_INTERFACES,
                                                  "MAX_HME_INTERFACES",
                                                  this->value_array_hme_,
                                                  which_member);

                  if (status == -1)
                    {
                      /// Unrecoverable error, diagnostic already output.
                      (void) kstat_close (this->kstats_);
                      return;
                    }
                  else if (status == 1)
                    {
                      /// The kstat_id changed underneath us, start over.
                      break;
                    }
                }
            }

          if (this->kstat_)
            {
              this->kstat_id_ = kstat_chain_update (this->kstats_);

              if (! this->kstat_id_ > 0)
                {
                  ACE_ERROR ((LM_ERROR, "kstat is is not > 0.\n"));
                  break;
                }
            }
          else
            {
              break;
            }
        }

      status = kstat_close (this->kstats_);

      if (status != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("closing kstats file failed\n")));
        }
    }

    int
    Solaris_Network_Interface_Monitor::check_ks_module (
      const unsigned long ks_instance,
      const unsigned long which_max,
      const char *max_str,
      ACE_UINT64 *value_array,
      ACE_UINT64 &which_member)
    {
      if (! (ks_instance < which_max))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "%s exceeded.\n",
                             max_str),
                            -1);
        }

      /// Because the kstat chain can change dynamically,
      /// watch the chain ID and restart the walk if the ID
      /// differs from what we saw during the walk. The restart
      /// is done by breaking from the cycle with kstat_ not 0.

      kid_t kstat_id =
        kstat_read (this->kstats_, this->kstat_, 0);

      if (kstat_id != this->kstat_id_)
        {
          /// This return value restarts the walk as described above.
          return 1;
        }

      kstat_named_t *value =
        (kstat_named_t *) kstat_data_lookup (
          this->kstat_,
          ACE_TEXT_ALWAYS_CHAR (this->lookup_str_.rep ()));

      if (value == 0)
        {
          /// Just return and let the calling FOR loop advance.
          return 0;
        }

      if (value->data_type != KSTAT_DATA_UINT32)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Wrong data type.\n"),
                            -1);
        }

      /// Guard against overflow.
      value_array[ks_instance] +=
        value->value.ui32
        - static_cast<ACE_UINT32> (value_array[ks_instance]);

      which_member += value_array[ks_instance];

      return 0;
    }
  }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (ACE_HAS_KSTAT) */
