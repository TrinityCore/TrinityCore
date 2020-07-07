-- Crate of Tasty Meat
SET @ENTRY := 65513;
DELETE FROM `item_loot_template` WHERE `Entry`= @ENTRY;
DELETE FROM `reference_loot_template` WHERE `Entry`= @ENTRY * 10  OR `Entry`= @ENTRY * 10 +1;
INSERT INTO `reference_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY * 10, 0, 62783, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62782, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62784, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62781, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62780, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62778, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62785, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62791, 0, 1, 2, 10),
(@ENTRY * 10, 0, 62779, 0, 1, 2, 10),
(@ENTRY * 10 + 1, 0, 65503, 0, 1, 1, 1),
(@ENTRY * 10 + 1, 0, 65505, 0, 1, 1, 1),
(@ENTRY * 10 + 1, 0, 65502, 0, 1, 1, 1),
(@ENTRY * 10 + 1, 0, 65509, 0, 1, 1, 1),
(@ENTRY * 10 + 1, 0, 65506, 0, 1, 1, 1);

INSERT INTO `item_loot_template` (`Entry`, `Reference`, `Item`, `Chance`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(@ENTRY, @ENTRY * 10, @ENTRY * 10, 100, 0, 2, 2),
(@ENTRY, @ENTRY * 10 + 1, @ENTRY * 10 + 1, 100, 0, 1, 1);
