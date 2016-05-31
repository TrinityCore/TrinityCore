--
DELETE FROM `playercreateinfo_cast_spell` WHERE `spell` IN(108059,108061,108058,108057,108056,108055,108060);
INSERT INTO `playercreateinfo_cast_spell` (`racemask`, `classmask`, `spell`, `note`) VALUES
(8388608, 1, 108059 , 'Pandaren - Warrior - Remove weapon'), -- 73210 
(8388608, 4, 108061 , 'Pandaren - Hunter - Remove weapon'), -- 73211
(8388608, 8, 108058 , 'Pandaren - Rogue - Remove weapon'), -- 73208, 73212 
(8388608, 16, 108057 , 'Pandaren - Priest - Remove weapon'), -- 73207, 76393
(8388608, 64, 108056 , 'Pandaren - Shaman - Remove weapon'), -- 76391, 73213 
(8388608, 128, 108055 , 'Pandaren - Mage - Remove weapon'),  -- 76390, 76392 
(8388608, 512, 108060 , 'Pandaren - Monk - Remove weapon'); -- 73209

DELETE FROM `phase_area` WHERE `AreaId` = 5834;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5834, 592, 'Pandaren starting zone - warrior'),
(5834, 593, 'Pandaren starting zone - mage'),
(5834, 594, 'Pandaren starting zone - hunter'),
(5834, 595, 'Pandaren starting zone - priest'),
(5834, 596, 'Pandaren starting zone - rogue'),
(5834, 597, 'Pandaren starting zone - shaman'),
(5834, 598, 'Pandaren starting zone - monk'),
(5834, 169, 'Pandaren starting zone - all classes');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=0 AND `SourceEntry` IN(598,597,596,595,594,593,592);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(26,0,598,0,0,15,0,512,0,0,0,"","Get phase only if the class is Monk"),
(26,0,593,0,0,15,0,128,0,0,0,"","Get phase only if the class is Mage"),
(26,0,594,0,0,15,0,4,0,0,0,"","Get phase only if the class is Hunter"),
(26,0,595,0,0,15,0,16,0,0,0,"","Get phase only if the class is Priest"),
(26,0,596,0,0,15,0,8,0,0,0,"","Get phase only if the player is Rogue"),
(26,0,597,0,0,15,0,64,0,0,0,"","Get phase only if the class is Shaman"),
(26,0,592,0,0,15,0,1,0,0,0,"","Get phase only if the class is Warrior");

UPDATE `gameobject` SET `PhaseId`=598 WHERE `id`=210005;
UPDATE `gameobject_template` SET `Data17`=13361 WHERE `entry`=210015;
UPDATE `gameobject_template` SET `Data17`=13362 WHERE `entry`=210016;
UPDATE `gameobject_template` SET `Data17`=13363 WHERE `entry`=210017;
UPDATE `gameobject_template` SET `Data17`=13365 WHERE `entry`=210018;
UPDATE `gameobject_template` SET `Data17`=13366 WHERE `entry`=210019;
UPDATE `gameobject_template` SET `Data17`=13364 WHERE `entry`=210020;
UPDATE `gameobject_template` SET `Data26`=128680, `VerifiedBuild`=19116 WHERE `entry` IN(210015,210016,210017,210018,210019,210020);

DELETE FROM `gameobject_addon` WHERE `guid` IN(45878,45947);
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES
(45878, 7, 1),
(45947, 9, 100);

-- Instructor Qun SAI
SET @ENTRY := 57748;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,4000,4000,5000,5000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Instructor Qun - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@ENTRY,0,1,2,61,0,100,0,4000,4000,5000,5000,45,1,1,0,0,0,0,9,53565,0,15,0,0,0,0,"Instructor Qun - Out of Combat - Set Data 1 1"),
(@ENTRY,0,2,0,61,0,100,0,4000,4000,5000,5000,45,1,1,0,0,0,0,9,65469,0,15,0,0,0,0,"Instructor Qun - Out of Combat - Set Data 1 1");

-- Actionlist SAI
SET @ENTRY := 5356500;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,1,1000,1000,0,0,11,108967,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Cast 'Jab' (No Repeat)");

-- Aspiring Trainee SAI
SET @ENTRY := 53565;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,5000,5000,80,53565*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 1 1 - Run Script");

-- Aspiring Trainee SAI
SET @ENTRY := 65469;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,5000,5000,80,53565*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 1 1 - Run Script");

