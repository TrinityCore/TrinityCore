-- DB update 2021_02_04_00 -> 2021_02_04_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_04_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_04_00 2021_02_04_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1611865917828980400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1611865917828980400');
DELETE FROM `item_template_locale` WHERE `ID` IN (30622,30637) and `locale` = 'zhCN';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`) VALUES
(30622, 'zhCN', '焰铸钥匙', '允许你进入英雄难度的地狱火堡垒地下城。', 15050),
(30637, 'zhCN', '焰铸钥匙', '允许你进入英雄难度的地狱火堡垒地下城。', 15050);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
