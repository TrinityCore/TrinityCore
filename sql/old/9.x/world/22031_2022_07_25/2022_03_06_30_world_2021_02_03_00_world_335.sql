-- 4482 Tratado sobre Tenacidad
-- https://es.classic.wowhead.com/quest=4482
SET @ID := 4482;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Treinta de oro, $r. Treinta de oro y los componentes necesarios.', 0),
(@ID, 'esMX', 'Treinta de oro, $r. Treinta de oro y los componentes necesarios.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A Kariel le tomó lo que equivaldría a varias de tus vidas completar el libram que ahora tienes, $r. ¿Todo para qué? Para que su discípulo pudiera estar en las Estepas Ardientes y bastardar su investigación para saciar un anhelo arcano sin fin... Maldigo esta asquerosa adicción.$B$BEstoy disgustado con tu falta de compasión y tu codicia insaciable. ¡Vete!', 0),
(@ID, 'esMX', 'A Kariel le tomó lo que equivaldría a varias de tus vidas completar el libram que ahora tienes, $r. ¿Todo para qué? Para que su discípulo pudiera estar en las Estepas Ardientes y bastardar su investigación para saciar un anhelo arcano sin fin... Maldigo esta asquerosa adicción.$B$BEstoy disgustado con tu falta de compasión y tu codicia insaciable. ¡Vete!', 0);
-- 4483 Tratado sobre Resistencia
-- https://es.classic.wowhead.com/quest=4483
SET @ID := 4483;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si lo que deseas es resistencia, necesito treinta de oro.', 0),
(@ID, 'esMX', 'Si lo que deseas es resistencia, necesito treinta de oro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otros tratados se han perdido en este mundo. Perdido en lugares a los que no te atreverías a entrar. Los lugares a los que rezarías no existían.$B$BBeberé las energías de estos componentes. Te daré el residuo...', 0),
(@ID, 'esMX', 'Otros tratados se han perdido en este mundo. Perdido en lugares a los que no te atreverías a entrar. Los lugares a los que rezarías no existían.$B$BBeberé las energías de estos componentes. Te daré el residuo...', 0);
-- 4484 Tratado sobre Voracidad
-- https://es.classic.wowhead.com/quest=4484
SET @ID := 4484;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me hagas perder el tiempo, $r. Dame lo que necesito. 30 piezas de oro y los componentes.', 0),
(@ID, 'esMX', 'No me hagas perder el tiempo, $r. Dame lo que necesito. 30 piezas de oro y los componentes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cabeza me va a estallar... Las energías de la inmensidad que compone nuestro universo... ¡ARGH!$B$B<Mathredis parece sufrir.>$B$B¡Toma lo que desees y márchate!', 0),
(@ID, 'esMX', 'La cabeza me va a estallar... Las energías de la inmensidad que compone nuestro universo... ¡ARGH!$B$B<Mathredis parece sufrir.>$B$B¡Toma lo que desees y márchate!', 0);
-- 4494 La marcha de los silítidos
-- https://es.classic.wowhead.com/quest=4494
SET @ID := 4494;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que te envía Zilzibin. Tu experiencia con estas bestezuelas es inestimable; nunca nos hemos enfrentado a uno. Y sí, es posible que su fuerza provenga del Cráter de Un\'Goro. Es una selva misteriosa y peligrosa al oeste de aquí... Puede que contenga el secreto de los silítidos.', 0),
(@ID, 'esMX', 'Veo que te envía Zilzibin. Tu experiencia con estas bestezuelas es inestimable; nunca nos hemos enfrentado a uno. Y sí, es posible que su fuerza provenga del Cráter de Un\'Goro. Es una selva misteriosa y peligrosa al oeste de aquí... Puede que contenga el secreto de los silítidos.', 0);
-- 4505 El pozo de la corrupción
-- https://es.classic.wowhead.com/quest=4505
SET @ID := 4505;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es importante. Ponte en marcha ahora.', 0),
(@ID, 'esMX', 'Esto es importante. Ponte en marcha ahora.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Debemos encontrar una forma de utilizar esta corrupción contra nuestros enemigos...', 0),
(@ID, 'esMX', 'Muy bien. Debemos encontrar una forma de utilizar esta corrupción contra nuestros enemigos...', 0);
-- 4506 Dientes de sable corruptos
-- https://es.classic.wowhead.com/quest=4506
SET @ID := 4506;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No me digas que no puedes volver allí! ¡En marcha!', 0),
(@ID, 'esMX', '¡No me digas que no puedes volver allí! ¡En marcha!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente!$B$B¡Los Renegados usarán cualquier medio necesario para aplastar a la Alianza! El uso del agua corrupta seguramente será útil en nuestros próximos esfuerzos...', 0),
(@ID, 'esMX', '¡Excelente!$B$B¡Los Renegados usarán cualquier medio necesario para aplastar a la Alianza! El uso del agua corrupta seguramente será útil en nuestros próximos esfuerzos...', 0);
-- 4509 La calma que precede a la tormenta
-- https://es.classic.wowhead.com/quest=4509
SET @ID := 4509;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Son unos ineptos, $n! Si miraran a su alrededor, se darían cuenta de la amenaza a la que nos enfrentamos. Su odio irracional por la Alianza será nuestra ruina. Ya no sé qué más pruebas aportar para que vean la amenaza que representan los silítidos. Ya solo me queda meterlos de cabeza en una de sus colmenas para que se den cuenta de lo que digo$B$BLo siento, ¿tienes alguna noticia que darme?', 0),
(@ID, 'esMX', '¡Son unos ineptos, $n! Si miraran a su alrededor, se darían cuenta de la amenaza a la que nos enfrentamos. Su odio irracional por la Alianza será nuestra ruina. Ya no sé qué más pruebas aportar para que vean la amenaza que representan los silítidos. Ya solo me queda meterlos de cabeza en una de sus colmenas para que se den cuenta de lo que digo$B$BLo siento, ¿tienes alguna noticia que darme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque realmente aprecio esto, no sé en qué podrá beneficiarnos. La Horda ignora todo peligro que no provenga de la Alianza. Aunque Thrall por sí mismo seguramente haría algo si conociera la situación, lo cierto es que recibe consejos totalmente dispares. ¡Estos ignorantes serían capaces de hacernos perseguir nuestras propias colas imaginarias si creyeran que con eso pillarían a la Alianza desprevenida!$B$BTú has visto el peligro con tus propios ojos, $n. ¡Debemos seguir adelante con nuestro compromiso de acabar con los silítidos!', 0),
(@ID, 'esMX', 'Aunque realmente aprecio esto, no sé en qué podrá beneficiarnos. La Horda ignora todo peligro que no provenga de la Alianza. Aunque Thrall por sí mismo seguramente haría algo si conociera la situación, lo cierto es que recibe consejos totalmente dispares. ¡Estos ignorantes serían capaces de hacernos perseguir nuestras propias colas imaginarias si creyeran que con eso pillarían a la Alianza desprevenida!$B$BTú has visto el peligro con tus propios ojos, $n. ¡Debemos seguir adelante con nuestro compromiso de acabar con los silítidos!', 0);
-- 4511 La calma que precede a la tormenta
-- https://es.classic.wowhead.com/quest=4511
SET @ID := 4511;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Zug zug! ¿Qué puedo hacer por ti, $c?', 0),
(@ID, 'esMX', '¡Zug zug! ¿Qué puedo hacer por ti, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este vale del banco me autoriza a retirar un objeto de la cuenta de Zilzibin Drumlore para dártelo a ti.', 0),
(@ID, 'esMX', 'Este vale del banco me autoriza a retirar un objeto de la cuenta de Zilzibin Drumlore para dártelo a ti.', 0);
-- 4521 Guardianes salvajes
-- https://es.classic.wowhead.com/quest=4521
SET @ID := 4521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Infórmeme después de que hayas completado la tarea que te di.', 0),
(@ID, 'esMX', 'Infórmeme después de que hayas completado la tarea que te di.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una noticia excelente, $n. Con esas bestias fuera de nuestro camino podemos pensar en adentrarnos en Cuna del Invierno. ¿Estás $glisto:lista; para más?', 0),
(@ID, 'esMX', 'Es una noticia excelente, $n. Con esas bestias fuera de nuestro camino podemos pensar en adentrarnos en Cuna del Invierno. ¿Estás $glisto:lista; para más?', 0);
-- 4542 Mensaje para el Poblado Viento Libre
-- https://es.classic.wowhead.com/quest=4542
SET @ID := 4542;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué deseas, $c? Un mensaje urgente... ¿para mí?', 0),
(@ID, 'esMX', '¿Qué deseas, $c? Un mensaje urgente... ¿para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Malas noticias de nuevo! ¡Los centauros han ido demasiado lejos! Asaltaron una de mis caravanas de suministros y mataron a todo el destacamento. ¡Esto es un atropello que no quedará impune!', 0),
(@ID, 'esMX', '¡Malas noticias de nuevo! ¡Los centauros han ido demasiado lejos! Asaltaron una de mis caravanas de suministros y mataron a todo el destacamento. ¡Esto es un atropello que no quedará impune!', 0);
-- 4561 Pruebas de impureza: Cráter de Un'Goro
-- https://es.classic.wowhead.com/quest=4561
SET @ID := 4561;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coges una muestra de babosa del Cráter de Un\'Goro y colocas un poco en los diversos tubos y vasos de precipitados que se encuentran sobre la mesa. A medida que todo empieza a hervir, la babosa cambia de color. Cuando el proceso comienza a detenerse y los líquidos dejan de bullir, ves una placa de Petri que contiene tus muestras de babosa de Un\'Goro purificadas y algunos restos.', 0),
(@ID, 'esMX', 'Coges una muestra de babosa del Cráter de Un\'Goro y colocas un poco en los diversos tubos y vasos de precipitados que se encuentran sobre la mesa. A medida que todo empieza a hervir, la babosa cambia de color. Cuando el proceso comienza a detenerse y los líquidos dejan de bullir, ves una placa de Petri que contiene tus muestras de babosa de Un\'Goro purificadas y algunos restos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coges la placa de Petri, que contiene la muestra de babosa. El único modo de saber si la muestra es lo suficientemente pura es examinando su contenido. Con suerte, podrás encontrar una muestra que le sirva al químico Fuely.', 0),
(@ID, 'esMX', 'Coges la placa de Petri, que contiene la muestra de babosa. El único modo de saber si la muestra es lo suficientemente pura es examinando su contenido. Con suerte, podrás encontrar una muestra que le sirva al químico Fuely.', 0);
-- 4641 Tu lugar en el mundo
-- https://es.classic.wowhead.com/quest=4641
SET @ID := 4641;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caparazón de un escórpido no es tan grueso como para impedir que $gun:una; $c lo rompa. Golpea con fuerza y determinación, y los escórpidos deberían resultar presa fácil.', 0),
(@ID, 'esMX', 'El caparazón de un escórpido no es tan grueso como para impedir que $gun:una; $c lo rompa. Golpea con fuerza y determinación, y los escórpidos deberían resultar presa fácil.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otro de los reclutas de Kaltunk, ¿eh?$B$BPues sí que están mal las cosas, si esto es lo mejor que puede ofrecer la Horda. No importa. Para cuando te llegue el momento de salir del Valle, serás $gun:una; $c $gdigno:digna; de la Horda.', 0),
(@ID, 'esMX', 'Otro de los reclutas de Kaltunk, ¿eh?$B$BPues sí que están mal las cosas, si esto es lo mejor que puede ofrecer la Horda. No importa. Para cuando te llegue el momento de salir del Valle, serás $gun:una; $c $gdigno:digna; de la Horda.', 0);
-- 4642 Fusión de influencias
-- https://es.classic.wowhead.com/quest=4642
SET @ID := 4642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va el experimento, $n? Continuaré estudiando las muestras que has recuperado para mí. Estoy empezando a comprender por qué Lady Sylvanas está tan interesada en estas criaturas. Si realmente son parte de los Dioses Antiguos, entonces quién sabe cómo se pueden utilizar para nuestro beneficio.', 0),
(@ID, 'esMX', '¿Cómo va el experimento, $n? Continuaré estudiando las muestras que has recuperado para mí. Estoy empezando a comprender por qué Lady Sylvanas está tan interesada en estas criaturas. Si realmente son parte de los Dioses Antiguos, entonces quién sabe cómo se pueden utilizar para nuestro beneficio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, excelente, $n. Esto es excelente.$B$B¿Quién hubiera pensado que los dos interactuarían entre sí de tal manera? Tendré que dedicar más tiempo a analizar los problemas ambientales que causan cambios en estas criaturas.$B$BContinuaré mi investigación por ahora. Quizás volvamos a hablar pronto. Hasta entonces, te deseo lo mejor.', 0),
(@ID, 'esMX', 'Oh, excelente, $n. Esto es excelente.$B$B¿Quién hubiera pensado que los dos interactuarían entre sí de tal manera? Tendré que dedicar más tiempo a analizar los problemas ambientales que causan cambios en estas criaturas.$B$BContinuaré mi investigación por ahora. Quizás volvamos a hablar pronto. Hasta entonces, te deseo lo mejor.', 0);
-- 4661 Pruebas de Corrupción: Frondavil
-- https://es.classic.wowhead.com/quest=4661
SET @ID := 4661;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Coges una muestra de babosa de Frondavil y colocas un poco en los diversos tubos y vasos de precipitados que se encuentran sobre la mesa. A medida que todo empieza a hervir, la babosa cambia de color. Cuando el proceso comienza a detenerse y los líquidos dejan de bullir, ves una placa de Petri que contiene tus muestras de babosa de Frondavil modificadas y algunos restos.', 0),
(@ID, 'esMX', 'Coges una muestra de babosa de Frondavil y colocas un poco en los diversos tubos y vasos de precipitados que se encuentran sobre la mesa. A medida que todo empieza a hervir, la babosa cambia de color. Cuando el proceso comienza a detenerse y los líquidos dejan de bullir, ves una placa de Petri que contiene tus muestras de babosa de Frondavil modificadas y algunos restos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tomas la placa de Petri, que contiene la muestra de babosa. El único modo de saber si la muestra es lo suficientemente pura es examinando su contenido. Con suerte, podrás encontrar una muestra que le sirva al químico Fuely.', 0),
(@ID, 'esMX', 'Tomas la placa de Petri, que contiene la muestra de babosa. El único modo de saber si la muestra es lo suficientemente pura es examinando su contenido. Con suerte, podrás encontrar una muestra que le sirva al químico Fuely.', 0);
-- 4701 Acaba con el origen de la amenaza
-- https://es.classic.wowhead.com/quest=4701
SET @ID := 4701;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto y abordado el origen de la amenaza del huargo?', 0),
(@ID, 'esMX', '¿Has descubierto y abordado el origen de la amenaza del huargo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No pierdas el tiempo con su sufrimiento, $n. La bestia era corrupta, un producto de la magia oscura. Le has prestado un gran servicio a la Alianza y se te recompensará por ello.', 0),
(@ID, 'esMX', 'No pierdas el tiempo con su sufrimiento, $n. La bestia era corrupta, un producto de la magia oscura. Le has prestado un gran servicio a la Alianza y se te recompensará por ello.', 0);
-- 4721 Guardianes salvajes
-- https://es.classic.wowhead.com/quest=4721
SET @ID := 4721;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Conoces tus órdenes, $n.', 0),
(@ID, 'esMX', 'Conoces tus órdenes, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Respeto muchísimo el trabajo duro, $n. Ahora podemos seguir avanzando en nuestros planes para Cuna del Invierno.', 0),
(@ID, 'esMX', 'Respeto muchísimo el trabajo duro, $n. Ahora podemos seguir avanzando en nuestros planes para Cuna del Invierno.', 0);
-- 4722 Tortuga marina varada
-- https://es.classic.wowhead.com/quest=4722
SET @ID := 4722;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n, ¿tienes algún informe sobre alguna criatura que haya encallado en la costa?', 0),
(@ID, 'esMX', 'Hola, $n, ¿tienes algún informe sobre alguna criatura que haya encallado en la costa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos has traído más material de estudio, ¡bien hecho, $n! Estos restos serán estudiados adecuadamente una vez lleguen a Darnassus. Por favor, acepta este pequeño honorario a cambio de los restos que nos has proporcionado para nuestro estudio.', 0),
(@ID, 'esMX', 'Nos has traído más material de estudio, ¡bien hecho, $n! Estos restos serán estudiados adecuadamente una vez lleguen a Darnassus. Por favor, acepta este pequeño honorario a cambio de los restos que nos has proporcionado para nuestro estudio.', 0);
-- 4724 La maestra de la manada
-- https://es.classic.wowhead.com/quest=4724
SET @ID := 4724;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la señora de la manada asesinada, podemos empezar a reducir los huargos centinelas de la Aguja y, finalmente, hacer algunos avances en la ciudad.', 0),
(@ID, 'esMX', 'Con la señora de la manada asesinada, podemos empezar a reducir los huargos centinelas de la Aguja y, finalmente, hacer algunos avances en la ciudad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cachorros rabiosos? ¿Gizrul el esclavista? ¡¿Y has vivido para contarlo?! ¡Increíble! ¡Un tributo bien merecido!', 0),
(@ID, 'esMX', '¿Cachorros rabiosos? ¿Gizrul el esclavista? ¡¿Y has vivido para contarlo?! ¡Increíble! ¡Un tributo bien merecido!', 0);
-- 4725 Tortuga marina varada
-- https://es.classic.wowhead.com/quest=4725
SET @ID := 4725;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¡Qué placer volver a verte! Estamos haciendo grandes esfuerzos por descubrir por qué esas majestuosas criaturas marinas vienen a morir encalladas a Costa Oscura. Pero parece que con cada pregunta a la que respondemos, nos surgen dos más.$B$B¿Has venido a ofrecernos más ayuda en nuestra investigación?', 0),
(@ID, 'esMX', '¡$n! ¡Qué placer volver a verte! Estamos haciendo grandes esfuerzos por descubrir por qué esas majestuosas criaturas marinas vienen a morir encalladas a Costa Oscura. Pero parece que con cada pregunta a la que respondemos, nos surgen dos más.$B$B¿Has venido a ofrecernos más ayuda en nuestra investigación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He oído hablar de esa especie de carruaje que hay en el lomo de la tortuga que encontraste. Creo que es un carruaje naga. Los usan tanto en combate como para transportar suministros a tierra. Los símbolos de la caja que encontraste, son de los naga. Eso explicaría su invasiva presencia en la zona norte de Costa Oscura.$B$BEnviaré esta caja a Darnassus junto con el resto de tus hallazgos. Esto es para ti. Gracias de nuevo por tu ayuda.', 0),
(@ID, 'esMX', 'He oído hablar de esa especie de carruaje que hay en el lomo de la tortuga que encontraste. Creo que es un carruaje naga. Los usan tanto en combate como para transportar suministros a tierra. Los símbolos de la caja que encontraste, son de los naga. Eso explicaría su invasiva presencia en la zona norte de Costa Oscura.$B$BEnviaré esta caja a Darnassus junto con el resto de tus hallazgos. Esto es para ti. Gracias de nuevo por tu ayuda.', 0);
-- 4726 Esencia de cría
-- https://es.classic.wowhead.com/quest=4726
SET @ID := 4726;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la esencia de cría, $n? Me muero por estudiarla.$B$BAdemás... mi cliente no es el tipo de persona al que convenga defraudar.', 0),
(@ID, 'esMX', '¿Tienes la esencia de cría, $n? Me muero por estudiarla.$B$BAdemás... mi cliente no es el tipo de persona al que convenga defraudar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ha funcionado! ¡Tienes la esencia! ¡Muy bien, $n! ¡Muy bien!$B$BEsta esencia será inestimable en mi investigación. Algún día espero aprender a capturar crías de dragón vivas, o quizás a capturar sus huevos. Si encontrara la forma de hacerlo, ¡sería la envidia de los estudiosos de dragones en el mundo entero!$B$BMi jefe también se alegraría y, como te dije antes, es alguien a quien más vale tener contento...', 0),
(@ID, 'esMX', '¡Ha funcionado! ¡Tienes la esencia! ¡Muy bien, $n! ¡Muy bien!$B$BEsta esencia será inestimable en mi investigación. Algún día espero aprender a capturar crías de dragón vivas, o quizás a capturar sus huevos. Si encontrara la forma de hacerlo, ¡sería la envidia de los estudiosos de dragones en el mundo entero!$B$BMi jefe también se alegraría y, como te dije antes, es alguien a quien más vale tener contento...', 0);
-- 4727 Tortuga marina varada
-- https://es.classic.wowhead.com/quest=4727
SET @ID := 4727;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola otra vez, $n. ¿Has encontrado alguna otra criatura encallada de la que el Templo de la Luna debería ser informado?', 0),
(@ID, 'esMX', 'Hola otra vez, $n. ¿Has encontrado alguna otra criatura encallada de la que el Templo de la Luna debería ser informado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es interesante que los murlocs no estuvieran allí... ¡lo tendremos en cuenta cuando estudiemos los restos de esta criatura! Gracias por tus esfuerzos, $n; el Templo de la Luna quiere que te dé esto para compensarte por tu tiempo.', 0),
(@ID, 'esMX', 'Es interesante que los murlocs no estuvieran allí... ¡lo tendremos en cuenta cuando estudiemos los restos de esta criatura! Gracias por tus esfuerzos, $n; el Templo de la Luna quiere que te dé esto para compensarte por tu tiempo.', 0);
-- 4728 Criatura marina varada
-- https://es.classic.wowhead.com/quest=4728
SET @ID := 4728;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, una vez más, $n. ¿Qué te trae de nuevo por Auberdine? ¿Has venido a informar de algún otro descubrimiento?', 0),
(@ID, 'esMX', 'Saludos, una vez más, $n. ¿Qué te trae de nuevo por Auberdine? ¿Has venido a informar de algún otro descubrimiento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, creo que los restos que encontraste estaban siendo estudiados en un principio por la Liga de Exploradores. Están trabajando en Costa Oscura. Dijeron que estaban estudiando una de las criaturas varadas cuando un grupo de murlocs los ahuyentó. Parece que has tenido éxito donde todos nosotros fracasamos. Por favor, acepta este honorario que te ofrece el Templo de la Luna.', 0),
(@ID, 'esMX', 'Ah, creo que los restos que encontraste estaban siendo estudiados en un principio por la Liga de Exploradores. Están trabajando en Costa Oscura. Dijeron que estaban estudiando una de las criaturas varadas cuando un grupo de murlocs los ahuyentó. Parece que has tenido éxito donde todos nosotros fracasamos. Por favor, acepta este honorario que te ofrece el Templo de la Luna.', 0);
-- 4729 Las mascotas exóticas de Kibler
-- https://es.classic.wowhead.com/quest=4729
SET @ID := 4729;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kibler está ocupado discutiendo con Opus.>', 0),
(@ID, 'esMX', '<Kibler está ocupado discutiendo con Opus.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los has conseguido en el momento justo, $n. ¡Un poco más tarde y no habría quien los amaestrara! Dame un minutillo y te prepararé tu propio cachorrillo.', 0),
(@ID, 'esMX', 'Los has conseguido en el momento justo, $n. ¡Un poco más tarde y no habría quien los amaestrara! Dame un minutillo y te prepararé tu propio cachorrillo.', 0);
-- 4730 Criatura marina varada
-- https://es.classic.wowhead.com/quest=4730
SET @ID := 4730;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola otra vez, $n. ¿Has venido a informar de algún otro descubrimiento?', 0),
(@ID, 'esMX', 'Hola otra vez, $n. ¿Has venido a informar de algún otro descubrimiento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los huesos que traes son de unos amables mamíferos marinos que habitan las aguas que rodean la base de Teldrassil. Jamás se había documentado que ninguno encallara tan violentamente en una playa como hacen los trilladores. ¿Por qué lo harán? Quizás el estudio de sus restos nos proporcione el conocimiento que buscamos.$B$BUna vez más, gracias por tu ayuda. Por favor, acepta este honorario del Templo de la Luna.', 0),
(@ID, 'esMX', 'Los huesos que traes son de unos amables mamíferos marinos que habitan las aguas que rodean la base de Teldrassil. Jamás se había documentado que ninguno encallara tan violentamente en una playa como hacen los trilladores. ¿Por qué lo harán? Quizás el estudio de sus restos nos proporcione el conocimiento que buscamos.$B$BUna vez más, gracias por tu ayuda. Por favor, acepta este honorario del Templo de la Luna.', 0);
-- 4731 Tortuga marina varada
-- https://es.classic.wowhead.com/quest=4731
SET @ID := 4731;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola de nuevo, $n. Has hecho un trabajo extraordinario para el Templo de la Luna. ¿Vas a bendecirnos con algún otro esfuerzo?', 0),
(@ID, 'esMX', 'Hola de nuevo, $n. Has hecho un trabajo extraordinario para el Templo de la Luna. ¿Vas a bendecirnos con algún otro esfuerzo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He oído hablar de esa especie de carruajes encontrados en el lomo de esa tortuga. Creo que son carruajes naga. Los usan tanto en combate como para transportar suministros a tierra. Los símbolos de la caja que encontraste son de los naga; quizás la criatura que descubriste fue asesinada cuando se dirigía más al sur... ¿a Vallefresno quizás?$B$BEnviaré esta caja a Darnassus con el resto de tus hallazgos. Esto es para ti. Gracias de nuevo por tu ayuda.', 0),
(@ID, 'esMX', 'He oído hablar de esa especie de carruajes encontrados en el lomo de esa tortuga. Creo que son carruajes naga. Los usan tanto en combate como para transportar suministros a tierra. Los símbolos de la caja que encontraste son de los naga; quizás la criatura que descubriste fue asesinada cuando se dirigía más al sur... ¿a Vallefresno quizás?$B$BEnviaré esta caja a Darnassus con el resto de tus hallazgos. Esto es para ti. Gracias de nuevo por tu ayuda.', 0);
-- 4732 Tortuga marina varada
-- https://es.classic.wowhead.com/quest=4732
SET @ID := 4732;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos otra vez, $n. ¿Algún descubrimiento más del que informar al Templo de la Luna?', 0),
(@ID, 'esMX', 'Saludos otra vez, $n. ¿Algún descubrimiento más del que informar al Templo de la Luna?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado más criaturas varadas, $n? Las tortugas marinas solían retozar en la base de Nordrassil antes de que fuera destruido. Pero, con el nacimiento de Teldrassil, cada vez se ven menos de estas criaturas. Hemos descubierto que algunas ponen fin a sus vidas por algún motivo desconocido.$B$BQuizás con tu ayuda descubramos el misterio. Por favor, acepta esto a cambio de los restos que nos has proporcionado para nuestro estudio.', 0),
(@ID, 'esMX', '¿Has encontrado más criaturas varadas, $n? Las tortugas marinas solían retozar en la base de Nordrassil antes de que fuera destruido. Pero, con el nacimiento de Teldrassil, cada vez se ven menos de estas criaturas. Hemos descubierto que algunas ponen fin a sus vidas por algún motivo desconocido.$B$BQuizás con tu ayuda descubramos el misterio. Por favor, acepta esto a cambio de los restos que nos has proporcionado para nuestro estudio.', 0);
-- 4733 Criatura marina varada
-- https://es.classic.wowhead.com/quest=4733
SET @ID := 4733;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a Elune! Me alegro de volver a verte, $n. El Templo de la Luna sigue trabajando en los extraños fenómenos de encalladuras de Costa Oscura. ¿No tendrás algo que aportar?', 0),
(@ID, 'esMX', '¡Gracias a Elune! Me alegro de volver a verte, $n. El Templo de la Luna sigue trabajando en los extraños fenómenos de encalladuras de Costa Oscura. ¿No tendrás algo que aportar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las dimensiones de ese trillador del que me hablas son inconcebibles. Los trilladores más ancianos de esta región alcanzan solo una fracción de ese tamaño. Había algunos más grandes cerca de Teldrassil, pero su número va disminuyendo. No puedo evitar preguntarme si estas criaturas que acaban varadas en la playa estarán relacionadas con esto.$B$BNosotros analizaremos los huesos que nos has traído. Mientras, acepta por favor este detalle del Templo de la Luna. Gracias, $n.', 0),
(@ID, 'esMX', 'Las dimensiones de ese trillador del que me hablas son inconcebibles. Los trilladores más ancianos de esta región alcanzan solo una fracción de ese tamaño. Había algunos más grandes cerca de Teldrassil, pero su número va disminuyendo. No puedo evitar preguntarme si estas criaturas que acaban varadas en la playa estarán relacionadas con esto.$B$BNosotros analizaremos los huesos que nos has traído. Mientras, acepta por favor este detalle del Templo de la Luna. Gracias, $n.', 0);
-- 4734 Un huevo congelado
-- https://es.classic.wowhead.com/quest=4734
SET @ID := 4734;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has probado el ovosciloscopio?', 0),
(@ID, 'esMX', '$n, ¿has probado el ovosciloscopio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha funcionado? ¡Fantástico! ¡Lo sabía!$B$BMientras estabas de viaje he trabajado en una nueva versión del ovosciloscopio. Este tiene un alcance mucho mayor.$B$BToma, puedes quedarte con uno por si volvieras a la Cumbre de Roca Negra.', 0),
(@ID, 'esMX', '¿Ha funcionado? ¡Fantástico! ¡Lo sabía!$B$BMientras estabas de viaje he trabajado en una nueva versión del ovosciloscopio. Este tiene un alcance mucho mayor.$B$BToma, puedes quedarte con uno por si volvieras a la Cumbre de Roca Negra.', 0);
-- 4735 La colecta de huevos
-- https://es.classic.wowhead.com/quest=4735
SET @ID := 4735;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los huevos, $n? ¡Mi patrón escuchó que los estaba reuniendo para mí y está muy ansioso por tenerlos en sus manos!', 0),
(@ID, 'esMX', '¿Tienes los huevos, $n? ¡Mi patrón escuchó que los estaba reuniendo para mí y está muy ansioso por tenerlos en sus manos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, los tienes! ¡El módulo collectrónico funcionó! ¡Soy un genio!$B$BGracias, $n. Mi patrón estará muy contento de conseguir estos huevos...', 0),
(@ID, 'esMX', '¡Vaya, los tienes! ¡El módulo collectrónico funcionó! ¡Soy un genio!$B$BGracias, $n. Mi patrón estará muy contento de conseguir estos huevos...', 0);
-- 4736 Buscando a Menara Nadiz
-- https://es.classic.wowhead.com/quest=4736
SET @ID := 4736;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, te envió Briarthorn. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0),
(@ID, 'esMX', 'Ah, te envió Briarthorn. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0);
-- 4737 Buscando a Menara Nadiz
-- https://es.classic.wowhead.com/quest=4737
SET @ID := 4737;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Zevrost te envió. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0),
(@ID, 'esMX', 'Ah, Zevrost te envió. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0);
-- 4738 Buscando a Menara Nadiz
-- https://es.classic.wowhead.com/quest=4738
SET @ID := 4738;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Demisette te envió. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0),
(@ID, 'esMX', 'Ah, Demisette te envió. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0);
-- 4739 Buscando a Menara Nadiz
-- https://es.classic.wowhead.com/quest=4739
SET @ID := 4739;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Kaal te envió. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0),
(@ID, 'esMX', 'Ah, Kaal te envió. Bueno. Entonces la palabra llega lo suficientemente lejos como para encontrar futuros estudiantes. Esto me agrada.$B$BEs típico de nuestra especie, $n, unirse, independientemente de la raza. Es especialmente importante ya que aquellos con quienes tratamos la mayoría no discrimina en su malicia si no los apaciguamos o controlamos adecuadamente.$B$BSiento que has aprendido muchas cosas y, si estás $gdispuesto:dispuesta;, te ayudaría a crear herramientas para complementar tus habilidades.', 0);
-- 4741 Guardianes salvajes
-- https://es.classic.wowhead.com/quest=4741
SET @ID := 4741;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No me digas que estás demasiado $gasustado:asustada;! ¡Ponte en marcha!', 0),
(@ID, 'esMX', '¡No me digas que estás demasiado $gasustado:asustada;! ¡Ponte en marcha!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo la sensación de que disfrutas con tu trabajo. Y creo que estamos a punto de dar con algo.', 0),
(@ID, 'esMX', 'Tengo la sensación de que disfrutas con tu trabajo. Y creo que estamos a punto de dar con algo.', 0);
