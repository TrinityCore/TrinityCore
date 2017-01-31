-- "Chesty" Jake <Excavation Supplies & Repairs>
UPDATE `creature_template` SET `gossip_menu_id` = 9848, `exp` = 3, `mindmg` = 967.1, `maxdmg` = 1297.7, `attackpower` = 1530, `rangeattacktime` = 0, `minrangedmg` = 704.9, `maxrangedmg` = 1016.5, `rangedattackpower` = 190 WHERE `entry` = 49409;
DELETE FROM `npc_vendor` WHERE `entry` = 49409;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(49409, 0, 2880, 0, 0, 0),
(49409, 0, 2901, 0, 0, 0),
(49409, 0, 3371, 0, 0, 0),
(49409, 0, 3466, 0, 0, 0),
(49409, 0, 4357, 1, 3600, 0),
(49409, 0, 4361, 2, 3600, 0),
(49409, 0, 4363, 2, 3600, 0),
(49409, 0, 4364, 4, 3600, 0),
(49409, 0, 4371, 2, 3600, 0),
(49409, 0, 4382, 1, 3600, 0),
(49409, 0, 4389, 1, 3600, 0),
(49409, 0, 4399, 0, 0, 0),
(49409, 0, 4400, 0, 0, 0),
(49409, 0, 4404, 3, 10800, 0),
(49409, 0, 5956, 0, 0, 0),
(49409, 0, 6532, 0, 0, 0),
(49409, 0, 10647, 0, 0, 0),
(49409, 0, 10648, 0, 0, 0),
(49409, 0, 14341, 0, 0, 0),
(49409, 0, 38426, 0, 0, 0),
(49409, 0, 39354, 0, 0, 0),
(49409, 0, 39501, 0, 0, 0),
(49409, 0, 39502, 0, 0, 0),
(49409, 0, 39684, 0, 0, 0),
(49409, 0, 40533, 0, 0, 0);
-- Aaron "Sandy Toes" Williamson <Reagents>
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 967.1, `maxdmg` = 1297.7, `attackpower` = 1530, `rangeattacktime` = 0, `minrangedmg` = 704.9, `maxrangedmg` = 1016.5, `rangedattackpower` = 190 WHERE `entry` = 49410;
DELETE FROM `npc_vendor` WHERE `entry` = 49410;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(49410, 0, 17020, 0, 0, 0),
(49410, 0, 17030, 0, 0, 0),
(49410, 0, 17031, 0, 0, 0),
(49410, 0, 17032, 0, 0, 0),
(49410, 0, 17034, 0, 0, 0);
-- Adarrah
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 3, `mindmg` = 927.2, `maxdmg` = 1219.8, `attackpower` = 1486, `baseattacktime` = 2000, `minrangedmg` = 689.7, `maxrangedmg` = 989.9, `rangedattackpower` = 157 WHERE `entry` = 48030;
-- Adarrah
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 3, `mindmg` = 927.2, `maxdmg` = 1219.8, `attackpower` = 1486, `baseattacktime` = 2000, `minrangedmg` = 689.7, `maxrangedmg` = 989.9, `rangedattackpower` = 157 WHERE `entry` = 46781;
-- Adarrah
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 3, `mindmg` = 927.2, `maxdmg` = 1219.8, `attackpower` = 1486, `baseattacktime` = 2000, `minrangedmg` = 689.7, `maxrangedmg` = 989.9, `rangedattackpower` = 157 WHERE `entry` = 47912;
-- Adarrah
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 927.2, `maxdmg` = 1219.8, `attackpower` = 1486, `rangeattacktime` = 0, `minrangedmg` = 689.7, `maxrangedmg` = 989.9, `rangedattackpower` = 157 WHERE `entry` = 48028;
-- Adarrah
UPDATE `creature_template` SET `minlevel` = 82, `maxlevel` = 82, `exp` = 3, `mindmg` = 927.2, `maxdmg` = 1219.8, `attackpower` = 1486, `baseattacktime` = 2000, `minrangedmg` = 689.7, `maxrangedmg` = 989.9, `rangedattackpower` = 157 WHERE `entry` = 46873;
-- Adarrah
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 927.2, `maxdmg` = 1219.8, `attackpower` = 1486, `rangeattacktime` = 0, `minrangedmg` = 689.7, `maxrangedmg` = 989.9, `rangedattackpower` = 157 WHERE `entry` = 47005;
-- Advisor Kathem
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 967.1, `maxdmg` = 1297.7, `attackpower` = 1530, `rangeattacktime` = 0, `minrangedmg` = 704.9, `maxrangedmg` = 1016.5, `rangedattackpower` = 190, `mingold` = 15, `maxgold` = 33, `InhabitType` = 1 WHERE `entry` = 47594;
-- Aggra
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `exp` = 3, `faction_A` = 2167, `faction_H` = 2167, `mindmg` = 619.2, `maxdmg` = 835.2, `attackpower` = 976, `baseattacktime` = 2000, `unit_class` = 2, `minrangedmg` = 466.8, `maxrangedmg` = 654, `rangedattackpower` = 156 WHERE `entry` = 53519;
-- Aggra
UPDATE `creature_template` SET `minlevel` = 85, `maxlevel` = 85, `exp` = 3, `faction_A` = 2167, `faction_H` = 2167, `mindmg` = 619.2, `maxdmg` = 835.2, `attackpower` = 976, `baseattacktime` = 2000, `unit_class` = 2, `minrangedmg` = 466.8, `maxrangedmg` = 654, `rangedattackpower` = 156 WHERE `entry` = 53536;
-- Akma'hat <Dirge of the Eternal Sands>
SET @ENTRY := 50063;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = @SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,9000,9000,22000,22000,11,94946,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Fury of the Sands"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,5000,5000,19500,27300,11,93578,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Sands of Time"),
(@ENTRY,@SOURCETYPE,2,0,9,0,100,0,0,8,15800,18300,11,94968,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Shockwave on Close"),
(@ENTRY,@SOURCETYPE,3,0,2,0,100,1,0,40,0,0,11,93561,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Stone Mantle at 40% HP");
UPDATE `creature_template` SET `minlevel` = 87, `maxlevel` = 87, `exp` = 3, `faction_A` = 14, `faction_H` = 14, `mindmg` = 1111.5, `maxdmg` = 1430.7, `attackpower` = 1613, `dmg_multiplier` = 4.6, `baseattacktime` = 2000, `minrangedmg` = 989.9, `maxrangedmg` = 1174.2, `rangedattackpower` = 225, `lootid` = @ENTRY, `spell1` = 94946, `spell2` = 93561, `spell3` = 93578, `spell4` = 94968, `AIName` = 'SmartAI', `InhabitType` = 1, `mechanic_immune_mask` = 613097436 WHERE `entry` = @ENTRY;
DELETE FROM `creature_loot_template` WHERE `entry` = @ENTRY;
INSERT INTO `creature_loot_template` VALUES 
(@ENTRY, 52365, 2, 1, 0, 1, 1),
(@ENTRY, 52366, 2, 1, 0, 1, 1),
(@ENTRY, 52388, 1.4, 1, 0, 1, 1),
(@ENTRY, 67129, 4, 1, 0, 1, 1),
(@ENTRY, 67130, 4, 1, 0, 1, 1),
(@ENTRY, 67131, 2, 1, 0, 1, 1),
(@ENTRY, 67132, 1.8, 1, 0, 1, 1),
(@ENTRY, 67133, 1.8, 1, 0, 1, 1),
(@ENTRY, 67134, 1.9, 1, 0, 1, 1),
(@ENTRY, 67135, 1.4, 1, 0, 1, 1),
(@ENTRY, 67136, 3, 1, 0, 1, 1),
(@ENTRY, 67137, 1.9, 1, 0, 1, 1),
(@ENTRY, 67138, 4, 1, 0, 1, 1),
(@ENTRY, 67139, 1.2, 1, 0, 1, 1),
(@ENTRY, 67140, 1.6, 1, 0, 1, 1),
(@ENTRY, 67141, 1.4, 1, 0, 1, 1),
(@ENTRY, 67142, 2, 1, 0, 1, 1),
(@ENTRY, 67143, 3, 1, 0, 1, 1),
(@ENTRY, 67144, 1.9, 1, 0, 1, 1),
(@ENTRY, 67145, 0.9, 1, 0, 1, 1),
(@ENTRY, 67146, 1.9, 1, 0, 1, 1),
(@ENTRY, 67147, 3, 1, 0, 1, 1),
(@ENTRY, 67148, 1.8, 1, 0, 1, 1),
(@ENTRY, 67149, 1.9, 1, 0, 1, 1),
(@ENTRY, 67150, 1.9, 1, 0, 1, 1),
(@ENTRY, 67240, 82, 1, 0, 1, 1),
(@ENTRY, 68781, 1.1, 1, 0, 1, 1),
(@ENTRY, 68782, 1.1, 1, 0, 1, 1);
DELETE FROM `creature` WHERE `id` = 50063;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(9, 50063, 1, 1, 1, 0, 0, -10517.6, 69.0821, 12.1969, 1.53465, 7200, 0, 0, 14700, 0, 0, 0, 0, 0);
-- Ambassador Laurent
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 3, `mindmg` = 500.4, `maxdmg` = 698.4, `attackpower` = 730, `baseattacktime` = 2000, `minrangedmg` = 409.2, `maxrangedmg` = 607.2, `rangedattackpower` = 120 WHERE `entry` = 47515;
-- Ambassador Laurent
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 500.4, `maxdmg` = 698.4, `attackpower` = 730, `minrangedmg` = 409.2, `maxrangedmg` = 607.2, `rangedattackpower` = 120 WHERE `entry` = 47176;
-- Amethyst Scarab
SET @ENTRY := 46129;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = @SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Serrated Slash");
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 967.1, `maxdmg` = 1297.7, `attackpower` = 1530, `rangeattacktime` = 0, `minrangedmg` = 704.9, `maxrangedmg` = 1016.5, `rangedattackpower` = 190, `AIName` = 'SmartAI' WHERE `entry` = @ENTRY;
-- Ancestral Guardian
SET @ENTRY := 48518;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = @SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,5000,5000,13500,14200,11,86085,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Mutilate");
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 986.1, `maxdmg` = 1316.7, `attackpower` = 1549, `rangeattacktime` = 0, `minrangedmg` = 729.6, `maxrangedmg` = 1037.4, `rangedattackpower` = 204, `lootid` = @ENTRY, `mingold` = 15, `maxgold` = 33, `AIName` = 'SmartAI', `InhabitType` = 1 WHERE `entry` = @ENTRY;
-- Antechamber Guardian
SET @ENTRY := 39077;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = @SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,9,0,100,0,0,5,15000,15000,11,80380,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Sand Breath on Close"),
(@ENTRY,@SOURCETYPE,1,0,9,0,100,0,0,25,22000,23000,11,73864,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,"Cast Sand Trap on Close"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,3000,3000,18000,18000,11,83567,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Cast Sparkling Sands");
UPDATE `creature_template` SET `minlevel` = 49, `maxlevel` = 49, `faction_A` = 16, `faction_H` = 16, `mindmg` = 157.7, `maxdmg` = 209, `attackpower` = 380, `baseattacktime` = 2000, `minrangedmg` = 108.3, `maxrangedmg` = 159.6, `rangedattackpower` = 25, `mingold` = 15, `maxgold` = 33, `AIName` = 'SmartAI', `InhabitType` = 1 WHERE `entry` = @ENTRY;
-- Arcane Guest Registry
SET @ENTRY := 49528;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = @SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,1,0,1,0,100,0,1000,2000,1000,1500,33,47970,0,0,0,0,0,17,0,20,0,0.0,0.0,0.0,0.0,"Credit");
UPDATE `creature_template` SET `mindmg` = 3.8, `maxdmg` = 3.8, `attackpower` = 46, `minrangedmg` = 1.9, `maxrangedmg` = 1.9, `AIName` = 'SmartAI' WHERE `entry` = 49528;
-- Armadillo
UPDATE `creature_template` SET `exp` = 3, `mindmg` = 967.1, `maxdmg` = 1297.7, `attackpower` = 1530, `rangeattacktime` = 0, `minrangedmg` = 704.9, `maxrangedmg` = 1016.5, `rangedattackpower` = 190, `lootid` = 48239, `skinloot` = 48239, `mingold` = 15, `maxgold` = 33, `InhabitType` = 1 WHERE `entry` = 48239;
DELETE FROM `creature_loot_template` WHERE (`entry`=48239);
INSERT INTO `creature_loot_template` VALUES 
(48239, 52363, 0.05, 1, 0, 1, 1),
(48239, 55312, 0.05, 1, 0, 1, 1),
(48239, 55329, 0.05, 1, 0, 1, 1),
(48239, 55338, 0.05, 1, 0, 1, 1),
(48239, 55339, 0.05, 1, 0, 1, 1),
(48239, 55347, 0.05, 1, 0, 1, 1),
(48239, 55365, 0.05, 1, 0, 1, 1),
(48239, 55366, 0.05, 1, 0, 1, 1),
(48239, 55376, 0.05, 1, 0, 1, 1),
(48239, 55384, 0.05, 1, 0, 1, 1),
(48239, 55393, 0.1, 1, 0, 1, 1),
(48239, 55419, 0.05, 1, 0, 1, 1),
(48239, 55420, 0.05, 1, 0, 1, 1),
(48239, 55421, 0.1, 1, 0, 1, 1),
(48239, 55428, 0.05, 1, 0, 1, 1),
(48239, 55437, 0.1, 1, 0, 1, 1),
(48239, 55438, 0.05, 1, 0, 1, 1),
(48239, 55439, 0.05, 1, 0, 1, 1),
(48239, 55456, 0.1, 1, 0, 1, 1),
(48239, 55464, 0.05, 1, 0, 1, 1),
(48239, 55466, 0.05, 1, 0, 1, 1),
(48239, 55492, 0.1, 1, 0, 1, 1),
(48239, 55493, 0.05, 1, 0, 1, 1),
(48239, 55509, 0.05, 1, 0, 1, 1),
(48239, 55536, 0.05, 1, 0, 1, 1),
(48239, 55538, 0.05, 1, 0, 1, 1),
(48239, 55555, 0.05, 1, 0, 1, 1),
(48239, 55556, 0.05, 1, 0, 1, 1),
(48239, 55564, 0.05, 1, 0, 1, 1),
(48239, 55574, 0.05, 1, 0, 1, 1),
(48239, 55581, 0.05, 1, 0, 1, 1),
(48239, 55583, 0.05, 1, 0, 1, 1),
(48239, 55600, 0.05, 1, 0, 1, 1),
(48239, 55617, 0.05, 1, 0, 1, 1),
(48239, 55626, 0.05, 1, 0, 1, 1),
(48239, 55627, 0.05, 1, 0, 1, 1),
(48239, 55628, 0.1, 1, 0, 1, 1),
(48239, 55635, 0.05, 1, 0, 1, 1),
(48239, 55636, 0.1, 1, 0, 1, 1),
(48239, 55644, 0.05, 1, 0, 1, 1),
(48239, 55654, 0.05, 1, 0, 1, 1),
(48239, 55671, 0.05, 1, 0, 1, 1),
(48239, 55682, 0.1, 1, 0, 1, 1),
(48239, 55691, 0.05, 1, 0, 1, 1),
(48239, 55699, 0.05, 1, 0, 1, 1),
(48239, 55708, 0.1, 1, 0, 1, 1),
(48239, 55716, 0.05, 1, 0, 1, 1),
(48239, 55717, 0.05, 1, 0, 1, 1),
(48239, 55718, 0.05, 1, 0, 1, 1),
(48239, 55726, 0.05, 1, 0, 1, 1),
(48239, 55734, 0.1, 1, 0, 1, 1),
(48239, 55744, 0.1, 1, 0, 1, 1),
(48239, 55745, 0.05, 1, 0, 1, 1),
(48239, 55752, 0.05, 1, 0, 1, 1),
(48239, 55753, 0.05, 1, 0, 1, 1),
(48239, 55754, 0.05, 1, 0, 1, 1),
(48239, 55770, 0.05, 1, 0, 1, 1),
(48239, 55771, 0.05, 1, 0, 1, 1),
(48239, 62065, 0.2, 1, 0, 1, 1),
(48239, 62111, 0.05, 1, 0, 1, 1),
(48239, 62136, 0.05, 1, 0, 1, 1),
(48239, 62518, 81.2, 1, 0, 1, 1),
(48239, 62519, 18.7, 1, 0, 1, 1),
(48239, 63541, -7, 1, 0, 1, 1),
(48239, 66912, 0.05, 1, 0, 1, 1),
(48239, 66987, 0.05, 1, 0, 1, 1),
(48239, 67117, 0.05, 1, 0, 1, 1),
(48239, 67119, 0.05, 1, 0, 1, 1),
(48239, 67539, 0.05, 1, 0, 1, 1);
DELETE FROM `skinning_loot_template` WHERE (`entry`=48239);
INSERT INTO `skinning_loot_template` VALUES 
(48239, 52976, 98.9215, 1, 0, 1, 5),
(48239, 67495, 3, 1, 0, 1, 1);
-- Armagedillo
SET @ENTRY := 50065;
UPDATE `creature_template` SET `minlevel` = 84, `maxlevel` = 84, `exp` = 3, `faction_A` = 14, `faction_H` = 14, `mindmg` = 986.1, `maxdmg` = 1316.7, `attackpower` = 1549, `dmg_multiplier` = 1.5, `baseattacktime` = 2000, `minrangedmg` = 729.6, `maxrangedmg` = 1037.4, `rangedattackpower` = 204, `lootid` = @ENTRY, `skinloot` = @ENTRY, `spell1` = 93592, `spell2` = 93590, `spell3` = 93598, `VehicleId` = 1411, `AIName` = 'SmartAI', `mechanic_immune_mask` = 613097436 WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid` = @ENTRY AND `source_type` = 0);
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 500, 1000, 5000, 15000, 11, 93598, 1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Armagedillo - Spiked Charge'),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 8000, 12000, 9000, 15000, 11, 93592, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Armagedillo - Dillogeddon'),
(@ENTRY, 0, 2, 0, 0, 0, 100, 0, 6000, 8000, 6000, 10000, 11, 93590, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Armagedillo - Flame Breath');
DELETE FROM `creature_loot_template` WHERE (`entry`=50065);
INSERT INTO `creature_loot_template` VALUES 
(50065, 67243, 100, 1, 0, 1, 1);
DELETE FROM `skinning_loot_template` WHERE (`entry`=50065);
INSERT INTO `skinning_loot_template` VALUES 
(50065, 52976, 97.3392, 1, 0, 1, 4),
(50065, 67495, 3, 1, 0, 1, 1);
-- Asaq <Royal Envoy>
-- Asaq
SET @ENTRY := 47930;
SET @SOURCETYPE := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type` = @SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,1,62,0,100,0,@ENTRY,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Asaq - On gossip option select - Close gossip"),
(@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,33,47936,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Asaq - Kill Credit");
DELETE FROM `gossip_menu_option` WHERE `menu_id` = @ENTRY;
INSERT INTO `gossip_menu_option` (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES (@ENTRY, 0, 0, 'The king wishes to be informed about recent Neferset activity.', 1, 1, 0, 0, 0, 0, null);
UPDATE `creature_template` SET `gossip_menu_id` = @ENTRY, `exp` = 3, `mindmg` = 967.1, `maxdmg` = 1297.7, `attackpower` = 1530, `rangeattacktime` = 0, `minrangedmg` = 704.9, `maxrangedmg` = 1016.5, `rangedattackpower` = 190, `mingold` = 3220, `maxgold` = 6046, `AIName` = 'SmartAI' WHERE `entry` = @ENTRY;
-- Aspiring Starlet
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 3, `mindmg` = 500.4, `maxdmg` = 698.4, `attackpower` = 730, `baseattacktime` = 2000, `unit_class` = 2, `minrangedmg` = 409.2, `maxrangedmg` = 607.2, `rangedattackpower` = 120 WHERE `entry` = 47961;
-- Aspiring Starlet
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 3, `mindmg` = 500.4, `maxdmg` = 698.4, `attackpower` = 730, `baseattacktime` = 2000, `unit_class` = 2, `minrangedmg` = 409.2, `maxrangedmg` = 607.2, `rangedattackpower` = 120 WHERE `entry` = 47189;
-- Aspiring Starlet
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 3, `mindmg` = 500.4, `maxdmg` = 698.4, `attackpower` = 730, `baseattacktime` = 2000, `unit_class` = 2, `minrangedmg` = 409.2, `maxrangedmg` = 607.2, `rangedattackpower` = 120, `faction_A` = 1818, `faction_H` = 1818, `mingold` = 15, `maxgold` = 33, `InhabitType` = 1 WHERE `entry` = 47988;
-- Aspiring Starlet
UPDATE `creature_template` SET `minlevel` = 80, `maxlevel` = 80, `exp` = 3, `mindmg` = 500.4, `maxdmg` = 698.4, `attackpower` = 730, `baseattacktime` = 2000, `unit_class` = 2, `minrangedmg` = 409.2, `maxrangedmg` = 607.2, `rangedattackpower` = 120 WHERE `entry` = 47708;
