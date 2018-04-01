-- FULL `creature_loot_template` of Entry 42937
DELETE FROM `creature_loot_template` WHERE (Entry = 42937);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(42937, 117, 0, 1.4323, 0, 1, 0, 1, 1, ''),
(42937, 159, 0, 0.8, 0, 1, 0, 1, 1, ''),
(42937, 782, 0, 0.001, 0, 1, 0, 1, 1, ''),
(42937, 805, 0, 0.1355, 0, 1, 0, 1, 1, ''),
(42937, 828, 0, 0.1623, 0, 1, 0, 1, 1, ''),
(42937, 1019, 0, 0.0019, 0, 1, 0, 1, 1, ''),
(42937, 1438, 0, 0.001, 0, 1, 0, 1, 1, ''),
(42937, 1468, 0, 0.0019, 0, 1, 0, 1, 1, ''),
(42937, 2886, 0, 0.001, 0, 1, 0, 1, 1, ''),
(42937, 4496, 0, 0.1623, 0, 1, 0, 1, 1, ''),
(42937, 5571, 0, 0.1537, 0, 1, 0, 1, 1, ''),
(42937, 5572, 0, 0.1172, 0, 1, 0, 1, 1, ''),
(42937, 23685, 0, 0.0029, 0, 1, 0, 1, 1, ''),
(42937, 58361, 0, 100, 1, 1, 0, 1, 1, '');

-- Table `creature_template`
UPDATE `creature_template` SET `npcflag` = 0 WHERE (entry = 50039);

DELETE FROM creature_queststarter WHERE quest = 31147;
DELETE FROM creature_questender WHERE quest = 31147;

-- Table quest_template_addon
UPDATE quest_template_addon SET AllowableClasses = 2048 WHERE (ID = 42739);
UPDATE quest_template_addon SET AllowableClasses = 2048 WHERE (ID = 42736);
UPDATE quest_template_addon SET AllowableClasses = 2048 WHERE (ID = 42738);
UPDATE quest_template_addon SET AllowableClasses = 2048 WHERE (ID = 42737);
