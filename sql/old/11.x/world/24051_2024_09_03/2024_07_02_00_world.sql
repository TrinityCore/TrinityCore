SET @CGUID := 9004167;
SET @NPCTEXTID := 590116;
SET @TRANSPORTID := 34;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 223514, 2708, 15105, 15121, '0', '0', 0, 0, 0, -47.4000396728515625, 4.740094661712646484, -2.33254122734069824, 3.179655313491821289, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Druid of the Fin (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+1, 223514, 2708, 15105, 15121, '0', '0', 0, 0, 0, -23.7593326568603515, 13.4630279541015625, -3.0103921890258789, 3.179655313491821289, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Druid of the Fin (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+2, 223500, 2708, 15105, 15121, '0', '0', 0, 0, 0, -43.48583984375, 5.54296875, 8.691546440124511718, 3.073985576629638671, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Druid of the Talon (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+3, 223514, 2708, 15105, 15121, '0', '0', 0, 0, 0, -43.7457923889160156, -7.4768686294555664, -2.91291046142578125, 3.005150079727172851, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Druid of the Fin (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+4, 223500, 2708, 15105, 15121, '0', '0', 0, 0, 0, 23.45166015625, -16.191650390625, 15.0529794692993164, 3.051739215850830078, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Druid of the Talon (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+5, 223460, 2708, 15105, 15121, '0', '0', 0, 0, 1, -26.80615234375, -0.02099609375, 6.256015777587890625, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mariner Everwatch (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+6, 223500, 2708, 15105, 15121, '0', '0', 0, 0, 0, 32.08899688720703125, 7.917928218841552734, 26.39356040954589843, 2.644264459609985351, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Druid of the Talon (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+7, 223462, 2708, 15105, 15121, '0', '0', 0, 0, 1, -11.1299562454223632, -4.64913845062255859, 5.113069534301757812, 3.118079185485839843, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mariner Softsong (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+8, 223596, 2708, 15105, 15121, '0', '0', 0, 0, 1, 13.93906307220458984, -5.77332162857055664, 5.892809867858886718, 4.108254432678222656, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Merchant Felagunne (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+9, 223470, 2708, 15105, 15121, '0', '0', 0, 0, 1, 20.65731239318847656, 0.552238166332244873, 12.19228267669677734, 3.461781263351440429, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mariner Moonblade (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+10, 223597, 2708, 15105, 15121, '0', '0', 0, 0, 1, 14.03762340545654296, -7.86949920654296875, 5.900602340698242187, 1.873324751853942871, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Galley Chief Alunwea (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+11, 223454, 2708, 15105, 15121, '0', '0', 0, 0, 0, 32.10377120971679687, -1.71056187152862548, 17.628265380859375, 3.329177141189575195, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Wisp (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+12, 223471, 2708, 15105, 15121, '0', '0', 0, 0, 1, 32.16616058349609375, 9.724039077758789062, 17.29249763488769531, 3.018790245056152343, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261), -- Mariner Stillwake (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
(@CGUID+13, 216722, 2708, 15105, 15121, '0', '0', 0, 0, 0, 31.81662750244140625, 1.327973008155822753, 17.62497711181640625, 3.046808958053588867, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55261); -- Captain Talar Oaktalon (Area: -Unknown- - Difficulty: 0) CreateObject1 - !!! on transport - transport template not found !!!
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 27325, 0, 0, 0, ''), -- Druid of the Fin
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 27325, 0, 0, 0, ''), -- Druid of the Fin
(@CGUID+2, 0, 0, 0, 3, 0, 1, 0, 0, 28645, 0, 0, 0, ''), -- Druid of the Talon
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 27325, 0, 0, 0, ''), -- Druid of the Fin
(@CGUID+4, 0, 0, 0, 3, 0, 1, 0, 0, 28645, 0, 0, 0, ''), -- Druid of the Talon
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 455, 0, 0, 0, 0, ''), -- Druid of the Talon
(@CGUID+8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Merchant Felagunne
(@CGUID+9, 0, 0, 0, 0, 0, 0, 0, 733, 0, 0, 0, 0, ''), -- Mariner Moonblade
(@CGUID+10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Galley Chief Alunwea
(@CGUID+11, 0, 0, 0, 3, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Wisp

-- Template
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216719; -- Mariner Farsight
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216722; -- Captain Talar Oaktalon
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=223471; -- Mariner Stillwake
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=223454; -- Wisp
UPDATE `creature_template` SET `faction`=1733, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223597; -- Galley Chief Alunwea
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=223470; -- Mariner Moonblade
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=1500, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216540; -- Feralas Visitor
UPDATE `creature_template` SET `faction`=1733, `npcflag`=6272, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=223596; -- Merchant Felagunne
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=223462; -- Mariner Softsong
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=223460; -- Mariner Everwatch
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=223500; -- Druid of the Talon
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=223514; -- Druid of the Fin
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216718; -- Mariner Swiftstar
UPDATE `creature_template` SET `faction`=1971, `npcflag`=1, `speed_run`=1.385714292526245117, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216803; -- Sentinel Eriadnar
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216763; -- Cerellean Whiteclaw
UPDATE `creature_template` SET `faction`=1971, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=216432; -- Kaldorei Angler
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=216753; -- Grimclaw
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=216710; -- Bel'ameth Watcher

DELETE FROM `gameobject_template` WHERE `entry` IN (419028 /*Boat*/, 421186 /*Kaldorei Spyglass*/, 420982 /*Portal to Feathermoon Stronghold*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(419028, 15, 72595, 'Boat', '', '', '', 1, 9543, 30, 1, 0, 0, 1, 2708, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Boat
(421186, 3, 87321, 'Kaldorei Spyglass', 'questinteract', '', '', 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6019, 121585, 0, 0, 0, 0, 2484, 55261), -- Kaldorei Spyglass
(420982, 22, 5231, 'Portal to Feathermoon Stronghold', '', '', '', 1.5, 433173, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 876, 55261); -- Portal to Feathermoon Stronghold

-- Transport
DELETE FROM `transports` WHERE `guid` = @TRANSPORTID;
INSERT INTO `transports` (`guid`, `entry`, `name`, `phaseUseFlags`, `phaseid`, `phasegroup`, `ScriptName`) VALUES
(@TRANSPORTID, 419028, 'Bel''Ameth and Gilneas (\"Moonlit Rose\")', 0, 0, 0, '');

DELETE FROM `gameobject_template_addon` WHERE `entry`= 419028;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `WorldEffectID`, `AIAnimKitID`) VALUES
(419028, 0, 0x100028, 0, 0, 0, 0);

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (216719,223471,223597,223470,223596,223462,223460,216718,216763,216432));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(216719, 1, 213012, 0, 0, 0, 0, 0, 5258, 0, 0, 55261), -- Mariner Farsight
(223471, 1, 213012, 0, 0, 0, 0, 0, 5258, 0, 0, 55261), -- Mariner Stillwake
(223597, 1, 200751, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Galley Chief Alunwea
(223470, 1, 213012, 0, 0, 0, 0, 0, 5258, 0, 0, 55261), -- Mariner Moonblade
(223596, 1, 154988, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Merchant Felagunne
(223462, 1, 213012, 0, 0, 0, 0, 0, 5258, 0, 0, 55261), -- Mariner Softsong
(223460, 1, 213012, 0, 0, 0, 0, 0, 5258, 0, 0, 55261), -- Mariner Everwatch
(216718, 1, 213012, 0, 0, 0, 0, 0, 5258, 0, 0, 55261), -- Mariner Swiftstar
(216763, 1, 3494, 0, 0, 0, 0, 0, 0, 0, 0, 55261), -- Cerellean Whiteclaw
(216432, 1, 116826, 0, 0, 0, 0, 0, 0, 0, 0, 55261); -- Kaldorei Angler

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`MenuID`=34913 AND `CreatureID`=216722) OR (`MenuID`=9056 AND `CreatureID`=223471) OR (`MenuID`=9054 AND `CreatureID` IN (223470,223462)) OR (`MenuID`=9057 AND `CreatureID`=223460);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(216722, 34913, 55261), -- Captain Talar Oaktalon
(223471, 9056, 55261), -- Mariner Stillwake
(223470, 9054, 55261), -- Mariner Moonblade
(223462, 9054, 55261), -- Mariner Softsong
(223460, 9057, 55261); -- Mariner Everwatch

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 263770, 0, 0, 0, 0, 0, 0, 0, 55261); -- 216722 (Captain Talar Oaktalon)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34913 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34913, @NPCTEXTID+0, 55261); -- 216722 (Captain Talar Oaktalon)

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (223471,223454,223597,223470,223596,223462,223460,223514,223500,218647,218977,218646));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(223471, 0, 9, 2, 1, 274298, 0, 0), -- Mariner Stillwake
(223454, 0, 9, 1.019999980926513671, 1, 274281, 0, 0), -- Wisp
(223597, 0, 9, 1, 1, 274456, 0, 0), -- Galley Chief Alunwea
(223470, 0, 9, 2, 1, 274297, 0, 0), -- Mariner Moonblade
(223596, 0, 9, 1, 1, 274455, 0, 0), -- Merchant Felagunne
(223462, 0, 9, 2, 1, 274289, 0, 0), -- Mariner Softsong
(223460, 0, 9, 2, 1, 274287, 0, 0), -- Mariner Everwatch
(223514, 0, 9, 1, 1, 274341, 4096, 0), -- Druid of the Fin
(223500, 0, 9, 1, 1, 274327, 4096, 0), -- Druid of the Talon
(218647, 0, 9, 1, 1, 268162, 0, 0), -- Glamrok
(218977, 0, 9, 1, 1, 268541, 0, 0), -- Happy
(218646, 0, 9, 1, 1, 268161, 0, 0); -- Bubbles

UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216719 AND `DifficultyID`=0); -- 216719 (Mariner Farsight) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216722 AND `DifficultyID`=0); -- 216722 (Captain Talar Oaktalon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=966, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223471 AND `DifficultyID`=0); -- 223471 (Mariner Stillwake) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=536870912, `VerifiedBuild`=55261 WHERE (`Entry`=223454 AND `DifficultyID`=0); -- 223454 (Wisp) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=966, `VerifiedBuild`=55261 WHERE (`Entry`=223597 AND `DifficultyID`=0); -- 223597 (Galley Chief Alunwea) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=966, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223470 AND `DifficultyID`=0); -- 223470 (Mariner Moonblade) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216540 AND `DifficultyID`=0); -- 216540 (Feralas Visitor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=966, `VerifiedBuild`=55261 WHERE (`Entry`=223596 AND `DifficultyID`=0); -- 223596 (Merchant Felagunne) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=966, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223462 AND `DifficultyID`=0); -- 223462 (Mariner Softsong) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=966, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223460 AND `DifficultyID`=0); -- 223460 (Mariner Everwatch) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=223500 AND `DifficultyID`=0); -- 223500 (Druid of the Talon) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=223514 AND `DifficultyID`=0); -- 223514 (Druid of the Fin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216718 AND `DifficultyID`=0); -- 216718 (Mariner Swiftstar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216803 AND `DifficultyID`=0); -- 216803 (Sentinel Eriadnar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216763 AND `DifficultyID`=0); -- 216763 (Cerellean Whiteclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216432 AND `DifficultyID`=0); -- 216432 (Kaldorei Angler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=268435456, `VerifiedBuild`=55261 WHERE (`Entry`=216753 AND `DifficultyID`=0); -- 216753 (Grimclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=876, `StaticFlags1`=805306368, `VerifiedBuild`=55261 WHERE (`Entry`=216710 AND `DifficultyID`=0); -- 216710 (Bel'ameth Watcher) - CanSwim, Floating

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (117023, 116742, 119487, 119575, 119485, 116946, 119574, 119472, 119469, 120148, 119526, 120117, 117021, 114248, 116224, 116973, 116972);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(117023, 0.305999994277954101, 1.5, 0, 55261),
(116742, 0.466800004243850708, 1.80000007152557373, 0, 55261),
(119487, 0.305999994277954101, 1.5, 0, 55261),
(119575, 0.305999994277954101, 1.5, 0, 55261),
(119485, 0.305999994277954101, 1.5, 0, 55261),
(116946, 0.388999998569488525, 1.5, 0, 55261),
(119574, 0.388999998569488525, 1.5, 0, 55261),
(119472, 0.305999994277954101, 1.5, 0, 55261),
(119469, 0.305999994277954101, 1.5, 0, 55261),
(120148, 1, 1, 0, 55261),
(119526, 0.349999994039535522, 0.800000011920928955, 0, 55261),
(120117, 0.984943270683288574, 1.5, 0, 55261),
(117021, 0.305999994277954101, 1.5, 0, 55261),
(114248, 0.305999994277954101, 1.5, 0, 55261),
(116224, 0.388999998569488525, 1.5, 0, 55261),
(116973, 0.388999998569488525, 1.5, 0, 55261),
(116972, 0.305999994277954101, 1.5, 0, 55261);

UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=2.25, `VerifiedBuild`=55261 WHERE `DisplayID`=68815;
UPDATE `creature_model_info` SET `VerifiedBuild`=55261 WHERE `DisplayID` IN (37729, 2428, 913);
UPDATE `creature_model_info` SET `BoundingRadius`=2.062988519668579101, `VerifiedBuild`=55261 WHERE `DisplayID`=106536;

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=223597 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=8950 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4544 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4542 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4541 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4540 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=8766 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=1645 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=1708 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=1205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=1179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223597 AND `item`=4600 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=223596 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(223597, 21, 2678, 0, 0, 1, 0, 0, 55261), -- Mild Spices
(223597, 20, 30817, 0, 0, 1, 0, 0, 55261), -- Simple Flour
(223597, 19, 8950, 0, 0, 1, 0, 0, 55261), -- Homemade Cherry Pie
(223597, 18, 4601, 0, 0, 1, 0, 0, 55261), -- Soft Banana Bread
(223597, 17, 4544, 0, 0, 1, 0, 0, 55261), -- Mulgore Spice Bread
(223597, 16, 4542, 0, 0, 1, 0, 0, 55261), -- Moist Cornbread
(223597, 15, 4541, 0, 0, 1, 0, 0, 55261), -- Freshly Baked Bread
(223597, 14, 4540, 0, 0, 1, 0, 0, 55261), -- Tough Hunk of Bread
(223597, 13, 8957, 0, 0, 1, 0, 0, 55261), -- Spinefin Halibut
(223597, 12, 21552, 0, 0, 1, 0, 0, 55261), -- Striped Yellowtail
(223597, 11, 4594, 0, 0, 1, 0, 0, 55261), -- Rockscale Cod
(223597, 10, 4593, 0, 0, 1, 0, 0, 55261), -- Bristle Whisker Catfish
(223597, 9, 4592, 0, 0, 1, 0, 0, 55261), -- Longjaw Mud Snapper
(223597, 8, 787, 0, 0, 1, 0, 0, 55261), -- Slitherskin Mackerel
(223597, 7, 8766, 0, 0, 1, 0, 0, 55261), -- Morning Glory Dew
(223597, 6, 1645, 0, 0, 1, 0, 0, 55261), -- Moonberry Juice
(223597, 5, 1708, 0, 0, 1, 0, 0, 55261), -- Sweet Nectar
(223597, 4, 1205, 0, 0, 1, 0, 0, 55261), -- Melon Juice
(223597, 3, 1179, 0, 0, 1, 0, 0, 55261), -- Ice Cold Milk
(223597, 2, 159, 0, 0, 1, 0, 0, 55261), -- Refreshing Spring Water
(223597, 1, 4600, 0, 0, 1, 0, 0, 55261), -- Cherry Grog
(223596, 31, 64670, 0, 0, 1, 0, 0, 55261), -- Vanishing Powder
(223596, 30, 39505, 0, 0, 1, 0, 0, 55261), -- Virtuoso Inking Set
(223596, 29, 20815, 0, 0, 1, 0, 0, 55261), -- Jeweler's Toolset
(223596, 28, 6532, 0, 0, 1, 0, 0, 55261), -- Bright Baubles
(223596, 27, 6530, 0, 0, 1, 0, 0, 55261), -- Nightcrawlers
(223596, 26, 4400, 0, 0, 1, 0, 0, 55261), -- Heavy Stock
(223596, 25, 4399, 0, 0, 1, 0, 0, 55261), -- Wooden Stock
(223596, 24, 4289, 0, 0, 1, 0, 0, 55261), -- Salt
(223596, 23, 3371, 0, 0, 1, 0, 0, 55261), -- Crystal Vial
(223596, 22, 4340, 0, 0, 1, 0, 0, 55261), -- Gray Dye
(223596, 21, 4342, 0, 0, 1, 0, 0, 55261), -- Purple Dye
(223596, 20, 4341, 0, 0, 1, 0, 0, 55261), -- Yellow Dye
(223596, 19, 2325, 0, 0, 1, 0, 0, 55261), -- Black Dye
(223596, 18, 2604, 0, 0, 1, 0, 0, 55261), -- Red Dye
(223596, 17, 2324, 0, 0, 1, 0, 0, 55261), -- Bleach
(223596, 16, 3857, 0, 0, 1, 0, 0, 55261), -- Coal
(223596, 15, 160298, 0, 0, 1, 0, 0, 55261), -- Durable Flux
(223596, 14, 3466, 0, 0, 1, 0, 0, 55261), -- Strong Flux
(223596, 13, 2880, 0, 0, 1, 0, 0, 55261), -- Weak Flux
(223596, 12, 2678, 0, 0, 1, 0, 0, 55261), -- Mild Spices
(223596, 11, 14341, 0, 0, 1, 0, 0, 55261), -- Rune Thread
(223596, 10, 8343, 0, 0, 1, 0, 0, 55261), -- Heavy Silken Thread
(223596, 9, 4291, 0, 0, 1, 0, 0, 55261), -- Silken Thread
(223596, 8, 2321, 0, 0, 1, 0, 0, 55261), -- Fine Thread
(223596, 7, 2320, 0, 0, 1, 0, 0, 55261), -- Coarse Thread
(223596, 6, 6217, 0, 0, 1, 0, 0, 55261), -- Copper Rod
(223596, 5, 5956, 0, 0, 1, 0, 0, 55261), -- Blacksmith Hammer
(223596, 4, 6256, 0, 0, 1, 0, 0, 55261), -- Fishing Pole
(223596, 3, 2901, 0, 0, 1, 0, 0, 55261), -- Mining Pick
(223596, 2, 85663, 0, 0, 1, 0, 0, 55261), -- Herbalist's Spade
(223596, 1, 7005, 0, 0, 1, 0, 0, 55261); -- Skinning Knife

-- Mariner Everwatch smart ai
SET @ENTRY := 223460;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 3, 0, 0, 80, 22346000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #Mariner Everwatch #0 (22346000) (update out of combat)');

-- Timed list 22346000 smart ai
SET @ENTRY := 22346000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 743, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Set emote state to 743'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 13000, 13000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 13 seconds - Self: Set emote state to 0');

-- Path for Mariner Stillwake
SET @ENTRY := 223471;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Mariner Stillwake - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 26.02051, 7.3479, 11.85602, NULL, 0),
(@PATH, 1, 24.02002, 5.13269, 11.85602, NULL, 6513),
(@PATH, 2, 24.61279, -4.212036, 11.80343, NULL, 0),
(@PATH, 3, 25.00098, -7.122681, 11.85602, NULL, 0),
(@PATH, 4, 29.37598, -9.937744, 15.04989, NULL, 0),
(@PATH, 5, 33.51416, -10.32849, 17.84612, NULL, 0),
(@PATH, 6, 38.84619, -9.051758, 17.68892, NULL, 0),
(@PATH, 7, 40.92529, -4.958862, 17.69354, NULL, 8172),
(@PATH, 8, 38.75, 7.836548, 17.77995, NULL, 0),
(@PATH, 9, 35.51514, 9.309692, 17.83146, NULL, 0),
(@PATH, 10, 29.63916, 10.03577, 15.28821, NULL, 0),
(@PATH, 11, 26.01953, 7.3479, 11.85602, NULL, 0),
(@PATH, 12, 24.01904, 5.132813, 11.85602, NULL, 6657),
(@PATH, 13, 24.61182, -4.211792, 11.80341, NULL, 0);

UPDATE `creature` SET `position_x`= 26.02051, `position_y`= 7.3479, `position_z`= 11.85602, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+12, @PATH, 0);

-- Path for Mariner Softsong
SET @ENTRY := 223462;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Mariner Softsong - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -25.33398, -2.862061, 6.067297, 0.1254, 23756),
(@PATH, 1, -9.031738, -5.387207, 4.281772, NULL, 0),
(@PATH, 2, -1.157715, -5.617554, 4.902032, NULL, 0),
(@PATH, 3, 1.369141, -4.943115, 5.275206, NULL, 8288),
(@PATH, 4, -21.3833, -4.407837, 5.856016, NULL, 0);

UPDATE `creature` SET `position_x`= -25.33398, `position_y`= -2.862061, `position_z`= 6.067297, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+7;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+7, @PATH, 0);

-- Path for Mariner Everwatch
SET @ENTRY := 223460;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Mariner Everwatch - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8.838379, 5.444092, 4.294831, NULL, 0),
(@PATH, 1, -5.549316, 6.186035, 4.641192, NULL, 0),
(@PATH, 2, -3.063965, 7.110962, 4.766873, NULL, 5255),
(@PATH, 3, -26.80713, -0.02148438, 6.256016, 0.1254, 14102),
(@PATH, 4, -8.839355, 5.443848, 4.294807, NULL, 0);

UPDATE `creature` SET `position_x`= -8.838379, `position_y`= 5.444092, `position_z`= 4.294831, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+5, @PATH, 0);
