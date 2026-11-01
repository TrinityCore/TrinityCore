SET @MOVID := 100000004;

DELETE FROM `quest_offer_reward_locale` WHERE (`locale`='ruRU' AND `ID` IN (59930,59929,54951,55122));
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(59930, 'ruRU', 'Всем уже лучше. Выдвигаемся. Пропавшая экспедиция где-то на этом острове.', 66709),
(59929, 'ruRU', 'Замечательно. Теперь давай поможем выжившим.', 66709),
(54951, 'ruRU', 'Нам пора идти. Надо найти пропавшую экспедицию.', 66709),
(55122, 'ruRU', 'Замечательно. Теперь давай поможем выжившим.', 66709);

DELETE FROM `quest_request_items_locale` WHERE (`locale`='ruRU' AND `ID` IN (59929,55122));
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(59929, 'ruRU', 'Наши аптечки растащили мурлоки. Убей их и верни аптечки мне.', 66709),
(55122, 'ruRU', 'Тебе удалось добыть аптечки? Не стоит недооценивать мурлоков.', 66709);

DELETE FROM `gameobject_template_locale` WHERE (`entry`=335718 AND `locale`='ruRU');
INSERT INTO `gameobject_template_locale` (`entry`, `locale`, `name`, `castBarCaption`, `unk1`, `VerifiedBuild`) VALUES
(335718, 'ruRU', 'Doodad_6DU_HighmaulRaid_Door_ThroneRoom001', '', '', 66709);

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=1409 AND `QuestLineId` IN (1083,1076,1072,1071));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(1409, 1083, 66709),
(1409, 1076, 66709),
(1409, 1072, 66709),
(1409, 1071, 66709);

DELETE FROM `creature_text` WHERE `CreatureID`=156626 AND `GroupID`=1 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(156626, 1, 0, 'Meet Captain Garrick up ahead. I\'m going to search the island for more survivors.', 12, 0, 100, 0, 0, 297965, 0, 0, 'Lady Jaina Proudmoore to Player');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=156626 AND `GroupID`=1 AND `ID`=0 AND `Locale`='ruRU';
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(156626, 1, 0, 'ruRU', 'Отправляйся к капитану Гэррик. А я обойду остров и поищу других выживших.');

DELETE FROM `creature_text` WHERE `CreatureID`=166782 AND `GroupID`=1 AND `ID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(166782, 1, 0, 'Meet Warlord Grimaxe up ahead. I\'ll keep looking for survivors.', 12, 0, 100, 0, 0, 297940, 0, 0, 'Thrall to Player');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=166782 AND `GroupID`=1 AND `ID`=0 AND `Locale`='ruRU';
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES
(166782, 1, 0, 'ruRU', 'Ступай к воеводе Люторез. А я продолжу искать выживших.');

-- GUID: Full: 0x2042590FE0A2DF80014BC900004803D1 Creature/0 R4246/S84937 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 166782 (Thrall) Low: 4719569
DELETE FROM `waypoint_path` WHERE `PathId`=@MOVID + 0;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@MOVID + 0, 1, 0, NULL, '166782 (Thrall)');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@MOVID + 0;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(@MOVID + 0, 1, -413.39062, -2602.0696, 0.75841147, NULL), -- PathType: None
(@MOVID + 0, 2, -395.6962, -2596.4514, 2.763699, NULL),
(@MOVID + 0, 3, -387.1111, -2597.139, 4.132194, NULL),
(@MOVID + 0, 4, -367.81772, -2600.0989, 4.9934635, NULL);

-- GUID: Full: 0x2030A10FE098F48003621C0000480314 Creature/0 R3112/S221724 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 156626 (Леди Джайна Праудмур) Low: 4719380
DELETE FROM `waypoint_path` WHERE `PathId`=@MOVID + 1;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@MOVID + 1, 1, 0, NULL, '156626 (Lady Jaina Proudmoore)');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@MOVID + 1;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(@MOVID + 1, 1, -412.55383, -2599.8594, 0.83426404, NULL),
(@MOVID + 1, 2, -400.0295, -2595.3196, 2.2845607, NULL),
(@MOVID + 1, 3, -392.21008, -2594.5208, 3.6496215, NULL);

DELETE FROM `creature_questender` WHERE (`id`=156651 AND `quest`=54952);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156651, 54952, 66709); -- 54952 ended by Капитан Гэррик

DELETE FROM `creature_questender` WHERE `id`=166854 AND `quest`=59931;
DELETE FROM `creature_questender` WHERE `id`=156607 AND `quest`=54952;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=12058 AND `Idx` IN (3,2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `ConversationActorGuid`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(12058, 76283, 3, 1051212, 0, 0, 0, 0, 66709), -- Full: 0x0
(12058, 76284, 2, 1051211, 0, 0, 0, 0, 66709), -- Full: 0x203CD10FE0A2F1800477B8000049D49E Creature/0 R3892/S292792 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 166854 Low: 4838558
(12058, 69830, 1, 1051210, 0, 0, 0, 0, 66709), -- Full: 0x0
(12058, 71297, 0, 1051209, 0, 0, 0, 0, 66709); -- Full: 0x203CD10FE098EFC00451AD0000497D20 Creature/0 R3892/S283053 Map: 2175 (9.0 NPE (New Player Experience) - Exile's Reach) Entry: 156607 (Алария) Low: 4816160

DELETE FROM `conversation_line_template` WHERE `Id` IN (36153, 36152, 34645, 29322);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(36153, 0, 3, 0, 0, 66709),
(36152, 0, 2, 0, 0, 66709),
(34645, 0, 1, 0, 0, 66709),
(29322, 0, 0, 0, 0, 66709);

DELETE FROM `conversation_template` WHERE `Id` IN (12058);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(12058, 29322, 0, 66709);
