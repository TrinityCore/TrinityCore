-- 6901 Lanzar el ataque
-- https://es.classic.wowhead.com/quest=6901
SET @ID := 6901;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya es hora! ¡Ahora podemos mostrarle a la Alianza su locura al venir al Valle de Alterac!', 0),
(@ID, 'esMX', '¡Ya es hora! ¡Ahora podemos mostrarle a la Alianza su locura al venir al Valle de Alterac!', 0);
-- 6921 Entre ruinas
-- https://es.classic.wowhead.com/quest=6921
SET @ID := 6921;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido encontrar el núcleo de las profundidades? Sin él no tendremos ni idea de qué anda tramando el Martillo Crepuscular por aquí.', 0),
(@ID, 'esMX', '¿Has conseguido encontrar el núcleo de las profundidades? Sin él no tendremos ni idea de qué anda tramando el Martillo Crepuscular por aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es exactamente lo que necesito. Un núcleo de las profundidades es un pozo de información que nos reportará muchas cosas buenas. Sea lo que sea lo que el Martillo Crepuscular está tramando ahí dentro, y seguro que no puede ser nada bueno, mis camaradas lo descubrirán.$B$BLo has hecho muy bien hoy; el Anillo de la Tierra te mira con cariño por ayudarnos. Además has ayudado al conjunto de la Horda y eso es algo que debería enorgullecerte.', 0),
(@ID, 'esMX', 'Esto es exactamente lo que necesito. Un núcleo de las profundidades es un pozo de información que nos reportará muchas cosas buenas. Sea lo que sea lo que el Martillo Crepuscular está tramando ahí dentro, y seguro que no puede ser nada bueno, mis camaradas lo descubrirán.$B$BLo has hecho muy bien hoy; el Anillo de la Tierra te mira con cariño por ayudarnos. Además has ayudado al conjunto de la Horda y eso es algo que debería enorgullecerte.', 0);
-- 6922 Barón Aquanis
-- https://es.classic.wowhead.com/quest=6922
SET @ID := 6922;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eh, hola otra vez, $n. Yo por aquí, leyendo las olas, el mar, lo de siempre, vamos. ¿Qué te trae por la avanzada?', 0),
(@ID, 'esMX', 'Eh, hola otra vez, $n. Yo por aquí, leyendo las olas, el mar, lo de siempre, vamos. ¿Qué te trae por la avanzada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto... esto es un hallazgo, $n.$B$B¿Y dices que lo conseguiste del barón Aquanis en Brazanegra? Hace tiempo que se cree que el barón Aquanis es un poder elemental corrupto; este globo demostrará qué fue exactamente lo que lo corrompió. Aunque no nos sorprendería que resultara ser el Martillo Crepuscular, nuestros estudios revelarán también cómo lo hicieron.$B$BHas hecho bien en traerme esto. Te lo ruego, llévale esto junto con los mejores deseos del Anillo de la Tierra.', 0),
(@ID, 'esMX', 'Esto... esto es un hallazgo, $n.$B$B¿Y dices que lo conseguiste del barón Aquanis en Brazanegra? Hace tiempo que se cree que el barón Aquanis es un poder elemental corrupto; este globo demostrará qué fue exactamente lo que lo corrompió. Aunque no nos sorprendería que resultara ser el Martillo Crepuscular, nuestros estudios revelarán también cómo lo hicieron.$B$BHas hecho bien en traerme esto. Te lo ruego, llévale esto junto con los mejores deseos del Anillo de la Tierra.', 0);
-- 6941 La llamada del aire: la flota de Vipore
-- https://es.classic.wowhead.com/quest=6941
SET @ID := 6941;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hay que ocuparse de las unidades de élite de los Lobo Gélido que vigilan las líneas, soldado! Te encargo que diezmes a esa manada de salvajes. Vuelve aquí con las medallas de sus tenientes y legionarios. Cuando me parezca que hemos despachado a suficiente chusma, desplegaré la fuerza aérea.', 0),
(@ID, 'esMX', '¡Hay que ocuparse de las unidades de élite de los Lobo Gélido que vigilan las líneas, soldado! Te encargo que diezmes a esa manada de salvajes. Vuelve aquí con las medallas de sus tenientes y legionarios. Cuando me parezca que hemos despachado a suficiente chusma, desplegaré la fuerza aérea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El vuelo no tardará en estar preparado. ¡Sigue trabajando duro!', 0),
(@ID, 'esMX', 'El vuelo no tardará en estar preparado. ¡Sigue trabajando duro!', 0);
-- 6942 La llamada del aire: la flota de Slidore
-- https://es.classic.wowhead.com/quest=6942
SET @ID := 6942;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis grifos están listos para atacar a las primeras líneas del frente pero no pueden hacerlo hasta que las líneas se reduzcan algo.$B$BLos guerreros Lobo Gélido, encargados de resistir en las primeras líneas del frente, llevan medallas de servicio que lucen orgullosos en la pechera. Arráncales esas medallas de sus podridos cadáveres y tráemelas.$B$BCuando la primera línea del frente esté suficientemente diezmada, ¡daré la orden de atacar desde el aire! ¡Muerte desde el cielo!', 0),
(@ID, 'esMX', 'Mis grifos están listos para atacar a las primeras líneas del frente pero no pueden hacerlo hasta que las líneas se reduzcan algo.$B$BLos guerreros Lobo Gélido, encargados de resistir en las primeras líneas del frente, llevan medallas de servicio que lucen orgullosos en la pechera. Arráncales esas medallas de sus podridos cadáveres y tráemelas.$B$BCuando la primera línea del frente esté suficientemente diezmada, ¡daré la orden de atacar desde el aire! ¡Muerte desde el cielo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sigue así y trae más, soldado! ¡Los grifos Nidal estarán listos para atacar muy pronto!', 0),
(@ID, 'esMX', '¡Sigue así y trae más, soldado! ¡Los grifos Nidal estarán listos para atacar muy pronto!', 0);
-- 6943 La llamada del aire: la flota de Ichman
-- https://es.classic.wowhead.com/quest=6943
SET @ID := 6943;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los ánimos están decaídos, soldado. Tras el fracaso de nuestro último ataque aéreo contra la Horda, ¡se niegan a volar! De ti depende subirles la moral.$B$BRegresa al campo de batalla y ataca directo al corazón del mando de los Lobo Gélido. Acaba con sus comandantes y guardianes. Vuelve aquí y tráeme sus medallas, ¡todas las que te quepan en la talega! Te lo prometo, cuando mis grifos vean el botín y huelan la sangre de nuestro enemigo, ¡volverán a volar! ¡Ahora vete!', 0),
(@ID, 'esMX', 'Los ánimos están decaídos, soldado. Tras el fracaso de nuestro último ataque aéreo contra la Horda, ¡se niegan a volar! De ti depende subirles la moral.$B$BRegresa al campo de batalla y ataca directo al corazón del mando de los Lobo Gélido. Acaba con sus comandantes y guardianes. Vuelve aquí y tráeme sus medallas, ¡todas las que te quepan en la talega! Te lo prometo, cuando mis grifos vean el botín y huelan la sangre de nuestro enemigo, ¡volverán a volar! ¡Ahora vete!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo ves? ¡Fíjate en ellos, soldado! Se acercan... ¡Pronto el Vuelo de Ichman volverá a atacar el corazón del valle! ¡Los Pico Tormenta serán los amos del cielo!', 0),
(@ID, 'esMX', '¿Lo ves? ¡Fíjate en ellos, soldado! Se acercan... ¡Pronto el Vuelo de Ichman volverá a atacar el corazón del valle! ¡Los Pico Tormenta serán los amos del cielo!', 0);
-- ¡El Gran Padre Invierno está aquí!
-- 6961, 7021, 7022, 7023, 7024
-- https://es.classic.wowhead.com/quest=6991
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6961, 7021, 7022, 7023, 7024) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6961, 'esES', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7021, 'esES', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7022, 'esES', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7023, 'esES', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7024, 'esES', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(6961, 'esMX', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7021, 'esMX', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7022, 'esMX', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7023, 'esMX', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(7024, 'esMX', 'Jo jo jo,... hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0);
-- Golosinas para el Gran Padre Invierno
-- 6962, 7025
-- https://es.classic.wowhead.com/quest=6962
DELETE FROM `quest_request_items_locale` WHERE `id` IN(6962, 7025) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(6962, 'esES', 'Tanto hablar de regalitos me ha dado hambre. Mmm, me encantarían unas galletas de jengibre y un vaso de leche...', 0),
(7025, 'esES', 'Tanto hablar de regalitos me ha dado hambre. Mmm, me encantarían unas galletas de jengibre y un vaso de leche...', 0),
(6962, 'esMX', 'Tanto hablar de regalitos me ha dado hambre. Mmm, me encantarían unas galletas de jengibre y un vaso de leche...', 0),
(7025, 'esMX', 'Tanto hablar de regalitos me ha dado hambre. Mmm, me encantarían unas galletas de jengibre y un vaso de leche...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6962, 7025) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6962, 'esES', 'Muchas gracias, $n. Te deseo un feliz Festival de Invierno.$B$BTen, una cosita para agradecerte el favor.', 0),
(7025, 'esES', 'Muchas gracias, $n. Te deseo un feliz Festival de Invierno.$B$BTen, una cosita para agradecerte el favor.', 0),
(6962, 'esMX', 'Muchas gracias, $n. Te deseo un feliz Festival de Invierno.$B$BTen, una cosita para agradecerte el favor.', 0),
(7025, 'esMX', 'Muchas gracias, $n. Te deseo un feliz Festival de Invierno.$B$BTen, una cosita para agradecerte el favor.', 0);
-- El robo de las golosinas del Festival de Invierno
-- 6963, 7042
-- https://es.classic.wowhead.com/quest=6963
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6963, 7042) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6963, 'esES', '¡Eh! ¿Hay alg-g-guien ahí?$B$BN-no s-s-soy un m-m-muñeco de n-nieve. M-me llamo S-sacks y rep-p-presento a P-pastos de Bosquehum-mmeante en For-j-jaz... ¡M-me han atacado unas c-c-criaturas ext-t-trañas mientras buscaba una c-c-carga p-perdida!$B$BT-t-tengo frrrrrrío...', 0),
(7042, 'esES', '¡Eh! ¿Hay alg-g-guien ahí?$B$BN-no s-s-soy un m-m-muñeco de n-nieve. M-me llamo S-sacks y rep-p-presento a P-pastos de Bosquehum-mmeante en For-j-jaz... ¡M-me han atacado unas c-c-criaturas ext-t-trañas mientras buscaba una c-c-carga p-perdida!$B$BT-t-tengo frrrrrrío...', 0),
(6963, 'esMX', '¡Eh! ¿Hay alg-g-guien ahí?$B$BN-no s-s-soy un m-m-muñeco de n-nieve. M-me llamo S-sacks y rep-p-presento a P-pastos de Bosquehum-mmeante en For-j-jaz... ¡M-me han atacado unas c-c-criaturas ext-t-trañas mientras buscaba una c-c-carga p-perdida!$B$BT-t-tengo frrrrrrío...', 0),
(7042, 'esMX', '¡Eh! ¿Hay alg-g-guien ahí?$B$BN-no s-s-soy un m-m-muñeco de n-nieve. M-me llamo S-sacks y rep-p-presento a P-pastos de Bosquehum-mmeante en For-j-jaz... ¡M-me han atacado unas c-c-criaturas ext-t-trañas mientras buscaba una c-c-carga p-perdida!$B$BT-t-tengo frrrrrrío...', 0);
-- 6964 El espíritu de esta fiesta
-- https://es.classic.wowhead.com/quest=6964
SET @ID := 6964;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Festival de Invierno? Por desgracia, con el tiempo ha ido perdiendo significado para los tauren.$B$BDebo decir que comparto el disgusto de Furmund; para él y su grupo, el pasado es como un pendón de guerra. A mí me parece bien que haya festejos, pero sin olvidar el verdadero espíritu del Festival.', 0),
(@ID, 'esMX', '¿El Festival de Invierno? Por desgracia, con el tiempo ha ido perdiendo significado para los tauren.$B$BDebo decir que comparto el disgusto de Furmund; para él y su grupo, el pasado es como un pendón de guerra. A mí me parece bien que haya festejos, pero sin olvidar el verdadero espíritu del Festival.', 0);
-- 7062 El espíritu de esta fiesta
-- https://es.classic.wowhead.com/quest=7062
SET @ID := 7062;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Festival de Invierno? Por desgracia, con el tiempo ha ido perdiendo significado para los enanos.$B$BDebo decir que comparto el disgusto de Furmund; para él y su grupo, el pasado es como un pendón de guerra. A mí me parece bien que haya festejos, pero sin olvidar el verdadero espíritu del Festival.', 0),
(@ID, 'esMX', '¿El Festival de Invierno? Por desgracia, con el tiempo ha ido perdiendo significado para los enanos.$B$BDebo decir que comparto el disgusto de Furmund; para él y su grupo, el pasado es como un pendón de guerra. A mí me parece bien que haya festejos, pero sin olvidar el verdadero espíritu del Festival.', 0);
-- 6981 El fragmento resplandeciente
-- https://es.classic.wowhead.com/quest=6981
SET @ID := 6981;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $r. ¿Qué puedo hacer por ti?', 0),
(@ID, 'esMX', 'Hola, $r. ¿Qué puedo hacer por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh... Nunca había visto algo así...', 0),
(@ID, 'esMX', 'Oh... Nunca había visto algo así...', 0);
-- 6982 Suministros de Dentefrío
-- https://es.classic.wowhead.com/quest=6982
SET @ID := 6982;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en la Mina Dentefrío, $n? ¿Tienes los suministros que te pedí?', 0),
(@ID, 'esMX', '¿Has estado en la Mina Dentefrío, $n? ¿Tienes los suministros que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, los tienes. ¡Buen trabajo, $n! Estos suministros están algo húmedos de estar guardados en esa oscura mina tanto tiempo pero les sacaremos partido igualmente.$B$BGracias, $n. Tus acciones son vitales para el mantenimiento de nuestras tropas.', 0),
(@ID, 'esMX', 'Ah, los tienes. ¡Buen trabajo, $n! Estos suministros están algo húmedos de estar guardados en esa oscura mina tanto tiempo pero les sacaremos partido igualmente.$B$BGracias, $n. Tus acciones son vitales para el mantenimiento de nuestras tropas.', 0);
-- ¡Qué ruin!
-- 6983, 7043
-- https://es.classic.wowhead.com/quest=6983
DELETE FROM `quest_request_items_locale` WHERE `id` IN(6983, 7043) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(6983, 'esES', '¡$n, nuestro Festival de Invierno será un desastre sin esos regalitos que hay que reponer! El propio Graccu no podrá compartir sus deliciosas empanadas de carne con todos los niños y niñas esta temporada...', 0),
(7043, 'esES', '¡$n, nuestro Festival de Invierno será un desastre sin esos regalitos que hay que reponer! El propio Graccu no podrá compartir sus deliciosas empanadas de carne con todos los niños y niñas esta temporada...', 0),
(6983, 'esMX', '¡$n, nuestro Festival de Invierno será un desastre sin esos regalitos que hay que reponer! El propio Graccu no podrá compartir sus deliciosas empanadas de carne con todos los niños y niñas esta temporada...', 0),
(7043, 'esMX', '¡$n, nuestro Festival de Invierno será un desastre sin esos regalitos que hay que reponer! El propio Graccu no podrá compartir sus deliciosas empanadas de carne con todos los niños y niñas esta temporada...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6983, 7043) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6983, 'esES', '¡Lo encontraste! ¡Has salvado el Festival de Invierno de los Pastos de Bosquehumeante!$B$BPobre Sacks... nos aseguraremos de enviar un destacamento a por él y encontrar la forma de descongelarlo. Con suerte, volverá a tiempo para el día del Festival aunque tendrá que compensar el tiempo que no haya podido trabajar. Sin embargo, ¡esto no sería posible si no fuera por ti!', 0),
(7043, 'esES', '¡Lo encontraste! ¡Has salvado el Festival de Invierno de los Pastos de Bosquehumeante!$B$BPobre Sacks... nos aseguraremos de enviar un destacamento a por él y encontrar la forma de descongelarlo. Con suerte, volverá a tiempo para el día del Festival aunque tendrá que compensar el tiempo que no haya podido trabajar. Sin embargo, ¡esto no sería posible si no fuera por ti!', 0),
(6983, 'esMX', '¡Lo encontraste! ¡Has salvado el Festival de Invierno de los Pastos de Bosquehumeante!$B$BPobre Sacks... nos aseguraremos de enviar un destacamento a por él y encontrar la forma de descongelarlo. Con suerte, volverá a tiempo para el día del Festival aunque tendrá que compensar el tiempo que no haya podido trabajar. Sin embargo, ¡esto no sería posible si no fuera por ti!', 0),
(7043, 'esMX', '¡Lo encontraste! ¡Has salvado el Festival de Invierno de los Pastos de Bosquehumeante!$B$BPobre Sacks... nos aseguraremos de enviar un destacamento a por él y encontrar la forma de descongelarlo. Con suerte, volverá a tiempo para el día del Festival aunque tendrá que compensar el tiempo que no haya podido trabajar. Sin embargo, ¡esto no sería posible si no fuera por ti!', 0);
-- Un agradecimiento de Pastos de Bosquehumeante
-- 6984, 7045
-- https://es.classic.wowhead.com/quest=6984
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6984, 7045) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6984, 'esES', 'Jo jo... ¡Saludos, $gaventurero:aventurera;!$B$BLos goblins me han dicho que te has ganado un regalito especial. Aquí tienes. ¡Feliz Festival de Invierno!', 0),
(7045, 'esES', 'Jo jo... ¡Saludos, $gaventurero:aventurera;!$B$BLos goblins me han dicho que te has ganado un regalito especial. Aquí tienes. ¡Feliz Festival de Invierno!', 0),
(6984, 'esMX', 'Jo jo... ¡Saludos, $gaventurero:aventurera;!$B$BLos goblins me han dicho que te has ganado un regalito especial. Aquí tienes. ¡Feliz Festival de Invierno!', 0),
(7045, 'esMX', 'Jo jo... ¡Saludos, $gaventurero:aventurera;!$B$BLos goblins me han dicho que te has ganado un regalito especial. Aquí tienes. ¡Feliz Festival de Invierno!', 0);
-- 6985 Suministros de Ferrohondo
-- https://es.classic.wowhead.com/quest=6985
SET @ID := 6985;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entraste la Mina Ferrohondo, $n? ¿Saqueastes sus suministros?', 0),
(@ID, 'esMX', '¿Entraste la Mina Ferrohondo, $n? ¿Saqueastes sus suministros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los tienes! ¡Bien hecho, $n! ¡Y espero que hayas visto a algunos enanos durante tu incursión y derrames su sangre por los Lobo Gélido!', 0),
(@ID, 'esMX', '¡Los tienes! ¡Bien hecho, $n! ¡Y espero que hayas visto a algunos enanos durante tu incursión y derrames su sangre por los Lobo Gélido!', 0);
-- 7001 Establos vacíos
-- https://es.classic.wowhead.com/quest=7001
SET @ID := 7001;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin tu ayuda, los Jinetes de Lobos Lobo Gélido no tendrían monturas para la batalla. ¡Nos haces un gran servicio!', 0),
(@ID, 'esMX', 'Sin tu ayuda, los Jinetes de Lobos Lobo Gélido no tendrían monturas para la batalla. ¡Nos haces un gran servicio!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo espero que todos los que deben reunir pieles de carnero sean tan aplicados como tú, $n.$B$BA este paso, tendremos el Establo lleno ¡en cuestión de horas!', 0),
(@ID, 'esMX', 'Solo espero que todos los que deben reunir pieles de carnero sean tan aplicados como tú, $n.$B$BA este paso, tendremos el Establo lleno ¡en cuestión de horas!', 0);
-- 7002 Arneses de pellejo de carnero
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=7002
-- https://www.wowhead.com/quest=7002
-- https://classic.wowhead.com/quest=7002
-- http://web.archive.org/web/20130402022122/http://es.wowhead.com/quest=7002
SET @ID := 7002;
UPDATE `quest_request_items` SET `CompletionText` = 'While some of our soldiers are busy capturing wolves for the stable master, others must provide for the simple necessities that riding requires. I am speaking of riding harnesses, of course.$B$BYou must strike at the indigenous rams of the region. The very same rams that the Stormpike cavalry uses as mounts!$B$BSlay them and return to me with their hides. Once we have gathered enough hides, we will fashion harnesses for the riders. The Frostwolf Wolf Riders will ride once more!', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras algunos de nuestros soldados están ocupados en la captura de lobos para el maestro de establos, otros deben encargarse de las necesidades básicas de la monta. Me refiero a los arneses para montar, claro.$B$BDebes atacar a los carneros locales de la región. ¡Los mismísimos carneros que la caballería Pico Tormenta usa de montura!$B$BAcaba con ellos y tráeme sus pieles. Cuando tengamos suficientes pieles, confeccionaremos los arneses para los jinetes. ¡Los Caballeros Lobo de los Lobo Gélido volverán por sus fueros!', 0),
(@ID, 'esMX', 'Mientras algunos de nuestros soldados están ocupados en la captura de lobos para el maestro de establos, otros deben encargarse de las necesidades básicas de la monta. Me refiero a los arneses para montar, claro.$B$BDebes atacar a los carneros locales de la región. ¡Los mismísimos carneros que la caballería Pico Tormenta usa de montura!$B$BAcaba con ellos y tráeme sus pieles. Cuando tengamos suficientes pieles, confeccionaremos los arneses para los jinetes. ¡Los Caballeros Lobo de los Lobo Gélido volverán por sus fueros!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, soldado. Te lo haré saber en cuanto tenga suficientes pieles acumuladas.$B$B¡Sigue así!', 0),
(@ID, 'esMX', 'Muy bien, soldado. Te lo haré saber en cuanto tenga suficientes pieles acumuladas.$B$B¡Sigue así!', 0);
-- 7026 Arneses de pellejo de carnero
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=7026
-- https://www.wowhead.com/quest=7026
-- https://classic.wowhead.com/quest=7026
-- http://web.archive.org/web/20130402022122/http://es.wowhead.com/quest=7026
SET @ID := 7026;
UPDATE `quest_request_items` SET `CompletionText` = 'The Stormpike Brigade cannot charge into battle bareback! We require harnesses for our mounts, after all, we are not savages.$B$BWhile we could easily slay the rams that roam near our base for the leather required to fashion a harness, doing so would be idiotic. We need those rams for mounts.$B$BYou must strike at our enemy\'s base, slaying the frostwolves they use as mounts and taking their hides. Return their hides to me so that harnesses may be made for the cavalry. Go!', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La Brigada Pico Tormenta no puede lanzarse a la batalla a pelo! Necesitamos arneses para nuestras monturas, después de todo, no somos salvajes.$B$BSi bien podríamos matar fácilmente a los carneros que merodean cerca de nuestra base por el cuero necesario para fabricar un arnés, hacerlo sería una idiotez. Necesitamos esos carneros como monturas.$B$BDebes atacar la base de nuestro enemigo, matando a los lobos de hielo que usan como monturas y tomando sus pieles. Devuélveme sus pieles para que le hagan arneses a la caballería. ¡Vamos!', 0),
(@ID, 'esMX', '¡La Brigada Pico Tormenta no puede lanzarse a la batalla a pelo! Necesitamos arneses para nuestras monturas, después de todo, no somos salvajes.$B$BSi bien podríamos matar fácilmente a los carneros que merodean cerca de nuestra base por el cuero necesario para fabricar un arnés, hacerlo sería una idiotez. Necesitamos esos carneros como monturas.$B$BDebes atacar la base de nuestro enemigo, matando a los lobos de hielo que usan como monturas y tomando sus pieles. Devuélveme sus pieles para que le hagan arneses a la caballería. ¡Vamos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, soldado. Te avisaré cuando haya almacenado suficientes pieles.', 0),
(@ID, 'esMX', 'Bien hecho, soldado. Te avisaré cuando haya almacenado suficientes pieles.', 0);
-- 7003 Gigantes reducidos
-- https://es.classic.wowhead.com/quest=7003
SET @ID := 7003;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El residuo de miniaturización es una materia valiosísima en ingeniería, te lo aseguro. Y lo es porque sirve para asegurarse de que el controlador no hace algo tan decepcionante como explotar en la cara del usuario.$B$BOh, no te preocupes, me refería a otros controladores, ¡no al que te di a ti, claro está!', 0),
(@ID, 'esMX', 'El residuo de miniaturización es una materia valiosísima en ingeniería, te lo aseguro. Y lo es porque sirve para asegurarse de que el controlador no hace algo tan decepcionante como explotar en la cara del usuario.$B$BOh, no te preocupes, me refería a otros controladores, ¡no al que te di a ti, claro está!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espléndidamente espléndido! Me alegra ver que has vuelto con el residuo, ¡y con todos tus apéndices intactos, cabeza y todo! Eso está muy bien... no es que el Ultra-reductor fuera peligroso, pero, oye...$B$BAh, y aprecio mucho tu ayuda, $n. De verdad, eres $gun buen amigo:una buena amiga; de los goblins de todo el mundo. Acepta esto como muestra de mi agradecimiento.', 0),
(@ID, 'esMX', '¡Espléndidamente espléndido! Me alegra ver que has vuelto con el residuo, ¡y con todos tus apéndices intactos, cabeza y todo! Eso está muy bien... no es que el Ultra-reductor fuera peligroso, pero, oye...$B$BAh, y aprecio mucho tu ayuda, $n. De verdad, eres $gun buen amigo:una buena amiga; de los goblins de todo el mundo. Acepta esto como muestra de mi agradecimiento.', 0);
-- 7027 Establos vacíos
-- https://es.classic.wowhead.com/quest=7027
SET @ID := 7027;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin tu ayuda, los Jinetes de Carnero de los Pico Tormenta no tendrían monturas para la batalla. ¡Nos haces un gran servicio!', 0),
(@ID, 'esMX', 'Sin tu ayuda, los Jinetes de Carnero de los Pico Tormenta no tendrían monturas para la batalla. ¡Nos haces un gran servicio!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Establo estará lleno muy pronto. ¡Sigue con tu buen trabajo!', 0),
(@ID, 'esMX', 'El Establo estará lleno muy pronto. ¡Sigue con tu buen trabajo!', 0);
-- 7029 La corrupción de Lenguavil
-- https://es.classic.wowhead.com/quest=7029
SET @ID := 7029;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Has curado la hiedra Tallovil', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'SI consigues curar a la planta, volverá a crecer. Tenemos que hacer todo lo que podamos, $n...', 0),
(@ID, 'esMX', 'SI consigues curar a la planta, volverá a crecer. Tenemos que hacer todo lo que podamos, $n...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n; seguiré investigando con los restos de líquido.$B$BAunque queda mucho por hacer, has contribuido a limpiar parte de la corrupción de Lenguavil en Maraudon. Toma esto como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Gracias, $n; seguiré investigando con los restos de líquido.$B$BAunque queda mucho por hacer, has contribuido a limpiar parte de la corrupción de Lenguavil en Maraudon. Toma esto como muestra de mi gratitud.', 0);
-- 7041 La corrupción de Lenguavil
-- https://es.classic.wowhead.com/quest=7041
SET @ID := 7041;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Has curado la hiedra Tallovil', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 7044 Leyendas de Maraudon
-- https://es.classic.wowhead.com/quest=7044
SET @ID := 7044;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He despertado de una pesadilla interminable...', 0),
(@ID, 'esMX', 'He despertado de una pesadilla interminable...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que me has traído las piezas del cetro, podremos limpiar Maraudon de la corrupcíón de Lenguavil.', 0),
(@ID, 'esMX', 'Ahora que me has traído las piezas del cetro, podremos limpiar Maraudon de la corrupcíón de Lenguavil.', 0);
-- 7046 El cetro de Celebras
-- https://es.classic.wowhead.com/quest=7046
SET @ID := 7046;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si deseas reiniciar el ritual, abandona nuestro primer intento y luego vuelve a hablarme.', 0),
(@ID, 'esMX', 'Si deseas reiniciar el ritual, abandona nuestro primer intento y luego vuelve a hablarme.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten; debes usar el poder que te ha sido concedido siempre para hacer el bien. Sigue explorando las cavernas, a ver si encuentras los restos de mi tío. Te esperan grandes peligros, $n.$B$BVuelve a hablar conmigo si lo necesitas.', 0),
(@ID, 'esMX', 'Ten; debes usar el poder que te ha sido concedido siempre para hacer el bien. Sigue explorando las cavernas, a ver si encuentras los restos de mi tío. Te esperan grandes peligros, $n.$B$BVuelve a hablar conmigo si lo necesitas.', 0);
-- 7061 El festín del Festival de Invierno
-- https://es.classic.wowhead.com/quest=7061
SET @ID := 7061;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a Mulgore ya nuestra humilde comunidad de Cima del Trueno, $gamigo:amiga;. Me agrada la gente que se interesa por el reino, sus gentes y sus tradiciones. ¿Es esa la razón por la que estás aquí?', 0),
(@ID, 'esMX', 'Te doy la bienvenida a Mulgore ya nuestra humilde comunidad de Cima del Trueno, $gamigo:amiga;. Me agrada la gente que se interesa por el reino, sus gentes y sus tradiciones. ¿Es esa la razón por la que estás aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las leyendas y la tradición del Festival de Invierno se han ido borrando de la memoria de nuestra gente con el paso de los años. Sí, sé que los goblins ayudan a revivir el Festival en su propio beneficio, pero eso al menos ayuda a que no caiga en el olvido.$B$BAdmiro tu interés en nuestra historia es un hecho admirable, joven $c. Me impresiona tu sabiduría.', 0),
(@ID, 'esMX', 'Las leyendas y la tradición del Festival de Invierno se han ido borrando de la memoria de nuestra gente con el paso de los años. Sí, sé que los goblins ayudan a revivir el Festival en su propio beneficio, pero eso al menos ayuda a que no caiga en el olvido.$B$BAdmiro tu interés en nuestra historia es un hecho admirable, joven $c. Me impresiona tu sabiduría.', 0);
-- 7063 El festín del Festival de Invierno
-- https://es.classic.wowhead.com/quest=7063
SET @ID := 7063;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida al Reino de Forjaz, $gamigo:amiga;. Me agrada la gente que se interesa por el reino, sus gentes y sus tradiciones. ¿Es esa la razón por la que estás aquí?', 0),
(@ID, 'esMX', 'Te doy la bienvenida al Reino de Forjaz, $gamigo:amiga;. Me agrada la gente que se interesa por el reino, sus gentes y sus tradiciones. ¿Es esa la razón por la que estás aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las leyendas y la tradición del Festival de Invierno se han ido borrando de la memoria de nuestra gente con el paso de los años. Sí, sé que los goblins ayudan a revivir el Festival en su propio beneficio, pero eso al menos ayuda a que no caiga en el olvido.$B$BEl hecho de que vayas más allá de lo material y te intereses por nuestra historia es algo admirable, joven $c. Me impresiona tu sabiduría.', 0),
(@ID, 'esMX', 'Las leyendas y la tradición del Festival de Invierno se han ido borrando de la memoria de nuestra gente con el paso de los años. Sí, sé que los goblins ayudan a revivir el Festival en su propio beneficio, pero eso al menos ayuda a que no caiga en el olvido.$B$BEl hecho de que vayas más allá de lo material y te intereses por nuestra historia es algo admirable, joven $c. Me impresiona tu sabiduría.', 0);
-- 7064 Corrupción de la tierra y de la semilla
-- https://es.classic.wowhead.com/quest=7064
SET @ID := 7064;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Preferiría pelear esta batalla por nuestra cuenta, pero no nos quedan otras opciones: necesitamos a los más poderosos, y las razas de Azeroth han demostrado sin lugar a dudas que pueden superar esas cosas cuando trabajan juntas. Así que es a ti a quien acudimos en busca de ayuda.$B$BSolo espero que sea suficiente.$B$BZaetar, hermano de Remulos, trajo muchos dolores a este mundo y finalmente causó su propia muerte. Solo espero no haber causado más muertes al pedirte que nos ayudes.', 0),
(@ID, 'esMX', 'Preferiría pelear esta batalla por nuestra cuenta, pero no nos quedan otras opciones: necesitamos a los más poderosos, y las razas de Azeroth han demostrado sin lugar a dudas que pueden superar esas cosas cuando trabajan juntas. Así que es a ti a quien acudimos en busca de ayuda.$B$BSolo espero que sea suficiente.$B$BZaetar, hermano de Remulos, trajo muchos dolores a este mundo y finalmente causó su propia muerte. Solo espero no haber causado más muertes al pedirte que nos ayudes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, $n! ¡Gracias!$B$BLe preguntaré a Marandis por los restos de Zaetar, pero al menos has hecho lo más difícil.$B$BElige uno de estos objetos como prueba de nuestra gratitud.', 0),
(@ID, 'esMX', '¡Estupendo, $n! ¡Gracias!$B$BLe preguntaré a Marandis por los restos de Zaetar, pero al menos has hecho lo más difícil.$B$BElige uno de estos objetos como prueba de nuestra gratitud.', 0);
-- 7066 La semilla de vida
-- https://es.classic.wowhead.com/quest=7066
SET @ID := 7066;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dejas un rastro de corrupción, $n, como muchos aventureros. Pero tú tienes algo distinto. ¿Has venido a hablar conmigo? Me resultas familiar, pero no consigo ubicarte.$B$BDime, ¿por qué has venido a verme?', 0),
(@ID, 'esMX', 'Dejas un rastro de corrupción, $n, como muchos aventureros. Pero tú tienes algo distinto. ¿Has venido a hablar conmigo? Me resultas familiar, pero no consigo ubicarte.$B$BDime, ¿por qué has venido a verme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El espíritu de mi hermano ha encontrado al fin la paz? Me alegro de saberlo. Lo creí perdido para siempre, pero esto... Este símbolo de su sacrificio me demuestra que no está perdido sino que ha renacido. Ha hecho lo que debía hacer.$B$BGracias, $n. Me has devuelto la esperanza; presiento que esta semilla será muy importante para las gentes de esta tierra.', 0),
(@ID, 'esMX', '¿El espíritu de mi hermano ha encontrado al fin la paz? Me alegro de saberlo. Lo creí perdido para siempre, pero esto... Este símbolo de su sacrificio me demuestra que no está perdido sino que ha renacido. Ha hecho lo que debía hacer.$B$BGracias, $n. Me has devuelto la esperanza; presiento que esta semilla será muy importante para las gentes de esta tierra.', 0);
-- 7067 Las instrucciones del Paria
-- https://es.classic.wowhead.com/quest=7067
SET @ID := 7067;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué me dices, $n? ¿Te atreves a pisar suelo sagrado para ayudarme a unificar a los centauros?', 0),
(@ID, 'esMX', '¿Qué me dices, $n? ¿Te atreves a pisar suelo sagrado para ayudarme a unificar a los centauros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin puedo iniciar la unificación de las tribus, $r! Gracias.$B$BAcepta esto en prueba de mi gratitud. Espero que cuando volvamos a vernos sea en tiempo de paz.', 0),
(@ID, 'esMX', '¡Al fin puedo iniciar la unificación de las tribus, $r! Gracias.$B$BAcepta esto en prueba de mi gratitud. Espero que cuando volvamos a vernos sea en tiempo de paz.', 0);
-- 7068 Trozos Oscuros
-- https://es.classic.wowhead.com/quest=7068
SET @ID := 7068;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los cristales? Seguro que serán muy útiles en todo tipo de magia arcana, rituales de poder y grandes hechizos.', 0),
(@ID, 'esMX', '¿Traes los cristales? Seguro que serán muy útiles en todo tipo de magia arcana, rituales de poder y grandes hechizos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto... Bueno, toma uno de estos abalorios y lárgate, tengo mucho que hacer.', 0),
(@ID, 'esMX', 'Perfecto... Bueno, toma uno de estos abalorios y lárgate, tengo mucho que hacer.', 0);
-- 7081 Los cementerios del Valle de Alterac
-- https://es.classic.wowhead.com/quest=7081
SET @ID := 7081;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cementerio atacado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, todavía no has asaltado un cementerio. Regresa a mí cuando esta tarea esté completa.', 0),
(@ID, 'esMX', '$n, todavía no has asaltado un cementerio. Regresa a mí cuando esta tarea esté completa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien! Los cementerios son clave para el control del Valle de Alterac. Cuando capturas uno, contribuyes a asegurar la soberanía de la Alianza en ese lugar.$B$BVete ahora, $n. Vuelve a la batalla y si ves un cementerio bajo control de la Horda... ¡ya sabes qué hacer!', 0),
(@ID, 'esMX', '¡Muy bien! Los cementerios son clave para el control del Valle de Alterac. Cuando capturas uno, contribuyes a asegurar la soberanía de la Alianza en ese lugar.$B$BVete ahora, $n. Vuelve a la batalla y si ves un cementerio bajo control de la Horda... ¡ya sabes qué hacer!', 0);
-- 7082 Los cementerios de Alterac
-- https://es.classic.wowhead.com/quest=7082
SET @ID := 7082;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cementerio atacado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ataca un cementerio de la Alianza!', 0),
(@ID, 'esMX', '¡Ataca un cementerio de la Alianza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n! Con cada cementerio que controlemos, el espíritu de nuestros enemigos vagará perdido y sin rumbo.', 0),
(@ID, 'esMX', '¡Muy bien, $n! Con cada cementerio que controlemos, el espíritu de nuestros enemigos vagará perdido y sin rumbo.', 0);
