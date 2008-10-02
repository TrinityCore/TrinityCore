DELETE FROM `spell_chain` WHERE `spell_id` = 27170;
INSERT INTO `spell_chain` VALUES (27170,20920,20375,6);
DELETE FROM `spell_proc_event` WHERE `entry` = 27170;
INSERT INTO `spell_proc_event` VALUES (27170, 0, 0, 0, 0, 1, 7);
