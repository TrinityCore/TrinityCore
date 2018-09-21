-- Creature Entry''s
SET @PIT_COMMANDER_ENTRY := 18945;
SET @PIT_COMMANDER_GUID := 68001;
SET @DARNASSIAN_ARCHER_ENTRY := 18965;
SET @DARKSPEAR_AXE_THROWER_ENTRY := 18970;
SET @STORMWIND_SOLDIER_ENTRY := 18948;
SET @ORGRIMMAR_GRUNT_ENTRY := 18950;
SET @ORGRIMMAR_SHAMAN_ENTRY := 18972;
SET @JUSTINIUS_THE_HARBINGER_ENTRY := 18966;
SET @MELGROMM_HIGHMOUNTAIN_ENTRY := 18969;
SET @IRONFORGE_PALADIN_ENTRY := 18986;
SET @UNDERCITY_MAGE_ENTRY := 18971;
SET @STORMWIND_MAGE_ENTRY := 18949;
SET @GNOMEREGAN_CONJUROR_ENTRY := 19007;
SET @SILVERMOON_MAGISTER_ENTRY := 19006;
SET @THRALLMAR_GRUNT_ENTRY := 16580;
SET @THRALLMAR_MARKSMAN_ENTRY := 16582;
SET @NETHERGARDE_INFANTRY_ENTRY := 16831;
SET @STORMWIND_INFANTRY_ENTRY := 16864;
SET @WRATH_MASTER_ENTRY := 19005;
SET @INFERNAL_TARGET_HYJAL_ENTRY := 21075;
SET @INFERNAL_RELAY_HELLFIRE_ENTRY := 19215;

