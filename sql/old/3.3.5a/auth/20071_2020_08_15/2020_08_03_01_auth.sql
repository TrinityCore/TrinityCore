-- 
ALTER TABLE `account`
    DROP COLUMN `session_key`,
    ADD COLUMN `session_key_auth` BINARY(40) DEFAULT NULL AFTER `verifier`,
    ADD COLUMN `session_key_bnet` VARBINARY(64) DEFAULT NULL AFTER `session_key_auth`;
