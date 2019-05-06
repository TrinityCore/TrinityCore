--
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (7582,7583,7585);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7582,0,0,'Greetings, elder. It is time for your people to end their hostility toward the draenei and their allies.',14872,1,3,7583,0,0,0,'',0,-1),
(7583,0,0,'I did not mean to deceive you, elder. The draenei of Telredor thought to approach you in a way that would be familiar to you.',14874,1,3,7585,0,0,0,'',0,-1),
(7585,0,0,'I will tell them. Farewell, elder.',14879,1,3,7586,0,0,0,'',0,-1);

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 18197;

DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 18197);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18197, 0, 0, 0, 62, 0, 100, 0, 7585, 0, 0, 0, 11, 32152, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Elder Kuruti - On Gossip Option 0 Selected - Add \'Elder Kuruti\'s Response\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 7582;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,7582,0,0,1,8,0,9803,0,0,1,0,'','Elder Kuruti - Show Gossip Option 0 if Quest 9803 is not rewarded'),
(15,7582,0,0,1,9,0,9803,0,0,0,0,'','Elder Kuruti - Show Gossip Option 0 if Quest 9803 is taken'),
(15,7582,0,0,1,2,0,24573,1,0,1,0,'','Elder Kuruti - Show Gossip Option 0 if player does not have item 24573 in inventory');
