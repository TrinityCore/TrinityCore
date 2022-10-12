UPDATE `item_instance` SET `owner_guid` = 0 WHERE guid in (SELECT `itemguid` FROM `auctionhouse`);
UPDATE `item_instance` SET `owner_guid` = 0 WHERE guid in (SELECT `item_guid` FROM `mail_items`);