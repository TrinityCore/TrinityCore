-- DB update 2021_03_07_02 -> 2021_03_07_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_07_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_07_02 2021_03_07_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614643528862573973'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614643528862573973');

DELETE FROM `spell_dbc` WHERE `ID`=49214;
INSERT INTO `spell_dbc` VALUES
(49214,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,101,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,28,0,0,1,0,0,0,0,0,0,0,0,0,0,0,18,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17102,0,0,247,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,"New Summon Test","New Summon Test","Test nouvelle invocation","Neuer Beschwörungstest","","","New Summon Test","New Summon Test","New Summon Test","","","","","","","",16712190,"","","","","","","","","","","","","","","","",16712172,"","","","","","","","","","","","","","","","",16712188,"","","","","","","","","","","","","","","","",16712188,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0);


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
