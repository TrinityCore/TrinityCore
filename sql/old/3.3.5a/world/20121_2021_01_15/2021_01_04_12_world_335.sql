-- 1056 Viaje a Cima del Espolón
-- https://es.classic.wowhead.com/quest=1056
SET @ID := 1056;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin has llegado. Veo que Faldreas ha escuchado a los espíritus del bosque...', 0),
(@ID, 'esMX', 'Por fin has llegado. Veo que Faldreas ha escuchado a los espíritus del bosque...', 0);
-- 1058 Magia del bosque de Jin'Zil
-- https://es.classic.wowhead.com/quest=1058
SET @ID := 1058;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mira a nuestros pobres amiguitos elfos. ¡Todos enjaulados sin un bosque donde retozar!$B$B¿Has podido conseguirme la savia? ¿Y los mostachos de los corredores Crepusculares? ¿Supongo que no tendrás la escama de dragón hada?$B$B¡Y los ojos! ¡Necesito montones de ojos! ¡No puedes crear una poción de magia del bosque poderosa sin muchos ojos!', 0),
(@ID, 'esMX', 'Mira a nuestros pobres amiguitos elfos. ¡Todos enjaulados sin un bosque donde retozar!$B$B¿Has podido conseguirme la savia? ¿Y los mostachos de los corredores Crepusculares? ¿Supongo que no tendrás la escama de dragón hada?$B$B¡Y los ojos! ¡Necesito montones de ojos! ¡No puedes crear una poción de magia del bosque poderosa sin muchos ojos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, qué contentas estarán estas pequeñas ninfas de los bosques! Haremos que se sientan como en casa con este brebaje especial.', 0),
(@ID, 'esMX', '¡Oh, qué contentas estarán estas pequeñas ninfas de los bosques! Haremos que se sientan como en casa con este brebaje especial.', 0);
-- 1060 Una carta para Jin'Zil
-- https://es.classic.wowhead.com/quest=1060
SET @ID := 1060;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces un personaje turbio. ¿Traes algo para mí?', 0),
(@ID, 'esMX', 'Pareces un personaje turbio. ¿Traes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, una carta de Darsok. Hacía muchos años que no sabía nada de él.$B$B¿Así que el último de los Sangrepluma ha muerto? Qué buena noticia, recuerdo cuando mi amigo Rokhan se marchó con el loco mok\'nathal para matar a su hermana mayor. Ah, quién fuera joven otra vez, como tú.', 0),
(@ID, 'esMX', 'Ah, una carta de Darsok. Hacía muchos años que no sabía nada de él.$B$B¿Así que el último de los Sangrepluma ha muerto? Qué buena noticia, recuerdo cuando mi amigo Rokhan se marchó con el loco mok\'nathal para matar a su hermana mayor. Ah, quién fuera joven otra vez, como tú.', 0);
-- 1061 Los espíritus del Espolón
-- https://es.classic.wowhead.com/quest=1061
SET @ID := 1061;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $c. Perfecto, tu habilidad nos ayudará con esos invasores.', 0),
(@ID, 'esMX', 'Ah, $c. Perfecto, tu habilidad nos ayudará con esos invasores.', 0);
-- 1062 Los invasores goblin
-- https://es.classic.wowhead.com/quest=1062
SET @ID := 1062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sierra Espolón se encuentra al noroeste, $n. Vamos. ¡Hay que infundir miedo en aquellos que saquearían esta tierra!', 0),
(@ID, 'esMX', 'Sierra Espolón se encuentra al noroeste, $n. Vamos. ¡Hay que infundir miedo en aquellos que saquearían esta tierra!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy valiente, $n.$B$BQuizás al final necesitemos la sabiduría de los ancestros tauren para apaciguar a los espíritus de Espolón, pero...$B$BAcabar con el personal de Ventura y Cía. es un buen primer paso contra ellos.', 0),
(@ID, 'esMX', 'Muy valiente, $n.$B$BQuizás al final necesitemos la sabiduría de los ancestros tauren para apaciguar a los espíritus de Espolón, pero...$B$BAcabar con el personal de Ventura y Cía. es un buen primer paso contra ellos.', 0);
-- 1063 La bruja anciana
-- https://es.classic.wowhead.com/quest=1063
SET @ID := 1063;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida. ¿Estás aquí en busca de consejo?', 0),
(@ID, 'esMX', 'Te doy la bienvenida. ¿Estás aquí en busca de consejo?', 0);
-- 1064 La ayuda de los Renegados
-- https://es.classic.wowhead.com/quest=1064
SET @ID := 1064;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Magatha dijo que vendrías, $n. Mi corazón ya ha dejado de latir pero aun así siento lástima por los habitantes de Espolón.$B$BLos Renegados estamos deseosos de ayudar en todo lo que podamos.', 0),
(@ID, 'esMX', 'Magatha dijo que vendrías, $n. Mi corazón ya ha dejado de latir pero aun así siento lástima por los habitantes de Espolón.$B$BLos Renegados estamos deseosos de ayudar en todo lo que podamos.', 0);
-- 1065 Viaja a Molino Tarren
-- https://es.classic.wowhead.com/quest=1065
SET @ID := 1065;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido a traerme mis nuevos sujetos de experimento?', 0),
(@ID, 'esMX', '¿Has venido a traerme mis nuevos sujetos de experimento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Una nota de parte de Zamah? Debe de estar desesperada para enviarte desde tan lejos. Veamos lo que dice...$B$B¡Ah, estupendo! ¡Sé exactamente lo que hay que hacer!', 0),
(@ID, 'esMX', '¿Una nota de parte de Zamah? Debe de estar desesperada para enviarte desde tan lejos. Veamos lo que dice...$B$B¡Ah, estupendo! ¡Sé exactamente lo que hay que hacer!', 0);
-- 1066 Sangre inocente
-- https://es.classic.wowhead.com/quest=1066
SET @ID := 1066;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes la sangre que te pedí?', 0),
(@ID, 'esMX', '¿Traes la sangre que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien!$B$BComo dije, no es fácil conseguir Sangre de los inocentes; suerte que la Hermandad nos hizo el trabajo.$B$BEspera mientras preparo la toxina.', 0),
(@ID, 'esMX', '¡Muy bien!$B$BComo dije, no es fácil conseguir Sangre de los inocentes; suerte que la Hermandad nos hizo el trabajo.$B$BEspera mientras preparo la toxina.', 0);
-- 1067 Regresa a Cima del Trueno
-- https://es.classic.wowhead.com/quest=1067
SET @ID := 1067;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Me traes algo del boticario Lydon?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Me traes algo del boticario Lydon?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De parte de Lydon? Muy bien. Seguro que esta toxina nos ayuda en nuestra lucha contra Ventura y Cía..', 0),
(@ID, 'esMX', '¿De parte de Lydon? Muy bien. Seguro que esta toxina nos ayuda en nuestra lucha contra Ventura y Cía..', 0);
-- 1068 Las sierras XT:4 y XT:9
-- https://es.classic.wowhead.com/quest=1068
SET @ID := 1068;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los espíritus de los árboles gimen por la pérdida de sus hermanos, $n. Debes destruir las sierras XT:4 y XT:9, o me temo que Sierra Espolón nunca se curará.', 0),
(@ID, 'esMX', 'Los espíritus de los árboles gimen por la pérdida de sus hermanos, $n. Debes destruir las sierras XT:4 y XT:9, o me temo que Sierra Espolón nunca se curará.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La destrucción de las máquinas XT:4 y XT:9 ha calmado a muchos de los espíritus de Espolón, $n. Esperemos que, con su pérdida, Ventura y Cía. se vaya de estas montañas.$B$BPorque si no lo hace, me temo que las atrocidades que este lugar ha sufrido palidecerán en comparación con las que nos depara el futuro.', 0),
(@ID, 'esMX', 'La destrucción de las máquinas XT:4 y XT:9 ha calmado a muchos de los espíritus de Espolón, $n. Esperemos que, con su pérdida, Ventura y Cía. se vaya de estas montañas.$B$BPorque si no lo hace, me temo que las atrocidades que este lugar ha sufrido palidecerán en comparación con las que nos depara el futuro.', 0);
-- 1086 El aeropuerto
-- https://es.classic.wowhead.com/quest=1086
SET @ID := 1086;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes encontrar el aeropuerto de Ventura y Cia, si es que existe, $n.', 0),
(@ID, 'esMX', 'Debes encontrar el aeropuerto de Ventura y Cia, si es que existe, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! ¡Seguro que esos globlins se llevaron una sorpresa!$B$BNo te sientas culpable por lo que has hecho; esa gente merece esto y más.$B$BEn mis años de servicio he aprendido algo:$B$Btodo medio es válido si conduce a la victoria.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! ¡Seguro que esos globlins se llevaron una sorpresa!$B$BNo te sientas culpable por lo que has hecho; esa gente merece esto y más.$B$BEn mis años de servicio he aprendido algo:$B$Btodo medio es válido si conduce a la victoria.', 0);
-- 1087 El legado de Cenarius
-- https://es.classic.wowhead.com/quest=1087
SET @ID := 1087;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí, canalizar la magia es como sacar agua de un pozo con un balde lleno de agujeros.', 0),
(@ID, 'esMX', 'Aquí, canalizar la magia es como sacar agua de un pozo con un balde lleno de agujeros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya puedo sentirlo... sí... un poder tan dulce... el flujo... Los kaldorei son unos necios por desdeñar los regalos de este mundo, por rechazar el curso de la magia cuando fluye cantando por tus venas.$B$B¡De qué sirve la vida sin esa ardiente comunión!', 0),
(@ID, 'esMX', 'Ya puedo sentirlo... sí... un poder tan dulce... el flujo... Los kaldorei son unos necios por desdeñar los regalos de este mundo, por rechazar el curso de la magia cuando fluye cantando por tus venas.$B$B¡De qué sirve la vida sin esa ardiente comunión!', 0);
-- 1088 Ordanus
-- https://es.classic.wowhead.com/quest=1088
SET @ID := 1088;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando mi maestro me destinó a la Cima del Espolón, supuse que todo lo que tendría que hacer era acabar con los elfos de la noche que se arrastraban por las ruinas sagradas de nuestro antiguo Templo de Azshara despojándolo de su santidad al tocarlo... pero me había olvidado de Ordanus.', 0),
(@ID, 'esMX', 'Cuando mi maestro me destinó a la Cima del Espolón, supuse que todo lo que tendría que hacer era acabar con los elfos de la noche que se arrastraban por las ruinas sagradas de nuestro antiguo Templo de Azshara despojándolo de su santidad al tocarlo... pero me había olvidado de Ordanus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez vi a Ordanus, hace mucho. Tenía la arrogancia típica de los suyos, creyéndose por encima incluso de los altonatos.$B$BPero ahora su cabeza no está tan estirada, ¿eh, $n?$B$BTe prometí una recompensa, y la tendrás. Atiéndeme.', 0),
(@ID, 'esMX', 'Una vez vi a Ordanus, hace mucho. Tenía la arrogancia típica de los suyos, creyéndose por encima incluso de los altonatos.$B$BPero ahora su cabeza no está tan estirada, ¿eh, $n?$B$BTe prometí una recompensa, y la tendrás. Atiéndeme.', 0);
-- 1089 El Cubil
-- https://es.classic.wowhead.com/quest=1089
SET @ID := 1089;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay tres cerraduras talladas en la piedra.', 0),
(@ID, 'esMX', 'Hay tres cerraduras talladas en la piedra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que las tres llaves se deslizan en sus aberturas correspondientes, en medio de la luz brillante aparecen varios elementos.', 0),
(@ID, 'esMX', 'A medida que las tres llaves se deslizan en sus aberturas correspondientes, en medio de la luz brillante aparecen varios elementos.', 0);
-- 1090 Órdenes de Gerenzo
-- https://es.classic.wowhead.com/quest=1090
SET @ID := 1090;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. La situación parecía algo complicada y, probablemente, habíamos atraído demasiada atención.$B$BLo más importante es que tenemos la muestra del mineral y que debemos llevársela a Ziz lo antes posible.', 0),
(@ID, 'esMX', 'Gracias, $n. La situación parecía algo complicada y, probablemente, habíamos atraído demasiada atención.$B$BLo más importante es que tenemos la muestra del mineral y que debemos llevársela a Ziz lo antes posible.', 0);
-- 1092 Órdenes de Gerenzo
-- https://es.classic.wowhead.com/quest=1092
SET @ID := 1092;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte con algo?', 0),
(@ID, 'esMX', '¿Puedo ayudarte con algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahhh, sabía que había hecho lo correcto al decirle a Piznik que se quedara atrás. Seguro que los ingenieros de Villabajo estarán más que interesados por esto...$B$BEstá claro que me quedaré con parte para mí, pero ojos que no ven corazón que no siente, ¿no crees?', 0),
(@ID, 'esMX', 'Ahhh, sabía que había hecho lo correcto al decirle a Piznik que se quedara atrás. Seguro que los ingenieros de Villabajo estarán más que interesados por esto...$B$BEstá claro que me quedaré con parte para mí, pero ojos que no ven corazón que no siente, ¿no crees?', 0);
-- 1098 Mortacechadores en Colmillo Oscuro
-- https://es.classic.wowhead.com/quest=1098
SET @ID := 1098;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cuerpo de Vincent yace inmóvil.$B$BAunque el mortacechador Adamant enviará un informe a Hadrec, Vincent se llevó a la tumba otros secretos.$B$BPero tiene en la mano un abalorio...', 0),
(@ID, 'esMX', 'El cuerpo de Vincent yace inmóvil.$B$BAunque el mortacechador Adamant enviará un informe a Hadrec, Vincent se llevó a la tumba otros secretos.$B$BPero tiene en la mano un abalorio...', 0);
-- 1100 El diario de Soliceja
-- https://es.classic.wowhead.com/quest=1100
SET @ID := 1100;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De tu cara de preocupación se deduce que algo no marcha bien...', 0),
(@ID, 'esMX', 'De tu cara de preocupación se deduce que algo no marcha bien...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y dices que este diario lo tenía un enano muerto? Dame un momento para leerlo...', 0),
(@ID, 'esMX', '¿Y dices que este diario lo tenía un enano muerto? Dame un momento para leerlo...', 0);
-- 1101 La bruja del Horado
-- https://es.classic.wowhead.com/quest=1101
SET @ID := 1101;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras Charlga Filonavaja esté reuniendo una fuerza en el Horado Rajacieno, estas tierras están en gran peligro.', 0),
(@ID, 'esMX', 'Mientras Charlga Filonavaja esté reuniendo una fuerza en el Horado Rajacieno, estas tierras están en gran peligro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La vieja ha sido sepultada. Esta es una noticia fantástica, $n.$B$BEn estos tiempos de peligro, es reconfortante ver a alguien tan valiente como tú.$B$BCon los esbirros de Filonavaja despachados, nuestros estudios en el área pueden continuar. Quizás ahora podamos obtener más conocimientos sobre qué sucedió exactamente para corromper el lugar de descanso de Agamaggan.$B$BSin embargo, me temo que la respuesta a esa pregunta también se encuentra en la traición...', 0),
(@ID, 'esMX', 'La vieja ha sido sepultada. Esta es una noticia fantástica, $n.$B$BEn estos tiempos de peligro, es reconfortante ver a alguien tan valiente como tú.$B$BCon los esbirros de Filonavaja despachados, nuestros estudios en el área pueden continuar. Quizás ahora podamos obtener más conocimientos sobre qué sucedió exactamente para corromper el lugar de descanso de Agamaggan.$B$BSin embargo, me temo que la respuesta a esa pregunta también se encuentra en la traición...', 0);
-- 1102 Un destino vengador
-- https://es.classic.wowhead.com/quest=1102
SET @ID := 1102;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando las bestias de Horado Rajacieno hayan sido expulsadas de su guarida, podré por fin descansar en paz sabiendo que han recibido su merecido.$B$B¿Has echado a los jabaespines del Horado? Dime que sí, y que me traes el corazón de Filonavaja como prueba de ello...', 0),
(@ID, 'esMX', 'Cuando las bestias de Horado Rajacieno hayan sido expulsadas de su guarida, podré por fin descansar en paz sabiendo que han recibido su merecido.$B$B¿Has echado a los jabaespines del Horado? Dime que sí, y que me traes el corazón de Filonavaja como prueba de ello...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tribu de Horado Rajacieno ya conoce de primera mano el sufrimiento vivido por mi pueblo. ¡Esas bestias se lo tenían bien merecido!$B$BExpulsar a alguien de una tierra sagrada es un pecado que merece un duro castigo.$B$BGracias por tu ayuda, $n.', 0),
(@ID, 'esMX', 'La tribu de Horado Rajacieno ya conoce de primera mano el sufrimiento vivido por mi pueblo. ¡Esas bestias se lo tenían bien merecido!$B$BExpulsar a alguien de una tierra sagrada es un pecado que merece un duro castigo.$B$BGracias por tu ayuda, $n.', 0);
-- 1103 La llamada del agua
-- https://es.classic.wowhead.com/quest=1103
SET @ID := 1103;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES 
(@ID, 'esES', '¿Tienes la sapta, $ghermano:hermana;?$B$BConozco a otro que tuvo problemas después de derrotar a un espíritu d\'agua corrupto; parece qu\'esperó demasiao y salió del mundo de los espíritus demasiao rápido pa\' su gusto. Odio que le pase a otro, así qu\'esperaré aquí un poco pa\' asegurarme de que nadie más necesite mi ayuda.', 0),
(@ID, 'esMX', '¿Tienes la sapta, $ghermano:hermana;?$B$BConozco a otro que tuvo problemas después de derrotar a un espíritu d\'agua corrupto; parece qu\'esperó demasiao y salió del mundo de los espíritus demasiao rápido pa\' su gusto. Odio que le pase a otro, así qu\'esperaré aquí un poco pa\' asegurarme de que nadie más necesite mi ayuda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES 
(@ID, 'esES', 'Ahhh, den tu listo ...$B$BLo pondré to\' en el blandón y tú también podrás hablar con los espíritus.$B$BY no te preocupes por ver el mundo de los espíritus con la sapta... el viejo Tiev sabe un par de trucos sobre cómo funciona la magia de la sapta.$B$BVen ahora, baja conmigo al santuario y hablemos juntos con los espíritus, $ghermano:hermana;.', 0),
(@ID, 'esMX', 'Ahhh, den tu listo ...$B$BLo pondré to\' en el blandón y tú también podrás hablar con los espíritus.$B$BY no te preocupes por ver el mundo de los espíritus con la sapta... el viejo Tiev sabe un par de trucos sobre cómo funciona la magia de la sapta.$B$BVen ahora, baja conmigo al santuario y hablemos juntos con los espíritus, $ghermano:hermana;.', 0);
-- 1109 Guano del Horado
-- https://es.classic.wowhead.com/quest=1109
SET @ID := 1109;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, veo que estás de vuelta. ¿Has conseguido guano del Horado?', 0),
(@ID, 'esMX', 'Ah, veo que estás de vuelta. ¿Has conseguido guano del Horado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espléndido! Era justo lo que necesitábamos para comenzar, $n.', 0),
(@ID, 'esMX', '¡Espléndido! Era justo lo que necesitábamos para comenzar, $n.', 0);
-- 1113 Corazones de fanatismo
-- https://es.classic.wowhead.com/quest=1113
SET @ID := 1113;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en el Monasterio Escarlata? ¡Voy a necesitar muchos corazones para mi maravilloso experimento!$B$BSin duda, a Varimathras y a la Dama Oscura también les gustará deshacerse de la porquería escarlata...', 0),
(@ID, 'esMX', '¿Has estado en el Monasterio Escarlata? ¡Voy a necesitar muchos corazones para mi maravilloso experimento!$B$BSin duda, a Varimathras y a la Dama Oscura también les gustará deshacerse de la porquería escarlata...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has traído sangre en abundancia, $n. Tus esfuerzos han sido más que sobresalientes.', 0),
(@ID, 'esMX', 'Me has traído sangre en abundancia, $n. Tus esfuerzos han sido más que sobresalientes.', 0);
-- 1116 Polvo onírico en el pantano
-- https://es.classic.wowhead.com/quest=1116
SET @ID := 1116;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has vuelto? ¿Tienes mi polvo de sueño?', 0),
(@ID, 'esMX', '¿Ya has vuelto? ¿Tienes mi polvo de sueño?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eh, mira eso. ¡Encontraste el polvo de sueño!$B$B¿Y qué, te gustó el pantano, $n? No es fácil conseguir comida allí, ¿verdad?', 0),
(@ID, 'esMX', 'Eh, mira eso. ¡Encontraste el polvo de sueño!$B$B¿Y qué, te gustó el pantano, $n? No es fácil conseguir comida allí, ¿verdad?', 0);
-- 1123 Rabine Saturna
-- https://es.classic.wowhead.com/quest=1123
SET @ID := 1123;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Soy Rabine Saturna. Te doy la bienvenida de parte del guardián Remulos y de los demás habitantes de este sagrado claro.$B$BAprecio tu interés y tu deseo de ayudar al Círculo Cenarion. Los tauren respetan los principios de Cenarius y, por ello, la Horda también es bien recibida en este claro. Ambos perseguimos un objetivo común, que es preservar Azeroth.$B$BAquí estás entre amigos, $n.', 0),
(@ID, 'esMX', 'Soy Rabine Saturna. Te doy la bienvenida de parte del guardián Remulos y de los demás habitantes de este sagrado claro.$B$BAprecio tu interés y tu deseo de ayudar al Círculo Cenarion. Los tauren respetan los principios de Cenarius y, por ello, la Horda también es bien recibida en este claro. Ambos perseguimos un objetivo común, que es preservar Azeroth.$B$BAquí estás entre amigos, $n.', 0);
-- 1127 Cerveza de tontos
-- https://es.classic.wowhead.com/quest=1127
SET @ID := 1127;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes esas mezclas de Zanzil, $n?', 0),
(@ID, 'esMX', '¿Ya tienes esas mezclas de Zanzil, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, muy bien! Aquí está tu paga.$B$BY aquí hay algo extra... por tu discreción.', 0),
(@ID, 'esMX', '¡Ah, muy bien! Aquí está tu paga.$B$BY aquí hay algo extra... por tu discreción.', 0);
-- 1130 Melor manda saludos
-- https://es.classic.wowhead.com/quest=1130
SET @ID := 1130;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has venido, $n. ¿Estás preparado para tu viaje por tierras lejanas?$B$BSi es así, joven $c, escucha atentamente.', 0),
(@ID, 'esMX', 'Has venido, $n. ¿Estás preparado para tu viaje por tierras lejanas?$B$BSi es así, joven $c, escucha atentamente.', 0);
-- 1131 Metaleador
-- https://es.classic.wowhead.com/quest=1131
SET @ID := 1131;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado a Metaleador, $n?', 0),
(@ID, 'esMX', '¿Has derrotado a Metaleador, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has derrotado a Metaleador y con ello has liberado a Las Mil Agujas de una auténtica pesadilla.$B$BEsa era la lección que quería enseñarte hoy.', 0),
(@ID, 'esMX', 'Has derrotado a Metaleador y con ello has liberado a Las Mil Agujas de una auténtica pesadilla.$B$BEsa era la lección que quería enseñarte hoy.', 0);
-- 1132 Fiora Orejona
-- https://es.classic.wowhead.com/quest=1132
SET @ID := 1132;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buenos días! ¿Te envía el señor Llavesílex de Puerto de Menethil? El señor Llavesílex es un buen psicólogo así que si él te envía, eso quiere decir que en Kalimdor encontrarás tu sitio.', 0),
(@ID, 'esMX', '¡Buenos días! ¿Te envía el señor Llavesílex de Puerto de Menethil? El señor Llavesílex es un buen psicólogo así que si él te envía, eso quiere decir que en Kalimdor encontrarás tu sitio.', 0);
-- 1133 Viaje a Astranaar
-- https://es.classic.wowhead.com/quest=1133
SET @ID := 1133;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás aquí para ofrecer tus servicios a la Alianza, $n? Toda ayuda es bien recibida porque, aunque el Bosque de Vallefresno conserva su belleza, ya no es un lugar tan pacífico como antes.', 0),
(@ID, 'esMX', '¿Estás aquí para ofrecer tus servicios a la Alianza, $n? Toda ayuda es bien recibida porque, aunque el Bosque de Vallefresno conserva su belleza, ya no es un lugar tan pacífico como antes.', 0);
