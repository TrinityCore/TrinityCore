-- DB update 2021_03_11_03 -> 2021_03_11_04
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_11_03';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_11_03 2021_03_11_04 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615287196510790727'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615287196510790727');

-- Delete spell_linked_spell  for Shadowmeld
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (58984);

-- Fix Shadowmeld
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_shadowmeld';
INSERT INTO `spell_script_names` VALUES (58984, 'spell_gen_shadowmeld');
--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
