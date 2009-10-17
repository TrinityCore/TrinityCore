/*
 *  $Id: Rtems_init.c 80826 2008-03-04 14:51:23Z wotte $
 */

#if defined (ACE_HAS_RTEMS)

#define RTEMS_BSP_NETWORK_DRIVER_NAME "ne1"
#define RTEMS_BSP_NETWORK_DRIVER_ATTACH rtems_ne_driver_attach
#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS 256

#define CONFIGURE_MAXIMUM_POSIX_THREADS 100
#define CONFIGURE_MAXIMUM_POSIX_MUTEXES 300
#define CONFIGURE_MAXIMUM_POSIX_CONDITION_VARIABLES 300
#define CONFIGURE_MAXIMUM_POSIX_KEYS 100
#define CONFIGURE_MAXIMUM_POSIX_TIMERS 100
#define CONFIGURE_MAXIMUM_POSIX_QUEUED_SIGNALS 10
#define CONFIGURE_MAXIMUM_POSIX_SEMAPHORES 300
#define CONFIGURE_POSIX_INIT_THREAD_TABLE
#define CONFIGURE_POSIX_INIT_THREAD_ENTRY_POINT Init
#define CONFIGURE_MEMORY_FOR_POSIX (10*1024)
#define CONFIGURE_POSIX_INIT_THREAD_STACK_SIZE (10*1024)

#define CONFIGURE_TEST_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_TEST_NEEDS_CLOCK_DRIVER

#define CONFIGURE_EXECUTIVE_RAM_SIZE (512*1024)

#define CONFIGURE_MICROSECONDS_PER_TICK 10000

#define CONFIGURE_MAXIMUM_SEMAPHORES    100
#define CONFIGURE_MAXIMUM_TASKS         100
#define CONFIGURE_INIT_TASK_PRIORITY 120
#define CONFIGURE_INIT_TASK_INITIAL_MODES (RTEMS_PREEMPT | \
                                           RTEMS_NO_TIMESLICE | \
                                           RTEMS_NO_ASR | \
                                           RTEMS_INTERRUPT_LEVEL(0))

#include <bsp.h>

char *rtems_progname;

#define CONFIGURE_INIT

rtems_task Init (rtems_task_argument argument);

#include <confdefs.h>

#include <stdio.h>

#if !defined (ACE_LACKS_NETWORKING)

#include <rtems/rtems_bsdnet.h>

/*
 * Network configuration
 *
 ************************************************************
 * EDIT THIS FILE TO REFLECT YOUR NETWORK CONFIGURATION     *
 * BEFORE RUNNING ANY RTEMS PROGRAMS WHICH USE THE NETWORK! *
 ************************************************************
 */

#ifndef _RTEMS_NETWORKCONFIG_H_
#define _RTEMS_NETWORKCONFIG_H_

#ifndef RTEMS_BSP_NETWORK_DRIVER_NAME
#warning "RTEMS_BSP_NETWORK_DRIVER_NAME is not defined"
#define RTEMS_BSP_NETWORK_DRIVER_NAME "no_network1"
#endif

#ifndef RTEMS_BSP_NETWORK_DRIVER_ATTACH
#warning "RTEMS_BSP_NETWORK_DRIVER_ATTACH is not defined"
#define RTEMS_BSP_NETWORK_DRIVER_ATTACH 0
#endif

/* #define RTEMS_USE_BOOTP */

#include <bsp.h>

/*
 * Define RTEMS_SET_ETHERNET_ADDRESS if you want to specify the
 * Ethernet address here.  If RTEMS_SET_ETHERNET_ADDRESS is not
 * defined the driver will choose an address.
 */
#define RTEMS_SET_ETHERNET_ADDRESS
#if (defined (RTEMS_SET_ETHERNET_ADDRESS))
static char ethernet_address[6] = { 0x00, 0x80, 0x7F, 0x22, 0x61, 0x77 };

#endif

#define RTEMS_USE_LOOPBACK

#ifdef RTEMS_USE_LOOPBACK
/*
 * Loopback interface
 */
int rtems_bsdnet_loopattach(struct rtems_bsdnet_ifconfig *, int);

