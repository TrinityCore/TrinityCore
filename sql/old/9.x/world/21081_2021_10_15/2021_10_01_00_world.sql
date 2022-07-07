-- Solanian's Belongings
UPDATE `gameobject_template` SET `ContentTuningId`=1485, `VerifiedBuild`=40120 WHERE `entry` IN (180510,180511,180512);

UPDATE `gameobject_template_addon` SET `flags`=0 WHERE `entry` IN (180510,180511,180512);

UPDATE `gameobject_questitem` SET `VerifiedBuild`=40120 WHERE (`GameObjectEntry` IN (180510,180511,180512) AND `Idx`=0);

UPDATE `quest_objectives` SET `VerifiedBuild`=40120 WHERE `ID` IN (276220,256221,276222);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=40120 WHERE (`ID` IN (276220,276222) AND `Index`=0);

-- Solanian's Scrying Orb
UPDATE `gameobject_template` SET `data1`=180510 WHERE `entry`=180510;
DELETE FROM `gameobject_loot_template` WHERE `entry`=180510;
INSERT INTO `gameobject_loot_template` (`entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(180510, 20470, 0, 100, 0, 1, 0, 1, 1, '');

-- Scroll of Scourge Magic
UPDATE `gameobject_template` SET `data1`=180511 WHERE `entry`=180511;
DELETE FROM `gameobject_loot_template` WHERE `entry`=180511;
INSERT INTO `gameobject_loot_template` (`entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(180511, 20471, 0, 100.000, 0, 1, 0, 1, 1, ''),
(180511, 21007, 0, 0.30826, 0, 1, 0, 1, 1, '');

-- Solanian's Journal
UPDATE `gameobject_template` SET `data1`=180512 WHERE `entry`=180512;
DELETE FROM `gameobject_loot_template` WHERE `entry`=180512;
INSERT INTO `gameobject_loot_template` (`entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(180512, 20472, 0, 100, 0, 1, 0, 1, 1, '');
