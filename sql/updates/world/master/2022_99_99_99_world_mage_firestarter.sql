DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_fireball', 'spell_mage_pyroblast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(133, 'spell_mage_fireball'),
(11366, 'spell_mage_pyroblast');
