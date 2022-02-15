DELETE FROM `broadcast_text_locale` WHERE `locale` = 'esES' AND `ID` IN (209968, 208581);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(209968, 'esES', '', 'Saludos, $gamigo:amiga;. ¿Te interesan las piedras angulares?', 38134),
(208581, 'esES', 'Saludos, NOMBRE DE USUARIO. Espero que estés teniendo un día GENERAR ADJETIVO POSITIVO ALEATORIO.', '', 38134);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'esES', 'Gafas de sol con bisutería', 38134);

DELETE FROM `currency_types_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1191, 'esES', 'Valor', 'Una moneda empleada para aumentar el poder de objetos de las mazmorras míticas.', 38134),
(1602, 'esES', 'Conquista', 'Se obtiene en actividades JcJ puntuadas. Gástalo para adquirir equipo en Oribos.', 38134),
(1828, 'esES', 'Ceniza de alma', 'Una fuente de energía pura que se halla en Torghast. Se usa para hacer funcionar la Cámara del Grabador de Runas.', 38134);

DELETE FROM `spell_name_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(328547, 'esES', 'Púa ósea dentada', 38134),
(335718, 'esES', 'Represalias', 38134),
(340882, 'esES', 'Llamar a Bolsa de Gas', 38134),
(351967, 'esES', 'Llamar a Tumorrosa', 38134),
(320914, 'esES', 'Reloj de arena de cronomántico', 38134),
(350249, 'esES', 'Distorsión temporal', 38134),
(320740, 'esES', 'Fijar', 38134),
(335161, 'esES', 'Escape de ánima', 38134),
(340433, 'esES', 'Bendición del Salto del Pecado', 38134),
(220358, 'esES', 'Golpes de ciclón', 38134),
(352329, 'esES', '[DNT] Learn Bananas', 38134),
(163708, 'esES', 'Fogata vinculada', 38134),
(34477, 'esES', 'Redirección', 38134),
(202335, 'esES', 'Barril doble', 38134),
(209584, 'esES', 'Té de enfoque zen', 38134),
(235219, 'esES', 'Mordedura de frío', 38134),
(243435, 'esES', 'Brebaje reconstituyente', 38134),
(248518, 'esES', 'Interponer', 38134),
(321995, 'esES', 'Presencia hipotérmica', 38134),
(327193, 'esES', 'Momento de gloria', 38134),
(352497, 'esES', '[DNT] Teleport', 38134),
(294587, 'esES', 'Púas de Obleron x2', 38134),
(294588, 'esES', 'Púas de Obleron x3', 38134),
(322841, 'esES', 'Alafuria', 38134),
(324919, 'esES', 'Alafuria', 38134),
(352816, 'esES', '[DNT] Grant Keystone', 38134),
(341220, 'esES', 'Ballesta jurafauces', 38134),
(321136, 'esES', 'Luz brillante', 38134),
(255260, 'esES', 'Marca del caos', 38134),
(281242, 'esES', 'Marca del caos', 38134),
(337541, 'esES', 'Espíritu de la Llama Oscura', 38134),
(71, 'esES', 'Vanguardia', 38134),
(48263, 'esES', 'Veterano de la Tercera Guerra', 38134),
(245013, 'esES', 'Equilibrio del maestro cervecero', 38134),
(300346, 'esES', 'Adepto osuno', 38134),
(316714, 'esES', 'Veterano de la Tercera Guerra', 38134),
(319278, 'esES', 'Veterano de la Cuarta Guerra', 38134),
(353367, 'esES', 'Égida de Luz', 38134),
(337334, 'esES', 'Trecho Celestial de Keefer', 38134),
(336061, 'esES', 'Carga de babas', 38134),
(340271, 'esES', 'Contagio coagulado', 38134),
(327332, 'esES', 'Imbuir arma', 38134),
(45525, 'esES', 'Intelecto Arcano', 38134),
(354135, 'esES', 'Bottom Barrier Visual', 38134),
(321828, 'esES', 'Palmas palmitas', 38134),
(321832, 'esES', 'Balón prisionero', 38134),
(326180, 'esES', 'Marca de congelación', 38134),
(322416, 'esES', 'Fractura rocosa', 38134);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91079, 'esES', 'Login with Bananas license (Charity Pet 2021)', 38134),
(91080, 'esES', '', 38134),
(91081, 'esES', 'Earn character-level Bananas achievement', 38134),
(91082, 'esES', '', 38134),
(91386, 'esES', 'Ve\'nari reputation is Apprehensive', 38134),
(91388, 'esES', 'Ve\'nari reputation is Tentative', 38134),
(91390, 'esES', 'Ve\'nari reputation is Ambivalent', 38134),
(91392, 'esES', 'Ve\'nari reputation is Cordial', 38134),
(91393, 'esES', '', 38134),
(91503, 'esES', 'Do You Have All Rank 1s in a Covenant Sanctum?', 38134),
(91504, 'esES', 'Login test for backporting of \"do you have all level 1 buildings\"', 38134),
(91505, 'esES', '', 38134),
(91506, 'esES', 'Do You Have All Rank 2s in a Covenant Sanctum?', 38134),
(91507, 'esES', 'Login test for backporting of \"do you have all level 2 buildings\"', 38134),
(91508, 'esES', '', 38134),
(91509, 'esES', 'Do You Have All Rank 3s in a Covenant Sanctum?', 38134),
(91510, 'esES', 'Login test for backporting of \"do you have all level 3 buildings\"', 38134),
(91511, 'esES', '', 38134),
(91387, 'esES', 'La reputación de Ve\'nari es Aprensiva.', 38134),
(91389, 'esES', 'La reputación de Ve\'nari es Indecisa.', 38134),
(91391, 'esES', 'La reputación de Ve\'nari es Ambivalente.', 38134),
(87404, 'esES', 'Gana encuentros JcJ puntuados durante la temporada 1 de Shadowlands con un índice de 1000 o más', 38134),
(87408, 'esES', 'Gana encuentros JcJ puntuados durante la temporada 1 de Shadowlands con un índice de 1000 o más', 38134);

DELETE FROM `specialization_spells_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `specialization_spells_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(5164, 'esES', '', 38134),
(5369, 'esES', '', 38134),
(5480, 'esES', '', 38134),
(6271, 'esES', '', 38134),
(6285, 'esES', '', 38134),
(6286, 'esES', '', 38134),
(6287, 'esES', '', 38134),
(6288, 'esES', '', 38134),
(6289, 'esES', '', 38134),
(6292, 'esES', '', 38134),
(6293, 'esES', '', 38134),
(6294, 'esES', '', 38134),
(6295, 'esES', '', 38134),
(6298, 'esES', '', 38134),
(6299, 'esES', '', 38134),
(6306, 'esES', '', 38134),
(6377, 'esES', '', 38134),
(6455, 'esES', '', 38134),
(6457, 'esES', '', 38134),
(6463, 'esES', '', 38134),
(6478, 'esES', '', 38134),
(6531, 'esES', '', 38134),
(6532, 'esES', '', 38134),
(6533, 'esES', '', 38134),
(6534, 'esES', '', 38134),
(6535, 'esES', '', 38134),
(6608, 'esES', '', 38134),
(5262, 'esES', '', 38134),
(6609, 'esES', '', 38134),
(5320, 'esES', '', 38134),
(5521, 'esES', '', 38134),
(5580, 'esES', '', 38134),
(5938, 'esES', '', 38134),
(6113, 'esES', '', 38134),
(6114, 'esES', '', 38134),
(6193, 'esES', '', 38134),
(6195, 'esES', '', 38134),
(6324, 'esES', '', 38134),
(6400, 'esES', '', 38134),
(6434, 'esES', '', 38134),
(6447, 'esES', '', 38134),
(6515, 'esES', '', 38134),
(6516, 'esES', '', 38134),
(6610, 'esES', '', 38134);

DELETE FROM `battlemaster_list_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `battlemaster_list_locale` (`ID`, `locale`, `Name_lang`, `GameType_lang`, `ShortDescription_lang`, `LongDescription_lang`, `VerifiedBuild`) VALUES
(100, 'esES', 'CDB puntuado', '', '', '', 38134),
(866, 'esES', 'Todas las arenas', 'Camorra', '', '', 38134),
(1047, 'esES', 'Mugambala', '', '', '', 38134),
(1048, 'esES', 'Robotódromo', '', '', '', 38134),
(1049, 'esES', 'Puntagarfio', '', '', '', 38134),
(1050, 'esES', 'Dominio Empíreo', '', '', '', 38134);

DELETE FROM `area_table_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12876, 'esES', 'Trono del Prelado', 38134),
(12917, 'esES', 'Salto del Pecado', 38134),
(12924, 'esES', 'Ardenweald', 38134),
(13387, 'esES', 'Ardenweald', 38134),
(6852, 'esES', 'Terreno de Pruebas', 38134);

