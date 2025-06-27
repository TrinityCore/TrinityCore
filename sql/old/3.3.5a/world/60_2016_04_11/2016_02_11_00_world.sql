-- Scarlet Insignia Ring - Questloot
DELETE FROM `creature_loot_template` WHERE `Entry` IN (1538,1539,1540) AND `Item`= 2875;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1538, 2875, 0, 40, 1, 1, 0, 1, 1, 'Scarlet Friar - Scarlet Insignia Ring'),
(1539, 2875, 0, 40, 1, 1, 0, 1, 1, 'Scarlet Neophyte - Scarlet Insignia Ring'),
(1540, 2875, 0, 40, 1, 1, 0, 1, 1, 'Scarlet Vanguard - Scarlet Insignia Ring');
