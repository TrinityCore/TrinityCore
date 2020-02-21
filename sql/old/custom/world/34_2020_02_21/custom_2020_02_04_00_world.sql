DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_rog_deadly_momentum',
'spell_rog_slice_and_dice',
'spell_rog_sap');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-79121, 'spell_rog_deadly_momentum'),
(5171, 'spell_rog_slice_and_dice'),
(6770, 'spell_rog_sap');

DELETE FROM `spell_proc` WHERE `SpellId` In (84590, -14156, 14177, 58410);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(84590, 8, 0, 0, 0, 0x00000010 | 0x00001000, 1, 0, 8),
(14177, 8, 0, 0, 0, 0x00000010 | 0x00000100 | 0x00000400 | 0x00001000 | 0x00004000 | 0x00010000, 1, 0, 8),
(-14156, 8, 0x00020000 | 0x00100000 | 0x00080000 | 0x00200000, 0x08000000 | 0x00000008 | 0x00000001, 0, 0, 1, 0, 0),
(58410, 8, 0, 0x00080000, 0, 0, 2, 0, 2);
