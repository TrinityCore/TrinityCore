-- 8327 Informar a Lanthan Perilon
-- https://es.classic.wowhead.com/quest=8327
SET @ID := 8327;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La magistrix Erona me dijo que llegarías pronto, $n. Ese edificio flotante con agujas ornamentadas, al oeste, es la Academia Falthrien. Tú dirigirás las operaciones para recuperarla de manos de uno de los desdichados, un $r que siempre ha sucumbido a sus más bajos instintos.$B$BEspero que vengas con ganas de trabajar. Esto no va a ser solo una lección sobre el peligro, sino sobre lo que pasa cuando olvidas quién eres.', 0),
(@ID, 'esMX', 'La magistrix Erona me dijo que llegarías pronto, $n. Ese edificio flotante con agujas ornamentadas, al oeste, es la Academia Falthrien. Tú dirigirás las operaciones para recuperarla de manos de uno de los desdichados, un $r que siempre ha sucumbido a sus más bajos instintos.$B$BEspero que vengas con ganas de trabajar. Esto no va a ser solo una lección sobre el peligro, sino sobre lo que pasa cuando olvidas quién eres.', 0);
-- 397 Nos has hecho un gran servicio
-- https://es.classic.wowhead.com/quest=397
SET @ID := 397;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maestro dice dar regalo a $n. Zggi querer quedarse con bonito regalo, pero Zggi no ser tan tonto para traicionar al maestro.', 0),
(@ID, 'esMX', 'Maestro dice dar regalo a $n. Zggi querer quedarse con bonito regalo, pero Zggi no ser tan tonto para traicionar al maestro.', 0);
-- 398 Se busca: Ojo de cresa
-- https://es.classic.wowhead.com/quest=398
SET @ID := 398;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin los ruines actos de Ojo de gusano han encontrado su venganza. Esperemos que este acto de valentía por tu parte sea un mensaje claro para aquellos que desean traer el sufrimiento a nuestro pueblo. En nombre de la ciudad de Rémol te doy las gracias, $n.', 0),
(@ID, 'esMX', 'Por fin los ruines actos de Ojo de gusano han encontrado su venganza. Esperemos que este acto de valentía por tu parte sea un mensaje claro para aquellos que desean traer el sufrimiento a nuestro pueblo. En nombre de la ciudad de Rémol te doy las gracias, $n.', 0);
-- 404 Una tarea pútrida
-- https://es.classic.wowhead.com/quest=404
SET @ID := 404;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has acabado lo que te encomendé? ¿Ya tienes las garras pútridas?', 0),
(@ID, 'esMX', '¿Has acabado lo que te encomendé? ¿Ya tienes las garras pútridas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. ¡Cómo me hubiera gustado presenciar el fin de esos no-muertos!', 0),
(@ID, 'esMX', 'Bien hecho. ¡Cómo me hubiera gustado presenciar el fin de esos no-muertos!', 0);
-- 405 El exánime pródigo
-- https://es.classic.wowhead.com/quest=405
SET @ID := 405;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. O no sabes quién soy o tienes algo urgente que tratar conmigo.$B$BEn caso de que ninguno de estos dos supuestos te atañan, desearás no haberme molestado.', 0),
(@ID, 'esMX', 'Saludos. O no sabes quién soy o tienes algo urgente que tratar conmigo.$B$BEn caso de que ninguno de estos dos supuestos te atañan, desearás no haberme molestado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, si te envía el magistrado Sevren entonces tengo una tarea de suma importancia que confiarte.$B$BEspero que estés a la altura... aunque eso ya se verá.', 0),
(@ID, 'esMX', 'Ah, si te envía el magistrado Sevren entonces tengo una tarea de suma importancia que confiarte.$B$BEspero que estés a la altura... aunque eso ya se verá.', 0);
-- 407 Campos de pena
-- https://es.classic.wowhead.com/quest=407
SET @ID := 407;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te acerques a mí, inmunda e impura criatura! ¡Que la Luz me proteja! La Cruzada Escarlata te expulsará de Azeroth y... .$B$B... espera. ¿Me traes comida? Tengo tanta hambre…', 0),
(@ID, 'esMX', '¡No te acerques a mí, inmunda e impura criatura! ¡Que la Luz me proteja! La Cruzada Escarlata te expulsará de Azeroth y... .$B$B... espera. ¿Me traes comida? Tengo tanta hambre…', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por la Luz! ¡Al fin algo de comida! Dulce, dulce calabaza…', 0),
(@ID, 'esMX', '¡Por la Luz! ¡Al fin algo de comida! Dulce, dulce calabaza…', 0);
-- 408 La Cripta de la Familia
-- https://es.classic.wowhead.com/quest=408
SET @ID := 408;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo corre en nuestra contra, $n. Cada hora que pasa, la Plaga afianza su posición en los Claros de Tirisfal.', 0),
(@ID, 'esMX', 'El tiempo corre en nuestra contra, $n. Cada hora que pasa, la Plaga afianza su posición en los Claros de Tirisfal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con tus acciones has asestado un duro golpe a la Plaga. Tu victoria no pasará inadvertida, ni para los Renegados ni para nuestros enemigos.$B$BSigue luchando como nosotros y quizás algún día consigamos expulsar al mismísimo rey Exánime de Azeroth.', 0),
(@ID, 'esMX', 'Con tus acciones has asestado un duro golpe a la Plaga. Tu victoria no pasará inadvertida, ni para los Renegados ni para nuestros enemigos.$B$BSigue luchando como nosotros y quizás algún día consigamos expulsar al mismísimo rey Exánime de Azeroth.', 0);
-- 409 Prueba de lealtad
-- https://es.classic.wowhead.com/quest=409
SET @ID := 409;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero una prueba de tu lealtad, $c.', 0),
(@ID, 'esMX', 'Espero una prueba de tu lealtad, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has derrotado a Lillith Nefara, lo que demuestra que eres $genemigo:enemiga; de la Plaga. Es increíble.$B$BHubiera jurado que era el único no-muerto con voluntad propia pero me has demostrado que también hay otros libres de la dominación del rey Exánime.', 0),
(@ID, 'esMX', 'Has derrotado a Lillith Nefara, lo que demuestra que eres $genemigo:enemiga; de la Plaga. Es increíble.$B$BHubiera jurado que era el único no-muerto con voluntad propia pero me has demostrado que también hay otros libres de la dominación del rey Exánime.', 0);
-- 410 Sombra durmiente
-- https://es.classic.wowhead.com/quest=410
SET @ID := 410;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta vieja mesa está hecha polvo.', 0),
(@ID, 'esMX', 'Esta vieja mesa está hecha polvo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas la vela de señalización sobre la mesa y la enciendes...', 0),
(@ID, 'esMX', 'Colocas la vela de señalización sobre la mesa y la enciendes...', 0);
-- 411 El regreso del exánime pródigo
-- https://es.classic.wowhead.com/quest=411
SET @ID := 411;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Le has devuelto a Gunther su libro? ¿Ha reaccionado?', 0),
(@ID, 'esMX', '¿Le has devuelto a Gunther su libro? ¿Ha reaccionado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido que se una a nuestra causa! Has hecho algo estupendo por los Renegados, $n. La Dama Oscura conocerá tu hazaña.', 0),
(@ID, 'esMX', '¡Has conseguido que se una a nuestra causa! Has hecho algo estupendo por los Renegados, $n. La Dama Oscura conocerá tu hazaña.', 0);
-- 415 La nueva bebida de Rejold
-- https://es.classic.wowhead.com/quest=415
SET @ID := 415;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Recuerdas la cerveza de cardaluz que me trajiste? Pues la utilicé en algunas recetas en las que estoy trabajando y una de ellas me salió mejor que genial.$B$BMira, prueba y dime qué opinas.', 0),
(@ID, 'esMX', '¡$n! ¿Recuerdas la cerveza de cardaluz que me trajiste? Pues la utilicé en algunas recetas en las que estoy trabajando y una de ellas me salió mejor que genial.$B$BMira, prueba y dime qué opinas.', 0);
-- 421 Demuestra tu valía
-- https://es.classic.wowhead.com/quest=421
SET @ID := 421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si quieres demostrar tu valía, debes matar a 5 Canosos Furia Lunar. Realiza esta tarea, y me aseguraré de que tu habilidad se use en tareas más valiosas.', 0),
(@ID, 'esMX', 'Si quieres demostrar tu valía, debes matar a 5 Canosos Furia Lunar. Realiza esta tarea, y me aseguraré de que tu habilidad se use en tareas más valiosas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has servido bien, $c. Es obvio que serás de gran ayuda mientras me preparo para liberar el Bosque de Argénteos de la maldición de Arugal.', 0),
(@ID, 'esMX', 'Me has servido bien, $c. Es obvio que serás de gran ayuda mientras me preparo para liberar el Bosque de Argénteos de la maldición de Arugal.', 0);
-- 422 La locura de Arugal
-- https://es.classic.wowhead.com/quest=422
SET @ID := 422;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Antes de saber lo que tenemos entre manos, $c, tengo que estudiar el hechizo conocido como el Remedio de Arugal. Tráemelo ahora, o tendré que buscar a un sirviente digno de hacerlo.', 0),
(@ID, 'esMX', 'Antes de saber lo que tenemos entre manos, $c, tengo que estudiar el hechizo conocido como el Remedio de Arugal. Tráemelo ahora, o tendré que buscar a un sirviente digno de hacerlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Precisamente, este es el hechizo que estaba buscando, $c. Si tu dedicación a la causa de la Dama Oscura permanece infalible, tendrás un futuro entre los Renegados.', 0),
(@ID, 'esMX', 'Precisamente, este es el hechizo que estaba buscando, $c. Si tu dedicación a la causa de la Dama Oscura permanece infalible, tendrás un futuro entre los Renegados.', 0);
-- 423 La locura de Arugal
-- https://es.classic.wowhead.com/quest=423
SET @ID := 423;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré 6 grilletes de glotón y 3 grilletes de almanegra antes de poder evaluar la situación y encontrar una solución para Arugal. Ahora haz lo que tienes que hacer y mata glotones Furia Lunar y almanegras Furia Lunar hasta que tenga todo lo que necesito.', 0),
(@ID, 'esMX', 'Necesitaré 6 grilletes de glotón y 3 grilletes de almanegra antes de poder evaluar la situación y encontrar una solución para Arugal. Ahora haz lo que tienes que hacer y mata glotones Furia Lunar y almanegras Furia Lunar hasta que tenga todo lo que necesito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero poder adquirir suficiente energía de una muestra tan limitada. Quizás tenía que haberte pedido más grilletes.$B$BDe todas formas, has demostrado una gran habilidad para reunir estos, $c.', 0),
(@ID, 'esMX', 'Espero poder adquirir suficiente energía de una muestra tan limitada. Quizás tenía que haberte pedido más grilletes.$B$BDe todas formas, has demostrado una gran habilidad para reunir estos, $c.', 0);
-- 424 La locura de Arugal
-- https://es.classic.wowhead.com/quest=424
SET @ID := 424;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Grimson el Pálido? Varimathras no estará contento si no hacemos lo que quiere.', 0),
(@ID, 'esMX', '¿Has matado a Grimson el Pálido? Varimathras no estará contento si no hacemos lo que quiere.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! La mina nos proporcionará excelentes recursos para nuestras tropas mientras avanzamos a través de Argénteos de camino a Azeroth.', 0),
(@ID, 'esMX', '¡Soberbio! La mina nos proporcionará excelentes recursos para nuestras tropas mientras avanzamos a través de Argénteos de camino a Azeroth.', 0);
-- 425 Ivar el Hediondo
-- https://es.classic.wowhead.com/quest=425
SET @ID := 425;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Ivar el Hediondo? Si no quieres hacerlo por mi hermano y por mí, al menos hazlo por los Renegados.', 0),
(@ID, 'esMX', '¿Has matado a Ivar el Hediondo? Si no quieres hacerlo por mi hermano y por mí, al menos hazlo por los Renegados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muchas gracias. Tienes mi gratitud, $n.$B$BY te incluiré en el informe que presento a mis superiores.', 0),
(@ID, 'esMX', 'Ah, muchas gracias. Tienes mi gratitud, $n.$B$BY te incluiré en el informe que presento a mis superiores.', 0);
-- 426 La invasión de los molinos
-- https://es.classic.wowhead.com/quest=426
SET @ID := 426;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestras batallas contra la Plaga están en marcha, $n. ¡Haz lo que te corresponde y envía a esos malditos no-muertos de vuelta a las Tierras de la Peste!', 0),
(@ID, 'esMX', 'Nuestras batallas contra la Plaga están en marcha, $n. ¡Haz lo que te corresponde y envía a esos malditos no-muertos de vuelta a las Tierras de la Peste!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos estás ayudando mucho en la guerra, $n. No te daré las gracias por hacer lo que es necesario, pero has de saber que los guardias de la muerte de Tirisfal no olvidaremos tu nombre.', 0),
(@ID, 'esMX', 'Nos estás ayudando mucho en la guerra, $n. No te daré las gracias por hacer lo que es necesario, pero has de saber que los guardias de la muerte de Tirisfal no olvidaremos tu nombre.', 0);
-- 427 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=427
SET @ID := 427;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si deseas demostrar tu valía a La Dama Oscura, mata a 10 Guerreros Escarlata, $c.', 0),
(@ID, 'esMX', 'Si deseas demostrar tu valía a La Dama Oscura, mata a 10 Guerreros Escarlata, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $c. Tu habilidad en el arte de la lucha es innegable.', 0),
(@ID, 'esMX', 'Impresionante, $c. Tu habilidad en el arte de la lucha es innegable.', 0);
-- 428 Los Mortacechadores desaparecidos
-- https://es.classic.wowhead.com/quest=428
SET @ID := 428;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nos has encontrado! Y justo a tiempo.', 0),
(@ID, 'esMX', '¡Nos has encontrado! Y justo a tiempo.', 0);
-- 429 Corazones salvajes
-- https://es.classic.wowhead.com/quest=429
SET @ID := 429;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me queda mucho tiempo, $c, la Dama Oscura me ha encargado una tarea de vital importancia.', 0),
(@ID, 'esMX', 'No me queda mucho tiempo, $c, la Dama Oscura me ha encargado una tarea de vital importancia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Renferrel coge los corazones.>$B$BResulta de lo más perturbador saber que nuestros Mortacechadores han fallado su misión.$B$BEsperemos que no tengamos muchos fracasos más.$B$BTe daré la poción en un momento, pero aquí tienes la receta. Si esos Mortacechadores necesitan ayuda en el futuro, quizás podías dárselo tú mismo.', 0),
(@ID, 'esMX', '<Renferrel coge los corazones.>$B$BResulta de lo más perturbador saber que nuestros Mortacechadores han fallado su misión.$B$BEsperemos que no tengamos muchos fracasos más.$B$BTe daré la poción en un momento, pero aquí tienes la receta. Si esos Mortacechadores necesitan ayuda en el futuro, quizás podías dárselo tú mismo.', 0);
-- 430 Regresa junto a Quinn
-- https://es.classic.wowhead.com/quest=430
SET @ID := 430;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi hermana me dijo que estabas aquí para ayudarnos. ¿Es eso cierto?', 0),
(@ID, 'esMX', 'Mi hermana me dijo que estabas aquí para ayudarnos. ¿Es eso cierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Quinn coge la poción y la bebe.>$B$BSí, siento que funciona. Pronto podré viajar.$B$BMe has hecho un gran favor, $n.', 0),
(@ID, 'esMX', '<Quinn coge la poción y la bebe.>$B$BSí, siento que funciona. Pronto podré viajar.$B$BMe has hecho un gran favor, $n.', 0);
-- 431 Velas de señalización
-- https://es.classic.wowhead.com/quest=431
SET @ID := 431;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coges una de las velas y la colocas en tu talega.', 0),
(@ID, 'esMX', 'Coges una de las velas y la colocas en tu talega.', 0);
