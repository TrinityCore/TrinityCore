-- Netherstrand Longbow SAI
SET @ID := 21268;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherstrand Longbow - On AI Initialize - Set Corpse Delay"),
(@ID,0,1,0,0,0,100,0,0,0,3600,3600,0,11,36980,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Netherstrand Longbow - In Combat CMC - Cast 'Shoot'"),
(@ID,0,2,0,0,0,100,0,5000,15000,15000,30000,0,11,36979,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Netherstrand Longbow - In Combat - Cast 'Multi-Shot'"),
(@ID,0,3,0,0,0,100,0,30000,50000,30000,50000,0,11,36994,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Netherstrand Longbow - In Combat - Cast 'Blink'");

-- Devastation SAI
SET @ID := 21269;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devastation - On AI Initialize - Set Corpse Delay"),
(@ID,0,1,0,0,0,100,0,10000,20000,20000,30000,0,11,36981,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Devastation - In Combat - Cast 'Whirlwind'");

-- Cosmic Infuser SAI
SET @ID := 21270;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cosmic Infuser - On AI Initialize - Set Corpse Delay"),
(@ID,0,1,0,0,0,100,0,5000,10000,10000,10000,0,11,36983,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cosmic Infuser - In Combat - Cast 'Heal'"),
(@ID,0,2,0,0,0,100,0,0,5000,5000,15000,0,11,36985,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Cosmic Infuser - In Combat - Cast 'Holy Nova'");

-- Infinity Blades SAI
SET @ID := 21271;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Infinity Blades - On AI Initialize - Set Corpse Delay"),
-- Usually triggered from proc aura however in this case for some reason no aura and slots are occupied by player auras
-- From my experience even if aura was completely hidden, slots were not empty
(@ID,0,1,0,0,0,100,0,5000,15000,10000,15000,0,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Infinity Blades - In Combat - Cast 'Thrash'");

-- Warp Slicer SAI
SET @ID := 21272;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Warp Slicer - On AI Initialize - Set Corpse Delay"),
(@ID,0,1,0,0,0,100,0,6000,6000,6000,6000,0,11,36991,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Warp Slicer - In Combat - Cast 'Rend'");

-- Phaseshift Bulwark SAI
SET @ID := 21273;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Phaseshift Bulwark - On AI Initialize - Set Corpse Delay"),
(@ID,0,1,0,0,0,100,0,5000,10000,5000,15000,0,11,36988,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Phaseshift Bulwark - In Combat - Cast 'Shield Bash'");

-- Staff of Disintegration SAI
SET @ID := 21274;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,37,0,100,0,0,0,0,0,0,116,60,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Staff of Disintegration - On AI Initialize - Set Corpse Delay"),
(@ID,0,1,0,0,0,100,0,0,0,2600,3600,0,11,36990,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Staff of Disintegration - In Combat CMC - Cast 'Frostbolt'"),
(@ID,0,2,0,0,0,100,0,5000,15000,15000,25000,0,11,36989,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Staff of Disintegration - In Combat - Cast 'Frost Nova'");

-- Bloodwarder Legionnaire SAI
SET @ID := 20031;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,10000,10000,15000,0,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Legionnaire - In Combat - Cast 'Cleave'"),
(@ID,0,1,0,0,0,100,0,10000,20000,15000,25000,0,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Legionnaire - In Combat - Cast 'Whirlwind'"),
(@ID,0,2,0,0,0,100,0,20000,30000,20000,30000,0,11,35949,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Legionnaire - In Combat - Cast 'Bloodthirst'");

-- Bloodwarder Vindicator SAI
SET @ID := 20032;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,10000,15000,15000,0,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Vindicator - In Combat - Cast 'Hammer of Justice'"),
(@ID,0,1,0,12,0,100,0,0,20,15000,15000,0,11,37251,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Vindicator - Target Between 0-20% Health - Cast 'Hammer of Wrath'"),
(@ID,0,2,0,74,0,100,0,0,20,10000,10000,50,11,37249,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bloodwarder Vindicator - On Friendly Between 0-20% Health - Cast 'Flash of Light'"),
(@ID,0,3,0,15,0,100,0,30,5000,10000,0,0,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bloodwarder Vindicator - Friendly Crowd Controlled - Cast 'Cleanse'");

-- Astromancer SAI
SET @ID := 20033;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,60,0,100,0,0,0,10000,15000,0,11,35915,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Astromancer - On Update - Cast 'Molten Armor'"),
(@ID,0,1,0,0,0,100,0,10000,20000,25000,30000,0,11,37109,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Astromancer - In Combat - Cast 'Fireball Volley'"),
(@ID,0,2,0,0,0,100,0,15000,25000,20000,25000,0,11,37110,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Astromancer - In Combat - Cast 'Fire Blast'");

-- Star Scryer SAI
SET @ID := 20034;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,10000,20000,20000,0,11,37122,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Star Scryer - In Combat - Cast 'Domination'"),
(@ID,0,1,0,0,0,100,0,5000,15000,20000,30000,0,11,37124,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Star Scryer - In Combat - Cast 'Starfall'"),
(@ID,0,2,0,0,0,100,0,10000,20000,10000,20000,0,11,37126,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Star Scryer - In Combat - Cast 'Arcane Blast'");

-- Bloodwarder Marshal SAI
SET @ID := 20035;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,20000,15000,25000,0,11,35949,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Marshal - In Combat - Cast 'Bloodthirst'"),
(@ID,0,1,0,0,0,100,0,15000,20000,20000,25000,0,11,34996,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Marshal - In Combat - Cast 'Uppercut'"),
(@ID,0,2,0,0,0,100,0,5000,10000,15000,20000,0,11,36132,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodwarder Marshal - In Combat - Cast 'Whirlwind'");
UPDATE `creature_template_addon` SET `auras` = "38716" WHERE `entry` = 20035;

-- Bloodwarder Squire SAI
SET @ID := 20036;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,10000,15000,15000,0,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Squire - In Combat - Cast 'Hammer of Justice'"),
(@ID,0,1,0,12,0,100,0,0,20,15000,15000,0,11,37255,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodwarder Squire - Target Between 0-20% Health - Cast 'Hammer of Wrath'"),
(@ID,0,2,0,74,0,100,0,0,60,10000,10000,50,11,37254,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bloodwarder Squire - On Friendly Between 0-60% Health - Cast 'Flash of Light'"),
(@ID,0,3,0,15,0,100,0,30,5000,10000,0,0,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bloodwarder Squire - Friendly Crowd Controlled - Cast 'Cleanse'");

-- Tempest Falconer SAI
SET @ID := 20037;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,60,0,100,0,0,0,30000,30000,0,11,37318,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tempest Falconer - On Update - Cast 'Fire Shield'"),
(@ID,0,1,0,0,0,100,0,0,0,3600,3600,0,11,39079,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Tempest Falconer - In Combat CMC - Cast 'Shoot'"),
(@ID,0,2,0,0,0,100,0,6000,12000,6000,12000,0,11,37154,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Tempest Falconer - In Combat - Cast 'Immolation Arrow'"),
(@ID,0,3,0,0,0,100,0,5000,10000,10000,10000,0,11,37317,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tempest Falconer - In Combat - Cast 'Knockback'");

-- Phoenix-Hawk Hatchling SAI
SET @ID := 20038;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,10000,15000,25000,0,11,37160,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Phoenix-Hawk Hatchling - In Combat - Cast 'Silence'"),
(@ID,0,1,0,0,0,100,0,5000,15000,15000,30000,0,11,37319,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Phoenix-Hawk Hatchling - In Combat - Cast 'Wing Buffet'");

-- Phoenix-Hawk SAI
SET @ID := 20039;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,15000,20000,25000,0,11,37156,0,0,0,0,0,28,45,0,0,0,0,0,0,0,"Phoenix-Hawk - In Combat - Cast 'Dive'"),
(@ID,0,1,0,0,0,100,0,10000,20000,20000,30000,0,11,37159,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Phoenix-Hawk - In Combat - Cast 'Mana Burn'");

-- Crystalcore Devastator SAI
SET @ID := 20040;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,20000,30000,25000,35000,0,11,35035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crystalcore Devastator - In Combat - Cast 'Countercharge'"),
(@ID,0,1,0,0,0,100,0,20000,25000,20000,30000,0,11,37102,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crystalcore Devastator - In Combat - Cast 'Knock Away'"),
-- 37.5 (CMaNGOS)
(@ID,0,2,0,31,0,100,0,37102,0,0,0,0,13,0,37,0,0,0,0,7,0,0,0,0,0,0,0,0,"Crystalcore Devastator - On Target Spellhit 'Knock Away' - Set Single Threat 0-37");

-- Crystalcore Sentinel SAI
SET @ID := 20041;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,20000,20000,30000,0,11,37106,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crystalcore Sentinel - In Combat - Cast 'Charged Arcane Explosion'"),
(@ID,0,1,2,0,0,100,0,15000,25000,15000,25000,0,11,37104,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Crystalcore Sentinel - In Combat - Cast 'Overcharge'"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crystalcore Sentinel - On Link - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s's hand begins to glow with Arcane energy!",16,0,100,0,0,0,19264,0,"Crystalcore Sentinel");

-- Tempest-Smith SAI
SET @ID := 20042;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,7000,10000,7000,10000,0,11,37118,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Tempest-Smith - In Combat - Cast 'Shell Shock'"),
(@ID,0,1,0,0,0,100,0,2000,10000,2000,10000,0,11,37120,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Tempest-Smith - In Combat - Cast 'Fragmentation Bomb'"),
(@ID,0,2,0,0,0,100,0,15000,25000,25000,35000,0,11,37112,0,0,0,0,0,26,100,0,0,0,0,0,0,0,"Tempest-Smith - In Combat - Cast 'Power Up'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 37112;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,37112,0,0,31,1,3,20040,0,0,0,0,"","Group 0: Spell 'Power Up' targets creature 'Crystalcore Devastator'"),
(17,0,37112,0,1,31,1,3,20041,0,0,0,0,"","Group 1: Spell 'Power Up' targets creature 'Crystalcore Sentinel'");

-- Apprentice Star Scryer SAI
-- Spells are not random (one of 2), some of them can cast all 4 spells with small delay, some can cast nothing, so chance is just not 100%
SET @ID := 20043;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,50,0,7000,15000,10000,20000,0,11,38725,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast 'Arcane Explosion'"),
(@ID,0,1,0,0,0,50,0,7000,15000,10000,20000,0,11,37129,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast 'Arcane Volley'"),
(@ID,0,2,0,0,0,50,0,10000,20000,15000,25000,0,11,37132,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast 'Arcane Shock'"),
(@ID,0,3,0,0,0,50,0,10000,20000,15000,25000,0,11,37133,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Apprentice Star Scryer - In Combat - Cast 'Arcane Buffet'");

-- Novice Astromancer SAI
-- Spells are not random (one of 2), some of them can cast all 4 spells with small delay, some can cast nothing, so chance is just not 100%
SET @ID := 20044;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,50,1,1000,5000,0,0,0,11,37282,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Novice Astromancer - In Combat - Cast 'Fire Shield' (No Repeat)"),
(@ID,0,1,0,0,0,50,0,5000,10000,10000,15000,0,11,37111,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Novice Astromancer - In Combat - Cast 'Fireball'"),
(@ID,0,2,0,0,0,50,0,5000,10000,10000,15000,0,11,37279,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Novice Astromancer - In Combat - Cast 'Arcane Volley'"),
(@ID,0,3,0,0,0,50,0,10000,15000,10000,15000,0,11,38728,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Novice Astromancer - In Combat - Cast 'Fire Nova'");

-- Nether Scryer SAI
SET @ID := 20045;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,25000,10000,20000,0,11,37126,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Nether Scryer - In Combat - Cast 'Arcane Blast'"),
(@ID,0,1,0,0,0,100,0,5000,15000,20000,20000,0,11,37135,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Nether Scryer - In Combat - Cast 'Domination'");

-- Astromancer Lord SAI
SET @ID := 20046;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,100,0,0,0,0,0,0,11,38732,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Astromancer Lord - On Aggro - Cast 'Fire Shield'"),
(@ID,0,1,0,0,0,100,0,15000,20000,20000,30000,0,11,37109,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Astromancer Lord - In Combat - Cast 'Fireball Volley'"),
(@ID,0,2,0,0,0,100,0,10000,15000,20000,20000,0,11,37110,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Astromancer Lord - In Combat - Cast 'Fire Blast'"),
(@ID,0,3,0,0,0,100,0,20000,25000,20000,30000,0,11,37289,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Astromancer Lord - In Combat - Cast 'Dragon's Breath'");

-- Crimson Hand Battle Mage SAI
SET @ID := 20047;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,15000,20000,30000,0,11,37262,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Hand Battle Mage - In Combat - Cast 'Frostbolt Volley'"),
(@ID,0,1,0,0,0,100,0,20000,25000,25000,40000,0,11,37263,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Crimson Hand Battle Mage - In Combat - Cast 'Blizzard'"),
(@ID,0,2,0,0,0,100,0,5000,10000,15000,20000,0,11,37265,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Hand Battle Mage - In Combat - Cast 'Cone of Cold'");
UPDATE `creature_template_addon` SET `auras` = "39086" WHERE `entry` = 20047;

-- Crimson Hand Centurion SAI, literally again after finish
SET @ID := 20048;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,10000,15000,10000,20000,0,11,37268,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Hand Centurion - In Combat - Cast 'Arcane Flurry'");

-- Crimson Hand Blood Knight SAI
SET @ID := 20049;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,5000,10000,10000,15000,0,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - In Combat - Cast 'Hammer of Justice'"),
(@ID,0,1,0,12,0,100,0,0,20,15000,15000,0,11,37259,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - Target Between 0-20% Health - Cast 'Hammer of Wrath'"),
(@ID,0,2,0,74,0,100,0,0,50,10000,10000,50,11,37257,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - On Friendly Between 0-50% Health - Cast 'Flash of Light'"),
(@ID,0,4,0,74,0,100,0,0,75,2500,2500,40,11,37260,32,0,0,0,0,7,0,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - On Friendly Between 0-75% Health - Cast 'Renew'"),
(@ID,0,5,0,15,0,100,0,30,3000,3000,0,0,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Crimson Hand Blood Knight - Friendly Crowd Controlled - Cast 'Cleanse'");

-- Crimson Hand Inquisitor SAI, Power Infusion - definitely not on aggro, no idea when
SET @ID := 20050;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,35000,35000,40000,65000,0,11,37274,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crimson Hand Inquisitor - In Combat - Cast 'Power Infusion'"),
(@ID,0,1,0,0,0,100,0,0,5000,0,10000,0,11,37276,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Crimson Hand Inquisitor - In Combat - Cast 'Mind Flay'"),
(@ID,0,2,0,0,0,100,0,5000,15000,10000,10000,0,11,37275,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Crimson Hand Inquisitor - In Combat - Cast 'Shadow Word: Pain'");

-- Crystalcore Mechanic SAI
SET @ID := 20052;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,20000,50000,20000,50000,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crystalcore Mechanic - Out of Combat - Run Script"),
-- This thing requires additional research, so far I see no real pattern here, some casts 2 first almost instantly,
-- then few with 1600 intervals, then 800 or 1200 or 4000, no real pattern and at the same time that thing is definitely not just random
-- Blizz indeed uses multiple fixed timers (1000-1000 or 2500-2500 or 3500-3500 for example) but that case is something else
-- Anyway they're really crazy in retail
(@ID,0,1,0,0,0,100,0,0,0,1600,1600,0,11,37123,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Crystalcore Mechanic - In Combat - Cast 'Saw Blade'"),
(@ID,0,2,0,74,0,100,0,0,50,20000,30000,10,11,37121,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Crystalcore Mechanic - On Friendly Between 0-50% Health - Cast 'Recharge'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,17,28,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crystalcore Mechanic - On Script - Set Emote State 28"),
(@ID*100+0,9,1,0,0,0,100,0,6000,6000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crystalcore Mechanic - On Script - Set Emote State 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 37121;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,37121,0,0,31,1,3,20040,0,0,0,0,"","Group 0: Spell 'Recharge' targets creature 'Crystalcore Devastator'"),
(17,0,37121,0,1,31,1,3,20041,0,0,0,0,"","Group 1: Spell 'Recharge' targets creature 'Crystalcore Sentinel'");
