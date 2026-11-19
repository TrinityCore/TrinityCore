--
-- remove loot item 4893, 'Savannah Lion Tusk' from the loot table
-- move loot item 5096 from Savannah Prowler (3425) to Savannah Huntress (3415)
DELETE FROM `creature_loot_template` WHERE `Item` IN (4893,5096);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(3415, 5096, 0, 50.08, 1, 1, 0, 1, 1, NULL);
