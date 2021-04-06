-- Mage Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_arcane_barrage', 'spell_mage_arcane_explosion');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44425, 'spell_mage_arcane_barrage'),
(1449, 'spell_mage_arcane_explosion');
