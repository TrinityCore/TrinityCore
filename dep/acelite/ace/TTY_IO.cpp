// $Id: TTY_IO.cpp 86739 2009-09-21 07:33:22Z olli $

#include "ace/TTY_IO.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_strings.h"

#if defined (ACE_HAS_TERMIOS)
# include "ace/os_include/os_termios.h"
#elif  defined (ACE_HAS_TERMIO)
# include <termio.h>
#endif

ACE_RCSID (ace,
           TTY_IO,
           "$Id: TTY_IO.cpp 86739 2009-09-21 07:33:22Z olli $")

namespace
{
  const char ACE_TTY_IO_NONE[]  = "none";
#if defined (ACE_HAS_TERMIOS) || defined (ACE_HAS_TERMIO) || defined (ACE_WIN32)
  const char ACE_TTY_IO_ODD[]   = "odd";
  const char ACE_TTY_IO_EVEN[]  = "even";
#endif
#if defined (ACE_WIN32)
  const char ACE_TTY_IO_MARK[]  = "mark";
  const char ACE_TTY_IO_SPACE[] = "space";
#endif /* ACE_WIN32 */
}

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_TTY_IO::Serial_Params::Serial_Params (void)
{
  baudrate = 9600;
  xonlim = 0;
  xofflim = 0;
  readmincharacters = 0;
  readtimeoutmsec = 10000;
  paritymode = ACE_TTY_IO_NONE;
  ctsenb = false;
  rtsenb = 0;
  xinenb = false;
  xoutenb = false;
  modem = false;
  rcvenb = true;
  dsrenb = false;
  dtrdisable = false;
  databits = 8;
  stopbits = 1;
}

// Interface for reading/writing serial device parameters

