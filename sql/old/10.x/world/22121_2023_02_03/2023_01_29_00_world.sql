DELETE FROM `world_state` WHERE `ID` IN (19735, 20084, 20838, 22869, 22980);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(19735, 79, -1, NULL, '', 'Covenant Renown (Currency) - Max quantity'),
(20084, 0, -1, NULL, '', 'Shadowlands PvP Weekly Reward Progress (Currency) - Max quantity'),
(20838, 3510, -1, NULL, '', 'Tower Knowledge (Currency) - Max quantity'),
(22869, 245000, -1, NULL, '', 'Conquest (Currency) - Max quantity'),
(22980, 3000, -1, NULL, '', 'Valor (Currency) - Max quantity');