#ifdef RTEMS_USE_LOOPBACK_ONLY
static struct rtems_bsdnet_ifconfig netdriver_config = {
#else
static struct rtems_bsdnet_ifconfig loopback_config = {
#endif
  "lo0",                    /* name */
  rtems_bsdnet_loopattach,  /* attach function */
  0,                        /* link to next interface */
  "127.0.0.1",              /* IP address */
  "255.0.0.0",              /* IP net mask */
};
#endif

/*
 * Default network interface
 */
#ifndef RTEMS_USE_LOOPBACK_ONLY
static struct rtems_bsdnet_ifconfig netdriver_config = {
  RTEMS_BSP_NETWORK_DRIVER_NAME,    /* name */
  RTEMS_BSP_NETWORK_DRIVER_ATTACH,  /* attach function */

#ifdef RTEMS_USE_LOOPBACK
  &loopback_config,  /* link to next interface */
#else
  0,                 /* No more interfaces */
#endif

#if (defined (RTEMS_USE_BOOTP))
  0,        /* BOOTP supplies IP address */
  0,        /* BOOTP supplies IP net mask */
#else
  "XXX.YYY.ZZZ.XYZ",   /* IP address */
  "255.255.255.0",     /* IP net mask */
#endif /* !RTEMS_USE_BOOTP */

#if (defined (RTEMS_SET_ETHERNET_ADDRESS))
  ethernet_address,    /* Ethernet hardware address */
#else
  0,                   /* Driver supplies hardware address */
#endif
  0                    /* Use default driver parameters */
};
#endif

/*
 * Network configuration
 */
struct rtems_bsdnet_config rtems_bsdnet_config = {
  &netdriver_config,

#if (defined (RTEMS_USE_BOOTP))
  rtems_bsdnet_do_bootp,
#else
  0,
#endif

  0,      /* Default network task priority */
  0,      /* Default mbuf capacity */
  0,      /* Default mbuf cluster capacity */

#if (!defined (RTEMS_USE_BOOTP))
  "rtems_host",       /* Host name */
  "nodomain.com",     /* Domain name */
  "XXX.YYY.ZZZ.1",    /* Gateway */
  "XXX.YYY.ZZZ.1",    /* Log host */
  {"XXX.YYY.ZZZ.1" }, /* Name server(s) */
  {"XXX.YYY.ZZZ.1" }, /* NTP server(s) */

  /*
  *  A real example -- DO NOT USE THIS YOURSELF!!!
  */

#if 0
  "dy4",             /* Host name */
  "NOT_oarcorp.com", /* Domain name */
  "192.168.1.2",     /* Gateway */
  "192.168.1.2",     /* Log host */
  {"192.168.1.2" },  /* Name server(s) */
  {"192.168.1.2" },  /* NTP server(s) */
#endif
#endif /* !RTEMS_USE_BOOTP */

};

/*
 * For TFTP test application
 */
#if (defined (RTEMS_USE_BOOTP))
#define RTEMS_TFTP_TEST_HOST_NAME "BOOTP_HOST"
#define RTEMS_TFTP_TEST_FILE_NAME "BOOTP_FILE"
#else
#define RTEMS_TFTP_TEST_HOST_NAME "XXX.YYY.ZZZ.XYZ"
#define RTEMS_TFTP_TEST_FILE_NAME "tftptest"
#endif

#endif /* _RTEMS_NETWORKCONFIG_H_ */

#endif /* ACE_LACKS_NETWORKING */

extern int main (int, char *[]);

/*
 * RTEMS Startup Task
 */
rtems_task
Init (rtems_task_argument not_used)
{
  int retval = 0;
#if !defined (ACE_LACKS_NETWORKING)
  retval = rtems_bsdnet_initialize_network ();
#endif /* ACE_LACKS_NETWORKING */
  if (retval == 0)
    {
      retval = main (0, 0);
    }
}

#elif !defined (__GNUC__) && !defined (__INTEL_COMPILER)
/* Make compilers stop complaining about an empty translation unit */
static int shut_up_compiler = 0;
#endif /* ACE_HAS_RTEMS */
