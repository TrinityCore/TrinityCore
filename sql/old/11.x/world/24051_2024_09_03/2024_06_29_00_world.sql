SET @CGUID := 9004166;
SET @NPCTEXTID := 590114;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 216946, 2444, 13862, 13862, '0', 23362, 0, 0, 0, 63.30729293823242187, -904.3836669921875, 836.5286865234375, 2.599628686904907226, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261); -- Chromie (Area: Valdrakken - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=216946; -- Chromie

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=216946 AND `MenuID` = 33614);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(216946, 33614, 55261); -- Chromie

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 261092, 0, 0, 0, 0, 0, 0, 0, 55261), -- 216946 (Chromie)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 254760, 0, 0, 0, 0, 0, 0, 0, 55261); -- 216946 (Chromie)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34417 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=33614 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34417, @NPCTEXTID+0, 55261), -- 216946 (Chromie)
(33614, @NPCTEXTID+1, 55261); -- 216946 (Chromie)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (33614,34417));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(33614, 121716, 0, 0, 'What was your Visage Day like?', 0, 0, 0, 34417, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55261),
(34417, 122651, 0, 0, 'I want to ask about something else.', 149761, 0, 0, 33614, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 55261);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 23362;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(23362, 'Cosmetic - See Chromie in Valdrakken');