int ACE_TTY_IO::control (Control_Mode cmd, Serial_Params *arg) const
{
#if defined (ACE_HAS_TERMIOS) || defined (ACE_HAS_TERMIO)

#if defined (ACE_HAS_TERMIOS)
  struct termios devpar;
  speed_t newbaudrate = 0;
  if (tcgetattr (get_handle () , &devpar) == -1)
#elif defined (TCGETS)
  struct termios devpar;
  unsigned int newbaudrate = 0;
  if (this->ACE_IO_SAP::control (TCGETS, static_cast<void*>(&devpar)) == -1)
#elif defined (TCGETA)
  struct termio devpar;
  unsigned int newbaudrate = 0;
  if (this->ACE_IO_SAP::control (TCGETA, static_cast<void*>(&devpar)) == -1)
#else
  errno = ENOSYS;
#endif /* ACE_HAS_TERMIOS */
  return -1;

  switch (cmd)
    {
    case SETPARAMS:
      switch (arg->baudrate)
        {
#if defined (B0)
        case 0:       newbaudrate = B0;       break;
#endif /* B0 */
#if defined (B50)
        case 50:      newbaudrate = B50;      break;
#endif /* B50 */
#if defined (B75)
        case 75:      newbaudrate = B75;      break;
#endif /* B75 */
#if defined (B110)
        case 110:     newbaudrate = B110;     break;
#endif /* B110 */
#if defined (B134)
        case 134:     newbaudrate = B134;     break;
#endif /* B134 */
#if defined (B150)
        case 150:     newbaudrate = B150;     break;
#endif /* B150 */
#if defined (B200)
        case 200:     newbaudrate = B200;     break;
#endif /* B200 */
#if defined (B300)
        case 300:     newbaudrate = B300;     break;
#endif /* B300 */
#if defined (B600)
        case 600:     newbaudrate = B600;     break;
#endif /* B600 */
#if defined (B1200)
        case 1200:    newbaudrate = B1200;    break;
#endif /* B1200 */
#if defined (B1800)
        case 1800:    newbaudrate = B1800;    break;
#endif /* B1800 */
#if defined (B2400)
        case 2400:    newbaudrate = B2400;    break;
#endif /* B2400 */
#if defined (B4800)
        case 4800:    newbaudrate = B4800;    break;
#endif /* B4800 */
#if defined (B9600)
        case 9600:    newbaudrate = B9600;    break;
#endif /* B9600 */
#if defined (B19200)
        case 19200:   newbaudrate = B19200;   break;
#endif /* B19200 */
#if defined (B38400)
        case 38400:   newbaudrate = B38400;   break;
#endif /* B38400 */
#if defined (B56000)
        case 56000:   newbaudrate = B56000;   break;
#endif /* B56000 */
#if defined (B57600)
        case 57600:   newbaudrate = B57600;   break;
#endif /* B57600 */
#if defined (B76800)
        case 76800:   newbaudrate = B76800;   break;
#endif /* B76800 */
#if defined (B115200)
        case 115200:  newbaudrate = B115200;  break;
#endif /* B115200 */
#if defined (B128000)
        case 128000:  newbaudrate = B128000;  break;
#endif /* B128000 */
#if defined (B153600)
        case 153600:  newbaudrate = B153600;  break;
#endif /* B153600 */
#if defined (B230400)
        case 230400:  newbaudrate = B230400;  break;
#endif /* B230400 */
#if defined (B307200)
        case 307200:  newbaudrate = B307200;  break;
#endif /* B307200 */
#if defined (B256000)
        case 256000:  newbaudrate = B256000;  break;
#endif /* B256000 */
#if defined (B460800)
        case 460800:  newbaudrate = B460800;  break;
#endif /* B460800 */
#if defined (B500000)
        case 500000:  newbaudrate = B500000;  break;
#endif /* B500000 */
#if defined (B576000)
        case 576000:  newbaudrate = B576000;  break;
#endif /* B576000 */
#if defined (B921600)
        case 921600:  newbaudrate = B921600;  break;
#endif /* B921600 */
#if defined (B1000000)
        case 1000000: newbaudrate = B1000000; break;
#endif /* B1000000 */
#if defined (B1152000)
        case 1152000: newbaudrate = B1152000; break;
#endif /* B1152000 */
#if defined (B1500000)
        case 1500000: newbaudrate = B1500000; break;
#endif /* B1500000 */
#if defined (B2000000)
        case 2000000: newbaudrate = B2000000; break;
#endif /* B2000000 */
#if defined (B2500000)
        case 2500000: newbaudrate = B2500000; break;
#endif /* B2500000 */
#if defined (B3000000)
        case 3000000: newbaudrate = B3000000; break;
#endif /* B3000000 */
#if defined (B3500000)
        case 3500000: newbaudrate = B3500000; break;
#endif /* B3500000 */
#if defined (B4000000)
        case 4000000: newbaudrate = B4000000; break;
#endif /* B4000000 */
        default:
          return -1;
        }

#if defined (ACE_HAS_TERMIOS)
      // Can you really have different input and output baud rates?!
      if (cfsetospeed (&devpar, newbaudrate) == -1)
        return -1;
      if (cfsetispeed (&devpar, newbaudrate) == -1)
        return -1;
#else
      devpar.c_cflag &= ~CBAUD;
# if defined (CBAUDEX)
      devpar.c_cflag &= ~CBAUDEX;
# endif /* CBAUDEX */
      devpar.c_cflag |= newbaudrate;
#endif /* ACE_HAS_TERMIOS */

      devpar.c_cflag &= ~CSIZE;
      switch (arg->databits)
        {
        case 5:
          devpar.c_cflag |= CS5;
          break;
        case 6:
          devpar.c_cflag |= CS6;
          break;
        case 7:
          devpar.c_cflag |= CS7;
          break;
        case 8:
          devpar.c_cflag |= CS8;
          break;
        default:
          return -1;
        }

      switch (arg->stopbits)
        {
        case 1:
          devpar.c_cflag &= ~CSTOPB;
          break;
        case 2:
          devpar.c_cflag |=  CSTOPB;
          break;
        default:
          return -1;
        }

      if (arg->paritymode)
        {
          if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_ODD) == 0)
            {
              devpar.c_cflag |=  PARENB;
              devpar.c_cflag |=  PARODD;
            }
          else if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_EVEN) == 0)
            {
              devpar.c_cflag |=  PARENB;
              devpar.c_cflag &= ~PARODD;
            }
          else if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_NONE) == 0)
            devpar.c_cflag &= ~PARENB;
          else
            return -1;
        }
      else
        {
          devpar.c_cflag &= ~PARENB;
        }

#if defined (CNEW_RTSCTS)
      if ((arg->ctsenb) || (arg->rtsenb)) // Enable RTS/CTS protocol
        devpar.c_cflag |= CNEW_RTSCTS;
      else
        devpar.c_cflag &= ~CNEW_RTSCTS;
