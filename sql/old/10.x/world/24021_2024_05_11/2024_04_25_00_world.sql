UPDATE `world_state` SET `DefaultValue`=192, `Comment`='Trophy of Strife - Dragonflight Season 3 (Currency) - Max quantity' WHERE `ID`=25259;
UPDATE `world_state` SET `DefaultValue`=0 WHERE `ID` IN (24880, 24882);

DELETE FROM `world_state` WHERE `ID` IN (25395,25413,25456,25457,25468,26001);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(25395, 2, NULL, NULL, '', '10.2.6 Professions - Personal Tracker - S4 Spark Drops (Hidden) (Currency) - Max quantity'),
(25413, 8, NULL, NULL, '', 'Trophy of Strife - Dragonflight Season 4 (Currency) - Max quantity'),
(25456, 120, NULL, NULL, '', 'Drake/Whelpling Awakened Crest (Currency) - Max quantity'),
(25457, 120, NULL, NULL, '', 'Aspect/Wyrm Awakened Crest (Currency) - Max quantity'),
(25468, 135000, NULL, NULL, '', 'Conquest - Dragonflight Season 4 (Currency) - Max quantity'),
(26001, 1, NULL, NULL, '', '10.2.6 Rewards - Personal Tracker - S4 Dinar Drops (Hidden) (Currency) - Max quantity');