DELETE FROM `char_titles_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(679, 'esES', 'Barón %s', 'Barón %s', 38134),
(680, 'esES', 'Baronesa %s', 'Baronesa %s', 38134),
(682, 'esES', 'Conde %s', 'Conde %s', 38134),
(683, 'esES', 'Condesa %s', 'Condesa %s', 38134);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'esES', '', '', '', '', 'Gafas de sol con bisutería', 38134),
(180317, 'esES', '', '', '', '', 'Poción de sanación de almas', 38134),
(180318, 'esES', '', '', '', '', 'Poción de maná de almas', 38134),
(155622, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(159570, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164580, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164581, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164582, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164583, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164584, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164585, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164586, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164587, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164950, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164951, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164952, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164953, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164954, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164955, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(164956, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164957, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164958, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164959, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(168316, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(171090, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(171091, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(171092, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(171093, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(171095, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171096, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171097, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171098, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171099, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172890, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(172891, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(172892, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(172893, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(172894, 'esES', '', '', '', '', 'Sigilo de Belinato', 38134),
(172895, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172896, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172897, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172898, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172899, 'esES', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(186099, 'esES', 'Este artilugio provoca la aparición de una falla miniaturizada en tu equipo con la forma perfecta para una gema.', '', '', '', 'Aparato de realineación espacial', 38134),
(183122, 'esES', '', '', '', '', 'Capa de la Muerte', 38134),
(183131, 'esES', '', '', '', '', 'Rezón de estigia', 38134),
(183135, 'esES', '', '', '', '', 'Invocar al Caído', 38134),
(183136, 'esES', '', '', '', '', 'Rata de Las Fauces incendiaria', 38134),
(183141, 'esES', '', '', '', '', 'Magma de estigia', 38134),
(183165, 'esES', '', '', '', '', 'Ballesta jurafauces', 38134),
(183187, 'esES', '', '', '', '', 'Conjuro tejesombras', 38134),
(174876, 'esES', '', '', '', '', 'Ojo de N\'Zoth arrancado', 38134),
(187116, 'esES', '', '', '', '', 'Muñeco-diana', 38134);

DELETE FROM `map_difficulty_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `map_difficulty_locale` (`ID`, `locale`, `Message_lang`, `VerifiedBuild`) VALUES
(4775, 'esES', '', 38134);

DELETE FROM `mount_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1458, 'esES', 'Ancestro errante', '|cFFFFD200Promoción|r', 'Los ancestros son defensores incondicionales de los bosques de Azeroth, también conocidos por sus gloriosos mantos de hojas que cambian de color con las estaciones.', 38134);

DELETE FROM `player_condition_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(90553, 'esES', '', 38134),
(90651, 'esES', '', 38134),
(90652, 'esES', '', 38134),
(78581, 'esES', '', 38134),
(87399, 'esES', 'Requiere que Ve\'nari tenga una opinión Agradecida o superior sobre ti.', 38134);

