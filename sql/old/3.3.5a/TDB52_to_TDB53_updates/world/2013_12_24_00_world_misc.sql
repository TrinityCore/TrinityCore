-- Budd Nedreck SAI
SET @ENTRY := 23559;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,8775,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option - Close Gossip"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,42540,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keristrasza - On Gossip Option - Cast Zul'aman Disguise Creation");
-- Gossip Option for Budd Nedreck
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8775);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(8775,0,0, 'You gave the crew disguises?',1,1,0,0,0,0, '');
-- Add Conditions for Budd Nedreck gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8775;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8775,0,0,0,9,0,11166,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 11166 is taken');

-- Remove script for Rathis Tomber
UPDATE `creature_template` SET `AIName`='', `ScriptName`= '' WHERE `entry`=16224;
-- Gossip Option for Rathis Tomber
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7162);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(7162,0,0, 'I want to browse your goods.',3,128,0,0,0,0, '');
-- Add Conditions for Rathis Tomber gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7162;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,7162,0,0,0,8,0,9152,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 9152 is rewarded');
