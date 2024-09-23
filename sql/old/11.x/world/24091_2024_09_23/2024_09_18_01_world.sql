UPDATE `world_state` SET `DefaultValue`=240 WHERE `ID`=25259;
UPDATE `world_state` SET `DefaultValue`=23 WHERE `ID`=25395;
UPDATE `world_state` SET `DefaultValue`=18 WHERE `ID`=26001;
UPDATE `world_state` SET `DefaultValue`=0 WHERE `ID` IN (25468, 25456, 25457, 25413);

DELETE FROM `world_state` WHERE `ID` IN (25833,25834,26186,26199,26365,26508,26509,26510,26511,26512,26513,26514,26515,26516,26517,26518,26620,26621,26622,26623,26624,26625,26626,26627,26628,26629,26630,26656,26869,27335);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(25833, 450, NULL, NULL, '', 'Weathered/Carved Harbinger Crest (Currency) - Max quantity'),
(25834, 180, NULL, NULL, '', 'Gilded/Runed Harbinger Crest (Currency) - Max quantity'),
(26186, 220000, NULL, NULL, '', 'Conquest - The War Within Season 1 (Currency) - Max quantity'),
(26199, 4, NULL, NULL, '', '11.0 Professions - Personal Tracker - S1 Spark Drops (Hidden) (Currency) - Max quantity'),
(26365, 190000, NULL, NULL, '', 'Bloody Tokens (Currency) - Max quantity'),
(26508, 56, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Alchemy Knowledge (Currency) - Max quantity'),
(26509, 64, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Blacksmithing Knowledge (Currency) - Max quantity'),
(26510, 59, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Enchanting Knowledge (Currency) - Max quantity'),
(26511, 44, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Engineering Knowledge (Currency) - Max quantity'),
(26512, 48, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Herbalism Knowledge (Currency) - Max quantity'),
(26513, 72, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Inscription Knowledge (Currency) - Max quantity'),
(26514, 56, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Jewelcrafting Knowledge (Currency) - Max quantity'),
(26515, 64, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Leatherworking Knowledge (Currency) - Max quantity'),
(26516, 44, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Mining Knowledge (Currency) - Max quantity'),
(26517, 40, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Skinning Knowledge (Currency) - Max quantity'),
(26518, 64, NULL, NULL, '', '11.0 Professions - Tracker - Weekly Tailoring Knowledge (Currency) - Max quantity'),
(26620, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Tailoring Knowledge (Currency) - Max quantity'),
(26621, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Skinning Knowledge (Currency) - Max quantity'),
(26622, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Mining Knowledge (Currency) - Max quantity'),
(26623, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Leatherworking Know. (Currency) - Max quantity'),
(26624, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Jewelcrafting Knowledge (Currency) - Max quantity'),
(26625, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Inscription Knowledge (Currency) - Max quantity'),
(26626, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Herbalism Knowledge (Currency) - Max quantity'),
(26627, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Engineering Knowledge (Currency) - Max quantity'),
(26628, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Enchanting Knowledge (Currency) - Max quantity'),
(26629, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Blacksmithing Knowledge (Currency) - Max quantity'),
(26630, 4, NULL, NULL, '', '11.0 Professions - Tracker - Insc Book - Alchemy Knowledge (Currency) - Max quantity'),
(26656, 2, NULL, NULL, '', '11.0 Delves - Personal Tracker - S1 Weekly Elise Turn-In(Hidden) (Currency) - Max quantity'),
(26869, 0, NULL, NULL, '', 'Nerub-ar Finery (Currency) - Max quantity'),
(27335, 56, NULL, NULL, '', 'Delver''s Journey (Currency) - Max quantity');
