DELETE FROM `spell_proc` WHERE `SpellId`= -53241;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-53241, 9, 0x00000800, 0, 0x00000001, 0x00000100, 1, 2, 0, 0, 0, 0, 100);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_hun_marked_for_death';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-53241, 'spell_hun_marked_for_death');
