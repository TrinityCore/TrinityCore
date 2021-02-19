-- 1135 Veneno de Nido Alto
-- https://es.classic.wowhead.com/quest=1135
SET @ID := 1135;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste Nido Alto, $n? ¿Qué tal te fue con los dracoleones que allí habitan?', 0),
(@ID, 'esMX', '¿Encontraste Nido Alto, $n? ¿Qué tal te fue con los dracoleones que allí habitan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, la mayor parte de ellas están cargadísimas de veneno, $n. Las glándulas como estas se suelen obtener de dracoleones jóvenes o de hembras fértiles. ¡Tuvo que haber sido una auténtica matanza en Nido Alto!', 0),
(@ID, 'esMX', 'Vaya, la mayor parte de ellas están cargadísimas de veneno, $n. Las glándulas como estas se suelen obtener de dracoleones jóvenes o de hembras fértiles. ¡Tuvo que haber sido una auténtica matanza en Nido Alto!', 0);
-- 1136 Faucehielo
-- https://es.classic.wowhead.com/quest=1136
SET @ID := 1136;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en las Montañas de Alterac, $n? ¿Te has enfrentado al escurridizo Faucehielo?', 0),
(@ID, 'esMX', '¿Has estado en las Montañas de Alterac, $n? ¿Te has enfrentado al escurridizo Faucehielo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hacía falta fuerza y astucia para encontrar a Faucehielo y derrotarlo, $n. Y tienes ambas.$B$BTu camino te ha llevado al valle de Las Mil Agujas y a Altomonte en Alterac. Un día te conducirá por todas las tierras de la Madre Tierra, porque tal es el camino del cazador.', 0),
(@ID, 'esMX', 'Hacía falta fuerza y astucia para encontrar a Faucehielo y derrotarlo, $n. Y tienes ambas.$B$BTu camino te ha llevado al valle de Las Mil Agujas y a Altomonte en Alterac. Un día te conducirá por todas las tierras de la Madre Tierra, porque tal es el camino del cazador.', 0);
-- 1140 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=1140
SET @ID := 1140;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Libera el alma altonato en la Senda de la Noche', `ObjectiveText2` = 'Libera el alma altonato en Satyrnaar', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 1142 Decaída mortal
-- https://es.classic.wowhead.com/quest=1142
SET @ID := 1142;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae por aquí, $r?', 0),
(@ID, 'esMX', '¿Qué te trae por aquí, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No!$B$B¡Oh, mundo cruel!$B$BAhora debo llevar el peso de mi pena y no dejar que el trabajo de Heralath muera con él.$B$BAgradezco tu valentía, $n, pero déjame ahora, por favor.$B$BQuiero llorar a solas.', 0),
(@ID, 'esMX', '¡No!$B$B¡Oh, mundo cruel!$B$BAhora debo llevar el peso de mi pena y no dejar que el trabajo de Heralath muera con él.$B$BAgradezco tu valentía, $n, pero déjame ahora, por favor.$B$BQuiero llorar a solas.', 0);
-- 1144 Willix el Importador
-- https://es.classic.wowhead.com/quest=1144
SET @ID := 1144;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias otra vez! Y ahora, la recompensa prometida.', 0),
(@ID, 'esMX', '¡Gracias otra vez! Y ahora, la recompensa prometida.', 0);
-- 1145 El enjambre crece
-- https://es.classic.wowhead.com/quest=1145
SET @ID := 1145;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te envidio, $c. Tu cara es la de alguien que ha visto mundo más allá de Orgrimmar.$B$BYo también viajaría en nombre del Jefe de Guerra si Thrall no precisara de mis habilidades en la ciudad. Pero es un buen líder y yo confío en su criterio, así que me quedaré aquí mientras me necesite.', 0),
(@ID, 'esMX', 'Te envidio, $c. Tu cara es la de alguien que ha visto mundo más allá de Orgrimmar.$B$BYo también viajaría en nombre del Jefe de Guerra si Thrall no precisara de mis habilidades en la ciudad. Pero es un buen líder y yo confío en su criterio, así que me quedaré aquí mientras me necesite.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, una nota de parte de Korran. Es un fiel servidor, desde hace ya algún tiempo. Me pregunto qué tal irán las cosas por El Cruce…', 0),
(@ID, 'esMX', 'Ah, una nota de parte de Korran. Es un fiel servidor, desde hace ya algún tiempo. Me pregunto qué tal irán las cosas por El Cruce…', 0);
-- 1146 El enjambre crece
-- https://es.classic.wowhead.com/quest=1146
SET @ID := 1146;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La guerra nos ha traído a mis hombres y a mí a El Desierto de Sal, $c. ¿Qué te trae a ti aquí?', 0),
(@ID, 'esMX', 'La guerra nos ha traído a mis hombres y a mí a El Desierto de Sal, $c. ¿Qué te trae a ti aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No hagas caso de los estruendos que retumban en las montañas. Los goblins y los gnomos están en El Desierto de Sal haciendo carreras con unas atrocidades creadas en nombre de lo que ellos denominan ciencia. Pero hay amenazas más importantes aquí en Las Mil Agujas, y una de ellas es la que acabó con más de la mitad de mi destacamento.$B$BAun así, nos quedaremos aquí hasta recibir noticias de Belgrom, que está en Orgrimmar. Hasta entonces, mantendremos nuestra posición sin bajar la guardia.', 0),
(@ID, 'esMX', 'No hagas caso de los estruendos que retumban en las montañas. Los goblins y los gnomos están en El Desierto de Sal haciendo carreras con unas atrocidades creadas en nombre de lo que ellos denominan ciencia. Pero hay amenazas más importantes aquí en Las Mil Agujas, y una de ellas es la que acabó con más de la mitad de mi destacamento.$B$BAun así, nos quedaremos aquí hasta recibir noticias de Belgrom, que está en Orgrimmar. Hasta entonces, mantendremos nuestra posición sin bajar la guardia.', 0);
-- 1147 El enjambre crece
-- https://es.classic.wowhead.com/quest=1147
SET @ID := 1147;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la cantidad de viajeros que se dirigen al Desierto de Sal para esas carreras, estoy seguro de que podemos convencer a suficientes buscadores de aventuras para que ayuden a hacer retroceder a esos insectos. Mi grupo y yo no podremos irnos hasta que lo hagamos.', 0),
(@ID, 'esMX', 'Con la cantidad de viajeros que se dirigen al Desierto de Sal para esas carreras, estoy seguro de que podemos convencer a suficientes buscadores de aventuras para que ayuden a hacer retroceder a esos insectos. Mi grupo y yo no podremos irnos hasta que lo hagamos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! ¡El icor te favorece mucho, $n! Si bien es cierto que apesta... Te recomendaría que no te acercases demasiado a los kodos, no vaya a ser que provoques una estampida o, lo que es peor, que se pongan en celo.$B$BCreo que todos estamos de acuerdo en que tu olor apestoso demuestra que efectivamente has combatido contra esos insectos. Gracias, $n.', 0),
(@ID, 'esMX', '¡Ja! ¡El icor te favorece mucho, $n! Si bien es cierto que apesta... Te recomendaría que no te acercases demasiado a los kodos, no vaya a ser que provoques una estampida o, lo que es peor, que se pongan en celo.$B$BCreo que todos estamos de acuerdo en que tu olor apestoso demuestra que efectivamente has combatido contra esos insectos. Gracias, $n.', 0);
-- 1148 Pedazos del enjambre
-- https://es.classic.wowhead.com/quest=1148
SET @ID := 1148;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, hacía tiempo que no venías a verme, $n. ¿Qué puedo hacer por ti? Tienes cara de haber combatido hace poco. Eso es bueno... para la Horda y para ti. Cuantas más batallas libres, más útil y más fuerte serás.', 0),
(@ID, 'esMX', 'Ah, hacía tiempo que no venías a verme, $n. ¿Qué puedo hacer por ti? Tienes cara de haber combatido hace poco. Eso es bueno... para la Horda y para ti. Cuantas más batallas libres, más útil y más fuerte serás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a Moktar recientemente? Él siempre me anda buscando. Siento que tenga que perder el tiempo velando por su pequeño escuadrón de combate en lugar de centrarse en la batalla pero estoy seguro de que se lo pasa bien matando a los miembros de la Liga de Expedicionarios.$B$BHas hecho bien en traerme estos especímenes, $n. Con esto y los huevos que encontremos en la Tierra de Gigantes, podré empezar a hacerme una idea de qué son estos insectos y qué andan buscando.', 0),
(@ID, 'esMX', '¿Has visto a Moktar recientemente? Él siempre me anda buscando. Siento que tenga que perder el tiempo velando por su pequeño escuadrón de combate en lugar de centrarse en la batalla pero estoy seguro de que se lo pasa bien matando a los miembros de la Liga de Expedicionarios.$B$BHas hecho bien en traerme estos especímenes, $n. Con esto y los huevos que encontremos en la Tierra de Gigantes, podré empezar a hacerme una idea de qué son estos insectos y qué andan buscando.', 0);
-- 1149 Prueba de fe
-- https://es.classic.wowhead.com/quest=1149
SET @ID := 1149;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La fe es mucho más importante de lo que algunos piensan.$B$BMuchas veces lo importante no es en qué creas, sino que creas en algo.', 0),
(@ID, 'esMX', 'La fe es mucho más importante de lo que algunos piensan.$B$BMuchas veces lo importante no es en qué creas, sino que creas en algo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hasta que no nos enfrentamos a la adversidad, no sabemos lo fuerte que es nuestro espíritu. Diste el salto de fe, incluso sin saber si sobrevivirías. Tu mente está abierta y tu espíritu preparado para lo que venga.$B$BSi lo deseas, puedes pasar a la siguiente prueba.', 0),
(@ID, 'esMX', 'Hasta que no nos enfrentamos a la adversidad, no sabemos lo fuerte que es nuestro espíritu. Diste el salto de fe, incluso sin saber si sobrevivirías. Tu mente está abierta y tu espíritu preparado para lo que venga.$B$BSi lo deseas, puedes pasar a la siguiente prueba.', 0);
 -- 1150 Prueba de resistencia
