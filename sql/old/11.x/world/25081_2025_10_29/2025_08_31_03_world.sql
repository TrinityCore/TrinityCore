UPDATE `gameobject_template` SET `scriptname` = 'go_master_surveyor' WHERE `entry` = 233664;

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 25 AND `SourceGroup` = 0 AND `SourceEntry` = 1152;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(25, 0, 1152, 0, 0, 47, 0, 36793, 66, 0, 0, 'TerrainSwap to 1152 if Quest: 36793 is complete/rewarded');

-- Spawntracking
DELETE FROM `spawn_tracking` WHERE `SpawnTrackingId`=920544;
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveIds`) VALUES
(920544, 1, 395673, '272928');

DELETE FROM `spawn_tracking_state` WHERE `SpawnType`=1 AND `SpawnId`=920544;
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, 920544, 0, 0, NULL, NULL, NULL, NULL),
(1, 920544, 1, 1, NULL, NULL, NULL, NULL),
(1, 920544, 2, 0, NULL, NULL, NULL, NULL);
