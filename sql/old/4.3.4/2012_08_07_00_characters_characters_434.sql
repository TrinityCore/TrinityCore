UPDATE characters SET drunk = (drunk / 256) & 0xFF;
ALTER TABLE characters CHANGE drunk drunk tinyint(3) unsigned NOT NULL DEFAULT '0';
