DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_mage_frostbolt', 'spell_mage_trigger_chilled');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(228597, 'spell_mage_trigger_chilled'),
(11426,  'spell_mage_trigger_chilled'),
(190356, 'spell_mage_trigger_chilled');
