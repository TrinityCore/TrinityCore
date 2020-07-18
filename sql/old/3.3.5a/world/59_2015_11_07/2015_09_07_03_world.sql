--
-- DK Faction Endquest - Implement Reaction for Orgrimmar and Alliance Guards

DELETE FROM `creature_text` WHERE `entry` IN (68,1756,1976,3296) AND `groupid`>1;
DELETE FROM `creature_text` WHERE `entry` IN (14304);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(68, 2, 0, '%s throws a rotten apple at $n.', 16, 0, 100, 0, 0, 0, 31671, 'Stormwind City Guard'),
(68, 3, 0, '%s throws rotten banana on $n.', 16, 0, 100, 0, 0, 0, 31672, 'Stormwind City Guard'),
(68, 4, 0, '%s spits on $n.', 16, 0, 100, 0, 0, 0, 31673, 'Stormwind City Guard'),
(68, 5, 0, 'Monster!', 12, 0, 100, 0, 0, 0, 31662, 'Stormwind City Guard'),
(68, 5, 1, 'Murderer!', 12, 0, 100, 0, 0, 0, 31679, 'Stormwind City Guard'),
(68, 5, 2, 'GET A ROPE!', 12, 0, 100, 0, 0, 0, 31669, 'Stormwind City Guard'),
(68, 5, 3, 'How dare you set foot in our city!', 12, 0, 100, 0, 0, 0, 31684, 'Stormwind City Guard'),
(68, 5, 4, 'You disgust me.', 12, 0, 100, 0, 0, 0, 31680, 'Stormwind City Guard'),
(68, 5, 5, 'Looks like we''re going to have ourselves an execution.', 12, 0, 100, 0, 0, 0, 31682, 'Stormwind City Guard'),
(68, 5, 6, 'Traitorous dog.', 12, 0, 100, 0, 0, 0, 31665, 'Stormwind City Guard'),
(68, 5, 7, 'My family was wiped out by the Scourge! MONSTER!', 12, 0, 100, 0, 0, 0, 31667, 'Stormwind City Guard'), 
(14304, 2, 0, '%s throws a rotten apple at $n.', 16, 0, 100, 0, 0, 0, 31671, 'Kor''kron Elite'),
(14304, 3, 0, '%s throws rotten banana on $n.', 16, 0, 100, 0, 0, 0, 31672, 'Kor''kron Elite'),
(14304, 4, 0, '%s spits on $n.', 16, 0, 100, 0, 0, 0, 31673, 'Kor''kron Elite'),
(14304, 5, 0, 'Monster!', 12, 0, 100, 0, 0, 0, 31662, 'Kor''kron Elite'),
(14304, 5, 1, 'Murderer!', 12, 0, 100, 0, 0, 0, 31679, 'Kor''kron Elite'),
(14304, 5, 2, 'GET A ROPE!', 12, 0, 100, 0, 0, 0, 31669, 'Kor''kron Elite'),
(14304, 5, 3, 'How dare you set foot in our city!', 12, 0, 100, 0, 0, 0, 31684, 'Kor''kron Elite'),
(14304, 5, 4, 'You disgust me.', 12, 0, 100, 0, 0, 0, 31680, 'Kor''kron Elite'),
(14304, 5, 5, 'Looks like we''re going to have ourselves an execution.', 12, 0, 100, 0, 0, 0, 31682, 'Kor''kron Elite'),
(14304, 5, 6, 'Traitorous dog.', 12, 0, 100, 0, 0, 0, 31665, 'Kor''kron Elite'),
(14304, 5, 7, 'My family was wiped out by the Scourge! MONSTER!', 12, 0, 100, 0, 0, 0, 31667, 'Kor''kron Elite'),
(1756, 2, 0, '%s throws a rotten apple at $n.', 16, 0, 100, 0, 0, 0, 31671, 'Stormwind Royal Guard'),
(1756, 3, 0, '%s throws rotten banana on $n.', 16, 0, 100, 0, 0, 0, 31672, 'Stormwind Royal Guard'),
(1756, 4, 0, '%s spits on $n.', 16, 0, 100, 0, 0, 0, 31673, 'Stormwind Royal Guard'),
(1756, 5, 0, 'Monster!', 12, 0, 100, 0, 0, 0, 31662, 'Stormwind Royal Guard'),
(1756, 5, 1, 'Murderer!', 12, 0, 100, 0, 0, 0, 31679, 'Stormwind Royal Guard'),
(1756, 5, 2, 'GET A ROPE!', 12, 0, 100, 0, 0, 0, 31669, 'Stormwind Royal Guard'),
(1756, 5, 3, 'How dare you set foot in our city!', 12, 0, 100, 0, 0, 0, 31684, 'Stormwind Royal Guard'),
(1756, 5, 4, 'You disgust me.', 12, 0, 100, 0, 0, 0, 31680, 'Stormwind Royal Guard'),
(1756, 5, 5, 'Looks like we''re going to have ourselves an execution.', 12, 0, 100, 0, 0, 0, 31682, 'Stormwind Royal Guard'),
(1756, 5, 6, 'Traitorous dog.', 12, 0, 100, 0, 0, 0, 31665, 'Stormwind Royal Guard'),
(1756, 5, 7, 'My family was wiped out by the Scourge! MONSTER!', 12, 0, 100, 0, 0, 0, 31667, 'Stormwind Royal Guard'),
(1976, 2, 0, '%s throws a rotten apple at $n.', 16, 0, 100, 0, 0, 0, 31671, 'Stormwind City Patroller'),
(1976, 3, 0, '%s throws rotten banana on $n.', 16, 0, 100, 0, 0, 0, 31672, 'Stormwind City Patroller'),
(1976, 4, 0, '%s spits on $n.', 16, 0, 100, 0, 0, 0, 31673, 'Stormwind City Patroller'),
(1976, 5, 0, 'Monster!', 12, 0, 100, 0, 0, 0, 31662, 'Stormwind City Patroller'),
(1976, 5, 1, 'Murderer!', 12, 0, 100, 0, 0, 0, 31679, 'Stormwind City Patroller'),
(1976, 5, 2, 'GET A ROPE!', 12, 0, 100, 0, 0, 0, 31669, 'Stormwind City Patroller'),
(1976, 5, 3, 'How dare you set foot in our city!', 12, 0, 100, 0, 0, 0, 31684, 'Stormwind City Patroller'),
(1976, 5, 4, 'You disgust me.', 12, 0, 100, 0, 0, 0, 31680, 'Stormwind City Patroller'),
(1976, 5, 5, 'Looks like we''re going to have ourselves an execution.', 12, 0, 100, 0, 0, 0, 31682, 'Stormwind City Patroller'),
(1976, 5, 6, 'Traitorous dog.', 12, 0, 100, 0, 0, 0, 31665, 'Stormwind City Patroller'),
(1976, 5, 7, 'My family was wiped out by the Scourge! MONSTER!', 12, 0, 100, 0, 0, 0, 31667, 'Stormwind City Patroller'),
(3296, 2, 0, '%s throws a rotten apple at $n.', 16, 0, 100, 0, 0, 0, 31671, 'Orgrimmar Grunt'),
(3296, 3, 0, '%s throws rotten banana on $n.', 16, 0, 100, 0, 0, 0, 31672, 'Orgrimmar Grunt'),
(3296, 4, 0, '%s spits on $n.', 16, 0, 100, 0, 0, 0, 31673, 'Orgrimmar Grunt'),
(3296, 5, 0, 'Monster!', 12, 0, 100, 0, 0, 0, 31662, 'Orgrimmar Grunt'),
(3296, 5, 1, 'Murderer!', 12, 0, 100, 0, 0, 0, 31679, 'Orgrimmar Grunt'),
(3296, 5, 2, 'GET A ROPE!', 12, 0, 100, 0, 0, 0, 31669, 'Orgrimmar Grunt'),
(3296, 5, 3, 'How dare you set foot in our city!', 12, 0, 100, 0, 0, 0, 31684, 'Orgrimmar Grunt'),
(3296, 5, 4, 'You disgust me.', 12, 0, 100, 0, 0, 0, 31680, 'Orgrimmar Grunt'),
(3296, 5, 5, 'Looks like we''re going to have ourselves an execution.', 12, 0, 100, 0, 0, 0, 31682, 'Orgrimmar Grunt'),
(3296, 5, 6, 'Traitorous dog.', 12, 0, 100, 0, 0, 0, 31665, 'Orgrimmar Grunt'),
(3296, 5, 7, 'My family was wiped out by the Scourge! MONSTER!', 12, 0, 100, 0, 0, 0, 31667, 'Orgrimmar Grunt'),
(14304, 0, 0, 'Taste blade, mongrel!', 12, 0, 100, 0, 0, 0, 10950, 'Kor''kron Elite - On Aggro'),
(14304, 0, 1, 'Please tell me that you didn''t just do what I think you just did. Please tell me that I''m not going to have to hurt you... ', 12, 0, 100, 0, 0, 0, 10951, 'Kor''kron Elite - On Aggro'),
(14304, 0, 2, 'As if we don''t have enough problems, you go and create more!', 12, 0, 100, 0, 0, 0, 10953, 'Kor''kron Elite - On Aggro'),
(14304, 0, 3, 'You dare spill blood on neutral ground? OUT! OUT, I SAY!', 12, 0, 100, 0, 0, 0, 10948, 'Kor''kron Elite - On Aggro'),
(14304, 0, 4, 'We don''t take kindly to miscreants, $r.', 12, 0, 100, 0, 0, 0, 10949, 'Kor''kron Elite - On Aggro'),
(14304, 0, 5, 'Get a rope!',12, 0, 100, 0, 0, 0, 10952, 'Kor''kron Elite - On Aggro'),
(14304, 0, 6, 'Believe me when I tell you this: You''re gonna wish you weren''t born, sissy!', 12, 0, 100, 0, 0, 0, 10954, 'Kor''kron Elite - On Aggro'),
(14304, 0, 7, 'Your actions shame us all, $c. I hurt inside as I beat you senseless.', 12, 0, 100, 0, 0, 0, 10955, 'Kor''kron Elite - On Aggro');

