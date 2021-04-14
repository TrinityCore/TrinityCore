ALTER TABLE character_pet ADD load_flags INT(3) DEFAULT '0' NOT NULL AFTER teachspelldata;
UPDATE characters SET at_login = at_login & ~16 WHERE at_login & 16;
