DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_arcane_missiles';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-5143,'spell_mage_arcane_missiles');

UPDATE `spell_script_names` SET `ScriptName`='spell_mage_missile_barrage_proc' WHERE `spell_id`=44401;
