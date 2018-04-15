-- Add gossip id to Frostborn Scout
UPDATE `creature_template` SET `gossip_menu_id`=9841 WHERE `entry`=29811;
-- Add Missing Gossip for Frostborn Scout
DELETE FROM `gossip_menu` WHERE `entry`=9841 AND `text_id`=13611;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9841,13611);
DELETE FROM `gossip_menu` WHERE `entry`=9842 AND `text_id`=13612;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9842,13612);
DELETE FROM `gossip_menu` WHERE `entry`=9843 AND `text_id`=13613;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9843,13613);
DELETE FROM `gossip_menu` WHERE `entry`=9844 AND `text_id`=13614;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9844,13614);
-- Add Any Missing Gossip Option for Frostborn Scout
DELETE FROM `gossip_menu_option` WHERE menu_id IN (9841,9842,9843);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(9841,0,0,"Are you okay? I''ve come TO take you back TO Frosthold IF you can stand.",1,1,9842,0,0,0,''),
(9842,0,0,"I''m sorry that I didn''t get here sooner. What happened?",1,1,9843,0,0,0,''),
(9843,0,0,"I''ll go get SOME help. Hang IN there.",1,1,9844,0,0,0,'');
-- Add Gossip option condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (9841);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9841,0,0,28,12864,0,0,1,0,'','Agnetta Tyrsdottar - Show gossip option only if quest "Missing scouts" is not complete');

-- Frostborn Scout SAI for Quest: Missing scouts
SET @ENTRY := 29647;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9843,0,0,0,15,12864,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Frostborn Scout - On Gossip Option Select - Give quest credit for Quest: Missing scouts');

-- Agnetta_Tyrsdottar SAI Quest: Is That Your Goblin?
SET @ENTRY := 30154;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,9874,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Agnetta_Tyrsdottar - On Gossip Option Select - Close Gossip Window'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,2,45,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Agnetta_Tyrsdottar - On Gossip Option Select - Set Faction'),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Agnetta_Tyrsdottar - On Gossip Option Select - Say 0'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Agnetta_Tyrsdottar - On Gossip Option Select - Attack Envoker'),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,2,2109,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Agnetta_Tyrsdottar - On Reset - Set faction');
