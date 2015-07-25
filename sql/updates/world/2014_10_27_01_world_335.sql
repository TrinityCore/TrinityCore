/*
-- Link reference loot to item (using one of the reference loot template ids from icy prism as same 6 loot items
DELETE FROM `item_loot_template` WHERE `Entry`=46812;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(46812, 1, 45010, 100, 0, 1, 0, 1, 1, NULL),
(46812, 2, 45010, 50, 0, 1, 0, 1, 1, NULL);

-- Add Northrend Mystery Gem Pouch to Lhara
DELETE FROM `npc_vendor` WHERE `entry`=14846 AND `item`=46812;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `VerifiedBuild`) VALUES 
(14846, 0, 46812, 1, 43200, 0, 0);

-- Delete NR Rare nr gems for Emblem of Heroism from Lhara
DELETE FROM `npc_vendor` WHERE `entry`=14846 AND `item` IN(36927,36918,36933,36921,36924,36930);
*/
