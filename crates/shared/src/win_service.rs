use std::ffi::{c_char, CStr, OsString};
use std::time::Duration;
use windows_service::service::{
    ServiceAccess, ServiceAction, ServiceActionType, ServiceErrorControl, ServiceFailureActions,
    ServiceFailureResetPeriod, ServiceInfo, ServiceStartType, ServiceType,
};
use windows_service::service_manager::{ServiceManager, ServiceManagerAccess};

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
        executable_path: std::env::current_exe().unwrap(),
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
