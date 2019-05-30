-- Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (46557, 46661, 46674);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(46557, 0, 0, 1, 0),
(46661, 0, 0, 1, 0),
(46674, 0, 0, 1, 0);

-- Spawns
SET @CGUID := 259631;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+45;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 46521, 1, 440, 980, 1, 169, 0, 0, 0, -8919.38, -2294.04, 9.048013, 1.797689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Samir's Camel
(@CGUID+1, 46532, 1, 440, 980, 1, 169, 0, 0, 0, -8939.34, -2274.2, 8.972433, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Adarrah's Camel
(@CGUID+2, 46524, 1, 440, 980, 1, 169, 0, 0, 0, -8917.41, -2282.13, 8.967353, 1.919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mack's Camel
(@CGUID+3, 46519, 1, 440, 980, 1, 169, 0, 0, 0, -8938.73, -2287.42, 9.057663, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Budd's Camel
(@CGUID+4, 46517, 1, 440, 980, 1, 169, 0, 0, 0, -8929.95, -2265.47, 8.960593, 1.396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Lady Humps
(@CGUID+5, 44833, 1, 440, 980, 1, 169, 0, 0, 0, -8920.7, -2261.42, 8.960933, 5.846853, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Adarrah
(@CGUID+6, 46516, 1, 440, 980, 1, 169, 0, 0, 0, -8929.7, -2285.64, 8.995103, 1.58825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Uldum Caravan Harness

-- Template Updates
UPDATE `creature_template` SET `VehicleId`= 1196 WHERE `entry`= 46521; -- Samir's Camel
UPDATE `creature_template` SET `VehicleId`= 1197 WHERE `entry`= 46524; -- Mack's Camel
UPDATE `creature_template` SET `VehicleId`= 1195 WHERE `entry`= 46519; -- Budd's Camel
UPDATE `creature_template` SET `VehicleId`= 1199 WHERE `entry`= 46516; -- Uldum Caravan Harness
UPDATE `creature_template` SET `npcflag`= 16777216 WHERE `entry`= 46517; -- Lady Humps
UPDATE `creature_template` SET `flags_extra`= 128, `VehicleId`= 1203, `ScriptName`= 'npc_uldum_uldum_camera_bunny_04' WHERE `entry`= 46557; -- Uldum Camera Bunny 04
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 46661; -- Beam Target Bunny
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 46674; -- Beam Target Bunny 02
UPDATE `creature_template` SET `VehicleId`= 1202 WHERE `entry`= 46543;
UPDATE `creature_template` SET `VehicleId`= 1201 WHERE `entry`= 46540;
UPDATE `creature_template` SET `VehicleId`= 1200 WHERE `entry`= 46538;
UPDATE `creature_template` SET `VehicleId`= 1198 WHERE `entry`= 46596;
UPDATE `creature_template` SET `VehicleId`= 1205 WHERE `entry`= 46546;
UPDATE `creature_template` SET `ScriptName`= 'npc_uldum_uldum_skarf', `VehicleId`= 1208 WHERE `entry`= 46679;

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (46521, 46524, 46519, 46516, 46517, 46546);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(46521, 46598, 1, 1),
(46524, 46598, 1, 1),
(46519, 46598, 1, 1),
(46516, 46598, 1, 1),
(46546, 46598, 1, 1),
(46517, 86750, 3, 1);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (46516, 46519, 46521, 46524);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
-- Uldum Caravan Harness
(46516, 46529, 4, 1, 'Uldum Caravan Harness - Kurzel', 8, 0), -- Uldum Caravan Harness - Kurzel
(46516, 46514, 3, 1, 'Uldum Caravan Harness - Domesticated Kodo', 8, 0), -- Uldum Caravan Harness - Domesticated Kodo
(46516, 46528, 2, 1, 'Uldum Caravan Harness - Tanzar', 8, 0), -- Uldum Caravan Harness - Tanzar
(46516, 46525, 0, 1, 'Uldum Caravan Harness - Turgore', 8, 0), -- Uldum Caravan Harness - Turgore
(46516, 46530, 5, 1, 'Uldum Caravan Harness - Harkor', 8, 0), -- Uldum Caravan Harness - Harkor
-- Budd's Camel
(46519, 46520, 0, 1, 'Budd\'s Camel - Budd', 8, 0), -- Budd's Camel - Budd
-- Samir's Camel
(46521, 46522, 0, 1, 'Samir\'s Camel - Samir', 8, 0), -- Samir's Camel - Samir
-- Mack's Camel
(46524, 46523, 0, 1, 'Mack\'s Camel - Mack', 8, 0); -- Mack's Camel - Mack

DELETE FROM `creature_template_addon` WHERE `entry` IN (46516, 46519, 46521, 46524, 46529, 46514, 46528, 46525, 46530, 46520, 46522, 46523, 46517, 44833, 46532);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(46517, 0, 1, 0, '80797 85549'),
-- (46519, 0, 1, 0, '80797'),
-- (46521, 0, 1, 0, '80797'),
-- (46524, 0, 1, 0, '80797'),
(46529, 0, 1, 0, '80797'),
(46514, 0, 1, 0, '80797'),
(46528, 0, 1, 0, '80797'),
(46525, 0, 1, 0, '80797'),
(46530, 0, 1, 0, '80797'),
(46520, 0, 1, 0, '80797'),
(46522, 0, 1, 0, '80797'),
(46523, 0, 1, 0, '80797'),
(44833, 0, 1, 0, '80797'),
-- (46516, 0, 1, 0, '80797'),
(46532, 0, 1, 0, '80797');

DELETE FROM `spell_area` WHERE `spell` IN (86749, 89270) AND `area`= 980;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(86749, 980, 27003, 27003, 0, 0, 2, 1, 1 | 8, 41),
(89270, 980, 27003, 27003, 0, 0, 2, 1, 8, 41);

DELETE FROM `conditions` WHERE `SourceEntry`= 86750 AND `SourceGroup`= 46517 AND `SourceTypeOrReferenceId`= 18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(18, 46517, 86750, 0, 0, 9, 0, 27003, 0, 0, 0, 0, '', 'Required quest active for spellclick');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (46596, 46538, 46540, 46543, 46557, 46679);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(46596, 46598, 1, 1),
(46538, 46598, 1, 1),
(46540, 46598, 1, 1),
(46543, 46598, 1, 1),
(46679, 46598, 1, 1);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (46543, 46540, 46538, 46596, 46679);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
-- Mack's Camel
(46543, 46542, 0, 0, 'Mack\'s Camel - Mack', 8, 180000), -- Mack's Camel - Mack
-- Samir's Camel
(46540, 46541, 0, 0, 'Samir\'s Camel - Samir', 8, 180000), -- Samir's Camel - Samir
 -- Budd's Camel
(46538, 46539, 0, 0, 'Budd\'s Camel - Budd', 8, 180000), -- Budd's Camel - Budd
 -- Uldum Caravan Harness
(46596, 46545, 5, 1, 'Uldum Caravan Harness - Harkor', 8, 0), -- Uldum Caravan Harness - Harkor
(46596, 46534, 4, 1, 'Uldum Caravan Harness - Domesticated Kodo', 8, 0), -- Uldum Caravan Harness - Domesticated Kodo
(46596, 46548, 3, 1, 'Uldum Caravan Harness - Kurzel', 8, 0), -- Uldum Caravan Harness - Kurzel
(46596, 46547, 2, 1, 'Uldum Caravan Harness - Tanzar', 8, 0), -- Uldum Caravan Harness - Tanzar
(46596, 46544, 0, 1, 'Uldum Caravan Harness - Turgore', 8, 0), -- Uldum Caravan Harness - Turgore
-- Skarf
(46679, 46680, 0, 1, 'Skarf - Sultan Oogah', 8, 0); -- Skarf - Sultan Oogah


UPDATE `spell_target_position` SET `Orientation`= 5.899213 WHERE `ID`= 86751;
UPDATE `spell_target_position` SET `Orientation`= 1.570796 WHERE `ID`= 86752;
UPDATE `spell_target_position` SET `Orientation`= 1.37881 WHERE `ID`= 86753;
UPDATE `spell_target_position` SET `Orientation`= 1.64061 WHERE `ID`= 86754;
UPDATE `spell_target_position` SET `Orientation`= 1.413717 WHERE `ID`= 86755;
UPDATE `spell_target_position` SET `Orientation`= 1.815142 WHERE `ID`= 86756;
UPDATE `spell_target_position` SET `Orientation`= 1.902409 WHERE `ID`= 86757;
UPDATE `spell_target_position` SET `Orientation`= 1.570796 WHERE `ID`= 86758;
UPDATE `spell_target_position` SET `Orientation`= 1.570796 WHERE `ID`= 86758;

DELETE FROM `spell_target_position` WHERE `ID` IN (87002, 86990, 86999);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(87002, 0, 1, -8968, -1746, 94.4533, 1.5708),
(86990, 0, 1, -8965, -1720, 94.4533, 1.5708),
(86999, 0, 1, -8956, -1735, 94.4533, 1.5708);

DELETE FROM `creature_text` WHERE `CreatureID` IN (46533, 46539, 46680, 46720, 46777);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(46533, 0, 0, 'No, no, silly $r...', 12, 0, 100, 11, 0, 0, 46688, 'Adarrah to Player'),
(46533, 1, 0, 'No one rides the Lady!', 12, 0, 100, 274, 0, 0, 46689, 'Adarrah to Player'),
(46539, 0, 0, 'Ahoy!', 12, 0, 100, 70, 0, 21174, 46715, 'Budd to Cloned Image'),
(46680, 0, 0, 'Attack!', 14, 0, 100, 53, 0, 18260, 46761, 'Sultan Oogah to Skarf'),
(46720, 0, 0, 'How many coconuts can we get for the ugly one?', 12, 0, 100, 396, 0, 18259, 46774, 'Pygmy Ambusher to Uldum Camera Bunny 04'),
(46777, 0, 0, 'THREE? He woulda paid five, easy... Dummy!', 12, 0, 100, 0, 0, 18259, 46839, 'Pygmy Ambusher to Pygmy Ambusher');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (41055, 45206) AND `ScriptName`= 'spell_gen_clone_weapon';
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_uldum_initialize_uldum_intro',
'spell_gen_reverse_cast_ride_vehicle',
'spell_gen_revserse_cast_mirror_image',
'spell_gen_mirror_image_aura',
'spell_uldum_player_summon_camera',
'spell_uldum_master_ping_all_actors',
'spell_uldum_master_summon_beam_target_02',
'spell_uldum_master_summon_skarf');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86748, 'spell_uldum_initialize_uldum_intro'),
(82721, 'spell_gen_reverse_cast_ride_vehicle'),
(82315, 'spell_gen_reverse_cast_ride_vehicle'),
(84301, 'spell_gen_reverse_cast_ride_vehicle'),
(84318, 'spell_gen_reverse_cast_ride_vehicle'),
(86783, 'spell_gen_revserse_cast_mirror_image'),
(86784, 'spell_gen_mirror_image_aura'),
(41055, 'spell_gen_clone_weapon'),
(45206, 'spell_gen_clone_weapon'),
(95747, 'spell_uldum_player_summon_camera'),
(86848, 'spell_uldum_master_ping_all_actors'),
(87010, 'spell_uldum_master_summon_skarf'),
(86960, 'spell_uldum_master_summon_beam_target_02');

DELETE FROM `conditions` WHERE `SourceEntry` IN (86784, 86815, 73448, 73449, 86944, 86943, 86970) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 7, 86784, 0, 0, 31, 0, 3, 46554, 0, 0, 0, '', 'Mirror Image Aura - Target Cloned Image'),
(13, 1, 86815, 0, 0, 31, 0, 3, 46557, 0, 0, 0, '', 'Ping Camera 00 - Target Uldum Camera Bunny 04'),
(13, 1, 73448, 0, 0, 31, 0, 3, 46596, 0, 0, 0, '', 'Chains of Bondage - Target Uldum Caravan Harness'),
(13, 1, 73449, 0, 0, 31, 0, 3, 46596, 0, 0, 0, '', 'Chains of Bondage - Target Uldum Caravan Harness'),
(13, 1, 86944, 0, 0, 31, 0, 3, 46661, 0, 0, 0, '', 'Ping Beam Target - Target Beam Target Bunny'),
(13, 1, 86943, 0, 0, 31, 0, 3, 46557, 0, 0, 0, '', 'Ping Camera 01 - Target Uldum Camera Dummy 04'),
(13, 1, 86970, 0, 0, 31, 0, 3, 46557, 0, 0, 0, '', 'Ping Camera 02 - Target Uldum Camera Dummy 04');

-- Spline Chains
DELETE FROM `script_spline_chain_waypoints` WHERE `entry` IN (46557, 46661, 46674);
INSERT INTO `script_spline_chain_waypoints` (`entry`, `chainId`, `splineId`, `wpId`, `x`, `y`, `z`) VALUES
(46557, 1, 0, 0, -8919,    -2272.5,  12.87063),
(46557, 1, 0, 1, -8922.04, -2274.03, 14.4508),
(46557, 1, 0, 2, -8915.17, -2282.37, 21.0023),
--
(46557, 1, 1, 0, -8915.17, -2282.37, 21.0023),
(46557, 1, 1, 1, -8921.55, -2291.59, 18.5897),
(46557, 1, 1, 2, -8928.08, -2291.1,  16.9801),
(46557, 1, 1, 3, -8932.17, -2279.79, 14.2697),
(46557, 1, 1, 4, -8933.72, -2263.06, 12.12),
--
(46557, 2, 0, 0, -8933.72, -2263.06, 12.12),
(46557, 2, 0, 1, -8928.93, -2256.39, 14.834),
(46557, 2, 0, 2, -8929.32, -2252.51, 22.9079),
--
(46557, 3, 0, 0, -8892.82, -1756.05, 270),
(46557, 3, 0, 1, -8893.39, -1756.05, 224.915),
(46557, 3, 0, 2, -8910.17, -1763.45, 174.896),
(46557, 3, 0, 3, -8927.54, -1768.3, 137.2482),
--
(46557, 4, 0, 0, -8927.54,  -1768.3,   137.2482),
(46557, 4, 0, 1, -8957.792, -1700.462, 114.447),
(46557, 4, 0, 2, -8966.18,  -1677.19,  106.987),
--
(46661, 1, 0, 0, -8954,    -2188,   10.96293),
(46661, 1, 0, 1, -8951.25, -2174.06, 17.2353),
(46661, 1, 0, 2, -8943.43, -2161.06, 54.8142),
--
(46674, 1, 0, 0, -8888,    -1631,    278.0833),
(46674, 1, 0, 1, -8889.82, -1654,    269.947),
(46674, 1, 0, 2, -8902.86, -1655.57, 245.528),
(46674, 1, 0, 3, -8937.08, -1666.77, 184.786),
(46674, 1, 0, 4, -8948.27, -1692.13, 129.785),
(46674, 1, 0, 5, -8954.04, -1717.66, 114.423),
(46674, 1, 0, 6, -8957.57, -1734.65, 110.775);

DELETE FROM `script_spline_chain_meta` WHERE `entry` IN (46557, 46661, 46674);
INSERT INTo `script_spline_chain_meta` (`entry`, `chainId`, `splineId`, `expectedDuration`, `msUntilNext`) VALUES
(46557, 1, 0, 6556, 6556),
(46557, 1, 1, 15828, 0),
(46557, 2, 0, 7047, 0),
(46557, 3, 0, 11685, 0),
(46557, 4, 0, 16567, 0),
(46661, 1, 0, 7008, 0),
(46674, 1, 0, 11627, 0);

-- Tempfix for invisibility auras breaking vehicle entering
-- Creature Budd's Camel 46519 SAI
SET @ENTRY := 46519;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 100, 100, 0, 0, 11, 80797, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 100 and 100 ms) - Self: Cast spell Generic Quest Invisibility 5 (80797) on Self // ");

-- Creature Samir's Camel 46521 SAI
SET @ENTRY := 46521;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 100, 100, 0, 0, 11, 80797, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 100 and 100 ms) - Self: Cast spell Generic Quest Invisibility 5 (80797) on Self // ");

-- Creature Mack's Camel 46524 SAI
SET @ENTRY := 46524;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 100, 100, 0, 0, 11, 80797, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 100 and 100 ms) - Self: Cast spell Generic Quest Invisibility 5 (80797) on Self // ");

