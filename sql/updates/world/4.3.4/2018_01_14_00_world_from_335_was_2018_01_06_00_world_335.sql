/*
-- Remove unique items from reference table 24077
DELETE FROM `reference_loot_template` WHERE `Entry`=24077 AND `Item` IN (827, 1214, 1219, 1405, 1925, 1928, 1958, 1959, 4676);
-- Add former items from reference table 24077 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (827, 1214, 1219, 1405, 1925, 1928, 1958, 1959, 4676);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `MinCount`, `MaxCount`, `GroupId`, `Comment`) VALUES
(122, 827, 0.1, 1, 1, 1, 0, 'Defias Highwayman - Wicked Blackjack'),
(449, 827, 0.1, 1, 1, 1, 0, 'Defias Knuckleduster - Wicked Blackjack'),
(426, 1214, 0.1, 1, 1, 1, 0, 'Redridge Brute - Gnoll Punisher'),
(424, 1219, 0.1, 1, 1, 1, 0, 'Redridge Poacher - Redridge Machete'),
(517, 1405, 0.1, 1, 1, 1, 0, 'Murloc Oracle - Foamspittle Staff'),
(1725, 1925, 0.1, 1, 1, 1, 0, 'Defias Watchman - Defias Rapier'),
(1726, 1928, 0.1, 1, 1, 1, 0, 'Defias Magician - Defias Mage Staff'),
(623, 1958, 0.1, 1, 1, 1, 2, 'Skeletal Miner - Petrified Shinbone'),
(623, 1959, 0.1, 1, 1, 1, 2, 'Skeletal Miner - Cold Iron Pick'),
(624, 1958, 0.1, 1, 1, 1, 2, 'Undead Excavator - Petrified Shinbone'),
(624, 4676, 0.1, 1, 1, 1, 2, 'Undead Excavator - Skeletal Gauntlets'),
(625, 1958, 0.1, 1, 1, 1, 0, 'Undead Dynamiter - Petrified Shinbone');
*/
