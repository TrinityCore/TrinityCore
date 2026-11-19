-- 
-- DB/Pathing/Emotes: Orgrimmar - The Valley of Spirits/Wisdom + The Drag + Valley of Strength
-- Conjurer Mixli SAI
SET @ENTRY := 45714;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Conjurer Mixli - Out of Combat - Play Emote 1");

-- shadowchannel 
-- Unjari Feltongue SAI
SET @ENTRY := 45138;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,10000,10000,11,45104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unjari Feltongue - Out of Combat - Cast 'Shadow Channelling'");

-- Kazrali the Witch SAI
SET @ENTRY := 45720;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kazrali the Witch - Out of Combat - Play Emote 1");

-- Goblin Bitchfight
DELETE FROM `creature_addon` WHERE `guid` IN (287013, 287010);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(287013, 0, 0, 0, 257, 0, '42648'),
(287010, 0, 0, 0, 257, 0, '42648');

-- Off-Duty Siegeworker SAI
SET @ENTRY := 45830;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,396,273,11,5,25,15,1,0,0,0,0,0,0,0,"Off-Duty Siegeworker - Out of Combat - Play Random Emote (396, 273, 11, 5, 25, 15)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=45830;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`,`NegativeCondition`) VALUES
(22,1,45830,0,0,1,1,42648,0,0,0,"","Off-Duty Siegeworker - Only run SAI without Sleep aura",1);

-- ballonflight
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=41266;

-- the cook is always the killer
-- Zarbo Porkpatty SAI
SET @ENTRY := 45550;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Zarbo Porkpatty - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 4555000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.722174,"On Script - Set Orientation 5,722174"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,10000,10000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.134460,"On Script - Set Orientation 1,134460"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Kazit SAI
SET @ENTRY := 46080;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,396,273,11,5,25,15,1,0,0,0,0,0,0,0,"Kazit - Out of Combat - Play Random Emote (396, 273, 11, 5, 25, 15)");

-- Boss Mida SAI
SET @ENTRY := 46078;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,396,273,11,5,25,15,1,0,0,0,0,0,0,0,"Boss Mida - Out of Combat - Play Random Emote (396, 273, 11, 5, 25, 15)");

-- Bruiser Janx SAI
SET @ENTRY := 45709;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,396,273,11,5,25,15,1,0,0,0,0,0,0,0,"Bruiser Janx - Out of Combat - Play Random Emote (396, 273, 11, 5, 25, 15)");

-- darkspeeremotes
-- Darkspear Headhunter SAI
SET @ENTRY := 45015;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,8000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkspear Headhunter - Out of Combat - Play Emote 1");

-- Huntress Kuzari SAI
SET @ENTRY := 45023;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,8000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huntress Kuzari - Out of Combat - Play Emote 1");

-- Berserker Zanga SAI
SET @ENTRY := 45019;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,8000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Berserker Zanga - Out of Combat - Play Emote 1");

-- frogmovement
UPDATE `creature` SET `spawndist`=8, `MovementType`=1 WHERE  `id`=1420;

-- danceing
-- Batamsi SAI
SET @ENTRY := 45008;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Batamsi - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 4500800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 10"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- cook
-- Zamja SAI
SET @ENTRY := 3399;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Zamja - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 339900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,28,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 28"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- hammer
DELETE FROM `creature_template_addon` WHERE `entry`=44781;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(44781,0,0,0,1,233, '');

-- kürschnern
-- Rento SAI
SET @ENTRY := 44782;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,44782000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Rento - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 4478200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Searn Firewarder SAI
SET @ENTRY := 5892;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,3000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searn Firewarder - Out of Combat - Play Emote 1");

-- Sagorne Creststrider SAI
SET @ENTRY := 13417;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,3000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sagorne Creststrider - Out of Combat - Play Emote 1");

-- Kardris Dreamseeker SAI
SET @ENTRY := 3344;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,3000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kardris Dreamseeker - Out of Combat - Play Emote 1");

-- standup
DELETE FROM `creature_addon` WHERE `guid` IN (311047, 311035, 311048, 286766);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(311047,0,0,0,1,0, ''),
(311035,0,0,0,1,0, ''),
(311048,0,0,0,1,0, ''),
(286766,0,0,0,1,0, '');
-- Nerog SAI
SET @ENTRY := 46716;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerog - Out of Combat - Play Emote 1");

-- Zilzibin Drumlore SAI
SET @ENTRY := 7010;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zilzibin Drumlore - Out of Combat - Play Emote 1");

-- talking  + no
-- Seer Liwatha SAI
SET @ENTRY := 44735;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,1,274,0,0,0,0,1,0,0,0,0,0,0,0,"Seer Liwatha - Out of Combat - Play Random Emote (1, 274)");

-- Sunwalker Atohmo SAI
SET @ENTRY := 44725;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,1,274,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwalker Atohmo - Out of Combat - Play Random Emote (1, 274)");

-- Nahu Ragehoof SAI
SET @ENTRY := 44723;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,1,274,0,0,0,0,1,0,0,0,0,0,0,0,"Nahu Ragehoof - Out of Combat - Play Random Emote (1, 274)");

-- Nohi Plainswalker SAI
SET @ENTRY := 44743;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,1,274,0,0,0,0,1,0,0,0,0,0,0,0,"Nohi Plainswalker - Out of Combat - Play Random Emote (1, 274)");

-- Sahi Cloudsinger SAI
SET @ENTRY := 44740;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,1,274,0,0,0,0,1,0,0,0,0,0,0,0,"Sahi Cloudsinger - Out of Combat - Play Random Emote (1, 274)");

-- Shalla Whiteleaf SAI
SET @ENTRY := 44726;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,1,274,0,0,0,0,1,0,0,0,0,0,0,0,"Shalla Whiteleaf - Out of Combat - Play Random Emote (1, 274)");

-- kruscteln
-- Kor'geld SAI
SET @ENTRY := 3348;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'geld - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 334800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

-- Whuut SAI
SET @ENTRY := 11046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Whuut - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 1104600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whuut - On Script - Set Emote State 69"),
(@ENTRY,9,1,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whuut - On Script - Set Emote State 0");

-- Dran Droffers SAI
SET @ENTRY := 6986;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,15,274,0,0,0,0,1,0,0,0,0,0,0,0,"Dran Droffers - Out of Combat - Play Random Emote (15, 274)");

-- Malton Droffers SAI
SET @ENTRY := 6987;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,3000,2000,3000,10,5,274,0,0,0,0,1,0,0,0,0,0,0,0,"Malton Droffers - Out of Combat - Play Random Emote (5, 274)");

-- Marud SAI
SET @ENTRY := 47247;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marud - On Reset - Set Emote State 69");

-- Gordul SAI
SET @ENTRY := 47233;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,396,273,396,0,0,0,1,0,0,0,0,0,0,0,"Gordul - Out of Combat - Play Random Emote (396, 273, 396)");

-- Ormok SAI
SET @ENTRY := 3328;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,396,273,396,0,0,0,1,0,0,0,0,0,0,0,"Ormok - Out of Combat - Play Random Emote (396, 273, 396)");

-- Gest SAI
SET @ENTRY := 3327;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,3000,5000,3000,5000,10,396,273,396,0,0,0,1,0,0,0,0,0,0,0,"Gest - Out of Combat - Play Random Emote (396, 273, 396)");

SET @NPC := 286787;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1847.02,`position_y`=-4319.55,`position_z`=-15.45576 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1847.02,-4319.55,-15.45576,0,0,0,0,100,0),
(@PATH,2,1847.02,-4319.55,-15.45576,0.7330383,5000,0,0,100,0),
(@PATH,3,1838.115,-4318.975,-15.21886,0,0,0,0,100,0),
(@PATH,4,1836.71,-4318.9,-15.48197,2.338741,0,0,0,100,0),
(@PATH,5,1838.385,-4319.755,-15.22519,0,0,0,0,100,0),
(@PATH,6,1846.06,-4324.11,-15.46842,3.595378,5000,0,0,100,0),
(@PATH,7,1844.135,-4329.245,-15.21449,0,0,0,0,100,0),
(@PATH,8,1843.21,-4331.38,-15.46056,4.729842,5000,0,0,100,0),
(@PATH,9,1844.135,-4329.245,-15.21449,0,0,0,0,100,0),
(@PATH,10,1846.06,-4324.11,-15.46842,3.595378,5000,0,0,100,0),
(@PATH,11,1847.02,-4319.55,-15.45576,0,0,0,0,100,0),
(@PATH,12,1847.02,-4319.55,-15.45576,0.7330383,5000,0,0,100,0),
(@PATH,13,1838.115,-4318.975,-15.21886,0,0,0,0,100,0),
(@PATH,14,1836.71,-4318.9,-15.48197,2.338741,5000,0,0,100,0),
(@PATH,15,1838.385,-4319.755,-15.22519,0,0,0,0,100,0),
(@PATH,16,1846.06,-4324.11,-15.46842,3.595378,5000,0,0,100,0),
(@PATH,17,1849.485,-4399.909,120.7372,0,0,0,0,100,0),
(@PATH,18,1851.735,-4397.409,119.2372,0,0,0,0,100,0),
(@PATH,19,1853.235,-4395.659,118.2372,0,0,0,0,100,0),
(@PATH,20,1853.735,-4395.659,117.7372,0,0,0,0,100,0),
(@PATH,21,1844.135,-4329.245,-15.21449,0,0,0,0,100,0),
(@PATH,22,1843.21,-4331.38,-15.46056,4.729842,5000,0,0,100,0),
(@PATH,23,1844.135,-4329.245,-15.21449,0,0,0,0,100,0),
(@PATH,24,1846.06,-4324.11,-15.46842,3.595378,5000,0,0,100,0);

SET @NPC := 310937;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1748.64,`position_y`=-4326.93,`position_z`=6.200298 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1748.64,-4326.93,6.200298,0,0,0,0,100,0),
(@PATH,2,1750.313,-4320.861,6.197538,0,0,0,0,100,0),
(@PATH,3,1750.249,-4321.09,6.197643,0.8726646,5000,0,0,100,0),
(@PATH,4,1743.22,-4322.41,6.206087,0,0,0,0,100,0),
(@PATH,5,1750.313,-4320.861,6.197538,0,0,0,0,100,0),
(@PATH,6,1750.313,-4320.861,6.197538,0.8726646,0,0,0,100,0),
(@PATH,7,1750.313,-4320.861,6.197538,0.8726646,5000,0,0,100,0),
(@PATH,8,1748.64,-4326.93,6.200298,0,0,0,0,100,0);

