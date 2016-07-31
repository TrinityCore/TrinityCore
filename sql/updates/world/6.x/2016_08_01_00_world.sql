-- Clear errors on some unused gameobjects
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (753, 2008, 2027, 2229, 3377, 14733, 18156, 20045);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(753, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot'),
(2008, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot'),
(2027, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot'),
(2229, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot'),
(3377, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot'),
(14733, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot'),
(18156, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot'),
(20045, 38, 0, 100, 0, 0, 0, 1, 1, 'Unused loot Recruit''s Shirt added to clear error. This will be deleted when disables support disable loot');
