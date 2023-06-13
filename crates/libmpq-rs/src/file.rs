use crate::archive_block::Block;
use crate::compression::{decompress, explode};
use crate::crypt::decrypt;
use crate::error::Error;
use crate::Archive;
use adler32::RollingAdler32;
use std::io::SeekFrom;
use std::path::Path;
use tokio::fs;
use tokio::io::{AsyncReadExt, AsyncSeekExt, AsyncWriteExt};

#[derive(Debug)]
pub struct File {
    pub(crate) name: String,
    pub(crate) block: Block,
    pub(crate) sector_offsets: Vec<u32>,
    pub(crate) sector_checksums: Vec<u32>,
    pub(crate) file_key: u32,
}

pub(crate) const FILE_IMPLODE: u32 = 0x00000100; // implode method by pkware compression library
pub(crate) const FILE_COMPRESS: u32 = 0x00000200; // compress methods by multiple methods
pub(crate) const FILE_ENCRYPTED: u32 = 0x00010000; // file is encrypted
pub(crate) const FILE_FIX_KEY: u32 = 0x00020000; // file decryption key is altered according to position of file in archive
pub(crate) const FILE_PATCH_FILE: u32 = 0x00100000; // file is a patch file. file data begins with patchinfo struct
pub(crate) const FILE_SINGLE_UNIT: u32 = 0x01000000; // file is stored as single unit
pub(crate) const FILE_SECTOR_CRC: u32 = 0x04000000;
pub(crate) const FILE_COMPRESS_MASK: u32 = 0x0000FF00;

impl File {
    pub fn size(&self) -> u32 {
        self.block.unpacked_size
    }

    pub fn name(&self) -> &str {
        self.name.as_ref()
    }

    // read data from file
    pub async fn read(&self, archive: &mut Archive, buf: &mut [u8]) -> Result<usize, Error> {
        if self.block.flags & FILE_PATCH_FILE != 0 {
            Err(Error::Other("Patch file not supported"))
        } else if self.block.flags & FILE_SINGLE_UNIT != 0 {
            // file is single block file
            self.read_single_unit_file(
                self.block.packed_size as usize,
                &mut archive.file,
                archive.offset,
                buf,
            )
            .await
        } else {
            // read as sector based MPQ file
            self.read_sector_file(archive, buf).await
        }
    }

    async fn read_sector_file(
        &self,
        archive: &mut Archive,
        out: &mut [u8],
    ) -> Result<usize, Error> {
        let mut buff: Vec<u8> = vec![0; archive.header.sector_size()];
        let mut read: usize = 0;

        if self.block.flags & FILE_COMPRESS_MASK != 0 {
            for i in 0..self.sector_offsets.len() - 1 {
                let sector_offset = self.sector_offsets[i];
                let sector_size = self.sector_offsets[i + 1] - sector_offset;

                let in_buf: &mut [u8] = &mut buff[0..sector_size as usize];
                let out_buf: &mut [u8] = &mut out[read..];

                archive
                    .file
                    .seek(SeekFrom::Start(
                        (self.block.offset + sector_offset) as u64 + archive.offset,
                    ))
                    .await?;
                archive.file.read_exact(in_buf).await?;

                if self.block.flags & FILE_ENCRYPTED != 0 {
                    decrypt(in_buf, self.file_key + i as u32);
                }

                // checksum verification
                if !self.sector_checksums.is_empty() && self.sector_checksums[i] != 0 {
                    let mut adler = RollingAdler32::from_value(0);
                    adler.update_buffer(in_buf);

                    if self.sector_checksums[i] != adler.hash() {
                        return Err(Error::Other("Sector checksum error"));
                    }
                }

                if self.block.flags & FILE_COMPRESS != 0 {
                    if in_buf.len() == archive.header.sector_size() || in_buf.len() == out_buf.len()
                    {
                        for (dst, src) in out_buf.iter_mut().zip(in_buf) {
                            *dst = *src;
                            read += 1;
                        }
                    } else {
                        read += decompress(in_buf, out_buf)?;
                    }
                } else if self.block.flags & FILE_IMPLODE != 0 {
                    if in_buf.len() == archive.header.sector_size() || in_buf.len() == out_buf.len()
                    {
                        for (dst, src) in out_buf.iter_mut().zip(in_buf) {
                            *dst = *src;
                            read += 1;
                        }
                    } else {
                        read += explode(in_buf, out_buf)?;
                    }
                }
            }
        } else {
            archive
                .file
                .seek(SeekFrom::Start(self.block.offset as u64 + archive.offset))
                .await?;
            archive.file.read_exact(out).await?;

            read = out.len();
        }

        Ok(read)
    }

    async fn read_single_unit_file(
        &self,
        buff_size: usize,
        file: &mut fs::File,
        offset: u64,
        out_buf: &mut [u8],
    ) -> Result<usize, Error> {
        let mut in_buff: Vec<u8> = vec![0; buff_size];

        file.seek(SeekFrom::Start(u64::from(self.block.offset) + offset))
            .await?;
        file.read_exact(&mut in_buff).await?;

        if self.block.flags & FILE_ENCRYPTED != 0 {
            decrypt(&mut in_buff, self.file_key);
        }

        if self.block.flags & FILE_COMPRESS != 0 && out_buf.len() > in_buff.len() {
            Ok(decompress(&mut in_buff, out_buf)?)
        } else if self.block.flags & FILE_IMPLODE != 0 {
            Ok(explode(&mut in_buff, out_buf)?)
        } else {
            for (dst, src) in out_buf.iter_mut().zip(&in_buff) {
                *dst = *src
            }

            Ok(self.block.unpacked_size as usize)
        }
    }

    // extract file from archive to the local filesystem
    pub async fn extract<P: AsRef<Path>>(
        &self,
        archive: &mut Archive,
        path: P,
    ) -> Result<usize, Error> {
        let mut buf: Vec<u8> = vec![0; self.size() as usize];
        self.read(archive, &mut buf).await?;

        fs::create_dir_all(path.as_ref().parent().unwrap()).await?;

        if path.as_ref().exists() {
            return Err(Error::AlreadyExists);
        }

        let mut file = fs::OpenOptions::new()
            .create(true)
            .write(true)
            .open(&path)
            .await
            .unwrap();

        Ok(file.write(&buf).await?)
    }
}
