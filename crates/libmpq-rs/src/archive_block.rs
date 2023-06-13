use byteorder::{ByteOrder, LittleEndian};

#[derive(Debug, Clone)]
#[repr(C)]
pub(crate) struct Hash {
    /// file name hash part A
    pub(crate) hash_a: u32,
    /// file name hash part B
    pub(crate) hash_b: u32,
    /// language of file using windows LANGID type
    pub(crate) locale: u16,
    /// platform file is used for
    pub(crate) platform: u16,
    /// index into the block table of file
    pub(crate) block_index: u32,
}

impl Hash {
    pub fn new(src: &[u8]) -> Hash {
        Hash {
            hash_a: LittleEndian::read_u32(src),
            hash_b: LittleEndian::read_u32(&src[4..]),
            locale: LittleEndian::read_u16(&src[8..]),
            platform: LittleEndian::read_u16(&src[10..]),
            block_index: LittleEndian::read_u32(&src[12..]),
        }
    }
}

#[derive(Debug, Clone)]
#[repr(C)]
pub(crate) struct Block {
    /// offset of the beginning of the file data, relative to the beginning of the archive
    pub(crate) offset: u32,
    /// compressed file size
    pub(crate) packed_size: u32,
    /// uncompressed file size
    pub(crate) unpacked_size: u32,
    /// flags for file
    pub(crate) flags: u32,
}

impl Block {
    pub fn new(src: &[u8]) -> Block {
        Block {
            offset: LittleEndian::read_u32(src),
            packed_size: LittleEndian::read_u32(&src[0x4..]),
            unpacked_size: LittleEndian::read_u32(&src[0x8..]),
            flags: LittleEndian::read_u32(&src[0xC..]),
        }
    }
}
