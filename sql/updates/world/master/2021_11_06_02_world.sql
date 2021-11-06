-- 
UPDATE `creature_template` SET `lootid`=13159 WHERE `entry`=13159;

DELETE FROM `creature_loot_template` WHERE `Entry`=13159;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(13159, 1307, 0, 100, 0, 1, 0, 1, 1, 'Gold Pickup Schedule'),
(13159, 57122, 0, 100, 1, 1, 0, 1, 1, 'James Clark\'s Head');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 1 AND `SourceGroup`=13159 AND `SourceEntry`=1307;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(1, 13159, 1307, 0, 0, 14, 0, 123, 0, 0, 0, 'Looter has never finished nor has active quest The Collector (123)'),
(1, 13159, 1307, 0, 0, 6, 0, 469, 0, 0, 0, 'Looter belongs to Alliance');
