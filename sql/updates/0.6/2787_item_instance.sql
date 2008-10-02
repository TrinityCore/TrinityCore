UPDATE `item_instance` 
  SET `data` = CONCAT(`data`,' 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ') 
  WHERE SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',3),' ',-1) = 7 AND SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',91),' ',-1) = '';
