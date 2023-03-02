ALTER TABLE `item_instance`   
  ADD COLUMN `reforgeID` INT(10) DEFAULT 0  NULL AFTER `randomPropertyId`,
  ADD COLUMN `transmogrifyId` INT(10) DEFAULT 0  NULL AFTER `reforgeID`;
