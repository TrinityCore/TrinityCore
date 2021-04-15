-- Spectral Mount Crate & Moonkin Egg
DELETE FROM `item_loot_template` WHERE `entry` IN (77956,68384);
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(77956, 76889, 100, 1, 0, 1, 1),
(77956, 76902, 100, 1, 0, 1, 1),
(68384, 68618, 100, 1, 0, 1, 1),
(68384, 68619, 100, 1, 0, 1, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=5 AND `SourceGroup` IN (77956,68384);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(5, 77956, 76889, 0, 0, 6, 0, 469, 0, 0, 0, 0, '', 'Spectral Gryphon Must Be Alliance'),
(5, 77956, 76902, 0, 0, 6, 0, 67, 0, 0, 0, 0, '', 'Spectral Wind Rider Must Be Horde'),
(5, 68384, 68618, 0, 0, 6, 0, 469, 0, 0, 0, 0, '', 'Moonkin Hatchling Must Be Alliance'),
(5, 68384, 68619, 0, 0, 6, 0, 67, 0, 0, 0, 0, '', 'Moonkin Hatchling Must Be Horde');

DELETE FROM `player_factionchange_items` WHERE `alliance_id` IN (76889,68618) AND `horde_id` IN (76902,68619);
INSERT INTO `player_factionchange_items` (`race_A`, `alliance_id`, `commentA`, `race_H`, `horde_id`, `commentH`) VALUES
(0, 76889, 'Spectral Gryphon', 0, 76902, 'Spectral Wind Rider'),
(0, 68618, 'Moonkin Hatchling', 0, 68619, 'Moonkin Hatchling');

DELETE FROM `player_factionchange_spells` WHERE `alliance_id` IN (107516,95786) AND `horde_id` IN (107517,95909);
INSERT INTO `player_factionchange_spells` (`alliance_id`, `horde_id`) VALUES
(107516, 107517), --  Spectral Wind Rider ←→ Spectral Wind Rider
(95786, 95909); --  Moonkin Hatchling ←→ Moonkin Hatchling
