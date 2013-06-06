-- Fallen Hero of the Horde http://old.wowhead.com/npc=7572
DELETE FROM `gossip_menu` WHERE `entry`=840 AND `text_id`=1451;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (840,1451);
DELETE FROM `gossip_menu` WHERE `entry`=880 AND `text_id`=1452;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (880,1452);
DELETE FROM `gossip_menu` WHERE `entry`=881 AND `text_id`=1456;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (881,1456);
DELETE FROM `gossip_menu` WHERE `entry`=882 AND `text_id`=1455;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (882,1455);
DELETE FROM `gossip_menu` WHERE `entry`=883 AND `text_id`=1454;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (883,1454);
DELETE FROM `gossip_menu` WHERE `entry`=884 AND `text_id`=1453;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (884,1453);
-- Text Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=840 AND `SourceEntry` IN (1391);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,840,1391,0,8,2784,0,0,0,'','Show gossip text if player has quest 2801 or 2784 completed'), -- It's hard to imagine that so much death and despair could be confined to such a small area; yet beyond the swamp is a land plagued by chaos and destruction.$B$BWatch your step, adventurer. The Blasted Lands are the final resting place to far greater beings than you.
(14,840,1391,1,8,2801,0,0,0,'','Show gossip text if player has quest 2801 or 2784 completed'); -- It's hard to imagine that so much death and despair could be confined to such a small area; yet beyond the swamp is a land plagued by chaos and destruction.$B$BWatch your step, adventurer. The Blasted Lands are the final resting place to far greater beings than you.
-- Gossip option conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=840;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,840,0,0,9,2784,0,0,0,'','Show gossip option if player has quest 2784 but not complete'),
(15,840,1,0,9,2801,0,0,0,'','Show gossip option if player has quest 2801 but not complete'),
(15,840,2,0,9,2702,0,0,0,'','Show gossip option if player has quest 2702 but not complete');
-- Add Any Missing Gossip Option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=840 AND `id` IN (0,1);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (880,881,882,883,884) AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(840,0,0,"Please continue, Hero...",1,1,880,0,0,0,''),
(840,1,0,"Please continue, Hero...",1,1,880,0,0,0,''),
(880,0,0,"What could be worse than death?",1,1,884,0,0,0,''),
(881,0,0,"I shall.",1,1,0,0,0,0,''),
(882,0,0,"You can count on me, Hero.",1,1,881,0,0,0,''),
(883,0,0,"What are the stones of binding?",1,1,882,0,0,0,''),
(884,0,0,"Subordinates?",1,1,883,0,0,0,'');
-- Fallen Hero of the Horde SAI
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=7572;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=7572 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7572,0,0,1,62,0,100,0,881,0,0,0,26,2784,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fallen Hero of the Horde - On Gossip option select - complete quest 2784'),
(7572,0,1,2,61,0,100,0,0,0,0,0,26,2801,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fallen Hero of the Horde - On Gossip option select - complete quest 2801'),
(7572,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fallen Hero of the Horde - On Gossip option select - Close Gossip'),
(7572,0,3,4,62,0,100,0,840,2,0,0,12,7750,1,180000,0,0,0,8,0,0,0,-10630.3,-2987.05,28.96,4.54,'Fallen Hero of the Horde - On Gossip option select - Spawn Corporal Thund Splithoof'),
(7572,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Fallen Hero of the Horde - On Gossip option select - Close Gossip');
