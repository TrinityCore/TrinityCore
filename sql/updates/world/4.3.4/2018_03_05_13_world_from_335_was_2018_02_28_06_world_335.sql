/*
-- Quest "Helcular's Revenge (Part 2)"
-- Helcular's Grave
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=1767;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1767 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1767,1,0,0,20,0,100,0,553,0,0,0,12,2433,3,600000,0,0,0,8,0,0,0,-742.94,-615.67,18.72,1.61731,"Helcular's Grave - On Quest 'Helcular's Revenge (Part 2)' Rewarded - Summon Creature 'Helcular's Remains'");

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=1767;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,1767,1,0,29,1,2433,200,0,1,0,0,"","SAI triggers only if Helcular's Remains is not already spawned");

-- Helcular's Remains
DELETE FROM `smart_scripts` WHERE `entryorguid`=2433 AND `source_type`=0 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2433,0,3,0,11,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular's Remains - On Respawn - Start Random Movement"),
(2433,0,4,0,11,0,100,0,0,0,0,0,11,3390,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helcular's Remains - On Respawn - Cast 'Helcular's Spawn'");

UPDATE `creature_text` SET `Emote`=15 WHERE `CreatureID`=2433 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=0 WHERE `CreatureID`=2433 AND `GroupID`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=2433 AND `GroupID`=0 AND `ID`=3;
DELETE FROM `creature_text` WHERE `CreatureID`=2433 AND `GroupID`=1 AND `ID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2433,0,3,"I returned from the grave to take my revenge!",14,0,100,15,0,0,599,0,"Helcular's Remains"),
(2433,1,1,"Die in the name of the Dark Lady, $n.",14,0,100,0,0,0,600,0,"Helcular's Remains");
*/
