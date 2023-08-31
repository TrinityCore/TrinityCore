DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=53110;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,1,53110,0,31,3,29102,'Devour Humanoid - target Hearthglen Crusader'),
(13,1,53110,1,31,3,29103,'Devour Humanoid - target Tirisfal Crusader');
