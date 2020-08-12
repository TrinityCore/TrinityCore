DELETE FROM `broadcast_text_locale` WHERE `VerifiedBuild`>0 AND `locale` = 'esES' AND `ID` IN (201778, 753, 195400, 79796, 165870, 79799, 79798, 79804, 194274, 183984, 201777, 79794, 79795, 141708, 201784, 165241, 165243, 165245, 165239, 165246, 165244, 165237);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(201778, 'esES', 'Estamos listos. ¡Adelante!', 'Estamos listos. ¡Adelante!', 35435),
(753, 'esES', '¿Qué? ¿Quieres decir que no puedes matarlo tú solo?', '', 35435),
(195400, 'esES', 'Déjame ver tus esencias sintetizadas, por favor.', 'Déjame ver tus esencias sintetizadas, por favor.', 35435),
(79796, 'esES', 'Descubierta piedra de chamán: Tocado por el fuego', 'Descubierta piedra de chamán: Tocado por el fuego', 35435),
(165870, 'esES', '', 'Cuando quierah, te hablaré de la caída de Rahtakhan.', 35435),
(79799, 'esES', 'Descubierta piedra de chamán: Entereza de ogro', 'Descubierta piedra de chamán: Entereza de ogro', 35435),
(79798, 'esES', 'Descubierta piedra de chamán: Vendaval furioso', 'Descubierta piedra de chamán: Vendaval furioso', 35435),
(79804, 'esES', 'Descubierta piedra de chamán: Tocado por el hielo', 'Descubierta piedra de chamán: Tocado por el hielo', 35435),
(194274, 'esES', 'I want to teleport to Operation: Mechagon (Dungeon).', 'I want to teleport to Operation: Mechagon (Dungeon).', 35435),
(183984, 'esES', '|cfff2e699+$1i cordura|r', '|cfff2e699+$1i cordura|r', 35435),
(201777, 'esES', '', 'Conozco una forma de llegar hahta la hija del mar. Seguidme si ehtáih lihtoh.', 35435),
(79794, 'esES', 'Descubierta piedra de chamán: Bendición del lobo', 'Descubierta piedra de chamán: Bendición del lobo', 35435),
(79795, 'esES', 'Descubierta piedra de chamán: Espíritu del lobo', 'Descubierta piedra de chamán: Espíritu del lobo', 35435),
(141708, 'esES', 'Debilita al grifo sin perder el agarre con |TInterface\\ICONS\\INV_MISC_DESECRATED_LEATHERGLOVE.BLP:20|t |cFFFF0000|Hspell:269442|h[Agarrar fuerte]|h|r', '', 35435),
(201784, 'esES', '¡Lo vi con mis propios ojos! ¡Atacaron a lady Jaina en alta mar!', '', 35435),
(165241, 'esES', 'Más profundo, más profundo...', 'Más profundo, más profundo...', 35435),
(165243, 'esES', 'Al fin... Abrazad la verdad de las sombras.', 'Al fin... Abrazad la verdad de las sombras.', 35435),
(165245, 'esES', 'Cada decisión os ata más a mi voluntad.', 'Cada decisión os ata más a mi voluntad.', 35435),
(165239, 'esES', 'Controla tu furia... Usa el odio como arma.', 'Controla tu furia... Usa el odio como arma.', 35435),
(165246, 'esES', 'Esas baratijas no son nada ante la mirada de un dios.', 'Esas baratijas no son nada ante la mirada de un dios.', 35435),
(165244, 'esES', 'Sí... estáis cerca... cada vez más cerca.', 'Sí... estáis cerca... cada vez más cerca.', 35435),
(165237, 'esES', 'Ah... crees que sabes lo que es el poder.', 'Ah... crees que sabes lo que es el poder.', 35435);

DELETE FROM `gameobjects_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `gameobjects_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(341828, 'esES', 'Teletransportador a Ciudad de Mecandria', 35435),
(341363, 'esES', 'Teletransportador a Ciudad de Mecandria', 35435),
(338477, 'esES', 'Teletransportador a Ciudad de Mecandria', 35435);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(87487, 'esES', 'Escudo de reverberación sonora', 35435);

DELETE FROM `azerite_essence_power_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `azerite_essence_power_locale` (`ID`, `locale`, `SourceAlliance_lang`, `SourceHorde_lang`, `VerifiedBuild`) VALUES
(114, 'esES', 'Visiones horripilantes de N\'Zoth|n|cFFFFD200Logro:|r|n\"En la profundidad de las visiones\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Ubicación:|r Cámara del Corazón', '', 35435),
(132, 'esES', 'Visiones horripilantes de N\'Zoth|n|cFFFFD200Logro:|r|n\"En la profundidad de las visiones\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Ubicación:|r Cámara del Corazón', '', 35435),
(140, 'esES', 'Visiones horripilantes de N\'Zoth|n|cFFFFD200Logro:|r|n\"En la profundidad de las visiones\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Ubicación:|r Cámara del Corazón', '', 35435);

DELETE FROM `currency_types_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1803, 'esES', 'Ecos de Ny\'alotha', 'Ahora que ha sido purificada de la corrupción de N\'Zoth, MADRE podrá usar esta substancia para sintetizar esencias en la Cámara del Corazón.', 35435);

