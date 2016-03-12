--
DELETE FROM `gossip_menu` WHERE `entry`=6024 AND `text_id`=6935;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6024, 6935);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14) AND `SourceGroup`=6024;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14, 6024, 7176, 0, 8, 7783, 0, 0, 0, '', 'Show gossip text if player get the quest The Lord of Blackrockreward', 0),
(14, 6024, 6935, 0, 8, 7783, 0, 0, 0, '', 'Show gossip text if te quest The Lord of Blackrock is not rewarded', 1);