SET @NPC := 310955;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1800.63,`position_y`=-4344.018,`position_z`=-10.65129 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1800.63,-4344.018,-10.65129,0,0,0,0,100,0),
(@PATH,2,1800.13,-4342.018,-10.65129,0,0,0,0,100,0),
(@PATH,3,1797.486,-4330.341,-10.85035,0,0,0,0,100,0),
(@PATH,4,1794.486,-4323.841,-10.85035,0,0,0,0,100,0),
(@PATH,5,1793.736,-4322.091,-10.10035,0,0,0,0,100,0),
(@PATH,6,1791.486,-4316.841,-6.850345,0,0,0,0,100,0),
(@PATH,7,1788.986,-4311.341,-4.100345,0,0,0,0,100,0),
(@PATH,8,1787.486,-4307.841,-1.600345,0,0,0,0,100,0),
(@PATH,9,1785.661,-4303.881,0.6941774,0,0,0,0,100,0),
(@PATH,10,1784.411,-4302.631,1.944177,0,0,0,0,100,0),
(@PATH,11,1780.661,-4299.131,4.944178,0,0,0,0,100,0),
(@PATH,12,1779.411,-4298.131,5.694178,0,0,0,0,100,0),
(@PATH,13,1779.501,-4297.958,5.53544,0,0,0,0,100,0),
(@PATH,14,1780.501,-4298.958,4.78544,0,0,0,0,100,0),
(@PATH,15,1784.251,-4302.708,1.78544,0,0,0,0,100,0),
(@PATH,16,1784.525,-4302.977,1.662452,0,0,0,0,100,0),
(@PATH,17,1786.025,-4304.227,0.4124517,0,0,0,0,100,0),
(@PATH,18,1787.525,-4307.727,-1.837548,0,0,0,0,100,0),
(@PATH,19,1789.025,-4311.477,-4.087548,0,0,0,0,100,0),
(@PATH,20,1791.275,-4316.477,-7.087548,0,0,0,0,100,0),
(@PATH,21,1793.775,-4321.977,-10.08755,0,0,0,0,100,0),
(@PATH,22,1794.525,-4323.977,-11.08755,0,0,0,0,100,0),
(@PATH,23,1797.615,-4330.72,-11.03062,0,0,0,0,100,0),
(@PATH,24,1800.115,-4342.22,-10.53062,0,0,0,0,100,0),
(@PATH,25,1800.054,-4342.425,-10.50339,0,0,0,0,100,0),
(@PATH,26,1800.554,-4344.425,-10.50339,0,0,0,0,100,0),
(@PATH,27,1799.054,-4346.425,-10.50339,0,0,0,0,100,0),
(@PATH,28,1795.304,-4350.175,-11.50339,0,0,0,0,100,0),
(@PATH,29,1790.934,-4355.938,-12.91172,0,0,0,0,100,0),
(@PATH,30,1790.934,-4357.188,-13.41172,0,0,0,0,100,0),
(@PATH,31,1790.184,-4363.688,-14.66172,0,0,0,0,100,0),
(@PATH,32,1790.067,-4363.927,-14.67502,0,0,0,0,100,0),
(@PATH,33,1790.067,-4364.677,-15.17502,0,0,0,0,100,0),
(@PATH,34,1790.317,-4366.677,-15.92502,0,0,0,0,100,0),
(@PATH,35,1790.567,-4367.927,-15.92502,0,0,0,0,100,0),
(@PATH,36,1790.817,-4369.927,-15.92502,0,0,0,0,100,0),
(@PATH,37,1790.817,-4371.177,-15.92502,0,0,0,0,100,0),
(@PATH,38,1791.567,-4377.427,-16.42502,0,0,0,0,100,0),
(@PATH,39,1792.904,-4383.558,-17.30309,0,0,0,0,100,0),
(@PATH,40,1793.654,-4384.058,-17.30309,0,0,0,0,100,0),
(@PATH,41,1798.426,-4387.68,-17.53324,0,0,0,0,100,0),
(@PATH,42,1798.426,-4387.18,-17.28324,0,0,0,0,100,0),
(@PATH,43,1798.945,-4392.266,-17.35662,0,0,0,0,100,0),
(@PATH,44,1790.257,-4389.847,-16.64119,0,0,0,0,100,0),
(@PATH,45,1789.007,-4387.347,-16.64119,0,0,0,0,100,0),
(@PATH,46,1787.757,-4383.347,-16.64119,0,0,0,0,100,0),
(@PATH,47,1786.757,-4381.347,-16.39119,0,0,0,0,100,0),
(@PATH,48,1785.257,-4377.597,-15.89119,0,0,0,0,100,0),
(@PATH,49,1785.057,-4377.37,-16.02831,0,0,0,0,100,0),
(@PATH,50,1784.557,-4375.62,-15.77831,0,0,0,0,100,0),
(@PATH,51,1785.307,-4372.87,-15.77831,0,0,0,0,100,0),
(@PATH,52,1786.057,-4371.12,-16.02831,0,0,0,0,100,0),
(@PATH,53,1786.557,-4368.62,-16.02831,0,0,0,0,100,0),
(@PATH,54,1786.79,-4368.333,-15.72491,0,0,0,0,100,0),
(@PATH,55,1787.54,-4365.833,-15.47491,0,0,0,0,100,0),
(@PATH,56,1789.04,-4363.833,-14.72491,0,0,0,0,100,0),
(@PATH,57,1792.54,-4359.083,-13.47491,0,0,0,0,100,0),
(@PATH,58,1793.54,-4357.583,-12.97491,0,0,0,0,100,0),
(@PATH,59,1794.762,-4355.913,-12.41032,0,0,0,0,100,0),
(@PATH,60,1798.262,-4354.913,-11.66032,0,0,0,0,100,0),
(@PATH,61,1799.762,-4354.413,-10.91032,0,0,0,0,100,0),
(@PATH,62,1800.079,-4354.228,-10.46055,0,0,0,0,100,0),
(@PATH,63,1802.579,-4353.478,-10.21055,0,0,0,0,100,0),
(@PATH,64,1808.079,-4358.728,-9.960546,0,0,0,0,100,0),
(@PATH,65,1812.829,-4362.978,-9.210546,0,0,0,0,100,0),
(@PATH,66,1815.329,-4365.478,-9.210546,0,0,0,0,100,0),
(@PATH,67,1815.723,-4365.562,-8.855595,0,0,0,0,100,0),
(@PATH,68,1816.723,-4366.812,-8.605595,0,0,0,0,100,0),
(@PATH,69,1817.223,-4367.562,-8.605595,0,0,0,0,100,0),
(@PATH,70,1817.973,-4368.812,-8.355595,0,0,0,0,100,0),
(@PATH,71,1819.723,-4371.312,-7.605595,0,0,0,0,100,0),
(@PATH,72,1821.973,-4375.812,-6.355595,0,0,0,0,100,0),
(@PATH,73,1826.223,-4382.312,-4.355595,0,0,0,0,100,0),
(@PATH,74,1829.572,-4387.597,-1.480897,0,0,0,0,100,0),
(@PATH,75,1829.822,-4388.597,-0.9808973,0,0,0,0,100,0),
(@PATH,76,1830.322,-4390.097,-0.4808973,0,0,0,0,100,0),
(@PATH,77,1831.572,-4393.847,1.019103,0,0,0,0,100,0),
(@PATH,78,1832.322,-4395.847,1.769103,0,0,0,0,100,0),
(@PATH,79,1832.822,-4397.597,3.019103,0,0,0,0,100,0),
(@PATH,80,1832.948,-4397.764,3.117026,0,0,0,0,100,0),
(@PATH,81,1833.448,-4399.014,3.867026,0,0,0,0,100,0),
(@PATH,82,1833.948,-4400.764,4.367026,0,0,0,0,100,0),
(@PATH,83,1834.198,-4401.764,4.617026,0,0,0,0,100,0),
(@PATH,84,1834.948,-4404.264,5.117026,0,0,0,0,100,0),
(@PATH,85,1835.448,-4405.514,5.117026,0,0,0,0,100,0),
(@PATH,86,1835.217,-4404.634,5.304562,0,0,0,0,100,0),
(@PATH,87,1835.717,-4405.634,5.554562,0,0,0,0,100,0),
(@PATH,88,1835.967,-4406.634,5.554562,0,0,0,0,100,0),
(@PATH,89,1837.467,-4407.134,5.304562,0,0,0,0,100,0),
(@PATH,90,1843.717,-4408.384,5.054562,0,0,0,0,100,0),
(@PATH,91,1845.467,-4409.134,5.554562,0,0,0,0,100,0),
(@PATH,92,1846.717,-4409.384,5.554562,0,0,0,0,100,0),
(@PATH,93,1848.467,-4409.884,5.804562,0,0,0,0,100,0),
(@PATH,94,1855.436,-4411.794,6.632955,0,0,0,0,100,0),
(@PATH,95,1851.686,-4408.044,6.132955,0,0,0,0,100,0),
(@PATH,96,1849.686,-4406.294,6.132955,0,0,0,0,100,0),
(@PATH,97,1847.186,-4403.794,5.632955,0,0,0,0,100,0),
(@PATH,98,1844.936,-4402.044,5.632955,0,0,0,0,100,0),
(@PATH,99,1844.186,-4401.294,5.132955,0,0,0,0,100,0),
(@PATH,100,1840.936,-4398.044,4.382955,0,0,0,0,100,0),
(@PATH,101,1839.686,-4396.794,4.632955,0,0,0,0,100,0),
(@PATH,102,1838.186,-4395.294,3.632955,0,0,0,0,100,0),
(@PATH,103,1837.845,-4395.007,3.208251,0,0,0,0,100,0),
(@PATH,104,1835.845,-4393.257,1.958251,0,0,0,0,100,0),
(@PATH,105,1835.095,-4392.007,1.208251,0,0,0,0,100,0),
(@PATH,106,1833.345,-4389.257,-0.2917492,0,0,0,0,100,0),
(@PATH,107,1831.845,-4386.757,-1.541749,0,0,0,0,100,0),
(@PATH,108,1830.095,-4384.007,-2.791749,0,0,0,0,100,0),
(@PATH,109,1828.595,-4381.757,-4.041749,0,0,0,0,100,0),
(@PATH,110,1826.595,-4378.507,-5.291749,0,0,0,0,100,0),
(@PATH,111,1824.845,-4375.507,-6.541749,0,0,0,0,100,0),
(@PATH,112,1822.595,-4372.007,-7.041749,0,0,0,0,100,0),
(@PATH,113,1821.845,-4371.007,-7.291749,0,0,0,0,100,0),
(@PATH,114,1820.845,-4369.257,-7.791749,0,0,0,0,100,0),
(@PATH,115,1820.095,-4368.007,-8.041749,0,0,0,0,100,0),
(@PATH,116,1818.468,-4365.716,-8.782751,0,0,0,0,100,0),
(@PATH,117,1817.718,-4364.216,-9.032751,0,0,0,0,100,0),
(@PATH,118,1812.218,-4355.216,-9.782751,0,0,0,0,100,0),
(@PATH,119,1809.649,-4351.164,-10.26638,0,0,0,0,100,0),
(@PATH,120,1808.899,-4339.414,-10.51638,0,0,0,0,100,0),
(@PATH,121,1808.399,-4336.414,-10.76638,0,0,0,0,100,0),
(@PATH,122,1808.149,-4331.664,-10.76638,0,0,0,0,100,0),
(@PATH,123,1807.899,-4330.664,-10.76638,0,0,0,0,100,0),
(@PATH,124,1807.992,-4330.78,-10.87779,0,0,0,0,100,0),
(@PATH,125,1807.992,-4331.78,-10.87779,0,0,0,0,100,0),
(@PATH,126,1808.242,-4336.28,-10.87779,0,0,0,0,100,0),
(@PATH,127,1808.492,-4338.78,-10.62779,0,0,0,0,100,0);

SET @NPC := 286703;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1963.26,`position_y`=-4468.53,`position_z`=25.8766 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1963.26,-4468.53,25.8766,0,0,0,0,100,0),
(@PATH,2,1963.243,-4468.618,26.14035,0,0,0,0,100,0),
(@PATH,3,1962.993,-4469.618,26.14035,0,0,0,0,100,0),
(@PATH,4,1962.601,-4472.248,25.94987,0,0,0,0,100,0),
(@PATH,5,1961.351,-4472.998,25.94987,0,0,0,0,100,0),
(@PATH,6,1959.851,-4473.998,26.19987,0,0,0,0,100,0),
(@PATH,7,1956.24,-4474.94,26.0593,0,0,0,0,100,0),
(@PATH,8,1956.24,-4474.94,26.0593,2.86234,5000,0,0,100,0),
(@PATH,9,1960.57,-4475.36,26.24231,0,0,0,0,100,0),
(@PATH,10,1962.57,-4475.36,25.99231,0,0,0,0,100,0),
(@PATH,11,1963.725,-4469.7,26.15803,0,0,0,0,100,0),
(@PATH,12,1961.328,-4464.891,26.15244,0,0,0,0,100,0),
(@PATH,13,1963.38,-4460.72,25.91459,5.427974,5000,0,0,100,0);

SET @NPC := 311026;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1894.27,`position_y`=-4365.83,`position_z`=43.7109 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1894.27,-4365.83,43.7109,2.024582,5000,0,0,100,0),
(@PATH,2,1892.38,-4362,42.4427,0,0,0,0,100,0),
(@PATH,3,1888.38,-4357.25,40.1927,0,0,0,0,100,0),
(@PATH,4,1884.38,-4353,37.1927,0,0,0,0,100,0),
(@PATH,5,1879.13,-4345.5,33.1927,0,0,0,0,100,0),
(@PATH,6,1874.63,-4334.75,28.6927,0,0,0,0,100,0),
(@PATH,7,1872.13,-4325.25,25.4427,0,0,0,0,100,0),
(@PATH,8,1872.13,-4318,24.1927,0,0,0,0,100,0),
(@PATH,9,1874.88,-4312,23.9427,0,0,0,0,100,0),
(@PATH,10,1876.38,-4304.25,23.6927,0,0,0,0,100,0),
(@PATH,11,1874.49,-4298.67,23.1745,3.124139,5000,0,0,100,0),
(@PATH,12,1875.63,-4303.5,23.6927,0,0,0,0,100,0),
(@PATH,13,1877.38,-4316,24.1927,0,0,0,0,100,0),
(@PATH,14,1878.13,-4324.5,25.9427,0,0,0,0,100,0),
(@PATH,15,1880.88,-4332.75,28.9427,0,0,0,0,100,0),
(@PATH,16,1884.88,-4341.75,32.9427,0,0,0,0,100,0),
(@PATH,17,1889.13,-4350.25,37.4427,0,0,0,0,100,0),
(@PATH,18,1891.88,-4357,40.6927,0,0,0,0,100,0);

SET @NPC :=  286723;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2002.82,`position_y`=-4358.24,`position_z`=93.9059 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2002.82,-4358.24,93.9059,5.864306,5000,0,0,100,0),
(@PATH,2,2005.57,-4361.24,94.4059,0,0,0,0,100,0),
(@PATH,3,2003.32,-4364.24,94.1559,0,0,0,0,100,0),
(@PATH,4,1997.07,-4362.99,97.4059,0,0,0,0,100,0),
(@PATH,5,1991.07,-4361.49,102.4059,0,0,0,0,100,0),
(@PATH,6,1987.82,-4360.74,105.6559,0,0,0,0,100,0),
(@PATH,7,1976.07,-4359.49,106.4059,0,0,0,0,100,0),
(@PATH,8,1965.57,-4360.99,106.4059,0,0,0,0,100,0),
(@PATH,9,1954.57,-4362.49,106.4059,0,0,0,0,100,0),
(@PATH,10,1940.57,-4365.24,104.6559,0,0,0,0,100,0),
(@PATH,11,1925.07,-4367.99,105.1559,0,0,0,0,100,0),
(@PATH,12,1917.32,-4369.74,105.9059,0,0,0,0,100,0),
(@PATH,13,1913.57,-4372.24,105.9059,0,0,0,0,100,0),
(@PATH,14,1911.57,-4376.24,105.9059,0,0,0,0,100,0),
(@PATH,15,1907.07,-4380.74,105.9059,0,0,0,0,100,0),
(@PATH,16,1899.82,-4381.99,105.9059,0,0,0,0,100,0),
(@PATH,17,1891.32,-4374.99,105.9059,0,0,0,0,100,0),
(@PATH,18,1896.32,-4365.99,105.9059,0,0,0,0,100,0),
(@PATH,19,1904.07,-4363.99,105.9059,0,0,0,0,100,0),
(@PATH,20,1910.57,-4366.24,105.9059,0,0,0,0,100,0),
(@PATH,21,1913.07,-4368.99,105.9059,0,0,0,0,100,0),
(@PATH,22,1917.32,-4369.74,105.9059,0,0,0,0,100,0),
(@PATH,23,1925.07,-4368.24,105.1559,0,0,0,0,100,0),
(@PATH,24,1940.57,-4364.99,104.6559,0,0,0,0,100,0),
(@PATH,25,1954.57,-4362.49,106.4059,0,0,0,0,100,0),
(@PATH,26,1965.57,-4360.99,106.4059,0,0,0,0,100,0),
(@PATH,27,1976.07,-4359.49,106.4059,0,0,0,0,100,0),
(@PATH,28,1987.82,-4360.74,105.6559,0,0,0,0,100,0),
(@PATH,29,1991.32,-4361.49,102.4059,0,0,0,0,100,0),
(@PATH,30,1997.32,-4363.24,97.1559,0,0,0,0,100,0),
(@PATH,31,2003.32,-4364.24,94.1559,0,0,0,0,100,0),
(@PATH,32,2005.57,-4361.24,94.4059,0,0,0,0,100,0);

SET @NPC := 286774;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1927.74,`position_y`=-4391.97,`position_z`=23.3262 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1927.74,-4391.97,23.3262,0.03490658,5000,0,0,100,0),
(@PATH,2,1931.435,-4389.675,23.60685,0,0,0,0,100,0),
(@PATH,3,1938.685,-4383.675,23.60685,0,0,0,0,100,0),
(@PATH,4,1937.935,-4375.675,23.85685,0,0,0,0,100,0),
(@PATH,5,1937.185,-4363.425,24.10685,0,0,0,0,100,0),
(@PATH,6,1935.435,-4352.175,23.85685,0,0,0,0,100,0),
(@PATH,7,1933.685,-4340.925,23.85685,0,0,0,0,100,0),
(@PATH,8,1929.435,-4320.925,26.35685,0,0,0,0,100,0),
(@PATH,9,1925.935,-4306.675,24.35685,0,0,0,0,100,0),
(@PATH,10,1921.185,-4306.925,24.35685,0,0,0,0,100,0),
(@PATH,11,1924.185,-4320.925,26.35685,0,0,0,0,100,0),
(@PATH,12,1926.685,-4328.675,25.10685,0,0,0,0,100,0),
(@PATH,13,1928.935,-4340.675,23.85685,0,0,0,0,100,0),
(@PATH,14,1929.685,-4354.925,23.85685,0,0,0,0,100,0),
(@PATH,15,1930.185,-4363.925,24.10685,0,0,0,0,100,0),
(@PATH,16,1931.185,-4374.425,23.85685,0,0,0,0,100,0),
(@PATH,17,1932.185,-4381.175,23.60685,0,0,0,0,100,0);

-- grunt
SET @NPC := 286810;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1893.98,`position_y`=-4251.22,`position_z`=32.6707 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1893.98,-4251.22,32.6707,3.961897,0,0,0,100,0),
(@PATH,2,1888.13,-4252.125,33.36665,0,0,0,0,100,0),
(@PATH,3,1877.88,-4249.375,35.36665,0,0,0,0,100,0),
(@PATH,4,1868.88,-4245.625,37.61665,0,0,0,0,100,0),
(@PATH,5,1859.88,-4243.125,38.86665,0,0,0,0,100,0),
(@PATH,6,1849.88,-4241.125,40.11665,0,0,0,0,100,0),
(@PATH,7,1839.13,-4238.375,41.11665,0,0,0,0,100,0),
(@PATH,8,1829.13,-4236.625,41.36665,0,0,0,0,100,0),
(@PATH,9,1815.88,-4234.875,41.11665,0,0,0,0,100,0),
(@PATH,10,1804.63,-4233.125,40.86665,0,0,0,0,100,0),
(@PATH,11,1791.63,-4230.375,40.86665,0,0,0,0,100,0),
(@PATH,12,1779.13,-4224.375,41.36665,0,0,0,0,100,0),
(@PATH,13,1768.63,-4218.875,43.11665,0,0,0,0,100,0),
(@PATH,14,1757.13,-4213.125,46.36665,0,0,0,0,100,0),
(@PATH,15,1749.13,-4208.625,48.61665,0,0,0,0,100,0),
(@PATH,16,1743.88,-4205.125,50.11665,0,0,0,0,100,0),
(@PATH,17,1740.38,-4197.875,51.86665,0,0,0,0,100,0),
(@PATH,18,1740.13,-4189.125,54.86665,0,0,0,0,100,0),
(@PATH,19,1739.88,-4184.125,55.61665,0,0,0,0,100,0),
(@PATH,20,1739.13,-4178.125,56.61665,0,0,0,0,100,0),
(@PATH,21,1738.38,-4170.125,56.86665,0,0,0,0,100,0),
(@PATH,22,1738.13,-4161.875,56.61665,0,0,0,0,100,0),
(@PATH,23,1737.38,-4152.875,56.61665,0,0,0,0,100,0),
(@PATH,24,1736.63,-4145.875,56.11665,0,0,0,0,100,0),
(@PATH,25,1734.13,-4135.625,54.11665,0,0,0,0,100,0),
(@PATH,26,1734.63,-4144.125,55.86665,0,0,0,0,100,0),
(@PATH,27,1736.13,-4153.375,56.61665,0,0,0,0,100,0),
(@PATH,28,1735.63,-4160.375,56.61665,0,0,0,0,100,0),
(@PATH,29,1736.38,-4170.375,56.61665,0,0,0,0,100,0),
(@PATH,30,1737.63,-4179.375,56.36665,0,0,0,0,100,0),
(@PATH,31,1738.38,-4186.875,55.36665,0,0,0,0,100,0),
(@PATH,32,1738.63,-4195.875,52.61665,0,0,0,0,100,0),
(@PATH,33,1740.13,-4202.625,50.86665,0,0,0,0,100,0),
(@PATH,34,1743.63,-4209.875,49.36665,0,0,0,0,100,0),
(@PATH,35,1748.13,-4214.125,48.11665,0,0,0,0,100,0),
(@PATH,36,1757.13,-4217.125,45.86665,0,0,0,0,100,0),
(@PATH,37,1769.13,-4223.875,42.86665,0,0,0,0,100,0),
(@PATH,38,1791.88,-4233.625,40.86665,0,0,0,0,100,0),
(@PATH,39,1806.63,-4237.875,41.11665,0,0,0,0,100,0),
(@PATH,40,1818.13,-4238.875,41.11665,0,0,0,0,100,0),
(@PATH,41,1828.63,-4240.625,41.36665,0,0,0,0,100,0),
(@PATH,42,1838.13,-4243.875,41.36665,0,0,0,0,100,0),
(@PATH,43,1845.88,-4245.625,40.61665,0,0,0,0,100,0),
(@PATH,44,1856.13,-4248.125,39.36665,0,0,0,0,100,0),
(@PATH,45,1868.63,-4251.125,37.11665,0,0,0,0,100,0),
(@PATH,46,1882.13,-4252.875,34.36665,0,0,0,0,100,0);

