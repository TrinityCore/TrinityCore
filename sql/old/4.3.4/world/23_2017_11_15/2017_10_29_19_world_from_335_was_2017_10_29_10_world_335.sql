/*
-- 
SET @GUID     := 81116; -- Need 6
SET @EVENT_ID := 74;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4 WHERE `entry` IN (35587, 35589, 35604);
DELETE FROM `creature` WHERE `id` IN (35587, 35589, 35604);
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID  , 35589, 571, 0, 0, 1, 1, 0, 0, 5667.981, 397.8138,  773.5132, 1.648981, 3600, 0, 0, 0, 0, 0, 0, 0, 0, "", 0),
(@GUID+1, 35587, 571, 0, 0, 1, 1, 0, 0, 5652.083, 383.7329, 773.6105, 1.648981, 3600, 0, 0, 0, 0, 0, 0, 0, 0, "", 0),
(@GUID+2, 35587, 571, 0, 0, 1, 1, 0, 0, 5657.443, 373.4184, 773.7465, 1.648981, 3600, 0, 0, 0, 0, 0, 0, 0, 0, "", 0),
(@GUID+3, 35604, 571, 0, 0, 1, 1, 0, 0, 5890.576, 311.1573, 819.8393, 1.648981, 3600, 0, 0, 0, 0, 0, 0, 0, 0, "", 0),
(@GUID+4, 35587, 571, 0, 0, 1, 1, 0, 0, 5885.933, 294.0366, 819.1774, 1.648981, 3600, 0, 0, 0, 0, 0, 0, 0, 0, "", 0),
(@GUID+5, 35587, 571, 0, 0, 1, 1, 0, 0, 5897.746, 303.434, 819.722, 1.648981, 3600, 0, 0, 0, 0, 0, 0, 0, 0, "", 0);

DELETE FROM `game_event` WHERE `eventEntry` IN (@EVENT_ID, @EVENT_ID+1);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `description`) VALUES
(@EVENT_ID, '2011-03-22 00:00:00', '2020-03-22 00:00:00', 60, 5, 'Dalaran: Argent Tournament heralds Horde'),
(@EVENT_ID+1, '2011-03-22 01:00:00', '2020-03-22 00:00:00', 60, 5, 'Dalaran: Argent Tournament heralds Alliance');

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2 AND `eventEntry`=@EVENT_ID;
INSERT INTO `game_event_creature` SELECT @EVENT_ID, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+2;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+3 AND @CGUID+5 AND `eventEntry`=@EVENT_ID+1;
INSERT INTO `game_event_creature` SELECT @EVENT_ID+1, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+3 AND @CGUID+5;

DELETE FROM `waypoints` WHERE `entry` IN (35589, 355870, 355871, 35604, 355872, 355873);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(35589, 1, 5668.624, 398.5799, 773.5132, "Jaeren Sunsworn"),
(35589, 2, 5725.442, 462.7153, 760.0244, "Jaeren Sunsworn"),
(35589, 3, 5800.564, 554.6614, 684.1921, "Jaeren Sunsworn"),
(35589, 4, 5833.159, 581.8802, 660.4152, "Jaeren Sunsworn"),
(35589, 5, 5873.917, 632.1146, 656.0275, "Jaeren Sunsworn"),
(35589, 6, 5896.446, 645.3889, 650.6648, "Jaeren Sunsworn"),
(35589, 7, 5910.374, 640.4618, 651.1382, "Jaeren Sunsworn"),
(35589, 8, 5927.374, 649.6198, 652.4438, "Jaeren Sunsworn"),
(35589, 9, 6014.182, 686.1268, 688.915, "Jaeren Sunsworn"),
(35589, 10, 6125.206, 740.4827, 776.0795, "Jaeren Sunsworn"),
(355870, 1, 5652.657, 384.5521, 773.6105, "Argent Peacekeeper"),
(355870, 2, 5717.878, 458.8056, 759.9131, "Argent Peacekeeper"),
(355870, 3, 5793.838, 550.7361, 684.3297, "Argent Peacekeeper"),
(355870, 4, 5826.26, 579.3629, 660.3875, "Argent Peacekeeper"),
(355870, 5, 5867.21, 630.5712, 656.2776, "Argent Peacekeeper"),
(355870, 6, 5898.586, 653.1563, 650.4151, "Argent Peacekeeper"),
(355870, 7, 5904.815, 648.9323, 650.7219, "Argent Peacekeeper"),
(355870, 8, 5921.449, 650.5695, 651.4497, "Argent Peacekeeper"),
(355870, 9, 6010.338, 686.4653, 687.6164, "Argent Peacekeeper"),
(355870, 10, 6121.343, 741.9896, 774.5883, "Argent Peacekeeper"),
(355871, 1, 5724.933, 452.9427, 759.5792, "Argent Peacekeeper"),
(355871, 2, 5797.671, 546.9618, 684.3028, "Argent Peacekeeper"),
(355871, 3, 5832.412, 574.3489, 660.6373, "Argent Peacekeeper"),
(355871, 4, 5872.779, 625.3055, 656.5553, "Argent Peacekeeper"),
(355871, 5, 5891.741, 645.5243, 651.7482, "Argent Peacekeeper"),
(355871, 6, 5900.167, 641.132, 651.4435, "Argent Peacekeeper"),
(355871, 7, 5925.063, 644.234, 652.3946, "Argent Peacekeeper"),
(355871, 8, 6012.224, 683.0504, 687.5056, "Argent Peacekeeper"),
(355871, 9, 6122.473, 737.8837, 775.0331, "Argent Peacekeeper"),
(35604, 1, 5882.346, 359.5052, 805.5128, "Arelas Brightstar"),
(35604, 2, 5870.818, 419.1528, 757.9805, "Arelas Brightstar"),
(35604, 3, 5861.615, 536.6198, 711.2313, "Arelas Brightstar"),
(35604, 4, 5819.368, 565.809, 686.2836, "Arelas Brightstar"),
(35604, 5, 5781.409, 579.5052, 660.2855, "Arelas Brightstar"),
(35604, 6, 5746.75, 605.8246, 659.4515, "Arelas Brightstar"),
(35604, 7, 5714.218, 632.6528, 653.4815, "Arelas Brightstar"),
(35604, 8, 5698.607, 642.5156, 653.6841, "Arelas Brightstar"),
(35604, 9, 5671.431, 657.9653, 673.2984, "Arelas Brightstar"),
(35604, 10, 5635.497, 664.8281, 695.1312, "Arelas Brightstar"),
(35604, 11, 5547.962, 679.8489, 714.7421, "Arelas Brightstar"),
(355872, 1, 5878.808, 349.5903, 805.3762, "Argent Peacekeeper"),
(355872, 2, 5868.299, 406.6215, 761.7755, "Argent Peacekeeper"),
(355872, 3, 5860.884, 526.5018, 711.9791, "Argent Peacekeeper"),
(355872, 4, 5824.564, 558.4792, 688.1653, "Argent Peacekeeper"),
(355872, 5, 5783.678, 573.8768, 660.6657, "Argent Peacekeeper"),
(355872, 6, 5750.437, 598.283, 659.5815, "Argent Peacekeeper"),
(355872, 7, 5717.358, 625.8871, 653.6937, "Argent Peacekeeper"),
(355872, 8, 5702.417, 633.6945, 653.3049, "Argent Peacekeeper"),
(355872, 9, 5678.096, 652.0139, 673.4606, "Argent Peacekeeper"),
(355872, 10, 5642.127, 659.5851, 695.1612, "Argent Peacekeeper"),
(355872, 11, 5557.141, 672.7847, 714.9632, "Argent Peacekeeper"),
(355873, 1, 5889.772, 351.6806, 806.7754, "Argent Peacekeeper"),
(355873, 2, 5880.2, 411.908, 757.5697, "Argent Peacekeeper"),
(355873, 3, 5872.773, 531.5399, 711.2826, "Argent Peacekeeper"),
(355873, 4, 5830.26, 564.6406, 687.3849, "Argent Peacekeeper"),
(355873, 5, 5789.554, 577.5486, 659.9398, "Argent Peacekeeper"),
(355873, 6, 5755.877, 605.9844, 660.134, "Argent Peacekeeper"),
(355873, 7, 5720.882, 632.6962, 653.6631, "Argent Peacekeeper"),
(355873, 8, 5706.856, 640.7604, 654.0797, "Argent Peacekeeper"),
(355873, 9, 5679.256, 661.4375, 673.4254, "Argent Peacekeeper"),
(355873, 10, 5644.36, 668.2396, 695.0526, "Argent Peacekeeper"),
(355873, 11, 5557.845, 682.9636, 714.3047, "Argent Peacekeeper");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35604, 3560400, -(@GUID+1), -(@GUID+2), 35589, 3558900, -(@GUID+4), -(@GUID+5)) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35589, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jaeren Sunsworn - On Respawn - Set Active"),
(35589, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 35589, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jaeren Sunsworn - On Respawn - Start WP"),
(35589, 0, 2, 0, 40, 0, 100, 0, 3, 0, 0, 0, 4, 15852, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jaeren Sunsworn - On WP 3 Reached - Play Sound"),
(35589, 0, 3, 0, 40, 0, 100, 0, 4, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jaeren Sunsworn - On WP 4 Reached - Say Line 0"),
(35589, 0, 4, 0, 40, 0, 100, 0, 7, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jaeren Sunsworn - On WP 7 Reached - Say Line 1"),
(35589, 0, 5, 0, 40, 0, 100, 0, 10, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jaeren Sunsworn - On WP 10 Reached - Despawn"),
(-(@GUID+1), 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On Respawn - Set Active"),
(-(@GUID+1), 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 355870, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On Respawn - Start WP"),
(-(@GUID+1), 0, 2, 0, 40, 0, 100, 0, 10, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On WP 10 Reached - Despawn"),
(-(@GUID+2), 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On Repawn - Set Active"),
(-(@GUID+2), 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 355871, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On Respawn - Start WP"),
(-(@GUID+2), 0, 2, 0, 40, 0, 100, 0, 9, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On WP 9 Reached - Despawn"),
(35604, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arelas Brightstar - On Spawn - Run Script"),
(35604, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 35604, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arelas Brightstar - On Script - Start WP"),
(35604, 0, 2, 0, 40, 0, 100, 0, 4, 0, 0, 0, 4, 15852, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arelas Brightstar - On WP 4 Reached - Play Sound"),
(35604, 0, 3, 0, 40, 0, 100, 0, 5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arelas Brightstar - On WP 5 Reached - Say Line 0"),
(35604, 0, 4, 0, 40, 0, 100, 0, 8, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arelas Brightstar - On WP 8 Reached - Say Line 1"),
(35604, 0, 5, 0, 40, 0, 100, 0, 11, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Arelas Brightstar - On WP 11 Reached - Despawn"),
(-(@GUID+4), 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On Respawn - Set Active"),
(-(@GUID+4), 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 355872, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - Respawn - Start WP"),
(-(@GUID+4), 0, 2, 0, 40, 0, 100, 0, 11, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On WP 11 Reached - Despawn"),
(-(@GUID+5), 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On Respawn - Set Active"),
(-(@GUID+5), 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 1, 355873, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - Respawn - Start WP"),
(-(@GUID+5), 0, 2, 0, 40, 0, 100, 0, 11, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Argent Peacekeeper - On WP 11 Reached - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID` IN (35589, 35604);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(35589, 0, 0, "The Argent Crusade invites you to test your skills in honorable combat against other heroes of Azeroth at the Argent Tournament.", 12, 0, 100, 0, 0, 0, 35896, 0, "Jaeren Sunsworn"),
(35589, 1, 0, "The champions of the world's great nations have gathered at the Argent Tournament Grounds in northeastern Icecrown to face all challengers.", 12, 0, 100, 0, 0, 0, 35871, 0, "Jaeren Sunsworn"),
(35604, 0, 0, "The Argent Crusade invites you to test your skills in honorable combat against other heroes of Azeroth at the Argent Tournament.", 12, 0, 100, 0, 0, 0, 35896, 0, "Arelas Brightstar"),
(35604, 1, 0, "The champions of the world's great nations have gathered at the Argent Tournament Grounds in northeastern Icecrown to face all challengers.", 12, 0, 100, 0, 0, 0, 35871, 0, "Arelas Brightstar");
*/
