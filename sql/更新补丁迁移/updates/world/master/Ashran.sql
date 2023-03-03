-- Aaron Scourgeflesh <Warspear Death Knight Leader>
SET @ENTRY := 88826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79895,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,25,15000,25000,11,79899,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chains of Ice on Close'),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,18000,22000,11,79897,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Alune Windmane <Alliance Captain>
SET @ENTRY := 80488;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,162621,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,162623,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Moonfire'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,162619,2,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Starfall');

-- Amberlight Giant
SET @ENTRY := 91917;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,189293,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Quake'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,189295,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smash on Close');

-- Ancient Inferno
SET @ENTRY := 84875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,138432,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Aura on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,138432,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fire Aura on Evade'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,176170,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,18000,22000,11,176171,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Molten Firestorm');

-- Ancient Spirit
SET @ENTRY := 76659;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,154781,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ancient Suffering');

-- Anenga <Stormshield Druid Leader>
SET @ENTRY := 81870;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79833,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mark of the Wild on Spawn'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,16561,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Regrowth at 40% HP'),
(@ENTRY,0,3,0,14,0,100,0,500000,40,15000,18000,11,12160,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies'),
(@ENTRY,0,4,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath');

-- Anne Otther <Alliance Captain>
SET @ENTRY := 85140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164063,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Plague Strike'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,18000,20000,11,164064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil');

-- Ashmaul Bruiser
SET @ENTRY := 74886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,169733,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brutal Bash'),
(@ENTRY,0,1,0,9,0,100,0,8,40,15000,25000,11,169737,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Smash on Close');

-- Ashmaul Destroyer
SET @ENTRY := 84876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176187,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Smash');

-- Ashmaul Enforcer
SET @ENTRY := 83812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Blow');

-- Ashmaul Flamespeaker
SET @ENTRY := 83790;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176768,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Blast');

-- Ashmaul Forager
SET @ENTRY := 83803;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,176796,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flaming Shot'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,176797,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Forage Food at 40% HP');

-- Ashmaul Gutwrencher
SET @ENTRY := 83804;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,151826,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boar Charge');

-- Ashmaul Magma Caster
SET @ENTRY := 84906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,169725,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lava Burst Volley');

-- Ashmaul Pyromancer
SET @ENTRY := 84878;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,169744,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,169742,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Flames');

-- Ashmaul Stoneshaper
SET @ENTRY := 84877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,169730,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,169732,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stone Bulwark at 40% HP');

-- Ashmaul Warden
SET @ENTRY := 83729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,162127,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,162133,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wild Flail on Close');

-- Atomik <Warspear Shaman Leader>
SET @ENTRY := 82204;
SET @ENTRYTOTEM := 22895;
SET @TOTEMSPELL := 39592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,39591,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Searing Totem'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,79884,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,34828,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shield at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,4000,5500,12000,15000,11,79890,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock');

-- Avenger Turley <Alliance Captain>
SET @ENTRY := 80499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,162641,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm'),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,18000,18000,11,162764,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,162638,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Avenger\'s Shield on Aggro'),
(@ENTRY,0,3,0,9,0,100,0,0,8,15000,25000,11,162642,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Consecration on Close');

-- Boneshallow Spider
SET @ENTRY := 84097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,168690,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web Spit');

-- Brickhouse <Mighty>
SET @ENTRY := 83819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,169499,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack'),
(@ENTRY,0,1,0,13,0,100,0,5000,8000,20000,30000,11,169498,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deafening Shout on Player Spell Cast'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,169504,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Brute
SET @ENTRY := 88698;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Blow');

-- Buzzing Venomfly
SET @ENTRY := 83681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,175675,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Terminal Sting');

-- Cadaverous Vulture
SET @ENTRY := 84102;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,168696,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swoop');

-- Captain Hoodrych <Horde Captain>
SET @ENTRY := 79900;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,164091,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164464,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidating Shout at 40% HP'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Carnivorous Plant
SET @ENTRY := 79933;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,161349,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Nature Spray');

-- Chani Malflame <Alliance Captain>
SET @ENTRY := 85129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,178076,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,18000,22000,11,178069,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,178072,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howl of Terror at 40% HP');

-- Crafticus Mindbender <Stormshield Quartermaster>
SET @ENTRY := 80882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,79880,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow');

-- Cursed Harbinger
SET @ENTRY := 85767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176696,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phantom Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,176701,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Essence at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,171197,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wicked Curse');

-- Cursed Kaliri
SET @ENTRY := 85765;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,158507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dive'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,171486,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wicked Curse');

-- Cursed Ravager
SET @ENTRY := 85763;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravage Armor');

-- Cursed Sharptalon
SET @ENTRY := 85766;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cursed Blood');

-- Danne Lukesi <Warspear Paladin Leader>
SET @ENTRY := 86202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79961,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Shock'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,79960,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 40% HP');

