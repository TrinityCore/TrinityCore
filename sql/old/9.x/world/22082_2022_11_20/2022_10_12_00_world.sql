--
--
-- Silverpine Forest
 
SET @CGUID := 395705;

-- 
-- Forsaken High Command

-- Detect: Quest Invis Zone 3
DELETE FROM `spell_area` WHERE `spell`=83989 AND `area`=5369 AND `quest_start`=26964 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83989, 5369, 26964, 27097, 0, 0, 2, 3, 66, 1);

DELETE FROM `spell_area` WHERE `spell`=83989 AND `area`=5369 AND `quest_start`=28568 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83989, 5369, 28568, 27097, 0, 0, 2, 3, 66, 1);

DELETE FROM `spell_area` WHERE `spell`=83989 AND `area`=5369 AND `quest_start`=27099 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83989, 5369, 27099, 27098, 0, 0, 2, 3, 64, 1);

--
-- Fenris Isle

DELETE FROM `phase_area` WHERE `AreaId`= 172 AND `PhaseId`= 266;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(172, 266, 'Silverpine Forest - Fenris Isle - No Escape');

DELETE FROM `phase_area` WHERE `AreaId`= 235 AND `PhaseId`= 266;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(235, 266, 'Silverpine Forest - Fenris Keep - No Escape');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=266 AND `SourceEntry`=172 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=27097 AND `ConditionValue2`=64 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 266, 172, 0, 0, 47, 0, 27097, 64, 0, 0, 0, 0, '', 'Fenris Isle - Add phase 266 - 27097 rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=266 AND `SourceEntry`=235 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=27097 AND `ConditionValue2`=64 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 266, 235, 0, 0, 47, 0, 27097, 64, 0, 0, 0, 0, '', 'Fenris Keep - Add phase 266 - 27097 rewarded');

-- Agatha (44951)
UPDATE `creature_template` SET `unit_class` = 2, `unit_flags` = 8, `VehicleId` = 1109, `HoverHeight` = 2.20000004768371582, `ScriptName` = 'npc_silverpine_agatha_fenris_isle' WHERE `entry` = 44951;

DELETE FROM `creature_template_addon` WHERE `entry` = 44951;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(44951, 0, 0, 0, 50331648, 1, 0, 0, 0, 0, 3, '85451');

DELETE FROM `creature_template_movement` WHERE `CreatureId`=44951;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(44951, 2, 1, 1, 0, 0, 0, NULL);

DELETE FROM `creature_text` WHERE `CreatureID` = 44951;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44951, 0, 0, 'Death is only the beginning.', 12, 0, 100, 0, 0, 0, 0, 45090, 5, ''),
(44951, 0, 1, 'Different master, same insatiable thirst for power.', 12, 0, 100, 0, 0, 0, 0, 45093, 5, ''),
(44951, 0, 2, 'Do you feel it, $n? The darkness surrounds us.', 12, 0, 100, 0, 0, 0, 0, 45097, 5, ''),
(44951, 0, 3, 'I long for the frozen wastes of Northrend.', 12, 0, 100, 0, 0, 0, 0, 45096, 5, ''),
(44951, 0, 4, 'I sense doom in your future, $n.', 12, 0, 100, 0, 0, 0, 0, 45094, 5, ''),
(44951, 0, 5, 'Life is meaningless. It is in the afterlife that we are truly tested.', 12, 0, 100, 0, 0, 0, 0, 45098, 5, ''),
(44951, 0, 6, 'The warmth of this place sickens me.', 12, 0, 100, 0, 0, 0, 0, 45095, 5, ''),
(44951, 0, 7, 'Through me the Banshee Queen sees all...', 12, 0, 100, 0, 0, 0, 0, 45099, 5, ''),
(44951, 0, 8, 'Waste no time, $n. We mustn\'t keep the Banshee Queen waiting.', 12, 0, 100, 0, 0, 0, 0, 45092, 5, ''),
(44951, 1, 0, 'Bow before your new master!', 14, 0, 100, 0, 0, 0, 0, 45114, 5, ''),
(44951, 1, 1, 'Rise and destroy our enemies!', 14, 0, 100, 0, 0, 0, 0, 45115, 5, ''),
(44951, 1, 2, 'Rise, $n! Become Forsaken!', 14, 0, 100, 0, 0, 0, 0, 45091, 5, ''),
(44951, 2, 0, 'This way, $n. We will take them by surprise.', 12, 0, 100, 1, 0, 0, 0, 45193, 5, ''),
(44951, 3, 0, 'Run...', 12, 0, 100, 457, 0, 0, 0, 45184, 5, ''),
(44951, 4, 0, 'RUN!', 12, 0, 100, 457, 0, 0, 0, 45185, 5, '');

DELETE FROM `waypoint_data` WHERE `id` = 449510;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(449510, 1, 978.75, 682.571, 74.9817, NULL, 1, 0, 0, 0, 0),
(449510, 2, 979.691, 672.536, 74.9817, NULL, 1, 0, 0, 0, 0),
(449510, 3, 984.573, 670.793, 75.4262, NULL, 1, 0, 0, 0, 0),
(449510, 4, 997.752, 671.819, 69.7039, NULL, 1, 0, 0, 0, 0),
(449510, 5, 998.248, 683.655, 70.2039, NULL, 1, 0, 0, 0, 0),
(449510, 6, 1012.42, 684.455, 65.1761, NULL, 1, 0, 0, 0, 0),
(449510, 7, 1011.69, 695.212, 60.9817, NULL, 1, 0, 0, 0, 0),
(449510, 8, 996.165, 694.927, 60.9817, NULL, 1, 0, 0, 0, 0),
(449510, 9, 995.677, 709.804, 60.9817, NULL, 1, 0, 0, 0, 0),
(449510, 10, 982.948, 711.526, 60.9817, NULL, 1, 0, 0, 0, 0),
(449510, 11, 983.938, 689.569, 60.2873, NULL, 1, 0, 0, 0, 0),
(449510, 12, 961.075, 688.958, 60.2873, NULL, 1, 0, 0, 0, 0),
(449510, 13, 933.366, 687.901, 70.0651, NULL, 1, 0, 0, 0, 0),
(449510, 14, 871.441, 700.913, 91.8428, NULL, 1, 1200, 0, 0, 0),
(449510, 15, 843.257, 730.168, 99.0837, NULL, 1, 0, 0, 0, 0),
(449510, 16, 891.191, 859.995, 99.0837, NULL, 1, 0, 0, 0, 0),
(449510, 17, 1167.72, 992.175, 99.0837, NULL, 1, 0, 0, 0, 0),
(449510, 18, 1343, 1029.57, 62.7226, NULL, 1, 0, 0, 0, 0),
(449510, 19, 1367.74, 1034.35, 54.1671, NULL, 1, 0, 0, 0, 0);

