-- 9014 Guardar lo mejor para el final
-- https://es.classic.wowhead.com/quest=9014
SET @ID := 9014;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar las piezas de magister a cambio de tu nueva corona y toga de hechicero?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar las piezas de magister a cambio de tu nueva corona y toga de hechicero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $n. Tengo una deuda contigo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 9015 El reto
-- https://es.classic.wowhead.com/quest=9015
SET @ID := 9015;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Equipo de Theldren derrotado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto, $n!', 0),
(@ID, 'esMX', '¡Has vuelto, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado parte del medallón, $n?', 0),
(@ID, 'esMX', '¿Has recuperado parte del medallón, $n?', 0);
-- 9023 El veneno perfecto
-- https://es.classic.wowhead.com/quest=9023
SET @ID := 9023;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Será mejor que lleves compañía para este trabajo, $n.', 0),
(@ID, 'esMX', 'Será mejor que lleves compañía para este trabajo, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes la gratitud de Ravenholdt! ¡Elige lo que quieras!', 0),
(@ID, 'esMX', '¡Tienes la gratitud de Ravenholdt! ¡Elige lo que quieras!', 0);
-- 9024 El presentimiento de Aristan
-- https://es.classic.wowhead.com/quest=9024
SET @ID := 9024;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', '¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entiendo a Aristan, pero creo que exagera. Me parece que ha olvidado lo que es ser joven y ardiente.$B$BPero no se lo vayas a decir; no creo que se lo tomara bien.', 0),
(@ID, 'esMX', 'Entiendo a Aristan, pero creo que exagera. Me parece que ha olvidado lo que es ser joven y ardiente.$B$BPero no se lo vayas a decir; no creo que se lo tomara bien.', 0);
-- 9025 El descubrimiento de Morgan
-- https://es.classic.wowhead.com/quest=9025
SET @ID := 9025;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me inquieta sobremanera comprobar que mis sospechas eran correctas. Debemos ser cautos.$B$BTen, por el perfume y la colonia.', 0),
(@ID, 'esMX', 'Me inquieta sobremanera comprobar que mis sospechas eran correctas. Debemos ser cautos.$B$BTen, por el perfume y la colonia.', 0);
-- 9026 Rastrear la fuente
-- https://es.classic.wowhead.com/quest=9026
SET @ID := 9026;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, acabo de recibir el perfume y la colonia y se venden muy bien; vamos, me los quitan de las manos.$B$BLa verdad es que es un poco aburrido, ahora todo el mundo huele igual.', 0),
(@ID, 'esMX', 'Sí, acabo de recibir el perfume y la colonia y se venden muy bien; vamos, me los quitan de las manos.$B$BLa verdad es que es un poco aburrido, ahora todo el mundo huele igual.', 0);
-- 9027 Rastrear la fuente
-- https://es.classic.wowhead.com/quest=9027
SET @ID := 9027;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, estas fragancias son el éxito de la temporada; no deja de venir gente preguntando por ellas.$B$BAquí se han agotado las existencias; prueba con Allison, la posadera de La Rosa Áurea.$B$BPero date prisa; te digo que esas fragancias son irresistibles.', 0),
(@ID, 'esMX', 'Sí, estas fragancias son el éxito de la temporada; no deja de venir gente preguntando por ellas.$B$BAquí se han agotado las existencias; prueba con Allison, la posadera de La Rosa Áurea.$B$BPero date prisa; te digo que esas fragancias son irresistibles.', 0);
-- 9028 El descubrimiento de la fuente
-- https://es.classic.wowhead.com/quest=9028
SET @ID := 9028;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, yo creé esas fragancias. ¿A que son magníficas?$B$BLos soldados de la Alianza y de la Horda estarán tan distraídos con sus amoríos que no podrán detener el avance del Consejo de la Sombra.$B$BEstarán debilitados y desprevenidos.$B$BEs un truco tan sencillo que no comprendo cómo no se me ocurrió antes. Y tú no puedes hacer nada para evitarlo.', 0),
(@ID, 'esMX', 'Sí, yo creé esas fragancias. ¿A que son magníficas?$B$BLos soldados de la Alianza y de la Horda estarán tan distraídos con sus amoríos que no podrán detener el avance del Consejo de la Sombra.$B$BEstarán debilitados y desprevenidos.$B$BEs un truco tan sencillo que no comprendo cómo no se me ocurrió antes. Y tú no puedes hacer nada para evitarlo.', 0);
-- 9029 Una caldera burbujeante
-- https://es.classic.wowhead.com/quest=9029
SET @ID := 9029;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Del caldero emana un aroma agradable.', 0),
(@ID, 'esMX', 'Del caldero emana un aroma agradable.', 0);
-- 9033 Ecos de Guerra
-- https://es.classic.wowhead.com/quest=9033
SET @ID := 9033;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deber, honor, dedicación... ¿Qué significan estas palabras para ti?', 0),
(@ID, 'esMX', 'Deber, honor, dedicación... ¿Qué significan estas palabras para ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Recibirás tu recompensa mediante los servicios de los habitantes de la Capilla de la Esperanza de la Luz.', 0),
(@ID, 'esMX', '¡Buen trabajo! Recibirás tu recompensa mediante los servicios de los habitantes de la Capilla de la Esperanza de la Luz.', 0);
-- 9034 La coraza acorator
-- https://es.classic.wowhead.com/quest=9034
SET @ID := 9034;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer una coraza acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer una coraza acorator.', 0);
-- 9036 Los quijotes acorator
-- https://es.classic.wowhead.com/quest=9036
SET @ID := 9036;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos quijotes acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos quijotes acorator.', 0);
-- 9037 El casco acorator
-- https://es.classic.wowhead.com/quest=9037
SET @ID := 9037;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer un casco acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer un casco acorator.', 0);
-- 9038 Los espaldares acorator
-- https://es.classic.wowhead.com/quest=9038
SET @ID := 9038;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos espaldares acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos espaldares acorator.', 0);
-- 9039 Los escarpes acorator
-- https://es.classic.wowhead.com/quest=9039
SET @ID := 9039;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos escarpes acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos escarpes acorator.', 0);
-- 9040 Los guanteletes acorator
-- https://es.classic.wowhead.com/quest=9040
SET @ID := 9040;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos guanteletes acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos guanteletes acorator.', 0);
-- 9041 Los guardarrenes acorator
-- https://es.classic.wowhead.com/quest=9041
SET @ID := 9041;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos guardarrenes acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos guardarrenes acorator.', 0);
-- 9042 Los brazales acorator
-- https://es.classic.wowhead.com/quest=9042
SET @ID := 9042;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos brazales acorator.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos brazales acorator.', 0);
-- 9043 La túnica de redención
-- https://es.classic.wowhead.com/quest=9043
SET @ID := 9043;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer una Guerrera de redención.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer una Guerrera de redención.', 0);
-- 9044 Las musleras de redención
-- https://es.classic.wowhead.com/quest=9044
SET @ID := 9044;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unas Musleras de redención.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unas Musleras de redención.', 0);
-- 9045 La celada de redención
-- https://es.classic.wowhead.com/quest=9045
SET @ID := 9045;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Eligor señala tu cabeza.>$B$BMantenla cubierta, $n.', 0),
(@ID, 'esMX', '<Eligor señala tu cabeza.>$B$BMantenla cubierta, $n.', 0);
-- 9046 Las bufas de redención
-- https://es.classic.wowhead.com/quest=9046
SET @ID := 9046;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves que estamos en medio de algo, $n?', 0),
(@ID, 'esMX', '¿No ves que estamos en medio de algo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cualquier $c te dirá que la mayor parte de su poder proviene de los hombros. Cuanto más grande, mejor...', 0),
(@ID, 'esMX', 'Cualquier $c te dirá que la mayor parte de su poder proviene de los hombros. Cuanto más grande, mejor...', 0);
-- 9047 Las botas de redención
-- https://es.classic.wowhead.com/quest=9047
SET @ID := 9047;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0),
(@ID, 'esMX', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas botas protegerán tus pies contra los ataques de la Plaga.', 0),
(@ID, 'esMX', 'Estas botas protegerán tus pies contra los ataques de la Plaga.', 0);
-- 9048 Las manoplas de redención
-- https://es.classic.wowhead.com/quest=9048
SET @ID := 9048;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0),
(@ID, 'esMX', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Deja que la Luz atraviese estas manoplas y derribe a tus enemigos!', 0),
(@ID, 'esMX', '¡Deja que la Luz atraviese estas manoplas y derribe a tus enemigos!', 0);
-- 9049 La faja de redención
-- https://es.classic.wowhead.com/quest=9049
SET @ID := 9049;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0),
(@ID, 'esMX', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta faja tendrá dos funciones: 1) Te protegerá y te guiará contra la Plaga y 2) Te hará lucir 10 kilos más $gliviano:liviana;.', 0),
(@ID, 'esMX', 'Esta faja tendrá dos funciones: 1) Te protegerá y te guiará contra la Plaga y 2) Te hará lucir 10 kilos más $gliviano:liviana;.', 0);
-- 9050 Los guardamuñecas de redención
-- https://es.classic.wowhead.com/quest=9050
SET @ID := 9050;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0),
(@ID, 'esMX', 'Debes proporcionarme lo que te he pedido si voy a empezar a crear.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son excepcionalmente rentables de construir, pero ten en cuenta que pueden oxidarse si los salpica demasiado.', 0),
(@ID, 'esMX', 'Estos son excepcionalmente rentables de construir, pero ten en cuenta que pueden oxidarse si los salpica demasiado.', 0);
-- 9051 Prueba de toxicidad
-- https://es.classic.wowhead.com/quest=9051
SET @ID := 9051;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste pacificar a la gran bestia?', 0),
(@ID, 'esMX', '¿Pudiste pacificar a la gran bestia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, gracias por tu valentía y saber hacer.$B$BDime, ¿qué efecto ha tenido la toxina en el demosaurio?', 0),
(@ID, 'esMX', '$n, gracias por tu valentía y saber hacer.$B$BDime, ¿qué efecto ha tenido la toxina en el demosaurio?', 0);
-- 9052 Veneno de Sangrepétalo
-- https://es.classic.wowhead.com/quest=9052
SET @ID := 9052;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido éxito?', 0),
(@ID, 'esMX', '¿Has tenido éxito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin los ingredientes!$B$BCon esto y la tierra de Un\'Goro, no tendré problemas para preparar la toxina.', 0),
(@ID, 'esMX', '¡Al fin los ingredientes!$B$BCon esto y la tierra de Un\'Goro, no tendré problemas para preparar la toxina.', 0);
-- 9053 Un ingrediente mejor
-- https://es.classic.wowhead.com/quest=9053
SET @ID := 9053;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado la vid?', 0),
(@ID, 'esMX', '¿Has recuperado la vid?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin, la toxina se puede crear por completo. No me atrevo a pedirte que se lo vuelvas a aplicar a la criatura, ya te he pedido demasiado.$B$BTienes mi agradecimiento y respeto. Que te vaya bien en tus viajes, $n.', 0),
(@ID, 'esMX', 'Por fin, la toxina se puede crear por completo. No me atrevo a pedirte que se lo vuelvas a aplicar a la criatura, ya te he pedido demasiado.$B$BTienes mi agradecimiento y respeto. Que te vaya bien en tus viajes, $n.', 0);
-- 9054 La guerrera de acechacriptas
-- https://es.classic.wowhead.com/quest=9054
SET @ID := 9054;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los artículos que pedí, $c?', 0),
(@ID, 'esMX', '¿Tienes los artículos que pedí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ellos te temerán, $n.', 0),
(@ID, 'esMX', 'Ellos te temerán, $n.', 0);
-- 9055 Las musleras de acechacriptas
-- https://es.classic.wowhead.com/quest=9055
SET @ID := 9055;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los artículos que pedí, $c?', 0),
(@ID, 'esMX', '¿Tienes los artículos que pedí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que te pongas esta armadura, notarás que tu personalidad está cambiando. Obtendrás una habilidad sobrenatural para matar. Quizás, incluso, ansia de sangre.$B$BQue se sepa que no seré responsable del caos que puedas causar...', 0),
(@ID, 'esMX', 'A medida que te pongas esta armadura, notarás que tu personalidad está cambiando. Obtendrás una habilidad sobrenatural para matar. Quizás, incluso, ansia de sangre.$B$BQue se sepa que no seré responsable del caos que puedas causar...', 0);
-- 9056 La celada de acechacriptas
-- https://es.classic.wowhead.com/quest=9056
SET @ID := 9056;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los artículos que pedí, $c?', 0),
(@ID, 'esMX', '¿Tienes los artículos que pedí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te estás convirtiendo en una criatura temible, $n.', 0),
(@ID, 'esMX', 'Te estás convirtiendo en una criatura temible, $n.', 0);
-- 9057 Las bufas de acechacriptas
-- https://es.classic.wowhead.com/quest=9057
SET @ID := 9057;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Bufas de acechacriptas.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Bufas de acechacriptas.', 0);
-- 9058 Las botas de acechacriptas
-- https://es.classic.wowhead.com/quest=9058
SET @ID := 9058;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Botas de acechacriptas.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Botas de acechacriptas.', 0);
