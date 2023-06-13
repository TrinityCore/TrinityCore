pub enum Error {
    Io(String),
    InvalidData,
    Other(&'static str),
    UnexpectedEof(String),
    NotFound(String),
    AlreadyExists,
}

impl From<std::io::Error> for Error {
    fn from(value: std::io::Error) -> Self {
        Self::Io(value.to_string())
    }
}
