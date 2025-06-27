-- Eck the Ferocious
UPDATE `creature_template` SET `minlevel` = 82, `unit_flags` = 32832 WHERE `entry` = 29932;

-- Drakkari Inciter SAI
-- He seems to control sparring between two Drakkari Earthshaker, even his faction name tells that (Monster Referee)
-- He uses emote Point (25) and after that two earthshakers changes their faction and starts to fight
SET @ID := 29874;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,0,0,6000,10000,0,10,5,11,15,23,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Inciter - Out of Combat - Play Random Emote"),
(@ID,0,1,0,0,0,100,2,5000,5000,10000,10000,0,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Drakkari Inciter - In Combat - Cast 'Strike' (Normal Dungeon)"),
(@ID,0,2,0,0,0,100,4,5000,5000,10000,10000,0,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Drakkari Inciter - In Combat - Cast 'Strike' (Heroic Dungeon)");

-- Drakkari Golem SAI (Shockwave & Body of Stone repeat timers guessed)
SET @ID := 29832;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,10000,14000,12000,17000,0,11,55635,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast 'Thunderclap' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,10000,14000,12000,17000,0,11,58975,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast 'Thunderclap' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,15000,25000,20000,25000,0,11,55636,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast 'Shockwave' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,15000,25000,20000,25000,0,11,58977,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast 'Shockwave' (Heroic Dungeon)"),
(@ID,0,4,0,0,0,100,0,15000,30000,30000,40000,0,11,55633,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Golem - In Combat - Cast 'Body of Stone'");

-- Drakkari Frenzy SAI
SET @ID := 29834;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,0,7000,25000,17000,26000,0,11,55518,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Frenzy - Out of Combat - Cast 'Leap'");

-- Drakkari Rhino SAI
UPDATE `smart_scripts` SET `event_param1` = 10000, `event_param2` = 10000, `event_param3` = 10000, `event_param4` = 10000 WHERE `entryorguid` IN (29838,29931) AND `source_type` = 0 AND `action_param1` IN (55663,58992);

-- Drakkari Raider SAI
SET @ID := 29982;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,0,12000,12000,10000,15000,0,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Drakkari Raider - In Combat - Cast 'Cleave'");

-- Drakkari Battle Rider SAI
SET @ID := 29836;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,0,0,2500,2500,0,11,55348,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat CMC - Cast 'Throw' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,0,0,2500,2500,0,11,58966,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat CMC - Cast 'Throw' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,15000,15000,10000,15000,0,11,55521,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat - Cast 'Poisoned Spear' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,15000,15000,10000,15000,0,11,58967,32,0,0,0,0,5,0,0,0,0,0,0,0,0,"Drakkari Battle Rider - In Combat - Cast 'Poisoned Spear' (Heroic Dungeon)");

-- Spitting Cobra SAI
SET @ID := 29774;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,8000,13000,10000,10000,0,11,55700,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Spitting Cobra - In Combat - Cast 'Venom Spit' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,8000,13000,10000,10000,0,11,59019,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Spitting Cobra - In Combat - Cast 'Venom Spit' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,11000,17000,15000,15000,0,11,55703,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Spitting Cobra - In Combat - Cast 'Cobra Strike' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,11000,17000,15000,15000,0,11,59020,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Spitting Cobra - In Combat - Cast 'Cobra Strike' (Heroic Dungeon)");

-- Unyielding Constrictor SAI
SET @ID := 29768;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,0,0,100,2,6000,9000,6000,11000,0,11,55602,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Unyielding Constrictor - In Combat - Cast 'Vicious Bite' (Normal Dungeon)"),
(@ID,0,1,0,0,0,100,4,6000,9000,6000,11000,0,11,59021,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Unyielding Constrictor - In Combat - Cast 'Vicious Bite' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,4000,7000,12000,18000,0,11,55603,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unyielding Constrictor - In Combat - Cast 'Puncturing Strike' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,4000,7000,12000,18000,0,11,59022,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Unyielding Constrictor - In Combat - Cast 'Puncturing Strike' (Heroic Dungeon)");

-- Drakkari Medicine Man SAI
SET @ID := 29826;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,1,0,100,2,1000,1000,30000,30000,0,11,55599,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - Out of Combat - Cast 'Earth Shield' (Normal Dungeon)"),
(@ID,0,1,0,1,0,100,4,1000,1000,30000,30000,0,11,58981,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - Out of Combat - Cast 'Earth Shield' (Heroic Dungeon)"),
(@ID,0,2,0,0,0,100,2,5000,7000,5000,7000,0,11,55599,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - In Combat - Cast 'Earth Shield' (Normal Dungeon)"),
(@ID,0,3,0,0,0,100,4,5000,7000,5000,7000,0,11,58981,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - In Combat - Cast 'Earth Shield' (Heroic Dungeon)"),
(@ID,0,4,0,74,0,100,2,0,40,14000,21000,40,11,55597,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - On Friendly Between 0-40% Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ID,0,5,0,74,0,100,4,0,40,14000,21000,40,11,58980,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - On Friendly Between 0-40% Health - Cast 'Healing Wave' (Heroic Dungeon)"),
(@ID,0,6,0,0,0,100,0,5000,8000,35000,45000,0,11,55582,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - In Combat - Cast 'Mana Link'"),
(@ID,0,7,0,0,0,100,0,12000,15000,12000,15000,0,11,55598,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drakkari Medicine Man - In Combat - Cast 'Cleanse Magic'");

-- Waypoints & formations for remaining creatures(excluding troll patrol in Cave of Mam'toth)
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (127014,127017,127023,127045);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(127014,127014,0,0,515,0,0),
(127014,127025,4,45,515,0,0),
(127014,127015,4,315,515,0,0),
(127017,127017,0,0,515,0,0),
(127017,127028,4,45,515,0,0),
(127017,127029,4,315,515,0,0),
(127023,127023,0,0,515,0,0),
(127023,127013,4,45,515,0,0),
(127023,127024,4,315,515,0,0),
(127045,127045,0,0,515,0,0),
(127045,127058,4,90,515,0,0);

DELETE FROM `waypoint_data` WHERE `id` IN (1270140,1270170,1270230,1270450);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(1270140,1,1783.4556,642.5727,124.49611),
(1270140,2,1786.3921,633.477,124.41425),
(1270140,3,1786.7518,623.6088,124.471115),
(1270140,4,1783.6442,616.3062,124.46875),
(1270140,5,1777.3759,607.6776,124.471756),
(1270140,6,1783.6442,616.3062,124.46875),
(1270140,7,1786.7518,623.6088,124.471115),
(1270140,8,1786.3921,633.477,124.41425),
(1270170,1,1766.6785,622.4259,124.46349),
(1270170,2,1764.4736,632.4841,124.0932),
(1270170,3,1768.57,640.7814,124.12474),
(1270170,4,1775.5234,649.30597,124.418434),
(1270170,5,1768.57,640.7814,124.12474),
(1270170,6,1764.4736,632.4841,124.0932),
(1270170,7,1766.6785,622.4259,124.46349),
(1270170,8,1767.7429,617.1144,124.70322),
(1270170,9,1773.4012,609.8914,124.45856),
(1270170,10,1767.7429,617.1144,124.70322),
(1270170,11,1766.6785,622.4259,124.46349),
(1270230,1,1639.5278,641.6166,125.37939),
(1270230,2,1645.098,633.3488,125.77433),
(1270230,3,1651.6385,628.7528,127.47812),
(1270230,4,1660.0083,623.5324,127.12056),
(1270230,5,1668.0419,624.53064,126.9709),
(1270230,6,1672.9036,628.22327,126.99458),
(1270230,7,1676.1814,637.1957,125.96748),
(1270230,8,1673.1793,645.9787,125.92528),
(1270230,9,1666.6741,651.5946,125.74996),
(1270230,10,1659.19,656.0175,125.16064),
(1270230,11,1650.649,657.3392,125.201836),
(1270230,12,1643.7992,655.79877,124.81762),
(1270230,13,1639.2317,648.5116,124.861984),
(1270450,1,1649.7554,645.5167,128.46371),
(1270450,2,1659.3977,636.32556,130.3013),
(1270450,3,1676.1699,633.8402,126.16728),
(1270450,4,1694.8239,633.5077,128.58441),
(1270450,5,1676.1699,633.8402,126.16728),
(1270450,6,1659.3977,636.32556,130.3013),
(1270450,7,1649.8481,645.42706,128.47978),
(1270450,8,1637.9829,656.9024,124.11612),
(1270450,9,1630.769,666.7845,130.88843),
(1270450,10,1630.2743,679.61444,136.12999),
(1270450,11,1630.769,666.7845,130.88843),
(1270450,12,1637.9829,656.9024,124.11612);

-- Spitting Cobra & Unyielding Constrictor
UPDATE `creature` SET `wander_distance` = 5, `MovementType` = 1 WHERE `guid` IN (127009,127010,127018,127022,127021,127012,127020,127019,127007,127008,127006,127011);
-- No movement for members of formation
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `guid` IN (127013,127024);

-- Loaded from templates
UPDATE `creature` SET `modelid` = 0 WHERE `id` IN (29820,29822,29826,29874);
