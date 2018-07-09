DELETE FROM `spell_proc` WHERE `SpellId`= -51525;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-51525, 11, 0x00000000, 0x01000010, 0x00020000 | 0x00000004, 0, 1, 1, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_sha_static_shock';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-51525, 'spell_sha_static_shock');