-- AIs
-- Stormwind City Guard SAI
SET @ENTRY := 68;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,10000,10000,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,@ENTRY*100+03,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - Within 1-10 Range Out of Combat LoS - Run Random Script"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On aggro - Say text1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=68;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,68,0,0,28,0,13188,0,0,0,"","Only Run script if quest is completed");

-- Kor''kron Elite SAI
SET @ENTRY := 14304;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,10000,10000,87,68*100+00,68*100+01,68*100+02,68*100+03,0,0,1,0,0,0,0,0,0,0,"Kor''kron Elite - Within 1-10 Range Out of Combat LoS - Run Random Script"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kor''kron Elite - On aggro - Say text1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=14304;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,14304,0,0,28,0,13189,0,0,0,"","Only Run script if quest is completed");

-- Stormwind City Patroller SAI
SET @ENTRY := 1976;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,10000,10000,87,68*100+00,68*100+01,68*100+02,68*100+03,0,0,1,0,0,0,0,0,0,0,"Stormwind City Patroller - Within 1-10 Range Out of Combat LoS - Run Random Script"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Patroller - On aggro - Say text1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=1976;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,1976,0,0,28,0,13188,0,0,0,"","Only Run script if quest is completed");

-- Stormwind Royal Guard SAI
SET @ENTRY := 1756;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,10000,10000,87,68*100+00,68*100+01,68*100+02,68*100+03,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - Within 1-10 Range Out of Combat LoS - Run Random Script");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=1756;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,1756,0,0,28,0,13188,0,0,0,"","Only Run script if quest is completed");

-- Orgrimmar Grunt SAI
SET @ENTRY := 3296;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,10000,10000,87,68*100+00,68*100+01,68*100+02,68*100+03,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Grunt - Within 1-10 Range Out of Combat LoS - Run Random Script"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgrimmar Grunt - On aggro - Say text1");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=3296;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,3296,0,0,28,0,13189,0,0,0,"","Only Run script if quest is completed");

-- Actionlist SAI
SET @ENTRY := 6800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58509,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Cast ''Rotten Apple Toss'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 2");

-- Actionlist SAI
SET @ENTRY := 6801;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58513,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Cast 'Rotten Banana Toss'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 3");

-- Actionlist SAI
SET @ENTRY := 6802;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,11,58520,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Cast 'Spit'"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 4");

-- Actionlist SAI
SET @ENTRY := 6803;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind City Guard - On Script - Say Line 5");


DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (58509, 58513, 58520);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(58509, 58511, 0, 'Rotten Apple - Rotten Apple'),
(58513, 58514, 0, 'Rotten Banana - Rotten Banana'),
(58520, 58519, 0, 'Spit - Spit');
