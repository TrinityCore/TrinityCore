SET @dbname = DATABASE();
SET @preparedStatementVp = (SELECT IF(
  (
    SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS
    WHERE
      (table_name = 'account')
      AND (table_schema = @dbname)
      AND (column_name = 'vp')
  ) > 0,
  "SELECT 1",
  "ALTER TABLE account ADD vp INT(10) NULL;"
));
PREPARE addVp FROM @preparedStatementVp;
EXECUTE addVp;
DEALLOCATE PREPARE addVp;

SET @preparedStatementDp = (SELECT IF(
  (
    SELECT COUNT(*) FROM INFORMATION_SCHEMA.COLUMNS
    WHERE
      (table_name = 'account')
      AND (table_schema = @dbname)
      AND (column_name = 'dp')
  ) > 0,
  "SELECT 1",
  "ALTER TABLE account ADD dp INT(10) NULL;"
));
PREPARE addDp FROM @preparedStatementDp;
EXECUTE addDp;
DEALLOCATE PREPARE addDp;
