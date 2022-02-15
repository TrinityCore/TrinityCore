DELETE FROM `broadcast_text_locale` WHERE `VerifiedBuild`>0 AND `locale` = 'itIT' AND `ID` IN (201778, 753, 195400, 79796, 165870, 79799, 79798, 79804, 194274, 183984, 201777, 79794, 79795, 141708, 201784, 165241, 165243, 165245, 165239, 165246, 165244, 165237);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(201778, 'itIT', 'Siamo pronti. Fai strada!', 'Siamo pronti. Fai strada!', 35435),
(753, 'itIT', 'Come?!? Vuoi dire che non riesci a ucciderlo da solo?', '', 35435),
(195400, 'itIT', 'Lascia che dia un\'occhiata alle tue essenze sintetizzate.', 'Lascia che dia un\'occhiata alle tue essenze sintetizzate.', 35435),
(79796, 'itIT', 'Pietra Sciamanica scoperta: Toccato dal Fuoco', 'Pietra Sciamanica scoperta: Toccato dal Fuoco', 35435),
(165870, 'itIT', '', 'Ti racconterò della caduta di Rastakhan, quando sarai $gpronto:pronta;.', 35435),
(79799, 'itIT', 'Pietra Sciamanica scoperta: Fermezza di Ogrish', 'Pietra Sciamanica scoperta: Fermezza di Ogrish', 35435),
(79798, 'itIT', 'Pietra Sciamanica scoperta: Folata Turbolenta', 'Pietra Sciamanica scoperta: Folata Turbolenta', 35435),
(79804, 'itIT', 'Pietra Sciamanica scoperta: Toccato dal Ghiaccio', 'Pietra Sciamanica scoperta: Toccato dal Ghiaccio', 35435),
(194274, 'itIT', 'I want to teleport to Operation: Mechagon (Dungeon).', 'I want to teleport to Operation: Mechagon (Dungeon).', 35435),
(183984, 'itIT', '|cfff2e699+$1i Sanità Mentale|r', '|cfff2e699+$1i Sanità Mentale|r', 35435),
(201777, 'itIT', '', 'Conosco nu modo per raggiungere la Figlia del Mare. Seguitemi, se vi sentite pronti.', 35435),
(79794, 'itIT', 'Pietra Sciamanica scoperta: Benedizione del Lupo', 'Pietra Sciamanica scoperta: Benedizione del Lupo', 35435),
(79795, 'itIT', 'Pietra Sciamanica scoperta: Spirito del Lupo', 'Pietra Sciamanica scoperta: Spirito del Lupo', 35435),
(141708, 'itIT', 'Indebolisci il grifone ma mantieni la presa con |TInterface\\ICONS\\INV_MISC_DESECRATED_LEATHERGLOVE.BLP:20|t |cFFFF0000|Hspell:269442|h[Presa Salda]|h|r', '', 35435),
(201784, 'itIT', 'L\'ho visto con i miei occhi! Dama Jaina ha lanciato l\'assalto in mare aperto!', '', 35435),
(165241, 'itIT', 'Più a fondo, ancora più a fondo...', 'Più a fondo, ancora più a fondo...', 35435),
(165243, 'itIT', 'Finalmente... accettate la verità dell\'ombra.', 'Finalmente... accettate la verità dell\'ombra.', 35435),
(165245, 'itIT', 'Ogni vostra scelta vi porterà più vicini a diventare miei servi.', 'Ogni vostra scelta vi porterà più vicini a diventare miei servi.', 35435),
(165239, 'itIT', 'Attingete alla vostra furia... Trasformate il vostro odio in un\'arma.', 'Attingete alla vostra furia... Trasformate il vostro odio in un\'arma.', 35435),
(165246, 'itIT', 'Meri ammassi di carne decomposta sotto lo sguardo di un dio.', 'Meri ammassi di carne decomposta sotto lo sguardo di un dio.', 35435),
(165244, 'itIT', 'Sì... avvicinatevi... sempre di più.', 'Sì... avvicinatevi... sempre di più.', 35435),
(165237, 'itIT', 'Ahhh... Pensate di conoscere il vero potere.', 'Ahhh... Pensate di conoscere il vero potere.', 35435);

DELETE FROM `gameobjects_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `gameobjects_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(341828, 'itIT', 'Teletrasporto di Meccagon', 35435),
(341363, 'itIT', 'Teletrasporto di Meccagon', 35435),
(338477, 'itIT', 'Teletrasporto di Meccagon', 35435);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(87487, 'itIT', 'Scudo della Risonanza Sonora', 35435);

DELETE FROM `azerite_essence_power_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `azerite_essence_power_locale` (`ID`, `locale`, `SourceAlliance_lang`, `SourceHorde_lang`, `VerifiedBuild`) VALUES
(114, 'itIT', 'Visioni Orripilanti di N\'zoth|n|cFFFFD200Impresa:|r|n\"Tra abissi e visioni\"|n|cFFFFD200PNG:|r Irathion|n|cFFFFD200Zona:|r Sala del Cuore', '', 35435),
(132, 'itIT', 'Visioni Orripilanti di N\'zoth|n|cFFFFD200Impresa:|r|n\"Tra abissi e visioni\"|n|cFFFFD200PNG:|r Irathion|n|cFFFFD200Zona:|r Sala del Cuore', '', 35435),
(140, 'itIT', 'Visioni Orripilanti di N\'zoth|n|cFFFFD200Impresa:|r|n\"Tra abissi e visioni\"|n|cFFFFD200PNG:|r Irathion|n|cFFFFD200Zona:|r Sala del Cuore', '', 35435);

DELETE FROM `currency_types_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1803, 'itIT', 'Echi di Ny\'alotha', 'Una volta purificata questa sostanza dalla corruzione di N\'zoth, la M.A.D.R.E. può utilizzarla per sintetizzare le essenze nella Sala del Cuore.', 35435);

