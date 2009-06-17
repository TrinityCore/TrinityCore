-- ALTER TABLE character_db_version CHANGE COLUMN required_7988_07_characters_characters required_8030_01_characters_character_spell bit;

UPDATE IGNORE character_spell
  SET spell = 64901
  WHERE spell = 64904;

DELETE FROM character_spell WHERE spell = 64904;