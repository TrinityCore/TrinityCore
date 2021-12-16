-- 556 Muestras de piedra
-- https://es.classic.wowhead.com/quest=556
SET @ID := 556;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes las muestras de piedra gastada? El mago está deseando estudiarlas.', 0),
(@ID, 'esMX', '¿Traes las muestras de piedra gastada? El mago está deseando estudiarlas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estupendo; aunque su magia parece gastada, estas muestras son perfectas para estudiarlas.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'Estupendo; aunque su magia parece gastada, estas muestras son perfectas para estudiarlas.$B$BGracias, $n.', 0);
-- 557 Brazales de vínculo
-- https://es.classic.wowhead.com/quest=557
SET @ID := 557;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Cómo fue con los elementales? ¿Traes los brazales de vínculo?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Cómo fue con los elementales? ¿Traes los brazales de vínculo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. ¿Tuviste problemas para conseguirlos?$B$BTienes razón, la pregunta es absurda.$B$BTe agradecemos tus servicios, $n.', 0),
(@ID, 'esMX', 'Excelente. ¿Tuviste problemas para conseguirlos?$B$BTienes razón, la pregunta es absurda.$B$BTe agradecemos tus servicios, $n.', 0);
-- 558 El autógrafo de Jaina
-- https://es.classic.wowhead.com/quest=558
SET @ID := 558;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Algún día, quiero ser un héroe como Jaina ... bueno, un niño héroe.', 0),
(@ID, 'esMX', 'Algún día, quiero ser un héroe como Jaina ... bueno, un niño héroe.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡GUAUU! ¡Tienes el autógrafo de Lady Jaina para mí! ¡Muchas gracias! Y guau... ella escribió un mensaje personal aquí - ¡para mí! Sabía que sería genial, y tal vez algún día le agradeceré yo mismo... ¡cuando me convierta en un héroe de la Alianza!$B$BEres $gel:la; mejor, $n. Gracias por ser tan amable conmigo.', 0),
(@ID, 'esMX', '¡GUAUU! ¡Tienes el autógrafo de Lady Jaina para mí! ¡Muchas gracias! Y guau... ella escribió un mensaje personal aquí - ¡para mí! Sabía que sería genial, y tal vez algún día le agradeceré yo mismo... ¡cuando me convierta en un héroe de la Alianza!$B$BEres $gel:la; mejor, $n. Gracias por ser tan amable conmigo.', 0);
-- 566 SE BUSCA: Barón Vardus
-- https://es.classic.wowhead.com/quest=566
SET @ID := 566;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n. ¿Has venido a por tu recompensa por la cabeza del Barón Vardus?', 0),
(@ID, 'esMX', 'Ah, $n. ¿Has venido a por tu recompensa por la cabeza del Barón Vardus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Con el Barón Vardus muerto, se debilita la cúpula de la Hermandad. Les queda poco tiempo.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Con el Barón Vardus muerto, se debilita la cúpula de la Hermandad. Les queda poco tiempo.', 0);
-- 567 ¡Peligrosos!
-- https://es.classic.wowhead.com/quest=567
SET @ID := 567;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $c. Buen trabajo.', 0),
(@ID, 'esMX', 'Excelente, $c. Buen trabajo.', 0);
-- 568 La defensa de Grom'gol
-- https://es.classic.wowhead.com/quest=568
SET @ID := 568;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros esfuerzos por mantener la cadena de suministros aún se ven obstaculizados por la población de raptores locales, $c.', 0),
(@ID, 'esMX', 'Nuestros esfuerzos por mantener la cadena de suministros aún se ven obstaculizados por la población de raptores locales, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has realizado tu trabajo con honor, $c.', 0),
(@ID, 'esMX', 'Has realizado tu trabajo con honor, $c.', 0);
-- 569 La defensa de Grom'gol
-- https://es.classic.wowhead.com/quest=569
SET @ID := 569;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has progresado con los ogros de las Ruinas de Mizjah, $c?', 0),
(@ID, 'esMX', '¿Has progresado con los ogros de las Ruinas de Mizjah, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. Has servido al Jefe de Guerra con honor.', 0),
(@ID, 'esMX', 'Bien hecho. Has servido al Jefe de Guerra con honor.', 0);
-- 570 El encantamiento de Mok'thardin
-- https://es.classic.wowhead.com/quest=570
SET @ID := 570;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias me traes?', 0),
(@ID, 'esMX', '¿Qué noticias me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Conoces la selva a la perfección, $n. Esto será perfecto. Agradeceré a los espíritus el sacrificio de unas bestias así por la causa de la Horda.', 0),
(@ID, 'esMX', 'Conoces la selva a la perfección, $n. Esto será perfecto. Agradeceré a los espíritus el sacrificio de unas bestias así por la causa de la Horda.', 0);
-- 571 El encantamiento de Mok'thardin
-- https://es.classic.wowhead.com/quest=571
SET @ID := 571;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ha acompañado la suerte, $n? ¿Has conseguido encontrar un tendón de gorila mayor?', 0),
(@ID, 'esMX', '¿Te ha acompañado la suerte, $n? ¿Has conseguido encontrar un tendón de gorila mayor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un tendón perfecto, $n. Tus esfuerzos han merecido la pena.', 0),
(@ID, 'esMX', 'Un tendón perfecto, $n. Tus esfuerzos han merecido la pena.', 0);
-- 572 El encantamiento de Mok'thardin
-- https://es.classic.wowhead.com/quest=572
SET @ID := 572;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Han dado fruto tus esfuerzos?', 0),
(@ID, 'esMX', '¿Han dado fruto tus esfuerzos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! Prepararé esto inmediatamente.', 0),
(@ID, 'esMX', '¡Soberbio! Prepararé esto inmediatamente.', 0);
-- 573 El encantamiento de Mok'thardin
-- https://es.classic.wowhead.com/quest=573
SET @ID := 573;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Casi estoy a punto de completar el encantamiento. ¿Has hecho lo que te he pedido?', 0),
(@ID, 'esMX', 'Casi estoy a punto de completar el encantamiento. ¿Has hecho lo que te he pedido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con este agua sagrada, la gargantilla ceremonial estará lista para el encantamiento.$B$BLlévala con orgullo, $n, en el nombre del Jefe de Guerra y en defensa de la poderosa Horda.', 0),
(@ID, 'esMX', 'Con este agua sagrada, la gargantilla ceremonial estará lista para el encantamiento.$B$BLlévala con orgullo, $n, en el nombre del Jefe de Guerra y en defensa de la poderosa Horda.', 0);
-- 575 La oferta y la demanda
-- https://es.classic.wowhead.com/quest=575
SET @ID := 575;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo todo el equipamiento listo, $n, solo necesito esas pieles. No queremos que Riddlevox tenga que esperar, eso queda claro.$B$BNo es buena idea que nadie deje insatisfecho al inventor jefe del Gremio de Manitas.', 0),
(@ID, 'esMX', 'Tengo todo el equipamiento listo, $n, solo necesito esas pieles. No queremos que Riddlevox tenga que esperar, eso queda claro.$B$BNo es buena idea que nadie deje insatisfecho al inventor jefe del Gremio de Manitas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con estas pieles será suficiente. La calidad no es demasiado importante, visto que se utilizarán para la capa interior de las botas, pero es importante que sean cómodas.$B$BSi son demasiado rígidas, utilizaré sangre de tigre para ablandarlas. Trucos del oficio, ¿sabes?', 0),
(@ID, 'esMX', 'Con estas pieles será suficiente. La calidad no es demasiado importante, visto que se utilizarán para la capa interior de las botas, pero es importante que sean cómodas.$B$BSi son demasiado rígidas, utilizaré sangre de tigre para ablandarlas. Trucos del oficio, ¿sabes?', 0);
-- 578 La piedra de las mareas
-- https://es.classic.wowhead.com/quest=578
SET @ID := 578;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los trols realmente poseían algunos objetos mágicos asombrosos, $n. Y ahora, quizás, tenga la oportunidad de agregar uno a mi extensa colección. ¿Tuviste suerte para encontrar la fuente del rumor?', 0),
(@ID, 'esMX', 'Los trols realmente poseían algunos objetos mágicos asombrosos, $n. Y ahora, quizás, tenga la oportunidad de agregar uno a mi extensa colección. ¿Tuviste suerte para encontrar la fuente del rumor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así que las historias eran ciertas! ¡Increíble!$B$BSin embargo, necesitaremos descubrir la forma de acabar con la maldición de la Piedra de las Mareas si queremos recuperarla. La maldición conlleva magia, así que necesitaremos a uno de esos zahoríes para que nos ayude.', 0),
(@ID, 'esMX', '¡Así que las historias eran ciertas! ¡Increíble!$B$BSin embargo, necesitaremos descubrir la forma de acabar con la maldición de la Piedra de las Mareas si queremos recuperarla. La maldición conlleva magia, así que necesitaremos a uno de esos zahoríes para que nos ayude.', 0);
-- 580 El grog de Whiskey el Delgado
-- https://es.classic.wowhead.com/quest=580
SET @ID := 580;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que me aspen! ¡Casi me he quedao sin bebida! El capitán va a echar el ancla y el viejo Slim va a quedar tan seco como el Desierto de Tanaris. Y cuando descubra que su oporto ha desaparecido. ¡La que me espera!', 0),
(@ID, 'esMX', '¡Que me aspen! ¡Casi me he quedao sin bebida! El capitán va a echar el ancla y el viejo Slim va a quedar tan seco como el Desierto de Tanaris. Y cuando descubra que su oporto ha desaparecido. ¡La que me espera!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Voto a bríos! ¡Has encontrao el grog del capitán!$B$BToy en deuda contigo, amigo.$B$BParece que hay una tormenta ahí fuera preparándose pa atacar. Quizás me quede con una de estas botellitas de aquí, solo pa esperar que pase la tormenta...', 0),
(@ID, 'esMX', '¡Voto a bríos! ¡Has encontrao el grog del capitán!$B$BToy en deuda contigo, amigo.$B$BParece que hay una tormenta ahí fuera preparándose pa atacar. Quizás me quede con una de estas botellitas de aquí, solo pa esperar que pase la tormenta...', 0);
-- 581 Caza para Yenniku
-- https://es.classic.wowhead.com/quest=581
SET @ID := 581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c. Demuéstrame que has tenido éxito con la tribu Sangrapellejo.$B$BEnséñame los trofeos.', 0),
(@ID, 'esMX', '$c. Demuéstrame que has tenido éxito con la tribu Sangrapellejo.$B$BEnséñame los trofeos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Unos colmillos de gran calidad, $n. Has demostrado que tienes la fuerza necesaria para cazar a los Sangrapellejo.$B$BY me alegro, porque todavía no has acabado con ellos.', 0),
(@ID, 'esMX', 'Unos colmillos de gran calidad, $n. Has demostrado que tienes la fuerza necesaria para cazar a los Sangrapellejo.$B$BY me alegro, porque todavía no has acabado con ellos.', 0);
-- 582 Caza cabezas
-- https://es.classic.wowhead.com/quest=582
SET @ID := 582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Temo por el hijo de nuestro jefe. ¿Tienes las cabezas reducidas para que pueda inspeccionarlas?', 0),
(@ID, 'esMX', '$n. Temo por el hijo de nuestro jefe. ¿Tienes las cabezas reducidas para que pueda inspeccionarlas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Inspeccionaré estas cabezas para asegurarme de que el pobre Yenniku se libró del hacha.', 0),
(@ID, 'esMX', 'Gracias, $n. Inspeccionaré estas cabezas para asegurarme de que el pobre Yenniku se libró del hacha.', 0);
-- 584 Las cabezas de los Sangrapellejo
-- https://es.classic.wowhead.com/quest=584
SET @ID := 584;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caldo verde de la caldera está hirviendo.', 0),
(@ID, 'esMX', 'El caldo verde de la caldera está hirviendo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas las cabezas de Gan\'zulah y Nezzliok en la caldera...', 0),
(@ID, 'esMX', 'Colocas las cabezas de Gan\'zulah y Nezzliok en la caldera...', 0);
-- 585 Hablando con Nezzliok
-- https://es.classic.wowhead.com/quest=585
SET @ID := 585;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero los cráneos...', 0),
(@ID, 'esMX', 'Espero los cráneos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí. Son perfectos. Cuando mi espíritu haya sido liberado, entraré en el Vacío Abismal con tres sirvientes.$B$BHonras a nuestro clan, $r, y me has aplacado.', 0),
(@ID, 'esMX', 'Sí. Son perfectos. Cuando mi espíritu haya sido liberado, entraré en el Vacío Abismal con tres sirvientes.$B$BHonras a nuestro clan, $r, y me has aplacado.', 0);
-- 586 Hablando con Gan'zulah
-- https://es.classic.wowhead.com/quest=586
SET @ID := 586;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque mi propia piel está siendo desgarrada y separada de mi cráneo, todavía puedo oler tu miedo.$B$B¡Ja! Nunca conseguirás hacer lo que te he pedido...', 0),
(@ID, 'esMX', 'Aunque mi propia piel está siendo desgarrada y separada de mi cráneo, todavía puedo oler tu miedo.$B$B¡Ja! Nunca conseguirás hacer lo que te he pedido...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No quiero creerlo, pero no puedo negar lo que has hecho. Y mi ira disminuye ahora que has vencido a Ana\'thek.$B$BTu poder te conducirá a grandes logros, $n. Pero un día... te veré en el Vacío Abismal y volveremos a enfrentarnos.$B$BTe estaré esperando.', 0),
(@ID, 'esMX', 'No quiero creerlo, pero no puedo negar lo que has hecho. Y mi ira disminuye ahora que has vencido a Ana\'thek.$B$BTu poder te conducirá a grandes logros, $n. Pero un día... te veré en el Vacío Abismal y volveremos a enfrentarnos.$B$BTe estaré esperando.', 0);
-- 588 El destino de Yenniku
-- https://es.classic.wowhead.com/quest=588
SET @ID := 588;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Zanzil el Desarraigado??$B$BSi Yenniku está en manos de ese trol, un malvado médico brujo, me temo que solo nos queda una pequeña esperanza. Muy pequeña. Tan pequeña como el insecto más ínfimo.$B$BPero, aún así, sigue siendo una esperanza.', 0),
(@ID, 'esMX', '¿¿Zanzil el Desarraigado??$B$BSi Yenniku está en manos de ese trol, un malvado médico brujo, me temo que solo nos queda una pequeña esperanza. Muy pequeña. Tan pequeña como el insecto más ínfimo.$B$BPero, aún así, sigue siendo una esperanza.', 0);
-- 589 Los cristales canto
-- https://es.classic.wowhead.com/quest=589
SET @ID := 589;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los fragmentos, $n? Los necesito para mi ritual final, cuando tengamos el Ojo de la Mente.', 0),
(@ID, 'esMX', '¿Tienes los fragmentos, $n? Los necesito para mi ritual final, cuando tengamos el Ojo de la Mente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Estos fragmentos son perfectos. Ya puedo oír su canto.$B$BY, mientras no estabas, hablé con los espíritus de la selva. Sé dónde está el Ojo de la Mente...$B$B... y quién lo tiene.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Estos fragmentos son perfectos. Ya puedo oír su canto.$B$BY, mientras no estabas, hablé con los espíritus de la selva. Sé dónde está el Ojo de la Mente...$B$B... y quién lo tiene.', 0);
-- 640 El sigilo roto
-- https://es.classic.wowhead.com/quest=640
SET @ID := 640;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Throm-ka, $c. Zengu me ha informado de que requerías mi ayuda.', 0),
(@ID, 'esMX', 'Throm-ka, $c. Zengu me ha informado de que requerías mi ayuda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿me necesitas para reconstruir este sigilo? No debería ser muy difícil... todas las piezas parecen estar aquí y será fácil reconstituir la estructura mágica.$B$BPuede que te convenga cerrar los ojos.', 0),
(@ID, 'esMX', 'Ah, ¿me necesitas para reconstruir este sigilo? No debería ser muy difícil... todas las piezas parecen estar aquí y será fácil reconstituir la estructura mágica.$B$BPuede que te convenga cerrar los ojos.', 0);
-- 641 El sigilo de Thoradin
-- https://es.classic.wowhead.com/quest=641
SET @ID := 641;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Tienes el segundo sigilo?', 0),
(@ID, 'esMX', '¡$n! ¿Tienes el segundo sigilo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya estamos a medio camino de conseguir extraer a Trol\'kalar de la tumba de Aterratrols. Aún no estamos seguros de dónde se encuentra el tercer sigilo porque sus poseedores parecen haberse dirigido a algún lugar cerca de Arathi pero tengo fe en que lograremos encontrarlo.', 0),
(@ID, 'esMX', 'Ya estamos a medio camino de conseguir extraer a Trol\'kalar de la tumba de Aterratrols. Aún no estamos seguros de dónde se encuentra el tercer sigilo porque sus poseedores parecen haberse dirigido a algún lugar cerca de Arathi pero tengo fe en que lograremos encontrarlo.', 0);
