DELETE FROM `spell_proc_check` WHERE (`entry`='121153') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='111240') AND (`hastalent`='0') AND (`powertype`='0') AND (`dmgclass`='0');

DELETE FROM `spell_proc_event` WHERE `entry` IN (121153);
INSERT INTO `spell_proc_event` VALUES (121153, 0, 0, 0, 0, 0x00000100, 0, 16, 0, 0, 100, 0, 7);