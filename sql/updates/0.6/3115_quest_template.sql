ALTER TABLE `quest_template` 
    ADD COLUMN `RewRepFaction3` int(11) unsigned NOT NULL default '0' AFTER `RewRepFaction2`,
    ADD COLUMN `RewRepFaction4` int(11) unsigned NOT NULL default '0' AFTER `RewRepFaction3`,
    ADD COLUMN `RewRepFaction5` int(11) unsigned NOT NULL default '0' AFTER `RewRepFaction4`,
    ADD COLUMN `RewRepValue3` int(11) NOT NULL default '0' AFTER `RewRepValue2`,
    ADD COLUMN `RewRepValue4` int(11) NOT NULL default '0' AFTER `RewRepValue3`,
    ADD COLUMN `RewRepValue5` int(11) NOT NULL default '0' AFTER `RewRepValue4`;
