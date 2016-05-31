-- Change loot in Mithril Bound Trunk to always give an item
DELETE FROM `item_loot_template` WHERE `entry`=21228;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Group1: Leather @ 70%
(21228,4304,40,1,1,2,4), -- Thick Leather
(21228,8170,30,1,1,1,2), -- Rugged Leather
-- Group2: Cloth @ 70%
(21228, 4339,40,1,2,1,3), -- Bolt of Mageweave
(21228,14048,30,1,2,1,2), -- Bolt of Runecloth
-- Ungrouped:
(21228,6149,20,1,0,1,2), -- Greater Mana Potion
(21228,3928,20,1,0,1,2), -- Superior Healing Potion
(21228,34109,50,1,0,1,1), -- Weather-Beaten Journal
(21228, 3914, 1,1,0,1,1), -- Journeyman's Backpack
(21228,7976,0.05,1,0,1,1), -- Plans: Mithril Shield Spike
(21228,7909,0.4,1,0,1,1), -- Aquamarine
(21228,7910,0.3,1,0,1,1), -- Star Ruby
(21228,1613,0.3,1,0,1,1), -- Spiritchaser Staff
(21228,9295,0.3,1,0,1,1), -- Recipe: Invisibility Potion
(21228,7468,0.2,1,0,1,1), -- Regal Robe
(21228,9291,0.2,1,0,1,1), -- Field Plate Leggings
(21228,9910,0.2,1,0,1,1), -- Royal Gloves
(21228,10320,0.2,1,0,1,1), -- Pattern: Red Mageweave Headband
(21228,15245,0.2,1,0,1,1), -- Vorpal Dagger
(21228,8281,0.2,1,0,1,1), -- Valorous Pauldrons
(21228,1685,0.2,1,0,1,1), -- Troll-hide Bag
(21228,8163,0.2,1,0,1,1), -- Jouster's Pauldrons
(21228,8141,0.2,1,0,1,1), -- Chromite Greaves
(21228,8121,0.2,1,0,1,1); -- Heraldic Gloves
