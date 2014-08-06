-- Rotface's Slime Spray scriptname
DELETE FROM `spell_script_names` WHERE `Spell_id` IN (69507, 71213, 73189, 73190);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(69507, 'spell_rotface_slime_spray'),
(71213, 'spell_rotface_slime_spray'),
(73189, 'spell_rotface_slime_spray'),
(73190, 'spell_rotface_slime_spray');
