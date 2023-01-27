DELETE FROM `spell_proc_event` WHERE `entry` IN (44448);
INSERT INTO `spell_proc_event` VALUES (44448, 4, 3, 4194304+1+16, 67108864+4096, 2097152, 0, 0, 0x00000C03, 0, 0, 0, 7);

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hitmask`, `comment`) VALUES ('33876', '34071', '1', 'Mangle combo point');

DELETE FROM `spell_proc_event` WHERE `entry` IN (14190);
INSERT INTO `spell_proc_event` VALUES (14190, 0, 8, 512, 6, 256, 0, 0, 2, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (13877);
INSERT INTO `spell_proc_event` VALUES (13877, 0, 8, 2+131072+536870912+512, 1+8388608+268435456, 2+2048+65536+32768, 0, 20, 2147483648, 0, 100, 0, 7);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('51723', 'spell_rog_fan_of_knives_cp');
INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `comments`) VALUES ('51723', '13', '13', '10 yards');

INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `resizeType`, `count`, `maxcount`, `comments`) VALUES ('118605', '30', '1', '1', '1', 'Guard');

INSERT INTO `spell_pet_auras` (`petEntry`, `spellId`, `option`, `target`, `comment`) VALUES ('61146', '126119', '5', '1', 'Святилище быка');

UPDATE `spell_trigger` SET `target`='7' WHERE (`spell_id`='124502') AND (`spell_trigger`='124503') AND (`option`='0') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');
UPDATE `spell_trigger` SET `target`='7' WHERE (`spell_id`='124502') AND (`spell_trigger`='124506') AND (`option`='0') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `target`, `removeMask`, `comment`) VALUES ('-66', '32612', '3', '16', 'Invisibility');