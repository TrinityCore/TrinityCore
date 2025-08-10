SET @CGUID := 10004746;

SET @NPCTEXTID := 600063;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 222314, 2552, 14717, 0, '0', 23649, 0, 0, 1, 1098.4600830078125, -1983.3819580078125, 82.3054046630859375, 2.410741329193115234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Peacekeeper Leif (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+1, 222315, 2552, 14717, 0, '0', 23649, 0, 0, 0, 1099.8975830078125, -1980.8785400390625, 82.17254638671875, 2.790581703186035156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Lamplighter Kaerter (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+2, 222334, 2552, 14717, 0, '0', 23649, 0, 0, 1, 1094.435791015625, -1979.4461669921875, 82.23516845703125, 5.751266002655029296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Freywold Constable (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+3, 222330, 2552, 14717, 0, '0', 23649, 0, 0, 1, 1096.3541259765625, -1977.2882080078125, 82.11641693115234375, 5.223948955535888671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Freywold Protector (Area: 0 - Difficulty: 0) CreateObject1
(@CGUID+4, 222330, 2552, 14717, 0, '0', 23649, 0, 0, 1, 1093.545166015625, -1982.142333984375, 82.3966217041015625, 6.269052505493164062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689); -- Freywold Protector (Area: 0 - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222334; -- Freywold Constable
UPDATE `creature_template` SET `faction`=3364, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222315; -- Lamplighter Kaerter
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222314; -- Peacekeeper Leif
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222330; -- Freywold Protector

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222334 AND `DifficultyID`=0); -- 222334 (Freywold Constable) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222315 AND `DifficultyID`=0); -- 222315 (Lamplighter Kaerter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222314 AND `DifficultyID`=0); -- 222314 (Peacekeeper Leif) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222330 AND `DifficultyID`=0); -- 222330 (Freywold Protector) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222266 AND `DifficultyID`=0); -- 222266 (Lamplighter Kaerter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222268 AND `DifficultyID`=0); -- 222268 (Peacekeeper Leif) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 23649;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23649, 'Cosmetic - See Peacekeeper Leif and Lamplighter Kaerter in Freywold Village');

DELETE FROM `phase_area` WHERE `PhaseId` = 23649;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(14717, 23649, 'See Peacekeeper Leif and Lamplighter Kaerter in Freywold Village');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23649 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23649, 0, 0, 0, 47, 0, 80210, 2|8|64, 0, 0, 'Apply Phase 23642 if Quest 80456 is taken | complete | rewarded');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=222334 AND `MenuID`=35409) OR (`CreatureID`=222315 AND `MenuID`=35386);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(222334, 35409, 57689), -- Freywold Constable
(222315, 35386, 57689); -- Lamplighter Kaerter

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+4;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 267569, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222334 (Freywold Constable)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 267375, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222315 (Lamplighter Kaerter)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 267437, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222315 (Lamplighter Kaerter)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 267436, 0, 0, 0, 0, 0, 0, 0, 57689), -- 222315 (Lamplighter Kaerter)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 267435, 0, 0, 0, 0, 0, 0, 0, 57689); -- 222315 (Lamplighter Kaerter)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35409 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=35386 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=35387 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=35388 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=34994 AND `TextID`=@NPCTEXTID+4);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35409, @NPCTEXTID+0, 57689), -- 222334 (Freywold Constable)
(35386, @NPCTEXTID+1, 57689), -- 222315 (Lamplighter Kaerter)
(35387, @NPCTEXTID+2, 57689), -- 222315 (Lamplighter Kaerter)
(35388, @NPCTEXTID+3, 57689), -- 222315 (Lamplighter Kaerter)
(34994, @NPCTEXTID+4, 57689); -- 222315 (Lamplighter Kaerter)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (35386,34994,35387,35388)) OR (`OptionID`=1 AND `MenuID`=35386) OR (`OptionID`=2 AND `MenuID`=35386);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(35386, 123118, 0, 0, 'What is your mission?', 0, 0, 0, 34994, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(35386, 123123, 1, 0, 'What is a Lamplighter?', 0, 0, 0, 35388, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(34994, 123121, 0, 0, 'I have another question.', 12241, 0, 0, 35386, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(35387, 123119, 0, 0, 'I have another question.', 12241, 0, 0, 35386, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689), -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552
(35386, 123122, 2, 0, 'Who are the Order of Night?', 0, 0, 0, 35387, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(35388, 123120, 0, 0, 'I have another question.', 12241, 0, 0, 35386, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689); -- OptionBroadcastTextID: 12241 - 12478 - 23442 - 62310 - 98552

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=222314 AND `quest`=80211) OR (`id`=222268 AND `quest`=80210);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(222314, 80211, 57689), -- The Pillage of Freywold Village offered by Peacekeeper Leif
(222268, 80210, 57689); -- Found Around the Unbound offered by Peacekeeper Leif

DELETE FROM `creature_questender` WHERE (`id`=222314 AND `quest`=80210);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(222314, 80210, 57689); -- Found Around the Unbound ended by Peacekeeper Leif

DELETE FROM `quest_template_addon` WHERE `ID` IN (80210, 80211);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(80210, 0, 0, 0, 80209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Found Around the Unbound
(80211, 0, 0, 0, 80210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Pillage of Freywold Village

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=81114;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(81114, 1.821576118469238281, 1, 0, 57689);

UPDATE `creature_model_info` SET `VerifiedBuild`=57689 WHERE `DisplayID` IN (120438, 83699, 120437, 121445, 118446, 118609, 114302, 118534, 117338, 119162, 117344, 118450, 111028, 120662, 120472, 117612, 118448, 119067, 119161, 117339, 119074, 117483, 114927, 104043, 119066, 70178, 114932, 117485, 106699, 106698, 107716, 117496, 119497, 114840, 81086, 120395, 120661, 121379, 121381, 117357, 4959, 120658, 120659, 120956, 120616, 121155, 118319, 119016, 77405, 120609, 16925, 121053, 121157, 118919, 120922, 116218, 121156, 120615, 121153, 121154, 42722, 42720, 114796, 23767, 117650, 103813, 120641, 117430, 120642, 118718, 118734, 117649, 117424, 120637, 121384, 120833, 117652, 120607, 120624, 120623, 117415, 104041, 117410, 120911, 120834, 120544, 106697, 117651, 114500, 117988, 104040);
UPDATE `creature_model_info` SET `BoundingRadius`=1.111697077751159667, `VerifiedBuild`=57689 WHERE `DisplayID`=67039;
UPDATE `creature_model_info` SET `BoundingRadius`=1.929097771644592285, `CombatReach`=1.50000011920928955, `VerifiedBuild`=57689 WHERE `DisplayID`=64333;
UPDATE `creature_model_info` SET `BoundingRadius`=2.062058925628662109, `VerifiedBuild`=57689 WHERE `DisplayID`=70052;
