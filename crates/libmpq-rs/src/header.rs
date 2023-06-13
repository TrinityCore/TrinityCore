use crate::error::Error;
use byteorder::{ByteOrder, LittleEndian};

pub(crate) struct UserDataHeader {
    pub(crate) user_data_size: u32,
    pub(crate) header_offset: u32,
    pub(crate) user_data_header_size: u32,

    pub(crate) user_data_header_offset: usize,
}

impl UserDataHeader {
    pub fn new(src: &[u8], user_data_header_offset: usize) -> Self {
        Self {
            user_data_size: LittleEndian::read_u32(&src[0x4..]),
            header_offset: LittleEndian::read_u32(&src[0x8..]),
            user_data_header_size: LittleEndian::read_u32(&src[0xC..]),
            user_data_header_offset,
        }
    }
}

const V1_HEADER_SIZE: usize = 0x20;
const V2_HEADER_SIZE: usize = 0x2C;
const V3_HEADER_SIZE: usize = 0x44;
pub(crate) const V4_HEADER_SIZE: usize = 0xD0;

#[derive(Default)]
pub(crate) struct ArchiveHeader {
    header_size: u32,
    block_size: u16,
    pub(crate) hash_table_pos: u32,
    pub(crate) block_table_pos: u32,
    pub(crate) hash_table_size: u32,
    pub(crate) block_table_size: u32,

    hi_block_table_pos_64: u64,
    hi_hash_table_pos: u16,
    hi_block_table_pos: u16,

    archive_size_64: u64,
    bet_table_pos: u64,
    het_table_pos: u64,

    hash_table_size_64: u64,
    block_table_size_64: u64,
    hi_block_table_size_64: u64,
    het_table_size_64: u64,
    bet_table_size_64: u64,
    raw_chunk_size: u32,
    md5_block_table: [u8; 16],
    md5_hash_table: [u8; 16],
    md5_hi_block_table: [u8; 16],
    md5_bet_table: [u8; 16],
    md5_het_table: [u8; 16],
    md5_mpq_table: [u8; 16],
}

impl ArchiveHeader {
    pub fn new(src: &[u8; V4_HEADER_SIZE]) -> Result<Self, Error> {
        let mut this = Self {
            header_size: LittleEndian::read_u32(&src[0x04..]),
            block_size: LittleEndian::read_u16(&src[0x0E..]),
            hash_table_pos: LittleEndian::read_u32(&src[0x10..]),
            block_table_pos: LittleEndian::read_u32(&src[0x14..]),
            hash_table_size: LittleEndian::read_u32(&src[0x18..]),
            block_table_size: LittleEndian::read_u32(&src[0x1C..]),
            ..Default::default()
        };

        match this.header_size as usize {
            V1_HEADER_SIZE => {}
            V2_HEADER_SIZE => {
                this.read_v2_header(src)?;
            }
            V3_HEADER_SIZE => {
                this.read_v3_header(src)?;
            }
            V4_HEADER_SIZE => {
                this.read_v4_header(src)?;
            }
            _ => return Err(Error::InvalidData),
        }

        Ok(this)
    }

    pub fn sector_size(&self) -> usize {
        512 << self.block_size
    }

    fn read_v2_header(&mut self, src: &[u8; V4_HEADER_SIZE]) -> Result<(), Error> {
        self.hi_block_table_pos_64 = LittleEndian::read_u64(&src[0x20..]);
        self.hi_hash_table_pos = LittleEndian::read_u16(&src[0x28..]);
        self.hi_block_table_pos = LittleEndian::read_u16(&src[0x2A..]);

        Ok(())
    }

    fn read_v3_header(&mut self, src: &[u8; V4_HEADER_SIZE]) -> Result<(), Error> {
        self.read_v2_header(src)?;

        self.archive_size_64 = LittleEndian::read_u64(&src[0x2C..]);
        self.bet_table_pos = LittleEndian::read_u64(&src[0x34..]);
        self.het_table_pos = LittleEndian::read_u64(&src[0x3C..]);

        Ok(())
    }

    fn read_v4_header(&mut self, src: &[u8; V4_HEADER_SIZE]) -> Result<(), Error> {
        self.read_v3_header(src)?;

        self.hash_table_size_64 = LittleEndian::read_u64(&src[0x44..]);
        self.block_table_size_64 = LittleEndian::read_u64(&src[0x4C..]);
        self.hi_block_table_size_64 = LittleEndian::read_u64(&src[0x54..]);
        self.het_table_size_64 = LittleEndian::read_u64(&src[0x5C..]);
        self.bet_table_size_64 = LittleEndian::read_u64(&src[0x64..]);
        self.raw_chunk_size = LittleEndian::read_u32(&src[0x6C..]);
        self.md5_block_table.copy_from_slice(&src[0x70..0x80]);
        self.md5_hash_table.copy_from_slice(&src[0x80..0x90]);
        self.md5_hi_block_table.copy_from_slice(&src[0x90..0xA0]);
        self.md5_bet_table.copy_from_slice(&src[0xA0..0xB0]);
        self.md5_het_table.copy_from_slice(&src[0xB0..0xC0]);
        self.md5_mpq_table.copy_from_slice(&src[0xC0..0xD0]);

        Ok(())
    }
}
