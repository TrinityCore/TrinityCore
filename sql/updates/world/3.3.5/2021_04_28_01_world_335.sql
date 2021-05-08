-- Una compensación justa
-- 8927, 8938, 8939, 8940, 8941, 8942, 8943, 8944, 10495
-- https://es.wowhead.com/quest=8927
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8927, 8938, 8939, 8940, 8941, 8942, 8943, 8944, 10495) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8927, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8938, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8939, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8940, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8941, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8942, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8943, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8944, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(10495, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8927, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8938, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8939, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8940, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8941, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8942, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8943, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8944, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(10495, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8927, 8938, 8939, 8940, 8941, 8942, 8943, 8944, 10495) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8927, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8938, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8939, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8940, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8941, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8942, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8943, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8944, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(10495, 'esES', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8927, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8938, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8939, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8940, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8941, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8942, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8943, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(8944, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0),
(10495, 'esMX', 'Nuestro acuerdo sigue vigente. Solo recuerda, esto es solo una muestra de lo que te espera. Líbrame de este destino maldito y te recompensaré con objetos de un poder verdaderamente grandioso.', 0);
-- 8928 Un mercader sospechoso
-- https://es.classic.wowhead.com/quest=8928
SET @ID := 8928;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte encontrando al diablillo en Garganta Negro Rumor?', 0),
(@ID, 'esMX', '¿Has tenido suerte encontrando al diablillo en Garganta Negro Rumor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo hiciste! Esta vara funcionará perfectamente. Ahora a ponerlo todo junto...', 0),
(@ID, 'esMX', '¡Lo hiciste! Esta vara funcionará perfectamente. Ahora a ponerlo todo junto...', 0);
-- 8929 Buscando a Anthion
-- https://es.classic.wowhead.com/quest=8929
SET @ID := 8929;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Deliana te ha puesto en contacto conmigo? Haré todo lo posible para ayudarte, pero primero debo pedirte un gran favor.', 0),
(@ID, 'esMX', '¿Deliana te ha puesto en contacto conmigo? Haré todo lo posible para ayudarte, pero primero debo pedirte un gran favor.', 0);
-- 8930 Buscando a Anthion
-- https://es.classic.wowhead.com/quest=8930
SET @ID := 8930;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mokvar te ha puesto en contacto conmigo? Haré todo lo posible para ayudarte, pero primero debo pedirte un gran favor.', 0),
(@ID, 'esMX', '¿Mokvar te ha puesto en contacto conmigo? Haré todo lo posible para ayudarte, pero primero debo pedirte un gran favor.', 0);
-- 8945 La súplica de un muerto
-- https://es.classic.wowhead.com/quest=8945
SET @ID := 8945;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ysida liberada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, ¿está viva Ysida?', 0),
(@ID, 'esMX', 'Dime, ¿está viva Ysida?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por rescatarme... temía por mi vida. Acepta esto como una pequeña muestra de mi gratitud.$B$BAnthion está... no... no puede ser...', 0),
(@ID, 'esMX', 'Gracias por rescatarme... temía por mi vida. Acepta esto como una pequeña muestra de mi gratitud.$B$BAnthion está... no... no puede ser...', 0);
-- 8946 Prueba de vida
-- https://es.classic.wowhead.com/quest=8946
SET @ID := 8946;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ysida... ¿está viva?', 0),
(@ID, 'esMX', 'Ysida... ¿está viva?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ese guardapelo... ¡la encontraste! Puedo descansar en paz por fin.$B$BAhora responderé cualquier pregunta que puedas tener, $n. Pero date prisa, mi tiempo en este mundo se termina.', 0),
(@ID, 'esMX', 'Ese guardapelo... ¡la encontraste! Puedo descansar en paz por fin.$B$BAhora responderé cualquier pregunta que puedas tener, $n. Pero date prisa, mi tiempo en este mundo se termina.', 0);
-- 8947 La extraña petición de Anthion
-- https://es.classic.wowhead.com/quest=8947
SET @ID := 8947;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Obtuviste los materiales que te pedí, $n?', 0),
(@ID, 'esMX', '¿Obtuviste los materiales que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Los transmutaré en algo más adecuado a nuestras necesidades.', 0),
(@ID, 'esMX', 'Excelente. Los transmutaré en algo más adecuado a nuestras necesidades.', 0);
-- 8948 Un viejo amigo de Anthion
-- https://es.classic.wowhead.com/quest=8948
SET @ID := 8948;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Habla $gextraño:extraña;, ¿no ves que estoy ocupado?', 0),
(@ID, 'esMX', 'Habla $gextraño:extraña;, ¿no ves que estoy ocupado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que Anthion te envió? Pensé que estaba muerto. Supongo que he escuchado cosas más extrañas en mi vida.$B$BMuy bien entonces. ¿Qué quieres que haga con este estandarte?', 0),
(@ID, 'esMX', '¿Dices que Anthion te envió? Pensé que estaba muerto. Supongo que he escuchado cosas más extrañas en mi vida.$B$BMuy bien entonces. ¿Qué quieres que haga con este estandarte?', 0);
-- 8949 La vendetta de Falrin
-- https://es.classic.wowhead.com/quest=8949
SET @ID := 8949;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho el favor que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has hecho el favor que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hmmm... por extraño que parezca, no me siento mejor por la muerte de mi hermano a manos de esos brutos.$B$BBueno, cumpliste tu parte del trato. Veamos qué puedo hacer por ti.', 0),
(@ID, 'esMX', 'Hmmm... por extraño que parezca, no me siento mejor por la muerte de mi hermano a manos de esos brutos.$B$BBueno, cumpliste tu parte del trato. Veamos qué puedo hacer por ti.', 0);
-- 8950 El encantamiento del provocador
-- https://es.classic.wowhead.com/quest=8950
SET @ID := 8950;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha reunido los materiales que necesito, $n?', 0),
(@ID, 'esMX', '¿Ha reunido los materiales que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, estos funcionarán bien. Cuando termine, ninguna fuerza en el mundo podrá impedir que tu víctima acepte tu desafío.', 0),
(@ID, 'esMX', 'Sí, estos funcionarán bien. Cuando termine, ninguna fuerza en el mundo podrá impedir que tu víctima acepte tu desafío.', 0);
-- La despedida de Anthion
-- 8951, 8952, 8953, 8954, 8955, 8956, 8958, 8959, 10496
-- https://es.wowhead.com/quest=8951
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8951, 8952, 8953, 8954, 8955, 8956, 8958, 8959, 10496) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8951, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8952, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8953, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8954, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8955, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8956, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8958, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8959, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(10496, 'esES', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8951, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8952, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8953, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8954, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8955, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8956, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8958, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(8959, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0),
(10496, 'esMX', 'Has vuelto, $n. Debes contarme todo lo que has descubierto. Pero primero permítenos arreglar tu recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8951, 8952, 8953, 8954, 8955, 8956, 8958, 8959, 10496) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8951, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8952, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8953, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8954, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8955, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8956, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8958, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8959, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(10496, 'esES', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8951, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8952, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8953, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8954, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8955, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8956, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8958, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(8959, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0),
(10496, 'esMX', '¡No puedo creer que nuestras vidas estén casi perdidas por culpa de un estúpido medallón! ¿Y estás $gseguro:segura; de que Anthion mencionó a Bodley?$B$BBueno, has hecho tu trabajo, así que saquemos tu recompensa.', 0);
-- La despedida de Anthion
-- 8957, 9016, 9017, 9018, 9019, 9020, 9021, 9022, 10497
-- https://es.wowhead.com/quest=8957
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8957, 9016, 9017, 9018, 9019, 9020, 9021, 9022, 10497) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8957, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9016, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9017, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9018, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9019, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9020, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9021, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9022, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(10497, 'esES', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(8957, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9016, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9017, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9018, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9019, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9020, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9021, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(9022, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0),
(10497, 'esMX', 'Has vuelto y veo en tus ojos que tienes mucho que contarme, $n. Primero, permítenos ocuparnos de tu recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8957, 9016, 9017, 9018, 9019, 9020, 9021, 9022, 10497) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8957, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9016, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9017, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9018, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9019, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9020, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9021, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9022, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(10497, 'esES', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(8957, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9016, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9017, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9018, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9019, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9020, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9021, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(9022, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0),
(10497, 'esMX', 'Esta maldición nos fue otorgada por un simple medallón. Lord Valthalak ciertamente sabe cómo guardar rencor.$B$BNos esforzaremos por encontrar las piezas restantes, con suerte antes de que me encuentre con una muerte prematura. Pero antes de eso, veamos cuál es tu recompensa.', 0);
-- El triste destino de Bodley
-- 8960, 9032
-- https://es.wowhead.com/quest=8960
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8960, 9032) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8960, 'esES', 'Estoy tan contento de que puedas verme. ¡Finalmente alguien con quien hablar!$B$B¿Nos ayudarás, $n? ¿Ayudarás a reparar el mal que perpetramos y arreglarás las cosas? Si es cierto que ya tienes la Pieza Superior del Amuleto de Lord Valthalak, entonces creo que puedo ponerte en la dirección correcta para conseguir las otras dos partes, reunirlas y acabar con todo esto.$B$BAh, por cierto, hola, mi nombre es Bodley. ¡Un placer conocerte!', 0),
(9032, 'esES', 'Estoy tan contento de que puedas verme. ¡Finalmente alguien con quien hablar!$B$B¿Nos ayudarás, $n? ¿Ayudarás a reparar el mal que perpetramos y arreglarás las cosas? Si es cierto que ya tienes la Pieza Superior del Amuleto de Lord Valthalak, entonces creo que puedo ponerte en la dirección correcta para conseguir las otras dos partes, reunirlas y acabar con todo esto.$B$BAh, por cierto, hola, mi nombre es Bodley. ¡Un placer conocerte!', 0),
(8960, 'esMX', 'Estoy tan contento de que puedas verme. ¡Finalmente alguien con quien hablar!$B$B¿Nos ayudarás, $n? ¿Ayudarás a reparar el mal que perpetramos y arreglarás las cosas? Si es cierto que ya tienes la Pieza Superior del Amuleto de Lord Valthalak, entonces creo que puedo ponerte en la dirección correcta para conseguir las otras dos partes, reunirlas y acabar con todo esto.$B$BAh, por cierto, hola, mi nombre es Bodley. ¡Un placer conocerte!', 0),
(9032, 'esMX', 'Estoy tan contento de que puedas verme. ¡Finalmente alguien con quien hablar!$B$B¿Nos ayudarás, $n? ¿Ayudarás a reparar el mal que perpetramos y arreglarás las cosas? Si es cierto que ya tienes la Pieza Superior del Amuleto de Lord Valthalak, entonces creo que puedo ponerte en la dirección correcta para conseguir las otras dos partes, reunirlas y acabar con todo esto.$B$BAh, por cierto, hola, mi nombre es Bodley. ¡Un placer conocerte!', 0);
-- 8961 Tres reyes de Fuego
-- https://es.wowhead.com/quest=8961
SET @ID := 8961;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fue nuestra locura... nuestra perdición que aceptáramos ese último trabajo. Si tan solo no hubiéramos robado inadvertidamente el espíritu de Lord Valthalak, que estaba contenido en el amuleto; si tan solo no hubieramos dividido el amuleto como codiciosos mercenarios. Hoy estaría vivo, tal vez bebiendo una cerveza o lanzando a uno de mis hijos al aire.$B$B$n, no permitas que la avaricia de los innobles de nuestra antigua compañía de mercenarios también sea tu perdición.', 0),
(@ID, 'esMX', 'Fue nuestra locura... nuestra perdición que aceptáramos ese último trabajo. Si tan solo no hubiéramos robado inadvertidamente el espíritu de Lord Valthalak, que estaba contenido en el amuleto; si tan solo no hubieramos dividido el amuleto como codiciosos mercenarios. Hoy estaría vivo, tal vez bebiendo una cerveza o lanzando a uno de mis hijos al aire.$B$B$n, no permitas que la avaricia de los innobles de nuestra antigua compañía de mercenarios también sea tu perdición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy impresionado, $n, pero no hay tiempo que perder. Te daré tu próxima tarea, porque todavía necesitarás adquirir algunos componentes importantes antes de que podamos continuar.$B$BHáblame de nuevo cuando sientas que estás $glisto:lista; para el desafío que te espera.', 0),
(@ID, 'esMX', 'Estoy impresionado, $n, pero no hay tiempo que perder. Te daré tu próxima tarea, porque todavía necesitarás adquirir algunos componentes importantes antes de que podamos continuar.$B$BHáblame de nuevo cuando sientas que estás $glisto:lista; para el desafío que te espera.', 0);
-- 8962 Componentes importantes
-- https://es.classic.wowhead.com/quest=8962
SET @ID := 8962;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de los restos en el blandón.$B$BAhora todo lo que queda es ir a la parte inferior de la Cumbre Roca Negra, a la cámara donde reside el Maestro de Guerra Voone en Tazz\'Alaor, y usar el blandón para convocar al espíritu corrupto de mi antiguo cohorte, Mor Grayhoof. No puede descansar hasta que le quiten la pieza del amuleto.', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de los restos en el blandón.$B$BAhora todo lo que queda es ir a la parte inferior de la Cumbre Roca Negra, a la cámara donde reside el Maestro de Guerra Voone en Tazz\'Alaor, y usar el blandón para convocar al espíritu corrupto de mi antiguo cohorte, Mor Grayhoof. No puede descansar hasta que le quiten la pieza del amuleto.', 0);
-- 8963 Componentes importantes
-- https://es.classic.wowhead.com/quest=8963
SET @ID := 8963;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la reliquia en el blandón.$B$BAhora todo lo que queda es ir al Santuario de Eldretharr en el ala este de Dire Maul, y usar el blandón para convocar el espíritu de mi antigua cohorte, Isalien. Su espíritu ha sido corrompido por la posesión de la pieza del amuleto de Valthalak y la porción de su alma dentro del mismo.', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la reliquia en el blandón.$B$BAhora todo lo que queda es ir al Santuario de Eldretharr en el ala este de Dire Maul, y usar el blandón para convocar el espíritu de mi antigua cohorte, Isalien. Su espíritu ha sido corrompido por la posesión de la pieza del amuleto de Valthalak y la porción de su alma dentro del mismo.', 0);
-- 8964 Componentes importantes
-- https://es.classic.wowhead.com/quest=8964
SET @ID := 8964;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la espada en el blandón.$B$BAhora todo lo que queda es entrar en El Trono Carmesí dentro del Bastión Escarlata en Stratholme, y usar el blandón para convocar los restos de mis antiguos cohortes, Jarien y Sothos. Sus almas se han torcido aún más por la posesión de la pieza de amuleto de Valthalak y su espíritu dentro.', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de la espada en el blandón.$B$BAhora todo lo que queda es entrar en El Trono Carmesí dentro del Bastión Escarlata en Stratholme, y usar el blandón para convocar los restos de mis antiguos cohortes, Jarien y Sothos. Sus almas se han torcido aún más por la posesión de la pieza de amuleto de Valthalak y su espíritu dentro.', 0);
-- 8965 Componentes importantes
-- https://es.classic.wowhead.com/quest=8965
SET @ID := 8965;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0),
(@ID, 'esMX', '$c, ¿Has regresado ya con lo que te envié a recoger?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Imbuiré la esencia de las cenizas en el blandón.$B$BAhora todo lo que queda es entrar en Scholomance, en la cámara de Ras Susurro Gélido, y usar el blandón para invocar el espíritu de mi antiguo cohorte, Kormok. La pieza del amuleto y el espíritu de Valthalak en su interior lo han corrompido aún más, y no descansará hasta que se lo quites por la fuerza.', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Imbuiré la esencia de las cenizas en el blandón.$B$BAhora todo lo que queda es entrar en Scholomance, en la cámara de Ras Susurro Gélido, y usar el blandón para invocar el espíritu de mi antiguo cohorte, Kormok. La pieza del amuleto y el espíritu de Valthalak en su interior lo han corrompido aún más, y no descansará hasta que se lo quites por la fuerza.', 0);
-- 8966 La parte izquierda del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8966
SET @ID := 8966;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces está hecho? ¿Has recuperado la pieza izquierda del amuleto de Lord Valthalak y finalmente has dejado descansar el espíritu de mi antiguo compañero, Mor Pezuña Gris?', 0),
(@ID, 'esMX', '¿Entonces está hecho? ¿Has recuperado la pieza izquierda del amuleto de Lord Valthalak y finalmente has dejado descansar el espíritu de mi antiguo compañero, Mor Pezuña Gris?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho algo grande, $n. Un espíritu descansa en paz, pero aún queda mucho trabajo por hacer antes de que podamos dejar todo esto atrás.$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0),
(@ID, 'esMX', 'Has hecho algo grande, $n. Un espíritu descansa en paz, pero aún queda mucho trabajo por hacer antes de que podamos dejar todo esto atrás.$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0);
-- 8967 La parte izquierda del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8967
SET @ID := 8967;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Seguramente aún no te has ocupado de la salvación del espíritu de Isalien y la recuperación de la pieza izquierda del amuleto de Lord Valthalak, $n.', 0),
(@ID, 'esMX', 'Seguramente aún no te has ocupado de la salvación del espíritu de Isalien y la recuperación de la pieza izquierda del amuleto de Lord Valthalak, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n, por hacer descansar el espíritu de Isalien. Ahora, tal vez, encontrará la paz con su diosa. Pero aún queda mucho trabajo por delante si queremos salir de este delicado aprieto en el que nos encontramos.$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0),
(@ID, 'esMX', 'Gracias, $n, por hacer descansar el espíritu de Isalien. Ahora, tal vez, encontrará la paz con su diosa. Pero aún queda mucho trabajo por delante si queremos salir de este delicado aprieto en el que nos encontramos.$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0);
-- 8968 La parte izquierda del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8968
SET @ID := 8968;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿Esto significa que ya dejaste descansar las almas de esos dos tontos y recuperaste la pieza izquierda del amuleto de Lord Valthalak?', 0),
(@ID, 'esMX', '$n, ¿Esto significa que ya dejaste descansar las almas de esos dos tontos y recuperaste la pieza izquierda del amuleto de Lord Valthalak?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que es lo mejor que las almas de esos dos finalmente hayan descansado, incluso si no me agradaron mientras estaban vivos. En cualquier caso, tenemos lo que buscábamos, ¡y eso definitivamente es algo bueno!$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0),
(@ID, 'esMX', 'Supongo que es lo mejor que las almas de esos dos finalmente hayan descansado, incluso si no me agradaron mientras estaban vivos. En cualquier caso, tenemos lo que buscábamos, ¡y eso definitivamente es algo bueno!$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0);
-- 8969 La parte izquierda del amuleto de Lord Valthalak
-- https://es.classic.wowhead.com/quest=8969
SET @ID := 8969;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te felicito, $n, si has regresado con la pieza izquierda del amuleto. Sin embargo, si no es así, ocúpate de eso, ya que no hay tiempo que perder, ¡te lo aseguro!', 0),
(@ID, 'esMX', 'Te felicito, $n, si has regresado con la pieza izquierda del amuleto. Sin embargo, si no es así, ocúpate de eso, ya que no hay tiempo que perder, ¡te lo aseguro!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Kormok no fue tan malo para un ogro, al menos no mientras aún estaba vivo, así que espero que obtenga el descanso que se merece. Pero tenemos más trabajo por delante.$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Kormok no fue tan malo para un ogro, al menos no mientras aún estaba vivo, así que espero que obtenga el descanso que se merece. Pero tenemos más trabajo por delante.$B$BDesafortunadamente, no sé la ubicación del que murió con la pieza derecha del amuleto en su poder. Pero no temas; En vida fui un aficionado al arte de la adivinación, así que tengo otra tarea para ti, que nos permitirá descubrir la pieza final.', 0);
-- 8970 En tu destino veo la Isla de Alcaz...
-- https://es.classic.wowhead.com/quest=8970
SET @ID := 8970;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alga de sangre, $n, un montón, eso es lo que necesito para potenciar mis hechizos adivinatorios. Es probable que tengas que llevar al menos a un par de amigos contigo a la Isla de Alcaz para recogerlo... ¡esos Strashaz son un grupo desagradable!', 0),
(@ID, 'esMX', 'Alga de sangre, $n, un montón, eso es lo que necesito para potenciar mis hechizos adivinatorios. Es probable que tengas que llevar al menos a un par de amigos contigo a la Isla de Alcaz para recogerlo... ¡esos Strashaz son un grupo desagradable!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para ser honesto, $n, me sorprende que hayas regresado de una pieza. Por otra parte, supongo que la Isla de Alcaz es la menor de tus preocupaciones en este momento.$B$BOk, dame un momento... la adivinación no es algo de lo que puedas chasquear los dedos y esperar respuestas precisas.', 0),
(@ID, 'esMX', 'Para ser honesto, $n, me sorprende que hayas regresado de una pieza. Por otra parte, supongo que la Isla de Alcaz es la menor de tus preocupaciones en este momento.$B$BOk, dame un momento... la adivinación no es algo de lo que puedas chasquear los dedos y esperar respuestas precisas.', 0);
-- 8977 Regresa junto a Deliana
-- https://es.classic.wowhead.com/quest=8977
SET @ID := 8977;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto?', 0),
(@ID, 'esMX', '¿Has vuelto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Lo has hecho bien, $n. No estoy segura de confiar en la destreza del goblin, pero no me queda otra opción.', 0),
(@ID, 'esMX', '¡Excelente! Lo has hecho bien, $n. No estoy segura de confiar en la destreza del goblin, pero no me queda otra opción.', 0);
