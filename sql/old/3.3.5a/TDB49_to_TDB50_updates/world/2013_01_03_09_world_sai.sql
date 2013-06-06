-- Servant of the Throne [SAI]
SET @ENTRY := 36724;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,3,0,0,0,100,30,5000,7000,5000,9000,11,70980,0,0,0,0,0,4,0,0,0,0,0,0,0, 'Cast Web Wrap'),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,6000,6000,12000,11,71029,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Cast Glacial Blast');
-- Ancient Skeletal Soldier
SET @ENTRY := 37012;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,3,0,0,0,100,30,5000,7000,5000,9000,11,70980,0,0,0,0,0,4,0,0,0,0,0,0,0, 'Cast Web Wrap'),
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,6000,6000,8000,11,70964,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Cast Shield Bash(70964)');
-- Nerub'ar Broodkeeper
SET @ENTRY := 36725;
SET @SOURCETYPE :=0;
UPDATE creature_template SET AIName='SmartAI', ScriptName='' WHERE entry=@ENTRY;
DELETE FROM creature_ai_scripts WHERE creature_id=@ENTRY;
DELETE FROM smart_scripts WHERE source_type=0 AND entryorguid=@ENTRY;
INSERT INTO smart_scripts (entryorguid,source_type,id,link,event_type,event_phase_mask,event_chance,event_flags,event_param1,event_param2,event_param3,event_param4,action_type,action_param1,action_param2,action_param3,action_param4,action_param5,action_param6,target_type,target_param1,target_param2,target_param3,target_x,target_y,target_z,target_o,comment) VALUES
(@ENTRY,@SOURCETYPE,1,0,10,0,100,30,1,60,1000,1000,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Nerub''ar Broodkeeper - On LOS - Zone Combat Pulse'),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,30,5000,7000,5000,9000,11,70965,0,0,0,0,0,4,0,0,0,0,0,0,0, 'Nerub''ar Broodkeeper - In Combat - Cast Crypt Scarabs'),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,30,5000,7000,5000,9000,11,70980,0,0,0,0,0,4,0,0,0,0,0,0,0, 'Nerub''ar Broodkeeper - In Combat - Cast Web Wrap'),
(@ENTRY,@SOURCETYPE,4,0,14,0,100,30,5000,30,8000,13000,11,36725,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Nerub''ar Broodkeeper - In Combat - Cast Dark Mending on Friendlies');
-- Deathbound Ward
SET @ENTRY := 37007;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,6000,6000,8000,11,71021,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Saber Lash'),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,6000,8000,6000,12000,11,71022,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Disrupting Shout');
-- Entrance Mobs End
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Starting Mobs infront Lady Deathwhisper
-- Deathspeaker Zealot
SET @ENTRY := 36808;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,6000,6000,8000,11,69492,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Shadow Cleave');
-- Deathspeaker Servant
SET @ENTRY := 36805;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,6000,6000,8000,11,69576,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Chaos Bolt'),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,6000,6000,8000,11,69405,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Consuming Shadows'),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,3000,6000,6000,8000,11,69404,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Curse of Agony');
-- Deathspeaker Attendant
SET @ENTRY := 36811;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,6000,6000,8000,11,69387,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Cast Shadow Bolt'),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,3000,6000,6000,8000,11,69355,0,0,0,0,0,18,15,0,0,0.0,0.0,0.0,0.0,'Cast Shadow Nova on 15 yard distance');
-- Deathspeaker Disciple
DELETE FROM smart_scripts WHERE entryorguid = 36807 AND source_type = 0;
SET @ENTRY := 36807;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, @SOURCETYPE, 0, 0, 0, 0, 100, 30, 0, 3000, 4000, 6000, 11, 69387, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Deathspeaker Disciple - Cast Shadow Bolt'),
(@ENTRY, @SOURCETYPE, 1, 0, 16, 0, 100, 30, 69391, 40, 15000, 20000, 11, 69391, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Deathspeaker Disciple - Cast Dark Blessing'),
(@ENTRY, @SOURCETYPE, 2, 0, 14, 0, 100, 30, 90000, 40, 15000, 20000, 11, 69389, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Deathspeaker Disciple - Cast Shadow Mend');
-- Deathspeaker High Priest [SAI]
SET @ENTRY := 36829;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName='SmartAI' WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,3000,6000,10000,15000,11,69483,2,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,'Cast Dark Reckoning'),
(@ENTRY,@SOURCETYPE,1,0,32,0,100,1,0,10000,0,0,11,69491,2,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Cast Aura of Darkness On Self'); -- when combat starts
