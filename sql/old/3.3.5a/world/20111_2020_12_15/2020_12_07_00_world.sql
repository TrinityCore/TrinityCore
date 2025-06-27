--
DELETE FROM `spell_script_names` WHERE `spell_id` = 25952 AND `ScriptName` = "spell_gen_despawn_self";
UPDATE `spell_scripts` SET `datalong` = 3000, `Comment` = "Reindeer Dust Effect - On Effect Hit (Dummy) - Caster - Delayed Despawn" WHERE `id` = 25952;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 15664 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1566400 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15664,0,0,1,62,0,100,0,6763,0,0,0,0,11,25952,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Metzen the Reindeer - On Gossip Option 0 Selected - Cast 'Reindeer Dust Effect'"),
(15664,0,1,0,61,0,100,0,0,0,0,0,0,33,15664,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Metzen the Reindeer - On Link - Quest Credit 'Metzen the Reindeer'");
