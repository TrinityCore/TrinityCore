UPDATE `creature_template` SET `RegenHealth`= 0 WHERE `entry`= 44564;
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_wounded';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46577, 'spell_gen_wounded');

-- Creature Wounded Trainee 44564 SAI
SET @ENTRY := 44564;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 65000, 65000, 11, 46577, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Update (OOC) 1000 min and 1000 max ms (repeat 65000 min 65000 max ms) - Self: Cast spell Wounded (46577) on Self // "),
(@ENTRY, 0, 1, 0, 8, 0, 100, 0, 2061, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spell Flash Heal (2061) hit  - Action invoker: Give kill credit Spell Practice Credit (44175) // ");
