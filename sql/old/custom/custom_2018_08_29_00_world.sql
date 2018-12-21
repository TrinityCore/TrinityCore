-- Creature Pit Viper 39444 SAI
SET @ENTRY := 39444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 116, 5500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Sets corpse delay of Self to 5500ms // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 9000, 10000, 8000, 8000, 11, 74538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 10000 ms (and later repeats every 8000 and 8000 ms) - Self: Cast spell 74538 on Victim // ");

-- Creature Sun-Touched Speaker 39373 SAI
SET @ENTRY := 39373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 3000, 12000, 12000, 11, 74632, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 3000 and 3000 ms (and later repeats every 12000 and 12000 ms) - Self: Cast spell 74632 on Self // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 1, 4000, 5000, 0, 0, 11, 73861, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 5000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 73861 on Random hostile // ");

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_hoo_flame_ring_visual');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74632, 'spell_hoo_flame_ring_visual');
