DELETE FROM `broadcast_text_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0 AND `ID` IN (201778, 753, 195400, 79796, 165870, 79799, 79798, 79804, 194274, 183984, 201777, 79794, 79795, 141708, 201784, 165241, 165243, 165245, 165239, 165246, 165244, 165237);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(201778, 'deDE', 'Wir sind so weit. Geht voran!', 'Wir sind so weit. Geht voran!', 35435),
(753, 'deDE', 'Was? Soll das heißen, Ihr könnt den hier nicht selbst töten?', '', 35435),
(195400, 'deDE', 'Zeigt mir bitte Eure synthetisierten Essenzen.', 'Zeigt mir bitte Eure synthetisierten Essenzen.', 35435),
(79796, 'deDE', 'Entdeckter Schamanenstein: Feuerberührung', 'Entdeckter Schamanenstein: Feuerberührung', 35435),
(165870, 'deDE', '', 'Ich werde Euch von Rastakhans Fall erzählen, wenn Ihr so weit seid.', 35435),
(79799, 'deDE', 'Entdeckter Schamanenstein: Ogerkraft', 'Entdeckter Schamanenstein: Ogerkraft', 35435),
(79798, 'deDE', 'Entdeckter Schamanenstein: Stürmische Zornböen', 'Entdeckter Schamanenstein: Stürmische Zornböen', 35435),
(79804, 'deDE', 'Entdeckter Schamanenstein: Eisberührung', 'Entdeckter Schamanenstein: Eisberührung', 35435),
(194274, 'deDE', 'I want to teleport to Operation: Mechagon (Dungeon).', 'I want to teleport to Operation: Mechagon (Dungeon).', 35435),
(183984, 'deDE', '|cfff2e699+$1i geistige Gesundheit|r', '|cfff2e699+$1i geistige Gesundheit|r', 35435),
(201777, 'deDE', '', 'Ich weiß, wie wir die Tochter der See erreich\'n können. Mir nach, wenn Ihr bereit seid.', 35435),
(79794, 'deDE', 'Entdeckter Schamanenstein: Segen des Wolfs', 'Entdeckter Schamanenstein: Segen des Wolfs', 35435),
(79795, 'deDE', 'Entdeckter Schamanenstein: Geist des Wolfs', 'Entdeckter Schamanenstein: Geist des Wolfs', 35435),
(141708, 'deDE', 'Schwächt den Greifen, aber Ihr solltet Euch dabei trotzdem gut|TInterface\\ICONS\\INV_MISC_DESECRATED_LEATHERGLOVE.BLP:20|t |cFFFF0000|Hspell:269442|h[Festhalten]|h|r!', '', 35435),
(201784, 'deDE', 'Ich habe es mit eigenen Augen gesehen! Lady Jaina wurde auf hoher See angegriffen!', '', 35435),
(165241, 'deDE', 'Tiefer, immer tiefer...', 'Tiefer, immer tiefer...', 35435),
(165243, 'deDE', 'Endlich... erkennt die Wahrheit der Schatten.', 'Endlich... erkennt die Wahrheit der Schatten.', 35435),
(165245, 'deDE', 'Mit jeder Entscheidung werdet Ihr mehr zu meinen Dienern.', 'Mit jeder Entscheidung werdet Ihr mehr zu meinen Dienern.', 35435),
(165239, 'deDE', 'Sammelt Eure Wut... macht Euren Hass zu einer Waffe.', 'Sammelt Eure Wut... macht Euren Hass zu einer Waffe.', 35435),
(165246, 'deDE', 'Dieser nutzlose Tand vergeht vor dem Blick eines Gottes.', 'Dieser nutzlose Tand vergeht vor dem Blick eines Gottes.', 35435),
(165244, 'deDE', 'Ja... sinkt tiefer... immer tiefer.', 'Ja... sinkt tiefer... immer tiefer.', 35435),
(165237, 'deDE', 'Ahh... Ihr denkt, Ihr wisst, was Macht ist?', 'Ahh... Ihr denkt, Ihr wisst, was Macht ist?', 35435);

DELETE FROM `gameobjects_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `gameobjects_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(341828, 'deDE', 'Teleporter: Stadt Mechagon', 35435),
(341363, 'deDE', 'Teleporter: Stadt Mechagon', 35435),
(338477, 'deDE', 'Teleporter: Stadt Mechagon', 35435);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(87487, 'deDE', 'Schild der klangvollen Resonanz', 35435);

DELETE FROM `azerite_essence_power_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `azerite_essence_power_locale` (`ID`, `locale`, `SourceAlliance_lang`, `SourceHorde_lang`, `VerifiedBuild`) VALUES
(114, 'deDE', 'Verstörende Visionen von N\'Zoth|n|cFFFFD200Erfolg:|r|n\"Durch die Tiefen der Visionen\"|n|cFFFFD200NSC:|r Furorion|n|cFFFFD200Ort:|r Herzkammer', '', 35435),
(132, 'deDE', 'Verstörende Visionen von N\'Zoth|n|cFFFFD200Erfolg:|r|n\"Durch die Tiefen der Visionen\"|n|cFFFFD200NSC:|r Furorion|n|cFFFFD200Ort:|r Herzkammer', '', 35435),
(140, 'deDE', 'Verstörende Visionen von N\'Zoth|n|cFFFFD200Erfolg:|r|n\"Durch die Tiefen der Visionen\"|n|cFFFFD200NSC:|r Furorion|n|cFFFFD200Ort:|r Herzkammer', '', 35435);

