SET @CGUID := 7001779;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 125093, 1643, 8721, 9032, '0', 0, 0, 0, 0, 92.28125, 1812.9774169921875, 44.45298004150390625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888); -- Fallhaven Villager (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- Fallhaven Villager - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)

-- Quest
DELETE FROM `quest_details` WHERE `ID`=47980;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47980, 0, 0, 0, 0, 0, 0, 0, 0, 59888); -- Furious Familiars

DELETE FROM `creature_queststarter` WHERE (`id`=125093 AND `quest`=47980);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(125093, 47980, 59888); -- Furious Familiars offered by Fallhaven Villager
