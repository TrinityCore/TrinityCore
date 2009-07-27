/*ALTER TABLE character_db_version CHANGE COLUMN required_8072_02_characters_characters required_8098_01_characters_character_action bit;*/

ALTER TABLE character_action
  CHANGE COLUMN action action int(11) unsigned NOT NULL default '0';

UPDATE character_action
  SET action = action | ( misc << 16 );

ALTER TABLE character_action
    DROP COLUMN misc;


UPDATE character_pet
   SET abdata = CONCAT(
     (SUBSTRING(abdata, 1, length(SUBSTRING_INDEX(abdata, ' ', 1))) >> 8),' ',
     SUBSTRING(abdata, length(SUBSTRING_INDEX(abdata, ' ', 1))+2, length(SUBSTRING_INDEX(abdata, ' ', 2))-length(SUBSTRING_INDEX(abdata, ' ', 1))-1),' ',
     (SUBSTRING(abdata, length(SUBSTRING_INDEX(abdata, ' ', 2))+2, length(SUBSTRING_INDEX(abdata, ' ', 3))-length(SUBSTRING_INDEX(abdata, ' ', 2))-1) >> 8),' ',
     SUBSTRING(abdata, length(SUBSTRING_INDEX(abdata, ' ', 3))+2, length(SUBSTRING_INDEX(abdata, ' ', 4))-length(SUBSTRING_INDEX(abdata, ' ', 3))-1),' ',
     (SUBSTRING(abdata, length(SUBSTRING_INDEX(abdata, ' ', 4))+2, length(SUBSTRING_INDEX(abdata, ' ', 5))-length(SUBSTRING_INDEX(abdata, ' ', 4))-1) >> 8),' ',
     SUBSTRING(abdata, length(SUBSTRING_INDEX(abdata, ' ', 5))+2, length(SUBSTRING_INDEX(abdata, ' ', 6))-length(SUBSTRING_INDEX(abdata, ' ', 5))-1),' ',
     (SUBSTRING(abdata, length(SUBSTRING_INDEX(abdata, ' ', 6))+2, length(SUBSTRING_INDEX(abdata, ' ', 7))-length(SUBSTRING_INDEX(abdata, ' ', 6))-1) >> 8),' ',
     SUBSTRING(abdata, length(SUBSTRING_INDEX(abdata, ' ', 7))+2, length(SUBSTRING_INDEX(abdata, ' ', 8))-length(SUBSTRING_INDEX(abdata, ' ', 7))-1),' '
  );


UPDATE pet_spell
   SET active = ( active >> 8);