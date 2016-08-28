--
SET @CGUID := 87945; -- 15 required
SET @OGUID := 64102; -- 15 required

-- Set Earthen Ring Elder ID: 26221 friendly to both factions
UPDATE `creature_template` SET `faction`=35 WHERE `entry`=26221;
DELETE FROM `creature_queststarter` WHERE `id` IN (26221,25975,25324);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+14;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGUID, 25866, 1, 1, 1, 0, 0, 3886.6, 771.658, 5.00204, 3.78625, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+1, 25866, 1, 1, 1, 0, 0, 3873.34, 786.567, 3.15877, 1.19364, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+2, 25866, 1, 1, 1, 0, 0, 3886.25, 820.325, 1.23753, 1.74656, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+3, 25866, 1, 1, 1, 0, 0, 3922.2, 795.453, 9.05771, 3.07546, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+4, 25863, 1, 1, 1, 0, 0, 3956.09, 767.42, 7.88992, 5.17483, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+5, 25863, 1, 1, 1, 0, 0, 3988.96, 790.529, 6.19678, 0.208762, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+6, 25863, 1, 1, 1, 0, 0, 3899.13, 764.193, 6.01616, 5.62487, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+7, 25863, 1, 1, 1, 0, 0, 3923.53, 840.173, 2.29151, 2.07879, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+8, 25924, 1, 1, 1, 0, 0, 3916.05, 783.268, 9.0577, 0.717698, 300, 0, 0, 44, 0, 0, 0, 0, 0),
(@CGUID+9, 25866, 1, 1, 1, 0, 0, 3900.86, 799.587, 7.80664, 1.37978, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+10, 25866, 1, 1, 1, 0, 0, 3950.07, 846.313, 7.9843, 4.16433, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+11, 25866, 1, 1, 1, 0, 0, 3982.71, 816.306, 8.04045, 4.0481, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+12, 25866, 1, 1, 1, 0, 0, 3918.32, 760.473, 7.77712, 1.94087, 300, 30, 0, 42, 0, 1, 0, 0, 0),
(@CGUID+13, 25863, 1, 1, 1, 0, 0, 3922.62, 811.827, 7.79205, 2.56369, 300, 0, 0, 42, 0, 0, 0, 0, 0),
(@CGUID+14, 25949, 1, 1, 1, 0, 0, 4196.1, 1172.44, 6.68073, 0.688985, 300, 0, 0, 486, 1357, 0, 0, 0, 0);
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID, 187989, 1, 1, 1, 3955.77, 862.105, 0.1785, 3.93579, 0, 0, 0.922187, -0.386745, 300, 0, 1),
(@OGUID+1, 187989, 1, 1, 1, 3880.54, 795.812, 2.67948, 0.589994, 0, 0, 0.290737, 0.956803, 300, 0, 1),
(@OGUID+2, 187989, 1, 1, 1, 3923.8, 748.779, 8.05033, 2.67052, 0, 0, 0.972389, 0.233364, 300, 0, 1),
(@OGUID+3, 187989, 1, 1, 1, 3959.24, 760.694, 6.12531, 2.76477, 0, 0, 0.982303, 0.1873, 300, 0, 1),
(@OGUID+4, 187989, 1, 1, 1, 3998.39, 815.017, 4.22604, 3.56744, 0, 0, 0.977417, -0.21132, 300, 0, 1),
(@OGUID+5, 187989, 1, 1, 1, 3953.32, 808.406, 9.07383, 0.295474, 0, 0, 0.1472, 0.989107, 300, 0, 1),
(@OGUID+6, 187989, 1, 1, 1, 3944.4, 817.924, 9.05937, 2.23541, 0, 0, 0.899098, 0.437748, 300, 0, 1),
(@OGUID+7, 187918, 1, 1, 1, 3891.73, 795.127, 7.70466, 3.57844, 0, 0, 0.97624, -0.216691, 300, 0, 1),
(@OGUID+8, 187918, 1, 1, 1, 3928.2, 818.467, 8.38597, 0.711076, 0, 0, 0.348095, 0.937459, 300, 0, 1),
(@OGUID+9, 187918, 1, 1, 1, 3956.23, 854.015, 7.9829, 1.18232, 0, 0, 0.557323, 0.830296, 300, 0, 1),
(@OGUID+10, 187918, 1, 1, 1, 3988.24, 819.46, 8.01849, 5.47452, 0, 0, 0.393407, -0.919365, 300, 0, 1),
(@OGUID+11, 187918, 1, 1, 1, 3923.81, 758.498, 7.77727, 4.57321, 0, 0, 0.754564, -0.656226, 300, 0, 1),
(@OGUID+12, 187918, 1, 1, 1, 3947.51, 812.939, 9.06439, 0.920322, 0, 0, 0.444092, 0.895981, 300, 0, 1),
(@OGUID+13, 187989, 1, 1, 1, 3924.28, 779.525, 9.05821, 2.43535, 0, 0, 0.938298, 0.345828, 300, 0, 1),
(@OGUID+14, 187989, 1, 1, 1, 3912.78, 792.797, 9.05821, 2.43771, 0, 0, 0.938704, 0.344723, 300, 0, 1);
-- SAI and loot for Twilight Firesworn, Twilight Flameguard and Twilight Speaker Viktor
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (25863,25924,25866);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25863,0,0,0,0,0,100,0,0,1000,7000,7500,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,'Firesworn - IC - Cast spell Fireball on victim'),
(25863,0,1,0,4,0,100,0,0,0,0,0,11,184,0,0,0,0,0,1,0,0,0,0,0,0,0,'Firesworn - On aggro - Cast fire shield on self'),
(25863,0,2,0,4,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Firesworn - On aggro - Say Text 0'),
(25924,0,0,0,0,0,100,0,0,1000,7000,7500,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,'Speaker Viktor - IC - Cast spell Fireball on victim'),
(25924,0,1,0,4,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Speaker Viktor - On aggro - Say Text 0'),
(25866,0,0,0,4,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Flameguard - On aggro - Say Text 0');
UPDATE `creature_template` SET `lootid`=25866,`AIName`= 'SmartAI' WHERE `entry`=25866;
UPDATE `creature_template` SET `lootid`=25863,`unit_class`=8,`AIName`= 'SmartAI' WHERE `entry`=25863;
UPDATE `creature_template` SET `AIName`= 'SmartAI',`lootid` =25924,`unit_class`=8 WHERE `entry`=25924;
DELETE FROM `creature_loot_template` WHERE `entry`IN (25866,25863,25924);
INSERT INTO `creature_loot_template` VALUES
(25866,35277,0,100,1,1,0,1,1,'Twilight Correspondence'),
(25863,35277,0,100,1,1,0,1,1,'Twilight Correspondence'),
(25924,35277,0,100,1,1,0,1,1,'Twilight Correspondence');
-- Add SAI for quest "Unusual activity"
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (26534,25324);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (26534,25324);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26534,0,0,0,1,0,100,1,6000,10000,0,0,12,25324,3,60000,0,0,0,23,0,0,0,0,0,0,0,'Totem - On event update - Summon guide'),
(25324,0,0,0,54,0,100,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Earthen ring Guide - On just summonned - Follow Totem'),
(25324,0,1,0,64,0,100,0,0,0,0,0,1,0,1500,0,0,0,0,1,0,0,0,0,0,0,0,'Earthen ring Guide - On gossip hello - Say text 0');
-- Earthen Ring Guide text
DELETE FROM `creature_text` WHERE `entry` IN (25324,25863,25924,25866);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(25324,0,1,'What is it you need?',12,0,100,1,1500,0,'Earthen ring guide',25739),
(25324,0,2,'Have you discovered something?',12,0,100,1,1500,0,'Earthen ring guide',25740),
(25324,0,3,'The elemental spirits are restless...',12,0,100,1,1500,0,'Earthen ring guide',25741),
(25863,0,0,'You are not allowed to interfere!',12,0,100,1,1500,0,'Twilight Firesworn',25098),
(25924,0,0,'Our vision will be realized!',12,0,100,1,1500,0,'Twilight Speaker Viktor',25099),
(25866,0,0,'The elements will crush you!',12,0,100,1,1500,0,'Twilight Speaker Viktor',25100);
-- SAI for Briatha
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25949;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=25949;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=2594900;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25949,0,0,0,10,0,100,0,1,20,40000,40000,80,2594900,2,0,0,0,0,1,0,0,0,0,0,0,0,'Briatha - OOC LOS - Call Timed ActionList'),
(2594900,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Briatha - Action list - Talk0'),
(2594900,9,1,0,0,0,100,0,6000,6000,0,0,1,0,4000,0,0,0,0,9,25951,0,15,0,0,0,0,'Emissary - Action list - Say text 0'),
(2594900,9,2,0,0,0,100,0,6000,6000,0,0,1,1,4000,0,0,0,0,1,0,0,0,0,0,0,0,'Briatha - Action list - Say text 1'),
(2594900,9,3,0,0,0,100,0,6000,6000,0,0,1,1,4000,0,0,0,0,9,25951,0,15,0,0,0,0,'Emissary - Action list - Say text 1'),
(2594900,9,4,0,0,0,100,0,6000,6000,0,0,1,2,3500,0,0,0,0,1,0,0,0,0,0,0,0,'Briatha - Action list - Say text 2'),
(2594900,9,5,0,0,0,100,0,0,0,0,0,11,46375,0,0,0,0,0,1,0,0,0,0,0,0,0,'Briatha - Action list - Cast spell quest credit');
-- Briatha and Heretic Emissary text
DELETE FROM `creature_text` WHERE `entry` IN (25949,25951);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(25949,0,0,'These stones should be the last of them. Our coordination with Neptulon''s forces will be impeccable.',12,0,100,1,0,0,'Briatha',25123),
(25949,1,0,'And your own preparations? Will the Frost Lord have a path to the portal?',12,0,100,1,0,0,'Briatha',25126),
(25949,2,0,'The ritual in Coilfang will bring Ahune through once he is fully prepared, and the resulting clash between Firelord and Frostlord will rend the foundations of this world. Our ultimate goals are in reach at last....',12,0,100,1,0,0,'Briatha',25128),
(25951,0,0,'Yess. The Tidehunter will be pleased at this development. The Firelord\'s hold will weaken.',12,0,100,1,0,0,'Heretic Emissary',25124),
(25951,1,0,'Skar\'this has informed us well. We have worked our way into the slave pens and await your cryomancerss.',12,0,100,1,0,0,'Heretic Emissary',25127);

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+14 AND `eventEntry`=1;
INSERT INTO `game_event_creature` SELECT 1, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+14;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14 AND `eventEntry`=1;
INSERT INTO `game_event_gameobject` SELECT 1, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+14;
