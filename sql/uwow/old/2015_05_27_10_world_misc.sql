DELETE FROM `spell_proc_event` WHERE `entry` IN (137639);
INSERT INTO `spell_proc_event` VALUES (137639, 0, 0, 4+1024+2+32, 2147483648+128+8388608+1, 8, 0, 0, 0, 0, 0, 0, 7);

DELETE FROM `spell_script_names` WHERE (`spell_id`='115098') AND (`ScriptName`='spell_monk_clone_cast');
DELETE FROM `spell_script_names` WHERE (`spell_id`='117952') AND (`ScriptName`='spell_monk_clone_cast');
DELETE FROM `spell_script_names` WHERE (`spell_id`='100784') AND (`ScriptName`='spell_monk_clone_cast');
DELETE FROM `spell_script_names` WHERE (`spell_id`='100787') AND (`ScriptName`='spell_monk_clone_cast');
DELETE FROM `spell_script_names` WHERE (`spell_id`='107428') AND (`ScriptName`='spell_monk_clone_cast');
DELETE FROM `spell_script_names` WHERE (`spell_id`='113656') AND (`ScriptName`='spell_monk_clone_cast');