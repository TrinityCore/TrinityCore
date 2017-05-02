-- 
DELETE FROM `spell_group` WHERE `id`=1083 AND `spell_id`=-1080;
UPDATE `creature` SET `equipment_id`=0 WHERE `id` IN (40971, 40970);
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN (307491);
UPDATE `quest_template_addon` SET `ProvidedItemCount`=1 WHERE `id` IN (24471);
UPDATE `creature_template` SET `lootid`=808 WHERE `entry`=808;
UPDATE `creature_template` SET `lootid`=37070  WHERE `entry`=37070 ;

DELETE FROM `reference_loot_template` WHERE `Entry` IN (43415);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(43415,56376, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56366, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56367, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56370, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56368, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56369, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56371, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56374, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56375, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,56373, 0, 0, 0, 1, 1, 1, 1, ""),
(43415,52506, 0, 100, 1, 1, 2, 1, 1, "");
