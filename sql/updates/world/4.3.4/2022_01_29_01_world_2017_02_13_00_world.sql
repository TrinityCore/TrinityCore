
-- To the Looter Go the Spoils (1166)
DELETE FROM `creature_loot_template` WHERE `entry`=1 AND `item`=18228;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `IsCurrency`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(1, 18228, 0, 1, 0, 0, 1, 0, 1, 1, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=1 AND `SourceEntry` IN(18228);
INSERT INTO `conditions` VALUES (1, 1, 18228, 0, 0, 22, 0, 30, 0, 0, 0, 0, 0, '', 'Requires map Alterac Valley');

-- Add Player Loot for WG quests
DELETE FROM `creature_loot_template` WHERE `entry`=1 AND `item` IN(43314, 43322, 43323, 43324, 44808, 44809);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `IsCurrency`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(1, 43314, 0, 100, 1, 0, 1, 0, 5, 5, ''),
(1, 43322, 0, 100, 1, 0, 1, 0, 5, 5, ''),
(1, 43323, 0, 100, 1, 0, 1, 0, 5, 5, ''),
(1, 43324, 0, 100, 1, 0, 1, 0, 5, 5, ''),
(1, 44808, 0, 100, 1, 0, 1, 0, 5, 5, ''),
(1, 44809, 0, 100, 1, 0, 1, 0, 5, 5, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=1 AND `SourceEntry` IN(43314, 43322, 43323, 43324, 44808, 44809);
INSERT INTO `conditions` VALUES (1, 1, 44808, 0, 0, 23, 0, 4585, 0, 0, 0, 0, 0, '', 'Requires Glacial Falls area'),
(1, 1, 43322, 0, 0, 23, 0, 4585, 0, 0, 0, 0, 0, '', 'Requires Glacial Falls area'),
(1, 1, 43314, 0, 0, 23, 0, 4584, 0, 0, 0, 0, 0, '', 'Requires Cauldron of Flames area'),
(1, 1, 43323, 0, 0, 23, 0, 4587, 0, 0, 0, 0, 0, '', 'Requires Forest of Shadows area'),
(1, 1, 43324, 0, 0, 23, 0, 4590, 0, 0, 0, 0, 0, '', 'Requires Steppe of Life area'),
(1, 1, 44809, 0, 0, 23, 0, 4590, 0, 0, 0, 0, 0, '', 'Requires Steppe of Life area');
