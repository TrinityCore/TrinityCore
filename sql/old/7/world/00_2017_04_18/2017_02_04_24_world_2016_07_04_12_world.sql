-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (8356, 8371);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(8356, 0, 0, 'Reclaim Flanis\'s pack.', 19326,1,1,0,0,0,0,'',0),
(8371, 0, 0, 'Search the corpse for Kagrosh\'s pack.', 19400,1,1,0,0,0,0,'',0);

-- Migrate NPCs to use SmartAI / remove from C++ script
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (21727, 21725, 22112);
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 23489;

-- Create SmartAI
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid IN (21727, 21725, 22112));
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21727, 0, 0, 1, 62, 0, 100, 0, 8356, 0, 0, 0, 11, 37244, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Flanis Swiftwing - On Gossip Option 0 Selected - Cast Spell'),
(21727, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Flanis Swiftwing - On Linked Action - Close Gossip'),
(21725, 0, 0, 1, 62, 0, 100, 0, 8371, 0, 0, 0, 11, 37245, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kagrosh - On Gossip Option 0 Selected - Cast Spell'),
(21725, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kagrosh - On Linked Action - Close Gossip'),
(22112, 0, 0, 0, 19, 0, 100, 0, 10866, 0, 0, 0, 12, 11980, 1, 300000, 0, 0, 0, 8, 0, 0, 0, -4204.94, 316.397, 122.508, 1.309, 'Karynaku - On Quest Accepted - Summon Creature \'Zuluhed the Whacked\''),
(22112, 0, 1, 0, 19, 0, 100, 0, 10870, 0, 0, 0, 52, 649, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Karynaku - On Quest Accepted - Activate Taxi Path 649');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (8356, 8371, 8754);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8356,0,0,0,2,0,30658,1,0,1,0,'','Flanis Swiftwing - Show gossip option 0 if player does not have item 30658 in inventory'),
(15,8356,0,0,0,9,0,10583,0,0,0,0,'','Flanis Swiftwing - Show gossip option 0 if player has accepted quest 10583'),
(15,8371,0,0,0,2,0,30659,1,0,1,0,'','Kagrosh - Show gossip option 0 if player does not have item 30659 in inventory'),
(15,8371,0,0,0,9,0,10601,0,0,0,0,'','Kagrosh - Show gossip option 0 if player has accepted quest 10601'),
(15,8754,0,0,0,5,0,1015,128,0,0,0,'','Drake Dealer Hurlunk - Show gossip option 0 if player is exalted with faction 1015');
