DELETE FROM `creature_formations` WHERE `leaderGUID`=9203;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(9203, 9203, 0, 0, 2, 0, 0),
(9203, 9204, 3, 45, 2, 0, 0),
(9203, 9205, 3, 315, 2, 0, 0);

DELETE FROM `creature_addon` WHERE guid IN (9204,9205);
DELETE FROM `waypoint_data` WHERE id IN (92040,92050);
UPDATE `creature` SET `MovementType`=0, `SpawnDist`=0 WHERE `id` IN (2477,7170);
UPDATE `creature_template` SET `MovementType`=0 WHERE `entry` IN (2477,7170);
UPDATE `creature_template` SET `Speed_Walk`=1.47, `Speed_Run`=1.14286 WHERE `entry` IN (2478);
UPDATE `creature_template` SET `Speed_Walk`=1.48, `Speed_Run`=1.14286 WHERE `entry` IN (2477,7170);
