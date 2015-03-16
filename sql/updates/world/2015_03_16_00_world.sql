-- 
-- Legacki SAI
SET @ENTRY := 10978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,17166,0,0,0,80,1097800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Spellhit 'Release Umi's Yeti' - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,15,10978,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Legacki - On Waypoint 15 Reached - Run Script");

-- Actionlist SAI
SET @ENTRY := 1097800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,53,1,10978,0,0,0,2,1,0,0,0,0,0,0,0,"On Script - Start Waypoint"),
(@ENTRY,9,2,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

-- Actionlist SAI
SET @ENTRY := 1097801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 2"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 3"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 4");

DELETE FROM `creature_text` WHERE `entry`=10978;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10978, 0, 0, '%s jumps in fright!', 16, 0, 100, 0, 0, 0, 6301, 0, 'Legacki'),
(10978, 1, 0, 'Ahhhhh!!!', 12, 0, 100, 0, 0, 0, 6302, 0, 'Legacki'),
(10978, 2, 0, 'You big meanie! Who put you up to this?', 12, 0, 100, 0, 0, 0, 6303, 0, 'Legacki'),
(10978, 3, 0, 'It was Umi, wasn''t it?! She''s always playing jokes on me, and now she''s got you in on it too!', 12, 0, 100, 0, 0, 0, 6304, 0, 'Legacki'),
(10978, 4, 0, '%s sighs.', 16, 0, 100, 0, 0, 0, 6305, 0, 'Legacki');

-- Umi's Mechanical Yeti SAI
SET @ENTRY := 10980;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,29,5,10,0,0,0,0,19,10978,10,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Start Follow Closest Creature 'Legacki'"),
(@ENTRY,0,1,3,61,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Say Line 0"),
(@ENTRY,0,2,0,52,0,100,0,0,10980,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umi's Mechanical Yeti - On Text 0 Over - Say Line 1"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umi's Mechanical Yeti - On Just Summoned - Despawn In 30000 ms");

DELETE FROM `creature_text` WHERE `entry`=10980;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10980, 0, 0, '%s marches around, roaring and making a ruckus.', 16, 0, 100, 0, 0, 0, 6327, 0, 'Umi\'s Mechanical Yeti'),
(10980, 1, 0, 'RAAAAAAAR!', 12, 0, 100, 0, 0, 0, 6329, 0, 'Umi\'s Mechanical Yeti');

DELETE FROM `waypoints` WHERE `entry`=10978;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(10978, 1,6713.694,-4682.374,721.6163, 'Legacki'),
(10978, 2,6731.523,-4675.635,721.2076, 'Legacki'),
(10978, 3,6736.806,-4672.955,721.9132, 'Legacki'),
(10978, 4,6749.889,-4662.13,725.0011, 'Legacki'),
(10978, 5,6750.157,-4661.562,724.9875, 'Legacki'),
(10978, 6,6732.859,-4641.781,722.8784, 'Legacki'),
(10978, 7,6727.719,-4641.233,721.6862, 'Legacki'),
(10978, 8,6715.982,-4643.644,721.1971, 'Legacki'),
(10978, 9,6719.307,-4652.817,721.231, 'Legacki'),
(10978, 10,6715.004,-4685.518,721.466, 'Legacki'),
(10978, 11,6718.75,-4705.675,721.9097, 'Legacki'),
(10978, 12,6712.263,-4717.947,721.5077, 'Legacki'),
(10978, 13,6701.636,-4714.284,721.6529, 'Legacki'),
(10978, 14,6701.108,-4695.846,722.3613, 'Legacki'),
(10978, 15,6705.608,-4686.181,721.9736, 'Legacki');
