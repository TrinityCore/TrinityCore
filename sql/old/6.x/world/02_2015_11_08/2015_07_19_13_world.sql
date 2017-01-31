-- Steelsnout SAI
SET @STEELSNOUT      := 92887;  -- Steelsnout
SET @SPELL_CORNERED  := 161128; -- Cornered
SET @SPELL_HEAVE     := 162083; -- Heave
SET @SPELL_ENRAGE    := 172781; -- Enrage
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@STEELSNOUT;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@STEELSNOUT AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@STEELSNOUT,0,0,0,0,0,100,0,30800,31900,43700,44100,11,@SPELL_CORNERED,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steelsnout - In Combat - Cornered"),
(@STEELSNOUT,0,1,0,0,0,100,0,14200,14600,24200,24600,11,@SPELL_HEAVE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steelsnout - In Combat - Heave"),
(@STEELSNOUT,0,2,0,0,0,100,0,13300,16100,16000,21800,11,@SPELL_ENRAGE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steelsnout - In Combat - Enrage");
