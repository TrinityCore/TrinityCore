UPDATE `spell_proc` SET `Charges`= 0 WHERE `SpellId`=44544;
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_mage_fingers_of_frost_charges';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44544, 'spell_mage_fingers_of_frost_charges');
