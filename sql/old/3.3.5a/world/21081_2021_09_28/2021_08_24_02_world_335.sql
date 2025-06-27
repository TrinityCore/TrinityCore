-- 10456 Lobos merodeadores
-- https://es.wowhead.com/quest=10456
SET @ID := 10456;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo explicarte lo suficiente la necesidad de que nos encarguemos de esos lobos temibles Señor del Trueno. Su mismísima existencia pone en peligro la estabilidad de La Arboleda Viviente y todo nuestro trabajo aquí.', 0),
(@ID, 'esMX', 'No puedo explicarte lo suficiente la necesidad de que nos encarguemos de esos lobos temibles Señor del Trueno. Su mismísima existencia pone en peligro la estabilidad de La Arboleda Viviente y todo nuestro trabajo aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien. Veré si puedo hacer algo útil con estas colas.$B$BSeguro que la Horda encontrará la forma de volver a conseguir más lobos pero, por ahora, podemos respirar con más tranquilidad.$B$B$n, si quieres ayudar, hay algo más que podrías hacer por la defensa de Sylvanaar y La Arboleda Viviente.', 0),
(@ID, 'esMX', 'Bien. Veré si puedo hacer algo útil con estas colas.$B$BSeguro que la Horda encontrará la forma de volver a conseguir más lobos pero, por ahora, podemos respirar con más tranquilidad.$B$B$n, si quieres ayudar, hay algo más que podrías hacer por la defensa de Sylvanaar y La Arboleda Viviente.', 0);
-- 10457 Proteger a los nuestros
-- https://es.wowhead.com/quest=10457
SET @ID := 10457;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Defensores de La Arboleda Viviente invocados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo van las defensas de La Arboleda Viviente?$B$BYa que desconocemos las intenciones de los arakkoa en Velo Lashh y la Horda se encuentra al otro lado del barranco, me temo que si no nos movemos rápidamente nos encontraremos en una situación muy penosa para poder defender nuestro nuevo hogar y nuestro trabajo en la arboleda.', 0),
(@ID, 'esMX', '¿Cómo van las defensas de La Arboleda Viviente?$B$BYa que desconocemos las intenciones de los arakkoa en Velo Lashh y la Horda se encuentra al otro lado del barranco, me temo que si no nos movemos rápidamente nos encontraremos en una situación muy penosa para poder defender nuestro nuevo hogar y nuestro trabajo en la arboleda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que has fortalecido las defensas de la arboleda, me siento mucho mejor.$B$BTe has ganado nuestro agradecimiento y nuestro aprecio, $n.$B$B¡Espera, me acabo de acordar de que tenemos algo pendiente!', 0),
(@ID, 'esMX', 'Ahora que has fortalecido las defensas de la arboleda, me siento mucho mejor.$B$BTe has ganado nuestro agradecimiento y nuestro aprecio, $n.$B$B¡Espera, me acabo de acordar de que tenemos algo pendiente!', 0);
-- 10458 Espíritus de fuego y tierra iracundos
-- https://es.wowhead.com/quest=10458
SET @ID := 10458;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Alma de terráneo capturada', `ObjectiveText2` = 'Alma de ígneo capturada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me temo que a esta tierra ya no le quedan esperanzas.', 0),
(@ID, 'esMX', 'Me temo que a esta tierra ya no le quedan esperanzas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando todas las almas elementales de esta región estén dentro del tótem, nos comunicaremos con ellas y descubriremos qué se puede hacer por el Valle Sombraluna.', 0),
(@ID, 'esMX', 'Cuando todas las almas elementales de esta región estén dentro del tótem, nos comunicaremos con ellas y descubriremos qué se puede hacer por el Valle Sombraluna.', 0);
-- 10460, 10461, 10462, 10463
-- https://es.wowhead.com/quest=10460
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10460, 10461, 10462, 10463) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10460, 'esES', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0),
(10461, 'esES', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0),
(10462, 'esES', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0),
(10463, 'esES', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0),
(10460, 'esMX', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0),
(10461, 'esMX', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0),
(10462, 'esMX', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0),
(10463, 'esMX', '¿Estás $gseguro:segura; de que este es el camino que buscas tomar, $N? Esta no es una decisión que debas tomar a la ligera.$B$BEste anillo está imbuido de una gota del Pozo de la Eternidad. Crecerá en poder a medida que demuestres tu valía en la Escama de las Arenas.', 0);
-- 10464, 10465, 10466, 10467
-- https://es.wowhead.com/quest=10464
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10464, 10465, 10466, 10467) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10464, 'esES', 'Continúas sirviéndonos bien, $N.', 0),
(10465, 'esES', 'Continúas sirviéndonos bien, $N.', 0),
(10466, 'esES', 'Continúas sirviéndonos bien, $N.', 0),
(10467, 'esES', 'Continúas sirviéndonos bien, $N.', 0),
(10464, 'esMX', 'Continúas sirviéndonos bien, $N.', 0),
(10465, 'esMX', 'Continúas sirviéndonos bien, $N.', 0),
(10466, 'esMX', 'Continúas sirviéndonos bien, $N.', 0),
(10467, 'esMX', 'Continúas sirviéndonos bien, $N.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10464, 10465, 10466, 10467) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10464, 'esES', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0),
(10465, 'esES', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0),
(10466, 'esES', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0),
(10467, 'esES', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0),
(10464, 'esMX', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0),
(10465, 'esMX', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0),
(10466, 'esMX', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0),
(10467, 'esMX', 'Has demostrado tu valía, $r. Hasta cierto punto, al menos.$B$BEl favor de la primera de Nozdormu no se obtiene fácilmente.', 0);
-- 10468, 10469, 10470, 10471
-- https://es.wowhead.com/quest=10468
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10468, 10469, 10470, 10471) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10468, 'esES', 'Has vuelto. ¿Quieres hablar conmigo?', 0),
(10469, 'esES', 'Has vuelto. ¿Quieres hablar conmigo?', 0),
(10470, 'esES', 'Has vuelto. ¿Quieres hablar conmigo?', 0),
(10471, 'esES', 'Has vuelto. ¿Quieres hablar conmigo?', 0),
(10468, 'esMX', 'Has vuelto. ¿Quieres hablar conmigo?', 0),
(10469, 'esMX', 'Has vuelto. ¿Quieres hablar conmigo?', 0),
(10470, 'esMX', 'Has vuelto. ¿Quieres hablar conmigo?', 0),
(10471, 'esMX', 'Has vuelto. ¿Quieres hablar conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10468, 10469, 10470, 10471) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10468, 'esES', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0),
(10469, 'esES', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0),
(10470, 'esES', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0),
(10471, 'esES', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0),
(10468, 'esMX', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0),
(10469, 'esMX', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0),
(10470, 'esMX', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0),
(10471, 'esMX', 'Realmente eres $gun aliado digno:una elegida digna;. ¡A medida que creces en poder, también lo hace la Sortija de eternidad!', 0);
-- 10472, 10473, 10474, 10475
-- https://es.wowhead.com/quest=10472
-- https://es.tbc.wowhead.com/quest=10472
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10472, 10473, 10474, 10475) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10472, 'esES', 'Que el tiempo esté siempre de tu lado, $N.', 0),
(10473, 'esES', 'Que el tiempo esté siempre de tu lado, $N.', 0),
(10474, 'esES', 'Que el tiempo esté siempre de tu lado, $N.', 0),
(10475, 'esES', 'Que el tiempo esté siempre de tu lado, $N.', 0),
(10472, 'esMX', 'Que el tiempo esté siempre de tu lado, $N.', 0),
(10473, 'esMX', 'Que el tiempo esté siempre de tu lado, $N.', 0),
(10474, 'esMX', 'Que el tiempo esté siempre de tu lado, $N.', 0),
(10475, 'esMX', 'Que el tiempo esté siempre de tu lado, $N.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10472, 10473, 10474, 10475) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10472, 'esES', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0),
(10473, 'esES', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0),
(10474, 'esES', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0),
(10475, 'esES', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0),
(10472, 'esMX', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0),
(10473, 'esMX', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0),
(10474, 'esMX', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0),
(10475, 'esMX', 'Eres $guno:una; con el tiempo, $N. Eres $guno:una; con nosotros.$B$B¡Mira! El poder más allá del entendimiento mortal se desata incluso desde ese pequeño remanente del Pozo de la Eternidad.$B$BAcepta este regalo para que todos conozcan tu pacto con la Escama de las Arenas... ¡para que todos conozcan tu pacto con el tiempo mismo!', 0);
-- 10476 Enemigos encarnizados
-- https://es.wowhead.com/quest=10476
SET @ID := 10476;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien, $n? ¿Solo vienes a charlar o tienes algo para mí?', 0),
(@ID, 'esMX', '¿Y bien, $n? ¿Solo vienes a charlar o tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has empezado a demostrar tu valía como $galiado:aliada; y como combatiente. Sigue así.', 0),
(@ID, 'esMX', 'Has empezado a demostrar tu valía como $galiado:aliada; y como combatiente. Sigue así.', 0);
-- 10477 Más abalorios de guerra
-- https://es.wowhead.com/quest=10477
SET @ID := 10477;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Llevas algún abalorio de guerra de obsidiana adicional, $n?', 0),
(@ID, 'esMX', '¿Llevas algún abalorio de guerra de obsidiana adicional, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigues demostrándonos tu valía, $n. Que tu fuerza nunca te falle.', 0),
(@ID, 'esMX', 'Sigues demostrándonos tu valía, $n. Que tu fuerza nunca te falle.', 0);
-- 10478 ¡Más abalorios de guerra!
-- https://es.wowhead.com/quest=10478
SET @ID := 10478;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido más abalorios de guerra, $n?', 0),
(@ID, 'esMX', '¿Has conseguido más abalorios de guerra, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigues demostrando tu fuerza y tu honor, $n.', 0),
(@ID, 'esMX', 'Sigues demostrando tu fuerza y tu honor, $n.', 0);
-- 10479 Demostrar tu fuerza
-- https://es.wowhead.com/quest=10479
SET @ID := 10479;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que mostrarme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que mostrarme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin duda eres $gun aliado:una aliada; fuerte, $n. Enfrentarse directamente a los ogros de Terrallende no es algo que pueda hacer cualquiera.', 0),
(@ID, 'esMX', 'Sin duda eres $gun aliado:una aliada; fuerte, $n. Enfrentarse directamente a los ogros de Terrallende no es algo que pueda hacer cualquiera.', 0);
-- 10480 Espíritus de agua iracundos
-- https://es.wowhead.com/quest=10480
SET @ID := 10480;
UPDATE `quest_template_locale` SET `ObjectiveText1` = '', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Doquiera encuentres nagas, casi seguro que encuentras espíritus de agua torturados.', 0),
(@ID, 'esMX', 'Doquiera encuentres nagas, casi seguro que encuentras espíritus de agua torturados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya solo falta el aire, $n.', 0),
(@ID, 'esMX', 'Ya solo falta el aire, $n.', 0);
-- 10480 Espíritus de agua iracundos
-- https://es.wowhead.com/quest=10480
SET @ID := 10480;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Alma acutica capturada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Doquiera encuentres nagas, casi seguro que encuentras espíritus de agua torturados.', 0),
(@ID, 'esMX', 'Doquiera encuentres nagas, casi seguro que encuentras espíritus de agua torturados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya solo falta el aire, $n.', 0),
(@ID, 'esMX', 'Ya solo falta el aire, $n.', 0);
-- 10481 Espíritus de aire iracundos
-- https://es.wowhead.com/quest=10481
SET @ID := 10481;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Alma aérea capturada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto hablaremos con las almas.', 0),
(@ID, 'esMX', 'Pronto hablaremos con las almas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Permíteme recompensarte por acometer tan ardua tarea, héroe.$B$B¡Y ahora a trabajar! Retrocede un poco para que pueda colocar el tótem y liberar a las almas.', 0),
(@ID, 'esMX', 'Permíteme recompensarte por acometer tan ardua tarea, héroe.$B$B¡Y ahora a trabajar! Retrocede un poco para que pueda colocar el tótem y liberar a las almas.', 0);
-- 10482 Orcos viles carroñeros
-- https://es.wowhead.com/quest=10482
SET @ID := 10482;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Mascahuesos aparecen en gran número, $N. ¡Mátalos o los orcos viles pueden invadirnos!', 0),
(@ID, 'esMX', 'Los Mascahuesos aparecen en gran número, $N. ¡Mátalos o los orcos viles pueden invadirnos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Sé bien que su pérdida será bien sentida en la Ciudadela del Fuego Infernal. A pesar de que ese bastión oscuro se cierne sobre nosotros, ¡con movimientos valientes como el tuyo obtendremos la victoria sobre los orcos viles!', 0),
(@ID, 'esMX', 'Muy bien. Sé bien que su pérdida será bien sentida en la Ciudadela del Fuego Infernal. A pesar de que ese bastión oscuro se cierne sobre nosotros, ¡con movimientos valientes como el tuyo obtendremos la victoria sobre los orcos viles!', 0);
-- 10483 Malos augurios
-- https://es.wowhead.com/quest=10483
SET @ID := 10483;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Información del Bastión del Honor, $n? Eso es bueno, nuestra campaña contra los demonios y los orcos viles empieza a estar necesitada de gente capaz.', 0),
(@ID, 'esMX', '¿Información del Bastión del Honor, $n? Eso es bueno, nuestra campaña contra los demonios y los orcos viles empieza a estar necesitada de gente capaz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿has recuperado una insignia de los orcos Foso Sangrante? Bien, ¡es intolerable que usen nuestros propios símbolos en nuestra contra y se rían de nuestros compañeros caídos ante las bestias de piel roja!', 0),
(@ID, 'esMX', 'Ah, ¿has recuperado una insignia de los orcos Foso Sangrante? Bien, ¡es intolerable que usen nuestros propios símbolos en nuestra contra y se rían de nuestros compañeros caídos ante las bestias de piel roja!', 0);
