DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_sha_earth_shock',
'spell_sha_fulmination');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95774, 'spell_sha_fulmination');

DELETE FROM `spell_proc` WHERE `SpellId`= 95774;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(95774, 11, 0x00100000, 0, 0, 0x00010000, 1, 1, 1 | 2 | 4 | 8 | 512 | 1024 | 2048, 0, 0, 1, 100);
