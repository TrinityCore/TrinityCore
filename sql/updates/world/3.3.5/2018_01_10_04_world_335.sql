-- Zukk'ash Stinger
DELETE FROM `smart_scripts` WHERE `entryorguid`=5244 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5244,0,1,0,2,0,100,1,0,15,0,0,11,17170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zukk'ash Stinger - Between 0-15% Health - Cast Fatal Sting (No Repeat)"),
(5244,0,2,0,2,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zukk'ash Stinger - Between 0-15% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=5244;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(5244,0,0,"%s prepares to sting its victim as a last desperate move!",16,0,100,0,0,0,3713,0,"Zukk'ash Stinger");

-- Krellack
DELETE FROM `smart_scripts` WHERE `entryorguid`=14476 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14476,0,0,0,2,0,100,0,0,15,8000,12000,11,17170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krellack - Between 0-15% Health - Cast Fatal Sting");

-- Silvermane Howler
DELETE FROM `smart_scripts` WHERE `entryorguid`=2925 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2925,0,2,0,2,0,100,1,0,50,0,0,39,30,1,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermane Howler - Between 0-50% Health - Call For Help (No Repeat)");

-- Vicious Owlbeast
DELETE FROM `smart_scripts` WHERE `entryorguid`=2927 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2927,0,0,0,12,0,100,0,0,20,14000,18000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vicious Owlbeast - Target Between 0-20% Health - Cast Fatal Bite");

-- Savage Owlbeast
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2929;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2929 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2929,0,0,0,12,0,100,0,0,20,14000,18000,11,7938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Owlbeast - Target Between 0-20% Health - Cast Fatal Bite");

-- Jalinde Summerdrake
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8214;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8214 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8214,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Jalinde Summerdrake - In Combat CMC - Cast Shoot"),
(8214,0,1,0,9,0,100,0,5,30,9000,13000,11,15495,0,0,0,0,0,5,0,0,0,0,0,0,0,"Jalinde Summerdrake - Within 5-30 Range - Cast Explosive Shot"),
(8214,0,2,0,0,0,100,0,3000,5000,15000,21000,11,8806,32,0,0,0,0,5,0,0,0,0,0,0,0,"Jalinde Summerdrake - In Combat - Cast Poisoned Shot");

-- Highvale Ranger
DELETE FROM `smart_scripts` WHERE `entryorguid`=2694 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2694,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highvale Ranger - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Witherbark Zealot
DELETE FROM `smart_scripts` WHERE `entryorguid`=2650 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2650,0,0,0,2,0,100,1,0,50,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Zealot - Between 0-50% Health - Cast Enrage (No Repeat)"),
(2650,0,1,0,2,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Zealot - Between 0-50% Health - Say Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=2650;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2650,0,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Witherbark Zealot");

-- Razorbeak Skylord
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2659;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2659 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2659,0,0,0,0,0,100,0,8000,12000,12000,16000,11,11019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razorbeak Skylord - In Combat - Cast Wing Flap"),
(2659,0,1,0,9,0,100,0,0,5,15000,19000,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razorbeak Skylord - Within 0-5 Range - Cast Rend Flesh");

-- Grimungous
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8215;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8215 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8215,0,0,0,0,0,100,0,6000,9000,9000,13000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimungous - In Combat - Cast Trample"),
(8215,0,1,0,9,0,100,0,0,5,14000,20000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimungous - Within 0-5 Range - Cast War Stomp");

-- Shadra
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2707;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2707 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2707,0,0,0,25,0,100,0,0,0,0,0,11,13299,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadra - On Reset - Cast Poison Proc"),
(2707,0,1,0,25,0,100,0,0,0,0,0,11,8601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadra - On Reset - Cast Slowing Poison"),
(2707,0,2,0,9,0,100,0,0,10,9000,10000,11,28991,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadra - Within 0-10 Range - Cast Web");

-- Fix bytes2 for some creatures
UPDATE `creature_template_addon` SET `bytes2`=2 WHERE `entry` IN (2693,2691);

-- Fix wrong spawn for Elder Gray Bear
UPDATE `creature` SET `position_x`=-598.9, `position_y`=-1604.41, `position_z`=61.6481 WHERE `guid`=14873 AND `id`=2356;

-- Add random movement for some creatures
UPDATE `creature` SET `spawndist`=5, `MovementType`=1 WHERE `guid` IN (69119,69117);

-- Pathing for Witherheart the Stalker
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=85478;
DELETE FROM `creature_addon` WHERE `guid`=85478;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(85478,854780,0,0,1,0,"");

DELETE FROM `waypoint_data` WHERE `id`=854780;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(854780,1,-336.731,-2833.29,77.0363,0,0,0,0,100,0),
(854780,2,-334.463,-2814.89,80.383,0,0,0,0,100,0),
(854780,3,-348.051,-2805.34,80.0625,0,0,0,0,100,0),
(854780,4,-364.007,-2805.31,76.9893,0,0,0,0,100,0),
(854780,5,-376.958,-2796.97,77.4724,0,0,0,0,100,0),
(854780,6,-394.72,-2805.83,77.8546,0,0,0,0,100,0),
(854780,7,-390.019,-2822.94,74.1284,0,0,0,0,100,0),
(854780,8,-389.906,-2837.06,74.2824,0,0,0,0,100,0),
(854780,9,-402.354,-2843.73,76.9459,0,0,0,0,100,0),
(854780,10,-416.467,-2844.41,79.3868,0,0,0,0,100,0),
(854780,11,-421.565,-2852.64,79.3284,0,0,0,0,100,0),
(854780,12,-421.623,-2874.12,83.6468,0,0,0,0,100,0),
(854780,13,-428.279,-2885.91,84.8522,0,0,0,0,100,0),
(854780,14,-417.871,-2899.71,83.2011,0,0,0,0,100,0),
(854780,15,-421.714,-2912.49,82.035,0,0,0,0,100,0),
(854780,16,-409.008,-2915.46,80.4308,0,0,0,0,100,0),
(854780,17,-398.058,-2912.56,79.2019,0,0,0,0,100,0),
(854780,18,-388.929,-2926.26,77.9069,0,0,0,0,100,0),
(854780,19,-376.519,-2927.69,75.9121,0,0,0,0,100,0),
(854780,20,-372.09,-2931.3,75.3061,0,0,0,0,100,0),
(854780,21,-354.46,-2929.29,75.2535,0,0,0,0,100,0),
(854780,22,-339.972,-2930.95,76.0707,0,0,0,0,100,0),
(854780,23,-326.085,-2943.36,78.7858,0,0,0,0,100,0),
(854780,24,-313.89,-2944.59,80.8206,0,0,0,0,100,0),
(854780,25,-305.916,-2935.44,82.1426,0,0,0,0,100,0),
(854780,26,-307.534,-2917.76,80.3467,0,0,0,0,100,0),
(854780,27,-298.165,-2903.94,81.5407,0,0,0,0,100,0),
(854780,28,-301.296,-2890.28,81.1735,0,0,0,0,100,0),
(854780,29,-310.921,-2881.96,79.6081,0,0,0,0,100,0),
(854780,30,-313.692,-2872.43,80.082,0,0,0,0,100,0),
(854780,31,-312.576,-2859.04,80.4389,0,0,0,0,100,0),
(854780,32,-320.584,-2852.24,78.3489,0,0,0,0,100,0),
(854780,33,-336.88,-2851.17,77.2118,0,0,0,0,100,0);
