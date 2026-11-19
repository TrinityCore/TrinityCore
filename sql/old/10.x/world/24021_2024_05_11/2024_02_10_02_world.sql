-- Ferocitas the Dream Eater Loot: Talonkai's Jewel
DELETE FROM `creature_loot_template` WHERE `Entry`=7234 AND `Item` IN (8049, 8050);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(7234,8050,0,100,1,1,0,1,1,'Quest Item: Talonkai''s Jewel');
