--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_bear_flank_master' WHERE `ScriptName` = 'spell_q13011_bear_flank_master';

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bear_flank_fail';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(56569,'spell_bear_flank_fail');

DELETE FROM `creature_text` WHERE `CreatureID` = 30292;
UPDATE `smart_scripts` SET `action_param2` = 0 WHERE `entryorguid` = 30292 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30292 AND `source_type` = 0 AND `id` = 2;

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30366 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3036600 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30366,0,0,0,11,0,100,0,0,0,0,0,0,80,3036600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lure Jormuttar Bunny - On Spawn - Run Script"),

(3036600,9,0,0,0,0,100,0,0,0,0,0,0,11,56577,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lure Jormuttar Bunny - On Script - Cast 'Summon Flank'"),
(3036600,9,1,0,0,0,100,0,5000,5000,0,0,0,12,30340,4,120000,0,0,0,8,0,0,0,0,7312.9766,-2048.7727,761.4259,2.775073528289794921,"Lure Jormuttar Bunny - On Script - Summon Creature 'Jormuttar'"),
(3036600,9,2,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lure Jormuttar Bunny - On Script - Despawn");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30340 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30340,0,0,0,0,0,100,0,0,0,3000,5000,0,11,61597,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Jormuttar - In Combat CMC - Cast 'Acid Spit'"),
(30340,0,1,0,0,0,100,0,5000,10000,10000,15000,0,11,61598,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jormuttar - In Combat - Cast 'Sweep'");
