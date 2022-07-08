-- Frenzied Geist (28419)
DELETE FROM `creature_loot_template` WHERE `Entry`=28419 AND `Item` IN (43507,43508,43509,43510);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES 
(28419,43507,0,0.1,0,1,0,1,1,''),
(28419,43508,0,0.1,0,1,0,1,1,''),
(28419,43509,0,0.1,0,1,0,1,1,''),
(28419,43510,0,0.1,0,1,0,1,1,'');

-- Tunneling Ghoul (24084)
DELETE FROM `creature_loot_template` WHERE `Entry`=24084 AND `Item` IN (43507,43508,43509,43510);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES 
(24084,43507,0,0.1,0,1,0,1,1,''),
(24084,43508,0,0.1,0,1,0,1,1,''),
(24084,43509,0,0.1,0,1,0,1,1,''),
(24084,43510,0,0.1,0,1,0,1,1,'');
