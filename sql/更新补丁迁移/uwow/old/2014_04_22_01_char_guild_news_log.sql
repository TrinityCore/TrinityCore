UPDATE guild_news_log SET playerGuid = playerGuid & 0xFFFF;
ALTER TABLE guild_news_log MODIFY COLUMN playerGuid int(11) UNSIGNED NOT NULL DEFAULT '1';