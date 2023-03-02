-- DB update 2021_04_06_09 -> 2021_04_07_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_06_09';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_06_09 2021_04_07_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616715058536439500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616715058536439500');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_clear_debuffs';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(34098, 'spell_gen_clear_debuffs');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
