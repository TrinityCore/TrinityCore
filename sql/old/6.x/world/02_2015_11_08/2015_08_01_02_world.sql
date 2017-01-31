-- DB/Quest: Orgrimmar - Blown Away (H)
-- Ballonspawns
SET @OGUID := 44;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 209058, 1, 1,1503.991, -4375.202, 23.263, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+1, 209058, 1, 1,1528.073, -4441.75, 24.02341, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+2, 209058, 1, 1,1530.462, -4374.63, 18.83806, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+3, 209058, 1, 1,1515.497, -4439.116, 23.48083, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+4, 209058, 1, 1,1590.663, -4366.837, 20.93084, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+5, 209058, 1, 1,1602.719, -4435.96, 13.90795, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+6, 209058, 1, 1,1629.444, -4417.929, 15.5577, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+7, 209058, 1, 1,1539.163, -4334.366, 22.73981, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Strength)
(@OGUID+8, 209058, 1, 1,1726.033, -4441.309, 40.65453, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Strength)
(@OGUID+9, 209058, 1, 1,1726.655, -4498.354, 30.89155, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+10, 209058, 1, 1,1751.536, -4534.128, 30.44205, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+11, 209058, 1, 1,1816.24, -4496.58, 46.47007, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+12, 209058, 1, 1,1872.5, -4464.323, 48.70532, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+13, 209058, 1, 1,1904.172, -4694.141, 36.44628, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Honor)
(@OGUID+14, 209058, 1, 1,1928.13, -4739.939, 36.58462, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Honor)
(@OGUID+15, 209058, 1, 1,2215.036, -4610.439, 85.89728, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: 0)
(@OGUID+16, 209058, 1, 1,1916.698, -4418.78, 46.36224, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+17, 209058, 1, 1,2032.356, -4414.33, 97.91099, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+18, 209058, 1, 1,1910.321, -4378.42, 105.6533, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: The Drag)
(@OGUID+19, 209058, 1, 1,1880.024, -4237.168, 35.96712, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+20, 209058, 1, 1,1989.224, -4206.981, 36.1769, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+21, 209058, 1, 1,2027.594, -4203.146, 105.683, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+22, 209058, 1, 1,1911.71, -4128.022, 109.7363, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Wisdom)
(@OGUID+23, 209058, 1, 1,1552.372, -4206.984, 53.92707, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Valley of Strength)
(@OGUID+24, 209058, 1, 1,1481.854, -4173.207, 52.93541, 0, 0, 0, 0, 1, 120, 255, 1), -- Windswept Balloon (Area: Goblin Slums)
(@OGUID+25, 209058, 1, 1,1770.215, -3952.91, 55.46432, 0, 0, 0, 0, 1, 120, 255, 1); -- Windswept Balloon (Area: Valley of Spirits)

-- questendscript
UPDATE `creature_template` SET `VehicleId`=1700, `flags_extra`=128 WHERE  `entry`=54066;
UPDATE `creature_template` SET `speed_walk`=0.5, `speed_run`=0.5, `InhabitType`=4 WHERE  `entry` IN (54066, 54068);

DELETE FROM `spell_area` WHERE `spell` IN (100616);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(100616, 5171, 0, 29401, 0, 0, 2, 1, 0, 43);

-- Jaga SAI
SET @ENTRY := 54004;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,29401,0,0,0,12,54066,3,25000,0,0,0,1,0,0,0,0,0,0,0,"Jaga - On Quest 'Blown Away' Finished - Summon Creature 'Balloon Bunny'"),
(@ENTRY,0,1,2,61,0,100,0,29401,0,0,0,12,54067,3,25000,0,0,0,1,0,0,0,0,0,0,0,"Jaga - On Quest 'Blown Away' Finished - Summon Creature 'Jaga'"),
(@ENTRY,0,2,0,61,0,100,0,29401,0,0,0,12,54068,3,25000,0,0,0,1,0,0,0,0,0,0,0,"Jaga - On Quest 'Blown Away' Finished - Summon Creature 'Balloons'");

-- Jaga SAI
SET @ENTRY := 54067;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,19,54066,20,0,0,0,0,0,"Jaga - On Just Summoned - Cast 'Ride Vehicle Hardcoded'"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,5000,5000,1,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Jaga - Out of Combat - Say Line 0");

-- Balloon Bunny SAI
SET @ENTRY := 54066;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1943.51,-4343.42,142.481,5.887,"Balloon Bunny - On Just Summoned - Move To Position"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balloon Bunny - On Just Summoned - Set Run Off");

-- Balloons SAI
SET @ENTRY := 54068;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,1943.51,-4343.42,142.481,5.887,"Balloons - On Just Summoned - Move To Position"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balloons - On Just Summoned - Set Run Off");

DELETE FROM `creature_text` WHERE `entry`=54067;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(54067, 0, 0, 'This is great!', 12, 0, 100, 0, 0, 0, 52697, 'Jaga'),
(54067, 0, 1, 'Thanks, $p! I''ll tell my pa you helped me see the world!', 12, 0, 100, 0, 0, 0, 52696, 'Jaga'),
(54067, 0, 2, 'Wahoo!', 12, 0, 100, 0, 0, 0, 44157, 'Jaga');
