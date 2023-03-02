DELETE FROM `spell_proc_event` WHERE `entry` IN (108283);
INSERT INTO `spell_proc_event` VALUES (108283, 0, 0, 1+2+1048576+2147483648+268435456+128+64+256, 4096, 65536+16, 4, 0, 1, 0, 100, 0, 7);

DELETE FROM `spell_script_names` WHERE (`spell_id`='108283') AND (`ScriptName`='spell_sha_echo_of_the_elements');