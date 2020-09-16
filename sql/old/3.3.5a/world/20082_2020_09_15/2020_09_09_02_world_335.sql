-- 7670 Lord Grisillo Quiebrasombras
-- https://es.wowhead.com/quest=7670
SET @ID := 7670;
UPDATE `quest_template_locale` SET `Details` = '$n, voy a explicarte lo que debes hacer para conseguir una montura.$B$BHabla con Lord Grisillo Quiebrasombras en el Distrito de la Catedral de Ventormenta. Te enseñará a cuidar de tu montura y te dirá qué tareas debes completar para conseguir una.$B$BTe deseo lo mejor. ¡Por la Luz, mi noble $ghermano:hermana;', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir su montura, y ahora ha llegado el momento.$B$BSeguramente se te pondrá a prueba de muchas maneras diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!', 0),
(@ID, 'esMX', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir su montura, y ahora ha llegado el momento.$B$BSeguramente se te pondrá a prueba de muchas maneras diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!', 0);
-- 8646 Rugidomazo el Ancestro
-- https://es.wowhead.com/quest=8646
SET @ID := 8646;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(@ID, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- 7648 Un trabajo bien hecho
-- https://es.classic.wowhead.com/quest=7648
SET @ID := 7648;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás progresando muy bien, $n. Una vez que haya hecho su barda, estará en camino a la siguiente tarea.', 0),
(@ID, 'esMX', 'Estás progresando muy bien, $n. Una vez que haya hecho su barda, estará en camino a la siguiente tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este trabajo es impresionante. Parece que a medida que Grimand envejece, su destreza continúa mejorando. Esa es una gran hazaña cuando su trabajo ya era uno de los mejores que encontrarías en cualquier lugar cuando hizo mi barda en el pasado.$B$BSi bien esta barda sería una excelente adición a cualquier corcel normal, no estamos tratando con una bestia tan mundana. Necesitará esta barda bendecida por una fuente adecuada para que sea digna de descansar sobre la montura de $gun:una; $c. Lo guardaré por ti hasta entonces.', 0),
(@ID, 'esMX', 'Este trabajo es impresionante. Parece que a medida que Grimand envejece, su destreza continúa mejorando. Esa es una gran hazaña cuando su trabajo ya era uno de los mejores que encontrarías en cualquier lugar cuando hizo mi barda en el pasado.$B$BSi bien esta barda sería una excelente adición a cualquier corcel normal, no estamos tratando con una bestia tan mundana. Necesitará esta barda bendecida por una fuente adecuada para que sea digna de descansar sobre la montura de $gun:una; $c. Lo guardaré por ti hasta entonces.', 0);
-- 11335 Llamamiento a las armas: Cuenca de Arathi
-- https://es.wowhead.com/quest=11335
SET @ID := 11335;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0),
(@ID, 'esMX', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0);
-- 1468 Semana de los Niños
-- https://es.wowhead.com/quest=1468
SET @ID := 1468;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm... hola. Me llamo Randis y supongo que me estás buscando, ¿no? Eres un aventurero, como lo fueron mi mamá y mi papá. Me alegro de conocerte.$B$BEspero que nos divirtamos mucho juntos. Hay unas cosas que me gustaría hacer, y mi matrona dice que harás de hermano para mí esta semana. Me encantaría, sí señor.', 0),
(@ID, 'esMX', 'Mm... hola. Me llamo Randis y supongo que me estás buscando, ¿no? Eres un aventurero, como lo fueron mi mamá y mi papá. Me alegro de conocerte.$B$BEspero que nos divirtamos mucho juntos. Hay unas cosas que me gustaría hacer, y mi matrona dice que harás de hermano para mí esta semana. Me encantaría, sí señor.', 0);
-- 11336 Llamamiento a las armas: Valle de Alterac
-- https://es.wowhead.com/quest=11336
SET @ID := 11336;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0),
(@ID, 'esMX', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0);
-- 11337 Llamamiento a las armas: Ojo de la Tormenta
-- https://es.wowhead.com/quest=11337
SET @ID := 11337;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hemos dado un paso más para lograr la victoria total sobre la Horda. No podemos permitir que el enemigo se establezca en este mundo o en cualquier otro.', 0),
(@ID, 'esMX', 'Hemos dado un paso más para lograr la victoria total sobre la Horda. No podemos permitir que el enemigo se establezca en este mundo o en cualquier otro.', 0);
-- 11338 Llamamiento a las armas: Garganta Grito de Guerra
-- https://es.wowhead.com/quest=11338
SET @ID := 11338;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0);
-- 9292 Cristal necrótico rajado
-- https://es.classic.wowhead.com/quest=9292
SET @ID := 9292;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hay algo que necesites?', 0),
(@ID, 'esMX', '¿Hay algo que necesites?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hm, ¿tomaste esto del cadáver de una de las abominaciones invasoras?$B$BHemos recibido noticias desde los campamentos base de la necrópolis que están siendo convocados por la Plaga. Sospecho que querían crear uno dentro de Ventormenta. Es bueno que no hayan tenido éxito.', 0),
(@ID, 'esMX', 'Hm, ¿tomaste esto del cadáver de una de las abominaciones invasoras?$B$BHemos recibido noticias desde los campamentos base de la necrópolis que están siendo convocados por la Plaga. Sospecho que querían crear uno dentro de Ventormenta. Es bueno que no hayan tenido éxito.', 0);
-- 5634
SET @ID := 5634;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'You have done the Light a great service by becoming a shining example to those who travel in these dangerous lands and beyond. Please, accept this lesson as a thanks for all you\'ve done.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(@ID, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0);
-- 5635, 5636, 5637, 5638, 5639, 5640 Oración desesperada
-- https://es.classic.wowhead.com/quest=5635
DELETE FROM `quest_offer_reward` WHERE `ID` IN (5635, 5636, 5637, 5638, 5639, 5640);
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES 
(5635, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5636, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5637, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5638, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5639, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0),
(5640, 'I\'m glad you\'ve arrived, <name>. There are many things we will have to discuss, but more importantly is your training in the ways of the Light.$B$BThere are lessons all servants of the Light must learn. If you are ready, we\'ll begin discussing some of those now.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (5635, 5636, 5637, 5638, 5639, 5640) AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5635, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5636, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5637, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5638, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5639, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5640, 'esES', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5635, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5636, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5637, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5638, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5639, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0),
(5640, 'esMX', 'Le has prestado un gran servicio a la Luz al convertirte en un brillante ejemplo para aquellos que viajan por estas peligrosas tierras y más allá. Por favor, acepte esta lección como agradecimiento por todo lo que ha hecho.', 0);
-- 1661 Escrito sobre nobleza
-- https://es.classic.wowhead.com/quest=1661
SET @ID := 1661;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'Congratulations, and may the Light protect you.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Felicitaciones y que la Luz te proteja.', 0),
(@ID, 'esMX', 'Felicitaciones y que la Luz te proteja.', 0);
-- 14163 Llamamiento a las armas: Isla de la Conquista
-- https://es.wowhead.com/quest=14163
SET @ID := 14163;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué bueno verte, $n! ¿Tienes noticias del frente?', 0),
(@ID, 'esMX', '¡Qué bueno verte, $n! ¿Tienes noticias del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Horda nunca será rival para nuestras fuerzas mientras tengamos a gente como tú de nuestro lado, $n.', 0),
(@ID, 'esMX', 'La Horda nunca será rival para nuestras fuerzas mientras tengamos a gente como tú de nuestro lado, $n.', 0);
-- 3681 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=3681
SET @ID := 3681;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; a la Catedral de la Luz, $c.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; a la Catedral de la Luz, $c.', 0);
-- 1790 El Símbolo de la Vida
-- https://es.classic.wowhead.com/quest=1790
SET @ID := 1790;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Date prisa, $n, más de una vida está en juego si fallas.$B$BSi por alguna razón no ayudas a Gazin y Henze, regresa conmigo y te daré otro Símbolo de Vida para tus viajes.$B$BNo confundas mi ayuda con una simple caridad, debes demostrar que eres digno como cualquier otro $c y el fracaso continuo puede reflejarse en ti más adelante.', 0),
(@ID, 'esMX', 'Date prisa, $n, más de una vida está en juego si fallas.$B$BSi por alguna razón no ayudas a Gazin y Henze, regresa conmigo y te daré otro Símbolo de Vida para tus viajes.$B$BNo confundas mi ayuda con una simple caridad, debes demostrar que eres digno como cualquier otro $c y el fracaso continuo puede reflejarse en ti más adelante.', 0);
-- 8860 ¡Las fiestas de Año Nuevo!
-- https://es.wowhead.com/quest=8860
SET @ID := 8860;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos! ¿Has venido al festival o solo te has parado a descansar?', 0),
(@ID, 'esMX', '¡Saludos! ¿Has venido al festival o solo te has parado a descansar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la comida de Pastos de Bosquehumeante! ¡Estupendo!$B$BGracias, $n. Acepta esto como recompensa; y ahora, ¡sal a beber y a divertirte!', 0),
(@ID, 'esMX', '¡Ah, la comida de Pastos de Bosquehumeante! ¡Estupendo!$B$BGracias, $n. Acepta esto como recompensa; y ahora, ¡sal a beber y a divertirte!', 0);
-- 5676 La reacción Arcana
-- https://es.classic.wowhead.com/quest=5676
SET @ID := 5676;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos vimos obligados a aprender algunas magias para protegernos de lo que comúnmente se llama nuestro mayor enemigo: los arcanos.$B$BTe enseñaré un hechizo para ayudarte a defenderte a ti mismo y a tus compañeros de aquellos que ejercen tal poder.', 0),
(@ID, 'esMX', 'Nos vimos obligados a aprender algunas magias para protegernos de lo que comúnmente se llama nuestro mayor enemigo: los arcanos.$B$BTe enseñaré un hechizo para ayudarte a defenderte a ti mismo y a tus compañeros de aquellos que ejercen tal poder.', 0);
-- 5677 La reacción Arcana
-- https://es.classic.wowhead.com/quest=5677
SET @ID := 5677;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'Ah, you have wonderful timing, <name>. I was beginning to wonder if all of my messengers had been successful. I\'m glad to see they were, otherwise I would wager you\'d still be out in the world learning more about all the threats that exist against our people.$B$BAre you ready? Ready for more training I mean. You\'re growing in power more quickly, and I feel you are ready to learn more about our faith.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0),
(@ID, 'esMX', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0);
-- 5678 La reacción Arcana
-- https://es.classic.wowhead.com/quest=5677
SET @ID := 5678;
DELETE FROM `quest_offer_reward` WHERE `ID` = @ID;
INSERT INTO `quest_offer_reward` (`ID`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'Ah, you have wonderful timing, <name>. I was beginning to wonder if all of my messengers had been successful. I\'m glad to see they were, otherwise I would wager you\'d still be out in the world learning more about all the threats that exist against our people.$B$BAre you ready? Ready for more training I mean. You\'re growing in power more quickly, and I feel you are ready to learn more about our faith.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0),
(@ID, 'esMX', 'Ah, tienes una sincronización maravillosa, $n. Empezaba a preguntarme si todos mis mensajeros habían tenido éxito. Me alegra ver que lo tuvieron, de lo contrario, apostaría a que aún estaría en el mundo aprendiendo más sobre todas las amenazas que existen contra nuestra gente.$B$B¿Estás $glisto:lista;? $gListo:Lista; para más entrenamiento, quiero decir. Estás creciendo en poder más rápidamente y siento que estás $gpreparado:preparada; para aprender más sobre nuestra fe.', 0);
-- 7630 La arcanita
-- https://es.classic.wowhead.com/quest=7630
SET @ID := 7630;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la arcanita, $n? Una vez que lo tenga, puedo hacerte la magnetita.', 0),
(@ID, 'esMX', '¿Tienes la arcanita, $n? Una vez que lo tenga, puedo hacerte la magnetita.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo tienes! ¡Bien hecho! Ahora puedo crear la magnetita. Cuando finalmente estés listo para tu ritual para crear el Círculo de Invocación Mayor, querrás una magnetita para asegurarte de que el ritual no se esfume.', 0),
(@ID, 'esMX', '¡Lo tienes! ¡Bien hecho! Ahora puedo crear la magnetita. Cuando finalmente estés listo para tu ritual para crear el Círculo de Invocación Mayor, querrás una magnetita para asegurarte de que el ritual no se esfume.', 0);
-- 14178 Llamamiento a las armas: Cuenca de Arathi
-- https://es.wowhead.com/quest=14178
SET @ID := 14178;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0),
(@ID, 'esMX', '¡Excelentes noticias, $c! Si nuestros despliegues tácticos siguen teniendo tanto éxito, la Horda se retirará por completo en poco tiempo.', 0);
