ALTER TABLE `quest_template` CHANGE `RequiredRepFaction` `RequiredMinRepFaction` int(10) unsigned NOT NULL default '0';
ALTER TABLE `quest_template` CHANGE `RequiredRepValue` `RequiredMinRepValue` int(10) NOT NULL default '0';
ALTER TABLE `quest_template` ADD `RequiredMaxRepFaction` int(10) unsigned NOT NULL default '0' AFTER `RequiredMinRepValue` ;
ALTER TABLE `quest_template` ADD `RequiredMaxRepValue` int(10) NOT NULL default '0' AFTER `RequiredMaxRepFaction` ;
