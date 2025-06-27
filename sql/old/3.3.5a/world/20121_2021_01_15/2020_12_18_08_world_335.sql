-- 666 El tesoro sumergido
-- https://es.classic.wowhead.com/quest=666
SET @ID := 666;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal funcionaban las gafas protectoras? ¿Todo funcionaba bien? Se pueden realizar ajustes si fuera necesario.$B$BAh, y necesitaré que me devuelvas las gafas protectoras cuando hayas acabado. Seguro que el capitán O\'Breen encontrará muchas formas de usarlas más adelante.', 0),
(@ID, 'esMX', '¿Qué tal funcionaban las gafas protectoras? ¿Todo funcionaba bien? Se pueden realizar ajustes si fuera necesario.$B$BAh, y necesitaré que me devuelvas las gafas protectoras cuando hayas acabado. Seguro que el capitán O\'Breen encontrará muchas formas de usarlas más adelante.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Magnífico, $n! ¡El Capitán estará muy complacido! ¡Y no veas cuando se entere el maestro de flota Cuernomarino!', 0),
(@ID, 'esMX', '¡Magnífico, $n! ¡El Capitán estará muy complacido! ¡Y no veas cuando se entere el maestro de flota Cuernomarino!', 0);
-- 667 Muerte desde abajo
-- https://es.classic.wowhead.com/quest=667
SET @ID := 667;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hemos sobrevivido al ataque!$B$BNo lo habríamos logrado sin ti, $n.$B$BPartiremos en cuanto suba la marea. Si no fueras una promesa como $ghéroe:heroína; te ofrecería un puesto en mi tripulación. Pero se te nota que te esperan peces más gordos.$B$BAunque no seas más que $gun:una; enclenque $r...', 0),
(@ID, 'esMX', '¡Hemos sobrevivido al ataque!$B$BNo lo habríamos logrado sin ti, $n.$B$BPartiremos en cuanto suba la marea. Si no fueras una promesa como $ghéroe:heroína; te ofrecería un puesto en mi tripulación. Pero se te nota que te esperan peces más gordos.$B$BAunque no seas más que $gun:una; enclenque $r...', 0);
-- 668 El tesoro sumergido
-- https://es.classic.wowhead.com/quest=668
SET @ID := 668;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah del barco, $c! ¿Qué te trae por el puente?', 0),
(@ID, 'esMX', '¡Ah del barco, $c! ¿Qué te trae por el puente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conque los pequeños gnomos demostraron su valor después de todo? ¡Sabía que esos mordedores de tobillo acabarían sirviendo para algo!', 0),
(@ID, 'esMX', '¿Conque los pequeños gnomos demostraron su valor después de todo? ¡Sabía que esos mordedores de tobillo acabarían sirviendo para algo!', 0);
-- 669 El tesoro sumergido
-- https://es.classic.wowhead.com/quest=669
SET @ID := 669;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae por Bahía del Botín, $c?', 0),
(@ID, 'esMX', '¿Qué te trae por Bahía del Botín, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bah, déjaselo al viejo Temblores O’Breen! ¡Sabía que era el capitán adecuado para la misión!', 0),
(@ID, 'esMX', '¡Bah, déjaselo al viejo Temblores O’Breen! ¡Sabía que era el capitán adecuado para la misión!', 0);
-- 670 El tesoro sumergido
-- https://es.classic.wowhead.com/quest=670
SET @ID := 670;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Estaba Cuernomarino contento contigo? Apuesto que su sonrisa iba de Bahía del Botín hasta Trinquete.', 0),
(@ID, 'esMX', '¿Qué? ¿Estaba Cuernomarino contento contigo? Apuesto que su sonrisa iba de Bahía del Botín hasta Trinquete.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por hacer un viaje tan largo y peligroso. Tienes el agradecimiento de los asaltantes Aguasnegras.', 0),
(@ID, 'esMX', 'Gracias por hacer un viaje tan largo y peligroso. Tienes el agradecimiento de los asaltantes Aguasnegras.', 0);
-- 671 Magia demoníaca
-- https://es.classic.wowhead.com/quest=671
SET @ID := 671;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La sangre que fuera maldita aún fluye por mis venas, $n. Si alguien... algo está conjurando demonios, hay que detenerlo.', 0),
(@ID, 'esMX', 'La sangre que fuera maldita aún fluye por mis venas, $n. Si alguien... algo está conjurando demonios, hay que detenerlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Llevará algún tiempo confirmar las verdaderas intenciones de la Hermandad pero me preocupa su abierta asociación con la magia oscura demoníaca. Te contaré más cuando lo sepa.', 0),
(@ID, 'esMX', 'Llevará algún tiempo confirmar las verdaderas intenciones de la Hermandad pero me preocupa su abierta asociación con la magia oscura demoníaca. Te contaré más cuando lo sepa.', 0);
-- 672 El despertar de los espíritus
-- https://es.classic.wowhead.com/quest=672
SET @ID := 672;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Crearé un amuleto que le dará a Gor\'mul parte de la fuerza de los raptores. Quizás esto encienda su llama interior...', 0),
(@ID, 'esMX', 'Crearé un amuleto que le dará a Gor\'mul parte de la fuerza de los raptores. Quizás esto encienda su llama interior...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fantástico. El espíritu de los raptores que dieron estos ojos aportará fuerza a quien lleve este amuleto.', 0),
(@ID, 'esMX', 'Fantástico. El espíritu de los raptores que dieron estos ojos aportará fuerza a quien lleve este amuleto.', 0);
-- 673 Magia demoníaca
-- https://es.classic.wowhead.com/quest=673
SET @ID := 673;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La sangre arde en mí... cada día más. Hay que detener al brujo.', 0),
(@ID, 'esMX', 'La sangre arde en mí... cada día más. Hay que detener al brujo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis agitadas noches se tornarán apacible sueño cuando logre destruir este orbe. Gracias, $n. Es un recuerdo estremecedor del terrible poder de los demonios que se había apoderado de los orcos antes de que Grito Infernal los liberara de la maldición.', 0),
(@ID, 'esMX', 'Mis agitadas noches se tornarán apacible sueño cuando logre destruir este orbe. Gracias, $n. Es un recuerdo estremecedor del terrible poder de los demonios que se había apoderado de los orcos antes de que Grito Infernal los liberara de la maldición.', 0);
-- 674 El despertar de los espíritus
-- https://es.classic.wowhead.com/quest=674
SET @ID := 674;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué esperanza queda cuando la mano de un cobarde puede ejecutar al más poderoso de los poderosos? ¡Dime! ¡¿Qué esperanza?!', 0),
(@ID, 'esMX', '¿Qué esperanza queda cuando la mano de un cobarde puede ejecutar al más poderoso de los poderosos? ¡Dime! ¡¿Qué esperanza?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Hueso pulido. ¿Y qué hago yo con hueso pulido? ¿Le devolverá un abalorio la gloria a la Horda?', 0),
(@ID, 'esMX', '¿Qué es esto? Hueso pulido. ¿Y qué hago yo con hueso pulido? ¿Le devolverá un abalorio la gloria a la Horda?', 0);
-- 10073 Vigía del pozo Solanian
-- https://es.wowhead.com/quest=10073
SET @ID := 10073;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has dominado la corrupción?', 0),
(@ID, 'esMX', '¿Has dominado la corrupción?', 0);
-- 675 El despertar de los espíritus
-- https://es.classic.wowhead.com/quest=675
SET @ID := 675;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No ha funcionado, ya veo. Sin embargo, creo que demostrándole el poder de los chamanes a Gor\'mul, le ayudaremos a recuperar algún día su orgullo. La potencia del amuleto era insuficiente para demostrarle nuestro nuevo poder.', 0),
(@ID, 'esMX', 'No ha funcionado, ya veo. Sin embargo, creo que demostrándole el poder de los chamanes a Gor\'mul, le ayudaremos a recuperar algún día su orgullo. La potencia del amuleto era insuficiente para demostrarle nuestro nuevo poder.', 0);
-- 701 La astucia del raptor
-- https://es.classic.wowhead.com/quest=701
SET @ID := 701;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo todos los preparativos listos, solo me faltan los corazones de raptor.', 0),
(@ID, 'esMX', 'Tengo todos los preparativos listos, solo me faltan los corazones de raptor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, nos vendrán de perlas. Transferiré su poder y el espíritu de los raptores a este orbe. Entonces este orbe le conferirá a Gor\'mul la feroz fortaleza e inteligencia del raptor.', 0),
(@ID, 'esMX', 'Sí, nos vendrán de perlas. Transferiré su poder y el espíritu de los raptores a este orbe. Entonces este orbe le conferirá a Gor\'mul la feroz fortaleza e inteligencia del raptor.', 0);
-- 702 La astucia del raptor
-- https://es.classic.wowhead.com/quest=702
SET @ID := 702;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Otra vez de vuelta? Desde luego, no hay nada que desee más que la compasión de Tor\'gan.$B$B¿Qué me traes esta vez? ¿Quizás un trozo de cuerda de color vivo? O una cuerda suficientemente larga para acabar con mi sufrimiento...', 0),
(@ID, 'esMX', '¿Otra vez de vuelta? Desde luego, no hay nada que desee más que la compasión de Tor\'gan.$B$B¿Qué me traes esta vez? ¿Quizás un trozo de cuerda de color vivo? O una cuerda suficientemente larga para acabar con mi sufrimiento...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al menos esta vez me traes algo interesante. Extraño poder el que emana...', 0),
(@ID, 'esMX', 'Al menos esta vez me traes algo interesante. Extraño poder el que emana...', 0);
-- 676 La Sentencia
-- https://es.classic.wowhead.com/quest=676
SET @ID := 676;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tengo tiempo ni de afilar el hacha y mucho menos de salir a acabar con esos que nos amenazan.$B$BNo parece que tengas mucha experiencia, $c. ¿Qué quieres?', 0),
(@ID, 'esMX', 'No tengo tiempo ni de afilar el hacha y mucho menos de salir a acabar con esos que nos amenazan.$B$BNo parece que tengas mucha experiencia, $c. ¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Crees que puedes ayudar a Sentencia? Muy bien.$B$BAlguna destreza tendrás, si no los ogros habrían acabado contigo. En todo caso, ando escaso de tropas.$B$BSi te quedas, descansa un poco y luego ven a verme otra vez. Seguro que te encuentro algunos cuellos que cortar.', 0),
(@ID, 'esMX', '¿Crees que puedes ayudar a Sentencia? Muy bien.$B$BAlguna destreza tendrás, si no los ogros habrían acabado contigo. En todo caso, ando escaso de tropas.$B$BSi te quedas, descansa un poco y luego ven a verme otra vez. Seguro que te encuentro algunos cuellos que cortar.', 0);
-- 677 Un llamamiento a las armas
-- https://es.classic.wowhead.com/quest=677
SET @ID := 677;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si aún no has completado mi tarea, entonces tal vez seas un cobarde de corazón y un principiante en la guerra.', 0),
(@ID, 'esMX', 'Si aún no has completado mi tarea, entonces tal vez seas un cobarde de corazón y un principiante en la guerra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las huellas de la guerra se evidencian en tus prendas y el sudor cae de tu frente. Bien, pero que muy bien.', 0),
(@ID, 'esMX', 'Las huellas de la guerra se evidencian en tus prendas y el sudor cae de tu frente. Bien, pero que muy bien.', 0);
-- 678 Un llamamiento a las armas
-- https://es.classic.wowhead.com/quest=678
SET @ID := 678;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes dudas. ¿Por qué? Hasta ahora has demostrado una gran fuerza, $n. No me falles ahora.', 0),
(@ID, 'esMX', 'Tienes dudas. ¿Por qué? Hasta ahora has demostrado una gran fuerza, $n. No me falles ahora.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres tan fuerte como un kodo y tu ansia de pelea es un orgullo para tu pueblo.', 0),
(@ID, 'esMX', 'Eres tan fuerte como un kodo y tu ansia de pelea es un orgullo para tu pueblo.', 0);
-- 679 Un llamamiento a las armas
-- https://es.classic.wowhead.com/quest=679
SET @ID := 679;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que tu coraje finalmente se desvanece. Parece que mis instintos estaban en lo cierto sobre ti: tu fuerza no es nada comparada con tu valentía.$B$BRegresa cuando la cabeza de la bestia haya sido cortada, o no regreses nunca.', 0),
(@ID, 'esMX', 'Veo que tu coraje finalmente se desvanece. Parece que mis instintos estaban en lo cierto sobre ti: tu fuerza no es nada comparada con tu valentía.$B$BRegresa cuando la cabeza de la bestia haya sido cortada, o no regreses nunca.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres motivo de orgullo para tu pueblo, $n. Se ha disminuido en gran medida la amenaza y estoy seguro de que no tardaremos en progresar aquí en las Tierras Altas.', 0),
(@ID, 'esMX', 'Eres motivo de orgullo para tu pueblo, $n. Se ha disminuido en gran medida la amenaza y estoy seguro de que no tardaremos en progresar aquí en las Tierras Altas.', 0);
-- 680 Una auténtica amenaza
-- https://es.classic.wowhead.com/quest=680
SET @ID := 680;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cerca de la Torre de Arathor, allí encontrarás a Or\'Kalar. Con su muerte cesarán los ataques a Sentencia y la vida de mi marido estará protegida.$B$BVeo en tus ojos que me consideras débil, incluso deshonrosa, por mi silencio. Algún día entenderás lo que es amar como yo. Quizás entiendas entonces que hay otra clase de fuerza y de honor.$B$BMientras tanto, haz lo que te pido y ejecuta a Or\'Kalar.', 0),
(@ID, 'esMX', 'Cerca de la Torre de Arathor, allí encontrarás a Or\'Kalar. Con su muerte cesarán los ataques a Sentencia y la vida de mi marido estará protegida.$B$BVeo en tus ojos que me consideras débil, incluso deshonrosa, por mi silencio. Algún día entenderás lo que es amar como yo. Quizás entiendas entonces que hay otra clase de fuerza y de honor.$B$BMientras tanto, haz lo que te pido y ejecuta a Or\'Kalar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has hecho un gran favor, $n. Ten por seguro que has protegido la vida de mi marido y la de Sentencia un día más con tus acciones. Te ruego aceptes esta recompensa por tu valentía.', 0),
(@ID, 'esMX', 'Me has hecho un gran favor, $n. Ten por seguro que has protegido la vida de mi marido y la de Sentencia un día más con tus acciones. Te ruego aceptes esta recompensa por tu valentía.', 0);
-- 683 La petición de Sara Balloo
-- https://es.classic.wowhead.com/quest=683
SET @ID := 683;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eres $n $gel:la; $c? El relato de tus servicios a la Alianza ha llegado hasta aquí.$B$BDime, ¿qué puedo hacer por ti?', 0),
(@ID, 'esMX', '¿Eres $n $gel:la; $c? El relato de tus servicios a la Alianza ha llegado hasta aquí.$B$BDime, ¿qué puedo hacer por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame unos minutos para leer la carta...', 0),
(@ID, 'esMX', 'Déjame unos minutos para leer la carta...', 0);
-- 686 Un homenaje real
-- https://es.classic.wowhead.com/quest=686
SET @ID := 686;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que vienes de parte del rey Magni Barbabronce?$B$B¡Vaya, esto debe de ser importante!', 0),
(@ID, 'esMX', '¿Que vienes de parte del rey Magni Barbabronce?$B$B¡Vaya, esto debe de ser importante!', 0);
-- 688 Aliados de Myzrael
-- https://es.classic.wowhead.com/quest=688
SET @ID := 688;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida;, $c. La Señora me informó de tu visita y si hemos de devolverla a la superficie, entonces tenemos mucho de qué hablar...', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida;, $c. La Señora me informó de tu visita y si hemos de devolverla a la superficie, entonces tenemos mucho de qué hablar...', 0);
-- 689 Un homenaje real
-- https://es.classic.wowhead.com/quest=689
SET @ID := 689;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, $n! Dime que me traes granito de Alterac para empezar el monumento a Sully Balloo.', 0),
(@ID, 'esMX', '¡Ah, $n! Dime que me traes granito de Alterac para empezar el monumento a Sully Balloo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Perfecto! ¡Mejor de lo que habría podido soñar!$B$BY que sepas que tengo mucha imaginación.', 0),
(@ID, 'esMX', '¡Perfecto! ¡Mejor de lo que habría podido soñar!$B$BY que sepas que tengo mucha imaginación.', 0);
-- 698 Falta de suministros
-- https://es.classic.wowhead.com/quest=698
SET @ID := 698;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lok\'tar, $c. Viajar por los pantanos no es algo que te puedas tomar a la ligera. Tienes que ser muy valiente si vas a demostrar lo que vales aquí.', 0),
(@ID, 'esMX', 'Lok\'tar, $c. Viajar por los pantanos no es algo que te puedas tomar a la ligera. Tienes que ser muy valiente si vas a demostrar lo que vales aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Estupendo. Esta noche tenemos carne fresca. Gracias, $n.$B$BHas ayudado a que las noches sean más tolerables. El fuego arde con brío y nuestros estómagos pronto estarán llenos.$B$BEs una agradable sorpresa que nos hayas traído un cargamento; Dar no es el orco más atractivo del mundo, pero al menos, su actitud apesta menos que su aliento.', 0),
(@ID, 'esMX', '¡Ah! Estupendo. Esta noche tenemos carne fresca. Gracias, $n.$B$BHas ayudado a que las noches sean más tolerables. El fuego arde con brío y nuestros estómagos pronto estarán llenos.$B$BEs una agradable sorpresa que nos hayas traído un cargamento; Dar no es el orco más atractivo del mundo, pero al menos, su actitud apesta menos que su aliento.', 0);
-- 699 Falta de suministros
-- https://es.classic.wowhead.com/quest=699
SET @ID := 699;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen licor de hidromiel, una buena hoguera, un ejército de orcos y un arsenal de armas... es todo lo que necesitamos aquí en la costa. No lamento para nada estar aquí fuera protegiendo Rocal, pero me gustaría poder conseguir una madriguera o, al menos, una torre.', 0),
(@ID, 'esMX', 'Un buen licor de hidromiel, una buena hoguera, un ejército de orcos y un arsenal de armas... es todo lo que necesitamos aquí en la costa. No lamento para nada estar aquí fuera protegiendo Rocal, pero me gustaría poder conseguir una madriguera o, al menos, una torre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que sigues con vida, $n.$B$BEstas garras serán perfectas. Cuantas más armas tengamos listas para los ataques, mejor parados saldremos.$B$BEmpezaré con tu arma en cuanto pueda. Solo me llevará un poco de tiempo. Me he vuelto muy hábil produciéndolas.', 0),
(@ID, 'esMX', 'Me alegra ver que sigues con vida, $n.$B$BEstas garras serán perfectas. Cuantas más armas tengamos listas para los ataques, mejor parados saldremos.$B$BEmpezaré con tu arma en cuanto pueda. Solo me llevará un poco de tiempo. Me he vuelto muy hábil produciéndolas.', 0);
-- 700 Un homenaje real
-- https://es.classic.wowhead.com/quest=700
SET @ID := 700;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El granito parece un homenaje muy pobre para tan gran enano, pero ningún enano vive para siempre.$B$BEsperemos que el monumento sí dure y que las generaciones futuras recuerden al valiente Sully Balloo y otros bravos soldados como él.', 0),
(@ID, 'esMX', 'El granito parece un homenaje muy pobre para tan gran enano, pero ningún enano vive para siempre.$B$BEsperemos que el monumento sí dure y que las generaciones futuras recuerden al valiente Sully Balloo y otros bravos soldados como él.', 0);
-- 710 Estudio de los elementos: roca
-- https://es.classic.wowhead.com/quest=710
SET @ID := 710;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este sitio es perfecto para… ¿Podrías sujetarme eso un momento? Sí, justo ahí, a lo largo del vector normal. Ahora, ¿por dónde...? Ah, sí. El lugar perfecto para probar mi proyecto más reciente. La materia prima, el espacio abierto... ¿qué más podría pedir un ilustrado y brillante practicante de las artes?', 0),
(@ID, 'esMX', 'Este sitio es perfecto para… ¿Podrías sujetarme eso un momento? Sí, justo ahí, a lo largo del vector normal. Ahora, ¿por dónde...? Ah, sí. El lugar perfecto para probar mi proyecto más reciente. La materia prima, el espacio abierto... ¿qué más podría pedir un ilustrado y brillante practicante de las artes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos nos servirán, $n. Gracias. Mm, algo más de arena de lo que preveía. Tengo que ajustar el coeficiente de fricción. No, espera; aún debería ser marginal con el aceite de escarcha.', 0),
(@ID, 'esMX', 'Estos nos servirán, $n. Gracias. Mm, algo más de arena de lo que preveía. Tengo que ajustar el coeficiente de fricción. No, espera; aún debería ser marginal con el aceite de escarcha.', 0);
