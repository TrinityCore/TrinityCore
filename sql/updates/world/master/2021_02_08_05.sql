-- DB update 2021_02_08_04 -> 2021_02_08_05
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_08_04';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_08_04 2021_02_08_05 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612704403809446000'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612704403809446000');

UPDATE `command` SET `security` = 1 WHERE `name` = 'gm';
UPDATE `command` SET `security` = 2 WHERE `name` IN ('gm list', 'gm visible');
UPDATE `command` SET `security` = 3 WHERE `name` IN ('cometome', 'wpgps');

INSERT IGNORE INTO  `command` (`name`, `security`, `help`) VALUES
('bank', 2, 'Syntax: .bank Show your bank inventory.'),
('debug Mod32Value', 3, 'Syntax: .debug Mod32Value #field #value Add #value to field #field of your character.');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
