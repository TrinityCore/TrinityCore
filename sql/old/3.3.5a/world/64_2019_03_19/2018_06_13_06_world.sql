-- Quest "By Any Means Necessary"
UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=9978;

-- Empoor
DELETE FROM `gossip_menu` WHERE `MenuID`=7704 AND `TextID`=9406;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7704,9406,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=7704 AND `OptionID`=1;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7704,1,0,"Tell me again what you know!",16123,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7704 AND `SourceEntry`=9406;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7704 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7704,9406,0,0,28,0,9978,0,0,0,0,0,"","Show gossip text 9406 if quest 'By Any Means Necessary' is complete"),
(15,7704,1,0,0,8,0,9978,0,0,0,0,0,"","Show gossip option 1 if quest 'By Any Means Necessary' is rewarded"),
(15,7704,1,0,0,14,0,9979,0,0,0,0,0,"","Show gossip option 1 if quest 'Wind Trader Lathrai' is not taken"),
(15,7704,1,0,1,28,0,9978,0,0,0,0,0,"","Show gossip option 1 if quest 'By Any Means Necessary' is complete");

DELETE FROM `smart_scripts` WHERE `entryorguid`=18482 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1848200,1848201,1848202) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18482,0,0,0,11,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Respawn - Remove Npc Flag Questgiver"),
(18482,0,1,0,11,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Respawn - Set Invincibility at 1 HP"),
(18482,0,2,4,62,0,100,0,7704,0,0,0,0,80,1848200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Gossip Option 0 Selected - Run Script"),
(18482,0,3,4,62,0,100,0,7704,1,0,0,0,80,1848200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Gossip Option 1 Selected - Run Script"),
(18482,0,4,0,61,0,100,0,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Gossip Option Selected - Reset All Scripts"),
(18482,0,5,0,2,0,100,1,0,1,0,0,0,80,1848201,2,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - Between 0-1% Health - Run Script"),
(18482,0,6,0,0,0,100,0,3000,5000,9000,12000,0,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Empoor - In Combat - Cast 'Frost Shock'"),
(18482,0,7,0,23,0,100,0,12550,0,1000,2000,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Has No Aura 'Lightning Shield' - Cast 'Lightning Shield'"),
(18482,0,8,0,7,0,100,0,0,0,0,0,0,80,1848202,2,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Evade - Run Script"),
(1848200,9,0,0,0,0,100,0,0,0,0,0,0,2,1679,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Set Faction 1679"),
(1848200,9,1,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,18483,0,0,0,0,0,0,"Empoor - On Script - Set Data 1 to Empoor's Bodyguard"),
(1848200,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Say Line 0"),
(1848200,9,3,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Empoor - On Script - Start Attacking"),
(1848201,9,0,0,0,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Set Faction 35"),
(1848201,9,1,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Stop Combat"),
(1848201,9,2,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,19,18483,0,0,0,0,0,0,"Empoor - On Script - Set Data 2 to Empoor's Bodyguard"),
(1848201,9,3,0,0,0,100,0,0,0,0,0,0,15,9978,0,0,0,0,0,18,50,0,0,0,0,0,0,"Empoor - On Script - Complete Quest 'By Any Means Necessary'"),
(1848201,9,4,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Add Npc Flag Questgiver"),
(1848201,9,5,0,0,0,100,0,120000,120000,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Remove Npc Flag Questgiver"),
(1848201,9,6,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Say Line 1"),
(1848202,9,0,0,0,0,100,0,20000,20000,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor - On Script - Set Faction 35");

DELETE FROM `creature_text` WHERE `CreatureID`=18482;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18482,0,0,"What is the meaning of this?!",12,0,100,0,0,0,15487,0,"Empoor"),
(18482,1,0,"I'm leaving now!",12,0,100,1,0,0,15491,0,"Empoor");

-- Empoor's Bodyguard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18483;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18483 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18483,0,0,0,38,0,100,0,1,1,0,0,2,1679,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor's Bodyguard - On Data Set - Set Faction 1679"),
(18483,0,1,0,38,0,100,0,1,1,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Empoor's Bodyguard - On Data Set - Start Attacking"),
(18483,0,2,0,38,0,100,0,2,2,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor's Bodyguard - On Data Set - Set Faction 35"),
(18483,0,3,0,38,0,100,0,2,2,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor's Bodyguard - On Data Set - Stop Combat"),
(18483,0,4,0,0,0,100,0,3000,5000,10000,14000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Empoor's Bodyguard - In Combat - Cast 'Rend'"),
(18483,0,5,0,0,0,100,0,5000,7000,15000,20000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor's Bodyguard - In Combat - Cast 'Demoralizing Shout'"),
(18483,0,6,0,7,0,100,0,0,0,0,0,80,1848202,2,0,0,0,0,1,0,0,0,0,0,0,0,"Empoor's Bodyguard - On Evade - Run Script");