SET @NPC := 286949;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1646.01, -4129.99, 68.7958, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1643.19, -4123.58, 67.471, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1639.93, -4115.83, 67.6571, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1635.81, -4106.18, 70.5661, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1634.44, -4102.96, 72.847, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1633.45, -4100.62, 74.0082, 0, 5000, 0, 0, 100, 0),
(@PATH, 7, 1636.86, -4108.29, 69.5999, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1640.94, -4117.97, 67.3172, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1646.37, -4130.87, 69.0926, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1650.01, -4139.24, 73.5179, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1650.9, -4141.14, 73.3816, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1650.72, -4140.71, 73.4114, 0, 5000, 0, 0, 100, 0);

-- standup
DELETE FROM `creature_addon` WHERE `guid`IN (286891, 286870,286871);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(286891,0,0,0,1,0, ''),
(286870,0,0,0,1,0, ''),
(286871,0,0,0,1,0, '');

SET @NPC := 286874;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1780.49, -4011.27, 95.4958, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1775.39, -4011.74, 91.9395, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1764.94, -4012.8, 86.226, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1754.5, -4013.89, 82.3094, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1744.06, -4015.04, 80.1415, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1732.35, -4016.46, 79.3967, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1726.33, -4017.22, 79.8366, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1718.57, -4018.19, 82.204, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 1717.99, -4018.27, 82.1986, 0, 5000, 0, 0, 100, 0),
(@PATH, 10, 1721.47, -4017.86, 81.3357, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1734.34, -4016.38, 79.3284, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1744.09, -4015.3, 80.1335, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1754.52, -4014.09, 82.3023, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 1764.95, -4012.87, 86.2223, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 1775.38, -4011.65, 91.941, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 1783.41, -4010.74, 97.7371, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 1782.53, -4010.85, 97.0696, 0, 5000, 0, 0, 100, 0);

SET @NPC := 286916;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH, 1, 1684.58, -4076.52, 86.124, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 1685.23, -4079.76, 84.7242, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 1687.23, -4088.99, 82.5687, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 1689.29, -4099.29, 82.3373, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 1690.72, -4106.14, 83.2874, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 1692.87, -4116.41, 86.0708, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 1694.42, -4123.73, 89.8237, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 1694.39, -4123.61, 89.8237, 0, 5000, 0, 0, 100, 0),
(@PATH, 9, 1693.6, -4120.21, 88.0661, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 1691.41, -4109.94, 84.046, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 1688.77, -4097.17, 82.2156, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 1686.7, -4086.87, 82.8869, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 1684.24, -4075.56, 87.002, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 1683.96, -4074.43, 87.4405, 0, 5000, 0, 0, 100, 0);

-- towernpcs
SET @NPC := 304139;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1687.106,`position_y`=-3926.072,`position_z`=83.63368 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1683.317,-3924.917,83.38367,0,0,0,0,100,0),
(@PATH,2,1685.813,-3923.332,83.38367,0,0,0,0,100,0),
(@PATH,3,1688.34,-3921.679,83.38367,0,0,0,0,100,0),
(@PATH,4,1690.882,-3920.017,83.38367,0,0,0,0,100,0),
(@PATH,5,1693.438,-3918.345,83.38367,0,0,0,0,100,0),
(@PATH,6,1695.961,-3916.695,83.38368,0,0,0,0,100,0),
(@PATH,7,1697.254,-3915.926,83.63368,0,0,0,0,100,0),
(@PATH,8,1701.048,-3913.367,83.38368,0,0,0,0,100,0),
(@PATH,9,1703.589,-3911.705,83.38368,0,0,0,0,100,0),
(@PATH,10,1706.116,-3910.052,83.38368,0,0,0,0,100,0),
(@PATH,11,1708.537,-3908.433,83.38368,0,0,0,0,100,0),
(@PATH,12,1711.037,-3906.704,83.38368,0,0,0,0,100,0),
(@PATH,13,1713.534,-3904.978,83.38368,0,0,0,0,100,0),
(@PATH,14,1716.009,-3903.267,83.38368,0,0,0,0,100,0),
(@PATH,15,1718.526,-3901.527,83.38368,0,0,0,0,100,0),
(@PATH,16,1718.652,-3901.44,83.38368,0,0,0,0,100,0),
(@PATH,17,1715.259,-3903.786,83.38368,0,0,0,0,100,0),
(@PATH,18,1714.406,-3904.375,83.38368,0,0,0,0,100,0),
(@PATH,19,1711.918,-3906.095,83.38368,0,0,0,0,100,0),
(@PATH,20,1709.411,-3907.828,83.38368,0,0,0,0,100,0),
(@PATH,21,1706.974,-3909.491,83.38368,0,0,0,0,100,0),
(@PATH,22,1704.462,-3911.134,83.38368,0,0,0,0,100,0),
(@PATH,23,1701.916,-3912.8,83.38368,0,0,0,0,100,0),
(@PATH,24,1699.32,-3914.498,83.38368,0,0,0,0,100,0),
(@PATH,25,1697.275,-3915.767,83.63368,0,0,0,0,100,0),
(@PATH,26,1694.232,-3917.825,83.38367,0,0,0,0,100,0),
(@PATH,27,1691.693,-3919.486,83.38367,0,0,0,0,100,0),
(@PATH,28,1689.138,-3921.157,83.38367,0,0,0,0,100,0),
(@PATH,29,1686.58,-3922.831,83.38367,0,0,0,0,100,0),
(@PATH,30,1684.068,-3924.445,83.38367,0,0,0,0,100,0),
(@PATH,31,1681.482,-3926.071,83.38367,0,0,0,0,100,0),
(@PATH,32,1678.902,-3927.693,83.38367,0,0,0,0,100,0),
(@PATH,33,1676.322,-3929.314,83.38367,0,0,0,0,100,0),
(@PATH,34,1673.82,-3930.887,83.38367,0,0,0,0,100,0),
(@PATH,35,1673.82,-3930.887,83.38367,0,0,0,0,100,0),
(@PATH,36,1677.312,-3928.692,83.38367,0,0,0,0,100,0),
(@PATH,37,1679.037,-3927.608,83.38367,0,0,0,0,100,0),
(@PATH,38,1681.617,-3925.986,83.38367,0,0,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=304139;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(304139, 304139, 0, 0, 2, 0, 0),
(304139, 286852, 4, 90, 2, 0, 0);

DELETE FROM `creature` WHERE `guid` IN (304138, 286853);
-- joman
SET @NPC := 286933;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1689.63,`position_y`=-4127.82,`position_z`=66.33573 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1689.63,-4127.82,66.33573,0,0,0,0,100,0),
(@PATH,2,1689.63,-4127.82,66.33573,0.418879,5000,0,0,100,0),
(@PATH,3,1680.66,-4124.89,66.34009,0,0,0,0,100,0),
(@PATH,4,1680.855,-4124.954,66.34,5.88176,5000,0,0,100,0);

-- gumbo
SET @NPC := 287012;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1499.775,`position_y`=-4191.948,`position_z`=53.54375 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1499.775,-4191.948,53.54375,0,0,0,0,100,0),
(@PATH,2,1501.025,-4191.698,53.54375,0,0,0,0,100,0),
(@PATH,3,1502.24,-4190.77,52.91138,1.518436,5000,0,0,100,0),
(@PATH,4,1503.254,-4191.556,53.51646,0,0,0,0,100,0),
(@PATH,5,1505.268,-4192.842,54.12154,4.956735,5000,0,0,100,0);

-- ingenieur
SET @NPC := 286994;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1564.773,`position_y`=-4145.446,`position_z`=51.52433 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,69, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1564.773,-4145.446,51.52433,0,0,0,0,100,0),
(@PATH,2,1563.273,-4146.446,51.52433,0,0,0,0,100,0),
(@PATH,3,1562.523,-4147.446,51.52433,0,0,0,0,100,0),
(@PATH,4,1562.9,-4149.08,51.4992,0.6632251,5000,0,0,100,0),
(@PATH,5,1562.275,-4147.93,51.4504,0,0,0,0,100,0),
(@PATH,6,1563.525,-4146.18,51.4504,0,0,0,0,100,0),
(@PATH,7,1566.146,-4145.313,51.54946,0,0,0,0,100,0),
(@PATH,8,1566.146,-4145.313,51.54946,4.258604,5000,0,0,100,0);

SET @NPC := 286888;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1743.84,`position_y`=-4099.944,`position_z`=50.23473 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1743.84,-4099.944,50.23473,0,0,0,0,100,0),
(@PATH,2,1742.34,-4101.694,50.23473,0,0,0,0,100,0),
(@PATH,3,1741.34,-4102.444,50.23473,0,0,0,0,100,0),
(@PATH,4,1738.84,-4103.944,50.48473,0,0,0,0,100,0),
(@PATH,5,1736.09,-4105.694,50.48473,0,0,0,0,100,0),
(@PATH,6,1735.09,-4106.194,50.73473,0,0,0,0,100,0),
(@PATH,7,1733.84,-4107.194,50.73473,0,0,0,0,100,0),
(@PATH,8,1734.917,-4106.415,50.5214,0,0,0,0,100,0),
(@PATH,9,1733.667,-4107.415,50.7714,0,0,0,0,100,0),
(@PATH,10,1732.417,-4107.915,50.7714,0,0,0,0,100,0),
(@PATH,11,1726.917,-4108.665,50.2714,0,0,0,0,100,0),
(@PATH,12,1726.57,-4108.776,50.29182,0,0,0,0,100,0),
(@PATH,13,1723.82,-4109.276,50.29182,0,0,0,0,100,0),
(@PATH,14,1719.07,-4108.526,50.04182,0,0,0,0,100,0),
(@PATH,15,1716.625,-4108.083,50.01192,0,0,0,0,100,0),
(@PATH,16,1714.625,-4107.833,49.76192,0,0,0,0,100,0),
(@PATH,17,1712.375,-4107.583,49.76192,0,0,0,0,100,0),
(@PATH,18,1714.474,-4107.645,49.88387,0,0,0,0,100,0),
(@PATH,19,1712.224,-4107.395,49.88387,0,0,0,0,100,0),
(@PATH,20,1711.724,-4107.395,49.63387,0,0,0,0,100,0),
(@PATH,21,1707.224,-4105.645,49.38387,0,0,0,0,100,0),
(@PATH,22,1704.974,-4104.895,49.38387,0,0,0,0,100,0),
(@PATH,23,1703.974,-4104.645,49.38387,0,0,0,0,100,0),
(@PATH,24,1701.724,-4103.645,49.38387,0,0,0,0,100,0),
(@PATH,25,1703.657,-4104.264,49.44991,0,0,0,0,100,0),
(@PATH,26,1701.657,-4103.514,49.19991,0,0,0,0,100,0),
(@PATH,27,1700.407,-4103.264,49.19991,0,0,0,0,100,0),
(@PATH,28,1697.157,-4102.264,48.94991,0,0,0,0,100,0),
(@PATH,29,1696.935,-4101.982,48.9732,0,0,0,0,100,0),
(@PATH,30,1695.685,-4101.482,48.9732,0,0,0,0,100,0),
(@PATH,31,1691.725,-4093.684,48.722,0,0,0,0,100,0),
(@PATH,32,1692.225,-4092.684,48.722,0,0,0,0,100,0),
(@PATH,33,1692.725,-4091.184,48.972,0,0,0,0,100,0),
(@PATH,34,1693.475,-4089.934,48.972,0,0,0,0,100,0),
(@PATH,35,1694.225,-4088.434,48.972,0,0,0,0,100,0),
(@PATH,36,1695.225,-4085.934,48.972,0,0,0,0,100,0),
(@PATH,37,1696.475,-4083.434,48.972,0,0,0,0,100,0),
(@PATH,38,1696.819,-4083.236,49.07568,0,0,0,0,100,0),
(@PATH,39,1697.319,-4081.986,49.07568,0,0,0,0,100,0),
(@PATH,40,1697.34,-4081.827,49.07653,0,0,0,0,100,0),
(@PATH,41,1699.59,-4080.827,49.07653,0,0,0,0,100,0),
(@PATH,42,1699.59,-4079.577,49.07653,0,0,0,0,100,0),
(@PATH,43,1699.997,-4080.607,49.07729,0,0,0,0,100,0),
(@PATH,44,1699.747,-4079.357,49.07729,0,0,0,0,100,0),
(@PATH,45,1699.497,-4078.107,49.07729,0,0,0,0,100,0),
(@PATH,46,1701.247,-4075.857,49.07729,0,0,0,0,100,0),
(@PATH,47,1702.247,-4074.607,49.07729,0,0,0,0,100,0),
(@PATH,48,1702.512,-4074.279,49.08138,0,0,0,0,100,0),
(@PATH,49,1703.012,-4073.779,49.08138,0,0,0,0,100,0),
(@PATH,50,1704.762,-4072.029,49.08138,0,0,0,0,100,0),
(@PATH,51,1706.762,-4069.779,49.08138,0,0,0,0,100,0),
(@PATH,52,1708.012,-4068.529,49.08138,0,0,0,0,100,0),
(@PATH,53,1708.762,-4067.529,49.08138,0,0,0,0,100,0),
(@PATH,54,1708.129,-4068.237,49.29485,0,0,0,0,100,0),
(@PATH,55,1709.129,-4067.237,49.29485,0,0,0,0,100,0),
(@PATH,56,1709.629,-4066.737,49.29485,0,0,0,0,100,0),
(@PATH,57,1711.879,-4064.987,49.29485,0,0,0,0,100,0),
(@PATH,58,1714.379,-4062.987,49.29485,0,0,0,0,100,0),
(@PATH,59,1715.879,-4061.987,49.29485,0,0,0,0,100,0),
(@PATH,60,1719.129,-4059.487,49.54485,0,0,0,0,100,0),
(@PATH,61,1721.129,-4057.987,49.79485,0,0,0,0,100,0),
(@PATH,62,1722.129,-4056.987,49.79485,0,0,0,0,100,0),
(@PATH,63,1725.26,-4054.754,49.9922,0,0,0,0,100,0),
(@PATH,64,1727.76,-4055.004,49.9922,0,0,0,0,100,0),
(@PATH,65,1730.01,-4055.504,49.9922,0,0,0,0,100,0),
(@PATH,66,1732.76,-4055.754,49.7422,0,0,0,0,100,0),
(@PATH,67,1737.76,-4056.504,49.4922,0,0,0,0,100,0),
(@PATH,68,1740.76,-4056.504,49.4922,0,0,0,0,100,0),
(@PATH,69,1743.26,-4056.754,49.4922,0,0,0,0,100,0),
(@PATH,70,1743.6,-4056.998,49.60223,0,0,0,0,100,0),
(@PATH,71,1744.6,-4057.248,49.60223,0,0,0,0,100,0),
(@PATH,72,1748.963,-4058.681,49.76654,0,0,0,0,100,0),
(@PATH,73,1750.963,-4061.431,49.76654,0,0,0,0,100,0),
(@PATH,74,1752.213,-4063.931,49.76654,0,0,0,0,100,0),
(@PATH,75,1752.963,-4064.681,49.76654,0,0,0,0,100,0),
(@PATH,76,1753.463,-4065.681,49.76654,0,0,0,0,100,0),
(@PATH,77,1754.213,-4066.681,49.76654,0,0,0,0,100,0),
(@PATH,78,1755.963,-4069.181,50.26654,0,0,0,0,100,0),
(@PATH,79,1755.893,-4069.432,50.25053,0,0,0,0,100,0),
(@PATH,80,1756.143,-4069.682,50.50053,0,0,0,0,100,0),
(@PATH,81,1756.143,-4070.682,50.50053,0,0,0,0,100,0),
(@PATH,82,1756.143,-4072.682,50.75053,0,0,0,0,100,0),
(@PATH,83,1756.393,-4075.682,50.25053,0,0,0,0,100,0),
(@PATH,84,1756.601,-4079.347,50.10918,0,0,0,0,100,0),
(@PATH,85,1755.601,-4081.597,50.10918,0,0,0,0,100,0),
(@PATH,86,1754.851,-4083.097,49.85918,0,0,0,0,100,0),
(@PATH,87,1753.601,-4086.097,49.85918,0,0,0,0,100,0),
(@PATH,88,1751.351,-4090.847,50.10918,0,0,0,0,100,0),
(@PATH,89,1750.874,-4090.969,50.22407,0,0,0,0,100,0),
(@PATH,90,1750.874,-4091.469,50.22407,0,0,0,0,100,0),
(@PATH,91,1750.124,-4092.469,50.47407,0,0,0,0,100,0),
(@PATH,92,1748.874,-4093.719,50.47407,0,0,0,0,100,0),
(@PATH,93,1746.874,-4095.969,50.22407,0,0,0,0,100,0),
(@PATH,94,1746.374,-4096.97,50.22407,0,0,0,0,100,0),
(@PATH,95,1744.124,-4099.72,50.22407,0,0,0,0,100,0);

