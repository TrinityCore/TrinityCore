DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='19750') AND (`spell_effect`='-54149') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_proc_event` WHERE `entry` IN (54149);
INSERT INTO `spell_proc_event` VALUES (54149, 0, 10, 0x80000000, 0, 0x00000600, 0, 0, 0, 0, 100, 0, 7);