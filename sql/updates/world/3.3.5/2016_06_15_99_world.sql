-- Fix requirement quest for the alliance
UPDATE `quest_template_addon` SET `PrevQuestID`=2278, `NextQuestID`=2439 WHERE `ID`=2279;

-- Add sniffed gossip text to menu
DELETE FROM `gossip_menu_option` WHERE (`menu_id` BETWEEN 1674 AND 1679) OR (`menu_id` IN (9977, 9978));
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(1674,0,0,'What function do you serve?',4054,1,1,1675,0,0,0,'',0),
(1675,0,0,'What are the Plates of Uldum?',4056,1,1,1676,0,0,0,'',0),
(1676,0,0,'Where are the Plates of Uldum?',4057,1,1,1677,0,0,0,'',0),
(1677,0,0,'Excuse me? We\'ve been "rescheduled for visitation"? What does that mean?!',4058,1,1,1678,0,0,0,'',0),
(1678,0,0,'So... what\'s inside Uldum?',4059,1,1,1679,0,0,0,'',0),
(1679,0,0,'I will return when I have the Plates of Uldum.',4060,1,1,0,0,0,0,'',0),
(8072,0,0,'Please take me to the master\'s lair.',17742,1,3,0,0,0,0,'',0);

-- Migrate NPC's to use SmartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (7918, 20142);

-- Create SmartAI
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid IN (7918, 20142));
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7918,0,0,1,62,0,100,0,1679,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stone Watcher of Norgannon - On Gossip Option 0 Selected - Close Gossip'),
(7918,0,1,0,61,0,100,0,0,0,0,0,15,2954,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stone Watcher of Norgannon - On Gossip Option 0 Selected - Quest Credit 2954'),
(20142,0,0,1,62,0,100,0,9978,0,0,0,85,34891,0,0,0,0,0,7,0,0,0,0,0,0,0,'Steward of Time - On Gossip Option 0 Selected - Invoker Cast \'Flight through Caverns\''),
(20142,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Steward of Time - On Gossip Option 0 Selected - Close Gossip'),
(20142,0,2,0,19,0,100,0,10279,0,0,0,85,34891,0,0,0,0,0,7,0,0,0,0,0,0,0,'Steward of Time - On Quest 10279 Taken - Invoker Cast \'Flight through Caverns\'');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 1674;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` IN (9977, 9978);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1674,0,0,0,9,0,2954,0,0,0,0,'','Stone Watcher of Norgannon - Show Gossip Option 0 if player has accepted quest 2954'),
(15,8072,0,0,0,8,0,10279,0,0,0,0,'','Steward of Time - Show Gossip Option 0 if Quest 10279 is not rewarded'),
(14,8072,9977,0,0,8,0,10279,0,0,1,0,'','Steward of Time - Show Gossip Menu text 9977 if Quest 10279 is not rewarded'),
(14,8072,9978,0,0,8,0,10279,0,0,0,0,'','Steward of Time - Show Gossip Menu text 9978 if Quest 10279 is rewarded');
