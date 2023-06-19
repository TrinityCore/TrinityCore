const BANNER: &'static str = r#"
              ▄▄
▀████▀ ▀███▀  ██   ██
  ██   ▄█▀         ██
  ██ ▄█▀    ▀███ ██████▀███▄███  ▄██▀██▄▀████████▄
  █████▄      ██   ██    ██▀ ▀▀ ██▀   ▀██ ██    ██
  ██  ███     ██   ██    ██     ██     ██ ██    ██
  ██   ▀██▄   ██   ██    ██     ██▄   ▄██ ██    ██
▄████▄   ███▄████▄ ▀████████▄    ▀█████▀▄████  ████▄
"#;

pub fn get_banner() -> &'static str {
    BANNER
}

/// Print out the banner to stdout
#[no_mangle]
pub extern "C" fn PrintBanner() {
    println!("{}", BANNER);
}
