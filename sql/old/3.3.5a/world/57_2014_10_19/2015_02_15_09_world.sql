--
DELETE FROM `gossip_menu` WHERE `entry`=40060;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(40060, 2494),
(40060, 2493);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=40060 AND `SourceEntry` IN (2494, 2493);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(14, 40060, 2494, 0, 0, 8, 0, 4023, 0, 0, 1, 0, 0, 'Show gossip text if player do not has quest 4023 completed'),
(14, 40060, 2493, 0, 1, 8, 0, 4022, 0, 0, 1, 0, 0, 'Show gossip text if player do not has quest 4022 completed');
