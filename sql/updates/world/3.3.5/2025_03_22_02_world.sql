-- Brokentoe (Area: The Ring of Blood - Difficulty: 0)
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=16/7 WHERE `entry`=18398;
UPDATE `smart_scripts` SET `target_x`=-709.04571533203125, `target_y`=7882.44091796875, `target_z`=46.05423355102539062, `target_o`=1.989675283432006835 WHERE `entryorguid`=1847100 AND `source_type`=9 AND `id`=1;
-- Murkblood Twin (Area: The Ring of Blood - Difficulty: 0)
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=12/7 WHERE `entry`=18399;
UPDATE `smart_scripts` SET `target_x`=-718.0357666015625, `target_y`=7871.61962890625, `target_z`=45.28351593017578125, `target_o`=1.570796370506286621 WHERE `entryorguid`=1847101 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `target_x`=-696.43133544921875, `target_y`=7883.2587890625, `target_z`=47.42765426635742187, `target_o`=2.478367567062377929 WHERE `entryorguid`=1847101 AND `source_type`=9 AND `id`=2;
-- Rokdar the Sundered Lord (Area: The Ring of Blood - Difficulty: 0)
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=8/7 WHERE `entry`=18400;
UPDATE `smart_scripts` SET `target_x`=-709.5670166015625, `target_y`=7882.85595703125, `target_z`=46.10964584350585937, `target_o`=1.902408838272094726 WHERE `entryorguid`=1847102 AND `source_type`=9 AND `id`=1;
-- Skra'gath (Area: The Ring of Blood - Difficulty: 0)
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=12/7 WHERE `entry`=18401;
UPDATE `smart_scripts` SET `target_x`=-708.91363525390625, `target_y`=7883.25634765625, `target_z`=46.19994354248046875, `target_o`=1.832595705986022949 WHERE `entryorguid`=1847103 AND `source_type`=9 AND `id`=1;
-- Warmaul Champion (Area: The Ring of Blood - Difficulty: 0)
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=14/7 WHERE `entry`=18402;
UPDATE `smart_scripts` SET `target_x`=-705.9747314453125, `target_y`=7866.71630859375, `target_z`=45.06111907958984375, `target_o`=1.570796370506286621 WHERE `entryorguid`=1847104 AND `source_type`=9 AND `id`=1;

-- Mogor (Area: Laughing Skull Ruins - Difficulty: 0)
UPDATE `creature_template` SET `speed_walk`=2.5/2.5, `speed_run`=14/7 WHERE `entry`=18069;
UPDATE `creature` SET `position_x`=-713.90032958984375, `position_y`=7929.8349609375, `position_z`=59.13791656494140625, `orientation`=4.607669353485107421, `VerifiedBuild`=59679 WHERE `guid`=48191 and `id`=18069;

UPDATE `waypoints` SET `position_x`=-713.90032958984375, `position_y`=7929.8349609375, `position_z`=59.13791656494140625 WHERE `entry`=1806900 AND `pointid`=1;
UPDATE `smart_scripts` SET `target_o`=4.607669353485107421 WHERE `entryorguid`=18069 AND `source_type`=0 AND `id`=23;

UPDATE `smart_scripts` SET `event_param1`=3, `comment`="Mogor - On Waypoint 3 Reached - Run Script" WHERE `entryorguid`=18069 AND `source_type`=0 AND `id`=10;
DELETE FROM `waypoints` WHERE `entry`=18069;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
(18069, 1, -720.218, 7914.135, 55.22982, NULL, 0, 'Mogor'),
(18069, 2, -720.4691, 7905.346, 50.42057, NULL, 0, 'Mogor'),
(18069, 3, -715.9375, 7896.43, 48.30074, NULL, 0, 'Mogor');