DELETE FROM `spell_name_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(324906, 'itIT', 'Corruzione - Devastazione del Crepuscolo 2', 35435),
(155343, 'itIT', 'Furia della Burrasca', 35435),
(324845, 'itIT', 'Corruzione - Vuoto Riecheggiante 3', 35435),
(304086, 'itIT', 'Conflitto', 35435),
(154259, 'itIT', 'Spirito del Lupo', 35435),
(155313, 'itIT', 'Toccato dal Fuoco', 35435),
(154275, 'itIT', 'Spirito del Lupo', 35435),
(319451, 'itIT', 'Teletrasporto: Città di Meccagon', 35435),
(324887, 'itIT', 'Corruzione - Appendice Distorta 2', 35435),
(292907, 'itIT', '', 35435),
(324900, 'itIT', 'Corruzione - Mente Concentrata 2', 35435),
(296464, 'itIT', 'Ripetitore di Rinforzo', 35435),
(299937, 'itIT', 'Ripetitore di Rinforzo', 35435),
(324852, 'itIT', 'Corruzione - Espediente 2', 35435),
(324892, 'itIT', 'Corruzione - Vitalità Crescente 1', 35435),
(324901, 'itIT', 'Corruzione - Mente Concentrata 3', 35435),
(332950, 'itIT', 'Attivazione da Fuoco', 35435),
(155345, 'itIT', 'Fermezza da Ogre', 35435),
(301578, 'itIT', 'REUSE ME', 35435),
(155315, 'itIT', 'Toccato dal Fuoco', 35435),
(324894, 'itIT', 'Corruzione - Vitalità Crescente 3', 35435),
(324888, 'itIT', 'Corruzione - Appendice Distorta 3', 35435),
(324886, 'itIT', 'Corruzione - Appendice Distorta 1', 35435),
(324890, 'itIT', 'Corruzione - Stelle Infinite 2', 35435),
(324881, 'itIT', 'Corruzione - Barlume di Lucidità', 35435),
(337816, 'itIT', 'Conseguenze Inevitabili', 35435),
(301683, 'itIT', 'REUSE ME', 35435),
(155347, 'itIT', 'Spirito del Lupo', 35435),
(324851, 'itIT', 'Corruzione - Espediente 3', 35435),
(154274, 'itIT', 'Benedizione del Lupo', 35435),
(110556, 'itIT', '[DNT] Force Cast Tried to Fly', 35435),
(324862, 'itIT', 'Corruzione - Versatile 1', 35435),
(300932, 'itIT', 'REUSE ME [MTMM] (DNT)', 35435),
(155333, 'itIT', 'Toccato dal Ghiaccio', 35435),
(291435, 'itIT', '', 35435),
(324853, 'itIT', 'Corruzione - Espediente 1', 35435),
(324884, 'itIT', 'Corruzione - Rituale del Vuoto 2', 35435),
(324893, 'itIT', 'Corruzione - Vitalità Crescente 2', 35435),
(324854, 'itIT', 'Corruzione - Cancellante 3', 35435),
(293777, 'itIT', 'Schianto d\'Ombra', 35435),
(120679, 'itIT', 'Bestia Feroce', 35435),
(274909, 'itIT', 'Nebbia Crescente', 35435),
(300692, 'itIT', 'REUSE ME [MTMM] (DNT)', 35435),
(324885, 'itIT', 'Corruzione - Rituale del Vuoto 3', 35435),
(155344, 'itIT', 'Furia della Burrasca', 35435),
(335642, 'itIT', 'Uber Strike', 35435),
(335148, 'itIT', 'Marchio della Distorsione Fatua', 35435),
(315958, 'itIT', 'Teletrasporto: Città di Meccagon', 35435),
(327254, 'itIT', 'Minaccia della Spora Marcescente', 35435),
(324839, 'itIT', 'Corruzione - Impeto Letale 3', 35435),
(264663, 'itIT', 'Sete del Predatore', 35435),
(302166, 'itIT', 'Ripetitore di Rinforzo', 35435),
(293072, 'itIT', '', 35435),
(311204, 'itIT', 'Teletrasporto: Meccagon', 35435),
(324870, 'itIT', 'Corruzione - Criticità 3', 35435),
(155334, 'itIT', 'Toccato dal Ghiaccio', 35435),
(324902, 'itIT', 'Corruzione - Ferita Zampillante', 35435),
(275496, 'itIT', 'Giustizia Indomabile', 35435),
(316661, 'itIT', 'Distruzione d\'Ossidiana', 35435),
(324864, 'itIT', 'Corruzione - Versatile 2', 35435),
(321200, 'itIT', 'Lancio Missione', 35435),
(324904, 'itIT', 'Corruzione - Verità Ineffabile 2', 35435),
(154253, 'itIT', 'Benedizione del Lupo', 35435),
(331973, 'itIT', '', 35435),
(325946, 'itIT', 'Lancio Poltiglia', 35435),
(324891, 'itIT', 'Corruzione - Stelle Infinite 3', 35435),
(321748, 'itIT', 'Clonami!', 35435),
(324882, 'itIT', 'Corruzione - Rituale del Vuoto 1', 35435),
(324860, 'itIT', 'Corruzione - Magistrale 2', 35435),
(324850, 'itIT', 'Corruzione - Vuoto Riecheggiante 1', 35435),
(324899, 'itIT', 'Corruzione - Mente Concentrata 1', 35435),
(294003, 'itIT', '', 35435),
(313040, 'itIT', 'Oscurità Infinita', 35435),
(324903, 'itIT', 'Corruzione - Verità Ineffabile 1', 35435),
(324680, 'itIT', 'Corruzione - Impeto Letale 1', 35435),
(321201, 'itIT', 'Lancio Missione', 35435),
(155346, 'itIT', 'Fermezza da Ogre', 35435),
(294479, 'itIT', 'Dissotterramento', 35435),
(325947, 'itIT', 'Lancio Poltiglia', 35435),
(328136, 'itIT', 'Ascendente Notevole', 35435),
(324861, 'itIT', 'Corruzione - Magistrale 1', 35435),
(300748, 'itIT', 'REUSE ME [MTMM] (DNT)', 35435),
(335151, 'itIT', 'Marchio delle Nebbie', 35435),
(324879, 'itIT', 'Corruzione - Aspirante 2', 35435),
(256133, 'itIT', 'REUSE ME [SCS]', 35435),
(324880, 'itIT', 'Corruzione - Aspirante 3', 35435),
(335152, 'itIT', 'Marchio del Ferro', 35435),
(306259, 'itIT', 'Tentacolo', 35435),
(324858, 'itIT', 'Corruzione - Magistrale 3', 35435),
(321428, 'itIT', 'Tributo Infinito', 35435),
(335150, 'itIT', 'Marchio del Distruttore', 35435),
(324907, 'itIT', 'Corruzione - Devastazione del Crepuscolo 3', 35435),
(324889, 'itIT', 'Corruzione - Stelle Infinite 1', 35435),
(324898, 'itIT', 'Corruzione - Impulso di Corsa 3', 35435),
(256134, 'itIT', 'REUSE ME [SCS]', 35435),
(324875, 'itIT', 'Corruzione - Elusivo 2', 35435),
(324866, 'itIT', 'Corruzione - Criticità 1', 35435),
(300798, 'itIT', 'REUSE ME [MTMM] (DNT)', 35435),
(292579, 'itIT', '', 35435),
(337612, 'itIT', 'Conseguenze Inevitabili', 35435),
(324877, 'itIT', 'Corruzione - Aspirante 1', 35435),
(324868, 'itIT', 'Corruzione - Criticità 2', 35435),
(324837, 'itIT', 'Corruzione - Impeto Letale 2', 35435),
(324848, 'itIT', 'Corruzione - Vuoto Riecheggiante 2', 35435),
(115546, 'itIT', 'Istigazione', 35435),
(324895, 'itIT', 'Corruzione - Elusivo 1', 35435),
(324857, 'itIT', 'Corruzione - Cancellante 1', 35435),
(324897, 'itIT', 'Corruzione - Impulso di Corsa 2', 35435),
(321714, 'itIT', 'Teletrasporto: Silitus', 35435),
(324896, 'itIT', 'Corruzione - Impulso di Corsa 1', 35435),
(324856, 'itIT', 'Corruzione - Cancellante 2', 35435),
(335149, 'itIT', 'Marchio del Flagello', 35435),
(324865, 'itIT', 'Corruzione - Versatile 3', 35435),
(324905, 'itIT', 'Corruzione - Devastazione del Crepuscolo 1', 35435),
(324874, 'itIT', 'Corruzione - Elusivo 3', 35435);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(85118, 'itIT', '', 35435),
(85126, 'itIT', '', 35435),
(85114, 'itIT', '', 35435),
(85084, 'itIT', '', 35435),
(85132, 'itIT', '', 35435),
(85098, 'itIT', '', 35435),
(85134, 'itIT', '', 35435),
(85025, 'itIT', 'Riva del Sud contro Mulino di Tarren', 35435),
(85128, 'itIT', '', 35435),
(84755, 'itIT', 'Completa la missione del Mantello Leggendario', 35435),
(85090, 'itIT', '', 35435),
(85130, 'itIT', '', 35435),
(84814, 'itIT', 'Giocatore Nobile Oscuro è idoneo all\'Armatura Retaggio', 35435),
(85100, 'itIT', '', 35435),
(85136, 'itIT', '', 35435),
(85102, 'itIT', '', 35435),
(85138, 'itIT', '', 35435),
(84815, 'itIT', 'Giocatore Orco Mag\'har è idoneo all\'Armatura Retaggio', 35435),
(85108, 'itIT', '', 35435),
(85110, 'itIT', '', 35435),
(85116, 'itIT', '', 35435),
(84812, 'itIT', 'Giocatore Meccagnomo è idoneo all\'Armatura Retaggio', 35435),
(78565, 'itIT', 'Differenziale Perfettamente a Tempo', 35435),
(34935, 'itIT', 'Ottieni la benedizione della Pietra Sciamanica: Spirito del Lupo', 35435),
(82623, 'itIT', 'Ripulisci la spazzatura a Meccagon', 35435),
(84810, 'itIT', 'Giocatore Nano Ferroscuro è idoneo all\'Armatura Retaggio', 35435),
(84809, 'itIT', 'Giocatore Elfo del Vuoto è idoneo all\'Armatura Retaggio', 35435),
(85096, 'itIT', '', 35435),
(85092, 'itIT', '', 35435),
(84816, 'itIT', 'Troll Zandalari è idoneo per l\'Armatura Retaggio', 35435),
(85122, 'itIT', '', 35435),
(84808, 'itIT', 'Giocatore Tauren di Alto Monte è idoneo all\'Armatura Retaggio', 35435),
(85120, 'itIT', '', 35435),
(85112, 'itIT', '', 35435),
(84813, 'itIT', 'Giocatore Vulpera è idoneo all\'Armatura Retaggio', 35435),
(85124, 'itIT', '', 35435),
(85088, 'itIT', '', 35435),
(85094, 'itIT', '', 35435),
(85086, 'itIT', '', 35435),
(85106, 'itIT', '', 35435),
(84817, 'itIT', 'Umano di Kul Tiras è idoneo per l\'Armatura Retaggio', 35435),
(85104, 'itIT', '', 35435),
(84811, 'itIT', 'Giocatore Draenei Forgialuce è idoneo all\'Armatura Retaggio', 35435);

DELETE FROM `item_name_description_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `item_name_description_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(13566, 'itIT', '35 Corruzione', 35435),
(13578, 'itIT', '16 Corruzione', 35435),
(13569, 'itIT', '10 Corruzione', 35435),
(13574, 'itIT', '28 Corruzione', 35435),
(13572, 'itIT', '25 Corruzione', 35435),
(13520, 'itIT', '30 Corruzione', 35435),
(13579, 'itIT', '8 Corruzione', 35435),
(13516, 'itIT', '5 Corruzione', 35435),
(13568, 'itIT', '20 Corruzione', 35435),
(13521, 'itIT', '5-30 Corruzione', 35435),
(13576, 'itIT', '30 Corruzione', 35435),
(13518, 'itIT', '15 Corruzione', 35435),
(13519, 'itIT', '20 Corruzione', 35435),
(13577, 'itIT', '12 Corruzione', 35435),
(13575, 'itIT', '17 Corruzione', 35435),
(13570, 'itIT', '75 Corruzione', 35435),
(13565, 'itIT', '66 Corruzione', 35435),
(13513, 'itIT', '25 Corruzione', 35435),
(13580, 'itIT', '60 Corruzione', 35435),
(13517, 'itIT', '10 Corruzione', 35435),
(13571, 'itIT', '50 Corruzione', 35435),
(13573, 'itIT', '45 Corruzione', 35435),
(13567, 'itIT', '15 Corruzione', 35435);

DELETE FROM `area_table_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12825, 'itIT', 'Città di Meccagon', 35435),
(10290, 'itIT', 'Meccagon', 35435);

