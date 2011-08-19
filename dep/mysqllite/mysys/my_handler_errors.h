#ifndef MYSYS_MY_HANDLER_ERRORS_INCLUDED
#define MYSYS_MY_HANDLER_ERRORS_INCLUDED

/*
  Errors a handler can give you
*/

static const char *handler_error_messages[]=
{
  "Didn't find key on read or update",
  "Duplicate key on write or update",
  "Internal (unspecified) error in handler",
  "Someone has changed the row since it was read (while the table was locked to prevent it)",
  "Wrong index given to function",
  "Undefined handler error 125",
  "Index file is crashed",
  "Record file is crashed",
  "Out of memory in engine",
  "Undefined handler error 129",
  "Incorrect file format",
  "Command not supported by database",
  "Old database file",
  "No record read before update",
  "Record was already deleted (or record file crashed)",
  "No more room in record file",
  "No more room in index file",
  "No more records (read after end of file)",
  "Unsupported extension used for table",
  "Too big row",
  "Wrong create options",
  "Duplicate unique key or constraint on write or update",
  "Unknown character set used in table",
  "Conflicting table definitions in sub-tables of MERGE table",
  "Table is crashed and last repair failed",
  "Table was marked as crashed and should be repaired",
  "Lock timed out; Retry transaction",
  "Lock table is full;  Restart program with a larger locktable",
  "Updates are not allowed under a read only transactions",
  "Lock deadlock; Retry transaction",
  "Foreign key constraint is incorrectly formed",
  "Cannot add a child row",
  "Cannot delete a parent row",
  "No savepoint with that name",
  "Non unique key block size",
  "The table does not exist in engine",
  "The table already existed in storage engine",
  "Could not connect to storage engine",
  "Unexpected null pointer found when using spatial index",
  "The table changed in storage engine",
  "There's no partition in table for the given value",
  "Row-based binlogging of row failed",
  "Index needed in foreign key constraint",
  "Upholding foreign key constraints would lead to a duplicate key error in "
  "some other table",
  "Table needs to be upgraded before it can be used",
  "Table is read only",
  "Failed to get next auto increment value",
  "Failed to set row auto increment value",
  "Unknown (generic) error from engine",
  "Record is the same",
  "It is not possible to log this statement",
  "The event was corrupt, leading to illegal data being read",
  "The table is of a new format not supported by this version",
  "The event could not be processed no other hanlder error happened",
  "Got a fatal error during initialzaction of handler",
  "File to short; Expected more data in file",
  "Read page with wrong checksum",
  "Too many active concurrent transactions"
};

#endif /* MYSYS_MY_HANDLER_ERRORS_INCLUDED */
