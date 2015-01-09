-- Captured Sunhawk Agent SAI
SET @ENTRY := 17824;
UPDATE `creature_template` SET `gossip_menu_id`=7531, `AIName`='SmartAI', `ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,7533,0,0,0,33,17974,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captured Sunhawk Agent - On Gossip Option - Kill Credit"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captured Sunhawk Agent - On Gossip Option - Close Gossip");

-- Add missing gossip for Captured Sunhawk Agent
DELETE FROM `gossip_menu` WHERE `entry` IN (7531,7533,7534,7535,7536,7537);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7531,9134),(7531,9136),(7533,9141),(7534,9140),(7535,9139),(7536,9138),(7537,9137);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7531,7537,7536,7535,7534,7533);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(7531,0,0, 'I''m a prisoner, what does it look like? The draenei filth captured me as I exited the sun gate. They killed our portal controllers and destroyed the gate. The Sun King will be most displeased with this turn of events.',1,1,7537,0,0,0, ''),
(7537,0,0, 'Ah yes, Sironas. I had nearly forgotten that Sironas was here. I served under Sironas back on Outland. I hadn''t heard of this abomination, though; those damnable draenei captured me before I even fully materialized on this world.',1,1,7536,0,0,0, ''),
(7536,0,0, 'Incredible. How did Sironas accomplish such a thing?',1,1,7535,0,0,0, ''),
(7535,0,0, 'Sironas is an eredar... I mean, yes, obviously.',1,1,7534,0,0,0, ''),
(7534,0,0, 'The Vector Coil is massive. I hope we have more than one abomination guarding the numerous weak points.',1,1,7533,0,0,0, ''),
(7533,0,0, 'I did and you believed me. Thank you for the information, blood elf. You have helped us more than you could know.',1,1,0,0,0,0, '');

-- Add Conditions for Captured Sunhawk Agent gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7531;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,7531,0,0,0,9,0,9756,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 9756 is taken'),
(15,7531,0,0,1,1,0,31609,0,0,0,0,0, '', 'Gossip Option - Show Option if player has aura 31609');
