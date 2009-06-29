ALTER TABLE quest_template
  ADD COLUMN `DetailsEmoteDelay1` int(11) unsigned NOT NULL default '0' AFTER `DetailsEmote4`,
  ADD COLUMN `DetailsEmoteDelay2` int(11) unsigned NOT NULL default '0' AFTER `DetailsEmoteDelay1`,
  ADD COLUMN `DetailsEmoteDelay3` int(11) unsigned NOT NULL default '0' AFTER `DetailsEmoteDelay2`,
  ADD COLUMN `DetailsEmoteDelay4` int(11) unsigned NOT NULL default '0' AFTER `DetailsEmoteDelay3`,
  ADD COLUMN `OfferRewardEmoteDelay1` int(11) unsigned NOT NULL default '0' AFTER `OfferRewardEmote4`,
  ADD COLUMN `OfferRewardEmoteDelay2` int(11) unsigned NOT NULL default '0' AFTER `OfferRewardEmoteDelay1`,
  ADD COLUMN `OfferRewardEmoteDelay3` int(11) unsigned NOT NULL default '0' AFTER `OfferRewardEmoteDelay2`,
  ADD COLUMN `OfferRewardEmoteDelay4` int(11) unsigned NOT NULL default '0' AFTER `OfferRewardEmoteDelay3`;