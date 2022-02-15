-- 690 Una petición de Malin
-- https://es.classic.wowhead.com/quest=690
SET @ID := 690;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que t\'envía Malin? M\'importa un bledo que Muradin resucitara y te pusiera un dragón pa\' traerte aquí. ¡Estoy ocupao! Habla con Kryten pa\' lo que sea.', 0),
(@ID, 'esMX', '¿Así que t\'envía Malin? M\'importa un bledo que Muradin resucitara y te pusiera un dragón pa\' traerte aquí. ¡Estoy ocupao! Habla con Kryten pa\' lo que sea.', 0);
-- 1477 Suministros de vital importancia
-- https://es.classic.wowhead.com/quest=1477
SET @ID := 1477;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Andromath? Muy bien. Tengo una importante tarea para ti...', 0),
(@ID, 'esMX', '¿Te envía Andromath? Muy bien. Tengo una importante tarea para ti...', 0);
-- 2861 La tarea de Tabetha
-- https://es.classic.wowhead.com/quest=2861
SET @ID := 2861;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es cierto. Tengo unas cuentas que arreglar con un trol. Algunas cuentas. ¡Todas!$B$B¿Quieres ayudarme?', 0),
(@ID, 'esMX', 'Es cierto. Tengo unas cuentas que arreglar con un trol. Algunas cuentas. ¡Todas!$B$B¿Quieres ayudarme?', 0);
-- 212 Un plato bien frío
-- https://es.classic.wowhead.com/quest=212
SET @ID := 212;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Has conseguido el anca ya? Debo cocinar pronto, ¡o el banquete será un desastre total!', 0),
(@ID, 'esMX', '¡$n! ¿Has conseguido el anca ya? Debo cocinar pronto, ¡o el banquete será un desastre total!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡esto vendrá de perlas! ¡Muchas, pero que muchísimas gracias!$B$BAhora, si me disculpas, tengo que picar esta pierna, marinarla y preparar la guarnición para el banquete.', 0),
(@ID, 'esMX', 'Ah, ¡esto vendrá de perlas! ¡Muchas, pero que muchísimas gracias!$B$BAhora, si me disculpas, tengo que picar esta pierna, marinarla y preparar la guarnición para el banquete.', 0);
-- 1260 Morgan Stern
-- https://es.classic.wowhead.com/quest=1260
SET @ID := 1260;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, así que te envía mi tío, ¿eh?$B$BBueno, he estado investigando unas recetas, y tengo algunas pistas, pero necesito ayuda.$B$BAyuda de alguien a quien no le importe mojarse los pies.', 0),
(@ID, 'esMX', 'Ah, así que te envía mi tío, ¿eh?$B$BBueno, he estado investigando unas recetas, y tengo algunas pistas, pero necesito ayuda.$B$BAyuda de alguien a quien no le importe mojarse los pies.', 0);
-- 55 Morbent Vil
-- https://es.classic.wowhead.com/quest=55
SET @ID := 55;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Has derrotado a Morbent Vil?!', 0),
(@ID, 'esMX', '¡¿Has derrotado a Morbent Vil?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Morbent Vil ha sido derrotado. Los jinetes oscuros aún andan por ahí, pero ya ha ocurrido una de las dos cosas que esperaba con desesperación.$B$BHas hecho lo imposible y tu hazaña perdurará en las leyendas del Bosque del Ocaso.$B$BVe, $n. Quizás un día, el destino vuelva a traerte a mí...', 0),
(@ID, 'esMX', 'Morbent Vil ha sido derrotado. Los jinetes oscuros aún andan por ahí, pero ya ha ocurrido una de las dos cosas que esperaba con desesperación.$B$BHas hecho lo imposible y tu hazaña perdurará en las leyendas del Bosque del Ocaso.$B$BVe, $n. Quizás un día, el destino vuelva a traerte a mí...', 0);
-- 284 La búsqueda continúa
-- https://es.classic.wowhead.com/quest=284
SET @ID := 284;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barril no ha sido tocado en mucho tiempo. Lo abres...$B$B... y te abruma un fuerte olor a queso. Está un poco mojado, ¡pero aún está bueno!', 0),
(@ID, 'esMX', 'El barril no ha sido tocado en mucho tiempo. Lo abres...$B$B... y te abruma un fuerte olor a queso. Está un poco mojado, ¡pero aún está bueno!', 0);
-- 285 Inspecciona más casuchas
-- https://es.classic.wowhead.com/quest=285
SET @ID := 285;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barril está casi enterrado entre el barro y la hierba...', 0),
(@ID, 'esMX', 'El barril está casi enterrado entre el barro y la hierba...', 0);
-- 286 Devuelve la Estatuilla
-- https://es.classic.wowhead.com/quest=286
SET @ID := 286;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la estatuilla?', 0),
(@ID, 'esMX', '¿Tienes la estatuilla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El capitán de La princesa ciega se sentirá aliviado al saber que has recuperado su precioso cargamento. Te has ganado el pago por tus servicios.$B$BEs bueno encontrar a gente fiable como tú, especialmente en tiempos difíciles como estos.', 0),
(@ID, 'esMX', 'El capitán de La princesa ciega se sentirá aliviado al saber que has recuperado su precioso cargamento. Te has ganado el pago por tus servicios.$B$BEs bueno encontrar a gente fiable como tú, especialmente en tiempos difíciles como estos.', 0);
-- 290 Purga de la maldición
-- https://es.classic.wowhead.com/quest=290
SET @ID := 290;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este cofre está bien cerrado.', 0),
(@ID, 'esMX', 'Este cofre está bien cerrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave está oxidada pero entra perfectamente en el candado.', 0),
(@ID, 'esMX', 'La llave está oxidada pero entra perfectamente en el candado.', 0);
-- 292 El ojo de Paleth
-- https://es.classic.wowhead.com/quest=292
SET @ID := 292;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía el borracho de Fistimos? Puedes decirle que no tengo más cerveza. ¡Tendrá que ir mendigarle a otro!', 0),
(@ID, 'esMX', '¿Te envía el borracho de Fistimos? Puedes decirle que no tengo más cerveza. ¡Tendrá que ir mendigarle a otro!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un ojo de Paleth? ¡Fascinante! Umm... algo va mal con este. ¿Lo encontraste en uno de los restos de naufragio? ¡Eso lo explica todo! Pero... no sabía que tuvieran un ojo así en la Tercera Flota...$B$BNo me extraña que Fistimos estuviera tan asustado. Encontrarse con un Ojo maldito de Paleth no es ninguna alegría.', 0),
(@ID, 'esMX', '¿Un ojo de Paleth? ¡Fascinante! Umm... algo va mal con este. ¿Lo encontraste en uno de los restos de naufragio? ¡Eso lo explica todo! Pero... no sabía que tuvieran un ojo así en la Tercera Flota...$B$BNo me extraña que Fistimos estuviera tan asustado. Encontrarse con un Ojo maldito de Paleth no es ninguna alegría.', 0);
-- 293 Limpieza del ojo
-- https://es.classic.wowhead.com/quest=293
SET @ID := 293;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es ese orbe? Parece... dañado.', 0),
(@ID, 'esMX', '¿Qué es ese orbe? Parece... dañado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un ojo de Paleth. Pero este ha visto demasiado dolor... debe haber sido testigo de una terrible, terrible tragedia.$B$BDéjame purificarlo, los ojos fueron creados para iluminar y sus poderes pueden ser muy peligrosos si están malditos como este.', 0),
(@ID, 'esMX', 'Un ojo de Paleth. Pero este ha visto demasiado dolor... debe haber sido testigo de una terrible, terrible tragedia.$B$BDéjame purificarlo, los ojos fueron creados para iluminar y sus poderes pueden ser muy peligrosos si están malditos como este.', 0);
-- 681 Mansión Redilnorte
-- https://es.classic.wowhead.com/quest=681
SET @ID := 681;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, con cada hora que pasa nuestro control sobre Stromgarde se vuelve más débil. Debes darte prisa o nuestra ciudad seguramente caerá.', 0),
(@ID, 'esMX', '$n, con cada hora que pasa nuestro control sobre Stromgarde se vuelve más débil. Debes darte prisa o nuestra ciudad seguramente caerá.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Con la muerte de los miembros de la Hermandad debería ser más fácil recibir los suministros de Costasur.$B$BQuizás aún quede esperanza para nuestra causa.', 0),
(@ID, 'esMX', 'Muy bien, $n. Con la muerte de los miembros de la Hermandad debería ser más fácil recibir los suministros de Costasur.$B$BQuizás aún quede esperanza para nuestra causa.', 0);
-- 684 Se busca: Marez Cogulla
-- https://es.classic.wowhead.com/quest=684
SET @ID := 684;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¿Tienes un informe para mí?', 0),
(@ID, 'esMX', 'Saludos, $c. ¿Tienes un informe para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has despachado a Marez Cogulla? Muy bien, $n. ¡Pero que muy bien!$B$BMarez era una amenaza para nuestros defensores de Stromgarde y se rumoreaba que era una emisaria entre la Hermandad y algún poder más oscuro. Nos alegramos de que ya no ejerza sus poderes contra nosotros.', 0),
(@ID, 'esMX', '¿Has despachado a Marez Cogulla? Muy bien, $n. ¡Pero que muy bien!$B$BMarez era una amenaza para nuestros defensores de Stromgarde y se rumoreaba que era una emisaria entre la Hermandad y algún poder más oscuro. Nos alegramos de que ya no ejerza sus poderes contra nosotros.', 0);
-- 685 Se busca: Otto y Lord Falconcrest
-- https://es.classic.wowhead.com/quest=685
SET @ID := 685;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. ¿Vienes a presentar un informe?', 0),
(@ID, 'esMX', 'Hola. ¿Vienes a presentar un informe?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Falconcrest y Otto? ¡Estupendo!$B$BAquí tienes tu recompensa, $n. Te la pago con mucho gusto.', 0),
(@ID, 'esMX', '¿Falconcrest y Otto? ¡Estupendo!$B$BAquí tienes tu recompensa, $n. Te la pago con mucho gusto.', 0);
-- 691 Valer su peso en oro
-- https://es.classic.wowhead.com/quest=691
SET @ID := 691;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte hasta ahora, $n?$B$B<Kryten toma algunas notas en su diario mientras lee>$B$BSi mi investigación es correcta, los colmillos deberían proceder de cualquier trol Secacorteza. Las bolsas de medicina proceden de los médicos brujos Secacorteza y el más fuerte de los cazadores oscuros Secacorteza debería llevar el cuchillo especial que se les entrega después de completar sus ritos de paso. No hay forma de saber qué cazador oscuro lleva el cuchillo hasta que te enfrentas a ellos.', 0),
(@ID, 'esMX', '¿Ha habido suerte hasta ahora, $n?$B$B<Kryten toma algunas notas en su diario mientras lee>$B$BSi mi investigación es correcta, los colmillos deberían proceder de cualquier trol Secacorteza. Las bolsas de medicina proceden de los médicos brujos Secacorteza y el más fuerte de los cazadores oscuros Secacorteza debería llevar el cuchillo especial que se les entrega después de completar sus ritos de paso. No hay forma de saber qué cazador oscuro lleva el cuchillo hasta que te enfrentas a ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Ahora entiendo por qué Malin te pidió que te unieras a nosotros, ¡gran idea, digo!$B$BA este paso, Skuerto y yo estaremos de vuelta en Ventormenta antes de que nos demos cuenta.$B$BCreo que mi compañero enano ha vuelto de su exploración de la Sala Puño de Roca; ve a hablar con él cuando estés $glisto:lista;.$B$BAl parecer, tuvo una escaramuza con los ogros. Aunque ni se lo menciones, es muy sensible ante las críticas a sus habilidades y a su trabajo como rastreador.', 0),
(@ID, 'esMX', '¡Increíble! Ahora entiendo por qué Malin te pidió que te unieras a nosotros, ¡gran idea, digo!$B$BA este paso, Skuerto y yo estaremos de vuelta en Ventormenta antes de que nos demos cuenta.$B$BCreo que mi compañero enano ha vuelto de su exploración de la Sala Puño de Roca; ve a hablar con él cuando estés $glisto:lista;.$B$BAl parecer, tuvo una escaramuza con los ogros. Aunque ni se lo menciones, es muy sensible ante las críticas a sus habilidades y a su trabajo como rastreador.', 0);
-- 3636 Trae la Luz
-- https://es.classic.wowhead.com/quest=3636
SET @ID := 3636;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Amnennar debe ser erradicado. Vete rápido.', 0),
(@ID, 'esMX', 'Amnennar debe ser erradicado. Vete rápido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. La Plaga ahora se lo pensará dos veces antes de intentar incrementar sus ejércitos.$B$BQue la Luz te bendiga.', 0),
(@ID, 'esMX', 'Gracias, $n. La Plaga ahora se lo pensará dos veces antes de intentar incrementar sus ejércitos.$B$BQue la Luz te bendiga.', 0);
-- 6141 Hermano Anton
-- https://es.classic.wowhead.com/quest=6141
SET @ID := 6141;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recibí noticias de una ayuda que llegaba del este. ¿Eres tú el objeto de tales rumores? ¿Has venido aquí a ayudar a la Hermandad Escarlata en su cruzada?$B$BSi es así, escucha con atención...', 0),
(@ID, 'esMX', 'Recibí noticias de una ayuda que llegaba del este. ¿Eres tú el objeto de tales rumores? ¿Has venido aquí a ayudar a la Hermandad Escarlata en su cruzada?$B$BSi es así, escucha con atención...', 0);
-- 682 Distintivos de Stromgarde
-- https://es.wowhead.com/quest=682
-- https://wow-es.gamepedia.com/Misión:Distintivos de Stromgarde
SET @ID := 682;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido recuperar alguna de las insignias de Stromgarde, $n? La Hermandad debe aprender que no se aprovecharán de nuestros muertos.', 0),
(@ID, 'esMX', '¿Has conseguido recuperar alguna de las insignias de Stromgarde, $n? La Hermandad debe aprender que no se aprovecharán de nuestros muertos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Informaremos a las familias sobre los soldados caídos en la batalla.$B$BSerán noticias crudas pero es mejor que la incertidumbre de alguien querido que ha desaparecido.', 0),
(@ID, 'esMX', 'Gracias, $n. Informaremos a las familias sobre los soldados caídos en la batalla.$B$BSerán noticias crudas pero es mejor que la incertidumbre de alguien querido que ha desaparecido.', 0);
-- 693 Empuñar la varita
-- https://es.classic.wowhead.com/quest=693
SET @ID := 693;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro objetivo es la varita, $n. Por ahora céntrate en eso.', 0),
(@ID, 'esMX', 'Nuestro objetivo es la varita, $n. Por ahora céntrate en eso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, $n! 1 menos, solo faltan 3, según mi lista. Los otros 3 están en Stromgarde.$B$BDescansa un poco pa’ recuperar las fuerzas, que t’hará buena falta pa’ la siguiente fase de mi plan. Vuelve cuando hayas tomado algo caliente y hayas descansado.', 0),
(@ID, 'esMX', '¡Genial, $n! 1 menos, solo faltan 3, según mi lista. Los otros 3 están en Stromgarde.$B$BDescansa un poco pa’ recuperar las fuerzas, que t’hará buena falta pa’ la siguiente fase de mi plan. Vuelve cuando hayas tomado algo caliente y hayas descansado.', 0);
-- 694 Las defensas de Trelane
-- https://es.classic.wowhead.com/quest=694
SET @ID := 694;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola otra vez, $n. ¿Has encontrado ya una ágata azur?', 0),
(@ID, 'esMX', 'Hola otra vez, $n. ¿Has encontrado ya una ágata azur?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $n. Una vez más, enhorabuena.$B$BDame un momento para lanzar el hechizo apropiado para encantar la gema ¡y listo!', 0),
(@ID, 'esMX', 'Impresionante, $n. Una vez más, enhorabuena.$B$BDame un momento para lanzar el hechizo apropiado para encantar la gema ¡y listo!', 0);
