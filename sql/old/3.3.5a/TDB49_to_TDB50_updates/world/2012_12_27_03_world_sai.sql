-- Shadowsword Fury Mage SAI
SET @ENTRY := 25799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Fury Mage - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,15000,30000,11,46101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Fury Mage - In Combat - Cast Fel Fireball"),
(@ENTRY,0,2,0,0,0,100,2,25000,25000,45000,55000,11,46102,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Fury Mage - In Combat - Cast Spell Fury");

-- Void Spawn SAI
SET @ENTRY := 25824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Spawn - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,25000,35000,11,46082,0,0,0,0,0,5,0,0,0,0,0,0,0,"Void Spawn - In Combat - Cast Shadow Bolt Volley");

-- Shadowsword Commander SAI
SET @ENTRY := 25837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Commander - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,14,0,100,2,0,15,45000,45000,11,46763,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowsword Commander - On Friendly Unit At 0 - 15% Health - Cast Battle Shout"),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,20000,35000,11,46762,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Commander - In Combat - Cast Shield Slam");

-- Volatile Fiend SAI
SET @ENTRY := 25851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volatile Fiend - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,30000,40000,11,47287,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volatile Fiend - In Combat - Cast Burning Destruction"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,46308,0,0,0,0,0,1,0,0,0,0,0,0,0,"Volatile Fiend - On Aggro - Cast Burning Winds"),
(@ENTRY,0,3,0,0,0,100,2,15000,15000,25000,40000,11,45779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Volatile Fiend - In Combat - Cast Felfire Fission");

-- Sunblade Dragonhawk SAI
SET @ENTRY := 25867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Dragonhawk - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,7500,7500,20000,30000,11,47251,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Dragonhawk - In Combat - Cast Flame Breath");

-- Bloodwarder Legionnaire SAI
SET @ENTRY := 20031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Legionnaire - On Aggro - Cast Dual Wield"),
(@ENTRY,0,1,0,0,0,85,2,10000,10000,27000,27000,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Legionnaire - In Combat - Cast Whirlwind"),
(@ENTRY,0,2,0,0,0,85,2,20000,20000,25000,25000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Legionnaire - In Combat - Cast Cleave"),
(@ENTRY,0,3,0,0,0,85,2,6000,6000,22000,22000,11,35949,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Legionnaire - In Combat - Cast Bloodthirst");

-- Bloodwarder Vindicator SAI
SET @ENTRY := 20032;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,8000,8000,20000,40000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Vindicator - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,1,0,12,0,100,2,0,20,15000,15000,11,37251,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Vindicator - On Target At 0 - 20% HP - Cast Hammer of Wrath"),
(@ENTRY,0,2,0,14,0,100,2,0,200,20000,20000,11,37254,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodwarder Vindicator - On Friendly Unit At 0 - 200% Health - Cast Flash of Light"),
(@ENTRY,0,3,0,14,0,100,2,0,200,60000,60000,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodwarder Vindicator - On Friendly Unit At 0 - 200% Health - Cast Cleanse"),
(@ENTRY,0,4,0,2,0,100,2,0,30,35000,35000,11,37254,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Vindicator - At 30% HP - Cast Flash of Light");

-- Astromancer SAI
SET @ENTRY := 20033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,35915,0,0,0,0,0,1,0,0,0,0,0,0,0,"Astromancer - On Aggro - Cast Molten Armor"),
(@ENTRY,0,1,0,0,0,85,2,19000,19000,25000,25000,11,37109,0,0,0,0,0,2,0,0,0,0,0,0,0,"Astromancer - In Combat - Cast Fireball Volley"),
(@ENTRY,0,2,0,0,0,75,2,25000,25000,20000,20000,11,37110,0,0,0,0,0,2,0,0,0,0,0,0,0,"Astromancer - In Combat - Cast Fire Blast");

-- Star Scryer SAI
SET @ENTRY := 20034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,15000,15000,20000,20000,11,37122,0,0,0,0,0,2,0,0,0,0,0,0,0,"Star Scryer - In Combat - Cast Domination"),
(@ENTRY,0,1,0,0,0,100,2,25000,25000,350000,350000,11,37124,0,0,0,0,0,2,0,0,0,0,0,0,0,"Star Scryer - In Combat - Cast Starfall"),
(@ENTRY,0,2,0,0,0,75,2,30000,30000,25000,25000,11,37126,0,0,0,0,0,2,0,0,0,0,0,0,0,"Star Scryer - In Combat - Cast Arcane Blast");

-- Bloodwarder Marshal SAI
SET @ENTRY := 20035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Marshal - On Aggro - Cast Dual Wield"),
(@ENTRY,0,1,0,0,0,75,2,10000,10000,29000,29000,11,15589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Marshal - In Combat - Cast Whirlwind"),
(@ENTRY,0,2,0,0,0,85,2,6000,6000,22000,22000,11,35949,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Marshal - In Combat - Cast Bloodthirst"),
(@ENTRY,0,3,0,0,0,85,2,20000,20000,25000,25000,11,34996,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Marshal - In Combat - Cast Uppercut");

-- Bloodwarder Squire SAI
SET @ENTRY := 20036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,6500,6500,20000,40000,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Squire - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,1,0,12,0,100,2,0,20,15000,15000,11,37255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Squire - On Target At 0 - 20% HP - Cast Hammer of Wrath"),
(@ENTRY,0,2,0,14,0,100,2,0,200,20000,20000,11,37254,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodwarder Squire - On Friendly Unit At 0 - 200% Health - Cast Flash of Light"),
(@ENTRY,0,3,0,14,0,100,2,0,200,60000,60000,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodwarder Squire - On Friendly Unit At 0 - 200% Health - Cast Cleanse"),
(@ENTRY,0,4,0,2,0,100,2,0,30,35000,35000,11,37254,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Squire - At 30% HP - Cast Flash of Light");

-- Tempest Falconer SAI
SET @ENTRY := 20037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,0,200,25000,25000,11,37318,0,0,0,0,0,7,0,0,0,0,0,0,0,"Tempest Falconer - On Friendly Unit At 0 - 200% Health - Cast Fire Shield"),
(@ENTRY,0,1,0,11,0,100,3,0,0,0,0,79,45,180,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest Falconer - On Respawn - Set Ranged Movement"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,12000,17000,11,39079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest Falconer - In Combat - Cast Shoot"),
(@ENTRY,0,3,0,0,0,100,2,18000,18000,18000,28000,11,37154,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest Falconer - In Combat - Cast Immolation Arrow"),
(@ENTRY,0,4,0,0,0,100,2,5000,9000,6000,11000,11,37317,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest Falconer - In Combat - Cast Knockback");

-- Phoenix-Hawk Hatchling SAI
SET @ENTRY := 20038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15000,15000,35000,50000,11,37160,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phoenix-Hawk Hatchling - In Combat - Cast Silence"),
(@ENTRY,0,1,0,0,0,100,2,7500,7500,25000,35000,11,37319,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phoenix-Hawk Hatchling - In Combat - Cast Wing Buffet");

-- Crimson Hand Blood Knight SAI
SET @ENTRY := 20049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,25000,50000,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,1,0,12,0,100,2,0,20,15000,15000,11,37259,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - On Target At 0 - 20% HP - Cast Hammer of Wrath"),
(@ENTRY,0,2,0,14,0,100,2,0,200,35000,35000,11,37257,0,0,0,0,0,7,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - On Friendly Unit At 0 - 200% Health - Cast Flash of Light"),
(@ENTRY,0,3,0,0,0,100,2,60000,60000,120000,160000,11,37257,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - In Combat - Cast Flash of Light"),
(@ENTRY,0,4,0,14,0,100,2,0,0,40000,40000,11,37260,0,0,0,0,0,7,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - On Friendly Unit At 0 - 0% Health - Cast Renew"),
(@ENTRY,0,5,0,14,0,100,2,0,0,60000,60000,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - On Friendly Unit At 0 - 0% Health - Cast Cleanse");

-- Chaos Gazer SAI
SET @ENTRY := 25595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chaos Gazer - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,15000,15000,11,46290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chaos Gazer - In Combat - Cast Tentacle Sweep"),
(@ENTRY,0,2,0,0,0,100,2,20000,20000,30000,45000,11,46288,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chaos Gazer - In Combat - Cast Petrify"),
(@ENTRY,0,3,0,0,0,100,3,0,0,60000,60000,11,46291,0,0,0,0,0,6,0,0,0,0,0,0,0,"Chaos Gazer - In Combat - Cast Drain Life");

-- Oblivion Mage SAI
SET @ENTRY := 25597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oblivion Mage - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,25000,35000,11,46279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oblivion Mage - In Combat - Cast Flame Buffet"),
(@ENTRY,0,2,0,0,0,100,2,20000,20000,20000,35000,11,46280,0,0,0,0,0,6,0,0,0,0,0,0,0,"Oblivion Mage - In Combat - Cast Polymorph");

-- Cataclysm Hound SAI
SET @ENTRY := 25599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cataclysm Hound - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,20000,35000,11,46292,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cataclysm Hound - In Combat - Cast Cataclysm Breath"),
(@ENTRY,0,2,0,2,0,100,3,0,20,0,0,11,47399,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cataclysm Hound - At 20% HP - Cast Enrage");

-- Shadowsword Berserker SAI
SET @ENTRY := 25798;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Berserker - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,20000,20000,20000,35000,11,46160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Berserker - In Combat - Cast Flurry");

-- Shadowsword Guardian SAI
SET @ENTRY := 25508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Guardian - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,20000,30000,11,46239,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Guardian - In Combat - Cast Bear Down");

-- Priestess of Torment SAI
SET @ENTRY := 25509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Priestess of Torment - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,30000,45000,11,46270,0,0,0,0,0,2,0,0,0,0,0,0,0,"Priestess of Torment - In Combat - Cast Whirlwind");

-- Doomfire Destroyer SAI
SET @ENTRY := 25592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doomfire Destroyer - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,3,0,0,1500,1500,11,46306,0,0,0,0,0,5,0,0,0,0,0,0,0,"Doomfire Destroyer - In Combat - Cast Create Doomfire Shard");

-- Apocalypse Guard SAI
SET @ENTRY := 25593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apocalypse Guard - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,20000,40000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apocalypse Guard - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,25000,25000,25000,45000,11,45029,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apocalypse Guard - In Combat - Cast Corrupting Strike"),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,17000,37000,11,46283,0,0,0,0,0,5,0,0,0,0,0,0,0,"Apocalypse Guard - In Combat - Cast Death Coil"),
(@ENTRY,0,4,0,2,0,100,3,0,20,0,0,11,46287,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apocalypse Guard - At 20% HP - Cast Infernal Defense");

-- Shadowsword Assassin SAI
SET @ENTRY := 25484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Assassin - On Respawn - Cast Stealth");

-- Shadowsword Deathbringer SAI
SET @ENTRY := 25485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Deathbringer - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,25000,45000,11,46481,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Deathbringer - In Combat - Cast Disease Buffet");

-- Shadowsword Vanquisher SAI
SET @ENTRY := 25486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Vanquisher - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,20000,30000,11,46468,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Vanquisher - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,2000,2000,15000,45000,11,46469,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Vanquisher - In Combat - Cast Melt Armor");

-- Shadowsword Lifeshaper SAI
SET @ENTRY := 25506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Lifeshaper - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,35000,35000,40000,70000,11,46466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Lifeshaper - In Combat - Cast Drain Life"),
(@ENTRY,0,2,0,14,0,100,2,0,300,60000,60000,11,46467,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowsword Lifeshaper - On Friendly Unit At 0 - 300% Health - Cast Health Funnel");

-- Sunblade Protector SAI
SET @ENTRY := 25507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Protector - On Respawn - Cast Invisibility and Stealth Detection");

-- Sunblade Dawn Priest SAI
SET @ENTRY := 25371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Dawn Priest - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,60,2,20000,20000,30000,40000,11,46564,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Dawn Priest - In Combat - Cast Holy Nova"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,46565,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Dawn Priest - On Aggro - Cast Holyform"),
(@ENTRY,0,3,0,14,0,100,2,0,300,30000,30000,11,46563,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sunblade Dawn Priest - On Friendly Unit At 0 - 300% Health - Cast Renew"),
(@ENTRY,0,4,0,2,0,100,2,10,60,20000,20000,11,46563,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Dawn Priest - At 60% HP - Cast Renew");

-- Sunblade Scout SAI
SET @ENTRY := 25372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Scout - On Respawn - Cast Invisibility and Stealth Detection");

-- Shadowsword Soulbinder SAI
SET @ENTRY := 25373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Soulbinder - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,25000,30000,11,46434,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Soulbinder - In Combat - Cast Curse of Exhaustion"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,20000,35000,11,46442,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Soulbinder - In Combat - Cast Flash of Darkness"),
(@ENTRY,0,3,0,4,0,30,3,0,0,0,0,11,46229,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowsword Soulbinder - On Aggro - Cast Summon Blazing Infernal"),
(@ENTRY,0,4,0,1,0,30,3,0,0,0,0,11,46241,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowsword Soulbinder - Out Of Combat - Cast Summon Felguard Slayer");

-- Shadowsword Manafiend SAI
SET @ENTRY := 25483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsword Manafiend - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,10000,30000,11,46457,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsword Manafiend - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,2,0,3,0,100,2,5,10,5000,5000,11,46453,0,0,0,0,0,6,0,0,0,0,0,0,0,"Shadowsword Manafiend - At 10% Mana - Cast Drain Mana");

-- Sunblade Arch Mage SAI
SET @ENTRY := 25367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Arch Mage - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,25000,45000,11,46553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Arch Mage - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,2,0,0,0,25,2,5000,5000,20000,20000,11,46555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Arch Mage - In Combat - Cast Frost Nova"),
(@ENTRY,0,3,0,0,0,100,2,20000,20000,30000,30000,11,46573,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunblade Arch Mage - In Combat - Cast Blink");

-- Sunblade Slayer SAI
SET @ENTRY := 25368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,0,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Slayer - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,79,60,45,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Slayer - On Respawn - Set Ranged Movement"),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,15000,20000,11,47001,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Slayer - In Combat - Cast Shoot"),
(@ENTRY,0,3,0,0,0,100,2,25000,25000,25000,25000,11,46557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Slayer - In Combat - Cast Slaying Shot");

-- Sunblade Vindicator SAI
SET @ENTRY := 25369;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Vindicator - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,15000,30000,11,46559,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Vindicator - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,35000,35000,25000,30000,11,39171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Vindicator - In Combat - Cast Mortal Strike");

-- Sunblade Dusk Priest SAI
SET @ENTRY := 25370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Dusk Priest - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,20000,35000,11,46562,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunblade Dusk Priest - In Combat - Cast Mind Flay"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,10000,30000,11,46560,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Dusk Priest - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,3,0,2,0,100,2,1,50,15000,15000,11,46561,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunblade Dusk Priest - At 50% HP - Cast Fear");

-- Hive'Zara Sandstalker SAI
SET @ENTRY := 15323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,10000,20000,10000,20000,11,26381,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive'Zara Sandstalker - In Combat - Cast Burrow"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,13,0,100,0,0,0,0,2,0,0,0,0,0,0,0,"Hive'Zara Sandstalker - In Combat - Remove 100% Threat");

-- Qiraji Gladiator SAI
SET @ENTRY := 15324;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,11000,8000,12000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Gladiator - In Combat - Cast Trample"),
(@ENTRY,0,1,0,9,0,100,2,0,10,7000,11000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Qiraji Gladiator - At 0 - 10 Range - Cast Uppercut"),
(@ENTRY,0,2,3,2,0,100,0,0,30,30000,30000,11,25164,1,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Gladiator - At 30% HP - Cast Vengeance"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Qiraji Gladiator - At 30% HP - Say Line 0");

-- Silicate Feeder SAI
SET @ENTRY := 15333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,11,17742,7,0,0,0,0,1,0,0,0,0,0,0,0,"Silicate Feeder - On Death - Cast Cloud of Disease");

-- Sunblade Cabalist SAI
SET @ENTRY := 25363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,45769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Cabalist - On Respawn - Cast Sunwell Radiance"),
(@ENTRY,0,1,0,0,0,100,2,20000,20000,20000,30000,11,46543,0,0,0,0,0,6,0,0,0,0,0,0,0,"Sunblade Cabalist - In Combat - Cast Ignite Mana"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,15000,20000,11,47248,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Cabalist - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,3,0,1,0,100,3,0,0,1000,1000,11,46544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Cabalist - Out Of Combat - Cast Summon Imp");

-- Stitched Colossus SAI
SET @ENTRY := 30071;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5400,12200,15500,22300,11,55821,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stitched Colossus - In Combat - Cast Massive Stomp"),
(@ENTRY,0,1,0,0,0,100,4,5400,12200,15500,22300,11,55826,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stitched Colossus - In Combat - Cast Massive Stomp"),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,54356,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stitched Colossus - At 30% HP - Cast Unstoppable Enrage");

-- Marauding Geist SAI
SET @ENTRY := 30083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,56729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marauding Geist - On Aggro - Cast Frenzied Leap");

-- Vigilant Shade SAI
SET @ENTRY := 30085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,55848,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vigilant Shade - Out Of Combat - Cast Invisibility"),
(@ENTRY,0,1,0,4,0,100,7,0,0,0,0,28,55848,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vigilant Shade - On Aggro - Remove Aura Invisibility"),
(@ENTRY,0,2,0,0,0,100,2,2300,2300,9600,9900,11,55850,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vigilant Shade - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,3,0,0,0,100,4,2300,2300,9600,9900,11,55851,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vigilant Shade - In Combat - Cast Shadow Bolt Volley");

-- Onyxian Warder SAI
SET @ENTRY := 12129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,12000,12000,11,20203,0,0,0,0,0,1,0,0,0,0,0,0,0,"Onyxian Warder - In Combat - Cast Fire Nova"),
(@ENTRY,0,1,0,0,0,90,6,5000,5000,20000,20000,11,18958,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onyxian Warder - In Combat - Cast Flame Lash"),
(@ENTRY,0,2,0,0,0,80,6,7000,7000,9000,11000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onyxian Warder - In Combat - Cast Cleave"),
(@ENTRY,0,3,0,0,0,95,6,3000,3000,35000,35000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Onyxian Warder - In Combat - Cast Pierce Armor");

-- Death Knight Understudy SAI
SET @ENTRY := 16803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,9700,17900,4100,6300,11,61696,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Knight Understudy - In Combat - Cast Blood Strike"),
(@ENTRY,0,1,0,0,0,100,6,7600,20800,30400,31700,11,29061,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Understudy - In Combat - Cast Bone Barrier"),
(@ENTRY,0,2,0,0,0,100,6,8300,21400,30600,32100,11,29060,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Knight Understudy - In Combat - Cast Taunt");

-- Plagued Champion SAI
SET @ENTRY := 16983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,11000,14000,11,30138,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plagued Champion - In Combat - Cast Shadow Shock"),
(@ENTRY,0,1,0,0,0,100,4,4000,8000,11000,14000,11,54889,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plagued Champion - In Combat - Cast Shadow Shock"),
(@ENTRY,0,2,0,0,0,100,6,7000,9000,9000,11000,11,32736,1,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Champion - In Combat - Cast Mortal Strike");

-- Plagued Warrior SAI
SET @ENTRY := 16984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7000,9000,7000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Warrior - In Combat - Cast Cleave");

-- Maexxna Spiderling SAI
SET @ENTRY := 17055;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,5000,8000,11,54121,32,0,0,0,0,2,0,0,0,0,0,0,0,"Maexxna Spiderling - In Combat - Cast Necrotic Poison"),
(@ENTRY,0,1,0,0,0,100,4,5000,9000,5000,8000,11,28776,32,0,0,0,0,2,0,0,0,0,0,0,0,"Maexxna Spiderling - In Combat - Cast Necrotic Poison");

-- Deathcharger Steed SAI
SET @ENTRY := 29818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3300,7500,10000,10900,11,55317,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deathcharger Steed - In Combat - Cast Charge");

-- Necro Stalker SAI
SET @ENTRY := 16453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,28431,0,0,0,0,0,2,0,0,0,0,0,0,0,"Necro Stalker - On Aggro - Cast Poison Charge");

-- Naxxramas Follower SAI
SET @ENTRY := 16505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,16000,21000,11,56107,1,0,0,0,0,5,0,0,0,0,0,0,0,"Naxxramas Follower - In Combat - Cast Berserker Charge"),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,11000,15000,11,54093,1,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Follower - In Combat - Cast Silence");

-- Crypt Guard SAI
SET @ENTRY := 16573;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,11,28969,32,0,0,0,0,5,0,0,0,0,0,0,0,"Crypt Guard - In Combat - Cast Acid Spit"),
(@ENTRY,0,1,0,0,0,100,5,0,0,0,0,11,56098,32,0,0,0,0,5,0,0,0,0,0,0,0,"Crypt Guard - In Combat - Cast Acid Spit"),
(@ENTRY,0,2,0,0,0,100,2,4000,6000,4000,7000,11,28969,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Guard - In Combat - Cast Acid Spit"),
(@ENTRY,0,3,0,0,0,100,4,4000,6000,4000,7000,11,56098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Guard - In Combat - Cast Acid Spit"),
(@ENTRY,0,4,0,0,0,100,6,7000,9000,7000,9000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Guard - In Combat - Cast Cleave"),
(@ENTRY,0,5,0,2,0,100,6,0,30,120000,120000,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crypt Guard - At 30% HP - Cast Frenzy");

-- Fallout Slime SAI
SET @ENTRY := 16290;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,7,0,0,0,0,11,54368,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallout Slime - In Combat - Cast Disease Cloud");

-- Mutated Grub SAI
SET @ENTRY := 16297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,6000,8000,11,30109,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mutated Grub - In Combat - Cast Slime Burst"),
(@ENTRY,0,1,0,0,0,100,4,2000,5000,6000,8000,11,54769,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mutated Grub - In Combat - Cast Slime Burst");

-- Sewage Slime SAI
SET @ENTRY := 16375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,28156,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sewage Slime - Out Of Combat - Cast Disease Cloud");

-- Lightning Totem SAI
SET @ENTRY := 16385;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,1100,4800,11,28297,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lightning Totem - In Combat - Cast Shock"),
(@ENTRY,0,1,0,0,0,100,4,0,0,1100,4800,11,54333,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lightning Totem - In Combat - Cast Shock");

-- Guardian of Icecrown SAI
SET @ENTRY := 16441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1200,2400,15600,23600,11,28470,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of Icecrown - In Combat - Cast Blood Tap");

-- Skeletal Smith SAI
SET @ENTRY := 16193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1700,7900,10500,12900,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Smith - In Combat - Cast Crush Armor"),
(@ENTRY,0,1,0,0,0,100,6,6200,6700,6000,8000,11,6713,1,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Smith - In Combat - Cast Disarm");

-- Unholy Axe SAI
SET @ENTRY := 16194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6100,13100,20100,20100,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unholy Axe - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,6,2200,8600,8800,13300,11,55463,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unholy Axe - In Combat - Cast Whirlwind");

-- Unholy Staff SAI
SET @ENTRY := 16215;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2400,8400,8400,16100,11,28450,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unholy Staff - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,1,0,0,0,100,4,9000,16000,20000,30000,11,55467,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unholy Staff - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,2,0,0,0,100,6,6100,10800,11000,15000,11,29849,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unholy Staff - In Combat - Cast Frost Nova"),
(@ENTRY,0,3,0,0,0,100,6,4800,6200,14800,14900,11,29848,1,0,0,0,0,6,0,0,0,0,0,0,0,"Unholy Staff - In Combat - Cast Polymorph");

-- Unholy Swords SAI
SET @ENTRY := 16216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4700,9200,15500,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unholy Swords - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,6,2400,7800,12000,13600,11,3391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unholy Swords - In Combat - Cast Thrash");

-- Eye Stalk SAI
SET @ENTRY := 16236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,14000,17000,11,29407,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye Stalk - In Combat - Cast Mind Flay"),
(@ENTRY,0,1,0,0,0,100,4,5000,7000,14000,17000,11,54805,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye Stalk - In Combat - Cast Mind Flay");

-- Bony Construct SAI
SET @ENTRY := 16167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,20000,20000,30000,11,55319,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bony Construct - In Combat - Cast Brutal Swipe"),
(@ENTRY,0,1,0,0,0,100,4,9000,20000,20000,30000,11,55324,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bony Construct - In Combat - Cast Brutal Swipe");

-- Stoneskin Gargoyle SAI
SET @ENTRY := 16168;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,7000,11,29325,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stoneskin Gargoyle - In Combat - Cast Acid Volley"),
(@ENTRY,0,1,0,0,0,100,4,3000,5000,5000,7000,11,54714,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stoneskin Gargoyle - In Combat - Cast Acid Volley"),
(@ENTRY,0,2,0,2,0,100,2,0,30,60000,60000,11,28995,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stoneskin Gargoyle - At 30% HP - Cast Stoneskin"),
(@ENTRY,0,3,0,2,0,100,4,0,30,60000,60000,11,54722,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stoneskin Gargoyle - At 30% HP - Cast Stoneskin");

-- Death Knight Cavalier SAI
SET @ENTRY := 16163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,4600,7300,11,55314,1,0,0,0,0,6,0,0,0,0,0,0,0,"Death Knight Cavalier - In Combat - Cast Strangulate"),
(@ENTRY,0,1,0,0,0,100,4,0,0,4600,7300,11,55334,1,0,0,0,0,6,0,0,0,0,0,0,0,"Death Knight Cavalier - In Combat - Cast Strangulate"),
(@ENTRY,0,2,0,0,0,100,2,1100,2200,4100,6200,11,55313,1,0,0,0,0,5,0,0,0,0,0,0,0,"Death Knight Cavalier - In Combat - Cast Icy Touch"),
(@ENTRY,0,3,0,0,0,100,4,1100,2200,4100,6200,11,55331,1,0,0,0,0,5,0,0,0,0,0,0,0,"Death Knight Cavalier - In Combat - Cast Icy Touch"),
(@ENTRY,0,4,0,0,0,100,2,4700,6100,15700,19800,11,55315,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Cavalier - In Combat - Cast Bone Armor"),
(@ENTRY,0,5,0,0,0,100,4,4700,6100,15700,19800,11,55336,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Cavalier - In Combat - Cast Bone Armor"),
(@ENTRY,0,6,0,2,0,100,7,0,30,0,0,11,55294,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Cavalier - At 30% HP - Cast Dismount Deathcharger");

-- Shade of Naxxramas SAI
SET @ENTRY := 16164;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2800,5100,4500,12000,11,28407,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of Naxxramas - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,1,0,0,0,100,4,2800,5100,4500,12000,11,55323,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of Naxxramas - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,2,0,0,0,100,6,4100,8700,75000,85000,11,28383,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of Naxxramas - In Combat - Cast Portal of Shadows");

-- Necro Knight SAI
SET @ENTRY := 16165;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,7,0,0,0,0,30,1,2,3,0,0,0,1,0,0,0,0,0,0,0,"Necro Knight - In Combat - Set Random Phase"),
(@ENTRY,0,1,0,0,0,100,6,1000,3200,2800,5200,11,15453,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necro Knight - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,2,0,0,0,100,6,0,0,13200,18500,11,28391,1,0,0,0,0,1,0,0,0,0,0,0,0,"Necro Knight - In Combat - Cast Blink"),
(@ENTRY,0,3,0,0,0,100,6,7600,8100,15000,20000,11,30092,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necro Knight - In Combat - Cast Blast Wave"),
(@ENTRY,0,4,0,0,0,100,6,1800,8900,9600,15700,11,30091,1,0,0,0,0,5,0,0,0,0,0,0,0,"Necro Knight - In Combat - Cast Flamestrike"),
(@ENTRY,0,5,0,0,0,100,6,3000,6000,25000,35000,11,30094,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necro Knight - In Combat - Cast Frost Nova"),
(@ENTRY,0,6,0,0,0,100,6,17000,21000,17000,23000,11,30095,1,0,0,0,0,1,0,0,0,0,0,0,0,"Necro Knight - In Combat - Cast Cone of Cold");

-- Death Knight Captain SAI
SET @ENTRY := 16145;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1600,7200,8100,14100,11,55255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Knight Captain - In Combat - Cast Plague Strike"),
(@ENTRY,0,1,0,0,0,100,4,1600,7200,8100,14100,11,55321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Knight Captain - In Combat - Cast Plague Strike"),
(@ENTRY,0,2,0,0,0,100,7,3500,10200,0,0,11,28353,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Captain - In Combat - Cast Raise Dead"),
(@ENTRY,0,3,0,2,0,100,7,0,20,0,0,11,55222,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight Captain - At 20% HP - Cast Unholy Presence");

-- Death Knight SAI
SET @ENTRY := 16146;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,7400,10100,17300,11,55213,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight - In Combat - Cast Hysteria"),
(@ENTRY,0,1,0,0,0,100,2,1000,1400,8500,20500,11,55209,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Knight - In Combat - Cast Death Coil"),
(@ENTRY,0,2,0,0,0,100,4,1000,1400,8500,20500,11,55320,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Knight - In Combat - Cast Death Coil"),
(@ENTRY,0,3,0,0,0,50,6,16600,17300,28500,34000,11,55210,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight - In Combat - Cast Death Coil"),
(@ENTRY,0,4,0,2,0,100,7,0,20,0,0,11,55212,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Knight - At 20% HP - Cast Blood Presence");

-- Risen Squire SAI
SET @ENTRY := 16154;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,45000,48000,11,55318,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Squire - In Combat - Cast Pierce Armor");

-- Dark Touched Warrior SAI
SET @ENTRY := 16156;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3300,8900,18900,19000,11,55266,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Touched Warrior - In Combat - Cast Whirlwind");
-- Plague Beast SAI
SET @ENTRY := 16034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,25000,30000,11,54780,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plague Beast - At 50% HP - Cast Plague Splash"),
(@ENTRY,0,1,0,2,0,100,4,0,50,25000,30000,11,56538,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plague Beast - At 50% HP - Cast Plague Splash");

-- Frenzied Bat SAI
SET @ENTRY := 16036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,11000,17000,11,54781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzied Bat - In Combat - Cast Frenzied Dive");

-- Plagued Bat SAI
SET @ENTRY := 16037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,13000,11,30113,32,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Bat - In Combat - Cast Putrid Bite"),
(@ENTRY,0,1,0,0,0,100,4,3000,6000,9000,13000,11,54772,32,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Bat - In Combat - Cast Putrid Bite");

-- Deathcharger Steed SAI
SET @ENTRY := 16067;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,55317,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathcharger Steed - On Aggro - Cast Charge");

-- Bile Sludge SAI
SET @ENTRY := 16142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,15,0,0,11,27890,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bile Sludge - At 15% HP - Cast Clone");

-- Living Monstrosity SAI
SET @ENTRY := 16021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7100,12500,18100,20900,11,28293,0,0,0,0,0,5,0,0,0,0,0,0,0,"Living Monstrosity - In Combat - Cast Chain Lightning"),
(@ENTRY,0,1,0,0,0,100,4,5000,8000,18000,24000,11,54334,0,0,0,0,0,5,0,0,0,0,0,0,0,"Living Monstrosity - In Combat - Cast Chain Lightning"),
(@ENTRY,0,2,0,0,0,100,6,6400,10000,16900,18500,11,28294,1,0,0,0,0,1,0,0,0,0,0,0,0,"Living Monstrosity - In Combat - Cast Lightning Totem");

-- Surgical Assistant SAI
SET @ENTRY := 16022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1600,2800,7700,11900,11,28310,32,0,0,0,0,5,0,0,0,0,0,0,0,"Surgical Assistant - In Combat - Cast Mind Flay"),
(@ENTRY,0,1,0,0,0,100,4,1600,2800,7700,11900,11,54339,0,0,0,0,0,5,0,0,0,0,0,0,0,"Surgical Assistant - In Combat - Cast Mind Flay");

-- Embalming Slime SAI
SET @ENTRY := 16024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,0,0,11,28322,0,0,0,0,0,1,0,0,0,0,0,0,0,"Embalming Slime - Out Of Combat - Cast Embalming Cloud");

-- Stitched Giant SAI
SET @ENTRY := 16025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5100,10400,18800,21300,11,28405,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stitched Giant - In Combat - Cast Knockback"),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,11,54356,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stitched Giant - At 30% HP - Cast Unstoppable Enrage");

-- Sludge Belcher SAI
SET @ENTRY := 16029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,0,0,11,28362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sludge Belcher - Out Of Combat - Cast Disease Cloud"),
(@ENTRY,0,1,0,0,0,100,2,1900,3000,6000,7300,11,27891,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sludge Belcher - In Combat - Cast Acidic Sludge"),
(@ENTRY,0,2,0,0,0,100,4,1900,3000,6000,7300,11,54331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sludge Belcher - In Combat - Cast Acidic Sludge");

-- Naxxramas Acolyte SAI
SET @ENTRY := 15981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,13000,16000,11,56064,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Acolyte - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,1,0,0,0,100,4,4000,8000,13000,16000,11,56065,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Acolyte - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,14000,17000,11,56063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Acolyte - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,3,0,0,0,100,4,9000,13000,14000,17000,11,56067,1,0,0,0,0,1,0,0,0,0,0,0,0,"Naxxramas Acolyte - In Combat - Cast Arcane Explosion");

-- Patchwork Golem SAI
SET @ENTRY := 16017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,0,0,11,27793,0,0,0,0,0,1,0,0,0,0,0,0,0,"Patchwork Golem - Out Of Combat - Cast Disease Cloud"),
(@ENTRY,0,1,0,0,0,100,6,5000,9300,15200,15200,11,27794,0,0,0,0,0,2,0,0,0,0,0,0,0,"Patchwork Golem - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,4800,10700,14000,19000,11,27758,1,0,0,0,0,1,0,0,0,0,0,0,0,"Patchwork Golem - In Combat - Cast War Stomp"),
(@ENTRY,0,3,0,0,0,100,4,4800,10700,14000,19000,11,56427,1,0,0,0,0,1,0,0,0,0,0,0,0,"Patchwork Golem - In Combat - Cast War Stomp"),
(@ENTRY,0,4,0,12,0,100,2,0,20,35000,43000,11,7160,1,0,0,0,0,7,0,0,0,0,0,0,0,"Patchwork Golem - On Target At 0 - 20% HP - Cast Execute"),
(@ENTRY,0,5,0,12,0,100,4,0,20,35000,43000,11,56426,1,0,0,0,0,7,0,0,0,0,0,0,0,"Patchwork Golem - On Target At 0 - 20% HP - Cast Execute");

-- Bile Retcher SAI
SET @ENTRY := 16018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3600,6800,13700,19700,11,27807,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bile Retcher - In Combat - Cast Bile Vomit"),
(@ENTRY,0,1,0,0,0,100,4,3600,6800,13700,19700,11,54326,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bile Retcher - In Combat - Cast Bile Vomit");

-- Mad Scientist SAI
SET @ENTRY := 16020;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7600,17300,6000,13300,11,28301,1,0,0,0,0,5,0,0,0,0,0,0,0,"Mad Scientist - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,4,7600,17300,6000,13300,11,28301,1,0,0,0,0,5,0,0,0,0,0,0,0,"Mad Scientist - In Combat - Cast Mana Burn"),
(@ENTRY,0,2,0,2,0,100,2,0,30,18000,21000,11,28306,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Scientist - At 30% HP - Cast Great Heal"),
(@ENTRY,0,3,0,2,0,100,4,0,30,18000,21000,11,54337,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Scientist - At 30% HP - Cast Great Heal");

-- Tomb Horror SAI
SET @ENTRY := 15979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,7000,12000,16000,11,54311,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tomb Horror - In Combat - Cast Crypt Scarabs"),
(@ENTRY,0,1,0,0,0,100,4,3000,7000,12000,16000,11,54316,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tomb Horror - In Combat - Cast Crypt Scarabs"),
(@ENTRY,0,2,0,0,0,100,2,15000,19000,28000,35000,11,54313,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tomb Horror - In Combat - Cast Crypt Scarab Swarm"),
(@ENTRY,0,3,0,0,0,100,4,15000,19000,28000,35000,11,54317,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tomb Horror - In Combat - Cast Crypt Scarab Swarm");

-- Naxxramas Cultist SAI
SET @ENTRY := 15980;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,14000,17000,11,28447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Cultist - In Combat - Cast Shadow Burst"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,14000,17000,11,53851,0,0,0,0,0,2,0,0,0,0,0,0,0,"Naxxramas Cultist - In Combat - Cast Shadow Burst");

-- Lava Spawn SAI
SET @ENTRY := 12265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,3000,3000,11,19391,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lava Spawn - In Combat - Cast Fireball"),
(@ENTRY,0,1,2,0,0,100,0,1000,1000,3000,3000,11,19391,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lava Spawn - In Combat - Cast Fireball"),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,12000,12000,11,19569,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lava Spawn - In Combat - Cast Split"),
(@ENTRY,0,3,4,0,0,100,0,12000,12000,12000,12000,11,19569,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lava Spawn - In Combat - Cast Split");

-- Dread Creeper SAI
SET @ENTRY := 15974;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,8000,11000,11,28440,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Creeper - In Combat - Cast Veil of Shadow"),
(@ENTRY,0,1,0,0,0,100,4,2000,5000,8000,11000,11,53803,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Creeper - In Combat - Cast Veil of Shadow");

-- Carrion Spinner SAI
SET @ENTRY := 15975;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,28434,0,0,0,0,0,2,0,0,0,0,0,0,0,"Carrion Spinner - On Aggro - Cast Spider Web"),
(@ENTRY,0,1,0,0,0,100,6,9000,16000,18000,21000,11,28434,0,0,0,0,0,5,0,0,0,0,0,0,0,"Carrion Spinner - In Combat - Cast Spider Web"),
(@ENTRY,0,2,0,0,0,100,2,5000,8000,14000,18000,11,30043,1,0,0,0,0,1,0,0,0,0,0,0,0,"Carrion Spinner - In Combat - Cast Poison Spray"),
(@ENTRY,0,3,0,0,0,100,4,5000,8000,14000,18000,11,56032,1,0,0,0,0,1,0,0,0,0,0,0,0,"Carrion Spinner - In Combat - Cast Poison Spray");

-- Venom Stalker SAI
SET @ENTRY := 15976;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,28431,0,0,0,0,0,5,0,0,0,0,0,0,0,"Venom Stalker - On Aggro - Cast Poison Charge"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,53809,0,0,0,0,0,5,0,0,0,0,0,0,0,"Venom Stalker - On Aggro - Cast Poison Charge");

-- Flamewaker Elite SAI
SET @ENTRY := 11664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,1000,1000,8000,8000,11,36711,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker Elite - In Combat - Cast Fireball"),
(@ENTRY,0,1,0,0,0,100,2,12000,12000,12000,12000,11,20229,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker Elite - In Combat - Cast Blast Wave"),
(@ENTRY,0,2,0,0,0,80,2,5000,5000,15000,15000,11,20623,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker Elite - In Combat - Cast Fire Blast");

-- Firewalker SAI
SET @ENTRY := 11666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,12000,8000,15000,11,19635,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firewalker - In Combat - Cast Incite Flames"),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,15000,15000,11,19636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Firewalker - In Combat - Cast Fire Blossom");

-- Flameguard SAI
SET @ENTRY := 11667;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,12000,10000,10000,11,19630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flameguard - In Combat - Cast Cone of Fire"),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,15000,15000,11,19631,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flameguard - In Combat - Cast Melt Armor");

-- Firelord SAI
SET @ENTRY := 11668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,15000,22000,11,19393,0,0,0,0,0,5,0,0,0,0,0,0,0,"Firelord - In Combat - Cast Soul Burn"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,30000,30000,11,19392,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firelord - In Combat - Cast Summon Lava Spawn");

-- Flamewaker Protector SAI
SET @ENTRY := 12119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15000,15000,30000,30000,11,20604,0,0,0,0,0,5,0,0,0,0,0,0,0,"Flamewaker Protector - In Combat - Cast Dominate Mind"),
(@ENTRY,0,1,0,0,0,100,2,6000,6000,6000,6000,11,20605,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker Protector - In Combat - Cast Cleave");

-- Deadwind Villager SAI
SET @ENTRY := 17672;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,7000,12000,15000,11,24317,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Villager - In Combat - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,5000,10000,11,27814,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deadwind Villager - In Combat - Cast Kick");

-- Molten Giant SAI
SET @ENTRY := 11658;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,7000,8000,8000,11,18944,0,0,0,0,0,5,0,0,0,0,0,0,0,"Molten Giant - In Combat - Cast Smash"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,15000,15000,11,18945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Molten Giant - In Combat - Cast Knock Away");

-- Molten Destroyer SAI
SET @ENTRY := 11659;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,12000,10000,10000,11,20276,0,0,0,0,0,2,0,0,0,0,0,0,0,"Molten Destroyer - In Combat - Cast Knockdown"),
(@ENTRY,0,1,0,0,0,100,2,18000,18000,12000,12000,11,19129,0,0,0,0,0,1,0,0,0,0,0,0,0,"Molten Destroyer - In Combat - Cast Massive Tremor");

-- Flamewaker SAI
SET @ENTRY := 11661;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,8000,8000,11,19730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,12000,12000,12000,12000,11,20277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker - In Combat - Cast Fist of Ragnaros"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,15000,15000,11,15502,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker - In Combat - Cast Sunder Armor");

-- Flamewaker Healer SAI
SET @ENTRY := 11663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,9000,9000,9000,11,20603,0,0,0,0,0,5,0,0,0,0,0,0,0,"Flamewaker Healer - In Combat - Cast Shadow Shock"),
(@ENTRY,0,1,0,0,0,100,2,2000,2000,2000,2000,11,22677,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flamewaker Healer - In Combat - Cast Shadow Bolt");

-- Ethereal Spellfilcher SAI
SET @ENTRY := 16545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,30000,30000,40000,40000,11,30007,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast Spatial Distortion"),
(@ENTRY,0,1,0,0,0,70,2,20000,20000,25000,25000,11,37161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast Arcane Volley"),
(@ENTRY,0,2,0,0,0,85,2,10000,10000,60000,60000,11,30036,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast Steal Magic"),
(@ENTRY,0,3,0,0,0,75,2,16000,16000,16000,16000,11,30039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereal Spellfilcher - In Combat - Cast Transference");

-- Fleshbeast SAI
SET @ENTRY := 16595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,5000,5000,20000,20000,11,29935,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fleshbeast - In Combat - Cast Gaping Maw"),
(@ENTRY,0,1,0,0,0,85,2,10000,10000,15000,15000,11,29939,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fleshbeast - In Combat - Cast Infectious Poison");

-- Phantom Hound SAI
SET @ENTRY := 17067;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,6000,6000,10000,10000,11,29574,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Hound - In Combat - Cast Rend"),
(@ENTRY,0,1,0,6,0,100,3,0,0,0,0,11,29541,3,0,0,0,0,1,0,0,0,0,0,0,0,"Phantom Hound - On Death - Cast Summon Phantom Hound Visual");

-- Astral Spark SAI
SET @ENTRY := 17283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,15000,15000,30000,30000,11,31472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Astral Spark - In Combat - Cast Arcane Discharge");

-- Magical Horror SAI
SET @ENTRY := 16529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,16000,16000,20000,20000,11,29911,0,0,0,0,0,6,0,0,0,0,0,0,0,"Magical Horror - In Combat - Cast Power Distortion"),
(@ENTRY,0,1,0,0,0,85,2,9000,9000,15000,15000,11,37078,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magical Horror - In Combat - Cast Arcane Volley");

-- Mana Warp SAI
SET @ENTRY := 16530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,10,0,0,11,29919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Warp - At 10% HP - Cast Warp Breach"),
(@ENTRY,0,1,0,2,0,100,5,0,10,0,0,11,37079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Warp - At 10% HP - Cast Warp Breach");

-- Shadow Pillager SAI
SET @ENTRY := 16540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,16000,16000,20000,20000,11,29930,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadow Pillager - In Combat - Cast Curse of Agony"),
(@ENTRY,0,1,0,0,0,80,2,6000,6000,12000,12000,11,29492,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadow Pillager - In Combat - Cast Searing Pain"),
(@ENTRY,0,2,0,0,0,75,2,22000,22000,22000,22000,11,29317,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadow Pillager - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,11,29928,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadow Pillager - On Aggro - Cast Immolate");

-- Arcane Protector SAI
SET @ENTRY := 16504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,80,2,0,0,0,0,11,29788,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcane Protector - On Spellhit - Cast Return Fire"),
(@ENTRY,0,1,0,0,0,100,3,0,0,15000,15000,12,17283,1,600000,0,0,0,5,0,0,0,0,0,0,0,"Arcane Protector - In Combat - Summon Creature Astral Spark"),
(@ENTRY,0,2,0,1,0,100,3,0,0,1000,1000,11,11649,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Protector - Out Of Combat - Cast Detect Invisibility");

-- Spell Shade SAI
SET @ENTRY := 16525;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,9000,9000,12000,12000,11,29926,1,0,0,0,0,5,0,0,0,0,0,0,0,"Spell Shade - In Combat - Cast Frostbolt"),
(@ENTRY,0,1,0,0,0,80,2,15000,15000,20000,20000,11,29927,1,0,0,0,0,5,0,0,0,0,0,0,0,"Spell Shade - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,2,0,0,0,75,2,20000,20000,22000,22000,11,29925,1,0,0,0,0,5,0,0,0,0,0,0,0,"Spell Shade - In Combat - Cast Fireball"),
(@ENTRY,0,3,0,0,0,85,2,8000,8000,10000,10000,11,29920,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spell Shade - In Combat - Cast Phasing Invisibility");

-- Sorcerous Shade SAI
SET @ENTRY := 16526;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,29923,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sorcerous Shade - On Aggro - Cast Frostbolt Volley"),
(@ENTRY,0,1,0,0,0,75,2,7000,7000,10000,10000,11,29923,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sorcerous Shade - In Combat - Cast Frostbolt Volley"),
(@ENTRY,0,2,0,0,0,75,2,14000,14000,16000,16000,11,29924,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sorcerous Shade - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,3,0,0,0,75,2,22000,22000,22000,22000,11,29922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sorcerous Shade - In Combat - Cast Fireball Volley");

-- Arcane Anomaly SAI
SET @ENTRY := 16488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,9000,9000,15000,15000,11,29885,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Anomaly - In Combat - Cast Arcane Volley"),
(@ENTRY,0,1,0,2,0,100,3,0,75,0,0,11,29880,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Anomaly - At 75% HP - Cast Mana Shield"),
(@ENTRY,0,2,0,0,0,90,2,30000,30000,45000,45000,11,29883,0,0,0,0,0,5,0,0,0,0,0,0,0,"Arcane Anomaly - In Combat - Cast Blink"),
(@ENTRY,0,3,0,6,0,100,3,0,0,0,0,11,29882,7,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Anomaly - On Death - Cast Loose Mana");

-- Chaotic Sentience SAI
SET @ENTRY := 16489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,10000,10000,30000,30000,11,29900,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chaotic Sentience - In Combat - Cast Unstable Magic");

-- Mana Feeder SAI
SET @ENTRY := 16491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,6000,6000,10000,10000,11,29908,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Feeder - In Combat - Cast Astral Bite");

-- Syphoner SAI
SET @ENTRY := 16492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,8000,8000,10000,10000,11,29881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syphoner - In Combat - Cast Drain Mana");

-- Skeletal Usher SAI
SET @ENTRY := 16471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,14000,14000,20000,20000,11,29666,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Usher - In Combat - Cast Frost Shock"),
(@ENTRY,0,1,2,0,0,100,0,5000,5000,13000,17000,11,29670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Usher - In Combat - Cast Ice Tomb"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,13,0,99,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Usher - In Combat - Remove 99% Threat");

-- Phantom Stagehand SAI
SET @ENTRY := 16472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,7000,7000,15000,15000,11,29677,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Stagehand - In Combat - Cast Mallet Toss"),
(@ENTRY,0,1,0,0,0,75,2,12000,12000,20000,20000,11,29673,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantom Stagehand - In Combat - Cast Sandbag"),
(@ENTRY,0,2,0,0,0,85,2,4000,4000,32000,32000,11,41580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Phantom Stagehand - In Combat - Cast Net");

-- Spectral Performer SAI
SET @ENTRY := 16473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,16000,16000,30000,30000,11,29679,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Performer - In Combat - Cast Bad Poetry"),
(@ENTRY,0,1,0,0,0,70,2,6000,6000,20000,20000,11,29680,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spectral Performer - In Combat - Cast Curtain Call"),
(@ENTRY,0,2,0,2,0,100,3,0,50,0,0,11,29683,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Performer - At 50% HP - Cast Spotlight");

-- Skeletal Waiter SAI
SET @ENTRY := 16415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,40,2,15000,15000,120000,120000,11,32441,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Waiter - In Combat - Cast Brittle Bones");

-- Spectral Sentry SAI
SET @ENTRY := 16424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Sentry - On Respawn - Cast Invisibility and Stealth Detection");

-- Phantom Guardsman SAI
SET @ENTRY := 16425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,75,0,0,11,29537,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantom Guardsman - At 75% HP - Cast Summon Phantom Hound"),
(@ENTRY,0,1,0,0,0,80,2,6000,6000,15000,15000,11,29684,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantom Guardsman - In Combat - Cast Shield Slam");

-- Wanton Hostess SAI
SET @ENTRY := 16459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,29485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wanton Hostess - On Aggro - Cast Alluring Aura"),
(@ENTRY,0,1,2,2,0,100,0,0,50,0,0,28,29485,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wanton Hostess - At 50% HP - Remove Aura Alluring Aura"),
(@ENTRY,0,2,3,2,0,100,0,0,0,0,0,11,29472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wanton Hostess - At 50% HP - Cast Wanton Hostess Transform"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,29486,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wanton Hostess - At 50% HP - Cast Bewitching Aura"),
(@ENTRY,0,4,0,0,0,75,2,8000,8000,20000,20000,11,29477,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wanton Hostess - In Combat - Cast Banshee Wail");

-- Spectral Retainer SAI
SET @ENTRY := 16410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,10000,10000,30000,30000,11,29578,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Retainer - In Combat - Cast Rend"),
(@ENTRY,0,1,0,0,0,80,2,13000,13000,20000,20000,11,29546,0,0,0,0,0,5,0,0,0,0,0,0,0,"Spectral Retainer - In Combat - Cast Oath of Fealty");

-- Spectral Chef SAI
SET @ENTRY := 16411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,4000,4000,6000,10000,11,29665,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Chef - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,20000,30000,11,29665,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Chef - In Combat - Cast Cleave");

-- Shadowbeast SAI
SET @ENTRY := 16176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,29304,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowbeast - On Aggro - Cast Howl of the Broken Hills");

-- Dreadbeast SAI
SET @ENTRY := 16177;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,12000,12000,11,29561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadbeast - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,12000,12000,300000,320000,11,29304,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dreadbeast - In Combat - Cast Howl of the Broken Hills");

-- Phase Hound SAI
SET @ENTRY := 16178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,9000,9000,10000,10000,11,32942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phase Hound - In Combat - Cast Phasing Invisibility");

-- Vampiric Mistbat SAI
SET @ENTRY := 16354;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,6000,6000,18000,18000,11,29363,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vampiric Mistbat - In Combat - Cast Draining Touch");

-- Lesser Scourgebat SAI
SET @ENTRY := 16355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,5000,5000,15000,15000,11,3234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lesser Scourgebat - In Combat - Cast Disease Touch");

-- Coldmist Stalker SAI
SET @ENTRY := 16170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,3000,3000,8000,8000,11,29290,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coldmist Stalker - In Combat - Cast Chilling Poison");

-- Coldmist Widow SAI
SET @ENTRY := 16171;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,90000,90000,20000,20000,11,29292,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmist Widow - In Combat - Cast Frost Mist"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,29292,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmist Widow - On Aggro - Cast Frost Mist"),
(@ENTRY,0,2,0,0,0,75,2,16000,16000,25000,25000,11,29293,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coldmist Widow - In Combat - Cast Poison Bolt Volley");

-- Shadowbat SAI
SET @ENTRY := 16173;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,4000,4000,19000,19000,11,29298,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowbat - In Combat - Cast Dark Shriek");

-- Greater Shadowbat SAI
SET @ENTRY := 16174;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,6000,6000,22000,22000,11,29303,0,0,0,0,0,5,0,0,0,0,0,0,0,"Greater Shadowbat - In Combat - Cast Wing Beat"),
(@ENTRY,0,1,0,0,0,85,2,15000,15000,35000,35000,11,29300,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Shadowbat - In Combat - Cast Sonic Blast");

-- Vampiric Shadowbat SAI
SET @ENTRY := 16175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,6000,6000,24000,24000,11,32429,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vampiric Shadowbat - In Combat - Cast Draining Touch");

-- Gronn-Priest SAI
SET @ENTRY := 21350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,2,7500,7500,20000,25000,11,36678,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gronn-Priest - In Combat - Cast Heal"),
(@ENTRY,0,1,0,0,0,75,2,2000,2000,20000,23000,11,36679,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gronn-Priest - In Combat - Cast Renew"),
(@ENTRY,0,2,0,0,0,85,2,6000,6000,15000,15000,11,22884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gronn-Priest - In Combat - Cast Psychic Scream");

-- Hellfire Warder SAI
SET @ENTRY := 18829;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,4800,4800,18400,27400,11,39175,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Warder - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,1,0,0,0,70,2,9000,9000,14500,21500,11,34437,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Warder - In Combat - Cast Death Coil"),
(@ENTRY,0,2,0,0,0,75,2,3000,3000,17000,18000,11,34435,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hellfire Warder - In Combat - Cast Rain of Fire"),
(@ENTRY,0,3,0,0,0,75,2,4100,4100,20000,23500,11,34436,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hellfire Warder - In Combat - Cast Shadow Burst"),
(@ENTRY,0,4,0,0,0,60,2,1400,1400,7000,9000,11,34439,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hellfire Warder - In Combat - Cast Unstable Affliction"),
(@ENTRY,0,5,0,0,0,75,2,57700,57700,50000,50000,11,34441,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Warder - In Combat - Cast Shadow Word: Pain");

-- Spectral Charger SAI
SET @ENTRY := 15547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,5000,5000,15000,15000,11,29320,0,0,0,0,0,4,0,0,0,0,0,0,0,"Spectral Charger - In Combat - Cast Charge");

-- Spectral Stallion SAI
SET @ENTRY := 15548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,10000,13000,11,29323,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Stallion - In Combat - Cast Absorb Vitality"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,6000,10000,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Stallion - In Combat - Cast Hoof Strike");

-- Fathom Sporebat SAI
SET @ENTRY := 22120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3800,7800,14000,21000,11,25778,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fathom Sporebat - In Combat - Cast Knock Away");

-- Serpentshrine Tidecaller SAI
SET @ENTRY := 22238;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2400,2400,17000,22000,11,38623,0,0,0,0,0,2,0,0,0,0,0,0,0,"Serpentshrine Tidecaller - In Combat - Cast Water Bolt Volley"),
(@ENTRY,0,1,0,0,0,100,2,7300,7300,20000,30000,11,39035,0,0,0,0,0,2,0,0,0,0,0,0,0,"Serpentshrine Tidecaller - In Combat - Cast Frost Nova");

-- Rancid Mushroom SAI
SET @ENTRY := 22250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,11,38652,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rancid Mushroom - In Combat - Cast Spore Cloud"),
(@ENTRY,0,1,0,0,0,100,3,0,0,500,500,11,38653,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rancid Mushroom - In Combat - Cast Spore Cloud");

-- Wild Fel Stalker SAI
SET @ENTRY := 18847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,10000,6000,10000,11,33086,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wild Fel Stalker - In Combat - Cast Wild Bite");

-- Lair Brute SAI
SET @ENTRY := 19389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5700,10500,8300,22500,11,39171,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lair Brute - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,2,17600,18100,27100,34200,11,24193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lair Brute - In Combat - Cast Charge"),
(@ENTRY,0,2,0,0,0,100,2,4100,15300,6100,16000,11,39174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lair Brute - In Combat - Cast Cleave");

-- Coilfang Shatterer SAI
SET @ENTRY := 21301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,34,25,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Shatterer - On Death - Set Instance Data 25 to 1");

-- Coilfang Hate-Screamer SAI
SET @ENTRY := 21339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,38600,38600,11,38491,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Hate-Screamer - In Combat - Cast Silence"),
(@ENTRY,0,1,0,0,0,100,2,6100,6100,4800,12800,11,38496,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Hate-Screamer - In Combat - Cast Sonic Scream");

-- Serpentshrine Lurker SAI
SET @ENTRY := 21863;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,32900,32900,11,38655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Serpentshrine Lurker - In Combat - Cast Poison Bolt Volley"),
(@ENTRY,0,1,0,0,0,70,2,0,0,16800,18800,11,38650,0,0,0,0,0,2,0,0,0,0,0,0,0,"Serpentshrine Lurker - In Combat - Cast Rancid Mushroom");

-- Tidewalker Lurker SAI
SET @ENTRY := 21920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,6700,6700,5900,7100,11,41932,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tidewalker Lurker - In Combat - Cast Carnivorous Bite");

-- Fathom Lurker SAI
SET @ENTRY := 22119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4800,6800,19000,22000,11,25778,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fathom Lurker - In Combat - Cast Knock Away");

-- Greyheart Technician SAI
SET @ENTRY := 21263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2100,2100,7300,13300,11,38995,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Technician - In Combat - Cast Hamstring");

-- Coilfang Serpentguard SAI
SET @ENTRY := 21298;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,11900,11900,10900,18900,11,38599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Serpentguard - In Combat - Cast Spell Reflection"),
(@ENTRY,0,1,0,0,0,100,2,0,0,59000,60000,11,38603,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Serpentguard - In Combat - Cast Corrupt Devotion Aura");

-- Coilfang Fathom-Witch SAI
SET @ENTRY := 21299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,13200,13200,22900,32900,11,38626,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilfang Fathom-Witch - In Combat - Cast Domination"),
(@ENTRY,0,1,0,0,0,100,2,12200,12200,66300,89300,11,38627,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Fathom-Witch - In Combat - Cast Shadow Nova"),
(@ENTRY,0,2,0,0,0,100,2,1200,1200,5200,9200,11,38628,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Fathom-Witch - In Combat - Cast Shadow Bolt");

-- Greyheart Shield-Bearer SAI
SET @ENTRY := 21231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7300,7300,7600,12600,11,38631,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Shield-Bearer - In Combat - Cast Avenger's Shield"),
(@ENTRY,0,1,0,0,0,80,3,1000,1000,10800,12800,11,38630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Shield-Bearer - In Combat - Cast Shield Charge");

-- Greyheart Skulker SAI
SET @ENTRY := 21232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1900,1900,4800,5500,11,38625,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Skulker - In Combat - Cast Kick");

-- Serpentshrine Sporebat SAI
SET @ENTRY := 21246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,13600,17600,11,22120,0,0,0,0,0,5,0,0,0,0,0,0,0,"Serpentshrine Sporebat - In Combat - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,2,2000,2000,36800,36800,11,38924,0,0,0,0,0,1,0,0,0,0,0,0,0,"Serpentshrine Sporebat - In Combat - Cast Spore Burst");

-- Underbog Colossus SAI
SET @ENTRY := 21251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,30,1,2,3,0,0,0,1,0,0,0,0,0,0,0,"Underbog Colossus - In Combat - Set Random Phase"),
(@ENTRY,0,1,0,0,0,100,2,16000,16000,22100,33100,11,38976,0,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Colossus - In Combat - Cast Spore Quake"),
(@ENTRY,0,2,0,0,0,100,2,11400,11400,14400,24900,11,39032,0,0,0,0,0,5,0,0,0,0,0,0,0,"Underbog Colossus - In Combat - Cast Initial Infection"),
(@ENTRY,0,3,0,0,0,100,2,2800,2800,2400,6800,11,39015,0,0,0,0,0,5,0,0,0,0,0,0,0,"Underbog Colossus - In Combat - Cast Atrophic Blow"),
(@ENTRY,0,4,0,0,0,60,2,10900,10900,16100,16900,11,39031,0,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Colossus - In Combat - Cast Enrage"),
(@ENTRY,0,5,0,0,0,100,2,14500,14500,20000,30000,11,39044,0,0,0,0,0,5,0,0,0,0,0,0,0,"Underbog Colossus - In Combat - Cast Serpentshrine Parasite"),
(@ENTRY,0,6,0,0,0,70,2,16800,16800,27700,29700,11,38971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Underbog Colossus - In Combat - Cast Acid Geyser"),
(@ENTRY,0,7,0,6,0,100,3,0,0,0,0,11,38718,3,0,0,0,0,1,0,0,0,0,0,0,0,"Underbog Colossus - On Death - Cast Toxic Pool");

-- Tidewalker Hydromancer SAI
SET @ENTRY := 21228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6600,6600,21000,25700,11,39062,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Hydromancer - In Combat - Cast Frost Shock"),
(@ENTRY,0,1,0,0,0,100,2,5400,5400,37000,37000,11,39063,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidewalker Hydromancer - In Combat - Cast Frost Nova"),
(@ENTRY,0,2,0,0,0,100,2,15000,15000,17300,21300,11,39064,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Hydromancer - In Combat - Cast Frostbolt");

-- Greyheart Tidecaller SAI
SET @ENTRY := 21229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,2300,2300,35700,35700,11,38624,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greyheart Tidecaller - In Combat - Cast Water Elemental Totem"),
(@ENTRY,0,1,0,0,0,100,3,0,0,13500,13500,11,39027,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greyheart Tidecaller - In Combat - Cast Poison Shield");

-- Greyheart Nether-Mage SAI
SET @ENTRY := 21230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,0,0,30,1,2,3,0,0,0,1,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Set Random Phase"),
(@ENTRY,0,1,0,0,0,100,2,0,0,1200,6400,11,38645,0,0,0,0,0,5,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Frostbolt"),
(@ENTRY,0,2,0,0,0,100,3,0,0,8000,8000,11,38644,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Cone of Cold"),
(@ENTRY,0,3,0,0,0,100,3,0,0,8100,8100,11,38649,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Frost Destruction"),
(@ENTRY,0,4,0,0,0,100,2,2100,2100,12600,15600,11,38634,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Arcane Lightning"),
(@ENTRY,0,5,0,0,0,100,3,0,0,2700,2700,11,38647,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Arcane Destruction"),
(@ENTRY,0,6,0,0,0,50,2,500,500,20000,20000,11,38642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Blink"),
(@ENTRY,0,7,0,0,0,100,2,8800,8800,9600,9600,11,38642,0,0,0,0,0,5,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Blink"),
(@ENTRY,0,8,0,0,0,100,2,4700,4700,116600,116600,11,38641,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Fireball"),
(@ENTRY,0,9,0,0,0,100,2,8400,8400,104400,104400,11,38635,0,0,0,0,0,5,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Rain of Fire"),
(@ENTRY,0,10,0,0,0,100,3,0,0,1000,1000,11,38648,0,0,0,0,0,1,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Fire Destruction"),
(@ENTRY,0,11,0,0,0,100,3,700,700,10100,10100,11,38636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greyheart Nether-Mage - In Combat - Cast Scorch");

-- Tidewalker Depth-Seer SAI
SET @ENTRY := 21224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,13300,13300,14500,17500,11,38657,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidewalker Depth-Seer - In Combat - Cast Rejuvenation"),
(@ENTRY,0,1,0,0,0,75,2,17700,17700,26500,29500,11,38658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidewalker Depth-Seer - In Combat - Cast Healing Touch"),
(@ENTRY,0,2,0,0,0,100,2,19300,19300,10000,11000,11,38659,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidewalker Depth-Seer - In Combat - Cast Tranquility");

-- Tidewalker Warrior SAI
SET @ENTRY := 21225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,11500,11500,20000,32500,11,39070,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidewalker Warrior - In Combat - Cast Bloodthirst"),
(@ENTRY,0,1,0,0,0,100,2,16100,16100,45000,45000,11,39069,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Warrior - In Combat - Cast Uppercut"),
(@ENTRY,0,2,0,0,0,100,2,17300,17300,22100,24600,11,38664,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidewalker Warrior - In Combat - Cast Enrage");

-- Tidewalker Shaman SAI
SET @ENTRY := 21226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,1200,1200,7600,9900,11,39065,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Shaman - In Combat - Cast Lightning Bolt"),
(@ENTRY,0,1,0,0,0,100,3,0,0,5900,5900,11,39066,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Shaman - In Combat - Cast Chain Lightning"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,39067,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidewalker Shaman - On Aggro - Cast Lightning Shield");

-- Tidewalker Harpooner SAI
SET @ENTRY := 21227;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,11600,11600,16800,25300,11,38661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Harpooner - In Combat - Cast Net"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,13,0,99,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Harpooner - In Combat - Remove 99% Threat"),
(@ENTRY,0,2,0,0,0,80,2,3100,3100,12000,17000,11,39060,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tidewalker Harpooner - In Combat - Cast Throw");

-- Coilfang Priestess SAI
SET @ENTRY := 21220;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,34,25,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Priestess - On Death - Set Instance Data 25 to 1");

-- Coilfang Beast-Tamer SAI
SET @ENTRY := 21221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1400,1400,3100,9100,11,38904,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Beast-Tamer - In Combat - Cast Throw"),
(@ENTRY,0,1,0,0,0,100,2,300,300,9900,10900,11,38474,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilfang Beast-Tamer - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,2000,2000,19300,19300,11,38484,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilfang Beast-Tamer - In Combat - Cast Bestial Wrath");

-- Tauren Warrior SAI
SET @ENTRY := 17933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,10000,30000,11,31755,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tauren Warrior - In Combat - Cast War Stomp");

-- Horde Witch Doctor SAI
SET @ENTRY := 17935;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,15000,20000,11,31759,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Witch Doctor - In Combat - Cast Holy Bolt"),
(@ENTRY,0,1,0,0,0,100,2,50000,50000,60000,80000,11,31760,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Witch Doctor - In Combat - Cast Healing Ward"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,31760,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Witch Doctor - On Aggro - Cast Healing Ward");

-- Horde Shaman SAI
SET @ENTRY := 17936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,31765,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Shaman - On Aggro - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,15000,20000,11,31764,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Shaman - In Combat - Cast Lightning Bolt"),
(@ENTRY,0,2,0,0,0,75,2,20000,20000,20000,30000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Shaman - In Combat - Cast Bloodlust");

-- Alliance Footman SAI
SET @ENTRY := 17919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,6500,6500,20000,30000,11,31731,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Footman - In Combat - Cast Shield Wall");

-- Alliance Knight SAI
SET @ENTRY := 17920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,500,500,50000,55000,11,31732,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Knight - In Combat - Cast Rallying Cry");

-- Alliance Sorceress SAI
SET @ENTRY := 17922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,10000,10000,35000,50000,11,31741,0,0,0,0,0,5,0,0,0,0,0,0,0,"Alliance Sorceress - In Combat - Cast Slow"),
(@ENTRY,0,1,0,0,0,100,2,7500,7500,12000,17000,11,31743,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Sorceress - In Combat - Cast Arcane Missiles");

-- Alliance Priest SAI
SET @ENTRY := 17928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,32000,32000,45000,65000,11,31739,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Priest - In Combat - Cast Heal"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,15000,25000,11,31740,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Priest - In Combat - Cast Holy Smite");

-- Blue Drakonid SAI
SET @ENTRY := 14261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,12000,12000,20000,20000,11,22559,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blue Drakonid - In Combat - Cast Brood Power: Blue");

-- Green Drakonid SAI
SET @ENTRY := 14262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,12000,12000,20000,20000,11,22561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Green Drakonid - In Combat - Cast Brood Power: Green");

-- Bronze Drakonid SAI
SET @ENTRY := 14263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,12000,12000,20000,20000,11,22642,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bronze Drakonid - In Combat - Cast Brood Power: Bronze");

-- Red Drakonid SAI
SET @ENTRY := 14264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,12000,12000,20000,20000,11,22558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Drakonid - In Combat - Cast Brood Power: Red");

-- Black Drakonid SAI
SET @ENTRY := 14265;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,4000,6000,11,22560,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Drakonid - In Combat - Cast Brood Power: Black");

-- Death Talon Captain SAI
SET @ENTRY := 12467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,22440,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Talon Captain - On Aggro - Cast Commanding Shout"),
(@ENTRY,0,1,0,0,0,85,2,4000,4000,5000,5000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Captain - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,80,2,20000,20000,20000,20000,11,22438,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Captain - In Combat - Cast Mark of Detonation");

-- Death Talon Hatcher SAI
SET @ENTRY := 12468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,2000,4000,7000,11,22442,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Hatcher - In Combat - Cast Growing Flames"),
(@ENTRY,0,1,0,0,0,100,2,2000,2000,6500,10500,11,22275,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Talon Hatcher - In Combat - Cast Flamestrike");

-- Grethok the Controller SAI
SET @ENTRY := 12557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,2,10000,10000,5000,10000,11,22274,0,0,0,0,0,5,0,0,0,0,0,0,0,"Grethok the Controller - In Combat - Cast Greater Polymorph"),
(@ENTRY,0,1,0,0,0,85,2,12000,12000,20000,20000,11,14515,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grethok the Controller - In Combat - Cast Dominate Mind"),
(@ENTRY,0,2,0,0,0,80,2,8000,8000,20000,20000,11,13747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grethok the Controller - In Combat - Cast Slow"),
(@ENTRY,0,3,0,0,0,80,2,16000,16000,12000,12000,11,22273,0,0,0,0,0,5,0,0,0,0,0,0,0,"Grethok the Controller - In Combat - Cast Arcane Missiles");

-- Blackwing Technician SAI
SET @ENTRY := 13996;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,2000,2000,2000,6000,11,22334,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackwing Technician - In Combat - Cast Bomb"),
(@ENTRY,0,1,0,0,0,85,2,2000,2000,8000,8000,11,22335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackwing Technician - In Combat - Cast Bottle of Poison");

-- Death Talon Overseer SAI
SET @ENTRY := 12461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,2000,2000,2000,6000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Overseer - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,80,2,3000,3000,3000,6000,11,20623,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Talon Overseer - In Combat - Cast Fire Blast");

-- Death Talon Flamescale SAI
SET @ENTRY := 12463;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,3000,3000,1000,5000,11,22423,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Flamescale - In Combat - Cast Flame Shock"),
(@ENTRY,0,1,0,0,0,70,2,9000,9000,12000,17000,11,16636,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Talon Flamescale - In Combat - Cast Berserker Charge");

-- Death Talon Seether SAI
SET @ENTRY := 12464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,10000,10000,10000,10000,11,22428,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Talon Seether - In Combat - Cast Enrage"),
(@ENTRY,0,1,0,0,0,70,2,10000,10000,7000,11000,11,22433,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Seether - In Combat - Cast Flame Buffet");

-- Death Talon Wyrmkin SAI
SET @ENTRY := 12465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,7000,7000,7000,9000,11,22424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Talon Wyrmkin - In Combat - Cast Blast Wave"),
(@ENTRY,0,1,0,0,0,70,2,2000,2000,2000,6000,11,22425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Wyrmkin - In Combat - Cast Fireball Volley");

-- Illidari Assassin SAI
SET @ENTRY := 23403;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,45000,55000,11,39667,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Assassin - In Combat - Cast Vanish"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,40000,42500,11,34099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Assassin - In Combat - Cast Riposte"),
(@ENTRY,0,2,0,0,0,100,2,15000,15000,35000,50000,11,3609,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Assassin - In Combat - Cast Paralyzing Poison");

-- Ashtongue Elementalist SAI
SET @ENTRY := 23523;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,18000,18000,20000,20000,11,42023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Elementalist - In Combat - Cast Rain of Fire"),
(@ENTRY,0,1,0,0,0,85,2,6000,6000,15000,15000,11,42024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Elementalist - In Combat - Cast Lightning Bolt");

-- Ashtongue Spiritbinder SAI
SET @ENTRY := 23524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,2,15000,15000,24000,24000,11,42025,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Spiritbinder - In Combat - Cast Spirit Mend"),
(@ENTRY,0,1,0,0,0,85,2,8000,8000,18000,18000,11,42027,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Spiritbinder - In Combat - Cast Chain Heal"),
(@ENTRY,0,2,0,14,0,100,2,0,100,30000,30000,11,42317,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Spiritbinder - On Friendly Unit At 0 - 100% Health - Cast Spirit Heal");

-- Blackwing Warlock SAI
SET @ENTRY := 12459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,5000,5000,5000,7000,11,19717,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackwing Warlock - In Combat - Cast Rain of Fire"),
(@ENTRY,0,1,0,0,0,85,2,6000,6000,3000,7000,11,22336,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackwing Warlock - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,2,0,0,0,80,2,10000,10000,10000,10000,11,22372,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackwing Warlock - In Combat - Cast Demon Portal");

-- Death Talon Wyrmguard SAI
SET @ENTRY := 12460;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,8000,8000,8000,14000,11,24375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Talon Wyrmguard - In Combat - Cast War Stomp");

-- Illidari Blood Lord SAI
SET @ENTRY := 23397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,500,500,50000,70000,11,41367,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Blood Lord - In Combat - Cast Divine Shield"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,35000,50000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Blood Lord - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,2,0,0,0,100,2,15000,15000,38000,43000,11,41368,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Blood Lord - In Combat - Cast Judgement of Command");

-- Illidari Archon SAI
SET @ENTRY := 23400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,3,0,0,0,0,11,29406,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Archon - On Aggro - Cast Shadowform"),
(@ENTRY,0,1,0,0,0,35,2,20000,20000,35000,37000,11,41372,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Archon - In Combat - Cast Heal"),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,25000,35000,11,41370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Archon - In Combat - Cast Holy Smite"),
(@ENTRY,0,3,0,0,0,100,2,15000,15000,30000,35000,11,41374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Archon - In Combat - Cast Mind Blast"),
(@ENTRY,0,4,0,0,0,100,2,20000,20000,25000,35000,11,41373,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Archon - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,5,0,12,0,100,2,0,10,15000,15000,11,41375,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Archon - On Target At 0 - 10% HP - Cast Shadow Word: Death");

-- Illidari Battle-mage SAI
SET @ENTRY := 23402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7500,7500,30000,50000,11,41382,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Battle-mage - In Combat - Cast Blizzard"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,35000,45000,11,41379,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Battle-mage - In Combat - Cast Flamestrike"),
(@ENTRY,0,2,0,0,0,100,2,20000,20000,45000,50000,11,41383,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Battle-mage - In Combat - Cast Fireball"),
(@ENTRY,0,3,0,0,0,100,2,2000,2000,25000,65000,11,41384,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Battle-mage - In Combat - Cast Frostbolt");

-- Ashtongue Rogue SAI
SET @ENTRY := 23318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Rogue - On Aggro - Cast Dual Wield"),
(@ENTRY,0,1,0,2,0,100,2,0,15,20000,20000,11,41177,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Rogue - At 15% HP - Cast Eviscerate"),
(@ENTRY,0,2,0,0,0,100,2,15000,15000,22000,22000,11,41978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Rogue - In Combat - Cast Debilitating Poison");

-- Dragonmaw Wind Reaver SAI
SET @ENTRY := 23330;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,15000,23400,11,40876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Wind Reaver - In Combat - Cast Doom Bolt"),
(@ENTRY,0,1,0,0,0,100,2,9000,9000,25000,33400,11,40877,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonmaw Wind Reaver - In Combat - Cast Fireball"),
(@ENTRY,0,2,0,0,0,100,2,18000,18000,33000,42400,11,40875,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonmaw Wind Reaver - In Combat - Cast Freeze");

-- Illidari Centurion SAI
SET @ENTRY := 23337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,9000,9000,18000,18000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Centurion - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,75,2,15000,15000,45000,45000,11,41168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Centurion - In Combat - Cast Sonic Strike");

-- Illidari Heartseeker SAI
SET @ENTRY := 23339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,41169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,3900,5900,11,41169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,2,7000,11000,19000,25000,11,41173,1,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - In Combat - Cast Rapid Shot"),
(@ENTRY,0,14,0,0,0,100,2,45000,60000,60000,75000,11,41171,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - In Combat - Cast Skeleton Shot"),
(@ENTRY,0,15,0,2,0,100,3,0,50,0,0,11,41170,1,0,0,0,0,2,0,0,0,0,0,0,0,"Illidari Heartseeker - At 50% HP - Cast Curse of the Bleakheart"),
(@ENTRY,0,16,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illidari Heartseeker - On Evade - Display melee weapon");

-- Promenade Sentinel SAI
SET @ENTRY := 23394;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,50000,55000,11,41360,0,0,0,0,0,5,0,0,0,0,0,0,0,"Promenade Sentinel - In Combat - Cast L5 Arcane Charge"),
(@ENTRY,0,1,0,2,0,100,3,0,75,0,0,11,41349,0,0,0,0,0,2,0,0,0,0,0,0,0,"Promenade Sentinel - At 75% HP - Cast L4 Arcane Charge");

-- Bonechewer Spectator SAI
SET @ENTRY := 23223;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,36140,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bonechewer Spectator - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,2,6000,6000,15000,21500,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Spectator - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,1500,1500,15000,21500,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Spectator - In Combat - Cast Strike"),
(@ENTRY,0,3,0,0,0,100,2,8000,8000,10000,16500,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Spectator - In Combat - Cast Sunder Armor"),
(@ENTRY,0,4,0,0,0,100,2,3000,3000,5600,25400,11,25646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Spectator - In Combat - Cast Mortal Wound");

-- Bonechewer Blade Fury SAI
SET @ENTRY := 23235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,30000,45000,11,41195,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Blade Fury - In Combat - Cast Whirlwind");

-- Bonechewer Shield Disciple SAI
SET @ENTRY := 23236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,20000,30000,11,41213,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Shield Disciple - In Combat - Cast Throw Shield"),
(@ENTRY,0,1,0,2,0,100,3,0,7,0,0,11,41196,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Shield Disciple - At 7% HP - Cast Shield Wall");

-- Ashtongue Defender SAI
SET @ENTRY := 23216;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,2,10000,10000,18000,18000,11,41178,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Defender - In Combat - Cast Debilitating Strike"),
(@ENTRY,0,1,0,0,0,85,2,8000,8000,16000,16000,11,41180,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Defender - In Combat - Cast Shield Bash");

-- Ashtongue Mystic SAI
SET @ENTRY := 22845;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,2000,45000,45000,11,39588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - In Combat - Cast Searing Totem"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,41185,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - On Aggro - Cast Bloodlust"),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,75000,75000,11,39589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - In Combat - Cast Cyclone Totem"),
(@ENTRY,0,3,0,2,0,100,2,0,50,30000,30000,11,41114,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - At 50% HP - Cast Chain Heal"),
(@ENTRY,0,4,0,0,0,85,2,15000,15000,25000,25000,11,41115,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Mystic - In Combat - Cast Flame Shock"),
(@ENTRY,0,5,0,0,0,75,2,25000,25000,25000,25000,11,41116,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ashtongue Mystic - In Combat - Cast Frost Shock"),
(@ENTRY,0,6,0,0,0,100,2,15000,15000,100000,100000,11,39586,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Mystic - In Combat - Cast Summon Windfury Totem");

-- Ashtongue Stormcaller SAI
SET @ENTRY := 22846;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,39534,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - Out Of Combat - Cast Summon Storm Fury"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,41151,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - On Aggro - Cast Lightning Shield"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Stormcaller - On Aggro - Cast Fireball"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,2,0,40,3800,5200,11,41184,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,6,7,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 15% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashtongue Stormcaller - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,0,0,100,2,12000,18000,22000,28000,11,41183,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ashtongue Stormcaller - In Combat - Cast Chain Lightning");

-- Blackwing Spellbinder SAI
SET @ENTRY := 12457;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,2,10000,10000,5000,10000,11,22274,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blackwing Spellbinder - In Combat - Cast Greater Polymorph"),
(@ENTRY,0,1,0,0,0,60,2,1000,1000,1000,60000,11,22275,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackwing Spellbinder - In Combat - Cast Flamestrike");

-- Sul'lithuz Abomination SAI
SET @ENTRY := 8120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,8000,8000,19000,19000,11,11020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sul'lithuz Abomination - In Combat - Cast Petrify");

-- Sul'lithuz Broodling SAI
SET @ENTRY := 8138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,3000,3000,5000,5000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sul'lithuz Broodling - In Combat - Cast Thrash");

-- Servant of Antu'sul SAI
SET @ENTRY := 8156;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,7000,7000,18000,18000,11,11020,0,0,0,0,0,5,0,0,0,0,0,0,0,"Servant of Antu'sul - In Combat - Cast Petrify");

-- Sandfury Acolyte SAI
SET @ENTRY := 8876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - On Respawn - Set Ranged Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 5 - 15 Range - Set Ranged Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Acolyte - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,2,8000,10000,25000,31000,11,11639,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,11,0,0,0,100,2,4000,6000,120000,135000,11,11980,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,12,0,0,0,100,2,5000,6000,15000,22000,11,11981,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sandfury Acolyte - In Combat - Cast Mana Burn");

-- Murta Grimgut SAI
SET @ENTRY := 7608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,85,2,0,50,10000,12000,11,11642,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murta Grimgut - At 50% HP - Cast Heal");

-- Sandfury Cretin SAI
SET @ENTRY := 7789;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,20798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Cretin - On Aggro - Cast Demon Skin"),
(@ENTRY,0,1,0,0,0,80,2,5000,7500,20000,25000,11,14032,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Cretin - In Combat - Cast Shadow Word: Pain");

-- Sul'lithuz Sandcrawler SAI
SET @ENTRY := 8095;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,10000,10000,17000,17000,11,11020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sul'lithuz Sandcrawler - In Combat - Cast Petrify");

-- Zul'Farrak Dead Hero SAI
SET @ENTRY := 7276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,3000,6000,12000,20000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Zul'Farrak Dead Hero - In Combat - Cast Infected Wound");

-- Raven SAI
SET @ENTRY := 7605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,29651,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raven - On Aggro - Cast Dual Wield"),
(@ENTRY,0,1,0,0,0,80,2,5000,5000,9000,9000,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raven - In Combat - Cast Gouge"),
(@ENTRY,0,2,0,0,0,80,2,3000,3000,12000,12000,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raven - In Combat - Cast Backstab");

-- Oro Eyegouge SAI
SET @ENTRY := 7606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - On Respawn - Set Ranged Movement"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,12741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - On Aggro - Cast Curse of Weakness"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,5,15,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 5 - 15 Range - Set Ranged Movement"),
(@ENTRY,0,9,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Oro Eyegouge - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,80,2,5000,7000,23000,27000,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - In Combat - Cast Immolate"),
(@ENTRY,0,12,0,0,0,80,2,8000,10000,15000,18250,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oro Eyegouge - In Combat - Cast Rain of Fire");

-- Sandfury Soul Eater SAI
SET @ENTRY := 7247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,3000,5500,6000,8500,11,11016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Soul Eater - In Combat - Cast Soul Bite"),
(@ENTRY,0,1,0,14,0,100,2,0,10,16000,20000,11,7154,1,0,0,0,0,7,0,0,0,0,0,0,0,"Sandfury Soul Eater - On Friendly Unit At 0 - 10% Health - Cast Dark Offering");

-- Sandfury Guardian SAI
SET @ENTRY := 7268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,2000,2000,6000,6000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Guardian - In Combat - Cast Thrash");

-- Scarab SAI
SET @ENTRY := 7269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,2000,5000,15000,25000,11,3256,32,0,0,0,0,5,0,0,0,0,0,0,0,"Scarab - In Combat - Cast Plague Cloud");

-- Sandfury Blood Drinker SAI
SET @ENTRY := 5649;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,5500,8000,8000,10000,11,11898,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Blood Drinker - In Combat - Cast Blood Leech");

-- Sandfury Witch Doctor SAI
SET @ENTRY := 5650;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,45000,45000,11,11899,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Witch Doctor - In Combat - Cast Healing Ward"),
(@ENTRY,0,1,0,0,0,85,2,3000,3000,35000,35000,11,8264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Witch Doctor - In Combat - Cast Lava Spout Totem"),
(@ENTRY,0,2,0,2,0,100,2,0,50,12000,12000,11,17843,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Witch Doctor - At 50% HP - Cast Flash Heal");

-- Sandfury Shadowhunter SAI
SET @ENTRY := 7246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowhunter - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,2,7000,12000,18000,25000,11,11641,1,0,0,0,0,6,0,0,0,0,0,0,0,"Sandfury Shadowhunter - In Combat - Cast Hex"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sandfury Shadowhunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowhunter - On Evade - Display melee weapon");

-- Deviate Venomwing SAI
SET @ENTRY := 5756;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,8000,10049,11,7951,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Venomwing - In Combat - Cast Toxic Spit");

-- Deviate Shambler SAI
SET @ENTRY := 5761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,70,21000,21000,11,7948,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Shambler - At 70% HP - Cast Wild Regeneration");

-- Verdan the Everliving SAI
SET @ENTRY := 5775;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,10000,13000,11,8142,0,0,0,0,0,1,0,0,0,0,0,0,0,"Verdan the Everliving - In Combat - Cast Grasping Vines");

-- Sandfury Shadowcaster SAI
SET @ENTRY := 5648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,20798,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - Out Of Combat - Cast Demon Skin"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,2,6000,9000,23000,28000,11,14032,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sandfury Shadowcaster - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,12,0,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sandfury Shadowcaster - At 15% HP - Flee For Assist");

-- Deviate Adder SAI
SET @ENTRY := 5048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,15000,25000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Adder - In Combat - Cast Poison");

-- Deviate Crocolisk SAI
SET @ENTRY := 5053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,10000,12000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Crocolisk - In Combat - Cast Tendon Rip");

-- Deviate Lasher SAI
SET @ENTRY := 5055;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,8000,12000,11,7342,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Lasher - In Combat - Cast Wide Slash");

-- Deviate Dreadfang SAI
SET @ENTRY := 5056;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,15000,15000,20000,25000,11,7399,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Dreadfang - In Combat - Cast Terrify"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,13,0,50,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Dreadfang - In Combat - Remove 50% Threat");

-- Deviate Viper SAI
SET @ENTRY := 5755;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,10000,15000,11,7947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Viper - In Combat - Cast Localized Toxin");

-- Lord Serpentis SAI
SET @ENTRY := 3673;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,34,4,3,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Serpentis - On Death - Set Instance Data 4 to 3");

-- Skum SAI
SET @ENTRY := 3674;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,4000,6000,11,6254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skum - In Combat - Cast Chained Bolt");

-- Druid of the Fang SAI
SET @ENTRY := 3840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Fang - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Fang - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,0,0,100,2,8000,11000,10000,20000,11,8040,33,0,0,0,0,6,0,0,0,0,0,0,0,"Druid of the Fang - In Combat - Cast Druid's Slumber"),
(@ENTRY,0,10,0,14,0,100,2,0,40,12000,18000,11,5187,1,0,0,0,0,7,0,0,0,0,0,0,0,"Druid of the Fang - On Friendly Unit At 0 - 40% Health - Cast Healing Touch"),
(@ENTRY,0,11,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,13,2,0,100,0,0,50,20000,25000,11,8041,1,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 50% HP - Cast Serpent Form"),
(@ENTRY,0,13,14,2,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 50% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - At 50% HP - Set Phase 3"),
(@ENTRY,0,15,16,16,0,100,0,8041,5,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On Friendly Buff Missing - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Fang - On Friendly Buff Missing - Set Phase 1");

-- Mutanus the Devourer SAI
SET @ENTRY := 3654;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,34,9,3,0,0,0,0,1,0,0,0,0,0,0,0,"Mutanus the Devourer - On Death - Set Instance Data 9 to 3");

-- Mad Magglish SAI
SET @ENTRY := 3655;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,1000,1000,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Magglish - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,0,0,100,2,0,0,9000,9000,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Magglish - In Combat - Cast Smoke Bomb");

-- Lord Cobrahn SAI
SET @ENTRY := 3669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,34,1,3,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Cobrahn - On Death - Set Instance Data 1 to 3");

-- Lord Pythas SAI
SET @ENTRY := 3670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,34,2,3,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Pythas - On Death - Set Instance Data 2 to 3");

-- Lady Anacondra SAI
SET @ENTRY := 3671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,34,3,3,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Anacondra - On Death - Set Instance Data 3 to 3");

-- Deviate Stinglash SAI
SET @ENTRY := 3631;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,17000,20000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Stinglash - In Combat - Cast Lash");

-- Deviate Creeper SAI
SET @ENTRY := 3632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,7000,14000,12000,18000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Creeper - In Combat - Cast Infected Wound"),
(@ENTRY,0,1,0,1,0,100,3,0,0,1000,1000,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Creeper - Out Of Combat - Cast Stealth");

-- Deviate Slayer SAI
SET @ENTRY := 3633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,40,10000,10000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deviate Slayer - At 40% HP - Cast Fatal Bite");

-- Deviate Ravager SAI
SET @ENTRY := 3636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,1000,1000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deviate Ravager - Out Of Combat - Cast Thrash");

-- Ymirjar Dusk Shaman SAI
SET @ENTRY := 26694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,2,0,25,12000,15000,11,49204,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ymirjar Dusk Shaman - On Friendly Unit At 0 - 25% Health - Cast Dark Mending"),
(@ENTRY,0,1,0,14,0,100,4,0,20,12000,15000,11,59252,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ymirjar Dusk Shaman - On Friendly Unit At 0 - 20% Health - Cast Dark Mending"),
(@ENTRY,0,2,0,2,0,100,6,0,50,200000,200000,11,49170,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Dusk Shaman - At 50% HP - Cast Lycanthropy");

-- Ymirjar Berserker SAI
SET @ENTRY := 26696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,12000,17000,11,49121,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Berserker - In Combat - Cast Shred"),
(@ENTRY,0,1,0,0,0,100,4,4000,8000,12000,17000,11,61548,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Berserker - In Combat - Cast Shred"),
(@ENTRY,0,2,0,0,0,100,6,10000,15000,20000,23000,11,49106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Berserker - In Combat - Cast Terrify");

-- Ymirjar Necromancer SAI
SET @ENTRY := 28368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,51432,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,5000,7000,11,51432,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,59254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,5000,7000,11,59254,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,2,9000,14000,18000,22000,11,49205,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,15,0,0,0,100,4,9000,14000,18000,22000,11,59255,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Necromancer - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,16,0,2,0,100,7,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 15% HP - Set Phase 3"),
(@ENTRY,0,17,18,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ymirjar Necromancer - At 15% HP - Flee For Assist");

-- Bloodthirsty Tundra Wolf SAI
SET @ENTRY := 26672;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,8000,19000,23000,11,49026,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodthirsty Tundra Wolf - In Combat - Cast Fixate");

-- Ymirjar Savage SAI
SET @ENTRY := 26669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,9000,12000,17000,11,48880,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Savage - In Combat - Cast Rend"),
(@ENTRY,0,1,0,0,0,100,4,6000,9000,12000,17000,11,59239,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Savage - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,17000,23000,11,48876,33,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Savage - In Combat - Cast Beast's Mark"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,17000,23000,11,59237,33,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Savage - In Combat - Cast Beast's Mark");

-- Ymirjar Flesh Hunter SAI
SET @ENTRY := 26670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,15,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Cast Shoot"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,5000,8000,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,4,0,100,0,0,0,0,0,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Cast Shoot"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Aggro - Increment Phase"),
(@ENTRY,0,9,10,9,0,100,0,5,30,5000,8000,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,11,12,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,14,15,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,16,17,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,18,19,0,0,100,0,9000,14000,22000,26000,11,48871,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast Aimed Shot"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Display ranged weapon"),
(@ENTRY,0,20,21,0,0,100,0,9000,14000,22000,26000,11,59243,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast Aimed Shot"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Display ranged weapon"),
(@ENTRY,0,22,23,0,0,100,0,14000,17000,24000,27000,11,48872,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast Multi-Shot"),
(@ENTRY,0,23,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Display ranged weapon"),
(@ENTRY,0,24,25,0,0,100,0,14000,17000,24000,27000,11,59244,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Cast Multi-Shot"),
(@ENTRY,0,25,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - In Combat - Display ranged weapon"),
(@ENTRY,0,26,0,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 15% HP - Increment Phase"),
(@ENTRY,0,27,28,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,28,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,29,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ymirjar Flesh Hunter - On Evade - Display melee weapon");

-- Dragonflayer Deathseeker SAI
SET @ENTRY := 26550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,9000,12000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Deathseeker - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,9000,15000,16000,20000,11,48851,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Deathseeker - In Combat - Cast Grave Strike"),
(@ENTRY,0,2,0,0,0,100,4,9000,15000,16000,20000,11,59079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Deathseeker - In Combat - Cast Grave Strike");

-- Dragonflayer Fanatic SAI
SET @ENTRY := 26553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,20,0,0,11,48702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Fanatic - At 20% HP - Cast Fervor");

-- Dragonflayer Seer SAI
SET @ENTRY := 26554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,48698,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,7000,11000,11,48698,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,59081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,7000,11000,11,59081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Seer - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Seer - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,2,4000,7000,12000,15000,11,48699,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Seer - In Combat - Cast Chain Lightning"),
(@ENTRY,0,15,0,0,0,100,4,4000,7000,12000,15000,11,59082,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Seer - In Combat - Cast Chain Lightning"),
(@ENTRY,0,16,0,14,0,100,2,0,30,18000,21000,11,48700,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Seer - On Friendly Unit At 0 - 30% Health - Cast Healing Wave"),
(@ENTRY,0,17,0,14,0,100,4,0,30,18000,21000,11,59083,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonflayer Seer - On Friendly Unit At 0 - 30% Health - Cast Healing Wave");

-- Savage Worg SAI
SET @ENTRY := 29735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,55077,1,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Worg - On Aggro - Cast Pounce"),
(@ENTRY,0,1,0,2,0,100,7,0,60,14000,16000,11,42745,1,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Worg - At 60% HP - Cast Enrage");

-- Tunneling Ghoul SAI
SET @ENTRY := 24084;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,2000,8000,12000,11,42702,1,0,0,0,0,2,0,0,0,0,0,0,0,"Tunneling Ghoul - In Combat - Cast Decrepify");

-- Ticking Bomb SAI
SET @ENTRY := 29684;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,54955,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Bomb - On Respawn - Cast Ticking Bomb"),
(@ENTRY,0,1,0,0,0,100,3,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Bomb - In Combat - Forced Despawn");

-- Ticking Time Bomb SAI
SET @ENTRY := 32246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,5,0,0,0,0,11,59686,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Time Bomb - On Respawn - Cast Ticking Time Bomb"),
(@ENTRY,0,1,0,0,0,100,5,5500,5500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Time Bomb - In Combat - Forced Despawn");

-- Dragonflayer Weaponsmith SAI
SET @ENTRY := 24080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2500,3000,8000,10000,11,42724,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Weaponsmith - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,6,3500,3500,12000,16000,11,22427,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Weaponsmith - In Combat - Cast Concussion Blow"),
(@ENTRY,0,2,0,0,0,100,6,8000,8500,9000,11000,11,6713,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Weaponsmith - In Combat - Cast Disarm");

-- Dragonflayer Overseer SAI
SET @ENTRY := 24085;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,35570,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Overseer - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,59611,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Overseer - On Aggro - Cast Charge"),
(@ENTRY,0,2,0,0,0,100,2,2000,3000,18000,20000,11,38232,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Overseer - In Combat - Cast Battle Shout"),
(@ENTRY,0,3,0,0,0,100,4,2000,3000,18000,20000,11,59614,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Overseer - In Combat - Cast Battle Shout"),
(@ENTRY,0,4,0,0,0,100,2,7500,8000,20000,30000,11,16244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Overseer - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,5,0,0,0,100,4,7500,8000,20000,30000,11,59613,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Overseer - In Combat - Cast Demoralizing Shout");

-- Dragonflayer Bonecrusher SAI
SET @ENTRY := 24069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,12000,19000,11,9791,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Bonecrusher - In Combat - Cast Head Crack"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,12000,19000,11,59599,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Bonecrusher - In Combat - Cast Head Crack"),
(@ENTRY,0,2,0,0,0,100,6,11000,12000,15000,16500,11,43935,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Bonecrusher - In Combat - Cast Knockdown Spin");

-- Dragonflayer Heartsplitter SAI
SET @ENTRY := 24071;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,500,500,17000,19000,11,43665,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Heartsplitter - In Combat - Cast Throw"),
(@ENTRY,0,1,0,0,0,100,4,500,500,17000,19000,11,59603,1,0,0,0,0,5,0,0,0,0,0,0,0,"Dragonflayer Heartsplitter - In Combat - Cast Throw"),
(@ENTRY,0,2,0,0,0,100,2,6000,7500,11000,17000,11,31551,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Heartsplitter - In Combat - Cast Piercing Jab"),
(@ENTRY,0,3,0,0,0,100,4,6000,7500,11000,17000,11,59605,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Heartsplitter - In Combat - Cast Piercing Jab"),
(@ENTRY,0,4,0,0,0,100,4,3000,4500,9000,12500,11,59604,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Heartsplitter - In Combat - Cast Wing Clip"),
(@ENTRY,0,5,0,0,0,100,2,3000,4500,9000,12500,11,32908,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Heartsplitter - In Combat - Cast Wing Clip");

-- Dragonflayer Ironhelm SAI
SET @ENTRY := 23961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,2000,7000,7000,11,57846,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Ironhelm - In Combat - Cast Heroic Strike"),
(@ENTRY,0,1,0,0,0,100,4,2000,2000,7000,7000,11,59607,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Ironhelm - In Combat - Cast Heroic Strike"),
(@ENTRY,0,2,0,0,0,100,2,4500,5000,8500,10000,11,42780,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Ironhelm - In Combat - Cast Ringing Slap"),
(@ENTRY,0,3,0,0,0,100,4,4500,5000,8500,10000,11,59606,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Ironhelm - In Combat - Cast Ringing Slap");

-- Raging Construct SAI
SET @ENTRY := 27970;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,20000,30000,45000,11,51819,1,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Construct - In Combat - Cast Potent Jolt"),
(@ENTRY,0,1,0,0,0,100,4,10000,20000,30000,45000,11,61514,1,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Construct - In Combat - Cast Potent Jolt"),
(@ENTRY,0,2,0,0,0,100,6,4000,7000,9000,12000,11,28168,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Construct - In Combat - Cast Arcing Smash");

-- Unrelenting Construct SAI
SET @ENTRY := 27971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,51842,0,0,0,0,0,5,0,0,0,0,0,0,0,"Unrelenting Construct - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,59040,0,0,0,0,0,5,0,0,0,0,0,0,0,"Unrelenting Construct - On Aggro - Cast Charge"),
(@ENTRY,0,2,0,0,0,100,2,12000,18000,12000,18000,11,51842,0,0,0,0,0,5,0,0,0,0,0,0,0,"Unrelenting Construct - In Combat - Cast Charge"),
(@ENTRY,0,3,0,0,0,100,4,12000,18000,12000,18000,11,59040,0,0,0,0,0,5,0,0,0,0,0,0,0,"Unrelenting Construct - In Combat - Cast Charge"),
(@ENTRY,0,4,0,0,0,100,2,4000,7000,9000,16000,11,51491,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unrelenting Construct - In Combat - Cast Unrelenting Strike"),
(@ENTRY,0,5,0,0,0,100,4,4000,7000,9000,16000,11,59039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unrelenting Construct - In Combat - Cast Unrelenting Strike"),
(@ENTRY,0,6,0,2,0,100,3,0,10,0,0,11,51832,7,0,0,0,0,1,0,0,0,0,0,0,0,"Unrelenting Construct - At 10% HP - Cast Short Circuit"),
(@ENTRY,0,7,0,2,0,100,5,0,10,0,0,11,61513,7,0,0,0,0,1,0,0,0,0,0,0,0,"Unrelenting Construct - At 10% HP - Cast Short Circuit");

-- Lightning Construct SAI
SET @ENTRY := 27972;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,9000,15000,11,52383,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lightning Construct - In Combat - Cast Chain Lightning"),
(@ENTRY,0,1,0,0,0,100,4,3000,6000,9000,15000,11,61528,0,0,0,0,0,5,0,0,0,0,0,0,0,"Lightning Construct - In Combat - Cast Chain Lightning"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,52341,7,0,0,0,0,1,0,0,0,0,0,0,0,"Lightning Construct - On Death - Cast Electrical Overload"),
(@ENTRY,0,3,0,6,0,100,5,0,0,0,0,11,59038,7,0,0,0,0,1,0,0,0,0,0,0,0,"Lightning Construct - On Death - Cast Electrical Overload");

-- Dark Rune Shaper SAI
SET @ENTRY := 27965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,51496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper - On Aggro - Cast Chiseling Ray"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,6000,9000,11,51496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper - At 0 - 40 Range - Cast Chiseling Ray"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,59034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper - On Aggro - Cast Chiseling Ray"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,6000,9000,11,59034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Shaper - At 0 - 40 Range - Cast Chiseling Ray"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Shaper - At 100% Mana - Increment Phase");

-- Dark Rune Controller SAI
SET @ENTRY := 27966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,51507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Controller - On Aggro - Cast Summon Shardling"),
(@ENTRY,0,1,0,0,0,100,6,5000,10000,17000,25000,11,51503,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Rune Controller - In Combat - Cast Domination"),
(@ENTRY,0,2,0,16,0,100,6,51805,15,14000,17000,11,51805,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Rune Controller - On Friendly Buff Missing - Cast Crystalline Growth");

-- Dark Rune Giant SAI
SET @ENTRY := 27969;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,6000,16000,21000,11,51493,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Giant - In Combat - Cast Stomp"),
(@ENTRY,0,1,0,0,0,100,4,3000,6000,16000,21000,11,59026,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Giant - In Combat - Cast Stomp"),
(@ENTRY,0,2,0,2,0,100,6,0,30,30000,38000,11,51494,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Giant - At 30% HP - Cast Iron Fist");

-- Dark Rune Scholar SAI
SET @ENTRY := 27964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,51799,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Scholar - On Aggro - Cast Runic Intellect"),
(@ENTRY,0,1,0,13,0,100,2,13000,16000,0,0,11,51612,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Rune Scholar - On Target Casting - Cast Static Arrest"),
(@ENTRY,0,2,0,13,0,100,4,13000,16000,0,0,11,59033,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Rune Scholar - On Target Casting - Cast Static Arrest");

-- Titanium Siegebreaker SAI
SET @ENTRY := 28961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,40,10000,15000,11,52891,7,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Siegebreaker - At 40% HP - Cast Blade Turning"),
(@ENTRY,0,1,0,2,0,100,4,0,50,10000,15000,11,59173,7,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Siegebreaker - At 50% HP - Cast Blade Turning"),
(@ENTRY,0,2,3,7,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Siegebreaker - On Evade - Set Phase 5"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Siegebreaker - On Evade - Display melee weapon");

-- Titanium Thunderer SAI
SET @ENTRY := 28965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,40,12000,18000,11,52879,7,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Thunderer - At 40% HP - Cast Deflection"),
(@ENTRY,0,1,0,2,0,100,4,0,65,12000,18000,11,59181,7,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Thunderer - At 65% HP - Cast Deflection"),
(@ENTRY,0,2,3,7,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Thunderer - On Evade - Set Phase 5"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanium Thunderer - On Evade - Display melee weapon");

-- Dark Rune Warrior SAI
SET @ENTRY := 27960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,12000,11,53395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Warrior - In Combat - Cast Heroic Strike"),
(@ENTRY,0,1,0,0,0,100,4,3000,7000,9000,12000,11,59035,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Warrior - In Combat - Cast Heroic Strike"),
(@ENTRY,0,2,0,0,0,100,6,9000,12000,9000,12000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Warrior - In Combat - Cast Cleave");

-- Dark Rune Worker SAI
SET @ENTRY := 27961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,45000,45000,11,46202,32,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Rune Worker - At 0 - 5 Range - Cast Pierce Armor"),
(@ENTRY,0,1,0,2,0,100,7,0,30,0,0,11,51499,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Rune Worker - At 30% HP - Cast Disgruntled Anger");

-- Stormforged Giant SAI
SET @ENTRY := 28920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,7000,8000,11000,11,53072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Giant - In Combat - Cast Stormbolt"),
(@ENTRY,0,1,0,0,0,100,4,0,7000,8000,11000,11,59155,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Giant - In Combat - Cast Stormbolt"),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,9000,15000,11,53071,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Giant - In Combat - Cast Thunderstorm"),
(@ENTRY,0,3,0,0,0,100,4,13000,17000,9000,15000,11,59154,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Giant - In Combat - Cast Thunderstorm"),
(@ENTRY,0,4,0,2,0,100,4,0,50,11000,19000,11,32315,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Giant - At 50% HP - Cast Soul Strike");

-- Stormfury Revenant SAI
SET @ENTRY := 28826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,5000,17000,23000,11,53043,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormfury Revenant - In Combat - Cast Electro Shock"),
(@ENTRY,0,1,0,0,0,100,4,0,5000,17000,23000,11,59168,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormfury Revenant - In Combat - Cast Electro Shock"),
(@ENTRY,0,2,0,0,0,100,2,14000,16000,15000,18000,11,52905,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormfury Revenant - In Combat - Cast Thunderbolt"),
(@ENTRY,0,3,0,0,0,100,4,14000,16000,15000,18000,11,59167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormfury Revenant - In Combat - Cast Thunderbolt");

-- Stormforged Construct SAI
SET @ENTRY := 28835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,4000,7000,1000,14000,11,53167,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Construct - In Combat - Cast Forked Lightning"),
(@ENTRY,0,1,0,0,0,75,4,4000,7000,9000,14000,11,59152,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Construct - In Combat - Cast Forked Lightning"),
(@ENTRY,0,2,0,9,0,100,2,0,5,12000,18000,11,61596,0,0,0,0,0,6,0,0,0,0,0,0,0,"Stormforged Construct - At 0 - 5 Range - Cast Runic Focus"),
(@ENTRY,0,3,0,9,0,100,4,0,5,12000,18000,11,61579,0,0,0,0,0,6,0,0,0,0,0,0,0,"Stormforged Construct - At 0 - 5 Range - Cast Runic Focus"),
(@ENTRY,0,4,0,2,0,100,2,0,65,11000,15000,11,53068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Construct - At 65% HP - Cast Rune Punch"),
(@ENTRY,0,5,0,2,0,100,4,0,75,11000,15000,11,59151,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Construct - At 75% HP - Cast Rune Punch");

-- Stormforged Runeshaper SAI
SET @ENTRY := 28836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,17000,21000,11,53048,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Runeshaper - In Combat - Cast Startling Roar"),
(@ENTRY,0,1,0,0,0,100,2,7000,10000,24000,30000,11,53049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Runeshaper - In Combat - Cast Charged Flurry"),
(@ENTRY,0,2,0,0,0,100,4,7000,10000,24000,30000,11,61581,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Runeshaper - In Combat - Cast Charged Flurry");

-- Stormforged Sentinel SAI
SET @ENTRY := 28837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9000,17000,20000,25000,11,53045,0,0,0,0,0,6,0,0,0,0,0,0,0,"Stormforged Sentinel - In Combat - Cast Sleep"),
(@ENTRY,0,1,0,0,0,100,4,7000,9000,20000,25000,11,59165,0,0,0,0,0,6,0,0,0,0,0,0,0,"Stormforged Sentinel - In Combat - Cast Sleep"),
(@ENTRY,0,2,0,14,0,100,2,0,40000,9000,15000,11,34423,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormforged Sentinel - On Friendly Unit At 0 - 40000% Health - Cast Renew"),
(@ENTRY,0,3,0,14,0,100,4,0,50000,9000,15000,11,37978,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormforged Sentinel - On Friendly Unit At 0 - 50000% Health - Cast Renew"),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,53047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Sentinel - At 30% HP - Cast Storming Bellow");

-- Stormforged Tactician SAI
SET @ENTRY := 28581;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,9000,11000,14000,11,52778,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Tactician - In Combat - Cast Welding Beam"),
(@ENTRY,0,1,0,0,0,100,4,0,9000,11000,14000,11,59166,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Tactician - In Combat - Cast Welding Beam"),
(@ENTRY,0,2,0,2,0,100,6,0,50,15000,27000,11,59085,0,0,0,0,0,6,0,0,0,0,0,0,0,"Stormforged Tactician - At 50% HP - Cast Arc Weld");

-- Stormforged Mender SAI
SET @ENTRY := 28582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,3,0,40,0,0,11,52774,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormforged Mender - On Friendly Unit At 0 - 40% Health - Cast Renew Steel"),
(@ENTRY,0,1,0,14,0,100,5,0,40,0,0,11,59160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormforged Mender - On Friendly Unit At 0 - 40% Health - Cast Renew Steel"),
(@ENTRY,0,2,0,2,0,100,6,0,80,10000,13000,11,52773,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Mender - At 80% HP - Cast Hammer Blow");

-- Blistering Steamrager SAI
SET @ENTRY := 28583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,10,9000,12000,11,52531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blistering Steamrager - At 0 - 10 Range - Cast Steam Blast"),
(@ENTRY,0,1,0,9,0,100,4,0,10,9000,12000,11,59141,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blistering Steamrager - At 0 - 10 Range - Cast Steam Blast");

-- Unbound Firestorm SAI
SET @ENTRY := 28584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,6000,8000,12000,11,53788,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Firestorm - In Combat - Cast Lava Burst"),
(@ENTRY,0,1,0,0,0,100,4,0,6000,8000,12000,11,59182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Firestorm - In Combat - Cast Lava Burst"),
(@ENTRY,0,2,0,2,0,100,2,0,75,16000,22000,11,52624,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Firestorm - At 75% HP - Cast Afterburn"),
(@ENTRY,0,3,0,2,0,100,4,0,75,16000,22000,11,59183,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Firestorm - At 75% HP - Cast Afterburn");

-- Hardened Steel Reaver SAI
SET @ENTRY := 28578;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,6000,10000,11,42724,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Reaver - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,9000,18000,12000,24000,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Reaver - In Combat - Cast Shield Slam"),
(@ENTRY,0,2,0,0,0,100,4,9000,18000,12000,24000,11,59142,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hardened Steel Reaver - In Combat - Cast Shield Slam");

-- Stonevault Flameweaver SAI
SET @ENTRY := 7321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,7000,17000,21000,11,2941,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stonevault Flameweaver - In Combat - Cast Immolate"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,18000,21000,11,2602,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Flameweaver - In Combat - Cast Fire Shield IV"),
(@ENTRY,0,2,0,0,0,100,2,15000,18000,15000,21000,11,7739,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Flameweaver - In Combat - Cast Inferno Shell"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Flameweaver - At 15% HP - Flee For Assist");

-- Earthen Stonebreaker SAI
SET @ENTRY := 7396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stonebreaker - On Aggro - Cast Battle Stance"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,4500,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stonebreaker - In Combat - Cast Strike");

-- Earthen Stonecarver SAI
SET @ENTRY := 7397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,5000,8000,11,10452,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Stonecarver - In Combat - Cast Flame Buffet"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,18000,21000,11,2602,1,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Stonecarver - In Combat - Cast Fire Shield IV");

-- Ancient Stone Keeper SAI
SET @ENTRY := 7206;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,45000,45000,11,10094,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Stone Keeper - In Combat - Cast Sand Storms"),
(@ENTRY,0,1,0,0,0,100,2,20000,20000,45000,45000,11,10132,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Stone Keeper - In Combat - Cast Sand Storms");

-- Obsidian Sentinel SAI
SET @ENTRY := 7023;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,80,0,0,11,10061,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 80% HP - Cast Summon Obsidian Shard"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,10072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 80% HP - Cast Splintered Obsidian"),
(@ENTRY,0,2,3,2,0,100,0,0,60,0,0,11,10061,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 60% HP - Cast Summon Obsidian Shard"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,10072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 60% HP - Cast Splintered Obsidian"),
(@ENTRY,0,4,5,2,0,100,0,0,40,0,0,11,10061,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 40% HP - Cast Summon Obsidian Shard"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,11,10072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 40% HP - Cast Splintered Obsidian"),
(@ENTRY,0,6,7,2,0,100,0,0,20,0,0,11,10061,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 20% HP - Cast Summon Obsidian Shard"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,11,10072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Sentinel - At 20% HP - Cast Splintered Obsidian");

-- Shadowforge Geologist SAI
SET @ENTRY := 7030;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,11000,16000,12000,16000,11,8814,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Geologist - In Combat - Cast Flame Spike"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,11000,17000,11,3356,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Geologist - In Combat - Cast Flame Lash");

-- Cleft Scorpid SAI
SET @ENTRY := 7078;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,6000,10000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Cleft Scorpid - In Combat - Cast Poison");

-- Shadowforge Ambusher SAI
SET @ENTRY := 7091;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Ambusher - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,11000,15000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Ambusher - In Combat - Cast Disarm"),
(@ENTRY,0,2,0,0,0,100,2,9000,13000,16000,20000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Ambusher - In Combat - Cast Shield Bash");

-- Earthen Rocksmasher SAI
SET @ENTRY := 7011;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Rocksmasher - On Aggro - Cast Battle Stance"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,4500,9000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Rocksmasher - In Combat - Cast Strike");

-- Earthen Sculptor SAI
SET @ENTRY := 7012;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3000,5000,8000,11,10452,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Sculptor - In Combat - Cast Flame Buffet"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,18000,21000,11,2602,1,0,0,0,0,1,0,0,0,0,0,0,0,"Earthen Sculptor - In Combat - Cast Fire Shield IV");

-- Venomlash Scorpid SAI
SET @ENTRY := 7022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,11000,11,8257,32,0,0,0,0,2,0,0,0,0,0,0,0,"Venomlash Scorpid - In Combat - Cast Venom Sting");

-- Eric "The Swift" SAI
SET @ENTRY := 6907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,7000,9000,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eric ""The Swift"" - In Combat - Cast Rushing Charge");

-- Olaf SAI
SET @ENTRY := 6908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,8000,11000,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Olaf - In Combat - Cast Shield Slam");

-- Stone Steward SAI
SET @ENTRY := 4860;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,12000,17000,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stone Steward - In Combat - Cast Ground Tremor");

-- Shrike Bat SAI
SET @ENTRY := 4861;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,14000,18000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shrike Bat - In Combat - Cast Sonic Burst");

-- Stonevault Oracle SAI
SET @ENTRY := 4852;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,20000,20000,11,8005,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Oracle - At 50% HP - Cast Healing Wave"),
(@ENTRY,0,1,0,0,0,100,2,100,100,45000,45000,11,945,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Oracle - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,2,8000,11000,48000,55000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Oracle - In Combat - Cast Healing Ward"),
(@ENTRY,0,3,0,0,0,100,2,4000,4000,30000,35000,11,8264,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Oracle - In Combat - Cast Lava Spout Totem"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Oracle - At 15% HP - Flee For Assist");

-- Shadowforge Archaeologist SAI
SET @ENTRY := 4849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Archaeologist - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,2,5000,7000,11000,14000,11,6713,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Archaeologist - In Combat - Cast Disarm"),
(@ENTRY,0,2,0,0,0,100,2,11000,14000,16000,20000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Archaeologist - In Combat - Cast Shield Bash");

-- Stonevault Cave Lurker SAI
SET @ENTRY := 4850;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Lurker - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,4000,7000,11,8721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Cave Lurker - In Combat - Cast Backstab");

-- Chaos Watcher SAI
SET @ENTRY := 32235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,4000,6000,11,54527,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chaos Watcher - At 0 - 8 Range - Cast Corrosive Saliva"),
(@ENTRY,0,1,0,0,0,100,6,7000,11000,17000,21000,11,54396,1,0,0,0,0,2,0,0,0,0,0,0,0,"Chaos Watcher - In Combat - Cast Optic Link");

-- Lava Hound SAI
SET @ENTRY := 32237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,4,4000,7000,10000,14000,11,59468,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Hound - In Combat - Cast Firebolt"),
(@ENTRY,0,1,0,0,0,100,4,11000,15000,30000,40000,11,54249,1,0,0,0,0,5,0,0,0,0,0,0,0,"Lava Hound - In Combat - Cast Lava Burn"),
(@ENTRY,0,2,0,0,0,100,4,8000,11000,16000,22000,11,59469,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lava Hound - In Combat - Cast Flame Breath"),
(@ENTRY,0,3,0,0,0,100,4,1000,3000,30000,45000,11,59466,33,0,0,0,0,5,0,0,0,0,0,0,0,"Lava Hound - In Combat - Cast Cauterizing Flames");

-- Ethereal Sphere SAI
SET @ENTRY := 32582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,5,0,0,0,0,41,40000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereal Sphere - On Respawn - Forced Despawn"),
(@ENTRY,0,1,0,10,0,100,4,1,5,10000,14000,11,59474,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereal Sphere - On LOS Out Of Combat - Cast Arcane Power");

-- Shadowforge Relic Hunter SAI
SET @ENTRY := 4847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,12000,19000,11,2767,32,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Relic Hunter - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,12000,16000,11,6726,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Relic Hunter - In Combat - Cast Silence"),
(@ENTRY,0,2,0,2,0,100,2,0,50,15000,20000,11,6064,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Relic Hunter - At 50% HP - Cast Heal");

-- Azure Mage Slayer SAI
SET @ENTRY := 31010;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,5000,14000,20000,11,58469,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Mage Slayer - In Combat - Cast Arcane Empowerment");

-- Azure Saboteur SAI
SET @ENTRY := 31079;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58291,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Saboteur - Out Of Combat - Cast Shield Disruption");

-- Azure Stalker SAI
SET @ENTRY := 32191;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Stalker - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,9,0,100,6,0,5,5000,7000,11,58471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Stalker - At 0 - 5 Range - Cast Backstab"),
(@ENTRY,0,2,0,0,0,100,6,11000,16000,13000,21000,11,58470,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Stalker - In Combat - Cast Tactical Blink");

-- Arakkoa Talon Guard SAI
SET @ENTRY := 32228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,8,10000,16000,11,54462,1,0,0,0,0,1,0,0,0,0,0,0,0,"Arakkoa Talon Guard - At 0 - 8 Range - Cast Howling Screech"),
(@ENTRY,0,1,0,0,0,100,6,5000,7000,5000,7000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arakkoa Talon Guard - In Combat - Cast Strike"),
(@ENTRY,0,2,0,0,0,100,6,9000,14000,25000,30000,11,39215,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arakkoa Talon Guard - In Combat - Cast Gushing Wound");

-- Void Lord SAI
SET @ENTRY := 32230;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,10000,9000,14000,11,59743,0,0,0,0,0,5,0,0,0,0,0,0,0,"Void Lord - In Combat - Cast Void Shift"),
(@ENTRY,0,1,0,0,0,100,6,3000,5000,12000,17000,11,59745,1,0,0,0,0,1,0,0,0,0,0,0,0,"Void Lord - In Combat - Cast Shroud of Darkness"),
(@ENTRY,0,2,0,0,0,100,6,1000,3000,30000,45000,11,54369,0,0,0,0,0,1,0,0,0,0,0,0,0,"Void Lord - In Combat - Cast Summon Void Sentry");

-- Azure Invader SAI
SET @ENTRY := 31008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,13000,16000,11,58459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - At 0 - 5 Range - Cast Impale"),
(@ENTRY,0,1,0,9,0,100,4,0,5,13000,16000,11,59256,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - At 0 - 5 Range - Cast Impale"),
(@ENTRY,0,2,0,0,0,100,6,8000,11000,5000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - In Combat - Cast Cleave");

-- Azure Spellbreaker SAI
SET @ENTRY := 31009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,13000,16000,11,58462,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Spellbreaker - At 0 - 30 Range - Cast Arcane Blast"),
(@ENTRY,0,1,0,9,0,100,4,0,30,13000,16000,11,59257,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Spellbreaker - At 0 - 30 Range - Cast Arcane Blast"),
(@ENTRY,0,2,0,0,0,100,6,3000,6000,7000,10000,11,25603,1,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellbreaker - In Combat - Cast Slow");

-- Azure Invader SAI
SET @ENTRY := 30961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Invader - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,9,0,100,6,0,5,5000,9000,11,58461,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - At 0 - 5 Range - Cast Sunder Armor"),
(@ENTRY,0,2,0,0,0,100,6,3000,6000,7000,12000,11,58460,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - In Combat - Cast Brutal Strike");

-- Azure Spellbreaker SAI
SET @ENTRY := 30962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbreaker - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,0,0,100,2,7000,11000,11000,17000,11,58463,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbreaker - In Combat - Cast Cone of Cold"),
(@ENTRY,0,2,0,0,0,100,4,7000,11000,11000,17000,11,59258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbreaker - In Combat - Cast Cone of Cold"),
(@ENTRY,0,3,0,9,0,100,6,0,30,9000,13000,11,58464,1,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Spellbreaker - At 0 - 30 Range - Cast Chains of Ice");

-- Azure Mage Slayer SAI
SET @ENTRY := 30963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Mage Slayer - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,13,0,100,7,0,0,0,0,11,30849,1,0,0,0,0,7,0,0,0,0,0,0,0,"Azure Mage Slayer - On Target Casting - Cast Spell Lock");

-- Portal Guardian SAI
SET @ENTRY := 30892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,10000,11000,16000,11,58526,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Guardian - In Combat - Cast Azure Bindings"),
(@ENTRY,0,1,0,9,0,100,2,0,5,13000,21000,11,58517,32,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Guardian - At 0 - 5 Range - Cast Grievous Wound"),
(@ENTRY,0,2,0,9,0,100,4,0,5,13000,21000,11,59262,32,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Guardian - At 0 - 5 Range - Cast Grievous Wound"),
(@ENTRY,0,3,0,9,0,100,6,0,5,7000,12000,11,58516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Guardian - At 0 - 5 Range - Cast Overpower");

-- Azure Raider SAI
SET @ENTRY := 30668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Raider - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,9,0,100,6,0,8,9000,14000,11,52719,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Raider - At 0 - 8 Range - Cast Concussion Blow"),
(@ENTRY,0,2,0,0,0,100,6,7000,14000,12000,18000,11,60158,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Raider - In Combat - Cast Magic Reflection");

-- Portal Keeper SAI
SET @ENTRY := 30695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,58531,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Cast Arcane Missiles"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,45,6000,8000,11,58531,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 45 Range - Cast Arcane Missiles"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,61593,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Cast Arcane Missiles"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,45,6000,8000,11,61593,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 45 Range - Cast Arcane Missiles"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,40,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 40 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,9,0,100,2,0,8,13000,19000,11,58532,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 8 Range - Cast Frostbolt Volley"),
(@ENTRY,0,14,0,9,0,100,4,0,8,13000,19000,11,61594,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 8 Range - Cast Frostbolt Volley"),
(@ENTRY,0,15,0,0,0,100,6,0,8,9000,14000,11,58534,1,0,0,0,0,6,0,0,0,0,0,0,0,"Portal Keeper - In Combat - Cast Deep Freeze"),
(@ENTRY,0,16,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 100% Mana - Increment Phase");

-- Portal Keeper SAI
SET @ENTRY := 30893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,58536,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Cast Arcane Volley"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,45,6000,8000,11,58536,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 45 Range - Cast Arcane Volley"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,61591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Cast Arcane Volley"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,45,6000,8000,11,61591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 45 Range - Cast Arcane Volley"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,40,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 40 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,9,0,100,2,0,45,13000,19000,11,58535,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 45 Range - Cast Frostbolt"),
(@ENTRY,0,14,0,9,0,100,4,0,45,13000,19000,11,61590,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Keeper - At 0 - 45 Range - Cast Frostbolt"),
(@ENTRY,0,15,0,0,0,100,6,0,8,9000,14000,11,58537,1,0,0,0,0,6,0,0,0,0,0,0,0,"Portal Keeper - In Combat - Cast Polymorph"),
(@ENTRY,0,16,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Portal Keeper - At 100% Mana - Increment Phase");

-- Azure Captain SAI
SET @ENTRY := 30666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Captain - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,9,0,100,6,0,5,5000,9000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Captain - At 0 - 5 Range - Cast Whirlwind"),
(@ENTRY,0,2,0,0,0,100,6,3000,6000,7000,10000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Captain - In Combat - Cast Mortal Strike");

-- Azure Sorceror SAI
SET @ENTRY := 30667;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,60181,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Sorceror - On Aggro - Cast Arcane Stream"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,2,5,35,6000,8000,11,60181,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Sorceror - At 5 - 35 Range - Cast Arcane Stream"),
(@ENTRY,0,6,7,4,0,100,0,0,0,0,0,11,60204,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Sorceror - On Aggro - Cast Arcane Stream"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - On Aggro - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,4,5,35,6000,8000,11,60204,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Sorceror - At 5 - 35 Range - Cast Arcane Stream"),
(@ENTRY,0,9,10,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 7% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,100,7,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 30 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,14,0,9,0,100,2,0,8,9000,15000,11,60182,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 0 - 8 Range - Cast Mana Detonation"),
(@ENTRY,0,15,0,9,0,100,4,0,8,9000,15000,11,60205,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 0 - 8 Range - Cast Mana Detonation"),
(@ENTRY,0,16,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Sorceror - At 100% Mana - Increment Phase");

-- Azure Mage Slayer SAI
SET @ENTRY := 30664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Mage Slayer - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,0,0,100,6,1000,5000,14000,20000,11,58469,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Mage Slayer - In Combat - Cast Arcane Empowerment");

-- Portal Guardian SAI
SET @ENTRY := 30660;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,6000,9000,11,58504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Portal Guardian - In Combat - Cast Agonizing Strike"),
(@ENTRY,0,1,0,0,0,100,6,7000,12000,9000,11000,11,58508,0,0,0,0,0,5,0,0,0,0,0,0,0,"Portal Guardian - In Combat - Cast Side Swipe");

-- Azure Invader SAI
SET @ENTRY := 30661;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Invader - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,9,0,100,2,0,5,13000,16000,11,58459,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - At 0 - 5 Range - Cast Impale"),
(@ENTRY,0,2,0,9,0,100,4,0,5,13000,16000,11,59256,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - At 0 - 5 Range - Cast Impale"),
(@ENTRY,0,3,0,0,0,100,6,8000,11000,5000,9000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Invader - In Combat - Cast Cleave");

-- Azure Spellbreaker SAI
SET @ENTRY := 30662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,58040,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Spellbreaker - Out Of Combat - Cast Destroy Door Seal"),
(@ENTRY,0,1,0,9,0,100,2,0,30,13000,16000,11,58462,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Spellbreaker - At 0 - 30 Range - Cast Arcane Blast"),
(@ENTRY,0,2,0,9,0,100,4,0,30,13000,16000,11,59257,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Spellbreaker - At 0 - 30 Range - Cast Arcane Blast"),
(@ENTRY,0,3,0,0,0,100,6,3000,6000,7000,10000,11,25603,1,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellbreaker - In Combat - Cast Slow");

-- Hamhock SAI
SET @ENTRY := 1717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5800,9700,10500,10500,11,6742,32,0,0,0,0,1,0,0,0,0,0,0,0,"Hamhock - In Combat - Cast Bloodlust"),
(@ENTRY,0,1,0,0,0,100,2,5800,8100,12900,19400,11,421,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hamhock - In Combat - Cast Chain Lightning");

-- Bruegal Ironknuckle SAI
SET @ENTRY := 1720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bruegal Ironknuckle - At 15% HP - Flee For Assist");

-- Defias Inmate SAI
SET @ENTRY := 1708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Inmate - Out Of Combat - Cast Battle Stance"),
(@ENTRY,0,1,0,0,0,100,2,1900,11800,14200,36200,11,6547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Inmate - In Combat - Cast Rend"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Inmate - At 15% HP - Flee For Assist");

-- Defias Convict SAI
SET @ENTRY := 1711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,674,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Convict - Out Of Combat - Cast Dual Wield"),
(@ENTRY,0,1,0,0,0,100,2,0,7700,10300,13800,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Convict - In Combat - Cast Backhand"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Convict - At 15% HP - Flee For Assist");

-- Defias Insurgent SAI
SET @ENTRY := 1715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7300,23100,20200,39400,11,9128,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Insurgent - In Combat - Cast Battle Shout"),
(@ENTRY,0,1,0,0,0,100,2,9200,30600,19800,24900,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Insurgent - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Insurgent - At 15% HP - Flee For Assist");

-- Defias Prisoner SAI
SET @ENTRY := 1706;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,14700,10400,15200,11,1766,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Prisoner - In Combat - Cast Kick"),
(@ENTRY,0,1,0,0,0,100,2,5900,22400,9600,16600,11,6713,1,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Prisoner - In Combat - Cast Disarm"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Prisoner - At 15% HP - Flee For Assist"),
(@ENTRY,0,3,0,11,0,100,3,1,34,0,0,2,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Prisoner - On Respawn - Set Faction 17");

-- Defias Captive SAI
SET @ENTRY := 1707;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2100,4000,2200,7100,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Captive - In Combat - Cast Backstab"),
(@ENTRY,0,1,0,0,0,100,2,1800,13500,1000,9500,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Captive - In Combat - Cast Infected Wound"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Captive - At 15% HP - Flee For Assist");

-- Greater Ley-Whelp SAI
SET @ENTRY := 28276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,20,7000,11000,11,51243,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Ley-Whelp - At 0 - 20 Range - Cast Arcane Bolt"),
(@ENTRY,0,1,0,9,0,100,4,0,20,7000,11000,11,59215,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greater Ley-Whelp - At 0 - 20 Range - Cast Arcane Bolt");

-- Dextren Ward SAI
SET @ENTRY := 1663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dextren Ward - Out Of Combat - Cast Battle Stance"),
(@ENTRY,0,1,0,0,0,100,2,7000,9600,14000,22300,11,19134,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dextren Ward - In Combat - Cast Frightening Shout"),
(@ENTRY,0,2,0,0,0,100,2,4800,7200,9600,21600,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dextren Ward - In Combat - Cast Strike"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dextren Ward - At 15% HP - Flee For Assist");

-- Kam Deepfury SAI
SET @ENTRY := 1666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,1200,5900,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kam Deepfury - In Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,2,2400,5900,9300,24600,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kam Deepfury - In Combat - Cast Shield Slam"),
(@ENTRY,0,2,0,0,0,100,2,16200,16200,18200,26400,11,3419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kam Deepfury - In Combat - Cast Improved Blocking"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kam Deepfury - At 15% HP - Flee For Assist");

-- Ring-Lord Conjurer SAI
SET @ENTRY := 27640;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,50717,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Conjurer - On Aggro - Cast Charged Skin"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,59276,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ring-Lord Conjurer - On Aggro - Cast Charged Skin");

-- Azure Ring Guardian SAI
SET @ENTRY := 27638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,9000,14000,11,49549,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Ring Guardian - In Combat - Cast Ice Beam"),
(@ENTRY,0,1,0,0,0,100,4,4000,8000,9000,14000,11,59211,0,0,0,0,0,5,0,0,0,0,0,0,0,"Azure Ring Guardian - In Combat - Cast Ice Beam");

-- Grand Magus Telestra SAI
SET @ENTRY := 26930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,8000,9000,11,47729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Ice Barb"),
(@ENTRY,0,1,0,0,0,100,4,3000,3000,8000,9000,11,56937,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Ice Barb"),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,15000,16000,11,47727,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Blizzard"),
(@ENTRY,0,3,0,0,0,100,4,9000,9000,15000,16000,11,56936,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Blizzard"),
(@ENTRY,0,4,5,6,0,100,0,0,0,0,0,11,47712,18,0,0,0,0,7,0,0,0,0,0,0,0,"Grand Magus Telestra - On Death - Cast Telestra Clone Dies (Frost)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Magus Telestra - On Death - Forced Despawn");

-- Horde Commander SAI
SET @ENTRY := 27947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Commander - On Aggro - Remove Aura Frozen Prison"),
(@ENTRY,0,1,0,0,0,100,6,3000,4000,11000,15000,11,60067,7,0,0,0,0,6,0,0,0,0,0,0,0,"Horde Commander - In Combat - Cast Charge"),
(@ENTRY,0,2,0,0,0,100,6,6000,8000,19500,25000,11,38618,5,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Commander - In Combat - Cast Whirlwind");

-- Alliance Commander SAI
SET @ENTRY := 27949;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Commander - On Aggro - Remove Aura Frozen Prison"),
(@ENTRY,0,1,0,0,0,100,6,3000,4000,11000,15000,11,60067,7,0,0,0,0,6,0,0,0,0,0,0,0,"Alliance Commander - In Combat - Cast Charge"),
(@ENTRY,0,2,0,0,0,100,6,6000,8000,19500,25000,11,38618,5,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Commander - In Combat - Cast Whirlwind");

-- Crystalline Tender SAI
SET @ENTRY := 28231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12000,15000,19500,35000,11,51972,3,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalline Tender - In Combat - Cast Tranquility"),
(@ENTRY,0,1,0,0,0,100,4,12000,15000,19500,35000,11,57054,3,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalline Tender - In Combat - Cast Tranquility"),
(@ENTRY,0,2,0,0,0,100,6,2000,5000,11100,19000,11,50994,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalline Tender - In Combat - Cast Toughen Hide");

-- Horde Cleric SAI
SET @ENTRY := 26803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Cleric - On Aggro - Remove Aura Frozen Prison"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,9500,15000,11,17139,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Cleric - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,2,0,0,0,100,4,2000,4000,9500,15000,11,35944,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Cleric - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,3,0,0,0,100,2,9000,11000,9500,15000,11,47697,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Cleric - In Combat - Cast Shadow Word: Death"),
(@ENTRY,0,4,0,0,0,100,4,9000,11000,9500,15000,11,56920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Cleric - In Combat - Cast Shadow Word: Death"),
(@ENTRY,0,5,0,14,0,100,2,0,25,12100,19000,11,17843,1,0,0,0,0,7,0,0,0,0,0,0,0,"Horde Cleric - On Friendly Unit At 0 - 25% Health - Cast Flash Heal"),
(@ENTRY,0,6,0,14,0,100,4,0,25,12100,19000,11,56919,1,0,0,0,0,7,0,0,0,0,0,0,0,"Horde Cleric - On Friendly Unit At 0 - 25% Health - Cast Flash Heal");

-- Alliance Cleric SAI
SET @ENTRY := 26805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Cleric - On Aggro - Remove Aura Frozen Prison"),
(@ENTRY,0,1,0,0,0,100,2,2000,4000,9500,15000,11,17139,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Cleric - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,2,0,0,0,100,4,2000,4000,9500,15000,11,35944,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Cleric - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,3,0,0,0,100,2,9000,11000,9500,15000,11,47697,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Cleric - In Combat - Cast Shadow Word: Death"),
(@ENTRY,0,4,0,0,0,100,4,9000,11000,9500,15000,11,56920,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alliance Cleric - In Combat - Cast Shadow Word: Death"),
(@ENTRY,0,5,0,14,0,100,2,0,25,12100,19000,11,17843,1,0,0,0,0,7,0,0,0,0,0,0,0,"Alliance Cleric - On Friendly Unit At 0 - 25% Health - Cast Flash Heal"),
(@ENTRY,0,6,0,14,0,100,4,0,25,12100,19000,11,56919,1,0,0,0,0,7,0,0,0,0,0,0,0,"Alliance Cleric - On Friendly Unit At 0 - 25% Health - Cast Flash Heal");

-- Grand Magus Telestra SAI
SET @ENTRY := 26928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,8000,9000,11,47721,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Fire Blast"),
(@ENTRY,0,1,0,0,0,100,4,3000,3000,8000,9000,11,56939,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Fire Blast"),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,9500,11500,11,47723,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Scorch"),
(@ENTRY,0,3,0,0,0,100,4,9000,9000,9500,11500,11,56938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Scorch"),
(@ENTRY,0,4,5,6,0,100,0,0,0,0,0,11,47711,18,0,0,0,0,7,0,0,0,0,0,0,0,"Grand Magus Telestra - On Death - Cast Telestra Clone Dies (Fire)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Magus Telestra - On Death - Forced Despawn");

-- Grand Magus Telestra SAI
SET @ENTRY := 26929;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,8000,10000,12000,11,47731,0,0,0,0,0,5,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Critter"),
(@ENTRY,0,1,0,0,0,100,6,15000,16000,15000,16000,11,47736,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Magus Telestra - In Combat - Cast Time Stop"),
(@ENTRY,0,2,3,6,0,100,0,0,0,0,0,11,47713,18,0,0,0,0,7,0,0,0,0,0,0,0,"Grand Magus Telestra - On Death - Cast Telestra Clone Dies (Arcane)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Magus Telestra - On Death - Forced Despawn");

-- Horde Berserker SAI
SET @ENTRY := 26799;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Berserker - On Aggro - Remove Aura Frozen Prison"),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,15000,19000,11,38682,7,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Berserker - In Combat - Cast War Stomp"),
(@ENTRY,0,2,0,0,0,100,6,9000,10000,9500,15000,11,47774,7,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Berserker - In Combat - Cast Frenzy"),
(@ENTRY,0,3,0,0,0,100,6,12000,15000,40000,58000,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Berserker - In Combat - Cast Bloodlust");

-- Alliance Berserker SAI
SET @ENTRY := 26800;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,28,47543,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Berserker - On Aggro - Remove Aura Frozen Prison"),
(@ENTRY,0,1,0,0,0,100,6,6000,8000,15000,19000,11,38682,7,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Berserker - In Combat - Cast War Stomp"),
(@ENTRY,0,2,0,0,0,100,6,9000,10000,9500,15000,11,47774,7,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Berserker - In Combat - Cast Frenzy"),
(@ENTRY,0,3,0,0,0,100,6,12000,15000,40000,58000,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alliance Berserker - In Combat - Cast Bloodlust");

-- Crazed Mana-Surge SAI
SET @ENTRY := 26737;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,9500,15000,11,48054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Mana-Surge - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,9500,15000,11,57047,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Mana-Surge - In Combat - Cast Mana Burn"),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,9500,15000,11,47696,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Mana-Surge - In Combat - Cast Arcane Nova"),
(@ENTRY,0,3,0,0,0,100,4,9000,11000,9500,15000,11,57046,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Mana-Surge - In Combat - Cast Arcane Nova"),
(@ENTRY,0,4,0,6,0,100,7,0,0,0,0,11,29882,7,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Mana-Surge - On Death - Cast Loose Mana");

-- Crazed Mana-Wraith SAI
SET @ENTRY := 26746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,1000,1500,11,33833,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Mana-Wraith - In Combat - Cast Arcane Missiles");

-- Crystalline Keeper SAI
SET @ENTRY := 26782;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,47699,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalline Keeper - On Aggro - Cast Crystal Bark"),
(@ENTRY,0,1,0,0,0,100,2,4000,6000,8500,12000,11,33688,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalline Keeper - In Combat - Cast Crystal Strike"),
(@ENTRY,0,2,0,0,0,100,4,4000,6000,8500,12000,11,57052,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalline Keeper - In Combat - Cast Crystal Strike");

-- Crystalline Protector SAI
SET @ENTRY := 26792;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,9500,15000,11,47698,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalline Protector - In Combat - Cast Crystal Chains"),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,9500,15000,11,57050,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalline Protector - In Combat - Cast Crystal Chains"),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,9500,15000,11,50302,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalline Protector - In Combat - Cast Shard Spray"),
(@ENTRY,0,3,0,0,0,100,4,9000,11000,9500,15000,11,57051,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalline Protector - In Combat - Cast Shard Spray"),
(@ENTRY,0,4,0,0,0,100,6,12000,15000,11100,19000,11,30633,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crystalline Protector - In Combat - Cast Thunderclap");

-- Mage Hunter Initiate SAI
SET @ENTRY := 26728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,9500,15000,11,50198,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Initiate - In Combat - Cast Magic Burn"),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,9500,15000,11,56860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Initiate - In Combat - Cast Magic Burn"),
(@ENTRY,0,2,0,0,0,100,6,9000,11000,9500,15000,11,17682,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Hunter Initiate - In Combat - Cast Drain Mana"),
(@ENTRY,0,3,0,0,0,100,6,12000,15000,9500,15000,11,25058,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Hunter Initiate - In Combat - Cast Renew");

-- Steward SAI
SET @ENTRY := 26729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,15000,19000,11,47779,0,0,0,0,0,1,0,0,0,0,0,0,0,"Steward - In Combat - Cast Arcane Torrent"),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,9500,15000,11,47780,0,0,0,0,0,2,0,0,0,0,0,0,0,"Steward - In Combat - Cast Spellbreaker");

-- Mage Slayer SAI
SET @ENTRY := 26730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,15000,19000,11,50131,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mage Slayer - In Combat - Cast Draw Magic"),
(@ENTRY,0,1,0,0,0,100,6,8000,10000,9500,15000,11,30849,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mage Slayer - In Combat - Cast Spell Lock");

-- Azure Enforcer SAI
SET @ENTRY := 26734;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,4000,12000,19000,11,39171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Enforcer - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,6,6300,8100,9500,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Enforcer - In Combat - Cast Cleave");

-- Azure Scale-Binder SAI
SET @ENTRY := 26735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,9500,15000,11,38881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Scale-Binder - In Combat - Cast Arcane Blast"),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,9500,15000,11,56969,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Scale-Binder - In Combat - Cast Arcane Blast"),
(@ENTRY,0,2,0,14,0,100,2,0,25,9500,15000,11,15586,1,0,0,0,0,7,0,0,0,0,0,0,0,"Azure Scale-Binder - On Friendly Unit At 0 - 25% Health - Cast Heal"),
(@ENTRY,0,3,0,14,0,100,4,0,25,9500,15000,11,61326,1,0,0,0,0,7,0,0,0,0,0,0,0,"Azure Scale-Binder - On Friendly Unit At 0 - 25% Health - Cast Heal");

-- Azure Warder SAI
SET @ENTRY := 26716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,6000,29000,35000,11,17741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Warder - In Combat - Cast Mana Shield"),
(@ENTRY,0,1,0,0,0,100,4,4000,6000,29000,35000,11,56778,0,0,0,0,0,1,0,0,0,0,0,0,0,"Azure Warder - In Combat - Cast Mana Shield"),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,9000,12000,11,6726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Warder - In Combat - Cast Silence"),
(@ENTRY,0,3,0,0,0,100,4,9000,11000,9000,12000,11,56777,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Warder - In Combat - Cast Silence");

-- Miner Johnson SAI
SET @ENTRY := 3586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,1900,7900,34400,56000,11,12097,32,0,0,0,0,2,0,0,0,0,0,0,0,"Miner Johnson - In Combat - Cast Pierce Armor");

-- Goblin Shipbuilder SAI
SET @ENTRY := 3947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Goblin Shipbuilder - At 15% HP - Flee For Assist");

-- Defias Strip Miner SAI
SET @ENTRY := 4416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,12000,45900,54200,11,6016,32,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Strip Miner - In Combat - Cast Pierce Armor");

-- Defias Evoker SAI
SET @ENTRY := 1729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Evoker - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,1,0,0,0,100,2,0,1200,3100,17100,11,11829,32,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Evoker - In Combat - Cast Flamestrike"),
(@ENTRY,0,2,0,0,0,100,2,1100,1100,42600,63500,11,4979,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Evoker - In Combat - Cast Quick Flame Ward"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Evoker - At 15% HP - Flee For Assist");

-- Goblin Craftsman SAI
SET @ENTRY := 1731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,700,9700,25000,52300,11,5159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Craftsman - In Combat - Cast Melt Ore"),
(@ENTRY,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Goblin Craftsman - At 15% HP - Flee For Assist");

-- Defias Squallshaper SAI
SET @ENTRY := 1732;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Squallshaper - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,1,0,0,0,30,2,1100,13600,23500,33500,11,122,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Squallshaper - In Combat - Cast Frost Nova"),
(@ENTRY,0,2,0,0,0,100,2,0,3200,8000,33000,11,2138,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Squallshaper - In Combat - Cast Fire Blast"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Squallshaper - At 15% HP - Flee For Assist");

-- Sneed's Shredder SAI
SET @ENTRY := 642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7900,12300,48100,54000,11,3603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sneed's Shredder - In Combat - Cast Distracting Pain"),
(@ENTRY,0,1,0,0,0,100,2,9000,14000,15000,21000,11,7399,1,0,0,0,0,5,0,0,0,0,0,0,0,"Sneed's Shredder - In Combat - Cast Terrify"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,5141,7,0,0,0,0,1,0,0,0,0,0,0,0,"Sneed's Shredder - On Death - Cast Eject Sneed");

-- Sneed SAI
SET @ENTRY := 643;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7900,17600,62000,86200,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sneed - In Combat - Cast Disarm");

-- Cookie SAI
SET @ENTRY := 645;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2400,3700,57000,66200,11,6306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cookie - In Combat - Cast Acid Splash"),
(@ENTRY,0,1,0,2,0,100,2,0,50,22200,33900,11,5174,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cookie - At 50% HP - Cast Cookie's Cooking"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Cookie - At 15% HP - Flee For Assist");

-- Captain Greenskin SAI
SET @ENTRY := 647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6200,13400,37400,97500,11,5208,32,0,0,0,0,5,0,0,0,0,0,0,0,"Captain Greenskin - In Combat - Cast Poisoned Harpoon"),
(@ENTRY,0,1,0,0,0,100,2,5000,18000,17700,42600,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Greenskin - In Combat - Cast Cleave");

-- Defias Pirate SAI
SET @ENTRY := 657;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,30,3,0,0,0,0,11,5172,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Pirate - Out Of Combat - Cast Bloodsail Companion");

-- Goblin Woodcarver SAI
SET @ENTRY := 641;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,3,1000,4000,0,0,11,6466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Woodcarver - In Combat - Cast Axe Toss"),
(@ENTRY,0,1,0,0,0,100,2,1700,9300,15900,34200,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Woodcarver - In Combat - Cast Cleave");

-- Defias Overseer SAI
SET @ENTRY := 634;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4800,17000,24000,43100,11,5115,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Overseer - In Combat - Cast Battle Command"),
(@ENTRY,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Overseer - At 15% HP - Flee For Assist");

-- Nether Charge SAI
SET @ENTRY := 20405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,37670,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - On Respawn - Cast Nether Charge Timer"),
(@ENTRY,0,1,0,0,0,100,6,14000,14000,1000,1000,11,35151,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - In Combat - Cast Nether Charge Pulse"),
(@ENTRY,0,2,0,0,0,100,7,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - In Combat - Start Auto Attack"),
(@ENTRY,0,3,0,0,0,100,7,0,0,14000,14000,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - In Combat - Allow Combat Movement"),
(@ENTRY,0,4,0,0,0,100,7,18000,18000,18000,18000,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nether Charge - In Combat - Cast Suicide");

-- Sunseeker Engineer SAI
SET @ENTRY := 20988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,10000,12000,11,36341,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Engineer - In Combat - Cast Super Shrink Ray"),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,14000,16000,11,36346,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Engineer - In Combat - Cast Growth Ray"),
(@ENTRY,0,2,0,0,0,100,2,3000,3000,8000,10000,11,36345,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Engineer - In Combat - Cast Death Ray"),
(@ENTRY,0,3,0,0,0,100,4,3000,3000,8000,10000,11,39196,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Engineer - In Combat - Cast Death Ray");

-- Bloodwarder Physician SAI
SET @ENTRY := 20990;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,5000,6000,11,36333,0,0,0,0,0,6,0,0,0,0,0,0,0,"Bloodwarder Physician - In Combat - Cast Anesthetic"),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,9000,10000,11,36340,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Physician - In Combat - Cast Holy Shock"),
(@ENTRY,0,2,0,0,0,100,4,4000,4000,9000,10000,11,38921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Physician - In Combat - Cast Holy Shock"),
(@ENTRY,0,3,0,2,0,100,2,0,50,10000,10000,11,36348,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Physician - At 50% HP - Cast Bandage"),
(@ENTRY,0,4,0,2,0,100,4,0,50,10000,10000,11,38919,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Physician - At 50% HP - Cast Bandage");

-- Defias Miner SAI
SET @ENTRY := 598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1900,7900,34400,56000,11,6016,32,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Miner - In Combat - Cast Pierce Armor"),
(@ENTRY,0,1,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Miner - At 15% HP - Flee For Assist");

-- Mechanar Wrecker SAI
SET @ENTRY := 19713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,18000,20000,11,35049,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mechanar Wrecker - In Combat - Cast Pound");

-- Mechanar Tinkerer SAI
SET @ENTRY := 19716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,8000,10000,11,35057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Tinkerer - In Combat - Cast Netherbomb"),
(@ENTRY,0,1,0,0,0,100,4,1000,1000,8000,10000,11,38925,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Tinkerer - In Combat - Cast Netherbomb"),
(@ENTRY,0,2,0,2,0,100,7,0,20,0,0,11,35062,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mechanar Tinkerer - At 20% HP - Cast Maniacal Charge"),
(@ENTRY,0,3,0,2,0,100,7,0,29,0,0,11,35058,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechanar Tinkerer - At 29% HP - Cast Nether Explosion");

-- Tempest-Forge Destroyer SAI
SET @ENTRY := 19735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,10000,17000,17000,11,36582,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Forge Destroyer - In Combat - Cast Charged Fist"),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,10000,10000,11,35783,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Destroyer - In Combat - Cast Knockdown");

-- Sunseeker Netherbinder SAI
SET @ENTRY := 20059;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,11000,13000,11,35261,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast Arcane Nova"),
(@ENTRY,0,1,0,0,0,100,4,6000,6000,11000,13000,11,38936,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast Arcane Nova"),
(@ENTRY,0,2,0,0,0,100,6,6000,6000,12000,17000,11,17201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Netherbinder - In Combat - Cast Dispel Magic");

-- Mechanar Crusher SAI
SET @ENTRY := 19231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,10000,12000,11,35055,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Crusher - In Combat - Cast The Claw");

-- Bloodwarder Centurion SAI
SET @ENTRY := 19510;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,8000,9000,11,35178,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodwarder Centurion - In Combat - Cast Shield Bash");

-- Mechanar Driller SAI
SET @ENTRY := 19712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,10000,20000,22000,11,35049,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mechanar Driller - In Combat - Cast Pound"),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,6000,8000,11,35047,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Driller - In Combat - Cast Drill Armor"),
(@ENTRY,0,2,0,0,0,100,6,6000,6000,15000,17000,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanar Driller - In Combat - Cast Crippling Poison");

-- Summoned Bloodwarder Mender SAI
SET @ENTRY := 20083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,34809,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Bloodwarder Mender - Out Of Combat - Cast Holy Fury"),
(@ENTRY,0,1,0,0,0,80,2,5000,5000,10000,14000,11,17194,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Bloodwarder Mender - In Combat - Cast Mind Blast"),
(@ENTRY,0,2,0,0,0,80,4,5000,5000,10000,14000,11,17287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Bloodwarder Mender - In Combat - Cast Mind Blast"),
(@ENTRY,0,3,0,2,0,100,6,0,30,5000,5000,11,35096,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Bloodwarder Mender - At 30% HP - Cast Greater Heal");

-- Tempest-Forge Patroller SAI
SET @ENTRY := 19166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,2000,9000,11000,11,35012,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast Charged Arcane Missile"),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,14000,16000,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempest-Forge Patroller - In Combat - Cast Knockdown");

-- Bloodwarder Slayer SAI
SET @ENTRY := 19167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,12000,14000,11,13736,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast Whirlwind"),
(@ENTRY,0,1,0,0,0,100,6,10000,10000,15000,17000,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast Mortal Strike"),
(@ENTRY,0,2,0,0,0,100,6,3000,3000,18000,20000,11,35189,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Slayer - In Combat - Cast Solar Strike");

-- Sunseeker Astromage SAI
SET @ENTRY := 19168;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,6000,8000,11,17195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast Scorch"),
(@ENTRY,0,1,0,0,0,100,4,6000,6000,6000,8000,11,36807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast Scorch"),
(@ENTRY,0,2,0,0,0,100,2,3000,3000,10000,12000,11,35267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast Solarburn"),
(@ENTRY,0,3,0,0,0,100,4,3000,3000,10000,12000,11,38930,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast Solarburn"),
(@ENTRY,0,4,0,0,0,100,2,1000,1000,120000,120000,11,35265,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast Fire Shield"),
(@ENTRY,0,5,0,0,0,100,4,1000,1000,120000,120000,11,38933,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Astromage - In Combat - Cast Fire Shield");

-- Frayer Protector SAI
SET @ENTRY := 19953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,6,5000,5000,10000,10000,11,34663,0,0,0,0,0,5,0,0,0,0,0,0,0,"Frayer Protector - In Combat - Cast Thorns");

-- White Seedling SAI
SET @ENTRY := 19958;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,6,12000,12000,10000,10000,11,34782,0,0,0,0,0,2,0,0,0,0,0,0,0,"White Seedling - In Combat - Cast Bind Feet");

-- Blue Seedling SAI
SET @ENTRY := 19962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,6,10000,10000,15000,15000,11,22357,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blue Seedling - In Combat - Cast Icebolt");

-- Red Seedling SAI
SET @ENTRY := 19964;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,6,9000,9000,13000,13000,11,25028,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Seedling - In Combat - Cast Fire Blast");

-- Green Seedling SAI
SET @ENTRY := 19969;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,6,5000,5000,20000,20000,11,25812,0,0,0,0,0,2,0,0,0,0,0,0,0,"Green Seedling - In Combat - Cast Toxic Volley");

-- Nethervine Inciter SAI
SET @ENTRY := 19511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,6,5000,5000,5000,10000,11,34615,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nethervine Inciter - In Combat - Cast Mind-numbing Poison"),
(@ENTRY,0,1,0,0,0,100,6,3000,3000,10000,15000,11,34616,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nethervine Inciter - In Combat - Cast Deadly Poison");

-- Nethervine Reaper SAI
SET @ENTRY := 19512;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,6,5000,5000,4000,8000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethervine Reaper - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,6,1000,1000,12000,16000,11,34626,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nethervine Reaper - In Combat - Cast Pale Death");

-- Bloodwarder Mender SAI
SET @ENTRY := 19633;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,180000,180000,11,34809,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Mender - Out Of Combat - Cast Holy Fury"),
(@ENTRY,0,1,0,0,0,80,2,5000,8000,10000,14000,11,17194,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Mender - In Combat - Cast Mind Blast"),
(@ENTRY,0,2,0,0,0,80,4,5000,8000,10000,14000,11,17287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Mender - In Combat - Cast Mind Blast"),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,11,35096,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Mender - At 30% HP - Cast Greater Heal");

-- Nethervine Trickster SAI
SET @ENTRY := 19843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,30831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethervine Trickster - Out Of Combat - Cast Stealth"),
(@ENTRY,0,1,0,0,0,50,6,7000,7000,7000,10000,11,34614,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethervine Trickster - In Combat - Cast Backstab");

-- Mutate Horror SAI
SET @ENTRY := 19865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,6000,10000,15000,11,34643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mutate Horror - In Combat - Cast Corrode Armor");

-- Sunseeker Gene-Splicer SAI
SET @ENTRY := 19507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,30000,32000,11,34642,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - In Combat - Cast Death & Decay"),
(@ENTRY,0,1,2,0,0,100,0,1000,1000,30000,32000,11,39347,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - In Combat - Cast Death & Decay"),
(@ENTRY,0,2,3,2,0,100,0,0,50,0,0,12,19598,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - At 50% HP - Summon Creature Mutate Fleshlasher"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,12,19598,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Gene-Splicer - At 50% HP - Summon Creature Mutate Fleshlasher");

-- Sunseeker Herbalist SAI
SET @ENTRY := 19508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Herbalist - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,34641,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Herbalist - On Aggro - Cast Spade Toss"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Herbalist - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,5,30,2200,3800,11,34641,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Herbalist - At 5 - 30 Range - Cast Spade Toss"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,11,39129,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Herbalist - On Aggro - Cast Spade Toss"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Herbalist - On Aggro - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,4,5,30,2200,3800,11,39129,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Herbalist - At 5 - 30 Range - Cast Spade Toss"),
(@ENTRY,0,7,0,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Herbalist - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Herbalist - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Herbalist - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,0,0,100,6,2000,5000,13000,16000,11,22127,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Herbalist - In Combat - Cast Entangling Roots");

-- Sunseeker Harvester SAI
SET @ENTRY := 19509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4000,12000,15000,11,37823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Harvester - In Combat - Cast Entangling Roots"),
(@ENTRY,0,1,0,0,0,60,6,7000,7000,6000,12000,11,34639,0,0,0,0,0,6,0,0,0,0,0,0,0,"Sunseeker Harvester - In Combat - Cast Polymorph"),
(@ENTRY,0,2,3,2,0,100,0,0,50,0,0,12,19598,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Harvester - At 50% HP - Summon Creature Mutate Fleshlasher"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,12,19598,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunseeker Harvester - At 50% HP - Summon Creature Mutate Fleshlasher");

-- Sunseeker Researcher SAI
SET @ENTRY := 18421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,60000,60000,11,34355,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Researcher - Out Of Combat - Cast Poison Shield"),
(@ENTRY,0,1,0,0,0,70,6,2000,2000,10000,14000,11,34352,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Researcher - In Combat - Cast Mind Shock"),
(@ENTRY,0,2,0,0,0,70,6,5000,5000,10000,14000,11,34353,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Researcher - In Combat - Cast Frost Shock"),
(@ENTRY,0,3,0,0,0,70,6,8000,8000,10000,14000,11,34354,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Researcher - In Combat - Cast Flame Shock");

-- Sunseeker Botanist SAI
SET @ENTRY := 18422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,60,21000,21000,11,27637,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Botanist - At 60% HP - Cast Regrowth"),
(@ENTRY,0,1,0,2,0,100,4,0,60,21000,21000,11,39125,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Botanist - At 60% HP - Cast Regrowth");

-- Sunseeker Chemist SAI
SET @ENTRY := 19486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,10000,10000,20000,25000,11,34358,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Chemist - In Combat - Cast Vial of Poison"),
(@ENTRY,0,1,0,0,0,80,4,12700,20500,20000,25000,11,39127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Chemist - In Combat - Cast Vial of Poison"),
(@ENTRY,0,2,0,0,0,80,2,5000,5000,10000,15000,11,34359,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Chemist - In Combat - Cast Fire Breath Potion"),
(@ENTRY,0,3,0,0,0,80,4,9600,15600,10000,15000,11,39128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Chemist - In Combat - Cast Fire Breath Potion");

-- Sunseeker Channeler SAI
SET @ENTRY := 19505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,30000,30000,11,34173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Channeler - Out Of Combat - Cast Sunseeker Blessing"),
(@ENTRY,0,1,0,0,0,70,6,4000,4000,10000,15000,11,34637,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunseeker Channeler - In Combat - Cast Soul Channel"),
(@ENTRY,0,2,0,0,0,40,6,14000,14000,10000,15000,11,34634,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Channeler - In Combat - Cast Sunseeker Aura");

-- Bloodwarder Steward SAI
SET @ENTRY := 18404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,6,10000,10000,15000,20000,11,34821,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Steward - In Combat - Cast Arcane Flurry");

-- Tempest-Forge Peacekeeper SAI
SET @ENTRY := 18405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,6,0,0,17800,21200,11,34785,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tempest-Forge Peacekeeper - In Combat - Cast Arcane Volley"),
(@ENTRY,0,1,0,0,0,100,6,5000,7100,7600,14500,11,34791,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tempest-Forge Peacekeeper - In Combat - Cast Arcane Explosion");

-- Bloodwarder Greenkeeper SAI
SET @ENTRY := 18419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,6,5000,5000,6000,10000,11,34800,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodwarder Greenkeeper - In Combat - Cast Impending Coma"),
(@ENTRY,0,1,0,0,0,80,2,1000,1000,5000,8000,11,34798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Greenkeeper - In Combat - Cast Greenkeeper's Fury"),
(@ENTRY,0,2,0,0,0,80,4,1000,1000,5000,8000,11,39121,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Greenkeeper - In Combat - Cast Greenkeeper's Fury"),
(@ENTRY,0,3,0,0,0,70,2,8000,8000,6000,10000,11,34797,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodwarder Greenkeeper - In Combat - Cast Nature Shock"),
(@ENTRY,0,4,0,0,0,70,4,8000,8000,6000,10000,11,39120,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodwarder Greenkeeper - In Combat - Cast Nature Shock");

-- Sunseeker Geomancer SAI
SET @ENTRY := 18420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,5000,5000,8000,11,35124,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Geomancer - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,1,0,1,0,100,6,1000,1000,12000,12000,11,35265,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunseeker Geomancer - Out Of Combat - Cast Fire Shield");

-- Bloodwarder Protector SAI
SET @ENTRY := 17993;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,7,0,1000,0,0,11,34784,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Protector - In Combat - Cast Intervene"),
(@ENTRY,0,1,0,0,0,80,6,6900,14700,18000,25000,11,35399,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Protector - In Combat - Cast Spell Reflection"),
(@ENTRY,0,2,0,0,0,80,6,2000,9000,6000,12000,11,29765,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodwarder Protector - In Combat - Cast Crystal Strike"),
(@ENTRY,0,3,0,2,0,100,7,0,10,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodwarder Protector - At 10% HP - Cast Suicide");

-- Bloodwarder Falconer SAI
SET @ENTRY := 17994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3200,3200,20000,25000,11,34852,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bloodwarder Falconer - In Combat - Cast Call of the Falcon");

-- Bloodfalcon SAI
SET @ENTRY := 18155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfalcon - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,6,7900,7900,12500,12500,11,34856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfalcon - In Combat - Cast Bloodburn"),
(@ENTRY,0,2,0,0,0,100,7,16700,20100,0,0,11,18144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfalcon - In Combat - Cast Swoop");

-- Sightless Eye SAI
SET @ENTRY := 21346;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,8000,8000,18000,18000,11,36646,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sightless Eye - In Combat - Cast Sightless Touch"),
(@ENTRY,0,1,0,0,0,80,4,8000,8000,18000,18000,11,38815,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sightless Eye - In Combat - Cast Sightless Touch");

-- Protean Spawn SAI
SET @ENTRY := 21395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4000,25000,30000,11,36796,1,0,0,0,0,2,0,0,0,0,0,0,0,"Protean Spawn - In Combat - Cast Acidic Bite");

-- Ethereum Life-Binder SAI
SET @ENTRY := 21702;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4000,15000,20000,11,37480,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast Bind"),
(@ENTRY,0,1,0,0,0,100,4,2000,4000,15000,20000,11,38900,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast Bind"),
(@ENTRY,0,2,0,0,0,100,2,7000,9000,27000,30000,11,15654,32,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,3,0,0,0,100,4,7000,9000,27000,30000,11,34941,32,0,0,0,0,5,0,0,0,0,0,0,0,"Ethereum Life-Binder - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,4,0,14,0,100,2,0,40,25000,30000,11,37479,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereum Life-Binder - On Friendly Unit At 0 - 40% Health - Cast Shadow Mend"),
(@ENTRY,0,5,0,14,0,100,4,0,40,25000,30000,11,38899,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereum Life-Binder - On Friendly Unit At 0 - 40% Health - Cast Shadow Mend");

-- Ethereum Slayer SAI
SET @ENTRY := 20896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,15087,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereum Slayer - At 30% HP - Cast Evasion"),
(@ENTRY,0,1,0,0,0,100,6,4000,6000,12000,15000,11,36839,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereum Slayer - In Combat - Cast Impairing Poison"),
(@ENTRY,0,2,0,0,0,100,2,2000,4000,10000,12000,11,36838,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereum Slayer - In Combat - Cast Slaying Strike"),
(@ENTRY,0,3,4,0,0,100,0,2000,4000,10000,12000,11,38894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereum Slayer - In Combat - Cast Slaying Strike");

-- Ethereum Wave-Caster SAI
SET @ENTRY := 20897;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,50,0,0,11,32693,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ethereum Wave-Caster - At 50% HP - Cast Arcane Haste"),
(@ENTRY,0,1,0,13,0,100,6,20000,25000,0,0,11,38897,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ethereum Wave-Caster - On Target Casting - Cast Sonic Boom"),
(@ENTRY,0,2,0,0,0,100,2,10000,12000,20000,25000,11,36840,32,0,0,0,0,6,0,0,0,0,0,0,0,"Ethereum Wave-Caster - In Combat - Cast Polymorph"),
(@ENTRY,0,3,0,0,0,100,4,10000,12000,20000,25000,11,38896,32,0,0,0,0,6,0,0,0,0,0,0,0,"Ethereum Wave-Caster - In Combat - Cast Polymorph");

-- Unchained Doombringer SAI
SET @ENTRY := 20900;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,6000,50000,60000,11,36836,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast Agonizing Armor"),
(@ENTRY,0,1,0,0,0,100,6,10000,13000,25000,30000,11,36833,1,0,0,0,0,6,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast Berserker Charge"),
(@ENTRY,0,2,0,0,0,100,2,7000,10000,25000,30000,11,36835,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast War Stomp"),
(@ENTRY,0,3,4,0,0,100,0,7000,10000,25000,30000,11,38911,1,0,0,0,0,1,0,0,0,0,0,0,0,"Unchained Doombringer - In Combat - Cast War Stomp");

-- Sargeron Hellcaller SAI
SET @ENTRY := 20902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,5000,30000,40000,11,36831,32,0,0,0,0,5,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast Curse of the Elements"),
(@ENTRY,0,1,0,0,0,100,2,1000,3000,15000,20000,11,36832,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast Incinerate"),
(@ENTRY,0,2,0,0,0,100,4,1000,3000,15000,20000,11,38918,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sargeron Hellcaller - In Combat - Cast Incinerate");

-- Death Watcher SAI
SET @ENTRY := 20867;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,8000,8000,22000,22000,11,36664,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Watcher - In Combat - Cast Tentacle Cleave"),
(@ENTRY,0,1,0,0,0,70,4,8000,8000,22000,22000,11,38816,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Watcher - In Combat - Cast Tentacle Cleave"),
(@ENTRY,0,2,0,2,0,100,2,0,50,32000,32000,11,36655,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Watcher - At 50% HP - Cast Drain Life"),
(@ENTRY,0,3,0,2,0,100,4,0,50,32000,32000,11,38817,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death Watcher - At 50% HP - Cast Drain Life"),
(@ENTRY,0,4,0,12,0,100,2,0,30,60000,60000,11,36657,1,0,0,0,0,7,0,0,0,0,0,0,0,"Death Watcher - On Target At 0 - 30% HP - Cast Death Count"),
(@ENTRY,0,5,0,12,0,100,4,0,30,60000,60000,11,38818,1,0,0,0,0,7,0,0,0,0,0,0,0,"Death Watcher - On Target At 0 - 30% HP - Cast Death Count");

-- Entropic Eye SAI
SET @ENTRY := 20868;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,6,3000,3000,25000,25000,11,36677,0,0,0,0,0,2,0,0,0,0,0,0,0,"Entropic Eye - In Combat - Cast Chaos Breath"),
(@ENTRY,0,1,0,0,0,75,2,8000,8000,22000,22000,11,36664,0,0,0,0,0,5,0,0,0,0,0,0,0,"Entropic Eye - In Combat - Cast Tentacle Cleave"),
(@ENTRY,0,2,0,0,0,75,4,8000,8000,22000,22000,11,38816,0,0,0,0,0,5,0,0,0,0,0,0,0,"Entropic Eye - In Combat - Cast Tentacle Cleave");

-- Eredar Deathbringer SAI
SET @ENTRY := 20880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,27987,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eredar Deathbringer - On Respawn - Cast Unholy Aura");

-- Unbound Devastator SAI
SET @ENTRY := 20881;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4000,20000,22000,11,36897,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast Transporter Malfunction"),
(@ENTRY,0,1,0,0,0,100,4,2000,4000,20000,22000,11,38850,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast Deafening Roar"),
(@ENTRY,0,2,0,0,0,100,2,10000,14000,20000,22000,11,36891,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast Devastate"),
(@ENTRY,0,3,0,0,0,100,4,10000,14000,20000,22000,11,38849,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Devastator - In Combat - Cast Devastate");

-- Protean Horror SAI
SET @ENTRY := 20865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,7,3000,7000,0,0,11,36612,1,0,0,0,0,2,0,0,0,0,0,0,0,"Protean Horror - In Combat - Cast Toothy Bite");

-- Soul Devourer SAI
SET @ENTRY := 20866;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,32958,1,0,0,0,0,1,0,0,0,0,0,0,0,"Soul Devourer - At 30% HP - Cast Crystal Channel"),
(@ENTRY,0,1,0,0,0,100,2,7000,10000,20000,23000,11,36654,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soul Devourer - In Combat - Cast Fel Breath"),
(@ENTRY,0,2,0,0,0,100,4,7000,10000,20000,23000,11,38813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soul Devourer - In Combat - Cast Fel Breath"),
(@ENTRY,0,3,0,0,0,100,7,15000,17000,0,0,11,36644,1,0,0,0,0,1,0,0,0,0,0,0,0,"Soul Devourer - In Combat - Cast Sightless Eye");

-- Deep Lurker SAI
SET @ENTRY := 8384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6300,15800,10800,24200,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Lurker - In Combat - Cast Trample");

-- Hakkari Bloodkeeper SAI
SET @ENTRY := 8438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,7741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hakkari Bloodkeeper - On Respawn - Cast Summoned Demon"),
(@ENTRY,0,1,0,9,0,100,2,0,40,5000,8000,11,12471,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hakkari Bloodkeeper - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,14000,20000,11,11671,33,0,0,0,0,5,0,0,0,0,0,0,0,"Hakkari Bloodkeeper - In Combat - Cast Corruption");

-- Shade of Hakkar SAI
SET @ENTRY := 8440;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,20000,25000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of Hakkar - At 0 - 5 Range - Cast Lash"),
(@ENTRY,0,1,0,0,0,100,2,6000,11000,21000,28000,11,12889,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shade of Hakkar - In Combat - Cast Curse of Tongues"),
(@ENTRY,0,2,0,0,0,100,2,13000,17000,18000,24000,11,12888,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shade of Hakkar - In Combat - Cast Cause Insanity");

-- Nightmare Suppressor SAI
SET @ENTRY := 8497;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,11,7741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Suppressor - On Respawn - Cast Summoned Demon"),
(@ENTRY,0,1,0,1,0,100,3,1000,3000,0,0,11,12623,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Suppressor - Out Of Combat - Cast Suppression");

-- Hukku's Succubus SAI
SET @ENTRY := 8657;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,12000,19500,11,11779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hukku's Succubus - At 0 - 5 Range - Cast Lash of Pain"),
(@ENTRY,0,1,0,0,0,100,2,8000,12000,15000,19000,11,6358,1,0,0,0,0,6,0,0,0,0,0,0,0,"Hukku's Succubus - In Combat - Cast Seduction");

-- Hazzas SAI
SET @ENTRY := 5722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2800,6100,8300,17900,11,12884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hazzas - In Combat - Cast Acid Breath"),
(@ENTRY,0,1,0,0,0,100,2,8700,13900,19300,34700,11,12882,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hazzas - In Combat - Cast Wing Flap");

-- Atal'ai Deathwalker's Spirit SAI
SET @ENTRY := 8317;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,42,100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Deathwalker's Spirit - On Aggro - Set Invincibility Health Pct To 100"),
(@ENTRY,0,1,0,0,0,100,3,15000,15000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Deathwalker's Spirit - In Combat - Die");

-- Hakkari Sapper SAI
SET @ENTRY := 8336;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15600,17800,10700,18200,11,11981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hakkari Sapper - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,2,8700,13900,27300,33300,11,12882,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hakkari Sapper - In Combat - Cast Wing Flap");

-- Zul'Lor SAI
SET @ENTRY := 5716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9800,14300,7900,16200,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zul'Lor - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,6100,14500,11,12530,1,0,0,0,0,1,0,0,0,0,0,0,0,"Zul'Lor - In Combat - Cast Frailty");

-- Mijan SAI
SET @ENTRY := 5717;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,14100,14100,63800,66700,11,8148,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mijan - In Combat - Cast Thorns Aura"),
(@ENTRY,0,1,0,14,0,100,2,0,40,19500,28100,11,8362,1,0,0,0,0,7,0,0,0,0,0,0,0,"Mijan - On Friendly Unit At 0 - 40% Health - Cast Renew"),
(@ENTRY,0,2,0,0,0,100,2,9500,18000,33400,45600,11,11899,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mijan - In Combat - Cast Healing Ward"),
(@ENTRY,0,3,0,2,0,100,2,0,30,9000,12000,11,12492,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mijan - At 30% HP - Cast Healing Wave");

-- Morphaz SAI
SET @ENTRY := 5719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2800,6100,8300,17900,11,12884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morphaz - In Combat - Cast Acid Breath"),
(@ENTRY,0,1,0,0,0,100,2,8700,13900,19300,34700,11,12882,1,0,0,0,0,1,0,0,0,0,0,0,0,"Morphaz - In Combat - Cast Wing Flap");

-- Weaver SAI
SET @ENTRY := 5720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2800,6200,6100,21600,11,12884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weaver - In Combat - Cast Acid Breath"),
(@ENTRY,0,1,0,0,0,100,2,8700,13900,19300,34700,11,12882,1,0,0,0,0,1,0,0,0,0,0,0,0,"Weaver - In Combat - Cast Wing Flap");

-- Zolo SAI
SET @ENTRY := 5712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6900,10100,9500,12400,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zolo - In Combat - Cast Chain Lightning"),
(@ENTRY,0,1,0,0,0,100,2,7000,12000,25000,35000,11,12506,1,0,0,0,0,1,0,0,0,0,0,0,0,"Zolo - In Combat - Cast Atal'ai Skeleton Totem");

-- Loro SAI
SET @ENTRY := 5714;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,7900,16600,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Loro - At 0 - 5 Range - Cast Shield Slam"),
(@ENTRY,0,1,0,0,0,100,2,9700,16700,10700,16900,11,3639,1,0,0,0,0,1,0,0,0,0,0,0,0,"Loro - In Combat - Cast Improved Blocking");

-- Nightmare Wanderer SAI
SET @ENTRY := 5283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,13900,16700,12100,19900,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Wanderer - In Combat - Cast Strike"),
(@ENTRY,0,1,0,9,0,100,2,0,5,23800,38200,11,12097,33,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Wanderer - At 0 - 5 Range - Cast Pierce Armor");

-- Hakkari Frostwing SAI
SET @ENTRY := 5291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5900,9700,15900,32200,11,8398,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hakkari Frostwing - In Combat - Cast Frostbolt Volley"),
(@ENTRY,0,1,0,9,0,100,2,0,5,8000,17800,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hakkari Frostwing - At 0 - 5 Range - Cast Swoop"),
(@ENTRY,0,2,0,0,0,100,2,6900,16800,16800,29600,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hakkari Frostwing - In Combat - Cast Frost Nova");

-- Spawn of Hakkar SAI
SET @ENTRY := 5708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3500,1200,6200,11,12280,32,0,0,0,0,2,0,0,0,0,0,0,0,"Spawn of Hakkar - In Combat - Cast Acid of Hakkar");

-- Nightmare Scalebane SAI
SET @ENTRY := 5277;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4500,10900,11900,17100,11,3639,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Scalebane - In Combat - Cast Improved Blocking");

-- Nightmare Wyrmkin SAI
SET @ENTRY := 5280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Wyrmkin - On Aggro - Cast Acid Spit"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,3400,4800,11,9591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightmare Wyrmkin - At 0 - 40 Range - Cast Acid Spit"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,2,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nightmare Wyrmkin - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,2,9000,14000,23000,27000,11,12098,1,0,0,0,0,6,0,0,0,0,0,0,0,"Nightmare Wyrmkin - In Combat - Cast Sleep");

-- Atal'ai Corpse Eater SAI
SET @ENTRY := 5270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,12000,12000,11,12134,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Corpse Eater - At 30% HP - Cast Atal'ai Corpse Eat");

-- Atal'ai Deathwalker SAI
SET @ENTRY := 5271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7300,14500,15900,32200,11,11639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Deathwalker - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,0,0,100,2,9000,13000,13000,18000,11,12096,1,0,0,0,0,6,0,0,0,0,0,0,0,"Atal'ai Deathwalker - In Combat - Cast Fear"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,12095,7,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'ai Deathwalker - On Death - Cast Summon Atal'ai Deathwalker's Spirit");

-- Enthralled Atal'ai SAI
SET @ENTRY := 5261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,12000,18000,25000,11,12021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enthralled Atal'ai - In Combat - Cast Fixate");

-- Black Guard Swordsmith SAI
SET @ENTRY := 11121;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,15000,15000,11,16867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Black Guard Swordsmith - In Combat - Cast Banshee Curse");

-- Murk Worm SAI
SET @ENTRY := 5226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2500,5400,6600,8300,11,7992,32,0,0,0,0,5,0,0,0,0,0,0,0,"Murk Worm - In Combat - Cast Slowing Poison");

-- Saturated Ooze SAI
SET @ENTRY := 5228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9700,14600,10900,15800,11,12250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saturated Ooze - In Combat - Cast Summon Oozeling"),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,12018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Saturated Ooze - At 50% HP - Cast Summon Oozeling");

-- Cursed Atal'ai SAI
SET @ENTRY := 5243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,12020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Atal'ai - At 30% HP - Cast Call of the Grave");

-- Atal'ai Warrior SAI
SET @ENTRY := 5256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7100,15800,12100,17800,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Warrior - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,7300,16000,19300,20100,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'ai Warrior - In Combat - Cast Rend");

-- Crimson Hammersmith SAI
SET @ENTRY := 11120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,20,2,12000,12000,20000,20000,11,17445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Hammersmith - In Combat - Cast Bone Smelt");

-- Archivist Galford SAI
SET @ENTRY := 10811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,15000,15000,10000,10000,11,17366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archivist Galford - In Combat - Cast Fire Nova"),
(@ENTRY,0,1,0,0,0,25,2,3000,3000,18000,18000,11,17274,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archivist Galford - In Combat - Cast Pyroblast"),
(@ENTRY,0,2,0,0,0,70,2,10000,10000,15000,15000,11,17293,0,0,0,0,0,5,0,0,0,0,0,0,0,"Archivist Galford - In Combat - Cast Burning Winds");

-- Undead Scarab SAI
SET @ENTRY := 10876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,20000,20000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Undead Scarab - In Combat - Cast Cripple");

-- Malor the Zealous SAI
SET @ENTRY := 11032;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,10000,10000,11,12734,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malor the Zealous - In Combat - Cast Ground Smash"),
(@ENTRY,0,1,0,14,0,100,2,0,40,3600000,3600000,11,10310,0,0,0,0,0,7,0,0,0,0,0,0,0,"Malor the Zealous - On Friendly Unit At 0 - 40% Health - Cast Lay on Hands"),
(@ENTRY,0,2,0,0,0,100,2,2000,2000,30000,35000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Malor the Zealous - In Combat - Cast Head Crack"),
(@ENTRY,0,3,0,2,0,100,3,21,40,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malor the Zealous - At 40% HP - Cast Holy Light"),
(@ENTRY,0,4,0,2,0,100,3,0,20,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malor the Zealous - At 20% HP - Cast Holy Light");

-- Crimson Monk SAI
SET @ENTRY := 11043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,674,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Monk - On Aggro - Cast Dual Wield"),
(@ENTRY,0,1,0,0,0,100,2,2000,2000,7000,7000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Monk - In Combat - Cast Thrash"),
(@ENTRY,0,2,0,0,0,100,2,4000,4000,10000,10000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Monk - In Combat - Cast Kick");

-- Bile Slime SAI
SET @ENTRY := 10697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,10000,10000,11,16866,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bile Slime - In Combat - Cast Venom Spit"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,15000,15000,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bile Slime - In Combat - Cast Slowing Poison");

-- Stonespine SAI
SET @ENTRY := 10809;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,21000,21000,11,14331,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonespine - In Combat - Cast Vicious Rend");

-- Crimson Inquisitor SAI
SET @ENTRY := 10426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10000,10000,10000,10000,11,15785,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Inquisitor - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,2,6000,6000,25000,25000,11,17146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Inquisitor - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,2,0,0,0,100,2,100,100,15000,15000,11,17165,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Inquisitor - In Combat - Cast Mind Flay"),
(@ENTRY,0,3,0,4,0,100,3,0,0,0,0,11,17151,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Inquisitor - On Aggro - Cast Shadow Barrier");

-- Shrieking Banshee SAI
SET @ENTRY := 10463;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,6000,6000,11,16868,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shrieking Banshee - In Combat - Cast Banshee Wail"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,30000,30000,11,3589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shrieking Banshee - In Combat - Cast Deafening Screech");

-- Wailing Banshee SAI
SET @ENTRY := 10464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,20000,20000,11,17105,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Banshee - In Combat - Cast Banshee Curse"),
(@ENTRY,0,1,0,0,0,100,2,100,100,30000,30000,11,19645,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Banshee - In Combat - Cast Anti-Magic Shield");

-- The Unforgiven SAI
SET @ENTRY := 10516;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,13000,17000,11,14907,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Unforgiven - In Combat - Cast Frost Nova"),
(@ENTRY,0,1,0,10,0,100,3,0,30,0,0,11,8822,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Unforgiven - On LOS Out Of Combat - Cast Stealth");

-- Crimson Priest SAI
SET @ENTRY := 10423;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,0,0,11,15586,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Priest - At 50% HP - Cast Heal"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,5000,5000,11,15238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Priest - In Combat - Cast Holy Smite"),
(@ENTRY,0,2,0,0,0,85,2,15000,15000,45000,45000,11,17139,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Priest - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,3,0,0,0,100,2,5000,5000,15000,15000,11,17142,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Priest - In Combat - Cast Holy Fire");

-- Crimson Gallant SAI
SET @ENTRY := 10424;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,8000,8000,11,17143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Gallant - In Combat - Cast Holy Strike"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,10000,10000,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Gallant - In Combat - Cast Crusader Strike"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,8990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Gallant - On Aggro - Cast Retribution Aura");

-- Crimson Battle Mage SAI
SET @ENTRY := 10425;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,2000,2000,20000,20000,11,11667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Battle Mage - In Combat - Cast Immolate"),
(@ENTRY,0,1,0,0,0,100,2,12000,12000,9000,9000,11,15253,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Battle Mage - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,13000,13000,11,17145,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Battle Mage - In Combat - Cast Blast Wave");

-- Crimson Initiate SAI
SET @ENTRY := 10420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,50,0,0,11,8362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Initiate - At 50% HP - Cast Renew"),
(@ENTRY,0,1,0,2,0,100,3,0,25,0,0,11,17138,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Initiate - At 25% HP - Cast Flash Heal"),
(@ENTRY,0,2,0,0,0,100,2,1000,1000,10000,10000,11,17194,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Initiate - In Combat - Cast Mind Blast");

-- Crimson Defender SAI
SET @ENTRY := 10421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Defender - On Aggro - Cast Devotion Aura"),
(@ENTRY,0,1,0,2,0,100,3,0,66,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Defender - At 66% HP - Cast Holy Light"),
(@ENTRY,0,2,0,2,0,100,3,0,45,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Defender - At 45% HP - Cast Holy Light"),
(@ENTRY,0,3,0,2,0,100,3,0,25,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Defender - At 25% HP - Cast Holy Light"),
(@ENTRY,0,4,0,2,0,100,3,0,10,0,0,11,15493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Defender - At 10% HP - Cast Holy Light"),
(@ENTRY,0,5,0,0,0,100,2,10000,10000,60000,60000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Defender - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,6,0,2,0,100,3,0,20,0,0,11,13874,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Defender - At 20% HP - Cast Divine Shield");

-- Venom Belcher SAI
SET @ENTRY := 10417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,15000,15000,11,16866,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venom Belcher - In Combat - Cast Venom Spit"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,30000,30000,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venom Belcher - In Combat - Cast Slowing Poison"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,34,5,1,0,0,0,0,1,0,0,0,0,0,0,0,"Venom Belcher - On Death - Set Instance Data 5 to 1");

-- Crimson Guardsman SAI
SET @ENTRY := 10418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Guardsman - On Aggro - Cast Shield Charge"),
(@ENTRY,0,1,0,0,0,100,2,6000,6000,15000,15000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Guardsman - In Combat - Cast Disarm"),
(@ENTRY,0,2,0,0,0,100,2,4000,4000,8000,8000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Guardsman - In Combat - Cast Shield Bash");

-- Crimson Conjuror SAI
SET @ENTRY := 10419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Conjuror - On Aggro - Cast Frostbolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Conjuror - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,85,2,7000,7000,10000,10000,11,17195,1,0,0,0,0,5,0,0,0,0,0,0,0,"Crimson Conjuror - In Combat - Cast Scorch"),
(@ENTRY,0,11,0,0,0,100,2,10000,10000,15000,15000,11,12674,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - In Combat - Cast Frost Nova"),
(@ENTRY,0,12,0,0,0,100,2,5000,5000,35000,45000,11,17162,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Conjuror - In Combat - Cast Summon Water Elemental");

-- Crypt Crawler SAI
SET @ENTRY := 10412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,15000,15000,11,15471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Crawler - In Combat - Cast Enveloping Web");

-- Crypt Beast SAI
SET @ENTRY := 10413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,15000,15000,11,4962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Beast - In Combat - Cast Encasing Webs");

-- Patchwork Horror SAI
SET @ENTRY := 10414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,5000,5000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Patchwork Horror - In Combat - Cast Thrash"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,14000,14000,11,16346,0,0,0,0,0,1,0,0,0,0,0,0,0,"Patchwork Horror - In Combat - Cast Disease Cloud"),
(@ENTRY,0,2,0,0,0,100,2,7000,7000,15000,15000,11,10101,0,0,0,0,0,5,0,0,0,0,0,0,0,"Patchwork Horror - In Combat - Cast Knock Away");

-- Bile Spewer SAI
SET @ENTRY := 10416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,3000,3000,5000,5000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bile Spewer - In Combat - Cast Thrash"),
(@ENTRY,0,1,0,0,0,100,3,0,0,5000,5000,11,16865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bile Spewer - In Combat - Cast Spawn Bile Slimes"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,34,5,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bile Spewer - On Death - Set Instance Data 5 to 1");

-- Ghoul Ravener SAI
SET @ENTRY := 10406;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,5000,5000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghoul Ravener - In Combat - Cast Head Crack"),
(@ENTRY,0,1,0,0,0,100,2,7000,7000,8000,8000,11,16553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghoul Ravener - In Combat - Cast Ravenous Claw");

-- Fleshflayer Ghoul SAI
SET @ENTRY := 10407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,2,5000,5000,6000,6000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fleshflayer Ghoul - In Combat - Cast Thrash"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,20000,20000,11,13738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fleshflayer Ghoul - In Combat - Cast Rend");

-- Rockwing Gargoyle SAI
SET @ENTRY := 10408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,4,6596,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockwing Gargoyle - On Aggro - Play Sound 6596"),
(@ENTRY,0,1,0,0,0,70,2,4000,4000,10000,10000,11,13444,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockwing Gargoyle - In Combat - Cast Sunder Armor");

-- Rockwing Screecher SAI
SET @ENTRY := 10409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,4,6596,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockwing Screecher - On Aggro - Play Sound 6596"),
(@ENTRY,0,1,0,0,0,85,2,6000,6000,40000,40000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockwing Screecher - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,2,0,0,0,100,2,9000,9000,35000,35000,11,8715,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockwing Screecher - In Combat - Cast Terrifying Howl"),
(@ENTRY,0,3,0,0,0,100,2,1000,1000,6000,6000,11,16997,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockwing Screecher - In Combat - Cast Gargoyle Strike");

-- Black Guard Sentry SAI
SET @ENTRY := 10394;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,10000,10000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Guard Sentry - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,6000,6000,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Guard Sentry - In Combat - Cast Shadow Shock");

-- Thuzadin Shadowcaster SAI
SET @ENTRY := 10398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,2,4000,6000,20000,25000,11,11443,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - In Combat - Cast Cripple"),
(@ENTRY,0,11,0,0,0,100,2,7000,12000,15000,20000,11,16429,33,0,0,0,0,5,0,0,0,0,0,0,0,"Thuzadin Shadowcaster - In Combat - Cast Piercing Shadow");

-- Thuzadin Necromancer SAI
SET @ENTRY := 10400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,16431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Necromancer - On Aggro - Cast Bone Armor"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,12420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thuzadin Necromancer - Out Of Combat - Cast Summon Skeletal Servant"),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,20000,20000,11,16430,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thuzadin Necromancer - In Combat - Cast Soul Tap");

-- Wrath Phantom SAI
SET @ENTRY := 10389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,10000,10000,11,7074,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrath Phantom - In Combat - Cast Screams of the Past");

-- Skeletal Guardian SAI
SET @ENTRY := 10390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,13787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - Out Of Combat - Cast Demon Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,85,2,9000,12000,9000,12000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - At 9000 - 12000 Range - Cast Frostbolt"),
(@ENTRY,0,12,0,0,0,85,2,6000,7000,9000,12000,11,37361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Guardian - In Combat - Cast Arcane Bolt"),
(@ENTRY,0,13,0,0,0,85,2,14000,18000,14000,18000,11,11975,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Guardian - In Combat - Cast Arcane Explosion");

-- Skeletal Berserker SAI
SET @ENTRY := 10391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,29651,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Berserker - On Aggro - Cast Dual Wield"),
(@ENTRY,0,1,0,0,0,100,2,1000,1000,6000,6000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Berserker - In Combat - Cast Strike"),
(@ENTRY,0,2,0,0,0,80,2,4000,4000,10000,10000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Berserker - In Combat - Cast Cleave"),
(@ENTRY,0,3,0,0,0,100,3,9000,9000,0,0,11,13730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Berserker - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,4,0,0,0,100,2,2000,2000,14000,19000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Berserker - In Combat - Cast Hamstring");

-- Ravaged Cadaver SAI
SET @ENTRY := 10381;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,30000,30000,11,16143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravaged Cadaver - In Combat - Cast Cadaver Worms"),
(@ENTRY,0,1,0,0,0,100,2,2000,2000,7000,7000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravaged Cadaver - In Combat - Cast Strike"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,16324,3,0,0,0,0,1,0,0,0,0,0,0,0,"Ravaged Cadaver - On Death - Cast Summon Broken Cadaver");

-- Mangled Cadaver SAI
SET @ENTRY := 10382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,30000,30000,11,16143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mangled Cadaver - In Combat - Cast Cadaver Worms");

-- Broken Cadaver SAI
SET @ENTRY := 10383;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,4000,40000,0,0,11,16141,0,0,0,0,0,2,0,0,0,0,0,0,0,"Broken Cadaver - In Combat - Cast Exploding Cadaver");

-- Vengeful Phantom SAI
SET @ENTRY := 10387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,3000,18000,18000,11,15089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vengeful Phantom - In Combat - Cast Frost Shock");

-- Spiteful Phantom SAI
SET @ENTRY := 10388;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,15000,15000,11,12531,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spiteful Phantom - In Combat - Cast Chilling Touch");

-- Commander Springvale SAI
SET @ENTRY := 4278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,10300,17800,61100,63500,11,5588,0,0,0,0,0,2,0,0,0,0,0,0,0,"Commander Springvale - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,1,0,14,0,100,2,0,40,17500,22300,11,1026,1,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Springvale - On Friendly Unit At 0 - 40% Health - Cast Holy Light");

-- Odo the Blindwatcher SAI
SET @ENTRY := 4279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,39,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Odo the Blindwatcher - On Aggro - Call For Help"),
(@ENTRY,0,1,0,2,0,100,3,0,60,0,0,11,7481,0,0,0,0,0,1,0,0,0,0,0,0,0,"Odo the Blindwatcher - At 60% HP - Cast Howling Rage"),
(@ENTRY,0,2,0,2,0,100,3,0,40,0,0,11,7483,0,0,0,0,0,1,0,0,0,0,0,0,0,"Odo the Blindwatcher - At 40% HP - Cast Howling Rage"),
(@ENTRY,0,3,0,2,0,100,3,0,20,0,0,11,7484,0,0,0,0,0,1,0,0,0,0,0,0,0,"Odo the Blindwatcher - At 20% HP - Cast Howling Rage");

-- Wolfguard Worg SAI
SET @ENTRY := 5058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wolfguard Worg - At 15% HP - Flee For Assist");

-- Tormented Officer SAI
SET @ENTRY := 3873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,10500,11900,3500,6500,11,7054,32,0,0,0,0,5,0,0,0,0,0,0,0,"Tormented Officer - In Combat - Cast Forsaken Skills");

-- Haunted Servitor SAI
SET @ENTRY := 3875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,9200,13200,4000,6000,11,7057,32,0,0,0,0,5,0,0,0,0,0,0,0,"Haunted Servitor - In Combat - Cast Haunting Spirits");

-- Wailing Guardsman SAI
SET @ENTRY := 3877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,7200,1200,12200,11,7074,32,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Guardsman - In Combat - Cast Screams of the Past");

-- Razorclaw the Butcher SAI
SET @ENTRY := 3886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,2800,9700,11,7485,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorclaw the Butcher - At 0 - 5 Range - Cast Butcher Drain");

-- Baron Silverlaine SAI
SET @ENTRY := 3887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,22300,35100,11,7068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Silverlaine - In Combat - Cast Veil of Shadow");

-- Lupine Horror SAI
SET @ENTRY := 3863;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,12800,21500,192000,206200,11,7132,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lupine Horror - In Combat - Cast Summon Lupine Delusions");

-- Fel Steed SAI
SET @ENTRY := 3864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3400,16600,16300,35200,11,7139,32,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Steed - In Combat - Cast Fel Stomp");

-- Vile Bat SAI
SET @ENTRY := 3866;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,39,30,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Bat - On Aggro - Call For Help"),
(@ENTRY,0,1,0,0,0,100,2,1800,5800,11900,20200,11,7145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Bat - In Combat - Cast Diving Sweep"),
(@ENTRY,0,2,0,0,0,100,2,7800,9700,18100,34100,11,6713,1,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Bat - In Combat - Cast Disarm");

-- Blood Seeker SAI
SET @ENTRY := 3868;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5700,5900,2000,12100,11,7140,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blood Seeker - In Combat - Cast Expose Weakness");

-- Deathsworn Captain SAI
SET @ENTRY := 3872;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathsworn Captain - Out Of Combat - Cast Battle Stance"),
(@ENTRY,0,1,0,0,0,100,2,4100,5800,8200,18200,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathsworn Captain - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,6700,7300,14600,33300,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deathsworn Captain - In Combat - Cast Hamstring");

-- Shadowfang Wolfguard SAI
SET @ENTRY := 3854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,7107,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowfang Wolfguard - Out Of Combat - Cast Summon Wolfguard Worg"),
(@ENTRY,0,1,0,14,0,100,3,0,10,21900,34000,11,7106,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowfang Wolfguard - On Friendly Unit At 0 - 10% Health - Cast Dark Restore");

-- Shadowfang Darksoul SAI
SET @ENTRY := 3855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1300,9700,3600,7200,11,970,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowfang Darksoul - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,0,0,100,2,2600,12700,3800,22500,11,8140,32,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowfang Darksoul - In Combat - Cast Befuddlement");

-- Shadowfang Glutton SAI
SET @ENTRY := 3857;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,3200,4800,12100,11,7122,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowfang Glutton - In Combat - Cast Blood Tap");

-- Shadowfang Ragetooth SAI
SET @ENTRY := 3859;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,35,0,0,11,7072,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowfang Ragetooth - At 35% HP - Cast Wild Rage");

-- Bleak Worg SAI
SET @ENTRY := 3861;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1200,4900,1200,9400,11,7127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bleak Worg - In Combat - Cast Wavering Will");

-- Rattlegore SAI
SET @ENTRY := 11622;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7300,22100,10800,27600,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rattlegore - In Combat - Cast Knock Away"),
(@ENTRY,0,1,0,0,0,100,2,6200,21800,7500,21300,11,18368,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rattlegore - In Combat - Cast Strike"),
(@ENTRY,0,2,0,0,0,100,2,15800,21400,13100,26400,11,16727,1,0,0,0,0,2,0,0,0,0,0,0,0,"Rattlegore - In Combat - Cast War Stomp");

-- Blood Steward of Kirtonos SAI
SET @ENTRY := 14861;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,19400,19700,4200,22900,11,22371,32,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Steward of Kirtonos - In Combat - Cast Curse of Impotence"),
(@ENTRY,0,1,0,0,0,100,2,6100,18200,3600,22600,11,12493,32,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Steward of Kirtonos - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,2,0,0,0,100,2,16000,19000,27300,46900,11,3609,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Steward of Kirtonos - In Combat - Cast Paralyzing Poison");

-- Son of Arugal SAI
SET @ENTRY := 2529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,11800,11800,9500,21400,11,7124,32,0,0,0,0,5,0,0,0,0,0,0,0,"Son of Arugal - In Combat - Cast Arugal's Gift");

-- Shadowfang Whitescalp SAI
SET @ENTRY := 3851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowfang Whitescalp - Out Of Combat - Cast Frost Armor");

-- Shadowfang Moonwalker SAI
SET @ENTRY := 3853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,8200,16700,25600,11,7121,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowfang Moonwalker - In Combat - Cast Anti-Magic Shield");

-- Plagued Hatchling SAI
SET @ENTRY := 10678;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,700,8200,4800,9700,11,17745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plagued Hatchling - In Combat - Cast Diseased Spit");

-- Scholomance Handler SAI
SET @ENTRY := 11257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4100,14500,6600,19400,11,10833,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Handler - In Combat - Cast Arcane Blast"),
(@ENTRY,0,1,0,0,0,100,2,4700,10800,10900,21200,11,17145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Handler - In Combat - Cast Blast Wave"),
(@ENTRY,0,2,0,0,0,100,2,3900,19400,10300,33800,11,15244,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Handler - In Combat - Cast Cone of Cold");

-- Necrofiend SAI
SET @ENTRY := 11551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6500,13100,20700,33900,11,15474,0,0,0,0,0,2,0,0,0,0,0,0,0,"Necrofiend - In Combat - Cast Web Explosion"),
(@ENTRY,0,1,0,0,0,100,2,6400,22800,16000,25600,11,3583,32,0,0,0,0,2,0,0,0,0,0,0,0,"Necrofiend - In Combat - Cast Deadly Poison");

-- Diseased Ghoul SAI
SET @ENTRY := 10495;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,12627,1,0,0,0,0,1,0,0,0,0,0,0,0,"Diseased Ghoul - Out Of Combat - Cast Disease Cloud"),
(@ENTRY,0,1,0,0,0,100,2,7100,12300,12300,40900,11,3436,32,0,0,0,0,5,0,0,0,0,0,0,0,"Diseased Ghoul - In Combat - Cast Wandering Plague"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,17742,7,0,0,0,0,1,0,0,0,0,0,0,0,"Diseased Ghoul - On Death - Cast Cloud of Disease");

-- Spectral Tutor SAI
SET @ENTRY := 10498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4200,19100,8600,26400,11,17630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Tutor - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,2,0,3300,12000,26300,11,12528,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Tutor - In Combat - Cast Silence"),
(@ENTRY,0,2,0,0,0,100,2,11800,12700,17700,25300,11,17651,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Tutor - In Combat - Cast Image Projection");

-- Spectral Researcher SAI
SET @ENTRY := 10499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,25700,7300,19400,11,17630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Researcher - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,2,1000,9400,9400,22800,11,17631,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Researcher - In Combat - Cast Wail of Souls");

-- Spectral Teacher SAI
SET @ENTRY := 10500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,13900,18100,10500,22400,11,17630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Teacher - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,2,9900,19700,30900,39600,11,17633,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Teacher - In Combat - Cast Arcane Focus");

-- Risen Guard SAI
SET @ENTRY := 10489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1700,9400,12800,27800,11,15655,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Guard - In Combat - Cast Shield Slam"),
(@ENTRY,0,1,0,0,0,100,2,700,9300,6100,14600,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Guard - In Combat - Cast Sunder Armor");

-- Risen Bonewarder SAI
SET @ENTRY := 10491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,3,4300,9400,0,0,11,16431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Bonewarder - In Combat - Cast Bone Armor"),
(@ENTRY,0,1,0,0,0,100,2,9900,21700,15700,34600,11,17715,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Bonewarder - In Combat - Cast Consuming Shadows"),
(@ENTRY,0,2,0,0,0,100,2,12600,25200,16700,32300,11,17620,1,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Bonewarder - In Combat - Cast Drain Life");

-- Reanimated Corpse SAI
SET @ENTRY := 10481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3600,17300,10300,18200,11,18270,32,0,0,0,0,2,0,0,0,0,0,0,0,"Reanimated Corpse - In Combat - Cast Dark Plague");

-- Risen Aberration SAI
SET @ENTRY := 10485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1500,8900,17300,33700,11,12021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Aberration - In Combat - Cast Fixate");

-- Risen Warrior SAI
SET @ENTRY := 10486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,11800,19700,15500,32600,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Warrior - In Combat - Cast Knockdown"),
(@ENTRY,0,1,0,0,0,100,2,7400,28700,13500,25200,11,16509,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Warrior - In Combat - Cast Rend"),
(@ENTRY,0,2,0,0,0,100,2,12300,17500,10800,33400,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Warrior - In Combat - Cast Strike"),
(@ENTRY,0,3,0,0,0,100,2,3200,22900,10800,32200,11,15588,1,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Warrior - In Combat - Cast Thunderclap");

-- Risen Protector SAI
SET @ENTRY := 10487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4700,14300,13100,30600,11,6726,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Protector - In Combat - Cast Silence"),
(@ENTRY,0,1,0,0,0,100,2,0,0,5400,25300,11,17439,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Protector - In Combat - Cast Shadow Shock"),
(@ENTRY,0,2,0,0,0,100,2,4000,15800,9700,19400,11,15654,32,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Protector - In Combat - Cast Shadow Word: Pain");

-- Scholomance Necromancer SAI
SET @ENTRY := 10477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,5,0,100,3,0,0,0,0,11,17616,0,0,0,0,0,7,0,0,0,0,0,0,0,"Scholomance Necromancer - On Killed Unit - Cast Corpse Explosion"),
(@ENTRY,0,1,0,0,0,100,2,4800,16000,10200,26800,11,14887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Necromancer - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,2,0,2,0,100,2,0,30,28000,28000,11,12020,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Necromancer - At 30% HP - Cast Call of the Grave"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scholomance Necromancer - At 15% HP - Flee For Assist");

-- Unstable Corpse SAI
SET @ENTRY := 10480;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,3,0,0,0,0,11,17689,3,0,0,0,0,1,0,0,0,0,0,0,0,"Unstable Corpse - On Death - Cast Disease Burst");

-- Scholomance Acolyte SAI
SET @ENTRY := 10471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,500,500,0,0,11,16592,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Acolyte - Out Of Combat - Cast Shadowform"),
(@ENTRY,0,1,0,14,0,100,2,0,40,26400,48400,11,17613,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scholomance Acolyte - On Friendly Unit At 0 - 40% Health - Cast Dark Mending"),
(@ENTRY,0,2,0,0,0,100,2,4500,26000,8400,26000,11,17615,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scholomance Acolyte - In Combat - Cast Mana Burn"),
(@ENTRY,0,3,0,0,0,100,2,2400,21700,11100,29900,11,17165,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scholomance Acolyte - In Combat - Cast Mind Flay"),
(@ENTRY,0,4,0,0,0,100,2,5700,33800,15800,28600,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Acolyte - In Combat - Cast Cripple");

-- Scholomance Occultist SAI
SET @ENTRY := 10472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4800,11700,32400,39700,11,16431,33,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Occultist - In Combat - Cast Bone Armor"),
(@ENTRY,0,1,0,0,0,100,2,500,1000,6500,15600,11,17228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Occultist - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,2,0,13,0,100,3,0,0,0,0,11,15122,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scholomance Occultist - On Target Casting - Cast Counterspell");

-- Scholomance Neophyte SAI
SET @ENTRY := 10470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Neophyte - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,3400,4800,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Neophyte - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scholomance Neophyte - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,2,8600,26300,18400,36000,11,17165,1,0,0,0,0,2,0,0,0,0,0,0,0,"Scholomance Neophyte - In Combat - Cast Mind Flay");

-- Scarlet Monk SAI
SET @ENTRY := 4540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,15000,30000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Monk - In Combat - Cast Kick"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,20000,30000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Monk - In Combat - Cast Thrash");

-- Anguished Dead SAI
SET @ENTRY := 6426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2500,2500,10000,15000,11,7068,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anguished Dead - In Combat - Cast Veil of Shadow");

-- Haunting Phantasm SAI
SET @ENTRY := 6427;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,75,3,0,0,0,0,11,8986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Haunting Phantasm - On Aggro - Cast Summon Illusionary Phantasm");

-- Ironspine SAI
SET @ENTRY := 6489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,20000,35000,11,702,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ironspine - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,1,0,0,0,100,2,1500,1500,60000,80000,11,3815,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ironspine - In Combat - Cast Poison Cloud");

-- Scarlet Centurion SAI
SET @ENTRY := 4301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,31403,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Centurion - On Aggro - Cast Battle Shout");

-- Scarlet Champion SAI
SET @ENTRY := 4302;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2500,2500,12000,22000,11,17143,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Champion - In Combat - Cast Holy Strike");

-- Scarlet Defender SAI
SET @ENTRY := 4298;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Defender - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,20000,30000,11,3639,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Defender - In Combat - Cast Improved Blocking"),
(@ENTRY,0,2,0,0,0,100,2,7500,7500,15000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Defender - In Combat - Cast Shield Bash");

-- Scarlet Chaplain SAI
SET @ENTRY := 4299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,1006,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Chaplain - On Aggro - Cast Inner Fire"),
(@ENTRY,0,1,0,0,0,100,2,12000,16000,40000,46000,11,6066,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Chaplain - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,2,0,2,0,100,3,0,50,0,0,11,8362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Chaplain - At 50% HP - Cast Renew"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Chaplain - At 15% HP - Flee For Assist");

-- Scarlet Wizard SAI
SET @ENTRY := 4300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,9000,42000,49000,11,2601,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Wizard - In Combat - Cast Fire Shield III"),
(@ENTRY,0,1,0,0,0,100,2,3500,4500,6500,9500,11,8439,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Wizard - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Wizard - At 15% HP - Flee For Assist");

-- Scarlet Myrmidon SAI
SET @ENTRY := 4295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Myrmidon - At 30% HP - Cast Frenzy"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Myrmidon - At 30% HP - Say Line 0");

-- Scarlet Adept SAI
SET @ENTRY := 4296;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,8000,12000,11,9734,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Adept - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,14,0,100,3,0,40,0,0,11,6063,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Adept - On Friendly Unit At 0 - 40% Health - Cast Heal"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Adept - At 15% HP - Flee For Assist");

-- Scarlet Protector SAI
SET @ENTRY := 4292;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Protector - On Aggro - Cast Devotion Aura"),
(@ENTRY,0,1,0,14,0,100,2,0,40,15000,30000,11,31713,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Protector - On Friendly Unit At 0 - 40% Health - Cast Holy Light");

-- Scarlet Guardsman SAI
SET @ENTRY := 4290;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Guardsman - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,30000,40000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Guardsman - In Combat - Cast Disarm");

-- Scarlet Soldier SAI
SET @ENTRY := 4286;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,20000,30000,11,3639,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Soldier - In Combat - Cast Improved Blocking");

-- Death's Head Sage SAI
SET @ENTRY := 4518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,4000,30000,30000,11,8262,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Sage - In Combat - Cast Elemental Protection Totem"),
(@ENTRY,0,1,0,0,0,100,2,6000,6000,30000,30000,11,4971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Sage - In Combat - Cast Healing Ward");

-- Death's Head Seer SAI
SET @ENTRY := 4519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,30000,30000,11,4971,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Seer - In Combat - Cast Healing Ward"),
(@ENTRY,0,1,0,0,0,100,2,3000,3000,20000,25000,11,8264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Seer - In Combat - Cast Lava Spout Totem");

-- Greater Kraul Bat SAI
SET @ENTRY := 4539;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,4000,4000,18000,18000,11,8281,0,0,0,0,0,5,0,0,0,0,0,0,0,"Greater Kraul Bat - In Combat - Cast Sonic Burst");

-- Death's Head Acolyte SAI
SET @ENTRY := 4515;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,5000,10000,11,15785,0,0,0,0,0,5,0,0,0,0,0,0,0,"Death's Head Acolyte - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,2,0,100,2,0,70,20000,20000,11,8362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death's Head Acolyte - At 70% HP - Cast Renew");

-- Frost Spectre SAI
SET @ENTRY := 8585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,7,0,100,3,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Spectre - On Evade - Forced Despawn"),
(@ENTRY,0,1,0,14,0,100,3,0,100,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frost Spectre - On Friendly Unit At 0 - 100% Health - Forced Despawn");

-- Death Speaker Jargba SAI
SET @ENTRY := 4428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Speaker Jargba - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Speaker Jargba - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Death Speaker Jargba - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,2,7000,10000,10000,15000,11,14515,1,0,0,0,0,6,0,0,0,0,0,0,0,"Death Speaker Jargba - In Combat - Cast Dominate Mind");

-- Skeletal Servant SAI
SET @ENTRY := 8477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,5000,5000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Servant - Out Of Combat - Forced Despawn");

-- Plaguemaw the Rotting SAI
SET @ENTRY := 7356;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,12000,15000,23000,11,12946,0,0,0,0,0,5,0,0,0,0,0,0,0,"Plaguemaw the Rotting - In Combat - Cast Putrid Stench");

-- Thorn Eater Ghoul SAI
SET @ENTRY := 7348;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,12000,8000,13000,11,12538,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thorn Eater Ghoul - In Combat - Cast Ravenous Claw");

-- Frozen Soul SAI
SET @ENTRY := 7352;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,10000,12000,11,12528,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frozen Soul - In Combat - Cast Silence");

-- Freezing Spirit SAI
SET @ENTRY := 7353;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,10000,12000,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Freezing Spirit - In Combat - Cast Frost Nova");

-- Ragglesnout SAI
SET @ENTRY := 7354;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragglesnout - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragglesnout - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ragglesnout - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,2,3000,5000,20000,25000,11,11639,1,0,0,0,0,5,0,0,0,0,0,0,0,"Ragglesnout - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,11,0,0,0,100,2,9000,13000,15000,20000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Ragglesnout - In Combat - Cast Dominate Mind"),
(@ENTRY,0,12,0,14,0,100,2,0,40,12000,16000,11,12039,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ragglesnout - On Friendly Unit At 0 - 40% Health - Cast Heal");

-- Splinterbone Warrior SAI
SET @ENTRY := 7344;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,12000,6000,10000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinterbone Warrior - In Combat - Cast Sunder Armor");

-- Splinterbone Captain SAI
SET @ENTRY := 7345;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,7000,4000,10000,11,12461,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinterbone Captain - In Combat - Cast Backhand"),
(@ENTRY,0,1,0,4,0,100,3,0,0,0,0,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinterbone Captain - On Aggro - Cast Battle Shout");

-- Splinterbone Centurion SAI
SET @ENTRY := 7346;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,9000,8000,15000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinterbone Centurion - In Combat - Cast Thunderclap");

-- Boneflayer Ghoul SAI
SET @ENTRY := 7347;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,8000,3000,10000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boneflayer Ghoul - In Combat - Cast Cleave");

-- Skeletal Frostweaver SAI
SET @ENTRY := 7341;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Frostweaver - On Aggro - Cast Frostbolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Frostweaver - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Frostweaver - At 100% Mana - Increment Phase");

-- Skeletal Summoner SAI
SET @ENTRY := 7342;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Summoner - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Summoner - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,3,6000,10000,0,0,11,11980,1,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Summoner - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,11,0,0,0,100,2,15000,20000,15000,20000,11,12258,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Summoner - In Combat - Cast Summon Shadowcaster");

-- Ragefire Shaman SAI
SET @ENTRY := 11319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragefire Shaman - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragefire Shaman - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,14,0,100,3,0,40,30000,35000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ragefire Shaman - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,11,0,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ragefire Shaman - At 15% HP - Flee For Assist");

-- Searing Blade Warlock SAI
SET @ENTRY := 11324;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - Out Of Combat - Cast Summon Voidwalker"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Blade Warlock - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - On Aggro - Set Phase 6"),
(@ENTRY,0,4,0,0,0,100,2,0,0,3400,6500,11,20791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Blade Warlock - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 15% Mana - Set Phase 5"),
(@ENTRY,0,7,0,9,0,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 100% Mana - Set Phase 6"),
(@ENTRY,0,11,0,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Searing Blade Warlock - At 15% HP - Flee For Assist");

-- Rotgrip SAI
SET @ENTRY := 13596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,6000,12000,12000,11,16495,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotgrip - In Combat - Cast Fatal Bite");

-- Stolid Snapjaw SAI
SET @ENTRY := 13599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,1000,1000,11,14104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stolid Snapjaw - Out Of Combat - Cast Spikes");

-- Tinkerer Gizlock SAI
SET @ENTRY := 13601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tinkerer Gizlock - On Aggro - Cast Shoot"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,2300,3900,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,14,0,0,0,100,2,9000,12000,14000,17000,11,9143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Cast Bomb"),
(@ENTRY,0,15,16,0,0,100,0,6000,9000,16000,19000,11,21833,40,0,0,0,0,2,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Cast Goblin Dragon Gun"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Set Faction 0"),
(@ENTRY,0,17,0,0,0,100,2,25000,25000,25000,25000,11,29419,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tinkerer Gizlock - In Combat - Cast Flash Bomb"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tinkerer Gizlock - On Evade - Display melee weapon");

-- Spirit of Kolk SAI
SET @ENTRY := 12240;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,2,21960,0,0,0,36,13742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Kolk - On Spellhit Manifest Spirit - Update Template");

-- Spirit of Magra SAI
SET @ENTRY := 12241;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,2,21960,0,0,0,36,13740,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Magra - On Spellhit Manifest Spirit - Update Template");

-- Spirit of Maraudos SAI
SET @ENTRY := 12242;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,2,21960,0,0,0,36,13739,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Maraudos - On Spellhit Manifest Spirit - Update Template");

-- Spirit of Veng SAI
SET @ENTRY := 12243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,2,21960,0,0,0,36,13738,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Veng - On Spellhit Manifest Spirit - Update Template");

-- Razorlash SAI
SET @ENTRY := 12258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,4000,4000,6500,6500,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorlash - In Combat - Cast Thrash"),
(@ENTRY,0,1,0,0,0,85,2,6000,6000,8000,8000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorlash - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,85,2,12000,12000,12000,12000,11,15976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorlash - In Combat - Cast Puncture");

-- Meshlok the Harvester SAI
SET @ENTRY := 12237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,11000,11000,9000,9000,11,15593,0,0,0,0,0,2,0,0,0,0,0,0,0,"Meshlok the Harvester - In Combat - Cast War Stomp"),
(@ENTRY,0,1,0,0,0,85,2,7000,7000,9000,9000,11,13446,0,0,0,0,0,2,0,0,0,0,0,0,0,"Meshlok the Harvester - In Combat - Cast Strike");

-- Spirit of Gelk SAI
SET @ENTRY := 12239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,2,21960,0,0,0,36,13741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit of Gelk - On Spellhit Manifest Spirit - Update Template");

-- Ambereye Basilisk SAI
SET @ENTRY := 11785;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,6000,6000,16000,16000,11,11020,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ambereye Basilisk - In Combat - Cast Petrify");

-- Ambereye Reaver SAI
SET @ENTRY := 11786;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,6000,6000,16000,16000,11,11020,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ambereye Reaver - In Combat - Cast Petrify"),
(@ENTRY,0,1,0,0,0,75,2,8000,8000,8000,8000,11,40504,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ambereye Reaver - In Combat - Cast Cleave");

-- Lord Vyletongue SAI
SET @ENTRY := 12236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,42459,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - On Aggro - Cast Dual Wield"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Vyletongue - On Aggro - Cast Shoot"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,5,30,2300,3900,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Vyletongue - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,7,8,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,9,10,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,11,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,14,15,9,0,100,0,5,30,7000,9500,11,21390,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Vyletongue - At 5 - 30 Range - Cast Multi-Shot"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,16,0,0,0,100,2,20000,30000,20000,30000,11,21655,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - In Combat - Cast Blink"),
(@ENTRY,0,17,0,0,0,100,2,8000,12000,14000,18000,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - In Combat - Cast Smoke Bomb"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - On Evade - Display melee weapon");

-- Shadowshard Rumbler SAI
SET @ENTRY := 11777;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,65,2,20000,20000,7500,7500,11,5568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowshard Rumbler - In Combat - Cast Trample");

-- Shadowshard Smasher SAI
SET @ENTRY := 11778;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,40000,40000,20000,20000,11,10101,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowshard Smasher - In Combat - Cast Knock Away"),
(@ENTRY,0,1,0,0,0,70,2,25000,25000,15000,15000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowshard Smasher - In Combat - Cast Knockdown");

-- Ambershard Crusher SAI
SET @ENTRY := 11781;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,70,2,20000,20000,5000,5000,11,21055,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ambershard Crusher - In Combat - Cast Crush Armor");

-- Ambershard Destroyer SAI
SET @ENTRY := 11782;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,2,15000,15000,5000,5000,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambershard Destroyer - In Combat - Cast Thrash"),
(@ENTRY,0,1,0,0,0,80,2,20000,20000,15000,15000,11,19701,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ambershard Destroyer - In Combat - Cast Boulder"),
(@ENTRY,0,2,0,0,0,75,2,23000,23000,9000,9000,11,13728,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ambershard Destroyer - In Combat - Cast Earth Shock");

-- Brightscale Wyrm SAI
SET @ENTRY := 24761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,7,0,0,0,0,11,44406,2,0,0,0,0,2,0,0,0,0,0,0,0,"Brightscale Wyrm - On Death - Cast Energy Infusion");

-- Sunblade Keeper SAI
SET @ENTRY := 24762;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Keeper - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,6,0,40,3400,4800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Keeper - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Keeper - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,6,6100,8600,15000,25000,11,20741,1,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Keeper - In Combat - Cast Shadow Bolt Volley"),
(@ENTRY,0,11,0,0,0,100,6,9000,12000,12000,15000,11,44765,1,0,0,0,0,6,0,0,0,0,0,0,0,"Sunblade Keeper - In Combat - Cast Banish");

-- Sunblade Imp SAI
SET @ENTRY := 24815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,44577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Imp - On Aggro - Cast Firebolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,30,3400,4800,11,44577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Imp - At 0 - 30 Range - Cast Firebolt"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,11,46044,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Imp - On Aggro - Cast Firebolt"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - On Aggro - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,4,0,30,3400,4800,11,46044,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Imp - At 0 - 30 Range - Cast Firebolt"),
(@ENTRY,0,7,8,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - At 15% Mana - Increment Phase"),
(@ENTRY,0,9,0,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Imp - At 100% Mana - Increment Phase");

-- Sister of Torment SAI
SET @ENTRY := 24697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3500,3500,25000,35000,11,44547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sister of Torment - In Combat - Cast Deadly Embrace"),
(@ENTRY,0,1,0,0,0,100,6,0,0,12000,22000,11,44640,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sister of Torment - In Combat - Cast Lash of Pain");

-- Ethereum Smuggler SAI
SET @ENTRY := 24698;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,10000,12000,17000,11,44538,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ethereum Smuggler - In Combat - Cast Arcane Explosion");

-- Wretched Husk SAI
SET @ENTRY := 24690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4000,29000,39000,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Husk - In Combat - Cast Drink Fel Infusion"),
(@ENTRY,0,1,0,0,0,50,6,5000,5000,7000,17000,11,44503,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Husk - In Combat - Cast Wretched Fireball"),
(@ENTRY,0,2,0,0,0,50,6,6500,6500,14000,24000,11,44504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Husk - In Combat - Cast Wretched Frostbolt");

-- Coilskar Witch SAI
SET @ENTRY := 24696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,35946,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilskar Witch - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,5000,11,35946,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilskar Witch - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,4,0,100,0,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilskar Witch - On Aggro - Cast Shoot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - On Aggro - Increment Phase"),
(@ENTRY,0,8,9,9,0,100,0,5,30,2300,5000,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coilskar Witch - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,10,11,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,14,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,15,16,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,17,18,9,0,100,0,0,50,8000,15000,11,44639,1,0,0,0,0,2,0,0,0,0,0,0,0,"Coilskar Witch - At 0 - 50 Range - Cast Frost Arrow"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 0 - 50 Range - Display ranged weapon"),
(@ENTRY,0,19,0,0,0,100,2,3700,7000,15000,20000,11,20299,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilskar Witch - In Combat - Cast Forked Lightning"),
(@ENTRY,0,20,0,0,0,100,4,3700,7000,15000,20000,11,46150,0,0,0,0,0,5,0,0,0,0,0,0,0,"Coilskar Witch - In Combat - Cast Forked Lightning"),
(@ENTRY,0,21,0,2,0,100,2,0,50,70000,85000,11,17741,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 50% HP - Cast Mana Shield"),
(@ENTRY,0,22,0,2,0,100,4,0,50,62000,70000,11,46151,1,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - At 50% HP - Cast Mana Shield"),
(@ENTRY,0,23,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coilskar Witch - On Evade - Display melee weapon");

-- Sunblade Warlock SAI
SET @ENTRY := 24686;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,44517,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Warlock - Out Of Combat - Cast Summon Sunblade Imp"),
(@ENTRY,0,1,0,1,0,100,7,1,1000,180000,180000,11,44520,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Warlock - Out Of Combat - Cast Fel Armor"),
(@ENTRY,0,2,0,0,0,100,2,20000,20000,12000,17000,11,44518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Warlock - In Combat - Cast Immolate"),
(@ENTRY,0,3,0,0,0,100,4,13900,13900,10000,15000,11,46042,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Warlock - In Combat - Cast Immolate"),
(@ENTRY,0,4,0,0,0,100,2,5000,5000,15000,50000,11,44519,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunblade Warlock - In Combat - Cast Incinerate"),
(@ENTRY,0,5,0,0,0,100,4,4000,4000,5000,20000,11,46043,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunblade Warlock - In Combat - Cast Incinerate");

-- Sunblade Physician SAI
SET @ENTRY := 24687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,44599,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Physician - On Aggro - Cast Inject Poison"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,46046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Physician - On Aggro - Cast Inject Poison"),
(@ENTRY,0,2,0,0,0,75,2,14000,14000,12000,19500,11,44599,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Physician - In Combat - Cast Inject Poison"),
(@ENTRY,0,3,0,0,0,100,4,12000,14000,10000,25000,11,46046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Physician - In Combat - Cast Inject Poison"),
(@ENTRY,0,4,0,0,0,75,2,26000,26000,24000,54000,11,44583,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Physician - In Combat - Cast Prayer of Mending"),
(@ENTRY,0,5,0,0,0,100,4,24000,24000,24000,54000,11,46045,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Physician - In Combat - Cast Prayer of Mending");

-- Wretched Skulker SAI
SET @ENTRY := 24688;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7300,29000,39000,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Skulker - In Combat - Cast Drink Fel Infusion"),
(@ENTRY,0,1,0,0,0,100,6,6200,14000,5000,12000,11,44533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Skulker - In Combat - Cast Wretched Stab");

-- Wretched Bruiser SAI
SET @ENTRY := 24689;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,7900,7900,23000,33000,11,44505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Bruiser - In Combat - Cast Drink Fel Infusion"),
(@ENTRY,0,1,0,0,0,100,6,3800,3800,6000,11000,11,44534,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Bruiser - In Combat - Cast Wretched Strike");

-- Sunblade Blood Knight SAI
SET @ENTRY := 24684;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,44480,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Blood Knight - On Aggro - Cast Seal of Wrath"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,46030,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Blood Knight - On Aggro - Cast Seal of Wrath"),
(@ENTRY,0,2,0,0,0,100,2,15000,20000,15000,20000,11,44482,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunblade Blood Knight - In Combat - Cast Judgement of Wrath"),
(@ENTRY,0,3,0,0,0,100,4,15000,20000,15000,20000,11,46033,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sunblade Blood Knight - In Combat - Cast Judgement of Wrath"),
(@ENTRY,0,4,0,14,0,100,2,0,40,30000,50000,11,44479,1,0,0,0,0,7,0,0,0,0,0,0,0,"Sunblade Blood Knight - On Friendly Unit At 0 - 40% Health - Cast Holy Light"),
(@ENTRY,0,5,0,14,0,100,4,0,40,30000,50000,11,46029,1,0,0,0,0,7,0,0,0,0,0,0,0,"Sunblade Blood Knight - On Friendly Unit At 0 - 40% Health - Cast Holy Light");

-- Sunblade Magister SAI
SET @ENTRY := 24685;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,44606,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Magister - On Aggro - Cast Frostbolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - On Aggro - Increment Phase"),
(@ENTRY,0,3,4,9,0,100,0,0,40,3400,4800,11,44606,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Magister - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 0 - 40 Range - Cast Enchantment of Spell Haste"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,46035,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Magister - On Aggro - Cast Frostbolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - On Aggro - Increment Phase"),
(@ENTRY,0,7,8,9,0,100,0,0,40,3400,4800,11,46035,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Magister - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 0 - 40 Range - Cast Enchantment of Spell Haste"),
(@ENTRY,0,9,10,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 15% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,14,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - At 100% Mana - Increment Phase"),
(@ENTRY,0,15,16,0,0,100,0,8000,11000,17000,27000,11,44644,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - In Combat - Cast Arcane Nova"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - In Combat - Cast Enchantment of Spell Haste"),
(@ENTRY,0,17,18,0,0,100,0,8000,11000,15000,21000,11,46036,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - In Combat - Cast Arcane Nova"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,11,44604,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Magister - In Combat - Cast Enchantment of Spell Haste");

-- Sunblade Mage Guard SAI
SET @ENTRY := 24683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,0,0,0,100,7,0,0,0,0,11,44475,1,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - In Combat - Cast Magic Dampening Field"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,44478,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Mage Guard - On Aggro - Cast Glaive Throw"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - On Aggro - Increment Phase"),
(@ENTRY,0,5,6,9,0,100,0,0,60,2300,5000,11,44478,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 0 - 60 Range - Cast Glaive Throw"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 0 - 60 Range - Display ranged weapon"),
(@ENTRY,0,7,8,4,0,100,0,0,0,0,0,11,46028,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Mage Guard - On Aggro - Cast Glaive Throw"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - On Aggro - Increment Phase"),
(@ENTRY,0,9,10,9,0,100,0,0,60,2300,5000,11,46028,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 0 - 60 Range - Cast Glaive Throw"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 0 - 60 Range - Display ranged weapon"),
(@ENTRY,0,11,12,9,0,100,0,45,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 45 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 45 - 80 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,14,15,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,16,17,9,0,100,0,5,20,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 5 - 20 Range - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 5 - 20 Range - Start Auto Attack"),
(@ENTRY,0,18,0,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 15% HP - Increment Phase"),
(@ENTRY,0,19,20,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Sunblade Mage Guard - At 15% HP - Flee For Assist"),
(@ENTRY,0,21,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunblade Mage Guard - On Evade - Display melee weapon");

-- Fizzle SAI
SET @ENTRY := 24656;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,44164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fizzle - On Aggro - Cast Firebolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,6,0,30,2400,3800,11,44164,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fizzle - At 0 - 30 Range - Cast Firebolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fizzle - At 100% Mana - Increment Phase");

-- Archmage Elandra SAI
SET @ENTRY := 37774;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Elandra - On Aggro - Cast Frostfire Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,3400,4800,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Elandra - At 0 - 40 Range - Cast Frostfire Bolt"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,70616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Elandra - On Aggro - Cast Frostfire Bolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,3400,4800,11,70616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Elandra - At 0 - 40 Range - Cast Frostfire Bolt"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,6,8000,12000,13000,16000,11,22746,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Elandra - In Combat - Cast Cone of Cold");

-- Shattered Hand Assassin SAI
SET @ENTRY := 17695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Assassin - Out Of Combat - Cast Stealth"),
(@ENTRY,0,1,0,0,0,100,6,2000,4000,4500,6500,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Assassin - In Combat - Cast Backstab");

-- Blood Guard Porung SAI
SET @ENTRY := 20923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,4,1900,8000,9000,22000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blood Guard Porung - In Combat - Cast Cleave");

-- Archmage Koreln SAI
SET @ENTRY := 37582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Koreln - On Aggro - Cast Frostfire Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,3400,4800,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Koreln - At 0 - 40 Range - Cast Frostfire Bolt"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,70616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Koreln - On Aggro - Cast Frostfire Bolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,3400,4800,11,70616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Koreln - At 0 - 40 Range - Cast Frostfire Bolt"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,9,0,100,6,0,8,10000,14000,11,22645,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - At 0 - 8 Range - Cast Frost Nova"),
(@ENTRY,0,15,0,0,0,100,6,8000,12000,13000,16000,11,22746,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Koreln - In Combat - Cast Cone of Cold");

-- Shattered Hand Champion SAI
SET @ENTRY := 17671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,1500,1500,5500,8500,11,32588,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Champion - In Combat - Cast Concussion Blow"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,13,100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Champion - In Combat - Add -100% Threat"),
(@ENTRY,0,2,0,0,0,100,6,500,500,10000,10000,11,32587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Champion - In Combat - Cast Shield Block"),
(@ENTRY,0,3,0,0,0,100,6,4000,4000,7000,11000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Champion - In Combat - Cast Shield Bash");

-- Shadowmoon Darkcaster SAI
SET @ENTRY := 17694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - On Aggro - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,4,0,40,2400,3800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,7,8,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,9,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 100% Mana - Increment Phase"),
(@ENTRY,0,13,0,0,0,100,2,2000,6000,15000,18000,11,11990,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - In Combat - Cast Rain of Fire"),
(@ENTRY,0,14,0,0,0,100,4,2000,6000,14000,16000,11,33508,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - In Combat - Cast Rain of Fire"),
(@ENTRY,0,15,0,0,0,100,6,4000,8000,7000,11000,11,12542,1,0,0,0,0,6,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - In Combat - Cast Fear"),
(@ENTRY,0,16,0,2,0,100,7,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 15% HP - Set Phase 3"),
(@ENTRY,0,17,18,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowmoon Darkcaster - At 15% HP - Flee For Assist");

-- Rabid Warhound SAI
SET @ENTRY := 17669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,500,500,7000,10000,11,30639,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Warhound - In Combat - Cast Carnivorous Bite"),
(@ENTRY,0,1,0,0,0,40,2,2000,2000,8000,14000,11,30636,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rabid Warhound - In Combat - Cast Furious Howl"),
(@ENTRY,0,2,0,0,0,40,4,2000,2000,8000,14000,11,35942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rabid Warhound - In Combat - Cast Furious Howl");

-- Shattered Hand Houndmaster SAI
SET @ENTRY := 17670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,5000,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,4,0,100,0,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - On Aggro - Cast Shoot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - On Aggro - Increment Phase"),
(@ENTRY,0,8,9,9,0,100,0,5,30,2300,5000,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,10,11,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,14,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,15,16,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,17,18,0,0,100,0,7000,12000,60000,70000,11,34100,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - In Combat - Cast Volley"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - In Combat - Display ranged weapon"),
(@ENTRY,0,19,20,0,0,100,0,7000,9000,60000,65000,11,35950,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - In Combat - Cast Volley"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - In Combat - Display ranged weapon"),
(@ENTRY,0,21,22,9,0,100,0,5,30,12000,16000,11,30932,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Cast Impaling Bolt"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,23,24,9,0,100,0,5,30,12000,16000,11,40248,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Cast Impaling Bolt"),
(@ENTRY,0,24,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,25,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Houndmaster - On Evade - Display melee weapon");

-- Dark Ranger Kalira SAI
SET @ENTRY := 37583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,31942,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Kalira - On Aggro - Cast Multi-Shot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,31942,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 5 - 30 Range - Cast Multi-Shot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Kalira - On Evade - Display melee weapon");

-- Dark Ranger Loralen SAI
SET @ENTRY := 37779;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,31942,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Loralen - On Aggro - Cast Multi-Shot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,31942,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 5 - 30 Range - Cast Multi-Shot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ranger Loralen - On Evade - Display melee weapon");

-- Shattered Hand Zealot SAI
SET @ENTRY := 17462;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,66,6,3500,3500,4000,5000,11,30989,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Zealot - In Combat - Cast Hamstring");

-- Shattered Hand Gladiator SAI
SET @ENTRY := 17464;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,500,500,6000,9000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Gladiator - In Combat - Cast Mortal Strike");

-- Shattered Hand Centurion SAI
SET @ENTRY := 17465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,500,500,4000,4000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Centurion - In Combat - Cast Sunder Armor"),
(@ENTRY,0,1,0,0,0,100,6,2000,2000,8000,14500,11,42246,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Centurion - In Combat - Cast Propagandized!");

-- Shattered Hand Executioner SAI
SET @ENTRY := 17301;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,66,6,500,500,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Executioner - In Combat - Cast Cleave");

-- Creeping Ooze SAI
SET @ENTRY := 17356;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,500,900,3800,6500,11,30494,0,0,0,0,0,2,0,0,0,0,0,0,0,"Creeping Ooze - In Combat - Cast Sticky Ooze");

-- Shattered Hand Sharpshooter SAI
SET @ENTRY := 16704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,5000,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,4,0,100,0,0,0,0,0,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - On Aggro - Cast Shoot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - On Aggro - Increment Phase"),
(@ENTRY,0,8,9,9,0,100,0,5,30,2300,5000,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,10,11,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,14,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,15,16,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,17,18,9,0,100,0,5,90,6000,9000,11,30481,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 90 Range - Cast Incendiary Shot"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 90 Range - Display ranged weapon"),
(@ENTRY,0,19,20,9,0,100,0,5,100,6000,9000,11,35945,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 100 Range - Cast Incendiary Shot"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 100 Range - Display ranged weapon"),
(@ENTRY,0,21,22,9,0,100,0,5,30,10000,14000,11,37551,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 30 Range - Cast Viper Sting"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,23,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Sharpshooter - On Evade - Display melee weapon");

-- Shattered Hand Brawler SAI
SET @ENTRY := 16593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,1500,1500,7000,10000,11,36020,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shattered Hand Brawler - In Combat - Cast Curse of the Shattered Hand"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,13,100,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Brawler - In Combat - Add -100% Threat"),
(@ENTRY,0,2,0,0,0,100,6,500,500,9500,9500,11,36033,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Brawler - In Combat - Cast Kick"),
(@ENTRY,0,3,0,0,0,100,6,4000,4000,5500,12500,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shattered Hand Brawler - In Combat - Cast Thrash");

-- Shadowmoon Acolyte SAI
SET @ENTRY := 16594;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - On Respawn - Set Ranged Movement"),
(@ENTRY,0,1,0,9,0,100,6,0,5,1,1,79,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - At 0 - 5 Range - Set Ranged Movement"),
(@ENTRY,0,2,0,9,0,20,6,0,5,2500,2500,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Acolyte - At 0 - 5 Range - Cast Mind Blast"),
(@ENTRY,0,3,0,9,0,100,6,5,30,1,1,79,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - At 5 - 30 Range - Set Ranged Movement"),
(@ENTRY,0,4,0,9,0,100,6,5,30,2500,2500,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Acolyte - At 5 - 30 Range - Cast Mind Blast"),
(@ENTRY,0,5,0,0,0,100,2,5000,5000,25000,25000,11,35944,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,6,0,0,0,100,4,5000,5000,25000,25000,11,36052,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,7,0,0,0,100,7,0,0,0,0,11,30479,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - In Combat - Cast Resist Shadow"),
(@ENTRY,0,8,0,2,0,100,2,0,60,7000,7000,11,15585,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - At 60% HP - Cast Prayer of Healing"),
(@ENTRY,0,9,0,2,0,100,4,0,60,7000,7000,11,35943,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Acolyte - At 60% HP - Cast Prayer of Healing");

-- Shattered Hand Sentry SAI
SET @ENTRY := 16507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,7,0,0,1000,1000,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Sentry - In Combat - Cast Charge"),
(@ENTRY,0,1,0,0,0,50,6,2000,2000,4000,4000,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shattered Hand Sentry - In Combat - Cast Hamstring");

-- Felguard Brute SAI
SET @ENTRY := 18894;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,10,13700,15700,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Brute - At 0 - 10 Range - Cast Uppercut"),
(@ENTRY,0,1,0,0,0,100,6,4000,8000,10000,15000,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Brute - In Combat - Cast Pummel");

-- Hellfire Familiar SAI
SET @ENTRY := 19016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,11921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Familiar - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,2900,4800,11,11921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Familiar - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Familiar - On Aggro - Cast Fireball"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,2900,4800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Familiar - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,8,9,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - At 15% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Familiar - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,4,6000,9000,6000,9000,11,14034,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Familiar - In Combat - Cast Fireball");

-- Laughing Skull Rogue SAI
SET @ENTRY := 17491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Rogue - Out Of Combat - Cast Stealth"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Rogue - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,28,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Rogue - On Aggro - Remove Aura Stealth"),
(@ENTRY,0,3,0,9,0,100,6,0,5,4300,8700,11,34969,33,0,0,0,0,5,0,0,0,0,0,0,0,"Laughing Skull Rogue - At 0 - 5 Range - Cast Poison"),
(@ENTRY,0,4,0,0,0,100,6,1000,5900,15000,20000,11,6434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Rogue - In Combat - Cast Slice and Dice"),
(@ENTRY,0,5,0,0,0,100,6,4100,7800,12000,15000,11,30832,0,0,0,0,0,2,0,0,0,0,0,0,0,"Laughing Skull Rogue - In Combat - Cast Kidney Shot");

-- Laughing Skull Warden SAI
SET @ENTRY := 17624;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,1000,1000,120000,130000,11,38551,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Warden - Out Of Combat - Cast Stealth Detection"),
(@ENTRY,0,1,0,0,0,100,6,300,1200,15800,15800,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Laughing Skull Warden - In Combat - Cast Battle Shout");

-- Fel Orc Neophyte SAI
SET @ENTRY := 17429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,20500,20500,11,22120,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fel Orc Neophyte - In Combat - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,6,2300,2500,120000,130000,11,8269,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Orc Neophyte - In Combat - Cast Frenzy");

-- Hellfire Imp SAI
SET @ENTRY := 17477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Imp - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Imp - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Imp - On Aggro - Cast Fireball"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,3400,4800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Imp - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,8,9,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - At 15% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Imp - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,4,6000,9000,6000,9000,11,16144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Imp - In Combat - Cast Fire Blast");

-- Shadowmoon Adept SAI
SET @ENTRY := 17397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Adept - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,6,2600,7800,7200,13300,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Adept - In Combat - Cast Thrash"),
(@ENTRY,0,2,0,0,0,100,6,5600,12300,9600,11400,11,11978,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Adept - In Combat - Cast Kick"),
(@ENTRY,0,3,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowmoon Adept - At 15% HP - Flee For Assist");

-- Seductress SAI
SET @ENTRY := 17399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,12800,12800,11,32202,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seductress - In Combat - Cast Lash of Pain"),
(@ENTRY,0,1,0,0,0,100,6,3200,5700,13700,13700,11,31865,1,0,0,0,0,6,0,0,0,0,0,0,0,"Seductress - In Combat - Cast Seduction");

-- Felguard Annihilator SAI
SET @ENTRY := 17400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,5,0,0,8700,14700,11,58747,0,0,0,0,0,5,0,0,0,0,0,0,0,"Felguard Annihilator - In Combat - Cast Intercept"),
(@ENTRY,0,1,0,9,0,100,6,0,10,8200,22100,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Annihilator - At 0 - 10 Range - Cast Uppercut"),
(@ENTRY,0,2,0,0,0,100,6,6000,9500,6900,14800,11,15615,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felguard Annihilator - In Combat - Cast Pummel");

-- Felhound Manastalker SAI
SET @ENTRY := 17401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,2500,11100,11300,11,13321,0,0,0,0,0,5,0,0,0,0,0,0,0,"Felhound Manastalker - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,6,3300,8700,12900,12900,11,30849,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felhound Manastalker - In Combat - Cast Spell Lock");

-- Shadowmoon Warlock SAI
SET @ENTRY := 17371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Warlock - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,3300,4900,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Warlock - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - On Aggro - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,4,0,40,3300,4900,11,15472,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,7,8,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 15% Mana - Increment Phase"),
(@ENTRY,0,9,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Warlock - At 100% Mana - Increment Phase"),
(@ENTRY,0,13,0,0,0,100,2,1100,7800,14800,30100,11,32197,33,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Warlock - In Combat - Cast Corruption"),
(@ENTRY,0,14,0,0,0,100,4,1100,7800,14800,30100,11,37113,33,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Warlock - In Combat - Cast Corruption"),
(@ENTRY,0,15,0,0,0,100,6,6600,10700,14900,14900,11,13338,33,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Warlock - In Combat - Cast Curse of Tongues");

-- Shadowmoon Summoner SAI
SET @ENTRY := 17395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Summoner - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,2,0,40,2400,3800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,4,0,100,0,0,0,0,0,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Summoner - On Aggro - Cast Fireball"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - On Aggro - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,4,0,40,2400,3800,11,17290,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,7,8,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 15% Mana - Increment Phase"),
(@ENTRY,0,9,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - At 100% Mana - Increment Phase"),
(@ENTRY,0,13,0,0,0,100,7,1000,5000,0,0,11,30853,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - In Combat - Cast Summon Seductress"),
(@ENTRY,0,14,0,0,0,100,7,10500,13000,0,0,11,30851,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmoon Summoner - In Combat - Cast Summon Felhound Manastalker"),
(@ENTRY,0,15,0,0,0,100,2,12000,14000,12000,14000,11,18399,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Summoner - In Combat - Cast Flamestrike"),
(@ENTRY,0,16,0,0,0,100,4,12000,14000,12000,14000,11,16102,1,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowmoon Summoner - In Combat - Cast Flamestrike");

-- Bleeding Hollow Scryer SAI
SET @ENTRY := 17478;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,7,0,0,0,0,11,31059,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Scryer - On Respawn - Cast Hellfire Channeling"),
(@ENTRY,0,1,0,21,0,100,7,1000,1000,1000,1000,11,31059,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Scryer - Just Reached Home - Cast Hellfire Channeling");

-- Fiendish Hound SAI
SET @ENTRY := 17540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,6000,8000,11000,13000,11,15785,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fiendish Hound - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,2,0,100,6,0,30,7000,10000,11,35748,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fiendish Hound - At 30% HP - Cast Drain Life");

-- Hellfire Watcher SAI
SET @ENTRY := 17309;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2400,6100,10500,23400,11,14032,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellfire Watcher - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,14,0,100,2,0,40,12000,20000,11,12039,1,0,0,0,0,7,0,0,0,0,0,0,0,"Hellfire Watcher - On Friendly Unit At 0 - 40% Health - Cast Heal"),
(@ENTRY,0,2,0,14,0,100,4,0,40,12000,20000,11,30643,1,0,0,0,0,7,0,0,0,0,0,0,0,"Hellfire Watcher - On Friendly Unit At 0 - 40% Health - Cast Heal"),
(@ENTRY,0,3,0,2,0,100,6,0,50,20000,25000,11,8362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hellfire Watcher - At 50% HP - Cast Renew");

-- Bonechewer Ravener SAI
SET @ENTRY := 17264;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Ravener - On Respawn - Cast Invisibility and Stealth Detection");

-- Bleeding Hollow Darkcaster SAI
SET @ENTRY := 17269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - On Aggro - Cast Scorch"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,30,2400,4900,11,15241,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 0 - 30 Range - Cast Scorch"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,36807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - On Aggro - Cast Scorch"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,30,2400,4900,11,36807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 0 - 30 Range - Cast Scorch"),
(@ENTRY,0,8,9,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,2,11600,23300,22700,33400,11,20754,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - In Combat - Cast Rain of Fire"),
(@ENTRY,0,15,0,0,0,100,4,11600,23300,22700,33400,11,36808,1,0,0,0,0,5,0,0,0,0,0,0,0,"Bleeding Hollow Darkcaster - In Combat - Cast Rain of Fire");

-- Bleeding Hollow Archer SAI
SET @ENTRY := 17270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,18651,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Archer - On Aggro - Cast Multi-Shot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,5000,11,18651,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 5 - 30 Range - Cast Multi-Shot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,4,0,100,0,0,0,0,0,11,31942,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Archer - On Aggro - Cast Multi-Shot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - On Aggro - Increment Phase"),
(@ENTRY,0,8,9,9,0,100,0,5,30,2300,5000,11,31942,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 5 - 30 Range - Cast Multi-Shot"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,10,11,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,14,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,15,16,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,17,18,0,0,100,0,12100,15300,13300,18200,11,30614,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bleeding Hollow Archer - In Combat - Cast Aimed Shot"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - In Combat - Display ranged weapon"),
(@ENTRY,0,19,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleeding Hollow Archer - On Evade - Display melee weapon");

-- Drakkari Rhino SAI
SET @ENTRY := 29838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,55530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Rhino - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,58991,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Rhino - On Aggro - Cast Charge"),
(@ENTRY,0,2,0,0,0,100,2,5000,11000,14000,20000,11,55663,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Rhino - In Combat - Cast Deafening Roar"),
(@ENTRY,0,3,0,0,0,100,4,5000,11000,14000,20000,11,58992,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Rhino - In Combat - Cast Deafening Roar");

-- Drakkari Inciter SAI
SET @ENTRY := 29874;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,7000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Inciter - At 0 - 5 Range - Cast Strike"),
(@ENTRY,0,1,0,9,0,100,4,0,5,5000,7000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Inciter - At 0 - 5 Range - Cast Strike");

-- Drakkari Rhino SAI
SET @ENTRY := 29931;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,55530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Rhino - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,4,0,100,5,0,0,0,0,11,58991,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Rhino - On Aggro - Cast Charge"),
(@ENTRY,0,2,0,0,0,100,2,5000,11000,14000,20000,11,55663,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Rhino - In Combat - Cast Deafening Roar"),
(@ENTRY,0,3,0,0,0,100,4,5000,11000,14000,20000,11,58992,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Rhino - In Combat - Cast Deafening Roar");

-- Drakkari Raider SAI
SET @ENTRY := 29982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,5000,7000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Raider - At 0 - 5 Range - Cast Cleave");

-- Drakkari Golem SAI
SET @ENTRY := 29832;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,14000,17000,11,55635,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast Thunderclap"),
(@ENTRY,0,1,0,0,0,100,4,2000,5000,14000,17000,11,58975,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast Thunderclap"),
(@ENTRY,0,2,0,0,0,100,2,5000,9000,20000,25000,11,55636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast Shockwave"),
(@ENTRY,0,3,0,0,0,100,4,5000,9000,20000,25000,11,58977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast Shockwave"),
(@ENTRY,0,4,0,2,0,100,6,0,30,17000,20000,11,55633,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Golem - At 30% HP - Cast Body of Stone");

-- Drakkari Battle Rider SAI
SET @ENTRY := 29836;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,55348,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,5000,7000,11,55348,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,4,0,100,0,0,0,0,0,11,58966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - On Aggro - Cast Throw"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - On Aggro - Increment Phase"),
(@ENTRY,0,8,9,9,0,100,0,5,30,5000,7000,11,58966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,10,11,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,14,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,15,16,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,17,18,0,0,100,0,12000,15000,16000,22000,11,55521,33,0,0,0,0,6,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat - Cast Poisoned Spear"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat - Display ranged weapon"),
(@ENTRY,0,19,20,0,0,100,0,12000,15000,16000,22000,11,58967,33,0,0,0,0,6,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat - Cast Poisoned Spear"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat - Display ranged weapon"),
(@ENTRY,0,21,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Battle Rider - On Evade - Display melee weapon");

-- Drakkari Medicine Man SAI
SET @ENTRY := 29826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,6,0,30,12000,15000,11,55598,0,0,0,0,0,7,0,0,0,0,0,0,0,"Drakkari Medicine Man - On Friendly Unit At 0 - 30% Health - Cast Cleanse Magic"),
(@ENTRY,0,1,0,3,0,100,6,0,30,22000,29000,11,55582,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Medicine Man - At 30% Mana - Cast Mana Link"),
(@ENTRY,0,2,0,14,0,100,2,0,40,14000,21000,11,55597,1,0,0,0,0,7,0,0,0,0,0,0,0,"Drakkari Medicine Man - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,3,0,14,0,100,4,0,40,14000,21000,11,58980,1,0,0,0,0,7,0,0,0,0,0,0,0,"Drakkari Medicine Man - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,4,0,2,0,100,3,0,50,0,0,11,55599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Medicine Man - At 50% HP - Cast Earth Shield"),
(@ENTRY,0,5,0,2,0,100,5,0,50,0,0,11,58981,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Medicine Man - At 50% HP - Cast Earth Shield");

-- Drakkari Earthshaker SAI
SET @ENTRY := 29829;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,14000,11,16172,32,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Earthshaker - At 0 - 5 Range - Cast Head Crack"),
(@ENTRY,0,1,0,9,0,100,4,0,5,9000,14000,11,58969,32,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Earthshaker - At 0 - 5 Range - Cast Head Crack"),
(@ENTRY,0,2,0,0,0,100,6,5000,8000,5000,7000,11,55567,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Earthshaker - In Combat - Cast Powerful Blow"),
(@ENTRY,0,3,0,0,0,100,6,12000,15000,12000,18000,11,55563,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Earthshaker - In Combat - Cast Slam Ground");

-- Drakkari Fire Weaver SAI
SET @ENTRY := 29822;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,55659,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - On Aggro - Cast Lava Burst"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,30,8000,9000,11,55659,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 0 - 30 Range - Cast Lava Burst"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,58972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - On Aggro - Cast Lava Burst"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,30,8000,9000,11,58972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 0 - 30 Range - Cast Lava Burst"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,2,4000,7000,12000,15000,11,55613,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Fire Weaver - In Combat - Cast Flame Shock"),
(@ENTRY,0,15,0,0,0,100,4,4000,7000,10000,14000,11,58971,1,0,0,0,0,5,0,0,0,0,0,0,0,"Drakkari Fire Weaver - In Combat - Cast Flame Shock"),
(@ENTRY,0,16,0,9,0,100,6,0,5,10000,16000,11,61362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Fire Weaver - At 0 - 5 Range - Cast Blast Wave");

-- Drakkari Lancer SAI
SET @ENTRY := 29819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,12000,15000,11,55622,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Lancer - In Combat - Cast Impale"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,12000,15000,11,58978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Lancer - In Combat - Cast Impale"),
(@ENTRY,0,2,0,0,0,100,6,9000,12000,15000,18000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Lancer - In Combat - Cast Disarm"),
(@ENTRY,0,3,0,0,0,100,6,10000,15000,17000,20000,11,40546,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Lancer - In Combat - Cast Retaliation");

-- Unyielding Constrictor SAI
SET @ENTRY := 29768;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,9000,9000,12000,11,55602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Constrictor - In Combat - Cast Vicious Bite"),
(@ENTRY,0,1,0,0,0,100,4,4000,9000,9000,12000,11,59021,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unyielding Constrictor - In Combat - Cast Vicious Bite");

-- Spitting Cobra SAI
SET @ENTRY := 29774;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,32860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,30,12000,15000,11,32860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - At 0 - 30 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,38378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,30,12000,15000,11,38378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - At 0 - 30 Range - Cast Shadow Bolt"),
(@ENTRY,0,8,9,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - At 7% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spitting Cobra - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,2,5000,10000,17000,20000,11,55703,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - In Combat - Cast Cobra Strike"),
(@ENTRY,0,15,0,0,0,100,4,5000,10000,17000,20000,11,59020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitting Cobra - In Combat - Cast Cobra Strike");

-- Crowd Pummeler 9-60 SAI
SET @ENTRY := 6229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,25000,25000,25000,35000,11,5568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crowd Pummeler 9-60 - In Combat - Cast Trample"),
(@ENTRY,0,1,0,0,0,100,2,40000,40000,35000,60000,11,10887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crowd Pummeler 9-60 - In Combat - Cast Crowd Pummel"),
(@ENTRY,0,2,0,0,0,100,2,15000,15000,15000,20000,11,8374,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crowd Pummeler 9-60 - In Combat - Cast Arcing Smash");

-- Electrocutioner 6000 SAI
SET @ENTRY := 6235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,2,25000,25000,5000,5000,11,11082,0,0,0,0,0,2,0,0,0,0,0,0,0,"Electrocutioner 6000 - In Combat - Cast Megavolt"),
(@ENTRY,0,1,0,0,0,80,2,15000,15000,8000,8000,11,15605,0,0,0,0,0,5,0,0,0,0,0,0,0,"Electrocutioner 6000 - In Combat - Cast Shock"),
(@ENTRY,0,2,0,0,0,80,2,31000,31000,11000,11000,11,11085,0,0,0,0,0,2,0,0,0,0,0,0,0,"Electrocutioner 6000 - In Combat - Cast Chain Bolt");

-- Holdout Warrior SAI
SET @ENTRY := 6391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,3000,5000,5000,7000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Holdout Warrior - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,12000,15000,11,12555,1,0,0,0,0,2,0,0,0,0,0,0,0,"Holdout Warrior - In Combat - Cast Pummel");

-- Walking Bomb SAI
SET @ENTRY := 7915;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,15000,15000,11,11504,0,0,0,0,0,1,0,0,0,0,0,0,0,"Walking Bomb - In Combat - Cast Walking Bomb Effect");

-- Dark Iron Agent SAI
SET @ENTRY := 6212;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,60000,60000,11,11802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Agent - Out Of Combat - Cast Dark Iron Land Mine");

-- Dark Iron Ambassador SAI
SET @ENTRY := 6228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Ambassador - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,2400,3800,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Ambassador - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,2,1000,1000,60000,65000,11,184,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast Fire Shield II"),
(@ENTRY,0,12,0,0,0,100,3,2000,2000,0,0,11,10870,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast Summon Burning Servant"),
(@ENTRY,0,13,0,0,0,100,3,3000,3000,0,0,11,10870,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast Summon Burning Servant"),
(@ENTRY,0,14,0,0,0,100,3,4000,4000,0,0,11,10869,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast Summon Embers");

-- Risen Drakkari Bat Rider SAI
SET @ENTRY := 26638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,5,30,9000,12000,11,16001,0,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Drakkari Bat Rider - At 5 - 30 Range - Cast Impale"),
(@ENTRY,0,1,0,0,0,100,2,3000,6000,9000,12000,11,50414,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Bat Rider - In Combat - Cast Curse of Blood"),
(@ENTRY,0,2,0,0,0,100,4,3000,6000,9000,12000,11,59009,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Drakkari Bat Rider - In Combat - Cast Curse of Blood");

-- Risen Drakkari Warrior SAI
SET @ENTRY := 26635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,5000,9500,11,36093,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast Ghost Strike"),
(@ENTRY,0,1,0,0,0,100,6,1000,3000,7250,10000,11,33661,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Warrior - In Combat - Cast Crush Armor");

-- Risen Drakkari Soulmage SAI
SET @ENTRY := 26636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,6000,7000,12000,11,49696,0,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Drakkari Soulmage - In Combat - Cast Shadow Blast"),
(@ENTRY,0,1,0,0,0,100,4,1000,5000,7000,12000,11,59013,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Soulmage - In Combat - Cast Shadow Blast"),
(@ENTRY,0,2,0,0,0,100,6,3000,6000,8900,13500,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Soulmage - In Combat - Cast Knockdown"),
(@ENTRY,0,3,0,0,0,50,4,2900,6600,10000,12000,11,59014,0,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Drakkari Soulmage - In Combat - Cast Shadow Void"),
(@ENTRY,0,4,0,0,0,50,2,2900,6600,10000,12000,11,55847,0,0,0,0,0,5,0,0,0,0,0,0,0,"Risen Drakkari Soulmage - In Combat - Cast Shadow Void"),
(@ENTRY,0,5,0,2,0,100,2,0,75,4000,6000,11,49701,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Soulmage - At 75% HP - Cast Blood Siphon"),
(@ENTRY,0,6,0,2,0,100,4,0,75,4000,6000,11,59015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Risen Drakkari Soulmage - At 75% HP - Cast Blood Siphon");

-- Ghoul Tormentor SAI
SET @ENTRY := 26621;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,3000,6000,6000,9000,11,51917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghoul Tormentor - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,9000,12000,11,51917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghoul Tormentor - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,4,6000,9000,9000,12000,11,59007,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghoul Tormentor - In Combat - Cast Flesh Rot");

-- Scourge Brute SAI
SET @ENTRY := 26623;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,3000,14000,18500,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Brute - In Combat - Cast Mortal Strike"),
(@ENTRY,0,1,0,0,0,100,6,6000,9000,9000,12000,11,35011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Brute - In Combat - Cast Knockdown");

-- Wretched Belcher SAI
SET @ENTRY := 26624;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,16345,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Belcher - Out Of Combat - Cast Disease Cloud"),
(@ENTRY,0,1,0,0,0,100,6,3000,6000,6000,9000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Belcher - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,2,6000,9000,7000,13000,11,49703,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Belcher - In Combat - Cast Bile Vomit"),
(@ENTRY,0,3,0,0,0,100,4,6000,9000,7000,13000,11,59018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Belcher - In Combat - Cast Bile Vomit");

-- Scourge Reanimator SAI
SET @ENTRY := 26626;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,50378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Reanimator - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,2,0,40,3400,4800,11,50378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Reanimator - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,11,59017,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Reanimator - On Aggro - Cast Frostbolt"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - On Aggro - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,4,0,40,3400,4800,11,59017,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Reanimator - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,8,9,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - At 15% Mana - Increment Phase"),
(@ENTRY,0,10,0,9,0,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,3,0,100,6,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Reanimator - At 100% Mana - Increment Phase"),
(@ENTRY,0,14,0,0,0,100,6,4000,8000,10000,15000,11,59017,1,0,0,0,0,5,0,0,0,0,0,0,0,"Scourge Reanimator - In Combat - Cast Frostbolt"),
(@ENTRY,0,15,0,14,0,100,7,0,30,0,0,11,49805,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scourge Reanimator - On Friendly Unit At 0 - 30% Health - Cast Unholy Frenzy");

-- Netherwalker SAI
SET @ENTRY := 14389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,5000,7000,11,22878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Netherwalker - In Combat - Cast Shadow Bolt Volley");

-- Eye of Immol'thar SAI
SET @ENTRY := 14396;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,9000,14000,11,22909,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eye of Immol'thar - In Combat - Cast Eye of Immol'thar");

-- Mana Burst SAI
SET @ENTRY := 14397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,5000,5000,7000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mana Burst - In Combat - Cast Arcane Explosion");

-- Eldreth Darter SAI
SET @ENTRY := 14398;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,17000,25000,11,22947,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Darter - In Combat - Cast Mana Burn"),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,30000,40000,11,17139,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Darter - In Combat - Cast Power Word: Shield");

-- Arcane Torrent SAI
SET @ENTRY := 14399;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,9000,7000,12000,11,22945,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Torrent - In Combat - Cast Forked Lightning"),
(@ENTRY,0,1,0,0,0,100,2,7000,14000,19000,23000,11,22946,1,0,0,0,0,5,0,0,0,0,0,0,0,"Arcane Torrent - In Combat - Cast Lightning Cloud");

-- Arcane Feedback SAI
SET @ENTRY := 14400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,15507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Feedback - Out Of Combat - Cast Lightning Shield");

-- Dread Guard SAI
SET @ENTRY := 14483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,10000,9000,12000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Guard - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,7000,12000,11,18663,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Guard - In Combat - Cast Shadow Shock");

-- Xorothian Dreadsteed SAI
SET @ENTRY := 14502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,16636,0,0,0,0,0,1,0,0,0,0,0,0,0,"Xorothian Dreadsteed - On Aggro - Cast Berserker Charge"),
(@ENTRY,0,1,0,0,0,100,2,4000,8000,20000,25000,11,22713,0,0,0,0,0,5,0,0,0,0,0,0,0,"Xorothian Dreadsteed - In Combat - Cast Flame Buffet"),
(@ENTRY,0,2,0,6,0,100,3,0,0,0,0,11,23159,7,0,0,0,0,1,0,0,0,0,0,0,0,"Xorothian Dreadsteed - On Death - Cast Summon Dreadsteed Spirit (DND)");

-- Lord Hel'nurath SAI
SET @ENTRY := 14506;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,22000,25000,11,17146,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Hel'nurath - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,0,0,100,2,11000,14000,14000,20000,11,23224,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Hel'nurath - In Combat - Cast Veil of Shadow"),
(@ENTRY,0,2,0,0,0,100,2,4000,9000,9000,15000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Hel'nurath - In Combat - Cast Knock Away"),
(@ENTRY,0,3,0,0,0,100,2,9000,13000,14000,17000,11,20989,1,0,0,0,0,6,0,0,0,0,0,0,0,"Lord Hel'nurath - In Combat - Cast Sleep");

-- Isalien SAI
SET @ENTRY := 16097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,1000,1000,0,0,11,27639,0,0,0,0,0,1,0,0,0,0,0,0,0,"Isalien - On Aggro - Cast Call Pet"),
(@ENTRY,0,1,0,9,0,100,2,5,30,2800,3900,11,22907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Isalien - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,2,0,9,0,100,2,5,30,7000,12000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Isalien - At 5 - 30 Range - Cast Multi-Shot"),
(@ENTRY,0,3,0,0,0,100,2,4000,9000,12000,15000,11,12024,0,0,0,0,0,5,0,0,0,0,0,0,0,"Isalien - In Combat - Cast Net"),
(@ENTRY,0,4,0,0,0,100,2,20000,30000,20000,30000,11,27636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Isalien - In Combat - Cast Starshards"),
(@ENTRY,0,5,0,2,0,100,2,0,80,20000,25000,11,27637,1,0,0,0,0,1,0,0,0,0,0,0,0,"Isalien - At 80% HP - Cast Regrowth");
