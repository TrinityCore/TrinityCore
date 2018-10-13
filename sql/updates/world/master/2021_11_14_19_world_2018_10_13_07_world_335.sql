-- 
-- Fallen Hero of the Horde
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=840 AND `SourceEntry`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,840,2,0,0,14,0,2702,0,0,1,0,0,"","Show gossip option if quest 'Heroes of Old (Part 1)' is taken, completed or rewarded"),
(15,840,2,0,0,8,0,2701,0,0,1,0,0,"","Show gossip option if quest 'Heroes of Old (Part 2)' is not rewarded"),
(15,840,2,0,0,29,1,7750,200,0,1,0,0,"","Show gossip option if Corporal Thund Splithoof is not already summoned");

DELETE FROM `smart_scripts` WHERE `entryorguid`=7572 AND `source_type`=0 AND `id` IN (5,6);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7572,0,5,0,62,0,100,0,840,2,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Hero of the Horde - On Gossip Option 2 Selected - Say Line 0"),
(7572,0,6,0,19,0,100,0,2702,0,0,0,11,11024,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Hero of the Horde - On Quest 'Heroes of Old (Part 1)' Taken - Cast 'Call of Thund'");

DELETE FROM `creature_text` WHERE `CreatureID`=7572;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7572,0,0,"Per your request, Corporal Splithoof has come, $n.",12,0,100,0,0,0,3764,0,"Fallen Hero of the Horde");
