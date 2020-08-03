ALTER TABLE `auctionhouse`
  CHANGE `buyoutprice` `buyoutprice` bigint(20) unsigned NOT NULL DEFAULT '0',
  CHANGE `lastbid` `lastbid` bigint(20) unsigned NOT NULL DEFAULT '0',
  CHANGE `startbid` `startbid` bigint(20) unsigned NOT NULL DEFAULT '0',
  CHANGE `deposit` `deposit` bigint(20) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `guild_member_withdraw` CHANGE `money` `money` bigint(20) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `guild_bank_eventlog` CHANGE `ItemOrMoney` `ItemOrMoney` bigint(20) unsigned NOT NULL DEFAULT '0';