#elif defined (CRTSCTS)
      if ((arg->ctsenb) || (arg->rtsenb)) // Enable RTS/CTS protocol
        devpar.c_cflag |= CRTSCTS;
      else
        devpar.c_cflag &= ~CRTSCTS;
#endif /* NEW_RTSCTS || CRTSCTS */

#if defined (CREAD)
      // Enable/disable receiver
      if (arg->rcvenb)
        devpar.c_cflag |= CREAD;
      else
        devpar.c_cflag &= ~CREAD;
#endif /* CREAD */

#if defined (HUPCL)
      // Cause DTR to drop after port close.
      devpar.c_cflag |= HUPCL;
#endif /* HUPCL */

#if defined (CLOCAL)
      // If device is not a modem set to local device.
      if (arg->modem)
        devpar.c_cflag &= ~CLOCAL;
      else
        devpar.c_cflag |= CLOCAL;
#endif /* CLOCAL */

      devpar.c_iflag = IGNPAR | INPCK;
      if (arg->databits < 8)
        devpar.c_iflag |= ISTRIP;

#if defined (IGNBRK)
      // If device is not a modem set to ignore break points
      if(arg->modem)
        devpar.c_iflag &= ~IGNBRK;
      else
        devpar.c_iflag |= IGNBRK;
#endif /* IGNBRK */

#if defined (IXOFF)
      // Enable/disable software flow control on input
      if (arg->xinenb)
        devpar.c_iflag |= IXOFF;
      else
        devpar.c_iflag &= ~IXOFF;
#endif /* IXOFF */

#if defined (IXON)
      // Enable/disable software flow control on output
      if (arg->xoutenb)
        devpar.c_iflag |= IXON;
      else
        devpar.c_iflag &= ~IXON;
#endif /* IXON */

#if defined (ICANON)
      // Enable noncanonical input processing mode
      devpar.c_lflag &= ~ICANON;
#endif /* ICANON */

#if defined (ECHO)
      // Disable echoing of input characters
      devpar.c_lflag &= ~ECHO;
#endif /* ECHO */

#if defined (ECHOE)
      // Disable echoing erase chareacter as BS-SP-BS
      devpar.c_lflag &= ~ECHOE;
#endif /* ECHOE */

#if defined (ISIG)
      // Disable SIGINTR, SIGSUSP, SIGDSUSP and SIGQUIT signals
      devpar.c_lflag &= ~ISIG;
#endif /* ISIG */

#if defined (OPOST)
      // Disable post-processing of output data
      devpar.c_oflag &= ~OPOST;
#endif /* OPOST */

      if (arg->readtimeoutmsec < 0)
        {
          // Settings for infinite timeout.
          devpar.c_cc[VTIME] = 0;
          // In case of infinite timeout [VMIN] must be at least 1.
          if (arg->readmincharacters > UCHAR_MAX)
            devpar.c_cc[VMIN] = UCHAR_MAX;
          else if (arg->readmincharacters < 1)
            devpar.c_cc[VMIN] = 1;
          else
            devpar.c_cc[VMIN] = static_cast<unsigned char>(arg->readmincharacters);
        }
      else
        {
          devpar.c_cc[VTIME] = static_cast<unsigned char>(arg->readtimeoutmsec / 100);

          if (arg->readmincharacters > UCHAR_MAX)
            devpar.c_cc[VMIN] = UCHAR_MAX;
          else if (arg->readmincharacters < 1)
            devpar.c_cc[VMIN] = 0;
          else
            devpar.c_cc[VMIN] = static_cast<unsigned char>(arg->readmincharacters);
        }

#if defined (TIOCMGET)
      int status;
      this->ACE_IO_SAP::control (TIOCMGET, &status);

      if (arg->dtrdisable)
        status &= ~TIOCM_DTR;
      else
        status |=  TIOCM_DTR;

      this->ACE_IO_SAP::control (TIOCMSET, &status);
#endif /* definded (TIOCMGET) */

#if defined (ACE_HAS_TERMIOS)
      return tcsetattr (get_handle (), TCSANOW, &devpar);
#elif defined (TCSETS)
      return this->ACE_IO_SAP::control (TCSETS, static_cast<void*>(&devpar));
#elif defined (TCSETA)
      return this->ACE_IO_SAP::control (TCSETA, static_cast<void*>(&devpar));
