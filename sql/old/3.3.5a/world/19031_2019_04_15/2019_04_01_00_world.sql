-- 
UPDATE `creature` SET `position_z`=79.48 WHERE `guid` IN (110837,111476,111479,111477,111478); 
UPDATE `gameobject` SET `position_z`=79.48 WHERE `guid`=56602;
UPDATE `creature` SET `position_x`=1256.053, `position_y`=-6167.272, `position_z`=232.392,`orientation`=5.633913, `MovementType`=0, `spawndist`=0  WHERE `guid` IN (110931);
DELETE FROM `creature_template_addon` WHERE `entry` IN (23967,23711);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23967, 0, 0, 0, 1, 233, ""),
(23711, 0, 0, 0, 1, 233, "");

DELETE FROM `creature_addon` WHERE `guid` IN (110852,110860,110868,110871,110872,110898,110905,110914,110940);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(110852, 0, 0, 0, 1, 0, ""),
(110860, 0, 0, 0, 1, 0, ""),
(110868, 0, 0, 0, 1, 0, ""),
(110871, 0, 0, 0, 1, 0, ""),
(110872, 0, 0, 0, 1, 0, ""),
(110898, 0, 0, 0, 1, 0, ""),
(110905, 0, 0, 0, 1, 0, ""),
(110914, 0, 0, 0, 1, 0, ""),
(110940, 0, 0, 0, 1, 0, "");
