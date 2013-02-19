-- Missing Love is in the Air NPCs
SET @GUID := 40481; -- need 8

DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+7 AND `id` IN (37887,38039,38040,38066,38325,38293);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,37887,0,1,1,0,0,-8864.01,635.646,96.0818,1.97249,300,0,0,42,0,0,2,0,8), -- Kwee Q. Peddlefeet <Crown Chemical Co.>
(@GUID+1,38039,1,1,1,0,0,9871.16,2488.28,1315.88,0.547356,300,0,0,42,0,0,2,0,8), -- Kwee Q. Peddlefeet <Crown Chemical Co.>
(@GUID+2,38040,530,1,1,0,0,-4010.12,-11846.9,0.1352,5.42082,300,0,0,42,0,0,2,0,8), -- Kwee Q. Peddlefeet <Crown Chemical Co.>
(@GUID+3,38040,0,1,1,0,0,-4915.43,-979.532,501.448,2.31443,300,0,0,42,0,0,2,0,8), -- Kwee Q. Peddlefeet <Crown Chemical Co.>
(@GUID+4,38066,0,1,1,0,0,-8867.86,652.647,97.0113,4.84704,300,0,0,42,0,0,2,0,8), -- Inspector Snip Snagglebolt
(@GUID+5,38325,0,1,1,0,0,-8881.19,669.006,105.834,0.696214,300,0,0,42,0,0,2,0,8), -- Marion Sutton
(@GUID+6,38293,0,1,1,0,0,-4932.9,-995.348,501.441,0.7201,300,0,0,42,0,0,2,0,8), -- Junior Inspector
(@GUID+7,38293,1,1,1,0,0,9885.37,2494.31,1315.92,3.01351,300,0,0,42,0,0,2,0,8); -- Junior Inspector

DELETE FROM `game_event_creature` WHERE `eventEntry`=8 AND `guid` BETWEEN @GUID AND @GUID+7;
INSERT INTO `game_event_creature` (`guid`,`eventEntry`) VALUES
(@GUID+0,8),
(@GUID+1,8),
(@GUID+2,8),
(@GUID+3,8),
(@GUID+4,8),
(@GUID+5,8),
(@GUID+6,8),
(@GUID+7,8);

-- Fixing an old SAI, by Aokromes, not related with above code
 UPDATE `smart_scripts` SET `event_param1`=56033 WHERE `entryorguid`=30146 and `event_param1` = 42837;
