-- 
DELETE FROM `creature` WHERE `guid` IN (153,155);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(153,30272,571,0,0,1,1,0,0,7819.851074, 3738.652588, 653.378479, 1.181855,300,0,0,37800,0,0,0,0,0,"",0),
(155,30272,571,0,0,1,1,0,0,7793.105469, 3739.857178, 653.982361, 1.743578,300,0,0,37800,0,0,0,0,0,"",0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 30272 AND `SourceEntry` = 57401;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 30272, 57401, 0, 0, 9, 0, 13071, 0, 0, 0, 0, 0, "", 'spellclick "Njorndar Proto-Drake" requires quest "Vile Like Fire!" active');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=30564 AND `ConditionTypeOrReference`=23;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(16,0,30564,0,0,23,0,4526,0,0,0,0,0,'','Dismount player in not intended area'),
(16,0,30564,0,1,23,0,4496,0,0,0,0,0,'','Dismount player in not intended area');
