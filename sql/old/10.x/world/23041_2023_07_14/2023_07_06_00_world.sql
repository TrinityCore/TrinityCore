UPDATE `world_state` SET `DefaultValue`=0, `Comment`='Valor - Dragonflight (Currency) - Max quantity' WHERE `ID`=22980;
UPDATE `world_state` SET `DefaultValue`=0, `Comment`='Conquest - Dragonflight Season 1 (Currency) - Max quantity' WHERE  `ID`=22869;

DELETE FROM `world_state` WHERE `ID` IN (20659,23730,23970,23747);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(20659, 0, -1, NULL, '', 'Valor - Shadowlands (Currency) - Max quantity'),
(23730, 1200, -1, NULL, '', 'Aspect/Wyrm Crest Fragment Tracker (Currency) - Max quantity'),
(23970, 1350, -1, NULL, '', 'Drake/Whelpling Crest Fragment Tracker (Currency) - Max quantity'),
(23747, 520000, -1, NULL, '', 'Conquest - Dragonflight Season 2 (Currency) - Max quantity');
