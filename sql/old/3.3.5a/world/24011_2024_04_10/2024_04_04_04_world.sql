-- Gest, correct gossip text when "Elegant Letter" is available
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=4513 AND `TextID` IN (5993,5996);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES (4513,5993);
-- Condition
UPDATE `conditions` SET `SourceEntry`=5993 WHERE `SourceGroup`=4513 AND `SourceEntry`=5996;
