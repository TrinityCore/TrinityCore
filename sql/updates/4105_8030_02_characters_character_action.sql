-- ALTER TABLE character_db_version CHANGE COLUMN required_8030_01_characters_character_spell required_8030_02_characters_character_action bit;

UPDATE character_action
  SET action = 64901
  WHERE action = 64904 AND type = '0';