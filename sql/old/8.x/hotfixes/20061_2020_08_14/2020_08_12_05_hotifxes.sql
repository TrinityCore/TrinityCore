DELETE FROM `broadcast_text_locale` WHERE `VerifiedBuild`>0 AND `locale` = 'esMX' AND `ID` IN (195400, 79796, 165870, 79804, 79799, 79798, 201784, 201777, 183984, 194274, 753, 201778, 79794, 79795, 141708, 165239, 165244, 165245, 165243, 165241, 165237, 165246);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(195400, 'esMX', 'Me gustaría ver las esencias sintetizadas, por favor.', 'Me gustaría ver las esencias sintetizadas, por favor.', 35435),
(79796, 'esMX', 'Piedra de chamán descubierta: tocado por fuego', 'Piedra de chamán descubierta: tocado por fuego', 35435),
(165870, 'esMX', '', 'Te contaré acerca de la caída de Rastakhan cuando estés lista.', 35435),
(79804, 'esMX', 'Piedra de chamán descubierta: tocado por hielo', 'Piedra de chamán descubierta: tocado por hielo', 35435),
(79799, 'esMX', 'Piedra de chamán descubierta: entereza de ogro', 'Piedra de chamán descubierta: entereza de ogro', 35435),
(79798, 'esMX', 'Piedra de chamán descubierta: vendaval de furia sacudidor', 'Piedra de chamán descubierta: vendaval de furia sacudidor', 35435),
(201784, 'esMX', '¡Lo he visto con mis propios ojos! ¡Lady Jaina fue atacada en alta mar!', '', 35435),
(201777, 'esMX', '', 'Sé cómo llegar hasta la hija del mar. Síganme si eh\'tán listos.', 35435),
(183984, 'esMX', '|cfff2e699+$1i p. de cordura|r', '|cfff2e699+$1i p. de cordura|r', 35435),
(194274, 'esMX', 'I want to teleport to Operation: Mechagon (Dungeon).', 'I want to teleport to Operation: Mechagon (Dungeon).', 35435),
(753, 'esMX', '¿Qué? ¿Quieres decir que no puedes matarlo tú solo?', '', 35435),
(201778, 'esMX', 'Estamos listos. ¡Adelante!', 'Estamos listos. ¡Adelante!', 35435),
(79794, 'esMX', 'Piedra de chamán descubierta: bendición del lobo', 'Piedra de chamán descubierta: bendición del lobo', 35435),
(79795, 'esMX', 'Piedra de chamán descubierta: espíritu del lobo', 'Piedra de chamán descubierta: espíritu del lobo', 35435),
(141708, 'esMX', 'Debilita al grifo pero mantén tu agarre con |TInterface\\ICONS\\INV_MISC_DESECRATED_LEATHERGLOVE.BLP:20|t |cFFFF0000|Hspell:269442|h[Sujeción firme]|h|r', '', 35435),
(165239, 'esMX', 'Dominen su furia... Conviertan el odio en un arma.', 'Dominen su furia... Conviertan el odio en un arma.', 35435),
(165244, 'esMX', 'Sí... Se acercan... cada vez más.', 'Sí... Se acercan... cada vez más.', 35435),
(165245, 'esMX', 'Cada elección que tomas te ata más y más a mi dominio.', 'Cada elección que tomas te ata más y más a mi dominio.', 35435),
(165243, 'esMX', 'Por fin... Reciban la verdad de la sombra.', 'Por fin... Reciban la verdad de la sombra.', 35435),
(165241, 'esMX', 'Más profundo, siempre más profundo.', 'Más profundo, siempre más profundo.', 35435),
(165237, 'esMX', 'Ahh... Creen que conocen el poder.', 'Ahh... Creen que conocen el poder.', 35435),
(165246, 'esMX', 'Las baratijas se pudren ante la mirada de un dios.', 'Las baratijas se pudren ante la mirada de un dios.', 35435);

DELETE FROM `gameobjects_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `gameobjects_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(338477, 'esMX', 'Teletransportador de Ciudad de Mecalópolis', 35435),
(341363, 'esMX', 'Teletransportador de Ciudad de Mecalópolis', 35435),
(341828, 'esMX', 'Teletransportador de Ciudad de Mecalópolis', 35435);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(87487, 'esMX', 'Escudo de resonancia sonora', 35435);

DELETE FROM `azerite_essence_power_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `azerite_essence_power_locale` (`ID`, `locale`, `SourceAlliance_lang`, `SourceHorde_lang`, `VerifiedBuild`) VALUES
(140, 'esMX', 'Visiones horribles de N\'Zoth|n|cFFFFD200Logro:|r|n\"Más allá de las Visiones\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Ubicación:|r Cámara del Corazón', '', 35435),
(132, 'esMX', 'Visiones horribles de N\'Zoth|n|cFFFFD200Logro:|r|n\"Más allá de las Visiones\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Ubicación:|r Cámara del Corazón', '', 35435),
(114, 'esMX', 'Visiones horribles de N\'Zoth|n|cFFFFD200Logro:|r|n\"Más allá de las Visiones\"|n|cFFFFD200PNJ:|r Wrathion|n|cFFFFD200Ubicación:|r Cámara del Corazón', '', 35435);

DELETE FROM `currency_types_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1803, 'esMX', 'Ecos de Ny\'alotha', 'Se ha eliminado por completo la corrupción de N\'Zoth de esta sustancia, y MADRE puede utilizarla para sintetizar esencias en la Cámara del Corazón.', 35435);

