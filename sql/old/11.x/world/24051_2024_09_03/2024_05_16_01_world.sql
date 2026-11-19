SET @CGUID := 397123;

DELETE FROM `creature` WHERE `guid` IN (450338, 450300, 450306, 450328, 450398, 450416, 450431, 450311, 450332, 450312, 450339, 450532, 450473, 450472, 450433, 450477, 450530, 450396, 450306, 450418, 450424, 450446, 450476, 450443, 450450); -- Reusable guids

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 56739, 860, 5736, 5825, '0', 0, 0, 0, 0, 1358.9617919921875, 3672.4150390625, 94.14377593994140625, 3.787364482879638671, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53584), -- Hozen Hanging Bunny (Area: The Dawning Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 56739, 860, 5736, 5825, '0', 0, 0, 0, 0, 1437.204833984375, 3651.520751953125, 92.66880035400390625, 3.089232683181762695, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54070), -- Hozen Hanging Bunny (Area: The Dawning Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 56739, 860, 5736, 5825, '0', 0, 0, 0, 0, 1437.5191650390625, 3621.397705078125, 89.036590576171875, 2.443460941314697265, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53584), -- Hozen Hanging Bunny (Area: The Dawning Valley - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 56739, 860, 5736, 5835, '0', 0, 0, 0, 0, 1459.907958984375, 3756.73779296875, 95.20215606689453125, 3.473205089569091796, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205), -- Hozen Hanging Bunny (Area: Wu-Song Village - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 56739, 860, 5736, 5825, '0', 0, 0, 0, 0, 1366.236083984375, 3786.056396484375, 96.02268218994140625, 5.445427417755126953, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54205); -- Hozen Hanging Bunny (Area: The Dawning Valley - Difficulty: 0) CreateObject1 (Auras: )

UPDATE `creature` SET `equipment_id` = 0 WHERE `guid` IN (450303, 450341, 450404, 450457, 450409, 450439, 450544, 450537);
UPDATE `creature` SET `equipment_id` = 1 WHERE `guid` = 450307;
UPDATE `creature` SET `position_x`=1445.74, `position_y`=3713.97, `position_z`=79.9498 WHERE `guid`=450438;
UPDATE `creature` SET `StringId` ='npc_wu_song_villager_attack_1' WHERE `guid` = 450409;
UPDATE `creature` SET `StringId` ='npc_wu_song_villager_attack_2' WHERE `guid` = 450439;
UPDATE `creature` SET `StringId` ='npc_wu_song_villager_attack_3' WHERE `guid` = 450475;
UPDATE `creature` SET `StringId` ='npc_wu_song_villager_attack_4' WHERE `guid` = 450303;
UPDATE `creature` SET `StringId` ='npc_wu_song_villager_attack_5' WHERE `guid` = 450323;
UPDATE `creature` SET `StringId` ='npc_wu_song_villager_attack_6' WHERE `guid` = 450438;
UPDATE `creature` SET `StringId` ='npc_wu_song_villager_attack_7' WHERE `guid` = 450455;

UPDATE `creature` SET `StringId` ='npc_fe_feng_hozen_attack_1' WHERE `guid` = 450402;
UPDATE `creature` SET `StringId` ='npc_fe_feng_hozen_attack_2' WHERE `guid` = 450448;
UPDATE `creature` SET `StringId` ='npc_fe_feng_hozen_attack_3' WHERE `guid` = 450451;
UPDATE `creature` SET `StringId` ='npc_fe_feng_brewthief_attack_1' WHERE `guid` = 450305;
UPDATE `creature` SET `StringId` ='npc_fe_feng_brewthief_attack_2' WHERE `guid` = 450326;
UPDATE `creature` SET `StringId` ='npc_fe_feng_brewthief_attack_3' WHERE `guid` = 450436;
UPDATE `creature` SET `StringId` ='npc_fe_feng_brewthief_attack_4' WHERE `guid` = 450456;

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`Entry`=57164 AND `DifficultyID`=0); -- Fe-Feng Leaper
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`Entry`=56730 AND `DifficultyID`=0); -- Fe-Feng Brewthief
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54070 WHERE (`Entry`=54131 AND `DifficultyID`=0); -- Fe-Feng Hozen
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=53584 WHERE (`Entry`=56739 AND `DifficultyID`=0); -- Hozen Hanging Bunny
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`DifficultyID`=0 AND `Entry` IN (65472,57132)); -- Wu-Song Villager
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53584 WHERE (`Entry`=57617 AND `DifficultyID`=0); -- Lee Sunspark