-- Creature Lady Humps 46517 SAI
SET @ENTRY := 46517;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 73, 0, 100, 0, 0, 0, 0, 0, 134, 86748, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On spellclick - Invoker: Cast spell Initialize Uldum Intro (86748) to Action invoker // ");

-- ----------------------- INTRO EVENT

-- Creature Adarrah 46533 SAI
SET @ENTRY := 46533;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 86843, 0, 0, 0, 80, 4653300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4653300 // ");

-- TimedActionList  4653300 SAI
SET @ENTRY := 4653300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 400, 400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8926.04, -2263.39, 9.00172, 0, "When in combat and timer at the begining between 400 and 400 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8926.04, -2263.39, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 1, 900, 900, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 900 and 900 ms (and later repeats every 0 and 0 ms) - Owner/Summoner: Talk 0 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 3600, 3600, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3600 and 3600 ms (and later repeats every 0 and 0 ms) - Self: Talk 1 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 3600, 3600, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8936.73, -2274.35, 9.00295, 0, "When in combat and timer at the begining between 3600 and 3600 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8936.73, -2274.35, 9.00295, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 43671, 0, 0, 0, 0, 0, 19, 46546, 10, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2000 and 2000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Ride Vehicle (43671) on Closest alive creature Adarrah's Camel (46546) in 10 yards // ");