DELETE FROM `currency_types_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1803, 'deDE', 'Echos aus Ny\'alotha', 'Befreit von N\'Zoths Verderbnis kann MUTTER diese Substanz dazu verwenden, Azeritessenzen in der Herzkammer zu synthetisieren.', 35435);

DELETE FROM `spell_name_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(324906, 'deDE', 'Verderbnis - Zwielichtverwüstung 2', 35435),
(155343, 'deDE', 'Shamanstone: Buffeting Galefury', 35435),
(324845, 'deDE', 'Verderbnis - Widerhallende Leere 3', 35435),
(304086, 'deDE', 'Konflikt', 35435),
(154259, 'deDE', 'Shamanstone: Spirit of the Wolf', 35435),
(155313, 'deDE', 'Shamanstone: Touched by Fire', 35435),
(154275, 'deDE', 'Shamanstone: Spirit of the Wolf', 35435),
(319451, 'deDE', 'Teleport nach Stadt Mechagon', 35435),
(324887, 'deDE', 'Verderbnis - Entstellte Gliedmaße 2', 35435),
(292907, 'deDE', 'Verderbter Eissplitter', 35435),
(324900, 'deDE', 'Verderbnis - Geschärfter Verstand 2', 35435),
(296464, 'deDE', 'Verstärkungsrelais', 35435),
(299937, 'deDE', 'Verstärkungsrelais', 35435),
(324852, 'deDE', 'Verderbnis - Entschlossen 2', 35435),
(324892, 'deDE', 'Verderbnis - Strömende Lebenskraft 1', 35435),
(324901, 'deDE', 'Verderbnis - Geschärfter Verstand 3', 35435),
(332950, 'deDE', 'Feuerproc', 35435),
(155345, 'deDE', 'Shamanstone: Ogrish Fortitude', 35435),
(301578, 'deDE', 'REUSE ME', 35435),
(155315, 'deDE', 'Shamanstone: Touched by Fire', 35435),
(324894, 'deDE', 'Verderbnis - Strömende Lebenskraft 3', 35435),
(324888, 'deDE', 'Verderbnis - Entstellte Gliedmaße 3', 35435),
(324886, 'deDE', 'Verderbnis - Entstellte Gliedmaße 1', 35435),
(324890, 'deDE', 'Verderbnis - Unendliche Sterne 2', 35435),
(324881, 'deDE', 'Verderbnis - Augenblick der Klarheit', 35435),
(337816, 'deDE', 'Unausweichliche Konsequenzen', 35435),
(301683, 'deDE', 'REUSE ME', 35435),
(155347, 'deDE', 'Shamanstone: Spirit of the Wolf', 35435),
(324851, 'deDE', 'Verderbnis - Entschlossen 3', 35435),
(154274, 'deDE', 'Schamanenstein: Segen des Wolfs', 35435),
(110556, 'deDE', '[DNT] Force Cast Tried to Fly', 35435),
(324862, 'deDE', 'Verderbnis - Vielseitig 1', 35435),
(300932, 'deDE', 'REUSE ME [MTMM] (DNT)', 35435),
(155333, 'deDE', 'Shamanstone: Touched by Ice', 35435),
(291435, 'deDE', 'Verstandspfütze', 35435),
(324853, 'deDE', 'Verderbnis - Entschlossen 1', 35435),
(324884, 'deDE', 'Verderbnis - Leerenritual 2', 35435),
(324893, 'deDE', 'Verderbnis - Strömende Lebenskraft 2', 35435),
(324854, 'deDE', 'Verderbnis - Durchstoß 3', 35435),
(293777, 'deDE', 'Schattengeschoss', 35435),
(120679, 'deDE', 'Alphatier', 35435),
(274909, 'deDE', 'Aufziehender Nebel', 35435),
(300692, 'deDE', 'REUSE ME [MTMM] (DNT)', 35435),
(324885, 'deDE', 'Verderbnis - Leerenritual 3', 35435),
(155344, 'deDE', 'Shamanstone: Buffeting Galefury', 35435),
(335642, 'deDE', 'Machtschlag', 35435),
(335148, 'deDE', 'Zeichen des Wirbelnden Nethers', 35435),
(315958, 'deDE', 'Teleport nach Stadt Mechagon', 35435),
(327254, 'deDE', 'Verrottende Spore - Bedrohung', 35435),
(324839, 'deDE', 'Verderbnis - Tödlicher Schwung 3', 35435),
(264663, 'deDE', 'Durst des Raubtiers', 35435),
(302166, 'deDE', 'Verstärkungsrelais', 35435),
(293072, 'deDE', 'Verstandspfütze', 35435),
(311204, 'deDE', 'Bringt mich zur Stadt Mechagon', 35435),
(324870, 'deDE', 'Verderbnis - Schwerwiegend 3', 35435),
(155334, 'deDE', 'Shamanstone: Touched by Ice', 35435),
(324902, 'deDE', 'Verderbnis - Klaffende Wunde', 35435),
(275496, 'deDE', 'Unbezähmbare Gerechtigkeit', 35435),
(316661, 'deDE', 'Obsidianzerstörung', 35435),
(324864, 'deDE', 'Verderbnis - Vielseitig 2', 35435),
(321200, 'deDE', 'Quest starten', 35435),
(324904, 'deDE', 'Verderbnis - Unbeschreibliche Wahrheit 2', 35435),
(154253, 'deDE', 'Schamanenstein: Segen des Wolfs', 35435),
(331973, 'deDE', '', 35435),
(325946, 'deDE', 'Schleimwurf', 35435),
(324891, 'deDE', 'Verderbnis - Unendliche Sterne 3', 35435),
(321748, 'deDE', 'Klont mich!', 35435),
(324882, 'deDE', 'Verderbnis - Leerenritual 1', 35435),
(324860, 'deDE', 'Verderbnis - Meisterhaft 2', 35435),
(324850, 'deDE', 'Verderbnis - Widerhallende Leere 1', 35435),
(324899, 'deDE', 'Verderbnis - Geschärfter Verstand 1', 35435),
(294003, 'deDE', 'Lied des Suchers', 35435),
(313040, 'deDE', 'Unendliche Finsternis', 35435),
(324903, 'deDE', 'Verderbnis - Unbeschreibliche Wahrheit 1', 35435),
(324680, 'deDE', 'Verderbnis - Tödlicher Schwung 1', 35435),
(321201, 'deDE', 'Quest starten', 35435),
(155346, 'deDE', 'Shamanstone: Ogrish Fortitude', 35435),
(294479, 'deDE', 'Ausgraben', 35435),
(325947, 'deDE', 'Schleimwurf', 35435),
(328136, 'deDE', 'Beeindruckender Einfluss', 35435),
(324861, 'deDE', 'Verderbnis - Meisterhaft 1', 35435),
(300748, 'deDE', 'REUSE ME [MTMM] (DNT)', 35435),
(335151, 'deDE', 'Zeichen der Nebel', 35435),
(324879, 'deDE', 'Verderbnis - Schröpfer 2', 35435),
(256133, 'deDE', 'REUSE ME [SCS]', 35435),
(324880, 'deDE', 'Verderbnis - Schröpfer 3', 35435),
(335152, 'deDE', 'Zeichen des Eisens', 35435),
(306259, 'deDE', 'Tentakel', 35435),
(324858, 'deDE', 'Verderbnis - Meisterhaft 3', 35435),
(321428, 'deDE', 'Spuren der Ewigkeit', 35435),
(335150, 'deDE', 'Zeichen des Zerstörers', 35435),
(324907, 'deDE', 'Verderbnis - Zwielichtverwüstung 3', 35435),
(324889, 'deDE', 'Verderbnis - Unendliche Sterne 1', 35435),
(324898, 'deDE', 'Verderbnis - Rasender Puls 3', 35435),
(256134, 'deDE', 'REUSE ME [SCS]', 35435),
(324875, 'deDE', 'Verderbnis - Schlüpfrig 2', 35435),
(324866, 'deDE', 'Verderbnis - Schwerwiegend 1', 35435),
(300798, 'deDE', 'REUSE ME [MTMM] (DNT)', 35435),
(292579, 'deDE', 'Lagerfeuer in der Nähe', 35435),
(337612, 'deDE', 'Unausweichliche Konsequenzen', 35435),
(324877, 'deDE', 'Verderbnis - Schröpfer 1', 35435),
(324868, 'deDE', 'Verderbnis - Schwerwiegend 2', 35435),
(324837, 'deDE', 'Verderbnis - Tödlicher Schwung 2', 35435),
(324848, 'deDE', 'Verderbnis - Widerhallende Leere 2', 35435),
(115546, 'deDE', 'Provokation', 35435),
(324895, 'deDE', 'Verderbnis - Schlüpfrig 1', 35435),
(324857, 'deDE', 'Verderbnis - Durchstoß 1', 35435),
(324897, 'deDE', 'Verderbnis - Rasender Puls 2', 35435),
(321714, 'deDE', 'Teleport nach Silithus', 35435),
(324896, 'deDE', 'Verderbnis - Rasender Puls 1', 35435),
(324856, 'deDE', 'Verderbnis - Durchstoß 2', 35435),
(335149, 'deDE', 'Zeichen der Geißel', 35435),
(324865, 'deDE', 'Verderbnis - Vielseitig 3', 35435),
(324905, 'deDE', 'Verderbnis - Zwielichtverwüstung 1', 35435),
(324874, 'deDE', 'Verderbnis - Schlüpfrig 3', 35435);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(85118, 'deDE', '', 35435),
(85126, 'deDE', '', 35435),
(85114, 'deDE', '', 35435),
(85084, 'deDE', '', 35435),
(85132, 'deDE', '', 35435),
(85098, 'deDE', '', 35435),
(85134, 'deDE', '', 35435),
(85025, 'deDE', 'Süderstade vs. Tarrens Mühle', 35435),
(85128, 'deDE', '', 35435),
(84755, 'deDE', 'Quest für legendären Umhang abgeschlossen', 35435),
(85090, 'deDE', '', 35435),
(85130, 'deDE', '', 35435),
(84814, 'deDE', 'Spielercharakter der Nachtgeborenen kann Traditionsrüstung erhalten', 35435),
(85100, 'deDE', '', 35435),
(85136, 'deDE', '', 35435),
(85102, 'deDE', '', 35435),
(85138, 'deDE', '', 35435),
(84815, 'deDE', 'Spielercharakter der Mag\'har kann Traditionsrüstung erhalten', 35435),
(85108, 'deDE', '', 35435),
(85110, 'deDE', '', 35435),
(85116, 'deDE', '', 35435),
(84812, 'deDE', 'Spielercharakter der Mechagnome kann Traditionsrüstung erhalten', 35435),
(78565, 'deDE', 'Perfekt eingestelltes Differential', 35435),
(34935, 'deDE', 'Erhaltet den Schamanensteinsegen Geist des Wolfs', 35435),
(82623, 'deDE', 'Räumt in Stadt Mechagon auf', 35435),
(84810, 'deDE', 'Spielercharakter der Dunkeleisenzwerge kann Traditionsrüstung erhalten', 35435),
(84809, 'deDE', 'Spielercharakter der Leerenelfen kann Traditionsrüstung erhalten', 35435),
(85096, 'deDE', '', 35435),
(85092, 'deDE', '', 35435),
(84816, 'deDE', 'Spielercharakter der Zandalaritrolle kann Traditionsrüstung erhalten', 35435),
(85122, 'deDE', '', 35435),
(84808, 'deDE', 'Spielercharakter der Hochbergtauren kann Traditionsrüstung erhalten', 35435),
(85120, 'deDE', '', 35435),
(85112, 'deDE', '', 35435),
(84813, 'deDE', 'Spielercharakter der Vulpera kann Traditionsrüstung erhalten', 35435),
(85124, 'deDE', '', 35435),
(85088, 'deDE', '', 35435),
(85094, 'deDE', '', 35435),
(85086, 'deDE', '', 35435),
(85106, 'deDE', '', 35435),
(84817, 'deDE', 'Spielercharakter der Kul Tiraner kann Traditionsrüstung erhalten', 35435),
(85104, 'deDE', '', 35435),
(84811, 'deDE', 'Spielercharakter der Lichtgeschmiedeten Draenei kann Traditionsrüstung erhalten', 35435);

DELETE FROM `item_name_description_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `item_name_description_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(13566, 'deDE', '35 Verderbnis', 35435),
(13578, 'deDE', '16 Verderbnis', 35435),
(13569, 'deDE', '10 Verderbnis', 35435),
(13574, 'deDE', '28 Verderbnis', 35435),
(13572, 'deDE', '25 Verderbnis', 35435),
(13520, 'deDE', '30 Verderbnis', 35435),
(13579, 'deDE', '8 Verderbnis', 35435),
(13516, 'deDE', '5 Verderbnis', 35435),
(13568, 'deDE', '20 Verderbnis', 35435),
(13521, 'deDE', '5-30 Verderbnis', 35435),
(13576, 'deDE', '30 Verderbnis', 35435),
(13518, 'deDE', '15 Verderbnis', 35435),
(13519, 'deDE', '20 Verderbnis', 35435),
(13577, 'deDE', '12 Verderbnis', 35435),
(13575, 'deDE', '17 Verderbnis', 35435),
(13570, 'deDE', '75 Verderbnis', 35435),
(13565, 'deDE', '66 Verderbnis', 35435),
(13513, 'deDE', '25 Verderbnis', 35435),
(13580, 'deDE', '60 Verderbnis', 35435),
(13517, 'deDE', '10 Verderbnis', 35435),
(13571, 'deDE', '50 Verderbnis', 35435),
(13573, 'deDE', '45 Verderbnis', 35435),
(13567, 'deDE', '15 Verderbnis', 35435);

