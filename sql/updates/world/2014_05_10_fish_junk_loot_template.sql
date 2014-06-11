SET @FISH_JUNK_GROUP := 11799;
SET @FISH_JUNK_LOOTMODE := 32768;

DELETE FROM fishing_loot_template WHERE `item`=@FISH_JUNK_GROUP;
INSERT INTO fishing_loot_template (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(1, @FISH_JUNK_GROUP, 100, @FISH_JUNK_LOOTMODE, 1, -@FISH_JUNK_GROUP, 1);

DELETE FROM reference_loot_template WHERE `entry`=@FISH_JUNK_GROUP;
INSERT INTO reference_loot_template (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@FISH_JUNK_GROUP, 45190, 15, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Driftwood]
(@FISH_JUNK_GROUP, 45191, 2, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Water Snail]
(@FISH_JUNK_GROUP, 45194, 15, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Tangled Fishing Line]
(@FISH_JUNK_GROUP, 45195, 5, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Empty Rum Bottle]
(@FISH_JUNK_GROUP, 45196, 15, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Tattered Cloth]
(@FISH_JUNK_GROUP, 45197, 5, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Tree Branch]
(@FISH_JUNK_GROUP, 45198, 15, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Weeds]
(@FISH_JUNK_GROUP, 45199, 5, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Old Boot]
(@FISH_JUNK_GROUP, 45200, 15, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Sickly Fish]
(@FISH_JUNK_GROUP, 45201, 3, @FISH_JUNK_LOOTMODE, 1, 1, 1), -- [Rock]
(@FISH_JUNK_GROUP, 45202, 5, @FISH_JUNK_LOOTMODE, 1, 1, 1); -- [Water Snail]
