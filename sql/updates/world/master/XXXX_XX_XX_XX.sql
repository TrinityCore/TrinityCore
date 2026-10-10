SET @CGUID := 11000391;
SET @PATH := 100000000;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 245248, 2369, 10424, 13377, '0', 0, 0, 0, 1, -3.81319260597229003, 2.652411937713623046, 9.070906639099121093, 2.632274627685546875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66562), -- Breka Grimaxe (Area: Северное море - Difficulty: 0) CreateObject1
(@CGUID+1, 248563, 2369, 10424, 13377, '0', 15286, 0, 0, 0, -16.2924175262451171, -36.7197608947753906, 8.992197036743164062, 3.240731477737426757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66562), -- Гневион (Area: Северное море - Difficulty: 0) CreateObject1
(@CGUID+2, 248565, 2369, 10424, 13377, '0', 15286, 0, 0, 0, -10.0732851028442382, 78.40439605712890625, 15.1006622314453125, 3.030475854873657226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66562); -- Калесгос (Area: Северное море - Difficulty: 0) CreateObject1

UPDATE `creature` SET `PhaseId`=15286 WHERE `guid`=1050189; -- Trall

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 3, 0, 1, 0, 0, 18508, 0, 0, 0, ''), -- Гневион
(@CGUID+2, 0, 0, 0, 3, 0, 1, 0, 0, 18518, 0, 0, 0, ''); -- Калесгос

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (166827,166814,166824,166573,245248));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(166827, 1, 204482, 0, 0, 0, 0, 0, 0, 0, 0, 66562), -- 166827
(166814, 1, 175161, 0, 0, 0, 0, 0, 0, 0, 0, 66562), -- 166814
(166824, 1, 204482, 0, 0, 0, 0, 0, 0, 0, 0, 66562), -- 166824
(166573, 1, 204482, 0, 0, 0, 0, 0, 0, 0, 0, 66562), -- 166573
(245248, 1, 165616, 0, 0, 0, 0, 0, 0, 0, 0, 66562); -- 245248

UPDATE `creature_template_difficulty` SET `ContentTuningID`=1421, `StaticFlags1`=0x10000000, `VerifiedBuild`=66562 WHERE (`Entry`=245248 AND `DifficultyID`=0); -- 245248 (Breka Grimaxe) - CanSwim
UPDATE `creature_template` SET `faction`=2361, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=245248; -- Breka Grimaxe

DELETE FROM `gameobject_template_locale` WHERE (`entry` IN (349879, 400622, 333479) AND `locale`='ruRU');
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `unk1`, `VerifiedBuild`) VALUES
(349879, 'ruRU', 'Транспорт Орды', '', '', 66562),
(400622, 'ruRU', 'Штабель бочек', '', '', 66562),
(333479, 'ruRU', 'Корабль Альянса', '', '', 66562);

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='ruRU' AND `ID` IN (59928,59927,59926,56775));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(59928, 'ruRU', 'Этим штормом управляет какая-то неведомая сила!\n\nДержись меня в момент крушения. Я буду оберегать тебя.', 66562),
(59927, 'ruRU', 'У тебя большой потенциал, |3-6($c). Ты тоже можешь найти славу на этом острове!', 66562),
(59926, 'ruRU', 'Хорошо. Ты тренируешься с тех пор, как мы отчалили.\n\nМне нужно исследовать этот шторм. За ним стоит какая-то противоестественная сила.\n\nСразись с Трогом. Он оценит твои навыки и решит, чем ты будешь заниматься, когда мы окажемся на суше.', 66562),
(56775, 'ruRU', 'Отлично, |3-6($c). Вижу, ты в пути времени зря не $gтерял:теряла;.\n\nЧто-то погода внезапно поменялась, не нравится мне это. Попроси рядового Коула с тобой потренироваться, пока я поразмыслю над текущей ситуацией.', 66562);

DELETE FROM `conversation_actors` WHERE (`ConversationId` IN (30361, 30343) AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(30361, 64220, 1, 248565, 105921, 0, 0, 66562),
(30361, 109403, 0, 166824, 115495, 0, 0, 66562), -- Full: 0x203AE50FE0A2EA000117FF000044EB9B Creature/0 R3769/S71679 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 166824 (Thrall) Low: 4516763
(30343, 64220, 1, 248565, 105921, 0, 0, 66562),
(30343, 109370, 0, 156280, 88316, 0, 0, 66562); -- Full: 0x2042490FE0989E0001580A0000455ABF Creature/0 R4242/S88074 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 156280 (Леди Джайна Праудмур) Low: 4545215

DELETE FROM `conversation_line_template` WHERE `Id` IN (83722, 83721, 83684, 83683);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(83722, 150, 1, 0, 0, 66562),
(83721, 0, 0, 0, 0, 66562),
(83684, 150, 1, 0, 0, 66562),
(83683, 0, 0, 0, 0, 66562);

DELETE FROM `conversation_template` WHERE `Id` IN (30361, 30343);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES
(30361, 83721, 0, 'conversation_spar_ship', 66562),
(30343, 83683, 0, 'conversation_spar_ship', 66562);

DELETE FROM `phase_name` WHERE `ID`=15286;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES (15286, 'Cosmetic - See Trall - Wrathion and Kalecgos on lower deck');

DELETE FROM `phase_area` WHERE `AreaId`=13377 AND `PhaseId`=15286;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES (13377, 15286, 'Cosmetic - See Trall - Wrathion and Kalecgos on lower deck');

-- GUID: Full: 0x203AE50FE0F2BD400117FF000044EB9B Creature/0 R3769/S71679 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 248565 (Калесгос) Low: 4516763
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH+0;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH+0, 1, 0, NULL, '248565 (Kalecgos fly forward - Horde)');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH+0;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(@PATH+0, 1, -410.0703, 78.40503, 15.183995, NULL); -- PathType: ExactPathFlying

-- GUID: Full: 0x203AE50FE0F2BCC00117FF000044EB9B Creature/0 R3769/S71679 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 248563 (Гневион) Low: 4516763
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH+1;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH+1, 1, 0, NULL, '248563 (Wrathion fly forward - Horde)');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH+1;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(@PATH+1, 1, -416.29395, -36.71997, 9.07553, NULL); -- PathType: ExactPathFlying

-- GUID: Full: 0x2042490FE0F2BD4001580A0000455ABF Creature/0 R4242/S88074 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 248565 (Калесгос) Low: 4545215
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH+2;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH+2, 1, 0, NULL, '248565 (Kalecgos fly forward - Alliance)');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH+2;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(@PATH+2, 1, -487.6328, 50.77539, 28.236526, NULL); -- PathType: ExactPathFlying

-- GUID: Full: 0x2042490FE0F2BCC001580A0000455ABF Creature/0 R4242/S88074 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 248563 (Гневион) Low: 4545215
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH+3;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH+3, 1, 0, NULL, '248563 (Wrathion fly forward - Alliance)');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH+3;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(@PATH+3, 1, -446.479, -32.87451, 6.100418, NULL); -- PathType: ExactPathFlying

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=15286 AND `SourceEntry`=13377;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 15286, 13377, 0, 0, 47, 0, 59926, 64, 0, '', 1, 0, 0, '', 'Apply Phase 15286 if Quest 59926 is not rewarded');
