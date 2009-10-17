// -*- C++ -*-
//=============================================================================
/**
 *  @file    TTY_IO.h
 *
 *  $Id: TTY_IO.h 82271 2008-07-09 09:23:03Z olli $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//=============================================================================
#ifndef ACE_TTY_IO_H
#define ACE_TTY_IO_H
#include "ace/DEV_IO.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_TTY_IO
 *
 * @brief Class definitions for platform specific TTY features.
 *
 * This class represents an example interface for a specific
 * device (a serial line). It extends the capability of the
 * underlying DEV_IO class by adding a control method that takes
 * a special structure (Serial_Params) as argument to allow a
 * comfortable user interface (away from that annoying termios
 * structure, which is very specific to UNIX).
 */
class ACE_Export ACE_TTY_IO : public ACE_DEV_IO
{
public:
  enum Control_Mode
  {
    SETPARAMS,              ///< Set control parameters.
    GETPARAMS               ///< Get control parameters.
  };
  struct ACE_Export Serial_Params
  {
    Serial_Params (void);
    /** Specifies the baudrate at which the communnication port operates. */
    int baudrate;
    /** Specifies the minimum number of bytes in input buffer before XON char
        is sent. Negative value indicates that default value should
        be used (Win32). */
    int xonlim;
    /** Specifies the maximum number of bytes in input buffer before XOFF char
        is sent. Negative value indicates that default value should
        be used (Win32). */
    int xofflim;
    /** Specifies the minimum number of characters for non-canonical
        read (POSIX). */
    unsigned int readmincharacters;
    /** Specifies the time to wait before returning from read. Negative value
        means infinite timeout. */
    int readtimeoutmsec;
    /** Specifies the parity mode. POSIX supports "none", "even" and
        "odd" parity. Additionally Win32 supports "mark" and "space"
        parity modes. */
    const char *paritymode;
    /** Enable & set CTS mode. Note that RTS & CTS are enabled/disabled
        together on some systems (RTS/CTS is enabled if either
        <code>ctsenb</code> or <code>rtsenb</code> is set). */
    bool ctsenb;
    /** Enable & set RTS mode. Note that RTS & CTS are enabled/disabled
        together on some systems (RTS/CTS is enabled if either
        <code>ctsenb</code> or <code>rtsenb</code> is set).
        - 0 = Disable RTS.
        - 1 = Enable RTS.
        - 2 = Enable RTS flow-control handshaking (Win32).
        - 3 = Specifies that RTS line will be high if bytes are available
              for transmission. After transmission RTS will be low (Win32). */
    unsigned char rtsenb;
    /** Enable/disable software flow control on input. */
    bool xinenb;
    /** Enable/disable software flow control on output. */
    bool xoutenb;
    /** Specifies if device is a modem (POSIX). If not set modem status
        lines are ignored. */
    bool modem;
    /** Enable/disable receiver (POSIX). */
    bool rcvenb;
    /** Controls whether DSR is disabled or enabled (Win32). */
    bool dsrenb;
    /** Controls whether DTR is disabled or enabled. */
    bool dtrdisable;
    /** Data bits. Valid values 5, 6, 7 and 8 data bits.
        Additionally Win32 supports 4 data bits. */
    unsigned char databits;
    /** Stop bits. Valid values are 1 and 2. */
    unsigned char stopbits;
  };
  /** Interface for reading/writing serial device parameters. */
  int control (Control_Mode cmd, Serial_Params *arg) const;
#if defined (ACE_NEEDS_DEV_IO_CONVERSION)
  /** This is necessary to pass ACE_TTY_IO as parameter to DEV_Connector. */
  operator ACE_DEV_IO &();
#endif /* ACE_NEEDS_DEV_IO_CONVERSION */
};
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_TTY_IO_H */

