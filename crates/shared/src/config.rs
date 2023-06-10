use anyhow::{Error, Result};
use config::builder::DefaultState;
use config::{Config, ConfigBuilder, Environment, File};
use glob::glob;
use std::path::PathBuf;

pub fn load_config<S, D, E>(conf_dir: S, default_source: Option<D>) -> Result<Config>
where
    S: AsRef<str>,
    E: std::error::Error + Send + Sync + 'static,
    D: FnMut(&mut ConfigBuilder<DefaultState>) -> std::result::Result<(), E>,
{
    let mut builder = Config::builder();

    if let Some(mut default) = default_source {
        default(&mut builder).map_err(|e| Error::new(e))?;
    }

    let mut path_buf = PathBuf::new();
    path_buf.push(conf_dir.as_ref());
    path_buf.push("*");

    Ok(builder
        .add_source(
            glob(path_buf.to_string_lossy().as_ref())
                .unwrap()
                .map(|path| File::from(path.unwrap()))
                .collect::<Vec<_>>(),
        )
        .add_source(Environment::default())
        .build()?)
}

#[no_mangle]
pub extern "C" fn LoadConfig() {
    todo!()
}