-- Creature Mack's Camel 46543 SAI
SET @ENTRY := 46543;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set active (are you sure?) // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4654300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4654300 // ");

-- TimedActionList  4654300 SAI
SET @ENTRY := 4654300;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 13400, 13400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8919.02, -2248.4, 9.00172, 0, "When in combat and timer at the begining between 13400 and 13400 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8919.02, -2248.4, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 1, 12000, 12000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8925.41, -2224.72, 9.00172, 0, "When in combat and timer at the begining between 12000 and 12000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8925.41, -2224.72, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 9700, 9700, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8935.07, -2190.94, 9.00184, 0, "When in combat and timer at the begining between 9700 and 9700 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8935.07, -2190.94, 9.00184, 0) (point id 0) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 16000, 16000, 0, 0, 11, 86999, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 16000 and 16000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Teleport Mack's Camel (86999) on Self // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 1, 3300, 3300, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8956.22, -1653.3, 94.5783, 0, "When in combat and timer at the begining between 3300 and 3300 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8956.22, -1653.3, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 20700, 20700, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8956.64, -1614.71, 94.5783, 0, "When in combat and timer at the begining between 20700 and 20700 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8956.64, -1614.71, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 9000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Eject All Passengers (50630) on Self // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 1, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Set run // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8907.16, -1644.48, 96.0539, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8907.16, -1644.48, 96.0539, 0) (point id 0) // ");