DELETE FROM `spell_name_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(155313, 'esMX', 'Piedra de chamán: tocado por fuego', 35435),
(324892, 'esMX', 'Corrupción - Vitalidad impetuosa 1', 35435),
(332950, 'esMX', 'Fire Proc (DNT)', 35435),
(324894, 'esMX', 'Corrupción - Vitalidad impetuosa 3', 35435),
(337816, 'esMX', 'Consecuencias inevitables', 35435),
(154274, 'esMX', 'Piedra de chamán: bendición del lobo', 35435),
(291435, 'esMX', 'Charco de cordura', 35435),
(324893, 'esMX', 'Corrupción - Vitalidad impetuosa 2', 35435),
(324854, 'esMX', 'Corrupción - Atravesar 3', 35435),
(293777, 'esMX', 'Fragor de sombra', 35435),
(120679, 'esMX', 'Bestia temible', 35435),
(274909, 'esMX', 'Niebla creciente', 35435),
(300692, 'esMX', 'REUSE ME [MTMM] (DNT)', 35435),
(335148, 'esMX', 'Señal del Vacío Abisal', 35435),
(315958, 'esMX', 'Teletransporte a Ciudad de Mecalópolis', 35435),
(324839, 'esMX', 'Corrupción - Ímpetu mortal 3', 35435),
(324905, 'esMX', 'Corrupción - Devastación crepuscular 1', 35435),
(324857, 'esMX', 'Corrupción - Atravesar 1', 35435),
(324848, 'esMX', 'Corrupción - Vacío resonante 2', 35435),
(324877, 'esMX', 'Corrupción - Succionador 1', 35435),
(337612, 'esMX', 'Consecuencias inevitables', 35435),
(292579, 'esMX', 'Hoguera cercana', 35435),
(300798, 'esMX', 'REUSE ME [MTMM] (DNT)', 35435),
(324866, 'esMX', 'Corrupción - Severidad 1', 35435),
(324898, 'esMX', 'Corrupción - Aceleración de pulso 3', 35435),
(324889, 'esMX', 'Corrupción - Estrellas infinitas 1', 35435),
(256133, 'esMX', 'REUSE ME [SCS]', 35435),
(335151, 'esMX', 'Señal de las Nieblas', 35435),
(324861, 'esMX', 'Corrupción - Maestro experto 1', 35435),
(328136, 'esMX', 'Influencia impresionante', 35435),
(294479, 'esMX', 'Desenterrando', 35435),
(155346, 'esMX', 'Piedra de chamán: entereza de ogro', 35435),
(324680, 'esMX', 'Corrupción - Ímpetu mortal 1', 35435),
(324899, 'esMX', 'Corrupción - Mente aguda 1', 35435),
(324850, 'esMX', 'Corrupción - Vacío resonante 1', 35435),
(324860, 'esMX', 'Corrupción - Maestro experto 2', 35435),
(324882, 'esMX', 'Corrupción - Ritual del Vacío 1', 35435),
(321748, 'esMX', '¡Clóname!', 35435),
(325946, 'esMX', 'Tirar baba', 35435),
(331973, 'esMX', '', 35435),
(324904, 'esMX', 'Corrupción - Verdad inefable 2', 35435),
(321200, 'esMX', 'Lanzar misión', 35435),
(324902, 'esMX', 'Corrupción - Herida sangrante', 35435),
(155334, 'esMX', 'Piedra de chamán: tocado por hielo', 35435),
(324906, 'esMX', 'Corrupción - Devastación crepuscular 2', 35435),
(155343, 'esMX', 'Piedra de chamán: vendaval de furia sacudidor', 35435),
(324845, 'esMX', 'Corrupción - Vacío resonante 3', 35435),
(304086, 'esMX', 'Conflicto', 35435),
(154259, 'esMX', 'Piedra de chamán: espíritu del lobo', 35435),
(324852, 'esMX', 'Corrupción - Expeditivo 2', 35435),
(299937, 'esMX', 'Relevo de refuerzos', 35435),
(296464, 'esMX', 'Relevo de refuerzos', 35435),
(324887, 'esMX', 'Corrupción - Extremidad retorcida 2', 35435),
(154275, 'esMX', 'Piedra de chamán: espíritu del lobo', 35435),
(275496, 'esMX', 'Justicia indomable', 35435),
(316661, 'esMX', 'Destrucción obsidiana', 35435),
(324864, 'esMX', 'Corrupción - Versátil 2', 35435),
(154253, 'esMX', 'Piedra de chamán: bendición del lobo', 35435),
(324891, 'esMX', 'Corrupción - Estrellas infinitas 3', 35435),
(294003, 'esMX', 'Canción del buscador', 35435),
(313040, 'esMX', 'Oscuridad infinita', 35435),
(324903, 'esMX', 'Corrupción - Verdad inefable 1', 35435),
(321201, 'esMX', 'Lanzar misión', 35435),
(325947, 'esMX', 'Tirar baba', 35435),
(300748, 'esMX', 'REUSE ME [MTMM] (DNT)', 35435),
(324879, 'esMX', 'Corrupción - Succionador 2', 35435),
(324880, 'esMX', 'Corrupción - Succionador 3', 35435),
(335152, 'esMX', 'Señal de Hierro', 35435),
(306259, 'esMX', 'Tentáculo', 35435),
(324858, 'esMX', 'Corrupción - Maestro experto 3', 35435),
(321428, 'esMX', 'El precio del infinito', 35435),
(335150, 'esMX', 'Señal del Destructor', 35435),
(324907, 'esMX', 'Corrupción - Devastación crepuscular 3', 35435),
(256134, 'esMX', 'REUSE ME [SCS]', 35435),
(324875, 'esMX', 'Corrupción - Evasivo 2', 35435),
(324868, 'esMX', 'Corrupción - Severidad 2', 35435),
(324837, 'esMX', 'Corrupción - Ímpetu mortal 2', 35435),
(115546, 'esMX', 'Burla', 35435),
(324895, 'esMX', 'Corrupción - Evasivo 1', 35435),
(324897, 'esMX', 'Corrupción - Aceleración de pulso 2', 35435),
(321714, 'esMX', 'Teleport to Silithus', 35435),
(324896, 'esMX', 'Corrupción - Aceleración de pulso 1', 35435),
(324856, 'esMX', 'Corrupción - Atravesar 2', 35435),
(335149, 'esMX', 'Señal de la Plaga', 35435),
(324865, 'esMX', 'Corrupción - Versátil 3', 35435),
(324874, 'esMX', 'Corrupción - Evasivo 3', 35435),
(324870, 'esMX', 'Corrupción - Severidad 3', 35435),
(311204, 'esMX', 'Llévame hacia Ciudad de Mecalópolis', 35435),
(293072, 'esMX', 'Charco de cordura', 35435),
(302166, 'esMX', 'Relevo de refuerzos', 35435),
(264663, 'esMX', 'Sed predadora', 35435),
(327254, 'esMX', 'Amenaza de Espora putrefacta', 35435),
(335642, 'esMX', 'Supergolpe', 35435),
(155344, 'esMX', 'Piedra de chamán: vendaval de furia sacudidor', 35435),
(324885, 'esMX', 'Corrupción - Ritual del Vacío 3', 35435),
(324884, 'esMX', 'Corrupción - Ritual del Vacío 2', 35435),
(324853, 'esMX', 'Corrupción - Expeditivo 1', 35435),
(155333, 'esMX', 'Piedra de chamán: tocado por hielo', 35435),
(300932, 'esMX', 'REUSE ME [MTMM] (DNT)', 35435),
(324862, 'esMX', 'Corrupción - Versátil 1', 35435),
(110556, 'esMX', '[DNT] Force Cast Tried to Fly', 35435),
(324851, 'esMX', 'Corrupción - Expeditivo 3', 35435),
(155347, 'esMX', 'Piedra de chamán: espíritu del lobo', 35435),
(301683, 'esMX', 'REUSE ME', 35435),
(324881, 'esMX', 'Corrupción - Atisbo de claridad', 35435),
(324890, 'esMX', 'Corrupción - Estrellas infinitas 2', 35435),
(324886, 'esMX', 'Corrupción - Extremidad retorcida 1', 35435),
(324888, 'esMX', 'Corrupción - Extremidad retorcida 3', 35435),
(155315, 'esMX', 'Piedra de chamán: tocado por fuego', 35435),
(301578, 'esMX', 'REUSE ME', 35435),
(155345, 'esMX', 'Piedra de chamán: entereza de ogro', 35435),
(324901, 'esMX', 'Corrupción - Mente aguda 3', 35435),
(324900, 'esMX', 'Corrupción - Mente aguda 2', 35435),
(292907, 'esMX', 'Fragmento de hielo corrupto', 35435),
(319451, 'esMX', 'Teletransporte a Ciudad de Mecalópolis', 35435);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(85132, 'esMX', '', 35435),
(85128, 'esMX', '', 35435),
(84755, 'esMX', 'Completa la misión de la capa legendaria', 35435),
(85090, 'esMX', '', 35435),
(84814, 'esMX', 'El jugador natonocturno puede vestir la armadura legada', 35435),
(85136, 'esMX', '', 35435),
(85102, 'esMX', '', 35435),
(84815, 'esMX', 'El jugador orco mag\'har puede vestir la armadura legada', 35435),
(85110, 'esMX', '', 35435),
(84811, 'esMX', 'El jugador templeluz puede vestir la armadura legada', 35435),
(85106, 'esMX', '', 35435),
(85086, 'esMX', '', 35435),
(85088, 'esMX', '', 35435),
(85124, 'esMX', '', 35435),
(84813, 'esMX', 'El jugador vulpera puede vestir la armadura legada', 35435),
(85120, 'esMX', '', 35435),
(84808, 'esMX', 'El jugador tauren de Altamontaña puede vestir la armadura legada', 35435),
(84816, 'esMX', 'El jugador trol zandalari puede vestir la armadura legada', 35435),
(85096, 'esMX', '', 35435),
(84809, 'esMX', 'El jugador elfo del Vacío puede vestir la armadura legada', 35435),
(34935, 'esMX', 'Obtén la bendición de la Piedra de chamán: Espíritu del Lobo', 35435),
(85116, 'esMX', '', 35435),
(85126, 'esMX', '', 35435),
(85084, 'esMX', '', 35435),
(85114, 'esMX', '', 35435),
(85118, 'esMX', '', 35435),
(84812, 'esMX', 'El jugador mecagnomo puede vestir la armadura legada', 35435),
(78565, 'esMX', 'Diferencial perfectamente sincronizado', 35435),
(82623, 'esMX', 'Limpia la ciudad de Mecalópolis', 35435),
(84810, 'esMX', 'El jugador enano Hierro Negro puede vestir la armadura legada', 35435),
(85092, 'esMX', '', 35435),
(85122, 'esMX', '', 35435),
(85112, 'esMX', '', 35435),
(85094, 'esMX', '', 35435),
(84817, 'esMX', 'El jugador kultirano puede vestir la armadura legada', 35435),
(85104, 'esMX', '', 35435),
(85108, 'esMX', '', 35435),
(85138, 'esMX', '', 35435),
(85100, 'esMX', '', 35435),
(85130, 'esMX', '', 35435),
(85025, 'esMX', 'Costasur contra Molino Tarren', 35435),
(85134, 'esMX', '', 35435),
(85098, 'esMX', '', 35435);

DELETE FROM `item_name_description_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `item_name_description_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(13572, 'esMX', '25 p. de corrupción', 35435),
(13520, 'esMX', '30 p. de corrupción', 35435),
(13568, 'esMX', '20 p. de corrupción', 35435),
(13576, 'esMX', '30 p. de corrupción', 35435),
(13567, 'esMX', '15 p. de corrupción', 35435),
(13573, 'esMX', '45 p. de corrupción', 35435),
(13565, 'esMX', '66 p. de corrupción', 35435),
(13575, 'esMX', '17 p. de corrupción', 35435),
(13577, 'esMX', '12 p. de corrupción', 35435),
(13569, 'esMX', '10 p. de corrupción', 35435),
(13578, 'esMX', '16 p. de corrupción', 35435),
(13566, 'esMX', '35 p. de corrupción', 35435),
(13519, 'esMX', '20 p. de corrupción', 35435),
(13570, 'esMX', '75 p. de corrupción', 35435),
(13513, 'esMX', '25 p. de corrupción', 35435),
(13580, 'esMX', '60 p. de corrupción', 35435),
(13517, 'esMX', '10 p. de corrupción', 35435),
(13571, 'esMX', '50 p. de corrupción', 35435),
(13518, 'esMX', '15 p. de corrupción', 35435),
(13521, 'esMX', 'Entre 5 y 30 p de corrupción', 35435),
(13516, 'esMX', '5 p. de corrupción', 35435),
(13579, 'esMX', '8 p. de corrupción', 35435),
(13574, 'esMX', '28 p. de corrupción', 35435);

DELETE FROM `area_table_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(10290, 'esMX', 'Mecalópolis', 35435),
(12825, 'esMX', 'Ciudad de Mecalópolis', 35435);

