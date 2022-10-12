DELETE FROM `spell_proc_event` WHERE `entry` IN (12846);
INSERT INTO `spell_proc_event` VALUES (12846, 4, 3, 1+4194304+16, 4096, 2097152, 0, 0, 0, 0, 100, 0, 7);

DELETE FROM `spell_script_names` WHERE (`spell_id`='133') AND (`ScriptName`='spell_mastery_ignite');
DELETE FROM `spell_script_names` WHERE (`spell_id`='2948') AND (`ScriptName`='spell_mastery_ignite');
DELETE FROM `spell_script_names` WHERE (`spell_id`='11366') AND (`ScriptName`='spell_mastery_ignite');
DELETE FROM `spell_script_names` WHERE (`spell_id`='44614') AND (`ScriptName`='spell_mastery_ignite');
DELETE FROM `spell_script_names` WHERE (`spell_id`='108853') AND (`ScriptName`='spell_mastery_ignite');