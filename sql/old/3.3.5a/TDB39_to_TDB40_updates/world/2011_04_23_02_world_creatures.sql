SET @GUID = 152261; -- Creatures
SET @EVENT = 9; -- Noblegarden

UPDATE `game_event` SET `start_time`='2011-04-24 00:02:00', `length`=11*24*60 WHERE `eventEntry`=@EVENT; -- 11 days length
DELETE FROM `game_event_creature_quest` WHERE `eventEntry`=@EVENT;

UPDATE `creature_template` SET `minlevel`=12,`maxlevel`=12 WHERE `entry` IN (32836,32837);
UPDATE `creature_template` SET `minlevel`=75,`maxlevel`=75 WHERE `entry` IN (32798,32799);

DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @GUID+00),(@EVENT, @GUID+01),
(@EVENT, @GUID+02),(@EVENT, @GUID+03),
(@EVENT, @GUID+04),(@EVENT, @GUID+05),
(@EVENT, @GUID+06),(@EVENT, @GUID+07),
(@EVENT, @GUID+08),(@EVENT, @GUID+09),
(@EVENT, @GUID+10),(@EVENT, @GUID+11),
(@EVENT, @GUID+12),(@EVENT, @GUID+13),
(@EVENT, @GUID+14),(@EVENT, @GUID+15);

DELETE FROM `creature` WHERE `id` IN (32798,32799,32836,32837);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+00,32798,0,1,1,0,0,2236.33,247.326,33.6595,2.84096,300,0,0,0,0,0,0,0,0,0), -- Spring Gatherer
(@GUID+01,32798,1,1,1,0,0,323.943,-4703.51,15.8903,4.29373,300,0,0,0,0,0,0,0,0,0), -- Spring Gatherer
(@GUID+02,32798,530,1,1,0,0,9495.4,-6841.51,16.986,0.807895,300,0,0,0,0,0,0,0,0,0), -- Spring Gatherer
(@GUID+03,32798,1,1,1,0,0,-2336.63,-355.656,-8.74798,5.58244,300,0,0,0,0,0,0,0,0,0), -- Spring Gatherer
(@GUID+04,32799,0,1,1,0,0,-5596.99,-506.959,401.155,2.73583,300,0,0,0,0,0,0,0,0,0), -- Spring Collector
(@GUID+05,32799,1,1,1,0,0,9837.29,969.65,1308.21,0.383221,300,0,0,0,0,0,0,0,0,0), -- Spring Collector
(@GUID+06,32799,0,1,1,0,0,-9453.86,44.7409,56.7139,1.45433,300,0,0,0,0,0,0,0,0,0), -- Spring Collector
(@GUID+07,32799,530,1,1,0,0,-4150.79,-12492.3,44.6553,3.75029,300,0,0,0,0,0,0,0,0,0), -- Spring Collector
(@GUID+08,32836,0,1,1,0,0,-5601.03,-512.86,401.492,1.56166,300,0,0,0,0,0,0,0,0,0), -- Noblegarden Vendor
(@GUID+09,32836,1,1,1,0,0,9839.27,961.92,1308.29,0.271694,300,0,0,0,0,0,0,0,0,0), -- Noblegarden Vendor
(@GUID+10,32836,0,1,1,0,0,-9451.26,42.2403,57.173,0.641447,300,0,0,0,0,0,0,0,0,0), -- Noblegarden Vendor
(@GUID+11,32836,530,1,1,0,0,-4155.63,-12486.1,44.7758,3.96234,300,0,0,0,0,0,0,0,0,0), -- Noblegarden Vendor
(@GUID+12,32837,0,1,1,0,0,2244.84,262.273,34.148,2.9156,300,0,0,0,0,0,0,0,0,0), -- Noblegarden Merchant
(@GUID+13,32837,1,1,1,0,0,333.091,-4707.97,15.6644,4.12487,300,0,0,0,0,0,0,0,0,0), -- Noblegarden Merchant
(@GUID+14,32837,530,1,1,0,0,9487.64,-6833.65,16.986,0.819677,300,0,0,0,0,0,0,0,0,0), -- Noblegarden Merchant
(@GUID+15,32837,1,1,1,0,0,-2343.08,-364.618,-8.4062,5.82199,300,0,0,0,0,0,0,0,0,0); -- Noblegarden Merchant
