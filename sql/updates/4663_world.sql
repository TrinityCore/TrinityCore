DELETE FROM `spell_proc_event` WHERE `entry` = 50453;
INSERT INTO `spell_proc_event` (`entry`, `procFlags`, `CustomChance`) VALUES ('50453', '0x00000004', '100');

DELETE FROM `creature_template_addon` WHERE `entry` = 28017;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES ('28017', '50453 0');