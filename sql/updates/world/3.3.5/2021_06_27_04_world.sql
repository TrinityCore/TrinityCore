-- Replace Burning Blossom with Emblem of Frost, Burning Blossom replaced Emblem of Frost only in Cata
-- Raise chance of Frostscythe of Lord Ahune
UPDATE `item_loot_template` SET `Item` = 49426, `GroupId` = 0, `MinCount` = 2, `MaxCount` = 2 WHERE `Entry` = 54536 AND `Item` = 23247;
UPDATE `item_loot_template` SET `Chance` = 6 WHERE `Entry` = 54536 AND `Item` = 54806;
