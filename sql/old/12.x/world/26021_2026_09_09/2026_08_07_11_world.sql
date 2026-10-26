SET @CGUID := 8000922;

SET @GGUID := 100199;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 169999, 2222, 11462, 11465, '0', 0, 0, 0, 0, 2563.0009765625, -2641.882080078125, 3305.7138671875, 2.575619697570800781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Theater of Pain - Difficulty: 0)
(@CGUID+1, 169999, 2222, 11462, 11467, '0', 0, 0, 0, 0, 2475.99658203125, -1589.13720703125, 3281.07421875, 2.540318012237548828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: The Spearhead - Difficulty: 0)
(@CGUID+2, 169999, 2222, 11462, 12777, '0', 0, 0, 0, 0, 2767.413330078125, -1406.28125, 3229.43017578125, 2.569593667984008789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Ossein Foundry - Difficulty: 0)
(@CGUID+3, 169999, 2222, 11462, 0, '0', 0, 0, 0, 0, 3405.069580078125, -1635.1875, 3148.9599609375, 2.267928838729858398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Hall of Chains - Difficulty: 0)
(@CGUID+4, 169999, 2222, 11462, 12812, '0', 0, 0, 0, 0, 3704.22216796875, -2562.88720703125, 3336.21484375, 2.074169635772705078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: High Stand - Difficulty: 0)
(@CGUID+5, 169999, 2222, 11462, 13192, '0', 0, 0, 0, 0, 3033.838623046875, -3913.725830078125, 3348.716552734375, 1.883209109306335449, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Rotting Mound - Difficulty: 0)
(@CGUID+6, 169999, 2222, 11462, 12899, '0', 0, 0, 0, 0, 1954.8853759765625, -2972.875, 3257.998779296875, 2.70807051658630371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Blighted Scar - Difficulty: 0)
(@CGUID+7, 169999, 2222, 11462, 11469, '0', 0, 0, 0, 0, 1625.3697509765625, -1902.4271240234375, 3459.499267578125, 2.801480293273925781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887); -- Spirit Obelisk (Area: Unfallen's Sanctum - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'), -- Spirit Obelisk - 315067 - Ghost
(@CGUID+1, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'), -- Spirit Obelisk - 315067 - Ghost
(@CGUID+2, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'), -- Spirit Obelisk - 315067 - Ghost
(@CGUID+3, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'), -- Spirit Obelisk - 315067 - Ghost
(@CGUID+4, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'), -- Spirit Obelisk - 315067 - Ghost
(@CGUID+5, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'), -- Spirit Obelisk - 315067 - Ghost
(@CGUID+6, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'), -- Spirit Obelisk - 315067 - Ghost
(@CGUID+7, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'); -- Spirit Obelisk - 315067 - Ghost

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+7;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 11462, 'Maldraxxus - Theater of Pain'),
(@GGUID+1, 11462, 'Maldraxxus - The Spearhead'),
(@GGUID+2, 11462, 'Maldraxxus - Ossein Foundry'),
(@GGUID+3, 11462, 'Maldraxxus - Hall of Chains'),
(@GGUID+4, 11462, 'Maldraxxus - High Stand'),
(@GGUID+5, 11462, 'Maldraxxus - Rotting Mound'),
(@GGUID+6, 11462, 'Maldraxxus - Blighted Scar'),
(@GGUID+7, 11462, 'Maldraxxus - Unfallen\'s Sanctum');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+7;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2222, 2557.5078, -2639.5017, 3305.936, 5.814549922943115234 / (2 * PI() / 360), 'Maldraxxus - Theater of Pain - GY'),
(@GGUID+1, 2222, 2480.2588, -1590.9149, 3280.9912, 2.446183681488037109 / (2 * PI() / 360), 'Maldraxxus - The Spearhead - GY'),
(@GGUID+2, 2222, 2771.441, -1409.9392, 3229.347, 2.024200439453125 / (2 * PI() / 360), 'Maldraxxus - Ossein Foundry - GY'),
(@GGUID+3, 2222, 3401.6, -1631.1, 3148.9, 5.382595062255859375 / (2 * PI() / 360), 'Maldraxxus - Hall of Chains - GY'),
(@GGUID+4, 2222, 3708.0938, -2566.5017, 3336.19, 2.017156839370727539 / (2 * PI() / 360), 'Maldraxxus - High Stand - GY'),
(@GGUID+5, 2222, 3031.7004, -3908.875, 3348.513, 5.341250896453857421 / (2 * PI() / 360), 'Maldraxxus - Rotting Mound - GY'),
(@GGUID+6, 2222, 1960.0365, -2975.3767, 3257.9155, 2.501056671142578125 / (2 * PI() / 360), 'Maldraxxus - Blighted Scar - GY'),
(@GGUID+7, 2222, 1634.0729, -1905.8993, 3458.3726, 2.670353651046752929 / (2 * PI() / 360), 'Maldraxxus - Unfallen\'s Sanctum - GY');
