ALTER TABLE `corpse`
 ADD COLUMN `displayId` int(10) unsigned NOT NULL default '0' AFTER `phaseMask`,
 ADD COLUMN `itemCache` text NOT NULL AFTER `displayId`,
 ADD COLUMN `bytes1` int(10) unsigned NOT NULL default '0' AFTER `itemCache`,
 ADD COLUMN `bytes2` int(10) unsigned NOT NULL default '0' AFTER `bytes1`,
 ADD COLUMN `guild` int(10) unsigned NOT NULL default '0' AFTER `bytes2`,
 ADD COLUMN `flags` int(10) unsigned NOT NULL default '0' AFTER `guild`,
 ADD COLUMN `dynFlags` int(10) unsigned NOT NULL default '0' AFTER `flags`;

UPDATE `corpse` SET
`displayId` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',10))+2,
length(SUBSTRING_INDEX(`data`,' ',10+1))-length(SUBSTRING_INDEX(data,' ',10))-1),

`itemCache` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',11))+2,
length(SUBSTRING_INDEX(`data`,' ',29+1))-length(SUBSTRING_INDEX(data,' ',11))-1),

`bytes1` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',30))+2,
length(SUBSTRING_INDEX(`data`,' ',30+1))-length(SUBSTRING_INDEX(data,' ',30))-1),

`bytes2` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',31))+2,
length(SUBSTRING_INDEX(`data`,' ',31+1))-length(SUBSTRING_INDEX(data,' ',31))-1),

`guild` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',32))+2,
length(SUBSTRING_INDEX(`data`,' ',32+1))-length(SUBSTRING_INDEX(data,' ',32))-1),

`flags` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',33))+2,
length(SUBSTRING_INDEX(`data`,' ',33+1))-length(SUBSTRING_INDEX(data,' ',33))-1),

`dynFlags` = SUBSTRING(`data`,
length(SUBSTRING_INDEX(`data`,' ',34))+2,
length(SUBSTRING_INDEX(`data`,' ',34+1))-length(SUBSTRING_INDEX(data,' ',34))-1);

ALTER TABLE `corpse` DROP `data`;