-- Darth Doomstout <Stormshield Death Knight Leader>
SET @ENTRY := 83001;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79895,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,25,15000,25000,11,79899,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chains of Ice on Close'),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,18000,22000,11,79897,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch');

-- Decker Watts <Gateway Guardian>
SET @ENTRY := 84651;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,79956,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Elements'),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,20000,22000,11,165757,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Ecilam <Stormshield Mage Leader>
SET @ENTRY := 82966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79858,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79850,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,18000,22000,11,79860,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard');

-- Elder Darkweaver Kath
SET @ENTRY := 85771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,158830,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Darkness Within'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158854,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Shadow Figurines at 40% HP');

-- Elementalist Novo <Horde Captain>
SET @ENTRY := 80491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,178059,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,25000,30000,11,178064,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Hex'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,25000,37000,11,178063,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Magma Totem'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,20000,11,178060,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning');

-- Elliott Van Rook <Horde Captain>
SET @ENTRY := 80493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79858,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79850,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,18000,22000,11,79860,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard');

-- Falcon Atherton <Gateway Guardian>
SET @ENTRY := 84652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79956,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Elements'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,79958,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Felguard on Spawn'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,165757,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Fangraal <Alliance Guardian>
SET @ENTRY := 81859;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,177606,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,168247,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Wild Growth at 40% HP');

-- Flat-Toothed Riverbeast
SET @ENTRY := 83841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close');

-- Fura <Warspear Mage Leader>
SET @ENTRY := 83995;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79858,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79850,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,18000,22000,11,79860,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blizzard');

-- Gaul Dun Firok <Alliance Champion>
SET @ENTRY := 81726;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,177157,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast MASSIVE Kick!'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,177150,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Booming Shout'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,164819,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Leap on Aggro'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,164811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Gayle Plagueheart <Gateway Guardian>
SET @ENTRY := 84645;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79939,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,165735,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Armor on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,79937,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,3,0,1,0,100,1,3000,5000,0,0,11,165736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Imp on Spawn');

-- General Lizzie Heartbane <Alliance Prisoner>
SET @ENTRY := 85673;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Genevere Hymnsorrow <Warspear Priest Leader>
SET @ENTRY := 88778;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79822,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,17140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Fire'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,4,0,2,0,100,0,0,40,22000,25000,11,11640,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 40% HP');

-- Gimlet Ginfizz
SET @ENTRY := 85749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,79880,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow');

-- Gor'vosh Necromancer
SET @ENTRY := 81087;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,168634,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,168661,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Raise Dead on Aggro');

-- Goregore
SET @ENTRY := 84893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,169668,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fast Asleep on Spawn'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,169710,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cranky at 30% HP');

-- Goren Iron-eater
SET @ENTRY := 78936;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176211,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charging Charge');

-- Grand Marshal Tremblade <Elite Conquest Quartermaster>
SET @ENTRY := 82876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,177147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Cleave'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,177165,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blade Twister');

-- Gronn Pulverizer
SET @ENTRY := 82295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,176225,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boulder Throw'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,176219,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pulverize');

-- Gronnling Breaker
SET @ENTRY := 84483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,176214,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mighty! at 40% HP');

-- Hammer
SET @ENTRY := 88699;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Blow');

-- High Warlord Volrath <Elite Conquest Quartermaster>
SET @ENTRY := 82877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,177147,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Cleave'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,178795,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blade Twister');

