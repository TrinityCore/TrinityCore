-- 
SET @CGUID := 7000554;
SET @OGUID := 7000202;

DELETE FROM `phase_name` WHERE `ID`=12844;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12844, 'Cosmetic: Kul Tiran Unlock Questline - Lumberjacks and Haunted Lumber in Evergreen Grove');

DELETE FROM `phase_area` WHERE `PhaseId`=12844;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9358, 12844, 'Cosmetic: Kul Tiran Unlock Questline - Lumberjacks and Haunted Lumber - Evergreen Grove');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12844));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12844, 0, 0, 0, 47, 0, 54727, 66, 0, '', 0, 'Player have Team Carry (54727) in state complete, rewarded');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 149020, 1643, 8567, 9358, '0', 12844, 0, 0, 1, 1691.9600830078125, 15.6875, 67.2205352783203125, 1.203155398368835449, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@CGUID+1, 149022, 1643, 8567, 9358, '0', 12844, 0, 0, 1, 1707.9166259765625, 3.137152910232543945, 70.6409759521484375, 0.734791696071624755, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@CGUID+2, 149021, 1643, 8567, 9358, '0', 12844, 0, 0, 1, 1706.704833984375, 4.387152671813964843, 69.80371856689453125, 0.570759117603302001, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Algerson Lumberjack (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@CGUID+3, 149019, 1643, 8567, 9358, '0', 12844, 0, 0, 1, 1690.9461669921875, 17.64409828186035156, 67.06375885009765625, 0.871639847755432128, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762); -- Algerson Lumberjack (Area: Evergreen Grove - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Algerson Lumberjack
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Algerson Lumberjack
(@CGUID+2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Algerson Lumberjack
(@CGUID+3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Algerson Lumberjack

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 316865, 1643, 8567, 9358, '0', 12844, 0, 1711.873291015625, 12.18923664093017578, 69.38278961181640625, 5.295260906219482421, 0.061417579650878906, -0.03307247161865234, -0.47296333312988281, 0.878316462039947509, 120, 255, 1, 54762), -- [DNT] Log Pile 02 (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@OGUID+1, 316865, 1643, 8567, 9358, '0', 12844, 0, 1715.41845703125, 7.71875, 72.98453521728515625, 2.179689884185791015, 0.461495876312255859, 0.884395599365234375, 0.061842918395996093, 0.032271843403577804, 120, 255, 1, 54762), -- [DNT] Log Pile 02 (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@OGUID+2, 316865, 1643, 8567, 9358, '0', 12844, 0, 1694.6180419921875, 20.38541603088378906, 66.80361175537109375, 3.805117130279541015, 0.005684375762939453, -0.01650047302246093, -0.94532585144042968, 0.325659990310668945, 120, 255, 1, 54762), -- [DNT] Log Pile 02 (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@OGUID+3, 317053, 1643, 8567, 9358, '0', 12844, 0, 1712.814208984375, 9.135416984558105468, 72.0547332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 54762), -- [DNT] Witch Energy (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@OGUID+4, 317053, 1643, 8567, 9358, '0', 12844, 0, 1693.74658203125, 19.16840362548828125, 66.79663848876953125, 0, 0, 0, 0, 1, 120, 255, 1, 54762), -- [DNT] Witch Energy (Area: Evergreen Grove - Difficulty: 0) CreateObject1
(@OGUID+5, 316866, 1643, 8567, 9358, '0', 12844, 0, 1711.76220703125, 9.321180343627929687, 70.25052642822265625, 5.397867202758789062, 0.161641120910644531, 0.162163734436035156, -0.43224620819091796, 0.87220311164855957, 120, 255, 1, 54762); -- [DNT] Log Pile 01 (Area: Evergreen Grove - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_addon` WHERE `entry` IN (150761);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(150761, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '292170'); -- 150761 (Log Stalker) - [DNT] Log Stalker Aura

UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=149025 AND `DifficultyID`=0); -- 149025 (Heavy Lumber) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306624, `VerifiedBuild`=54762 WHERE (`Entry`=149027 AND `DifficultyID`=0); -- 149027 (Lumber Carried) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149032 AND `DifficultyID`=0); -- 149032 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149033 AND `DifficultyID`=0); -- 149033 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149034 AND `DifficultyID`=0); -- 149034 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149035 AND `DifficultyID`=0); -- 149035 (Algerson Lumberjack) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=149036 AND `DifficultyID`=0); -- 149036 (Algerson Bodyguard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=150761 AND `DifficultyID`=0); -- 150761 (Log Stalker) - CanSwim

UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=149027; -- Lumber Carried
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=150761; -- Log Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=149036; -- Algerson Bodyguard
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry` IN (149032, 149033, 149034, 149035); -- Algerson Lumberjack
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=149025; -- Heavy Lumber

 -- Algerson Lumberjack smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 149019;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+3), 0, 0, 0, '', 1, 0, 100, 0, 2000, 6000, 5000, 6000, 10, 274, 273, 1, 6, 603, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds (OOC) - Self: Play random emote: 274, 273, 1, 6, 603,');

 -- Algerson Lumberjack smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 149020;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+0), 0, 0, 0, '', 1, 0, 100, 0, 2000, 6000, 5000, 6000, 10, 274, 273, 1, 6, 603, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds (OOC) - Self: Play random emote: 274, 273, 1, 6, 603,');
