-- Champion Cyssa Dawnrose --> Fix gossip text
DELETE FROM `gossip_menu` WHERE `MenuID`=8111 AND `TextID` IN (10040,10044);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8111,10044,0);

UPDATE `conditions` SET `SourceEntry`=10044 WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=8111 AND `SourceEntry`=10040;
