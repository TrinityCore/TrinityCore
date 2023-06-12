use cbindgen::Config;
use std::path::PathBuf;

fn main() {
    let path = std::env::current_dir().unwrap();
    let current_dir = path.to_str().unwrap();
    println!("{} {}", file!(), current_dir);

    let mut cbindgen_config = PathBuf::from(current_dir);
    cbindgen_config.push("cbindgen.toml");

    let mut header_file = PathBuf::from(current_dir);
    header_file.push("libenturion_shared.h");

    let config = Config::from_file(cbindgen_config).unwrap();
    cbindgen::generate_with_config(current_dir, config)
        .unwrap()
        .write_to_file(header_file);
}
