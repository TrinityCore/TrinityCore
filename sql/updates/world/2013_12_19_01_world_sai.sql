-- Bloodmaul Skirmisher SAI
SET @ENTRY := 19948;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Skirmisher - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Skirmisher - On Aggro - Say text 0"),
(@ENTRY,0,2,0,2,0,100,0,10000,12000,10000,12000,11,37786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Skirmisher - In Combat - Cast Bloodmaul Rage");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bloodmaul Skirmisher on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bloodmaul Skirmisher on Aggro Text'),
(@ENTRY,0,2, 'Me angered. Raaah!',12,0,100,0,0,0, 'Bloodmaul Skirmisher on Aggro Text'),
(@ENTRY,0,3, 'I''ll crush you!',12,0,100,0,0,0, 'Bloodmaul Skirmisher on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Skirmisher on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Skirmisher on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Skirmisher on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Skirmisher on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Skirmisher on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Skirmisher on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Skirmisher says text on death if quest 11000 is rewarded');

-- Bloodmaul Mauler SAI
SET @ENTRY := 19993;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Mauler - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Mauler - On Aggro - Say text 0"),
(@ENTRY,0,2,0,2,0,100,0,10000,12000,10000,12000,11,37786,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Mauler - In Combat - Cast Bloodmaul Rage");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bloodmaul Mauler on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bloodmaul Mauler on Aggro Text'),
(@ENTRY,0,2, 'Me angered. Raaah!',12,0,100,0,0,0, 'Bloodmaul Mauler on Aggro Text'),
(@ENTRY,0,3, 'I''ll crush you!',12,0,100,0,0,0, 'Bloodmaul Mauler on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Mauler on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Mauler on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Mauler on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Mauler on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Mauler on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Mauler on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Mauler says text on death if quest 11000 is rewarded');

-- Bloodmaul Warlock SAI
SET @ENTRY := 19994;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Warlock - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Out Of Combat - Cast Demon Armor"),
(@ENTRY,0,2,0,1,0,100,0,3000,3000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Out Of Combat - Cast Summon Imp"),
(@ENTRY,0,3,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Warlock - On Aggro - Say text 0"),
(@ENTRY,0,4,0,0,0,100,0,0,0,2400,3800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Warlock - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,5,0,2,0,100,1,0,20,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Warlock - Between 0-20% Health - Flee for assist");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Me smash! You die!',12,0,100,0,0,0, 'Bloodmaul Warlock on Aggro Text'),
(@ENTRY,0,1, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Warlock on Aggro Text'),
(@ENTRY,0,2, 'I''ll crush you!',12,0,100,0,0,0, 'Bloodmaul Warlock on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Warlock on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Warlock on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Warlock on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Warlock on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Warlock on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Warlock on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Warlock says text on death if quest 11000 is rewarded');

-- Bladespire Crusher SAI
SET @ENTRY := 20765;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Crusher - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Crusher - on Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,10000,20000,11,15496,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Crusher - In Combat - Cast Cleave'),
(@ENTRY,0,3,4,2,0,100,0,0,30,35000,45000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Crusher - HP below 30% - Cast Enrage'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Crusher - HP below 30% - Say text 2");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bladespire Crusher on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bladespire Crusher on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Crusher on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Crusher on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Crusher on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Crusher on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Crusher on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Crusher on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Crusher on death Quest 11000 complete'),
(@ENTRY,2,0, '%s becomes enraged!',16,0,100,0,0,0, 'Bladespire Crusher on enrage');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Crusher says text on death if quest 11000 is rewarded');

-- Bladespire Mystic SAI
SET @ENTRY := 20766;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Mystic - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Mystic - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Mystic - Out of Combat - Cast Lightning Shield'),
(@ENTRY,0,3,0,0,0,100,0,6000,9000,17000,17000,11,37599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Mystic - In Combat - Cast Bloodlust'),
(@ENTRY,0,4,0,14,0,100,0,3000,40,15000,18000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,'Bladespire Mystic - Friendly HP below 60% - Cast Healing Wave');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bladespire Mystic on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bladespire Mystic on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Mystic on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Mystic on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Mystic on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Mystic on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Mystic on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Mystic on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Mystic on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Mystic says text on death if quest 11000 is rewarded');

-- Gnosh Brognat SAI
SET @ENTRY := 20768;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gnosh Brognat - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gnosh Brognat - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,15000,20000,15000,20000,11,37597,0,0,0,0,0,2,0,0,0,0,0,0,0,'Gnosh Brognat - In Combat - Cast Meat Slap'),
(@ENTRY,0,3,0,0,0,100,0,15000,20000,15000,20000,11,37596,32,0,0,0,0,2,0,0,0,0,0,0,0,'Gnosh Brognat - In Combat - Cast Tenderize');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Gnosh Brognat on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Gnosh Brognat on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Gnosh Brognat on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Gnosh Brognat on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Gnosh Brognat on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Gnosh Brognat on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Gnosh Brognat on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Gnosh Brognat on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Gnosh Brognat on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Gnosh Brognat says text on death if quest 11000 is rewarded');

-- Bloodmaul Drudger SAI
SET @ENTRY := 21238;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Drudger - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodmaul Drudger - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,30000,30000,11,35918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bloodmaul Drudger - In Combat - Cast Puncture Armor'),
(@ENTRY,0,3,4,2,0,100,0,0,30,35000,45000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodmaul Drudger - HP below 30% - Cast Enrage'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Drudger - HP below 30% - Say text 2");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bloodmaul Drudger on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bloodmaul Drudger on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Drudger on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Drudger on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Drudger on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Drudger on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Drudger on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Drudger on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Drudger on death Quest 11000 complete'),
(@ENTRY,2,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Bloodmaul Drudger on enrage');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Drudger says text on death if quest 11000 is rewarded');

-- Bloodmaul Brute SAI
SET @ENTRY := 19991;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Brute - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodmaul Brute - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,9000,12000,11,15496,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodmaul Brute - In Combat - Cast Cleave'),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,18000,22000,11,37577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bloodmaul Brute - In Combat - Cast Debilitating Strike'),
(@ENTRY,0,4,5,2,0,100,0,0,30,35000,45000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodmaul Brute - HP below 30% - Cast Enrage'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Brute - HP below 30% - Say text 2");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bloodmaul Brute on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bloodmaul Brute on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Brute on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Brute on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Brute on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Brute on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Brute on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Brute on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Brute on death Quest 11000 complete'),
(@ENTRY,2,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Bloodmaul Brute on enrage');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Brute says text on death if quest 11000 is rewarded');

-- Bloodmaul Shaman SAI
SET @ENTRY := 19992;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Shaman - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,1,0,100,0,0,0,60000,60000,11,12550,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Shaman - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Shaman - On Aggro - Say text 0"),
(@ENTRY,0,3,0,0,0,50,0,6000,6000,50000,50000,11,15038,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Shaman - In Combat - Cast Scorching Totem"),
(@ENTRY,0,4,0,0,0,100,0,12000,12000,45000,45000,11,15869,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Shaman - In Combat - Cast Superior Healing Ward");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Me smash! You die!',12,0,100,0,0,0, 'Bloodmaul Shaman on Aggro Text'),
(@ENTRY,0,1, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Shaman on Aggro Text'),
(@ENTRY,0,2, 'I''ll crush you!',12,0,100,0,0,0, 'Bloodmaul Shaman on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Shaman on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Shaman on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Shaman on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Shaman on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Shaman on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Shaman on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Shaman says text on death if quest 11000 is rewarded');

-- Grimnok Battleborn SAI
SET @ENTRY := 20095;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimnok Battleborn - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,0,0,100,0,6000,10000,6000,10000,11,15496,0,0,0,0,0,1,0,0,0,0,0,0,0,'Grimnok Battleborn - In Combat - Cast Cleave'),
(@ENTRY,0,2,3,0,0,100,0,10000,12000,10000,12000,11,37786,0,0,0,0,0,1,0,0,0,0,0,0,0,'Grimnok Battleborn - In Combat - Cast Bloodmaul Rage'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimnok Battleborn - In Combat - Say text 0 when cast Cast Bloodmaul Rage"),
(@ENTRY,0,4,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimnok Battleborn - On Aggro - Say text 0"),
(@ENTRY,0,5,0,1,0,100,0,120000,120000,180000,180000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimnok Battleborn - Out of Combat - Say text 2");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Grimnok Battleborn on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Grimnok Battleborn on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Grimnok Battleborn on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Grimnok Battleborn on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Grimnok Battleborn on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Grimnok Battleborn on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Grimnok Battleborn on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Grimnok Battleborn on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Grimnok Battleborn on death Quest 11000 complete'),
(@ENTRY,2,0, 'You! I see you! One of you, kill them!',14,0,100,0,0,0, 'Grimnok Battleborn OOC'),
(@ENTRY,2,1, 'Don''t let any escape, you dogs!',14,0,100,0,0,0, 'Grimnok Battleborn OOC'),
(@ENTRY,2,2, 'I want these Alliance and Horde pigs dead!',14,0,100,0,0,0, 'Grimnok Battleborn OOC'),
(@ENTRY,2,3, 'Get up there. March on Bladespire Hold. I want to adorn my tower with Gorr''Dim''s head!',14,0,100,0,0,0, 'Grimnok Battleborn OOC');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Grimnok Battleborn says text on death if quest 11000 is rewarded');

-- Bloodmaul Brewmaster SAI
SET @ENTRY := 19957;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Brewmaster - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Brewmaster - On Aggro - Say text 0"),
(@ENTRY,0,2,0,0,0,85,0,6000,6000,30000,35000,11,37591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Brewmaster - In Combat - Cast Drunken Haze");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bloodmaul Brewmaster on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bloodmaul Brewmaster on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Brewmaster on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Brewmaster on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Brewmaster on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Brewmaster on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Brewmaster on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Brewmaster on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Brewmaster on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Brewmaster says text on death if quest 11000 is rewarded');

-- Bloodmaul Geomancer SAI
SET @ENTRY := 19952;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Geomancer - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Geomancer - On Aggro - Say text 0"),
(@ENTRY,0,2,0,1,0,100,0,0,0,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Geomancer - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,3,0,4,0,50,0,0,0,0,0,11,6136,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Geomancer - On Aggro - Cast Chilled"),
(@ENTRY,0,4,0,0,0,100,0,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Geomancer - In Combat CMC - Cast Fireball");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Me smash! You die!',12,0,100,0,0,0, 'Bloodmaul Geomancer on Aggro Text'),
(@ENTRY,0,1, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Geomancer on Aggro Text'),
(@ENTRY,0,2, 'I''ll crush you!',12,0,100,0,0,0, 'Bloodmaul Geomancer on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Geomancer on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Geomancer on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Geomancer on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Geomancer on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Geomancer on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Geomancer on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Geomancer says text on death if quest 11000 is rewarded');

-- Bladespire Brute SAI
SET @ENTRY := 19995;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Brute - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Brute - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,8000,18000,11,15496,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Brute - In Combat - Cast Cleave');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bladespire Brute on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bladespire Brute on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Brute on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Brute on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Brute on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Brute on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Brute on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Brute on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Brute on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Brute says text on death if quest 11000 is rewarded');

-- Bladespire Shaman SAI
SET @ENTRY := 19998;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Shaman - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,1,0,100,0,0,0,60000,60000,11,12550,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bladespire Shaman - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Shaman - On Aggro - Say text 0"),
(@ENTRY,0,3,0,0,0,100,0,2000,4000,8000,12000,11,26098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Shaman - In Combat - Cast Lightning Bolt");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Me smash! You die!',12,0,100,0,0,0, 'Bladespire Shaman on Aggro Text'),
(@ENTRY,0,1, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Shaman on Aggro Text'),
(@ENTRY,0,2, 'I''ll crush you!',12,0,100,0,0,0, 'Bladespire Shaman on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Shaman on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Shaman on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Shaman on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Shaman on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Shaman on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Shaman on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Shaman says text on death if quest 11000 is rewarded');

-- Bladespire Cook SAI
SET @ENTRY := 20334;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Cook - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Cook - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,15000,20000,15000,20000,11,37597,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bladespire Cook - In Combat - Cast Meat Slap'),
(@ENTRY,0,3,0,0,0,100,0,15000,20000,15000,20000,11,37596,32,0,0,0,0,2,0,0,0,0,0,0,0,'Bladespire Cook - In Combat - Cast Tenderize');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bladespire Cook on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bladespire Cook on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Cook on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Cook on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Cook on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Cook on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Cook on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Cook on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Cook on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Cook says text on death if quest 11000 is rewarded');

-- Bladespire Champion SAI
SET @ENTRY := 21296;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Champion - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Champion - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,10000,14000,11000,22000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Champion - In Combat - Cast Thunderclap'),
(@ENTRY,0,3,0,9,0,100,0,5,10,2000,2000,11,37777,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bladespire Champion - Range 5 - 10 yards - Cast Mighty Charge');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bladespire Champion on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bladespire Champion on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Champion on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Champion on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Champion on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Champion on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Champion on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Champion on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Champion on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Champion says text on death if quest 11000 is rewarded');

-- Bloodmaul Taskmaster SAI
SET @ENTRY := 22160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Taskmaster - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodmaul Taskmaster - On Aggro - Say Text 0'),
(@ENTRY,0,2,3,0,0,100,0,10000,12000,10000,12000,11,37786,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bloodmaul Taskmaster - In Combat - Cast Bloodmaul Rage'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Taskmaster - In Combat - Say text 0 when cast Cast Bloodmaul Rage");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bloodmaul Taskmaster on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bloodmaul Taskmaster on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Taskmaster on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Taskmaster on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Taskmaster on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Taskmaster on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Taskmaster on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Taskmaster on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Taskmaster on death Quest 11000 complete'),
(@ENTRY,2,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Bloodmaul Taskmaster on enrage');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Taskmaster says text on death if quest 11000 is rewarded');

-- Bloodmaul Soothsayer SAI
SET @ENTRY := 22384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Soothsayer - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,13787,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Soothsayer - Out Of Combat - Cast Demon Armor"),
(@ENTRY,0,2,0,1,0,100,0,3000,3000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Soothsayer - Out Of Combat - Cast Summon Imp"),
(@ENTRY,0,3,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Soothsayer - On Aggro - Say text 0"),
(@ENTRY,0,4,0,0,0,100,0,0,0,2400,3800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodmaul Soothsayer - In Combat - Cast Shadow Bolt"),
(@ENTRY,0,5,0,2,0,100,1,0,20,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmaul Soothsayer - Between 0-20% Health - Flee for assist");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Me smash! You die!',12,0,100,0,0,0, 'Bloodmaul Soothsayer on Aggro Text'),
(@ENTRY,0,1, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bloodmaul Soothsayer on Aggro Text'),
(@ENTRY,0,2, 'I''ll crush you!',12,0,100,0,0,0, 'Bloodmaul Soothsayer on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bloodmaul Soothsayer on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bloodmaul Soothsayer on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bloodmaul Soothsayer on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bloodmaul Soothsayer on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bloodmaul Soothsayer on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bloodmaul Soothsayer on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bloodmaul Soothsayer says text on death if quest 11000 is rewarded');

-- Bladespire Battlemage SAI
SET @ENTRY := 19996;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Battlemage - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,1,0,100,0,0,0,60000,60000,11,12550,1,1,0,0,0,1,0,0,0,0,0,0,0,"Bladespire Battlemage - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Battlemage - On Aggro - Say text 0"),
(@ENTRY,0,3,0,0,0,100,0,8000,16000,8000,16000,11,16102,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Battlemage - In Combat - Cast Flamestrike"),
(@ENTRY,0,4,0,0,0,100,0,6000,9000,17000,17000,11,37599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Battlemage - In Combat - Cast Bloodlust');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Me smash! You die!',12,0,100,0,0,0, 'Bladespire Battlemage on Aggro Text'),
(@ENTRY,0,1, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Battlemage on Aggro Text'),
(@ENTRY,0,2, 'I''ll crush you!',12,0,100,0,0,0, 'Bladespire Battlemage on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Battlemage on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Battlemage on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Battlemage on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Battlemage on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Battlemage on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Battlemage on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Battlemage says text on death if quest 11000 is rewarded');

-- Bladespire Enforcer SAI
SET @ENTRY := 19997;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Enforcer - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Enforcer - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,10000,14000,11000,22000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Enforcer - In Combat - Cast Thunderclap'),
(@ENTRY,0,3,4,2,0,100,0,0,30,35000,45000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Enforcer - HP below 30% - Cast Enrage'),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Enforcer - HP below 30% - Say text 2");
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bladespire Enforcer on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bladespire Enforcer on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Enforcer on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Enforcer on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Enforcer on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Enforcer on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Enforcer on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Enforcer on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Enforcer on death Quest 11000 complete'),
(@ENTRY,2,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'Bladespire Enforcer on enrage');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Enforcer says text on death if quest 11000 is rewarded');

-- Bladespire Chef SAI
SET @ENTRY := 20756;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bladespire Chef - On Death - Say text 1 CONDITIONED"),
(@ENTRY,0,1,0,4,0,35,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Bladespire Chef - On Aggro - Say Text 0'),
(@ENTRY,0,2,0,0,0,100,0,15000,20000,15000,20000,11,37597,0,0,0,0,0,2,0,0,0,0,0,0,0,'Bladespire Chef - In Combat - Cast Meat Slap'),
(@ENTRY,0,3,0,0,0,100,0,15000,20000,15000,20000,11,37596,32,0,0,0,0,2,0,0,0,0,0,0,0,'Bladespire Chef - In Combat - Cast Tenderize');
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Stupid puny thing.  Me smash!',12,0,100,0,0,0, 'Bladespire Chef on Aggro Text'),
(@ENTRY,0,1, 'Me mad. You get smash in face!',12,0,100,0,0,0, 'Bladespire Chef on Aggro Text'),
(@ENTRY,0,2, 'Raaar!!! Me smash $r!',12,0,100,0,0,0, 'Bladespire Chef on Aggro Text'),
(@ENTRY,1,0, 'Puny $r... you were a... horrible king.',12,0,100,0,0,0, 'Bladespire Chef on death Quest 11000 complete'),
(@ENTRY,1,1, 'Agh... me am...dead.',12,0,100,0,0,0, 'Bladespire Chef on death Quest 11000 complete'),
(@ENTRY,1,2, 'Me go to Ogri''la.',12,0,100,0,0,0, 'Bladespire Chef on death Quest 11000 complete'),
(@ENTRY,1,3, 'King think... there really is... an Ogri''la',12,0,100,0,0,0, 'Bladespire Chef on death Quest 11000 complete'),
(@ENTRY,1,4, 'Me honored... king kill me.',12,0,100,0,0,0, 'Bladespire Chef on death Quest 11000 complete'),
(@ENTRY,1,5, 'King $n, me die now.',12,0,100,0,0,0, 'Bladespire Chef on death Quest 11000 complete');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,@ENTRY,0,0,8,0,11000,0,0,0,0,0, '', 'SAI - Bladespire Chef says text on death if quest 11000 is rewarded');
