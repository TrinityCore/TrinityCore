DELETE FROM `access_requirement` WHERE `item` IN (30637, 30623, 30634, 30633);

DELETE FROM `access_requirement` WHERE `mapId`=560 AND `item`=30635;
UPDATE `access_requirement` SET `item`=0 WHERE `mapId`=269 AND `difficulty`=1;