SET @NPC := 286910;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1734.391,`position_y`=-4089.083,`position_z`=67.85324 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1734.391,-4089.083,67.85324,0,0,0,0,100,0),
(@PATH,2,1730.891,-4091.083,67.85324,0,0,0,0,100,0),
(@PATH,3,1727.141,-4093.333,66.35324,0,0,0,0,100,0),
(@PATH,4,1723.391,-4095.083,64.35324,0,0,0,0,100,0),
(@PATH,5,1718.641,-4096.583,62.60324,0,0,0,0,100,0),
(@PATH,6,1713.891,-4093.583,60.60324,0,0,0,0,100,0),
(@PATH,7,1712.891,-4088.333,59.10324,0,0,0,0,100,0),
(@PATH,8,1715.141,-4083.833,57.85324,0,0,0,0,100,0),
(@PATH,9,1719.641,-4081.083,55.85324,0,0,0,0,100,0),
(@PATH,10,1725.391,-4078.333,53.35324,0,0,0,0,100,0),
(@PATH,11,1731.431,-4077.146,50.53487,0,0,0,0,100,0),
(@PATH,12,1731.431,-4077.146,50.53487,1.029744,5000,0,0,100,0),
(@PATH,13,1729.845,-4076.729,50.8541,0,0,0,0,100,0),
(@PATH,14,1723.845,-4078.979,54.1041,0,0,0,0,100,0),
(@PATH,15,1716.595,-4082.729,57.3541,0,0,0,0,100,0),
(@PATH,16,1712.845,-4087.979,59.1041,0,0,0,0,100,0),
(@PATH,17,1714.845,-4094.729,60.8541,0,0,0,0,100,0),
(@PATH,18,1719.595,-4096.229,62.8541,0,0,0,0,100,0),
(@PATH,19,1723.595,-4094.979,64.3541,0,0,0,0,100,0),
(@PATH,20,1728.345,-4093.229,67.1041,0,0,0,0,100,0),
(@PATH,21,1733.095,-4088.729,67.8541,0,0,0,0,100,0),
(@PATH,22,1737.76,-4089.313,67.67332,2.932153,5000,0,0,100,0);

DELETE FROM `creature_formations` WHERE `leaderGUID`=286901;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(286901, 286901, 0, 0, 2, 0, 0),
(286901, 286902, 2, 0, 2, 0, 0),
(286901, 286900, 2, 50, 2, 0, 0),
(286901, 286899, 2, 310, 2, 0, 0);

SET @NPC := 286901;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1746.421,`position_y`=-4089.614,`position_z`=50.53776 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1746.421,-4089.614,50.53776,0,0,0,0,100,0),
(@PATH,2,1747.171,-4088.114,50.28776,0,0,0,0,100,0),
(@PATH,3,1747.671,-4086.864,50.28776,0,0,0,0,100,0),
(@PATH,4,1748.671,-4083.864,49.78776,0,0,0,0,100,0),
(@PATH,5,1749.421,-4082.614,49.78776,0,0,0,0,100,0),
(@PATH,6,1749.921,-4081.614,50.03776,0,0,0,0,100,0),
(@PATH,7,1750.421,-4080.864,50.03776,0,0,0,0,100,0),
(@PATH,8,1750.921,-4079.114,50.28776,0,0,0,0,100,0),
(@PATH,9,1752.421,-4076.114,50.53776,0,0,0,0,100,0),
(@PATH,10,1752.482,-4075.893,50.48777,0,0,0,0,100,0),
(@PATH,11,1752.482,-4075.643,50.48777,0,0,0,0,100,0),
(@PATH,12,1751.232,-4073.643,50.73777,0,0,0,0,100,0),
(@PATH,13,1749.732,-4071.143,50.48777,0,0,0,0,100,0),
(@PATH,14,1748.982,-4070.143,50.23777,0,0,0,0,100,0),
(@PATH,15,1748.232,-4068.893,49.98777,0,0,0,0,100,0),
(@PATH,16,1747.232,-4067.143,49.73777,0,0,0,0,100,0),
(@PATH,17,1746.482,-4065.893,49.73777,0,0,0,0,100,0),
(@PATH,18,1745.982,-4064.893,49.73777,0,0,0,0,100,0),
(@PATH,19,1744.732,-4063.143,49.73777,0,0,0,0,100,0),
(@PATH,20,1744.482,-4063.012,49.71793,0,0,0,0,100,0),
(@PATH,21,1744.232,-4062.512,49.46793,0,0,0,0,100,0),
(@PATH,22,1742.482,-4062.512,49.46793,0,0,0,0,100,0),
(@PATH,23,1738.982,-4062.012,49.71793,0,0,0,0,100,0),
(@PATH,24,1737.482,-4062.012,49.46793,0,0,0,0,100,0),
(@PATH,25,1733.482,-4061.512,49.71793,0,0,0,0,100,0),
(@PATH,26,1731.982,-4061.512,49.46793,0,0,0,0,100,0),
(@PATH,27,1729.263,-4061.259,49.67731,0,0,0,0,100,0),
(@PATH,28,1726.013,-4062.759,49.67731,0,0,0,0,100,0),
(@PATH,29,1725.263,-4063.259,49.42731,0,0,0,0,100,0),
(@PATH,30,1722.763,-4064.509,49.42731,0,0,0,0,100,0),
(@PATH,31,1720.513,-4065.509,49.17731,0,0,0,0,100,0),
(@PATH,32,1719.013,-4066.259,49.17731,0,0,0,0,100,0),
(@PATH,33,1717.513,-4067.009,49.17731,0,0,0,0,100,0),
(@PATH,34,1717.184,-4067.297,49.15305,0,0,0,0,100,0),
(@PATH,35,1715.684,-4068.047,49.15305,0,0,0,0,100,0),
(@PATH,36,1713.184,-4071.797,48.90305,0,0,0,0,100,0),
(@PATH,37,1711.684,-4073.547,48.90305,0,0,0,0,100,0),
(@PATH,38,1710.184,-4075.797,48.90305,0,0,0,0,100,0),
(@PATH,39,1709.684,-4076.547,48.90305,0,0,0,0,100,0),
(@PATH,40,1708.184,-4078.797,48.90305,0,0,0,0,100,0),
(@PATH,41,1707.434,-4079.797,48.90305,0,0,0,0,100,0),
(@PATH,42,1706.684,-4080.797,48.90305,0,0,0,0,100,0),
(@PATH,43,1704.684,-4083.547,48.90305,0,0,0,0,100,0),
(@PATH,44,1703.684,-4085.047,48.90305,0,0,0,0,100,0),
(@PATH,45,1699.934,-4090.297,48.90305,0,0,0,0,100,0),
(@PATH,46,1699.184,-4091.297,48.90305,0,0,0,0,100,0),
(@PATH,47,1699.22,-4091.597,49.06976,0,0,0,0,100,0),
(@PATH,48,1698.72,-4092.097,49.06976,0,0,0,0,100,0),
(@PATH,49,1699.47,-4093.597,48.81976,0,0,0,0,100,0),
(@PATH,50,1700.72,-4096.598,48.81976,0,0,0,0,100,0),
(@PATH,51,1700.988,-4096.782,49.05772,0,0,0,0,100,0),
(@PATH,52,1701.238,-4097.782,49.30772,0,0,0,0,100,0),
(@PATH,53,1703.488,-4098.282,49.30772,0,0,0,0,100,0),
(@PATH,54,1705.488,-4098.782,49.55772,0,0,0,0,100,0),
(@PATH,55,1708.738,-4099.782,49.55772,0,0,0,0,100,0),
(@PATH,56,1709.738,-4100.032,49.55772,0,0,0,0,100,0),
(@PATH,57,1711.738,-4100.282,49.55772,0,0,0,0,100,0),
(@PATH,58,1713.738,-4100.782,49.80772,0,0,0,0,100,0),
(@PATH,59,1714.988,-4101.032,49.80772,0,0,0,0,100,0),
(@PATH,60,1715.988,-4101.282,49.80772,0,0,0,0,100,0),
(@PATH,61,1717.488,-4101.782,50.05772,0,0,0,0,100,0),
(@PATH,62,1718.738,-4102.032,50.05772,0,0,0,0,100,0),
(@PATH,63,1720.488,-4102.532,50.05772,0,0,0,0,100,0),
(@PATH,64,1726.738,-4104.032,50.55772,0,0,0,0,100,0),
(@PATH,65,1726.883,-4104.031,50.58294,0,0,0,0,100,0),
(@PATH,66,1727.133,-4104.031,50.58294,0,0,0,0,100,0),
(@PATH,67,1730.845,-4102.978,50.61089,0,0,0,0,100,0),
(@PATH,68,1731.845,-4101.978,50.61089,0,0,0,0,100,0),
(@PATH,69,1733.095,-4100.978,50.61089,0,0,0,0,100,0),
(@PATH,70,1735.095,-4099.228,50.36089,0,0,0,0,100,0),
(@PATH,71,1737.345,-4097.228,50.36089,0,0,0,0,100,0),
(@PATH,72,1739.345,-4095.478,50.36089,0,0,0,0,100,0),
(@PATH,73,1742.845,-4092.728,50.36089,0,0,0,0,100,0),
(@PATH,74,1745.095,-4090.728,50.36089,0,0,0,0,100,0);

SET @NPC := 287101;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1562.72,`position_y`=-4223.45,`position_z`=54.2681 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1562.72,-4223.45,54.2681,0,0,0,0,100,0),
(@PATH,2,1563.47,-4223.45,54.2681,0,0,0,0,100,0),
(@PATH,3,1564.47,-4223.45,54.2681,0,0,0,0,100,0),
(@PATH,4,1564.36,-4223.44,54.19297,0,0,0,0,100,0),
(@PATH,5,1560.91,-4224.63,54.1431,0,0,0,0,100,0),
(@PATH,6,1560.91,-4224.63,54.1431,1.308997,5000,0,0,100,0),
(@PATH,7,1562.72,-4223.45,54.2681,0,0,0,0,100,0);

SET @NPC := 286980;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1474.875,`position_y`=-4149.25,`position_z`=52.90524 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1474.875,-4149.25,52.90524,0,0,0,0,100,0),
(@PATH,2,1478.625,-4151,52.90524,0,0,0,0,100,0),
(@PATH,3,1479.375,-4155,52.90524,0,0,0,0,100,0),
(@PATH,4,1476.625,-4158,52.90524,0,0,0,0,100,0),
(@PATH,5,1470.34,-4159.11,52.84705,0,0,0,0,100,0),
(@PATH,6,1470.34,-4159.11,52.84705,4.537856,5000,0,0,100,0),
(@PATH,7,1475.565,-4157.505,52.73143,0,0,0,0,100,0),
(@PATH,8,1478.315,-4156.255,52.73143,0,0,0,0,100,0),
(@PATH,9,1479.065,-4153.255,52.73143,0,0,0,0,100,0),
(@PATH,10,1472.12,-4148.55,52.69459,0,0,0,0,100,0),
(@PATH,11,1472.12,-4148.55,52.69459,6.230825,5000,0,0,100,0);

-- DB/Pathing/Emotes: Orgrimmar
SET @NPC := 287179;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1433.26,`position_y`=-4428.14,`position_z`=73.792 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1433.26,-4428.14,73.792,3.193953,0,0,0,100,0),
(@PATH,2,1426.51,-4428.89,74.042,0,0,0,0,100,0),
(@PATH,3,1420.51,-4424.64,74.042,0,0,0,0,100,0),
(@PATH,4,1417.76,-4415.14,74.042,0,0,0,0,100,0),
(@PATH,5,1416.01,-4404.64,74.042,0,0,0,0,100,0),
(@PATH,6,1415.01,-4394.14,74.042,0,0,0,0,100,0),
(@PATH,7,1413.76,-4385.14,74.042,0,0,0,0,100,0),
(@PATH,8,1412.76,-4376.14,74.042,0,0,0,0,100,0),
(@PATH,9,1411.51,-4366.14,74.042,0,0,0,0,100,0),
(@PATH,10,1408.26,-4363.89,74.042,0,0,0,0,100,0),
(@PATH,11,1400.76,-4364.39,74.042,0,0,0,0,100,0),
(@PATH,12,1397.76,-4368.14,74.042,0,0,0,0,100,0),
(@PATH,13,1398.51,-4377.39,74.042,0,0,0,0,100,0),
(@PATH,14,1399.76,-4386.89,74.042,0,0,0,0,100,0),
(@PATH,15,1401.26,-4395.64,74.042,0,0,0,0,100,0),
(@PATH,16,1401.26,-4402.89,74.042,0,0,0,0,100,0),
(@PATH,17,1402.01,-4413.39,74.042,0,0,0,0,100,0),
(@PATH,18,1403.26,-4422.39,74.042,0,0,0,0,100,0),
(@PATH,19,1406.76,-4426.89,74.042,0,0,0,0,100,0),
(@PATH,20,1410.01,-4430.39,74.042,0,0,0,0,100,0),
(@PATH,21,1412.01,-4440.64,73.792,0,0,0,0,100,0),
(@PATH,22,1413.51,-4450.89,73.792,0,0,0,0,100,0),
(@PATH,23,1414.51,-4460.64,73.792,0,0,0,0,100,0),
(@PATH,24,1412.76,-4465.89,73.792,0,0,0,0,100,0),
(@PATH,25,1411.01,-4471.39,74.042,0,0,0,0,100,0),
(@PATH,26,1411.01,-4476.64,74.042,0,0,0,0,100,0),
(@PATH,27,1411.51,-4483.14,74.042,0,0,0,0,100,0),
(@PATH,28,1413.01,-4492.39,74.042,0,0,0,0,100,0),
(@PATH,29,1414.01,-4501.64,74.042,0,0,0,0,100,0),
(@PATH,30,1418.76,-4503.64,74.042,0,0,0,0,100,0),
(@PATH,31,1424.51,-4502.39,74.042,0,0,0,0,100,0),
(@PATH,32,1426.26,-4498.64,74.042,0,0,0,0,100,0),
(@PATH,33,1425.76,-4491.64,74.042,0,0,0,0,100,0),
(@PATH,34,1425.26,-4486.64,74.042,0,0,0,0,100,0),
(@PATH,35,1424.26,-4479.39,74.042,0,0,0,0,100,0),
(@PATH,36,1423.26,-4470.39,74.042,0,0,0,0,100,0),
(@PATH,37,1421.76,-4460.14,73.792,0,0,0,0,100,0),
(@PATH,38,1421.01,-4450.64,73.792,0,0,0,0,100,0),
(@PATH,39,1420.51,-4440.39,74.042,0,0,0,0,100,0),
(@PATH,40,1421.51,-4432.64,73.792,0,0,0,0,100,0),
(@PATH,41,1426.51,-4428.64,74.042,0,0,0,0,100,0);

