-- Fix Quest A Choice of Allies
-- add quest starter A Choice of Allies
DELETE FROM `creature_queststarter` WHERE (`quest` = 50239) AND (`id` IN (126301));
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(126301, 50239);

-- add quest ender A Choice of Allies
DELETE FROM `creature_questender` WHERE (`quest` = 50239) AND (`id` IN (126301));
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(126301, 50239);

-- Add Objectives for quest A Choice of Allies
DELETE FROM `quest_objectives` WHERE (`QuestID` = 50239);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (411622, 50239, 2, 1, 0, 273855, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (411623, 50239, 2, 2, 1, 273853, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (411624, 50239, 2, 3, 2, 298865, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (411625, 50239, 2, 4, 3, 316736, 1, 0, 0, 0, NULL, 35662);
INSERT INTO `quest_objectives`(`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES (411626, 50239, 2, 5, 4, 339222, 1, 0, 0, 0, NULL, 35662);

-- Update gameobject for quest A Choice of Allies
UPDATE `gameobject_template` SET `size` = 0.5, `type` = 22 WHERE (`entry` = 316736);
UPDATE `gameobject_template` SET `type` = 22, `size` = 0.5 WHERE (`entry` = 339222);
UPDATE `gameobject_template` SET `Data0` = 0 WHERE (`entry` = 273855);
UPDATE `gameobject_template` SET `Data0` = 0 WHERE (`entry` = 273853);
UPDATE `gameobject_template` SET `Data0` = 0 WHERE (`entry` = 298865);

-- Spawn Gameobjects for quest A Choice of Allies 
DELETE FROM `gameobject` WHERE (`guid` = 4000000023287);
DELETE FROM `gameobject` WHERE (`guid` = 4000000023288);
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES (4000000023287, 316736, 0, 0, 0, '0', 0, 0, 0, -1, -8145.9, 813.306, 75.9667, 3.94896, -0, -0, -0.919619, 0.392811, 300, 255, 1, 0, '', 37623);
INSERT INTO `gameobject`(`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`, `VerifiedBuild`) VALUES (4000000023288, 339222, 0, 0, 0, '0', 0, 0, 0, -1, -8152.94, 829.162, 75.9667, 4.34165, -0, -0, -0.825319, 0.564666, 300, 255, 1, 0, '', 37623);