DELETE FROM `area_table_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12825, 'deDE', 'Stadt Mechagon', 35435),
(10290, 'deDE', 'Mechagon', 35435);

DELETE FROM `ui_map_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `ui_map_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1574, 'deDE', 'Stadt Mechagon', 35435),
(1573, 'deDE', 'Stadt Mechagon', 35435);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(177977, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Klaffende Wunde', 35435),
(177997, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schröpfer', 35435),
(178006, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Zwielichtverwüstung', 35435),
(177974, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Entschlossen', 35435),
(177976, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Augenblick der Klarheit', 35435),
(178015, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Leerenritual', 35435),
(178012, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Vielseitig', 35435),
(87487, 'deDE', '', '', '', '', 'Schild der klangvollen Resonanz', 35435),
(177983, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Unendliche Sterne', 35435),
(177980, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Geschärfter Verstand', 35435),
(178004, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Zwielichtverwüstung', 35435),
(177987, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Meisterhaft', 35435),
(177965, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Tödlicher Schwung', 35435),
(177989, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Rasender Puls', 35435),
(177998, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Durchstoß', 35435),
(178011, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Vielseitig', 35435),
(177993, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schwerwiegend', 35435),
(177978, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Geschärfter Verstand', 35435),
(178002, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Strömende Lebenskraft', 35435),
(177967, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Widerhallende Leere', 35435),
(177970, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schlüpfrig', 35435),
(177972, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schlüpfrig', 35435),
(177992, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schwerwiegend', 35435),
(177985, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Unendliche Sterne', 35435),
(177982, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Unbeschreibliche Wahrheit', 35435),
(177991, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Rasender Puls', 35435),
(177971, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schlüpfrig', 35435),
(168043, 'deDE', 'Wird von den Amathet begehrt, die sich als Hüter der titanischen Werke sehen.', '', '', '', 'Titanenartefakt', 35435),
(177964, 'deDE', '', '', '', '', 'Waffe - Kraftmultiplikator', 35435),
(177986, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Meisterhaft', 35435),
(178013, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Leerenritual', 35435),
(177994, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schwerwiegend', 35435),
(178009, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Entstellte Gliedmaße', 35435),
(173937, 'deDE', 'Das herrenlose Auge erwidert Euren Blick, egal wohin Ihr schaut.', '', '', '', 'Abgetrennter Oculus', 35435),
(177973, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Entschlossen', 35435),
(178007, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Entstellte Gliedmaße', 35435),
(177981, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Unbeschreibliche Wahrheit', 35435),
(178003, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Strömende Lebenskraft', 35435),
(177979, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Geschärfter Verstand', 35435),
(177966, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Tödlicher Schwung', 35435),
(177999, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Durchstoß', 35435),
(178010, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Vielseitig', 35435),
(177969, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Widerhallende Leere', 35435),
(178000, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Durchstoß', 35435),
(177975, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Entschlossen', 35435),
(178001, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Strömende Lebenskraft', 35435),
(178008, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Entstellte Gliedmaße', 35435),
(177995, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schröpfer', 35435),
(177968, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Widerhallende Leere', 35435),
(177955, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Tödlicher Schwung', 35435),
(177988, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Meisterhaft', 35435),
(177996, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Schröpfer', 35435),
(177984, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Unendliche Sterne', 35435),
(178014, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Leerenritual', 35435),
(177990, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Rasender Puls', 35435),
(178005, 'deDE', '', '', '', '', 'Eingedämmter Kontaminant: Zwielichtverwüstung', 35435),
(141057, 'deDE', 'Lehrt Euch, wie man eine Glyphe \'Blendgranate\' herstellt.', '', '', '', 'Technik: Glyphe \'Blendgranate\'', 35435),
(139412, 'deDE', '', '', '', '', 'Junge mutierte Kriegsschildkröten', 35435),
(139345, 'deDE', '', '', '', '', 'Rattenhände', 35435),
(139411, 'deDE', '', '', '', '', 'Bankett der Schattenseite', 35435),
(137826, 'deDE', 'Lehrt Euch, wie man einen magischen Schattenrubinanhänger herstellt.', '', '', '', 'Vorlage: Magischer Schattenrubinanhänger', 35435),
(138016, 'deDE', 'Lehrt Euch, wie man eine Kleidertruhe: Einwohner von Dalaran herstellt.', '', '', '', 'Kleidertruhenmuster: Einwohner von Dalaran', 35435),
(137932, 'deDE', 'Lehrt Euch, wie man einen brennenden Reifen herstellt.', '', '', '', 'Muster: Brennender Reifen', 35435),
(137954, 'deDE', 'Lehrt Euch, wie man einen seidengewebten Hüftgurt herstellt.', '', '', '', 'Muster: Seidengewebter Hüftgurt', 35435),
(137901, 'deDE', 'Lehrt Euch, wie man einen Kampfschwurgurt herstellt.', '', '', '', 'Muster: Kampfschwurgurt', 35435),
(137881, 'deDE', 'Lehrt Euch, wie man einen Kriegsbalggürtel herstellt.', '', '', '', 'Muster: Kriegsbalggürtel', 35435),
(139344, 'deDE', '', '', '', '', 'Manabanane', 35435),
(139347, 'deDE', '', '', '', '', 'Schattengelee', 35435),
(137706, 'deDE', 'Lehrt Euch, wie man eine Schwarzpulverladung herstellt.', '', '', '', 'Bauplan: Schwarzpulverladung', 35435),
(137962, 'deDE', 'Lehrt Euch, wie man einen seidengewebten Hüftgurt herstellt.', '', '', '', 'Muster: Seidengewebter Hüftgurt', 35435),
(137829, 'deDE', 'Lehrt Euch, wie man einen verstohlenen Schattenrubinanhänger herstellt.', '', '', '', 'Vorlage: Verstohlener Schattenrubinanhänger', 35435),
(137913, 'deDE', 'Lehrt Euch, wie man einen Kampfschwurgurt herstellt.', '', '', '', 'Muster: Kampfschwurgurt', 35435),
(137917, 'deDE', 'Lehrt Euch, wie man einen Gravurschuppengurt herstellt.', '', '', '', 'Muster: Gravurschuppengurt', 35435),
(139431, 'deDE', '', '', '', '', 'Kiste mit Rattenhengstharnischen', 35435),
(141065, 'deDE', 'Lehrt Euch, wie man eine Glyphe \'Terrorwache\' herstellt.', '', '', '', 'Technik: Glyphe \'Terrorwache\'', 35435),
(137885, 'deDE', 'Lehrt Euch, wie man einen Schreckensledergürtel herstellt.', '', '', '', 'Muster: Schreckensledergürtel', 35435),
(137869, 'deDE', 'Lehrt Euch, wie man einen Kriegsbalggürtel herstellt.', '', '', '', 'Muster: Kriegsbalggürtel', 35435),
(127918, 'deDE', 'Lehrt Euch die effizientere Herstellung eines uralten Manatranks.', '', '', '', 'Rezept: Uralter Manatrank', 35435),
(139422, 'deDE', '', '', '', '', 'Dämonischer Köder', 35435),
(141058, 'deDE', 'Lehrt Euch, wie man eine Glyphe \'Kleintierverhexung\' herstellt.', '', '', '', 'Technik: Glyphe \'Kleintierverhexung\'', 35435),
(141038, 'deDE', 'Lehrt Euch, wie man eine Glyphe \'Schattenfeinde\' herstellt.', '', '', '', 'Technik: Glyphe \'Schattenfeinde\'', 35435),
(139346, 'deDE', '', '', '', '', 'Thunis patentierte Trinkflüssigkeit', 35435),
(137934, 'deDE', 'Lehrt Euch, wie man eine lederne Haustierleine herstellt.', '', '', '', 'Muster: Lederne Haustierleine', 35435),
(137831, 'deDE', 'Lehrt Euch, wie man einen rachsüchtigen Pandemonithalsreif herstellt.', '', '', '', 'Vorlage: Rachsüchtiger Pandemonithalsreif', 35435),
(139425, 'deDE', '', '', '', '', 'Wichtelbindender Vertrag', 35435),
(141850, 'deDE', 'Lehrt Euch, wie man ein Urhornzaumzeug herstellt.', '', '', '', 'Muster: Urhornzaumzeug', 35435),
(137966, 'deDE', 'Lehrt Euch, wie man einen machtgetränkten seidengewebten Hüftgurt herstellt.', '', '', '', 'Muster: Machtgetränkter seidengewebter Hüftgurt', 35435);

DELETE FROM `mount_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(468, 'deDE', 'Kaiserqilen', '|cFFFFD200Promotion:|r Mists of Pandaria Collector\'s Edition', 'Qilen sind die Lieblingshaustiere der uralten Moguprinzen und können treue und furchtlose Begleiter und Reittiere sein.', 35435),
(1282, 'deDE', 'N\'Zoths schwarze Schlange', '|cFFFFD200Erfolg:|r Durch die Tiefen der Visionen', 'N\'Zoths schwarze Schlangen sind die Vorboten der Umsetzung seiner ultimativen Vision in die Realität. Nur Diener oder Gegner, die dieses Gebiet betreten können, haben die Möglichkeit, sie zu unterwerfen.', 35435);