SET @NPC := 310815;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1447.13,`position_y`=-4426.4,`position_z`=73.83344 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1447.13,-4426.4,73.83344,0,0,0,0,100,0),
(@PATH,2,1447.13,-4426.4,73.83344,0.1919862,0,0,0,100,0),
(@PATH,3,1452.93,-4425.615,74.08311,0,0,0,0,100,0),
(@PATH,4,1456.43,-4420.615,74.08311,0,0,0,0,100,0),
(@PATH,5,1457.68,-4409.365,74.08311,0,0,0,0,100,0),
(@PATH,6,1457.43,-4398.115,74.08311,0,0,0,0,100,0),
(@PATH,7,1456.18,-4385.615,74.08311,0,0,0,0,100,0),
(@PATH,8,1455.43,-4378.365,74.08311,0,0,0,0,100,0),
(@PATH,9,1458.18,-4374.865,74.08311,0,0,0,0,100,0),
(@PATH,10,1463.43,-4373.615,74.08311,0,0,0,0,100,0),
(@PATH,11,1466.68,-4376.615,74.08311,0,0,0,0,100,0),
(@PATH,12,1468.18,-4385.615,74.08311,0,0,0,0,100,0),
(@PATH,13,1468.93,-4394.365,74.08311,0,0,0,0,100,0),
(@PATH,14,1469.93,-4406.615,74.08311,0,0,0,0,100,0),
(@PATH,15,1470.43,-4411.365,74.08311,0,0,0,0,100,0),
(@PATH,16,1468.18,-4417.865,74.08311,0,0,0,0,100,0),
(@PATH,17,1464.68,-4423.365,74.08311,0,0,0,0,100,0),
(@PATH,18,1460.18,-4429.865,74.08311,0,0,0,0,100,0),
(@PATH,19,1458.18,-4434.865,74.08311,0,0,0,0,100,0),
(@PATH,20,1460.18,-4439.115,74.08311,0,0,0,0,100,0),
(@PATH,21,1463.18,-4442.115,74.08311,0,0,0,0,100,0),
(@PATH,22,1466.93,-4444.865,74.08311,0,0,0,0,100,0),
(@PATH,23,1470.68,-4447.365,74.08311,0,0,0,0,100,0),
(@PATH,24,1473.93,-4450.615,74.08311,0,0,0,0,100,0),
(@PATH,25,1474.93,-4461.115,74.08311,0,0,0,0,100,0),
(@PATH,26,1476.18,-4470.365,74.08311,0,0,0,0,100,0),
(@PATH,27,1477.43,-4478.365,74.08311,0,0,0,0,100,0),
(@PATH,28,1475.93,-4482.365,73.83311,0,0,0,0,100,0),
(@PATH,29,1469.68,-4482.865,73.83311,0,0,0,0,100,0),
(@PATH,30,1466.43,-4480.615,73.83311,0,0,0,0,100,0),
(@PATH,31,1465.43,-4472.365,74.08311,0,0,0,0,100,0),
(@PATH,32,1465.18,-4466.615,74.08311,0,0,0,0,100,0),
(@PATH,33,1464.68,-4462.615,74.08311,0,0,0,0,100,0),
(@PATH,34,1464.18,-4455.365,74.08311,0,0,0,0,100,0),
(@PATH,35,1463.43,-4448.365,74.08311,0,0,0,0,100,0),
(@PATH,36,1462.93,-4442.865,74.08311,0,0,0,0,100,0),
(@PATH,37,1460.68,-4438.865,74.08311,0,0,0,0,100,0),
(@PATH,38,1458.43,-4434.365,74.08311,0,0,0,0,100,0),
(@PATH,39,1456.18,-4429.865,74.08311,0,0,0,0,100,0),
(@PATH,40,1453.18,-4425.865,74.08311,0,0,0,0,100,0);

SET @NPC := 287184;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1428.8,`position_y`=-4365.275,`position_z`=25.8377 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1428.8,-4365.275,25.8377,0,0,0,0,100,0),
(@PATH,2,1432.3,-4396.275,25.8377,0,0,0,0,100,0),
(@PATH,3,1436.05,-4423.775,25.8377,0,0,0,0,100,0),
(@PATH,4,1436.05,-4423.775,25.8377,0,0,0,0,100,0),
(@PATH,5,1432.3,-4396.275,25.8377,0,0,0,0,100,0),
(@PATH,6,1428.8,-4365.275,25.8377,0,0,0,0,100,0);

SET @NPC := 310840;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1522.4,`position_y`=-4361.835,`position_z`=20.78642 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1522.4,-4361.835,20.78642,0,0,0,0,100,0),
(@PATH,2,1524.4,-4362.335,20.78642,0,0,0,0,100,0),
(@PATH,3,1527.4,-4363.335,20.78642,0,0,0,0,100,0),
(@PATH,4,1528.65,-4363.585,20.78642,0,0,0,0,100,0),
(@PATH,5,1533.4,-4364.585,20.78642,0,0,0,0,100,0),
(@PATH,6,1537.65,-4365.835,20.78642,0,0,0,0,100,0),
(@PATH,7,1539.65,-4366.335,20.78642,0,0,0,0,100,0),
(@PATH,8,1544.195,-4367.621,20.76924,0,0,0,0,100,0),
(@PATH,9,1544.695,-4368.121,20.76924,0,0,0,0,100,0),
(@PATH,10,1544.945,-4368.371,20.76924,0,0,0,0,100,0),
(@PATH,11,1545.945,-4368.621,19.76924,0,0,0,0,100,0),
(@PATH,12,1547.695,-4369.371,18.26924,0,0,0,0,100,0),
(@PATH,13,1548.438,-4370.313,17.49227,5.77704,10000,0,0,100,0),
(@PATH,14,1547.559,-4369.556,18.27049,0,0,0,0,100,0),
(@PATH,15,1545.809,-4368.556,19.77049,0,0,0,0,100,0),
(@PATH,16,1544.559,-4367.806,20.27049,0,0,0,0,100,0),
(@PATH,17,1540.309,-4365.556,20.77049,0,0,0,0,100,0),
(@PATH,18,1539.059,-4365.056,20.77049,0,0,0,0,100,0),
(@PATH,19,1537.059,-4363.806,20.77049,0,0,0,0,100,0),
(@PATH,20,1530.309,-4360.056,20.77049,0,0,0,0,100,0),
(@PATH,21,1528.809,-4359.306,20.77049,0,0,0,0,100,0),
(@PATH,22,1528.059,-4358.806,20.77049,0,0,0,0,100,0),
(@PATH,23,1530.097,-4359.898,20.79203,0,0,0,0,100,0),
(@PATH,24,1528.597,-4359.148,20.79203,0,0,0,0,100,0),
(@PATH,25,1528.097,-4358.648,20.79203,0,0,0,0,100,0),
(@PATH,26,1526.847,-4358.148,20.79203,0,0,0,0,100,0),
(@PATH,27,1526.847,-4357.148,20.79203,0,0,0,0,100,0),
(@PATH,28,1526.847,-4354.148,20.54203,0,0,0,0,100,0),
(@PATH,29,1526.59,-4351.83,20.54868,5.113815,10000,0,0,100,0),
(@PATH,30,1525.255,-4353.895,20.78824,0,0,0,0,100,0),
(@PATH,31,1523.505,-4356.395,20.53824,0,0,0,0,100,0),
(@PATH,32,1522.505,-4358.395,20.78824,0,0,0,0,100,0),
(@PATH,33,1520.42,-4361.46,20.52781,0.1396263,10000,0,0,100,0);

SET @NPC := 287111;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1563.189,`position_y`=-4343.167,`position_z`=20.91406 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1563.189,-4343.167,20.91406,0,0,0,0,100,0),
(@PATH,2,1567.635,-4339.139,21.75208,0,0,0,0,100,0),
(@PATH,3,1577.135,-4330.389,22.50208,0,0,0,0,100,0),
(@PATH,4,1583.385,-4324.389,21.75208,0,0,0,0,100,0),
(@PATH,5,1600.135,-4314.639,21.00208,0,0,0,0,100,0),
(@PATH,6,1613.635,-4305.389,20.75208,0,0,0,0,100,0),
(@PATH,7,1636.135,-4295.139,21.00208,0,0,0,0,100,0),
(@PATH,8,1650.385,-4292.889,21.75208,0,0,0,0,100,0),
(@PATH,9,1670.885,-4288.389,25.25208,0,0,0,0,100,0),
(@PATH,10,1685.635,-4295.139,29.50208,0,0,0,0,100,0),
(@PATH,11,1699.385,-4310.889,31.25208,0,0,0,0,100,0),
(@PATH,12,1712.635,-4332.389,31.50208,0,0,0,0,100,0),
(@PATH,13,1718.385,-4354.389,31.50208,0,0,0,0,100,0),
(@PATH,14,1719.885,-4379.389,32.50208,0,0,0,0,100,0),
(@PATH,15,1715.635,-4389.139,33.50208,0,0,0,0,100,0),
(@PATH,16,1707.135,-4396.639,34.00208,0,0,0,0,100,0),
(@PATH,17,1695.635,-4404.139,33.25208,0,0,0,0,100,0),
(@PATH,18,1685.885,-4407.889,29.25208,0,0,0,0,100,0),
(@PATH,19,1652.635,-4410.639,18.00208,0,0,0,0,100,0),
(@PATH,20,1623.885,-4408.139,15.50208,0,0,0,0,100,0),
(@PATH,21,1613.885,-4409.639,15.25208,0,0,0,0,100,0),
(@PATH,22,1611.135,-4416.889,14.75208,0,0,0,0,100,0),
(@PATH,23,1614.635,-4419.889,16.25208,0,0,0,0,100,0),
(@PATH,24,1629.385,-4433.139,16.25208,0,0,0,0,100,0),
(@PATH,25,1632.385,-4436.389,17.50208,0,0,0,0,100,0),
(@PATH,26,1635.135,-4437.139,17.50208,0,0,0,0,100,0),
(@PATH,27,1636.635,-4440.889,17.50208,0,0,0,0,100,0),
(@PATH,28,1633.385,-4444.139,17.50208,0,0,0,0,100,0),
(@PATH,29,1629.885,-4443.139,17.50208,0,0,0,0,100,0),
(@PATH,30,1628.635,-4439.889,17.50208,0,0,0,0,100,0),
(@PATH,31,1626.135,-4436.639,16.25208,0,0,0,0,100,0),
(@PATH,32,1612.635,-4421.889,16.25208,0,0,0,0,100,0),
(@PATH,33,1609.885,-4419.139,14.50208,0,0,0,0,100,0),
(@PATH,34,1591.135,-4407.889,15.50208,0,0,0,0,100,0),
(@PATH,35,1560.385,-4398.889,17.25208,0,0,0,0,100,0),
(@PATH,36,1532.885,-4404.139,19.00208,0,0,0,0,100,0),
(@PATH,37,1522.635,-4407.639,20.75208,0,0,0,0,100,0),
(@PATH,38,1511.135,-4410.389,22.50208,0,0,0,0,100,0),
(@PATH,39,1495.635,-4413.639,24.00208,0,0,0,0,100,0),
(@PATH,40,1493.635,-4416.639,24.00208,0,0,0,0,100,0),
(@PATH,41,1496.885,-4418.889,24.00208,0,0,0,0,100,0),
(@PATH,42,1512.635,-4416.389,22.50208,0,0,0,0,100,0),
(@PATH,43,1524.635,-4412.889,20.75208,0,0,0,0,100,0),
(@PATH,44,1533.885,-4409.889,19.25208,0,0,0,0,100,0),
(@PATH,45,1540.635,-4405.889,18.75208,0,0,0,0,100,0),
(@PATH,46,1546.635,-4400.139,18.50208,0,0,0,0,100,0),
(@PATH,47,1548.635,-4392.389,18.25208,0,0,0,0,100,0),
(@PATH,48,1550.885,-4378.389,17.50208,0,0,0,0,100,0),
(@PATH,49,1547.885,-4371.639,18.00208,0,0,0,0,100,0),
(@PATH,50,1543.385,-4368.639,20.75208,0,0,0,0,100,0),
(@PATH,51,1528.885,-4360.889,20.75208,0,0,0,0,100,0),
(@PATH,52,1518.385,-4357.639,20.75208,0,0,0,0,100,0),
(@PATH,53,1516.885,-4352.889,20.75208,0,0,0,0,100,0),
(@PATH,54,1520.885,-4351.389,20.75208,0,0,0,0,100,0),
(@PATH,55,1530.885,-4358.639,20.75208,0,0,0,0,100,0),
(@PATH,56,1544.635,-4366.639,20.75208,0,0,0,0,100,0),
(@PATH,57,1549.635,-4368.389,18.00208,0,0,0,0,100,0),
(@PATH,58,1554.635,-4366.139,17.75208,0,0,0,0,100,0),
(@PATH,59,1557.635,-4353.389,19.25208,0,0,0,0,100,0);

SET @NPC := 287207;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1630.975,`position_y`=-4438.447,`position_z`=17.17567 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1630.975,-4438.447,17.17567,0,0,0,0,100,0),
(@PATH,2,1630.475,-4437.947,17.17567,0,0,0,0,100,0),
(@PATH,3,1629.225,-4436.697,17.42567,0,0,0,0,100,0),
(@PATH,4,1627.725,-4435.197,16.42567,0,0,0,0,100,0),
(@PATH,5,1627.225,-4434.947,16.17567,0,0,0,0,100,0),
(@PATH,6,1625.475,-4432.947,16.17567,0,0,0,0,100,0),
(@PATH,7,1623.725,-4431.197,16.17567,0,0,0,0,100,0),
(@PATH,8,1622.725,-4430.197,16.17567,0,0,0,0,100,0),
(@PATH,9,1617.256,-4425.196,16.04735,0,0,0,0,100,0),
(@PATH,10,1616.256,-4424.196,16.04735,0,0,0,0,100,0),
(@PATH,11,1615.506,-4424.196,16.04735,0,0,0,0,100,0),
(@PATH,12,1606.32,-4423.52,13.6591,0,0,0,0,100,0),
(@PATH,13,1604.415,-4416.555,14.49741,0,0,0,0,100,0),
(@PATH,14,1614.51,-4415.09,14.83572,2.216568,5000,0,0,100,0),
(@PATH,15,1609.97,-4417.64,14.28848,0,0,0,0,100,0),
(@PATH,16,1611.177,-4419.067,14.40346,0,0,0,0,100,0),
(@PATH,17,1612.712,-4420.489,15.94843,0,0,0,0,100,0),
(@PATH,18,1613.212,-4420.739,15.94843,0,0,0,0,100,0),
(@PATH,19,1615.962,-4423.739,15.94843,0,0,0,0,100,0),
(@PATH,20,1616.962,-4424.489,15.94843,0,0,0,0,100,0),
(@PATH,21,1617.462,-4425.239,15.94843,0,0,0,0,100,0),
(@PATH,22,1621.712,-4429.239,15.94843,0,0,0,0,100,0),
(@PATH,23,1626.99,-4434.539,16.21526,0,0,0,0,100,0),
(@PATH,24,1627.24,-4434.789,16.21526,0,0,0,0,100,0),
(@PATH,25,1627.74,-4435.289,16.46526,0,0,0,0,100,0),
(@PATH,26,1629.24,-4436.789,17.21526,0,0,0,0,100,0);

