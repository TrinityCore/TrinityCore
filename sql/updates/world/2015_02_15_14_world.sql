-- 
DELETE FROM `creature_addon` WHERE `guid` IN (127436, 127437);
DELETE FROM `linked_respawn` WHERE `guid` IN (127436, 127437);
DELETE FROM `spell_script_names` WHERE  `spell_id`=8283 AND `ScriptName`='spell_snufflenose_command';
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=26206;