-- Holy Knight <Stormshield Knight Riders>
SET @ENTRY := 84165;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79964,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exorcism'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,79960,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 40% HP'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79962,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Righteousness on Spawn');

-- Ilya Plagueheart <Gateway Guardian>
SET @ENTRY := 84646;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,165735,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Armor on Spawn'),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,0,0,11,165736,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Imp on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,79937,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolate'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4700,11,79939,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Bolt');

-- Jackson Bajheera <Alliance Captain>
SET @ENTRY := 80484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,164091,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164464,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidating Shout at 40% HP'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Jared V. Hellstrike <Horde Captain>
SET @ENTRY := 85131;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164394,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blackout Kick'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,18000,22000,11,127734,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rising Sun Kick');

-- Jeron Emberfall <Warspear Tower Guardian>
SET @ENTRY := 88178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176098,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phoenix Flames'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,176652,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,176605,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Combustion Nova on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,176664,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Lava Fury at 40% HP');

-- John Swifty <Alliance Captain>
SET @ENTRY := 79902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,164091,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bladestorm on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164464,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidating Shout at 40% HP'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Kaga Barkhoof <Warspear Druid Leader>
SET @ENTRY := 88777;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,165752,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rejuvenation at 40% HP'),
(@ENTRY,0,3,0,14,0,100,0,800000,40,15000,18000,11,165753,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,600000,600000,11,165754,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mark of the Wild on Spawn');

-- Kalgan <Warspear Warrior Leader>
SET @ENTRY := 83830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close');

-- Kaliri Skyterror
SET @ENTRY := 85753;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,158507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dive');

-- Kaliri Skyterror <Horde Guardian>
SET @ENTRY := 89140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,43517,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Talon');

-- Kaliri Skyterror <Horde Guardian>
SET @ENTRY := 89139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,43517,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Talon');

-- Kamatari Whisperwind <Stormshield Hunter Leader>
SET @ENTRY := 82991;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting');

-- Kauper <Portal Guardian>
SET @ENTRY := 84466;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79854,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79857,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,79856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Kaz Endsky <Horde Captain>
SET @ENTRY := 87690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,18000,22000,11,164334,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay'),
(@ENTRY,0,2,0,0,0,100,0,3000,10000,10000,19000,11,164064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,9,0,100,0,0,30,15000,25000,11,79894,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Grip on Close');

-- Kimilyn <Forged in Flame>
SET @ENTRY := 88109;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,164443,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psychic Scream at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,164448,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast');

-- Kor'lok <The Ogre King>
SET @ENTRY := 80858;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,177157,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast MASSIVE Kick!'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,177150,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Booming Shout'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,164819,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Leap on Aggro'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,164811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Korthall Soulgorger
SET @ENTRY := 84110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,154724,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Geyser'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,19000,22000,11,154766,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Ancient Spirits'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,154784,2,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Summon Spirit Binder at 40% HP');

-- Kronus <Horde Guardian>
SET @ENTRY := 82201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,170893,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fracture'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,175058,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rock Shield at 40% HP');

-- Kroshik <Hemet Nesingwary's Pet>
SET @ENTRY := 87359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,174785,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stampede!');

-- Lava Fury
SET @ENTRY := 88404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176685,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Magma Blast');

-- Lieutenant Vessup
SET @ENTRY := 85354;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,119419,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,17000,22000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,165712,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Aggro'),
(@ENTRY,0,3,0,13,0,100,0,5000,8000,20000,30000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick on Player Spell Cast');

-- Lord Mes <Horde Captain>
SET @ENTRY := 80497;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blood Plague'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,18000,22000,11,164334,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death and Decay'),
(@ENTRY,0,2,0,0,0,100,0,3000,10000,10000,19000,11,164064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Coil'),
(@ENTRY,0,3,0,9,0,100,0,0,30,15000,25000,11,79894,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Grip on Close');

-- Malda Brewbelly <Alliance Captain>
SET @ENTRY := 85122;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting');

-- Mandragoraster
SET @ENTRY := 83683;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,161344,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fertile Spit'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,18000,22000,11,161517,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Splitting Breath');

-- Marked Apexis Windwraith
SET @ENTRY := 91919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,158087,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whirling Winds'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,18000,22000,11,186312,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Apexis Mark of Redemption');

-- Marketa <Stormshield Warlock Leader>
SET @ENTRY := 82660;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79956,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Elements'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,18000,20000,11,79955,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire');