SET @NPC := 286678;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1851.119,`position_y`=-4517.251,`position_z`=24.18536 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1851.119,-4517.251,24.18536,0,0,0,0,100,0),
(@PATH,2,1838.687,-4521.425,24.12316,0,0,0,0,100,0),
(@PATH,3,1822.937,-4523.175,23.62316,0,0,0,0,100,0),
(@PATH,4,1814.664,-4524.395,23.43164,0,0,0,0,100,0),
(@PATH,5,1792.395,-4526.896,23.87183,0,0,0,0,100,0),
(@PATH,6,1784.645,-4527.646,24.37183,0,0,0,0,100,0),
(@PATH,7,1775.932,-4528.245,25.23722,0,0,0,0,100,0),
(@PATH,8,1771.682,-4525.745,25.48722,0,0,0,0,100,0),
(@PATH,9,1766.932,-4522.995,26.23722,0,0,0,0,100,0),
(@PATH,10,1763.147,-4520.727,26.59712,0,0,0,0,100,0),
(@PATH,11,1757.318,-4520.313,27.18797,0,0,0,0,100,0),
(@PATH,12,1760.318,-4522.813,26.68797,0,0,0,0,100,0),
(@PATH,13,1763.818,-4526.063,26.18797,0,0,0,0,100,0),
(@PATH,14,1811.458,-4530.557,23.69439,0,0,0,0,100,0),
(@PATH,15,1834.708,-4525.557,23.94439,0,0,0,0,100,0),
(@PATH,16,1858.364,-4524.273,24.94416,0,0,0,0,100,0),
(@PATH,17,1863.364,-4527.523,25.44416,0,0,0,0,100,0),
(@PATH,18,1868.364,-4530.773,26.19416,0,0,0,0,100,0),
(@PATH,19,1872.364,-4533.273,26.69416,0,0,0,0,100,0),
(@PATH,20,1876.614,-4535.773,27.44416,0,0,0,0,100,0),
(@PATH,21,1880.745,-4538.067,28.21308,0,0,0,0,100,0),
(@PATH,22,1890.245,-4536.317,28.71308,0,0,0,0,100,0),
(@PATH,23,1846.463,-4523.104,24.2444,0,0,0,0,100,0),
(@PATH,24,1858.362,-4524.417,24.9125,0,0,0,0,100,0),
(@PATH,25,1863.362,-4527.417,25.4125,0,0,0,0,100,0),
(@PATH,26,1868.362,-4530.667,26.1625,0,0,0,0,100,0),
(@PATH,27,1872.362,-4533.167,26.6625,0,0,0,0,100,0),
(@PATH,28,1876.612,-4535.917,27.4125,0,0,0,0,100,0),
(@PATH,29,1880.635,-4538.062,28.04634,0,0,0,0,100,0),
(@PATH,30,1890.385,-4536.312,28.54634,0,0,0,0,100,0),
(@PATH,31,1894.55,-4535.616,28.75937,0,0,0,0,100,0),
(@PATH,32,1894.8,-4531.616,28.25937,0,0,0,0,100,0),
(@PATH,33,1895.05,-4525.616,27.50937,0,0,0,0,100,0),
(@PATH,34,1895.3,-4519.866,27.00937,0,0,0,0,100,0),
(@PATH,35,1895.3,-4514.866,26.50937,0,0,0,0,100,0),
(@PATH,36,1895.55,-4510.866,25.75937,0,0,0,0,100,0),
(@PATH,37,1895.763,-4505.792,25.21579,0,0,0,0,100,0),
(@PATH,38,1892.263,-4502.292,24.46579,0,0,0,0,100,0),
(@PATH,39,1889.513,-4499.792,24.21579,0,0,0,0,100,0),
(@PATH,40,1883.375,-4494.163,23.63243,0,0,0,0,100,0),
(@PATH,41,1863.905,-4510.321,23.82265,0,0,0,0,100,0),
(@PATH,42,1851.133,-4517.409,24.19658,0,0,0,0,100,0);

SET @NPC := 286611;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1940.928,`position_y`=-4677.009,`position_z`=33.84278 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1940.928,-4677.009,33.84278,0,0,0,0,100,0),
(@PATH,2,1927.215,-4666.632,33.64573,0,0,0,0,100,0),
(@PATH,3,1922.24,-4656.295,33.53835,0,0,0,0,100,0),
(@PATH,4,1927.13,-4666.74,33.56191,0,0,0,0,100,0),
(@PATH,5,1927.48,-4666.732,33.6406,0,0,0,0,100,0),
(@PATH,6,1941.19,-4677.344,33.7936,0,0,0,0,100,0),
(@PATH,7,1952.69,-4679.344,33.2936,0,0,0,0,100,0),
(@PATH,8,1952.909,-4679.659,33.25051,0,0,0,0,100,0),
(@PATH,9,1954.159,-4679.909,33.00051,0,0,0,0,100,0),
(@PATH,10,1960.909,-4680.409,32.50051,0,0,0,0,100,0),
(@PATH,11,1966.636,-4681.128,31.84682,0,0,0,0,100,0),
(@PATH,12,1971.485,-4678.636,31.61636,0,0,0,0,100,0),
(@PATH,13,1972.735,-4678.636,31.61636,0,0,0,0,100,0),
(@PATH,14,1977.235,-4681.386,32.11636,0,0,0,0,100,0),
(@PATH,15,1981.485,-4683.636,32.36636,0,0,0,0,100,0),
(@PATH,16,1985.735,-4685.886,32.36636,0,0,0,0,100,0),
(@PATH,17,1986.047,-4686.072,32.31528,0,0,0,0,100,0),
(@PATH,18,1987.047,-4686.572,32.31528,0,0,0,0,100,0),
(@PATH,19,1990.297,-4688.322,31.81528,0,0,0,0,100,0),
(@PATH,20,1994.297,-4690.072,30.81528,0,0,0,0,100,0),
(@PATH,21,1999.094,-4692.644,29.50362,0,0,0,0,100,0),
(@PATH,22,2003.983,-4693.757,29.15121,0,0,0,0,100,0),
(@PATH,23,2016.154,-4687.944,28.6915,0,0,0,0,100,0),
(@PATH,24,2025.908,-4682.835,28.44281,0,0,0,0,100,0),
(@PATH,25,2027.452,-4670.082,28.80202,0,0,0,0,100,0),
(@PATH,26,2027.254,-4661.718,28.77965,0,0,0,0,100,0),
(@PATH,27,2021.034,-4651.025,28.84457,0,0,0,0,100,0),
(@PATH,28,2020.784,-4650.775,28.34457,0,0,0,0,100,0),
(@PATH,29,2021.534,-4649.025,30.09457,0,0,0,0,100,0),
(@PATH,30,2024.784,-4648.275,31.84457,0,0,0,0,100,0),
(@PATH,31,2024.684,-4648.058,31.82929,0,0,0,0,100,0),
(@PATH,32,2022.434,-4646.808,31.82929,0,0,0,0,100,0),
(@PATH,33,2022.934,-4645.558,31.82929,0,0,0,0,100,0),
(@PATH,34,2023.83,-4640.935,31.93436,0,0,0,0,100,0),
(@PATH,35,2024.01,-4639.8,31.6793,0,0,0,0,100,0),
(@PATH,36,2023.63,-4640.87,31.93757,0,0,0,0,100,0),
(@PATH,37,2022.88,-4644.87,31.93757,0,0,0,0,100,0),
(@PATH,38,2022.794,-4644.919,31.83172,0,0,0,0,100,0),
(@PATH,39,2022.294,-4646.919,31.83172,0,0,0,0,100,0),
(@PATH,40,2019.794,-4646.419,31.83172,0,0,0,0,100,0),
(@PATH,41,2020.294,-4648.419,30.08172,0,0,0,0,100,0),
(@PATH,42,2020.3,-4648.677,29.99502,0,0,0,0,100,0),
(@PATH,43,2020.55,-4651.677,28.99502,0,0,0,0,100,0),
(@PATH,44,2027.175,-4661.797,28.80478,0,0,0,0,100,0),
(@PATH,45,2027.589,-4670.408,28.68972,0,0,0,0,100,0),
(@PATH,46,2025.86,-4683.181,28.42958,0,0,0,0,100,0),
(@PATH,47,2015.776,-4688.109,28.73262,0,0,0,0,100,0),
(@PATH,48,2003.63,-4693.804,29.23157,0,0,0,0,100,0),
(@PATH,49,1998.394,-4691.927,29.86153,0,0,0,0,100,0),
(@PATH,50,1994.394,-4690.177,30.86153,0,0,0,0,100,0),
(@PATH,51,1990.394,-4688.177,31.86153,0,0,0,0,100,0),
(@PATH,52,1986.831,-4686.379,32.36172,0,0,0,0,100,0),
(@PATH,53,1985.831,-4685.879,32.36172,0,0,0,0,100,0),
(@PATH,54,1981.581,-4683.629,32.36172,0,0,0,0,100,0),
(@PATH,55,1977.331,-4681.379,32.11172,0,0,0,0,100,0),
(@PATH,56,1971.895,-4678.033,31.80171,0,0,0,0,100,0),
(@PATH,57,1966.294,-4680.932,32.32523,0,0,0,0,100,0),
(@PATH,58,1960.544,-4680.432,32.57523,0,0,0,0,100,0),
(@PATH,59,1953.9,-4679.636,33.22524,0,0,0,0,100,0),
(@PATH,60,1946.4,-4678.386,33.72524,0,0,0,0,100,0);

SET @NPC := 286648;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1919.725,`position_y`=-4572.23,`position_z`=36.2021 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1919.725,-4572.23,36.2021,0,0,0,0,100,0),
(@PATH,2,1924.975,-4579.98,36.2021,0,0,0,0,100,0),
(@PATH,3,1924.975,-4587.23,36.2021,0,0,0,0,100,0),
(@PATH,4,1913.975,-4595.23,36.2021,0,0,0,0,100,0),
(@PATH,5,1900.225,-4604.73,36.2021,0,0,0,0,100,0),
(@PATH,6,1898.475,-4612.98,36.2021,0,0,0,0,100,0),
(@PATH,7,1898.475,-4612.98,36.2021,0,0,0,0,100,0),
(@PATH,8,1900.225,-4604.73,36.2021,0,0,0,0,100,0),
(@PATH,9,1913.975,-4595.23,36.2021,0,0,0,0,100,0),
(@PATH,10,1924.975,-4587.23,36.2021,0,0,0,0,100,0),
(@PATH,11,1924.975,-4579.98,36.2021,0,0,0,0,100,0),
(@PATH,12,1919.725,-4572.23,36.2021,0,0,0,0,100,0);

SET @NPC := 286710;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1939.754,`position_y`=-4491.729,`position_z`=27.66025 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1939.754,-4491.729,27.66025,0,0,0,0,100,0),
(@PATH,2,1933.004,-4484.979,26.16025,0,0,0,0,100,0),
(@PATH,3,1921.504,-4484.979,26.16025,0,0,0,0,100,0),
(@PATH,4,1915.004,-4480.729,25.66025,0,0,0,0,100,0),
(@PATH,5,1924.74,-4477.54,25.218,3.525565,0,0,0,100,0),
(@PATH,6,1925.405,-4480.79,25.5873,0,0,0,0,100,0),
(@PATH,7,1931.155,-4479.79,25.8373,0,0,0,0,100,0),
(@PATH,8,1941.905,-4473.04,25.5873,0,0,0,0,100,0),
(@PATH,9,1945.655,-4472.79,26.3373,0,0,0,0,100,0),
(@PATH,10,1949.905,-4471.29,26.3373,0,0,0,0,100,0),
(@PATH,11,1940.88,-4481.57,25.8503,2.792527,0,0,0,100,0),
(@PATH,12,1936.324,-4481.993,25.9764,0,0,0,0,100,0),
(@PATH,13,1935.074,-4485.743,26.2264,0,0,0,0,100,0),
(@PATH,14,1942.574,-4493.243,27.7264,0,0,0,0,100,0);

SET @NPC := 311028;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1833.535,`position_y`=-4523.455,`position_z`=24.19615 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1833.535,-4523.455,24.19615,0,0,0,0,100,0),
(@PATH,2,1819.785,-4523.205,23.69615,0,0,0,0,100,0),
(@PATH,3,1809.285,-4523.705,23.44615,0,0,0,0,100,0),
(@PATH,4,1797.785,-4527.455,23.69615,0,0,0,0,100,0),
(@PATH,5,1789.535,-4529.205,23.94615,0,0,0,0,100,0),
(@PATH,6,1775.785,-4529.955,24.94615,0,0,0,0,100,0),
(@PATH,7,1766.035,-4521.955,26.44615,0,0,0,0,100,0),
(@PATH,8,1759.285,-4514.205,27.69615,0,0,0,0,100,0),
(@PATH,9,1753.035,-4509.205,28.94615,0,0,0,0,100,0),
(@PATH,10,1749.035,-4505.205,30.19615,0,0,0,0,100,0),
(@PATH,11,1744.285,-4500.205,30.69615,0,0,0,0,100,0),
(@PATH,12,1738.035,-4493.455,31.69615,0,0,0,0,100,0),
(@PATH,13,1734.285,-4486.955,32.69615,0,0,0,0,100,0),
(@PATH,14,1733.035,-4478.705,34.19615,0,0,0,0,100,0),
(@PATH,15,1733.535,-4472.705,35.44615,0,0,0,0,100,0),
(@PATH,16,1737.035,-4471.455,35.44615,0,0,0,0,100,0),
(@PATH,17,1743.285,-4476.955,37.44615,0,0,0,0,100,0),
(@PATH,18,1747.285,-4480.205,40.19615,0,0,0,0,100,0),
(@PATH,19,1750.785,-4483.455,42.19615,0,0,0,0,100,0),
(@PATH,20,1755.035,-4487.455,44.19615,0,0,0,0,100,0),
(@PATH,21,1753.8,-4493.53,43.9572,3.403392,5000,0,0,100,0),
(@PATH,22,1758.535,-4486.705,44.69615,0,0,0,0,100,0),
(@PATH,23,1755.535,-4480.205,43.19615,0,0,0,0,100,0),
(@PATH,24,1752.035,-4476.455,40.44615,0,0,0,0,100,0),
(@PATH,25,1747.035,-4472.455,37.44615,0,0,0,0,100,0),
(@PATH,26,1741.785,-4469.455,35.69615,0,0,0,0,100,0),
(@PATH,27,1729.285,-4472.455,35.44615,0,0,0,0,100,0),
(@PATH,28,1726.785,-4480.955,33.94615,0,0,0,0,100,0),
(@PATH,29,1728.285,-4487.955,32.69615,0,0,0,0,100,0),
(@PATH,30,1733.535,-4496.955,31.44615,0,0,0,0,100,0),
(@PATH,31,1737.285,-4501.705,30.94615,0,0,0,0,100,0),
(@PATH,32,1742.035,-4507.205,30.19615,0,0,0,0,100,0),
(@PATH,33,1747.285,-4511.955,29.44615,0,0,0,0,100,0),
(@PATH,34,1755.035,-4518.955,27.94615,0,0,0,0,100,0),
(@PATH,35,1764.285,-4526.705,26.19615,0,0,0,0,100,0),
(@PATH,36,1775.535,-4533.455,24.94615,0,0,0,0,100,0),
(@PATH,37,1793.035,-4534.455,23.69615,0,0,0,0,100,0),
(@PATH,38,1808.535,-4531.705,23.44615,0,0,0,0,100,0),
(@PATH,39,1815.285,-4529.705,23.69615,0,0,0,0,100,0),
(@PATH,40,1829.035,-4529.205,24.19615,0,0,0,0,100,0);

