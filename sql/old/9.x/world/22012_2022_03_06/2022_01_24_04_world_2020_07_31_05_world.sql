-- Tel'athion the Impure
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17359;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17359 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1735900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(17359,0,0,0,0,0,100,0,0,0,3000,5000,0,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tel'athion the Impure - In Combat - Cast 'Frostbolt'"),
(17359,0,1,0,0,0,100,0,9000,11000,13000,15000,0,11,15735,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tel'athion the Impure - In Combat - Cast 'Arcane Missiles'"),
(17359,0,2,0,0,0,100,0,4000,6000,12000,16000,0,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tel'athion the Impure - In Combat - Cast 'Fire Blast'"),
(17359,0,3,0,9,0,100,0,0,8,11000,13000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tel'athion the Impure - Within 0-8 Range - Cast 'Frost Nova'"),
(17359,0,4,5,11,0,100,0,0,0,0,0,0,80,1735900,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tel'athion the Impure - On Spawn - Run Script"),
(17359,0,5,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Tel'athion the Impure - On Spawn - Start Attacking"),
(1735900,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tel'athion the Impure - On Script - Say Line 0"),
(1735900,9,1,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,19,6748,0,0,0,0,0,0,"Tel'athion the Impure - On Script - Say Line 0 (Water Spirit)"),
(1735900,9,2,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tel'athion the Impure - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` IN (17359,6748);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17359,0,0,"What have you done to my life's work?!  DIE!!!",12,0,100,0,0,0,13793,0,"Tel'athion the Impure"),
(17359,1,0,"It is YOU who are wrong!  I will deal with you two after I have slain this meddlesome shaman!",12,0,100,0,0,0,14248,0,"Tel'athion the Impure"),
(6748,0,0,"Wrong!  It is YOU that will die, Tel'athion the Impure!",12,0,100,0,0,0,14247,0,"Water Spirit");

-- Water Spirit
UPDATE `creature_template` SET `AIName`="SmartAI", `faction`=1685 WHERE `entry`=6748;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6748 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6748,0,0,0,1,0,100,1,4000,4000,0,0,0,49,0,0,0,0,0,0,19,17359,0,0,0,0,0,0,"Water Spirit - Out of Combat - Start Attacking");
