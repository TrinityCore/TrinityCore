--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 38224;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_shadowmoon_illidari_agent_illusion','spell_shadowmoon_quest_credit_crazed_colossus');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(38224,'spell_shadowmoon_illidari_agent_illusion'),
(38223,'spell_shadowmoon_quest_credit_crazed_colossus');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 19823 AND `SourceId` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19823 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19823,0,0,0,2,0,100,1,0,75,0,0,0,11,37947,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crazed Colossus - Between 0-75% Health - Cast 'Summon Crazed Shardling' (No Repeat)"),
(19823,0,1,0,2,0,100,1,0,50,0,0,0,11,37948,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crazed Colossus - Between 0-50% Health - Cast 'Summon Crazed Shardling' (No Repeat)"),
(19823,0,2,0,2,0,100,1,0,25,0,0,0,11,37949,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crazed Colossus - Between 0-25% Health - Cast 'Summon Crazed Shardling' (No Repeat)"),
(19823,0,3,0,6,0,100,0,0,0,0,0,0,11,38223,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Crazed Colossus - On Death - Cast 'Quest Credit: Crazed Colossus'");
