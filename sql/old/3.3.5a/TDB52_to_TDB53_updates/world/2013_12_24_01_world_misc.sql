-- Remove script for Naladu gossip already exist
UPDATE `creature_template` SET `AIName`='', `ScriptName`= '' WHERE `entry`=19361;

-- Gossip text & Options for Tracy Proudwell
UPDATE `creature_template` SET `gossip_menu_id`=7892 WHERE `entry`=18266;
DELETE FROM `gossip_menu` WHERE `entry` IN (8544);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8544,10689);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7892,8544);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(7892,0,1, 'I have marks to redeem!',3,128,0,0,0,0, ''),
(7892,1,0, 'I heard that your dog Fei Fei took Klatu''s prayer beads...',1,1,8544,0,0,0, ''),
(8544,0,0, '<back>',1,1,7892,0,0,0, '');
-- Add Conditions for Budd Nedreck gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7892;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,7892,1,0,0,9,0,10916,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 10916 is taken');

-- Commander Danath Trollbane SAI
SET @ENTRY := 16819;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,50,0,100,0,10254,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Danath Trollbane - On Quest Rewarded - Say 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,6245,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Danath Trollbane - On Quest Rewarded - Cast Force Target - Salute");

-- Creature text for Commander Danath Trollbane
DELETE FROM `creature_text` WHERE `entry`=16819;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16819,0,0, 'Welcome to Honor Hold, $N.  It''s good to have you.',12,0,100,66,0,0, 'Commander Danath Trollbane');

-- Gossip text & Options for Force Commander Danath Trollbane
DELETE FROM `gossip_menu` WHERE `entry` IN (8043,8044,8049,8051);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8043,9933),(8044,9932),(8049,9941),(8051,8772);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7352,8044);
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(7352,0,0, 'Tell me of the Sons of Lothar.',1,1,8044,0,0,0, ''),
(7352,1,0, 'Tell me of the Hellfire orcs.',1,1,8049,0,0,0, ''),
(7352,2,0, 'Tell me of your homeland.',1,1,8051,0,0,0, ''),
(8044,0,0, '<more>',1,1,8043,0,0,0, '');

-- Add Conditions for Force Commander Danath Trollbane gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7352;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7352,9938,0,0,8,0,10254,0,0,0,1,0, '', 'Gossip Text - Show Text if Quest 10254 is not rewarded'),
(14,7352,9939,0,0,8,0,10254,0,0,0,0,0, '', 'Gossip Text - Show Text if Quest 10254 is rewarded'),
(14,7352,9939,0,1,8,0,10937,0,0,0,1,0, '', 'Gossip Text - Show Text if Quest 10937 is not rewarded'),
(14,7352,9944,0,0,8,0,10937,0,0,0,0,0, '', 'Gossip Text - Show Text if Quest 10937 is rewarded');

-- Add Conditions for Force Commander Danath Trollbane gossip options
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7352;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,7352,0,0,0,8,0,10254,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 10254 is rewarded'),
(15,7352,1,0,0,8,0,10254,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 10254 is rewarded'),
(15,7352,2,0,0,8,0,10141,0,0,0,0,0, '', 'Gossip Option - Show Option if Quest 10141 is rewarded');
