-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (25205, 25211);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25205, 25211) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25205, 0, 0, 1, 19, 0, 100, 0, 11563, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Mrmrglmr - On Quest 'Grmmurggll Mrllggrl Glrggl!!!' Accepted - Store Target (Invoker)"),
(25205, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 25211, 0, 0, 0, 0, 0, 0, "Mrmrglmr - On Quest 'Grmmurggll Mrllggrl Glrggl!!!' Accepted - Send Stored Target (Cleaver Bmurglbrm)"),
(25205, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 25211, 0, 0, 0, 0, 0, 0, "Mrmrglmr - On Quest 'Grmmurggll Mrllggrl Glrggl!!!' Accepted - Set Data 1 1 (Cleaver Bmurglbrm)"),
(25211, 0, 0, 0, 1, 0, 100, 0, 0, 0, 3000, 3000, 11, 45264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cleaver Bmurglbrm - Out Of Combat - Cast Spell 'Cleaver Bmrglbrm's Whale Dissection'"),
(25211, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Cleaver Bmurglbrm - On Data 1 1 Set - Say Line 0 (Target Stored Target)");

DELETE FROM `creature_text` WHERE `creatureid`=25211;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25211, 0, 0, "Psst... $r, over here! Next to the dead whale.", 15, 0, 100, 0, 0, 0, 24450, 0, "Cleaver Bmurglbrm");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=45264;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 45264, 0, 0, 31, 0, 3, 23837, 0, 0, 0, 0, "", "Spell 'Cleaver Bmrglbrm's Whale Dissection' EFFECT_1 targets 'ELM General Purpose Bunny'");
