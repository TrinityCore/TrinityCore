UPDATE `pet_levelstats` SET `str`= 476, `agi`= 3343, `sta`= 546, `inte`= 69, `spi`= 116 WHERE `creature_entry`= 26125 AND `level`= 85;

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dk_avoidance_passive';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62137, 'spell_dk_avoidance_passive');
