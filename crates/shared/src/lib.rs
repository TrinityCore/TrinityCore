use std::sync::OnceLock;
use tokio::runtime::Runtime;

pub mod config;
pub mod dbc;
pub mod signals;
pub mod timer;
#[cfg(windows)]
pub mod win_service;

pub static RUNTIME: OnceLock<Runtime> = OnceLock::new();
