-- [QUEST] A Rough Ride (12536)
-- NPC entry 28298 (Captive Crocolisk)
SET @ENTRY := 28298;
SET @GOSSIP := 9674;
SET @TEXT_ID := 13120;
UPDATE `creature_template` SET `gossip_menu_id`=@GOSSIP,`npcflag`=npcflag|1,`VehicleId`=0 WHERE `entry`=@ENTRY;
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP;
INSERT INTO `gossip_menu` (`entry`,`text_id`)
VALUES (@GOSSIP,@TEXT_ID);
-- Added condition so player can only select it once he has the quest
SET @GOSSIP_ENTRY := 9674;
SET @QUEST := 12536;
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP_ENTRY AND `SourceTypeOrReferenceId`=15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP_ENTRY,0,0,9,@QUEST,0,0,0,0, 'Only show gossip 9674 when quest 12536 is added');
-- Add missing gossip
SET @GOSSIP := 9674;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9674 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES 
(@GOSSIP,0,0,"You look safe enough... let's do this.",1,1,0,0,0,0, '');
-- [SAI] On gossip select - mount and waypoint
SET @ENTRY := 28298;
SET @GOSSIP := 9674;
SET @SPELL := 51258;
SET @ENTRY_MOUNT := 28308;
SET @MODELID_MOUNT := 25107;
SET @QUEST := 12536;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@ENTRY,@ENTRY_MOUNT);
UPDATE `creature_template` SET `VehicleId`=115 WHERE `entry`=@ENTRY_MOUNT;
UPDATE `creature_template` SET `InhabitType`=3 WHERE `entry`=@ENTRY_MOUNT;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|512|256 WHERE `entry`=@ENTRY_MOUNT;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY_MOUNT) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY_MOUNT*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,@GOSSIP,0,0,0,11,@SPELL,0,0,0,0,0,7,0,0,0,0,0,0,0, 'On gossip select - cast spell 51258 - Captive Crocolisk'),
(@ENTRY_MOUNT,0,1,0,54,0,100,0,0,0,0,0,80,@ENTRY_MOUNT*100,0,2,0,0,0,1,0,0,0,0,0,0,0, 'On summon - run script - Captive Crocolisk'),
(@ENTRY_MOUNT*100,9,1,0,0,0,100,0,0,0,0,0,53,1,@ENTRY_MOUNT,0,@QUEST,0,1,1,0,0,0,0,0,0,0, 'Start wp - Captive Crocolisk'),
(@ENTRY_MOUNT,0,2,3,58,0,100,0,47,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'on wp end - despawn - Captive Crocolisk'),
(@ENTRY_MOUNT,0,3,0,61,0,100,0,@ENTRY_MOUNT,0,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0,0,0,0, 'on despawn - call area explored of event happens');
-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY_MOUNT;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY_MOUNT,1,5268.226,4425.439,-95.55899, 'Captive Crocolisk'),
(@ENTRY_MOUNT,2,5249.557,4405.892,-96.04365, 'Captive Crocolisk'),
(@ENTRY_MOUNT,3,5266.678,4365.464,-98.19455, 'Captive Crocolisk'),
(@ENTRY_MOUNT,4,5289.138,4366.553,-102.234, 'Captive Crocolisk'),
(@ENTRY_MOUNT,5,5330.018,4363.27,-121.0311, 'Captive Crocolisk'),
(@ENTRY_MOUNT,6,5349.229,4341.059,-134.0126, 'Captive Crocolisk'),
(@ENTRY_MOUNT,7,5268.226,4425.439,-95.55899, 'Captive Crocolisk'),
(@ENTRY_MOUNT,8,5249.557,4405.892,-96.04365, 'Captive Crocolisk'),
(@ENTRY_MOUNT,9,5266.678,4365.464,-98.19455, 'Captive Crocolisk'),
(@ENTRY_MOUNT,10,5289.138,4366.553,-102.234, 'Captive Crocolisk'),
(@ENTRY_MOUNT,11,5330.018,4363.27,-121.0311, 'Captive Crocolisk'),
(@ENTRY_MOUNT,12,5349.229,4341.059,-134.0126, 'Captive Crocolisk'),
(@ENTRY_MOUNT,13,5365.038,4333.716,-141.5817, 'Captive Crocolisk'),
(@ENTRY_MOUNT,14,5405.443,4307.841,-142.03, 'Captive Crocolisk'),
(@ENTRY_MOUNT,15,5434.999,4305.659,-136.4706, 'Captive Crocolisk'),
(@ENTRY_MOUNT,16,5464.708,4302.066,-133.1981, 'Captive Crocolisk'),
(@ENTRY_MOUNT,17,5490.555,4294.395,-127.5203, 'Captive Crocolisk'),
(@ENTRY_MOUNT,18,5503.808,4269.717,-110.3168, 'Captive Crocolisk'),
(@ENTRY_MOUNT,19,5518.324,4255.308,-103.0638, 'Captive Crocolisk'),
(@ENTRY_MOUNT,20,5540.53,4259.77,-102.3979, 'Captive Crocolisk'),
(@ENTRY_MOUNT,21,5564.194,4263.45,-102.7574, 'Captive Crocolisk'),
(@ENTRY_MOUNT,22,5585.45,4261.137,-99.54807, 'Captive Crocolisk'),
(@ENTRY_MOUNT,23,5609.614,4259.657,-98.87333, 'Captive Crocolisk'),
(@ENTRY_MOUNT,24,5633.434,4259.228,-98.53442, 'Captive Crocolisk'),
(@ENTRY_MOUNT,25,5681.639,4266.31,-99.26748, 'Captive Crocolisk'),
(@ENTRY_MOUNT,26,5708.126,4273.348,-102.9183, 'Captive Crocolisk'),
(@ENTRY_MOUNT,27,5748.732,4284.135,-112.0557, 'Captive Crocolisk'),
(@ENTRY_MOUNT,28,5839.82,4368.61,-112.0805, 'Captive Crocolisk'),
(@ENTRY_MOUNT,29,5865.922,4371.208,-105.5544, 'Captive Crocolisk'),
(@ENTRY_MOUNT,30,5897.276,4408.44,-95.25065, 'Captive Crocolisk'),
(@ENTRY_MOUNT,31,5925.311,4440.624,-94.77592, 'Captive Crocolisk'),
(@ENTRY_MOUNT,32,5953.005,4476.29,-94.3763, 'Captive Crocolisk'),
(@ENTRY_MOUNT,33,5964.229,4503.729,-92.81553, 'Captive Crocolisk'),
(@ENTRY_MOUNT,34,5960.583,4546.558,-95.65462, 'Captive Crocolisk'),
(@ENTRY_MOUNT,35,5965.167,4579.141,-97.39779, 'Captive Crocolisk'),
(@ENTRY_MOUNT,36,5969.295,4613.739,-98.05751, 'Captive Crocolisk'),
(@ENTRY_MOUNT,37,5975.809,4659.289,-99.27143, 'Captive Crocolisk'),
(@ENTRY_MOUNT,38,5992.961,4699.554,-99.30317, 'Captive Crocolisk'),
(@ENTRY_MOUNT,39,6015.139,4743.752,-97.52377, 'Captive Crocolisk'),
(@ENTRY_MOUNT,40,6035.183,4788.787,-94.66938, 'Captive Crocolisk'),
(@ENTRY_MOUNT,41,6064.951,4827.502,-94.54885, 'Captive Crocolisk'),
(@ENTRY_MOUNT,42,6065.57,4870.553,-94.47726, 'Captive Crocolisk'),
(@ENTRY_MOUNT,43,6096.612,4885.741,-94.44479, 'Captive Crocolisk'),
(@ENTRY_MOUNT,44,6120.387,4902.048,-95.06882, 'Captive Crocolisk'),
(@ENTRY_MOUNT,45,6139.616,4913.349,-94.8635, 'Captive Crocolisk'),
(@ENTRY_MOUNT,46,6139.616,4913.349,-94.93861, 'Captive Crocolisk'),
(@ENTRY_MOUNT,47,6139.616,4913.349,-94.93861, 'Captive Crocolisk');
-- Spawn Zepik
SET @GUID := 40267;
DELETE FROM `creature` WHERE `id`=28216;
INSERT INTO `creature` VALUES
(@GUID,28216,571,1,1,0,0,6147.37,4917.29,-94.094,3.42155,300,0,0,42,0,0,0,0,0);
