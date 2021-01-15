-- Insert "Brazie's Black Book of Secrets" into Brazie Getz's vendor table
DELETE FROM `npc_vendor` WHERE `entry`=37904 AND `item`=49926;
INSERT INTO `npc_vendor` (`entry`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `VerifiedBuild`) VALUES
(37904, 49926, 0, 0, 0, 0);
-- Add various Brazie's "guides" inside "Brazie's Black Book of Secrets"
DELETE FROM `item_loot_template` WHERE `Entry`=49926 AND `Item` IN (49918, 49922, 49923, 49924, 49925);
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49926, 49918, 100, 0, 1, 0, 1, 1), -- Brazie's Guide to Getting Good with Gnomish Girls
(49926, 49922, 100, 0, 1, 0, 1, 1), -- Brazie's Dictionary of Devilish Draenei Damsels
(49926, 49923, 100, 0, 1, 0, 1, 1), -- Brazie's Document on Dwarven Dates in Dun Morogh
(49926, 49924, 100, 0, 1, 0, 1, 1), -- Brazie's Notes on Naughty Night Elves
(49926, 49925, 100, 0, 1, 0, 1, 1); -- Brazie's Handbook to Handling Human Hunnies
