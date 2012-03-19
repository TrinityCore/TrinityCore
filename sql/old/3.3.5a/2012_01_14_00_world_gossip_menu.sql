-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9500,9502,9503,9504,9505,9576) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9576,0,0, 'I''d like to use the stables.',14,4194304,0,0,0,0, ''),
(9500,0,0, 'You''re free to go Orsonn, but first tell me what''s wrong with the furbolg.',1,1,9502,0,0,0, ''),
(9502,0,0, 'What happened then?',1,1,9503,0,0,0, ''),
(9503,0,0, 'Thank you, Son of Ursoc.  I''ll see what can be done.',1,1,0,0,0,0, ''),
(9504,0,0, 'Who was this stranger?',1,1,9505,0,0,0, ''),
(9505,0,0, 'Thank you, Kodian.  I''ll do what I can.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9576 AND `text_id`=12912;
DELETE FROM `gossip_menu` WHERE `entry`=9502 AND `text_id`=12794;
DELETE FROM `gossip_menu` WHERE `entry`=9503 AND `text_id`=12796;
DELETE FROM `gossip_menu` WHERE `entry`=9770 AND `text_id`=13445;
DELETE FROM `gossip_menu` WHERE `entry`=9505 AND `text_id`=12798;
DELETE FROM `gossip_menu` WHERE `entry`=9627 AND `text_id`=13024;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9576,12912),
(9502,12794),
(9503,12796),
(9505,12798),
(9770,13445),
(9627,13024);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9576 WHERE `entry`=26944; -- Soulok Stormfury
UPDATE `creature_template` SET `gossip_menu_id`=9770 WHERE `entry`=26935; -- Sasha

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9500,9502,9503,9504,9505,9576) AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9627 AND `SourceEntry`=13024;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9627,13024,0,6,67,0,0,0,'','Emily has different gossip when player is Horde'),
(15,9500,0,0,9,12231,0,0,0,'','Orsonn - Show gossip option only if player has taken quest 12231'),
(15,9500,0,1,9,12247,0,0,0,'','Orsonn - Show gossip option only if player has taken quest 12247'),
(15,9502,0,0,9,12231,0,0,0,'','Orsonn - Show gossip option only if player has taken quest 12231'),
(15,9502,0,1,9,12247,0,0,0,'','Orsonn - Show gossip option only if player has taken quest 12247'),
(15,9503,0,0,9,12231,0,0,0,'','Orsonn - Show gossip option only if player has taken quest 12231'),
(15,9503,0,1,9,12247,0,0,0,'','Orsonn - Show gossip option only if player has taken quest 12247'),
(15,9504,0,0,9,12231,0,0,0,'','Kodian - Show gossip option only if player has taken quest 12231'),
(15,9504,0,1,9,12247,0,0,0,'','Kodian - Show gossip option only if player has taken quest 12247'),
(15,9505,0,0,9,12231,0,0,0,'','Kodian - Show gossip option only if player has taken quest 12231'),
(15,9505,0,1,9,12247,0,0,0,'','Kodian - Show gossip option only if player has taken quest 12247'),
(15,9576,0,0,15,3,0,0,0,'','Soulok Stormfury - Show gossip option only if player is a hunter');

-- SmartAIs
SET @NPC_ORSONN := 27274;
SET @NPC_KODIAN := 27275;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (@NPC_ORSONN,@NPC_KODIAN); -- script npc_orsonn_and_kodian, the defines and enums in grizzly_hills.cpp have to be deleted
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_ORSONN,@NPC_KODIAN) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_ORSONN,0,0,1,62,0,100,0,9503,0,0,0,33,27322,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orsonn - On gossip select - Quest credit'),
(@NPC_ORSONN,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Orsonn - On gossip select - Close gossip'),
(@NPC_KODIAN,0,0,1,62,0,100,0,9505,0,0,0,33,27321,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kodian - On gossip select - Quest credit'),
(@NPC_KODIAN,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kodian - On gossip select - Close gossip');
