-- 
DELETE FROM `game_event` WHERE `eventEntry` IN (79,80);
INSERT INTO `game_event` (`eventEntry`,`start_time`,`end_time`,`occurence`,`length`,`holiday`,`description`,`world_event`, announce) VALUES
(79, '2018-10-28 12:00:00', '2020-12-31 18:00:00',1440,360,0, 'Diurnal fishing event',0,2),
(80, '2018-10-28 00:00:00', '2020-12-31 06:00:00',1440,360,0, 'Nocturnal fishing event',0,2);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup` IN (11010,11008) AND `SourceEntry` IN (13760,13759);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10, 11010, 13760, 0, 0, 12, 0, 80, 0, 0, 1, 0, 0, "", "Raw Sunscale Salmon only when Nocturnal fishing event is off"),
(10, 11010, 13759, 0, 0, 12, 0, 79, 0, 0, 1, 0, 0, "", "Raw Nightfin Snapper only when Diurnal fishing event is off"),
(10, 11008, 13760, 0, 0, 12, 0, 80, 0, 0, 1, 0, 0, "", "Raw Sunscale Salmon only when Nocturnal fishing event is off"),
(10, 11008, 13759, 0, 0, 12, 0, 79, 0, 0, 1, 0, 0, "", "Raw Nightfin Snapper only when Diurnal fishing event is off");
