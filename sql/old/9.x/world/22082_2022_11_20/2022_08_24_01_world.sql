SET @CGUID := 460682;
SET @OGUID := 395672;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 70859, 1116, 7004, 0, '0', 3196, 0, 0, 1, 5611.7099609375, 4525.859375, 120.2640228271484375, 0.194926872849464416, 7200, 0, 0, 2955600, 320750, 0, 0, 0, 0, 45114), -- Thrall (Area: 0 - Difficulty: 0)
(@CGUID+1, 76411, 1116, 7004, 0, '0', 3196, 0, 0, 0, 5611.736328125, 4533.6083984375, 121.02215576171875, 6.025817394256591796, 7200, 0, 0, 24630, 0, 0, 0, 0, 0, 45114), -- Farseer Drek'Thar (Area: 0 - Difficulty: 0)
(@CGUID+2, 78288, 1116, 7004, 0, '0', 3196, 0, 0, 1, 5612.44970703125, 4523.4912109375, 119.755645751953125, 0.29847005009651184, 7200, 0, 0, 19710, 9573, 0, 0, 0, 0, 45114), -- Archmage Khadgar (Area: 0 - Difficulty: 0)
(@CGUID+3, 78272, 1116, 7004, 0, '0', 3331, 0, 0, 1, 5610.61962890625, 4521.2412109375, 119.8433837890625, 0.209163606166839599, 7200, 0, 0, 738900, 0, 0, 0, 0, 0, 45114), -- Durotan (Area: 0 - Difficulty: 0)
(@CGUID+4, 78466, 1116, 7004, 7004, '0', 3197, 0, 0, 1, 5628.99658203125, 4525.7666015625, 119.05975341796875, 2.934297561645507812, 7200, 0, 0, 3325, 0, 0, 0, 0, 0, 45114); -- Gazlowe (Area: -Unknown- - Difficulty: 0)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 229057, 1116, 7004, 7004, '0', 3427, 0, 5630.2197265625, 4529.671875, 119.0678482055664062, 3.66789412498474121, 0, 0, -0.96557521820068359, 0.260124027729034423, 7200, 255, 1, 45114); -- Horde Banner (Area: -Unknown- - Difficulty: 0)

-- Phasing
DELETE FROM `phase_area` WHERE (`AreaId` = 7004 AND `PhaseId` IN (3196, 3331, 3427, 3197));
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7004, 3196, 'Cosmetic - Iconics at Garrison Location'),
(7004, 3331, 'Cosmetic - Durotan at Garrison Location'),
(7004, 3427, 'Frostfire Ridge Intro - Horde'),
(7004, 3197, 'Cosmetic - Gazlowe at Initial Garrison Location');

-- Conditon
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3196 AND `SourceEntry` = 7004) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3331 AND `SourceEntry` = 7004) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3427 AND `SourceEntry` = 7004) OR (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 3197 AND `SourceEntry` = 7004) OR (`SourceTypeOrReferenceId` = 32 AND `SourceGroup` = 8 AND `SourceEntry` = 229057);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3196, 7004, 0, 0, 47, 0, 34402, 2 | 64, 0, 0, 'Apply Phase 3196 If Quest    IS complete / rewarded'),
(26, 3331, 7004, 0, 0, 47, 0, 34402, 2 | 64, 0, 0, 'Apply Phase 3331 If Quest 34402 IS complete / rewarded'),
(26, 3331, 7004, 0, 0, 47, 0, 34364, 64, 0, 1, 'Apply Phase 3331 if Quest 34364 is NOT rewarded'),
(26, 3427, 7004, 0, 0, 47, 0, 34378, 64, 0, 1, 'Apply Phase 3427 If Quest 34378 IS NOT rewarded'),
(26, 3197, 7004, 0, 0, 47, 0, 34364, 2 | 64, 0, 0, 'Apply Phase 3197 If Quest 34364 IS complete / rewarded'),
-- Horde Banner Gob
(32, 8, 229057, 0, 0, 47, 0, 34364, 2 | 8 | 64, 0, 0, 'Horde Banner gets visible if Quest: 34364 is in Progress / complete / rewarded');

DELETE FROM `gossip_menu` WHERE (`MenuID`=16271 AND `TextID`=23530);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(16271, 23530, 45114); -- 76411 (Farseer Drek'Thar)

UPDATE `creature_template` SET `gossip_menu_id`=16271 WHERE `entry`=76411; -- Farseer Drek'Thar
