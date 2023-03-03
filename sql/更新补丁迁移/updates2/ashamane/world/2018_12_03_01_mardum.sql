UPDATE creature SET phaseId = 170 WHERE guid IN (20540916, 20540920, 20540915, 20540918, 20540919, 20540917);

DELETE FROM `creature_loot_template` WHERE (Entry = 95226);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(95226, 128227, 0, 100, 1, 1, 0, 1, 1, 'Legion key'),
(95226, 129196, 0, 1,   0, 1, 0, 1, 1, 'Legion Healthstone'),
(95226, 130264, 0, 6,   0, 1, 0, 1, 1, 'Fel-Stained Claw'),
(95226, 130265, 0, 1,   0, 1, 0, 1, 1, 'Sharpened Canine'),
(95226, 130266, 0, 0.3, 0, 1, 0, 1, 1, 'Trophy Spine'),
(95226, 130267, 0, 87,  0, 1, 0, 1, 1, 'Extinguished Demon Stone'),
(95226, 130268, 0, 13,  0, 1, 0, 1, 1, 'Bone Toothpick'),
(95226, 130317, 0, 3,   0, 1, 0, 1, 1, 'Fractured Trophy');

UPDATE `creature_template` SET `AIName` = '' WHERE (entry = 93221);
UPDATE creature SET phaseID = 0 WHERE id = 96655;

DELETE FROM `creature_loot_template` WHERE (Entry = 93802);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(93802, 124672, 0, 100, 1, 1, 0, 1, 1, 'Sargerite Keystone'),
(93802, 129196, 0, 7, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(93802, 130267, 0, 42, 0, 1, 0, 1, 1, 'Extinguished Demon Stone'),
(93802, 130268, 0, 44, 0, 1, 0, 1, 1, 'Bone Toothpick'),
(93802, 130317, 0, 15, 0, 1, 0, 1, 1, 'Fractured Trophy');

DELETE FROM `spell_area` WHERE `spell` = 193387 AND area = 1;
INSERT INTO `spell_area` (`spell`, `area`, `flags`) VALUES
('193387', '1', '0');
