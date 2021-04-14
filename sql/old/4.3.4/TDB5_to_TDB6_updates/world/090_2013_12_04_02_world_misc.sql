-- Terrorspark SAI
SET @ENTRY := 10078;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3400,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Combat - Cast Fireball"),
(@ENTRY,0,1,0,0,0,100,0,4800,29300,2300,9700,11,11968,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Combat - Cast Fire Shield"),
(@ENTRY,0,2,3,0,0,100,0,10900,23300,33000,53400,11,15710,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Combat - Cast Summon Flamekin Torcher"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,15711,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Runekeeper - Combat - Cast Summon Summon Flamekin Rager");
