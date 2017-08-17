ALTER TABLE `auctionhouse`
  CHANGE COLUMN `buyoutprice` `buyoutprice` bigint(20) unsigned NOT NULL DEFAULT '0',
  CHANGE COLUMN `lastbid` `lastbid` bigint(20) unsigned NOT NULL DEFAULT '0',
  CHANGE COLUMN `startbid` `startbid` bigint(20) unsigned NOT NULL DEFAULT '0',
  CHANGE COLUMN `deposit` `deposit` bigint(20) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `guild_member_withdraw`
  CHANGE COLUMN `money` `money` bigint(20) unsigned NOT NULL DEFAULT '0';

ALTER TABLE `item_refund_instance`
  CHANGE COLUMN `paidMoney` `paidMoney` bigint(20) unsigned NOT NULL DEFAULT '0';
