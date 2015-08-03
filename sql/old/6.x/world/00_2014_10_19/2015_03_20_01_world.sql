-- Sungraze Mushan SAI
SET @MUSHAN         := 58893;  -- Sungraze Mushan
SET @SPELL_BLUDGEON := 117586; -- Bludgeon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@MUSHAN;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MUSHAN AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MUSHAN,0,0,0,0,0,100,0,7200,7300,7250,7350,11,@SPELL_BLUDGEON,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sungraze Mushan - In Combat - Bludgeon");

-- Weeping Horror SAI
SET @HORROR        := 57649;  -- Weeping Horror
SET @SPELL_SADNESS := 119556; -- Overwhelming Sadness
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@HORROR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@HORROR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@HORROR,0,0,0,0,0,100,0,7200,8300,7400,8500,11,@SPELL_SADNESS,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weeping Horror - In Combat - Overwhelming Sadness");

-- Dojani Surveyor SAI
SET @SURVEYOR     := 58068; -- Dojani Surveyor
SET @SPELL_SUNDER := 11971; -- Sunder Armor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SURVEYOR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SURVEYOR AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SURVEYOR,0,0,0,0,0,100,0,21800,25400,24300,26700,11,@SPELL_SUNDER,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dojani Surveyor - In Combat - Sunder Armor");

-- Dojani Enforcer SAI
SET @ENFORCER        := 65626;  -- Dojani Enforcer
SET @SPELL_SHOCKWAVE := 129018; -- Shockwave
SET @SPELL_LEAP      := 129017; -- Leap of Victory
SET @SPELL_ENRAGE    := 129016; -- Enrage
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENFORCER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENFORCER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENFORCER,0,0,0,0,0,100,0,21800,21900,21700,23100,11,@SPELL_SHOCKWAVE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dojani Enforcer - In Combat - Shockwave"),
(@ENFORCER,0,1,0,0,0,100,0,13300,14600,14500,15800,11,@SPELL_LEAP,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dojani Enforcer - In Combat - Leap of Victory"),
(@ENFORCER,0,2,0,0,0,100,0,12400,16700,16500,21800,11,@SPELL_ENRAGE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dojani Enforcer - In Combat - Enrage");

-- Mortbreath Snapper SAI
SET @SNAPPER         := 60201; -- Mortbreath Snapper
SET @SPELL_CHARGE    := 87930; -- Charge
SET @SPELL_JAW_SNAP  := 118990; -- Jaw Snap
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SNAPPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SNAPPER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SNAPPER,0,0,0,9,0,100,0,5,40,1000,1500,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mortbreath Snapper - Within 5-40 Range - Charge"),
(@SNAPPER,0,1,0,0,0,100,0,12000,12900,12500,13400,11,@SPELL_JAW_SNAP,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mortbreath Snapper - In Combat - Jaw Snap");

-- Mortbreath Skulker SAI
SET @SKULKER         := 60202; -- Mortbreath Skulker
SET @SPELL_CHARGE    := 87930; -- Charge
SET @SPELL_JAW_SNAP  := 118990; -- Jaw Snap
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@SKULKER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SKULKER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SKULKER,0,0,0,9,0,100,0,5,40,1000,1500,11,@SPELL_CHARGE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mortbreath Skulker - Within 5-40 Range - Charge"),
(@SKULKER,0,1,0,0,0,100,0,12000,12900,12500,13400,11,@SPELL_JAW_SNAP,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mortbreath Skulker - In Combat - Jaw Snap");

-- Enraged Blacksmith SAI
SET @BLACKSMITH := 61130;
SET @FURIOUS    := 121445;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@BLACKSMITH;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@BLACKSMITH AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@BLACKSMITH,0,0,0,0,0,100,0,4900,14400,12500,21700,11,@FURIOUS,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Blacksmith - In Combat - Cast Furious Blow");

-- Sha-Infested Prowler SAI
SET @PROWLER  := 66668;
SET @FEROCIOUS := 115083;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@PROWLER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PROWLER AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@PROWLER,0,0,0,0,0,100,0,5000,15000,10000,20000,11,@FEROCIOUS,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sha-Infested Prowler - In Combat - Ferocious Claw");

-- Lupello SAI
SET @LUPELLO    := 56357;
SET @SPELL_PREY := 129496;
SET @SPELL_HOWL := 129502;
SET @SPELL_POUNCED := 129497;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@LUPELLO;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LUPELLO AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@LUPELLO,0,0,0,9,0,100,0,5,40,1700,3800,11,@SPELL_PREY,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lupello - Within 5-40 Range - Cast 'Prey Pounce'"),
(@LUPELLO,0,1,0,0,0,100,0,10000,10500,10500,15500,11,@SPELL_HOWL,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lupello - In Combat - Cast 'Fearsome Howl'"),
(@LUPELLO,0,2,0,0,0,100,0,5000,10000,10000,15000,11,@SPELL_POUNCED,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lupello - In Combat - Cast 'Pounced'");

-- Ice Fury SAI
SET @ICEFURY       := 78214;  -- Ice Fury
SET @SPELL_ICYGUST := 165416; -- Icy Gust
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ICEFURY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ICEFURY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ICEFURY,0,0,0,0,0,100,0,10900,13400,12200,14700,11,@SPELL_ICYGUST,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Fury - In Combat - Cast Icy Gust");

-- Thunderlord War-Gronn SAI
SET @THUNDERLORD := 74448;  -- Thunderlord War-Gronn
SET @SPELL_SMASH := 149864; -- Smash
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@THUNDERLORD;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@THUNDERLORD AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@THUNDERLORD,0,0,0,0,0,100,0,5100,6100,5200,6200,11,@SPELL_SMASH,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderlord War-Gronn - In Combat - Cast Smash");
