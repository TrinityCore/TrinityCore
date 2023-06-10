use crate::RUNTIME;
use std::error::Error;
use std::fmt::{Debug, Display, Formatter};
use std::future::Future;
use std::sync::{Mutex, OnceLock};
use std::time::Duration;
use tokio::task::JoinHandle;
use tokio::time;

static TIMERS: OnceLock<Mutex<Vec<JoinHandle<()>>>> = OnceLock::new();

struct DummyError {}

impl Debug for DummyError {
    fn fmt(&self, _: &mut Formatter<'_>) -> std::fmt::Result {
        unreachable!()
    }
}

impl Display for DummyError {
    fn fmt(&self, _: &mut Formatter<'_>) -> std::fmt::Result {
        unreachable!()
    }
}

impl Error for DummyError {}

pub fn create_timer<R, E, F>(interval: Duration, callback: F)
where
    E: Error + Send,
    R: Future<Output = Result<(), E>> + Send,
    F: Fn() -> R + 'static + Send + Sync,
{
    let mut interval = time::interval(interval);
    let handle = tokio::spawn(async move {
        loop {
            interval.tick().await;
            let _ = (callback)().await;
        }
    });

    let mut timers = TIMERS.get_or_init(Mutex::default).lock().unwrap();
    timers.push(handle);
}

type TimerCallback = unsafe extern "C" fn();

#[no_mangle]
pub extern "C" fn CreateTimer(interval_seconds: u64, callback: TimerCallback) {
    let rt = RUNTIME.get().unwrap();
    let _guard = rt.enter();

    create_timer(Duration::from_secs(interval_seconds), move || async move {
        unsafe {
            callback();
        }
        Ok::<(), DummyError>(())
    })
}
