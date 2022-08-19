DROP TABLE IF EXISTS `gossip_menu_addon`;
CREATE TABLE `gossip_menu_addon` (
  `MenuID` INT UNSIGNED NOT NULL DEFAULT 0,
  `FriendshipFactionID` INT NOT NULL DEFAULT 0,
  `VerifiedBuild` INT NOT NULL DEFAULT 0,
  PRIMARY KEY (`MenuID`)
) ENGINE=INNODB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DELETE FROM `gossip_menu_addon` WHERE `MenuID` IN (13332, 13338, 13470, 13475, 13486, 13574, 13593, 13594, 13595);
INSERT INTO `gossip_menu_addon` (`MenuID`, `FriendshipFactionID`, `VerifiedBuild`) VALUES
(13332, 1283, 44908), -- 57298 (Farmer Fung)
(13338, 1279, 44908), -- 57402 (Haohan Mudclaw)
(13470, 1281, 44908), -- 58706 (Gina Mudclaw)
(13475, 1281, 44908), -- 58706 (Gina Mudclaw)
(13486, 1275, 44908), -- 58647 (Ella)
(13574, 1282, 44908), -- 58705 (Fish Fellreed)
(13593, 1280, 44908), -- 58761 (Tina Mudclaw)
(13594, 1277, 44908), -- 58709 (Chee Chee)
(13595, 1276, 44908); -- 58707 (Old Hillpaw)
