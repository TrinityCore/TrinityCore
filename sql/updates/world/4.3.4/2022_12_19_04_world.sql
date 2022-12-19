UPDATE `gossip_menu_option` SET `OptionType`= 1 WHERE `MenuID`= 12646;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=12646 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`, `NegativeCondition`, `ScriptName`,`Comment`) VALUES
(15, 12646, 1, 0, 0, 13, 0, 1, 3, 2, 0, 0, "", "Show gossip if Anraphet or Earthrager Ptah have been defeated"),
(15, 12646, 1, 0, 1, 13, 0, 2, 3, 2, 0, 0, "", "Show gossip if Anraphet or Earthrager Ptah have been defeated"),
(15, 12646, 2, 0, 0, 13, 0, 3, 3, 2, 0, 0, "", "Show gossip if the Constructs of the Four Seats have been defeated"),
(15, 12646, 2, 0, 0, 13, 0, 4, 3, 2, 0, 0, "", "Show gossip if the Constructs of the Four Seats have been defeated"),
(15, 12646, 2, 0, 0, 13, 0, 5, 3, 2, 0, 0, "", "Show gossip if the Constructs of the Four Seats have been defeated"),
(15, 12646, 2, 0, 0, 13, 0, 6, 3, 2, 0, 0, "", "Show gossip if the Constructs of the Four Seats have been defeated");
