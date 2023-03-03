UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 276790;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `guid` = 276791;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` = 6781;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` = 10606;
UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` = 2852;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` = 1995;

UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 1995;
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 1997;

-- Ancient Teldrassil Protector
SET @ENTRY := 34530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,62245,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Boulder'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,65843,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shockwave');

-- Ally of Nature
SET @ENTRY := 34517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,65837,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vine Lash'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2500,3000,11,34745,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot Thorns'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,16000,20000,11,65605,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bursting Seed');

-- Gnarlpine Warrior
SET @ENTRY := 2008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,12000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close');
UPDATE `creature_template` SET `minlevel` = 120, `maxlevel` = 120 WHERE `entry` = 3469;
UPDATE `creature_template` SET `minlevel` = 120, `maxlevel` = 120 WHERE `entry` = 2041;
UPDATE `creature_template` SET `minlevel` = 120, `maxlevel` = 120 WHERE `entry` = 4262;
-- Ferocitas the Dream Eater
SET @ENTRY := 7234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,78921,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dream Lash');

replace  into `npc_trainer`(`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`,`Index`) values 
(3602,8936,0,798,0,5,0),
(3602,106830,0,798,0,5,0),
(3602,5221,0,798,0,5,0),
(3602,33917,0,798,0,8,0),
(3602,22568,0,798,0,7,0),
(3603,136197,100000,171,500,0,0),
(3603,114786,20000,171,300,0,0),
(3603,114752,200000,171,500,0,0),
(3603,114751,200000,171,500,0,0),
(3603,105206,600000,171,500,0,0),
(3603,96254,100000,171,500,0,0),
(3603,96253,100000,171,500,0,0),
(3603,96252,100000,171,500,0,0),
(3603,94162,200000,171,500,0,0),
(3603,93935,150000,171,425,0,0),
(3603,80731,500000,171,425,0,0),
(3603,80726,250000,171,525,0,0),
(3603,80725,250000,171,525,0,0),
(3603,80723,200000,171,510,0,0),
(3603,80721,200000,171,510,0,0),
(3603,80720,200000,171,505,0,0),
(3603,80719,200000,171,500,0,0),
(3603,80508,100000,171,500,0,0),
(3603,80498,175000,171,495,0,0),
(3603,80497,175000,171,495,0,0),
(3603,80496,175000,171,490,0,0),
(3603,80495,175000,171,485,0,0),
(3603,80494,175000,171,485,0,0),
(3603,80493,175000,171,490,0,0),
(3603,80492,175000,171,480,0,0),
(3603,80491,175000,171,480,0,0),
(3603,80490,160000,171,475,0,0),
(3603,80488,160000,171,475,0,0),
(3603,80487,160000,171,470,0,0),
(3603,80486,160000,171,470,0,0),
(3603,80484,160000,171,465,0,0),
(3603,80482,160000,171,465,0,0),
(3603,80481,160000,171,460,0,0),
(3603,80480,150000,171,455,0,0),
(3603,80479,150000,171,455,0,0),
(3603,80478,150000,171,450,0,0),
(3603,80477,150000,171,450,0,0),
(3603,80269,160000,171,460,0,0),
(3603,80251,200000,171,505,45,0),
(3603,80250,200000,171,510,45,0),
(3603,80248,200000,171,515,45,0),
(3603,80247,200000,171,520,45,0),
(3603,80246,200000,171,515,45,0),
(3603,80245,250000,171,525,45,0),
(3603,80244,200000,171,520,45,0),
(3603,80243,250000,171,525,45,0),
(3603,80237,250000,171,525,45,0),
(3603,78866,175000,171,485,45,0),
(3603,66664,200000,171,450,45,0),
(3603,66663,200000,171,450,45,0),
(3603,66662,200000,171,450,45,0),
(3603,66660,200000,171,450,45,0),
(3603,66658,200000,171,450,45,0),
(3603,63732,2000,171,135,0,0),
(3603,62409,60000,171,375,0,0),
(3603,60893,200000,171,400,0,0),
(3603,60405,200000,171,400,0,0),
(3603,60403,200000,171,400,0,0),
(3603,60396,200000,171,400,0,0),
(3603,60367,120000,171,395,0,0),
(3603,60350,150000,171,395,45,0),
(3603,58871,150000,171,410,0,0),
(3603,58868,150000,171,410,0,0),
(3603,57427,150000,171,425,45,0),
(3603,57425,150000,171,430,45,0),
(3603,54218,120000,171,385,0,0),
(3603,54213,150000,171,435,0,0),
(3603,53905,120000,171,395,0,0),
(3603,53903,180000,171,435,0,0),
(3603,53902,150000,171,435,0,0),
(3603,53901,180000,171,435,0,0),
(3603,53900,120000,171,380,0,0),
(3603,53899,60000,171,375,0,0),
(3603,53898,120000,171,390,0,0),
(3603,53848,60000,171,375,0,0),
(3603,53847,65000,171,385,0,0),
(3603,53842,40000,171,365,0,0),
(3603,53841,40000,171,355,0,0),
(3603,53840,120000,171,395,0,0),
(3603,53839,40000,171,360,0,0),
(3603,53838,40000,171,350,0,0),
(3603,53837,150000,171,410,0,0),
(3603,53836,150000,171,405,0,0),
(3603,53812,60000,171,375,0,0),
(3603,51304,350000,171,350,0,0),
(3603,45061,35000,171,325,0,0),
(3603,39638,30000,171,320,0,0),
(3603,39636,25000,171,310,0,0),
(3603,38070,20000,171,325,0,0),
(3603,33741,30000,171,315,0,0),
(3603,33740,20000,171,300,0,0),
(3603,33738,20000,171,300,0,0),
(3603,33733,25000,171,310,0,0),
(3603,33732,20000,171,300,0,0),
(3603,28596,100000,171,275,0,0),
(3603,28551,50000,171,325,0,0),
(3603,28545,25000,171,310,0,0),
(3603,28544,25000,171,305,0,0),
(3603,22808,10000,171,215,0,0),
(3603,17573,20000,171,285,0,0),
(3603,17572,20000,171,285,0,0),
(3603,17557,20000,171,275,0,0),
(3603,17556,20000,171,275,0,0),
(3603,17555,15000,171,270,0,0),
(3603,17553,15000,171,260,0,0),
(3603,17552,15000,171,255,0,0),
(3603,17551,15000,171,250,0,0),
(3603,15833,10000,171,230,0,0),
(3603,12609,8000,171,200,0,0),
(3603,11611,50000,171,200,0,0),
(3603,11478,14000,171,250,0,0),
(3603,11467,12000,171,240,0,0),
(3603,11465,12000,171,235,0,0),
(3603,11461,10000,171,235,0,0),
(3603,11460,5000,171,230,0,0),
(3603,11457,10000,171,215,0,0),
(3603,11451,8000,171,205,0,0),
(3603,11450,7500,171,195,0,0),
(3603,11449,6500,171,185,0,0),
(3603,11448,9000,171,205,0,0),
(3603,7845,3000,171,140,0,0),
(3603,7841,1000,171,100,0,0),
(3603,7837,1000,171,130,0,0),
(3603,7836,250,171,80,0,0),
(3603,7181,5000,171,155,0,0),
(3603,7179,450,171,90,0,0),
(3603,3464,5000,171,125,0,0),
(3603,3452,5000,171,160,0,0),
(3603,3450,6000,171,175,0,0),
(3603,3449,5000,171,165,0,0),
(3603,3448,5000,171,165,0,0),
(3603,3447,4000,171,110,0,0),
(3603,3177,2000,171,130,0,0),
(3603,3176,1500,171,125,0,0),
(3603,3173,1500,171,120,0,0),
(3603,3171,500,171,90,0,0),
(3603,3170,50,171,15,0,0),
(3603,3101,500,171,50,0,0),
(3603,2337,1000,171,55,0,0),
(3603,2334,250,171,50,0,0),
(3603,2332,150,171,40,0,0),
(3603,2331,100,171,25,0,0),
(3604,110413,600000,182,500,0,0),
(3604,74519,500000,182,425,0,0),
(3604,50300,350000,182,350,0,0),
(3604,28695,100000,182,275,0,0),
(3604,11993,50000,182,200,0,0),
(3604,3570,5000,182,125,0,0),
(3604,2368,500,182,50,0,0),
(3604,2366,10,182,0,0,0),
(3603,2259,10,171,0,0,0);
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 14432;
-- Webwood Venomfang
SET @ENTRY := 1999;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,11918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison');

-- Gnarlpine Shaman
SET @ENTRY := 2009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,11986,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 40% HP'),
(@ENTRY,0,2,0,14,0,100,0,50,40,15000,18000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Wave on Friendlies'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Sentinel Huntress
SET @ENTRY := 34249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,5000,8000,11,66032,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,66031,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bandage at 40% HP');
UPDATE `creature_template` SET `minlevel` = 10, `maxlevel` = 10 WHERE `entry` = 34249;