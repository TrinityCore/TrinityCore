-- 
DELETE FROM `spell_area` WHERE `spell` IN (58530, 58551);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(58530,12,13188,13188,0,0,2,1,2,11),
(58530,1519,13188,13188,0,0,2,1,2,11),
(58551,1637,13189,13189,0,0,2,1,2,11),
(58551,14,13189,13189,0,0,2,1,2,11);

UPDATE `conditions` SET `NegativeCondition`=1 WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry` IN (68,14304,1976,1756,3296);
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceEntry = 58533;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 58533, 0, 31, 3, 68, 0, 0, '', "Return to Stormwind"),
(13, 1, 58533, 1, 31, 3, 1756, 0, 0, '', "Return to Stormwind"),
(13, 1, 58533, 2, 31, 3, 1976, 0, 0, '', "Return to Stormwind");
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceEntry = 58552;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 58552, 0, 31, 3, 14304, 0, 0, '', "Return to Orgrimmar"),
(13, 1, 58552, 1, 31, 3, 3296, 0, 0, '', "Return to Orgrimmar");

-- Stormwind City Guard SAI
SET @ENTRY := 68;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=11;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,11,0,8,0,100,0,58533,0,1000,1000,87,329600,329601,329602,329603,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On spell hit - Run Random Script");

-- Kor''kron Elite SAI
SET @ENTRY := 14304;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,12,0,8,0,100,0,58552,0,1000,1000,87,329600,329601,329602,329603,0,0,1,0,0,0,0,0,0,0,"Kor''kron Elite - On spell hit - Run Random Script");

-- Stormwind City Patroller SAI
SET @ENTRY := 1976;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=11;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,11,0,8,0,100,0,58533,0,1000,1000,87,329600,329601,329602,329603,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - On spell hit - Run Random Script");

-- Stormwind Royal Guard SAI
SET @ENTRY := 1756;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=11;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,11,0,8,0,100,0,58533,0,1000,1000,87,329600,329601,329602,329603,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On spell hit - Run Random Script");

-- Orgrimmar Grunt SAI
SET @ENTRY := 3296;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,12,0,8,0,100,0,58552,0,1000,1000,87,329600,329601,329602,329603,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - On spell hit - Run Random Script");

-- Actionlist SAI
SET @ENTRY := 329600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58509,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Cast ''Rotten Apple Toss'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 329601;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58513,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Cast 'Rotten Banana Toss'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 3");

-- Actionlist SAI
SET @ENTRY := 329602;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58520,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Cast 'Spit'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 329603;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 5");
