-- Wiki: This item is a zone drop from the following mobs in Dire Maul: Ironbark Protector, Petrified Guardian, Petrified Treant
-- Chance: http://web.archive.org/web/20100429225237/www.wowhead.com/item=18343
DELETE FROM `reference_loot_template` WHERE `Entry` = 24016 AND `Item` = 18343;
DELETE FROM `creature_loot_template` WHERE `Item` = 18343;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`) VALUES
(11458,18343,0,0.5,0,1,0,1,1),
(11459,18343,0,0.5,0,1,0,1,1),
(14303,18343,0,0.5,0,1,0,1,1);
