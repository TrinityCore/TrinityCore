-- Ayudar al Consorcio
-- 10263, 10264
-- https://es.wowhead.com/quest=10263
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10263, 10264) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10263, 'esES', 'Hola, $r.$B$B¿Estás disponible para una misión de recuperación de cierta importancia?', 0),
(10264, 'esES', 'Hola, $r.$B$B¿Estás disponible para una misión de recuperación de cierta importancia?', 0),
(10263, 'esMX', 'Hola, $r.$B$B¿Estás disponible para una misión de recuperación de cierta importancia?', 0),
(10264, 'esMX', 'Hola, $r.$B$B¿Estás disponible para una misión de recuperación de cierta importancia?', 0);
-- 10265 Colección de cristales de El Consorcio
-- https://es.wowhead.com/quest=10265
SET @ID := 10265;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo la impresión de que el príncipe busca un cristal especial pero no estoy seguro de lo que es.$B$B¿Has recuperado el del Señor del Terror?', 0),
(@ID, 'esMX', 'Tengo la impresión de que el príncipe busca un cristal especial pero no estoy seguro de lo que es.$B$B¿Has recuperado el del Señor del Terror?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame echar un vistazo.$B$BNo parece tener nada especial. No es seguro que esto sea lo que buscan, pero por lo que cuentas de las actividades de la Legión Ardiente en las ruinas, se diría que también están buscando algo concreto.$B$BEsperemos que no sea el cristal que tan desesperadamente quiere el príncipe-nexo.', 0),
(@ID, 'esMX', 'Déjame echar un vistazo.$B$BNo parece tener nada especial. No es seguro que esto sea lo que buscan, pero por lo que cuentas de las actividades de la Legión Ardiente en las ruinas, se diría que también están buscando algo concreto.$B$BEsperemos que no sea el cristal que tan desesperadamente quiere el príncipe-nexo.', 0);
-- 10266 Petición de ayuda
-- https://es.wowhead.com/quest=10266
SET @ID := 10266;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así es; los elfos de sangre han vuelto a negarse a pagar por una mercancía ya entregada.$B$BYa que el Acechador abisal Khay\'ji responde por ti, espero que puedas ayudarme con este asunto.', 0),
(@ID, 'esMX', 'Así es; los elfos de sangre han vuelto a negarse a pagar por una mercancía ya entregada.$B$BYa que el Acechador abisal Khay\'ji responde por ti, espero que puedas ayudarme con este asunto.', 0);
-- 10267 Legítima recuperación
-- https://es.wowhead.com/quest=10267
SET @ID := 10267;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste el equipo de análisis que los elfos de sangre rechazaron pagar?', 0),
(@ID, 'esMX', '¿Conseguiste el equipo de análisis que los elfos de sangre rechazaron pagar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, me alegro de que se haya solucionado este asunto tan desagradable. No creo que el Consorcio tenga clientes más groseros y poco de fiar que estos seres.$B$BEn cambio, tú sí pareces de fiar, $n. ¿Podrías hacerme otro favor?', 0),
(@ID, 'esMX', 'Bueno, me alegro de que se haya solucionado este asunto tan desagradable. No creo que el Consorcio tenga clientes más groseros y poco de fiar que estos seres.$B$BEn cambio, tú sí pareces de fiar, $n. ¿Podrías hacerme otro favor?', 0);
-- 10268 Una audiencia con el príncipe
-- https://es.wowhead.com/quest=10268
SET @ID := 10268;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acércate.', 0),
(@ID, 'esMX', 'Acércate.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a La Flecha de la Tormenta, $c. Disfruta de la hospitalidad del Consorcio.$B$BDeja el equipamiento donde quieras; tengo la impresión de que tendrás que recogerlo antes de lo que imaginas.', 0),
(@ID, 'esMX', 'Te doy la bienvenida a La Flecha de la Tormenta, $c. Disfruta de la hospitalidad del Consorcio.$B$BDeja el equipamiento donde quieras; tengo la impresión de que tendrás que recogerlo antes de lo que imaginas.', 0);
-- 10269 Punto de triangulación uno
-- https://es.wowhead.com/quest=10269
SET @ID := 10269;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gviajero:viajera;. ¿Vienes a verme porque necesitas alguno de mis productos?', 0),
(@ID, 'esMX', 'Hola, $gviajero:viajera;. ¿Vienes a verme porque necesitas alguno de mis productos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Tratante Hazzin baja la voz.>$B$BSí, conozco tu misión. ¡Es de suma importancia para el Príncipe del Nexo Haramad!$B$BAhora que tenemos la ubicación del primer punto de triangulación, debes apresurarte para localizar el segundo punto.', 0),
(@ID, 'esMX', '<El Tratante Hazzin baja la voz.>$B$BSí, conozco tu misión. ¡Es de suma importancia para el Príncipe del Nexo Haramad!$B$BAhora que tenemos la ubicación del primer punto de triangulación, debes apresurarte para localizar el segundo punto.', 0);
-- 10270 Proposición poco decente
-- https://es.wowhead.com/quest=10270
SET @ID := 10270;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás $gpreparado:preparada; para hablar de negocios, $n?', 0),
(@ID, 'esMX', '¿Estás $gpreparado:preparada; para hablar de negocios, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta célula de energía servirá. Cuando empecemos a ganar dinero, la mejoraremos aún más.$B$BBasta de charla; cada minuto perdido es dinero perdido.', 0),
(@ID, 'esMX', 'Esta célula de energía servirá. Cuando empecemos a ganar dinero, la mejoraremos aún más.$B$BBasta de charla; cada minuto perdido es dinero perdido.', 0);
-- 10271 A trabajar
-- https://es.wowhead.com/quest=10271
SET @ID := 10271;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy seguro de que tienes muchas preguntas, todas serán respondidas a su debido tiempo.', 0),
(@ID, 'esMX', 'Estoy seguro de que tienes muchas preguntas, todas serán respondidas a su debido tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y pensar que ese miserable etéreo iba a venderles estas esencias a los elfos de sangre como si fueran caramelos...', 0),
(@ID, 'esMX', 'Y pensar que ese miserable etéreo iba a venderles estas esencias a los elfos de sangre como si fueran caramelos...', 0);
-- 10272 Un buen comienzo
-- https://es.wowhead.com/quest=10272
SET @ID := 10272;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los huevos?', 0),
(@ID, 'esMX', '¿Traes los huevos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son perfectos, $n. Gracias por tu ayuda.$B$BSin embargo, hay otro asunto del que tenemos que ocuparnos antes de proseguir.', 0),
(@ID, 'esMX', 'Son perfectos, $n. Gracias por tu ayuda.$B$BSin embargo, hay otro asunto del que tenemos que ocuparnos antes de proseguir.', 0);
-- 10273 Problemas a la vista
-- https://es.wowhead.com/quest=10273
SET @ID := 10273;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este Marid es un tonto, o mejor dicho, fue un tonto.', 0),
(@ID, 'esMX', 'Este Marid es un tonto, o mejor dicho, fue un tonto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que nos hemos librado de ese etéreo, podemos concentrarnos en los dracos abisales. He estudiado los huevos y he descubierto algunas cosas.', 0),
(@ID, 'esMX', 'Ahora que nos hemos librado de ese etéreo, podemos concentrarnos en los dracos abisales. He estudiado los huevos y he descubierto algunas cosas.', 0);
-- 10274 Proteger la Cresta Celestial
-- https://es.wowhead.com/quest=10274
SET @ID := 10274;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Mata a Veraku', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has desafiado y derrotado a Veraku?', 0),
(@ID, 'esMX', '¿Has desafiado y derrotado a Veraku?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy, pero que muy bien, $n. Puede que los dragonantes abisales no acepten de entrada a un dragón Azul, pero con tiempo y unas demostraciones de autoridad, se acostumbrarán. Están dispersos, aislados y sin jefe; debemos estar alerta para evitar que caigan bajo alguna influencia malévola.', 0),
(@ID, 'esMX', 'Muy, pero que muy bien, $n. Puede que los dragonantes abisales no acepten de entrada a un dragón Azul, pero con tiempo y unas demostraciones de autoridad, se acostumbrarán. Están dispersos, aislados y sin jefe; debemos estar alerta para evitar que caigan bajo alguna influencia malévola.', 0);
-- 10275 Punto de triangulación dos
-- https://es.wowhead.com/quest=10275
SET @ID := 10275;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Deseas comprar o vender?', 0),
(@ID, 'esMX', '¿Deseas comprar o vender?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy, muy bien. ¡El Príncipe del Nexo estará complacido!$B$B¡El segundo punto de triangulación nos dirá dónde está el tercero y la ubicación del cristal!', 0),
(@ID, 'esMX', 'Muy, muy bien. ¡El Príncipe del Nexo estará complacido!$B$B¡El segundo punto de triangulación nos dirá dónde está el tercero y la ubicación del cristal!', 0);
-- 10276 Triángulo completo
-- https://es.wowhead.com/quest=10276
SET @ID := 10276;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo. ¿Ha habido suerte con el cristal?', 0),
(@ID, 'esMX', 'Hola de nuevo. ¿Ha habido suerte con el cristal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca soñé que llegarías a recuperar el cristal!$B$B¡Y que luego me lo traerías! ¿Tienes idea del poder que encierra?$B$B¡Tu generosidad no conoce límites, $n! Me has dado mucho en qué pensar.', 0),
(@ID, 'esMX', '¡Nunca soñé que llegarías a recuperar el cristal!$B$B¡Y que luego me lo traerías! ¿Tienes idea del poder que encierra?$B$B¡Tu generosidad no conoce límites, $n! Me has dado mucho en qué pensar.', 0);
-- 10277 Las Cavernas del Tiempo
-- https://es.wowhead.com/quest=10277
SET @ID := 10277;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No regreses hasta que tengas al menos una comprensión rudimentaria de lo que está sucediendo.', 0),
(@ID, 'esMX', 'No regreses hasta que tengas al menos una comprensión rudimentaria de lo que está sucediendo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es de esperar que ahora comprendas mejor lo que se espera de ti.', 0),
(@ID, 'esMX', 'Es de esperar que ahora comprendas mejor lo que se espera de ti.', 0);
-- 10278 Las fallas de distorsión
-- https://es.wowhead.com/quest=10278
SET @ID := 10278;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya usaste mi dispositivo experimental? Creo que mi Generador de fallas de distorsión inestable funcionará tan cerca del abismo.', 0),
(@ID, 'esMX', '¿Ya usaste mi dispositivo experimental? Creo que mi Generador de fallas de distorsión inestable funcionará tan cerca del abismo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Increíble. ¡Tocaste el vacío mismo! $n, salvaste el trabajo de toda mi vida. Pero aún queda mucho por hacer y tú puedes ayudarme.', 0),
(@ID, 'esMX', 'Increíble. ¡Tocaste el vacío mismo! $n, salvaste el trabajo de toda mi vida. Pero aún queda mucho por hacer y tú puedes ayudarme.', 0);
-- 10279 La caverna del maestro
-- https://es.wowhead.com/quest=10279
SET @ID := 10279;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos que prepararte para las batallas que están por llegar...', 0),
(@ID, 'esMX', 'Tenemos que prepararte para las batallas que están por llegar...', 0);
-- 10280 Una entrega especial a la Ciudad de Shattrath
-- https://es.wowhead.com/quest=10280
SET @ID := 10280;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La musicalidad del idioma de los naaru llena tu mente.>$B$BSiento que portas algo de gran poder, $r. ¿Qué me traes?', 0),
(@ID, 'esMX', '<La musicalidad del idioma de los naaru llena tu mente.>$B$BSiento que portas algo de gran poder, $r. ¿Qué me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has recuperado Canción del Espíritu! Es el Cristal de Ata\'mal que el profeta Velen dejó a su gente para que lo guardara cuando se embarcó en la malhadada misión a El Exodar.$B$BEs curioso que no adivinara que acabaría en manos de la Legión Ardiente, aunque fuera por poco tiempo.$B$B¿O puede que sí? A lo mejor sí lo supo y dejó el cristal para que tú lo recuperaras y me lo trajeras.$B$BCreo que eso es lo que pasó. ¡Eres un orgullo para tu gente, $n!', 0),
(@ID, 'esMX', '¡Has recuperado Canción del Espíritu! Es el Cristal de Ata\'mal que el profeta Velen dejó a su gente para que lo guardara cuando se embarcó en la malhadada misión a El Exodar.$B$BEs curioso que no adivinara que acabaría en manos de la Legión Ardiente, aunque fuera por poco tiempo.$B$B¿O puede que sí? A lo mejor sí lo supo y dejó el cristal para que tú lo recuperaras y me lo trajeras.$B$BCreo que eso es lo que pasó. ¡Eres un orgullo para tu gente, $n!', 0);
-- 10281 Presentaciones formales
-- https://es.wowhead.com/quest=10281
SET @ID := 10281;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me llamo Tyrygosa, del linaje de Malygos, pero todo el mundo me llama Tyri. Mi compañero es el $c Jorad Maza.$B$BLos rumores sobre estos extraños dragonantes se han extendido mucho y temo que habrá quien venga a explotarlos comercialmente sin darse cuenta de lo que son realmente. Esperamos que nos ayudes a conocer mejor a estas criaturas antes de que las descubran otros.', 0),
(@ID, 'esMX', 'Me llamo Tyrygosa, del linaje de Malygos, pero todo el mundo me llama Tyri. Mi compañero es el $c Jorad Maza.$B$BLos rumores sobre estos extraños dragonantes se han extendido mucho y temo que habrá quien venga a explotarlos comercialmente sin darse cuenta de lo que son realmente. Esperamos que nos ayudes a conocer mejor a estas criaturas antes de que las descubran otros.', 0);
-- 10282 Antigua Trabalomas
-- https://es.wowhead.com/quest=10282
SET @ID := 10282;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros peores temores podrían hacerse realidad muy pronto. Esta alteración temporal es obra de un nuevo Vuelo de dragones llamados los Infinitos. No sabemos de dónde vienen ni por qué destruyen los portales del tiempo.$B$BEn esta realidad temporal han secuestrado a Taretha Foxton, hija de Tammis Foxton, el secretario de Aedelas Lodonegro, gobernador de Durnholde y encargado de todos los campos de internamiento de Azeroth.', 0),
(@ID, 'esMX', 'Nuestros peores temores podrían hacerse realidad muy pronto. Esta alteración temporal es obra de un nuevo Vuelo de dragones llamados los Infinitos. No sabemos de dónde vienen ni por qué destruyen los portales del tiempo.$B$BEn esta realidad temporal han secuestrado a Taretha Foxton, hija de Tammis Foxton, el secretario de Aedelas Lodonegro, gobernador de Durnholde y encargado de todos los campos de internamiento de Azeroth.', 0);
-- 10283 La maniobra de Taretha
-- https://es.wowhead.com/quest=10283
SET @ID := 10283;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Pabellones de internamiento incendiados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién eres?', 0),
(@ID, 'esMX', '¿Quién eres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eres $gamigo:amiga; de Taretha? ¿Este es su nuevo plan? Muy bien entonces...', 0),
(@ID, 'esMX', '¿Eres $gamigo:amiga; de Taretha? ¿Este es su nuevo plan? Muy bien entonces...', 0);
-- 10284 Huida de Durnholde
-- https://es.wowhead.com/quest=10284
SET @ID := 10284;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Destino de Thrall cumplido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Erozion asiente.>', 0),
(@ID, 'esMX', '<Erozion asiente.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho algo grande, $n. Por desgracia, el recuerdo del joven jefe de guerra de estos eventos debe ser como era originalmente... Andormu te espera en la guarida del maestro.', 0),
(@ID, 'esMX', 'Has hecho algo grande, $n. Por desgracia, el recuerdo del joven jefe de guerra de estos eventos debe ser como era originalmente... Andormu te espera en la guarida del maestro.', 0);
-- 10285 Regresa junto a Andormu
-- https://es.wowhead.com/quest=10285
SET @ID := 10285;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acepta un regalo del vuelo de bronce. Estos objetetos te ayudarán en tus viajes a través del tiempo.', 0),
(@ID, 'esMX', 'Acepta un regalo del vuelo de bronce. Estos objetetos te ayudarán en tus viajes a través del tiempo.', 0);
-- 10286 El secreto de Arelion
-- https://es.wowhead.com/quest=10286
SET @ID := 10286;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hablaré, $c. Baja el arma; no quiero tener más problemas.', 0),
(@ID, 'esMX', 'Hablaré, $c. Baja el arma; no quiero tener más problemas.', 0);
-- 10287 Amante descubierta
-- https://es.wowhead.com/quest=10287
SET @ID := 10287;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Viera Suspirosol? Asquerosa metomentodo.$B$B¡Le enseñaré que conmigo no se juega!', 0),
(@ID, 'esMX', '¿Viera Suspirosol? Asquerosa metomentodo.$B$B¡Le enseñaré que conmigo no se juega!', 0);
-- 10288 Llegada a Terrallende
-- https://es.wowhead.com/quest=10288
SET @ID := 10288;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te vi hablando con Duron. ¡Debes de estar en una misión muy importante!', 0),
(@ID, 'esMX', 'Te vi hablando con Duron. ¡Debes de estar en una misión muy importante!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Informes del Bastión del Honor? Sin problema: te llevaremos allí $gsano y salvo:sana y salva; sobre uno de mis grifos.', 0),
(@ID, 'esMX', '¿Informes del Bastión del Honor? Sin problema: te llevaremos allí $gsano y salvo:sana y salva; sobre uno de mis grifos.', 0);
-- 10289 Viaje a Thrallmar
-- https://es.wowhead.com/quest=10289
SET @ID := 10289;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un Informe de Orion? ¡Dámelo, rápido!$B$B<Frunciendo el ceño, el General Krakork lee rápidamente el destrozado documento>$B$BMaldita sea, justo lo que nos temíamos. ¡Orion y sus guerreros podrían ser invadidos en cualquier momento!', 0),
(@ID, 'esMX', '¿Un Informe de Orion? ¡Dámelo, rápido!$B$B<Frunciendo el ceño, el General Krakork lee rápidamente el destrozado documento>$B$BMaldita sea, justo lo que nos temíamos. ¡Orion y sus guerreros podrían ser invadidos en cualquier momento!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reuniré todas las tropas que pueda y las enviaré a ayudar a Orion en El Portal Oscuro. ¡A la Legión le costará olvidar el grito de guerra de la Horda! Y tú, $n, has hecho un gran servicio a Thrallmar. Creo que nos vas a resultar de gran ayuda aquí, siempre y cuando consigas sobrevivir, claro está.', 0),
(@ID, 'esMX', 'Reuniré todas las tropas que pueda y las enviaré a ayudar a Orion en El Portal Oscuro. ¡A la Legión le costará olvidar el grito de guerra de la Horda! Y tú, $n, has hecho un gran servicio a Thrallmar. Creo que nos vas a resultar de gran ayuda aquí, siempre y cuando consigas sobrevivir, claro está.', 0);
-- 10290 Buscando faralita
-- https://es.wowhead.com/quest=10290
SET @ID := 10290;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entiendo los peligros que encierra recolectar faralita, pero los beneficios valen la pena. Si un mercante no está dispuesto a asumir riesgos, más le vale dejar el negocio.', 0),
(@ID, 'esMX', 'Entiendo los peligros que encierra recolectar faralita, pero los beneficios valen la pena. Si un mercante no está dispuesto a asumir riesgos, más le vale dejar el negocio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este es precisamente el tipo que quería. Si conseguimos asegurar una fuente con los gigantes quizás podamos dejar de excavar para extraer el cristal.', 0),
(@ID, 'esMX', 'Sí, este es precisamente el tipo que quería. Si conseguimos asegurar una fuente con los gigantes quizás podamos dejar de excavar para extraer el cristal.', 0);
-- 10291 Informar a Nazgrel
-- https://es.wowhead.com/quest=10291
SET @ID := 10291;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya hemos perdido demasiados valientes guerreros en esta maldita tierra. No tengo mucho interés en mandar más reclutas a una muerte segura.$B$B<Nazgrel te observa fijamente a través de su máscara de lobo>$B$BAun así, si el General Krakork te ha enviado, debe de haber visto algo en ti. ¿Qué me dices, $n? ¿Servirás a nuestro Jefe de Guerra con honor?', 0),
(@ID, 'esMX', 'Ya hemos perdido demasiados valientes guerreros en esta maldita tierra. No tengo mucho interés en mandar más reclutas a una muerte segura.$B$B<Nazgrel te observa fijamente a través de su máscara de lobo>$B$BAun así, si el General Krakork te ha enviado, debe de haber visto algo en ti. ¿Qué me dices, $n? ¿Servirás a nuestro Jefe de Guerra con honor?', 0);
-- 10293 A por la veta
-- https://es.wowhead.com/quest=10293
SET @ID := 10293;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigues con vida, lo que significa que traes el núcleo o que cambiaste de idea. ¿Y bien?', 0),
(@ID, 'esMX', 'Sigues con vida, lo que significa que traes el núcleo o que cambiaste de idea. ¿Y bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Voy a probarlo enseguida.', 0),
(@ID, 'esMX', '¡Buen trabajo! Voy a probarlo enseguida.', 0);
-- 10294 La Cresta del Vacío
-- https://es.wowhead.com/quest=10294
SET @ID := 10294;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que lo lograste? ¿Tienes los fragmentos que necesitamos?', 0),
(@ID, 'esMX', '¿Así que lo lograste? ¿Tienes los fragmentos que necesitamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estupendo, el generador de fallas de distorsión casi está terminado. Solo necesitamos un último ingrediente. Pronto seremos capaces de abrir una falla de distorsión hacia lo más profundo del Abismo.$B$B¿Quién sabe qué extraña criatura puede aparecer por ahí? Piénsalo, $n, el poder que semejante conocimiento traerá no tiene límites.', 0),
(@ID, 'esMX', 'Estupendo, el generador de fallas de distorsión casi está terminado. Solo necesitamos un último ingrediente. Pronto seremos capaces de abrir una falla de distorsión hacia lo más profundo del Abismo.$B$B¿Quién sabe qué extraña criatura puede aparecer por ahí? Piénsalo, $n, el poder que semejante conocimiento traerá no tiene límites.', 0);
-- 10295 Desde el abismo
-- https://es.wowhead.com/quest=10295
SET @ID := 10295;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya destruiste al barón del vacío Galaxis?', 0),
(@ID, 'esMX', '¿Ya destruiste al barón del vacío Galaxis?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Salvaste el trabajo de toda una vida, $n.$B$BMe tildaron de loco, se burlaron de mí, creyeron que había enloquecido con mi obsesión con la Cresta del Vacío y Los Campos Alabeados. Ahora con este fragmento de alma puedo revelar los secretos de los abisarios. Controlaré el poder del abismo.', 0),
(@ID, 'esMX', 'Salvaste el trabajo de toda una vida, $n.$B$BMe tildaron de loco, se burlaron de mí, creyeron que había enloquecido con mi obsesión con la Cresta del Vacío y Los Campos Alabeados. Ahora con este fragmento de alma puedo revelar los secretos de los abisarios. Controlaré el poder del abismo.', 0);
-- 10296 La Ciénaga Negra
-- https://es.wowhead.com/quest=10296
SET @ID := 10296;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ciertamente, si los orcos no llegan nunca a Azeroth, jamás se formará la Alianza. Acabará por estallar una guerra civil que debilitará aún más los reinos humanos.$B$BAl final la Legión Ardiente invadirá Azeroth y lo destruirá ante la ausencia de cualquier defensa.', 0),
(@ID, 'esMX', 'Ciertamente, si los orcos no llegan nunca a Azeroth, jamás se formará la Alianza. Acabará por estallar una guerra civil que debilitará aún más los reinos humanos.$B$BAl final la Legión Ardiente invadirá Azeroth y lo destruirá ante la ausencia de cualquier defensa.', 0);
-- 10297 La apertura de El Portal Oscuro
-- https://es.wowhead.com/quest=10297
SET @ID := 10297;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo puedes usar una cronobengala por bolsillo de tiempo.', 0),
(@ID, 'esMX', 'Solo puedes usar una cronobengala por bolsillo de tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Los portales del tiempo vuelven a estar a salvo.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Los portales del tiempo vuelven a estar a salvo.', 0);
-- 10298 Adalid del linaje
-- https://es.wowhead.com/quest=10298
SET @ID := 10298;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez más has asegurado el presente y el futuro de este mundo, $n. Acepta estos artículos como recompensa por tus logros.', 0),
(@ID, 'esMX', 'Una vez más has asegurado el presente y el futuro de este mundo, $n. Acepta estos artículos como recompensa por tus logros.', 0);
-- 10299 El cierre de la Forja de Maná B'naar
-- https://es.wowhead.com/quest=10299
SET @ID := 10299;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Forja de Maná B\'naar cerrada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido éxito en tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has tenido éxito en tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Luz te sonríe, $n. Todos rezamos para que tuvieras éxito.', 0),
(@ID, 'esMX', 'La Luz te sonríe, $n. Todos rezamos para que tuvieras éxito.', 0);
-- 10300 Reconstrucción del bastón
-- https://es.wowhead.com/quest=10300
SET @ID := 10300;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido encontrar algún cristal adecuado para la nueva empuñadura del bastón del archimago?', 0),
(@ID, 'esMX', '¿Has conseguido encontrar algún cristal adecuado para la nueva empuñadura del bastón del archimago?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ravandwyr examina detalladamente los cristales y elige uno.>$B$BEste cristal debería servir. Reformaré la hendidura del bastón para asegurar la nueva empuñadura.$B$BCuando el archimago Vargoth lo vea, se sentirá decepcionado, pero toleraré la decepción de mi maestro si eso significa que podemos salvarle.', 0),
(@ID, 'esMX', '<Ravandwyr examina detalladamente los cristales y elige uno.>$B$BEste cristal debería servir. Reformaré la hendidura del bastón para asegurar la nueva empuñadura.$B$BCuando el archimago Vargoth lo vea, se sentirá decepcionado, pero toleraré la decepción de mi maestro si eso significa que podemos salvarle.', 0);
-- 10301 Abrir el Compendio
-- https://es.wowhead.com/quest=10301
SET @ID := 10301;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el óculo?', 0),
(@ID, 'esMX', '¿Has conseguido el óculo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. Ahora, tenemos casi todo lo que necesitamos para romper la magia de Kael\'thas.$B$BY, si los elfos de sangre sufren por la pérdida de su comandante local, mejor que mejor.', 0),
(@ID, 'esMX', 'Excelente, $n. Ahora, tenemos casi todo lo que necesitamos para romper la magia de Kael\'thas.$B$BY, si los elfos de sangre sufren por la pérdida de su comandante local, mejor que mejor.', 0);
