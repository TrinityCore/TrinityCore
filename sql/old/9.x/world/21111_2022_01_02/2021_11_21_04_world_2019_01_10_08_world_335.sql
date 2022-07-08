-- 
DELETE FROM `reference_loot_template` WHERE `Entry` IN (11009,11105) AND `Item`=13755;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(11009, 13755, 0, 15, 0, 1, 1, 1, 1, ""),
(11105, 13755, 0, 20, 0, 1, 1, 1, 1, "");

DELETE FROM `game_event` WHERE `eventEntry`=78;
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`, announce) VALUES
(78, '2019-03-20 06:00:00', '2019-09-22 05:00:00',525600,262800,0, 'Summer seasonal fish',0,2);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup` IN (11009,11105) AND `SourceEntry` IN (13755,13756);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10, 11009, 13756, 0, 0, 12, 0, 78, 0, 0, 0, 0, 0, "", "Raw Summer Bass during Summer seasonal fish only"),
(10, 11105, 13756, 0, 0, 12, 0, 78, 0, 0, 0, 0, 0, "", "Raw Summer Bass during Summer seasonal fish only"),
(10, 11009, 13755, 0, 0, 12, 0, 78, 0, 0, 1, 0, 0, "", "Winter Squid only when Summer seasonal fish is off"),
(10, 11105, 13755, 0, 0, 12, 0, 78, 0, 0, 1, 0, 0, "", "Winter Squid only when Summer seasonal fish is off");
