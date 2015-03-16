-- 
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=11192;

-- Kilram SAI
SET @ENTRY := 11192;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,28626,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kilram - On Quest 'Tree Delivery' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 1119200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,12,49191,2,60000,0,0,0,8,0,0,0,6775.828613,-4670.644531,723.81134,2.01846,"On Script - Summon Creature 'Kilram's Tree'"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,11,91827,0,0,0,0,0,19,49191,20,0,0,0,0,0,"On Script - Cast 'Bolder'"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

-- Kilram's Tree SAI
SET @ENTRY := 49191;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,49191,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kilram's Tree - On Just Summoned - Cast '7th Legion Chain Gun'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kilram's Tree - On Just Summoned - Run Script");

-- Actionlist SAI
SET @ENTRY := 4919100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,6000,6000,0,0,5,445,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kilram's Tree - On Script - Play Emote 445"),
(@ENTRY,9,1,0,0,0,100,0,12000,12000,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kilram's Tree - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `entry`=11192;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(11192, 0, 0, 'Why flail around when all you need...', 12, 0, 100, 0, 0, 0, 49308, 0, 'Kilram\'s Tree'),
(11192, 1, 0, '...is just one CHOP!', 12, 0, 100, 0, 0, 0, 49309, 0, 'Kilram\'s Tree');