DELETE FROM `spell_name_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(324906, 'esES', 'Corrupción - Devastación crepuscular 2', 35435),
(155343, 'esES', 'Shamanstone: Buffeting Galefury', 35435),
(324845, 'esES', 'Corrupción - Vacío resonante 3', 35435),
(304086, 'esES', 'Conflicto', 35435),
(154259, 'esES', 'Piedra de chamán: Espíritu del lobo', 35435),
(155313, 'esES', 'Piedra de chamán: Tocado por el fuego', 35435),
(154275, 'esES', 'Piedra de chamán: Espíritu del lobo', 35435),
(319451, 'esES', 'Teletransporte a Ciudad de Mecandria', 35435),
(324887, 'esES', 'Corrupción - Apéndice retorcido 2', 35435),
(292907, 'esES', 'Fragmento de hielo corrupto', 35435),
(324900, 'esES', 'Corrupción - Mente aguda 2', 35435),
(296464, 'esES', 'Relé de refuerzo', 35435),
(299937, 'esES', 'Relé de refuerzo', 35435),
(324852, 'esES', 'Corrupción - Expeditivo 2', 35435),
(324892, 'esES', 'Corrupción - Vitalidad emergente 1', 35435),
(324901, 'esES', 'Corrupción - Mente aguda 3', 35435),
(332950, 'esES', 'Fire Proc (DNT)', 35435),
(155345, 'esES', 'Piedra de chamán: Entereza de ogro', 35435),
(301578, 'esES', 'REUSE ME', 35435),
(155315, 'esES', 'Piedra de chamán: Tocado por el fuego', 35435),
(324894, 'esES', 'Corrupción - Vitalidad emergente 3', 35435),
(324888, 'esES', 'Corrupción - Apéndice retorcido 3', 35435),
(324886, 'esES', 'Corrupción - Apéndice retorcido 1', 35435),
(324890, 'esES', 'Corrupción - Estrellas del infinito 2', 35435),
(324881, 'esES', 'Corrupción - Atisbo de claridad', 35435),
(337816, 'esES', 'Consecuencias ineludibles', 35435),
(301683, 'esES', 'REUSE ME', 35435),
(155347, 'esES', 'Shamanstone: Spirit of the Wolf', 35435),
(324851, 'esES', 'Corrupción - Expeditivo 3', 35435),
(154274, 'esES', 'Piedra de chamán: Bendición del lobo', 35435),
(110556, 'esES', '[DNT] Force Cast Tried to Fly', 35435),
(324862, 'esES', 'Corrupción - Versátil 1', 35435),
(300932, 'esES', 'REUSE ME [MTMM] (DNT)', 35435),
(155333, 'esES', 'Shamanstone: Touched by Ice', 35435),
(291435, 'esES', 'Poza de cordura', 35435),
(324853, 'esES', 'Corrupción - Expeditivo 1', 35435),
(324884, 'esES', 'Corrupción - Ritual del Vacío 2', 35435),
(324893, 'esES', 'Corrupción - Vitalidad emergente 2', 35435),
(324854, 'esES', 'Corrupción - Golpe penetrante 3', 35435),
(293777, 'esES', 'Fragor de sombra', 35435),
(120679, 'esES', 'Bestia temible', 35435),
(274909, 'esES', 'Niebla naciente', 35435),
(300692, 'esES', 'REUSE ME [MTMM] (DNT)', 35435),
(324885, 'esES', 'Corrupción - Ritual del Vacío 3', 35435),
(155344, 'esES', 'Shamanstone: Buffeting Galefury', 35435),
(335642, 'esES', 'Supergolpe', 35435),
(335148, 'esES', 'Señal de El Vacío Abisal', 35435),
(315958, 'esES', 'Teletransporte a Ciudad de Mecandria', 35435),
(327254, 'esES', 'Amenaza de espora putrefacta', 35435),
(324839, 'esES', 'Corrupción - Inercia mortal 3', 35435),
(264663, 'esES', 'Sed del depredador', 35435),
(302166, 'esES', 'Relé de refuerzo', 35435),
(293072, 'esES', 'Poza de cordura', 35435),
(311204, 'esES', 'Llévame a la Ciudad de Mecandria', 35435),
(324870, 'esES', 'Corrupción - Severo 3', 35435),
(155334, 'esES', 'Shamanstone: Touched by Ice', 35435),
(324902, 'esES', 'Corrupción - Herida sangrante', 35435),
(275496, 'esES', 'Justicia indómita', 35435),
(316661, 'esES', 'Destrucción de obsidiana', 35435),
(324864, 'esES', 'Corrupción - Versátil 2', 35435),
(321200, 'esES', 'Iniciar misión', 35435),
(324904, 'esES', 'Corrupción - Verdad indescriptible 2', 35435),
(154253, 'esES', 'Piedra de chamán: Bendición del lobo', 35435),
(331973, 'esES', '', 35435),
(325946, 'esES', 'Lanzar baba', 35435),
(324891, 'esES', 'Corrupción - Estrellas del infinito 3', 35435),
(321748, 'esES', '¡Clóname!', 35435),
(324882, 'esES', 'Corrupción - Ritual del Vacío 1', 35435),
(324860, 'esES', 'Corrupción - Magistral 2', 35435),
(324850, 'esES', 'Corrupción - Vacío resonante 1', 35435),
(324899, 'esES', 'Corrupción - Mente aguda 1', 35435),
(294003, 'esES', 'Canción del buscador', 35435),
(313040, 'esES', 'Oscuridad infinita', 35435),
(324903, 'esES', 'Corrupción - Verdad indescriptible 1', 35435),
(324680, 'esES', 'Corrupción - Inercia mortal 1', 35435),
(321201, 'esES', 'Iniciar misión', 35435),
(155346, 'esES', 'Piedra de chamán: Entereza de ogro', 35435),
(294479, 'esES', 'Desenterrando', 35435),
(325947, 'esES', 'Lanzar baba', 35435),
(328136, 'esES', 'Influencia impresionante', 35435),
(324861, 'esES', 'Corrupción - Magistral 1', 35435),
(300748, 'esES', 'REUSE ME [MTMM] (DNT)', 35435),
(335151, 'esES', 'Señal de la niebla', 35435),
(324879, 'esES', 'Corrupción - Succionador 2', 35435),
(256133, 'esES', 'REUSE ME [SCS]', 35435),
(324880, 'esES', 'Corrupción - Succionador 3', 35435),
(335152, 'esES', 'Señal del hierro', 35435),
(306259, 'esES', 'Tentáculo', 35435),
(324858, 'esES', 'Corrupción - Magistral 3', 35435),
(321428, 'esES', 'Estrago del infinito', 35435),
(335150, 'esES', 'Señal del Destructor', 35435),
(324907, 'esES', 'Corrupción - Devastación crepuscular 3', 35435),
(324889, 'esES', 'Corrupción - Estrellas del infinito 1', 35435),
(324898, 'esES', 'Corrupción - Pulso acelerado 3', 35435),
(256134, 'esES', 'REUSE ME [SCS]', 35435),
(324875, 'esES', 'Corrupción - Evasivo 2', 35435),
(324866, 'esES', 'Corrupción - Severo 1', 35435),
(300798, 'esES', 'REUSE ME [MTMM] (DNT)', 35435),
(292579, 'esES', 'Hoguera cercana', 35435),
(337612, 'esES', 'Consecuencias ineludibles', 35435),
(324877, 'esES', 'Corrupción - Succionador 1', 35435),
(324868, 'esES', 'Corrupción - Severo 2', 35435),
(324837, 'esES', 'Corrupción - Inercia mortal 2', 35435),
(324848, 'esES', 'Corrupción - Vacío resonante 2', 35435),
(115546, 'esES', 'Burla', 35435),
(324895, 'esES', 'Corrupción - Evasivo 1', 35435),
(324857, 'esES', 'Corrupción - Golpe penetrante 1', 35435),
(324897, 'esES', 'Corrupción - Pulso acelerado 2', 35435),
(321714, 'esES', 'Teletransporte a Silithus', 35435),
(324896, 'esES', 'Corrupción - Pulso acelerado 1', 35435),
(324856, 'esES', 'Corrupción - Golpe penetrante 2', 35435),
(335149, 'esES', 'Señal de la Plaga', 35435),
(324865, 'esES', 'Corrupción - Versátil 3', 35435),
(324905, 'esES', 'Corrupción - Devastación crepuscular 1', 35435),
(324874, 'esES', 'Corrupción - Evasivo 3', 35435);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(85118, 'esES', '', 35435),
(85126, 'esES', '', 35435),
(85114, 'esES', '', 35435),
(85084, 'esES', '', 35435),
(85132, 'esES', '', 35435),
(85098, 'esES', '', 35435),
(85134, 'esES', '', 35435),
(85025, 'esES', 'Costasur contra Molino Tarren', 35435),
(85128, 'esES', '', 35435),
(84755, 'esES', 'Misión de la capa legendaria completada', 35435),
(85090, 'esES', '', 35435),
(85130, 'esES', '', 35435),
(84814, 'esES', 'El jugador Nocheterna cumple los requisitos para la armadura dinástica', 35435),
(85100, 'esES', '', 35435),
(85136, 'esES', '', 35435),
(85102, 'esES', '', 35435),
(85138, 'esES', '', 35435),
(84815, 'esES', 'El jugador orco Mag\'har cumple los requisitos para la armadura dinástica', 35435),
(85108, 'esES', '', 35435),
(85110, 'esES', '', 35435),
(85116, 'esES', '', 35435),
(84812, 'esES', 'El jugador mecagnomo cumple los requisitos para la armadura dinástica', 35435),
(78565, 'esES', 'Diferencial perfectamente sincronizado', 35435),
(34935, 'esES', 'Obtén la bendición de la piedra de chamán: Espíritu del lobo', 35435),
(82623, 'esES', 'Elimina la basura de la Ciudad de Mecandria', 35435),
(84810, 'esES', 'El jugador enano Hierro Negro cumple los requisitos para la armadura dinástica', 35435),
(84809, 'esES', 'El jugador elfo del Vacío cumple los requisitos para la armadura dinástica', 35435),
(85096, 'esES', '', 35435),
(85092, 'esES', '', 35435),
(84816, 'esES', 'El jugador trol Zandalari cumple los requisitos para la armadura dinástica', 35435),
(85122, 'esES', '', 35435),
(84808, 'esES', 'El jugador tauren Monte Alto cumple los requisitos para la armadura dinástica', 35435),
(85120, 'esES', '', 35435),
(85112, 'esES', '', 35435),
(84813, 'esES', 'El jugador vulpera cumple los requisitos para la armadura dinástica', 35435),
(85124, 'esES', '', 35435),
(85088, 'esES', '', 35435),
(85094, 'esES', '', 35435),
(85086, 'esES', '', 35435),
(85106, 'esES', '', 35435),
(84817, 'esES', 'El jugador de Kul Tiras cumple los requisitos para la armadura dinástica', 35435),
(85104, 'esES', '', 35435),
(84811, 'esES', 'El jugador draenei forjado por la Luz cumple los requisitos para la armadura dinástica', 35435);

DELETE FROM `item_name_description_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `item_name_description_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(13566, 'esES', '35 p. de corrupción', 35435),
(13578, 'esES', '16 p. de corrupción', 35435),
(13569, 'esES', '10 p. de corrupción', 35435),
(13574, 'esES', '28 p. de corrupción', 35435),
(13572, 'esES', '25 p. de corrupción', 35435),
(13520, 'esES', '30 p. de corrupción', 35435),
(13579, 'esES', '8 p. de corrupción', 35435),
(13516, 'esES', '5 p. de corrupción', 35435),
(13568, 'esES', '20 p. de corrupción', 35435),
(13521, 'esES', '5-30 p. de corrupción', 35435),
(13576, 'esES', '30 p. de corrupción', 35435),
(13518, 'esES', '15 p. de corrupción', 35435),
(13519, 'esES', '20 p. de corrupción', 35435),
(13577, 'esES', '12 p. de corrupción', 35435),
(13575, 'esES', '17 p. de corrupción', 35435),
(13570, 'esES', '75 p. de corrupción', 35435),
(13565, 'esES', '66 p. de corrupción', 35435),
(13513, 'esES', '25 p. de corrupción', 35435),
(13580, 'esES', '60 p. de corrupción', 35435),
(13517, 'esES', '10 p. de corrupción', 35435),
(13571, 'esES', '50 p. de corrupción', 35435),
(13573, 'esES', '45 p. de corrupción', 35435),
(13567, 'esES', '15 p. de corrupción', 35435);

DELETE FROM `area_table_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12825, 'esES', 'Ciudad de Mecandria', 35435),
(10290, 'esES', 'Mecandria', 35435);

