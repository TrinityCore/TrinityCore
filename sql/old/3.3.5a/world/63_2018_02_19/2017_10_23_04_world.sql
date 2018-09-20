--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7917;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7917 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7917, 0, 0, 1, 10, 0, 100, 0, 1, 10, 40000, 80000, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brother Sarno - OOC LoS - Face Invoker"),
(7917, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 3000, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Brother Sarno - OOC LoS - Say Line 1"),
(7917, 0, 2, 0, 52, 0, 100, 0, 0, 7917, 0, 0, 66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Brother Sarno - On Text Over - Reset Orientation");

DELETE FROM `creature_text` WHERE `creatureid`=7917;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7917, 0, 0, "Greetings, $c!  Welcome to the Cathedral of Light!", 12, 0, 100, 3, 0, 0, 3988, 0, "Brother Sarno");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=7917;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7917, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, "", "Execute SAI only if invoker is a player AND"),
(22, 1, 7917, 0, 0, 15, 0, 32, 0, 0, 1, 0, 0, "", "Execute SAI only if invoker is NOT a Death Knight");