-- Aspiring Trainee SAI
SET @GUID := -138320;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=53565;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138307;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=53565;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138305;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=53565;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138289;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=53565;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=53565;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,1,100,0,0,0,4000,8000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Play Random Emote (509, 543, 511, 507)"),
(@GUID,0,1,2,38,0,100,0,2,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Say Line 0"),
(@GUID,0,2,0,61,0,100,0,2,1,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 1 - Set Event Phase 2"),
(@GUID,0,3,0,38,0,100,0,2,2,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Data Set 2 2 - Set Event Phase 1"),
(@GUID,0,4,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aspiring Trainee - On Reset - Set Event Phase 1");

-- Aspiring Trainee SAI
SET @GUID := -138284;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=53565;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,120000,150000,300000,350000,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aspiring Trainee - Out of Combat - Say Line 1");

-- Training Target SAI
SET @ENTRY := 53714;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Training Target - On Reset - Set Reactstate Passive"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,45,2,1,0,0,0,0,11,53565,3,0,0,0,0,0,"Training Target - On Just Died - Set Data 2 1"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,45,2,1,0,0,0,0,11,65469,3,0,0,0,0,0,"Training Target - On Just Died - Set Data 2 1"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,45,2,2,0,0,0,0,11,53565,3,0,0,0,0,0,"Training Target - On Reset - Set Data 2 2"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,45,2,2,0,0,0,0,11,65469,3,0,0,0,0,0,"Training Target - On Reset - Set Data 2 2");

-- Training Target SAI
SET @ENTRY := 57873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Training Target - On Reset - Set Reactstate Passive"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,45,2,1,0,0,0,0,11,53565,3,0,0,0,0,0,"Training Target - On Just Died - Set Data 2 1"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,45,2,1,0,0,0,0,11,65469,3,0,0,0,0,0,"Training Target - On Just Died - Set Data 2 1"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,45,2,2,0,0,0,0,11,53565,3,0,0,0,0,0,"Training Target - On Reset - Set Data 2 2"),
(@ENTRY,0,4,0,25,0,100,0,0,0,0,0,45,2,2,0,0,0,0,11,65469,3,0,0,0,0,0,"Training Target - On Reset - Set Data 2 2");

-- Quiet Lam SAI
SET @ENTRY := 57752;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,5000,5000,5000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Quiet Lam - Out of Combat - Play Random Emote (509, 543, 511, 507)");

-- Ironfist Zhou SAI
SET @ENTRY := 57753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,4000,5000,5000,10,509,543,511,507,0,0,1,0,0,0,0,0,0,0,"Ironfist Zhou - Out of Combat - Play Random Emote (509, 543, 511, 507)");

DELETE FROM `creature_text` WHERE `entry` IN (54587,65471,54586,65470,65469,53565);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
-- Tushui Trainee
(54587, 0, 0, 'That was a good match. Thank you.', 12, 0, 100, 1, 0, 0, 56444, 'Tushui Trainee to 0'),
(54587, 0, 1, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 1, 0, 0, 56443, 'Tushui Trainee to 0'),
(54587, 0, 2, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 0, 56439, 'Tushui Trainee to 0'),
-- Tushui Trainee
(65471, 0, 0, 'That was a good match. Thank you.', 12, 0, 100, 1, 0, 0, 56444, 'Tushui Trainee to 0'),
(65471, 0, 1, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 1, 0, 0, 56443, 'Tushui Trainee to 0'),
(65471, 0, 2, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 0, 56439, 'Tushui Trainee to 0'),
-- Huojin Trainee
(54586, 0, 0, 'That was a good match. Thank you.', 12, 0, 100, 511, 0, 0, 56444, 'Huojin Trainee to 0'),
(54586, 0, 1, 'My skills are no match for yours. I admit defeat.', 12, 0, 100, 507, 0, 0, 56441, 'Huojin Trainee to 0'),
(54586, 0, 2, 'Your skills are too great. I yield.', 12, 0, 100, 511, 0, 0, 56442, 'Huojin Trainee to 0'),
-- Huojin Trainee 
(65470, 0, 0, 'That was a good match. Thank you.', 12, 0, 100, 1, 0, 0, 56444, 'Huojin Trainee to 0'),
(65470, 0, 1, 'My skills are no match for yours. I admit defeat.', 12, 0, 100, 507, 0, 0, 56441, 'Huojin Trainee to 0'),
(65470, 0, 2, 'Your skills are too great. I yield.', 12, 0, 100, 511, 0, 0, 56442, 'Huojin Trainee to 0'),
-- Aspiring Trainee
(65469, 0, 0, 'Such skill for a new trainee.', 12, 0, 100, 511, 0, 0, 56431, 'Aspiring Trainee to Training Target'),
(65469, 0, 1, 'That target didn''t stand a chance.', 12, 0, 100, 509, 0, 0, 56433, 'Aspiring Trainee to Training Target'),
(65469, 0, 2, 'One day you will have to teach me your secrets.', 12, 0, 100, 509, 0, 0, 56432, 'Aspiring Trainee to Training Target'),
(65469, 0, 3, 'You are bound for a great things, trainee.', 12, 0, 100, 508, 0, 0, 56435, 'Aspiring Trainee to Training Target'),
-- Aspiring Trainee
(53565, 0, 0, 'Such skill for a new trainee.', 12, 0, 100, 511, 0, 0, 56431, 'Aspiring Trainee to Training Target'),
(53565, 0, 1, 'That target didn''t stand a chance.', 12, 0, 100, 511, 0, 0, 56433, 'Aspiring Trainee to Training Target'),
(53565, 0, 2, 'One day you will have to teach me your secrets.', 12, 0, 100, 509, 0, 0, 56432, 'Aspiring Trainee to Training Target'),
(53565, 0, 3, 'You are bound for a great things, trainee.', 12, 0, 100, 508, 0, 0, 56435, 'Aspiring Trainee to Training Target'),
(53565, 1, 0, 'My money''s on Lam. Did you see him take down Chu during training last week?', 12, 0, 100, 1, 0, 0, 56420, 'Aspiring Trainee to 0');

