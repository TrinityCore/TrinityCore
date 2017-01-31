-- Overseer Nuaar SAI
SET @ENTRY := 21981;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,8429,0,0,0,26,10682,0,0,0,0,0,7,0,0,0,0,0,0,0,"Overseer Nuaar - On Gossip Option - Complete quest 10682");

-- Add Conditions for Overseer Nuaar gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8429;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8429,0,0,0,9,0,10682,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 10682 is taken');

-- Add Conditions for Sai'kkal the Elder gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8616;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8616,0,0,0,9,0,10980,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 10980 is taken');

UPDATE `creature_template` SET `gossip_menu_id`=8616 WHERE `entry`=22932;
DELETE FROM `gossip_menu` WHERE (`entry`=8616 AND `text_id`=10794);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8616,10794);
DELETE FROM `gossip_menu` WHERE (`entry`=8617 AND `text_id`=10795);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8617,10795);
DELETE FROM `gossip_menu` WHERE (`entry`=8618 AND `text_id`=10796);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8618,10796);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8616,8617);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(8616,0,0, 'Yes... yes, it''s me.',1,1,8617,0,0,0, ''),
(8617,0,0, 'Yes elder. Tell me more of the book.',1,1,8618,0,0,0, '');
