SET @Bag := 20469;
SET @RefA := 10022;
SET @RefB := 10023;
SET @RefC := 10024;
SET @RefD := 10025;

-- Add missing recipes to "Decoded True Believer Clippings" (i20469)
DELETE FROM `item_loot_template` WHERE `entry` = 20469;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@Bag,1,100,1,0,-@RefD,2), -- Decoded Twilight Texts
-- scrolls via reference
(@Bag,2,100,1,0,-10001,1), -- one from level V scrolls
(@Bag,3,4,1,0,-@RefA,1), -- one from Crest of Beckoning
(@Bag,4,4,1,0,-@RefB,1), -- one from Sigil of Beckoning
(@Bag,5,4,1,0,-@RefC,1), -- one from Scepter of Beckoning
-- special pattern drops:
(@Bag,20546,3,1,0,1,1), -- Runed Stygian Leggings
(@Bag,20547,3,1,0,1,1), -- Runed Stygian Boots
(@Bag,20548,3,1,0,1,1), -- Runed Stygian Belt
(@Bag,20553,3,1,0,1,1), -- Darkrune Gauntlets
(@Bag,20554,3,1,0,1,1), -- Darkrune Breastplate
(@Bag,20555,3,1,0,1,1); -- Darkrune Helm
-- References:
DELETE FROM `reference_loot_template` WHERE `entry` IN (@RefA,@RefB,@RefC,@RefD);
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
-- Decoded Twilight Texts:
(@RefD,20676,0,1,0,1,3), 
(@RefD,20541,0,1,0,1,3), 
(@RefD,20545,0,1,0,1,3), 
(@RefD,20679,0,1,0,1,3), 
(@RefD,20677,0,1,0,1,3), 
(@RefD,20678,0,1,0,1,3),
(@RefD,20552,0,1,0,1,3), 