ALTER TABLE `arena_team` CHANGE `captainGuid` `captainGuid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `arena_team_member` CHANGE `guid` `guid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` CHANGE `auctioneerguid` `auctioneerguid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` CHANGE `itemguid` `itemguid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` CHANGE `itemowner` `itemowner` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `auctionhouse` CHANGE `buyguid` `buyguid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0';
