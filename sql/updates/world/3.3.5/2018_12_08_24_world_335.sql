-- Scooty
DELETE FROM `creature_text` WHERE `CreatureID`=7853;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7853,0,0,"Give me a moment while I calibrate the transponder to your height and weight specifications, $n.",12,0,100,0,0,0,3904,0,"Scooty"),
(7853,1,0,"Alright, $n, your transponder is ready!",12,0,100,0,0,0,3905,0,"Scooty");

DELETE FROM `smart_scripts` WHERE `entryorguid`=7853 AND `source_type`=0 AND `id` IN (1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=785300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7853,0,1,0,62,0,100,0,1628,0,0,0,85,13325,2,0,0,0,0,7,0,0,0,0,0,0,0,"Scooty - On Gossip Option 0 Selected - Invoker Cast 'Transponder Summon'"),
(7853,0,2,0,62,0,100,0,1628,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scooty - On Gossip Option 0 Selected - Close Gossip"),
(785300,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scooty - On Script - Remove Npc Flag Questgiver"),
(785300,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scooty - On Script - Say Line 0"),
(785300,9,2,0,0,0,100,0,3000,3000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scooty - On Script - Set Emote State 69"),
(785300,9,3,0,0,0,100,0,12000,12000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scooty - On Script - Set Emote State 0"),
(785300,9,4,0,0,0,100,0,0,0,0,0,15,2843,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scooty - On Script - Complete Quest 'Gnomer-gooooone!'"),
(785300,9,5,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scooty - On Script - Say Line 1"),
(785300,9,6,0,0,0,100,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scooty - On Script - Add Npc Flag Questgiver");

DELETE FROM `gossip_menu_option` WHERE `MenuID`=1628;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1628,0,0,"I lost my transponder and need another one, Scooty.",4634,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1628;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,1628,0,0,0,8,0,2843,0,0,0,0,0,"","Show gossip option if quest 'Gnomer-gooooone!' is rewarded"),
(15,1628,0,0,0,2,0,9173,1,1,1,0,0,"","Show gossip option if player does not have item 'Goblin Transponder'");
