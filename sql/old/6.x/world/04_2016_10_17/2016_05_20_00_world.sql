DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_item_t18_elemental_4p_bonus';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(189063,'spell_sha_item_t18_elemental_4p_bonus');

DELETE FROM `spell_proc_event` WHERE `entry`=88766;
INSERT INTO `spell_proc_event` (`entry`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`cooldown`) VALUES
(88766,0x00100003,0x00001000,0x00000000,0x00000004,0);
