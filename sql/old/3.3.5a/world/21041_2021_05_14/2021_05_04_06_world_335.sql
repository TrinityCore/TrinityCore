-- 9366 Se busca: Sangrevil
-- https://es.wowhead.com/quest=9366
SET @ID := 9366;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La sangrevil... ¿la has conseguido, $n?', 0),
(@ID, 'esMX', 'La sangrevil... ¿la has conseguido, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La energía contenida en estas muestras es tremenda, $n. Ahora solo tenemos que asegurarnos de que nuestro acceso a esta sangrevil no se interrumpe.', 0),
(@ID, 'esMX', 'La energía contenida en estas muestras es tremenda, $n. Ahora solo tenemos que asegurarnos de que nuestro acceso a esta sangrevil no se interrumpe.', 0);
-- El Festival del Fuego
-- 9367, 9368
-- https://es.classic.wowhead.com/quest=9367
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9367, 9368) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9367, 'esES', '¿Están ardiendo las hogueras?', 0),
(9368, 'esES', '¿Están ardiendo las hogueras?', 0),
(9367, 'esMX', '¿Están ardiendo las hogueras?', 0),
(9368, 'esMX', '¿Están ardiendo las hogueras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9367, 9368) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9367, 'esES', '¡Excelente! Me alegra saber que las hogueras arden correctamente este año. Gracias por ir a inspeccionarlas en mi lugar; acepta esto en prueba de mi gratitud.', 0),
(9368, 'esES', '¡Excelente! Me alegra saber que las hogueras arden correctamente este año. Gracias por ir a inspeccionarlas en mi lugar; acepta esto en prueba de mi gratitud.', 0),
(9367, 'esMX', '¡Excelente! Me alegra saber que las hogueras arden correctamente este año. Gracias por ir a inspeccionarlas en mi lugar; acepta esto en prueba de mi gratitud.', 0),
(9368, 'esMX', '¡Excelente! Me alegra saber que las hogueras arden correctamente este año. Gracias por ir a inspeccionarlas en mi lugar; acepta esto en prueba de mi gratitud.', 0);
-- 9369 Recargar los cristales de sanación
-- https://es.wowhead.com/quest=9369
SET @ID := 9369;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes la sangre de polilla del valle para los cristales de sanación? ¡Debemos apresurarnos, hay muchos supervivientes en el valle!', 0),
(@ID, 'esMX', '¿Traes la sangre de polilla del valle para los cristales de sanación? ¡Debemos apresurarnos, hay muchos supervivientes en el valle!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es lamentable que esas criaturas tuvieran que morir para que nosotros vivamos; los draenei no matamos indiscriminadamente. Pero la sangre que traes recargará nuestros cristales de sanación. La muerte de esas criaturas no ha sido en vano.', 0),
(@ID, 'esMX', 'Es lamentable que esas criaturas tuvieran que morir para que nosotros vivamos; los draenei no matamos indiscriminadamente. Pero la sangre que traes recargará nuestros cristales de sanación. La muerte de esas criaturas no ha sido en vano.', 0);
-- 9370 Detengamos la purificación
-- https://es.wowhead.com/quest=9370
SET @ID := 9370;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado, $n. ¿Acabaste con la locura de los draenei?', 0),
(@ID, 'esMX', 'Has regresado, $n. ¿Acabaste con la locura de los draenei?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así aprenderán esos fanáticos a meterse en sus propios asuntos.', 0),
(@ID, 'esMX', 'Así aprenderán esos fanáticos a meterse en sus propios asuntos.', 0);
-- 9371 La botánica Taerix
-- https://es.wowhead.com/quest=9371
-- https://es.tbc.wowhead.com/quest=9371
SET @ID := 9371;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Menos mal que has venido. Tenemos muchísimo que hacer.', 0),
(@ID, 'esMX', 'Menos mal que has venido. Tenemos muchísimo que hacer.', 0);
-- 9372 Contaminación demoníaca
-- https://es.wowhead.com/quest=9372
SET @ID := 9372;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste recolectar las muestras de sangre?', 0),
(@ID, 'esMX', '¿Pudiste recolectar las muestras de sangre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Estas muestras de sangre serán muy útiles en mi investigación y en los estudios de mayor alcance que la expedición está llevando a cabo sobre las criaturas de Terrallende.$B$BSi pudiera aislar lo que hace cambiar estas criaturas continuamente, quizás podría inventar un antídoto.', 0),
(@ID, 'esMX', 'Muy bien, $n. Estas muestras de sangre serán muy útiles en mi investigación y en los estudios de mayor alcance que la expedición está llevando a cabo sobre las criaturas de Terrallende.$B$BSi pudiera aislar lo que hace cambiar estas criaturas continuamente, quizás podría inventar un antídoto.', 0);
-- 9373 Carta perdida
-- https://es.wowhead.com/quest=9373
SET @ID := 9373;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buenos días, $c. ¿Qué te trae por mi campamento?', 0),
(@ID, 'esMX', 'Buenos días, $c. ¿Qué te trae por mi campamento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por traerme esto, $c. Me preguntaba por qué no había tenido noticias de la expedición en tanto tiempo. ¿Cuánto tiempo habrá pasado desde que enviaron este mensaje y qué habrá sido de su portador?$B$BAquí tienes, por las molestias.', 0),
(@ID, 'esMX', 'Gracias por traerme esto, $c. Me preguntaba por qué no había tenido noticias de la expedición en tanto tiempo. ¿Cuánto tiempo habrá pasado desde que enviaron este mensaje y qué habrá sido de su portador?$B$BAquí tienes, por las molestias.', 0);
-- 9374 El diario de Arelion
-- https://es.wowhead.com/quest=9374
SET @ID := 9374;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte, $n? Encontrarás las Pozas de Aggonar al norte de la Ciudadela del Fuego Infernal.', 0),
(@ID, 'esMX', '¿Ha habido suerte, $n? Encontrarás las Pozas de Aggonar al norte de la Ciudadela del Fuego Infernal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El diario de mi marido... no tiene nada que ver con la investigación!$B$B¿Cómo he podido ser tan estúpida? "Propiedades mágicas de las babosas imbuidas de sustancia envilecedora", me lo había tragado.', 0),
(@ID, 'esMX', '¡El diario de mi marido... no tiene nada que ver con la investigación!$B$B¿Cómo he podido ser tan estúpida? "Propiedades mágicas de las babosas imbuidas de sustancia envilecedora", me lo había tragado.', 0);
-- 9375 Hacia la Avanzada del Halcón
-- https://es.wowhead.com/quest=9375
SET @ID := 9375;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué necesitas, $c?', 0),
(@ID, 'esMX', '¿Qué necesitas, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Taleris increpa a gritos a varios elfos de sangre en la avanzada.>$B$B¡Llevadla adentro y atended sus heridas!$B$B<Taleris se vuelve hacia ti.>$B$BTiene suerte de que la encontraras cuando lo hiciste, $c. No creo que hubiera durado mucho más ahí fuera.$B$B¿Entiendes lo que estaba diciendo?', 0),
(@ID, 'esMX', '<Taleris increpa a gritos a varios elfos de sangre en la avanzada.>$B$B¡Llevadla adentro y atended sus heridas!$B$B<Taleris se vuelve hacia ti.>$B$BTiene suerte de que la encontraras cuando lo hiciste, $c. No creo que hubiera durado mucho más ahí fuera.$B$B¿Entiendes lo que estaba diciendo?', 0);
-- 9376 Una peregrina afligida
-- https://es.wowhead.com/quest=9376
SET @ID := 9376;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las cosas no van bien. A este paso, no conseguirá volver al camino. ¿Has conseguido encontrar esa talega?', 0),
(@ID, 'esMX', 'Las cosas no van bien. A este paso, no conseguirá volver al camino. ¿Has conseguido encontrar esa talega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por recuperar esto, $n. No tengo muy claro qué significa para la peregrina herida pero se niega a dejar que nadie se le acerque hasta tenerlo de nuevo en sus manos.', 0),
(@ID, 'esMX', 'Gracias por recuperar esto, $n. No tengo muy claro qué significa para la peregrina herida pero se niega a dejar que nadie se le acerque hasta tenerlo de nuevo en sus manos.', 0);
-- 9381 Esas flechas sí que vuelan
-- https://es.wowhead.com/quest=9381
SET @ID := 9381;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste recolectar todas las plumas?', 0),
(@ID, 'esMX', '¿Pudiste recolectar todas las plumas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deberían servir. Me preocupaba que les faltaran flechas a los forestales pero ahora es una preocupación menos. Gracias por tu ayuda, $c.', 0),
(@ID, 'esMX', 'Deberían servir. Me preocupaba que les faltaran flechas a los forestales pero ahora es una preocupación menos. Gracias por tu ayuda, $c.', 0);
-- 9383 Un plan ambicioso
-- https://es.wowhead.com/quest=9383
SET @ID := 9383;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Usaste la magia del cristal contra un abisario sin control?', 0),
(@ID, 'esMX', '¿Usaste la magia del cristal contra un abisario sin control?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Parece que el cristal aguanta de momento, aunque no podemos saber cuánto durará. Lo tendremos en observación y mientras tanto prepararemos más cristales.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Parece que el cristal aguanta de momento, aunque no podemos saber cuánto durará. Lo tendremos en observación y mientras tanto prepararemos más cristales.', 0);
-- 9385 Devastadores descontrolados
-- https://es.wowhead.com/quest=9385
SET @ID := 9385;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho algún progreso contra los devastadores?', 0),
(@ID, 'esMX', '¿Has hecho algún progreso contra los devastadores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. ¡Ahora esas bestias saben quién manda aquí!', 0),
(@ID, 'esMX', 'Buen trabajo, $n. ¡Ahora esas bestias saben quién manda aquí!', 0);
-- 9386 Una luz en la oscuridad
-- https://es.classic.wowhead.com/quest=9386
SET @ID := 9386;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has probado que no eres del todo inútil, mortal.', 0),
(@ID, 'esMX', 'Has probado que no eres del todo inútil, mortal.', 0);
-- 9387 El origen de la corrupción
-- https://es.wowhead.com/quest=9387
SET @ID := 9387;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido las muestras?', 0),
(@ID, 'esMX', '¿Has conseguido las muestras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has sido de gran ayuda, $n. Ahora veamos qué podemos aprender de nuestro amigo azul.', 0),
(@ID, 'esMX', 'Has sido de gran ayuda, $n. Ahora veamos qué podemos aprender de nuestro amigo azul.', 0);
-- 9388 La oscilación de las llamas de Kalimdor
-- https://es.classic.wowhead.com/quest=9388
SET @ID := 9388;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los fuegos no pueden morir hasta que termine el festival!', 0),
(@ID, 'esMX', '¡Los fuegos no pueden morir hasta que termine el festival!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahhh, todavía arden. Me alegro; no sería bueno que esos fuegos se apagaran antes de tiempo. Lo has hecho bien, $n. Toma esto con mi bendición.', 0),
(@ID, 'esMX', 'Ahhh, todavía arden. Me alegro; no sería bueno que esos fuegos se apagaran antes de tiempo. Lo has hecho bien, $n. Toma esto con mi bendición.', 0);
-- 9389 La oscilación de las llamas de los Reinos del Este
-- https://es.classic.wowhead.com/quest=9389
SET @ID := 9389;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has cumplido tu tarea?', 0),
(@ID, 'esMX', '¿Has cumplido tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te han parecido las hogueras esmeralda? Son una visión magnífica, aunque seguro que esperas una recompensa más tangible; aquí tienes.', 0),
(@ID, 'esMX', '¿Qué te han parecido las hogueras esmeralda? Son una visión magnífica, aunque seguro que esperas una recompensa más tangible; aquí tienes.', 0);
-- 9390 En busca de Sedai
-- https://es.wowhead.com/quest=9390
SET @ID := 9390;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hallado el cuerpo de un joven paladín draenei. Todo indica que lo han matado por la espalda.', 0),
(@ID, 'esMX', 'Has hallado el cuerpo de un joven paladín draenei. Todo indica que lo han matado por la espalda.', 0);
-- 9391 Iluminar el camino
-- https://es.wowhead.com/quest=9391
SET @ID := 9391;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho lo que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has hecho lo que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Gran Fisura, aunque sigue siendo peligrosa, será una ruta válida para nuestros peregrinos.$B$BCon la Alianza vigilando todas la carreteras que entran y salen de la Avanzada del Halcón, este es el tipo de acto desesperado que se nos exige.', 0),
(@ID, 'esMX', 'La Gran Fisura, aunque sigue siendo peligrosa, será una ruta válida para nuestros peregrinos.$B$BCon la Alianza vigilando todas la carreteras que entran y salen de la Avanzada del Halcón, este es el tipo de acto desesperado que se nos exige.', 0);
-- 9392 Entrenamiento de pícaros
-- https://es.wowhead.com/quest=9392
SET @ID := 9392;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Escuché tu nombre susurrado desde las sombras, $n. Se dice que estás buscando a alguien con experiencia que te enseñe cómo hacerlo, alguien como yo. Puedo hacer eso, pero te costará una pequeña parte de tu dinero cada vez que tenga algo que enseñarte. Entonces sí, te entrenaré en lo que significa ser $gun pícaro:una pícara;.$B$BPero recuerda, si alguna vez te atrapan robando algo, esta conversación nunca tuvo lugar. ¡Ahora sal y muéstrame de qué estás $ghecho:hecha;!', 0),
(@ID, 'esMX', 'Escuché tu nombre susurrado desde las sombras, $n. Se dice que estás buscando a alguien con experiencia que te enseñe cómo hacerlo, alguien como yo. Puedo hacer eso, pero te costará una pequeña parte de tu dinero cada vez que tenga algo que enseñarte. Entonces sí, te entrenaré en lo que significa ser $gun pícaro:una pícara;.$B$BPero recuerda, si alguna vez te atrapan robando algo, esta conversación nunca tuvo lugar. ¡Ahora sal y muéstrame de qué estás $ghecho:hecha;!', 0);
-- 9393 Instrucción de cazador
-- https://es.wowhead.com/quest=9393
SET @ID := 9393;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tus ojos son agudos como los de un halcón, tus movimientos tan fluidos como los de un mono o tu velocidad la de un guepardo? Los míos lo son, y los tuyos también pueden serlo con el entrenamiento adecuado. El camino del cazador es de dominio sobre las bestias del mundo, una precisión incomparable en la puntería y el conocimiento de cómo sobrevivir en situaciones en las que otros perecerían.$B$BSi estas son las cosas que buscas aprender, entonces te entrenaré, por una pequeña tarifa, por supuesto. ¿Deberíamos empezar?', 0),
(@ID, 'esMX', '$n, ¿tus ojos son agudos como los de un halcón, tus movimientos tan fluidos como los de un mono o tu velocidad la de un guepardo? Los míos lo son, y los tuyos también pueden serlo con el entrenamiento adecuado. El camino del cazador es de dominio sobre las bestias del mundo, una precisión incomparable en la puntería y el conocimiento de cómo sobrevivir en situaciones en las que otros perecerían.$B$BSi estas son las cosas que buscas aprender, entonces te entrenaré, por una pequeña tarifa, por supuesto. ¿Deberíamos empezar?', 0);
-- 9396 La magia de los arakkoa
-- https://es.wowhead.com/quest=9396
SET @ID := 9396;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido ya los pergaminos, $n?', 0),
(@ID, 'esMX', '¿Has conseguido ya los pergaminos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Los secretos de Terrallende no seguirán ocultos por mucho tiempo.$B$BEs nuestro destino convertirnos en los amos de este universo.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Los secretos de Terrallende no seguirán ocultos por mucho tiempo.$B$BEs nuestro destino convertirnos en los amos de este universo.', 0);
-- 9397 En compañía de pájaros
-- https://es.wowhead.com/quest=9397
SET @ID := 9397;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado. ¿Me has traído la hembra kaliri?', 0),
(@ID, 'esMX', 'Has regresado. ¿Me has traído la hembra kaliri?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! ¡Has atrapado una prole hembra!$B$BEs preciosa. Te doy las gracias, $n.', 0),
(@ID, 'esMX', '¡Lo has conseguido! ¡Has atrapado una prole hembra!$B$BEs preciosa. Te doy las gracias, $n.', 0);
-- 9398 Depredadores letales
-- https://es.wowhead.com/quest=9398
SET @ID := 9398;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has completado la tarea que te pedí?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has completado la tarea que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un buen trabajo, $n. Siempre es una lástima tener que arrebatar una vida, aunque sea la de una peligrosa criatura como los despellejadores de roca.$B$BCuentas con mi gratitud por despachar esta cruda tarea.', 0),
(@ID, 'esMX', 'Has hecho un buen trabajo, $n. Siempre es una lástima tener que arrebatar una vida, aunque sea la de una peligrosa criatura como los despellejadores de roca.$B$BCuentas con mi gratitud por despachar esta cruda tarea.', 0);
-- 9399 Capataces crueles
-- https://es.wowhead.com/quest=9399
SET @ID := 9399;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto! ¿Completaste tu tarea?', 0),
(@ID, 'esMX', '¡Has vuelto! ¿Completaste tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Estoy en deuda contigo, $n. Mira todos los Zarrapucha que hay por aquí.$B$BConmigo lo aprenderán todo sobre la antigua sabiduría, ya verás.', 0),
(@ID, 'esMX', '¡Excelente! Estoy en deuda contigo, $n. Mira todos los Zarrapucha que hay por aquí.$B$BConmigo lo aprenderán todo sobre la antigua sabiduría, ya verás.', 0);
-- 9400 El asesino
-- https://es.wowhead.com/quest=9400
SET @ID := 9400;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cadáver coincide con la descripción de Krun Rompeloma, el asesino de la Ciudadela del Fuego Infernal. Al darle la vuelta al cuerpo, descubres un hacha de piedra clavada en su espalda.', 0),
(@ID, 'esMX', 'El cadáver coincide con la descripción de Krun Rompeloma, el asesino de la Ciudadela del Fuego Infernal. Al darle la vuelta al cuerpo, descubres un hacha de piedra clavada en su espalda.', 0);
-- 9401 Un arma inusual
-- https://es.wowhead.com/quest=9401
SET @ID := 9401;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, ¿ha muerto el asesino?', 0),
(@ID, 'esMX', 'Dime, ¿ha muerto el asesino?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo mataron con esta arma? ¡No puede ser!$B$B¿Los hemos... encontrado?', 0),
(@ID, 'esMX', '¿Lo mataron con esta arma? ¡No puede ser!$B$B¿Los hemos... encontrado?', 0);
-- 9402 ¡Tráeme una cosita!
-- https://es.wowhead.com/quest=9402
SET @ID := 9402;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo está el agua?', 0),
(@ID, 'esMX', '¿Cómo está el agua?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien... Te dije que saltaras en un charco y lo hiciste. Solo puedo imaginar lo que harías si un buen amigo tuyo te lo pidiera.$B$BSi quieres una recompensa por tus esfuerzos, ahí va: nunca levantes un dedo sin saber qué te llevas. La mente de $gun:una; $c es su arma más poderosa. No lo olvides e intenta usar la tuya un poco más.', 0),
(@ID, 'esMX', 'Muy bien... Te dije que saltaras en un charco y lo hiciste. Solo puedo imaginar lo que harías si un buen amigo tuyo te lo pidiera.$B$BSi quieres una recompensa por tus esfuerzos, ahí va: nunca levantes un dedo sin saber qué te llevas. La mente de $gun:una; $c es su arma más poderosa. No lo olvides e intenta usar la tuya un poco más.', 0);
-- 9403 El agua más pura
-- https://es.wowhead.com/quest=9403
SET @ID := 9403;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo el agua de las Cascadas Elrendar tiene la pureza necesaria para usarla con la magia. ¿La tienes?', 0),
(@ID, 'esMX', 'Solo el agua de las Cascadas Elrendar tiene la pureza necesaria para usarla con la magia. ¿La tienes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A ver qué me has traído...$B$B<Acerca la ampolla a la luz y la examina atentamente.>$B$BSí, servirá. Muy bien, $n.', 0),
(@ID, 'esMX', 'A ver qué me has traído...$B$B<Acerca la ampolla a la luz y la examina atentamente.>$B$BSí, servirá. Muy bien, $n.', 0);
-- 9404 Recientemente vivo
-- https://es.wowhead.com/quest=9404
SET @ID := 9404;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la rama viva? ¡Dámela, rápido!', 0),
(@ID, 'esMX', '¿Tienes la rama viva? ¡Dámela, rápido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho lo que te pedí, $n, y puedes recibir tu recompensa ahora.', 0),
(@ID, 'esMX', 'Has hecho lo que te pedí, $n, y puedes recibir tu recompensa ahora.', 0);
-- 9405 El mandato del Jefe de Guerra
-- https://es.wowhead.com/quest=9405
SET @ID := 9405;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime lo que buscas para que te pueda ayudar a encontrarlo.', 0),
(@ID, 'esMX', 'Dime lo que buscas para que te pueda ayudar a encontrarlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No digas más, $c. Entiendo la petición de Nazgrel.', 0),
(@ID, 'esMX', 'No digas más, $c. Entiendo la petición de Nazgrel.', 0);
-- 9406 Los Mag'har
-- https://es.wowhead.com/quest=9406
SET @ID := 9406;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué nos traes, $n?', 0),
(@ID, 'esMX', '¿Qué nos traes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás $gseguro:segura;? Esto es muy importante, $n. ¡Esos orcos serán de gran ayuda para nuestra causa tanto aquí como en nuestro hogar!', 0),
(@ID, 'esMX', '¿Estás $gseguro:segura;? Esto es muy importante, $n. ¡Esos orcos serán de gran ayuda para nuestra causa tanto aquí como en nuestro hogar!', 0);
-- 9407 A través de El Portal Oscuro
-- https://es.wowhead.com/quest=9407
SET @ID := 9407;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestra Expedición atravesó el Portal de manera segura y estableció una nueva base llamada Thrallmar. Sin embargo, como puedes ver. la Legión Ardiente nos separó de nuestros hermanos. Claramente, los demonios esperan recuperar el Portal Oscuro y evitar que lleguen refuerzos de Azeroth.', 0),
(@ID, 'esMX', 'Nuestra Expedición atravesó el Portal de manera segura y estableció una nueva base llamada Thrallmar. Sin embargo, como puedes ver. la Legión Ardiente nos separó de nuestros hermanos. Claramente, los demonios esperan recuperar el Portal Oscuro y evitar que lleguen refuerzos de Azeroth.', 0);
-- 9409 Entrega urgente
-- https://es.wowhead.com/quest=9409
SET @ID := 9409;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Traes algo para mí?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Traes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Con esto podremos reponer los cristales de sanación.$B$BYa que estás aquí, tengo otra tarea para ti. ¿Quieres encargarte?', 0),
(@ID, 'esMX', '¡Buen trabajo! Con esto podremos reponer los cristales de sanación.$B$BYa que estás aquí, tengo otra tarea para ti. ¿Quieres encargarte?', 0);
-- 9410 Un espíritu guía
-- https://es.wowhead.com/quest=9410
SET @ID := 9410;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes suerte de estar $gvivo:viva;.', 0),
(@ID, 'esMX', 'Tienes suerte de estar $gvivo:viva;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién eres tú para entrar aquí sin que te anuncien? Ordené a mis hombres que no se movieran solo porque Ryga sintió que los espíritus estaban contigo.$B$BHabla con total libertad pero elige tus palabras con prudencia. En raras ocasiones confiamos en los forasteros tan cerca de la ciudadela.', 0),
(@ID, 'esMX', '¿Quién eres tú para entrar aquí sin que te anuncien? Ordené a mis hombres que no se movieran solo porque Ryga sintió que los espíritus estaban contigo.$B$BHabla con total libertad pero elige tus palabras con prudencia. En raras ocasiones confiamos en los forasteros tan cerca de la ciudadela.', 0);
-- 9415 Preséntate ante el alguacil Murazul
-- https://es.classic.wowhead.com/quest=9415
SET @ID := 9415;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Alianza necesita todos las manos capaces que pueda conseguir. La Horda ha estado recibiendo un suministro constante de refuerzos de la parte norte del continente, y ha sido una lucha mantener el ritmo.$B$BDéjame explicarte la situación.', 0),
(@ID, 'esMX', 'La Alianza necesita todos las manos capaces que pueda conseguir. La Horda ha estado recibiendo un suministro constante de refuerzos de la parte norte del continente, y ha sido una lucha mantener el ritmo.$B$BDéjame explicarte la situación.', 0);
