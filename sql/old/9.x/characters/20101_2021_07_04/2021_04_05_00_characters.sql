ALTER TABLE `account_data` MODIFY `time` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `account_instance_times` MODIFY `releaseTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `auctionhouse`
  MODIFY `startTime` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `endTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `blackmarket_auctions` MODIFY `time` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `calendar_events`
  MODIFY `Date` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `LockDate` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `calendar_invites` MODIFY `ResponseTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `channels` MODIFY `lastUsed` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_account_data` MODIFY `time` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_achievement` MODIFY `date` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_achievement_progress` MODIFY `date` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_banned`
  MODIFY `bandate` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `unbandate` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_garrison_buildings` MODIFY `timeBuilt` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_queststatus` MODIFY `timer` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_queststatus_daily` MODIFY `time` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_queststatus_objectives_criteria_progress` MODIFY `date` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_spell_charges`
  MODIFY `rechargeStart` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `rechargeEnd` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `character_spell_cooldown`
  MODIFY `time` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `categoryEnd` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `characters`
  MODIFY `logout_time` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `resettalents_time` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `death_expire_time` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `deleteDate` bigint(20) unsigned DEFAULT NULL;

ALTER TABLE `creature_respawn` MODIFY `respawnTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `game_event_save` MODIFY `next_start` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `gameobject_respawn` MODIFY `respawnTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `gm_bug` MODIFY `createTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `gm_complaint` MODIFY `createTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `gm_complaint_chatlog` MODIFY `timestamp` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `gm_suggestion` MODIFY `createTime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `guild_achievement` MODIFY `date` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `guild_achievement_progress` MODIFY `date` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `guild_bank_eventlog` MODIFY `TimeStamp` bigint(20) NOT NULL DEFAULT '0' COMMENT 'Event UNIX time';

ALTER TABLE `guild_eventlog` MODIFY `TimeStamp` bigint(20) NOT NULL COMMENT 'Event UNIX time';

ALTER TABLE `guild_finder_applicant` MODIFY `submitTime` bigint(20) DEFAULT NULL;

ALTER TABLE `guild_newslog` MODIFY `TimeStamp` bigint(20) NOT NULL DEFAULT '0' COMMENT 'Event UNIX time';

ALTER TABLE `instance` MODIFY `resettime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `instance_reset` MODIFY `resettime` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `instance_scenario_progress` MODIFY `date` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `mail`
  MODIFY `expire_time` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `deliver_time` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `pet_spell_charges`
  MODIFY `rechargeStart` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `rechargeEnd` bigint(20) NOT NULL DEFAULT '0';

ALTER TABLE `pet_spell_cooldown`
  MODIFY `time` bigint(20) NOT NULL DEFAULT '0',
  MODIFY `categoryEnd` bigint(20) NOT NULL DEFAULT '0';
