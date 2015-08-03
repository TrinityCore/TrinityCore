-- SAI for Opus
SET @ENTRY := 10262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,1,0,100,0,55000,65000,55000,65000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Opus - OOC - Say Random text');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -587 AND -582;
DELETE FROM `creature_text` WHERE `entry` IN (10262);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(10262,0,0, 'Bijou knows where treasures are hidden.',12,0,100,0,0,0, 'Opus - Random Say'),
(10262,0,1, 'SQUAWK!! *cough* *cough* I need to quit smoking!',12,0,100,0,0,0, 'Opus - Random Say'),
(10262,0,2, 'Ask Kibler about the treasure! SQUAWK!',12,0,100,0,0,0, 'Opus - Random Say'),
(10262,0,3, 'They all go to the Spire but none never come back... just like Bijou.',12,0,100,0,0,0, 'Opus - Random Say'),
(10262,0,4, 'Opus wants some Cuergo''s Gold... with worm.',12,0,100,0,0,0, 'Opus - Random Say'),
(10262,0,5, 'Kibler is being investigated by G.E.T.A.',12,0,100,0,0,0, 'Opus - Random Say');

-- SAI for Chok'sul
SET @ENTRY := 1210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chok''sul - On Aggro - Say Random text'),
(@ENTRY,0,1,0,0,0,100,0,4300,13200,10300,23000,11,18072,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Chok''sul - Combat - Cast Uppercut');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -369 AND -367;
DELETE FROM `creature_text` WHERE `entry` IN (1210);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1210,0,0, 'Huh? What dat?',12,0,100,0,0,0, 'Chok''sul - Random Say'),
(1210,0,1, 'Dat $R look gud to eat!',12,0,100,0,0,0, 'Chok''sul - Random Say'),
(1210,0,2, 'Bash it!',12,0,100,0,0,0, 'Chok''sul - Random Say');

-- SAI for Draenei Mourner
SET @ENTRY := 17073;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,1,0,100,0,25000,35000,45000,65000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Draenei Mourner - OOC - Say Random text');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -923 AND -911;
DELETE FROM `creature_text` WHERE `entry` IN (17073);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17073,0,0, '<Sobbing> I hate graveyards. So many dead. And my sweet Luhanaa.....',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,1, 'It should have been me!',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,2, 'Be at peace, my sweet, sweet, Luhanaa.',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,3, 'I''ll never forget you, my love.',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,4, 'If I ever find the ones responsible for the crash...!',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,5, 'We should never have come along.',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,6, 'Why, Luhanaa? Why?',12,0,100,6,0,0, 'Draenei Mourner - Random Say'),
(17073,0,7, 'I miss you so much!',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,8, 'You''ll always be here, with me.',12,0,100,1,0,0, 'Draenei Mourner - Random Say'),
(17073,0,9, 'Draenei Mourner weeps softly.',16,0,100,18,0,0, 'Draenei Mourner - Random Say'),
(17073,0,10, 'Draenei Mourner bows his head and sighs, clearly exhausted.',16,0,100,2,0,0, 'Draenei Mourner - Random Say'),
(17073,0,11, 'Draenei Mourner breaks down into huge, wracking sobs.',16,0,100,18,0,0, 'Draenei Mourner - Random Say'),
(17073,0,12, 'Draenei Mourner stares in silence at the graver marker before him.',16,0,100,0,0,0, 'Draenei Mourner - Random Say');

-- SAI for Guard Captain Cragtar
SET @ENTRY := 16589;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,1,0,100,0,450000,450000,450000,450000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 0'),
(@ENTRY,0,1,0,1,0,100,0,453000,453000,453000,453000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 1'),
(@ENTRY,0,2,0,1,0,100,0,457000,457000,457000,457000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 2'),
(@ENTRY,0,3,0,1,0,100,0,460000,460000,460000,460000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 3'),
(@ENTRY,0,4,0,1,0,100,0,461000,461000,461000,461000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 4'),
(@ENTRY,0,5,0,1,0,100,0,466000,466000,466000,466000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 5'),
(@ENTRY,0,6,0,1,0,100,0,468000,468000,468000,468000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 6'),
(@ENTRY,0,7,0,1,0,100,0,470000,470000,470000,470000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Guard Captain Cragtar - OOC - Say text 7');

-- NPC talk text convert from creature_ai_text
-- DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -293 AND -286;
DELETE FROM `creature_text` WHERE `entry` IN (16589);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16589,0,0, 'So there we were - me and the battalion, doing a routine recon down the bone road. We''d sent the scout up ahead to look around in case anything dangerous come up.',12,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 0'),
(16589,1,0, 'Sure enough, scount came runnin'' back, talkin'' bout some orcs down the path. They hadn''t seen us yet so we figured we''d go get aquainted.',12,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 1'),
(16589,2,0, 'Big red bastards! Bigger than any orc I''d ever seen. Muscles out to here, tusks out to here...',12,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 2'),
(16589,3,0, '%s nods.',16,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 3'),
(16589,4,0, 'Fel orcs...',12,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 4'),
(16589,5,0, 'I dunno, grunt. I just - don''t - know...',12,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 5'),
(16589,6,0, 'But that''s not the worst of it. Before I could pull us back, a group of ''em spotted us and attacked.',12,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 6'),
(16589,7,0, 'Lost some of my best soldiers that day...',12,0,100,0,0,0, 'Guard Captain Cragtar - Speech Text 7');
