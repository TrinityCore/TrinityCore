--
--
-- Silverpine Forest

DELETE FROM `phase_area` WHERE `AreaId`=130 AND `PhaseId`=267;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(130, 267, 'Silverpine Forest during 27098');

DELETE FROM `phase_area` WHERE `AreaId`=5369 AND `PhaseId`=267;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(5369, 267, 'Forsaken High Command during 27098');

DELETE FROM `phase_area` WHERE `AreaId`=228 AND `PhaseId`=267;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(228, 267, 'The Sepulcher during 27098');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=267 AND `SourceEntry`=130 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=27098 AND `ConditionValue2`=8 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 267, 130, 0, 2, 47, 0, 27098, 8, 0, 0, 0, 0, '', 'Silverpine Forest - Add phase 267 - 27098 taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=267 AND `SourceEntry`=5369 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=27098 AND `ConditionValue2`=8 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 267, 5369, 0, 2, 47, 0, 27098, 8, 0, 0, 0, 0, '', 'Forsaken High Command - Add phase 267 - 27098 taken');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=267 AND `SourceEntry`=228 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=47 AND `ConditionTarget`=0 AND `ConditionValue1`=27098 AND `ConditionValue2`=8 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(26, 267, 228, 0, 2, 47, 0, 27098, 8, 0, 0, 0, 0, '', 'The Sepulcher - Add phase 267 - 27098 taken');

-- Lordaeron Area Aura
DELETE FROM `spell_area` WHERE `spell`=84189 AND `area`=130 AND `quest_start`=27099 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(84189, 130, 27099, 27098, 0, 0, 2, 3, 64, 11);

DELETE FROM `spell_area` WHERE `spell`=84189 AND `area`=5369 AND `quest_start`=27099 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(84189, 5369, 27099, 27098, 0, 0, 2, 3, 64, 11);

DELETE FROM `spell_area` WHERE `spell`=84189 AND `area`=228 AND `quest_start`=27099 AND `aura_spell`=0 AND `racemask`=0 AND `gender`=2;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES 
(84189, 228, 27099, 27098, 0, 0, 2, 3, 64, 11);

-- Lady Sylvanas Windrunner
UPDATE `creature` SET `ScriptName`='npc_silverpine_sylvanas_windrunner_high_command_sepulcher' WHERE `guid`=395637;

DELETE FROM `creature_template_addon` WHERE `entry`=45051;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(45051, 0, 0, 0, 0, 2, 0, 0, 0, 0, 5, '');

-- Forsaken Warhorse
UPDATE `creature_template` SET `VehicleId` = 1076, `ScriptName` = 'npc_silverpine_warhorse_player_lordaeron' WHERE `entry` = 45041;

DELETE FROM `creature_template_addon` WHERE `entry`=45041;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(45041, 0, 0, 0, 0, 1, 0, 0, 0, 0, 5, '');

-- Ride Sylvanas Horse
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84166 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45057 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84166, 0, 0, 31, 0, 3, 45057, 0, 0, 0, 0, '', 'Ride Sylvanas Horse - Target Forsaken Warhorse');

-- Forsaken Warhorse
UPDATE `creature_template` SET `VehicleId` = 1077, `ScriptName` = 'npc_silverpine_warhorse_sylvanas_lordaeron' WHERE `entry` = 45057;

DELETE FROM `creature_template_addon` WHERE `entry`=45057;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(45057, 0, 0, 0, 0, 1, 0, 0, 0, 0, 5, '');

