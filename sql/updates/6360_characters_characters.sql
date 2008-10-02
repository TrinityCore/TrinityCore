UPDATE characters SET data = REPLACE(data,'  ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');

UPDATE characters
SET data=CONCAT(SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',1396),' ',-1396),' ','0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0',' ',SUBSTRING_INDEX(SUBSTRING_INDEX(data,' ',1529),' ',-133))
WHERE SUBSTRING_INDEX(data,' ',1528) = data AND SUBSTRING_INDEX(data,' ',1527) <> data;
