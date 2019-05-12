DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_shooting_stars';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93400, 'spell_dru_shooting_stars');

UPDATE `spell_proc` SET `SpellFamilyMask0`= `SpellFamilyMask0` | 0x00000002, `Chance`= 100 WHERE `SpellId`= 54845;