-- Creature Samir's Camel 46540 SAI
SET @ENTRY := 46540;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set active (are you sure?) // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4654000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4654000 // ");

-- TimedActionList  4654000 SAI
SET @ENTRY := 4654000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 13400, 13400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8923.14, -2255.77, 9.00172, 0, "When in combat and timer at the begining between 13400 and 13400 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8923.14, -2255.77, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 1, 14500, 14500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8927.98, -2228.35, 9.00172, 0, "When in combat and timer at the begining between 14500 and 14500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8927.98, -2228.35, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 11000, 11000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8930.85, -2208.77, 9.50172, 0, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8930.85, -2208.77, 9.50172, 0) (point id 0) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 10000, 10000, 0, 0, 11, 87001, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Teleport Samir's Camel (87001) on Self // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 1, 5700, 5700, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8957.25, -1653.6, 94.5783, 0, "When in combat and timer at the begining between 5700 and 5700 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8957.25, -1653.6, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 1, 23000, 23000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8956.91, -1622.85, 94.5783, 0, "When in combat and timer at the begining between 23000 and 23000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8956.91, -1622.85, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 1, 6600, 6600, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6600 and 6600 ms (and later repeats every 0 and 0 ms) - Self: Set run // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 1, 0, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Eject All Passengers (50630) on Self // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8889.91, -1617.43, 97.5189, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8889.91, -1617.43, 97.5189, 0) (point id 0) // ");

