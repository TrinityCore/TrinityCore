-- 257044 - Rapid Fire
DELETE FROM `spell_script_names` WHERE `spell_id` IN (257044, 257045);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(257044, 'spell_hun_rapid_fire'),
(257045, 'spell_hun_rapid_fire_damage');
