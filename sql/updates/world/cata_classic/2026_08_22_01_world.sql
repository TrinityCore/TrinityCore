DELETE FROM `world_state` WHERE `ID` IN (28186, 26145, 26146, 26147);
INSERT INTO `world_state` (`ID`, `MapIDs`, `DefaultValue`, `Comment`) VALUES
(28186, NULL, 1, 'Enable Elemental Rune Protocol Twilight Dungeons'),
(26145, NULL, 1, 'Enable End Time Dungeon'),
(26146, NULL, 1, 'Enable Well of Eternity Dungeon'),
(26147, NULL, 1, 'Enable Hour of Twilight Dungeon');
