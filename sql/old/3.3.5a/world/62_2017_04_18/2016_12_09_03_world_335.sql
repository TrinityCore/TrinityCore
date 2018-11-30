-- [Q] Challenge to the Black Flight -- http://wotlk.openwow.com/quest=11162
-- Smolderwing SAI
SET @ENTRY := 23789;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderwing - On Just Created - Run Script"),
(@ENTRY,0,1,0,34,0,100,0,0,1,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Smolderwing - On Reached Point 1 - Run Script");

-- Actionlist SAI
SET @ENTRY := 2378900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,18,770,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Flags Not Attackable & Immune To Players & Immune To NPC's"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,3000,3000,0,0,69,1,0,0,0,0,0,20,186335,100,0,0,0,0,0,"On Script - Move To Closest Gameobject 'Stonemaul Banner'");

-- Actionlist SAI
SET @ENTRY := 2378901;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,42433,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Smolderwing Fire Breath'"),
(@ENTRY,9,1,0,0,0,100,0,3000,3000,0,0,19,770,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Remove Flags Not Attackable & Immune To Players & Immune To NPC's"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"On Script - Start Attacking");

DELETE FROM `creature_text` WHERE `entry`=23789;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(23789, 0, 0, 'Pitiful mortal, Onyxia answers to no one!', 14, 0, 100, 0, 0, 0, 22285, 'Smolderwing'),
(23789, 1, 0, 'Your pathetic challenge has not gone unnoticed. I shall enjoy toying with you before you die.', 14, 0, 100, 0, 0, 0, 22286, 'Smolderwing');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=42425;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,42425,0,0,29,0,23789,200,0,1,0,0,"","Cannot cast Plant Stonemaul Banner if Smolderwing is in range");
