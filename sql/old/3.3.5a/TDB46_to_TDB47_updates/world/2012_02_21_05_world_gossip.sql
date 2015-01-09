-- SAI for Lothos Riftwaker
SET @ENTRY=14387;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Lothos Riftwaker - On Gossip Option select - close gossip'),
(@ENTRY,0,1,0,61,0,100,0,5750,0,0,0,62,409,0,0,0,0,0,7,0,0,0,1096,-467,-104.6,3.64,'Lothos Riftwaker - On Gossip Option select - teleport player');

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (5750);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(5750,0,0,'Teleport me to the Molten Core, Lothos.',1,1,0,0,0,0,'');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (5750);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,5750,0,0,0,8,7848,0,0,0,0,'','Show gossip option if player has quest 7848 completed');

-- SAI for Zamael Lunthistle
SET @ENTRY=8436;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,1285,0,0,0,26,3377,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zamael Lunthistle - On Gossip Option select - quest credit'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Zamael Lunthistle - On Gossip Option select - close gossip');

DELETE FROM `gossip_menu` WHERE `entry`=1285 AND `text_id`=1920;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1285,1920);
DELETE FROM `gossip_menu` WHERE `entry`=1286 AND `text_id`=1922;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1286,1922);
DELETE FROM `gossip_menu` WHERE `entry`=1287 AND `text_id`=1921;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1287,1921);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (1285,1286,1287);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(1285,0,0,'I wish to hear your tale.',1,1,1287,0,0,0,''),
(1286,0,0,'Let me think about it, Zamael.',1,1,1285,0,0,0,''),
(1287,0,0,'Please continue, Zamael.',1,1,1286,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (1285);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1285,0,0,0,9,3377,0,0,0,0,'','Show gossip option if player has quest 3377 but not complete');
