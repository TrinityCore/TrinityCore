-- 
UPDATE `creature_template` SET `npcflag`=1048577 WHERE `entry` IN (34978,34987,34985,34983);
DELETE FROM `battlemaster_entry` WHERE `entry` IN (34978,34987,34985,34983);
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES
(34978,32),(34987,32),(34985,32),(34983,32);

DELETE FROM `creature` WHERE `guid` IN (86711,86723,86800,86801,86802,86803,86804);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86711, 34987, 530, 1, 1, 0, 1, -3998.37, -11326, -120.91, 4.72984, 300, 0, 0, 3874500, 8908, 0),
(86723, 34985, 0, 1, 1, 0, 1, 1333.51, 326.417, -63.6327, 3.33358, 300, 0, 0, 521300, 448950, 0),
(86800, 34983, 0, 1, 1, 0, 1, 1329.95, 341.604, -63.6265, 3.52556, 300, 0, 0, 651650, 0, 0),
(86801, 28209, 230, 1, 1, 0, 1, 849.49, -179.317, -49.671, 4.10152, 180, 0, 0, 2215, 0, 0),
(86802, 28210, 230, 1, 1, 0, 1, 845.881, -182.203, -49.6705, 1.18682, 180, 0, 0, 2215, 0, 0),
(86803, 28206, 230, 1, 1, 0, 0, 847.823, -181.144, -49.6707, 1.85005, 180, 0, 0, 42, 0, 0),
(86804, 29145, 530, 1, 1, 0, 0, 2970.77, 3750.62, 144.341, 4.9631, 180, 0, 0, 6986, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (28209,28210);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `emote`) VALUES
(28209, 1, 133),
(28210, 1, 133);
