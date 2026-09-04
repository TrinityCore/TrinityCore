SET @CGUID := 11000394;

UPDATE `creature_text` SET `CreatureID`=245248 WHERE `CreatureID`=166827; -- Trall

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (29787, 29823);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(29787, 108040, 1, 245248, 99444, 0, 0, 66562), -- Full: 0x203AE50FE0EF80000117FF000044621F Creature/0 R3769/S71679 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 245248 (Breka Grimaxe) Low: 4481567
(29787, 108041, 0, 166583, 91670, 0, 0, 66562), -- Full: 0x203AE50FE0A2ADC00117FF000044EC6E Creature/0 R3769/S71679 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 166583 (Grunt Throg) Low: 4516974
(29823, 108119, 1, 245371, 92690, 0, 0, 66562), -- Full: 0x2042650FE0EF9EC000BF9200004661AA Creature/0 R4249/S49042 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 245371 (Капитан Гэррик) Low: 4612522
(29823, 73556, 0, 160664, 94939, 0, 0, 66562); -- Full: 0x2042650FE09CE60000BF9200004663AC Creature/0 R4249/S49042 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 160664 (Рядовой Коул) Low: 4613036

DELETE FROM `conversation_line_template` WHERE `Id` IN (82300, 82299, 82390, 82389);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(82300, 0, 1, 0, 0, 66562),
(82299, 0, 0, 0, 0, 66562),
(82390, 0, 1, 0, 0, 66562),
(82389, 0, 0, 0, 0, 66562);

DELETE FROM `conversation_template` WHERE `Id` IN (29787, 29823);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(29787, 82299, 0, 66562),
(29823, 82389, 0, 66562);

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 245371, 2261, 10424, 10639, '0', 13861, 0, 0, 1, 27.25753211975097656, 3.65452742576599121, 5.023797512054443359, 3.864473342895507812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 66562); -- Капитан Гэррик (Area: Северное море - Difficulty: 0) CreateObject1
