UPDATE npc_spellclick_spells SET cast_flags = 1 WHERE npc_entry = 100545;

-- Demon Hunter SAI
SET @ENTRY := 100545;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,192262,0,0,0,33,97395,0,0,0,0,0,7,0,0,0,0,0,0,0,"Demon Hunter - On Spellhit '<Spell not found!>' - Quest Credit ''"),
(@ENTRY,0,1,0,8,0,100,0,192262,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Demon Hunter - On Spellhit '<Spell not found!>' - Despawn In 5000 ms"),
(@ENTRY,0,2,0,8,0,100,0,192262,0,0,0,83,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Demon Hunter - On Spellhit '<Spell not found!>' - Remove Npc Flag Spellclick");

UPDATE npc_spellclick_spells SET cast_flags = 1 WHERE npc_entry = 97382;

-- Soul Harvester SAI
SET @ENTRY := 97382;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,73,0,100,0,0,0,0,0,33,97382,0,0,0,0,0,7,0,0,0,0,0,0,0,"Soul Harvester - On Spellclick - Quest Credit ''"),
(@ENTRY,0,1,0,73,0,100,0,0,0,0,0,83,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soul Harvester - On Spellclick - Remove Npc Flag Spellclick"),
(@ENTRY,0,2,0,73,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soul Harvester - On Spellclick - Despawn In 2000 ms");

-- Mardum Executioner SAI
SET @ENTRY := 96279;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+03) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,26,0,100,1,1,10,0,0,87,@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+03,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - In Combat LoS - Run Random Script (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,200827,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mardum Executioner - In Combat - Cast '<Spell not found!>'"),
(@ENTRY*100+01,9,0,0,0,0,100,0,0,0,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - On Script - Say Line 0"),
(@ENTRY*100+02,9,0,0,0,0,100,0,0,0,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - On Script - Say Line 1"),
(@ENTRY*100+03,9,0,0,0,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Mardum Executioner - On Script - Say Line 2");
