DELETE FROM `spell_proc` WHERE `SpellId` = 210714;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `SpellPhaseMask`) VALUES
(210714, 11, 0x80000000, 0x01000080, 0x00000000, 0x00000000, 0x1);

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_sha_icefury';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (210714, 'spell_sha_icefury');