DELETE FROM `ui_map_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `ui_map_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1574, 'itIT', 'Città di Meccagon', 35435),
(1573, 'itIT', 'Città di Meccagon', 35435);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(177977, 'itIT', '', '', '', '', 'Contaminante Preservato: Ferita Zampillante', 35435),
(177997, 'itIT', '', '', '', '', 'Contaminante Preservato: Prosciugamento', 35435),
(178006, 'itIT', '', '', '', '', 'Contaminante Preservato: Devastazione del Crepuscolo', 35435),
(177974, 'itIT', '', '', '', '', 'Contaminante Preservato: Espediente', 35435),
(177976, 'itIT', '', '', '', '', 'Contaminante Preservato: Barlume di Lucidità', 35435),
(178015, 'itIT', '', '', '', '', 'Contaminante Preservato: Rituale del Vuoto', 35435),
(178012, 'itIT', '', '', '', '', 'Contaminante Preservato: Versatile', 35435),
(87487, 'itIT', '', '', '', '', 'Scudo della Risonanza Sonora', 35435),
(177983, 'itIT', '', '', '', '', 'Contaminante Preservato: Stelle Infinite', 35435),
(177980, 'itIT', '', '', '', '', 'Contaminante Preservato: Mente Concentrata', 35435),
(178004, 'itIT', '', '', '', '', 'Contaminante Preservato: Devastazione del Crepuscolo', 35435),
(177987, 'itIT', '', '', '', '', 'Contaminante Preservato: Magistrale', 35435),
(177965, 'itIT', '', '', '', '', 'Contaminante Preservato: Impeto Letale', 35435),
(177989, 'itIT', '', '', '', '', 'Contaminante Preservato: Impulso di Corsa', 35435),
(177998, 'itIT', '', '', '', '', 'Contaminante Preservato: Amplificazione', 35435),
(178011, 'itIT', '', '', '', '', 'Contaminante Preservato: Versatile', 35435),
(177993, 'itIT', '', '', '', '', 'Contaminante Preservato: Criticità', 35435),
(177978, 'itIT', '', '', '', '', 'Contaminante Preservato: Mente Concentrata', 35435),
(178002, 'itIT', '', '', '', '', 'Contaminante Preservato: Vitalità Crescente', 35435),
(177967, 'itIT', '', '', '', '', 'Contaminante Preservato: Vuoto Riecheggiante', 35435),
(177970, 'itIT', '', '', '', '', 'Contaminante Preservato: Elusivo', 35435),
(177972, 'itIT', '', '', '', '', 'Contaminante Preservato: Elusivo', 35435),
(177992, 'itIT', '', '', '', '', 'Contaminante Preservato: Criticità', 35435),
(177985, 'itIT', '', '', '', '', 'Contaminante Preservato: Stelle Infinite', 35435),
(177982, 'itIT', '', '', '', '', 'Contaminante Preservato: Verità Ineffabile', 35435),
(177991, 'itIT', '', '', '', '', 'Contaminante Preservato: Impulso di Corsa', 35435),
(177971, 'itIT', '', '', '', '', 'Contaminante Preservato: Elusivo', 35435),
(168043, 'itIT', 'Bramato dagli Amathet, che si ritengono i custodi delle opere dei Titani.', '', '', '', 'Manufatto dei Titani', 35435),
(177964, 'itIT', '', '', '', '', 'Incantamento Arma - Moltiplicatore di Forza', 35435),
(177986, 'itIT', '', '', '', '', 'Contaminante Preservato: Magistrale', 35435),
(178013, 'itIT', '', '', '', '', 'Contaminante Preservato: Rituale del Vuoto', 35435),
(177994, 'itIT', '', '', '', '', 'Contaminante Preservato: Criticità', 35435),
(178009, 'itIT', '', '', '', '', 'Contaminante Preservato: Appendice Distorta', 35435),
(173937, 'itIT', 'L\'occhio ti fissa, a prescindere da dove guardi.', '', '', '', 'Oculus Reciso', 35435),
(177973, 'itIT', '', '', '', '', 'Contaminante Preservato: Espediente', 35435),
(178007, 'itIT', '', '', '', '', 'Contaminante Preservato: Appendice Distorta', 35435),
(177981, 'itIT', '', '', '', '', 'Contaminante Preservato: Verità Ineffabile', 35435),
(178003, 'itIT', '', '', '', '', 'Contaminante Preservato: Vitalità Crescente', 35435),
(177979, 'itIT', '', '', '', '', 'Contaminante Preservato: Mente Concentrata', 35435),
(177966, 'itIT', '', '', '', '', 'Contaminante Preservato: Impeto Letale', 35435),
(177999, 'itIT', '', '', '', '', 'Contaminante Preservato: Amplificazione', 35435),
(178010, 'itIT', '', '', '', '', 'Contaminante Preservato: Versatile', 35435),
(177969, 'itIT', '', '', '', '', 'Contaminante Preservato: Vuoto Riecheggiante', 35435),
(178000, 'itIT', '', '', '', '', 'Contaminante Preservato: Amplificazione', 35435),
(177975, 'itIT', '', '', '', '', 'Contaminante Preservato: Espediente', 35435),
(178001, 'itIT', '', '', '', '', 'Contaminante Preservato: Vitalità Crescente', 35435),
(178008, 'itIT', '', '', '', '', 'Contaminante Preservato: Appendice Distorta', 35435),
(177995, 'itIT', '', '', '', '', 'Contaminante Preservato: Prosciugamento', 35435),
(177968, 'itIT', '', '', '', '', 'Contaminante Preservato: Vuoto Riecheggiante', 35435),
(177955, 'itIT', '', '', '', '', 'Contaminante Preservato: Impeto Letale', 35435),
(177988, 'itIT', '', '', '', '', 'Contaminante Preservato: Magistrale', 35435),
(177996, 'itIT', '', '', '', '', 'Contaminante Preservato: Prosciugamento', 35435),
(177984, 'itIT', '', '', '', '', 'Contaminante Preservato: Stelle Infinite', 35435),
(178014, 'itIT', '', '', '', '', 'Contaminante Preservato: Rituale del Vuoto', 35435),
(177990, 'itIT', '', '', '', '', 'Contaminante Preservato: Impulso di Corsa', 35435),
(178005, 'itIT', '', '', '', '', 'Contaminante Preservato: Devastazione del Crepuscolo', 35435),
(141057, 'itIT', 'Ti insegna a creare il Glifo - Scoppio Lampo.', '', '', '', 'Tecnica: Glifo - Scoppio Lampo', 35435),
(139412, 'itIT', '', '', '', '', 'Tartarughe da Guerra Mutanti Giovani', 35435),
(139345, 'itIT', '', '', '', '', 'Zampette di Ratto', 35435),
(139411, 'itIT', '', '', '', '', 'Banchetto dei Sotterranei', 35435),
(137826, 'itIT', 'Ti insegna a creare un Pendente con Rubino d\'Ombra Incantato.', '', '', '', 'Modello: Pendente con Rubino d\'Ombra Incantato', 35435),
(138016, 'itIT', 'Ti insegna a creare una Cassa di Vestiti: Cittadini di Dalaran.', '', '', '', 'Modello di Cassa di Vestiti: Cittadini di Dalaran', 35435),
(137932, 'itIT', 'Ti insegna a creare un Cerchio Fiammeggiante.', '', '', '', 'Modello: Cerchio Fiammeggiante', 35435),
(137954, 'itIT', 'Ti insegna a creare una Cintura di Fildiseta.', '', '', '', 'Modello: Cintura di Fildiseta', 35435),
(137901, 'itIT', 'Ti insegna a creare un Cinturone del Battagliero.', '', '', '', 'Modello: Cinturone del Battagliero', 35435),
(137881, 'itIT', 'Ti insegna a creare una Cintura di Pellefiera.', '', '', '', 'Modello: Cintura di Pellefiera', 35435),
(139344, 'itIT', '', '', '', '', 'Banana al Mana', 35435),
(139347, 'itIT', '', '', '', '', 'Sottervino', 35435),
(137706, 'itIT', 'Ti insegna a creare una Carica di Polvere da Sparo.', '', '', '', 'Schema: Carica di Polvere da Sparo', 35435),
(137962, 'itIT', 'Ti insegna a creare una Cintura di Fildiseta.', '', '', '', 'Modello: Cintura di Fildiseta', 35435),
(137829, 'itIT', 'Ti insegna a creare un Pendente con Rubino d\'Ombra Scaltro.', '', '', '', 'Modello: Pendente con Rubino d\'Ombra Scaltro', 35435),
(137913, 'itIT', 'Ti insegna a creare un Cinturone del Battagliero.', '', '', '', 'Modello: Cinturone del Battagliero', 35435),
(137917, 'itIT', 'Ti insegna a creare un Cinturone di Scaglie Sepolcrali.', '', '', '', 'Modello: Cinturone di Scaglie Sepolcrali', 35435),
(139431, 'itIT', '', '', '', '', 'Cassa di Bardature per Rattostalloni', 35435),
(141065, 'itIT', 'Ti insegna a creare il Glifo - Guardia Maligna.', '', '', '', 'Tecnica: Glifo - Guardia Maligna', 35435),
(137885, 'itIT', 'Ti insegna a creare una Cintura di Cuoio del Terrore.', '', '', '', 'Modello: Cintura di Cuoio del Terrore', 35435),
(137869, 'itIT', 'Ti insegna a creare una Cintura di Pellefiera.', '', '', '', 'Modello: Cintura di Pellefiera', 35435),
(127918, 'itIT', 'Ti insegna a creare una Pozione di Mana Antica più efficacemente.', '', '', '', 'Ricetta: Pozione di Mana Antica', 35435),
(139422, 'itIT', '', '', '', '', 'Vilinteriora', 35435),
(141058, 'itIT', 'Ti insegna a creare il Glifo - Maleficio Animale.', '', '', '', 'Tecnica: Glifo - Maleficio Animale', 35435),
(141038, 'itIT', 'Ti insegna a creare il Glifo - Nemici d\'Ombra.', '', '', '', 'Tecnica: Glifo - Nemici d\'Ombra', 35435),
(139346, 'itIT', '', '', '', '', 'Fluido Potabile Brevettato di Thuni', 35435),
(137934, 'itIT', 'Ti insegna a creare un Guinzaglio per Mascotte di Cuoio.', '', '', '', 'Modello: Guinzaglio per Mascotte di Cuoio', 35435),
(137831, 'itIT', 'Ti insegna a creare un Girocollo di Pandemonite Vendicativo.', '', '', '', 'Modello: Girocollo di Pandemonite Vendicativo', 35435),
(139425, 'itIT', '', '', '', '', 'Contratto Vincolaimp', 35435),
(141850, 'itIT', 'Ti insegna a creare una Sella per Grancorno.', '', '', '', 'Modello: Sella per Grancorno', 35435),
(137966, 'itIT', 'Ti insegna a creare una Cintura di Fildiseta Infusa.', '', '', '', 'Modello: Cintura di Fildiseta Infusa', 35435);

