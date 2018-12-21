DELETE FROM `creature_template_addon` WHERE `entry`= 33248;
-- Creature Power Word: Barrier 33248 SAI
SET @ENTRY := 33248;
UPDATE `creature_template` SET `unit_flags`= 33554440, `unit_flags2`= 34, `minlevel`= 1, `maxlevel`= 1, `faction`= 35, `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 11, 40031, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell 40031 on Self // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 81781, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 81781 on Self // ");


DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_power_word_barrier';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81781, 'spell_power_word_barrier');