-- Creature Budd's Camel 46538 SAI
SET @ENTRY := 46538;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set active (are you sure?) // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4653800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4653800 // ");

-- TimedActionList  4653800 SAI
SET @ENTRY := 4653800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 21000, 21000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8933.07, -2249.24, 9.00172, 0, "When in combat and timer at the begining between 21000 and 21000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8933.07, -2249.24, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 14500, 14500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8937.89, -2211.88, 9.00196, 0, "When in combat and timer at the begining between 14500 and 14500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8937.89, -2211.88, 9.00196, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 16300, 16300, 0, 0, 11, 87002, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 16300 and 16300 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Teleport Budd's Camel (87002) on Self // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 3100, 3100, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8968.27, -1685.77, 94.57826, 0, "When in combat and timer at the begining between 3100 and 3100 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8968.27, -1685.77, 94.57826, 0) (point id 0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 14700, 14700, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8968.21, -1661.29, 94.57826, 0, "When in combat and timer at the begining between 14700 and 14700 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8968.21, -1661.29, 94.57826, 0) (point id 0) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8967.31, -1641.22, 94.57826, 0, "When in combat and timer at the begining between 7000 and 7000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8967.31, -1641.22, 94.57826, 0) (point id 0) // ");

-- Creature Adarrah's Camel 46546 SAI
SET @ENTRY := 46546;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set active (are you sure?) // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4654600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4654600 // ");

