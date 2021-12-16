-- 5519 El disfraz de ogro Gordok
-- https://es.classic.wowhead.com/quest=5519
SET @ID := 5519;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitas otro traje, ¿verdad? Pues mira, como parece que no voy a ir a ninguna parte, tráeme las cosas que te pedí la vez anterior y te haré otro traje de ogro.', 0),
(@ID, 'esMX', 'Necesitas otro traje, ¿verdad? Pues mira, como parece que no voy a ir a ninguna parte, tráeme las cosas que te pedí la vez anterior y te haré otro traje de ogro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n. Ponte esto y dispondrás de diez minutos para hacer lo que tengas que hacer. ¡Buena suerte!$B$BAh, y si por un casual encuentras una llave para sacarme de aquí, ¡¡¡POR FAVOR, HÁZMELO SABER!!!', 0),
(@ID, 'esMX', 'Aquí tienes, $n. Ponte esto y dispondrás de diez minutos para hacer lo que tengas que hacer. ¡Buena suerte!$B$BAh, y si por un casual encuentras una llave para sacarme de aquí, ¡¡¡POR FAVOR, HÁZMELO SABER!!!', 0);
-- 5522 Leonid Barthalomew
-- https://es.classic.wowhead.com/quest=5522
SET @ID := 5522;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú eres $gel:la; que está haciendo travesuras en la torre Roca Negra, ¿no? ¿Tienes lo que pedí?', 0),
(@ID, 'esMX', 'Tú eres $gel:la; que está haciendo travesuras en la torre Roca Negra, ¿no? ¿Tienes lo que pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. No conoces el poder maligno para el que has trabajado, pero ahora conocerás la verdad. Y no temas, no soy un sirviente de ese amo. Soy Leonid Barthalomew, conocido como "el Venerado" por mis hermanos en el Alba Argenta.$B$BEngañé a Tinkee para que te enviara a ti y a los huevos de dragón. Y es bueno que mi truco haya tenido éxito, porque si estos huevos hubieran llegado a su destino previsto, un gran poder habría caído en manos del enemigo.', 0),
(@ID, 'esMX', 'Ah, muy bien. No conoces el poder maligno para el que has trabajado, pero ahora conocerás la verdad. Y no temas, no soy un sirviente de ese amo. Soy Leonid Barthalomew, conocido como "el Venerado" por mis hermanos en el Alba Argenta.$B$BEngañé a Tinkee para que te enviara a ti y a los huevos de dragón. Y es bueno que mi truco haya tenido éxito, porque si estos huevos hubieran llegado a su destino previsto, un gran poder habría caído en manos del enemigo.', 0);
-- 5525 ¡Libera a Knot!
-- https://es.classic.wowhead.com/quest=5525
SET @ID := 5525;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se llama llave de los grilletes de Gordok... bueno, así es como la llaman esos graciosillos. Creo que podría tenerla cualquiera de los ogros, pero no sé cuáles en concreto. Probablemente podrían tenerla los guardias...$B$B¿Pero qué estoy diciendo? ¡Si tú ya la tienes! ¡¿No?! ¡¿¿No es eso que tienes ahí??!', 0),
(@ID, 'esMX', 'Se llama llave de los grilletes de Gordok... bueno, así es como la llaman esos graciosillos. Creo que podría tenerla cualquiera de los ogros, pero no sé cuáles en concreto. Probablemente podrían tenerla los guardias...$B$B¿Pero qué estoy diciendo? ¡Si tú ya la tienes! ¡¿No?! ¡¿¿No es eso que tienes ahí??!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú... eres $gel:la; mejor. Todos los demás no te llegan ni a la rodilla. ¡Gracias por liberarme!$B$B¡Sabía que mi destino no era acabar siendo el aperitivo de algún ogro!', 0),
(@ID, 'esMX', 'Tú... eres $gel:la; mejor. Todos los demás no te llegan ni a la rodilla. ¡Gracias por liberarme!$B$B¡Sabía que mi destino no era acabar siendo el aperitivo de algún ogro!', 0);
-- 7429 ¡Libera a Knot!
-- https://es.classic.wowhead.com/quest=7429
SET @ID := 7429;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se llama llave de los grilletes de Gordok... bueno, así es como la llaman esos graciosillos. Creo que podría tenerla cualquiera de los ogros, pero no sé cuáles en concreto. Probablemente podrían tenerla los guardias...$B$B¿Pero qué estoy diciendo? ¡Si tú ya la tienes! ¡¿No?! ¡¿¿No es eso que tienes ahí??!', 0),
(@ID, 'esMX', 'Se llama llave de los grilletes de Gordok... bueno, así es como la llaman esos graciosillos. Creo que podría tenerla cualquiera de los ogros, pero no sé cuáles en concreto. Probablemente podrían tenerla los guardias...$B$B¿Pero qué estoy diciendo? ¡Si tú ya la tienes! ¡¿No?! ¡¿¿No es eso que tienes ahí??!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias por liberarme! Tú... eres $gel:la; mejor. Todos los demás no te llegan ni a la rodilla.$B$B¡Sabía que mi destino no era acabar siendo el aperitivo de algún ogro!', 0),
(@ID, 'esMX', '¡Gracias por liberarme! Tú... eres $gel:la; mejor. Todos los demás no te llegan ni a la rodilla.$B$B¡Sabía que mi destino no era acabar siendo el aperitivo de algún ogro!', 0);
-- 5528 La cata de los Gordok
-- https://es.classic.wowhead.com/quest=5528
SET @ID := 5528;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora eres $gel jefe:la jefa;, ¡así consigues muestras gratis de mis mejores bebidas! ¡Te darán un buen subidón y un potente tirón! Son las buenas, $gjefe:jefa;. ¡Prueba y dilo a Kreeg!', 0),
(@ID, 'esMX', 'Ahora eres $gel jefe:la jefa;, ¡así consigues muestras gratis de mis mejores bebidas! ¡Te darán un buen subidón y un potente tirón! Son las buenas, $gjefe:jefa;. ¡Prueba y dilo a Kreeg!', 0);
-- 5531 Betina Bigglezink
-- https://es.classic.wowhead.com/quest=5531
SET @ID := 5531;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, $n! Escuché que estabas aquí con algunos huevos de dragón. Bueno, ¡veámoslos!', 0),
(@ID, 'esMX', '¡Hola, $n! Escuché que estabas aquí con algunos huevos de dragón. Bueno, ¡veámoslos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Allí están! Y en un recipiente tan bonito. ¡El tamaño perfecto!$B$BGuardaremos estos huevos en un lugar seguro para poder estudiarlos más tarde, pero ahora mismo necesitamos esa cosa que trajiste.$B$BHe creado un dispositivo con un uso muy específico: destruir a los eruditos no-muertos de Scholomance. Están estudiando dragones en sus esfuerzos por crear un vuelo de dragones plagado, y debemos detener su progreso.$B$BLlamo al dispositivo Gambito del Alba, porque... ¡No estoy segura de si funciona!$B$B¿Lo averiguarás por nosotros?', 0),
(@ID, 'esMX', '¡Allí están! Y en un recipiente tan bonito. ¡El tamaño perfecto!$B$BGuardaremos estos huevos en un lugar seguro para poder estudiarlos más tarde, pero ahora mismo necesitamos esa cosa que trajiste.$B$BHe creado un dispositivo con un uso muy específico: destruir a los eruditos no-muertos de Scholomance. Están estudiando dragones en sus esfuerzos por crear un vuelo de dragones plagado, y debemos detener su progreso.$B$BLlamo al dispositivo Gambito del Alba, porque... ¡No estoy segura de si funciona!$B$B¿Lo averiguarás por nosotros?', 0);
-- 5533 Scholomance
-- https://es.classic.wowhead.com/quest=5533
SET @ID := 5533;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hallado $c. He dedicado una parte importante de mis recientes estudios a Scholomance y creo conocer un medio para adquirir una llave... una que te permita cruzar la puerta delantera.$B$BSolo puedo imaginar las atrocidades que podrán verse en su interior, $n. No sé cómo hacéis $glos héroes:las heroinas;...', 0),
(@ID, 'esMX', 'Bien hallado $c. He dedicado una parte importante de mis recientes estudios a Scholomance y creo conocer un medio para adquirir una llave... una que te permita cruzar la puerta delantera.$B$BSolo puedo imaginar las atrocidades que podrán verse en su interior, $n. No sé cómo hacéis $glos héroes:las heroinas;...', 0);
-- 5534 El equipamiento "perdido" de Kim'jael
-- https://es.classic.wowhead.com/quest=5534
SET @ID := 5534;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien, $n? ¿Dónde está la runa? Eres $gun buen empleado:una buena empleada;, ¿verdad? ¿Estás aquí para ayudar?$B$BNo me hagas pensarme dos veces lo que acordamos que te pagaría. ¡¿Qué?! Ah, ¿no habíamos quedado en nada? Oh, bueno... entonces tómate tu tiempo, pero conste que la cantidad será mucho menor si te lleva mucho tiempo.', 0),
(@ID, 'esMX', '¿Y bien, $n? ¿Dónde está la runa? Eres $gun buen empleado:una buena empleada;, ¿verdad? ¿Estás aquí para ayudar?$B$BNo me hagas pensarme dos veces lo que acordamos que te pagaría. ¡¿Qué?! Ah, ¿no habíamos quedado en nada? Oh, bueno... entonces tómate tu tiempo, pero conste que la cantidad será mucho menor si te lleva mucho tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ea! ¡Estupendo!$B$BMe aseguraré de averiguar para qué es esto y por qué lo quiere Magus Rimtori, la petarda que me contrató. ¡Ja! ¡Ahora os he pillado, malditos elfos de sangre! ¡Kim\'jael! ¡Toma! ¡Ya les enseñaré yo quiénes son las ratas!$B$BHas hecho un trabajo daguten, $n. Un montón de gracias. Ah, aquí tienes esta moneda y márchate ya, tengo cosas que hacer.', 0),
(@ID, 'esMX', '¡Ea! ¡Estupendo!$B$BMe aseguraré de averiguar para qué es esto y por qué lo quiere Magus Rimtori, la petarda que me contrató. ¡Ja! ¡Ahora os he pillado, malditos elfos de sangre! ¡Kim\'jael! ¡Toma! ¡Ya les enseñaré yo quiénes son las ratas!$B$BHas hecho un trabajo daguten, $n. Un montón de gracias. Ah, aquí tienes esta moneda y márchate ya, tengo cosas que hacer.', 0);
-- 5534 El equipamiento "perdido" de Kim'jael
-- https://es.classic.wowhead.com/quest=5534
SET @ID := 5534;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien, $n? ¿Dónde está la runa? Eres $gun buen empleado:una buena empleada;, ¿verdad? ¿Estás aquí para ayudar?$B$BNo me hagas pensarme dos veces lo que acordamos que te pagaría. ¡¿Qué?! Ah, ¿no habíamos quedado en nada? Oh, bueno... entonces tómate tu tiempo, pero conste que la cantidad será mucho menor si te lleva mucho tiempo.', 0),
(@ID, 'esMX', '¿Y bien, $n? ¿Dónde está la runa? Eres $gun buen empleado:una buena empleada;, ¿verdad? ¿Estás aquí para ayudar?$B$BNo me hagas pensarme dos veces lo que acordamos que te pagaría. ¡¿Qué?! Ah, ¿no habíamos quedado en nada? Oh, bueno... entonces tómate tu tiempo, pero conste que la cantidad será mucho menor si te lleva mucho tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ea! ¡Estupendo!$B$BMe aseguraré de averiguar para qué es esto y por qué lo quiere Magus Rimtori, la petarda que me contrató. ¡Ja! ¡Ahora os he pillado, malditos elfos de sangre! ¡Kim\'jael! ¡Toma! ¡Ya les enseñaré yo quiénes son las ratas!$B$BHas hecho un trabajo daguten, $n. Un montón de gracias. Ah, aquí tienes esta moneda y márchate ya, tengo cosas que hacer.', 0),
(@ID, 'esMX', '¡Ea! ¡Estupendo!$B$BMe aseguraré de averiguar para qué es esto y por qué lo quiere Magus Rimtori, la petarda que me contrató. ¡Ja! ¡Ahora os he pillado, malditos elfos de sangre! ¡Kim\'jael! ¡Toma! ¡Ya les enseñaré yo quiénes son las ratas!$B$BHas hecho un trabajo daguten, $n. Un montón de gracias. Ah, aquí tienes esta moneda y márchate ya, tengo cosas que hacer.', 0);
-- 5537 Trozos esqueléticos
-- https://es.classic.wowhead.com/quest=5537
SET @ID := 5537;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque suene muy siniestro, necesitaremos un suministro abundante de fragmentos esqueléticos para la capa externa de la llave. Por algo se llama Llave esqueleto, ¿sabes?', 0),
(@ID, 'esMX', 'Aunque suene muy siniestro, necesitaremos un suministro abundante de fragmentos esqueléticos para la capa externa de la llave. Por algo se llama Llave esqueleto, ¿sabes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto valdrá, $n! Ahora me toca a mí, los imbuiré con un temple adecuado que impedirá que se destruyan en el proceso de fundición por el que van a pasar.$B$BEl siguiente paso consistirá en conseguir el molde adecuado para la llave. Conozco a un herrero goblin en Tanaris que en el pasado hizo moldes para objetos igual de macabros. Trabaja para quien trabajan todos los goblins: el mejor postor.', 0),
(@ID, 'esMX', '¡Esto valdrá, $n! Ahora me toca a mí, los imbuiré con un temple adecuado que impedirá que se destruyan en el proceso de fundición por el que van a pasar.$B$BEl siguiente paso consistirá en conseguir el molde adecuado para la llave. Conozco a un herrero goblin en Tanaris que en el pasado hizo moldes para objetos igual de macabros. Trabaja para quien trabajan todos los goblins: el mejor postor.', 0);
-- 5542 Perros demoníacos
-- https://es.classic.wowhead.com/quest=5542
SET @ID := 5542;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te apiades de los perros demoníacos, raza. ¡Son abominaciones!', 0),
(@ID, 'esMX', 'No te apiades de los perros demoníacos, raza. ¡Son abominaciones!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Ven. Descansa. ¡Vamos a comer algo y hablar de los días pasados!', 0),
(@ID, 'esMX', 'Bien hecho, $n. Ven. Descansa. ¡Vamos a comer algo y hablar de los días pasados!', 0);
-- 5543 Cielos sangrientos
-- https://es.classic.wowhead.com/quest=5543
SET @ID := 5543;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No subestimes a las alimañas aladas, $r. La plaga les ha dado habilidades sobrenaturales.', 0),
(@ID, 'esMX', 'No subestimes a las alimañas aladas, $r. La plaga les ha dado habilidades sobrenaturales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eres un brillante ejemplo de cortesía, $r! Hacía mucho que no sentía la sangre de los héroes corriendo por mis venas. ¡Tus hazañas hacen crecer la moral!', 0),
(@ID, 'esMX', '¡Eres un brillante ejemplo de cortesía, $r! Hacía mucho que no sentía la sangre de los héroes corriendo por mis venas. ¡Tus hazañas hacen crecer la moral!', 0);
-- 5544 Gusanos carroñeros
-- https://es.classic.wowhead.com/quest=5544
SET @ID := 5544;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aprenderás a tolerar el sabor, $r.', 0),
(@ID, 'esMX', 'Aprenderás a tolerar el sabor, $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que la Luz te guarde! $gBendito:Bendita; seas, joven.', 0),
(@ID, 'esMX', '¡Que la Luz te guarde! $gBendito:Bendita; seas, joven.', 0);
-- 5561 El rodeo kodo
-- https://es.classic.wowhead.com/quest=5561
SET @ID := 5561;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Kodos domados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 5581 Los portales de la Legión
-- https://es.classic.wowhead.com/quest=5581
SET @ID := 5581;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Portales destruidos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has arrasado los portales demoníacos del Aquelarre Mannoroc?', 0),
(@ID, 'esMX', '¿Has arrasado los portales demoníacos del Aquelarre Mannoroc?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gdigno:digna; de elogio, $n. Con tus esfuerzos has contribuido enormemente a la lucha contra la amenaza demoníaca y, gracias a eso, todo Azeroth está más seguro.', 0),
(@ID, 'esMX', 'Eres $gdigno:digna; de elogio, $n. Con tus esfuerzos has contribuido enormemente a la lucha contra la amenaza demoníaca y, gracias a eso, todo Azeroth está más seguro.', 0);
-- 5582 Escama de dragón sana
-- https://es.classic.wowhead.com/quest=5582
SET @ID := 5582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Ahora podré seguir estudiando las maquinaciones de la Plaga. Gracias, $n. Si encuentras más escamas, tráemelas.', 0),
(@ID, 'esMX', '¡Excelente! Ahora podré seguir estudiando las maquinaciones de la Plaga. Gracias, $n. Si encuentras más escamas, tráemelas.', 0);
-- 5621 Prendas de la luna
-- https://es.classic.wowhead.com/quest=5621
SET @ID := 5621;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cura y fortalece a la centinela Shaya.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros hechizos de Fortalecer son muy poderosos, $n. Permiten a nuestros compañeros recibir más daño de todo tipo de ataques y sobrevivir en situaciones en las que normalmente caerían. Pero esto no es nada en comparación con nuestra capacidad de curar. No hay sanadores más grandes que los sacerdotes; es bueno recordarlo. Tu poder por sí solo puede cambiar el rumbo de la batalla fácilmente.', 0),
(@ID, 'esMX', 'Nuestros hechizos de Fortalecer son muy poderosos, $n. Permiten a nuestros compañeros recibir más daño de todo tipo de ataques y sobrevivir en situaciones en las que normalmente caerían. Pero esto no es nada en comparación con nuestra capacidad de curar. No hay sanadores más grandes que los sacerdotes; es bueno recordarlo. Tu poder por sí solo puede cambiar el rumbo de la batalla fácilmente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien y has servido a Elune. Por eso te agradezco.$B$BPor favor, toma esta toga como muestra de mi agradecimiento. Significa que te has ganado tu lugar en nuestra orden. Si lo deseas, llévelo con orgullo, pero de cualquier manera, siempre te reconoceremos como $guno:una; de $glos nuestros:las nuestras;.$B$BVe con Elune, $n, y gracias.', 0),
(@ID, 'esMX', 'Lo has hecho bien y has servido a Elune. Por eso te agradezco.$B$BPor favor, toma esta toga como muestra de mi agradecimiento. Significa que te has ganado tu lugar en nuestra orden. Si lo deseas, llévelo con orgullo, pero de cualquier manera, siempre te reconoceremos como $guno:una; de $glos nuestros:las nuestras;.$B$BVe con Elune, $n, y gracias.', 0);
-- 5622 Los caminos de Elune
-- https://es.classic.wowhead.com/quest=5622
SET @ID := 5622;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que Shanda te ha enviado a buscarme, $n. Enseñar a $glos sacerdotes:las sacerdotisas; jóvenes los caminos de Elune me da una gran satisfacción.', 0),
(@ID, 'esMX', 'Me alegra ver que Shanda te ha enviado a buscarme, $n. Enseñar a $glos sacerdotes:las sacerdotisas; jóvenes los caminos de Elune me da una gran satisfacción.', 0);
-- 5624 Las prendas de la Luz
-- https://es.classic.wowhead.com/quest=5624
SET @ID := 5624;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cura y fortalece al guardia Roberts', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 5625 Las prendas de la Luz
-- https://es.classic.wowhead.com/quest=5625
SET @ID := 5625;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cura y fortalece al montaraz Dolf', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has encontrado a Dolf, $n?$B$BProbablemente ya lo sepas, pero nuestra capacidad de curar es muy útil. No solo podemos cuidar de los heridos, sino que somos vitales para la supervivencia de todos esos posibles héroes que intentan hacerse un nombre. Fortaleciéndolos para aumentar la cantidad de golpes que pueden recibir y nuestra magia curativa para mantenerlos con vida, ¡no hay nada que no podamos superar!', 0),
(@ID, 'esMX', '¿Ya has encontrado a Dolf, $n?$B$BProbablemente ya lo sepas, pero nuestra capacidad de curar es muy útil. No solo podemos cuidar de los heridos, sino que somos vitales para la supervivencia de todos esos posibles héroes que intentan hacerse un nombre. Fortaleciéndolos para aumentar la cantidad de golpes que pueden recibir y nuestra magia curativa para mantenerlos con vida, ¡no hay nada que no podamos superar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, $n. Tienes la Luz en tu interior, eso es seguro.$B$BTen, coge esta toga. Denotará tu papel en la iglesia y ayudará a la gente a reconocerte como $c. Llévala si quieres.$B$BMás adelante tendrás que superar más pruebas. Haz lo que puedas para aprender más sobre tus habilidades y sobre lo que eres capaz de hacer. Ponte a prueba con uno o dos combates en solitario y luego con otros viajeros.$B$BY no te preocupes... eres más fuerte de lo que crees.', 0),
(@ID, 'esMX', 'Bien, $n. Tienes la Luz en tu interior, eso es seguro.$B$BTen, coge esta toga. Denotará tu papel en la iglesia y ayudará a la gente a reconocerte como $c. Llévala si quieres.$B$BMás adelante tendrás que superar más pruebas. Haz lo que puedas para aprender más sobre tus habilidades y sobre lo que eres capaz de hacer. Ponte a prueba con uno o dos combates en solitario y luego con otros viajeros.$B$BY no te preocupes... eres más fuerte de lo que crees.', 0);
-- 5626 Al servicio de la Luz
-- https://es.classic.wowhead.com/quest=5626
SET @ID := 5626;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, así que te envía Silo, ¿eh? ¡Bien, bien! Tiene razón, ya es hora de que des un paso más grande hacia la Luz. Forjará tu carácter y te hará más fuerte... y eso es lo que necesitarás por encima de todo: fuerza física... y fuerza de voluntad.', 0),
(@ID, 'esMX', 'Ah, así que te envía Silo, ¿eh? ¡Bien, bien! Tiene razón, ya es hora de que des un paso más grande hacia la Luz. Forjará tu carácter y te hará más fuerte... y eso es lo que necesitarás por encima de todo: fuerza física... y fuerza de voluntad.', 0);
-- 5627 Estrellas de Elune
-- https://es.classic.wowhead.com/quest=5627
SET @ID := 5627;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado ser $gdigno:digna; de la atención de Elune, $n. Si sientes que estás $glisto:lista;, me gustaría mucho enseñarte uno de los hechizos únicos para nuestra gente.', 0),
(@ID, 'esMX', 'Has demostrado ser $gdigno:digna; de la atención de Elune, $n. Si sientes que estás $glisto:lista;, me gustaría mucho enseñarte uno de los hechizos únicos para nuestra gente.', 0);
-- La vuelta a casa
-- 5628, 5629, 5631
-- https://es.classic.wowhead.com/quest=5628
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5628, 5629, 5631) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5628, 'esES', 'Maravilloso, has vuelto a casa, $n. Siempre nos complace a Tyrande y a mí cuando aquellos a quienes hemos entrenado salen al mundo y regresan sanos y salvos. ¿Cómo te han ido las cosas? ¿Elune todavía bendice tus viajes? Quizás después de que hablemos más sobre el asunto en cuestión, podrías contarme más sobre tus viajes.', 0),
(5629, 'esES', 'Maravilloso, has vuelto a casa, $n. Siempre nos complace a Tyrande y a mí cuando aquellos a quienes hemos entrenado salen al mundo y regresan sanos y salvos. ¿Cómo te han ido las cosas? ¿Elune todavía bendice tus viajes? Quizás después de que hablemos más sobre el asunto en cuestión, podrías contarme más sobre tus viajes.', 0),
(5631, 'esES', 'Maravilloso, has vuelto a casa, $n. Siempre nos complace a Tyrande y a mí cuando aquellos a quienes hemos entrenado salen al mundo y regresan sanos y salvos. ¿Cómo te han ido las cosas? ¿Elune todavía bendice tus viajes? Quizás después de que hablemos más sobre el asunto en cuestión, podrías contarme más sobre tus viajes.', 0),
(5628, 'esMX', 'Maravilloso, has vuelto a casa, $n. Siempre nos complace a Tyrande y a mí cuando aquellos a quienes hemos entrenado salen al mundo y regresan sanos y salvos. ¿Cómo te han ido las cosas? ¿Elune todavía bendice tus viajes? Quizás después de que hablemos más sobre el asunto en cuestión, podrías contarme más sobre tus viajes.', 0),
(5629, 'esMX', 'Maravilloso, has vuelto a casa, $n. Siempre nos complace a Tyrande y a mí cuando aquellos a quienes hemos entrenado salen al mundo y regresan sanos y salvos. ¿Cómo te han ido las cosas? ¿Elune todavía bendice tus viajes? Quizás después de que hablemos más sobre el asunto en cuestión, podrías contarme más sobre tus viajes.', 0),
(5631, 'esMX', 'Maravilloso, has vuelto a casa, $n. Siempre nos complace a Tyrande y a mí cuando aquellos a quienes hemos entrenado salen al mundo y regresan sanos y salvos. ¿Cómo te han ido las cosas? ¿Elune todavía bendice tus viajes? Quizás después de que hablemos más sobre el asunto en cuestión, podrías contarme más sobre tus viajes.', 0);
-- 5641 Sin miedo
-- https://es.classic.wowhead.com/quest=5641
SET @ID := 5641;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes lo necesario en $gun:una; gran $c, $n. ¡Sigue con el buen trabajo!$B$BYa has demostrado que estás $glisto:lista; para la batalla. Quizás es hora de que te enseñemos un poco más.', 0),
(@ID, 'esMX', 'Tienes lo necesario en $gun:una; gran $c, $n. ¡Sigue con el buen trabajo!$B$BYa has demostrado que estás $glisto:lista; para la batalla. Quizás es hora de que te enseñemos un poco más.', 0);
-- 5646 Peste devoradora
-- https://es.classic.wowhead.com/quest=5646
SET @ID := 5646;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, has vuelto, y no es demasiado tarde. Tenemos grandes cosas que discutir, $n. Tus habilidades son cada vez más fuertes y debemos asegurarnos de que estés $gpreparado:preparada;.', 0),
(@ID, 'esMX', 'Bien, has vuelto, y no es demasiado tarde. Tenemos grandes cosas que discutir, $n. Tus habilidades son cada vez más fuertes y debemos asegurarnos de que estés $gpreparado:preparada;.', 0);
-- 5648 Prendas de espiritualidad
-- https://es.classic.wowhead.com/quest=5648
SET @ID := 5648;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cura y fortalece al bruto Kor\'ja', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La mayoría piensa que es lógico que la magia curativa sea poderosa, pero no muchos entienden cuán poderosa es. Puedes mantener a muchos con vida cuando deberían encontrarse con sus propios antepasados. Esta magia curativa combinada con la habilidad de Fortaleza es una combinación muy poderosa de hechizos. Recuerda esto. Es útil para todo tipo de personas: guerreros, magos y todo lo demás.', 0),
(@ID, 'esMX', 'La mayoría piensa que es lógico que la magia curativa sea poderosa, pero no muchos entienden cuán poderosa es. Puedes mantener a muchos con vida cuando deberían encontrarse con sus propios antepasados. Esta magia curativa combinada con la habilidad de Fortaleza es una combinación muy poderosa de hechizos. Recuerda esto. Es útil para todo tipo de personas: guerreros, magos y todo lo demás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, entonces Kor\'ja vive y se va a defender nuestra ciudad de esos humanos. A menudo deseo recordar días de batalla; donde el poder se mostraba en el combate y eran los sabios quienes a menudo destruían a aquellos que confiaban solo en su fuerza.$B$BLo has hecho bien, $n. Toma esta toga. Quizás te ayude, quizás no te importe, pero te lo ganaste y estoy orgulloso de llamarte $ghermano:hermana;.', 0),
(@ID, 'esMX', 'Bien, entonces Kor\'ja vive y se va a defender nuestra ciudad de esos humanos. A menudo deseo recordar días de batalla; donde el poder se mostraba en el combate y eran los sabios quienes a menudo destruían a aquellos que confiaban solo en su fuerza.$B$BLo has hecho bien, $n. Toma esta toga. Quizás te ayude, quizás no te importe, pero te lo ganaste y estoy orgulloso de llamarte $ghermano:hermana;.', 0);
-- 5649 Al servicio de la espiritualidad
-- https://es.classic.wowhead.com/quest=5649
SET @ID := 5649;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahh... así que finalmente vienes a Tai\'jin. Esto es bueno.$B$BYa sabes que no somos la misma tribu que una vez se unió a la Horda. Somos mucho más fuertes ahora. Somos más fuertes porque nos adaptamos, la Horda nos enseña mucho. Ya no derrotamos a nuestros enemigos y obtenemos fuerzas de ellos; ahora ganamos fuerza y luego derrotamos a nuestros enemigos.$B$BLa diferencia será sutil, pero aprenderás. Ya verás. La tribu cuenta contigo para aprender esas cosas.', 0),
(@ID, 'esMX', 'Ahh... así que finalmente vienes a Tai\'jin. Esto es bueno.$B$BYa sabes que no somos la misma tribu que una vez se unió a la Horda. Somos mucho más fuertes ahora. Somos más fuertes porque nos adaptamos, la Horda nos enseña mucho. Ya no derrotamos a nuestros enemigos y obtenemos fuerzas de ellos; ahora ganamos fuerza y luego derrotamos a nuestros enemigos.$B$BLa diferencia será sutil, pero aprenderás. Ya verás. La tribu cuenta contigo para aprender esas cosas.', 0);
-- 5650 Las prendas de la Oscuridad
-- https://es.classic.wowhead.com/quest=5650
SET @ID := 5650;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cura y fortalece al guardia de la muerte Kel.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros poderes nos hacen ideales para tantas situaciones, $n. Sin embargo, descubrirás que, pase lo que pase, nuestra capacidad para curar heridas y aumentar la cantidad de daño que pueden recibir nuestros compañeros siempre serán los talentos más deseados a los que tengamos acceso. No dejes que eso te disuada de seguir otros caminos como $c; puedes ser $gefectivo:efectiva; de muchas maneras. Pero... si realmente deseas destruir a tus enemigos con energía mágica, quizás lo arcano sea más de tu agrado.', 0),
(@ID, 'esMX', 'Nuestros poderes nos hacen ideales para tantas situaciones, $n. Sin embargo, descubrirás que, pase lo que pase, nuestra capacidad para curar heridas y aumentar la cantidad de daño que pueden recibir nuestros compañeros siempre serán los talentos más deseados a los que tengamos acceso. No dejes que eso te disuada de seguir otros caminos como $c; puedes ser $gefectivo:efectiva; de muchas maneras. Pero... si realmente deseas destruir a tus enemigos con energía mágica, quizás lo arcano sea más de tu agrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has superado mi prueba con facilidad. Muy bien.$B$BPronto podrás asumir más responsabilidad, y ese camino te conducirá a poderes aún más oscuros, poderes que ningún otro $c de otra raza posee.$B$BToma esta toga como símbolo de tu estatus. Te la has ganado. Póntela si lo deseas o haz con ella lo que gustes. Nosotros siempre te reconoceremos por lo que has conseguido en nuestras filas.', 0),
(@ID, 'esMX', 'Has superado mi prueba con facilidad. Muy bien.$B$BPronto podrás asumir más responsabilidad, y ese camino te conducirá a poderes aún más oscuros, poderes que ningún otro $c de otra raza posee.$B$BToma esta toga como símbolo de tu estatus. Te la has ganado. Póntela si lo deseas o haz con ella lo que gustes. Nosotros siempre te reconoceremos por lo que has conseguido en nuestras filas.', 0);
-- 5651 Al servicio de la Oscuridad
-- https://es.classic.wowhead.com/quest=5651
SET @ID := 5651;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin has llegado. No podrás superar las pruebas que tienes por delante con la sola ayuda de tu fe, joven. Has de ser $gávido:ávida; y actuar con apremio.', 0),
(@ID, 'esMX', 'Por fin has llegado. No podrás superar las pruebas que tienes por delante con la sola ayuda de tu fe, joven. Has de ser $gávido:ávida; y actuar con apremio.', 0);
-- 5652 Maleficio de Debilidad
-- https://es.classic.wowhead.com/quest=5652
SET @ID := 5652;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Harías bien en prestar atención a esta lección, joven. El maleficio de la debilidad será de gran ayuda para ti en la batalla. Más tarde te haré pruebas para que te desarrolles y demuestres tu valía a la tribu.', 0),
(@ID, 'esMX', 'Harías bien en prestar atención a esta lección, joven. El maleficio de la debilidad será de gran ayuda para ti en la batalla. Más tarde te haré pruebas para que te desarrolles y demuestres tu valía a la tribu.', 0);
-- Toque de debilidad
-- 5659, 5660, 5661, 5662, 5663
-- https://es.classic.wowhead.com/quest=5660
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5659, 5660, 5661, 5662, 5663) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5659, 'esES', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5660, 'esES', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5661, 'esES', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5662, 'esES', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5663, 'esES', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5659, 'esMX', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5660, 'esMX', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5661, 'esMX', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5662, 'esMX', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0),
(5663, 'esMX', 'Ah, bien, ha llegado $gotro:otra;. Puede que el tiempo no me importe, pero para ti es fundamental. Hay mucho que aprender y hay mucho que deseo enseñarte. Simplemente debes demostrar tu valía. Hazlo y serás muy $grecompensado:recompensada;.', 0);
-- 5672 La Gracia de Elune
-- https://es.classic.wowhead.com/quest=5672
SET @ID := 5672;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al dedicarte a Elune y a nuestra gente, has alcanzado un estado que no todos podemos lograr. Es tradición que luego se te enseñen habilidades aún mayores para tu devoción. ¿Aceptas?', 0),
(@ID, 'esMX', 'Al dedicarte a Elune y a nuestra gente, has alcanzado un estado que no todos podemos lograr. Es tradición que luego se te enseñen habilidades aún mayores para tu devoción. ¿Aceptas?', 0);
-- 5673 La Gracia de Elune
-- https://es.classic.wowhead.com/quest=5673
SET @ID := 5673;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Elune te bendiga por regresar tan rápido a nosotros. Este es un momento importante en tu capacitación y un momento que todos nuestra orden se toma muy en serio. Cuando hayas descansado de tu viaje, por favor, avíseme. Luego, podemos discutir la continuación de tu capacitación y dónde te llevará tu camino.', 0),
(@ID, 'esMX', 'Elune te bendiga por regresar tan rápido a nosotros. Este es un momento importante en tu capacitación y un momento que todos nuestra orden se toma muy en serio. Cuando hayas descansado de tu viaje, por favor, avíseme. Luego, podemos discutir la continuación de tu capacitación y dónde te llevará tu camino.', 0);
-- 5679 Peste devoradora
-- https://es.classic.wowhead.com/quest=5679
SET @ID := 5679;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te enseñaré Peste devoradora si sientes que estás $gpreparado:preparada;, $n. Un hechizo de no poca potencia, te ayudará en tus próximas batallas. Practica con él, habrá pruebas más adelante.', 0),
(@ID, 'esMX', 'Te enseñaré Peste devoradora si sientes que estás $gpreparado:preparada;, $n. Un hechizo de no poca potencia, te ayudará en tus próximas batallas. Practica con él, habrá pruebas más adelante.', 0);
-- 5680 Guardia de las Sombras
-- https://es.classic.wowhead.com/quest=5680
SET @ID := 5680;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus ritos llegarán pronto. Por ahora, te enseño un hechizo que te será de gran utilidad cuando luches contra tus enemigos.', 0),
(@ID, 'esMX', 'Tus ritos llegarán pronto. Por ahora, te enseño un hechizo que te será de gran utilidad cuando luches contra tus enemigos.', 0);
-- 5713 Un disparo, una baja
-- https://es.classic.wowhead.com/quest=5713
SET @ID := 5713;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a Sentinel Aynasha en el camino? Partió en una misión importante pero aún no ha regresado.', 0),
(@ID, 'esMX', '¿Has visto a Sentinel Aynasha en el camino? Partió en una misión importante pero aún no ha regresado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Traes noticias que son muy bien recibidas, $c. Me alegra saber que Aynasha sigue con vida gracias a ti. Espero que aceptes esta recompensa por tu valor. Que Elune te proteja e ilumine tu camino.', 0),
(@ID, 'esMX', 'Traes noticias que son muy bien recibidas, $c. Me alegra saber que Aynasha sigue con vida gracias a ti. Espero que aceptes esta recompensa por tu valor. Que Elune te proteja e ilumine tu camino.', 0);
-- 5721 La Batalla de Villa Darrow
-- https://es.classic.wowhead.com/quest=5721
SET @ID := 5721;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Acepta el perdón de Rutagrana', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creo que escuché fantasmas afuera. Me susurran cosas aterradoras...', 0),
(@ID, 'esMX', 'Creo que escuché fantasmas afuera. Me susurran cosas aterradoras...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La batalla ha terminado! Mi papá me lo susurró. ¡Asustó a todos los fantasmas y dice que va a venir a casa! ¡Estoy tan feliz!$B$BTambién dijo que tendría que recibirte bien cuando vinieras a casa, así que he preparado un poco de té.$B$B¡Espero que te guste con montones de azúcar!', 0),
(@ID, 'esMX', '¡La batalla ha terminado! Mi papá me lo susurró. ¡Asustó a todos los fantasmas y dice que va a venir a casa! ¡Estoy tan feliz!$B$BTambién dijo que tendría que recibirte bien cuando vinieras a casa, así que he preparado un poco de té.$B$B¡Espero que te guste con montones de azúcar!', 0);
-- 5724 La vuelta de la cartera perdida
-- https://es.classic.wowhead.com/quest=5724
SET @ID := 5724;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste algo, $n? Nos vendría bien cualquier pista que ayude a explicar por qué un miembro de su clan ha tenido que morir innecesariamente.', 0),
(@ID, 'esMX', '¿Encontraste algo, $n? Nos vendría bien cualquier pista que ayude a explicar por qué un miembro de su clan ha tenido que morir innecesariamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. Gracias.$B$BMagatha me dijo que te entregara esto si encontrabas al miembro de su clan. Por favor, cógelo como muestra de agradecimiento.', 0),
(@ID, 'esMX', 'Excelente, $n. Gracias.$B$BMagatha me dijo que te entregara esto si encontrabas al miembro de su clan. Por favor, cógelo como muestra de agradecimiento.', 0);
