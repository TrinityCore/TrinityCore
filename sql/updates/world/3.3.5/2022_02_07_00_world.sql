-- 10808 Frustra los planes del Cónclave
-- https://es.tbc.wowhead.com/quest=10808
SET @ID := 10808;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Acabar con el ritual de invocación del Cónclave Oscuro', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 10810 La máscara dañada
-- https://es.tbc.wowhead.com/quest=10810
SET @ID := 10810;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No me molestes! ¿No ves que estoy intentando liberar mis poderes misteriosos?', 0),
(@ID, 'esMX', '¡No me molestes! ¿No ves que estoy intentando liberar mis poderes misteriosos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿qué tienes ahí? Déjame verlo más de cerca, $c.Sí, sí... Es justo lo que pensaba que era. Déjame arreglar esta máscara.', 0),
(@ID, 'esMX', 'Ah, ¿qué tienes ahí? Déjame verlo más de cerca, $c.Sí, sí... Es justo lo que pensaba que era. Déjame arreglar esta máscara.', 0);
-- 10811 Buscar a Neltharaku
-- https://es.tbc.wowhead.com/quest=10811
SET @ID := 10811;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis hijos me han contado tus hazañas, $r. Todavía puedes hacer más.', 0),
(@ID, 'esMX', 'Mis hijos me han contado tus hazañas, $r. Todavía puedes hacer más.', 0);
-- 10812 La máscara misteriosa
-- https://es.tbc.wowhead.com/quest=10812
SET @ID := 10812;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo creer lo que ven mis ojos.', 0),
(@ID, 'esMX', 'No puedo creer lo que ven mis ojos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La máscara que tienes es una máscara de gas Jurapenas, y al parecer está en buen estado. Con ella podremos causar muchos problemas en Campamento Forja: Inquina. ¿Te interesa ayudarnos, $n?', 0),
(@ID, 'esMX', 'La máscara que tienes es una máscara de gas Jurapenas, y al parecer está en buen estado. Con ella podremos causar muchos problemas en Campamento Forja: Inquina. ¿Te interesa ayudarnos, $n?', 0);
-- 10813 Los ojos de Grillok
-- https://es.wowhead.com/quest=10813
SET @ID := 10813;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ojo de Grillok devuelto', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los orcos del clan Foso Sangrante fueron oscuros aliados hace tiempo... Ahora son enemigos todavía más oscuros.', 0),
(@ID, 'esMX', 'Los orcos del clan Foso Sangrante fueron oscuros aliados hace tiempo... Ahora son enemigos todavía más oscuros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy en deuda contigo, $n. Te has vuelto a adentrar en Zeth\'Gor y su oscuridad ha rozado tu corazón. Estudiaré el ojo y puede que comprenda los secretos de su maestro, Grillok.$B$B¡Esperemos que no pueda usar su magia!', 0),
(@ID, 'esMX', 'Estoy en deuda contigo, $n. Te has vuelto a adentrar en Zeth\'Gor y su oscuridad ha rozado tu corazón. Estudiaré el ojo y puede que comprenda los secretos de su maestro, Grillok.$B$B¡Esperemos que no pueda usar su magia!', 0);
-- 10814 La historia de Neltharaku
-- https://es.wowhead.com/quest=10814
SET @ID := 10814;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Permíteme terminar de contarl mi historia.', 0),
(@ID, 'esMX', 'Permíteme terminar de contarl mi historia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces nos ayudarás?', 0),
(@ID, 'esMX', '¿Entonces nos ayudarás?', 0);
-- 10816 Reclamar los terrenos sagrados
-- https://es.wowhead.com/quest=10816
SET @ID := 10816;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Salve, $n. ¿Qué novedades traes?', 0),
(@ID, 'esMX', 'Salve, $n. ¿Qué novedades traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo excelente, $c. Que la Luz siga protegiéndote.', 0),
(@ID, 'esMX', 'Un trabajo excelente, $c. Que la Luz siga protegiéndote.', 0);
-- 10817 El gran castigo
-- https://es.tbc.wowhead.com/quest=10817
SET @ID := 10817;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Salve, $n. ¿Qué novedades traes?', 0),
(@ID, 'esMX', 'Salve, $n. ¿Qué novedades traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy te has ganado mi respeto, $n.$B$BMatar a un orco vil no es tarea fácil. Masacrar a muchos de ellos es... heroico.', 0),
(@ID, 'esMX', 'Hoy te has ganado mi respeto, $n.$B$BMatar a un orco vil no es tarea fácil. Masacrar a muchos de ellos es... heroico.', 0);
-- 10818 El Barón Sablecrín ha solicitado tu presencia
-- https://es.wowhead.com/quest=10818
SET @ID := 10818;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, veo que has decidido tomarte tu tiempo para responder a mi llamada.$B$BNo importa, tengo mucho tiempo para ejecutar mi venganza, ¡y mi intención es que seas mi $gapoderado:apoderada; en la próxima batalla!', 0),
(@ID, 'esMX', 'Ah, veo que has decidido tomarte tu tiempo para responder a mi llamada.$B$BNo importa, tengo mucho tiempo para ejecutar mi venganza, ¡y mi intención es que seas mi $gapoderado:apoderada; en la próxima batalla!', 0);
-- 10819 La máscara de gas jurapenas
-- https://es.wowhead.com/quest=10819
SET @ID := 10819;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué significa esto?! ¡Nadie me invoca a mí! ¡Habla o yo haré que calles para siempre!', 0),
(@ID, 'esMX', '¡¿Qué significa esto?! ¡Nadie me invoca a mí! ¡Habla o yo haré que calles para siempre!', 0);
-- 10820 Engañar al enemigo
-- https://es.wowhead.com/quest=10820
SET @ID := 10820;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi paciencia se agota, ¿por qué no has terminado?', 0),
(@ID, 'esMX', 'Mi paciencia se agota, ¿por qué no has terminado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así aprenderán los que no hacen lo que digo...$B$BPor cierto..., ¿dónde está la pregonera de fatalidad? ¿Por qué me has informado a mí de esta revuelta y no a ella?', 0),
(@ID, 'esMX', 'Así aprenderán los que no hacen lo que digo...$B$BPor cierto..., ¿dónde está la pregonera de fatalidad? ¿Por qué me has informado a mí de esta revuelta y no a ella?', 0);
-- 10821 ¡Largo de aquí!
-- https://es.wowhead.com/quest=10821
SET @ID := 10821;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres unirte a mi lista de prescindibles? ¡Consigue esas llaves y silencia a la Pregonera de fatalidad!', 0),
(@ID, 'esMX', '¿Quieres unirte a mi lista de prescindibles? ¡Consigue esas llaves y silencia a la Pregonera de fatalidad!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso son grandes noticias, sin duda, $n. No podría haber pedido un resultado mejor. Tu servicio a nuestro pueblo se aprecia enormemente, escoge uno de los siguientes objetos heroicos.$B$BTu nombre se recordará siempre en el corazón de nuestro pueblo.', 0),
(@ID, 'esMX', 'Eso son grandes noticias, sin duda, $n. No podría haber pedido un resultado mejor. Tu servicio a nuestro pueblo se aprecia enormemente, escoge uno de los siguientes objetos heroicos.$B$BTu nombre se recordará siempre en el corazón de nuestro pueblo.', 0);
-- 10824 Sellos Furia del Sol
-- https://es.wowhead.com/quest=10824
SET @ID := 10824;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Adelante, $n. Habla.', 0),
(@ID, 'esMX', 'Adelante, $n. Habla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los elfos de Kael están extremadamente bien entrenados. Excelente trabajo.', 0),
(@ID, 'esMX', 'Los elfos de Kael están extremadamente bien entrenados. Excelente trabajo.', 0);
-- 10825 La verdad sin orbes
-- https://es.wowhead.com/quest=10825
SET @ID := 10825;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿sientes eso? Noto algo sobrenatural y maligno cerca.', 0),
(@ID, 'esMX', '$c, ¿sientes eso? Noto algo sobrenatural y maligno cerca.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí, es ese orbe que tienes ahí! Es extraño, parece tener diseño de los arakkoa. ¿Estuviste en Grishnath hace poco?$B$BDe acuerdo, eso lo explica, pero me pregunto qué propósito diabólico cumple este objeto. Aunque irradia mal, también parece que, de alguna manera, está conectado con el mundo natural.$B$BDame, permíteme intentar activarlo. El mal es tan fuerte en su interior que hay algún tipo de memoria residual aquí...', 0),
(@ID, 'esMX', '¡Sí, es ese orbe que tienes ahí! Es extraño, parece tener diseño de los arakkoa. ¿Estuviste en Grishnath hace poco?$B$BDe acuerdo, eso lo explica, pero me pregunto qué propósito diabólico cumple este objeto. Aunque irradia mal, también parece que, de alguna manera, está conectado con el mundo natural.$B$BDame, permíteme intentar activarlo. El mal es tan fuerte en su interior que hay algún tipo de memoria residual aquí...', 0);
-- 10826 Marcas de Sargeras
-- https://es.wowhead.com/quest=10826
SET @ID := 10826;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes alguna insignia de nuestros enemigos, $n?', 0),
(@ID, 'esMX', '¿Tienes alguna insignia de nuestros enemigos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu coraje es fuerte, $gamigo:amiga;. ¡Que todos sepan que eres $gun verdadero aliado:una verdadera aliada; del sacerdocio!', 0),
(@ID, 'esMX', 'Tu coraje es fuerte, $gamigo:amiga;. ¡Que todos sepan que eres $gun verdadero aliado:una verdadera aliada; del sacerdocio!', 0);
-- 10829 Troncárbol debe saber
-- https://es.tbc.wowhead.com/quest=10829
SET @ID := 10829;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $gpequeño:pequeña; $r. Los pájaros de mis pensamientos me susurraron que ibas a venir.$B$B¿Estás aquí para ayudar a liberar a los árboles del bosque de su maligna posesión?', 0),
(@ID, 'esMX', 'Saludos, $gpequeño:pequeña; $r. Los pájaros de mis pensamientos me susurraron que ibas a venir.$B$B¿Estás aquí para ayudar a liberar a los árboles del bosque de su maligna posesión?', 0);
-- 10830 El exorcismo de los árboles
-- https://es.tbc.wowhead.com/quest=10830
SET @ID := 10830;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Exorcismo de hojabarba realizado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El mal que habita en los árboles está comenzando a filtrarse en todas las cosas naturales del bosque.$B$B¡Debes actuar rápido, $N, antes de que todo se pierda!', 0),
(@ID, 'esMX', 'El mal que habita en los árboles está comenzando a filtrarse en todas las cosas naturales del bosque.$B$B¡Debes actuar rápido, $N, antes de que todo se pierda!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El mal está abandonando el Bosque del Cuervo! ¿Puedes sentirlo, $n?$B$BNos has salvado a todos y a toda la flora de una muerte segura.$B$BTengo cuatro anillos mágicos guardados para ocasiones como esta cuando un héroe realiza alguna hazaña como esta.$B$B¡Y tú eres $gese héroe:esa heroína;! En nombre de todo el Bosque del Cuervo, te doy las gracias.', 0),
(@ID, 'esMX', '¡El mal está abandonando el Bosque del Cuervo! ¿Puedes sentirlo, $n?$B$BNos has salvado a todos y a toda la flora de una muerte segura.$B$BTengo cuatro anillos mágicos guardados para ocasiones como esta cuando un héroe realiza alguna hazaña como esta.$B$B¡Y tú eres $gese héroe:esa heroína;! En nombre de todo el Bosque del Cuervo, te doy las gracias.', 0);
-- 10831 Convertirse en un sastre de tela lunar
-- https://es.tbc.wowhead.com/quest=10831
SET @ID := 10831;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has creado la muestra de tela lunar primigenia?', 0),
(@ID, 'esMX', '¿Has creado la muestra de tela lunar primigenia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Nasmara examina la tela y le da la vuelta en las manos.>$B$BEsta es una muestra excelente, $N. Serás $gun:una; excelente sastre de tela lunar.', 0),
(@ID, 'esMX', '<Nasmara examina la tela y le da la vuelta en las manos.>$B$BEsta es una muestra excelente, $N. Serás $gun:una; excelente sastre de tela lunar.', 0);
-- 10832 Convertirse en sastre de fuego de hechizo
-- https://es.tbc.wowhead.com/quest=10832
SET @ID := 10832;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste la muestra del ánima abisal?', 0),
(@ID, 'esMX', '¿Conseguiste la muestra del ánima abisal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gidge examina la esencia del ánima abisal.>$B$BIncluso esta pequeña muestra de la esencia de la criatura irradia poder. Tal vez entendí mal lo que está pasando. No estamos enojando a los espectros tomando energía del medio ambiente. Más bien, ¡los espectros y el entorno son lo mismo!$B$BNo dudes en avisarme si haces más descubrimientos, ahora que te has convertido en $gun:una; sastre de fuego de hechizos.', 0),
(@ID, 'esMX', '<Gidge examina la esencia del ánima abisal.>$B$BIncluso esta pequeña muestra de la esencia de la criatura irradia poder. Tal vez entendí mal lo que está pasando. No estamos enojando a los espectros tomando energía del medio ambiente. Más bien, ¡los espectros y el entorno son lo mismo!$B$BNo dudes en avisarme si haces más descubrimientos, ahora que te has convertido en $gun:una; sastre de fuego de hechizos.', 0);
-- 10833 Convertirse en un sastre de tejido de sombra
-- https://es.tbc.wowhead.com/quest=10833
SET @ID := 10833;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ajustar sintonía con El Altar de las Sombras', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has usado el poder del cristal para profundizar tu sintonía con el Altar de las Sombras?', 0),
(@ID, 'esMX', '¿Has usado el poder del cristal para profundizar tu sintonía con el Altar de las Sombras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo ver que tu visita al altar ha sido todo un éxito. Hay una sutil diferencia en ti que muy pocos podrán ver, aunque no cabe ni la menor duda de que ahí está.', 0),
(@ID, 'esMX', 'Puedo ver que tu visita al altar ha sido todo un éxito. Hay una sutil diferencia en ti que muy pocos podrán ver, aunque no cabe ni la menor duda de que ahí está.', 0);
-- 10834 Grillok "Ojosombra"
-- https://es.tbc.wowhead.com/quest=10834
SET @ID := 10834;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los malvados orcos del clan Foso Sangrante no respetan ningún límite y solo sus parientes de la Mano Destrozada son un rival para ellos.', 0),
(@ID, 'esMX', 'Los malvados orcos del clan Foso Sangrante no respetan ningún límite y solo sus parientes de la Mano Destrozada son un rival para ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Igual que quienes pierden una mano o una pierna en la batalla a menudo sienten el dolor de su miembro perdido, me pregunto si Grillok sigue viendo su ojo perdido en sus oscuros sueños...$B$BYo también soñaré con esto y, si la fortuna está de nuestro lado, quizás descubre lo que llevó a Grillok y al clan Foso Sangrante a sucumbir ante los demonios.', 0),
(@ID, 'esMX', 'Ah, sí. Igual que quienes pierden una mano o una pierna en la batalla a menudo sienten el dolor de su miembro perdido, me pregunto si Grillok sigue viendo su ojo perdido en sus oscuros sueños...$B$BYo también soñaré con esto y, si la fortuna está de nuestro lado, quizás descubre lo que llevó a Grillok y al clan Foso Sangrante a sucumbir ante los demonios.', 0);
-- 10835 El boticario Antonivich
-- https://es.tbc.wowhead.com/quest=10835
SET @ID := 10835;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buenos días, $n. ¿Cómo es tu estancia en la Península del Fuego Infernal? Confío en que haya sido provechosa...', 0),
(@ID, 'esMX', 'Buenos días, $n. ¿Cómo es tu estancia en la Península del Fuego Infernal? Confío en que haya sido provechosa...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿un informe de Albreck? Muy bien. La Sociedad Real de Boticarios trabaja febrilmente para determinar cómo los orcos de la Península del Fuego Infernal se convirtieron en orcos viles. Su traición es imperdonable... y debemos asegurarnos de que nuestros amigos orcos siempre estén a salvo de una corrupción futura.', 0),
(@ID, 'esMX', 'Ah, ¿un informe de Albreck? Muy bien. La Sociedad Real de Boticarios trabaja febrilmente para determinar cómo los orcos de la Península del Fuego Infernal se convirtieron en orcos viles. Su traición es imperdonable... y debemos asegurarnos de que nuestros amigos orcos siempre estén a salvo de una corrupción futura.', 0);
-- 10836 Infiltrarse en la Fortaleza Faucedraco
-- https://es.tbc.wowhead.com/quest=10836
SET @ID := 10836;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho? Solo espero que no sea demasiado tarde...', 0),
(@ID, 'esMX', '¿Está hecho? Solo espero que no sea demasiado tarde...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. He descubierto una forma para poder liberar a los dracos esclavizados que son retenidos en la Fortaleza Faucedraco.', 0),
(@ID, 'esMX', 'Bien hecho, $n. He descubierto una forma para poder liberar a los dracos esclavizados que son retenidos en la Fortaleza Faucedraco.', 0);
-- 10837 ¡Al Arrecife del Ala Abisal!
-- https://es.tbc.wowhead.com/quest=10837
SET @ID := 10837;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito cristales de vid abisal.', 0),
(@ID, 'esMX', 'Necesito cristales de vid abisal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Neltharaku te coge los cristales.>$B$BTe prepararé los cristales ahora.', 0),
(@ID, 'esMX', '<Neltharaku te coge los cristales.>$B$BTe prepararé los cristales ahora.', 0);
-- 10839 Velo Skith: Rocanegra de Terokk
-- https://es.tbc.wowhead.com/quest=10839
SET @ID := 10839;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La oscuridad nos rodea. ¿Qué tienes que decir sobre Velo Skith?', 0),
(@ID, 'esMX', 'La oscuridad nos rodea. ¿Qué tienes que decir sobre Velo Skith?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He oído la explosión desde aquí. No con mis oídos, sino con mi corazón.$B$BSi el toque del naaru bendito, A\'dal, no es suficiente para que los arakkoa se rediman, nada lo será. Aquellos que no se hayan entregado a la Luz son meros sirvientes del mal.$B$BDeben ser destruidos.', 0),
(@ID, 'esMX', 'He oído la explosión desde aquí. No con mis oídos, sino con mi corazón.$B$BSi el toque del naaru bendito, A\'dal, no es suficiente para que los arakkoa se rediman, nada lo será. Aquellos que no se hayan entregado a la Luz son meros sirvientes del mal.$B$BDeben ser destruidos.', 0);
-- 10840 La Tumba de las Luces
-- https://es.tbc.wowhead.com/quest=10840
SET @ID := 10840;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuántos etéreos has destruido? Espero que sea suficiente para expulsarlos de la Tumba de las Luces.', 0),
(@ID, 'esMX', '¿Cuántos etéreos has destruido? Espero que sea suficiente para expulsarlos de la Tumba de las Luces.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí fuera, en las zonas salvajes de Terrallende, somos débiles y solo tenemos la ayuda de algunos héroes para defender nuestros derechos, pero tú les has hecho tener miedo, $c. Creo que los etéreos tardarán en olvidar el fuerte brazo de $n.', 0),
(@ID, 'esMX', 'Aquí fuera, en las zonas salvajes de Terrallende, somos débiles y solo tenemos la ayuda de algunos héroes para defender nuestros derechos, pero tú les has hecho tener miedo, $c. Creo que los etéreos tardarán en olvidar el fuerte brazo de $n.', 0);
-- 10842 Almas vengativas
-- https://es.tbc.wowhead.com/quest=10842
SET @ID := 10842;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Presagista vengativo derrotado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos has salvado a todos. ¿Cómo podemos agradecértelo?', 0),
(@ID, 'esMX', 'Nos has salvado a todos. ¿Cómo podemos agradecértelo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te imaginas lo que has hecho, $n. Has salvado a tantos de nosotros de una eternidad de oscuridad... Hay poco que pueda hacer por los vivos y nada que pudiera darte serviría para agradecértelo lo suficiente. Toma lo que te parezca útil.', 0),
(@ID, 'esMX', 'No te imaginas lo que has hecho, $n. Has salvado a tantos de nosotros de una eternidad de oscuridad... Hay poco que pueda hacer por los vivos y nada que pudiera darte serviría para agradecértelo lo suficiente. Toma lo que te parezca útil.', 0);
-- 10843 Desde tiempos olvidados...
-- https://es.tbc.wowhead.com/quest=10843
SET @ID := 10843;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Mok\'Nathal no aceptan el fracaso ni ponen excusas. ¡O vences a tu enemigo, o él te mata!$B$BYa que estás $gparado:parada; frente a mí, ya debes haber matado a Gnosh Brognat.', 0),
(@ID, 'esMX', 'Los Mok\'Nathal no aceptan el fracaso ni ponen excusas. ¡O vences a tu enemigo, o él te mata!$B$BYa que estás $gparado:parada; frente a mí, ya debes haber matado a Gnosh Brognat.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Leoroxx te evalúa con una mirada penetrante, aparentemente intentando medirte.>$B$BLa muerte de Gnosh Brognat es una bendición para todos los Mok\'Nathal. Esto es bueno para ti.$B$BVeamos si podemos poner al límite tu valor un poco más.', 0),
(@ID, 'esMX', '<Leoroxx te evalúa con una mirada penetrante, aparentemente intentando medirte.>$B$BLa muerte de Gnosh Brognat es una bendición para todos los Mok\'Nathal. Esto es bueno para ti.$B$BVeamos si podemos poner al límite tu valor un poco más.', 0);
-- 10845 Matar a la madre de linaje
-- https://es.tbc.wowhead.com/quest=10845
SET @ID := 10845;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque a mis ojos no te beneficiarás, no hay vergüenza en admitir que no estás a la altura del desafío de matar a la madre de los dracos inferiores de Cresta Canto.$B$B¿Es eso lo que has venido a decirme?', 0),
(@ID, 'esMX', 'Aunque a mis ojos no te beneficiarás, no hay vergüenza en admitir que no estás a la altura del desafío de matar a la madre de los dracos inferiores de Cresta Canto.$B$B¿Es eso lo que has venido a decirme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No? ¿Mataste a Alatemible? Quizás me equivocaba contigo, $c.$B$BQuizás.$B$BAun así, has matado a los jefes de las tres mayores amenazas a las que nos enfrentamos. Eso es algo de lo que estar $gorgulloso:orgullosa;.$B$BTe ofrezco un regalo en muestra de mi aprecio, pero no dejes que se te suba a la cabeza. Todavía no comprendes del todo lo que significa ser un Mok\'Nathal, y puede que nosotros todavía necesitemos de tus habilidades.', 0),
(@ID, 'esMX', '¿No? ¿Mataste a Alatemible? Quizás me equivocaba contigo, $c.$B$BQuizás.$B$BAun así, has matado a los jefes de las tres mayores amenazas a las que nos enfrentamos. Eso es algo de lo que estar $gorgulloso:orgullosa;.$B$BTe ofrezco un regalo en muestra de mi aprecio, pero no dejes que se te suba a la cabeza. Todavía no comprendes del todo lo que significa ser un Mok\'Nathal, y puede que nosotros todavía necesitemos de tus habilidades.', 0);
-- 10846 Comprender a los Mok'Nathal
-- https://es.tbc.wowhead.com/quest=10846
SET @ID := 10846;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos muchos enemigos. Algunos los hemos elegido y otros, como el Vehk\'nir, no.$B$BDe todos modos, mataremos a todos sus jefes hasta que ninguno se interponga ante nosotros.', 0),
(@ID, 'esMX', 'Tenemos muchos enemigos. Algunos los hemos elegido y otros, como el Vehk\'nir, no.$B$BDe todos modos, mataremos a todos sus jefes hasta que ninguno se interponga ante nosotros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Vekh\'nir son los más inferiores de nuestros adversarios.$B$BAsí que sabes cómo matar a un pájaro grande. Eso no te convierte en $gun guerrero auténtico:una guerrera auténtica;. Eso no te da una comprensión total de nuestros hábitos.$B$BPero es un comienzo.', 0),
(@ID, 'esMX', 'Los Vekh\'nir son los más inferiores de nuestros adversarios.$B$BAsí que sabes cómo matar a un pájaro grande. Eso no te convierte en $gun guerrero auténtico:una guerrera auténtica;. Eso no te da una comprensión total de nuestros hábitos.$B$BPero es un comienzo.', 0);
