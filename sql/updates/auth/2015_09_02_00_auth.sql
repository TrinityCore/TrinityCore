SET @s = (SELECT IF(
    (SELECT COUNT(*)
        FROM INFORMATION_SCHEMA.COLUMNS
        WHERE table_name = 'realmlist'
        AND table_schema = DATABASE()
        AND column_name = 'address6'
    ) > 0,
    "SELECT 1",
    "ALTER TABLE realmlist ADD address6 VARCHAR(255) NOT NULL DEFAULT ''"
));

PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

