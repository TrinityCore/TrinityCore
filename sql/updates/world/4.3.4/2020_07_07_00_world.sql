SET @ENTRY := 68813;
DELETE FROM `item_loot_template` WHERE `Entry`= @ENTRY;
DELETE FROM `reference_loot_template` WHERE `Entry`= @ENTRY * 10;
INSERT INTO `reference_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- 5 herbs per roll
(@ENTRY * 10, 0, 52984, 0, 1, 5, 5),
(@ENTRY * 10, 0, 52986, 0, 1, 5, 5),
(@ENTRY * 10, 0, 52983, 0, 1, 5, 5),
(@ENTRY * 10, 0, 52988, 0, 1, 5, 5),
(@ENTRY * 10, 0, 52987, 0, 1, 5, 5),
(@ENTRY * 10, 0, 52985, 0, 1, 5, 5);

INSERT INTO `item_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY, @ENTRY * 10, @ENTRY * 10, 100, 0, 4, 4);
