/*
-- Remove unique items from reference table 24078
DELETE FROM `reference_loot_template` WHERE `Entry`=24078 AND `Item` IN (899, 1391, 1440, 1446, 1469, 1473, 1929, 1930, 1936, 1943, 1944, 1945, 1951, 2020, 4290, 10400, 10401, 10402);

-- Add former items from reference table 24078 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (899, 1391, 1440, 1446, 1469, 1473, 1929, 1930, 1936, 1943, 1944, 1945, 1951, 2020, 4290, 10400, 10401, 10402);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(217, 899, 0.1, 0, "Venom Web Spider - Venom Web Fang"),
(453, 1391, 0.1, 0, "Riverpaw Mystic - Riverpaw Mystic Staff"),
(446, 1440, 0.1, 0, "Redridge Basher - Gnoll Skull Basher"),
(440, 1446, 0.1, 0, "Blackrock Grunt - Blackrock Boots"),
(578, 1469, 0.1, 0, "Murloc Scout - Scimitar of Atun"),
(14270, 1469, 1, 0, "Squiddic - Scimitar of Atun"),
(545, 1473, 0.1, 0, "Murloc Tidecaller - Riverside Staff"),
(1729, 1929, 0.1, 0, "Defias Evoker - Silk-threaded Trousers"),
(4418, 1929, 0.1, 0, "Defias Wizard - Silk-threaded Trousers"),
(598, 1930, 0.1, 0, "Defias Miner - Stonemason Cloak"),
(622, 1936, 0.1, 0, "Goblin Engineer - Goblin Screwdriver"),
(3947, 1943, 0.1, 0, "Goblin Shipbuilder - Goblin Mail Leggings"),
(1731, 1944, 0.1, 0, "Goblin Craftsman - Metalworking Gloves"),
(641, 1945, 0.1, 0, "Goblin Woodcarver - Woodworking Gloves"),
(657, 1951, 0.1, 0, "Defias Pirate - Blackwater Cutlass"),
(1732, 1951, 0.1, 0, "Defias Squallshaper - Blackwater Cutlass"),
(539, 2020, 0.1, 0, "Pygmy Venom Web Spider - Hollowfang Blade"),
(832, 4290, 0.5, 0, "Dust Devil - Dust Bowl"),
(634, 10400, 0.5, 2, "Defias Overseer - Blackened Defias Leggings"),
(4417, 10400, 0.5, 2, "Defias Taskmaster - Blackened Defias Leggings"),
(634, 10401, 0.5, 2, "Defias Overseer - Blackened Defias Gloves"),
(4417, 10401, 0.5, 2, "Defias Taskmaster - Blackened Defias Gloves"),
(4416, 10402, 0.5, 0, "Defias Strip Miner - Blackened Defias Boots");
*/