-- TimedActionList  4654600 SAI
SET @ENTRY := 4654600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 10500, 10500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8931.88, -2249.08, 9.00172, 0, "When in combat and timer at the begining between 10500 and 10500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8931.88, -2249.08, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8936.35, -2218.25, 9.00196, 0, "When in combat and timer at the begining between 9000 and 9000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8936.35, -2218.25, 9.00196, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 13400, 13400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8942.33, -2190.52, 9.00184, 0, "When in combat and timer at the begining between 13400 and 13400 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8942.33, -2190.52, 9.00184, 0) (point id 0) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 13500, 13500, 0, 0, 11, 86993, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 13500 and 13500 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Teleport Adarrah's Camel (86993) on Self // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 1, 8500, 8500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8977.74, -1644.23, 94.5783, 0, "When in combat and timer at the begining between 8500 and 8500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8977.74, -1644.23, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 1, 20700, 20700, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8976.28, -1612.19, 94.5783, 0, "When in combat and timer at the begining between 20700 and 20700 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8976.28, -1612.19, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 1, 9000, 9000, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 9000 and 9000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Eject All Passengers (50630) on Self // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 1, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Set run // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9044.94, -1613.99, 94.5525, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-9044.94, -1613.99, 94.5525, 0) (point id 0) // ");

-- Creature Lady Humps 46536 SAI
SET @ENTRY := 46536;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set active (are you sure?) // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4653600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4653600 // ");

