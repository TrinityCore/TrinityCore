UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 12671) AND (`TextID` = 17817);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 12580) AND (`TextID` = 17690);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 12579) AND (`TextID` = 17687);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 12479) AND (`TextID` = 17556);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 12463) AND (`TextID` = 17531);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 11809) AND (`TextID` = 16558);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 10817) AND (`TextID` = 14995);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 10684) AND (`TextID` = 14808);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 10552) AND (`TextID` = 14600);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 10135) AND (`TextID` = 14071);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 10127) AND (`TextID` = 14061);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 9486) AND (`TextID` = 12758);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 4270) AND (`TextID` = 5440);
UPDATE `gossip_menu` SET `VerifiedBuild` = 15005 WHERE (`MenuID` = 2783) AND (`TextID` = 3471);
  
DELETE FROM `gossip_menu` WHERE (`MenuId`=10708 AND `TextId`=15006) OR (`MenuId`=10960 AND `TextId`=15232) OR (`MenuId`=10985 AND `TextId`=15262) OR (`MenuId`=11645 AND `TextId`=15262) OR (`MenuId`=12532 AND `TextId`=15000);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(10708, 15006, 15005), -- 35917 (Kilag Gorefang)
(10960, 15232, 15005), -- 38015 (Karthog)
(10985, 15262, 15005), -- 38244 (Legati)
(11645, 15262, 15005), -- 42618 (Voldreka)
(12532, 15000, 15005); -- 49902 (Warrior-Matic NX-01)
