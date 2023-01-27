-- DB update 2021_03_19_02 -> 2021_03_20_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_19_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_19_02 2021_03_20_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614870494129873100'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614870494129873100');

DELETE FROM `spell_target_position` WHERE `ID`=62501 AND `EffectIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES (62501, 0, 603, 2035.95, -202.085, 432.687, 3.16408, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` = 62502;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (62501, 'spell_hodir_shatter_chest');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
