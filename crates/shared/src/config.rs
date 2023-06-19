use crate::error::DummyError;
use anyhow::{Error, Result};
use config::builder::DefaultState;
use config::{Case, ConfigBuilder, Environment, File, FileFormat, Source, Value, ValueKind};
use glob::glob;
use serde::Deserialize;
use std::ffi::{c_char, c_void, CStr, CString};
use std::mem::ManuallyDrop;
use std::path::PathBuf;
use std::ptr::null_mut;
use std::{fs, ptr};

#[repr(C)]
pub struct Config {
    #[cfg(feature = "ffi_config")]
    inner: *const c_void,
    #[cfg(not(feature = "ffi_config"))]
    inner: Config,
}

impl Config {
    /// Load configuration files.
    /// If a file is given, only this file will be loaded, otherwise all the files in
    /// the directory will be loaded (ordered by file name).
    ///
    /// # Arguments
    /// conf_dir - Configuration directory or file.
    pub fn load_config<S>(conf_dir: S) -> Result<Config>
    where
        S: AsRef<str>,
    {
        Self::load_config_with_default(conf_dir, |_| Ok::<(), DummyError>(()))
    }

    /// Load configuration files.
    /// See [`load_config`]
    ///
    /// # Arguments
    /// conf_dir - Configuration directory or file.
    /// default_source - A function or closure that accepts the config builder.
    ///                  In that function is possible to configure the default configuration values.
    pub fn load_config_with_default<S, D, E>(conf_dir: S, default_source: D) -> Result<Config>
    where
        S: AsRef<str>,
        E: std::error::Error + Send + Sync + 'static,
        D: Fn(&mut ConfigBuilder<DefaultState>) -> std::result::Result<(), E>,
    {
        let mut builder = config::Config::builder();
        default_source(&mut builder).map_err(|e| Error::new(e))?;

        let conf_dir_meta = fs::metadata(conf_dir.as_ref())?;
        let sources = if conf_dir_meta.is_dir() {
            let mut path_buf = PathBuf::new();
            path_buf.push(conf_dir.as_ref());
            path_buf.push("*");

            glob(path_buf.to_string_lossy().as_ref())
                .unwrap()
                .map(|path| File::from(path.unwrap()))
                .collect::<Vec<_>>()
        } else {
            let mut path_buf = PathBuf::new();
            path_buf.push(conf_dir.as_ref());
            let is_conf = path_buf.extension().is_some_and(|ext| ext == "conf");

            let mut file = File::from(path_buf);
            if is_conf {
                file = file.format(FileFormat::Ini);
            }

            vec![file]
        };

        let config = Box::new(
            builder
                .add_source(sources)
                .add_source(
                    Environment::with_prefix("app")
                        .convert_case(Case::Pascal)
                        .prefix_separator("_")
                        .separator("__"),
                )
                .build()?,
        );

        Ok(Self {
            #[cfg(feature = "ffi_config")]
            inner: Box::into_raw(config) as *const c_void,
            #[cfg(not(feature = "ffi_config"))]
            inner: config,
        })
    }

    /// # Safety
    /// Inner is always initialized.
    fn inner(&self) -> &config::Config {
        #[cfg(feature = "ffi_config")]
        {
            let b = unsafe { Box::<config::Config>::from_raw(self.inner as *mut _) };
            Box::leak(b)
        }

        #[cfg(not(feature = "ffi_config"))]
        {
            &self.inner
        }
    }

    /// Get all the configuration keys as string.
    pub fn get_keys(&self) -> Vec<String> {
        let configs = self.inner().collect().unwrap();
        let mut keys = vec![];

        fn process_map(
            map: &config::Map<String, Value>,
            keys: &mut Vec<String>,
            current_prefix: &str,
        ) {
            for (key, value) in map.iter() {
                match &value.kind {
                    ValueKind::Table(table) => {
                        process_map(table, keys, &format!("{}{}.", current_prefix, key))
                    }
                    _ => keys.push(format!("{}{}", current_prefix, key)),
                }
            }
        }

        process_map(&configs, &mut keys, "");
        keys
    }

    /// Gets a configuration value by key.
    /// If the key is not present, the default value is used if given or an error will be returned.
    pub fn get<'de, T>(&self, key: &str, default: Option<T>) -> Result<T>
    where
        T: Deserialize<'de>,
    {
        self.inner().get(key).or_else(|e| {
            if let Some(def) = default {
                Ok(def)
            } else {
                Err(Error::new(e))
            }
        })
    }

    // C/C++ interface
    // The following methods serves only as interface for C code

