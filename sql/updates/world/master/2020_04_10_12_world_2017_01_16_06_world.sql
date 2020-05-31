-- Warden Nork Bloodfrenzy SAI
SET @ENTRY := 25379;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,4,0,1,0,100,0,10000,10000,470000,470000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 2537900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,2000,2000,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,0,10000,0,0,0,0,10,125421,25426,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,8000,8000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Play Emote 11"),
(@ENTRY,9,4,0,0,0,100,0,2000,2000,0,0,1,2,1000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 2"),
(@ENTRY,9,5,0,0,0,100,0,1000,1000,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 3"),
(@ENTRY,9,6,0,0,0,100,0,5000,5000,0,0,1,1,6000,0,0,0,0,10,125421,25426,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 1"),
(@ENTRY,9,7,0,0,0,100,0,6000,6000,0,0,1,4,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 4"),
(@ENTRY,9,8,0,0,0,100,0,3000,3000,0,0,1,5,10000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 5"),
(@ENTRY,9,9,0,0,0,100,0,5000,5000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Play Emote 1"),
(@ENTRY,9,10,0,0,0,100,0,5000,5000,0,0,1,2,8000,0,0,0,0,10,125421,25426,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 2"),
(@ENTRY,9,11,0,0,0,100,0,8000,8000,0,0,1,6,9000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 6"),
(@ENTRY,9,12,0,0,0,100,0,5000,5000,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Play Emote 1"),
(@ENTRY,9,13,0,0,0,100,0,4000,4000,0,0,1,7,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 7"),
(@ENTRY,9,14,0,0,0,100,0,5000,5000,0,0,1,8,7000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 8"),
(@ENTRY,9,15,0,0,0,100,0,7000,7000,0,0,1,3,3000,0,0,0,0,10,125421,25426,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 3"),
(@ENTRY,9,16,0,0,0,100,0,3000,3000,0,0,1,4,5000,0,0,0,0,10,125421,25426,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 4"),
(@ENTRY,9,17,0,0,0,100,0,5000,5000,0,0,1,5,3000,0,0,0,0,10,125421,25426,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 5"),
(@ENTRY,9,18,0,0,0,100,0,3000,3000,0,0,1,6,5000,0,0,0,0,10,125421,25426,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 6"),
(@ENTRY,9,19,0,0,0,100,0,5000,5000,0,0,1,9,2000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 9"),
(@ENTRY,9,20,0,0,0,100,0,2000,2000,0,0,1,10,7000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 10"),
(@ENTRY,9,21,0,0,0,100,0,4000,4000,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Play Emote 15"),
(@ENTRY,9,22,0,0,0,100,0,3000,3000,0,0,1,11,6000,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Say Line 11"),
(@ENTRY,9,23,0,0,0,100,0,3000,3000,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Play Emote 5"),
(@ENTRY,9,24,0,0,0,100,0,2000,2000,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Nork Bloodfrenzy - On Script - Set Active Off");

DELETE FROM `creature_text` WHERE `CreatureID`=25379 AND `GroupID` >=1;
DELETE FROM `creature_text` WHERE `CreatureID`=25426;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
-- Warden Nork Bloodfrenzy
(25379, 1, 0, 'Look at \'em, Ug. You know what those are?', 12, 1, 100, 25, 0, 0, 24631, 'Warden Nork Bloodfrenzy'),
(25379, 2, 0, 'Those...', 12, 1, 100, 25, 0, 0, 24633, 'Warden Nork Bloodfrenzy'),
(25379, 3, 0, 'Those are cowards.', 12, 1, 100, 1, 0, 0, 24634, 'Warden Nork Bloodfrenzy'),
(25379, 4, 0, '%s shakes his head.', 16, 1, 100, 274, 0, 0, 24636, 'Warden Nork Bloodfrenzy'),
(25379, 5, 0, 'No, blood of my blood, they are soldiers of the Alliance. Our sworn enemies.', 12, 1, 100, 1, 0, 0, 24637, 'Warden Nork Bloodfrenzy'),
(25379, 6, 0, 'They are here because they do not wish to defend their homes... their families...', 12, 1, 100, 1, 0, 0, 24639, 'Warden Nork Bloodfrenzy'),
(25379, 7, 0, 'They have given up and surrendered - willingly - to us.', 12, 1, 100, 1, 0, 0, 24640, 'Warden Nork Bloodfrenzy'),
(25379, 8, 0, 'Ug\'thor, they are afraid to die.', 12, 1, 100, 1, 0, 0, 24641, 'Warden Nork Bloodfrenzy'),
(25379, 9, 0, '%s laughs.', 16, 1, 100, 11, 0, 0, 24646, 'Warden Nork Bloodfrenzy'),
(25379, 10, 0, 'That\'s right, Ug. Victory or death!', 12, 1, 100, 273, 0, 0, 24647, 'Warden Nork Bloodfrenzy'),
(25379, 11, 0, '[In Broken Common] Hear boy, cowards? Boy die! Boy die for freedom!', 12, 0, 100, 273, 0, 0, 24648, 'Warden Nork Bloodfrenzy'),
-- Ug''thor Bloodfrenzy
(25426, 0, 0, 'No, popo. They look kind of like the pigs. Are they pigs?', 12, 1, 100, 1, 0, 0, 24632, 'Ug''thor Bloodfrenzy'),
(25426, 1, 0, 'Are they cowardly pigs, popo?', 12, 1, 100, 1, 0, 0, 24635, 'Ug''thor Bloodfrenzy'),
(25426, 2, 0, 'But popo, what are they afraid of? Why are they here?', 12, 1, 100, 1, 0, 0, 24638, 'Ug''thor Bloodfrenzy'),
(25426, 3, 0, '%s scratches his head.', 16, 1, 100, 0, 0, 0, 24642, 'Ug''thor Bloodfrenzy'),
(25426, 4, 0, 'I... I don\'t understand, popo.', 12, 1, 100, 1, 0, 0, 24643, 'Ug''thor Bloodfrenzy'),
(25426, 5, 0, '%s puffs out his chest and stands on his tip-toes.', 16, 1, 100, 0, 0, 0, 24644, 'Ug''thor Bloodfrenzy'),
(25426, 6, 0, 'Lok\'tar ogar, popo!', 12, 1, 100, 1, 0, 0, 24645, 'Ug''thor Bloodfrenzy');
