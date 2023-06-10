pub mod file_loader;

#[repr(u8)]
#[must_use]
pub enum DbcFieldFormat {
    FtNa = b'x',         //not used or unknown, 4 byte size
    FtNaByte = b'X',     //not used or unknown, byte
    FtString = b's',     //char*
    FtFloat = b'f',      //float
    FtInt = b'i',        //uint32
    FtByte = b'b',       //uint8
    FtSort = b'd',       //sorted by this field, field is not included
    FtInd = b'n',        //the same, but parsed to data
    FtLogic = b'l',      //Logical (boolean)
    FtSqlPresent = b'p', //Used in sql format to mark column present in sql dbc
    FtSqlAbsent = b'a',  //Used in sql format to mark column absent in sql dbc
}

impl From<char> for DbcFieldFormat {
    fn from(value: char) -> Self {
        match value {
            'x' => Self::FtNa,
            'X' => Self::FtNaByte,
            's' => Self::FtString,
            'f' => Self::FtFloat,
            'i' => Self::FtInt,
            'b' => Self::FtByte,
            'd' => Self::FtSort,
            'n' => Self::FtInd,
            'l' => Self::FtLogic,
            'p' => Self::FtSqlPresent,
            'a' => Self::FtSqlAbsent,
            _ => panic!("Unknown field format character in DBCfmt.h"),
        }
    }
}