DELETE FROM `mount_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(468, 'itIT', 'Quilen Imperiale', '|cFFFFD200Promozione:|r Collector\'s Edition di Mists of Pandaria', 'Creature amate dagli antichi principi dei Mogu, i Quilen sono compagni e cavalcature leali e impavide.', 35435),
(1282, 'itIT', 'Serpe Nera di N\'zoth', '|cFFFFD200Impresa:|r Tra abissi e visioni', 'Le serpi nere di N\'zoth sono i precursori della sua Visione definitiva sul punto di diventare realtà. Solo i servitori o i nemici che osano attraversare quei luoghi hanno la possibilità di guidarli.', 35435);

DELETE FROM `player_condition_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(79509, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza della Resistenza di Bullonaccio su un altro personaggio per sbloccare questa essenza.', 35435),
(79518, 'itIT', 'Apprendi il Grado 3 di Lotta e Conflitto su un altro personaggio per sbloccare questa essenza.', 35435),
(79511, 'itIT', 'Apprendi il Grado 3 di Forza Vitale Condensata, Condotto della Vitalità o Dono Imperituro di Azeroth su un altro personaggio per sbloccare questa essenza.', 35435),
(79508, 'itIT', 'Apprendi il Grado 3 di Sangue dei Nemici, Artificio del Tempo o Sfera della Soppressione su un altro personaggio per sbloccare questa essenza.', 35435),
(79523, 'itIT', 'Apprendi il Grado 3 di Vuoto Informe su un altro personaggio per sbloccare questa essenza.', 35435),
(74078, 'itIT', 'Richiede Ashjra\'kamas, Manto della Risolutezza.', 35435),
(79512, 'itIT', 'Apprendi il Grado 3 di Visione della Perfezione su un altro personaggio per sbloccare questa essenza.', 35435),
(79505, 'itIT', 'Apprendi il Grado 3 di Increspatura Spaziale su un altro personaggio per sbloccare questa essenza.', 35435),
(79499, 'itIT', 'Apprendi il Grado 3 di Iride Focalizzante, Invocazione della Protettrice della Vita o Anima della Vita e della Morte su un altro personaggio per sbloccare questa essenza.', 35435),
(79522, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza delle Visioni Orripilanti su un altro personaggio per sbloccare questa essenza.', 35435),
(79514, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza dei Rajani o della Coalizione di Uldum su un altro personaggio per sbloccare questa essenza.', 35435),
(75180, 'itIT', 'Richiede l\'impresa \"Tra abissi e visioni\" e l\'essenza di Grado 3 sbloccata. (Impossibile acquistare se già in possesso)', 35435),
(79516, 'itIT', 'Apprendi il Grado 3 di Memoria dei Sogni Lucidi su un altro personaggio per sbloccare questa essenza.', 35435),
(79519, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza dei Rajani o della Coalizione di Uldum su un altro personaggio per sbloccare questa essenza.', 35435),
(79504, 'itIT', 'Apprendi il Grado 3 di Forza Vitale Condensata, Condotto della Vitalità o Dono Imperituro di Azeroth su un altro personaggio per sbloccare questa essenza.', 35435),
(75170, 'itIT', 'Richiede l\'impresa \"Tra abissi e visioni\" e l\'essenza di Grado 3 sbloccata. (Impossibile acquistare se già in possesso)', 35435),
(79513, 'itIT', 'Apprendi il Grado 3 di Sangue dei Nemici, Artificio del Tempo o Sfera della Soppressione su un altro personaggio per sbloccare questa essenza.', 35435),
(79502, 'itIT', 'Apprendi il Grado 3 di Crogiolo delle Fiamme su un altro personaggio per sbloccare questa essenza.', 35435),
(79501, 'itIT', 'Apprendi il Grado 3 di Iride Focalizzante, Invocazione della Protettrice della Vita o Anima della Vita e della Morte su un altro personaggio per sbloccare questa essenza.', 35435),
(79486, 'itIT', 'Apprendi il Grado 3 di Forza Vitale Condensata, Condotto della Vitalità o Dono Imperituro di Azeroth su un altro personaggio per sbloccare questa essenza.', 35435),
(79515, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza della reputazione di Nazjatar su un altro personaggio per sbloccare questa essenza.', 35435),
(79510, 'itIT', 'Apprendi il Grado 3 di Iride Focalizzante, Invocazione della Protettrice della Vita o Anima della Vita e della Morte su un altro personaggio per sbloccare questa essenza.', 35435),
(79497, 'itIT', 'Apprendi il Grado 3 di Sangue dei Nemici, Artificio del Tempo o Sfera della Soppressione su un altro personaggio per sbloccare questa essenza.', 35435),
(79521, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza dei Rajani o della Coalizione di Uldum su un altro personaggio per sbloccare questa essenza.', 35435),
(75191, 'itIT', 'Richiede l\'impresa \"Tra abissi e visioni\" e l\'essenza di Grado 3 sbloccata. (Impossibile acquistare se già in possesso)', 35435),
(79506, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza delle Visioni Orripilanti su un altro personaggio per sbloccare questa essenza.', 35435),
(79500, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza della Resistenza di Bullonaccio su un altro personaggio per sbloccare questa essenza.', 35435),
(79503, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza della Resistenza di Bullonaccio su un altro personaggio per sbloccare questa essenza.', 35435),
(79498, 'itIT', 'Apprendi il Grado 3 di Risonanza della Vena del Mondo su un altro personaggio per sbloccare questa essenza.', 35435),
(79507, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza della reputazione di Nazjatar su un altro personaggio per sbloccare questa essenza.', 35435),
(79517, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza della reputazione di Nazjatar su un altro personaggio per sbloccare questa essenza.', 35435),
(79520, 'itIT', 'Apprendi il Grado 3 di una qualunque essenza delle Visioni Orripilanti su un altro personaggio per sbloccare questa essenza.', 35435);

DELETE FROM `map_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(2268, 'itIT', 'Città di Meccagon', '', '', '', '', 35435);

DELETE FROM `wmo_area_table_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `wmo_area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(103067, 'itIT', 'Meccagon', 35435);

DELETE FROM `achievement_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14260, 'itIT', '', '', '', 35435),
(14251, 'itIT', '', '', '', 35435),
(14256, 'itIT', '', '', '', 35435),
(14263, 'itIT', '', '', '', 35435),
(14250, 'itIT', '', '', '', 35435),
(14241, 'itIT', '', '', '', 35435),
(14246, 'itIT', '', '', '', 35435),
(14244, 'itIT', '', '', '', 35435),
(14264, 'itIT', '', '', '', 35435),
(6980, 'itIT', 'Entra in possesso di quattro Globi del Potere e uccidi quattro nemici che sono in possesso di un Globo del Potere in una singola battaglia al Tempio di Kotmogu.', 'Stella del Tempio di Kotmogu', '', 35435),
(14258, 'itIT', '', '', '', 35435),
(14249, 'itIT', '', '', '', 35435),
(14254, 'itIT', '', '', '', 35435),
(14252, 'itIT', '', '', '', 35435),
(14212, 'itIT', '', '<Hidden> 8.3 Main Line - Account Has Obtained Legendary Cloak (DNT)', '', 35435),
(14245, 'itIT', '', '', '', 35435),
(14242, 'itIT', '', '', '', 35435),
(14257, 'itIT', '', '', '', 35435),
(14255, 'itIT', '', '', '', 35435),
(14248, 'itIT', '', '', '', 35435),
(14259, 'itIT', '', '', '', 35435),
(14261, 'itIT', '', '', '', 35435),
(14265, 'itIT', '', '', '', 35435),
(14247, 'itIT', '', '', '', 35435),
(14240, 'itIT', '', '', '', 35435),
(14238, 'itIT', '', 'Azerite Essence - Rank 3 on any character - Azeroth\'s Undying Gift <DND>', '', 35435),
(14253, 'itIT', '', '', '', 35435),
(14262, 'itIT', '', '', '', 35435),
(14239, 'itIT', '', '', '', 35435),
(14243, 'itIT', '', '', '', 35435);

DELETE FROM `mail_template_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `mail_template_locale` (`ID`, `locale`, `Body_lang`, `VerifiedBuild`) VALUES
(550, 'itIT', 'Per riattivare il tuo account usando l\'oro di gioco, abbiamo prelevato dell\'oro non riscattato nella tua casella di posta. Per questo motivo, potresti notare meno oro del previsto nella posta, ma non preoccuparti: niente è andato perso.\nGrazie e bentornato su Azeroth!\n- Il team di sviluppo di WoW', 35435);

DELETE FROM `dungeon_encounter_locale` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `dungeon_encounter_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(786, 'itIT', 'Gran Sacerdotessa Mar\'li', 35435);


DELETE FROM `hotfix_blob` WHERE `locale` = 'itIT' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(3386943305, 195997, 'itIT', 0x0778781000B20200000400081000000000000000000000000000000001000000000000000097A80200, 35435), -- CreatureDifficulty
(600565378, 267260, 'itIT', 0xE56501000000803F6666A63F0093A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267271, 'itIT', 0xB46501000000803F0000803F009BA80200, 35435), -- CreatureXDisplayInfo
(3386291891, 174231, 'itIT', 0x4D69726D69646F6E65205A616E6A276972000000000007000000E56501000000000000000000000000000000803F0000803F0000803F0000803F879402000000000000000000, 35435), -- Creature
(600565378, 267266, 'itIT', 0xE56501000000803F6666A63F0097A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267274, 'itIT', 0xEA6501000000803F9A99993F009EA80200, 35435), -- CreatureXDisplayInfo
(813076512, 22908, 'itIT', 0x760000002B2F0300, 35435), -- SpellLabel
(813076512, 22909, 'itIT', 0x240100002B2F0300, 35435), -- SpellLabel
(3776013982, 324874, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C634646464646464646456C757369766F7C720D0A24407370656C6C646573633331353630390000, 35435), -- Spell
(3776013982, 324905, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374617A696F6E652064656C20437265707573636F6C6F7C720D0A24407370656C6C646573633331383237360000, 35435), -- Spell
(3776013982, 324865, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C634646464646464646566572736174696C657C720D0A24407370656C6C646573633331353535330000, 35435), -- Spell
(3776013982, 335149, 'itIT', 0x0041756D656E7461206C61207265707574617A696F6E65206469205772617468206F6620746865204C696368204B696E67206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692064656C20247331252E0D0A007C6346463030414139394576656E746F20626F6E75733A20566961676769206E656C2054656D706F206469205772617468206F6620746865204C696368204B696E677C720D0A0D0A5265707574617A696F6E65206469205772617468206F6620746865204C696368204B696E67206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692061756D656E746174612064656C20247331252E00, 35435), -- Spell
(3776013982, 324856, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646416D706C69666963617A696F6E657C720D0A24407370656C6C646573633331353238310000, 35435), -- Spell
(3776013982, 324896, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646496D70756C736F20646920436F7273617C720D0A24407370656C6C646573633331383236360000, 35435), -- Spell
(3776013982, 321714, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324897, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646496D70756C736F20646920436F7273617C720D0A24407370656C6C646573633331383439320000, 35435), -- Spell
(2230237587, 1188, 'itIT', 0x43697474C3A0206469204D65636361676F6E0096010000250600000000000000, 35435), -- UiMapGroupMember
(3776013982, 324857, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646416D706C69666963617A696F6E657C720D0A24407370656C6C646573633331353237370000, 35435), -- Spell
(3776013982, 324895, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C634646464646464646456C757369766F7C720D0A24407370656C6C646573633331353630370000, 35435), -- Spell
(3776013982, 115546, 'itIT', 0x0050726F766F636120696C206265727361676C696F2065206C6F206F62626C6967612061206D756F766572736920766572736F2064692074652C2061756D656E74616E646F6E65206C612076656C6F636974C3A0206469206D6F76696D656E746F2064656C20243131363138396D33252E243F733131353331355B0D0A0D0A4C276162696C6974C3A0207075C3B22065737365726520696E646972697A7A6174612073756C6C61205374617475612064656C6C6F2059616B204E65726F2C2070726F766F63616E646F206C6F2073746573736F206566666574746F2073752074757474692069206E656D69636920656E74726F20243131383633354131206D2064616C6C61207374617475612E5D5B5D0000, 35435), -- Spell
(3776013982, 324848, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C63464646464646464656756F746F20526965636865676769616E74657C720D0A24407370656C6C646573633331383438350000, 35435), -- Spell
(3776013982, 324837, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496D7065746F204C6574616C657C720D0A24407370656C6C646573633331383439330000, 35435), -- Spell
(3776013982, 324868, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646464372697469636974C3A07C720D0A24407370656C6C646573633331353535370000, 35435), -- Spell
(3776013982, 324877, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C634646464646464646456C757369766F7C720D0A24407370656C6C646573633331353539300000, 35435), -- Spell
(3205218938, 41793, 'itIT', 0x4755494C445F46494E4445525F504F5354494E475F45585049524544004C27616E6E756E63696F20696E2054726F766120756E612067696C646120C3A8207363616475746F210001, 35435), -- GlobalStrings
(3776013982, 337612, 'itIT', 0x004E277A6F746820726976656E64696361206C612074756120657373656E7A612C20696E666C696767656E646F2064616E6E69207061726920616C20247331252064656C6C61207475612073616C757465206D617373696D61206F676E69202474312073206D656E7472652073656920696E20636F6D62617474696D656E746F2E204C612066696E6520C3A820766963696E612E0044616E6E69207061726920616C20247731252064656C6C612073616C757465206D617373696D6120737562697469206F676E69202474312073206D656E74726520736920C3A820696E20636F6D62617474696D656E746F2E00, 35435), -- Spell
(3776013982, 292579, 'itIT', 0x000000, 35435), -- Spell
(2230237587, 1162, 'itIT', 0x4D65636361676F6E008F010000D90500000400000000, 35435), -- UiMapGroupMember
(2035710060, 7072, 'itIT', 0x5370697269746F204C6F612041646F6D627261746F004C61204772616E205361636572646F7465737361204D6172276C692075736120717565737461206162696C6974C3A0207175616E646F20C3A820706F737365647574612064616C6C6F205370697269746F2064692047617261276A616C2E0D0A0D0A4C61204772616E205361636572646F7465737361204D6172276C692065766F636120756E6F205370697269746F204C6F612041646F6D627261746F2E204C6F207370697269746F207072656E6465206469206D69726120756E20706572736F6E616767696F2063617375616C652065206C6F20696E7365677565207065722024313337333935642C207563636964656E646F6C6F20616C6C27697374616E7465207365206172726976612061206D656E6F20646920243133373339304131206D2064692064697374616E7A612E0D0A0D0A536520646F706F202431333733393564206C6F207370697269746F20C3A820616E636F7261207669766F2C2073616C746120697374616E74616E65616D656E74652073756C2073756F206265727361676C696F2065206C6F207563636964652E0030031C8A1B0000A11B02000000000000000000000000DFA209000200320013, 35435), -- JournalEncounterSection
(3776013982, 300798, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324866, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646464372697469636974C3A07C720D0A24407370656C6C646573633331353535340000, 35435), -- Spell
(3776013982, 324875, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C634646464646464646456C757369766F7C720D0A24407370656C6C646573633331353630380000, 35435), -- Spell
(3776013982, 256134, 'itIT', 0x00526964756365207369676E6966696361746976616D656E74652069206D6174657269616C69206E6563657373617269207065722063726561726520756E204D6F746F7265205375706572636172696361746F2E0000, 35435), -- Spell
(3776013982, 324898, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C634646464646464646496D70756C736F20646920436F7273617C720D0A24407370656C6C646573633331383439360000, 35435), -- Spell
(3776013982, 324889, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C6346464646464646465374656C6C6520496E66696E6974657C720D0A24407370656C6C646573633331383237340000, 35435), -- Spell
(3776013982, 324907, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374617A696F6E652064656C20437265707573636F6C6F7C720D0A24407370656C6C646573633331383437380000, 35435), -- Spell
(3776013982, 335150, 'itIT', 0x0041756D656E7461206C61207265707574617A696F6E652064692043617461636C79736D206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692064656C20247331252E0D0A007C6346463030414139394576656E746F20626F6E75733A20566961676769206E656C2054656D706F2064692043617461636C79736D7C720D0A0D0A5265707574617A696F6E652064692043617461636C79736D206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692061756D656E746174612064656C20247331252E00, 35435), -- Spell
(3776013982, 321428, 'itIT', 0x00496E666C69676765202473312064616E6E69206461206F6D6272612061207475747469206920706572736F6E61676769206F676E692024743120732E002473312064616E6E69206461206F6D62726120696E666C69747469206F676E692024743120732E00, 35435), -- Spell
(2035710060, 7071, 'itIT', 0x49726120646569204C6F61004C61204772616E205361636572646F7465737361204D6172276C692075736120717565737461206162696C6974C3A0207175616E646F20C3A820706F737365647574612064616C6C6F205370697269746F2064692047617261276A616C2E0D0A0D0A4C61204772616E205361636572646F7465737361204D6172276C6920636F6C706973636520756E20706572736F6E616767696F20636F6E2049726120646569204C6F612C20696E666C696767656E646F202431333733343773312064616E6E69206461206F6D6272612E0030031B8A1B0000A01B02000000000000000000000000BC62090000004000FF, 35435), -- JournalEncounterSection
(3776013982, 324858, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C657C720D0A24407370656C6C646573633331353533310000, 35435), -- Spell
(3776013982, 306259, 'itIT', 0x000000, 35435), -- Spell
(2901650891, 1582, 'itIT', 0x4772616E205361636572646F7465737361204D6172276C6900002E060000300372BA0000000000000309000000, 35435), -- JournalEncounterCreature
(3776013982, 335152, 'itIT', 0x0041756D656E7461206C61207265707574617A696F6E65206469205761726C6F726473206F6620447261656E6F72206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692064656C20247331252E0D0A007C6346463030414139394576656E746F20626F6E75733A20566961676769206E656C2054656D706F206469205761726C6F726473206F6620447261656E6F727C720D0A0D0A5265707574617A696F6E65206469205761726C6F726473206F6620447261656E6F72206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692061756D656E746174612064656C20247331252E00, 35435), -- Spell
(3776013982, 324880, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464650726F7363697567616D656E746F7C720D0A24407370656C6C646573633331353539320000, 35435), -- Spell
(3776013982, 256133, 'itIT', 0x005269647563652069206D6174657269616C69206E6563657373617269207065722063726561726520756E204D6F746F7265205375706572636172696361746F2E0000, 35435), -- Spell
(3776013982, 324879, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464650726F7363697567616D656E746F7C720D0A24407370656C6C646573633331353539310000, 35435), -- Spell
(3776013982, 335151, 'itIT', 0x0041756D656E7461206C61207265707574617A696F6E65206469204D69737473206F662050616E6461726961206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692064656C20247331252E0D0A007C6346463030414139394576656E746F20626F6E75733A20566961676769206E656C2054656D706F206469204D69737473206F662050616E64617269617C720D0A0D0A5265707574617A696F6E65206469204D69737473206F662050616E6461726961206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692061756D656E746174612064656C20247331252E00, 35435), -- Spell
(3776013982, 300748, 'itIT', 0x000000, 35435), -- Spell
(20077728, 396607, 'itIT', 0x000001000000474302000001006FD6, 35435), -- QuestObjective
(3205218938, 42497, 'itIT', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F5449544C450053656920737461746F2070726F6D6F73736F2061204361706F67727570706F7C54496E746572666163655C5C47726F75704672616D655C5C55492D47726F75702D4C656164657249636F6E3A303A303A303A2D317C74207C6E7C6E7C63666666666432303056756F692072696D65747465726520696E206C6973746120696C2067727570706F3A7C727C6E25737C6E0001, 35435), -- GlobalStrings
(3776013982, 324861, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C657C720D0A24407370656C6C646573633331353532390000, 35435), -- Spell
(3776013982, 328136, 'itIT', 0x0041756D656E7461206C61207265707574617A696F6E65206F7474656E7574612061204B756C2054697261732C2049736F6C652044697370657273652C2041726775732C205A616E64616C61722065204E617A6A617461722064656C20247331252E005265707574617A696F6E65206F7474656E7574612061204B756C2054697261732C2049736F6C652044697370657273652C2041726775732C205A616E64616C61722065204E617A6A617461722061756D656E746174612064656C20247331252E00, 35435), -- Spell
(3776013982, 325947, 'itIT', 0x0024407370656C6C646573633239363832300000, 35435), -- Spell
(3776013982, 294479, 'itIT', 0x0000416C6C612072696365726361206469206D616E75666174746920616E74696368692E00, 35435), -- Spell
(3776013982, 155346, 'itIT', 0x0054692074726173666F726D6120706572696F646963616D656E746520696E20756E207669676F726F736F204F6772652064692046756F636F67656C6F2C2061756D656E74616E646F206C6120726573697374656E7A61206120747574746920676C6920656666657474692064616E6E6F73692064656C20243135353333377332252E0054692074726173666F726D6120706572696F646963616D656E746520696E20756E207669676F726F736F204F6772652064692046756F636F67656C6F2C2061756D656E74616E646F206C6120726573697374656E7A61206120747574746920676C6920656666657474692064616E6E6F73692064656C20243135353333377332252E00, 35435), -- Spell
(3776013982, 321201, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324680, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496D7065746F204C6574616C657C720D0A24407370656C6C646573633331383236380000, 35435), -- Spell
(3776013982, 324903, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C6346464646464646465665726974C3A020496E6566666162696C657C720D0A24407370656C6C646573633331383330330000, 35435), -- Spell
(3205218938, 42500, 'itIT', 0x47524F55505F46494E4445525F4445534C4953545F5741524E494E475F454449545F4C495354494E47004D6F646966696361204C697374610001, 35435), -- GlobalStrings
(3776013982, 313040, 'itIT', 0x004372656120756E6F20737175617263696F206E656C207465737375746F2064656C6C61207265616C74C3A02C20636F6E73756D616E646F202433313330343073322053616E6974C3A0204D656E74616C65206520696E666C696767656E646F202433313330343073312064616E6E69206461206F6D62726120612074757474692069206E656D6963692E0D0A0D0A4C6F20737175617263696F20637265612024407370656C6C6E616D65333137363237207065722024333137363334442E0000, 35435), -- Spell
(3205218938, 42645, 'itIT', 0x424E45545F4552524F525F34303031310028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C0002, 35435), -- GlobalStrings
(3776013982, 294003, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324899, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E746520436F6E63656E74726174617C720D0A24407370656C6C646573633331383236390000, 35435), -- Spell
(3776013982, 324850, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C63464646464646464656756F746F20526965636865676769616E74657C720D0A24407370656C6C646573633331383238300000, 35435), -- Spell
(3776013982, 324860, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C657C720D0A24407370656C6C646573633331353533300000, 35435), -- Spell
(3776013982, 324882, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C652064656C2056756F746F7C720D0A24407370656C6C646573633331383238360000, 35435), -- Spell
(3776013982, 321748, 'itIT', 0x00436F737472696E676520696C206265727361676C696F20636F7272656E7465206120636C6F6E617265206C27696E63616E7461746F72652E0000, 35435), -- Spell
(3776013982, 324891, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C6346464646464646465374656C6C6520496E66696E6974657C720D0A24407370656C6C646573633331383438380000, 35435), -- Spell
(3776013982, 325946, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 331973, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 154253, 'itIT', 0x00556E204C75706F204269616E636F207075C3B2206769756E6765726520696E20736F63636F72736F206465692063616D70696F6E692064656C20436C616E204C757069204269616E6368692E00556E204C75706F204269616E636F207075C3B2206769756E6765726520696E20736F63636F72736F206465692063616D70696F6E692064656C20436C616E204C757069204269616E6368692E00, 35435), -- Spell
(3776013982, 324904, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C6346464646464646465665726974C3A020496E6566666162696C657C720D0A24407370656C6C646573633331383438340000, 35435), -- Spell
(3776013982, 321200, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324864, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C634646464646464646566572736174696C657C720D0A24407370656C6C646573633331353535320000, 35435), -- Spell
(3776013982, 316661, 'itIT', 0x0024407370656C6C646573633331363635310000, 35435), -- Spell
(3776013982, 275496, 'itIT', 0x0047697564697A696F20696E666C696767652064616E6E692061676769756E74697669207175616E646F206C61207475612070657263656E7475616C652064692073616C75746520C3A8207069C3B920616C7461206469207175656C6C612064656C206265727361676C696F2C2066696E6F206120756E206D617373696D6F206469202473312064616E6E692E0000, 35435), -- Spell
(3776013982, 324902, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F49726F6E4D616964656E735F436F72727570746564426C6F6F642E626C703A32347C74207C634646464646464646466572697461205A616D70696C6C616E74657C720D0A24407370656C6C646573633331383237320000, 35435), -- Spell
(3776013982, 155334, 'itIT', 0x0053656920696E2061726D6F6E696120636F6E20696C20676869616363696F2064656C6C6120726567696F6E652E204C61207475612070726573656E7A612074616C766F6C746120636F6E67656C612069206E656D6963692E004C61207475612070726573656E7A612074616C766F6C746120636F6E67656C612069206E656D6963692E00, 35435), -- Spell
(3776013982, 324870, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646464372697469636974C3A07C720D0A24407370656C6C646573633331353535380000, 35435), -- Spell
(3776013982, 311204, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 293072, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 302166, 'itIT', 0x00496C20436163636961746F726520417373617373696E6F206661206172726976617265206465692072696E666F727A69206461204D65636361676F6E2E0000, 35435), -- Spell
(3776013982, 264663, 'itIT', 0x4665726F63696120285061737369766F290041756D656E746120696C207269746F726E6F20766974616C652074756F20652064656C2074756F2066616D69676C696F2064656C20247331252E005269746F726E6F20766974616C652061756D656E7461746F2064656C20247732252E00, 35435), -- Spell
(3776013982, 324839, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496D7065746F204C6574616C657C720D0A24407370656C6C646573633331383439370000, 35435), -- Spell
(3776013982, 327254, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 315958, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 335148, 'itIT', 0x0041756D656E7461206C61207265707574617A696F6E65206469204275726E696E672043727573616465206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692064656C20247331252E0D0A007C6346463030414139394576656E746F20626F6E75733A20566961676769206E656C2054656D706F206469204275726E696E6720437275736164657C720D0A0D0A5265707574617A696F6E65206469204275726E696E672043727573616465206775616461676E61746120696E20636F6D62617474696D656E746F206520636F6D706C6574616E646F206C65206D697373696F6E692061756D656E746174612064656C20247331252E00, 35435), -- Spell
(3776013982, 335642, 'itIT', 0x00537472696B65732074686520656E656D7920666F72202473312520776561706F6E2064616D61676520617320536861646F772C20616E6420696E637265617365732064616D616765206465616C74206279202473322520666F722024642E0044616D61676520696E63726561736564206279202473322500, 35435), -- Spell
(3776013982, 155344, 'itIT', 0x00526963657669206C612062656E6564697A696F6E65206465692076656E74692064656C6C61204C616E64612064692046756F636F67656C6F2C2063686520666F726E6973636520756E612070726F626162696C6974C3A02064692072696365766572652046757269612064656C6C612042757272617363612C2061756D656E74616E646F2064656C2031303025206C612063656C65726974C3A02065206F7474656E656E646F204C65766974617A696F6E652E0050726F626162696C6974C3A0206469207269636576657265206C276566666574746F2046757269612064656C6C612042757272617363612C2061756D656E74616E646F2064656C2031303025206C612063656C65726974C3A02065206F7474656E656E646F204C65766974617A696F6E652E00, 35435), -- Spell
(3205218938, 41792, 'itIT', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952455F534F4F4E0053636164656E7A612064656C6C27616E6E756E63696F20696E2054726F766120756E6120636F6D756E6974C3A0207472613A0001, 35435), -- GlobalStrings
(3776013982, 324885, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C652064656C2056756F746F7C720D0A24407370656C6C646573633331383438300D0A0000, 35435), -- Spell
(3776013982, 300692, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 274909, 'itIT', 0x0043616C63696F2064656C20536F6C65204E617363656E7465206375726120747574746920676C6920616C6C6561746920636F6E20756E2074756F206566666574746F206469204E65626269612043757261746976612C204E6562626961204176766F6C67656E7465206F20466F6E74652064656C6C27457373656E7A612061747469766F206469202432373439313273312065206E6520657374656E6465206C61206475726174612064692024733120732C2066696E6F206120756E206D617373696D6F2064656C20247332252064656C6C612073756120647572617461206F726967696E616C652E0000, 35435), -- Spell
(2035710060, 7050, 'itIT', 0x4772616E205361636572646F7465737361204D6172276C69000030031800009D1B00000172BA000000000000000000000000000001000000FF, 35435), -- JournalEncounterSection
(3776013982, 120679, 'itIT', 0x0045766F636120756E6120706F74656E7465206265737469612073656C76616767696120636865206174746163636120696C206265727361676C696F20652072756767697363652C2061756D656E74616E646F206C61207475612063656C65726974C3A02064656C2024323831303336733125207065722024642E0000, 35435), -- Spell
(3776013982, 293777, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324854, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646416D706C69666963617A696F6E657C720D0A24407370656C6C646573633331353238320000, 35435), -- Spell
(3776013982, 324893, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6974C3A0204372657363656E74657C720D0A24407370656C6C646573633331383439350000, 35435), -- Spell
(3776013982, 324884, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C652064656C2056756F746F7C720D0A24407370656C6C646573633331383437390000, 35435), -- Spell
(3776013982, 324853, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C634646464646464646457370656469656E74657C720D0A24407370656C6C646573633331353534340000, 35435), -- Spell
(3776013982, 291435, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 155333, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 300932, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324862, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C634646464646464646566572736174696C657C720D0A24407370656C6C646573633331353534390000, 35435), -- Spell
(3205218938, 42496, 'itIT', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F53554254455854007C6E257320616C6C612072696D6F7A696F6E65206175746F6D61746963610001, 35435), -- GlobalStrings
(3776013982, 110556, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 154274, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324851, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C634646464646464646457370656469656E74657C720D0A24407370656C6C646573633331353534360000, 35435), -- Spell
(3776013982, 155347, 'itIT', 0x0053656920696E6675736F2064656C6C6F207370697269746F2064656C206C75706F2C206368652061756D656E7461206C612076656C6F636974C3A0206469206D6F76696D656E746F2064656C2024313534323539733125207175616E646F207365692066756F72692064616C20636F6D62617474696D656E746F206E656C6C61204C616E64612064692046756F636F67656C6F2E0056656C6F636974C3A0206469206D6F76696D656E746F2061756D656E746174612064656C2024313534323539733125207175616E646F20736920C3A82066756F72692064616C20636F6D62617474696D656E746F2E00, 35435), -- Spell
(3776013982, 301683, 'itIT', 0x0053636174656E6120756E276F6E6461746120646920627269766964692076656C656E6F73692073756C6C6120706F73697A696F6E652064656C206E656D69636F2C20696E666C696767656E646F202473312064616E6E6920612074757474692069206E656D69636920656E74726F2035206D2E0000, 35435), -- Spell
(3776013982, 337816, 'itIT', 0x0024407370656C6C646573633333373631320000, 35435), -- Spell
(3776013982, 324881, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5741524C4F434B5F534F554C535741502E424C503A32347C74207C6346464646464646464261726C756D65206469204C756369646974C3A07C720D0A24407370656C6C646573633331383233390000, 35435), -- Spell
(3776013982, 324890, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C6346464646464646465374656C6C6520496E66696E6974657C720D0A24407370656C6C646573633331383438370000, 35435), -- Spell
(3776013982, 324886, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646417070656E6469636520446973746F7274617C720D0A24407370656C6C646573633331383438310000, 35435), -- Spell
(3745449290, 6134, 'itIT', 0x4D65636361676F6E0000F61700008E1F2444E4C4BB431233A4C300000000000000007E1A000084110000C5EC000003000000D9050000310800000000000000000000, 35435), -- AreaPOI
(3776013982, 324888, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646417070656E6469636520446973746F7274617C720D0A24407370656C6C646573633331383438330000, 35435), -- Spell
(3776013982, 324894, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6974C3A0204372657363656E74657C720D0A24407370656C6C646573633331383439390000, 35435), -- Spell
(2035710060, 7070, 'itIT', 0x5370697269746F204C6F612042656E65646574746F004C61204772616E205361636572646F7465737361204D6172276C692065766F636120756E6F205370697269746F204C6F612042656E65646574746F2E204C6F207370697269746F207369206D756F766520766572736F206C27616C6C6561746F206469204D6172276C6920636F6E206D696E6F72652073616C7574652065206C6F20637572612064656C20243133373330337331252064656C6C61207375612073616C757465206D617373696D612C207365206E6F6E207669656E652075636369736F207072696D61206469207261676769756E6765726C6F2E0D0A0D0A536520646F706F202431333732383764206C6F207370697269746F20C3A820616E636F7261207669766F2C2073616C746120697374616E74616E65616D656E74652073756C2073756F206265727361676C696F2065206C6F20637572612064656C20243133373330337331252064656C6C61207375612073616C757465206D617373696D612E0030031A8A1B00009F1B02000000000000000000000000C231080000002200FF, 35435), -- JournalEncounterSection
(3776013982, 155315, 'itIT', 0x0053656920696E2061726D6F6E696120636F6E20696C2066756F636F2064656C6C6120726567696F6E652E20556E6120636F6C6F6E6E61206469206C6176612073692073636174656E612074616C766F6C746120736F74746F2069207069656469206465692074756F69206E656D6963692E00556E6120636F6C6F6E6E61206469206C6176612073692073636174656E612074616C766F6C746120736F74746F2069207069656469206465692074756F69206E656D6963692E00, 35435), -- Spell
(3776013982, 301578, 'itIT', 0x000000, 35435), -- Spell
(2035710060, 7073, 'itIT', 0x4661746F20446973746F72746F004C61204772616E205361636572646F7465737361204D6172276C692075736120717565737461206162696C6974C3A0207175616E646F20C3A820706F737365647574612064616C6C6F205370697269746F2064692047617261276A616C2E0D0A0D0A4C61204772616E205361636572646F7465737361204D6172276C692073747261707061206C6520616E696D652064692064756520706572736F6E616767692063617375616C692065206C652076696E636F6C61206C27756E6120616C6C27616C7472612E20456E7472616D6265206C6520616E696D652073692063657263616E6F2C20696E666C696767656E646F202431333739373273312064616E6E69206461206F6D6272612061207475747469206920706572736F6E61676769206F676E692024313337393735743120732E20492064616E6E69206469204661746F20446973746F72746F2073692072696475636F6E6F20616C6C2761756D656E746172652064656C6C612064697374616E7A6120747261206C652064756520616E696D652E0D0A0D0A5175616E646F20756E27616E696D61206D756F72652C2072657363696E64656E646F20696C2076696E636F6C6F20636F6E206C27616C7472612C206C27616E696D612072696D6173746120696E697A6961206120696E666C696767657265202431333739383673312064616E6E69206461206F6D627261206F676E692024313337393836743220732E0030031D8A1B00000000020000000000000000000000009B07070002001A000C, 35435), -- JournalEncounterSection
(3776013982, 155345, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 332950, 'itIT', 0x00004C65206162696C6974C3A02068616E6E6F20756E612070726F626162696C6974C3A020646920696E666C6967676572652024403930353773312064616E6E692E00, 35435), -- Spell
(3776013982, 324901, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E746520436F6E63656E74726174617C720D0A24407370656C6C646573633331383439380000, 35435), -- Spell
(3776013982, 324892, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6974C3A0204372657363656E74657C720D0A24407370656C6C646573633331383237300000, 35435), -- Spell
(3776013982, 324852, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C634646464646464646457370656469656E74657C720D0A24407370656C6C646573633331353534350000, 35435), -- Spell
(3776013982, 299937, 'itIT', 0x00496C20436163636961746F726520417373617373696E6F206661206172726976617265206465692072696E666F727A69206461204D65636361676F6E2E0000, 35435), -- Spell
(3776013982, 296464, 'itIT', 0x004C27556E6974C3A0206469204F707072657373696F6E6520416572656120484B2D38206661206172726976617265206465692072696E666F727A69206461204D65636361676F6E2E0000, 35435), -- Spell
(3205218938, 42646, 'itIT', 0x424E45545F4552524F525F34303031320028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C202832290002, 35435), -- GlobalStrings
(3776013982, 324900, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E746520436F6E63656E74726174617C720D0A24407370656C6C646573633331383439340000, 35435), -- Spell
(3776013982, 292907, 'itIT', 0x004C616E63696120756E6120736368656767696120646920676869616363696F20636F6E74726F20696C206265727361676C696F2C20696E666C696767656E646F2064616E6E6920666973696369207061726920616C20247331252064656C6C612073616C757465206D617373696D612E0000, 35435), -- Spell
(3776013982, 324887, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C634646464646464646417070656E6469636520446973746F7274617C720D0A24407370656C6C646573633331383438320000, 35435), -- Spell
(3205218938, 41794, 'itIT', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F45585049524544004C27616E6E756E63696F20696E2054726F766120756E6120636F6D756E6974C3A020C3A8207363616475746F210001, 35435), -- GlobalStrings
(3776013982, 319451, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 154275, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 155313, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 154259, 'itIT', 0x004C6F207370697269746F2064656C206C75706F20C3A82064656E74726F20646920746520652061756D656E7461206C61207475612076656C6F636974C3A0206469206D6F76696D656E746F2064656C20733125206E656C6C61204C616E64612064692046756F636F67656C6F2E0056656C6F636974C3A0206469206D6F76696D656E746F2061756D656E746174612064656C2024733125206E656C6C61204C616E64612064692046756F636F67656C6F2E00, 35435), -- Spell
(3205218938, 41791, 'itIT', 0x4755494C445F46494E4445525F504F5354494E475F474F494E475F544F5F4558504952450053636164656E7A612064656C6C27616E6E756E63696F20696E2054726F766120756E612067696C6461207472613A0001, 35435), -- GlobalStrings
(3776013982, 304086, 'itIT', 0x457373656E7A61206427417A65726974650046696E6368C3A920736920C3A82073746F72646974692C20696C2062656E65666963696F20646966656E7369766F20666F726E69746F2064616C6C6120766572736174696C6974C3A020C3A82061756D656E7461746F2064656C20243330343737357331252E0000, 35435), -- Spell
(3776013982, 324845, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C63464646464646464656756F746F20526965636865676769616E74657C720D0A24407370656C6C646573633331383438360000, 35435), -- Spell
(3776013982, 155343, 'itIT', 0x000000, 35435), -- Spell
(3776013982, 324906, 'itIT', 0x00496E666F6E646520756E206F67676574746F20636F6E20756E2765636F206D616C69676E612064656C6C6120636F7272757A696F6E65206469204E277A6F74682E0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374617A696F6E652064656C20437265707573636F6C6F7C720D0A24407370656C6C646573633331383437370000, 35435), -- Spell
(2035710060, 7069, 'itIT', 0x49726120646569204C6F61004C61204772616E205361636572646F7465737361204D6172276C6920636F6C706973636520756E20706572736F6E616767696F20636F6E2049726120646569204C6F612C20696E666C696767656E646F202431333733343473312064616E6E6920646120736163726F2E003003198A1B00009E1B020000000000000000000000002413020000004000FF, 35435), -- JournalEncounterSection
(2948698321, 249, 'itIT', 0xD6968DCA7ACF9DD1, 35435), -- TactKeyLookup
(2948698321, 259, 'itIT', 0xB50278B84158ABDF, 35435), -- TactKeyLookup
(603412935, 28663, 'itIT', 0x3130E9878CE5B1B1E8B7AFE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28664, 'itIT', 0xE6899BE9BAA6E9838E0004, 35435), -- ChatProfanity
(603412935, 28644, 'itIT', 0xE689A9E998B4E599A80004, 35435), -- ChatProfanity
(603412935, 28652, 'itIT', 0xE5A3B9E59C8BE585A9E8A3BD0004, 35435), -- ChatProfanity
(603412935, 28656, 'itIT', 0xE99988E696B9E5AE89E7949F0004, 35435), -- ChatProfanity
(603412935, 28653, 'itIT', 0xE994A4E995B0E5B8AE0004, 35435), -- ChatProfanity
(603412935, 28650, 'itIT', 0x4C69626572617465484B0004, 35435), -- ChatProfanity
(603412935, 28645, 'itIT', 0xE5BEB7E5AFB8E88C8E0004, 35435), -- ChatProfanity
(603412935, 28648, 'itIT', 0xE99B8FE5A5B30004, 35435), -- ChatProfanity
(603412935, 28658, 'itIT', 0xE794B2E7B49AE688A6E78AAF0004, 35435), -- ChatProfanity
(603412935, 28655, 'itIT', 0xE69C80E9AB98E4BABAE6B0910004, 35435), -- ChatProfanity
(603412935, 28661, 'itIT', 0xE684BFE88DA3E58589E5BD92E9A699E6B8AF0004, 35435), -- ChatProfanity
(603412935, 28649, 'itIT', 0xE6B9BFE7A9B40004, 35435), -- ChatProfanity
(603412935, 28657, 'itIT', 0xE4BD95E4BF8AE4BB810004, 35435), -- ChatProfanity
(603412935, 28647, 'itIT', 0xE99CB2E998B4E9B8A10004, 35435), -- ChatProfanity
(603412935, 28662, 'itIT', 0xE58D81E9878CE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28646, 'itIT', 0xE88C8EE9BE9F0004, 35435), -- ChatProfanity
(603412935, 28651, 'itIT', 0x66726565484B0004, 35435), -- ChatProfanity
(603412935, 28660, 'itIT', 0xE88194E982A6E5AEA3E8A8800004, 35435), -- ChatProfanity
(603412935, 28654, 'itIT', 0xE4BABAE6B091E6A380E5AF9FE999A20004, 35435), -- ChatProfanity
(603412935, 28659, 'itIT', 0xE696B0E4B8ADE59BBDE88194E982A60004, 35435), -- ChatProfanity
(4033975491, 403803, 'itIT', 0x0000704100000000000000410000000000000000000000005B290600308A1300000000000000000000000000000000000000000000000000000000204100000000FFFFFFFFFFFF00000000000000000000000AD50100, 35435), -- SpellVisualKitModelAttach
(4146370265, 91772, 'itIT', 0x0000A0400000000000002041000000000000000000000000000000000000000022130000000000000000000000000000000000000000000000000000000000000000, 35435), -- SpellVisual
(517656225, 6688, 'itIT', 0x0000803F00000000E17AD43F000000000000000100001A00000000000303000000000000000000000000A4707D3F0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFF4742000000000000000000000000000000000000C8430000964300000040FFFFFFFF02038030E13E022B873D0AD7233C636D2400000020400000003F69000000000000000000803F0000803F6E186F180000000000000000000000000000000000000000403F3333B33E6666E63E0000000000000000000000000000000000000000000000000000000000000000000000008D5E1E008C5E1E008C5E1E00, 35435), -- SpellChainEffects
(4033975491, 404117, 'itIT', 0x00000000000000000000C03F000000000000000000000000952A0600D9891300000000000000000000000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000009D50100, 35435), -- SpellVisualKitModelAttach
(1181150530, 307455, 'itIT', 0x020000005B2906000AD50100, 35435), -- SpellVisualKitEffect
(25144992, 2203, 'itIT', 0x201A0000000000000000000001000000CB0100000000000013000000FFFFFFFF0000000000000000, 35435); -- BeamEffect

