use crate::dbc::DbcFieldFormat;
use std::ffi::{c_char, c_float, CStr};

/// Returns the size of the record based on textual representation
pub fn get_format_record_size(format: &str) -> (usize, Option<usize>) {
    let mut record_size = 0;
    let mut index_position = None;

    for (idx, char) in format.chars().enumerate() {
        record_size += match DbcFieldFormat::from(char) {
            DbcFieldFormat::FtFloat => std::mem::size_of::<c_float>(),
            DbcFieldFormat::FtInt => std::mem::size_of::<u32>(),
            DbcFieldFormat::FtString => std::mem::size_of::<*const c_char>(),
            DbcFieldFormat::FtSort => {
                index_position = Some(idx);
                0
            }
            DbcFieldFormat::FtInd => {
                index_position = Some(idx);
                std::mem::size_of::<u32>()
            }
            DbcFieldFormat::FtByte => std::mem::size_of::<u8>(),
            DbcFieldFormat::FtNa | DbcFieldFormat::FtNaByte => 0,
            DbcFieldFormat::FtLogic => {
                panic!("Attempted to load DBC files that do not have field types that match what is in the core. Check your DBC files.");
            }
            _ => unreachable!(),
        }
    }

    (record_size, index_position)
}

/// # Safety
/// C++ Interface. Do conversions from unsafe structs to safe ones and back.
/// Asserts that the format pointer is non-null.
#[no_mangle]
pub unsafe extern "C" fn DBCFileLoader_GetFormatRecordSize(
    format: *const c_char,
    index_pos: *mut i32,
) -> usize {
    assert_ne!(format, std::ptr::null());

    let format = CStr::from_ptr(format).to_str().unwrap();
    let (record_size, index_position) = get_format_record_size(format);
    if let Some(index_pos) = index_pos.as_mut() {
        *index_pos = index_position.map_or(-1, |p| p as i32);
    }

    record_size
}

#[cfg(test)]
mod tests {
    use crate::dbc::file_loader::get_format_record_size;
    use std::ffi::c_void;

    #[test]
    pub fn format_record_size() {
        assert_eq!(get_format_record_size("f"), (4, None));
        assert_eq!(get_format_record_size("i"), (4, None));
        assert_eq!(
            get_format_record_size("s"),
            (std::mem::size_of::<*const c_void>(), None)
        );
        assert_eq!(get_format_record_size("d"), (0, Some(0)));
        assert_eq!(get_format_record_size("n"), (4, Some(0)));
        assert_eq!(get_format_record_size("b"), (1, None));
        assert_eq!(get_format_record_size("x"), (0, None));
        assert_eq!(get_format_record_size("X"), (0, None));

        assert_eq!(get_format_record_size("ffinbb"), (18, Some(3)));
    }
}
