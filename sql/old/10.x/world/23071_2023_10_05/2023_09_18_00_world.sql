SET @CGUID := 9004027;

SET @NPCTEXTID := 590106;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 211031, 2444, 13862, 14489, '0', 21991, 0, 0, 1, 91.65625, -934.2100830078125, 837.3204345703125, 5.072644233703613281, 120, 0, 0, 135503, 3155, 0, NULL, NULL, NULL, NULL, 51237), -- Archdruid Hamuul Runetotem (Area: The Seat of the Aspects - Difficulty: 0) CreateObject1
(@CGUID+1, 205067, 2444, 13862, 13862, '0', 21015, 0, 0, 1, 136.9461822509765625, -928.84722900390625, 836.69000244140625, 2.534599065780639648, 120, 0, 0, 1129190, 3155, 0, NULL, NULL, NULL, NULL, 51313); -- Shandris Feathermoon (Area: Valdrakken - Difficulty: 0) CreateObject1

-- Creature Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=211031; -- Archdruid Hamuul Runetotem
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=205067; -- Shandris Feathermoon

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (211031, 205067);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(211031, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 211031 (Archdruid Hamuul Runetotem)
(205067, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 205067 (Shandris Feathermoon)

-- Creature equipment
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (211031, 205067);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(211031, 1, 63052, 0, 0, 0, 0, 0, 0, 0, 0, 51237), -- Archdruid Hamuul Runetotem
(205067, 1, 45078, 0, 0, 0, 0, 0, 208025, 0, 0, 51313); -- Shandris Feathermoon

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID` IN (77423 /*Surging Dreams*/, 75918 /*Fire Season*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(77423, 0, 0, 0, 0, 0, 0, 0, 0, 51313), -- Surging Dreams
(75918, 0, 0, 0, 0, 0, 0, 0, 0, 51313); -- Fire Season

DELETE FROM `creature_queststarter` WHERE (`id`=211031 AND `quest`=77423) OR (`id`=205067 AND `quest`=75918);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(211031, 77423, 51313), -- Surging Dreams offered Archdruid Hamuul Runetotem
(205067, 75918, 51313); -- Fire Season offered Shandris Feathermoon

-- Difficulty and modelstuff
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (207148,211031,207696,139073,206864,88807,205067,207098));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(207148, 0, 0, 0, 81, 9, 1, 1, 236371, 1073741840, 6, 51313), -- Idol
(211031, 0, 0, 0, 2708, 9, 1, 1, 260380, 0, 16384, 51313), -- Archdruid Hamuul Runetotem
(207696, 0, 0, 0, 81, 9, 1, 1, 236929, 0, 0, 51313), -- Bobby Carlisle
(139073, 0, 0, 0, 371, 9, 1, 1, 145850, 0, 0, 51313), -- Poda
(206864, 0, 0, 0, 2669, 9, 1, 1, 236087, 0, 0, 51313), -- Preservationist Kathos
(88807, 0, 0, 0, 371, 9, 1, 1, 88091, 0, 0, 51313), -- Argi
(205067, 0, 0, 0, 2154, 9, 10, 1, 234208, 0, 32768, 51313), -- Shandris Feathermoon
(207098, 0, 0, 0, 2688, 9, 1, 1, 236321, 1610612752, 6, 51313); -- [DNT] Hook Stalker

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=51313 WHERE (`DifficultyID`=0 AND `Entry` IN (58542,189168,188869,192814,199605,199261,195106,198742,185562,197182,196499,188747,197533,188825,189543,185553,188706,174170,197710,199530,199528,184170,189591,188661,143622,188219,199527,197912,197781,193495,142666,199526,188223,196191,197244,189632,189285,142668,188293,198580,187788,186794,189500,201492,189869,188210,188694,189489,188227,197986,188670,187678,202656,188823,187676,197711,187669,185714,193321,185556,199220,189827,184168,188824,107222,32639,62822,121541,32638,62821,189895));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2078, `VerifiedBuild`=51313 WHERE (`Entry`=205409 AND `DifficultyID`=0); -- Merithra
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `VerifiedBuild`=51313 WHERE (`DifficultyID`=0 AND `Entry` IN (199705,200208)); -- Trading Post Barker
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2649, `VerifiedBuild`=51313 WHERE (`Entry`=201401 AND `DifficultyID`=0); -- Hadexian
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2650, `VerifiedBuild`=51313 WHERE (`Entry`=204287 AND `DifficultyID`=0); -- Ebyssian

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (113192, 110932, 110828, 113531, 112578, 110827, 113479, 112292, 112587, 111428, 110999, 111007);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(113192, 0.300000011920928955, 1, 0, 51313),
(110932, 0.722000002861022949, 2, 0, 51313),
(110828, 0.382999986410140991, 1.5, 0, 51313),
(113531, 0.305999994277954101, 1.5, 0, 51313),
(112578, 2, 18, 0, 51313),
(110827, 0.305999994277954101, 1.5, 0, 51313),
(113479, 0.208000004291534423, 1.5, 0, 51313),
(112292, 0.367200016975402832, 1.80000007152557373, 0, 51313),
(112587, 1.5, 13.5, 0, 51313),
(111428, 19.52296829223632812, 16, 0, 51313),
(110999, 0.347000002861022949, 1.5, 0, 51313),
(111007, 1, 1.5, 0, 51313);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (21991, 21015);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(21991, 'Cosmetic - See Hamuul Runetotem in Valdrakken'),
(21015, 'Cosmetic - See Shandris Feathermoon in Valdrakken');

DELETE FROM `phase_area` WHERE `PhaseId` IN (21991, 21015) AND `AreaId` = 13862;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13862, 21991, 'Cosmetic - See Hamuul Runetotem in Valdrakken'),
(13862, 21015, 'Cosmetic - See Shandris Feathermoon in Valdrakken');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 21991 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 21991, 0, 0, 0, 47, 0, 77423, 2|8|64, 0, 1, 'Apply Phase 21991 if Quest 77423 is not complete | in progress | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 21015 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 21015, 0, 0, 0, 47, 0, 75918, 2|8|64, 0, 1, 'Apply Phase 21015 if Quest 75918 is not complete | in progress | rewarded');

-- Gossip data
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=205067 AND `MenuID`=32781);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(205067, 32781, 51313); -- Shandris Feathermoon

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 249709, 0, 0, 0, 0, 0, 0, 0, 51313); -- 205067 (Shandris Feathermoon)

DELETE FROM `gossip_menu` WHERE (`MenuID`=32781 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(32781, @NPCTEXTID+0, 51313); -- 205067 (Shandris Feathermoon)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=32781 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(114061, 32781, 0, 0, '|cFF0000FF(Play Movie)|r What have you heard from Lunedane?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 51313);
