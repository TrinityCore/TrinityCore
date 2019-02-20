-- Tuluun <Shaman Trainer> + Draenei Artificer Hate Conversation -- http://wotlk.openwow.com/npc=17212 + http://wotlk.openwow.com/npc=17228

UPDATE `creature` SET `position_x`=-4149.24, `position_y`=-12465, `position_z`=45.3466, `orientation`=5.67608 WHERE  `guid`=61962;

-- Draenei Artificer SAI
SET @ENTRY := 17228;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,20000,176000,176000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - Out of Combat - Run Script"),
(@ENTRY,0,1,0,1,0,100,0,65000,65000,176000,176000,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - Out of Combat - Run Script"),
(@ENTRY,0,2,0,1,0,100,0,118000,118000,176000,176000,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 1722800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 0"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,10,61721,17212,0,0,0,0,0,"Draenei Artificer - On Script - Set Orientation Closest Creature 'Tuluun'"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,4000,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Say Line 1"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.67608,"Draenei Artificer - On Script - Set Orientation 5.67608"),
(@ENTRY,9,5,0,0,0,100,0,2000,2000,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 234");

-- Actionlist SAI
SET @ENTRY := 1722801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 0"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,10,61721,17212,0,0,0,0,0,"Draenei Artificer - On Script - Set Orientation Closest Creature 'Tuluun'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Say Line 2"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.67608,"Draenei Artificer - On Script - Set Orientation 5.67608"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 234");

-- Actionlist SAI
SET @ENTRY := 1722802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Run Off"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4160.31,-12458.7,44.5919,2.08552,"Draenei Artificer - On Script - Move To Position"),
(@ENTRY,9,3,0,0,0,100,0,8000,8000,0,0,66,0,0,0,0,0,0,10,61721,17212,0,0,0,0,0,"Draenei Artificer - On Script - Set Orientation Closest Creature 'Tuluun'"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,3,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Say Line 3"),
(@ENTRY,9,5,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4149.24,-12465,45.3466,5.67608,"Draenei Artificer - On Script - Move To Position"),
(@ENTRY,9,6,0,0,0,100,0,7000,7000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.67608,"Draenei Artificer - On Script - Set Orientation 5.67608"),
(@ENTRY,9,7,0,0,0,100,0,2000,2000,0,0,17,234,0,0,0,0,0,1,0,0,0,0,0,0,0,"Draenei Artificer - On Script - Set Emote State 234");

DELETE FROM `creature_text` WHERE `entry`=17228;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(17228, 0, 0, 'How can I be expected to get any work done with that thing spreading its heresy?', 12, 0, 100, 0, 0, 0, 14383, 'Draenei Artificer'),
(17228, 1, 0, '%s sighs disgustedly as he turns back to his work.', 16, 0, 100, 0, 0, 0, 14384, 'Draenei Artificer'),
(17228, 2, 0, 'Turning to face Tuluun, the %s sneers contemptuously.', 16, 0, 100, 0, 0, 0, 14381, 'Draenei Artificer'),
(17228, 3, 0, 'We do not need your kind here.', 12, 0, 100, 0, 0, 0, 14382, 'Draenei Artificer');
