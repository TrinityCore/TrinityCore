UPDATE `creature_text` SET `type`=14 WHERE `CreatureID`=24118;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=24118;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23671 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23671, 0, 0, 1, 54, 0, 100, 512, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Store Target (Invoker)"),
(23671, 0, 1, 2, 61, 0, 100, 512, 0, 0, 0, 0, 44, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Set Phasemask 3"),
(23671, 0, 2, 3, 61, 0, 100, 512, 0, 0, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Talk 0"),
(23671, 0, 3, 4, 61, 0, 100, 512, 0, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 9, 24118, 0, 90, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Change Phasemask of Val'kyr Observer"),
(23671, 0, 4, 0, 61, 0, 100, 512, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Just Summoned - Set Unitflag IMMUNE_TO_PC"),
(23671, 0, 5, 6, 52, 0, 100, 0, 0, 23671, 0, 0, 1, 1, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Text 0 Over - Talk 1"),
(23671, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Text 0 Over - Remove Unitflag IMMUNE_TO_PC"),
(23671, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Text 0 Over - Start Attack"),
(23671, 0, 8, 9, 2, 0, 100, 1, 0, 50, 0, 0, 1, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Between 0% and 50% Health - Talk 2 (No Repeat\)"),
(23671, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Between 50% and 75% Health - Cast 'Enrage' (No Repeat\)"),
(23671, 0, 10, 11, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 24118, 0, 90, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Death - Set Data 1 1 to Val'kyr Observer"),
(23671, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 43091, 2, 0, 0, 0, 0, 19, 23837, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - On Death - Cast 'Stop the Ascension!: Summon Halfdan's Soul'"),
(23671, 0, 12, 0, 0, 0, 100, 0, 2000, 5000, 9500, 11500, 11, 35263, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Frost Attack'"),
(23671, 0, 13, 0, 0, 0, 100, 0, 2500, 5000, 6000, 10000, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Mortal Strike'"),
(23671, 0, 14, 0, 0, 0, 100, 0, 1250, 5000, 5000, 6000, 11, 12169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Shield Block'"),
(23671, 0, 15, 0, 0, 0, 100, 0, 3000, 8000, 4000, 12000, 11, 32015, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - In Combat - Cast 'Knockdown'"),
(23671, 0, 16, 0, 9, 0, 100, 0, 8, 25, 5000, 5000, 11, 19131, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Halfdan the Ice-Hearted - Within 8-25 Range - Cast 'Shield Charge'");
