DELETE FROM `broadcast_text_locale` WHERE `locale` = 'esMX' AND `ID` IN (209968, 208581);
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `Text_lang`, `Text1_lang`, `VerifiedBuild`) VALUES
(209968, 'esMX', '', '$UBienvenido, amigo:Bienvenida, amiga;. ¿Te interesan las piedras angulares?', 38134),
(208581, 'esMX', 'Saludos NOMBREDEUSUARIO. Espero que tengas un GENERANDO UN ADJETIVO POSITIVO ALEATORIO día.', '', 38134);

DELETE FROM `item_search_name_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `item_search_name_locale` (`ID`, `locale`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'esMX', 'Gafas de sol con bisutería', 38134);

DELETE FROM `currency_types_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `currency_types_locale` (`ID`, `locale`, `Name_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1191, 'esMX', 'Valor', 'Una moneda utilizada para aumentar el poder de los objetos de los calabozos míticos.', 38134),
(1602, 'esMX', 'Conquista', 'Se obtiene en actividades JcJ puntuadas. Úsala para obtener equipamiento en Oribos.', 38134),
(1828, 'esMX', 'Ceniza de alma', 'Una fuente de poder en bruto que se encuentra en Torghast. Sirve para alimentar la Cámara del Tallarrunas.', 38134);

DELETE FROM `spell_name_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `spell_name_locale` (`ID`, `locale`, `Name_lang`, `VerifiedBuild`) VALUES
(328547, 'esMX', 'Púa ósea serrada', 38134),
(335718, 'esMX', 'Represalia', 38134),
(340882, 'esMX', 'Llamada a Bolsa de gases', 38134),
(351967, 'esMX', 'Llamar a Hervoria', 38134),
(320914, 'esMX', 'Reloj de arena de cronomántico', 38134),
(350249, 'esMX', 'Distorsión temporal', 38134),
(320740, 'esMX', 'Fijación', 38134),
(335161, 'esMX', 'Agotamiento de ánima', 38134),
(340433, 'esMX', 'Favor de Caída del Pecado', 38134),
(220358, 'esMX', 'Golpes de ciclón', 38134),
(352329, 'esMX', '[DNT] Learn Bananas', 38134),
(163708, 'esMX', 'Encantado por una fogata', 38134),
(34477, 'esMX', 'Redirección', 38134),
(202335, 'esMX', 'Barril doble', 38134),
(209584, 'esMX', 'Té de enfoque zen', 38134),
(235219, 'esMX', 'Mordedura de frío', 38134),
(243435, 'esMX', 'Brebaje reconstituyente', 38134),
(248518, 'esMX', 'Entrometerse', 38134),
(321995, 'esMX', 'Presencia hipotérmica', 38134),
(327193, 'esMX', 'Momento de gloria', 38134),
(352497, 'esMX', '[DNT] Teleport', 38134),
(294587, 'esMX', 'Púas de Obleron x2', 38134),
(294588, 'esMX', 'Púas de Obleron x3', 38134),
(322841, 'esMX', 'Alafuria', 38134),
(324919, 'esMX', 'Alafuria', 38134),
(352816, 'esMX', '[DNT] Grant Keystone', 38134),
(341220, 'esMX', 'Ballesta jurafauces', 38134),
(321136, 'esMX', 'Luz brillante', 38134),
(255260, 'esMX', 'Enseña del caos', 38134),
(281242, 'esMX', 'Enseña del caos', 38134),
(337541, 'esMX', 'Espíritu de la Llama de la Oscuridad', 38134),
(71, 'esMX', 'Vanguardia', 38134),
(48263, 'esMX', 'Veterano de la Tercera Guerra', 38134),
(245013, 'esMX', 'Equilibrio del maestro cervecero', 38134),
(300346, 'esMX', 'Adepto osuno', 38134),
(316714, 'esMX', 'Veterano de la Tercera Guerra', 38134),
(319278, 'esMX', 'Veterano de la Cuarta Guerra', 38134),
(353367, 'esMX', 'Égida de luz', 38134),
(337334, 'esMX', 'Trecho Celestial de Keefer', 38134),
(336061, 'esMX', 'Arremetida de baba', 38134),
(340271, 'esMX', 'Contagio coagulado', 38134),
(327332, 'esMX', 'Imbuir arma', 38134),
(45525, 'esMX', 'Intelecto Arcano', 38134),
(354135, 'esMX', 'Bottom Barrier Visual', 38134),
(321828, 'esMX', 'Pastelito', 38134),
(321832, 'esMX', 'Quemado', 38134),
(326180, 'esMX', 'Marca congeladora', 38134),
(322416, 'esMX', 'Fractura escarpada', 38134);

DELETE FROM `criteria_tree_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `criteria_tree_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(91079, 'esMX', 'Login with Bananas license (Charity Pet 2021)', 38134),
(91080, 'esMX', '', 38134),
(91081, 'esMX', 'Earn character-level Bananas achievement', 38134),
(91082, 'esMX', '', 38134),
(91386, 'esMX', 'Ve\'nari reputation is Apprehensive', 38134),
(91388, 'esMX', 'Ve\'nari reputation is Tentative', 38134),
(91390, 'esMX', 'Ve\'nari reputation is Ambivalent', 38134),
(91392, 'esMX', 'Ve\'nari reputation is Cordial', 38134),
(91393, 'esMX', '', 38134),
(91503, 'esMX', 'Do You Have All Rank 1s in a Covenant Sanctum?', 38134),
(91504, 'esMX', 'Login test for backporting of \"do you have all level 1 buildings\"', 38134),
(91505, 'esMX', '', 38134),
(91506, 'esMX', 'Do You Have All Rank 2s in a Covenant Sanctum?', 38134),
(91507, 'esMX', 'Login test for backporting of \"do you have all level 2 buildings\"', 38134),
(91508, 'esMX', '', 38134),
(91509, 'esMX', 'Do You Have All Rank 3s in a Covenant Sanctum?', 38134),
(91510, 'esMX', 'Login test for backporting of \"do you have all level 3 buildings\"', 38134),
(91511, 'esMX', '', 38134),
(91387, 'esMX', 'La reputación de Ve\'nari es Aprensiva', 38134),
(91389, 'esMX', 'La reputación de Ve\'nari es Tentativa', 38134),
(91391, 'esMX', 'La reputación de Ve\'nari es Ambivalente', 38134),
(87404, 'esMX', 'Gana partidas de JcJ puntuado durante la temporada 1 de Shadowlands con un índice de 1000 o superior', 38134),
(87408, 'esMX', 'Gana partidas de JcJ puntuado durante la temporada 1 de Shadowlands con un índice de 1000 o superior', 38134);

DELETE FROM `specialization_spells_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `specialization_spells_locale` (`ID`, `locale`, `Description_lang`, `VerifiedBuild`) VALUES
(5164, 'esMX', '', 38134),
(5369, 'esMX', '', 38134),
(5480, 'esMX', '', 38134),
(6271, 'esMX', '', 38134),
(6285, 'esMX', '', 38134),
(6286, 'esMX', '', 38134),
(6287, 'esMX', '', 38134),
(6288, 'esMX', '', 38134),
(6289, 'esMX', '', 38134),
(6292, 'esMX', '', 38134),
(6293, 'esMX', '', 38134),
(6294, 'esMX', '', 38134),
(6295, 'esMX', '', 38134),
(6298, 'esMX', '', 38134),
(6299, 'esMX', '', 38134),
(6306, 'esMX', '', 38134),
(6377, 'esMX', '', 38134),
(6455, 'esMX', '', 38134),
(6457, 'esMX', '', 38134),
(6463, 'esMX', '', 38134),
(6478, 'esMX', '', 38134),
(6531, 'esMX', '', 38134),
(6532, 'esMX', '', 38134),
(6533, 'esMX', '', 38134),
(6534, 'esMX', '', 38134),
(6535, 'esMX', '', 38134),
(6608, 'esMX', '', 38134),
(5262, 'esMX', '', 38134),
(6609, 'esMX', '', 38134),
(5320, 'esMX', '', 38134),
(5521, 'esMX', '', 38134),
(5580, 'esMX', '', 38134),
(5938, 'esMX', '', 38134),
(6113, 'esMX', '', 38134),
(6114, 'esMX', '', 38134),
(6193, 'esMX', '', 38134),
(6195, 'esMX', '', 38134),
(6324, 'esMX', '', 38134),
(6400, 'esMX', '', 38134),
(6434, 'esMX', '', 38134),
(6447, 'esMX', '', 38134),
(6515, 'esMX', '', 38134),
(6516, 'esMX', '', 38134),
(6610, 'esMX', '', 38134);

DELETE FROM `battlemaster_list_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `battlemaster_list_locale` (`ID`, `locale`, `Name_lang`, `GameType_lang`, `ShortDescription_lang`, `LongDescription_lang`, `VerifiedBuild`) VALUES
(100, 'esMX', 'CDB puntuado', '', '', '', 38134),
(866, 'esMX', 'Todas las arenas', 'Gresca', '', '', 38134),
(1047, 'esMX', 'Mugambala', '', '', '', 38134),
(1048, 'esMX', 'El Robódromo', '', '', '', 38134),
(1049, 'esMX', 'Punta Garfio', '', '', '', 38134),
(1050, 'esMX', 'Dominio Empíreo', '', '', '', 38134);

DELETE FROM `area_table_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `area_table_locale` (`ID`, `locale`, `AreaName_lang`, `VerifiedBuild`) VALUES
(12876, 'esMX', 'Trono del Primus', 38134),
(12917, 'esMX', 'Caída del Pecado', 38134),
(12924, 'esMX', 'Ardenweald', 38134),
(13387, 'esMX', 'Ardenweald', 38134),
(6852, 'esMX', 'Terreno de Pruebas', 38134);

DELETE FROM `char_titles_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `char_titles_locale` (`ID`, `locale`, `Name_lang`, `Name1_lang`, `VerifiedBuild`) VALUES
(679, 'esMX', 'Barón %s', 'Barón %s', 38134),
(680, 'esMX', 'Baronesa %s', 'Baronesa %s', 38134),
(682, 'esMX', 'Conde%s', 'Conde%s', 38134),
(683, 'esMX', 'Condesa %s', 'Condesa %s', 38134);

DELETE FROM `item_sparse_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `item_sparse_locale` (`ID`, `locale`, `Description_lang`, `Display3_lang`, `Display2_lang`, `Display1_lang`, `Display_lang`, `VerifiedBuild`) VALUES
(52489, 'esMX', '', '', '', '', 'Gafas de sol con bisutería', 38134),
(180317, 'esMX', '', '', '', '', 'Poción de sanación conmovedora', 38134),
(180318, 'esMX', '', '', '', '', 'Poción de maná conmovedora', 38134),
(155622, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(159570, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164580, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164581, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164582, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164583, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164584, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164585, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164586, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164587, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164950, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164951, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164952, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164953, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164954, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164955, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(164956, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164957, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164958, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(164959, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(168316, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(171090, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(171091, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(171092, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(171093, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(171095, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171096, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171097, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171098, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(171099, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172890, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(172891, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(172892, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(172893, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(172894, 'esMX', '', '', '', '', 'Sigilo belinato', 38134),
(172895, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172896, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172897, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172898, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(172899, 'esMX', '', '', '', '', 'Trofeo del señor de la guerra', 38134),
(186099, 'esMX', 'Este aparato ocasiona una pequeña falla en el espacio dentro de tu equipo, con la forma perfecta para que encaje una gema.', '', '', '', 'Aparato de realineamiento espacial', 38134),
(183122, 'esMX', '', '', '', '', 'Capa de la muerte', 38134),
(183131, 'esMX', '', '', '', '', 'Arpeo de estigia', 38134),
(183135, 'esMX', '', '', '', '', 'Invocar a los caídos', 38134),
(183136, 'esMX', '', '', '', '', 'Faucerrata incendiaria', 38134),
(183141, 'esMX', '', '', '', '', 'Magma de estigia', 38134),
(183165, 'esMX', '', '', '', '', 'Ballesta jurafauces', 38134),
(183187, 'esMX', '', '', '', '', 'Encantamiento del hilasombras', 38134),
(174876, 'esMX', '', '', '', '', 'Ojo cercenado de N\'Zoth', 38134),
(187116, 'esMX', '', '', '', '', 'Muñeco-diana', 38134);

DELETE FROM `map_difficulty_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `map_difficulty_locale` (`ID`, `locale`, `Message_lang`, `VerifiedBuild`) VALUES
(4775, 'esMX', '', 38134);

DELETE FROM `mount_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `mount_locale` (`ID`, `locale`, `Name_lang`, `SourceText_lang`, `Description_lang`, `VerifiedBuild`) VALUES
(1458, 'esMX', 'Anciano errante', '|cFFFFD200Promoción|r', 'Defensores acérrimos de los bosques de Azeroth, los ancianos también son conocidos por sus gloriosas copas de hojas, que cambian de color con las estaciones.', 38134);

DELETE FROM `player_condition_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `player_condition_locale` (`ID`, `locale`, `FailureDescription_lang`, `VerifiedBuild`) VALUES
(90553, 'esMX', '', 38134),
(90651, 'esMX', '', 38134),
(90652, 'esMX', '', 38134),
(78581, 'esMX', '', 38134),
(87399, 'esMX', 'Requiere que Ve\'nari tenga una opinión Agradecida o mejor de ti.', 38134);

DELETE FROM `achievement_locale` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `achievement_locale` (`ID`, `locale`, `Description_lang`, `Title_lang`, `Reward_lang`, `VerifiedBuild`) VALUES
(15010, 'esMX', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Apprehensive standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Apprehensive [DNT]', '', 38134),
(15011, 'esMX', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Tentative standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Tentative [DNT]', '', 38134),
(15012, 'esMX', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Ambivalent standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Ambivalent [DNT]', '', 38134),
(15013, 'esMX', 'Hidden account-wide tracking achievement allowing access to Ve\'nari\'s goods which require Cordial standing [DNT]', 'Maw Tracking - Vendor - Items Unlocked - Cordial [DNT]', '', 38134),
(14340, 'esMX', 'Derrota a un jefe en la Senda de Ascensión.', 'La Senda hacia la Ascensión 1', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14342, 'esMX', 'Derrota a tres jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 3', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14343, 'esMX', 'Derrota a cinco jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 5', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14344, 'esMX', 'Derrota a siete jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 7', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14345, 'esMX', 'Derrota a doce jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 12', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14346, 'esMX', 'Derrota a 16 jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 16', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14348, 'esMX', 'Derrota a 20 jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 20', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14349, 'esMX', 'Derrota a 24 jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 24', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14351, 'esMX', 'Derrota a 39 jefes en la Senda de Ascensión.', 'La Senda hacia la Ascensión 39', 'Desbloquea más desafíos en la Senda de Ascensión.', 38134),
(14502, 'esMX', 'Supera las primeras ocho pruebas de lealtad.', 'En busca de la lealtad', '', 38134),
(14633, 'esMX', 'Desbloquea el rango III de la red de transporte de tu sagrario.', 'Navegante maestro', '', 38134),
(14636, 'esMX', 'Desbloquea el rango III de la mesa de comando de aventuras de tu sagrario.', 'Aventurero jefe', '', 38134),
(14637, 'esMX', 'Desbloquea el rango V de la función especial de tu sagrario', 'El toque de tu pacto', '', 38134),
(14638, 'esMX', 'Desbloquea todas las ubicaciones conectadas a tu conductor de ánima.', 'El ánima debe fluir', '', 38134),
(14639, 'esMX', 'Usa tu conductor de ánima 50 veces.', 'Dedicación a la restauración', '', 38134),
(14670, 'esMX', 'Incuba un espíritu de cada clase en el Vivero de la Reina.', 'Espíritu benevolente', '', 38134),
(14675, 'esMX', 'Incuba un espíritu superior de cada clase en el Vivero de la Reina.', 'Interlocutor de espíritu', '', 38134),
(14676, 'esMX', 'Incuba un espíritu divino de cada clase en el Vivero de la Reina.', 'Salvador de espíritus divino', '', 38134),
(14677, 'esMX', 'Completa cada una de las misiones de observación de espíritus de Falir en el Vivero de la Reina.', 'Observaciones espirituales', '', 38134),
(14678, 'esMX', 'Desbloquea los siguientes favores para tu Corte de Brasas.', 'Favores de la corte', '', 38134),
(14679, 'esMX', 'Desbloquea las siguientes mejoras para tu Corte de Brasas.', 'El palacio festivo', '', 38134),
(14680, 'esMX', 'Desbloquea los siguientes servicios para tu Corte de Brasas.', 'Algo para todos', '', 38134),
(14681, 'esMX', 'Entrena a tu dragador de la Corte de Brasas en las siguientes capacidades de mayordomo.', 'Academia de dragadores', '', 38134),
(14682, 'esMX', 'Completa los siguientes logros de la Corte de Brasas.', 'El heraldo de la fiesta', 'Título de recompensa: El Heraldo de la fiesta', 38134),
(14683, 'esMX', 'Desbloquea las siguientes opciones decorativas para tu dragador de la Corte de Brasas.', 'Estilo de dragador', '', 38134),
(14684, 'esMX', 'Completa las siguientes misiones de costura abominable', 'Vidas abominables', '', 38134),
(14723, 'esMX', 'Recibe a los siguientes invitados en tu Corte de Brasas.', 'Siéntete como en casa', '', 38134),
(14724, 'esMX', 'Ayuda a que los siguientes invitados obtengan el humor Maravillado en tu Corte de Brasas.', 'Complaciente crónico', '', 38134),
(14725, 'esMX', 'Organiza una Corte de Brasas con cuatro invitados Maravillados.', 'Pocos pero felices', '', 38134),
(14726, 'esMX', 'Organiza Cortes de Brasas con niveles altos de los siguientes atributos.', 'No hay tiempo para el aburrimiento', '', 38134),
(14727, 'esMX', 'Completa 10 eventos durante una Corte de Brasas.', 'Maestro de ceremonias', '', 38134),
(14748, 'esMX', 'Crea 25 de estos accesorios de moda con costura abominable.', 'Renovación de vestuario', '', 38134),
(14749, 'esMX', 'Ayuda a Rendle a buscar los siguientes sombreros para usar en la Corte de Brasas.', 'El gran día de Rendle', '', 38134),
(14751, 'esMX', 'Construye cada uno de los siguientes ensamblajes con costura abominable.', 'La pandilla reunida', 'Recompensa: Montura Tauralus de los Elegidos', 38134),
(14752, 'esMX', 'Completa los siguientes logros de costura abominable.', 'Cosas para hacer en la muerte', 'Título de recompensa: Abominable. Recompensa: Montura Tauralus de los Elegidos acorazado', 38134),
(14753, 'esMX', 'Aporta 100 envolturas cubiertas de ánima al invocador Gerard para ayudar a invocar a Visectus, Espectro de guerra.', 'Envuelto para regalo', '', 38134),
(14764, 'esMX', 'Consigue el gran grisgrís con ayuda de Coqui.', 'El gran grisgrís', '', 38134),
(14775, 'esMX', 'Alcanza la reputación Exaltado con Marasmius.', 'Felicitaciones fúngicas', 'Título de recompensa: Tipo divertido / Chica divertida', 38134),
(14777, 'esMX', 'Mejora todas las opciones de tu sagrario de Pacto.', 'Experto en restauración', '', 38134),
(14780, 'esMX', 'Completa todas las misiones de meditación de Om en el Vivero de la Reina y descubre tu paz interior.', 'Maestro de meditación', '', 38134),
(14789, 'esMX', 'Completa la serie de misiones de Lía para restaurar todos los espíritus de animales en el Vivero de la Reina.', 'Espíritus grandes y pequeños por igual', '', 38134),
(14833, 'esMX', 'Crea cada uno de estos accesorios de moda con costura abominable.', 'Abominación à la mode', '', 38134),
(14839, 'esMX', 'Sube a tres lazos de alma a nivel 60 en las Aventuras.', 'Un lazo aventurado', '', 38134),
(14840, 'esMX', 'Sube a un aventurero a nivel 20.', 'Aventuras: Primeros pasos', '', 38134),
(14841, 'esMX', 'Sube a un aventurero a nivel 40.', 'Aventuras: Bien encaminado', '', 38134),
(14842, 'esMX', 'Sube a un aventurero a nivel 60.', 'Aventuras: Fuerza y resiliencia', '', 38134),
(14843, 'esMX', 'Consigue a los 12 aventureros de tu Pacto.', 'Aventuras: La armonía del propósito', '', 38134),
(14844, 'esMX', 'Completa las siguientes aventuras de las Fauces.', 'Aventuras: Hacia la brecha', '', 38134),
(14845, 'esMX', 'Completa una aventura.', 'Aventuras: Un paso en la dirección correcta', '', 38134),
(14846, 'esMX', 'Completa 10 aventuras.', 'Aventuras: Como hojas en el bosque', '', 38134),
(14847, 'esMX', 'Completa 100 aventuras.', 'Aventuras: Protector de las Tierras de las Sombras', '', 38134),
(14851, 'esMX', 'Derrota a Kalisthene y Craven Corinto mientras usas la Égida forjada con espíritus.', 'Bastión de protección', '', 38134),
(14852, 'esMX', 'Derrota a Alderyn y Myn\'ir y Pesadilla cortezastilla en una Prueba de lealtad como Mikanikos.', 'Uh-uh, uh-uh, qué problema', '', 38134),
(14853, 'esMX', 'Derrota a Mortimer, el loco, después de recibir Venas ardientes, Congelado y Vómito descontrolado.', 'Todos los dolores del arcoíris', '', 38134),
(14854, 'esMX', 'Supera una Prueba de lealtad con cada pieza de equipamiento de lazo de almas.', 'No es lo que usas', '', 38134),
(14856, 'esMX', 'Supera una Prueba de sabiduría con cinco talismanes en tu equipo.', 'Talismanes de la sabiduría', '', 38134),
(14857, 'esMX', 'Derrota a Echthra en una Prueba de sabiduría después de matar a 20 reptadores.', 'Pequeños guerreros', '', 38134),
(14858, 'esMX', 'Derrota a Craven Corinto en una Prueba de sabiduría después de que haya consumido dos orbes de ánima.', 'Maldición de sed', '', 38134),
(14859, 'esMX', 'Derrota a Athanos en una Prueba de sabiduría después de sobrevivir cinco Barridas poderosas.', 'A prueba de barridas', '', 38134),
(14860, 'esMX', 'Supera una Prueba de sabiduría sin equipamiento de lazo de almas.', 'Solo con lo esencial', '', 38134),
(14861, 'esMX', 'Derrota a Kalisthene y Athanos en la Prueba de sabiduría con Pelagos, Kleia y Mikanikos.', 'Aprender de los maestros', '', 38134),
(14862, 'esMX', 'Supera una Prueba de humildad con cada equipamiento de lazo de almas.', 'Es la forma en que lo usas', '', 38134),
(14863, 'esMX', 'Derrota a Thran\'tiok en una Prueba de sabiduría sin dañarla antes de destruir todas las filacterias.', 'Muerte por cuatro', '', 38134),
(14864, 'esMX', 'Derrota a Azaruux en una Prueba de sabiduría como Pelagos sin enfrentar a ningún recuerdo.', 'Pesadilla personal', '', 38134),
(14865, 'esMX', 'Supera las diez Pruebas de humildad con Pelagos, Kleia y Mikanikos.', 'Discípulo de la humildad', '', 38134),
(14866, 'esMX', 'Supera las diez Pruebas de humildad sin talismanes ni braseros activos.', 'Maestro de la senda', '', 38134),
(14887, 'esMX', 'Despídete de Athanos después de que él se despida de ti.', 'A la luna', '', 38134),
(15023, 'esMX', 'Desbloquea el rango I de las cuatro mejoras del pacto.', 'La reconstrucción es posible', 'Desbloquea: Recompensas de ánima aumentadas', 38134),
(15024, 'esMX', 'Desbloquea el rango II de las cuatro mejoras del pacto.', 'Combatiendo la sequía', 'Desbloquea: Recompensas de ánima aumentadas', 38134),
(15025, 'esMX', 'Desbloquea el rango III de las cuatro mejoras del pacto.', 'Sagrario superior', 'Desbloquea: Recompensas de ánima aumentadas', 38134);


DELETE FROM `hotfix_blob` WHERE `locale` = 'esMX' AND `VerifiedBuild`>0;
INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(13330255, 89547, 'esMX', 0xFB1E0200ECDA0200, 38134), -- ItemXItemEffect
(3865974254, 187116, 'esMX', 0xECDA020000000000, 38134), -- ModifiedReagentItem
(3205218938, 34395, 'esMX', 0x4C4F47494E5F504152454E54414C434F4E54524F4C0045737461206375656E7461207469656E6520656C20636F6E74726F6C20706172656E74616C20616374697661646F2E205075656465732063616D62696172206C6120636F6E6669677572616369C3B36E206465207475206375656E746120656E20656C20617061727461646F204765737469C3B36E206465206C61206375656E7461206465206E75657374726F20736974696F207765622E0002, 38134), -- GlobalStrings
(3205218938, 33881, 'esMX', 0x424E45545F4552524F525F31310045737461206375656E7461207469656E6520656C20636F6E74726F6C20706172656E74616C20616374697661646F2E205075656465732063616D62696172206C6120636F6E6669677572616369C3B36E206465207475206375656E746120656E20656C20617061727461646F204765737469C3B36E206465206C61206375656E7461206465206E75657374726F20736974696F207765622E0002, 38134), -- GlobalStrings
(3205218938, 33838, 'esMX', 0x415554485F504152454E54414C5F434F4E54524F4C0045737461206375656E7461207469656E6520656C20636F6E74726F6C20706172656E74616C20616374697661646F2E205075656465732063616D62696172206C6120636F6E6669677572616369C3B36E206465207475206375656E746120656E20656C20617061727461646F204765737469C3B36E206465206C61206375656E7461206465206E75657374726F20736974696F207765622E0002, 38134), -- GlobalStrings
(1754233351, 4164, 'esMX', 0x69ED040011C2B8323FF3665F3F00004843000048430000000000000000000000000000000000000000000000000000803F0000803F0000A040, 38134), -- SpellMissile
(240389885, 5745, 'esMX', 0x005238383800000000020202020000000001000000080000000A0000000C00000000000000000000000000000000000000, 38134), -- UnitCondition
(3776013982, 322416, 'esMX', 0x00456C207461756D61747572676F2070726F766F636120717565207375726A616E206772696574617320656E206C6120726F636120646562616A6F20646520746F646F73206C6F7320656E656D69676F732063657263616E6F732E204C6F73207075C3B16F7320696E666C6967656E2024333232343138733120702E206465206461C3B16F2066C3AD7369636F2079206C616E7A616E2061206C6F7320656E656D69676F7320706F7220656C20616972652E0000, 38134), -- Spell
(3865974254, 174876, 'esMX', 0x1CAB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 326180, 'esMX', 0x0024407370656C6C646573633332313837330D0A0000, 38134), -- Spell
(3776013982, 321832, 'esMX', 0x0024407370656C6C646573633331303430360D0A0000, 38134), -- Spell
(3776013982, 321828, 'esMX', 0x00436C616D616E65626C696E61206A7565676120612024407370656C6C6E616D6533323138323820636F6E20756E20656E656D69676F2C20696E666C6967652024733120702E206465206461C3B16F206465206E61747572616C657A61207920636F6E66756E646520616C206F626A657469766F20647572616E74652024642E20456C206F626A657469766F20707565646520696E74657272756D70697220657374652068656368697A6F2E00436F6E66756E6469646F2E00, 38134), -- Spell
(2640972154, 324, 'esMX', 0x4C6120436F7274652064652042726173617300440100006F00000000000000050000000001000000000000000500000002000000, 38134), -- GarrTalentTree
(2640972154, 321, 'esMX', 0x46C3A162726963612064652041626F6D696E6163696F6E657300410100006F00000000000000050000000000000000000000000500000004000000, 38134), -- GarrTalentTree
(2640972154, 320, 'esMX', 0x53656E646120646520417363656E7369C3B36E00400100006F00000000000000050000A31400000000000000000500000001000000, 38134), -- GarrTalentTree
(2640972154, 319, 'esMX', 0x456C2056697665726F206465206C61205265696E61003F0100006F00000000000000050000000000000000000000000500000003000000, 38134), -- GarrTalentTree
(4033975491, 441527, 'esMX', 0x00000000666646C000005040000000000000000000000000B7BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441526, 'esMX', 0x000000006666464000005040000000000000000000000000B6BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 441525, 'esMX', 0x000000000000000000005040000000000000000000000000B5BC06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF000000000000000000000000000000FA390200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429002, 'esMX', 0x00000000666646C000003040000000000000000000000000CA8B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429001, 'esMX', 0x000000006666464000003040000000000000000000000000C98B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(4033975491, 429000, 'esMX', 0x000000000000000000003040000000000000000000000000C88B06008293FF0000DB0FC93FDB0FC9BF000000000000000000000000000000000000804000000000FFFFFFFFFFFF00000000000000000000000000000009210200, 38134), -- SpellVisualKitModelAttach
(1181150530, 381714, 'esMX', 0x02000000B7BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381713, 'esMX', 0x02000000B6BC0600FA390200, 38134), -- SpellVisualKitEffect
(1181150530, 381712, 'esMX', 0x02000000B5BC0600FA390200, 38134), -- SpellVisualKitEffect
(3425193231, 280125, 'esMX', 0x090000000A0000000000000000000000000000000000000003000000FA39020075A60100, 38134), -- SpellVisualEvent
(4146370265, 108149, 'esMX', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3776013982, 354135, 'esMX', 0x000000, 38134), -- Spell
(2939349194, 723, 'esMX', 0x4A656665732064656C206D756E646F202854696572726173206465206C617320536F6D6272617329004A656665732064656C206D756E646F00030000002301000000008C4E0100AE08000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 722, 'esMX', 0x43617374696C6C6F204E61746872696120284865726F69636F29004865726F69636F0003020B0123000000D7008C4E0100F8080F00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 721, 'esMX', 0x43617374696C6C6F204E61746872696120284DC3AD7469636F29004DC3AD7469636F0003030B0123000000E6008C4E0100F808100000140000000000, 38134), -- GroupFinderActivity
(2939349194, 720, 'esMX', 0x43617374696C6C6F204E61746872696120284E6F726D616C29004E6F726D616C0003010B0123000000C8008C4E0100F8080E00001E0000000000, 38134), -- GroupFinderActivity
(2939349194, 719, 'esMX', 0x54656174726F2064656C20446F6C6F7220284865726F69636F29004865726F69636F0002010A016300000073008C4E0100F508020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 718, 'esMX', 0x54656174726F2064656C20446F6C6F7220284DC3AD7469636F29004DC3AD7469636F0002010A016300000073008C4E0100F508170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 717, 'esMX', 0x54656174726F2064656C20446F6C6F72202850696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010A01C300000073008C4E0100F508080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 716, 'esMX', 0x54656174726F2064656C20446F6C6F7220284E6F726D616C29004E6F726D616C0002010A016300000000008C4E0100F508010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 715, 'esMX', 0x4C6120446573747275636369C3B36E204E656372C3B37469636120284865726F69636F29004865726F69636F00020109016300000073008C4E0100EE08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 714, 'esMX', 0x4C6120446573747275636369C3B36E204E656372C3B37469636120284DC3AD7469636F29004DC3AD7469636F00020109016300000073008C4E0100EE08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 713, 'esMX', 0x4C6120446573747275636369C3B36E204E656372C3B374696361202850696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010901C300000073008C4E0100EE08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 712, 'esMX', 0x4C6120446573747275636369C3B36E204E656372C3B37469636120284E6F726D616C29004E6F726D616C00020109016300000000008C4E0100EE08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 711, 'esMX', 0x546F7272657320646520417363656E7369C3B36E20284865726F69636F29004865726F69636F00020108016300000073008C4E0100ED08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 710, 'esMX', 0x546F7272657320646520417363656E7369C3B36E20284DC3AD7469636F29004DC3AD7469636F00020108016300000073008C4E0100ED08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 709, 'esMX', 0x546F7272657320646520417363656E7369C3B36E202850696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010801C300000073008C4E0100ED08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 708, 'esMX', 0x546F7272657320646520417363656E7369C3B36E20284E6F726D616C29004E6F726D616C00020108016300000000008C4E0100ED08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 707, 'esMX', 0x50726F66756E646964616465732053616E6775C3AD6E65617320284865726F69636F29004865726F69636F00020107016300000073008C4E0100EC08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 706, 'esMX', 0x50726F66756E646964616465732053616E6775C3AD6E65617320284DC3AD7469636F29004DC3AD7469636F00020107016300000073008C4E0100EC08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 705, 'esMX', 0x50726F66756E646964616465732053616E6775C3AD6E656173202850696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010701C300000073008C4E0100EC08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 704, 'esMX', 0x50726F66756E646964616465732053616E6775C3AD6E65617320284E6F726D616C29004E6F726D616C00020107016300000000008C4E0100EC08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 703, 'esMX', 0x4E6965626C6173206465205469726E6120536369746865202850696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010601C300000073008C4E0100F208080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 702, 'esMX', 0x4E6965626C6173206465205469726E612053636974686520284DC3AD7469636F29004DC3AD7469636F00020106016300000073008C4E0100F208170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 701, 'esMX', 0x4E6965626C6173206465205469726E612053636974686520284865726F69636F29004865726F69636F00020106016300000073008C4E0100F208020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 700, 'esMX', 0x4E6965626C6173206465205469726E612053636974686520284E6F726D616C29004E6F726D616C00020106016300000000008C4E0100F208010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 699, 'esMX', 0x53616C6F6E65732064652045787069616369C3B36E202850696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010501C300000073008C4E0100EF08080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 698, 'esMX', 0x53616C6F6E65732064652045787069616369C3B36E20284DC3AD7469636F29004DC3AD7469636F00020105016300000073008C4E0100EF08170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 697, 'esMX', 0x53616C6F6E65732064652045787069616369C3B36E20284865726F69636F29004865726F69636F00020105016300000073008C4E0100EF08020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 696, 'esMX', 0x53616C6F6E65732064652045787069616369C3B36E20284E6F726D616C29004E6F726D616C00020105016300000000008C4E0100EF08010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 695, 'esMX', 0x456C204F74726F204C61646F202850696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010401C300000073008C4E0100F308080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 694, 'esMX', 0x456C204F74726F204C61646F20284DC3AD7469636F29004DC3AD7469636F00020104016300000073008C4E0100F308170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 693, 'esMX', 0x456C204F74726F204C61646F20284865726F69636F29004865726F69636F00020104016300000073008C4E0100F308020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 692, 'esMX', 0x456C204F74726F204C61646F20284E6F726D616C29004E6F726D616C00020104016300000000008C4E0100F308010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 691, 'esMX', 0x506C61676120416272756D61646F7261202870696564726120616E67756C6172206DC3AD7469636129004DC3AD7469636F2B0002010301C300000073008C4E0100F108080000050100000000, 38134), -- GroupFinderActivity
(2939349194, 690, 'esMX', 0x506C61676120416272756D61646F726120286DC3AD7469636F29004DC3AD7469636F00020103016300000073008C4E0100F108170000050100000000, 38134), -- GroupFinderActivity
(2939349194, 689, 'esMX', 0x506C61676120416272756D61646F726120286865726F69636F29004865726F69636F00020103016300000073008C4E0100F108020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 688, 'esMX', 0x506C61676120416272756D61646F726120286E6F726D616C29004E6F726D616C00020103016300000000008C4E0100F108010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 657, 'esMX', 0x4A65666573206465206D756E646F2028426174746C6520666F7220417A65726F746829004A656665732064656C206D756E646F0003000000230100000000BF5300000000000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 498, 'esMX', 0x43616C61626F7A6F20616C6561746F72696F20646520426174746C6520666F7220417A65726F746820286865726F69636F29004865726F69636F0002028800620000003A00BF5300006A06020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 497, 'esMX', 0x43616C61626F7A6F20616C6561746F72696F20646520426174746C6520666F7220417A65726F746820286E6F726D616C29004E6F726D616C0002008800620000000000BF5300006A06010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 458, 'esMX', 0x4A656665732064656C206D756E646F20284C6567696F6E29004A656665732064656C206D756E646F0003000000230100000000BF530000C404000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 418, 'esMX', 0x43616C61626F7A6F206465204C6567696F6E20616C6561746F72696F20284865726F69636F29004865726F69636F0002026F00620000003200BF530000C404020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 417, 'esMX', 0x43616C61626F7A6F206465204C6567696F6E20616C6561746F72696F20284E6F726D616C29004E6F726D616C0002006F00620000000000BF530000C404010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 398, 'esMX', 0x4A65666573206465206D756E646F2028447261656E6F7229004A65666573206465206D756E646F0003000000230100000000BF5300005C04000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 397, 'esMX', 0x4A65666573206465206D756E646F202850616E646172696129004A65666573206465206D756E646F0003000000230100000000BF5300006603000000280000000000, 38134), -- GroupFinderActivity
(2939349194, 396, 'esMX', 0x43616C61626F7A6F206465205761726C6F72647320616C6561746F72696F20284865726F69636F29004865726F69636F0002006D00620000000000BF5300005C04020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 395, 'esMX', 0x43616C61626F7A6F206465205761726C6F72647320616C6561746F72696F20284E6F726D616C29004E6F726D616C0002006D00620000000000BF5300005C04010000050100000000, 38134), -- GroupFinderActivity
(2939349194, 364, 'esMX', 0x43616C61626F7A6F2064652050616E646172696120616C6561746F72696F20284865726F69636F29004865726F69636F0002005400620000000000BF5300006603020000050100000000, 38134), -- GroupFinderActivity
(2939349194, 363, 'esMX', 0x43616C61626F7A6F2064652050616E646172696120616C6561746F72696F20284E6F726D616C29004E6F726D616C0002005400620000000000BF5300006603010000050100000000, 38134), -- GroupFinderActivity
(3776013982, 45525, 'esMX', 0x0041756D656E746120656C20696E74656C6563746F20646520756E20616C6961646F202473312520702E20647572616E74652024642E00496E74656C6563746F2061756D656E7461646F202473312520702E00, 38134), -- Spell
(3776013982, 327332, 'esMX', 0x00456C207461756D61747572676F20696E66756E646520C3A16E696D6120656E2073752061726D612E204C6F73207072C3B378696D6F73203520617461717565732064656E74726F20646520246420696E666C6967656E206461C3B16F20617263616E6F2061646963696F6E616C2E004C6F73206174617175657320636F6E2061726D617320696E666C6967656E2024333237333331733120702E206DC3A173206465206461C3B16F20617263616E6F2E00, 38134), -- Spell
(3776013982, 340271, 'esMX', 0x0052656475636520756E202433343032373373312520656C206461C3B16F20726563696269646F20706F7220616C6961646F7320656E20756E20726164696F206465203135206D2E0052656475636520756E202433343032373373312520656C206461C3B16F20726563696269646F20706F7220616C6961646F7320656E20756E20726164696F206465203135206D2E00, 38134), -- Spell
(3776013982, 336061, 'esMX', 0x000000, 38134), -- Spell
(603412935, 28771, 'esMX', 0xE4B8ADE59BBDE9AB98E5B182E4BABAE4BA8BE58F98E58AA80004, 38134), -- ChatProfanity
(603412935, 28770, 'esMX', 0xE4B8ADE59BBDE9AB98E5B182E69D83E58A9BE69697E4BA890004, 38134), -- ChatProfanity
(603412935, 28769, 'esMX', 0xE4B8ADE59BBDE5AE98E59CBAE68385E69D80E6A1880004, 38134), -- ChatProfanity
(603412935, 28768, 'esMX', 0xE69CB1E6BAB6E59FBA0004, 38134), -- ChatProfanity
(603412935, 28767, 'esMX', 0xE69CB1E6BAB6E9B8A10004, 38134), -- ChatProfanity
(603412935, 28766, 'esMX', 0xE5AFACE8A1A3E5B89D0004, 38134), -- ChatProfanity
(603412935, 28765, 'esMX', 0xE7A588E7BFA00004, 38134), -- ChatProfanity
(603412935, 28764, 'esMX', 0xE5B08FE5ADA6E58D9AE5A3ABE7BFA00004, 38134), -- ChatProfanity
(603412935, 28763, 'esMX', 0xE694BFE59D9BE9BB91E9A9AC0004, 38134), -- ChatProfanity
(603412935, 28762, 'esMX', 0xE694BFE6B2BBE6B581E6B0930004, 38134), -- ChatProfanity
(603412935, 28761, 'esMX', 0xE788B1E59BBDE88085E5908CE79B9FE7BD91E7AB990004, 38134), -- ChatProfanity
(603412935, 28760, 'esMX', 0xE6AF9BE79A87E5B89D0004, 38134), -- ChatProfanity
(603412935, 28759, 'esMX', 0xE999A4E58C85E5AD900004, 38134), -- ChatProfanity
(603412935, 28758, 'esMX', 0xE89BA4E79A870004, 38134), -- ChatProfanity
(603412935, 28757, 'esMX', 0xE89BA4E89F86E698AFE8B0810004, 38134), -- ChatProfanity
(603412935, 28756, 'esMX', 0xE89BA4E89F86E698AFE8AAB00004, 38134), -- ChatProfanity
(603412935, 28755, 'esMX', 0xE680BBE4B9A6E8AEB0E79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28754, 'esMX', 0xE88081E6B19FE79785E58DB10004, 38134), -- ChatProfanity
(603412935, 28753, 'esMX', 0xE6B19FE9A9BEE5B4A90004, 38134), -- ChatProfanity
(603412935, 28752, 'esMX', 0xE6B19FE5898DE79A870004, 38134), -- ChatProfanity
(603412935, 28751, 'esMX', 0xE6B19FE4B88AE79A870004, 38134), -- ChatProfanity
(603412935, 28750, 'esMX', 0xE99995E8A5BFE5B8A6E5A4B4E5A4A7E593A50004, 38134), -- ChatProfanity
(603412935, 28749, 'esMX', 0xE68A97E9BAA6E9838E0004, 38134), -- ChatProfanity
(603412935, 28748, 'esMX', 0xE6A0BCE890A8E5B094E78E8B0004, 38134), -- ChatProfanity
(603412935, 28747, 'esMX', 0xE890A8E6A0BCE5B094E78E8B0004, 38134), -- ChatProfanity
(3776013982, 337334, 'esMX', 0x0050616C6D612064656C2074696772652061686F7261207469656E6520756E20616C63616E636520646520247B246D312B357D206D207920636F72726573206861636961206C612075626963616369C3B36E2064656C206F626A657469766F206375616E646F206C6120757361732E0D0A0D0A50616C6D612064656C2074696772652074616D6269C3A96E2061706C69636120756E2065666563746F207175652061756D656E746120756E20243334343032316D31252074752070726F626162696C6964616420646520676F6C7065206372C3AD7469636F20736F62726520656C206F626A657469766F20647572616E74652024333434303231642E20457374652065666563746F206E6F2073652070756564652061706C69636172206DC3A17320646520756E612076657A206361646120243333373334316420706F72206F626A657469766F2E0000, 38134), -- Spell
(813076512, 80114, 'esMX', 0x2401000057640500, 38134), -- SpellLabel
(813076512, 80113, 'esMX', 0x1A00000057640500, 38134), -- SpellLabel
(813076512, 80112, 'esMX', 0x1000000057640500, 38134), -- SpellLabel
(3776013982, 353367, 'esMX', 0x00546F646F20656C206461C3B16F20726563696269646F2073652072656475636520756E20247331252E0000, 38134), -- Spell
(3776013982, 319278, 'esMX', 0x0041756D656E746120756E202473312520656C20616775616E74652E0D0A243F733331363731345B456C206461C3B16F20726563696269646F2073652072656475636520756E20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 316714, 'esMX', 0x52616E676F20320041756D656E746120656C20616775616E746520756E20247331252E0D0A456C206461C3B16F20726563696269646F2073652072656475636520756E20247B2461627328247332297D252E0000, 38134), -- Spell
(3776013982, 300346, 'esMX', 0x00467565676F206C756E61722C2043616C6D61722C20456C696D696E617220636F727275706369C3B36E20792052656E616365722070756564656E2075736172736520656E20466F726D61206465206F736F2E0D0A0D0A546F646F20656C206461C3B16F20726563696269646F2073652072656475636520756E20247332252E0000, 38134), -- Spell
(3776013982, 245013, 'esMX', 0x00546F646F206461C3B16F20726563696269646F2073652072656475636520756E202473322520792074752061726D61647572612061756D656E746120756E20247331252E0000, 38134), -- Spell
(3776013982, 48263, 'esMX', 0x0041756D656E746120756E202473312520656C20616775616E74652E0D0A243F733331363731345B456C206461C3B16F20726563696269646F2073652072656475636520756E20247333252E5D5B5D0000, 38134), -- Spell
(3776013982, 71, 'esMX', 0x004C6120626174616C6C6120746520686120666F7274616C656369646F2E20546F646F20656C206461C3B16F20726563696269646F2073652072656475636520756E20247333252C20747520616775616E74652061756D656E746120756E20247332252C20792074752061726D616475726120756E202473312520646520747520667565727A612E0000, 38134), -- Spell
(3776013982, 337541, 'esMX', 0x005475204D617263612061726469656E74652061686F72612074652073616E6120756E612063616E7469646164206571756976616C656E746520616C20247331252064656C206461C3B16F20696E666C696769646F20696E696369616C20647572616E74652024333337353433642C2079206361646120656E656D69676F20676F6C706561646F20706F7220747520536967696C6F206465206C61206C6C616D612061756D656E746120656C206461C3B16F20696E7374616E74C3A16E656F206465207475207072C3B378696D61204D617263612061726469656E746520756E20243333373534327331252E205365206163756D756C612068617374612024333337353432752076656365732E0000, 38134), -- Spell
(3776013982, 281242, 'esMX', 0x005475206461C3B16F206D6172636120616C206F626A657469766F20792061756D656E746120656C206461C3B16F206DC3A16769636F207175652072656369626520756E2024313439307331252E0000, 38134), -- Spell
(3776013982, 255260, 'esMX', 0x005475206461C3B16F206D6172636120616C206F626A657469766F20792061756D656E746120656C206461C3B16F206DC3A16769636F207175652072656369626520756E2024313439307331252E0000, 38134), -- Spell
(603412935, 28746, 'esMX', 0x5C62725C733F615C733F705C733F655C733F5C620000, 38134), -- ChatProfanity
(603412935, 28745, 'esMX', 0x5C62725C733F655C733F745C733F615C733F725C733F64285C733F737C5C733F655C733F64293F5C620000, 38134), -- ChatProfanity
(4033975491, 436804, 'esMX', 0x00000000000000000000000000000000000000000000000044AA06000A59FF0E030000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000000000000CDCC4C3DCDCC4C3DCC0B0200, 38134), -- SpellVisualKitModelAttach
(3386943305, 171057, 'esMX', 0x07787800000000000000004A00B20200000000081000000000000400000000000000000001000040000000000000000000E05A0200, 38134), -- CreatureDifficulty
(3386943305, 170644, 'esMX', 0x07787800000000000000001000B2020000000008100000000000000000000000000000000100000000000000000000000068590200, 38134), -- CreatureDifficulty
(3899321669, 4791, 'esMX', 0xB71200000101180B0300, 38134), -- SpellAuraVisibility
(3899321669, 4790, 'esMX', 0xB61200000001180B0300, 38134), -- SpellAuraVisibility
(4033975491, 440494, 'esMX', 0x0000000000000000CDCC4C3E000000000000000000000000AEB80600D058FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 440493, 'esMX', 0x0000000000000000CDCCCC3D000000000000000000000000ADB806007F87FF00000000000000000000000000000000000000000000000000003333333F0000000000009E009F0000000000000000000000000000000051160200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417672, 'esMX', 0x000000000000000000000000000000000000000000000000885F06000F5AFF00000000000000000000000000000000000000000000000000000000C03F00000000FFFFFFFFFFFF00000800000000000000000000000021030200, 38134), -- SpellVisualKitModelAttach
(4033975491, 417626, 'esMX', 0x0000000000000000000000000000000000000000000000005A5F0600E64BFF0000000000000000000000000000000000000000000000000000333373400000000000009E009F0000000000000000000000000000000009030200, 38134), -- SpellVisualKitModelAttach
(1181150530, 380178, 'esMX', 0x02000000AEB8060051160200, 38134), -- SpellVisualKitEffect
(1181150530, 380177, 'esMX', 0x02000000ADB8060051160200, 38134), -- SpellVisualKitEffect
(3776013982, 321136, 'esMX', 0x0043616461202473312045736375646F732064656C20686F6E7261646F2C207475207072C3B378696D612050616C6162726120646520676C6F726961206573206772617469732E0000, 38134), -- Spell
(3776013982, 341220, 'esMX', 0x000024407370656C6C6465736333343132313200, 38134), -- Spell
(3865974254, 183187, 'esMX', 0x93CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183165, 'esMX', 0x7DCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183141, 'esMX', 0x65CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183136, 'esMX', 0x60CB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183135, 'esMX', 0x5FCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183131, 'esMX', 0x5BCB020000000000, 38134), -- ModifiedReagentItem
(3865974254, 183122, 'esMX', 0x52CB020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352816, 'esMX', 0x000000, 38134), -- Spell
(600565378, 300040, 'esMX', 0xA06D01000000803F0000803F0074BA0200, 38134), -- CreatureXDisplayInfo
(813076512, 79920, 'esMX', 0x9703000075A80400, 38134), -- SpellLabel
(13330255, 73366, 'esMX', 0x081D0200F3D60200, 38134), -- ItemXItemEffect
(3865974254, 186099, 'esMX', 0xF3D6020000000000, 38134), -- ModifiedReagentItem
(600565378, 299890, 'esMX', 0x4A6400000000803F0000803F001CBA0200, 38134), -- CreatureXDisplayInfo
(600565378, 299885, 'esMX', 0x0A6F01000000803F0000803F0017BA0200, 38134), -- CreatureXDisplayInfo
(3865974254, 172899, 'esMX', 0x63A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172898, 'esMX', 0x62A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172897, 'esMX', 0x61A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172896, 'esMX', 0x60A3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172895, 'esMX', 0x5FA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172894, 'esMX', 0x5EA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172893, 'esMX', 0x5DA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172892, 'esMX', 0x5CA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172891, 'esMX', 0x5BA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 172890, 'esMX', 0x5AA3020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171099, 'esMX', 0x5B9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171098, 'esMX', 0x5A9C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171097, 'esMX', 0x599C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171096, 'esMX', 0x589C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171095, 'esMX', 0x579C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171094, 'esMX', 0x569C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171093, 'esMX', 0x559C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171092, 'esMX', 0x549C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171091, 'esMX', 0x539C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 171090, 'esMX', 0x529C020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168316, 'esMX', 0x7C91020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164959, 'esMX', 0x5F84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164958, 'esMX', 0x5E84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164957, 'esMX', 0x5D84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164956, 'esMX', 0x5C84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164955, 'esMX', 0x5B84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164954, 'esMX', 0x5A84020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164953, 'esMX', 0x5984020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164952, 'esMX', 0x5884020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164951, 'esMX', 0x5784020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164950, 'esMX', 0x5684020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164587, 'esMX', 0xEB82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164586, 'esMX', 0xEA82020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164585, 'esMX', 0xE982020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164584, 'esMX', 0xE882020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164583, 'esMX', 0xE782020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164582, 'esMX', 0xE682020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164581, 'esMX', 0xE582020000000000, 38134), -- ModifiedReagentItem
(3865974254, 164580, 'esMX', 0xE482020000000000, 38134), -- ModifiedReagentItem
(3865974254, 159570, 'esMX', 0x526F020000000000, 38134), -- ModifiedReagentItem
(3865974254, 155622, 'esMX', 0xE65F020000000000, 38134), -- ModifiedReagentItem
(3205218938, 43871, 'esMX', 0x43555252454E43595F534541534F4E5F544F54414C5F4D4158494D554D004DC3A178696D6F2064652074656D706F726164613A20257325732F25730001, 38134), -- GlobalStrings
(3776013982, 324919, 'esMX', 0x0024407370656C6C646573633332323834310000, 38134), -- Spell
(3776013982, 322841, 'esMX', 0x0041756D656E746120756E202473312520656C206461C3B16F20646520243F613231323631325B41636F6D65746964612076696C5D3F613231323631335B476F6C706520696E6665726E616C5D5B5D2E0041756D656E746120756E202473312520656C206461C3B16F20646520243F613231323631325B41636F6D65746964612076696C5D3F613231323631335B476F6C706520696E6665726E616C5D5B5D2E00, 38134), -- Spell
(3776013982, 294588, 'esMX', 0x0041756D656E746120756E20247B2473312A2432393435373873317D25206C612070726F626162696C6964616420646520676F6C7065206372C3AD7469636F2E0000, 38134), -- Spell
(3776013982, 294587, 'esMX', 0x0041756D656E746120756E20247B2473312A2432393435373873317D25206C612070726F626162696C6964616420646520676F6C7065206372C3AD7469636F2E0000, 38134), -- Spell
(3865974254, 180318, 'esMX', 0x5EC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 180317, 'esMX', 0x5DC0020000000000, 38134), -- ModifiedReagentItem
(3865974254, 176406, 'esMX', 0x16B1020000000000, 38134), -- ModifiedReagentItem
(3865974254, 168564, 'esMX', 0x7492020000000000, 38134), -- ModifiedReagentItem
(3776013982, 352497, 'esMX', 0x000000, 38134), -- Spell
(3776013982, 327193, 'esMX', 0x005265737461626C65636520656C207469656D706F2064652072657574696C697A616369C3B36E2064652045736375646F2064652076656E6761646F722E20547573207072C3B378696D6F7320246E2045736375646F732064652076656E6761646F72206E6F207469656E656E207469656D706F2064652072657574696C697A616369C3B36E206520696E666C6967656E20756E2024733225206DC3A173206465206461C3B16F2E00547573207369677569656E74657320246E2045736375646F732064652076656E6761646F72206E6F207469656E656E207469656D706F2064652072657574696C697A616369C3B36E206520696E666C6967656E20756E2024773225206DC3A173206465206461C3B16F2E00, 38134), -- Spell
(3776013982, 321995, 'esMX', 0x00546520656E74726567617320616C206869656C6F2071756520636F72726520706F72207475732076656E61732C206C6F207175652072656475636520656C20636F73746F20646520706F6465722072C3BA6E69636F2064652074757320686162696C69646164657320756E202473312520647572616E74652024642E204E6F2061637469766120656C207469656D706F2064652072657574696C697A616369C3B36E20676C6F62616C2E00456C20636F73746F20646520706F6465722072C3BA6E69636F2064652074757320686162696C6964616465732073652072656475636520247331252E00, 38134), -- Spell
(3776013982, 248518, 'esMX', 0x54616C656E746F206465204A634A00456C207369677569656E74652068656368697A6F20686F7374696C20717565207365206C616E636520636F6E74726120656C206F626A657469766F20686172C3A12071756520647572616E7465206C6F73207072C3B378696D6F73202473312073206C6F732068656368697A6F7320686F7374696C6573207365207265646972656363696F6E656E206861636961207475206D6173636F74612E0D0A0D0A5475206D6173636F7461206465626520657374617220656E20756E20726164696F20646520243234383531396131206D2064656C206F626A657469766F207061726120717565207365207265646972656363696F6E656E206C6F732068656368697A6F732E0000, 38134), -- Spell
(3776013982, 243435, 'esMX', 0x00436F6E766965727465207475207069656C20656E2070696564726120792061756D656E746120756E20247331252074752073616C75642061637475616C2079206DC3A178696D6120792072656475636520756E202473322520656C206461C3B16F20726563696269646F20647572616E74652024642E004C612073616C7564206DC3A178696D612061756D656E746120756E20247731252E0D0A456C206461C3B16F20726563696269646F2073652072656475636520756E20247732252E243F2477343E315B0D0A4162736F7262652024773420702E206465206461C3B16F2E5D5B5D00, 38134), -- Spell
(3776013982, 235219, 'esMX', 0x005265737461626C65636520656C207469656D706F2064652072657574696C697A616369C3B36E2064652074752042617272657261206465206869656C6F2C204E6F76612064652065736361726368612C20436F6E6F206465206672C3AD6F207920426C6F717565206465206869656C6F2E0000, 38134), -- Spell
(3776013982, 209584, 'esMX', 0x54616C656E746F206465204A634A0050726F706F7263696F6E6120696E6D756E696461642061206C6F732065666563746F732064652073696C656E63696F206520696E7465727275706369C3B36E20647572616E74652024642E00496E6D756E652061206C6F732065666563746F732064652073696C656E63696F206520696E7465727275706369C3B36E2E00, 38134), -- Spell
(3776013982, 202335, 'esMX', 0x54616C656E746F206465204A634A005475207369677569656E746520456D6261746520636F6E2062617272696C20696E666C69676520756E2024733125206DC3A173206465206461C3B16F207920617475726465206120746F646F73206C6F7320656E656D69676F732071756520676F6C70656120647572616E74652024323032333436642E00456D6261746520636F6E2062617272696C20696E666C69676520756E2024733125206DC3A173206465206461C3B16F207920617475726465206120746F646F73206C6F73206F626A657469766F732071756520676F6C70656120647572616E74652024323032333436642E00, 38134), -- Spell
(3776013982, 34477, 'esMX', 0x0044697269676520646520666F726D6120657272C3B36E656120746F646F7320747573206174617175657320636F6E74726120756E206D69656D62726F2073656C656363696F6E61646F2064656C20677275706F206F2062616E646120616C207072696E636970696F206465207475207369677569656E746520617461717565206C616E7A61646F20656E206C6F73207072C3B378696D6F73202464207920647572616E746520243335303739642E00416D656E617A6120726564697269676964612064656C2063617A61646F722E00, 38134), -- Spell
(3359787322, 19830, 'esMX', 0x764D0000, 38134), -- WorldState
(3359787322, 19710, 'esMX', 0xFE4C0000, 38134), -- WorldState
(3359787322, 19709, 'esMX', 0xFD4C0000, 38134), -- WorldState
(3359787322, 19384, 'esMX', 0xB84B0000, 38134), -- WorldState
(368401261, 5214, 'esMX', 0x5B8800000000000000000000000000000000000000000000, 38134), -- CombatCondition
(368401261, 4771, 'esMX', 0x848400000000000000000000000000000000000000000000, 38134), -- CombatCondition
(3776013982, 163708, 'esMX', 0x0041756D656E746120656C206461C3B16F2064652068656368697A6F7320756E203230252E0D0A0D0A5065726D697465207175652053657468656B6B206172616B6B6F61206C616E636520456E63616E7461646F20706F7220756E61206C6C616D612E0041756D656E746120656C206461C3B16F2064652068656368697A6F7320756E203230252E0D0A0D0A5065726D697465207175652053657468656B6B206172616B6B6F61206C616E636520456E63616E7461646F20706F7220756E61206C6C616D612E00, 38134), -- Spell
(3776013982, 352329, 'esMX', 0x000000, 38134), -- Spell
(3865974254, 52489, 'esMX', 0x09CD000000000000, 38134), -- ModifiedReagentItem
(3037505077, 52489, 'esMX', 0x0100, 38134), -- TradeSkillItem
(3776013982, 220358, 'esMX', 0x0024407370656C6C646573633130313534360000, 38134), -- Spell
(3776013982, 340433, 'esMX', 0x00C3816E696D6120726566696E616461207265636F7272652074752063756572706F20792061756D656E746120756E202473312520656C206461C3B16F2079206C612073616E616369C3B36E20717565207265616C697A617320647572616E74652024642E00456C206461C3B16F20696E666C696769646F2061756D656E746120756E20247331252E0D0A4C612073616E616369C3B36E207265616C697A6164612061756D656E746120756E20247332252E00, 38134), -- Spell
(3776013982, 335161, 'esMX', 0x00456C20C3A16E696D61207265636F6C65637461646120646520676F6C6961747320646573636F6D70756573746F732061756D656E7461206C612076656C6F6369646164206465206D6F76696D69656E746F20756E2024733125207920686163652071756520656C206A756761646F7220656E74726520656E20657275706369C3B36E206361646120247433207320647572616E74652024642C206C6F2071756520696E666C6967652024333434343231733120702E206465206461C3B16F20617263616E6F2061206C6F7320656E656D69676F732063657263616E6F732079206F746F7267612024333434343232733120702E2064652073616E616369C3B36E2061206C6F7320616C6961646F732063657263616E6F732E004C612076656C6F6369646164206465206D6F76696D69656E746F2061756D656E746120756E20247331252E20496E666C6967652024333434343231733120702E206465206461C3B16F20617263616E6F2061206C6F7320656E656D69676F732063657263616E6F7320792073616E612024333434343232733120702E2061206C6F7320616C6961646F732063657263616E6F7320636164612024743320732E00, 38134), -- Spell
(3205218938, 43287, 'esMX', 0x4741525249534F4E5F464F4C4C4F5745525F4F4E5F4D495353494F4E5F434F4D504C45544500456E206D697369C3B36E202D20436F6D706C65746164610001, 38134), -- GlobalStrings
(3205218938, 43286, 'esMX', 0x4741525249534F4E5F464F4C4C4F5745525F4D495353494F4E5F434F4D504C4554454400436F6D706C65746164610001, 38134), -- GlobalStrings
(3205218938, 43283, 'esMX', 0x434F56454E414E545F464F4C4C4F5745525F4D495353494F4E5F434F4D504C455445004465204176656E7475726173202D20436F6D706C65746164610001, 38134), -- GlobalStrings
(261693969, 59853, 'esMX', 0xFFFFFFFFFFFFFFFF4375656E746F73206465206C6120686F72612064656C2074C3A93A20537962696C6C652C206C6120706572646964610000CDE900007599F633010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F88700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59852, 'esMX', 0xFFFFFFFFFFFFFFFF4375656E746F73206465206C6120686F72612064656C2074C3A93A20477562C3AD6E207920547562C3AD6E0000CCE900007499F533010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59850, 'esMX', 0xFFFFFFFFFFFFFFFF4375656E746F73206465206C6120686F72612064656C2074C3A93A2056756C63610000CAE900007299F433010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(261693969, 59848, 'esMX', 0xFFFFFFFFFFFFFFFF4375656E746F73206465206C6120686F72612064656C2074C3A93A205468656F7461720000C8E900007199F333010000000000FFFF00000000000000000000000000000000000000000000000000000000000000000000000000000000F78700006D000000450300000000000003000000000129020000000000000000000000000000000000000000, 38134), -- QuestV2CliTask
(3776013982, 320740, 'esMX', 0x000000, 38134), -- Spell
(3776013982, 350249, 'esMX', 0x00446973746F7273696F6E6120656C207472616E73637572736F2064656C207469656D706F2C206C6F207175652061756D656E746120756E20247331252074752063656C6572696461642079206C6120646520747573205265666C656A6F732065786163746F7320647572616E74652024313130393039642E004C612063656C6572696461642061756D656E746120756E20247731252E20243F2457343E305B456C20C3AD6E64696365206465207469656D706F2061756D656E746120756E20247734252E5D5B5D00, 38134), -- Spell
(3776013982, 320914, 'esMX', 0x00447572616E746520416C746572617220656C207469656D706F2C2074C3BA207920747573205265666C656A6F732065786163746F73206F627469656E656E20756E6120446973746F727369C3B36E2074656D706F72616C2061646963696F6E616C20636F6E20756E2076616C6F722064656C20247331252E204E6F20736520766520616665637461646F20706F7220446973746F727369C3B36E2074656D706F72616C206E69206F74726F732065666563746F732073696D696C617265732E00447572616E746520416C746572617220656C207469656D706F2C2074C3BA207920747573205265666C656A6F732065786163746F73206F627469656E656E20756E6120446973746F727369C3B36E2074656D706F72616C2061646963696F6E616C20636F6E20756E2076616C6F722064656C20247331252E204E6F20736520766520616665637461646F20706F7220446973746F727369C3B36E2074656D706F72616C206E69206F74726F732065666563746F732073696D696C617265732E00, 38134), -- Spell
(3893700160, 169, 'esMX', 0x0F000000E2000000D20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 168, 'esMX', 0x0E000000E2000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 167, 'esMX', 0x0D000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 166, 'esMX', 0x0C000000DF000000CF0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 165, 'esMX', 0x0B000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 164, 'esMX', 0x0A000000DC000000CB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 163, 'esMX', 0x09000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 162, 'esMX', 0x08000000D8000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 161, 'esMX', 0x07000000D5000000C80000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 160, 'esMX', 0x06000000D2000000C50000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 159, 'esMX', 0x05000000D2000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 158, 'esMX', 0x04000000CF000000C20000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 157, 'esMX', 0x03000000CB000000BE0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 156, 'esMX', 0x02000000C8000000BB0000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3893700160, 155, 'esMX', 0x0100000000000000B70000004D000000, 38134), -- MythicPlusSeasonRewardLevels
(3776013982, 351967, 'esMX', 0x000000, 38134), -- Spell
(3776013982, 340882, 'esMX', 0x004C6C616D61206120426F6C736120646520676173657320706F7220736920657374C3A1206578747261766961646F206F206D756572746F2E004C6C616D61206120426F6C736120646520676173657320706F7220736920657374C3A1206578747261766961646F206F206D756572746F2E00, 38134), -- Spell
(2340571112, 755, 'esMX', 0xBD000000D51C0000D0040000060000008F1B00000000000000000000, 38134), -- ItemBonusListGroupEntry
(2998606315, 212, 'esMX', 0x0000000005000000803A09000000000000000000, 38134), -- ScheduledInterval
(3359787322, 20659, 'esMX', 0xB3500000, 38134); -- WorldState

INSERT INTO `hotfix_blob` (`TableHash`, `RecordId`, `locale`, `Blob`, `VerifiedBuild`) VALUES
(4021368146, 4553, 'esMX', 0x45737469676961206162616E646F6E616461000000000000000000D8020000424400000000000000000000000000000000000000, 38134), -- Vignette
(2202435563, 997132, 'esMX', 0x0C370F00240127010000F3170700, 38134), -- QuestPOIPoint
(2202435563, 997131, 'esMX', 0x0B370F00240128010000F2170700, 38134), -- QuestPOIPoint
(2921112328, 464883, 'esMX', 0xF31707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(2921112328, 464882, 'esMX', 0xF21707003B097E06000001E1E9000001000000871306000000000000000000, 38134), -- QuestPOIBlob
(3776013982, 335718, 'esMX', 0x00436172676172206520496E74657276656E6972207465206F746F72676120426C6F717565617220636F6E2065736375646F20647572616E746520247B2473312F313030307D20732C20C2A1526576616E6368612120792067656E65726120247B2433333537333473312F31307D20702E206465206972612E0000, 38134), -- Spell
(2948698321, 339, 'esMX', 0x6D68C604BDD61274, 38134), -- TactKeyLookup
(2948698321, 278, 'esMX', 0x7CB28F52811F5830, 38134), -- TactKeyLookup
(3776013982, 328547, 'esMX', 0x4E6563726F7365C3B16F7200496E63727573746120756E612070C3BA6120C3B373656120656E20656C206F626A657469766F206520696E666C6967652024733120702E206465206461C3B16F20792024333234303733733120702E206465206461C3B16F2064652073616E677261646F206361646120243332343037337431207320686173746120717565206D75657265206F2073616C6520646520636F6D626174652E200D0A0D0A526573746175726120756E61206361726761206375616E646F20656C206F626A657469766F206D756572652E0D0A0D0A7C6346464646464646464F746F726761203120702E20646520636F6D626F206D617320312061646963696F6E616C20706F7220636164612070C3BA6120C3B3736561206163746976612E7C720000, 38134), -- Spell
(1369604944, 2081, 'esMX', 0x000000000000000000000000000000000000000000000000210800006E1C00000000FF2200000000000000002C010000EE0204020000410B0000000000000000002208, 38134), -- SpellVisualMissile
(4033975491, 439153, 'esMX', 0x00000000000000000000000000000000000000000000000071B3060092001500000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(4033975491, 439152, 'esMX', 0x00000000000000000000000000000000000000000000000070B3060092001600000000000000000000000000000000000000000000000000000000803F00000000FFFFFFFFFFFF00000C000000000000000000000000FF340200, 38134), -- SpellVisualKitModelAttach
(1181150530, 377991, 'esMX', 0x050000001ABB020096D20100, 38134), -- SpellVisualKitEffect
(1181150530, 377990, 'esMX', 0x0500000019BB0200F3290200, 38134), -- SpellVisualKitEffect
(1181150530, 377988, 'esMX', 0x0500000019BB020054180200, 38134), -- SpellVisualKitEffect
(1181150530, 377987, 'esMX', 0x0500000018BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377986, 'esMX', 0x0500000017BB020088F60100, 38134), -- SpellVisualKitEffect
(1181150530, 377985, 'esMX', 0x0500000016BB0200820F0200, 38134), -- SpellVisualKitEffect
(1181150530, 377984, 'esMX', 0x0500000015BB02009FFA0100, 38134), -- SpellVisualKitEffect
(1181150530, 377983, 'esMX', 0x050000006C4E01004B4B0100, 38134), -- SpellVisualKitEffect
(1181150530, 377982, 'esMX', 0x0200000071B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377981, 'esMX', 0x0200000070B30600FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377980, 'esMX', 0x05000000EFCC0100FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377979, 'esMX', 0x06000000B7D20500FF340200, 38134), -- SpellVisualKitEffect
(1181150530, 377978, 'esMX', 0x0500000014BB020052F20100, 38134), -- SpellVisualKitEffect
(1181150530, 377977, 'esMX', 0x0500000013BB0200D8030200, 38134), -- SpellVisualKitEffect
(3425193231, 278473, 'esMX', 0x060000000D0000000000000000000000000000000000000002000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278472, 'esMX', 0x060000000D0000000000000000000000000000000000000001000000494B01001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278471, 'esMX', 0x030000000D0000000000000000000000000000000000000001000000FF3402001EA30100, 38134), -- SpellVisualEvent
(3425193231, 278470, 'esMX', 0x010000000200000000000000000000000000000000000000010000004A4B01001EA30100, 38134), -- SpellVisualEvent
(859088734, 381623, 'esMX', 0xFFFFFFFF360000000000, 38134), -- SpellVisualAnim
(4146370265, 107294, 'esMX', 0x0000000000000000000000000000000000000000000000000000000000000000FF22000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SpellVisual
(3266400455, 613060, 'esMX', 0x1ABB02002C713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613059, 'esMX', 0x1ABB02002B713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613058, 'esMX', 0x1ABB02002A713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613057, 'esMX', 0x1ABB020029713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613056, 'esMX', 0x1ABB020028713500010000803F, 38134), -- SoundKitEntry
(3266400455, 613055, 'esMX', 0x19BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613054, 'esMX', 0x19BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613053, 'esMX', 0x19BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613052, 'esMX', 0x19BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613051, 'esMX', 0x19BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613050, 'esMX', 0x19BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613049, 'esMX', 0x19BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613043, 'esMX', 0x18BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613042, 'esMX', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613041, 'esMX', 0x18BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613040, 'esMX', 0x18BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613039, 'esMX', 0x18BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613038, 'esMX', 0x17BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613037, 'esMX', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613036, 'esMX', 0x17BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613035, 'esMX', 0x17BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613034, 'esMX', 0x17BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613033, 'esMX', 0x16BB0200BC6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613032, 'esMX', 0x16BB0200BB6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613031, 'esMX', 0x16BB0200BA6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613030, 'esMX', 0x16BB0200B96A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613029, 'esMX', 0x16BB0200B86A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613028, 'esMX', 0x16BB0200B76A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613027, 'esMX', 0x16BB0200B66A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613018, 'esMX', 0x15BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613017, 'esMX', 0x15BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613016, 'esMX', 0x15BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613015, 'esMX', 0x15BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613014, 'esMX', 0x15BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613013, 'esMX', 0x15BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613012, 'esMX', 0x15BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613011, 'esMX', 0x14BB02004AE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613010, 'esMX', 0x14BB02004BE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613009, 'esMX', 0x14BB02004CE21900010000803F, 38134), -- SoundKitEntry
(3266400455, 613008, 'esMX', 0x13BB0200C36A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613007, 'esMX', 0x13BB0200C26A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613006, 'esMX', 0x13BB0200C16A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613005, 'esMX', 0x13BB0200C06A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613004, 'esMX', 0x13BB0200BF6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613003, 'esMX', 0x13BB0200BE6A3500010000803F, 38134), -- SoundKitEntry
(3266400455, 613002, 'esMX', 0x13BB0200BD6A3500010000803F, 38134), -- SoundKitEntry
(3232102598, 140456, 'esMX', 0xA82402001ABB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000F4010000F4010000580C00000000803F010000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140455, 'esMX', 0xA7240200AF6C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140454, 'esMX', 0xA6240200C06502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140453, 'esMX', 0xA5240200D07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140452, 'esMX', 0xA424020019BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140451, 'esMX', 0xA3240200020A00000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140450, 'esMX', 0xA224020018BB02000000A040000000410000000000000000000000000000000000000000020000000000000000E8030000E8030000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140449, 'esMX', 0xA124020017BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140448, 'esMX', 0xA02402003E7502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140447, 'esMX', 0x9F240200447502000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140446, 'esMX', 0x9E24020016BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140445, 'esMX', 0x9D24020015BB02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140444, 'esMX', 0x9C240200B9710200000040410000C04100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140443, 'esMX', 0x9B240200956C02000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140442, 'esMX', 0x9A240200177202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140441, 'esMX', 0x99240200F46F02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140440, 'esMX', 0x98240200817202000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140439, 'esMX', 0x97240200557102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140438, 'esMX', 0x96240200ED6602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140437, 'esMX', 0x952402001E7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140436, 'esMX', 0x94240200E56602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140435, 'esMX', 0x9324020014BB02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140434, 'esMX', 0x9224020013BB02000000A040000000410000000000000000000000000000000000000000020000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140433, 'esMX', 0x91240200666C02000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 140432, 'esMX', 0x90240200267102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123926, 'esMX', 0x16E40100407602000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123714, 'esMX', 0x42E30100437502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000101F4010000F4010000570C0000E8030000E8030000580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123675, 'esMX', 0x1BE30100457502000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123670, 'esMX', 0x16E301003D7502000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123594, 'esMX', 0xCAE20100F17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123515, 'esMX', 0x7BE20100A27402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C01000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123514, 'esMX', 0x7AE20100A17402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123504, 'esMX', 0x70E201009F7402000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001401F0000401F0000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123503, 'esMX', 0x6FE201009E7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000002C010000000000000000000000016400000064000000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 123502, 'esMX', 0x6EE201009D7402000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122935, 'esMX', 0x37E00100507202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122901, 'esMX', 0x15E00100167202000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000100FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122891, 'esMX', 0x0BE00100187202000000C0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122821, 'esMX', 0xC5DF0100D1710200000000400000804000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122814, 'esMX', 0xBEDF0100C87102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122807, 'esMX', 0xB7DF0100C17102000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001BC020000BC020000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122806, 'esMX', 0xB6DF0100C07102000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122804, 'esMX', 0xB4DF0100BE7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000009600000000000000000000000001C8000000C8000000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122709, 'esMX', 0x55DF01004A7102000000C0400000404100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122629, 'esMX', 0x05DF0100F97002000000A0400000004100000000000000000000000000000000000000000200000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B44300000000000000C800000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 122404, 'esMX', 0x24DE0100F56F02000000C0400000404100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121643, 'esMX', 0x2BDB0100D76C02000000803F0000004000000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000001012C0100002C010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121613, 'esMX', 0x0DDB0100976C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B4430000000000000000000000000000000000000000012C0100002C010000570C0000FFFFFFFFFFFFFFFF580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121609, 'esMX', 0x09DB0100906C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000B80B0000B80B0000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 121587, 'esMX', 0xF3DA0100686C02000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001F4010000F4010000570C0000E8030000E8030000580C00000000803F020000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 120239, 'esMX', 0xAFD50100E66602000000C040000040410000000000000000000000000000000000000000000000000000000000F4010000F4010000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000001E8030000E8030000570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 119974, 'esMX', 0xA6D40100D66502000000A0400000004100000000000000000000000000000000000000000000000000000000000000000000000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000002FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000803F00000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(3232102598, 25856, 'esMX', 0x00650000C9E600000000A04000002041000000000000000000000000000000000000000002E6000000E6000000E6000000E6000000000000803F0000803F0000803F0000803F0000803F0000803F0000803F000000000000000000000000000000000000B4430000B443000000000000000000000000000000000000000000FFFFFFFFFFFFFFFF570C0000FFFFFFFFFFFFFFFF580C00000000803F000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 38134), -- SoundKitAdvanced
(1485693696, 5565, 'esMX', 0x1ABB0200010000000069620000000000000100, 38134); -- SoundEnvelope
