DELETE FROM `creature_template_addon` WHERE  `entry`=160737;

DELETE FROM creature   WHERE id NOT IN (SELECT entry FROM creature_template);
DELETE FROM gameobject WHERE id NOT IN (SELECT entry FROM gameobject_template);
DELETE FROM creature_addon   WHERE guid NOT IN (SELECT guid FROM creature);
DELETE FROM gameobject_addon WHERE guid NOT IN (SELECT guid FROM gameobject);
DELETE FROM creature_template_addon   WHERE entry NOT IN (SELECT entry FROM creature_template);
DELETE FROM gameobject_template_addon WHERE entry NOT IN (SELECT entry FROM gameobject_template);

DELETE FROM `areatrigger_template` WHERE `Id` IN (25730, 26911, 25732, 22448, 25311, 24252);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(25730, 1, 0, 0, 2, 2, 0, 0, 0, 0, 38134),
(26911, 1, 0, 0, 3, 3, 0, 0, 0, 0, 38134),
(25732, 1, 0, 4, 10, 10, 0, 0, 0, 0, 38134),
(22448, 1, 1, 2048, 30, 0.5, 7.5, 30, 0.5, 7.5, 38134),
(25311, 1, 0, 4, 5, 5, 0, 0, 0, 0, 38134),
(24252, 1, 1, 4, 15, 15, 5, 15, 15, 5, 38134);


DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=21467 AND `AreaTriggerId`=25730) OR (`SpellMiscId`=22386 AND `AreaTriggerId`=26911) OR (`SpellMiscId`=21469 AND `AreaTriggerId`=25732) OR (`SpellMiscId`=21900 AND `AreaTriggerId`=22448) OR (`SpellMiscId`=20985 AND `AreaTriggerId`=25311) OR (`SpellMiscId`=20345 AND `AreaTriggerId`=24252);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(21467, 25730, 0, 0, 0, 0, 0, 0, 0, 0, 12000, 38134), -- SpellId : 338924
(22386, 26911, 0, 0, 0, 0, 0, 0, 0, 0, 600000, 38134), -- SpellId : 348548
(21469, 25732, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 339676
(21900, 22448, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 343593
(20985, 25311, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- SpellId : 333928
(20345, 24252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- SpellId : 327954

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6039 AND `AreaTriggerId`=10727); -- SpellId : 0

UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=13479 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=13479 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=13479 AND `Idx`=0);

DELETE FROM `conversation_actor_template` WHERE `Id`=76489;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(76489, 164937, 95624, 38134);


DELETE FROM `conversation_line_template` WHERE `Id` IN (34157, 33595, 33585, 33584, 33583, 33582, 40579, 40578, 33529, 33391, 33390, 36737, 36736, 36735, 36734, 36733);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(34157, 0, 0, 0, 0, 38134),
(33595, 18600, 0, 0, 0, 38134),
(33585, 14200, 0, 1, 0, 38134),
(33584, 10400, 0, 0, 0, 38134),
(33583, 3450, 0, 1, 0, 38134),
(33582, 0, 0, 0, 0, 38134),
(40579, 15326, 0, 0, 0, 38134),
(40578, 0, 0, 0, 0, 38134),
(33529, 7550, 0, 0, 0, 38134),
(33391, 4100, 0, 1, 0, 38134),
(33390, 0, 0, 0, 0, 38134),
(36737, 77372, 1565, 0, 0, 38134),
(36736, 54687, 1565, 0, 0, 38134),
(36735, 31580, 1565, 0, 0, 38134),
(36734, 11614, 1565, 0, 0, 38134),
(36733, 0, 1565, 0, 0, 38134);

UPDATE `conversation_line_template` SET `StartTime`=14850, `VerifiedBuild`=38134 WHERE `Id`=33534;
UPDATE `conversation_line_template` SET `StartTime`=10600, `VerifiedBuild`=38134 WHERE `Id`=33533;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=33532;


DELETE FROM `conversation_template` WHERE `Id` IN (13705, 14663, 16118, 13480, 13430, 13498);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(13705, 34157, 8362, 0, 38134),
(14663, 36733, 99248, 0, 38134),
(16118, 40578, 30750, 0, 38134),
(13480, 33535, 18600, 0, 38134),
(13430, 33390, 11600, 0, 38134),
(13498, 33582, 21050, 0, 38134);

UPDATE `conversation_template` SET `LastLineEndTime`=20200, `VerifiedBuild`=38134 WHERE `Id`=13479;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (330193 /*Celda de ánima*/, 325740 /*Ánima saqueada*/, 351883 /*Runa de placa de presión*/, 351484 /*Puerta de celda*/, 351483 /*Puerta de celda*/, 349606 /*Jaula de almas*/, 364381 /*Salir de Torghast*/, 364880 /*Piso invisible*/, 341819 /*Puerta*/, 355046 /*Jaula*/, 340626 /*Puerta*/, 349591 /*Espiral de cuerda*/, 364379 /*Antecámara de Torghast*/, 364378 /*Portal a la Mazmorra del Tallarrunas*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(330193, 0, 33587232, 11493, 2664), -- Celda de ánima
(325740, 0, 33587232, 11493, 2664), -- Ánima saqueada
(351883, 0, 16, 0, 0), -- Runa de placa de presión
(351484, 0, 48, 0, 0), -- Puerta de celda
(351483, 0, 48, 0, 0), -- Puerta de celda
(349606, 0, 48, 14852, 0), -- Jaula de almas
(364381, 0, 32, 0, 18072), -- Salir de Torghast
(364880, 114, 0, 0, 0), -- Piso invisible
(341819, 114, 32, 0, 0), -- Puerta
(355046, 0, 16, 0, 0), -- Jaula
(340626, 114, 32, 0, 0), -- Puerta
(349591, 0, 262144, 14411, 0), -- Espiral de cuerda
(364379, 35, 32, 0, 0), -- Antecámara de Torghast
(364378, 35, 32, 0, 0); -- Portal a la Mazmorra del Tallarrunas

DELETE FROM `creature_template_locale` WHERE (`locale`='esMX' AND `entry` IN (172801,157406,164808,173191,166660,155812,167230,168114,170130,167231,166953,166713,169628,169635,174803,155945,168108,175069,155824,157340,169782,157807,155831,171166,168109,155790,166360,155830,155793,164937,171179,173580,156681,173351,156686,168432,175211,156732,156689,156687,176332,170651));
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `Title`, `TitleAlt`, `VerifiedBuild`) VALUES
(172801, 'esMX', 'Cadena', NULL, NULL, NULL, 38134),
(157406, 'esMX', 'Renavyth', NULL, NULL, NULL, 38134),
(164808, 'esMX', 'Medallón de Renavyth', NULL, NULL, NULL, 38134),
(173191, 'esMX', 'Acechador de almas V\'lara', NULL, NULL, NULL, 38134),
(166660, 'esMX', 'Palanca', NULL, NULL, NULL, 38134),
(155812, 'esMX', 'Ritualista jurafauces', NULL, NULL, NULL, 38134),
(167230, 'esMX', 'Esqueleto maldraxxi', NULL, NULL, NULL, 38134),
(168114, 'esMX', 'Placa de presión', NULL, NULL, NULL, 38134),
(170130, 'esMX', 'Trampa de púas', NULL, NULL, NULL, 38134),
(167231, 'esMX', 'Nigromante maldraxxi', NULL, NULL, NULL, 38134),
(166953, 'esMX', 'Elite Rune Bunny', NULL, NULL, NULL, 38134),
(166713, 'esMX', 'Puerta de celda', NULL, NULL, NULL, 38134),
(169628, 'esMX', 'Restos de alma atormentada', 'Restos de alma atormentada', NULL, NULL, 38134),
(169635, 'esMX', 'Restos de alma atormentada', NULL, NULL, NULL, 38134),
(174803, 'esMX', 'Guadaña de almas', NULL, NULL, NULL, 38134),
(155945, 'esMX', 'Gherus el Encadenado', NULL, NULL, NULL, 38134),
(168108, 'esMX', 'Creación torpe potenciada', NULL, NULL, NULL, 38134),
(175069, 'esMX', 'Salir de Torghast', NULL, NULL, NULL, 38134),
(155824, 'esMX', 'Creación torpe', NULL, NULL, NULL, 38134),
(157340, 'esMX', 'Restos esqueléticos', NULL, NULL, NULL, 38134),
(169782, 'esMX', 'Restos de alma esclava', NULL, NULL, NULL, 38134),
(157807, 'esMX', 'Tejealmas jurafauces', NULL, NULL, NULL, 38134),
(155831, 'esMX', 'Atrapaalmas jurafauces', NULL, NULL, NULL, 38134),
(171166, 'esMX', 'Restos de alma desbocada', NULL, NULL, NULL, 38134),
(168109, 'esMX', 'Ritualista jurafauces potenciado', NULL, NULL, NULL, 38134),
(155790, 'esMX', 'Acólito jurafauces', NULL, NULL, NULL, 38134),
(166360, 'esMX', 'Punto de agarre', NULL, NULL, NULL, 38134),
(155830, 'esMX', 'Discípulo jurafauces', NULL, NULL, NULL, 38134),
(155793, 'esMX', 'Restos esqueléticos', NULL, NULL, NULL, 38134),
(164937, 'esMX', 'Tallarrunas', NULL, NULL, NULL, 38134),
(171179, 'esMX', 'Buscaalmas del Crisol', NULL, NULL, NULL, 38134),
(173580, 'esMX', 'Inquisidor Devaki', NULL, NULL, NULL, 38134),
(156681, 'esMX', 'Costurero Au\'phes', NULL, 'Instructor de sastrería', NULL, 38134),
(173351, 'esMX', 'Facilitador de comercio', NULL, 'Cártel Ba', NULL, 38134),
(156686, 'esMX', 'Seleccionador Au\'mar', NULL, 'Instructor de herboristería', NULL, 38134),
(168432, 'esMX', 'Ve\'rayn', NULL, 'Activos y pasivos', NULL, 38134),
(175211, 'esMX', 'Asistente real', 'Asistente real', NULL, NULL, 38134),
(156732, 'esMX', 'Distribuidor Au\'sha', NULL, 'Suministros de inscripción', NULL, 38134),
(156689, 'esMX', 'Distribuidor Au\'naci', NULL, 'Suministros de alquimia', NULL, 38134),
(156687, 'esMX', 'Elixirista Au\'pyr', NULL, 'Instructor de alquimia', NULL, 38134),
(176332, 'esMX', 'Caballero de la Espada de Ébano', 'Caballero de la Espada de Ébano', NULL, NULL, 38134),
(170651, 'esMX', 'Baine Pezuña de Sangre', NULL, 'Gran jefe', NULL, 38134);


UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=63508 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=115146 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=32638 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=17252 AND `locale`='esMX');
UPDATE `creature_template_locale` SET `VerifiedBuild`=38134 WHERE (`entry`=32639 AND `locale`='esMX');


DELETE FROM `quest_template_locale` WHERE (`locale`='esMX' AND `ID` IN (59344,60269,60268,62967,60281,60646,61075,63051,63062,63031,62910,62932));
INSERT INTO `quest_template_locale` (`ID`, `locale`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES
(59344, 'esMX', 'Medallón de Renavyth', '', '', '', '', '', '', '', '', 38134),
(60269, 'esMX', 'Nuevo despertar', 'Encuentra un recuerdo robado del tallarrunas.', 'Si logras recuperar mis recuerdos, podré ayudarte. Al menos eso creo.\n\nDespués, tal vez podamos ayudarnos mutuamente.', '', 'Esta criatura, uno de los tenientes del Carcelero, vigila atentamente las Fauces.', 'Odalrik', '', '', '', 38134),
(60268, 'esMX', 'En lo profundo', 'Habla con el prisionero y descubre más sobre su situación.', '¿Quién... quién eres? ¿Viniste a extraer más de mis recuerdos?$b$bMe temo que no queda ninguno útil, excepto los recuerdos de mi encierro.$b$b¿O viniste por otra razón?', '', '', '', '', '', '', 38134),
(62967, 'esMX', 'La prisión de los olvidados', 'Averigua dónde usar la llave de los olvidados.', 'He descubierto un objeto interesante que tenía el celador que mataste en la torre. \n\nSerá mejor que no me preguntes cómo se lo que haces y en qué partes de la torre. Digamos que tengo mis recursos.\n\nPero esta llave puede conducir a lugares interesantes dentro de Torghast. O hacia algo horrible. Con toda probabilidad, algo horrible.\n\nDebes explorar un poco y ver qué puertas abre.', '', '', '', '', '', '', 38134),
(60281, 'esMX', 'Regla 4: Haz una lista', 'Mata al inquisidor Devaki y averigua cómo intenta rastrear a Ve\'nari.', 'He descubierto que uno de los inquisidores del Carcelero está intentando crear un método para rastrear mis movimientos.\n\nSin duda, es un problema para mí... y en consecuencia, para ti.\n\nEl inquisidor ha pasado a ser el primero en mi lista de potenciales amenazas. Antes, hubiera tenido que ocuparme de él yo misma. Pero ahora... tengo $gun socio:una socia;.\n\nTermina con esto, ¿sí? Y si puedes, averigua cómo es que intentaba rastrearme exactamente.', '', 'Mata al Inquisidor Devaki y descubre cómo consiguió información sobre los informantes.', 'Inquisidor Devaki', '', '', '', 38134),
(60646, 'esMX', 'Cosecha de miserias', 'Recolecta $1oa esencias de miseria y destruye los conductos de miseria.', 'Los jurafauces han comenzado a cosechar la miseria de las almas que fluyen por el Gorgoa, el Río de Almas.\n\n¿Por qué? Todavía no lo sé. Pero es nuestro deber detenerlos.\n\nDestruye los conductos en los que han depositado la miseria y tráeme algunas muestras de su trabajo. \n\nTal vez, si investigo un poco, puedo discernir sus intenciones.', '', '', '', '', '', '', 38134),
(61075, 'esMX', 'Un destello de luz', 'Derrota $1oa ojos de la condenación.', 'Gorgoa es una fuerza proteica alimentada por las almas que llegan de muchos mundos. Entran donde nace el río, en un lugar al que bautizaron \"Crisol de los Malditos\".\n\nLos imperturbables ojos del Carcelero patrullan el río y vigilan que ningún alma intente escapar.\n\nCiega a los ojos que las encuentran. Ciérralos de una vez por todas. \n\nToma esto y haz lo que sea necesario.', '', '', '', '', '', '', 38134),
(63051, 'esMX', 'Problemas de confianza', 'Responde las preguntas de Ve\'rayn acerca de las Fauces.', '¡Ah, Surcafauces! Permíteme presentarme. Soy Ve\'rayn, y estoy a cargo de los libros contables del Cártel Ve.\n\nSupe que puedes viajar libremente entre Oribos y las Fauces, un lugar de sumo interés para mi cártel.\n\n¿Podría hacerte algunas preguntas sobre eso?\n\nDesde luego, recibirás una compensación adecuada por tu tiempo y tu información. Después de todo, son dos bienes muy valiosos.', '', '', '', '', '', 'Habla con Ve\'nari en el interior de las Fauces', 38134),
(63062, 'esMX', 'Tormentos para todos', 'Llena el succionador fásico en las fisuras del alma de Detrithos y devuélveselo a Ve\'nari en las Fauces.', '<Han abandonado un dispositivo de negociantes aquí. Parece que lo usaron para succionar energía de fallas de energía de alma que entraron en erupción en esta zona.\n\nEs muy extraño que los negociantes se propusieran recolectar esta energía si no servía para algo. Tal vez deberías terminar lo que comenzaron.>', '', '', '', '', '', 'Vuelve a ver a Ve\'nari en el Refugio de Ve\'nari.', 38134),
(63031, 'esMX', 'Adquisición: estigia cristalizada', 'Recoge $1oa de estigia cristalizada y lleva todo a Ve\'nari, en las Fauces.', '<Este fragmento de cristal parece ser parte de una de las enormes estructuras cristalinas que hay en toda el área. Vibra por la energía contenida.\n\nEs probable que Ve\'nari tenga mucho interés en cualquiera de estos fragmentos que encuentres.>', '', '', '', '', '', 'Vuelve con Ve\'nari al Refugio de Ve\'nari.', 38134),
(62910, 'esMX', 'Contra todos los pronósticos', 'Mata a 25 jugadores de la Horda de nivel 60 dentro de las Tierras de las Sombras.', 'Tus eternos enemigos de la Horda son cada vez más fuertes y numerosos en las Tierras de las Sombras. \n\n¿Tú y tus camaradas piensan rendirse a su poderío? \n\nNo, supongo que no. Parece que ni siquiera la muerte ha aplacado tu sed de batalla. \n\nSi logras eliminar a tus enemigos contra todos los pronósticos te daré una buena recompensa.', '', '', '', '', '', '', 38134),
(62932, 'esMX', 'Explorar Torghast', 'Explota Torghast en busca de pistas para localizar a tus aliados.', 'Baine está a salvo, pero nuestros otros aliados aún son prisioneros del Carcelero y siguen corriendo un grave peligro.\n\nTorghast es un lugar que cambia constantemente, según los caprichos de su amo. No podrás encontrar a nuestros aliados con medios convencionales.\n\nEntra a los bloques de celdas e intenta obtener alguna información. Busca cualquier pista que nos pueda llevar hasta nuestros amigos, y tráemela.', '', '', '', '', '', 'Regresa con el alto señor Bolvar Fordragón en Oribos', 38134);


DELETE FROM `quest_objectives_locale` WHERE (`locale`='esMX' AND `ID` IN (396362,411627,398033,398032,409004,409228,409227,409112,409150,408920,408951));
INSERT INTO `quest_objectives_locale` (`ID`, `locale`, `QuestId`, `StorageIndex`, `Description`, `VerifiedBuild`) VALUES
(396362, 'esMX', 59344, 0, 'Ayuda a Renavyth a recuperar su medallón', 38134),
(411627, 'esMX', 60269, 2, 'Regresa a la Mazmorra del Tallarrunas', 38134),
(398033, 'esMX', 60269, 0, 'Recupera el recuerdo del tallarrunas de las garras de Odalrik', 38134),
(398032, 'esMX', 60268, 0, 'Obtén más información sobre el prisionero', 38134),
(409004, 'esMX', 60281, 1, 'Método de rastreo encontrado', 38134),
(409228, 'esMX', 60646, 2, 'Conducto de miseria norte destruido', 38134),
(409227, 'esMX', 60646, 0, 'Conducto de miseria sur destruido', 38134),
(409112, 'esMX', 63051, 0, 'Preguntas de Ve\'rayn contestadas', 38134),
(409150, 'esMX', 63062, 0, 'Succionador fásico lleno', 38134),
(408920, 'esMX', 62910, 0, 'Mata jugadores de la Horda', 38134),
(408951, 'esMX', 62932, 0, 'Información adquirida', 38134);


DELETE FROM `quest_greeting_locale` WHERE (`ID`=174922 AND `Type`=0 AND `locale`='esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(174922, 0, 'esMX', 'Saludos, mortal. Sirvo para concertar interacciones que podrían beneficiar a los observadores.', 38134);


DELETE FROM `quest_request_items_locale` WHERE (`ID`=61099 AND `locale`='esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(61099, 'esMX', '¡Lo has encontrado!', 38134);

DELETE FROM `playerchoice_locale` WHERE `ChoiceId` IN (598, 611, 573);
INSERT INTO `playerchoice_locale` (`ChoiceId`, `Locale`, `Question`, `VerifiedBuild`) VALUES
(598, 'esMX', '', 38134),
(611, 'esMX', 'c�4����-wEl ánima toma la', 38134),
(573, 'esMX', '', 38134);


DELETE FROM `playerchoice_response_locale` WHERE (`ResponseId`=0 AND `ChoiceId` IN (588,598,573,611));
INSERT INTO `playerchoice_response_locale` (`ChoiceId`, `ResponseId`, `Locale`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `VerifiedBuild`) VALUES
(588, 0, 'esMX', '@Abalorios de oración profanados$332407sc�4����-w03)�@Incensario almaforjado$332534sb�4����-�', '', '¿Qué forma debería tomar el ánima?', '', '', '', 38134),
(598, 0, 'esMX', '�@Gratitud de los Venthyr$306575sb�4�p�!-��El prisionero agradecido te entrega un poco de ánima. ¿Qué forma debería tomar?', '', '', '', '', '', 38134),
(573, 0, 'esMX', '@@Capa de subterfugio de V\'lara$338948sc�4�p�!-,+$v�@Broche protegealmas$338922sb�4', '', '�p�!-�+¿Qué forma debería tomar el ánima?', '', '', '', 38134),
(611, 0, 'esMX', 'Abalorios de oración profanados', '', '', '', '$332407s', '', 38134);


DELETE FROM `scene_template` WHERE (`SceneId`=2413 AND `ScriptPackageID`=2812) OR (`SceneId`=2560 AND `ScriptPackageID`=3000);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2413, 20, 2812, 0),
(2560, 20, 3000, 0);


DELETE FROM `quest_offer_reward` WHERE `ID` IN (60268 /*-Unknown-*/, 60267 /*-Unknown-*/, 63051 /*-Unknown-*/, 63346 /*-Unknown-*/, 61099 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(60268, 0, 0, 0, 0, 0, 0, 0, 0, 'Tú podrías ser la clave para mi libertad. ¿Puedes ayudarme, mortal?', 38134), -- -Unknown-
(60267, 0, 0, 0, 0, 0, 0, 0, 0, '<Cuando colocas la llave en el dispositivo, vibra por un momento y comienza a abrirse.>', 38134), -- -Unknown-
(63051, 1, 0, 0, 0, 0, 0, 0, 0, '¿El Cártel Ve te hizo preguntas sobre mí?\n\nMe siento halagada. Recuerda que nunca debes contarles nada.\n\nJamás.\n\nVen, hay trabajo por hacer.', 38134), -- -Unknown-
(63346, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, $n. He oído muchas historias sobre tu habilidad en el campo de batalla. \n\nMe interesa que grandes combatientes como tú estén bien equipados. Zo\'dash tiene autorización para mejorar tus armas y armaduras.', 38134), -- -Unknown-
(61099, 1, 1, 0, 0, 0, 0, 0, 0, 'Hallar a Baine no fue una hazaña sencilla. Pero has enfrentado los horrores de esa torre y has triunfado.\n\nBien hecho.\n\nPero me temo que tu trabajo acaba de comenzar.', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=60269 AND `BlobIndex`=1 AND `Idx1`=7) OR (`QuestID`=60269 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=60268 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=60268 AND `BlobIndex`=2 AND `Idx1`=5) OR (`QuestID`=60268 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=60268 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=60268 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=60268 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=60268 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=61075 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=61075 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=61075 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=63051 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=63051 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(60269, 1, 7, 32, 0, 0, 2222, 1543, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60269, 0, 6, 32, 0, 0, 2453, 1912, 0, 0, 0, 0, 0, 2026717, 0, 38134), -- -Unknown-
(60268, 0, 6, 32, 0, 0, 2453, 1912, 0, 0, 0, 0, 0, 2026717, 0, 38134), -- -Unknown-
(60268, 2, 5, 0, 398032, 164937, 2222, 1543, 0, 0, 0, 0, 0, 1872077, 0, 38134), -- -Unknown-
(60268, 1, 4, 0, 398032, 164937, 2453, 1911, 0, 0, 0, 0, 0, 2026735, 0, 38134), -- -Unknown-
(60268, 0, 3, 0, 398032, 164937, 2453, 1912, 0, 0, 0, 0, 0, 2026717, 0, 38134), -- -Unknown-
(60268, 2, 2, -1, 0, 0, 2453, 1911, 0, 0, 0, 0, 0, 2026735, 0, 38134), -- -Unknown-
(60268, 1, 1, -1, 0, 0, 2222, 1543, 0, 0, 0, 0, 0, 1872077, 0, 38134), -- -Unknown-
(60268, 0, 0, -1, 0, 0, 2453, 1912, 0, 0, 0, 0, 0, 2026717, 0, 38134), -- -Unknown-
(61075, 0, 2, 32, 0, 0, 2222, 1543, 0, 0, 0, 0, 0, 1890492, 0, 38134), -- -Unknown-
(61075, 0, 1, 0, 405172, 171179, 2222, 1543, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(61075, 0, 0, -1, 0, 0, 2222, 1543, 0, 0, 0, 0, 0, 1890492, 0, 38134), -- -Unknown-
(63051, 0, 1, 0, 409112, 168432, 2222, 1671, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(63051, 0, 0, -1, 0, 0, 2222, 1543, 0, 0, 0, 0, 0, 1978804, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `ObjectiveIndex`=2, `QuestObjectiveID`=411627, `QuestObjectID`=21983, `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `ObjectiveIndex`=2, `QuestObjectiveID`=411627, `QuestObjectID`=21983, `UiMapID`=1911, `SpawnTrackingID`=2029590, `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `BlobIndex`=2 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=3 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=0 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=5 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=4 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=3 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=63346 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=63346 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61331 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61331 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=0 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=5 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=4 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=3 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50605 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=5 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=4 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=3 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=2 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=60269 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=60269 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=60268 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=60268 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=60268 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=60268 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=60268 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60268 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60268 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=61075 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=61075 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=61075 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=61075 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=61075 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=61075 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=61075 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=61075 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=61075 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=63051 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=63051 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(60269, 7, 0, 4644, 6673, 0, 38134), -- -Unknown-
(60269, 6, 0, 2704, 2099, 317, 38134), -- -Unknown-
(60268, 6, 0, 2704, 2099, 317, 38134), -- -Unknown-
(60268, 5, 0, 4646, 6671, 4841, 38134), -- -Unknown-
(60268, 4, 0, 1597, 2312, 381, 38134), -- -Unknown-
(60268, 3, 0, 2704, 2099, 317, 38134), -- -Unknown-
(60268, 2, 0, 1597, 2312, 381, 38134), -- -Unknown-
(60268, 1, 0, 4646, 6671, 4841, 38134), -- -Unknown-
(60268, 0, 0, 2704, 2099, 317, 38134), -- -Unknown-
(61075, 2, 0, 4582, 6723, 4846, 38134), -- -Unknown-
(61075, 1, 6, 4327, 7713, 4925, 38134), -- -Unknown-
(61075, 1, 5, 4281, 7737, 4928, 38134), -- -Unknown-
(61075, 1, 4, 4218, 7804, 4950, 38134), -- -Unknown-
(61075, 1, 3, 4362, 7991, 4958, 38134), -- -Unknown-
(61075, 1, 2, 4462, 7871, 4905, 38134), -- -Unknown-
(61075, 1, 1, 4542, 7714, 4874, 38134), -- -Unknown-
(61075, 1, 0, 4366, 7699, 4915, 38134), -- -Unknown-
(61075, 0, 0, 4582, 6723, 4846, 38134), -- -Unknown-
(63051, 1, 11, -1897, 1165, 0, 38134), -- -Unknown-
(63051, 1, 10, -1957, 1240, 0, 38134), -- -Unknown-
(63051, 1, 9, -1958, 1318, 0, 38134), -- -Unknown-
(63051, 1, 8, -1933, 1381, 0, 38134), -- -Unknown-
(63051, 1, 7, -1898, 1408, 0, 38134), -- -Unknown-
(63051, 1, 6, -1808, 1412, 0, 38134), -- -Unknown-
(63051, 1, 5, -1750, 1391, 0, 38134), -- -Unknown-
(63051, 1, 4, -1714, 1339, 0, 38134), -- -Unknown-
(63051, 1, 3, -1701, 1270, 0, 38134), -- -Unknown-
(63051, 1, 2, -1716, 1220, 0, 38134), -- -Unknown-
(63051, 1, 1, -1750, 1176, 0, 38134), -- -Unknown-
(63051, 1, 0, -1812, 1149, 0, 38134), -- -Unknown-
(63051, 0, 0, 4582, 6725, 4846, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `X`=4647, `Y`=6667, `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `X`=1601, `Y`=2312, `Z`=385, `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60269 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60646 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60281 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62932 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=63346 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=63346 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61331 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=61331 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60457 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60267 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50605 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=35174 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_greeting` WHERE (`ID`=174922 AND `Type`=0);
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(174922, 0, 1, 0, 'Saludos, mortal. Sirvo para concertar interacciones que podrían beneficiar a los observadores.', 38134); -- 174922


DELETE FROM `quest_details` WHERE `ID` IN (60269 /*-Unknown-*/, 60268 /*-Unknown-*/, 60646 /*-Unknown-*/, 61075 /*-Unknown-*/, 60281 /*-Unknown-*/, 63051 /*-Unknown-*/, 62286 /*-Unknown-*/, 62288 /*-Unknown-*/, 62910 /*-Unknown-*/, 62932 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(60269, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60268, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60646, 1, 1, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(61075, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60281, 6, 1, 6, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(63051, 6, 1, 6, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(62286, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(62288, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(62910, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(62932, 1, 1, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID`=61099;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(61099, 0, 0, 0, 0, '¡Lo has encontrado!', 0); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (344497,313711)) OR (`EffectIndex`=3 AND `ID`=319721);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(344497, 0, 2453, 1646, 2215.610107421875, 371.57000732421875, 38134), -- Spell: 344497 (Exit Torghast) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(319721, 3, 2222, 4601.89013671875, 6805.81005859375, 4869.5498046875, 38134), -- Spell: 319721 (Maw Jump to Cocyrus) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(313711, 0, 2222, 4640.97021484375, 6673.89013671875, 4840.1201171875, 38134); -- Spell: 313711 (Exit Torghast) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (170257 /*170257 (Broker Ve'nott) - Refuge of the Damned*/, 172801 /*172801 (Cadena) - Chain*/, 168539 /*168539 - Area Trigger*/, 164778 /*164778*/, 157406 /*157406 (Renavyth) - Escort Spawn Safety, Conversation Area, Chained, Proc*/, 164808 /*164808 (Medallón de Renavyth)*/, 165361 /*165361 - Defender of Torghast, Ambush!*/, 164542 /*164542 - Locked, Locked, Locked, Glow*/, 168114 /*168114 (Placa de presión) - Spawn*/, 150965 /*150965 - Defender of Torghast, Polearm*/, 173191 /*173191 (Acechador de almas V'lara) - Defender of Torghast, Torghast - Elite Rune Boss Aura*/, 166953 /*166953 (Elite Rune Bunny) - Torghast - Elite Rune Boss Aura*/, 166660 /*166660 (Palanca) - Quest Interact Visual*/, 166713 /*166713 (Puerta de celda)*/, 155812 /*155812 (Ritualista jurafauces) - Defender of Torghast, Soul Image*/, 167231 /*167231 (Nigromante maldraxxi) - Prisoner, Area Trigger*/, 170130 /*170130 (Trampa de púas) - Defender of Torghast, Spike Trap*/, 164549 /*164549 - Glow*/, 167230 /*167230 (Esqueleto maldraxxi) - Prisoner, Area Trigger*/, 169628 /*169628 (Restos de alma atormentada) - Shadowy Ghost Visual, Shrouded*/, 173649 /*173649*/, 169635 /*169635 (Restos de alma atormentada)*/, 174803 /*174803 (Soul Scythe) - Soul Scythe*/, 169632 /*169632*/, 155945 /*155945 (Gherus el Encadenado) - Defender of Torghast, Festive Skoldus, [DNT] Hologram*/, 168108 /*168108 (Creación torpe potenciada) - Defender of Torghast, The Jailer's Influence, Enslaved*/, 155824 /*155824 (Creación torpe) - Defender of Torghast, Enslaved*/, 175069 /*175069 (Salir de Torghast) - Exit Torghast*/, 171336 /*171336 - Chains*/, 156480 /*156480 - Vignette Area Trigger*/, 157807 /*157807 (Tejealmas jurafauces) - Defender of Torghast, Soul Image*/, 169782 /*169782 (Restos de alma esclava) - Chained*/, 157561 /*157561 - Chained*/, 153849 /*153849 - Defender of Torghast*/, 171159 /*171159 - Unraveling Soul*/, 155831 /*155831 (Atrapaalmas jurafauces) - Defender of Torghast, Soul Image*/, 173645 /*173645*/, 153874 /*153874 - Defender of Torghast, Polearm*/, 169237 /*169237*/, 164471 /*164471*/, 168109 /*168109 (Ritualista jurafauces potenciado) - Defender of Torghast, The Jailer's Influence, Soul Image*/, 164539 /*164539*/, 152594 /*152594 (Broker Ve'ken) - Shrouded, Refuge of the Damned*/, 164538 /*164538*/, 167986 /*167986 - Empowered Urn*/, 150958 /*150958 - Defender of Torghast*/, 155830 /*155830 (Discípulo jurafauces) - Defender of Torghast, Soul Image*/, 152708 /*152708 - Defender of Torghast*/, 166360 /*166360 (Punto de agarre) - Grapple Point*/, 169560 /*169560 - Souls Small Placeholder*/, 169561 /*169561 - Souls Small Placeholder*/, 171166 /*171166 (Restos de alma desbocada) - Unraveling Soul*/, 151353 /*151353 (Mawrat) - Defender of Torghast, Mod Scale 105-110%*/, 155790 /*155790 (Acólito jurafauces) - Defender of Torghast, Soul Image*/, 164698 /*164698*/, 155793 /*155793 (Restos esqueléticos) - Defender of Torghast, Enslaved*/, 165799 /*165799*/, 170724 /*170724 - Timer*/, 173236 /*173236 - Visuals*/, 164937 /*164937 (Runecarver) - Runecarver Starting State (DNT)*/, 175698 /*175698 (Doomed Soul) - Maw Soul*/, 173640 /*173640 - Permanent Feign Death (Stun, Untrackable, Immune)*/, 156681 /*156681 (Costurero Au'phes)*/, 173351 /*173351 (Facilitador de comercio)*/, 156686 /*156686 (Seleccionador Au'mar)*/, 175211 /*175211 (Asistente real)*/, 156732 /*156732 (Distribuidor Au'sha)*/, 156689 /*156689 (Distribuidor Au'naci)*/, 156687 /*156687 (Elixirista Au'pyr)*/, 170651 /*170651 (Baine Pezuña de Sangre)*/, 176332 /*176332 (Caballero de la Espada de Ébano)*/, 176308 /*176308 - Grapple Point*/, 170825 /*170825 - -Unknown-*/, 70528 /*70528 - Cloak of the Covenant*/, 162804 /*162804*/, 172925 /*172925 - Broker Portal*/, 170824 /*170824 - -Unknown-*/, 170819 /*170819 - -Unknown-*/, 172631 /*172631*/, 170827 /*170827 - -Unknown-*/, 170826 /*170826 - -Unknown-*/, 173668 /*173668 - Exit Torghast*/, 152898 /*152898 - Deadsoul Shadows, Ghostly Aura, Yellow Aura, Invisibility and Stealth Detection*/, 175009 /*175009 - Portal*/, 175121 /*175121*/, 175127 /*175127*/, 175026 /*175026 - Portal*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(170257, 0, 0, 0, 1, 0, 0, 0, 0, '339676'), -- 170257 (Broker Ve'nott) - Refuge of the Damned
(172801, 0, 0, 0, 1, 0, 0, 0, 0, '337588'), -- 172801 (Cadena) - Chain
(168539, 0, 0, 0, 1, 0, 0, 0, 0, '327954'), -- 168539 - Area Trigger
(164778, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164778
(157406, 0, 0, 0, 1, 0, 0, 0, 0, '320797 321118 321309 329535'), -- 157406 (Renavyth) - Escort Spawn Safety, Conversation Area, Chained, Proc
(164808, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164808 (Medallón de Renavyth)
(165361, 0, 0, 0, 1, 0, 0, 0, 0, '311180 322055'), -- 165361 - Defender of Torghast, Ambush!
(164542, 0, 0, 0, 1, 0, 0, 0, 0, '320173 320172 320051 320184'), -- 164542 - Locked, Locked, Locked, Glow
(168114, 0, 0, 0, 1, 0, 0, 0, 0, '327042'), -- 168114 (Placa de presión) - Spawn
(150965, 0, 0, 0, 1, 0, 0, 0, 0, '311180 334922'), -- 150965 - Defender of Torghast, Polearm
(173191, 0, 0, 0, 1, 0, 0, 0, 0, '311180 325344'), -- 173191 (Acechador de almas V'lara) - Defender of Torghast, Torghast - Elite Rune Boss Aura
(166953, 0, 0, 0, 1, 0, 0, 0, 0, '325344'), -- 166953 (Elite Rune Bunny) - Torghast - Elite Rune Boss Aura
(166660, 0, 0, 0, 1, 0, 0, 0, 0, '320764'), -- 166660 (Palanca) - Quest Interact Visual
(166713, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166713 (Puerta de celda)
(155812, 0, 0, 0, 1, 0, 0, 0, 0, '311180 303616'), -- 155812 (Ritualista jurafauces) - Defender of Torghast, Soul Image
(167231, 0, 0, 0, 1, 0, 0, 0, 0, '325639 326959'), -- 167231 (Nigromante maldraxxi) - Prisoner, Area Trigger
(170130, 0, 0, 0, 1, 0, 0, 0, 0, '311180 331341'), -- 170130 (Trampa de púas) - Defender of Torghast, Spike Trap
(164549, 0, 0, 0, 1, 0, 0, 0, 0, '320177'), -- 164549 - Glow
(167230, 0, 0, 0, 1, 0, 0, 0, 0, '325699 326959'), -- 167230 (Esqueleto maldraxxi) - Prisoner, Area Trigger
(169628, 0, 0, 33554432, 1, 0, 0, 0, 0, '295709 305628'), -- 169628 (Restos de alma atormentada) - Shadowy Ghost Visual, Shrouded
(173649, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 173649
(169635, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 169635 (Restos de alma atormentada)
(174803, 0, 0, 0, 1, 0, 0, 0, 0, '343593'), -- 174803 (Soul Scythe) - Soul Scythe
(169632, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169632
(155945, 0, 0, 0, 1, 0, 0, 0, 0, '311180 346153 348441'), -- 155945 (Gherus el Encadenado) - Defender of Torghast, Festive Skoldus, [DNT] Hologram
(168108, 0, 0, 0, 1, 0, 0, 0, 0, '311180 328048 303622'), -- 168108 (Creación torpe potenciada) - Defender of Torghast, The Jailer's Influence, Enslaved
(155824, 0, 0, 0, 1, 0, 0, 0, 0, '311180 303622'), -- 155824 (Creación torpe) - Defender of Torghast, Enslaved
(175069, 0, 0, 0, 1, 0, 0, 0, 0, '340121'), -- 175069 (Salir de Torghast) - Exit Torghast
(171336, 0, 0, 0, 1, 0, 0, 0, 0, '334216'), -- 171336 - Chains
(156480, 0, 0, 50331648, 1, 0, 0, 0, 0, '323440'), -- 156480 - Vignette Area Trigger
(157807, 0, 0, 0, 1, 0, 0, 0, 0, '311180 303786'), -- 157807 (Tejealmas jurafauces) - Defender of Torghast, Soul Image
(169782, 0, 0, 0, 1, 0, 0, 0, 0, '324709'), -- 169782 (Restos de alma esclava) - Chained
(157561, 0, 0, 0, 1, 0, 0, 0, 0, '324709'), -- 157561 - Chained
(153849, 0, 0, 0, 1, 0, 0, 0, 0, '311180'), -- 153849 - Defender of Torghast
(171159, 0, 0, 33554432, 0, 0, 0, 0, 0, '333903'), -- 171159 - Unraveling Soul
(155831, 0, 0, 0, 1, 0, 0, 0, 0, '311180 303786'), -- 155831 (Atrapaalmas jurafauces) - Defender of Torghast, Soul Image
(173645, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 173645
(153874, 0, 0, 0, 1, 0, 0, 0, 0, '311180 334922'), -- 153874 - Defender of Torghast, Polearm
(169237, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169237
(164471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164471
(168109, 0, 0, 0, 1, 0, 0, 0, 0, '311180 328048 303616'), -- 168109 (Ritualista jurafauces potenciado) - Defender of Torghast, The Jailer's Influence, Soul Image
(164539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164539
(152594, 0, 0, 0, 1, 0, 0, 0, 0, '305628 339676'), -- 152594 (Broker Ve'ken) - Shrouded, Refuge of the Damned
(164538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164538
(167986, 0, 0, 0, 1, 0, 0, 0, 0, '327803'), -- 167986 - Empowered Urn
(150958, 0, 0, 0, 1, 0, 0, 0, 0, '311180'), -- 150958 - Defender of Torghast
(155830, 0, 0, 0, 1, 0, 0, 0, 0, '311180 303786'), -- 155830 (Discípulo jurafauces) - Defender of Torghast, Soul Image
(152708, 0, 0, 0, 1, 0, 0, 0, 0, '311180'), -- 152708 - Defender of Torghast
(166360, 0, 0, 0, 1, 0, 0, 0, 0, '324236'), -- 166360 (Punto de agarre) - Grapple Point
(169560, 0, 0, 0, 1, 0, 0, 0, 0, '330015'), -- 169560 - Souls Small Placeholder
(169561, 0, 0, 0, 1, 0, 0, 0, 0, '330017'), -- 169561 - Souls Small Placeholder
(171166, 0, 0, 0, 1, 0, 13299, 0, 0, '333928'), -- 171166 (Restos de alma desbocada) - Unraveling Soul
(151353, 0, 0, 0, 1, 0, 0, 0, 0, '311180 123169'), -- 151353 (Mawrat) - Defender of Torghast, Mod Scale 105-110%
(155790, 0, 0, 0, 1, 0, 0, 0, 0, '311180 303616'), -- 155790 (Acólito jurafauces) - Defender of Torghast, Soul Image
(164698, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164698
(155793, 0, 0, 0, 1, 0, 0, 0, 0, '311180 303622'), -- 155793 (Restos esqueléticos) - Defender of Torghast, Enslaved
(165799, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165799
(170724, 0, 0, 0, 1, 0, 0, 0, 0, '332919'), -- 170724 - Timer
(173236, 0, 0, 0, 1, 0, 0, 0, 0, '338943'), -- 173236 - Visuals
(164937, 0, 0, 0, 1, 0, 0, 0, 0, '330750'), -- 164937 (Runecarver) - Runecarver Starting State (DNT)
(175698, 0, 0, 1, 1, 0, 0, 0, 0, '323906'), -- 175698 (Doomed Soul) - Maw Soul
(173640, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 173640 - Permanent Feign Death (Stun, Untrackable, Immune)
(156681, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156681 (Costurero Au'phes)
(173351, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173351 (Facilitador de comercio)
(156686, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156686 (Seleccionador Au'mar)
(175211, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 175211 (Asistente real)
(156732, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156732 (Distribuidor Au'sha)
(156689, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156689 (Distribuidor Au'naci)
(156687, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156687 (Elixirista Au'pyr)
(170651, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 170651 (Baine Pezuña de Sangre)
(176332, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 176332 (Caballero de la Espada de Ébano)
(176308, 0, 0, 0, 1, 0, 0, 0, 0, '347379'), -- 176308 - Grapple Point
(170825, 0, 0, 0, 1, 0, 0, 0, 0, '333177'), -- 170825 - -Unknown-
(70528, 0, 0, 0, 1, 0, 0, 0, 0, '308237'), -- 70528 - Cloak of the Covenant
(162804, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162804
(172925, 0, 0, 0, 1, 0, 0, 0, 0, '337905'), -- 172925 - Broker Portal
(170824, 0, 0, 0, 1, 0, 0, 0, 0, '333175'), -- 170824 - -Unknown-
(170819, 0, 0, 0, 1, 0, 0, 0, 0, '333171'), -- 170819 - -Unknown-
(172631, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172631
(170827, 0, 0, 0, 1, 0, 0, 0, 0, '333181'), -- 170827 - -Unknown-
(170826, 0, 0, 0, 1, 0, 0, 0, 0, '333179'), -- 170826 - -Unknown-
(173668, 0, 0, 0, 1, 0, 0, 0, 0, '340121'), -- 173668 - Exit Torghast
(152898, 0, 0, 0, 1, 0, 0, 0, 0, '306919 227526 344829 18950'), -- 152898 - Deadsoul Shadows, Ghostly Aura, Yellow Aura, Invisibility and Stealth Detection
(175009, 0, 0, 50331648, 1, 0, 0, 0, 0, '341125'), -- 175009 - Portal
(175121, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 175121
(175127, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175127
(175026, 0, 0, 50331648, 1, 0, 0, 0, 0, '341125'); -- 175026 - Portal

UPDATE `creature_template_addon` SET `auras`='122729 123240' WHERE `entry`=62822; -- 62822
UPDATE `creature_template_addon` SET `auras`='122729 123236' WHERE `entry`=62821; -- 62821
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=54638; -- 54638
UPDATE `creature_template_addon` SET `aiAnimKit`=13353 WHERE `entry`=164803; -- 164803
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=121541; -- 121541 (Ban-Lu)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=164123; -- 164123

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=167 AND `Entry` IN (170257,172801,168539,164778,157406,164808,165361,164542,168114,150965,173191,166953,166660,166713,155812,167231,170130,164549,167230,169628,173649,169635,174803,169632,155945,168108,155824,175069,171336,156480,157807,169782,157561,153849,171159,155831,173645,153874,169237,164471,168109,164539,152594,164538,167986,150958,155830,152708,166360,169560,169561,171166,151353,155790,164698,155793));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(170257, 167, 60, 60, 0, 0, 709, 38134),
(172801, 167, 60, 60, 0, 0, 709, 38134),
(168539, 167, 60, 60, 0, 0, 709, 38134),
(164778, 167, 60, 60, 0, 0, 709, 38134),
(157406, 167, 60, 60, 0, 0, 709, 38134),
(164808, 167, 60, 60, 0, 0, 709, 38134),
(165361, 167, 60, 60, 0, 0, 709, 38134),
(164542, 167, 60, 60, 0, 0, 709, 38134),
(168114, 167, 60, 60, 0, 0, 709, 38134),
(150965, 167, 60, 60, 0, 0, 709, 38134),
(173191, 167, 60, 60, 1, 1, 709, 38134),
(166953, 167, 60, 60, 0, 0, 709, 38134),
(166660, 167, 60, 60, 0, 0, 709, 38134),
(166713, 167, 35, 50, 0, 0, 188, 38134),
(155812, 167, 60, 60, 0, 0, 709, 38134),
(167231, 167, 60, 60, 0, 0, 709, 38134),
(170130, 167, 60, 60, 0, 0, 709, 38134),
(164549, 167, 60, 60, 0, 0, 709, 38134),
(167230, 167, 60, 60, 0, 0, 709, 38134),
(169628, 167, 60, 60, 0, 0, 709, 38134),
(173649, 167, 60, 60, 0, 0, 709, 38134),
(169635, 167, 60, 60, 0, 0, 709, 38134),
(174803, 167, 60, 60, 0, 0, 709, 38134),
(169632, 167, 60, 60, 0, 0, 709, 38134),
(155945, 167, 60, 60, 2, 2, 709, 38134),
(168108, 167, 60, 60, 1, 1, 709, 38134),
(155824, 167, 60, 60, 0, 0, 709, 38134),
(175069, 167, 60, 60, 0, 0, 709, 38134),
(171336, 167, 60, 60, 0, 0, 709, 38134),
(156480, 167, 60, 60, 0, 0, 709, 38134),
(157807, 167, 60, 60, 0, 0, 709, 38134),
(169782, 167, 60, 60, 0, 0, 709, 38134),
(157561, 167, 60, 60, 0, 0, 709, 38134),
(153849, 167, 60, 60, 0, 0, 709, 38134),
(171159, 167, 60, 60, 0, 0, 709, 38134),
(155831, 167, 60, 60, 0, 0, 709, 38134),
(173645, 167, 60, 60, 0, 0, 709, 38134),
(153874, 167, 60, 60, 0, 0, 709, 38134),
(169237, 167, 60, 60, 0, 0, 709, 38134),
(164471, 167, 60, 60, 0, 0, 709, 38134),
(168109, 167, 60, 60, 1, 1, 709, 38134),
(164539, 167, 60, 60, 0, 0, 709, 38134),
(152594, 167, 60, 60, 0, 0, 709, 38134),
(164538, 167, 60, 60, 0, 0, 709, 38134),
(167986, 167, 60, 60, 0, 0, 709, 38134),
(150958, 167, 60, 60, 0, 0, 709, 38134),
(155830, 167, 60, 60, 0, 0, 709, 38134),
(152708, 167, 60, 60, 0, 0, 709, 38134),
(166360, 167, 35, 50, 0, 0, 188, 38134),
(169560, 167, 60, 60, 0, 0, 709, 38134),
(169561, 167, 60, 60, 0, 0, 709, 38134),
(171166, 167, 60, 60, 0, 0, 709, 38134),
(151353, 167, 60, 60, 0, 0, 709, 38134),
(155790, 167, 60, 60, 0, 0, 709, 38134),
(164698, 167, 60, 60, 0, 0, 709, 38134),
(155793, 167, 60, 60, 0, 0, 709, 38134);

UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=165799 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=170724 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=173236 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2125, `VerifiedBuild`=38134 WHERE (`Entry`=164937 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=175698 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=173640 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=156681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=173351 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=156686 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=807, `VerifiedBuild`=38134 WHERE (`Entry`=175211 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=156732 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=156689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=156687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=170651 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=176332 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=176308 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=170825 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=32, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=167, `VerifiedBuild`=38134 WHERE (`Entry`=70528 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2098, `VerifiedBuild`=38134 WHERE (`Entry`=162804 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=172925 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=170824 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=170819 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=172631 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=170827 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=170826 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=173668 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=152898 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=175009 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=175121 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=175127 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=175026 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91526;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92984;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=95565;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=20577;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95487;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92416;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92415;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96339;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94055;
UPDATE `creature_model_info` SET `BoundingRadius`=0.683212339878082275, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=97211;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98016;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96252;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100477;
UPDATE `creature_model_info` SET `BoundingRadius`=1.513591408729553222, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=98909;
UPDATE `creature_model_info` SET `BoundingRadius`=1.009060859680175781, `CombatReach`=0.800000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=98486;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=69032;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95935;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96839;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690578341484069824, `CombatReach`=0.899999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=92779;
UPDATE `creature_model_info` SET `BoundingRadius`=2.833333492279052734, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=93583;
UPDATE `creature_model_info` SET `BoundingRadius`=0.100000001490116119, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=96842;
UPDATE `creature_model_info` SET `BoundingRadius`=0.100000001490116119, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=96841;
UPDATE `creature_model_info` SET `BoundingRadius`=0.983263254165649414, `CombatReach`=1.45000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=92410;
UPDATE `creature_model_info` SET `BoundingRadius`=0.100000001490116119, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=96843;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58952;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92780;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96840;
UPDATE `creature_model_info` SET `BoundingRadius`=0.961840033531188964, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=92628;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96846;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96286;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64947;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96847;
UPDATE `creature_model_info` SET `BoundingRadius`=0.592886686325073242, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=94426;
UPDATE `creature_model_info` SET `BoundingRadius`=1.21804666519165039, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=95749;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690578341484069824, `CombatReach`=0.899999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=92781;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96848;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=58949;
UPDATE `creature_model_info` SET `BoundingRadius`=2.418225288391113281, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=94375;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95102;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95624;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100304;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92627;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96326;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96423;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94626;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=93579;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96331;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96325;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96332;
UPDATE `creature_model_info` SET `BoundingRadius`=0.445083141326904296, `CombatReach`=1.80000007152557373, `VerifiedBuild`=38134 WHERE `DisplayID`=99051;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96330;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96086;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81646;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96422;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96084;
UPDATE `creature_model_info` SET `BoundingRadius`=2.083333253860473632, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=94613;
UPDATE `creature_model_info` SET `BoundingRadius`=0.774677395820617675, `CombatReach`=1.70000004768371582 WHERE `DisplayID`=92191;
UPDATE `creature_model_info` SET `BoundingRadius`=0.843031287193298339, `CombatReach`=1.85000002384185791 WHERE `DisplayID`=92192;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94625;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95325;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97879;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99050;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96748;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94469;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99048;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100403;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95004;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98159;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97386;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98562;
UPDATE `creature_model_info` SET `BoundingRadius`=2.018712759017944335, `CombatReach`=3.125, `VerifiedBuild`=38134 WHERE `DisplayID`=95039;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95276;

DELETE FROM `npc_vendor` WHERE (`entry`=170257 AND `item`=1173 AND `ExtendedCost`=6908 AND `type`=4) OR (`entry`=170257 AND `item`=1192 AND `ExtendedCost`=6908 AND `type`=4) OR (`entry`=170257 AND `item`=1434 AND `ExtendedCost`=6554 AND `type`=4) OR (`entry`=170257 AND `item`=10 AND `ExtendedCost`=6547 AND `type`=4) OR (`entry`=170257 AND `item`=176409 AND `ExtendedCost`=6553 AND `type`=1) OR (`entry`=170257 AND `item`=176408 AND `ExtendedCost`=6553 AND `type`=1) OR (`entry`=170257 AND `item`=168207 AND `ExtendedCost`=6551 AND `type`=1) OR (`entry`=170257 AND `item`=174283 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=170257 AND `item`=1171 AND `ExtendedCost`=6908 AND `type`=4) OR (`entry`=152594 AND `item`=1172 AND `ExtendedCost`=6908 AND `type`=4) OR (`entry`=152594 AND `item`=1170 AND `ExtendedCost`=6908 AND `type`=4) OR (`entry`=152594 AND `item`=1177 AND `ExtendedCost`=6908 AND `type`=4) OR (`entry`=152594 AND `item`=1258 AND `ExtendedCost`=6908 AND `type`=4) OR (`entry`=152594 AND `item`=16 AND `ExtendedCost`=6554 AND `type`=4) OR (`entry`=152594 AND `item`=7 AND `ExtendedCost`=6547 AND `type`=4) OR (`entry`=152594 AND `item`=176409 AND `ExtendedCost`=6553 AND `type`=1) OR (`entry`=152594 AND `item`=176443 AND `ExtendedCost`=6554 AND `type`=1) OR (`entry`=152594 AND `item`=170540 AND `ExtendedCost`=6642 AND `type`=1) OR (`entry`=152594 AND `item`=168207 AND `ExtendedCost`=6551 AND `type`=1) OR (`entry`=152594 AND `item`=174283 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=168011 AND `item`=179609 AND `ExtendedCost`=6867 AND `type`=1) OR (`entry`=168011 AND `item`=179569 AND `ExtendedCost`=6867 AND `type`=1) OR (`entry`=168011 AND `item`=180004 AND `ExtendedCost`=6720 AND `type`=1) OR (`entry`=168011 AND `item`=179526 AND `ExtendedCost`=6720 AND `type`=1) OR (`entry`=168011 AND `item`=179543 AND `ExtendedCost`=6720 AND `type`=1) OR (`entry`=168011 AND `item`=180081 AND `ExtendedCost`=6720 AND `type`=1) OR (`entry`=168011 AND `item`=180261 AND `ExtendedCost`=6874 AND `type`=1) OR (`entry`=168011 AND `item`=180019 AND `ExtendedCost`=6994 AND `type`=1) OR (`entry`=168011 AND `item`=182349 AND `ExtendedCost`=6874 AND `type`=1) OR (`entry`=168011 AND `item`=179559 AND `ExtendedCost`=6994 AND `type`=1) OR (`entry`=168011 AND `item`=179578 AND `ExtendedCost`=6874 AND `type`=1) OR (`entry`=168011 AND `item`=179495 AND `ExtendedCost`=6874 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(170257, 136, 1173, 1, 6908, 4, 0, 0, 38134), -- 1173
(170257, 135, 1192, 1, 6908, 4, 0, 0, 38134), -- 1192
(170257, 17, 1434, 1, 6554, 4, 0, 0, 38134), -- 1434
(170257, 12, 10, 1, 6547, 4, 0, 0, 38134), -- 10
(170257, 9, 176409, 0, 6553, 1, 0, 0, 38134), -- Rejuvenating Siphoned Essence
(170257, 7, 176408, 3, 6553, 1, 0, 0, 38134), -- Blinding Smoke Capsules
(170257, 4, 168207, 2, 6551, 1, 0, 0, 38134), -- -Unknown-
(170257, 1, 174283, 0, 0, 1, 0, 0, 38134), -- Stygian Stew
(170257, 131, 1171, 1, 6908, 4, 0, 0, 38134), -- 1171
(152594, 138, 1172, 1, 6908, 4, 0, 0, 38134), -- 1172
(152594, 137, 1170, 1, 6908, 4, 0, 0, 38134), -- 1170
(152594, 133, 1177, 1, 6908, 4, 0, 0, 38134), -- 1177
(152594, 132, 1258, 1, 6908, 4, 0, 0, 38134), -- 1258
(152594, 18, 16, 1, 6554, 4, 0, 0, 38134), -- 16
(152594, 14, 7, 1, 6547, 4, 0, 0, 38134), -- 7
(152594, 9, 176409, 0, 6553, 1, 0, 0, 38134), -- Rejuvenating Siphoned Essence
(152594, 8, 176443, 1, 6554, 1, 0, 0, 38134), -- Fleeting Frenzy Potion
(152594, 5, 170540, 1, 6642, 1, 0, 0, 38134), -- -Unknown-
(152594, 4, 168207, 1, 6551, 1, 0, 0, 38134), -- -Unknown-
(152594, 1, 174283, 0, 0, 1, 0, 0, 38134), -- Stygian Stew
(168011, 12, 179609, 0, 6867, 1, 0, 0, 38134), -- Sinful Gladiator's Bulwark
(168011, 11, 179569, 0, 6867, 1, 0, 0, 38134), -- Sinful Gladiator's Lyre
(168011, 10, 180004, 0, 6720, 1, 0, 0, 38134), -- Sinful Gladiator's Staff
(168011, 9, 179526, 0, 6720, 1, 0, 0, 38134), -- Sinful Gladiator's Spear
(168011, 8, 179543, 0, 6720, 1, 0, 0, 38134), -- Sinful Gladiator's Bludgeon
(168011, 7, 180081, 0, 6720, 1, 0, 0, 38134), -- Sinful Gladiator's Warbow
(168011, 6, 180261, 0, 6874, 1, 0, 0, 38134), -- Sinful Gladiator's Edge
(168011, 5, 180019, 0, 6994, 1, 0, 0, 38134), -- Sinful Gladiator's Wand
(168011, 4, 182349, 0, 6874, 1, 0, 0, 38134), -- Sinful Gladiator's Shillelagh
(168011, 3, 179559, 0, 6994, 1, 0, 0, 38134), -- Sinful Gladiator's Scepter
(168011, 2, 179578, 0, 6874, 1, 0, 0, 38134), -- Sinful Gladiator's Jaws
(168011, 1, 179495, 0, 6874, 1, 0, 0, 38134); -- Sinful Gladiator's Fang

UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182624 AND `ExtendedCost`=6910 AND `type`=1); -- Show of Force
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181712 AND `ExtendedCost`=6910 AND `type`=1); -- Depths of Insanity
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=180935 AND `ExtendedCost`=6910 AND `type`=1); -- Crash the Ramparts
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=180842 AND `ExtendedCost`=6910 AND `type`=1); -- Stalwart Guardian
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182769 AND `ExtendedCost`=6910 AND `type`=1); -- Combusting Engine
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182748 AND `ExtendedCost`=6910 AND `type`=1); -- Borne of Blood
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182449 AND `ExtendedCost`=6910 AND `type`=1); -- Resolute Barrier
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182743 AND `ExtendedCost`=6910 AND `type`=1); -- Focused Malignancy
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182142 AND `ExtendedCost`=6910 AND `type`=1); -- Embrace of Earth
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182137 AND `ExtendedCost`=6910 AND `type`=1); -- Magma Fist
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182128 AND `ExtendedCost`=6910 AND `type`=1); -- Call of Flame
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182109 AND `ExtendedCost`=6910 AND `type`=1); -- Totemic Surge
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183514 AND `ExtendedCost`=6910 AND `type`=1); -- Perforated Veins
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183507 AND `ExtendedCost`=6910 AND `type`=1); -- Triple Threat
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183506 AND `ExtendedCost`=6910 AND `type`=1); -- Lethal Poisons
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183501 AND `ExtendedCost`=6910 AND `type`=1); -- Rushed Setup
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182140 AND `ExtendedCost`=6910 AND `type`=1); -- Dissonant Echoes
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181944 AND `ExtendedCost`=6910 AND `type`=1); -- Resonant Words
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181844 AND `ExtendedCost`=6910 AND `type`=1); -- Pain Transformation
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181837 AND `ExtendedCost`=6910 AND `type`=1); -- Clear Mind
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182465 AND `ExtendedCost`=6910 AND `type`=1); -- Truth's Wake
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182681 AND `ExtendedCost`=6910 AND `type`=1); -- Vengeful Shock
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182667 AND `ExtendedCost`=6910 AND `type`=1); -- Focused Light
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182461 AND `ExtendedCost`=6910 AND `type`=1); -- Echoing Blessings
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181462 AND `ExtendedCost`=6910 AND `type`=1); -- Coordinated Offensive
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181737 AND `ExtendedCost`=6910 AND `type`=1); -- Nourishing Chi
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181700 AND `ExtendedCost`=6910 AND `type`=1); -- Scalding Brew
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181373 AND `ExtendedCost`=6910 AND `type`=1); -- Harm Denial
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181461 AND `ExtendedCost`=6910 AND `type`=1); -- Ice Bite
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183197 AND `ExtendedCost`=6910 AND `type`=1); -- Controlled Destruction
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181511 AND `ExtendedCost`=6910 AND `type`=1); -- Nether Precision
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181498 AND `ExtendedCost`=6910 AND `type`=1); -- Grounding Surge
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183184 AND `ExtendedCost`=6910 AND `type`=1); -- Stinging Strike
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182686 AND `ExtendedCost`=6910 AND `type`=1); -- Powerful Precision
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182621 AND `ExtendedCost`=6910 AND `type`=1); -- One With the Beast
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182480 AND `ExtendedCost`=6910 AND `type`=1); -- Reversal of Fortune
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183491 AND `ExtendedCost`=6910 AND `type`=1); -- Ready for Anything
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183485 AND `ExtendedCost`=6910 AND `type`=1); -- Savage Combatant
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183480 AND `ExtendedCost`=6910 AND `type`=1); -- Taste for Blood
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183478 AND `ExtendedCost`=6910 AND `type`=1); -- Fury of the Skies
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=183470 AND `ExtendedCost`=6910 AND `type`=1); -- Born of the Wilds
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182344 AND `ExtendedCost`=6910 AND `type`=1); -- Lost in Darkness
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182598 AND `ExtendedCost`=6910 AND `type`=1); -- Demon Muzzle
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182368 AND `ExtendedCost`=6910 AND `type`=1); -- Relentless Onslaught
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182325 AND `ExtendedCost`=6910 AND `type`=1); -- Ravenous Consumption
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181980 AND `ExtendedCost`=6910 AND `type`=1); -- Embrace Death
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181848 AND `ExtendedCost`=6910 AND `type`=1); -- Accelerated Cold
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=182187 AND `ExtendedCost`=6910 AND `type`=1); -- Meat Shield
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181836 AND `ExtendedCost`=6910 AND `type`=1); -- Spirit Drain
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178448 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Amulet
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178387 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Pendant
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175922 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Necklace
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178442 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Signet
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178381 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Band
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175916 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Ring
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=184311 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Greatcloak
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178414 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Shawl
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178353 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Drape
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175888 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Cloak
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178383 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Plate Vambraces
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175918 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Plate Wristguards
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178384 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Chain Bracers
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175919 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Chain Wristguards
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178385 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Leather Wristguards
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175920 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Leather Wristwraps
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178382 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Silk Armbands
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175917 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Silk Wristwraps
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178447 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Emblem
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178386 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Insignia of Alacrity
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175921 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Badge of Ferocity
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181816 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Sigil of Adaptation
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181335 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Relentless Brooch
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=181333 AND `ExtendedCost`=6717 AND `type`=1); -- Sinful Gladiator's Medallion
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178377 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Greatbelt
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175912 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Girdle
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178374 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Pauldrons
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175909 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Shoulders
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178363 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Handguards
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175898 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Gauntlets
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178358 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Stompers
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175893 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Plate Warboots
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178379 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Girdle
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175914 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178376 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Shoulderguard
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175911 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Monnion
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178365 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Handguards
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175900 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Gauntlets
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178360 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175895 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Chain Sabatons
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178380 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Strap
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175915 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178373 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Shoulderpads
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175908 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Spaulders
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178362 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Grips
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175897 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178361 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Treads
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175896 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Leather Boots
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178378 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Belt
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175913 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Cord
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178375 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Amice
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175910 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Mantle
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178364 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Handwraps
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175899 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Gloves
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178359 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Treads
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175894 AND `ExtendedCost`=6718 AND `type`=1); -- Sinful Gladiator's Silk Slippers
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178369 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Plate Wargreaves
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175904 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Plate Legguards
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178352 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Plate Helmet
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175887 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Plate Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178355 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Plate Chestplate
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175890 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Plate Chestguard
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178371 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Chain Breeches
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175906 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Chain Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178367 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Chain Faceguard
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175902 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Chain Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178356 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Chain Tunic
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175891 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Chain Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178372 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Leather Legwraps
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175907 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Leather Breeches
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178368 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Leather Mask
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175903 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Leather Helm
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178357 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Leather Jerkin
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175892 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Leather Vest
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178370 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Silk Trousers
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175905 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Silk Leggings
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178366 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Silk Guise
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175901 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Silk Hood
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=178354 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Silk Vestments
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=168011 AND `item`=175889 AND `ExtendedCost`=6719 AND `type`=1); -- Sinful Gladiator's Silk Robe

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (157406,150965,173191,155812,157807,155831,153874,168109,150958,155830,155790,176332));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(157406, 1, 144187, 0, 0, 0, 0, 0, 0, 0, 0), -- Renavyth
(150965, 1, 179727, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(173191, 1, 31805, 0, 0, 31805, 0, 0, 0, 0, 0), -- Acechador de almas V'lara
(155812, 1, 179724, 0, 0, 0, 0, 0, 0, 0, 0), -- Ritualista jurafauces
(157807, 1, 179725, 0, 0, 0, 0, 0, 0, 0, 0), -- Tejealmas jurafauces
(155831, 1, 114918, 0, 0, 19309, 0, 0, 0, 0, 0), -- Atrapaalmas jurafauces
(153874, 1, 179728, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(168109, 1, 179723, 0, 0, 0, 0, 0, 0, 0, 0), -- Ritualista jurafauces potenciado
(150958, 1, 179721, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(155830, 1, 108786, 0, 0, 3451, 0, 0, 0, 0, 0), -- Discípulo jurafauces
(155790, 1, 179725, 0, 0, 0, 0, 0, 0, 0, 0), -- Acólito jurafauces
(176332, 1, 117049, 0, 0, 0, 0, 0, 0, 0, 0); -- Caballero de la Espada de Ébano


DELETE FROM `gossip_menu` WHERE (`MenuId`=26658 AND `TextId`=41849) OR (`MenuId`=26656 AND `TextId`=41847) OR (`MenuId`=26677 AND `TextId`=42400) OR (`MenuId`=24577 AND `TextId`=38631) OR (`MenuId`=25682 AND `TextId`=40535) OR (`MenuId`=25673 AND `TextId`=40520) OR (`MenuId`=26736 AND `TextId`=42519) OR (`MenuId`=26735 AND `TextId`=42518) OR (`MenuId`=26734 AND `TextId`=42517) OR (`MenuId`=26733 AND `TextId`=42516) OR (`MenuId`=26794 AND `TextId`=42627);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(26658, 41849, 38134), -- 175026
(26656, 41847, 38134), -- 175009
(26677, 42400, 38134), -- 175127
(24577, 38631, 38134), -- 157406 (Renavyth)
(25682, 40535, 38134), -- 164937 (Runecarver)
(25673, 40520, 38134), -- 162804
(26736, 42519, 38134), -- 168432 (Ve'rayn)
(26735, 42518, 38134), -- 168432 (Ve'rayn)
(26734, 42517, 38134), -- 168432 (Ve'rayn)
(26733, 42516, 38134), -- 168432 (Ve'rayn)
(26794, 42627, 38134); -- 162804

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25685 AND `TextId`=40543); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25685 AND `TextId`=40543); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25685 AND `TextId`=40543); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25685 AND `TextId`=40543); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25278 AND `TextId`=40584); -- 0

DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=7 AND `MenuId` IN (26658,26656)) OR (`OptionIndex`=6 AND `MenuId` IN (26658,26656)) OR (`OptionIndex`=5 AND `MenuId` IN (26658,26656,25278)) OR (`OptionIndex`=4 AND `MenuId` IN (26658,26656,25278)) OR (`OptionIndex`=3 AND `MenuId` IN (26658,26656,25278,26734)) OR (`OptionIndex`=2 AND `MenuId` IN (26658,26656,26734)) OR (`OptionIndex`=1 AND `MenuId` IN (26658,26656,26734)) OR (`OptionIndex`=0 AND `MenuId` IN (26658,26656,24577,25682,26736,26735,26734,26733));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(26658, 7, 0, '8', 68912, 38134),
(26658, 6, 0, '7', 68913, 38134),
(26658, 5, 0, '6', 68914, 38134),
(26658, 4, 0, '5', 68915, 38134),
(26658, 3, 0, '4', 68916, 38134), -- OptionBroadcastTextID: 68916 - 121744
(26658, 2, 0, '3', 68917, 38134), -- OptionBroadcastTextID: 68917 - 92736 - 121745
(26658, 1, 0, '2', 68918, 38134), -- OptionBroadcastTextID: 68918 - 92737 - 121746
(26658, 0, 0, '1', 68919, 38134), -- OptionBroadcastTextID: 68919 - 92738 - 121747
(26656, 7, 0, '8', 68912, 38134),
(26656, 6, 0, '7', 68913, 38134),
(26656, 5, 0, '6', 68914, 38134),
(26656, 4, 0, '5', 68915, 38134),
(26656, 3, 0, '4', 68916, 38134), -- OptionBroadcastTextID: 68916 - 121744
(26656, 2, 0, '3', 68917, 38134), -- OptionBroadcastTextID: 68917 - 92736 - 121745
(26656, 1, 0, '2', 68918, 38134), -- OptionBroadcastTextID: 68918 - 92737 - 121746
(26656, 0, 0, '1', 68919, 38134), -- OptionBroadcastTextID: 68919 - 92738 - 121747
(24577, 0, 0, 'Te ayudaré.', 0, 38134),
(25682, 0, 0, '¿Quién eres? ¿Por qué estás aquí?', 0, 38134),
(25278, 5, 1, '¿Qué tienes para comerciar?', 0, 38134),
(25278, 3, 0, '|cFF0000FF(Misión)|r Uno de los guardias más poderosos del Carcelero llevaba esto. ¿Sabes lo que hace?', 0, 38134),
(26736, 0, 0, 'No conozco a nadie que se llame Ve\'nari.', 0, 38134),
(26735, 0, 0, '¿Ve\'nari? ¿Quién es Ve\'nari?', 0, 38134),
(26734, 3, 0, 'Disculpa, ¿para qué dijiste que era esto?', 0, 38134),
(26734, 2, 0, 'Desayuno monstruos como el Carcelero. ¿Has oído hablar de la Legión Ardiente?', 0, 38134),
(26734, 1, 0, 'Es un desafío, pero puedo superarlo.', 0, 38134),
(26734, 0, 0, 'Por supuesto. Necesito todas mis fuerzas para mantenerme con vida.', 0, 38134),
(26733, 0, 0, 'Sí, las fuerzas del Carcelero se han vuelto más poderosas desde la traición de Denathrius.', 0, 38134),
(25278, 4, 0, '|cFF0000FF(Misión)|r Uno de los guardias más poderosos del Carcelero llevaba esto. ¿Sabes lo que hace?', 0, 38134);


REPLACE INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(25278, 3, 25673, 0),
(26735, 0, 26736, 0),
(26734, 0, 26735, 0),
(26733, 0, 26734, 0),
(25278, 4, 26794, 0);




UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=170257; -- Broker Ve'nott
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67125248, `unit_flags3`=1 WHERE `entry`=172801; -- Cadena
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=168539; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=164778; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=24577, `minlevel`=60, `maxlevel`=60, `faction`=1665, `npcflag`=35184372088832, `speed_walk`=2.799999952316284179, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=98336 WHERE `entry`=157406; -- Renavyth
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags3`=32769 WHERE `entry`=164808; -- Medallón de Renavyth
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=33556480 WHERE `entry`=165361; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67125248, `unit_flags3`=32769 WHERE `entry`=164542; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=67108864, `unit_flags3`=1 WHERE `entry`=168114; -- Placa de presión
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=150965; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=35653632 WHERE `entry`=173191; -- Acechador de almas V'lara
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=67110912 WHERE `entry`=166953; -- Elite Rune Bunny
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=7, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67125248, `unit_flags3`=1 WHERE `entry`=166660; -- Palanca
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=166713; -- Puerta de celda
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480, `HoverHeight`=1.10000002384185791 WHERE `entry`=155812; -- Ritualista jurafauces
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3204, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=167231; -- Nigromante maldraxxi
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=67141632, `unit_flags3`=32769 WHERE `entry`=170130; -- Trampa de púas
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=71319552, `unit_flags3`=32769 WHERE `entry`=164549; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3204, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33554432 WHERE `entry`=167230; -- Esqueleto maldraxxi
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=169628; -- Restos de alma atormentada
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1665, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67143680 WHERE `entry`=173649; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=67110912, `unit_flags3`=32768 WHERE `entry`=169635; -- Restos de alma atormentada
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=100665344 WHERE `entry`=174803; -- Soul Scythe
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=169632; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=4196352, `unit_flags3`=1 WHERE `entry`=155945; -- Gherus el Encadenado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480 WHERE `entry`=168108; -- Creación torpe potenciada
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=155824; -- Creación torpe
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=175069; -- Salir de Torghast
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=171336; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912 WHERE `entry`=156480; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=157807; -- Tejealmas jurafauces
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=290, `BaseAttackTime`=2000, `unit_flags`=33587712, `unit_flags2`=33556480 WHERE `entry`=169782; -- Restos de alma esclava
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=290, `BaseAttackTime`=2000, `unit_flags`=33587712, `unit_flags2`=33556480 WHERE `entry`=157561; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=153849; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=188, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480, `unit_flags3`=1 WHERE `entry`=171159; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480, `HoverHeight`=1.10000002384185791 WHERE `entry`=155831; -- Atrapaalmas jurafauces
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1665, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67143680 WHERE `entry`=173645; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=153874; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=169237; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=164471; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480, `HoverHeight`=1.60000002384185791 WHERE `entry`=168109; -- Ritualista jurafauces potenciado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=164539; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=152594; -- Broker Ve'ken
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=164538; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=559104, `unit_flags3`=1 WHERE `entry`=167986; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=150958; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=155830; -- Discípulo jurafauces
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=152708; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=166360; -- Punto de agarre
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=169560; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67108864, `unit_flags3`=32769 WHERE `entry`=169561; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=188, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480, `unit_flags3`=1 WHERE `entry`=171166; -- Restos de alma desbocada
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=151353; -- Mawrat
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=155790; -- Acólito jurafauces
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=559104, `unit_flags3`=1 WHERE `entry`=164698; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `speed_walk`=1.60000002384185791, `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=155793; -- Restos esqueléticos
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=67110912, `unit_flags3`=32768 WHERE `entry`=165799; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=100698112 WHERE `entry`=170724; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67635200, `unit_flags3`=32768 WHERE `entry`=173236; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=25682, `npcflag`=3, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags2`=34816 WHERE `entry`=164937; -- Runecarver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=175698; -- Doomed Soul
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=173640; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=19, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=156681; -- Costurero Au'phes
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=17179869184, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=32 WHERE `entry`=173351; -- Facilitador de comercio
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=156686; -- Seleccionador Au'mar
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175211; -- Asistente real
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=156732; -- Distribuidor Au'sha
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=156689; -- Distribuidor Au'naci
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=156687; -- Elixirista Au'pyr
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=170651; -- Baine Pezuña de Sangre
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=2050, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=176332; -- Caballero de la Espada de Ébano
UPDATE `creature_template` SET `gossip_menu_id`=25685 WHERE `entry`=168011; -- Zo'sorg
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=159478; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=162666; -- Pathscribe Roh-Avonavi
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=178804; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2131968, `unit_flags3`=1 WHERE `entry`=176308; -- -Unknown-
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048 WHERE `entry`=170825; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0, `unit_flags2`=2099200 WHERE `entry`=70528; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=25278, `minlevel`=60, `maxlevel`=60, `faction`=7, `npcflag`=4227, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=4212736 WHERE `entry`=162804; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=94, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=172925; -- -Unknown-
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048 WHERE `entry`=170824; -- -Unknown-
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048 WHERE `entry`=170819; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=1073743872, `unit_flags3`=1 WHERE `entry`=172631; -- -Unknown-
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048 WHERE `entry`=170827; -- -Unknown-
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048 WHERE `entry`=170826; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=173668; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=3218, `BaseAttackTime`=2000, `unit_flags`=33587520, `unit_flags2`=33556480 WHERE `entry`=152898; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=26656, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=71337984 WHERE `entry`=175009; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=175121; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=26677, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=71354368 WHERE `entry`=175127; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=26658, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=71337984 WHERE `entry`=175026; -- -Unknown-


DELETE FROM `quest_template` WHERE `ID` IN (61075 /*-Unknown-*/, 63062 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(61075, 2, 0, 742, 11400, 0, 0, 0, 6, 1, 514800, 6, 1, 0, 0, 0, 0, 180607, 0, 1, 0, 33554824, 2097216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 180607, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2432, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 7, 7, 7, 7, 85000, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 1646, 8, 0, 0, 1767, 0, 0, 0, 425, 0, 0, 0, 890, 878, 38134), -- -Unknown-
(63062, 2, 0, 742, 11400, 0, 0, 0, 5, 1, 257400, 5, 1, 61750, 0, 0, 0, 0, 0, 1, 0, 33554568, 2138176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2432, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 7, 7, 7, 7, 7500, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 8, 0, 0, 1767, 0, 0, 0, 140, 0, 0, 0, 890, 878, 38134); -- -Unknown-

UPDATE `quest_template` SET `FlagsEx`=2149580864, `VerifiedBuild`=38134 WHERE `ID`=59344; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105664, `VerifiedBuild`=38134 WHERE `ID`=60269; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105664, `VerifiedBuild`=38134 WHERE `ID`=60268; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105664, `VerifiedBuild`=38134 WHERE `ID`=62967; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=60281; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=514800, `FlagsEx`=2097216, `TreasurePickerID`=1646, `VerifiedBuild`=38134 WHERE `ID`=60646; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2105408, `VerifiedBuild`=38134 WHERE `ID`=63051; -- -Unknown-
UPDATE `quest_template` SET `RewardMoney`=257400, `FlagsEx`=2129984, `VerifiedBuild`=38134 WHERE `ID`=63031; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2097216, `VerifiedBuild`=38134 WHERE `ID`=62910; -- -Unknown-
UPDATE `quest_template` SET `FlagsEx`=2621504, `VerifiedBuild`=38134 WHERE `ID`=62932; -- -Unknown-

DELETE FROM `quest_objectives` WHERE `ID` IN (411627 /*411627*/, 405172 /*405172*/, 409275 /*409275*/, 409150 /*409150*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `VerifiedBuild`) VALUES
(411627, 60269, 19, 2, 2, 21983, 0, 2, 0, 0, 38134), -- 411627
(405172, 61075, 0, 0, 0, 171179, 4, 0, 0, 0, 38134), -- 405172
(409275, 63062, 0, 1, 3, 176377, 100, 28, 0, 0, 38134), -- 409275
(409150, 63062, 0, 0, 0, 175973, 1, 0, 0, 0, 38134); -- 409150

UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=396362; -- 396362
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408904; -- 408904
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398033; -- 398033
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398032; -- 398032
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409004; -- 409004
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=398071; -- 398071
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409228; -- 409228
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409227; -- 409227
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409224; -- 409224
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409112; -- 409112
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=409030; -- 409030
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408920; -- 408920
UPDATE `quest_objectives` SET `VerifiedBuild`=38134 WHERE `ID`=408951; -- 408951

DELETE FROM `quest_visual_effect` WHERE (`ID`=409150 AND `Index` IN (1,0));
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(409150, 1, 16830, 38134),
(409150, 0, 16829, 38134);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396362 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398033 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398033 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398032 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398071 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=409228 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=409227 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=409112 AND `Index`=0);



DELETE FROM `playerchoice` WHERE `ChoiceId` IN (598, 611, 573);
INSERT INTO `playerchoice` (`ChoiceId`, `UiTextureKitId`, `SoundKitId`, `Question`, `HideWarboardHeader`, `KeepOpenAfterChoice`, `VerifiedBuild`) VALUES
(598, 5275, 168437, '', 0, 0, 38134),
(611, 5275, 168437, 'c�4����-wEl ánima toma la', 0, 0, 38134),
(573, 5275, 168437, '', 0, 0, 38134);


DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=588 AND `ResponseId`=0 AND `Index`=1) OR (`ChoiceId`=588 AND `ResponseId`=0 AND `Index`=0) OR (`ChoiceId`=598 AND `ResponseId`=0 AND `Index`=1) OR (`ChoiceId`=598 AND `ResponseId`=0 AND `Index`=0) OR (`ChoiceId`=573 AND `ResponseId`=0 AND `Index`=1) OR (`ChoiceId`=573 AND `ResponseId`=0 AND `Index`=0) OR (`ChoiceId`=611 AND `ResponseId`=0 AND `Index`=0) OR (`ChoiceId`=611 AND `ResponseId`=0 AND `Index`=1);
REPLACE INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `ResponseIdentifier`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(588, 0, 26525, 1, 52, -65536, 756678655, 318439424, 196613, 0, '@Abalorios de oración profanados$332407sc�4����-w03)�@Incensario almaforjado$332534sb�4����-�', '', '¿Qué forma debería tomar el ánima?', '', '', '', 0, 0, 38134),
(588, 0, 46, 0, 1360759, 0, 0, 0, 0, 0, 'Riendas tocadas por las almas', '', '', '', '$332539s', '', 0, 0, 38134),
(598, 0, -26525, 1, 131124, 1893531648, 757202688, 2157707264, 4, 0, '�@Gratitud de los Venthyr$306575sb�4�p�!-��El prisionero agradecido te entrega un poco de ánima. ¿Qué forma debería tomar?', '', '', '', '', '', 0, 0, 38134),
(598, 0, 44, 0, 3743737, 0, 0, 0, 0, 0, 'Abundancia de phantasma', '', '', '', '$295068s', '', 0, 0, 38134),
(573, 0, -26525, 1, 65588, -16777216, 757268254, 2158034944, 4, 0, '@@Capa de subterfugio de V\'lara$338948sc�4�p�!-,+$v�@Broche protegealmas$338922sb�4', '', '�p�!-�+¿Qué forma debería tomar el ánima?', '', '', '', 0, 0, 38134),
(573, 0, 41, 0, 3743737, 0, 0, 0, 0, 0, 'Bolsa de phantasma', '', '', '', '$295073s', '', 0, 0, 38134),
(611, 0, 40, 0, 1027815, 0, 0, 0, 0, 0, 'Abalorios de oración profanados', '', '', '', '$332407s', '', 0, 0, 38134),
(611, 0, 26526, 1, 131124, 1893531648, 757202688, 344653824, 131077, 0, '', '', '@@Especias secretas$295694sa�4�p�!-�k�5@Núcleo de alma aullante$341576sc�4�p�!-H6El ánima toma la forma de un favor poderoso.', '', '', '', 0, 0, 38134);



DELETE FROM `npc_text` WHERE `ID` IN (41849 /*41849*/, 38631 /*38631*/, 40535 /*40535*/, 40520 /*40520*/, 42519 /*42519*/, 42518 /*42518*/, 42517 /*42517*/, 42516 /*42516*/, 42627 /*42627*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(41849, 1, 0, 0, 0, 0, 0, 0, 0, 204883, 0, 0, 0, 0, 0, 0, 0, 38134), -- 41849
(38631, 1, 0, 0, 0, 0, 0, 0, 0, 179525, 0, 0, 0, 0, 0, 0, 0, 38134), -- 38631
(40535, 1, 0, 0, 0, 0, 0, 0, 0, 196644, 0, 0, 0, 0, 0, 0, 0, 38134), -- 40535
(40520, 1, 0, 0, 0, 0, 0, 0, 0, 196524, 0, 0, 0, 0, 0, 0, 0, 38134), -- 40520
(42519, 0, 0, 0, 0, 0, 0, 0, 0, 207119, 0, 0, 0, 0, 0, 0, 0, 38134), -- 42519
(42518, 0, 0, 0, 0, 0, 0, 0, 0, 207118, 0, 0, 0, 0, 0, 0, 0, 38134), -- 42518
(42517, 0, 0, 0, 0, 0, 0, 0, 0, 207113, 0, 0, 0, 0, 0, 0, 0, 38134), -- 42517
(42516, 1, 0, 0, 0, 0, 0, 0, 0, 207112, 0, 0, 0, 0, 0, 0, 0, 38134), -- 42516
(42627, 0, 0, 0, 0, 0, 0, 0, 0, 207442, 0, 0, 0, 0, 0, 0, 0, 38134); -- 42627

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=40543; -- 40543
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=40584; -- 40584

DELETE FROM `world_quest` WHERE `id` IN (54471 /*54471*/, 61603 /*61603*/, 61867 /*61867*/, 60858 /*60858*/, 51500 /*51500*/, 60655 /*60655*/, 55889 /*55889*/, 50876 /*50876*/, 55834 /*55834*/, 58221 /*58221*/, 61337 /*61337*/, 54569 /*54569*/, 56048 /*56048*/, 55900 /*55900*/, 60646 /*60646*/, 57650 /*57650*/, 60872 /*60872*/, 52889 /*52889*/, 60786 /*60786*/, 46179 /*46179*/, 54540 /*54540*/, 55302 /*55302*/, 60457 /*60457*/, 61883 /*61883*/, 56036 /*56036*/, 46006 /*46006*/, 61787 /*61787*/, 52456 /*52456*/, 52167 /*52167*/, 55720 /*55720*/, 52464 /*52464*/, 53714 /*53714*/, 63031 /*63031*/, 54622 /*54622*/, 54089 /*54089*/, 55837 /*55837*/, 63062 /*63062*/, 61075 /*61075*/, 46011 /*46011*/, 61549 /*61549*/, 57338 /*57338*/, 60911 /*60911*/, 61949 /*61949*/, 54236 /*54236*/, 59743 /*59743*/);
INSERT INTO `world_quest` (`id`, `duration`, `variable`, `value`) VALUES
(54471, 25200, 16290, 1), -- 54471
(61603, 86400, 20382, 12), -- 61603
(61867, 86400, 19955, 1), -- 61867
(60858, 86400, 19497, 1), -- 60858
(51500, 345600, 15926, 1), -- 51500
(60655, 86400, 19424, 1), -- 60655
(55889, 259200, 17587, 1), -- 55889
(50876, 86400, 14964, 1), -- 50876
(55834, 86400, 17529, 1), -- 55834
(58221, 86400, 18290, 1), -- 58221
(61337, 86400, 19733, 1), -- 61337
(54569, 86400, 16869, 1), -- 54569
(56048, 86400, 17690, 1), -- 56048
(55900, 86400, 17583, 1), -- 55900
(60646, 604800, 19686, 1), -- 60646
(57650, 86400, 18431, 2), -- 57650
(60872, 86400, 19498, 1), -- 60872
(52889, 86400, 15499, 2), -- 52889
(60786, 86400, 19472, 1), -- 60786
(46179, 21600, 13005, 1), -- 46179
(54540, 86400, 16870, 1), -- 54540
(55302, 86400, 17260, 1), -- 55302
(60457, 259200, 19339, 1), -- 60457
(61883, 86400, 19964, 1), -- 61883
(56036, 86400, 17683, 1), -- 56036
(46006, 21600, 13074, 1), -- 46006
(61787, 86400, 19943, 1), -- 61787
(52456, 345600, 15041, 2), -- 52456
(52167, 86400, 16041, 1), -- 52167
(55720, 86400, 17442, 1), -- 55720
(52464, 86400, 15764, 1), -- 52464
(53714, 25200, 16290, 1), -- 53714
(63031, 86400, 20306, 1), -- 63031
(54622, 86400, 16910, 1), -- 54622
(54089, 25200, 16290, 1), -- 54089
(55837, 86400, 17532, 1), -- 55837
(63062, 86400, 20308, 1), -- 63062
(61075, 604800, 19684, 1), -- 61075
(46011, 21600, 13077, 1), -- 46011
(61549, 86400, 19850, 1), -- 61549
(57338, 43200, 18141, 1), -- 57338
(60911, 86400, 19528, 1), -- 60911
(61949, 86400, 19978, 1), -- 61949
(54236, 86400, 16682, 1), -- 54236
(59743, 86400, 18687, 1); -- 59743

UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45439; -- 45439
UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45390; -- 45390
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45786; -- 45786
UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45439; -- 45439
UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45390; -- 45390
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45786; -- 45786
UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45439; -- 45439
UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45390; -- 45390
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45786; -- 45786
UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45439; -- 45439
UPDATE `world_quest` SET `variable`=14245 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=14064 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45390; -- 45390
UPDATE `world_quest` SET `variable`=13005 WHERE `id`=45786; -- 45786

