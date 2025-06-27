-- Missing World Trigger, spawns only in heroic. Or was added in Cata, no WotLK sniffs from heroic
-- Purpose unknown. Since trigger creatures involved in Anzu summoning event not exists in all sniffs and probably are summoned or were
-- removed, probably this one is related to encounter and not to summoning event
DELETE FROM `creature` WHERE `guid` = 131116 AND `id` = 22515;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(131116, 22515, 556, 2, 1, 0, -91.6134567260742187, 288.205718994140625, 26.56649971008300781, 1.29154360294342041, 300, 0, 0, 15595);

-- Anzu, sniffed position
-- z is still not correct because in videos Anzu is summoned slightly above ground, anyway we can't get correct position anymore
UPDATE `smart_scripts` SET `target_x` = -89.2040634155273437, `target_y` = 287.973602294921875, `target_z` = 26.56649971008300781, `target_o` = 3.001966238021850585 WHERE `entryorguid` = 2305700 AND `source_type` = 9 AND `id` = 15;

UPDATE `creature_model_info` SET `BoundingRadius` = 0.6, `CombatReach` = 2 WHERE `DisplayID` = 21492;

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 23035;
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` IN (23134,23135,23136);
UPDATE `creature_template` SET `speed_run` = 3.85714 WHERE `entry` = 23132;

DELETE FROM `creature_text` WHERE `CreatureID` IN (23134,23135,23136);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(23134,0,0,"%s returns to stone.",16,0,100,0,0,0,20980,3,"Hawk Spirit"),
(23135,0,0,"%s returns to stone.",16,0,100,0,0,0,20980,3,"Falcon Spirit"),
(23136,0,0,"%s returns to stone.",16,0,100,0,0,0,20980,3,"Eagle Spirit");

-- Default positions from all CreateObject2
UPDATE `creature` SET `position_x` = -25.1083, `position_y` = 95.7329, `position_z` = 0.0916533, `orientation` = 4.01758, `VerifiedBuild` = 11159 WHERE `guid` = 86751 AND `id` = 4076;
UPDATE `creature` SET `position_x` = 9.02388, `position_y` = 90.1725, `position_z` = 0.0312833, `orientation` = 0.703954, `VerifiedBuild` = 11159 WHERE `guid` = 86743 AND `id` = 4076;
UPDATE `creature` SET `position_x` = 46.6449, `position_y` = -1.34446, `position_z` = 0.0890683, `orientation` = 5.96064, `VerifiedBuild` = 11159 WHERE `guid` = 86742 AND `id` = 4076;
UPDATE `creature` SET `position_x` = 20.6933, `position_y` = 3.65365, `position_z` = 0.0883923, `orientation` = 0.367999, `VerifiedBuild` = 11159 WHERE `guid` = 84262 AND `id` = 2914;
UPDATE `creature` SET `position_x` = 47.2232, `position_y` = 29.827, `position_z` = 0.0908253, `orientation` = 0.925025, `VerifiedBuild` = 11159 WHERE `guid` = 86647 AND `id` = 2914;
UPDATE `creature` SET `position_x` = 53.9685, `position_y` = 83.8201, `position_z` = 0.234137, `orientation` = 0.645772, `VerifiedBuild` = 11159 WHERE `guid` = 83247 AND `id` = 19429;
UPDATE `creature` SET `position_x` = 40.0595, `position_y` = 19.5294, `position_z` = 0.0913553, `orientation` = 4.90438, `VerifiedBuild` = 11159 WHERE `guid` = 12819 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 37.1415, `position_y` = 20.3053, `position_z` = 0.0912323, `orientation` = 4.71238, `VerifiedBuild` = 11159 WHERE `guid` = 11747 AND `id` = 18323;
UPDATE `creature` SET `position_x` = 45.3656, `position_y` = 40.2488, `position_z` = 0.0908233, `orientation` = 4.30235, `VerifiedBuild` = 11159 WHERE `guid` = 83246 AND `id` = 19429;
UPDATE `creature` SET `position_x` = 41.7448, `position_y` = 38.9211, `position_z` = 0.0908153, `orientation` = 5.07581, `VerifiedBuild` = 11159 WHERE `guid` = 83248 AND `id` = 18318;
