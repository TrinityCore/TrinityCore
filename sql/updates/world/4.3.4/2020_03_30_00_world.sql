-- Creature Singing Sunflower 51090 SAI
SET @ENTRY := 51090;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 93971, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Sunflower (DND) (93971) on Self // ");


DELETE FROM `spell_script_names`WHERE `ScriptName`= 'spell_gen_sunflower_dnd';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93971, 'spell_gen_sunflower_dnd');
