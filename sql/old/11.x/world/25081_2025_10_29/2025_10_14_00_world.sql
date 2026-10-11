DELETE FROM `world_state` WHERE `ID` IN (841, 1350, 1963, 2139, 2286, 3010, 4009, 4488, 12169, 13445, 26010, 27475);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(841, 0, NULL, NULL, '', 'Holiday - Feast of Winter Veil'),
(1350, 0, NULL, NULL, '', 'Holiday - Noblegarden'),
(1963, 0, NULL, NULL, '', 'Holiday - Hallow''s End'),
(2139, 0, NULL, NULL, '', 'Holiday - Lunar Festival'),
(2286, 0, NULL, NULL, '', 'Holiday - Midsummer Fire Festival'),
(3010, 0, NULL, NULL, '', 'Holiday - Brewfest'),
(4009, 0, NULL, NULL, '', 'Holiday - Pilgrim''s Bounty'),
(4488, 0, NULL, NULL, '', 'Holiday - Love is in the Air'),
(12169, 0, NULL, NULL, '', 'Holiday - WoW''s Anniversary'),
(13445, 0, NULL, NULL, '', 'Holiday - Trial of Style'),
(26010, 0, NULL, NULL, '', 'Holiday - WoW''s 20th Anniversary'),
(27475, 0, NULL, NULL, '', 'Holiday - Dastardly Duos');

UPDATE `game_event` SET `WorldStateId`=841 WHERE `eventEntry`=2;
UPDATE `game_event` SET `WorldStateId`=1350 WHERE `eventEntry`=9;
UPDATE `game_event` SET `WorldStateId`=1963 WHERE `eventEntry`=12;
UPDATE `game_event` SET `WorldStateId`=2139 WHERE `eventEntry`=7;
UPDATE `game_event` SET `WorldStateId`=2286 WHERE `eventEntry`=1;
UPDATE `game_event` SET `WorldStateId`=3010 WHERE `eventEntry`=24;
UPDATE `game_event` SET `WorldStateId`=4009 WHERE `eventEntry`=26;
UPDATE `game_event` SET `WorldStateId`=4488 WHERE `eventEntry`=8;
UPDATE `game_event` SET `WorldStateId`=26010 WHERE `eventEntry`=89;
