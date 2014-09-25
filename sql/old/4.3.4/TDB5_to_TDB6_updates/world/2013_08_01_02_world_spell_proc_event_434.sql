DELETE FROM `spell_proc_event` WHERE `entry`=-16880;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(-16880, 0, 7, 0x200042, 0, 0, 0, 0, 0, 0, 60);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (48517,48518);
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(48517,'spell_dru_eclipse_solar'),
(48518,'spell_dru_eclipse_lunar');
