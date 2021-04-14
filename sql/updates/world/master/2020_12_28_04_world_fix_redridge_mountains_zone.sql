-- Redridge mountain fix

DELETE FROM `quest_poi` WHERE `QuestID` = '26505'; 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26505, 0, 0, -1, 0, 0, 0, 5327, 0, 1, 0, 0, 0, 0, 35662); 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26505, 0, 1, 0, 252470, 58890, 0, 69, 0, 1, 0, 0, 0, 0, 35662); 
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26505'; 
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26505, 0, 0, -9620, -1872, 24330);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26505, 1, 0, -9219, -2222, 24330);

--
-- NPC 43248 was invisble (not anymore :P)
DELETE FROM creature_template_addon WHERE entry = 43248;

-- 
DELETE FROM `quest_poi` WHERE `QuestID` = '26586';
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26586, 0, 0, -1, 0, 0, 0, 36, 0, 1, 0, 0, 0, 0, 24330);
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26586';
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26586, 0, 0, -9233, -2700, 24330);

-- NPC ID 8962 is not a quest starter, she is quest ender :P
DELETE FROM creature_queststarter WHERE id = '8962';

-- DELETE MULTIPLIED MUDS
DELETE FROM `gameobject` WHERE `guid` IN (884, 5635, 2736);

-- REMOVE DUPLCIATE SPAWN OF RARE CREATURE
DELETE FROM creature WHERE guid = 52575;

-- SET QUEST 26512 TO AUTOC
UPDATE `quest_template` SET `QuestType` = '0' WHERE `ID` = '26512';

DELETE FROM `quest_poi` WHERE `QuestID` = '26607'; 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26607, 0, 0, -1, 0, 0, 0, 49, 0, 1, 0, 0, 0, 0, 35662); 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26607, 0, 1, 0, 267653, 59061, 0, 49, 0, 1, 0, 0, 0, 0, 35662); 
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26607'; 
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26607, 1, 0, -9202, -2154, 35662);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26607, 0, 0, -9212, -2215, 35662);
--

DELETE FROM `quest_poi` WHERE `QuestID` = '26640'; 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26640, 0, 0, -1, 0, 0, 0, 49, 0, 1, 0, 0, 0, 0, 35662); 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26640, 0, 1, 0, 253692, 59157, 0, 49, 0, 1, 0, 0, 0, 0, 35662); 
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26640'; 
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26640, 1, 0, -9463, -2829, 35662);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26640, 0, 0, -9676, -2842, 35662);

-- Quest needs to be rescripted
UPDATE `quest_template` SET `QuestType` = '0' WHERE `ID` = '26651';

-- DELETE BUGGED CHED OBJECT ID 2850 it gives all loot
DELETE FROM `gameobject` WHERE `id` = '2850';

--
DELETE FROM `quest_poi` WHERE `QuestID` = '26714'; 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26714, 0, 0, -1, 0, 0, 0, 49, 0, 1, 0, 0, 0, 0, 35662); 
INSERT INTO `quest_poi`(`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES (26714, 0, 1, 0, 267188, 43496, 0, 49, 0, 1, 0, 0, 0, 0, 35662); 
DELETE FROM `quest_poi_points` WHERE `QuestID` = '26714'; 
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26714, 0, 0, -9142, -3037, 35662);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26714, 1, 0, -9474, -2977, 35662);
INSERT INTO `quest_poi_points`(`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES (26714, 2, 0, -9142, -3037, 35662);

-- add missing npc
DELETE FROM `creature` WHERE `guid` = '3530203330003068';
DELETE FROM `creature_addon` WHERE `guid` = '3530203330003068';
INSERT INTO `creature`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES (3530203330003068, 43733, 0, 0, 0, '0', 0, 0, 0, -1, 0, 0, -9142.3, -3037.48, 108.713, 1.86589, 300, 0, 0, 1090, 0, 0, 0, 0, 0, 0, 0, '', 0);
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES (3530203330003068, 0, 0, 0, 0, 0, 0, 0, 0, 0, '130432');

-- THE END :P
