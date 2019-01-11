DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_trap_launcher';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77769, 'spell_hun_trap_launcher');

DELETE FROM `spell_proc` WHERE `spellId`= 77769;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(77769, 9, 0x00000080, 0x0, 0x0, 0x00015550, 0x4, 0x1, 0x0, 0x0);
