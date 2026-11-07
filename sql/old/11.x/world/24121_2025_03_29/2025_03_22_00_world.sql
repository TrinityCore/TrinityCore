-- Creature Template
DELETE FROM `creature_template_addon` WHERE `entry` IN (37912 /*37912 (Drowned Kul Tiras Marine) - Permanent Feign Death*/, 37911 /*37911 (Drowned Kul Tiras Sailor) - Permanent Feign Death*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(37912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'), -- 37912 (Drowned Kul Tiras Marine) - Permanent Feign Death
(37911, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '29266'); -- 37911 (Drowned Kul Tiras Sailor) - Permanent Feign Death

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=59679 WHERE (`Entry`=37912 AND `DifficultyID`=0); -- 37912 (Drowned Kul Tiras Marine) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=59679 WHERE (`Entry`=37911 AND `DifficultyID`=0); -- 37911 (Drowned Kul Tiras Sailor) - Sessile, CanSwim