-- Pit Commander SAI
UPDATE `creature_template` SET `AIName`="SmartAI", `mechanic_immune_mask`=650854271 WHERE `entry`=@PIT_COMMANDER_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@PIT_COMMANDER_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@PIT_COMMANDER_ENTRY,0,0,2,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - On Respawn - Set Active"),
(@PIT_COMMANDER_ENTRY,0,1,0,36,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - On Corpse Removed - Set Active"),
(@PIT_COMMANDER_ENTRY,0,2,3,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - On Respawn - Set Event Phase 0"),
(@PIT_COMMANDER_ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,51347,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - On Respawn - Cast Teleport Visual Only"),
(@PIT_COMMANDER_ENTRY,0,4,0,61,0,100,0,0,0,0,0,67,1,4000,4000,0,0,100,1,0,0,0,0,0,0,0,"Pit Commander - On Respawn - Create Timed Event"),
(@PIT_COMMANDER_ENTRY,0,5,0,59,0,100,0,1,0,0,0,53,0,@PIT_COMMANDER_ENTRY,0,0,0,2,1,0,0,0,0,0,0,0,"Pit Commander - On Timed Event - Start WP"),
(@PIT_COMMANDER_ENTRY,0,6,7,40,0,100,0,43,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - On WP Reached - Set Event Phase"),
(@PIT_COMMANDER_ENTRY,0,7,0,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - On WP Reached - Set Home pos"),
(@PIT_COMMANDER_ENTRY,0,8,0,6,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - On Death - Despawn"),
(@PIT_COMMANDER_ENTRY,0,9,0,0,0,100,0,3000,7000,7000,11000,11,16044,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pit Commander - In Combat - Cast Cleave"),
(@PIT_COMMANDER_ENTRY,0,10,0,0,0,100,0,12000,19000,21000,31000,11,33627,0,0,0,0,0,5,0,0,0,0,0,0,0,"Pit Commander - In Combat - Cast Rain of Fire"),
(@PIT_COMMANDER_ENTRY,0,11,0,1,1,100,0,6000,6000,60000,60000,11,33393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pit Commander - Out of Combat - Cast Summon Infernals"),
(@PIT_COMMANDER_ENTRY,0,12,0,1,1,100,0,6000,6000,60000,60000,45,1,0,0,0,0,0,10,74081,21075,0,0,0,0,0,"Pit Commander - Out of Combat - Set Data"),
(@PIT_COMMANDER_ENTRY,0,13,0,1,1,100,0,7000,7000,60000,60000,45,1,0,0,0,0,0,10,74082,21075,0,0,0,0,0,"Pit Commander - Out of Combat - Set Data");

-- Waypoints 
DELETE FROM `waypoints` WHERE `entry`=@PIT_COMMANDER_ENTRY;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@PIT_COMMANDER_ENTRY, 1, -404.629, 1820.85, 73.209, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 2, -382.802, 1816.85, 74.3855, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 3, -359.458, 1815.56, 76.3872, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 4, -335.046, 1814.74, 78.3202, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 5, -315.229, 1821.68, 83.0968, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 6, -293.231, 1829.2, 87.2354, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 7, -275.158, 1833.68, 89.3406, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 8, -258.02, 1837.22, 92.2399, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 9, -246.41, 1838.59, 93.0124, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 10, -240.571, 1837.9, 92.4368, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 11, -236.971, 1839.41, 89.9613, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 12, -224.306, 1833.44, 88.3981, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 13, -220.364, 1826.26, 87.3495, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 14, -216.424, 1810.36, 84.5744, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 15, -211.085, 1788.83, 78.924, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 16, -206.033, 1768.44, 73.1322, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 17, -203.105, 1741.79, 65.4756, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 18, -202.015, 1718.44, 58.8484, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 19, -200.981, 1696.27, 52.4718, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 20, -199.729, 1669.42, 46.1631, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 21, -199.282, 1646.05, 41.2679, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 22, -200.769, 1619.28, 36.301, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 23, -204.386, 1598.59, 32.4132, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 24, -210.568, 1577.36, 29.1862, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 25, -217.415, 1553.83, 26.4816, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 26, -223.967, 1530.23, 24.0484, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 27, -229.802, 1505.21, 21.1095, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 28, -234.836, 1481.24, 17.8893, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 29, -239.664, 1458.43, 15.1325, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 30, -245.217, 1432.2, 14.0314, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 31, -250.046, 1409.4, 12.3827, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 32, -251.786, 1388.47, 11.215, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 33, -250.26, 1364.02, 10.9601, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 34, -248.735, 1339.58, 13.2148, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 35, -247.056, 1317.58, 16.6388, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 36, -244.276, 1302.65, 19.114, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 37, -240.016, 1279.77, 23.1148, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 38, -239.095, 1260.01, 26.6083, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 39, -239.616, 1241.4, 29.732, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 40, -241.521, 1220.49, 33.8372, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 41, -242.736, 1206.55, 39.2003, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 42, -244.53, 1197.24, 42.3959, 'Pit Commander'),
(@PIT_COMMANDER_ENTRY, 43, -246.588, 1175.04, 41.621, 'Pit Commander');

-- Infernal Target (Hyjal)
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=@INFERNAL_TARGET_HYJAL_ENTRY;

-- Infernal Target (Hyjal) SAI
SET @GUID := -74081;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|512, `AIName`="SmartAI" WHERE `entry`=@INFERNAL_TARGET_HYJAL_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,0,0,0,11,33240,0,0,0,0,0,10,68745,@INFERNAL_RELAY_HELLFIRE_ENTRY,0,0,0,0,0,"Infernal Target (Hyjal) - On Data Set - Cast Infernal"),
(@GUID,0,1,0,25,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infernal Target (Hyjal) - On Data Set - Cast Infernal");
-- Infernal Target (Hyjal) SAI
SET @GUID := -74082;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@INFERNAL_TARGET_HYJAL_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,38,0,100,0,1,0,0,0,11,33240,0,0,0,0,0,10,68744,@INFERNAL_RELAY_HELLFIRE_ENTRY,0,0,0,0,0,"Infernal Target (Hyjal) - On Data Set - Cast Infernal"),
(@GUID,0,2,0,25,0,100,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infernal Target (Hyjal) - On Data Set - Cast Infernal");

-- Infernal Relay (Hellfire)
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=@INFERNAL_RELAY_HELLFIRE_ENTRY;
UPDATE `creature_template` SET `InhabitType`=4 WHERE entry=@INFERNAL_RELAY_HELLFIRE_ENTRY;
UPDATE `creature_template` SET `AIName`="" WHERE `entry`=@INFERNAL_RELAY_HELLFIRE_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INFERNAL_RELAY_HELLFIRE_ENTRY AND `source_type`=0;

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40, `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@WRATH_MASTER_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@WRATH_MASTER_ENTRY, -68311, -68312, -68313, -68314) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@WRATH_MASTER_ENTRY*100+0, @WRATH_MASTER_ENTRY*100+1, @WRATH_MASTER_ENTRY*100+2, @WRATH_MASTER_ENTRY*100+3) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WRATH_MASTER_ENTRY*100+0, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -278.63, 1534.43, 32.62, 0.0, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+0, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+0, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -280.33, 1541.21, 33.74, 0.0, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+0, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+0, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -277.73, 1523.79, 31.30, 0.0, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+0, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+0, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -279.23, 1518.37, 30.84, 0.0, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+0, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -170.70, 1508.39, 27.5, 3.14, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -169.63, 1503.79, 27.3, 3.14, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+1, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -169.62, 1519.02, 28.6, 3.14, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+1, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+1, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -166.86, 1524.43, 29.4, 3.14, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+1, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+2, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -100.15, 1888.80, 77.4, 2.54, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+2, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+2, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -100.48, 1885.22, 77.35, 2.54, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+2, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+2, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -95.23, 1895.04, 76.5, 2.54, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+2, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+2, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -91.67, 1896.62, 75.8, 2.54, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+2, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+3, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -415.50, 1829.44, 74.8, 4.53, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+3, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+3, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -412.43, 1830.42, 75.4, 4.53, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+3, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+3, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -423.48, 1831.24, 74.5, 4.53, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+3, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(@WRATH_MASTER_ENTRY*100+3, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 18944, 8, 0, 0, 0, 0, 8, 0, 0, 0, -427.70, 1833.82, 75.0, 4.53, 'Wrath Master - On Script - Summon Fel Soldier'),
(@WRATH_MASTER_ENTRY*100+3, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Script - Set Data'),
(-68311, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Set Active'),
(-68311, 0, 1, 0, 36, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Corpse Removed - Set Active'),
(-68311, 0, 2, 3, 11, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Cast Teleport Visual Only'),
(-68311, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 6000, 6000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Create Timed Event'),
(-68311, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @WRATH_MASTER_ENTRY*100+0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Run Script'),
(-68311, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 53, 0, 68311, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Timed Event - Start WP'),
(-68311, 0, 6, 0, 17, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - Just Summoned - Store Target'),
(-68311, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Death - Despawn'),
(-68311, 0, 8, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Aggro - Call For Help'),
(-68311, 0, 10, 0, 0, 0, 100, 0, 3000, 13000, 15000, 31000, 11, 29574, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Rend'),
(-68311, 0, 11, 0, 0, 0, 100, 0, 6000, 19000, 21000, 36000, 11, 35871, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Spellbreaker'),
(-68312, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Set Active'),
(-68312, 0, 1, 0, 36, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Corpse Removed - Set Active'),
(-68312, 0, 2, 3, 11, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Cast Teleport Visual Only'),
(-68312, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 1500, 1500, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Create Timed Event'),
(-68312, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @WRATH_MASTER_ENTRY*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Run Script'),
(-68312, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 53, 0, 68312, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Timed Event - Start WP'),
(-68312, 0, 6, 0, 17, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - Just Summoned - Store Target'),
(-68312, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Death - Despawn'),
(-68312, 0, 8, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Aggro - Call For Help'),
(-68312, 0, 10, 0, 0, 0, 100, 0, 3000, 13000, 15000, 31000, 11, 29574, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Rend'),
(-68312, 0, 11, 0, 0, 0, 100, 0, 6000, 19000, 21000, 36000, 11, 35871, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Spellbreaker'),
(-68313, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Set Active'),
(-68313, 0, 1, 0, 36, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Corpse Removed - Set Active'),
(-68313, 0, 2, 3, 11, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Cast Teleport Visual Only'),
(-68313, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 4000, 4000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Create Timed Event'),
(-68313, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @WRATH_MASTER_ENTRY*100+2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Run Script'),
(-68313, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 53, 0, 68313, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Timed Event - Start WP'),
(-68313, 0, 6, 0, 17, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - Just Summoned - Store Target'),
(-68313, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Death - Despawn'),
(-68313, 0, 8, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Aggro - Call For Help'),
(-68313, 0, 10, 0, 0, 0, 100, 0, 3000, 13000, 15000, 31000, 11, 29574, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Rend'),
(-68313, 0, 11, 0, 0, 0, 100, 0, 6000, 19000, 21000, 36000, 11, 35871, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Spellbreaker'),
(-68314, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Set Active'),
(-68314, 0, 1, 0, 36, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Corpse Removed - Set Active'),
(-68314, 0, 2, 3, 11, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Cast Teleport Visual Only'),
(-68314, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 4000, 4000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Create Timed Event'),
(-68314, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @WRATH_MASTER_ENTRY*100+3, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Respawn - Run Script'),
(-68314, 0, 5, 0, 59, 0, 100, 0, 1, 0, 0, 0, 53, 0, 68314, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Timed Event - Start WP'),
(-68314, 0, 6, 0, 17, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - Just Summoned - Store Target'),
(-68314, 0, 7, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Death - Despawn'),
(-68314, 0, 8, 0, 4, 0, 100, 0, 0, 0, 0, 0, 39, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - On Aggro - Call For Help'),
(-68314, 0, 10, 0, 0, 0, 100, 0, 3000, 13000, 15000, 31000, 11, 29574, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Rend'),
(-68314, 0, 11, 0, 0, 0, 100, 0, 6000, 19000, 21000, 36000, 11, 35871, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Wrath Master - In Combat - Cast Spellbreaker');

DELETE FROM `waypoints` WHERE `entry` IN(68311, 68312, 68313, 68314);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(68311, 1, -270.735, 1527.63, 31.1836, 'Wrath Master'),
(68311, 2, -260.567, 1525.02, 29.8034, 'Wrath Master'),
(68311, 3, -253.926, 1522.59, 28.1088, 'Wrath Master'),
(68311, 4, -249.349, 1521.57, 25.0041, 'Wrath Master'),
(68311, 5, -240.034, 1516.72, 22.8203, 'Wrath Master'),
(68311, 6, -232.184, 1508.16, 21.5413, 'Wrath Master'),
(68311, 7, -230.872, 1501.28, 20.6535, 'Wrath Master'),
(68311, 8, -233.41, 1485.1, 18.4649, 'Wrath Master'),
(68311, 9, -236.188, 1467.82, 16.1683, 'Wrath Master'),
(68311, 10, -242.961, 1443.11, 14.2698, 'Wrath Master'),
(68311, 11, -248.129, 1419.16, 13.0837, 'Wrath Master'),
(68311, 12, -251.718, 1398.48, 11.6931, 'Wrath Master'),
(68311, 13, -251.572, 1377.49, 10.8303, 'Wrath Master'),
(68311, 14, -250.61, 1350.7, 11.892, 'Wrath Master'),
(68311, 15, -249.213, 1325.08, 15.3074, 'Wrath Master'),
(68311, 16, -246.101, 1309.06, 18.0727, 'Wrath Master'),
(68311, 17, -241.369, 1288.6, 21.4746, 'Wrath Master'),
(68311, 18, -237.172, 1270.45, 24.8971, 'Wrath Master'),
(68311, 19, -237.027, 1250.64, 28.2199, 'Wrath Master'),
(68311, 20, -238.517, 1229.74, 31.7736, 'Wrath Master'),
(68311, 21, -241.342, 1213.6, 35.8261, 'Wrath Master'),
(68311, 22, -242.892, 1198.11, 42.0217, 'Wrath Master'),
(68311, 23, -243.448, 1186.46, 42.3938, 'Wrath Master'),
(68311, 24, -244.052, 1171.28, 41.5405, 'Wrath Master'),
(68311, 25, -244.678, 1153.82, 41.6494, 'Wrath Master'),
(68311, 26, -251.905, 1139.83, 41.6667, 'Wrath Master'),
(68311, 27, -251.17, 1123.45, 42.1819, 'Wrath Master'),
(68311, 28, -251.454, 1105.95, 41.6667, 'Wrath Master'),
(68311, 29, -251.642, 1094.33, 41.6667, 'Wrath Master'),
(68311, 30, -251.786, 1085.48, 47.0111, 'Wrath Master'),
(68311, 31, -245.954, 1075.11, 53.9023, 'Wrath Master'),
(68311, 32, -246.144, 1063.42, 54.3107, 'Wrath Master'),
(68311, 33, -246.447, 1044.73, 54.3162, 'Wrath Master'),
(68312, 1, -180.01, 1516.58, 27.6035, 'Wrath Master'),
(68312, 2, -188.161, 1515.78, 27.4855, 'Wrath Master'),
(68312, 3, -194.709, 1514.48, 27.2184, 'Wrath Master'),
(68312, 4, -203.528, 1512.33, 23.5807, 'Wrath Master'),
(68312, 5, -209.201, 1510.78, 22.2023, 'Wrath Master'),
(68312, 6, -213.606, 1506.99, 21.42, 'Wrath Master'),
(68312, 7, -222.386, 1499.38, 20.397, 'Wrath Master'),
(68312, 8, -228.273, 1486.68, 18.8159, 'Wrath Master'),
(68312, 9, -232.004, 1474.43, 17.1083, 'Wrath Master'),
(68312, 10, -232.004, 1474.43, 17.1083, 'Wrath Master'),
(68312, 11, -240.088, 1440.38, 14.1734, 'Wrath Master'),
(68312, 12, -247.414, 1410.98, 12.5468, 'Wrath Master'),
(68312, 13, -248.588, 1400.56, 11.8825, 'Wrath Master'),
(68312, 14, -248.808, 1369.07, 10.8148, 'Wrath Master'),
(68312, 15, -248.808, 1369.07, 10.8148, 'Wrath Master'),
(68312, 16, -245.535, 1334.29, 14.0067, 'Wrath Master'),
(68312, 17, -245.535, 1334.29, 14.0067, 'Wrath Master'),
(68312, 18, -241.99, 1299.51, 19.6667, 'Wrath Master'),
(68312, 19, -241.99, 1299.51, 19.6667, 'Wrath Master'),
(68312, 20, -238.526, 1264.69, 25.8431, 'Wrath Master'),
(68312, 21, -238.904, 1239.16, 30.0995, 'Wrath Master'),
(68312, 22, -238.904, 1239.16, 30.0995, 'Wrath Master'),
(68312, 23, -243.629, 1211.67, 36.8028, 'Wrath Master'),
(68312, 24, -245.399, 1197.78, 42.3701, 'Wrath Master'),
(68312, 25, -245.493, 1176.78, 41.6676, 'Wrath Master'),
(68312, 26, -245.586, 1155.78, 41.6338, 'Wrath Master'),
(68312, 27, -245.69, 1132.47, 41.6998, 'Wrath Master'),
(68312, 28, -251.551, 1115.07, 41.6792, 'Wrath Master'),
(68312, 29, -251.829, 1094.35, 41.6669, 'Wrath Master'),
(68312, 30, -251.929, 1086.16, 46.5319, 'Wrath Master'),
(68312, 31, -251.935, 1075.06, 53.8996, 'Wrath Master'),
(68312, 32, -248.941, 1063.44, 54.3106, 'Wrath Master'),
(68312, 33, -248.95, 1045.94, 54.3171, 'Wrath Master'),
(68313, 1, -112.343, 1891.33, 80.0147, 'Wrath Master'),
(68313, 2, -129.092, 1880.62, 83.4569, 'Wrath Master'),
(68313, 3, -145.72, 1872.24, 86.5619, 'Wrath Master'),
(68313, 4, -159.512, 1869.84, 89.052, 'Wrath Master'),
(68313, 5, -177.777, 1865.91, 93.1582, 'Wrath Master'),
(68313, 6, -189.585, 1861.14, 94.292, 'Wrath Master'),
(68313, 7, -194.196, 1859.96, 92.3105, 'Wrath Master'),
(68313, 8, -198.484, 1858.43, 91.6116, 'Wrath Master'),
(68313, 9, -200.727, 1857.64, 90.8248, 'Wrath Master'),
(68313, 10, -207.861, 1851.66, 90.1464, 'Wrath Master'),
(68313, 11, -215.437, 1841.33, 88.974, 'Wrath Master'),
(68313, 12, -215.021, 1829.64, 87.6314, 'Wrath Master'),
(68313, 13, -214.322, 1813.28, 85.0578, 'Wrath Master'),
(68313, 14, -212.8, 1800.56, 82.2836, 'Wrath Master'),
(68313, 15, -210.241, 1780.85, 76.6338, 'Wrath Master'),
(68313, 16, -207.241, 1757.73, 70.0961, 'Wrath Master'),
(68313, 17, -204.692, 1738.08, 64.4382, 'Wrath Master'),
(68313, 18, -204.353, 1720.59, 59.5464, 'Wrath Master'),
(68313, 19, -203.371, 1699.54, 53.4667, 'Wrath Master'),
(68313, 20, -202.608, 1683.18, 49.4984, 'Wrath Master'),
(68313, 21, -201.737, 1664.51, 45.1893, 'Wrath Master'),
(68313, 22, -200.81, 1644.72, 41.0282, 'Wrath Master'),
(68313, 23, -199.93, 1627.31, 37.7967, 'Wrath Master'),
(68313, 24, -199.93, 1627.31, 37.7967, 'Wrath Master'),
(68313, 25, -203.923, 1601.96, 33.021, 'Wrath Master'),
(68313, 26, -207.465, 1588.42, 30.7292, 'Wrath Master'),
(68313, 27, -211.591, 1572.64, 28.6103, 'Wrath Master'),
(68313, 28, -216.32, 1554.56, 26.5615, 'Wrath Master'),
(68313, 29, -220.446, 1538.78, 24.9218, 'Wrath Master'),
(68313, 30, -224.874, 1521.85, 23.0684, 'Wrath Master'),
(68313, 31, -230.789, 1499.23, 20.3917, 'Wrath Master'),
(68313, 32, -235.517, 1481.15, 17.8653, 'Wrath Master'),
(68313, 33, -240.529, 1461.98, 15.4422, 'Wrath Master'),
(68313, 34, -244.372, 1447.29, 14.5134, 'Wrath Master'),
(68313, 35, -248.8, 1430.35, 13.8539, 'Wrath Master'),
(68313, 36, -252.625, 1415.73, 12.7361, 'Wrath Master'),
(68313, 37, -253.861, 1404.17, 11.9207, 'Wrath Master'),
(68313, 38, -252.777, 1387.83, 11.1616, 'Wrath Master'),
(68313, 39, -251.771, 1372.67, 10.7793, 'Wrath Master'),
(68313, 40, -250.459, 1352.89, 11.6834, 'Wrath Master'),
(68313, 41, -249.305, 1335.49, 13.7715, 'Wrath Master'),
(68313, 42, -248.147, 1318.03, 16.5355, 'Wrath Master'),
(68313, 43, -246.234, 1306.5, 18.4776, 'Wrath Master'),
(68313, 44, -243.565, 1290.41, 21.1146, 'Wrath Master'),
(68313, 45, -239.75, 1267.41, 25.3402, 'Wrath Master'),
(68313, 46, -236.313, 1246.7, 28.9015, 'Wrath Master'),
(68313, 47, -239.597, 1224.71, 32.8632, 'Wrath Master'),
(68313, 48, -240.818, 1210.69, 37.0075, 'Wrath Master'),
(68313, 49, -242.052, 1196.54, 42.1932, 'Wrath Master'),
(68313, 50, -242.537, 1181.36, 41.8351, 'Wrath Master'),
(68313, 51, -243.318, 1156.93, 41.6182, 'Wrath Master'),
(68313, 52, -243.987, 1135.98, 41.6667, 'Wrath Master'),
(68313, 53, -251.546, 1118.49, 42.0075, 'Wrath Master'),
(68313, 54, -251.067, 1102.19, 41.6667, 'Wrath Master'),
(68313, 55, -251.326, 1094.07, 41.6667, 'Wrath Master'),
(68313, 56, -251.59, 1083.3, 48.4641, 'Wrath Master'),
(68313, 57, -251.594, 1074.58, 54.2525, 'Wrath Master'),
(68313, 58, -245.603, 1058.27, 54.3126, 'Wrath Master'),
(68313, 59, -245.614, 1037.27, 54.3191, 'Wrath Master'),
(68314, 1, -404.061, 1818.73, 72.6499, 'Wrath Master'),
(68314, 2, -389.501, 1814.49, 72.7857, 'Wrath Master'),
(68314, 3, -370.481, 1808.96, 73.5055, 'Wrath Master'),
(68314, 4, -352.539, 1803.73, 73.6972, 'Wrath Master'),
(68314, 5, -338.685, 1805.75, 75.216, 'Wrath Master'),
(68314, 6, -320.381, 1809.53, 79.0509, 'Wrath Master'),
(68314, 7, -301.382, 1815.28, 82.8135, 'Wrath Master'),
(68314, 8, -285.97, 1820.62, 85.9315, 'Wrath Master'),
(68314, 9, -272.466, 1827.48, 88.2899, 'Wrath Master'),
(68314, 10, -265.201, 1831.11, 89.7627, 'Wrath Master'),
(68314, 11, -253.62, 1832.71, 91.8272, 'Wrath Master'),
(68314, 12, -241.178, 1841.39, 92.7873, 'Wrath Master'),
(68314, 13, -236.851, 1842.14, 90.2615, 'Wrath Master'),
(68314, 14, -227.443, 1837.47, 89.0557, 'Wrath Master'),
(68314, 15, -219.36, 1827.54, 87.4862, 'Wrath Master'),
(68314, 16, -216.983, 1813.74, 85.215, 'Wrath Master'),
(68314, 17, -213.051, 1795.54, 80.9159, 'Wrath Master'),
(68314, 18, -208.664, 1776.22, 75.3269, 'Wrath Master'),
(68314, 19, -203.564, 1753.41, 68.8117, 'Wrath Master'),
(68314, 20, -201.937, 1733.59, 63.0754, 'Wrath Master'),
(68314, 21, -200.196, 1709.16, 56.0166, 'Wrath Master'),
(68314, 22, -199.037, 1689.31, 50.7389, 'Wrath Master'),
(68314, 23, -199.125, 1669.5, 46.1424, 'Wrath Master'),
(68314, 24, -199.234, 1645, 41.067, 'Wrath Master'),
(68314, 25, -199.968, 1621.71, 36.7692, 'Wrath Master'),
(68314, 26, -201.72, 1601.97, 33.0508, 'Wrath Master'),
(68314, 27, -208.383, 1578.4, 29.3313, 'Wrath Master'),
(68314, 28, -214.934, 1551.17, 26.2096, 'Wrath Master'),
(68314, 29, -223.08, 1519.51, 22.738, 'Wrath Master'),
(68314, 30, -230.058, 1492.4, 19.5117, 'Wrath Master'),
(68314, 31, -236.163, 1468.67, 16.2668, 'Wrath Master'),
(68314, 32, -242.269, 1444.94, 14.2877, 'Wrath Master'),
(68314, 33, -247.799, 1423.45, 13.3939, 'Wrath Master'),
(68314, 34, -251.61, 1399.26, 11.7349, 'Wrath Master'),
(68314, 35, -252.834, 1369.07, 10.8068, 'Wrath Master'),
(68314, 36, -251.446, 1349.31, 12.034, 'Wrath Master'),
(68314, 37, -248.328, 1326.21, 15.1602, 'Wrath Master'),
(68314, 38, -245.147, 1303.12, 19.0204, 'Wrath Master'),
(68314, 39, -241.558, 1277.81, 23.4223, 'Wrath Master'),
(68314, 40, -241.404, 1256.81, 27.0886, 'Wrath Master'),
(68314, 41, -240.981, 1234.62, 30.8882, 'Wrath Master'),
(68314, 42, -242.084, 1214.77, 35.4648, 'Wrath Master'),
(68314, 43, -243.058, 1197.23, 42.2163, 'Wrath Master'),
(68314, 44, -243.323, 1180.92, 41.8092, 'Wrath Master'),
(68314, 45, -243.721, 1156.42, 41.6234, 'Wrath Master'),
(68314, 46, -245.046, 1137.85, 41.668, 'Wrath Master'),
(68314, 47, -252.701, 1115.96, 41.6755, 'Wrath Master'),
(68314, 48, -252.761, 1094.48, 41.6669, 'Wrath Master'),
(68314, 49, -252.516, 1085.41, 47.012, 'Wrath Master'),
(68314, 50, -252.234, 1074.91, 53.9873, 'Wrath Master'),
(68314, 51, -252.106, 1057.41, 54.3128, 'Wrath Master'),
(68314, 52, -249.986, 1041.03, 54.318, 'Wrath Master');

-- Delete current creatures Infernal Siegebreaker (18946)
DELETE FROM `creature_addon` WHERE `guid` IN(SELECT `guid` FROM `creature` WHERE id=18946);
DELETE FROM `creature` WHERE `id`=18946;

-- Update extra flags
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40 WHERE `entry`=18946;

-- Infernal Siegebreaker SAI
DELETE FROM `creature_template_addon` WHERE `entry` = 18946;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES (18946, '33650');

DELETE FROM `creature_addon` WHERE `guid` IN(SELECT `guid` FROM `creature` WHERE `id`=18944);
DELETE FROM `creature` WHERE id=18944;
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x40 WHERE `entry`=18944;

-- Fel Soldier SAI
SET @ENTRY := 18944;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,29,1,120,0,0,0,0,23,0,0,0,0,0,0,0,"Fel Soldier - On Data Set - Follow"),
(@ENTRY,0,1,0,38,0,100,0,2,2,0,0,29,6,120,0,0,0,0,23,0,0,0,0,0,0,0,"Fel Soldier - On Data Set - Follow"),
(@ENTRY,0,2,0,38,0,100,0,3,3,0,0,29,1,240,0,0,0,0,23,0,0,0,0,0,0,0,"Fel Soldier - On Data Set - Follow"),
(@ENTRY,0,3,0,38,0,100,0,4,4,0,0,29,6,240,0,0,0,0,23,0,0,0,0,0,0,0,"Fel Soldier - On Data Set - Follow"),
(@ENTRY,0,4,5,54,0,100,0,0,0,0,0,11,51347,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Soldier - On Reset - Cast Teleport Visual Only"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Soldier - On Respawn - Set Run False"),
(@ENTRY,0,6,0,0,0,100,0,3000,12000,9000,15000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Soldier - In Combat - Cast Cleave"),
(@ENTRY,0,7,0,0,0,100,0,6000,20000,16000,33000,11,32009,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fel Soldier - In Combat - Cast Cutdown"),
(@ENTRY,0,8,0,4,0,100,0,0,0,0,0,39,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Soldier - On Aggro - Call For Help"),
(@ENTRY,0,9,0,60,0,100,0,5000,5000,5000,5000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Soldier - On Update - Set Home Position");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=18944;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19006, 19007) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19006, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gnomeregan Conjuror - On Reset - Set active"),
(19007, 0, 1, 0, 25, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gnomeregan Conjuror - On Reset - Set active");

-- Darkspear Axe Thrower
UPDATE `creature_template` SET AIName='SmartAI', `ScriptName`='' WHERE `entry`=@DARKSPEAR_AXE_THROWER_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DARKSPEAR_AXE_THROWER_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DARKSPEAR_AXE_THROWER_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkspear Axe Thrower - On JUST SUMMONED - Cast visual teleport'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 0, 1, 2, 61, 0, 100, 0, 1, 0, 0, 0, 53, 1, @DARKSPEAR_AXE_THROWER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkspear Axe Thrower - On Timed Event - Start WP'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkspear Axe Thrower - On JUST SUMMONED - Set active'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 0, 3, 0, 0, 0, 100, 0, 0, 2000, 2300, 3900, 11, 10277, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Darkspear Axe Thrower - In Combat - Cast Throw'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 0, 4, 5, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkspear Axe Thrower - On WP Reached - Set Home pos'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darkspear Axe Thrower - On WP Reached - Random mov'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 0, 6, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 30, 0, 0, 0, 0, 0, 0, 'Darkspear Axe Thrower - Ooc - Start attack');

-- Orgrimmar Grunt
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ORGRIMMAR_GRUNT_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ORGRIMMAR_GRUNT_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ORGRIMMAR_GRUNT_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - On JUST SUMMONED - Cast visual teleport'),
(@ORGRIMMAR_GRUNT_ENTRY, 0, 1, 2, 61, 0, 100, 0, 1, 0, 0, 0, 53, 1, @DARKSPEAR_AXE_THROWER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - On Timed Event - Start WP'),
(@ORGRIMMAR_GRUNT_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - On JUST SUMMONED - Set active'),
(@ORGRIMMAR_GRUNT_ENTRY, 0, 3, 0, 0, 0, 100, 0, 3000, 9000, 8000, 13000, 11, 33626, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - In Combat - Cast Strike'),
(@ORGRIMMAR_GRUNT_ENTRY, 0, 4, 0, 0, 0, 40, 0, 3000, 29000, 28000, 53000, 11, 23511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - In Combat - Cast Demoralizing Shout'),
(@ORGRIMMAR_GRUNT_ENTRY, 0, 5, 6, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - On WP Reached - Set Home pos'),
(@ORGRIMMAR_GRUNT_ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - On WP Reached - Random mov'),
(@ORGRIMMAR_GRUNT_ENTRY, 0, 7, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Orgrimmar Grunt - Ooc - Start attack');

-- Orgrimmar Shaman
DELETE FROM `creature_template_addon` WHERE `entry` = @ORGRIMMAR_SHAMAN_ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`, `emote`) VALUES (@ORGRIMMAR_SHAMAN_ENTRY, 4097, 333);

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ORGRIMMAR_SHAMAN_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ORGRIMMAR_SHAMAN_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - On JUST SUMMONED - Cast visual teleport'),
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 1, 2, 61, 0, 100, 0, 1, 0, 0, 0, 53, 1, @DARKSPEAR_AXE_THROWER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - On Timed Event - Start WP'),
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - On JUST SUMMONED - Set active'),
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 3, 0, 0, 0, 100, 0, 3000, 12000, 12000, 18000, 11, 15616, 0, 0, 0, 0, 0, 5, 20, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - In Combat - Cast Flame Shock'),
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 4, 0, 0, 0, 100, 0, 0, 5000, 60000, 60000, 11, 20545, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - In Combat - Cast Lightning Shield'),
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 5, 6, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - On WP Reached - Set Home pos'),
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - On WP Reached - Random mov'),
(@ORGRIMMAR_SHAMAN_ENTRY, 0, 7, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Orgrimmar Shaman - Ooc - Start attack');

-- Undercity Mage
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@UNDERCITY_MAGE_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@UNDERCITY_MAGE_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@UNDERCITY_MAGE_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - On JUST SUMMONED - Cast visual teleport'),
(@UNDERCITY_MAGE_ENTRY, 0, 1, 2, 61, 0, 100, 0, 1, 0, 0, 0, 53, 1, @DARKSPEAR_AXE_THROWER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - On Timed Event - Start WP'),
(@UNDERCITY_MAGE_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - On JUST SUMMONED - Set active'),
(@UNDERCITY_MAGE_ENTRY, 0, 3, 0, 0, 0, 100, 0, 1000, 2000, 3000, 5000, 11, 33417, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - In Combat - Cast Fireball'),
(@UNDERCITY_MAGE_ENTRY, 0, 4, 0, 0, 0, 100, 0, 3000, 17000, 20000, 40000, 11, 33419, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - In Combat - Cast Arcane Missiles'),
(@UNDERCITY_MAGE_ENTRY, 0, 5, 0, 0, 0, 100, 0, 3000, 27000, 30000, 50000, 11, 33624, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - In Combat - Cast Blizzard'),
(@UNDERCITY_MAGE_ENTRY, 0, 6, 7, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - On WP Reached - Set Home pos'),
(@UNDERCITY_MAGE_ENTRY, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Undercity Mage - On WP Reached - Random mov'),
(@UNDERCITY_MAGE_ENTRY, 0, 8, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 30, 0, 0, 0, 0, 0, 0, 'Undercity Mage - Ooc - Start attack');

-- Darnassian Archer
UPDATE `creature_template` SET `AIName`='SmartAI', ScriptName='' WHERE `entry`=@DARNASSIAN_ARCHER_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DARNASSIAN_ARCHER_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DARNASSIAN_ARCHER_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnassian Archer - On JUST SUMMONED - Cast visual teleport'),
(@DARNASSIAN_ARCHER_ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, @DARNASSIAN_ARCHER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnassian Archer - On JUST SUMMONED - start WP'),
(@DARNASSIAN_ARCHER_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnassian Archer - On JUST SUMMONED - Set active'),
(@DARNASSIAN_ARCHER_ENTRY, 0, 3, 0, 0, 0, 100, 0, 0, 2000, 2000, 3000, 11, 15620, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Darnassian Archer - In Combat - Cast Shoot'),
(@DARNASSIAN_ARCHER_ENTRY, 0, 4, 5, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darnassian Archer - On WP Reached - Set Home pos'),
(@DARNASSIAN_ARCHER_ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Archer - On WP Reached - Random mov'),
(@DARNASSIAN_ARCHER_ENTRY, 0, 6, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 30, 0, 0, 0, 0, 0, 0, 'Darnassian Archer - Ooc - Start attack');

-- Ironforge Paladin
DELETE FROM `creature_template_addon` WHERE `entry` = @IRONFORGE_PALADIN_ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`, `emote`) VALUES (@IRONFORGE_PALADIN_ENTRY, 4097, 333);

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@IRONFORGE_PALADIN_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@IRONFORGE_PALADIN_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@IRONFORGE_PALADIN_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - On JUST SUMMONED - Cast visual teleport'),
(@IRONFORGE_PALADIN_ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, @DARNASSIAN_ARCHER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - On JUST SUMMONED - start WP'),
(@IRONFORGE_PALADIN_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - On JUST SUMMONED - Set active'),
(@IRONFORGE_PALADIN_ENTRY, 0, 3, 0, 0, 0, 100, 0, 3000, 9000, 8000, 13000, 11, 20696, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - In Combat - Cast Holy Smite'),
(@IRONFORGE_PALADIN_ENTRY, 0, 4, 0, 0, 0, 40, 0, 3000, 12000, 15000, 28000, 11, 33632, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - In Combat - Cast Exorcism'),
(@IRONFORGE_PALADIN_ENTRY, 0, 5, 6, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - On WP Reached - Set Home pos'),
(@IRONFORGE_PALADIN_ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - On WP Reached - Random mov'),
(@IRONFORGE_PALADIN_ENTRY, 0, 7, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Ironforge Paladin - Ooc - Start attack');

-- Stormwind Soldier
DELETE FROM `creature_template_addon` WHERE `entry` = @STORMWIND_SOLDIER_ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`, `emote`) VALUES (@STORMWIND_SOLDIER_ENTRY, 4097, 333);

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@STORMWIND_SOLDIER_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@STORMWIND_SOLDIER_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@STORMWIND_SOLDIER_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - On JUST SUMMONED - Cast visual teleport'),
(@STORMWIND_SOLDIER_ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, @DARNASSIAN_ARCHER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - On JUST SUMMONED - start WP'),
(@STORMWIND_SOLDIER_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - On JUST SUMMONED - Set active'),
(@STORMWIND_SOLDIER_ENTRY, 0, 3, 0, 0, 0, 100, 0, 3000, 9000, 8000, 13000, 11, 33626, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - In Combat - Cast Strike'),
(@STORMWIND_SOLDIER_ENTRY, 0, 4, 0, 0, 0, 40, 0, 3000, 29000, 28000, 53000, 11, 23511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - In Combat - Cast Demoralizing Shout'),
(@STORMWIND_SOLDIER_ENTRY, 0, 5, 6, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - On WP Reached - Set Home pos'),
(@STORMWIND_SOLDIER_ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - On WP Reached - Random mov'),
(@STORMWIND_SOLDIER_ENTRY, 0, 7, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Stormwind Soldier - Ooc - Start attack');

-- Stormwind Mage
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@STORMWIND_MAGE_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@STORMWIND_MAGE_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@STORMWIND_MAGE_ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 11, 51347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - On JUST SUMMONED - Cast visual teleport'),
(@STORMWIND_MAGE_ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, @DARNASSIAN_ARCHER_ENTRY, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - On JUST SUMMONED - start WP'),
(@STORMWIND_MAGE_ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - On JUST SUMMONED - Set active'),
(@STORMWIND_MAGE_ENTRY, 0, 3, 0, 0, 0, 100, 0, 1000, 2000, 3000, 5000, 11, 33417, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - In Combat - Cast Fireball'),
(@STORMWIND_MAGE_ENTRY, 0, 4, 0, 0, 0, 100, 0, 3000, 17000, 20000, 40000, 11, 33419, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - In Combat - Cast Arcane Missiles'),
(@STORMWIND_MAGE_ENTRY, 0, 5, 0, 0, 0, 100, 0, 3000, 27000, 30000, 50000, 11, 33624, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - In Combat - Cast Blizzard'),
(@STORMWIND_MAGE_ENTRY, 0, 6, 7, 40, 0, 100, 0, 12, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - On WP Reached - Set Home pos'),
(@STORMWIND_MAGE_ENTRY, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 89, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - On WP Reached - Random mov'),
(@STORMWIND_MAGE_ENTRY, 0, 8, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 30, 0, 0, 0, 0, 0, 0, 'Stormwind Mage - Ooc - Start attack');

-- Justinius the Harbinger
DELETE FROM `creature_text` WHERE `CreatureID`=@JUSTINIUS_THE_HARBINGER_ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 0,"Soldiers of Azeroth, you now fight against the vile Burning Crusade. And the hopes and prayers of all Light-loving people march with you. In the company of our brave allies and brothers -in-arms you will hold your ground and break the demonic charge. You will stem the destructive tyranny that rages across so many worlds.", 14, 0, 100, 0, 0, 0, 16625, 0, 'Justinius the Harbinger Aggro'),
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 1,"With each passing moment, I see the people of Azeroth prove again the reasons we have come. It is with solemn pride that I fight with you, and if I die this day, then I die among friends.", 14, 0, 100, 0, 0, 0, 16633, 0, 'Justinius the Harbinger Aggro'),
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 2,"The demons should be in no doubt that we are their nemesis and, though they wish our destruction, it is we who bring about their ruin. Kazzak and his forces will be diminished and defeated by this coalition. And to do this, we must throw at them our bodies and hearts, for they seek no less than the obliteration of this world.", 14, 0, 100, 0, 0, 0, 16627, 0, 'Justinius the Harbinger Aggro'),
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 3,"Fight on, good people of Azeroth. And take heart! Your brethren rush to this hellish portal and will soon throw themselves at these demons as you have so bravely done. May the Light keep you!", 14, 0, 100, 0, 0, 0, 16933, 0, 'Justinius the Harbinger Aggro'),
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 4,"Behold the power of the Light! Grace and glory to the Alliance!" , 14, 0, 100, 0, 0, 0, 16286, 0, 'Justinius the Harbinger Aggro');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@JUSTINIUS_THE_HARBINGER_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@JUSTINIUS_THE_HARBINGER_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 0, 0, 0, 0, 100, 0, 1000, 20000, 20000, 40000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Justinius the Harbinger - IC - Say Line 0'),
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 10000, 20000, 11, 33554, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Justinius the Harbinger - In Combat - Cast Judgement of Command'),
(@JUSTINIUS_THE_HARBINGER_ENTRY, 0, 2, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 50, 0, 0, 0, 0, 0, 0, 'Justinius the Harbinger - Ooc - Start attack');

DELETE FROM `creature_text` WHERE `CreatureID`=@MELGROMM_HIGHMOUNTAIN_ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 0,"Hunters, to me! Let us show these demons what it is to fight and die in Azeroth!" , 14, 0, 100, 0, 0, 0, 16616, 0, 'MELGROMM_HIGHMOUNTAIN'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 1,"The spirits sing to us! They sing the song of battle!", 14, 0, 100, 0, 0, 0, 16617, 0, 'MELGROMM_HIGHMOUNTAIN'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 2,"Strike true, brothers and sisters! Today our quarry is demons!", 14, 0, 100, 0, 0, 0, 16618, 0, 'MELGROMM_HIGHMOUNTAIN'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 3,"Once again, we will show this Burning Legion that our world is not for the taking!", 14, 0, 100, 0, 0, 0, 16620, 0, 'MELGROMM_HIGHMOUNTAIN'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 4,"These fiends will fail! For Azeroth!", 14, 0, 100, 0, 0, 0, 16621, 0, 'MELGROMM_HIGHMOUNTAIN'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 5,"If it is our fate to die this day, then we will not go easy! Mark me, these demons will fall like wheat!", 14, 0, 100, 0, 0, 0, 16622, 0, 'MELGROMM_HIGHMOUNTAIN'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 6,"Though your sinews tire and your blood flows from cuts and wounds to this sodden ground, you fight for the spirits of your world. No evil force can stand against us!", 14, 0, 100, 0, 0, 0, 16624, 0, 'MELGROMM_HIGHMOUNTAIN'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 7,"My brethern, my commands-in-arms! I must go to seek the forces of the Horde and direct them here! Keep your spirits strong, brave hunters! Do not fall to the portal-spawned fiends!", 14, 0, 100, 0, 0, 0, 16935, 0, 'MELGROMM_HIGHMOUNTAIN');

-- Melgromm Highmountain
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@MELGROMM_HIGHMOUNTAIN_ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MELGROMM_HIGHMOUNTAIN_ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 0, 0, 0, 0, 100, 0, 5000, 10000, 10000, 20000, 11, 33643, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Melgromm Highmountain - In Combat - Cast Chain Lightning'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 10000, 20000, 11, 22885, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Melgromm Highmountain - In Combat - Cast Earth Shock'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 2, 0, 0, 0, 100, 0, 1000, 20000, 20000, 40000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Melgromm Highmountain - IC - Say Line 0'),
(@MELGROMM_HIGHMOUNTAIN_ENTRY, 0, 3, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 25, 50, 0, 0, 0, 0, 0, 0, 'Melgromm Highmountain - Ooc - Start attack');

-- Remake stairs spawns
DELETE FROM `creature_addon` WHERE `guid` IN(SELECT `guid` FROM `creature` WHERE `id` IN(@DARKSPEAR_AXE_THROWER_ENTRY, @ORGRIMMAR_GRUNT_ENTRY, @ORGRIMMAR_SHAMAN_ENTRY, @DARNASSIAN_ARCHER_ENTRY, @IRONFORGE_PALADIN_ENTRY, @STORMWIND_SOLDIER_ENTRY, @UNDERCITY_MAGE_ENTRY, @STORMWIND_MAGE_ENTRY, @JUSTINIUS_THE_HARBINGER_ENTRY, @MELGROMM_HIGHMOUNTAIN_ENTRY));

DELETE FROM `creature` WHERE `id` IN(@DARKSPEAR_AXE_THROWER_ENTRY, @ORGRIMMAR_GRUNT_ENTRY, @ORGRIMMAR_SHAMAN_ENTRY, @DARNASSIAN_ARCHER_ENTRY, @IRONFORGE_PALADIN_ENTRY, @STORMWIND_SOLDIER_ENTRY, @UNDERCITY_MAGE_ENTRY, @STORMWIND_MAGE_ENTRY, @JUSTINIUS_THE_HARBINGER_ENTRY, @MELGROMM_HIGHMOUNTAIN_ENTRY, @PIT_COMMANDER_ENTRY, @WRATH_MASTER_ENTRY);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@PIT_COMMANDER_GUID, @PIT_COMMANDER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -420.58, 1832.27, 75.1, 4.60, 10, 0, 0, 236000, 330900, 0, 0, 0, 0, 0),
(68311, @WRATH_MASTER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -276.43, 1529.10, 31.8, 0.0, 35, 0, 0, 143620, 0, 0, 0, 0, 0, 0),
(68312, @WRATH_MASTER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -172.35, 1513.68, 27.8, 3.14, 25, 0, 0, 143620, 0, 0, 0, 0, 0, 0),
(68313, @WRATH_MASTER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -99.78, 1892.91, 77.35, 2.54, 25, 0, 0, 143620, 0, 0, 0, 0, 0, 0),
(68314, @WRATH_MASTER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -418.51, 1828.48, 74.2, 4.53, 25, 0, 0, 143620, 0, 0, 0, 0, 0, 0),
(68010, @STORMWIND_SOLDIER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -267.365, 1098.02, 41.7141, 1.5708, 30, 0, 0, 12652 , 0, 0, 0, 0, 0, 0),
(68011, @STORMWIND_SOLDIER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -272.049, 1097.78, 41.936, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68012, @STORMWIND_SOLDIER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -259.395, 1098.42, 41.6679, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68013, @STORMWIND_SOLDIER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -264.079, 1098.18, 41.6716, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68021, @STORMWIND_SOLDIER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -254.498, 1098.19, 41.6667, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68017, @ORGRIMMAR_GRUNT_ENTRY, 530, 0, 0, 1, 0, 0, 1, -229.442, 1098.11, 41.6667, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68018, @ORGRIMMAR_GRUNT_ENTRY, 530, 0, 0, 1, 0, 0, 1, -237.898, 1098.01, 41.6667, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68020, @ORGRIMMAR_GRUNT_ENTRY, 530, 0, 0, 1, 0, 0, 1, -246.297, 1097.92, 41.6667, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68022, @ORGRIMMAR_GRUNT_ENTRY, 530, 0, 0, 1, 0, 0, 1, -251.015, 1097.87, 41.7916, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68024, @ORGRIMMAR_GRUNT_ENTRY, 530, 0, 0, 1, 0, 0, 1, -233.684, 1098.06, 41.6667, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68025, @ORGRIMMAR_GRUNT_ENTRY, 530, 0, 0, 1, 0, 0, 1, -242.321, 1097.96, 41.6667, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68111, @DARNASSIAN_ARCHER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -269.663, 1086.26, 46.2537, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68112, @DARNASSIAN_ARCHER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -269.932, 1083.3, 48.2155, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68113, @DARNASSIAN_ARCHER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -260.548, 1086.05, 46.4834, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68114, @DARNASSIAN_ARCHER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -260.593, 1083.48, 48.1924, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68115, @DARNASSIAN_ARCHER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -265.322, 1083.37, 48.2152, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68116, @DARNASSIAN_ARCHER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -265.187, 1086.36, 46.23, 1.5708, 30  , 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68118, @JUSTINIUS_THE_HARBINGER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -269.544, 1071.83, 54.3084, 1.5708, 30, 0, 0, 111780, 47325, 0, 0, 0, 0, 0),
(68121, @MELGROMM_HIGHMOUNTAIN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -230.449, 1071.93, 54.3084, 1.5708, 30, 0, 0, 111780, 47325, 0, 0, 0, 0, 0),
(68023, @DARKSPEAR_AXE_THROWER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -231.948, 1088.23, 45.3315, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68122, @DARKSPEAR_AXE_THROWER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -232.25, 1085.21, 47.3327, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68123, @DARKSPEAR_AXE_THROWER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -235.748, 1085.1, 47.3696, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68124, @DARKSPEAR_AXE_THROWER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -238.932, 1088.06, 45.3673, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68125, @DARKSPEAR_AXE_THROWER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -235.209, 1088.15, 45.3476, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(68126, @DARKSPEAR_AXE_THROWER_ENTRY, 530, 0, 0, 1, 0, 0, 1, -239.247, 1084.99, 47.4066, 1.5708, 30, 0, 0, 12652, 0, 0, 0, 0, 0, 0),
(86066, @ORGRIMMAR_SHAMAN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -249.345, 1094.04, 41.6667, 1.5708, 30, 0, 0, 7590, 29330, 0, 0, 0, 0, 0),
(86068, @ORGRIMMAR_SHAMAN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -240.736, 1094.17, 41.6667, 1.5708, 30, 0, 0, 7590, 29330, 0, 0, 0, 0, 0),
(86069, @ORGRIMMAR_SHAMAN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -245.398, 1094.1, 41.6667, 1.5708, 30, 0, 0, 7590, 29330, 0, 0, 0, 0, 0),
(86070, @ORGRIMMAR_SHAMAN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -231.307, 1094.23, 41.6667, 1.5708, 30, 0, 0, 7590, 29330, 0, 0, 0, 0, 0),
(86071, @ORGRIMMAR_SHAMAN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -236.089, 1094.24, 41.6667, 1.5708, 30, 0, 0, 7590, 29330, 0, 0, 0, 0, 0),
(68262, @IRONFORGE_PALADIN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -265.912, 1092.97, 41.8355, 1.5708, 30, 0, 0, 12650, 29330, 0, 0, 0, 0, 0),
(68263, @IRONFORGE_PALADIN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -257.407, 1092.94, 41.9379, 1.5708, 30, 0, 0, 12650, 29330, 0, 0, 0, 0, 0),
(68264, @IRONFORGE_PALADIN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -253.246, 1093.04, 41.9172, 1.5708, 30, 0, 0, 12650, 29330, 0, 0, 0, 0, 0),
(68265, @IRONFORGE_PALADIN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -261.812, 1092.96, 41.8783, 1.5708, 30, 0, 0, 12650, 29330, 0, 0, 0, 0, 0),
(68266, @IRONFORGE_PALADIN_ENTRY, 530, 0, 0, 1, 0, 0, 1, -270.575, 1093.28, 41.923, 1.5708, 30, 0, 0, 12650, 29330, 0, 0, 0, 0, 0),
(68127, @UNDERCITY_MAGE_ENTRY, 530, 0, 0, 1, 0, 0, 1, -225.987, 1083.23, 54.3374, 2.71726, 30, 0, 0, 9160, 68820, 0, 0, 0, 0, 0),
(68128, @UNDERCITY_MAGE_ENTRY, 530, 0, 0, 1, 0, 0, 1, -228.478, 1074.47, 54.3336, 2.51033, 30, 0, 0, 9160, 68820, 0, 0, 0, 0, 0),
(68015, @STORMWIND_MAGE_ENTRY, 530, 0, 0, 1, 0, 0, 1, -272.632, 1075, 54.3557, 1.5708, 30, 0, 0, 9160, 68820, 0, 0, 0, 0, 0),
(68016, @STORMWIND_MAGE_ENTRY, 530, 0, 0, 1, 0, 0, 1, -275.911, 1083.75, 54.3343, 1.5708, 30, 0, 0, 9160, 68820, 0, 0, 0, 0, 0);

-- Update addon
DELETE FROM `creature_addon` WHERE `guid` IN(@PIT_COMMANDER_GUID, 68311, 68312, 68313, 68314);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@PIT_COMMANDER_GUID, 0, 0, 0, 4097, 0, ''),
(68311, 0, 0, 0, 4097, 0, ''),
(68312, 0, 0, 0, 4097, 0, ''),
(68313, 0, 0, 0, 4097, 0, ''),
(68314, 0, 0, 0, 4097, 0, '');

-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN(@DARNASSIAN_ARCHER_ENTRY, @DARKSPEAR_AXE_THROWER_ENTRY);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@DARNASSIAN_ARCHER_ENTRY, 1, -334.99, 968.724, 54.284, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 2, -332.945, 976.655, 54.2957, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 3, -329.261, 988.924, 54.3038, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 4, -322.755, 1002.57, 54.2993, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 5, -316.731, 1015.21, 54.2947, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 6, -308.524, 1019.75, 54.2763, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 7, -296.914, 1021.11, 54.3091, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 8, -283.465, 1025.01, 54.3014, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 9, -273.568, 1036.39, 54.3263, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 10, -264.833, 1054.17, 54.3152, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 11, -263.071, 1071.34, 54.3081, 'Alliance - Stair of Destiny'),
(@DARNASSIAN_ARCHER_ENTRY, 12, -262.876, 1108.63, 41.666, 'Alliance - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 1, -163.282, 972.931, 54.2865, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 2, -167.265, 987.781, 54.3042, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 3, -170.451, 998.956, 54.2921, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 4, -177.333, 1012.5, 54.2872, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 5, -189.116, 1020.06, 54.2777, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 6, -206.5, 1022.07, 54.3103, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 7, -220.28, 1024.54, 54.3101, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 8, -228.761, 1035.68, 54.326, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 9, -233.435, 1046.39, 54.3183, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 10, -236.363, 1058.87, 54.3133, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 11, -236.71, 1072.11, 54.3082, 'Horde - Stair of Destiny'),
(@DARKSPEAR_AXE_THROWER_ENTRY, 12, -236.72, 1106.10, 41.6667, 'Horde - Stair of Destiny');

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (18968, 18967);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18968, 18967) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1896800,1896801,1896802,1896803, 1896700, 1896701, 1896702, 1896703) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18968, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Horde Portal Invisible Stalker - Ooc - Set active'),
(18968, 0, 1, 0, 1, 0, 100, 0, 150000, 150000, 25000, 25000, 87, 1896800, 1896801, 1896802, 1896803, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Horde Portal Invisible Stalker - Ooc - Random action list'),
(1896800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @UNDERCITY_MAGE_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Horde Portal Invisible Stalker - Action list - Summon'),
(1896801, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @ORGRIMMAR_SHAMAN_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Horde Portal Invisible Stalker - Action list - Summon'),
(1896802, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @ORGRIMMAR_GRUNT_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Horde Portal Invisible Stalker - Action list - Summon'),
(1896803, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @DARKSPEAR_AXE_THROWER_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Horde Portal Invisible Stalker - Action list - Summon'),
(18967, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Alliance Portal Invisible Stalker - Ooc - Set active'),
(18967, 0, 1, 0, 1, 0, 100, 0, 150000, 150000, 25000, 25000, 87, 1896700, 1896701, 1896702, 1896703, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Alliance Portal Invisible Stalker - Ooc - Random action list'),
(1896700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @STORMWIND_MAGE_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Alliance Portal Invisible Stalker - Action list - Summon'),
(1896701, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @STORMWIND_SOLDIER_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Alliance Portal Invisible Stalker - Action list - Summon'),
(1896702, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @IRONFORGE_PALADIN_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Alliance Portal Invisible Stalker - Action list - Summon'),
(1896703, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @DARNASSIAN_ARCHER_ENTRY, 3, 180000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Assault Alliance Portal Invisible Stalker - Action list - Summon');
