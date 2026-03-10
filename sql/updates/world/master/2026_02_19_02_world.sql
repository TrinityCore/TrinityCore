SET @CGUID := 10006962;
SET @OGUID := 10001992;

SET @NPCTEXTID := 600176;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 248956, 0, 1519, 5316, '0', 27177, 0, 0, 0, -8188.8056640625, 608.265625, 74.8302001953125, 0.881725788116455078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65940), -- Tome of History (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: 464097 - [DNT] Lorewalking Icon)
(@CGUID+1, 230246, 0, 1519, 5316, '0', 24825, 0, 0, 0, -8182.81591796875, 606.560791015625, 74.3564605712890625, 0.911829054355621337, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65940); -- Lorewalker Cho (Area: Olivia's Pond - Difficulty: 0) CreateObject1 (Auras: 464097 - [DNT] Lorewalking Icon)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, '464097'); -- Lorewalker Cho - 464097 - [DNT] Lorewalking Icon

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 474122, 0, 1519, 5316, '0', 24825, 0, -8183.84716796875, 606.89410400390625, 73.83031463623046875, 0.86522454023361206, 0, 0, 0.419243812561035156, 0.907873690128326416, 120, 255, 1, 65940), -- Bench (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@OGUID+1, 474123, 0, 1519, 5316, '0', 24825, 0, -8181.85595703125, 605.513916015625, 73.94167327880859375, 0.722574532032012939, -0.02024602890014648, 0.055511474609375, 0.352823257446289062, 0.933822393417358398, 120, 255, 1, 65940), -- Books (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@OGUID+2, 474123, 0, 1519, 5316, '0', 24825, 0, -8181.81591796875, 605.53643798828125, 74.68930816650390625, 2.097476482391357421, 0.022162914276123046, 0.049818992614746093, 0.865352630615234375, 0.498188436031341552, 120, 255, 1, 65940), -- Books (Area: Olivia's Pond - Difficulty: 0) CreateObject1
(@OGUID+3, 474124, 0, 1519, 5316, '0', 24825, 0, -8180.7568359375, 605.30731201171875, 73.7899322509765625, 5.708745956420898437, -0.10214805603027343, -0.01639270782470703, -0.2857828140258789, 0.952693700790405273, 120, 255, 1, 65940); -- Books (Area: Olivia's Pond - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 248956;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(248956, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, '464097'); -- 248956 (Tome of History) - [DNT] Lorewalking Icon

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=248956; -- Tome of History

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3011, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=65940 WHERE (`Entry`=248956 AND `DifficultyID`=0); -- 248956 (Tome of History) - Sessile, CanSwim, Floating - CannotTurn

-- Phase
DELETE FROM `phase_name` WHERE `ID` IN (27177,24825);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(27177, 'Cosmetic - See Tome of History in capitals'),
(24825, 'Cosmetic - See Lorewalker Cho in capitals');

DELETE FROM `phase_area` WHERE `PhaseId` IN (27177,24825);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 27177, 'See Tome of History in capitals'),
(1519, 24825, 'See Lorewalker Cho in capitals');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=248956 AND `MenuID`=40111);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(248956, 40111, 65940); -- Tome of History

UPDATE `creature_template_gossip` SET `VerifiedBuild`=65940 WHERE (`CreatureID`=230246 AND `MenuID`=36405);

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 295179, 0, 0, 0, 0, 0, 0, 0, 65940), -- 248956 (Tome of History)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 299160, 0, 0, 0, 0, 0, 0, 0, 65940); -- 248956 (Tome of History)

DELETE FROM `gossip_menu` WHERE (`MenuID`=40111 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=40366 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(40111, @NPCTEXTID+0, 65940), -- 248956 (Tome of History)
(40366, @NPCTEXTID+1, 65940); -- 248956 (Tome of History)

UPDATE `gossip_menu` SET `VerifiedBuild`=65940 WHERE (`MenuID`=36405 AND `TextID`=600110) OR (`MenuID`=37339 AND `TextID`=600109);

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=40111 AND `OptionID` IN (1,0)) OR (`MenuID`=40366 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(40111, 135056, 1, 0, 'What is Recap?', 0, 0, 0, 40366, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65940),
(40111, 135057, 0, 0, '|cFF0000FF(Recap)|r What stories can you tell me?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 1248038, NULL, 65940),
(40366, 135529, 0, 0, '<Ask about something else.>', 0, 0, 0, 40111, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65940);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=65940 WHERE (`MenuID`=36405 AND `OptionID` IN (1,0)) OR (`MenuID`=37339 AND `OptionID`=0);

-- Playerchoice
DELETE FROM `playerchoice` WHERE `ChoiceId`=974;
INSERT INTO `playerchoice` (`ChoiceId`, `UiTextureKitId`, `SoundKitId`, `CloseSoundKitId`, `Duration`, `Question`, `PendingChoiceText`, `InfiniteRange`, `HideWarboardHeader`, `KeepOpenAfterChoice`, `ShowChoicesAsList`, `ForceDontShowChoicesAsList`, `VerifiedBuild`) VALUES
(974, 263, 0, 0, NULL, 'Which story would you like to hear?', '', 0, 0, 0, 0, 0, 65940);

UPDATE `playerchoice` SET `InfiniteRange`=0, `HideWarboardHeader`=0, `KeepOpenAfterChoice`=0, `ShowChoicesAsList`=0, `ForceDontShowChoicesAsList`=0, `VerifiedBuild`=65940 WHERE `ChoiceId`=845;

DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=845 AND `ResponseId`=5046) OR (`ChoiceId`=974 AND `ResponseId`=5348);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(845, 5046, 3, 6403386, 0, 1574, 0, 0, 0, 'Elves', '', '', 'Begin', 'The elves of Azeroth each have their own stories that weave together into an intricate tapestry of history. For the blood elves and the void elves, it is a story shaped by strength in the face of utmost tragedy.', '', 0, 0, 65940),
(974, 5348, 0, 7231394, 0, 1868, 0, 0, 0, 'The War Within', '', 'The War Within Awaits...', 'Begin', 'Experience the story of the champions of Azeroth dealing with Xal\'atath in the War Within storyline.', '', 0, 0, 65940);

UPDATE `playerchoice_response` SET `VerifiedBuild`=65940 WHERE (`ChoiceId`=845 AND `ResponseId` IN (4379,4322));
UPDATE `playerchoice_response` SET `Description`='Xal\'atath, the Harbinger, was once known as the Blade of the Black Empire. Her history is a well-kept secret. But her words and deeds have affected so many that she is impossible to ignore. Her story must be told.', `VerifiedBuild`=65940 WHERE (`ChoiceId`=845 AND `ResponseId`=4321);
