--
-- Fix up some errors in Vekniss Hive Crawler Entry: 15240 pathing
UPDATE `creature` SET `position_x`=-8259.721,`position_y`=1343.373,`position_z`=-84.4428 WHERE `guid`=87942;
UPDATE `creature` SET `position_x`=-8524.316,`position_y`=1389.612,`position_z`=-57.2656 WHERE `guid`=87944;
DELETE FROM `creature_addon` WHERE `guid` IN (87940,87942,87944);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(87940,879390,0,0,1,0, ''),(87942,879410,0,0,1,0, ''),(87944,879430,0,0,1,0, '');