DELETE FROM `ui_map_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `ui_map_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1574, 'esES', 'Ciudad de Mecandria', 35435),
(1573, 'esES', 'Ciudad de Mecandria', 35435);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(177977, 'esES', '', '', '', '', 'Contaminante conservado: Herida sangrante', 35435),
(177997, 'esES', '', '', '', '', 'Contaminante conservado: Succionador', 35435),
(178006, 'esES', '', '', '', '', 'Contaminante conservado: Devastación crepuscular', 35435),
(177974, 'esES', '', '', '', '', 'Contaminante conservado: Expeditivo', 35435),
(177976, 'esES', '', '', '', '', 'Contaminante conservado: Atisbo de claridad', 35435),
(178015, 'esES', '', '', '', '', 'Contaminante conservado: Ritual del Vacío', 35435),
(178012, 'esES', '', '', '', '', 'Contaminante conservado: Versátil', 35435),
(87487, 'esES', '', '', '', '', 'Escudo de reverberación sonora', 35435),
(177983, 'esES', '', '', '', '', 'Contaminante conservado: Estrellas del infinito', 35435),
(177980, 'esES', '', '', '', '', 'Contaminante conservado: Mente aguda', 35435),
(178004, 'esES', '', '', '', '', 'Contaminante conservado: Devastación crepuscular', 35435),
(177987, 'esES', '', '', '', '', 'Contaminante conservado: Magistral', 35435),
(177965, 'esES', '', '', '', '', 'Contaminante conservado: Inercia mortal', 35435),
(177989, 'esES', '', '', '', '', 'Contaminante conservado: Pulso acelerado', 35435),
(177998, 'esES', '', '', '', '', 'Contaminante conservado: Golpe penetrante', 35435),
(178011, 'esES', '', '', '', '', 'Contaminante conservado: Versátil', 35435),
(177993, 'esES', '', '', '', '', 'Contaminante conservado: Severo', 35435),
(177978, 'esES', '', '', '', '', 'Contaminante conservado: Mente aguda', 35435),
(178002, 'esES', '', '', '', '', 'Contaminante conservado: Vitalidad emergente', 35435),
(177967, 'esES', '', '', '', '', 'Contaminante conservado: Vacío resonante', 35435),
(177970, 'esES', '', '', '', '', 'Contaminante conservado: Evasivo', 35435),
(177972, 'esES', '', '', '', '', 'Contaminante conservado: Evasivo', 35435),
(177992, 'esES', '', '', '', '', 'Contaminante conservado: Severo', 35435),
(177985, 'esES', '', '', '', '', 'Contaminante conservado: Estrellas del infinito', 35435),
(177982, 'esES', '', '', '', '', 'Contaminante conservado: Verdad indescriptible', 35435),
(177991, 'esES', '', '', '', '', 'Contaminante conservado: Pulso acelerado', 35435),
(177971, 'esES', '', '', '', '', 'Contaminante conservado: Evasivo', 35435),
(168043, 'esES', 'Codiciado por los amathet, quienes se creen los guardianes de las obras de los titanes.', '', '', '', 'Artefacto titánico', 35435),
(177964, 'esES', '', '', '', '', 'Encantar arma: Multiplicador de fuerza', 35435),
(177986, 'esES', '', '', '', '', 'Contaminante conservado: Magistral', 35435),
(178013, 'esES', '', '', '', '', 'Contaminante conservado: Ritual del Vacío', 35435),
(177994, 'esES', '', '', '', '', 'Contaminante conservado: Severo', 35435),
(178009, 'esES', '', '', '', '', 'Contaminante conservado: Apéndice retorcido', 35435),
(173937, 'esES', 'Mires donde mires, el ojo te devuelve la mirada.', '', '', '', 'Óculo cercenado', 35435),
(177973, 'esES', '', '', '', '', 'Contaminante conservado: Expeditivo', 35435),
(178007, 'esES', '', '', '', '', 'Contaminante conservado: Apéndice retorcido', 35435),
(177981, 'esES', '', '', '', '', 'Contaminante conservado: Verdad indescriptible', 35435),
(178003, 'esES', '', '', '', '', 'Contaminante conservado: Vitalidad emergente', 35435),
(177979, 'esES', '', '', '', '', 'Contaminante conservado: Mente aguda', 35435),
(177966, 'esES', '', '', '', '', 'Contaminante conservado: Inercia mortal', 35435),
(177999, 'esES', '', '', '', '', 'Contaminante conservado: Golpe penetrante', 35435),
(178010, 'esES', '', '', '', '', 'Contaminante conservado: Versátil', 35435),
(177969, 'esES', '', '', '', '', 'Contaminante conservado: Vacío resonante', 35435),
(178000, 'esES', '', '', '', '', 'Contaminante conservado: Golpe penetrante', 35435),
(177975, 'esES', '', '', '', '', 'Contaminante conservado: Expeditivo', 35435),
(178001, 'esES', '', '', '', '', 'Contaminante conservado: Vitalidad emergente', 35435),
(178008, 'esES', '', '', '', '', 'Contaminante conservado: Apéndice retorcido', 35435),
(177995, 'esES', '', '', '', '', 'Contaminante conservado: Succionador', 35435),
(177968, 'esES', '', '', '', '', 'Contaminante conservado: Vacío resonante', 35435),
(177955, 'esES', '', '', '', '', 'Contaminante conservado: Inercia mortal', 35435),
(177988, 'esES', '', '', '', '', 'Contaminante conservado: Magistral', 35435),
(177996, 'esES', '', '', '', '', 'Contaminante conservado: Succionador', 35435),
(177984, 'esES', '', '', '', '', 'Contaminante conservado: Estrellas del infinito', 35435),
(178014, 'esES', '', '', '', '', 'Contaminante conservado: Ritual del Vacío', 35435),
(177990, 'esES', '', '', '', '', 'Contaminante conservado: Pulso acelerado', 35435),
(178005, 'esES', '', '', '', '', 'Contaminante conservado: Devastación crepuscular', 35435),
(141057, 'esES', 'Te enseña a fabricar un glifo de Destello cegador.', '', '', '', 'Técnica: Glifo de Destello cegador', 35435),
(139412, 'esES', '', '', '', '', 'Tortugas de guerra mutantes jóvenes', 35435),
(139345, 'esES', '', '', '', '', 'Manitas de rata', 35435),
(139411, 'esES', '', '', '', '', 'Banquete de Los Bajos Fondos', 35435),
(137826, 'esES', 'Te enseña a fabricar un colgante de rubí sombrío hechicero.', '', '', '', 'Boceto: colgante de rubí sombrío hechicero', 35435),
(138016, 'esES', 'Te enseña a fabricar un cofre de ropa: ciudadanos de Dalaran.', '', '', '', 'Patrón de cofre de ropa: ciudadanos de Dalaran', 35435),
(137932, 'esES', 'Te enseña a fabricar un aro en llamas.', '', '', '', 'Receta: aro en llamas', 35435),
(137954, 'esES', 'Te enseña a fabricar un cincho de filoseda.', '', '', '', 'Patrón: cincho de filoseda', 35435),
(137901, 'esES', 'Te enseña a fabricar una faja de vínculo bélico.', '', '', '', 'Receta: faja de vínculo bélico', 35435),
(137881, 'esES', 'Te enseña a fabricar un cinturón de pellejo de guerra.', '', '', '', 'Receta: cinturón de pellejo de guerra', 35435),
(139344, 'esES', '', '', '', '', 'Plátano de maná', 35435),
(139347, 'esES', '', '', '', '', 'Bajamedusa', 35435),
(137706, 'esES', 'Te enseña a fabricar una carga de pólvora.', '', '', '', 'Esquema: carga de pólvora', 35435),
(137962, 'esES', 'Te enseña a fabricar un cincho de filoseda.', '', '', '', 'Patrón: cincho de filoseda', 35435),
(137829, 'esES', 'Te enseña a fabricar un colgante de rubí sombrío sutil.', '', '', '', 'Boceto: colgante de rubí sombrío sutil', 35435),
(137913, 'esES', 'Te enseña a fabricar una faja de vínculo bélico.', '', '', '', 'Receta: faja de vínculo bélico', 35435),
(137917, 'esES', 'Te enseña a fabricar una faja de escamas grabadas.', '', '', '', 'Receta: faja de escamas grabadas', 35435),
(139431, 'esES', '', '', '', '', 'Cajón de arneses de ratrotón', 35435),
(141065, 'esES', 'Te enseña a fabricar un glifo de Guarda terrorífico.', '', '', '', 'Técnica: Glifo de Guarda terrorífico', 35435),
(137885, 'esES', 'Te enseña a fabricar un cinturón de terrocuero.', '', '', '', 'Receta: cinturón de terrocuero', 35435),
(137869, 'esES', 'Te enseña a fabricar un cinturón de pellejo de guerra.', '', '', '', 'Receta: cinturón de pellejo de guerra', 35435),
(127918, 'esES', 'Te enseña a hacer una poción de maná antigua de forma más eficiente.', '', '', '', 'Receta: poción de maná antigua', 35435),
(139422, 'esES', '', '', '', '', 'Carnaza vil', 35435),
(141058, 'esES', 'Te enseña a fabricar un glifo de Maleficio de alimaña.', '', '', '', 'Técnica: Glifo de Maleficio de alimaña', 35435),
(141038, 'esES', 'Te enseña a fabricar un glifo de Enemigos de las Sombras.', '', '', '', 'Técnica: Glifo de Enemigos de las Sombras', 35435),
(139346, 'esES', '', '', '', '', 'Fluido bebible patentado de Thuni', 35435),
(137934, 'esES', 'Te enseña a fabricar una correa de cuero para mascotas.', '', '', '', 'Receta: correa de cuero para mascotas', 35435),
(137831, 'esES', 'Te enseña a fabricar una gargantilla de pandemonita vengativa.', '', '', '', 'Boceto: gargantilla de pandemonita vengativa', 35435),
(139425, 'esES', '', '', '', '', 'Contrato vinculante con diablillos', 35435),
(141850, 'esES', 'Te enseña a fabricar un arnés para montar cuernoviejos.', '', '', '', 'Receta: arnés para montar cuernoviejos', 35435),
(137966, 'esES', 'Te enseña a fabricar un cincho de filoseda imbuida.', '', '', '', 'Patrón: cincho de filoseda imbuida', 35435);

