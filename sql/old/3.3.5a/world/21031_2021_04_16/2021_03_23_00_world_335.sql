-- 8302 La mano del honrado
-- https://es.classic.wowhead.com/quest=8302
SET @ID := 8302;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás algún día todo el Fuerte Cenarion esté trabajando bajo tu mando.', 0),
(@ID, 'esMX', 'Quizás algún día todo el Fuerte Cenarion esté trabajando bajo tu mando.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $ghéroe:heroína;. Ahora se te otorgará la capacidad de sustituir a otro Agente de Nozdormu.', 0),
(@ID, 'esMX', 'Bien hecho, $ghéroe:heroína;. Ahora se te otorgará la capacidad de sustituir a otro Agente de Nozdormu.', 0);
-- 8303 Anacronos
-- https://es.classic.wowhead.com/quest=8303
SET @ID := 8303;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres la esperanza de Kalimdor, $n.', 0),
(@ID, 'esMX', 'Eres la esperanza de Kalimdor, $n.', 0);
-- 8304 Queridísima Natalia
-- https://es.classic.wowhead.com/quest=8304
SET @ID := 8304;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Has interrogado a Frankal', `ObjectiveText2` = 'Has interrogado a Rutgar', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No pierdas el tiempo, $n!', 0),
(@ID, 'esMX', '¡No pierdas el tiempo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El comandante Mar\'alith medita un momento.>$B$BTengo que cumplir mi deber, tanto si está viva como si no. La encontraremos, pero yo no puedo dejar la avanzada. ¿Puedo contar contigo de nuevo, $n?', 0),
(@ID, 'esMX', '<El comandante Mar\'alith medita un momento.>$B$BTengo que cumplir mi deber, tanto si está viva como si no. La encontraremos, pero yo no puedo dejar la avanzada. ¿Puedo contar contigo de nuevo, $n?', 0);
-- 8305 Recuerdos olvidados
-- https://es.classic.wowhead.com/quest=8305
SET @ID := 8305;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedes sentir un gran dolor girando alrededor de este cristal. La fuerza es tan poderosa que sientes como si pudieras colapsar y morir de tristeza.', 0),
(@ID, 'esMX', 'Puedes sentir un gran dolor girando alrededor de este cristal. La fuerza es tan poderosa que sientes como si pudieras colapsar y morir de tristeza.', 0);
-- 8306 En las fauces de la locura
-- https://es.wowhead.com/quest=8306
SET @ID := 8306;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'El sino de la maestra Natalia Mar\'alith', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Natalia?', 0),
(@ID, 'esMX', '¿Natalia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El comandante Mar\'alith se lleva una mano al pecho.>$B$B¿C\'Thun? ¿Qué es C\'Thun? ¿Cómo puede haber convertido a mi Natalia en ese monstruo que describes?', 0),
(@ID, 'esMX', '<El comandante Mar\'alith se lleva una mano al pecho.>$B$B¿C\'Thun? ¿Qué es C\'Thun? ¿Cómo puede haber convertido a mi Natalia en ese monstruo que describes?', 0);
-- 8307 Receta del desierto
-- https://es.wowhead.com/quest=8307
SET @ID := 8307;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este libro contiene varias recetas comunes y algunas bastante exóticas. Después de ojearlo durante unos segundos, ves una receta con carne de gusano de arena.', 0),
(@ID, 'esMX', 'Este libro contiene varias recetas comunes y algunas bastante exóticas. Después de ojearlo durante unos segundos, ves una receta con carne de gusano de arena.', 0);
-- 8309 Los grabados de los glifos
-- https://es.wowhead.com/quest=8309
SET @ID := 8309;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si te encuentras a una elfa de la noche medio loca en las colmenas, dale una patada en el trasero.', 0),
(@ID, 'esMX', 'Si te encuentras a una elfa de la noche medio loca en las colmenas, dale una patada en el trasero.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca había visto nada igual, no entiendo estos glifos. Espero que los estudios de Frankal nos iluminen un poco.', 0),
(@ID, 'esMX', 'Nunca había visto nada igual, no entiendo estos glifos. Espero que los estudios de Frankal nos iluminen un poco.', 0);
-- 8310 Descifrar el código
-- https://es.wowhead.com/quest=8310
SET @ID := 8310;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vete por ahí. No tengo tiempo para esto.', 0),
(@ID, 'esMX', 'Vete por ahí. No tengo tiempo para esto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Magnífico! No te alejes mucho; seguro que tenemos más misiones para ti.', 0),
(@ID, 'esMX', '¡Magnífico! No te alejes mucho; seguro que tenemos más misiones para ti.', 0);
-- Golosinas de Halloween para Jesper
-- 8311, 8312
-- https://es.wowhead.com/quest=8311
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8311, 8312) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8311, 'esES', '¿Has terminado ya lo del truco o trato? Ojalá pudiese ir, pero no quiero cruzarme con Alamuerte.', 0),
(8312, 'esES', '¿Has terminado ya lo del truco o trato? Ojalá pudiese ir, pero no quiero cruzarme con Alamuerte.', 0),
(8311, 'esMX', '¿Has terminado ya lo del truco o trato? Ojalá pudiese ir, pero no quiero cruzarme con Alamuerte.', 0),
(8312, 'esMX', '¿Has terminado ya lo del truco o trato? Ojalá pudiese ir, pero no quiero cruzarme con Alamuerte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8311, 8312) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8311, 'esES', '¡Genial, lo has conseguido todo! ¡Eres increíble!$B$BGracias por ir de truco o trato por mí. Ten, regalitos de calabaza, ¡ya verás cómo te gustan!$B$B¡Feliz Halloween, $n!', 0),
(8312, 'esES', '¡Genial, lo has conseguido todo! ¡Eres increíble!$B$BGracias por ir de truco o trato por mí. Ten, regalitos de calabaza, ¡ya verás cómo te gustan!$B$B¡Feliz Halloween, $n!', 0),
(8311, 'esMX', '¡Genial, lo has conseguido todo! ¡Eres increíble!$B$BGracias por ir de truco o trato por mí. Ten, regalitos de calabaza, ¡ya verás cómo te gustan!$B$B¡Feliz Halloween, $n!', 0),
(8312, 'esMX', '¡Genial, lo has conseguido todo! ¡Eres increíble!$B$BGracias por ir de truco o trato por mí. Ten, regalitos de calabaza, ¡ya verás cómo te gustan!$B$B¡Feliz Halloween, $n!', 0);
-- 8313 Compartir el conocimiento
-- https://es.wowhead.com/quest=8313
SET @ID := 8313;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has aprendido la receta? ¡Espero que la compartas!', 0),
(@ID, 'esMX', '¿Has aprendido la receta? ¡Espero que la compartas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Echemos un vistazo a eso...$B$BParece bastante simple. Tienen sus propios nombres para algunas de las hierbas, pero es fácil descifrarlos. Mira, te lo mostraré.', 0),
(@ID, 'esMX', 'Echemos un vistazo a eso...$B$BParece bastante simple. Tienen sus propios nombres para algunas de las hierbas, pero es fácil descifrarlos. Mira, te lo mostraré.', 0);
-- 8314 Desentrañar el misterio
-- https://es.wowhead.com/quest=8314
SET @ID := 8314;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué llevas ahí, $n?', 0),
(@ID, 'esMX', '¿Qué llevas ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los enanos no pudieron descifrarlo porque no hay nada que descifrar. La capa externa fluida tiene que alinearse con los grabados del interior para transmitir el mensaje. Interesante...$B$BPodemos traducir los datos, pero antes hay que desbloquear el código. En el prisma solo hay una pista y no es muy esperanzadora.', 0),
(@ID, 'esMX', 'Los enanos no pudieron descifrarlo porque no hay nada que descifrar. La capa externa fluida tiene que alinearse con los grabados del interior para transmitir el mensaje. Interesante...$B$BPodemos traducir los datos, pero antes hay que desbloquear el código. En el prisma solo hay una pista y no es muy esperanzadora.', 0);
-- 8315 La llamada
-- https://es.wowhead.com/quest=8315
SET @ID := 8315;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aprovecha la oportunidad en cuanto se presente!', 0),
(@ID, 'esMX', '¡Aprovecha la oportunidad en cuanto se presente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tengo 20.000 años de historia en las manos, $n!', 0),
(@ID, 'esMX', '¡Tengo 20.000 años de historia en las manos, $n!', 0);
-- Armamentos de guerra
-- 8316, 8376, 8377, 8378, 8379, 8380, 8381, 8382
-- https://es.classic.wowhead.com/quest=8316
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8316, 8376, 8377, 8378, 8379, 8380, 8381, 8382) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8316, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8376, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8377, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8378, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8379, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8380, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8381, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8382, 'esES', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8316, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8376, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8377, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8378, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8379, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8380, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8381, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0),
(8382, 'esMX', 'Viene la guerra, $n, y con ella vienen horrores incalculables. Has hecho todo lo que se te puede pedir y por eso debes ser $grecompensado:recompensada;.$B$BSi esta... esta profecía alguna vez se cumpliera...$B$B<El geólogo Larksbane se pone pálido.>$B$BEl futuro de todos nosotros podría llegar a su fin.$B$BEste armamento resultará indispensable para la campaña en este desierto.', 0);
-- 8317 Echar una mano en la cocina
-- https://es.classic.wowhead.com/quest=8317
SET @ID := 8317;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal van esas albóndigas?', 0),
(@ID, 'esMX', '¿Qué tal van esas albóndigas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Me has salvado la vida. Las albóndigas salieron bastante bien. No esperaba que algo del Martillo Crepuscular tuviera tan buen sabor.', 0),
(@ID, 'esMX', '¡Excelente! Me has salvado la vida. Las albóndigas salieron bastante bien. No esperaba que algo del Martillo Crepuscular tuviera tan buen sabor.', 0);
-- 8318 Mensajes secretos
-- https://es.wowhead.com/quest=8318
SET @ID := 8318;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído textos?', 0),
(@ID, 'esMX', '¿Me has traído textos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Guardaré esto, quizás sea útil más tarde.', 0),
(@ID, 'esMX', '¡Excelente! Guardaré esto, quizás sea útil más tarde.', 0);
-- 8319 Textos Crepusculares codificados
-- https://es.wowhead.com/quest=8319
SET @ID := 8319;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue trayéndome textos. Pronto podremos expulsar al Martillo Crepuscular de Silithus.', 0),
(@ID, 'esMX', 'Sigue trayéndome textos. Pronto podremos expulsar al Martillo Crepuscular de Silithus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente trabajo! Hablaré bien de ti.', 0),
(@ID, 'esMX', '¡Excelente trabajo! Hablaré bien de ti.', 0);
-- 8320 Geoseñores Crepusculares
-- https://es.classic.wowhead.com/quest=8320
SET @ID := 8320;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entra en el desierto y encuentra a los geoseñores Crepusculares, $n. Vuelve a mí después de matarlos.', 0),
(@ID, 'esMX', 'Entra en el desierto y encuentra a los geoseñores Crepusculares, $n. Vuelve a mí después de matarlos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo bien hecho, $n. Matar a los geoseñores Crepusculares debe de haber causado un duro golpe al culto. Esperemos haber frustrado sus planes...', 0),
(@ID, 'esMX', 'Un trabajo bien hecho, $n. Matar a los geoseñores Crepusculares debe de haber causado un duro golpe al culto. Esperemos haber frustrado sus planes...', 0);
-- 8321 Vyral el Vil
-- https://es.wowhead.com/quest=8321
SET @ID := 8321;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has derrotado ya a Vyral el Vil? ¿Tienes su sello?', 0),
(@ID, 'esMX', '$n, ¿has derrotado ya a Vyral el Vil? ¿Tienes su sello?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! ¡Vyral está muerto! Eso solo puede significar el fin de las operaciones del Martillo Crepuscular en Silithus. Es posible que haya más por ahí, pero el golpe que le has dado al culto hoy, es uno del que no se recuperarán fácilmente.', 0),
(@ID, 'esMX', '¡Lo has conseguido! ¡Vyral está muerto! Eso solo puede significar el fin de las operaciones del Martillo Crepuscular en Silithus. Es posible que haya más por ahí, pero el golpe que le has dado al culto hoy, es uno del que no se recuperarán fácilmente.', 0);
-- 8322 Huevos podridos
-- https://es.wowhead.com/quest=8322
SET @ID := 8322;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barril está lleno de cerveza.$B$BDespués de abrirte paso con éxito dentro de la posada, ahora colocas los huevos dentro del barril. Puedes oler el mal olor que impregna el aire...', 0),
(@ID, 'esMX', 'El barril está lleno de cerveza.$B$BDespués de abrirte paso con éxito dentro de la posada, ahora colocas los huevos dentro del barril. Puedes oler el mal olor que impregna el aire...', 0);
-- 8323 El creyente verdadero
-- https://es.wowhead.com/quest=8323
SET @ID := 8323;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algún texto codificado? Tengo muchas ganas de leer El creyente verdadero de este mes.', 0),
(@ID, 'esMX', '¿Has encontrado algún texto codificado? Tengo muchas ganas de leer El creyente verdadero de este mes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Me pondré a descifrar esto en cuanto pueda. Si descubro algo interesante, encontraré la forma de hacerte llegar la información.', 0),
(@ID, 'esMX', '¡Excelente! Me pondré a descifrar esto en cuanto pueda. Si descubro algo interesante, encontraré la forma de hacerte llegar la información.', 0);
-- 8324 Seguir creyendo
-- https://es.wowhead.com/quest=8324
SET @ID := 8324;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado más textos encriptados? Tráeme todos los que puedas, este trabajo de descodificación lleva su tiempo.', 0),
(@ID, 'esMX', '¿Has encontrado más textos encriptados? Tráeme todos los que puedas, este trabajo de descodificación lleva su tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Me muero por leerlos. Por favor, sigue trayéndome textos encriptados si los encuentras.', 0),
(@ID, 'esMX', '¡Excelente! Me muero por leerlos. Por favor, sigue trayéndome textos encriptados si los encuentras.', 0);
-- 8328 Instrucción de mago
-- https://es.classic.wowhead.com/quest=8328
SET @ID := 8328;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n - Creo que eres $guno de los nuevos magos:una de las nuevas magas; aquí en la isla, ¿no? Bueno, has venido al lugar indicado. Si lo que buscas es el dominio arcano, entonces puedo proporcionar ese conocimiento, siempre que tengas los medios para abonar los costos de entrenamiento y la capacidad de concentrarte en las lecciones que te enseñaré.$B$B¡Empecemos!', 0),
(@ID, 'esMX', 'Ah, $n - Creo que eres $guno de los nuevos magos:una de las nuevas magas; aquí en la isla, ¿no? Bueno, has venido al lugar indicado. Si lo que buscas es el dominio arcano, entonces puedo proporcionar ese conocimiento, siempre que tengas los medios para abonar los costos de entrenamiento y la capacidad de concentrarte en las lecciones que te enseñaré.$B$B¡Empecemos!', 0);
-- 8331 Aurel Hojaurea
-- https://es.classic.wowhead.com/quest=8331
SET @ID := 8331;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, buenos días. ¿Me han dicho que te vas a presentar ante el Consejo Abisal? Si es así, escucha mis palabras atentamente...', 0),
(@ID, 'esMX', '$n, buenos días. ¿Me han dicho que te vas a presentar ante el Consejo Abisal? Si es así, escucha mis palabras atentamente...', 0);
-- 8332 Los Duques del Consejo
-- https://es.classic.wowhead.com/quest=8332
SET @ID := 8332;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el fragmento y los emblemas, $n? Los necesito para hacer el medallón de estatus de fiel Crepuscular.', 0),
(@ID, 'esMX', '¿Tienes el fragmento y los emblemas, $n? Los necesito para hacer el medallón de estatus de fiel Crepuscular.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. He estado trabajando en el medallón. Ahora, con estos últimos ingredientes, acabaré en un abrir y cerrar de ojos...$B$BYa estamos. Aquí tienes el medallón, $n.$B$BTendrás que llevarlo cuando actives una de las piedras de viento del Martillo Crepuscular. Póntelo junto con el resto de los símbolos del Martillo y el Consejo Abisal te verá como uno de sus subordinados.', 0),
(@ID, 'esMX', 'Ah, muy bien. He estado trabajando en el medallón. Ahora, con estos últimos ingredientes, acabaré en un abrir y cerrar de ojos...$B$BYa estamos. Aquí tienes el medallón, $n.$B$BTendrás que llevarlo cuando actives una de las piedras de viento del Martillo Crepuscular. Póntelo junto con el resto de los símbolos del Martillo y el Consejo Abisal te verá como uno de sus subordinados.', 0);
-- 8333 Medallón de estatus
-- https://es.classic.wowhead.com/quest=8333
SET @ID := 8333;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si necesitas otro medallón de estatus del culto crepuscular, me complace complacerte. Sin embargo, necesitaré otro fragmento luminoso y algunos blasones abisales...', 0),
(@ID, 'esMX', 'Si necesitas otro medallón de estatus del culto crepuscular, me complace complacerte. Sin embargo, necesitaré otro fragmento luminoso y algunos blasones abisales...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n. Un medallón más de estatus del culto Crepuscular. ¡Úsalo bien y te deseo suerte contra el Consejo Abisal!', 0),
(@ID, 'esMX', 'Aquí tienes, $n. Un medallón más de estatus del culto Crepuscular. ¡Úsalo bien y te deseo suerte contra el Consejo Abisal!', 0);
-- 8341 Señores del Consejo
-- https://es.classic.wowhead.com/quest=8341
SET @ID := 8341;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los fragmentos y los sellos, $n? Los necesitaré para crear el anillo de nobleza.', 0),
(@ID, 'esMX', '¿Tienes los fragmentos y los sellos, $n? Los necesitaré para crear el anillo de nobleza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias. Un momento y tendré ese anillo listo para ti...$B$BAhí está. Ahora estás $glisto:lista;.$B$BAsegúrate de usar este anillo, junto con un medallón de estatus y el resto de los adornos crepusculares, cuando actives una piedra de viento mayor. Hazlo y el Consejo Abisal te considerará uno de sus sirvientes. Entonces, ¡quizás puedas atraer a uno a una emboscada!', 0),
(@ID, 'esMX', 'Gracias. Un momento y tendré ese anillo listo para ti...$B$BAhí está. Ahora estás $glisto:lista;.$B$BAsegúrate de usar este anillo, junto con un medallón de estatus y el resto de los adornos crepusculares, cuando actives una piedra de viento mayor. Hazlo y el Consejo Abisal te considerará uno de sus sirvientes. Entonces, ¡quizás puedas atraer a uno a una emboscada!', 0);
-- 8342 Anillo de nobleza Crepuscular
-- https://es.classic.wowhead.com/quest=8342
SET @ID := 8342;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, si planeas ir tras el Alto Consejo Abisal de nuevo, necesitarás otro anillo de nobleza Crepuscular. Tráeme más fragmentos y sellos y te haré uno.', 0),
(@ID, 'esMX', '$n, si planeas ir tras el Alto Consejo Abisal de nuevo, necesitarás otro anillo de nobleza Crepuscular. Tráeme más fragmentos y sellos y te haré uno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, veo que tus convicciones son fuertes. ¡No muchos le plantarían cara a ese consejo de demonios!$B$BAquí está tu anillo, $n. Que tu voluntad y tu fortuna se mantengan firmes.', 0),
(@ID, 'esMX', 'Ah, veo que tus convicciones son fuertes. ¡No muchos le plantarían cara a ese consejo de demonios!$B$BAquí está tu anillo, $n. Que tu voluntad y tu fortuna se mantengan firmes.', 0);
-- 8343 El descubrimiento de Hojaurea
-- https://es.classic.wowhead.com/quest=8343
SET @ID := 8343;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que dice Huum es cierto. ¡Creo que sé cómo convocar a un señor del Consejo Abisal! Escucha y te explicaré...', 0),
(@ID, 'esMX', 'Lo que dice Huum es cierto. ¡Creo que sé cómo convocar a un señor del Consejo Abisal! Escucha y te explicaré...', 0);
-- 8344 Ventanas al origen
-- https://es.classic.wowhead.com/quest=8344
SET @ID := 8344;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las esencias de las ánimas me servirán como fuente de experimentación. Al igual que tu vida como $c, es importante aprender de lo que encontramos en el mundo... antes de torcerlo a nuestra voluntad. Con los demonios como la fuente de poder más rica, será una gran bendición si tal mancha está realmente presente en la isla.$B$BBueno... una bendición para nosotros los brujos, está claro.', 0),
(@ID, 'esMX', 'Las esencias de las ánimas me servirán como fuente de experimentación. Al igual que tu vida como $c, es importante aprender de lo que encontramos en el mundo... antes de torcerlo a nuestra voluntad. Con los demonios como la fuente de poder más rica, será una gran bendición si tal mancha está realmente presente en la isla.$B$BBueno... una bendición para nosotros los brujos, está claro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho! Sí, esto debería ser suficiente para comenzar con mi investigación. Tengo la fuerte sensación de que esta esencia contaminada será justamente la clave... la ventana, como mencioné.$B$BSeguir las órdenes de tus maestros es muy recomendable como joven $n. Como te prometí, aquí tienes la recompensa por obedecer instrucciones y completarlas de manera competente: el conocimiento para convocar y atar a tu propio diablillo.$B$BÚsalo bien, $n', 0),
(@ID, 'esMX', '¡Bien hecho! Sí, esto debería ser suficiente para comenzar con mi investigación. Tengo la fuerte sensación de que esta esencia contaminada será justamente la clave... la ventana, como mencioné.$B$BSeguir las órdenes de tus maestros es muy recomendable como joven $n. Como te prometí, aquí tienes la recompensa por obedecer instrucciones y completarlas de manera competente: el conocimiento para convocar y atar a tu propio diablillo.$B$BÚsalo bien, $n', 0);
-- 8346 Sed insaciable
-- https://es.classic.wowhead.com/quest=8346
SET @ID := 8346;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Torrente Arcano desatado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 8348 Sellos de los Duques
-- https://es.classic.wowhead.com/quest=8348
SET @ID := 8348;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te fue con el Duque Abisal? ¿Golpeó fuerte?', 0),
(@ID, 'esMX', '¿Cómo te fue con el Duque Abisal? ¿Golpeó fuerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que eras $gun:una; $n $gduro:dura; en el momento en que te vi entrar en Fuerte Cenarion. ¡Sigue así!', 0),
(@ID, 'esMX', 'Sabía que eras $gun:una; $n $gduro:dura; en el momento en que te vi entrar en Fuerte Cenarion. ¡Sigue así!', 0);
-- 8349 Bor Ferocrín
-- https://es.classic.wowhead.com/quest=8349
SET @ID := 8349;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué alegría volver a verte, $c! ¿Te han hecho un medallón? Bien... lo necesitarás para tu próxima misión...', 0),
(@ID, 'esMX', '¡Qué alegría volver a verte, $c! ¿Te han hecho un medallón? Bien... lo necesitarás para tu próxima misión...', 0);
-- 8351 Bor quiere hablar contigo
-- https://es.classic.wowhead.com/quest=8351
SET @ID := 8351;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, es cierto, $n. Tengo una tarea muy dura por delante...', 0),
(@ID, 'esMX', 'Sí, es cierto, $n. Tengo una tarea muy dura por delante...', 0);
-- 8352 Cetro del Consejo
-- https://es.classic.wowhead.com/quest=8352
SET @ID := 8352;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿cómo te fue? ¡Haría cualquier cosa por dejar mi puesto y luchar contra una de esas cosas yo mismo!', 0),
(@ID, 'esMX', 'Bueno, ¿cómo te fue? ¡Haría cualquier cosa por dejar mi puesto y luchar contra una de esas cosas yo mismo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tú... lo hiciste! ¡Lo hiciste, $n! ¡Aquí! Toma esto. Es el cofre más grande que teníamos y lo llené con algunas de las mejores cosas que encontramos.', 0),
(@ID, 'esMX', '¡Tú... lo hiciste! ¡Lo hiciste, $n! ¡Aquí! Toma esto. Es el cofre más grande que teníamos y lo llené con algunas de las mejores cosas que encontramos.', 0);
-- 8353 Una menta por cacarear como un pollo
-- https://es.classic.wowhead.com/quest=8353
SET @ID := 8353;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cacarea como un pollo para el tabernero Brebefuego', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué divertido! ¡Lo has hecho muy bien, $n! Aquí tienes tu regalo.$B$B¡Feliz Halloween!', 0),
(@ID, 'esMX', '¡Qué divertido! ¡Lo has hecho muy bien, $n! Aquí tienes tu regalo.$B$B¡Feliz Halloween!', 0);
-- 8354 Una menta por cacarear como un pollo
-- https://es.classic.wowhead.com/quest=8354
SET @ID := 8354;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cacarea como un pollo para el tabernero Norman', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué divertido! ¡Lo has hecho muy bien, $n! Aquí tienes tu regalo.$B$B¡Feliz Halloween!', 0),
(@ID, 'esMX', '¡Qué divertido! ¡Lo has hecho muy bien, $n! Aquí tienes tu regalo.$B$B¡Feliz Halloween!', 0);
