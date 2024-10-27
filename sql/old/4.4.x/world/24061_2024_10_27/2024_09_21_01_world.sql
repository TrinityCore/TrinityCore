DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_offensive_state_dnd', 'spell_mage_arcane_missiles');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79684, 'spell_mage_offensive_state_dnd'),
(79683, 'spell_mage_arcane_missiles');

DELETE FROM `spell_proc` WHERE `SpellId` IN (79684, 79683);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellPhaseMask`, `Charges`) VALUES
(79684, 3, 0x0, 0x1, 0),
(79683, 3, 0x800, 0x1, 1);
