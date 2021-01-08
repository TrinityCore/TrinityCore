-- 528 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=528
SET @ID := 528;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes tus órdenes, $c. Deje de perder el tiempo aquí en Molino Tarren cuando hay trabajo que hacer en otro lugar.', 0),
(@ID, 'esMX', 'Tienes tus órdenes, $c. Deje de perder el tiempo aquí en Molino Tarren cuando hay trabajo que hacer en otro lugar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte cierra el cerco en torno a Trabalomas. La batalla va bien.', 0),
(@ID, 'esMX', 'La muerte cierra el cerco en torno a Trabalomas. La batalla va bien.', 0);
-- 529 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=529
SET @ID := 529;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cumpliste la misión, $c? ¿Eliminaste a Verringtan y sus aprendices? ¿Dónde está el cargamento de hierro?', 0),
(@ID, 'esMX', '¿Cumpliste la misión, $c? ¿Eliminaste a Verringtan y sus aprendices? ¿Dónde está el cargamento de hierro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Misión cumplida, $c. Y cumplida con gran talento, además.', 0),
(@ID, 'esMX', 'Misión cumplida, $c. Y cumplida con gran talento, además.', 0);
-- 530 La venganza de un esposo
-- https://es.classic.wowhead.com/quest=530
SET @ID := 530;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las manos, $n?', 0),
(@ID, 'esMX', '¿Tienes las manos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bien. Estas son las manos que dieron muerte a mi esposa, Deliah. Lo único que quería era vengarme de su asesino, y tú lo has hecho posible.$B$BToma, quédate el anillo que me trajiste. Hace tanto tiempo de la muerte de Deliah, que ya no significa nada para mí. Las manos, sin embargo, las conservaré para recordar la traición del que fue mi amigo.', 0),
(@ID, 'esMX', 'Ah, bien. Estas son las manos que dieron muerte a mi esposa, Deliah. Lo único que quería era vengarme de su asesino, y tú lo has hecho posible.$B$BToma, quédate el anillo que me trajiste. Hace tanto tiempo de la muerte de Deliah, que ya no significa nada para mí. Las manos, sin embargo, las conservaré para recordar la traición del que fue mi amigo.', 0);
-- 532 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=532
SET @ID := 532;
UPDATE `quest_template_locale` SET `ObjectiveText3` = 'Has destruido la Declaración de Trabalomas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué nuevas me traes?', 0),
(@ID, 'esMX', '¿Qué nuevas me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos ha llegado el relato de tus proezas en Trabalomas. Buen trabajo, $c.', 0),
(@ID, 'esMX', 'Nos ha llegado el relato de tus proezas en Trabalomas. Buen trabajo, $c.', 0);
-- 533 Infiltración
-- https://es.classic.wowhead.com/quest=533
SET @ID := 533;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has averiguado algo? Cuanto más tiempo pasa, menos posibilidades tiene Gol\'dir...', 0),
(@ID, 'esMX', '¿Has averiguado algo? Cuanto más tiempo pasa, menos posibilidades tiene Gol\'dir...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al fin hemos sabido dónde está Gol\'dir. El campamento no está lejos y esperamos que no estén tan bien preparados como la otra vez.', 0),
(@ID, 'esMX', 'Al fin hemos sabido dónde está Gol\'dir. El campamento no está lejos y esperamos que no estén tan bien preparados como la otra vez.', 0);
-- 535 Valik
-- https://es.classic.wowhead.com/quest=535
SET @ID := 535;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído una copa o has regresado para rematar el trabajo?', 0),
(@ID, 'esMX', '¿Me has traído una copa o has regresado para rematar el trabajo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dada mi inminente muerte, creo que puedo decir, sin temor a equivocarme, que esta es la más dulce... Toma, llévate esto, no me hará ninguna falta cuando haya muerto.$B$BBueno, ¡acaba de una vez!', 0),
(@ID, 'esMX', 'Dada mi inminente muerte, creo que puedo decir, sin temor a equivocarme, que esta es la más dulce... Toma, llévate esto, no me hará ninguna falta cuando haya muerto.$B$BBueno, ¡acaba de una vez!', 0);
-- 538 Costasur
-- https://es.classic.wowhead.com/quest=538
SET @ID := 538;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, recuerdo a Milton. Un ratón de biblioteca sin duda alguna. Bendito sea.$B$BY tiene razón. Todavía quedan textos en las Ruinas de Alterac que corren el peligro de desaparecer para siempre.$B$BAhora Alterac está lleno de ogros y no es que les importe mucho el aprendizaje y el conocimiento.', 0),
(@ID, 'esMX', 'Ah, sí, recuerdo a Milton. Un ratón de biblioteca sin duda alguna. Bendito sea.$B$BY tiene razón. Todavía quedan textos en las Ruinas de Alterac que corren el peligro de desaparecer para siempre.$B$BAhora Alterac está lleno de ogros y no es que les importe mucho el aprendizaje y el conocimiento.', 0);
-- 539 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=539
SET @ID := 539;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recibiste órdenes directas de atacar la Mina Azur. Es mejor que tus razones para holgazanear por Molino Tarren sean buenas o te decapitaré por traición.', 0),
(@ID, 'esMX', 'Recibiste órdenes directas de atacar la Mina Azur. Es mejor que tus razones para holgazanear por Molino Tarren sean buenas o te decapitaré por traición.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A la Dama Oscura le gustará saber que dispone de otra mina con la que abastecer de armas a sus soldados.', 0),
(@ID, 'esMX', 'A la Dama Oscura le gustará saber que dispone de otra mina con la que abastecer de armas a sus soldados.', 0);
-- 540 Proteger el conocimiento
-- https://es.classic.wowhead.com/quest=540
SET @ID := 540;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me gustaría ir contigo, pero ya estoy mayor para andar explorando por ahí. Dime, ¿cómo va tu búsqueda de conocimiento, $n?', 0),
(@ID, 'esMX', 'Me gustaría ir contigo, pero ya estoy mayor para andar explorando por ahí. Dime, ¿cómo va tu búsqueda de conocimiento, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Empezaré a estudiar el Arma de Gri\'lek de inmediato!', 0),
(@ID, 'esMX', '¡Excelente! ¡Empezaré a estudiar el Arma de Gri\'lek de inmediato!', 0);
-- 541 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=541
SET @ID := 541;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dun Garok es mucho para ti, $c? Y yo que pensé que te habías establecido valientemente en Trabalomas.$B$BSi no estás $gpreparado:preparada; para la misión que se te asignó, buscaré otro que pueda dar mejores resultados. En cuanto a ti, bueno, estoy seguro de que la Dama Oscura siempre podría necesitar más sepultureros en los Claros de Tirisfal.', 0),
(@ID, 'esMX', '¿Dun Garok es mucho para ti, $c? Y yo que pensé que te habías establecido valientemente en Trabalomas.$B$BSi no estás $gpreparado:preparada; para la misión que se te asignó, buscaré otro que pueda dar mejores resultados. En cuanto a ti, bueno, estoy seguro de que la Dama Oscura siempre podría necesitar más sepultureros en los Claros de Tirisfal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus hazañas en el campo de batalla merecen las mayores alabanzas.', 0),
(@ID, 'esMX', 'Tus hazañas en el campo de batalla merecen las mayores alabanzas.', 0);
-- 542 Regresa junto a Milton
-- https://es.classic.wowhead.com/quest=542
SET @ID := 542;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto, $n! ¿Qué tal en Alterac? ¿Traes algo?', 0),
(@ID, 'esMX', '¡Has vuelto, $n! ¿Qué tal en Alterac? ¿Traes algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo creer que todo esto haya sobrevivido a la hecatombe de Alterac.$B$B¡Muchas gracias, $n! Has ayudado a preservar una fuente de conocimiento y a enriquecer el Archivo Real de Ventormenta.', 0),
(@ID, 'esMX', 'No puedo creer que todo esto haya sobrevivido a la hecatombe de Alterac.$B$B¡Muchas gracias, $n! Has ayudado a preservar una fuente de conocimiento y a enriquecer el Archivo Real de Ventormenta.', 0);
-- 544 Colarse en la cárcel
-- https://es.classic.wowhead.com/quest=544
SET @ID := 544;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste a los traidores? ¿Traes lo que robaron?', 0),
(@ID, 'esMX', '¿Encontraste a los traidores? ¿Traes lo que robaron?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has rendido un gran servicio a los Renegados, $n; tenemos estos objetos en gran estima.$B$BMe alegro de que los culpables hayan recibido su merecido.', 0),
(@ID, 'esMX', 'Has rendido un gran servicio a los Renegados, $n; tenemos estos objetos en gran estima.$B$BMe alegro de que los culpables hayan recibido su merecido.', 0);
-- 545 Las patrullas de Dalaran
-- https://es.classic.wowhead.com/quest=545
SET @ID := 545;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha reducido las patrullas de Dalaran alrededor de sus ruinas?', 0),
(@ID, 'esMX', '¿Ha reducido las patrullas de Dalaran alrededor de sus ruinas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente; ahora podré explorar las ruinas.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'Excelente; ahora podré explorar las ruinas.$B$BGracias, $n.', 0);
-- 546 Recuerdos de muerte
-- https://es.classic.wowhead.com/quest=546
SET @ID := 546;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás aquí, $n? ¿A cuántos humanos liquidaste? ¡Espero que a cientos!$B$B¿Traes las calaveras?', 0),
(@ID, 'esMX', '¿Ya estás aquí, $n? ¿A cuántos humanos liquidaste? ¡Espero que a cientos!$B$B¿Traes las calaveras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué magníficas calaveras! Ten tu recompensa, $n!', 0),
(@ID, 'esMX', '¡Qué magníficas calaveras! Ten tu recompensa, $n!', 0);
-- 547 La espada de Humbert
-- https://es.classic.wowhead.com/quest=547
SET @ID := 547;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi espada, $n? La suma ejecutora Darthalia me colgará si se entera de que la perdí.', 0),
(@ID, 'esMX', '¿Tienes mi espada, $n? La suma ejecutora Darthalia me colgará si se entera de que la perdí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La encontraste!$B$BAh, qué bien sienta sostener la espada otra vez.', 0),
(@ID, 'esMX', '¡La encontraste!$B$BAh, qué bien sienta sostener la espada otra vez.', 0);
-- 549 SE BUSCA: Personal de la Hermandad
-- https://es.classic.wowhead.com/quest=549
SET @ID := 549;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No tienes nada mejor que hacer que estar aquí delante de mí, $c? Como Sumo Ejecutor, tengo asuntos más urgentes que mirar tu rostro podrido.', 0),
(@ID, 'esMX', '¿No tienes nada mejor que hacer que estar aquí delante de mí, $c? Como Sumo Ejecutor, tengo asuntos más urgentes que mirar tu rostro podrido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $c. Pronto conseguiremos librarnos definitivamente de la Hermandad.', 0),
(@ID, 'esMX', 'Excelente, $c. Pronto conseguiremos librarnos definitivamente de la Hermandad.', 0);
-- 550 La batalla de Trabalomas
-- https://es.classic.wowhead.com/quest=550
SET @ID := 550;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué estás en Entrañas y no en el campo de batalla, $c?', 0),
(@ID, 'esMX', '¿Por qué estás en Entrañas y no en el campo de batalla, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que eres tú quien asestó el golpe mortal a las fuerzas de la Alianza en las Laderas de Trabalomas? Tu fama ha llegado hasta Entrañas.$B$BSigue así y te espera un futuro brillante en las filas de la Dama Oscura.$B$BAunque la amenaza principal es la Peste del rey Exánime por el norte, no podemos olvidarnos de los humanos. Pero tú has demostrado que es posible derrotarlos.', 0),
(@ID, 'esMX', '¿Así que eres tú quien asestó el golpe mortal a las fuerzas de la Alianza en las Laderas de Trabalomas? Tu fama ha llegado hasta Entrañas.$B$BSigue así y te espera un futuro brillante en las filas de la Dama Oscura.$B$BAunque la amenaza principal es la Peste del rey Exánime por el norte, no podemos olvidarnos de los humanos. Pero tú has demostrado que es posible derrotarlos.', 0);
-- 551 El papiro encantado
-- https://es.classic.wowhead.com/quest=551
SET @ID := 551;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh. ¿Tienes algo que te gustaría que viera? Algún resto de tradición recolectado en las montañas, espero...', 0),
(@ID, 'esMX', 'Oh. ¿Tienes algo que te gustaría que viera? Algún resto de tradición recolectado en las montañas, espero...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Más notas cifradas?$B$BOjalá tuviera el talento para descifrar todos estos extraños signos que nos llegan de Alterac. Pero me temo que me falta el conocimiento necesario.', 0),
(@ID, 'esMX', '¿Más notas cifradas?$B$BOjalá tuviera el talento para descifrar todos estos extraños signos que nos llegan de Alterac. Pero me temo que me falta el conocimiento necesario.', 0);
-- 552 La venganza de Helcular
-- https://es.classic.wowhead.com/quest=552
SET @ID := 552;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes la Vara de Helcular? Hay tantos yetis por aquí que será difícil dar con ella, pero la necesitamos.', 0),
(@ID, 'esMX', '¿Ya tienes la Vara de Helcular? Hay tantos yetis por aquí que será difícil dar con ella, pero la necesitamos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Magnífico!', 0),
(@ID, 'esMX', '¡Magnífico!', 0);
-- 553 La venganza de Helcular
-- https://es.classic.wowhead.com/quest=553
SET @ID := 553;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Has cargado la Llama de Azel', `ObjectiveText2` = 'Has cargado la Llama de Veraz', `ObjectiveText3` = 'Has cargado la Llama de Uzel', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De la tumba de Helcular emana una energía mística.', 0),
(@ID, 'esMX', 'De la tumba de Helcular emana una energía mística.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oyes un rugido procedente del subsuelo.', 0),
(@ID, 'esMX', 'Oyes un rugido procedente del subsuelo.', 0);
 -- 554 La descodificación de Pico Tormenta
