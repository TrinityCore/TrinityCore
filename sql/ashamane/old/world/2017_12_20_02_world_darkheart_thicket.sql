ALTER TABLE `creature_template` CHANGE `femaleName` `femaleName` CHAR(200) CHARSET utf8 COLLATE utf8_general_ci NULL; 

SET @CGUID := 20549397;

DELETE FROM `areatrigger_template` WHERE `Id` IN (10693, 10665, 9482, 10343, 11353, 10727, 10771, 10253, 11266, 10424, 10725, 4744, 10193, 10154, 10152, 11023, 10377, 10714);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(10693, 0, 0, 6, 6, 0, 0, 0, 0, 22810),
(10665, 0, 0, 6, 6, 0, 0, 0, 0, 22810),
(9482, 0, 0, 15, 15, 0, 0, 0, 0, 22810),
(10343, 0, 6, 5, 5, 0, 0, 0, 0, 22810),
(11353, 4, 0, 8, 8, 4, 4, 0.3, 0.3, 22810),
(10727, 0, 0, 8, 8, 0, 0, 0, 0, 22810),
(10771, 0, 0, 50, 50, 0, 0, 0, 0, 22810),
(10253, 0, 0, 8, 8, 0, 0, 0, 0, 22810),
(11266, 0, 0, 6, 6, 0, 0, 0, 0, 22810),
(10424, 0, 4, 5, 5, 0, 0, 0, 0, 22810),
(10725, 0, 4, 2.25, 2.25, 0, 0, 0, 0, 22810),
(4744, 4, 0, 5, 5, 30, 30, 0.5, 0.5, 22810),
(10193, 0, 2, 6, 6, 0, 0, 0, 0, 22810),
(10154, 0, 2, 4, 4, 0, 0, 0, 0, 22810),
(10152, 0, 4, 4, 4, 0, 0, 0, 0, 22810),
(11023, 0, 0, 8, 8, 0, 0, 0, 0, 22810),
(10377, 0, 4, 2, 2, 0, 0, 0, 0, 22810),
(10714, 0, 0, 8, 8, 0, 0, 0, 0, 22810);


DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=6711 AND `AreaTriggerId`=10693) OR (`SpellMiscId`=5977 AND `AreaTriggerId`=10665) OR (`SpellMiscId`=4756 AND `AreaTriggerId`=9482) OR (`SpellMiscId`=8082 AND `AreaTriggerId`=10343) OR (`SpellMiscId`=6826 AND `AreaTriggerId`=11353) OR (`SpellMiscId`=6039 AND `AreaTriggerId`=10727) OR (`SpellMiscId`=5529 AND `AreaTriggerId`=10771) OR (`SpellMiscId`=5542 AND `AreaTriggerId`=10253) OR (`SpellMiscId`=6710 AND `AreaTriggerId`=11266) OR (`SpellMiscId`=5714 AND `AreaTriggerId`=10424) OR (`SpellMiscId`=6037 AND `AreaTriggerId`=10725) OR (`SpellMiscId`=983 AND `AreaTriggerId`=4744) OR (`SpellMiscId`=5486 AND `AreaTriggerId`=10193) OR (`SpellMiscId`=5445 AND `AreaTriggerId`=10154) OR (`SpellMiscId`=5443 AND `AreaTriggerId`=10152) OR (`SpellMiscId`=6351 AND `AreaTriggerId`=11023) OR (`SpellMiscId`=5670 AND `AreaTriggerId`=10377) OR (`SpellMiscId`=6027 AND `AreaTriggerId`=10714);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(6711, 10693, 0, 0, 0, 0, 0, 0, 20000, 22810), -- SpellId : 204062
(5977, 10665, 0, 0, 0, 0, 0, 0, 20000, 22810), -- SpellId : 204255
(4756, 9482, 0, 0, 0, 0, 0, 0, 6636, 22810), -- SpellId : 191034
(8082, 10343, 0, 2063, 0, 0, 34, 0, 20000, 22810), -- SpellId : 200289
(6826, 11353, 0, 0, 0, 0, 0, 0, 6000, 22810), -- SpellId : 210797
(6039, 10727, 0, 0, 0, 0, 0, 0, 1000, 22810), -- SpellId : 204596
(5529, 10771, 0, 0, 0, 0, 0, 0, 8000, 22810), -- SpellId : 199345
(5542, 10253, 0, 0, 0, 0, 0, 0, 30000, 22810), -- SpellId : 199458
(6710, 11266, 0, 0, 0, 0, 0, 0, 20000, 22810), -- SpellId : 203795
(5714, 10424, 0, 0, 0, 0, 0, 0, 2500, 22810), -- SpellId : 201226
(6037, 10725, 0, 0, 0, 0, 0, 0, 0, 22810), -- SpellId : 199067
(983, 4744, 0, 0, 0, 0, 0, 0, 8000, 22810), -- SpellId : 78675
(5486, 10193, 0, 1872, 0, 0, 22, 0, 30000, 22810), -- SpellId : 198915
(5445, 10154, 0, 1838, 0, 0, 34, 0, 300000, 22810), -- SpellId : 198402
(5443, 10152, 0, 0, 0, 0, 0, 0, 3000, 22810), -- SpellId : 198379
(6351, 11023, 0, 0, 0, 0, 0, 0, 1000, 22810), -- SpellId : 207684
(5670, 10377, 0, 0, 0, 0, 0, 0, 2000, 22810), -- SpellId : 200768
(6027, 10714, 0, 0, 0, 0, 0, 0, 1000, 22810); -- SpellId : 202137


DELETE FROM `conversation_actors` WHERE (`ConversationId`=1212 AND `ConversationActorId`=50759 AND `Idx`=0) OR (`ConversationId`=1212 AND `ConversationActorId`=50760 AND `Idx`=1) OR (`ConversationId`=1213 AND `ConversationActorId`=50759 AND `Idx`=0) OR (`ConversationId`=1213 AND `ConversationActorId`=50760 AND `Idx`=1) OR (`ConversationId`=1211 AND `ConversationActorId`=50759 AND `Idx`=0) OR (`ConversationId`=1211 AND `ConversationActorId`=50760 AND `Idx`=1);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(1212, 50759, 0, 22810),
(1212, 50760, 1, 22810),
(1213, 50759, 0, 22810),
(1213, 50760, 1, 22810),
(1211, 50759, 0, 22810),
(1211, 50760, 1, 22810);


DELETE FROM `conversation_actor_template` WHERE `Id` IN (50760, 50759);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(50760, 100652, 71689, 22810),
(50759, 99192, 71688, 22810);


DELETE FROM `conversation_line_template` WHERE `Id` IN (2872, 2871, 2870, 2875, 2874, 2873, 2868, 2867, 2866);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(2872, 15717, 585, 0, 0, 22810),
(2871, 9165, 580, 1, 0, 22810),
(2870, 0, 585, 0, 0, 22810),
(2875, 15308, 585, 0, 0, 22810),
(2874, 8749, 580, 1, 0, 22810),
(2873, 0, 585, 0, 0, 22810),
(2868, 14132, 585, 0, 0, 22810),
(2867, 9346, 580, 1, 0, 22810),
(2866, 0, 585, 0, 0, 22810);


