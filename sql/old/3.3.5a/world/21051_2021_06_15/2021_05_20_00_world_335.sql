-- 9813 Encuentro con el Jefe de Guerra
-- https://es.wowhead.com/quest=9813
SET @ID := 9813;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n?', 0),
(@ID, 'esMX', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thrall comienza a leer la carta.>$B$BAsí que los elfos de sangre finalmente se encargaron de su pequeño problema. No es de extrañar que haya sido necesaria tu ayuda y la de todo un regimiento de Renegados para hacer el trabajo.$B$B<El Jefe de Guerra se echa a reír.>$B$BSupongo que no hay forma de detener esto. Al final, los necesitamos tanto como ellos nos necesitan a nosotros.', 0),
(@ID, 'esMX', '<Thrall comienza a leer la carta.>$B$BAsí que los elfos de sangre finalmente se encargaron de su pequeño problema. No es de extrañar que haya sido necesaria tu ayuda y la de todo un regimiento de Renegados para hacer el trabajo.$B$B<El Jefe de Guerra se echa a reír.>$B$BSupongo que no hay forma de detener esto. Al final, los necesitamos tanto como ellos nos necesitan a nosotros.', 0);
-- 9814 ¡Champiñones fulminantes, colega!
-- https://es.wowhead.com/quest=9814
SET @ID := 9814;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes los champiñones, colega?', 0),
(@ID, 'esMX', '¿Ya tienes los champiñones, colega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es excelente, $gtío:tía;!$B$BAtiende. ¡Como has jugado limpio y has ayudado con los champiñones, te dejo apuntarte a la diversión!', 0),
(@ID, 'esMX', '¡Eso es excelente, $gtío:tía;!$B$BAtiende. ¡Como has jugado limpio y has ayudado con los champiñones, te dejo apuntarte a la diversión!', 0);
-- 9815 Bucear en lodo
-- https://es.wowhead.com/quest=9815
SET @ID := 9815;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No dejes nada de lodo contaminado!', 0),
(@ID, 'esMX', '¡No dejes nada de lodo contaminado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Anillo de la Tierra te da las gracias, $n. También los elementos te dan las gracias. Tus continuos esfuerzos por limpiar nuestro mundo no pasan desapercibidos.', 0),
(@ID, 'esMX', 'El Anillo de la Tierra te da las gracias, $n. También los elementos te dan las gracias. Tus continuos esfuerzos por limpiar nuestro mundo no pasan desapercibidos.', 0);
-- 9816 Mascotas adorables
-- https://es.wowhead.com/quest=9816
SET @ID := 9816;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Suelta a los murlocs en la Aldea Dagapantano', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El médico brujo Torghast sonríe .>$B¿A los pequeños Perdidos les gustó su regalo?', 0),
(@ID, 'esMX', '<El médico brujo Torghast sonríe .>$B¿A los pequeños Perdidos les gustó su regalo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Espero que se lo pasaran bien!', 0),
(@ID, 'esMX', '¡Excelente! ¡Espero que se lo pasaran bien!', 0);
-- 9817 Líder de los Escamas de Sangre
-- https://es.wowhead.com/quest=9817
SET @ID := 9817;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás aquí para reclamar la recompensa por Fyashe? Esa es la mejor noticia que he escuchado en todo el día.', 0),
(@ID, 'esMX', '¿Estás aquí para reclamar la recompensa por Fyashe? Esa es la mejor noticia que he escuchado en todo el día.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apuesto a que los Escamas de Sangre se lo pensarán dos veces antes de volver a atacar a nuestros exploradores de la expedición. Acepta esto como recompensa, $n. Te lo has ganado.', 0),
(@ID, 'esMX', 'Apuesto a que los Escamas de Sangre se lo pensarán dos veces antes de volver a atacar a nuestros exploradores de la expedición. Acepta esto como recompensa, $n. Te lo has ganado.', 0);
-- 9818 Bajo la tierra
-- https://es.wowhead.com/quest=9818
SET @ID := 9818;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Parece que Gordawg está asintiendo.>$B$BSiéntate.', 0),
(@ID, 'esMX', '<Parece que Gordawg está asintiendo.>$B$BSiéntate.', 0);
-- 9819 La tierra torturada
-- https://es.wowhead.com/quest=9819
SET @ID := 9819;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ellos duermen?', 0),
(@ID, 'esMX', '¿Ellos duermen?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gordawg asiente con la cabeza.>$B$BMuy bien. Ahora los espíritus duermen.', 0),
(@ID, 'esMX', '<Gordawg asiente con la cabeza.>$B$BMuy bien. Ahora los espíritus duermen.', 0);
-- 9820 SE BUSCA: Jefe Grog'ak
-- https://es.wowhead.com/quest=9820
SET @ID := 9820;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tenemos ahí, $n?', 0),
(@ID, 'esMX', '¿Qué tenemos ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Sin embargo, la presencia de esos ogros tan cerca de nuestra avanzada me tiene preocupado. Parece ser que llevan algún tiempo viniendo desde las montañas del norte.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Sin embargo, la presencia de esos ogros tan cerca de nuestra avanzada me tiene preocupado. Parece ser que llevan algún tiempo viniendo desde las montañas del norte.', 0);
-- 9821 Comiendo condenación
-- https://es.wowhead.com/quest=9821
SET @ID := 9821;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gordawg come esta roca. Gordawg encuentra usurpador. ¡Traer roca!', 0),
(@ID, 'esMX', 'Gordawg come esta roca. Gordawg encuentra usurpador. ¡Traer roca!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gordawg escupe la roca masticada, lanzándote una lluvia de escombros.>$B$BVeneno. Estas rocas no son Nagrand. Estas rocas son veneno. Tú destruir roca venenosa. Tú encontrar usurpador.', 0),
(@ID, 'esMX', '<Gordawg escupe la roca masticada, lanzándote una lluvia de escombros.>$B$BVeneno. Estas rocas no son Nagrand. Estas rocas son veneno. Tú destruir roca venenosa. Tú encontrar usurpador.', 0);
-- 9822 Ataque inminente
-- https://es.wowhead.com/quest=9822
SET @ID := 9822;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado alguna prueba de los planes de los ogros?', 0),
(@ID, 'esMX', '¿Has encontrado alguna prueba de los planes de los ogros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El cazador de las Sombras Denjai examina los planes.>$B$B¡Lo sabía! La peste de los ogros siempre lleva una amenaza implícita. Ahora que tenemos pruebas de lo que pretenden hacer, debemos actuar antes que ellos.', 0),
(@ID, 'esMX', '<El cazador de las Sombras Denjai examina los planes.>$B$B¡Lo sabía! La peste de los ogros siempre lleva una amenaza implícita. Ahora que tenemos pruebas de lo que pretenden hacer, debemos actuar antes que ellos.', 0);
-- 9823 Nosotros o ellos
-- https://es.wowhead.com/quest=9823
SET @ID := 9823;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La amenaza de los Ango\'rosh se cierne sobre nosotros. ¿Has eliminado a su líder?', 0),
(@ID, 'esMX', 'La amenaza de los Ango\'rosh se cierne sobre nosotros. ¿Has eliminado a su líder?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos que celebrar tu victoria sobre los Ango\'rosh, $n. Me pregunto cuánto tiempo pasará antes de que esos ogros encuentren a otro jefe sediento de sangre.$B$BNo importa, estaremos preparados cuando llegue el momento.', 0),
(@ID, 'esMX', 'Tenemos que celebrar tu victoria sobre los Ango\'rosh, $n. Me pregunto cuánto tiempo pasará antes de que esos ogros encuentren a otro jefe sediento de sangre.$B$BNo importa, estaremos preparados cuando llegue el momento.', 0);
-- 9824 Alteraciones arcanas
-- https://es.wowhead.com/quest=9824
SET @ID := 9824;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Lectura del pozo subterráneo', `ObjectiveText2` = 'Lectura del estanque subterráneo', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las lecturas, $n. ¿Las completaste?', 0),
(@ID, 'esMX', 'Las lecturas, $n. ¿Las completaste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas lecturas no auguran nada bueno, $n. Karazhan debería estar emanando todo tipo de corrientes arcanas... en cambio, se ha convertido en un enorme vacío de energía. No hay señales. Nada. Excepto un eco demoníaco muy débil.$B$BEstas son malas noticias, $n.', 0),
(@ID, 'esMX', 'Estas lecturas no auguran nada bueno, $n. Karazhan debería estar emanando todo tipo de corrientes arcanas... en cambio, se ha convertido en un enorme vacío de energía. No hay señales. Nada. Excepto un eco demoníaco muy débil.$B$BEstas son malas noticias, $n.', 0);
-- 9825 Actividad incansable
-- https://es.wowhead.com/quest=9825
SET @ID := 9825;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has obtenido las esencias fantasmales que necesito, $n?', 0),
(@ID, 'esMX', '¿Has obtenido las esencias fantasmales que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fascinante. Estudiaré estas esencias. Te agradezco tu ayuda $n.', 0),
(@ID, 'esMX', 'Fascinante. Estudiaré estas esencias. Te agradezco tu ayuda $n.', 0);
-- 9826 Contacto de Dalaran
-- https://es.wowhead.com/quest=9826
SET @ID := 9826;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alturus te confió esta información? Ese viejo tonto.$B$BSupongo que el daño ya está hecho, también podríamos hacer uso de ti. ¿Supongo que cooperarás?', 0),
(@ID, 'esMX', '¿Alturus te confió esta información? Ese viejo tonto.$B$BSupongo que el daño ya está hecho, también podríamos hacer uso de ti. ¿Supongo que cooperarás?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conoces el Ojo Violeta? No lo parece.', 0),
(@ID, 'esMX', '¿Conoces el Ojo Violeta? No lo parece.', 0);
-- Basidio marchito
-- 9827, 9828
-- https://es.wowhead.com/quest=9827
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9827, 9828) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9827, 'esES', '¿Qué tienes ahí, $n?', 0),
(9828, 'esES', '¿Qué tienes ahí, $n?', 0),
(9827, 'esMX', '¿Qué tienes ahí, $n?', 0),
(9828, 'esMX', '¿Qué tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9827, 9828) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9827, 'esES', 'Parece el basidio de un gigante de la marisma, pero no había visto nunca un basidio en estas condiciones. He oído que los gigantes de El Lodo Muerto han empezado a enfermar, pero la enfermedad está más avanzada de lo que esperaba.$B$BEl Lodo Muerto fue un lago más de la marisma y servía de zona de cría a los gigantes. Con la retirada del agua, parece que los cambios están evitando que los gigantes se reproduzcan. Si esto sigue así, los gigantes podrían desaparecer completamente.', 0),
(9828, 'esES', 'Parece el basidio de un gigante de la marisma, pero no había visto nunca un basidio en estas condiciones. He oído que los gigantes de El Lodo Muerto han empezado a enfermar, pero la enfermedad está más avanzada de lo que esperaba.$B$BEl Lodo Muerto fue un lago más de la marisma y servía de zona de cría a los gigantes. Con la retirada del agua, parece que los cambios están evitando que los gigantes se reproduzcan. Si esto sigue así, los gigantes podrían desaparecer completamente.', 0),
(9827, 'esMX', 'Parece el basidio de un gigante de la marisma, pero no había visto nunca un basidio en estas condiciones. He oído que los gigantes de El Lodo Muerto han empezado a enfermar, pero la enfermedad está más avanzada de lo que esperaba.$B$BEl Lodo Muerto fue un lago más de la marisma y servía de zona de cría a los gigantes. Con la retirada del agua, parece que los cambios están evitando que los gigantes se reproduzcan. Si esto sigue así, los gigantes podrían desaparecer completamente.', 0),
(9828, 'esMX', 'Parece el basidio de un gigante de la marisma, pero no había visto nunca un basidio en estas condiciones. He oído que los gigantes de El Lodo Muerto han empezado a enfermar, pero la enfermedad está más avanzada de lo que esperaba.$B$BEl Lodo Muerto fue un lago más de la marisma y servía de zona de cría a los gigantes. Con la retirada del agua, parece que los cambios están evitando que los gigantes se reproduzcan. Si esto sigue así, los gigantes podrían desaparecer completamente.', 0);
-- 9829 Khadgar
-- https://es.wowhead.com/quest=9829
SET @ID := 9829;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El ojo violeta? No digas más.$B$BMuéstrame este informe del que hablas.', 0),
(@ID, 'esMX', '¿El ojo violeta? No digas más.$B$BMuéstrame este informe del que hablas.', 0);
-- 9830 Veneno letal
-- https://es.wowhead.com/quest=9830
SET @ID := 9830;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quiero demostrar los usos del veneno de sangrador al anacoreta Ahuurn y a todos los demás de Telredor. Aunque para ello voy a necesitar doblar mis suministros.', 0),
(@ID, 'esMX', 'Quiero demostrar los usos del veneno de sangrador al anacoreta Ahuurn y a todos los demás de Telredor. Aunque para ello voy a necesitar doblar mis suministros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por traerme el veneno, $n. Me ayudará mucho y ahora puedo hacer mi demostración sin agotar mis reservas personales.', 0),
(@ID, 'esMX', 'Gracias por traerme el veneno, $n. Me ayudará mucho y ahora puedo hacer mi demostración sin agotar mis reservas personales.', 0);
-- 9831 La entrada a Karazhan
-- https://es.wowhead.com/quest=9831
SET @ID := 9831;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has obtenido el fragmento, $c? Harías bien en no perder tiempo en este asunto.', 0),
(@ID, 'esMX', '¿Has obtenido el fragmento, $c? Harías bien en no perder tiempo en este asunto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. No estaba seguro de que lo lograras.$B$BLos contenedores están encantados con un potente hechizo que enmascara su presencia a ojos indignos. Me alegra ver que no te eludieron.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. No estaba seguro de que lo lograras.$B$BLos contenedores están encantados con un potente hechizo que enmascara su presencia a ojos indignos. Me alegra ver que no te eludieron.', 0);
-- 9832 El segundo y tercer trozo
-- https://es.wowhead.com/quest=9832
SET @ID := 9832;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda de los fragmentos de la llave, $n?', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda de los fragmentos de la llave, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes los fragmentos. Esto es muy impresionante, $n. Ciertamente eres $gdigno:digna; de tener la llave de Karazhan.$BQueda un pequeño problema.', 0),
(@ID, 'esMX', 'Tienes los fragmentos. Esto es muy impresionante, $n. Ciertamente eres $gdigno:digna; de tener la llave de Karazhan.$BQueda un pequeño problema.', 0);
-- 9833 Líneas de comunicación
-- https://es.wowhead.com/quest=9833
SET @ID := 9833;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has avanzado en la seguridad de los caminos?', 0),
(@ID, 'esMX', '¿Has avanzado en la seguridad de los caminos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelentes noticias. Los caminos todavía no son completamente seguros, pero los mensajeros son inteligentes y tienen sus propios recursos.', 0),
(@ID, 'esMX', 'Excelentes noticias. Los caminos todavía no son completamente seguros, pero los mensajeros son inteligentes y tienen sus propios recursos.', 0);
-- 9834 Armadura natural
-- https://es.wowhead.com/quest=9834
SET @ID := 9834;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿Tiene pellejos para Maktu?', 0),
(@ID, 'esMX', '$n, ¿Tiene pellejos para Maktu?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maktu cree que son buenos pellejos. Servirán bien para las armaduras.$B$B¿Quién sabe? Quizás haya los suficientes como para que Maktu haga algunas armaduras para los draenei.', 0),
(@ID, 'esMX', 'Maktu cree que son buenos pellejos. Servirán bien para las armaduras.$B$B¿Quién sabe? Quizás haya los suficientes como para que Maktu haga algunas armaduras para los draenei.', 0);
-- 9835 Invasión de los Ango'rosh
-- https://es.wowhead.com/quest=9835
SET @ID := 9835;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la lucha contra los Ango\'rosh?', 0),
(@ID, 'esMX', '¿Cómo va la lucha contra los Ango\'rosh?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por el momento, hemos contenido la amenaza de los Ango\'rosh, pero me temo que no se rendirán tan fácilmente. He olvidado muchas cosas desde el fin de mi vida como draenei, pero la terquedad de los ogros es un recuerdo imborrable.', 0),
(@ID, 'esMX', 'Por el momento, hemos contenido la amenaza de los Ango\'rosh, pero me temo que no se rendirán tan fácilmente. He olvidado muchas cosas desde el fin de mi vida como draenei, pero la terquedad de los ogros es un recuerdo imborrable.', 0);
-- 9836 El toque del maestro
-- https://es.wowhead.com/quest=9836
SET @ID := 9836;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién eres y qué quieres?', 0),
(@ID, 'esMX', '¿Quién eres y qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esa llave, la reconozco. Esa es la llave de Kadghar... por supuesto. Pero todavía no se la he dado.', 0),
(@ID, 'esMX', 'Esa llave, la reconozco. Esa es la llave de Kadghar... por supuesto. Pero todavía no se la he dado.', 0);
-- 9837 Regresa junto a Khadgar
-- https://es.wowhead.com/quest=9837
SET @ID := 9837;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Su propia llave? ¡Eso es increíble!$B$BNo siento ninguna perturbación en nuestra línea de tiempo, así que supongo que estaba destinado a ocurrir todo el tiempo. No hay vuelta atrás ahora, $n. La llave es tuya y solo tuya.', 0),
(@ID, 'esMX', '¿Su propia llave? ¡Eso es increíble!$B$BNo siento ninguna perturbación en nuestra línea de tiempo, así que supongo que estaba destinado a ocurrir todo el tiempo. No hay vuelta atrás ahora, $n. La llave es tuya y solo tuya.', 0);
-- 9838 El Ojo Violeta
-- https://es.wowhead.com/quest=9838
SET @ID := 9838;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envié a entregar un informe y regresas con una llave de este lugar? Debe haber más para ti de lo que parece, $n.', 0),
(@ID, 'esMX', '¿Te envié a entregar un informe y regresas con una llave de este lugar? Debe haber más para ti de lo que parece, $n.', 0);
-- 9839 Señor supremo Puño Sajante
-- https://es.wowhead.com/quest=9839
SET @ID := 9839;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho? ¿Has tratado con el Señor supremo Puño Sajante?', 0),
(@ID, 'esMX', '¿Está hecho? ¿Has tratado con el Señor supremo Puño Sajante?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! Tienes nuestro agradecimiento por tu ayuda para asegurar nuestra posición del Puerto Orebor. Informaré sobre tus hazañas a la ciudad Kurenai de Telaar, en Nagrand. Habrá muchas oportunidades para que nuestros pueblos trabajen juntos.', 0),
(@ID, 'esMX', '¡Por fin! Tienes nuestro agradecimiento por tu ayuda para asegurar nuestra posición del Puerto Orebor. Informaré sobre tus hazañas a la ciudad Kurenai de Telaar, en Nagrand. Habrá muchas oportunidades para que nuestros pueblos trabajen juntos.', 0);
-- 9840 Evaluando la situación
-- https://es.wowhead.com/quest=9840
SET @ID := 9840;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Koren te mira con expresión insegura.>$B$BNo sé nada de ese Ojo Violeta del que hablas. Un herrero es todo lo que soy.', 0),
(@ID, 'esMX', '<Koren te mira con expresión insegura.>$B$BNo sé nada de ese Ojo Violeta del que hablas. Un herrero es todo lo que soy.', 0);
-- 9841 Aguijoneando los aguijoneros
-- https://es.wowhead.com/quest=9841
SET @ID := 9841;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El sonido parece haberse perdido en la distancia. ¿Es una ilusión o realmente has hecho algo al respecto?', 0),
(@ID, 'esMX', 'El sonido parece haberse perdido en la distancia. ¿Es una ilusión o realmente has hecho algo al respecto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso pensaba. Ya puedo sentir la diferencia. Por fin podré volver a trabajar gracias a ti. Si alguna vez necesitas suministros para algún oficio, no te olvides del viejo Gambarinka.', 0),
(@ID, 'esMX', 'Eso pensaba. Ya puedo sentir la diferencia. Por fin podré volver a trabajar gracias a ti. Si alguna vez necesitas suministros para algún oficio, no te olvides del viejo Gambarinka.', 0);
-- 9842 Las hojas más afiladas
-- https://es.wowhead.com/quest=9842
SET @ID := 9842;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido algunas de esas hojas de cercenadores Colmillo de la Marisma?', 0),
(@ID, 'esMX', '¿Has conseguido algunas de esas hojas de cercenadores Colmillo de la Marisma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Con esto tendré suministros durante un tiempo! Creo que algunos han empezado a darse cuenta. He tenido varias ofertas para comprar mis hojas. Venderlas de contrabando podría proporcionarme un mejor negocio que mis ventas normales.', 0),
(@ID, 'esMX', '¡Con esto tendré suministros durante un tiempo! Creo que algunos han empezado a darse cuenta. He tenido varias ofertas para comprar mis hojas. Venderlas de contrabando podría proporcionarme un mejor negocio que mis ventas normales.', 0);
-- 9843 Los apuntes de Keanna
-- https://es.wowhead.com/quest=9843
SET @ID := 9843;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los apuntes de Keanna... ¿los has encontrado?', 0),
(@ID, 'esMX', 'Los apuntes de Keanna... ¿los has encontrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los apuntes! Espero que la información que necesitamos esté aquí, $n.', 0),
(@ID, 'esMX', '¡Los apuntes! Espero que la información que necesitamos esté aquí, $n.', 0);
-- 9844 Una presencia demoníaca
-- https://es.wowhead.com/quest=9844
SET @ID := 9844;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Presencia demoníaca destruida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me da miedo preguntar, $n. ¿Qué ha sido de la situación en Karazhan?', 0),
(@ID, 'esMX', 'Me da miedo preguntar, $n. ¿Qué ha sido de la situación en Karazhan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo hiciste! ¡Sí, las lecturas vuelven a ser normales!$B$BDebemos darle esta noticia a Cedric. Él estará muy impresionado con tu logro.', 0),
(@ID, 'esMX', '¡Lo hiciste! ¡Sí, las lecturas vuelven a ser normales!$B$BDebemos darle esta noticia a Cedric. Él estará muy impresionado con tu logro.', 0);
-- 9845 Competición de pesca
-- https://es.wowhead.com/quest=9845
SET @ID := 9845;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es seguro para mí volver a pescar?', 0),
(@ID, 'esMX', '¿Es seguro para mí volver a pescar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué ganas tengo de volver a pescar! Ahora podré volver al pueblo con algún pescado en la cesta y Gambarinka no volverá a reírse de mí.', 0),
(@ID, 'esMX', '¡Qué ganas tengo de volver a pescar! Ahora podré volver al pueblo con algún pescado en la cesta y Gambarinka no volverá a reírse de mí.', 0);
-- 9846 Espíritus de los Feropantanos
-- https://es.wowhead.com/quest=9846
SET @ID := 9846;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los tótems?', 0),
(@ID, 'esMX', '¿Has conseguido los tótems?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... Parecen divididos entre imágenes de un espíritu serpiente y un espíritu pájaro. Ningún trol de Lanza Negra digno adoraría a un pájaro. Son espíritus débiles y caprichosos. Son para los Amani.$B$BPero la serpiente, $n, la serpiente tiene mucho poder; ese es el espíritu que debería estudiar.', 0),
(@ID, 'esMX', 'Mmm... Parecen divididos entre imágenes de un espíritu serpiente y un espíritu pájaro. Ningún trol de Lanza Negra digno adoraría a un pájaro. Son espíritus débiles y caprichosos. Son para los Amani.$B$BPero la serpiente, $n, la serpiente tiene mucho poder; ese es el espíritu que debería estudiar.', 0);
-- 9847 ¿Un espíritu aliado?
-- https://es.wowhead.com/quest=9847
SET @ID := 9847;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Invocar al espíritu serpiente', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste invocar al espíritu Feropantano?', 0),
(@ID, 'esMX', '¿Pudiste invocar al espíritu Feropantano?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Le cuentas al vidente Janidi lo que ocurrió cuando utilizaste el tótem.>$B$B¿El espíritu te atacó? Debe de tener mayor afinidad con Los Perdidos de lo que había pensado. No hay forma de obligarle a que me sirva fácilmente. Tendré que buscar una nueva fuente de poder en este mísero mundo.', 0),
(@ID, 'esMX', '<Le cuentas al vidente Janidi lo que ocurrió cuando utilizaste el tótem.>$B$B¿El espíritu te atacó? Debe de tener mayor afinidad con Los Perdidos de lo que había pensado. No hay forma de obligarle a que me sirva fácilmente. Tendré que buscar una nueva fuente de poder en este mísero mundo.', 0);
