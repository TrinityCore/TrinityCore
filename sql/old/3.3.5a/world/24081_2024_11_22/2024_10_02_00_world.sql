--
DELETE FROM `prospecting_loot_template` WHERE `Entry`=10620 AND `Reference`=13001;
DELETE FROM `prospecting_loot_template` WHERE `Entry`=10620 AND `Item` IN (21929,23077,23079,23107,23112,23117);
INSERT INTO `prospecting_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(10620,21929,0,0,0,1,1,1,2,NULL),
(10620,23077,0,0,0,1,1,1,2,NULL),
(10620,23079,0,0,0,1,1,1,2,NULL),
(10620,23107,0,0,0,1,1,1,2,NULL),
(10620,23112,0,0,0,1,1,1,2,NULL),
(10620,23117,0,0,0,1,1,1,2,NULL);