DELETE FROM `conversation_template` WHERE `Id` IN (1213, 1212, 1211);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(1213, 2873, 1073819456, 22810),
(1212, 2870, 1073819392, 22810),
(1211, 2866, 1073819328, 22810);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+431;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 100403, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2882.958, 1952.354, 190.0834, 4.509956, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100403 (Area: -1 - Difficulty: Normal)
(@CGUID+1, 100403, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2881.493, 1967.554, 189.7887, 3.280079, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100403 (Area: -1 - Difficulty: Normal)
(@CGUID+2, 100403, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2908.128, 1982.531, 190.1481, 0.4744453, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100403 (Area: -1 - Difficulty: Normal)
(@CGUID+3, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3109.9, 1569.889, 137.5248, 3.714376, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+4, 100403, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2895.06, 1946.438, 189.8097, 4.811821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100403 (Area: -1 - Difficulty: Normal)
(@CGUID+5, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3108.496, 1573.388, 137.4828, 3.867326, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+6, 96512, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2859.063, 1921.377, 190.6622, 1.377103, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 96512 (Area: -1 - Difficulty: Normal) (Auras: 197709 - Bond cruel)
(@CGUID+7, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3108.844, 1577.576, 137.424, 5.483344, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+8, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3110.564, 1578.224, 137.3658, 0.04842249, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+9, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3102.131, 1579.425, 137.41, 2.722094, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+10, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3102.397, 1574.244, 137.4522, 2.213907, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+11, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3088.679, 1586.252, 137.587, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+12, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3115.825, 1564.488, 138.0849, 4.532831, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+13, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2958.673, 1960.155, 189.6238, 0.7492282, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+14, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3087.503, 1583.724, 137.3343, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+15, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3085.056, 1576.993, 137.8863, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+16, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2963.701, 1959.906, 189.8236, 3.152632, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+17, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3118.155, 1569.417, 137.6526, 4.532831, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+18, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2961.583, 1966.198, 189.5125, 3.117844, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+19, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3089.77, 1588.875, 137.7726, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+20, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2960.287, 1950.724, 189.8793, 2.627849, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+21, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2956.052, 1958.212, 189.563, 2.398188, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+22, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2963.713, 1963.063, 189.7199, 0.06594519, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+23, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2968.288, 1962.514, 190.0564, 2.664786, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+24, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3120.2, 1571.163, 137.7969, 4.532831, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+25, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3088.297, 1591.543, 138.126, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+26, 100539, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3000.36, 1656.205, 134.0776, 1.335526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100539 (Area: -1 - Difficulty: Normal)
(@CGUID+27, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2961.611, 1955.545, 189.75, 3.022137, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+28, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3120.472, 1567.993, 137.7795, 4.532831, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+29, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3091.898, 1591.854, 138.0612, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+30, 100539, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2997.318, 1652.007, 134.0901, 4.385022, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100539 (Area: -1 - Difficulty: Normal)
(@CGUID+31, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2959.804, 1963.969, 189.5805, 1.246617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+32, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2964.817, 1954.285, 189.9671, 1.246617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+33, 99365, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3009.3, 1644.073, 135.4039, 3.909997, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99365 (Area: -1 - Difficulty: Normal)
(@CGUID+34, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3117.85, 1566.415, 138.0575, 4.532831, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+35, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3087.867, 1574.368, 137.943, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+36, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3086.248, 1572.066, 137.8117, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+37, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3104.173, 1559.09, 138.134, 6.052779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+38, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3083.65, 1574.089, 137.8151, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+39, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3082.674, 1571.063, 137.7378, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+40, 100400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2951.719, 1961.016, 189.6053, 3.929565, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: -1 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+41, 73400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3174.952, 1831.892, 216.8842, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: -1 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+42, 100404, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2928.832, 1961.144, 189.8137, 1.247608, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100404 (Area: -1 - Difficulty: Normal) (Auras: )
(@CGUID+43, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3100.422, 1556.243, 137.9711, 6.052779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+44, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3087.169, 1564.246, 138.0223, 2.200978, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+45, 99200, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3009.663, 1481.958, 142.602, 1.071526, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99200 (Area: -1 - Difficulty: Normal) (Auras: )
(@CGUID+46, 100526, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2995.649, 1622.286, 109.7756, 3.356502, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100526 (Area: -1 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+47, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3087.773, 1555.892, 138.1989, 5.070559, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+48, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3086.432, 1558.495, 138.3867, 5.976762, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+49, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3078.604, 1561.873, 138.321, 5.75685, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+50, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3078.154, 1560.009, 138.3583, 0.5388148, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+51, 100526, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2989.972, 1624.653, 109.8042, 3.776182, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100526 (Area: -1 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+52, 99358, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2896.916, 1764.708, 153.8823, 0.2890956, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 99358 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+53, 99360, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2898.181, 1768.916, 153.5993, 0.08995268, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+54, 99360, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2898.149, 1761.878, 153.2774, 0.07624759, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+55, 100404, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2898.939, 1934.929, 190.2736, 3.308647, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100404 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+56, 100404, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2916.074, 1993.612, 189.9109, 5.730954, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100404 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+57, 102851, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2896.708, 1967.349, 189.1411, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 102851 (Area: -1 - Difficulty: Normal) (Auras: 203257 - Bouclier géant)
(@CGUID+58, 111221, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2908.59, 1966.587, 189.7902, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111221 (Area: -1 - Difficulty: Normal)
(@CGUID+59, 107638, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2914.628, 1968.67, 189.7902, 5.975735, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 107638 (Area: -1 - Difficulty: Normal)
(@CGUID+60, 99365, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2951.103, 1662.918, 124.0966, 4.217285, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99365 (Area: -1 - Difficulty: Normal)
(@CGUID+61, 73400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3168.58, 1862.145, 215.4202, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: -1 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+62, 100527, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2955.58, 1657.672, 123.7201, 0.1995347, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100527 (Area: -1 - Difficulty: Normal) (Auras: 191262 - Apparition de diablotin du Cauchemar)
(@CGUID+63, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3106.97, 1591.071, 137.424, 0.8829675, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+64, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3112.255, 1590.321, 137.424, 1.738964, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+65, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3122.154, 1585.217, 137.8455, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+66, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3121.532, 1591.474, 137.4616, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+67, 100529, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3109.326, 1585.475, 137.424, 5.114347, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+68, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3119.935, 1586.495, 137.3857, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+69, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3121.832, 1582.323, 137.6193, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+70, 100533, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3121.754, 1587.655, 137.7031, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: -1 - Difficulty: Normal)
(@CGUID+71, 73400, 1466, 0, 0, 8388870, '0', 0, 0, 0, 3163.82, 1904.309, 213.9938, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: -1 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+72, 100404, 1466, 0, 0, 8388870, '0', 0, 0, 0, 2882.648, 1937.752, 190.0144, 2.628406, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100404 (Area: -1 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+73, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3163.87, 1908.768, 213.7698, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+74, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3203.931, 1942.997, 216.3562, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+75, 100529, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3092.247, 1675.18, 140.9436, 1.013957, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+76, 100529, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3088.969, 1675.732, 140.9303, 1.105636, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+77, 100529, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3081.721, 1676.233, 141.5413, 5.978162, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+78, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3207.954, 1940.582, 216.4077, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+79, 100529, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3085.708, 1686.651, 141.9539, 0.9037932, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+80, 100529, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3077.739, 1687.698, 141.8683, 5.780073, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+81, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3175.585, 1973.183, 215.5422, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+82, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3179.792, 1973.023, 215.6557, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+83, 100404, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2864.957, 1959.46, 189.6006, 1.739098, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100404 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: )
(@CGUID+84, 100529, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3085.787, 1680.056, 141.6183, 3.275201, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+85, 100529, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3092.446, 1677.553, 141.2361, 3.341836, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+86, 100529, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3098.316, 1671.984, 140.7017, 3.762396, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+87, 100529, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3087.721, 1672.113, 140.7433, 1.101293, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+88, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3120.57, 1964.676, 205.9837, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+89, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3121.564, 1963.451, 205.8374, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+90, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3120.089, 1962.015, 205.8224, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+91, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3078.492, 1941.738, 205.3025, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+92, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2787.212, 1956.325, 185.6815, 2.446836, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+93, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2781.825, 1947.805, 184.7349, 6.279223, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+94, 99358, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2780.84, 1941.295, 184.6099, 1.792763, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 99358 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+95, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 3087.765, 1945.311, 205.0211, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+96, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2771.946, 1899.064, 185.6885, 0.895741, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+97, 99359, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2765.356, 1900.16, 185.7913, 5.404621, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99359 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: )
(@CGUID+98, 99358, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2754.616, 1906.507, 185.5144, 0.1550746, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 99358 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+99, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2761.681, 1890.607, 185.9906, 5.803561, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+100, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2987.388, 1957.624, 193.9498, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+101, 99359, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2769.415, 1822.026, 185.2615, 2.830894, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99359 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: )
(@CGUID+102, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2777.419, 1814.643, 185.9334, 5.082772, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres)
(@CGUID+103, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2769.667, 1829.691, 185.0381, 2.322982, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres)
(@CGUID+104, 99359, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2765.34, 1817.193, 185.5163, 0.7931123, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99359 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: )
(@CGUID+105, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2756.272, 1824.183, 185.1018, 3.566923, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: )
(@CGUID+106, 99358, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2750.798, 1819.196, 185.1018, 3.35236, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99358 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: )
(@CGUID+107, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2754.995, 1816.55, 185.1018, 3.415394, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: )
(@CGUID+108, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2958.583, 1961.391, 189.6167, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+109, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2705.961, 1812.414, 185.4642, 3.073888, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+110, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2709.269, 1803.216, 185.8898, 6.278925, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+111, 99360, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2698.074, 1815.118, 185.8461, 5.909861, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+112, 73400, 1466, 7673, 8100, 8388870, '0', 0, 0, 0, 2952.948, 1964.818, 189.6117, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: La grotte Pourrissante - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+113, 99360, 1466, 7673, 8099, 8388870, '0', 0, 0, 0, 2694.091, 1807.451, 185.5526, 3.019474, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- Floraison vileronce (Area: Sanctum de G’Hanir - Difficulty: Normal) (Auras: 200760 - Racines terrestres) (possible waypoints or random movement)
(@CGUID+114, 100400, 1466, 7673, 8099, 8388870, '0', 0, 0, 0, 2700.714, 1805.337, 185.8153, 5.516175, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Sanctum de G’Hanir - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+115, 73400, 1466, 7673, 8099, 8388870, '0', 0, 0, 0, 2881.816, 1962.166, 189.7887, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Sanctum de G’Hanir - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+116, 73400, 1466, 7673, 8099, 8388870, '0', 0, 0, 0, 2892.91, 1958.601, 189.7454, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Sanctum de G’Hanir - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+117, 73400, 1466, 7673, 8099, 8388870, '0', 0, 0, 0, 2884.085, 1960.045, 189.7914, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Sanctum de G’Hanir - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+118, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2786.677, 1949.94, 185.5566, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+119, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2763.537, 1906.881, 185.5081, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+120, 95772, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3107.857, 1992.535, 205.1597, 3.665263, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95772 (Area: 0 - Difficulty: Normal) (Auras: 195110 -)
(@CGUID+121, 95779, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3078.632, 1902.665, 205.8631, 6.198259, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95779 (Area: 0 - Difficulty: Normal)
(@CGUID+122, 95779, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3112.066, 1913.644, 205.9944, 1.891584, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95779 (Area: 0 - Difficulty: Normal)
(@CGUID+123, 95771, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3104.273, 1989.88, 205.6337, 0.7102805, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Dévastateur âmeffroi (Area: 0 - Difficulty: Normal) (Auras: 195110 -)
(@CGUID+124, 95772, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3122.917, 1956.771, 205.7463, 5.865149, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95772 (Area: 0 - Difficulty: Normal) (Auras: 195110 -)
(@CGUID+125, 95779, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3067.062, 1907.899, 206.1484, 1.197031, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95779 (Area: 0 - Difficulty: Normal)
(@CGUID+126, 95772, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3149.047, 2029.051, 204.6437, 4.00141, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 95772 (Area: 0 - Difficulty: Normal) (Auras: 195110 -) (possible waypoints or random movement)
(@CGUID+127, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3068.618, 1916.868, 205.6707, 5.609585, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+128, 95772, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3143.59, 2033.548, 204.6437, 4.001643, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 95772 (Area: 0 - Difficulty: Normal) (Auras: 195110 -) (possible waypoints or random movement)
(@CGUID+129, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3071.785, 1902.004, 205.7034, 1.751203, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+130, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3069.095, 1929.545, 205.4849, 5.516175, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+131, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2764.527, 1904.849, 185.5772, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+132, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3074.009, 1908.825, 205.7921, 1.094562, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+133, 95766, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3146.596, 2052.691, 205.4653, 5.023777, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95766 (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+134, 95771, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3149.729, 2044.943, 205.1684, 1.481737, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Dévastateur âmeffroi (Area: 0 - Difficulty: Normal) (Auras: 195110 -)
(@CGUID+135, 95771, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3155.542, 2048.847, 204.6464, 2.427679, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Dévastateur âmeffroi (Area: 0 - Difficulty: Normal) (Auras: 195110 -)
(@CGUID+136, 95766, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3152.705, 2056.106, 205.5087, 4.567013, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95766 (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+137, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2750.244, 1849.682, 185.4754, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+138, 99366, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2956.135, 1652.759, 122.5818, 0.2796564, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99366 (Area: 0 - Difficulty: Normal)
(@CGUID+139, 99365, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2949.76, 1650.913, 122.4742, 2.144927, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99365 (Area: 0 - Difficulty: Normal)
(@CGUID+140, 100527, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2866.983, 1581.578, 105.5467, 0.9014215, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100527 (Area: 0 - Difficulty: Normal) (Auras: 191262 - Apparition de diablotin du Cauchemar)
(@CGUID+141, 99366, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2883.365, 1588.17, 100.6832, 0.3292791, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 99366 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+142, 100527, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2893.202, 1587.954, 99.5162, 0.3848299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100527 (Area: 0 - Difficulty: Normal) (Auras: 191262 - Apparition de diablotin du Cauchemar)
(@CGUID+143, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2768.55, 1823.397, 185.2911, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+144, 100527, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2852.353, 1552.477, 110.643, 0.5992038, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100527 (Area: 0 - Difficulty: Normal) (Auras: 191262 - Apparition de diablotin du Cauchemar)
(@CGUID+145, 99365, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2860.572, 1546.741, 112.9159, 1.05048, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99365 (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+146, 100527, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2859.634, 1549.884, 111.3304, 1.254359, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100527 (Area: 0 - Difficulty: Normal) (Auras: 191262 - Apparition de diablotin du Cauchemar)
(@CGUID+147, 99366, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2852.207, 1544.354, 111.1829, 0.9220657, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99366 (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+148, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2770.611, 1819.139, 185.8316, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+149, 100526, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2980.238, 1618.975, 109.6465, 4.580287, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100526 (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+150, 100526, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2986.735, 1607.042, 109.6966, 2.114024, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100526 (Area: 0 - Difficulty: Normal)
(@CGUID+151, 100526, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2811.849, 1497.197, 118.7127, 1.41413, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100526 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+152, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2840.852, 1769.857, 175.9994, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+153, 100526, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2822.152, 1495.998, 118.8234, 1.344639, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100526 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+154, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2988.224, 1531.609, 138.0866, 1.602672, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+155, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2981.6, 1523.896, 138.1313, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+156, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3080.835, 1611.892, 137.6528, 1.460833, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+157, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2984.714, 1525.655, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+158, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3079.653, 1642.307, 137.7941, 5.47671, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+159, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2980.212, 1520.922, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+160, 100531, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3089.364, 1649.455, 138.2061, 4.990328, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100531 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+161, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3078.398, 1618.901, 137.8078, 1.460833, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+162, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2996.09, 1528.993, 138.102, 1.602672, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+163, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3081.063, 1639.901, 137.7742, 5.47671, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+164, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3080.782, 1615.818, 137.6939, 1.460833, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+165, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2991.253, 1529.321, 138.0652, 1.602672, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+166, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3079.673, 1637.179, 137.7132, 5.47671, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+167, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2993.68, 1527.087, 138.102, 1.602672, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+168, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2984.885, 1521.259, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+169, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3078.816, 1613.536, 137.441, 1.460833, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+170, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3081.584, 1646.67, 138.0896, 5.47671, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+171, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2986.19, 1528.292, 137.8887, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+172, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3001.118, 1532.785, 138.102, 2.548722, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+173, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3080.054, 1609.766, 137.7371, 1.460833, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+174, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3097.618, 1640.507, 137.8403, 4.883166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+175, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3082.335, 1643.839, 138.0034, 5.47671, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+176, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3004.897, 1533.194, 138.102, 2.548722, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+177, 100526, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2801.403, 1488.481, 121.1299, 4.321712, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100526 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+178, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2984.996, 1514.804, 138.102, 4.964592, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+179, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3102.866, 1636.66, 138.8854, 4.883166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+180, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3101.043, 1639.354, 138.2571, 4.883166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+181, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3009.333, 1530.504, 138.102, 2.548722, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+182, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3100.196, 1641.997, 137.9829, 4.883166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+183, 100526, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2809.68, 1483.156, 119.4084, 1.037403, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100526 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+184, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2982.659, 1512.014, 138.102, 4.964592, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+185, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3005.265, 1530.215, 138.102, 2.548722, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+186, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2984.133, 1518.385, 138.102, 4.964592, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+187, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2999.534, 1528.917, 138.102, 1.602672, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+188, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2984.341, 1506.132, 138.1781, 4.964592, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+189, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2986.049, 1509.163, 138.102, 4.964592, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+190, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3012.484, 1526.563, 138.102, 2.548722, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+191, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3018.696, 1529.115, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+192, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3105.198, 1638.174, 139.6007, 4.883166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+193, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3031.244, 1540.568, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+194, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2842.138, 1768.648, 175.3692, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+195, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3016.73, 1526.851, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+196, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3034.901, 1539.714, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+197, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3029.891, 1536.823, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+198, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3020.211, 1525.651, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+199, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3033.514, 1536.835, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+200, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3029.654, 1532.698, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+201, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3095.157, 1609.847, 137.5198, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+202, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3022.457, 1528.156, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+203, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2985.231, 1501.651, 138.1699, 2.001165, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+204, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3026.883, 1529.724, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+205, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3098.845, 1601.67, 137.5465, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+206, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3058.2, 1553.806, 137.9444, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+207, 100529, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3064.241, 1560.896, 138.4603, 5.164085, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+208, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3098.109, 1607.281, 137.6509, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+209, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2989.568, 1502.571, 138.102, 2.001165, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+210, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3037.957, 1537.609, 138.1802, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+211, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3054.3, 1551.839, 137.9462, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+212, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3096.6, 1604.377, 137.5444, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+213, 100529, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3065.691, 1555.259, 137.6539, 4.632364, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100529 (Area: 0 - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+214, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2991.707, 1497.252, 138.102, 2.001165, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+215, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3043.129, 1535.661, 138.2249, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+216, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3059.856, 1550.764, 137.6424, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+217, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3038.977, 1534.481, 138.1217, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+218, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3097.919, 1598.118, 137.5719, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+219, 100531, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3056.908, 1541.635, 138.2527, 3.076779, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 100531 (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+220, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2989.174, 1495.122, 138.102, 2.001165, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+221, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3047.051, 1531.014, 138.1297, 1.652507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+222, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3042.175, 1532.161, 138.1073, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+223, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3056.889, 1546.302, 137.9667, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+224, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2988.195, 1498.752, 138.102, 2.001165, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+225, 100529, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3070.646, 1559.033, 138.0687, 4.991494, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100529 (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+226, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3056.624, 1549.693, 137.8785, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+227, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3047.034, 1533.863, 138.217, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+228, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3049.76, 1531.299, 138.1535, 1.652507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+229, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3125.339, 1619.851, 139.5034, 5.516175, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+230, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3047.746, 1527.09, 138.1021, 1.652507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+231, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3049.099, 1529.283, 138.1079, 1.652507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+232, 100529, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3076.596, 1552.8, 137.7294, 3.832692, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100529 (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+233, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2991.039, 1490.646, 138.2207, 1.075787, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+234, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3051.66, 1528.276, 138.1024, 1.652507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal) (Auras: 199313 - Eclosion de jeune dragonnet)
(@CGUID+235, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2995.032, 1492.726, 138.102, 1.075787, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+236, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2994.49, 1488.398, 138.1096, 1.075787, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+237, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3122.245, 1597.495, 137.1371, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+238, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2992.273, 1483.807, 138.102, 1.075787, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+239, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3125.262, 1605.83, 137.3778, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+240, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2997.055, 1485.563, 138.102, 1.075787, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+241, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3126.119, 1599.556, 137.2839, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+242, 111221, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3049.551, 1519.297, 138.102, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111221 (Area: 0 - Difficulty: Normal)
(@CGUID+243, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3122.157, 1601.212, 137.2409, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+244, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3119.603, 1598.667, 137.2883, 2.941238, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+245, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3060.804, 1515.839, 138.2535, 4.608549, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+246, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3084.459, 1531.693, 138.129, 3.421127, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+247, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2994.838, 1480.47, 138.102, 2.206719, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+248, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3058.708, 1513.936, 138.1354, 4.608549, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+249, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3079.293, 1529.602, 138.123, 3.421127, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810); -- 100533 (Area: 0 - Difficulty: Normal)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3102.874, 1549.629, 138.0002, 6.052779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+251, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3061.818, 1512.762, 138.2934, 4.608549, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+252, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3076.888, 1527.425, 137.952, 3.421127, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+253, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3102.037, 1553.12, 138.1769, 6.052779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+254, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3073.949, 1524.642, 137.7371, 3.421127, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+255, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3059.833, 1519.439, 138.1493, 4.608549, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+256, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3099.243, 1550.396, 137.8046, 6.052779, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+257, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3083.084, 1528.813, 137.8518, 3.421127, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+258, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3058.064, 1517.332, 138.1347, 4.608549, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+259, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3095.615, 1530.606, 137.5031, 1.938496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+260, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3059.593, 1506.91, 138.102, 3.792139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+261, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2997.727, 1475.335, 138.102, 2.206719, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+262, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3089.816, 1531.691, 137.9893, 1.938496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+263, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3061.562, 1509.248, 138.1451, 3.792139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+264, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3097.214, 1532.889, 137.5106, 1.938496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+265, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3169.582, 1862.234, 215.4187, 0.2255282, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+266, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3093.431, 1532.434, 137.6934, 1.938496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+267, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3009.072, 1480.49, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+268, 95779, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3221.154, 1856.007, 214.2786, 1.891584, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95779 (Area: 0 - Difficulty: Normal)
(@CGUID+269, 100533, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3092.681, 1529.589, 137.5608, 1.938496, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: 0 - Difficulty: Normal)
(@CGUID+270, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3005.765, 1481.552, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+271, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2994.413, 1476.439, 138.102, 2.206719, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+272, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3171.687, 1856.144, 215.3274, 4.302589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+273, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2999.732, 1478.849, 138.102, 2.206719, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+274, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3059.695, 1503.441, 138.102, 3.792139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+275, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3015.417, 1479.563, 138.102, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+276, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3049.981, 1495.71, 138.102, 1.806231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+277, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3009.079, 1476.254, 137.7772, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+278, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3052.284, 1496.241, 138.1597, 1.806231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+279, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3018.565, 1479.413, 138.102, 2.567477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+280, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3054.404, 1498.129, 138.151, 1.806231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+281, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3161.678, 1909.517, 213.3565, 4.587429, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+282, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3002.111, 1475.559, 138.102, 2.206719, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+283, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3052.258, 1493.403, 138.0863, 1.806231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+284, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3043.589, 1491.059, 138.102, 3.371537, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+285, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3062.175, 1504.634, 138.1046, 3.792139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+286, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3163.977, 1907.28, 213.8906, 5.206978, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+287, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3058.504, 1501.042, 138.102, 3.792139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+288, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3012.36, 1478.406, 138.0411, 2.629639, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+289, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3161.708, 1912.847, 213.0226, 5.206978, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+290, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3047.52, 1488.804, 138.102, 3.371537, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+291, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3031.659, 1482.865, 138.1011, 3.141988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+292, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3043.791, 1486.627, 138.102, 3.371537, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+293, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3028.687, 1481.25, 138.102, 3.141988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+294, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3026.44, 1480.148, 138.102, 2.567477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+295, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3022.615, 1478.446, 138.102, 2.567477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+296, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3053.28, 1490.819, 138.0295, 1.806231, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+297, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3040.888, 1485.736, 138.0979, 3.371537, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+298, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3030.701, 1478.88, 138.102, 3.141988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+299, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3024.406, 1475.903, 138.102, 2.567477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+300, 95779, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3197.717, 2042.274, 205.4849, 4.301178, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95779 (Area: 0 - Difficulty: Normal)
(@CGUID+301, 100400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3166.666, 1918.616, 214.1201, 1.246617, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: 0 - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+302, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3040.043, 1482.599, 138.102, 3.371537, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+303, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3020.423, 1474.953, 138.1159, 2.567477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+304, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3036.366, 1482.484, 138.0092, 3.141988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+305, 101072, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3033.833, 1480.009, 138.0474, 3.141988, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: 0 - Difficulty: Normal)
(@CGUID+306, 95779, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3207.17, 2032.427, 205.4849, 3.409024, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95779 (Area: 0 - Difficulty: Normal)
(@CGUID+307, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3176.899, 1917.033, 215.217, 3.319208, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+308, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3201.504, 1876.363, 215.0655, 4.69587, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+309, 73400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 2949.388, 1755.627, 142.2451, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+310, 73400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 2945.648, 1757.503, 142.2451, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+311, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3208.096, 1884.304, 214.9865, 5.516175, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+312, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3208.349, 1881.241, 214.9232, 0.2255282, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+313, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3220.112, 1859.625, 214.3268, 3.291384, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+314, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3203.707, 1881.844, 214.9865, 4.191301, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+315, 101679, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3108.334, 1998.472, 205.2882, 3.508889, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101679 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 195110 -)
(@CGUID+316, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3202.958, 1943.776, 216.3415, 5.642033, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+317, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3204.292, 1933.908, 216.4441, 0.5532302, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+318, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3205.241, 1937.818, 216.4143, 1.24094, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+319, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3211.81, 1948.608, 216.3593, 0.2255282, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+320, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3208.89, 1948.271, 216.3411, 1.015835, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+321, 100400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3218.141, 1947.422, 216.4153, 5.516175, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 146007 - Apparition des morts)
(@CGUID+322, 101679, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3124.466, 2017.934, 205.5914, 3.631403, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 101679 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 195110 -) (possible waypoints or random movement)
(@CGUID+323, 73400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3018.986, 1746.756, 142.2971, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+324, 73400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3021.968, 1745.608, 142.3074, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+325, 73400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3016.328, 1746.554, 142.2893, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+326, 73400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3022.34, 1747.176, 142.3067, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+327, 73400, 1466, 7673, 8101, 8388870, '0', 0, 0, 0, 3021.353, 1745.067, 142.3062, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Défilé Miasmatique - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+328, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3085.846, 1677.835, 141.4332, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+329, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3090.458, 1653.125, 138.3397, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+330, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3084.094, 1679.087, 141.7382, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+331, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3103.776, 1591.997, 138.3397, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+332, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3091.005, 1563.536, 138.3397, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+333, 95771, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3007.369, 1934.797, 198.9202, 0.891751, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Dévastateur âmeffroi (Area: Terrier Impur - Difficulty: Normal) (Auras: 195110 -)
(@CGUID+334, 111833, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2787.067, 1463.934, 127.6865, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111833 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+335, 111221, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2787.067, 1463.934, 127.6865, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111221 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+336, 101072, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3055.87, 1522.722, 138.0953, 4.959472, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+337, 101072, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3059.194, 1522.688, 138.092, 4.959472, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+338, 101072, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3055.045, 1528.278, 138.0736, 4.959472, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+339, 101072, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3054.102, 1525.694, 138.092, 4.959472, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+340, 101072, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3057.188, 1525.229, 138.0731, 4.959472, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+341, 99365, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2753.342, 1404.257, 141.6189, 1.170924, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99365 (Area: Terrier Impur - Difficulty: Normal) (Auras: )
(@CGUID+342, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2774.411, 1337.148, 162.6886, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+343, 99366, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2747.264, 1397.182, 142.8715, 1.170924, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99366 (Area: Terrier Impur - Difficulty: Normal) (Auras: )
(@CGUID+344, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2762.429, 1361.91, 156.0718, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+345, 100539, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2742.267, 1401.116, 142.9397, 1.170924, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100539 (Area: Terrier Impur - Difficulty: Normal) (Auras: )
(@CGUID+346, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2768.468, 1362.023, 164.3882, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+347, 99192, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2693.172, 1288.7, 128.4517, 2.120859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 99192 (Area: Terrier Impur - Difficulty: Normal) (Auras: 195106 - Ombre de Xavius)
(@CGUID+348, 100527, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2744.822, 1407.161, 142.291, 0.7178114, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100527 (Area: Terrier Impur - Difficulty: Normal) (Auras: 191262 - Apparition de diablotin du Cauchemar)
(@CGUID+349, 100526, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2752.656, 1396.479, 144.1051, 1.170924, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100526 (Area: Terrier Impur - Difficulty: Normal) (Auras: )
(@CGUID+350, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2760.63, 1380.071, 162.1245, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+351, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2766.595, 1358.606, 151.3061, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+352, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2764.791, 1347.08, 143.9962, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+353, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3019.066, 1499.71, 138.3397, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+354, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3097.618, 1640.507, 137.8403, 4.883166, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+355, 101072, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3051.66, 1528.276, 138.1024, 1.652507, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101072 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+356, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3012.596, 1502.793, 138.3397, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+357, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3095.157, 1609.847, 137.5198, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+358, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3098.845, 1601.67, 137.5465, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+359, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3098.109, 1607.281, 137.6509, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+360, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3097.919, 1598.118, 137.5719, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+361, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3096.6, 1604.377, 137.5444, 3.415504, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+362, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3088.297, 1591.543, 138.126, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+363, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3091.898, 1591.854, 138.0612, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+364, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3088.679, 1586.252, 137.587, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+365, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3089.77, 1588.875, 137.7726, 5.732284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+366, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3086.248, 1572.066, 137.8117, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+367, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3082.674, 1571.063, 137.7378, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+368, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3083.65, 1574.089, 137.8151, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+369, 100533, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3087.867, 1574.368, 137.943, 3.577847, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 100533 (Area: Terrier Impur - Difficulty: Normal)
(@CGUID+370, 73400, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 3009.15, 1507.269, 138.3397, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Terrier Impur - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+371, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2752.123, 1361.46, 137.8516, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+372, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2731.064, 1390.731, 167.0469, 1.426256, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+373, 111042, 1466, 7673, 8097, 8388870, '0', 0, 0, 0, 2730.089, 1384.936, 145.0522, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: Terrier Impur - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+374, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2722.805, 1382.127, 134.9908, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+375, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2713.4, 1379.281, 167.1792, 1.626156, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+376, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2767.361, 1329.533, 158.4381, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+377, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2711.715, 1372.106, 139.2182, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+378, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2762.916, 1328.288, 146.9322, 6.157152, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+379, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2702.597, 1366.257, 147.5701, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+380, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2696.073, 1374.977, 164.2432, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+381, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2708.403, 1380.097, 173.0091, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+382, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2754.227, 1334.964, 135.9921, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+383, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2770.134, 1316.42, 146.7999, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+384, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2690.523, 1362.271, 141.2946, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+385, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2876.353, 1584.55, 102.3957, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+386, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2683.479, 1362.064, 143.4371, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+387, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2671.481, 1370.946, 171.5531, 4.90659, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+388, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2678.878, 1352.474, 137.8283, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+389, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2765.086, 1302.095, 158.7395, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+390, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2762.763, 1297.828, 141.8775, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+391, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2664.684, 1349.691, 158.0986, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+392, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2756.939, 1288.217, 139.5723, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+393, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2670.127, 1338.573, 141.0188, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+394, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2853.595, 1546.581, 110.9173, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+395, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2739.688, 1282.701, 135.8249, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+396, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2749.785, 1280.271, 172.0609, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+397, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2748.089, 1283.63, 144.1413, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+398, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2664.425, 1339.868, 155.2378, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+399, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2659.085, 1326.12, 165.2992, 4.939292, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+400, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2666.72, 1320.316, 141.5491, 5.831089, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+401, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2723.746, 1276.453, 142.4416, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+402, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2682.589, 1293.826, 138.4925, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+403, 101329, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2686.353, 1290.243, 131.8871, 0.7438113, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 101329 (Area: 0 - Difficulty: Normal) (Auras: 199752 - Liens du Cauchemar)
(@CGUID+404, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2669.523, 1308.427, 151.8139, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+405, 100652, 1466, 7673, 0, 8388870, '0', 0, 0, 0, -0.4, -0.2, 0, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- Malfurion Hurlorage (Area: 0 - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+406, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2709.099, 1273.031, 138.1911, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+407, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2693.061, 1274.877, 144.1371, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+408, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2675.246, 1292.668, 159.4652, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+409, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2725.83, 1264.625, 161.2658, 3.432476, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+410, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2672.003, 1293.045, 167.8171, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+411, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2704.771, 1267.828, 158.0753, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+412, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2700.007, 1266.677, 163.6841, 1.75219, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+413, 111042, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2693.036, 1257.543, 161.5415, 1.573426, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 111042 (Area: 0 - Difficulty: Normal) (Auras: 221067 - Feu cauchemardesque)
(@CGUID+414, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2812.184, 1488.299, 117.4226, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+415, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2810.3, 1492.227, 118.2055, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+416, 95769, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3099.005, 1999.724, 210.8522, 5.369719, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95769 (Area: 0 - Difficulty: Normal)
(@CGUID+417, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2749.095, 1402.257, 142.3536, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+418, 73400, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 2743.643, 1399.464, 142.9126, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: 0 - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+419, 95769, 1466, 7673, 0, 8388870, '0', 0, 0, 0, 3147.231, 1828.434, 274.8328, 5.094758, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 95769 (Area: 0 - Difficulty: Normal)
(@CGUID+420, 73400, 1466, 7673, 8102, 8388870, '0', 0, 0, 0, 2694.875, 1307.138, 128.4517, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Cœur de l’Effroi - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+421, 95769, 1466, 7673, 8102, 8388870, '0', 0, 0, 0, 3100.229, 1698.653, 274.167, 2.740385, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 95769 (Area: Cœur de l’Effroi - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+422, 73400, 1466, 7673, 8102, 8388870, '0', 0, 0, 0, 2689.772, 1297.272, 128.4517, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Cœur de l’Effroi - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+423, 95769, 1466, 7673, 8102, 8388870, '0', 0, 0, 0, 3065.443, 1729.307, 274.6673, 4.28405, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 22810), -- 95769 (Area: Cœur de l’Effroi - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+424, 73400, 1466, 7673, 8102, 8388870, '0', 0, 0, 0, 2692.138, 1300.588, 128.4517, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Cœur de l’Effroi - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+425, 73400, 1466, 7673, 8102, 8388870, '0', 0, 0, 0, 2694.518, 1299.203, 128.4517, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810), -- 73400 (Area: Cœur de l’Effroi - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+426, 73400, 1466, 7673, 8102, 8388870, '0', 0, 0, 0, 2692.508, 1299.539, 128.4517, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 22810); -- 73400 (Area: Cœur de l’Effroi - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+431;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100403
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100403
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100403
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100403
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, '197709'), -- 96512 - 197709 - Bond cruel
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+11, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+12, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+14, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+15, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+17, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+19, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+24, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+25, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100539
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+28, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+29, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+30, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 100539
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+33, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 99365
(@CGUID+34, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+35, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+36, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+37, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+38, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+39, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+41, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100404
(@CGUID+43, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+45, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 99200
(@CGUID+46, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+51, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99358
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Floraison vileronce
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Floraison vileronce
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100404
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100404
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '203257'), -- 102851 - 203257 - Bouclier géant
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111221
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107638
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99365
(@CGUID+61, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, '191262'), -- 100527 - 191262 - Apparition de diablotin du Cauchemar
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+65, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+66, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+68, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+69, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+70, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+71, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100404
(@CGUID+73, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+74, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+78, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+81, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+82, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100404
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+88, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+89, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+90, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+91, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99358
(@CGUID+95, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99359
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99358
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+100, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99359
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99359
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Floraison vileronce
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99358
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Floraison vileronce
(@CGUID+108, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+112, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, '200760'), -- Floraison vileronce - 200760 - Racines terrestres
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+115, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+116, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+117, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+118, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+119, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+120, 0, 0, 1, 1, 0, 0, 0, 0, '195110'), -- 95772 - 195110 -
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95779
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95779
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- Dévastateur âmeffroi - 195110 -
(@CGUID+124, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- 95772 - 195110 -
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95779
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- 95772 - 195110 -
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- 95772 - 195110 -
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+131, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+132, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95766
(@CGUID+134, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- Dévastateur âmeffroi - 195110 -
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- Dévastateur âmeffroi - 195110 -
(@CGUID+136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95766
(@CGUID+137, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99366
(@CGUID+139, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 99365
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '191262'), -- 100527 - 191262 - Apparition de diablotin du Cauchemar
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99366
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, '191262'), -- 100527 - 191262 - Apparition de diablotin du Cauchemar
(@CGUID+143, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, '191262'), -- 100527 - 191262 - Apparition de diablotin du Cauchemar
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99365
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, '191262'), -- 100527 - 191262 - Apparition de diablotin du Cauchemar
(@CGUID+147, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 99366
(@CGUID+148, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+149, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+150, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+151, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+152, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+153, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+154, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+155, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+156, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+157, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+158, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+159, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100531
(@CGUID+161, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+162, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+163, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+164, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+165, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+166, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+167, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+168, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+169, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+170, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+171, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+172, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+173, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+174, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+175, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+176, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+177, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+178, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+179, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+180, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+181, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+182, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+183, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+184, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+185, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+186, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+187, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+188, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+189, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+190, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+191, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+192, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+193, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+194, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+195, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+196, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+197, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+198, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+199, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+200, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+201, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+202, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+203, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+204, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+205, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+206, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+208, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+209, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+210, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+211, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+212, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+214, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+215, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+216, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+217, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+218, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - 199313 - Eclosion de jeune dragonnet
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100531
(@CGUID+220, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+221, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+222, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+223, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+224, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+226, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+227, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+228, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+230, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+231, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(@CGUID+233, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+234, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 101072 - 199313 - Eclosion de jeune dragonnet
(@CGUID+235, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+236, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+237, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+238, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+239, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+240, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+241, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111221
(@CGUID+243, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+244, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+245, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+246, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+247, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+248, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+249, 0, 0, 33554432, 1, 0, 0, 0, 0, ''); -- 100533

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+251, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+252, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+253, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+254, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+255, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+256, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+257, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+258, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+259, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+260, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+261, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+262, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+263, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+264, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+266, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+267, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95779
(@CGUID+269, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+270, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+271, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+273, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+274, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+275, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+276, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+277, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+278, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+279, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+280, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+282, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+283, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+284, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+285, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+287, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+288, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+289, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+290, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+291, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+292, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+293, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+294, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+295, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+296, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+297, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+298, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+299, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95779
(@CGUID+301, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+302, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+303, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+304, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+305, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95779
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+308, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+309, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+310, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+315, 0, 0, 8, 1, 0, 0, 0, 0, '195110'), -- 101679 - 195110 -
(@CGUID+316, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+319, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+320, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - 146007 - Apparition des morts
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- 101679 - 195110 -
(@CGUID+323, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+324, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+325, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+326, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+327, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+328, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+329, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+330, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+331, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+332, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+333, 0, 0, 8, 1, 0, 0, 0, 0, '195110'), -- Dévastateur âmeffroi - 195110 -
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111833
(@CGUID+335, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111221
(@CGUID+336, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+337, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+338, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+339, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+340, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+341, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 99365
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99366
(@CGUID+344, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+345, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 100539
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, '195106'), -- 99192 - 195106 - Ombre de Xavius
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, '191262'), -- 100527 - 191262 - Apparition de diablotin du Cauchemar
(@CGUID+349, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+351, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+352, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+353, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+354, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+355, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(@CGUID+356, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+357, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+358, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+359, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+360, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+361, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+362, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+363, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+364, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+365, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+366, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+367, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+368, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+369, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100533
(@CGUID+370, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+382, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+385, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+394, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, '199752'), -- 101329 - 199752 - Liens du Cauchemar
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Malfurion Hurlorage - 46598 - Ride Vehicle Hardcoded
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - 221067 - Feu cauchemardesque
(@CGUID+414, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+415, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+416, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 95769
(@CGUID+417, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+418, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+419, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 95769
(@CGUID+420, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+421, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 95769
(@CGUID+422, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+423, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 95769
(@CGUID+424, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+425, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+426, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490');

DELETE FROM `creature_template_addon` WHERE `entry` IN (88903 /*88903*/, 82301 /*82301 - Brouillard*/, 95769 /*95769*/, 100652 /*Malfurion Hurlorage - Ride Vehicle Hardcoded*/, 101329 /*101329 - Liens du Cauchemar*/, 99192 /*99192 - Ombre de Xavius*/, 111042 /*111042 - Feu cauchemardesque*/, 111833 /*111833*/, 101679 /*101679*/, 100531 /*100531*/, 101072 /*101072*/, 99366 /*99366*/, 95766 /*95766*/, 95771 /*Dévastateur âmeffroi*/, 95779 /*95779*/, 95772 /*95772*/, 99359 /*99359*/, 100527 /*100527 - Apparition de diablotin du Cauchemar*/, 107638 /*107638*/, 111221 /*111221*/, 102851 /*102851 - Bouclier géant*/, 99360 /*Floraison vileronce*/, 99358 /*99358*/, 100526 /*100526*/, 99200 /*99200*/, 100404 /*100404*/, 73400 /*73400 - Healing Rain Visual*/, 99365 /*99365*/, 100539 /*100539*/, 100400 /*100400 - Apparition des morts*/, 100533 /*100533 - Eclosion de jeune dragonnet*/, 96512 /*96512 - Bond cruel*/, 100529 /*100529*/, 100403 /*100403*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(88903, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 88903
(82301, 0, 0, 50331648, 1, 0, 0, 0, 0, '165644'), -- 82301 - Brouillard
(95769, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 95769
(100652, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Malfurion Hurlorage - Ride Vehicle Hardcoded
(101329, 0, 0, 0, 1, 0, 0, 0, 0, '199752'), -- 101329 - Liens du Cauchemar
(99192, 0, 0, 0, 1, 0, 0, 0, 0, '195106'), -- 99192 - Ombre de Xavius
(111042, 0, 0, 0, 1, 0, 0, 0, 0, '221067'), -- 111042 - Feu cauchemardesque
(111833, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111833
(101679, 0, 0, 8, 1, 0, 0, 0, 0, '195110'), -- 101679
(100531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100531
(101072, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 101072
(99366, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99366
(95766, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95766
(95771, 0, 0, 0, 1, 0, 0, 0, 0, '195110'), -- Dévastateur âmeffroi
(95779, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 95779
(95772, 0, 0, 1, 1, 0, 0, 0, 0, '195110'), -- 95772
(99359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99359
(100527, 0, 0, 0, 1, 0, 0, 0, 0, '191262'), -- 100527 - Apparition de diablotin du Cauchemar
(107638, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 107638
(111221, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 111221
(102851, 0, 0, 0, 1, 0, 0, 0, 0, '203257'), -- 102851 - Bouclier géant
(99360, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Floraison vileronce
(99358, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 99358
(100526, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 100526
(99200, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 99200
(100404, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100404
(73400, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - Healing Rain Visual
(99365, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 99365
(100539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100539
(100400, 0, 0, 0, 1, 0, 0, 0, 0, '146007'), -- 100400 - Apparition des morts
(100533, 0, 0, 33554432, 1, 0, 0, 0, 0, '199313'), -- 100533 - Eclosion de jeune dragonnet
(96512, 0, 0, 0, 1, 0, 0, 0, 0, '197709'), -- 96512 - Bond cruel
(100529, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100529
(100403, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 100403


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (101072, 100400, 100527, 100533, 99365, 100526, 99360, 100529, 95771, 100960, 111042, 99366, 101756, 107638, 102277, 101074, 95779, 100991, 100539, 96512, 99359, 100532, 99358, 99200, 101679, 100403, 95772, 95769, 100531, 101329, 99192, 95766);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(101072, 0, 22810),
(100400, 0, 22810),
(100527, 0, 22810),
(100533, 0, 22810),
(99365, 0, 22810),
(100526, 0, 22810),
(99360, 0, 22810),
(100529, 0, 22810),
(95771, 0, 22810),
(100960, 0, 22810),
(111042, 0, 22810),
(99366, 0, 22810),
(101756, 0, 22810),
(107638, 0, 22810),
(102277, 0, 22810),
(101074, 0, 22810),
(95779, 1, 22810),
(100991, 0, 22810),
(100539, 0, 22810),
(96512, 2, 22810),
(99359, 0, 22810),
(100532, 0, 22810),
(99358, 0, 22810),
(99200, 2, 22810),
(101679, 0, 22810),
(100403, 0, 22810),
(95772, 0, 22810),
(95769, 0, 22810),
(100531, 0, 22810),
(101329, 0, 22810),
(99192, 2, 22810),
(95766, 0, 22810);


INSERT IGNORE INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(61206, 0.124, 1.2, 0, 22810),
(16946, 1, 2, 0, 22810),
(64536, 3.094482, 1.5, 0, 22810),
(71689, 2.014859, 2.5, 0, 22810),
(67054, 0.3, 3, 0, 22810),
(71688, 3.872835, 4.5, 0, 22810),
(67297, 0.5835, 2.25, 0, 22810),
(67296, 0.4896, 2.4, 0, 22810),
(69820, 3.043402, 7, 0, 22810),
(66633, 3.043402, 7, 0, 22810),
(29278, 0.91668, 3, 0, 22810),
(66131, 2.136065, 1.5, 0, 22810),
(64540, 0.5835, 2.25, 0, 22810),
(64535, 1.860481, 1.5, 0, 22810),
(64541, 1.049585, 1.5, 0, 22810),
(69819, 3.043402, 7, 0, 22810),
(64539, 0.4896, 2.4, 0, 22810),
(69818, 3.043402, 7, 0, 22810),
(64385, 1.049585, 1.5, 0, 22810),
(69688, 1.904265, 1.5, 0, 22810),
(12190, 1.159686, 1.5, 0, 22810),
(67001, 0.5, 1, 0, 22810),
(69687, 0.525, 1.5, 0, 22810),
(69689, 0.8205888, 3.5, 0, 22810),
(61828, 3.451858, 2, 0, 22810),
(71675, 12, 12, 0, 22810),
(16925, 0.5, 1, 0, 22810),
(11686, 0.5, 1, 0, 22810),
(66740, 1.869058, 1.5, 0, 22810),
(64486, 2.136066, 1.5, 0, 22810),
(66638, 0.48625, 1.875, 0, 22810),
(66739, 1.35, 4.5, 0, 22810),
(66637, 0.3825, 1.875, 0, 22810),
(66639, 0.48625, 1.875, 0, 22810),
(60365, 1.5, 5, 0, 22810),
(66738, 1.425, 4.75, 0, 22810),
(69815, 0.778, 3, 0, 22810),
(47926, 0.31, 3, 0, 22810),
(66636, 0.3825, 1.875, 0, 22810);


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=101679 AND `ID`=1) OR (`CreatureID`=99366 AND `ID`=1) OR (`CreatureID`=95771 AND `ID`=1) OR (`CreatureID`=107638 AND `ID`=1) OR (`CreatureID`=99358 AND `ID`=1) OR (`CreatureID`=100539 AND `ID`=1) OR (`CreatureID`=100400 AND `ID`=1) OR (`CreatureID`=96512 AND `ID`=1) OR (`CreatureID`=100403 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(101679, 1, 39743, 0, 0, 0, 0, 0, 0, 0, 0), -- 101679
(99366, 1, 85562, 0, 0, 0, 0, 0, 0, 0, 0), -- 99366
(95771, 1, 52529, 0, 0, 0, 0, 0, 0, 0, 0), -- Dévastateur âmeffroi
(107638, 1, 52529, 0, 0, 0, 0, 0, 0, 0, 0), -- 107638
(99358, 1, 137012, 0, 0, 0, 0, 0, 0, 0, 0), -- 99358
(100539, 1, 0, 0, 0, 0, 0, 0, 58793, 0, 0), -- 100539
(100400, 1, 52529, 0, 0, 0, 0, 0, 0, 0, 0), -- 100400
(96512, 1, 72253, 0, 0, 0, 0, 0, 0, 0, 0), -- 96512
(100403, 1, 52529, 0, 0, 0, 0, 0, 0, 0, 0); -- 100403

INSERT IGNORE INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(102277, 0, 0, 64486, 0, 0, 0, 'Leurre de Mornœil', "", "", "", 6, 0, 0, 1, 0, 3, 2097224, 0, 1, 1, 0, 0, 22810), -- 102277
(101329, 0, 0, 169, 67054, 0, 0, 'Liens du Cauchemar', "", "", "", 6, 0, 0, 1, 0, 4, 2097224, 128, 10, 1, 0, 0, 22810), -- 101329
(59764, 0, 0, 4587, 0, 0, 0, 'Totem de marée de soins', "", "", "", -1, 0, 0, 0, 0, 11, 0, 0, 0.05, 1, 0, 0, 22810), -- 59764
(101078, 0, 0, 16925, 1060, 0, 0, "", "", "", "", 6, 0, 0, 0, 0, 10, 1048576, 0, 1, 1, 0, 0, 22810), -- 101078
(111042, 0, 0, 1060, 11686, 0, 0, 'Feu cauchemardesque', "", "", "", 6, 0, 0, 0, 0, 10, 1048576, 0, 0.5, 1, 0, 0, 22810), -- 111042
(111833, 0, 0, 29297, 11686, 0, 0, 'Thal’kiel', "", "", "", 0, 0, 0, 0, 0, 10, 1048576, 0, 1, 1, 0, 0, 22810), -- 111833
(53006, 0, 0, 4590, 0, 0, 0, 'Totem de lien d''esprit', "", "", "", -1, 0, 0, 0, 0, 11, 0, 0, 1.1, 1, 0, 0, 22810), -- 53006
(100532, 0, 0, 17045, 0, 0, 0, 'Irruption sang-vicié', "", "", "", 6, 0, 0, 0, 49, 4, 2097224, 0, 1, 1, 0, 0, 22810), -- 100532
(101074, 0, 0, 69908, 0, 0, 0, 'Jeune dragonnet haine-né', "", "", "", 6, 0, 0, 0, 0, 2, 2097224, 0, 0.5, 1, 0, 0, 22810), -- 101074
(100991, 0, 0, 0, 11686, 0, 0, 'Racines étrangleuses', "", "", "", 6, 0, 0, 1, 0, 10, 2097224, 128, 0.5, 1, 0, 0, 22810), -- 100991
(101072, 0, 0, 60365, 66738, 66739, 0, 'Oeuf de dragon corrompu', "", "", "", 6, 0, 0, 1, 0, 2, 3145800, 128, 0.5, 1, 0, 0, 22810), -- 101072
(99366, 0, 0, 66131, 0, 0, 0, 'Invocateur cœur-corrompu', "", "", "", 6, 0, 0, 1, 0, 3, 2097224, 0, 6, 1, 0, 0, 22810), -- 99366
(100960, 0, 0, 11686, 0, 0, 0, 'Champignon infâme', "", "", "", 6, 0, 0, 0, 0, 11, 0, 0, 0.0000018758, 1, 0, 0, 22810), -- 100960
(101958, 0, 0, 16925, 1060, 0, 0, "", "", "", "", 6, 0, 0, 0, 0, 10, 1048576, 0, 1, 1, 0, 0, 22810), -- 101958
(99359, 0, 0, 69688, 0, 0, 0, 'Gardien cœur-putride', "", "", "", 6, 0, 0, 1, 0, 7, 2097224, 0, 5.5, 1, 0, 0, 22810), -- 99359
(101756, 0, 0, 67817, 0, 67818, 0, 'Hallucination d’araignée cœur-poison', "", "", "", 5, 0, 0, 0, 0, 3, 1048576, 0, 0.01, 1, 0, 0, 22810), -- 101756
(100652, 0, 0, 71689, 0, 0, 0, 'Malfurion Hurlorage', "", "", "", 6, 0, 0, 1, 0, 7, 134217732, 0, 1250, 225, 0, 0, 22810), -- Malfurion Hurlorage
(99192, 0, 0, 71688, 0, 0, 0, 'Ombre de Xavius', "", "", "", 6, 0, 0, 1, 0, 3, 2097256, 65664, 39, 1, 0, 171, 22810), -- 99192
(100527, 0, 0, 12190, 0, 0, 0, 'Diablotin brûle-effroi', "", "", "", 6, 0, 0, 1, 0, 3, 2097224, 0, 3, 1, 0, 0, 22810), -- 100527
(3527, 0, 0, 4587, 0, 0, 0, 'Totem guérisseur', "", "", "", -1, 0, 0, 0, 0, 11, 0, 0, 0.05, 1, 0, 0, 22810), -- 3527
(111221, 0, 0, 1287, 67001, 0, 0, 'Xal’atath', "", "", "", 0, 0, 0, 0, 0, 10, 1048576, 0, 1, 1, 0, 0, 22810), -- 111221
(107638, 0, 0, 66636, 66637, 0, 0, 'Protectrice druidique', "", "", "", 6, 0, 0, 0, 0, 7, 2097152, 0, 5, 1, 0, 0, 22810), -- 107638
(102851, 0, 0, 1060, 16925, 0, 0, 'Traqueur invisible de bouclier', "", "", "", 6, 0, 0, 0, 0, 10, 1048576, 0, 1, 1, 0, 0, 22810), -- 102851
(73504, 0, 0, 949, 0, 0, 0, 'Esprit du raptor', "", "", "", 2, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 191, 22810), -- 73504
(29264, 0, 0, 55290, 0, 0, 0, 'Esprit du loup', "", "", "", 2, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 191, 22810), -- 29264
(99360, 0, 0, 69687, 0, 0, 0, 'Floraison vileronce', "", "", "", 6, 0, 0, 1, 0, 4, 2097480, 0, 5, 1, 0, 0, 22810), -- Floraison vileronce
(99358, 0, 0, 69689, 0, 0, 0, 'Dryade cœur-putride', "", "", "", 6, 0, 0, 1, 0, 7, 2097224, 0, 4.5, 1, 0, 0, 22810), -- 99358
(61245, 0, 0, 4590, 0, 0, 0, 'Totem d’explosion de foudre', "", "", "", -1, 0, 0, 0, 0, 11, 0, 0, 1.1, 1, 0, 0, 22810), -- 61245
(100526, 0, 0, 61828, 0, 0, 0, 'Cherche-sang tourmenté', "", "", "", 6, 0, 0, 1, 0, 1, 2097224, 0, 5, 1, 0, 0, 22810), -- 100526
(100404, 0, 0, 1060, 16925, 0, 0, "", "", "", "", 6, 0, 0, 0, 0, 10, 1048576, 0, 1, 1, 0, 0, 22810), -- 100404
(99200, 0, 0, 71675, 0, 0, 0, 'Dresaron', "", "", "", 6, 0, 0, 1, 0, 2, 2097256, 128, 35, 1, 0, 171, 22810), -- 99200
(73400, 0, 0, 1126, 11686, 0, 0, 'Healing Ran Invisible Stalker DND', "", "", "", 4, 0, 0, 0, 0, 10, 1024, 0, 1, 1, 0, 187, 22810), -- 73400
(99365, 0, 0, 66740, 0, 0, 0, 'Traqueur cœur-corrompu', "", "", "", 6, 0, 0, 1, 0, 3, 2097224, 0, 5, 1, 0, 0, 22810), -- 99365
(100539, 0, 0, 64486, 0, 0, 0, 'Mornœil cœur-corrompu', "", "", "", 6, 0, 0, 1, 0, 3, 2097224, 0, 5, 1, 0, 0, 22810), -- 100539
(100403, 0, 0, 66636, 66637, 66638, 66639, 'Protecteur druidique', 'Protectrice druidique', "", "", 6, 0, 0, 0, 0, 7, 2097152, 0, 5, 1, 0, 0, 22810), -- 100403
(96512, 0, 0, 69815, 0, 0, 0, 'Archidruide Glaidalis', "", "", "", 6, 0, 0, 1, 0, 7, 2149580872, 65664, 35, 1, 0, 0, 22810); -- 96512

INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `VehicleId`, `HoverHeight`) VALUES
(88903, 0, 90, 91, 14, 0, 1, 0.9920629, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 1),
(82301, 0, 100, 100, 35, 0, 1, 1.142857, 2000, 2000, 1, 33554688, 4196352, 1, 0, 0, 1), -- 82301
(95769, 0, 98, 110, 16, 0, 1, 1, 1500, 2000, 1, 32832, 4196352, 0, 0, 0, 1), -- 95769
(100652, 0, 110, 110, 35, 0, 1, 1, 2000, 2000, 2, 33088, 2048, 0, 0, 0, 1), -- Malfurion Hurlorage
(101329, 0, 98, 110, 16, 0, 1, 1.142857, 2000, 2000, 1, 33024, 32768, 0, 0, 4533, 1), -- 101329
(99192, 0, 98, 110, 1771, 0, 2.8, 1.714286, 1500, 2000, 2, 32832, 2099200, 0, 0, 0, 1), -- 99192
(111042, 0, 98, 110, 14, 0, 1, 1.142857, 2000, 2000, 1, 33555200, 2048, 0, 0, 0, 1), -- 111042
(111833, 0, 1, 1, 35, 0, 1, 1.142857, 2000, 2000, 1, 33554944, 2048, 1, 0, 0, 1), -- 111833
(101679, 0, 101, 110, 16, 0, 1, 1.142857, 1500, 2000, 8, 32832, 2048, 0, 0, 0, 1), -- 101679
(100531, 0, 98, 110, 16, 0, 1, 1.289683, 2000, 2000, 1, 32832, 2048, 0, 0, 0, 1), -- 100531
(101072, 0, 98, 110, 14, 0, 1, 1.142857, 2000, 2000, 1, 33587200, 2048, 0, 0, 0, 1), -- 101072
(99366, 0, 98, 110, 16, 0, 1, 1, 2000, 2000, 8, 32832, 2048, 0, 0, 0, 1), -- 99366
(95766, 0, 98, 110, 16, 0, 1, 1, 1500, 2000, 1, 32832, 2099200, 0, 0, 0, 1), -- 95766
(95771, 0, 98, 110, 16, 0, 1, 1.142857, 2000, 2000, 8, 32832, 2099200, 0, 0, 0, 1), -- Dévastateur âmeffroi
(95779, 0, 98, 110, 16, 0, 2.8, 2, 2000, 2000, 1, 32832, 2099200, 0, 0, 0, 1), -- 95779
(95772, 0, 98, 110, 16, 0, 1, 1, 2000, 2000, 4, 32832, 2099200, 0, 0, 0, 1), -- 95772
(99359, 0, 98, 110, 16, 0, 1, 1, 2000, 2000, 2, 32832, 2048, 0, 0, 0, 1), -- 99359
(100527, 0, 98, 110, 16, 0, 1, 1, 2000, 2000, 2, 32768, 2048, 0, 0, 0, 1), -- 100527
(107638, 0, 98, 110, 35, 0, 1, 1.142857, 2000, 2000, 8, 32768, 2048, 1, 0, 0, 1), -- 107638
(111221, 0, 1, 1, 35, 0, 1, 1.142857, 2000, 2000, 1, 33554944, 2048, 1, 0, 0, 1), -- 111221
(102851, 0, 1, 1, 35, 0, 1, 0.9920629, 2000, 2000, 1, 33554432, 2048, 1, 0, 0, 1), -- 102851
(99360, 0, 98, 110, 16, 0, 1, 1.142857, 2000, 2000, 1, 32832, 2048, 0, 0, 0, 1), -- Floraison vileronce
(99358, 0, 98, 110, 16, 0, 1, 1, 1500, 2000, 2, 32832, 2048, 0, 0, 0, 1), -- 99358
(100526, 0, 98, 110, 16, 0, 1, 1.142857, 2000, 2000, 1, 32832, 2048, 0, 0, 0, 1), -- 100526
(99200, 0, 98, 110, 16, 0, 2.8, 1.714286, 2000, 2000, 1, 32832, 2099200, 0, 0, 0, 9), -- 99200
(100404, 0, 1, 1, 35, 0, 1, 0.9920629, 2000, 2000, 1, 33554432, 2048, 1, 0, 0, 1), -- 100404
(73400, 0, 90, 90, 35, 0, 3.2, 2, 2000, 2000, 2, 33570816, 2048, 1, 0, 0, 1), -- 73400
(99365, 0, 98, 110, 16, 0, 1, 1, 2000, 2000, 8, 32832, 2048, 0, 0, 0, 1), -- 99365
(100539, 0, 98, 110, 16, 0, 1, 1, 2000, 2000, 8, 32832, 2048, 0, 0, 0, 1), -- 100539
(100400, 0, 98, 110, 35, 0, 1, 1.142857, 2000, 2000, 8, 33587200, 67110912, 1, 0, 0, 1), -- 100400
(100533, 0, 98, 110, 14, 0, 1, 1.142857, 2000, 2000, 1, 33587200, 2048, 0, 0, 0, 1), -- 100533
(96512, 0, 98, 110, 16, 0, 1, 1.142857, 1500, 2000, 8, 32832, 2099200, 0, 0, 0, 1), -- 96512
(100529, 0, 98, 110, 16, 0, 1, 0.9920629, 2000, 2000, 1, 32768, 2048, 0, 0, 0, 1), -- 100529
(100403, 0, 98, 110, 35, 0, 1, 1.142857, 2000, 2000, 8, 32768, 2099200, 1, 0, 0, 1)
ON DUPLICATE KEY UPDATE
`entry`= VALUES(entry),
`minlevel`= VALUES(minlevel),
`maxlevel`= VALUES(maxlevel),
`faction`= VALUES(faction),
`npcflag`= VALUES(npcflag),
`speed_walk`= VALUES(speed_walk),
`speed_run`= VALUES(speed_run),
`BaseAttackTime`= VALUES(BaseAttackTime),
`RangeAttackTime`= VALUES(RangeAttackTime),
`unit_class`= VALUES(unit_class),
`unit_flags`= VALUES(unit_flags),
`unit_flags2`= VALUES(unit_flags2),
`unit_flags3`= VALUES(unit_flags3),
`dynamicflags`= VALUES(dynamicflags),
`VehicleId`= VALUES(VehicleId),
`HoverHeight`= VALUES(HoverHeight);

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=99192 AND `Idx`=7) OR (`CreatureEntry`=99192 AND `Idx`=6) OR (`CreatureEntry`=99192 AND `Idx`=5) OR (`CreatureEntry`=99192 AND `Idx`=4) OR (`CreatureEntry`=99192 AND `Idx`=3) OR (`CreatureEntry`=99192 AND `Idx`=2) OR (`CreatureEntry`=99192 AND `Idx`=1) OR (`CreatureEntry`=99192 AND `Idx`=0) OR (`CreatureEntry`=99360 AND `Idx`=1) OR (`CreatureEntry`=99360 AND `Idx`=0) OR (`CreatureEntry`=100526 AND `Idx`=1) OR (`CreatureEntry`=100526 AND `Idx`=0) OR (`CreatureEntry`=99200 AND `Idx`=3) OR (`CreatureEntry`=99200 AND `Idx`=2) OR (`CreatureEntry`=99200 AND `Idx`=1) OR (`CreatureEntry`=99200 AND `Idx`=0) OR (`CreatureEntry`=96512 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(99192, 7, 139538, 22810), -- 99192
(99192, 6, 138969, 22810), -- 99192
(99192, 5, 138971, 22810), -- 99192
(99192, 4, 138968, 22810), -- 99192
(99192, 3, 137268, 22810), -- 99192
(99192, 2, 126940, 22810), -- 99192
(99192, 1, 134091, 22810), -- 99192
(99192, 0, 134090, 22810), -- 99192
(99360, 1, 129151, 22810), -- Floraison vileronce
(99360, 0, 129151, 22810), -- Floraison vileronce
(100526, 1, 129888, 22810), -- 100526
(100526, 0, 129888, 22810), -- 100526
(99200, 3, 129894, 22810), -- 99200
(99200, 2, 129894, 22810), -- 99200
(99200, 1, 129894, 22810), -- 99200
(99200, 0, 136578, 22810), -- 99200
(96512, 0, 137211, 22810); -- 96512

UPDATE creature_template SET scriptname = "npc_dt_trash_vile_mushroom" WHERE entry = 100960;
UPDATE creature_template SET scriptname = "npc_dt_malfurion_stormrage" WHERE entry = 100652;
UPDATE creature_template SET scriptname = "boss_archdruid_glaidalis" WHERE entry = 96512;
UPDATE creature_template SET scriptname = "boss_oakheart" WHERE entry = 103344;
UPDATE creature_template SET scriptname = "npc_dt_strangling_roots" WHERE entry = 100991;
UPDATE creature_template SET scriptname = "boss_dresaron" WHERE entry = 99200;
UPDATE creature_template SET scriptname = "boss_shade_of_xavius" WHERE entry = 99192;

UPDATE areatrigger_template SET scriptname = "at_archdruid_glaidalis_nightfall" WHERE id = 10154;
UPDATE areatrigger_template SET scriptname = "at_archdruid_glaidalis_primal_rage" WHERE id = 10152;
UPDATE areatrigger_template SET scriptname = "at_oakheart_strangling_roots" WHERE id = 10725;
UPDATE areatrigger_template SET scriptname = "at_dresaron_down_draft" WHERE id = 10771;
UPDATE areatrigger_template SET scriptname = "at_shade_of_xavius_growing_paranoia" WHERE id = 10343;
UPDATE areatrigger_template SET scriptname = "at_dt_trash_propelling_charge" WHERE id = 10377;
UPDATE areatrigger_template SET scriptname = "at_dt_trash_vile_mushroom" WHERE id = 10193;
UPDATE areatrigger_template SET scriptname = "at_dt_trash_blood_assault" WHERE id = 10424;

DELETE FROM spell_script_names WHERE scriptname IN (
"spell_archdruid_glaidalis_grevious_leap_damage",
"spell_archdruid_glaidalis_primal_rage_charge", 
"spell_archdruid_glaidalis_grevious_leap_first",
"spell_archdruid_glaidalis_grevious_leap_target",
"spell_oakheart_strangling_roots_target",
"spell_oakheart_strangling_roots_summon",
"spell_shade_of_xavius_apocalyptic_nightmare",
"spell_shade_of_xavius_induced_paranoia_target",
"spell_shade_of_xavius_nightmare_bolt_target",
"spell_dt_trash_star_shower",
"spell_dt_trash_tormenting_eye",
"spell_dt_trash_hatch_whelpling"
);
INSERT INTO spell_script_names VALUES
(196354, "spell_archdruid_glaidalis_grevious_leap_damage"),
(198379, "spell_archdruid_glaidalis_primal_rage_charge"),
(196348, "spell_archdruid_glaidalis_grevious_leap_first"),
(196346, "spell_archdruid_glaidalis_grevious_leap_target"),
(204574, "spell_oakheart_strangling_roots_target"),
(199060, "spell_oakheart_strangling_roots_summon"),
(200050, "spell_shade_of_xavius_apocalyptic_nightmare"),
(200359, "spell_shade_of_xavius_induced_paranoia_target"),
(204808, "spell_shade_of_xavius_nightmare_bolt_target"),
(200658, "spell_dt_trash_star_shower"),
(204243, "spell_dt_trash_tormenting_eye"),
(199313, "spell_dt_trash_hatch_whelpling");

UPDATE `instance_template` SET parent = 1220, script = "instance_darkheart_thicket" WHERE `map` = 1466;

UPDATE creature_template SET flags_extra = flags_extra | 128 where entry IN (102851, 111042);
DELETE FROM creature WHERE map = 1466 AND id IN (73400, 111221);
UPDATE `creature_template` SET `faction` = 7, `unit_flags` = 33587202 WHERE (entry = 101072);
