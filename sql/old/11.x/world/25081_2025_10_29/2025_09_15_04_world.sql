UPDATE `world_state` SET `Comment`='Bloody Tokens - The War Within Season 1 (Currency) - Max quantity' WHERE `ID`=26365;
UPDATE `world_state` SET `DefaultValue`=28 WHERE `ID`=26199;
UPDATE `world_state` SET `DefaultValue`=574 WHERE `ID`=26508;
UPDATE `world_state` SET `DefaultValue`=864 WHERE `ID`=26509;
UPDATE `world_state` SET `DefaultValue`=647 WHERE `ID`=26510;
UPDATE `world_state` SET `DefaultValue`=484 WHERE `ID`=26511;
UPDATE `world_state` SET `DefaultValue`=588 WHERE `ID`=26512;
UPDATE `world_state` SET `DefaultValue`=792 WHERE `ID`=26513;
UPDATE `world_state` SET `DefaultValue`=574 WHERE `ID`=26514;
UPDATE `world_state` SET `DefaultValue`=800 WHERE `ID`=26515;
UPDATE `world_state` SET `DefaultValue`=506 WHERE `ID`=26516;
UPDATE `world_state` SET `DefaultValue`=400 WHERE `ID`=26517;
UPDATE `world_state` SET `DefaultValue`=640 WHERE `ID`=26518;
UPDATE `world_state` SET `DefaultValue`=40 WHERE `ID` BETWEEN 26620 AND 26629;
UPDATE `world_state` SET `DefaultValue`=30 WHERE `ID`=26630;
UPDATE `world_state` SET `DefaultValue`=28 WHERE `ID`=26656;
UPDATE `world_state` SET `DefaultValue`=128 WHERE `ID`=26869;
UPDATE `world_state` SET `DefaultValue`=8 WHERE `ID`=27606;

DELETE FROM `world_state` WHERE `ID` IN (21865, 26898, 26979, 26983, 27168, 27169, 27170, 27191, 27226, 27326, 27335, 27346, 27793, 28158, 28182, 28388, 28390, 28441, 28538, 28715, 29245, 29713);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(21865, 0, NULL, NULL, '', 'Conquest - Shadowlands (Currency) - Max quantity'),
(26898, 275, NULL, NULL, '', 'Bronze Celebration Token (Currency) - Max quantity'),
(26979, 0, NULL, NULL, '', 'Weathered/Carved Undermine Crest (Currency) - Max quantity'),
(26983, 0, NULL, NULL, '', 'Gilded/Runed Undermine Crest (Currency) - Max quantity'),
(27168, 0, NULL, NULL, '', 'Conquest - The War Within Season 2 (Currency) - Max quantity'),
(27169, 0, NULL, NULL, '', 'Bloody Tokens - The War Within Season 2 (Currency) - Max quantity'),
(27170, 400000, NULL, NULL, '', 'Conquest - The War Within Season 3 (Currency) - Max quantity'),
(27191, 28, NULL, NULL, '', '11.1 Professions - Personal Tracker - S2 Spark Drops (Hidden) (Currency) - Max quantity'),
(27226, 28, NULL, NULL, '', '11.1 Delves - Personal Tracker - S2 Weekly Elise Turn-In(Hidden) (Currency) - Max quantity'),
(27326, 7, NULL, NULL, '', 'Starlight Spark Dust (Currency) - Max quantity'),
(27335, 140, NULL, NULL, '', '11.X Delves - Bountiful Tracker - Brann EXP Cap (Currency) - Max quantity'),
(27346, 4, NULL, NULL, '', '11.0 Delves - Vendor - Bountiful Key Tracker - Cap (Currency) - Max quantity'),
(27793, 1820, NULL, NULL, '', '11.X Delves - Bountiful Tracker - Progress Cap - Mislaid (Currency) - Max quantity'),
(28158, 5, NULL, NULL, '', '11.2 Delves - Personal Tracker - S3 Weekly Elise Turn-In(Hidden) (Currency) - Max quantity'),
(28182, 5000000, NULL, NULL, '', 'Gallagio Loyalty Rewards Club (Currency) - Max quantity'),
(28388, 540, NULL, NULL, '', 'Weathered/Carved Ethereal Crest (Currency) - Max quantity'),
(28390, 450, NULL, NULL, '', 'Gilded/Runed Ethereal Crest (Currency) - Max quantity'),
(28441, 355000, NULL, NULL, '', 'Bloody Tokens - The War Within Season 3 (Currency) - Max quantity'),
(28538, 15, NULL, NULL, '', 'Ethereal Strands (Currency) - Max quantity'),
(28715, 1250000, NULL, NULL, '', 'Manaforge Vandals (Currency) - Max quantity'),
(29245, 6, NULL, NULL, '', '11.1.5 Mid-Season - Turbo-Boost Quest Turn-In Tracker (Currency) - Max quantity'),
(29713, 6, NULL, NULL, '', 'Renown - Manaforge Vandals (Currency) - Max quantity');
