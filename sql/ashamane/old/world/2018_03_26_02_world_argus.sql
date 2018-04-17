SET @GUID := 21011558;

-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `faction` = 16, `rank` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 33280, `unit_flags2` = 2048, `type` = 7 WHERE (entry = 125233);

-- FULL `creature` of id 125233
DELETE FROM `creature` WHERE (guid = @GUID+0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(@GUID+0, 125233, 1669, 8701, 8885, 1, 0, 0, 6241.899902, 9903.650391, -25.274401, 2.32921, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

-- Creating a new SmartAI script for [Creature] ENTRY 126368 (name: Investigate the Ruins of Oronaar)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 126368;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 126368);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(126368, 0, 0, 0, 10, 0, 100, 0, 1, 0, 0, 0, 33, 126368, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

-- Creating a new SmartAI script for [Creature] ENTRY 110557 (name: Prophet Velen)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 110557;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 110557);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(110557, 0, 0, 0, 10, 0, 100, 0, 1, 0, 0, 0, 33, 110557, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, '');

-- Creating a new SmartAI script for [Creature] ENTRY 111719 (name: Kill Credit: Use Hatecoil Lens)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 111719;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 111719);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(111719, 0, 0, 0, 10, 0, 100, 0, 1, 0, 0, 0, 33, 111719, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

-- FULL `creature` of id 111719
DELETE FROM `creature` WHERE (guid = @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(@GUID+1, 111719, 1512, 7834, 7834, 1, 0, 0, 1376.22998, 1344.410034, 176.738007, 0.013963, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `faction` = 14, `rank` = 1, `unit_flags` = 49728, `unit_flags2` = 2048, `type` = 7, `spell1` = 251745, `spell2` = 251759, `HealthModifier` = 26 WHERE (entry = 125034);

-- FULL `creature` of id 125034
DELETE FROM `creature` WHERE (guid = @GUID+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(@GUID+2, 125034, 1669, 8574, 9050, 1, 0, 0, 2477.697998, 2133.38501, 313.019196, 3.863323, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

-- FULL `creature_loot_template` of Entry 122950
DELETE FROM `creature_loot_template` WHERE (Entry = 122950);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(122950, 150993, 0, 100, 1, 1, 0, 1, 1, '');

-- FULL `creature` of id 122950
DELETE FROM `creature` WHERE (guid = @GUID+3);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(@GUID+3, 122950, 1669, 8574, 8933, 1, 0, 0, 1218.865234, 2636.91626, 423.613586, 3.419825, 10, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

-- Table `creature_template`
UPDATE `creature_template` SET `minlevel` = 110, `maxlevel` = 110, `faction` = 35, `npcflag` = 2, `unit_flags` = 768, `unit_flags2` = 2048 WHERE (entry = 121578);

-- FULL `creature` of id 121578
DELETE FROM `creature` WHERE (guid = @GUID+4);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(@GUID+4, 121578, 1669, 8574, 8933, 1, 0, 0, 952.786987, 2565.600098, 391.287994, 5.29456, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);

-- Table creature_template
UPDATE creature_template SET npcflag = 33554432, unit_flags = 16777984 WHERE (entry = 122794);

-- Table `gameobject_template`
UPDATE `gameobject_template` SET `type` = 3, `displayId` = 44037, `castBarCaption` = 'Opening', `Data0` = 57, `Data1` = 267729 WHERE (entry = 267729);

-- FULL `gameobject_template` of entry 267729
DELETE FROM `gameobject_template` WHERE (entry = 267729);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
(267729, 3, 30322, 'Argunite Crystal', 'questinteract', 'Collecting', '', 1, 43, 150942, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74152, 0, 0, 0, '', '', 26124);


-- Table `creature_template`
UPDATE `creature_template` SET `InhabitType` = 4 WHERE (entry = 126114);

-- Table `creature_template`
UPDATE `creature_template` SET `InhabitType` = 4 WHERE (entry = 126341);

-- Table `creature_template`
UPDATE `creature_template` SET `InhabitType` = 4 WHERE (entry = 126207);

-- Table creature_template
UPDATE creature_template SET minlevel = 110, maxlevel = 110, lootid = 124677, faction = 16, rank = 1, BaseAttackTime = 2800, RangeAttackTime = 0, unit_flags = 64, type = 7, type_flags = 2097260, spell1 = 252315, spell4 = 252312, spell5 = 252314, HealthModifier = 32, ManaModifier = 533.107 WHERE (entry = 124677);

-- FULL `creature_loot_template` of Entry 124677
DELETE FROM `creature_loot_template` WHERE (Entry = 124677);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(124677, 151476, 0, 100, 1, 1, 0, 1, 1, '');

-- Table `gameobject_template`
UPDATE `gameobject_template` SET `type` = 3 WHERE (entry = 271668);

-- FULL `gameobject` of id 271668
DELETE FROM `gameobject` WHERE (id = 271668);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`, `PhaseId`, `PhaseGroup`) VALUES
(0, 271668, 1669, 8701, 8882, 1, 5630.148438, 9509.030273, -68.814919, 3.146066, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0);


-- FULL `creature_loot_template` of Entry 123508
DELETE FROM `creature_loot_template` WHERE (Entry = 123508);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(123508, 124438, 0, 0.0133609, 0, 1, 0, 3, 8, ''),
(123508, 132183, 0, 22, 0, 1, 0, 1, 1, ''),
(123508, 132185, 0, 3, 0, 1, 0, 1, 1, ''),
(123508, 132231, 0, 74, 0, 1, 0, 1, 1, ''),
(123508, 138781, 0, 0.290733, 0, 1, 0, 1, 1, ''),
(123508, 138782, 0, 0.0304629, 0, 1, 0, 1, 1, ''),
(123508, 140220, 0, 0.0299284, 0, 1, 0, 1, 1, ''),
(123508, 140221, 0, 0.0491682, 0, 1, 0, 1, 1, ''),
(123508, 140222, 0, 0.0876476, 0, 1, 0, 1, 1, ''),
(123508, 140225, 0, 0.0197742, 0, 1, 0, 1, 1, ''),
(123508, 140226, 0, 0.0181708, 0, 1, 0, 1, 1, ''),
(123508, 140227, 0, 0.247444, 0, 1, 0, 1, 1, ''),
(123508, 144330, 0, 0.0486337, 0, 1, 0, 1, 1, ''),
(123508, 144345, 0, 0.088182, 0, 1, 0, 1, 1, ''),
(123508, 151366, 0, 36, 1, 1, 0, 5, 5, ''),
(123508, 151566, 0, 0.0539781, 0, 1, 0, 1, 1, ''),
(123508, 152411, 0, 21, 1, 1, 0, 1, 1, ''),
(123508, 153202, 0, 0.115973, 0, 1, 0, 1, 1, ''),
(123508, 153248, 0, 0.124524, 0, 1, 0, 1, 1, '');


-- Table `creature_template`
UPDATE `creature_template` SET `faction` = 35, `npcflag` = 33554432, `BaseAttackTime` = 2800, `unit_flags` = 134217728, `type` = 9, `MovementType` = 2, `HealthModifier` = 130 WHERE (entry = 124987);

-- Creating a new SmartAI script for [Creature] ENTRY 127528 (name: Greater Invasion Point: Matron Folnuna)

-- Table creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 127528;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 127528);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(127528, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 62, 9295, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Greater Invasion Point: Matron Folnuna - On Spellclick - Teleport');

