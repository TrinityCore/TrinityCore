--
DELETE FROM `gossip_menu` WHERE `entry`=24 and `text_id`=521;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(24, 521);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=24 AND `SourceEntry`=521;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 24, 521, 0, 0, 8, 0, 770, 0, 0, 0, 0, 0, '', 'Show gossip text if player has quest 770 completed');
