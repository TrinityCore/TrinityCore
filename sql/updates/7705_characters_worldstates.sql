ALTER TABLE `saved_variables` CHANGE `NextArenaPointDistributionTime` `value` bigint(40) UNSIGNED NOT NULL DEFAULT '0',
ADD COLUMN `entry` mediumint(11) UNSIGNED NOT NULL DEFAULT '0' FIRST,
ADD COLUMN `comment` text NOT NULL,
ADD PRIMARY KEY  (`entry`),
RENAME `worldstates`,
ROW_FORMAT=DYNAMIC;

-- Only posible value is NextArenaPointDistributionTime so make the conversion to custom worldstate
UPDATE `worldstates` SET `entry`=20001, `comment`='NextArenaPointDistributionTime';
