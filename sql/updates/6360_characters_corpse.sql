UPDATE corpse SET data = REPLACE(data,'  ',' ');
UPDATE corpse SET data = CONCAT(TRIM(data),' ');

UPDATE corpse
SET data=CONCAT(SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',8),' ',-8),' ','0 0',' ',SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',39),' ',-31))
WHERE SUBSTRING_INDEX(data,' ',38) = data AND SUBSTRING_INDEX(data,' ',37) <> data;
