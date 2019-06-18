-- 
UPDATE `creature` SET MovementType=1, spawndist=10 WHERE `guid` IN (79481, 79486);
DELETE FROM `creature` WHERE `guid` IN (71669,71670,84841,84842)  AND `id` IN (20868,20867);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(71669, 20868, 552, 0, 0, 3, 1, 0, 0, 254.91, -125.087, -10.1232, 2.89044, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(71670, 20868, 552, 0, 0, 3, 1, 0, 0, 266.335, -187.128, -10.1051, 4.02795, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(84841, 20868, 552, 0, 0, 3, 1, 0, 0, 244.258, -156.479, -10.104, 4.38315, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 0),
(84842, 20867, 552, 0, 0, 3, 1, 0, 0, 254.91, -125.087, -10.1232, 2.89044, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 0);

DELETE FROM `pool_template` WHERE `entry` IN (573,574,575);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(573, 1, "Death Watcher/Entropic Eye"),
(574, 1, "Death Watcher/Entropic Eye"),
(575, 1, "Death Watcher/Entropic Eye");

DELETE FROM `pool_creature` WHERE `pool_entry` IN (573,574,575);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(84841,573, 0, "Death Watcher/Entropic Eye"),
(79481,573, 0, "Death Watcher/Entropic Eye"),
(84842,574, 0, "Death Watcher/Entropic Eye"),
(71669,574, 0, "Death Watcher/Entropic Eye"),
(71670,575, 0, "Death Watcher/Entropic Eye"),
(79486,575, 0, "Death Watcher/Entropic Eye");
