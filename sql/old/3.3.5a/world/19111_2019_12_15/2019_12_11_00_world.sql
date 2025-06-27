-- 
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|768 WHERE `entry` IN (35984,35462,30281);
DELETE FROM `creature` WHERE `guid` IN (120675);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(120675, 35462, 571, 1, 1, 0, 1, 8479.33, 925.866, 547.417, 4.64556, 180, 0, 0, 0, 0, 0);
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (86812);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(86812,86812,0,0,515,0,0),
(86812,120675,3,270,515,0,0);