DELETE FROM `creature_template_addon` WHERE `entry` IN (57164, 57205);

DELETE FROM `creature_template_addon` WHERE `entry` IN (57617, 54568);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(57617, 0, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, NULL),
(54568, 0, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, NULL);

UPDATE `creature_template_addon` SET `auras`='109084' WHERE `entry`=56730; -- 56730 (Fe-Feng Brewthief) - Drunken Boxing

DELETE FROM `creature_addon` WHERE `guid`IN (450317, 450303, 450323, 450324, 450321, 450318, 450320, 450322, 450315, 450329, 450335, 450308, 450404, 450409, 450555, 450438, 450439, 450475, 450455);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450317, 0, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, NULL),
(450303, 0, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, NULL),
(450323, 0, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, NULL),
(450438, 0, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, NULL),
(450475, 0, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, NULL),
(450455, 0, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, NULL),
(450409, 0, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, NULL),
(450439, 0, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, NULL),
(450329, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '109084 107747'),
(450555, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL),
(450335, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL),
(450308, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL),
(450404, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL),
(450324, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96733'),
(450321, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96733'),
(450318, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96733'),
(450320, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96733'),
(450322, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96733'),
(450315, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '96733');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=56730; -- Fe-Feng Brewthief
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=57164; -- Fe-Feng Leaper
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (57205, 54131); -- Fe-Feng Hozen
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (57132, 65472); -- Wu-Song Villager
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=54568; -- Ji Firepaw

DELETE FROM `creature_template_sparring` WHERE `Entry` IN (57132, 56730, 57205, 65472) AND `NoNPCDamageBelowHealthPct`=85;
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(57132, 85),
(65472, 85),
(57205, 85),
(56730, 85);

DELETE FROM `creature_text` WHERE `CreatureID` = 54568;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(54568, 0, 0, 'Take that monkeybutt!', 12, 0, 100, 5, 0, 27344, 59757, 0, 'Ji Firepaw to Player');

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=56739 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(56739, 54131, 0, 0, 'Hozen Hanging Bunny - Fe-Feng Hozen', 7, 0); -- Hozen Hanging Bunny - Fe-Feng Hozen

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=56739 AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(56739, 46598, 0, 0);

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=-450434 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450434, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450341 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450341, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Hozen - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450457 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450457, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Hozen - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450447 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450447, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450344 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450344, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450304 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450304, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450445 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450445, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450478 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450478, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450336 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450336, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450334 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450334, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450314 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450314, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450313 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450313, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450474 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450474, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450471 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450471, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

-- Waypoints
-- Normal waypoints
-- Fe-Feng Hozen 1
SET @ENTRY := 57205;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1251.481, 3684.075, 93.97271, NULL, 0),
(@PATH, 1, 1265.085, 3689.423, 93.59255, NULL, 0),
(@PATH, 2, 1281.759, 3671.965, 89.19791, NULL, 0),
(@PATH, 3, 1295.333, 3662.651, 89.23215, NULL, 0),
(@PATH, 4, 1302.435, 3666.339, 86.99618, NULL, 0),
(@PATH, 5, 1314.788, 3669.837, 86.47299, NULL, 0),
(@PATH, 6, 1323.345, 3665.26, 85.1386, NULL, 0),
(@PATH, 7, 1302.436, 3666.339, 87.02302, NULL, 0),
(@PATH, 8, 1295.334, 3662.651, 89.20162, NULL, 0),
(@PATH, 9, 1281.759, 3671.965, 89.19791, NULL, 0),
(@PATH, 10, 1265.085, 3689.423, 93.59255, NULL, 0),
(@PATH, 11, 1257.632, 3692.337, 94.46534, NULL, 0),
(@PATH, 12, 1251.481, 3684.075, 93.97271, NULL, 0);

UPDATE `creature` SET `position_x`= 1251.481, `position_y`= 3684.075, `position_z`= 93.97271, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450535;
DELETE FROM `creature_addon` WHERE `guid`= 450535;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450535, @PATH, 1);

-- Fe-Feng Hozen 2
SET @ENTRY := 57205;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 2');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1510.571, 3655.367, 77.37856, NULL, 390),
(@PATH, 1, 1508.556, 3633.912, 78.70818, NULL, 0),
(@PATH, 2, 1490.227, 3610.696, 81.53677, NULL, 0),
(@PATH, 3, 1472.73, 3603.274, 87.48109, NULL, 0),
(@PATH, 4, 1450.028, 3598.661, 86.96149, NULL, 0),
(@PATH, 5, 1427.795, 3595.583, 89.88957, NULL, 0),
(@PATH, 6, 1417.955, 3600.851, 89.90552, NULL, 0),
(@PATH, 7, 1418.339, 3617.548, 86.55445, NULL, 0),
(@PATH, 8, 1420.514, 3629.339, 83.81339, NULL, 0),
(@PATH, 9, 1410.627, 3644.011, 82.84434, NULL, 0),
(@PATH, 10, 1399.51, 3646.278, 86.80801, NULL, 0),
(@PATH, 11, 1393.873, 3650.874, 86.88097, NULL, 0),
(@PATH, 12, 1393.064, 3661.001, 87.92618, NULL, 0),
(@PATH, 13, 1381.281, 3672.597, 87.92618, NULL, 0),
(@PATH, 14, 1369.106, 3669.344, 87.92618, NULL, 0),
(@PATH, 15, 1356.769, 3666.675, 88.03418, NULL, 0),
(@PATH, 16, 1347.543, 3676.744, 85.85583, NULL, 204),
(@PATH, 17, 1356.769, 3666.675, 88.03418, NULL, 0),
(@PATH, 18, 1369.106, 3669.344, 87.92618, NULL, 0),
(@PATH, 19, 1381.281, 3672.597, 87.92618, NULL, 0),
(@PATH, 20, 1393.064, 3661.001, 87.92618, NULL, 0),
(@PATH, 21, 1393.873, 3650.874, 86.88097, NULL, 0),
(@PATH, 22, 1399.51, 3646.278, 86.80801, NULL, 0),
(@PATH, 23, 1410.627, 3644.011, 82.84434, NULL, 0),
(@PATH, 24, 1420.514, 3629.339, 83.81339, NULL, 0),
(@PATH, 25, 1418.339, 3617.548, 86.55445, NULL, 0),
(@PATH, 26, 1417.955, 3600.851, 89.90552, NULL, 0),
(@PATH, 27, 1427.795, 3595.583, 89.88957, NULL, 0),
(@PATH, 28, 1450.028, 3598.661, 86.96149, NULL, 0),
(@PATH, 29, 1472.578, 3603.221, 87.48109, NULL, 0),
(@PATH, 30, 1490.227, 3610.696, 81.53677, NULL, 0),
(@PATH, 31, 1508.556, 3633.912, 78.70818, NULL, 0);

UPDATE `creature` SET `position_x`= 1510.571, `position_y`= 3655.367, `position_z`= 77.37856, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450307;
DELETE FROM `creature_addon` WHERE `guid`= 450307;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450307, @PATH, 1);

-- Fe-Feng Hozen 3
SET @ENTRY := 57205;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 3');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1433.557, 3710.008, 79.5691, NULL, 0),
(@PATH, 1, 1445.766, 3710.594, 79.94168, NULL, 0),
(@PATH, 2, 1452.951, 3714.253, 79.94983, NULL, 0),
(@PATH, 3, 1456.028, 3724.659, 82.1713, NULL, 0),
(@PATH, 4, 1453.163, 3731.899, 84.73679, NULL, 0),
(@PATH, 5, 1447.457, 3738.717, 85.36936, NULL, 0),
(@PATH, 6, 1447.764, 3751.399, 85.08856, NULL, 0),
(@PATH, 7, 1444.819, 3760.462, 84.78928, NULL, 0),
(@PATH, 8, 1436.623, 3769.741, 84.52623, NULL, 0),
(@PATH, 9, 1428.234, 3775.19, 84.49818, NULL, 0),
(@PATH, 10, 1414.582, 3772.882, 83.44241, NULL, 0),
(@PATH, 11, 1406.505, 3761.499, 84.41571, NULL, 0),
(@PATH, 12, 1409.063, 3749.219, 84.39035, NULL, 0),
(@PATH, 13, 1415.936, 3736.017, 82.43708, NULL, 0),
(@PATH, 14, 1417.028, 3725.414, 81.06744, NULL, 0),
(@PATH, 15, 1420.585, 3713.412, 79.68462, NULL, 0);

UPDATE `creature` SET `position_x`= 1433.557, `position_y`= 3710.008, `position_z`= 79.5691, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450441;
DELETE FROM `creature_addon` WHERE `guid`= 450441;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450441, @PATH, 1);

-- Waypoints of creatures who attack other npcs
-- Fe-Feng Hozen 1
SET @ENTRY := 57205;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint to Wu-Song Villager 3');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1473.46, 3715.695, 79.83499, NULL, 0),
(@PATH, 1, 1465.448, 3708.645, 79.85747, NULL, 0),
(@PATH, 2, 1457.01, 3703.309, 79.78724, NULL, 0),
(@PATH, 3, 1442.898, 3702.631, 79.27051, NULL, 0),
(@PATH, 4, 1432.934, 3706.349, 79.93696, NULL, 0),
(@PATH, 5, 1423.271, 3708.028, 79.52547, NULL, 0),
(@PATH, 6, 1417.344, 3697.451, 78.79962, NULL, 0),
(@PATH, 7, 1414.998, 3688.631, 83.38158, NULL, 0);

UPDATE `creature` SET `position_x`= 1473.46, `position_y`= 3715.695, `position_z`= 79.83499, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450402;

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450402 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450402, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5720502, 0, 0, 0, 2, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Hozen - On just created - Self: Start path #5673000, run, do not repeat, Aggresive'),
(-450402, 0, 1, 2, '', 58, 0, 100, 0, 7, 5720502, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57132, 0, 0, 0, 'npc_wu_song_villager_attack_1', 0, 0, 0, 0, 'Fe-Feng Hozen - On Waypoint Finished - Start Attacking'),
(-450402, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Hozen - On Linked - Disable Health Regen');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450409 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450409, 0, 0, 1, '', 75, 0, 100, 1, 0, 57205, 2, 1000, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57205, 0, 0, 0, 'npc_fe_feng_hozen_attack_1', 0, 0, 0, 0, 'Wu-Song Villager - On Creature Distance - Start Attacking'),
(-450409, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wu-Song Villager - On Linked - Disable Health Regen');

-- Fe-Feng Hozen 2
SET @ENTRY := 57205;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint to Wu-Song Villager 5');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1450.712, 3763.139, 85.01343, NULL, 0),
(@PATH, 1, 1444.384, 3745.242, 84.93659, NULL, 0),
(@PATH, 2, 1434.585, 3739.824, 84.23158, NULL, 0),
(@PATH, 3, 1422.84, 3740.06, 83.58831, NULL, 0),
(@PATH, 4, 1410.189, 3739.675, 83.69814, NULL, 0);

UPDATE `creature` SET `position_x`= 1450.712, `position_y`= 3763.139, `position_z`= 85.01343, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450448;

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450448 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450448, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5720504, 0, 0, 0, 2, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Hozen - On just created - Self: Start path #5673000, run, do not repeat, Aggresive'),
(-450448, 0, 1, 2, '', 58, 0, 100, 0, 4, 5720504, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57132, 0, 0, 0, 'npc_wu_song_villager_attack_2', 0, 0, 0, 0, 'Fe-Feng Hozen - On Waypoint Finished - Start Attacking'),
(-450448, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Hozen - On Linked - Disable Health Regen');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450439 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450439, 0, 0, 1, '', 75, 0, 100, 1, 0, 57205, 2, 1000, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57205, 0, 0, 0, 'npc_fe_feng_hozen_attack_2', 0, 0, 0, 0, 'Wu-Song Villager - On Creature Distance - Start Attacking'),
(-450439, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wu-Song Villager - On Linked - Disable Health Regen');

-- Fe-Feng Hozen 3
SET @ENTRY := 57205;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint to Wu-Song Villager 7');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1358.036, 3768.396, 83.11465, NULL, 0),
(@PATH, 1, 1372.575, 3767.295, 84.63619, NULL, 0),
(@PATH, 2, 1394.809, 3753.418, 84.93942, NULL, 0),
(@PATH, 3, 1409.22, 3749.642, 84.4346, NULL, 0),
(@PATH, 4, 1420.172, 3750.372, 84.69238, NULL, 0);

UPDATE `creature` SET `position_x`= 1358.036, `position_y`= 3768.396, `position_z`= 83.11465, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450451;

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450451 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450451, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5720505, 0, 0, 0, 2, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Hozen - On just created - Self: Start path #5673000, run, do not repeat, Aggresive'),
(-450451, 0, 1, 2, '', 58, 0, 100, 0, 4, 5720505, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57132, 0, 0, 0, 'npc_wu_song_villager_attack_3', 0, 0, 0, 0, 'Fe-Feng Hozen - On Waypoint Finished - Start Attacking'),
(-450451, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Hozen - On Linked - Disable Health Regen');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450475 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450475, 0, 0, 1, '', 75, 0, 100, 1, 0, 57205, 2, 1000, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57205, 0, 0, 0, 'npc_fe_feng_hozen_attack_3', 0, 0, 0, 0, 'Wu-Song Villager - On Creature Distance - Start Attacking'),
(-450475, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wu-Song Villager - On Linked - Disable Health Regen');

-- Fe-Feng Brewthief 1
SET @ENTRY := 56730;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to Wu-Song Villager 1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1472.51, 3608.762, 85.91302, NULL, 0),
(@PATH, 1, 1455.12, 3603.943, 86.8589, NULL, 0),
(@PATH, 2, 1440.436, 3610.888, 87.19036, NULL, 0),
(@PATH, 3, 1433.392, 3619.705, 84.96278, NULL, 0),
(@PATH, 4, 1432.549, 3623.884, 84.26337, NULL, 0);

UPDATE `creature` SET `position_x`= 1472.51, `position_y`= 3608.762, `position_z`= 85.91302, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450305;

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450305 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450305, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673000, 0, 0, 0, 2, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On just created - Self: Start path #5673000, run, do not repeat, Aggresive'),
(-450305, 0, 1, 2, '', 58, 0, 100, 0, 4, 5673000, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57132, 0, 0, 0, 'npc_wu_song_villager_attack_4', 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Start Attacking'),
(-450305, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Linked - Disable Health Regen');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450303 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450303, 0, 0, 1, '', 75, 0, 100, 1, 0, 56730, 2, 1000, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 56730, 0, 0, 0, 'npc_fe_feng_brewthief_attack_1', 0, 0, 0, 0, 'Wu-Song Villager - On Creature Distance - Start Attacking'),
(-450303, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wu-Song Villager - On Linked - Disable Health Regen');

-- Fe-Feng Brewthief 2
SET @ENTRY := 56730;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to Wu-Song Villager 2');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1341.082, 3680.921, 83.52776, NULL, 0),
(@PATH, 1, 1342.387, 3668.629, 87.68966, NULL, 0),
(@PATH, 2, 1350.229, 3652.049, 88.62582, NULL, 0),
(@PATH, 3, 1360.543, 3642.147, 88.033, NULL, 0),
(@PATH, 4, 1372.198, 3639.886, 87.92618, NULL, 0),
(@PATH, 5, 1378.575, 3640.457, 87.92618, NULL, 0),
(@PATH, 6, 1383.488, 3645.484, 87.8055, NULL, 0),
(@PATH, 7, 1384.646, 3650.066, 87.75733, NULL, 0);

UPDATE `creature` SET `position_x`= 1341.082, `position_y`= 3680.921, `position_z`= 83.52776, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450326;

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450326 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450326, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673001, 0, 0, 0, 2, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On just created - Self: Start path #5673000, run, do not repeat, Aggresive'),
(-450326, 0, 1, 2, '', 58, 0, 100, 0, 7, 5673001, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 57132, 0, 0, 0, 'npc_wu_song_villager_attack_5', 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Start Attacking'),
(-450326, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Linked - Disable Health Regen');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450323 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450323, 0, 0, 1, '', 75, 0, 100, 1, 0, 56730, 2, 1000, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 56730, 0, 0, 0, 'npc_fe_feng_brewthief_attack_2', 0, 0, 0, 0, 'Wu-Song Villager - On Creature Distance - Start Attacking'),
(-450323, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wu-Song Villager - On Linked - Disable Health Regen');

-- Fe-Feng Brewthief 3
SET @ENTRY := 56730;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to Wu-Song Villager 4');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1475.618, 3758.82, 81.3439, NULL, 0),
(@PATH, 1, 1473.146, 3738.558, 81.6088, NULL, 0),
(@PATH, 2, 1462.161, 3728.173, 83.25296, NULL, 0),
(@PATH, 3, 1453.792, 3716.79, 79.94983, NULL, 0),
(@PATH, 4, 1449.754, 3712.675, 79.94983, NULL, 0),
(@PATH, 5, 1448.912, 3712.947, 79.94983, 0, 0);

UPDATE `creature` SET `position_x`= 1475.618, `position_y`= 3758.82, `position_z`= 81.3439, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450436;

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450436 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450436, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673002, 0, 0, 0, 2, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On just created - Self: Start path #5673000, run, do not repeat, Aggresive'),
(-450436, 0, 1, 2, '', 58, 0, 100, 0, 5, 5673002, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 65472, 0, 0, 0, 'npc_wu_song_villager_attack_6', 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Start Attacking'),
(-450436, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Linked - Disable Health Regen');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450438 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450438, 0, 0, 1, '', 75, 0, 100, 1, 0, 56730, 4, 1000, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 56730, 0, 0, 0, 'npc_fe_feng_brewthief_attack_3', 0, 0, 0, 0, 'Wu-Song Villager - On Creature Distance - Start Attacking'),
(-450438, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wu-Song Villager - On Linked - Disable Health Regen');

-- Fe-Feng Brewthief 4
SET @ENTRY := 56730;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to Wu-Song Villager 6');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1396.523, 3761.713, 84.58096, NULL, 0),
(@PATH, 1, 1403.3, 3744.214, 85.10693, NULL, 0);

UPDATE `creature` SET `position_x`= 1396.523, `position_y`= 3761.713, `position_z`= 84.58096, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450456;

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450456 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450456, 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673003, 0, 0, 0, 2, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On just created - Self: Start path #5673000, run, do not repeat, Aggresive'),
(-450456, 0, 1, 2, '', 58, 0, 100, 0, 1, 5673003, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 65472, 0, 0, 0, 'npc_wu_song_villager_attack_7', 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Start Attacking'),
(-450456, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Linked - Disable Health Regen');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450455 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450455, 0, 0, 1, '', 75, 0, 100, 1, 0, 56730, 2, 1000, 0, '', 49, 0, 0, 0, 0, 0, 0, 0, NULL, 19, 56730, 0, 0, 0, 'npc_fe_feng_brewthief_attack_4', 0, 0, 0, 0, 'Wu-Song Villager - On Creature Distance - Start Attacking'),
(-450455, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 102, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wu-Song Villager - On Linked - Disable Health Regen');

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=57617 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=57617 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=57617 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=57617 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=57617 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=57617 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=57617 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=57617 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(57617, 8, 3857, 0, 0, 1, 0, 0, 54070), -- Coal
(57617, 7, 18567, 0, 0, 1, 0, 0, 54070), -- Elemental Flux
(57617, 6, 160298, 0, 0, 1, 0, 0, 54070), -- Durable Flux
(57617, 5, 3466, 0, 0, 1, 0, 0, 54070), -- Strong Flux
(57617, 4, 2880, 0, 0, 1, 0, 0, 54070), -- Weak Flux
(57617, 3, 180733, 0, 0, 1, 0, 0, 54070), -- Luminous Flux
(57617, 2, 5956, 0, 0, 1, 0, 0, 54070), -- Blacksmith Hammer
(57617, 1, 2901, 0, 0, 1, 0, 0, 54070); -- Mining Pick

-- Quests
DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='esES' AND `ID` IN (29417,29522));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(29417, 'esES', '¡Luchas con soltura! ¡Creo que me caes bien!', 54205),
(29522, 'esES', '¡Hola! Rebosas aplomo y seguridad... ¡Me gusta!$b$bMe han llegado algunos rumores bastante impresionantes sobre ti desde los campos de entrenamiento. Si eres la mitad de capaz de lo que cuentan, ¡creo que tú y yo nos vamos a llevar muy bien!', 54205);

UPDATE `quest_template_locale` SET `LogDescription`='Habla con Ji Zarpa Ígnea en la Aldea Wu-Song.', `QuestDescription`='Otro de mis discípulos con más talento te espera en la Aldea Wu-Song, al noroeste. Su forma de pensar es distinta a la de Aysa, pero con sus diferencias se equilibran mutuamente.$b$bJi Zarpa Ígnea te enseñará a reunir las ofrendas para el espíritu del fuego. Confía en su sabiduría.', `VerifiedBuild`=54205 WHERE (`ID`=29522 AND `locale`='esES');
UPDATE `quest_template_locale` SET `LogTitle`='La filosofía huojin', `QuestDescription`='A esos monos rabiosos que arrasan nuestro pueblo los llamamos \"hozen\". Normalmente nos dejan en paz, pero como saben que va a pasar algo malo han venido a robar nuestros suministros.$b$bEn este tipo de situaciones es necesaria una respuesta contundente. ¡Esos monos se irán por la fuerza! El verdadero crimen sería no defender nuestro pueblo y a nuestros seres queridos. Esa es la filosofía huojin.', `VerifiedBuild`=54205 WHERE (`ID`=29417 AND `locale`='esES');

DELETE FROM `quest_template_addon` WHERE `ID`=29414;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29414, 0, 0, 0, 29424, 29522, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_template_addon` WHERE `ID`=29522;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29522, 0, 0, 0, 29414, 29417, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_template_addon` WHERE `ID`=29417;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29417, 0, 0, 0, 29522, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_template_addon` WHERE `ID`=29418;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29418, 0, 0, 0, 29417, 29420, -29418, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_template_addon` WHERE `ID`=29523;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29523, 0, 0, 0, 29417, 29420, -29418, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, '');

DELETE FROM `quest_template_addon` WHERE `ID`=29420;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(29420, 0, 0, 0, 29418, 29664, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=7749;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7749, 'SmartTrigger');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=7749;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 7749, 2, 0, 1, 0, 116219, 0, 0, 1, 0, 0, '', 'Areatrigger 7749 only triggers when player has not aura 116219'),
(22, 1, 7749, 2, 0, 47, 0, 29522, 2, 0, 0, 0, 0, '', 'Areatrigger 7749 only triggers when player has completed quest 29522');

DELETE FROM `smart_scripts` WHERE `entryorguid`=7749 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7749, 2, 0, 0, 46, 0, 100, 0, 7749, 0, 0, 0, 0, '', 86, 116219, 2, 19, 54568, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Cast Area Trigger Dummy Timer Aura A');

DELETE FROM `smart_scripts` WHERE `entryorguid`=54568 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(54568, 0, 0, 0, 31, 0, 100, 0, 116219, 0, 1000, 1000, 0, '', 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Ji Firepaw - On Spellhit Target - Talk');

-- Graveyards
DELETE FROM `graveyard_zone` WHERE `ID` IN (3295, 3297, 3299, 3301, 3303, 3305, 3307) AND `GhostZone`=5736;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(3295, 5736, 'The Wandering Isle, Starting Area GY'),
(3297, 5736, 'The Wandering Isle, Hot Springs GY'),
(3299, 5736, 'The Wandering Isle, Farm Area GY'),
(3301, 5736, 'The Wandering Isle, Temple Town GY'),
(3303, 5736, 'The Wandering Isle, Wind Area Town GY'),
(3305, 5736, 'The Wandering Isle, Staff Forest GY'),
(3307, 5736, 'The Wandering Isle, Bamboo Forest GY');
