ALTER TABLE `item_template` 
   ADD COLUMN `minMoneyLoot` int(11) unsigned NOT NULL default '0' AFTER `FoodType`,
   ADD COLUMN `maxMoneyLoot` int(11) unsigned NOT NULL default '0' AFTER `minMoneyLoot`;