-- Bond of the Val'kyr
DELETE FROM `spell_script_names` WHERE `spell_id` = 83979 AND `ScriptName` = 'spell_silverpine_bond_of_the_valkyr';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83979, 'spell_silverpine_bond_of_the_valkyr');

DELETE FROM `spell_area` WHERE `spell`=83979 AND `area`=5369 AND `quest_start`=27097 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83979, 5369, 27097, 27099, 0, 0, 2, 3, 74, 11);

DELETE FROM `spell_area` WHERE `spell`=83979 AND `area`=130 AND `quest_start`=27097 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83979, 130, 27097, 27099, 0, 0, 2, 3, 74, 11);

DELETE FROM `spell_area` WHERE `spell`=83979 AND `area`=927 AND `quest_start`=27097 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83979, 927, 27097, 27099, 0, 0, 2, 3, 74, 11);

DELETE FROM `spell_area` WHERE `spell`=83979 AND `area`=1338 AND `quest_start`=27097 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83979, 1338, 27097, 27099, 0, 0, 2, 3, 74, 11);

DELETE FROM `spell_area` WHERE `spell`=83979 AND `area`=172 AND `quest_start`=27097 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83979, 172, 27097, 27099, 0, 0, 2, 3, 74, 11);

DELETE FROM `spell_area` WHERE `spell`=83979 AND `area`=235 AND `quest_start`=27097 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(83979, 235, 27097, 27099, 0, 0, 2, 3, 74, 11);

-- Agatha Broadcast
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83978 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44951 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 83978, 0, 0, 31, 0, 3, 44951, 0, 0, 0, 0, '', 'Agatha Broadcast - Target Agatha');

-- Notify Agatha
DELETE FROM `spell_script_names` WHERE `spell_id` = 83990 AND `ScriptName` = 'spell_silverpine_notify_agatha';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83990, 'spell_silverpine_notify_agatha');

-- Armoire Camera
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84111 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44951 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84111, 0, 0, 31, 0, 3, 44951, 0, 0, 0, 0, '', 'Armoire Camera - Agatha');

-- Reverse Cast Ride Vehicle
DELETE FROM `spell_script_names` WHERE `spell_id` = 84109 AND `ScriptName` = 'spell_gen_reverse_cast_target_to_caster_triggered';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84109, 'spell_gen_reverse_cast_target_to_caster_triggered');

-- Despawn All Summons
DELETE FROM `spell_script_names` WHERE `spell_id` = 84011 AND `ScriptName` = 'spell_gen_despawn_all_summons_owned_by_caster';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84011, 'spell_gen_despawn_all_summons_owned_by_caster');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84011 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44951 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84011, 0, 0, 31, 0, 3, 44951, 0, 0, 0, 0, '', 'Despawn All Summons - Target Agatha');

