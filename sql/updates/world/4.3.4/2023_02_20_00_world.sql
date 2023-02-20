DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_rogue_venomous_wounds',
'spell_rog_glyph_of_backstab_triggered');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-79133, 'spell_rogue_venomous_wounds');

DELETE FROM `spell_proc` WHERE `SpellId`= -79133;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(-79133, 8, 0x100 | 0x100000, 0x1, 0x2);
