DELETE FROM `spell_proc_event` WHERE `entry` IN (79096);
INSERT INTO `spell_proc_event` VALUES (79096, 0, 0, 8388608+8519680+1048576, 0, 8192, 0, 0, 0, 0, 100, 0, 7);

DELETE FROM `spell_script_names` WHERE (`spell_id`='1943') AND (`ScriptName`='spell_rog_restless_blades');
DELETE FROM `spell_script_names` WHERE (`spell_id`='2098') AND (`ScriptName`='spell_rog_restless_blades');
DELETE FROM `spell_script_names` WHERE (`spell_id`='121411') AND (`ScriptName`='spell_rog_restless_blades');