-- TimedActionList  4653600 SAI
SET @ENTRY := 4653600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 13400, 13400, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8931.92, -2234.18, 9.00172, 0, "When in combat and timer at the begining between 13400 and 13400 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8931.92, -2234.18, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 1, 11000, 11000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8938.87, -2204.73, 9.00196, 0, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8938.87, -2204.73, 9.00196, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 12300, 12300, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8947.44, -2170.03, 9.00184, 0, "When in combat and timer at the begining between 12300 and 12300 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8947.44, -2170.03, 9.00184, 0) (point id 0) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 17300, 17300, 0, 0, 11, 86990, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 17300 and 17300 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Teleport Lady Humps (86990) on Self // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8966.77, -1637.49, 94.5783, 0, "When in combat and timer at the begining between 1000 and 1000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8966.77, -1637.49, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 1, 20000, 20000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8967.16, -1607.32, 94.5783, 0, "When in combat and timer at the begining between 20000 and 20000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8967.16, -1607.32, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 1, 19000, 19000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8997.21, -1550.94, 94.5783, 0, "When in combat and timer at the begining between 19000 and 19000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8997.21, -1550.94, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 1, 6600, 6600, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6600 and 6600 ms (and later repeats every 0 and 0 ms) - Self: Set run // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9030.65, -1549.04, 94.5783, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-9030.65, -1549.04, 94.5783, 0) (point id 0) // ");

-- Creature Cloned Image 46554 SAI
SET @ENTRY := 46554;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 2, 25, 0, 100, 0, 0, 0, 0, 0, 11, 86783, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Cast spell Reverse Cast Mirror Image (86783) on Self // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4655400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4655400 // ");

