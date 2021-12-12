-- 9986 Frustrando los planes de los arakkoa
-- https://es.wowhead.com/quest=9986
SET @ID := 9986;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno verte de nuevo, $n. ¿Has hecho lo que te pedí?', 0),
(@ID, 'esMX', 'Es bueno verte de nuevo, $n. ¿Has hecho lo que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Ya tenemos bastantes preocupaciones sin tener que pensar en si los arakkoa empezarán a acosar a nuestros mercaderes y mensajeros.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Ya tenemos bastantes preocupaciones sin tener que pensar en si los arakkoa empezarán a acosar a nuestros mercaderes y mensajeros.', 0);
-- 9987 Frustrando los planes de los arakkoa
-- https://es.wowhead.com/quest=9987
SET @ID := 9987;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has tratado con los líderes arakkoa?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has tratado con los líderes arakkoa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Ya tenemos bastantes preocupaciones sin tener que pensar en si los arakkoa empezarán a acosar a nuestros mercaderes y mensajeros.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Ya tenemos bastantes preocupaciones sin tener que pensar en si los arakkoa empezarán a acosar a nuestros mercaderes y mensajeros.', 0);
-- 9990 Investigación de Tuurem
-- https://es.wowhead.com/quest=9990
SET @ID := 9990;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes, $n?', 0),
(@ID, 'esMX', '¿Qué noticias traes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Etéreos? ¿Mercancía entregada en Tuurem? ¿Piezas exóticas energizadas? ¿Y elfos de sangre preparados para entregar esta última caja al Alto Ala de Fuego?$B$B¡¿Qué significa todo esto?! ¿Qué relación tiene con lo que les ocurrió a los druidas en el Matorral Cenarion?$B$BCreo que deberíamos ver lo que contiene esa caja.', 0),
(@ID, 'esMX', '¿Etéreos? ¿Mercancía entregada en Tuurem? ¿Piezas exóticas energizadas? ¿Y elfos de sangre preparados para entregar esta última caja al Alto Ala de Fuego?$B$B¡¿Qué significa todo esto?! ¿Qué relación tiene con lo que les ocurrió a los druidas en el Matorral Cenarion?$B$BCreo que deberíamos ver lo que contiene esa caja.', 0);
-- 9991 Inspeccionar la tierra
-- https://es.wowhead.com/quest=9991
SET @ID := 9991;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca has volado a lomos de un Draco abisal, ¿eh?', 0),
(@ID, 'esMX', 'Nunca has volado a lomos de un Draco abisal, ¿eh?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un trabajo excelente, $n! Ahora tenemos un punto desde el que podemos planear nuestro contraataque.', 0),
(@ID, 'esMX', '¡Un trabajo excelente, $n! Ahora tenemos un punto desde el que podemos planear nuestro contraataque.', 0);
-- 9992 Semillas de olemba
-- https://es.wowhead.com/quest=9992
SET @ID := 9992;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He empezado una colección de semillas, pero voy a necesitar ayuda para conseguir las suficientes y poder enviarlas al parque de Ventormenta.', 0),
(@ID, 'esMX', 'He empezado una colección de semillas, pero voy a necesitar ayuda para conseguir las suficientes y poder enviarlas al parque de Ventormenta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por las semillas. Ya casi tengo bastantes para enviar el primer cargamento.', 0),
(@ID, 'esMX', 'Gracias por las semillas. Ya casi tengo bastantes para enviar el primer cargamento.', 0);
-- 9993 Aceite de semilla de olemba
-- https://es.wowhead.com/quest=9993
SET @ID := 9993;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes alguna semilla para mí?', 0),
(@ID, 'esMX', '¿Tienes alguna semilla para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen comienzo, pero vamos a necesitar muchas más si queremos sacar una buena cantidad de aceite.', 0),
(@ID, 'esMX', 'Un buen comienzo, pero vamos a necesitar muchas más si queremos sacar una buena cantidad de aceite.', 0);
-- 9994 ¿Qué son estas cosas?
-- https://es.wowhead.com/quest=9994
SET @ID := 9994;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces $gpreocupado:preocupada;. ¿Qué ocurre, $c?', 0),
(@ID, 'esMX', 'Pareces $gpreocupado:preocupada;. ¿Qué ocurre, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, no! ¡Qué noticias tan horribles! No puedo creerme que solo queden dos de nuestros amigos de Cenarius con vida.$B$BMuy bien, deja que eche un vistazo a estas piezas. Espero que no sean lo que creo que son.$B$BSí, como me temía son piezas de una bomba. Nuestros ojos y nuestros oídos en la Ciudad de Shattrath nos han proporcionado información sobre etéreos que importan mercancías prohibidas de otras dimensiones con las que han entrado en contacto.', 0),
(@ID, 'esMX', '¡Oh, no! ¡Qué noticias tan horribles! No puedo creerme que solo queden dos de nuestros amigos de Cenarius con vida.$B$BMuy bien, deja que eche un vistazo a estas piezas. Espero que no sean lo que creo que son.$B$BSí, como me temía son piezas de una bomba. Nuestros ojos y nuestros oídos en la Ciudad de Shattrath nos han proporcionado información sobre etéreos que importan mercancías prohibidas de otras dimensiones con las que han entrado en contacto.', 0);
-- 9995 ¿Qué son estas cosas?
-- https://es.wowhead.com/quest=9995
SET @ID := 9995;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces preocupado. ¿Qué ocurre, $c?', 0),
(@ID, 'esMX', 'Pareces preocupado. ¿Qué ocurre, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, no! ¡Qué noticias tan horribles! No puedo creerme que solo queden dos de nuestros amigos de Cenarius con vida.$B$BMuy bien, deja que eche un vistazo a estas piezas. Espero que no sean lo que creo que son.', 0),
(@ID, 'esMX', '¡Oh, no! ¡Qué noticias tan horribles! No puedo creerme que solo queden dos de nuestros amigos de Cenarius con vida.$B$BMuy bien, deja que eche un vistazo a estas piezas. Espero que no sean lo que creo que son.', 0);
-- Ataque en el Alto Ala de Fuego
-- 9996, 9997
-- https://es.wowhead.com/quest=9996
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9996, 9997) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9996, 'esES', 'Informe. ¿Qué novedades traes de Alto Ala de Fuego?', 0),
(9997, 'esES', 'Informe. ¿Qué novedades traes de Alto Ala de Fuego?', 0),
(9996, 'esMX', 'Informe. ¿Qué novedades traes de Alto Ala de Fuego?', 0),
(9997, 'esMX', 'Informe. ¿Qué novedades traes de Alto Ala de Fuego?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9996, 9997) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9996, 'esES', 'Es un buen comienzo, pero si tenemos en cuenta lo que viste en el patio y la información que he recibido, ¡hay asuntos mucho más urgentes que resolver!', 0),
(9997, 'esES', 'Es un buen comienzo, pero si tenemos en cuenta lo que viste en el patio y la información que he recibido, ¡hay asuntos mucho más urgentes que resolver!', 0),
(9996, 'esMX', 'Es un buen comienzo, pero si tenemos en cuenta lo que viste en el patio y la información que he recibido, ¡hay asuntos mucho más urgentes que resolver!', 0),
(9997, 'esMX', 'Es un buen comienzo, pero si tenemos en cuenta lo que viste en el patio y la información que he recibido, ¡hay asuntos mucho más urgentes que resolver!', 0);
-- 9997 Ataque en el Alto Ala de Fuego
-- https://es.wowhead.com/quest=9997
SET @ID := 9997;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Informe. ¿Qué novedades traes del Alto Ala de Fuego?', 0),
(@ID, 'esMX', 'Informe. ¿Qué novedades traes del Alto Ala de Fuego?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un buen comienzo, pero si tenemos en cuenta lo que viste en el patio y la información que he recibido, ¡hay asuntos mucho más urgentes que resolver!', 0),
(@ID, 'esMX', 'Es un buen comienzo, pero si tenemos en cuenta lo que viste en el patio y la información que he recibido, ¡hay asuntos mucho más urgentes que resolver!', 0);
-- 9998 Vecinos indisciplinados
-- https://es.wowhead.com/quest=9998
SET @ID := 9998;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que Bertelm te envió para obstaculizar los esfuerzos de los peones.', 0),
(@ID, 'esMX', 'Supongo que Bertelm te envió para obstaculizar los esfuerzos de los peones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El elfo noble asiente.>$B$BEs un buen comienzo y Bertelm ha hecho bien en enviarte a verme. He descubierto algo que podría ayudar a explicar la presencia de los orcos viles aquí.', 0),
(@ID, 'esMX', '<El elfo noble asiente.>$B$BEs un buen comienzo y Bertelm ha hecho bien en enviarte a verme. He descubierto algo que podría ayudar a explicar la presencia de los orcos viles aquí.', 0);
-- 9999 Tiempo extra
-- https://es.wowhead.com/quest=9999
SET @ID := 9999;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto?', 0),
(@ID, 'esMX', '¿Regresaste tan pronto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que sospechaba. No hay ningún método convencional para destruir el acero vil. Sin embargo, no todo está perdido...', 0),
(@ID, 'esMX', 'Lo que sospechaba. No hay ningún método convencional para destruir el acero vil. Sin embargo, no todo está perdido...', 0);
-- 10000 Una presencia inoportuna
-- https://es.wowhead.com/quest=10000
SET @ID := 10000;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estaba a punto de enviar un mensaje a Rokag recomendando un ataque, pero veo que no será necesario.', 0),
(@ID, 'esMX', 'Estaba a punto de enviar un mensaje a Rokag recomendando un ataque, pero veo que no será necesario.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece ser que, para detener a los orcos viles, vamos a necesitar mucho más que simplemente encargarnos de sus trabajadores. He descubierto algo que va a ayudarnos a comprender la razón de su presencia aquí. Además, creo firmemente que tenemos que actuar rápidamente.', 0),
(@ID, 'esMX', 'Parece ser que, para detener a los orcos viles, vamos a necesitar mucho más que simplemente encargarnos de sus trabajadores. He descubierto algo que va a ayudarnos a comprender la razón de su presencia aquí. Además, creo firmemente que tenemos que actuar rápidamente.', 0);
-- 10001 El maestro planificador
-- https://es.wowhead.com/quest=10001
SET @ID := 10001;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Evita a los sobrestantes a toda costa. No puedes permitir que te vean. El resultado podría ser desastroso...', 0),
(@ID, 'esMX', 'Evita a los sobrestantes a toda costa. No puedes permitir que te vean. El resultado podría ser desastroso...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Probablemente mi amigo sepa cómo poder destruir los campamentos. Después de todo fue un ingeniero de la Legión...', 0),
(@ID, 'esMX', 'Probablemente mi amigo sepa cómo poder destruir los campamentos. Después de todo fue un ingeniero de la Legión...', 0);
-- 10002 El contacto Ala de Fuego
-- https://es.wowhead.com/quest=10002
SET @ID := 10002;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La actividad en el campamento sigue aumentando. ¿Has cumplido tu misión?', 0),
(@ID, 'esMX', 'La actividad en el campamento sigue aumentando. ¿Has cumplido tu misión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Theloria asiente.>$B$BBien hecho. Hemos conseguido algo de tiempo extra. Los elfos de sangre se preguntarán qué ha ocurrido con su amiga. Esperemos que, para cuando lo descubran, ya sepamos mejor lo que está pasando.', 0),
(@ID, 'esMX', '<Theloria asiente.>$B$BBien hecho. Hemos conseguido algo de tiempo extra. Los elfos de sangre se preguntarán qué ha ocurrido con su amiga. Esperemos que, para cuando lo descubran, ya sepamos mejor lo que está pasando.', 0);
-- 10003 El contacto Ala de Fuego
-- https://es.wowhead.com/quest=10003
SET @ID := 10003;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuanto más tiempo les permitamos hacer los preparativos, más difícil será erradicarlos. ¿Has matado al enlace?', 0),
(@ID, 'esMX', 'Cuanto más tiempo les permitamos hacer los preparativos, más difícil será erradicarlos. ¿Has matado al enlace?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kaide asiente.>$B$BBien hecho. Hemos conseguido algo de tiempo extra. Los elfos de sangre se preguntarán qué ha ocurrido con su amiga. Esperemos que, para cuando lo descubran, ya sepamos mejor lo que está pasando.$B$BCuando llegue el momento, informaré a Rogak sobre nuestro progreso.', 0),
(@ID, 'esMX', '<Kaide asiente.>$B$BBien hecho. Hemos conseguido algo de tiempo extra. Los elfos de sangre se preguntarán qué ha ocurrido con su amiga. Esperemos que, para cuando lo descubran, ya sepamos mejor lo que está pasando.$B$BCuando llegue el momento, informaré a Rogak sobre nuestro progreso.', 0);
-- 10004 Paciencia y comprensión
-- https://es.wowhead.com/quest=10004
SET @ID := 10004;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Sal\'salabim se frota la frente.>$B$B[Demoníaco] Ik il romath sardon.', 0),
(@ID, 'esMX', '<Sal\'salabim se frota la frente.>$B$B[Demoníaco] Ik il romath sardon.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tranquilízate, ojos brillantes! Sal\'salabim te ayudará.', 0),
(@ID, 'esMX', '¡Tranquilízate, ojos brillantes! Sal\'salabim te ayudará.', 0);
-- Informar al vinculador terrestre Tavgren
-- 10005, 10006
-- https://es.wowhead.com/quest=10005
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10005, 10006) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10005, 'esES', '¡Una bomba de maná puro podría destruir ciudades enteras! Pero, ¿por qué? ¿Por qué harían algo así los elfos de sangre? ¿Por qué lo usarían contra nosotros? El Matorral Cenarion era un lugar de paz y descanso.$B$BLa respuesta a estas preguntas está en la cabeza del celador Treelos y yo no tengo ni idea de cómo curarlo. Quizás su mente sane con el tiempo.$B$BDe todas formas, me gustaría darte las gracias por ayudarme a entender lo que pasó. Solo espero que esto no le vuelva a suceder a nadie nunca más.', 0),
(10006, 'esES', '¡Una bomba de maná puro podría destruir ciudades enteras! Pero, ¿por qué? ¿Por qué harían algo así los elfos de sangre? ¿Por qué lo usarían contra nosotros? El Matorral Cenarion era un lugar de paz y descanso.$B$BLa respuesta a estas preguntas está en la cabeza del celador Treelos y yo no tengo ni idea de cómo curarlo. Quizás su mente sane con el tiempo.$B$BDe todas formas, me gustaría darte las gracias por ayudarme a entender lo que pasó. Solo espero que esto no le vuelva a suceder a nadie nunca más.', 0),
(10005, 'esMX', '¡Una bomba de maná puro podría destruir ciudades enteras! Pero, ¿por qué? ¿Por qué harían algo así los elfos de sangre? ¿Por qué lo usarían contra nosotros? El Matorral Cenarion era un lugar de paz y descanso.$B$BLa respuesta a estas preguntas está en la cabeza del celador Treelos y yo no tengo ni idea de cómo curarlo. Quizás su mente sane con el tiempo.$B$BDe todas formas, me gustaría darte las gracias por ayudarme a entender lo que pasó. Solo espero que esto no le vuelva a suceder a nadie nunca más.', 0),
(10006, 'esMX', '¡Una bomba de maná puro podría destruir ciudades enteras! Pero, ¿por qué? ¿Por qué harían algo así los elfos de sangre? ¿Por qué lo usarían contra nosotros? El Matorral Cenarion era un lugar de paz y descanso.$B$BLa respuesta a estas preguntas está en la cabeza del celador Treelos y yo no tengo ni idea de cómo curarlo. Quizás su mente sane con el tiempo.$B$BDe todas formas, me gustaría darte las gracias por ayudarme a entender lo que pasó. Solo espero que esto no le vuelva a suceder a nadie nunca más.', 0);
-- 10007 Disminuir las filas
-- https://es.wowhead.com/quest=10007
SET @ID := 10007;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tu ataque tuvo éxito?', 0),
(@ID, 'esMX', '¿Tu ataque tuvo éxito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al menos parece que la situación empieza a mejorar. Creo que si podemos evitar que los orcos viles envíen refuerzos a sus compañeros, podremos mantener esta avanzada bajo control.', 0),
(@ID, 'esMX', 'Al menos parece que la situación empieza a mejorar. Creo que si podemos evitar que los orcos viles envíen refuerzos a sus compañeros, podremos mantener esta avanzada bajo control.', 0);
-- 10008 Lo que pasa en Terokkar, se queda en Terokkar
-- https://es.wowhead.com/quest=10008
SET @ID := 10008;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime que no estaba equivocado al confiar en ti con esta misión...', 0),
(@ID, 'esMX', 'Dime que no estaba equivocado al confiar en ti con esta misión...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que has viajado mucho, $n, pero debes entender que algunas historias es mejor que no salgan de donde ocurrieron. ¿Me entiendes?', 0),
(@ID, 'esMX', 'Sé que has viajado mucho, $n, pero debes entender que algunas historias es mejor que no salgan de donde ocurrieron. ¿Me entiendes?', 0);
-- 10009 Aplastar unas calaveras
-- https://es.wowhead.com/quest=10009
SET @ID := 10009;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tú no volver sin oros de Sal\'salabim!', 0),
(@ID, 'esMX', '¡Tú no volver sin oros de Sal\'salabim!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, trato es trato pero cuando Sal\'salabim decir tú, tú no enfadar, ¿sí?', 0),
(@ID, 'esMX', 'Bueno, trato es trato pero cuando Sal\'salabim decir tú, tú no enfadar, ¿sí?', 0);
-- 10010 ¿Es así de fácil?
-- https://es.wowhead.com/quest=10010
SET @ID := 10010;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por supuesto! Utilizaremos sus propias armas contra ellos.', 0),
(@ID, 'esMX', '¡Por supuesto! Utilizaremos sus propias armas contra ellos.', 0);
-- 10011 Campamento Forja: aniquilado
-- https://es.wowhead.com/quest=10011
SET @ID := 10011;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Campamento Forja: Odio destruido', `ObjectiveText2` = 'Campamento Forja: Miedo destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho?', 0),
(@ID, 'esMX', '¿Está hecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hemos ganado! ¡Hemos detenido el avance de la Legión!$B$BPuedes elegir una recompensa por tus heroicas hazañas.', 0),
(@ID, 'esMX', '¡Hemos ganado! ¡Hemos detenido el avance de la Legión!$B$BPuedes elegir una recompensa por tus heroicas hazañas.', 0);
-- 10012 Planos de orcos viles
-- https://es.wowhead.com/quest=10012
SET @ID := 10012;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Bertelm coge los planos y echa un vistazo.>$B$BSi no me hubieras traído este mapa, te diría que te has vuelto loca, pero está muy claro. No solo los orcos viles están aquí para servir a los elfos de sangre, sino que parece ser que les han ordenado mantenernos ocupados.$B$BEste mapa me genera más preguntas que respuestas, pero nos da una mejor idea de lo que tenemos entre manos.', 0),
(@ID, 'esMX', '<Bertelm coge los planos y echa un vistazo.>$B$BSi no me hubieras traído este mapa, te diría que te has vuelto loca, pero está muy claro. No solo los orcos viles están aquí para servir a los elfos de sangre, sino que parece ser que les han ordenado mantenernos ocupados.$B$BEste mapa me genera más preguntas que respuestas, pero nos da una mejor idea de lo que tenemos entre manos.', 0);
-- 10013 Una mano invisible
-- https://es.wowhead.com/quest=10013
SET @ID := 10013;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Rokag coge los planos y echa un vistazo.>$B$B¡Así que Kaide tenía razón! Esa escoria de orcos viles están tramando algo. Nunca habría pensado que fueran a aliarse con los elfos de sangre.$B$BSegún este mapa, los orcos viles tienen que mantenernos ocupados... pero, ¿por qué? Estas noticias me preocupan, $n. Has hecho lo más sensato al traerme los planos inmediatamente.', 0),
(@ID, 'esMX', '<Rokag coge los planos y echa un vistazo.>$B$B¡Así que Kaide tenía razón! Esa escoria de orcos viles están tramando algo. Nunca habría pensado que fueran a aliarse con los elfos de sangre.$B$BSegún este mapa, los orcos viles tienen que mantenernos ocupados... pero, ¿por qué? Estas noticias me preocupan, $n. Has hecho lo más sensato al traerme los planos inmediatamente.', 0);
-- 10015 El proyecto del Alto Ala de Fuego
-- https://es.wowhead.com/quest=10015
SET @ID := 10015;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esos códigos? Viste lo que les pasó a los druidas en Matorral Cenarion.$B$B¿Quieres que le pase eso a Bastión Rompepedras?', 0),
(@ID, 'esMX', '¿Tienes esos códigos? Viste lo que les pasó a los druidas en Matorral Cenarion.$B$B¿Quieres que le pase eso a Bastión Rompepedras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo!$B$BDéjame echar un vistazo a esas hojas de códigos. ¡Tengo una idea y podría ser lo suficientemente loca como para funcionar!', 0),
(@ID, 'esMX', '¡Buen trabajo!$B$BDéjame echar un vistazo a esas hojas de códigos. ¡Tengo una idea y podría ser lo suficientemente loca como para funcionar!', 0);
-- 10016 Colas de huargos grises
-- https://es.wowhead.com/quest=10016
SET @ID := 10016;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has sobrevivido a los peligros del bosque. ¿Me traes alguna cola para mi capa?', 0),
(@ID, 'esMX', 'Veo que has sobrevivido a los peligros del bosque. ¿Me traes alguna cola para mi capa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bien hecho, $gamigo:amiga;. Son mejores de lo que me imaginaba. Haré una capa estupenda.$B$B<Bertelm mira hacia la posada.>$B$BSí, será una buena capa.', 0),
(@ID, 'esMX', 'Ah, bien hecho, $gamigo:amiga;. Son mejores de lo que me imaginaba. Haré una capa estupenda.$B$B<Bertelm mira hacia la posada.>$B$BSí, será una buena capa.', 0);
-- 10017 Cortos de suministros
-- https://es.wowhead.com/quest=10017
SET @ID := 10017;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has obtenido los sacos de veneno, $n? Estos refugiados no pueden esperar mucho más.', 0),
(@ID, 'esMX', '¿Has obtenido los sacos de veneno, $n? Estos refugiados no pueden esperar mucho más.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi agradecimiento, $n. Los Aldor se enterarán de tus acciones.', 0),
(@ID, 'esMX', 'Tienes mi agradecimiento, $n. Los Aldor se enterarán de tus acciones.', 0);
-- 10018 Vestimentas del espíritu lobo
-- https://es.wowhead.com/quest=10018
SET @ID := 10018;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido encontrar todas las pelambres que necesito?', 0),
(@ID, 'esMX', '¿Has conseguido encontrar todas las pelambres que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Son perfectas, $n! No podrían ser mejores.', 0),
(@ID, 'esMX', '¡Son perfectas, $n! No podrían ser mejores.', 0);
-- 10019 Más sacos de veneno
-- https://es.wowhead.com/quest=10019
SET @ID := 10019;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchos refugiados todavía necesitan tratamiento para sus heridas envenenadas. ¿Has traído más sacos de veneno para que los use, $n?', 0),
(@ID, 'esMX', 'Muchos refugiados todavía necesitan tratamiento para sus heridas envenenadas. ¿Has traído más sacos de veneno para que los use, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi agradecimiento, $n. Los naaru han extendido su protección a estas almas desafortunadas; Sería una lástima que llegaran a Shattrath y murieran por heridas anteriores.$B$B<Esta misión se puede repetir hasta la reputación Neutral.>', 0),
(@ID, 'esMX', 'Tienes mi agradecimiento, $n. Los naaru han extendido su protección a estas almas desafortunadas; Sería una lástima que llegaran a Shattrath y murieran por heridas anteriores.$B$B<Esta misión se puede repetir hasta la reputación Neutral.>', 0);
-- 10020 Una cura para Zahlia
-- https://es.wowhead.com/quest=10020
SET @ID := 10020;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has obtenido la sangre, $n? Sin ella, es posible que Zahlia nunca vuelva a ver a su hijo.', 0),
(@ID, 'esMX', '¿Has obtenido la sangre, $n? Sin ella, es posible que Zahlia nunca vuelva a ver a su hijo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Cuidar a los necesitados es una tarea difícil, pero con el tiempo he descubierto que es su propia recompensa.', 0),
(@ID, 'esMX', 'Gracias, $n. Cuidar a los necesitados es una tarea difícil, pero con el tiempo he descubierto que es su propia recompensa.', 0);
-- 10021 Restaurar la Luz
-- https://es.wowhead.com/quest=10021
SET @ID := 10021;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha completado su tarea, $n?', 0),
(@ID, 'esMX', '¿Ha completado su tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi agradecimiento, $n. Somos guardianes de la luz y no podemos abandonar nuestras responsabilidades, incluso en los momentos más difíciles.', 0),
(@ID, 'esMX', 'Tienes mi agradecimiento, $n. Somos guardianes de la luz y no podemos abandonar nuestras responsabilidades, incluso en los momentos más difíciles.', 0);
-- 10022 El esquivo Quijahierro
-- https://es.wowhead.com/quest=10022
SET @ID := 10022;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quijahierro también ha podido contigo? ¿O has conseguido ser más $gastuto:astuta; que nuestro viejo amigo?', 0),
(@ID, 'esMX', '¿Quijahierro también ha podido contigo? ¿O has conseguido ser más $gastuto:astuta; que nuestro viejo amigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me inclino ante tus habilidades, $n. Has demostrado ser $gun gran:una gran; $c.$B$BNo olvidaré que me has ayudado a hacer esta capa. Va a ser única y la llevaré con orgullo.', 0),
(@ID, 'esMX', 'Me inclino ante tus habilidades, $n. Has demostrado ser $gun gran:una gran; $c.$B$BNo olvidaré que me has ayudado a hacer esta capa. Va a ser única y la llevaré con orgullo.', 0);
