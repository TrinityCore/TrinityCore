SET @CGUID := 6005881;
SET @OGUID := 6002948;
SET @WORLD_SAFE_LOC_ID := 100099;
SET @SPAWN_GROUP := 328;

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLD_SAFE_LOC_ID + 0 AND @WORLD_SAFE_LOC_ID + 1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WORLD_SAFE_LOC_ID+0, 1672, 2770.8577, 6061.6104, -3.1084170, DEGREES(5.440911), 'Blade\'s Edge Arena (Legion) - Purple Team'),
(@WORLD_SAFE_LOC_ID+1, 1672, 2803.7612, 5945.7803, -3.0935593, DEGREES(2.2982829), 'Blade\'s Edge Arena (Legion) - Gold Team');

DELETE FROM `battleground_scripts` WHERE `MapId` = 1672 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(1672, 0, 'arena_blades_edge_legion'); -- Blade's Edge Arena

DELETE FROM `battleground_template` WHERE `ID` = 844;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(844, @WORLD_SAFE_LOC_ID+0, @WORLD_SAFE_LOC_ID+1, 0, 1, 'Blade\'s Edge Arena (Legion)');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 117659, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2773.859619140625, 6065.44091796875, -2.58116912841796875, 0.514784097671508789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Scorpid (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@CGUID+1, 117658, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2793.29541015625, 6027.94091796875, -4.04620695114135742, 5.408627510070800781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Rock Viper (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@CGUID+2, 117659, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2724.5849609375, 6002.72412109375, -1.74358296394348144, 6.000385761260986328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Scorpid (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@CGUID+3, 117659, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2778.191162109375, 5970.97216796875, -4.46185207366943359, 3.474638938903808593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Scorpid (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@CGUID+4, 117658, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2806.5029296875, 5946.08154296875, -3.09581923484802246, 3.247663736343383789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Rock Viper (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@CGUID+5, 115494, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2833.854248046875, 6044.1015625, 17.71433448791503906, 3.770940303802490234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- High King Maulgar (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+6, 117659, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2728.302001953125, 6003.59619140625, -2.61333441734313964, 1.871769309043884277, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163), -- Scorpid (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@CGUID+7, 119661, 1672, 8482, 8482, '0', '0', 0, 0, 0, 2171.42919921875, 6377.80810546875, 84.3413238525390625, 0.414297670125961303, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63163); -- Nether Drake (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+5, 0, 0, 0, 3, 0, 1, 0, 0, 2188, 0, 0, 0, ''), -- High King Maulgar
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''); -- Nether Drake

UPDATE `creature_template` SET `ScriptName` = 'npc_blades_edge_high_king_maulgar' WHERE `entry`=115494; -- High King Maulgar
UPDATE `creature_template` SET `unit_flags`=0x0, `unit_flags2`=0x4000800, `unit_flags3`=0x1000000 WHERE `entry`=119661; -- Nether Drake

DELETE FROM `creature_text` WHERE `CreatureID` = 115494;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadCastTextId`, `TextRange`, `comment`) VALUES
(115494, 0, 0, 'You bore me!', 12, 0, 100, 1, 0, 78035, 124391, 3, 'High King Maulgar'),
(115494, 0, 1, 'Get in there and fight, stop hiding!', 12, 0, 100, 1, 0, 78039, 124392, 3, 'High King Maulgar'),
(115494, 0, 2, 'All you weaklings do is run around!', 12, 0, 100, 1, 0, 78040, 124393, 3, 'High King Maulgar'),
(115494, 1, 0, 'Finish him!', 12, 0, 100, 1, 0, 78041, 124394, 3, 'High King Maulgar to player'),
(115494, 2, 0, 'Finish her!', 12, 0, 100, 1, 0, 78042, 124395, 3, 'High King Maulgar to player'),
(115494, 3, 0, 'Yes, yes!', 12, 0, 100, 1, 0, 78045, 124397, 3, 'High King Maulgar to player'),
(115494, 4, 0, 'Let the games... BEGIN!', 12, 0, 100, 1, 0, 78044, 124398, 3, 'High King Maulgar');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 184395, 1672, 8482, 8482, '0', '0', 0, 2947.501220703125, 5950.77001953125, 0.286495000123977661, 5.583495140075683593, 0, 0, -0.34275245666503906, 0.939425766468048095, 7200, 255, 1, 63163), -- Bonfire (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+1, 184396, 1672, 8482, 8482, '0', '0', 0, 2947.3310546875, 5949.99560546875, 38.14368820190429687, 2.154982566833496093, 0, 0, 0.880772590637207031, 0.473539501428604125, 7200, 255, 1, 63163), -- Bonfire (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+2, 265571, 1672, 8482, 8482, '0', '0', 0, 2776.37060546875, 6055.70166015625, -3.733994722366333, 2.21798110008239746, 0, 0, 0.895249366760253906, 0.445565462112426757, 7200, 255, 1, 63163), -- Door (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+3, 265569, 1672, 8482, 8482, '0', '0', 0, 2797.013916015625, 5953.52734375, -4.09923839569091796, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 7200, 255, 1, 63163), -- Door (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+4, 266083, 1672, 8482, 8482, '0', '0', 0, 2800.4658203125, 5997.59716796875, -8.07323837280273437, 2.262584209442138671, -0.00215911865234375, -0.01087379455566406, 0.904894828796386718, 0.425490826368331909, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers082 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+5, 266082, 1672, 8482, 8482, '0', '0', 0, 2840.24560546875, 6058.2109375, -5.21827173233032226, 3.939640045166015625, -0.00664281845092773, 0.008875846862792968, -0.92139530181884765, 0.388468563556671142, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers079 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+6, 266086, 1672, 8482, 8482, '0', '0', 0, 2785.341064453125, 5989.615234375, -6.23292875289916992, 2.262584209442138671, -0.00215911865234375, -0.01087379455566406, 0.904894828796386718, 0.425490826368331909, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers083 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+7, 266085, 1672, 8482, 8482, '0', '0', 0, 2870.6826171875, 6018.66943359375, -5.1286468505859375, 3.738955259323120117, -0.00572013854980468, 0.009496688842773437, -0.95567512512207031, 0.294214487075805664, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers080 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+8, 266084, 1672, 8482, 8482, '0', '0', 0, 2872.996337890625, 6018.84619140625, -5.12864494323730468, 3.754499435424804687, -0.00579404830932617, 0.009451866149902343, -0.95335960388183593, 0.30163314938545227, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers081 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+9, 266459, 1672, 8482, 8482, '0', '0', 0, 2794.473876953125, 5992.12841796875, -4.21862745285034179, 2.78618025779724121, 0.000728130340576171, -0.0110626220703125, 0.984186172485351562, 0.176789849996566772, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers089 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+10, 266458, 1672, 8482, 8482, '0', '0', 0, 2803.607666015625, 6006.0869140625, 3.44696664810180664, 2.262584209442138671, -0.00215911865234375, -0.01087379455566406, 0.904894828796386718, 0.425490826368331909, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers088 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+11, 266457, 1672, 8482, 8482, '0', '0', 0, 2818.75830078125, 6030.14697265625, -4.85922908782958984, 0.597361922264099121, -0.00949668884277343, -0.00572013854980468, 0.294214248657226562, 0.955675184726715087, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers084 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+12, 266463, 1672, 8482, 8482, '0', '0', 0, 2791.13232421875, 5987.50830078125, -9.83725547790527343, 2.281576395034790039, -0.00205612182617187, -0.01089382171630859, 0.908894538879394531, 0.416878670454025268, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers087 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+13, 266462, 1672, 8482, 8482, '0', '0', 0, 2816.47705078125, 6047.59716796875, -4.76898479461669921, 5.423169136047363281, -0.01089429855346679, 0.002056121826171875, -0.41687870025634765, 0.908894538879394531, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers086 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+14, 266461, 1672, 8482, 8482, '0', '0', 0, 2787.833740234375, 6056.595703125, -5.55760955810546875, 0.885311543941497802, -0.00857782363891601, -0.00702381134033203, 0.428288459777832031, 0.903574049472808837, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers085 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+15, 184395, 1672, 8482, 8482, '0', '0', 0, 2793.4306640625, 5836.51220703125, 0.271331578493118286, 3.881798982620239257, 0, 0, -0.93229007720947265, 0.3617115318775177, 7200, 255, 1, 63163), -- Bonfire (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+16, 266514, 1672, 8482, 8482, '0', '0', 0, 2788.75830078125, 5993.626953125, 3.44696664810180664, 2.262584209442138671, -0.00215911865234375, -0.01087379455566406, 0.904894828796386718, 0.425490826368331909, 7200, 255, 1, 63163), -- Doodad_StratholmeFloatingEmbers090 (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+17, 184396, 1672, 8482, 8482, '0', '0', 0, 2792.68505859375, 5836.7822265625, 38.1285247802734375, 0.453289836645126342, 0, 0, 0.224709510803222656, 0.974425792694091796, 7200, 255, 1, 63163), -- Bonfire (Area: Blade's Edge Arena - Difficulty: 0) CreateObject1
(@OGUID+18, 184663, 1672, 8482, 8482, '0', '0', 0, 2760.416748046875, 6037.50244140625, -3.35283970832824707, 4.834563255310058593, 0, 0, -0.66261959075927734, 0.748956084251403808, 360, 255, 1, 63163), -- Shadow Sight (Area: Blade's Edge Arena - Difficulty: 0) CreateObject2
(@OGUID+19, 184664, 1672, 8482, 8482, '0', '0', 0, 2815.5556640625, 5971.9619140625, -4.4591231346130371, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 360, 255, 1, 63163); -- Shadow Sight (Area: Blade's Edge Arena - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.53729951381683349, 0.8433915376663208, 0, 0), -- Bonfire
(@OGUID+1, 0, 0, -0.53729951381683349, 0.8433915376663208, 0, 0), -- Bonfire
(@OGUID+2, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Door
(@OGUID+3, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Door
(@OGUID+4, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers082
(@OGUID+5, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers079
(@OGUID+6, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers083
(@OGUID+7, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers080
(@OGUID+8, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers081
(@OGUID+9, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers089
(@OGUID+10, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers088
(@OGUID+11, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers084
(@OGUID+12, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers087
(@OGUID+13, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers086
(@OGUID+14, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers085
(@OGUID+15, 0, 0, 0.988361477851867675, -0.15212363004684448, 0, 0), -- Bonfire
(@OGUID+16, 0, 0, 0.906307816505432128, 0.422618210315704345, 0, 0), -- Doodad_StratholmeFloatingEmbers090
(@OGUID+17, 0, 0, 0.988361477851867675, -0.15212363004684448, 0, 0); -- Bonfire

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP, 'Blade\'s Edge Arena (Legion) - Shadow sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+18),
(@SPAWN_GROUP, 1, @OGUID+19);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` = @SPAWN_GROUP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63163 WHERE (`Entry`=115494 AND `DifficultyID`=0); -- 115494 (High King Maulgar) - Floating

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_blades_edge_arena_game_event');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(234033, 'spell_blades_edge_arena_game_event');

SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 119661;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 15.2539, 'Nether Drake - Cosmetic');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2059.413, 6334.735, -2.3675117, NULL, 0),
(@PATH, 1, 2137.5972, 6363.3384, 55.499084, NULL, 0),
(@PATH, 2, 2215.7812, 6391.942, 113.36568, NULL, 0),
(@PATH, 3, 2316.1042, 6390.921, 119.06386, NULL, 0),
(@PATH, 4, 2494.236, 6403.2007, 121.73211, NULL, 0),
(@PATH, 5, 2699.9548, 6261.1113, 128.2429, NULL, 0),
(@PATH, 6, 2816.322, 6127.936, 125.12247, NULL, 0),
(@PATH, 7, 3005.0781, 6042.907, 110.24812, NULL, 0),
(@PATH, 8, 3190.691, 5817.6885, 129.08238, NULL, 0),
(@PATH, 9, 3436.2656, 5690.382, 83.15675, NULL, 0),
(@PATH, 10, 3220.894, 5799.993, -8.201389, NULL, 0),
(@PATH, 11, 2986.9453, 6036.0176, 20.21007, NULL, 0),
(@PATH, 12, 2825.1484, 6087.107, 80.20109, NULL, 0),
(@PATH, 13, 2604.684, 6361.683, 105.1807, NULL, 0),
(@PATH, 14, 2355.5364, 6414.83, 92.65027, NULL, 0),
(@PATH, 15, 2181.5469, 6400.0312, 83.15675, NULL, 0);

UPDATE `creature` SET `position_x`=2059.413, `position_y`=6334.735, `position_z`=-2.3675117, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;
