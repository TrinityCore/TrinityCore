-- 9545 La reliquia del vidente
-- https://es.wowhead.com/quest=9545
SET @ID := 9545;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Visión concedida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tuviste la visión, $n?', 0),
(@ID, 'esMX', '¿Tuviste la visión, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que la visión que tuviste te haya ayudado a comprender mejor la muerte de Sedai. La reliquia te mostró una serie probable de acontecimientos que conducen al presente. Puede que la realidad fuera otra; no tenemos modo de saberlo.$B$B¿Actuarás de otro modo ahora que sabes lo que sabes?$B$B¿Quién puede saber si seguiremos en conflicto con los orcos? Lo importante es mantenerse abiertos a todas las posibilidades.', 0),
(@ID, 'esMX', 'Espero que la visión que tuviste te haya ayudado a comprender mejor la muerte de Sedai. La reliquia te mostró una serie probable de acontecimientos que conducen al presente. Puede que la realidad fuera otra; no tenemos modo de saberlo.$B$B¿Actuarás de otro modo ahora que sabes lo que sabes?$B$B¿Quién puede saber si seguiremos en conflicto con los orcos? Lo importante es mantenerse abiertos a todas las posibilidades.', 0);
-- 9546 Una promesa por cumplir
-- https://es.wowhead.com/quest=9546
SET @ID := 9546;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cautivo Semprepino liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- La llamada del aire
-- 9547, 9551
-- https://es.wowhead.com/quest=9547
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9547, 9551) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9547, 'esES', 'Y finalmente llegamos a él, el último de los cuatro grandes elementos: el aire. ¿Te crees lo suficientemente $gsabio:sabia; para continuar, $n?', 0),
(9551, 'esES', 'Y finalmente llegamos a él, el último de los cuatro grandes elementos: el aire. ¿Te crees lo suficientemente $gsabio:sabia; para continuar, $n?', 0),
(9547, 'esMX', 'Y finalmente llegamos a él, el último de los cuatro grandes elementos: el aire. ¿Te crees lo suficientemente $gsabio:sabia; para continuar, $n?', 0),
(9551, 'esMX', 'Y finalmente llegamos a él, el último de los cuatro grandes elementos: el aire. ¿Te crees lo suficientemente $gsabio:sabia; para continuar, $n?', 0);
-- 9548 Equipamiento robado
-- https://es.wowhead.com/quest=9548
SET @ID := 9548;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado encontrar mi equipamiento?', 0),
(@ID, 'esMX', '¿Has logrado encontrar mi equipamiento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es fantástico! ¡Con el robo de mi equipamiento he alcanzado mayor percepción de la naturaleza de estos múrlocs de lo que posiblemente habría logrado en varias semanas de observación!$B$BYa sé lo que voy a decir en mi informe.$B$B\'Cuando se encuentran con productos de una cultura tecnológicamente superior, los Cienonegro no mostraron ninguna de las características de curiosidad de las culturas emergentes en las especies humanoides.\'$B$B¡Es brillante! ¡A los caballeros de Forjaz les va a encantar! Cualquier agradecimiento se queda corto, $n.', 0),
(@ID, 'esMX', '¡Esto es fantástico! ¡Con el robo de mi equipamiento he alcanzado mayor percepción de la naturaleza de estos múrlocs de lo que posiblemente habría logrado en varias semanas de observación!$B$BYa sé lo que voy a decir en mi informe.$B$B\'Cuando se encuentran con productos de una cultura tecnológicamente superior, los Cienonegro no mostraron ninguna de las características de curiosidad de las culturas emergentes en las especies humanoides.\'$B$B¡Es brillante! ¡A los caballeros de Forjaz les va a encantar! Cualquier agradecimiento se queda corto, $n.', 0);
-- 9549 Los artefactos de los Cienonegro
-- https://es.wowhead.com/quest=9549
SET @ID := 9549;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esas muestras para que las envíe de vuelta a Forjaz?', 0),
(@ID, 'esMX', '¿Tienes esas muestras para que las envíe de vuelta a Forjaz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Asombroso, sencillamente asombroso! Son perfectos, $n. Ya los veo en su urna de cristal en el museo de Forjaz. ¡Prácticamente se escribe ya en mi cabeza el texto de presentación!$B$BTu ayuda ha sido valiosísima en conseguir que mis estudios se encarrilaran. ¿Cómo se escribe tu nombre? Me aseguraré de que figuras en mi informe como $gcoautor:coautora;.$B$BUno de los chicos del barco me dio este \'mapa del tesoro\' para saldar una deuda de juego pero la mitología no es mi campo. Pandilla de supersticiosos esos marineros.', 0),
(@ID, 'esMX', '¡Asombroso, sencillamente asombroso! Son perfectos, $n. Ya los veo en su urna de cristal en el museo de Forjaz. ¡Prácticamente se escribe ya en mi cabeza el texto de presentación!$B$BTu ayuda ha sido valiosísima en conseguir que mis estudios se encarrilaran. ¿Cómo se escribe tu nombre? Me aseguraré de que figuras en mi informe como $gcoautor:coautora;.$B$BUno de los chicos del barco me dio este \'mapa del tesoro\' para saldar una deuda de juego pero la mitología no es mi campo. Pandilla de supersticiosos esos marineros.', 0);
-- 9550 Un mapa con destino desconocido
-- https://es.wowhead.com/quest=9550
SET @ID := 9550;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás el viejo diario sea a lo que el mapa se refiere.', 0),
(@ID, 'esMX', 'Quizás el viejo diario sea a lo que el mapa se refiere.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tras un cuidadoso examen, concluyes que debe de ser un diario. Sus páginas están escritas con una letra elegante distinta a la del mapa. El texto en muchas páginas está oscurecido por dibujos y anotaciones en la mano del autor del mapa.$B$BEs casi imposible llegar a leer el texto debajo de los relatos que el autor del mapa hace de las juergas y borracheras durante un permiso en tierra.', 0),
(@ID, 'esMX', 'Tras un cuidadoso examen, concluyes que debe de ser un diario. Sus páginas están escritas con una letra elegante distinta a la del mapa. El texto en muchas páginas está oscurecido por dibujos y anotaciones en la mano del autor del mapa.$B$BEs casi imposible llegar a leer el texto debajo de los relatos que el autor del mapa hace de las juergas y borracheras durante un permiso en tierra.', 0);
-- 9552 La llamada del aire
-- https://es.wowhead.com/quest=9552
SET @ID := 9552;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me susurraron en los vientos que vendrías, $n.$B$BEl clarividente Nobundo piensa muy bien de tí, y por lo que he oído de tus viajes, yo también.', 0),
(@ID, 'esMX', 'Me susurraron en los vientos que vendrías, $n.$B$BEl clarividente Nobundo piensa muy bien de tí, y por lo que he oído de tus viajes, yo también.', 0);
-- 9553 La llamada del aire
-- https://es.wowhead.com/quest=9553
SET @ID := 9553;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado esperando tu llegada, $n. Vienes buscando sabiduría, y siento algo más.$B$BMuy bien, comencemos.', 0),
(@ID, 'esMX', 'He estado esperando tu llegada, $n. Vienes buscando sabiduría, y siento algo más.$B$BMuy bien, comencemos.', 0);
-- 9554 La llamada del aire
-- https://es.wowhead.com/quest=9554
SET @ID := 9554;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto? Tu cabello se ve despeinado.$B$B<Nobundo sonríe con complicidad.>', 0),
(@ID, 'esMX', '¿Regresaste tan pronto? Tu cabello se ve despeinado.$B$B<Nobundo sonríe con complicidad.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy orgulloso de ti, $n. Ha perseverado donde otros vacilan, y en el proceso has ganado mayor comprensión de los elementos y de tí $gmismo:misma;. Recuerda tus lecciones a medida que avanzas por la vida y serás más $gsabio:sabia; por ello.$B$BAhora, dame la espiral de aire para que pueda imbuirla en tu tótem de aire. Al igual que con los otros tótems, servirá como foco y como recordatorio de la conexión que has forjado con los elementos.', 0),
(@ID, 'esMX', 'Estoy orgulloso de ti, $n. Ha perseverado donde otros vacilan, y en el proceso has ganado mayor comprensión de los elementos y de tí $gmismo:misma;. Recuerda tus lecciones a medida que avanzas por la vida y serás más $gsabio:sabia; por ello.$B$BAhora, dame la espiral de aire para que pueda imbuirla en tu tótem de aire. Al igual que con los otros tótems, servirá como foco y como recordatorio de la conexión que has forjado con los elementos.', 0);
-- 9555 La llamada del fuego
-- https://es.wowhead.com/quest=9555
SET @ID := 9555;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. Siempre es alentador conocer a $gun:una; $r que está $gabierto:abierta; al camino del chamanismo. Son tan pocos.$B$BHas aprendido a no juzgar la llama por su apariencia exterior, como no debes juzgar la mía.$B$BEstás aquí porque estás $glisto:lista; para crear tu tótem de fuego.', 0),
(@ID, 'esMX', 'Saludos. Siempre es alentador conocer a $gun:una; $r que está $gabierto:abierta; al camino del chamanismo. Son tan pocos.$B$BHas aprendido a no juzgar la llama por su apariencia exterior, como no debes juzgar la mía.$B$BEstás aquí porque estás $glisto:lista; para crear tu tótem de fuego.', 0);
-- 9557 Descifrar el libro
-- https://es.wowhead.com/quest=9557
SET @ID := 9557;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la Luz brille sobre ti y todo lo que emprendas, $c. ¿Qué tienes ahí?', 0),
(@ID, 'esMX', 'Que la Luz brille sobre ti y todo lo que emprendas, $c. ¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... esto es de lo más fascinante. Sí, debería conseguir entender lo que el autor original escribió en las páginas de este libro.$B$BDebería tener todo lo que necesito para ello. Solo debería ser un segundo.', 0),
(@ID, 'esMX', 'Mmm... esto es de lo más fascinante. Sí, debería conseguir entender lo que el autor original escribió en las páginas de este libro.$B$BDebería tener todo lo que necesito para ello. Solo debería ser un segundo.', 0);
-- 9558 Los Barbalarga
-- https://es.wowhead.com/quest=9558
SET @ID := 9558;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo nos has encontrado, $c? No importa, supongo que te enviaron a echarnos una mano. Bien, ¡a trabajar!', 0),
(@ID, 'esMX', '¿Cómo nos has encontrado, $c? No importa, supongo que te enviaron a echarnos una mano. Bien, ¡a trabajar!', 0);
-- 9559 El Bastión Semprepino
-- https://es.wowhead.com/quest=9559
SET @ID := 9559;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Durante siglos, hemos convivido relativamente en paz con las criaturas de esta tierra. Hace unos meses, Kurz empezó a ver augurios oscuros. La paz que durante tiempo habíamos disfrutado se iba a acabar. ¡No se podía saber el alcance de la catástrofe!$B$BAl parecer los dioses iban a destruir nuestra tierra, volviendo a amigos y a enemigos en contra nuestra. Pero había algo más... En medio del caos, $gun héroe:una heroína; se levantaría, $gun héroe:una heroína; de sangre distinta a los Semprepino. $gEl Prometido:La Prometida; nos libraría de la destrucción total.$B$B<El héroe/La heroína de la profecía eras tú.', 0),
(@ID, 'esMX', 'Durante siglos, hemos convivido relativamente en paz con las criaturas de esta tierra. Hace unos meses, Kurz empezó a ver augurios oscuros. La paz que durante tiempo habíamos disfrutado se iba a acabar. ¡No se podía saber el alcance de la catástrofe!$B$BAl parecer los dioses iban a destruir nuestra tierra, volviendo a amigos y a enemigos en contra nuestra. Pero había algo más... En medio del caos, $gun héroe:una heroína; se levantaría, $gun héroe:una heroína; de sangre distinta a los Semprepino. $gEl Prometido:La Prometida; nos libraría de la destrucción total.$B$B<El héroe/La heroína de la profecía eras tú.', 0);
-- 9560 ¡Las bestias del apocalipsis!
-- https://es.wowhead.com/quest=9560
SET @ID := 9560;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son unas criaturitas muy feas. Hasta el vigía ciego podía verlas... y es ciego.', 0),
(@ID, 'esMX', 'Son unas criaturitas muy feas. Hasta el vigía ciego podía verlas... y es ciego.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No solo es cierta la profecía, ¡esta armadura también es impresionante! ¡No hay duda de que es una armadura para campeones! Y te la venderé con descuento, valiente.$B$BAh... La primera pieza es de regalo.', 0),
(@ID, 'esMX', 'No solo es cierta la profecía, ¡esta armadura también es impresionante! ¡No hay duda de que es una armadura para campeones! Y te la venderé con descuento, valiente.$B$BAh... La primera pieza es de regalo.', 0);
-- 9561 Las palabras de Nolkai
-- https://es.wowhead.com/quest=9561
SET @ID := 9561;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La hierba y los arbustos cubren una elevación anormal del terreno.$B$BDespués de cavar unos minutos hallas una caja vieja, casi con toda seguridad es la mencionada en el diario de Nolkai.', 0),
(@ID, 'esMX', 'La hierba y los arbustos cubren una elevación anormal del terreno.$B$BDespués de cavar unos minutos hallas una caja vieja, casi con toda seguridad es la mencionada en el diario de Nolkai.', 0);
-- 9562 Múrlocs... ¿Por qué?
-- https://es.wowhead.com/quest=9562
SET @ID := 9562;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un múrloc me pateó el trasero y me escupió... ¡a plena luz del día!', 0),
(@ID, 'esMX', 'Un múrloc me pateó el trasero y me escupió... ¡a plena luz del día!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, grano... ¡Qué contento se va a poner Parkat!', 0),
(@ID, 'esMX', 'Mmm, grano... ¡Qué contento se va a poner Parkat!', 0);
-- 9563 Ganar la confianza de Mirren
-- https://es.wowhead.com/quest=9563
SET @ID := 9563;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No encuentras la cerveza? El bueno de Bernie debe de tener varios barriles en el Castillo de Nethergarde.$B$BA no ser que se le haya acabado, ¡eso sería desastroso!', 0),
(@ID, 'esMX', '¿No encuentras la cerveza? El bueno de Bernie debe de tener varios barriles en el Castillo de Nethergarde.$B$BA no ser que se le haya acabado, ¡eso sería desastroso!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! Tienes cara de $gbuen:buena; $r. Supongo que se puede confiar en ti.', 0),
(@ID, 'esMX', '¡Estupendo! Tienes cara de $gbuen:buena; $r. Supongo que se puede confiar en ti.', 0);
-- 9564 La dignidad de Gurf
-- https://es.wowhead.com/quest=9564
SET @ID := 9564;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eso es lo que creo que es?', 0),
(@ID, 'esMX', '¿Eso es lo que creo que es?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gurf escupe en el montón de piel e intenta pegarlo en la calva de su espalda.>$B$B¡Me tendré que apañar con esto por ahora! Espero que uno de los chamanes sea capaz de reparar el daño.', 0),
(@ID, 'esMX', '<Gurf escupe en el montón de piel e intenta pegarlo en la calva de su espalda.>$B$B¡Me tendré que apañar con esto por ahora! Espero que uno de los chamanes sea capaz de reparar el daño.', 0);
-- 9565 Registra el Bastión Semprepino
-- https://es.wowhead.com/quest=9565
SET @ID := 9565;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cristal de sangre irradia un halo asqueroso que se filtra en el agua de la caverna.', 0),
(@ID, 'esMX', 'El cristal de sangre irradia un halo asqueroso que se filtra en el agua de la caverna.', 0);
-- 9566 Cristales de sangre
-- https://es.wowhead.com/quest=9566
SET @ID := 9566;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos cristales de sangre que viste... mis exploradores han visto muchos hacia el norte.$B$BTe agradezco la ayuda pero ahora te pido que me dejes para consultar a los ancianos. Te llamaré después de haber hablado con los ancianos de la aldea.', 0),
(@ID, 'esMX', 'Estos cristales de sangre que viste... mis exploradores han visto muchos hacia el norte.$B$BTe agradezco la ayuda pero ahora te pido que me dejes para consultar a los ancianos. Te llamaré después de haber hablado con los ancianos de la aldea.', 0);
-- 9567 Conoce a tu enemigo
-- https://es.wowhead.com/quest=9567
SET @ID := 9567;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido obtener el conocimiento de los sátiros Nazzivus?', 0),
(@ID, 'esMX', '¿Has conseguido obtener el conocimiento de los sátiros Nazzivus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. A ver qué puedo averiguar con este glifo para que podamos planificar nuestro movimiento siguiente.', 0),
(@ID, 'esMX', 'Muy bien, $n. A ver qué puedo averiguar con este glifo para que podamos planificar nuestro movimiento siguiente.', 0);
-- 9569 Contener la amenaza
-- https://es.wowhead.com/quest=9569
SET @ID := 9569;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La mirada de la vindicadora Aalesia parece perderse más allá de ti más que en ti, los pensamientos fijos en cómo enfrentarse al sátiro.>$B$B¿Has ido a por el líder sátiro como te pedí?', 0),
(@ID, 'esMX', '<La mirada de la vindicadora Aalesia parece perderse más allá de ti más que en ti, los pensamientos fijos en cómo enfrentarse al sátiro.>$B$B¿Has ido a por el líder sátiro como te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin su líder, y con la recuperación de los cristales corruptos bien encaminada, podemos mantener a los sátiros a raya. Solo la Luz sabe cuántas de estas desdichadas criaturas hay ahí fuera.$B$BEl presagista Mikolaas y yo te agradecemos la ayuda que has prestado para combatir a los sátiros antes de que se convirtieran en una amenaza mayor. Tu trabajo es un recordatorio de que la vigilancia es la clave de la victoria sobre la Legión y sus esbirros.', 0),
(@ID, 'esMX', 'Sin su líder, y con la recuperación de los cristales corruptos bien encaminada, podemos mantener a los sátiros a raya. Solo la Luz sabe cuántas de estas desdichadas criaturas hay ahí fuera.$B$BEl presagista Mikolaas y yo te agradecemos la ayuda que has prestado para combatir a los sátiros antes de que se convirtieran en una amenaza mayor. Tu trabajo es un recordatorio de que la vigilancia es la clave de la victoria sobre la Legión y sus esbirros.', 0);
-- 9570 El Kurken acecha
-- https://es.wowhead.com/quest=9570
SET @ID := 9570;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kurz emite un gruñido.>', 0),
(@ID, 'esMX', '<Kurz emite un gruñido.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$gEl Prometido:La Prometida; ha resultado $gvictorioso:victoriosa;!$B$BLa profecía casi se ha completado. Y en cuanto a ese pellejo...', 0),
(@ID, 'esMX', '¡$gEl Prometido:La Prometida; ha resultado $gvictorioso:victoriosa;!$B$BLa profecía casi se ha completado. Y en cuanto a ese pellejo...', 0);
-- 9571 El pellejo de El Kurken
-- https://es.wowhead.com/quest=9571
SET @ID := 9571;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, $ghéroe:heroína;!', 0),
(@ID, 'esMX', '¡Hola, $ghéroe:heroína;!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta es la armadura más resistente que jamás haya hecho! Úsala bien, $n.', 0),
(@ID, 'esMX', '¡Esta es la armadura más resistente que jamás haya hecho! Úsala bien, $n.', 0);
-- 9572 Debilitar la muralla
-- https://es.wowhead.com/quest=9572
SET @ID := 9572;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿verdad? Stok\'ton me dijo que esperara tu informe.$B$B¿Confío en que traigas buenas noticias?', 0),
(@ID, 'esMX', '$n, ¿verdad? Stok\'ton me dijo que esperara tu informe.$B$B¿Confío en que traigas buenas noticias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un buen comienzo. Con esos tres muertos, sus fuerzas deberían estar dispersas. ¡Y con su artillería silenciada, nos será más fácil acercarnos lo suficiente para tomar la ciudadela!$B$BPero hay más en esto de lo que parece, puedo sentirlo, así que voy a tener algo más para que lo hagas.$B$BPor el momento lo has hecho bien. Elige uno de estos de la armería de Thrallmar.', 0),
(@ID, 'esMX', 'Es un buen comienzo. Con esos tres muertos, sus fuerzas deberían estar dispersas. ¡Y con su artillería silenciada, nos será más fácil acercarnos lo suficiente para tomar la ciudadela!$B$BPero hay más en esto de lo que parece, puedo sentirlo, así que voy a tener algo más para que lo hagas.$B$BPor el momento lo has hecho bien. Elige uno de estos de la armería de Thrallmar.', 0);
-- 9573 El cabecilla Oomooroo
-- https://es.wowhead.com/quest=9573
SET @ID := 9573;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La tarea está completa?', 0),
(@ID, 'esMX', '¿La tarea está completa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta podría ser la oportunidad que nos hacía falta! ¡Lanzaré un ataque inmediatamente! ¡Los Semprepino te agradecen el servicio, $n!', 0),
(@ID, 'esMX', '¡Esta podría ser la oportunidad que nos hacía falta! ¡Lanzaré un ataque inmediatamente! ¡Los Semprepino te agradecen el servicio, $n!', 0);
-- 9574 Víctimas de la corrupción
-- https://es.wowhead.com/quest=9574
SET @ID := 9574;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido ya las muestras que necesito?', 0),
(@ID, 'esMX', '¿Has conseguido ya las muestras que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay más que suficiente aquí para mi investigación. Gracias, $n. Si encuentras cualquier otra prueba de que los cristales están corrompiendo las criaturas originarias de Bruma de Sangre, házmelo saber enseguida.', 0),
(@ID, 'esMX', 'Hay más que suficiente aquí para mi investigación. Gracias, $n. Si encuentras cualquier otra prueba de que los cristales están corrompiendo las criaturas originarias de Bruma de Sangre, házmelo saber enseguida.', 0);
-- 9575 Debilitar la muralla
-- https://es.wowhead.com/quest=9575
SET @ID := 9575;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿verdad? Chadwick me dijo que esperara tu informe.$B$B¡¿Qué estás haciendo en mi presencia?! ¿Está completa tu tarea? ¿Eres $gun completo y absoluto tonto:una completa y absoluta tonta;? ¡Me dan ganas de vomitar!$B$B¡Ahora coloca tu inútil trasero en esas murallas y haz lo que se te indicó que hicieras! ¡¿Me escuchas?!', 0),
(@ID, 'esMX', '$n, ¿verdad? Chadwick me dijo que esperara tu informe.$B$B¡¿Qué estás haciendo en mi presencia?! ¿Está completa tu tarea? ¿Eres $gun completo y absoluto tonto:una completa y absoluta tonta;? ¡Me dan ganas de vomitar!$B$B¡Ahora coloca tu inútil trasero en esas murallas y haz lo que se te indicó que hicieras! ¡¿Me escuchas?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sabes qué odio más que equivocarme? Perder oro en una apuesta que no pudiste lograr, cariño.$B$B¡Sobresaliente! Con esos tres muertos, sus fuerzas deberían estar dispersas. ¡Y con su artillería silenciada, nos será más fácil acercarnos lo suficiente para tomar la ciudadela!$B$BSin embargo, tengo la sensación de que hay más en esto de lo que parece a simple vista, así que voy a tener algo más para que hagas. Toma, toma uno de estos de la armería.', 0),
(@ID, 'esMX', '¿Sabes qué odio más que equivocarme? Perder oro en una apuesta que no pudiste lograr, cariño.$B$B¡Sobresaliente! Con esos tres muertos, sus fuerzas deberían estar dispersas. ¡Y con su artillería silenciada, nos será más fácil acercarnos lo suficiente para tomar la ciudadela!$B$BSin embargo, tengo la sensación de que hay más en esto de lo que parece a simple vista, así que voy a tener algo más para que hagas. Toma, toma uno de estos de la armería.', 0);
-- 9576 El colgante de Aleta Cruel
-- https://es.wowhead.com/quest=9576
SET @ID := 9576;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es muy curioso, $n. No creo que hayamos visto a los múrlocs con ningún tipo de adorno antes.$B$BDada la influencia corruptora que se sabe que tienen los fragmentos de cristal, el múrloc que llevaba este colgante debe haber creído que le otorgaba poder sobre sus compañeros. No me sorprendería que hubiera superado rápidamente a sus compañeros múrlocs y hubiera ganado fuerza.', 0),
(@ID, 'esMX', 'Esto es muy curioso, $n. No creo que hayamos visto a los múrlocs con ningún tipo de adorno antes.$B$BDada la influencia corruptora que se sabe que tienen los fragmentos de cristal, el múrloc que llevaba este colgante debe haber creído que le otorgaba poder sobre sus compañeros. No me sorprendería que hubiera superado rápidamente a sus compañeros múrlocs y hubiera ganado fuerza.', 0);
-- 9578 En busca de Galaen
-- https://es.wowhead.com/quest=9578
SET @ID := 9578;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cadáver parece vestido como un técnico de El Exodar pero el colgante que Morae describió no está.', 0),
(@ID, 'esMX', 'El cadáver parece vestido como un técnico de El Exodar pero el colgante que Morae describió no está.', 0);
-- 9579 El sino de Galaen
-- https://es.wowhead.com/quest=9579
SET @ID := 9579;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Morae te mira esperanzada.>$B$B¿Has hallado alguna huella de Galaen?', 0),
(@ID, 'esMX', '<Morae te mira esperanzada.>$B$B¿Has hallado alguna huella de Galaen?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Le cuentas a Morae tus hallazgos en los restos de El Crionúcleo.>$B$BAsí que... está...$B$BSupongo que una parte de mí lo sabía pero no me resignaba a creerlo. No es la noticia que esperaba pero tienes mi profunda gratitud por encontrar a Galaen.', 0),
(@ID, 'esMX', '<Le cuentas a Morae tus hallazgos en los restos de El Crionúcleo.>$B$BAsí que... está...$B$BSupongo que una parte de mí lo sabía pero no me resignaba a creerlo. No es la noticia que esperaba pero tienes mi profunda gratitud por encontrar a Galaen.', 0);
-- 9580 Las necesidades del oso
-- https://es.wowhead.com/quest=9580
SET @ID := 9580;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $n?', 0),
(@ID, 'esMX', '¿Cómo va la caza, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con esto tenemos los suministros cubiertos por un tiempo y prepararlo para su consumo ciertamente me mantendrá ocupado. Gracias por tu ayuda, $n.', 0),
(@ID, 'esMX', 'Con esto tenemos los suministros cubiertos por un tiempo y prepararlo para su consumo ciertamente me mantendrá ocupado. Gracias por tu ayuda, $n.', 0);
-- 9581 Las lecciones de los cristales
-- https://es.wowhead.com/quest=9581
SET @ID := 9581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has podido recolectar la primera muestra de cristal?', 0),
(@ID, 'esMX', '¿Has podido recolectar la primera muestra de cristal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este fragmento de cristal dará a nuestros investigadores una referencia con la que comparar muestras de otros lugares de la isla ya que procede de una de las regiones menos corruptas de Bruma de Sangre.$B$BNo podré enviarlo hasta que tengamos un serie completa de muestras pero esto es un gran comienzo. Si deseas ayudar a recolectar más muestras, me ocuparé de que te recompensen por tu contribución.', 0),
(@ID, 'esMX', 'Este fragmento de cristal dará a nuestros investigadores una referencia con la que comparar muestras de otros lugares de la isla ya que procede de una de las regiones menos corruptas de Bruma de Sangre.$B$BNo podré enviarlo hasta que tengamos un serie completa de muestras pero esto es un gran comienzo. Si deseas ayudar a recolectar más muestras, me ocuparé de que te recompensen por tu contribución.', 0);
-- 9582 La fuerza de uno solo
-- https://es.wowhead.com/quest=9582
SET @ID := 9582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a la bestia?', 0),
(@ID, 'esMX', '¿Has matado a la bestia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ruada asiente solemnemente.>$B$BEntonces esta hecho.$B$BEstás listo para tu próxima lección, $n, pero no seré yo quien te la enseñe.', 0),
(@ID, 'esMX', '<Ruada asiente solemnemente.>$B$BEntonces esta hecho.$B$BEstás listo para tu próxima lección, $n, pero no seré yo quien te la enseñe.', 0);
-- 9584 La segunda muestra
-- https://es.wowhead.com/quest=9584
SET @ID := 9584;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la segunda muestra de cristal?', 0),
(@ID, 'esMX', '¿Tienes la segunda muestra de cristal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El presagista Mikolaas examina el fragmento de cristal.>$B$BEste fragmento es muy diferente al de la primera muestra.$B$B<El presagista Mikolaas sube el cristal para verlo con más luz.>$B$B¿Ves cómo late? Es preocupante. Haré un apunte en mi informe sobre las alteraciones que los elfos de sangre parecen haberle hecho al cristal. Gracias otra vez por tu ayuda, $n.', 0),
(@ID, 'esMX', '<El presagista Mikolaas examina el fragmento de cristal.>$B$BEste fragmento es muy diferente al de la primera muestra.$B$B<El presagista Mikolaas sube el cristal para verlo con más luz.>$B$B¿Ves cómo late? Es preocupante. Haré un apunte en mi informe sobre las alteraciones que los elfos de sangre parecen haberle hecho al cristal. Gracias otra vez por tu ayuda, $n.', 0);
-- 9585 La última muestra
-- https://es.wowhead.com/quest=9585
SET @ID := 9585;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes la muestra que te pedí?', 0),
(@ID, 'esMX', '¿Me traes la muestra que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El presagista Mikolaas coge el cristal que le das.>$B$BYa tengo todo el juego. Ahora solo tengo que empaquetarlos y enviarlos a El Exodar.$B$B<Parece alegrarse mucho de haber terminado.>$B$BNo me malinterpretes, $n; seguro que la investigación es importante, pero tenemos problemas más urgentes que atender.', 0),
(@ID, 'esMX', '<El presagista Mikolaas coge el cristal que le das.>$B$BYa tengo todo el juego. Ahora solo tengo que empaquetarlos y enviarlos a El Exodar.$B$B<Parece alegrarse mucho de haber terminado.>$B$BNo me malinterpretes, $n; seguro que la investigación es importante, pero tenemos problemas más urgentes que atender.', 0);
-- 9586 Ayudar a Tavara
-- https://es.wowhead.com/quest=9586
SET @ID := 9586;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Sana a Tavara', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado a Tavara?', 0),
(@ID, 'esMX', '¿Has encontrado a Tavara?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por ayudar a Tavara. Muchos no están familiarizados con estas tierras y encuentran problemas donde menos se lo esperan.$B$BMe honraría si usaras esta toga. Te marcan como uno de los protectores de la Avanzada Azur y $gun devoto seguidor:una devota seguidora; de la Luz.', 0),
(@ID, 'esMX', 'Gracias por ayudar a Tavara. Muchos no están familiarizados con estas tierras y encuentran problemas donde menos se lo esperan.$B$BMe honraría si usaras esta toga. Te marcan como uno de los protectores de la Avanzada Azur y $gun devoto seguidor:una devota seguidora; de la Luz.', 0);
-- 9587 Aciagas nuevas
-- https://es.wowhead.com/quest=9587
SET @ID := 9587;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $ghijo:hija;?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $ghijo:hija;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está firmado por Illidan, dices? Déjame ver eso.$B$B<El comandante lee la carta y luego otra vez, pensando un momento antes de continuar.>$B$BEsta noticia que traes es realmente preocupante. Sabiendo esto, debemos acelerar nuestros planes contra la Ciudadela del Fuego Infernal y El Horno de Sangre. Debido a que has demostrado que puedes hacer el trabajo, quiero que dirijas esos planes.$B$BGunny te dará tu próxima misión, aunque sospecho que será mucho más mortífera que la primera.$B$B¡Que la Luz te acompañe, $n!', 0),
(@ID, 'esMX', '¿Está firmado por Illidan, dices? Déjame ver eso.$B$B<El comandante lee la carta y luego otra vez, pensando un momento antes de continuar.>$B$BEsta noticia que traes es realmente preocupante. Sabiendo esto, debemos acelerar nuestros planes contra la Ciudadela del Fuego Infernal y El Horno de Sangre. Debido a que has demostrado que puedes hacer el trabajo, quiero que dirijas esos planes.$B$BGunny te dará tu próxima misión, aunque sospecho que será mucho más mortífera que la primera.$B$B¡Que la Luz te acompañe, $n!', 0);
