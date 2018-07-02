-- Creature Rupture 49576 SAI
SET @ENTRY := 49576;
UPDATE `creature_template` SET `AIName`= "SmartAI", `flags_extra`= 2 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 5, 449, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On just summoned - Self: Play emote 449 // "),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 92381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell 92381 on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 3600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Despawn in 3600 ms // ");

-- Bouncer Spike
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry`= 42189;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_ozruk_paralyze',
'spell_ozruk_elementium_spike_shield',
'spell_elementium_spike_shield',
'spell_ozruk_rupture',
'spell_rupture',
'spell_ozruk_paralyze_stun');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(92427, 'spell_ozruk_paralyze'),
(78835, 'spell_ozruk_elementium_spike_shield'),
(92429, 'spell_ozruk_elementium_spike_shield'),
(92393, 'spell_ozruk_rupture'),
(92426, 'spell_ozruk_paralyze_stun');
