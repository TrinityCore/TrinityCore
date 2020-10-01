--
DELETE FROM `spell_proc` WHERE `SpellId` IN (98970, 98996);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(98970, 15, 0, 0x40000000, 0, 4, 1),
(98996, 15, 0, 0x20000 | 0x8000000, 0, 1, 2);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_dk_item_death_knight_t12_dps_4p_bonus',
'spell_dk_smoldering_rune');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(98996, 'spell_dk_item_death_knight_t12_dps_4p_bonus'),
(98971, 'spell_dk_smoldering_rune');
