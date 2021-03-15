-- 7581 Las selladuras de la prisión
-- https://es.classic.wowhead.com/quest=7581
SET @ID := 7581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo la sangre del sátiro Mala Hierba será suficiente.', 0),
(@ID, 'esMX', 'Solo la sangre del sátiro Mala Hierba será suficiente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, una excelente adquisición. La sangre suprimirá las defensas mágicas de los Guardias apocalípticos.', 0),
(@ID, 'esMX', 'Ah, una excelente adquisición. La sangre suprimirá las defensas mágicas de los Guardias apocalípticos.', 0);
-- 7582 El revestimiento de la prisión
-- https://es.classic.wowhead.com/quest=7582
SET @ID := 7582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Hederine no renunciará a sus preciosas gemas sin luchar, $n.', 0),
(@ID, 'esMX', 'Los Hederine no renunciará a sus preciosas gemas sin luchar, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo necesito combinar la sangre de los Sátiro Mala Hierba con estos cristales y la prisión estará lista para su uso.', 0),
(@ID, 'esMX', 'Solo necesito combinar la sangre de los Sátiro Mala Hierba con estos cristales y la prisión estará lista para su uso.', 0);
-- 7583 Supresión
-- https://es.classic.wowhead.com/quest=7583
SET @ID := 7583;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hrm? ¿Bien?', 0),
(@ID, 'esMX', '¿Hrm? ¿Bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho lo que te pedí. Estás $glisto:lista; para recibir el conocimiento para conjurar y controlar a la bestia.', 0),
(@ID, 'esMX', 'Has hecho lo que te pedí. Estás $glisto:lista; para recibir el conocimiento para conjurar y controlar a la bestia.', 0);
-- 7601 La orden de Niby
-- https://es.classic.wowhead.com/quest=7601
SET @ID := 7601;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh $gchico:chica;, aquí vamos de nuevo.', 0),
(@ID, 'esMX', 'Oh $gchico:chica;, aquí vamos de nuevo.', 0);
-- 7602 Esencia de energía vil pura
-- https://es.classic.wowhead.com/quest=7602
SET @ID := 7602;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No le digas a nadie, pero Niby es tonto.', 0),
(@ID, 'esMX', 'No le digas a nadie, pero Niby es tonto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame un minuto y combinaré las esencias en fuego vil.', 0),
(@ID, 'esMX', 'Dame un minuto y combinaré las esencias en fuego vil.', 0);
-- 7603 El núcleo infernal de Kroshius
-- https://es.classic.wowhead.com/quest=7603
SET @ID := 7603;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has perdido?', 0),
(@ID, 'esMX', '¿Te has perdido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un trato es un trato! Rápido, toma esto y anótalo. ¡No tengo tiempo! ¡Mi mayor conjuro está sobre nosotros!', 0),
(@ID, 'esMX', '¡Un trato es un trato! Rápido, toma esto y anótalo. ¡No tengo tiempo! ¡Mi mayor conjuro está sobre nosotros!', 0);
-- 7604 Un contrato vinculante
-- https://es.wowhead.com/quest=7604
SET @ID := 7604;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Trato?', 0),
(@ID, 'esMX', '¿Trato?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ha sido un placer hacer negocios contigo, $n!$B$B¡En nombre de HT, S.A., te deseo suerte en tu búsqueda de Sulfuras!', 0),
(@ID, 'esMX', '¡Ha sido un placer hacer negocios contigo, $n!$B$B¡En nombre de HT, S.A., te deseo suerte en tu búsqueda de Sulfuras!', 0);
-- 7621 Un aviso
-- https://es.classic.wowhead.com/quest=7621
SET @ID := 7621;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, estás a punto de pasar por una rigurosa serie de eventos que pondrán a prueba todas tus habilidades.$B$BTe sugiero que escuches la historia que tengo que contar.$B$BTen cuidado, debes completar esta tarea $gsolo:sola;. Se recomienda que tus aliados se mantengan a distancia. La interferencia de agentes externos resultará en un castigo más severo.$B$BEl destino te ha llevado a ti y solo a ti, hasta aquí. Batalla con honor. Aprovecha la luz.', 0),
(@ID, 'esMX', '$n, estás a punto de pasar por una rigurosa serie de eventos que pondrán a prueba todas tus habilidades.$B$BTe sugiero que escuches la historia que tengo que contar.$B$BTen cuidado, debes completar esta tarea $gsolo:sola;. Se recomienda que tus aliados se mantengan a distancia. La interferencia de agentes externos resultará en un castigo más severo.$B$BEl destino te ha llevado a ti y solo a ti, hasta aquí. Batalla con honor. Aprovecha la luz.', 0);
-- 7622 Equilibrio de Luz y Sombras
-- https://es.classic.wowhead.com/quest=7622
SET @ID := 7622;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu tenacidad y coraje son asombrosos, $gsacerdote:sacerdotisa;. Te has ganado el derecho a poseer la Astilla de Nordrassil. Solo queda una tarea: el Ojo de las Sombras debe recuperarse. Recorre el mundo.', 0),
(@ID, 'esMX', 'Tu tenacidad y coraje son asombrosos, $gsacerdote:sacerdotisa;. Te has ganado el derecho a poseer la Astilla de Nordrassil. Solo queda una tarea: el Ojo de las Sombras debe recuperarse. Recorre el mundo.', 0);
-- 7623 Lord Pesadilla
-- https://es.classic.wowhead.com/quest=7623
SET @ID := 7623;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi paciencia se extiende por milenios, $n. Pero no creas que te permite más de un instante de mi tiempo...', 0),
(@ID, 'esMX', 'Mi paciencia se extiende por milenios, $n. Pero no creas que te permite más de un instante de mi tiempo...', 0);
-- 7624 Ulathek el Traidor
-- https://es.classic.wowhead.com/quest=7624
SET @ID := 7624;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya puedo saborear el corazón de Ulathek en mis labios. Tan dulce es la carne de un traidor...', 0),
(@ID, 'esMX', 'Ya puedo saborear el corazón de Ulathek en mis labios. Tan dulce es la carne de un traidor...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué espléndido! Después de pudrirse una semana, ¡este corazón resultará un suculento regalo! Quizás enviaré a buscar la cabeza de Ulathek y la colocaré ante mí mientras como...$B$BMe has prestado un servicio, $n, por lo que mi paciencia ha aumentado. Ligeramente.', 0),
(@ID, 'esMX', '¡Ah, qué espléndido! Después de pudrirse una semana, ¡este corazón resultará un suculento regalo! Quizás enviaré a buscar la cabeza de Ulathek y la colocaré ante mí mientras como...$B$BMe has prestado un servicio, $n, por lo que mi paciencia ha aumentado. Ligeramente.', 0);
-- 7625 Polvo estelar xorothiano
-- https://es.classic.wowhead.com/quest=7625
SET @ID := 7625;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en Jaedenar, $n? ¿Has conseguido el polvo estelar de Lord Pesadilla?', 0),
(@ID, 'esMX', '¿Has estado en Jaedenar, $n? ¿Has conseguido el polvo estelar de Lord Pesadilla?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahí está! ¡Casi no puedo creer que lo tengas! Debes de haber llegado a un pacto de aúpa con ese señor del terror o habrás pagado una suma indecente, ¡o ambos!$B$BMor\'zul tendrá su tinta muy pronto y podrá al fin crear el pergamino con glifos, de forma que puedas abrir un portal a Xoroth ¡y conseguir uno de sus famosos terrorecus!', 0),
(@ID, 'esMX', '¡Ahí está! ¡Casi no puedo creer que lo tengas! Debes de haber llegado a un pacto de aúpa con ese señor del terror o habrás pagado una suma indecente, ¡o ambos!$B$BMor\'zul tendrá su tinta muy pronto y podrá al fin crear el pergamino con glifos, de forma que puedas abrir un portal a Xoroth ¡y conseguir uno de sus famosos terrorecus!', 0);
-- 7626 La Campana de Dethmoora
-- https://es.classic.wowhead.com/quest=7626
SET @ID := 7626;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esos elixires, $n? Mor\'zul me dijo que necesitabas una Campana de Dethmoora y para hacer una de estas ¡hace falta mucha energía!', 0),
(@ID, 'esMX', '¿Tienes esos elixires, $n? Mor\'zul me dijo que necesitabas una Campana de Dethmoora y para hacer una de estas ¡hace falta mucha energía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! Espero que no te costara demasiado conseguir esos elixires. A veces los alquimistas son tan mezquinos con sus creaciones...$B$BCrearé la campana y la guardaré hasta que estés $gpreparado:preparada; para el ritual.', 0),
(@ID, 'esMX', '¡Estupendo! Espero que no te costara demasiado conseguir esos elixires. A veces los alquimistas son tan mezquinos con sus creaciones...$B$BCrearé la campana y la guardaré hasta que estés $gpreparado:preparada; para el ritual.', 0);
-- 7627 Rueda de la Marcha Negra
-- https://es.classic.wowhead.com/quest=7627
SET @ID := 7627;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Rueda de la Marcha Negra no es fácil de hacer, requiere muchos materiales. ¿Los has reunido ya?', 0),
(@ID, 'esMX', 'La Rueda de la Marcha Negra no es fácil de hacer, requiere muchos materiales. ¿Los has reunido ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahí están! He oído que el mineral de hierro negro solo se encuentra en las profundidades de Roca Negra y estoy seguro de que tampoco ha sido fácil encontrar estos fragmentos. Nunca deja de asombrarme la entrega de los brujos. Si decidieras concentrar toda esa energía en la captura de bichos, ¡nadarías en la abundancia!$B$BDisculpa, una pequeña digresión. Crearé la rueda y la guardaré hasta que estés $gpreparado:preparada; para el ritual.', 0),
(@ID, 'esMX', '¡Ahí están! He oído que el mineral de hierro negro solo se encuentra en las profundidades de Roca Negra y estoy seguro de que tampoco ha sido fácil encontrar estos fragmentos. Nunca deja de asombrarme la entrega de los brujos. Si decidieras concentrar toda esa energía en la captura de bichos, ¡nadarías en la abundancia!$B$BDisculpa, una pequeña digresión. Crearé la rueda y la guardaré hasta que estés $gpreparado:preparada; para el ritual.', 0);
-- 7628 La Vela del Apocalipsis
-- https://es.classic.wowhead.com/quest=7628
SET @ID := 7628;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Trajiste las escamas de dragón, $n? No quiero comenzar con la vela hasta que las tenga... ¡o podría volar todo el campamento!', 0),
(@ID, 'esMX', '¿Trajiste las escamas de dragón, $n? No quiero comenzar con la vela hasta que las tenga... ¡o podría volar todo el campamento!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Las necesitaré para contener los fuegos de la vela. Ahora que tengo la balanza, haré la vela y la sostendré hasta que estés $glisto:lista; para comenzar tu ritual para el Círculo de Invocación Mayor.', 0),
(@ID, 'esMX', 'Ah, muy bien. Las necesitaré para contener los fuegos de la vela. Ahora que tengo la balanza, haré la vela y la sostendré hasta que estés $glisto:lista; para comenzar tu ritual para el Círculo de Invocación Mayor.', 0);
-- 7629 Entrega de diablillo
-- https://es.classic.wowhead.com/quest=7629
SET @ID := 7629;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Pergamino creado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en el Scholomance, $n? ¿El diablillo ya ha infundido el pergamino con el polvo de estrellas?', 0),
(@ID, 'esMX', '¿Has estado en el Scholomance, $n? ¿El diablillo ya ha infundido el pergamino con el polvo de estrellas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah bueno. J\'eevee creó el pergamino. ¿Cómo estuvo Scholomance? Encantador, ¿no crees? Y los bichos allí... ¡Escuché que son deliciosos!$B$BBien hecho, $n, y gracias por devolver mi frasco. Lo tengo desde hace mucho tiempo... ¡y no está a la venta!', 0),
(@ID, 'esMX', 'Ah bueno. J\'eevee creó el pergamino. ¿Cómo estuvo Scholomance? Encantador, ¿no crees? Y los bichos allí... ¡Escuché que son deliciosos!$B$BBien hecho, $n, y gracias por devolver mi frasco. Lo tengo desde hace mucho tiempo... ¡y no está a la venta!', 0);
-- 7631 Corcel nefasto xorothiano
-- https://es.classic.wowhead.com/quest=7631
SET @ID := 7631;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has derrotado al espíritu del corcel nefasto de Xoroth. Aunque la furia aún late por sus fantasmales flancos, sabes que el alma de la bestia es tuya...$B$BLe susurra magia oscura a tu mente y te infiere el conocimiento para conjurar un corcel nefasto.', 0),
(@ID, 'esMX', 'Has derrotado al espíritu del corcel nefasto de Xoroth. Aunque la furia aún late por sus fantasmales flancos, sabes que el alma de la bestia es tuya...$B$BLe susurra magia oscura a tu mente y te infiere el conocimiento para conjurar un corcel nefasto.', 0);
-- 7632 La hoja antigua
-- https://es.classic.wowhead.com/quest=7632
SET @ID := 7632;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Vartrus gime.>', 0),
(@ID, 'esMX', '<Vartrus gime.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por supuesto que reconozco mis propias hojas. ¡Mira eso! Esta en perfectas condiciones.$B$BQué bueno que lo devuelvas, $n.$B$BQuizás pueda sernos útil y nosotros a ti.', 0),
(@ID, 'esMX', 'Por supuesto que reconozco mis propias hojas. ¡Mira eso! Esta en perfectas condiciones.$B$BQué bueno que lo devuelvas, $n.$B$BQuizás pueda sernos útil y nosotros a ti.', 0);
-- 7633 Una presentación
-- https://es.classic.wowhead.com/quest=7633
SET @ID := 7633;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se ha observado tu diligencia e integridad, $n.$B$BSomos Ancianos: Protectores de este otrora gran bosque. Nuestras formas físicas fueron destruidas hace 10.000 años cuando Archimonde y la Legión Ardiente marcharon sobre Hyjal. Nuestros espíritus, sin embargo, permanecen intactos.$B$BHay tareas que podemos ofrecer. Tareas que, si se completan, te revelarán los secretos de los Antiguos.$B$BDebes saber esto, si completas estas tareas, simplemente regresa a esta roca y responderemos a la llamada.', 0),
(@ID, 'esMX', 'Se ha observado tu diligencia e integridad, $n.$B$BSomos Ancianos: Protectores de este otrora gran bosque. Nuestras formas físicas fueron destruidas hace 10.000 años cuando Archimonde y la Legión Ardiente marcharon sobre Hyjal. Nuestros espíritus, sin embargo, permanecen intactos.$B$BHay tareas que podemos ofrecer. Tareas que, si se completan, te revelarán los secretos de los Antiguos.$B$BDebes saber esto, si completas estas tareas, simplemente regresa a esta roca y responderemos a la llamada.', 0);
-- 7634 Carcaj antiguo cosido con tendón
-- https://es.classic.wowhead.com/quest=7634
SET @ID := 7634;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, joven $n.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, joven $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que mis hojas protejan tus flechas del daño. Que tus flechas sean certeras. Que los enemigos de nuestro mundo sean derrotados.', 0),
(@ID, 'esMX', 'Que mis hojas protejan tus flechas del daño. Que tus flechas sean certeras. Que los enemigos de nuestro mundo sean derrotados.', 0);
-- 7635 La cuerda adecuada
-- https://es.classic.wowhead.com/quest=7635
SET @ID := 7635;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy seguro de que tendrás pocas dificultades para encontrar y matar a un dragón negro, $n. No pierdas mi tiempo con charlas ociosas.', 0),
(@ID, 'esMX', 'Estoy seguro de que tendrás pocas dificultades para encontrar y matar a un dragón negro, $n. No pierdas mi tiempo con charlas ociosas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este era un dragón de lo más repugnante. El tendón apesta a maldad.$B$BDame un momento para limpiar la suciedad de esta carne y aplicar los encantamientos adecuados.', 0),
(@ID, 'esMX', 'Este era un dragón de lo más repugnante. El tendón apesta a maldad.$B$BDame un momento para limpiar la suciedad de esta carne y aplicar los encantamientos adecuados.', 0);
-- 7636 El báculo de los Ancestros
-- https://es.classic.wowhead.com/quest=7636
SET @ID := 7636;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te dejes engañar por sus disfraces!', 0),
(@ID, 'esMX', '¡No te dejes engañar por sus disfraces!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nos has servido bien, $n! Toma este pentagrama y combínalo con la cuerda de arco que Stoma es capaz de crear. Juntos, forman un arma formidable.', 0),
(@ID, 'esMX', '¡Nos has servido bien, $n! Toma este pentagrama y combínalo con la cuerda de arco que Stoma es capaz de crear. Juntos, forman un arma formidable.', 0);
-- 7640 Exorcismo en Valle del Terror
-- https://es.classic.wowhead.com/quest=7640
SET @ID := 7640;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno verte de nuevo $n. ¿Está hecho el trabajo en el Valle del Terror?', 0),
(@ID, 'esMX', 'Es bueno verte de nuevo $n. ¿Está hecho el trabajo en el Valle del Terror?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Dar el juicio de la Luz sobre los que moran en las tinieblas es una tarea que debemos abordar con entusiasmo y celo; lo has hecho con tu sacrificio en Forjaz y tus juicios sobre los espíritus en el Valle del Terror.$B$BTus próximos pasos requerirán tanto sacrificio como juicio nuevamente mientras luchas por recuperar el espíritu de un caballero caído que ahora sirve a un Caballero de la Muerte conocido como Atracoscuro.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Dar el juicio de la Luz sobre los que moran en las tinieblas es una tarea que debemos abordar con entusiasmo y celo; lo has hecho con tu sacrificio en Forjaz y tus juicios sobre los espíritus en el Valle del Terror.$B$BTus próximos pasos requerirán tanto sacrificio como juicio nuevamente mientras luchas por recuperar el espíritu de un caballero caído que ahora sirve a un Caballero de la Muerte conocido como Atracoscuro.', 0);
-- 7641 El trabajo de Grimand Elmore
-- https://es.classic.wowhead.com/quest=7641
SET @ID := 7641;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, Lord Quiebrasombras me envió un mensaje con anticipación de que vendrías por aquí para verme. Estoy dispuesto a hacerte lo que necesitas, pero no será barato ni fácil; saquemos eso a la luz en primer lugar.$B$BDiré todo esto, y Grayson me respaldará cuando haga esta afirmación... no encontrarás mejores bardas hechas en todo Azeroth que aquí.', 0),
(@ID, 'esMX', 'Hola, Lord Quiebrasombras me envió un mensaje con anticipación de que vendrías por aquí para verme. Estoy dispuesto a hacerte lo que necesitas, pero no será barato ni fácil; saquemos eso a la luz en primer lugar.$B$BDiré todo esto, y Grayson me respaldará cuando haga esta afirmación... no encontrarás mejores bardas hechas en todo Azeroth que aquí.', 0);
-- 7642 Recopilación de artículos
-- https://es.classic.wowhead.com/quest=7642
SET @ID := 7642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n. No podré terminar tu barda sin las cosas que mencioné. ¿Has reunido todo?', 0),
(@ID, 'esMX', 'Ah, $n. No podré terminar tu barda sin las cosas que mencioné. ¿Has reunido todo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto... bueno, esto es exactamente lo que necesitaba. Eres bastante $gingenioso:ingeniosa; $n, ¿no?$B$BMuy bien, ¡terminemos esta barda para ti!', 0),
(@ID, 'esMX', 'Esto... bueno, esto es exactamente lo que necesitaba. Eres bastante $gingenioso:ingeniosa; $n, ¿no?$B$BMuy bien, ¡terminemos esta barda para ti!', 0);
-- 7643 El antiguo espíritu equino
-- https://es.classic.wowhead.com/quest=7643
SET @ID := 7643;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Antiguo Espíritu Equino te mira expectante, como si quisiera algo de ti.', 0),
(@ID, 'esMX', 'El Antiguo Espíritu Equino te mira expectante, como si quisiera algo de ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Antiguo Espíritu Equino acepta la ofrenda del pienso para caballos enriquecido con maná, acariciando el recipiente mientras se sirve la avena y los cereales especiales. Después de haber comido un poco, mira la barda que posees y se posiciona como si quisiera que la coloques sobre su espalda...', 0),
(@ID, 'esMX', 'El Antiguo Espíritu Equino acepta la ofrenda del pienso para caballos enriquecido con maná, acariciando el recipiente mientras se sirve la avena y los cereales especiales. Después de haber comido un poco, mira la barda que posees y se posiciona como si quisiera que la coloques sobre su espalda...', 0);
-- 7644 La gualdrapa de arcanita bendita
-- https://es.classic.wowhead.com/quest=7644
SET @ID := 7644;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡has vuelto! ¿Pudiste lidiar con éxito con Merideth Carlson y Tendris Alabeo? Honestamente, no estoy seguro de cuál es una amenaza mayor a veces...', 0),
(@ID, 'esMX', '$n, ¡has vuelto! ¿Pudiste lidiar con éxito con Merideth Carlson y Tendris Alabeo? Honestamente, no estoy seguro de cuál es una amenaza mayor a veces...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has llegado lejos, $gamigo:amiga;. Tu barda está ahora adecuadamente preparada para la última tarea que tienes entre manos.$B$BUsarás esta barda para aprovechar tu corcel una vez que la tarea de redención esté completa. Antes de eso, sin embargo, tendrás que superar una lucha monumental. Tu tiempo se acerca - ¡huzzah!$B$BHay un último elemento que debe hacerse antes de comenzar esto, $n. Ojalá tu ingenio no te haya abandonado desde que te hiciste la barda...', 0),
(@ID, 'esMX', 'Has llegado lejos, $gamigo:amiga;. Tu barda está ahora adecuadamente preparada para la última tarea que tienes entre manos.$B$BUsarás esta barda para aprovechar tu corcel una vez que la tarea de redención esté completa. Antes de eso, sin embargo, tendrás que superar una lucha monumental. Tu tiempo se acerca - ¡huzzah!$B$BHay un último elemento que debe hacerse antes de comenzar esto, $n. Ojalá tu ingenio no te haya abandonado desde que te hiciste la barda...', 0);
-- 7645 Alimento para caballos enriquecido con maná
-- https://es.classic.wowhead.com/quest=7645
SET @ID := 7645;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, te he demostrado que te equivocas, ¿no? ¡He demostrado que todos estaban equivocados! ¡¡¡YO ESTOY EN LO CIERTO!!!', 0),
(@ID, 'esMX', 'Sí, te he demostrado que te equivocas, ¿no? ¡He demostrado que todos estaban equivocados! ¡¡¡YO ESTOY EN LO CIERTO!!!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'SÍ, AHORA QUIÉN - espera - ¿también me estás dando el oro? ¿No fuiste tú quien me llamó loco? (en realidad me llamaron un loco de pastel de frutas)... aún así, ¿estás $gdispuesto:dispuesta; a mostrar sacrificio incluso por los errores que no has cometido?$B$BYo... te juzgué mal, $n. Si necesitas más alimento para caballos, ven a verme. Te lo daré gratis. Gracias... noble $n.$B$BSin embargo, me voy a quedar con el dinero; no estoy tan loco como para renunciar a una fortuna.', 0),
(@ID, 'esMX', 'SÍ, AHORA QUIÉN - espera - ¿también me estás dando el oro? ¿No fuiste tú quien me llamó loco? (en realidad me llamaron un loco de pastel de frutas)... aún así, ¿estás $gdispuesto:dispuesta; a mostrar sacrificio incluso por los errores que no has cometido?$B$BYo... te juzgué mal, $n. Si necesitas más alimento para caballos, ven a verme. Te lo daré gratis. Gracias... noble $n.$B$BSin embargo, me voy a quedar con el dinero; no estoy tan loco como para renunciar a una fortuna.', 0);
-- 7646 El cristal de adivinación
-- https://es.classic.wowhead.com/quest=7646
SET @ID := 7646;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has llegado muy lejos, $n. Tu acto final de sacrificio de objetos mundanos será la génesis de uno de tus mayores logros. ¡Lo puedo sentir en la fibra misma de mi ser!', 0),
(@ID, 'esMX', 'Has llegado muy lejos, $n. Tu acto final de sacrificio de objetos mundanos será la génesis de uno de tus mayores logros. ¡Lo puedo sentir en la fibra misma de mi ser!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son buenos ejemplares, $n; las piezas finales ya están en su lugar. ¡Por fin, ha llegado tu hora!$B$BEn las profundidades del Gran Osario de Scholomance se encuentran los restos óseos de muchos seres. Entre ellos se encuentra un caballero que alguna vez fue noble. El alma hueca de este caballero ahora sirve como corcel para el Caballero de la Muerte Atracoscuro. Es a él a quien te enfrentarás, y es este corcel al que juzgarás. Solo tú, $n, puedes redimir su alma y salvarla del tormento de su servidumbre.', 0),
(@ID, 'esMX', 'Estos son buenos ejemplares, $n; las piezas finales ya están en su lugar. ¡Por fin, ha llegado tu hora!$B$BEn las profundidades del Gran Osario de Scholomance se encuentran los restos óseos de muchos seres. Entre ellos se encuentra un caballero que alguna vez fue noble. El alma hueca de este caballero ahora sirve como corcel para el Caballero de la Muerte Atracoscuro. Es a él a quien te enfrentarás, y es este corcel al que juzgarás. Solo tú, $n, puedes redimir su alma y salvarla del tormento de su servidumbre.', 0);
-- 7647 Juzgar y redimir
-- https://es.classic.wowhead.com/quest=7647
SET @ID := 7647;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El espíritu del corcel caído te mira con mirada triste. Ojos tristes, casi vacíos, te miran como si toda esperanza se hubiera perdido.', 0),
(@ID, 'esMX', 'El espíritu del corcel caído te mira con mirada triste. Ojos tristes, casi vacíos, te miran como si toda esperanza se hubiera perdido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un destello de vida, largamente ausente de la pobre bestia, brilla en sus ojos mientras le devuelves su alma juzgada. Sientes una oleada de poder sagrado a tu alrededor cuando colocas la barda sobre su espalda, habiendo juzgado al corcel redimido. El corcel acaricia tu mano mientras las cargas del pasado son quitadas de la bestia. Ahora sientes que podrías llamar a esta bestia para que te sirva como tu corcel, en caso de que surja la necesidad.$B$B¡Has reclamado tu corcel épico, $n! ¡Felicidades!', 0),
(@ID, 'esMX', 'Un destello de vida, largamente ausente de la pobre bestia, brilla en sus ojos mientras le devuelves su alma juzgada. Sientes una oleada de poder sagrado a tu alrededor cuando colocas la barda sobre su espalda, habiendo juzgado al corcel redimido. El corcel acaricia tu mano mientras las cargas del pasado son quitadas de la bestia. Ahora sientes que podrías llamar a esta bestia para que te sirva como tu corcel, en caso de que surja la necesidad.$B$B¡Has reclamado tu corcel épico, $n! ¡Felicidades!', 0);
-- Las mallas de placas en torio encantado: volumen I
-- 7649, 7650, 7651
-- https://es.classic.wowhead.com/quest=7649
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7649, 7650, 7651) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7649, 'esES', '¡Has recuperado un tomo!', 0),
(7650, 'esES', '¡Has recuperado un tomo!', 0),
(7651, 'esES', '¡Has recuperado un tomo!', 0),
(7649, 'esMX', '¡Has recuperado un tomo!', 0),
(7650, 'esMX', '¡Has recuperado un tomo!', 0),
(7651, 'esMX', '¡Has recuperado un tomo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7649, 7650, 7651) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7649, 'esES', 'Bien hecho, mi $gniño:niña;.$B$B<Tradicionalista Lydros arranca una página del libro.>$B$BEstoy seguro de que puedes hacer uso de esta receta.', 0),
(7650, 'esES', 'Bien hecho, mi $gniño:niña;.$B$B<Tradicionalista Lydros arranca una página del libro.>$B$BEstoy seguro de que puedes hacer uso de esta receta.', 0),
(7651, 'esES', 'Bien hecho, mi $gniño:niña;.$B$B<Tradicionalista Lydros arranca una página del libro.>$B$BEstoy seguro de que puedes hacer uso de esta receta.', 0),
(7649, 'esMX', 'Bien hecho, mi $gniño:niña;.$B$B<Tradicionalista Lydros arranca una página del libro.>$B$BEstoy seguro de que puedes hacer uso de esta receta.', 0),
(7650, 'esMX', 'Bien hecho, mi $gniño:niña;.$B$B<Tradicionalista Lydros arranca una página del libro.>$B$BEstoy seguro de que puedes hacer uso de esta receta.', 0),
(7651, 'esMX', 'Bien hecho, mi $gniño:niña;.$B$B<Tradicionalista Lydros arranca una página del libro.>$B$BEstoy seguro de que puedes hacer uso de esta receta.', 0);
-- 7652 Una ganga azulada
-- https://es.classic.wowhead.com/quest=7652
SET @ID := 7652;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $gseñor:señora;, te voy a ofrecer un buen trato.$B$BQuiero deshacerme de estos diseños de esta armadura de placas imperiales y necesito a alguien que cargue con ellos. Todo lo que quiero a cambio es algunas barras de torio. ¿Te parece bien?', 0),
(@ID, 'esMX', 'Muy bien, $gseñor:señora;, te voy a ofrecer un buen trato.$B$BQuiero deshacerme de estos diseños de esta armadura de placas imperiales y necesito a alguien que cargue con ellos. Todo lo que quiero a cambio es algunas barras de torio. ¿Te parece bien?', 0);
-- 7653 Cinturón de placas imperiales
-- https://es.classic.wowhead.com/quest=7653
SET @ID := 7653;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para los planos del cinturón, necesitaré 10 barras de torio.', 0),
(@ID, 'esMX', 'Para los planos del cinturón, necesitaré 10 barras de torio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0),
(@ID, 'esMX', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0);
-- 7654 Botas de placas imperiales
-- https://es.classic.wowhead.com/quest=7654
SET @ID := 7654;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para los planes de las botas, necesitaré 20 barras de torio. Sí, 20. ¿Vas a llorar? ¿Quieres un pañuelo?$B$B<Derotain se ríe.>', 0),
(@ID, 'esMX', 'Para los planes de las botas, necesitaré 20 barras de torio. Sí, 20. ¿Vas a llorar? ¿Quieres un pañuelo?$B$B<Derotain se ríe.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0),
(@ID, 'esMX', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0);