-- Marsh Creature
SET @ENTRY := 84837;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,176810,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fungal Regrowth at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,176812,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Itchy Spores');

-- Mathias Zunn <Alliance Captain>
SET @ENTRY := 85137;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,164443,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psychic Scream at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,164448,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast');

-- Mindbender Talbadar <Horde Captain>
SET @ENTRY := 80490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,164443,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Psychic Scream at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,164448,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast');

-- Mor'riz <The Ultimate Troll>
SET @ENTRY := 85133;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164337,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Typhoon');

-- Muk'Mar Raz <Horde Champion>
SET @ENTRY := 81725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,177157,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast MASSIVE Kick!'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,177150,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Booming Shout'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,164819,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Leap on Aggro'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,164811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Necrolord Azael <Horde Captain>
SET @ENTRY := 80486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,178069,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,178076,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,178072,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howl of Terror at 40% HP');

-- Nisstyr <Warspear Warlock Leader>
SET @ENTRY := 83997;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,79933,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Life at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,79930,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,79934,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demon Armor on Spawn');

-- Nitrana
SET @ENTRY := 86820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79863,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hemorrhage'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,79862,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3500,4100,11,79866,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Throw'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,79864,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP');

-- Nozaro <Stormshield Priest Leader>
SET @ENTRY := 82939;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79822,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,17140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Fire'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,4,0,2,0,100,0,0,40,22000,25000,11,11640,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 40% HP');

-- Ogron Destructor
SET @ENTRY := 83687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,162280,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flurry'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,167680,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boulder Throw'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,162232,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Interrupting Shout at 40% HP');

-- Onyx Ravager
SET @ENTRY := 85756;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravage Armor');

-- Oraggro
SET @ENTRY := 84904;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,169716,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Headbutt'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,19000,19000,11,169721,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast HEADBUTTS!');

-- Outcast Harbinger
SET @ENTRY := 85752;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176696,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phantom Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,176701,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Essence at 40% HP');

-- Panthora
SET @ENTRY := 83691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176542,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Claws');

-- Panthran Pride
SET @ENTRY := 83692;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176512,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Strikes'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,176643,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Skulking on Spawn');

-- Panthran Witchdoctor
SET @ENTRY := 83690;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176517,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Blast'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,176643,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Skulking on Spawn'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,176516,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Mending at 40% HP');

-- Pheary Sparkrocket <Warspear Hunter Leader>
SET @ENTRY := 88781;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting');

-- Podling Poker
SET @ENTRY := 84350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176821,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poke');

-- Power Geode
SET @ENTRY := 80511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,172062,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Geode on Spawn');

-- Prison Guard
SET @ENTRY := 86664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Razor Guerra <Horde Captain>
SET @ENTRY := 85138;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,178054,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eviscerate'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,19000,20000,11,178052,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hemorrhage'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,178055,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cloak of Shadows at 40% HP');

-- Retribution Knight <Knight Riders>
SET @ENTRY := 83711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,165746,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retribution Aura on Aggro'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,165747,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Might on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,165744,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm');

-- Rifthunter Yoske <Horde Captain>
SET @ENTRY := 80496;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting');

-- Risen Ancient
SET @ENTRY := 83715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,168674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smash');

-- Risen Brute
SET @ENTRY := 81065;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,168629,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Slice');

-- Risen Mage
SET @ENTRY := 84155;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,168622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spirit Barrage');

-- Risen Spirit
SET @ENTRY := 81225;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79115,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ancient Darkness'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,88883,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pact of Darkness'),
(@ENTRY,0,2,0,2,0,35,1,0,20,0,0,11,163912,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elusion at 20% HP');

-- Rubyspike Goren
SET @ENTRY := 78935;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Spit');

-- Rylai Crestfall <Stormshield Tower Guardian>
SET @ENTRY := 88224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176268,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,176276,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,176269,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Block at 40% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,176204,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mass Polymorph at 30% HP');

-- Sand Scavenger
SET @ENTRY := 88076;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,120468,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pinch');

-- Seldy
SET @ENTRY := 85509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,13864,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79822,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,17140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Fire'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,4,0,2,0,100,0,0,40,22000,25000,11,11640,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renew at 40% HP');

