DELETE FROM `spell_proc_event` WHERE `entry` IN (49222);
INSERT INTO `spell_proc_event` VALUES (49222, 0, 0, 0, 0, 0, 0, 8+32+128+512+131072, 0, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (13159);
INSERT INTO `spell_proc_event` VALUES (13159, 0, 0, 0, 0, 0, 0, 8+32+128+512+131072, 0, 0, 0, 0, 7);

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='421') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='403') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='51514') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='73920') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='8004') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='1064') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='331') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='77472') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='117014') AND (`spell_effect`='-53817') AND (`type`='0') AND (`hastalent`='0');

DELETE FROM `spell_proc_event` WHERE `entry` IN (53817);
INSERT INTO `spell_proc_event` VALUES (53817, 0, 0, 2+1+128+256+64, 32768, 1048576+65536, 4, 1024+4096+16384+65536, 0, 0, 0, 0, 7);