-- https://es.classic.wowhead.com/quest=1150
SET @ID := 1150;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes estar preparado espiritual, física y mentalmente para los desafíos que tienes por delante.$B$BMuchas veces, queremos avanzar sin estar preparados. Mi obligación con los jóvenes, sean de la tribu que sean, es prepararlos para enfrentarse a los peligros con los que se puedan topar cuando abandonen el calor del hogar.', 0),
(@ID, 'esMX', 'Debes estar preparado espiritual, física y mentalmente para los desafíos que tienes por delante.$B$BMuchas veces, queremos avanzar sin estar preparados. Mi obligación con los jóvenes, sean de la tribu que sean, es prepararlos para enfrentarse a los peligros con los que se puedan topar cuando abandonen el calor del hogar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Grenka era muy poderoso. Para ser $gun:una; $r debes sentirte $gorgulloso:orgullosa; de lo que has logrado hoy.$B$BDurante tu prueba de fe, demostraste poseer gran fuerza de espíritu y, al acabar con las arpías Malapluma, has demostrado tener gran resistencia en combate. Ha llegado la hora de que afrontes una nueva prueba.', 0),
(@ID, 'esMX', 'Grenka era muy poderoso. Para ser $gun:una; $r debes sentirte $gorgulloso:orgullosa; de lo que has logrado hoy.$B$BDurante tu prueba de fe, demostraste poseer gran fuerza de espíritu y, al acabar con las arpías Malapluma, has demostrado tener gran resistencia en combate. Ha llegado la hora de que afrontes una nueva prueba.', 0);
-- 1151 Prueba de fuerza
-- https://es.classic.wowhead.com/quest=1151
SET @ID := 1151;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las tribus de centauros de Las Mil Agujas denominan a Rok\'Alim el Aporreador debido a la fuerza con la que sus puños golpean a las criaturas lo suficientemente valientes o demasiado insensatas como para cruzarse en su camino.', 0),
(@ID, 'esMX', 'Las tribus de centauros de Las Mil Agujas denominan a Rok\'Alim el Aporreador debido a la fuerza con la que sus puños golpean a las criaturas lo suficientemente valientes o demasiado insensatas como para cruzarse en su camino.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La prueba de fuerza ha concluido. Has demostrado ser fuerte y valiente, y ahora estás preparado para la prueba final.', 0),
(@ID, 'esMX', 'La prueba de fuerza ha concluido. Has demostrado ser fuerte y valiente, y ahora estás preparado para la prueba final.', 0);
-- 1152 Prueba de conocimiento
-- https://es.classic.wowhead.com/quest=1152
SET @ID := 1152;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El desasosiego crece en este mundo a medida que los goblins expolian la tierra y los elfos de la noche ponen el punto de mira en las razas más jóvenes. Los Renegados y los orcos no son los únicos culpables de las penurias sufridas por Kalimdor y Lordaeron. Muchas de las razas inteligentes han contribuido al malestar que reina en el mundo. Dorn lo sabe y te ha enviado a verme porque has demostrado ser capaz de entender la situación.$B$BTe encuentras ante Braug.', 0),
(@ID, 'esMX', 'El desasosiego crece en este mundo a medida que los goblins expolian la tierra y los elfos de la noche ponen el punto de mira en las razas más jóvenes. Los Renegados y los orcos no son los únicos culpables de las penurias sufridas por Kalimdor y Lordaeron. Muchas de las razas inteligentes han contribuido al malestar que reina en el mundo. Dorn lo sabe y te ha enviado a verme porque has demostrado ser capaz de entender la situación.$B$BTe encuentras ante Braug.', 0);
-- 1153 Una nueva muestra de mineral
-- https://es.classic.wowhead.com/quest=1153
SET @ID := 1153;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He vuelto a ver a los viajeros, los que no me quieren vender la muestra de ese mineral. Les escupí por no colaborar con el Jefe de Guerra.$B$BDeben morir en la batalla como cobardes y no como guerreros como corresponde a aquellos que están de parte de la Horda.', 0),
(@ID, 'esMX', 'He vuelto a ver a los viajeros, los que no me quieren vender la muestra de ese mineral. Les escupí por no colaborar con el Jefe de Guerra.$B$BDeben morir en la batalla como cobardes y no como guerreros como corresponde a aquellos que están de parte de la Horda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buena muestra, $n. Muy buena muestra...$B$BEsos viajeros ya no podrán restregarme por la cara el mineral que encontraron.$B$BHe de ponerme manos a la obra de inmediato. Si resulta ser lo suficientemente resistente, enviaré un arma fabricada a partir de este material al Jefe de Guerra como prueba de nuestro éxito.$B$BNunca olvidaré lo que has hecho por mí, $c.', 0),
(@ID, 'esMX', 'Buena muestra, $n. Muy buena muestra...$B$BEsos viajeros ya no podrán restregarme por la cara el mineral que encontraron.$B$BHe de ponerme manos a la obra de inmediato. Si resulta ser lo suficientemente resistente, enviaré un arma fabricada a partir de este material al Jefe de Guerra como prueba de nuestro éxito.$B$BNunca olvidaré lo que has hecho por mí, $c.', 0);
-- 1154 Prueba de conocimiento
-- https://es.classic.wowhead.com/quest=1154
SET @ID := 1154;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tráeme el libro que has estudiado. No te haré la pregunta hasta que me lo hayas entregado.', 0),
(@ID, 'esMX', 'Tráeme el libro que has estudiado. No te haré la pregunta hasta que me lo hayas entregado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ese el libro que te pedí. Podrás responder mi pregunta correctamente... a no ser que te hayas olvidado de estudiar su contenido.$B$BCuando estés preparado, ven a hablar conmigo y te plantearé la pregunta.', 0),
(@ID, 'esMX', 'Ese el libro que te pedí. Podrás responder mi pregunta correctamente... a no ser que te hayas olvidado de estudiar su contenido.$B$BCuando estés preparado, ven a hablar conmigo y te plantearé la pregunta.', 0);
-- 1159 Prueba de conocimiento
-- https://es.classic.wowhead.com/quest=1159
SET @ID := 1159;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Braug? No es posible...$B$B<Parqual te mira de arriba abajo.>$B$B¿Estuviste en Dor\'danil, diste el salto de fe y luchaste y derrotaste a un poderoso elemental? ¡Bah! Seguro que eres un impostor. Alguien que escuchó una conversación en alguna taberna y cree estar preparado para superar mi prueba. Ya lo veremos... $c.', 0),
(@ID, 'esMX', '¿Te envía Braug? No es posible...$B$B<Parqual te mira de arriba abajo.>$B$B¿Estuviste en Dor\'danil, diste el salto de fe y luchaste y derrotaste a un poderoso elemental? ¡Bah! Seguro que eres un impostor. Alguien que escuchó una conversación en alguna taberna y cree estar preparado para superar mi prueba. Ya lo veremos... $c.', 0);
-- 1160 Prueba de conocimiento
-- https://es.classic.wowhead.com/quest=1160
SET @ID := 1160;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas hecho sufrir un poco a la Cruzada Escarlata antes de robarle el libro.$B$BMi opinión sobre sus integrantes está más que justificada. En su día fueron seguidores de la Luz pero ahora persiguen destruir a toda criatura que no esté de acuerdo con su religión. Creen que los no-muertos, Renegados o no, deben ser aniquilados y que todo el que viaje por sus tierras o está loco o sujeto a la poderosa magia de los no-muertos. ¡Insensatos! Son todos unos insensatos y unos ignorantes.', 0),
(@ID, 'esMX', 'Espero que hayas hecho sufrir un poco a la Cruzada Escarlata antes de robarle el libro.$B$BMi opinión sobre sus integrantes está más que justificada. En su día fueron seguidores de la Luz pero ahora persiguen destruir a toda criatura que no esté de acuerdo con su religión. Creen que los no-muertos, Renegados o no, deben ser aniquilados y que todo el que viaje por sus tierras o está loco o sujeto a la poderosa magia de los no-muertos. ¡Insensatos! Son todos unos insensatos y unos ignorantes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es el libro que te pedí que buscaras.$B$B<Parqual acaricia con cuidado la tapa del libro mientras lo observa fijamente.>$B$BAsí que ahora quieres que te haga una pregunta para demostrar que tu mente es tan poderosa como tu cuerpo y tu espíritu. Si has estudiado el libro lo suficiente, procederé a plantearte la pregunta y habrás acabado las pruebas.', 0),
(@ID, 'esMX', 'Este es el libro que te pedí que buscaras.$B$B<Parqual acaricia con cuidado la tapa del libro mientras lo observa fijamente.>$B$BAsí que ahora quieres que te haga una pregunta para demostrar que tu mente es tan poderosa como tu cuerpo y tu espíritu. Si has estudiado el libro lo suficiente, procederé a plantearte la pregunta y habrás acabado las pruebas.', 0);
-- 1164 Robar a un ladrón...
-- https://es.classic.wowhead.com/quest=1164
SET @ID := 1164;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mátalos y tráeme sus cabezas!', 0),
(@ID, 'esMX', '¡Mátalos y tráeme sus cabezas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has cumplido mi venganza y me inclino ante ti en agradecimiento.$B$BAhora que están todos muertos y que se ha acabado su progenie en Azeroth, puedo concentrar mis energías en algo más lucrativo. Espero que hayas saqueado su granja tras haberles dado muerte.', 0),
(@ID, 'esMX', 'Has cumplido mi venganza y me inclino ante ti en agradecimiento.$B$BAhora que están todos muertos y que se ha acabado su progenie en Azeroth, puedo concentrar mis energías en algo más lucrativo. Espero que hayas saqueado su granja tras haberles dado muerte.', 0);
-- 1166 Las pertenencias del señor supremo Mok'Morokk
-- https://es.classic.wowhead.com/quest=1166
SET @ID := 1166;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo sed. Quiero grog. Y tabaco. ¿Dónde está mi caja fuerte? Tú vas a buscarlos para Señor Supremo Mok\'Morokk.$B$BVe al sur, a casa vieja. Yo estoy muy ocupado mandando a ogros.', 0),
(@ID, 'esMX', 'Tengo sed. Quiero grog. Y tabaco. ¿Dónde está mi caja fuerte? Tú vas a buscarlos para Señor Supremo Mok\'Morokk.$B$BVe al sur, a casa vieja. Yo estoy muy ocupado mandando a ogros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú buen $r. Yo echo de menos mis cosas. Mucho. Ahora me gustas.', 0),
(@ID, 'esMX', 'Tú buen $r. Yo echo de menos mis cosas. Mucho. Ahora me gustas.', 0);
-- 1168 El ejército de los dragones Negros
-- https://es.classic.wowhead.com/quest=1168
SET @ID := 1168;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mok\'Morokk les dice a todos ogros que se queden y mantengan lugar seguro. Creo que ogros necesitan matar al ejército de dragones negros y volver a casa.$B$BAyudar a ogros a volver a casa. Ayudar a ogros a vengarse.', 0),
(@ID, 'esMX', 'Mok\'Morokk les dice a todos ogros que se queden y mantengan lugar seguro. Creo que ogros necesitan matar al ejército de dragones negros y volver a casa.$B$BAyudar a ogros a volver a casa. Ayudar a ogros a vengarse.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú matar a muchos del ejército de dragones negros. Tú valiente $r.$B$BPoner a Tharg contento.', 0),
(@ID, 'esMX', 'Tú matar a muchos del ejército de dragones negros. Tú valiente $r.$B$BPoner a Tharg contento.', 0);
-- 1169 Identifica a los cachorros
-- https://es.classic.wowhead.com/quest=1169
SET @ID := 1169;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con los corazones y las lenguas de las crías chamuscadas del ejército de los dragones negros, podré averiguar qué bestia introdujo a su prole en nuestra casa. Si reunimos información sobre nuestros agresores, quizás podamos destruirlos de una vez para siempre y rescatar de la ruina al poblado Quebrantarrocas.$B$BPor supuesto, conseguir que Mok\'Morokk arrastre su letárgica mole de ese agujero de estiércol, va a ser toda una odisea...', 0),
(@ID, 'esMX', 'Con los corazones y las lenguas de las crías chamuscadas del ejército de los dragones negros, podré averiguar qué bestia introdujo a su prole en nuestra casa. Si reunimos información sobre nuestros agresores, quizás podamos destruirlos de una vez para siempre y rescatar de la ruina al poblado Quebrantarrocas.$B$BPor supuesto, conseguir que Mok\'Morokk arrastre su letárgica mole de ese agujero de estiércol, va a ser toda una odisea...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debió de ser peligroso eso de reunir tantos corazones y lenguas. Me sumergiré en las profundidades de lo Arcano para rastrear el origen de esa negra amenaza que se ha cernido sobre nuestro antiguo hogar.', 0),
(@ID, 'esMX', 'Debió de ser peligroso eso de reunir tantos corazones y lenguas. Me sumergiré en las profundidades de lo Arcano para rastrear el origen de esa negra amenaza que se ha cernido sobre nuestro antiguo hogar.', 0);
-- 1170 El linaje de Onyxia
-- https://es.classic.wowhead.com/quest=1170
SET @ID := 1170;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué hablar de dragones? No me gustan. A mí me gusta esto. Aquí no dragones.', 0),
(@ID, 'esMX', '¿Por qué hablar de dragones? No me gustan. A mí me gusta esto. Aquí no dragones.', 0);
-- 1171 El linaje de Onyxia
-- https://es.classic.wowhead.com/quest=1171
SET @ID := 1171;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ese vago cobarde!$B$BMok\'Morokk demostró ser fuerte cuando Rexxar era nuestro líder. Pero en cuanto Rexxar partió, Mok\'Morokk cayó presa de una insaciable ansia de poder. En lugar de liderar, exige. Ya no sirve a su gente, ahora espera que nosotros le sirvamos a él.$B$BHay que hacer algo al respecto.', 0),
(@ID, 'esMX', '¡Ese vago cobarde!$B$BMok\'Morokk demostró ser fuerte cuando Rexxar era nuestro líder. Pero en cuanto Rexxar partió, Mok\'Morokk cayó presa de una insaciable ansia de poder. En lugar de liderar, exige. Ya no sirve a su gente, ahora espera que nosotros le sirvamos a él.$B$BHay que hacer algo al respecto.', 0);
-- 1172 El linaje de Onyxia
-- https://es.classic.wowhead.com/quest=1172
SET @ID := 1172;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'El huevo de Onyxia ha sido destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes apresurarte hacia el Pantano del Dragón, $n. Con los huevos de Onyxia repartidos por la Ciénaga de Fuego, nos enfrentamos a números abrumadores a menos que se haga algo rápidamente.$B$B¡Destruye sus huevos! ¡No dejes que la plaga del dragón negro se extienda por nuestro hogar!', 0),
(@ID, 'esMX', 'Debes apresurarte hacia el Pantano del Dragón, $n. Con los huevos de Onyxia repartidos por la Ciénaga de Fuego, nos enfrentamos a números abrumadores a menos que se haga algo rápidamente.$B$B¡Destruye sus huevos! ¡No dejes que la plaga del dragón negro se extienda por nuestro hogar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espléndido! Pasará algún tiempo hasta que Onyxia pueda poner más huevos.$B$BTe doy las gracias de parte de mi gente, $n.$B$BSoy consciente de que ya te he pedido mucho. Pero quizás quieras hacer un último servicio al clan Quebrantarrocas.$B$BMok\'Morokk no puede ser nuestro líder. Tharg sería un guía excelente, pero está entorpecido por sus heridas y su edad. Expulsa a Mok\'Morokk de este lugar por la fuerza. Solo entonces podremos proclamar un nuevo líder que nos lleve de regreso al sur, a nuestro verdadero hogar.', 0),
(@ID, 'esMX', '¡Espléndido! Pasará algún tiempo hasta que Onyxia pueda poner más huevos.$B$BTe doy las gracias de parte de mi gente, $n.$B$BSoy consciente de que ya te he pedido mucho. Pero quizás quieras hacer un último servicio al clan Quebrantarrocas.$B$BMok\'Morokk no puede ser nuestro líder. Tharg sería un guía excelente, pero está entorpecido por sus heridas y su edad. Expulsa a Mok\'Morokk de este lugar por la fuerza. Solo entonces podremos proclamar un nuevo líder que nos lleve de regreso al sur, a nuestro verdadero hogar.', 0);
-- 1173 Desafiar al señor supremo Mok'Morokk
-- https://es.classic.wowhead.com/quest=1173
SET @ID := 1173;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pensé que ibas a intentar expulsar a Mok\'Morokk del pueblo. ¿En cambio has venido a mí para charlar?', 0),
(@ID, 'esMX', 'Pensé que ibas a intentar expulsar a Mok\'Morokk del pueblo. ¿En cambio has venido a mí para charlar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esa mole cobarde de Mok\'Morokk huyó como un niño asustado. Nos has hecho un gran servicio, $n.$B$BAhora mi gente puede proclamar un nuevo líder, uno que nos ayudará a reclamar nuestro antiguo hogar.', 0),
(@ID, 'esMX', 'Esa mole cobarde de Mok\'Morokk huyó como un niño asustado. Nos has hecho un gran servicio, $n.$B$BAhora mi gente puede proclamar un nuevo líder, uno que nos ayudará a reclamar nuestro antiguo hogar.', 0);
-- 1177 ¡Qué hambre!
-- https://es.classic.wowhead.com/quest=1177
SET @ID := 1177;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Da comida o yo me como a ti.', 0),
(@ID, 'esMX', 'Da comida o yo me como a ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡A mí gusta cabeza de pez!$B$BYo no me como a ti ya.', 0),
(@ID, 'esMX', '¡A mí gusta cabeza de pez!$B$BYo no me como a ti ya.', 0);
-- 1184 Pedazos del enjambre
-- https://es.classic.wowhead.com/quest=1184
SET @ID := 1184;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Agradezco tus esfuerzos, $c. El Jefe de Guerra se alegrará de ver la tenacidad con la que has cumplido tus obligaciones.$B$BPor supuesto, le hablaré bien de ti. Él habla conmigo a menudo y valora mucho mis opiniones.$B$BAhora vete, tengo mucho que hacer. Si hablas con Korran y tiene alguna novedad acerca de estas criaturas, entonces ven a verme de nuevo. De ser así, tendría que empezar a pensar que son una seria amenaza que hay que detener.', 0),
(@ID, 'esMX', 'Agradezco tus esfuerzos, $c. El Jefe de Guerra se alegrará de ver la tenacidad con la que has cumplido tus obligaciones.$B$BPor supuesto, le hablaré bien de ti. Él habla conmigo a menudo y valora mucho mis opiniones.$B$BAhora vete, tengo mucho que hacer. Si hablas con Korran y tiene alguna novedad acerca de estas criaturas, entonces ven a verme de nuevo. De ser así, tendría que empezar a pensar que son una seria amenaza que hay que detener.', 0);
-- 1185 Debajo de la quitina había...
-- https://es.classic.wowhead.com/quest=1185
SET @ID := 1185;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Anda, si eres tú! ¡O sea, $n!$B$BMe alegro de verte.$B$BEl libro que encontraste en Silithus es un diario escrito en un antiguo dialecto. Voy a estudiarlo a fondo. Pensé que te gustaría saber que es muy valioso.$B$B¡Tienes la gratitud del Círculo!', 0),
(@ID, 'esMX', '¡Anda, si eres tú! ¡O sea, $n!$B$BMe alegro de verte.$B$BEl libro que encontraste en Silithus es un diario escrito en un antiguo dialecto. Voy a estudiarlo a fondo. Pensé que te gustaría saber que es muy valioso.$B$B¡Tienes la gratitud del Círculo!', 0);
-- 1193 Una trampa rota
-- https://es.classic.wowhead.com/quest=1193
SET @ID := 1193;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes ante ti una gran trampa rota. Parece que los ogros han intentado reparar la trampa, pero sin éxito. Al lado de la trampa hay una nota escrita a toda prisa. Lo curioso es que describe exactamente lo que se necesita para reparar la trampa: 1 trasto wow de torio y un poco de aceite de escarcha. Si se reparara la trampa, cualquier ogro que pasara por aquí podría caer en ella... uno menos.$B$BEvidentemente, el hecho de que sean pocos los ogros que saben leer, podría parecer un hecho fortuito.$B$BPodría parecerlo...', 0),
(@ID, 'esMX', 'Tienes ante ti una gran trampa rota. Parece que los ogros han intentado reparar la trampa, pero sin éxito. Al lado de la trampa hay una nota escrita a toda prisa. Lo curioso es que describe exactamente lo que se necesita para reparar la trampa: 1 trasto wow de torio y un poco de aceite de escarcha. Si se reparara la trampa, cualquier ogro que pasara por aquí podría caer en ella... uno menos.$B$BEvidentemente, el hecho de que sean pocos los ogros que saben leer, podría parecer un hecho fortuito.$B$BPodría parecerlo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El trasto wow de torio se desliza a su sitio sin esfuerzo, creando un conducto para verter el aceite de escarcha. Cuando se ha vertido la última gota de aceite, la trampa se coloca en posición.$B$B¡Pobre del ogro despistado que pase por aquí!', 0),
(@ID, 'esMX', 'El trasto wow de torio se desliza a su sitio sin esfuerzo, creando un conducto para verter el aceite de escarcha. Cuando se ha vertido la última gota de aceite, la trampa se coloca en posición.$B$B¡Pobre del ogro despistado que pase por aquí!', 0);
-- 1195 La llama sacra
-- https://es.classic.wowhead.com/quest=1195
SET @ID := 1195;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tengamos la ampolla llena, se la podremos enviar a mi socio Rau, que está en Las Mil Agujas. Él es quien pidió la ampolla de agua así que sabrá mejor qué hacer con ella.', 0),
(@ID, 'esMX', 'Cuando tengamos la ampolla llena, se la podremos enviar a mi socio Rau, que está en Las Mil Agujas. Él es quien pidió la ampolla de agua así que sabrá mejor qué hacer con ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, es justo lo que Rau quería. ¿No podrías llevársela? Seguro que te apetece pasar un tiempo en Las Mil Agujas.', 0),
(@ID, 'esMX', 'Muy bien, es justo lo que Rau quería. ¿No podrías llevársela? Seguro que te apetece pasar un tiempo en Las Mil Agujas.', 0);
-- 1196 La llama sacra
-- https://es.classic.wowhead.com/quest=1196
SET @ID := 1196;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por casualidad no te enviará Zangen, ¿no?', 0),
(@ID, 'esMX', 'Por casualidad no te enviará Zangen, ¿no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, esta ampolla de agua servirá a nuestros propósitos. Debido a la ascendencia común de los dríades y los centauros, con el agua de las pozas de la luna podremos romper la protección de la llama eterna que rodea la reliquia de los centauros.', 0),
(@ID, 'esMX', 'Sí, esta ampolla de agua servirá a nuestros propósitos. Debido a la ascendencia común de los dríades y los centauros, con el agua de las pozas de la luna podremos romper la protección de la llama eterna que rodea la reliquia de los centauros.', 0);
