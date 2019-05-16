-- Quest "Field Duty" (Horde)
-- Krug Skullsplit
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15612;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15612 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1561200,1561201) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15612,0,0,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Respawn - Set Active On"),
(15612,0,1,0,11,0,100,0,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Respawn - Set Npc Flag 'Gossip'"),
(15612,0,2,0,62,0,100,0,6687,0,0,0,12,15620,6,120000,0,0,0,8,0,0,0,-7765,536,-43.4281,0,"Krug Skullsplit - On Gossip Option Selected - Summon 'Hive'Regal Hunter-Killer'"),
(15612,0,3,0,38,0,100,0,1,1,0,0,80,1561200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Data 1 Set - Run Script"),
(15612,0,4,0,38,0,100,0,2,2,0,0,80,1561201,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Data 2 Set - Run Script"),
(15612,0,5,0,4,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Aggro - Say Line 2"),
(15612,0,6,0,0,0,100,0,5000,7000,12000,16000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krug Skullsplit - In Combat - Cast 'Mortal Strike'"),
(15612,0,7,0,0,0,100,0,8000,12000,18000,22000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - In Combat - Cast 'Thunderclap'"),
(1561200,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Script - Say Line 0"),
(1561200,9,1,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Script - Say Line 1"),
(1561200,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,15613,0,0,0,0,0,0,"Krug Skullsplit - On Script - Set Data to Merok Longstride"),
(1561200,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,15615,0,0,0,0,0,0,"Krug Skullsplit - On Script - Set Data to Shadow Priestess Shai"),
(1561201,9,0,0,0,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Script - Set Npc Flag 'Questgiver'"),
(1561201,9,1,0,0,0,100,0,120000,120000,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krug Skullsplit - On Script - Set Npc Flag 'Gossip'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6687;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=15612;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,6687,0,0,0,9,0,8731,0,0,0,0,0,"","Show gossip option if quest 'Field Duty' is taken"),
(22,3,15612,0,0,29,1,15620,900,0,1,0,0,"","SAI triggers only if Hive'Regal Hunter-Killer is not already spawned");

DELETE FROM `creature_text` WHERE `CreatureID`=15612;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15612,0,0,"The enemy is upon us, stand ready!",14,0,100,22,0,0,11286,0,"Krug Skullsplit"),
(15612,1,0,"Merok!  Shai!  To my side!",14,0,100,5,0,0,11287,0,"Krug Skullsplit"),
(15612,2,0,"For the Horde!",14,0,100,0,0,0,11288,0,"Krug Skullsplit");

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6687);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6687,0,0,"Reporting for duty, sir.",11274,1,1,6688,0,0,0,"",0,0);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (6688);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6688,8060,0);

UPDATE `npc_text` SET `text0_0`="You're just in time, $c.  Do you feel the ground shaking beneath you?$B$BSomething approaches from the hive.  Take a place near the grunts, $n.  I'm counting on you!", `text0_1`="" WHERE `ID`=8060;

-- Hive'Regal Hunter-Killer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15620;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15620 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15620,0,0,0,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - Just Summoned - Set Active On"),
(15620,0,1,0,54,0,100,0,0,0,0,0,53,0,15620,0,0,0,2,1,0,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - Just Summoned - Start Waypoint"),
(15620,0,2,0,40,0,100,0,11,15620,0,0,45,1,1,0,0,0,0,19,15612,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - On Waypoint 11 Reached - Set Data 1 to Krug Skullsplit"),
(15620,0,3,0,0,0,100,0,15000,20000,25000,30000,11,25821,0,0,0,0,0,21,40,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - In Combat - Cast 'Charge'"),
(15620,0,4,0,0,0,100,0,7000,10000,16000,19000,11,15588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - In Combat - Cast 'Thunderclap'"),
(15620,0,5,0,0,0,100,0,5000,7000,5000,12000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - In Combat - Cast 'Cleave'"),
(15620,0,6,0,0,0,100,0,10000,15000,35000,40000,11,25815,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - In Combat - Cast 'Frightening Shriek'"),
(15620,0,7,0,6,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,15612,0,0,0,0,0,0,"Hive'Regal Hunter-Killer - On Just Died - Set Data 2 to Krug Skullsplit");

DELETE FROM `waypoints` WHERE `entry`=15620;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(15620, 1, -7769.14, 549.365, -44.1111),
(15620, 2, -7762.88, 564.709, -45.9125),
(15620, 3, -7749.28, 589.14, -47.1617),
(15620, 4, -7748.5, 622.853, -45.2946),
(15620, 5, -7730.37, 643.343, -46.7866),
(15620, 6, -7694.24, 660.321, -51.0377),
(15620, 7, -7674.25, 671.264, -50.4592),
(15620, 8, -7655.01, 671.601, -47.9161),
(15620, 9, -7634.07, 672.497, -47.8617),
(15620, 10, -7603.06, 667.321, -48.6429),
(15620, 11, -7571.59, 665.263, -48.3899),
(15620, 12, -7562.58, 687.328, -49.9864),
(15620, 13, -7559.18, 689.958, -40.8654),
(15620, 14, -7555.3, 692.953, -30.7562),
(15620, 15, -7548.27, 697.037, -25.6632),
(15620, 16, -7547.07, 706.949, -17.7001),
(15620, 17, -7549.78, 711.901, -16.4527);

-- Merok Longstride
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15613;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15613 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15613,0,0,0,0,0,100,0,3000,6000,13000,16000,11,15616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Merok Longstride - In Combat - Cast 'Flame Shock'"),
(15613,0,1,0,23,0,100,0,15507,0,3000,5000,11,15507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Merok Longstride - In Combat - Cast 'Lightning Shield'"),
(15613,0,2,0,14,0,100,0,4000,40,15000,20000,11,15982,0,0,0,0,0,7,0,0,0,0,0,0,0,"Merok Longstride - Friendly At 4000 Health - Cast 'Healing Wave'"),
(15613,0,3,0,38,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,-7542.45,720.155,-15.6801,0,"Merok Longstride - On Data Set - Move to Position");

-- Shadow Priestess Shai
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15615;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15615 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15615,0,0,0,0,0,100,0,3000,5000,12000,16000,11,17194,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadow Priestess Shai - In Combat - Cast 'Mind Blast'"),
(15615,0,1,0,0,0,100,0,6000,8000,22000,26000,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Shadow Priestess Shai - In Combat - Cast 'Shadow Word: Pain'"),
(15615,0,2,0,14,0,100,0,4000,40,15000,20000,11,17138,0,0,0,0,0,7,0,0,0,0,0,0,0,"Shadow Priestess Shai - Friendly At 4000 Health - Cast 'Flash Heal'"),
(15615,0,3,0,38,0,100,0,1,1,0,0,69,0,0,0,0,0,0,8,0,0,0,-7553.46,720.924,-16.715,0,"Shadow Priestess Shai - On Data Set - Move to Position");

-- Alliance version
-- Janela Stouthammer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15443;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15443 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1544300,1544301) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15443,0,0,0,11,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janela Stouthammer - On Respawn - Set Active On"),
(15443,0,1,0,62,0,100,0,6623,0,0,0,80,1544300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janela Stouthammer - On Gossip Option Selected - Run Script"),
(15443,0,2,0,0,0,100,0,5000,7000,12000,16000,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Janela Stouthammer - In Combat - Cast 'Crusader Strike'"),
(15443,0,3,0,14,0,100,0,4000,40,15000,20000,11,25263,0,0,0,0,0,7,0,0,0,0,0,0,0,"Janela Stouthammer - Friendly At 4000 Health - Cast 'Holy Light'"),
(1544300,9,0,0,0,0,100,0,0,0,0,0,12,15449,6,120000,0,0,0,8,0,0,0,-7355.47,1660.02,-33.1674,5.4105,"Janela Stouthammer - On Script - Summon 'Hive'Zora Abomination'"),
(1544300,9,1,0,0,0,100,0,20000,20000,0,0,12,15440,6,60000,0,0,0,8,0,0,0,-7168.18,1380.71,2.91784,1.09484,"Janela Stouthammer - On Script - Summon 'Captain Blackanvil'"),
(1544300,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,10,42910,15441,0,0,0,0,0,"Janela Stouthammer - On Script - Say Line 0 (Ironforge Brigade Rifleman)"),
(1544300,9,3,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Janela Stouthammer - On Script - Say Line 0"),
(1544300,9,4,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,10,42910,15441,0,0,0,0,0,"Janela Stouthammer - On Script - Say Line 1 (Ironforge Brigade Rifleman)"),
(1544300,9,5,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,42910,15441,0,0,0,0,0,"Janela Stouthammer - On Script - Set Data to Ironforge Brigade Rifleman");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6623;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,6623,0,0,0,9,0,8507,0,0,0,0,0,"","Show gossip option if quest 'Field Duty' is taken"),
(15,6623,0,0,0,29,1,15449,900,0,1,0,0,"","SAI triggers only if Hive'Zora Abomination is not already spawned"),
(15,6623,0,0,0,29,1,15440,900,0,1,0,0,"","SAI triggers only if Captain Blackanvil is not already spawned");

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6623);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6623,0,0,"I'm here to aid the Captain.",11006,1,1,6624,0,0,0,"",0,0);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (6624);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6624,7875,0);

-- Hive'Zora Abomination
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15449;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15449 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15449,0,0,0,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive'Zora Abomination - Just Summoned - Set Active On"),
(15449,0,1,0,54,0,100,0,0,0,0,0,53,0,15449,0,0,0,2,1,0,0,0,0,0,0,0,"Hive'Zora Abomination - Just Summoned - Start Waypoint"),
(15449,0,2,0,0,0,100,0,8000,12000,16000,24000,11,25189,0,0,0,0,0,6,0,0,0,0,0,0,0,"Hive'Zora Abomination - In Combat - Cast 'Enveloping Winds'"),
(15449,0,3,0,0,0,100,0,9000,13000,15000,25000,11,25198,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive'Zora Abomination - In Combat - Cast 'Poison Cloud'"),
(15449,0,4,0,0,0,100,0,5000,7000,13000,17000,11,25262,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hive'Zora Abomination - In Combat - Cast 'Abomination Spit'"),
(15449,0,5,0,0,0,100,0,10000,15000,35000,40000,11,25260,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hive'Zora Abomination - In Combat - Cast 'Wings of Despair'"),
(15449,0,6,0,40,0,100,0,6,15449,0,0,45,2,2,0,0,0,0,19,15440,0,0,0,0,0,0,"Hive'Zora Abomination - On Waypoint 6 Reached - Set Data 2 to Captain Blackanvil"),
(15449,0,7,0,6,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,15440,0,0,0,0,0,0,"Hive'Zora Abomination - On Just Died - Set Data 3 to Captain Blackanvil");

DELETE FROM `waypoints` WHERE `entry`=15449;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(15449, 1, -7327.58, 1626.2, -30.2021),
(15449, 2, -7280.14, 1586.27, -29.5117),
(15449, 3, -7254.51, 1552.92, -15.7705),
(15449, 4, -7241.55, 1498.67, -5.84411),
(15449, 5, -7212.22, 1452.28, -2.78192),
(15449, 6, -7205.93, 1433.55, 4.94912),
(15449, 7, -7203.28, 1417.93, 5.47492),
(15449, 8, -7181.79, 1397.39, 2.85378);

-- Ironforge Brigade Rifleman
DELETE FROM `smart_scripts` WHERE `entryorguid`=-42910 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-42910,0,0,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ironforge Brigade Rifleman - In Combat - Cast 'Shoot'"),
(-42910,0,1,0,38,0,100,0,1,1,0,0,53,1,15441,0,0,0,2,1,0,0,0,0,0,0,0,"Ironforge Brigade Rifleman - On Data Set - Start Waypoint"),
(-42910,0,2,0,40,0,100,0,1,15441,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironforge Brigade Rifleman - On Waypoint 1 Reached - Pause Waypoint"),
(-42910,0,3,0,40,0,100,0,1,15441,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.24021,"Ironforge Brigade Rifleman - On Waypoint 1 Reached - Set Orientation"),
(-42910,0,4,0,40,0,100,0,1,15441,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ironforge Brigade Rifleman - On Waypoint 1 Reached - Say Line 2"),
(-42910,0,5,0,40,0,100,0,1,15441,0,0,45,1,1,0,0,0,0,19,15440,0,0,0,0,0,0,"Ironforge Brigade Rifleman - On Waypoint 1 Reached - Set Data 1 to Captain Blackanvil"),
(-42910,0,6,0,40,0,100,0,1,15441,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.23402,"Ironforge Brigade Rifleman - On Waypoint 2 Reached - Set Orientation");

DELETE FROM `waypoints` WHERE `entry`=15441;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(15441, 1, -7167.08, 1382.81, 2.9195),
(15441, 2, -7178.14, 1390.42, 2.9267);

-- Captain Blackanvil
DELETE FROM `creature` WHERE `guid`=150185; -- Captain Blackanvil only spawns during the event

UPDATE `creature_template` SET `npcflag`=2, `AIName`="SmartAI" WHERE `entry`=15440;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15440 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1544000,1544001,1544002) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15440,0,0,0,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - Just Summoned - Set Active On"),
(15440,0,1,0,54,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - Just Summoned - Remove Npc Flag 'Questgiver'"),
(15440,0,2,0,38,0,100,0,1,1,0,0,80,1544000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Data 1 Set - Run Script"),
(15440,0,3,0,38,0,100,0,2,2,0,0,80,1544001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Data 2 Set - Run Script"),
(15440,0,4,0,38,0,100,0,3,3,0,0,80,1544002,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Data 3 Set - Run Script"),
(1544000,9,0,0,0,0,100,0,7000,7000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Script - Say Line 0"),
(1544000,9,1,0,0,0,100,0,4000,4000,0,0,53,0,15440,0,0,0,2,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Script - Start Waypoint"),
(1544000,9,2,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Script - Say Line 1"),
(1544001,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Script - Say Line 2"),
(1544001,9,1,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Script - Say Line 3"),
(1544002,9,0,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Script - Add Npc Flag 'Questgiver'"),
(1544002,9,1,0,0,0,100,0,120000,120000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Blackanvil - On Script - Despawn");

DELETE FROM `waypoints` WHERE `entry`=15440;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES
(15440, 1, -7169.92, 1384.67, 2.91995),
(15440, 2, -7177.31, 1393.31, 2.60589);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (15443, 15441, 15440);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15441,0,0,"Something big's coming out from the hive, ma'am.  Headed straight for us.",12,0,100,0,0,0,10973,0,"Ironforge Brigade Rifleman"),
(15441,1,0,"Yes, Ma'am!",12,0,100,66,0,0,10975,0,"Ironforge Brigade Rifleman"),
(15441,2,0,"Captain!  Lieutenant Stouthammer requests your presence!  The enemy is approaching, sir!",12,0,100,66,0,0,10976,0,"Ironforge Brigade Rifleman"),
(15443,0,0,"Soldier, call Captain Blackanvil at once!",12,0,100,25,0,0,10974,0,"Janela Stouthammer"),
(15440,0,0,"Aye, lads!  Things are about to get quite ugly.",14,0,100,5,0,0,10967,0,"Captain Blackanvil"),
(15440,1,0,"Looks like it's going to be one of those days.",14,0,100,0,0,0,10968,0,"Captain Blackanvil"),
(15440,2,0,"I should've grabbed a bigger sword.",14,0,100,0,0,0,10969,0,"Captain Blackanvil"),
(15440,3,0,"Footmen, make a line!",14,0,100,25,0,0,10970,0,"Captain Blackanvil");

-- Arcanist Nozzlespring
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15444;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15444 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15444,0,0,0,0,0,100,0,0,0,3000,5000,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Arcanist Nozzlespring - In Combat - Cast 'Fireball'"),
(15444,0,1,0,0,0,100,0,6000,9000,14000,20000,11,15790,64,0,0,0,0,2,0,0,0,0,0,0,0,"Arcanist Nozzlespring - In Combat - Cast 'Arcane Missiles'");
