-- 1027 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1027
SET @ID := 1027;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la última pieza de la vara, $n?', 0),
(@ID, 'esMX', '¿Has encontrado la última pieza de la vara, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la última pieza? Fantástico para ti... y para Raene.$B$BBueno, habrá que ver si la arreglamos, ¿no?', 0),
(@ID, 'esMX', '¿Has encontrado la última pieza? Fantástico para ti... y para Raene.$B$BBueno, habrá que ver si la arreglamos, ¿no?', 0);
-- 1028 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1028
SET @ID := 1028;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque sutil, se siente una poderosa fuerza en el altar y los árboles circundantes.$B$BEmpieza por colocar la vara en el interior del altar y se oirá un repiqueteo suave alrededor del altar que empezará a irradiar luz...', 0),
(@ID, 'esMX', 'Aunque sutil, se siente una poderosa fuerza en el altar y los árboles circundantes.$B$BEmpieza por colocar la vara en el interior del altar y se oirá un repiqueteo suave alrededor del altar que empezará a irradiar luz...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando se apague el brillo, verás que la vara vuelve a estar encantada en la pila del altar.', 0),
(@ID, 'esMX', 'Cuando se apague el brillo, verás que la vara vuelve a estar encantada en la pila del altar.', 0);
-- 1055 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1055
SET @ID := 1055;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado, $n! ¡Muy bien!', 0),
(@ID, 'esMX', '¡Lo has logrado, $n! ¡Muy bien!', 0);
-- 1029 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1029
SET @ID := 1029;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recreado la vara que Teronis se había propuesto encontrar? ¡Qué alegría oírlo!$B$BTeronis estaría orgulloso de ver que su misión se completó incluso después de su trágico fin.', 0),
(@ID, 'esMX', '¿Has recreado la vara que Teronis se había propuesto encontrar? ¡Qué alegría oírlo!$B$BTeronis estaría orgulloso de ver que su misión se completó incluso después de su trágico fin.', 0);
-- 1030 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1030
SET @ID := 1030;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí... eres como yo, pero aún completo. Aún limpio.$B$BNo estoy seguro de cómo has conseguido librarte de las atrocidades que los elfos de la noche han infligido a nuestro pueblo pero me alegro de saber que ya no estoy solo.$B$BLa corrupción corre ahora por las venas de los nuestros, joven, corrupción que los orgullosos elfos de la noche nos trajeron. Son los que le han hecho esto a nuestro pueblo... A ellos culpo por haberme apartado de mi tribu.$B$BDe noche aún puedo ver las fogatas en la oscuridad.', 0),
(@ID, 'esMX', 'Sí, sí... eres como yo, pero aún completo. Aún limpio.$B$BNo estoy seguro de cómo has conseguido librarte de las atrocidades que los elfos de la noche han infligido a nuestro pueblo pero me alegro de saber que ya no estoy solo.$B$BLa corrupción corre ahora por las venas de los nuestros, joven, corrupción que los orgullosos elfos de la noche nos trajeron. Son los que le han hecho esto a nuestro pueblo... A ellos culpo por haberme apartado de mi tribu.$B$BDe noche aún puedo ver las fogatas en la oscuridad.', 0);
-- 1045 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1045
SET @ID := 1045;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Ran ya, amigo mío?$B$BIncluso los elfos de la noche no merecen realmente su ira. Su odio arde aún más brillante que el mío, pero su mente ya no es la suya. Es una amenaza para todas las criaturas de este bosque.', 0),
(@ID, 'esMX', '¿Has matado a Ran ya, amigo mío?$B$BIncluso los elfos de la noche no merecen realmente su ira. Su odio arde aún más brillante que el mío, pero su mente ya no es la suya. Es una amenaza para todas las criaturas de este bosque.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, mi amigo.$B$BEl bosque aún está contaminado pero al menos hemos hecho algo para devolverle parte de su gloria pasada. Si quieres volver aquí, siempre disfruto de la compañía de uno de los míos.$B$BCuídate. Quizás nuestras tribus vuelvan a encontrarse en tiempos menos violentos.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, mi amigo.$B$BEl bosque aún está contaminado pero al menos hemos hecho algo para devolverle parte de su gloria pasada. Si quieres volver aquí, siempre disfruto de la compañía de uno de los míos.$B$BCuídate. Quizás nuestras tribus vuelvan a encontrarse en tiempos menos violentos.', 0);
-- 1046 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1046
SET @ID := 1046;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las centinelas hacen lo que pueden aquí en Vallefresno pero es gracias a $r como tú que hemos recuperado el terreno.', 0),
(@ID, 'esMX', 'Las centinelas hacen lo que pueden aquí en Vallefresno pero es gracias a $r como tú que hemos recuperado el terreno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que esta es la calavera de la amenaza fúrbolg más feroz de Vallefresno?$B$BTus facultades son todo un portento, $n. Las centinelas no pueden agradecértelo lo suficiente. Espero que podamos volver a contar contigo en el futuro para ayudar a nuestro pueblo.$B$BPondré esta calavera y la vara de Dartol en un lugar de veneración para que los demás las vean.$B$BTeronis estaría orgulloso de ti. Gracias otra vez.', 0),
(@ID, 'esMX', '¿Así que esta es la calavera de la amenaza fúrbolg más feroz de Vallefresno?$B$BTus facultades son todo un portento, $n. Las centinelas no pueden agradecértelo lo suficiente. Espero que podamos volver a contar contigo en el futuro para ayudar a nuestro pueblo.$B$BPondré esta calavera y la vara de Dartol en un lugar de veneración para que los demás las vean.$B$BTeronis estaría orgulloso de ti. Gracias otra vez.', 0);
-- 1016 Brazales elementales
-- https://es.classic.wowhead.com/quest=1016
SET @ID := 1016;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puesto que debes destruir los brazales para matar los elementales, no será fácil encontrar los que contienen la información que el pergamino de adivinación requiere. Puedes intercambiar brazales con otros para conseguir los que necesitas o ¿acaso tienes ya el papel adivinado?', 0),
(@ID, 'esMX', 'Puesto que debes destruir los brazales para matar los elementales, no será fácil encontrar los que contienen la información que el pergamino de adivinación requiere. Puedes intercambiar brazales con otros para conseguir los que necesitas o ¿acaso tienes ya el papel adivinado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n, con esto deberíamos conseguir la información que necesitamos para descubrir al culpable. ¿Qué te parecería enfrentarte al mago que llena nuestras pozas de elementales corruptos? La corrupción de Vallefresno y más allá me revuelve el estómago, pero que un mago esté intentando llevar aún más lejos esta destrucción me pone enferma como nunca nada antes lo ha hecho. Haremos que pague por ello.', 0),
(@ID, 'esMX', 'Muy bien, $n, con esto deberíamos conseguir la información que necesitamos para descubrir al culpable. ¿Qué te parecería enfrentarte al mago que llena nuestras pozas de elementales corruptos? La corrupción de Vallefresno y más allá me revuelve el estómago, pero que un mago esté intentando llevar aún más lejos esta destrucción me pone enferma como nunca nada antes lo ha hecho. Haremos que pague por ello.', 0);
-- 1017 Mago invocador
-- https://es.classic.wowhead.com/quest=1017
SET @ID := 1017;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya está? ¿Ha muerto Sarilus Fuenteviciosa?', 0),
(@ID, 'esMX', '¿Ya está? ¿Ha muerto Sarilus Fuenteviciosa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora veo su repugnante sonrisa borrada de su rostro para siempre. Lo has hecho muy bien, $n. Acepta este presente, la Luz de Elune, bébela cuando todo parezca perdido y la muerte se acerque. Podría salvarte, la Diosa mediante.', 0),
(@ID, 'esMX', 'Ahora veo su repugnante sonrisa borrada de su rostro para siempre. Lo has hecho muy bien, $n. Acepta este presente, la Luz de Elune, bébela cuando todo parezca perdido y la muerte se acerque. Podría salvarte, la Diosa mediante.', 0);
-- 622 Regresa junto al cabo Kaleb
-- https://es.classic.wowhead.com/quest=622
SET @ID := 622;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has logrado llegar a la Bahía del Botín? ¿El goblin Krazek me ha arreglado la olla?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has logrado llegar a la Bahía del Botín? ¿El goblin Krazek me ha arreglado la olla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Funciona! Esto es fantástico, ahora podré ponerme a preparar la cena. Muchísimas gracias, $n.$B$BEspero que no tuvieras problemas en la Bahía del Botín. Ese lugar puede ser bastante peliagudo y... he oído rumores que dicen que, algunas veces, los goblins se llevan a marineros borrachos a sus barcos de esclavos... quién sabe dónde... para hacer quién sabe qué...', 0),
(@ID, 'esMX', '¡Funciona! Esto es fantástico, ahora podré ponerme a preparar la cena. Muchísimas gracias, $n.$B$BEspero que no tuvieras problemas en la Bahía del Botín. Ese lugar puede ser bastante peliagudo y... he oído rumores que dicen que, algunas veces, los goblins se llevan a marineros borrachos a sus barcos de esclavos... quién sabe dónde... para hacer quién sabe qué...', 0);
-- 11522
-- https://es.wowhead.com/quest=11522
SET @ID := 11522;
DELETE FROM `quest_template_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_template_locale` (`id`, `locale`, `Details`, `VerifiedBuild`) VALUES
(@ID, 'esES', '[PH]Por alguna razón,(TBD),$BTienes que reunir 5 Raicez de Rajaespina.$B$BEstos solo se pueden encontrar en una ubicación remota al noreste de Shattrath, justo cuando subes a la cima de la Península del Fuego Infernal.', 0),
(@ID, 'esMX', '[PH]Por alguna razón,(TBD),$BTienes que reunir 5 Raicez de Rajaespina.$B$BEstos solo se pueden encontrar en una ubicación remota al noreste de Shattrath, justo cuando subes a la cima de la Península del Fuego Infernal.', 0);
-- 9755
-- https://es.wowhead.com/quest=9755
SET @ID := 9755;
DELETE FROM `quest_template_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_template_locale` (`id`, `locale`, `Details`, `Objectives`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los intentos de interrogatorio han fracasado estrepitosamente, $n. La tortura queda totalmente descartada, por supuesto. Lo que necesitamos es un infiltrado draenei.$B$BTe lanzaré un hechizo que te dará el aspecto y modo de hablar de un elfo de sangre; puede que los agentes capturados nos den la información que necesitamos.$B$BHabla con ellos y averigua todo lo que puedas.$B$BUna cosa, $n, no salgas de la Avanzada de Sangre o el hechizo se anulará.', 'Habla con un agente Halcón del Sol capturado en Avanzada de Sangre y consigue información. Luego ve a ver al exarca Admetius.', 0),
(@ID, 'esMX', 'Los intentos de interrogatorio han fracasado estrepitosamente, $n. La tortura queda totalmente descartada, por supuesto. Lo que necesitamos es un infiltrado draenei.$B$BTe lanzaré un hechizo que te dará el aspecto y modo de hablar de un elfo de sangre; puede que los agentes capturados nos den la información que necesitamos.$B$BHabla con ellos y averigua todo lo que puedas.$B$BUna cosa, $n, no salgas de la Avanzada de Sangre o el hechizo se anulará.', 'Habla con un agente Halcón del Sol capturado en Avanzada de Sangre y consigue información. Luego ve a ver al exarca Admetius.', 0);
-- 9748 Agua que no has de beber...
-- https://es.classic.wowhead.com/quest=9748
SET @ID := 9748;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No bebas ese agua, $n!', 0),
(@ID, 'esMX', '¡No bebas ese agua, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como sospechaba, el agua se ha teñido de rojo por la contaminación que se filtra del fluido del núcleo.$B$BEspero que no hayas nadado en esa agua contaminada.', 0),
(@ID, 'esMX', 'Como sospechaba, el agua se ha teñido de rojo por la contaminación que se filtra del fluido del núcleo.$B$BEspero que no hayas nadado en esa agua contaminada.', 0);
-- 2 La garfa de Garfafilada
-- https://es.classic.wowhead.com/quest=2
SET @ID := 2;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, $gpoderoso:poderosa; $c, he presentido tu llegada. Confío que tienes más noticias que darme sobre tu caza.', 0),
(@ID, 'esMX', 'Sí, $gpoderoso:poderosa; $c, he presentido tu llegada. Confío que tienes más noticias que darme sobre tu caza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De lo más impresionante, $n... ¡no puede haber sido un paseo conseguir la garra de Garrafilada! ¡La Caza de Vallefresno te está yendo bien!$B$BGarrafilada lleva muchos años aterrorizando a los peones de los aserraderos cuando se trasladan a Puesto del Hachazo y se cruzan en su ruta. No lo dudes, cuando se corra la voz de que doblegaste a ese monstruo, ¡se escucharán muchas canciones alabando tu valor en los campamentos y aserraderos de todo Vallefresno!', 0),
(@ID, 'esMX', 'De lo más impresionante, $n... ¡no puede haber sido un paseo conseguir la garra de Garrafilada! ¡La Caza de Vallefresno te está yendo bien!$B$BGarrafilada lleva muchos años aterrorizando a los peones de los aserraderos cuando se trasladan a Puesto del Hachazo y se cruzan en su ruta. No lo dudes, cuando se corra la voz de que doblegaste a ese monstruo, ¡se escucharán muchas canciones alabando tu valor en los campamentos y aserraderos de todo Vallefresno!', 0);
-- 1475 En El Templo de Atal'Hakkar
-- https://es.classic.wowhead.com/quest=1475
SET @ID := 1475;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras el crepúsculo desciende lentamente sobre mi carrera, me dirijo a ti, $n, para que me ayudes en mi búsqueda final de la Liga de Exploradores. Si mis viejos huesos pudieran reunir la fuerza para desafiar el Pantano de los Dolores y el templo hundido, estaría luchando junto a ti.$B$BEl orgullo me dificulta pedir tu ayuda para recolectar las tabletas Atal\'ai. Pero la vejez obliga a la necesidad.$B$BPor favor, ayúdame, $n. Quiero retirarme de la Liga de Exploradores habiendo completado su licitación final.', 0),
(@ID, 'esMX', 'Mientras el crepúsculo desciende lentamente sobre mi carrera, me dirijo a ti, $n, para que me ayudes en mi búsqueda final de la Liga de Exploradores. Si mis viejos huesos pudieran reunir la fuerza para desafiar el Pantano de los Dolores y el templo hundido, estaría luchando junto a ti.$B$BEl orgullo me dificulta pedir tu ayuda para recolectar las tabletas Atal\'ai. Pero la vejez obliga a la necesidad.$B$BPor favor, ayúdame, $n. Quiero retirarme de la Liga de Exploradores habiendo completado su licitación final.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Las tablillas Atal\'ai! ¡Gracias, $n!$B$BUna vez que las entregue a la Liga de Exploradores, nuestros nombres pasarán juntos a la historia. Has ayudado a un viejo enano a cumplir su última obligación en la vida. Por eso te estoy eternamente agradecido.', 0),
(@ID, 'esMX', '¡Las tablillas Atal\'ai! ¡Gracias, $n!$B$BUna vez que las entregue a la Liga de Exploradores, nuestros nombres pasarán juntos a la historia. Has ayudado a un viejo enano a cumplir su última obligación en la vida. Por eso te estoy eternamente agradecido.', 0);
-- 1474 El vínculo
-- https://es.classic.wowhead.com/quest=1474
SET @ID := 1474;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los poderes de más allá del vacío, el súcubo es uno de los más peligrosos, ya que los débiles se atrapan más fácilmente entre sus dedos.$B$BRecuerda eso ahora y en el futuro.', 0),
(@ID, 'esMX', 'De los poderes de más allá del vacío, el súcubo es uno de los más peligrosos, ya que los débiles se atrapan más fácilmente entre sus dedos.$B$BRecuerda eso ahora y en el futuro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez más, lo has hecho bien, $n. Ha pasado bastante tiempo desde que vi a $gun:una; $c joven con tanto potencial como tú. Ten la seguridad de que seguiré observando tu progreso y me prepararé para ayudarte en tus pruebas futuras.$B$BPor ahora, déjame mostrarte el hechizo de invocación para tu súcubo recién dominado.', 0),
(@ID, 'esMX', 'Una vez más, lo has hecho bien, $n. Ha pasado bastante tiempo desde que vi a $gun:una; $c joven con tanto potencial como tú. Ten la seguridad de que seguiré observando tu progreso y me prepararé para ayudarte en tus pruebas futuras.$B$BPor ahora, déjame mostrarte el hechizo de invocación para tu súcubo recién dominado.', 0);
-- 978 Lechúcico Lunadón
-- https://es.classic.wowhead.com/quest=978
SET @ID := 978;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De dónde pueden haber surgido estos poderes? Creo que estamos siguiendo la pista correcta para encontrar la respuesta, $n.', 0),
(@ID, 'esMX', '¿De dónde pueden haber surgido estos poderes? Creo que estamos siguiendo la pista correcta para encontrar la respuesta, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya puedo comparar las plumas... Veamos...', 0),
(@ID, 'esMX', 'Ya puedo comparar las plumas... Veamos...', 0);
-- 3783 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=3783
SET @ID := 3783;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0),
(@ID, 'esMX', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0),
(@ID, 'esMX', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0);
-- 6603 Problemas en Cuna del Invierno
-- https://es.classic.wowhead.com/quest=6603
SET @ID := 6603;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, hola! ¿Así que Meggi te habló de los problemas que he tenido aquí?', 0),
(@ID, 'esMX', '¡Eh, hola! ¿Así que Meggi te habló de los problemas que he tenido aquí?', 0);
-- 6604 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=6604
SET @ID := 6604;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¿qué puedo hacer por ti?', 0),
(@ID, 'esMX', 'Sí, ¿qué puedo hacer por ti?', 0);
-- 5601 Pamela, mi hermana
-- https://es.classic.wowhead.com/quest=5601
SET @ID := 5601;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está mi hermana Jessica? Se fue hace mucho tiempo, cuando yo era muy pequeña. Lloró un montón cuando se fue. ¡No sé por qué lloraba! Igual se cayó y se hizo daño.$B$BCuando Jessica estaba aquí, jugábamos a cosas y bailábamos y recogíamos flores. Y a veces nos escondíamos cuando veíamos que venía papá a casa, ¡y luego salíamos y le dábamos un susto!$B$B¡Vuelve, Jessica! Si vuelves, igual vuelve también papá y podremos volver a jugar todos juntos...', 0),
(@ID, 'esMX', '¿Dónde está mi hermana Jessica? Se fue hace mucho tiempo, cuando yo era muy pequeña. Lloró un montón cuando se fue. ¡No sé por qué lloraba! Igual se cayó y se hizo daño.$B$BCuando Jessica estaba aquí, jugábamos a cosas y bailábamos y recogíamos flores. Y a veces nos escondíamos cuando veíamos que venía papá a casa, ¡y luego salíamos y le dábamos un susto!$B$B¡Vuelve, Jessica! Si vuelves, igual vuelve también papá y podremos volver a jugar todos juntos...', 0);
-- 6028 El informe Vista Eterna
-- https://es.classic.wowhead.com/quest=6028
SET @ID := 6028;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. En nombre del Alba Argenta, te ofrezco seguridad y refugio mientras estás aquí en el Campamento del Orvallo. También podría tener algo de trabajo para ti...', 0),
(@ID, 'esMX', 'Saludos, $n. En nombre del Alba Argenta, te ofrezco seguridad y refugio mientras estás aquí en el Campamento del Orvallo. También podría tener algo de trabajo para ti...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gregor es muy ingenioso. Ha estado lidiando con el Cártel Bonvapor desde hace algún tiempo y se ha convertido en un experto en el "arte" de las negociaciones con goblins. Aunque es cierto que la principal lealtad de los goblins reside en quienes tienen los monederos más grandes, también conocen y respetan el valor de la diplomacia. En todo caso, les proporciona clientes habituales...$B$BEn cualquier caso, el Alba Argenta te agradece tu esfuerzo. Por favor, toma esto junto con nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Gregor es muy ingenioso. Ha estado lidiando con el Cártel Bonvapor desde hace algún tiempo y se ha convertido en un experto en el "arte" de las negociaciones con goblins. Aunque es cierto que la principal lealtad de los goblins reside en quienes tienen los monederos más grandes, también conocen y respetan el valor de la diplomacia. En todo caso, les proporciona clientes habituales...$B$BEn cualquier caso, el Alba Argenta te agradece tu esfuerzo. Por favor, toma esto junto con nuestro agradecimiento.', 0);
-- 6030 El duque Nicolas Zverenhoff
-- https://es.classic.wowhead.com/quest=6030
SET @ID := 6030;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la Luz te guíe en estos tiempos confusos, $c. ¿Qué te trae a este faro de esperanza en medio de la oscuridad y la desesperación?', 0),
(@ID, 'esMX', 'Que la Luz te guíe en estos tiempos confusos, $c. ¿Qué te trae a este faro de esperanza en medio de la oscuridad y la desesperación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Me... me has traído un libro muy especial. Me gustaría decirte que, en este caso, "especial" significa "único y muy posiblemente iluminador", pero todavía hay que verlo.$B$B"¿Ooooo?" ¿A quién en su sano juicio se le ocurría esto?$B$BBien, he oído hablar de ese Umbranse del que te habló Gregor, será una ventaja. Haré todo lo que pueda por descifrarlo. En cuanto a ti... por favor, toma esto, cortesía del Alba Argenta. Mientras estés por aquí quizás puedas ayudarnos con alguna otra cosa.', 0),
(@ID, 'esMX', '"Me... me has traído un libro muy especial. Me gustaría decirte que, en este caso, "especial" significa "único y muy posiblemente iluminador", pero todavía hay que verlo.$B$B"¿Ooooo?" ¿A quién en su sano juicio se le ocurría esto?$B$BBien, he oído hablar de ese Umbranse del que te habló Gregor, será una ventaja. Haré todo lo que pueda por descifrarlo. En cuanto a ti... por favor, toma esto, cortesía del Alba Argenta. Mientras estés por aquí quizás puedas ayudarnos con alguna otra cosa.', 0);
