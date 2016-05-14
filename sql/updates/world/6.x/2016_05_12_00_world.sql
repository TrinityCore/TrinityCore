DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_lightning_shield';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(324,'spell_sha_lightning_shield');

DELETE FROM `spell_proc_event` WHERE `entry`=324;
INSERT INTO `spell_proc_event` (`entry`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`cooldown`) VALUES
(324,0x00000000,0x00000000,0x00000000,0x00000000,0);