    /// Load the configuration from files.
    /// If load error is not NULL, an error has been raised and the returned value is invalid.
    ///
    /// # Safety
    /// C interface: unsafe function.
    /// If an error occurred, the return value is invalid and cannot be used.
    #[no_mangle]
    #[cfg(feature = "ffi_config")]
    pub unsafe extern "C" fn LoadConfig(
        conf_dir: *const c_char,
        load_error: *mut *mut c_char,
    ) -> Config {
        let conf_dir = CStr::from_ptr(conf_dir).to_str().unwrap();
        *load_error = null_mut();

        match Config::load_config(conf_dir) {
            Ok(conf) => conf,
            Err(err) => {
                let error_message = err.to_string();
                let conf_error = ManuallyDrop::new(CString::new(error_message).unwrap());
                *load_error = conf_error.as_ref().as_ptr() as *mut _;

                std::mem::transmute::<_, Config>(0_usize)
            }
        }
    }

    /// Gets all the configuration keys.
    /// The keys are returned in the keys array (must be passed as pointer). The return value
    /// represents the length of the array.
    ///
    /// # Safety
    /// Unsafe: keys array must be freed after use.
    #[no_mangle]
    #[cfg(feature = "ffi_config")]
    pub unsafe extern "C" fn Config_GetKeys(&self, keys: *mut *const *const c_char) -> usize {
        let strings = self
            .get_keys()
            .iter()
            .map(|str| CString::new(str.clone()).unwrap())
            .map(|cstr| {
                let ptr = cstr.as_ptr();
                std::mem::forget(cstr);

                ptr
            })
            .collect::<Vec<_>>();

        let length = strings.len();
        *keys = strings.as_ptr();
        std::mem::forget(strings);

        length
    }

    /// Gets a string configuration value or default.
    ///
    /// # Safety
    /// Unsafe: name is not checked for safety/sanity.
    /// Unsafe: returned value must be freed after use.
    #[no_mangle]
    #[cfg(feature = "ffi_config")]
    pub unsafe extern "C" fn Config_GetStringDefault(
        &self,
        name: *const c_char,
        default: *const c_char,
    ) -> *const c_char {
        let name = CStr::from_ptr(name).to_str().unwrap();
        let value = if let Ok(value) = self.inner().get_string(name) {
            ManuallyDrop::new(CString::new(value).unwrap())
        } else {
            let default = CStr::from_ptr(default).to_str().unwrap();
            ManuallyDrop::new(CString::new(default).unwrap())
        };

        value.as_ref().as_ptr()
    }

    /// Gets a boolean configuration value.
    ///
    /// # Safety
    /// Unsafe: name is not checked for safety/sanity.
    #[no_mangle]
    #[cfg(feature = "ffi_config")]
    pub unsafe extern "C" fn Config_GetBoolDefault(
        &self,
        name: *const c_char,
        default: bool,
    ) -> bool {
        let name = CStr::from_ptr(name).to_str().unwrap();
        if let Ok(value) = self.inner().get_bool(name) {
            value
        } else {
            default
        }
    }

    /// Gets an integer configuration value or default.
    ///
    /// # Safety
    /// Unsafe: name is not checked for safety/sanity.
    #[no_mangle]
    #[cfg(feature = "ffi_config")]
    pub unsafe extern "C" fn Config_GetIntDefault(&self, name: *const c_char, default: i64) -> i64 {
        let name = CStr::from_ptr(name).to_str().unwrap();
        if let Ok(value) = self.inner().get_int(name) {
            value
        } else {
            default
        }
    }

    /// Gets a float configuration value or default.
    ///
    /// # Safety
    /// Unsafe: name is not checked for safety/sanity.
    #[no_mangle]
    #[cfg(feature = "ffi_config")]
    pub unsafe extern "C" fn Config_GetFloatDefault(
        &self,
        name: *const c_char,
        default: f64,
    ) -> f64 {
        let name = CStr::from_ptr(name).to_str().unwrap();
        if let Ok(value) = self.inner().get_float(name) {
            value
        } else {
            default
        }
    }

    /// De-allocates the current configuration, freeing memory
    #[no_mangle]
    #[cfg(feature = "ffi_config")]
    pub extern "C" fn Config_Free(self) {
        drop(self);
    }
}

#[cfg(feature = "ffi_config")]
impl Drop for Config {
    fn drop(&mut self) {
        if self.inner != ptr::null() {
            unsafe {
                ptr::drop_in_place(self.inner as *mut c_void);
            }
        }
    }
}
