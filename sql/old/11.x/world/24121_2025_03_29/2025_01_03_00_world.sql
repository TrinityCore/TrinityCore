UPDATE `world_state` SET `DefaultValue`=476 WHERE `ID`=27335;
UPDATE `world_state` SET `DefaultValue`=104 WHERE `ID`=26869;
UPDATE `world_state` SET `DefaultValue`=17 WHERE `ID`=26656;
UPDATE `world_state` SET `DefaultValue`=19 WHERE `ID` IN (26199,26620,26621,26622,26623,26624,26625,26626,26627,26628,26629,26630);
UPDATE `world_state` SET `DefaultValue`=266 WHERE `ID`=26508;
UPDATE `world_state` SET `DefaultValue`=304 WHERE `ID`=26509;
UPDATE `world_state` SET `DefaultValue`=269 WHERE `ID`=26510;
UPDATE `world_state` SET `DefaultValue`=209 WHERE `ID`=26511;
UPDATE `world_state` SET `DefaultValue`=228 WHERE `ID`=26512;
UPDATE `world_state` SET `DefaultValue`=342 WHERE `ID`=26513;
UPDATE `world_state` SET `DefaultValue`=266 WHERE `ID`=26514;
UPDATE `world_state` SET `DefaultValue`=304 WHERE `ID`=26515;
UPDATE `world_state` SET `DefaultValue`=209 WHERE `ID`=26516;
UPDATE `world_state` SET `DefaultValue`=190 WHERE `ID`=26517;
UPDATE `world_state` SET `DefaultValue`=304 WHERE `ID`=26518;
UPDATE `world_state` SET `DefaultValue`=30 WHERE `ID`=25395;
UPDATE `world_state` SET `DefaultValue`=0 WHERE `ID` IN (26186,26365,25834,25833);

DELETE FROM `world_state` WHERE `ID` IN (27342, 27343, 27344, 27606);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(27342, 120, NULL, NULL, '', '11.0.5 20th Anniversary - Tracker 1 (Currency) - Max quantity'),
(27343, 120, NULL, NULL, '', '11.0.5 20th Anniversary - Tracker 2 (Currency) - Max quantity'),
(27344, 120, NULL, NULL, '', '11.0.5 20th Anniversary - Tracker 3 (Currency) - Max quantity'),
(27606, 6, NULL, NULL, '', '11.0 Raid - Nerubian - Account Quest Complete Tracker (Hidden) (Currency) - Max quantity');
