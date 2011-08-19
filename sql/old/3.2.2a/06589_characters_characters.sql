UPDATE characters SET data = REPLACE(data,'  ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');

UPDATE `characters` SET `data` = CONCAT(
        SUBSTRING_INDEX(`data`, ' ', 1167 + 1), ' ',
        '0 0 ',
        SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1246 + 1), ' ', -1246 + 1168 - 1), ' ',
        '0 0 0 ',
        SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1294 + 1), ' ', -1294 + 1247 - 1), ' ',
        '0 '
        )
WHERE length(SUBSTRING_INDEX(data, ' ', 1294)) < length(data) and length(SUBSTRING_INDEX(data, ' ', 1294+1)) >= length(data);

UPDATE characters SET data = REPLACE(data,'  ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');

