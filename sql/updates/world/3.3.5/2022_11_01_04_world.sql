-- Darrok and Gordun
UPDATE `smart_scripts` SET `event_param1`=9528 WHERE `entryorguid`=27425 AND `source_type`=0 AND `id`=0;
SET @ENTRY  := 27414;
SET @GOSSIP := 9531;
UPDATE `creature_template` SET `gossip_menu_id`= @GOSSIP WHERE `entry`=@ENTRY;
DELETE FROM `gossip_menu` WHERE `MenuID` = 21251;
DELETE FROM `gossip_menu_option` WHERE `MenuId`=@GOSSIP AND `OptionId`=0;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES
(@GOSSIP,0,0, 'Yes, I am ready to travel to Venture Bay!',26605,1,1);
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Gordun - On gossip option select - Close gossip'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,134,48622,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Gordun - On gossip option select - Cast alliance Log Ride 01 Begin on player'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,134,48621,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Gordun - On gossip option select - Cast Log Ride Horde 00 on player');
