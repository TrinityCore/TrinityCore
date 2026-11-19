-- SAI for Defias Messenger
SET @ENTRY := 550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Messenger - On Aggro - Say Random text'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Defias Messenger - HP@15% - Flee');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -211 AND -209;
DELETE FROM `creature_text` WHERE `entry` IN (550);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(550,0,0, 'I have a special message for $N. And it says you must die!',12,0,100,0,0,0, 'Defias Messenger - Aggro Random Say'),
(550,0,1, 'I''ll deliver you, weak $C, to the afterlife!',12,0,100,0,0,0, 'Defias Messenger - Aggro Random Say'),
(550,0,2, 'Die in the name of Edwin van Cleef!',12,0,100,0,0,0, 'Defias Messenger - Aggro Random Say');

-- SAI for Cursed Sailor
SET @ENTRY := 1157;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cursed Sailor - On Aggro - Say Random text');

-- SAI for Cursed Marine
SET @ENTRY := 1158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Cursed Marine - On Aggro - Say Random text'),
(@ENTRY,0,1,2,0,0,100,0,4200,19600,27500,57700,11,10651,32,0,0,0,0,2,0,0,0,0,0,0,0, 'Cursed Marine - Combat - Cast Curse of the Eye'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,3360,32,0,0,0,0,2,0,0,0,0,0,0,0, 'Cursed Marine - Combat - Cast Curse of the Eye');

-- SAI for Captain Halyndor
SET @ENTRY := 1160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Captain Halyndor - On Aggro - Say Random text'),
(@ENTRY,0,1,2,0,0,100,0,3600,4800,11000,23300,11,10651,32,0,0,0,0,4,0,0,0,0,0,0,0, 'Cursed Marine - Combat - Cast Curse of the Eye'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,3360,32,0,0,0,0,4,0,0,0,0,0,0,0, 'Cursed Marine - Combat - Cast Curse of the Eye'),
(@ENTRY,0,3,0,0,0,100,0,7300,8300,11000,26400,11,3389,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Captain Halyndor - Combat - Cast Ward of the Eye');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE `entry` IN (-42,-103,-161);
DELETE FROM `creature_text` WHERE `entry` IN (1157,1158,1160);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1157,0,0, 'Time to join us, $C.',12,0,100,0,0,0, 'Cursed Sailor - Aggro Random Say'),
(1157,0,1, 'Brains...',12,0,100,0,0,0, 'Cursed Sailor - Aggro Random Say'),
(1157,0,2, 'A living $R... soon to be a dead like me.',12,0,100,0,0,0, 'Cursed Sailor - Aggro Random Say'),
(1158,0,0, 'Time to join us, $C.',12,0,100,0,0,0, 'Cursed Marine - Aggro Random Say'),
(1158,0,1, 'Brains...',12,0,100,0,0,0, 'Cursed Marine - Aggro Random Say'),
(1158,0,2, 'A living $R... soon to be a dead like me.',12,0,100,0,0,0, 'Cursed Marine - Aggro Random Say'),
(1160,0,0, 'Time to join us, $C.',12,0,100,0,0,0, 'Captain Halyndor - Aggro Random Say'),
(1160,0,1, 'Brains...',12,0,100,0,0,0, 'Captain Halyndor - Aggro Random Say'),
(1160,0,2, 'A living $R... soon to be a dead like me.',12,0,100,0,0,0, 'Captain Halyndor - Aggro Random Say');

-- SAI for Mottled Screecher
SET @ENTRY := 1021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,2,0,100,1,0,20,0,0,39,20,0,0,0,0,0,0,0,0,0,0,0,0,0, 'Mottled Screecher - HP@20% - Call for help'),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mottled Screecher - HP@20% - Say text');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE `entry` IN (-100);
DELETE FROM `creature_text` WHERE `entry` IN (1021);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1021,0,0, '%s lets out a high pitched screech, calling for help!',16,0,100,0,0,0, 'Mottled Screecher - Call for help Say');

-- SAI for Spectral Stable Hand
SET @ENTRY := 15551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,0,0,100,2,7000,7000,15000,15000,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Spectral Stable Hand - Combat - Cast Knockdown'),
(@ENTRY,0,1,0,0,0,100,2,4000,4000,45000,45000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Spectral Stable Hand - Combat - Cast Pierce Armor'),
(@ENTRY,0,2,3,14,0,100,3,38400,40,60000,60000,11,29339,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Spectral Stable Hand - Combat - Cast Healing Touch on Ally'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,29340,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Spectral Stable Hand - Combat - Cast Whip Frenzy on Ally'),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Spectral Stable Hand - On Death - Say text');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE `entry` IN (-40,-41);
DELETE FROM `creature_text` WHERE `entry` IN (15551);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15551,0,0, 'Is this the end?',14,0,100,0,0,0, 'Spectral Stable Hand - On Death Say'),
(15551,0,1, 'What will become of...',12,0,100,0,0,0, 'Spectral Stable Hand - On Death Say');
