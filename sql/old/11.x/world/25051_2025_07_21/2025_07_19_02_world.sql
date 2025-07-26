SET @CGUID := 10006614;
SET @OGUID := 10001665;

SET @NPCTEXTID := 600109;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 230246, 2552, 14771, 15042, '0', 0, 0, 0, 0, 2858.532958984375, -2576.01220703125, 239.730743408203125, 0.837110340595245361, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Lorewalker Cho (Area: Keepers Terrace - Difficulty: 0) CreateObject1 (Auras: 464097 - [DNT] Lorewalking Icon)
(@CGUID+1, 242566, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2638.10595703125, -2619.75, 219.7344207763671875, 3.888756275177001953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Lorewalker Initiate (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+2, 242550, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2635.666748046875, -2622.458251953125, 219.747222900390625, 0.866100430488586425, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61967); -- Lorewalker Initiate (Area: Dornogal - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 474122, 2552, 14771, 15042, '0', 0, 0, 2857.52783203125, -2575.600830078125, 239.1248321533203125, 0.790507078170776367, 0, 0, 0.385042190551757812, 0.922898948192596435, 120, 255, 1, 61967), -- Bench (Area: Keepers Terrace - Difficulty: 0) CreateObject1
(@OGUID+1, 474123, 2552, 14771, 15042, '0', 0, 0, 2859.4609375, -2577.079833984375, 239.12603759765625, 2.111130714416503906, -0.01104593276977539, -0.01439189910888671, 0.870058059692382812, 0.492615282535552978, 120, 255, 1, 61967), -- Books (Area: Keepers Terrace - Difficulty: 0) CreateObject1
(@OGUID+2, 474124, 2552, 14771, 15042, '0', 0, 0, 2860.491455078125, -2577.416748046875, 239.124786376953125, 4.991405010223388671, 0.028058052062988281, -0.02954292297363281, -0.60119438171386718, 0.798063457012176513, 120, 255, 1, 61967), -- Books (Area: Keepers Terrace - Difficulty: 0) CreateObject1
(@OGUID+3, 474123, 2552, 14771, 15042, '0', 0, 0, 2859.411376953125, -2577.12841796875, 239.87872314453125, 0.613140523433685302, 0.013192176818847656, -0.01514434814453125, 0.301870346069335937, 0.953137397766113281, 120, 255, 1, 61967); -- Books (Area: Keepers Terrace - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 230246;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(230246, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, '464097'); -- 230246 (Lorewalker Cho) - [DNT] Lorewalking Icon

DELETE FROM `gameobject_template_addon` WHERE `entry` = 474122;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(474122, 0, 0x800000, 0, 0); -- Bench

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=230246; -- Lorewalker Cho
UPDATE `creature_template` SET `faction`=2569, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry` IN (242566, 242550); -- Lorewalker Initiate

DELETE FROM `gameobject_template` WHERE `entry` IN (546979 /*11.1.7 OCD - Overcharged Console - Console (BIC) - Generic Hub*/, 474122 /*Bench*/, 474123 /*Books*/, 474124 /*Books*/, 547529 /*Scorched Poster*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(546979, 5, 104720, '11.1.7 OCD - Overcharged Console - Console (BIC) - Generic Hub', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967), -- 11.1.7 OCD - Overcharged Console - Console (BIC) - Generic Hub
(474122, 5, 11062, 'Bench', '', '', '', 1.60000002384185791, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967), -- Bench
(474123, 5, 51572, 'Books', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967), -- Books
(474124, 5, 43, 'Books', '', '', '', 1.20000004768371582, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967), -- Books
(547529, 2, 90368, 'Scorched Poster', '', '', '', 2, 0, 28737, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61967); -- Scorched Poster

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=230246 AND `MenuID`=36405) OR (`CreatureID`=242550 AND `MenuID`=38869) OR (`CreatureID`=242566 AND `MenuID`=38879);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(230246, 36405, 61967), -- Lorewalker Cho
(242550, 38869, 61967), -- Lorewalker Initiate
(242566, 38879, 61967); -- Lorewalker Initiate

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 277940, 0, 0, 0, 0, 0, 0, 0, 61967), -- 230246 (Lorewalker Cho)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 271126, 0, 0, 0, 0, 0, 0, 0, 61967), -- 230246 (Lorewalker Cho)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 287965, 0, 0, 0, 0, 0, 0, 0, 61967), -- 242550 (Lorewalker Initiate)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 288023, 0, 0, 0, 0, 0, 0, 0, 61967); -- 242566 (Lorewalker Initiate)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37339 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=36405 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=38869 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=38879 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37339, @NPCTEXTID+0, 61967), -- 230246 (Lorewalker Cho)
(36405, @NPCTEXTID+1, 61967), -- 230246 (Lorewalker Cho)
(38869, @NPCTEXTID+2, 61967), -- 242550 (Lorewalker Initiate)
(38879, @NPCTEXTID+3, 61967); -- 242566 (Lorewalker Initiate)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=36405 AND `OptionID` IN (1,0)) OR (`MenuID`=37339 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(36405, 125563, 1, 0, 'What is Lorewalking?', 0, 0, 0, 37339, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61967),
(36405, 124311, 0, 0, '|cFF0000FF(Lorewalking)|r What stories can you tell me?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61967),
(37339, 125564, 0, 0, '<Ask about something else.>', 0, 0, 0, 36405, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 61967);

-- Playerchoice
DELETE FROM `playerchoice` WHERE `ChoiceId`=845;
INSERT INTO `playerchoice` (`ChoiceId`, `UiTextureKitId`, `SoundKitId`, `CloseSoundKitId`, `Duration`, `Question`, `PendingChoiceText`, `InfiniteRange`, `HideWarboardHeader`, `KeepOpenAfterChoice`, `ShowChoicesAsList`, `ForceDontShowChoicesAsList`, `VerifiedBuild`) VALUES
(845, 263, 0, 0, NULL, 'Which story would you like to hear?', '', 0, 0, 0, 0, 0, 61967);

DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=845 AND `ResponseId` IN (4379,4322,4321));
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(845, 4379, 2, 6403388, 0, 1573, 0, 0, 0, 'The Lich King', '', '', 'Begin', 'Arthas Menethil. It is said that when he was born, the very forests of Lordaeron whispered his name. But did the forests of his youth know what he would eventually grow to become?', '', 0, 0, 61967),
(845, 4322, 1, 6403387, 0, 1572, 0, 0, 0, 'Ethereals', '', 'Who are the ethereals?', 'Begin', 'Mysterious and elusive, the ethereals that have traveled to our world speak little of their history. Yet there is much to be learned from the few things they do choose to share...', '', 0, 0, 61967),
(845, 4321, 0, 6403389, 0, 1571, 0, 0, 0, 'Xal\'atath', '', 'Xal\'atath awaits...', 'Begin', 'Xal\'atath, the Harbinger--once known as the Blade of the Black Empire. Her history is a well-kept secret. But her words and deeds have affected so many that she is impossible to ignore. Her story must be told.', '', 0, 0, 61967);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=127838;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(127838, 0.347222000360488891, 1.5, 0, 61967);

UPDATE `creature_model_info` SET `VerifiedBuild`=61967 WHERE `DisplayID` IN (77407, 119120, 121985, 117343, 120640, 120750, 117356, 117642, 121970, 121157, 120629, 117409, 103813, 118448, 120642, 121178, 117652, 116218, 118458, 117353, 117358, 117338, 117660, 121969, 120621, 117654, 121154, 120618, 121980, 119074, 117653, 42941, 120637, 118338, 120607, 117347, 117336, 121975, 118459, 117656, 117413, 117650, 117431, 104040, 117348, 117341, 117349, 120627, 120628, 114814, 120802, 122491, 121972, 117651, 121153, 121977, 42722, 117346, 120606, 42720, 105422, 125322, 23767, 120638, 125926, 121973, 117649, 120829, 121981, 121978, 117350, 120828, 55878, 117659, 104041, 121155, 121384, 121979, 11686, 117657, 117410, 104042, 114500, 118457, 117411, 106697, 120626);
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=9, `VerifiedBuild`=61967 WHERE `DisplayID`=110362;

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (242566,242550,230246));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(242566, 0, 10, 1, 1, 321971, 0x0, 0), -- Lorewalker Initiate
(242550, 0, 10, 1, 1, 321876, 0x0, 0), -- Lorewalker Initiate
(230246, 0, 10, 1, 1, 281542, 0x0, 0); -- Lorewalker Cho

UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=230246 AND `DifficultyID`=0); -- 230246 (Lorewalker Cho) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3011, `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=242550 AND `DifficultyID`=0); -- 242550 (Lorewalker Initiate) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3011, `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=242566 AND `DifficultyID`=0); -- 242566 (Lorewalker Initiate) - CanSwim
