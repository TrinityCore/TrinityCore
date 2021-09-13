-- 10484 Dijes malditos
-- https://es.wowhead.com/quest=10484
SET @ID := 10484;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde están los dijes, $n?', 0),
(@ID, 'esMX', '¿Dónde están los dijes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Se me entristece el corazón al verlos. Son el recuerdo de las grandes pérdidas que hemos tenido frente a los orcos viles en el Bastión del Honor. Si matamos suficientes, quizás podamos salir victoriosos de esta guerra.', 0),
(@ID, 'esMX', 'Gracias, $n. Se me entristece el corazón al verlos. Son el recuerdo de las grandes pérdidas que hemos tenido frente a los orcos viles en el Bastión del Honor. Si matamos suficientes, quizás podamos salir victoriosos de esta guerra.', 0);
-- 10485 Señor de la guerra del Foso Sangrante
-- https://es.wowhead.com/quest=10485
SET @ID := 10485;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la armadura destrozada de Morkh? ¿Te has adentrado en Zeth\'Gor de nuevo?', 0),
(@ID, 'esMX', '¿Tienes la armadura destrozada de Morkh? ¿Te has adentrado en Zeth\'Gor de nuevo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! ¡Morkh ha muerto! ¡Ahora tenemos una oportunidad frente a los orcos viles!$B$BGracias, $n. Tú ayuda aquí ha sido encomiable.', 0),
(@ID, 'esMX', '¡Lo has conseguido! ¡Morkh ha muerto! ¡Ahora tenemos una oportunidad frente a los orcos viles!$B$BGracias, $n. Tú ayuda aquí ha sido encomiable.', 0);
-- 10486 La naturaleza invasora
-- https://es.wowhead.com/quest=10486
SET @ID := 10486;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestra supervivencia aquí depende de nuestra capacidad para concentrar nuestros esfuerzos contra aquellos que realmente importan, no los meros Flebotomistas Alacuchilla.$B$B¿Estás aquí de nuevo, por lo que esto debe significar que has tratado el asunto en cuestión?', 0),
(@ID, 'esMX', 'Nuestra supervivencia aquí depende de nuestra capacidad para concentrar nuestros esfuerzos contra aquellos que realmente importan, no los meros Flebotomistas Alacuchilla.$B$B¿Estás aquí de nuevo, por lo que esto debe significar que has tratado el asunto en cuestión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No has tardado tanto como pensaba. ¿Seguro que te has ocupado de tantos como era necesario?$B$BMuy bien, hay algo más en lo que quiero que nos ayudes. Algo mucho más importante.', 0),
(@ID, 'esMX', 'No has tardado tanto como pensaba. ¿Seguro que te has ocupado de tantos como era necesario?$B$BMuy bien, hay algo más en lo que quiero que nos ayudes. Algo mucho más importante.', 0);
-- 10487 Polvo de los dracos
-- https://es.wowhead.com/quest=10487
SET @ID := 10487;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece como si la Alianza estuviera decidida a seguirnos dondequiera que vayamos. Enseñémosles que no nos intimida su presencia.$B$B¿Tienes lo que te pedí?', 0),
(@ID, 'esMX', 'Parece como si la Alianza estuviera decidida a seguirnos dondequiera que vayamos. Enseñémosles que no nos intimida su presencia.$B$B¿Tienes lo que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No solo has debilitado su defensa, sino que vamos a utilizar este polvo para reforzar nuestra propia defensa contra la Alianza.', 0),
(@ID, 'esMX', 'No solo has debilitado su defensa, sino que vamos a utilizar este polvo para reforzar nuestra propia defensa contra la Alianza.', 0);
-- 10488 Proteger a los nuestros
-- https://es.wowhead.com/quest=10488
SET @ID := 10488;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Lobo temible Señor del Trueno reforzado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va el refuerzo de las defensas de nuestros lobos temibles del Señor del Trueno?', 0),
(@ID, 'esMX', '¿Cómo va el refuerzo de las defensas de nuestros lobos temibles del Señor del Trueno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que has reforzado a los lobos y las defensas de la Cresta Dentada, quizás podamos volver a centrar nuestra atención en asuntos más letales, como los ogros.$B$BHas hecho un buen trabajo ayudándonos. Nos podría venir bien la ayuda de alguien hábil, como tú, si decidieras quedarte.$B$BHagas lo que hagas, te has ganado mi respeto y agradecimiento.', 0),
(@ID, 'esMX', 'Ahora que has reforzado a los lobos y las defensas de la Cresta Dentada, quizás podamos volver a centrar nuestra atención en asuntos más letales, como los ogros.$B$BHas hecho un buen trabajo ayudándonos. Nos podría venir bien la ayuda de alguien hábil, como tú, si decidieras quedarte.$B$BHagas lo que hagas, te has ganado mi respeto y agradecimiento.', 0);
-- 10489 Talar un antiguo árbol
-- https://es.wowhead.com/quest=10489
SET @ID := 10489;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí? ¡Sí que eres fuerte!', 0),
(@ID, 'esMX', '¿Qué tienes ahí? ¡Sí que eres fuerte!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El tronco de Manofirme Raizhonda! ¿Lo talaste tú $gsolo:sola;?$B$BApuesto a que sí. ¿Sabes? $gUn:Una; $c joven y fuerte, como tú, siempre viene bien para ayudar por aquí, sobre todo con los problemas que los ogros no dejan de causarnos. No dejes de venir a verme si te interesa.$B$BBueno, ese tronco es sin duda una prueba, lo que significa que estás aquí para cobrar la recompensa y no para escucharme hablar. Adelante, elige lo que quieras.', 0),
(@ID, 'esMX', '¡El tronco de Manofirme Raizhonda! ¿Lo talaste tú $gsolo:sola;?$B$BApuesto a que sí. ¿Sabes? $gUn:Una; $c joven y fuerte, como tú, siempre viene bien para ayudar por aquí, sobre todo con los problemas que los ogros no dejan de causarnos. No dejes de venir a verme si te interesa.$B$BBueno, ese tronco es sin duda una prueba, lo que significa que estás aquí para cobrar la recompensa y no para escucharme hablar. Adelante, elige lo que quieras.', 0);
-- 10490 La llamada del agua
-- https://es.tbc.wowhead.com/quest=10490
SET @ID := 10490;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos encontremos de nuevo. He estado observando tu progreso desde lejos, $c, y estoy complacido.$B$BHa llegado el momento de que te comuniques con el elemento agua, aprendas sus misterios y te entregues al agua para que, a su vez, aprendas a dominarlo.', 0),
(@ID, 'esMX', 'Nos encontremos de nuevo. He estado observando tu progreso desde lejos, $c, y estoy complacido.$B$BHa llegado el momento de que te comuniques con el elemento agua, aprendas sus misterios y te entregues al agua para que, a su vez, aprendas a dominarlo.', 0);
-- 10491 La llamada del aire
-- https://es.tbc.wowhead.com/quest=10491
SET @ID := 10491;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y finalmente llegamos a él, el último de los cuatro grandes elementos: el aire. ¿Te crees lo suficientemente $gsabio:sabia; para continuar, $N?', 0),
(@ID, 'esMX', 'Y finalmente llegamos a él, el último de los cuatro grandes elementos: el aire. ¿Te crees lo suficientemente $gsabio:sabia; para continuar, $N?', 0);
-- 10498 Guardar lo mejor para el final
-- https://es.tbc.wowhead.com/quest=10498
SET @ID := 10498;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De acuerdo con nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Corazón Salvaje a cambio de tu nuevo chaleco y capucha cuoroferal?', 0),
(@ID, 'esMX', 'De acuerdo con nuestro trato, ¿estás $glisto:lista; para entregar tus piezas de Corazón Salvaje a cambio de tu nuevo chaleco y capucha cuoroferal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a extrañar, $N. Te debo una gran deuda de gratitud; Creo que nunca podré pagarlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0),
(@ID, 'esMX', 'Te voy a extrañar, $N. Te debo una gran deuda de gratitud; Creo que nunca podré pagarlo.$B$BEspero que disfrutes de tu nueva armadura para la cabeza y el pecho, y que te proteja durante mucho tiempo.', 0);
-- 10499 Guardar lo mejor para el final
-- https://es.wowhead.com/quest=10499
SET @ID := 10499;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según nuestro trato, ¿estás $glisto:lista; para entregar las piezas Forjaluz a cambio de tu nueva corona y túnica de hechicero?', 0),
(@ID, 'esMX', 'Según nuestro trato, ¿estás $glisto:lista; para entregar las piezas Forjaluz a cambio de tu nueva corona y túnica de hechicero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente te extrañaré, $N. Tengo una deuda que te debo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0),
(@ID, 'esMX', 'Realmente te extrañaré, $N. Tengo una deuda que te debo y que tal vez nunca pueda pagar.$B$BDisfruta de tu nueva armadura para la cabeza y el pecho. ¡Que te proteja durante mucho tiempo y te ayude a alcanzar un honor aún mayor!', 0);
-- 10502 Los ogros Machacasangre
-- https://es.wowhead.com/quest=10502
SET @ID := 10502;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ogros Machacasangre muertos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros exploradores han informado que los ogros Machacasangre han comenzado a subir sigilosamente por la sendero, que conduce a la Arboleda Viviente desde su bodega.$B$BEs una pena que no podamos encontrar la manera de vivir juntos en paz con los ogros, pero..., ¿cuándo hemos podido hacerlo?', 0),
(@ID, 'esMX', 'Nuestros exploradores han informado que los ogros Machacasangre han comenzado a subir sigilosamente por la sendero, que conduce a la Arboleda Viviente desde su bodega.$B$BEs una pena que no podamos encontrar la manera de vivir juntos en paz con los ogros, pero..., ¿cuándo hemos podido hacerlo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se trata de un buen primer paso a la hora de asegurar Sylvanaar y La Arboleda.$B$BAl haber reducido sus filas, los ogros Machacasangre se lo pensarán dos veces antes de atacarnos.$B$BOjalá fuera el único clan de ogros del que tenemos que preocuparnos.', 0),
(@ID, 'esMX', 'Se trata de un buen primer paso a la hora de asegurar Sylvanaar y La Arboleda.$B$BAl haber reducido sus filas, los ogros Machacasangre se lo pensarán dos veces antes de atacarnos.$B$BOjalá fuera el único clan de ogros del que tenemos que preocuparnos.', 0);
-- 10503 La amenaza Aguja del Filo
-- https://es.wowhead.com/quest=10503
SET @ID := 10503;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ogros Aguja del Filo muertos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros exploradores han informado que los ogros Aguja del Filo han establecido un campamento aún más cerca del camino, que nos lleva desde su fortaleza hasta aquí.$B$BEs una pena que no podamos simplemente someter a esta escoria de ogros a nuestra voluntad, pero si lo que quieren es una pelea, encontrarán a la Horda más que complaciente.', 0),
(@ID, 'esMX', 'Nuestros exploradores han informado que los ogros Aguja del Filo han establecido un campamento aún más cerca del camino, que nos lleva desde su fortaleza hasta aquí.$B$BEs una pena que no podamos simplemente someter a esta escoria de ogros a nuestra voluntad, pero si lo que quieren es una pelea, encontrarán a la Horda más que complaciente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se trata de un buen primer paso a la hora de asegurar nuestra posición contra los ogros.$B$BAl haber reducido sus filas, los Aguja del Filo se lo pensarán dos veces antes de intentar conquistar el Bastión Señor del Trueno.$B$BOjalá fuera el único clan de ogros del que tenemos que preocuparnos.', 0),
(@ID, 'esMX', 'Se trata de un buen primer paso a la hora de asegurar nuestra posición contra los ogros.$B$BAl haber reducido sus filas, los Aguja del Filo se lo pensarán dos veces antes de intentar conquistar el Bastión Señor del Trueno.$B$BOjalá fuera el único clan de ogros del que tenemos que preocuparnos.', 0);
-- 10504 Los ogros Aguja del Filo
-- https://es.wowhead.com/quest=10504
SET @ID := 10504;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ogros Aguja del Filo muertos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Machacasangre o Aguja del Filo, no importa. Todos los clanes de ogros luchan entre sí, compitiendo por el dominio que conlleva tener el favor de Gruul el Asesino de Dragones.$B$BAmbos siguen siendo nuestros enemigos, independientemente de a quién haya recaído ese favor.', 0),
(@ID, 'esMX', 'Machacasangre o Aguja del Filo, no importa. Todos los clanes de ogros luchan entre sí, compitiendo por el dominio que conlleva tener el favor de Gruul el Asesino de Dragones.$B$BAmbos siguen siendo nuestros enemigos, independientemente de a quién haya recaído ese favor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus acciones contra los clanes Machacasangre y Aguja del Filo han significado un gran paso adelante a la hora de asegurar el futuro de Sylvanaar. Si bien no pretendemos expandirnos más allá de este trozo de tierra que, inicialmente, encontramos vacío, tampoco estamos dispuestos a permitir que nos destruyan.$B$BComo nos has hecho un gran servicio, lo recompensaré con el reconocimiento y el agradecimiento de la Alianza.', 0),
(@ID, 'esMX', 'Tus acciones contra los clanes Machacasangre y Aguja del Filo han significado un gran paso adelante a la hora de asegurar el futuro de Sylvanaar. Si bien no pretendemos expandirnos más allá de este trozo de tierra que, inicialmente, encontramos vacío, tampoco estamos dispuestos a permitir que nos destruyan.$B$BComo nos has hecho un gran servicio, lo recompensaré con el reconocimiento y el agradecimiento de la Alianza.', 0);
-- 10505 Los ogros Machacasangre
-- https://es.wowhead.com/quest=10505
SET @ID := 10505;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ogros Machacasangre muertos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aguja del Filo o Machacasangre, no importa. Todos los clanes de ogros luchan entre sí, compitiendo por el dominio que conlleva tener el favor de Gruul el Asesino de Dragones.$B$BAmbos siguen siendo nuestros enemigos, independientemente de en quién haya recaído ese favor, ¡y nos enfrentaremos a ellos!', 0),
(@ID, 'esMX', 'Aguja del Filo o Machacasangre, no importa. Todos los clanes de ogros luchan entre sí, compitiendo por el dominio que conlleva tener el favor de Gruul el Asesino de Dragones.$B$BAmbos siguen siendo nuestros enemigos, independientemente de en quién haya recaído ese favor, ¡y nos enfrentaremos a ellos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus acciones contra los clanes Aguja del Filo y Machacasangre han significado un gran paso adelante a la hora de asegurar el futuro del Bastión Señor del Trueno. No estamos dispuestos a permitir que se interpongan en nuestro destino.$B$BComo nos has hecho un gran servicio, lo recompensaré con el reconocimiento y el agradecimiento de la Horda.', 0),
(@ID, 'esMX', 'Tus acciones contra los clanes Aguja del Filo y Machacasangre han significado un gran paso adelante a la hora de asegurar el futuro del Bastión Señor del Trueno. No estamos dispuestos a permitir que se interpongan en nuestro destino.$B$BComo nos has hecho un gran servicio, lo recompensaré con el reconocimiento y el agradecimiento de la Horda.', 0);
-- 10506 Una situación extrema
-- https://es.wowhead.com/quest=10506
SET @ID := 10506;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Lobo temible Machacasangre debilitado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido algo de suerte? Sé que es peligroso estar haciendo esto entre los ogros Machacasangre, pero si podemos evitar la matanza de más animales, estaré satisfecha.', 0),
(@ID, 'esMX', '¿Ha habido algo de suerte? Sé que es peligroso estar haciendo esto entre los ogros Machacasangre, pero si podemos evitar la matanza de más animales, estaré satisfecha.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de oír que funcionó. Cuantas menos criaturas de la naturaleza tengan que morir, mejor.$B$BCon todo lo que ya has hecho por nosotros, tengo que decir que empiezo a aficionarme mucho a tu compañía.$B$BCuídate, $n.', 0),
(@ID, 'esMX', 'Me alegro de oír que funcionó. Cuantas menos criaturas de la naturaleza tengan que morir, mejor.$B$BCon todo lo que ya has hecho por nosotros, tengo que decir que empiezo a aficionarme mucho a tu compañía.$B$BCuídate, $n.', 0);
-- 10507 Punto de inflexión
-- https://es.wowhead.com/quest=10507
SET @ID := 10507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho, $n?', 0),
(@ID, 'esMX', '¿Lo has hecho, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres una persona con un poder extraordinario, $n. Los Arúspices tienen suerte de contar contigo como $galiado:aliada;.$B$BCuando se corra la voz sobre la nueva lealtad de Kael, más gente verá las cosas como nosotros. El hecho de que podamos reivindicar una victoria tan decisiva contra los nuevos Señores Supremos de Kael\'thas nos coloca en una situación de lo más favorable.$B$BNo olvidaré tus hazañas.', 0),
(@ID, 'esMX', 'Eres una persona con un poder extraordinario, $n. Los Arúspices tienen suerte de contar contigo como $galiado:aliada;.$B$BCuando se corra la voz sobre la nueva lealtad de Kael, más gente verá las cosas como nosotros. El hecho de que podamos reivindicar una victoria tan decisiva contra los nuevos Señores Supremos de Kael\'thas nos coloca en una situación de lo más favorable.$B$BNo olvidaré tus hazañas.', 0);
-- 10508 Un regalo para Voren'thal
-- https://es.wowhead.com/quest=10508
SET @ID := 10508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la piedra de teletransporte de Socrethar, $n?', 0),
(@ID, 'esMX', '¿Has conseguido la piedra de teletransporte de Socrethar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No dejas de sorprenderme, $n! Me alegro de que estés de nuestro lado.', 0),
(@ID, 'esMX', '¡No dejas de sorprenderme, $n! Me alegro de que estés de nuestro lado.', 0);
-- 10509 Destinado a la gloria
-- https://es.wowhead.com/quest=10509
SET @ID := 10509;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tienes idea de lo que esto significará para los Arúspices, $n. Tendrás que disculparme mientras cojo aliento y evalúo la situación.', 0),
(@ID, 'esMX', 'No tienes idea de lo que esto significará para los Arúspices, $n. Tendrás que disculparme mientras cojo aliento y evalúo la situación.', 0);
-- 10510 En el interior de la Mina Draenetista
-- https://es.wowhead.com/quest=10510
SET @ID := 10510;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No te parece excitante? Después de toda la suciedad y los insectos de Silithus, este lugar es como un paraíso.', 0),
(@ID, 'esMX', '¿No te parece excitante? Después de toda la suciedad y los insectos de Silithus, este lugar es como un paraíso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ooh, por la pinta que tienen, son unos cristales excelentes. Me muero por coger mis herramientas y ponerme a estudiarlos.$B$B¡Muchas gracias!', 0),
(@ID, 'esMX', 'Ooh, por la pinta que tienen, son unos cristales excelentes. Me muero por coger mis herramientas y ponerme a estudiarlos.$B$B¡Muchas gracias!', 0);
