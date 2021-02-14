-- 5223 Regresa al Campamento del Orvallo
-- https://es.classic.wowhead.com/quest=5223
SET @ID := 5223;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que analicemos con éxito la muestra extraída del caldero del Tormento, ¡nos proporcionará una tercera vía para entregar un contraagente devastador para la Plaga!', 0),
(@ID, 'esMX', 'Una vez que analicemos con éxito la muestra extraída del caldero del Tormento, ¡nos proporcionará una tercera vía para entregar un contraagente devastador para la Plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Otra misión finamente ejecutada, $n! Esto pone a nuestra disposición tres calderos para volverlos contra la Plaga. Si el dominio nigromántico de Kel\'Thuzad sobre estas tierras no fuera tan fuerte como lo es actualmente, ¡me atrevería a decir que las cerrarías por completo!$B$BEl alquimista Arbington tendrá un informe sobre lo que este caldero, al igual que los otros calderos, requerirá para entregar nuestro contraagente a la plaga. ¡Con eso, ha llegado el momento de traer el último caldero del oeste bajo nuestra influencia!', 0),
(@ID, 'esMX', '¡Otra misión finamente ejecutada, $n! Esto pone a nuestra disposición tres calderos para volverlos contra la Plaga. Si el dominio nigromántico de Kel\'Thuzad sobre estas tierras no fuera tan fuerte como lo es actualmente, ¡me atrevería a decir que las cerrarías por completo!$B$BEl alquimista Arbington tendrá un informe sobre lo que este caldero, al igual que los otros calderos, requerirá para entregar nuestro contraagente a la plaga. ¡Con eso, ha llegado el momento de traer el último caldero del oeste bajo nuestra influencia!', 0);
-- 5224 La caldera de El Tormento
-- https://es.classic.wowhead.com/quest=5224
SET @ID := 5224;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y adquirido su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0),
(@ID, 'esMX', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y adquirido su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el medio ambiente.', 0),
(@ID, 'esMX', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el medio ambiente.', 0);
-- 5225 Objetivo: Gangrena de Gahrron
-- https://es.classic.wowhead.com/quest=5225
SET @ID := 5225;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El panel de acceso al caldero permanece bien sujeto. Para abrirlo, deberás encontrar la llave.', 0),
(@ID, 'esMX', 'El panel de acceso al caldero permanece bien sujeto. Para abrirlo, deberás encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave del señor del Caldero se desintegra cuando toca la cerradura en el panel de acceso en la base de la plataforma del caldero. Se escucha un ligero ruido metálico en el interior y el panel de acceso se abre para revelar más toxinas viscosas dentro del marco del caldero.$B$BHay un pequeño grifo debajo del cual encaja la botella lo suficientemente bien, lo que le permite extraer una muestra para la Suma Sacerdotisa MacDonnell en el Campamento del Orvallo.', 0),
(@ID, 'esMX', 'La llave del señor del Caldero se desintegra cuando toca la cerradura en el panel de acceso en la base de la plataforma del caldero. Se escucha un ligero ruido metálico en el interior y el panel de acceso se abre para revelar más toxinas viscosas dentro del marco del caldero.$B$BHay un pequeño grifo debajo del cual encaja la botella lo suficientemente bien, lo que le permite extraer una muestra para la Suma Sacerdotisa MacDonnell en el Campamento del Orvallo.', 0);
-- 5226 Regresa al Campamento del Orvallo
-- https://es.classic.wowhead.com/quest=5226
SET @ID := 5226;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gangrena de Gahrron alberga el último caldero aquí en el este al que necesitamos acceder. Una vez que tengamos una muestra de la plaga que arroja, ¡podremos introducir nuestros reactivos en el medio ambiente a través de cuatro recipientes separados! La Plaga estará en apuros para mantenernos fuera de los cuatro, incluso con el poder de Kel\'Thuzad detrás de ellos.', 0),
(@ID, 'esMX', 'Gangrena de Gahrron alberga el último caldero aquí en el este al que necesitamos acceder. Una vez que tengamos una muestra de la plaga que arroja, ¡podremos introducir nuestros reactivos en el medio ambiente a través de cuatro recipientes separados! La Plaga estará en apuros para mantenernos fuera de los cuatro, incluso con el poder de Kel\'Thuzad detrás de ellos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Felicitaciones $n, has desbloqueado el último caldero para nosotros! El alquimista Arbington pronto sabrá los reactivos necesarios para este caldero.$B$BEn cuanto a ti, estoy seguro de que el comandante Valorfist querrá agradecerle personalmente la ayuda que nos has brindado. Sin ti, nuestra lucha contra la Plaga habría sido casi insuperable. ¡Gracias, $ghéroe:heroína;!', 0),
(@ID, 'esMX', '¡Felicitaciones $n, has desbloqueado el último caldero para nosotros! El alquimista Arbington pronto sabrá los reactivos necesarios para este caldero.$B$BEn cuanto a ti, estoy seguro de que el comandante Valorfist querrá agradecerle personalmente la ayuda que nos has brindado. Sin ti, nuestra lucha contra la Plaga habría sido casi insuperable. ¡Gracias, $ghéroe:heroína;!', 0);
-- 5227 La caldera de la Gangrena de Gahrron
-- https://es.classic.wowhead.com/quest=5227
SET @ID := 5227;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y adquirido su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0),
(@ID, 'esMX', 'El caldero de la Plaga está ante ti, arrojando grandes cantidades de toxinas al aire. Un pequeño panel de acceso indescriptible se encuentra en la base de la vasta plataforma del caldero.$B$BDespués de haber derrotado al señor del caldero y adquirido su llave, puedes agregar los reactivos apropiados al caldero para hacer un agente contra la plaga.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el aire.', 0),
(@ID, 'esMX', 'Al agregar los reactivos a la mezcla del caldero, este comienza a cambiar el color y la textura de la nube que arroja. Los miembros de la Plaga que están cerca del caldero parecen retroceder ante la introducción de los nuevos componentes en el aire.', 0);
-- 5228 Las calderas de la Plaga
-- https://es.classic.wowhead.com/quest=5228
SET @ID := 5228;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Desde las sombras, $ghermano:hermana; $r, te hago llegar mis saludos. Estoy aquí para servirte como coordinadora en nuestro plan para sabotear las calderas de la Plaga.$B$BNuestro objetivo será alterar la composición de la peste que crean las calderas, convirtiéndola en algo que afecte negativamente a la Plaga. Para conseguir este cambio tendrás que acceder a las cuatro calderas de las Tierras de la Peste del Oeste.$B$BHa llegado el momento de que lideres el ataque contra la Plaga, $ghéroe:heroína;.', 0),
(@ID, 'esMX', 'Desde las sombras, $ghermano:hermana; $r, te hago llegar mis saludos. Estoy aquí para servirte como coordinadora en nuestro plan para sabotear las calderas de la Plaga.$B$BNuestro objetivo será alterar la composición de la peste que crean las calderas, convirtiéndola en algo que afecte negativamente a la Plaga. Para conseguir este cambio tendrás que acceder a las cuatro calderas de las Tierras de la Peste del Oeste.$B$BHa llegado el momento de que lideres el ataque contra la Plaga, $ghéroe:heroína;.', 0);
-- 5229 Objetivo: Campo de Piedramácula
-- https://es.classic.wowhead.com/quest=5229
SET @ID := 5229;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0),
(@ID, 'esMX', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave que has conseguido del señor de la caldera Garravil encaja perfectamente y abre el panel de acceso, pero desaparece cuando la utilizas. Sin embargo te parece que ahora podrás abrir el panel sin la llave. Un hedor nauseabundo emana del panel una vez abierto, al tiempo que una mezcla desconocida de sustancias concentradas se arremolina en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0),
(@ID, 'esMX', 'La llave que has conseguido del señor de la caldera Garravil encaja perfectamente y abre el panel de acceso, pero desaparece cuando la utilizas. Sin embargo te parece que ahora podrás abrir el panel sin la llave. Un hedor nauseabundo emana del panel una vez abierto, al tiempo que una mezcla desconocida de sustancias concentradas se arremolina en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0);
-- 5230 Regresa a El Baluarte
-- https://es.classic.wowhead.com/quest=5230
SET @ID := 5230;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido de nuevo a la relativa seguridad de El Baluarte, $n. ¿Tienes que informar sobre algún progreso con las calderas?', 0),
(@ID, 'esMX', 'Bienvenido de nuevo a la relativa seguridad de El Baluarte, $n. ¿Tienes que informar sobre algún progreso con las calderas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n, el boticario Dithers no debería necesitar mucho tiempo para analizar esto y preparar un contraagente que introducir en la caldera. Si pudiéramos propagar suficiente contraagente en el aire podríamos debilitar la Plaga de este lugar.$B$BSerá sin duda un duro esfuerzo pero no podemos dejar de atentar contra esas calderas ni de introducir nuestros componentes en su mezcla. Sin embargo, si pudiéramos seguir así tendríamos una enorme ventaja sobre la Plaga cuando llegara el momento de la batalla.', 0),
(@ID, 'esMX', 'Bien hecho, $n, el boticario Dithers no debería necesitar mucho tiempo para analizar esto y preparar un contraagente que introducir en la caldera. Si pudiéramos propagar suficiente contraagente en el aire podríamos debilitar la Plaga de este lugar.$B$BSerá sin duda un duro esfuerzo pero no podemos dejar de atentar contra esas calderas ni de introducir nuestros componentes en su mezcla. Sin embargo, si pudiéramos seguir así tendríamos una enorme ventaja sobre la Plaga cuando llegara el momento de la batalla.', 0);
-- 5231 Objetivo: Llanto de Dalson
-- https://es.classic.wowhead.com/quest=5231
SET @ID := 5231;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0),
(@ID, 'esMX', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave esquelética que encontraste en el señor de la caldera se desliza suavemente en la cerradura y desaparece, permitiéndote acceder permanentemente al panel. Unos icores crudos y viscosos palpitan a través de tubos retorcidos en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0),
(@ID, 'esMX', 'La llave esquelética que encontraste en el señor de la caldera se desliza suavemente en la cerradura y desaparece, permitiéndote acceder permanentemente al panel. Unos icores crudos y viscosos palpitan a través de tubos retorcidos en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0);
-- 5232 Regresa a El Baluarte
-- https://es.classic.wowhead.com/quest=5232
SET @ID := 5232;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabemos que cada una de las calderas utiliza una mezcla distinta de componentes para generar su toxina inductora de la peste. De igual modo sabemos que tendremos que desarrollar un contraagente único para cada caldera. Tu muestra del Llanto de Dalson será la clave para comprender los componentes distintivos para esa caldera.', 0),
(@ID, 'esMX', 'Sabemos que cada una de las calderas utiliza una mezcla distinta de componentes para generar su toxina inductora de la peste. De igual modo sabemos que tendremos que desarrollar un contraagente único para cada caldera. Tu muestra del Llanto de Dalson será la clave para comprender los componentes distintivos para esa caldera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, aquí hay mucho que estudiar. ¡Bien hecho, $n!$B$BPor ahora, el siguiente paso está en nuestras manos. Tendremos que producir una lista de componentes que combinados con lo que ya está en la caldera actúen como su contrario.$B$BEl único modo en el que podremos conseguirlo es poniendo los componentes directamente en la caldera. El boticario Dithers tendrá más información, así que no olvides hablar con él en cuanto te sea posible.', 0),
(@ID, 'esMX', 'Ah, aquí hay mucho que estudiar. ¡Bien hecho, $n!$B$BPor ahora, el siguiente paso está en nuestras manos. Tendremos que producir una lista de componentes que combinados con lo que ya está en la caldera actúen como su contrario.$B$BEl único modo en el que podremos conseguirlo es poniendo los componentes directamente en la caldera. El boticario Dithers tendrá más información, así que no olvides hablar con él en cuanto te sea posible.', 0);
-- 5233 Objetivo: El Tormento
-- https://es.classic.wowhead.com/quest=5233
SET @ID := 5233;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0),
(@ID, 'esMX', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave del señor de la caldera abre el panel de acceso a la caldera y desaparece como ya ocurrió en las anteriores calderas. Un olor putrefacto se agita violentamente bajo la plataforma de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0),
(@ID, 'esMX', 'La llave del señor de la caldera abre el panel de acceso a la caldera y desaparece como ya ocurrió en las anteriores calderas. Un olor putrefacto se agita violentamente bajo la plataforma de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0);
-- 5234 Regresa a El Baluarte
-- https://es.classic.wowhead.com/quest=5234
SET @ID := 5234;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cuando analicemos con éxito la muestra extraída de la caldera de El Tormento, tendremos una tercera vía para desarrollar un contraagente devastador contra la Plaga!', 0),
(@ID, 'esMX', '¡Cuando analicemos con éxito la muestra extraída de la caldera de El Tormento, tendremos una tercera vía para desarrollar un contraagente devastador contra la Plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Otra misión ejecutada a la perfección, $n! Con esta ya son tres calderas que podemos volver contra la Plaga. Si el dominio nigromántico de Kel\'Thuzad sobre estas tierras no fuera tan fuerte me atrevería a decirte que acabaras con ellas por completo.$B$BEl boticario Dithers tendrá un informe sobre lo que esta y las demás calderas necesitarán para que nuestro contraagente se dirija contra la Peste. ¡Así pues ha llegado el momento de poner bajo nuestra influencia la última caldera del Oeste!', 0),
(@ID, 'esMX', '¡Otra misión ejecutada a la perfección, $n! Con esta ya son tres calderas que podemos volver contra la Plaga. Si el dominio nigromántico de Kel\'Thuzad sobre estas tierras no fuera tan fuerte me atrevería a decirte que acabaras con ellas por completo.$B$BEl boticario Dithers tendrá un informe sobre lo que esta y las demás calderas necesitarán para que nuestro contraagente se dirija contra la Peste. ¡Así pues ha llegado el momento de poner bajo nuestra influencia la última caldera del Oeste!', 0);
-- 5235 Objetivo: Gangrena de Gahrron
-- https://es.classic.wowhead.com/quest=5235
SET @ID := 5235;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0),
(@ID, 'esMX', 'Un panel de acceso a la caldera sigue estando cerrado. Para abrirlo tendrás que encontrar la llave.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La llave del señor de la caldera Iralma se desintegra al tocar el candado del panel de acceso a la base de la plataforma de la caldera. Se oye un débil sonido metálico en el interior y el panel de acceso se abre para mostrar más toxinas viscosas en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0),
(@ID, 'esMX', 'La llave del señor de la caldera Iralma se desintegra al tocar el candado del panel de acceso a la base de la plataforma de la caldera. Se oye un débil sonido metálico en el interior y el panel de acceso se abre para mostrar más toxinas viscosas en el interior de la caldera.$B$BHay una pequeña espita en la que encaja la botella y puedes recoger una muestra para la sacerdotisa de las Sombras Vandis en El Baluarte.', 0);
-- 5236 Regresa a El Baluarte
-- https://es.classic.wowhead.com/quest=5236
SET @ID := 5236;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Tormento alberga la última de las calderas a las que necesitamos acceder. Cuando tengamos una muestra de la peste de la caldera podremos introducir nuestros componentes en el entorno a través de cuatro recipientes distintos. La Plaga tendrá problemas para mantenernos fuera de los cuatro... aun teniendo el poder de Kel\'Thuzad detrás suyo.', 0),
(@ID, 'esMX', 'El Tormento alberga la última de las calderas a las que necesitamos acceder. Cuando tengamos una muestra de la peste de la caldera podremos introducir nuestros componentes en el entorno a través de cuatro recipientes distintos. La Plaga tendrá problemas para mantenernos fuera de los cuatro... aun teniendo el poder de Kel\'Thuzad detrás suyo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Felicidades, $n, ¡has conseguido abrirnos la última caldera! El boticario Dithers pronto sabrá qué componentes se necesitan para la mezcla.$B$BEn cuanto a ti, seguro que el sumo ejecutor Derrington querrá agradecerte personalmente la ayuda que nos has prestado. Sin ti nuestra lucha contra la Plaga habría sido prácticamente insuperable. Muchas gracias, $gpoderoso:poderosa; $c.', 0),
(@ID, 'esMX', 'Felicidades, $n, ¡has conseguido abrirnos la última caldera! El boticario Dithers pronto sabrá qué componentes se necesitan para la mezcla.$B$BEn cuanto a ti, seguro que el sumo ejecutor Derrington querrá agradecerte personalmente la ayuda que nos has prestado. Sin ti nuestra lucha contra la Plaga habría sido prácticamente insuperable. Muchas gracias, $gpoderoso:poderosa; $c.', 0);
-- 5237 ¡Misión cumplida!
-- https://es.classic.wowhead.com/quest=5237
SET @ID := 5237;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n, tu éxito cambiando la estructura de las calderas es una enorme victoria para nosotros!$B$B<El comandante se aclara la garganta y comienza a gritar con fuerza.>$B$BQue todos los que están en mi presencia lo oigan: por los servicios prestados al reino de Ventormenta y a toda la Alianza muy por encima de lo que era de esperar y, añado, por haber superado todos los pronósticos y un peligro inenarrable, concedo esto a $n, y le hago llegar nuestra eterna gratitud como $gun auténtico héroe:una auténtica heroína; de la Alianza. ¡Lancemos nuestros vítores!', 0),
(@ID, 'esMX', '¡$n, tu éxito cambiando la estructura de las calderas es una enorme victoria para nosotros!$B$B<El comandante se aclara la garganta y comienza a gritar con fuerza.>$B$BQue todos los que están en mi presencia lo oigan: por los servicios prestados al reino de Ventormenta y a toda la Alianza muy por encima de lo que era de esperar y, añado, por haber superado todos los pronósticos y un peligro inenarrable, concedo esto a $n, y le hago llegar nuestra eterna gratitud como $gun auténtico héroe:una auténtica heroína; de la Alianza. ¡Lancemos nuestros vítores!', 0);
-- 5238 ¡Misión cumplida!
-- https://es.classic.wowhead.com/quest=5238
SET @ID := 5238;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n, tu éxito cambiando la estructura de las calderas es una enorme victoria para nosotros!$B$B<El Sumo Ejecutor se aclara la garganta y comienza a gritar con fuerza.>$B$BQue todos los que están en mi presencia lo oigan: por los servicios prestados a los Renegados y a toda la Horda muy por encima de lo que era de esperar y, añado, por haber superado todos los pronósticos y un peligro inenarrable, concedo esto a $n, y le hago llegar nuestra eterna gratitud como $gun auténtico héroe:una auténtica heroína; de la Horda. ¡Huzzah!', 0),
(@ID, 'esMX', '¡$n, tu éxito cambiando la estructura de las calderas es una enorme victoria para nosotros!$B$B<El Sumo Ejecutor se aclara la garganta y comienza a gritar con fuerza.>$B$BQue todos los que están en mi presencia lo oigan: por los servicios prestados a los Renegados y a toda la Horda muy por encima de lo que era de esperar y, añado, por haber superado todos los pronósticos y un peligro inenarrable, concedo esto a $n, y le hago llegar nuestra eterna gratitud como $gun auténtico héroe:una auténtica heroína; de la Horda. ¡Huzzah!', 0);
-- 5242 Un golpe final
-- https://es.classic.wowhead.com/quest=5242
SET @ID := 5242;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez eliminado Fel\'dan, el Consejo de la Sombra perderá el norte y comenzarán las luchas internas. Combatirán entre ellos por hacerse con el control del Consejo. Ese será nuestro momento: acabaremos con ellos y con sus esclavos demoníacos.', 0),
(@ID, 'esMX', 'Una vez eliminado Fel\'dan, el Consejo de la Sombra perderá el norte y comenzarán las luchas internas. Combatirán entre ellos por hacerse con el control del Consejo. Ese será nuestro momento: acabaremos con ellos y con sus esclavos demoníacos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bendita sea la Madre Tierra, $n! ¡Gracias! ¡Este es un gran día!$B$BEl Consejo de la Sombra tendrá que luchar para alcanzar los niveles de poder de que gozaban antes de que su jerarquía recibiera este golpe. ¡Hoy has hecho algo grande!', 0),
(@ID, 'esMX', '¡Bendita sea la Madre Tierra, $n! ¡Gracias! ¡Este es un gran día!$B$BEl Consejo de la Sombra tendrá que luchar para alcanzar los niveles de poder de que gozaban antes de que su jerarquía recibiera este golpe. ¡Hoy has hecho algo grande!', 0);
-- 5243 Las casas de lo sagrado
-- https://es.classic.wowhead.com/quest=5243
SET @ID := 5243;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes saber que no todas las cajas de suministros habrán sobrevivido a la destrucción de la ciudad. La Plaga no se atreve a tocar el agua, pero dudo que el agua sagrada impida las infestaciones de alimañas.', 0),
(@ID, 'esMX', 'Debes saber que no todas las cajas de suministros habrán sobrevivido a la destrucción de la ciudad. La Plaga no se atreve a tocar el agua, pero dudo que el agua sagrada impida las infestaciones de alimañas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $r. Has demostrado que, aunque eres $gcompasivo:compasiva;, no te detendrás ante nada para destruir a los esbirros de Kel\'Thuzad.', 0),
(@ID, 'esMX', 'Bien hecho, $r. Has demostrado que, aunque eres $gcompasivo:compasiva;, no te detendrás ante nada para destruir a los esbirros de Kel\'Thuzad.', 0);
-- 5246 Trozos del pasado
-- https://es.classic.wowhead.com/quest=5246
SET @ID := 5246;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sólo consultando las páginas de las sagradas escrituras podré decidir si puedo ayudarte o no.', 0),
(@ID, 'esMX', 'Sólo consultando las páginas de las sagradas escrituras podré decidir si puedo ayudarte o no.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nadie ha tocado estas páginas en muchos, muchos años...', 0),
(@ID, 'esMX', 'Nadie ha tocado estas páginas en muchos, muchos años...', 0);
-- 5247 Trozos del pasado
-- https://es.classic.wowhead.com/quest=5247
SET @ID := 5247;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La reliquia debe ponerse en buenas manos. No la pueden volver a robar...', 0),
(@ID, 'esMX', 'La reliquia debe ponerse en buenas manos. No la pueden volver a robar...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Usando estos elementos, puedo fusionar los fragmentos... con suerte, en lo que una vez fueron.', 0),
(@ID, 'esMX', 'Usando estos elementos, puedo fusionar los fragmentos... con suerte, en lo que una vez fueron.', 0);
-- 5248 Atormentados por el pasado
-- https://es.classic.wowhead.com/quest=5248
SET @ID := 5248;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maldiiiiita... Paaaara sieeeeeempre...', 0),
(@ID, 'esMX', 'Maldiiiiita... Paaaara sieeeeeempre...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Poooor favooooor, libéeeeeerame...', 0),
(@ID, 'esMX', 'Poooor favooooor, libéeeeeerame...', 0);
-- 5249 ¡A la Cuna del Invierno!
-- https://es.classic.wowhead.com/quest=5249
SET @ID := 5249;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un amigo de Ivy Correhoja? Un placer conocerte, $n.', 0),
(@ID, 'esMX', '¿Un amigo de Ivy Correhoja? Un placer conocerte, $n.', 0);
-- 5249 ¡A la Cuna del Invierno!
-- https://es.classic.wowhead.com/quest=5249
SET @ID := 5249;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un amigo de Ivy Correhoja? Un placer conocerte, $n.', 0),
(@ID, 'esMX', '¿Un amigo de Ivy Correhoja? Un placer conocerte, $n.', 0);
-- 5251 El archivista
-- https://es.classic.wowhead.com/quest=5251
SET @ID := 5251;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Archivo quemado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 5252 Altonato arrepentido
-- https://es.classic.wowhead.com/quest=5252
SET @ID := 5252;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha pasado algún tiempo desde que te fuiste, $n. ¿Cómo te ha ido?', 0),
(@ID, 'esMX', 'Ha pasado algún tiempo desde que te fuiste, $n. ¿Cómo te ha ido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es lo que creo que es?', 0),
(@ID, 'esMX', '¿Es lo que creo que es?', 0);
-- 5253 El cristal de Zin-Malor
-- https://es.classic.wowhead.com/quest=5253
SET @ID := 5253;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $r?', 0),
(@ID, 'esMX', '¿Sí, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He oído hablar del Cristal de Zin-Malor; el que usa el cristal adquiere un increíble poder arcano, pero solo si es verdaderamente digno. Me impresiona que no solo hayas recuperado el cristal, sino que también te des cuenta de tus propios límites y no hayas intentado usar el cristal tú $gmismo:misma;.$B$BGracias por traérmelo, $n. Lo mantendremos a salvo, y que los espíritus malditos que una vez protegieron el cristal roto finalmente estén en paz.', 0),
(@ID, 'esMX', 'He oído hablar del Cristal de Zin-Malor; el que usa el cristal adquiere un increíble poder arcano, pero solo si es verdaderamente digno. Me impresiona que no solo hayas recuperado el cristal, sino que también te des cuenta de tus propios límites y no hayas intentado usar el cristal tú $gmismo:misma;.$B$BGracias por traérmelo, $n. Lo mantendremos a salvo, y que los espíritus malditos que una vez protegieron el cristal roto finalmente estén en paz.', 0);
-- 5262 La verdad cae del cielo
-- https://es.classic.wowhead.com/quest=5262
SET @ID := 5262;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué significará esto para la Cruzada? ¿Sería posible que estuvieran bajo el control de este demonio? ¿Obligados a servir como títeres de un mal mucho mayor?', 0),
(@ID, 'esMX', '¿Qué significará esto para la Cruzada? ¿Sería posible que estuvieran bajo el control de este demonio? ¿Obligados a servir como títeres de un mal mucho mayor?', 0);
-- 5263 Por encima y más allá
-- https://es.classic.wowhead.com/quest=5263
SET @ID := 5263;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Barón ha matado a más gente de la que tú has visto en toda tu vida.', 0),
(@ID, 'esMX', 'El Barón ha matado a más gente de la que tú has visto en toda tu vida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace muchos años que no recibo a $gun campeón:una campeona; entre nosotros. Eres $gel primero al:la primera a la; que Lord Maxwell recibe en años.', 0),
(@ID, 'esMX', 'Hace muchos años que no recibo a $gun campeón:una campeona; entre nosotros. Eres $gel primero al:la primera a la; que Lord Maxwell recibe en años.', 0);
-- 5264 Lord Maxwell Neófitus
-- https://es.classic.wowhead.com/quest=5264
SET @ID := 5264;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gun valioso aliado:una valiosa aliada;, $n. Recogerás los frutos de tu incondicional dedicación.', 0),
(@ID, 'esMX', 'Eres $gun valioso aliado:una valiosa aliada;, $n. Recogerás los frutos de tu incondicional dedicación.', 0);
-- 5265 El Bastión Argenta
-- https://es.classic.wowhead.com/quest=5265
SET @ID := 5265;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya...', 0),
(@ID, 'esMX', 'Vaya...', 0);
-- 5282 Espíritus inquietos
-- https://es.classic.wowhead.com/quest=5282
SET @ID := 5282;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Almas liberadas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La compasión es lo que nos separa de los animales, $n. Recuérdalo...', 0),
(@ID, 'esMX', 'La compasión es lo que nos separa de los animales, $n. Recuérdalo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Egan se seca una lágrima del ojo.>$B$B¿Viste a mi madre, $n? ¿La liberaste?$B$BEres un gran ejemplo de decencia. Por las molestias...', 0),
(@ID, 'esMX', '<Egan se seca una lágrima del ojo.>$B$B¿Viste a mi madre, $n? ¿La liberaste?$B$BEres un gran ejemplo de decencia. Por las molestias...', 0);
-- 5283 El arte del forjador de armaduras
-- https://es.classic.wowhead.com/quest=5283
SET @ID := 5283;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, no hay nada como un buen bronceado de forja. Puedes decir quién tiene un bronceado realmente buenos por las líneas de tu delantal.', 0),
(@ID, 'esMX', 'Ah, no hay nada como un buen bronceado de forja. Puedes decir quién tiene un bronceado realmente buenos por las líneas de tu delantal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eso es, $n. Después de esto, no hay forma de volver atrás. No es demasiado tarde para convertirse en fabricante de juguetes,... estooo,... armero.$B$BConfío en que tomarás la decisión correcta.', 0),
(@ID, 'esMX', 'Eso es, $n. Después de esto, no hay forma de volver atrás. No es demasiado tarde para convertirse en fabricante de juguetes,... estooo,... armero.$B$BConfío en que tomarás la decisión correcta.', 0);
-- 5284 El arte del forjador de armas
-- https://es.classic.wowhead.com/quest=5284
SET @ID := 5284;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ironus está ocupado apilando monedas de oro en pequeños montones.>', 0),
(@ID, 'esMX', '<Ironus está ocupado apilando monedas de oro en pequeños montones.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya era hora! Tengo clientes esperando.$B$BDale esto a los de aquí y presta atención. Vas a dar el primer paso en tu carrera como $garmero:armera;.', 0),
(@ID, 'esMX', '¡Ya era hora! Tengo clientes esperando.$B$BDale esto a los de aquí y presta atención. Vas a dar el primer paso en tu carrera como $garmero:armera;.', 0);
-- 5301 El arte del forjador de armaduras
-- https://es.classic.wowhead.com/quest=5301
SET @ID := 5301;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Golpearé el acero hasta perder el aliento.', 0),
(@ID, 'esMX', 'Golpearé el acero hasta perder el aliento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es el último paso antes de comenzar su nueva carrera como $gherrero:herrera;, $n. Si decides echarte atrás, ahora es tu última oportunidad. De lo contrario, prepárate para una vida de gloria.', 0),
(@ID, 'esMX', 'Este es el último paso antes de comenzar su nueva carrera como $gherrero:herrera;, $n. Si decides echarte atrás, ahora es tu última oportunidad. De lo contrario, prepárate para una vida de gloria.', 0);
-- 5302 El arte del forjador de armas
-- https://es.classic.wowhead.com/quest=5302
SET @ID := 5302;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por la gloria de la Horda!', 0),
(@ID, 'esMX', '¡Por la gloria de la Horda!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es el último paso antes de comenzar tu nueva carrera como $garmero:armera;, $n. Si decides echarte atrás, ahora sería tu última oportunidad. De lo contrario, ¡prepárate para ser $gconsumido:consumida; por el conocimiento!', 0),
(@ID, 'esMX', 'Este es el último paso antes de comenzar tu nueva carrera como $garmero:armera;, $n. Si decides echarte atrás, ahora sería tu última oportunidad. De lo contrario, ¡prepárate para ser $gconsumido:consumida; por el conocimiento!', 0);
-- 5305 Dulce serenidad
-- https://es.classic.wowhead.com/quest=5305
SET @ID := 5305;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tu delantal! ¿Dónde está?', 0),
(@ID, 'esMX', '¡Tu delantal! ¿Dónde está?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que golpees muchos cerebros, $n!', 0),
(@ID, 'esMX', '¡Que golpees muchos cerebros, $n!', 0);
