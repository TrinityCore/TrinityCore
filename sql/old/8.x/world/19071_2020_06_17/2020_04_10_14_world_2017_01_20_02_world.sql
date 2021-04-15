-- Lord Thorval - Rework Textevent
SET @NPC := 128506;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`, `orientation`, `delay`) VALUES
(@PATH, 1, 2527.73, -5549.21, 377.036, 3.735, 30000),
(@PATH, 2, 2524.61, -5545.03, 377.027, 2.21325, 0),
(@PATH, 3, 2524.61, -5545.03, 377.027, 4.06051, 15000),
(@PATH, 4, 2530.44, -5554.25, 377.056, 5.26204, 0),
(@PATH, 5, 2530.44, -5554.25, 377.056, 3.50275, 15000),
(@PATH, 6, 2524.61, -5545.03, 377.027, 2.21325, 0),
(@PATH, 7, 2524.61, -5545.03, 377.027, 4.06051, 15000),
(@PATH, 8, 2530.44, -5554.25, 377.056, 5.26204, 1000),
(@PATH, 9, 2524.61, -5545.03, 377.027, 2.21325, 1000),
(@PATH, 10, 2530.44, -5554.25, 377.056, 5.26204, 1000),
(@PATH, 11, 2524.61, -5545.03, 377.027, 2.21325, 0),
(@PATH, 12, 2524.61, -5545.03, 377.027, 4.06051, 15000),
(@PATH, 13, 2527.73, -5549.21, 377.036, 2.18866, 0),
(@PATH, 14, 2527.73, -5549.21, 377.036, 3.735, 330000);

-- Lord Thorval SAI
SET @ENTRY := 28472;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,34,0,100,0,2,2,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Reached Point 2 - Run Script"),
(@ENTRY,0,1,0,34,0,100,0,2,4,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Reached Point 4 - Run Script"),
(@ENTRY,0,2,0,34,0,100,0,2,6,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Reached Point 6 - Run Script"),
(@ENTRY,0,3,0,34,0,100,0,2,7,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Reached Point 7 - Run Script"),
(@ENTRY,0,4,0,34,0,100,0,2,8,0,0,80,@ENTRY*100+04,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Reached Point 8 - Run Script"),
(@ENTRY,0,5,0,34,0,100,0,2,9,0,0,80,@ENTRY*100+05,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Reached Point 9 - Run Script"),
(@ENTRY,0,6,0,34,0,100,0,2,11,0,0,80,@ENTRY*100+06,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Reached Point 11 - Run Script");

-- Actionlist SAI
SET @ENTRY := 2847200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 0");

-- Actionlist SAI
SET @ENTRY := 2847201;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,9000,9000,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 2847202;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,3,9000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 3"),
(@ENTRY,9,1,0,0,0,100,0,9000,9000,0,0,1,4,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 2847203;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,5,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 5");

-- Actionlist SAI
SET @ENTRY := 2847204;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,6,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 6");

-- Actionlist SAI
SET @ENTRY := 2847205;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,7,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 7");

-- Actionlist SAI
SET @ENTRY := 2847206;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,8,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Thorval - On Script - Say Line 8");

DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(@ENTRY, 0, 0, 'As disciples of blood, you strive to master the very lifeforce of your enemies.',                                       12, 0, 100, 1, 0, 0, 'Lord Thorval', 29867),
(@ENTRY, 1, 0, 'Be it by blade or incantation, blood feeds our attacks and weakens our foes.',                                          12, 0, 100, 1, 0, 0, 'Lord Thorval', 29868),
(@ENTRY, 2, 0, 'True masters learn to make blood serve more than just their strength in battle.',                                       12, 0, 100, 1, 0, 0, 'Lord Thorval', 29869),
(@ENTRY, 3, 0, 'Stripping energy from our foes, both fighting and fallen, allows us to persevere where lesser beigns falls exhausted.', 12, 0, 100, 1, 0, 0, 'Lord Thorval', 29870),
(@ENTRY, 4, 0, 'And every foe that falls, energy sapped and stolen, only further fuels our assault.',                                   12, 0, 100, 1, 0, 0, 'Lord Thorval', 29871),
(@ENTRY, 5, 0, 'As masters of blood, we know battle without end...',                                                                    12, 0, 100, 1, 0, 0, 'Lord Thorval', 29872),
(@ENTRY, 6, 0, 'We know hunger never to be quenched...',                                                                                12, 0, 100, 1, 0, 0, 'Lord Thorval', 29873),
(@ENTRY, 7, 0, 'We know power never to be overcome...',                                                                                 12, 0, 100, 1, 0, 0, 'Lord Thorval', 29874),
(@ENTRY, 8, 0, 'As masters of blood, we are masters of life and death itself. Agains us, even hope falls drained and lifeless.',        12, 0, 100, 1, 0, 0, 'Lord Thorval', 29875);
