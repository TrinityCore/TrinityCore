-- DB update 2021_04_03_00 -> 2021_04_04_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_03_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_03_00 2021_04_04_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617473386855005400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617473386855005400');

DELETE FROM `spell_dbc` WHERE `ID` =75;
INSERT INTO `spell_dbc` VALUES (75, 0, 0, 0, 327698, 0, 32, 32768, 16777217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 101, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 114, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 262156, 0, 58, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 83, 122, 50, 'Auto Shot','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190,'','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'Automatically shoots the target until cancelled.  Ranged attacks fired by a Hunter all have $34082s2% increased attack speed.','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 'Firing at the target.','','','','','','','','', 0, 0, 0, 0, 0, 0, 0, 16712190, 0, 0, 0, 0, 9, 1, 0, 0, 0, 3, 2, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
