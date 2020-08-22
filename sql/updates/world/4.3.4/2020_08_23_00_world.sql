DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_hun_fervor',
'spell_hun_killing_streak',
'spell_hun_crouching_tiger_hidden_chimera');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82726, 'spell_hun_fervor'),
(-82748, 'spell_hun_killing_streak'),
(-82898, 'spell_hun_crouching_tiger_hidden_chimera');

DELETE FROM `spell_proc` WHERE `SpellId` IN (-82748, 94006, 94007, -82898);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask1`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Chance`, `AttributesMask`) VALUES
(-82748, 9, 0x800, 0x00055554, 1, 2, 0, 100, 0x20),
(94006, 9,  0x800, 0, 4, 2, 0, 0, 0x8 | 0x20),
(94007, 9,  0x800, 0, 4, 2, 0, 0, 0x8 | 0x20);

INSERT INTO `spell_proc` (`SpellId`, `Cooldown`) VALUES
(-82898, 2000);
