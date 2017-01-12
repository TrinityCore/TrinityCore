/*
-- Teacher and Kids in Stormwind - add Formation
DELETE FROM `creature_formations` WHERE `leaderGUID`=84028;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(84028, 84028, 0, 0, 2, 0, 0),
(84028, 87092, 3, 30, 2, 0, 0),
(84028, 87088, 3, 60, 2, 0, 0),
(84028, 87090, 3, 90, 2, 0, 0),
(84028, 87089, 3, 330, 2, 0, 0),
(84028, 87082, 3, 300, 2, 0, 0),
(84028, 87091, 3, 270, 2, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (87091,87092,87088,87090,87089,87082);
DELETE FROM `waypoint_data` WHERE `id` IN (870910,870920,870880,870900,870890,870820);
UPDATE `creature` SET `MovementType`=0, `SpawnDist`=0 WHERE `id` IN (3507,3510,3505,3511,3508,3512);
UPDATE `creature_template` SET `MovementType`=0 WHERE `entry` IN (3507,3510,3505,3511,3508,3512);
*/
