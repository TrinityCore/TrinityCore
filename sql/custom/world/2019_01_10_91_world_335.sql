
-- remove price for no experience npcs
UPDATE `gossip_menu_option`
SET `BoxMoney` = 0
WHERE `MenuID` = 10638
