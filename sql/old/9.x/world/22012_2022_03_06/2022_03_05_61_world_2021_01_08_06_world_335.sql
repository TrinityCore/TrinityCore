-- 1389 Cristales draenetistas
-- https://es.classic.wowhead.com/quest=1389
SET @ID := 1389;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los cristales?', 0),
(@ID, 'esMX', '¿Tienes los cristales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estamos en deuda contigo.', 0),
(@ID, 'esMX', 'Gracias, $n. Estamos en deuda contigo.', 0);
-- 1391 El suero de la verdad
-- https://es.classic.wowhead.com/quest=1391
SET @ID := 1391;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por favor, ten piedad de mí! Tengo información que va más allá de los límites de la alianza. Si bien no simpatizo con la Horda, ¡hay una traición política que debe ser revelada!', 0),
(@ID, 'esMX', '¡Por favor, ten piedad de mí! Tengo información que va más allá de los límites de la alianza. Si bien no simpatizo con la Horda, ¡hay una traición política que debe ser revelada!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un trago para mí? Qué amable. Han pasado días desde que me permitieron beber. Déjame beber esto y luego te contaré lo que he averiguado...', 0),
(@ID, 'esMX', '¿Un trago para mí? Qué amable. Han pasado días desde que me permitieron beber. Déjame beber esto y luego te contaré lo que he averiguado...', 0);
-- 1392 Noboru el Garrote
-- https://es.classic.wowhead.com/quest=1392
SET @ID := 1392;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. Bienvenido a El Malecón.', 0),
(@ID, 'esMX', 'Saludos. Bienvenido a El Malecón.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el arma del terrorífico Noboru? ¿Eso quiere decir que está muerto?$B$BEste es un día de júbilo para El Malecón. Noboru y los suyos representaban una seria amenaza para nosotros pues vagaban por los pantanos matando a todos los draenei que se cruzaban en su camino. Sin duda, ponía en peligro nuestra existencia pero nosotros no teníamos la fuerza suficiente para hacerle frente.$B$BSomos afortunados por tenerte como $gamigo:amiga;, $n.', 0),
(@ID, 'esMX', '¿Has conseguido el arma del terrorífico Noboru? ¿Eso quiere decir que está muerto?$B$BEste es un día de júbilo para El Malecón. Noboru y los suyos representaban una seria amenaza para nosotros pues vagaban por los pantanos matando a todos los draenei que se cruzaban en su camino. Sin duda, ponía en peligro nuestra existencia pero nosotros no teníamos la fuerza suficiente para hacerle frente.$B$BSomos afortunados por tenerte como $gamigo:amiga;, $n.', 0);
-- 1393 La huida de Galen
-- https://es.classic.wowhead.com/quest=1393
SET @ID := 1393;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El ojo de la cerradura de esta caja fuerte está llena de resina negra y resulta imposible abrirla.$B$BPero Galen te dijo que había un pasador escondido en la base de la caja fuerte...$B$BTras una búsqueda rápida, localizas el pasador. Lo levantas y la caja fuerte se abre...', 0),
(@ID, 'esMX', 'El ojo de la cerradura de esta caja fuerte está llena de resina negra y resulta imposible abrirla.$B$BPero Galen te dijo que había un pasador escondido en la base de la caja fuerte...$B$BTras una búsqueda rápida, localizas el pasador. Lo levantas y la caja fuerte se abre...', 0);
-- 1394 La recta final
-- https://es.classic.wowhead.com/quest=1394
SET @ID := 1394;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n. Hacía tiempo que no venías por aquí. Parece que hayan pasado muchas lunas desde que diste el primer salto que te inició en tu camino.$B$BY ahora regresas a mí más fuerte de lo que una vez fuiste... y más $gsabio:sabia;. Eso me complace y creo que deberías recibir una recompensa por haber superado mis pruebas.', 0),
(@ID, 'esMX', 'Ah, $n. Hacía tiempo que no venías por aquí. Parece que hayan pasado muchas lunas desde que diste el primer salto que te inició en tu camino.$B$BY ahora regresas a mí más fuerte de lo que una vez fuiste... y más $gsabio:sabia;. Eso me complace y creo que deberías recibir una recompensa por haber superado mis pruebas.', 0);
-- 1418 Neeka Marca de Sangre
-- https://es.classic.wowhead.com/quest=1418
SET @ID := 1418;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que Helgrum quiere un informe? Envié un avanzado a Rocal no hace ni tres días. ¿No cumplió su misión? Si mi informe no ha llegado a Rocal significa que así es.$B$BEsperemos que el siguiente corredor que envíe sea mejor o tenga más suerte.', 0),
(@ID, 'esMX', '¿Así que Helgrum quiere un informe? Envié un avanzado a Rocal no hace ni tres días. ¿No cumplió su misión? Si mi informe no ha llegado a Rocal significa que así es.$B$BEsperemos que el siguiente corredor que envíe sea mejor o tenga más suerte.', 0);
-- 1419 Ladrones coyote
-- https://es.classic.wowhead.com/quest=1419
SET @ID := 1419;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las mandíbulas?', 0),
(@ID, 'esMX', '¿Tienes las mandíbulas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué maravillosa colección de mandíbulas, $n! Esos coyotes ya no destrozarán más nuestras provisiones en busca de comida.$B$BBuen trabajo. Los coyotes de las Tierras Inhóspitas no son una presa fácil. Tus actos demuestran que quizás seas capaz de sobrevivir aquí.', 0),
(@ID, 'esMX', '¡Qué maravillosa colección de mandíbulas, $n! Esos coyotes ya no destrozarán más nuestras provisiones en busca de comida.$B$BBuen trabajo. Los coyotes de las Tierras Inhóspitas no son una presa fácil. Tus actos demuestran que quizás seas capaz de sobrevivir aquí.', 0);
-- 1420 Un informe para Helgrum
-- https://es.classic.wowhead.com/quest=1420
SET @ID := 1420;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¿Tienes algún informe?', 0),
(@ID, 'esMX', 'Has vuelto. ¿Tienes algún informe?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. En el informe de Neeka puedo ver que la Alianza también tiene problemas. Es posible, además, que tengamos enemigos comunes.', 0),
(@ID, 'esMX', 'Gracias, $n. En el informe de Neeka puedo ver que la Alianza también tiene problemas. Es posible, además, que tengamos enemigos comunes.', 0);
-- 1422 La amenaza marítima
-- https://es.classic.wowhead.com/quest=1422
SET @ID := 1422;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Silencio un momento, $c. Incluso por encima del rugir del mar se pueden oír esos horribles gritos de los pescadores.', 0),
(@ID, 'esMX', 'Silencio un momento, $c. Incluso por encima del rugir del mar se pueden oír esos horribles gritos de los pescadores.', 0);
-- 1423 Los suministros perdidos
-- https://es.classic.wowhead.com/quest=1423
SET @ID := 1423;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! ¡Gracias, $n! Se han perdido muchos suministros desde Villa Oscura hasta aquí. Siempre es bueno recuperar parte de ellos.', 0),
(@ID, 'esMX', '¡Ah! ¡Gracias, $n! Se han perdido muchos suministros desde Villa Oscura hasta aquí. Siempre es bueno recuperar parte de ellos.', 0);
-- 1424 Charca de Lágrimas
-- https://es.classic.wowhead.com/quest=1424
SET @ID := 1424;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nadie sabe qué tipo de oscuras prácticas sucedieron en El Templo de Atal\'Hakkar. Pero sí sabemos que se emplearon poderosas fuerzas mágicas.$B$BDebemos descubrir todo lo que podamos sobre esa magia. Quizás los hechizos de los Atal\'ai tengan algún uso para la Horda.$B$BCuando hayas conseguido suficientes artefactos Atal\'ai de la Charca de Lágrimas, podré comenzar a entender lo que pretendían lograr los trols y qué puede haber salido tan horriblemente mal.', 0),
(@ID, 'esMX', 'Nadie sabe qué tipo de oscuras prácticas sucedieron en El Templo de Atal\'Hakkar. Pero sí sabemos que se emplearon poderosas fuerzas mágicas.$B$BDebemos descubrir todo lo que podamos sobre esa magia. Quizás los hechizos de los Atal\'ai tengan algún uso para la Horda.$B$BCuando hayas conseguido suficientes artefactos Atal\'ai de la Charca de Lágrimas, podré comenzar a entender lo que pretendían lograr los trols y qué puede haber salido tan horriblemente mal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu diligencia para conseguir los artefactos Atal\'ai es digna de elogio, $c.', 0),
(@ID, 'esMX', 'Tu diligencia para conseguir los artefactos Atal\'ai es digna de elogio, $c.', 0);
-- 1426 La amenaza marítima
-- https://es.classic.wowhead.com/quest=1426
SET @ID := 1426;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Soy paciente. Paciente y eterno como una vieja piedra kank de Draenor. Los hombres-pez no pasarán nuestras fronteras, no mientras yo esté aquí. Si tuviéramos un ejército a nuestra disposición, limpiaría este mundo y todos los demás de su presencia. Siento mi odio hervir solo de hablar de ellos.', 0),
(@ID, 'esMX', 'Soy paciente. Paciente y eterno como una vieja piedra kank de Draenor. Los hombres-pez no pasarán nuestras fronteras, no mientras yo esté aquí. Si tuviéramos un ejército a nuestra disposición, limpiaría este mundo y todos los demás de su presencia. Siento mi odio hervir solo de hablar de ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El mar semeja inmenso e implacable pero tú lo has teñido con su propia sangre. Los hombres-pez están sufriendo. Tras la devastación que has provocado, su insensatez hará que refuercen sus filas, y eso es bueno.$B$BHaz que sus gritos ahogados resuenen sin cesar. Disfrutaré cada vez que uno de ellos muera.$B$BRegresa a mí si deseas matar a más hombres-pez pues te recompensaré de nuevo con mucho gusto.', 0),
(@ID, 'esMX', 'El mar semeja inmenso e implacable pero tú lo has teñido con su propia sangre. Los hombres-pez están sufriendo. Tras la devastación que has provocado, su insensatez hará que refuercen sus filas, y eso es bueno.$B$BHaz que sus gritos ahogados resuenen sin cesar. Disfrutaré cada vez que uno de ellos muera.$B$BRegresa a mí si deseas matar a más hombres-pez pues te recompensaré de nuevo con mucho gusto.', 0);
-- 1427 La amenaza marítima
-- https://es.classic.wowhead.com/quest=1427
SET @ID := 1427;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, $n, has vuelto! ¡Qué bien! Ya he acabado de fabricar más armas para luchar contra los murlocs. Te ofrezco una para que puedas traernos más carne fresca de denteserras y con ello hacer feliz a Katar.', 0),
(@ID, 'esMX', '¡Ah, $n, has vuelto! ¡Qué bien! Ya he acabado de fabricar más armas para luchar contra los murlocs. Te ofrezco una para que puedas traernos más carne fresca de denteserras y con ello hacer feliz a Katar.', 0);
-- 1428 La amenaza continua
-- https://es.classic.wowhead.com/quest=1428
SET @ID := 1428;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No estaré complacido hasta que el mar y todos sus hijos sean silenciados... especialmente esos repugnantes hombres-pez.', 0),
(@ID, 'esMX', 'No estaré complacido hasta que el mar y todos sus hijos sean silenciados... especialmente esos repugnantes hombres-pez.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $c. Quiero más de su sangre. ¡Acaba con todos los hombres-pez!', 0),
(@ID, 'esMX', 'Bien hecho, $c. Quiero más de su sangre. ¡Acaba con todos los hombres-pez!', 0);
-- 1429 El exiliado Atal'ai
-- https://es.classic.wowhead.com/quest=1429
SET @ID := 1429;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres muy valiente al haber venido aquí. Valiente o imbécil...', 0),
(@ID, 'esMX', 'Eres muy valiente al haber venido aquí. Valiente o imbécil...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes los artefactos de invocación de los Atal\'ai?$B$BVeo que Jammal\'an el Profeta lidera a los discípulos de la Cámara Sangrienta hacia su destino elegido. Me pregunto si Hakkar ha regresado al templo. ¿Han encontrado su destino?', 0),
(@ID, 'esMX', '¿Me traes los artefactos de invocación de los Atal\'ai?$B$BVeo que Jammal\'an el Profeta lidera a los discípulos de la Cámara Sangrienta hacia su destino elegido. Me pregunto si Hakkar ha regresado al templo. ¿Han encontrado su destino?', 0);
-- 1430 Carne fresca
-- https://es.classic.wowhead.com/quest=1430
SET @ID := 1430;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo un barril de vino esperando a que tengas éxito, $n. Es normal que pruebe las mercancías antes de enviárselas a mis clientes.', 0),
(@ID, 'esMX', 'Tengo un barril de vino esperando a que tengas éxito, $n. Es normal que pruebe las mercancías antes de enviárselas a mis clientes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, esto será perfecto. Me muero por probar esto después de haberse cocinado lentamente en la hoguera. Deberías llevarte una muestra para tu viaje. ¡Qué delicia!', 0),
(@ID, 'esMX', 'Ah, esto será perfecto. Me muero por probar esto después de haberse cocinado lentamente en la hoguera. Deberías llevarte una muestra para tu viaje. ¡Qué delicia!', 0);
-- 1431 Las relaciones de la Alianza
-- https://es.classic.wowhead.com/quest=1431
SET @ID := 1431;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, noble $c. Me llamo Keldran, estudioso de la magia y otras artes místicas.$B$BEl asunto por el que vienes a verme requiere sutileza, pero creo que podrás ayudarnos.$B$BSiéntate y escucha por qué necesitamos tu ayuda.$B$BTodo está relacionado con las apariencias, $n, con cómo la Horda se ve a sí misma. Y cómo la ven los enemigos.', 0),
(@ID, 'esMX', 'Saludos, noble $c. Me llamo Keldran, estudioso de la magia y otras artes místicas.$B$BEl asunto por el que vienes a verme requiere sutileza, pero creo que podrás ayudarnos.$B$BSiéntate y escucha por qué necesitamos tu ayuda.$B$BTodo está relacionado con las apariencias, $n, con cómo la Horda se ve a sí misma. Y cómo la ven los enemigos.', 0);
-- 1432 Las relaciones de la Alianza
-- https://es.classic.wowhead.com/quest=1432
SET @ID := 1432;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Veo que traes noticias de Orgrimmar.$B$BLa tierra está ahogada por la infestación demoníaca. Los centauros se consideran dueños de la tierra, pero hay fuerzas que escapan a su control y pueden acabar aplastándolos.$B$BMe disgusta ayudar a los centauros aunque sea indirectamente, pero tengo que pensar en el bien de la Horda, por lo que hago lo que tengo que hacer como Jefe de Guerra, incluso si esto significa ayudar a los brujos dentro de la Horda.', 0),
(@ID, 'esMX', 'Saludos, $c. Veo que traes noticias de Orgrimmar.$B$BLa tierra está ahogada por la infestación demoníaca. Los centauros se consideran dueños de la tierra, pero hay fuerzas que escapan a su control y pueden acabar aplastándolos.$B$BMe disgusta ayudar a los centauros aunque sea indirectamente, pero tengo que pensar en el bien de la Horda, por lo que hago lo que tengo que hacer como Jefe de Guerra, incluso si esto significa ayudar a los brujos dentro de la Horda.', 0);
-- 1433 Las relaciones de la Alianza
-- https://es.classic.wowhead.com/quest=1433
SET @ID := 1433;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre se agradece la ayuda de los leales al Jefe de Guerra.$B$BMe llamo Maurin y estoy aquí a petición de Keldran y de Thrall. Quiero combatir contra los males que acechan a mi jefe.$B$BAcércate, $c, te voy a explicar mi plan para erradicar al Filo Ardiente.', 0),
(@ID, 'esMX', 'Siempre se agradece la ayuda de los leales al Jefe de Guerra.$B$BMe llamo Maurin y estoy aquí a petición de Keldran y de Thrall. Quiero combatir contra los males que acechan a mi jefe.$B$BAcércate, $c, te voy a explicar mi plan para erradicar al Filo Ardiente.', 0);
-- 1434 La contaminación del sátiro
-- https://es.classic.wowhead.com/quest=1434
SET @ID := 1434;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un compañero tauren me advirtió que los sátiros no son todo lo que parecen. Él cree que hay algo más en ellos, que su maldad es una tergiversación de su verdadera naturaleza. Pero no he visto tales cosas.$B$BSolo veo la matanza despiadada de los débiles y la corrupción de aquellos que buscan el poder oscuro.$B$BContinuaré con mi deber de aniquilarlos hasta que el Jefe de Guerra me indique lo contrario. Hasta entonces, no me compadezco de ellos.', 0),
(@ID, 'esMX', 'Un compañero tauren me advirtió que los sátiros no son todo lo que parecen. Él cree que hay algo más en ellos, que su maldad es una tergiversación de su verdadera naturaleza. Pero no he visto tales cosas.$B$BSolo veo la matanza despiadada de los débiles y la corrupción de aquellos que buscan el poder oscuro.$B$BContinuaré con mi deber de aniquilarlos hasta que el Jefe de Guerra me indique lo contrario. Hasta entonces, no me compadezco de ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Admiro el honor y dedicación que has mostrado, $c.$B$BCuando termine la campaña en Desolace, informaré al Jefe de Guerra sobre tus actos y tu ayuda.$B$BGracias.', 0),
(@ID, 'esMX', 'Admiro el honor y dedicación que has mostrado, $c.$B$BCuando termine la campaña en Desolace, informaré al Jefe de Guerra sobre tus actos y tu ayuda.$B$BGracias.', 0);
-- 1435 Los espíritus ardientes
-- https://es.classic.wowhead.com/quest=1435
SET @ID := 1435;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He intentado imbuir hechizos simples. Extraer el espíritu de la víctima de su forma corrupta te será fácil. No confíes en las gemas para aniquilar al enemigo; solo debes activarlas cuando el sujeto esté a punto de morir. De lo contrario, no servirán de nada.', 0),
(@ID, 'esMX', 'He intentado imbuir hechizos simples. Extraer el espíritu de la víctima de su forma corrupta te será fácil. No confíes en las gemas para aniquilar al enemigo; solo debes activarlas cuando el sujeto esté a punto de morir. De lo contrario, no servirán de nada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte. Dame las gemas, las pondré en lugar seguro.$B$BNo tengo más tareas para ti, $c. Ve a ver a Takata cuando hayas descansado; puede que tenga trabajo para ti o que tengas que ir a Orgrimmar para informar a Keldran sobre nuestro progreso aquí, en Desolace.', 0),
(@ID, 'esMX', 'Me alegro de verte. Dame las gemas, las pondré en lugar seguro.$B$BNo tengo más tareas para ti, $c. Ve a ver a Takata cuando hayas descansado; puede que tenga trabajo para ti o que tengas que ir a Orgrimmar para informar a Keldran sobre nuestro progreso aquí, en Desolace.', 0);
-- 1436 Las relaciones de la Alianza
-- https://es.classic.wowhead.com/quest=1436
SET @ID := 1436;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien en Desolace, $n.$B$BGracias por tu esfuerzo, tu tiempo y tu comprensión. Thrall desea que haya paz entre la Horda y la Alianza; ahora que nuestro aspecto es aceptable, evitaremos que haya más violencia.$B$BEstoy en deuda contigo.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien en Desolace, $n.$B$BGracias por tu esfuerzo, tu tiempo y tu comprensión. Thrall desea que haya paz entre la Horda y la Alianza; ahora que nuestro aspecto es aceptable, evitaremos que haya más violencia.$B$BEstoy en deuda contigo.', 0);
-- 1444 Regresa junto a Fel'Zerul
-- https://es.classic.wowhead.com/quest=1444
SET @ID := 1444;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace mucho tiempo que no hablamos, $c. Espero que hayas tenido éxito en tu viaje.$B$B¿Qué conocimiento has obtenido de los exiliados Atal\'ai en las Tierras del Interior?', 0),
(@ID, 'esMX', 'Hace mucho tiempo que no hablamos, $c. Espero que hayas tenido éxito en tu viaje.$B$B¿Qué conocimiento has obtenido de los exiliados Atal\'ai en las Tierras del Interior?', 0);
-- 1445 El Templo de Atal'Hakkar
-- https://es.classic.wowhead.com/quest=1445
SET @ID := 1445;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los fetiches Atal\'ai tienen el poder de invocar a Hakkar y cumplir la profecía de Jammal\'an, tenemos que conseguirlos. ¡La Horda debe descubrir esos poderes!', 0),
(@ID, 'esMX', 'Si los fetiches Atal\'ai tienen el poder de invocar a Hakkar y cumplir la profecía de Jammal\'an, tenemos que conseguirlos. ¡La Horda debe descubrir esos poderes!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Valiente $c, has demostrado ser $gun gran campeón:una gran campeona; de la Horda.$B$BAhora, hay que encargarse de esta colección de fetiches de Hakkar.', 0),
(@ID, 'esMX', 'Valiente $c, has demostrado ser $gun gran campeón:una gran campeona; de la Horda.$B$BAhora, hay que encargarse de esta colección de fetiches de Hakkar.', 0);
-- 1446 Jammal'an el Profeta
-- https://es.classic.wowhead.com/quest=1446
SET @ID := 1446;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando acabes con Jammal\'an podré volver con mi gente.$B$BSi sigue siendo su líder espiritual, los Atal\'ai van directos a la perdición.', 0),
(@ID, 'esMX', 'Cuando acabes con Jammal\'an podré volver con mi gente.$B$BSi sigue siendo su líder espiritual, los Atal\'ai van directos a la perdición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La imprudente fe de Jammal\'an en visiones falsas ha llevado a mi gente a la perdición.$B$BGracias por vengar mi exilio, $c. Estoy de luto por mi gente y mi hogar perdido.', 0),
(@ID, 'esMX', 'La imprudente fe de Jammal\'an en visiones falsas ha llevado a mi gente a la perdición.$B$BGracias por vengar mi exilio, $c. Estoy de luto por mi gente y mi hogar perdido.', 0);
-- 1463 Sapta de tierra
-- https://es.classic.wowhead.com/quest=1463
SET @ID := 1463;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te daré una de muy buena fe. Ya has probado tu valía en una ocasión, pero deberías tener más cuidado en el futuro.', 0),
(@ID, 'esMX', 'Te daré una de muy buena fe. Ya has probado tu valía en una ocasión, pero deberías tener más cuidado en el futuro.', 0);
-- 1464 La sapta de fuego
-- https://es.classic.wowhead.com/quest=1464
SET @ID := 1464;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Habla con Telf Joolam para conseguir otra sapta de fuego.', 0),
(@ID, 'esMX', 'Habla con Telf Joolam para conseguir otra sapta de fuego.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que el fuego arda en tu corazón, $n.$B$BLos elementos te esperan.', 0),
(@ID, 'esMX', 'Que el fuego arda en tu corazón, $n.$B$BLos elementos te esperan.', 0);
-- 1470 Descubrir el misterio
-- https://es.classic.wowhead.com/quest=1470
SET @ID := 1470;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu poder es pequeño ahora, aunque sospecho que ya percibes las posibilidades.$B$BIncluso los muertos pueden sentirse vivos, con ese poder atravesándonos.', 0),
(@ID, 'esMX', 'Tu poder es pequeño ahora, aunque sospecho que ya percibes las posibilidades.$B$BIncluso los muertos pueden sentirse vivos, con ese poder atravesándonos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque todavía no has sido $gprobado:probada; y eres joven en tu aprendizaje, has demostrado que posees la capacidad suficiente para dominar la invocación y atadura de un diablillo. No te dejes engañar por el tamaño de un diablillo. Aunque carece de fuerza física, posee poderes y una inteligencia que te servirán de mucho.$B$BEscúchame con atención, $n, porque no repetiré esta lección y te dejaré el dominio a ti.', 0),
(@ID, 'esMX', 'Aunque todavía no has sido $gprobado:probada; y eres joven en tu aprendizaje, has demostrado que posees la capacidad suficiente para dominar la invocación y atadura de un diablillo. No te dejes engañar por el tamaño de un diablillo. Aunque carece de fuerza física, posee poderes y una inteligencia que te servirán de mucho.$B$BEscúchame con atención, $n, porque no repetiré esta lección y te dejaré el dominio a ti.', 0);
-- 1471 El vínculo
-- https://es.classic.wowhead.com/quest=1471
SET @ID := 1471;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero saber de tu éxito, $n. No cumplir con mis expectativas será la menor de tus preocupaciones, sin embargo, si fallas...', 0),
(@ID, 'esMX', 'Espero saber de tu éxito, $n. No cumplir con mis expectativas será la menor de tus preocupaciones, sin embargo, si fallas...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Ahora, te enseñaré el hechizo utilizado para convocar al abisario.$B$BEl poder que desató sobre ti ahora es tuyo. Úsalo con sabiduría.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Ahora, te enseñaré el hechizo utilizado para convocar al abisario.$B$BEl poder que desató sobre ti ahora es tuyo. Úsalo con sabiduría.', 0);
-- 1472 Devoradora de almas
-- https://es.classic.wowhead.com/quest=1472
SET @ID := 1472;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ha enviado Carendin? $n.$B$BNo pienses en mí a la ligera porque mi vista se ha ido. Ahora veo las cosas que quedan atrás, con una claridad que nunca había conocido. Lo que una vez pensé que era una maldición, ahora es una bendición.', 0),
(@ID, 'esMX', '¿Te ha enviado Carendin? $n.$B$BNo pienses en mí a la ligera porque mi vista se ha ido. Ahora veo las cosas que quedan atrás, con una claridad que nunca había conocido. Lo que una vez pensé que era una maldición, ahora es una bendición.', 0);
-- 1473 Criatura Abisal
-- https://es.classic.wowhead.com/quest=1473
SET @ID := 1473;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Egalin fue el maestro que me enseñó. Con apenas una mirada, pudo comandar al abisario que había convocado.$B$BCuando llegó mi turno de intentarlo, estaba demasiado confiado. No juegues con los poderes que tienes, $n, pueden consumir incluso a los vigilantes.', 0),
(@ID, 'esMX', 'Egalin fue el maestro que me enseñó. Con apenas una mirada, pudo comandar al abisario que había convocado.$B$BCuando llegó mi turno de intentarlo, estaba demasiado confiado. No juegues con los poderes que tienes, $n, pueden consumir incluso a los vigilantes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, esto es excelente. Perrine ignoraba el verdadero poder del libro mohoso que nos había robado.$B$BNo volverá a alejarse de nuestras manos. Observa, $n, la estructura del hechizo, la forma en que tu poder debe ser canalizado.', 0),
(@ID, 'esMX', 'Ah, esto es excelente. Perrine ignoraba el verdadero poder del libro mohoso que nos había robado.$B$BNo volverá a alejarse de nuestras manos. Observa, $n, la estructura del hechizo, la forma en que tu poder debe ser canalizado.', 0);
 -- 1476 Corazones puros
-- https://es.classic.wowhead.com/quest=1476
SET @ID := 1476;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me ha sorprendido gratamente el ritmo de tu progreso hasta ahora, $n. Tráeme los corazones y me volverás a impresionar.', 0),
(@ID, 'esMX', 'Me ha sorprendido gratamente el ritmo de tu progreso hasta ahora, $n. Tráeme los corazones y me volverás a impresionar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El corazón de un buen hombre se parece mucho al de cualquier otro, cuando lo ves así, ¿no crees?$B$BQuizás tenemos algo de... diferente... punto de vista sobre el tema. Sin embargo, estos servirán. No tengo ninguna duda de que una súcubo se sentiría atraída por su pureza.', 0),
(@ID, 'esMX', 'El corazón de un buen hombre se parece mucho al de cualquier otro, cuando lo ves así, ¿no crees?$B$BQuizás tenemos algo de... diferente... punto de vista sobre el tema. Sin embargo, estos servirán. No tengo ninguna duda de que una súcubo se sentiría atraída por su pureza.', 0);
