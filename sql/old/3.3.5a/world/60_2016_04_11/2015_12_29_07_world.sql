-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16544, 16545) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16545,0,0,0,0,0,100,3,0,0,0,0,11,30007,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast 'Spatial Distortion' (No Repeat) (Normal Dungeon)"),
(16545,0,1,0,0,0,100,2,4000,9000,5000,10000,11,37161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast 'Arcane Volley' (Normal Dungeon)"),
(16545,0,2,0,0,0,100,2,8000,10000,10000,15000,11,30036,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast 'Steal Magic' (Normal Dungeon)"),
(16545,0,3,0,0,0,100,2,6000,12000,16000,16000,11,30039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast 'Transference' (Normal Dungeon)"),
(16544,0,0,0,0,0,100,2,4000,7000,4000,8000,11,30014,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Thief - In Combat - Cast 'Cleave' (Normal Dungeon)"),
(16544,0,1,0,5,0,100,2,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Thief - On Killed Unit - Say Line 0"),
(16544,0,2,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Thief - On Just Died - Say Line 1"),
(16544,0,3,0,0,0,100,3,0,0,0,0,75,29982,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Thief - In Combat - Add Aura 'Spatial Distortion' (No Repeat) (Normal Dungeon)"),
(16544,0,4,0,0,0,100,2,15000,15000,20000,20000,11,30013,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Thief - In Combat - Cast 'Disarm' (Normal Dungeon)"),
(16544,0,5,0,31,0,100,2,30013,0,1,1,13,0,100,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Thief - On Target Spellhit 'Disarm' - Set Single Threat 0-100 (Normal Dungeon)");
