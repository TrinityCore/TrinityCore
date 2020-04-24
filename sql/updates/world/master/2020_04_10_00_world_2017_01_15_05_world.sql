-- Levixus SAI
SET @ENTRY := 19847;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24313,0,0,0,0,0,1,0,0,0,0,0,0,0,"Levixus - On Respawn - Cast 'Shade' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,13000,17000,11,11443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Levixus - In Combat - Cast 'Cripple'"),
(@ENTRY,0,2,0,0,0,100,0,9000,14000,13000,17000,11,7645,1,0,0,0,0,6,0,0,0,0,0,0,0,"Levixus - In Combat - Cast 'Dominate Mind'"),
(@ENTRY,0,3,0,0,0,100,0,10000,13000,18000,22000,11,38939,1,0,0,0,0,2,0,0,0,0,0,0,0,"Levixus - In Combat - Cast 'Inferno'"),
(@ENTRY,0,4,0,1,0,100,0,0,0,20000,20000,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Levixus - Out of Combat - Run Script");

-- Actionlist SAI
SET @ENTRY := 1984700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,1000,1000,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,"Levixus - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,1000,1000,0,0,1,1,8000,0,0,0,0,1,0,0,0,0,0,0,0,"Levixus - On Script - Say Line 1"),
(@ENTRY,9,2,0,0,0,100,0,8000,8000,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,"Levixus - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,1000,1000,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Levixus - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=19847;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
(19847, 0, 0, '%s reads from the book of the dead.', 16, 0, 100, 0, 0, 0, 17446, 'Levixus'),
-- 
(19847, 1, 0, 'Shane Dabiri, Lee, Alex T., Rob F., J. A. B.,  A. Mayberry!', 12, 8, 100, 15, 0, 0, 17454, 'Levixus'),
(19847, 1, 1, 'Jeffrey Kaplan! Tom Chilton! Rob Pardo!', 12, 8, 100, 15, 0, 0, 17447, 'Levixus'),
(19847, 1, 2, 'Justin Thavirat! Roman Kenney! Our entire awesome art and animation team!', 12, 8, 100, 15, 0, 0, 17448, 'Levixus'),
(19847, 1, 3, 'Kevin Jordan and Jonathan LeCraft!', 12, 8, 100, 15, 0, 0, 17453, 'Levixus'),
(19847, 1, 4, 'CHRIS METZEN!', 12, 8, 100, 15, 0, 0, 17449, 'Levixus'),
(19847, 1, 5, 'Pat Nagle! World design team! Cory Stockton, Paul C., Jim Chadwick, Staats, Ed Hanes, Morris, Gotcher, Jesse!, Sarah B., Victor C., Dave A.! All of our amazing exterior artists!', 12, 8, 100, 15, 0, 0, 17450, 'Levixus'),
(19847, 1, 6, 'Scott Mercer! Geoff, Wyatt, Joe, Travis, Kris, Steven! Brazie!', 12, 8, 100, 15, 0, 0, 17451, 'Levixus'),
(19847, 1, 7, 'Luis, Brianna and Eric! Blizzard QA team! Of course our fans!', 12, 8, 100, 15, 0, 0, 17452, 'Levixus');
