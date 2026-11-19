--
DELETE FROM `reference_loot_template` WHERE `Entry`=34279 AND `Item` IN (52025, 52026, 52027);
UPDATE `creature_loot_template` SET `MaxCount`=1, `Comment`="Mark of Sanctification (Heroic)" WHERE `Reference`=34279;
UPDATE `gameobject_loot_template` SET `MaxCount`=1, `comment`="Mark of Sanctification (Heroic)" WHERE `Reference`=34279;
DELETE FROM `creature_loot_template` WHERE `Entry` IN (38586, 38436, 38267, 39168) AND `Reference`=34278;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(38586, 2, 34278, 100, 0, 1, 0, 2, 2, "Mark of Sanctification (Normal)"),
(38436, 3, 34278, 100, 0, 1, 0, 2, 2, "Mark of Sanctification (Normal)"),
(38267, 3, 34278, 100, 0, 1, 0, 2, 2, "Mark of Sanctification (Normal)"),
(39168, 3, 34278, 100, 0, 1, 0, 2, 2, "Mark of Sanctification (Normal)");

DELETE FROM `gameobject_loot_template` WHERE `Entry`=28088 AND `Reference`=34278;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28088, 3, 34278, 100, 0, 1, 0, 2, 2, "Mark of Sanctification (Normal)");
