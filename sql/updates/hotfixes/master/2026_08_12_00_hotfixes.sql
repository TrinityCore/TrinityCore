ALTER TABLE `player_condition` 
  CHANGE COLUMN `MovementFlags1` `MovementFlags` int NOT NULL DEFAULT 0 AFTER `PowerTypeValue`,
  DROP COLUMN `MovementFlags2`;
