-- Uncomment this query if the ALTER query gives you primary key violation errors
-- SET @item_guid := (SELECT `item_guid` FROM `mail_items` GROUP BY `item_guid` HAVING COUNT(`item_guid`) > 1);
-- DELETE FROM `mail_items` WHERE `item_guid` IN (@item_guid);

ALTER TABLE `mail_items`
DROP PRIMARY KEY,
ADD PRIMARY KEY(`item_guid`),
ADD KEY `idx_mail_id` (`mail_id`);
