-- Eredar Soul eater

SET @SOULEATER   := 20879;
SET @SOULEATERHC := 21595;
SET @GUID        := 52355; -- TC Unused GUID search tool
SET @POOL        := 368;

UPDATE `creature_template` SET `spell1` = 0, `spell2` = 0, `spell3` = 0, `AIName` = 'SmartAI' WHERE `entry` = @SOULEATER;
UPDATE `creature_template` SET `spell1` = 0, `spell2` = 0, `spell3` = 0 WHERE `entry` = @SOULEATERHC;

-- Eredar Soul Eater SAI // not sure how to implement behaviour for spell:36778(SOUL STEAL)
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@SOULEATER AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@SOULEATER, 0, 0, 0, 1, 0, 100, 0, 0, 0, 0, 0, 11, 36784, 0, 0, 0, 0, 0, 17, 0, 100, 0, 0, 0, 0, 0, "Eredar Soul Eater - At Range - Cast Entropic Aura"),
(@SOULEATER, 0, 1, 0, 0, 0, 100, 0, 6000, 12000, 30000, 30000, 11, 36786, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Eredar Soul Eater - In Combat - Cast Soul Chill");

-- Creature location for Eredar Soul Eater
DELETE FROM `linked_respawn` WHERE `guid` = 86053;
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1) OR id = @SOULEATER;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@GUID, @SOULEATER, 552, 3, 1, 19950, 0, 280.787, 145.315, 22.22593, 0.005122, 7200, 0, 0, 39123, 12620, 0, 0, 0, 8),
(@GUID+1, @SOULEATER, 552, 3, 1, 19950, 0, 307.477, 150.934, 24.85841, 3.959065, 7200, 0, 0, 39123, 12620, 0, 0, 0, 8);


-- Creature Loot for Eredar Soul Eater
DELETE FROM `creature_loot_template` WHERE `entry`=@SOULEATER;
INSERT INTO `creature_loot_template` VALUES 
(@SOULEATER, 30809, 70, 1, 0, 1, 1),
(@SOULEATER, 21877, 39, 1, 0, 2, 3),
(@SOULEATER, 32902, 11, 1, 0, 1, 2),
(@SOULEATER, 27854, 7, 1, 0, 1, 1),
(@SOULEATER, 29740, 5, 1, 0, 1, 1),
(@SOULEATER, 27860, 1.8, 1, 0, 1, 1);

-- Creature Pickpocketing Loot for Eredar Soul Eater
DELETE FROM `pickpocketing_loot_template` WHERE (`entry`=@SOULEATER);
INSERT INTO `pickpocketing_loot_template` VALUES 
(@SOULEATER, 29570, 67, 1, 0, 1, 1),
(@SOULEATER, 29569, 42, 1, 0, 1, 1),
(@SOULEATER, 27855, 25, 1, 0, 1, 1),
(@SOULEATER, 22829, 17, 1, 0, 1, 1),
(@SOULEATER, 27854, 8, 1, 0, 1, 1);

-- Pool_template for Eredar Soul Eater Spawns
DELETE FROM `pool_template` WHERE entry = 1161;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL, 2, 'Eredar Soul-Eater');

-- Pool_creature for Eredar Soul Eater Spawns
DELETE FROM `pool_creature` WHERE guid IN (@GUID, @GUID+1);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID, @POOL, 0, 'Eredar Soul-Eater - Spawn 1'),
(@GUID+1, @POOL, 0, 'Eredar Soul-Eater - Spawn 2');