DELETE FROM `phase_area` WHERE (`PhaseId` = 23362 AND `AreaId` = 13862);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13862, 23362, 'Cosmetic - See Chromie in Valdrakken');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23362 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 23362, 0, 0, 0, 47, 0, 79511, 64, 0, 1, 'Apply Phase 23362 if Quest 79511 is not rewarded');

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID`=79511;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(79511, 1, 0, 0, 0, 0, 0, 0, 0, 'I take it Chromie sent you?', 55261); -- Identity Crisis

DELETE FROM `quest_details` WHERE `ID` IN (79512 /*Who Are You?*/, 79511 /*Identity Crisis*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(79512, 1, 0, 0, 0, 0, 0, 0, 0, 55261), -- Who Are You?
(79511, 1, 0, 0, 0, 0, 0, 0, 0, 55261); -- Identity Crisis

DELETE FROM `creature_queststarter` WHERE (`id`=216945 AND `quest`=79512) OR (`id`=216946 AND `quest`=79511);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(216945, 79512, 55261), -- Who Are You? offered by Scalecommander Emberthal
(216946, 79511, 55261); -- Identity Crisis offered by Chromie

DELETE FROM `creature_questender` WHERE (`id`=216945 AND `quest`=79511);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(216945, 79511, 55261); -- Identity Crisis ended by Scalecommander Emberthal

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE `DifficultyID`=0 AND `Entry` = 216946;
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(216946, 0, 9, 50, 1, 266436, 4, 0); -- Chromie

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2828, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216946 AND `DifficultyID`=0); -- 216946 (Chromie) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (110931, 113618, 109539, 112097, 112098, 112099, 113211, 111286, 112498, 109269, 115816, 107355, 116193, 113871, 110679, 117912, 116140, 112141);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(110931, 0.722000002861022949, 2, 0, 55261),
(113618, 0.305999994277954101, 1.5, 0, 55261),
(109539, 0.5, 1, 0, 55261),
(112097, 1.404254555702209472, 2.40000009536743164, 0, 55261),
(112098, 1.404254555702209472, 2.40000009536743164, 0, 55261),
(112099, 1.404254555702209472, 2.40000009536743164, 0, 55261),
(113211, 0.305999994277954101, 1.5, 0, 55261),
(111286, 0.382999986410140991, 1.5, 0, 55261),
(112498, 0.700812160968780517, 0.900000035762786865, 0, 55261),
(109269, 0.347000002861022949, 1.5, 0, 55261),
(115816, 0.347222000360488891, 1.5, 0, 55261),
(107355, 0.347000002861022949, 2, 0, 55261),
(116193, 0.305999994277954101, 1.5, 0, 55261),
(113871, 0.236000001430511474, 1.5, 0, 55261),
(110679, 1.930850028991699218, 3.300000190734863281, 0, 55261),
(117912, 0.372000008821487426, 1.5, 0, 55261),
(116140, 0.305999994277954101, 1.5, 0, 55261),
(112141, 0.722000002861022949, 2, 0, 55261);

UPDATE `creature_model_info` SET `CombatReach`=3.60000014305114746, `VerifiedBuild`=55261 WHERE `DisplayID` IN (104928, 104297, 104920, 104935, 104300, 104937, 106902, 104934, 106911, 103055, 104924, 104930, 106903, 104927, 104925, 104929, 104923, 104939, 104933, 106905, 104921);
UPDATE `creature_model_info` SET `VerifiedBuild`=55261 WHERE `DisplayID` IN (105893, 110847, 110484, 105526, 109518, 106214, 109519, 108179, 108178, 108919, 109251, 109522, 108384, 108622, 108466, 108506, 108482, 108498, 108524, 110511, 108583, 108002, 109302, 102031, 67362, 108157, 99952, 102033, 108402, 108464, 109253, 108992, 105828, 107950, 109005, 110241, 108283, 109383, 104555, 107270, 108995, 110350, 107065, 105394, 108164, 110647, 102647, 105851, 106110, 108377, 108267, 108074, 102140, 108135, 105529, 104178, 108158, 110240, 105530, 61527, 108249, 109602, 108657, 106705, 108656, 106707, 108988, 105806, 100847, 104451, 105104, 26375, 108418, 106449, 106946, 106416, 106945, 109473, 70287, 113531, 39211, 110344, 113479, 24746, 107069, 34533, 103825, 77405, 107700, 112292, 61892, 108433, 109669, 116648, 102365, 117262, 106489, 106487, 23439, 112587, 104171, 96559, 111423, 102777, 16412, 109442, 63703, 106310, 28282, 28111, 104323, 106253, 101210, 16431, 115766, 104949, 27823, 112578, 103479, 105218, 106426, 23767, 103828, 42722, 108832, 42720, 110930, 109849, 11686, 105601, 102137, 106367, 77687, 102202, 77406, 77690, 77407, 104308, 106494, 112165, 47166);
UPDATE `creature_model_info` SET `CombatReach`=3, `VerifiedBuild`=55261 WHERE `DisplayID` IN (110855, 108319, 108987);
UPDATE `creature_model_info` SET `CombatReach`=2.40000009536743164, `VerifiedBuild`=55261 WHERE `DisplayID` IN (107026, 106358, 108117, 107027, 107025, 107024, 107023);
UPDATE `creature_model_info` SET `BoundingRadius`=0.476598590612411499, `VerifiedBuild`=55261 WHERE `DisplayID`=107462;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=55261 WHERE `DisplayID` IN (109423, 105894);
UPDATE `creature_model_info` SET `BoundingRadius`=1.755318164825439453, `CombatReach`=3, `VerifiedBuild`=55261 WHERE `DisplayID`=108993;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=55261 WHERE `DisplayID`=106467;
UPDATE `creature_model_info` SET `BoundingRadius`=0.498713225126266479, `CombatReach`=0.5, `VerifiedBuild`=55261 WHERE `DisplayID`=102843;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=9, `VerifiedBuild`=55261 WHERE `DisplayID`=109286;
UPDATE `creature_model_info` SET `CombatReach`=3.300000190734863281, `VerifiedBuild`=55261 WHERE `DisplayID` IN (107394, 102218, 102181, 102746, 102940);
UPDATE `creature_model_info` SET `BoundingRadius`=1.014431953430175781, `CombatReach`=2.5, `VerifiedBuild`=55261 WHERE `DisplayID` IN (55233, 106811, 57521);
UPDATE `creature_model_info` SET `BoundingRadius`=1.014432311058044433, `CombatReach`=2.5, `VerifiedBuild`=55261 WHERE `DisplayID`=57522;
UPDATE `creature_model_info` SET `BoundingRadius`=1.755318164825439453, `CombatReach`=2.999999761581420898, `VerifiedBuild`=55261 WHERE `DisplayID` IN (107975, 106448);
UPDATE `creature_model_info` SET `BoundingRadius`=1.05910801887512207, `VerifiedBuild`=55261 WHERE `DisplayID`=100197;
UPDATE `creature_model_info` SET `BoundingRadius`=1.343548059463500976, `CombatReach`=4.024999618530273437, `VerifiedBuild`=55261 WHERE `DisplayID`=106908;
UPDATE `creature_model_info` SET `BoundingRadius`=1.141789793968200683, `VerifiedBuild`=55261 WHERE `DisplayID`=106788;
UPDATE `creature_model_info` SET `BoundingRadius`=0.819302201271057128, `CombatReach`=1, `VerifiedBuild`=55261 WHERE `DisplayID`=104133;
UPDATE `creature_model_info` SET `CombatReach`=2.699999809265136718, `VerifiedBuild`=55261 WHERE `DisplayID`=110235;
UPDATE `creature_model_info` SET `BoundingRadius`=1.755318164825439453, `CombatReach`=3.000000238418579101, `VerifiedBuild`=55261 WHERE `DisplayID` IN (106565, 106646);
UPDATE `creature_model_info` SET `BoundingRadius`=1.014432072639465332, `CombatReach`=2.5, `VerifiedBuild`=55261 WHERE `DisplayID`=55561;
UPDATE `creature_model_info` SET `BoundingRadius`=2.670000076293945312, `CombatReach`=7, `VerifiedBuild`=55261 WHERE `DisplayID`=107010;
UPDATE `creature_model_info` SET `BoundingRadius`=0.228800013661384582, `CombatReach`=1.649999976158142089, `VerifiedBuild`=55261 WHERE `DisplayID`=109761;
UPDATE `creature_model_info` SET `BoundingRadius`=0.509302020072937011, `VerifiedBuild`=55261 WHERE `DisplayID`=109141;
UPDATE `creature_model_info` SET `BoundingRadius`=0.500797629356384277, `CombatReach`=1, `VerifiedBuild`=55261 WHERE `DisplayID` IN (105600, 105602);
UPDATE `creature_model_info` SET `BoundingRadius`=25.37703704833984375, `VerifiedBuild`=55261 WHERE `DisplayID`=92146;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=55261 WHERE `DisplayID`=106481;
UPDATE `creature_model_info` SET `BoundingRadius`=22.45141220092773437, `VerifiedBuild`=55261 WHERE `DisplayID`=108926;
UPDATE `creature_model_info` SET `BoundingRadius`=1.343548059463500976, `CombatReach`=4.02500009536743164, `VerifiedBuild`=55261 WHERE `DisplayID`=106647;
UPDATE `creature_model_info` SET `BoundingRadius`=1.584961533546447753, `CombatReach`=2.10000014305114746, `VerifiedBuild`=55261 WHERE `DisplayID`=103508;
