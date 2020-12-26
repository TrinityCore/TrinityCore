-- 
DELETE FROM `gossip_menu` WHERE `MenuId`=8558 AND `textid`=10722;
INSERT INTO `gossip_menu` (`MenuId`,`textid`) VALUES
(8558,10722);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (8558,8560);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,8558,7778,0,0,5,0,932,16,0,0,0,0,'',"Show gossip text if player is Friendly with The Aldor"),
(14,8558,10722,0,0,5,0,932,16,0,1,0,0,'',"Show gossip text if player is not Friendly with The Aldor"),
(14,8560,7778,0,0,5,0,934,16,0,0,0,0,'',"Show gossip text if player is Friendly with The Scryers"),
(14,8560,10723,0,0,5,0,934,16,0,1,0,0,'',"Show gossip text if player is not Friendly with The Scryers"),
(15,8558,0,0,0,5,0,932,16,0,0,0,0,'',"Show gossip menu option if player is Friendly with The Aldor"),
(15,8560,0,0,0,5,0,934,16,0,0,0,0,'',"Show gossip menu option if player is Friendly with The Scryers");
