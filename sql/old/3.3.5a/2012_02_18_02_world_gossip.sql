-- Gossip for Lore Keeper of Norgannon "Uldaman" for quest 2278 "The Platinum Discs"
UPDATE `creature_template` SET `gossip_menu_id`=562 WHERE `entry`=7172;

-- SAI for Lore Keeper of Norgannon
SET @ENTRY := 7172;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,576,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Lore Keeper of Norgannon - On gossip option select - close gossip'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,26,2278,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Lore Keeper of Norgannon - On gossip option select - give quest credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=562 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,562,0,0,9,2278,0,0,0,'','Show gossip option if player has quest 2278 but not complete');

DELETE FROM `gossip_menu` WHERE `entry` BETWEEN 561 AND 576;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(561,1080),
(562,1079),
(563,1081),
(564,1082),
(565,1083),
(566,1084),
(567,1085),
(568,1086),
(569,1087),
(570,1088),
(571,1089),
(572,1090),
(573,1091),
(574,1092),
(575,1093),
(576,1094);

DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN 561 AND 576;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`)VALUES
(561,0,0,'What is a "subterranean being matrix"?',1,1,563,0,0,0,''),
(562,0,0,'Who are the Earthen?',1,1,561,0,0,0,''),
(563,0,0,'What are the anomalies you speak of?',1,1,564,0,0,0,''),
(564,0,0,'What is a "resilient foundation of construction"?',1,1,565,0,0,0,''),
(565,0,0,'So... the Earthen were made out of stone?',1,1,566,0,0,0,''),
(566,0,0,'Anything else I should know about the Earthen?',1,1,567,0,0,0,''),
(567,0,0,'I think I understand the Creators'' design intent for the Earthen now.  What are the Earthen''s anomalies that you spoke of earlier?',1,1,568,0,0,0,''),
(568,0,0,'What high-stress environments would cause the Earthen to destabilize?',1,1,569,0,0,0,''),
(569,0,0,'What happens when the Earthen destabilize?',1,1,570,0,0,0,''),
(570,0,0,'Troggs?!  Are the troggs you mention the same as the ones in the world today?',1,1,571,0,0,0,''),
(571,0,0,'You mentioned two results when the Earthen destabilize.  What is the second?',1,1,572,0,0,0,''),
(572,0,0,'Dwarves!!!  Now you''re telling me that dwarves originally came from the Earthen?!',1,1,573,0,0,0,''),
(573,0,0,'These dwarves are the same ones today, yes?  Do dwarves maintain any other links to the Earthen?',1,1,574,0,0,0,''),
(574,0,0,'Who are the Creators?',1,1,575,0,0,0,''),
(575,0,0,'This is a lot to think about.',1,1,576,0,0,0,''),
(576,0,0,'I will access the discs now.',1,1,0,0,0,0,'');