-- Sergeant Damarcus
SET @ENTRY := 85280;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,119419,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,17000,22000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,165712,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Aggro'),
(@ENTRY,0,3,0,13,0,100,0,5000,8000,20000,30000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick on Player Spell Cast');

-- Sergeant Schmidt
SET @ENTRY := 86829;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,119419,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,17000,22000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,165712,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Aggro'),
(@ENTRY,0,3,0,13,0,100,0,5000,8000,20000,30000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick on Player Spell Cast');

-- Shani Freezewind <Alliance Captain>
SET @ENTRY := 80485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,162608,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,164067,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,162609,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Lance'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,162610,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard');

-- Sharpclaw Hunter
SET @ENTRY := 83689;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176262,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,176643,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Skulking on Spawn'),
(@ENTRY,0,2,0,9,0,100,0,0,10,15000,25000,11,176502,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spiked Net on Close');

-- Sharpclaw Poison-Shaper
SET @ENTRY := 83694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176515,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Erupting Poison'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,176643,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Skulking on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,176514,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Bolt');

-- Sharptalon Outcast
SET @ENTRY := 85750;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cursed Blood');

-- Soulbrewer Nadagast <Horde Captain>
SET @ENTRY := 80489;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,178069,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,178076,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chaos Bolt'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,178072,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howl of Terror at 40% HP');

-- Sporebat Darter
SET @ENTRY := 83720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176848,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spore Spray');

-- Star Root Sniffer
SET @ENTRY := 83754;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176821,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poke');

-- Stone Guard Brokefist <Primal Combatant>
SET @ENTRY := 87774;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,225832,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Nightglow Wisp');

-- Stonehide Riverbeast
SET @ENTRY := 88075;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,167439,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whip Splash');

-- Stonehide Riverbeast
SET @ENTRY := 82310;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,167439,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whip Splash');

-- Stormshield Druid
SET @ENTRY := 81887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,165752,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rejuvenation at 40% HP'),
(@ENTRY,0,3,0,14,0,100,0,800000,40,15000,18000,11,165753,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Regrowth on Friendlies'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,600000,600000,11,165754,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mark of the Wild on Spawn');

-- Stormshield Engineer
SET @ENTRY := 90909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,189278,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Explosive Bomb');

-- Stormshield Field Marshal
SET @ENTRY := 82974;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,173642,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kill Shot'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussive Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,35963,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Improved Wing Clip on Close');

-- Stormshield Footman
SET @ENTRY := 79268;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,176302,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fearsome Battle Standard on Spawn');

-- Stormshield Gladiator
SET @ENTRY := 85812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,119419,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,17000,22000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,165712,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Devotion Aura on Aggro'),
(@ENTRY,0,3,0,13,0,100,0,5000,8000,20000,30000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick on Player Spell Cast');

-- Stormshield Guard
SET @ENTRY := 87657;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Stormshield Guard
SET @ENTRY := 86413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Stormshield Guard
SET @ENTRY := 86408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Stormshield Guard
SET @ENTRY := 88856;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Stormshield Officer
SET @ENTRY := 86436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Stormshield Officer
SET @ENTRY := 86438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Stormshield Officer
SET @ENTRY := 86433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Stormshield Priest
SET @ENTRY := 79947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,136098,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,17139,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,54520,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Penance'),
(@ENTRY,0,3,0,2,0,100,0,0,55,22000,25000,11,176467,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Healing at 55% HP');

-- Stormshield Rock Cutter
SET @ENTRY := 90908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,189287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grind'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,19000,20000,11,189266,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heavy Metal');

-- Stormshield Sentinel
SET @ENTRY := 86767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,173642,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kill Shot'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussive Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,35963,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Improved Wing Clip on Close');

-- Succubus <Nisstyr's Minion>
SET @ENTRY := 83998;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,151384,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kiss of Death');

