-- SAI for Kalaran Windblade
SET @ENTRY=8479;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY*100 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- AI
(@ENTRY,0,0,1,62,0,100,0,1321,0,0,0,26,3441,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kalaran Windblade - On Gossip Option select - quest credit'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kalaran Windblade - On Gossip Option select - close gossip'),
(@ENTRY,0,2,3,62,0,100,0,1323,2,0,0,11,19797,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kalaran Windblade - On Gossip Option select - cast 19797'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kalaran Windblade - On Gossip Option select - close gossip'),
(@ENTRY,0,4,0,62,0,100,0,1323,3,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kalaran Windblade - On Gossip Option select - run script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kalaran Windblade - script - close gossip'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kalaran Windblade - script - remove npc flags'),
(@ENTRY*100,9,2,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kalaran Windblade - script - say 0'),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,1000,1000,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kalaran Windblade - script - emotestate usestanding'),
(@ENTRY*100,9,4,0,0,0,100,0,60000,60000,60000,60000,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kalaran Windblade - script - emotestate none'),
(@ENTRY*100,9,5,0,0,0,100,0,1000,1000,1000,1000,26,3453,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kalaran Windblade - script - give quest credit'),
(@ENTRY*100,9,6,0,0,0,100,0,1000,1000,1000,1000,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kalaran Windblade - script - add npc flags');
-- npc text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY,0,0,'Please be patient, $N',12,0,100,0,0,0,'Kalaran Windblade');
-- Gossip options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1321,1322,1323);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(1321,0,0,'Let me confer with my colleagues.',1,1,0,0,0,0,''),
(1322,0,0,'Continue please.',1,1,1321,0,0,0,''),
(1323,0,0,'Tell me what drives this vengeance?',1,1,1322,0,0,0,''),
(1323,2,0,'Kalaran, I have misplaced my torch. I require another.',1,1,0,0,0,0,''),
(1323,3,0,'Kalaran, please enchant the torch.',1,1,0,0,0,0,'');
-- Gossip option conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (1323);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1323,0,0,0,9,3441,0,0,0,0,'','Show gossip option if player has quest 3441 but not complete'),
(15,1323,2,0,0,8,3454,0,0,0,0,'','Show gossip option if player has quest 3441 complete'),
(15,1323,2,0,0,2,10515,0,1,0,0,'','Show gossip option if player does not have item 10515'),
(15,1323,3,0,0,9,3453,0,0,0,0,'','Show gossip option if player has quest 3453 but not complete');