DELETE FROM `player_condition_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(79509, 'deDE', 'Erlernt Rang 3 einer beliebigen Essenz des Rostbolzenwiderstands auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79518, 'deDE', 'Erlernt Rang 3 von Konflikt und Zwietracht auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79511, 'deDE', 'Erlernt Rang 3 der Kondensierten Lebenskraft, der Vitalitätsverbindung, oder von Azeroths unsterblichem Geschenk auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79508, 'deDE', 'Erlernt Rang 3 vom Blut des Feindes, des Kunstwerks der Zeit, oder der Sphäre der Unterdrückung auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79523, 'deDE', 'Erlernt Rang 3 der Formlosen Leere auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(74078, 'deDE', 'Benötigt Ashjra\'kamas, Tuch der Entschlossenheit.', 35435),
(79512, 'deDE', 'Erlernt Rang 3 der Vision der Perfektion auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79505, 'deDE', 'Erlernt Rang 3 der Raumwelle auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79499, 'deDE', 'Erlernt Rang 3 der Essenz der Fokussierungsiris, der Invokation der Lebensbinderin, oder der Anima von Leben und Tod auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79522, 'deDE', 'Erlernt Rang 3 einer Essenz aus Verstörenden Visionen auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79514, 'deDE', 'Erlernt Rang 3 einer Essenz von den Rajani oder dem Abkommen von Uldum auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(75180, 'deDE', 'Erfordert den Erfolg \"Durch die Tiefen der Visionen\" und Freischaltung der Essenz von Rang 3. (Kauf nicht möglich, wenn bereits bekannt)', 35435),
(79516, 'deDE', 'Erlernt Rang 3 der Erinnerung an den Klartraum auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79519, 'deDE', 'Erlernt Rang 3 einer Essenz von den Rajani oder dem Abkommen von Uldum auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79504, 'deDE', 'Erlernt Rang 3 der Kondensierten Lebenskraft, der Vitalitätsverbindung, oder von Azeroths unsterblichem Geschenk auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(75170, 'deDE', 'Erfordert den Erfolg \"Durch die Tiefen der Visionen\" und Freischaltung der Essenz von Rang 3. (Kauf nicht möglich, wenn bereits bekannt)', 35435),
(79513, 'deDE', 'Erlernt Rang 3 vom Blut des Feindes, des Kunstwerks der Zeit, oder der Sphäre der Unterdrückung auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79502, 'deDE', 'Erlernt Rang 3 des Schmelztiegels der Flammen auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79501, 'deDE', 'Erlernt Rang 3 der Essenz der Fokussierungsiris, der Invokation der Lebensbinderin, oder der Anima von Leben und Tod auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79486, 'deDE', 'Erlernt Rang 3 der Kondensierten Lebenskraft, der Vitalitätsverbindung, oder von Azeroths unsterblichem Geschenk auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79515, 'deDE', 'Erlernt Rang 3 einer beliebigen Rufessenz aus Nazjatar auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79510, 'deDE', 'Erlernt Rang 3 der Essenz der Fokussierungsiris, der Invokation der Lebensbinderin, oder der Anima von Leben und Tod auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79497, 'deDE', 'Erlernt Rang 3 vom Blut des Feindes, des Kunstwerks der Zeit, oder der Sphäre der Unterdrückung auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79521, 'deDE', 'Erlernt Rang 3 einer Essenz von den Rajani oder dem Abkommen von Uldum auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(75191, 'deDE', 'Erfordert den Erfolg \"Durch die Tiefen der Visionen\" und Freischaltung der Essenz von Rang 3. (Kauf nicht möglich, wenn bereits bekannt)', 35435),
(79506, 'deDE', 'Erlernt Rang 3 einer Essenz aus Verstörenden Visionen auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79500, 'deDE', 'Erlernt Rang 3 einer beliebigen Essenz des Rostbolzenwiderstands auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79503, 'deDE', 'Erlernt Rang 3 einer beliebigen Essenz des Rostbolzenwiderstands auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79498, 'deDE', 'Erlernt Rang 3 der Resonanz der Weltader auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79507, 'deDE', 'Erlernt Rang 3 einer beliebigen Rufessenz aus Nazjatar auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79517, 'deDE', 'Erlernt Rang 3 einer beliebigen Rufessenz aus Nazjatar auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435),
(79520, 'deDE', 'Erlernt Rang 3 einer Essenz aus Verstörenden Visionen auf einem anderen Charakter, um diese Essenz freizuschalten.', 35435);

DELETE FROM `map_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(2268, 'deDE', 'Stadt Mechagon', '', '', '', '', 35435);

DELETE FROM `wmo_area_table_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `wmo_area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(103067, 'deDE', 'Stadt Mechagon', 35435);

DELETE FROM `achievement_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14260, 'deDE', '', '', '', 35435),
(14251, 'deDE', '', '', '', 35435),
(14256, 'deDE', '', '', '', 35435),
(14263, 'deDE', '', '', '', 35435),
(14250, 'deDE', '', '', '', 35435),
(14241, 'deDE', '', '', '', 35435),
(14246, 'deDE', '', '', '', 35435),
(14244, 'deDE', '', '', '', 35435),
(14264, 'deDE', '', '', '', 35435),
(6980, 'deDE', 'Haltet in einer einzigen Schlacht um den Tempel von Katmogu vier Kugeln der Macht und tötet vier Gegner, die eine Kugel der Macht halten.', 'Held des Tempels von Katmogu', '', 35435),
(14258, 'deDE', '', '', '', 35435),
(14249, 'deDE', '', '', '', 35435),
(14254, 'deDE', '', '', '', 35435),
(14252, 'deDE', '', '', '', 35435),
(14212, 'deDE', '', '<Hidden> 8.3 Main Line - Account Has Obtained Legendary Cloak (DNT)', '', 35435),
(14245, 'deDE', '', '', '', 35435),
(14242, 'deDE', '', '', '', 35435),
(14257, 'deDE', '', '', '', 35435),
(14255, 'deDE', '', '', '', 35435),
(14248, 'deDE', '', '', '', 35435),
(14259, 'deDE', '', '', '', 35435),
(14261, 'deDE', '', '', '', 35435),
(14265, 'deDE', '', '', '', 35435),
(14247, 'deDE', '', '', '', 35435),
(14240, 'deDE', '', '', '', 35435),
(14238, 'deDE', '', 'Azerite Essence - Rank 3 on any character - Azeroth\'s Undying Gift <DND>', '', 35435),
(14253, 'deDE', '', '', '', 35435),
(14262, 'deDE', '', '', '', 35435),
(14239, 'deDE', '', '', '', 35435),
(14243, 'deDE', '', '', '', 35435);

DELETE FROM `mail_template_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `mail_template_locale` (`ID`, `locale`, `Body_lang`, `VerifiedBuild`) VALUES
(550, 'deDE', 'Um diesen Account mit Gold reaktivieren zu können, haben wir eine gewisse Goldmenge aus der ungeöffneten Post verwendet. Daher kann der verbleibende Goldbetrag in der Post geringer ausfallen als erwartet. Es besteht aber kein Grund zur Sorge, da kein Gold verloren gegangen ist.\n\nVielen Dank und willkommen zurück in Azeroth!\n - Das Entwicklerteam von WoW', 35435);

