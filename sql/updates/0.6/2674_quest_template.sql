alter table quest_template
add column 
  `OfferRewardEmote` int(11) unsigned NOT NULL default '0';

alter table quest_template
add column 
  `RequestItemsEmote` int(11) unsigned NOT NULL default '1';

alter table quest_template
add column 
  `CompleteScript` int(11) unsigned NOT NULL default '0';
