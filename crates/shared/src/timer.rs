use crate::error::DummyError;
use crate::RUNTIME;
use std::error::Error;
use std::future::Future;
use std::sync::{Mutex, OnceLock};
use std::time::Duration;
use tokio::task::JoinHandle;
use tokio::time;

static TIMERS: OnceLock<Mutex<Vec<JoinHandle<()>>>> = OnceLock::new();

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

#[allow(clippy::await_holding_lock)]
pub async fn stop_timers() {
    let mut timers = TIMERS.get_or_init(Mutex::default).lock().unwrap();
    for timer in timers.drain(..) {
        timer.abort();
        let _ = timer.await;
    }
}

#[cfg(feature = "ffi_timer")]
type TimerCallback = unsafe extern "C" fn();

#[no_mangle]
#[cfg(feature = "ffi_timer")]
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

#[cfg(test)]
mod tests {
    use crate::error::DummyError;
    use crate::timer::{create_timer, stop_timers};
    use std::sync::atomic::{AtomicU32, Ordering};
    use std::sync::Arc;
    use std::time::Duration;
    use tokio::time::sleep;

    #[tokio::test]
    pub async fn timer_should_work() {
        let counter = Arc::new(AtomicU32::new(0));
        let counter_ref = counter.clone();

        create_timer(Duration::from_secs(1), move || {
            counter_ref.fetch_add(1, Ordering::SeqCst);

            async { Ok::<(), DummyError>(()) }
        });

        sleep(Duration::from_millis(3500)).await;
        assert_eq!(counter.load(Ordering::Relaxed), 4);

        stop_timers().await;
    }
}