-- https://es.classic.wowhead.com/quest=554
SET @ID := 554;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Otra interrupción?!$B$BAh, este pergamino está protegido por un hechizo muy complicado. Puedo descifrarlo, pero me llevará tiempo y no tengo mucho...$B$B¿Y si me lo vendes?', 0),
(@ID, 'esMX', '¡¿Otra interrupción?!$B$BAh, este pergamino está protegido por un hechizo muy complicado. Puedo descifrarlo, pero me llevará tiempo y no tengo mucho...$B$B¿Y si me lo vendes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabia decisión. Soy el único que puede descifrarlo. Y no te preocupes, te informaré de su contenido.', 0),
(@ID, 'esMX', 'Sabia decisión. Soy el único que puede descifrarlo. Y no te preocupes, te informaré de su contenido.', 0);
-- 637 La carta de Sully Balloo
-- https://es.classic.wowhead.com/quest=637
SET @ID := 637;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que hayas recorrido una gran distancia y visto gran caos en tu vida, $c. Los tiempos que vivimos ponen a prueba el alma. ¿Qué noticias me traes?', 0),
(@ID, 'esMX', 'Parece que hayas recorrido una gran distancia y visto gran caos en tu vida, $c. Los tiempos que vivimos ponen a prueba el alma. ¿Qué noticias me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que viste a mi Sully tendido sin vida bajo las aguas heladas? ¡Dime que no es así!$B$BDéjame leer lo que escribió...', 0),
(@ID, 'esMX', '¿Dices que viste a mi Sully tendido sin vida bajo las aguas heladas? ¡Dime que no es así!$B$BDéjame leer lo que escribió...', 0);
-- 638 Aterratrols
-- https://es.classic.wowhead.com/quest=638
SET @ID := 638;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal te va, $c? La tarea que nos ha propuesto Vol\'jin será difícil y cualquier ayuda que puedas proporcionarnos, será más que apreciada.', 0),
(@ID, 'esMX', '¿Qué tal te va, $c? La tarea que nos ha propuesto Vol\'jin será difícil y cualquier ayuda que puedas proporcionarnos, será más que apreciada.', 0);
-- 639 El sigilo de Strom
-- https://es.classic.wowhead.com/quest=639
SET @ID := 639;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado ya el primer sigilo? Lo más probable es que lo lleve encima uno de los agentes de la Hermandad de Stromgarde.', 0),
(@ID, 'esMX', '¿Has encontrado ya el primer sigilo? Lo más probable es que lo lleve encima uno de los agentes de la Hermandad de Stromgarde.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fantástico, colega. Es un buen comienzo para reunir los sigilos que necesitamos para extraer a Trol\'kalar de la tumba de Aterratrols.', 0),
(@ID, 'esMX', 'Fantástico, colega. Es un buen comienzo para reunir los sigilos que necesitamos para extraer a Trol\'kalar de la tumba de Aterratrols.', 0);
