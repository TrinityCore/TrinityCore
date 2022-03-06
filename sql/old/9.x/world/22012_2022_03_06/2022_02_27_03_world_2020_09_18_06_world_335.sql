-- 5821 Guardaespaldas de alquiler
-- https://es.classic.wowhead.com/quest=5821
SET @ID := 5821;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué sigo esperando esa maldita caravana?$B$B<Smeed parece iluminado.>$B$BOh, sí, ellos pagan las facturas. ¿Los has visto?', 0),
(@ID, 'esMX', '¿Por qué sigo esperando esa maldita caravana?$B$B<Smeed parece iluminado.>$B$BOh, sí, ellos pagan las facturas. ¿Los has visto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes, no parece rentable pagarle a gente como tú para proteger la caravana Gizelton. $c, si fuera un poco más alto, podría aceptar un segundo trabajo y sentarme con el arma más grande que mis manos pudieran llevar... y les mostraría a los malditos centauros quién es su papito.', 0),
(@ID, 'esMX', 'Sabes, no parece rentable pagarle a gente como tú para proteger la caravana Gizelton. $c, si fuera un poco más alto, podría aceptar un segundo trabajo y sentarme con el arma más grande que mis manos pudieran llevar... y les mostraría a los malditos centauros quién es su papito.', 0);
-- 5943 La caravana Gizelton
-- https://es.classic.wowhead.com/quest=5943
SET @ID := 5943;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes, si esa caravana desapareciera alguna vez, ¡estaría arruinado! No eres portador de malas noticias sobre la caravana, ¿verdad?$B$B<Smeed se seca el sudor de la frente.>$B$B¡Gracias a la diosa de la codicia!', 0),
(@ID, 'esMX', 'Sabes, si esa caravana desapareciera alguna vez, ¡estaría arruinado! No eres portador de malas noticias sobre la caravana, ¿verdad?$B$B<Smeed se seca el sudor de la frente.>$B$B¡Gracias a la diosa de la codicia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sé yo si es una propuesta propicia pagar tanto dinero para proteger la caravana Gizelton. Cork y Rigger solo se sacan una moneda de oro a la semana, pero mientras me paguen los kodos, tampoco es que me importe un carajo cómo lleven su negocio.', 0),
(@ID, 'esMX', 'No sé yo si es una propuesta propicia pagar tanto dinero para proteger la caravana Gizelton. Cork y Rigger solo se sacan una moneda de oro a la semana, pero mientras me paguen los kodos, tampoco es que me importe un carajo cómo lleven su negocio.', 0);
-- 1114 Un envío para los gnomos
-- https://es.classic.wowhead.com/quest=1114
SET @ID := 1114;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí? ¡Genial! A ver, a ver...', 0),
(@ID, 'esMX', '¿Tienes algo para mí? ¡Genial! A ver, a ver...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí están los hidrotrinquetes y las ballestas! Son perfectos. ¡Gracias!', 0),
(@ID, 'esMX', '¡Aquí están los hidrotrinquetes y las ballestas! Son perfectos. ¡Gracias!', 0);
-- 1115 Rumores
-- https://es.classic.wowhead.com/quest=1115
SET @ID := 1115;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Preguntas por Nazz Vaporio? Es un piloto de carreras en El Desierto de Sal, ¿no?$B$BSí, puede que averigüe algo sobre él, pero no será fácil. Ni rápido...', 0),
(@ID, 'esMX', '¿Preguntas por Nazz Vaporio? Es un piloto de carreras en El Desierto de Sal, ¿no?$B$BSí, puede que averigüe algo sobre él, pero no será fácil. Ni rápido...', 0);
-- 1186 El piloto nº18
-- https://es.classic.wowhead.com/quest=1186
SET @ID := 1186;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú eres quien ha estado ayudando a Pozzik, ¿verdad? Yo antes era como tú; andaba vagando por los boxes y ayudando a los mecánicos en lo que podía.$B$B¡Y mírame ahora! ¡Soy el piloto del equipo de carreras de los goblins!', 0),
(@ID, 'esMX', 'Tú eres quien ha estado ayudando a Pozzik, ¿verdad? Yo antes era como tú; andaba vagando por los boxes y ayudando a los mecánicos en lo que podía.$B$B¡Y mírame ahora! ¡Soy el piloto del equipo de carreras de los goblins!', 0);
-- 1190 Mantener la velocidad
-- https://es.classic.wowhead.com/quest=1190
SET @ID := 1190;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un pergamino de notas y diseños que explican el proceso de refinado de un material, garabateados con mala letra.', 0),
(@ID, 'esMX', 'Un pergamino de notas y diseños que explican el proceso de refinado de un material, garabateados con mala letra.', 0);
-- 1187 Los ajustes de Razzeric
-- https://es.classic.wowhead.com/quest=1187
SET @ID := 1187;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo voy a participar en la carrera sin contar con un pequeño empujoncito? ¡Haría el ridículo!', 0),
(@ID, 'esMX', '¿Cómo voy a participar en la carrera sin contar con un pequeño empujoncito? ¡Haría el ridículo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mira esta belleza! ¡Siete kilos de potencia de seforio macizo! Cuando se lo ponga a mi coche, iré tan rápido por la pista... ¡que adelantaré a los gnomos dos veces!', 0),
(@ID, 'esMX', '¡Mira esta belleza! ¡Siete kilos de potencia de seforio macizo! Cuando se lo ponga a mi coche, iré tan rápido por la pista... ¡que adelantaré a los gnomos dos veces!', 0);
-- 1191 La distracción de Zamek
-- https://es.classic.wowhead.com/quest=1191
SET @ID := 1191;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vamos!', 0),
(@ID, 'esMX', '¡Vamos!', 0);
-- 1194 Los esquemas de Rizzle
-- https://es.classic.wowhead.com/quest=1194
SET @ID := 1194;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Indurio? Interesante... Si tiene una resistencia al calor tan alta como dices, eso podría explicar la mejora en los resultados experimentada por los gnomos.$B$BAdemás, esta muestra que me has traído tiene un valor incalculable. Podré hacer algunas pruebas con ella pero necesitaré más para poder sacarle partido.', 0),
(@ID, 'esMX', '¿Indurio? Interesante... Si tiene una resistencia al calor tan alta como dices, eso podría explicar la mejora en los resultados experimentada por los gnomos.$B$BAdemás, esta muestra que me has traído tiene un valor incalculable. Podré hacer algunas pruebas con ella pero necesitaré más para poder sacarle partido.', 0);
-- 1192 Mena de indurio
-- https://es.classic.wowhead.com/quest=1192
SET @ID := 1192;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me gustaría usar indurio en diferentes partes de nuestros diseños, pero necesito grandes cantidades de mineral de indurio para crear estas partes.$B$BPuedes encontrar mineral de indurio en la excavación de Uldaman en Tierras Inhóspitas, al otro lado del mar en Khaz Modan.$B$BLos gnomos están obteniendo su propio suministro, por lo que es importante que tengamos el nuestro para seguirles el ritmo.', 0),
(@ID, 'esMX', 'Me gustaría usar indurio en diferentes partes de nuestros diseños, pero necesito grandes cantidades de mineral de indurio para crear estas partes.$B$BPuedes encontrar mineral de indurio en la excavación de Uldaman en Tierras Inhóspitas, al otro lado del mar en Khaz Modan.$B$BLos gnomos están obteniendo su propio suministro, por lo que es importante que tengamos el nuestro para seguirles el ritmo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Haré que el equipo trabaje de inmediato en las piezas que usaremos para la próxima carrera.', 0),
(@ID, 'esMX', '¡Excelente! Haré que el equipo trabaje de inmediato en las piezas que usaremos para la próxima carrera.', 0);
-- 1188 La seguridad primero
-- https://es.classic.wowhead.com/quest=1188
SET @ID := 1188;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Seguro que ya sabes que en la Cacharrería podrás encontrar todo lo que necesites! ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¡Seguro que ya sabes que en la Cacharrería podrás encontrar todo lo que necesites! ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Razzeric es el único que podría echar un vistazo a esto y decir que de algún modo le he puesto un seguro. ¡Este propulsor es seforio puro! Lo modifiqué para que suelte la mayor parte de la carga explosiva pero Razzeric siempre quiere más. ¡Quiere que vaya a tope!', 0),
(@ID, 'esMX', 'Razzeric es el único que podría echar un vistazo a esto y decir que de algún modo le he puesto un seguro. ¡Este propulsor es seforio puro! Lo modifiqué para que suelte la mayor parte de la carga explosiva pero Razzeric siempre quiere más. ¡Quiere que vaya a tope!', 0);
-- 1189 La seguridad primero
-- https://es.classic.wowhead.com/quest=1189
SET @ID := 1189;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedes creer que Pozzik puso un cubo de arena en el coche? ¿Cómo se supone que voy a llegar al máximo de velocidad con un cubo de arena bajo el asiento?', 0),
(@ID, 'esMX', '¿Puedes creer que Pozzik puso un cubo de arena en el coche? ¿Cómo se supone que voy a llegar al máximo de velocidad con un cubo de arena bajo el asiento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto está mejor! Me gustaría ver la cara que pondrán los gnomos cuando me vean pasar a la velocidad del rayo con esta belleza.$B$B¡Pero estaré demasiado ocupado batiendo un nuevo récord!', 0),
(@ID, 'esMX', '¡Esto está mejor! Me gustaría ver la cara que pondrán los gnomos cuando me vean pasar a la velocidad del rayo con esta belleza.$B$B¡Pero estaré demasiado ocupado batiendo un nuevo récord!', 0);
-- 2865 Caparazones de escarabajo
-- https://es.classic.wowhead.com/quest=2865
SET @ID := 2865;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los caparazones? Mi primo de Bahía del Botín sigue esperando el cargamento, ¡y se está impacientando!', 0),
(@ID, 'esMX', '¿Tienes los caparazones? Mi primo de Bahía del Botín sigue esperando el cargamento, ¡y se está impacientando!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, genial! ¡Los conseguiste!$B$BGracias, $n. ¡Eres $gun:una; $gauténtico:auténtica; salvavidas!', 0),
(@ID, 'esMX', '¡Oh, genial! ¡Los conseguiste!$B$BGracias, $n. ¡Eres $gun:una; $gauténtico:auténtica; salvavidas!', 0);
-- 3362 El Valle Cardizal
-- https://es.classic.wowhead.com/quest=3362
SET @ID := 3362;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me gustaría echar un vistazo más de cerca a ese cactus en el valle... Así que deja alguno de una pieza, ¿quieres?', 0),
(@ID, 'esMX', 'Me gustaría echar un vistazo más de cerca a ese cactus en el valle... Así que deja alguno de una pieza, ¿quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sabía que eran tan grandes. Creo que tengo que perfeccionar mi plan...$B$BPero tú has cumplido con tu parte, así que aquí tienes lo que te prometí.', 0),
(@ID, 'esMX', 'No sabía que eran tan grandes. Creo que tengo que perfeccionar mi plan...$B$BPero tú has cumplido con tu parte, así que aquí tienes lo que te prometí.', 0);
-- 4504 Superpegajoso
-- https://es.classic.wowhead.com/quest=4504
SET @ID := 4504;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tran\'rek lo ha vuelto a conseguir. ¡Este pegamento superpegajoso hará furor!', 0),
(@ID, 'esMX', 'Tran\'rek lo ha vuelto a conseguir. ¡Este pegamento superpegajoso hará furor!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este alquitrán es genial...$B$B¡Eh, espera un segundo! Mis manos... están pegadas...$B$BQuizás no haya sido tan buena idea. ¡Ah, eso es! ¡Quita-alquitrán superpegajoso! ¡Ahí es donde está el dinero!', 0),
(@ID, 'esMX', 'Sí, este alquitrán es genial...$B$B¡Eh, espera un segundo! Mis manos... están pegadas...$B$BQuizás no haya sido tan buena idea. ¡Ah, eso es! ¡Quita-alquitrán superpegajoso! ¡Ahí es donde está el dinero!', 0);
-- 2781 SE BUSCA: Califa Escorpijón
-- https://es.classic.wowhead.com/quest=2781
SET @ID := 2781;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí $c, yo soy un oficial de la compañía de aguas de Gadgetzan. ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', 'Sí $c, yo soy un oficial de la compañía de aguas de Gadgetzan. ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin se ha hecho justicia! ¡Has asestado un duro golpe a esos infames nómadas! La muerte de Escorpijón será clave para expulsar finalmente a los que se están aprovechando de los pozos de agua de Gadgetzan.$B$BPor la autoridad que me confiere la compañía de aguas de Gadgetzan, te hago entrega de tu recompensa. Nos has prestado un gran servicio a todos nosotros.', 0),
(@ID, 'esMX', '¡Al fin se ha hecho justicia! ¡Has asestado un duro golpe a esos infames nómadas! La muerte de Escorpijón será clave para expulsar finalmente a los que se están aprovechando de los pozos de agua de Gadgetzan.$B$BPor la autoridad que me confiere la compañía de aguas de Gadgetzan, te hago entrega de tu recompensa. Nos has prestado un gran servicio a todos nosotros.', 0);
-- 2875 SE BUSCA: Andre Barbafuego
-- https://es.classic.wowhead.com/quest=2875
SET @ID := 2875;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces un tanto aturdido. ¿Has estado leyendo nuestros documentos legales?', 0),
(@ID, 'esMX', 'Pareces un tanto aturdido. ¿Has estado leyendo nuestros documentos legales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la cabeza de Andre! ¡Supongo que al final recibió su merecido!$B$BMuchas gracias, $n. Y ahora si me firmas aquí, te pagaré por los servicios prestados.$B$BNo te preocupes por la letra pequeña, no pone nada interesante y... de todos modos, no creo que exista una lupa lo suficientemente buena como para poder leerla.', 0),
(@ID, 'esMX', '¡Ah, la cabeza de Andre! ¡Supongo que al final recibió su merecido!$B$BMuchas gracias, $n. Y ahora si me firmas aquí, te pagaré por los servicios prestados.$B$BNo te preocupes por la letra pequeña, no pone nada interesante y... de todos modos, no creo que exista una lupa lo suficientemente buena como para poder leerla.', 0);
-- 1707 Cazador de faltriqueras de agua
-- https://es.classic.wowhead.com/quest=1707
SET @ID := 1707;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes las faltriqueras de agua de los Deambuladores que necesitamos? ¡Si es así, entonces recibirás el paquete modelo 103-XB de la compañía de aguas de Gadgetzan!', 0),
(@ID, 'esMX', '¿Ya tienes las faltriqueras de agua de los Deambuladores que necesitamos? ¡Si es así, entonces recibirás el paquete modelo 103-XB de la compañía de aguas de Gadgetzan!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0),
(@ID, 'esMX', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0);
-- 1690 Justicia para los Vagayermos
-- https://es.classic.wowhead.com/quest=1690
SET @ID := 1690;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto? ¡Espero que hayas podido hacer justicia al estilo goblin a esos bandidos y ladrones Vagayermos como te pedí!', 0),
(@ID, 'esMX', '¿Regresaste tan pronto? ¡Espero que hayas podido hacer justicia al estilo goblin a esos bandidos y ladrones Vagayermos como te pedí!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡A eso le llamo yo ser eficiente! Has acabado con tantos nómadas que ya se dibuja la posibilidad de recuperar nuestros pozos de agua.$B$BLa compañía de aguas de Gadgetzan te agradece tu inestimable ayuda, aunque todavía queda mucho trabajo que hacer con estos nómadas. Escucha atentamente, esto lo próximo que necesitamos que hagas...', 0),
(@ID, 'esMX', '¡A eso le llamo yo ser eficiente! Has acabado con tantos nómadas que ya se dibuja la posibilidad de recuperar nuestros pozos de agua.$B$BLa compañía de aguas de Gadgetzan te agradece tu inestimable ayuda, aunque todavía queda mucho trabajo que hacer con estos nómadas. Escucha atentamente, esto lo próximo que necesitamos que hagas...', 0);
-- 2768 Vara divinomática
-- https://es.classic.wowhead.com/quest=2768
SET @ID := 2768;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste al sargento Bly? ¿Tienes mi Vara Divinomática?', 0),
(@ID, 'esMX', '¿Encontraste al sargento Bly? ¿Tienes mi Vara Divinomática?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo encontraste! ¡Bien hecho, $n! ¿Tuviste que luchar con Bly para conseguirlo? Espero que le dieras bien fuerte a él y a toda su banda.', 0),
(@ID, 'esMX', '¡Lo encontraste! ¡Bien hecho, $n! ¿Tuviste que luchar con Bly para conseguirlo? Espero que le dieras bien fuerte a él y a toda su banda.', 0);
-- 2605 El goblin sediento
-- https://es.classic.wowhead.com/quest=2605
SET @ID := 2605;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor, dime que has encontrado a los colectores de rocío.', 0),
(@ID, 'esMX', 'Por favor, dime que has encontrado a los colectores de rocío.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, maravilloso! ¡Trae, me lo voy a beber!', 0),
(@ID, 'esMX', '¡Oh, maravilloso! ¡Trae, me lo voy a beber!', 0);