DELETE FROM `ui_map_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `ui_map_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(1573, 'esMX', 'Ciudad de Mecalópolis', 35435),
(1574, 'esMX', 'Ciudad de Mecalópolis', 35435);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(87487, 'esMX', '', '', '', '', 'Escudo de resonancia sonora', 35435),
(178004, 'esMX', '', '', '', '', 'Extracto de contaminante: Devastación crepuscular', 35435),
(177989, 'esMX', '', '', '', '', 'Extracto de contaminante: Aceleración de pulso', 35435),
(178011, 'esMX', '', '', '', '', 'Extracto de contaminante: Versátil', 35435),
(177993, 'esMX', '', '', '', '', 'Extracto de contaminante: Severidad', 35435),
(177978, 'esMX', '', '', '', '', 'Extracto de contaminante: Mente aguda', 35435),
(177967, 'esMX', '', '', '', '', 'Extracto de contaminante: Vacío resonante', 35435),
(177972, 'esMX', '', '', '', '', 'Extracto de contaminante: Evasivo', 35435),
(177982, 'esMX', '', '', '', '', 'Extracto de contaminante: Verdad inefable', 35435),
(178005, 'esMX', '', '', '', '', 'Extracto de contaminante: Devastación crepuscular', 35435),
(177990, 'esMX', '', '', '', '', 'Extracto de contaminante: Aceleración de pulso', 35435),
(177984, 'esMX', '', '', '', '', 'Extracto de contaminante: Estrellas infinitas', 35435),
(177988, 'esMX', '', '', '', '', 'Extracto de contaminante: Maestro experto', 35435),
(177955, 'esMX', '', '', '', '', 'Extracto de contaminante: Ímpetu mortal', 35435),
(177995, 'esMX', '', '', '', '', 'Extracto de contaminante: Succionador', 35435),
(178000, 'esMX', '', '', '', '', 'Extracto de contaminante: Atravesar', 35435),
(178010, 'esMX', '', '', '', '', 'Extracto de contaminante: Versátil', 35435),
(177999, 'esMX', '', '', '', '', 'Extracto de contaminante: Atravesar', 35435),
(177966, 'esMX', '', '', '', '', 'Extracto de contaminante: Ímpetu mortal', 35435),
(178003, 'esMX', '', '', '', '', 'Extracto de contaminante: Vitalidad impetuosa', 35435),
(177981, 'esMX', '', '', '', '', 'Extracto de contaminante: Verdad inefable', 35435),
(178007, 'esMX', '', '', '', '', 'Extracto de contaminante: Extremidad retorcida', 35435),
(173937, 'esMX', 'El ojo cercenado sigue tu mirada a todas partes.', '', '', '', 'Oculus cercenado', 35435),
(177986, 'esMX', '', '', '', '', 'Extracto de contaminante: Maestro experto', 35435),
(177964, 'esMX', '', '', '', '', 'Encantar arma: Multiplicador de fuerzas', 35435),
(168043, 'esMX', 'Codiciado por los Amathet, que se consideran los guardianes de las obras de los titanes.', '', '', '', 'Artefacto titánico', 35435),
(177971, 'esMX', '', '', '', '', 'Extracto de contaminante: Evasivo', 35435),
(177974, 'esMX', '', '', '', '', 'Extracto de contaminante: Expeditivo', 35435),
(178006, 'esMX', '', '', '', '', 'Extracto de contaminante: Devastación crepuscular', 35435),
(177977, 'esMX', '', '', '', '', 'Extracto de contaminante: Herida sangrante', 35435),
(177991, 'esMX', '', '', '', '', 'Extracto de contaminante: Aceleración de pulso', 35435),
(178013, 'esMX', '', '', '', '', 'Extracto de contaminante: Ritual del Vacío', 35435),
(177994, 'esMX', '', '', '', '', 'Extracto de contaminante: Severidad', 35435),
(178009, 'esMX', '', '', '', '', 'Extracto de contaminante: Extremidad retorcida', 35435),
(177973, 'esMX', '', '', '', '', 'Extracto de contaminante: Expeditivo', 35435),
(177979, 'esMX', '', '', '', '', 'Extracto de contaminante: Mente aguda', 35435),
(177969, 'esMX', '', '', '', '', 'Extracto de contaminante: Vacío resonante', 35435),
(177975, 'esMX', '', '', '', '', 'Extracto de contaminante: Expeditivo', 35435),
(178001, 'esMX', '', '', '', '', 'Extracto de contaminante: Vitalidad impetuosa', 35435),
(178008, 'esMX', '', '', '', '', 'Extracto de contaminante: Extremidad retorcida', 35435),
(177968, 'esMX', '', '', '', '', 'Extracto de contaminante: Vacío resonante', 35435),
(177996, 'esMX', '', '', '', '', 'Extracto de contaminante: Succionador', 35435),
(178014, 'esMX', '', '', '', '', 'Extracto de contaminante: Ritual del Vacío', 35435),
(177985, 'esMX', '', '', '', '', 'Extracto de contaminante: Estrellas infinitas', 35435),
(177992, 'esMX', '', '', '', '', 'Extracto de contaminante: Severidad', 35435),
(177970, 'esMX', '', '', '', '', 'Extracto de contaminante: Evasivo', 35435),
(178002, 'esMX', '', '', '', '', 'Extracto de contaminante: Vitalidad impetuosa', 35435),
(177998, 'esMX', '', '', '', '', 'Extracto de contaminante: Atravesar', 35435),
(177965, 'esMX', '', '', '', '', 'Extracto de contaminante: Ímpetu mortal', 35435),
(177987, 'esMX', '', '', '', '', 'Extracto de contaminante: Maestro experto', 35435),
(177980, 'esMX', '', '', '', '', 'Extracto de contaminante: Mente aguda', 35435),
(177983, 'esMX', '', '', '', '', 'Extracto de contaminante: Estrellas infinitas', 35435),
(178012, 'esMX', '', '', '', '', 'Extracto de contaminante: Versátil', 35435),
(178015, 'esMX', '', '', '', '', 'Extracto de contaminante: Ritual del Vacío', 35435),
(177976, 'esMX', '', '', '', '', 'Extracto de contaminante: Atisbo de claridad', 35435),
(177997, 'esMX', '', '', '', '', 'Extracto de contaminante: Succionador', 35435),
(137934, 'esMX', 'Te enseña a fabricar una Correa de cuero para mascotas.', '', '', '', 'Receta: Correa de cuero para mascotas', 35435),
(137962, 'esMX', 'Te enseña a fabricar una Cincha de filoseda.', '', '', '', 'Patrón: Cincha de filoseda', 35435),
(137917, 'esMX', 'Te enseña a fabricar una Faja de escama grabada.', '', '', '', 'Receta: Faja de escama grabada', 35435),
(139344, 'esMX', '', '', '', '', 'Banana de maná', 35435),
(139346, 'esMX', '', '', '', '', 'Fluido para beber patentado de Thuni', 35435),
(137881, 'esMX', 'Te enseña a fabricar un Cinturón de pellejo de guerra.', '', '', '', 'Receta: Cinturón de pellejo de guerra', 35435),
(139412, 'esMX', '', '', '', '', 'Tortugas de guerra mutantes jóvenes', 35435),
(139345, 'esMX', '', '', '', '', 'Manos de rata', 35435),
(139347, 'esMX', '', '', '', '', 'Medusa de bajío', 35435),
(139422, 'esMX', '', '', '', '', 'Cebo vil', 35435),
(137826, 'esMX', 'Te enseña a fabricar un Colgante de rubí sombrío hechicero.', '', '', '', 'Diseño: Colgante de rubí sombrío hechicero', 35435),
(137954, 'esMX', 'Te enseña a fabricar una Cincha de filoseda.', '', '', '', 'Patrón: Cincha de filoseda', 35435),
(139411, 'esMX', '', '', '', '', 'Festín de los Bajos Fondos', 35435),
(141057, 'esMX', 'Te enseña a fabricar un Glifo de destello cegador.', '', '', '', 'Técnica: Glifo de destello cegador', 35435),
(137706, 'esMX', 'Te enseña a fabricar una Carga de pólvora.', '', '', '', 'Esquema: Carga de pólvora', 35435),
(137831, 'esMX', 'Te enseña a fabricar una Gargantilla de pandemonita vengativa.', '', '', '', 'Diseño: Gargantilla de pandemonita vengativa', 35435),
(139425, 'esMX', '', '', '', '', 'Contrato vinculador de diablillos', 35435),
(137913, 'esMX', 'Te enseña a fabricar una Faja de batalla.', '', '', '', 'Receta: Faja de batalla', 35435),
(139431, 'esMX', '', '', '', '', 'Cajón de arneses de rata semental', 35435),
(137932, 'esMX', 'Te enseña a fabricar un Aro ígneo.', '', '', '', 'Receta: Aro ígneo', 35435),
(141038, 'esMX', 'Te enseña a fabricar un Glifo de enemigos de las sombras.', '', '', '', 'Técnica: Glifo de enemigos de las sombras', 35435),
(137829, 'esMX', 'Te enseña a fabricar un Colgante de rubí sombrío sutil.', '', '', '', 'Diseño: Colgante de rubí sombrío sutil', 35435),
(138016, 'esMX', 'Te enseña a fabricar un Cofre de ropa: ciudadanos de Dalaran.', '', '', '', 'Patrón de Cofre de ropa: ciudadanos de Dalaran', 35435),
(137869, 'esMX', 'Te enseña a fabricar un Cinturón de pellejo de guerra.', '', '', '', 'Receta: Cinturón de pellejo de guerra', 35435),
(137885, 'esMX', 'Te enseña a fabricar un Cinturón de terrocuero.', '', '', '', 'Receta: Cinturón de terrocuero', 35435),
(127918, 'esMX', 'Te enseña a hacer una poción de maná ancestral de manera más eficiente.', '', '', '', 'Receta: poción de maná ancestral', 35435),
(141850, 'esMX', 'Te enseña a fabricar un arnés para montar vetecuerno.', '', '', '', 'Receta: Arnés para montar vetecuerno', 35435),
(137901, 'esMX', 'Te enseña a fabricar una Faja de batalla.', '', '', '', 'Receta: Faja de batalla', 35435),
(137966, 'esMX', 'Te enseña a fabricar una Cincha de filoseda imbuida.', '', '', '', 'Patrón: Cincha de filoseda imbuida', 35435),
(141058, 'esMX', 'Te enseña a fabricar un Glifo del maleficio de alimaña.', '', '', '', 'Técnica: Glifo del maleficio de alimaña', 35435),
(141065, 'esMX', 'Te enseña a fabricar un Glifo del Guarda terrorífico.', '', '', '', 'Técnica: Glifo del Guarda terrorífico', 35435);

