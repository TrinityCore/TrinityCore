-- Missing 5 man normal spellid
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gal_darah_stampede_charge' AND `spell_id`=55220;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(55220,'spell_gal_darah_stampede_charge');
