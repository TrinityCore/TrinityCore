-- Druid
SET @CLASS_MASK := 1024;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`= 11829;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,11829,16586,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip text if player is a Druid'),
(14,11829,14835,0,0,15,0,@CLASS_MASK,0,0,'',1,0,0,'','Show gossip text if player is not a Druid'),
(15,11829,0,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid'),
(15,11829,1,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid'),
(15,11829,2,0,0,15,0,@CLASS_MASK,0,0,'',0,0,0,'','Show gossip option if player is a Druid');

DELETE FROM `creature_trainer` WHERE `CreatureID`=44396 AND `MenuID`=11829;
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(44396, 39, 11829, 0);

DELETE FROM `creature` WHERE `guid` IN (397104, 314382, 314388, 314386, 314381, 314387, 313860);
DELETE FROM `creature_addon` WHERE `guid` IN (397104, 314382, 314388, 314386, 314381, 314387, 313860);

SET @CGUID := 3990082;
SET @OGUID := 3990012;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 44807, 0, 1519, 5397, '0', '0', 0, 0, 0, -8062.85986328125, 819.364990234375, 67.048736572265625, 3.351032257080078125, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Farmer Wollerton (Area: The Wollerton Stead - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 2442, 0, 1519, 5397, '0', '0', 0, 0, 0, -8025.3701171875, 810.4310302734375, 65.391937255859375, 3.159045934677124023, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Cow (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@CGUID+2, 2442, 0, 1519, 5397, '0', '0', 0, 0, 0, -8042.52978515625, 818.62799072265625, 68.01163482666015625, 4.15388345718383789, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Cow (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@CGUID+3, 2442, 0, 1519, 5397, '0', '0', 0, 0, 0, -8039.080078125, 806.35101318359375, 67.30403900146484375, 4.188790321350097656, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Cow (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@CGUID+4, 2442, 0, 1519, 5397, '0', '0', 0, 0, 0, -8030.12548828125, 818.1346435546875, 65.729522705078125, 5.28196573257446289, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Cow (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@CGUID+5, 2442, 0, 1519, 5397, '0', '0', 0, 0, 0, -8054.85986328125, 814.780029296875, 67.2454376220703125, 3.525565147399902343, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Cow (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@CGUID+6, 5504, 0, 1519, 4411, '0', '0', 0, 0, 1, -8575.11328125, 1246.201416015625, 5.313568115234375, 4.729842185974121093, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 55141), -- Sheldras Moontree (Area: Stormwind Harbor - Difficulty: 0) CreateObject1
(@CGUID+7, 54441, 0, 1519, 5704, '0', '0', 0, 0, 1, -8693.5244140625, 843.61285400390625, 99.003082275390625, 2.809980154037475585, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564); -- Thaumaturge Vashreen (Area: The Catacombs - Difficulty: 0) CreateObject1


DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Farmer Wollerton
(@CGUID+6, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Sheldras Moontree

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 3799, 0, 1519, 5397, '0', '0', 0, -8054.3046875, 834.66717529296875, 67.52725982666015625, 1.139281392097473144, 0, 0, 0.53932952880859375, 0.842094838619232177, 120, 255, 1, 57564), -- Cozy Fire (Area: The Wollerton Stead - Difficulty: 0) CreateObject1
(@OGUID+1, 3800, 0, 1519, 5397, '0', '0', 0, -8054.9443359375, 835.29254150390625, 67.52725982666015625, 2.430821418762207031, 0, 0, 0.937512397766113281, 0.347951859235763549, 120, 255, 1, 57564); -- Cozy Fire (Area: The Wollerton Stead - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.33975598216056823, 0.94051361083984375, 0, 0), -- Cozy Fire
(@OGUID+1, 0, 0, -0.33975598216056823, 0.94051361083984375, 0, 0); -- Cozy Fire

UPDATE `creature_template` SET `npcflag`=268435456 WHERE `entry`=54442; -- Warpweaver Hashom
DELETE FROM `creature_template_gossip` WHERE `CreatureID`= 54442;