-- Taylor Dewland <Alliance Captain>
SET @ENTRY := 80500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,178060,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,1,0,0,0,100,0,8000,8900,29000,20000,11,178064,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Hex'),
(@ENTRY,0,2,0,0,0,30,0,4000,5500,12000,15000,11,178091,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,3,0,0,0,100,0,0,0,3400,4700,11,178059,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,4,0,0,0,100,0,5000,8000,25000,37000,11,178063,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Magma Totem');

-- Tina Fang
SET @ENTRY := 86203;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entangling Roots'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79833,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mark of the Wild on Spawn'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,16561,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Regrowth at 40% HP'),
(@ENTRY,0,3,0,14,0,100,0,500000,40,15000,18000,11,12160,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies'),
(@ENTRY,0,4,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath');

-- Titarus
SET @ENTRY := 83713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,169334,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cracked Earth'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,18000,22000,11,169317,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earthspike'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,169346,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ground Smash on Close');

-- Tosan Galaxyfist <Alliance Captain>
SET @ENTRY := 80494;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,164394,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blackout Kick'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,18000,22000,11,127734,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rising Sun Kick');

-- Tower Lookout
SET @ENTRY := 85483;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,80676,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spyglass on Spawn');

-- Unholy Blades <Darth Stormstout's Minion>
SET @ENTRY := 83002;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Valant Brightsworn <Stormshield Paladin Leader>
SET @ENTRY := 82893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Wrath'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,79976,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retribution Aura on Aggro'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Might on Spawn'),
(@ENTRY,0,3,0,9,0,100,0,0,8,15000,25000,11,79970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm on Close'),
(@ENTRY,0,4,0,2,0,100,0,0,60,22000,25000,11,79972,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Truth at 60% HP');

-- Vanguard Samuelle <Horde Captain>
SET @ENTRY := 80492;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Wrath'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,79976,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retribution Aura on Aggro'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Might on Spawn'),
(@ENTRY,0,3,0,9,0,100,0,0,8,15000,25000,11,79970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm on Close'),
(@ENTRY,0,4,0,2,0,100,0,0,60,22000,25000,11,162760,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Judgment at 60% HP');

-- Vilewing Rylak
SET @ENTRY := 84644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,163332,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pyre Breath');

-- Volo Morin <Warspear Rogue Leader>
SET @ENTRY := 86201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,79863,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hemorrhage'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,79862,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3500,4100,11,79866,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Throw'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,79864,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP');

-- Warspear Bruiser
SET @ENTRY := 88073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Warspear Druid
SET @ENTRY := 88780;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Faerie Fire');

-- Warspear Engineer
SET @ENTRY := 90498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,189278,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Explosive Bomb');

-- Warspear Gladiator
SET @ENTRY := 85811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Warspear Headhunter
SET @ENTRY := 88691;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,173642,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kill Shot'),
(@ENTRY,0,1,0,0,0,100,0,4000,5500,12000,15000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Concussive Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,35963,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Improved Wing Clip on Close');

-- Warspear Lieutenant
SET @ENTRY := 86478;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Warspear Priest
SET @ENTRY := 79982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,136098,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,17139,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Shield at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,54520,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Penance'),
(@ENTRY,0,3,0,2,0,100,0,0,55,22000,25000,11,176467,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Prayer of Healing at 55% HP');

-- Warspear Shadow Hunter
SET @ENTRY := 86655;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Warspear Shredder
SET @ENTRY := 90499;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,189265,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shred'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,18000,22000,11,189266,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Heavy Metal');

-- Web-wrapped Soldier
SET @ENTRY := 84196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,168355,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Web Wrapped on Spawn');

-- Wild Goreger
SET @ENTRY := 83719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,176735,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gore');

-- Wolf Rider <Warspear Wolf Riders>
SET @ENTRY := 83895;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close');

-- Wyrmple
SET @ENTRY := 91921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5500,12000,15000,11,189264,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Massive Inhalation'),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,19000,22000,11,189255,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Necrotic Spittle'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,189259,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sweeping Flail on Close');

-- Zaram Sunraiser <Portal Guardian>
SET @ENTRY := 84468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79854,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79857,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,2,0,0,0,100,0,4000,5500,12000,15000,11,79856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');