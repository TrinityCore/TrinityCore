use std::error::Error;
use std::path::PathBuf;
use std::rc::Rc;

#[derive(Clone)]
pub enum CargoTargetType {
    Executable,
    Library {
        has_staticlib: bool,
        has_cdylib: bool,
    },
}

#[derive(Clone)]
pub struct CargoTarget {
    cargo_package: Rc<cargo_metadata::Package>,
    cargo_target: cargo_metadata::Target,
    target_type: CargoTargetType,
    workspace_manifest_path: Rc<PathBuf>,
}

impl CargoTargetType {
    fn to_string(&self) -> String {
        let mut s = String::new();
        match self {
            Self::Executable => {
                s.push_str("bin");
            }
            Self::Library {
                has_staticlib,
                has_cdylib,
            } => {
                if *has_staticlib {
                    s.push_str("staticlib")
                }
                if *has_cdylib {
                    s.push_str(" cdylib")
                }
            }
        }
        s
    }
}

impl CargoTarget {
    pub fn from_metadata(
        cargo_package: Rc<cargo_metadata::Package>,
        cargo_target: cargo_metadata::Target,
        workspace_manifest_path: Rc<PathBuf>,
        // If Some, only import crates if the kind variant is given in crate_kinds.
        crate_kinds: &Option<Vec<&str>>,
    ) -> Option<Self> {
        let filtered_kinds: Vec<String> = cargo_target
            .kind
            .clone()
            .into_iter()
            .filter(|kind| match crate_kinds {
                None => true,
                Some(allowed_kinds_subset) => allowed_kinds_subset.contains(&&**kind),
            })
            .collect();

        let target_type = if filtered_kinds
            .iter()
            .any(|k| k.as_str() == "staticlib" || k.as_str() == "cdylib")
        {
            CargoTargetType::Library {
                has_staticlib: filtered_kinds.iter().any(|k| k == "staticlib"),
                has_cdylib: filtered_kinds.iter().any(|k| k == "cdylib"),
            }
        } else if filtered_kinds.iter().any(|k| k == "bin") {
            CargoTargetType::Executable
        } else {
            return None;
        };

        Some(Self {
            cargo_package,
            cargo_target,
            target_type,
            workspace_manifest_path,
        })
    }

    pub(crate) fn target_name(&self) -> &str {
        &self.cargo_target.name
    }

    pub fn emit_cmake_target(
        &self,
        out_file: &mut dyn std::io::Write,
        passthrough_add_cargo_build: &str,
    ) -> Result<(), Box<dyn Error>> {
        writeln!(
            out_file,
            "set(byproducts \"\")
                            set(cargo_build_out_dir \"\")
                            set(archive_byproducts \"\")
                            set(shared_lib_byproduct \"\")
                            set(pdb_byproduct \"\")
                            set(bin_byproduct \"\")
        "
        )?;
        let ws_manifest = self
            .workspace_manifest_path
            .to_str()
            .expect("Non-utf8 path encountered")
            .replace("\\", "/");

        match self.target_type {
            CargoTargetType::Library {
                has_staticlib,
                has_cdylib,
            } => {
                assert!(has_staticlib || has_cdylib);
                let ws_manifest = self
                    .workspace_manifest_path
                    .to_str()
                    .expect("Non-utf8 path encountered")
                    .replace("\\", "/");
                let mut lib_kinds = if has_staticlib { "staticlib" } else { "" }.to_string();
                if has_cdylib {
                    if has_staticlib {
                        lib_kinds.push(' ');
                    }
                    lib_kinds.push_str("cdylib")
                }

                writeln!(
                    out_file,
                    "
                    _corrosion_add_library_target(
                            WORKSPACE_MANIFEST_PATH \"{workspace_manifest_path}\"
                            TARGET_NAME \"{target_name}\"
                            LIB_KINDS {lib_kinds}
                            OUT_ARCHIVE_OUTPUT_BYPRODUCTS archive_byproducts
                            OUT_SHARED_LIB_BYPRODUCTS shared_lib_byproduct
                            OUT_PDB_BYPRODUCT pdb_byproduct
                    )
                    list(APPEND byproducts
                            \"${{archive_byproducts}}\"
                            \"${{shared_lib_byproduct}}\"
                            \"${{pdb_byproduct}}\"
                    )
                    ",
                    workspace_manifest_path = ws_manifest,
                    target_name = self.cargo_target.name,
                    lib_kinds = lib_kinds,
                )?;
            }
            CargoTargetType::Executable => {
                writeln!(
                    out_file,
                    "
                    _corrosion_add_bin_target(\"{workspace_manifest_path}\" \"{target_name}\"
                        bin_byproduct pdb_byproduct
                    )
                    set(byproducts \"\")
                    list(APPEND byproducts \"${{bin_byproduct}}\" \"${{pdb_byproduct}}\")
                    ",
                    workspace_manifest_path = ws_manifest,
                    target_name = self.cargo_target.name,
                )?;
            }
        };
        let target_kinds = self.target_type.to_string();
        writeln!(out_file,
            "
            set(cargo_build_out_dir \"\")
            _add_cargo_build(
                cargo_build_out_dir
                PACKAGE \"{package_name}\"
                TARGET \"{target_name}\"
                MANIFEST_PATH \"{package_manifest_path}\"
                WORKSPACE_MANIFEST_PATH \"{workspace_manifest_path}\"
                TARGET_KINDS {target_kinds}
                BYPRODUCTS \"${{byproducts}}\"
                {passthrough_add_cargo_build}
            )

            set_target_properties({target_name} PROPERTIES
                INTERFACE_COR_PACKAGE_MANIFEST_PATH \"{package_manifest_path}\"
            )

            if(archive_byproducts)
                _corrosion_copy_byproducts(
                    {target_name} ARCHIVE_OUTPUT_DIRECTORY \"${{cargo_build_out_dir}}\" \"${{archive_byproducts}}\"
                )
            endif()
            if(shared_lib_byproduct)
                _corrosion_copy_byproducts(
                    {target_name} LIBRARY_OUTPUT_DIRECTORY \"${{cargo_build_out_dir}}\" \"${{shared_lib_byproduct}}\"
                )
            endif()
            if(pdb_byproduct)
                _corrosion_copy_byproducts(
                    {target_name} PDB_OUTPUT_DIRECTORY \"${{cargo_build_out_dir}}\" \"${{pdb_byproduct}}\"
                )
            endif()
            if(bin_byproduct)
                _corrosion_copy_byproducts(
                    {target_name} RUNTIME_OUTPUT_DIRECTORY \"${{cargo_build_out_dir}}\" \"${{bin_byproduct}}\"
                )
            endif()
            ",
            package_name = self.cargo_package.name,
            target_name = self.cargo_target.name,
            package_manifest_path = self.cargo_package.manifest_path.as_str().replace("\\", "/"),
            workspace_manifest_path = ws_manifest,
            target_kinds = target_kinds,
            passthrough_add_cargo_build = passthrough_add_cargo_build,

        )?;
        Ok(())
    }
}
