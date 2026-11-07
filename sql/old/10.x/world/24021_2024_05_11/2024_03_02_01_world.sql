UPDATE `world_state` SET `DefaultValue`=0 WHERE `ID` IN (23730, 23747, 23970);

DELETE FROM `world_state` WHERE `ID` IN (24880,24882,24906,25146,25219,25259);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(24880, 1260, NULL, NULL, '', 'Drake/Whelpling Dreaming Crest (Currency) - Max quantity'),
(24882, 1170, NULL, NULL, '', 'Aspect/Wyrm Dreaming Crest (Currency) - Max quantity'),
(24906, 0, NULL, NULL, '', 'Conquest - Dragonflight Season 3 (Currency) - Max quantity'),
(25146, 1000, NULL, NULL, '', 'Echoed Ephemera Tracker (Currency) - Max quantity'),
(25219, 0, NULL, NULL, '', '10.2 Legendary - Progressive Advance - Tracker (Currency) - Max quantity'),
(25259, 104, NULL, NULL, '', 'Trophy of Strife (Currency) - Max quantity');
