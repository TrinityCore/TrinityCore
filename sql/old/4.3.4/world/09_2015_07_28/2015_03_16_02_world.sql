-- 
UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry`=11191;

-- Lilith the Lithe SAI 
SET @ENTRY := 11191;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,28618,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lilith the Lithe - On Quest 'Boulder Delivery' Finished - Run Script");

-- Actionlist SAI
SET @ENTRY := 1119100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,12,49149,2,90000,0,0,0,8,0,0,0,6775.828613,-4670.644531,723.81134,2.01846,"On Script - Summon Creature 'Instant Boulder'"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,11,91667,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Bolder'"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,11,91667,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Bolder'"),
(@ENTRY,9,4,0,0,0,100,0,1000,1000,0,0,11,91667,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Bolder'"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,11,91671,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Bolder'"),
(@ENTRY,9,6,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1");

-- Instant Boulder SAI
SET @ENTRY := 49149;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,11,91601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instant Boulder - On Just Summoned - Cast 'Bolder'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instant Boulder - On Just Summoned - Despawn In 6000 ms");

DELETE FROM `creature_text` WHERE `entry`=11191;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(11191, 0, 0, 'Watch and weep.', 12, 0, 100, 0, 0, 0, 49258, 0, 'Lilith the Lithe'),
(11191, 1, 0, 'You see? Nothing beats the crushing power of my hammers.', 12, 0, 100, 0, 0, 0, 49259, 0, 'Lilith the Lithe');
