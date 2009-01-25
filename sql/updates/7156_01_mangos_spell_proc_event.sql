ALTER TABLE db_version CHANGE COLUMN required_7150_01_mangos_playercreateinfo_spell required_7156_01_mangos_spell_proc_event bit;

-- (44401) Missile Barrage ()
DELETE FROM `spell_proc_event` WHERE `entry` IN (44401);
INSERT INTO `spell_proc_event` VALUES (44401, 0x00, 3, 0x00200000, 0x00000000, 0x00000000, 0x00000000, 0x00000FFF, 0.000000, 0.000000, 0);
