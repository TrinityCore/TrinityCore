-- 
DELETE FROM `item_loot_template` WHERE `Entry` = 43575 AND `Item` IN (43611,43612,43613);
INSERT INTO `item_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(43575,43611,0,0.05,0,1,1,1,1),
(43575,43612,0,0.05,0,1,1,1,1),
(43575,43613,0,0.05,0,1,1,1,1);
