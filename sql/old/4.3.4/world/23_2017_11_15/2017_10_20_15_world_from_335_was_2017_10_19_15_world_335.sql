/*
-- Alexi Barov & Weldon Barov
DELETE FROM `creature_text` WHERE `CreatureID` IN (11022, 11023);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(11022,0,0,"The deeds are mine, brother! Soon you shall be out of my way for good!",14,0,100,11,0,0,6554,0,"Alexi Barov"),
(11022,1,0,"HELP! ASSASSINS HAVE COME TO KILL ME!",14,0,100,0,0,0,7979,0,"Alexi Barov"),
(11023,0,0,"The fortune is mine, Alexi! Your end comes soon!",14,0,100,11,0,0,6555,0,"Weldon Barov"),
(11023,1,0,"HELP! ASSASSINS HAVE COME TO KILL ME!",14,0,100,0,0,0,7979,0,"Weldon Barov");

-- Alexi Barov
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11022;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11022 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11022,0,0,0,0,0,100,0,5000,9000,9000,13000,11,14873,0,0,0,0,0,5,0,0,0,0,0,0,0,"Alexi Barov - In Combat - Cast Sinister Strike"),
(11022,0,1,0,67,0,100,0,7000,12000,0,0,11,7159,2,0,0,0,0,2,0,0,0,0,0,0,0,"Alexi Barov - On Behind Target - Cast Backstab"),
(11022,0,2,0,9,0,100,0,0,5,13000,18000,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Alexi Barov - Within 0-5 Range - Cast Rupture"),
(11022,0,3,0,13,0,100,0,12000,16000,0,0,11,15614,0,0,0,0,0,7,0,0,0,0,0,0,0,"Alexi Barov - Target Casting - Cast Kick"),
(11022,0,4,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alexi Barov - On Aggro - Say Line 1"),
(11022,0,5,0,20,0,100,0,5341,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alexi Barov - On Quest 'Barov Family Fortune' Finished - Say Line 0");

-- Weldon Barov
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=11023;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11023 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(11023,0,0,0,0,0,100,0,5000,8000,6000,9000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weldon Barov - In Combat - Cast Strike"),
(11023,0,1,0,9,0,100,0,0,8,12000,18000,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Weldon Barov - Within 0-8 Range - Cast Demoralizing Shout"),
(11023,0,2,0,9,0,100,0,0,5,13000,16000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weldon Barov - Within 0-5 Range - Cast Hamstring"),
(11023,0,3,0,0,0,100,0,8000,13000,13000,16000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weldon Barov - In Combat - Cast Cleave"),
(11023,0,4,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Weldon Barov - On Aggro - Say Line 1"),
(11023,0,5,0,20,0,100,0,5343,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Weldon Barov - On Quest 'Barov Family Fortune' Finished - Say Line 0");
*/
