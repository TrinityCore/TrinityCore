SET @CGUID := 9004528;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 203258, 654, 4755, 4755, '0', 170, 0, 0, 0, -1695.470458984375, 1310.78125, 19.86565017700195312, 4.697300434112548828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63796); -- Todd Abel (Area: Gilneas City - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Todd Abel

-- Template
UPDATE `creature_template` SET `faction`=2163, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=203258; -- Todd Abel

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=78, `StaticFlags1`=0x10000000, `VerifiedBuild`=63796 WHERE (`Entry`=203258 AND `DifficultyID`=0); -- 203258 (Todd Abel) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=111870;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(111870, 0.305999994277954101, 1.5, 0, 63796);

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (75189 /*Safety in Numbers*/, 75190 /*Ready and Abel*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(75189, 0, 0, 0, 0, 0, 0, 0, 0, 63796), -- Safety in Numbers
(75190, 0, 0, 0, 0, 0, 0, 0, 0, 63796); -- Ready and Abel

DELETE FROM `quest_offer_reward` WHERE `ID` IN (75189 /*Safety in Numbers*/, 75190 /*Ready and Abel*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(75189, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'ve done well in coming here. If we Gilneans stick together, we might yet defeat this terrible enemy.', 63796), -- Safety in Numbers
(75190, 0, 0, 0, 0, 0, 0, 0, 0, 'Glad to see you made it here safely.', 63796); -- Ready and Abel

DELETE FROM `creature_queststarter` WHERE (`id`=203258 AND `quest`=75189) OR (`id`=35840 AND `quest`=75190);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(203258, 75189, 63796), -- Safety in Numbers offered by Todd Abel
(35840, 75190, 63796); -- Ready and Abel offered by Gwen Armstead

UPDATE `creature_queststarter` SET `VerifiedBuild`=63796 WHERE (`id`=35112 AND `quest`=14157);

DELETE FROM `creature_questender` WHERE (`id`=35112 AND `quest`=75189) OR (`id`=203258 AND `quest`=75190);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(35112, 75189, 63796), -- Safety in Numbers ended by King Genn Greymane
(203258, 75190, 63796); -- Ready and Abel ended by Todd Abel
