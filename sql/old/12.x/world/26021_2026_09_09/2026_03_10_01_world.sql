DELETE FROM `world_state` WHERE `ID` IN (29688, 30157, 27499, 27489, 27490, 27491, 27492, 27493, 27494, 27495, 27496, 27497, 27498, 27500, 27501, 27502, 27503, 27504, 27505, 27506, 27507, 27508, 27509, 27510, 27488, 29184, 29185, 31021, 31023, 31024, 31025, 30221, 30474);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES
(29688, 0, NULL, NULL, '', 'Conquest - Midnight Season 1 (Currency) - Max quantity'),
(30157, 0, NULL, NULL, '', 'Bloody Tokens - Midnight Season 1 (Currency) - Max quantity'),
(27499, 22, NULL, NULL, '', '12.x Professions - Tracker - Weekly Alchemy Knowledge (Currency) - Max quantity'),
(27489, 28, NULL, NULL, '', '12.x Professions - Tracker - Weekly Tailoring Knowledge (Currency) - Max quantity'),
(27490, 18, NULL, NULL, '', '12.x Professions - Tracker - Weekly Skinning Knowledge (Currency) - Max quantity'),
(27491, 20, NULL, NULL, '', '12.x Professions - Tracker - Weekly Mining Knowledge (Currency) - Max quantity'),
(27492, 36, NULL, NULL, '', '12.x Professions - Tracker - Weekly Leatherworking Knowledge (Currency) - Max quantity'),
(27493, 38, NULL, NULL, '', '12.x Professions - Tracker - Weekly Jewelcrafting Knowledge (Currency) - Max quantity'),
(27494, 40, NULL, NULL, '', '12.x Professions - Tracker - Weekly Inscription Knowledge (Currency) - Max quantity'),
(27495, 24, NULL, NULL, '', '12.x Professions - Tracker - Weekly Herbalism Knowledge (Currency) - Max quantity'),
(27496, 22, NULL, NULL, '', '12.x Professions - Tracker - Weekly Engineering Knowledge (Currency) - Max quantity'),
(27497, 30, NULL, NULL, '', '12.x Professions - Tracker - Weekly Enchanting Knowledge (Currency) - Max quantity'),
(27498, 36, NULL, NULL, '', '12.x Professions - Tracker - Weekly Blacksmithing Knowledge (Currency) - Max quantity'),
(27500, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Tailoring Knowledge (Currency) - Max quantity'),
(27501, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Skinning Knowledge (Currency) - Max quantity'),
(27502, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Mining Knowledge (Currency) - Max quantity'),
(27503, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Leatherworking Know. (Currency) - Max quantity'),
(27504, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Jewelcrafting Knowledge (Currency) - Max quantity'),
(27505, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Inscription Knowledge (Currency) - Max quantity'),
(27506, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Herbalism Knowledge (Currency) - Max quantity'),
(27507, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Engineering Knowledge (Currency) - Max quantity'),
(27508, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Enchanting Knowledge (Currency) - Max quantity'),
(27509, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Blacksmithing Knowledge (Currency) - Max quantity'),
(27510, 1, NULL, NULL, '', '12.x Professions - Tracker - Insc Book - Alchemy Knowledge (Currency) - Max quantity'),
(27488, 1, NULL, NULL, '', 'Radiant Spark Dust (Currency) - Max quantity'),
(29184, 200, NULL, NULL, '', 'Veteran/Champion/Adventurer Dawncrest (Currency) - Max quantity'),
(29185, 0, NULL, NULL, '', 'Hero/Myth Dawncrest (Currency) - Max quantity'),
(31021, 18, NULL, NULL, '', 'Renown - The Amani Tribe (Currency) - Max quantity'),
(31023, 18, NULL, NULL, '', 'Renown - The Hara''ti (Currency) - Max quantity'),
(31024, 18, NULL, NULL, '', 'Renown - Silvermoon Court (Currency) - Max quantity'),
(31025, 18, NULL, NULL, '', 'Renown - The Singularity (Currency) - Max quantity'),
(30221, 0, NULL, NULL, '', '12.0 Delves - Personal Tracker - S1 Weekly Turn-In (Hidden) (Currency) - Max quantity'),
(30474, 0, NULL, NULL, '', '12.0 Midseason - Voidforge Unlock - Turn-In Tracker (Currency) - Max quantity');

UPDATE `world_state` SET `Comment`='Valor (Currency) - Max quantity' WHERE `ID`=22980;
UPDATE `world_state` SET `DefaultValue`=812, `Comment`='EVERGREEN Delves - Tracker - EoD Account Rewards - Weekly Cap (Currency) - Max quantity' WHERE `ID`=27335;
UPDATE `world_state` SET `DefaultValue`=10556, `Comment`='EVERGREEN Delves - Tracker - Mislaid Curiosity - Weekly Cap (Currency)- Max quantity' WHERE `ID`=27793;
UPDATE `world_state` SET `DefaultValue`=0 WHERE `ID` IN (27170,28388,28390,28441);
UPDATE `world_state` SET `DefaultValue`=30 WHERE `ID`=27326;
UPDATE `world_state` SET `DefaultValue`=28 WHERE `ID`=28158;
UPDATE `world_state` SET `DefaultValue`=3500000 WHERE `ID`=28715;
UPDATE `world_state` SET `DefaultValue`=6 WHERE `ID`=29600;
