-- Warmaul Chef Bufferlo
UPDATE `creature_template` SET `AIName`="SmartAI", `speed_walk`=1 WHERE `entry`=18440;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18440 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1844000,1844001,1844002) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18440,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Aggro - Say Line 0"),
(18440,0,1,0,1,0,100,0,10000,30000,80000,100000,0,87,1844000,1844001,1844002,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - Out of Combat - Run Random Script"),
(18440,0,2,0,0,0,100,0,7000,12000,7000,12000,0,11,32376,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - In Combat - Cast 'Tenderize'"),
(18440,0,3,0,0,0,100,0,4000,6000,14000,18000,0,11,32378,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - In Combat - Cast 'Filet'"),
(18440,0,4,0,4,0,100,0,0,0,0,0,0,11,31994,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Aggro - Cast 'Shoulder Charge'"),
(1844000,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 1"),
(1844000,9,1,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 2"),
(1844001,9,0,0,0,0,100,0,0,0,0,0,0,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Play Emote 36"),
(1844001,9,1,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 3"),
(1844002,9,0,0,0,0,100,0,0,0,0,0,0,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Play Emote 35"),
(1844002,9,1,0,0,0,100,0,2000,2000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 4"),
(1844002,9,2,0,0,0,100,0,5000,5000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 5"),
(1844002,9,3,0,0,0,100,0,4000,4000,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 6"),
(1844002,9,4,0,0,0,100,0,4000,4000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 7"),
(1844002,9,5,0,0,0,100,0,2000,2000,0,0,0,5,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Play Emote 35"),
(1844002,9,6,0,0,0,100,0,2000,2000,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 8"),
(1844002,9,7,0,0,0,100,0,8000,8000,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Say Line 9"),
(1844002,9,8,0,0,0,100,0,3000,3000,0,0,0,5,153,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Chef Bufferlo - On Script - Play Emote 153");

DELETE FROM `creature_text` WHERE `CreatureID`=18440;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18440,0,0,"IT DUZ WUT IT'S TOLD!",12,0,100,0,0,0,15419,0,"Warmaul Chef Bufferlo"),
(18440,0,1,"GET IN DA STEW!",12,0,100,0,0,0,15420,0,"Warmaul Chef Bufferlo"),
(18440,0,2,"YOU GUD IN DA BELLY!",12,0,100,0,0,0,15421,0,"Warmaul Chef Bufferlo"),
(18440,1,0,"Your daddy pay Warmaul and maybe we no eat you.",12,0,100,1,0,0,15426,0,"Warmaul Chef Bufferlo"),
(18440,2,0,"Ha-ha! Just kidding. We eat you for shure anyway!",12,0,100,11,0,0,15427,0,"Warmaul Chef Bufferlo"),
(18440,3,0,"BAM! Look at dat gristle sizzle!",12,0,100,1,0,0,15430,0,"Warmaul Chef Bufferlo"),
(18440,4,0,"And dis is da recipe for da bestest Broken chowder!",12,0,100,1,0,0,15431,0,"Warmaul Chef Bufferlo"),
(18440,5,0,"First you need da spices.",12,0,100,1,0,0,15432,0,"Warmaul Chef Bufferlo"),
(18440,6,0,"Da salt goes into da pot...",12,0,100,35,0,0,15433,0,"Warmaul Chef Bufferlo"),
(18440,7,0,"Den you put da pepper in da pot...",12,0,100,0,0,0,15434,0,"Warmaul Chef Bufferlo"),
(18440,8,0,"Now we gonna kick it up a notch wit da secret ingra... ingor... inrag... da secret sauce!",12,0,100,43,0,0,15435,0,"Warmaul Chef Bufferlo"),
(18440,9,0,"And last, we put in da Corki!",12,0,100,1,0,0,15436,0,"Warmaul Chef Bufferlo");
