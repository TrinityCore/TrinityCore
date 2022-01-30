DELETE FROM `spell_proc` WHERE `SpellId` IN (200071, 216251);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellPhaseMask`, `HitMask`, `Chance`) VALUES
(200071, 0x0, 11, 0x00000080, 0x00000400, 0x00010000, 0x0,  0x00004400, 0x1, 0x0, 100),
(216251, 0x0, 11, 0x00000080, 0x00000400, 0x00010000, 0x0,  0x00004400, 0x1, 0x0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_undulation_passive', 'spell_sha_undulation_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(200071, 'spell_sha_undulation_passive'),
(216251, 'spell_sha_undulation_proc');
