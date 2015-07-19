SET @CGUID := 75064;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3 AND `id`=24921;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 24921, 603, 3, 1, 1437.423, 117.3453, 425.8442, 0, 7200, 0, 0), -- 24921 (Area: 0) (Auras: )
(@CGUID+1, 24921, 603, 3, 1, 1437.352, 115.7263, 425.8618, 0, 7200, 0, 0), -- 24921 (Area: 0) (Auras: )
(@CGUID+2, 24921, 603, 3, 1, 1437.107, 118.4796, 425.813, 0, 7200, 0, 0), -- 24921 (Area: 0) (Auras: )
(@CGUID+3, 24921, 603, 3, 1, 1436.955, 118.8366, 425.8709, 0, 7200, 0, 0); -- 24921 (Area: 0) (Auras: )

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(64201,64229);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 64201, 0, 0, 31, 0, 3, 24921, 0, 0, 0, 0, '', 'Sunbeam Targets Cosmetic Trigger - LAB'),
(13, 1, 64229, 0, 0, 31, 0, 3, 24921, 0, 0, 0, 0, '', 'Iron Roots Targets Cosmetic Trigger - LAB');
