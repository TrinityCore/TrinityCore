use std::error::Error;
use std::fmt::{Debug, Display, Formatter};

pub(crate) struct DummyError {}

impl Debug for DummyError {
    fn fmt(&self, _: &mut Formatter<'_>) -> std::fmt::Result {
        unreachable!()
    }
}

impl Display for DummyError {
    fn fmt(&self, _: &mut Formatter<'_>) -> std::fmt::Result {
        unreachable!()
    }
}

impl Error for DummyError {}
