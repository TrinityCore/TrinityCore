DROP TABLE IF EXISTS `guild_news_log`;
CREATE TABLE `guild_news_log` (
  `guild` INT(10) UNSIGNED NOT NULL,
  `id` INT(10) UNSIGNED NOT NULL,
  `eventType` INT(10) UNSIGNED NOT NULL,
  `playerGuid` BIGINT(20) UNSIGNED NOT NULL,
  `data0` INT(10) UNSIGNED NOT NULL,
  `flags` INT(10) UNSIGNED NOT NULL,
  `date` INT(10) UNSIGNED NOT NULL DEFAULT '0',
  PRIMARY KEY (`guild`,`id`)
) ENGINE=INNODB DEFAULT CHARSET=utf8;


ALTER TABLE guild_member ADD weeklyRepGained INT(10) DEFAULT '0' AFTER offnote;
ALTER TABLE guild_member ADD weeklyActivity BIGINT(20) unsigned DEFAULT '0' AFTER weeklyRep;
ALTER TABLE guild_member ADD totalActivity BIGINT(20) unsigned DEFAULT '0' AFTER weeklyActivity;

ALTER TABLE guild_member ADD BankResetTimeTab6 INT(10) unsigned DEFAULT '0' AFTER BankRemSlotsTab5;
ALTER TABLE guild_member ADD BankRemSlotsTab6 INT(10) unsigned DEFAULT '0' AFTER BankResetTimeTab6;
ALTER TABLE guild_member ADD BankResetTimeTab7 INT(10) unsigned DEFAULT '0' AFTER BankRemSlotsTab6;
ALTER TABLE guild_member ADD BankRemSlotsTab7 INT(10) unsigned DEFAULT '0' AFTER BankResetTimeTab7;
ALTER TABLE guild_member ADD GuildReputation INT(10) DEFAULT '0' AFTER BankRemSlotsTab7;
ALTER TABLE guild_member ADD AchievementPoints INT(10) unsigned DEFAULT '0' AFTER GuildReputation;
ALTER TABLE guild_member ADD ProfessionSkillId0 INT(10) unsigned DEFAULT '0' AFTER AchievementPoints;
ALTER TABLE guild_member ADD ProfessionLevel0 INT(10) unsigned DEFAULT '0' AFTER ProfessionSkillId0;
ALTER TABLE guild_member ADD ProfessionRank0 INT(10) unsigned DEFAULT '0' AFTER ProfessionLevel0;
ALTER TABLE guild_member ADD ProfessionSkillId1 INT(10) unsigned DEFAULT '0' AFTER ProfessionRank0;
ALTER TABLE guild_member ADD ProfessionLevel1 INT(10) unsigned DEFAULT '0' AFTER ProfessionSkillId1;
ALTER TABLE guild_member ADD ProfessionRank1 INT(10) unsigned DEFAULT '0' AFTER ProfessionLevel1;

ALTER TABLE guild ADD xp BIGINT(20) unsigned DEFAULT '0' AFTER BankMoney;
ALTER TABLE guild ADD level INT(10) unsigned DEFAULT '0' AFTER xp;
ALTER TABLE guild ADD today_xp BIGINT(20) unsigned DEFAULT '0' AFTER LEVEL;