-- SET @CGUID := 123456789;
-- 
-- DELETE FROM `creature` WHERE `guid`= @CGUID+0;
-- INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
-- (@CGUID+0, 121818, 0, 41, 0, '0', '0', 0, 0, 1, -11781.095703125, -2378.037109375, -6.59761428833007812, 4.975621223449707031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Lord Kazzak (Area: 0 - Difficulty: 0) CreateObject1 (Auras: )

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=888, `StaticFlags1`=0x10000000, `VerifiedBuild`=58238 WHERE (`Entry`=121818 AND `DifficultyID`=0); -- 121818 (Lord Kazzak) - CanSwim
UPDATE `creature_template` SET `unit_flags2`=0x800, `ScriptName`='boss_lord_kazzak_anniversary' WHERE `entry`=121818; -- Lord Kazzak

DELETE FROM `creature_template_addon` WHERE `entry` = 121818;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(121818, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 121818 (Lord Kazzak)

DELETE FROM `creature_text` WHERE `CreatureID`=121818;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(121818, 0, 0, 'For the Legion! For Kil\'Jaeden!', 14, 0, 100, 0, 0, 0, 8650, 0, 'Lord Kazzak'),
(121818, 1, 0, 'Your own strength feeds me, $n!', 14, 0, 100, 0, 0, 0, 8461, 0, 'Lord Kazzak'),
(121818, 2, 0, 'Kazzak is supreme!', 14, 0, 100, 0, 0, 0, 8651, 0, 'Lord Kazzak');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (243737, 243723, 243726, 243715);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(243737, 'spell_lord_kazzak_mark_of_kazzak_selector'),
(243723, 'spell_lord_kazzak_mark_of_kazzak_periodic'),
(243726, 'spell_lord_kazzak_mark_of_kazzak_explosion'),
(243715, 'spell_lord_kazzak_thunderclap');
