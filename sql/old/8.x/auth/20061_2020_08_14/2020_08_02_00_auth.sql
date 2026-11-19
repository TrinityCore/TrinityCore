-- AUTH CLEANUP PHASE 3
-- update `account` structure
-- sha_pass_hash/s/v kept around for now, for backwards compatibility
ALTER TABLE `account`
    DROP COLUMN `sessionkey`,
    ADD COLUMN `salt` BINARY(32) AFTER `username`,
    ADD COLUMN `verifier` BINARY(32) AFTER `salt`,
    ADD COLUMN `session_key` BINARY(40) AFTER `verifier`,
    MODIFY COLUMN `s` VARCHAR(64) NOT NULL DEFAULT 'dummy value, use `salt` instead',
    MODIFY COLUMN `v` VARCHAR(64) NOT NULL DEFAULT 'dummy value, use `verifier` instead';

UPDATE `account` SET `salt`=REVERSE(UNHEX(`s`)), `s`=DEFAULT WHERE LENGTH(`s`)=64;
UPDATE `account` SET `verifier`=REVERSE(UNHEX(`v`)), `v`=DEFAULT WHERE LENGTH(`v`)=64;
