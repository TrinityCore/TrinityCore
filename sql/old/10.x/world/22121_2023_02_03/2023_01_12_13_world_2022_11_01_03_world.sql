-- Ulduar - General Vezax 25 and Yogg-Saron 25 should drop Fragment of Val'anyr
DELETE FROM `creature_loot_template` WHERE `Entry` IN (33449,33955) AND `Item`=45038;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES 
(33449,45038,0,9,0,1,0,1,1,'General Vezax 25: Fragment of Val\'anyr'),
(33955,45038,0,100,0,1,0,1,1,'Yogg-Saron 25: Fragment of Val\'anyr Guaranteed (100%)');
