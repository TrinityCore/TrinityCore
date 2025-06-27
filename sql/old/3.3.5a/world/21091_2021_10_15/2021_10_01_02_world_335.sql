-- 10567 Crear el colgante
-- https://es.tbc.wowhead.com/quest=10567
SET @ID := 10567;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En cuanto el presagista perciba tu ataque, responderá rápidamente.', 0),
(@ID, 'esMX', 'En cuanto el presagista perciba tu ataque, responderá rápidamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo tienes!$B$BCon este colgante, podré acercarte a los arakkoa de Grishnath tanto que hasta podrás entender su idioma.$B$BCon esto, comprenderemos mejor a los arakkoa y la naturaleza del Cuervo. Voy a necesitar tu ayuda.', 0),
(@ID, 'esMX', '¡Lo tienes!$B$BCon este colgante, podré acercarte a los arakkoa de Grishnath tanto que hasta podrás entender su idioma.$B$BCon esto, comprenderemos mejor a los arakkoa y la naturaleza del Cuervo. Voy a necesitar tu ayuda.', 0);
-- Las tablillas de Baa'ri
-- 10568, 10683
-- https://es.tbc.wowhead.com/quest=10568
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10568, 10683) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10568, 'esES', '¿Has encontrado las tablillas, $n?', 0),
(10683, 'esES', '¿Has encontrado las tablillas, $n?', 0),
(10568, 'esMX', '¿Has encontrado las tablillas, $n?', 0),
(10683, 'esMX', '¿Has encontrado las tablillas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10568, 10683) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10568, 'esES', '¡Las tablillas Baa\'ri! Sí, gracias a ellas podríamos conseguir información muy útil.', 0),
(10683, 'esES', '¡Las tablillas Baa\'ri! Sí, gracias a ellas podríamos conseguir información muy útil.', 0),
(10568, 'esMX', '¡Las tablillas Baa\'ri! Sí, gracias a ellas podríamos conseguir información muy útil.', 0),
(10683, 'esMX', '¡Las tablillas Baa\'ri! Sí, gracias a ellas podríamos conseguir información muy útil.', 0);
-- 10569 Las Ruinas de Sketh'lon
-- https://es.tbc.wowhead.com/quest=10569
SET @ID := 10569;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto?', 0),
(@ID, 'esMX', '¿Qué has descubierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kieran hojea las páginas del diario.>$B$BLa mayoría es ininteligible, pero más o menos habla de preparaciones para un hechizo que salió mal, víctimas y de situación que se deteriora. También hay una curiosa nota sobre un \'desertor\'.', 0),
(@ID, 'esMX', '<Kieran hojea las páginas del diario.>$B$BLa mayoría es ininteligible, pero más o menos habla de preparaciones para un hechizo que salió mal, víctimas y de situación que se deteriora. También hay una curiosa nota sobre un \'desertor\'.', 0);
-- 10570 Perder la cabeza... por unos cardos
-- https://es.tbc.wowhead.com/quest=10570
SET @ID := 10570;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé breve, $gmuchacho:muchacha;.', 0),
(@ID, 'esMX', 'Sé breve, $gmuchacho:muchacha;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Borak toma la misiva que le das y empieza a leerla.>$B$B¡Vaya unos listillos! Es una directiva de Illidan que ordena dónde hay que ocultar la clave después. Al parecer, la trasladan constantemente. Y no nos dice su ubicación actual... Si pudiéramos entregar la misiva ahora que conocemos la siguiente ubicación.$B$BLástima que el sello esté roto, ahora es inservible.$B$BMmm... Aunque...', 0),
(@ID, 'esMX', '<Borak toma la misiva que le das y empieza a leerla.>$B$B¡Vaya unos listillos! Es una directiva de Illidan que ordena dónde hay que ocultar la clave después. Al parecer, la trasladan constantemente. Y no nos dice su ubicación actual... Si pudiéramos entregar la misiva ahora que conocemos la siguiente ubicación.$B$BLástima que el sello esté roto, ahora es inservible.$B$BMmm... Aunque...', 0);
-- 10571 Oronu el Anciano
-- https://es.tbc.wowhead.com/quest=10571
SET @ID := 10571;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna novedad, $n? El tiempo apremia.', 0),
(@ID, 'esMX', '¿Alguna novedad, $n? El tiempo apremia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es la mismísima letra de Akama. Es una verdadera pena lo que le ha ocurrido a alguien tan sabio y querido como él.', 0),
(@ID, 'esMX', 'Es la mismísima letra de Akama. Es una verdadera pena lo que le ha ocurrido a alguien tan sabio y querido como él.', 0);
-- 10572 Preparación de la bomba
-- https://es.tbc.wowhead.com/quest=10572
SET @ID := 10572;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Le das los materiales al comandante del aire.>', 0),
(@ID, 'esMX', '<Le das los materiales al comandante del aire.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El comandante del aire inserta la batería en las placas de armadura y sella el dispositivo, asintiendo.>$B$BAquello debería funcionar. También debería provocar una explosión bastante grande, si se me permite decirlo.', 0),
(@ID, 'esMX', '<El comandante del aire inserta la batería en las placas de armadura y sella el dispositivo, asintiendo.>$B$BAquello debería funcionar. También debería provocar una explosión bastante grande, si se me permite decirlo.', 0);
-- 10573 La Forja Muerta
-- https://es.tbc.wowhead.com/quest=10573
SET @ID := 10573;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El enano asiente con la cabeza.>$B$BEstará bien contar con ese respaldo. Hemos reunido información sobre lo que puede estar tramando el Consejo de la Sombra allí pero estaré más tranquilo si podemos empezar ya a tomar represalias.', 0),
(@ID, 'esMX', '<El enano asiente con la cabeza.>$B$BEstará bien contar con ese respaldo. Hemos reunido información sobre lo que puede estar tramando el Consejo de la Sombra allí pero estaré más tranquilo si podemos empezar ya a tomar represalias.', 0);
-- 10574 Los corruptores Lengua de Ceniza
-- https://es.tbc.wowhead.com/quest=10574
SET @ID := 10574;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los 4 trozos del medallón, $n?', 0),
(@ID, 'esMX', '¿Has conseguido los 4 trozos del medallón, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! Los 4 trozos del medallón. Ahora a unirlos...', 0),
(@ID, 'esMX', '¡Eso es! Los 4 trozos del medallón. Ahora a unirlos...', 0);
-- 10575 La Jaula de la Guardiana
-- https://es.tbc.wowhead.com/quest=10575
SET @ID := 10575;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te esperábamos, $n. Akama dijo que vendrías tarde o temprano.', 0),
(@ID, 'esMX', 'Te esperábamos, $n. Akama dijo que vendrías tarde o temprano.', 0);
-- 10576 Revuelo en Sombraluna
-- https://es.tbc.wowhead.com/quest=10576
SET @ID := 10576;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es demasiado complicado, $r. No lo entenderías.', 0),
(@ID, 'esMX', 'Es demasiado complicado, $r. No lo entenderías.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Espero que como actor seas igual de excelente. ¡El próximo paso de mi gran plan va a requerir algo de teatro!', 0),
(@ID, 'esMX', 'Muy bien, $n. Espero que como actor seas igual de excelente. ¡El próximo paso de mi gran plan va a requerir algo de teatro!', 0);
-- 10577 Lo que Illidan quiere, lo consigue...
-- https://es.tbc.wowhead.com/quest=10577
SET @ID := 10577;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El disfraz es delicado. Casi cualquier acción, además de caminar, interrumpirá la magia que lo mantiene unido.', 0),
(@ID, 'esMX', 'El disfraz es delicado. Casi cualquier acción, además de caminar, interrumpirá la magia que lo mantiene unido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora solo tienes que conseguir el código. Fácil, ¿no?', 0),
(@ID, 'esMX', 'Ahora solo tienes que conseguir el código. Fácil, ¿no?', 0);
-- 10578 La Clave de Condenación: La carga de Borak
-- https://es.tbc.wowhead.com/quest=10578
SET @ID := 10578;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Debes actuar sin perder un minuto!', 0),
(@ID, 'esMX', '¡Debes actuar sin perder un minuto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! ¡El fragmento del código es nuestro!$B$B<Borak coloca el fragmento en una caja.>', 0),
(@ID, 'esMX', '¡Por fin! ¡El fragmento del código es nuestro!$B$B<Borak coloca el fragmento en una caja.>', 0);
-- 10579 La Clave de Condenación: Tercer trozo recuperado
-- https://es.tbc.wowhead.com/quest=10579
SET @ID := 10579;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n!', 0),
(@ID, 'esMX', '¡$n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En cuanto los 3 fragmentos de la clave se junten, se conocerán las antiguas palabras.$B$BRecuperar este fragmento ha tenido que ser todo un reto. Mereces una recompensa por semejante heroísmo.', 0),
(@ID, 'esMX', 'En cuanto los 3 fragmentos de la clave se junten, se conocerán las antiguas palabras.$B$BRecuperar este fragmento ha tenido que ser todo un reto. Mereces una recompensa por semejante heroísmo.', 0);
-- 10580 ¿Dónde se han metido esos malditos gnomos?
-- https://es.wowhead.com/quest=10580
SET @ID := 10580;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿SYLVANAAR? ¿EL COMANDANTE CIELOSOMBRA?$B$B¡ESTO NO COMPUTA!$B$B¡VETE ANTES DE QUE ME VEA OBLIGADO A TOCARTE SONIDOS ALTOS!', 0),
(@ID, 'esMX', '¿SYLVANAAR? ¿EL COMANDANTE CIELOSOMBRA?$B$B¡ESTO NO COMPUTA!$B$B¡VETE ANTES DE QUE ME VEA OBLIGADO A TOCARTE SONIDOS ALTOS!', 0);
-- 10581 Sigue el rastro
-- https://es.wowhead.com/quest=10581
SET @ID := 10581;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vale, ¿conque quieres echar una mano? Bien, tengo justo lo que te hace falta para demostrar tu valía.$B$BCreo que te gustará.', 0),
(@ID, 'esMX', 'Vale, ¿conque quieres echar una mano? Bien, tengo justo lo que te hace falta para demostrar tu valía.$B$BCreo que te gustará.', 0);
-- 10582 Esbirros del Consejo de la Sombra
-- https://es.wowhead.com/quest=10582
SET @ID := 10582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya abriste un camino hacia la Forja Muerta?', 0),
(@ID, 'esMX', '¿Ya abriste un camino hacia la Forja Muerta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ojalá hubiera podido ir contigo! Echo de menos algo de acción con mi martillo pero mi misión es observar, no matar.$B$BAhora que has abierto un hueco en sus defensas, nos concentraremos en cerrar su línea de producción de La Forja Muerta.', 0),
(@ID, 'esMX', '¡Ojalá hubiera podido ir contigo! Echo de menos algo de acción con mi martillo pero mi misión es observar, no matar.$B$BAhora que has abierto un hueco en sus defensas, nos concentraremos en cerrar su línea de producción de La Forja Muerta.', 0);
-- 10583 El destino de Flanis
-- https://es.tbc.wowhead.com/quest=10583
SET @ID := 10583;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algún rastro de Flanis en La Forja Muerta?', 0),
(@ID, 'esMX', '¿Has encontrado algún rastro de Flanis en La Forja Muerta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ewan sacude la cabeza al tomar la talega que le entregas.>$B$BNo creo que Flanis se diera cuenta de lo fuertemente vigilada que estaría La Forja Muerta. Ahora que sabemos a qué se dedican allí, no me extraña. Ojalá Flanis lo hubiera sabido cuando entró.$B$BSolo espero que aquí dentro haya algo que nos ayude a cerrar La Forja Muerta de una vez por todas.', 0),
(@ID, 'esMX', '<Ewan sacude la cabeza al tomar la talega que le entregas.>$B$BNo creo que Flanis se diera cuenta de lo fuertemente vigilada que estaría La Forja Muerta. Ahora que sabemos a qué se dedican allí, no me extraña. Ojalá Flanis lo hubiera sabido cuando entró.$B$BSolo espero que aquí dentro haya algo que nos ayude a cerrar La Forja Muerta de una vez por todas.', 0);
-- 10584 Recoger transformadores de energía
-- https://es.tbc.wowhead.com/quest=10584
SET @ID := 10584;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Electromentales recolectados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta línea de investigación que seguimos con los electromentales es interesantísima! Imagínate... criaturas eléctricas inteligentes que podemos crear a nuestro antojo ¡y que obedecerán todas nuestras órdenes!$B$B¿Qué podría salir mal?', 0),
(@ID, 'esMX', '¡Esta línea de investigación que seguimos con los electromentales es interesantísima! Imagínate... criaturas eléctricas inteligentes que podemos crear a nuestro antojo ¡y que obedecerán todas nuestras órdenes!$B$B¿Qué podría salir mal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Con todo este poder que has recuperado podremos mantener la maquinaria funcionando una temporada.$B$B¡El Cefirium Capacitorium es una auténtica ruina en cuanto al consumo!$B$BEspero que no fuera demasiado difícil ocuparte de esos electromentales. Estoy pensando en otra cosa de la que podrías encargarte y me parece que podría ser un poco más peligroso.', 0),
(@ID, 'esMX', '¡Excelente! Con todo este poder que has recuperado podremos mantener la maquinaria funcionando una temporada.$B$B¡El Cefirium Capacitorium es una auténtica ruina en cuanto al consumo!$B$BEspero que no fuera demasiado difícil ocuparte de esos electromentales. Estoy pensando en otra cosa de la que podrías encargarte y me parece que podría ser un poco más peligroso.', 0);
-- 10585 La cámara de invocación
-- https://es.wowhead.com/quest=10585
SET @ID := 10585;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Acaba con el ritual de invocacin infernal', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos permitir que sigan con la producción. ¿Has puesto fin al ritual de invocación?', 0),
(@ID, 'esMX', 'No podemos permitir que sigan con la producción. ¿Has puesto fin al ritual de invocación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Al interrumpir la invocación del Consejo de la Sombra nos acercamos al cierre de La Forja Muerta.', 0),
(@ID, 'esMX', 'Muy bien, $n. Al interrumpir la invocación del Consejo de la Sombra nos acercamos al cierre de La Forja Muerta.', 0);
-- 10586 ¡Tumba al belisario!
-- https://es.wowhead.com/quest=10586
SET @ID := 10586;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes de La Forja Muerta?', 0),
(@ID, 'esMX', '¿Qué noticias traes de La Forja Muerta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Informas al comandante del aire y le entregas las órdenes interceptadas.>$B$BLa derrota del belisario Razuun debería suponer el final de nuestros problemas con la Legión pero según estas órdenes, su plan tiene mucho más alcance de lo que pensaba. Me temo que aún nos queda trabajo.', 0),
(@ID, 'esMX', '<Informas al comandante del aire y le entregas las órdenes interceptadas.>$B$BLa derrota del belisario Razuun debería suponer el final de nuestros problemas con la Legión pero según estas órdenes, su plan tiene mucho más alcance de lo que pensaba. Me temo que aún nos queda trabajo.', 0);
-- 10587 Patio de Armas de Karabor
-- https://es.tbc.wowhead.com/quest=10587
SET @ID := 10587;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te encargué, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te encargué, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Examinemos estas armas, $n. Mmmm... Esto es bastante preocupante.', 0),
(@ID, 'esMX', 'Examinemos estas armas, $n. Mmmm... Esto es bastante preocupante.', 0);
