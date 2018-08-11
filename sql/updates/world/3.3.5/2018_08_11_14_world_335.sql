-- Renn McGill
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=23569;

DELETE FROM `gossip_menu_option` WHERE `MenuID`=8837;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8837,0,0,"I don't have the Repaired Diving Gear anymore. Do you have a spare?",22482,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8837;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8837,0,0,0,9,0,11140,0,0,0,0,0,"","Show gossip option if quest 'Recover the Cargo!' is taken"),
(15,8837,0,0,0,2,0,33040,1,1,1,0,0,"","Show gossip option if player does not have item 'Repaired Diving Gear'");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23569;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23569 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2356900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23569,0,0,1,62,0,100,0,8837,0,0,0,85,42670,0,0,0,0,0,7,0,0,0,0,0,0,0,"Renn McGill - On Gossip Option 0 Selected - Invoker Cast 'Replace Repaired Diving Gear'"),
(23569,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Renn McGill - On Gossip Option 0 Selected - Close Gossip"),
(23569,0,2,0,20,0,100,0,11140,0,0,0,80,2356900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Renn McGill - On Quest 'Recover the Cargo!' Finished - Run Script"),
(2356900,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Renn McGill - On Script - Remove Npc Flag Questgiver+Gossip"),
(2356900,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Renn McGill - On Script - Say Line 0"),
(2356900,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Renn McGill - On Script - Say Line 1"),
(2356900,9,3,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Renn McGill - On Script - Say Line 2"),
(2356900,9,4,0,0,0,100,0,6000,6000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Renn McGill - On Script - Add Npc Flag Questgiver+Gossip");

DELETE FROM `creature_text` WHERE `CreatureID`=23569;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23569,0,0,"Hmm... old coins... ugly jewelry...",12,7,100,0,0,0,22160,0,"Renn McGill"),
(23569,1,0,"More ugly jewelry... letters home... I'm beginning to give up hope!",12,7,100,0,0,0,22161,0,"Renn McGill"),
(23569,2,0,"Hey... what's this? A pair of manacles and not just any. These are enchanted. This cargo, it wasn't a thing... it was a person!",12,7,100,0,0,0,22162,0,"Renn McGill");
