-- 8074 Dechados de Poder: el Cinturón de augur
-- https://es.classic.wowhead.com/quest=8074
SET @ID := 8074;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Dechados de Poder son lo que necesito, colega: sacaremos el poder de ellos en nuestra lucha contra el mal de Zul\'Gurub. ¿Los tienes para mí?', 0),
(@ID, 'esMX', 'Los Dechados de Poder son lo que necesito, colega: sacaremos el poder de ellos en nuestra lucha contra el mal de Zul\'Gurub. ¿Los tienes para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo oler el olor del mal vencido en ti, $n. Es un dulce olor colega... uno que creo que conoces bastante bien.$B$BSé que no es poca cosa haberme traído los Dechados de Poder necesarios para el cinturón. Tus obras no solo han honrado a la tribu, sino que también te has honrado a ti $gmismo:misma; entre la tribu. Aquí tienes: ¡toma el cinturón de augur y póntelo como si fuera tuyo!', 0),
(@ID, 'esMX', 'Puedo oler el olor del mal vencido en ti, $n. Es un dulce olor colega... uno que creo que conoces bastante bien.$B$BSé que no es poca cosa haberme traído los Dechados de Poder necesarios para el cinturón. Tus obras no solo han honrado a la tribu, sino que también te has honrado a ti $gmismo:misma; entre la tribu. Aquí tienes: ¡toma el cinturón de augur y póntelo como si fuera tuyo!', 0);
-- 8075 Dechados de Poder: el Camisote de augur
-- https://es.classic.wowhead.com/quest=8075
SET @ID := 8075;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Dechados de Poder son una fuente clave de poder mágico, el mismo tipo de poder que se utiliza para fabricar el Camisote del augur. Tráeme lo que necesito y podré compartir las mejores vestimentas que cualquier augur de Zandalar querría como propio.', 0),
(@ID, 'esMX', 'Los Dechados de Poder son una fuente clave de poder mágico, el mismo tipo de poder que se utiliza para fabricar el Camisote del augur. Tráeme lo que necesito y podré compartir las mejores vestimentas que cualquier augur de Zandalar querría como propio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé por lo que tuviste que pasar para traerme los Dechados de Poder, $n. No fue fácil, colega, derrotar al mal que se filtra de Zul\'Gurub como un lodo asqueroso, pero ahora que todo está dicho y hecho, puedo decir que serás $gvenerado:venerada; entre los Zandalar durante siglos.$B$B¡Toma, toma el Camisote de augur y úsalo con orgullo!', 0),
(@ID, 'esMX', 'Sé por lo que tuviste que pasar para traerme los Dechados de Poder, $n. No fue fácil, colega, derrotar al mal que se filtra de Zul\'Gurub como un lodo asqueroso, pero ahora que todo está dicho y hecho, puedo decir que serás $gvenerado:venerada; entre los Zandalar durante siglos.$B$B¡Toma, toma el Camisote de augur y úsalo con orgullo!', 0);
-- 8076 Dechados de Poder: el Manto de endemoniado
-- https://es.classic.wowhead.com/quest=8076
SET @ID := 8076;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Recuperaste los Dechados de Poder de Zul\'Gurub? Si bien tomaremos el poder latente de estos elementos y los haremos nuestros, te daremos tu propia recompensa de poder si tienes éxito...', 0),
(@ID, 'esMX', '¿Recuperaste los Dechados de Poder de Zul\'Gurub? Si bien tomaremos el poder latente de estos elementos y los haremos nuestros, te daremos tu propia recompensa de poder si tienes éxito...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Los Dechados de Poder de Zul\'Gurub deberían actuar como un recordatorio del poder desperdiciado. Los Gurubashi eran fuertes en su apogeo, pero se dejaron consumir por él. Un endemoniado sabe que el juego que juega es muy similar, pero el poder desatado es a menudo lo que se necesita para sobrevivir.$B$BUsa este manto como un aliado de honor de los Zandalar... te servirá bien.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Los Dechados de Poder de Zul\'Gurub deberían actuar como un recordatorio del poder desperdiciado. Los Gurubashi eran fuertes en su apogeo, pero se dejaron consumir por él. Un endemoniado sabe que el juego que juega es muy similar, pero el poder desatado es a menudo lo que se necesita para sobrevivir.$B$BUsa este manto como un aliado de honor de los Zandalar... te servirá bien.', 0);
-- 8077 Dechados de Poder: la Toga de endemoniado
-- https://es.classic.wowhead.com/quest=8077
SET @ID := 8077;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Dechados de Poder... ¿has vuelto con ellos? Solo una vez que los tengamos, compartiremos contigo el símbolo supremo del poder demoníaco, $n.', 0),
(@ID, 'esMX', 'Los Dechados de Poder... ¿has vuelto con ellos? Solo una vez que los tengamos, compartiremos contigo el símbolo supremo del poder demoníaco, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante: tu victoria en Zul\'Gurub nos ha asegurado, no, al mundo, que Hakkar no prevalecerá. Puede llegar el momento en que te enfrentes directamente al Dios de la Sangre... y si esto sucede, debes saber que tu reverencia está asegurada entre la tribu Zandalar.$B$BOh, y creo que esta sencilla toga también debería ayudar.$B$B<Al\'tabim te guiña un ojo con complicidad.>', 0),
(@ID, 'esMX', 'Impresionante: tu victoria en Zul\'Gurub nos ha asegurado, no, al mundo, que Hakkar no prevalecerá. Puede llegar el momento en que te enfrentes directamente al Dios de la Sangre... y si esto sucede, debes saber que tu reverencia está asegurada entre la tribu Zandalar.$B$BOh, y creo que esta sencilla toga también debería ayudar.$B$B<Al\'tabim te guiña un ojo con complicidad.>', 0);
-- 8078 Dechados de Poder: el Cinturón de vindicador
-- https://es.classic.wowhead.com/quest=8078
SET @ID := 8078;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído los Dechados de Poder? ¿Has aniquilado a los enemigos de la tribu? ¡Hakkar debe conocer la furia del vindicador!', 0),
(@ID, 'esMX', '¿Has traído los Dechados de Poder? ¿Has aniquilado a los enemigos de la tribu? ¡Hakkar debe conocer la furia del vindicador!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya conoces las artes del vindicador. Has honrado a la tribu. Te has honrado a ti $gmismo:misma;. Has sembrado el horror entre tus enemigos.$B$BEl Cinturón de vindicador es tuyo. Algún día serás $guno:una; con las artes del vindicador.', 0),
(@ID, 'esMX', 'Ya conoces las artes del vindicador. Has honrado a la tribu. Te has honrado a ti $gmismo:misma;. Has sembrado el horror entre tus enemigos.$B$BEl Cinturón de vindicador es tuyo. Algún día serás $guno:una; con las artes del vindicador.', 0);
-- 8079 Dechados de Poder: la coraza de vindicador
-- https://es.classic.wowhead.com/quest=8079
SET @ID := 8079;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tu presencia significa victoria? ¿Tienes los Dechados de Poder? ¡Háblame de la venganza que has realizado hoy!', 0),
(@ID, 'esMX', '¿Tu presencia significa victoria? ¿Tienes los Dechados de Poder? ¡Háblame de la venganza que has realizado hoy!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes ser $greverenciado:reverenciada; por tus actos. La tribu premia a sus $ghéroes:heroínas;. Zul\'Gurub ha probado la venganza de Zandalar como nunca antes.$B$BTus actos anunciarán los de otros por venir. Te verán como un signo de poder real. ¡Te verán como la venganza personificada!', 0),
(@ID, 'esMX', 'Debes ser $greverenciado:reverenciada; por tus actos. La tribu premia a sus $ghéroes:heroínas;. Zul\'Gurub ha probado la venganza de Zandalar como nunca antes.$B$BTus actos anunciarán los de otros por venir. Te verán como un signo de poder real. ¡Te verán como la venganza personificada!', 0);
-- Más cajas de suministros
-- 8081, 8157, 8158, 8159, 8298
-- https://es.classic.wowhead.com/quest=8081
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8081, 8157, 8158, 8159, 8298) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8081, 'esES', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8157, 'esES', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8158, 'esES', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8159, 'esES', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8298, 'esES', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8081, 'esMX', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8157, 'esMX', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8158, 'esMX', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8159, 'esMX', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8298, 'esMX', '$n, la Liga de Arathor tiene una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8081, 8157, 8158, 8159, 8298) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8081, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8157, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8158, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8159, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8298, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8081, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8157, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8158, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8159, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0),
(8298, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el soldado al mariscal de campo, todos notan tus contribuciones a nuestra lucha.', 0);
-- Más cajas de suministros
-- 8124, 8163, 8164, 8165, 8300
-- https://es.classic.wowhead.com/quest=8124
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8124, 8163, 8164, 8165, 8300) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8124, 'esES', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8163, 'esES', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8164, 'esES', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8165, 'esES', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8300, 'esES', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8124, 'esMX', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8163, 'esMX', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8164, 'esMX', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8165, 'esMX', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0),
(8300, 'esMX', '$n, los Rapiñadores tienen una misión permanente para que vuelvas a entrar en la Cuenca de Arathi, obtengas más cajas de recursos y me las traigas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8124, 8163, 8164, 8165, 8300) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8124, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8163, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8164, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8165, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8300, 'esES', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8124, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8163, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8164, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8165, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0),
(8300, 'esMX', 'Muy bueno. Se los llevaré a nuestros intendentes de inmediato, y se enviará un elogio por tus acciones a mis superiores.$B$BUna vez más, gracias $n. Desde el bruto al Alto señor de la Guerra, todos notan tus contribuciones a nuestra lucha.', 0);
-- 8101 El guijarro de Kajaro
-- https://es.classic.wowhead.com/quest=8101
SET @ID := 8101;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$r, el guijarro que se encuentra en del marco de este talismán proviene del Monte Kajaro en los Mares del Sur. El monte Kajaro es un área plagada de volatilidad, marcada por erupciones volcánicas violentas y, a menudo, mágicas.$B$BA medida que crece tu vínculo con los trols de Zandalar, también lo hará el poder de este guijarro. Aprovecha el poder del guijarro para derrotar a nuestros enemigos. Sé como la montaña: $gRápido, explosivo:Rápida, explosiva;, mortal...', 0),
(@ID, 'esMX', '$r, el guijarro que se encuentra en del marco de este talismán proviene del Monte Kajaro en los Mares del Sur. El monte Kajaro es un área plagada de volatilidad, marcada por erupciones volcánicas violentas y, a menudo, mágicas.$B$BA medida que crece tu vínculo con los trols de Zandalar, también lo hará el poder de este guijarro. Aprovecha el poder del guijarro para derrotar a nuestros enemigos. Sé como la montaña: $gRápido, explosivo:Rápida, explosiva;, mortal...', 0);
-- 8102 El guijarro de Kajaro
-- https://es.classic.wowhead.com/quest=8102
SET @ID := 8102;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $c. Puedo ver que el guijarro ha tenido mucho uso. Muchos de nuestros enemigos han caído en manos de tus habilidades de otro mundo. Su sufrimiento ha sido grande. Es hora de que aumente el poder del guijarro. Dámelo.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $c. Puedo ver que el guijarro ha tenido mucho uso. Muchos de nuestros enemigos han caído en manos de tus habilidades de otro mundo. Su sufrimiento ha sido grande. Es hora de que aumente el poder del guijarro. Dámelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé imparable, como los frentes fundidos de Kajaro.', 0),
(@ID, 'esMX', 'Sé imparable, como los frentes fundidos de Kajaro.', 0);
-- 8103 El guijarro de Kajaro
-- https://es.classic.wowhead.com/quest=8103
SET @ID := 8103;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Hakkari te teme, $n. Hablan de horrores que creían que solo su Dios sin rostro podía perpetrar. Los has quemado con la fuerza de Kajaro. Ahora conocen el miedo en dos lugares.$B$BEs hora de fortalecer aún más el guijarro. Pásame el talismán.', 0),
(@ID, 'esMX', 'Los Hakkari te teme, $n. Hablan de horrores que creían que solo su Dios sin rostro podía perpetrar. Los has quemado con la fuerza de Kajaro. Ahora conocen el miedo en dos lugares.$B$BEs hora de fortalecer aún más el guijarro. Pásame el talismán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Continúa diezmando a los trols de Zul\'Gurub. Debemos asegurarnos que el mundo no se doblegue ante la indomable voluntad de Hakkar.', 0),
(@ID, 'esMX', 'Continúa diezmando a los trols de Zul\'Gurub. Debemos asegurarnos que el mundo no se doblegue ante la indomable voluntad de Hakkar.', 0);
-- 8104 La Joya de Kajaro
-- https://es.classic.wowhead.com/quest=8104
SET @ID := 8104;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame el talismán, $n. Debo mostrarte algo.', 0),
(@ID, 'esMX', 'Dame el talismán, $n. Debo mostrarte algo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Al\'tabim rompe el guijarro con una poderosa fuerza invisible>.$B$B¿Lo ves? El guijarro es lo que llamamos geoda. Dentro del guijarro hay cristales poderosos que se han empapado de las energías latentes de nuestro mundo. Al cortar el guijarro por la mitad, finalmente he permitido que se desarrolle todo su potencial. Úselo para arrasar con nuestros enemigos.', 0),
(@ID, 'esMX', '<Al\'tabim rompe el guijarro con una poderosa fuerza invisible>.$B$B¿Lo ves? El guijarro es lo que llamamos geoda. Dentro del guijarro hay cristales poderosos que se han empapado de las energías latentes de nuestro mundo. Al cortar el guijarro por la mitad, finalmente he permitido que se desarrolle todo su potencial. Úselo para arrasar con nuestros enemigos.', 0);
-- La batalla por la Cuenca de Arathi
-- 8105, 8166, 8167, 8168, 10531
-- https://es.classic.wowhead.com/quest=8105
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Mina Atacada', `ObjectiveText2` = 'Serrería Atacada', `ObjectiveText3` = 'Herrería Atacada', `ObjectiveText4` = 'Granja Atacada', `VerifiedBuild` = 0 WHERE `id` IN(8105, 8166, 8167, 8168, 10531) AND `locale` IN('esES', 'esMX');
-- La batalla por la Cuenca de Arathi
-- 8120, 8169, 8170, 8171
-- https://es.classic.wowhead.com/quest=8120
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Mina Atacada', `ObjectiveText2` = 'Serrería Atacada', `ObjectiveText3` = 'Herrería Atacada', `ObjectiveText4` = 'Establo Atacado', `VerifiedBuild` = 0 WHERE `id` IN(8120, 8169, 8170, 8171) AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8120, 8169, 8170, 8171) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8120, 'esES', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0),
(8169, 'esES', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0),
(8170, 'esES', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0),
(8171, 'esES', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0),
(8120, 'esMX', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0),
(8169, 'esMX', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0),
(8170, 'esMX', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0),
(8171, 'esMX', 'Un explorador de los Rapiñadores vino a mí con un informe de tu éxito, $n. Bien hecho.$B$BComo aprenderás, para ganar la batalla por la Cuenca de Arathi, debemos estar siempre atentos y aplastar cualquier intento de expansión de la Alianza. Haz esto, y nuestra victoria aquí está asegurada.', 0);
-- 8106 Ocaso de Kezan
-- https://es.classic.wowhead.com/quest=8106
SET @ID := 8106;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acepta este talismán, $c. Acéptalo y usa su poder para derrotar a nuestros enemigos mutuos.$B$BAlrededor de tu cuello llevas un pedazo de historia. Kezan fue una vez un gran territorio del Imperio Zandalar. Por desgracia, la mancha de los príncipes mercantes goblin expulsaría a mis orgullosos hermanos y hermanas.$B$BKezan es ahora el hogar de la capital goblin de Minahonda; pero debes saber que antes de la mancha, tenía grandeza. Aún hasta el día de hoy, Kezan se considera tierra sagrada para mi pueblo.', 0),
(@ID, 'esMX', 'Acepta este talismán, $c. Acéptalo y usa su poder para derrotar a nuestros enemigos mutuos.$B$BAlrededor de tu cuello llevas un pedazo de historia. Kezan fue una vez un gran territorio del Imperio Zandalar. Por desgracia, la mancha de los príncipes mercantes goblin expulsaría a mis orgullosos hermanos y hermanas.$B$BKezan es ahora el hogar de la capital goblin de Minahonda; pero debes saber que antes de la mancha, tenía grandeza. Aún hasta el día de hoy, Kezan se considera tierra sagrada para mi pueblo.', 0);
-- 8107 Ocaso de Kezan
-- https://es.classic.wowhead.com/quest=8107
SET @ID := 8107;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El honor se gana entre los trols Zandalar, $n. Con el honor viene la recompensa: amistad, alianza...$B$BDame el talismán para que pueda aumentar su poder.', 0),
(@ID, 'esMX', 'El honor se gana entre los trols Zandalar, $n. Con el honor viene la recompensa: amistad, alianza...$B$BDame el talismán para que pueda aumentar su poder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ven a la oscuridad, $c. Abraza las sombras. Deja que la Mancha de Kezan complete tu llegada en la oscuridad.', 0),
(@ID, 'esMX', 'Ven a la oscuridad, $c. Abraza las sombras. Deja que la Mancha de Kezan complete tu llegada en la oscuridad.', 0);
-- 8108 Ocaso de Kezan
-- https://es.classic.wowhead.com/quest=8108
SET @ID := 8108;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy listo para ti, $c. Una vez más mejoraré tu talismán. Solo te pido que continúes destruyendo a Hakkar y sus secuaces.$B$BDame el talismán.', 0),
(@ID, 'esMX', 'Estoy listo para ti, $c. Una vez más mejoraré tu talismán. Solo te pido que continúes destruyendo a Hakkar y sus secuaces.$B$BDame el talismán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es solo a través de nuestros esfuerzos combinados que detendremos al Rompealmas.', 0),
(@ID, 'esMX', 'Es solo a través de nuestros esfuerzos combinados que detendremos al Rompealmas.', 0);
-- 8109 Mancha imparable de Kezan
-- https://es.classic.wowhead.com/quest=8109
SET @ID := 8109;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Invoca a tus demonios, $c. Déjalos disfrutar de la energía de la Mancha de Kezan. ¡Ordénales en el campo de batalla! ¡Diezma al enemigo!$B$BSí... Ha llegado el momento de aplicar la mejora final a la Mancha de Kezan. Dame el talismán.', 0),
(@ID, 'esMX', 'Invoca a tus demonios, $c. Déjalos disfrutar de la energía de la Mancha de Kezan. ¡Ordénales en el campo de batalla! ¡Diezma al enemigo!$B$BSí... Ha llegado el momento de aplicar la mejora final a la Mancha de Kezan. Dame el talismán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Arranca la carne de sus cadáveres. Observa cómo las sombras consumen al Hakkari. Saca poder de su miedo, $c. Deja que la Mancha de Kezan aumente este poder...', 0),
(@ID, 'esMX', 'Arranca la carne de sus cadáveres. Observa cómo las sombras consumen al Hakkari. Saca poder de su miedo, $c. Deja que la Mancha de Kezan aumente este poder...', 0);
-- 8110 Algas de los Mares del Sur encantadas
-- https://es.classic.wowhead.com/quest=8110
SET @ID := 8110;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ves estas algas de aquí, colega? Es de los mares del sur. Solo le agregamos un poco de mojo y un poco de magia y adquiere las propiedades más adecuadas para su dueño.$B$BEres $gun:una; $c, así que será fácil, colega. Simplemente lialo alrededor de tu cuello y piensa en la naturaleza o las ardillas o lo que sea que le guste a la gente.', 0),
(@ID, 'esMX', '¿Ves estas algas de aquí, colega? Es de los mares del sur. Solo le agregamos un poco de mojo y un poco de magia y adquiere las propiedades más adecuadas para su dueño.$B$BEres $gun:una; $c, así que será fácil, colega. Simplemente lialo alrededor de tu cuello y piensa en la naturaleza o las ardillas o lo que sea que le guste a la gente.', 0);
-- 8111 Algas de los Mares del Sur encantadas
-- https://es.classic.wowhead.com/quest=8111
SET @ID := 8111;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oye, colega! Es bueno verte de nuevo. La tribu estará hablando de tu matanza de los Hakkari y todo eso. Molthor me dio la palabra para agregar más mojo a tu talismán. Solo déjalo aquí y Maywiki lo mejorará.', 0),
(@ID, 'esMX', '¡Oye, colega! Es bueno verte de nuevo. La tribu estará hablando de tu matanza de los Hakkari y todo eso. Molthor me dio la palabra para agregar más mojo a tu talismán. Solo déjalo aquí y Maywiki lo mejorará.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La pieza del cuello no es para fumar, colega! Tienes que usarlo para luchar contra el mal.', 0),
(@ID, 'esMX', '¡La pieza del cuello no es para fumar, colega! Tienes que usarlo para luchar contra el mal.', 0);
-- 8112 Algas de los Mares del Sur encantadas
-- https://es.classic.wowhead.com/quest=8112
SET @ID := 8112;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo ser el talismán, colega? Parece que haber que añadir más magia y mojo a sus hojas y necesita florecer un poco... se está marchitando. Dámelo y Maywiki lo arreglará.', 0),
(@ID, 'esMX', '¿Cómo ser el talismán, colega? Parece que haber que añadir más magia y mojo a sus hojas y necesita florecer un poco... se está marchitando. Dámelo y Maywiki lo arreglará.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora coge a los trols malvados de Zul\'Gurub y enséñales lo que pueden hacer tus poderes naturales, colega!', 0),
(@ID, 'esMX', '¡Ahora coge a los trols malvados de Zul\'Gurub y enséñales lo que pueden hacer tus poderes naturales, colega!', 0);
-- 8113 Algas de los Mares del Sur encantadas prístinas
-- https://es.classic.wowhead.com/quest=8113
SET @ID := 8113;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! Ha pasado mucho tiempo desde que te vi. ¿Sabías que el propio rey Rastakhan me está dando la orden de agregar el último toque de mojo y magia a tu talismán? ¡Es verdad, colega! No lo hubiera creído si no lo hubiera visto con mis propios ojos. Dámelo.', 0),
(@ID, 'esMX', '¡$n! Ha pasado mucho tiempo desde que te vi. ¿Sabías que el propio rey Rastakhan me está dando la orden de agregar el último toque de mojo y magia a tu talismán? ¡Es verdad, colega! No lo hubiera creído si no lo hubiera visto con mis propios ojos. Dámelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n colega, ha sido un buen viaje. Continúa matando y eliminando a Hakkar y sus secuaces.', 0),
(@ID, 'esMX', '$n colega, ha sido un buen viaje. Continúa matando y eliminando a Hakkar y sus secuaces.', 0);
-- 8114 Controla cuatro bases
-- https://es.classic.wowhead.com/quest=8114
SET @ID := 8114;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy buen trabajo, $n! Un explorador emocionado se acercó a mí con un informe de tus hazañas. ¡En la Liga de Arathor estamos muy contentos!$B$BRápidamente te estás convirtiendo en $gun héroe:una heroína; local entre los soldados de la Liga, y la hazaña de hoy demuestra una vez más tu excelente reputación.', 0),
(@ID, 'esMX', '¡Muy buen trabajo, $n! Un explorador emocionado se acercó a mí con un informe de tus hazañas. ¡En la Liga de Arathor estamos muy contentos!$B$BRápidamente te estás convirtiendo en $gun héroe:una heroína; local entre los soldados de la Liga, y la hazaña de hoy demuestra una vez más tu excelente reputación.', 0);
-- 8115 Controla cinco bases
-- https://es.classic.wowhead.com/quest=8115
SET @ID := 8115;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo hiciste! ¡Te llevaste todas las bases! ¡Bien hecho, $n!$B$BHabía quienes dudaban de tus posibilidades, pero sabía que podías hacerlo. Gracias, y debes saber que la Liga de Arathor te tiene en alta estima, al igual que los Rapiñadores de los Renegados deben temer la sola mención de tu nombre.', 0),
(@ID, 'esMX', '¡Lo hiciste! ¡Te llevaste todas las bases! ¡Bien hecho, $n!$B$BHabía quienes dudaban de tus posibilidades, pero sabía que podías hacerlo. Gracias, y debes saber que la Liga de Arathor te tiene en alta estima, al igual que los Rapiñadores de los Renegados deben temer la sola mención de tu nombre.', 0);
-- 8116 Visión de Voodress
-- https://es.classic.wowhead.com/quest=8116
SET @ID := 8116;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú y Maywiki tenéis algo en común, colega. ¡Los dos seremos $c! Aunque, Maywiki es más un místico y tú eres más un matorral. Aún así, ambos sabemos lo que traen los grandes espíritus.$B$BComo regalo te doy este orbe para que lo lleves alrededor del cuello. ¡Mira dentro y ve el pueblo de Voodress en los mares del sur! ¡Deja que te levante el ánimo!', 0),
(@ID, 'esMX', 'Tú y Maywiki tenéis algo en común, colega. ¡Los dos seremos $c! Aunque, Maywiki es más un místico y tú eres más un matorral. Aún así, ambos sabemos lo que traen los grandes espíritus.$B$BComo regalo te doy este orbe para que lo lleves alrededor del cuello. ¡Mira dentro y ve el pueblo de Voodress en los mares del sur! ¡Deja que te levante el ánimo!', 0);
-- 8117 Visión de Voodress
-- https://es.classic.wowhead.com/quest=8117
SET @ID := 8117;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buenas noticias, $n. Molthor está cantando tus alabanzas últimamente. Dice cómo te convertirás en $gun verdadero héroe:una verdadera heroína; de Zandalar.$B$B¡También dice que Maywiki pula tu orbe un poco más! Dájalo aquí para que Maywiki pueda iluminar la visión.', 0),
(@ID, 'esMX', 'Buenas noticias, $n. Molthor está cantando tus alabanzas últimamente. Dice cómo te convertirás en $gun verdadero héroe:una verdadera heroína; de Zandalar.$B$B¡También dice que Maywiki pula tu orbe un poco más! Dájalo aquí para que Maywiki pueda iluminar la visión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuidado con los espíritus malignos de Hakkari, colega. Honestamente, son espeluznantes.', 0),
(@ID, 'esMX', 'Cuidado con los espíritus malignos de Hakkari, colega. Honestamente, son espeluznantes.', 0);
-- 8118 Visión de Voodress
-- https://es.classic.wowhead.com/quest=8118
SET @ID := 8118;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Chama-colega! ¡Maywiki bromea!$B$B<Maywiki se ríe.>$B$BEntonces, has estado usando espíritus y elementos contra nuestros enemigos en Zul\'Gurub, ¿eh? ¡Alabado sea el espíritu!$B$BMaywiki iluminará tu orbe. Dámelo, $n.', 0),
(@ID, 'esMX', '¡Chama-colega! ¡Maywiki bromea!$B$B<Maywiki se ríe.>$B$BEntonces, has estado usando espíritus y elementos contra nuestros enemigos en Zul\'Gurub, ¿eh? ¡Alabado sea el espíritu!$B$BMaywiki iluminará tu orbe. Dámelo, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Échale un vistazo ahora, $n. Voodress entra aún más claro ahora, ¿sí? Deja que el poder primordial fluya a través de ti, colega.', 0),
(@ID, 'esMX', 'Échale un vistazo ahora, $n. Voodress entra aún más claro ahora, ¿sí? Deja que el poder primordial fluya a través de ti, colega.', 0);
-- 8119 Visión inmaculada de Voodress
-- https://es.classic.wowhead.com/quest=8119
SET @ID := 8119;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maywiki señala tu talismán.>$B$B¡Míralo, $n! Ha cobrado vida. Los espíritus bailan alrededor del orbe.$B$BDáselo a Maywiki para que pueda hacer un último ajuste.', 0),
(@ID, 'esMX', '<Maywiki señala tu talismán.>$B$B¡Míralo, $n! Ha cobrado vida. Los espíritus bailan alrededor del orbe.$B$BDáselo a Maywiki para que pueda hacer un último ajuste.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un día, $n, podrás usar este orbe para comunicarte directamente conmigo. Siempre que esta batalla con Hakkar termine y Maywiki se vaya a casa. Llamemos a los espíritus y pidamos que ese día llegue pronto.', 0),
(@ID, 'esMX', 'Un día, $n, podrás usar este orbe para comunicarte directamente conmigo. Siempre que esta batalla con Hakkar termine y Maywiki se vaya a casa. Llamemos a los espíritus y pidamos que ese día llegue pronto.', 0);
-- 8121 Toma el control de cuatro bases
-- https://es.classic.wowhead.com/quest=8121
SET @ID := 8121;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Tus últimas acciones en la Cuenca de Arathi fueron bastante difíciles, por lo que tus éxitos son dignos de elogio. La Liga de Arathor debe estar recuperándose de las últimas escaramuzas en la cuenca, lamiendo sus heridas y, esperemos, reconsiderando su decisión de luchar aquí.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Tus últimas acciones en la Cuenca de Arathi fueron bastante difíciles, por lo que tus éxitos son dignos de elogio. La Liga de Arathor debe estar recuperándose de las últimas escaramuzas en la cuenca, lamiendo sus heridas y, esperemos, reconsiderando su decisión de luchar aquí.', 0);
-- 8122 Toma el control de cinco bases
-- https://es.classic.wowhead.com/quest=8122
SET @ID := 8122;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los gritos de la Alianza mientras tú y tus compatriotas los atacaban se podían escuchar incluso desde aquí, $n. Casi puedo sentir lástima de ellos por el dolor y el miedo que le has causado a sus filas. Casi, pero no del todo.$B$BTu valor para los Rapiñadores es indudable. Tus hazañas en la Cuenca de Arathi han sido de lo más impresionantes y han resonado entre las cámaras de Varimathras... y la misma Dama Oscura.', 0),
(@ID, 'esMX', 'Los gritos de la Alianza mientras tú y tus compatriotas los atacaban se podían escuchar incluso desde aquí, $n. Casi puedo sentir lástima de ellos por el dolor y el miedo que le has causado a sus filas. Casi, pero no del todo.$B$BTu valor para los Rapiñadores es indudable. Tus hazañas en la Cuenca de Arathi han sido de lo más impresionantes y han resonado entre las cámaras de Varimathras... y la misma Dama Oscura.', 0);
-- 8141 Dije Zandalar de las Sombras
-- https://es.classic.wowhead.com/quest=8141
SET @ID := 8141;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Avanzas rápidamente, joven $c. Quizás sea el momento de iniciarte en el Shera Ali\'kh - Zandalari de la Mano de la Muerte. Durante miles de años hemos desempeñado el papel de asesinos del Imperio Zandalar. Durante demasiado tiempo nos hemos sentado de brazos cruzados, permitiendo que el Hakkari crezca en fuerza. Una vez más nos enfrentamos a Hakkar, pero esta vez sin el apoyo de un frente $r unido. ¡Eres tu y tus aliados quienes deben ayudar a vencer al Dios de la Sangre y sus secuaces!$B$BUsa este talismán y deja que te ayude en tus viajes.', 0),
(@ID, 'esMX', 'Avanzas rápidamente, joven $c. Quizás sea el momento de iniciarte en el Shera Ali\'kh - Zandalari de la Mano de la Muerte. Durante miles de años hemos desempeñado el papel de asesinos del Imperio Zandalar. Durante demasiado tiempo nos hemos sentado de brazos cruzados, permitiendo que el Hakkari crezca en fuerza. Una vez más nos enfrentamos a Hakkar, pero esta vez sin el apoyo de un frente $r unido. ¡Eres tu y tus aliados quienes deben ayudar a vencer al Dios de la Sangre y sus secuaces!$B$BUsa este talismán y deja que te ayude en tus viajes.', 0);
-- 8142 Dije Zandalar de las Sombras
-- https://es.classic.wowhead.com/quest=8142
SET @ID := 8142;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $n. Tienes un don para matar que no he sentido en otro en muchos años. Incluso Molthor es consciente del trabajo que has hecho para Zandalar. Es hora de mejorar aún más tu talismán. Dámelo.', 0),
(@ID, 'esMX', 'Impresionante, $n. Tienes un don para matar que no he sentido en otro en muchos años. Incluso Molthor es consciente del trabajo que has hecho para Zandalar. Es hora de mejorar aún más tu talismán. Dámelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo queda una mejora que se puede colocar en el talismán, $c. Cuando sea el momento adecuado, aplicaré esa mejora.', 0),
(@ID, 'esMX', 'Solo queda una mejora que se puede colocar en el talismán, $c. Cuando sea el momento adecuado, aplicaré esa mejora.', 0);
-- 8143 Dije Zandalar de las Sombras
-- https://es.classic.wowhead.com/quest=8143
SET @ID := 8143;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento que has causado innumerables muertes a los Hakkari, $n. Llevas el hedor de su mojo.$B$B¿Asumo que el talismán de la Sombra ha ayudado en la matanza? Dámelo y permíteme potenciar su poder.', 0),
(@ID, 'esMX', 'Siento que has causado innumerables muertes a los Hakkari, $n. Llevas el hedor de su mojo.$B$B¿Asumo que el talismán de la Sombra ha ayudado en la matanza? Dámelo y permíteme potenciar su poder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gUn asesino:Una asesina; de tu calibre debería tener un amplio margen. ¡Tus enemigos deben aprender a respetar! Obtendrás exactamente eso cuando el enemigo vea el destello de la Mano de la Muerte, y sea demasiado tarde...', 0),
(@ID, 'esMX', '$gUn asesino:Una asesina; de tu calibre debería tener un amplio margen. ¡Tus enemigos deben aprender a respetar! Obtendrás exactamente eso cuando el enemigo vea el destello de la Mano de la Muerte, y sea demasiado tarde...', 0);
