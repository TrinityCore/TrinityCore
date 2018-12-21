DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_rog_glyph_of_hemorrhage',
'spell_rog_honor_among_thieves');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(56807, 'spell_rog_glyph_of_hemorrhage'),
(-51698, 'spell_rog_honor_among_thieves');

DELETE FROM `spell_proc` WHERE `SpellId` IN (56807, 51698, 51700, 51701, -51698);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(56807, 8, 0x02000000, 0, 0, 0x00000010, 1, 2, 0, 0, 0, 0, 100),
(-51698, 0, 0, 0, 0, 0x00055110, 1, 2, 2, 0, 2000, 0, 0);
