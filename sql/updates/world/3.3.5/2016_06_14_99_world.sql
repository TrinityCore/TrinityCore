-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8356, 8371); -- Flanis Swiftwing, Kagrosh

INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(8356, 0, 0, 'Reclaim Flanis\'s pack.', 19326,1,1,0,0,0,0,'',0),
(8371, 0, 0, 'Search the corpse for Kagrosh\'s pack.', 19400,1,1,0,0,0,0,'',0);

-- Migrate NPC to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (21727, 21725);

-- Create SmartAI for Flanis
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21727);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21727, 0, 0, 1, 62, 0, 100, 0, 8356, 0, 0, 0, 56, 30658, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Flanis Swiftwing - On Gossip Option 0 Selected - Add Item \'Flanis\'s Pack\'  1 Time'),
(21727, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Flanis Swiftwing - On Linked Action - Close Gossip'); -- fixes current non-Blizzlike behaviour

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8356;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8356,0,0,0,2,0,30658,1,0,1,0,'','Flanis Swiftwing - Show gossip option 0 if player does not have item 30658 in inventory'),
(15,8356,0,0,0,9,0,10583,0,0,0,0,'','Flanis Swiftwing - Show gossip option 0 if player has accepted quest 10583');

-- Create SmartAI for Kagrosh
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 21725);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21725, 0, 0, 1, 62, 0, 100, 0, 8371, 0, 0, 0, 56, 30659, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kagrosh - On Gossip Option 0 Selected - Add Item \'Kagrosh\'s Pack\'  1 Time'),
(21725, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kagrosh - On Linked Action - Close Gossip'); -- fixes current non-Blizzlike behaviour

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8371;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8371,0,0,0,2,0,30659,1,0,1,0,'','Kagrosh - Show gossip option 0 if player does not have item 30659 in inventory'),
(15,8371,0,0,0,9,0,10601,0,0,0,0,'','Kagrosh - Show gossip option 0 if player has accepted quest 10601');

-- Migrate NPC off of cpp script
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 23489;
-- Create conditions for Hurlunk
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8754;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8754,0,0,0,5,0,1015,128,0,0,0,'','Drake Dealer Hurlunk - Show gossip option 0 if player is exalted with faction 1015');
