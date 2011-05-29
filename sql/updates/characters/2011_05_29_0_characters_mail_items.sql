-- Uncomment this query if the second query gives you primary key violation errors
-- DELETE FROM `mail_items` WHERE `item_guid` IN (SELECT `item_guid` FROM `mail_items` GROUP BY `item_guid` HAVING COUNT(`item_guid`) > 1);

ALTER TABLE `mail_items`
DROP PRIMARY KEY,
ADD PRIMARY KEY(`item_guid`),
ADD KEY `idx_mail_id` (`mail_id`);
