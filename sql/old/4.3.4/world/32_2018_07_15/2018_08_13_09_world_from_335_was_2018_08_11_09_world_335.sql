/*
-- Evidence Marker --> Add missing spawns
SET @GUID1 := 38851;
SET @GUID2 := 42847;
SET @GUID3 := 42850;
DELETE FROM `creature` WHERE `guid` IN (@GUID1,@GUID2,@GUID3);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID1,23583,1,0,0,1,1,0,0,-3700.58,-2534.09,68.7248,3.05433,300,0,0,41,0,0,0,0,0,"",0),
(@GUID2,23583,1,0,0,1,1,0,0,-3721.85,-2541.17,69.7589,3.05433,300,0,0,41,0,0,0,0,0,"",0),
(@GUID3,23583,1,0,0,1,1,0,0,-3734.45,-2530.79,73.2862,3.30957,300,0,0,41,0,0,0,0,0,"",0);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=23567;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(23567,1,1,2,0);

-- Fix "Reflective Dust"
UPDATE `creature_template_addon` SET `auras`="42171 42175" WHERE `entry`=23583;

-- Fix rotation for some objects
UPDATE `gameobject` SET `rotation0`=0.556657, `rotation1`=-0.434788, `rotation2`=0.43101, `rotation3`=0.561536 WHERE `guid`=6376; -- Theramore Guard Badge
UPDATE `gameobject` SET `rotation0`=-0.105384, `rotation1`=0.677422, `rotation2`=0.042204, `rotation3`=0.726783 WHERE `guid`=6821; -- Black Shield

-- Add condition for Inspector Tarem's gossip option
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=8761;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,8761,0,0,0,8,0,11123,0,0,0,0,0,"","Show gossip option if quest 'Inspecting the Ruins' is rewarded"),
(15,8761,0,0,1,8,0,11124,0,0,0,0,0,"","Show gossip option if quest 'Inspecting the Ruins' is rewarded");
*/
