ALTER TABLE `creature_template` 
  ADD COLUMN `InhabitType` tinyint(1) unsigned NOT NULL default '3' AFTER `MovementType`;

/*
0 - not used
1 - can walk (or fly above ground)
2 - can swim (or fly above water)
3 (= 1 | 2) - can walk and swim (and fly)
*/

UPDATE `creature_template`
  SET `InhabitType` = 1  WHERE `family` > 0 AND `family` < 6 OR `family` = 8 OR `family` = 11 OR `family` > 14 AND `family` < 20 OR `family` = 25 OR `family` = 27;
