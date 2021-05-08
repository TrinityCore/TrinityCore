-- 8513 ¡La Alianza necesita cuero medio!
-- https://es.classic.wowhead.com/quest=8513
SET @ID := 8513;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí señor, te recuerdo. ¿Es ese el cuero medio que llevas contigo?', 0),
(@ID, 'esMX', 'Sí señor, te recuerdo. ¿Es ese el cuero medio que llevas contigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau! Parecía que solo estabas aquí ofreciéndote como $gvoluntario:voluntaria; para ayudar. Muchas gracias por la donación. Los empacaré y los contaré. Seguro que sabes cómo alegrarle el día a un chico.', 0),
(@ID, 'esMX', '¡Guau! Parecía que solo estabas aquí ofreciéndote como $gvoluntario:voluntaria; para ayudar. Muchas gracias por la donación. Los empacaré y los contaré. Seguro que sabes cómo alegrarle el día a un chico.', 0);
-- 8514 ¡La Alianza necesita más cuero medio!
-- https://es.classic.wowhead.com/quest=8514
SET @ID := 8514;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí $gseñor:señora;, parece que hemos reunido muchas piezas de cuero medio, pero necesitamos más. Puedo asegurarte que todo se aprovechará; ni una sola pieza se desperdiciará. Sé que es mucho pedir, pero si aún estás $gdispuesto:dispuesta;, podría usar tu ayuda para intentar hacer mella en el resto de mi cuota.', 0),
(@ID, 'esMX', 'Sí $gseñor:señora;, parece que hemos reunido muchas piezas de cuero medio, pero necesitamos más. Puedo asegurarte que todo se aprovechará; ni una sola pieza se desperdiciará. Sé que es mucho pedir, pero si aún estás $gdispuesto:dispuesta;, podría usar tu ayuda para intentar hacer mella en el resto de mi cuota.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Caramba, seguro que has traído mucho cuero medio, $gseñor:señora;! Me aseguraré de que todo esto se utilice correctamente, sí, de hecho. ¡Con tu ayuda, habremos completado nuestra provisión de cuero medio en poco tiempo!$B$B¡Gracias, $n!', 0),
(@ID, 'esMX', '¡Caramba, seguro que has traído mucho cuero medio, $gseñor:señora;! Me aseguraré de que todo esto se utilice correctamente, sí, de hecho. ¡Con tu ayuda, habremos completado nuestra provisión de cuero medio en poco tiempo!$B$B¡Gracias, $n!', 0);
-- 8515 ¡La Alianza necesita cuero grueso!
-- https://es.classic.wowhead.com/quest=8515
SET @ID := 8515;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es ese el cuero grueso que tienes en tu mochila, $n? ¿Lo es? ¡No puedo esperar a que me lo entregues! Todos van a estar tan contentos con nosotros, ¿no crees?', 0),
(@ID, 'esMX', '¿Es ese el cuero grueso que tienes en tu mochila, $n? ¿Lo es? ¡No puedo esperar a que me lo entregues! Todos van a estar tan contentos con nosotros, ¿no crees?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, sabía que podías hacerlo, $n, ¡simplemente lo sabía! Los pondré en las manos adecuadas tan pronto como pueda. Ahora veamos aquí. Mmm, parece que nuestra cuenta va bastante bien. Deberías volver a consultarme en un momento, una vez que termine de contar para ver si necesitamos más. ¡Porque si lo hacemos, tú eres $gel:la; que quiero que lo reuna para mí!', 0),
(@ID, 'esMX', 'Oh, sabía que podías hacerlo, $n, ¡simplemente lo sabía! Los pondré en las manos adecuadas tan pronto como pueda. Ahora veamos aquí. Mmm, parece que nuestra cuenta va bastante bien. Deberías volver a consultarme en un momento, una vez que termine de contar para ver si necesitamos más. ¡Porque si lo hacemos, tú eres $gel:la; que quiero que lo reuna para mí!', 0);
-- 8516 ¡La Alianza necesita más cuero grueso!
-- https://es.classic.wowhead.com/quest=8516
SET @ID := 8516;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, la pila todavía no es lo suficientemente alta. $n, todavía no hemos alcanzado nuestro objetivo de cuero grueso. ¡Piensa en todas las cosas que podemos hacer con todo ese cuero! Todo tipo de armaduras y armas. ¡Cosas para el interior de los tanques de vapor y visores de rifle! Y gafas de ingeniería, ¡siempre son divertidas!$B$B¿Me traerás de vuelta un poco más de cuero grueso?', 0),
(@ID, 'esMX', 'Sí, la pila todavía no es lo suficientemente alta. $n, todavía no hemos alcanzado nuestro objetivo de cuero grueso. ¡Piensa en todas las cosas que podemos hacer con todo ese cuero! Todo tipo de armaduras y armas. ¡Cosas para el interior de los tanques de vapor y visores de rifle! Y gafas de ingeniería, ¡siempre son divertidas!$B$B¿Me traerás de vuelta un poco más de cuero grueso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo hiciste otra vez! Es simplemente asombroso cómo sales, recolectas todas estas cosas, y luego las traes aquí y las entregas. Te lo digo, cuando se enteren de cuánto has estado ayudando por aquí, ¡no podrás caminar por la calle sin que la gente te pida tu autógrafo!$B$BGracias de nuevo por tu generosa donación de cuero grueso, $n.', 0),
(@ID, 'esMX', '¡Lo hiciste otra vez! Es simplemente asombroso cómo sales, recolectas todas estas cosas, y luego las traes aquí y las entregas. Te lo digo, cuando se enteren de cuánto has estado ayudando por aquí, ¡no podrás caminar por la calle sin que la gente te pida tu autógrafo!$B$BGracias de nuevo por tu generosa donación de cuero grueso, $n.', 0);
-- 8517 ¡La Alianza necesita vendas de lino!
-- https://es.classic.wowhead.com/quest=8517
SET @ID := 8517;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las veinte vendas de lino que necesito, $n?', 0),
(@ID, 'esMX', '¿Tienes las veinte vendas de lino que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchos son los soldados que se beneficiarán de tu contribución de hoy, $n. Me ocuparé personalmente de que la Alianza conozca sus esfuerzos. Permítame un momento para almacenar estos vendajes correctamente y actualizar mi recuento, y luego consulta conmigo para ver si necesito más.$B$B¡Que la Luz de Elune brille sobre ti, $r!', 0),
(@ID, 'esMX', 'Muchos son los soldados que se beneficiarán de tu contribución de hoy, $n. Me ocuparé personalmente de que la Alianza conozca sus esfuerzos. Permítame un momento para almacenar estos vendajes correctamente y actualizar mi recuento, y luego consulta conmigo para ver si necesito más.$B$B¡Que la Luz de Elune brille sobre ti, $r!', 0);
-- 8518 ¡La Alianza necesita más vendas de lino!
-- https://es.classic.wowhead.com/quest=8518
SET @ID := 8518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca dejará de asombrarme el altruismo demostrado cuando tantos optarían por una alternativa egoísta. $c, todavía necesito unas cuantas vendas de lino para poder dar mi encargo por cumplido. ¿Me ayudarás una vez más a reunir esas vendas?', 0),
(@ID, 'esMX', 'Nunca dejará de asombrarme el altruismo demostrado cuando tantos optarían por una alternativa egoísta. $c, todavía necesito unas cuantas vendas de lino para poder dar mi encargo por cumplido. ¿Me ayudarás una vez más a reunir esas vendas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mereces todos mis elogios, $n. Mientras muchos se aprovecharían de la economía de nuestra guerra para enriquecerse enfervorecidos por la avaricia, has demostrado una y otra vez que tu entrega a la Alianza, y por ende a todo Azeroth, es lo primero.$B$B¡Que la bendición de Elune siempre esté contigo!', 0),
(@ID, 'esMX', 'Mereces todos mis elogios, $n. Mientras muchos se aprovecharían de la economía de nuestra guerra para enriquecerse enfervorecidos por la avaricia, has demostrado una y otra vez que tu entrega a la Alianza, y por ende a todo Azeroth, es lo primero.$B$B¡Que la bendición de Elune siempre esté contigo!', 0);
-- 8519 Un peón en el ajedrez de la vida
-- https://es.classic.wowhead.com/quest=8519
SET @ID := 8519;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Después de la traición de Staghelm, recogí los pedazos destrozados del Cetro de las arenas movedizas y regresé aquí. Tenía toda la intención de proteger el cetro de aquellos que tratarían de usarlo para causar daño a nuestro mundo; así nació la carga de los Vuelo de Dragón.$B$BUn cetro dividido entre los cuatro poderosos Aspectos resultaría casi imposible de restaurar para aquellos que deliberadamente buscan el caos... o eso pensé. Qué tonto fui. Incluso ahora me persigue ese vuelo maldito.', 0),
(@ID, 'esMX', 'Después de la traición de Staghelm, recogí los pedazos destrozados del Cetro de las arenas movedizas y regresé aquí. Tenía toda la intención de proteger el cetro de aquellos que tratarían de usarlo para causar daño a nuestro mundo; así nació la carga de los Vuelo de Dragón.$B$BUn cetro dividido entre los cuatro poderosos Aspectos resultaría casi imposible de restaurar para aquellos que deliberadamente buscan el caos... o eso pensé. Qué tonto fui. Incluso ahora me persigue ese vuelo maldito.', 0);
-- 8520 ¡La Alianza necesita vendas de seda!
-- https://es.classic.wowhead.com/quest=8520
SET @ID := 8520;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c, ¿ya has conseguido esas veinte vendas de seda?', 0),
(@ID, 'esMX', 'Hola, $c, ¿ya has conseguido esas veinte vendas de seda?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¡lo lograste! Gracias a ti estamos un paso más cerca de conseguir nuestro objetivo con las vendas de seda. Las guardaré y luego podremos hablar más si quieres.', 0),
(@ID, 'esMX', '$c, ¡lo lograste! Gracias a ti estamos un paso más cerca de conseguir nuestro objetivo con las vendas de seda. Las guardaré y luego podremos hablar más si quieres.', 0);
-- 8521 ¡La Alianza necesita más vendas de seda!
-- https://es.classic.wowhead.com/quest=8521
SET @ID := 8521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es muy amable por tu parte ofrecerte a ayudarme de nuevo, $c. Parece que hemos reunido la gran cantidad de vendas de seda que se nos ha encomendado, pero aún necesitamos más. $n, ¿hay alguna forma que te parezca adecuada para hacer otro paquete y traerlo? La Alianza y yo estaremos muy agradecidos.', 0),
(@ID, 'esMX', 'Es muy amable por tu parte ofrecerte a ayudarme de nuevo, $c. Parece que hemos reunido la gran cantidad de vendas de seda que se nos ha encomendado, pero aún necesitamos más. $n, ¿hay alguna forma que te parezca adecuada para hacer otro paquete y traerlo? La Alianza y yo estaremos muy agradecidos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres una persona tan desinteresada. Muchas gracias por tu contribución al esfuerzo de guerra. Son las personas como tú las que van a marcar la diferencia entre el éxito y el fracaso en Ahn\'Qiraj. Solo espero que todo esto sea suficiente.$B$BGracias de nuevo, $n.', 0),
(@ID, 'esMX', 'Eres una persona tan desinteresada. Muchas gracias por tu contribución al esfuerzo de guerra. Son las personas como tú las que van a marcar la diferencia entre el éxito y el fracaso en Ahn\'Qiraj. Solo espero que todo esto sea suficiente.$B$BGracias de nuevo, $n.', 0);
-- 8522 ¡La Alianza necesita vendas de paño rúnico!
-- https://es.classic.wowhead.com/quest=8522
SET @ID := 8522;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los días pasan uno tras otro y seguimos adelante. $n, ¿tienes esas vendas de paño rúnico?', 0),
(@ID, 'esMX', 'Los días pasan uno tras otro y seguimos adelante. $n, ¿tienes esas vendas de paño rúnico?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu perseverancia en esta tarea es digna de elogio, $n. Guardaré estas vendas y luego me gustaría volver a hablar contigo sobre la posibilidad de que recojas aún más vendas de paño rúnico.', 0),
(@ID, 'esMX', 'Tu perseverancia en esta tarea es digna de elogio, $n. Guardaré estas vendas y luego me gustaría volver a hablar contigo sobre la posibilidad de que recojas aún más vendas de paño rúnico.', 0);
-- 8523 ¡La Alianza necesita más vendas de paño rúnico!
-- https://es.classic.wowhead.com/quest=8523
SET @ID := 8523;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que venimos a discutir asuntos urgentes una vez más, $n. Una vez más te agradezco tus esfuerzos; no todos son tan tan desinteresados. Pero aún queda mucho trabajo por hacer.$B$B$n, ¿volverás a recoger vendas de paño rúnico y me las devolverás aquí?', 0),
(@ID, 'esMX', 'Así que venimos a discutir asuntos urgentes una vez más, $n. Una vez más te agradezco tus esfuerzos; no todos son tan tan desinteresados. Pero aún queda mucho trabajo por hacer.$B$B$n, ¿volverás a recoger vendas de paño rúnico y me las devolverás aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vamos por buen camino, $n. Eres $gun excelente compañero:una excelente compañera; de trabajo. Una vez más te doy las gracias por tus esfuerzos en nombre de toda la Alianza. Ven y habla de nuevo conmigo pronto.', 0),
(@ID, 'esMX', 'Vamos por buen camino, $n. Eres $gun excelente compañero:una excelente compañera; de trabajo. Una vez más te doy las gracias por tus esfuerzos en nombre de toda la Alianza. Ven y habla de nuevo conmigo pronto.', 0);
-- 8524 ¡La Alianza necesita atún blanco arco iris!
-- https://es.classic.wowhead.com/quest=8524
SET @ID := 8524;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy dispuesto a apostar que has regresado con todo ese atún blanco del que estábamos hablando antes, ¿verdad, $n?', 0),
(@ID, 'esMX', 'Estoy dispuesto a apostar que has regresado con todo ese atún blanco del que estábamos hablando antes, ¿verdad, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dos para la Alianza, uno para mí, dos para la Alianza, uno para mí. Hola, $gpescador:pescadora;, excelente trabajo. Puedo ver que vas a ser un verdadero mérito para el club. Sin embargo, me parece que probablemente necesitemos más de ese atún blanco. ¿Por qué no te diriges hacia fuera y pescas un poco más? Ya puedo escuchar mi estómago retumbar.', 0),
(@ID, 'esMX', 'Dos para la Alianza, uno para mí, dos para la Alianza, uno para mí. Hola, $gpescador:pescadora;, excelente trabajo. Puedo ver que vas a ser un verdadero mérito para el club. Sin embargo, me parece que probablemente necesitemos más de ese atún blanco. ¿Por qué no te diriges hacia fuera y pescas un poco más? Ya puedo escuchar mi estómago retumbar.', 0);
-- 8525 ¡La Alianza necesita más atún blanco arco iris!
-- https://es.classic.wowhead.com/quest=8525
SET @ID := 8525;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué! ¿Tú otra vez? Bueno, seré el tío de un mono... excepto que soy un Gnomo. ¡Gastrónomo Salao para ser precisos! Así que volviste a ayudar, ¿eh? Bueno, no puedo decir que te culpo. ¿No te encanta el olor de toda esa comida? <babeando>$B$B¡Basta de holgazanear! ¡Sal y tráeme más atún blanco arcoíris!', 0),
(@ID, 'esMX', '¡Qué! ¿Tú otra vez? Bueno, seré el tío de un mono... excepto que soy un Gnomo. ¡Gastrónomo Salao para ser precisos! Así que volviste a ayudar, ¿eh? Bueno, no puedo decir que te culpo. ¿No te encanta el olor de toda esa comida? <babeando>$B$B¡Basta de holgazanear! ¡Sal y tráeme más atún blanco arcoíris!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que lo tenías dentro, $gchico:chica;. Tienes el aspecto de alguien que sabe lo que le gusta. Específicamente que te gusta complacerme y los poderes fácticos. Y eso lo tienes, te lo garantizo.$B$BJaja, está bien, simplemente guardaré estos peces adecuadamente, y luego tú y yo podemos tener una pequeña charla sobre que recolectes otros veinte atunes.', 0),
(@ID, 'esMX', 'Sabía que lo tenías dentro, $gchico:chica;. Tienes el aspecto de alguien que sabe lo que le gusta. Específicamente que te gusta complacerme y los poderes fácticos. Y eso lo tienes, te lo garantizo.$B$BJaja, está bien, simplemente guardaré estos peces adecuadamente, y luego tú y yo podemos tener una pequeña charla sobre que recolectes otros veinte atunes.', 0);
-- 8526 ¡La Alianza necesita raptor asado!
-- https://es.classic.wowhead.com/quest=8526
SET @ID := 8526;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿ya tienes todo ese raptor asado?', 0),
(@ID, 'esMX', 'Entonces, ¿ya tienes todo ese raptor asado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, eso es genial. Gracias por traerme toda esta carne de animal quemada, $n. Lo pondré en la pila de allí. Seguro que alguien se ocupará de ello. Supongo que si tienes algo de tiempo, ¿querrás traerme más?', 0),
(@ID, 'esMX', 'Vaya, eso es genial. Gracias por traerme toda esta carne de animal quemada, $n. Lo pondré en la pila de allí. Seguro que alguien se ocupará de ello. Supongo que si tienes algo de tiempo, ¿querrás traerme más?', 0);
-- 8528 ¡La Alianza necesita serviolas moteadas!
-- https://es.classic.wowhead.com/quest=8528
SET @ID := 8528;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy segura de que regresarás pronto con las serviolas moteadas que discutimos.', 0),
(@ID, 'esMX', 'Estoy segura de que regresarás pronto con las serviolas moteadas que discutimos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por este regalo, $n, y de manera tan oportuna también. Seguramente a nuestros soldados no les faltará algo de comer. Solo déjame guardar estos peces correctamente y luego tú y yo podemos discutir una segunda entrega, si estás $gdispuesto:dispuesta;.', 0),
(@ID, 'esMX', 'Gracias por este regalo, $n, y de manera tan oportuna también. Seguramente a nuestros soldados no les faltará algo de comer. Solo déjame guardar estos peces correctamente y luego tú y yo podemos discutir una segunda entrega, si estás $gdispuesto:dispuesta;.', 0);
-- 8529 ¡La Alianza necesita más serviolas moteadas!
-- https://es.classic.wowhead.com/quest=8529
SET @ID := 8529;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si todavía estás $gdispuesto:dispuesta;, me gustaría enviarte de regreso para que traigas otra carga de serviolas moteadas, $n. Me imagino que, con la experiencia de la primera vez, esta captura debería ser mucho más rápida y sencilla. ¿Estás en el juego?', 0),
(@ID, 'esMX', 'Si todavía estás $gdispuesto:dispuesta;, me gustaría enviarte de regreso para que traigas otra carga de serviolas moteadas, $n. Me imagino que, con la experiencia de la primera vez, esta captura debería ser mucho más rápida y sencilla. ¿Estás en el juego?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gun verdadero:una verdadera; miembro de la Alianza, $n. Tus esfuerzos no pasarán desapercibidos ni serán despreciados. Y gracias por cocinar el pescado también. Me encargaré de que se almacenen correctamente y luego tendré que actualizar mi recuento. Cada uno nos acerca mucho más a alcanzar nuestro objetivo.', 0),
(@ID, 'esMX', 'Eres $gun verdadero:una verdadera; miembro de la Alianza, $n. Tus esfuerzos no pasarán desapercibidos ni serán despreciados. Y gracias por cocinar el pescado también. Me encargaré de que se almacenen correctamente y luego tendré que actualizar mi recuento. Cada uno nos acerca mucho más a alcanzar nuestro objetivo.', 0);
-- 8532 ¡La Horda necesita lingotes de cobre!
-- https://es.classic.wowhead.com/quest=8532
SET @ID := 8532;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que eso que traes son los 20 lingotes de cobre, $c.', 0),
(@ID, 'esMX', 'Espero que eso que traes son los 20 lingotes de cobre, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos lingotes servirán y gracias por no sacarles brillo. De nada sirve embellecerlos cuando se van a fundir para todo tipo de material que se debe construir para la guerra. Me ocuparé de poner esto en las pilas y me aseguraré de que se aprovechan bien. Vuelve a hablar conmigo si te interesara traer otros 20.', 0),
(@ID, 'esMX', 'Estos lingotes servirán y gracias por no sacarles brillo. De nada sirve embellecerlos cuando se van a fundir para todo tipo de material que se debe construir para la guerra. Me ocuparé de poner esto en las pilas y me aseguraré de que se aprovechan bien. Vuelve a hablar conmigo si te interesara traer otros 20.', 0);
-- 8533 ¡La Horda necesita más lingotes de cobre!
-- https://es.classic.wowhead.com/quest=8533
SET @ID := 8533;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has vuelto? No tardarás en convertirte en $gun auténtico minero:una auténtica minera;, $c. Así que ya sabes de qué va; necesito que vayas a extraer un montón de mineral de cobre, lo fundas en lingotes y me los traigas aquí. Sé que es algo de lo que eres capaz, el tema es ¿estás $gdispuesto:dispuesta; a hacerlo?', 0),
(@ID, 'esMX', '¿Ya has vuelto? No tardarás en convertirte en $gun auténtico minero:una auténtica minera;, $c. Así que ya sabes de qué va; necesito que vayas a extraer un montón de mineral de cobre, lo fundas en lingotes y me los traigas aquí. Sé que es algo de lo que eres capaz, el tema es ¿estás $gdispuesto:dispuesta; a hacerlo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me lo has probado una vez más, $n. Me ocuparé de que este cobre se utilice a su debido tiempo. Sin embargo, por ahora, necesito colocar estas barras de cobre en el palé y contarlas. Si todavía te sientes $ganimado:animada;, podría usar tu ayuda para reunir aún más barras de cobre.', 0),
(@ID, 'esMX', 'Me lo has probado una vez más, $n. Me ocuparé de que este cobre se utilice a su debido tiempo. Sin embargo, por ahora, necesito colocar estas barras de cobre en el palé y contarlas. Si todavía te sientes $ganimado:animada;, podría usar tu ayuda para reunir aún más barras de cobre.', 0);
-- 8534 Informe de exploración de Colmen'Zora
-- https://es.classic.wowhead.com/quest=8534
SET @ID := 8534;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encontrarás al Explorador Azenel dentro de Colmen\'Zora. ¡Date prisa, $n! El tiempo es esencial.', 0),
(@ID, 'esMX', 'Encontrarás al Explorador Azenel dentro de Colmen\'Zora. ¡Date prisa, $n! El tiempo es esencial.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apreciamos mucho tus esfuerzos, $n. Leeré estos informes de exploración de inmediato, siéntete libre de repasar tu próxima tarea.', 0),
(@ID, 'esMX', 'Apreciamos mucho tus esfuerzos, $n. Leeré estos informes de exploración de inmediato, siéntete libre de repasar tu próxima tarea.', 0);
-- Templario vetusto
-- 8535, 8536, 8537
-- https://es.classic.wowhead.com/quest=8535
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8535, 8536, 8537) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8535, 'esES', '¿Has terminado tu tarea, $n?', 0),
(8536, 'esES', '¿Has terminado tu tarea, $n?', 0),
(8537, 'esES', '¿Has terminado tu tarea, $n?', 0),
(8535, 'esMX', '¿Has terminado tu tarea, $n?', 0),
(8536, 'esMX', '¿Has terminado tu tarea, $n?', 0),
(8537, 'esMX', '¿Has terminado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8535, 8536, 8537) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8535, 'esES', 'Buen trabajo, $n. Aquí está su próxima tarea.', 0),
(8536, 'esES', 'Buen trabajo, $n. Aquí está su próxima tarea.', 0),
(8537, 'esES', 'Buen trabajo, $n. Aquí está su próxima tarea.', 0),
(8535, 'esMX', 'Buen trabajo, $n. Aquí está su próxima tarea.', 0),
(8536, 'esMX', 'Buen trabajo, $n. Aquí está su próxima tarea.', 0),
(8537, 'esMX', 'Buen trabajo, $n. Aquí está su próxima tarea.', 0);
-- 8538 Los cuatro Duques
-- https://es.classic.wowhead.com/quest=8538
SET @ID := 8538;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has terminado tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has terminado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy has conseguido un gran logro para nuestra causa, $n. Has vencido a algunos de nuestros enemigos más poderosos. Por eso, te felicito enormemente.', 0),
(@ID, 'esMX', 'Hoy has conseguido un gran logro para nuestra causa, $n. Has vencido a algunos de nuestros enemigos más poderosos. Por eso, te felicito enormemente.', 0);
-- 8539 Objetivo: las hermanas de la colmena de Colmen'Zora
-- https://es.classic.wowhead.com/quest=8539
SET @ID := 8539;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Eres $gun digno aliado:una digna aliada;.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Eres $gun digno aliado:una digna aliada;.', 0);
-- Botas para la guardia
-- 8540, 8541
-- https://es.classic.wowhead.com/quest=8540
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8540, 8541) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8540, 'esES', '¿Tienes algo para mí, $n?', 0),
(8541, 'esES', '¿Tienes algo para mí, $n?', 0),
(8540, 'esMX', '¿Tienes algo para mí, $n?', 0),
(8541, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8540, 8541) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8540, 'esES', 'Excelente. Las necesitábamos, $n. Buen trabajo.', 0),
(8541, 'esES', 'Excelente. Las necesitábamos, $n. Buen trabajo.', 0),
(8540, 'esMX', 'Excelente. Las necesitábamos, $n. Buen trabajo.', 0),
(8541, 'esMX', 'Excelente. Las necesitábamos, $n. Buen trabajo.', 0);
-- 8542 ¡La Horda necesita lingotes de estaño!
-- https://es.classic.wowhead.com/quest=8542
SET @ID := 8542;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuántos lingotes de estaño tienes, $c? Después de la guerra creo que necesitaré que alguien me enseñe a contar.', 0),
(@ID, 'esMX', '¿Cuántos lingotes de estaño tienes, $c? Después de la guerra creo que necesitaré que alguien me enseñe a contar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, supongo que parece el número correcto de lingotes de estaño. ¡No intentes engañarme, $c! Al contar me duele el cráneo. Ahora voy y pongo estas barras en la pila y tú sales y me traes más de lo mismo.', 0),
(@ID, 'esMX', 'Bueno, supongo que parece el número correcto de lingotes de estaño. ¡No intentes engañarme, $c! Al contar me duele el cráneo. Ahora voy y pongo estas barras en la pila y tú sales y me traes más de lo mismo.', 0);
-- 8543 ¡La Horda necesita más lingotes de estaño!
-- https://es.classic.wowhead.com/quest=8543
SET @ID := 8543;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, veo que te tomas en serio la guerra. Sin embargo, estoy un poco nervioso esperando a que comience, y estoy seguro de que tú también, $n. Será glorioso cuando comience. La Horda corriendo sobre las arenas del desierto de Silithus, armas en mano, cargando de contra las masas de insectos. ¡Ese día todos tendrán un gran honor!$B$B¡Har! Pero primero necesitamos más lingotes de estaño. Es curioso cómo una cosa tan pequeña puede marcar una diferencia tan grande, ¿no crees?', 0),
(@ID, 'esMX', 'Muy bien, veo que te tomas en serio la guerra. Sin embargo, estoy un poco nervioso esperando a que comience, y estoy seguro de que tú también, $n. Será glorioso cuando comience. La Horda corriendo sobre las arenas del desierto de Silithus, armas en mano, cargando de contra las masas de insectos. ¡Ese día todos tendrán un gran honor!$B$B¡Har! Pero primero necesitamos más lingotes de estaño. Es curioso cómo una cosa tan pequeña puede marcar una diferencia tan grande, ¿no crees?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Throm\'ka, $n. Nos honras a mí y a la Horda con tus lingotes de estaño. Los pondré en la pila y luego vendrán y harán cosas con ellos. Y luego, cuando todo esté hecho, iremos a la guerra y le mostraremos a la insignificante Alianza cómo luchar contra los insectos.$B$B¡Ahora tráeme más lingotes de estaño!', 0),
(@ID, 'esMX', 'Throm\'ka, $n. Nos honras a mí y a la Horda con tus lingotes de estaño. Los pondré en la pila y luego vendrán y harán cosas con ellos. Y luego, cuando todo esté hecho, iremos a la guerra y le mostraremos a la insignificante Alianza cómo luchar contra los insectos.$B$B¡Ahora tráeme más lingotes de estaño!', 0);
-- 8544 Las bufas de conquistador
-- https://es.classic.wowhead.com/quest=8544
SET @ID := 8544;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha recogido los componentes que necesito?', 0),
(@ID, 'esMX', '¿Ha recogido los componentes que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con los materiales que traes y de las escamas de nuestros enemigos qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que verte infunda miedo en nuestros enemigos.', 0),
(@ID, 'esMX', 'Con los materiales que traes y de las escamas de nuestros enemigos qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que verte infunda miedo en nuestros enemigos.', 0);
-- 8545 ¡La Horda necesita barras de mitril!
-- https://es.classic.wowhead.com/quest=8545
SET @ID := 8545;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Seguro que sería bueno tener todas las barras de mitril que necesitamos pa\' el esfuerzo bélico de Ahn\'Qiraj. ¿Es por eso qu\'has vuelto, colega? ¿Tienes mis barras?', 0),
(@ID, 'esMX', 'Seguro que sería bueno tener todas las barras de mitril que necesitamos pa\' el esfuerzo bélico de Ahn\'Qiraj. ¿Es por eso qu\'has vuelto, colega? ¿Tienes mis barras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este será un buen comienzo pa\' ti y pa\' mí, $n. Son otras veinte barras de mitril que puedo poner en las pilas y marcar fuera de la lista. Todo se v\'a aprovechar pa\' hacer el material de guerra.$B$BAsegúrate de volver a verme porque ¿sabes que?, parece que vamos a necesitar más d\'esas barras de mitril.', 0),
(@ID, 'esMX', 'Este será un buen comienzo pa\' ti y pa\' mí, $n. Son otras veinte barras de mitril que puedo poner en las pilas y marcar fuera de la lista. Todo se v\'a aprovechar pa\' hacer el material de guerra.$B$BAsegúrate de volver a verme porque ¿sabes que?, parece que vamos a necesitar más d\'esas barras de mitril.', 0);
-- 8546 ¡La Horda necesita más barras de mitril!
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=8546
SET @ID := 8546;
UPDATE `quest_request_items` SET `CompletionText` = 'Yup, I be glad you\'re here, mon. You helped me before, and now I need your help again. We still lookin\' ta bring in more mithril bars for the war effort; gonna build lots of armor and weapons and things to go squish them bugs at Ahn\'Qiraj.$B$BSo if you be a true friend, you bring me back more stacks of mithril bars. I take all you got until we hit our quota. You have some for me now?', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, m’alegro qu’hayas venío, colega. M’has ayudao antes y ahora vuelvo a necesitarte. Entoavía hay que traer más lingotes de mitril pa’ los preparativos de la guerra; vamos a construir un montón d’armaduras, armas y tal y tal pa\' aplastar a esos bichos d’Ahn\'Qiraj.$B$BSi eres $gun amigo:una amiga; de verdad, tráeme más pilas de lingotes de mitril. Me lo quedaré to\' hasta qu\'alcancemos nuestro cupo. ¿No tendrás algunos pa’ mí ahora?', 0),
(@ID, 'esMX', 'Sí, m’alegro qu’hayas venío, colega. M’has ayudao antes y ahora vuelvo a necesitarte. Entoavía hay que traer más lingotes de mitril pa’ los preparativos de la guerra; vamos a construir un montón d’armaduras, armas y tal y tal pa\' aplastar a esos bichos d’Ahn\'Qiraj.$B$BSi eres $gun amigo:una amiga; de verdad, tráeme más pilas de lingotes de mitril. Me lo quedaré to\' hasta qu\'alcancemos nuestro cupo. ¿No tendrás algunos pa’ mí ahora?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un trabajo increíble, $n! Otros 20 lingotes y nos acercaremos al objetivo y tendremos más material pa\' la guerra. M’ocuparé de que lo guarden. Y si consigues otro montón de lingotes de mitril, asegúrate de que los traes a la menda.', 0),
(@ID, 'esMX', '¡Un trabajo increíble, $n! Otros 20 lingotes y nos acercaremos al objetivo y tendremos más material pa\' la guerra. M’ocuparé de que lo guarden. Y si consigues otro montón de lingotes de mitril, asegúrate de que los traes a la menda.', 0);
-- 8548 Equipamiento de Voluntario
-- https://es.classic.wowhead.com/quest=8548
SET @ID := 8548;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0),
(@ID, 'esMX', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:maiga;!', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:maiga;!', 0);
-- 8549 ¡La Horda necesita flores de paz!
-- https://es.classic.wowhead.com/quest=8549
SET @ID := 8549;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vete ahora, $n. Busca, $n.', 0),
(@ID, 'esMX', 'Vete ahora, $n. Busca, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No ha sido una tarea fácil, pero has sobresalido. Claro que no te apresures a pensar que me has impresionado, $n.', 0),
(@ID, 'esMX', 'No ha sido una tarea fácil, pero has sobresalido. Claro que no te apresures a pensar que me has impresionado, $n.', 0);
-- 8550 ¡La Horda necesita más flores de paz!
-- https://es.classic.wowhead.com/quest=8550
SET @ID := 8550;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tus continuos esfuerzos, $n. Te traes un gran honor a ti $gmismo:misma; y a tus antepasados con tu generosidad desinteresada, ¡y todos lo sabrán! Guardaré estas hierbas para que se mantengan frescas hasta que se necesiten. Una vez más, revelas el verdadero espíritu de la Horda, la lucha por vencer y la promesa de que podemos trabajar juntos para lograrlo.', 0),
(@ID, 'esMX', 'Gracias por tus continuos esfuerzos, $n. Te traes un gran honor a ti $gmismo:misma; y a tus antepasados con tu generosidad desinteresada, ¡y todos lo sabrán! Guardaré estas hierbas para que se mantengan frescas hasta que se necesiten. Una vez más, revelas el verdadero espíritu de la Horda, la lucha por vencer y la promesa de que podemos trabajar juntos para lograrlo.', 0);
-- 8551 El cofre del Capitán
-- https://es.classic.wowhead.com/quest=8551
SET @ID := 8551;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buenas, $n! ¿Has encontrado a Gorlash? Ese cofre era mi favorito y tiene un compartimiento oculto donde guardaba mis mayores tesoros.', 0),
(@ID, 'esMX', '¡Buenas, $n! ¿Has encontrado a Gorlash? Ese cofre era mi favorito y tiene un compartimiento oculto donde guardaba mis mayores tesoros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La has encontrado! ¡Oh, qué día tan feliz! Gracias, $n. Recuperar mi cofre hace que se enfríe el fuego que arde en mi interior.$B$BPero mi venganza todavía no ha terminado...', 0),
(@ID, 'esMX', '¡La has encontrado! ¡Oh, qué día tan feliz! Gracias, $n. Recuperar mi cofre hace que se enfríe el fuego que arde en mi interior.$B$BPero mi venganza todavía no ha terminado...', 0);
-- 8552 La banda con monograma
-- https://es.classic.wowhead.com/quest=8552
SET @ID := 8552;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Tienes algo de lo que hablar conmigo?', 0),
(@ID, 'esMX', '¡Hola! ¿Tienes algo de lo que hablar conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado mi banda? Entonces... tienes que haber matado a ese gigante marino Mok\'rash. ¡Hurra!$B$BMe alegro de que ese villano asqueroso esté muerto. Mok\'rash fue uno de los tres gigantes marinos que destrozó mis barcos y mató a mi tripulación.$B$BTres veces.$B$BEres $gun:una; $c de gran valía, $n.', 0),
(@ID, 'esMX', '¿Has recuperado mi banda? Entonces... tienes que haber matado a ese gigante marino Mok\'rash. ¡Hurra!$B$BMe alegro de que ese villano asqueroso esté muerto. Mok\'rash fue uno de los tres gigantes marinos que destrozó mis barcos y mató a mi tripulación.$B$BTres veces.$B$BEres $gun:una; $c de gran valía, $n.', 0);
