ALTER TABLE `hotfix_blob`
ADD COLUMN `locale` VARCHAR(4) NOT NULL COLLATE 'utf8mb4_unicode_ci' AFTER `RecordId`,
DROP PRIMARY KEY,
ADD PRIMARY KEY (`TableHash`, `RecordId`, `locale`);

UPDATE `hotfix_blob` SET `locale` = "enUS";
