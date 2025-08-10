SET @OGUID := 246817;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=190050; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=190050; -- Candy Bucket

-- Quests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=12347;

DELETE FROM `gameobject_queststarter` WHERE `id`=190050;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190050, 12347, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=190050 AND `quest`=12347);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190050;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180407, 1, 406, 467, '0', 0, 0, 2710.922119140625, 1510.6875, 238.1061553955078125, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Stonetalon Peak - Difficulty: 0)
(@OGUID+1, 180523, 1, 406, 467, '0', 0, 0, 2725.38330078125, 1513.48046875, 237.3129425048828125, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 120, 255, 1, 46366), -- Apple Bob (Area: Stonetalon Peak - Difficulty: 0)
(@OGUID+2, 190050, 1, 406, 467, '0', 0, 0, 2708.419189453125, 1511.0125732421875, 236.814239501953125, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 120, 255, 1, 46366); -- Candy Bucket (Area: Stonetalon Peak - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2);
