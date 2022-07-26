-- 9059 Las manoplas de acechacriptas
-- https://es.classic.wowhead.com/quest=9059
SET @ID := 9059;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Manoplas de acechacriptas.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Manoplas de acechacriptas.', 0);
-- 9060 La faja de acechacriptas
-- https://es.classic.wowhead.com/quest=9060
SET @ID := 9060;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Faja de acechacriptas.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Faja de acechacriptas.', 0);
-- 9061 Los guardamuñecas de acechacriptas
-- https://es.classic.wowhead.com/quest=9061
SET @ID := 9061;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unos Guardamuñecas de acechacriptas.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unos Guardamuñecas de acechacriptas.', 0);
-- 9063 Torwa Abrecaminos
-- https://es.classic.wowhead.com/quest=9063
SET @ID := 9063;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un largo camino para venir a verme, $c, y has llegado justo a tiempo.', 0),
(@ID, 'esMX', 'Has hecho un largo camino para venir a verme, $c, y has llegado justo a tiempo.', 0);
-- 9068 La guerrera Rompeterra
-- https://es.classic.wowhead.com/quest=9068
SET @ID := 9068;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Guerrera Rompeterra.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Guerrera Rompeterra.', 0);
-- 9069 Las musleras Rompeterra
-- https://es.classic.wowhead.com/quest=9069
SET @ID := 9069;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Musleras Rompeterra.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Musleras Rompeterra.', 0);
-- 9070 La celada Rompeterra
-- https://es.classic.wowhead.com/quest=9070
SET @ID := 9070;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Celada Rompeterra.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Celada Rompeterra.', 0);
-- 9071 Las bufas Rompeterra
-- https://es.classic.wowhead.com/quest=9071
SET @ID := 9071;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Bufas Rompeterra.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Bufas Rompeterra.', 0);
-- 9072 Las botas Rompeterra
-- https://es.classic.wowhead.com/quest=9072
SET @ID := 9072;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Botas Rompeterra.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer unas Botas Rompeterra.', 0);
-- 9073 Las manoplas Rompeterra
-- https://es.classic.wowhead.com/quest=9073
SET @ID := 9073;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído lo que necesito?', 0),
(@ID, 'esMX', '¿Me has traído lo que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estas manoplas canalizan el poder de los elementos!', 0),
(@ID, 'esMX', '¡Estas manoplas canalizan el poder de los elementos!', 0);
-- 9074 La faja Rompeterra
-- https://es.classic.wowhead.com/quest=9074
SET @ID := 9074;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Faja Rompeterra.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Faja Rompeterra.', 0);
-- 9075 Los guardamuñecas Rompeterra
-- https://es.classic.wowhead.com/quest=9075
SET @ID := 9075;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído lo que necesito?', 0),
(@ID, 'esMX', '¿Me has traído lo que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los guardamuñecas están listos, $n.$B$B<Rimblat hace una reverencia.>', 0),
(@ID, 'esMX', 'Los guardamuñecas están listos, $n.$B$B<Rimblat hace una reverencia.>', 0);
-- 9076 El jefe de los desdichados
-- https://es.wowhead.com/quest=9076
SET @ID := 9076;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes la cabeza? No tengo tiempo que perder, $n.', 0),
(@ID, 'esMX', '¿Me traes la cabeza? No tengo tiempo que perder, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo derrotaste! Claro que mis hombres lo habían ablandado un poco antes.$B$BEs broma, $c. Lo hiciste muy bien. No te metas en líos y te harás de una buena reputación.', 0),
(@ID, 'esMX', '¡Lo derrotaste! Claro que mis hombres lo habían ablandado un poco antes.$B$BEs broma, $c. Lo hiciste muy bien. No te metas en líos y te harás de una buena reputación.', 0);
-- 9077 La coraza Segahuesos
-- https://es.classic.wowhead.com/quest=9077
SET @ID := 9077;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Coraza Segahuesos.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer una Coraza Segahuesos.', 0);
-- 9078 Los quijotes Segahuesos
-- https://es.classic.wowhead.com/quest=9078
SET @ID := 9078;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Rohan se ríe.>$B$BMe acabo de dar cuenta de la ironía de todo esto.', 0),
(@ID, 'esMX', '<Rohan se ríe.>$B$BMe acabo de dar cuenta de la ironía de todo esto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado al caminar con esas cosas. Puedes cortarte.', 0),
(@ID, 'esMX', 'Ten cuidado al caminar con esas cosas. Puedes cortarte.', 0);
-- 9079 El casco Segahuesos
-- https://es.classic.wowhead.com/quest=9079
SET @ID := 9079;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer un Casco Segahuesos.', 0),
(@ID, 'esMX', '¡Excelente $n! tienes todo lo que te pedí y ahora puedo hacer un Casco Segahuesos.', 0);
-- 9080 Los espaldares Segahuesos
-- https://es.classic.wowhead.com/quest=9080
SET @ID := 9080;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Rohan te mira con recelo.>$B$B¿Has estado en Mano de Tyr últimamente?', 0),
(@ID, 'esMX', '<Rohan te mira con recelo.>$B$B¿Has estado en Mano de Tyr últimamente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Rohan se seca el sudor de la frente>.$B$B¡Estos hombros requirieron algo de trabajo! No salgas y te maten como a un matorral, $n.', 0),
(@ID, 'esMX', '<Rohan se seca el sudor de la frente>.$B$B¡Estos hombros requirieron algo de trabajo! No salgas y te maten como a un matorral, $n.', 0);
-- 9081 Los escarpes Segahuesos
-- https://es.classic.wowhead.com/quest=9081
SET @ID := 9081;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo tráeme los materiales y deja de perder mi tiempo, $n.', 0),
(@ID, 'esMX', 'Solo tráeme los materiales y deja de perder mi tiempo, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se ponen el los pies. Dime, no has vuelto a husmear en la Mano de Tyr, ¿verdad?', 0),
(@ID, 'esMX', 'Se ponen el los pies. Dime, no has vuelto a husmear en la Mano de Tyr, ¿verdad?', 0);
-- 9082 Los guanteletes Segahuesos
-- https://es.classic.wowhead.com/quest=9082
SET @ID := 9082;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo esperas que haga algo sin los elementos que te pedí?', 0),
(@ID, 'esMX', '¿Cómo esperas que haga algo sin los elementos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos guanteletes podrían usarlos como armas si fuera necesario. ¡Úsalos con orgullo!', 0),
(@ID, 'esMX', 'Estos guanteletes podrían usarlos como armas si fuera necesario. ¡Úsalos con orgullo!', 0);
-- 9083 Los guardarrenes Segahuesos
-- https://es.classic.wowhead.com/quest=9083
SET @ID := 9083;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo esperas que haga algo sin los elementos que te pedí?', 0),
(@ID, 'esMX', '¿Cómo esperas que haga algo sin los elementos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cinturón está listo, $n. ¿Alguna vez has visto un artículo de tan alta calidad vendido por tan poco?', 0),
(@ID, 'esMX', 'El cinturón está listo, $n. ¿Alguna vez has visto un artículo de tan alta calidad vendido por tan poco?', 0);
-- 9084 Los brazales Segahuesos
-- https://es.classic.wowhead.com/quest=9084
SET @ID := 9084;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo esperas que haga algo sin los elementos que te pedí?', 0),
(@ID, 'esMX', '¿Cómo esperas que haga algo sin los elementos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los brazaletes están listos, $n.$B$B<Rohan hace una reverencia.>', 0),
(@ID, 'esMX', 'Los brazaletes están listos, $n.$B$B<Rohan hace una reverencia.>', 0);
-- 9085 Sombras del Apocalipsis
-- https://es.classic.wowhead.com/quest=9085
SET @ID := 9085;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte, $n?', 0),
(@ID, 'esMX', '¿Has tenido suerte, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Con las sombras destruidas, nuestra esperanza de victoria contra el Rey Exánime sobrevive.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Con las sombras destruidas, nuestra esperanza de victoria contra el Rey Exánime sobrevive.', 0);
-- 9086 La guerrera Caminasueños
-- https://es.classic.wowhead.com/quest=9086
SET @ID := 9086;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu Guerrera Caminasueños está lista, $n.', 0),
(@ID, 'esMX', 'Tu Guerrera Caminasueños está lista, $n.', 0);
-- 9087 Las musleras Caminasueños
-- https://es.classic.wowhead.com/quest=9087
SET @ID := 9087;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como prometí, Musleras Caminasueños.$B$B<Rayne te entrega la armadura.>', 0),
(@ID, 'esMX', 'Como prometí, Musleras Caminasueños.$B$B<Rayne te entrega la armadura.>', 0);
-- 9088 La celada Caminasueños
-- https://es.classic.wowhead.com/quest=9088
SET @ID := 9088;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu Celada Caminasueños está lista, $n.', 0),
(@ID, 'esMX', 'Tu Celada Caminasueños está lista, $n.', 0);
-- 9089 Las bufas Caminasueños
-- https://es.classic.wowhead.com/quest=9089
SET @ID := 9089;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus Bufas Caminasueños están listas, $n.', 0),
(@ID, 'esMX', 'Tus Bufas Caminasueños están listas, $n.', 0);
-- 9090 Las botas Caminasueños
-- https://es.classic.wowhead.com/quest=9090
SET @ID := 9090;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus Botas Caminasueños están listas, $n.', 0),
(@ID, 'esMX', 'Tus Botas Caminasueños están listas, $n.', 0);
-- 9091 Las manoplas Caminasueños
-- https://es.classic.wowhead.com/quest=9091
SET @ID := 9091;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus Manoplas Caminasueños están listas, $n.', 0),
(@ID, 'esMX', 'Tus Manoplas Caminasueños están listas, $n.', 0);
-- 9092 La faja Caminasueños
-- https://es.classic.wowhead.com/quest=9092
SET @ID := 9092;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu Faja Caminasueños está lista, $n.', 0),
(@ID, 'esMX', 'Tu Faja Caminasueños está lista, $n.', 0);
-- 9093 Los guardamuñecas Caminasueños
-- https://es.classic.wowhead.com/quest=9093
SET @ID := 9093;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El costo del material es alto, pero pronto lo olvidarás.', 0),
(@ID, 'esMX', 'El costo del material es alto, pero pronto lo olvidarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus Guardamuñecas Caminasueños están listos, $n.', 0),
(@ID, 'esMX', 'Tus Guardamuñecas Caminasueños están listos, $n.', 0);
-- 9095 La toga de Fuego de Escarcha
-- https://es.classic.wowhead.com/quest=9095
SET @ID := 9095;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer una Toga de Fuego de Escarcha.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer una Toga de Fuego de Escarcha.', 0);
-- 9096 Los leotardos de Fuego de Escarcha
-- https://es.classic.wowhead.com/quest=9096
SET @ID := 9096;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos Leotardos de Fuego de Escarcha.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer unos Leotardos de Fuego de Escarcha.', 0);
-- 9097 El aro de Fuego de Escarcha
-- https://es.classic.wowhead.com/quest=9097
SET @ID := 9097;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0),
(@ID, 'esMX', 'Te faltan algunas piezas para la misión, ¡por favor ve y consíguelas todas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer un Aro de Fuego de Escarcha.', 0),
(@ID, 'esMX', '¡Excelente $n! obtuviste todo tal como te pedí y ahora puedo hacer un Aro de Fuego de Escarcha.', 0);
