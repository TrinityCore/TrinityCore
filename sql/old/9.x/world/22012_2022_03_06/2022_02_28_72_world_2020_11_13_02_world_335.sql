-- 4101 Limpiar Frondavil
-- https://es.classic.wowhead.com/quest=4101
SET @ID := 4101;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que Frondavil sufre, $n. ¡Y yo sufro con él! He de ser firme: si el conocimiento que poseo cayera en manos equivocadas, la desgracia caería sobre Frondavil.$B$BTráeme la sangre ámbar de los elementales alabeos muertos y te ganarás mi confianza; te dejaré que me ayudes a combatir la corrupción.', 0),
(@ID, 'esMX', 'Sé que Frondavil sufre, $n. ¡Y yo sufro con él! He de ser firme: si el conocimiento que poseo cayera en manos equivocadas, la desgracia caería sobre Frondavil.$B$BTráeme la sangre ámbar de los elementales alabeos muertos y te ganarás mi confianza; te dejaré que me ayudes a combatir la corrupción.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta sangre ámbar se utilizará para encontrar un medio de acabar con la corrupción de Frondavil. Me has demostrado que estás deseando hacer cualquier cosa por ayudar al Círculo Cenarion. Ahora confío en ti.$B$BPuede parecer extraño que te ganaras mi confianza matando a los elementales, pero cualquier medio está justificado si nos ayuda a lograr un fin mayor: salvar a innumerables seres sensibles. Ahora podemos centrarnos en preservar la vida con los bálsamos que preparo.$B$B$n, ha llegado el momento de limpiar Frondavil.', 0),
(@ID, 'esMX', 'Esta sangre ámbar se utilizará para encontrar un medio de acabar con la corrupción de Frondavil. Me has demostrado que estás deseando hacer cualquier cosa por ayudar al Círculo Cenarion. Ahora confío en ti.$B$BPuede parecer extraño que te ganaras mi confianza matando a los elementales, pero cualquier medio está justificado si nos ayuda a lograr un fin mayor: salvar a innumerables seres sensibles. Ahora podemos centrarnos en preservar la vida con los bálsamos que preparo.$B$B$n, ha llegado el momento de limpiar Frondavil.', 0);
-- 8460 Aliado Fauces de Madera
-- https://es.classic.wowhead.com/quest=8460
SET @ID := 8460;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue así, $n. Si deseas ganarte nuestra confianza, deberás demostrarnos tu valía.', 0),
(@ID, 'esMX', 'Sigue así, $n. Si deseas ganarte nuestra confianza, deberás demostrarnos tu valía.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sufrimos mucho por acontecimientos del pasado. Gracias por lo que has hecho para ayudar a proteger a los Fauces de Madera. Acepta esta humilde ofrenda como símbolo de nuestra creciente amistad.', 0),
(@ID, 'esMX', 'Sufrimos mucho por acontecimientos del pasado. Gracias por lo que has hecho para ayudar a proteger a los Fauces de Madera. Acepta esta humilde ofrenda como símbolo de nuestra creciente amistad.', 0);
-- 8462 Habla con Nafien
-- https://es.classic.wowhead.com/quest=8462
SET @ID := 8462;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah... El viento me ha hecho llegar noticias de quienes no pertenecen a nuestra tribu y quieren aliarse con los fúrbolgs Fauces de Madera. Te doy la bienvenida, pero debo advertirte que mi tribu no reacciona bien frente a los extraños.$B$BEstos son tiempos agobiantes, y solo podemos confiar en quienes deciden combatir la corrupción de la tierra junto a nosotros... y que nos hayan demostrado su valía. Los que no lo hagan no encontrarán más que hostilidad si entran al Bastión.', 0),
(@ID, 'esMX', 'Ah... El viento me ha hecho llegar noticias de quienes no pertenecen a nuestra tribu y quieren aliarse con los fúrbolgs Fauces de Madera. Te doy la bienvenida, pero debo advertirte que mi tribu no reacciona bien frente a los extraños.$B$BEstos son tiempos agobiantes, y solo podemos confiar en quienes deciden combatir la corrupción de la tierra junto a nosotros... y que nos hayan demostrado su valía. Los que no lo hagan no encontrarán más que hostilidad si entran al Bastión.', 0);
-- 8466 Plumas para Grazle
-- https://es.classic.wowhead.com/quest=8466
SET @ID := 8466;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los furbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0),
(@ID, 'esMX', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los furbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0);
-- 4084 Corazón de plata
-- https://es.classic.wowhead.com/quest=4084
SET @ID := 4084;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo decirte más cosas para que logres derrotar a Correfuego, pero primero tienes que recolectar los objetos que te pedí.', 0),
(@ID, 'esMX', 'Puedo decirte más cosas para que logres derrotar a Correfuego, pero primero tienes que recolectar los objetos que te pedí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Parece que te tomas muy en serio el ayudar a tu amigo.', 0),
(@ID, 'esMX', 'Muy bien, $n. Parece que te tomas muy en serio el ayudar a tu amigo.', 0);
-- 4421 La corrupción de los Fuego de Jade
-- https://es.classic.wowhead.com/quest=4421
SET @ID := 4421;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción aquí lleva a las criaturas a la locura...', 0),
(@ID, 'esMX', 'La corrupción aquí lleva a las criaturas a la locura...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Liberar a Frondavil de Xavathras es el primer paso de un largo proceso. Reparar el daño que se ha hecho aquí requerirá mucho trabajo.$B$BPercibo que hay algo más grande actuando aquí... más poderoso que los sátiros. Pero solo el tiempo nos revelará la verdad...', 0),
(@ID, 'esMX', 'Liberar a Frondavil de Xavathras es el primer paso de un largo proceso. Reparar el daño que se ha hecho aquí requerirá mucho trabajo.$B$BPercibo que hay algo más grande actuando aquí... más poderoso que los sátiros. Pero solo el tiempo nos revelará la verdad...', 0);
-- 5156 Investigación acerca de la corrupción
-- https://es.classic.wowhead.com/quest=5156
SET @ID := 5156;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que tu búsqueda salga bien, $n. No he comenzado a dirigirme tan al norte, pero lo admito, la idea de cruzar el camino de un infernal en cualquier momento me asusta un poco. Las criaturas no tienen cerebro, pero siguen siendo bastante intimidantes.', 0),
(@ID, 'esMX', 'Espero que tu búsqueda salga bien, $n. No he comenzado a dirigirme tan al norte, pero lo admito, la idea de cruzar el camino de un infernal en cualquier momento me asusta un poco. Las criaturas no tienen cerebro, pero siguen siendo bastante intimidantes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que sigas con vida, $n. Pero me preocupa que esa agua aún exista. Esperaba encontrar al menos una fuente de agua pura en Frondavil. Pero parece que mi búsqueda ha sido un fracaso. El proceso de curación de la tierra habría sido mucho más sencillo de haber existido tal fuente.$B$BTendré que centrarme en salvar a las criaturas del bosque que aún puedan salvarse mientras destruyo a las que se han corrompido tanto que son un peligro para sí mismas y para los viajeros que atraviesen este bosque que antaño fuera tan poderoso.', 0),
(@ID, 'esMX', 'Me alegra que sigas con vida, $n. Pero me preocupa que esa agua aún exista. Esperaba encontrar al menos una fuente de agua pura en Frondavil. Pero parece que mi búsqueda ha sido un fracaso. El proceso de curación de la tierra habría sido mucho más sencillo de haber existido tal fuente.$B$BTendré que centrarme en salvar a las criaturas del bosque que aún puedan salvarse mientras destruyo a las que se han corrompido tanto que son un peligro para sí mismas y para los viajeros que atraviesen este bosque que antaño fuera tan poderoso.', 0);
-- 5155 Las fuerzas de Jaedenar
-- https://es.classic.wowhead.com/quest=5155
SET @ID := 5155;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu pelea, $n? Sé que el derramamiento de sangre como prueba de honor puede ser repugnante para algunos, pero debes entender que tiene dos objetivos: haces mi tarea más fácil al reducir su número, y nos ganamos un respeto mutuo que solo nos hará más fuertes para los tiempos venideros.$B$BEspero que lo entiendas.', 0),
(@ID, 'esMX', '¿Cómo va tu pelea, $n? Sé que el derramamiento de sangre como prueba de honor puede ser repugnante para algunos, pero debes entender que tiene dos objetivos: haces mi tarea más fácil al reducir su número, y nos ganamos un respeto mutuo que solo nos hará más fuertes para los tiempos venideros.$B$BEspero que lo entiendas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien, $n! Ahora que su número se debilita, podemos presionarles más.$B$B¿Qué tal te supo esa primera cata de su poder? ¿Son tan fuertes como pensaste que serían? ¿Más fuertes? ¿O resultaron no ser un desafío a tu altura? Eso sería fantástico.$B$BPero ya discutiremos los detalles de tus hazañas más tarde. Ahora tenemos que concentrarnos en otras cosas.', 0),
(@ID, 'esMX', '¡Bien, $n! Ahora que su número se debilita, podemos presionarles más.$B$B¿Qué tal te supo esa primera cata de su poder? ¿Son tan fuertes como pensaste que serían? ¿Más fuertes? ¿O resultaron no ser un desafío a tu altura? Eso sería fantástico.$B$BPero ya discutiremos los detalles de tus hazañas más tarde. Ahora tenemos que concentrarnos en otras cosas.', 0);
-- Flor del viento corrupta
-- 996, 998, 4115, 4222, 4467
-- https://es.classic.wowhead.com/quest=996
DELETE FROM `quest_request_items_locale` WHERE `id` IN(996, 998, 4115, 4222, 4467) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(996, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(998, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4115, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4222, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4467, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(996, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(998, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4115, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4222, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4467, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(996, 998, 4115, 4222, 4467) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(996, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(998, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4115, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4222, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4467, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(996, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(998, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4115, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4222, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4467, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0);
-- 8461 Los Muertobosque del Norte
-- https://es.classic.wowhead.com/quest=8461
SET @ID := 8461;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que ganes la confianza de los Fauces de madera, estoy seguro de que podremos hacer algo por ti. Los Fauces de madera no olvidan a sus aliados, especialmente en tiempos oscuros como estos.', 0),
(@ID, 'esMX', 'Una vez que ganes la confianza de los Fauces de madera, estoy seguro de que podremos hacer algo por ti. Los Fauces de madera no olvidan a sus aliados, especialmente en tiempos oscuros como estos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Percibo que has logrado una victoria. Victoria, con lo que has hecho... ¡qué de contradicción puede encerrar una palabra! En cualquier caso, has demostrado que mereces nuestra confianza.$B$BPodría pasar un tiempo antes de que los Fauces de Madera te reciban sin hostilidad en el Bastión. Aún así, tu perseverancia acabará con cualquier sospecha que alberguen mis hermanos. Mientras no nos traiciones y no alces tus armas contra nosotros, nos entenderemos bien.', 0),
(@ID, 'esMX', 'Percibo que has logrado una victoria. Victoria, con lo que has hecho... ¡qué de contradicción puede encerrar una palabra! En cualquier caso, has demostrado que mereces nuestra confianza.$B$BPodría pasar un tiempo antes de que los Fauces de Madera te reciban sin hostilidad en el Bastión. Aún así, tu perseverancia acabará con cualquier sospecha que alberguen mis hermanos. Mientras no nos traiciones y no alces tus armas contra nosotros, nos entenderemos bien.', 0);
-- 8467 Plumas para Nafien
-- https://es.classic.wowhead.com/quest=8467
SET @ID := 8467;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los fúrbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0),
(@ID, 'esMX', 'Aunque a mí ya me has probado tu valía, tendrás que seguir trabajando si quieres ganarte a los recelosos miembros de mi tribu. Quizás yo pueda ayudarte a conseguirlo.$B$BReduce el número de los fúrbolgs Muertobosque y recoge el penacho que llevan algunos. Te servirá como prueba de tu hazaña. Tráeme una pluma de cualquiera de los penachos que consigas; por cada grupo de 5 que me traigas, ganarás reconocimiento entre los Fauces de Madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Me aseguraré de que tus hazañas lleguen a oídos de toda mi tribu.$B$BAcuérdate de traerme cualquiera de las plumas que encuentres. Yo seguiré aceptándolas mientras sea necesario.', 0);
-- 8465 Habla con Salfa
-- https://es.classic.wowhead.com/quest=8465
SET @ID := 8465;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Estoy aquí de guardia, pero también como portavoz de los Fauces de Madera en Cuna del Invierno y como defensor de la tribu.$B$BNuestros hermanos Nevada han sido víctimas de la misma corrupción que los fúrbolgs de Frondavil. Si has venido aquí a ofrecer ayuda a los Fauces de Madera, debo decirte que la aceptaremos.', 0),
(@ID, 'esMX', 'Saludos, $c. Estoy aquí de guardia, pero también como portavoz de los Fauces de Madera en Cuna del Invierno y como defensor de la tribu.$B$BNuestros hermanos Nevada han sido víctimas de la misma corrupción que los fúrbolgs de Frondavil. Si has venido aquí a ofrecer ayuda a los Fauces de Madera, debo decirte que la aceptaremos.', 0);
-- 5157 Una muestra de agua corrupta
-- https://es.classic.wowhead.com/quest=5157
SET @ID := 5157;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tengamos el agua de la Poza de la Luna, la purificaremos y la utilizaremos para extinguir los blandones de protección de la Guarida Sombría. Eso debería darme tiempo suficiente para mirar en las cámaras más profundas y discernir quién lidera este... culto.$B$BRezo para que la Madre Tierra esté con nosotros.', 0),
(@ID, 'esMX', 'Cuando tengamos el agua de la Poza de la Luna, la purificaremos y la utilizaremos para extinguir los blandones de protección de la Guarida Sombría. Eso debería darme tiempo suficiente para mirar en las cámaras más profundas y discernir quién lidera este... culto.$B$BRezo para que la Madre Tierra esté con nosotros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta agua nos servirá, $n.$B$BAhora solo nos queda purificarla antes de utilizarla en los blandones. No debería ser difícil, pero requiere un viajecito.$B$BEspero que podamos hacerlo rápido.', 0),
(@ID, 'esMX', 'Esta agua nos servirá, $n.$B$BAhora solo nos queda purificarla antes de utilizarla en los blandones. No debería ser difícil, pero requiere un viajecito.$B$BEspero que podamos hacerlo rápido.', 0);
-- 4005 Aquamentas
-- https://es.classic.wowhead.com/quest=4005
SET @ID := 4005;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que has vuelto, ¿eh? Ummm... Déjame echar un vistazo a eso, $n.', 0),
(@ID, 'esMX', 'Así que has vuelto, ¿eh? Ummm... Déjame echar un vistazo a eso, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Correfuego, dices...$B$BSí, ese poderoso elemental vive en el tórrido centro del cráter. Procuramos mantenernos alejados, nadie ha podido atravesar la potente aura que le rodea. Muchos han salido volando montaña abajo al intentar acercarse a él.', 0),
(@ID, 'esMX', 'Correfuego, dices...$B$BSí, ese poderoso elemental vive en el tórrido centro del cráter. Procuramos mantenernos alejados, nadie ha podido atravesar la potente aura que le rodea. Muchos han salido volando montaña abajo al intentar acercarse a él.', 0);
-- 4906 Más corrupción
-- https://es.classic.wowhead.com/quest=4906
SET @ID := 4906;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor, pon fin al sufrimiento de las criaturas de Frondavil.', 0),
(@ID, 'esMX', 'Por favor, pon fin al sufrimiento de las criaturas de Frondavil.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por todo lo que has hecho, $n. Que Elune te proteja y te guíe en tu camino.', 0),
(@ID, 'esMX', 'Gracias por todo lo que has hecho, $n. Que Elune te proteja y te guíe en tu camino.', 0);
-- Bálsamo por caza
-- 4103, 4108, 5882, 5887
-- https://es.classic.wowhead.com/quest=4103
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4103, 4108, 5882, 5887) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4103, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(4108, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5882, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5887, 'esES', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(4103, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(4108, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5882, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0),
(5887, 'esMX', 'Una antorcha Cenarion te permite ver un fragmento de alma corrupto en esas bestias corruptas que deben ser sacrificadas por un bien mayor. Yo pulverizo los fragmentos y los convierto en un componente con el que se crea el bálsamo de planta de Cenarion. Y es lo que utilizaremos para sanar a las plantas corruptas.$B$BA cambio de esos fragmentos, te daré algunos bálsamos de planta de Cenarion que ya tengo preparados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4103, 4108, 5882, 5887) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4103, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(4108, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5882, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5887, 'esES', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(4103, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(4108, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5882, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0),
(5887, 'esMX', 'Muy bien. Aquí están tus bálsamos de planta de Cenarion. ¡Explora Frondavil y busca plantas corruptas, $n! Estén donde estén, utiliza el bálsamo que te he dado para purificarlas.', 0);
-- Bálsamo por desencantamiento
-- 4107, 4112, 5886, 5891
-- https://es.classic.wowhead.com/quest=4107
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4107, 4112, 5886, 5891) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4107, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(4112, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5886, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5891, 'esES', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(4107, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(4112, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5886, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0),
(5891, 'esMX', 'El poder de un objeto mágico desencantado se siente por la esencia que crea. He ideado una forma de convertir la esencia cruda utilizada por los encantadores en un reactivo adecuado para crear un bálsamo de planta Cenarion. No necesitas una baliza Cenarion para esto; cualquier elemento adecuadamente desencantado que produzca esencias inferiores menores funcionará.$B$BSolo necesito una única esencia inferior menor; a cambio, te daré ungüentos de planta Cenarion. La esencia es extremadamente potente, ¡definitivamente, un poco rinde mucho!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4107, 4112, 5886, 5891) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4107, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(4112, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5886, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5891, 'esES', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(4107, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(4112, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5886, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0),
(5891, 'esMX', 'Aquí hay algunos ungüentos de plantas Cenarion: solo necesito una esencia inferior menor para esto, $n. La esencia es, con mucho, el elemento más potente que puedo utilizar para convertir espadas en arados, por así decirlo. Si necesitas más bálsamo, ¡búscame aquí!', 0);
