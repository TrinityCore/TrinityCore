alter table quest_template
   add column
  `HaveQuestId` int(11) unsigned NOT NULL default '0';

alter table quest_template
  change column `IncompleteText` `RequestItemsText` text;

alter table quest_template
  change column `CompletionText` `OfferRewardText` text;

alter table quest_template
   add column
  `Repeatable` int(11) unsigned NOT NULL default '0';
