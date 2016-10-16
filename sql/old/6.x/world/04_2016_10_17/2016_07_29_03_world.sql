-- Add items to gameobject_loot_template for Gameobject Royal Cache
DELETE FROM `gameobject_loot_template` WHERE `Entry`=40353;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(40353, 72833, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Royal Cache contains Loot item Scepter of Azshara'),
(40353, 72834, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Royal Cache contains Loot item Breastplate of the Queen''s Guard'),
(40353, 72835, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Royal Cache contains Loot item Puppeteer''s Pantaloons'),
(40353, 72836, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Royal Cache contains Loot item Slippers of Wizardry'),
(40353, 72837, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Royal Cache contains Loot item Queen''s Boon'),
(40353, 72838, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Royal Cache contains Loot item Cloak of the Royal Protector');

-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=28561;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28561, 22739, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Blackbelly Mudfish School contains Loot item Tome of Polymorph: Turtle'),
(28561, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Blackbelly Mudfish School contains Loot item Sea Turtle'),
(28561, 52326, 0, 9.98, 0, 1, 1, 1, 1, 'Gameobject Blackbelly Mudfish School contains Loot item Volatile Water'),
(28561, 53066, 0, 90, 0, 1, 1, 1, 1, 'Gameobject Blackbelly Mudfish School contains Loot item Blackbelly Mudfish');
