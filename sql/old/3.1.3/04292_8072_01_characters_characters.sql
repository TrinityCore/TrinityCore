-- ALTER TABLE character_db_version CHANGE COLUMN required_8030_02_characters_character_action required_8072_01_characters_characters bit;

ALTER TABLE characters
ADD gender TINYINT UNSIGNED NOT NULL default '0' AFTER class,
ADD level TINYINT UNSIGNED NOT NULL default '0' AFTER gender,
ADD xp INT UNSIGNED NOT NULL default '0' AFTER level,
ADD money INT UNSIGNED NOT NULL default '0' AFTER xp,
ADD playerBytes INT UNSIGNED NOT NULL default '0' AFTER money,
ADD playerBytes2 INT UNSIGNED NOT NULL default '0' AFTER playerBytes,
ADD playerFlags INT UNSIGNED NOT NULL default '0' AFTER playerBytes2;
