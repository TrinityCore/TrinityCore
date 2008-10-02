ALTER TABLE `quest_template` ADD `StartScript` int(11) unsigned NOT NULL default '0' AFTER `OfferRewardEmote4`;
ALTER TABLE `scripts` ADD `StartOrFinish` int(11) unsigned NOT NULL default '0';