DELETE FROM `achievement_locale` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(15010, 'esES', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Apprehensive standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Apprehensive [DNT]', '', 38134),
(15011, 'esES', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Tentative standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Tentative [DNT]', '', 38134),
(15012, 'esES', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Ambivalent standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Ambivalent [DNT]', '', 38134),
(15013, 'esES', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Cordial standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Cordial [DNT]', '', 38134),
(14340, 'esES', 'Derrota a un jefe en el camino de la ascensión.', 'El camino hacia la ascensión 1', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14342, 'esES', 'Derrota a tres jefes en el camino de la ascensión.', 'El camino hacia la ascensión 3', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14343, 'esES', 'Derrota a cinco jefes en el camino de la ascensión.', 'El camino hacia la ascensión 5', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14344, 'esES', 'Derrota a siete jefes en el camino de la ascensión.', 'El camino hacia la ascensión 7', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14345, 'esES', 'Derrota a 12 jefes en el camino de la ascensión.', 'El camino hacia la ascensión 12', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14346, 'esES', 'Derrota a 16 jefes en el camino de la ascensión.', 'El camino hacia la ascensión 16', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14348, 'esES', 'Derrota a 20 jefes en el camino de la ascensión.', 'El camino hacia la ascensión 20', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14349, 'esES', 'Derrota a 24 jefes en el camino de la ascensión.', 'El camino hacia la ascensión 24', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14351, 'esES', 'Derrota a 39 jefes en el camino de la ascensión.', 'El camino hacia la ascensión 39', 'Desbloquea más desafíos en el camino de la ascensión.', 38134),
(14502, 'esES', 'Supera las ocho primeras pruebas de lealtad.', 'En busca de la lealtad', '', 38134),
(14633, 'esES', 'Desbloquea el rango III de la red de transporte de tu sagrario.', 'Navegación maestra', '', 38134),
(14636, 'esES', 'Desbloquea el rango III de la mesa de mando de aventuras de tu sagrario.', 'Aventurero jefe', '', 38134),
(14637, 'esES', 'Desbloquea el rango V de la característica especial de tu sagrario.', 'La esencia de tu curia', '', 38134),
(14638, 'esES', 'Desbloquea todas las ubicaciones conectadas a tu conductor de ánima.', 'El ánima debe fluir', '', 38134),
(14639, 'esES', 'Usa tu conductor de ánima 50 veces.', 'Dedicación a la restauración', '', 38134),
(14670, 'esES', 'Incuba un espíritu de cada tipo en el Invernadero de la Reina.', 'Ese es el espíritu', '', 38134),
(14675, 'esES', 'Incuba un espíritu superior de cada tipo en el Invernadero de la Reina.', 'Médium', '', 38134),
(14676, 'esES', 'Incuba un espíritu divino de cada tipo en el Invernadero de la Reina.', 'Salvador de espíritus divinos', '', 38134),
(14677, 'esES', 'Completa cada una de las misiones de observación de espíritus de Falir en el Invernadero de la Reina.', 'Observaciones espirituales', '', 38134),
(14678, 'esES', 'Desbloquea los siguientes favores para tu Corte de Ascuas.', 'Favores de la corte', '', 38134),
(14679, 'esES', 'Desbloquea las siguientes mejoras para tu Corte de Ascuas.', 'Fiesta en palacio', '', 38134),
(14680, 'esES', 'Desbloquea los siguientes servicios para tu Corte de Ascuas.', 'Para todos los gustos', '', 38134),
(14681, 'esES', 'Entrena al dragador de tu Corte de Ascuas en las siguientes artes del oficio de mayordomo.', 'Academia de dragadores', '', 38134),
(14682, 'esES', 'Completa los siguientes logros de la Corte de Ascuas.', 'Heraldo de la fiesta', 'Título de recompensa: Heraldo de la fiesta', 38134),
(14683, 'esES', 'Desbloquea las siguientes opciones estéticas para tu dragador de la Corte de Ascuas.', 'Estilo de dragador', '', 38134),
(14684, 'esES', 'Completa todas las siguientes misiones de costura abominable.', 'Vidas abominables', '', 38134),
(14723, 'esES', 'Recibe a los siguientes invitados en tu Corte de Ascuas.', 'Déjanos invitarte', '', 38134),
(14724, 'esES', 'Ayuda a que los siguientes invitados alcancen el nivel de humor eufórico en tu Corte de Ascuas.', 'Complaciente', '', 38134),
(14725, 'esES', 'Celebra una Corte de Ascuas con cuatro invitados eufóricos.', 'Nos felices pocos', '', 38134),
(14726, 'esES', 'Celebra Cortes de Ascuas con los siguientes atributos en niveles superiores.', 'La juerga padre', '', 38134),
(14727, 'esES', 'Completa 10 eventos durante una sola Corte de Ascuas.', 'Maestro de ceremonias', '', 38134),
(14748, 'esES', 'Crea 25 de los siguientes accesorios de moda con la costura abominable.', 'Cambio de armario', '', 38134),
(14749, 'esES', 'Ayuda a Rendle a encontrar los siguientes sombreros para llevarlos a la Corte de Ascuas.', 'El gran día de Rendle', '', 38134),
(14751, 'esES', 'Construye cada uno de los siguientes ensamblajes con la costura abominable.', 'Ya estamos todos', 'Recompensa: montura tauralus elegido', 38134),
(14752, 'esES', 'Completa los siguientes logros de costura abominable.', 'Qué hacer cuando has muerto', 'Título de recompensa: Abominable y recompensa: montura tauralus elegido acorazado', 38134),
(14753, 'esES', 'Entrégale 100 envolturas imbuidas de ánima al invocador Gerard para ayudarlo a invocar a Visectus, espectro de guerra.', 'Pues ya está', '', 38134),
(14764, 'esES', 'Consigue el gran grisgrís con la ayuda de Chordy.', 'El gran grisgrís', '', 38134),
(14775, 'esES', 'Alcanza la reputación Exaltado con Marasmius.', 'Te aprecio un champiñón', 'Título de recompensa: El Divertido / La Divertida', 38134),
(14777, 'esES', 'Mejora todas las características del sagrario de tu curia.', 'Experto en restauración', '', 38134),
(14780, 'esES', 'Completa todas las misiones de meditación de Ohm en el Invernadero de la Reina y reconcíliate con tu calma interior.', 'Maestro de meditaciones', '', 38134),
(14789, 'esES', 'Completa la cadena de misiones de Lia para restaurar todos los espíritus animales en el Invernadero de la Reina.', 'Todos los espíritus cuentan', '', 38134),
(14833, 'esES', 'Crea los siguientes accesorios de moda con la costura abominable.', 'Moda abominable', '', 38134),
(14839, 'esES', 'Sube tres nexos de almas al nivel 60 en aventuras.', 'Compromiso con la aventura', '', 38134),
(14840, 'esES', 'Sube un aventurero al nivel 20.', 'Aventuras: Coger el truquillo', '', 38134),
(14841, 'esES', 'Sube un aventurero al nivel 40.', 'Aventuras: Ahora sí que sí', '', 38134),
(14842, 'esES', 'Sube un aventurero al nivel 60.', 'Aventuras: Fuerza y resistencia', '', 38134),
(14843, 'esES', 'Consigue a los 12 aventureros de tu curia.', 'Aventuras: Armonía de propósito', '', 38134),
(14844, 'esES', 'Completa las siguientes aventuras de Las Fauces.', 'Aventuras: Abriendo brecha', '', 38134),
(14845, 'esES', 'Completa una aventura.', 'Aventuras: Un paso en la dirección correcta', '', 38134),
(14846, 'esES', 'Completa 10 aventuras.', 'Aventuras: Hojas en el bosque', '', 38134),
(14847, 'esES', 'Completa 100 aventuras.', 'Aventuras: Escudo de las Tierras Sombrías', '', 38134),
(14851, 'esES', 'Derrota a Kalisthene y a Corinth Medroso usando la égida forjada con espíritus.', 'Bastión de protección', '', 38134),
(14852, 'esES', 'Derrota a Alderyn y Myn\'ir y a la Pesadilla Rajacorteza en una prueba de lealtad con Mikanikos.', 'El quid de la cuestión', '', 38134),
(14853, 'esES', 'Derrota a Mortimer el Loco después de que te afecten Venas ígneas, Congelado y Vómito descontrolado.', 'Todos los colores del arco iris del dolor', '', 38134),
(14854, 'esES', 'Supera una prueba de lealtad usando todas las piezas de equipo de tu nexo de almas.', 'No es lo que llevas puesto', '', 38134),
(14856, 'esES', 'Supera una prueba de sabiduría con cinco talismanes equipados.', 'Todo talismán es bienvenido', '', 38134),
(14857, 'esES', 'Derrota a Echthra en una prueba de sabiduría después de matar a 20 reptadores.', 'Luchadores minúsculos', '', 38134),
(14858, 'esES', 'Derrota a Corinth Medroso en una prueba de sabiduría después de que haya consumido dos orbes de ánima.', 'Maldición de la sed', '', 38134),
(14859, 'esES', 'Derrota a Athanos en una prueba de sabiduría después de sobrevivir a cinco Golpes potentes.', 'Un paseo por el parque', '', 38134),
(14860, 'esES', 'Supera una prueba de sabiduría sin equiparte con nada de tu nexo de almas.', 'Lo más vital', '', 38134),
(14861, 'esES', 'Derrota a Kalisthene y a Athanos en la prueba de sabiduría usando a Pelagos, Kleia y Mikanikos.', 'Aprendiendo de los maestros', '', 38134),
(14862, 'esES', 'Supera una prueba de humildad usando todas las piezas de equipo de tu nexo de almas.', 'Sino cómo lo llevas', '', 38134),
(14863, 'esES', 'Derrota a Thran\'tiok en una prueba de sabiduría sin infligirle daño antes de destruir todas las filacterias.', 'Muerte a la cuarta potencia', '', 38134),
(14864, 'esES', 'Derrota a Azaruux en una prueba de sabiduría con Pelagos sin enfrentarte a ningún recuerdo.', 'Pesadilla personal', '', 38134),
(14865, 'esES', 'Supera las diez pruebas de humildad con Pelagos, Kleia y Mikanikos.', 'Discípulo de la humildad', '', 38134),
(14866, 'esES', 'Supera las diez pruebas de humildad sin ningún talismán ni blandón activo.', 'Maestro del camino', '', 38134),
(14887, 'esES', 'Despídete con la mano de Athanos después de que él se despida de ti.', 'A la luna', '', 38134),
(15023, 'esES', 'Desbloquea el rango I de las cuatro mejoras de tu curia.', 'Podemos reconstruir esto', 'Desbloquea: mayores recompensas de ánima', 38134),
(15024, 'esES', 'Desbloquea el rango II de las cuatro mejoras de tu curia.', 'Adiós a la sequía', 'Desbloquea: mayores recompensas de ánima', 38134),
(15025, 'esES', 'Desbloquea el rango III de las cuatro mejoras de tu curia.', 'Sagrario superior', 'Desbloquea: mayores recompensas de ánima', 38134);


DELETE FROM `hotfix_blob` WHERE `locale` = 'esES' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(13330255, 89547, 'esES', 0xFB1E0200ECDA0200, 38134), -- ItemXItemEffect
(3865974254, 187116, 'esES', 0xECDA020000000000, 38134), -- ModifiedReagentItem
(3205218938, 34395, 'esES', 0x4C4F47494E5F504152454E54414C434F4E54524F4C0045737461206375656E7461207469656E6520656C20636F6E74726F6C20706172656E74616C20616374697661646F2E205075656465732063616D62696172206C6120636F6E6669677572616369C3B36E206465207475206375656E746120656E20656C20617061727461646F204765737469C3B36E206465206C61206375656E7461206465206E75657374726F20736974696F207765622E0002, 38134), -- GlobalStrings
(3205218938, 33881, 'esES', 0x424E45545F4552524F525F31310045737461206375656E7461207469656E6520656C20636F6E74726F6C20706172656E74616C20616374697661646F2E205075656465732063616D62696172206C6120636F6E6669677572616369C3B36E206465207475206375656E746120656E20656C20617061727461646F204765737469C3B36E206465206C61206375656E7461206465206E75657374726F20736974696F207765622E0002, 38134), -- GlobalStrings
(3205218938, 33838, 'esES', 0x415554485F504152454E54414C5F434F4E54524F4C0045737461206375656E7461207469656E6520656C20636F6E74726F6C20706172656E74616C20616374697661646F2E205075656465732063616D62696172206C6120636F6E6669677572616369C3B36E206465207475206375656E746120656E20656C20617061727461646F204765737469C3B36E206465206C61206375656E7461206465206E75657374726F20736974696F207765622E0002, 38134), -- GlobalStrings
(1754233351, 4164, 'esES', 0x69ED040011C2B8323FF3665F3F00004843000048430000000000000000000000000000000000000000000000000000803F0000803F0000A040, 38134), -- SpellMissile
(240389885, 5745, 'esES', 0x005238383800000000020202020000000001000000080000000A0000000C00000000000000000000000000000000000000, 38134), -- UnitCondition
(3776013982, 322416, 'esES', 0x00456C207461756D61747572676F2070726F766F636120717565207375726A616E2066726163747572617320726F636F7361732062616A6F206C6F73207069657320646520746F646F73206C6F7320656E656D69676F732063657263616E6F732C206C6F2071756520696E666C6967652024333232343138733120702E206465206461C3B16F2066C3AD7369636F2079206861636520717565207675656C656E20706F72206C6F732061697265732E0000, 38134), -- Spell
(3865974254, 174876, 'esES', 0x1CAB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 326180, 'esES', 0x0024407370656C6C646573633332313837330D0A0000, 38134), -- Spell
(3776013982, 321832, 'esES', 0x0024407370656C6C646573633331303430360D0A0000, 38134), -- Spell
(3776013982, 321828, 'esES', 0x00436C616D616E65626C696E61206A7565676120612024407370656C6C6E616D6533323138323820636F6E20756E20656E656D69676F2C206C6F2071756520696E666C6967652024733120702E206465206461C3B16F206465204E61747572616C657A61207920636F6E66756E646520616C206F626A657469766F20647572616E74652024642E20456C206F626A657469766F20707565646520696E74657272756D70697220657374652068656368697A6F2E00436F6E66756E6469646F2E00, 38134), -- Spell
(2640972154, 324, 'esES', 0x4C6120436F7274652064652041736375617300440100006F00000000000000050000000001000000000000000500000002000000, 38134), -- GarrTalentTree
(2640972154, 321, 'esES', 0x46C3A162726963612064652061626F6D696E6163696F6E657300410100006F00000000000000050000000000000000000000000500000004000000, 38134), -- GarrTalentTree
(2640972154, 320, 'esES', 0x43616D696E6F206465206C6120617363656E7369C3B36E00400100006F00000000000000050000A31400000000000000000500000001000000, 38134), -- GarrTalentTree
(2640972154, 319, 'esES', 0x496E7665726E616465726F206465206C61205265696E61003F0100006F00000000000000050000000000000000000000000500000003000000, 38134), -- GarrTalentTree
(4033975491, 441527, 'esES', 0x00000000666646C000005040000000000000000000000000B7BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441526, 'esES', 0x000000006666464000005040000000000000000000000000B6BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441525, 'esES', 0x000000000000000000005040000000000000000000000000B5BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429002, 'esES', 0x00000000666646C000003040000000000000000000000000CA8B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429001, 'esES', 0x000000006666464000003040000000000000000000000000C98B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429000, 'esES', 0x000000000000000000003040000000000000000000000000C88B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(1181150530, 381714, 'esES', 0x02000000B7BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381713, 'esES', 0x02000000B6BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381712, 'esES', 0x02000000B5BC0600FA390200, 38134), -- SpellVisualKitEffect
(3425193231, 280125, 'esES', 0x090000000A0000000000000000000000000000000000000003000000FA39020075A60100, 38134), -- SpellVisualEvent
(4146370265, 108149, 'esES', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3776013982, 354135, 'esES', 0x000000, 38134), -- Spell
(2939349194, 723, 'esES', 0x4A65666573206465206D756E646F2028536861646F776C616E647329004A65666573206465206D756E646F00030000002301000000008C4E0100AE08000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 722, 'esES', 0x43617374696C6C6F206465204E61746872696120286865726F69636129004865726F6963610003020B0123000000D7008C4E0100F8080F00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 721, 'esES', 0x43617374696C6C6F206465204E61746872696120286DC3AD7469636129004DC3AD746963610003030B0123000000E6008C4E0100F808100000140000000000, 38134), -- GroupFinderActivity
(2939349194, 720, 'esES', 0x43617374696C6C6F206465204E61746872696120286E6F726D616C29004E6F726D616C0003010B0123000000C8008C4E0100F8080E00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 719, 'esES', 0x54656174726F2064656C20446F6C6F7220286865726F69636129004865726F6963610002010A016300000073008C4E0100F508020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 718, 'esES', 0x54656174726F2064656C20446F6C6F7220286DC3AD7469636129004DC3AD746963610002010A016300000073008C4E0100F508170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 717, 'esES', 0x54656174726F2064656C20446F6C6F72202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010A01C300000073008C4E0100F508080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 716, 'esES', 0x54656174726F2064656C20446F6C6F7220286E6F726D616C29004E6F726D616C0002010A016300000000008C4E0100F508010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 715, 'esES', 0x457374656C61204E656372C3B37469636120286865726F69636129004865726F69636100020109016300000073008C4E0100EE08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 714, 'esES', 0x457374656C61204E656372C3B37469636120286DC3AD7469636129004DC3AD7469636100020109016300000073008C4E0100EE08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 713, 'esES', 0x457374656C61204E656372C3B374696361202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010901C300000073008C4E0100EE08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 712, 'esES', 0x457374656C61204E656372C3B37469636120286E6F726D616C29004E6F726D616C00020109016300000000008C4E0100EE08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 711, 'esES', 0x4167756A617320646520417363656E7369C3B36E20286865726F69636129004865726F69636100020108016300000073008C4E0100ED08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 710, 'esES', 0x4167756A617320646520417363656E7369C3B36E20286DC3AD7469636129004DC3AD7469636100020108016300000073008C4E0100ED08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 709, 'esES', 0x4167756A617320646520417363656E7369C3B36E202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010801C300000073008C4E0100ED08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 708, 'esES', 0x4167756A617320646520417363656E7369C3B36E20286E6F726D616C29004E6F726D616C00020108016300000000008C4E0100ED08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 707, 'esES', 0x43617665726E61732053616E6775696E617320286865726F69636129004865726F69636100020107016300000073008C4E0100EC08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 706, 'esES', 0x43617665726E61732053616E6775696E617320286DC3AD7469636129004DC3AD7469636100020107016300000073008C4E0100EC08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 705, 'esES', 0x43617665726E61732053616E6775696E6173202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010701C300000073008C4E0100EC08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 704, 'esES', 0x43617665726E61732053616E6775696E617320286E6F726D616C29004E6F726D616C00020107016300000000008C4E0100EC08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 703, 'esES', 0x4E6965626C6173206465205469726E6120536369746865202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010601C300000073008C4E0100F208080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 702, 'esES', 0x4E6965626C6173206465205469726E612053636974686520286DC3AD7469636129004DC3AD7469636100020106016300000073008C4E0100F208170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 701, 'esES', 0x4E6965626C6173206465205469726E612053636974686520286865726F69636129004865726F69636100020106016300000073008C4E0100F208020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 700, 'esES', 0x4E6965626C6173206465205469726E612053636974686520286E6F726D616C29004E6F726D616C00020106016300000000008C4E0100F208010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 699, 'esES', 0x53616C6173206465206C612045787069616369C3B36E202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010501C300000073008C4E0100EF08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 698, 'esES', 0x53616C6173206465206C612045787069616369C3B36E20286DC3AD7469636129004DC3AD7469636100020105016300000073008C4E0100EF08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 697, 'esES', 0x53616C6173206465206C612045787069616369C3B36E20286865726F69636129004865726F69636100020105016300000073008C4E0100EF08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 696, 'esES', 0x53616C6173206465206C612045787069616369C3B36E20286E6F726D616C29004E6F726D616C00020105016300000000008C4E0100EF08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 695, 'esES', 0x456C204F74726F204C61646F202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010401C300000073008C4E0100F308080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 694, 'esES', 0x456C204F74726F204C61646F20286DC3AD7469636129004DC3AD7469636100020104016300000073008C4E0100F308170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 693, 'esES', 0x456C204F74726F204C61646F20286865726F69636129004865726F69636100020104016300000073008C4E0100F308020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 692, 'esES', 0x456C204F74726F204C61646F20286E6F726D616C29004E6F726D616C00020104016300000000008C4E0100F308010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 691, 'esES', 0x42616A617065737465202870696564726120616E67756C6172206DC3AD7469636129004DC3AD746963612B0002010301C300000073008C4E0100F108080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 690, 'esES', 0x42616A61706573746520286DC3AD7469636129004DC3AD7469636100020103016300000073008C4E0100F108170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 689, 'esES', 0x42616A61706573746520286865726F69636129004865726F69636100020103016300000073008C4E0100F108020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 688, 'esES', 0x42616A61706573746520286E6F726D616C29004E6F726D616C00020103016300000000008C4E0100F108010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 657, 'esES', 0x4A65666573206465206D756E646F2028426174746C6520666F7220417A65726F746829004A65666573206465206D756E646F0003000000230100000000BF5300000000000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 498, 'esES', 0x4D617A6D6F72726120616C6561746F72696120646520426174746C6520666F7220417A65726F746820286865726F69636129004865726F6963610002028800620000003A00BF5300006A06020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 497, 'esES', 0x4D617A6D6F72726120616C6561746F72696120646520426174746C6520666F7220417A65726F746820286E6F726D616C29004E6F726D616C0002008800620000000000BF5300006A06010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 458, 'esES', 0x4A65666573206465206D756E646F20284C6567696F6E29004A65666573206465206D756E646F0003000000230100000000BF530000C404000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 418, 'esES', 0x4D617A6D6F72726120616C6561746F726961206465204C6567696F6E20286865726F69636129004865726F6963610002026F00620000003200BF530000C404020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 417, 'esES', 0x4D617A6D6F72726120616C6561746F726961206465204C6567696F6E20286E6F726D616C29004E6F726D616C0002006F00620000000000BF530000C404010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 398, 'esES', 0x4A65666573206465206D756E646F2028447261656E6F7229004A65666573206465206D756E646F0003000000230100000000BF5300005C04000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 397, 'esES', 0x4A65666573206465206D756E646F202850616E646172696129004A65666573206465206D756E646F0003000000230100000000BF5300006603000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 396, 'esES', 0x4D617A6D6F72726120616C6561746F726961206465205761726C6F72647320286865726F69636129004865726F6963610002006D00620000000000BF5300005C04020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 395, 'esES', 0x4D617A6D6F72726120616C6561746F726961206465205761726C6F72647320286E6F726D616C29004E6F726D616C0002006D00620000000000BF5300005C04010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 364, 'esES', 0x4D617A6D6F72726120616C6561746F7269612064652050616E646172696120286865726F69636129004865726F6963610002005400620000000000BF5300006603020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 363, 'esES', 0x4D617A6D6F72726120616C6561746F7269612064652050616E646172696120286E6F726D616C29004E6F726D616C0002005400620000000000BF5300006603010000050100000000, 38134), -- GroupFinderActivity
(3776013982, 45525, 'esES', 0x0041756D656E746120656C20696E74656C6563746F20646520756E20616C6961646F202473312520702E20647572616E74652024642E00496E74656C6563746F2061756D656E7461646F202473312520702E00, 38134), -- Spell
(3776013982, 327332, 'esES', 0x00456C207461756D61747572676F20696D6275796520646520C3A16E696D612073752061726D612E204C6F73207369677569656E7465732035206174617175657320647572616E746520246420696E666C6967656E206461C3B16F20417263616E6F2065787472612E004C6F73206174617175657320636F6E2061726D6120696E666C6967656E2024333237333331733120702E206465206461C3B16F20417263616E6F206578747261732E00, 38134), -- Spell
(3776013982, 340271, 'esES', 0x0052656475636520756E202433343032373373312520656C206461C3B16F20726563696269646F20706F72206C6F7320616C6961646F7320656E20756E20726164696F206465203135206D2E0052656475636520756E202433343032373373312520656C206461C3B16F20726563696269646F20706F72206C6F7320616C6961646F7320656E20756E20726164696F206465203135206D2E00, 38134), -- Spell
(3776013982, 336061, 'esES', 0x000000, 38134), -- Spell
(603412935, 28771, 'esES', 0xE4B8ADE59BBDE9AB98E5B182E4BABAE4BA8BE58F98E58AA80004, 38134), -- ChatProfanity
(603412935, 28770, 'esES', 0xE4B8ADE59BBDE9AB98E5B182E69D83E58A9BE69697E4BA890004, 38134), -- ChatProfanity
(603412935, 28769, 'esES', 0xE4B8ADE59BBDE5AE98E59CBAE68385E69D80E6A1880004, 38134), -- ChatProfanity
(603412935, 28768, 'esES', 0xE69CB1E6BAB6E59FBA0004, 38134), -- ChatProfanity
(603412935, 28767, 'esES', 0xE69CB1E6BAB6E9B8A10004, 38134), -- ChatProfanity
(603412935, 28766, 'esES', 0xE5AFACE8A1A3E5B89D0004, 38134), -- ChatProfanity
(603412935, 28765, 'esES', 0xE7A588E7BFA00004, 38134), -- ChatProfanity
(603412935, 28764, 'esES', 0xE5B08FE5ADA6E58D9AE5A3ABE7BFA00004, 38134), -- ChatProfanity
(603412935, 28763, 'esES', 0xE694BFE59D9BE9BB91E9A9AC0004, 38134), -- ChatProfanity
(603412935, 28762, 'esES', 0xE694BFE6B2BBE6B581E6B0930004, 38134), -- ChatProfanity
(603412935, 28761, 'esES', 0xE788B1E59BBDE88085E5908CE79B9FE7BD91E7AB990004, 38134), -- ChatProfanity
(603412935, 28760, 'esES', 0xE6AF9BE79A87E5B89D0004, 38134), -- ChatProfanity
(603412935, 28759, 'esES', 0xE999A4E58C85E5AD900004, 38134), -- ChatProfanity
(603412935, 28758, 'esES', 0xE89BA4E79A870004, 38134), -- ChatProfanity
(603412935, 28757, 'esES', 0xE89BA4E89F86E698AFE8B0810004, 38134), -- ChatProfanity
(603412935, 28756, 'esES', 0xE89BA4E89F86E698AFE8AAB00004, 38134), -- ChatProfanity
(603412935, 28755, 'esES', 0xE680BBE4B9A6E8AEB0E79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28754, 'esES', 0xE88081E6B19FE79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28753, 'esES', 0xE6B19FE9A9BEE5B4A90004, 38134), -- ChatProfanity
(603412935, 28752, 'esES', 0xE6B19FE5898DE79A870004, 38134), -- ChatProfanity
(603412935, 28751, 'esES', 0xE6B19FE4B88AE79A870004, 38134), -- ChatProfanity
(603412935, 28750, 'esES', 0xE99995E8A5BFE5B8A6E5A4B4E5A4A7E593A50004, 38134), -- ChatProfanity
(603412935, 28749, 'esES', 0xE68A97E9BAA6E9838E0004, 38134), -- ChatProfanity
(603412935, 28748, 'esES', 0xE6A0BCE890A8E5B094E78E8B0004, 38134), -- ChatProfanity
(603412935, 28747, 'esES', 0xE890A8E6A0BCE5B094E78E8B0004, 38134), -- ChatProfanity
(3776013982, 337334, 'esES', 0x0050616C6D612064656C2074696772652061686F7261207469656E6520756E20616C63616E636520646520247B246D312B357D206D2079207465206C6C65766120686163696120656C206F626A657469766F206375616E646F206C6120757361732E0D0A0D0A4164656DC3A1732C2061706C69636120756E2065666563746F207175652061756D656E746120756E20243334343032316D31252074752070726F626162696C6964616420646520676F6C7065206372C3AD7469636F20636F6E74726120656C206F626A657469766F20647572616E74652024333434303231642E20457374652065666563746F206E6F2073652070756564652061706C69636172206DC3A17320646520756E612076657A206361646120243333373334316420706F72206F626A657469766F2E0000, 38134), -- Spell
(813076512, 80114, 'esES', 0x2401000057640500, 38134), -- SpellLabel
(813076512, 80113, 'esES', 0x1A00000057640500, 38134), -- SpellLabel
(813076512, 80112, 'esES', 0x1000000057640500, 38134), -- SpellLabel
(3776013982, 353367, 'esES', 0x00546F646F20656C206461C3B16F20726563696269646F2073652072656475636520756E20247331252E0000, 38134), -- Spell
(3776013982, 319278, 'esES', 0x00416775616E74652061756D656E7461646F20756E20247331252E0D0A243F733331363731345B4461C3B16F20726563696269646F20726564756369646F20756E20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 316714, 'esES', 0x52616E676F20320041756D656E746120756E202473312520656C20616775616E74652E0D0A52656475636520756E20247B2461627328247332297D2520656C206461C3B16F20726563696269646F2E0000, 38134), -- Spell
(3776013982, 300346, 'esES', 0x00467565676F206C756E61722C2043616C6D61722C20456C696D696E617220636F727275706369C3B36E20792052656E616365722073652070756564656E207573617220656E20666F726D61206465206F736F2E0D0A0D0A546F646F20656C206461C3B16F20726563696269646F2073652072656475636520756E20247332252E0000, 38134), -- Spell
(3776013982, 245013, 'esES', 0x00546F646F20656C206461C3B16F20726563696269646F2073652072656475636520756E20247332252079206C612061726D61647572612061756D656E746120756E20247331252E0000, 38134), -- Spell
(3776013982, 48263, 'esES', 0x00416775616E74652061756D656E7461646F20756E20247331252E0D0A243F733331363731345B4461C3B16F20726563696269646F20726564756369646F20756E20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 71, 'esES', 0x00416C206573746172206375727469646F20706F72206C6120626174616C6C612C20746F646F20656C206461C3B16F2071756520726563696265732073652072656475636520756E20247333252C20747520616775616E74652061756D656E746120756E202473322520792074752061726D61647572612061756D656E746120756E202473312520646520747520667565727A612E0000, 38134), -- Spell
(3776013982, 337541, 'esES', 0x0041686F7261207475204D6172636120C3AD676E65612074652073616E6120756E2024733125206465207375206461C3B16F20696E696369616C20647572616E74652024333337353433642079206361646120656E656D69676F20676F6C706561646F20706F7220747520536967696C6F206465206C6C616D61732061756D656E746120656C206461C3B16F20696E7374616E74C3A16E656F206465207475207369677569656E7465204D6172636120C3AD676E656120756E20243333373534327331252E205365206163756D756C612068617374612024333337353432752076656365732E0000, 38134), -- Spell
(3776013982, 281242, 'esES', 0x005475206461C3B16F206D6172636120616C206F626A657469766F2C206C6F207175652061756D656E746120656C206461C3B16F206DC3A16769636F207175652072656369626520756E2024313439307331252E0000, 38134), -- Spell
(3776013982, 255260, 'esES', 0x005475206461C3B16F206D6172636120616C206F626A657469766F2C206C6F207175652061756D656E746120656C206461C3B16F206DC3A16769636F207175652072656369626520756E2024313439307331252E0000, 38134), -- Spell
(603412935, 28746, 'esES', 0x5C62725C733F615C733F705C733F655C733F5C620000, 38134), -- ChatProfanity
(603412935, 28745, 'esES', 0x5C62725C733F655C733F745C733F615C733F725C733F64285C733F737C5C733F655C733F64293F5C620000, 38134), -- ChatProfanity
(4033975491, 436804, 'esES', 0x00000000000000000000000000000000000000000000000044AA06000A59FF0E030000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000000000000CDCC4C3DCDCC4C3DCC0B0200, 38134), -- SpellVisualKitModelAttach
(3386943305, 171057, 'esES', 0x07787800000000000000004A00B20200000000081000000000000400000000000000000001000040000000000000000000E05A0200, 38134), -- CreatureDifficulty
(3386943305, 170644, 'esES', 0x07787800000000000000001000B2020000000008100000000000000000000000000000000100000000000000000000000068590200, 38134), -- CreatureDifficulty
(3899321669, 4791, 'esES', 0xB71200000101180B0300, 38134), -- SpellAuraVisibility
(3899321669, 4790, 'esES', 0xB61200000001180B0300, 38134), -- SpellAuraVisibility
(4033975491, 440494, 'esES', 0x0000000000000000CDCC4C3E000000000000000000000000AEB80600D058FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 440493, 'esES', 0x0000000000000000CDCCCC3D000000000000000000000000ADB806007F87FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417672, 'esES', 0x000000000000000000000000000000000000000000000000885F06000F5AFF00000000000000000000000000000000000000000000000000000000C03F00000000FFFFFFFFFFFF00000800000000000000000000000021030200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417626, 'esES', 0x0000000000000000000000000000000000000000000000005A5F0600E64BFF0000000000000000000000000000000000000000000000000000333373400000000000009E009F0000000000000000000000000000000009030200, 38134), -- SpellVisualKitModelAttach
(1181150530, 380178, 'esES', 0x02000000AEB8060051160200, 38134), -- SpellVisualKitEffect
(1181150530, 380177, 'esES', 0x02000000ADB8060051160200, 38134), -- SpellVisualKitEffect
(3776013982, 321136, 'esES', 0x0043616461202473312045736375646F732064656C20686F6E7261646F2C207475207369677569656E74652050616C6162726120646520676C6F726961206E6F207469656E6520636F7374652E0000, 38134), -- Spell
(3776013982, 341220, 'esES', 0x000024407370656C6C6465736333343132313200, 38134), -- Spell
(3865974254, 183187, 'esES', 0x93CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183165, 'esES', 0x7DCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183141, 'esES', 0x65CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183136, 'esES', 0x60CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183135, 'esES', 0x5FCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183131, 'esES', 0x5BCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183122, 'esES', 0x52CB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352816, 'esES', 0x000000, 38134), -- Spell
(600565378, 300040, 'esES', 0xA06D01000000803F0000803F0074BA0200, 38134), -- CreatureXDisplayInfo
(813076512, 79920, 'esES', 0x9703000075A80400, 38134), -- SpellLabel
(13330255, 73366, 'esES', 0x081D0200F3D60200, 38134), -- ItemXItemEffect
(3865974254, 186099, 'esES', 0xF3D6020000000000, 38134), -- ModifiedReagentItem
(600565378, 299890, 'esES', 0x4A6400000000803F0000803F001CBA0200, 38134), -- CreatureXDisplayInfo
(600565378, 299885, 'esES', 0x0A6F01000000803F0000803F0017BA0200, 38134), -- CreatureXDisplayInfo
(3865974254, 172899, 'esES', 0x63A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172898, 'esES', 0x62A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172897, 'esES', 0x61A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172896, 'esES', 0x60A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172895, 'esES', 0x5FA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172894, 'esES', 0x5EA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172893, 'esES', 0x5DA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172892, 'esES', 0x5CA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172891, 'esES', 0x5BA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172890, 'esES', 0x5AA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171099, 'esES', 0x5B9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171098, 'esES', 0x5A9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171097, 'esES', 0x599C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171096, 'esES', 0x589C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171095, 'esES', 0x579C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171094, 'esES', 0x569C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171093, 'esES', 0x559C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171092, 'esES', 0x549C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171091, 'esES', 0x539C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171090, 'esES', 0x529C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168316, 'esES', 0x7C91020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164959, 'esES', 0x5F84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164958, 'esES', 0x5E84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164957, 'esES', 0x5D84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164956, 'esES', 0x5C84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164955, 'esES', 0x5B84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164954, 'esES', 0x5A84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164953, 'esES', 0x5984020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164952, 'esES', 0x5884020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164951, 'esES', 0x5784020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164950, 'esES', 0x5684020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164587, 'esES', 0xEB82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164586, 'esES', 0xEA82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164585, 'esES', 0xE982020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164584, 'esES', 0xE882020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164583, 'esES', 0xE782020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164582, 'esES', 0xE682020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164581, 'esES', 0xE582020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164580, 'esES', 0xE482020000000000, 38134), -- ModifiedReagentItem
(3865974254, 159570, 'esES', 0x526F020000000000, 38134), -- ModifiedReagentItem
(3865974254, 155622, 'esES', 0xE65F020000000000, 38134), -- ModifiedReagentItem
(3205218938, 43871, 'esES', 0x43555252454E43595F534541534F4E5F544F54414C5F4D4158494D554D004DC3A178696D6F206465206C612074656D706F726164613A20257325732F25730001, 38134), -- GlobalStrings
(3776013982, 324919, 'esES', 0x0024407370656C6C646573633332323834310000, 38134), -- Spell
(3776013982, 322841, 'esES', 0x00456C206461C3B16F20646520243F613231323631325B43617267612076696C5D3F613231323631335B476F6C706520696E6665726E616C5D5B5D2061756D656E746120756E20247331252E00456C206461C3B16F20646520243F613231323631325B43617267612076696C5D3F613231323631335B476F6C706520696E6665726E616C5D5B5D2061756D656E746120756E20247331252E00, 38134), -- Spell
(3776013982, 294588, 'esES', 0x0041756D656E746120756E20247B2473312A2432393435373873317D25206C612070726F626162696C6964616420646520676F6C7065206372C3AD7469636F2E0000, 38134), -- Spell
(3776013982, 294587, 'esES', 0x0041756D656E746120756E20247B2473312A2432393435373873317D25206C612070726F626162696C6964616420646520676F6C7065206372C3AD7469636F2E0000, 38134), -- Spell
(3865974254, 180318, 'esES', 0x5EC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 180317, 'esES', 0x5DC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 176406, 'esES', 0x16B1020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168564, 'esES', 0x7492020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352497, 'esES', 0x000000, 38134), -- Spell
(3776013982, 327193, 'esES', 0x005265696E6963696120656C207469656D706F2064652072657574696C697A616369C3B36E2064652045736375646F2064652076656E6761646F722E20547573207369677569656E74657320246E2045736375646F732064652076656E6761646F72206E6F207469656E656E207469656D706F2064652072657574696C697A616369C3B36E206520696E666C6967656E20756E2024733225206DC3A173206465206461C3B16F2E00547573207369677569656E74657320246E2045736375646F732064652076656E6761646F72206E6F207469656E656E207469656D706F2064652072657574696C697A616369C3B36E206520696E666C6967656E20756E2024773225206DC3A173206465206461C3B16F2E00, 38134), -- Spell
(3776013982, 321995, 'esES', 0x0041636F67657320616C206869656C6F20656E207475732076656E61732C206C6F207175652072656475636520756E202473312520656C20636F73746520646520706F6465722072C3BA6E69636F2064652074757320666163756C746164657320647572616E74652024642E204E6F2061637469766120656C207469656D706F2064652072657574696C697A616369C3B36E20676C6F62616C2E00456C20636F73746520646520706F6465722072C3BA6E69636F2064652074757320666163756C74616465732073652072656475636520756E20247331252E00, 38134), -- Spell
(3776013982, 248518, 'esES', 0x54616C656E746F204A634A00456C207369677569656E74652068656368697A6F20686F7374696C20717565207365206C616E636520736F62726520656C206F626A657469766F2070726F766F636172C3A120717565206C6F732068656368697A6F7320686F7374696C6573206C616E7A61646F7320647572616E7465206C6F73207369677569656E746573202473312073207365207265646972696A616E2061207475206D6173636F74612E0D0A0D0A5061726120717565207365207265646972696A616E206C6F732068656368697A6F732C207475206D6173636F7461206465626520657374617220656E20756E20726164696F20646520243234383531396131206D2064656C206F626A657469766F2E0000, 38134), -- Spell
(3776013982, 243435, 'esES', 0x00436F6E766965727465207475207069656C20656E207069656472612C206C6F207175652061756D656E74612074752073616C75642061637475616C2079206DC3A178696D6120756E202473312520792072656475636520656C206461C3B16F20726563696269646F20756E202473322520647572616E74652024642E0053616C7564206DC3A178696D612061756D656E7461646120756E20247731252E0D0A4461C3B16F20726563696269646F20726564756369646F20756E20247732252E243F2477343E315B0D0A4162736F7262652024773420702E206465206461C3B16F2E5D5B5D00, 38134), -- Spell
(3776013982, 235219, 'esES', 0x005265696E6963696120656C207469656D706F2064652072657574696C697A616369C3B36E2064652074752042617272657261206465206869656C6F2C204E6F76612064652045736361726368612C20436F6E6F206465206672C3AD6F207920426C6F717565206465206869656C6F2E0000, 38134), -- Spell
(3776013982, 209584, 'esES', 0x54616C656E746F204A634A004F746F72676120696E6D756E696461642061206C6F732065666563746F732064652073696C656E63696F206520696E7465727275706369C3B36E20647572616E74652024642E00496E6D756E652061206C6F732065666563746F732064652073696C656E63696F206520696E7465727275706369C3B36E2E00, 38134), -- Spell
(3776013982, 202335, 'esES', 0x54616C656E746F204A634A005475207369677569656E746520456D6261746520636F6E2062617272696C20696E666C69676520756E2024733125206465206461C3B16F206578747261207920617475726465206120746F646F73206C6F73206F626A657469766F732061206C6F732071756520676F6C70656120647572616E74652024323032333436642E00456D6261746520636F6E2062617272696C20696E666C69676520756E2024733125206465206461C3B16F206578747261207920617475726465206120746F646F73206C6F73206F626A657469766F732061206C6F732071756520676F6C70656120647572616E74652024323032333436642E00, 38134), -- Spell
(3776013982, 34477, 'esES', 0x00526564697269676520746F6461206C6120616D656E617A61207175652067656E6572617320616C206D69656D62726F2064656C20677275706F206F2062616E64612073656C656363696F6E61646F2C20636F6D656E7A616E646F20706F72207475207369677569656E74652061746171756520656E206C6F73207369677569656E7465732024642E204475726120243335303739642E00416D656E617A612064656C2063617A61646F7220726564697269676964612E00, 38134), -- Spell
(3359787322, 19830, 'esES', 0x764D0000, 38134), -- WorldState
(3359787322, 19710, 'esES', 0xFE4C0000, 38134), -- WorldState
(3359787322, 19709, 'esES', 0xFD4C0000, 38134), -- WorldState
(3359787322, 19384, 'esES', 0xB84B0000, 38134), -- WorldState
(368401261, 5214, 'esES', 0x5B8800000000000000000000000000000000000000000000, 38134), -- CombatCondition
(368401261, 4771, 'esES', 0x848400000000000000000000000000000000000000000000, 38134), -- CombatCondition
(3776013982, 163708, 'esES', 0x0041756D656E746120656C206461C3B16F20636F6E2068656368697A6F7320756E203230252E0D0A0D0A5065726D69746520616C206172616B6B6F612053657468656B6B206C616E7A6172204C6C616D612076696E63756C6164612E0041756D656E746120656C206461C3B16F20636F6E2068656368697A6F7320756E203230252E0D0A0D0A5065726D69746520616C206172616B6B6F612053657468656B6B206C616E7A6172204C6C616D612076696E63756C6164612E00, 38134), -- Spell
(3776013982, 352329, 'esES', 0x000000, 38134), -- Spell
(3865974254, 52489, 'esES', 0x09CD000000000000, 38134), -- ModifiedReagentItem
(3037505077, 52489, 'esES', 0x0100, 38134), -- TradeSkillItem
(3776013982, 220358, 'esES', 0x0024407370656C6C646573633130313534360000, 38134), -- Spell
(3776013982, 340433, 'esES', 0x00456C20C3A16E696D6120726566696E61646120666C75796520612074726176C3A97320646520746920792061756D656E746120756E202473312520656C206461C3B16F2071756520696E666C696765732079206C612073616E616369C3B36E20717565207265616C697A617320647572616E74652024642E004461C3B16F20696E666C696769646F2061756D656E7461646F20756E20247331252E0D0A53616E616369C3B36E207265616C697A6164612061756D656E7461646120756E20247332252E00, 38134), -- Spell
(3776013982, 335161, 'esES', 0x00456C2065736361706520646520C3A16E696D61206F6274656E69646F206465206C6F7320676F6C6961747320657374726F706561646F732061756D656E7461206C612076656C6F6369646164206465206D6F76696D69656E746F20756E202473312520792070726F766F63612071756520656C206A756761646F7220656E74726520656E20657275706369C3B36E206361646120247433207320647572616E74652024642C206C6F2071756520696E666C6967652024333434343231733120702E206465206461C3B16F20417263616E6F2061206C6F7320656E656D69676F732063657263616E6F7320792073616E612061206C6F7320616C6961646F732063657263616E6F732024333434343232733120702E0056656C6F6369646164206465206D6F76696D69656E746F2061756D656E7461646120756E20247331252E20496E666C696769656E646F2024333434343231733120702E206465206461C3B16F20417263616E6F2061206C6F7320656E656D69676F732063657263616E6F7320792073616E616E646F2061206C6F7320616C6961646F732063657263616E6F732024333434343232733120702E20636164612024743320732E00, 38134), -- Spell
(3205218938, 43287, 'esES', 0x4741525249534F4E5F464F4C4C4F5745525F4F4E5F4D495353494F4E5F434F4D504C45544500456E20756E61206D697369C3B36E202D20436F6D706C65746164610001, 38134), -- GlobalStrings
(3205218938, 43286, 'esES', 0x4741525249534F4E5F464F4C4C4F5745525F4D495353494F4E5F434F4D504C4554454400436F6D706C65746164610001, 38134), -- GlobalStrings
(3205218938, 43283, 'esES', 0x434F56454E414E545F464F4C4C4F5745525F4D495353494F4E5F434F4D504C45544500456E20756E61206176656E74757261202D20436F6D706C65746164610001, 38134), -- GlobalStrings
(261693969, 59853, 'esES', 0xFFFFFFFFFFFFFFFF486973746F726961732061206C6120686F72612064656C2074C3A93A20536962696C6120506572646964610000CDE900007599F633010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F88700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59852, 'esES', 0xFFFFFFFFFFFFFFFF486973746F726961732061206C6120686F72612064656C2074C3A93A2054726F6368652079204D6F6368650000CCE900007499F533010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59850, 'esES', 0xFFFFFFFFFFFFFFFF486973746F726961732061206C6120686F72612064656C2074C3A93A2056756C63610000CAE900007299F433010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59848, 'esES', 0xFFFFFFFFFFFFFFFF486973746F726961732061206C6120686F72612064656C2074C3A93A205468656F7461720000C8E900007199F333010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(3776013982, 320740, 'esES', 0x000000, 38134), -- Spell
(3776013982, 350249, 'esES', 0x00446973746F7273696F6E6120656C20666C756A6F2074656D706F72616C2C206C6F207175652061756D656E746120756E20247331252074752063656C6572696461642079206C6120646520747573207265666C656A6F732065786163746F7320647572616E74652024313130393039642E0043656C6572696461642061756D656E7461646120756E20247731252E20243F2457343E305B56656C6F63696461642064656C207469656D706F2061756D656E7461646120756E20247734252E5D5B5D00, 38134), -- Spell
(3776013982, 320914, 'esES', 0x00447572616E746520416C746572617220656C207469656D706F2C20747573207265666C656A6F732065786163746F7320792074C3BA206F6274656EC3A9697320446973746F727369C3B36E2074656D706F72616C20636F6E20756E20247331252064652073752076616C6F722E2041206573746F206E6F206C65206166656374616E20446573706C617A616D69656E746F2074656D706F72616C206E692065666563746F732073696D696C617265732E00447572616E746520416C746572617220656C207469656D706F2C20747573207265666C656A6F732065786163746F7320792074C3BA206F6274656EC3A9697320446973746F727369C3B36E2074656D706F72616C20636F6E20756E20247331252064652073752076616C6F722E2041206573746F206E6F206C65206166656374616E20446573706C617A616D69656E746F2074656D706F72616C206E692065666563746F732073696D696C617265732E00, 38134), -- Spell
(3893700160, 169, 'esES', 0x0F000000E2000000D20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 168, 'esES', 0x0E000000E2000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 167, 'esES', 0x0D000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 166, 'esES', 0x0C000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 165, 'esES', 0x0B000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 164, 'esES', 0x0A000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 163, 'esES', 0x09000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 162, 'esES', 0x08000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 161, 'esES', 0x07000000D5000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 160, 'esES', 0x06000000D2000000C50000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 159, 'esES', 0x05000000D2000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 158, 'esES', 0x04000000CF000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 157, 'esES', 0x03000000CB000000BE0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 156, 'esES', 0x02000000C8000000BB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 155, 'esES', 0x0100000000000000B70000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3776013982, 351967, 'esES', 0x000000, 38134), -- Spell
(3776013982, 340882, 'esES', 0x004C6C616D61206120426F6C73612064652047617320656E206361736F2064652071756520686179612064657361706172656369646F206F206D756572746F2E004C6C616D61206120426F6C73612064652047617320656E206361736F2064652071756520686179612064657361706172656369646F206F206D756572746F2E00, 38134), -- Spell
(2340571112, 755, 'esES', 0xBD000000D51C0000D0040000060000008F1B00000000000000000000, 38134), -- ItemBonusListGroupEntry
(2998606315, 212, 'esES', 0x0000000005000000803A09000000000000000000, 38134), -- ScheduledInterval
(3359787322, 20659, 'esES', 0xB3500000, 38134); -- WorldState

INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(4021368146, 4553, 'esES', 0x45737469676961206361C3AD6461000000000000000000D8020000424400000000000000000000000000000000000000, 38134), -- Vignette
(2202435563, 997132, 'esES', 0x0C370F00240127010000F3170700, 38134), -- QuestPOIPoint
(2202435563, 997131, 'esES', 0x0B370F00240128010000F2170700, 38134), -- QuestPOIPoint
(2921112328, 464883, 'esES', 0xF31707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(2921112328, 464882, 'esES', 0xF21707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(3776013982, 335718, 'esES', 0x00436172676172206520496E74657276656E6972207465206F746F7267616E20426C6F717565617220636F6E2065736375646F20647572616E746520247B2473312F313030307DC2A073207920C2A1526576616E636861212C206164656DC3A1732064652067656E6572617220247B2433333537333473312F31307D20702E206465206972612E0000, 38134), -- Spell
(2948698321, 339, 'esES', 0x6D68C604BDD61274, 38134), -- TactKeyLookup
(2948698321, 278, 'esES', 0x7CB28F52811F5830, 38134), -- TactKeyLookup
(3776013982, 328547, 'esES', 0x4E6563726F7365C3B16F7200436C6176617320756E612070C3BA6120C3B373656120616C206F626A657469766F2C206C6F20717565206C6520696E666C6967652024733120702E206465206461C3B16F20792024333234303733733120702E206465206461C3B16F2064652073616E677261646F206361646120243332343037337431C2A07320686173746120717565206D75657265206F206162616E646F6E6120656C20636F6D626174652E0D0A0D0A44657675656C766520756E61206361726761206375616E646F20656C206F626A657469766F206D756572652E0D0A0D0A7C6346464646464646464F746F726761203120702E20646520636F6D626F206DC3A173203120657874726120706F7220636164612070C3BA6120C3B3736561206163746976612E7C720000, 38134), -- Spell
(1369604944, 2081, 'esES', 0x000000000000000000000000000000000000000000000000210800006E1C00000000FF2200000000000000002C010000EE0204020000410B0000000000000000002208, 38134), -- SpellVisualMissile
(4033975491, 439153, 'esES', 0x00000000000000000000000000000000000000000000000071B3060092001500000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(4033975491, 439152, 'esES', 0x00000000000000000000000000000000000000000000000070B3060092001600000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(1181150530, 377991, 'esES', 0x050000001ABB020096D20100, 38134), -- SpellVisualKitEffect
(1181150530, 377990, 'esES', 0x0500000019BB0200F3290200, 38134), -- SpellVisualKitEffect
(1181150530, 377988, 'esES', 0x0500000019BB020054180200, 38134), -- SpellVisualKitEffect
(1181150530, 377987, 'esES', 0x0500000018BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377986, 'esES', 0x0500000017BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377985, 'esES', 0x0500000016BB0200820F0200, 38134), -- SpellVisualKitEffect
(1181150530, 377984, 'esES', 0x0500000015BB02009FFA0100, 38134), -- SpellVisualKitEffect
(1181150530, 377983, 'esES', 0x050000006C4E01004B4B0100, 38134), -- SpellVisualKitEffect
(1181150530, 377982, 'esES', 0x0200000071B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377981, 'esES', 0x0200000070B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377980, 'esES', 0x05000000EFCC0100FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377979, 'esES', 0x06000000B7D20500FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377978, 'esES', 0x0500000014BB020052F20100, 38134), -- SpellVisualKitEffect
(1181150530, 377977, 'esES', 0x0500000013BB0200D8030200, 38134), -- SpellVisualKitEffect
(3425193231, 278473, 'esES', 0x060000000D0000000000000000000000000000000000000002000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278472, 'esES', 0x060000000D0000000000000000000000000000000000000001000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278471, 'esES', 0x030000000D0000000000000000000000000000000000000001000000FF3402001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278470, 'esES', 0x010000000200000000000000000000000000000000000000010000004A4B01001EA30100, 38134), -- SpellVisualEvent
(859088734, 381623, 'esES', 0xFFFFFFFF360000000000, 38134), -- SpellVisualAnim
(4146370265, 107294, 'esES', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3266400455, 613060, 'esES', 0x1ABB02002C713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613059, 'esES', 0x1ABB02002B713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613058, 'esES', 0x1ABB02002A713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613057, 'esES', 0x1ABB020029713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613056, 'esES', 0x1ABB020028713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613055, 'esES', 0x19BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613054, 'esES', 0x19BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613053, 'esES', 0x19BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613052, 'esES', 0x19BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613051, 'esES', 0x19BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613050, 'esES', 0x19BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613049, 'esES', 0x19BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613043, 'esES', 0x18BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613042, 'esES', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613041, 'esES', 0x18BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613040, 'esES', 0x18BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613039, 'esES', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613038, 'esES', 0x17BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613037, 'esES', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613036, 'esES', 0x17BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613035, 'esES', 0x17BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613034, 'esES', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613033, 'esES', 0x16BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613032, 'esES', 0x16BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613031, 'esES', 0x16BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613030, 'esES', 0x16BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613029, 'esES', 0x16BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613028, 'esES', 0x16BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613027, 'esES', 0x16BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613018, 'esES', 0x15BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613017, 'esES', 0x15BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613016, 'esES', 0x15BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613015, 'esES', 0x15BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613014, 'esES', 0x15BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613013, 'esES', 0x15BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613012, 'esES', 0x15BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613011, 'esES', 0x14BB02004AE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613010, 'esES', 0x14BB02004BE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613009, 'esES', 0x14BB02004CE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613008, 'esES', 0x13BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613007, 'esES', 0x13BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613006, 'esES', 0x13BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613005, 'esES', 0x13BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613004, 'esES', 0x13BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613003, 'esES', 0x13BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613002, 'esES', 0x13BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3232102598, 140456, 'esES', 0xA82402001ABB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000F4010000F4010000580C00000000803F010000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140455, 'esES', 0xA7240200AF6C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140454, 'esES', 0xA6240200C06502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140453, 'esES', 0xA5240200D07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140452, 'esES', 0xA424020019BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140451, 'esES', 0xA3240200020A00000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140450, 'esES', 0xA224020018BB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140449, 'esES', 0xA124020017BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140448, 'esES', 0xA02402003E7502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140447, 'esES', 0x9F240200447502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140446, 'esES', 0x9E24020016BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140445, 'esES', 0x9D24020015BB02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140444, 'esES', 0x9C240200B9710200000040410000C04100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140443, 'esES', 0x9B240200956C02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140442, 'esES', 0x9A240200177202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140441, 'esES', 0x99240200F46F02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140440, 'esES', 0x98240200817202000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140439, 'esES', 0x97240200557102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140438, 'esES', 0x96240200ED6602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140437, 'esES', 0x952402001E7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140436, 'esES', 0x94240200E56602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140435, 'esES', 0x9324020014BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140434, 'esES', 0x9224020013BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140433, 'esES', 0x91240200666C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140432, 'esES', 0x90240200267102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123926, 'esES', 0x16E40100407602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123714, 'esES', 0x42E30100437502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000101F4010000F4010000570C0000E8030000E8030000580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123675, 'esES', 0x1BE30100457502000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123670, 'esES', 0x16E301003D7502000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123594, 'esES', 0xCAE20100F17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123515, 'esES', 0x7BE20100A27402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123514, 'esES', 0x7AE20100A17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123504, 'esES', 0x70E201009F7402000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001401F0000401F0000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123503, 'esES', 0x6FE201009E7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C010000000000000000000000016400000064000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123502, 'esES', 0x6EE201009D7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122935, 'esES', 0x37E00100507202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122901, 'esES', 0x15E00100167202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122891, 'esES', 0x0BE00100187202000000C0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122821, 'esES', 0xC5DF0100D1710200000000400000804000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122814, 'esES', 0xBEDF0100C87102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122807, 'esES', 0xB7DF0100C17102000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001BC020000BC020000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122806, 'esES', 0xB6DF0100C07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122804, 'esES', 0xB4DF0100BE7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122709, 'esES', 0x55DF01004A7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122629, 'esES', 0x05DF0100F97002000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B44300000000000000C800000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122404, 'esES', 0x24DE0100F56F02000000C0400000404100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121643, 'esES', 0x2BDB0100D76C02000000803F0000004000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000001012C0100002C010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121613, 'esES', 0x0DDB0100976C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000000012C0100002C010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121609, 'esES', 0x09DB0100906C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121587, 'esES', 0xF3DA0100686C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 120239, 'esES', 0xAFD50100E66602000000C040000040410000000000000000000000000000000000000000000000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001E8030000E8030000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 119974, 'esES', 0xA6D40100D66502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000002FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 25856, 'esES', 0x00650000C9E600000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(1485693696, 5565, 'esES', 0x1ABB0200010000000069620000000000000100, 38134); -- SoundEnvelope

