-- Nexus-King Salhadaar SAI
SET @ENTRY := 20454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,3,100,1,1000,1000,1000,1000,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Out of Combat - Remove Flag Not Selectable (Phase 4) (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,1,1000,1000,1000,1000,2,1796,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Out of Combat - Set Faction 1796 (Phase 4) (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Out of Combat - Say Line 0 (Phase 4)"),
(@ENTRY,0,3,0,0,0,100,0,5000,10000,15000,25000,11,36533,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - In Combat - Cast 'Gravity Flux'"),
(@ENTRY,0,4,5,2,0,100,1,5,25,0,0,11,36848,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Between 5-25% Health - Cast 'Mirror Image' (No Repeat)"),
(@ENTRY,0,5,0,61,0,100,0,5,25,0,0,11,36847,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - Between 5-25% Health - Cast 'Mirror Image' (No Repeat)"),
(@ENTRY,0,6,0,0,0,100,0,15000,25000,10000,30000,11,36527,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nexus-King Salhadaar - In Combat - Cast 'Stasis'"),
(@ENTRY,0,7,8,7,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Evade - Set Faction 35"),
(@ENTRY,0,8,10,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,21425,20,0,0,0,0,0,"Nexus-King Salhadaar - On Evade - Set Data 1 1"),
(@ENTRY,0,9,0,38,0,100,0,1,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Data Set 1 1 - Increment Phase"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Evade - Set Event Phase 0");

-- Nexus-King Salhadaar SAI
SET @ENTRY := 21425;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Nexus-King Salhadaar - On Just Summoned - Start Attacking"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nexus-King Salhadaar - On Data Set 1 1 - Despawn Instant");

-- remove randmmovement
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE  `guid` IN (73277, 73278, 73279);

-- Salaadin's Energy Ball SAI
SET @ENTRY := 20769;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,32566,0,0,0,0,0,1,0,0,0,0,0,0,0,"Salaadin's Energy Ball - On Respawn - Cast 'Purple Banish State' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,5000,5000,0,0,11,35515,0,0,0,0,0,9,20454,0,200,0,0,0,0,"Salaadin's Energy Ball - Out of Combat - Cast 'Salaadin's Tesla'"),
(@ENTRY,0,2,0,38,0,100,0,1,1,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Salaadin's Energy Ball - On Data Set 1 1 - Despawn In 100 ms");

-- Protectorate Disruptor SAI
SET @ENTRY := 184561;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,1,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,20769,10,0,0,0,0,0,"Protectorate Disruptor - Out of Combat - Set Data 1 1 (No Repeat)"),
(@ENTRY,1,1,0,1,0,100,1,1000,1000,0,0,45,1,1,0,0,0,0,10,72462,20454,0,0,0,0,0,"Protectorate Disruptor - Out of Combat - Set Data 1 1 (No Repeat)");

DELETE FROM `creature_text` WHERE `entry` = 20454 AND `groupid` = 0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`comment`, `BroadcastTextId`) VALUES
(20454, 0, 0, "Prepare to enter oblivion, meddlers. You have unleashed a god!", 14, 0, 100, "Nexus-King Salhadaar", 18443);

DELETE FROM `creature_text` WHERE `entry` = 20454 AND `groupid` = 0;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`comment`, `BroadcastTextID`) VALUES
(20454, 0, 0, "Prepare to enter oblivion, meddlers. You have unleashed a god!", 14, 0, 100, "Nexus-King Salhadaar", 18443);

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=35515;
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,35515,64,'Ignore LOS on Salaadin\'s Tesla');
