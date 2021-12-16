-- 10701 Infiltrarse en la Roca Abisal
-- https://es.wowhead.com/quest=10701
SET @ID := 10701;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¡¿Qué?! Date prisa... hay mucho que hacer por aquí.$B$BQuiero hacer que esto despegue algún día, ¿sabes?', 0),
(@ID, 'esMX', '¿Qué? ¡¿Qué?! Date prisa... hay mucho que hacer por aquí.$B$BQuiero hacer que esto despegue algún día, ¿sabes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Ah... te has ocupado de la Roca Abisal. ¡Qué buena noticia!$B$BCon ese pesado de gigante montés fuera de combate, ahora debería ser más fácil explo... eh, administrar los recursos de Las Ruinas Desmoronadas.$B$BMe alegra oír que ya no molestará a esos pobres e inocentes elementales.$B$B¿Cómo puedo pagarte por esto?', 0),
(@ID, 'esMX', '¡Ah! Ah... te has ocupado de la Roca Abisal. ¡Qué buena noticia!$B$BCon ese pesado de gigante montés fuera de combate, ahora debería ser más fácil explo... eh, administrar los recursos de Las Ruinas Desmoronadas.$B$BMe alegra oír que ya no molestará a esos pobres e inocentes elementales.$B$B¿Cómo puedo pagarte por esto?', 0);
-- 10702 Un trabajo ingrato...
-- https://es.wowhead.com/quest=10702
SET @ID := 10702;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Regresa a mí cuando las tierras salvajes estén seguras para que nuestras caravanas las atraviesen.', 0),
(@ID, 'esMX', 'Regresa a mí cuando las tierras salvajes estén seguras para que nuestras caravanas las atraviesen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Si me surge alguna otra cosilla, te encontraré.', 0),
(@ID, 'esMX', '¡Fantástico! Si me surge alguna otra cosilla, te encontraré.', 0);
-- 10703 Ponte las rodilleras...
-- https://es.wowhead.com/quest=10703
SET @ID := 10703;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Regresa a mí cuando las tierras salvajes estén seguras para que nuestras caravanas las atraviesen.', 0),
(@ID, 'esMX', 'Regresa a mí cuando las tierras salvajes estén seguras para que nuestras caravanas las atraviesen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es, buen trabajo! Aquí tienes unas monedas por tus esfuerzos. Si necesito sacar más basura, sabré a quién llamar.', 0),
(@ID, 'esMX', '¡Eso es, buen trabajo! Aquí tienes unas monedas por tus esfuerzos. Si necesito sacar más basura, sabré a quién llamar.', 0);
-- 10704 Cómo infiltrarse en El Arcatraz
-- https://es.wowhead.com/quest=10704
SET @ID := 10704;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Oyes ecos de la voz de A\'dal en tu cabeza.>$B$BHas vuelto. ¿Traes los dos fragmentos de la llave de El Arcatraz?', 0),
(@ID, 'esMX', '<Oyes ecos de la voz de A\'dal en tu cabeza.>$B$BHas vuelto. ¿Traes los dos fragmentos de la llave de El Arcatraz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy impresionado, $n, aunque no esperaba menos de $gun héroe:una heroína; que nos ha devuelto el cristal de Ata\'mal.$B$BEntrégame los otros dos fragmentos y me aseguraré de que se combinan en su forma final. Entonces tendrás acceso a El Arcatraz.', 0),
(@ID, 'esMX', 'Estoy impresionado, $n, aunque no esperaba menos de $gun héroe:una heroína; que nos ha devuelto el cristal de Ata\'mal.$B$BEntrégame los otros dos fragmentos y me aseguraré de que se combinan en su forma final. Entonces tendrás acceso a El Arcatraz.', 0);
-- 10705 El vidente Udalo
-- https://es.wowhead.com/quest=10705
SET @ID := 10705;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace mucho tiempo que el vidente Lengua de ceniza murió. Al darle la vuelta al cuerpo, descubres algo garabateado en el suelo.', 0),
(@ID, 'esMX', 'Hace mucho tiempo que el vidente Lengua de ceniza murió. Al darle la vuelta al cuerpo, descubres algo garabateado en el suelo.', 0);
-- 10706 Un misterioso portento
-- https://es.wowhead.com/quest=10706
SET @ID := 10706;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... ¡claro! Ahora lo veo todo claro.', 0),
(@ID, 'esMX', 'Sí... ¡claro! Ahora lo veo todo claro.', 0);
-- 10707 El bancal de Ata'mal
-- https://es.wowhead.com/quest=10707
SET @ID := 10707;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado, $n.', 0),
(@ID, 'esMX', 'Has regresado, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El cristal! Su poder... ¡ahora en mis manos!', 0),
(@ID, 'esMX', '¡El cristal! Su poder... ¡ahora en mis manos!', 0);
-- 10708 La promesa de Akama
-- https://es.wowhead.com/quest=10708
SET @ID := 10708;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Cuando le das el medallón a A\'dal, desaparece en su ser en un destello de luz.>$B$B<Se te muestra brevemente un vistazo de un momento... quizás en el futuro. Ves a Akama y Maiev saliendo de la jaula del guardián, abriéndose camino hacia el Templo Oscuro. Una tercera figura envuelta en sombras los está ayudando. Tras una inspección más cercana, notas que la figura eres tú.>', 0),
(@ID, 'esMX', '<Cuando le das el medallón a A\'dal, desaparece en su ser en un destello de luz.>$B$B<Se te muestra brevemente un vistazo de un momento... quizás en el futuro. Ves a Akama y Maiev saliendo de la jaula del guardián, abriéndose camino hacia el Templo Oscuro. Una tercera figura envuelta en sombras los está ayudando. Tras una inspección más cercana, notas que la figura eres tú.>', 0);
-- 10710 Vuelo de prueba: La Cresta Canto
-- Notice: English text: In quest_request_items.CompletionText change 'Mitharan' to '$n'
-- https://es.wowhead.com/quest=10710
SET @ID := 10710;
UPDATE `quest_request_items` SET `CompletionText` = 'Don\'t worry, $n! Worry never got anyone anywhere!', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te preocupes, $n! ¡La preocupación nunca llevó a nadie a ninguna parte!', 0),
(@ID, 'esMX', '¡No te preocupes, $n! ¡La preocupación nunca llevó a nadie a ninguna parte!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau! ¡Has vuelto a sobrevivir! ¡Soy mucho mejor ingeniero de lo que pensaba!$B$BAquí tienes tu dinero. Y vuelve a verme más tarde... tendré más experimentos que necesiten conejillos de indias.', 0),
(@ID, 'esMX', '¡Guau! ¡Has vuelto a sobrevivir! ¡Soy mucho mejor ingeniero de lo que pensaba!$B$BAquí tienes tu dinero. Y vuelve a verme más tarde... tendré más experimentos que necesiten conejillos de indias.', 0);
-- 10711 Vuelo de prueba: Zona de Aterrizaje Razaan
-- Notice: English text: In quest_request_items.CompletionText change 'Domme' to $n quest_request_items.CompletionText
-- https://es.wowhead.com/quest=10711
SET @ID := 10711;
UPDATE `quest_request_items` SET `CompletionText` = 'What? You don\'t want to perform the experiment? Don\'t fret, $n! I\'m behind you all the way!', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿No quieres realizar el experimento? ¡No te preocupes, $n! ¡Estoy detrás de ti todo el camino!', 0),
(@ID, 'esMX', '¿Qué? ¿No quieres realizar el experimento? ¡No te preocupes, $n! ¡Estoy detrás de ti todo el camino!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, vaya! ¡Has vuelto tan rápido! ¡Te vi salir volando! ¡Pensé que te romperías las piernas con el vuelo y estarías convaleciente al menos un mes! ¡Eres valiente e imprudente! ¡Pero sobre todo valiente!', 0),
(@ID, 'esMX', '¡Oh, vaya! ¡Has vuelto tan rápido! ¡Te vi salir volando! ¡Pensé que te romperías las piernas con el vuelo y estarías convaleciente al menos un mes! ¡Eres valiente e imprudente! ¡Pero sobre todo valiente!', 0);
-- 10712 Vuelo de prueba: La Foresta Ruuan
-- https://es.wowhead.com/quest=10712
SET @ID := 10712;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, hola! Mi clo... quiero decir, mi primo Tally me dijo que vendrías por aquí. ¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¡Hola, hola! Mi clo... quiero decir, mi primo Tally me dijo que vendrías por aquí. ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ¿has tomado lecturas con la veleta giratoria abisal? ¡Espléndido! ¡Los datos de este instrumento y mis medidas de magia druídica darán muchos frutos!$B$BOh, ¡te aseguro que las aplicaciones serán alucinantes!', 0),
(@ID, 'esMX', 'Oh, ¿has tomado lecturas con la veleta giratoria abisal? ¡Espléndido! ¡Los datos de este instrumento y mis medidas de magia druídica darán muchos frutos!$B$BOh, ¡te aseguro que las aplicaciones serán alucinantes!', 0);
-- 10713 ...y tiempos de acción
-- https://es.wowhead.com/quest=10713
SET @ID := 10713;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has protegido los árboles? ¿Has cortado los taladores?', 0),
(@ID, 'esMX', '¿Has protegido los árboles? ¿Has cortado los taladores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BAunque nos aseguraremos de que la población de animales se repone rápidamente, el crecimiento de los árboles, sobre todo de forma natural, es un proceso mucho más lento.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BAunque nos aseguraremos de que la población de animales se repone rápidamente, el crecimiento de los árboles, sobre todo de forma natural, es un proceso mucho más lento.', 0);
-- 10714 Las alas de Espíritu
-- https://es.wowhead.com/quest=10714
SET @ID := 10714;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Escuchar los planes de los ogros Machacasangre', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has aprendido, $n?', 0),
(@ID, 'esMX', '¿Qué has aprendido, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Espíritu se posa sobre el hombro de Rexxar mientras Rexxar escucha atentamente.>$B$BAsí que son los hijos de Gruul los que están detrás de las acciones de los ogros. Ellos ordenan a los Machacasangre que destruyan a los Mok\'Nathal para obtener su favor.', 0),
(@ID, 'esMX', '<Espíritu se posa sobre el hombro de Rexxar mientras Rexxar escucha atentamente.>$B$BAsí que son los hijos de Gruul los que están detrás de las acciones de los ogros. Ellos ordenan a los Machacasangre que destruyan a los Mok\'Nathal para obtener su favor.', 0);
-- En el interior de la Garganta Bulliciosa
-- 10715, 10799
-- https://es.wowhead.com/quest=10715
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10715, 10799) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10715, 'esES', '¿Tienes todas las glándulas venenosas? Si no es así, vete y no malgastes mi tiempo hasta que las tengas.', 0),
(10799, 'esES', '¿Tienes todas las glándulas venenosas? Si no es así, vete y no malgastes mi tiempo hasta que las tengas.', 0),
(10715, 'esMX', '¿Tienes todas las glándulas venenosas? Si no es así, vete y no malgastes mi tiempo hasta que las tengas.', 0),
(10799, 'esMX', '¿Tienes todas las glándulas venenosas? Si no es así, vete y no malgastes mi tiempo hasta que las tengas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10715, 10799) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10715, 'esES', 'Muy bien, una tarea simple y sencilla completada. Ahora, dame las glándulas y me pondré con la parte difícil.', 0),
(10799, 'esES', 'Muy bien, una tarea simple y sencilla completada. Ahora, dame las glándulas y me pondré con la parte difícil.', 0),
(10715, 'esMX', 'Muy bien, una tarea simple y sencilla completada. Ahora, dame las glándulas y me pondré con la parte difícil.', 0),
(10799, 'esMX', 'Muy bien, una tarea simple y sencilla completada. Ahora, dame las glándulas y me pondré con la parte difícil.', 0);
-- 10717 Robar a un ladrón
-- https://es.wowhead.com/quest=10717
SET @ID := 10717;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la obtención de redes? Por lo que he visto, esas redes que los furtivos usan deberían ser lo suficientemente resistentes para capturar una cría.', 0),
(@ID, 'esMX', '¿Cómo va la obtención de redes? Por lo que he visto, esas redes que los furtivos usan deberían ser lo suficientemente resistentes para capturar una cría.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, tienen un aspecto estupendo. Estos cultores sin duda tienen buen ojo para la artesanía.$B$BLástima que se desperdicie.$B$BY ahora que tenemos las redes, ¿te importaría ayudar a una pobre ancianita en un par de cositas?', 0),
(@ID, 'esMX', 'Oh, tienen un aspecto estupendo. Estos cultores sin duda tienen buen ojo para la artesanía.$B$BLástima que se desperdicie.$B$BY ahora que tenemos las redes, ¿te importaría ayudar a una pobre ancianita en un par de cositas?', 0);
-- 10718 Los espíritus tienen voces
-- https://es.wowhead.com/quest=10718
SET @ID := 10718;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De qué estás hablando?$B$B¿Garm Hermano Lobo? Fue el último jefe del clan Señor del Trueno. Si te has comunicado con su espíritu, entonces debe de ser verdad.', 0),
(@ID, 'esMX', '¿De qué estás hablando?$B$B¿Garm Hermano Lobo? Fue el último jefe del clan Señor del Trueno. Si te has comunicado con su espíritu, entonces debe de ser verdad.', 0);
-- 10719 ¿Has conseguido la nota?
-- https://es.wowhead.com/quest=10719
SET @ID := 10719;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí? ¿Esa mancha en la nota es de sangre?', 0),
(@ID, 'esMX', '¿Qué tienes ahí? ¿Esa mancha en la nota es de sangre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interesante. Me sugiere una idea pero deberíamos preguntar primero a Samia quién es este Kolphis Rangoscuro.', 0),
(@ID, 'esMX', 'Interesante. Me sugiere una idea pero deberíamos preguntar primero a Samia quién es este Kolphis Rangoscuro.', 0);
-- 10720 Las criaturas más pequeñas
-- https://es.wowhead.com/quest=10720
SET @ID := 10720;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Envenenar el barril de grog de punto verde', `ObjectiveText2` = 'Envenenar el barril de licor de luna añejo', `ObjectiveText3` = 'Envenenar el barril de cerveza de semillas fermentadas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho?', 0),
(@ID, 'esMX', '¿Lo has hecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Durante muchos años me he concentrado en perfeccionar el modo de comunicarme con la naturaleza. Esto es solo una ínfima parte del potencial que las bestias pueden otorgarte.', 0),
(@ID, 'esMX', 'Durante muchos años me he concentrado en perfeccionar el modo de comunicarme con la naturaleza. Esto es solo una ínfima parte del potencial que las bestias pueden otorgarte.', 0);
-- 10721 Un jabalí para Grulloc
-- https://es.wowhead.com/quest=10721
SET @ID := 10721;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has vuelto? ¿Has venido a traerme lo que Rexxar me debe?', 0),
(@ID, 'esMX', '¿Ya has vuelto? ¿Has venido a traerme lo que Rexxar me debe?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El barón Sablecrín mira en el saco del gronn y parece satisfecho.>$B$BMuy bien, has cumplido tu parte del trato. Con el precio pagado, le daré a Rexxar lo que quiere.', 0),
(@ID, 'esMX', '<El barón Sablecrín mira en el saco del gronn y parece satisfecho.>$B$BMuy bien, has cumplido tu parte del trato. Con el precio pagado, le daré a Rexxar lo que quiere.', 0);
-- 10722 Encuentro en el Aquelarre Alanegra
-- https://es.wowhead.com/quest=10722
SET @ID := 10722;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué novedades traes? ¿Sabes lo que están haciendo los del Culto Vermis?', 0),
(@ID, 'esMX', '¿Qué novedades traes? ¿Sabes lo que están haciendo los del Culto Vermis?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Atacarnos? ¿Eliminarnos? Va a ser que no.$B$B¡Estos del Aquelarre Alanegra tienen mucho que aprender si piensan que es tan fácil despachar a la Expedición Cenarion!$B$B¿Cuál era la expresión? ¡Ojo por ojo, diente por diente!', 0),
(@ID, 'esMX', '¿Atacarnos? ¿Eliminarnos? Va a ser que no.$B$B¡Estos del Aquelarre Alanegra tienen mucho que aprender si piensan que es tan fácil despachar a la Expedición Cenarion!$B$B¿Cuál era la expresión? ¡Ojo por ojo, diente por diente!', 0);
-- 10723 Gorgrom el Comedragones
-- https://es.wowhead.com/quest=10723
SET @ID := 10723;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Coloca Tótems repelentes', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los ogros Machacasangre ya no nos molestarán nunca más.', 0),
(@ID, 'esMX', 'Los ogros Machacasangre ya no nos molestarán nunca más.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los ogros Machacasangre y su maestro, Gorgrom, ya no molestarán nunca más a los Mok\'Nathal.$B$BSin embargo, me preocupa el efecto de nuestras acciones en el otro gronn. Creo que debemos poner fin a esta lucha de una vez por todas.', 0),
(@ID, 'esMX', 'Los ogros Machacasangre y su maestro, Gorgrom, ya no molestarán nunca más a los Mok\'Nathal.$B$BSin embargo, me preocupa el efecto de nuestras acciones en el otro gronn. Creo que debemos poner fin a esta lucha de una vez por todas.', 0);
-- 10724 Prisionero de los Aguja del Filo
-- https://es.wowhead.com/quest=10724
SET @ID := 10724;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Rescatar a Leokk', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Será bueno volver a contar con la ayuda de Leokk.', 0),
(@ID, 'esMX', 'Será bueno volver a contar con la ayuda de Leokk.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Leokk nos ha traído la cabeza de uno de los dragones Negros de Fin del Dragón. Con esto, pondremos furioso a Goc, el gronn que le capturó y conseguiremos que se enfrente a nosotros.', 0),
(@ID, 'esMX', 'Leokk nos ha traído la cabeza de uno de los dragones Negros de Fin del Dragón. Con esto, pondremos furioso a Goc, el gronn que le capturó y conseguiremos que se enfrente a nosotros.', 0);
-- Eminencia ante El Ojo Violeta
-- 10725, 10726, 10727, 10728
-- https://es.wowhead.com/quest=10725
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10725, 10726, 10727, 10728) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10725, 'esES', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0),
(10726, 'esES', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0),
(10727, 'esES', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0),
(10728, 'esES', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0),
(10725, 'esMX', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0),
(10726, 'esMX', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0),
(10727, 'esMX', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0),
(10728, 'esMX', 'El sello que ahora tienes es tan poderoso como el de cualquier Archimago del Consejo. Úsalo donde quiera que vayas para que los iniciados puedan reconocer tu lealtad. ¡Úsalo donde quiera que vayas para que su poder pueda servirte como tu nos has servido a nosotros!', 0);
-- El camino del mago Violeta
-- 10729, 10730, 10731, 10732
-- https://es.tbc.wowhead.com/quest=10729
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10729, 10730, 10731, 10732) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10729, 'esES', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0),
(10730, 'esES', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0),
(10731, 'esES', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0),
(10732, 'esES', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0),
(10729, 'esMX', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0),
(10730, 'esMX', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0),
(10731, 'esMX', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0),
(10732, 'esMX', '¿Tienes clara tu elección, $n? No debes decidirlo a la ligera.$B$BEl sello Violeta aumentará su poder según demuestres tu valía a El Ojo Violeta.', 0);
-- Por el camino Violeta
-- 10733, 10734, 10735, 10736
-- https://es.wowhead.com/quest=10733
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10733, 10734, 10735, 10736) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10733, 'esES', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0),
(10734, 'esES', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0),
(10735, 'esES', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0),
(10736, 'esES', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0),
(10733, 'esMX', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0),
(10734, 'esMX', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0),
(10735, 'esMX', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0),
(10736, 'esMX', 'Nos honras con tus servicios, $n. ¡Observa como libero el poder de tu sello!', 0);
-- Servicio distinguido
-- 10738, 10739, 10740, 10741
-- https://es.wowhead.com/quest=10738
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10738, 10739, 10740, 10741) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10738, 'esES', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0),
(10739, 'esES', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0),
(10740, 'esES', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0),
(10741, 'esES', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0),
(10738, 'esMX', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0),
(10739, 'esMX', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0),
(10740, 'esMX', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0),
(10741, 'esMX', 'Tus servicios no han pasado desapercibidos, $n. Tu sello puede parecer igual, pero sus poderes aumentan a medida que continúas demostrando tu lealtad.', 0);
