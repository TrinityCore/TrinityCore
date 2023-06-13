use crate::archive_block::{Block, Hash};
use crate::crypt::{decrypt, hash_string};
use crate::error::Error;
use crate::file::{FILE_COMPRESS, FILE_ENCRYPTED, FILE_FIX_KEY, FILE_SECTOR_CRC, FILE_SINGLE_UNIT};
use crate::header::{ArchiveHeader, UserDataHeader, V4_HEADER_SIZE};
use std::io::SeekFrom;
use std::path::Path;
use tokio::fs::File;
use tokio::io::{AsyncReadExt, AsyncSeekExt};

const ID_MPQA: &[u8] = b"MPQ\x1A";
const ID_MPQB: &[u8] = b"MPQ\x1B";

pub struct Archive {
    pub(crate) file: File,
    pub(crate) header: ArchiveHeader,
    user_data_header: Option<UserDataHeader>,
    hash_table: Vec<Hash>,
    block_table: Vec<Block>,
    pub(crate) offset: u64,
}

impl Archive {
    pub async fn open<P>(path: P) -> Result<Self, Error>
    where
        P: AsRef<Path> + Sized,
    {
        let mut file = File::open(path).await?;
        let mut buffer = [0_u8; V4_HEADER_SIZE];
        let mut offset = 0_u64;
        let mut user_data_header: Option<UserDataHeader> = None;

        loop {
            file.seek(SeekFrom::Start(offset)).await?;
            file.read_exact(&mut buffer).await?;

            if buffer.starts_with(ID_MPQA) {
                break;
            }

            if buffer.starts_with(ID_MPQB) {
                let header = UserDataHeader::new(&buffer, offset as usize);
                offset += header.header_offset as u64;

                file.seek(SeekFrom::Start(offset)).await?;
                file.read_exact(&mut buffer).await?;

                if !buffer.starts_with(ID_MPQA) {
                    return Err(Error::InvalidData);
                }

                user_data_header = Some(header);
                break;
            }

            offset += 0x200;
        }

        let header = ArchiveHeader::new(&buffer)?;

        // read hash table
        let mut hash_buff: Vec<u8> =
            vec![0; (header.hash_table_size as usize) * std::mem::size_of::<Hash>()];
        let mut hash_table: Vec<Hash> = Vec::with_capacity(header.hash_table_size as usize);

        file.seek(SeekFrom::Start(header.hash_table_pos as u64 + offset))
            .await?;
        file.read_exact(&mut hash_buff).await?;
        decrypt(&mut hash_buff, hash_string("(hash table)", 0x300));

        for x in 0..header.hash_table_size {
            hash_table.push(Hash::new(
                &hash_buff[x as usize * std::mem::size_of::<Hash>()..],
            ));
        }

        // read block table
        let mut block_buff: Vec<u8> =
            vec![0; (header.block_table_size as usize) * std::mem::size_of::<Block>()];
        let mut block_table: Vec<Block> = Vec::with_capacity(header.block_table_size as usize);

        file.seek(SeekFrom::Start(header.block_table_pos as u64 + offset))
            .await?;
        file.read_exact(&mut block_buff).await?;
        decrypt(&mut block_buff, hash_string("(block table)", 0x300));

        for x in 0..header.block_table_size {
            block_table.push(Block::new(
                &block_buff[x as usize * std::mem::size_of::<Block>()..],
            ));
        }

        Ok(Self {
            file,
            header,
            user_data_header,
            hash_table,
            block_table,
            offset,
        })
    }

    pub async fn read_user_data(&mut self) -> Result<Option<Vec<u8>>, Error> {
        let Some(ref header) = self.user_data_header else {
            return Ok(None);
        };

        let mut buf: Vec<u8> = vec![0; header.user_data_size as usize];

        self.file
            .seek(SeekFrom::Start(
                (header.user_data_header_offset + header.user_data_header_size as usize) as u64,
            ))
            .await?;
        self.file.read_exact(&mut buf).await?;

        Ok(Some(buf))
    }

    pub async fn open_file(&mut self, filename: &str) -> Result<crate::File, Error> {
        use byteorder::{ByteOrder, LittleEndian};

        let sector_size = self.header.sector_size();
        let start_index = (hash_string(filename, 0x0) & (self.header.hash_table_size - 1)) as usize;

        let mut hash;
        let hash_a = hash_string(filename, 0x100);
        let hash_b = hash_string(filename, 0x200);
        let mut file_key = 0;

        for i in start_index..self.hash_table.len() {
            hash = &self.hash_table[i];
            if hash.hash_a != hash_a || hash.hash_b != hash_b {
                continue;
            }

            let block = &self.block_table[hash.block_index as usize];
            let mut sector_offsets: Vec<u32> = Vec::new();
            let mut sector_checksums: Vec<u32> = Vec::new();

            // file if encrypted, generate decryption key
            if block.flags & FILE_ENCRYPTED != 0 {
                match filename.split(&['\\', '/'][..]).last() {
                    Some(basename) => file_key = hash_string(basename, 0x300),
                    None => {
                        return Err(Error::Other("Unable to extract filename from path"));
                    }
                }

                // fix decryption key
                if block.flags & FILE_FIX_KEY != 0 {
                    file_key = (file_key + block.offset) ^ block.unpacked_size;
                }
            }

            // block split into sectors, read sector offsets
            if block.flags & FILE_SINGLE_UNIT == 0 {
                // FixMe: handle empty files, packed and unpacked size should be 0

                if block.unpacked_size == 0 || sector_size == 0 {
                    return Err(Error::UnexpectedEof(filename.to_string()));
                }

                let num_sectors = ((block.unpacked_size - 1) / sector_size as u32) + 1;
                let mut sector_buff: Vec<u8> = vec![0; ((num_sectors as usize) + 1) * 4];

                self.file
                    .seek(SeekFrom::Start(u64::from(block.offset) + self.offset))
                    .await?;
                self.file.read_exact(&mut sector_buff).await?;

                if block.flags & FILE_ENCRYPTED != 0 {
                    decrypt(&mut sector_buff, file_key - 1);
                }

                let mut x = 0;
                while x < sector_buff.len() - 3 {
                    sector_offsets.push(LittleEndian::read_u32(&sector_buff[x..]));
                    x += 4;
                }

                // load sector checksums
                if block.flags & FILE_COMPRESS != 0 && block.flags & FILE_SECTOR_CRC != 0 {
                    let mut buff: Vec<u8> = vec![0; 4];

                    self.file.read_exact(&mut buff).await?;

                    let last_offset = LittleEndian::read_u32(&buff);
                    let checksum_offset = sector_offsets[num_sectors as usize];
                    let sector_size = last_offset - checksum_offset;
                    let expected_size = num_sectors * 4_u32;

                    // is checksum sector the expected size
                    if sector_size == expected_size {
                        self.file
                            .seek(SeekFrom::Start(
                                u64::from(block.offset) + u64::from(checksum_offset),
                            ))
                            .await?;

                        for _ in 0..num_sectors {
                            self.file.read_exact(&mut buff).await?;
                            sector_checksums.push(LittleEndian::read_u32(&buff));
                        }
                    }
                }
            }

            return Ok(crate::File {
                name: String::from(filename),
                block: block.clone(),
                sector_offsets,
                sector_checksums,
                file_key,
            });
        }

        Err(Error::NotFound(filename.to_string()))
    }
}
