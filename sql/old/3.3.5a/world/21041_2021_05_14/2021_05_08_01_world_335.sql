-- 9504 La llamada del agua
-- https://es.wowhead.com/quest=9504
SET @ID := 9504;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el agua pura de las ruinas?', 0),
(@ID, 'esMX', '¿Tienes el agua pura de las ruinas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las piezas son fáciles, pero junta las suficientes y crearás una fuerza imparable. Lava la tierra y el fuego, y fácilmente empuja el aire fuera del camino.$B$B¡Somos esa fuerza imparable, $n, no los que han envenenado la Isla Bruma de Sangre!', 0),
(@ID, 'esMX', 'Las piezas son fáciles, pero junta las suficientes y crearás una fuerza imparable. Lava la tierra y el fuego, y fácilmente empuja el aire fuera del camino.$B$B¡Somos esa fuerza imparable, $n, no los que han envenenado la Isla Bruma de Sangre!', 0);
-- 9505 La profecía de Velen
-- https://es.wowhead.com/quest=9505
SET @ID := 9505;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que has encontrado a una de los nuestros y que está herida? ¡Enviaré a alguien de inmediato!', 0),
(@ID, 'esMX', '¿Dices que has encontrado a una de los nuestros y que está herida? ¡Enviaré a alguien de inmediato!', 0);
-- 9506 Un pequeño susto
-- https://es.wowhead.com/quest=9506
SET @ID := 9506;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte?', 0),
(@ID, 'esMX', '¿Ha habido suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí que eres eficiente! Ahora que tenemos el equipamiento de navegación, podemos calcular cuánto nos hemos desviado de nuestro rumbo.$B$BPero, espera. ¿Qué es esto? Hay algo enrollado en el mapa. A ver...$B$BSon órdenes de Mogul Razdunk de Ventura y Cía. Según estos planes, están aquí para explotar a cielo abierto la isla y hacerse con el cristal. Y cuando hayan acabado, robar nuestros barcos.$B$B¡Por la ceja peluda de Barbabronce! ¿Por eso nos obligaron a tocar tierra? ¿Cómo conocían nuestros planes?$B$BMe huele a traidor...', 0),
(@ID, 'esMX', '¡Sí que eres eficiente! Ahora que tenemos el equipamiento de navegación, podemos calcular cuánto nos hemos desviado de nuestro rumbo.$B$BPero, espera. ¿Qué es esto? Hay algo enrollado en el mapa. A ver...$B$BSon órdenes de Mogul Razdunk de Ventura y Cía. Según estos planes, están aquí para explotar a cielo abierto la isla y hacerse con el cristal. Y cuando hayan acabado, robar nuestros barcos.$B$B¡Por la ceja peluda de Barbabronce! ¿Por eso nos obligaron a tocar tierra? ¿Cómo conocían nuestros planes?$B$BMe huele a traidor...', 0);
-- 9508 La llamada del agua
-- https://es.wowhead.com/quest=9508
SET @ID := 9508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has logrado?', 0),
(@ID, 'esMX', '¿Lo has logrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Entonces está hecho! La crisis se ha evitado y habéis puesto en marcha la restauración del agua en Isla Bruma de Sangre. Con el tiempo, el agua, junto con los otros elementos, se curará a sí misma.$B$B¡Es lamentable que los elfos de sangre no puedan ver que al contaminar su entorno también se están matando a sí mismos!', 0),
(@ID, 'esMX', '¡Entonces está hecho! La crisis se ha evitado y habéis puesto en marcha la restauración del agua en Isla Bruma de Sangre. Con el tiempo, el agua, junto con los otros elementos, se curará a sí misma.$B$B¡Es lamentable que los elfos de sangre no puedan ver que al contaminar su entorno también se están matando a sí mismos!', 0);
-- 9509 La llamada del agua
-- https://es.wowhead.com/quest=9509
SET @ID := 9509;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los elementos me han hablado de las grandes hazañas que has realizado. Ven, hablemos.', 0),
(@ID, 'esMX', 'Los elementos me han hablado de las grandes hazañas que has realizado. Ven, hablemos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te has comportado con sabiduría más allá de tus años, $n. Puedo sentir que el elemento agua está complacido con tus acciones. Será un gran honor para mí tomar el agua pura que llevas y combinar su esencia en tu nuevo tótem de agua.$B$BRecuerde bien las lecciones del agua a medida que avanzas y obtendrás una mayor comprensión y dominio del elemento.', 0),
(@ID, 'esMX', 'Te has comportado con sabiduría más allá de tus años, $n. Puedo sentir que el elemento agua está complacido con tus acciones. Será un gran honor para mí tomar el agua pura que llevas y combinar su esencia en tu nuevo tótem de agua.$B$BRecuerde bien las lecciones del agua a medida que avanzas y obtendrás una mayor comprensión y dominio del elemento.', 0);
-- 9512 El jumbo gumbo de Cocinitas
-- https://es.wowhead.com/quest=9512
SET @ID := 9512;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Argh! ¡Toma! ¡Voto a bríos! Este... lo siento, $gamigo:amiga;, tengo que practicar mis piraterías o las olvidaré...', 0),
(@ID, 'esMX', '¡Argh! ¡Toma! ¡Voto a bríos! Este... lo siento, $gamigo:amiga;, tengo que practicar mis piraterías o las olvidaré...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bendito sea tu corazón, $gforastero:forastera;. Esto \'stará muy bien pa\' levantar la moral de la tripulación.', 0),
(@ID, 'esMX', 'Bendito sea tu corazón, $gforastero:forastera;. Esto \'stará muy bien pa\' levantar la moral de la tripulación.', 0);
-- 9513 Recuperar las ruinas
-- https://es.wowhead.com/quest=9513
SET @ID := 9513;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haces algo bueno por mi gente, $n.', 0),
(@ID, 'esMX', 'Haces algo bueno por mi gente, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alabada sea Elune! Los espíritus inquietos podrían encontrar la paz después de todo.', 0),
(@ID, 'esMX', '¡Alabada sea Elune! Los espíritus inquietos podrían encontrar la paz después de todo.', 0);
-- 9514 Tablilla cubierta de runas
-- https://es.wowhead.com/quest=9514
SET @ID := 9514;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algo?', 0),
(@ID, 'esMX', '¿Has encontrado algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sé leer estas runas, pero conozco a alguien que sí sabe.', 0),
(@ID, 'esMX', 'No sé leer estas runas, pero conozco a alguien que sí sabe.', 0);
-- 9515 Señor de la guerra Sriss'tiz
-- https://es.wowhead.com/quest=9515
SET @ID := 9515;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Permanece en guardia!', 0),
(@ID, 'esMX', '¡Permanece en guardia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con el señor de la guerra Sriss\'tiz muerto, la posibilidad de una invasión naga es ahora solo un lejano recuerdo. Estamos a salvo, por ahora...$B$BDebo reconocerlo, me equivoqué al pensar mal de ti, $n. Has demostrado que no tienes nada que ver con esa escoria de Archimonde. Acepta este regalo de los elfos de la noche.', 0),
(@ID, 'esMX', 'Con el señor de la guerra Sriss\'tiz muerto, la posibilidad de una invasión naga es ahora solo un lejano recuerdo. Estamos a salvo, por ahora...$B$BDebo reconocerlo, me equivoqué al pensar mal de ti, $n. Has demostrado que no tienes nada que ver con esa escoria de Archimonde. Acepta este regalo de los elfos de la noche.', 0);
-- 9516 Destruye a la Legión
-- https://es.wowhead.com/quest=9516
SET @ID := 9516;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hay demonios todavía en pie?', 0),
(@ID, 'esMX', '¿Hay demonios todavía en pie?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi respeto y agradecimiento, $n. Quizás podamos crear un nuevo hogar aquí sin tener que preocuparnos por la Legión Ardiente una vez más.', 0),
(@ID, 'esMX', 'Tienes mi respeto y agradecimiento, $n. Quizás podamos crear un nuevo hogar aquí sin tener que preocuparnos por la Legión Ardiente una vez más.', 0);
-- 9517 ¡Sería una lástima desperdiciarlo!
-- https://es.wowhead.com/quest=9517
SET @ID := 9517;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El anciano cruje cuando se vuelve hacia ti.>$B$BEl arquitecto Nemos dijo que podrías estar trayendo madera recuperada del aserradero de los deforestadores y de la sucia Satyrnaar.', 0),
(@ID, 'esMX', '<El anciano cruje cuando se vuelve hacia ti.>$B$BEl arquitecto Nemos dijo que podrías estar trayendo madera recuperada del aserradero de los deforestadores y de la sucia Satyrnaar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La madera cortada con las toscas hojas de los orcos está deformada con tanta seguridad como la expuesta a extremos elementales. No se puede construir ningún sonido con ella, pero la purificaré y se la devolveré al arquitecto Nemos y sus hombres para su uso. Algo bueno saldrá de esta tragedia, después de todo.', 0),
(@ID, 'esMX', 'La madera cortada con las toscas hojas de los orcos está deformada con tanta seguridad como la expuesta a extremos elementales. No se puede construir ningún sonido con ella, pero la purificaré y se la devolveré al arquitecto Nemos y sus hombres para su uso. Algo bueno saldrá de esta tragedia, después de todo.', 0);
-- 9518 Agentes de destrucción
-- https://es.wowhead.com/quest=9518
SET @ID := 9518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras viva el Sobrestante Gorthak, me opondré a él. ¿Qué noticias traes del campamento maderero?', 0),
(@ID, 'esMX', 'Mientras viva el Sobrestante Gorthak, me opondré a él. ¿Qué noticias traes del campamento maderero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin hemos enviado un mensaje que los orcos no se atreverán a ignorar. ¡Cualquier sobrestante o capataz que ponga un pie en el campamento para reemplazar a Gorthak sentirá mi ira!$B$BDebemos aprovechar nuestra ventaja, $n, y nunca descansar hasta que el Aserradero Grito de Guerra sea un recuerdo lejano y un claro de árboles se alce sobre ese terreno.', 0),
(@ID, 'esMX', 'Por fin hemos enviado un mensaje que los orcos no se atreverán a ignorar. ¡Cualquier sobrestante o capataz que ponga un pie en el campamento para reemplazar a Gorthak sentirá mi ira!$B$BDebemos aprovechar nuestra ventaja, $n, y nunca descansar hasta que el Aserradero Grito de Guerra sea un recuerdo lejano y un claro de árboles se alce sobre ese terreno.', 0);
-- 9519 El cáliz perdido
-- https://es.wowhead.com/quest=9519
SET @ID := 9519;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿Puedes sentir el toque de corrupción en el viento? Si no hacemos nada, seguirá avanzando. Por eso busco el Cáliz de Elune. ¿Pudiste encontrarlo?', 0),
(@ID, 'esMX', '$n, ¿Puedes sentir el toque de corrupción en el viento? Si no hacemos nada, seguirá avanzando. Por eso busco el Cáliz de Elune. ¿Pudiste encontrarlo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Ciertamente hay un poder latente aquí, uno que ni siquiera la exposición constante a la corrupción del sátiro puede atenuar. ¿Ves cómo sigue brillando después de todos estos años?', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Ciertamente hay un poder latente aquí, uno que ni siquiera la exposición constante a la corrupción del sátiro puede atenuar. ¿Ves cómo sigue brillando después de todos estos años?', 0);
-- 9520 Planes diabólicos
-- https://es.wowhead.com/quest=9520
SET @ID := 9520;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $gseñor:señora;?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $gseñor:señora;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por los Siete Cristales de Ata\'mal, esto no puede ser! ¡¿Planean atacarnos aquí en Canción del Bosque?!$B$B¡No en mi turno!$B$B<El vindicador Vedaar arruga los planos garabateados por los demonios en su puño.>$B$BNo. ¡No permitiremos que esto suceda!', 0),
(@ID, 'esMX', '¡Por los Siete Cristales de Ata\'mal, esto no puede ser! ¡¿Planean atacarnos aquí en Canción del Bosque?!$B$B¡No en mi turno!$B$B<El vindicador Vedaar arruga los planos garabateados por los demonios en su puño.>$B$BNo. ¡No permitiremos que esto suceda!', 0);
-- 9521 Informe del frente norte
-- https://es.wowhead.com/quest=9521
SET @ID := 9521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es lo que tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué es lo que tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por entregar este informe, $n. Por lo que escribe la Centinela Luciel, parece que nuestros peores temores se han cumplido. Con cada avance que hacemos, la Horda parece más decidida a hacer el mayor daño posible.$B$BNo podemos darnos el lujo de dar marcha atrás; el destino de nuestras tierras ancestrales está en juego. Con más gente como tú en primera línea, estoy segura de que podríamos triunfar. ¿Te unirás a nuestra lucha?', 0),
(@ID, 'esMX', 'Gracias por entregar este informe, $n. Por lo que escribe la Centinela Luciel, parece que nuestros peores temores se han cumplido. Con cada avance que hacemos, la Horda parece más decidida a hacer el mayor daño posible.$B$BNo podemos darnos el lujo de dar marcha atrás; el destino de nuestras tierras ancestrales está en juego. Con más gente como tú en primera línea, estoy segura de que podríamos triunfar. ¿Te unirás a nuestra lucha?', 0);
-- 9522 ¡Nunca más!
-- https://es.wowhead.com/quest=9522
SET @ID := 9522;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros exploradores elfos de la noche informan que los preparativos para el ataque aún pueden estar en curso. ¡Esos señores del terror deben morir pronto, $n!', 0),
(@ID, 'esMX', 'Nuestros exploradores elfos de la noche informan que los preparativos para el ataque aún pueden estar en curso. ¡Esos señores del terror deben morir pronto, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca más la Legión Ardiente nos amenazará aquí! Nos has librado de una pelea que probablemente hubiéramos perdido, $n.$B$BTe doy las gracias y el más profundo agradecimiento de la Mano de Argus. Me honra tenerte a nuestro lado.', 0),
(@ID, 'esMX', '¡Nunca más la Legión Ardiente nos amenazará aquí! Nos has librado de una pelea que probablemente hubiéramos perdido, $n.$B$BTe doy las gracias y el más profundo agradecimiento de la Mano de Argus. Me honra tenerte a nuestro lado.', 0);
-- 9523 Material frágil y valioso, manipúlese con cuidado
-- https://es.wowhead.com/quest=9523
SET @ID := 9523;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No vuelvas sin algunas de las antiguas reliquias.', 0),
(@ID, 'esMX', 'No vuelvas sin algunas de las antiguas reliquias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mi papá estaría orgulloso! Exitazo de su niño en su primer encuentro con los elfos de la noche... Con tu ayuda, claro. Sí, no te preocupes, no te dejaré fuera del hallazgo. Te llamabas $n, ¿no? Lo sabrán todo de ti en Forjaz.', 0),
(@ID, 'esMX', '¡Mi papá estaría orgulloso! Exitazo de su niño en su primer encuentro con los elfos de la noche... Con tu ayuda, claro. Sí, no te preocupes, no te dejaré fuera del hallazgo. Te llamabas $n, ¿no? Lo sabrán todo de ti en Forjaz.', 0);
-- 9524 Encarcelados en la Ciudadela
-- https://es.wowhead.com/quest=9524
SET @ID := 9524;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Capitana Alina rescatada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Debo admitir que no esperaba que un grupo de rescate estuviera en camino.$B$BReuniré a los prisioneros restantes y los llevaré de regreso al Bastión del Honor.', 0),
(@ID, 'esMX', 'Gracias, $n. Debo admitir que no esperaba que un grupo de rescate estuviera en camino.$B$BReuniré a los prisioneros restantes y los llevaré de regreso al Bastión del Honor.', 0);
-- 9525 Encarcelados en la Ciudadela
-- https://es.wowhead.com/quest=9525
SET @ID := 9525;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Capitán Triturahuesos rescatado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has iluminado mi día, $n. Cuando muera, me aseguraré de que esté en el campo de batalla... cubierto con la sangre de mis oponentes y llevándolos conmigo.', 0),
(@ID, 'esMX', 'Has iluminado mi día, $n. Cuando muera, me aseguraré de que esté en el campo de batalla... cubierto con la sangre de mis oponentes y llevándolos conmigo.', 0);
-- 9526 Recuperar el Cerro Lumbrevil
-- https://es.wowhead.com/quest=9526
SET @ID := 9526;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Semillas de árbol plantadas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Seguro que todavía no has plantado todas mis semillas?', 0),
(@ID, 'esMX', '¿Seguro que todavía no has plantado todas mis semillas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien. Aunque puede que pasen muchos años antes de que las plántulas se conviertan en ancestros, con el tiempo nos ayudarán en nuestra lucha contra los demonios en Cerro Lumbrevil.$B$BVete en paz, $ghermano pequeño:hermana pequeña;.', 0),
(@ID, 'esMX', 'Bien. Aunque puede que pasen muchos años antes de que las plántulas se conviertan en ancestros, con el tiempo nos ayudarán en nuestra lucha contra los demonios en Cerro Lumbrevil.$B$BVete en paz, $ghermano pequeño:hermana pequeña;.', 0);
-- 9527 Solo quedan los restos
-- https://es.wowhead.com/quest=9527
SET @ID := 9527;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi esposa se llamaba Thalrisa y mi hija, Magwin.', 0),
(@ID, 'esMX', 'Mi esposa se llamaba Thalrisa y mi hija, Magwin.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Por fin sus espíritus descansarán ahora.', 0),
(@ID, 'esMX', 'Gracias, $n. Por fin sus espíritus descansarán ahora.', 0);
-- 9527 Solo quedan los restos
-- https://es.wowhead.com/quest=9527
SET @ID := 9527;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi esposa se llamaba Thalrisa y mi hija, Magwin.', 0),
(@ID, 'esMX', 'Mi esposa se llamaba Thalrisa y mi hija, Magwin.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Por fin sus espíritus descansarán ahora.', 0),
(@ID, 'esMX', 'Gracias, $n. Por fin sus espíritus descansarán ahora.', 0);
-- 9528 Una llamada de socorro
-- https://es.wowhead.com/quest=9528
SET @ID := 9528;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Salve, $n.', 0),
(@ID, 'esMX', 'Salve, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Lágrimas de alegría resbalan por el rostro de Cowlen.>$B$B¿Cómo puedo recompensarte por esto, $n? Te lo ruego, acepta esta reliquia. Simboliza un vínculo sagrado de amistad, confianza y amor entre los elfos de la noche. Desde ahora y hasta el final de los días, eres $gun hermano:una hermana; para mí.', 0),
(@ID, 'esMX', '<Lágrimas de alegría resbalan por el rostro de Cowlen.>$B$B¿Cómo puedo recompensarte por esto, $n? Te lo ruego, acepta esta reliquia. Simboliza un vínculo sagrado de amistad, confianza y amor entre los elfos de la noche. Desde ahora y hasta el final de los días, eres $gun hermano:una hermana; para mí.', 0);
-- 9530 Hay un traidor
-- https://es.wowhead.com/quest=9530
SET @ID := 9530;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me encanta cuando un plan va saliendo...', 0),
(@ID, 'esMX', 'Me encanta cuando un plan va saliendo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo avisarte, lo siguiente que voy a pedirte será peligroso. No bajará mi estima por ti si decides no ayudarme, $n.', 0),
(@ID, 'esMX', 'Debo avisarte, lo siguiente que voy a pedirte será peligroso. No bajará mi estima por ti si decides no ayudarme, $n.', 0);
-- 9531 En compañía de árboles
-- https://es.wowhead.com/quest=9531
SET @ID := 9531;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Se descubre el traidor', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ese traidor deseará no haberse metido con el Mando Naval de la Alianza!', 0),
(@ID, 'esMX', '¡Ese traidor deseará no haberse metido con el Mando Naval de la Alianza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No lo puedo creer! Todo era cosa de los gnomos... ¡Tendría que haberlo sospechado!', 0),
(@ID, 'esMX', '¡No lo puedo creer! Todo era cosa de los gnomos... ¡Tendría que haberlo sospechado!', 0);
-- 9532 Encuentra a Keltus Hojaoscura
-- https://es.wowhead.com/quest=9532
SET @ID := 9532;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que puedas ver que estoy muy a cubierto... al menos lo estaba.', 0),
(@ID, 'esMX', 'Espero que puedas ver que estoy muy a cubierto... al menos lo estaba.', 0);
-- 9534 Destruye a la Legión
-- https://es.wowhead.com/quest=9534
SET @ID := 9534;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hay demonios todavía en pie? ¿Te llamas $r? ¡No es momento de tomarse un descanso de la lucha!', 0),
(@ID, 'esMX', '¿Hay demonios todavía en pie? ¿Te llamas $r? ¡No es momento de tomarse un descanso de la lucha!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso está mejor! No hay nada como librar a nuestro mundo de un demonio. Y también son dignos oponentes, a diferencia de las débiles razas de la Alianza.', 0),
(@ID, 'esMX', '¡Eso está mejor! No hay nada como librar a nuestro mundo de un demonio. Y también son dignos oponentes, a diferencia de las débiles razas de la Alianza.', 0);
-- 9535 Planes diabólicos
-- https://es.wowhead.com/quest=9535
SET @ID := 9535;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $gexplorador:exploradora;?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $gexplorador:exploradora;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Señores del terror! ¡¿Planean atacarnos aquí en Puesto del Hachazo?!$B$B¡No mientras aún respire!$B$B<Valusha arruga los planos garabateados por los demonios en su puño.>$B$BNo. ¡No permitiremos que esto suceda! ¡Son una plaga para nuestro mundo!', 0),
(@ID, 'esMX', '¡Señores del terror! ¡¿Planean atacarnos aquí en Puesto del Hachazo?!$B$B¡No mientras aún respire!$B$B<Valusha arruga los planos garabateados por los demonios en su puño.>$B$BNo. ¡No permitiremos que esto suceda! ¡Son una plaga para nuestro mundo!', 0);
-- 9536 ¡Nunca más!
-- https://es.wowhead.com/quest=9536
SET @ID := 9536;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esos señores del terror deben morir pronto, $n!', 0),
(@ID, 'esMX', '¡Esos señores del terror deben morir pronto, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca más la Legión Ardiente convertirá en esclavos a los orcos ni a ninguna otra raza de la Horda!$B$B¡Has luchado con valentía, $n! ¡Tienes el verdadero corazón de la Horda latiendo dentro de ti! ¡Nos das mucho honor!', 0),
(@ID, 'esMX', '¡Nunca más la Legión Ardiente convertirá en esclavos a los orcos ni a ninguna otra raza de la Horda!$B$B¡Has luchado con valentía, $n! ¡Tienes el verdadero corazón de la Horda latiendo dentro de ti! ¡Nos das mucho honor!', 0);
-- 9537 Justicia para el gnomo
-- https://es.wowhead.com/quest=9537
SET @ID := 9537;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste a ese bellaco mentiroso?', 0),
(@ID, 'esMX', '¿Encontraste a ese bellaco mentiroso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¡Todo esto formaba parte de su plan!$B$BDebemos informar al Rey y a tus jefes; las implicaciones son asombrosas.', 0),
(@ID, 'esMX', '¡Increíble! ¡Todo esto formaba parte de su plan!$B$BDebemos informar al Rey y a tus jefes; las implicaciones son asombrosas.', 0);
-- 9538 Aprendizaje de idiomas
-- https://es.wowhead.com/quest=9538
SET @ID := 9538;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oyes un tarareo en tono grave que emana del tótem.', 0),
(@ID, 'esMX', 'Oyes un tarareo en tono grave que emana del tótem.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra A-K-I-D-A.', 0),
(@ID, 'esMX', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra A-K-I-D-A.', 0);
-- 9539 El Tótem de Coo
-- https://es.wowhead.com/quest=9539
SET @ID := 9539;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra C-O-O.', 0),
(@ID, 'esMX', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra C-O-O.', 0);
-- 9540 El Tótem de Tikti
-- https://es.wowhead.com/quest=9540
SET @ID := 9540;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra T-I-K-T-I.', 0),
(@ID, 'esMX', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra T-I-K-T-I.', 0);
-- 9541 El Tótem de Yor
-- https://es.wowhead.com/quest=9541
SET @ID := 9541;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra Y-O-R.', 0),
(@ID, 'esMX', 'El tótem tiene varias marcas primarias. En la superficie se ven grabados de búhos, osos y venados.$B$BObservas una extraña serie de símbolos que hacen que tu boca forme la palabra Y-O-R.', 0);
-- 9542 El Tótem de Vark
-- https://es.wowhead.com/quest=9542
SET @ID := 9542;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que lees el tótem, tus labios forman la palabra V-A-R-K. Entiendes que esto significa justicia.', 0),
(@ID, 'esMX', 'A medida que lees el tótem, tus labios forman la palabra V-A-R-K. Entiendes que esto significa justicia.', 0);
-- 9543 Expiación
-- https://es.wowhead.com/quest=9543
SET @ID := 9543;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte en algo, $n? Parece que algo te perturba.', 0),
(@ID, 'esMX', '¿Puedo ayudarte en algo, $n? Parece que algo te perturba.', 0);
-- 9544 La profecía de Akida
-- https://es.wowhead.com/quest=9544
SET @ID := 9544;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cautivo Semprepino liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '[Fúrbolg] Entonces la profecía de Akida es cierta... Se nos ha entregado $gun héroe:una heroína;.', 0),
(@ID, 'esMX', '[Fúrbolg] Entonces la profecía de Akida es cierta... Se nos ha entregado $gun héroe:una heroína;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '[Fúrbolg] La profecía hablaba de alguien que se levantaría y nos liberaría de nuestra opresión de los Brazolanudo, que los mismísimos espíritus anunciarían la llegada de $geste héroe:esta heroína;.$B$BY ahora has venido.$B$BMe inclino humildemente ante ti, $gmagno:magna;.', 0),
(@ID, 'esMX', '[Fúrbolg] La profecía hablaba de alguien que se levantaría y nos liberaría de nuestra opresión de los Brazolanudo, que los mismísimos espíritus anunciarían la llegada de $geste héroe:esta heroína;.$B$BY ahora has venido.$B$BMe inclino humildemente ante ti, $gmagno:magna;.', 0);
