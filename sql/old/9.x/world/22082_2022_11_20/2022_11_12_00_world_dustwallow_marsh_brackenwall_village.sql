SET @OGUID := 247489;

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=46366 WHERE `entry`=190085; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `faction`=1735 WHERE `entry`=190085; -- Candy Bucket

-- Quests
UPDATE `quest_offer_reward` SET `VerifiedBuild`=46366 WHERE `ID`=12383;

DELETE FROM `gameobject_queststarter` WHERE `id`=190085;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190085, 12383, 46366);

UPDATE `gameobject_questender` SET `VerifiedBuild`=46366 WHERE (`id`=190085 AND `quest`=12383);

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190085;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180407, 1, 15, 496, '0', 0, 0, -3169.844482421875, -2901.30712890625, 39.4384307861328125, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, 46366), -- G_Pumpkin_03 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+1, 180472, 1, 15, 496, '0', 0, 0, -3170.10498046875, -2909.896484375, 43.365447998046875, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 120, 255, 1, 46366), -- HangingSkullLight02 (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+2, 180523, 1, 15, 496, '0', 0, 0, -3166.025390625, -2903.937744140625, 35.84684371948242187, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 120, 255, 1, 46366), -- Apple Bob (Area: Brackenwall Village - Difficulty: 0)
(@OGUID+3, 190085, 1, 15, 496, '0', 0, 0, -3168.76220703125, -2905.763916015625, 35.33940887451171875, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 120, 255, 1, 46366); -- Candy Bucket (Area: Brackenwall Village - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3);
