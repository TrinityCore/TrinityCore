-- 
ALTER TABLE `warden_checks`
    CHANGE COLUMN `data` `oldData` VARCHAR(48),
    CHANGE COLUMN `result` `oldResult` VARCHAR(24),
    ADD COLUMN `data` BINARY(24) DEFAULT NULL,
    ADD COLUMN `result` VARBINARY(12) DEFAULT NULL;

UPDATE `warden_checks` SET `data`=UNHEX(`oldData`) WHERE `type` IN (113,178,191);
UPDATE `warden_checks` SET `result`=UNHEX(`oldResult`) WHERE `type` IN (152,243);

ALTER TABLE `warden_checks`
    DROP COLUMN `oldData`,
    DROP COLUMN `oldResult`;

DELETE FROM `command` WHERE `name`='reload warden_action';
