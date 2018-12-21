DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_sha_frozen_power';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-63373, 'spell_sha_frozen_power');

DELETE FROM `spell_proc` WHERE `SpellId`= -63373;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-63373, 11, 0x80000000, 0, 0, 0x00010000, 1, 2, 0, 16, 0, 0, 100);
