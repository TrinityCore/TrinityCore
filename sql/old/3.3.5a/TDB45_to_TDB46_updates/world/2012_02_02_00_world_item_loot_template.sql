-- Update reference for hallowed end
SET @Ref := 10020;
DELETE FROM `reference_loot_template` WHERE `entry` IN (@Ref,10021);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Masks
(@Ref,20391,2,1,0,1,1), -- Flimsy Male Gnome Mask
(@Ref,20392,2,1,0,1,1), -- Flimsy Female Gnome Mask
(@Ref,20561,2,1,0,1,1), -- Flimsy Male Dwarf Mask
(@Ref,20562,2,1,0,1,1), -- Flimsy Female Dwarf Mask
(@Ref,20563,2,1,0,1,1), -- Flimsy Female Night Elf Mask
(@Ref,20564,2,1,0,1,1), -- Flimsy Male Night Elf Mask
(@Ref,20565,2,1,0,1,1), -- Flimsy Female Human Mask
(@Ref,20566,2,1,0,1,1), -- Flimsy Male Human Mask
(@Ref,20567,2,1,0,1,1), -- Flimsy Female Troll Mask
(@Ref,20568,2,1,0,1,1), -- Flimsy Male Troll Mask
(@Ref,20569,2,1,0,1,1), -- Flimsy Female Orc Mask
(@Ref,20570,2,1,0,1,1), -- Flimsy Male Orc Mask
(@Ref,20571,2,1,0,1,1), -- Flimsy Female Tauren Mask
(@Ref,20572,2,1,0,1,1), -- Flimsy Male Tauren Mask
(@Ref,20573,2,1,0,1,1), -- Flimsy Male Undead Mask
(@Ref,20574,2,1,0,1,1), -- Flimsy Female Undead Mask
(@Ref,34000,2,1,0,1,1), -- Flimsy Female Blood Elf Mask
(@Ref,34001,2,1,0,1,1), -- Flimsy Female Draenei Mask
(@Ref,34002,2,1,0,1,1), -- Flimsy Male Blood Elf Mask
(@Ref,34003,2,1,0,1,1), -- Flimsy Male Draenei Mask
-- Wands
(@Ref,20397,2,1,0,1,1), -- Hallowed Wand - Pirate
(@Ref,20398,2,1,0,1,1), -- Hallowed Wand - Ninja
(@Ref,20399,2,1,0,1,1), -- Hallowed Wand - Leper Gnome
(@Ref,20409,2,1,0,1,1), -- Hallowed Wand - Ghost
(@Ref,20410,2,1,0,1,1), -- Hallowed Wand - Bat
(@Ref,20411,2,1,0,1,1), -- Hallowed Wand - Skeleton
(@Ref,20413,2,1,0,1,1), -- Hallowed Wand - Random
(@Ref,20414,2,1,0,1,1), -- Hallowed Wand - Wisp
-- Pets
(@Ref,33154,5,1,0,1,1), -- Sinister Squashling
(@Ref,33292,5,1,0,1,1), -- Hallowed Helm
-- Candies
(@Ref,20388,15,1,0,4,6), -- Lollipop
(@Ref,20389,15,1,0,4,6), -- Candy Corn
(@Ref,20390,15,1,0,4,6), -- Candy Bar
(@Ref,37604,30,1,0,10,10), -- Tooth Pick
(@Ref,37582,30,1,0,1,2), -- Pyroblast Cinnamon Ball
(@Ref,37583,30,1,0,1,2), -- G.N.E.R.D.S.
(@Ref,37584,30,1,0,1,2), -- Soothing Spearmint Candy
(@Ref,37585,30,1,0,1,2), -- Chewy Fel Taffy
(@Ref,37606,15,1,0,1,1); -- Penny Pouch

-- Assign loot to the special bags
DELETE FROM `item_loot_template` WHERE `entry` IN (54516,37586);
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Loot Filled Pumpkin:
(54516,33226,100,1,0,2,3), -- Tricky Treat
(54516,1,100,1,0,-@Ref,1), -- Referenced Specials
(54516,33808,2,1,0,1,1), -- The Horseman's Helm
(54516,38175,2,1,0,1,1), -- The Horseman's Blade
(54516,37012,0.1,1,0,1,1), -- The Horseman's Reins
-- Handfull of Treats:
(37586,33226,100,1,0,2,3), -- Tricky Treat
(37586,1,100,1,0,-@Ref,1); -- Referenced Specials
