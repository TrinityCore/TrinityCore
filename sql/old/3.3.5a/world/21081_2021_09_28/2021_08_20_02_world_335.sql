-- 9740 El portal solar
-- https://es.wowhead.com/quest=9740
SET @ID := 9740;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Portal solar destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Debes eliminar sus controladores de portal antes de que puedas destruir la puerta!', 0),
(@ID, 'esMX', '¡Debes eliminar sus controladores de portal antes de que puedas destruir la puerta!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Hemos cortado su línea de suministros. ¡Ahora solo tenemos que rematarlos!', 0),
(@ID, 'esMX', '¡Fantástico! Hemos cortado su línea de suministros. ¡Ahora solo tenemos que rematarlos!', 0);
-- 10432 Pruebas condenatorias
-- https://es.wowhead.com/quest=10432
SET @ID := 10432;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien? ¿Qué te ha dicho Theledorn?', 0),
(@ID, 'esMX', '¿Y bien? ¿Qué te ha dicho Theledorn?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es grande, $n. ¡Muy grande!$B$BVoren\'thal querrá enterarse de todo rápidamente.', 0),
(@ID, 'esMX', 'Esto es grande, $n. ¡Muy grande!$B$BVoren\'thal querrá enterarse de todo rápidamente.', 0);
-- 10433 Guardando las apariencias
-- https://es.wowhead.com/quest=10433
SET @ID := 10433;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Shauly alza la voz para atraer la atención de los etéreos de la zona.>$B$B¿Tienes alguna pelambre que venderme?', 0),
(@ID, 'esMX', '<Shauly alza la voz para atraer la atención de los etéreos de la zona.>$B$B¿Tienes alguna pelambre que venderme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Shauly admira las pelambres ostentosamente.>$B$B¡Son magníficas, totalmente magníficas! ¡Te pagaré muy bien por ellas! ¿Cuánto por tus servicios?', 0),
(@ID, 'esMX', '<Shauly admira las pelambres ostentosamente.>$B$B¡Son magníficas, totalmente magníficas! ¡Te pagaré muy bien por ellas! ¿Cuánto por tus servicios?', 0);
-- 10434 El dúo dinámico
-- https://es.wowhead.com/quest=10434
SET @ID := 10434;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Te presentas y le dices a Audi que Shauly te envía.>$B$BAh, sí, esperábamos a alguien que nos ayudara ah, eh... mover algunas, eh... mercancías.', 0),
(@ID, 'esMX', '<Te presentas y le dices a Audi que Shauly te envía.>$B$BAh, sí, esperábamos a alguien que nos ayudara ah, eh... mover algunas, eh... mercancías.', 0);
-- 10435 Recuperar las mercancías
-- https://es.wowhead.com/quest=10435
SET @ID := 10435;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has conseguido todo?', 0),
(@ID, 'esMX', '¿Lo has conseguido todo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente trabajo! La parte más difícil del proyecto está hecha. Ahora, todo lo que necesitamos es una forma de devolverlos al Área 52 y también atraer el interés de la Expedición Cenarion. Debería haber suficiente aquí para nuestras necesidades y para, además, obtener algunos beneficios.', 0),
(@ID, 'esMX', '¡Excelente trabajo! La parte más difícil del proyecto está hecha. Ahora, todo lo que necesitamos es una forma de devolverlos al Área 52 y también atraer el interés de la Expedición Cenarion. Debería haber suficiente aquí para nuestras necesidades y para, además, obtener algunos beneficios.', 0);
-- 10436 ¡Todo despejado!
-- https://es.wowhead.com/quest=10436
SET @ID := 10436;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has despejado el área de prueba?', 0),
(@ID, 'esMX', '¿Has despejado el área de prueba?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Parece que todo está en orden. Estamos listos para empezar.', 0),
(@ID, 'esMX', 'Muy bien. Parece que todo está en orden. Estamos listos para empezar.', 0);
-- 10437 Receta para la destrucción
-- https://es.wowhead.com/quest=10437
SET @ID := 10437;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has reunido suficientes fragmentos?', 0),
(@ID, 'esMX', '¿Has reunido suficientes fragmentos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Con estos fragmentos, podemos calibrar una bomba que destruirá el conducto del vacío que se encuentra sobre Ultris. Una vez destruido el conducto del vacío, la conexión de Dimensius con el vacío se cortará ¡y se quedará indefenso!', 0),
(@ID, 'esMX', '¡Excelente! Con estos fragmentos, podemos calibrar una bomba que destruirá el conducto del vacío que se encuentra sobre Ultris. Una vez destruido el conducto del vacío, la conexión de Dimensius con el vacío se cortará ¡y se quedará indefenso!', 0);
-- 10438 En alas abisales
-- https://es.wowhead.com/quest=10438
SET @ID := 10438;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Conducto del Vacío destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has triunfado?', 0),
(@ID, 'esMX', '¿Has triunfado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ha llegado la hora de atacar! ¡Con la lágrima desaparecida, Dimensius es vulnerable a los ataques físicos y mágicos!', 0),
(@ID, 'esMX', '¡Ha llegado la hora de atacar! ¡Con la lágrima desaparecida, Dimensius es vulnerable a los ataques físicos y mágicos!', 0);
-- 10439 Dimensius el Devoratodo
-- https://es.wowhead.com/quest=10439
SET @ID := 10439;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Habla con el capitán Saeed', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué pasa con el señor del vacío?', 0),
(@ID, 'esMX', '¿Qué pasa con el señor del vacío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Durante un milenio solo hemos conocido el conflicto. Hemos defendido a nuestro pueblo de los ataques de las alimañas del vacío y etéreas.$B$BAhora, uno de nuestros más odiados enemigos yace muerto, por fin.$B$BTe doy las gracias de parte de cien millones de etéreos, ser de carne.', 0),
(@ID, 'esMX', 'Durante un milenio solo hemos conocido el conflicto. Hemos defendido a nuestro pueblo de los ataques de las alimañas del vacío y etéreas.$B$BAhora, uno de nuestros más odiados enemigos yace muerto, por fin.$B$BTe doy las gracias de parte de cien millones de etéreos, ser de carne.', 0);
-- 10440 ¡Éxito!
-- https://es.wowhead.com/quest=10440
SET @ID := 10440;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora mismo pondré a mis técnicos a trabajar en esas reparaciones.$B$BAunque la sospecha de Tashar de que se produzca algún sabotaje me preocupa. No se me ocurre nadie que sea lo suficientemente audaz para robar nuestra tecnología. Nadie que sepa de lo que somos capaces, en cualquier caso. Podría haber llegado la hora de cerrar La Flecha de la Tormenta.', 0),
(@ID, 'esMX', 'Ahora mismo pondré a mis técnicos a trabajar en esas reparaciones.$B$BAunque la sospecha de Tashar de que se produzca algún sabotaje me preocupa. No se me ocurre nadie que sea lo suficientemente audaz para robar nuestra tecnología. Nadie que sepa de lo que somos capaces, en cualquier caso. Podría haber llegado la hora de cerrar La Flecha de la Tormenta.', 0);
-- 10442 Ayudar al Puesto Cenarion
-- https://es.wowhead.com/quest=10442
SET @ID := 10442;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, cielos, debes de ser la ayuda que pedí hace semanas a la Avanzada del Halcón.$B$BBien, estás aquí ahora y hay mucho por hacer. Tengo justo lo que te hace falta para empezar.', 0),
(@ID, 'esMX', 'Oh, cielos, debes de ser la ayuda que pedí hace semanas a la Avanzada del Halcón.$B$BBien, estás aquí ahora y hay mucho por hacer. Tengo justo lo que te hace falta para empezar.', 0);
-- 10443 Ayudar al Puesto Cenarion
-- https://es.wowhead.com/quest=10443
SET @ID := 10443;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, cielos, debes de ser la ayuda que pedí al Templo de Telhamat.$B$BMe alegro de que estés aquí; hay mucho por hacer y tengo justo lo que te hace falta para empezar.', 0),
(@ID, 'esMX', 'Oh, cielos, debes de ser la ayuda que pedí al Templo de Telhamat.$B$BMe alegro de que estés aquí; hay mucho por hacer y tengo justo lo que te hace falta para empezar.', 0);
-- 10444 Informa en el Puesto Allerian
-- https://es.wowhead.com/quest=10444
SET @ID := 10444;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Piezas de bombas. Así que estaba en lo cierto. Y mira que no me habría importado equivocarme en eso.$B$BBueno, pues parece que nos espera un lúgubre asunto.', 0),
(@ID, 'esMX', 'Piezas de bombas. Así que estaba en lo cierto. Y mira que no me habría importado equivocarme en eso.$B$BBueno, pues parece que nos espera un lúgubre asunto.', 0);
-- 10445 Los viales de la eternidad
-- https://es.wowhead.com/quest=10445
SET @ID := 10445;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te he pedido lo imposible, pero espero que tengas éxito. Mucho depende de ello.', 0),
(@ID, 'esMX', 'Te he pedido lo imposible, pero espero que tengas éxito. Mucho depende de ello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te he pedido lo imposible, pero espero que tengas éxito. Mucho depende de ello.', 0),
(@ID, 'esMX', 'Te he pedido lo imposible, pero espero que tengas éxito. Mucho depende de ello.', 0);
-- 10446 El código final
-- https://es.wowhead.com/quest=10446
SET @ID := 10446;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Bomba de maná activada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El teniente Meridiano nos ha mantenido informados de la situación en el Alto Ala de Fuego. ¿Está todo bien?', 0),
(@ID, 'esMX', 'El teniente Meridiano nos ha mantenido informados de la situación en el Alto Ala de Fuego. ¿Está todo bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡LO HAS CONSEGUIDO! ¡NOS HAS SALVADO! ¡¡HAS SALVADO EL BASTIÓN ALLERIAN!!$B$BCon sus tropas diezmadas, su líder muerto y la bomba de maná destruida, todos podemos respirar con mucha más facilidad ahora.$B$B$n, nunca había visto tanto altruismo... ¡tanto heroísmo! Te lo ruego, acepta esto en nombre de todos nosotros.', 0),
(@ID, 'esMX', '¡LO HAS CONSEGUIDO! ¡NOS HAS SALVADO! ¡¡HAS SALVADO EL BASTIÓN ALLERIAN!!$B$BCon sus tropas diezmadas, su líder muerto y la bomba de maná destruida, todos podemos respirar con mucha más facilidad ahora.$B$B$n, nunca había visto tanto altruismo... ¡tanto heroísmo! Te lo ruego, acepta esto en nombre de todos nosotros.', 0);
-- El código final
-- 10446, 10447
-- https://es.wowhead.com/quest=10446
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Bomba de maná activada', `VerifiedBuild` = 0 WHERE `id` IN(10446, 10447) AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10446, 10447) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10446, 'esES', 'El teniente Meridiano nos ha mantenido informados de la situación en el Alto Ala de Fuego. ¿Está todo bien?', 0),
(10447, 'esES', 'El teniente Meridiano nos ha mantenido informados de la situación en el Alto Ala de Fuego. ¿Está todo bien?', 0),
(10446, 'esMX', 'El teniente Meridiano nos ha mantenido informados de la situación en el Alto Ala de Fuego. ¿Está todo bien?', 0),
(10447, 'esMX', 'El teniente Meridiano nos ha mantenido informados de la situación en el Alto Ala de Fuego. ¿Está todo bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10446, 10447) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10446, 'esES', '¡LO HAS CONSEGUIDO! ¡NOS HAS SALVADO! ¡¡HAS SALVADO EL BASTIÓN ALLERIAN!!$B$BCon sus tropas diezmadas, su líder muerto y la bomba de maná destruida, todos podemos respirar con mucha más facilidad ahora.$B$B$n, nunca había visto tanto altruismo... ¡tanto heroísmo! Te lo ruego, acepta esto en nombre de todos nosotros.', 0),
(10447, 'esES', '¡LO HAS CONSEGUIDO! ¡NOS HAS SALVADO! ¡¡HAS SALVADO EL BASTIÓN ALLERIAN!!$B$BCon sus tropas diezmadas, su líder muerto y la bomba de maná destruida, todos podemos respirar con mucha más facilidad ahora.$B$B$n, nunca había visto tanto altruismo... ¡tanto heroísmo! Te lo ruego, acepta esto en nombre de todos nosotros.', 0),
(10446, 'esMX', '¡LO HAS CONSEGUIDO! ¡NOS HAS SALVADO! ¡¡HAS SALVADO EL BASTIÓN ALLERIAN!!$B$BCon sus tropas diezmadas, su líder muerto y la bomba de maná destruida, todos podemos respirar con mucha más facilidad ahora.$B$B$n, nunca había visto tanto altruismo... ¡tanto heroísmo! Te lo ruego, acepta esto en nombre de todos nosotros.', 0),
(10447, 'esMX', '¡LO HAS CONSEGUIDO! ¡NOS HAS SALVADO! ¡¡HAS SALVADO EL BASTIÓN ALLERIAN!!$B$BCon sus tropas diezmadas, su líder muerto y la bomba de maná destruida, todos podemos respirar con mucha más facilidad ahora.$B$B$n, nunca había visto tanto altruismo... ¡tanto heroísmo! Te lo ruego, acepta esto en nombre de todos nosotros.', 0);
-- 10448 Preséntate en el Campamento Rompepedras
-- https://es.wowhead.com/quest=10448
SET @ID := 10448;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Componentes de bombas. Así que mis sospechas eran ciertas. Y no quería tener razón sobre eso.$B$BMuy bien, tú y yo tenemos por delante bastante trabajo y nada sencillo.', 0),
(@ID, 'esMX', 'Componentes de bombas. Así que mis sospechas eran ciertas. Y no quería tener razón sobre eso.$B$BMuy bien, tú y yo tenemos por delante bastante trabajo y nada sencillo.', 0);
-- 10449 La boticaria Zelana
-- https://es.wowhead.com/quest=10449
SET @ID := 10449;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un honor cumplir los deseos de la Horda. ¿Cómo puedo ayudarte?', 0),
(@ID, 'esMX', 'Es un honor cumplir los deseos de la Horda. ¿Cómo puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. La sangre del clan Mascahuesos. Siento mucha curiosidad por estos orcos... Aún son los depravados demonios del pasado, pero su fuerza y poder es mayor de lo que había oído...$B$BBueno, comencemos. ¿Te parece?', 0),
(@ID, 'esMX', 'Ah, sí. La sangre del clan Mascahuesos. Siento mucha curiosidad por estos orcos... Aún son los depravados demonios del pasado, pero su fuerza y poder es mayor de lo que había oído...$B$BBueno, comencemos. ¿Te parece?', 0);
-- 10450 Sangre de Mascahuesos
-- https://es.wowhead.com/quest=10450
SET @ID := 10450;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te enfrentaste a los Mascahuesos, $n? ¡Espero que derramases su sangre por doquier!', 0),
(@ID, 'esMX', '¿Te enfrentaste a los Mascahuesos, $n? ¡Espero que derramases su sangre por doquier!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! Así que ya has conocido a los Mascahuesos, nuestros depravados primos. Bien hecho, $n. Solo lamento que no hayan caído más de ellos y derramado más sangre... ¡para calmar mi rabia!', 0),
(@ID, 'esMX', '¡Ja! Así que ya has conocido a los Mascahuesos, nuestros depravados primos. Bien hecho, $n. Solo lamento que no hayan caído más de ellos y derramado más sangre... ¡para calmar mi rabia!', 0);
-- 10451 Huida de la Cisterna Cicatriz Espiral
-- https://es.wowhead.com/quest=10451
SET @ID := 10451;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste a la hermana Wilda?', 0),
(@ID, 'esMX', '¿Encontraste a la hermana Wilda?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alabada sea la Madre Tierra. Estoy seguro de que Wilda encontrará el camino a casa. Acepta esto como muestra de nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Alabada sea la Madre Tierra. Estoy seguro de que Wilda encontrará el camino a casa. Acepta esto como muestra de nuestro agradecimiento.', 0);
-- 10455 La naturaleza invasora
-- https://es.wowhead.com/quest=10455
SET @ID := 10455;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No dije la verdad? Los Linces acecharboleda se han convertido en una amenaza no solo para aquellos que viajan por el camino, sino también para Sylvanaar.$B$BSus muertes son lamentables, pero el objetivo de nuestra creación de La Arboleda Viviente es que Sylvanaar pueda estar rodeado por una región defensiva de belleza natural y tranquilidad.', 0),
(@ID, 'esMX', '¿No dije la verdad? Los Linces acecharboleda se han convertido en una amenaza no solo para aquellos que viajan por el camino, sino también para Sylvanaar.$B$BSus muertes son lamentables, pero el objetivo de nuestra creación de La Arboleda Viviente es que Sylvanaar pueda estar rodeado por una región defensiva de belleza natural y tranquilidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué rapidez! ¿Seguro que has matado todos los que has podido?$B$BMuy bien, hay algo más con lo que puedes ayudarnos.', 0),
(@ID, 'esMX', '¡Qué rapidez! ¿Seguro que has matado todos los que has podido?$B$BMuy bien, hay algo más con lo que puedes ayudarnos.', 0);
