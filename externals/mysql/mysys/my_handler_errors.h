
/*
  Errors a handler can give you
*/

static const char *handler_error_messages[]=
{
  /* HA_ERR_KEY_NOT_FOUND */
  "Didn't find key on read or update",
  /* HA_ERR_FOUND_DUPP_KEY */
  "Duplicate key on write or update",
  /* HA_ERR_INTERNAL_ERROR */
  "Internal (unspecified) error in handler",
  /* HA_ERR_RECORD_CHANGED */
  "Someone has changed the row since it was read (while the table was locked to prevent it)",
  /* HA_ERR_WRONG_INDEX */
  "Wrong index given to function",
  /* empty */
  "Undefined handler error 125",
  /* HA_ERR_CRASHED */
  "Index file is crashed",
  /* HA_ERR_WRONG_IN_RECORD */
  "Record file is crashed",
  /* HA_ERR_OUT_OF_MEM */
  "Out of memory in engine",
  /* empty */
  "Undefined handler error 129",
  /* HA_ERR_NOT_A_TABLE */
  "Incorrect file format",
  /* HA_ERR_WRONG_COMMAND */
  "Command not supported by database",
  /* HA_ERR_OLD_FILE */
  "Old database file",
  /* HA_ERR_NO_ACTIVE_RECORD */
  "No record read before update",
  /* HA_ERR_RECORD_DELETED */
  "Record was already deleted (or record file crashed)",
  /* HA_ERR_RECORD_FILE_FULL */
  "No more room in record file",
  /* HA_ERR_INDEX_FILE_FULL */
  "No more room in index file",
  /* HA_ERR_END_OF_FILE */
  "No more records (read after end of file)",
  /* HA_ERR_UNSUPPORTED */
  "Unsupported extension used for table",
  /* HA_ERR_TO_BIG_ROW */
  "Too big row",
  /* HA_WRONG_CREATE_OPTION */
  "Wrong create options",
  /* HA_ERR_FOUND_DUPP_UNIQUE */
  "Duplicate unique key or constraint on write or update",
  /* HA_ERR_UNKNOWN_CHARSET */
  "Unknown character set used in table",
  /* HA_ERR_WRONG_MRG_TABLE_DEF */
  "Conflicting table definitions in sub-tables of MERGE table",
  /* HA_ERR_CRASHED_ON_REPAIR */
  "Table is crashed and last repair failed",
  /* HA_ERR_CRASHED_ON_USAGE */
  "Table was marked as crashed and should be repaired",
  /* HA_ERR_LOCK_WAIT_TIMEOUT */
  "Lock timed out; Retry transaction",
  /* HA_ERR_LOCK_TABLE_FULL */
  "Lock table is full;  Restart program with a larger lock table",
  /* HA_ERR_READ_ONLY_TRANSACTION */
  "Updates are not allowed under a read only transactions",
  /* HA_ERR_LOCK_DEADLOCK */
  "Lock deadlock; Retry transaction",
  /* HA_ERR_CANNOT_ADD_FOREIGN */
  "Foreign key constraint is incorrectly formed",
  /* HA_ERR_NO_REFERENCED_ROW */
  "Cannot add a child row",
  /* HA_ERR_ROW_IS_REFERENCED */
  "Cannot delete a parent row",
  /* HA_ERR_NO_SAVEPOINT */
  "No savepoint with that name",
  /* HA_ERR_NON_UNIQUE_BLOCK_SIZE */
  "Non unique key block size",
  /* HA_ERR_NO_SUCH_TABLE */
  "The table does not exist in engine",
  /* HA_ERR_TABLE_EXIST */
  "The table already existed in storage engine",
  /* HA_ERR_NO_CONNECTION */
  "Could not connect to storage engine",
  /* HA_ERR_NULL_IN_SPATIAL */
  "Unexpected null pointer found when using spatial index",
  /* HA_ERR_TABLE_DEF_CHANGED */
  "The table changed in storage engine",
  /* HA_ERR_NO_PARTITION_FOUND */
  "There's no partition in table for the given value",
  /* HA_ERR_RBR_LOGGING_FAILED */
  "Row-based binary logging of row failed",
  /* HA_ERR_DROP_INDEX_FK */
  "Index needed in foreign key constraint",
  /* HA_ERR_FOREIGN_DUPLICATE_KEY */
  "Upholding foreign key constraints would lead to a duplicate key error in "
  "some other table",
  /* HA_ERR_TABLE_NEEDS_UPGRADE */
  "Table needs to be upgraded before it can be used",
  /* HA_ERR_TABLE_READONLY */
  "Table is read only",
  /* HA_ERR_AUTOINC_READ_FAILED */
  "Failed to get next auto increment value",
  /* HA_ERR_AUTOINC_ERANGE */
  "Failed to set row auto increment value",
  /* HA_ERR_GENERIC */
  "Unknown (generic) error from engine",
  /* HA_ERR_RECORD_IS_THE_SAME */
  "Record was not update. Original values was same as new values",
  /* HA_ERR_LOGGING_IMPOSSIBLE */
  "It is not possible to log this statement",
  /* HA_ERR_TABLESPACE_EXIST */
  "Tablespace exists",
  /* HA_ERR_CORRUPT_EVENT */
  "The event was corrupt, leading to illegal data being read",
  /* HA_ERR_NEW_FILE */
  "The table is of a new format not supported by this version",
  /* HA_ERR_ROWS_EVENT_APPLY */
  "The event could not be processed. No other handler error happened",
  /* HA_ERR_INITIALIZATION */
  "Got a fatal error during initialization of handler",
  /* HA_ERR_FILE_TOO_SHORT */
  "File too short; Expected more data in file",

  /* HA_ERR_WRONG_CRC */
  "Read page with wrong checksum",
  /* HA_ERR_LOCK_OR_ACTIVE_TRANSACTION */
  "Lock or active transaction", /* TODO: get a better message */
  /* HA_ERR_NO_SUCH_TABLESPACE */
  "No such table space", /* TODO: get a better message */
  /* HA_ERR_TABLESPACE_NOT_EMPTY */
  "Tablespace not empty", /* TODO: get a better message */
  /* HA_ERR_TABLESPACE_DATAFILE_EXIST */
  "Tablespace data file already exists", /* TODO: get a better message */
  /* HA_ERR_ROW_NOT_VISIBLE */
  "Row is not visible by the current transaction"
};

