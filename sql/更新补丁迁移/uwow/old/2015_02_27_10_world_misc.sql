DELETE FROM `spell_proc_event` WHERE `entry` IN (93098);
INSERT INTO `spell_proc_event` VALUES (93098, 0, 0, 0, 0, 0, 0, 0, 0x0000047B, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (84840);
INSERT INTO `spell_proc_event` VALUES (84840, 0, 0, 0, 0, 0, 0, 0, 0x0000047B, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (84839);
INSERT INTO `spell_proc_event` VALUES (84839, 0, 0, 0, 0, 0, 0, 0, 0x0000047B, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (93099);
INSERT INTO `spell_proc_event` VALUES (93099, 0, 0, 0, 0, 0, 0, 0, 0x0000047B, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (120267);
INSERT INTO `spell_proc_event` VALUES (120267, 0, 0, 0, 0, 0, 0, 0, 0x0000047B, 0, 0, 0, 7);

UPDATE `spell_trigger` SET `aura`='7376' WHERE (`spell_id`='93098') AND (`spell_trigger`='132365') AND (`option`='24') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');
UPDATE `spell_trigger` SET `aura`='115069' WHERE (`spell_id`='120267') AND (`spell_trigger`='132365') AND (`option`='24') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');
UPDATE `spell_trigger` SET `aura`='48263' WHERE (`spell_id`='93099') AND (`spell_trigger`='132365') AND (`option`='24') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-7376', '-132365', 'Remove Vengeance');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-115069', '-132365', 'Remove vengeance');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-48263', '-132365', 'Remove vengeance');

UPDATE `spell_linked_spell` SET `spell_trigger`='-5487' WHERE (`spell_trigger`='768') AND (`spell_effect`='-132365') AND (`type`='0') AND (`hastalent`='0');