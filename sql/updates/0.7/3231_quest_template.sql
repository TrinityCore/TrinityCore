ALTER TABLE `quest_template` ADD COLUMN `ReqSourceCount1` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceId4`;
ALTER TABLE `quest_template` ADD COLUMN `ReqSourceCount2` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceCount1`;
ALTER TABLE `quest_template` ADD COLUMN `ReqSourceCount3` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceCount2`;
ALTER TABLE `quest_template` ADD COLUMN `ReqSourceCount4` int(11) unsigned NOT NULL default '0' AFTER `ReqSourceCount3`;

UPDATE `quest_template` SET `ReqSourceCount1`='1' WHERE `ReqSourceId1`!='0';
UPDATE `quest_template` SET `ReqSourceCount2`='1' WHERE `ReqSourceId2`!='0';
UPDATE `quest_template` SET `ReqSourceCount3`='1' WHERE `ReqSourceId3`!='0';
UPDATE `quest_template` SET `ReqSourceCount4`='1' WHERE `ReqSourceId4`!='0';