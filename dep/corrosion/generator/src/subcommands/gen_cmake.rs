use std::{
    fs::{create_dir_all, File},
    io::{stdout, Write},
    path::Path,
    rc::Rc,
};

use clap::{App, Arg, ArgMatches, SubCommand};

mod target;

// Command name
pub const GEN_CMAKE: &str = "gen-cmake";

// Options
const OUT_FILE: &str = "out-file";
const CONFIGURATION_ROOT: &str = "configuration-root";
const CRATES: &str = "crates";
const IMPORTED_CRATES: &str = "imported-crates";
const CRATE_TYPE: &str = "crate-type";
const PASSTHROUGH_ADD_CARGO_BUILD: &str = "passthrough-acb";

pub fn subcommand() -> App<'static, 'static> {
    SubCommand::with_name(GEN_CMAKE)
        .arg(
            Arg::with_name(CONFIGURATION_ROOT)
                .long("configuration-root")
                .value_name("DIRECTORY")
                .takes_value(true)
                .help(
                    "Specifies a root directory for configuration folders. E.g. Win32 \
                 in VS Generator.",
                ),
        )
        .arg(
            Arg::with_name(CRATES)
                .long("crates")
                .value_name("crates")
                .takes_value(true)
                .multiple(true)
                .require_delimiter(true)
                .help("Specifies which crates of the workspace to import"),
        )
        .arg(
            Arg::with_name(CRATE_TYPE)
                .long(CRATE_TYPE)
                .value_name("kind")
                .possible_values(&["staticlib", "cdylib", "bin"])
                .multiple(true)
                .value_delimiter(";")
                .help("Only import the specified crate types")
        )
        .arg(
            Arg::with_name(OUT_FILE)
                .short("o")
                .long("out-file")
                .value_name("FILE")
                .help("Output CMake file name. Defaults to stdout."),
        )
        .arg(
            Arg::with_name(IMPORTED_CRATES)
                .long(IMPORTED_CRATES)
                .value_name("variable_name")
                .takes_value(true)
                .help("Save a list of the imported target names into c CMake variable with the given name"),
        )
        .arg(
            Arg::with_name(PASSTHROUGH_ADD_CARGO_BUILD)
                .long(PASSTHROUGH_ADD_CARGO_BUILD)
                .takes_value(true)
                .multiple(true)
                .value_delimiter(std::char::from_u32(0x1f).unwrap().to_string().as_str())
                .help("Passthrough arguments to the _add_cargo_build invocation(s) in CMake")
        )
}

pub fn invoke(
    args: &crate::GeneratorSharedArgs,
    matches: &ArgMatches,
) -> Result<(), Box<dyn std::error::Error>> {
    let mut out_file: Box<dyn Write> = if let Some(path) = matches.value_of(OUT_FILE) {
        let path = Path::new(path);
        if let Some(parent) = path.parent() {
            create_dir_all(parent).expect("Failed to create directory!");
        }
        let file = File::create(path).expect("Unable to open out-file!");
        Box::new(file)
    } else {
        Box::new(stdout())
    };

    writeln!(
        out_file,
        "\
cmake_minimum_required(VERSION 3.15)
"
    )?;

    let crates = matches
        .values_of(CRATES)
        .map_or(Vec::new(), |c| c.collect());
    let crate_kinds: Option<Vec<&str>> = matches.values_of(CRATE_TYPE).map(|c| c.collect());
    let workspace_manifest_path = Rc::new(args.manifest_path.clone());
    let targets: Vec<_> = args
        .metadata
        .packages
        .iter()
        .filter(|p| {
            args.metadata.workspace_members.contains(&p.id)
                && (crates.is_empty() || crates.contains(&p.name.as_str()))
        })
        .cloned()
        .map(Rc::new)
        .flat_map(|package| {
            package
                .targets
                .iter()
                .filter_map(|t| {
                    target::CargoTarget::from_metadata(
                        package.clone(),
                        t.clone(),
                        workspace_manifest_path.clone(),
                        &crate_kinds,
                    )
                })
                .collect::<Vec<_>>()
        })
        .collect();

    let passthrough_args: Vec<String> = matches
        .values_of(PASSTHROUGH_ADD_CARGO_BUILD)
        .map(|values| {
            // Add quotes around each argument for CMake to preserve which arguments belong together.
            values
                .filter(|val| !val.is_empty())
                .map(|val| format!("\"{}\"", val))
                .collect()
        })
        .unwrap_or_default();
    let passthrough_str = passthrough_args.join(" ");

    for target in &targets {
        target
            .emit_cmake_target(&mut out_file, &passthrough_str)
            .unwrap();
    }
    if let Some(imported_crate_list_name) = matches.value_of(IMPORTED_CRATES) {
        let imported_targets: Vec<_> = targets.iter().map(|target| target.target_name()).collect();
        let imported_targets_list = imported_targets.join(";");
        writeln!(
            out_file,
            "set({} \"{}\")",
            imported_crate_list_name, imported_targets_list
        )?;
    }

    writeln!(out_file)?;

    std::process::exit(0);
}
