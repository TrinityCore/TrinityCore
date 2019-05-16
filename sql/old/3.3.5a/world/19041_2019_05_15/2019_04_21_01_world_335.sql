-- Elenna Edune
UPDATE `creature` SET `position_x`=2862.77, `position_y`=708.663, `position_z`=103.374, `spawndist`=0, `MovementType`=2 WHERE `guid`=33027;
UPDATE `creature` SET `position_x`=2863.40, `position_y`=707.171, `position_z`=103.124, `spawndist`=0, `MovementType`=0 WHERE `guid`=33070;

DELETE FROM `creature_addon` WHERE `guid`=33027;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(33027,330270,0,0,1,0,"");

DELETE FROM `creature_formations` WHERE `leaderGUID`=33027;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(33027,33027,0,0,515,0,0),
(33027,33070,3,270,515,0,0);

DELETE FROM `waypoint_data` WHERE `id`=330270;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(330270,1,2861.92,708.325,103.371,0,0,0,0,100,0),
(330270,2,2840.84,700.44,101.536,0,0,0,0,100,0),
(330270,3,2814.9,682.815,101.238,0,0,0,0,100,0),
(330270,4,2774.06,667.349,100.26,4.07927,23000,0,0,100,0),
(330270,5,2774.55,659.654,99.373,0,0,0,0,100,0),
(330270,6,2760.7,652.225,99.1858,0,0,0,0,100,0),
(330270,7,2734.3,647.405,97.8214,0,0,0,0,100,0),
(330270,8,2707.91,648.922,102.831,0,0,0,0,100,0),
(330270,9,2691.1,642.196,102.258,0,0,0,0,100,0),
(330270,10,2677.72,642.806,104.075,0,0,0,0,100,0),
(330270,11,2626.23,633.322,102.169,0,0,0,0,100,0),
(330270,12,2608.55,623.392,104.291,0,0,0,0,100,0),
(330270,13,2592.23,606.496,103.122,0,0,0,0,100,0),
(330270,14,2587.62,594.632,101.817,0,0,0,0,100,0),
(330270,15,2588.02,583.145,101.933,0,0,0,0,100,0),
(330270,16,2595.25,575.838,102.361,0,0,0,0,100,0),
(330270,17,2606.6,572.189,102.245,0,0,0,0,100,0),
(330270,18,2622.3,581.536,102.827,0,0,0,0,100,0),
(330270,19,2640.05,601.042,102.455,0,0,0,0,100,0),
(330270,20,2657.07,613.695,100.792,0,0,0,0,100,0),
(330270,21,2665.42,624.445,100.561,0,0,0,0,100,0),
(330270,22,2681.05,632.544,103.077,0,0,0,0,100,0),
(330270,23,2691.08,642.225,102.267,0,0,0,0,100,0),
(330270,24,2712.16,642.786,100.7,0,0,0,0,100,0),
(330270,25,2737.49,638.751,95.8643,0,0,0,0,100,0),
(330270,26,2760.24,637.029,96.1858,0,0,0,0,100,0),
(330270,27,2784.28,642.281,94.1803,0,0,0,0,100,0),
(330270,28,2813.79,658.468,96.4133,0,0,0,0,100,0),
(330270,29,2843.9,678.039,99.2061,0,0,0,0,100,0),
(330270,30,2865.19,686.739,99.5422,0,0,0,0,100,0),
(330270,31,2874.57,692.561,99.6937,0,0,0,0,100,0),
(330270,32,2884.33,703.512,101.247,0,0,0,0,100,0),
(330270,33,2886.17,711.556,102.242,0,0,0,0,100,0),
(330270,34,2881.1,716.877,102.735,0,0,0,0,100,0),
(330270,35,2871.84,715.082,103.666,0,0,0,0,100,0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=24738 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2473800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24738,0,0,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - On Respawn - Set Active On"),
(24738,0,1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Elenna Edune - In Combat - Cast 'Shoot'"),
(24738,0,2,0,34,0,100,0,2,2,0,0,80,2473800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elenna Edune - On Reached Point 3 - Run Script"),
(24738,0,3,0,34,0,100,0,2,3,0,0,45,1,1,0,0,0,0,19,24737,0,0,0,0,0,0,"Elenna Edune - On Reached Point 4 - Set Data to William Dunadaire"),
(2473800,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,24739,0,0,0,0,0,0,"Elenna Edune - On Script - Say Line 0 (Benjari Edune)"),
(2473800,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,24737,0,0,0,0,0,0,"Elenna Edune - On Script - Say Line 0 (William Dunadaire)"),
(2473800,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,19,24739,0,0,0,0,0,0,"Elenna Edune - On Script - Say Line 1 (Benjari Edune)");

-- William Dunadaire
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24737;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24737 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2473700,2473701,2473702) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24737,0,0,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Respawn - Set Active On"),
(24737,0,1,0,38,0,100,0,1,1,0,0,80,2473700,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Data Set - Run Script"),
(24737,0,2,0,40,0,100,0,3,24737,0,0,80,2473701,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Waypoint 3 Reached - Run Script"),
(24737,0,3,0,40,0,100,0,6,24737,0,0,80,2473702,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Waypoint 6 Reached - Run Script"),
(2473700,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.98872,"William Dunadaire - On Script - Set Orientation"),
(2473700,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,24738,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 0 (Elenna Edune)"),
(2473700,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 1"),
(2473700,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,24738,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 1 (Elenna Edune)"),
(2473700,9,4,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 2"),
(2473700,9,5,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 3"),
(2473700,9,6,0,0,0,100,0,2000,2000,0,0,53,0,24737,0,0,0,2,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Start Waypoint"),
(2473700,9,7,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,19,24738,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 2 (Elenna Edune)"),
(2473701,9,0,0,0,0,100,0,0,0,0,0,54,29000,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Pause Waypoint"),
(2473701,9,1,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 4"),
(2473701,9,2,0,0,0,100,0,3000,3000,0,0,28,32356,0,0,0,0,0,19,24735,0,0,0,0,0,0,"William Dunadaire - On Script - Remove Aura 'Cat Form' from Becanna Edune"),
(2473701,9,3,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.59826,"William Dunadaire - On Script - Set Orientation"),
(2473701,9,4,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,19,24735,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 0 (Becanna Edune)"),
(2473701,9,5,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 5"),
(2473701,9,6,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,19,24735,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 1 (Becanna Edune)"),
(2473701,9,7,0,0,0,100,0,4000,4000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 6"),
(2473701,9,8,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,19,24735,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 2 (Becanna Edune)"),
(2473701,9,9,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 7"),
(2473701,9,10,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,24735,0,0,0,0,0,0,"William Dunadaire - On Script - Set Data to Becanna Edune"),
(2473702,9,0,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.10669,"William Dunadaire - On Script - Set Orientation"),
(2473702,9,1,0,0,0,100,0,30000,30000,0,0,1,0,0,0,0,0,0,19,24736,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 0 (Sulan Dunadaire)"),
(2473702,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,19,24736,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 1 (Sulan Dunadaire)"),
(2473702,9,3,0,0,0,100,0,4000,4000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"William Dunadaire - On Script - Say Line 8");

DELETE FROM `waypoints` WHERE `entry`=24737;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(24737, 1, 2771.5, 668.147, 100.476),
(24737, 2, 2756.94, 676.171, 103.751),
(24737, 3, 2748.23, 683.799, 104.479),
(24737, 4, 2756.94, 676.171, 103.751),
(24737, 5, 2771.5, 668.147, 100.476),
(24737, 6, 2772.1, 664.314, 100.216);

-- Becanna Edune
UPDATE `creature` SET `position_x`=2748.53, `position_y`=689.135, `position_z`=104.479, `orientation`=4.47674, `modelid`=0 WHERE `guid`=32943;

UPDATE `creature_model_info` SET `Gender`=2 WHERE `DisplayID`=892;

DELETE FROM `smart_scripts` WHERE `entryorguid`=24735 AND `source_type`=0 AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2473500) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24735,0,1,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Respawn - Set Active On"),
(24735,0,2,0,11,0,100,0,0,0,0,0,11,32356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Respawn - Cast 'Cat Form'"),
(24735,0,3,0,38,0,100,0,1,1,0,0,80,2473500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Data Set - Run Script"),
(24735,0,4,0,40,0,100,0,4,24735,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Waypoint 4 Reached - Pause Waypoint"),
(24735,0,5,0,40,0,100,0,6,24735,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Waypoint 6 Reached - Pause Waypoint"),
(24735,0,6,0,40,0,100,0,6,24735,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Waypoint 6 Reached - Say Line 6"),
(24735,0,7,0,40,0,100,0,9,24735,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.47674,"Becanna Edune - On Waypoint 6 Reached - Set Orientation"),
(2473500,9,0,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,19,24734,0,0,0,0,0,0,"Becanna Edune - On Script - Set Data to Aleanna Edune"),
(2473500,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.01002,"Becanna Edune - On Script - Set Orientation"),
(2473500,9,2,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Script - Say Line 3"),
(2473500,9,3,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Script - Say Line 4"),
(2473500,9,4,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,24734,0,0,0,0,0,0,"Becanna Edune - On Script - Say Line 0 (Aleanna Edune)"),
(2473500,9,5,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Script - Say Line 5"),
(2473500,9,6,0,0,0,100,0,9000,9000,0,0,1,1,0,0,0,0,0,19,24734,0,0,0,0,0,0,"Becanna Edune - On Script - Say Line 1 (Aleanna Edune)"),
(2473500,9,7,0,0,0,100,0,7000,7000,0,0,11,32356,0,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Script - Cast 'Cat Form'"),
(2473500,9,8,0,0,0,100,0,0,0,0,0,53,1,24735,0,0,0,0,1,0,0,0,0,0,0,0,"Becanna Edune - On Script - Start Waypoint"),
(2473500,9,9,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,19,24734,0,0,0,0,0,0,"Becanna Edune - On Script - Set Data to Aleanna Edune");

DELETE FROM `waypoints` WHERE `entry`=24735;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(24735, 1, 2748.23, 683.799, 104.479),
(24735, 2, 2758.44, 675.416, 103.286),
(24735, 3, 2782.78, 673.343, 99.8184),
(24735, 4, 2858.61, 698.409, 101.932),
(24735, 5, 2778.97, 680.788, 101.444),
(24735, 6, 2768.67, 687.386, 103.869),
(24735, 7, 2758.44, 675.416, 103.286),
(24735, 8, 2758.44, 675.416, 103.286),
(24735, 9, 2748.53, 689.135, 104.479);

-- Aleanna Edune
UPDATE `creature` SET `position_x`=2744.01, `position_y`=683.613, `position_z`=104.479, `orientation`=3.95897 WHERE `guid`=32936;

DELETE FROM `smart_scripts` WHERE `entryorguid`=24734 AND `source_type`=0 AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2473400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24734,0,1,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.825229,"Aleanna Edune - On Data Set - Set Orientation"),
(24734,0,2,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.95897,"Aleanna Edune - On Data Set - Set Orientation");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (24739,24737,24738,24735,24736,24734);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24739,0,0,"... and have I told you about the time when I ventured deep into the heart of Blackrock Mountain?",12,7,100,6,0,0,23739,0,"Benjari Edune"),
(24739,0,1,"..with a mighty blow, I slew a Murloc, freeing the orb from his cold, slimy hands!",12,7,100,1,0,0,23744,0,"Benjari Edune"),
(24739,0,2,"... not to forget that time I ventured deep within the forests of Zul'Aman.",12,7,100,1,0,0,23745,0,"Benjari Edune"),
(24739,0,3,"... the burning sands of Silithus scorched my face as we battled wave after wave of Silithid.",12,7,100,1,0,0,23746,0,"Benjari Edune"),
(24739,0,4,"... the city was burned, a scorched ruin of what it once was. The armies of the undead rose where the people had once lived.",12,7,100,1,0,0,23747,0,"Benjari Edune"),
(24739,0,5,"... did I tell you about the time that I explored the far reaches of Dire Maul?",12,7,100,6,0,0,23748,0,"Benjari Edune"),
(24739,1,0,"That was when I slew the Orc with a great slash and took away these spaulders.",12,7,100,1,0,0,23740,0,"Benjari Edune"),
(24739,1,1,"I found a mighty axe there, freshly forged upon the fire.",12,7,100,1,0,0,23741,0,"Benjari Edune"),
(24739,1,2,"There, I crafted this breastplate with my own hands, toiling for hours upon the forge.",12,7,100,1,0,0,23742,0,"Benjari Edune"),
(24739,1,3,"There, deep within the pockets of a Troll was the beautiful gem, which I sold for a handsome price!",12,7,100,1,0,0,23743,0,"Benjari Edune"),
(24737,0,0,"%s nods silently...",16,0,100,0,0,0,23750,0,"William Dunadaire"),
(24737,0,1,"%s listens impatiently...",16,0,100,0,0,0,23751,0,"William Dunadaire"),
(24737,0,2,"%s sighs...",16,0,100,0,0,0,23749,0,"William Dunadaire"),
(24737,1,0,"What? Why do you want me to do it?",12,7,100,6,0,0,23719,0,"William Dunadaire"),
(24737,2,0,"Alright, I'll tell her.",12,7,100,1,0,0,23720,0,"William Dunadaire"),
(24737,3,0,"%s takes a deep breath.",16,0,100,0,0,0,23721,0,"William Dunadaire"),
(24737,4,0,"Odd, she's usually here...",12,7,100,0,0,0,23722,0,"William Dunadaire"),
(24737,5,0,"Hi, uh, Becanna, I mean... uh, Elenna found some herbs! Can you go pick them up?",12,7,100,24,0,0,23723,0,"William Dunadaire"),
(24737,6,0,"Thanks! If you uh, need any help, just come pick me up... I mean, come get me and I'll help!",12,7,100,24,0,0,23725,0,"William Dunadaire"),
(24737,7,0,"%s turns slightly red and walks away.",16,0,100,0,0,0,23726,0,"William Dunadaire"),
(24737,8,0,"Thanks, but I'm not very hungry right now.",12,7,100,274,0,0,23729,0,"William Dunadaire"),
(24738,0,0,"William, I saw a fresh growth of herbs out on the ridge. Go ask Becanna to pick them up.",12,7,100,1,0,0,23712,0,"Elenna Edune"),
(24738,1,0,"Come on, just do it.",12,7,100,5,0,0,23718,0,"Elenna Edune"),
(24738,2,0,"Come on, Goodie, lets go scout the area.",12,2,100,0,0,0,23709,0,"Elenna Edune"),
(24736,0,0,"Oh, these apples are utterly delicious!",12,7,100,7,0,0,23727,0,"Sulan Dunadaire"),
(24736,1,0,"My brother simply must try these.",12,7,100,0,0,0,23728,0,"Sulan Dunadaire"),
(24734,0,0,"Hmm... well, just be careful, he might be sweet on you. I don't trust that sister of his either...",12,2,100,0,0,0,23737,0,"Aleanna Edune"),
(24734,1,0,"Alright, Becca, just leave them in the garden next to the bush. Watch out for wolves!",12,2,100,1,0,0,23738,0,"Aleanna Edune"),
(24735,0,0,"Hi, William, what's up?",12,7,100,3,0,0,23730,0,"Becanna Edune"),
(24735,1,0,"Ah, thank you! I'll be sure to go get them soon.",12,7,100,1,0,0,23731,0,"Becanna Edune"),
(24735,2,0,"Nah, I can handle it. Thanks.",12,7,100,274,0,0,23732,0,"Becanna Edune"),
(24735,3,0,"That William is so funny. His face always turns bright red.",12,2,100,11,0,0,23734,0,"Becanna Edune"),
(24735,4,0,"I'd better ask before I go herbing this time. I don't want to get attacked by another wolf.",12,2,100,0,0,0,23733,0,"Becanna Edune"),
(24735,5,0,"I am sure a noble soldier of the Alliance has better things on his mind. Oh! Elenna found some herbs so I'm going to go pick them up.",12,2,100,1,0,0,23735,0,"Becanna Edune"),
(24735,6,0,"%s replants the herbs nearby.",16,0,100,0,0,0,23736,0,"Becanna Edune");