DELETE FROM `waypoint_data` WHERE `id` = 450570;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(450570, 1, 1361.34, 1026.57, 52.7564, NULL, 0, 1, 0, 0, 0),
(450570, 2, 1341.41, 1015.48, 54.5546, NULL, 0, 1, 0, 0, 0),
(450570, 3, 1326.32, 1011.06, 54.5992, NULL, 0, 1, 0, 0, 0),
(450570, 4, 1310.18, 1039.85, 54.5992, NULL, 0, 1, 0, 0, 0),
(450570, 5, 1284.02, 1074.41, 53.3174, NULL, 0, 1, 0, 0, 0),
(450570, 6, 1271.46, 1090.13, 52.2455, NULL, 0, 1, 0, 0, 0),
(450570, 7, 1252.99, 1106.65, 51.4217, NULL, 0, 1, 0, 0, 0),
(450570, 8, 1222.99, 1130.19, 50.4758, NULL, 0, 1, 0, 0, 0),
(450570, 9, 1212.3, 1138.05, 50.4684, NULL, 0, 1, 0, 0, 0),
(450570, 10, 1202.34, 1144.84, 49.592, NULL, 0, 1, 0, 0, 0),
(450570, 11, 1177.26, 1162.18, 48.9129, NULL, 0, 1, 0, 0, 0),
(450570, 12, 1147.52, 1182.8, 48.2925, NULL, 0, 1, 0, 0, 0),
(450570, 13, 1113.01, 1204.53, 46.7171, NULL, 0, 1, 0, 0, 0),
(450570, 14, 1090.95, 1220.55, 46.3405, NULL, 0, 1, 0, 0, 0),
(450570, 15, 1069.73, 1242.65, 46.2058, NULL, 0, 1, 0, 0, 0),
(450570, 16, 1049.1, 1263.08, 46.0836, NULL, 0, 1, 0, 0, 0),
(450570, 17, 1020.5, 1286.14, 45.9548, NULL, 0, 1, 0, 0, 0),
(450570, 18, 998.104, 1299.97, 45.8613, NULL, 0, 1, 0, 0, 0),
(450570, 19, 962.071, 1322.14, 46.134, NULL, 0, 1, 0, 0, 0),
(450570, 20, 932.884, 1340.81, 47.1454, NULL, 0, 1, 0, 0, 0),
(450570, 21, 912.49, 1349.2, 48.3521, NULL, 0, 1, 0, 0, 0),
(450570, 22, 883.944, 1356.02, 51.5032, NULL, 0, 1, 0, 0, 0),
(450570, 23, 864.58, 1361.52, 54.6625, NULL, 0, 1, 0, 0, 0),
(450570, 24, 816.589, 1361.97, 56.856, NULL, 0, 1, 0, 0, 0),
(450570, 25, 796.295, 1362.45, 60.7326, NULL, 0, 1, 0, 0, 0),
(450570, 26, 768.406, 1362.56, 65.9252, NULL, 0, 1, 0, 0, 0),
(450570, 27, 738.898, 1360.21, 70.7869, NULL, 0, 1, 0, 0, 0),
(450570, 28, 719.656, 1352.28, 73.8382, NULL, 0, 1, 0, 0, 0),
(450570, 29, 711.545, 1347.76, 75.2224, NULL, 0, 1, 0, 0, 0),
(450570, 30, 699.997, 1335.61, 77.6982, NULL, 0, 1, 0, 0, 0),
(450570, 31, 685.394, 1323.57, 79.4473, NULL, 0, 1, 0, 0, 0),
(450570, 32, 667.123, 1311.57, 81.713, NULL, 0, 1, 0, 0, 0),
(450570, 33, 645.257, 1302.21, 84.9805, NULL, 0, 1, 0, 0, 0),
(450570, 34, 637.26, 1308.36, 84.6332, NULL, 0, 1, 0, 0, 0),
(450570, 35, 624.309, 1330.15, 84.646, NULL, 0, 1, 0, 0, 0),
(450570, 36, 610.8, 1356.02, 87.0058, NULL, 0, 1, 0, 0, 0),
(450570, 37, 596.417, 1387.09, 90.5174, NULL, 0, 1, 0, 0, 0),
(450570, 38, 583.141, 1415.35, 95.7118, NULL, 0, 1, 0, 0, 0),
(450570, 39, 572.297, 1434.98, 100.203, NULL, 0, 1, 0, 0, 0),
(450570, 40, 550.889, 1457.77, 106.652, NULL, 0, 1, 0, 0, 0),
(450570, 41, 532.182, 1475.22, 114.478, NULL, 0, 1, 0, 0, 0),
(450570, 42, 516.007, 1488.57, 121.406, NULL, 0, 1, 0, 0, 0),
(450570, 43, 505.278, 1507.11, 126.695, NULL, 0, 1, 0, 0, 0),
(450570, 44, 501.087, 1524.91, 128.901, NULL, 0, 1, 0, 0, 0);

-- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_sylvanas_lordaeron' WHERE `entry` = 45051;