DELETE FROM `mount_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1282, 'esMX', 'Serpiente negra de N\'Zoth', '|cFFFFD200Logro:|r Más allá de las Visiones', 'Las serpientes negras de N\'Zoth anuncian que su visión más terrible se está volviendo realidad. Solo aquellos sirvientes o enemigos que pueden caminar en este plano tienen posibilidad de dominarlas.', 35435),
(468, 'esMX', 'Quilen imperial', '|cFFFFD200Promoción:|r Edición de coleccionista de Mists of Pandaria', 'Los quilen, las mascotas favoritas de los antiguos príncipes mogu, son compañeros leales y monturas temerarias.', 35435);

DELETE FROM `player_condition_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(79508, 'esMX', 'Aprende Sangre del enemigo, Artificio del tiempo o Esfera de supresión (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79512, 'esMX', 'Aprende Visión de perfección (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79505, 'esMX', 'Aprende Desgarro espacial (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79522, 'esMX', 'Aprende cualquier esencia (rango 3) de Visiones horribles con otro personaje para desbloquear esta esencia.', 35435),
(75180, 'esMX', 'Requiere el logro \"Más allá de las Visiones\" y haber desbloqueado la esencia de rango 3. (No se puede comprar si ya lo aprendiste).', 35435),
(79516, 'esMX', 'Aprende Recuerdos de sueños lúcidos (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(75170, 'esMX', 'Requiere el logro \"Más allá de las Visiones\" y haber desbloqueado la esencia de rango 3. (No se puede comprar si ya lo aprendiste).', 35435),
(79513, 'esMX', 'Aprende Sangre del enemigo, Artificio del tiempo o Esfera de supresión (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79502, 'esMX', 'Aprende Crisol de Llamas (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79520, 'esMX', 'Aprende cualquier esencia (rango 3) de Visiones horribles con otro personaje para desbloquear esta esencia.', 35435),
(79517, 'esMX', 'Aprende cualquier esencia de rango 3 de la reputación de Nazjatar con otro personaje para desbloquear esta esencia.', 35435),
(79507, 'esMX', 'Aprende cualquier esencia de rango 3 de la reputación de Nazjatar con otro personaje para desbloquear esta esencia.', 35435),
(79503, 'esMX', 'Aprende cualquier esencia de rango 3 de la Resistencia de Pernoxidado con otro personaje para desbloquear esta esencia.', 35435),
(79500, 'esMX', 'Aprende cualquier esencia de rango 3 de la Resistencia de Pernoxidado con otro personaje para desbloquear esta esencia.', 35435),
(75191, 'esMX', 'Requiere el logro \"Más allá de las Visiones\" y haber desbloqueado la esencia de rango 3. (No se puede comprar si ya lo aprendiste).', 35435),
(79521, 'esMX', 'Aprende cualquier esencia Rajani o de Acuerdo de Uldum (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79497, 'esMX', 'Aprende Sangre del enemigo, Artificio del tiempo o Esfera de supresión (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79515, 'esMX', 'Aprende cualquier esencia de rango 3 de la reputación de Nazjatar con otro personaje para desbloquear esta esencia.', 35435),
(79519, 'esMX', 'Aprende cualquier esencia Rajani o de Acuerdo de Uldum (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79501, 'esMX', 'Aprende Iris de enfoque, Invocación de la Protectora o Ánima de vida y muerte (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79509, 'esMX', 'Aprende cualquier esencia de rango 3 de la Resistencia de Pernoxidado con otro personaje para desbloquear esta esencia.', 35435),
(79511, 'esMX', 'Aprende Fuerza vital condensada, Conducto de vitalidad o Dádiva imperecedera de Azeroth (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79518, 'esMX', 'Aprende Conflicto y discordia (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79486, 'esMX', 'Aprende Fuerza vital condensada, Conducto de vitalidad o Dádiva imperecedera de Azeroth (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79510, 'esMX', 'Aprende Iris de enfoque, Invocación de la Protectora o Ánima de vida y muerte (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79506, 'esMX', 'Aprende cualquier esencia (rango 3) de Visiones horribles con otro personaje para desbloquear esta esencia.', 35435),
(79498, 'esMX', 'Aprende Resonancia de veta del mundo (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79504, 'esMX', 'Aprende Fuerza vital condensada, Conducto de vitalidad o Dádiva imperecedera de Azeroth (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79514, 'esMX', 'Aprende cualquier esencia Rajani o de Acuerdo de Uldum (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(79499, 'esMX', 'Aprende Iris de enfoque, Invocación de la Protectora o Ánima de vida y muerte (rango 3) con otro personaje para desbloquear esta esencia.', 35435),
(74078, 'esMX', 'Requiere Ashjra\'kamas, sudario de determinación.', 35435),
(79523, 'esMX', 'Aprende El Vacío amorfo (rango 3) con otro personaje para desbloquear esta esencia.', 35435);

DELETE FROM `map_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `map_locale` (`ID`, `locale`, `MapName_lang`, `MapDescription0_lang`, `MapDescription1_lang`, `PvpShortDescription_lang`, `PvpLongDescription_lang`, `VerifiedBuild`) VALUES
(2268, 'esMX', 'Ciudad de Mecalópolis', '', '', '', '', 35435);

DELETE FROM `wmo_area_table_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `wmo_area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(103067, 'esMX', 'Ciudad de Mecalópolis', 35435);

DELETE FROM `achievement_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(14241, 'esMX', '', '', '', 35435),
(14246, 'esMX', '', '', '', 35435),
(6980, 'esMX', 'Mientras tienes los cuatro Orbes de Poder, mata a cuatro enemigos que tengan un Orbe de Poder en una sola partida en el Templo de Kotmogu.', 'Estrella del Templo de Kotmogu', '', 35435),
(14249, 'esMX', '', '', '', 35435),
(14254, 'esMX', '', '', '', 35435),
(14212, 'esMX', '', '<Hidden> 8.3 Main Line - Account Has Obtained Legendary Cloak (DNT)', '', 35435),
(14243, 'esMX', '', '', '', 35435),
(14262, 'esMX', '', '', '', 35435),
(14238, 'esMX', '', 'Azerite Essence - Rank 3 on any character - Azeroth\'s Undying Gift <DND>', '', 35435),
(14240, 'esMX', '', '', '', 35435),
(14265, 'esMX', '', '', '', 35435),
(14248, 'esMX', '', '', '', 35435),
(14242, 'esMX', '', '', '', 35435),
(14260, 'esMX', '', '', '', 35435),
(14263, 'esMX', '', '', '', 35435),
(14251, 'esMX', '', '', '', 35435),
(14257, 'esMX', '', '', '', 35435),
(14255, 'esMX', '', '', '', 35435),
(14259, 'esMX', '', '', '', 35435),
(14261, 'esMX', '', '', '', 35435),
(14247, 'esMX', '', '', '', 35435),
(14253, 'esMX', '', '', '', 35435),
(14239, 'esMX', '', '', '', 35435),
(14245, 'esMX', '', '', '', 35435),
(14252, 'esMX', '', '', '', 35435),
(14258, 'esMX', '', '', '', 35435),
(14264, 'esMX', '', '', '', 35435),
(14244, 'esMX', '', '', '', 35435),
(14250, 'esMX', '', '', '', 35435),
(14256, 'esMX', '', '', '', 35435);

DELETE FROM `mail_template_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `mail_template_locale` (`ID`, `locale`, `Body_lang`, `VerifiedBuild`) VALUES
(550, 'esMX', 'Para reactivar tu cuenta con oro, hemos retirado dinero no recolectado de tu correo. Debido a esto, es posible que veas que hay menos dinero del que esperabas en el correo. No te preocupes, ya que el dinero no se ha perdido.\nGracias, ¡y disfruta de Azeroth!\n- El equipo de desarrollo de WoW', 35435);

DELETE FROM `dungeon_encounter_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `dungeon_encounter_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(786, 'esMX', 'Suma sacerdotisa Mar\'li', 35435);


DELETE FROM `hotfix_blob` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(3386943305, 195997, 'esMX', 0x0778781000B20200000400081000000000000000000000000000000001000000000000000097A80200, 35435), -- CreatureDifficulty
(600565378, 267260, 'esMX', 0xE56501000000803F6666A63F0093A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267266, 'esMX', 0xE56501000000803F6666A63F0097A80200, 35435), -- CreatureXDisplayInfo
(600565378, 267271, 'esMX', 0xB46501000000803F0000803F009BA80200, 35435), -- CreatureXDisplayInfo
(600565378, 267274, 'esMX', 0xEA6501000000803F9A99993F009EA80200, 35435), -- CreatureXDisplayInfo
(3386291891, 174231, 'esMX', 0x4D69726D6964C3B36E207A616E6A276972000000000007000000E56501000000000000000000000000000000803F0000803F0000803F0000803F879402000000000000000000, 35435), -- Creature
(813076512, 22909, 'esMX', 0x240100002B2F0300, 35435), -- SpellLabel
(813076512, 22908, 'esMX', 0x760000002B2F0300, 35435), -- SpellLabel
(3776013982, 155313, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 319451, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 292907, 'esMX', 0x004469737061726120756E20667261676D656E746F206465206869656C6F20636F6E74726120656C206F626A657469766F2071756520696E666C69676520756E2024733125206465206461C3B16F2064652061746171756520636F6D6F206461C3B16F2066C3AD7369636F2E0000, 35435), -- Spell
(3776013982, 324900, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E74652061677564617C720D0A24407370656C6C646573633331383439340000, 35435), -- Spell
(3205218938, 42646, 'esMX', 0x424E45545F4552524F525F34303031320028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C202832290002, 35435), -- GlobalStrings
(3776013982, 324901, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E74652061677564617C720D0A24407370656C6C646573633331383439380000, 35435), -- Spell
(3776013982, 155345, 'esMX', 0x000000, 35435), -- Spell
(2035710060, 7073, 'esMX', 0x44657374696E6F207265746F726369646F004C612073756D61207361636572646F74697361204D6172276C69207574696C697A61206573746120666163756C746164206D69656E7472617320657374C3A120706F7365C3AD646120706F7220656C20657370C3AD726974752064652047617261276A616C2E0D0A0D0A4C612073756D61207361636572646F74697361204D6172276C6920617272616E6361206C617320616C6D617320646520646F73206A756761646F72657320616C6561746F72696F732079206C61732076696E63756C612E204361646120756E612070657273696775652061206C61206F747261206520696E666C6967652024313337393732733120702E206465206461C3B16F206465206C617320536F6D62726173206120746F646F73206C6F73206A756761646F72657320636164612024313337393735743120732E20456C206461C3B16F2064652044657374696E6F207265746F726369646F20736520726564756365206375616E746F206DC3A173206C656A6F7320657374C3A920756E20616C6D61206465206C61206F7472612E0D0A0D0A4375616E646F20756E20616C6D61206D756572652C20656C2076C3AD6E63756C6F20736520726F6D70652079206C61206F74726120636F6D69656E7A61206120696E666C696769722024313337393836733120702E206465206461C3B16F206465206C617320536F6D6272617320636164612024313337393836743220732E0030031D8A1B00000000020000000000000000000000009B07070002001A000C, 35435), -- JournalEncounterSection
(3776013982, 301578, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 155315, 'esMX', 0x00457374C3A17320656E2073696E746F6EC3AD6120636F6E20656C20667565676F206465206C61207A6F6E612E20556E2070696C6172206465206C617661206578706C6F746120636164612074616E746F20646562616A6F2064652074757320656E656D69676F732E00556E2070696C6172206465206C617661206578706C6F746120636164612074616E746F20646562616A6F2064652074757320656E656D69676F732E00, 35435), -- Spell
(2035710060, 7070, 'esMX', 0x457370C3AD72697475206C6F612062656E6469746F004C612073756D61207361636572646F74697361204D6172276C6920696E766F636120756E20657370C3AD72697475206C6F612062656E6469746F20656E2073752075626963616369C3B36E2E20456C20657370C3AD726974752073652061636572636172C3A120616C20616C6961646F206465204D6172276C6920636F6E206D656E6F732073616C75642072657374616E74652079206C6F2073616E6172C3A120756E20243133373330337331252064652073752073616C7564206DC3A178696D61207369206E6F207365206D61746120616C20657370C3AD7269747520616E7465732064652071756520616C63616E63652061207375206F626A657469766F2E0D0A0D0A536920656C20657370C3AD72697475207369677565207669766F20747261732024313337323837642C2073616C7461206175746F6DC3A1746963616D656E74652061207375206F626A657469766F2079206C6F2073616E6120756E20243133373330337331252064652073752073616C7564206DC3A178696D612E0030031A8A1B00009F1B02000000000000000000000000C231080000002200FF, 35435), -- JournalEncounterSection
(3776013982, 324888, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C63464646464646464645787472656D69646164207265746F72636964617C720D0A24407370656C6C646573633331383438330000, 35435), -- Spell
(3745449290, 6134, 'esMX', 0x436975646164206465204D6563616CC3B3706F6C69730000F61700008E1F2444E4C4BB431233A4C300000000000000007E1A000084110000C5EC000003000000D9050000310800000000000000000000, 35435), -- AreaPOI
(3776013982, 324886, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C63464646464646464645787472656D69646164207265746F72636964617C720D0A24407370656C6C646573633331383438310000, 35435), -- Spell
(3776013982, 324890, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C6C617320696E66696E697461737C720D0A24407370656C6C646573633331383438370000, 35435), -- Spell
(3776013982, 324881, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5741524C4F434B5F534F554C535741502E424C503A32347C74207C63464646464646464641746973626F20646520636C6172696461647C720D0A24407370656C6C646573633331383233390000, 35435), -- Spell
(3776013982, 301683, 'esMX', 0x00456E76C3AD6120756E61206F6C612064652074656D626C6F7265732076656E656E6F736F73206465736465206C612075626963616369C3B36E20646520747520656E656D69676F2071756520696E666C6967656E2024733120702E206465206461C3B16F2061206C6F7320656E656D69676F7320656E20756E20726164696F2064652035206D2E0000, 35435), -- Spell
(3776013982, 155347, 'esMX', 0x005469656E657320656C20657370C3AD726974752064656C206C6F626F2C206C6F207175652061756D656E74612074752076656C6F6369646164206465206361727265726120756E202431353432353973312520667565726120646520636F6D626174652079206D69656E7472617320657374C3A97320656E20437265737461205069726F6672C3AD6F2E0056656C6F636964616420646520636172726572612061756D656E7461646120756E2024313534323539733125206D69656E74726173206E6F20657374C3A97320656E20636F6D626174652E00, 35435), -- Spell
(3776013982, 324851, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C6346464646464646464578706564697469766F7C720D0A24407370656C6C646573633331353534360000, 35435), -- Spell
(3776013982, 110556, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324862, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353534390000, 35435), -- Spell
(3776013982, 300932, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 155333, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324853, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C6346464646464646464578706564697469766F7C720D0A24407370656C6C646573633331353534340000, 35435), -- Spell
(3776013982, 324884, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C2064656C20566163C3AD6F7C720D0A24407370656C6C646573633331383437390000, 35435), -- Spell
(3776013982, 324885, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C2064656C20566163C3AD6F7C720D0A24407370656C6C646573633331383438300D0A0000, 35435), -- Spell
(3776013982, 155344, 'esMX', 0x0054652062656E646963656E206C6F73207669656E746F7320646520437265737461205069726F6672C3AD6F2E205469656E657320756E612070726F626162696C696461642064652067616E61722056656E646176616C20667572696F736F2079206F6274656E657220313030252064652063656C6572696461642079206C65766974616369C3B36E2E005469656E657320756E612070726F626162696C696461642064652067616E61722056656E646176616C20667572696F736F2079206F6274656E657220313030252064652063656C6572696461642079206C65766974616369C3B36E2E00, 35435), -- Spell
(3776013982, 335642, 'esMX', 0x00476F6C70656120616C20656E656D69676F2079206C6520696E666C6967652024733125206465206461C3B16F2064652061726D6120636F6D6F206461C3B16F206465206C617320736F6D6272617320792061756D656E746120656C206461C3B16F20696E666C696769646F20756E202473322520647572616E74652024642E004461C3B16F2061756D656E7461646F20756E202473322500, 35435), -- Spell
(3776013982, 327254, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 264663, 'esMX', 0x506173697661206465204665726F63696461640054C3BA2079207475206D6173636F7461206F627469656E656E20756E202473312520646520726F626F20646520766964612E00456C20726F626F20646520766964612061756D656E746120756E20247732252E00, 35435), -- Spell
(3776013982, 302166, 'esMX', 0x00456C2043617A61646F722D61736573696E6F20696E766F6361207265667565727A6F73206465206C6120436975646164206465204D6563616CC3B3706F6C69732E0000, 35435), -- Spell
(3776013982, 293072, 'esMX', 0x004372656120756E2063686172636F206F736375726F20717565206472656E6120246F3220702E20646520636F726475726120647572616E74652024642061206C6F7320656E656D69676F732071756520656E7472616E20656E20C3A96C2E005069657264652024733220702E20646520636F726475726120636164612024743220246C736567756E646F3A736567756E646F733B2E00, 35435), -- Spell
(3776013982, 311204, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324870, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646465365766572696461647C720D0A24407370656C6C646573633331353535380000, 35435), -- Spell
(3776013982, 324874, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630390000, 35435), -- Spell
(3776013982, 324865, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353535330000, 35435), -- Spell
(3776013982, 335149, 'esMX', 0x0047616E616E636961206465207265707574616369C3B36E206465205772617468206F6620746865204C696368204B696E6720706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A2043726F6E6F7669616A65206465205772617468206F6620746865204C696368204B696E677C720D0A0D0A47616E616E636961206465207265707574616369C3B36E206465205772617468206F6620746865204C696368204B696E6720706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E00, 35435), -- Spell
(3776013982, 324856, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C6346464646464646464174726176657361727C720D0A24407370656C6C646573633331353238310000, 35435), -- Spell
(3776013982, 324896, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C6346464646464646464163656C6572616369C3B36E2064652070756C736F7C720D0A24407370656C6C646573633331383236360000, 35435), -- Spell
(3776013982, 321714, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324897, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C6346464646464646464163656C6572616369C3B36E2064652070756C736F7C720D0A24407370656C6C646573633331383439320000, 35435), -- Spell
(2230237587, 1188, 'esMX', 0x436975646164206465204D6563616CC3B3706F6C69730096010000250600000000000000, 35435), -- UiMapGroupMember
(3776013982, 324895, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630370000, 35435), -- Spell
(3776013982, 115546, 'esMX', 0x0050726F766F636120616C206F626A657469766F2079206861636520717565207365206D75657661206861636961207469206120756E612076656C6F63696461642061756D656E7461646120756E20243131363138396D33252E243F733131353331355B0D0A0D0A4573746120686162696C696461642070756564652066696A6172736520656E20747520457374617475612064656C2042756579204E6567726F2C206C6F207175652070726F766F636120656C206D69736D6F2065666563746F20656E20746F646F73206C6F7320656E656D69676F7320656E20756E20726164696F20646520243131383633354131206D206465206C6120657374617475612E5D5B5D0000, 35435), -- Spell
(3776013982, 324837, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646C38D6D70657475206D6F7274616C7C720D0A24407370656C6C646573633331383439330000, 35435), -- Spell
(3776013982, 324868, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646465365766572696461647C720D0A24407370656C6C646573633331353535370000, 35435), -- Spell
(3205218938, 41793, 'esMX', 0x4755494C445F46494E4445525F504F5354494E475F4558504952454400C2A14C61207075626C6963616369C3B36E20686120636164756361646F210001, 35435), -- GlobalStrings
(2230237587, 1162, 'esMX', 0x436975646164206465204D6563616CC3B3706F6C6973008F010000D90500000400000000, 35435), -- UiMapGroupMember
(2035710060, 7072, 'esMX', 0x457370C3AD72697475206C6F6120656E736F6D6272656369646F004C612073756D61207361636572646F74697361204D6172276C69207574696C697A61206573746120666163756C746164206D69656E7472617320657374C3A120706F7365C3AD646120706F7220656C20657370C3AD726974752064652047617261276A616C2E0D0A0D0A4C612073756D61207361636572646F74697361204D6172276C6920696E766F636120756E20657370C3AD72697475206C6F6120656E736F6D6272656369646F20656E2073752075626963616369C3B36E2E20456C20657370C3AD726974752073652066696A6120656E20756E206A756761646F7220616C6561746F72696F2079206C6F20706572736967756520647572616E74652024313337333935642E20536920656C20657370C3AD72697475207365206163657263612061206D656E6F7320646520243133373339304131206D2064656C206A756761646F722C206C6F206D6174612E0D0A0D0A536920656C20657370C3AD72697475207369677565207669766F20747261732024313337333935642C2073616C74612061207375206F626A657469766F20616C20696E7374616E74652079206C6F206D6174612E0030031C8A1B0000A11B02000000000000000000000000DFA209000200320013, 35435), -- JournalEncounterSection
(3776013982, 324875, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F5741524C4F434B5F44454D4F4E534F554C2E424C503A32347C74207C6346464646464646464576617369766F7C720D0A24407370656C6C646573633331353630380000, 35435), -- Spell
(3776013982, 256134, 'esMX', 0x00526564756365206E6F7461626C656D656E7465206C612063616E7469646164206465206D6174657269616C6573206E656365736172696F73207061726120666162726963617220756E206D6F746F722073757065726361726761646F2E0000, 35435), -- Spell
(3776013982, 324907, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374616369C3B36E2063726570757363756C61727C720D0A24407370656C6C646573633331383437380000, 35435), -- Spell
(3776013982, 335150, 'esMX', 0x0047616E616E636961206465207265707574616369C3B36E2064652043617461636C79736D20706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A2043726F6E6F7669616A652064652043617461636C79736D7C720D0A0D0A47616E616E636961206465207265707574616369C3B36E2064652043617461636C79736D20706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E00, 35435), -- Spell
(3776013982, 321428, 'esMX', 0x00496E666C6967652024733120702E206465206461C3B16F206465206C617320736F6D62726173206120746F646F73206C6F73206A756761646F72657320636164612024743120732E00496E666C6967652024733120702E206465206461C3B16F206465206C617320736F6D6272617320636164612024743120732E00, 35435), -- Spell
(3776013982, 324858, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D61657374726F206578706572746F7C720D0A24407370656C6C646573633331353533310000, 35435), -- Spell
(3776013982, 306259, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 335152, 'esMX', 0x0047616E616E636961206465207265707574616369C3B36E206465205761726C6F726473206F6620447261656E6F7220706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A2043726F6E6F7669616A65206465205761726C6F726473206F6620447261656E6F727C720D0A0D0A47616E616E636961206465207265707574616369C3B36E206465205761726C6F726473206F6620447261656E6F7220706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E00, 35435), -- Spell
(3776013982, 324880, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653756363696F6E61646F727C720D0A24407370656C6C646573633331353539320000, 35435), -- Spell
(3776013982, 324879, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653756363696F6E61646F727C720D0A24407370656C6C646573633331353539310000, 35435), -- Spell
(3776013982, 300748, 'esMX', 0x000000, 35435), -- Spell
(20077728, 396607, 'esMX', 0x000001000000474302000001006FD6, 35435), -- QuestObjective
(3776013982, 325947, 'esMX', 0x0024407370656C6C646573633239363832300000, 35435), -- Spell
(3776013982, 321201, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324903, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C63464646464646464656657264616420696E656661626C657C720D0A24407370656C6C646573633331383330330000, 35435), -- Spell
(3776013982, 313040, 'esMX', 0x004162726520756E612066616C6C6120656E20656C20656E7472616D61646F206465206C61207265616C6964616420717565206472656E612024333133303430733220702E20646520636F7264757261206520696E666C6967652024333133303430733120702E206465206461C3B16F206465206C617320736F6D62726173206120746F646F73206C6F7320656E656D69676F732E0D0A0D0A45737465206167756A65726F2063726561207C352024407370656C6C6E616D6533313736323720647572616E74652024333137363334442E0000, 35435), -- Spell
(3205218938, 42645, 'esMX', 0x424E45545F4552524F525F34303031310028434E204F6E6C7929205365636F6E6461727920506172656E74616C20436F6E74726F6C0002, 35435), -- GlobalStrings
(3776013982, 294003, 'esMX', 0x00004C6F637572612064697369706164612E0D0A526567656E6572616E646F20636F72647572612E00, 35435), -- Spell
(3776013982, 324891, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C6C617320696E66696E697461737C720D0A24407370656C6C646573633331383438380000, 35435), -- Spell
(3776013982, 154253, 'esMX', 0x00556E204C6F626F2047C3A96C69646F20617975646172C3A120616C67756E61732076656365732061206C6F732063616D70656F6E65732064656C20636C616E204C6F626F2047C3A96C69646F00556E204C6F626F2047C3A96C69646F20617975646172C3A120616C67756E61732076656365732061206C6F732063616D70656F6E65732064656C20636C616E204C6F626F2047C3A96C69646F00, 35435), -- Spell
(3776013982, 324864, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F415243414E455F415243414E45544143544943532E424C503A32347C74207C63464646464646464656657273C3A174696C7C720D0A24407370656C6C646573633331353535320000, 35435), -- Spell
(3776013982, 316661, 'esMX', 0x0024407370656C6C646573633331363635310000, 35435), -- Spell
(3776013982, 275496, 'esMX', 0x0053656E74656E63696120696E666C696765206461C3B16F2061646963696F6E616C206375616E646F20747520706F7263656E74616A652064652073616C75642073757065726120656C2064656C206F626A657469766F2E20507565646520696E666C696769722068617374612024733120702E206465206461C3B16F2E0000, 35435), -- Spell
(3205218938, 41791, 'esMX', 0x4755494C445F46494E4445525F504F5354494E475F474F494E475F544F5F455850495245004C61207075626C6963616369C3B36E2063616475636120656E3A0001, 35435), -- GlobalStrings
(3776013982, 154275, 'esMX', 0x000000, 35435), -- Spell
(3205218938, 41794, 'esMX', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952454400C2A14C61207075626C6963616369C3B36E20686120636164756361646F210001, 35435), -- GlobalStrings
(3776013982, 324887, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F424F53535F594F47475341524F4E5F30312E424C503A32347C74207C63464646464646464645787472656D69646164207265746F72636964617C720D0A24407370656C6C646573633331383438320000, 35435), -- Spell
(3776013982, 296464, 'esMX', 0x004C6120556E69646164206465206F7072657369C3B36E2061C3A972656120484B2D38207472616E73706F736963696F6E6120756E696461646573206465207265667565727A6F206465736465206C6120436975646164206465204D6563616CC3B3706F6C69732E0000, 35435), -- Spell
(3776013982, 299937, 'esMX', 0x00456C2043617A61646F722D61736573696E6F20696E766F6361207265667565727A6F73206465206C6120436975646164206465204D6563616CC3B3706F6C69732E0000, 35435), -- Spell
(3776013982, 324852, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F4D4147455F4E455448455257494E4450524553454E43452E424C503A32347C74207C6346464646464646464578706564697469766F7C720D0A24407370656C6C646573633331353534350000, 35435), -- Spell
(3776013982, 154259, 'esMX', 0x005469656E657320656C20657370C3AD726974752064656C206C6F626F2C206C6F207175652061756D656E74612074752076656C6F6369646164206465206361727265726120656E2024733125206D69656E7472617320657374C3A97320656E20437265737461205069726F6672C3AD6F2E0056656C6F636964616420646520636172726572612061756D656E7461646120756E2024733125206D69656E7472617320657374C3A97320656E20437265737461205069726F6672C3AD6F2E00, 35435), -- Spell
(3776013982, 304086, 'esMX', 0x4573656E63696120646520617A6572697461004D69656E7472617320657374C3A17320617475726469646F2C20656C2062656E65666963696F20646566656E7369766F20646520747520766572736174696C696461642061756D656E746120756E20243330343737357331252E0000, 35435), -- Spell
(3776013982, 324845, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566163C3AD6F207265736F6E616E74657C720D0A24407370656C6C646573633331383438360000, 35435), -- Spell
(3776013982, 155343, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324906, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374616369C3B36E2063726570757363756C61727C720D0A24407370656C6C646573633331383437370000, 35435), -- Spell
(2035710060, 7069, 'esMX', 0x497261206465206C6F73206C6F61004C612073756D61207361636572646F74697361204D6172276C6920676F6C706561206120756E206A756761646F7220636F6E206C6120497261206465206C6F73206C6F612C206C6F2071756520696E666C6967652024313337333434733120702E206465206461C3B16F205361677261646F2E003003198A1B00009E1B020000000000000000000000002413020000004000FF, 35435), -- JournalEncounterSection
(3776013982, 155334, 'esMX', 0x00457374C3A17320656E2073696E746F6EC3AD6120636F6E20656C206869656C6F206465206C61207A6F6E612E20412076656365732074752070726573656E63696120636F6E67656C6120612074757320656E656D69676F732E00412076656365732074752070726573656E63696120636F6E67656C6120612074757320656E656D69676F732E00, 35435), -- Spell
(3776013982, 324902, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F49726F6E4D616964656E735F436F72727570746564426C6F6F642E626C703A32347C74207C6346464646464646464865726964612073616E6772616E74657C720D0A24407370656C6C646573633331383237320000, 35435), -- Spell
(3776013982, 321200, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324904, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C494E565F57616E645F31485F4E7A6F7468526169645F445F30312E626C703A32347C74207C63464646464646464656657264616420696E656661626C657C720D0A24407370656C6C646573633331383438340000, 35435), -- Spell
(3776013982, 331973, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 325946, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 321748, 'esMX', 0x0050726F766F63612071756520656C206F626A657469766F2061637475616C20636C6F6E6520616C207461756D61747572676F2E0000, 35435), -- Spell
(3776013982, 324882, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F534841444F575F5348414445534F464441524B4E4553532E424C503A32347C74207C63464646464646464652697475616C2064656C20566163C3AD6F7C720D0A24407370656C6C646573633331383238360000, 35435), -- Spell
(3776013982, 324860, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D61657374726F206578706572746F7C720D0A24407370656C6C646573633331353533300000, 35435), -- Spell
(3776013982, 324850, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566163C3AD6F207265736F6E616E74657C720D0A24407370656C6C646573633331383238300000, 35435), -- Spell
(3776013982, 324899, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5350454C4C5F4E41545552455F464F43555345444D494E442E424C503A32347C74207C6346464646464646464D656E74652061677564617C720D0A24407370656C6C646573633331383236390000, 35435), -- Spell
(3205218938, 42500, 'esMX', 0x47524F55505F46494E4445525F4445534C4953545F5741524E494E475F454449545F4C495354494E4700456469746172206C697374610001, 35435), -- GlobalStrings
(3776013982, 324680, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646C38D6D70657475206D6F7274616C7C720D0A24407370656C6C646573633331383236380000, 35435), -- Spell
(3776013982, 155346, 'esMX', 0x0050657269C3B3646963616D656E7465207465207472616E73666F726D6172C3A17320656E20756E20706F6465726F736F206F67726F206465205069726F6672C3AD6F2C206C6F20717565207465206F746F726761202431353533333773322520646520726573697374656E636961206D656A6F726164612061206C6F732065666563746F73206E6F6369766F732E0050657269C3B3646963616D656E7465207465207472616E73666F726D6172C3A17320656E20756E20706F6465726F736F206F67726F206465205069726F6672C3AD6F2C206C6F20717565207465206F746F726761202431353533333773322520646520726573697374656E636961206D656A6F726164612061206C6F732065666563746F73206E6F6369766F732E00, 35435), -- Spell
(3776013982, 294479, 'esMX', 0x000042757363616E646F2061727465666163746F7320616E746967756F732E00, 35435), -- Spell
(3776013982, 328136, 'esMX', 0x0041756D656E746120756E2024733125206C61207265707574616369C3B36E206F6274656E69646120656E206C61732049736C6173205175656272616461732C2041726775732C204B756C2054697261732C205A616E64616C61722079204E617A6A617461722E004F627469656E657320756E2024733125206DC3A173206465207265707574616369C3B36E20656E206C61732049736C6173205175656272616461732C2041726775732C204B756C2054697261732C205A616E64616C61722079204E617A6A617461722E00, 35435), -- Spell
(3776013982, 324861, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F524F4755455F53494E495354455243414C4C494E472E424C503A32347C74207C6346464646464646464D61657374726F206578706572746F7C720D0A24407370656C6C646573633331353532390000, 35435), -- Spell
(3205218938, 42497, 'esMX', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F5449544C450054652068616E20617363656E6469646F2061204CC3AD6465727C54496E746572666163655C5C47726F75704672616D655C5C55492D47726F75702D4C656164657249636F6E3A303A303A303A2D317C74207C6E7C6E7C636666666664323030C2BF5175696572657320766F6C766572206120696E636C756972206120747520677275706F3F7C727C6E25737C6E0001, 35435), -- GlobalStrings
(3776013982, 335151, 'esMX', 0x0047616E616E636961206465207265707574616369C3B36E206465204D69737473206F662050616E646172696120706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A2043726F6E6F7669616A65206465204D69737473206F662050616E64617269617C720D0A0D0A47616E616E636961206465207265707574616369C3B36E206465204D69737473206F662050616E646172696120706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E00, 35435), -- Spell
(3776013982, 256133, 'esMX', 0x00526564756365206C612063616E7469646164206465206D6174657269616C6573206E656365736172696F73207061726120666162726963617220756E206D6F746F722073757065726361726761646F2E0000, 35435), -- Spell
(2901650891, 1582, 'esMX', 0x53756D61207361636572646F74697361204D6172276C6900002E060000300372BA0000000000000309000000, 35435), -- JournalEncounterCreature
(2035710060, 7071, 'esMX', 0x497261206465206C6F73206C6F61004C612073756D61207361636572646F74697361204D6172276C69207574696C697A61206573746120666163756C746164206D69656E7472617320657374C3A120706F7365C3AD646120706F7220656C20657370C3AD726974752064652047617261276A616C2E0D0A0D0A4C612073756D61207361636572646F74697361204D6172276C6920676F6C706561206120756E206A756761646F7220636F6E206C6120497261206465206C6F73206C6F612C206C6F2071756520696E666C6967652024313337333437733120702E206465206461C3B16F206465206C617320536F6D627261732E0030031B8A1B0000A01B02000000000000000000000000BC62090000004000FF, 35435), -- JournalEncounterSection
(3776013982, 324889, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F44525549445F5354415246414C4C2E424C503A32347C74207C63464646464646464645737472656C6C617320696E66696E697461737C720D0A24407370656C6C646573633331383237340000, 35435), -- Spell
(3776013982, 324898, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F57415252494F525F424C4F4F444652454E5A592E424C503A32347C74207C6346464646464646464163656C6572616369C3B36E2064652070756C736F7C720D0A24407370656C6C646573633331383439360000, 35435), -- Spell
(3776013982, 324866, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F5052494553545F534841444F575941505041524954494F4E2E424C503A32347C74207C6346464646464646465365766572696461647C720D0A24407370656C6C646573633331353535340000, 35435), -- Spell
(3776013982, 300798, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 292579, 'esMX', 0x0053692068617920756E6120686F67756572612063657263616E612C20756E206176656E74757265726F20707565646520656E63656E6465726C612E0053692068617920756E6120686F67756572612063657263616E612C20756E206176656E74757265726F20707565646520656E63656E6465726C612E00, 35435), -- Spell
(3776013982, 337612, 'esMX', 0x004E275A6F7468207265636C616D61207475206573656E636961207920746520696E666C69676520756E206461C3B16F206571756976616C656E7465206120756E20247331252064652074752073616C7564206DC3A178696D612063616461202474312073206D69656E7472617320657374C3A17320656E20636F6D626174652E20456C2066696E207365206163657263612E00526563696269656E646F20756E206461C3B16F206571756976616C656E7465206120756E20247731252064652074752073616C7564206DC3A178696D612063616461202474312073206D69656E7472617320657374C3A17320656E20636F6D626174652E00, 35435), -- Spell
(3776013982, 324877, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F536861646F775F4C696665447261696E30325F707572706C652E626C703A32347C74207C63464646464646464653756363696F6E61646F727C720D0A24407370656C6C646573633331353539300000, 35435), -- Spell
(3776013982, 324848, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F5072696573745F566F6964456E74726F70792E626C703A32347C74207C634646464646464646566163C3AD6F207265736F6E616E74657C720D0A24407370656C6C646573633331383438350000, 35435), -- Spell
(3776013982, 324857, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C6346464646464646464174726176657361727C720D0A24407370656C6C646573633331353237370000, 35435), -- Spell
(3776013982, 324905, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C5370656C6C5F5072696573745F566F6964536561722E626C703A32347C74207C634646464646464646446576617374616369C3B36E2063726570757363756C61727C720D0A24407370656C6C646573633331383237360000, 35435), -- Spell
(3776013982, 324839, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4162696C6974795F48756E7465725F526170746F72537472696B652E626C703A32347C74207C634646464646464646C38D6D70657475206D6F7274616C7C720D0A24407370656C6C646573633331383439370000, 35435), -- Spell
(3776013982, 315958, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 335148, 'esMX', 0x0047616E616E636961206465207265707574616369C3B36E206465204275726E696E67204372757361646520706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E007C6346463030414139394576656E746F20646520626F6E69666963616369C3B36E3A2043726F6E6F7669616A65206465204275726E696E6720437275736164657C720D0A0D0A47616E616E636961206465207265707574616369C3B36E206465204275726E696E67204372757361646520706F7220636F6D626174652079206D6973696F6E65732061756D656E7461646120756E20247331252E00, 35435), -- Spell
(3205218938, 41792, 'esMX', 0x434F4D4D554E4954595F46494E4445525F504F5354494E475F4558504952455F534F4F4E004C61207075626C6963616369C3B36E2063616475636120656E3A0001, 35435), -- GlobalStrings
(3776013982, 300692, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 274909, 'esMX', 0x005061746164612064656C20736F6C206E616369656E74652073616E61206120746F646F73206C6F7320616C6961646F7320636F6E207475204E6965626C612072656E6F7661646F72612C204E6965626C6120656E766F6C76656E7465206F204675656E7465206465206573656E63696120706F722024323734393132733120702E20792065787469656E64652065736F732065666563746F7320247331207320686173746120756E202473322520646520737520647572616369C3B36E206F726967696E616C2E0000, 35435), -- Spell
(2035710060, 7050, 'esMX', 0x53756D61207361636572646F74697361204D6172276C69000030031800009D1B00000172BA000000000000000000000000000001000000FF, 35435), -- JournalEncounterSection
(3776013982, 120679, 'esMX', 0x00496E766F636120756E61206265737469612073616C76616A6520706F6465726F73612071756520617461636120616C206F626A657469766F207920727567652C206C6F207175652061756D656E74612074752063656C65726964616420756E202432383130333673312520647572616E74652024642E0000, 35435), -- Spell
(3776013982, 293777, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 324854, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C414348494556454D454E545F50524F46455353494F4E5F46495348494E475F46494E44464953482E424C503A32347C74207C6346464646464646464174726176657361727C720D0A24407370656C6C646573633331353238320000, 35435), -- Spell
(3776013982, 324893, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6964616420696D706574756F73617C720D0A24407370656C6C646573633331383439350000, 35435), -- Spell
(3776013982, 291435, 'esMX', 0x004372656120756E2063686172636F206F736375726F20717565206472656E6120246F3220702E20646520636F726475726120647572616E74652024642061206C6F7320656E656D69676F732071756520656E7472616E20656E20C3A96C2E005069657264652024733220702E20646520636F726475726120636164612024743220246C736567756E646F3A736567756E646F733B2E00, 35435), -- Spell
(3205218938, 42496, 'esMX', 0x47524F55505F46494E4445525F44454C4953545F5741524E494E475F53554254455854007C6E257320686173746120616E756C616369C3B36E206175746F6DC3A17469636120646520696E73637269706369C3B36E0001, 35435), -- GlobalStrings
(3776013982, 154274, 'esMX', 0x000000, 35435), -- Spell
(3776013982, 337816, 'esMX', 0x0024407370656C6C646573633333373631320000, 35435), -- Spell
(3776013982, 324894, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6964616420696D706574756F73617C720D0A24407370656C6C646573633331383439390000, 35435), -- Spell
(3776013982, 332950, 'esMX', 0x0000596F7572206162696C697469657320686176652061206368616E636520746F206465616C2024403930353773312064616D6167652E00, 35435), -- Spell
(3776013982, 324892, 'esMX', 0x00496D6275796520756E206F626A65746F20636F6E20756E612063657061206D616C69676E61206465206C6120636F727275706369C3B36E206465204E275A6F74682E0D0A0D0A0D0A7C54696E746572666163655C69636F6E735C4142494C4954595F48554E5445525F4F4E45574954484E41545552452E424C503A32347C74207C634646464646464646566974616C6964616420696D706574756F73617C720D0A24407370656C6C646573633331383237300000, 35435), -- Spell
(2948698321, 259, 'esMX', 0xB50278B84158ABDF, 35435), -- TactKeyLookup
(2948698321, 249, 'esMX', 0xD6968DCA7ACF9DD1, 35435), -- TactKeyLookup
(603412935, 28646, 'esMX', 0xE88C8EE9BE9F0004, 35435), -- ChatProfanity
(603412935, 28664, 'esMX', 0xE6899BE9BAA6E9838E0004, 35435), -- ChatProfanity
(603412935, 28654, 'esMX', 0xE4BABAE6B091E6A380E5AF9FE999A20004, 35435), -- ChatProfanity
(603412935, 28649, 'esMX', 0xE6B9BFE7A9B40004, 35435), -- ChatProfanity
(603412935, 28650, 'esMX', 0x4C69626572617465484B0004, 35435), -- ChatProfanity
(603412935, 28658, 'esMX', 0xE794B2E7B49AE688A6E78AAF0004, 35435), -- ChatProfanity
(603412935, 28656, 'esMX', 0xE99988E696B9E5AE89E7949F0004, 35435), -- ChatProfanity
(603412935, 28662, 'esMX', 0xE58D81E9878CE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(603412935, 28644, 'esMX', 0xE689A9E998B4E599A80004, 35435), -- ChatProfanity
(603412935, 28645, 'esMX', 0xE5BEB7E5AFB8E88C8E0004, 35435), -- ChatProfanity
(603412935, 28648, 'esMX', 0xE99B8FE5A5B30004, 35435), -- ChatProfanity
(603412935, 28653, 'esMX', 0xE994A4E995B0E5B8AE0004, 35435), -- ChatProfanity
(603412935, 28647, 'esMX', 0xE99CB2E998B4E9B8A10004, 35435), -- ChatProfanity
(603412935, 28657, 'esMX', 0xE4BD95E4BF8AE4BB810004, 35435), -- ChatProfanity
(603412935, 28652, 'esMX', 0xE5A3B9E59C8BE585A9E8A3BD0004, 35435), -- ChatProfanity
(603412935, 28655, 'esMX', 0xE69C80E9AB98E4BABAE6B0910004, 35435), -- ChatProfanity
(603412935, 28659, 'esMX', 0xE696B0E4B8ADE59BBDE88194E982A60004, 35435), -- ChatProfanity
(603412935, 28661, 'esMX', 0xE684BFE88DA3E58589E5BD92E9A699E6B8AF0004, 35435), -- ChatProfanity
(603412935, 28660, 'esMX', 0xE88194E982A6E5AEA3E8A8800004, 35435), -- ChatProfanity
(603412935, 28651, 'esMX', 0x66726565484B0004, 35435), -- ChatProfanity
(603412935, 28663, 'esMX', 0x3130E9878CE5B1B1E8B7AFE4B88DE68DA2E882A90004, 35435), -- ChatProfanity
(1181150530, 307455, 'esMX', 0x020000005B2906000AD50100, 35435), -- SpellVisualKitEffect
(25144992, 2203, 'esMX', 0x201A0000000000000000000001000000CB0100000000000013000000FFFFFFFF0000000000000000, 35435), -- BeamEffect
(4033975491, 403803, 'esMX', 0x0000704100000000000000410000000000000000000000005B290600308A1300000000000000000000000000000000000000000000000000000000204100000000FFFFFFFFFFFF00000000000000000000000AD50100, 35435), -- SpellVisualKitModelAttach
(4033975491, 404117, 'esMX', 0x00000000000000000000C03F000000000000000000000000952A0600D9891300000000000000000000000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000009D50100, 35435), -- SpellVisualKitModelAttach
(517656225, 6688, 'esMX', 0x0000803F00000000E17AD43F000000000000000100001A00000000000303000000000000000000000000A4707D3F0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000FFFF4742000000000000000000000000000000000000C8430000964300000040FFFFFFFF02038030E13E022B873D0AD7233C636D2400000020400000003F69000000000000000000803F0000803F6E186F180000000000000000000000000000000000000000403F3333B33E6666E63E0000000000000000000000000000000000000000000000000000000000000000000000008D5E1E008C5E1E008C5E1E00, 35435), -- SpellChainEffects
(4146370265, 91772, 'esMX', 0x0000A0400000000000002041000000000000000000000000000000000000000022130000000000000000000000000000000000000000000000000000000000000000, 35435); -- SpellVisual

