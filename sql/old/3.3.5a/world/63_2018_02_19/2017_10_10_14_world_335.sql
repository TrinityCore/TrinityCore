-- Bristleback Battleboar
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid`=2954 AND `source_type`=0;

-- Bristleback Shaman
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=2953 AND `source_type`=0 AND `id`=0;

-- Elder Plainstrider
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2957;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2957 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2957,0,0,0,0,0,100,0,6000,10000,19000,24000,11,7272,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Plainstrider - In Combat - Cast Dust Cloud");

-- Prairie Wolf
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2958;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2958 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2958,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prairie Wolf - Out of Combat - Play Sound 1018"),
(2958,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prairie Wolf - Out of Combat - Play Emote 393"),
(2958,0,2,0,0,0,100,0,6000,10000,35000,45000,11,5781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prairie Wolf - In Combat - Cast Threatening Growl");

-- Prairie Stalker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2959;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2959 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2959,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prairie Stalker - Out of Combat - Play Sound 1018"),
(2959,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prairie Stalker - Out of Combat - Play Emote 393");

-- Prairie Wolf Alpha
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2960;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2960 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2960,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prairie Wolf Alpha - Out of Combat - Play Sound 1018"),
(2960,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prairie Wolf Alpha - Out of Combat - Play Emote 393"),
(2960,0,2,0,0,0,100,0,6000,10000,35000,45000,11,5781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prairie Wolf Alpha - In Combat - Cast Threatening Growl");

-- Wiry Swoop
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2969;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2969 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2969,0,0,0,0,0,100,0,5000,8000,15000,21000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wiry Swoop - In Combat - Cast Swoop");

-- Swoop
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2970;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2970 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2970,0,0,0,0,0,100,0,5000,8000,15000,21000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Swoop - In Combat - Cast Swoop");

-- Taloned Swoop
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2971;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2971 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2971,0,0,0,0,0,100,0,5000,8000,15000,21000,11,5708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taloned Swoop - In Combat - Cast Swoop");

-- Venture Co. Laborer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2976;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2976 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2976,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Laborer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Taskmaster
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2977;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2977 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2977,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Taskmaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Worker
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2978;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2978 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2978,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Worker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Venture Co. Supervisor
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2979;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2979 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2979,0,0,0,0,0,100,0,1000,3000,15000,30000,11,6673,2,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Supervisor - In Combat - Cast Battle Shout");

-- Kodo Matriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2974;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2974 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2974,0,0,0,9,0,100,0,0,8,9000,14000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kodo Matriarch - Within 0-8 Range - Cast Trample");

-- Kodo Bull
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2973;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2973 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2973,0,0,0,9,0,100,0,0,8,9000,14000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kodo Bull - Within 0-8 Range - Cast Trample");

-- Kodo Calf
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2972;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2972 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2972,0,0,0,4,0,100,0,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kodo Calf - On Aggro - Cast Rushing Charge");

-- Galak Outrunner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2968;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2968 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2968,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Galak Outrunner - In Combat - Cast Shoot"),
(2968,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Galak Outrunner - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bristleback Interloper
DELETE FROM `smart_scripts` WHERE `entryorguid`=3232 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3232,0,0,0,0,0,100,0,5000,8000,14000,20000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bristleback Interloper - In Combat - Cast Muscle Tear"),
(3232,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bristleback Interloper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- The Rake
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5807;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5807 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5807,0,0,0,0,0,100,0,5000,8000,8000,12000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Rake - In Combat - Cast Muscle Tear");

-- Enforcer Emilgund
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5787;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5787 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5787,0,0,1,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enforcer Emilgund - Between 0-30% Health - Cast Frenzy (No Repeat)"),
(5787,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enforcer Emilgund - Between 0-30% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5787;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5787,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,2384,0,"Enforcer Emilgund");

-- Bael'dun Digger
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2989;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2989 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2989,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bael'dun Digger - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bael'dun Appraiser
UPDATE `smart_scripts` SET `event_param4`=17000 WHERE `entryorguid`=2990 AND `source_type`=0 AND `id`=0;

-- Windfury Wind Witch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2963;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2963 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2963,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Windfury Wind Witch - In Combat - Cast Lightning Bolt"),
(2963,0,1,0,9,0,100,0,0,5,11000,16000,11,6982,0,0,0,0,0,2,0,0,0,0,0,0,0,"Windfury Wind Witch - Within 0-5 Range - Cast Gust of Wind");

-- Windfury Sorceress
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2964;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2964 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2964,0,0,0,0,0,100,0,0,0,3400,4800,11,13322,64,0,0,0,0,2,0,0,0,0,0,0,0,"Windfury Sorceress - In Combat - Cast Frostbolt");

-- Windfury Matriarch
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2965;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2965 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2965,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Windfury Matriarch - In Combat - Cast Lightning Bolt"),
(2965,0,1,0,2,0,100,0,0,50,18000,24000,11,332,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windfury Matriarch - Between 0-50% Health - Cast Healing Wave");

-- Sister Hatelash
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5785;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5785 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5785,0,0,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sister Hatelash - In Combat - Cast Lightning Bolt"),
(5785,0,1,0,0,0,100,0,4000,9000,30000,45000,11,6960,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sister Hatelash - In Combat - Cast Lightning Barrier");

-- Snagglespear
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5786;
DELETE FROM `smart_scripts` WHERE `entryorguid`=5786 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5786,0,0,0,9,0,100,0,0,20,11000,18000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snagglespear - Within 0-20 Range - Cast Net");

-- Arra'chea
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3058;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3058 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3058,0,0,0,0,0,100,0,7000,9000,11000,15000,11,6730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arra'chea - In Combat - Cast Head Butt");

-- Mazzranache
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3068;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3068 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3068,0,0,0,4,0,100,0,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mazzranache - On Aggro - Cast Rushing Charge"),
(3068,0,1,0,0,0,100,0,6000,8000,16000,20000,11,3583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mazzranache - In Combat - Cast Deadly Poison");

-- Palemane Tanner
UPDATE `smart_scripts` SET `event_param3`=2400, `event_param4`=3800 WHERE `entryorguid`=2949 AND `source_type`=0 AND `id`=1;

-- Palemane Poacher
UPDATE `smart_scripts` SET `event_param3`=2300, `event_param4`=3900 WHERE `entryorguid`=2951 AND `source_type`=0 AND `id`=1;
