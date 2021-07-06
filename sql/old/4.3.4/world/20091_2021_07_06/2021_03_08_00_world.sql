DELETE FROM `spell_proc` WHERE `SpellId` IN (-83340, 83359, 89388);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Charges`) VALUES
(-83340, 9, 0x800 | 0x20000, 0x80000000, 0x0, 0, 1, 2, 2, 0),
(83359, 9, 0x80000, 0x0, 0x0, 0x10, 1, 1, 0, 1),
(89388, 9, 0x80000, 0x0, 0x0, 0x10, 1, 1, 0, 1);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_sic_em';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-83340, 'spell_hun_sic_em');
