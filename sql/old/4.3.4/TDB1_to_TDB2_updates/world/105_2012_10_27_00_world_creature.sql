-- Dragonbone Condor
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (106595,106596,106597,106598,106603,106604,106605,106607,106608,106626,106629,106631,106643,106646,106658,106663,106665,106668,106669,106675,106676,106679,106680,106681,106682,106683,106684,106685,106686,106687,106688,106692,106693,106696,106702,106703,106706,106722,106723,106724,106726,106727,106728,106733,106737,106741,106749,106755,106757,131072);
UPDATE `creature` SET `position_z`=72.130 WHERE `guid`=106631;
UPDATE `creature` SET `position_z`=72.902 WHERE `guid`=106675;
UPDATE `creature` SET `position_z`=69.505 WHERE `guid`=131072;
/* Carrion Condor
 * All these have unitfieldbyte1=1 which means sitting. Obviously that makes no sense when they are moving randomly within their spawndist. They should be sitting on the pillars in Borean Tundra.
 * There are some that are spawned very close to dead Taunka. From retail I know they should be flying directly on top of them not moving so I changed them, too. */
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `guid` IN (101804,101805,101806,101807,101808,101809,101810,101814,101815,101818,101819,101820,101823,101824,101825,101832,101834,101836,101837,101838,101839,101842,101845,101849,101850,101856,101859,101860,101862,101866,101872,101876,101877,101890,101921,101923);
-- Courier Lanson: The npc should be sleeping on the bed instead of just standing there.
DELETE FROM `creature_template_addon` WHERE `entry`=27060;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(27060,0,0,3,0,0,'');
