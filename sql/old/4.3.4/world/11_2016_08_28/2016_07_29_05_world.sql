-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=1594 AND `Item`=3255;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(1594, 3255, 0, 100, 1, 1, 0, 1, 1, 'Gameobject Berard''s Bookshelf holds Loot item Berard''s Journal');

UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry` IN (706,946,7073,37070,37105,37507);
UPDATE `creature_template` SET `mingold`=3, `maxgold`=8 WHERE `entry` IN (808);
