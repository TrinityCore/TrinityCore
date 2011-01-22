ALTER TABLE `character_inventory` 
ADD UNIQUE KEY (`guid`,`bag`,`slot`);
