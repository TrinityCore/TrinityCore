DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_rog_serrated_blades';

DELETE FROM `spell_proc` WHERE `SpellId`= 36563;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(36563, 8, 0x00000200 | 0x00000100, 0, 0, 0, 1, 1, 0, 0);
