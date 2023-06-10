use std::future::Future;
use std::pin::Pin;
use std::task::{Context, Poll};
#[cfg(unix)]
use tokio::signal::unix::{signal, Signal as tokio_signal, SignalKind};
#[cfg(windows)]
use tokio::signal::windows::{
    ctrl_break, ctrl_c, ctrl_close, ctrl_logoff, ctrl_shutdown, CtrlBreak, CtrlC, CtrlClose,
    CtrlLogoff, CtrlShutdown,
};

/// Represents the specific kind of signal to listen for.
#[derive(Debug, Clone, Copy, Hash, PartialEq, Eq)]
pub enum Signal {
    Terminate = 0,
    Interruption = 1,
    Abort = 2,
}

pub struct Signals {
    #[cfg(unix)]
    sigterm: tokio_signal,
    #[cfg(unix)]
    sigint: tokio_signal,
    #[cfg(unix)]
    sigabrt: tokio_signal,
    #[cfg(windows)]
    ctrl_break: CtrlBreak,
    #[cfg(windows)]
    ctrl_c: CtrlC,
    #[cfg(windows)]
    ctrl_close: CtrlClose,
    #[cfg(windows)]
    ctrl_shutdown: CtrlShutdown,
    #[cfg(windows)]
    ctrl_logoff: CtrlLogoff,
}

impl Default for Signals {
    #[cfg(unix)]
    fn default() -> Self {
        let sigterm = signal(SignalKind::terminate()).unwrap();
        let sigint = signal(SignalKind::interrupt()).unwrap();
        let sigabrt = signal(SignalKind::from_raw(libc::SIGABRT)).unwrap();

        Self {
            sigterm,
            sigint,
            sigabrt,
        }
    }

    #[cfg(windows)]
    fn default() -> Self {
        let ctrl_break = ctrl_break().unwrap();
        let ctrl_c = ctrl_c().unwrap();
        let ctrl_shutdown = ctrl_shutdown().unwrap();
        let ctrl_logoff = ctrl_logoff().unwrap();
        let ctrl_close = ctrl_close().unwrap();

        Self {
            ctrl_break,
            ctrl_c,
            ctrl_shutdown,
            ctrl_logoff,
            ctrl_close,
        }
    }
}

impl AsMut<Signals> for Signals {
    fn as_mut(&mut self) -> &mut Signals {
        self
    }
}

impl Future for &mut Signals {
    type Output = Option<Signal>;

    #[cfg(unix)]
    fn poll(mut self: Pin<&mut Self>, cx: &mut Context<'_>) -> Poll<Self::Output> {
        let sigint = self.sigint.poll_recv(cx);
        let sigterm = self.sigterm.poll_recv(cx);
        let sigabrt = self.sigabrt.poll_recv(cx);

        if let Poll::Ready(opt) = sigint {
            Poll::Ready(opt.map(|_| Signal::Interruption))
        } else if let Poll::Ready(opt) = sigterm {
            Poll::Ready(opt.map(|_| Signal::Terminate))
        } else if let Poll::Ready(opt) = sigabrt {
            Poll::Ready(opt.map(|_| Signal::Abort))
        } else {
            Poll::Pending
        }
    }

    #[cfg(windows)]
    fn poll(mut self: Pin<&mut Self>, cx: &mut Context<'_>) -> Poll<Self::Output> {
        let ctrl_break = self.ctrl_break.poll_recv(cx);
        let ctrl_c = self.ctrl_c.poll_recv(cx);
        let ctrl_shutdown = self.ctrl_shutdown.poll_recv(cx);
        let ctrl_logoff = self.ctrl_logoff.poll_recv(cx);
        let ctrl_close = self.ctrl_close.poll_recv(cx);

        if let Poll::Ready(opt) = ctrl_break {
            Poll::Ready(opt.map(|_| Signal::Interruption))
        } else if let Poll::Ready(opt) = ctrl_c {
            Poll::Ready(opt.map(|_| Signal::Interruption))
        } else if let Poll::Ready(opt) = ctrl_shutdown {
            Poll::Ready(opt.map(|_| Signal::Terminate))
        } else if let Poll::Ready(opt) = ctrl_logoff {
            Poll::Ready(opt.map(|_| Signal::Terminate))
        } else if let Poll::Ready(opt) = ctrl_close {
            Poll::Ready(opt.map(|_| Signal::Terminate))
        } else {
            Poll::Pending
        }
    }
}
