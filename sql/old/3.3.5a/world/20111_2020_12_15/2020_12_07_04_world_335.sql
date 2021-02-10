-- 467 La búsqueda de los Roscapiedra
-- https://es.classic.wowhead.com/quest=467
SET @ID := 467;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n, ¿vienes por el trabajito? ¡Me alegro de ver que aún hay gente que se emociona con la idea de una aventura!', 0),
(@ID, 'esMX', 'Hola, $n, ¿vienes por el trabajito? ¡Me alegro de ver que aún hay gente que se emociona con la idea de una aventura!', 0);
-- 477 Pasa la frontera
-- https://es.classic.wowhead.com/quest=477
SET @ID := 477;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Al destapar la caja, encuentras una selección de objetos cuidadosamente empaquetados. En la parte de arriba de la caja hay unos mapas amarillentos por el paso del tiempo, que parecen describir el Bosque de Argénteos y otras partes del oeste de Lordaeron.$B$BBajo los mapas hay un colgante de aspecto misterioso.>', 0),
(@ID, 'esMX', '<Al destapar la caja, encuentras una selección de objetos cuidadosamente empaquetados. En la parte de arriba de la caja hay unos mapas amarillentos por el paso del tiempo, que parecen describir el Bosque de Argénteos y otras partes del oeste de Lordaeron.$B$BBajo los mapas hay un colgante de aspecto misterioso.>', 0);
-- 478 Mapas y runas
-- https://es.classic.wowhead.com/quest=478
SET @ID := 478;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has aprendido algo útil, $n?', 0),
(@ID, 'esMX', '¿Has aprendido algo útil, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mapas y este... colgante, ¿mmm? Interesante.$B$BEs obvio que los zahoríes de Dalaran están interesados en Molino Ámbar por alguna razón, pero aun así, no llego a entender el motivo.$B$BQuizás Dalar sepa algo.', 0),
(@ID, 'esMX', 'Mapas y este... colgante, ¿mmm? Interesante.$B$BEs obvio que los zahoríes de Dalaran están interesados en Molino Ámbar por alguna razón, pero aun así, no llego a entender el motivo.$B$BQuizás Dalar sepa algo.', 0);
-- 479 Las investigaciones de Molino Ámbar
-- https://es.classic.wowhead.com/quest=479
SET @ID := 479;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos darnos prisa, no podemos permitir que lleven a cabo su plan, o podríamos perder nuestra posición en el Bosque de Argénteos.', 0),
(@ID, 'esMX', 'Debemos darnos prisa, no podemos permitir que lleven a cabo su plan, o podríamos perder nuestra posición en el Bosque de Argénteos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dalar ha descubierto que han avanzado bastante a pesar del revés.$B$BTienen a un zahorí de gran poder guiando la energía mágica. Tenemos que detenerle rápidamente.', 0),
(@ID, 'esMX', 'Dalar ha descubierto que han avanzado bastante a pesar del revés.$B$BTienen a un zahorí de gran poder guiando la energía mágica. Tenemos que detenerle rápidamente.', 0);
-- 480 El Tejedor
-- https://es.classic.wowhead.com/quest=480
SET @ID := 480;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Rápido, nos quedamos sin tiempo, $n!', 0),
(@ID, 'esMX', '¡Rápido, nos quedamos sin tiempo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La magia de los zahoríes se disipa y las energías Ley entran en letargo. Tus esfuerzos han dado fruto, $n, y hemos causado un duro golpe a nuestros enemigos y a los dominantes zahoríes de Dalaran.$B$BSin embargo, debemos ser vigilantes ya que sabemos que la fuente de la energía está tan cerca... Tenemos que hacer planes para el futuro.', 0),
(@ID, 'esMX', 'La magia de los zahoríes se disipa y las energías Ley entran en letargo. Tus esfuerzos han dado fruto, $n, y hemos causado un duro golpe a nuestros enemigos y a los dominantes zahoríes de Dalaran.$B$BSin embargo, debemos ser vigilantes ya que sabemos que la fuente de la energía está tan cerca... Tenemos que hacer planes para el futuro.', 0);
-- 481 El análisis de Dalar
-- https://es.classic.wowhead.com/quest=481
SET @ID := 481;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $c? ¿Qué quieres?', 0),
(@ID, 'esMX', '¿Sí, $c? ¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interesante, parece que se trata de más maquinaciones del Kirin Tor. Se trata de un poderoso artefacto. Los poderosos zahoríes del Kirin Tor lo utilizaban frecuentemente para canalizar las energías mágicas.$B$BQue estén enviando tantos a Molino Ámbar indica que deben de estar preparando un proyecto de gran magnitud.$B$BA ver si consigo atravesar sus escudos y frustrar su intento...', 0),
(@ID, 'esMX', 'Interesante, parece que se trata de más maquinaciones del Kirin Tor. Se trata de un poderoso artefacto. Los poderosos zahoríes del Kirin Tor lo utilizaban frecuentemente para canalizar las energías mágicas.$B$BQue estén enviando tantos a Molino Ámbar indica que deben de estar preparando un proyecto de gran magnitud.$B$BA ver si consigo atravesar sus escudos y frustrar su intento...', 0);
-- 482 Las intenciones de los Dalaran
-- https://es.classic.wowhead.com/quest=482
SET @ID := 482;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Traes nefastas noticias, $n. Si Dalar tiene razón, y no me cabe duda de que así es, debemos movernos rápidamente.$B$BTengo que decidir con él nuestro plan de ataque. Pero, mientras tanto, tendremos que retrasar su avance.', 0),
(@ID, 'esMX', 'Traes nefastas noticias, $n. Si Dalar tiene razón, y no me cabe duda de que así es, debemos movernos rápidamente.$B$BTengo que decidir con él nuestro plan de ataque. Pero, mientras tanto, tendremos que retrasar su avance.', 0);
-- 485 ¡Encuentra a OOX-09/TI!
-- https://es.classic.wowhead.com/quest=485
SET @ID := 485;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0),
(@ID, 'esMX', 'Parece que has descubierto los restos de... ¿un pollo robótico? La voz que proviene del huevo vuelve de nuevo a la vida:$B$B"¡Sí, un trabajo excelente! Este es sin duda mi robot mensajero, aunque mis sensores indican que necesita un empujón para que pueda volar de regreso a Bahía del Botín para ser reparado. Coloca el localizador en el interior del robot. ¡El localizador hará todo lo demás!"', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el huevo... localizador de emergencia... dentro del pollo... el robot mensajero.$B$BDentro se oyen zumbidos y chirridos. Cuando el robot es revivido, se vuelve a oír la voz de Oglethorpe una vez más, pero ahora, viene de dentro del robot:$B$B"OOX-09/TI funciona, pero necesita reparaciones. Es demasiado pesado para llevarlo, pero tengo una idea. ¿Puedes vigilarlo un rato más?"', 0),
(@ID, 'esMX', 'Colocas el huevo... localizador de emergencia... dentro del pollo... el robot mensajero.$B$BDentro se oyen zumbidos y chirridos. Cuando el robot es revivido, se vuelve a oír la voz de Oglethorpe una vez más, pero ahora, viene de dentro del robot:$B$B"OOX-09/TI funciona, pero necesita reparaciones. Es demasiado pesado para llevarlo, pero tengo una idea. ¿Puedes vigilarlo un rato más?"', 0);
-- 491 Una varita para Bethor
-- https://es.classic.wowhead.com/quest=491
SET @ID := 491;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has derrotado a Thule Corvozarpa?', 0),
(@ID, 'esMX', '$n, ¿has derrotado a Thule Corvozarpa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¿Thule tenía nuestra varita tejida? Creí que la había perdido cuando nuestra amistad se destruyó y se alió con el rey Exánime.$B$BNo ha invocado su poder porque, si lo hubiera hecho, yo lo habría sentido. Y me alegro de que no la haya usado...$B$BEs un descubrimiento maravilloso. Tienes mi gratitud, $n, y recibirás una recompensa.', 0),
(@ID, 'esMX', '¿Qué es esto? ¿Thule tenía nuestra varita tejida? Creí que la había perdido cuando nuestra amistad se destruyó y se alió con el rey Exánime.$B$BNo ha invocado su poder porque, si lo hubiera hecho, yo lo habría sentido. Y me alegro de que no la haya usado...$B$BEs un descubrimiento maravilloso. Tienes mi gratitud, $n, y recibirás una recompensa.', 0);
-- 492 Una nueva Peste
-- https://es.classic.wowhead.com/quest=492
SET @ID := 492;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si tuviera mi rifle acabaría contigo, $c. ¡Espera a que la Brigada de los tanques de vapor me saque de aquí!', 0),
(@ID, 'esMX', 'Si tuviera mi rifle acabaría contigo, $c. ¡Espera a que la Brigada de los tanques de vapor me saque de aquí!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, por fin algo que beber! Estoy seguro de que no es malta rapsódica pero en este momento mojaría el gaznate con cualquier cosa.', 0),
(@ID, 'esMX', '¡Ah, por fin algo que beber! Estoy seguro de que no es malta rapsódica pero en este momento mojaría el gaznate con cualquier cosa.', 0);
-- 493 Viaja a Laderas de Trabalomas
-- https://es.classic.wowhead.com/quest=493
SET @ID := 493;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, excelente! El boticario Renferrel se merece todo mi respeto. Me muero por estudiar su obra.', 0),
(@ID, 'esMX', '¡Excelente, excelente! El boticario Renferrel se merece todo mi respeto. Me muero por estudiar su obra.', 0);
-- 494 El momento de atacar
-- https://es.classic.wowhead.com/quest=494
SET @ID := 494;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Desde el oeste nos llega el llanto del cuervo."$B$B¡Qué noticia tan excelente! Todo está a punto para arrasar Trabalomas. Esto complacerá a Varimathras.', 0),
(@ID, 'esMX', '"Desde el oeste nos llega el llanto del cuervo."$B$B¡Qué noticia tan excelente! Todo está a punto para arrasar Trabalomas. Esto complacerá a Varimathras.', 0);
-- 495 Corona de Voluntad
-- https://es.classic.wowhead.com/quest=495
SET @ID := 495;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Shalindra? Muy bien, pues vayamos al grano.$B$BMug\'Thol es un estorbo así que debemos ocuparnos de él sin perder ni un segundo.', 0),
(@ID, 'esMX', '¿Te envía Shalindra? Muy bien, pues vayamos al grano.$B$BMug\'Thol es un estorbo así que debemos ocuparnos de él sin perder ni un segundo.', 0);
-- 496 Elixir de sufrimiento
-- https://es.classic.wowhead.com/quest=496
SET @ID := 496;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ya estás aquí. Espero que traigas los ingredientes; me deprimo si paso más de un día sin matar nada.', 0),
(@ID, 'esMX', 'Ah, ya estás aquí. Espero que traigas los ingredientes; me deprimo si paso más de un día sin matar nada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, perfecto. Gracias por arrojar un tenue rayo de alegría a otro día sombrío.', 0),
(@ID, 'esMX', 'Muy bien, perfecto. Gracias por arrojar un tenue rayo de alegría a otro día sombrío.', 0);
-- 1000 La nueva frontera
-- https://es.classic.wowhead.com/quest=1000
SET @ID := 1000;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0),
(@ID, 'esMX', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0);
-- 990 El camino de Vallefresno
-- https://es.classic.wowhead.com/quest=990
SET @ID := 990;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $gun:una; $c de Costa Oscura. Selarin ha hecho bien en enviarte tan rápidamente, $n. Ojalá tu viaje aquí no se debiera a tan funesta urgencia. Quizás con tu ayuda logremos mejorar la situación.$B$BEmpezaría mi visita hablando con otros ciudadanos de Astranaar. Seguro que alguno te puede ayudar.', 0),
(@ID, 'esMX', 'Ah, $gun:una; $c de Costa Oscura. Selarin ha hecho bien en enviarte tan rápidamente, $n. Ojalá tu viaje aquí no se debiera a tan funesta urgencia. Quizás con tu ayuda logremos mejorar la situación.$B$BEmpezaría mi visita hablando con otros ciudadanos de Astranaar. Seguro que alguno te puede ayudar.', 0);
-- 1004 La nueva frontera
-- https://es.classic.wowhead.com/quest=1004
SET @ID := 1004;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0),
(@ID, 'esMX', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas por lo que eres bien $grecibido:recibida; aquí. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra relación con el Círculo Cenarion en el Claro de la Luna trasciende la barrera racial y política; no lo olvides nunca.', 0);
-- 1011 Los males de los Renegados
-- https://es.classic.wowhead.com/quest=1011
SET @ID := 1011;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el campamento, $n? ¿Tienes una botella de enfermedad?', 0),
(@ID, 'esMX', '¿Encontraste el campamento, $n? ¿Tienes una botella de enfermedad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Ahora... probando el contenido de esta botella, ¡se revelarán los objetivos de los Renegados!', 0),
(@ID, 'esMX', 'Muy bien, $n. Ahora... probando el contenido de esta botella, ¡se revelarán los objetivos de los Renegados!', 0);
-- 1012 Druidas dementes
-- https://es.classic.wowhead.com/quest=1012
SET @ID := 1012;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La angustia de los druidas Dor\'danil todavía acecha mis sueños, $n. ¡Debes destruir a sus líderes!', 0),
(@ID, 'esMX', 'La angustia de los druidas Dor\'danil todavía acecha mis sueños, $n. ¡Debes destruir a sus líderes!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sentí que la angustia del Túmulo de Dor\'danil disminuía y supe que habías completado tu tarea.$B$BHas hecho un macabro trabajo, $n, ya que los espíritus que has tenido que destruir eran meras víctimas de la perversión de los Renegados. Pero con su destrucción, esperemos que otros espíritus enloquecidos encuentren el descanso.', 0),
(@ID, 'esMX', 'Sentí que la angustia del Túmulo de Dor\'danil disminuía y supe que habías completado tu tarea.$B$BHas hecho un macabro trabajo, $n, ya que los espíritus que has tenido que destruir eran meras víctimas de la perversión de los Renegados. Pero con su destrucción, esperemos que otros espíritus enloquecidos encuentren el descanso.', 0);
-- 1013 El Libro de Ur
-- https://es.classic.wowhead.com/quest=1013
SET @ID := 1013;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el libro?', 0),
(@ID, 'esMX', '¿Encontraste el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto; esto completa mi colección de obras de Ur. Era sabio, pero su conciencia lo mantenía alejado del poder verdadero. Así, cuando la Plaga lo puso a prueba, falló.$B$BLos Renegados no podemos permitirnos tal debilidad.$B$BNo si queremos vencer.', 0),
(@ID, 'esMX', 'Perfecto; esto completa mi colección de obras de Ur. Era sabio, pero su conciencia lo mantenía alejado del poder verdadero. Así, cuando la Plaga lo puso a prueba, falló.$B$BLos Renegados no podemos permitirnos tal debilidad.$B$BNo si queremos vencer.', 0);
-- 1014 Arugal debe morir
-- https://es.classic.wowhead.com/quest=1014
SET @ID := 1014;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la muerte de Arugal, podemos aumentar el bastión de la Dama Oscura en Lordaeron.', 0),
(@ID, 'esMX', 'Con la muerte de Arugal, podemos aumentar el bastión de la Dama Oscura en Lordaeron.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin el Bosque de Argénteos está libre del vicio de ese malvado Arugal. Has hecho un gran servicio a la Dama Oscura, $n. Tu tenacidad será recompensada.', 0),
(@ID, 'esMX', 'Por fin el Bosque de Argénteos está libre del vicio de ese malvado Arugal. Has hecho un gran servicio a la Dama Oscura, $n. Tu tenacidad será recompensada.', 0);
-- 1015 La nueva frontera
-- https://es.classic.wowhead.com/quest=1015
SET @ID := 1015;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0),
(@ID, 'esMX', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0);
-- 1018 La nueva frontera
-- https://es.classic.wowhead.com/quest=1018
SET @ID := 1018;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas; te doy la bienvenida. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra conexión con el Círculo en Claro de la Luna trasciende las barreras raciales y políticas; no lo olvides nunca.', 0),
(@ID, 'esMX', 'Saludos, $c.$B$BMe alegra ver que alguien como tú se preocupa por el bienestar de la naturaleza. He oído hablar de tus hazañas; te doy la bienvenida. Al mirarte tengo la certeza de que el Círculo Cenarion recibirá la ayuda que necesita.$B$BNuestra conexión con el Círculo en Claro de la Luna trasciende las barreras raciales y políticas; no lo olvides nunca.', 0);
-- 1019 La nueva frontera
-- https://es.classic.wowhead.com/quest=1019
SET @ID := 1019;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0),
(@ID, 'esMX', '¿Qué te hace pensar que deseo que alguien como tú venga a molestarme, $c? Ahora mismo voy a abandonar tooodos esos insignificantísimos quehaceres para ayudarte a localizar el chisme que estás buscando. Sea como sea, el bienestar de todo Darnassus, no, de todo Teldrassil, debería estar en segundo lugar. Lo más importante es conseguir un adorno para tu colección.$B$BEsos imbéciles del Claro de la Luna me hacen perder el tiempo con sus llamaditas de ayuda, ¿y ahora tengo que aguantar esto?', 0);
