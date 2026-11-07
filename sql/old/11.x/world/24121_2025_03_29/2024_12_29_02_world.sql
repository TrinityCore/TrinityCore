DELETE FROM `creature_loot_template` WHERE `Entry`=150228 AND `ItemType`=0 AND `Item` BETWEEN 174791 AND 174794;
DELETE FROM `creature_loot_template` WHERE `Entry`=150237 AND `ItemType`=0 AND `Item` BETWEEN 174811 AND 174814;
DELETE FROM `creature_loot_template` WHERE `Entry`=162817 AND `ItemType`=0 AND `Item`=176398;
DELETE FROM `creature_loot_template` WHERE `Entry`=150228 AND `ItemType`=1 AND `Item`=150228;
DELETE FROM `creature_loot_template` WHERE `Entry`=150237 AND `ItemType`=1 AND `Item`=150237;
DELETE FROM `creature_loot_template` WHERE `Entry`=162817 AND `ItemType`=1 AND `Item`=162817;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(150228, 1, 150228, 20, 0, 1, 0, 1, 1, 'Murloc Spearhunter/Watershaper - boots'),
(150237, 1, 150237, 20, 0, 1, 0, 1, 1, 'Quilboar Warrior/Geomancer - chest armor'),
(162817, 1, 162817, 100, 0, 1, 0, 1, 1, 'Torgok - Torgok''s Reagent Pouch');

DELETE FROM `reference_loot_template` WHERE `Entry` IN (150228,150237,162817);
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(150228, 0, 174791, 100, 0, 1, 0, 1, 1, 'Exile''s Reach boot drop from murlocs - Stitched Cloth Shoes'),
(150228, 0, 174792, 100, 0, 1, 0, 1, 1, 'Exile''s Reach boot drop from murlocs - Stitched Leather Boots'),
(150228, 0, 174793, 100, 0, 1, 0, 1, 1, 'Exile''s Reach boot drop from murlocs - Linked Mail Boots'),
(150228, 0, 174794, 100, 0, 1, 0, 1, 1, 'Exile''s Reach boot drop from murlocs - Dented Plate Boots'),
(150228, 3, 58883, 100, 0, 1, 0, 1, 0, 'Exile''s Reach boot drop from murlocs - Tracking quest flag'),
(150237, 0, 174811, 100, 0, 1, 0, 1, 1, 'Exile''s Reach chest drop from quilboar - Stitched Cloth Tunic'),
(150237, 0, 174812, 100, 0, 1, 0, 1, 1, 'Exile''s Reach chest drop from quilboar - Stitched Leather Tunic'),
(150237, 0, 174813, 100, 0, 1, 0, 1, 1, 'Exile''s Reach chest drop from quilboar - Linked Mail Hauberk'),
(150237, 0, 174814, 100, 0, 1, 0, 1, 1, 'Exile''s Reach chest drop from quilboar - Dented Chestplate'),
(150237, 3, 58882, 100, 0, 1, 0, 1, 0, ' Exile''s Reach chest drop from quilboar - Tracking quest flag'),
(162817, 0, 176398, 100, 0, 1, 0, 1, 1, 'Exile''s Reach Torgok - Torgok''s Reagent Pouch'),
(162817, 3, 59610, 100, 0, 1, 0, 1, 0, ' Exile''s Reach Torgok - Torgok''s Reagent Pouch - Tracking quest flag');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=150228;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=150237;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=162817;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=150228;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=150237;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=162817;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10, 150228, 174791, 0, 0, 15, 0, 400, 0, 0, '', 0, 0, 0, '', 'Item drops for cloth wearer'),
(10, 150228, 174792, 0, 0, 15, 0, 3592, 0, 0, '', 0, 0, 0, '', 'Item drops for leather wearer'),
(10, 150228, 174793, 0, 0, 15, 0, 4164, 0, 0, '', 0, 0, 0, '', 'Item drops for mail wearer'),
(10, 150228, 174794, 0, 0, 15, 0, 35, 0, 0, '', 0, 0, 0, '', 'Item drops for plate wearer'),
(10, 150228, 174791, 0, 0, 47, 0, 58883, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58883 is not rewarded'),
(10, 150228, 174792, 0, 0, 47, 0, 58883, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58883 is not rewarded'),
(10, 150228, 174793, 0, 0, 47, 0, 58883, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58883 is not rewarded'),
(10, 150228, 174794, 0, 0, 47, 0, 58883, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58883 is not rewarded'),
(10, 150237, 174811, 0, 0, 15, 0, 400, 0, 0, '', 0, 0, 0, '', 'Item drops for cloth wearer'),
(10, 150237, 174812, 0, 0, 15, 0, 3592, 0, 0, '', 0, 0, 0, '', 'Item drops for leather wearer'),
(10, 150237, 174813, 0, 0, 15, 0, 4164, 0, 0, '', 0, 0, 0, '', 'Item drops for mail wearer'),
(10, 150237, 174814, 0, 0, 15, 0, 35, 0, 0, '', 0, 0, 0, '', 'Item drops for plate wearer'),
(10, 150237, 174811, 0, 0, 47, 0, 58882, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58882 is not rewarded'),
(10, 150237, 174812, 0, 0, 47, 0, 58882, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58882 is not rewarded'),
(10, 150237, 174813, 0, 0, 47, 0, 58882, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58882 is not rewarded'),
(10, 150237, 174814, 0, 0, 47, 0, 58882, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 58882 is not rewarded'),
(10, 162817, 176398, 0, 0, 47, 0, 59610, 64, 0, '', 1, 0, 0, '', 'Item drops if quest 59610 is not rewarded');

UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName`='npc_murloc_spearhunter_watershaper';
