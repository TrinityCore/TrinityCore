-- DB update 2021_02_01_06 -> 2021_02_02_00
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_01_06';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_01_06 2021_02_02_00 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1611180684314340400'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1611180684314340400');

DELETE FROM `spell_script_names` WHERE `spell_id` = 75731;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75731, 'spell_item_instant_statue');
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432, `AIName` = '' WHERE `entry` = 40246;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (74890, -75731);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(74890, 75055, 0, 'Instant Statue'),
(-75731, -74890, 0, 'Instant Statue'),
(-75731, -75055, 0, 'Instant Statue');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
