DROP TABLE IF EXISTS item_test;
CREATE TABLE item_test
SELECT w.`item_guid`,w.`source`,w.`count` FROM
  (SELECT u.`item_guid`,u.`source`,COUNT(u.`item_guid`) as `count` FROM
    ((SELECT c.`item`      as `item_guid`, 'i' as `source` FROM character_inventory c) UNION
     (SELECT a.`itemguid`  as `item_guid`, 'a' as `source` FROM auctionhouse        a) UNION
     (SELECT m.`item_guid` as `item_guid`, 'm' as `source` FROM mail_items          m) UNION
     (SELECT g.`item_guid` as `item_guid`, 'g' as `source` FROM guild_bank_item     g)
    ) as u
   GROUP BY u.`item_guid`
  ) as w
 WHERE w.`count` > 1;

DELETE FROM auctionhouse    WHERE itemguid  IN (SELECT item_guid FROM item_test WHERE `source`='i');
DELETE FROM mail_items      WHERE item_guid IN (SELECT item_guid FROM item_test WHERE `source`='i');
DELETE FROM guild_bank_item WHERE item_guid IN (SELECT item_guid FROM item_test WHERE `source`='i');

DELETE FROM mail_items      WHERE item_guid IN (SELECT item_guid FROM item_test WHERE `source`='a');
DELETE FROM guild_bank_item WHERE item_guid IN (SELECT item_guid FROM item_test WHERE `source`='a');

DELETE FROM guild_bank_item WHERE item_guid IN (SELECT item_guid FROM item_test WHERE `source`='m');
DROP TABLE IF EXISTS item_test;
