-- 
DELETE FROM `fishing_loot_template` WHERE `Item` IN (45323,45328,45903);
DELETE FROM `reference_loot_template` WHERE `Item` IN (45328);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(11024, 45328, 0, 10, 1, 1, 2, 1, 1, "");
DELETE FROM `conditions` WHERE `SourceGroup` IN (11026) AND `SourceTypeOrReferenceId`=10 AND `SourceEntry`=45328;
UPDATE `fishing_loot_template` SET `GroupID`=0 WHERE `entry` IN (4567,4560);
UPDATE `reference_loot_template` SET `GroupID`=1 WHERE `entry` IN (11024,11026);
UPDATE `reference_loot_template` SET `Chance`=6 WHERE `entry` IN (11024) AND `Item` IN (43658,43695,43696);
UPDATE `reference_loot_template` SET `GroupID`=2 WHERE `Item` IN (45328,45903);
