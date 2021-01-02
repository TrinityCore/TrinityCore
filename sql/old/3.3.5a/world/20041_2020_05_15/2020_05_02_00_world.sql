-- Add missing bandages to Arathi Basin care packages
DELETE FROM `item_loot_template` WHERE `Item` IN (20065,20066,20067);
INSERT INTO `item_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(20230,20065,0,100,0,1,0,20,20),
(20236,20065,0,100,0,1,0,20,20),
(20228,20066,0,100,0,1,0,20,20),
(20231,20066,0,100,0,1,0,20,20),
(20229,20067,0,100,0,1,0,20,20),
(20233,20067,0,100,0,1,0,20,20);
