/*
-- Scorpid Worker
DELETE FROM `smart_scripts` WHERE `entryorguid`=3124 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3124,0,0,0,0,0,100,0,4000,8000,6000,12000,11,6751,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpid Worker - In Combat - Cast Weak Poison");

-- Sarkoth
DELETE FROM `smart_scripts` WHERE `entryorguid`=3281 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3281,0,0,0,0,0,100,0,5000,8000,5000,8000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sarkoth - In Combat - Cast Poison");

-- Yarrog Baneshadow
DELETE FROM `smart_scripts` WHERE `entryorguid`=3183 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3183,0,0,0,9,0,100,0,0,30,15000,19000,11,172,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - Within 0-30 Range - Cast Corruption"),
(3183,0,1,0,0,0,100,0,6000,8000,18000,22000,11,348,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - In Combat - Cast Immolate");

-- Clattering Scorpid
DELETE FROM `smart_scripts` WHERE `entryorguid`=3125 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3125,0,0,0,0,0,100,0,5000,8000,6000,12000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Scorpid - In Combat - Cast Poison");

-- Venomtail Scorpid
DELETE FROM `smart_scripts` WHERE `entryorguid`=3127 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3127,0,0,0,0,0,100,0,5000,8000,6000,12000,11,5416,32,0,0,0,0,2,0,0,0,0,0,0,0,"Venomtail Scorpid - In Combat - Cast Venom Sting");

-- Kolkar Drudge
DELETE FROM `smart_scripts` WHERE `entryorguid`=3119 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3119,0,0,0,0,0,100,0,6000,11000,15000,22000,11,7272,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Drudge - In Combat - Cast Dust Cloud");

-- Warlord Kolkanis
DELETE FROM `smart_scripts` WHERE `entryorguid`=5808 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5808,0,0,0,13,0,100,0,15000,25000,0,0,11,12555,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warlord Kolkanis - Target Casting - Cast Pummel"),
(5808,0,1,0,9,0,100,0,0,8,16000,23000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Kolkanis - Within 0-8 Range - Cast Thunderclap"),
(5808,0,2,0,0,0,100,0,8000,12000,10000,14000,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Kolkanis - In Combat - Cast Pummel");

-- Encrusted Surf Crawler
DELETE FROM `smart_scripts` WHERE `entryorguid`=3108 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3108,0,0,0,0,0,100,0,9000,16000,30000,40000,11,5426,0,0,0,0,0,1,0,0,0,0,0,0,0,"Encrusted Surf Crawler - In Combat - Cast Quick Sidestep");

-- Makrura Snapclaw
DELETE FROM `smart_scripts` WHERE `entryorguid`=3105 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3105,0,0,0,0,0,100,0,6000,9000,15000,21000,11,5424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Makrura Snapclaw - In Combat - Cast Claw Grasp");

-- Makrura Elder
DELETE FROM `smart_scripts` WHERE `entryorguid`=3141 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3141,0,0,0,0,0,100,0,6000,9000,15000,21000,11,5424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Makrura Elder - In Combat - Cast Claw Grasp");

-- Voodoo Troll
DELETE FROM `smart_scripts` WHERE `entryorguid`=3206 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3206,0,0,0,1,0,100,0,500,1000,600000,600000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,"Voodoo Troll - Out of Combat - Cast Lightning Shield"),
(3206,0,1,0,16,0,100,0,324,1,15000,30000,11,324,0,0,0,0,0,1,0,0,0,0,0,0,0,"Voodoo Troll - On Friendly Unit Missing Buff Lightning Shield - Cast Lightning Shield"),
(3206,0,2,0,2,0,100,0,0,50,16000,21000,11,332,0,0,0,0,0,1,0,0,0,0,0,0,0,"Voodoo Troll - Between 0-50% Health - Cast Healing Wave");

-- Zalazane
DELETE FROM `smart_scripts` WHERE `entryorguid`=3205 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3205,0,0,0,2,0,100,0,0,50,16000,21000,11,332,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zalazane - Between 0-50% Health - Cast Healing Wave"),
(3205,0,1,0,0,0,100,0,6000,11000,12000,21000,11,7289,32,0,0,0,0,2,0,0,0,0,0,0,0,"Zalazane - In Combat - Cast Shrink");

-- Lieutenant Benedict
DELETE FROM `smart_scripts` WHERE `entryorguid`=3192 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3192,0,1,0,13,0,100,0,20000,30000,0,0,11,72,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Benedict - Target Casting - Cast Shield Bash"),
(3192,0,2,0,0,0,100,0,10000,13000,14000,20000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Benedict - In Combat - Cast Shield Bash"),
(3192,0,3,0,0,0,100,0,7000,12000,15000,21000,11,3248,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Benedict - In Combat - Cast Improved Blocking");

-- Kul Tiras Marine
DELETE FROM `smart_scripts` WHERE `entryorguid`=3129 AND `source_type`=0 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3129,0,3,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kul Tiras Marine - Just Summoned - Say Line 0"),
(3129,0,4,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,20,0,0,0,0,0,0,"Kul Tiras Marine - Just Summoned - Start Attack");

DELETE FROM `creature_text` WHERE `CreatureID`=3129;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3129,0,0,"Step away from the Lieutenant's belongings!",12,0,100,0,0,0,980,0,"Kul Tiras Marine");

-- Razormane Quilboar
DELETE FROM `smart_scripts` WHERE `entryorguid`=3111 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3111,0,1,0,0,0,100,0,0,0,45000,50000,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Quilboar - In Combat - Cast Razor Mane");

-- Razormane Dustrunner
DELETE FROM `smart_scripts` WHERE `entryorguid`=3113 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3113,0,0,0,0,0,100,0,4000,9000,30000,35000,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razormane Dustrunner - In Combat - Cast Faerie Fire"),
(3113,0,1,0,14,0,100,0,100,40,14000,21000,11,774,0,0,0,0,0,7,0,0,0,0,0,0,0,"Razormane Dustrunner - Friendly At 100 Health - Cast Rejuvenation");

-- Razormane Battleguard
DELETE FROM `smart_scripts` WHERE `entryorguid`=3114 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3114,0,0,0,0,0,100,0,3000,8000,11000,19000,11,3248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razormane Battleguard - In Combat - Cast Improved Blocking");

-- Captain Flat Tusk
DELETE FROM `smart_scripts` WHERE `entryorguid`=5824 AND `source_type`=0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5824,0,0,0,25,0,100,0,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Flat Tusk - On Reset - Cast Battle Stance"),
(5824,0,1,0,0,0,100,0,6000,9000,7000,12000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Flat Tusk - In Combat - Cast Heroic Strike");

-- Dreadmaw Crocolisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=3110 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3110,0,0,0,0,0,100,0,5000,9000,12000,16000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaw Crocolisk - In Combat - Cast Muscle Tear");

-- Corrupted Dreadmaw Crocolisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=3231 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3231,0,0,0,0,0,100,0,5000,8000,6000,12000,11,7901,32,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Dreadmaw Crocolisk - In Combat - Cast Decayed Agility");

-- Burning Blade Neophyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=3196 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3196,0,0,0,0,0,100,0,3000,5000,18000,24000,11,348,0,0,0,0,0,2,0,0,0,0,0,0,0,"Burning Blade Neophyte - In Combat - Cast Immolate");

-- Burning Blade Apprentice
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3198 AND `source_type`=0 AND `id`=1;

-- Fizzle Darkstorm
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3203 AND `source_type`=0 AND `id`=1;

-- Thunder Lizard
DELETE FROM `smart_scripts` WHERE `entryorguid`=3130 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3130,0,0,0,0,0,100,0,4000,9000,6000,11000,11,5401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunder Lizard - In Combat - Cast Lizard Bolt");

-- Lightning Hide
DELETE FROM `smart_scripts` WHERE `entryorguid`=3131 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3131,0,0,0,0,0,100,0,4000,9000,6000,11000,11,5401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lightning Hide - In Combat - Cast Lizard Bolt");

-- Dustwind Pillager
DELETE FROM `smart_scripts` WHERE `entryorguid`=3116 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3116,0,0,0,0,0,100,0,5000,11000,18000,24000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustwind Pillager - In Combat - Cast Rend Flesh");

-- Dustwind Storm Witch
UPDATE `smart_scripts` SET `event_param3`=3400, `event_param4`=4800 WHERE `entryorguid`=3118 AND `source_type`=0 AND `id`=0;

-- Random movement for some creatures
UPDATE `creature` SET `MovementType`=1, `spawndist`=3 WHERE `guid` IN (12188, 12183, 12186, 12951, 12185, 12195, 12190, 12184, 12956, 12202, 12204, 6435, 6436, 7333, 7342, 6420, 7335, 7337, 7883, 7899, 6424, 7897, 8428, 8429, 6426, 7334, 7880, 7900, 7338, 7339, 6421, 6418, 7885, 6423, 6422, 7901, 7336, 7898, 6425, 7340, 7884, 6417, 7882, 6419);

-- Correct spawn position for one creature
UPDATE `creature` SET `position_x`=1421.6, `position_y`=-4770.55, `position_z`=4.49296 WHERE `guid`=7336;
*/