-- TimedActionList  4655400 SAI
SET @ENTRY := 4655400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 1000, 1000, 0, 0, 11, 95747, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1000 and 1000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Player Summon Camera (95747) on Self // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, 11, 86815, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Ping Camera 00 (86815) on Self // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 1300, 1300, 0, 0, 11, 86815, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1300 and 1300 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Ping Camera 00 (86815) on Self // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 140, 140, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 140 and 140 ms (and later repeats every 0 and 0 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to ONESHOT_NONE (0) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 1, 1200, 1200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 46533, 15, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Look at Creature Adarrah (46533) in 15 yd // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 1, 9800, 9800, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.94444, "When in combat and timer at the begining between 9800 and 9800 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 3.94444) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 1, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_QUESTION (6) // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 1, 6000, 6000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8922.09, -2270.6, 9.00212, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8922.09, -2270.6, 9.00212, 0) (point id 0) // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 1, 3600, 3600, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.24631, "When in combat and timer at the begining between 3600 and 3600 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 3.24631) // "),
(@ENTRY, 9, 9, 0, 0, 0, 100, 1, 4900, 4900, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4900 and 4900 ms (and later repeats every 0 and 0 ms) - Self: Set run // "),
(@ENTRY, 9, 10, 0, 0, 0, 100, 1, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8929.25, -2269.74, 9.00212, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8929.25, -2269.74, 9.00212, 0) (point id 0) // "),
(@ENTRY, 9, 11, 0, 0, 0, 100, 0, 1200, 1200, 0, 0, 11, 43671, 0, 0, 0, 0, 0, 11, 46596, 20, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1200 and 1200 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Ride Vehicle (43671) on Creature Uldum Caravan Harness (46596) in 20 yd // "),
(@ENTRY, 9, 12, 0, 0, 0, 100, 1, 3700, 3700, 0, 0, 11, 86815, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 3700 and 3700 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Ping Camera 00 (86815) on Self // ");

-- Creature Pack Mule 46537 SAI
SET @ENTRY := 46537;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Set active (are you sure?) // "),
(@ENTRY, 0, 2, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4653700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4653700 // ");

-- TimedActionList  4653700 SAI
SET @ENTRY := 4653700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 13500, 13500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8922.56, -2250.76, 9.00172, 0, "When in combat and timer at the begining between 13500 and 13500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8922.56, -2250.76, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 1, 10000, 10000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8927.56, -2229.44, 9.00172, 0, "When in combat and timer at the begining between 10000 and 10000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8927.56, -2229.44, 9.00172, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 8500, 8500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8934.89, -2199.31, 9.00184, 0, "When in combat and timer at the begining between 8500 and 8500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8934.89, -2199.31, 9.00184, 0) (point id 0) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 14700, 14700, 0, 0, 11, 86995, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 14700 and 14700 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Teleport Mule (86995) on Self // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 1, 8500, 8500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8960.52, -1665.42, 94.5783, 0, "When in combat and timer at the begining between 8500 and 8500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8960.52, -1665.42, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 1, 15800, 15800, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8960.71, -1616.34, 94.5783, 0, "When in combat and timer at the begining between 15800 and 15800 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8960.71, -1616.34, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 1, 10500, 10500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8961.9, -1565.36, 94.5783, 0, "When in combat and timer at the begining between 10500 and 10500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8961.9, -1565.36, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 1, 500, 500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8962.98, -1533.89, 94.5783, 0, "When in combat and timer at the begining between 500 and 500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8962.98, -1533.89, 94.5783, 0) (point id 0) // "),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 1400, 1400, 0, 0, 59, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 1400 and 1400 ms (and later repeats every 0 and 0 ms) - Self: Set run // "),
(@ENTRY, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8953.83, -1501.06, 94.5783, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8953.83, -1501.06, 94.5783, 0) (point id 0) // ");

-- Creature Uldum Caravan Harness 46596 SAI
SET @ENTRY := 46596;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On AI initialize - Self: Set walk // "),
(@ENTRY, 0, 1, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4659600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4659600 // ");

-- TimedActionList  4659600 SAI
SET @ENTRY := 4659600;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 17000, 17000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8935.14, -2234.49, 9.00222, 0, "When in combat and timer at the begining between 17000 and 17000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8935.14, -2234.49, 9.00222, 0) (point id 0) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 19500, 19500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8939.94, -2211.02, 9.00196, 0, "When in combat and timer at the begining between 19500 and 19500 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8939.94, -2211.02, 9.00196, 0) (point id 0) // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 1, 11000, 11000, 0, 0, 11, 86997, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 11000 and 11000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell Teleport Caravan (86997) on Self // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 1, 8000, 8000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -8966.66, -1627.04, 94.5783, 0, "When in combat and timer at the begining between 8000 and 8000 ms (and later repeats every 0 and 0 ms) - Self: Move to position (-8966.66, -1627.04, 94.5783, 0) (point id 0) // ");

-- Creature Budd 46539 SAI
SET @ENTRY := 46539;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 1, 86843, 0, 0, 0, 80, 4653900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Start timed action list id #4653900 // ");

-- TimedActionList  4653900 SAI
SET @ENTRY := 4653900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 1, 30400, 30400, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 30400 and 30400 ms (and later repeats every 0 and 0 ms) - Self: Talk 0 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 1, 2400, 2400, 0, 0, 5, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 2400 and 2400 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_CHEER(DNR) (4) // ");

-- Creature Harkor 46545 SAI
SET @ENTRY := 46545;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 86843, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Ping All Actors 00 (86843) hit  - Self: Set event phase to 2 // "),
(@ENTRY, 0, 1, 0, 60, 2, 100, 0, 6000, 6000, 17000, 17000, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 17000 and 17000 ms (for the first time, timer between 6000 and 6000 ms) - Self: Play emote ONESHOT_EAT_NOSHEATHE (92) // "),
(@ENTRY, 0, 2, 0, 60, 2, 100, 0, 16000, 16000, 17000, 17000, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 17000 and 17000 ms (for the first time, timer between 16000 and 16000 ms) - Self: Play emote ONESHOT_EAT_NOSHEATHE (92) // ");

-- Creature Beam Target Bunny 02 46674 SAI
SET @ENTRY := 46674;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 2400, 2400, 0, 0, 11, 86970, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2400 and 2400 ms) - Self: Cast spell Ping Camera 02 (86970) on Self // ");

