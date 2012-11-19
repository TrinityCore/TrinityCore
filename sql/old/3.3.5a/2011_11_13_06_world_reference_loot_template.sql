SET @Ref = 10020;
DELETE FROM `reference_loot_template` WHERE `entry`=@Ref AND `item`IN (34000,34001,34002,34003,33292,37606);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@REF,34000,0.8,1,0,1,1), -- Flimsy Female Blood Elf Mask
(@REF,34001,0.8,1,0,1,1), -- Flimsy Female Draenei Mask
(@REF,34002,0.8,1,0,1,1), -- Flimsy Male Blood Elf Mask
(@REF,34003,0.8,1,0,1,1), -- Flimsy Male Draenei Mask
(@REF,37606,11,1,0,1,1), -- Penny Pouch
(@REF,33292,2,1,0,1,1); -- Hallowed Helm
