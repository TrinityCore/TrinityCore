-- Slag Behemoth Blackrock Foundry SAI
SET @ENTRY := 77504;
UPDATE creature_template SET `AIName`='SmartAI' WHERE entry=77504;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13000,15000,11,156345,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slag Behemoth - In Combat - Cast Ignite Searcher."),
(@ENTRY,0,1,0,0,0,100,0,11000,12000,11000,12000,11,156348,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slag Behemoth - In Combat - Cast Volcanic Bomb Searcher."),
(@ENTRY,0,2,0,0,0,100,0,30000,32000,34000,36000,11,156446,1,0,0,0,0,1,0,0,0,0,0,0,0,"Slag Behemoth - In Combat - Cast Blast Wave.");
/* (@ENTRY,0,3,0,0,0,100,0,30000,32000,34000,36000,11,159750,1,0,0,0,0,1,0,0,0,0,0,0,0,"Slag Behemoth - In Combat - Cast Blast Waves (Mythic only)"); */

-- spell_gen_slag_behemoth_blast_waves
 DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_slag_behemoth_blast_waves';
 INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
 (159750,'spell_gen_slag_behemoth_blast_waves');

-- spell_gen_slag_behemoth_blast_waves_dummy_spells
 DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_slag_behemoth_blast_waves_dummy_spells';
 INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
 (159749,'spell_gen_slag_behemoth_blast_waves_dummy_spells'),
 (159760,'spell_gen_slag_behemoth_blast_waves_dummy_spells');
