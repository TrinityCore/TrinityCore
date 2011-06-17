-- SAI for Grom'tor, Son of Oronok & Coilskar Commander (Shadowmoon Valley)
SET @ENTRY := 21291;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-2815.424,`position_y`=1771.031,`position_z`=59.10168,`orientation`=4.967079 WHERE `guid`=74574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
-- AI
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - On spawn - Start WP movement'),
(@ENTRY,0,1,0,1,0,100,0,10000,30000,240000,240000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - OOC - Run Script'),
-- Script
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Pause path'),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,1,0,0,0,-2814.744,1774.838,59.49939,0, 'Grom''tor, Son of Oronok - Script - Move to'),
(@ENTRY*100,9,2,0,0,0,100,0,1200,1200,0,0,66,0,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Turn to Coilskar Commander'),
(@ENTRY*100,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 0'),
(@ENTRY*100,9,4,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 1'),
(@ENTRY*100,9,5,0,0,0,100,0,3000,3000,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - do emote 5'),
(@ENTRY*100,9,6,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Coilskar Commander Say text 0'),
(@ENTRY*100,9,7,0,0,0,100,0,1000,1000,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Resume path'),
(@ENTRY*100,9,8,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Coilskar Commander Say text 1'),
(@ENTRY*100,9,9,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 2'),
(@ENTRY*100,9,10,0,0,0,100,0,2000,2000,0,0,54,26000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Pause path'),
(@ENTRY*100,9,11,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 3'),
(@ENTRY*100,9,12,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Coilskar Commander Say text 2'),
(@ENTRY*100,9,13,0,0,0,100,0,5000,5000,0,0,69,0,0,0,0,0,0,1,0,0,0,-2814.744,1774.838,59.49939,0, 'Grom''tor, Son of Oronok - Script - Move to'),
(@ENTRY*100,9,14,0,0,0,100,0,1500,1500,0,0,66,0,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Turn to Coilskar Commander'),
(@ENTRY*100,9,15,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 4'),
(@ENTRY*100,9,16,0,0,0,100,0,2000,2000,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - do emote 25'),
(@ENTRY*100,9,17,0,0,0,100,0,1500,1500,0,0,11,36538,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - cast 36538 on Coilskar Commander'),
(@ENTRY*100,9,18,0,0,0,100,0,1200,1200,0,0,11,36540,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - cast 36540 on Coilskar Commander'),
(@ENTRY*100,9,19,0,0,0,100,0,1200,1200,0,0,11,36538,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - cast 36538 on Coilskar Commander'),
(@ENTRY*100,9,20,0,0,0,100,0,1200,1200,0,0,11,36538,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - cast 36538 on Coilskar Commander'),
(@ENTRY*100,9,21,0,0,0,100,0,1200,1200,0,0,11,36540,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - cast 36540 on Coilskar Commander'),
(@ENTRY*100,9,22,0,0,0,100,0,1200,1200,0,0,11,36539,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - cast 36539 on Coilskar Commander'),
(@ENTRY*100,9,23,0,0,0,100,0,1500,1500,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 5'),
(@ENTRY*100,9,24,0,0,0,100,0,500,500,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 6'),
(@ENTRY*100,9,25,0,0,0,100,0,2500,2500,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Resume path'),
(@ENTRY*100,9,26,0,0,0,100,0,2500,2500,0,0,54,16000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Pause path'),
(@ENTRY*100,9,27,0,0,0,100,0,100,100,0,0,66,0,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Turn to Coilskar Commander'),
(@ENTRY*100,9,28,0,0,0,100,0,500,500,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Say text 7'),
(@ENTRY*100,9,29,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Coilskar Commander Say text 4'),
(@ENTRY*100,9,30,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,19,21295,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Coilskar Commander Say text 5'),
(@ENTRY*100,9,31,0,0,0,100,0,4000,4000,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Grom''tor, Son of Oronok - Script - Resume path');
-- Waypoints for Grom'tor, Son of Oronok from sniff
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-2817.188,1777.806,60.35168, 'Grom''tor, Son of Oronok'),
(@ENTRY,2,-2815.424,1771.031,59.10168, 'Grom''tor, Son of Oronok');
-- SAI for Coilskar Commander
SET @ENTRY := 21295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY; 
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,8,0,100,0,36539,0,0,0,11,36542,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coilskar Commander - On Spellhit 36539 - cast 36542 on self'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coilskar Commander - On Spellhit 36539 - set bytes1 7'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coilskar Commander - On Spellhit 36539 - set phase 1'),
(@ENTRY,0,3,4,1,1,100,0,6000,6000,6000,6000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coilskar Commander - On Spellhit 36539 - Coilskar Commander Say text 3 (phase 1)'),
(@ENTRY,0,4,5,61,1,100,0,0,0,0,0,28,36542,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coilskar Commander - On Spellhit 36539 - remove aura 36542 (phase 1)'),
(@ENTRY,0,5,6,61,1,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coilskar Commander - On Spellhit 36539 - unset bytes1 7 (phase 1)'),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Coilskar Commander - On Spellhit 36539 - set phase 0 (phase 1)');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (21291,21295);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(21291,0,0, 'I''m through asking nicely, fish-man.',12,0,100,25,0,0, 'Grom''tor, Son of Oronok'),
(21291,1,0, 'Where is the Cipher of Damnation? I know a third of it is in this village.',12,0,100,6,0,0, 'Grom''tor, Son of Oronok'),
(21295,0,0, 'Whhaaat... are you sssspeaking of, ssssoft-sskin?',12,0,100,1,0,0, 'Coilskar Commander'),
(21295,1,0, 'The naga do nottt... have thissss... cipherrr...',12,0,100,1,0,0, 'Coilskar Commander'),
(21291,2,0, 'No... Of course not. What was I thinking? Why would you have a third of the Cipher of Damnation?',12,0,100,274,0,0, 'Grom''tor, Son of Oronok'),
(21291,3,0, 'I feel so stupid. Maybe I should unchain you and set you free?',12,0,100,11,0,0, 'Grom''tor, Son of Oronok'),
(21295,2,0, 'Yesss... Yesss... Ssset me freee...',12,0,100,1,0,0, 'Coilskar Commander'),
(21291,4,0, 'DO I HONESTLY LOOK THAT STUPID TO YOU, NAGA? NOW YOU FEEL PAIN!',12,0,100,5,0,0, 'Grom''tor, Son of Oronok'),
(21291,5,0, '%s spits on the Coilskar naga.',16,0,100,5,0,0, 'Grom''tor, Son of Oronok'),
(21291,6,0, 'GET UP YOU ROTTEN PIECE OF TRASH! GET UP BEFORE I END YOU!',12,0,100,5,0,0, 'Grom''tor, Son of Oronok'),
(21295,3,0, '%s regains consciousness.',16,0,100,0,0,0, 'Coilskar Commander'),
(21291,7,0, 'I''m listening...',12,0,100,273,0,0, 'Grom''tor, Son of Oronok'),
(21295,4,0, 'Do not beat the Coilsssskaarrr commander anymore, orc! I will tell you! The cipherrr... It is hidden in one of the chests at Coilssskarrr Point... The naga there hold the keysss...',12,0,100,1,0,0, 'Coilskar Commander'),
(21295,5,0, 'COILSSSKARRR!',12,0,100,15,0,0, 'Coilskar Commander');