#else
      errno = ENOSYS;
      return -1;
#endif /* ACE_HAS_TERMIOS */

    case GETPARAMS:
      return -1; // Not yet implemented.
    default:
      return -1; // Wrong cmd.
    }
#elif defined (ACE_WIN32)
  DCB dcb;
  dcb.DCBlength = sizeof dcb;
  if (!::GetCommState (this->get_handle (), &dcb))
  {
    ACE_OS::set_errno_to_last_error ();
    return -1;
  }

  COMMTIMEOUTS timeouts;
  if (!::GetCommTimeouts (this->get_handle(), &timeouts))
  {
    ACE_OS::set_errno_to_last_error ();
    return -1;
  }

  switch (cmd)
    {
    case SETPARAMS:
      dcb.BaudRate = arg->baudrate;

      switch (arg->databits)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
          dcb.ByteSize = arg->databits;
          break;
        default:
          return -1;
        }

      switch (arg->stopbits)
        {
        case 1:
          dcb.StopBits = ONESTOPBIT;
          break;
        case 2:
          dcb.StopBits = TWOSTOPBITS;
          break;
        default:
          return -1;
        }

      if (arg->paritymode)
        {
          dcb.fParity = TRUE;
          if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_ODD) == 0)
            dcb.Parity = ODDPARITY;
          else if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_EVEN) == 0)
            dcb.Parity = EVENPARITY;
          else if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_NONE) == 0)
            dcb.Parity = NOPARITY;
          else if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_MARK) == 0)
            dcb.Parity = MARKPARITY;
          else if (ACE_OS::strcasecmp (arg->paritymode, ACE_TTY_IO_SPACE) == 0)
            dcb.Parity = SPACEPARITY;
          else
            return -1;
        }
      else
        {
          dcb.fParity = FALSE;
          dcb.Parity = NOPARITY;
        }

      // Enable/disable RTS protocol.
      switch (arg->rtsenb)
        {
        case 1:
          dcb.fRtsControl = RTS_CONTROL_ENABLE;
          break;
        case 2:
          dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
          break;
        case 3:
          dcb.fRtsControl = RTS_CONTROL_TOGGLE;
          break;
        default:
          dcb.fRtsControl = RTS_CONTROL_DISABLE;
        }

      // Enable/disable CTS protocol.
      if (arg->ctsenb)
        dcb.fOutxCtsFlow = TRUE;
      else
        dcb.fOutxCtsFlow = FALSE;

      // Enable/disable DSR protocol.
      if (arg->dsrenb)
        dcb.fOutxDsrFlow = TRUE;
      else
        dcb.fOutxDsrFlow = FALSE;

      // Disable/enable DTR protocol
      if (arg->dtrdisable)
        dcb.fDtrControl = DTR_CONTROL_DISABLE;
      else
        dcb.fDtrControl = DTR_CONTROL_ENABLE;

      // Enable/disable software flow control on input
      if (arg->xinenb)
        dcb.fInX = TRUE;
      else
        dcb.fInX = FALSE;

      // Enable/disable software flow control on output
      if (arg->xoutenb)
        dcb.fOutX = TRUE;
      else
        dcb.fOutX = FALSE;

      // Always set limits unless set to negative to use default.
      if (arg->xonlim >= 0)
        dcb.XonLim  = static_cast<WORD>(arg->xonlim);
      if (arg->xofflim >= 0)
        dcb.XoffLim = static_cast<WORD>(arg->xofflim);

      dcb.fAbortOnError = FALSE;
      dcb.fErrorChar = FALSE;
      dcb.fNull = FALSE;
      dcb.fBinary = TRUE;

      if (!::SetCommState (this->get_handle (), &dcb))
        {
          ACE_OS::set_errno_to_last_error ();
          return -1;
        }

      if (arg->readtimeoutmsec < 0)
        {
          // Settings for infinite timeout.
          timeouts.ReadIntervalTimeout        = 0;
          timeouts.ReadTotalTimeoutMultiplier = 0;
          timeouts.ReadTotalTimeoutConstant   = 0;
        }
      else if (arg->readtimeoutmsec == 0)
        {
          // Return immediately if no data in the input buffer.
          timeouts.ReadIntervalTimeout        = MAXDWORD;
          timeouts.ReadTotalTimeoutMultiplier = 0;
          timeouts.ReadTotalTimeoutConstant   = 0;
        }
      else
        {
          // Wait for specified timeout for char to arrive before returning.
          timeouts.ReadIntervalTimeout        = MAXDWORD;
          timeouts.ReadTotalTimeoutMultiplier = MAXDWORD;
          timeouts.ReadTotalTimeoutConstant   = arg->readtimeoutmsec;
        }

       if (!::SetCommTimeouts (this->get_handle (), &timeouts))
         {
           ACE_OS::set_errno_to_last_error ();
           return -1;
         }

       return 0;

    case GETPARAMS:
      arg->baudrate = dcb.BaudRate;

      switch (dcb.ByteSize)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
          arg->databits = dcb.ByteSize;
          break;
        default:
          return -1;
        }

      switch (dcb.StopBits)
        {
        case ONESTOPBIT:
          arg->stopbits = 1;
          break;
        case TWOSTOPBITS:
          arg->stopbits = 2;
          break;
        default:
          return -1;
        }

      if (!dcb.fParity)
        {
          arg->paritymode = ACE_TTY_IO_NONE;
        }
      else
        {
          switch (dcb.Parity)
            {
            case ODDPARITY:
              arg->paritymode = ACE_TTY_IO_ODD;
              break;
            case EVENPARITY:
              arg->paritymode = ACE_TTY_IO_EVEN;
              break;
            case NOPARITY:
              arg->paritymode = ACE_TTY_IO_NONE;
              break;
            case MARKPARITY:
              arg->paritymode = ACE_TTY_IO_MARK;
              break;
            case SPACEPARITY:
              arg->paritymode = ACE_TTY_IO_SPACE;
              break;
            default:
              return -1;
            }
        }

      // Enable/disable RTS protocol.
      switch (dcb.fRtsControl)
        {
        case RTS_CONTROL_ENABLE:
          arg->rtsenb = 1;
          break;
        case RTS_CONTROL_HANDSHAKE:
          arg->rtsenb = 2;
          break;
        case RTS_CONTROL_TOGGLE:
          arg->rtsenb = 3;
          break;
        case RTS_CONTROL_DISABLE:
          arg->rtsenb = 0;
          break;
        default:
          return -1;
        }

      // Enable/disable CTS protocol.
      if (dcb.fOutxCtsFlow)
        arg->ctsenb = true;
      else
        arg->ctsenb = false;

      // Enable/disable DSR protocol.
      if (dcb.fOutxDsrFlow)
        arg->dsrenb = true;
      else
        arg->dsrenb = false;

      // Disable/enable DTR protocol
      // Attention: DTR_CONTROL_HANDSHAKE is not supported.
      switch (dcb.fDtrControl)
        {
        case DTR_CONTROL_DISABLE:
          arg->dtrdisable = true;
          break;
        case DTR_CONTROL_ENABLE:
          arg->dtrdisable = false;
          break;
        default:
          return -1;
        }

      // Enable/disable software flow control on input
      if (dcb.fInX)
        arg->xinenb = true;
      else
        arg->xinenb = false;

      // Enable/disable software flow control on output
      if (dcb.fOutX)
        arg->xoutenb = true;
      else
        arg->xoutenb = false;

      arg->xonlim = static_cast<int>(dcb.XonLim);
      arg->xofflim = static_cast<int>(dcb.XoffLim);

      if (timeouts.ReadIntervalTimeout == 0 &&
        timeouts.ReadTotalTimeoutMultiplier == 0 &&
        timeouts.ReadTotalTimeoutConstant == 0)
          arg->readtimeoutmsec = -1;
      else
        arg->readtimeoutmsec = timeouts.ReadTotalTimeoutConstant;

      return 0;

    default:
      return -1; // Wrong cmd.

    } // arg switch
#else
  ACE_UNUSED_ARG (cmd);
  ACE_UNUSED_ARG (arg);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_TERMIOS || ACE_HAS_TERMIO */
}

#if defined (ACE_NEEDS_DEV_IO_CONVERSION)
ACE_TTY_IO::operator ACE_DEV_IO &()
{
  return static_cast<ACE_DEV_IO &>(*this);
}
#endif /* ACE_NEEDS_DEV_IO_CONVERSION */

ACE_END_VERSIONED_NAMESPACE_DECL
