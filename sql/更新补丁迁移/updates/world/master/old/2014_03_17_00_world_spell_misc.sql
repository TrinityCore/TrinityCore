DELETE FROM `spell_script_names` WHERE (`spell_id`='172') AND (`ScriptName`='spell_warl_nightfall');

DELETE FROM `spell_proc_event` WHERE `entry` IN (108558);
INSERT INTO `spell_proc_event` VALUES (108558, 0, 0, 2, 0, 0, 0, 0, 0, 0, 10, 0, 7);