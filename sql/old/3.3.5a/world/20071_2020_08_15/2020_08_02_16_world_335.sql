-- 18 Hermandad de ladrones
-- https://es.classic.wowhead.com/quest=18
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Hermandad_de_ladrones
DELETE FROM `quest_request_items_locale` WHERE `ID` = 18 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (18, 'esES', '¿Me traes los pañuelos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 18 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (18, 'esES', 'De vuelta con algunos pañuelos, ya veo... El Ejército de Ventormenta te agradece tu ayuda.', 0);

-- 5261 Eagan Desollapelambres
-- https://es.classic.wowhead.com/quest=5261
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 5261 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (5261, 'esES', 'Estoy buscando a alguien que cace lobos, ¿te interesa?', 0);

-- 33 Los lobos cruzan la frontera
-- https://es.wowhead.com/quest=33
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Los_lobos_cruzan_la_frontera
DELETE FROM `quest_request_items_locale` WHERE `ID` = 33 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (33, 'esES', 'Hola, $n. ¿Cómo va la caza de los lobos jóvenes malsanos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 33 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (33, 'esES', 'Era una tarea amarga, $gamigo:amiga;, pero has cumplido tu parte del trato.$B$BTengo algunas cosas que quizás te interesen, ¡elije lo que quieras!', 0);

-- 3903 Milly Osworth
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Milly_Osworth
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3903 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (3903, 'esES', '¿Que te envía el Ayudante del Alguacil Willem? Es valiente y voluntarioso, pero está en la Abadía de Villanorte...$B$B¿Tú podrías ayudarme?', 0);

-- 3904 La cosecha de Milly
-- https://wow-es.gamepedia.com/Misi%C3%B3n:La_cosecha_de_Milly
DELETE FROM `quest_request_items_locale` WHERE `ID` = 3904 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (3904, 'esES', '¿Traes la cosecha, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3904 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (3904, 'esES', '¡Gracias, $n! ¡Has salvado mi cosecha! Espero que hayas dada una lección a unos cuantos Defias.$B$B¡Aunque tengamos pocas tropas, tenemos la suerte de contar con valientes como tú!', 0);

-- 3905 Informe de la vendimia
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Informe_de_la_vendimia
DELETE FROM `quest_request_items_locale` WHERE `ID` = 3905 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (3905, 'esES', '¡Te veo muy bien! ¡Siéntate y tómate algo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 3905 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (3905, 'esES', 'Veamos...$B$BOh, has salvado la uva; me preocupé cuando me habló de esos villanos en los viñedos. Por suerte, nunca perdí la fe en la Luz.$B$BY ahora, gracias a tu valor, podremos hacer vino. Que la Luz te acompañe y te proteja, $n. ', 0);

-- 6 La recompensa por Garrick Piesuaves 
-- https://wow-es.gamepedia.com/Misi%C3%B3n:La_recompensa_por_Garrick_Piesuaves
DELETE FROM `quest_request_items_locale` WHERE `ID` = 6 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (6, 'esES', '¿Has encontrado la choza de Garrick? ¿Has acabado con él?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 6 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (6, 'esES', '¡Lo has conseguido! Elwynn te estará muy agradecido por esto. ¡Acabas de ganarte una hermosa recompensa!', 0);

-- 54 Informa en Villadorada
-- https://es.wowhead.com/quest=54
DELETE FROM `quest_request_items_locale` WHERE `ID` = 54 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (54, 'esES', '¿Traes noticias de McBride? Villanorte es un jardín comparada con el Bosque de Elwynn; me pregunto qué querrá McBride.$B$BDame los documentos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 54 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (54, 'esES', 'Dice que te han nombrado ayudante del alguacil de Ventormenta. Enhorabuena.$B$BY buena suerte, el trabajo no será fácil ahora que el ejército parece que anda ocupado con la nobleza.$B$BQué misteriosa es la política en estos tiempos difíciles...', 0);

-- 2158 Descanso y relajación
-- https://wow-es.gamepedia.com/Misi%C3%B3n:Descanso_y_relajaci%C3%B3n
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 2158 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (2158, 'esES', '¡Descanso y relax para quien no puede más! ¡Ese es nuestro lema! Por favor, toma asiento cerca del fuego y da un respiro a tus cansados huesos.$B$B¿Te gustaría probar una selección de nuestra excelente comida y bebida? ', 0);

-- 62 La Mina Abisal
-- https://wow-es.gamepedia.com/Misi%C3%B3n:La_Mina_Abisal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 62 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (62, 'esES', '¿Qué tienes que informar, $n? ¿Has estado en la Mina Abisal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 62 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (62, 'esES', 'Esta es una mala noticia. ¿Qué será lo siguiente, dragones? Vamos a tener que aumentar nuestras patrullas cerca de la mina. Gracias por tu trabajo, $n. Y mantente al tanto... Podría tener otra tarea para ti.', 0);

-- 47 Intercambio de polvo de oro
-- https://es.wowhead.com/quest=47
-- https://wow-es.gamepedia.com/Misión:Intercambio_de_polvo_de_oro
DELETE FROM `quest_request_items_locale` WHERE `ID` = 47 AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (47, 'esES', '¡Psst! ¿Tienes ese Polvo de Oro para mí... para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 47 AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (47, 'esES', 'Gracias por el Polvo de oro, $n. Aquí tienes tu dinero y... este detalle de mis socios. Puede que lo encuentres útil... útil. ', 0);

-- Instructores (trainer_locale)
DELETE FROM `trainer_locale` WHERE `Id` BETWEEN 1 AND 124 AND `locale` = 'esES';
DELETE FROM `trainer_locale` WHERE `Id` = 126 AND `locale` = 'esES';
INSERT INTO `trainer_locale` (`Id`, `locale`, `Greeting_lang`, `VerifiedBuild`) VALUES
(1, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(2, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(3, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(4, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(5, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(6, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(7, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(8, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(9, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(10, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(11, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(12, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(13, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(14, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(15, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(16, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(17, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(18, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(19, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(20, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(21, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(22, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(23, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(24, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(25, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(26, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(27, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(28, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(29, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(30, 'esES', '¡$gBienvenido:Bienvenida;!', 0),
(31, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(32, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(33, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(34, 'esES', '¡Saludos, $c! ¿$gListo:Lista; para el entrenamiento?', 0),
(35, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(36, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(37, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(38, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(39, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(40, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(41, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(42, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(43, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(44, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(45, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(46, 'esES', '¡Saludos! ¿Puedo enseñarte algo?', 0),
(47, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(48, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(49, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(50, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(51, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(52, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(53, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(54, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(55, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(56, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(57, 'esES', '¡Saludos! ¿$gListo:Lista; para el entrenamiento?', 0),
(58, 'esES', '¿Quieres aprender a convertir el mineral que encuentras en armas y armaduras de metal?', 0),
(59, 'esES', '¿Quieres aprender a convertir el mineral que encuentras en armas y armaduras de metal?', 0),
(60, 'esES', '¿Quieres aprender a convertir el mineral que encuentras en armas y armaduras de metal?', 0),
(61, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir las pieles de bestias en armaduras?', 0),
(62, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir las pieles de bestias en armaduras?', 0),
(63, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir las pieles de bestias en armaduras?', 0),
(64, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir las pieles de bestias en armaduras?', 0),
(65, 'esES', 'Con la alquimia puedes convertir las hierbas encontradas en pociones curativas y de otro tipo.', 0),
(66, 'esES', 'Con la alquimia puedes convertir las hierbas encontradas en pociones curativas y de otro tipo.', 0),
(67, 'esES', 'Con la alquimia puedes convertir las hierbas encontradas en pociones curativas y de otro tipo.', 0),
(68, 'esES', 'Con la alquimia puedes convertir las hierbas encontradas en pociones curativas y de otro tipo.', 0),
(69, 'esES', 'La búsqueda de hierbas requiere conocimiento e instinto.', 0),
(70, 'esES', 'La búsqueda de hierbas requiere conocimiento e instinto.', 0),
(71, 'esES', 'La búsqueda de hierbas requiere conocimiento e instinto.', 0),
(72, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir la tela encontrada en armaduras de tela?', 0),
(73, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir la tela encontrada en armaduras de tela?', 0),
(74, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir la tela encontrada en armaduras de tela?', 0),
(75, 'esES', '¿Puedo enseñarte cómo convertir la carne que encuentras en las bestias en un festín?', 0),
(76, 'esES', '¿Puedo enseñarte cómo convertir la carne que encuentras en las bestias en un festín?', 0),
(77, 'esES', '¿Puedo enseñarte cómo convertir la carne que encuentras en las bestias en un festín?', 0),
(78, 'esES', 'No has vivido hasta que has cavado profundamente en la tierra.', 0),
(79, 'esES', 'No has vivido hasta que has cavado profundamente en la tierra.', 0),
(80, 'esES', 'No has vivido hasta que has cavado profundamente en la tierra.', 0),
(81, 'esES', 'Aquí, déjame mostrarte cómo vendar esas heridas ...', 0),
(82, 'esES', 'Aquí, déjame mostrarte cómo vendar esas heridas ...', 0),
(83, 'esES', 'Aquí, déjame mostrarte cómo vendar esas heridas ...', 0),
(84, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(85, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(86, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(87, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(88, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(89, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(90, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(91, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(92, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(93, 'esES', '¿Puedo enseñarte cómo convertir la carne que encuentras en las bestias en un festín?', 0),
(94, 'esES', 'Encantar es el arte de mejorar los objetos existentes a través de la magia.', 0),
(95, 'esES', 'Encantar es el arte de mejorar los objetos existentes a través de la magia.', 0),
(96, 'esES', 'Encantar es el arte de mejorar los objetos existentes a través de la magia.', 0),
(97, 'esES', 'Puedo enseñarte cómo usar una caña de pescar.', 0),
(98, 'esES', 'Puedo enseñarte cómo usar una caña de pescar.', 0),
(99, 'esES', 'Puedo enseñarte cómo usar una caña de pescar.', 0),
(100, 'esES', 'Se requiere una mano firme para quitar el cuero de una bestia muerta.', 0),
(101, 'esES', 'Se requiere una mano firme para quitar el cuero de una bestia muerta.', 0),
(102, 'esES', 'Se requiere una mano firme para quitar el cuero de una bestia muerta.', 0),
(103, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(104, 'esES', '¿Quieres aprender a convertir el mineral que encuentras en armas y armaduras de metal?', 0),
(105, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir las pieles de bestias en armaduras?', 0),
(106, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir las pieles de bestias en armaduras?', 0),
(107, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir las pieles de bestias en armaduras?', 0),
(108, 'esES', '¡Saludos! ¿Puedo enseñarte cómo convertir la tela encontrada en armaduras de tela?', 0),
(109, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(110, 'esES', 'No has vivido hasta que has cavado profundamente en la tierra.', 0),
(111, 'esES', '¡Saludos! ¿Puedo enseñarte cómo tallar gemas preciosas y joyas artesanales??', 0),
(112, 'esES', '¡Saludos! ¿Puedo enseñarte cómo tallar gemas preciosas y joyas artesanales??', 0),
(113, 'esES', '¡Saludos! ¿Puedo enseñarte cómo tallar gemas preciosas y joyas artesanales??', 0),
(114, 'esES', 'Encantar es el arte de mejorar los objetos existentes a través de la magia.', 0),
(115, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(116, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(117, 'esES', '¿Puedo enseñarte cómo convertir la carne que encuentras en las bestias en un festín?', 0),
(118, 'esES', 'La ingeniería es muy simple una vez que entiendes lo básico.', 0),
(119, 'esES', '¿Te gustaría aprender las complejidades de la inscripción?', 0),
(120, 'esES', '¿Te gustaría aprender las complejidades de la inscripción?', 0),
(121, 'esES', '¿Te gustaría aprender las complejidades de la inscripción?', 0),
(122, 'esES', 'Con la alquimia puedes convertir las hierbas encontradas en pociones curativas y de otro tipo.', 0),
(123, 'esES', '¿Quieres aprender a convertir el mineral que encuentras en armas y armaduras de metal?', 0),
(124, 'esES', '¿Quieres aprender a convertir el mineral que encuentras en armas y armaduras de metal?', 0),
(126, 'esES', '¿Puedo enseñarte cómo convertir la carne que encuentras en las bestias en un festín?', 0);
