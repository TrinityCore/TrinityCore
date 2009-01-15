ALTER TABLE character_db_version CHANGE COLUMN required_2008_12_22_18_characters_characters required_2008_12_22_19_characters_item_instance bit;

UPDATE item_instance SET data = REPLACE(data,'  ',' ');
UPDATE item_instance SET data = CONCAT(TRIM(data),' ');

UPDATE item_instance SET data= CONCAT(
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',54),' ',-54),' 0 0 0 ',
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',60),' ',-60+54),' 0 ')
WHERE SUBSTRING_INDEX(data,' ',60) = data AND SUBSTRING_INDEX(data,' ',60-1) <> data;

UPDATE item_instance SET data= CONCAT(
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',30),' ',-30),' 0 0 0 ',
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',60),' ',-60+30),' 0 ',
  SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',134),' ',-134+60))
WHERE SUBSTRING_INDEX(data,' ',134) = data AND SUBSTRING_INDEX(data,' ',134-1) <> data;
