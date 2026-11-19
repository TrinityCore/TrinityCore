SET @CGUID := 7000559;
SET @NPCTEXTID := 570041;

DELETE FROM `phase_name` WHERE `ID`=12645;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12645, 'Cosmetic: See Ulfar in Ulfars Den');

DELETE FROM `phase_area` WHERE `PhaseId`=12645;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9965, 12645, 'Cosmetic: See Ulfar in Ulfars Den');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12645));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12645, 0, 0, 0, 48, 0, 388248, 0, 1, '', 1, 'Player doesn\'t have quest objective 388248 == 1'),
(26, 12645, 0, 0, 1, 47, 0, 54731, 66, 0, '', 0, 'Player have Balance in All Things (54731) in state complete, rewarded');

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 141159, 1643, 8721, 9965, '0', 12645, 0, 0, 0, -489, 2710.79248046875, 279.670654296875, 5.194651603698730468, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Ulfar (Area: Ulfar's Den - Difficulty: 0) CreateObject1

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=141159 AND `DifficultyID`=0); -- 141159 (Ulfar) - CanSwim

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=141159 AND `MenuID`=23072) OR (`CreatureID`=149386 AND `MenuID`=23899);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(141159, 23072, 54847), -- Ulfar
(149386, 23899, 54847); -- Ulfar

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 161422, 0, 0, 0, 0, 0, 0, 0, 54847), -- 141159 (Ulfar)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 168297, 0, 0, 0, 0, 0, 0, 0, 54847), -- 141159 (Ulfar)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 170289, 0, 0, 0, 0, 0, 0, 0, 54847); -- 149386 (Ulfar)

DELETE FROM `gossip_menu` WHERE (`MenuID`=23310 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=23072 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=23899 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23310, @NPCTEXTID+0, 54847), -- 141159 (Ulfar)
(23072, @NPCTEXTID+1, 54847), -- 141159 (Ulfar)
(23899, @NPCTEXTID+2, 54847); -- 149386 (Ulfar)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=23072 AND `OptionID` IN (2,6));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(23072, 49063, 2, 0, 'Are you a druid as well?', 161426, 0, 0, 23310, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 54847),
(23072, 49067, 6, 0, '|cFF0000FF(Quest)|r Tell me how I can help.', 168298, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 54847);

UPDATE `gossip_menu_option` SET `GossipOptionID`=49062, `OptionBroadcastTextID`=25092, `ActionMenuID`=23307, `VerifiedBuild`=54847 WHERE (`MenuID`=23072 AND `OptionID`=1); -- OptionBroadcastTextID: 25092 - 38470 - 47091 - 47632 - 62792 - 65124 - 79414 - 97339 - 153888 - 161428 - 166571 - 176081 - 185133 - 224837
UPDATE `gossip_menu_option` SET `GossipOptionID`=49065, `ActionMenuID`=23311, `VerifiedBuild`=54847 WHERE (`MenuID`=23072 AND `OptionID`=4);
UPDATE `gossip_menu_option` SET `GossipOptionID`=49155, `OptionBroadcastTextID`=61781, `ActionMenuID`=23072, `VerifiedBuild`=54847 WHERE (`MenuID`=23307 AND `OptionID`=0); -- OptionBroadcastTextID: 61781 - 121489 - 152386 - 157767 - 171009
UPDATE `gossip_menu_option` SET `GossipOptionID`=49156, `OptionBroadcastTextID`=61781, `ActionMenuID`=23072, `VerifiedBuild`=54847 WHERE (`MenuID`=23310 AND `OptionID`=0); -- OptionBroadcastTextID: 61781 - 121489 - 152386 - 157767 - 171009
UPDATE `gossip_menu_option` SET `GossipOptionID`=49157, `OptionBroadcastTextID`=61781, `ActionMenuID`=23072, `VerifiedBuild`=54847 WHERE (`MenuID`=23311 AND `OptionID`=0); -- OptionBroadcastTextID: 61781 - 121489 - 152386 - 157767 - 171009

-- 
DELETE FROM `creature_model_info` WHERE `DisplayID`=90894;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(90894, 5, 0, 0, 54847);

UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=54847 WHERE `DisplayID`=86573;
UPDATE `creature_model_info` SET `VerifiedBuild`=54847 WHERE `DisplayID` IN (87111, 87519, 87518, 80850, 79761, 79843, 80951, 78516, 80766, 87930, 85030, 83401, 56156, 85176, 83402, 85032, 83399, 52598, 79282, 134, 79676, 87425, 86520, 85390, 86698, 81081, 86525, 81144, 2537, 86519);
UPDATE `creature_model_info` SET `BoundingRadius`=0.866801261901855468, `CombatReach`=2, `VerifiedBuild`=54847 WHERE `DisplayID`=86555;
UPDATE `creature_model_info` SET `BoundingRadius`=0.859295487403869628, `CombatReach`=0.400000005960464477, `VerifiedBuild`=54847 WHERE `DisplayID` IN (80910, 45598, 45906);
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.25, `VerifiedBuild`=54847 WHERE `DisplayID`=81097;
UPDATE `creature_model_info` SET `BoundingRadius`=2.588892936706542968, `CombatReach`=1.5, `VerifiedBuild`=54847 WHERE `DisplayID`=60055;
UPDATE `creature_model_info` SET `BoundingRadius`=1.881773948669433593, `CombatReach`=2.299999952316284179, `VerifiedBuild`=54847 WHERE `DisplayID`=53283;
UPDATE `creature_model_info` SET `BoundingRadius`=0.434602528810501098, `VerifiedBuild`=54847 WHERE `DisplayID`=52607;