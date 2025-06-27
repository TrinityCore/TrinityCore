DELETE FROM `gameobject_loot_template` WHERE `Entry`=26782;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(26782, 44724, 0, 100, 0, 1, 1, 1, 1, NULL), -- Everfrost Chip
(26782, 44725, 0, 19, 0, 1, 2, 1, 1, NULL), -- Everfrost Chip (Quest Starter)
(26782, 44729, 0, 81, 0, 1, 2, 1, 1, NULL); -- Everfrost Powder

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=4 AND `SourceGroup`=26782;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(4, 26782, 44724, 0, 1, 8, 0, 13420, 0, 0, 0, 0, 0, '', NULL), -- Everfrost Chip  only drops if player is rewarded for ever frost,
(4, 26782, 44729, 0, 0, 9, 0, 13420, 0, 0, 1, 0, 0, '', NULL), -- Everfrost powder only drops if player has not taken or completed Everfrost,
(4, 26782, 44729, 0, 0, 8, 0, 13420, 0, 0, 1, 0, 0, '', NULL), -- Everfrost powder only drops if player has not taken or completed Everfrost,
(4, 26782, 44725, 0, 0, 9, 0, 13420, 0, 0, 1, 0, 0, '', NULL), -- Everfrost Chip (Quest Starter) only drops if player has not taken or completed Everfrost,
(4, 26782, 44725, 0, 0, 8, 0, 13420, 0, 0, 1, 0, 0, '', NULL), -- Everfrost Chip (Quest Starter) only drops if player has not taken or completed Everfrost,
(4, 26782, 44725, 0, 0, 5, 0, 1119, 8, 0, 0, 0, 0, '', NULL); -- Everfrost Chip (Quest Starter) only drops if player is friendly with Sons of Hodir,

UPDATE `quest_template_addon` SET `SpecialFlags`=1 WHERE  `ID`=13421;

DELETE FROM `creature_questender` WHERE `quest`=13421;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(32594, 13421);

DELETE FROM `creature_queststarter` WHERE `quest`=13421;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(32594, 13421);

UPDATE `quest_template_addon` SET `PrevQuestID`=13420 WHERE  `ID`=13421;
