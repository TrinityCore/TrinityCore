-- 9928 Armamentos para engañar
-- https://es.wowhead.com/quest=9928
SET @ID := 9928;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Forjaremos un odio no visto hasta ahora entre los dos clanes!', 0),
(@ID, 'esMX', '¡Forjaremos un odio no visto hasta ahora entre los dos clanes!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Nuestro próximo objetivo serán las Ruinas Riecráneos.', 0),
(@ID, 'esMX', '¡Excelente! Nuestro próximo objetivo serán las Ruinas Riecráneos.', 0);
-- 9931 Devolver el favor
-- https://es.wowhead.com/quest=9931
SET @ID := 9931;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Estandarte Mata’penas plantado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedes predecir qué ocurrirá después?', 0),
(@ID, 'esMX', '¿Puedes predecir qué ocurrirá después?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El plan es perfecto, $n. Ya puedo ver los frutos de tu trabajo.', 0),
(@ID, 'esMX', 'El plan es perfecto, $n. Ya puedo ver los frutos de tu trabajo.', 0);
-- 9932 El cadáver del delito
-- https://es.wowhead.com/quest=9932
SET @ID := 9932;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cadáveres Mata’penas colocados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Comprendes por qué nunca podrías ganar una guerra contra mí?', 0),
(@ID, 'esMX', '¿Comprendes por qué nunca podrías ganar una guerra contra mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo admitir que no me había sentido tan vivo desde hace décadas. Lo has hecho bien, $n.', 0),
(@ID, 'esMX', 'Debo admitir que no me había sentido tan vivo desde hace décadas. Lo has hecho bien, $n.', 0);
-- 9933 Mensaje para Telaar
-- https://es.wowhead.com/quest=9933
SET @ID := 9933;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Paz, dices?', 0),
(@ID, 'esMX', '¿Paz, dices?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor, $n, coge lo que quieras de la ofrenda de paz. Después de todo, sin tus esfuerzos, esto no habría sido posible.', 0),
(@ID, 'esMX', 'Por favor, $n, coge lo que quieras de la ofrenda de paz. Después de todo, sin tus esfuerzos, esto no habría sido posible.', 0);
-- 9934 Mensaje para Garadar
-- https://es.wowhead.com/quest=9934
SET @ID := 9934;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Garrosh no parece estar conmovido por la ofrenda.>', 0),
(@ID, 'esMX', '<Garrosh no parece estar conmovido por la ofrenda.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Garrosh da una patada a la caja.>$B$BEstás perdiendo el tiempo, $r. Coge lo que quieras de esta caja. Ni yo ni Garadar necesitamos esas baratijas inútiles.', 0),
(@ID, 'esMX', '<Garrosh da una patada a la caja.>$B$BEstás perdiendo el tiempo, $r. Coge lo que quieras de esta caja. Ni yo ni Garadar necesitamos esas baratijas inútiles.', 0);
-- Se busca: Giselda la Vieja bruja
-- 9935, 9936
-- https://es.wowhead.com/quest=9935
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9935, 9936) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9935, 'esES', '¿Estás aquí para cobrar una recompensa?', 0),
(9936, 'esES', '¿Estás aquí para cobrar una recompensa?', 0),
(9935, 'esMX', '¿Estás aquí para cobrar una recompensa?', 0),
(9936, 'esMX', '¿Estás aquí para cobrar una recompensa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9935, 9936) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9935, 'esES', '¡La bruja está muerta! Qué noticias tan fantásticas, $n. Aquí tienes tu recompensa.', 0),
(9936, 'esES', '¡La bruja está muerta! Qué noticias tan fantásticas, $n. Aquí tienes tu recompensa.', 0),
(9935, 'esMX', '¡La bruja está muerta! Qué noticias tan fantásticas, $n. Aquí tienes tu recompensa.', 0),
(9936, 'esMX', '¡La bruja está muerta! Qué noticias tan fantásticas, $n. Aquí tienes tu recompensa.', 0);
-- 9937 Se busca: Durn el Hambriento
-- https://es.wowhead.com/quest=9937
SET @ID := 9937;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por los Mag\'har!', 0),
(@ID, 'esMX', '¡Por los Mag\'har!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin nos hemos librado del garrote asesino de Durn! Nagrand tiene un futuro más brillante gracias a ti, $ghéroe:heroína;. ¡Bien hecho!', 0),
(@ID, 'esMX', '¡Por fin nos hemos librado del garrote asesino de Durn! Nagrand tiene un futuro más brillante gracias a ti, $ghéroe:heroína;. ¡Bien hecho!', 0);
-- 9938 Se busca: Durn el Hambriento
-- https://es.wowhead.com/quest=9938
SET @ID := 9938;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No pierdas el tiempo! ¡Hay que detener a Durn!', 0),
(@ID, 'esMX', '¡No pierdas el tiempo! ¡Hay que detener a Durn!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin nos hemos librado del garrote asesino de Durn! Nagrand tiene un futuro más brillante gracias a ti, $ghéroe:heroína;. ¡Bien hecho!', 0),
(@ID, 'esMX', '¡Por fin nos hemos librado del garrote asesino de Durn! Nagrand tiene un futuro más brillante gracias a ti, $ghéroe:heroína;. ¡Bien hecho!', 0);
-- 9939 Se busca: Zorbo el Consejero
-- https://es.wowhead.com/quest=9939
SET @ID := 9939;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás aquí para cobrar una recompensa?', 0),
(@ID, 'esMX', '¿Estás aquí para cobrar una recompensa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una gran victoria para el pueblo de Garadar! ¡Bien hecho, $n!', 0),
(@ID, 'esMX', '¡Una gran victoria para el pueblo de Garadar! ¡Bien hecho, $n!', 0);
-- 9940 Se busca: Zorbo el Consejero
-- https://es.wowhead.com/quest=9940
SET @ID := 9940;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás aquí para cobrar una recompensa?', 0),
(@ID, 'esMX', '¿Estás aquí para cobrar una recompensa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una gran victoria para el pueblo de Telaar! ¡Bien hecho, $n!', 0),
(@ID, 'esMX', '¡Una gran victoria para el pueblo de Telaar! ¡Bien hecho, $n!', 0);
-- 9944 La procesión Mag'hari
-- https://es.wowhead.com/quest=9944
SET @ID := 9944;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Treinta orcos, $r! De esos treinta, solo quedamos Ungriz y yo. Encontramos al joven Colmillosauro casi muerto cerca de Primasol. Al parecer, estaba ahí por otra razón...', 0),
(@ID, 'esMX', '¡Treinta orcos, $r! De esos treinta, solo quedamos Ungriz y yo. Encontramos al joven Colmillosauro casi muerto cerca de Primasol. Al parecer, estaba ahí por otra razón...', 0);
-- 9945 Sangre en Mazo de Guerra
-- https://es.wowhead.com/quest=9945
SET @ID := 9945;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es simplemente un paso en un largo proceso. A los ogros, como a los perros, se les debe mostrar la diferencia entre el bien y el mal. Hablarles no sirve de nada.', 0),
(@ID, 'esMX', 'Este es simplemente un paso en un largo proceso. A los ogros, como a los perros, se les debe mostrar la diferencia entre el bien y el mal. Hablarles no sirve de nada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un buen comienzo, pero hay que acabar con el líder para que tus actos tengan un efecto duradero.', 0),
(@ID, 'esMX', 'Es un buen comienzo, pero hay que acabar con el líder para que tus actos tengan un efecto duradero.', 0);
-- 9946 Cho'war el Saqueador
-- https://es.wowhead.com/quest=9946
SET @ID := 9946;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin duda, estará bien protegido.', 0),
(@ID, 'esMX', 'Sin duda, estará bien protegido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocaremos esta cabeza a las puertas de Garadar, a la vista de todos. Los ogros se lo van a pensar dos veces antes de interrumpir los rituales sagrados de los Mag\'har.', 0),
(@ID, 'esMX', 'Colocaremos esta cabeza a las puertas de Garadar, a la vista de todos. Los ogros se lo van a pensar dos veces antes de interrumpir los rituales sagrados de los Mag\'har.', 0);
-- 9948 Encontrando a los supervivientes
-- https://es.wowhead.com/quest=9948
SET @ID := 9948;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Prisionero Mag\'har liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ungriz suspira.>$B$BSé que es mucho pedir, $n; pero devuélvelos vivos...', 0),
(@ID, 'esMX', '<Ungriz suspira.>$B$BSé que es mucho pedir, $n; pero devuélvelos vivos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has logrado lo que nadie creyó posible y has traído de vuelta a nuestros hermanos desaparecidos. Eres $gun héroe:una heroína; para los Mag\'har, $n. Todos conocerán tu nombre y tus hazañas.', 0),
(@ID, 'esMX', 'Has logrado lo que nadie creyó posible y has traído de vuelta a nuestros hermanos desaparecidos. Eres $gun héroe:una heroína; para los Mag\'har, $n. Todos conocerán tu nombre y tus hazañas.', 0);
-- 9950 A vista de pájaro
-- https://es.wowhead.com/quest=9950
SET @ID := 9950;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Rokag me ha contado el plan. ¿Tienes los ojos?', 0),
(@ID, 'esMX', 'Rokag me ha contado el plan. ¿Tienes los ojos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Curioso, estos ojos no son exactamente con los que estoy acostumbrado a trabajar. La forma en que los arakkoa usan su magia es ligeramente diferente a la nuestra.$B$BParece que vamos a necesitar una cosa más para poder buscar la información para localizar a Dugar.', 0),
(@ID, 'esMX', 'Curioso, estos ojos no son exactamente con los que estoy acostumbrado a trabajar. La forma en que los arakkoa usan su magia es ligeramente diferente a la nuestra.$B$BParece que vamos a necesitar una cosa más para poder buscar la información para localizar a Dugar.', 0);
-- 9951 ¡Naphthal'ar te vigila!
-- https://es.wowhead.com/quest=9951
SET @ID := 9951;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca debimos invitarlos a cenar, eso es seguro!$B$BO al menos, debimos insistir en un par de platos antes del postre que trajeron.', 0),
(@ID, 'esMX', '¡Nunca debimos invitarlos a cenar, eso es seguro!$B$BO al menos, debimos insistir en un par de platos antes del postre que trajeron.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En el fondo es lo mejor. Si no puede aceptar civilizadamente una invitación, entonces es mejor que se quede donde está.$B$B<El celador Treelos parece confundido por un momento.>$B$B¿Quién eres tú y qué haces aquí? ¡Sal de aquí antes de que sea demasiado tarde!', 0),
(@ID, 'esMX', 'En el fondo es lo mejor. Si no puede aceptar civilizadamente una invitación, entonces es mejor que se quede donde está.$B$B<El celador Treelos parece confundido por un momento.>$B$B¿Quién eres tú y qué haces aquí? ¡Sal de aquí antes de que sea demasiado tarde!', 0);
-- 9954 El rescate de Corki
-- https://es.wowhead.com/quest=9954
SET @ID := 9954;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta vez me han pillado bien, $n. El rey Mazo de Guerra, Cho\'war, tiene la llave.', 0),
(@ID, 'esMX', 'Esta vez me han pillado bien, $n. El rey Mazo de Guerra, Cho\'war, tiene la llave.', 0);
-- 9955 Cho'war el Saqueador
-- https://es.wowhead.com/quest=9955
SET @ID := 9955;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Corki liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está Corki?', 0),
(@ID, 'esMX', '¿Dónde está Corki?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. He enviado a Corki a vivir con los elfos de la noche en Filospada. Espero que ellos puedan conseguir que no se meta en líos.$B$BY ahora, lo de tu recompensa...', 0),
(@ID, 'esMX', 'Gracias, $n. He enviado a Corki a vivir con los elfos de la noche en Filospada. Espero que ellos puedan conseguir que no se meta en líos.$B$BY ahora, lo de tu recompensa...', 0);
-- 9956 La Caravana Devastada
-- https://es.wowhead.com/quest=9956
SET @ID := 9956;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me siento tan mal. El hijo de Arechron, Corki, me preguntó qué había pasado y se lo conté. ¡Ahora ha vuelto a desaparecer!', 0),
(@ID, 'esMX', 'Me siento tan mal. El hijo de Arechron, Corki, me preguntó qué había pasado y se lo conté. ¡Ahora ha vuelto a desaparecer!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¿Cómo has logrado hacer todo eso sin ayuda?', 0),
(@ID, 'esMX', '¡Increíble! ¿Cómo has logrado hacer todo eso sin ayuda?', 0);
-- 9957 ¿Qué pasa en el Matorral Cenarion?
-- https://es.wowhead.com/quest=9957
SET @ID := 9957;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que el refugio te enviase. Los druidas del Matorral están muertos. Solo quedamos otro compañero, que está loco, y yo.$B$BNo sé qué ocurrió, pero pretendo llegar al fondo del asunto. Fuera lo que fuera, ocurrió rápidamente y no parece muy normal.$B$B¿Me ayudarás?', 0),
(@ID, 'esMX', 'Me alegro de que el refugio te enviase. Los druidas del Matorral están muertos. Solo quedamos otro compañero, que está loco, y yo.$B$BNo sé qué ocurrió, pero pretendo llegar al fondo del asunto. Fuera lo que fuera, ocurrió rápidamente y no parece muy normal.$B$B¿Me ayudarás?', 0);
-- Información sobre las defensas
-- 9958, 9959
-- https://es.wowhead.com/quest=9958
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Investigar las defensas de Velo Shalas', `VerifiedBuild` = 0 WHERE `id` IN(9958, 9959) AND `locale` IN('esES', 'esMX');
-- Algo pasa en el Matorral Cenarion
-- 9960, 9961
-- https://es.wowhead.com/quest=9960
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9960, 9961) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9960, 'esES', 'Me alegro de que te hayan enviado del Bastión Rompepedras. ¡Han asesinado a los druidas del Matorral! Solo hemos sobrevivido dos, y mi compañero ha perdido el juicio.$B$BNo sé qué ha pasado, pero pienso averiguarlo. Fue muy rápido y antinatural.$B$B¿Me ayudarás?', 0),
(9961, 'esES', 'Me alegro de que te hayan enviado del Bastión Rompepedras. ¡Han asesinado a los druidas del Matorral! Solo hemos sobrevivido dos, y mi compañero ha perdido el juicio.$B$BNo sé qué ha pasado, pero pienso averiguarlo. Fue muy rápido y antinatural.$B$B¿Me ayudarás?', 0),
(9960, 'esMX', 'Me alegro de que te hayan enviado del Bastión Rompepedras. ¡Han asesinado a los druidas del Matorral! Solo hemos sobrevivido dos, y mi compañero ha perdido el juicio.$B$BNo sé qué ha pasado, pero pienso averiguarlo. Fue muy rápido y antinatural.$B$B¿Me ayudarás?', 0),
(9961, 'esMX', 'Me alegro de que te hayan enviado del Bastión Rompepedras. ¡Han asesinado a los druidas del Matorral! Solo hemos sobrevivido dos, y mi compañero ha perdido el juicio.$B$BNo sé qué ha pasado, pero pienso averiguarlo. Fue muy rápido y antinatural.$B$B¿Me ayudarás?', 0);
-- 9962 El Círculo de Sangre: Dedorroto
-- https://es.wowhead.com/quest=9962
SET @ID := 9962;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0),
(@ID, 'esMX', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No eh\'tá mal, nada mal... Tienes mucho potencial. Ten, un poco de oro pa\' llenah\'te los bolsillos.', 0),
(@ID, 'esMX', 'No eh\'tá mal, nada mal... Tienes mucho potencial. Ten, un poco de oro pa\' llenah\'te los bolsillos.', 0);
-- 9967 El Círculo de Sangre: los hermanos azules
-- https://es.wowhead.com/quest=9967
SET @ID := 9967;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0),
(@ID, 'esMX', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo admitir que no creía que fueses a conseguih\'lo, $n. ¡Ha sido impresionante! ¿Qué te parece otra pelea? Gurgthock tiene al oponente perfecto pa\' ti.', 0),
(@ID, 'esMX', 'Debo admitir que no creía que fueses a conseguih\'lo, $n. ¡Ha sido impresionante! ¿Qué te parece otra pelea? Gurgthock tiene al oponente perfecto pa\' ti.', 0);
-- 9968 Extraña energía
-- https://es.wowhead.com/quest=9968
SET @ID := 9968;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mis muestras?', 0),
(@ID, 'esMX', '¿Tienes mis muestras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué raro. Las muestras de las teropolillas sañosas están imbuidas con algo que parece ser maná puro.$B$BPor lo visto, lo que provocó su muerte también dejó un campo de energía residual. Pero por lo visto, las teropolillas no murieron; en vez de eso, les provocó un estado de agitación aguda.$B$BParece evidente que esa energía extraña proviene de lo que atacó el matorral.', 0),
(@ID, 'esMX', 'Qué raro. Las muestras de las teropolillas sañosas están imbuidas con algo que parece ser maná puro.$B$BPor lo visto, lo que provocó su muerte también dejó un campo de energía residual. Pero por lo visto, las teropolillas no murieron; en vez de eso, les provocó un estado de agitación aguda.$B$BParece evidente que esa energía extraña proviene de lo que atacó el matorral.', 0);
-- 9970 El Círculo de Sangre: Rokdar el Señor Hendido
-- https://es.wowhead.com/quest=9970
SET @ID := 9970;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0),
(@ID, 'esMX', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble, has hecho sudar a los ogros! Aquí tienes algo extra... no lo uses todo en el mismo lugar.$B$B¿Eh\'tás lih\'to pa\' otra pelea? ¡Gurgthock apuesta fueh\'te por ti!', 0),
(@ID, 'esMX', '¡Increíble, has hecho sudar a los ogros! Aquí tienes algo extra... no lo uses todo en el mismo lugar.$B$B¿Eh\'tás lih\'to pa\' otra pelea? ¡Gurgthock apuesta fueh\'te por ti!', 0);
-- 9971 Pistas en el Matorral
-- https://es.wowhead.com/quest=9971
SET @ID := 9971;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Objeto extraño examinado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto algo?', 0),
(@ID, 'esMX', '¿Has descubierto algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que tenía razón. ¿Ese era el cuerpo de uno de los Tábidos? ¿Y puedes confirmar que había un objeto extraño a su lado?$B$BNo tiene ningún sentido. ¿Qué hacía ahí un Tábido? ¿Y qué es esa cosa?$B$B¿Acaso fue lo que provocó todas esas muertes?', 0),
(@ID, 'esMX', 'Así que tenía razón. ¿Ese era el cuerpo de uno de los Tábidos? ¿Y puedes confirmar que había un objeto extraño a su lado?$B$BNo tiene ningún sentido. ¿Qué hacía ahí un Tábido? ¿Y qué es esa cosa?$B$B¿Acaso fue lo que provocó todas esas muertes?', 0);
-- 9972 El Círculo de Sangre: Skra'gath
-- https://es.wowhead.com/quest=9972
SET @ID := 9972;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0),
(@ID, 'esMX', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡IMPRESIONANTE! ¡$gCHICO:CHICA;, ALLÁ VAMOS! La próxima pelea es la grande. ¡El campeonato final!$B$BMuy bien, pero tú, $gtranquilo:tranquila;. No queremos que los ogros sepan lo que tenemos entre manos. Después de todo, yo me llevo pah\'te de los beneficios.', 0),
(@ID, 'esMX', '¡IMPRESIONANTE! ¡$gCHICO:CHICA;, ALLÁ VAMOS! La próxima pelea es la grande. ¡El campeonato final!$B$BMuy bien, pero tú, $gtranquilo:tranquila;. No queremos que los ogros sepan lo que tenemos entre manos. Después de todo, yo me llevo pah\'te de los beneficios.', 0);
-- 9973 El Círculo de Sangre: el campeón Mazo de Guerra
-- https://es.wowhead.com/quest=9973
SET @ID := 9973;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0),
(@ID, 'esMX', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, oh! Mogor ha utilizado su derecho de combate como héroe de los Mazo de Guerra. ¡Vas a tener que luchar contra él!$B$BNadie dijo nunca que los Mazo de Guerra no hicieran... ehhh... trampas.', 0),
(@ID, 'esMX', '¡Oh, oh! Mogor ha utilizado su derecho de combate como héroe de los Mazo de Guerra. ¡Vas a tener que luchar contra él!$B$BNadie dijo nunca que los Mazo de Guerra no hicieran... ehhh... trampas.', 0);
-- Magia primigenia
-- 9975, 9976
-- https://es.wowhead.com/quest=9975
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Utiliza el talismán de Kokorek', `VerifiedBuild` = 0 WHERE `id` IN(9975, 9976) AND `locale` IN('esES', 'esMX');
-- 9977 El Círculo de Sangre: el desafío final
-- https://es.wowhead.com/quest=9977
SET @ID := 9977;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0),
(@ID, 'esMX', 'La pelea termina cuando tú o t\'oponente estáis muertos en el suelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gurgthock dijo que te recompensaría, $gchico:chica;. ¡Escoge lo que quieras!', 0),
(@ID, 'esMX', 'Gurgthock dijo que te recompensaría, $gchico:chica;. ¡Escoge lo que quieras!', 0);
-- 9978 Cueste lo que cueste
-- https://es.wowhead.com/quest=9978
SET @ID := 9978;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vale, vale... Te diré lo que sé, pero no es mucho.', 0),
(@ID, 'esMX', 'Vale, vale... Te diré lo que sé, pero no es mucho.', 0);
-- 9979 Comerciante de viento Lathrai
-- https://es.wowhead.com/quest=9979
SET @ID := 9979;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿En qué te puedo ayudar, $r?', 0),
(@ID, 'esMX', '¿Sí? ¿En qué te puedo ayudar, $r?', 0);
-- 9980 ¡Rescata a Deirom!
-- https://es.wowhead.com/quest=9980
SET @ID := 9980;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Liberar a Deirom', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 9981 ¡Rescata a Dugar!
-- https://es.wowhead.com/quest=9981
SET @ID := 9981;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Liberar a Dugar', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- Se hacía llamar Altruis...
-- 9982, 9983
-- https://es.wowhead.com/quest=9982
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9982, 9983) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9982, 'esES', '¿Acaso mi apariencia te sorprende? ¿Sabes lo que soy?', 0),
(9983, 'esES', '¿Acaso mi apariencia te sorprende? ¿Sabes lo que soy?', 0),
(9982, 'esMX', '¿Acaso mi apariencia te sorprende? ¿Sabes lo que soy?', 0),
(9983, 'esMX', '¿Acaso mi apariencia te sorprende? ¿Sabes lo que soy?', 0);
-- Anfitrión de la ciudad oculta
-- 9984, 9985
-- https://es.wowhead.com/quest=9984
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9984, 9985) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9984, 'esES', 'Puedo leer la mayor parte de esto, lo suficiente como para tener una idea general. Quien escribió esto elogia el \'progreso\' logrado por Luanga y lo alienta a seguir interrogando a sus \'invitados\'.$B$BMientras tanto, dice, \'los preparativos en Skettis avanzan según lo planeado\' y que \'pronto estarán listos para reclamar sus tierras ancestrales\'.$B$BNo estoy familiarizado con este \'Skettis\' mencionado por el escritor, pero donde sea que esté, ¡parece que los arakkoa están reuniendo un ejército allí! Thander debe ser informado sobre esto de inmediato.', 0),
(9985, 'esES', 'Puedo leer la mayor parte de esto, lo suficiente como para tener una idea general. Quien escribió esto elogia el \'progreso\' logrado por Luanga y lo alienta a seguir interrogando a sus \'invitados\'.$B$BMientras tanto, dice, \'los preparativos en Skettis avanzan según lo planeado\' y que \'pronto estarán listos para reclamar sus tierras ancestrales\'.$B$BNo estoy familiarizado con este \'Skettis\' mencionado por el escritor, pero donde sea que esté, ¡parece que los arakkoa están reuniendo un ejército allí! Thander debe ser informado sobre esto de inmediato.', 0),
(9984, 'esMX', 'Puedo leer la mayor parte de esto, lo suficiente como para tener una idea general. Quien escribió esto elogia el \'progreso\' logrado por Luanga y lo alienta a seguir interrogando a sus \'invitados\'.$B$BMientras tanto, dice, \'los preparativos en Skettis avanzan según lo planeado\' y que \'pronto estarán listos para reclamar sus tierras ancestrales\'.$B$BNo estoy familiarizado con este \'Skettis\' mencionado por el escritor, pero donde sea que esté, ¡parece que los arakkoa están reuniendo un ejército allí! Thander debe ser informado sobre esto de inmediato.', 0),
(9985, 'esMX', 'Puedo leer la mayor parte de esto, lo suficiente como para tener una idea general. Quien escribió esto elogia el \'progreso\' logrado por Luanga y lo alienta a seguir interrogando a sus \'invitados\'.$B$BMientras tanto, dice, \'los preparativos en Skettis avanzan según lo planeado\' y que \'pronto estarán listos para reclamar sus tierras ancestrales\'.$B$BNo estoy familiarizado con este \'Skettis\' mencionado por el escritor, pero donde sea que esté, ¡parece que los arakkoa están reuniendo un ejército allí! Thander debe ser informado sobre esto de inmediato.', 0);
