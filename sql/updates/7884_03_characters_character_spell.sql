ALTER TABLE character_db_version CHANGE COLUMN required_7802_02_characters_character_achievement_progress required_7884_03_characters_character_spell bit;

DELETE FROM character_spell WHERE spell = '28734';
