CREATE TABLE IF NOT EXISTS `guild_member_withdraw` (
  `guid` int(10) unsigned NOT NULL,
  `tab0` int(10) unsigned NOT NULL DEFAULT '0',
  `tab1` int(10) unsigned NOT NULL DEFAULT '0',
  `tab2` int(10) unsigned NOT NULL DEFAULT '0',
  `tab3` int(10) unsigned NOT NULL DEFAULT '0',
  `tab4` int(10) unsigned NOT NULL DEFAULT '0',
  `tab5` int(10) unsigned NOT NULL DEFAULT '0',
  `money` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild Member Daily Withdraws';

ALTER TABLE `guild_member` DROP COLUMN `BankRemMoney`;
ALTER TABLE `guild_member` DROP COLUMN `BankRemSlotsTab0`;
ALTER TABLE `guild_member` DROP COLUMN `BankRemSlotsTab1`;
ALTER TABLE `guild_member` DROP COLUMN `BankRemSlotsTab2`;
ALTER TABLE `guild_member` DROP COLUMN `BankRemSlotsTab3`;
ALTER TABLE `guild_member` DROP COLUMN `BankRemSlotsTab4`;
ALTER TABLE `guild_member` DROP COLUMN `BankRemSlotsTab5`;
ALTER TABLE `guild_member` DROP COLUMN `BankResetTimeMoney`;
ALTER TABLE `guild_member` DROP COLUMN `BankResetTimeTab0`;
ALTER TABLE `guild_member` DROP COLUMN `BankResetTimeTab1`;
ALTER TABLE `guild_member` DROP COLUMN `BankResetTimeTab2`;
ALTER TABLE `guild_member` DROP COLUMN `BankResetTimeTab3`;
ALTER TABLE `guild_member` DROP COLUMN `BankResetTimeTab4`;
ALTER TABLE `guild_member` DROP COLUMN `BankResetTimeTab5`;

DELETE FROM `worldstates` WHERE `entry`=20006;
INSERT INTO `worldstates` (`entry`,`value`,`comment`) VALUES (20006,0, 'Guild daily reset');
