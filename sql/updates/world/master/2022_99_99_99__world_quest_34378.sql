UPDATE `gameobject_template` SET `scriptname` = 'go_master_surveyor' WHERE `entry` = 233664;

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 25 AND `SourceGroup` = 0 AND `SourceEntry` = 1152;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(25, 0, 1152, 0, 0, 47, 0, 36793, 66, 0, 0, 'TerrainSwap to 1152 if Quest: 36793 is complete/rewarded');
