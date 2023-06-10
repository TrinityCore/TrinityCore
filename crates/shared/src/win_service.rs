use std::ffi::{c_char, CStr, OsString};
use std::os::windows::ffi::OsStringExt;
use std::path::PathBuf;
use std::ptr;
use std::time::Duration;
use winapi::shared::minwindef::{DWORD, MAX_PATH};
use winapi::shared::winerror::ERROR_INSUFFICIENT_BUFFER;
use winapi::um::{errhandlingapi::GetLastError, libloaderapi::GetModuleFileNameW};
use windows_service::service::{
    ServiceAccess, ServiceAction, ServiceActionType, ServiceErrorControl, ServiceFailureActions,
    ServiceFailureResetPeriod, ServiceInfo, ServiceStartType, ServiceType,
};
use windows_service::service_manager::{ServiceManager, ServiceManagerAccess};

pub(crate) fn get_executable_path() -> Option<PathBuf> {
    fn get_executable_path(len: usize) -> Option<PathBuf> {
        let mut buf = Vec::with_capacity(len);
        unsafe {
            let ret = GetModuleFileNameW(ptr::null_mut(), buf.as_mut_ptr(), len as DWORD) as usize;
            if ret == 0 {
                None
            } else if ret < len {
                // Success, we need to trim trailing null bytes from the vec.
                buf.set_len(ret);
                let s = OsString::from_wide(&buf);
                Some(s.into())
            } else {
                // The buffer might not be big enough so we need to check errno.
                let errno = GetLastError();
                if errno == ERROR_INSUFFICIENT_BUFFER {
                    get_executable_path(len * 2)
                } else {
                    None
                }
            }
        }
    }

    get_executable_path(MAX_PATH)
}

fn install_service(
    service_name: &str,
    service_description: &str,
) -> Result<(), Box<dyn std::error::Error>> {
    let manager_access = ServiceManagerAccess::CONNECT;
    let service_manager = ServiceManager::local_computer(None::<&str>, manager_access)?;

    let service_info = ServiceInfo {
        name: OsString::from(service_name),
        display_name: OsString::from(service_name),
        service_type: ServiceType::OWN_PROCESS | ServiceType::INTERACTIVE_PROCESS,
        start_type: ServiceStartType::AutoStart,
        error_control: ServiceErrorControl::Ignore,
        executable_path: get_executable_path().unwrap(),
        launch_arguments: vec![OsString::from("--service"), OsString::from("run")],
        dependencies: vec![],
        account_name: None, // run as System
        account_password: None,
    };

    let service = service_manager.create_service(&service_info, ServiceAccess::all())?;
    let _ = service.set_description(OsString::from(service_description));

    let actions = vec![ServiceAction {
        action_type: ServiceActionType::Restart,
        delay: Duration::from_secs(10),
    }];

    service.update_failure_actions(ServiceFailureActions {
        reset_period: ServiceFailureResetPeriod::Never,
        command: None,
        reboot_msg: None,
        actions: Some(actions),
    })?;

    Ok(())
}

#[no_mangle]
pub extern "C" fn WinServiceInstall(
    service_name: *const c_char,
    service_description: *const c_char,
) -> bool {
    let service_name = unsafe { CStr::from_ptr(service_name) };
    let service_description = unsafe { CStr::from_ptr(service_description) };
    install_service(
        service_name.to_str().unwrap(),
        service_description.to_str().unwrap(),
    )
    .is_ok()
}
