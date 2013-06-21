-- Updates for Quest A Blade Fit For A Champion

UPDATE `creature_template` SET `ScriptName`= 'npc_lake_frog' WHERE `entry` IN (33211,33224);
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry` IN (33224);

-- Add option conditions for gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (10316);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10316,0,0,2,44981,1,1,1,0,'','Maiden of Ashwood Lake - Show gossip option if player does not have Ashwood Brand');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=33220;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(33220,0,0, 'Can it really be? Free after all these years?',12,0,100,1,0,0, 'Maiden of Ashwood Lake'),
(33220,1,0, 'And now, I must return to the waters of the lake.',12,0,100,2,0,0, 'Maiden of Ashwood Lake');

-- Add missing lake frog spawns
SET @GUID := 306080;
SET @POOL := 60003;

SET @GUID := 306080;
DELETE FROM `creature` WHERE `id`=33211;
INSERT INTO `creature` (`guid`,`id`,`map`,`zone`,`area`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES 
(@GUID+0,33211,571,0,0,1,1,0,0,3714.71313,-4303.6416,182.597778,0.5710628,120,5,0,1,0,1),
(@GUID+1,33211,571,0,0,1,1,0,0,3727.22876,-4303.32568,182.255157,0.8603498,120,5,0,1,0,1),
(@GUID+2,33211,571,0,0,1,1,0,0,3728.51538,-4303.354,182.132217,0.182852328,120,5,0,1,0,1),
(@GUID+3,33211,571,0,0,1,1,0,0,3743.80762,-4300.40234,181.845047,2.43378878,120,5,0,1,0,1),
(@GUID+4,33211,571,0,0,1,1,0,0,3745.317,-4298.76855,182.1726,3.83392715,120,5,0,1,0,1),
(@GUID+5,33211,571,0,0,1,1,0,0,3756.09375,-4303.11963,181.720047,4.65554,120,5,0,1,0,1),
(@GUID+6,33211,571,0,0,1,1,0,0,3771.87622,-4306.225,184.171371,1.57087767,120,5,0,1,0,1),
(@GUID+7,33211,571,0,0,1,1,0,0,3772.263,-4314.93066,180.231476,2.44895387,120,5,0,1,0,1),
(@GUID+8,33211,571,0,0,1,1,0,0,3772.70654,-4317.774,179.991028,4.85300732,120,5,0,1,0,1),
(@GUID+9,33211,571,0,0,1,1,0,0,3775.58887,-4305.576,185.450317,6.26560926,120,5,0,1,0,1),
(@GUID+10,33211,571,0,0,1,1,0,0,3777.857,-4321.65234,180.575317,6.11946154,120,5,0,1,0,1),
(@GUID+11,33211,571,0,0,1,1,0,0,3778.75439,-4320.91846,180.922287,5.89215,120,5,0,1,0,1),
(@GUID+12,33211,571,0,0,1,1,0,0,3789.02856,-4324.987,182.870514,0.5579872,120,5,0,1,0,1),
(@GUID+13,33211,571,0,0,1,1,0,0,3790.625,-4323.959,183.450317,2.364004,120,5,0,1,0,1),
(@GUID+14,33211,571,0,0,1,1,0,0,3792.34375,-4335.88965,180.584076,1.4193728,120,5,0,1,0,1),
(@GUID+15,33211,571,0,0,1,1,0,0,3792.57,-4335.01953,180.620331,4.567329,120,5,0,1,0,1),
(@GUID+16,33211,571,0,0,1,1,0,0,3800.04688,-4336.84375,182.426788,0.0697878,120,5,0,1,0,1),
(@GUID+17,33211,571,0,0,1,1,0,0,3801.10449,-4336.328,182.681076,2.52183533,120,5,0,1,0,1),
(@GUID+18,33211,571,0,0,1,1,0,0,3805.919,-4356.706,181.306076,4.68659163,120,5,0,1,0,1),
(@GUID+19,33211,571,0,0,1,1,0,0,3806.053,-4357.079,181.381226,2.51099515,120,5,0,1,0,1),
(@GUID+20,33211,571,0,0,1,1,0,0,3807.35254,-4346.9873,181.609863,2.069034,120,5,0,1,0,1),
(@GUID+21,33211,571,0,0,1,1,0,0,3810.154,-4348.294,182.556076,0.350148171,120,5,0,1,0,1),
(@GUID+22,33211,571,0,0,1,1,0,0,3815.82153,-4356.93164,182.881485,2.11018085,120,5,0,1,0,1),
(@GUID+23,33211,571,0,0,1,1,0,0,3816.023,-4362.761,181.806076,2.04126978,120,5,0,1,0,1),
(@GUID+24,33211,571,0,0,1,1,0,0,3816.47925,-4363.564,181.7469,4.345304,120,5,0,1,0,1),
(@GUID+25,33211,571,0,0,1,1,0,0,3816.487,-4356.44141,182.931076,0.0126206363,120,5,0,1,0,1),
(@GUID+26,33224,571,0,0,1,1,0,0,3819.22485,-4360.78125,182.311951,4.927386,120,5,0,1,0,1);

DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL, 1, 'Lake Frog (33224)');

DELETE FROM `pool_creature` WHERE `guid` BETWEEN @GUID AND @GUID+5;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@GUID+0, @POOL, 0, 'Lake Frog (33224) - Spawn 1'),
(@GUID+1, @POOL, 0, 'Lake Frog (33224) - Spawn 2'),
(@GUID+2, @POOL, 0, 'Lake Frog (33224) - Spawn 3'),
(@GUID+3, @POOL, 0, 'Lake Frog (33224) - Spawn 4'),
(@GUID+4, @POOL, 0, 'Lake Frog (33224) - Spawn 5'),
(@GUID+5, @POOL, 0, 'Lake Frog (33224) - Spawn 6');
