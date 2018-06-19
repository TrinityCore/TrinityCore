DELETE FROM spell_script_names WHERE scriptname = "spell_pal_fervent_martyr";
INSERT INTO spell_script_names VALUES
(196923, "spell_pal_fervent_martyr");

DELETE FROM `spell_proc` WHERE `SpellId` = 196923;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask2`, `SpellPhaseMask`) VALUES
(196923, 10, 1073741824, 1024, 2);
