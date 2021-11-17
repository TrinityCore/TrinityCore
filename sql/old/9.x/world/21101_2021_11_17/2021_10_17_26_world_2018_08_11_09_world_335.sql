-- Evidence Marker --> Add missing spawns
-- SET @GUID1 := 38851;
-- SET @GUID2 := 42847;
-- SET @GUID3 := 42850;
-- DELETE FROM `creature` WHERE `guid` IN (@GUID1,@GUID2,@GUID3);
-- INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
-- (@GUID1,23583,1,0,0,1,1,0,0,-3700.58,-2534.09,68.7248,3.05433,300,0,0,41,0,0,0,0,0,"",0),
-- (@GUID2,23583,1,0,0,1,1,0,0,-3721.85,-2541.17,69.7589,3.05433,300,0,0,41,0,0,0,0,0,"",0),
-- (@GUID3,23583,1,0,0,1,1,0,0,-3734.45,-2530.79,73.2862,3.30957,300,0,0,41,0,0,0,0,0,"",0);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=23567;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(23567,1,1,2,0);

-- Fix "Reflective Dust"
UPDATE `creature_template_addon` SET `auras`="42171 42175" WHERE `entry`=23583;

-- Fix rotation for some objects
-- restore 3.3.5 guids
DELETE FROM `gameobject` WHERE `id` IN (21042,20992);
DELETE FROM `gameobject` WHERE `guid` IN (6376,6821);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(6376,21042,1,15,403,'0',0,0,-3721.850341796875,-2541.166259765625,69.7589111328125,0,0.556656837463378906,-0.43478775024414062,0.431009292602539062,0.561536967754364013,120,255,1,40593), -- Theramore Guard Badge
(6821,20992,1,15,403,'0',0,0,-3734.911376953125,-2530.625,73.28624725341796875,5.480335712432861328,-0.10538148880004882,0.677423477172851562,0.042206764221191406,0.726781070232391357,120,255,1,40593); -- Black Shield

-- Add condition for Inspector Tarem's gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8761;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8761,0,0,0,8,0,11123,0,0,0,0,0,"","Show gossip option if quest 'Inspecting the Ruins' is rewarded"),
(15,8761,0,0,1,8,0,11124,0,0,0,0,0,"","Show gossip option if quest 'Inspecting the Ruins' is rewarded");