DELETE FROM `creature_text` WHERE `CreatureID` = 45051;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(45051, 0, 0, 'I have not always been the Banshee Queen, $n.', 12, 0, 0, 274, 0, 20470, 0, 45201, 5, 'VO_QE_Sylvanas_Event01'),
(45051, 1, 0, 'And my people have not always been the Forsaken.', 12, 0, 0, 396, 0, 20471, 0, 45202, 5, 'VO_QE_Sylvanas_Event02'),
(45051, 2, 0, 'Long ago, this land comprised the northern kingdoms of Lordaeron, ruled by King Terenas Menethil.', 12, 0, 0, 396, 0, 20472, 0, 45203, 5, 'VO_QE_Sylvanas_Event03'),
(45051, 3, 0, 'Terenas had a son named Arthas.', 12, 0, 0, 396, 0, 20473, 0, 45204, 5, 'VO_QE_Sylvanas_Event04'),
(45051, 4, 0, 'Arthas... even saying his name makes my body quiver in rage.', 12, 0, 0, 396, 0, 20474, 0, 45205, 0, 'VO_QE_Sylvanas_Event05'),
(45051, 5, 0, 'This man-child, Arthas, took for himself a cursed blade known as Frostmourne.', 12, 0, 0, 396, 0, 20475, 0, 45206, 5, 'VO_QE_Sylvanas_Event06'),
(45051, 6, 0, 'Through Frostmourne, Arthas killed his own father and razed this land along with every living creature in it!', 12, 0, 0, 396, 0, 20476, 0, 45207, 5, 'VO_QE_Sylvanas_Event07'),
(45051, 7, 0, 'My own death came at the hands of Arthas when he and his armies sacked my homeland, Quel\'Thalas, and murdered my people.', 12, 0, 0, 1, 0, 20477, 0, 45208, 5, 'VO_QE_Sylvanas_Event08'),
(45051, 8, 0, 'In his vast cruelty, Arthas severed my spirit from my body and raised me as a banshee to serve in his Scourge army.', 12, 0, 0, 1, 0, 20478, 0, 45209, 5, 'VO_QE_Sylvanas_Event09'),
(45051, 9, 0, 'A similar fate befell all that would die to the Scourge war machine.', 12, 0, 0, 5, 0, 20479, 0, 45210, 5, 'VO_QE_Sylvanas_Event10'),
(45051, 10, 0, 'In death, they were reborn as mindless undead.', 12, 0, 0, 1, 0, 20480, 0, 45217, 5, 'VO_QE_Sylvanas_Event11'),
(45051, 11, 0, 'But Arthas was not invincible! With each passing day his power waned-his grip over the will of the damned loosening.', 12, 0, 0, 5, 0, 20481, 0, 45218, 5, 'VO_QE_Sylvanas_Event12'),
(45051, 12, 0, 'It was when Arthas was at his weakest that I struck!', 12, 0, 0, 22, 0, 20482, 0, 45219, 5, 'VO_QE_Sylvanas_Event13'),
(45051, 13, 0, 'And though the hour of his atonement had come, the worm managed to escape his fate, returning to the frozen wastes of Northrend.', 12, 0, 0, 1, 0, 20483, 0, 45220, 5, 'VO_QE_Sylvanas_Event14'),
(45051, 14, 0, 'With Arthas gone, so too was the control he held over the undead masses of Lordaeron. After recovering my body, I freed the remaining Scourage that were left behind.', 12, 0, 0, 1, 0, 20484, 0, 45221, 5, 'VO_QE_Sylvanas_Event15'),
(45051, 15, 0, 'From the cruelty and mercilessness of Arthas, the man who would be the Lich King, the Forsaken were born.', 12, 0, 0, 1, 0, 20485, 0, 45222, 5, 'VO_QE_Sylvanas_Event16'),
(45051, 16, 0, 'Our goal... Our sole purpose was to destroy the Lich King. We threw our lot in with the Horde and began our journey towards redemption.', 12, 0, 0, 1, 0, 20486, 0, 45223, 5, 'VO_QE_Sylvanas_Event17'),
(45051, 17, 0, 'Now the Lich King is dead and we have returned.', 12, 0, 0, 1, 0, 20487, 0, 45224, 5, 'VO_QE_Sylvanas_Event18'),
(45051, 18, 0, 'The people who called this land their home in life, do so in death as well.', 12, 0, 0, 1, 0, 20488, 0, 45225, 5, 'VO_QE_Sylvanas_Event19'),
(45051, 19, 0, 'But the Alliance does not recognize our rights. They claim this land is their own while attempting to invalidate the claims of the founders of this kingdom.', 12, 0, 0, 1, 0, 20489, 0, 45226, 5, 'VO_QE_Sylvanas_Event20'),
(45051, 20, 0, 'I will never allow it... Never!', 12, 0, 0, 274, 0, 20490, 0, 45227, 5, 'VO_QE_Sylvanas_Event21'),
(45051, 21, 0, 'Lordaeron belongs to the Forsaken - always and forever.', 12, 0, 0, 5, 0, 20491, 0, 45228, 5, 'VO_QE_Sylvanas_Event22');

