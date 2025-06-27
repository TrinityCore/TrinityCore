--
DELETE FROM `gossip_menu` WHERE `entry`=4519 AND `text_id`=12696;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(4519, 12696, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4519 AND `SourceEntry`=12696;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 4519, 12696, 0, 0, 8, 0, 12085, 0, 0, 0, 0, 0, "", "Show gossip text if quest A Letter for Home is not rewarded");
