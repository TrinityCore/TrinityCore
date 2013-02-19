-- SAI for Unrestrained Dragonhawk
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=25236;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=25236 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25236,0,0,1,62,0,100,0,9143,0,0,0,11,45353,0,0,0,0,0,7,0,0,0,0,0,0,0,'Unrestrained Dragonhawk - On Gossip option select - cast "Quest - Sunwell Daily - Ship Bombing Run Return" on player'),
(25236,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Unrestrained Dragonhawk - On Gossip option select - Close Gossip');
-- Unrestrained Dragonhawk Gossip
UPDATE `creature_template` SET `gossip_menu_id`=9143 WHERE `entry`=25236;
-- Gossip_menu from UDB
DELETE FROM `gossip_menu` WHERE `entry`=9143;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9143,12371);
-- Gossip_menu_option Update from UDB
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9143;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9143,0,0, '<Ride the dragonhawk to Sun''s Reach.>',1,1,0,0,0,0, '');
-- Gossip option Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9143;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9143,0,0,9,11542,0,0,0,'','Show gossip option if player has quest 11542 but not complete'),
(15,9143,0,1,9,11543,0,0,0,'','Show gossip option if player has quest 11543 but not complete');
