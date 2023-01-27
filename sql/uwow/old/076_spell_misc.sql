DELETE FROM `spell_script_names` WHERE (`spell_id`='53385') AND (`ScriptName`='spell_mastery_hand_of_light');
DELETE FROM `spell_script_names` WHERE (`spell_id`='53595') AND (`ScriptName`='spell_mastery_hand_of_light');
DELETE FROM `spell_script_names` WHERE (`spell_id`='24275') AND (`ScriptName`='spell_mastery_hand_of_light');
DELETE FROM `spell_script_names` WHERE (`spell_id`='35395') AND (`ScriptName`='spell_mastery_hand_of_light');
DELETE FROM `spell_script_names` WHERE (`spell_id`='85256') AND (`ScriptName`='spell_mastery_hand_of_light');
DELETE FROM `spell_proc_event` WHERE `entry` IN (76672);
INSERT INTO `spell_proc_event` VALUES (76672, 0, 0, 0, 262144+32768+131072, 8192, 0, 0, 0, 0, 100, 0, 7);