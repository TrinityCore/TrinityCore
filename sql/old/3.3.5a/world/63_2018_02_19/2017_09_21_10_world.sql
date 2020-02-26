-- 
DELETE FROM `creature_text` WHERE `CreatureID` IN (20501, 20778);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(20501, 0, 0, "%s attempts to split in two.", 16, 0, 100, 0, 0, 0, 18912, 0, "Seeping Sludge"),
(20501, 1, 0, "%s breaks down into globules!", 16, 0, 100, 0, 0, 0, 18479, 0, "Seeping Sludge"),
(20778, 0, 0, "%s breaks down into globules!", 16, 0, 100, 0, 0, 0, 18479, 0, "Void Waste");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20778, 20501) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20778, 0, 0, 0, 0, 0, 100, 0, 2000, 6000, 7000, 10000, 11, 36519, 32, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Void Waste - In Combat - Cast 'Toxic Burst' (No Repeat)"),
(20778, 0, 1, 2, 8, 0, 100, 1, 35686, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Void Waste - On Spellhit 'Electro-Shock' - Say Line 0 (No Repeat)"),
(20778, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 35688, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Void Waste - On Spellhit 'Electro-Shock' - Cast Spell 'Summon Void Waste Globule'"),
(20778, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Void Waste - On Spellhit 'Electro-Shock' - Kill Self"),
(20501, 0, 0, 1, 2, 0, 100, 0, 0, 50, 30000, 45000, 11, 36465, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Seeping Sludge - Between 0-50% Health - Cast 'Seeping Split' (Phase 1) (No Repeat)"),
(20501, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Seeping Sludge - Between 0-50% Health - Say Line 0"),
(20501, 0, 2, 3, 8, 0, 100, 1, 35686, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Seeping Sludge - On Spellhit 'Electro-Shock' - Say Line 1 (No Repeat)"),
(20501, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 11, 35687, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Seeping Sludge - On Spellhit 'Electro-Shock' - Cast Spell 'Summon Seeping Sludge Globule'"),
(20501, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Seeping Sludge - On Spellhit 'Electro-Shock' - Kill Self");
