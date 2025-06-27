-- 10389 La agonía y la oscuridad
-- https://es.wowhead.com/quest=10389
SET @ID := 10389;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, $C, ¿los terroadictos han sido derrotados?', 0),
(@ID, 'esMX', 'Bueno, $C, ¿los terroadictos han sido derrotados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bravo, $n. ¡Sabía que lo conseguirías! ¡Se acerca cada vez más la derrota de la Legión!', 0),
(@ID, 'esMX', 'Bravo, $n. ¡Sabía que lo conseguirías! ¡Se acerca cada vez más la derrota de la Legión!', 0);
-- 10390 Campamento Forja: Mageddon
-- https://es.wowhead.com/quest=10390
SET @ID := 10390;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Apúrate, $c, debemos cerrar el Campamento Forja: Mageddon antes de que los demonios acaben de construirlo!', 0),
(@ID, 'esMX', '¡Apúrate, $c, debemos cerrar el Campamento Forja: Mageddon antes de que los demonios acaben de construirlo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $c, eso es un campamento de forja menos por el que preocuparse. A la Legión le llevará un tiempo que vuelva a estar operativo este centro. Acabas de conseguirnos lo único que se nos había acabado: tiempo.', 0),
(@ID, 'esMX', 'Buen trabajo, $c, eso es un campamento de forja menos por el que preocuparse. A la Legión le llevará un tiempo que vuelva a estar operativo este centro. Acabas de conseguirnos lo único que se nos había acabado: tiempo.', 0);
-- 10391 Cañones de ira
-- https://es.wowhead.com/quest=10391
SET @ID := 10391;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La Legión podría empezar a bombardearnos en cualquier momento, $N! ¡Tienes que destruir esos malditos cañones!', 0),
(@ID, 'esMX', '¡La Legión podría empezar a bombardearnos en cualquier momento, $N! ¡Tienes que destruir esos malditos cañones!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que tenías el talante, $n, ¡pero esta vez te has superado! ¡Hasta aquí se ha oído como explotaban esos cañones! ¡Eso debería enseñar a la Legión a no subestimar a los Hijos de Durotar!', 0),
(@ID, 'esMX', 'Sabía que tenías el talante, $n, ¡pero esta vez te has superado! ¡Hasta aquí se ha oído como explotaban esos cañones! ¡Eso debería enseñar a la Legión a no subestimar a los Hijos de Durotar!', 0);
-- 10392 Una puerta hacia el abismo
-- https://es.wowhead.com/quest=10392
SET @ID := 10392;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Destruye la Puerta de la Legión Ardiente', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Date prisa, $n. ¡Por cada segundo que ese portal de distorsión permanece abierto, entra otro asqueroso demonio en este mundo!', 0),
(@ID, 'esMX', 'Date prisa, $n. ¡Por cada segundo que ese portal de distorsión permanece abierto, entra otro asqueroso demonio en este mundo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alabados sean los ancestros, ¡lo has conseguido, $n! Le has impuesto una grave derrota a la Legión y Thrallmar vuelve a ser segura. Ah, ojalá tuviera un centenar de guerreros con tu corazón y astucia, ¡esta tierra destrozada ya estaría controlada! Me inclino ante ti.$B$B<Nazgrel te saluda tajantemente>', 0),
(@ID, 'esMX', 'Alabados sean los ancestros, ¡lo has conseguido, $n! Le has impuesto una grave derrota a la Legión y Thrallmar vuelve a ser segura. Ah, ojalá tuviera un centenar de guerreros con tu corazón y astucia, ¡esta tierra destrozada ya estaría controlada! Me inclino ante ti.$B$B<Nazgrel te saluda tajantemente>', 0);
-- 10393 Planes malvados
-- https://es.wowhead.com/quest=10393
SET @ID := 10393;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tengo tiempo que perder, $c. ¿Qué minucias me traes ahora?', 0),
(@ID, 'esMX', 'No tengo tiempo que perder, $c. ¿Qué minucias me traes ahora?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho bien en contármelo. Podría ser un pedido para producir más atracadores viles ¡o nuevos planes de ataque! Llevará algún tiempo descifrarlo. Déjame. Te citaré cuando sepa algo más.$B$B<El magister Halcón de sangre te saluda con la cabeza al marcharte.>$B$BHas demostrado agudeza, $n. Estaré pendiente de tu evolución.', 0),
(@ID, 'esMX', 'Has hecho bien en contármelo. Podría ser un pedido para producir más atracadores viles ¡o nuevos planes de ataque! Llevará algún tiempo descifrarlo. Déjame. Te citaré cuando sepa algo más.$B$B<El magister Halcón de sangre te saluda con la cabeza al marcharte.>$B$BHas demostrado agudeza, $n. Estaré pendiente de tu evolución.', 0);
-- 10394 Desbarajuste en el Campamento Forja: Mageddon
-- https://es.wowhead.com/quest=10394
SET @ID := 10394;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No me digas que te estás enfriando, $C? Si terminan la construcción de ese campamento de forja, ¡tendrás más de qué preocuparte que solo de esos atracadores viles! ¡Hazlo!', 0),
(@ID, 'esMX', '¿No me digas que te estás enfriando, $C? Si terminan la construcción de ese campamento de forja, ¡tendrás más de qué preocuparte que solo de esos atracadores viles! ¡Hazlo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, debo admitir que estoy impresionado, $n. No creí que tuvieras el temple necesario para esta misión. Muy bien. Pero que muy bien.', 0),
(@ID, 'esMX', 'Vaya, debo admitir que estoy impresionado, $n. No creí que tuvieras el temple necesario para esta misión. Muy bien. Pero que muy bien.', 0);
-- 10395 La oscura misiva
-- https://es.wowhead.com/quest=10395
SET @ID := 10395;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué quieres, $c? Presiento que has encontrado algo que tiene que ver con un desastre próximo.', 0),
(@ID, 'esMX', '¿Qué quieres, $c? Presiento que has encontrado algo que tiene que ver con un desastre próximo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha sido una casualidad que interceptaras esta misiva cuando lo hiciste, $n. Aunque me llevará algún tiempo descifrarla, ya puedo sentir el odio y la urgencia que este pergamino encierra. Me temo que los verdaderos motivos de la presencia de la Legión en esta tierra no tardarán en revelarse...$B$BDame unos minutos para descifrar la misiva.$B$B<Arúspice de distorsión Kryv comienza a leer la misiva demoníaca>', 0),
(@ID, 'esMX', 'Ha sido una casualidad que interceptaras esta misiva cuando lo hiciste, $n. Aunque me llevará algún tiempo descifrarla, ya puedo sentir el odio y la urgencia que este pergamino encierra. Me temo que los verdaderos motivos de la presencia de la Legión en esta tierra no tardarán en revelarse...$B$BDame unos minutos para descifrar la misiva.$B$B<Arúspice de distorsión Kryv comienza a leer la misiva demoníaca>', 0);
-- 10396 Enemigo de mi enemigo...
-- https://es.wowhead.com/quest=10396
SET @ID := 10396;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La Legión podría comenzar a bombardear a la Horda en cualquier momento, $N! ¡Tienes que destruir esos malditos cañones!', 0),
(@ID, 'esMX', '¡La Legión podría comenzar a bombardear a la Horda en cualquier momento, $N! ¡Tienes que destruir esos malditos cañones!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo reconocerlo, $n, ¡eres $gun luchador nato:una luchadora nata;! Puede que esos palurdos de la Horda no sepan nunca lo cerca que estuvieron del fin. Hace falta un carácter fuerte para arriesgarse en nombre de tus enemigos. ¡Esa es la clase de honor y compromiso que sostiene la Alianza!$B$B<Mariscal de campo Brock te saluda tajantemente.>', 0),
(@ID, 'esMX', 'Debo reconocerlo, $n, ¡eres $gun luchador nato:una luchadora nata;! Puede que esos palurdos de la Horda no sepan nunca lo cerca que estuvieron del fin. Hace falta un carácter fuerte para arriesgarse en nombre de tus enemigos. ¡Esa es la clase de honor y compromiso que sostiene la Alianza!$B$B<Mariscal de campo Brock te saluda tajantemente.>', 0);
-- 10397 Punto de invasión: Aniquilador
-- https://es.wowhead.com/quest=10397
SET @ID := 10397;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Destruye la Puerta de la Legión Ardiente', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has cerrado ya ese portal de distorsión, $n? Mientras estiras las piernas, ¡entran cada vez más demonios en Terrallende!', 0),
(@ID, 'esMX', '¿Has cerrado ya ese portal de distorsión, $n? Mientras estiras las piernas, ¡entran cada vez más demonios en Terrallende!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente trabajo! Eso debería reducir drásticamente la cantidad de demonios que intentan subírsenos a la espalda. Me faltan palabras para expresar mi gratitud, $n.', 0),
(@ID, 'esMX', '¡Excelente trabajo! Eso debería reducir drásticamente la cantidad de demonios que intentan subírsenos a la espalda. Me faltan palabras para expresar mi gratitud, $n.', 0);
-- 10399 El corazón de la oscuridad
-- https://es.wowhead.com/quest=10399
SET @ID := 10399;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento una creciente oscuridad dentro de tu corazón, $C. ¿Has enfrentado tu miedo? ¿O todavía te espera en las Pozas de Aggonar?', 0),
(@ID, 'esMX', 'Siento una creciente oscuridad dentro de tu corazón, $C. ¿Has enfrentado tu miedo? ¿O todavía te espera en las Pozas de Aggonar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Había previsto esta gran victoria, $n. En este día los benditos naaru te contemplan con regocijo.', 0),
(@ID, 'esMX', 'Había previsto esta gran victoria, $n. En este día los benditos naaru te contemplan con regocijo.', 0);
-- 10400 Señor Supremo
-- https://es.wowhead.com/quest=10400
SET @ID := 10400;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $N, ¿se ha hecho justicia? ¿Ha sido derrotado el señor de la legión?', 0),
(@ID, 'esMX', 'Dime, $N, ¿se ha hecho justicia? ¿Ha sido derrotado el señor de la legión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alabada sea la Luz, ¡sabía que lo conseguirías! ¡Arazzius y sus esbirros ya no nos molestarán! Pronto la Legión saldrá huyendo y este castigado mundo volverá a ser seguro. Entonces, cuando se haya hecho justicia, también podremos volver a casa.$B$BGracias, $n, ¡en este día la Alianza y los Hijos de Lothar te honran!', 0),
(@ID, 'esMX', 'Alabada sea la Luz, ¡sabía que lo conseguirías! ¡Arazzius y sus esbirros ya no nos molestarán! Pronto la Legión saldrá huyendo y este castigado mundo volverá a ser seguro. Entonces, cuando se haya hecho justicia, también podremos volver a casa.$B$BGracias, $n, ¡en este día la Alianza y los Hijos de Lothar te honran!', 0);
-- 10403 Naladu
-- https://es.wowhead.com/quest=10403
SET @ID := 10403;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido para ayudar a mi tribu, $r? Qué insólito. Escasean los que se preocupan por el destino de los Tábidos en esta tierra.', 0),
(@ID, 'esMX', '¿Has venido para ayudar a mi tribu, $r? Qué insólito. Escasean los que se preocupan por el destino de los Tábidos en esta tierra.', 0);
-- 10404 Contra la Legión
-- https://es.wowhead.com/quest=10404
SET @ID := 10404;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Le diste un gran golpe a los enemigos de la Luz, $N. Tienes mi agradecimiento así como el de los Aldor.', 0),
(@ID, 'esMX', 'Le diste un gran golpe a los enemigos de la Luz, $N. Tienes mi agradecimiento así como el de los Aldor.', 0);
-- 10405 S-A-B-O-T-A-J-E
-- https://es.wowhead.com/quest=10405
SET @ID := 10405;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado el vendaje?', 0),
(@ID, 'esMX', '¿Has recuperado el vendaje?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Bien, ahora para calibrar el instrumento...', 0),
(@ID, 'esMX', '¡Excelente! Bien, ahora para calibrar el instrumento...', 0);
-- 10406 Entregar el mensaje
-- https://es.wowhead.com/quest=10406
SET @ID := 10406;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Debes tener éxito!', 0),
(@ID, 'esMX', '¡Debes tener éxito!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a ti, ¡sus planes se han ido al traste! Solo queda un detalle... Salhadaar.', 0),
(@ID, 'esMX', 'Gracias a ti, ¡sus planes se han ido al traste! Solo queda un detalle... Salhadaar.', 0);
-- 10407 La sombra de Socrethar
-- https://es.wowhead.com/quest=10407
SET @ID := 10407;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la piedra de teletransporte de Socrethar, $n?', 0),
(@ID, 'esMX', '¿Has conseguido la piedra de teletransporte de Socrethar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu entrega a nuestra causa es ejemplar, $n. Ahora que la piedra de teletransporte de Socrethar obra en nuestro poder, solo nos falta una cosa por hacer.', 0),
(@ID, 'esMX', 'Tu entrega a nuestra causa es ejemplar, $n. Ahora que la piedra de teletransporte de Socrethar obra en nuestro poder, solo nos falta una cosa por hacer.', 0);
-- 10408 El rey-nexo Salhadaar
-- https://es.wowhead.com/quest=10408
SET @ID := 10408;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está... de verdad está muerto? ¿Destruido?', 0),
(@ID, 'esMX', '¿Está... de verdad está muerto? ¿Destruido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace unos mil años, tal vez más, que Salhadaar empezó su cruzada para exterminar todo lo que se interpusiera en su camino. Apenas puedo creer que ya no lo veremos más... Nos has prestado un gran servicio, $n, y recibirás justa recompensa por ello.', 0),
(@ID, 'esMX', 'Hace unos mil años, tal vez más, que Salhadaar empezó su cruzada para exterminar todo lo que se interpusiera en su camino. Apenas puedo creer que ya no lo veremos más... Nos has prestado un gran servicio, $n, y recibirás justa recompensa por ello.', 0);
-- 10409 Golpe mortal a la Legión
-- https://es.wowhead.com/quest=10409
SET @ID := 10409;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La luz esté contigo, $C.', 0),
(@ID, 'esMX', 'La luz esté contigo, $C.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya está, $n. Socrethar ha sido destruido.$B$BNos repondremos de nuestras heridas, $n. Sin embargo, la cólera de la magia de Socrethar fue más de lo que el joven Kaylaan podía soportar. Ni mis más fervientes oraciones han podido devolvérnoslo.$B$BMe causa un insoportable dolor que alguien tan joven cayera en la batalla. Pero al final su voluntad fue lo suficientemente fuerte para recuperarse de la corrupción de la Legión y debemos hallar consuelo en esto.', 0),
(@ID, 'esMX', 'Ya está, $n. Socrethar ha sido destruido.$B$BNos repondremos de nuestras heridas, $n. Sin embargo, la cólera de la magia de Socrethar fue más de lo que el joven Kaylaan podía soportar. Ni mis más fervientes oraciones han podido devolvérnoslo.$B$BMe causa un insoportable dolor que alguien tan joven cayera en la batalla. Pero al final su voluntad fue lo suficientemente fuerte para recuperarse de la corrupción de la Legión y debemos hallar consuelo en esto.', 0);
-- 10410 La ayuda de Ishanah
-- https://es.wowhead.com/quest=10410
SET @ID := 10410;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te inquieta, criatura?', 0),
(@ID, 'esMX', '¿Qué te inquieta, criatura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Socrethar... Recuerdo ese nombre. Fue otrora un afamado guerrero de la Luz y solo pecaba de orgulloso.', 0),
(@ID, 'esMX', 'Socrethar... Recuerdo ese nombre. Fue otrora un afamado guerrero de la Luz y solo pecaba de orgulloso.', 0);
-- 10411 ¡Divino electrochoque!
-- https://es.wowhead.com/quest=10411
SET @ID := 10411;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tanto el lodo como el residuo son extremadamente tóxicos. Si se descuidan, ¡formarán un moco de horror de vacío cuajado!', 0),
(@ID, 'esMX', 'Tanto el lodo como el residuo son extremadamente tóxicos. Si se descuidan, ¡formarán un moco de horror de vacío cuajado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no sea demasiado tarde. ¿Te fijaste en si había babosas más grandes de lo normal por la zona donde se vierten los residuos de vacío?', 0),
(@ID, 'esMX', 'Espero que no sea demasiado tarde. ¿Te fijaste en si había babosas más grandes de lo normal por la zona donde se vierten los residuos de vacío?', 0);
