-- 5624 Las prendas de la Luz
-- https://es.classic.wowhead.com/quest=5624
SET @ID := 5624;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como ya habrás aprendido, nuestras magias curativas son vitales para la supervivencia de nuestra gente en estos tiempos difíciles, especialmente para los aventureros y héroes que toman las armas y la magia para luchar contra tantas amenazas diferentes.$B$BHarías bien en recordar siempre lo importante que es esa habilidad. Eso, sumado a la Fortaleza, hará que tus compañeros sean mucho más capaces en la batalla, ya que podrán resistir un mayor número de golpes.$B$BNo dejes que nadie descarte lo poderosas que son sus magias.', 0),
(@ID, 'esMX', 'Como ya habrás aprendido, nuestras magias curativas son vitales para la supervivencia de nuestra gente en estos tiempos difíciles, especialmente para los aventureros y héroes que toman las armas y la magia para luchar contra tantas amenazas diferentes.$B$BHarías bien en recordar siempre lo importante que es esa habilidad. Eso, sumado a la Fortaleza, hará que tus compañeros sean mucho más capaces en la batalla, ya que podrán resistir un mayor número de golpes.$B$BNo dejes que nadie descarte lo poderosas que son sus magias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n Con un guardia más sano para ayudar a la ciudad, estaremos mucho más seguros. Me alegra ver que ya estás aprendiendo a usar tus habilidades con sabiduría. Si sientes que estás listo para recibir más capacitación en cualquier momento, por favor regrese a mí. Pero por ahora, coge esta toga. Les permitirá a los demás saber que eres uno de nuestra orden. Si no quieres ponértela, está bien. Más adelante habrá más pruebas y esta toga no es necesaria para ellas.', 0),
(@ID, 'esMX', 'Excelente, $n Con un guardia más sano para ayudar a la ciudad, estaremos mucho más seguros. Me alegra ver que ya estás aprendiendo a usar tus habilidades con sabiduría. Si sientes que estás listo para recibir más capacitación en cualquier momento, por favor regrese a mí. Pero por ahora, coge esta toga. Les permitirá a los demás saber que eres uno de nuestra orden. Si no quieres ponértela, está bien. Más adelante habrá más pruebas y esta toga no es necesaria para ellas.', 0);
-- 9260 Investigar la Plaga de Ventormenta
-- https://es.wowhead.com/quest=9260
SET @ID := 9260;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hmm. Por lo que me dices, las voces dentro de los círculos... deben usarse como comunicación de algún tipo. Me estremezco al pensar en qué mentes antinaturales se contactan a través de tal magia. Independientemente, parece que has salido $gsano:sana; y $gsalvo:salva;. El Alba Argenta agradece tu servicio.', 0),
(@ID, 'esMX', 'Hmm. Por lo que me dices, las voces dentro de los círculos... deben usarse como comunicación de algún tipo. Me estremezco al pensar en qué mentes antinaturales se contactan a través de tal magia. Independientemente, parece que has salido $gsano:sana; y $gsalvo:salva;. El Alba Argenta agradece tu servicio.', 0);
-- 184 Las escrituras de Cejade
-- https://es.classic.wowhead.com/quest=184
SET @ID := 184;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Tienes la escritura de mi granja?? ¡Qué buena noticia! Me la robaron unos rufianes hace unos días... ¡La daba por perdida!$B$BPor favor, deja que la coja. Estamos saliendo de los Páramos de Poniente y no vamos a volver pronto, pero si lo hacemos, necesitaré esos papeles...', 0),
(@ID, 'esMX', '¿¿Tienes la escritura de mi granja?? ¡Qué buena noticia! Me la robaron unos rufianes hace unos días... ¡La daba por perdida!$B$BPor favor, deja que la coja. Estamos saliendo de los Páramos de Poniente y no vamos a volver pronto, pero si lo hacemos, necesitaré esos papeles...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muchas gracias, $n! Como te decía, este ya no es lugar para gente honrada como nosotros. Pero si en un futuro las cosas mejoran, esta escritura nos permitirá reclamar nuestras tierras.$B$BNo tengo mucho que ofrecer, tan solo esto.', 0),
(@ID, 'esMX', '¡Muchas gracias, $n! Como te decía, este ya no es lugar para gente honrada como nosotros. Pero si en un futuro las cosas mejoran, esta escritura nos permitirá reclamar nuestras tierras.$B$BNo tengo mucho que ofrecer, tan solo esto.', 0);
-- 123 El Coleccionista
-- https://es.classic.wowhead.com/quest=123
SET @ID := 123;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué?! ¡Pero si nuestra gente lleva meses sin trabajar en las minas de Elwynn!$B$BDéjame ver esa nota...', 0),
(@ID, 'esMX', '¡¿Qué?! ¡Pero si nuestra gente lleva meses sin trabajar en las minas de Elwynn!$B$BDéjame ver esa nota...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm... He oído hablar de ese Coleccionista, pero no sé para quién trabaja. Gracias por la información. Nos ayudará a resolver este misterio.', 0),
(@ID, 'esMX', 'Mm... He oído hablar de ese Coleccionista, pero no sé para quién trabaja. Gracias por la información. Nos ayudará a resolver este misterio.', 0);
-- 147 La persecución
-- https://es.classic.wowhead.com/quest=147
SET @ID := 147;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado al Coleccionista? ¿Has averiguado para quién trabaja?', 0),
(@ID, 'esMX', '¿Has encontrado al Coleccionista? ¿Has averiguado para quién trabaja?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has encontrado? Bien hecho, $n. ¡Ya no volverá a "coleccionar"!$B$BY... este anillo que encontraste es muy interesante. Es un anillo de la antigua Hermandad de albañiles de Ventormenta. ¿Cómo habrá llegado el anillo de una hermandad de artesanos a manos de un mísero ladrón? ¿Y por qué los ladrones Defias se llevan dinero de nuestras minas?$B$BSon preguntas difíciles de responder. Pero espero que algún día encontraré esas respuestas.', 0),
(@ID, 'esMX', '¿Lo has encontrado? Bien hecho, $n. ¡Ya no volverá a "coleccionar"!$B$BY... este anillo que encontraste es muy interesante. Es un anillo de la antigua Hermandad de albañiles de Ventormenta. ¿Cómo habrá llegado el anillo de una hermandad de artesanos a manos de un mísero ladrón? ¿Y por qué los ladrones Defias se llevan dinero de nuestras minas?$B$BSon preguntas difíciles de responder. Pero espero que algún día encontraré esas respuestas.', 0);
-- 1666 El mariscal Haggard
-- https://es.classic.wowhead.com/quest=1666
SET @ID := 1666;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién es?$B$B¿Burlguard, eres tú?$B$BTendrás que acercarte un poco más. Mis ojos ya no son lo que eran. $B$B¡Andando así creía que eras un gnoll!', 0),
(@ID, 'esMX', '¿Quién es?$B$B¿Burlguard, eres tú?$B$BTendrás que acercarte un poco más. Mis ojos ya no son lo que eran. $B$B¡Andando así creía que eras un gnoll!', 0);
-- 1667 Jack Dentomuerto
-- https://es.classic.wowhead.com/quest=1667
SET @ID := 1667;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi insignia? No quiero ni pensar en todo el daño que ha podido hacer Jack Dentomuerto con ella.', 0),
(@ID, 'esMX', '¿Tienes mi insignia? No quiero ni pensar en todo el daño que ha podido hacer Jack Dentomuerto con ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡La encontraste! Temía que estuviera perdida para siempre y que la utilizaran los Defias para fingir ser algún oficial de Ventormenta. Bien, ahora ya no pueden hacerlo, gracias a ti.$B$BEstas son algunas armas que utilicé cuando era alguacil. Las conservé en buen estado, ¡elige lo que quieras!', 0),
(@ID, 'esMX', '¡Genial! ¡La encontraste! Temía que estuviera perdida para siempre y que la utilizaran los Defias para fingir ser algún oficial de Ventormenta. Bien, ahora ya no pueden hacerlo, gracias a ti.$B$BEstas son algunas armas que utilicé cuando era alguacil. Las conservé en buen estado, ¡elige lo que quieras!', 0);
-- 2205 Busca el IV:7
-- https://es.classic.wowhead.com/quest=2205
SET @ID := 2205;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte, $c?', 0),
(@ID, 'esMX', '¿Puedo ayudarte, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me encontraste, y al mirarte, diría que la carrera y la búsqueda posterior pueden haber sido una gran tensión para tu sistema, tanto mental como físicamente.$B$B¿Te gustaría que Renzik te mostrara el camino a una posada o estás listo para trabajar?', 0),
(@ID, 'esMX', 'Me encontraste, y al mirarte, diría que la carrera y la búsqueda posterior pueden haber sido una gran tensión para tu sistema, tanto mental como físicamente.$B$B¿Te gustaría que Renzik te mostrara el camino a una posada o estás listo para trabajar?', 0);
-- 1860 Habla con Jennea
-- https://es.classic.wowhead.com/quest=1860
SET @ID := 1860;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te han enviado para ayudarme con mi tarea, $n? Bien. Es alentador ver cómo $glos:las; jóvenes $gmagos:magas; se esfuerzan por ayudar a nuestra causa...$B$B¿Qué causa, dices? A su debido tiempo, joven. Lo sabrás... a su debido tiempo.', 0),
(@ID, 'esMX', '¿Te han enviado para ayudarme con mi tarea, $n? Bien. Es alentador ver cómo $glos:las; jóvenes $gmagos:magas; se esfuerzan por ayudar a nuestra causa...$B$B¿Qué causa, dices? A su debido tiempo, joven. Lo sabrás... a su debido tiempo.', 0);
-- 1861 Lago Espejo
-- https://es.classic.wowhead.com/quest=1861
SET @ID := 1861;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la muestra, $n? El flujo mágico de Ventormenta y Elwynn ha sido alterado y debo averiguar si se está filtrando en el agua.', 0),
(@ID, 'esMX', '¿Tienes la muestra, $n? El flujo mágico de Ventormenta y Elwynn ha sido alterado y debo averiguar si se está filtrando en el agua.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Comprobaré las propiedades mágicas de este agua. Esperemos que no contenga ninguna o los que han estado bebiendo demasiado tiempo agua del Lago Espejo podrían estar afectados.$B$BToma, $n. Coge este orbe o este bastón como prueba de tus servicios. Que te sean de ayuda.', 0),
(@ID, 'esMX', 'Gracias, $n. Comprobaré las propiedades mágicas de este agua. Esperemos que no contenga ninguna o los que han estado bebiendo demasiado tiempo agua del Lago Espejo podrían estar afectados.$B$BToma, $n. Coge este orbe o este bastón como prueba de tus servicios. Que te sean de ayuda.', 0);
-- 2206 El robo
-- https://es.wowhead.com/quest=2206
SET @ID := 2206;
UPDATE `quest_template_locale` SET `Objectives` = 'Encuentra al maestro de embarcadero y recupera el calendario de envíos para el maestro Mathias Shaw.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu mortandad disminuye con cada momento que desperdicias merodeando en los barracones, $c.', 0),
(@ID, 'esMX', 'Tu mortandad disminuye con cada momento que desperdicias merodeando en los barracones, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy asombrado ... Asombrado de que Keryn finalmente haya encontrado $gun:una; recluta que posiblemente podría tener los ingredientes de $gun:una; $c adecuado. Toma esta espada, $n. Llegará un día en que se te llamará nuevamente para servir al IV:7. Perfecciona tus habilidades, mantén los ojos abiertos y la hoja afilada.$B$BNo nos verás venir pero lo sentirás cuando lleguemos ...', 0),
(@ID, 'esMX', 'Estoy asombrado ... Asombrado de que Keryn finalmente haya encontrado $gun:una; recluta que posiblemente podría tener los ingredientes de $gun:una; $c adecuado. Toma esta espada, $n. Llegará un día en que se te llamará nuevamente para servir al IV:7. Perfecciona tus habilidades, mantén los ojos abiertos y la hoja afilada.$B$BNo nos verás venir pero lo sentirás cuando lleguemos ...', 0);
-- 2360 Mathias y los Defias
-- https://es.classic.wowhead.com/quest=2360
SET @ID := 2360;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mathias finalmente envió a otro agente para respaldarme, ¿eh? Bueno, espero que esté listo para escuchar malas noticias.', 0),
(@ID, 'esMX', 'Mathias finalmente envió a otro agente para respaldarme, ¿eh? Bueno, espero que esté listo para escuchar malas noticias.', 0);
-- 2359 La torre de Klaven
-- https://es.classic.wowhead.com/quest=2359
SET @ID := 2359;
UPDATE `quest_template_locale` SET `Objectives` = 'Roba la Llave de la Torre Defias, entra en la Torre Defias y descubre qué contiene el Cofre del Bosque del Ocaso. Lleva toda la información que encuentres a Mathias Shaw de Ventormenta. Lee el diario de Kearnen para saber cómo acceder a la torre.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna noticia del agente Kearnen?', 0),
(@ID, 'esMX', '¿Alguna noticia del agente Kearnen?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto explicaría los Defias que tú y Kearnen vieron fuera de la torre, $n. También explicaría la participación de Ventura y Cía. con los Defias y los extraños envíos del Bosque del Ocaso.$B$BSegún este libro, los trols Zanzil de Tuercespina han descubierto una forma de resucitar a los muertos mediante pociones... o para ser más específicos: veneno.$B$BNo serás de utilidad para IV:7 sin una comprensión firme de los venenos, $n, especialmente con la receta para crear no-muerte al alcance de la mano.', 0),
(@ID, 'esMX', 'Esto explicaría los Defias que tú y Kearnen vieron fuera de la torre, $n. También explicaría la participación de Ventura y Cía. con los Defias y los extraños envíos del Bosque del Ocaso.$B$BSegún este libro, los trols Zanzil de Tuercespina han descubierto una forma de resucitar a los muertos mediante pociones... o para ser más específicos: veneno.$B$BNo serás de utilidad para IV:7 sin una comprensión firme de los venenos, $n, especialmente con la receta para crear no-muerte al alcance de la mano.', 0);
-- 2607 Toque de Zanzil
-- https://es.classic.wowhead.com/quest=2607
SET @ID := 2607;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya es hora! Simplemente ponga el queso en la mesa y salte. Osborne te pagará a la salida.', 0),
(@ID, 'esMX', '¡Ya es hora! Simplemente ponga el queso en la mesa y salte. Osborne te pagará a la salida.', 0);
-- 7638 Lord Grisillo Quiebrasombras
-- https://es.classic.wowhead.com/quest=7638
SET @ID := 7638;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir tu montura, y ahora ha llegado el momento.$B$BSeguramente serás probado de muchas formas diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!.', 0),
(@ID, 'esMX', 'Me alegro de verte $n. Sé que has esperado noticias sobre cómo adquirir tu montura, y ahora ha llegado el momento.$B$BSeguramente serás probado de muchas formas diferentes, pero lo más importante es tu voluntad de superar los numerosos obstáculos que se te presentan. Estos no se realizan como un ejercicio de aprendizaje: su dificultad va más allá de las simples pruebas educativas. Debes salvar a tu futuro compañero de las garras del mal contra el que te has pasado la vida luchando.$B$B¡Ojo, ha llegado la hora!.', 0);
-- 171 Alcaide de la Alianza
-- https://es.wowhead.com/quest=171
SET @ID := 171;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer volver a verte, $n. ¿Has cumplido las obligaciones con las que te comprometiste al ofrecerte como voluntario para la Semana de los Niños?', 0),
(@ID, 'esMX', 'Es un placer volver a verte, $n. ¿Has cumplido las obligaciones con las que te comprometiste al ofrecerte como voluntario para la Semana de los Niños?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¡Un regalo para todos los huérfanos!$B$BQue los cielos te bendigan, $n. Has hecho más por Randis de lo que nunca hubiera pensado. Gracias, eres una estrella brillante en los cielos de la Alianza.$B$BRandis se ha divertido mucho contigo, $n, y ha querido darte una de sus mascotas favoritas para que no te olvides de él.', 0),
(@ID, 'esMX', '¿Qué es esto? ¡Un regalo para todos los huérfanos!$B$BQue los cielos te bendigan, $n. Has hecho más por Randis de lo que nunca hubiera pensado. Gracias, eres una estrella brillante en los cielos de la Alianza.$B$BRandis se ha divertido mucho contigo, $n, y ha querido darte una de sus mascotas favoritas para que no te olvides de él.', 0);
-- 14180 Llamamiento a las armas: Garganta Grito de Guerra
-- https://es.wowhead.com/quest=14180
SET @ID := 14180;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes del frente, $n?', 0),
(@ID, 'esMX', '¿Qué noticias traes del frente, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. ¡La integridad de nuestras fronteras debe preservarse a toda costa!', 0);
-- 13478 Esfuerzos concertados
-- https://es.wowhead.com/quest=13478
SET @ID := 13478;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal te va en tus viajes, $gchico:chica;?', 0),
(@ID, 'esMX', '¿Qué tal te va en tus viajes, $gchico:chica;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No eres alguien que decepcione, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0),
(@ID, 'esMX', '¡No eres alguien que decepcione, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0);
-- 13427 Llamamiento a las armas: Valle de Alterac
-- https://es.wowhead.com/quest=13427
SET @ID := 13427;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, $n. ¿Qué novedades traes del frente?', 0),
(@ID, 'esMX', 'Dime, $n. ¿Qué novedades traes del frente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0),
(@ID, 'esMX', '¡Justo lo que quería escuchar! Una victoria en el Valle de Alterac, aunque sea temporal, es crucial para nuestra estrategia general contra la Horda.', 0);
-- 1715 El Cordero Degollado
-- https://es.classic.wowhead.com/quest=1715
SET @ID := 1715;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Llavenegra? Esos malditos brujos de Forjaz tienen que organizarse; no hay tantos instructores en Ventormenta. Tanto movimiento acabará por llamar la atención.', 0),
(@ID, 'esMX', '¿Te envía Llavenegra? Esos malditos brujos de Forjaz tienen que organizarse; no hay tantos instructores en Ventormenta. Tanto movimiento acabará por llamar la atención.', 0);
-- 8385 Esfuerzos concertados
-- https://es.classic.wowhead.com/quest=8385
SET @ID := 8385;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n. Espero que sigas aportando tu experiencia a los diferentes frentes de batalla. Muchos de nuestros muchachos y muchachas en el campo admiran a los veteranos experimentados como tú.', 0),
(@ID, 'esMX', 'Ah, $n. Espero que sigas aportando tu experiencia a los diferentes frentes de batalla. Muchos de nuestros muchachos y muchachas en el campo admiran a los veteranos experimentados como tú.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás a la altura de tu reputación, $n. Sin gente como tú, la Alianza no tendría ninguna posibilidad contra las fuerzas salvajes de la Horda.', 0),
(@ID, 'esMX', 'Estás a la altura de tu reputación, $n. Sin gente como tú, la Alianza no tendría ninguna posibilidad contra las fuerzas salvajes de la Horda.', 0);
-- 8897 Queridísima Colara:
-- https://es.classic.wowhead.com/quest=8897
SET @ID := 8897;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola $gguapo:guapa;. ¿Te puedo ayudar en algo?', 0),
(@ID, 'esMX', 'Hola $gguapo:guapa;. ¿Te puedo ayudar en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, es tan dulce! Esta es la primera vez que me envía algo. ¿Crees que se está poniendo serio?$B$BColara Heldric? Supongo que suena... Oh, pero me estoy adelantando. Gracias.', 0),
(@ID, 'esMX', '¡Oh, es tan dulce! Esta es la primera vez que me envía algo. ¿Crees que se está poniendo serio?$B$BColara Heldric? Supongo que suena... Oh, pero me estoy adelantando. Gracias.', 0);
