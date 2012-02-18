-- [Q] The Dwarven Spy
SET @ENTRY := 15420;
SET @GOSSIP := 21310;

-- Waypoints
DELETE FROM `script_waypoint` WHERE `entry`=@ENTRY;
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,9294.78,-6682.51,22.42,'Prospector Anvilward'),
(@ENTRY,2,9298.27,-6667.99,22.42,'Prospector Anvilward'),
(@ENTRY,3,9309.63,-6658.84,22.42,'Prospector Anvilward'),
(@ENTRY,4,9304.43,-6649.31,26.46,'Prospector Anvilward'),
(@ENTRY,5,9298.83,-6648,28.61,'Prospector Anvilward'),
(@ENTRY,6,9291.06,-6653.46,31.83,'Prospector Anvilward'),
(@ENTRY,7,9289.08,-6660.17,31.83,'Prospector Anvilward');

-- Prospector Anvilward SAI
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='',`gossip_menu_id`=@GOSSIP WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP+1,0,0,0,53,0,@ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,'Prospector Anvilward - On Gossip Select - Start WP'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Prospector Anvilward - On Gossip Select - Start WP'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Anvilward - On Gossip Select - Remove npcflag'),
(@ENTRY,0,3,0,40,0,100,0,1,@ENTRY,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Prospector Anvilward - On WP 1 - Say Line 0'),
(@ENTRY,0,4,5,40,0,100,0,6,@ENTRY,0,0,54,2500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Anvilward - On WP 6 - Pause Path'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Prospector Anvilward - On WP 6 - Say Line 1'),
(@ENTRY,0,6,7,40,0,100,0,7,@ENTRY,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Anvilward - On WP 7 - Pause Path'),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,2,24,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prospector Anvilward - On WP 7 - Set Faction'),
(@ENTRY,0,8,0,1,0,100,1,10000,10000,24000,29000,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,"Prospector Anvilward - Out of Combat - Say Line 2");

-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Very well. Let's see what you have to show me, $N.",12,1,100,0,0,0,'Prospector Anvilward'),
(@ENTRY,1,0,"What manner of trick is this, $r? If you seek to ambush me, I warn you I will not go down quietly!",12,1,100,0,0,0,'Prospector Anvilward'),
(@ENTRY,2,0,"These arcane sanctums of yours are quite... interesting, Mr. Caidanis. I appreciate the information you have given me today.",12,0,100,1,0,0,'Prospector Anvilward');

-- This one was missing..
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP AND `text_id`=8239;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP,8239);
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP+1 AND `text_id`=8240;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP+1,8240);

-- Insert menu options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIP+0,@GOSSIP+1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@GOSSIP+0,0,0,"I need a moment of your time, sir.",1,1,@GOSSIP+1),
(@GOSSIP+1,0,0,"Why... yes, of course. I've something to show you right inside this building, Mr. Anvilward.",1,1,0);

-- Conditions for gossip menu of quest The Dwarven Spy
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP+0 AND `ConditionValue1`=8483;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP+0,0,0,9,8483,0,0,0,'',"Only show first gossip if player is on quest The Dwarven Spy");
