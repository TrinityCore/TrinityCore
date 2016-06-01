-- Cloud Prince SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45917;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 45917 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45917, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 88081, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - On Aggro - Cast 'Whipping Winds'"),
(45917, 0, 1, 0, 0, 0, 100, 0, 5000, 10000, 5000, 10000, 11, 88073, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - In Combat - Cast 'Starfall'"),
(45917, 0, 2, 0, 0, 0, 100, 0, 10000, 15000, 10000, 15000, 11, 88075, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Cloud Prince - In Combat - Cast 'Typhoon'"),
(45917,0,3,0,17,0,100,0,47238,0,0,0,13,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cloud Prince - On Summoned Whipping Winds - Add Threat 1 Percent."),
(45917,0,4,0,17,0,100,0,47238,0,0,0,80,45917*100+00,2,0,0,0,0,7,0,0,0,0,0,0,0,"Cloud Prince - On Summoned Whipping Winds - Run Script."),
(45917,0,5,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,24,0,0,0,0,0,0,0,"Cloud Prince - On Evade - Set Data 1 1 on Full Threat List for despawn full whipping winds list.");

-- Cloud Prince Actionlist SAI
SET @ENTRY := 4591700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,500,500,500,500,64,1,0,0,0,0,0,24,0,0,0,0,0,0,0,"Cloud Prince - On Script - Store Target List Full Threat List.");

-- Whipping Wind SAI
SET @ENTRY := 47238;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 47238;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 0, 0, 1500, 1500, 11, 88080, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Whipping Wind - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,38,0,100,0,1,1,1000,1000,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whipping Wind - On Data Set 1 1 - Force Despawn.");

-- Young Storm Dragon SAI
SET @ENTRY := 45919;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 45919;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,91,3,3,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Reset - Remove Hover and Always Stand Unit Byte Flag."),
(@ENTRY,0,2,0,25,0,100,0,0,0,0,0,60,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Reset - Set Fly Off."),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Reset - Set React Passive."),
(@ENTRY,0,4,0,4,0,100,0,0,0,0,0,11,88201,1,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Aggro - Cast Healing Well."),
(@ENTRY,0,5,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Combat - Set Data 1 1."),
(@ENTRY,0,6,0,38,0,100,1,1,1,0,0,60,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Young Storm Dragon - On Data Set 1 1 - Set Fly On."),
(@ENTRY,0,7,0,38,0,100,1,1,1,0,0,90,3,3,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Data Set 1 1 - Set Hover Byte."),
(@ENTRY,0,8,0,38,0,100,1,1,1,0,0,114,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Data Set 1 1 - Rise Up on 10 Yards."),
(@ENTRY,0,9,0,4,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Reset - Set React Aggressive."),
(@ENTRY,0,10,0,0,0,100,1,6000,6000,0,0,80,@ENTRY*100+00,1,0,0,0,0,1,0,0,0,0,0,0,0,"Young Storm Dragon - On Combat - Run Script.");

-- Young Storm Dragon Actionlist SAI
SET @ENTRY := 4591900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,88194,0,0,0,0,0,2,0,0,0,0,0,0,0,"Young Storm Dragon - On Script - Cast Chilling Blast.");
