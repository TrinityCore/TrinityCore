-- DB update 2021_04_18_00 -> 2021_04_18_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_18_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_18_00 2021_04_18_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1618698984447935300'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1618698984447935300');

-- Ground & water
UPDATE `creature_template` SET `InhabitType`=3 WHERE entry IN (
3632, -- Deviate Creeper
3633, -- Deviate Slayer
3634, -- Deviate Stalker
3636, -- Deviate Ravager
3638); -- Devouring Ectoplasm

-- Ground & air
UPDATE `creature_template` SET `InhabitType`=5 WHERE entry IN (
3630, -- Deviate Coiler
3631, -- Deviate Stinglash
20797); -- Deviate Coiler Hatchling

-- Improve SAI for Deviate Stinglash
-- https://wowgaming.altervista.org/aowow/?npc=3631#abilities
UPDATE `smart_scripts` SET `event_param1`=5000, `event_param2`=7000, `event_param3`=12000, `event_param4`=18000, `comment`='Deviate Stinglash - In Combat - Cast Lash' WHERE `entryorguid`=3631 AND `source_type`=0 AND `id`=0 AND `link`=0;


--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
