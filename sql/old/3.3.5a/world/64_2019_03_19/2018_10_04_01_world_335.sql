-- Lexlort
UPDATE `creature_template` SET `gossip_menu_id`=5762, `AIName`="SmartAI" WHERE `entry`=9080;

DELETE FROM `gossip_menu` WHERE `MenuID`=5762;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5762,6947,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=5762;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5762,0,0,"Lexlort, I lost the thorium shackles.",9529,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5762;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,5762,0,0,0,14,0,4122,0,0,1,0,0,"","Show gossip option if quest 'Grark Lorkrub' is taken"),
(15,5762,0,0,0,8,0,4121,0,0,1,0,0,"","Show gossip option if quest 'Precarious Predicament' is not rewarded"),
(15,5762,0,0,0,2,0,11286,1,1,1,0,0,"","Show gossip option if player does not have item 'Thorium Shackles'");

DELETE FROM `smart_scripts` WHERE `entryorguid`=9080 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9080,0,0,0,62,0,100,0,5762,0,0,0,85,22941,2,0,0,0,0,7,0,0,0,0,0,0,0,"Lexlort - On Gossip Option Selected - Invoker Cast 'Player Lost Shackles DND'"),
(9080,0,1,0,62,0,100,0,5762,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Lexlort - On Gossip Option Selected - Close Gossip");

-- Grark Lorkrub
DELETE FROM `smart_scripts` WHERE `entryorguid`=9520 AND `source_type`=0 AND `id` IN (0,1,2,3,4,5,6,7,8,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9520,0,0,0,11,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Respawn - Remove Npc Flag 'Questgiver'"),
(9520,0,1,2,8,0,100,0,14250,0,0,0,0,2,40,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Spellhit 'Capture Grark' - Set Faction 40"),
(9520,0,2,3,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grark Lorkrub - On Spellhit 'Capture Grark' - Start Attacking"),
(9520,0,3,4,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Spellhit 'Capture Grark' - Say Line 0"),
(9520,0,4,0,61,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Spellhit 'Capture Grark' - Set Invincibility at 1 HP"),
(9520,0,5,6,2,0,100,1,0,25,0,0,0,2,29,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - Between 0-25% Health - Set Faction 29"),
(9520,0,6,7,61,0,100,1,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - Between 0-25% Health - Add Npc Flag 'Questgiver'"),
(9520,0,7,8,61,0,100,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - Between 0-25% Health - Say Line 1"),
(9520,0,8,0,61,0,100,1,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - Between 0-25% Health - Evade"),
(9520,0,9,0,1,0,100,1,120000,120000,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - Out of Combat - Remove Npc Flag 'Questgiver'");

DELETE FROM `creature_text` WHERE `CreatureID`=9520 AND `GroupID` IN (0,1);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9520,0,0,"You have come to play? Then let us play!",12,0,100,0,0,0,4927,0,"Grark Lorkrub"),
(9520,1,0,"%s submits.",16,0,100,0,0,0,4918,0,"Grark Lorkrub");
