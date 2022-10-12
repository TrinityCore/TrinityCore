-- DB update 2021_03_14_07 -> 2021_03_14_08
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_14_07';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_14_07 2021_03_14_08 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1615597737321479109'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1615597737321479109');

-- Fixing template for Pridewing Soarer
DELETE FROM `creature_template` WHERE (`entry` = 6141);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `DamageModifier`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(6141, 0, 0, 0, 0, 0, 2155, 0, 0, 0, 'Pridewing Soarer', NULL, NULL, 0, 22, 22, 0, 16, 0, 1, 1.14286, 1, 0, 32, 42, 0, 78, 1, 2000, 2000, 1, 0, 2048, 0, 0, 0, 0, 0, 0, 21, 32, 4, 1, 0, 0, 0, 100006, 0, 0, 0, 0, 0, 0, 744, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 1, 1, 1.02, 1, 1, 0, 144, 1, 0, 0, 2, '', 12340);

-- Fixing spawn places for Pridewing Soarer
DELETE FROM `creature` WHERE (`id` = 6141);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(32317, 6141, 1, 0, 0, 1, 1, 2155, 0, 1392.03, 920.975, 149.868, 5.91921, 300, 0, 0, 574, 0, 0, 0, 0, 0, '', 0),
(32316, 6141, 1, 0, 0, 1, 1, 2155, 0, 1644.5, 907.431, 124.021, 0.897669, 300, 0, 0, 574, 0, 0, 0, 0, 0, '', 0);

-- Quest item loot added for Pridewing Soarer
DELETE FROM `creature_questitem` WHERE (`CreatureEntry` = 6141);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(6141, 0, 5808, 0);

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
