DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_flurry','spell_mage_flurry_damage');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(44614,'spell_mage_flurry'),
(228354,'spell_mage_flurry_damage');