-- Kill Me
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84180 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45051 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84180, 0, 0, 31, 0, 3, 45051, 0, 0, 0, 0, '', 'Kill Me - Target Lady Sylvanas Windrunner');

-- Worgen Renegade
DELETE FROM `creature_template_movement` WHERE `CreatureId`=44793;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES 
(44793, 1, 1, 0, 0, 0, 0, NULL);

-- Forsaken Trooper
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_forsaken_trooper' WHERE `entry` = 44792;

-- Orc Sea Orc
DELETE FROM `waypoint_data` WHERE `id` = 4494200;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(4494200, 1, 1002.19, 1305.97, 45.9039, NULL, 0, 0, 0, 0, 0),
(4494200, 2, 974.613, 1323.48, 45.6693, NULL, 0, 0, 0, 0, 0),
(4494200, 3, 941.259, 1342.61, 46.7854, NULL, 0, 0, 0, 0, 0),
(4494200, 4, 922.768, 1351.14, 47.8096, NULL, 0, 0, 0, 0, 0),
(4494200, 5, 895.555, 1361.47, 49.7753, NULL, 0, 0, 0, 0, 0),
(4494200, 6, 924.202, 1352.21, 47.7473, NULL, 0, 0, 0, 0, 0),
(4494200, 7, 946.228, 1340.19, 46.4945, NULL, 0, 0, 0, 0, 0),
(4494200, 8, 981.543, 1318.51, 45.6626, NULL, 0, 0, 0, 0, 0),
(4494200, 9, 1025.23, 1291.7, 45.9554, NULL, 0, 0, 0, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 4494201;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(4494201, 0, 1031.23, 1332.41, 37.9303, NULL, 0, 0, 0, 0, 0),
(4494201, 1, 1014.11, 1326.63, 41.121, NULL, 0, 0, 0, 0, 0),
(4494201, 2, 994.812, 1331.02, 45.0159, NULL, 0, 0, 0, 0, 0),
(4494201, 3, 963.834, 1335.98, 46.1114, NULL, 0, 0, 0, 0, 0),
(4494201, 4, 945.676, 1339.23, 46.4755, NULL, 0, 0, 0, 0, 0),
(4494201, 5, 923.799, 1350.95, 47.7382, NULL, 0, 0, 0, 0, 0),
(4494201, 6, 897.104, 1360.41, 49.5317, NULL, 0, 0, 0, 0, 0),
(4494201, 7, 865.078, 1363.33, 54.5691, NULL, 0, 0, 0, 0, 0),
(4494201, 8, 821.376, 1363.54, 56.3932, NULL, 0, 0, 0, 0, 0);

 -- Dreadguard (44911)
UPDATE `creature_template` SET `ScriptName` = 'npc_silverpine_dreadguard_lordaeron' WHERE `entry` = 44911;

DELETE FROM `creature_template_addon` WHERE `entry` = 44911;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(44911, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '18950');

-- Summon Lordaeron Actors
DELETE FROM `spell_script_names` WHERE `spell_id` = 84127 AND `ScriptName` = 'spell_silverpine_summon_lordaeron_actors';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(84127, 'spell_silverpine_summon_lordaeron_actors');

-- Despawn All Summons
DELETE FROM `spell_script_names` WHERE `spell_id` = 84173 AND `ScriptName` = 'spell_gen_despawn_all_summons_owned_by_caster';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84173, 'spell_gen_despawn_all_summons_owned_by_caster');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84173 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45051 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84173, 0, 0, 31, 0, 3, 45051, 0, 0, 0, 0, '', 'Despawn All Summons - Target Lady Sylvanas Windrunner');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84173 AND `SourceId`=0 AND `ElseGroup`=1 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45057 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84173, 0, 1, 31, 0, 3, 45057, 0, 0, 0, 0, '', 'Despawn All Summons - Target Forsaken Warhorse (Sylvanas)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=84173 AND `SourceId`=0 AND `ElseGroup`=2 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=45041 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 84173, 0, 2, 31, 0, 3, 45041, 0, 0, 0, 0, '', 'Despawn All Summons - Target Forsaken Warhorse (Player)');
