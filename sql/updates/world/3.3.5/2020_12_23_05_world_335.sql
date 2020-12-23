-- 9207 Muestras de mena de Sondaluz
-- https://es.wowhead.com/quest=9207
SET @ID := 9207;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué puedo ayudarte, $c?', 0),
(@ID, 'esMX', '¿En qué puedo ayudarte, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mi aprendiza no fue capaz de ocuparse de esto ella sola? Tendré que hablar con ella cuando vuelva, con gnolls o sin ellos. Y hablando de la reina de Roma, ¿por qué no ha vuelto contigo?$B$B<El magister suspira.>$B$BMenuda fierecilla, no va a ser fácil instruirla debidamente. Gracias, $c, por traerme estas muestras. Esperamos poder descubrir alguna propiedad especial en ellas que ayude en la lucha contra la Plaga.$B$BAcepta esta moneda como muestra de mi agradecimiento.', 0),
(@ID, 'esMX', '¿Mi aprendiza no fue capaz de ocuparse de esto ella sola? Tendré que hablar con ella cuando vuelva, con gnolls o sin ellos. Y hablando de la reina de Roma, ¿por qué no ha vuelto contigo?$B$B<El magister suspira.>$B$BMenuda fierecilla, no va a ser fácil instruirla debidamente. Gracias, $c, por traerme estas muestras. Esperamos poder descubrir alguna propiedad especial en ellas que ayude en la lucha contra la Plaga.$B$BAcepta esta moneda como muestra de mi agradecimiento.', 0);
-- 747 Empieza la caza
-- https://es.classic.wowhead.com/quest=747
SET @ID := 747;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Conseguir carne y plumas para la tribu es el primer paso para probar tu valor ante el Jefe.', 0),
(@ID, 'esMX', 'Conseguir carne y plumas para la tribu es el primer paso para probar tu valor ante el Jefe.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los tauren de Narache te dan las gracias, $n. Prometes mucho.', 0),
(@ID, 'esMX', 'Los tauren de Narache te dan las gracias, $n. Prometes mucho.', 0);
-- 752 Una humilde contribución
-- https://es.classic.wowhead.com/quest=752
SET @ID := 752;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido hasta aquí para ayudar a una anciana? Ay, ay, ¡qué admirable!', 0),
(@ID, 'esMX', '¿Has venido hasta aquí para ayudar a una anciana? Ay, ay, ¡qué admirable!', 0);
-- 753 Una humilde contribución
-- https://es.classic.wowhead.com/quest=753
SET @ID := 753;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que estás de vuelta. ¿Tienes noticias de la abuela Viento de Halcón?', 0),
(@ID, 'esMX', 'Parece que estás de vuelta. ¿Tienes noticias de la abuela Viento de Halcón?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, te dijo que trajeras este cántaro de agua. Ya veo.$B$BTu deseo de ayudar a los tauren del Campamento Narache me dice que algún día honrarás a la tribu en Cima del Trueno.', 0),
(@ID, 'esMX', 'Ah, te dijo que trajeras este cántaro de agua. Ya veo.$B$BTu deseo de ayudar a los tauren del Campamento Narache me dice que algún día honrarás a la tribu en Cima del Trueno.', 0);
-- 755 Los ritos de la Madre Tierra
-- https://es.classic.wowhead.com/quest=755
SET @ID := 755;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía el Jefe Viento de Halcón? Los Ritos de la Madre Tierra son un asunto de cierta envergadura...', 0),
(@ID, 'esMX', '¿Te envía el Jefe Viento de Halcón? Los Ritos de la Madre Tierra son un asunto de cierta envergadura...', 0);
-- 750 La caza sigue
-- https://es.classic.wowhead.com/quest=750
SET @ID := 750;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si consigues pelambres para la tribu, hablaré de tu valor a mi padre, el Jefe Viento de Halcón.', 0),
(@ID, 'esMX', 'Si consigues pelambres para la tribu, hablaré de tu valor a mi padre, el Jefe Viento de Halcón.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los tauren de Narache te agradecen estas provisiones, $n. Con esa habilidad para la caza, algún día alcanzarás el nivel de reputación venerado con Cima del Trueno.', 0),
(@ID, 'esMX', 'Los tauren de Narache te agradecen estas provisiones, $n. Con esa habilidad para la caza, algún día alcanzarás el nivel de reputación venerado con Cima del Trueno.', 0);
-- 3094 La nota verdeante
-- https://es.classic.wowhead.com/quest=3094
SET @ID := 3094;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno que hayas llegado; los espíritus de los antepasados están inquietos en todo Mulgore, pero no sé por qué. Siempre debes escuchar a la naturaleza y ser su Avatar. No lo olvides.', 0),
(@ID, 'esMX', 'Es bueno que hayas llegado; los espíritus de los antepasados están inquietos en todo Mulgore, pero no sé por qué. Siempre debes escuchar a la naturaleza y ser su Avatar. No lo olvides.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque estamos relacionados, no esperes una buena acogida de los elfos de la noche; su orgullo no les deja ver, aunque eso no es problema nuestro. Preocúpate solo de las enseñanzas de la Madre Tierra y de las lecciones que te daré.$B$BVen a verme a menudo, $n. Descubrirás que la Madre Tierra recompensa a los más aplicados.', 0),
(@ID, 'esMX', 'Aunque estamos relacionados, no esperes una buena acogida de los elfos de la noche; su orgullo no les deja ver, aunque eso no es problema nuestro. Preocúpate solo de las enseñanzas de la Madre Tierra y de las lecciones que te daré.$B$BVen a verme a menudo, $n. Descubrirás que la Madre Tierra recompensa a los más aplicados.', 0);
-- 757 Rito de la fuerza
-- https://es.classic.wowhead.com/quest=757
SET @ID := 757;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado el Rito de la Fuerza, $n? Quiero una prueba de tus acciones contra nuestros enemigos, los Erizapúas.', 0),
(@ID, 'esMX', '¿Has completado el Rito de la Fuerza, $n? Quiero una prueba de tus acciones contra nuestros enemigos, los Erizapúas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has superado el primero de los Ritos de la Madre Tierra. La tribu estará orgullosa.', 0),
(@ID, 'esMX', 'Has superado el primero de los Ritos de la Madre Tierra. La tribu estará orgullosa.', 0);
-- 3376 La cabeza de Cornapunta
-- https://es.classic.wowhead.com/quest=3376
SET @ID := 3376;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cornapunta no nos dará más problemas; quiero su cabeza, $n.$B$BLos tauren vivimos para cazar y la mejor presa es aquella que podría contraatacar. Si consigues cumplir tu tarea, empezarás a entender esto que digo.', 0),
(@ID, 'esMX', 'Cornapunta no nos dará más problemas; quiero su cabeza, $n.$B$BLos tauren vivimos para cazar y la mejor presa es aquella que podría contraatacar. Si consigues cumplir tu tarea, empezarás a entender esto que digo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy se ha hecho justicia gracias a ti, $n. Que esto sirva de advertencia a todos cuantos amenazan nuestro hogar.$B$BAcepta esta recompensa por tu hazaña, $c.', 0),
(@ID, 'esMX', 'Hoy se ha hecho justicia gracias a ti, $n. Que esto sirva de advertencia a todos cuantos amenazan nuestro hogar.$B$BAcepta esta recompensa por tu hazaña, $c.', 0);
-- 780 Los jabaguerreros
-- https://es.classic.wowhead.com/quest=780
SET @ID := 780;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los jabaguerreros siguen atacando. ¿Me traes los hocicos y los costillares?', 0),
(@ID, 'esMX', 'Los jabaguerreros siguen atacando. ¿Me traes los hocicos y los costillares?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Con esto prepararé un estofado y de paso hemos dado una lección a esos Erizapúas.', 0),
(@ID, 'esMX', 'Excelente. Con esto prepararé un estofado y de paso hemos dado una lección a esos Erizapúas.', 0);
-- 763 Los ritos de la Madre Tierra
-- https://es.classic.wowhead.com/quest=763
SET @ID := 763;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae por aquí, $c?', 0),
(@ID, 'esMX', '¿Qué te trae por aquí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, vienes de parte del Jefe Viento de Halcón! Sus grabados indican que te considera muy especial.', 0),
(@ID, 'esMX', '¡Ah, vienes de parte del Jefe Viento de Halcón! Sus grabados indican que te considera muy especial.', 0);
-- 1656 Una tarea por terminar
-- https://es.classic.wowhead.com/quest=1656
SET @ID := 1656;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, ¿querías algo?$B$BEl viaje desde la Mesa puede ser terrible para algunos y delicioso para otros. ¿En qué grupo estás tú?', 0),
(@ID, 'esMX', 'Hola, ¿querías algo?$B$BEl viaje desde la Mesa puede ser terrible para algunos y delicioso para otros. ¿En qué grupo estás tú?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, las pieles. Gracias.$B$BHan llegado antes de lo que esperaba; podremos hacer buenas mantas.$B$BQuédate todo el tiempo que quieras; la posada siempre está abierta. Y dormir bien es importante, sobre todo cuando viajas.', 0),
(@ID, 'esMX', 'Ah, las pieles. Gracias.$B$BHan llegado antes de lo que esperaba; podremos hacer buenas mantas.$B$BQuédate todo el tiempo que quieras; la posada siempre está abierta. Y dormir bien es importante, sobre todo cuando viajas.', 0);
-- 745 Compartir la tierra
-- https://es.classic.wowhead.com/quest=745
SET @ID := 745;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los Crines Pálidas hubieran respetado más la tierra y sus habitantes, este conflicto nunca se habría producido.', 0),
(@ID, 'esMX', 'Si los Crines Pálidas hubieran respetado más la tierra y sus habitantes, este conflicto nunca se habría producido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Es importante respetar la tierra y a sus criaturas. La vida y la muerte forman un círculo necesario, la una no puede existir sin la otra. Reflexiona sobre esto y no lo olvides nunca.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Es importante respetar la tierra y a sus criaturas. La vida y la muerte forman un círculo necesario, la una no puede existir sin la otra. Reflexiona sobre esto y no lo olvides nunca.', 0);
-- 767 Rito de la Visión
-- https://es.classic.wowhead.com/quest=767
SET @ID := 767;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Presentía tu llegada, $c. Es fácil reconocer a quien está intentando superar los Ritos de la Madre Tierra.', 0),
(@ID, 'esMX', 'Presentía tu llegada, $c. Es fácil reconocer a quien está intentando superar los Ritos de la Madre Tierra.', 0);
-- 743 Las Viento Furioso son un peligro
-- https://es.classic.wowhead.com/quest=743
SET @ID := 743;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las Viento Furioso son mortíferas; su potencia en combate solo es comparable a su sed de sangre.', 0),
(@ID, 'esMX', 'Las Viento Furioso son mortíferas; su potencia en combate solo es comparable a su sed de sangre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Ha llegado el momento de seguir tu viaje; que el viento siempre esté a tu espalda.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Ha llegado el momento de seguir tu viaje; que el viento siempre esté a tu espalda.', 0);
-- 748 Pozos envenenados
-- https://es.classic.wowhead.com/quest=748
SET @ID := 748;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes lo que te pedí?', 0),
(@ID, 'esMX', '¿Traes lo que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Voy a imbuir su poder en un tótem purificador.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Voy a imbuir su poder en un tótem purificador.', 0);
-- 761 La caza de los aguilones
-- https://es.classic.wowhead.com/quest=761
SET @ID := 761;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes las plumas de aguilón?', 0),
(@ID, 'esMX', '¿Me traes las plumas de aguilón?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que esto no ha sido fácil, $n. Has probado tu valor; nos alegramos de tenerte en el Poblado Pezuña de Sangre.', 0),
(@ID, 'esMX', 'Sé que esto no ha sido fácil, $n. Has probado tu valor; nos alegramos de tenerte en el Poblado Pezuña de Sangre.', 0);
-- 771 Rito de la Visión
-- https://es.classic.wowhead.com/quest=771
SET @ID := 771;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando me traigas las piedras de pozo y las bellotas ámbar, te prepararé el Agua de los Videntes.', 0),
(@ID, 'esMX', 'Cuando me traigas las piedras de pozo y las bellotas ámbar, te prepararé el Agua de los Videntes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has aprendido a recolectar en nuestra tierra sagrada, $n. En un momento te daré el Agua de los Videntes.', 0),
(@ID, 'esMX', 'Veo que has aprendido a recolectar en nuestra tierra sagrada, $n. En un momento te daré el Agua de los Videntes.', 0);
-- 768 Recolecta cuero
-- https://es.classic.wowhead.com/quest=768
SET @ID := 768;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo. ¿Has estado cazando? ¿Tienes mis pieles?', 0),
(@ID, 'esMX', 'Hola de nuevo. ¿Has estado cazando? ¿Tienes mis pieles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas pieles son excelentes. Con ellas podré hacer objetos de cuero de primera calidad.$B$BToma, $n. Coge esto a cambio...', 0),
(@ID, 'esMX', 'Estas pieles son excelentes. Con ellas podré hacer objetos de cuero de primera calidad.$B$BToma, $n. Coge esto a cambio...', 0);
-- 11129 ¡Kyle ha desaparecido!
-- https://es.wowhead.com/quest=11129
SET @ID := 11129;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Kyle alimentado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado a Kyle?', 0),
(@ID, 'esMX', '¿Has encontrado a Kyle?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gran trabajo, $n! Kyle volvió a casa justo después de comer y se fue directo a dormir. Gracias por tu ayuda.', 0),
(@ID, 'esMX', '¡Gran trabajo, $n! Kyle volvió a casa justo después de comer y se fue directo a dormir. Gracias por tu ayuda.', 0);
-- 749 La Caravana Devastada
-- https://es.classic.wowhead.com/quest=749
SET @ID := 749;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja tiene el sello de Ventura y Cía. en todos los lados. En el lateral se indica que el contenido debe ser procesado en una de sus plantas centrales.', 0),
(@ID, 'esMX', 'La caja tiene el sello de Ventura y Cía. en todos los lados. En el lateral se indica que el contenido debe ser procesado en una de sus plantas centrales.', 0);
-- 754 La purificación de Pezuña Invernal
-- https://es.classic.wowhead.com/quest=754
SET @ID := 754;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los animales ya están bebiendo del pozo.$B$BHas prestado un gran servicio a la tierra y a los $r, $n.', 0),
(@ID, 'esMX', 'Los animales ya están bebiendo del pozo.$B$BHas prestado un gran servicio a la tierra y a los $r, $n.', 0);
-- 746 Una excavación de los enanos
-- https://es.classic.wowhead.com/quest=746
SET @ID := 746;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Tienes las herramientas rotas? La excavación de los enanos enfurecerá a los kodos de Mulgore. ¡Debes detener esta profanación!', 0),
(@ID, 'esMX', 'Hola, $n. ¿Tienes las herramientas rotas? La excavación de los enanos enfurecerá a los kodos de Mulgore. ¡Debes detener esta profanación!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n, esto tranquilizará a las bestias de Mulgore. Y enseñará a los enanos que horadar la tierra no les llevará a alcanzar la sabiduría.', 0),
(@ID, 'esMX', 'Gracias, $n, esto tranquilizará a las bestias de Mulgore. Y enseñará a los enanos que horadar la tierra no les llevará a alcanzar la sabiduría.', 0);
-- 756 El tótem de Tronacuerno
-- https://es.classic.wowhead.com/quest=756
SET @ID := 756;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes lo que te pedí, $n? El Pozo Tronacuerno se corrompe más cada minuto que pasa.', 0),
(@ID, 'esMX', '¿Traes lo que te pedí, $n? El Pozo Tronacuerno se corrompe más cada minuto que pasa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. La pureza con la que cazan estas bestias es vital para crear el tótem de limpieza.$B$BLos goblins nunca aprenderán la diferencia entre explotar la tierra y vivir en armonía con ella.', 0),
(@ID, 'esMX', 'Gracias, $n. La pureza con la que cazan estas bestias es vital para crear el tótem de limpieza.$B$BLos goblins nunca aprenderán la diferencia entre explotar la tierra y vivir en armonía con ella.', 0);
-- 766 Mazzranache
-- https://es.classic.wowhead.com/quest=766
SET @ID := 766;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La fiebre empeora y mi consciencia empieza a perderse en pesadillas delirantes... Tenía que haber sabido que no podría con una bestia que mi abuelo no fue capaz de derrotar...$B$B¿Tienes los ingredientes para el remedio? Temo que si no acabo con la infección pronto, no saldré de esta.', 0),
(@ID, 'esMX', 'La fiebre empeora y mi consciencia empieza a perderse en pesadillas delirantes... Tenía que haber sabido que no podría con una bestia que mi abuelo no fue capaz de derrotar...$B$B¿Tienes los ingredientes para el remedio? Temo que si no acabo con la infección pronto, no saldré de esta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, gracias, $n. Con los objetos que me has traído, podré fabricar el remedio que necesito para impedir que la infección se extienda y, finalmente, curarla por completo. Te debo la vida.$B$BPero nunca olvidaré el terrible chillido de Mazzranache cuando se abalanzó sobre mí, ni el fogonazo de color de su pico al descender...$B$BVe con cautela en tus viajes.', 0),
(@ID, 'esMX', 'Ah, gracias, $n. Con los objetos que me has traído, podré fabricar el remedio que necesito para impedir que la infección se extienda y, finalmente, curarla por completo. Te debo la vida.$B$BPero nunca olvidaré el terrible chillido de Mazzranache cuando se abalanzó sobre mí, ni el fogonazo de color de su pico al descender...$B$BVe con cautela en tus viajes.', 0);
