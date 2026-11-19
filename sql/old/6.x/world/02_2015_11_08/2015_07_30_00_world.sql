-- 
SET @CGUID := 25;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 44865, 1, 1, 1643.72, -4443.32, 18.61603, 1.570796, 120, 0, 0), -- Auctioneer Fazdran (Area: Valley of Strength)
(@CGUID+1, 44867, 1, 1, 1640.17, -4445.12, 18.61683, 2.251475, 120, 0, 0), -- Auctioneer Ralinza (Area: Valley of Strength)
(@CGUID+2, 44866, 1, 1, 1637.42, -4448.21, 18.61663, 2.408554, 120, 0, 0), -- Auctioneer Drezmit (Area: Valley of Strength)
(@CGUID+3, 44868, 1, 1, 1635.46, -4451.19, 18.61623, 3.176499, 120, 0, 0); -- Auctioneer Xifa (Area: Valley of Strength)

-- Auctioneer Fazdran SAI
SET @ENTRY := 44865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Fazdran - Out of Combat - Play Random Emote (273, 5)");

-- Auctioneer Ralinza SAI
SET @ENTRY := 44867;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Ralinza - Out of Combat - Play Random Emote (273, 5)");

-- Auctioneer Drezmit SAI
SET @ENTRY := 44866;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Drezmit - Out of Combat - Play Random Emote (273, 5)");

-- Auctioneer Xifa SAI
SET @ENTRY := 44868;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,15000,10000,15000,10,273,5,0,0,0,0,1,0,0,0,0,0,0,0,"Auctioneer Xifa - Out of Combat - Play Random Emote (273, 5)");

-- grundtalk
DELETE FROM `creature_addon` WHERE `guid` IN (310823, 310821,287204,287201);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(310823,0,0,0,1,1, ''),
(310821,0,0,0,1,1, ''),
(287204,0,0,0,1,1, ''),
(287201,0,0,0,1,1, '');

-- Doyo'da SAI
SET @ENTRY := 5613;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,1,11,0,0,0,0,0,0,0,0,0,0,0,0,"Doyo'da - Out of Combat - Play Random Emote (1, 11)");
