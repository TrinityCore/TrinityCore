SET @CGUID := 9004104;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 209303, 0, 1519, 1519, '0', 0, 0, 0, 0, -8804.6005859375, 341.430572509765625, 99.46265411376953125, 5.699672698974609375, 120, 0, 0, 90335, 7196, 0, NULL, NULL, NULL, NULL, 52106); -- Jaxos Widdowson (Area: Stormwind City - Difficulty: 0) CreateObject1

-- Update new positions after Patch 10.2
UPDATE `creature` SET `position_x`= -8802.9599609375, `position_y` = 332.375, `position_z` = 107.1673355102539062, `orientation` = 3.299901008605957031 WHERE `guid` = 1052058; -- Frazzle Frostfingers
UPDATE `creature` SET `position_x`= -8804.91015625, `position_y` = 331.1319580078125, `position_z` = 107.1396484375, `orientation` = 1.639717817306518554 WHERE `guid` = 1052063; -- Laphandrus Voidheart
UPDATE `creature` SET `position_x`= -8810.9970703125, `position_y` = 336.326385498046875, `position_z` = 107.1321945190429687, `orientation` = 1.808167099952697753 WHERE `guid` = 1052047; -- Patrice Lancaster
UPDATE `creature` SET `position_x`= -8814.533203125, `position_y` = 340.276031494140625, `position_z` = 107.1314926147460937, `orientation` = 0.209478929638862609 WHERE `guid` = 1052057; -- Juisheng Halfclaw
UPDATE `creature` SET `position_x`= -8815.185546875, `position_y` = 344.90972900390625, `position_z` = 107.1316757202148437, `orientation` = 5.420800209045410156 WHERE `guid` = 1052046; -- Ezul'aan
UPDATE `creature` SET `position_x`= -8812.873046875, `position_y` = 345.680572509765625, `position_z` = 107.1321029663085937, `orientation` = 4.674129009246826171 WHERE `guid` = 1052064; -- Veruca Darkstream
UPDATE `creature` SET `position_x`= -8802.8193359375, `position_y` = 352.713531494140625, `position_z` = 109.5107574462890625, `orientation` = 4.305622577667236328 WHERE `guid` = 1052054; -- Elton Campbell
UPDATE `creature` SET `position_x`= -8799.296875, `position_y` = 348.37847900390625, `position_z` = 109.2069931030273437, `orientation` = 3.694152116775512695 WHERE `guid` = 1052055; -- Gilda Silvershield
UPDATE `creature` SET `position_x`= -8819.3056640625, `position_y` = 353.748260498046875, `position_z` = 107.1325225830078125, `orientation` = 0.662197113037109375 WHERE `guid` = 1052061; -- Mithlos Falconbriar
UPDATE `creature` SET `position_x`= -8817.2724609375, `position_y` = 355.432281494140625, `position_z` = 107.132476806640625, `orientation` = 3.80734109878540039 WHERE `guid` = 1052049; -- Mulric Boldrock
UPDATE `creature` SET `position_x`= -8800.611328125, `position_y` = 349.81597900390625, `position_z` = 99.46265411376953125, `orientation` = 4.103053092956542968 WHERE `guid` = 1052065; -- Evelyn Thorn
UPDATE `creature` SET `position_x`= -8791.2236328125, `position_y` = 347.607635498046875, `position_z` = 117.718292236328125, `orientation` = 4.452894210815429687 WHERE `guid` = 1052060; -- Amaria Wildthorn
UPDATE `creature` SET `position_x`= -8806.470703125, `position_y` = 325.88714599609375, `position_z` = 115.5490188598632812, `orientation` = 2.353574037551879882 WHERE `guid` = 1052056; -- Katrina Long

-- Template
UPDATE `creature_template` SET `faction`=3011, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=209303; -- Jaxos Widdowson
UPDATE `creature_template` SET `faction`=12, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=199145; -- R'mortos the Shining Shadow

-- Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (164947, 164945, 164941, 164955, 164962, 164953, 164954);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(164947, 0, 0, 0, 0, 0, 0, 0, 720, 0, 0, 0, 0, ''), -- Gerald Black
(164945, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 164945 (Mulric Boldrock)
(164941, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 164941 (Laphandrus Voidheart)
(164955, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 164955 (Frazzle Frostfingers)
(164962, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 164962 (Mithlos Falconbriar)
(164953, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '121801'); -- 164953 (Katrina Long) - Meditate

-- Difficulty & Model
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=209303 AND `DifficultyID`=0);
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(209303, 0, 0, 0, 865, 9, 1, 1, 238552, 0, 0, 52106); -- Jaxos Widdowson

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52106 WHERE (`DifficultyID`=0 AND `Entry` IN (51348,61081,62954,918,284,43694,12787,164947,164946,12786,164945,12785,12784,1976,54660,35845,12783,164943,8383,175051,164942,164941,12781,164940,12780,44252,12779,164939,146633,14559,19848,14561,167429,73190,14560,44246,52030,44245,43693,52029,32520,111190,163007,49540,164962,164961,164960,164957,4269,1326,164956,198629,199149,164955,308,164954,69975,69974,164953,164952,31146,153292,199145,58154,114832,164950,62913,164949,6946,164948));

DELETE FROM `creature_model_info` WHERE `DisplayID`=113855;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(113855, 0.6987152099609375, 1.5, 0, 52106);
