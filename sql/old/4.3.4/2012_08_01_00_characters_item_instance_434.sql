UPDATE `item_instance` SET `enchantments` = REPLACE(`enchantments`,'  ',' ');
UPDATE `item_instance` SET `enchantments` = CONCAT(TRIM(`enchantments`),' ');

UPDATE `item_instance` SET `enchantments` = CONCAT(
    SUBSTRING_INDEX(`enchantments`, ' ', 7*3),
    ' 0 0 0 0 0 0 0 0 0 ',
    SUBSTRING_INDEX(`enchantments`, ' ', -(12-7)*3 - 1))
WHERE (LENGTH(`enchantments`) - LENGTH(REPLACE(`enchantments`, ' ', ''))) = 12*3;

UPDATE `item_instance` SET `enchantments` = REPLACE(`enchantments`,'  ',' ');
UPDATE `item_instance` SET `enchantments` = CONCAT(TRIM(`enchantments`),' ');
