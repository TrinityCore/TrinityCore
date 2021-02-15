-- 4122 Grark Lorkrub
-- https://es.classic.wowhead.com/quest=4122
SET @ID := 4122;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves el poder que obtenemos al unirnos a la legión de Roca Negra?', 0),
(@ID, 'esMX', '¿No ves el poder que obtenemos al unirnos a la legión de Roca Negra?', 0);
-- 4123 El corazón de la montaña
-- https://es.classic.wowhead.com/quest=4123
SET @ID := 4123;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el corazón de la montaña? Para mí, su valor es incalculable.', 0),
(@ID, 'esMX', '¿Tienes el corazón de la montaña? Para mí, su valor es incalculable.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes el corazón! ¡Asombroso! ¡Es aún más hermoso de lo que me imaginaba!$B$BAquí tienes, $n, como pago.', 0),
(@ID, 'esMX', '¡Tienes el corazón! ¡Asombroso! ¡Es aún más hermoso de lo que me imaginaba!$B$BAquí tienes, $n, como pago.', 0);
-- 4124 El mensajero desaparecido
-- https://es.classic.wowhead.com/quest=4124
SET @ID := 4124;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que te envía Latro. Creo que a estas alturas es una causa perdida, pero aceptaré cualquier ayuda que me puedas proporcionar. He de reconocer que me alegraré cuando este asunto esté resuelto. Cada día me adentro en Feralas buscando a Raschal y cada noche regreso con las manos vacías... bueno, en realidad, llenas de colmillos de gnolls y de decepción.', 0),
(@ID, 'esMX', 'Supongo que te envía Latro. Creo que a estas alturas es una causa perdida, pero aceptaré cualquier ayuda que me puedas proporcionar. He de reconocer que me alegraré cuando este asunto esté resuelto. Cada día me adentro en Feralas buscando a Raschal y cada noche regreso con las manos vacías... bueno, en realidad, llenas de colmillos de gnolls y de decepción.', 0);
-- 4125 El mensajero desaparecido
-- https://es.classic.wowhead.com/quest=4125
SET @ID := 4125;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has encontrado lo que parecen ser los restos de un bote de remos. A través del agua, ves unos enormes agujeros en el lado de babor. El bote está casi reducido a su simple estructura de madera. Lo que quiera que rompiera el bote, probablemente intentó partirlo en dos. En la parte de estribor hay un pequeño escudo del Bastión Plumaluna.$B$BEn el barro de la base del bote, hay un brillo metálico que te llama la atención...', 0),
(@ID, 'esMX', 'Has encontrado lo que parecen ser los restos de un bote de remos. A través del agua, ves unos enormes agujeros en el lado de babor. El bote está casi reducido a su simple estructura de madera. Lo que quiera que rompiera el bote, probablemente intentó partirlo en dos. En la parte de estribor hay un pequeño escudo del Bastión Plumaluna.$B$BEn el barro de la base del bote, hay un brillo metálico que te llama la atención...', 0);
-- 4126 Hurley Negrálito
-- https://es.classic.wowhead.com/quest=4126
SET @ID := 4126;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la receta, $n? ¡No soporto la idea de esos enanos Hierro Negro bebiendo la bebida de mi familia!', 0),
(@ID, 'esMX', '¿Tienes la receta, $n? ¡No soporto la idea de esos enanos Hierro Negro bebiendo la bebida de mi familia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La encontraste! ¡Muy bien! ¡Y espero que les dieras a esos Hierro Negro y a Hurley Negrálito una buena paliza!$B$BLos Cebatruenos están a tu servicio, $n. ¡Eres $gun héroe:una heroína; entre $ghéroes:heroínas;!', 0),
(@ID, 'esMX', '¡La encontraste! ¡Muy bien! ¡Y espero que les dieras a esos Hierro Negro y a Hurley Negrálito una buena paliza!$B$BLos Cebatruenos están a tu servicio, $n. ¡Eres $gun héroe:una heroína; entre $ghéroes:heroínas;!', 0);
-- 4127 Los restos del bote
-- https://es.classic.wowhead.com/quest=4127
SET @ID := 4127;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bienvenido de nuevo, $n. Espero que pudieras averiguar algo sobre la suerte que corrió Raschal, por trágica que fuera.', 0),
(@ID, 'esMX', 'Ah, bienvenido de nuevo, $n. Espero que pudieras averiguar algo sobre la suerte que corrió Raschal, por trágica que fuera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interesante... Creo que este es el cuchillo de Raschal. ¿Y dices que lo encontraste en el fondo del agua, junto a su bote? Bueno, aunque el hallazgo del cuchillo no sea suficiente para deducir lo peor, sí que nos abre una vía poco convencional para averiguar más.$B$B¿Has oído hablar de la psicometría?', 0),
(@ID, 'esMX', 'Interesante... Creo que este es el cuchillo de Raschal. ¿Y dices que lo encontraste en el fondo del agua, junto a su bote? Bueno, aunque el hallazgo del cuchillo no sea suficiente para deducir lo peor, sí que nos abre una vía poco convencional para averiguar más.$B$B¿Has oído hablar de la psicometría?', 0);
-- 4128 Ragnar Cebatruenos
-- https://es.classic.wowhead.com/quest=4128
SET @ID := 4128;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás en lo cierto, ¡estoy loco! ¡Loco de furia por el robo! ¡Me han robado una de las recetas de familia! ¡¿Cómo osan?! ¡Como si no me sobraran razones ya para odiar a los enanos Hierro Negro! Pero ahora, vaya... ¡ahora me van a oír!', 0),
(@ID, 'esMX', 'Estás en lo cierto, ¡estoy loco! ¡Loco de furia por el robo! ¡Me han robado una de las recetas de familia! ¡¿Cómo osan?! ¡Como si no me sobraran razones ya para odiar a los enanos Hierro Negro! Pero ahora, vaya... ¡ahora me van a oír!', 0);
-- 4129 La revelación del cuchillo
-- https://es.classic.wowhead.com/quest=4129
SET @ID := 4129;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te envía Ginro, ¿eh?$B$BLas lecturas psicométricas son extenuantes para la mente... agotan mis recursos... Pero bueno, mis pérdidas al mus Kalimdor también agotan mis recursos. Por aquí me llaman el "Rey de los faroles que no se encienden". Pero... desafortunado en el juego, afortunado en el dominio de los secretos de la naturaleza...$B$BEn fin, que sí, que te ayudaré. Podría ser decisivo para descubrir el destino de Raschal. Si me entregas el cuchillo, empezaremos.', 0),
(@ID, 'esMX', 'Te envía Ginro, ¿eh?$B$BLas lecturas psicométricas son extenuantes para la mente... agotan mis recursos... Pero bueno, mis pérdidas al mus Kalimdor también agotan mis recursos. Por aquí me llaman el "Rey de los faroles que no se encienden". Pero... desafortunado en el juego, afortunado en el dominio de los secretos de la naturaleza...$B$BEn fin, que sí, que te ayudaré. Podría ser decisivo para descubrir el destino de Raschal. Si me entregas el cuchillo, empezaremos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BLa psicometría no es un arte exacto, se mire como se mire, pero sí que la he utilizado en el pasado para intentar resolver situaciones que otros daban por perdidas. Creo que utilizándola en el cuchillo que encontraste, podríamos conseguir alguna pista de lo que le ha ocurrido a Raschal.$B$BSolo necesito un momento para aplicarla, pero no es lo que se definiría como una tarea agradable. Tenme un poco de paciencia.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BLa psicometría no es un arte exacto, se mire como se mire, pero sí que la he utilizado en el pasado para intentar resolver situaciones que otros daban por perdidas. Creo que utilizándola en el cuchillo que encontraste, podríamos conseguir alguna pista de lo que le ha ocurrido a Raschal.$B$BSolo necesito un momento para aplicarla, pero no es lo que se definiría como una tarea agradable. Tenme un poco de paciencia.', 0);
-- 4130 Lectura psicométrica
-- https://es.classic.wowhead.com/quest=4130
SET @ID := 4130;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por transmitirme las visiones de Quint, $n. Intentaré recordar que nos ha ayudado la próxima vez que juguemos a las cartas.$B$BRaschal se defiende bien en combate y los gnolls no son algo que le preocuparía en absoluto. Aún así, quizás tú y los tuyos consigáis cerrar este desesperante asunto utilizando esta nueva información.', 0),
(@ID, 'esMX', 'Gracias por transmitirme las visiones de Quint, $n. Intentaré recordar que nos ha ayudado la próxima vez que juguemos a las cartas.$B$BRaschal se defiende bien en combate y los gnolls no son algo que le preocuparía en absoluto. Aún así, quizás tú y los tuyos consigáis cerrar este desesperante asunto utilizando esta nueva información.', 0);
-- 4131 Los gnolls Zarpaleña
-- https://es.classic.wowhead.com/quest=4131
SET @ID := 4131;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En un árbol cercano hay dos grandes mochilas de piel. Ambas tienen la insignia del Bastión Plumaluna en la parte delantera...', 0),
(@ID, 'esMX', 'En un árbol cercano hay dos grandes mochilas de piel. Ambas tienen la insignia del Bastión Plumaluna en la parte delantera...', 0);
-- 4132 Operación: muerte a Forjainquina
-- https://es.classic.wowhead.com/quest=4132
SET @ID := 4132;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ha deshecho del Carnicero de Roca Negra?', 0),
(@ID, 'esMX', '¿Te ha deshecho del Carnicero de Roca Negra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! ¡El villano va a rendir cuentas ante la justicia! Eres sorprendente, $n. Lleva este medallón como símbolo de tu inquebrantable entrega a la Horda y a la F.E.K.', 0),
(@ID, 'esMX', '¡Por fin! ¡El villano va a rendir cuentas ante la justicia! Eres sorprendente, $n. Lleva este medallón como símbolo de tu inquebrantable entrega a la Horda y a la F.E.K.', 0);
-- 4133 Vivian Lagrave
-- https://es.classic.wowhead.com/quest=4133
SET @ID := 4133;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por venir, $n. Este lugar no está mal, aunque le faltan las amenidades del Apothecarium.$B$BBueno, ya hemos hablado bastante. ¿Vamos al grano, si?', 0),
(@ID, 'esMX', 'Gracias por venir, $n. Este lugar no está mal, aunque le faltan las amenidades del Apothecarium.$B$BBueno, ya hemos hablado bastante. ¿Vamos al grano, si?', 0);
-- 4134 La receta de Cebatruenos perdida
-- https://es.classic.wowhead.com/quest=4134
SET @ID := 4134;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la receta de la cerveza Cebatruenos, $n?', 0),
(@ID, 'esMX', '¿Tienes la receta de la cerveza Cebatruenos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Enviaré esta fórmula a El Apothecarium para que la estudien y con el tiempo llegaremos a desvelar su secreto. Algún día, los enanos de la Alianza podrían encontrarse con las virtudes de este brebaje ¡usadas contra ellos!$B$BMe parece de lo más divertido. Quizás la muerte tenga algún efecto sobre el sentido del humor... ¿no te parece?', 0),
(@ID, 'esMX', 'Muy bien. Enviaré esta fórmula a El Apothecarium para que la estudien y con el tiempo llegaremos a desvelar su secreto. Algún día, los enanos de la Alianza podrían encontrarse con las virtudes de este brebaje ¡usadas contra ellos!$B$BMe parece de lo más divertido. Quizás la muerte tenga algún efecto sobre el sentido del humor... ¿no te parece?', 0);
-- 4135 Las Galerías Retorcidas
-- https://es.classic.wowhead.com/quest=4135
SET @ID := 4135;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has encontrado una larga vaina de extraña naturaleza. La textura de la vaina es mucosa y está reforzada con unas protuberancias que salen de ella. La vaina, por su tamaño, podría contener fácilmente a un humanoide en su interior. De hecho, eso es precisamente lo que parece que contiene, pues a través de su piel puedes entrever una forma humana.', 0),
(@ID, 'esMX', 'Has encontrado una larga vaina de extraña naturaleza. La textura de la vaina es mucosa y está reforzada con unas protuberancias que salen de ella. La vaina, por su tamaño, podría contener fácilmente a un humanoide en su interior. De hecho, eso es precisamente lo que parece que contiene, pues a través de su piel puedes entrever una forma humana.', 0);
-- 4136 Ribbly Llavenrosca
-- https://es.classic.wowhead.com/quest=4136
SET @ID := 4136;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes a Ribbly? ¿O al menos a parte de él?', 0),
(@ID, 'esMX', '¿Tienes a Ribbly? ¿O al menos a parte de él?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! ¡Lo has encontrado! Y... al parecer, mi hermanito no se fue a la chita callando. Es una lástima. Me habría gustado ver su expresión cuando le comunicara nuestros planes de devolverlo a Revilgaz.$B$BGracias, $n. Le has dado un motivo de alegría a mi familia. Y Ribbly nunca pareció tan sereno como ahora.', 0),
(@ID, 'esMX', '¡Eso es! ¡Lo has encontrado! Y... al parecer, mi hermanito no se fue a la chita callando. Es una lástima. Me habría gustado ver su expresión cuando le comunicara nuestros planes de devolverlo a Revilgaz.$B$BGracias, $n. Le has dado un motivo de alegría a mi familia. Y Ribbly nunca pareció tan sereno como ahora.', 0);
-- 4145 Larion y Muigin
-- https://es.classic.wowhead.com/quest=4145
SET @ID := 4145;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muigin necesita disculparse primero antes de que vuelva a hablar con él!', 0),
(@ID, 'esMX', '¡Muigin necesita disculparse primero antes de que vuelva a hablar con él!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n, pero me temo que tengo malas noticias...', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n, pero me temo que tengo malas noticias...', 0);
-- 4146 Combustible de irradior
-- https://es.classic.wowhead.com/quest=4146
SET @ID := 4146;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es agotador, $n. ¡Esas cosas nunca me dejarán en paz!', 0),
(@ID, 'esMX', 'Esto es agotador, $n. ¡Esas cosas nunca me dejarán en paz!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, ¿así que Marvon no estaba? De todos modos, enséñame lo que conseguiste.', 0),
(@ID, 'esMX', 'Vaya, ¿así que Marvon no estaba? De todos modos, enséñame lo que conseguiste.', 0);
-- 4147 El taller de Marvon
-- https://es.classic.wowhead.com/quest=4147
SET @ID := 4147;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Marvon se marchó hace ya bastante tiempo, $n. Partió hacia Tanaris para estudiar las antiguas ruinas trol.$B$BDime, ¿qué dijiste que necesitabas?', 0),
(@ID, 'esMX', 'Marvon se marchó hace ya bastante tiempo, $n. Partió hacia Tanaris para estudiar las antiguas ruinas trol.$B$BDime, ¿qué dijiste que necesitabas?', 0);
-- 4148 Liquidador de Sangrepétalo
-- https://es.classic.wowhead.com/quest=4148
SET @ID := 4148;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para poder funcionar, el controlador necesita una muestra de la criatura elegida. Ve al cráter y recoge un brote Pétalo de Sangre. Cuando lo tenga podré calibrar el controlador para que funcione con los amiguitos de Muigin...$B$BSi no fuera tan cabezota ya podríamos estar de camino a casa... ¡Pero hasta entonces tendré que enseñarle que su broma no me molesta del todo!', 0),
(@ID, 'esMX', 'Para poder funcionar, el controlador necesita una muestra de la criatura elegida. Ve al cráter y recoge un brote Pétalo de Sangre. Cuando lo tenga podré calibrar el controlador para que funcione con los amiguitos de Muigin...$B$BSi no fuera tan cabezota ya podríamos estar de camino a casa... ¡Pero hasta entonces tendré que enseñarle que su broma no me molesta del todo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que va a funcionar sin problemas, $n. Y ahora, recuerda, si ves alguna de esas pestes, ¡no dudes en usar el controlador!', 0),
(@ID, 'esMX', 'Parece que va a funcionar sin problemas, $n. Y ahora, recuerda, si ves alguna de esas pestes, ¡no dudes en usar el controlador!', 0);
-- 4182 La amenaza de los dragonantes
-- https://es.classic.wowhead.com/quest=4182
SET @ID := 4182;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza del dragón?', 0),
(@ID, 'esMX', '¿Cómo va la caza del dragón?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Magnífica ejecución, $n. Ahora que sabemos que te manejas bien con los dragonantes, podemos hablar de asuntos más urgentes.', 0),
(@ID, 'esMX', 'Magnífica ejecución, $n. Ahora que sabemos que te manejas bien con los dragonantes, podemos hablar de asuntos más urgentes.', 0);
-- 4183 Los verdaderos maestros
-- https://es.classic.wowhead.com/quest=4183
SET @ID := 4183;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. ¿Nos conocemos? Me suenas algo, vagamente.', 0),
(@ID, 'esMX', 'Saludos, $n. ¿Nos conocemos? Me suenas algo, vagamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El magistrado Salomón abre la carta sellada de Helendis y empieza a leerla.>', 0),
(@ID, 'esMX', '<El magistrado Salomón abre la carta sellada de Helendis y empieza a leerla.>', 0);
-- 4184 Los verdaderos maestros
-- https://es.classic.wowhead.com/quest=4184
SET @ID := 4184;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae al Castillo de Ventormenta?', 0),
(@ID, 'esMX', '¿Qué te trae al Castillo de Ventormenta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dragones? ¡No es posible!', 0),
(@ID, 'esMX', '¿Dragones? ¡No es posible!', 0);
-- 4185 Los verdaderos maestros
-- https://es.classic.wowhead.com/quest=4185
SET @ID := 4185;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Bolvar te observa intensamente.>', 0),
(@ID, 'esMX', '<Bolvar te observa intensamente.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Bolvar coloca la barbilla sobre la mano sumido en profundos pensamientos.>$B$BSi bien respeto la posición de Lady Prestor, creo que hay una solución para este dilema que podría acabar con todas nuestras preocupaciones.', 0),
(@ID, 'esMX', '<Bolvar coloca la barbilla sobre la mano sumido en profundos pensamientos.>$B$BSi bien respeto la posición de Lady Prestor, creo que hay una solución para este dilema que podría acabar con todas nuestras preocupaciones.', 0);
-- 4186 Los verdaderos maestros
-- https://es.classic.wowhead.com/quest=4186
SET @ID := 4186;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna noticia de Bolvar?', 0),
(@ID, 'esMX', '¿Alguna noticia de Bolvar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que podría haber sido peor...$B$B<El magistrado Salomón te mira de arriba a abajo.>$B$BEs como si el destino de la Villa del Lago solo descansase sobre tus hombros.$B$B<Ves al magistrado Salomón parpadeando rápidamente. Parece estar llorando.>', 0),
(@ID, 'esMX', 'Supongo que podría haber sido peor...$B$B<El magistrado Salomón te mira de arriba a abajo.>$B$BEs como si el destino de la Villa del Lago solo descansase sobre tus hombros.$B$B<Ves al magistrado Salomón parpadeando rápidamente. Parece estar llorando.>', 0);
-- 4201 La poción de enamoramiento
-- https://es.classic.wowhead.com/quest=4201
SET @ID := 4201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes todos los ingredientes? ¡El vacío de mi corazón amenaza con consumirme!', 0),
(@ID, 'esMX', '¿Tienes todos los ingredientes? ¡El vacío de mi corazón amenaza con consumirme!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! Ahora puedo preparar mi poción y usarla sobre Sinroca. ¡Por fin caerá víctima de mis encantos!$B$BGracias, $n. ¡Eres $gun campeón:una campeona; del amor!', 0),
(@ID, 'esMX', '¡Lo has logrado! Ahora puedo preparar mi poción y usarla sobre Sinroca. ¡Por fin caerá víctima de mis encantos!$B$BGracias, $n. ¡Eres $gun campeón:una campeona; del amor!', 0);
-- Flor del viento corrupta
-- 4221, 4343, 4403, 4466
-- https://es.classic.wowhead.com/quest=4221
DELETE FROM `quest_request_items_locale` WHERE `id` IN(4221, 4343, 4403, 4466) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(4221, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4343, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4403, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4466, 'esES', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4221, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4343, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4403, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0),
(4466, 'esMX', 'Has encontrado una versión enfermiza y corrupta de lo que parece ser una planta de flor del viento. Las bayas que cuelgan de la planta parecen podridas y venenosas. Necesita desesperadamente algún tipo de atención para volver a la normalidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(4221, 4343, 4403, 4466) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(4221, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4343, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4403, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4466, 'esES', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4221, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4343, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4403, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0),
(4466, 'esMX', 'Aplicas dos Bálsamos de planta Cenarion a la flor del viento. Inmediatamente comienza a deshacerse de su forma corrupta, convirtiéndose en una planta vibrante y saludable.', 0);
-- 4223 Los verdaderos maestros
-- https://es.classic.wowhead.com/quest=4223
SET @ID := 4223;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El mariscal Maxwell se ríe.>', 0),
(@ID, 'esMX', '<El mariscal Maxwell se ríe.>', 0);
-- 4224 Los verdaderos maestros
-- https://es.classic.wowhead.com/quest=4224
SET @ID := 4224;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya hablaste con John?', 0),
(@ID, 'esMX', '¿Ya hablaste con John?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te podría haber avisado pero no habría sido divertido ¿verdad?', 0),
(@ID, 'esMX', 'Te podría haber avisado pero no habría sido divertido ¿verdad?', 0);
-- 4241 El mariscal Windsor
-- https://es.classic.wowhead.com/quest=4241
SET @ID := 4241;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está? ¡Lo mataré!', 0),
(@ID, 'esMX', '¿Dónde está? ¡Lo mataré!', 0);
-- 4242 Esperanza perdida
-- https://es.classic.wowhead.com/quest=4242
SET @ID := 4242;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por lo visto, ha perdido el juicio.$B$B<Oralius agacha la cabeza como en señal de duelo.>$B$BEs una desgracia que un otrora noble y orgulloso guerrero se haya convertido en semejante imbécil. SUPONGO que estamos en un callejón sin salida...$B$BDebo recompensarte por todo tu trabajo, $n.', 0),
(@ID, 'esMX', 'Por lo visto, ha perdido el juicio.$B$B<Oralius agacha la cabeza como en señal de duelo.>$B$BEs una desgracia que un otrora noble y orgulloso guerrero se haya convertido en semejante imbécil. SUPONGO que estamos en un callejón sin salida...$B$BDebo recompensarte por todo tu trabajo, $n.', 0);
-- 4261 El espíritu de un Ancestro
-- https://es.classic.wowhead.com/quest=4261
SET @ID := 4261;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, $n. Frondavil ha pasado muchas penurias. Gracias por lo que has hecho.$B$BUn día podremos arrebatar a Frondavil de las garras de la corrupción. Hasta entonces, cualquier buena acción es de gran ayuda.', 0),
(@ID, 'esMX', 'Sí, $n. Frondavil ha pasado muchas penurias. Gracias por lo que has hecho.$B$BUn día podremos arrebatar a Frondavil de las garras de la corrupción. Hasta entonces, cualquier buena acción es de gran ayuda.', 0);
-- 4262 Maestro supremo Pyron
-- https://es.classic.wowhead.com/quest=4262
SET @ID := 4262;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Jalinda parece estar mirando fijamente tu cabeza.>', 0),
(@ID, 'esMX', '<Jalinda parece estar mirando fijamente tu cabeza.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Incendius? ¡Dios mío!', 0),
(@ID, 'esMX', '¿Incendius? ¡Dios mío!', 0);
-- 4263 ¡Incendius!
-- https://es.classic.wowhead.com/quest=4263
SET @ID := 4263;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El demonio está muerto?', 0),
(@ID, 'esMX', '¿El demonio está muerto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Dios mío! ¿Estás $gseguro:segura; de que Incendius dijo "Ragnaros"?$B$B<Jalinda te tiende algo y te da una palmada en la muñeca y se queda pensativa.>”', 0),
(@ID, 'esMX', '¡Dios mío! ¿Estás $gseguro:segura; de que Incendius dijo "Ragnaros"?$B$B<Jalinda te tiende algo y te da una palmada en la muñeca y se queda pensativa.>”', 0);
-- 4264 Una nota arrugada
-- https://es.classic.wowhead.com/quest=4264
SET @ID := 4264;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El mariscal Windsor mira la nota que traes en la mano.>$B$B¿Qué traes ahí, $n?', 0),
(@ID, 'esMX', '<El mariscal Windsor mira la nota que traes en la mano.>$B$B¿Qué traes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El mariscal Windsor mira la nota y empieza a leerla.>', 0),
(@ID, 'esMX', '<El mariscal Windsor mira la nota y empieza a leerla.>', 0);
