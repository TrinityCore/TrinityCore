DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_crash_lightning';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(187874,'spell_sha_crash_lightning');

DELETE FROM `spell_proc_event` WHERE `entry`=187878;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`spellFamilyMask3`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(187878,0,11,0,0x01000000,4,0,0,0,0,0,0);
