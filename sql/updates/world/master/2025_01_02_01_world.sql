-- using signed as Stats updatefield is also signed
ALTER TABLE `player_classlevelstats` 
  MODIFY COLUMN `str` int NOT NULL COMMENT 'strength' AFTER `level`,
  MODIFY COLUMN `agi` int NOT NULL COMMENT 'agility' AFTER `str`,
  MODIFY COLUMN `sta` int NOT NULL COMMENT 'stamina' AFTER `agi`,
  MODIFY COLUMN `inte` int NOT NULL COMMENT 'intellect' AFTER `sta`;
