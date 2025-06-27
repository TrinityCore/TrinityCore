-- 3639 Muestra tu trabajo
-- https://es.classic.wowhead.com/quest=3639
SET @ID := 3639;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que me entregues los objetos de ingeniería que has creado y pueda inspeccionarlos, te daré una tarjeta de miembro del Club de Ingeniería Goblin. Mientras la tarjeta sea válida, tendrás acceso ilimitado a todos los instructores de ingeniería goblin del mundo.', 0),
(@ID, 'esMX', 'Una vez que me entregues los objetos de ingeniería que has creado y pueda inspeccionarlos, te daré una tarjeta de miembro del Club de Ingeniería Goblin. Mientras la tarjeta sea válida, tendrás acceso ilimitado a todos los instructores de ingeniería goblin del mundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí tienes tu primera tarjeta de miembro del Club de Ingeniería Goblin!$B$BEsta tarjeta tiene pagados los primeros catorce días. Todas las tarjetas expiran después de dos semanas de actividad. Cuando suceda, visita a cualquier instructor goblin de ingeniería para comprar otra. Sin la tarjeta, tu membresía caducará temporalmente y no podrás acceder a los nuevos esquemas.$B$BEsto no afecta a tus conocimientos. Un ingeniero goblin nunca olvida lo que ya sabe.', 0),
(@ID, 'esMX', '¡Aquí tienes tu primera tarjeta de miembro del Club de Ingeniería Goblin!$B$BEsta tarjeta tiene pagados los primeros catorce días. Todas las tarjetas expiran después de dos semanas de actividad. Cuando suceda, visita a cualquier instructor goblin de ingeniería para comprar otra. Sin la tarjeta, tu membresía caducará temporalmente y no podrás acceder a los nuevos esquemas.$B$BEsto no afecta a tus conocimientos. Un ingeniero goblin nunca olvida lo que ya sabe.', 0);
-- 3640 La promesa del secreto
-- https://es.classic.wowhead.com/quest=3640
SET @ID := 3640;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si me das el documento firmado, ya no hay marcha atrás.$B$BHaber firmado el compromiso de secreto perpetuo es un asunto muy serio; todos lo firmamos. ¡Bienvenido al mundo de la ingeniería gnómica, $n!', 0),
(@ID, 'esMX', 'Si me das el documento firmado, ya no hay marcha atrás.$B$BHaber firmado el compromiso de secreto perpetuo es un asunto muy serio; todos lo firmamos. ¡Bienvenido al mundo de la ingeniería gnómica, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien, $n! Pronto tendrás acceso al mejor plan de estudios avanzado de ingeniería de Azeroth.$B$BVeamos cómo se te da la ingeniería gnómica y después diseñaremos un currículo adaptado a tus habilidades.', 0),
(@ID, 'esMX', '¡Bien, $n! Pronto tendrás acceso al mejor plan de estudios avanzado de ingeniería de Azeroth.$B$BVeamos cómo se te da la ingeniería gnómica y después diseñaremos un currículo adaptado a tus habilidades.', 0);
-- Muestra tu trabajo
-- 3641, 3643
-- https://es.classic.wowhead.com/quest=3641
DELETE FROM `quest_request_items_locale` WHERE `id` IN(3641, 3643) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3641, 'esES', 'Cuando revise lo que me has traído, te daré tu tarjeta de miembro del Club de Ingeniería Gnómica. Mientras sea válida, tendrás acceso a cualquier instructor de ingeniería gnómica del mundo.', 0),
(3643, 'esES', 'Cuando revise lo que me has traído, te daré tu tarjeta de miembro del Club de Ingeniería Gnómica. Mientras sea válida, tendrás acceso a cualquier instructor de ingeniería gnómica del mundo.', 0),
(3641, 'esMX', 'Cuando revise lo que me has traído, te daré tu tarjeta de miembro del Club de Ingeniería Gnómica. Mientras sea válida, tendrás acceso a cualquier instructor de ingeniería gnómica del mundo.', 0),
(3643, 'esMX', 'Cuando revise lo que me has traído, te daré tu tarjeta de miembro del Club de Ingeniería Gnómica. Mientras sea válida, tendrás acceso a cualquier instructor de ingeniería gnómica del mundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3641, 3643) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3641, 'esES', 'Aquí tienes tu tarjeta de miembro del Club de Ingeniería Gnómica.$B$BCaduca a las 2 semanas; para renovarla, paga la cuota. Si no tienes la tarjeta, no podrás seguir estudiando hasta que la renueves.$B$BPero no olvidarás lo que hayas aprendido; la ingeniería gnómica es como ir en bicicleta.', 0),
(3643, 'esES', 'Aquí tienes tu tarjeta de miembro del Club de Ingeniería Gnómica.$B$BCaduca a las 2 semanas; para renovarla, paga la cuota. Si no tienes la tarjeta, no podrás seguir estudiando hasta que la renueves.$B$BPero no olvidarás lo que hayas aprendido; la ingeniería gnómica es como ir en bicicleta.', 0),
(3641, 'esMX', 'Aquí tienes tu tarjeta de miembro del Club de Ingeniería Gnómica.$B$BCaduca a las 2 semanas; para renovarla, paga la cuota. Si no tienes la tarjeta, no podrás seguir estudiando hasta que la renueves.$B$BPero no olvidarás lo que hayas aprendido; la ingeniería gnómica es como ir en bicicleta.', 0),
(3643, 'esMX', 'Aquí tienes tu tarjeta de miembro del Club de Ingeniería Gnómica.$B$BCaduca a las 2 semanas; para renovarla, paga la cuota. Si no tienes la tarjeta, no podrás seguir estudiando hasta que la renueves.$B$BPero no olvidarás lo que hayas aprendido; la ingeniería gnómica es como ir en bicicleta.', 0);
-- 3642 La promesa del secreto
-- https://es.classic.wowhead.com/quest=3642
SET @ID := 3642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si has firmado el documento entrégamelo y terminemos.$B$BSi bien puedo estar vehementemente en desacuerdo con Gnomeregan, especialmente con ese tonto Maestro manitas Sobrechispa, políticamente, ¡la promesa de secreto trasciende todo lo demás! Debes aceptar comprometerte con un solo camino y mantenerte fiel a ese camino a lo largo de tu vida.', 0),
(@ID, 'esMX', 'Si has firmado el documento entrégamelo y terminemos.$B$BSi bien puedo estar vehementemente en desacuerdo con Gnomeregan, especialmente con ese tonto Maestro manitas Sobrechispa, políticamente, ¡la promesa de secreto trasciende todo lo demás! Debes aceptar comprometerte con un solo camino y mantenerte fiel a ese camino a lo largo de tu vida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bienvenido a bordo, $n! Pronto tendrás acceso a los esquemas de ingeniería más avanzados de Azeroth.$B$BAhora que te has comprometido con la búsqueda de este conocimiento, es hora de examinar tu trabajo de ingeniería. A partir de aquí, te ayudaremos a crear un plan para maximizar tus talentos de Ingeniería Gnómica.', 0),
(@ID, 'esMX', '¡Bienvenido a bordo, $n! Pronto tendrás acceso a los esquemas de ingeniería más avanzados de Azeroth.$B$BAhora que te has comprometido con la búsqueda de este conocimiento, es hora de examinar tu trabajo de ingeniería. A partir de aquí, te ayudaremos a crear un plan para maximizar tus talentos de Ingeniería Gnómica.', 0);
-- Renovación de la tarjeta de miembro
-- 3644, 3646
-- https://es.classic.wowhead.com/quest=3644
DELETE FROM `quest_request_items_locale` WHERE `id` IN(3644, 3646) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3644, 'esES', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0),
(3646, 'esES', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0),
(3644, 'esMX', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0),
(3646, 'esMX', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3644, 3646) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3644, 'esES', 'En vista de que eres $gun:una; profesional de la ingeniería goblin con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería goblin de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0),
(3646, 'esES', 'En vista de que eres $gun:una; profesional de la ingeniería goblin con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería goblin de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0),
(3644, 'esMX', 'En vista de que eres $gun:una; profesional de la ingeniería goblin con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería goblin de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0),
(3646, 'esMX', 'En vista de que eres $gun:una; profesional de la ingeniería goblin con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería goblin de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0);
-- Renovación de la tarjeta de miembro
-- 3645, 3647
-- https://es.classic.wowhead.com/quest=3645
DELETE FROM `quest_request_items_locale` WHERE `id` IN(3645, 3647) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(3645, 'esES', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0),
(3647, 'esES', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0),
(3645, 'esMX', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0),
(3647, 'esMX', 'Para renovar tu tarjeta de miembro tendrás que pagar las cuotas de renovación, que son dos piezas de oro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3645, 3647) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3645, 'esES', 'En vista de que eres $gun:una; profesional de la ingeniería Gnómica con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería gnómica de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0),
(3647, 'esES', 'En vista de que eres $gun:una; profesional de la ingeniería Gnómica con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería gnómica de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0),
(3645, 'esMX', 'En vista de que eres $gun:una; profesional de la ingeniería Gnómica con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería gnómica de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0),
(3647, 'esMX', 'En vista de que eres $gun:una; profesional de la ingeniería Gnómica con buena reputación, te voy a renovar tu tarjeta caducada por una cuota de dos piezas de oro. Cuando hayas pagado esta cuota, recibirás una nueva tarjeta de miembro con la que podrás recibir nuevos esquemas de ingeniería gnómica de los instructores apropiados.$B$BEsta tarjeta tiene una validez de dos semanas de actividad, período tras el cual tendrás que pagar la cuota de nuevo. Si quieres tener acceso a los esquemas, tendrás que saldar tus deudas antes.', 0);
-- 3701 Las humeantes Ruinas de Thaurissan
-- https://es.classic.wowhead.com/quest=3701
SET @ID := 3701;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Has recuperado la información', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 3721 Tu propio OOX
-- https://es.classic.wowhead.com/quest=3721
SET @ID := 3721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has recuperado tres de mis robots mensajeros OOX! Has hecho mucho más de lo que tenías que hacer, así que te daré algo especial por toda tu ayuda. Es una versión miniatura del robot que tan bien conoces, ¡el OOX!$B$BNormalmente, no dejaría que nadie tuviese un dispositivo tan potencialmente letal, pero tú has sido de gran ayuda. Además, el mecanismo de combate y las funciones de búsqueda de este robot están desactivados.$B$BPor todo lo demás, ¡es un OOX auténtico!', 0),
(@ID, 'esMX', '¡Has recuperado tres de mis robots mensajeros OOX! Has hecho mucho más de lo que tenías que hacer, así que te daré algo especial por toda tu ayuda. Es una versión miniatura del robot que tan bien conoces, ¡el OOX!$B$BNormalmente, no dejaría que nadie tuviese un dispositivo tan potencialmente letal, pero tú has sido de gran ayuda. Además, el mecanismo de combate y las funciones de búsqueda de este robot están desactivados.$B$BPor todo lo demás, ¡es un OOX auténtico!', 0);
-- 3761 Tierra de Un'Goro
-- https://es.classic.wowhead.com/quest=3761
SET @ID := 3761;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Descanse, soldado! Si vienes a traer tierra de Un\'Goro, estupendo. De lo contrario, márchate inmediatamente.', 0),
(@ID, 'esMX', '¡Descanse, soldado! Si vienes a traer tierra de Un\'Goro, estupendo. De lo contrario, márchate inmediatamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, soldado $n. ¡Quédate ahí mirando y no me ayudes a descargar la tierra! Si los Grandes Espíritus hubieran querido descargarla por arte de magia, ya lo habrían hecho, ¿no crees?$B$BEl archidruida Tótem de Runa quiere hablar contigo de nuevo pero para su siguiente tarea debes saber que le resultaría útil contar con un oficial herborista. Si no te ajustas al perfil, no te preocupes. Seguro que habrá algo en lo que le puedas ser de utilidad.', 0),
(@ID, 'esMX', 'Muy bien, soldado $n. ¡Quédate ahí mirando y no me ayudes a descargar la tierra! Si los Grandes Espíritus hubieran querido descargarla por arte de magia, ya lo habrían hecho, ¿no crees?$B$BEl archidruida Tótem de Runa quiere hablar contigo de nuevo pero para su siguiente tarea debes saber que le resultaría útil contar con un oficial herborista. Si no te ajustas al perfil, no te preocupes. Seguro que habrá algo en lo que le puedas ser de utilidad.', 0);
-- 3762 Ayuda al archidruida Tótem de Runa
-- https://es.classic.wowhead.com/quest=3762
SET @ID := 3762;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c; Me alegra que estés $ginteresado:interesada; en ayudar en nuestra investigación. Queda mucho por hacer, y te haría un flaco favor si no te informara que el trabajo que esto conlleva es peligroso. Con suerte, esto no te asustará... pero por tu apariencia, supongo que el peligro es algo con lo que has lidiado antes.', 0),
(@ID, 'esMX', 'Saludos, $c; Me alegra que estés $ginteresado:interesada; en ayudar en nuestra investigación. Queda mucho por hacer, y te haría un flaco favor si no te informara que el trabajo que esto conlleva es peligroso. Con suerte, esto no te asustará... pero por tu apariencia, supongo que el peligro es algo con lo que has lidiado antes.', 0);
-- Ayuda al archidruida Corzocelada
-- 3763, 3789, 3790, 10520
-- https://es.classic.wowhead.com/quest=3763
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3763, 3789, 3790, 10520) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3763, 'esES', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0),
(3789, 'esES', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0),
(3790, 'esES', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0),
(10520, 'esES', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0),
(3763, 'esMX', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0),
(3789, 'esMX', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0),
(3790, 'esMX', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0),
(10520, 'esMX', 'Bien, $c, veo que fuiste $ginformado:informada; de que yo encabezaba la investigación en persona, y es evidente que viniste tan rápido como pudiste.$B$BAhora que estás aquí, presta atención, pues te daré los detalles una sola vez, no me gusta repetirme.', 0);
-- 3765 Lejana corrupción
-- https://es.classic.wowhead.com/quest=3765
SET @ID := 3765;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te ha enviado aquí mi hermano Argos, ¿eh? Supongo que debes de estar $gagotado:agotada; de tanto viaje. Pero tenemos mucho que hablar.', 0),
(@ID, 'esMX', 'Así que te ha enviado aquí mi hermano Argos, ¿eh? Supongo que debes de estar $gagotado:agotada; de tanto viaje. Pero tenemos mucho que hablar.', 0);
-- 3782 Investigar la mañagrana
-- https://es.classic.wowhead.com/quest=3782
SET @ID := 3782;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La paz sea contigo, $gamigo:amiga;. Vienes aquí por comisión del archidruida en persona, ¿verdad?', 0),
(@ID, 'esMX', 'La paz sea contigo, $gamigo:amiga;. Vienes aquí por comisión del archidruida en persona, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por este vale puedo darte veinte paquetes de semillas. Si te quedas sin ellas, siempre puedes comprarme más.$B$BPor desgracia, $n, resulta muy costoso cultivar semillas de Tharlendris en grandes cantidades. Por eso el Círculo Cenarion pide a quienes nos están ayudando que participen asumiendo parte de su coste. Aquellos que traigan mañagrana recibirán una recompensa del archidruida que compensará con creces los gastos.', 0),
(@ID, 'esMX', 'Por este vale puedo darte veinte paquetes de semillas. Si te quedas sin ellas, siempre puedes comprarme más.$B$BPor desgracia, $n, resulta muy costoso cultivar semillas de Tharlendris en grandes cantidades. Por eso el Círculo Cenarion pide a quienes nos están ayudando que participen asumiendo parte de su coste. Aquellos que traigan mañagrana recibirán una recompensa del archidruida que compensará con creces los gastos.', 0);
-- 3784 Ayuda al archidruida Tótem de Runa
-- https://es.classic.wowhead.com/quest=3784
SET @ID := 3784;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $C; Me alegra que esté interesado en ayudar en nuestra investigación. Queda mucho por hacer, y les haría un flaco favor si les informara que el trabajo que esto conlleva no es peligroso. Con suerte, esto no te asustará ... pero por tu apariencia, supongo que el peligro es algo con lo que has lidiado antes.', 0),
(@ID, 'esMX', 'Saludos, $C; Me alegra que esté interesado en ayudar en nuestra investigación. Queda mucho por hacer, y les haría un flaco favor si les informara que el trabajo que esto conlleva no es peligroso. Con suerte, esto no te asustará ... pero por tu apariencia, supongo que el peligro es algo con lo que has lidiado antes.', 0);
-- 3786 Investigar la mañagrana
-- https://es.classic.wowhead.com/quest=3786
SET @ID := 3786;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Has cultivado algo de mañagrana para la importante investigación del archidruida? El trabajo que está haciendo para el Círculo Cenarion es muy importante. ¡Tu ayuda no pasará desapercibida!', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Has cultivado algo de mañagrana para la importante investigación del archidruida? El trabajo que está haciendo para el Círculo Cenarion es muy importante. ¡Tu ayuda no pasará desapercibida!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Me aseguraré de dárselas al archidruida cuando las necesite. Mientras tanto, acepta esto como muestra del aprecio del Círculo Cenarion.$B$BNecesitamos mañagrana continuamente. Si quieres seguir ayudándonos, vuelve a mí cuando hayas cultivado más mañagrana.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Me aseguraré de dárselas al archidruida cuando las necesite. Mientras tanto, acepta esto como muestra del aprecio del Círculo Cenarion.$B$BNecesitamos mañagrana continuamente. Si quieres seguir ayudándonos, vuelve a mí cuando hayas cultivado más mañagrana.', 0);
-- La petición de Jonguja
-- 3787, 3788
-- https://es.classic.wowhead.com/quest=3787
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(3787, 3788) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(3787, 'esES', '¡Gracias por venir, $gviajero:viajera;! Permite que me presente: soy Quintis Jonguja, druida y humilde servidor de Malfurión y del Círculo Cenarion. Mis colegas (el general Shandris Plumaluna y el Protectorado, igual has oído hablar de nosotros) y yo, queríamos hablar contigo sobre el trabajo que estás haciendo para Fandral Corzocelada en Darnassus.$B$BAntes de proseguir, quisiera pedirte que esta conversación quede entre nosotros. Si esto no te supone un problema, podemos continuar.', 0),
(3788, 'esES', '¡Gracias por venir, $gviajero:viajera;! Permite que me presente: soy Quintis Jonguja, druida y humilde servidor de Malfurión y del Círculo Cenarion. Mis colegas (el general Shandris Plumaluna y el Protectorado, igual has oído hablar de nosotros) y yo, queríamos hablar contigo sobre el trabajo que estás haciendo para Fandral Corzocelada en Darnassus.$B$BAntes de proseguir, quisiera pedirte que esta conversación quede entre nosotros. Si esto no te supone un problema, podemos continuar.', 0),
(3787, 'esMX', '¡Gracias por venir, $gviajero:viajera;! Permite que me presente: soy Quintis Jonguja, druida y humilde servidor de Malfurión y del Círculo Cenarion. Mis colegas (el general Shandris Plumaluna y el Protectorado, igual has oído hablar de nosotros) y yo, queríamos hablar contigo sobre el trabajo que estás haciendo para Fandral Corzocelada en Darnassus.$B$BAntes de proseguir, quisiera pedirte que esta conversación quede entre nosotros. Si esto no te supone un problema, podemos continuar.', 0),
(3788, 'esMX', '¡Gracias por venir, $gviajero:viajera;! Permite que me presente: soy Quintis Jonguja, druida y humilde servidor de Malfurión y del Círculo Cenarion. Mis colegas (el general Shandris Plumaluna y el Protectorado, igual has oído hablar de nosotros) y yo, queríamos hablar contigo sobre el trabajo que estás haciendo para Fandral Corzocelada en Darnassus.$B$BAntes de proseguir, quisiera pedirte que esta conversación quede entre nosotros. Si esto no te supone un problema, podemos continuar.', 0);
-- 3791 El misterio de mañagrana
-- https://es.classic.wowhead.com/quest=3791
SET @ID := 3791;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy buscando diez mañagranas, eso debería ser suficiente para al menos comenzar mi investigación. Sin duda quemaré a muchos de los que van por caminos equivocados, pero esa es la naturaleza de la investigación.', 0),
(@ID, 'esMX', 'Estoy buscando diez mañagranas, eso debería ser suficiente para al menos comenzar mi investigación. Sin duda quemaré a muchos de los que van por caminos equivocados, pero esa es la naturaleza de la investigación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gah, estos granos de mañagrana me hacen sentir... raro. En nombre de Elune, ¿qué está haciendo Staghelm con estas cosas?$B$BDe todos modos, gracias de nuevo por tu ayuda. Aquí hay algo... ya sabes, por el esfuerzo. Mi investigación sobre la mañagrana va a llevar un tiempo y sin duda voy a necesitar más. Mientras estoy en eso, supongo que podría tomarme el tiempo para ver si el grano de mañagrana tiene algunos usos alquímicos pertinentes. Aún así, me siento incómodo incluso estando cerca de ellos.', 0),
(@ID, 'esMX', 'Gah, estos granos de mañagrana me hacen sentir... raro. En nombre de Elune, ¿qué está haciendo Staghelm con estas cosas?$B$BDe todos modos, gracias de nuevo por tu ayuda. Aquí hay algo... ya sabes, por el esfuerzo. Mi investigación sobre la mañagrana va a llevar un tiempo y sin duda voy a necesitar más. Mientras estoy en eso, supongo que podría tomarme el tiempo para ver si el grano de mañagrana tiene algunos usos alquímicos pertinentes. Aún así, me siento incómodo incluso estando cerca de ellos.', 0);
-- 3792 Mañagrana a Bastión Plumaluna
-- https://es.classic.wowhead.com/quest=3792
SET @ID := 3792;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo, $n. Mi investigación avanza bastante bien, pero si tienes cinco Mañagranas más, estaré feliz de quitártelos de las manos. Bueno... feliz es un término figurado; cuanto más estoy cerca de ellos, más incómodo me siento. Aún así, mi investigación exige que supere esto.', 0),
(@ID, 'esMX', 'Hola de nuevo, $n. Mi investigación avanza bastante bien, pero si tienes cinco Mañagranas más, estaré feliz de quitártelos de las manos. Bueno... feliz es un término figurado; cuanto más estoy cerca de ellos, más incómodo me siento. Aún así, mi investigación exige que supere esto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias $n; Solo los guardaré fuera de circulación por el momento. Aunque no dispongo de los recursos que tiene Staghelm, puedo darte algo por las molestias. De todos modos, quién sabe qué pasará si Staghelm sigue obteniendo Mañagrana sin parar. Algo sospechoso está sucediendo, recuerda mis palabras.$B$BRecuerda que siempre estoy buscando más Mañagrana. Tráelas de cinco en cinco.', 0),
(@ID, 'esMX', 'Gracias $n; Solo los guardaré fuera de circulación por el momento. Aunque no dispongo de los recursos que tiene Staghelm, puedo darte algo por las molestias. De todos modos, quién sabe qué pasará si Staghelm sigue obteniendo Mañagrana sin parar. Algo sospechoso está sucediendo, recuerda mis palabras.$B$BRecuerda que siempre estoy buscando más Mañagrana. Tráelas de cinco en cinco.', 0);
-- 3801 El legado de los Hierro Negro
-- https://es.classic.wowhead.com/quest=3801
SET @ID := 3801;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya sea la codicia lo que te trajo aquí o un acto de entrega altruista, lo que estás a punto de acometer es bueno para todos.', 0),
(@ID, 'esMX', 'Ya sea la codicia lo que te trajo aquí o un acto de entrega altruista, lo que estás a punto de acometer es bueno para todos.', 0);
-- 3802 El legado de los Hierro Negro
-- https://es.classic.wowhead.com/quest=3802
SET @ID := 3802;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La estatua se cierne inquietante sobre ti.', 0),
(@ID, 'esMX', 'La estatua se cierne inquietante sobre ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El martillo se desliza firmemente en su lugar, en el puño del colosal monumento Hierro Negro. Un minúsculo compartimento se abre en la base de la estatua. En el interior encuentras...', 0),
(@ID, 'esMX', 'El martillo se desliza firmemente en su lugar, en el puño del colosal monumento Hierro Negro. Un minúsculo compartimento se abre en la base de la estatua. En el interior encuentras...', 0);
-- 3803 Mañagrana para Darnassus
-- https://es.classic.wowhead.com/quest=3803
SET @ID := 3803;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Archidruida siempre está buscando más Mañagrana para la investigación continua del Círculo Cenarion. Los tomamos de grupos de diez y te otorgamos un alijo de bienes que puedes encontrar útiles. Cuando tengas diez, avísame y te recompensaré en consecuencia.', 0),
(@ID, 'esMX', 'El Archidruida siempre está buscando más Mañagrana para la investigación continua del Círculo Cenarion. Los tomamos de grupos de diez y te otorgamos un alijo de bienes que puedes encontrar útiles. Cuando tengas diez, avísame y te recompensaré en consecuencia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, esta Mañagrana sin duda complacerá al Archidruida. Sin embargo, debo admitir que... estar cerca de ella me hace sentir un poco incómodo. ¡Solo puedo imaginar lo difícil que es para el Archidruida tolerarlos en cantidades tan grandes!$B$BEsto es para ti, $n. El Círculo Cenarion te agradece tu continuo apoyo.', 0),
(@ID, 'esMX', 'Excelente, esta Mañagrana sin duda complacerá al Archidruida. Sin embargo, debo admitir que... estar cerca de ella me hace sentir un poco incómodo. ¡Solo puedo imaginar lo difícil que es para el Archidruida tolerarlos en cantidades tan grandes!$B$BEsto es para ti, $n. El Círculo Cenarion te agradece tu continuo apoyo.', 0);
-- 3804 Mañagrana para Cima del Trueno
-- https://es.classic.wowhead.com/quest=3804
SET @ID := 3804;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El archidruida siempre está buscando mañagrana para el proyecto de investigación sobre el Cráter de Un’Goro que lleva a cabo el Círculo Cenarion. La recogemos en lotes de 10 y recompensamos a quien la trae con un conjunto de objetos muy útiles. Si reúnes 10 plantas de mañagrana, tráemelas y te daré tu recompensa.', 0),
(@ID, 'esMX', 'El archidruida siempre está buscando mañagrana para el proyecto de investigación sobre el Cráter de Un’Goro que lleva a cabo el Círculo Cenarion. La recogemos en lotes de 10 y recompensamos a quien la trae con un conjunto de objetos muy útiles. Si reúnes 10 plantas de mañagrana, tráemelas y te daré tu recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, llegado el momento esta mañagrana sin duda será de utilidad. Sabemos que los elfos de la noche también están estudiando estas plantas, aunque desconocemos con qué propósito las usarán si llegan a descubrir algo. El archidruida cree que seguiremos necesitando mañagrana hasta que descubramos los misterios que encierra esta planta.$B$BEsto es para ti, $n. El Círculo Cenarion te agradece tu constante apoyo.', 0),
(@ID, 'esMX', 'Excelente, llegado el momento esta mañagrana sin duda será de utilidad. Sabemos que los elfos de la noche también están estudiando estas plantas, aunque desconocemos con qué propósito las usarán si llegan a descubrir algo. El archidruida cree que seguiremos necesitando mañagrana hasta que descubramos los misterios que encierra esta planta.$B$BEsto es para ti, $n. El Círculo Cenarion te agradece tu constante apoyo.', 0);
-- 3821 Roca Machacamiedo
-- https://es.classic.wowhead.com/quest=3821
SET @ID := 3821;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pobre Thal\'trak.$B$BHabíamos planeado mudarnos a vivir juntos con mi madre y mi padre en las Tierras del Interior al acabar nuestra gira. ¡Ahora todo se ha venido abajo!', 0),
(@ID, 'esMX', 'Pobre Thal\'trak.$B$BHabíamos planeado mudarnos a vivir juntos con mi madre y mi padre en las Tierras del Interior al acabar nuestra gira. ¡Ahora todo se ha venido abajo!', 0);
-- 3822 Krom'Grul
-- https://es.classic.wowhead.com/quest=3822
SET @ID := 3822;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado a Sha’ni? ¿Está bien?', 0),
(@ID, 'esMX', '¿Has encontrado a Sha’ni? ¿Está bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thal\'trak se derrumba.>$B$BÍbamos a mudarnos a las Tierras del Interior. ¿Te lo dijo? Esta iba a ser su última misión...$B$B<Thal\'trak solloza.>$B$BNo la quiero, $n. Quédatela, deshazte de ella, ¡no me importa! La sortija ahora ya no significa nada para mí. No sin ella...', 0),
(@ID, 'esMX', '<Thal\'trak se derrumba.>$B$BÍbamos a mudarnos a las Tierras del Interior. ¿Te lo dijo? Esta iba a ser su última misión...$B$B<Thal\'trak solloza.>$B$BNo la quiero, $n. Quédatela, deshazte de ella, ¡no me importa! La sortija ahora ya no significa nada para mí. No sin ella...', 0);
-- 3823 El exterminio de los Pirontraña
-- https://es.classic.wowhead.com/quest=3823
SET @ID := 3823;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No hay suficiente sangre en su uniforme, soldado!', 0),
(@ID, 'esMX', '¡No hay suficiente sangre en su uniforme, soldado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, soldado! Los orcos y los ogros se tambalearán unos minutos tras este ataque, ¡a lo mejor hasta horas!', 0),
(@ID, 'esMX', '¡Fantástico, soldado! Los orcos y los ogros se tambalearán unos minutos tras este ataque, ¡a lo mejor hasta horas!', 0);
-- 3824 Gor'tesh, el Señor de los toscos
-- https://es.classic.wowhead.com/quest=3824
SET @ID := 3824;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, día de gloria! ¿Vuelves con la cabeza que te pedí?', 0),
(@ID, 'esMX', '¡Oh, día de gloria! ¿Vuelves con la cabeza que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fíjate en esto, soldado! ¡Asqueroso! Cuando los ogros Ardentrañas vean esta gran jarra clavada en una estaca en la cumbre de su montaña, ¡se desatará la histeria colectiva!$B$B<Oralius rompe en una carcajada desenfrenada.>', 0),
(@ID, 'esMX', '¡Fíjate en esto, soldado! ¡Asqueroso! Cuando los ogros Ardentrañas vean esta gran jarra clavada en una estaca en la cumbre de su montaña, ¡se desatará la histeria colectiva!$B$B<Oralius rompe en una carcajada desenfrenada.>', 0);
-- 3825 Una cabeza ogro empalada = FIESTA
-- https://es.classic.wowhead.com/quest=3825
SET @ID := 3825;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cabeza de Gor\'tesh plantada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces? ¿Pintaste algún cuadro del evento?', 0),
(@ID, 'esMX', '¿Entonces? ¿Pintaste algún cuadro del evento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente trabajo, soldado! ¡Simplemente asombroso! Oh, obtendré la medalla de la valentía por esto, eh, ¡quiero decir que serás $grecompensado:recompensada; generosamente por esto!', 0),
(@ID, 'esMX', '¡Excelente trabajo, soldado! ¡Simplemente asombroso! Oh, obtendré la medalla de la valentía por esto, eh, ¡quiero decir que serás $grecompensado:recompensada; generosamente por esto!', 0);
-- 3841 Un huérfano que busca un hogar
-- https://es.classic.wowhead.com/quest=3841
SET @ID := 3841;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, hola, $c.$B$BNo te dejes engañar, no estoy aquí por las carreras, por muy interesantes que puedan resultar.$B$BEstoy en Las Mil Agujas estudiando la tierra para ver si se puede salvar. He convertido en mi cruzada personal revitalizar esta zona con nueva tierra, tierra fértil. Quizás descubra que hay una fuente de agua cerca.$B$BPorque no me digas que no has notado lo extraña que es la transición de Feralas a Las Mil Agujas. Hay una magia extraña detrás de esto...', 0),
(@ID, 'esMX', 'Vaya, hola, $c.$B$BNo te dejes engañar, no estoy aquí por las carreras, por muy interesantes que puedan resultar.$B$BEstoy en Las Mil Agujas estudiando la tierra para ver si se puede salvar. He convertido en mi cruzada personal revitalizar esta zona con nueva tierra, tierra fértil. Quizás descubra que hay una fuente de agua cerca.$B$BPorque no me digas que no has notado lo extraña que es la transición de Feralas a Las Mil Agujas. Hay una magia extraña detrás de esto...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un huevo de duende dardo. Y uno que está casi a punto de eclosionar, si no me equivoco. Es asombroso que hayas encontrado un espécimen, sobre todo uno en tan buenas condiciones. Se ven pocos en Feralas en estos tiempos. Entiendo que había varios cazadores furtivos por la zona, intentando capturarlos y matarlos por varios motivos. Es una pena... son unas criaturas muy hermosas cuando llegan a la madurez.$B$BY dime, ¿cómo ha llegado a tus manos semejante joya?', 0),
(@ID, 'esMX', 'Ah, un huevo de duende dardo. Y uno que está casi a punto de eclosionar, si no me equivoco. Es asombroso que hayas encontrado un espécimen, sobre todo uno en tan buenas condiciones. Se ven pocos en Feralas en estos tiempos. Entiendo que había varios cazadores furtivos por la zona, intentando capturarlos y matarlos por varios motivos. Es una pena... son unas criaturas muy hermosas cuando llegan a la madurez.$B$BY dime, ¿cómo ha llegado a tus manos semejante joya?', 0);
-- 3842 Una corta incubación
-- https://es.classic.wowhead.com/quest=3842
SET @ID := 3842;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuanto más tiempo me quedo aquí, más tentado estoy de participar en estas carreras, $n. Verdaderamente asombroso...$B$B¿Ya encontraste los elixires? Una vez que sepa si el huevo va a estar sano o no, te lo devolveré para que lo guardes hasta que esté preparado para eclosionar.$B$BHázmelo saber.', 0),
(@ID, 'esMX', 'Cuanto más tiempo me quedo aquí, más tentado estoy de participar en estas carreras, $n. Verdaderamente asombroso...$B$B¿Ya encontraste los elixires? Una vez que sepa si el huevo va a estar sano o no, te lo devolveré para que lo guardes hasta que esté preparado para eclosionar.$B$BHázmelo saber.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maravilloso. Esto funcionará muy bien. Dame un momento para mezclar mis componentes y veremos qué tan bien va a estar este huevo.', 0),
(@ID, 'esMX', 'Maravilloso. Esto funcionará muy bien. Dame un momento para mezclar mis componentes y veremos qué tan bien va a estar este huevo.', 0);
-- 3843 Un nuevo miembro en la familia
-- https://es.classic.wowhead.com/quest=3843
SET @ID := 3843;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. ¿Cómo puedo servirte?', 0),
(@ID, 'esMX', 'Saludos, $n. ¿Cómo puedo servirte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, bueno, bueno ... No he visto uno de estos dragones en años. Dragón de las hadas, si no me equivoco... parece ser de la variedad de duende dardo. Excelente, excelente en verdad.$B$BBueno, si este pequeño va a nacer y vivir para ser fuerte y saludable, entonces deberíamos conseguir algo de comida. Bien, tráela a tiempo.', 0),
(@ID, 'esMX', 'Bueno, bueno, bueno ... No he visto uno de estos dragones en años. Dragón de las hadas, si no me equivoco... parece ser de la variedad de duende dardo. Excelente, excelente en verdad.$B$BBueno, si este pequeño va a nacer y vivir para ser fuerte y saludable, entonces deberíamos conseguir algo de comida. Bien, tráela a tiempo.', 0);
-- 3901 Sacudir esqueletos
-- https://es.classic.wowhead.com/quest=3901
SET @ID := 3901;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquellos que se entretienen en esta tarea bien podrían terminar vagando sin rumbo fijo como nuestros hermanos y hermanas caídos en el pueblo. Esperemos que te vaya mejor que a ellos, ¿no?', 0),
(@ID, 'esMX', 'Aquellos que se entretienen en esta tarea bien podrían terminar vagando sin rumbo fijo como nuestros hermanos y hermanas caídos en el pueblo. Esperemos que te vaya mejor que a ellos, ¿no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He acabado contigo, $n. Has demostrado ser $gmerecedor:merecedora; de la libertad que te ha sido concedida. Muchos serán los que se alzarán contra ti por lo que eres ahora, pero debes saber que, intenten lo que intenten contra nosotros, somos libres y no volverán a encadenarnos.$B$BCoge esto y ponte en camino. Tienes mucho que lograr, $c.', 0),
(@ID, 'esMX', 'He acabado contigo, $n. Has demostrado ser $gmerecedor:merecedora; de la libertad que te ha sido concedida. Muchos serán los que se alzarán contra ti por lo que eres ahora, pero debes saber que, intenten lo que intenten contra nosotros, somos libres y no volverán a encadenarnos.$B$BCoge esto y ponte en camino. Tienes mucho que lograr, $c.', 0);
