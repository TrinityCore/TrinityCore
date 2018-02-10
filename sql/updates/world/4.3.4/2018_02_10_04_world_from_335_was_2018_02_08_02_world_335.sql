/*
-- Remove unique items from reference table 24062
DELETE FROM `reference_loot_template` WHERE `Entry`=24062 AND `Item` IN (880, 1299, 1457, 1458, 2175, 1462, 1461, 1459, 3018, 3227);

-- Add former items from reference table 24062 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (880, 1299, 1457, 1458, 2175, 1462, 1461, 1459);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(202,  880, 0.1, 0, "Skeletal Horror - Staff of Horrors"),
(436, 1299, 0.1, 0, "Blackrock Shadowcaster - Lesser Belt of the Spire"),
(433, 1457, 0.1, 0, "Shadowhide Gnoll - Shadowhide Mace"),
(432, 1458, 0.1, 0, "Shadowhide Brute - Shadowhide Maul"),
(568, 2175, 0.1, 0, "Shadowhide Warrior - Shadowhide Battle Axe"),
(429, 1462, 0.1, 0, "Shadowhide Darkweaver - Ring of the  Shadow"),
(431, 1461, 0.1, 0, "Shadowhide Slayer - Slayer's Battle Axe"),
(579, 1459, 0.1, 0, "Shadowhide Assassin - Shadowhide Scalper");
*/
