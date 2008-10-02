ALTER TABLE `item_page` RENAME TO `page_text`;
ALTER TABLE `page_text` ENGINE = MyISAM;

ALTER TABLE `page_text`
  DROP PRIMARY KEY,
  CHANGE COLUMN `id` `entry` int(11) NOT NULL default '0',
  ADD PRIMARY KEY (`entry`);
