/*
-- Quest "The Prodigal Lich Returns"
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=5666;

UPDATE `creature_text` SET `Emote`=0 WHERE `CreatureID`=1498 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=2 WHERE `CreatureID`=5666 AND `GroupID` IN (0,2);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (149800,566600) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(149800,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Remove Npc Flag Questgiver"),
(149800,9,1,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Store Targetlist"),
(149800,9,2,0,0,0,100,0,0,0,0,0,11,7762,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Cast 'Summon Gunther's Visage'"),
(149800,9,3,0,0,0,100,0,2000,2000,0,0,12,5666,1,21000,0,0,0,8,0,0,0,1765.81,57.0857,-46.3189,1.591,"Bethor Iceshard - On Script - Summon Creature 'Gunther's Visage'"),
(149800,9,4,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,5666,0,0,0,0,0,0,"Bethor Iceshard - On Script - Send Targetlist to 'Guther's Visage'"),
(149800,9,5,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,19,5666,0,0,0,0,0,0,"Bethor Iceshard - On Script - Set Orientation"),
(149800,9,6,0,0,0,100,0,18000,18000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Set Orientation"),
(149800,9,7,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Add Npc Flag Questgiver"),
(566600,9,0,0,0,0,100,0,0,0,0,0,53,0,5666,0,0,0,0,1,0,0,0,0,0,0,0,"Gunther's Visage - On Script - Start Waypoint"),
(566600,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Gunther's Visage - On Script - Say Line 0"),
(566600,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Gunther's Visage - On Script - Say Line 1"),
(566600,9,3,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Gunther's Visage - On Script - Set Orientation"),
(566600,9,4,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Gunther's Visage - On Script - Say Line 2"),
(566600,9,5,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,19,1498,0,0,0,0,0,0,"Gunther's Visage - On Script - Say Line 0 (Bethor Iceshard)");

DELETE FROM `waypoints` WHERE `entry`=5666;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(5666,1,1766.04,62.8454,-46.3213,"");

-- Quest "Rot Hide Origins"
DELETE FROM `smart_scripts` WHERE `entryorguid`=149801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(149801,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Remove Npc Flag Questgiver"),
(149801,9,1,0,0,0,100,0,0,0,0,0,11,5017,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Cast 'Divining Trance'"),
(149801,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Say Line 1"),
(149801,9,3,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Say Line 2"),
(149801,9,4,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Say Line 3"),
(149801,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Add Npc Flag Questgiver");

-- Quest "The Mind's Eye"
DELETE FROM `smart_scripts` WHERE `entryorguid`=251900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(251900,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Remove Npc Flag Questgiver"),
(251900,9,1,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Set Flag Standstate 'Kneel'"),
(251900,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 0"),
(251900,9,3,0,0,0,100,0,3000,3000,0,0,0,11,2362,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Cast Create Spellstone"),
(251900,9,4,0,0,0,100,0,6000,6000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Remove Flag Standstate 'Kneel'"),
(251900,9,5,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 1"),
(251900,9,6,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Add Npc Flag Questgiver");

-- Quest "Elixir of Suffering (Part 2)"
DELETE FROM `smart_scripts` WHERE `entryorguid`=2230 AND `source_type`=0; -- Umpi
DELETE FROM `smart_scripts` WHERE `entryorguid`=223000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2230,0,0,0,20,0,100,512,499,0,0,0,80,223000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umpi - On Quest 'Elixir of Agony (Part 2)' Rewarded - Run Script"),
(2230,0,1,0,20,0,100,512,499,0,0,0,45,1,1,0,0,0,0,19,2216,0,0,0,0,0,0,"Umpi - On Quest 'Elixir of Agony (Part 2)' Rewarded - Set Data to Apothecary Lydon"),
(223000,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umpi - On Script - Say Line 0"),
(223000,9,1,0,0,0,100,0,0,0,0,0,11,3240,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umpi - On Script - Cast 'Bloody Explosion'");

DELETE FROM `creature_text` WHERE `CreatureID`=2230;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2230,0,0,"Croak!",12,0,100,0,0,0,579,0,"Umpi");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2216 AND `source_type`=0 AND `id`=1; -- Apothecary Lydon
DELETE FROM `smart_scripts` WHERE `entryorguid`=221601 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2216,0,1,0,38,0,100,512,1,1,0,0,80,221601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Data Set - Run Script"),
(221601,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.15964,"Apothecary Lydon - On Script - Set Orientation"),
(221601,9,1,0,0,0,100,0,2000,2000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Play Emote 'Laugh'"),
(221601,9,2,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Lydon - On Script - Set Orientation");

-- Quest "Elixir of Pain (Part 2)"
DELETE FROM `smart_scripts` WHERE `entryorguid`=2274 AND `source_type`=0 AND `id` IN (0,1,2); -- Stanley
DELETE FROM `smart_scripts` WHERE `entryorguid`=227400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2274,0,0,0,20,0,100,512,502,0,0,0,80,227400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stanley - On Quest 'Elixir of Pain (Part 2)' Rewarded - Run Script"),
(227400,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stanley - On Script - Say Line 0"),
(227400,9,1,0,0,0,100,0,2000,2000,0,0,36,2275,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stanley - On Script - Update Template To 'Enraged Stanley'"),
(227400,9,2,0,0,0,100,0,0,0,0,0,3,2275,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stanley - On Script - Morph To Creature 'Enraged Stanley'"),
(227400,9,3,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stanley - On Script - Start Attacking");

DELETE FROM `creature_text` WHERE `CreatureID`=2274;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2274,0,0,"%s sniffs the elixir then eagerly digs in!",16,0,100,0,0,0,580,0,"Stanley");

-- Quest "Elixir of Agony (Part 5)"
DELETE FROM `creature_text` WHERE `CreatureID`=2284 AND `GroupID` IN (2,3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2284,2,0,"%s raises his mug to his eye, and frowns.",16,0,100,0,0,0,561,0,"Captured Farmer"),
(2284,3,0,"%s swaggers heavily.",16,0,100,0,0,0,559,0,"Captured Farmer"),
(2284,4,0,"%s mumbles incoherent words.",16,0,100,1,0,0,560,0,"Captured Farmer");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (172800,1589100,1589200,1589300) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(172800,9,0,0,0,0,100,0,0,0,0,0,50,1729,120,0,0,0,0,8,0,0,0,0.437117,-942.794,61.9384,-2.54818,"Dusty Rug - On Script - Summon Gameobject 'Tainted Keg'"),
(172800,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,2284,0,50,0,0,0,0,"Dusty Rug - On Script - Set Data 1 1"),
(172800,9,2,0,0,0,100,0,1000,1000,0,0,50,1730,119,0,0,0,0,8,0,0,0,0.437117,-942.794,61.9384,-2.54818,"Dusty Rug - On Script - Summon Gameobject 'Tainted Keg Smoke'"),
(1589100,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 0"),
(1589100,9,1,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,0.426498,-944.53,61.9386,0,"Captured Farmer - On Script - Move To Position"),
(1589100,9,2,0,0,0,100,0,3000,3000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Play Emote 'Kneel'"),
(1589100,9,3,0,0,0,100,0,1000,1000,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Play Emote 'Stand'"),
(1589100,9,4,0,0,0,100,0,3000,3000,0,0,17,418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State 'Eat'"),
(1589100,9,5,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State 'None'"),
(1589100,9,6,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 2"),
(1589100,9,7,0,0,0,100,0,2000,2000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Kill Self"),
(1589200,9,0,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,-1.4032,-942.653,61.9,0,"Captured Farmer - On Script - Move To Position"),
(1589200,9,1,0,0,0,100,0,3000,3000,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Play Emote 'Kneel'"),
(1589200,9,2,0,0,0,100,0,1000,1000,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Play Emote 'Stand'"),
(1589200,9,3,0,0,0,100,0,3000,3000,0,0,17,418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State 'Eat'"),
(1589200,9,4,0,0,0,100,0,6000,6000,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State 'Stun'"),
(1589200,9,5,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 3"),
(1589200,9,6,0,0,0,100,0,4000,4000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Kill Self"),
(1589300,9,0,0,0,0,100,0,3000,3000,0,0,69,0,0,0,0,0,0,8,0,0,0,0.446124,-941.072,61.91,0,"Captured Farmer - On Script - Move To Position"),
(1589300,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 1"),
(1589300,9,2,0,0,0,100,0,0,0,0,0,5,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Play Emote 'Kneel'"),
(1589300,9,3,0,0,0,100,0,1000,1000,0,0,5,26,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Play Emote 'Stand'"),
(1589300,9,4,0,0,0,100,0,3000,3000,0,0,17,418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State 'Eat'"),
(1589300,9,5,0,0,0,100,0,7500,7500,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Set Emote State 'None'"),
(1589300,9,6,0,0,0,100,0,500,500,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Say Line 4"),
(1589300,9,7,0,0,0,100,0,3000,3000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Farmer - On Script - Kill Self");

-- Quest "The Tower of Althalaxx (Part 4)"
DELETE FROM `smart_scripts` WHERE `entryorguid`=366300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(366300,9,0,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Remove Npc Flag Questgiver"),
(366300,9,1,0,0,0,100,0,1000,1000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 0"),
(366300,9,2,0,0,0,100,0,4000,4000,0,0,0,5,61,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Play Emote 61"),
(366300,9,3,0,0,0,100,0,0,0,0,0,0,50,19862,5,0,0,0,0,8,0,0,0,3186.81,189.953,4.57494,3.48778,"Delgren the Purifier - On Script - Summon Object 'Glowing Soulgem'"),
(366300,9,4,0,0,0,100,0,1000,1000,0,0,0,12,4509,8,0,0,0,0,8,0,0,0,3188.2,191.026,4.53698,3.6802,"Delgren the Purifier - On Script - Summon Sargath"),
(366300,9,5,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 0 (Sargath)"),
(366300,9,6,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 1 (Sargath)"),
(366300,9,7,0,0,0,100,0,7000,7000,0,0,0,1,2,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 2 (Sargath)"),
(366300,9,8,0,0,0,100,0,7000,7000,0,0,0,1,3,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 3 (Sargath)"),
(366300,9,9,0,0,0,100,0,7000,7000,0,0,0,1,4,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 4 (Sargath)"),
(366300,9,10,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 1"),
(366300,9,11,0,0,0,100,0,7000,7000,0,0,0,1,5,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 5 (Sargath)"),
(366300,9,12,0,0,0,100,0,7000,7000,0,0,0,1,6,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Say Line 6 (Sargath)"),
(366300,9,13,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,19,4509,0,0,0,0,0,0,"Delgren the Purifier - On Script - Despawn (Sargath)"),
(366300,9,14,0,0,0,100,0,1000,1000,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Delgren the Purifier - On Script - Add Npc Flag Questgiver");

-- Quest "Fields of Grief (Part 2)"
DELETE FROM `smart_scripts` WHERE `entryorguid`=1931 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1931,0,1,0,20,0,100,512,407,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captured Scarlet Zealot - On Quest 'Fields of Grief' Finished - Set Run Off");
*/
