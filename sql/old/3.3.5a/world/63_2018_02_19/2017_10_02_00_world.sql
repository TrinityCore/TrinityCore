-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=25836 AND `id`=1 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25836, 0, 1, 0, 1, 0, 100, 0, 1000, 120000, 140000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Loot Crazed Diver - Out Of Combat - Say Line 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=25836;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 2, 25836, 0, 0, 30, 1, 187909, 5, 0, 0, 0, 0, "", "Run SAI script if invoker is nearby gameobject 'Coldrock Clam'");

DELETE FROM `creature_text` WHERE `creatureid`=25836;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25836, 0, 0, "Mother of pearl!", 12, 0, 100, 0, 0, 0, 25037, 0, "Loot Crazed Diver"),
(25836, 0, 1, "Clam skin dress shirt here I come!", 12, 0, 100, 0, 0, 0, 25038, 0, "Loot Crazed Diver"),
(25836, 0, 2, "The clam has given up the goods!", 12, 0, 100, 0, 0, 0, 25039, 0, "Loot Crazed Diver"),
(25836, 0, 3, "BAM!", 12, 0, 100, 0, 0, 0, 25040, 0, "Loot Crazed Diver");
