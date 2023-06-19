use std::ffi::{c_char, CString};
use std::sync::OnceLock;
use tokio::runtime::Runtime;

pub mod banner;
pub mod config;
pub mod dbc;
pub mod error;
pub mod signals;
pub mod timer;
#[cfg(windows)]
pub mod win_service;

pub static RUNTIME: OnceLock<Runtime> = OnceLock::new();
static CURRENT_EXE: OnceLock<CString> = OnceLock::new();

/// Gets the current executable filepath.
#[no_mangle]
pub extern "C" fn GetCurrentExe() -> *const c_char {
    let current_exe = CURRENT_EXE.get_or_init(|| {
        let current_exe = std::env::current_exe().unwrap_or_default();
        CString::new(current_exe.as_os_str().to_str().unwrap()).unwrap()
    });

    current_exe.as_ptr()
}
