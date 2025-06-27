-- 
DELETE FROM `creature` WHERE `guid` IN (91799);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(91799, 15353, 0, 1, 1, 0, 0, -4918.64, -983.141, 501.538, 2.43867, 120, 0, 0);

DELETE FROM `game_event_creature` WHERE `guid` IN (91799) AND `eventEntry`=12;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES (12,91799);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=15353 AND `SourceEntry`=20557; 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 15353, 20557, 0, 0, 8, 0, 8311, 0, 0, 0, 0, 0, "", "Item Hallow's End Pumpkin Treat sold by Katrina Shimmerstar requires quest Hallow's End Treats for Jesper! rewarded");
