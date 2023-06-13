use crate::archive::Archive;
use crate::error::Error;
use std::collections::HashSet;
use std::path::Path;

#[derive(Default)]
pub struct Chain {
    chain: Vec<Archive>,
}

impl Chain {
    pub fn new() -> Self {
        Chain { chain: Vec::new() }
    }

    pub fn size(&self) -> usize {
        self.chain.len()
    }

    pub async fn add<P: AsRef<Path>>(&mut self, path: P) -> Result<(), Error> {
        self.chain.insert(0, Archive::open(path).await?);

        Ok(())
    }

    pub async fn read(&mut self, filename: &str) -> Result<Vec<u8>, Error> {
        for archive in &mut self.chain.iter_mut() {
            if let Ok(file) = archive.open_file(filename).await {
                let mut buf: Vec<u8> = vec![0; file.size() as usize];
                file.read(archive, &mut buf).await?;

                return Ok(buf);
            }
        }

        Err(Error::NotFound(filename.to_string()))
    }

    pub async fn list(&mut self) -> Result<Vec<String>, Error> {
        let mut contents: HashSet<String> = HashSet::new();

        for archive in &mut self.chain.iter_mut() {
            if let Ok(file) = archive.open_file("(listfile)").await {
                let mut buf: Vec<u8> = vec![0; file.size() as usize];

                file.read(archive, &mut buf).await?;
                let Ok(archive_string) = String::from_utf8(buf) else {
                    return Err(Error::InvalidData);
                };

                contents.extend(
                    archive_string
                        .lines()
                        .map(String::from)
                        .collect::<Vec<String>>(),
                );
            }
        }

        Ok(contents.into_iter().collect::<Vec<String>>())
    }

    pub async fn read_to_string(&mut self, filename: &str) -> Result<String, Error> {
        match self.read(filename).await {
            Ok(buf) => match String::from_utf8(buf) {
                Ok(v) => Ok(v),
                Err(_) => Err(Error::InvalidData),
            },
            Err(e) => Err(e),
        }
    }

    // extract file from archive to the local filesystem
    pub async fn extract<P: AsRef<Path>>(
        &mut self,
        filename: &str,
        path: P,
    ) -> Result<usize, Error> {
        for archive in &mut self.chain.iter_mut() {
            let Ok(file) = archive.open_file(filename).await else { continue; };
            return file.extract(archive, path).await;
        }

        Err(Error::NotFound(filename.to_string()))
    }
}
