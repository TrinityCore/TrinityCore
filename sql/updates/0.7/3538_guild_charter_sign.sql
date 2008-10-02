ALTER TABLE `guild_charter_sign`
  ADD `player_account` int(11) unsigned NOT NULL default '0' AFTER `playerguid`;

UPDATE `guild_charter_sign`,`character`
  SET `guild_charter_sign`.`player_account` = `character`.`account`
  WHERE `guild_charter_sign`.`playerguid` = `character`.`guid`;
