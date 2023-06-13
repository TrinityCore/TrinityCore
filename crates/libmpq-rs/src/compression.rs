use implode::exploder::Exploder;
use implode::symbol::DEFAULT_CODE_TABLE;
use std::io::{Error, ErrorKind};

const COMPRESSION_HUFFMAN: u8 = 0x01;
const COMPRESSION_ZLIB: u8 = 0x02;
const COMPRESSION_PKWARE: u8 = 0x08;
const COMPRESSION_BZIP2: u8 = 0x10;
const COMPRESSION_SPARSE: u8 = 0x20;
const COMPRESSION_ADPCM_MONO: u8 = 0x40;
const COMPRESSION_ADPCM_STEREO: u8 = 0x80;
const COMPRESSION_LZMA: u8 = 0x12;

pub fn decompress(data: &mut [u8], out: &mut [u8]) -> Result<usize, Error> {
    let compression_type = data[0];

    if compression_type & COMPRESSION_BZIP2 != 0 {
        let mut decompress = bzip2::Decompress::new(true);

        match decompress.decompress(&data[1..], out) {
            Ok(_) => {}
            Err(e) => return Err(Error::new(ErrorKind::Other, e)),
        }

        return Ok(decompress.total_out() as usize);
    }

    if compression_type & COMPRESSION_ZLIB != 0 {
        let mut zlib = flate2::Decompress::new(true);

        match zlib.decompress(&data[1..], out, flate2::FlushDecompress::None) {
            Ok(_) => {}
            Err(e) => return Err(Error::new(ErrorKind::Other, e)),
        }

        return Ok(zlib.total_out() as usize);
    }

    if compression_type & COMPRESSION_PKWARE != 0 {
        let mut exploder = Exploder::new(&DEFAULT_CODE_TABLE);

        let mut cpos: u32 = 1;
        let len = data.len();
        let mut c = 0;

        while !exploder.ended {
            let abuf = &mut data[cpos as usize..len];

            let x = exploder.explode_block(abuf).unwrap();

            cpos += x.0 as u32;

            let bf = x.1;

            for (d, s) in out.iter_mut().zip(bf.iter()) {
                *d = *s;
                c += 1;
            }
        }

        return Ok(c);
    }

    if compression_type & COMPRESSION_HUFFMAN != 0 {
        return Err(Error::new(
            ErrorKind::Other,
            "Compression algorithm Huffman not supported",
        ));
    }

    if compression_type & COMPRESSION_SPARSE != 0 {
        return Err(Error::new(
            ErrorKind::Other,
            "Compression algorithm Sparse not supported",
        ));
    }

    if compression_type & COMPRESSION_ADPCM_STEREO != 0 {
        return Err(Error::new(
            ErrorKind::Other,
            "Compression algorithm ADPCM Stereo not supported",
        ));
    }

    if compression_type & COMPRESSION_ADPCM_MONO != 0 {
        return Err(Error::new(
            ErrorKind::Other,
            "Compression algorithm ADPCM Stereo not supported",
        ));
    }

    if compression_type & COMPRESSION_LZMA != 0 {
        return Err(Error::new(
            ErrorKind::Other,
            "Compression algorithm LZMA not supported",
        ));
    }

    Err(Error::new(ErrorKind::Other, "No compression type found"))
}

pub fn explode(data: &mut [u8], out: &mut [u8]) -> Result<usize, Error> {
    let mut exploder = Exploder::new(&DEFAULT_CODE_TABLE);

    let mut cpos: u32 = 0;
    let len = data.len();
    let mut c = 0;

    while !exploder.ended {
        let abuf = &mut data[cpos as usize..len];

        let x = exploder.explode_block(abuf).unwrap();

        cpos += x.0 as u32;

        let bf = x.1;

        for (d, s) in out.iter_mut().zip(bf.iter()) {
            *d = *s;
            c += 1;
        }
    }

    Ok(c)
}
