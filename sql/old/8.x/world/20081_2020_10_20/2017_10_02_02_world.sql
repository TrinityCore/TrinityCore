-- Out of combat script for Instructor Ciel
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18629;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18629) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1862900) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18629, 0, 0, 0, 1, 0, 100, 0, 200, 1000, 12000, 12000, 80, 1862900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Ciel - Out Of Combat - Run Script"),
(1862900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'Laugh'"),
(1862900, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 54, 0, 0, 0, 0, 0, 19, 18626, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'SpecialAttack1H' (Trainee Alcor)"),
(1862900, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 54, 0, 0, 0, 0, 0, 19, 18627, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'SpecialAttack1H' (Trainee Firea)"),
(1862900, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'Point'"),
(1862900, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 35, 0, 0, 0, 0, 0, 19, 18626, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'AttackUnarmed' (Trainee Alcor)"),
(1862900, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 35, 0, 0, 0, 0, 0, 19, 18627, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'AttackUnarmed' (Trainee Firea)"),
(1862900, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'No'"),
(1862900, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 60, 0, 0, 0, 0, 0, 19, 18626, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'Kick' (Trainee Alcor)"),
(1862900, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 60, 0, 0, 0, 0, 0, 19, 18627, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'Kick' (Trainee Firea)"),
(1862900, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'Point'"),
(1862900, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 36, 0, 0, 0, 0, 0, 19, 18626, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'Attack1H' (Trainee Alcor)"),
(1862900, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 36, 0, 0, 0, 0, 0, 19, 18627, 0, 0, 0, 0, 0, 0, "Instructor Ciel - On Script - Emote 'Attack1H' (Trainee Firea)");