DELETE FROM `dungeon_encounter_locale` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `dungeon_encounter_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(786, 'deDE', 'Hohepriesterin Mar\'li', 35435);


DELETE FROM `hotfix_blob` WHERE `locale` = 'deDE' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(3386943305, 195997, 'deDE', 0x0778781000B20200000400081000000000000000000000000000000001000000000000000097A80200, 35435), -- CreatureDifficulty
(600565378, 267260, 'deDE', 0xE56501000000803F6666A63F0093A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267271, 'deDE', 0xB46501000000803F0000803F009BA80200, 35435), -- CreatureXDisplayInfo
(3386291891, 174231, 'deDE', 0x4D79726D69646F6E6520646572205A616E6A276972000000000007000000E56501000000000000000000000000000000803F0000803F0000803F0000803F879402000000000000000000, 35435), -- Creature
(600565378, 267266, 'deDE', 0xE56501000000803F6666A63F0097A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267274, 'deDE', 0xEA6501000000803F9A99993F009EA80200, 35435), -- CreatureXDisplayInfo
(813076512, 22908, 'deDE', 0x760000002B2F0300, 35435), -- SpellLabel
(813076512, 22909, 'deDE', 0x240100002B2F0300, 35435), -- SpellLabel
(3776013982, 324874, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646465363686CC3BC70667269677C720D0A24407370656C6C646573633331353630390000, 35435), -- Spell
(3776013982, 324905, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C6346464646464646465A7769656C6963687476657277C3BC7374756E677C720D0A24407370656C6C646573633331383237360000, 35435), -- Spell
(3776013982, 324865, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C6346464646464646465669656C7365697469677C720D0A24407370656C6C646573633331353535330000, 35435), -- Spell
(3776013982, 335149, 'deDE', 0x00457268C3B668742064656E205275667A75776163687320626569204672616B74696F6E656E20766F6E205772617468206F6620746865204C696368204B696E67206475726368204B616D706620756E642051756573747320756D20247331252E007C634646303041413939426F6E757365726569676E69733A205A65697477616E646572756E6720285772617468206F6620746865204C696368204B696E67297C720D0A0D0A5275667A75776163687320626569204672616B74696F6E656E20766F6E205772617468206F6620746865204C696368204B696E67206475726368204B616D706620756E642051756573747320756D202473312520657268C3B668742E00, 35435), -- Spell
(3776013982, 324856, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646447572636873746FC39F7C720D0A24407370656C6C646573633331353238310000, 35435), -- Spell
(3776013982, 324896, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646526173656E6465722050756C737C720D0A24407370656C6C646573633331383236360000, 35435), -- Spell
(3776013982, 321714, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324897, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646526173656E6465722050756C737C720D0A24407370656C6C646573633331383439320000, 35435), -- Spell
(2230237587, 1188, 'deDE', 0x5374616474204D65636861676F6E0096010000250600000000000000, 35435), -- UiMapGroupMember
(3776013982, 324857, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646447572636873746FC39F7C720D0A24407370656C6C646573633331353237370000, 35435), -- Spell
(3776013982, 324895, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646465363686CC3BC70667269677C720D0A24407370656C6C646573633331353630370000, 35435), -- Spell
(3776013982, 115546, 'deDE', 0x0056657273706F7474657420646173205A69656C2C20736F646173732065732073696368206D697420756D20243131363138396D332520657268C3B668746572204265776567756E6773676573636877696E6469676B656974206175662045756368207A756265776567742E243F733131353331355B0D0A0D0A44696573652046C3A46869676B656974206B616E6E2061756620457572652053746174756520646573205363687761727A656E204F636873656E20616E676577616E64742077657264656E2C20776F647572636820616C6C65204765676E657220696E6E657268616C6220766F6E20243131383633354131204D657465726E20766F6E2064657220537461747565206D69742064656D73656C62656E20456666656B742062656C6567742077657264656E2E5D5B5D0000, 35435), -- Spell
(3776013982, 324848, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646576964657268616C6C656E6465204C656572657C720D0A24407370656C6C646573633331383438350000, 35435), -- Spell
(3776013982, 324837, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C63464646464646464654C3B6646C69636865722053636877756E677C720D0A24407370656C6C646573633331383439330000, 35435), -- Spell
(3776013982, 324868, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464653636877657277696567656E647C720D0A24407370656C6C646573633331353535370000, 35435), -- Spell
(3776013982, 324877, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653636872C3B6706665727C720D0A24407370656C6C646573633331353539300000, 35435), -- Spell
(3205218938, 41793, 'deDE', 0x4755494C445F46494E4445525F504F5354494E475F455850495245440047696C64656E62726F77736572616E7A6569676520616267656C617566656E210001, 35435), -- GlobalStrings
(3776013982, 337612, 'deDE', 0x004E275A6F74682065726865627420416E73707275636820617566204575726520457373656E7A20756E642066C3BC6774204575636820696D204B616D706620616C6C65202474312053656B2E205363686164656E20696E2048C3B6686520766F6E2024733125204575726572206D6178696D616C656E20476573756E6468656974207A752E2044617320456E6465206E6168742E0045726C656964657420696D204B616D706620616C6C65202474312053656B2E205363686164656E20696E2048C3B6686520766F6E202477312520646572206D6178696D616C656E20476573756E64686569742E00, 35435), -- Spell
(3776013982, 292579, 'deDE', 0x0045696E204162656E746575726572206B616E6E20646173204C61676572666575657220696E20646572204EC3A4686520656E747AC3BC6E64656E2E0045696E204162656E746575726572206B616E6E20646173204C61676572666575657220696E20646572204EC3A4686520656E747AC3BC6E64656E2E00, 35435), -- Spell
(2230237587, 1162, 'deDE', 0x5374616474204D65636861676F6E008F010000D90500000400000000, 35435), -- UiMapGroupMember
(2035710060, 7072, 'deDE', 0x536368617474656E686166746572204C6F61676569737400486F68657072696573746572696E204D6172276C69207365747A742064696573652046C3A46869676B6569742065696E2C2077656E6E2073696520766F6D20476569737420766F6E2047617261276A616C20626573657373656E206973742E0D0A0D0A53696520626573636877C3B672742065696E656E20736368617474656E68616674656E204C6F61676569737420616E20696872657220506F736974696F6E2E2044657220476569737420666978696572742073696368206175662065696E656E207A7566C3A46C6C6967656E20537069656C657263686172616B7465722C20766572666F6C67742069686E202431333733393564206C616E6720756E642074C3B67465742064656E20537069656C657263686172616B74657220736F666F72742C2077656E6E2065722069686D206EC3A468657220616C7320243133373339304131204D65746572206B6F6D6D742E0D0A0D0A57656E6E20646572204765697374206E616368202431333733393564206E6F636820616D204C6562656E206973742C20737072696E677420657220736F666F7274207A75207365696E656D205A69656C20756E642074C3B67465742065732E0030031C8A1B0000A11B02000000000000000000000000DFA209000200320013, 35435), -- JournalEncounterSection
(3776013982, 300798, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324866, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464653636877657277696567656E647C720D0A24407370656C6C646573633331353535340000, 35435), -- Spell
(3776013982, 324875, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646465363686CC3BC70667269677C720D0A24407370656C6C646573633331353630380000, 35435), -- Spell
(3776013982, 256134, 'deDE', 0x0056657272696E676572742065726865626C69636820646965206572666F726465726C696368656E204D6174657269616C69656E207A7572204865727374656C6C756E672065696E6573204D6F746F7273206D697420547572626F6C616465722E0000, 35435), -- Spell
(3776013982, 324898, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646526173656E6465722050756C737C720D0A24407370656C6C646573633331383439360000, 35435), -- Spell
(3776013982, 324889, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C634646464646464646556E656E646C6963686520537465726E657C720D0A24407370656C6C646573633331383237340000, 35435), -- Spell
(3776013982, 324907, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C6346464646464646465A7769656C6963687476657277C3BC7374756E677C720D0A24407370656C6C646573633331383437380000, 35435), -- Spell
(3776013982, 335150, 'deDE', 0x00457268C3B668742064656E205275667A75776163687320626569204672616B74696F6E656E20766F6E2043617461636C79736D206475726368204B616D706620756E642051756573747320756D20247331252E007C634646303041413939426F6E757365726569676E69733A205A65697477616E646572756E6720284361746163796C736D297C720D0A0D0A5275667A75776163687320626569204672616B74696F6E656E20766F6E2043617461636C79736D206475726368204B616D706620756E642051756573747320756D202473312520657268C3B668742E00, 35435), -- Spell
(3776013982, 321428, 'deDE', 0x0046C3BC677420616C6C656E20537069656C657263686172616B746572656E20616C6C65202474312053656B2E2024733120536368617474656E7363686164656E207A752E005665727572736163687420616C6C65202474312053656B2E2024733120536368617474656E7363686164656E2E00, 35435), -- Spell
(2035710060, 7071, 'deDE', 0x5A6F726E20646572204C6F6100486F68657072696573746572696E204D6172276C69207365747A742064696573652046C3A46869676B6569742065696E2C2077656E6E2073696520766F6D20476569737420766F6E2047617261276A616C20626573657373656E206973742E0D0A0D0A486F68657072696573746572696E204D6172276C692061747461636B696572742065696E656E20537069656C657263686172616B746572206D69742064656D20275A6F726E20646572204C6F612720756E6420766572757273616368742024313337333437733120536368617474656E7363686164656E2E0030031B8A1B0000A01B02000000000000000000000000BC62090000004000FF, 35435), -- JournalEncounterSection
(3776013982, 324858, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D656973746572686166747C720D0A24407370656C6C646573633331353533310000, 35435), -- Spell
(3776013982, 306259, 'deDE', 0x000000, 35435), -- Spell
(2901650891, 1582, 'deDE', 0x486F68657072696573746572696E204D6172276C6900002E060000300372BA0000000000000309000000, 35435), -- JournalEncounterCreature
(3776013982, 335152, 'deDE', 0x00457268C3B668742064656E205275667A75776163687320626569204672616B74696F6E656E20766F6E205761726C6F726473206F6620447261656E6F72206475726368204B616D706620756E642051756573747320756D20247331252E007C634646303041413939426F6E757365726569676E69733A205A65697477616E646572756E6720285761726C6F726473206F6620447261656E6F72297C720D0A0D0A5275667A75776163687320626569204672616B74696F6E656E20766F6E205761726C6F726473206F6620447261656E6F72206475726368204B616D706620756E642051756573747320756D202473312520657268C3B668742E00, 35435), -- Spell
(3776013982, 324880, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653636872C3B6706665727C720D0A24407370656C6C646573633331353539320000, 35435), -- Spell
(3776013982, 256133, 'deDE', 0x0056657272696E6765727420646965206572666F726465726C696368656E204D6174657269616C69656E207A7572204865727374656C6C756E672065696E6573204D6F746F7273206D697420547572626F6C616465722E0000, 35435), -- Spell
(3776013982, 324879, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653636872C3B6706665727C720D0A24407370656C6C646573633331353539310000, 35435), -- Spell
(3776013982, 335151, 'deDE', 0x00457268C3B668742064656E205275667A75776163687320626569204672616B74696F6E656E20766F6E204D69737473206F662050616E6461726961206475726368204B616D706620756E642051756573747320756D20247331252E007C634646303041413939426F6E757365726569676E69733A205A65697477616E646572756E6720284D69737473206F662050616E6461726961297C720D0A0D0A5275667A75776163687320626569204672616B74696F6E656E20766F6E204D69737473206F662050616E6461726961206475726368204B616D706620756E642051756573747320756D202473312520657268C3B668742E00, 35435), -- Spell
(3776013982, 300748, 'deDE', 0x000000, 35435), -- Spell
(20077728, 396607, 'deDE', 0x000001000000474302000001006FD6, 35435), -- QuestObjective
(3205218938, 42497, 'deDE', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F5449544C450049687220777572646574207A756D20416E66C3BC68726520626566C3B67264657274207C54496E746572666163655C5C47726F75704672616D655C5C55492D47726F75702D4C656164657249636F6E3A303A303A303A2D317C74207C6E7C6E7C6366666666643230304DC3B66368746574204968722064696520477275707065206E657520616E6D656C64656E3F3A7C727C6E25737C6E0001, 35435), -- GlobalStrings
(3776013982, 324861, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D656973746572686166747C720D0A24407370656C6C646573633331353532390000, 35435), -- Spell
(3776013982, 328136, 'deDE', 0x00457268C3B668742064656E20657268616C74656E656E20527566206175662064656E205A65727363686C6167656E656E20496E73656C6E2C2041726775732C20696E204B756C2054697261732C205A616E64616C617220756E64204E617A6A6174617220756D20247331252E0052756662656C6F686E756E67656E206175662064656E205A65727363686C6167656E656E20496E73656C6E2C2041726775732C20696E204B756C2054697261732C205A616E64616C617220756E64204E617A6A6174617220756D202473312520657268C3B668742E00, 35435), -- Spell
(3776013982, 325947, 'deDE', 0x0024407370656C6C646573633239363832300000, 35435), -- Spell
(3776013982, 294479, 'deDE', 0x00005375636874206E616368207572616C74656E204172746566616B74656E2E00, 35435), -- Spell
(3776013982, 155346, 'deDE', 0x0056657277616E64656C74204575636820766F6E205A656974207A75205A65697420696E2065696E656E206DC3A46368746967656E2046726F737466657565726F67657220756E6420676577C3A468727420756D202431353533333773322520657268C3B66874656E2057696465727374616E6420676567656E206E6567617469766520456666656B74652E0056657277616E64656C74204575636820766F6E205A656974207A75205A65697420696E2065696E656E206DC3A46368746967656E2046726F737466657565726F67657220756E6420676577C3A468727420756D202431353533333773322520657268C3B66874656E2057696465727374616E6420676567656E206E6567617469766520456666656B74652E00, 35435), -- Spell
(3776013982, 321201, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324680, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C63464646464646464654C3B6646C69636865722053636877756E677C720D0A24407370656C6C646573633331383236380000, 35435), -- Spell
(3776013982, 324903, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C634646464646464646556E6265736368726569626C696368652057616872686569747C720D0A24407370656C6C646573633331383330330000, 35435), -- Spell
(3205218938, 42500, 'deDE', 0x47524F55505F46494E4445525F4445534C4953545F5741524E494E475F454449545F4C495354494E470045696E74726167206265617262656974656E0001, 35435), -- GlobalStrings
(3776013982, 313040, 'deDE', 0x00526569C39F742065696E204C6F636820696E732047657765626520646572205265616C6974C3A4742C20656E747A6965687420616C6C656E204765676E65726E2024333133303430733220676569737469676520476573756E646865697420756E642066C3BC67742069686E656E2024333133303430733120536368617474656E7363686164656E207A752E0D0A0D0A446965736573204C6F6368206572736368616666742066C3BC72202433313736333444202724407370656C6C6E616D65333137363237272E0000, 35435), -- Spell
(3205218938, 42645, 'deDE', 0x424E45545F4552524F525F343030313100284E7572204368696E61292053656B756E64C3A4726520656C7465726C696368652046726569676162650002, 35435), -- GlobalStrings
(3776013982, 294003, 'deDE', 0x00005761686E73696E6E2067656CC3A475746572742E0D0A476569737469676520476573756E6468656974207769726420726567656E6572696572742E00, 35435), -- Spell
(3776013982, 324899, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464765736368C3A47266746572205665727374616E647C720D0A24407370656C6C646573633331383236390000, 35435), -- Spell
(3776013982, 324850, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646576964657268616C6C656E6465204C656572657C720D0A24407370656C6C646573633331383238300000, 35435), -- Spell
(3776013982, 324860, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D656973746572686166747C720D0A24407370656C6C646573633331353533300000, 35435), -- Spell
(3776013982, 324882, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C6346464646464646464C656572656E72697475616C7C720D0A24407370656C6C646573633331383238360000, 35435), -- Spell
(3776013982, 321748, 'deDE', 0x004272696E67742064617320616B7475656C6C65205A69656C2064617A752C2064656E205A61756265726E64656E207A75206B6C6F6E656E2E0000, 35435), -- Spell
(3776013982, 324891, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C634646464646464646556E656E646C6963686520537465726E657C720D0A24407370656C6C646573633331383438380000, 35435), -- Spell
(3776013982, 325946, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 331973, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 154253, 'deDE', 0x0045696E2046726F7374776F6C6620756E7465727374C3BC747A742067656C6567656E746C696368204368616D70696F6E73206465732046726F7374776F6C666B6C616E732E0045696E2046726F7374776F6C6620756E7465727374C3BC747A742067656C6567656E746C696368204368616D70696F6E73206465732046726F7374776F6C666B6C616E732E00, 35435), -- Spell
(3776013982, 324904, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C634646464646464646556E6265736368726569626C696368652057616872686569747C720D0A24407370656C6C646573633331383438340000, 35435), -- Spell
(3776013982, 321200, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324864, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C6346464646464646465669656C7365697469677C720D0A24407370656C6C646573633331353535320000, 35435), -- Spell
(3776013982, 316661, 'deDE', 0x0024407370656C6C646573633331363635310000, 35435), -- Spell
(3776013982, 275496, 'deDE', 0x0057656E6E20457572652070726F7A656E7475616C6520476573756E64686569742064696520646573205A69656C7320C3BC6265727374656967742C20766572757273616368742027526963687475727465696C27207A7573C3A4747A6C696368656E205363686164656E2028626973207A75206D6178696D616C20247331205363686164656E292E0000, 35435), -- Spell
(3776013982, 324902, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F49726F6E4D616964656E735F436F72727570746564426C6F6F642E626C703A32347C74207C6346464646464646464B6C616666656E64652057756E64657C720D0A24407370656C6C646573633331383237320000, 35435), -- Spell
(3776013982, 155334, 'deDE', 0x00496872207365696420696D2045696E6B6C616E67206D69742064656D204569732064696573657220476567656E642E2045757265204765676E65722077657264656E206D616E63686D616C206475726368204575726520626C6FC39F6520416E776573656E686569742065696E676566726F72656E2E0045757265204765676E65722077657264656E206D616E63686D616C206475726368204575726520626C6FC39F6520416E776573656E686569742065696E676566726F72656E2E00, 35435), -- Spell
(3776013982, 324870, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464653636877657277696567656E647C720D0A24407370656C6C646573633331353535380000, 35435), -- Spell
(3776013982, 311204, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 293072, 'deDE', 0x004572736368616666742065696E652064756E6B6C65205066C3BC747A652C20646965204765676E65726E2C206469652064656E204265726569636820626574726574656E2C20246F3220676569737469676520476573756E646865697420696D205665726C61756620766F6E20246420656E747A696568742E005665726C6965727420616C6C65202474322053656B2E2024733220676569737469676520476573756E64686569742E00, 35435), -- Spell
(3776013982, 302166, 'deDE', 0x00446572204AC3A46765726B696C6C6572207761727074205665727374C3A4726B756E672061757320646572205374616474204D65636861676F6E206865726265692E0000, 35435), -- Spell
(3776013982, 264663, 'deDE', 0x506173736976652057696C64686569747366C3A46869676B6569740045756572204C6562656E737261756220756E6420646572204575726573204265676C656974657273207769726420756D202473312520657268C3B668742E004C6562656E737261756220756D202477322520657268C3B668742E00, 35435), -- Spell
(3776013982, 324839, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C63464646464646464654C3B6646C69636865722053636877756E677C720D0A24407370656C6C646573633331383439370000, 35435), -- Spell
(3776013982, 327254, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 315958, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 335148, 'deDE', 0x00457268C3B668742064656E205275667A75776163687320626569204672616B74696F6E656E20766F6E20546865204275726E696E672043727573616465206475726368204B616D706620756E642051756573747320756D20247331252E007C634646303041413939426F6E757365726569676E69733A205A65697477616E646572756E6720284275726E696E672043727573616465297C720D0A0D0A5275667A75776163687320626569204672616B74696F6E656E20766F6E20546865204275726E696E672043727573616465206475726368204B616D706620756E642051756573747320756D202473312520657268C3B668742E00, 35435), -- Spell
(3776013982, 335642, 'deDE', 0x004772656966742064656E204765676E657220616E20756E642066C3BC67742069686D20247331252057616666656E7363686164656E20616C7320536368617474656E7363686164656E207A752E204175C39F657264656D207769726420646572207665727572736163687465205363686164656E202464206C616E6720756D202473322520657268C3B668742E005363686164656E20756D202473322520657268C3B668742E00, 35435), -- Spell
(3776013982, 155344, 'deDE', 0x004968722073656964206D69742064656E2057696E64656E206465732046726F737466657565726772617465732067657365676E65742E2049687220686162742065696E65204368616E63652C20275374C3BC726D6973636865205A6F726E62C3B6656E27207A7520657268616C74656E2C20776F64757263682049687220736368776562656E206BC3B66E6E7420756E6420457565722054656D706F20756D203130302520657268C3B6687420776972642E00476577C3A46872742065696E65204368616E63652C20275374C3BC726D6973636865205A6F726E62C3B6656E27207A7520657268616C74656E2C20776F64757263682049687220736368776562656E206BC3B66E6E7420756E6420457565722054656D706F20756D203130302520657268C3B6687420776972642E00, 35435), -- Spell
(3205218938, 41792, 'deDE', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952455F534F4F4E00436F6D6D756E697479616E7A65696765206CC3A475667420616220696E3A0001, 35435), -- GlobalStrings
(3776013982, 324885, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C6346464646464646464C656572656E72697475616C7C720D0A24407370656C6C646573633331383438300D0A0000, 35435), -- Spell
(3776013982, 300692, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 274909, 'deDE', 0x002754726974742064657220617566676568656E64656E20536F6E6E6527206865696C7420616C6C6520766F6E20457572656E20456666656B74656E202745726E657565726E646572204E6562656C272C202745696E68C3BC6C6C656E646572204E6562656C27206F6465722027457373656E7A626F726E2720626574726F6666656E656E2056657262C3BC6E646574656E20756D2024323734393132733120476573756E646865697420756E6420657268C3B66874206469652044617565722064696573657220456666656B746520756D202473312053656B2E2C20626973207A75206D6178696D616C2024733225206968726572207572737072C3BC6E676C696368656E2044617565722E0000, 35435), -- Spell
(2035710060, 7050, 'deDE', 0x486F68657072696573746572696E204D6172276C69000030031800009D1B00000172BA000000000000000000000000000001000000FF, 35435), -- JournalEncounterSection
(3776013982, 120679, 'deDE', 0x00527566742065696E206DC3A4636874696765732057696C6474696572206865726265692C206461732045756572205A69656C20616E6772656966742E2044657220416E6772696666207769726420766F6E2065696E656D204272C3BC6C6C656E206265676C65697465742C2064617320457565722054656D706F202464206C616E6720756D202432383130333673312520657268C3B668742E0000, 35435), -- Spell
(3776013982, 293777, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324854, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646447572636873746FC39F7C720D0A24407370656C6C646573633331353238320000, 35435), -- Spell
(3776013982, 324893, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646537472C3B66D656E6465204C6562656E736B726166747C720D0A24407370656C6C646573633331383439350000, 35435), -- Spell
(3776013982, 324884, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C6346464646464646464C656572656E72697475616C7C720D0A24407370656C6C646573633331383437390000, 35435), -- Spell
(3776013982, 324853, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C634646464646464646456E747363686C6F7373656E7C720D0A24407370656C6C646573633331353534340000, 35435), -- Spell
(3776013982, 291435, 'deDE', 0x004572736368616666742065696E652064756E6B6C65205066C3BC747A652C20646965204765676E65726E2C206469652064656E204265726569636820626574726574656E2C20246F3220676569737469676520476573756E646865697420696D205665726C61756620766F6E20246420656E747A696568742E005665726C6965727420616C6C65202474322053656B2E2024733220676569737469676520476573756E64686569742E00, 35435), -- Spell
(3776013982, 155333, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 300932, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324862, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C6346464646464646465669656C7365697469677C720D0A24407370656C6C646573633331353534390000, 35435), -- Spell
(3205218938, 42496, 'deDE', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F53554254455854007C6E257320626973207A7572206175746F6D617469736368656E2041626D656C64756E670001, 35435), -- GlobalStrings
(3776013982, 110556, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 154274, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324851, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C634646464646464646456E747363686C6F7373656E7C720D0A24407370656C6C646573633331353534360000, 35435), -- Spell
(3776013982, 155347, 'deDE', 0x0049687220736569642064757263686472756E67656E20766F6D2047656973742064657320576F6C66732C206465722045757265204265776567756E6773676573636877696E6469676B65697420696D2046726F7374666575657267726174206175C39F657268616C6220646573204B616D7066657320756D202431353432353973312520657268C3B668742E004265776567756E6773676573636877696E6469676B656974206175C39F657268616C6220646573204B616D7066657320756D202431353432353973312520657268C3B668742E00, 35435), -- Spell
(3776013982, 301683, 'deDE', 0x0053747261686C742065696E652057656C6C6520676966746967656E204672C3B67374656C6E7320766F6E2064657220506F736974696F6E204575726573204765676E657273206175732C2064696520616C6C656E204765676E65726E20696E6E657268616C622065696E65732052616469757320766F6E2035204D657465726E20247331205363686164656E207A7566C3BC67742E0000, 35435), -- Spell
(3776013982, 337816, 'deDE', 0x0024407370656C6C646573633333373631320000, 35435), -- Spell
(3776013982, 324881, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5741524C4F434B5F534F554C535741502E424C503A32347C74207C634646464646464646417567656E626C69636B20646572204B6C6172686569747C720D0A24407370656C6C646573633331383233390000, 35435), -- Spell
(3776013982, 324890, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C634646464646464646556E656E646C6963686520537465726E657C720D0A24407370656C6C646573633331383438370000, 35435), -- Spell
(3776013982, 324886, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646456E747374656C6C746520476C6965646D61C39F657C720D0A24407370656C6C646573633331383438310000, 35435), -- Spell
(3745449290, 6134, 'deDE', 0x5374616474204D65636861676F6E0000F61700008E1F2444E4C4BB431233A4C300000000000000007E1A000084110000C5EC000003000000D9050000310800000000000000000000, 35435), -- AreaPOI
(3776013982, 324888, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646456E747374656C6C746520476C6965646D61C39F657C720D0A24407370656C6C646573633331383438330000, 35435), -- Spell
(3776013982, 324894, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646537472C3B66D656E6465204C6562656E736B726166747C720D0A24407370656C6C646573633331383439390000, 35435), -- Spell
(2035710060, 7070, 'deDE', 0x47657365676E65746572204C6F61676569737400486F68657072696573746572696E204D6172276C6920626573636877C3B672742065696E656E2067657365676E6574656E204C6F61676569737420616E20696872657220506F736974696F6E2E2044657220476569737420626577656774207369636820617566204D6172276C69732056657262C3BC6E646574656E206D69742064657220676572696E677374656E20476573756E6468656974207A7520756E64206865696C742069686E20756D2024313337333033733125207365696E6572204D6178696D616C676573756E64686569742C2077656E6E206572206E6963687420766F722064656D2045727265696368656E206465732056657262C3BC6E646574656E20676574C3B674657420776972642E0D0A0D0A57656E6E20646572204765697374206E616368202431333732383764206E6F636820616D204C6562656E206973742C20737072696E677420657220736F666F7274207A75207365696E656D205A69656C20756E64206865696C7420657320756D2024313337333033733125207365696E6572204D6178696D616C676573756E64686569742E0030031A8A1B00009F1B02000000000000000000000000C231080000002200FF, 35435), -- JournalEncounterSection
(3776013982, 155315, 'deDE', 0x00496872207365696420696D2045696E6B6C616E67206D69742064656E2046657565726E2064696573657220476567656E642E2045696E65204C617661666F6E74C3A46E652062726963687420766F6E205A656974207A75205A65697420646972656B7420756E74657220457572656E204765676E65726E206175732E0045696E65204C617661666F6E74C3A46E652062726963687420766F6E205A656974207A75205A65697420646972656B7420756E74657220457572656E204765676E65726E206175732E00, 35435), -- Spell
(3776013982, 301578, 'deDE', 0x000000, 35435), -- Spell
(2035710060, 7073, 'deDE', 0xC39C626C65732053636869636B73616C00486F68657072696573746572696E204D6172276C69207365747A742064696573652046C3A46869676B6569742065696E2C2077656E6E2073696520766F6D20476569737420766F6E2047617261276A616C20626573657373656E206973742E0D0A0D0A53696520656E74726569C39F74207A776569207A7566C3A46C6C6967656E20537069656C657263686172616B746572656E2069687265205365656C656E20756E642076657262696E64657420736965206D697465696E616E6465722E204A656465205365656C6520766572666F6C677420646965205365656C652C206D697420646572207369652076657262756E64656E206973742C20756E642066C3BC677420616C6C656E20537069656C657263686172616B746572656E20616C6C65202431333739373574312053656B2E2024313337393732733120536368617474656E7363686164656E207A752E20446572205363686164656E20766F6E2027C39C626C65732053636869636B73616C2720776972642076657272696E676572742C206A652077656974657220646965205365656C656E20766F6E65696E616E64657220656E746665726E742073696E642E0D0A0D0A57656E6E2065696E65205365656C652073746972627420756E64206469652056657262696E64756E67207A757220616E646572656E205365656C6520756E74657262726F6368656E20776972642C20626567696E6E742064696520766572626C656962656E6465205365656C652C20616C6C65202431333739383674322053656B2E2024313337393836733120536368617474656E7363686164656E207A7520766572757273616368656E2E0030031D8A1B00000000020000000000000000000000009B07070002001A000C, 35435), -- JournalEncounterSection
(3776013982, 155345, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 332950, 'deDE', 0x0000457572652046C3A46869676B656974656E20686162656E2065696E65204368616E63652C202440393035377331205363686164656E207A7520766572757273616368656E2E00, 35435), -- Spell
(3776013982, 324901, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464765736368C3A47266746572205665727374616E647C720D0A24407370656C6C646573633331383439380000, 35435), -- Spell
(3776013982, 324892, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646537472C3B66D656E6465204C6562656E736B726166747C720D0A24407370656C6C646573633331383237300000, 35435), -- Spell
(3776013982, 324852, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C634646464646464646456E747363686C6F7373656E7C720D0A24407370656C6C646573633331353534350000, 35435), -- Spell
(3776013982, 299937, 'deDE', 0x00446572204AC3A46765726B696C6C6572207761727074205665727374C3A4726B756E672061757320646572205374616474204D65636861676F6E206865726265692E0000, 35435), -- Spell
(3776013982, 296464, 'deDE', 0x0044696520666C696567656E646520556E7465726472C3BC636B756E677365696E68656974204A4B2D38207761727074205665727374C3A4726B756E672061757320646572205374616474204D65636861676F6E206865726265692E0000, 35435), -- Spell
(3205218938, 42646, 'deDE', 0x424E45545F4552524F525F343030313200284E7572204368696E61292053656B756E64C3A4726520656C7465726C69636865204672656967616265202832290002, 35435), -- GlobalStrings
(3776013982, 324900, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464765736368C3A47266746572205665727374616E647C720D0A24407370656C6C646573633331383439340000, 35435), -- Spell
(3776013982, 292907, 'deDE', 0x004665756572742065696E656E2045697373706C69747465722C20646572202473312520416E6772696666737363686164656E20616C73206BC3B6727065726C696368656E205363686164656E20766572757273616368742E0000, 35435), -- Spell
(3776013982, 324887, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646456E747374656C6C746520476C6965646D61C39F657C720D0A24407370656C6C646573633331383438320000, 35435), -- Spell
(3205218938, 41794, 'deDE', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952454400436F6D6D756E69747962726F77736572616E7A6569676520616267656C617566656E210001, 35435), -- GlobalStrings
(3776013982, 319451, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 154275, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 155313, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 154259, 'deDE', 0x0049687220736569642064757263686472756E67656E20766F6D2047656973742064657320576F6C66732C206465722045757265204265776567756E6773676573636877696E6469676B65697420696D2046726F737466657565726772617420756D202473312520657268C3B668742E004265776567756E6773676573636877696E6469676B65697420696D2046726F737466657565726772617420756D202473312520657268C3B668742E00, 35435), -- Spell
(3205218938, 41791, 'deDE', 0x4755494C445F46494E4445525F504F5354494E475F474F494E475F544F5F4558504952450047696C64656E616E7A65696765206CC3A475667420616220696E3A0001, 35435), -- GlobalStrings
(3776013982, 304086, 'deDE', 0x417A65726974657373656E7A0057C3A46872656E642049687220626574C3A475627420736569642C206973742064657220646566656E7369766520426F6E7573204575726572205669656C7365697469676B65697420756D202433303437373573312620657268C3B668742E0000, 35435), -- Spell
(3776013982, 324845, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646576964657268616C6C656E6465204C656572657C720D0A24407370656C6C646573633331383438360000, 35435), -- Spell
(3776013982, 155343, 'deDE', 0x000000, 35435), -- Spell
(3776013982, 324906, 'deDE', 0x004B6F6E74616D696E696572742065696E656E20476567656E7374616E64206D69742065696E65722062C3B6736172746967656E2056617269616E746520766F6E204E275A6F74687320566572646572626E69732E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C6346464646464646465A7769656C6963687476657277C3BC7374756E677C720D0A24407370656C6C646573633331383437370000, 35435), -- Spell
(2035710060, 7069, 'deDE', 0x5A6F726E20646572204C6F6100486F68657072696573746572696E204D6172276C692061747461636B696572742065696E656E20537069656C657263686172616B746572206D69742064656D20275A6F726E20646572204C6F612720756E64207665727572736163687420243133373334347331204865696C69677363686164656E2E003003198A1B00009E1B020000000000000000000000002413020000004000FF, 35435), -- JournalEncounterSection
(2948698321, 249, 'deDE', 0xD6968DCA7ACF9DD1, 35435), -- TactKeyLookup
(2948698321, 259, 'deDE', 0xB50278B84158ABDF, 35435), -- TactKeyLookup
(603412935, 28663, 'deDE', 0x3130E9878CE5B1B1E8B7AFE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28664, 'deDE', 0xE6899BE9BAA6E9838E0004, 35435), -- ChatProfanity
(603412935, 28644, 'deDE', 0xE689A9E998B4E599A80004, 35435), -- ChatProfanity
(603412935, 28652, 'deDE', 0xE5A3B9E59C8BE585A9E8A3BD0004, 35435), -- ChatProfanity
(603412935, 28656, 'deDE', 0xE99988E696B9E5AE89E7949F0004, 35435), -- ChatProfanity
(603412935, 28653, 'deDE', 0xE994A4E995B0E5B8AE0004, 35435), -- ChatProfanity
(603412935, 28650, 'deDE', 0x4C69626572617465484B0004, 35435), -- ChatProfanity
(603412935, 28645, 'deDE', 0xE5BEB7E5AFB8E88C8E0004, 35435), -- ChatProfanity
(603412935, 28648, 'deDE', 0xE99B8FE5A5B30004, 35435), -- ChatProfanity
(603412935, 28658, 'deDE', 0xE794B2E7B49AE688A6E78AAF0004, 35435), -- ChatProfanity
(603412935, 28655, 'deDE', 0xE69C80E9AB98E4BABAE6B0910004, 35435), -- ChatProfanity
(603412935, 28661, 'deDE', 0xE684BFE88DA3E58589E5BD92E9A699E6B8AF0004, 35435), -- ChatProfanity
(603412935, 28649, 'deDE', 0xE6B9BFE7A9B40004, 35435), -- ChatProfanity
(603412935, 28657, 'deDE', 0xE4BD95E4BF8AE4BB810004, 35435), -- ChatProfanity
(603412935, 28647, 'deDE', 0xE99CB2E998B4E9B8A10004, 35435), -- ChatProfanity
(603412935, 28662, 'deDE', 0xE58D81E9878CE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28646, 'deDE', 0xE88C8EE9BE9F0004, 35435), -- ChatProfanity
(603412935, 28651, 'deDE', 0x66726565484B0004, 35435), -- ChatProfanity
(603412935, 28660, 'deDE', 0xE88194E982A6E5AEA3E8A8800004, 35435), -- ChatProfanity
(603412935, 28654, 'deDE', 0xE4BABAE6B091E6A380E5AF9FE999A20004, 35435), -- ChatProfanity
(603412935, 28659, 'deDE', 0xE696B0E4B8ADE59BBDE88194E982A60004, 35435), -- ChatProfanity
(4033975491, 403803, 'deDE', 0x0000704100000000000000410000000000000000000000005B290600308A1300000000000000000000000000000000000000000000000000000000204100000000FFFFFFFFFFFF00000000000000000000000AD50100, 35435), -- SpellVisualKitModelAttach
(4146370265, 91772, 'deDE', 0x0000A0400000000000002041000000000000000000000000000000000000000022130000000000000000000000000000000000000000000000000000000000000000, 35435), -- SpellVisual
(517656225, 6688, 'deDE', 0x0000803F00000000E17AD43F000000000000000100001A00000000000303000000000000000000000000A4707D3F0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFF4742000000000000000000000000000000000000C8430000964300000040FFFFFFFF02038030E13E022B873D0AD7233C636D2400000020400000003F69000000000000000000803F0000803F6E186F180000000000000000000000000000000000000000403F3333B33E6666E63E0000000000000000000000000000000000000000000000000000000000000000000000008D5E1E008C5E1E008C5E1E00, 35435), -- SpellChainEffects
(4033975491, 404117, 'deDE', 0x00000000000000000000C03F000000000000000000000000952A0600D9891300000000000000000000000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000009D50100, 35435), -- SpellVisualKitModelAttach
(1181150530, 307455, 'deDE', 0x020000005B2906000AD50100, 35435), -- SpellVisualKitEffect
(25144992, 2203, 'deDE', 0x201A0000000000000000000001000000CB0100000000000013000000FFFFFFFF0000000000000000, 35435); -- BeamEffect

