-- Fix some path errors
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=66949;

DELETE FROM `creature_addon` WHERE `guid`=114330;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES
(114330,1143300,1);

UPDATE `creature_addon` SET `path_id`=2034560 WHERE `guid`=203456;
UPDATE `waypoint_data` SET `id`=2034560 WHERE `id`=203591;

-- Windrock hunter removed in rev 2.2.0
DELETE FROM `creature` WHERE `id`=18996;

-- Delete existing unblizzlike spawns
DELETE FROM `creature` WHERE `id` IN (29064,29063,29062,29098,29096,29097);
-- Delete addon data from previous mentioned wrong spanws
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 127316 AND 127337;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 127340 AND 127375;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 127293 AND 127315;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 127272 AND 127292;
DELETE FROM `creature_addon` WHERE `guid`=12246;

DELETE FROM `gameobject` WHERE `guid` IN (17454,17455);
