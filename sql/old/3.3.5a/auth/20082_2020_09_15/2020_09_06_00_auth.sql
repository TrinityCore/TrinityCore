-- 
UPDATE `account` SET `salt`=UNHEX(CONCAT(MD5(RAND()),MD5(RAND()))), `verifier`=UNHEX(CONCAT(MD5(RAND()),MD5(RAND()))) WHERE `salt` IS NULL OR `verifier` IS NULL;
ALTER TABLE `account`
    DROP COLUMN `s`,
    DROP COLUMN `v`,
    DROP COLUMN `sha_pass_hash`,
    MODIFY COLUMN `salt` BINARY(32) NOT NULL,
    MODIFY COLUMN `verifier` BINARY(32) NOT NULL;
