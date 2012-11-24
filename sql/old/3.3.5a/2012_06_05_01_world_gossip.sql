-- Witch Doctor Mau'ari SAI
SET @ENTRY  := 10307;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,2,62,0,100,0,2703,2,0,0,85,16351,0,0,0,0,0,7,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - On Gossip Option 2 Select - Cast Spell'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Witch Doctor Mau''ari - On Gossip Option 2 Select - Close gossip');
-- Add some missing gossip for Witch Doctor Mau'ari
UPDATE `creature_template` SET `gossip_menu_id`=2703,`ScriptName`='' WHERE `entry`=10307;
DELETE FROM `gossip_menu` WHERE `entry` IN (2703,21320,21321);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (2703,3375),(2703,3377),(21320,3382),(21321,3383);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=2703 AND `id` IN (0,1,2);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(2703,0,0, 'How do I use the Cache of Mau''ari?',1,1,21320,0,0,0, ''),
(2703,1,0, 'What is E''ko?',1,1,21321,0,0,0, ''),
(2703,2,0, 'I''d like you to make me a new Cache of Mau''ari please',1,1,0,0,0,0, '');
-- Add conditions for gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=2703;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,2703,3377,0,8,975,0,0,0,0,'','Only show gossip text 3377 if player has completed quest 975');
-- Add conditions for gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2703;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,2703,2,0,8,975,0,0,0,0,'','Only show gossip option if player has completed quest 975'),
(15,2703,2,0,2,12384,1,1,1,0,'','Only show gossip option if player Does not have item 12384');