SET @NPC := 286827;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1729.325,`position_y`=-4315.215,`position_z`=62.04093 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1729.325,-4315.215,62.04093,0,0,0,0,100,0),
(@PATH,2,1734.575,-4325.215,58.79093,0,0,0,0,100,0),
(@PATH,3,1739.825,-4338.215,53.29093,0,0,0,0,100,0),
(@PATH,4,1742.075,-4352.215,47.54093,0,0,0,0,100,0),
(@PATH,5,1741.325,-4367.715,40.29093,0,0,0,0,100,0),
(@PATH,6,1738.575,-4375.465,37.04093,0,0,0,0,100,0),
(@PATH,7,1735.575,-4379.465,34.29093,0,0,0,0,100,0),
(@PATH,8,1735.41,-4383.35,33.1556,3.874631,0,0,0,100,0),
(@PATH,9,1734.74,-4379.615,33.79375,0,0,0,0,100,0),
(@PATH,10,1738.49,-4375.615,36.79375,0,0,0,0,100,0),
(@PATH,11,1741.49,-4367.115,40.54375,0,0,0,0,100,0),
(@PATH,12,1741.99,-4351.865,47.54375,0,0,0,0,100,0),
(@PATH,13,1739.74,-4336.865,53.79375,0,0,0,0,100,0),
(@PATH,14,1734.99,-4325.615,58.54375,0,0,0,0,100,0),
(@PATH,15,1729.49,-4315.865,62.04375,0,0,0,0,100,0),
(@PATH,16,1729.325,-4315.215,62.04093,0,0,0,0,100,0),
(@PATH,17,1734.575,-4325.215,58.79093,0,0,0,0,100,0),
(@PATH,18,1739.825,-4338.215,53.29093,0,0,0,0,100,0),
(@PATH,19,1742.075,-4352.215,47.54093,0,0,0,0,100,0),
(@PATH,20,1741.325,-4367.715,40.29093,0,0,0,0,100,0),
(@PATH,21,1738.575,-4375.465,37.04093,0,0,0,0,100,0),
(@PATH,22,1735.575,-4379.465,34.29093,0,0,0,0,100,0);

SET @NPC := 286600;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1920.912,`position_y`=-4672.05,`position_z`=34.50681 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1920.912,-4672.05,34.50681,0,0,0,0,100,0),
(@PATH,2,1921.662,-4670.8,34.25681,0,0,0,0,100,0),
(@PATH,3,1918.662,-4661.55,34.00681,0,0,0,0,100,0),
(@PATH,4,1918.2,-4661.582,33.97115,0,0,0,0,100,0),
(@PATH,5,1918.2,-4661.332,33.72115,0,0,0,0,100,0),
(@PATH,6,1919.685,-4666.685,34.22895,0,0,0,0,100,0),
(@PATH,7,1919.685,-4668.685,34.22895,0,0,0,0,100,0),
(@PATH,8,1919.685,-4670.685,34.47895,0,0,0,0,100,0),
(@PATH,9,1918.685,-4674.685,34.97895,0,0,0,0,100,0),
(@PATH,10,1919.951,-4678.11,35.15611,0,0,0,0,100,0),
(@PATH,11,1912.701,-4682.61,35.65611,0,0,0,0,100,0),
(@PATH,12,1909.832,-4683.692,35.95065,0,0,0,0,100,0),
(@PATH,13,1909.082,-4683.692,36.20065,0,0,0,0,100,0),
(@PATH,14,1907.332,-4683.692,37.70065,0,0,0,0,100,0),
(@PATH,15,1906.332,-4683.692,38.70065,0,0,0,0,100,0),
(@PATH,16,1906.133,-4683.496,38.59302,0,0,0,0,100,0),
(@PATH,17,1905.633,-4683.496,38.59302,0,0,0,0,100,0),
(@PATH,18,1900.633,-4682.996,38.59302,0,0,0,0,100,0),
(@PATH,19,1899.383,-4682.996,38.59302,0,0,0,0,100,0),
(@PATH,20,1892.883,-4682.496,38.59302,0,0,0,0,100,0),
(@PATH,21,1889.383,-4682.246,38.59302,0,0,0,0,100,0),
(@PATH,22,1886.633,-4681.996,38.59302,0,0,0,0,100,0),
(@PATH,23,1884.883,-4681.746,38.59302,0,0,0,0,100,0),
(@PATH,24,1884.433,-4681.579,38.75163,0,0,0,0,100,0),
(@PATH,25,1884.183,-4681.329,38.50163,0,0,0,0,100,0),
(@PATH,26,1883.433,-4678.829,38.50163,0,0,0,0,100,0),
(@PATH,27,1882.46,-4676.81,38.50108,5.585053,5000,0,0,100,0),
(@PATH,28,1909.314,-4683.479,36.07848,0,0,0,0,100,0),
(@PATH,29,1910.064,-4683.479,35.82848,0,0,0,0,100,0),
(@PATH,30,1916.686,-4679.775,35.18268,0,0,0,0,100,0);

SET @NPC := 286746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1773.07,`position_y`=-4493.42,`position_z`=45.7378 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1773.07,-4493.42,45.7378,1.291544,5000,0,0,100,0),
(@PATH,2,1772.36,-4497.94,45.0764,0,0,0,0,100,0),
(@PATH,3,1777.61,-4505.44,45.0764,0,0,0,0,100,0),
(@PATH,4,1791.61,-4504.94,45.3264,0,0,0,0,100,0),
(@PATH,5,1806.86,-4498.69,46.3264,0,0,0,0,100,0),
(@PATH,6,1823.36,-4494.94,47.3264,0,0,0,0,100,0),
(@PATH,7,1840.61,-4490.19,47.0764,0,0,0,0,100,0),
(@PATH,8,1859.36,-4478.94,47.3264,0,0,0,0,100,0),
(@PATH,9,1875.11,-4464.44,49.5764,0,0,0,0,100,0),
(@PATH,10,1885.36,-4453.19,51.5764,0,0,0,0,100,0),
(@PATH,11,1891.61,-4447.69,53.0764,0,0,0,0,100,0);

SET @NPC := 310941;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1779.89,`position_y`=-4384.665,`position_z`=103.0044 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1779.89,-4384.665,103.0044,0,0,0,0,100,0),
(@PATH,2,1777.39,-4382.415,102.7544,0,0,0,0,100,0),
(@PATH,3,1772.39,-4385.165,106.0044,0,0,0,0,100,0),
(@PATH,4,1767.14,-4388.665,109.7544,0,0,0,0,100,0),
(@PATH,5,1765.39,-4393.665,109.7544,0,0,0,0,100,0),
(@PATH,6,1760.39,-4404.415,109.7544,0,0,0,0,100,0),
(@PATH,7,1746.64,-4402.415,109.7544,0,0,0,0,100,0),
(@PATH,8,1731.89,-4412.415,108.5044,0,0,0,0,100,0),
(@PATH,9,1718.64,-4421.415,110.5044,0,0,0,0,100,0),
(@PATH,10,1714.14,-4423.665,110.5044,0,0,0,0,100,0),
(@PATH,11,1698.01,-4422.38,110.214,2.600541,5000,0,0,100,0),
(@PATH,12,1700.86,-4422.88,110.4795,0,0,0,0,100,0),
(@PATH,13,1714.36,-4423.63,110.4795,0,0,0,0,100,0),
(@PATH,14,1720.61,-4420.13,110.4795,0,0,0,0,100,0),
(@PATH,15,1730.86,-4413.13,108.7295,0,0,0,0,100,0),
(@PATH,16,1742.36,-4405.13,109.7295,0,0,0,0,100,0),
(@PATH,17,1744.36,-4403.38,109.7295,0,0,0,0,100,0),
(@PATH,18,1749.36,-4389.13,109.7295,0,0,0,0,100,0),
(@PATH,19,1764.61,-4388.88,109.7295,0,0,0,0,100,0),
(@PATH,20,1768.61,-4387.88,109.7295,0,0,0,0,100,0),
(@PATH,21,1700.86,-4422.88,110.4795,0,0,0,0,100,0),
(@PATH,22,1714.36,-4423.63,110.4795,0,0,0,0,100,0),
(@PATH,23,1720.61,-4420.13,110.4795,0,0,0,0,100,0),
(@PATH,24,1730.86,-4413.13,108.7295,0,0,0,0,100,0),
(@PATH,25,1742.36,-4405.13,109.7295,0,0,0,0,100,0),
(@PATH,26,1744.36,-4403.38,109.7295,0,0,0,0,100,0),
(@PATH,27,1749.36,-4389.13,109.7295,0,0,0,0,100,0),
(@PATH,28,1764.61,-4388.88,109.7295,0,0,0,0,100,0),
(@PATH,29,1768.61,-4387.88,109.7295,0,0,0,0,100,0),
(@PATH,30,1776.94,-4388.29,102.063,0,0,0,0,100,0),
(@PATH,31,1778.27,-4386.95,102.2948,0,0,0,0,100,0),
(@PATH,32,1778.27,-4386.95,102.2948,0.6806784,5000,0,0,100,0);

SET @NPC := 286472;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2067.078,`position_y`=-4604.621,`position_z`=49.55064 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2067.078,-4604.621,49.55064,0,0,0,0,100,0),
(@PATH,2,2066.837,-4601.917,49.58557,0,0,0,0,100,0),
(@PATH,3,2071.4,-4598.52,49.61624,0,0,0,0,100,0),
(@PATH,4,2073.402,-4593.574,49.62801,0,0,0,0,100,0),
(@PATH,5,2076.472,-4592.464,49.62801,0,0,0,0,100,0),
(@PATH,6,2079.267,-4593.267,49.62801,0,0,0,0,100,0),
(@PATH,7,2080.517,-4595.267,49.62801,0,0,0,0,100,0),
(@PATH,8,2085.191,-4595.672,49.62801,0,0,0,0,100,0),
(@PATH,9,2082.922,-4599.072,49.62801,0,0,0,0,100,0),
(@PATH,10,2077.278,-4597.584,49.62801,0,0,0,0,100,0),
(@PATH,11,2077.057,-4597.626,49.58388,0,0,0,0,100,0),
(@PATH,12,2074.807,-4598.126,49.58388,0,0,0,0,100,0),
(@PATH,13,2072.718,-4601.672,49.56532,0,0,0,0,100,0),
(@PATH,14,2071.877,-4604.907,49.53975,0,0,0,0,100,0),
(@PATH,15,2067.195,-4604.676,49.33388,0,0,0,0,100,0);

SET @NPC := 310942;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1756.095,`position_y`=-4287.895,`position_z`=101.411 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1756.095,-4287.895,101.411,0,0,0,0,100,0),
(@PATH,2,1755.845,-4293.395,101.411,0,0,0,0,100,0),
(@PATH,3,1755.095,-4297.645,101.661,0,0,0,0,100,0),
(@PATH,4,1754.595,-4302.645,101.661,0,0,0,0,100,0),
(@PATH,5,1756.345,-4307.145,101.661,0,0,0,0,100,0),
(@PATH,6,1757.845,-4311.145,101.411,0,0,0,0,100,0),
(@PATH,7,1756.56,-4314.15,101.445,3.787364,5000,0,0,100,0),
(@PATH,8,1757.845,-4310.895,101.411,0,0,0,0,100,0),
(@PATH,9,1760.345,-4307.895,101.411,0,0,0,0,100,0),
(@PATH,10,1762.095,-4304.895,101.411,0,0,0,0,100,0),
(@PATH,11,1762.345,-4300.645,101.411,0,0,0,0,100,0),
(@PATH,12,1761.095,-4296.395,101.411,0,0,0,0,100,0),
(@PATH,13,1758.345,-4293.645,101.411,0,0,0,0,100,0),
(@PATH,14,1756.095,-4290.895,101.411,0,0,0,0,100,0),
(@PATH,15,1755.845,-4288.145,101.411,0,0,0,0,100,0);

SET @NPC := 287251;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1769.491,`position_y`=-4284.555,`position_z`=101.3198 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1769.491,-4284.555,101.3198,0,0,0,0,100,0),
(@PATH,2,1769.491,-4286.555,101.3198,0,0,0,0,100,0),
(@PATH,3,1769.741,-4291.305,101.3198,0,0,0,0,100,0),
(@PATH,4,1770.13,-4291.393,101.2691,0,0,0,0,100,0),
(@PATH,5,1770.13,-4292.893,101.0191,0,0,0,0,100,0),
(@PATH,6,1771.13,-4301.143,101.0191,0,0,0,0,100,0),
(@PATH,7,1771.789,-4304.024,101.2555,0,0,0,0,100,0),
(@PATH,8,1772.789,-4306.274,101.2555,0,0,0,0,100,0),
(@PATH,9,1776.528,-4313.794,101.3277,0,0,0,0,100,0),
(@PATH,10,1779.581,-4317.397,101.3794,0,0,0,0,100,0),
(@PATH,11,1780.581,-4318.397,101.3794,0,0,0,0,100,0),
(@PATH,12,1781.831,-4319.397,101.3794,0,0,0,0,100,0),
(@PATH,13,1780.874,-4318.676,101.42,0,0,0,0,100,0),
(@PATH,14,1782.124,-4319.426,101.42,0,0,0,0,100,0),
(@PATH,15,1782.374,-4319.676,101.42,0,0,0,0,100,0),
(@PATH,16,1784.79,-4320.3,101.2179,0.08726646,6000,0,0,100,0),
(@PATH,17,1784.595,-4318.9,101.4229,0,0,0,0,100,0),
(@PATH,18,1782.468,-4310.931,101.359,0,0,0,0,100,0),
(@PATH,19,1777.557,-4307.645,101.2813,0,0,0,0,100,0),
(@PATH,20,1776.307,-4306.395,101.2813,0,0,0,0,100,0),
(@PATH,21,1771.615,-4301.402,101.2395,0,0,0,0,100,0);

SET @NPC := 286708;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1902.69,`position_y`=-4450.71,`position_z`=53.40442 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1902.69,-4450.71,53.40442,0,0,0,0,100,0),
(@PATH,2,1902.69,-4450.71,53.40442,0.6981317,5000,0,0,100,0),
(@PATH,3,1905.7,-4455.57,53.39288,0,0,0,0,100,0),
(@PATH,4,1905.831,-4455.37,53.63839,0,0,0,0,100,0),
(@PATH,5,1907.59,-4460.51,53.38523,0,0,0,0,100,0),
(@PATH,6,1907.898,-4460.374,53.63419,0,0,0,0,100,0),
(@PATH,7,1907.07,-4462.99,53.38649,5.51524,5000,0,0,100,0),
(@PATH,8,1902.12,-4462.42,53.40385,0,0,0,0,100,0),
(@PATH,9,1902.431,-4462.497,53.65258,0,0,0,0,100,0),
(@PATH,10,1907.07,-4462.99,53.38649,5.51524,5000,0,0,100,0),
(@PATH,11,1902.12,-4462.42,53.40385,0,0,0,0,100,0),
(@PATH,12,1902.434,-4462.497,53.65257,0,0,0,0,100,0),
(@PATH,13,1900.8,-4463.85,53.40813,5.410521,5000,0,0,100,0);

