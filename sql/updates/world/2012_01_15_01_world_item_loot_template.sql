SET @Bag := 20469;
SET @RefA := 10022;
SET @RefB := 10023;
SET @RefC := 10024;

-- Add missing recipes to "Decoded True Believer Clippings" (i20469)
DELETE FROM `item_loot_template` WHERE `entry` = 20469;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Decoded Twilight Texts:
(@Bag,20676,Chance,1,0,1,3), 
(@Bag,20541,Chance,1,0,1,3), 
(@Bag,20545,Chance,1,0,1,3), 
(@Bag,20679,Chance,1,0,1,3), 
(@Bag,20677,Chance,1,0,1,3), 
(@Bag,20678,Chance,1,0,1,3),
(@Bag,20552,Chance,1,0,1,3), 
-- scrolls via reference
(@Bag,1,100,1,0,-10001,1), -- one from level V scrolls
(@Bag,2,4,1,0,-@RefA,1), -- one from Crest of Beckoning
(@Bag,2,4,1,0,-@RefB,1), -- one from Sigil of Beckoning
(@Bag,2,4,1,0,-@RefC,1), -- one from Scepter of Beckoning
-- special pattern drops:
(@Bag,20546,3,1,0,1,1), -- Runed Stygian Leggings
(@Bag,20547,3,1,0,1,1), -- Runed Stygian Boots
(@Bag,20548,3,1,0,1,1), -- Runed Stygian Belt
(@Bag,20553,3,1,0,1,1), -- Darkrune Gauntlets
(@Bag,20554,3,1,0,1,1), -- Darkrune Breastplate
(@Bag,20555,3,1,0,1,1); -- Darkrune Helm
-- References:
DELETE FROM `reference_loot_template` WHERE `entry` IN (@RefA,@RefB,@RefC);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@RefA,20518,0,1,1,1,1), -- Scroll: Crest of Beckoning
(@RefA,20526,0,1,1,1,1), -- Scroll: Crest of Beckoning
(@RefA,20527,0,1,1,1,1), -- Scroll: Crest of Beckoning
(@RefA,20528,0,1,1,1,1), -- Scroll: Crest of Beckoning
(@RefB,20531,0,1,1,1,1), -- Scroll: Sigil of Beckoning
(@RefB,20532,0,1,1,1,1), -- Scroll: Sigil of Beckoning
(@RefB,20533,0,1,1,1,1), -- Scroll: Sigil of Beckoning
(@RefB,20535,0,1,1,1,1), -- Scroll: Sigil of Beckoning
(@RefC,20540,0,1,1,1,1), -- Scroll: Scepter of Beckoning
(@RefC,20542,0,1,1,1,1), -- Scroll: Scepter of Beckoning
(@RefC,20543,0,1,1,1,1), -- Scroll: Scepter of Beckoning
(@RefC,20544,0,1,1,1,1); -- Scroll: Scepter of Beckoning
