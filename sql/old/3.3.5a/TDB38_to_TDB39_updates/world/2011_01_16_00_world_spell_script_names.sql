DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_marrowgar_coldflame_trigger';
DELETE FROM `spell_script_names` WHERE `spell_id` IN (69146,70823,70824,70825) AND `ScriptName`='spell_marrowgar_coldflame_damage';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(69146,'spell_marrowgar_coldflame_damage'),
(70823,'spell_marrowgar_coldflame_damage'),
(70824,'spell_marrowgar_coldflame_damage'),
(70825,'spell_marrowgar_coldflame_damage');
