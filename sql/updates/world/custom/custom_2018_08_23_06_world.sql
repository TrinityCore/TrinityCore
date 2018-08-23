DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_sha_fulmination',
'spell_sha_earth_shock');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(8042, 'spell_sha_earth_shock');

DELETE FROM `spell_proc` WHERE `SpellId`= 95774;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(95774, 11, 0x00100000, 0, 0, 0x00010000, 1, 1, 0, 16, 0, 1, 100);
