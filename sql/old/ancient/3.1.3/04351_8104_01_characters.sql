-- ALTER TABLE character_db_version CHANGE COLUMN required_8098_04_characters_pet_spell required_8104_01_characters bit;

ALTER TABLE character_achievement ENGINE=InnoDB DEFAULT CHARSET=utf8;
ALTER TABLE character_achievement_progress ENGINE=InnoDB DEFAULT CHARSET=utf8;
ALTER TABLE character_declinedname ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;
ALTER TABLE character_pet_declinedname ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;
ALTER TABLE guild_eventlog ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT 'Guild Eventlog';