DELETE FROM `mount_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(468, 'esES', 'Quilen imperial', '|cFFFFD200Promoción:|r Collector\'s Edition de Mists of Pandaria', 'Los quilen, mascotas favoritas de los ancestrales príncipes mogu, son compañeros y monturas leales y valientes.', 35435),
(1282, 'esES', 'Serpiente negra de N\'Zoth', '|cFFFFD200Logro:|r En la profundidad de las visiones', 'Las serpientes negras de N\'Zoth son el presagio de su última visión hecha realidad. Solo los sirvientes o enemigos capaces de caminar por este espacio tienen alguna posibilidad de dominarlas.', 35435);

DELETE FROM `player_condition_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(79509, 'esES', 'Aprende cualquier esencia de la Resistencia de Pernoóxido de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79518, 'esES', 'Aprende Conflicto y discordia de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79511, 'esES', 'Aprende Fuerza vital condensada, Conducto de vitalidad o Dádiva inmortal de Azeroth de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79508, 'esES', 'Aprende Sangre del enemigo, Artificio del tiempo o Esfera de supresión de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79523, 'esES', 'Aprende El Vacío informe de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(74078, 'esES', 'Requiere Ashjra\'kamas, Velo de Resolución.', 35435),
(79512, 'esES', 'Aprende Visión de perfección de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79505, 'esES', 'Aprende Ondulación en el espacio de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79499, 'esES', 'Aprende Iris de enfoque, Invocación de la Patrona de la Vida o Ánima de la Vida y la Muerte de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79522, 'esES', 'Aprende una esencia de alguna visión horripilante de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79514, 'esES', 'Aprende una esencia de los Rajani o del Acuerdo de Uldum de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(75180, 'esES', 'Requiere el logro \"En la profundidad de las visiones\" y haber desbloqueado el rango 3 de esencia. (No se puede comprar si ya se conoce).', 35435),
(79516, 'esES', 'Aprende Recuerdo de sueños lúcidos de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79519, 'esES', 'Aprende una esencia de los Rajani o del Acuerdo de Uldum de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79504, 'esES', 'Aprende Fuerza vital condensada, Conducto de vitalidad o Dádiva inmortal de Azeroth de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(75170, 'esES', 'Requiere el logro \"En la profundidad de las visiones\" y haber desbloqueado el rango 3 de esencia. (No se puede comprar si ya se conoce).', 35435),
(79513, 'esES', 'Aprende Sangre del enemigo, Artificio del tiempo o Esfera de supresión de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79502, 'esES', 'Aprende El Crisol de Llamas de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79501, 'esES', 'Aprende Iris de enfoque, Invocación de la Patrona de la Vida o Ánima de la Vida y la Muerte de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79486, 'esES', 'Aprende Fuerza vital condensada, Conducto de vitalidad o Dádiva inmortal de Azeroth de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79515, 'esES', 'Aprende cualquier esencia de reputación de Nazjatar de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79510, 'esES', 'Aprende Iris de enfoque, Invocación de la Patrona de la Vida o Ánima de la Vida y la Muerte de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79497, 'esES', 'Aprende Sangre del enemigo, Artificio del tiempo o Esfera de supresión de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79521, 'esES', 'Aprende una esencia de los Rajani o del Acuerdo de Uldum de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(75191, 'esES', 'Requiere el logro \"En la profundidad de las visiones\" y haber desbloqueado el rango 3 de esencia. (No se puede comprar si ya se conoce).', 35435),
(79506, 'esES', 'Aprende una esencia de alguna visión horripilante de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79500, 'esES', 'Aprende cualquier esencia de la Resistencia de Pernoóxido de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79503, 'esES', 'Aprende cualquier esencia de la Resistencia de Pernoóxido de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79498, 'esES', 'Aprende Resonancia del Vetamundo de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79507, 'esES', 'Aprende cualquier esencia de reputación de Nazjatar de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79517, 'esES', 'Aprende cualquier esencia de reputación de Nazjatar de rango 3 con otro personaje para desbloquear esta esencia.', 35435),
(79520, 'esES', 'Aprende una esencia de alguna visión horripilante de rango 3 con otro personaje para desbloquear esta esencia.', 35435);

DELETE FROM `map_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(2268, 'esES', 'Ciudad de Mecandria', '', '', '', '', 35435);

DELETE FROM `wmo_area_table_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `wmo_area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(103067, 'esES', 'Ciudad de Mecandria', 35435);

DELETE FROM `achievement_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14260, 'esES', '', '', '', 35435),
(14251, 'esES', '', '', '', 35435),
(14256, 'esES', '', '', '', 35435),
(14263, 'esES', '', '', '', 35435),
(14250, 'esES', '', '', '', 35435),
(14241, 'esES', '', '', '', 35435),
(14246, 'esES', '', '', '', 35435),
(14244, 'esES', '', '', '', 35435),
(14264, 'esES', '', '', '', 35435),
(6980, 'esES', 'Mientras tienes los cuatro Orbes de Poder, mata a cuatro enemigos que tengan un Orbe de Poder en una sola partida en el Templo de Kotmogu.', 'Estrella del Templo de Kotmogu', '', 35435),
(14258, 'esES', '', '', '', 35435),
(14249, 'esES', '', '', '', 35435),
(14254, 'esES', '', '', '', 35435),
(14252, 'esES', '', '', '', 35435),
(14212, 'esES', '', '<Hidden> 8.3 Main Line - Account Has Obtained Legendary Cloak (DNT)', '', 35435),
(14245, 'esES', '', '', '', 35435),
(14242, 'esES', '', '', '', 35435),
(14257, 'esES', '', '', '', 35435),
(14255, 'esES', '', '', '', 35435),
(14248, 'esES', '', '', '', 35435),
(14259, 'esES', '', '', '', 35435),
(14261, 'esES', '', '', '', 35435),
(14265, 'esES', '', '', '', 35435),
(14247, 'esES', '', '', '', 35435),
(14240, 'esES', '', '', '', 35435),
(14238, 'esES', '', 'Azerite Essence - Rank 3 on any character - Azeroth\'s Undying Gift <DND>', '', 35435),
(14253, 'esES', '', '', '', 35435),
(14262, 'esES', '', '', '', 35435),
(14239, 'esES', '', '', '', 35435),
(14243, 'esES', '', '', '', 35435);

DELETE FROM `mail_template_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `mail_template_locale` (`ID`, `locale`, `Body_lang`, `VerifiedBuild`) VALUES
(550, 'esES', 'Para reactivar tu cuenta con oro, hemos retirado algo del dinero disponible en tu correo. Debido a esto, es posible que veas que hay menos dinero del que esperabas en el correo. No te preocupes, ya que no se ha perdido.\nGracias, ¡y disfruta de Azeroth!\n- El equipo de desarrollo de WoW', 35435);

DELETE FROM `dungeon_encounter_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `dungeon_encounter_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(786, 'esES', 'Suma sacerdotisa Mar\'li', 35435);


DELETE FROM `hotfix_blob` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(3386943305, 195997, 'esES', 0x0778781000B20200000400081000000000000000000000000000000001000000000000000097A80200, 35435), -- CreatureDifficulty
(600565378, 267260, 'esES', 0xE56501000000803F6666A63F0093A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267271, 'esES', 0xB46501000000803F0000803F009BA80200, 35435), -- CreatureXDisplayInfo
(3386291891, 174231, 'esES', 0x4D69726D6964C3B36E205A616E6A276972000000000007000000E56501000000000000000000000000000000803F0000803F0000803F0000803F879402000000000000000000, 35435), -- Creature
(600565378, 267266, 'esES', 0xE56501000000803F6666A63F0097A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267274, 'esES', 0xEA6501000000803F9A99993F009EA80200, 35435), -- CreatureXDisplayInfo
(813076512, 22908, 'esES', 0x760000002B2F0300, 35435), -- SpellLabel
(813076512, 22909, 'esES', 0x240100002B2F0300, 35435), -- SpellLabel
(3776013982, 324874, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630390000, 35435), -- Spell
(3776013982, 324905, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374616369C3B36E2063726570757363756C61727C720D0A24407370656C6C646573633331383237360000, 35435), -- Spell
(3776013982, 324865, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353535330000, 35435), -- Spell
(3776013982, 335149, 'esES', 0x004C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E6573206465205772617468206F6620746865204C696368204B696E672061756D656E746120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A20506173656F20656E20656C207469656D706F206465205772617468206F6620746865204C696368204B696E677C720D0A0D0A4C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E6573206465205772617468206F6620746865204C696368204B696E672061756D656E746120756E20247331252E00, 35435), -- Spell
(3776013982, 324856, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646476F6C70652070656E657472616E74657C720D0A24407370656C6C646573633331353238310000, 35435), -- Spell
(3776013982, 324896, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C63464646464646464650756C736F206163656C657261646F7C720D0A24407370656C6C646573633331383236360000, 35435), -- Spell
(3776013982, 321714, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324897, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C63464646464646464650756C736F206163656C657261646F7C720D0A24407370656C6C646573633331383439320000, 35435), -- Spell
(2230237587, 1188, 'esES', 0x436975646164206465204D6563616E647269610096010000250600000000000000, 35435), -- UiMapGroupMember
(3776013982, 324857, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646476F6C70652070656E657472616E74657C720D0A24407370656C6C646573633331353237370000, 35435), -- Spell
(3776013982, 324895, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630370000, 35435), -- Spell
(3776013982, 115546, 'esES', 0x004861636520756E20676573746F2070726F766F6361646F7220616C206F626A657469766F20792070726F766F636120717565207365206D75657661206861636961207469206120756E612076656C6F63696461642061756D656E7461646120756E20243131363138396D33252E243F733131353331355B0D0A0D0A4573746120666163756C746164207365207075656465206C616E7A61722061206C6120657374617475612064656C2042756579204E6567726F20706172612070726F766F63617220656C206D69736D6F2065666563746F20656E20746F646F73206C6F7320656E656D69676F7320656E20756E20726164696F20646520243131383633354131206D2064652061206C6120657374617475612E5D5B5D0000, 35435), -- Spell
(3776013982, 324848, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566163C3AD6F207265736F6E616E74657C720D0A24407370656C6C646573633331383438350000, 35435), -- Spell
(3776013982, 324837, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496E6572636961206D6F7274616C7C720D0A24407370656C6C646573633331383439330000, 35435), -- Spell
(3776013982, 324868, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464653657665726F7C720D0A24407370656C6C646573633331353535370000, 35435), -- Spell
(3776013982, 324877, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653756363696F6E61646F727C720D0A24407370656C6C646573633331353539300000, 35435), -- Spell
(3205218938, 41793, 'esES', 0x4755494C445F46494E4445525F504F5354494E475F4558504952454400C2A1456C20616E756E63696F20686120657870697261646F210001, 35435), -- GlobalStrings
(3776013982, 337612, 'esES', 0x004E275A6F7468207265636C616D61207475206573656E636961207920746520696E666C69676520756E206461C3B16F206571756976616C656E7465206120756E20247331252064652074752073616C7564206DC3A178696D612063616461202474312073206D69656E7472617320657374C3A17320656E20636F6D626174652E20456C2066696E207365206163657263612E00526563696269656E646F20756E206461C3B16F206571756976616C656E7465206120756E20247731252064652074752073616C7564206DC3A178696D612063616461202474312073206D69656E7472617320657374C3A17320656E20636F6D626174652E00, 35435), -- Spell
(3776013982, 292579, 'esES', 0x0053692068617920756E6120686F67756572612063657263612C20756E206176656E74757265726F20707565646520656E63656E6465726C612E0053692068617920756E6120686F67756572612063657263612C20756E206176656E74757265726F20707565646520656E63656E6465726C612E00, 35435), -- Spell
(2230237587, 1162, 'esES', 0x436975646164206465204D6563616E64726961008F010000D90500000400000000, 35435), -- UiMapGroupMember
(2035710060, 7072, 'esES', 0x457370C3AD72697475206C6F6120656E736F6D6272656369646F004C612073756D61207361636572646F74697361204D6172276C69207574696C697A61206573746120666163756C746164206D69656E7472617320657374C3A120706F7365C3AD646120706F7220656C20657370C3AD726974752064652047617261276A616C2E0D0A0D0A4C612073756D61207361636572646F74697361204D6172276C6920696E766F636120756E20657370C3AD72697475206C6F6120656E736F6D6272656369646F20656E2073752075626963616369C3B36E2E20456C20657370C3AD726974752073652066696A6120656E20756E206A756761646F7220616C6561746F72696F2079206C6F20706572736967756520647572616E74652024313337333935642E20536920656C20657370C3AD72697475207365206163657263612061206D656E6F7320646520243133373339304131206D2064656C206A756761646F722C206C6F206D6174612E0D0A0D0A536920656C20657370C3AD72697475207369677565207669766F20747261732024313337333935642C2073616C74612061207375206F626A657469766F20616C20696E7374616E74652079206C6F206D6174612E0030031C8A1B0000A11B02000000000000000000000000DFA209000200320013, 35435), -- JournalEncounterSection
(3776013982, 300798, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324866, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464653657665726F7C720D0A24407370656C6C646573633331353535340000, 35435), -- Spell
(3776013982, 324875, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630380000, 35435), -- Spell
(3776013982, 256134, 'esES', 0x0052656475636520636F6E736964657261626C656D656E7465206C6F73206D6174657269616C6573206E656365736172696F73207061726120666162726963617220756E206D6F746F7220736F627265616C696D656E7461646F2E0000, 35435), -- Spell
(3776013982, 324898, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C63464646464646464650756C736F206163656C657261646F7C720D0A24407370656C6C646573633331383439360000, 35435), -- Spell
(3776013982, 324889, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C6C61732064656C20696E66696E69746F7C720D0A24407370656C6C646573633331383237340000, 35435), -- Spell
(3776013982, 324907, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374616369C3B36E2063726570757363756C61727C720D0A24407370656C6C646573633331383437380000, 35435), -- Spell
(3776013982, 335150, 'esES', 0x004C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E65732064652043617461636C79736D2061756D656E746120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A20506173656F20656E20656C207469656D706F2064652043617461636C79736D7C720D0A0D0A4C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E65732064652043617461636C79736D2061756D656E746120756E20247331252E00, 35435), -- Spell
(3776013982, 321428, 'esES', 0x00496E666C6967652024733120702E206465206461C3B16F206465206C617320536F6D62726173206120746F646F73206C6F73206A756761646F72657320636164612024743120732E0024733120702E206465206461C3B16F206465206C617320536F6D6272617320696E666C696769646F7320636164612024743120732E00, 35435), -- Spell
(2035710060, 7071, 'esES', 0x497261206465206C6F73206C6F61004C612073756D61207361636572646F74697361204D6172276C69207574696C697A61206573746120666163756C746164206D69656E7472617320657374C3A120706F7365C3AD646120706F7220656C20657370C3AD726974752064652047617261276A616C2E0D0A0D0A4C612073756D61207361636572646F74697361204D6172276C6920676F6C706561206120756E206A756761646F7220636F6E206C6120497261206465206C6F73206C6F612C206C6F2071756520696E666C6967652024313337333437733120702E206465206461C3B16F206465206C617320536F6D627261732E0030031B8A1B0000A01B02000000000000000000000000BC62090000004000FF, 35435), -- JournalEncounterSection
(3776013982, 324858, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C7C720D0A24407370656C6C646573633331353533310000, 35435), -- Spell
(3776013982, 306259, 'esES', 0x000000, 35435), -- Spell
(2901650891, 1582, 'esES', 0x53756D61207361636572646F74697361204D6172276C6900002E060000300372BA0000000000000309000000, 35435), -- JournalEncounterCreature
(3776013982, 335152, 'esES', 0x004C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E6573206465205761726C6F726473206F6620447261656E6F722061756D656E746120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A20506173656F20656E20656C207469656D706F206465205761726C6F726473206F6620447261656E6F727C720D0A0D0A4C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E6573206465205761726C6F726473206F6620447261656E6F722061756D656E746120756E20247331252E00, 35435), -- Spell
(3776013982, 324880, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653756363696F6E61646F727C720D0A24407370656C6C646573633331353539320000, 35435), -- Spell
(3776013982, 256133, 'esES', 0x00526564756365206C6F73206D6174657269616C6573206E656365736172696F73207061726120666162726963617220756E206D6F746F7220736F627265616C696D656E7461646F2E0000, 35435), -- Spell
(3776013982, 324879, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653756363696F6E61646F727C720D0A24407370656C6C646573633331353539310000, 35435), -- Spell
(3776013982, 335151, 'esES', 0x004C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E6573206465204D69737473206F662050616E64617269612061756D656E746120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A20506173656F20656E20656C207469656D706F206465204D69737473206F662050616E64617269617C720D0A0D0A4C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E6573206465204D69737473206F662050616E64617269612061756D656E746120756E20247331252E00, 35435), -- Spell
(3776013982, 300748, 'esES', 0x000000, 35435), -- Spell
(20077728, 396607, 'esES', 0x000001000000474302000001006FD6, 35435), -- QuestObjective
(3205218938, 42497, 'esES', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F5449544C450053652074652068612070726F6D6F63696F6E61646F2061206CC3AD6465727C54496E746572666163655C5C47726F75704672616D655C5C55492D47726F75702D4C656164657249636F6E3A303A303A303A2D317C74207C6E7C6E7C636666666664323030C2BF5175696572657320766F6C76657220612061C3B1616469722061206C61206C6973746120656C207369677569656E746520677275706F3F7C727C6E25737C6E0001, 35435), -- GlobalStrings
(3776013982, 324861, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C7C720D0A24407370656C6C646573633331353532390000, 35435), -- Spell
(3776013982, 328136, 'esES', 0x0041756D656E746120756E2024733125206C612067616E616E636961206465207265707574616369C3B36E20656E206C61732049736C61732041627275707461732C2041726775732C204B756C2054697261732C205A616E64616C61722079204E617A6A617461722E0047616E616E636961206465207265707574616369C3B36E20656E206C61732049736C61732041627275707461732C2041726775732C204B756C2054697261732C205A616E64616C61722079204E617A6A617461722061756D656E7461646120756E20247331252E00, 35435), -- Spell
(3776013982, 325947, 'esES', 0x0024407370656C6C646573633239363832300000, 35435), -- Spell
(3776013982, 294479, 'esES', 0x000042757363616E646F2061727465666163746F7320616E746967756F732E00, 35435), -- Spell
(3776013982, 155346, 'esES', 0x005465207472616E73666F726D6172C3A1732070657269C3B3646963616D656E746520656E20756E20706F6465726F736F206F67726F20467565676F20476C616369616C20717565206F746F72676120756E202431353533333773322520646520726573697374656E636961206D656A6F726164612061206C6F732065666563746F73206164766572736F732E005465207472616E73666F726D6172C3A1732070657269C3B3646963616D656E746520656E20756E20706F6465726F736F206F67726F20467565676F20476C616369616C20717565206F746F72676120756E202431353533333773322520646520726573697374656E636961206D656A6F726164612061206C6F732065666563746F73206164766572736F732E00, 35435), -- Spell
(3776013982, 321201, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324680, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496E6572636961206D6F7274616C7C720D0A24407370656C6C646573633331383236380000, 35435), -- Spell
(3776013982, 324903, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C63464646464646464656657264616420696E646573637269707469626C657C720D0A24407370656C6C646573633331383330330000, 35435), -- Spell
(3205218938, 42500, 'esES', 0x47524F55505F46494E4445525F4445534C4953545F5741524E494E475F454449545F4C495354494E4700456469746172206C697374610001, 35435), -- GlobalStrings
(3776013982, 313040, 'esES', 0x004162726520756E206167756A65726F20656E20656C2074656A69646F206465206C61207265616C696461642C206C6F20717565206472656E612024333133303430733220702E20646520636F7264757261206520696E666C6967652024333133303430733120702E206465206461C3B16F206465206C617320536F6D62726173206120746F646F73206C6F7320656E656D69676F732E0D0A0D0A456C206167756A65726F2063726561207C352024407370656C6C6E616D6533313736323720647572616E74652024333137363334442E0000, 35435), -- Spell
(3205218938, 42645, 'esES', 0x424E45545F4552524F525F34303031310028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C0002, 35435), -- GlobalStrings
(3776013982, 294003, 'esES', 0x00004C6F63757261732070757269666963616461732E0D0A436F726475726120726567656E6572C3A16E646F73652E00, 35435), -- Spell
(3776013982, 324899, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E74652061677564617C720D0A24407370656C6C646573633331383236390000, 35435), -- Spell
(3776013982, 324850, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566163C3AD6F207265736F6E616E74657C720D0A24407370656C6C646573633331383238300000, 35435), -- Spell
(3776013982, 324860, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D616769737472616C7C720D0A24407370656C6C646573633331353533300000, 35435), -- Spell
(3776013982, 324882, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C2064656C20566163C3AD6F7C720D0A24407370656C6C646573633331383238360000, 35435), -- Spell
(3776013982, 321748, 'esES', 0x0050726F766F63612071756520656C206F626A657469766F2061637475616C20636C6F6E6520616C207461756D61747572676F2E0000, 35435), -- Spell
(3776013982, 324891, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C6C61732064656C20696E66696E69746F7C720D0A24407370656C6C646573633331383438380000, 35435), -- Spell
(3776013982, 325946, 'esES', 0x000000, 35435), -- Spell
(3776013982, 331973, 'esES', 0x000000, 35435), -- Spell
(3776013982, 154253, 'esES', 0x00412076656365732C20756E206C6F626F2067C3A96C69646F20617975646172C3A12061206C6F732063616D70656F6E65732064656C20636C616E204C6F626F2047C3A96C69646F2E00412076656365732C20756E206C6F626F2067C3A96C69646F20617975646172C3A12061206C6F732063616D70656F6E65732064656C20636C616E204C6F626F2047C3A96C69646F2E00, 35435), -- Spell
(3776013982, 324904, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C63464646464646464656657264616420696E646573637269707469626C657C720D0A24407370656C6C646573633331383438340000, 35435), -- Spell
(3776013982, 321200, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324864, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353535320000, 35435), -- Spell
(3776013982, 316661, 'esES', 0x0024407370656C6C646573633331363635310000, 35435), -- Spell
(3776013982, 275496, 'esES', 0x0053656E74656E63696120696E666C696765206461C3B16F206578747261206375616E646F20747520706F7263656E74616A652064652073616C7564206573207375706572696F722061206C612073616C75642064656C206F626A657469766F2C20686173746120756E206DC3A178696D6F2064652024733120702E206465206461C3B16F2E0000, 35435), -- Spell
(3776013982, 324902, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F49726F6E4D616964656E735F436F72727570746564426C6F6F642E626C703A32347C74207C6346464646464646464865726964612073616E6772616E74657C720D0A24407370656C6C646573633331383237320000, 35435), -- Spell
(3776013982, 155334, 'esES', 0x00457374C3A17320656E2073696E63726F6EC3AD6120636F6E20656C206869656C6F2064656C20C3A17265612E2054757320656E656D69676F73206120766563657320736520636F6E67656C616E20616E74652074752070726573656E6369612E0054757320656E656D69676F73206120766563657320736520636F6E67656C616E20616E74652074752070726573656E6369612E00, 35435), -- Spell
(3776013982, 324870, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C63464646464646464653657665726F7C720D0A24407370656C6C646573633331353535380000, 35435), -- Spell
(3776013982, 311204, 'esES', 0x000000, 35435), -- Spell
(3776013982, 293072, 'esES', 0x004372656120756E2063686172636F206F736375726F20717565206472656E6120246F3220702E20646520636F726475726120647572616E74652024642061206C6F7320656E656D69676F732071756520656E7472656E20656E20656C20C3A17265612E0024733220702E20646520636F7264757261207065726469646F7320636164612024743220732E00, 35435), -- Spell
(3776013982, 302166, 'esES', 0x00456C2063617A61646F722061736573696E6F207472616520756E696461646573206465207265667565727A6F206465736465206C6120436975646164206465204D6563616E647269612E0000, 35435), -- Spell
(3776013982, 264663, 'esES', 0x506173697661206465204665726F6369646164005475206D6173636F746120792074C3BA2067616EC3A1697320756E202473312520646520726573746974756369C3B36E2E005061726173697461722061756D656E7461646F20756E20247732252E00, 35435), -- Spell
(3776013982, 324839, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646496E6572636961206D6F7274616C7C720D0A24407370656C6C646573633331383439370000, 35435), -- Spell
(3776013982, 327254, 'esES', 0x000000, 35435), -- Spell
(3776013982, 315958, 'esES', 0x000000, 35435), -- Spell
(3776013982, 335148, 'esES', 0x004C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E657320646520546865204275726E696E6720437275736164652061756D656E746120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A20506173656F20656E20656C207469656D706F20646520546865204275726E696E6720437275736164657C720D0A0D0A4C61207265707574616369C3B36E206F6274656E69646120656E20636F6D62617465207920656E206D6973696F6E657320646520546865204275726E696E6720437275736164652061756D656E746120756E20247331252E00, 35435), -- Spell
(3776013982, 335642, 'esES', 0x00476F6C70656120616C20656E656D69676F2C206C6520696E666C69676520756E20247331252064656C206461C3B16F20636F6E2061726D6120636F6D6F206461C3B16F206465206C617320536F6D6272617320792061756D656E746120756E202473322520656C206461C3B16F20696E666C696769646F20647572616E74652024642E004461C3B16F2061756D656E7461646F20756E20247332252E00, 35435), -- Spell
(3776013982, 155344, 'esES', 0x0054652062656E646963656E206C6F73207669656E746F73206465206C612043726573746120467565676F20476C616369616C2E205469656E657320756E612070726F626162696C69646164206465206F6274656E65722056656E646176616C20667572696F736F2C20717565206F746F72676120756E20313030252064652063656C6572696461642079206C65766974616369C3B36E2E005469656E657320756E612070726F626162696C69646164206465206F6274656E65722056656E646176616C20667572696F736F2C20717565206F746F72676120756E20313030252064652063656C6572696461642079206C65766974616369C3B36E2E00, 35435), -- Spell
(3205218938, 41792, 'esES', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952455F534F4F4E00456C20616E756E63696F2065787069726120656E3A0001, 35435), -- GlobalStrings
(3776013982, 324885, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C2064656C20566163C3AD6F7C720D0A24407370656C6C646573633331383438300D0A0000, 35435), -- Spell
(3776013982, 300692, 'esES', 0x000000, 35435), -- Spell
(3776013982, 274909, 'esES', 0x005061746164612064656C20736F6C206E616369656E74652073616E612024323734393132733120702E206120746F646F73206C6F7320616C6961646F7320636F6E207475204E6965626C612072656E6F7661646F72612C204E6965626C6120656E766F6C76656E7465206F204675656E7465206465206573656E63696120792061756D656E7461202473312073206C6120647572616369C3B36E2064652065736F732065666563746F732C20686173746120756E202473322520646520737520647572616369C3B36E206F726967696E616C2E0000, 35435), -- Spell
(2035710060, 7050, 'esES', 0x53756D61207361636572646F74697361204D6172276C69000030031800009D1B00000172BA000000000000000000000000000001000000FF, 35435), -- JournalEncounterSection
(3776013982, 120679, 'esES', 0x00496E766F636120756E6120706F6465726F7361206265737469612073616C76616A652071756520617461636120616C206F626A657469766F207920727567652C206C6F207175652061756D656E746120756E20243238313033367331252074752063656C65726964616420647572616E74652024642E0000, 35435), -- Spell
(3776013982, 293777, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324854, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C634646464646464646476F6C70652070656E657472616E74657C720D0A24407370656C6C646573633331353238320000, 35435), -- Spell
(3776013982, 324893, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6964616420656D657267656E74657C720D0A24407370656C6C646573633331383439350000, 35435), -- Spell
(3776013982, 324884, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C2064656C20566163C3AD6F7C720D0A24407370656C6C646573633331383437390000, 35435), -- Spell
(3776013982, 324853, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C6346464646464646464578706564697469766F7C720D0A24407370656C6C646573633331353534340000, 35435), -- Spell
(3776013982, 291435, 'esES', 0x004372656120756E2063686172636F206F736375726F20717565206472656E6120246F3220702E20646520636F726475726120647572616E74652024642061206C6F7320656E656D69676F732071756520656E7472656E20656E20656C20C3A17265612E0024733220702E20646520636F7264757261207065726469646F7320636164612024743220732E00, 35435), -- Spell
(3776013982, 155333, 'esES', 0x000000, 35435), -- Spell
(3776013982, 300932, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324862, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353534390000, 35435), -- Spell
(3205218938, 42496, 'esES', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F53554254455854007C6E257320686173746120656C696D696E6172206465206C61206C69737461206175746F6DC3A1746963616D656E74650001, 35435), -- GlobalStrings
(3776013982, 110556, 'esES', 0x000000, 35435), -- Spell
(3776013982, 154274, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324851, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C6346464646464646464578706564697469766F7C720D0A24407370656C6C646573633331353534360000, 35435), -- Spell
(3776013982, 155347, 'esES', 0x00546520696D62757965732064656C20657370C3AD726974752064656C206C6F626F2C206C6F206375616C2061756D656E74612074752076656C6F6369646164206465206361727265726120756E2024313534323539733125206375616E646F206E6F20657374C3A17320656E20636F6D6261746520656E206C612043726573746120467565676F20476C616369616C2E0056656C6F636964616420646520636172726572612061756D656E7461646120756E202431353432353973312520667565726120646520636F6D626174652E00, 35435), -- Spell
(3776013982, 301683, 'esES', 0x00456D69746520756E61206F6C6120646520657363616C6F6672C3AD6F732076656E656E6F736F73206465736465206C612075626963616369C3B36E20646520747520656E656D69676F2071756520696E666C6967652024733120702E206465206461C3B16F206120746F646F73206C6F7320656E656D69676F7320656E20756E20726164696F2064652035206D2E0000, 35435), -- Spell
(3776013982, 337816, 'esES', 0x0024407370656C6C646573633333373631320000, 35435), -- Spell
(3776013982, 324881, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5741524C4F434B5F534F554C535741502E424C503A32347C74207C63464646464646464641746973626F20646520636C6172696461647C720D0A24407370656C6C646573633331383233390000, 35435), -- Spell
(3776013982, 324890, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C6C61732064656C20696E66696E69746F7C720D0A24407370656C6C646573633331383438370000, 35435), -- Spell
(3776013982, 324886, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C6346464646464646464170C3A96E64696365207265746F726369646F7C720D0A24407370656C6C646573633331383438310000, 35435), -- Spell
(3745449290, 6134, 'esES', 0x436975646164206465204D6563616E647269610000F61700008E1F2444E4C4BB431233A4C300000000000000007E1A000084110000C5EC000003000000D9050000310800000000000000000000, 35435), -- AreaPOI
(3776013982, 324888, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C6346464646464646464170C3A96E64696365207265746F726369646F7C720D0A24407370656C6C646573633331383438330000, 35435), -- Spell
(3776013982, 324894, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6964616420656D657267656E74657C720D0A24407370656C6C646573633331383439390000, 35435), -- Spell
(2035710060, 7070, 'esES', 0x457370C3AD72697475206C6F612062656E6469746F004C612073756D61207361636572646F74697361204D6172276C6920696E766F636120756E20657370C3AD72697475206C6F612062656E6469746F20656E2073752075626963616369C3B36E2E20456C20657370C3AD726974752073652061636572636172C3A120616C20616C6961646F206465204D6172276C6920636F6E206D656E6F732073616C75642072657374616E74652079206C6F2073616E6172C3A120756E20243133373330337331252064652073752073616C7564206DC3A178696D61207369206E6F207365206D61746120616C20657370C3AD7269747520616E7465732064652071756520616C63616E63652061207375206F626A657469766F2E0D0A0D0A536920656C20657370C3AD72697475207369677565207669766F20747261732024313337323837642C2073616C7461206175746F6DC3A1746963616D656E74652061207375206F626A657469766F2079206C6F2073616E6120756E20243133373330337331252064652073752073616C7564206DC3A178696D612E0030031A8A1B00009F1B02000000000000000000000000C231080000002200FF, 35435), -- JournalEncounterSection
(3776013982, 155315, 'esES', 0x00457374C3A17320656E2073696E63726F6EC3AD6120636F6E20656C20667565676F2064656C20C3A17265612E20412076656365732C20756E2070696C6172206465206C617661206578706C6F746172C3A12062616A6F2074757320656E656D69676F732E00412076656365732C20756E2070696C6172206465206C617661206578706C6F746172C3A12062616A6F2074757320656E656D69676F732E00, 35435), -- Spell
(3776013982, 301578, 'esES', 0x000000, 35435), -- Spell
(2035710060, 7073, 'esES', 0x44657374696E6F207265746F726369646F004C612073756D61207361636572646F74697361204D6172276C69207574696C697A61206573746120666163756C746164206D69656E7472617320657374C3A120706F7365C3AD646120706F7220656C20657370C3AD726974752064652047617261276A616C2E0D0A0D0A4C612073756D61207361636572646F74697361204D6172276C6920617272616E6361206C617320616C6D617320646520646F73206A756761646F72657320616C6561746F72696F732079206C61732076696E63756C612E204361646120756E612070657273696775652061206C61206F747261206520696E666C6967652024313337393732733120702E206465206461C3B16F206465206C617320536F6D62726173206120746F646F73206C6F73206A756761646F72657320636164612024313337393735743120732E20456C206461C3B16F2064652044657374696E6F207265746F726369646F20736520726564756365206375616E746F206DC3A173206C656A6F7320657374C3A920756E20616C6D61206465206C61206F7472612E0D0A0D0A4375616E646F20756E20616C6D61206D756572652C20656C2076C3AD6E63756C6F20736520726F6D70652079206C61206F74726120636F6D69656E7A61206120696E666C696769722024313337393836733120702E206465206461C3B16F206465206C617320536F6D6272617320636164612024313337393836743220732E0030031D8A1B00000000020000000000000000000000009B07070002001A000C, 35435), -- JournalEncounterSection
(3776013982, 155345, 'esES', 0x000000, 35435), -- Spell
(3776013982, 332950, 'esES', 0x000054757320666163756C7461646573207469656E656E20756E612070726F626162696C6964616420646520696E666C6967697220244039303537733120702E206465206461C3B16F2E00, 35435), -- Spell
(3776013982, 324901, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E74652061677564617C720D0A24407370656C6C646573633331383439380000, 35435), -- Spell
(3776013982, 324892, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6964616420656D657267656E74657C720D0A24407370656C6C646573633331383237300000, 35435), -- Spell
(3776013982, 324852, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C6346464646464646464578706564697469766F7C720D0A24407370656C6C646573633331353534350000, 35435), -- Spell
(3776013982, 299937, 'esES', 0x00456C2063617A61646F722061736573696E6F207472616520756E696461646573206465207265667565727A6F206465736465206C6120436975646164206465204D6563616E647269612E0000, 35435), -- Spell
(3776013982, 296464, 'esES', 0x004C6120756E69646164206465206F7072657369C3B36E2061C3A9726561204B505537207472616520756E696461646573206465207265667565727A6F206465736465206C6120436975646164206465204D6563616E647269612E0000, 35435), -- Spell
(3205218938, 42646, 'esES', 0x424E45545F4552524F525F34303031320028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C202832290002, 35435), -- GlobalStrings
(3776013982, 324900, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E74652061677564617C720D0A24407370656C6C646573633331383439340000, 35435), -- Spell
(3776013982, 292907, 'esES', 0x004C616E7A6120756E20667261676D656E746F206465206869656C6F20616C206F626A657469766F2C206C6F2071756520696E666C69676520756E20247331252064656C206461C3B16F2064652061746171756520636F6D6F206461C3B16F2066C3AD7369636F2E0000, 35435), -- Spell
(3776013982, 324887, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C6346464646464646464170C3A96E64696365207265746F726369646F7C720D0A24407370656C6C646573633331383438320000, 35435), -- Spell
(3205218938, 41794, 'esES', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952454400C2A1456C20616E756E63696F20686120657870697261646F210001, 35435), -- GlobalStrings
(3776013982, 319451, 'esES', 0x000000, 35435), -- Spell
(3776013982, 154275, 'esES', 0x000000, 35435), -- Spell
(3776013982, 155313, 'esES', 0x000000, 35435), -- Spell
(3776013982, 154259, 'esES', 0x00546520696D62757965732064656C20657370C3AD726974752064656C206C6F626F2C206C6F206375616C2061756D656E74612074752076656C6F6369646164206465206D6F76696D69656E746F20756E2073312520656E206C612043726573746120467565676F20476C616369616C2E0056656C6F636964616420646520636172726572612061756D656E7461646120756E202473312520656E206C612043726573746120467565676F20476C616369616C2E00, 35435), -- Spell
(3205218938, 41791, 'esES', 0x4755494C445F46494E4445525F504F5354494E475F474F494E475F544F5F45585049524500456C20616E756E63696F2065787069726120656E3A0001, 35435), -- GlobalStrings
(3776013982, 304086, 'esES', 0x4573656E63696120646520617A6572697461004D69656E7472617320657374C3A17320617475726469646F2C20656C20626F6E757320646520646566656E736120646520747520766572736174696C696461642061756D656E746120756E20243330343737357331252E0000, 35435), -- Spell
(3776013982, 324845, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566163C3AD6F207265736F6E616E74657C720D0A24407370656C6C646573633331383438360000, 35435), -- Spell
(3776013982, 155343, 'esES', 0x000000, 35435), -- Spell
(3776013982, 324906, 'esES', 0x00496D6275796520756E206F626A65746F20646520756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374616369C3B36E2063726570757363756C61727C720D0A24407370656C6C646573633331383437370000, 35435), -- Spell
(2035710060, 7069, 'esES', 0x497261206465206C6F73206C6F61004C612073756D61207361636572646F74697361204D6172276C6920676F6C706561206120756E206A756761646F7220636F6E206C6120497261206465206C6F73206C6F612C206C6F2071756520696E666C6967652024313337333434733120702E206465206461C3B16F205361677261646F2E003003198A1B00009E1B020000000000000000000000002413020000004000FF, 35435), -- JournalEncounterSection
(2948698321, 249, 'esES', 0xD6968DCA7ACF9DD1, 35435), -- TactKeyLookup
(2948698321, 259, 'esES', 0xB50278B84158ABDF, 35435), -- TactKeyLookup
(603412935, 28663, 'esES', 0x3130E9878CE5B1B1E8B7AFE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28664, 'esES', 0xE6899BE9BAA6E9838E0004, 35435), -- ChatProfanity
(603412935, 28644, 'esES', 0xE689A9E998B4E599A80004, 35435), -- ChatProfanity
(603412935, 28652, 'esES', 0xE5A3B9E59C8BE585A9E8A3BD0004, 35435), -- ChatProfanity
(603412935, 28656, 'esES', 0xE99988E696B9E5AE89E7949F0004, 35435), -- ChatProfanity
(603412935, 28653, 'esES', 0xE994A4E995B0E5B8AE0004, 35435), -- ChatProfanity
(603412935, 28650, 'esES', 0x4C69626572617465484B0004, 35435), -- ChatProfanity
(603412935, 28645, 'esES', 0xE5BEB7E5AFB8E88C8E0004, 35435), -- ChatProfanity
(603412935, 28648, 'esES', 0xE99B8FE5A5B30004, 35435), -- ChatProfanity
(603412935, 28658, 'esES', 0xE794B2E7B49AE688A6E78AAF0004, 35435), -- ChatProfanity
(603412935, 28655, 'esES', 0xE69C80E9AB98E4BABAE6B0910004, 35435), -- ChatProfanity
(603412935, 28661, 'esES', 0xE684BFE88DA3E58589E5BD92E9A699E6B8AF0004, 35435), -- ChatProfanity
(603412935, 28649, 'esES', 0xE6B9BFE7A9B40004, 35435), -- ChatProfanity
(603412935, 28657, 'esES', 0xE4BD95E4BF8AE4BB810004, 35435), -- ChatProfanity
(603412935, 28647, 'esES', 0xE99CB2E998B4E9B8A10004, 35435), -- ChatProfanity
(603412935, 28662, 'esES', 0xE58D81E9878CE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28646, 'esES', 0xE88C8EE9BE9F0004, 35435), -- ChatProfanity
(603412935, 28651, 'esES', 0x66726565484B0004, 35435), -- ChatProfanity
(603412935, 28660, 'esES', 0xE88194E982A6E5AEA3E8A8800004, 35435), -- ChatProfanity
(603412935, 28654, 'esES', 0xE4BABAE6B091E6A380E5AF9FE999A20004, 35435), -- ChatProfanity
(603412935, 28659, 'esES', 0xE696B0E4B8ADE59BBDE88194E982A60004, 35435), -- ChatProfanity
(4033975491, 403803, 'esES', 0x0000704100000000000000410000000000000000000000005B290600308A1300000000000000000000000000000000000000000000000000000000204100000000FFFFFFFFFFFF00000000000000000000000AD50100, 35435), -- SpellVisualKitModelAttach
(4146370265, 91772, 'esES', 0x0000A0400000000000002041000000000000000000000000000000000000000022130000000000000000000000000000000000000000000000000000000000000000, 35435), -- SpellVisual
(517656225, 6688, 'esES', 0x0000803F00000000E17AD43F000000000000000100001A00000000000303000000000000000000000000A4707D3F0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFF4742000000000000000000000000000000000000C8430000964300000040FFFFFFFF02038030E13E022B873D0AD7233C636D2400000020400000003F69000000000000000000803F0000803F6E186F180000000000000000000000000000000000000000403F3333B33E6666E63E0000000000000000000000000000000000000000000000000000000000000000000000008D5E1E008C5E1E008C5E1E00, 35435), -- SpellChainEffects
(4033975491, 404117, 'esES', 0x00000000000000000000C03F000000000000000000000000952A0600D9891300000000000000000000000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000009D50100, 35435), -- SpellVisualKitModelAttach
(1181150530, 307455, 'esES', 0x020000005B2906000AD50100, 35435), -- SpellVisualKitEffect
(25144992, 2203, 'esES', 0x201A0000000000000000000001000000CB0100000000000013000000FFFFFFFF0000000000000000, 35435); -- BeamEffect
