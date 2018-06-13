-- Remove unique items from reference table 24048
DELETE FROM `reference_loot_template` WHERE `Entry`=24048 AND `Item` IN (1297, 2234, 4462, 4724);

-- Add former items from reference table 24048 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (1297, 2234, 4462, 4724);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(2553, 1297, 0.1, 0, "Witherbark Shadowcaster - Robes of the Shadowcaster"),
(2577, 1297, 0.1, 0, "Dark Iron Shadowcaster - Robes of the Shadowcaster"),
(920,  2234, 0.1, 0, "Nightbane Tainted One - Nightwalker Armor"),
(503,  4462, 5,   0, "Lord Malathrom - Cloak of Rot"),
(2345, 4724, 2.5, 0, "Dun Garok Rifleman - Humbert's Helm");

-- Remove unique items from reference table 24050
DELETE FROM `reference_loot_template` WHERE `Entry`=24050 AND `Item` IN (1998, 3341);

-- Add former items from reference table 24050 to their proper NPCs
DELETE FROM `creature_loot_template` WHERE `Item` IN (1998, 3341);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `GroupId`, `Comment`) VALUES
(697,  1998, 0.1, 0, "Bloodscalp Shaman - Bloodscalp Channeling Staff"),
(2562, 3341, 0.1, 0, "Boulderfist Ogre - Gauntlets of Ogre Strength"),
(2564, 3341, 0.1, 0, "Boulderfist Enforcer - Gauntlets of Ogre Strength");
