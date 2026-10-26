--
UPDATE `creature_template` SET `flags_extra` = `flags_extra`&~2 WHERE `entry` = 15514;
UPDATE `creature` SET `spawntimesecs` = 120 WHERE `id` = 15514;

UPDATE `spell_script_names` SET `ScriptName` = 'spell_buru_egg_explosion' WHERE `ScriptName` = 'spell_egg_explosion';

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (15521,15964);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15521,15964) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15521,0,0,0,37,0,100,0,0,0,0,0,0,116,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hive'Zara Hatchling - On AI Initialize - Set Corpse Delay"),
(15521,0,1,0,11,0,100,0,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hive'Zara Hatchling - On Spawn - Set In Combat With Zone"),

(15964,0,0,0,11,0,100,0,0,0,0,0,0,11,26646,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Buru Egg Trigger - On Spawn - Cast 'Buru Egg Trigger Effect'");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_buru_cancel_creeping_plague';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(27027, 'spell_buru_cancel_creeping_plague');
