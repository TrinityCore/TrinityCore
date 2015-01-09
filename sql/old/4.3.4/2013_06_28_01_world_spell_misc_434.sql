DELETE FROM `spell_script_names` WHERE `ScriptName`="spell_pal_eye_for_an_eye";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(9799, "spell_pal_eye_for_an_eye"),
(25988, "spell_pal_eye_for_an_eye");

DELETE FROM `spell_proc_event` WHERE `entry` IN (9799,25988);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(9799, 0, 0, 0, 0, 0, 0x10000, 0, 0, 0, 0),
(25988, 0, 0, 0, 0, 0, 0x10000, 0, 0, 0, 0);
