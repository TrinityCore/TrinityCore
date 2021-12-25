-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=28314 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2831400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28314, 0, 0, 0, 19, 0, 100, 0, 12566, 0, 0, 0, 0, 80, 2831400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Longrunner Nanik - On Quest Accept - Run Script"),
(2831400, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 28313, 0, 0, 0, 0, 0, 0, 0, "Longrunner Nanik - On Script - Say Line 0 (Apothecary Scyllis)"),
(2831400, 9, 1, 0, 0, 0, 0, 0, 6000, 6000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 28313, 0, 0, 0, 0, 0, 0, 0, "Longrunner Nanik - On Script - Say Line 1 (Apothecary Scyllis)");

DELETE FROM `creature_text` WHERE `CreatureID`=28313;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28313, 0, 0, "Yes, yes, we should do whatever we can to help them.", 12, 1, 100, 1, 0, 0, 27726, 0, "Apothecary Scyllis"),
(28313, 1, 0, "Longrunner, your fodder... err, people will be a valuable resource against the vrykul. Did I say resource? I meant, 'ally.' \n", 12, 1, 100, 25, 0, 0, 27727, 0, "Apothecary Scyllis");
