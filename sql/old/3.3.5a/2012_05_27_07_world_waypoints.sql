-- Fix pathing for Thiassi the Lightning Bringer
DELETE FROM `creature_addon` WHERE `guid`=106554;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`) VALUES (106554,1065540,1);

-- bio's screwed up movement for rares. Fix for some
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id` IN (32400,32417,32422,32429);
UPDATE `creature_addon` SET `path_id`=2026020 WHERE `guid`=202602;
UPDATE `waypoint_data` SET `id`=2026020 WHERE `id`=2500060;