-- Hillsbrad Refugee (44954, 44966)
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_silverpine_hillsbrad_refugee' WHERE `entry` IN (44954, 44966);

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 44954;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES 
(44954, 1, 3346, 0, 0, 45745),
(44954, 2, 1906, 0, 0, 45745),
(44954, 3, 25587, 13604, 0, 45745),
(44954, 4, 3367, 0, 0, 45745),
(44954, 6, 2715, 0, 0, 45745),
(44954, 7, 2704, 0, 0, 45745),
(44954, 8, 2714, 0, 0, 45745);

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 44966;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`, `VerifiedBuild`) VALUES 
(44966, 1, 2714, 0, 0, 45745),
(44966, 2, 3367, 0, 0, 45745),
(44966, 3, 2704, 0, 0, 45745),
(44966, 4, 3351, 0, 0, 45745),
(44966, 6, 25587, 13604, 0, 45745),
(44966, 7, 3346, 0, 0, 45745),
(44966, 8, 1906, 0, 0, 45745);

UPDATE `creature` SET `equipment_id`=FLOOR(RAND()*(7-1+1)+1) WHERE `id` IN (44954, 44966);
UPDATE `creature` SET `MovementType` = 1, `wander_distance` = 5 WHERE `guid` IN (321951, 321953, 321550, 321551, 321549, 321766, 321771, 321765, 321773, 321827, 321828, 321829, 321952, 321824);
UPDATE `creature` SET `position_x` = 858.1942, `position_y` = 596.9427, `position_z` = 36.42773, `MovementType` = 2 WHERE `guid` IN (321553, 321554);
UPDATE `creature` SET `equipment_id`=8, `position_x`= 740.559, `position_y`= 704.448, `position_z`= 38.42833, `MovementType` = 2 WHERE `guid` = 321555;
UPDATE `creature` SET `position_x`= 714.8848, `position_y`= 681.1774, `position_z`= 44.46771, `MovementType` = 2 WHERE `guid` IN (321453, 321454);
UPDATE `creature` SET `equipment_id`=8, `position_x`= 948.477, `position_y`= 634.106, `position_z`= 53.4356, `MovementType` = 2 WHERE `guid`=321767;

DELETE FROM `creature_addon` WHERE `guid` IN (321775, 321826, 321825, 321778, 321776, 321774, 321777, 321772, 321769, 321768, 321770, 321641, 321638, 321639, 321637, 321636, 321831, 321830, 321767, 321553, 321453, 321555, 321640, 321955);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321775, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321826, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321825, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321778, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321776, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321774, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321777, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321772, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321769, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321768, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321770, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321641, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321638, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321639, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321637, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321636, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321831, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321830, 0, 0, 0, 0, 1, 333, 0, 0, 0, 0, ''),
(321767, 3217670, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(321553, 3215530, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(321453, 3214530, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(321555, 3215550, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(321640, 3216400, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(321955, 3219550, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

UPDATE `creature` SET `MovementType` = 2, `equipment_id`=8 WHERE `guid` = 321640;

DELETE FROM `waypoint_data` WHERE `id` = 3217670;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3217670, 1, 948.47700, 634.106, 53.43565, NULL, 0, 0, 0, 0, 0),
(3217670, 2, 939.64900, 640.635, 53.49473, NULL, 0, 0, 0, 0, 0),
(3217670, 3, 930.23400, 649.747, 53.70245, NULL, 0, 0, 0, 0, 0),
(3217670, 4, 917.99300, 663.144, 53.56036, NULL, 0, 0, 0, 0, 0),
(3217670, 5, 913.96000, 669.524, 53.58414, NULL, 0, 0, 0, 0, 0),
(3217670, 6, 917.99300, 663.144, 53.56036, NULL, 0, 0, 0, 0, 0),
(3217670, 7, 930.23400, 649.747, 53.70245, NULL, 0, 0, 0, 0, 0),
(3217670, 8, 939.64900, 640.635, 53.49473, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 3215550;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3215550, 1, 740.55900, 704.448, 38.42833, NULL, 0, 0, 0, 0, 0),
(3215550, 2, 745.78300, 692.319, 40.47646, NULL, 0, 0, 0, 0, 0),
(3215550, 3, 759.01400, 685.604, 43.82069, NULL, 0, 0, 0, 0, 0),
(3215550, 4, 771.75900, 685.523, 46.95479, NULL, 0, 0, 0, 0, 0),
(3215550, 5, 788.42200, 685.8, 50.57882, NULL, 0, 0, 0, 0, 0),
(3215550, 6, 800.55900, 686.811, 53.03011, NULL, 0, 0, 0, 0, 0),
(3215550, 7, 788.42200, 685.8, 50.57882, NULL, 0, 0, 0, 0, 0),
(3215550, 8, 771.75900, 685.523, 46.95479, NULL, 0, 0, 0, 0, 0),
(3215550, 9, 759.01400, 685.604, 43.82069, NULL, 0, 0, 0, 0, 0),
(3215550, 10, 745.78300, 692.319, 40.47646, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 3216400;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3216400, 1, 905.91100, 686.674, 53.33414, NULL, 0, 0, 0, 0, 0),
(3216400, 2, 882.71200, 688.306, 53.93879, NULL, 0, 0, 0, 0, 0),
(3216400, 3, 866.19800, 688.432, 53.63894, NULL, 0, 0, 0, 0, 0),
(3216400, 4, 854.57100, 687.913, 53.501, NULL, 0, 0, 0, 0, 0),
(3216400, 5, 844.26000, 688.267, 53.91982, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 3215530;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3215530, 1, 841.50570, 600.1945, 35.56526, NULL, 0, 0, 0, 0, 0),
(3215530, 2, 838.45000, 599.3725, 35.54626, NULL, 0, 0, 0, 0, 0),
(3215530, 3, 835.41430, 598.5559, 35.59277, NULL, 0, 0, 0, 0, 0),
(3215530, 4, 832.37110, 597.7373, 35.49213, NULL, 0, 0, 0, 0, 0),
(3215530, 5, 829.32790, 596.9186, 35.61664, NULL, 0, 0, 0, 0, 0),
(3215530, 6, 826.28470, 596.1, 35.65741, NULL, 0, 0, 0, 0, 0),
(3215530, 7, 823.27500, 595.2904, 35.87946, NULL, 0, 0, 0, 0, 0),
(3215530, 8, 820.24660, 594.4759, 35.95258, NULL, 0, 0, 0, 0, 0),
(3215530, 9, 817.23200, 593.6755, 36.37152, NULL, 0, 0, 0, 0, 0),
(3215530, 10, 814.20910, 592.8752, 35.93695, NULL, 0, 0, 0, 0, 0),
(3215530, 11, 811.83690, 592.5848, 35.60614, NULL, 0, 0, 0, 0, 0),
(3215530, 12, 808.84580, 592.3621, 35.08319, NULL, 0, 0, 0, 0, 0),
(3215530, 13, 805.95210, 592.1465, 34.5019, NULL, 0, 0, 0, 0, 0),
(3215530, 14, 802.83260, 591.9146, 34.22004, NULL, 0, 0, 0, 0, 0),
(3215530, 15, 799.79830, 591.6887, 33.82306, NULL, 0, 0, 0, 0, 0),
(3215530, 16, 796.78160, 591.4719, 33.94806, NULL, 0, 0, 0, 0, 0),
(3215530, 17, 797.64540, 590.9355, 33.94806, NULL, 0, 0, 0, 0, 0),
(3215530, 18, 796.24150, 593.6481, 33.82306, NULL, 0, 0, 0, 0, 0),
(3215530, 19, 794.83520, 596.3653, 34.00531, NULL, 0, 0, 0, 0, 0),
(3215530, 20, 793.48830, 598.9668, 34.32306, NULL, 0, 0, 0, 0, 0),
(3215530, 21, 792.03720, 601.7714, 34.46612, NULL, 0, 0, 0, 0, 0),
(3215530, 22, 790.64110, 604.4688, 34.79315, NULL, 0, 0, 0, 0, 0),
(3215530, 23, 789.25340, 607.1498, 35.6867, NULL, 0, 0, 0, 0, 0),
(3215530, 24, 787.88310, 609.7974, 36.21942, NULL, 0, 0, 0, 0, 0),
(3215530, 25, 786.55510, 612.3639, 37.14215, NULL, 0, 0, 0, 0, 0),
(3215530, 26, 785.42380, 614.7849, 37.99469, NULL, 0, 0, 0, 0, 0),
(3215530, 27, 784.28330, 617.4319, 39.02862, NULL, 0, 0, 0, 0, 0),
(3215530, 28, 783.13090, 620.1067, 39.98553, NULL, 0, 0, 0, 0, 0),
(3215530, 29, 782.00880, 622.709, 40.82306, NULL, 0, 0, 0, 0, 0),
(3215530, 30, 780.86520, 625.3652, 41.82306, NULL, 0, 0, 0, 0, 0),
(3215530, 31, 779.66050, 628.1616, 42.26825, NULL, 0, 0, 0, 0, 0),
(3215530, 32, 778.53030, 630.7832, 42.94806, NULL, 0, 0, 0, 0, 0),
(3215530, 33, 777.35160, 633.5176, 43.64753, NULL, 0, 0, 0, 0, 0),
(3215530, 34, 775.67800, 636.6871, 43.98749, NULL, 0, 0, 0, 0, 0),
(3215530, 35, 774.06190, 639.2108, 44.29035, NULL, 0, 0, 0, 0, 0),
(3215530, 36, 772.43020, 641.7588, 44.84626, NULL, 0, 0, 0, 0, 0),
(3215530, 37, 770.81570, 644.28, 45.2735, NULL, 0, 0, 0, 0, 0),
(3215530, 38, 769.19300, 646.814, 46.00788, NULL, 0, 0, 0, 0, 0),
(3215530, 39, 768.84110, 647.375, 46.14264, NULL, 0, 0, 0, 0, 0),
(3215530, 40, 770.99040, 644.0211, 45.38141, NULL, 0, 0, 0, 0, 0),
(3215530, 41, 771.54350, 643.1572, 45.10761, NULL, 0, 0, 0, 0, 0),
(3215530, 42, 773.17190, 640.6172, 44.39753, NULL, 0, 0, 0, 0, 0),
(3215530, 43, 774.74610, 638.1563, 44.14753, NULL, 0, 0, 0, 0, 0),
(3215530, 44, 776.45040, 635.4877, 43.84357, NULL, 0, 0, 0, 0, 0),
(3215530, 45, 777.82430, 632.4358, 43.35748, NULL, 0, 0, 0, 0, 0),
(3215530, 46, 779.02890, 629.6401, 42.68682, NULL, 0, 0, 0, 0, 0),
(3215530, 47, 780.20280, 626.9156, 42.05365, NULL, 0, 0, 0, 0, 0),
(3215530, 48, 781.32910, 624.3008, 41.57306, NULL, 0, 0, 0, 0, 0),
(3215530, 49, 782.50390, 621.5723, 40.44806, NULL, 0, 0, 0, 0, 0),
(3215530, 50, 783.67580, 618.8516, 39.57306, NULL, 0, 0, 0, 0, 0),
(3215530, 51, 784.81490, 616.2108, 38.48321, NULL, 0, 0, 0, 0, 0),
(3215530, 52, 785.96640, 613.5321, 37.56353, NULL, 0, 0, 0, 0, 0),
(3215530, 53, 787.17250, 611.1723, 36.67974, NULL, 0, 0, 0, 0, 0),
(3215530, 54, 788.5095, 608.5892, 35.94806, NULL, 0, 0, 0, 0, 0),
(3215530, 55, 789.8115, 606.0762, 35.07306, NULL, 0, 0, 0, 0, 0),
(3215530, 56, 791.2459, 603.3023, 34.5368, NULL, 0, 0, 0, 0, 0),
(3215530, 57, 792.6329, 600.6226, 34.39459, NULL, 0, 0, 0, 0, 0),
(3215530, 58, 794.0262, 597.9305, 34.10235, NULL, 0, 0, 0, 0, 0),
(3215530, 59, 795.4131, 595.251, 33.93597, NULL, 0, 0, 0, 0, 0),
(3215530, 60, 796.8153, 592.5414, 33.82306, NULL, 0, 0, 0, 0, 0),
(3215530, 61, 798.1349, 589.9899, 33.94806, NULL, 0, 0, 0, 0, 0),
(3215530, 62, 798.1393, 591.5784, 33.94806, NULL, 0, 0, 0, 0, 0),
(3215530, 63, 801.1903, 591.8059, 34.04853, NULL, 0, 0, 0, 0, 0),
(3215530, 64, 804.2335, 592.0325, 34.34101, NULL, 0, 0, 0, 0, 0),
(3215530, 65, 807.1543, 592.25, 34.7519, NULL, 0, 0, 0, 0, 0),
(3215530, 66, 810.1221, 592.4707, 35.2519, NULL, 0, 0, 0, 0, 0),
(3215530, 67, 813.3135, 592.7004, 35.77839, NULL, 0, 0, 0, 0, 0),
(3215530, 68, 815.2618, 593.1611, 36.03144, NULL, 0, 0, 0, 0, 0),
(3215530, 69, 818.2425, 593.9628, 36.25031, NULL, 0, 0, 0, 0, 0),
(3215530, 70, 821.2012, 594.7585, 35.88495, NULL, 0, 0, 0, 0, 0),
(3215530, 71, 824.1599, 595.5543, 35.84784, NULL, 0, 0, 0, 0, 0),
(3215530, 72, 827.1321, 596.3537, 35.62702, NULL, 0, 0, 0, 0, 0),
(3215530, 73, 830.1091, 597.152, 35.56025, NULL, 0, 0, 0, 0, 0),
(3215530, 74, 833.0894, 597.9483, 35.52741, NULL, 0, 0, 0, 0, 0),
(3215530, 75, 836.0379, 598.7361, 35.57116, NULL, 0, 0, 0, 0, 0),
(3215530, 76, 838.9864, 599.5238, 35.59252, NULL, 0, 0, 0, 0, 0),
(3215530, 77, 841.9667, 600.3201, 35.69026, NULL, 0, 0, 0, 0, 0),
(3215530, 78, 845.6719, 600.2321, 35.81526, NULL, 0, 0, 0, 0, 0),
(3215530, 79, 848.7002, 599.4366, 36.10705, NULL, 0, 0, 0, 0, 0),
(3215530, 80, 851.7286, 598.6411, 36.25195, NULL, 0, 0, 0, 0, 0),
(3215530, 81, 854.7719, 597.8417, 36.41051, NULL, 0, 0, 0, 0, 0),
(3215530, 82, 857.7952, 597.0475, 36.44018, NULL, 0, 0, 0, 0, 0),
(3215530, 83, 860.8261, 596.2514, 36.46984, NULL, 0, 0, 0, 0, 0),
(3215530, 84, 863.8983, 595.4442, 36.38854, NULL, 0, 0, 0, 0, 0),
(3215530, 85, 866.9508, 594.6372, 36.26096, NULL, 0, 0, 0, 0, 0),
(3215530, 86, 867.5857, 594.4694, 36.22068, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_formations` WHERE `MemberGUID` IN (321553, 321554);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(321553, 321553, 0, 0, 515, 0, 0),
(321553, 321554, 3.5, 270, 515, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 3214530;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3214530, 1, 714.88480, 681.1774, 44.46771, NULL, 0, 0, 0, 0, 0),
(3214530, 2, 717.74330, 682.2034, 44.48248, NULL, 0, 0, 0, 0, 0),
(3214530, 3, 720.59340, 683.2263, 44.70172, NULL, 0, 0, 0, 0, 0),
(3214530, 4, 723.46830, 684.2582, 44.54425, NULL, 0, 0, 0, 0, 0),
(3214530, 5, 726.32400, 685.2832, 44.32477, NULL, 0, 0, 0, 0, 0),
(3214530, 6, 729.14390, 686.298, 44.00629, NULL, 0, 0, 0, 0, 0),
(3214530, 7, 734.58500, 685.3998, 43.28798, NULL, 0, 0, 0, 0, 0),
(3214530, 8, 736.93120, 683.4936, 43.75307, NULL, 0, 0, 0, 0, 0),
(3214530, 9, 739.26430, 681.5978, 44.1067, NULL, 0, 0, 0, 0, 0),
(3214530, 10, 741.61210, 679.69, 44.56032, NULL, 0, 0, 0, 0, 0),
(3214530, 11, 743.95030, 677.79, 45.04994, NULL, 0, 0, 0, 0, 0),
(3214530, 12, 746.26970, 675.9054, 45.72853, NULL, 0, 0, 0, 0, 0),
(3214530, 13, 748.61940, 673.996, 46.50514, NULL, 0, 0, 0, 0, 0),
(3214530, 14, 750.40650, 668.7034, 47.54665, NULL, 0, 0, 0, 0, 0),
(3214530, 15, 749.76170, 665.7148, 47.60152, NULL, 0, 0, 0, 0, 0),
(3214530, 16, 749.12520, 662.6761, 47.43404, NULL, 0, 0, 0, 0, 0),
(3214530, 17, 748.48320, 659.6558, 47.07271, NULL, 0, 0, 0, 0, 0),
(3214530, 18, 747.84330, 656.6453, 46.90523, NULL, 0, 0, 0, 0, 0),
(3214530, 19, 746.04740, 652.9103, 46.85152, NULL, 0, 0, 0, 0, 0),
(3214530, 20, 743.60780, 650.9083, 46.72652, NULL, 0, 0, 0, 0, 0),
(3214530, 21, 741.16420, 648.9031, 46.60152, NULL, 0, 0, 0, 0, 0),
(3214530, 22, 738.72870, 646.9044, 46.43648, NULL, 0, 0, 0, 0, 0),
(3214530, 23, 736.29970, 644.9109, 46.26998, NULL, 0, 0, 0, 0, 0),
(3214530, 24, 733.85380, 642.9036, 46.10152, NULL, 0, 0, 0, 0, 0),
(3214530, 25, 731.40880, 640.8969, 45.90495, NULL, 0, 0, 0, 0, 0),
(3214530, 26, 728.98590, 638.9084, 45.97795, NULL, 0, 0, 0, 0, 0),
(3214530, 27, 726.52810, 636.8914, 45.78935, NULL, 0, 0, 0, 0, 0),
(3214530, 28, 722.84830, 634.614, 45.47282, NULL, 0, 0, 0, 0, 0),
(3214530, 29, 719.75810, 634.4147, 45.28484, NULL, 0, 0, 0, 0, 0),
(3214530, 30, 716.68370, 634.2162, 45.0435, NULL, 0, 0, 0, 0, 0),
(3214530, 31, 713.59940, 634.0171, 44.9185, NULL, 0, 0, 0, 0, 0),
(3214530, 32, 710.53800, 633.8194, 44.7935, NULL, 0, 0, 0, 0, 0),
(3214530, 33, 707.46080, 633.6207, 44.7935, NULL, 0, 0, 0, 0, 0),
(3214530, 34, 704.38590, 633.4221, 44.7935, NULL, 0, 0, 0, 0, 0),
(3214530, 35, 701.33890, 633.2253, 44.76194, NULL, 0, 0, 0, 0, 0),
(3214530, 36, 698.24140, 633.0253, 44.93248, NULL, 0, 0, 0, 0, 0),
(3214530, 37, 695.30730, 632.8235, 44.90843, NULL, 0, 0, 0, 0, 0),
(3214530, 38, 691.36740, 633.6268, 44.95145, NULL, 0, 0, 0, 0, 0),
(3214530, 39, 688.44740, 634.4315, 44.60099, NULL, 0, 0, 0, 0, 0),
(3214530, 40, 685.53250, 635.2348, 44.25126, NULL, 0, 0, 0, 0, 0),
(3214530, 41, 682.77150, 635.998, 43.79984, NULL, 0, 0, 0, 0, 0),
(3214530, 42, 679.76900, 636.8227, 43.31961, NULL, 0, 0, 0, 0, 0),
(3214530, 43, 736.01780, 684.2358, 43.59499, NULL, 0, 0, 0, 0, 0),
(3214530, 44, 738.36360, 682.3297, 44.15077, NULL, 0, 0, 0, 0, 0),
(3214530, 45, 740.70340, 680.4285, 44.31496, NULL, 0, 0, 0, 0, 0),
(3214530, 46, 743.05300, 678.5192, 44.78773, NULL, 0, 0, 0, 0, 0),
(3214530, 47, 745.38010, 676.6282, 45.46059, NULL, 0, 0, 0, 0, 0),
(3214530, 48, 747.70540, 674.7388, 46.21718, NULL, 0, 0, 0, 0, 0),
(3214530, 49, 750.65310, 669.8632, 47.43715, NULL, 0, 0, 0, 0, 0),
(3214530, 50, 750.00960, 666.8362, 47.72328, NULL, 0, 0, 0, 0, 0),
(3214530, 51, 749.37100, 663.8322, 47.46358, NULL, 0, 0, 0, 0, 0),
(3214530, 52, 748.73250, 660.8287, 47.13692, NULL, 0, 0, 0, 0, 0),
(3214530, 53, 748.09170, 657.814, 46.93502, NULL, 0, 0, 0, 0, 0),
(3214530, 54, 747.5231, 655.1613, 46.80977, NULL, 0, 0, 0, 0, 0),
(3214530, 55, 744.5469, 651.679, 46.7596, NULL, 0, 0, 0, 0, 0),
(3214530, 56, 742.0965, 649.6681, 46.72652, NULL, 0, 0, 0, 0, 0),
(3214530, 57, 739.6622, 647.6705, 46.54842, NULL, 0, 0, 0, 0, 0),
(3214530, 58, 737.2003, 645.6501, 46.37801, NULL, 0, 0, 0, 0, 0),
(3214530, 59, 734.7805, 643.6642, 46.10152, NULL, 0, 0, 0, 0, 0),
(3214530, 60, 732.3397, 641.6609, 45.92497, NULL, 0, 0, 0, 0, 0),
(3214530, 61, 729.8919, 639.652, 45.87224, NULL, 0, 0, 0, 0, 0),
(3214530, 62, 727.4529, 637.6503, 45.77544, NULL, 0, 0, 0, 0, 0),
(3214530, 63, 725.0307, 635.6624, 45.64275, NULL, 0, 0, 0, 0, 0),
(3214530, 64, 736.1111, 684.16, 43.61122, NULL, 0, 0, 0, 0, 0),
(3214530, 65, 738.4492, 682.2601, 44.14711, NULL, 0, 0, 0, 0, 0),
(3214530, 66, 740.7828, 680.3639, 44.33656, NULL, 0, 0, 0, 0, 0),
(3214530, 67, 743.1246, 678.461, 44.80898, NULL, 0, 0, 0, 0, 0),
(3214530, 68, 745.465, 676.5592, 45.49428, NULL, 0, 0, 0, 0, 0),
(3214530, 69, 747.6699, 674.7676, 46.24232, NULL, 0, 0, 0, 0, 0),
(3214530, 70, 750.6296, 669.7529, 47.44765, NULL, 0, 0, 0, 0, 0),
(3214530, 71, 749.9955, 666.7703, 47.72939, NULL, 0, 0, 0, 0, 0),
(3214530, 72, 749.3607, 663.7834, 47.46224, NULL, 0, 0, 0, 0, 0),
(3214530, 73, 748.7216, 660.7773, 47.13558, NULL, 0, 0, 0, 0, 0),
(3214530, 74, 748.0859, 657.787, 46.93428, NULL, 0, 0, 0, 0, 0),
(3214530, 75, 747.5204, 655.1494, 46.81099, NULL, 0, 0, 0, 0, 0),
(3214530, 76, 744.5404, 651.6736, 46.75887, NULL, 0, 0, 0, 0, 0),
(3214530, 77, 742.0898, 649.6627, 46.72652, NULL, 0, 0, 0, 0, 0),
(3214530, 78, 739.6493, 647.6599, 46.54696, NULL, 0, 0, 0, 0, 0),
(3214530, 79, 737.2234, 645.669, 46.38082, NULL, 0, 0, 0, 0, 0),
(3214530, 80, 734.7814, 643.6649, 46.10152, NULL, 0, 0, 0, 0, 0),
(3214530, 81, 732.3544, 641.673, 46.05022, NULL, 0, 0, 0, 0, 0),
(3214530, 82, 729.9125, 639.6689, 45.87285, NULL, 0, 0, 0, 0, 0),
(3214530, 83, 727.4672, 637.662, 45.77702, NULL, 0, 0, 0, 0, 0),
(3214530, 84, 725.0348, 635.6658, 45.64287, NULL, 0, 0, 0, 0, 0),
(3214530, 85, 660.1733, 649.8429, 39.05645, NULL, 0, 0, 0, 0, 0),
(3214530, 86, 661.1892, 652.7288, 38.83525, NULL, 0, 0, 0, 0, 0),
(3214530, 87, 662.196, 655.5893, 38.49187, NULL, 0, 0, 0, 0, 0),
(3214530, 88, 663.2006, 658.4437, 38.17107, NULL, 0, 0, 0, 0, 0),
(3214530, 89, 664.2139, 661.3227, 37.929, NULL, 0, 0, 0, 0, 0),
(3214530, 90, 665.2198, 664.1805, 37.58611, NULL, 0, 0, 0, 0, 0),
(3214530, 91, 668.9871, 668.0948, 37.51793, NULL, 0, 0, 0, 0, 0),
(3214530, 92, 671.8945, 668.7461, 37.91674, NULL, 0, 0, 0, 0, 0),
(3214530, 93, 674.8334, 669.4044, 38.48034, NULL, 0, 0, 0, 0, 0),
(3214530, 94, 677.7624, 670.0605, 38.88451, NULL, 0, 0, 0, 0, 0),
(3214530, 95, 680.7086, 670.7205, 39.48473, NULL, 0, 0, 0, 0, 0),
(3214530, 96, 681.6362, 669.6058, 39.83587, NULL, 0, 0, 0, 0, 0),
(3214530, 97, 684.3414, 669.4562, 40.32225, NULL, 0, 0, 0, 0, 0),
(3214530, 98, 687.2417, 669.6869, 40.64912, NULL, 0, 0, 0, 0, 0),
(3214530, 99, 692.5371, 673.3724, 40.79381, NULL, 0, 0, 0, 0, 0),
(3214530, 100, 694.9862, 674.0354, 40.92516, NULL, 0, 0, 0, 0, 0),
(3214530, 101, 697.8115, 675.0494, 41.49254, NULL, 0, 0, 0, 0, 0),
(3214530, 102, 700.592, 676.0474, 42.2348, NULL, 0, 0, 0, 0, 0),
(3214530, 103, 703.3599, 677.0409, 42.96649, NULL, 0, 0, 0, 0, 0),
(3214530, 104, 706.0352, 678.002, 43.46771, NULL, 0, 0, 0, 0, 0),
(3214530, 105, 708.9597, 679.0508, 43.80682, NULL, 0, 0, 0, 0, 0),
(3214530, 106, 711.829, 680.0806, 44.02753, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_formations` WHERE `MemberGUID` IN (321453, 321454);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(321453, 321453, 0, 0, 515, 0, 0),
(321453, 321454, 3.5, 270, 515, 0, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 321955;

DELETE FROM `waypoint_data` WHERE `id` = 3219550;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3219550, 1, 1109.07000, 716.198, 35.7871, NULL, 0, 0, 0, 0, 0),
(3219550, 2, 1094.38000, 714.918, 41.10038, NULL, 0, 0, 0, 0, 0),
(3219550, 3, 1078.26000, 716.108, 46.21903, NULL, 0, 0, 0, 0, 0),
(3219550, 4, 1057.98000, 721.387, 49.78899, NULL, 0, 0, 0, 0, 0),
(3219550, 5, 1078.26000, 716.108, 46.21903, NULL, 0, 0, 0, 0, 0),
(3219550, 6, 1094.38000, 714.918, 41.10038, NULL, 0, 0, 0, 0, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` = 321780;

DELETE FROM `creature_addon` WHERE `guid` = 321780;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(321780, 3217800, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `waypoint_data` WHERE `id` = 3217800;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3217800, 1, 966.373, 597.295, 53.6044, NULL, 0, 0, 0, 0, 0),
(3217800, 2, 969.602, 604.546, 53.6308, NULL, 0, 0, 0, 0, 0),
(3217800, 3, 974.849, 607.956, 53.6883, NULL, 0, 0, 0, 0, 0),
(3217800, 4, 977.878, 615.096, 53.9903, NULL, 0, 0, 0, 0, 0),
(3217800, 5, 978.026, 623.815, 53.9622, NULL, 0, 0, 0, 0, 0),
(3217800, 6, 975.686, 608.754, 53.7591, NULL, 0, 0, 0, 0, 0),
(3217800, 7, 968.572, 603.749, 53.6704, NULL, 0, 0, 0, 0, 0),
(3217800, 8, 965.196, 594.681, 53.5906, NULL, 0, 0, 0, 0, 0),
(3217800, 9, 964.486, 587.571, 53.5704, NULL, 0, 0, 0, 0, 0);

DELETE FROM `creature_formations` WHERE `MemberGUID` IN (321955, 321954);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(321955, 321955, 0, 0, 515, 0, 0),
(321955, 321954, 3.5, 270, 515, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` = 83997 AND `ScriptName` = 'spell_silverpine_forsaken_trooper_masterscript_fenris_isle';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83997, 'spell_silverpine_forsaken_trooper_masterscript_fenris_isle');

 -- Forsaken Trooper (44958, 44959, 44960, 44961, 44962, 44963, 44964, 44965)
UPDATE `creature_template` SET `ScriptName`= 'npc_silverpine_forsaken_trooper_fenris_isle' WHERE `entry` IN (44958, 44959, 44960, 44961, 44962, 44963, 44964, 44965);

DELETE FROM `creature_text` WHERE `CreatureID` IN (44958, 44959, 44960, 44961, 44962, 44963, 44964, 44965);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(44958, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44958, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44958, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44958, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44958, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, ''),
(44959, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44959, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44959, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44959, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44959, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, ''),
(44960, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44960, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44960, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44960, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44960, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, ''),
(44961, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44961, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44961, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44961, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44961, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, ''),
(44962, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44962, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44962, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44962, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44962, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, ''),
(44963, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44963, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44963, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44963, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44963, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, ''),
(44964, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44964, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44964, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44964, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44964, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, ''),
(44965, 0, 0, 'I am Forsaken.', 12, 0, 100, 16, 0, 0, 0, 45106, 0, ''),
(44965, 0, 1, 'For the glory of the Dark Lady!', 12, 0, 100, 16, 0, 0, 0, 45107, 0, ''),
(44965, 0, 2, 'Wha... What has happened?', 12, 0, 100, 16, 0, 0, 0, 45108, 0, ''),
(44965, 0, 3, 'I am eternal... I am death.', 12, 0, 100, 16, 0, 0, 0, 45109, 0, ''),
(44965, 0, 4, 'I LIVE!', 12, 0, 100, 16, 0, 0, 0, 45111, 0, '');

-- Worgen Sentry
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_worgen_sentry', `AIName` = '' WHERE `entry` = 44987;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+0, 44987, 0, 130, 235, '0', 0, 266, 0, -1, 0, 0, 985.293, 689.312, 59.4764, 3.19127, 120, 0, 0, 683, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+1, 44987, 0, 130, 235, '0', 0, 266, 0, -1, 0, 0, 979.146, 666.453, 60.9757, 6.27395, 120, 0, 0, 683, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+2, 44987, 0, 130, 235, '0', 0, 266, 0, -1, 0, 0, 999.823, 712.408, 60.9755, 3.14414, 120, 0, 0, 683, 0, 2, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+3, 44987, 0, 130, 235, '0', 0, 266, 0, -1, 0, 0, 1011.31, 695.133, 60.9755, 3.15591, 120, 0, 0, 683, 0, 0, 0, 0, 0, 0, 0, '', 45745),
(@CGUID+4, 44987, 0, 130, 235, '0', 0, 266, 0, -1, 0, 0, 996.279, 690.808, 69.7955, 0.163545, 120, 0, 0, 683, 0, 0, 0, 0, 0, 0, 0, '', 45745);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(@CGUID+0, 0, 0, 0, 0, 1, 27, 0, 0, 0, 0, ''),
(@CGUID+1, 3990930, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(@CGUID+2, 3990940, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(@CGUID+3, 0, 0, 0, 0, 1, 27, 0, 0, 0, 0, ''),
(@CGUID+4, 0, 0, 0, 0, 1, 27, 0, 0, 0, 0, '');

DELETE FROM `creature_text` WHERE `CreatureID` = 44987;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44987, 0, 0, 'Hurry, my lord! The enemy is upon us!', 14, 0, 100, 0, 0, 0, 0, 45128, 0, ''),
(44987, 0, 1, 'They come!', 14, 0, 100, 0, 0, 0, 0, 45127, 0, '');

DELETE FROM `waypoint_data` WHERE `id` = 3990940;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3990940, 0, 977.275, 711.484, 60.9751, NULL, 0, 0, 0, 0, 0),
(3990940, 1, 999.823, 712.408, 60.9755, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 3990930;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `move_type`, `delay`, `action`, `action_chance`, `wpguid`) VALUES 
(3990930, 0, 1001.85, 667.365, 60.9754, NULL, 0, 0, 0, 0, 0),
(3990930, 1, 979.146, 666.453, 60.9757, NULL, 0, 0, 0, 0, 0);

-- AreaTrigger 6230 (Fenris Keep)
DELETE FROM `areatrigger_scripts` WHERE `entry` = 6230;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(6230, 'at_silverpine_no_escape');

-- Fenris Keep Stalker
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_fenris_keep_stalker' WHERE `entry` = 45032;

DELETE FROM `creature` WHERE `guid` = @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+5, 45032, 0, 130, 235, '0', 0, 266, 0, -1, 0, 0, 978.801, 689.085, 74.8985, 0.021992, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 45745);

UPDATE `creature` SET `PhaseId` = 266 WHERE `id` = 45032;

-- General Trigger 11
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84114 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44951 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84114, 0, 0, 31, 0, 3, 44951, 0, 0, 0, 0, '', 'General Trigger 11 - Target Agatha');

-- Summon Fenris Actors
DELETE FROM `spell_script_names` WHERE `spell_id` = 84053 AND `ScriptName` = 'spell_silverpine_summon_fenris_keep_actors';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84053, 'spell_silverpine_summon_fenris_keep_actors');

-- Despawn All Summons
DELETE FROM `spell_script_names` WHERE `spell_id` = 84065 AND `ScriptName` = 'spell_gen_despawn_all_summons_owned_by_caster';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84065, 'spell_gen_despawn_all_summons_owned_by_caster');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44990 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 0, 31, 0, 3, 44990, 0, 0, 'Despawn All Summons - Target Bloodfang Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44989 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 1, 31, 0, 3, 44989, 0, 0, 'Despawn All Summons - Target Crowley Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44993 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 2, 31, 0, 3, 44993, 0, 0, 'Despawn All Summons - Target Phin Odelic Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=3 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44994 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 3, 31, 0, 3, 44994, 0, 0, 'Despawn All Summons - Target Bartolo Ginsetti Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=4 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44995 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 4, 31, 0, 3, 44995, 0, 0, 'Despawn All Summons - Target Loremaster Dibbs Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=5 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44996 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 5, 31, 0, 3, 44996, 0, 0, 'Despawn All Summons - Target Magistrate Henry Maleb Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=6 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44997 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 6, 31, 0, 3, 44997, 0, 0, 'Despawn All Summons - Target Caretaker Smithers Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=7 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45002 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 7, 31, 0, 3, 45002, 0, 0, 'Despawn All Summons - Target Sophia Zwoski Fenris');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84065 AND `SourceId`=0 AND `ElseGroup`=8 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45003 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 84065, 0, 8, 31, 0, 3, 45003, 0, 0, 'Despawn All Summons - Target Fenris Keep Camera');

-- Fenris Keep Camera
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_fenris_keep_camera', `VehicleID` = 1070 WHERE `entry` = 45003;

-- Lord Darius Crowley
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_crowley_bloodfang_fenris_keep' WHERE `entry` = 44989;

DELETE FROM `creature_text` WHERE `CreatureID` = 44989;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44989, 0, 0, 'The Forsaken have broken through your defenses, magistrate.', 12, 0, 100, 396, 0, 0, 0, 45161, 0, ''),
(44989, 1, 0, 'You are out of time.', 12, 0, 100, 274, 0, 0, 0, 45162, 0, ''),
(44989, 2, 0, 'A decision must be made!', 12, 0, 100, 5, 0, 0, 0, 45163, 0, ''),
(44989, 3, 0, 'Die in battle and be raised as a servant of the Forsaken or...', 12, 0, 100, 396, 0, 0, 0, 45164, 0, ''),
(44989, 4, 0, 'Drink in my blood and reborn as worgen, immune to the depravity of the Forsaken.', 12, 0, 100, 5, 0, 0, 0, 45165, 0, ''),
(44989, 5, 0, 'Help us destroy the Forsaken and retake Lordaeron for the Alliance!', 12, 0, 100, 5, 0, 0, 0, 45166, 0, '');

-- General Trigger 10
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84102 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44989 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84102, 0, 0, 31, 0, 3, 44989, 0, 0, 0, 0, '', 'General Trigger 10 - Target Lord Darius Crowley');

-- Armoire Camera
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=83763 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44989 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 83763, 0, 0, 31, 0, 3, 44989, 0, 0, 0, 0, '', 'Armoire Camera - Target Lord Darius Crowley');

-- Packleader Ivar Bloodfang
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_crowley_bloodfang_fenris_keep' WHERE `entry` = 44990;

-- Phin Odelic
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_generic_actor_fenris_keep' WHERE `entry` = 44993;

-- Bartolo Ginsetti
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_generic_actor_fenris_keep' WHERE `entry` = 44994;

-- Loremaster Dibbs
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_generic_actor_fenris_keep' WHERE `entry` = 44995;

-- Magistrate Henry Maleb
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_generic_actor_fenris_keep' WHERE `entry` = 44996;

DELETE FROM `creature_text` WHERE `CreatureID` = 44996;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(44996, 0, 0, 'We would rather die than be turned into worgen, but seeing as how even death provides no relief from the atrocities of this war...', 12, 0, 100, 1, 0, 0, 0, 45167, 0, ''),
(44996, 1, 0, 'We choose vengeance!', 12, 0, 100, 5, 0, 0, 0, 45168, 0, '');

-- Conversation Trigger 01
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84076 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44996 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84076, 0, 0, 31, 0, 3, 44996, 0, 0, 0, 0, '', 'Conversation Trigger 01 - Magistrate Henry Maleb');

-- Armoire Camera
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84103 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=44996 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84103, 0, 0, 31, 0, 3, 44996, 0, 0, 0, 0, '', 'Armoire Camera - Magistrate Henry Maleb');

-- Caretaker Smithers
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_generic_actor_fenris_keep' WHERE `entry` = 44997;

-- Sophia Zwoski
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_generic_actor_fenris_keep' WHERE `entry` = 45002;

--
-- Quests

UPDATE `quest_template_addon` SET `NextQuestId`=0 WHERE `ID`=27088;
