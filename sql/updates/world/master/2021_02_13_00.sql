-- DB update 2021_02_12_06 -> 2021_02_13_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_12_06';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_12_06 2021_02_13_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1612679130179828100'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1612679130179828100');

DELETE FROM `item_template_locale` WHERE `ID` IN (30623,30633,30634,30635,24490) AND `locale` = 'zhCN';
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`) VALUES
(30623, 'zhCN', '水库钥匙', '允许你进入英雄难度的盘牙水库地下城。', 15050),
(30633, 'zhCN', '奥金尼钥匙', '允许你进入英雄难度的奥金顿地下城。', 15050),
(30634, 'zhCN', '星船钥匙', '允许你进入英雄难度的风暴要塞地下城。', 15050),
(30635, 'zhCN', '时光之钥', '允许你进入英雄难度的时光之穴地下城。', 15050),
(24490, 'zhCN', '麦迪文的钥匙', '', 15050);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
