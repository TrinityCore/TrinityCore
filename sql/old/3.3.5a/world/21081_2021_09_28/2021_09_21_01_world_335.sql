-- 10542 Mi pipaaa me la robaaaron...
-- https://es.wowhead.com/quest=10542
SET @ID := 10542;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, ¿tienes ya mi pipa de agua y esas cervezas?', 0),
(@ID, 'esMX', 'Hola, ¿tienes ya mi pipa de agua y esas cervezas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¡a eso se refiere T\'chali! Aunque mí no estar seguro de lo que esos ogros poner ahí dentro; olor en la pipa de agua no ser marca de tabaco de T\'chali.$B$BDa igual, T\'chali es feliz. Tan feliz y contento como para pedirte una cosa más.', 0),
(@ID, 'esMX', 'Sí, ¡a eso se refiere T\'chali! Aunque mí no estar seguro de lo que esos ogros poner ahí dentro; olor en la pipa de agua no ser marca de tabaco de T\'chali.$B$BDa igual, T\'chali es feliz. Tan feliz y contento como para pedirte una cosa más.', 0);
-- 10543 Grimnok y Korgaah, ¡voy a por vosotros!
-- https://es.wowhead.com/quest=10543
SET @ID := 10543;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Crees que a T\'chali le gusta ser así? ¡No!$B$BEntonces, ¿ya has reclamado mi venganza? ¿Grimnok y Korgaah están muertos?', 0),
(@ID, 'esMX', '¿Crees que a T\'chali le gusta ser así? ¡No!$B$BEntonces, ¿ya has reclamado mi venganza? ¿Grimnok y Korgaah están muertos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'T\'chali se alegra de que Korgaah y Grimnok Belinato estén criando malvas, como él.$B$BPero la sed de venganza de T\'chali todavía no se ha saciado. ¡Hay algo más que debes hacer!', 0),
(@ID, 'esMX', 'T\'chali se alegra de que Korgaah y Grimnok Belinato estén criando malvas, como él.$B$BPero la sed de venganza de T\'chali todavía no se ha saciado. ¡Hay algo más que debes hacer!', 0);
-- 10544 ¡Una maldición para ambos clanes!
-- https://es.wowhead.com/quest=10544
SET @ID := 10544;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Edificio del Bastión Aguja del Filo maldito', `ObjectiveText2` = 'Edificio de la Avanzada Machacasangre maldito', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'T\'chali no quiere volver a hablar hasta que $n haya usado el fetiche para maldecir los edificios y torres de los clanes Aguja del Filo y Machacasangre.', 0),
(@ID, 'esMX', 'T\'chali no quiere volver a hablar hasta que $n haya usado el fetiche para maldecir los edificios y torres de los clanes Aguja del Filo y Machacasangre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja, ja! ¡Qué dulce es la venganza!$B$BPero T\'chali puede ver que tienes ganas de seguir adelante ahora que le has ayudado a vengarse. Tienes razón, colega... la vida es para vivirla.$B$BMira, T\'chali tiene un montón de cosas buenas en su tumba. ¡Te dejo elegir la que tú quieras!', 0),
(@ID, 'esMX', '¡Ja, ja, ja! ¡Qué dulce es la venganza!$B$BPero T\'chali puede ver que tienes ganas de seguir adelante ahora que le has ayudado a vengarse. Tienes razón, colega... la vida es para vivirla.$B$BMira, T\'chali tiene un montón de cosas buenas en su tumba. ¡Te dejo elegir la que tú quieras!', 0);
-- 10545 La mezcla Aguja del Filo
-- https://es.wowhead.com/quest=10545
SET @ID := 10545;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ogros Aguja del Filo borrachos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuéntale a T\'chali... ¿Ha funcionado la mezcla? ¿Les gustó a los ogros Aguja del Filo?', 0),
(@ID, 'esMX', 'Cuéntale a T\'chali... ¿Ha funcionado la mezcla? ¿Les gustó a los ogros Aguja del Filo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buenas noticias! Esa cerveza nos va a venir muy bien para lo que T\'chali te va a pedir a continuación.', 0),
(@ID, 'esMX', '¡Buenas noticias! Esa cerveza nos va a venir muy bien para lo que T\'chali te va a pedir a continuación.', 0);
-- 10546 Borak, hijo de Oronok
-- https://es.wowhead.com/quest=10546
SET @ID := 10546;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Borak se queda en silencio durante un momento.>$B$BLlevo semanas observando a estos elfos de sangre, intentando descubrir dónde han escondido la tercera parte de la Clave de Condenación.$B$BHasta ahora, no he tenido éxito. Lo único que sé es que Illidan manda a un enviado desde el Templo Oscuro una vez al día.$B$BEste enviado es intocable. Le he seguido durante una semana intentando descubrir cómo separarle de su guardaespaldas. Por desgracia, el guardaespaldas nunca le deja solo.', 0),
(@ID, 'esMX', '<Borak se queda en silencio durante un momento.>$B$BLlevo semanas observando a estos elfos de sangre, intentando descubrir dónde han escondido la tercera parte de la Clave de Condenación.$B$BHasta ahora, no he tenido éxito. Lo único que sé es que Illidan manda a un enviado desde el Templo Oscuro una vez al día.$B$BEste enviado es intocable. Le he seguido durante una semana intentando descubrir cómo separarle de su guardaespaldas. Por desgracia, el guardaespaldas nunca le deja solo.', 0);
-- 10547 Sobre cabezacardos y huevos...
-- https://es.wowhead.com/quest=10547
SET @ID := 10547;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Tobias eleva una ceja.>$B$B¿Cardo de sangre? Nuna había oído hablar de eso... ¿Eres $gun:una; pacifista? Sabes que deberías decírmelo si lo fueses... ¡Tengo mis derechos!', 0),
(@ID, 'esMX', '<Tobias eleva una ceja.>$B$B¿Cardo de sangre? Nuna había oído hablar de eso... ¿Eres $gun:una; pacifista? Sabes que deberías decírmelo si lo fueses... ¡Tengo mis derechos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes un huevo de arakkoa podrido? ¿Y por qué no me lo has dicho antes? Creo que podemos hacer negocios.$B$B<Tobias sonríe, dejando a la vista una dentadura podrida y muy sucia.>', 0),
(@ID, 'esMX', '¿Tienes un huevo de arakkoa podrido? ¿Y por qué no me lo has dicho antes? Creo que podemos hacer negocios.$B$B<Tobias sonríe, dejando a la vista una dentadura podrida y muy sucia.>', 0);
-- 10548 La triste verdad
-- https://es.wowhead.com/quest=10548
SET @ID := 10548;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza de cabezas?', 0),
(@ID, 'esMX', '¿Cómo va la caza de cabezas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh Guau. Eso no es agradable. Estoy segura de que el comerciante lo apreciará más que yo.$B$BComo pago, el comerciante se ofreció a comprar uno de mis artículos especiales para ti, ¡así que elige, cariño!', 0),
(@ID, 'esMX', 'Oh Guau. Eso no es agradable. Estoy segura de que el comerciante lo apreciará más que yo.$B$BComo pago, el comerciante se ofreció a comprar uno de mis artículos especiales para ti, ¡así que elige, cariño!', 0);
-- 10550 El fardo de cardos de sangre
-- https://es.wowhead.com/quest=10550
SET @ID := 10550;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el cardo de sangre?', 0),
(@ID, 'esMX', '¿Tienes el cardo de sangre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien, a poner la trampa!', 0),
(@ID, 'esMX', '¡Bien, a poner la trampa!', 0);
-- 10551 Lealtad hacia los Aldor
-- https://es.wowhead.com/quest=10551
SET @ID := 10551;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes clara tu decisión, $n? Los Aldor te darán la bienvenida como $galiado:aliada;, pero los Arúspices no olvidarán fácilmente tu elección.', 0),
(@ID, 'esMX', '¿Tienes clara tu decisión, $n? Los Aldor te darán la bienvenida como $galiado:aliada;, pero los Arúspices no olvidarán fácilmente tu elección.', 0);
-- 10552 Lealtad a los Arúspices
-- https://es.wowhead.com/quest=10552
SET @ID := 10552;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes clara tu elección, $n? Los Arúspices te darán la bienvenida como $galiado:aliada;, pero los Aldor no olvidarán fácilmente tu decisión.', 0),
(@ID, 'esMX', '¿Tienes clara tu elección, $n? Los Arúspices te darán la bienvenida como $galiado:aliada;, pero los Aldor no olvidarán fácilmente tu decisión.', 0);
-- 10553 Voren'thal el vidente
-- https://es.wowhead.com/quest=10553
SET @ID := 10553;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Khadgar envía $gun nuevo:una nueva; recluta? Te vamos a poner a trabajar, $c.', 0),
(@ID, 'esMX', '¿Khadgar envía $gun nuevo:una nueva; recluta? Te vamos a poner a trabajar, $c.', 0);
-- 10554 Ishanah
-- https://es.tbc.wowhead.com/quest=10554
SET @ID := 10554;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido, $n. Me alegro de oír que has decidido unirte a nosotros en nuestra misión. Que la Luz siempre te proteja.', 0),
(@ID, 'esMX', 'Bienvenido, $n. Me alegro de oír que has decidido unirte a nosotros en nuestra misión. Que la Luz siempre te proteja.', 0);
-- 10555 Malestar
-- https://es.tbc.wowhead.com/quest=10555
SET @ID := 10555;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por los rudimentarios pictogramas de las páginas del libro envejecido, deduces que se necesitarán muchas plumas Lashh\'an para lanzar los hechizos ahí descritos.', 0),
(@ID, 'esMX', 'Por los rudimentarios pictogramas de las páginas del libro envejecido, deduces que se necesitarán muchas plumas Lashh\'an para lanzar los hechizos ahí descritos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hojeando las páginas con notas garabateadas y alargada escritura de los arrakoa Lashh\'an, encuentras una página con un pictograma de los círculos de poder que has visto en Velo Lashh.', 0),
(@ID, 'esMX', 'Hojeando las páginas con notas garabateadas y alargada escritura de los arrakoa Lashh\'an, encuentras una página con un pictograma de los círculos de poder que has visto en Velo Lashh.', 0);
-- 10556 Arañazos
-- https://es.wowhead.com/quest=10556
-- https://es.tbc.wowhead.com/quest=10556
SET @ID := 10556;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Que Daranelle analice el aura de kaliri', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es emocionante! No puedo esperar a estudiar el funcionamiento del hechizo.', 0),
(@ID, 'esMX', '¡Esto es emocionante! No puedo esperar a estudiar el funcionamiento del hechizo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sé qué decir. Este hechizo es muy extraño. No es un simple conjuro o encantamiento, sino algún tipo de hechizo de comunión o comunicación.$B$BNo sé con seguridad qué pensar, $n. Tendré que pensar en ello algo más de tiempo.$B$B¡Pero gracias por tu ayuda de todos modos! Seguro que lo resolveré tarde o temprano.', 0),
(@ID, 'esMX', 'No sé qué decir. Este hechizo es muy extraño. No es un simple conjuro o encantamiento, sino algún tipo de hechizo de comunión o comunicación.$B$BNo sé con seguridad qué pensar, $n. Tendré que pensar en ello algo más de tiempo.$B$B¡Pero gracias por tu ayuda de todos modos! Seguro que lo resolveré tarde o temprano.', 0);
-- 10557 Vuelo de prueba: el Cefirium Capacitorium
-- https://es.tbc.wowhead.com/quest=10557
SET @ID := 10557;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No temas! ¡Esto es por la ciencia, y la ciencia es dolorosa!', 0),
(@ID, 'esMX', '¡No temas! ¡Esto es por la ciencia, y la ciencia es dolorosa!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau, lo has conseguido! ¡Y sin un rasguño ni fractura múltiple! ¡Ves, ya te dije que todo saldría bien!$B$BToma tu paga, $n. Había descontado gastos médicos, pero como no te van a hacer falta... ¡más dinero que te llevas!', 0),
(@ID, 'esMX', '¡Guau, lo has conseguido! ¡Y sin un rasguño ni fractura múltiple! ¡Ves, ya te dije que todo saldría bien!$B$BToma tu paga, $n. Había descontado gastos médicos, pero como no te van a hacer falta... ¡más dinero que te llevas!', 0);
-- 10560 Venerado con Sha'tar
-- https://es.wowhead.com/quest=10560
SET @ID := 10560;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<A\'dal parece estar muy satisfecho contigo. Con tu ayuda, el Castillo de la Tempestad será recuperado algún día de las garras del mal.>', 0),
(@ID, 'esMX', '<A\'dal parece estar muy satisfecho contigo. Con tu ayuda, el Castillo de la Tempestad será recuperado algún día de las garras del mal.>', 0);
-- 10562 ¡Asediados!
-- https://es.wowhead.com/quest=10562
SET @ID := 10562;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás $gcansado:cansada;, $c?', 0),
(@ID, 'esMX', '¿Ya estás $gcansado:cansada;, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por relevar a mis hombres, $n. Con tu ayuda y la de otros, todavía podemos resistir. Desafortunadamente, simplemente resistir no es suficiente. Debemos ir a la ofensiva.', 0),
(@ID, 'esMX', 'Gracias por relevar a mis hombres, $n. Con tu ayuda y la de otros, todavía podemos resistir. Desafortunadamente, simplemente resistir no es suficiente. Debemos ir a la ofensiva.', 0);
-- 10563 Al Bastión de la Legión
-- https://es.tbc.wowhead.com/quest=10563
SET @ID := 10563;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Descubrir los planes de la Legión', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto?', 0),
(@ID, 'esMX', '¿Qué has descubierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El comandante del aire Nuainn escucha tu informe, mientras su alarma aumenta con cada frase.>$B$B¿Así que dices que tienen infernales más que suficientes para intensificar el bombardeo? Si no los detenemos antes de que pongan en marcha la siguiente fase de su plan, el Bastión Martillo Salvaje está acabado.', 0),
(@ID, 'esMX', '<El comandante del aire Nuainn escucha tu informe, mientras su alarma aumenta con cada frase.>$B$B¿Así que dices que tienen infernales más que suficientes para intensificar el bombardeo? Si no los detenemos antes de que pongan en marcha la siguiente fase de su plan, el Bastión Martillo Salvaje está acabado.', 0);
-- 10564 ¡Infernales por los aires!
-- https://es.wowhead.com/quest=10564
SET @ID := 10564;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Destruye infernales del Bastión de la Legión', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado alguna forma de destruir las reservas de infernales de la Legión?', 0),
(@ID, 'esMX', '¿Has encontrado alguna forma de destruir las reservas de infernales de la Legión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Ojalá pudiera decir que la Legión se rendirá después de un revés así, pero tú y yo sabemos que no será así. La Forja Muerta, de la que oíste hablar durante tu misión de reconocimiento, será nuestro próximo objetivo.', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Ojalá pudiera decir que la Legión se rendirá después de un revés así, pero tú y yo sabemos que no será así. La Forja Muerta, de la que oíste hablar durante tu misión de reconocimiento, será nuestro próximo objetivo.', 0);
-- 10565 Las piedras de Vekh'nir
-- https://es.tbc.wowhead.com/quest=10565
SET @ID := 10565;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los arakkoa Vekh\'nir han sido benignos durante muchos años, pero ahora, algo los ha agitado.', 0),
(@ID, 'esMX', 'Los arakkoa Vekh\'nir han sido benignos durante muchos años, pero ahora, algo los ha agitado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, mira cómo brilla! Debo probarlo de inmediato.', 0),
(@ID, 'esMX', '¡Ah, mira cómo brilla! Debo probarlo de inmediato.', 0);
-- 10566 Ensayo y error
-- https://es.tbc.wowhead.com/quest=10566
SET @ID := 10566;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Prueba la primera varita', `ObjectiveText2` = 'Prueba la segunda varita', `ObjectiveText3` = 'Prueba la tercera varita', `ObjectiveText4` = 'Prueba la cuarta varita', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero ansiosamente tus resultados, $N.', 0),
(@ID, 'esMX', 'Espero ansiosamente tus resultados, $N.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta información será muy útil, $n. Refinaré más ese diseño y veré si puedo ampliar su utilidad.', 0),
(@ID, 'esMX', 'Esta información será muy útil, $n. Refinaré más ese diseño y veré si puedo ampliar su utilidad.', 0);
