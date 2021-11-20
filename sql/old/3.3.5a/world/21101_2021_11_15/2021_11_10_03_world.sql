-- 10642 Un fantasma en la máquina
-- https://es.wowhead.com/quest=10642
SET @ID := 10642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, existe una dualidad... la siento.', 0),
(@ID, 'esMX', 'Sí, existe una dualidad... la siento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Zorus comienza a trabajar con las muestras de la ceniza.>$B$BYa está. ¡Espectróculos!', 0),
(@ID, 'esMX', '<Zorus comienza a trabajar con las muestras de la ceniza.>$B$BYa está. ¡Espectróculos!', 0);
-- 10643 Presagistas de Sombraluna
-- https://es.wowhead.com/quest=10643
SET @ID := 10643;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si pierdes tus gafas, dímelo y te haré otro par.', 0),
(@ID, 'esMX', 'Si pierdes tus gafas, dímelo y te haré otro par.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que los espíritus te han susurrado? ¿Y que mencionaron a Teron Sanguino?$B$B<Zorus tiembla.>$B$BSí... Conozco a Teron Sanguino. Pensaba que llevaba mucho tiempo muerto. ¿De qué estarían hablando los espíritus?', 0),
(@ID, 'esMX', '¿Dices que los espíritus te han susurrado? ¿Y que mencionaron a Teron Sanguino?$B$B<Zorus tiembla.>$B$BSí... Conozco a Teron Sanguino. Pensaba que llevaba mucho tiempo muerto. ¿De qué estarían hablando los espíritus?', 0);
-- 10645 Yo, Teron Sanguino
-- https://es.wowhead.com/quest=10645
SET @ID := 10645;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué dices?', 0),
(@ID, 'esMX', '¿Qué dices?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que has hecho qué? ¡IMBÉCIL!$B$BTienes que solucionarlo. Después de todo, es por tu culpa. Coge uno de estos cascos. Cada uno de ellos tiene parte de las cenizas siempreardientes que sacaste de mí. Te permitirán ver a los fantasmas de Sombraluna, incluido a Teron Sanguino.$B$BSi alguna vez encuentras a Teron Sanguino, mátale.', 0),
(@ID, 'esMX', '¿Que has hecho qué? ¡IMBÉCIL!$B$BTienes que solucionarlo. Después de todo, es por tu culpa. Coge uno de estos cascos. Cada uno de ellos tiene parte de las cenizas siempreardientes que sacaste de mí. Te permitirán ver a los fantasmas de Sombraluna, incluido a Teron Sanguino.$B$BSi alguna vez encuentras a Teron Sanguino, mátale.', 0);
-- 10646 El pupilo de Illidan
-- https://es.wowhead.com/quest=10646
SET @ID := 10646;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora conoces la historia. Solo nos queda una cosa pendiente.', 0),
(@ID, 'esMX', 'Ahora conoces la historia. Solo nos queda una cosa pendiente.', 0);
-- 10647 Se busca: Uvuros, plaga de Sombraluna
-- https://es.wowhead.com/quest=10647
SET @ID := 10647;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido pa’ recoger la recompensa, colega?', 0),
(@ID, 'esMX', '¿Has venido pa’ recoger la recompensa, colega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'T’has llevado un peaso pesca, colega. ¡Da guten! Tendrás tu recompensa. ¡Tranqui, que pa’hí anda!', 0),
(@ID, 'esMX', 'T’has llevado un peaso pesca, colega. ¡Da guten! Tendrás tu recompensa. ¡Tranqui, que pa’hí anda!', 0);
-- 10648 Se busca: Uvuros, plaga de Sombraluna
-- https://es.wowhead.com/quest=10648
SET @ID := 10648;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas conseguido algo especial, $gchico:chica;. Si no, ¡¡ya te estás largando!!', 0),
(@ID, 'esMX', 'Espero que hayas conseguido algo especial, $gchico:chica;. Si no, ¡¡ya te estás largando!!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso es, aquí tienes tu recompensa. No te lo gastes todo de golpe.', 0),
(@ID, 'esMX', 'Eso es, aquí tienes tu recompensa. No te lo gastes todo de golpe.', 0);
-- 10649 El Libro de Nombres Viles
-- https://es.wowhead.com/quest=10649
SET @ID := 10649;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste el libro, $n?', 0),
(@ID, 'esMX', '¿Conseguiste el libro, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sentía el poder del libro a kilómetros de distancia. La tentación de quedármelo es... muy fuerte.', 0),
(@ID, 'esMX', 'Sentía el poder del libro a kilómetros de distancia. La tentación de quedármelo es... muy fuerte.', 0);
-- 10650 Regresa junto a los Aldor
-- https://es.wowhead.com/quest=10650
SET @ID := 10650;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Cómo puedes traer esa aberración de libro a este lugar sagrado?! Más te vale tener una buena explicación, $n.', 0),
(@ID, 'esMX', '¡¿Cómo puedes traer esa aberración de libro a este lugar sagrado?! Más te vale tener una buena explicación, $n.', 0);
-- 10651 Hay que detener a Varedis
-- https://es.wowhead.com/quest=10651
SET @ID := 10651;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado lo que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has completado lo que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un trabajo estupendo, $n! Tu victoria sobre Varedis tendrá un impacto tremendo en nuestra guerra contra Illidan.$B$BHas demostrado tu valía no solo ante los Aldor sino también ante toda Terrallende.', 0),
(@ID, 'esMX', '¡Un trabajo estupendo, $n! Tu victoria sobre Varedis tendrá un impacto tremendo en nuestra guerra contra Illidan.$B$BHas demostrado tu valía no solo ante los Aldor sino también ante toda Terrallende.', 0);
-- 10652 Tras las líneas enemigas
-- https://es.wowhead.com/quest=10652
SET @ID := 10652;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida, $c. Intenta que no descubran nuestra posición.$B$BNo duraríamos mucho si los colegas de Kael nos descubriesen.', 0),
(@ID, 'esMX', 'Te doy la bienvenida, $c. Intenta que no descubran nuestra posición.$B$BNo duraríamos mucho si los colegas de Kael nos descubriesen.', 0);
-- 10653 Marcas de Sargeras
-- https://es.wowhead.com/quest=10653
SET @ID := 10653;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes alguna insignia de nuestros enemigos, $n?', 0),
(@ID, 'esMX', '¿Tienes alguna insignia de nuestros enemigos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enfrentarse a los demonios de la Legión Ardiente y a los cultores locos es toda una proeza, $n. Has demostrado gran dedicación y coraje. Sigue así y tu reputación entre los Aldor seguirá aumentando.', 0),
(@ID, 'esMX', 'Enfrentarse a los demonios de la Legión Ardiente y a los cultores locos es toda una proeza, $n. Has demostrado gran dedicación y coraje. Sigue así y tu reputación entre los Aldor seguirá aumentando.', 0);
-- Más marcas de Sargeras
-- 10654, 10827
-- https://es.wowhead.com/quest=10654
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10654, 10827) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10654, 'esES', '¿Tienes más insignias de nuestros enemigos, $c? La Legión Ardiente sigue siendo una amenaza y nosotros seguimos persiguiéndoles siempre que podemos.', 0),
(10827, 'esES', '¿Tienes más insignias de nuestros enemigos, $c? La Legión Ardiente sigue siendo una amenaza y nosotros seguimos persiguiéndoles siempre que podemos.', 0),
(10654, 'esMX', '¿Tienes más insignias de nuestros enemigos, $c? La Legión Ardiente sigue siendo una amenaza y nosotros seguimos persiguiéndoles siempre que podemos.', 0),
(10827, 'esMX', '¿Tienes más insignias de nuestros enemigos, $c? La Legión Ardiente sigue siendo una amenaza y nosotros seguimos persiguiéndoles siempre que podemos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10654, 10827) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10654, 'esES', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0),
(10827, 'esES', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0),
(10654, 'esMX', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0),
(10827, 'esMX', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0);
-- Marca de Sargeras única
-- 10655, 10828
-- https://es.wowhead.com/quest=10655
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10655, 10828) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10655, 'esES', 'Me quedaré con las insignias que te sobran. No te preocupes, tus acciones serán tenidas en cuenta.', 0),
(10828, 'esES', 'Me quedaré con las insignias que te sobran. No te preocupes, tus acciones serán tenidas en cuenta.', 0),
(10655, 'esMX', 'Me quedaré con las insignias que te sobran. No te preocupes, tus acciones serán tenidas en cuenta.', 0),
(10828, 'esMX', 'Me quedaré con las insignias que te sobran. No te preocupes, tus acciones serán tenidas en cuenta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10655, 10828) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10655, 'esES', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0),
(10828, 'esES', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0),
(10655, 'esMX', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0),
(10828, 'esMX', 'Sigue demostrándonos tu valía, $n. Lucha contra los enemigos de la Luz cada vez que los encuentres; tus acciones se verán recompensadas.', 0);
-- 10656 Sellos Furia del Sol
-- https://es.wowhead.com/quest=10656
SET @ID := 10656;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Adelante, $n. Habla.', 0),
(@ID, 'esMX', 'Adelante, $n. Habla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El ejército Furia del Sol de Kael está muy bien entrenado. Es realmente impresionante, $n.', 0),
(@ID, 'esMX', 'El ejército Furia del Sol de Kael está muy bien entrenado. Es realmente impresionante, $n.', 0);
-- 10657 A lomos del relámpago
-- https://es.wowhead.com/quest=10657
SET @ID := 10657;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Golpes de relámpagos absorbidos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La clave en el uso de la esfera de magneto repolarizado es saber cuándo apagarla antes de que te fría hasta las cejas.$B$BPor supuesto, debes calcularlo en función del número de esas serpientes voladoras a las que desees enfrentarte.$B$BY a propósito, ¿has logrado recargar la esfera?', 0),
(@ID, 'esMX', 'La clave en el uso de la esfera de magneto repolarizado es saber cuándo apagarla antes de que te fría hasta las cejas.$B$BPor supuesto, debes calcularlo en función del número de esas serpientes voladoras a las que desees enfrentarte.$B$BY a propósito, ¿has logrado recargar la esfera?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Viva! ¡Ha funcionado! A decir verdad, no estaba seguro... Estimaba en un 23.72% de probabilidades de que implosionaras al tercer intento.$B$B<Toshley esboza una sonrisa inocente.>$B$BBien, ahora que sabemos que la esfera funciona, no deberíamos tener ningún problema en conseguir la energía necesaria para el Cefirium Capacitorium. Bueno, eso si conseguimos más voluntarios que salgan por ahí y se dejen pillar.$B$BPero bueno, te lo has trabajado ¡y mereces algo a cambio!', 0),
(@ID, 'esMX', '¡Viva! ¡Ha funcionado! A decir verdad, no estaba seguro... Estimaba en un 23.72% de probabilidades de que implosionaras al tercer intento.$B$B<Toshley esboza una sonrisa inocente.>$B$BBien, ahora que sabemos que la esfera funciona, no deberíamos tener ningún problema en conseguir la energía necesaria para el Cefirium Capacitorium. Bueno, eso si conseguimos más voluntarios que salgan por ahí y se dejen pillar.$B$BPero bueno, te lo has trabajado ¡y mereces algo a cambio!', 0);
-- Más sellos Furia del Sol
-- 10658, 10823
-- https://es.wowhead.com/quest=10658
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10658, 10823) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10658, 'esES', '¿Qué has hecho por nosotros últimamente, $n? Diría que la guerra contra Kael\'thas no va a librarse sola, ¿no te parece?', 0),
(10823, 'esES', '¿Qué has hecho por nosotros últimamente, $n? Diría que la guerra contra Kael\'thas no va a librarse sola, ¿no te parece?', 0),
(10658, 'esMX', '¿Qué has hecho por nosotros últimamente, $n? Diría que la guerra contra Kael\'thas no va a librarse sola, ¿no te parece?', 0),
(10823, 'esMX', '¿Qué has hecho por nosotros últimamente, $n? Diría que la guerra contra Kael\'thas no va a librarse sola, ¿no te parece?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10658, 10823) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10658, 'esES', '¡Excelente! Eso le demostrará a Kael\'thas que no debe subestimar nuestro poder.', 0),
(10823, 'esES', '¡Excelente! Eso le demostrará a Kael\'thas que no debe subestimar nuestro poder.', 0),
(10658, 'esMX', '¡Excelente! Eso le demostrará a Kael\'thas que no debe subestimar nuestro poder.', 0),
(10823, 'esMX', '¡Excelente! Eso le demostrará a Kael\'thas que no debe subestimar nuestro poder.', 0);
-- Sello Furia del Sol único
-- 10659, 10822
-- https://es.tbc.wowhead.com/quest=10659
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10659, 10822) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10659, 'esES', 'Todas las contribuciones a la causa se notan, $n, por pequeñas que sean. Nuestros enemigos son muchos, ¡pero lo conseguiremos!', 0),
(10822, 'esES', 'Todas las contribuciones a la causa se notan, $n, por pequeñas que sean. Nuestros enemigos son muchos, ¡pero lo conseguiremos!', 0),
(10659, 'esMX', 'Todas las contribuciones a la causa se notan, $n, por pequeñas que sean. Nuestros enemigos son muchos, ¡pero lo conseguiremos!', 0),
(10822, 'esMX', 'Todas las contribuciones a la causa se notan, $n, por pequeñas que sean. Nuestros enemigos son muchos, ¡pero lo conseguiremos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10659, 10822) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10659, 'esES', 'El ejército de Kael caerá pronto.', 0),
(10822, 'esES', 'El ejército de Kael caerá pronto.', 0),
(10659, 'esMX', 'El ejército de Kael caerá pronto.', 0),
(10822, 'esMX', 'El ejército de Kael caerá pronto.', 0);
-- 10660 Extrañas criaturas
-- https://es.tbc.wowhead.com/quest=10660
SET @ID := 10660;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bazos! ¡Necesito bazos!', 0),
(@ID, 'esMX', '¡Bazos! ¡Necesito bazos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El investigador Tiorus toma los bazos y empieza a examinarlos.>$B$BEsto podría llevar algún tiempo. Aquí tienes unas monedas por tu esforzado trabajo.', 0),
(@ID, 'esMX', '<El investigador Tiorus toma los bazos y empieza a examinarlos.>$B$BEsto podría llevar algún tiempo. Aquí tienes unas monedas por tu esforzado trabajo.', 0);
-- 10661 Para darte un 'abazo'
-- https://es.tbc.wowhead.com/quest=10661
SET @ID := 10661;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bazos! ¡Necesito bazos!', 0),
(@ID, 'esMX', '¡Bazos! ¡Necesito bazos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gnomus toma los bazos con ansiedad.>$B$BAquí tienes tu moneda como te prometí. Te llamaré si necesito más bazos.$B$BQué maravilla... ¡casi te daría un \'abazo\'!', 0),
(@ID, 'esMX', '<Gnomus toma los bazos con ansiedad.>$B$BAquí tienes tu moneda como te prometí. Te llamaré si necesito más bazos.$B$BQué maravilla... ¡casi te daría un \'abazo\'!', 0);
-- 10662 El herrero ermitaño
-- https://es.wowhead.com/quest=10662
SET @ID := 10662;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae por aquí, $c? No tengo muchas visitas.', 0),
(@ID, 'esMX', '¿Qué te trae por aquí, $c? No tengo muchas visitas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ordinn te ha enviado con esto?$B$B<El herrero examina los lingotes.>$B$BTenía razón. Se ha desvanecido casi toda la magia pero aún percibo rastros. Con un poco de trabajo y algunos recursos \'exóticos\', puedo forjar una poderosa espada antidemonios con este metal.', 0),
(@ID, 'esMX', '¿Ordinn te ha enviado con esto?$B$B<El herrero examina los lingotes.>$B$BTenía razón. Se ha desvanecido casi toda la magia pero aún percibo rastros. Con un poco de trabajo y algunos recursos \'exóticos\', puedo forjar una poderosa espada antidemonios con este metal.', 0);
-- 10663 El herrero ermitaño
-- https://es.wowhead.com/quest=10663
SET @ID := 10663;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae por aquí, $c? No tengo muchas visitas.', 0),
(@ID, 'esMX', '¿Qué te trae por aquí, $c? No tengo muchas visitas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El herrero frunce el ceño y examina los lingotes.>$B$BSeré franco contigo, $c. Soy una reliquia de una época cuando la cooperación con la Horda era algo impensable.$B$BNo estoy tan ciego como para no ver que no tenemos enemigos comunes. Te ayudaré a reforjar el arma antidemonios, pero va a significar mucho trabajo y algunos objetos \'exóticos\'.', 0),
(@ID, 'esMX', '<El herrero frunce el ceño y examina los lingotes.>$B$BSeré franco contigo, $c. Soy una reliquia de una época cuando la cooperación con la Horda era algo impensable.$B$BNo estoy tan ciego como para no ver que no tenemos enemigos comunes. Te ayudaré a reforjar el arma antidemonios, pero va a significar mucho trabajo y algunos objetos \'exóticos\'.', 0);
-- 10664 Más materiales
-- https://es.wowhead.com/quest=10664
SET @ID := 10664;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido esos materiales?', 0),
(@ID, 'esMX', '¿Has conseguido esos materiales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El herrero acepta los materiales, asintiendo con tono de aprobación.>$B$BCon esto será suficiente. Aunque el resto de materiales que voy a necesitar no será tan fácil de conseguir.', 0),
(@ID, 'esMX', '<El herrero acepta los materiales, asintiendo con tono de aprobación.>$B$BCon esto será suficiente. Aunque el resto de materiales que voy a necesitar no será tan fácil de conseguir.', 0);
-- 10665 Recién hechas en El Mechanar
-- https://es.wowhead.com/quest=10665
SET @ID := 10665;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido robar una célula de maná en El Mechanar?', 0),
(@ID, 'esMX', '¿Has conseguido robar una célula de maná en El Mechanar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es aún más potente de lo que esperaba! Con tanto poder, ¡podría forjar una docena de espadas!', 0),
(@ID, 'esMX', '¡Esto es aún más potente de lo que esperaba! Con tanto poder, ¡podría forjar una docena de espadas!', 0);
