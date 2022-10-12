-- DB update 2021_01_25_00 -> 2021_03_21_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_auth' AND COLUMN_NAME = '2021_01_25_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_auth CHANGE COLUMN 2021_01_25_00 2021_03_21_00 bit;
SELECT sql_rev INTO OK FROM version_db_auth WHERE sql_rev = '1615629613255169700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_auth` (`sql_rev`) VALUES ('1615629613255169700');

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

ALTER TABLE `account`
    DROP COLUMN `session_key`,
    ADD COLUMN `session_key` BINARY(40) DEFAULT NULL AFTER `verifier`;

UPDATE `account` SET `salt`=UNHEX(CONCAT(MD5(RAND()),MD5(RAND()))), `verifier`=UNHEX(CONCAT(MD5(RAND()),MD5(RAND()))) WHERE `salt` IS NULL OR `verifier` IS NULL;

ALTER TABLE `account`
    DROP COLUMN `s`,
    DROP COLUMN `v`,
    DROP COLUMN `sha_pass_hash`,
    MODIFY COLUMN `salt` BINARY(32) NOT NULL,
    MODIFY COLUMN `verifier` BINARY(32) NOT NULL;

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