SET @NPC := 310850;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1549.595,`position_y`=-4329.565,`position_z`=26.08117 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1549.595,-4329.565,26.08117,0,0,0,0,100,0),
(@PATH,2,1550.845,-4331.565,26.08117,0,0,0,0,100,0),
(@PATH,3,1553.095,-4335.815,22.83117,0,0,0,0,100,0),
(@PATH,4,1562.845,-4346.815,20.83117,0,0,0,0,100,0),
(@PATH,5,1567.845,-4356.315,21.08117,0,0,0,0,100,0),
(@PATH,6,1573.095,-4367.065,20.58117,0,0,0,0,100,0),
(@PATH,7,1582.595,-4373.815,20.83117,0,0,0,0,100,0),
(@PATH,8,1594.095,-4372.065,21.33117,0,0,0,0,100,0),
(@PATH,9,1593.4,-4373.435,21.0926,0,0,0,0,100,0),
(@PATH,10,1582.4,-4375.935,20.5926,0,0,0,0,100,0),
(@PATH,11,1575.15,-4368.435,20.8426,0,0,0,0,100,0),
(@PATH,12,1568.15,-4356.435,21.0926,0,0,0,0,100,0),
(@PATH,13,1563.15,-4348.435,20.5926,0,0,0,0,100,0),
(@PATH,14,1553.65,-4335.935,22.5926,0,0,0,0,100,0),
(@PATH,15,1550.65,-4331.435,26.0926,0,0,0,0,100,0),
(@PATH,16,1546.4,-4325.35,25.93285,0,0,0,0,100,0);

DELETE FROM `creature` WHERE `guid`=310801;
UPDATE `creature` SET `spawndist`=3, `MovementType`=1 WHERE  `guid`=287231;
DELETE FROM `creature` WHERE  `guid`=310835;

DELETE FROM `creature_template_addon` WHERE `entry`=37072;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(37072,0,0,0,1,233, '');

-- Sana SAI
SET @ENTRY := 3319;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,5000,6000,8000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sana - Out of Combat - Play Emote 1");

-- Naros SAI
SET @ENTRY := 46512;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,5000,6000,8000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Naros - Out of Combat - Play Emote 1");

-- Gonto SAI
SET @ENTRY := 46357;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,21000,21000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gonto - Out of Combat - Run Script");
-- Actionlist SAI
SET @ENTRY := 4635700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.560978,"On Script - Set Orientation 2,560978"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 69"),
(@ENTRY,9,2,0,0,0,100,0,11000,11000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.934120,"On Script - Set Orientation 5,934120"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Set Emote State 0");

DELETE FROM `creature` WHERE  `guid`=310841;

-- Urtharo SAI
SET @ENTRY := 3314;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,3000,14000,25000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urtharo - Out of Combat - Play Emote 1");

SET @NPC := 287142;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1653.72,`position_y`=-4324.76,`position_z`=63.8352 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1653.72,-4324.76,63.8352,0,0,0,0,100,0),
(@PATH,2,1639.97,-4333.26,63.8352,0,0,0,0,100,0),
(@PATH,3,1634.47,-4344.01,63.8352,0,0,0,0,100,0),
(@PATH,4,1634.97,-4355.51,63.8352,0,0,0,0,100,0),
(@PATH,5,1640.22,-4365.26,63.8352,0,0,0,0,100,0),
(@PATH,6,1649.22,-4372.01,63.8352,0,0,0,0,100,0),
(@PATH,7,1661.97,-4372.76,63.8352,0,0,0,0,100,0),
(@PATH,8,1675.22,-4365.51,63.8352,0,0,0,0,100,0),
(@PATH,9,1675.22,-4365.51,63.8352,0,0,0,0,100,0),
(@PATH,10,1661.97,-4372.76,63.8352,0,0,0,0,100,0),
(@PATH,11,1649.22,-4372.01,63.8352,0,0,0,0,100,0),
(@PATH,12,1640.22,-4365.26,63.8352,0,0,0,0,100,0),
(@PATH,13,1634.97,-4355.51,63.8352,0,0,0,0,100,0),
(@PATH,14,1634.47,-4344.01,63.8352,0,0,0,0,100,0),
(@PATH,15,1639.97,-4333.26,63.8352,0,0,0,0,100,0),
(@PATH,16,1653.72,-4324.76,63.8352,0,0,0,0,100,0);

SET @NPC := 310923;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1599.81,`position_y`=-4305.11,`position_z`=20.5214 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1599.81,-4305.11,20.5214,5.375614,5000,0,0,100,0),
(@PATH,2,1603.225,-4311.32,21.014,0,0,0,0,100,0),
(@PATH,3,1610.225,-4308.57,21.014,0,0,0,0,100,0),
(@PATH,4,1618.975,-4302.07,21.014,0,0,0,0,100,0),
(@PATH,5,1627.975,-4297.07,21.014,0,0,0,0,100,0),
(@PATH,6,1643.475,-4294.32,21.764,0,0,0,0,100,0),
(@PATH,7,1657.975,-4289.82,22.764,0,0,0,0,100,0),
(@PATH,8,1668.975,-4288.07,25.014,0,0,0,0,100,0),
(@PATH,9,1677.475,-4291.32,27.764,0,0,0,0,100,0),
(@PATH,10,1686.225,-4296.57,30.014,0,0,0,0,100,0),
(@PATH,11,1693.975,-4305.32,31.514,0,0,0,0,100,0),
(@PATH,12,1699.975,-4312.82,31.514,0,0,0,0,100,0),
(@PATH,13,1705.725,-4321.32,31.514,0,0,0,0,100,0),
(@PATH,14,1710.975,-4331.82,31.514,0,0,0,0,100,0),
(@PATH,15,1715.225,-4343.07,31.514,0,0,0,0,100,0),
(@PATH,16,1717.225,-4353.57,31.514,0,0,0,0,100,0),
(@PATH,17,1719.225,-4365.32,31.764,0,0,0,0,100,0),
(@PATH,18,1718.725,-4377.32,32.264,0,0,0,0,100,0),
(@PATH,19,1721.225,-4387.32,33.264,0,0,0,0,100,0),
(@PATH,20,1725.975,-4393.57,34.514,0,0,0,0,100,0),
(@PATH,21,1730.725,-4396.57,35.514,0,0,0,0,100,0),
(@PATH,22,1734.975,-4396.32,36.264,0,0,0,0,100,0),
(@PATH,23,1738.225,-4393.82,36.514,0,0,0,0,100,0),
(@PATH,24,1741.225,-4390.57,40.014,0,0,0,0,100,0),
(@PATH,25,1744.725,-4388.07,42.764,0,0,0,0,100,0),
(@PATH,26,1749.22,-4385.11,42.50665,0,0,0,0,100,0),
(@PATH,27,1749.22,-4385.11,42.50665,3.752458,5000,0,0,100,0),
(@PATH,28,1744.765,-4388.11,42.76402,0,0,0,0,100,0),
(@PATH,29,1741.015,-4390.61,39.76402,0,0,0,0,100,0),
(@PATH,30,1737.515,-4393.11,36.51402,0,0,0,0,100,0),
(@PATH,31,1733.265,-4397.36,36.01402,0,0,0,0,100,0),
(@PATH,32,1729.765,-4397.11,35.51402,0,0,0,0,100,0),
(@PATH,33,1726.765,-4390.36,34.01402,0,0,0,0,100,0),
(@PATH,34,1726.765,-4377.61,32.51402,0,0,0,0,100,0),
(@PATH,35,1726.765,-4364.86,31.76402,0,0,0,0,100,0),
(@PATH,36,1725.015,-4355.36,31.51402,0,0,0,0,100,0),
(@PATH,37,1722.015,-4344.36,31.51402,0,0,0,0,100,0),
(@PATH,38,1719.015,-4334.61,31.51402,0,0,0,0,100,0),
(@PATH,39,1713.515,-4324.36,31.51402,0,0,0,0,100,0),
(@PATH,40,1706.515,-4312.86,31.51402,0,0,0,0,100,0),
(@PATH,41,1699.515,-4305.11,31.51402,0,0,0,0,100,0),
(@PATH,42,1692.265,-4296.86,31.01402,0,0,0,0,100,0),
(@PATH,43,1681.515,-4286.11,28.26402,0,0,0,0,100,0),
(@PATH,44,1671.265,-4282.11,25.51402,0,0,0,0,100,0),
(@PATH,45,1659.765,-4284.11,23.26402,0,0,0,0,100,0),
(@PATH,46,1642.265,-4287.86,21.51402,0,0,0,0,100,0),
(@PATH,47,1620.015,-4295.11,21.01402,0,0,0,0,100,0),
(@PATH,48,1611.015,-4300.86,21.01402,0,0,0,0,100,0),
(@PATH,49,1604.765,-4304.11,21.01402,0,0,0,0,100,0);

SET @NPC := 310873;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1632.455,`position_y`=-4264.46,`position_z`=38.0437 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1632.455,-4264.46,38.0437,0,0,0,0,100,0),
(@PATH,2,1621.955,-4265.21,43.5437,0,0,0,0,100,0),
(@PATH,3,1613.705,-4266.96,50.5437,0,0,0,0,100,0),
(@PATH,4,1609.205,-4265.71,51.2937,0,0,0,0,100,0),
(@PATH,5,1605.705,-4249.21,52.0437,0,0,0,0,100,0),
(@PATH,6,1612.955,-4243.71,52.2937,0,0,0,0,100,0),
(@PATH,7,1630.955,-4241.71,52.2937,0,0,0,0,100,0),
(@PATH,8,1648.705,-4241.71,52.2937,0,0,0,0,100,0),
(@PATH,9,1661.205,-4240.96,52.2937,0,0,0,0,100,0),
(@PATH,10,1676.955,-4239.71,52.2937,0,0,0,0,100,0),
(@PATH,11,1687.705,-4236.96,52.2937,0,0,0,0,100,0),
(@PATH,12,1698.955,-4233.71,52.0437,0,0,0,0,100,0),
(@PATH,13,1706.455,-4231.21,51.5437,0,0,0,0,100,0),
(@PATH,14,1713.705,-4227.96,51.2937,0,0,0,0,100,0),
(@PATH,15,1731.19,-4219.69,49.8088,3.473205,5000,0,0,100,0),
(@PATH,16,1713.455,-4227.96,51.2937,0,0,0,0,100,0),
(@PATH,17,1706.205,-4231.21,51.5437,0,0,0,0,100,0),
(@PATH,18,1698.955,-4233.71,52.0437,0,0,0,0,100,0),
(@PATH,19,1687.455,-4237.21,52.2937,0,0,0,0,100,0),
(@PATH,20,1676.955,-4239.71,52.2937,0,0,0,0,100,0),
(@PATH,21,1671.955,-4244.46,52.2937,0,0,0,0,100,0),
(@PATH,22,1670.455,-4250.96,52.2937,0,0,0,0,100,0),
(@PATH,23,1668.205,-4256.96,52.2937,0,0,0,0,100,0),
(@PATH,24,1658.455,-4259.71,47.0437,0,0,0,0,100,0),
(@PATH,25,1648.705,-4261.46,40.2937,0,0,0,0,100,0),
(@PATH,26,1638.72,-4261.23,37.2786,4.939282,5000,0,0,100,0);

SET @NPC := 287071;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1491.04,`position_y`=-4153.62,`position_z`=51.4495 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1491.04,-4153.62,51.4495,0,0,0,0,100,0),
(@PATH,2,1488.66,-4155.7,52.37835,0,0,0,0,100,0),
(@PATH,3,1484.16,-4163.7,52.87835,0,0,0,0,100,0),
(@PATH,4,1482.66,-4175.7,53.12835,0,0,0,0,100,0),
(@PATH,5,1484.66,-4180.95,53.37835,0,0,0,0,100,0),
(@PATH,6,1489.91,-4184.2,53.37835,0,0,0,0,100,0),
(@PATH,7,1495.66,-4184.2,52.87835,0,0,0,0,100,0),
(@PATH,8,1501.91,-4185.95,52.62835,0,0,0,0,100,0),
(@PATH,9,1507.16,-4188.2,52.62835,0,0,0,0,100,0),
(@PATH,10,1512.16,-4191.2,52.37835,0,0,0,0,100,0),
(@PATH,11,1518.91,-4195.2,52.62835,0,0,0,0,100,0),
(@PATH,12,1523.66,-4196.95,52.62835,0,0,0,0,100,0),
(@PATH,13,1529.66,-4198.2,52.62835,0,0,0,0,100,0),
(@PATH,14,1540.91,-4201.7,53.12835,0,0,0,0,100,0),
(@PATH,15,1549.41,-4205.7,53.87835,0,0,0,0,100,0),
(@PATH,16,1551.91,-4210.95,54.12835,0,0,0,0,100,0),
(@PATH,17,1554.91,-4215.95,54.37835,0,0,0,0,100,0),
(@PATH,18,1561.66,-4218.7,54.12835,0,0,0,0,100,0),
(@PATH,19,1567.16,-4216.2,54.12835,0,0,0,0,100,0),
(@PATH,20,1572.91,-4211.2,54.12835,0,0,0,0,100,0),
(@PATH,21,1576.41,-4207.45,54.12835,0,0,0,0,100,0),
(@PATH,22,1576.995,-4201.592,53.90705,0,0,0,0,100,0),
(@PATH,23,1576.995,-4201.592,53.90705,5.358161,5000,0,0,100,0),
(@PATH,24,1578.267,-4204.606,53.92828,0,0,0,0,100,0),
(@PATH,25,1575.017,-4207.606,54.17828,0,0,0,0,100,0),
(@PATH,26,1570.517,-4209.106,54.42828,0,0,0,0,100,0),
(@PATH,27,1563.767,-4207.856,54.42828,0,0,0,0,100,0),
(@PATH,28,1556.267,-4204.606,54.17828,0,0,0,0,100,0),
(@PATH,29,1548.767,-4202.106,53.67828,0,0,0,0,100,0),
(@PATH,30,1536.767,-4198.856,52.67828,0,0,0,0,100,0),
(@PATH,31,1528.517,-4196.856,52.67828,0,0,0,0,100,0),
(@PATH,32,1518.517,-4193.856,52.42828,0,0,0,0,100,0),
(@PATH,33,1510.767,-4189.106,52.42828,0,0,0,0,100,0),
(@PATH,34,1501.517,-4181.606,52.42828,0,0,0,0,100,0),
(@PATH,35,1495.517,-4175.606,52.42828,0,0,0,0,100,0),
(@PATH,36,1489.267,-4167.606,52.67828,0,0,0,0,100,0),
(@PATH,37,1487.767,-4161.606,52.67828,0,0,0,0,100,0);

SET @NPC :=  287049;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1554.32,`position_y`=-4199.72,`position_z`=54.13395 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1554.32,-4199.72,54.13395,0,0,0,0,100,0),
(@PATH,2,1556.82,-4200.47,54.13395,0,0,0,0,100,0),
(@PATH,3,1558.07,-4202.22,54.38395,0,0,0,0,100,0),
(@PATH,4,1560.57,-4203.22,54.38395,0,0,0,0,100,0),
(@PATH,5,1565.39,-4202.8,54.61966,0,0,0,0,100,0),
(@PATH,6,1565.39,-4202.8,54.61966,3.211406,5000,0,0,100,0),
(@PATH,7,1564.01,-4201.91,54.5091,0,0,0,0,100,0),
(@PATH,8,1564.01,-4201.91,54.5091,1.466077,5000,0,0,100,0),
(@PATH,9,1563.155,-4202.085,54.6693,0,0,0,0,100,0),
(@PATH,10,1561.905,-4201.085,54.4193,0,0,0,0,100,0),
(@PATH,11,1561.905,-4199.085,54.6693,0,0,0,0,100,0),
(@PATH,12,1562.155,-4197.335,54.6693,0,0,0,0,100,0),
(@PATH,13,1560.8,-4195.76,54.3295,1.239184,5000,0,0,100,0),
(@PATH,14,1559.6,-4197.16,54.2491,0,0,0,0,100,0),
(@PATH,15,1560.305,-4195.975,54.53215,0,0,0,0,100,0),
(@PATH,16,1558.805,-4195.225,54.28215,0,0,0,0,100,0),
(@PATH,17,1557.055,-4196.475,54.28215,0,0,0,0,100,0),
(@PATH,18,1556.805,-4198.475,54.28215,0,0,0,0,100,0),
(@PATH,19,1555.305,-4199.225,54.03215,0,0,0,0,100,0),
(@PATH,20,1554.01,-4198.29,53.8152,1.291544,5000,0,0,100,0),
(@PATH,21,1554.32,-4199.72,54.13395,0,0,0,0,100,0);
