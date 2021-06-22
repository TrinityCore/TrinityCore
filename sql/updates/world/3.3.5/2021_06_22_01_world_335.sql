-- 10226 Extracción de energía elemental
-- https://es.wowhead.com/quest=10226
SET @ID := 10226;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya la energía de esos elementales? Bueno, tampoco te des tanta prisa... que solo están en juego mi carrera y mi vida.', 0),
(@ID, 'esMX', '¿Tienes ya la energía de esos elementales? Bueno, tampoco te des tanta prisa... que solo están en juego mi carrera y mi vida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso ya me gusta más! Muy bien, ahora podemos funcionar.$B$BDeja que eche esto en el cacharro mágico este y seguro que escupirá un núcleo de motor de fase completamente operativo.$B$BAh, oye, ¡y supongo que te debo una recompensa por salvarme el cuello! Jeje.', 0),
(@ID, 'esMX', '¡Eso ya me gusta más! Muy bien, ahora podemos funcionar.$B$BDeja que eche esto en el cacharro mágico este y seguro que escupirá un núcleo de motor de fase completamente operativo.$B$BAh, oye, ¡y supongo que te debo una recompensa por salvarme el cuello! Jeje.', 0);
-- 10227 Veo draenei muertos
-- https://es.wowhead.com/quest=10227
SET @ID := 10227;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El niño dice la verdad. Yo fui un sacerdote de la muerte.$B$B<Ramdor hace una mueca.>$B$BQué título tan desagradable.$B$BAl final de ese corredor están las Criptas Auchenai. Dentro encontrarás a lo que queda de mi priorato. Están todos locos, por supuesto. Supongo que yo destacaba bastante, ya que era el único al que le quedaba algo de sentido común. Y naturalmente, fui excomulgado por mis creencias.$B$B¿Que cuáles son, dices?', 0),
(@ID, 'esMX', 'El niño dice la verdad. Yo fui un sacerdote de la muerte.$B$B<Ramdor hace una mueca.>$B$BQué título tan desagradable.$B$BAl final de ese corredor están las Criptas Auchenai. Dentro encontrarás a lo que queda de mi priorato. Están todos locos, por supuesto. Supongo que yo destacaba bastante, ya que era el único al que le quedaba algo de sentido común. Y naturalmente, fui excomulgado por mis creencias.$B$B¿Que cuáles son, dices?', 0);
-- 10228 Ezekiel
-- https://es.wowhead.com/quest=10228
SET @ID := 10228;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Libro sobre los Muertos? Nunca he oído hablar de él. ¿Qué sucede? ¿Quién te envía?', 0),
(@ID, 'esMX', '¿El Libro sobre los Muertos? Nunca he oído hablar de él. ¿Qué sucede? ¿Quién te envía?', 0);
-- 10229 Descifrar el escrito
-- https://es.wowhead.com/quest=10229
SET @ID := 10229;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¿Un libro que un espíritu Implacable llevaba? Qué extraño. Déjamelo que lo estudie, quizás pueda aprender algo de la historia de los Implacables.', 0),
(@ID, 'esMX', '¿Qué es esto? ¿Un libro que un espíritu Implacable llevaba? Qué extraño. Déjamelo que lo estudie, quizás pueda aprender algo de la historia de los Implacables.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estudié historia antigua durante toda mi no-vida. Nunca vi nada parecido a este libro. Cuenta toda la historia de la Armería, incluidos los acontecimientos que ocurrieron después de su destrucción.$B$BLos Implacables conservaron su historia incluso después de caer en la batalla. Con este libro podremos entender a los Implacables y convencerlos de que se unan a nosotros.', 0),
(@ID, 'esMX', 'Estudié historia antigua durante toda mi no-vida. Nunca vi nada parecido a este libro. Cuenta toda la historia de la Armería, incluidos los acontecimientos que ocurrieron después de su destrucción.$B$BLos Implacables conservaron su historia incluso después de caer en la batalla. Con este libro podremos entender a los Implacables y convencerlos de que se unan a nosotros.', 0);
-- 10230 El cuerno de batalla
-- https://es.wowhead.com/quest=10230
SET @ID := 10230;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos ayudar a los Implacables pronto. Si logramos convencerlos de que se unan a la Horda, habremos conseguido un poderoso aliado.', 0),
(@ID, 'esMX', 'Debemos ayudar a los Implacables pronto. Si logramos convencerlos de que se unan a la Horda, habremos conseguido un poderoso aliado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo hiciste muy bien, $n. Con este antiguo cuerno podremos invocar a los Implacables.$B$BBueno, si ellos quieren.', 0),
(@ID, 'esMX', 'Lo hiciste muy bien, $n. Con este antiguo cuerno podremos invocar a los Implacables.$B$BBueno, si ellos quieren.', 0);
-- 10231 ¿Libro? Yo no veo ninguno
-- https://es.wowhead.com/quest=10231
SET @ID := 10231;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué quieres?', 0),
(@ID, 'esMX', '¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vale, vale! ¡No nos hagas daño! Teníamos el libro pero lo vendimos...', 0),
(@ID, 'esMX', '¡Vale, vale! ¡No nos hagas daño! Teníamos el libro pero lo vendimos...', 0);
-- 10232 Movida con la Legión
-- https://es.wowhead.com/quest=10232
SET @ID := 10232;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que estés a la altura de esa pelea con la Legión Ardiente.$B$BNo hay muchas cosas que odie más que a $glos:las; que incumplen un trato, o los gnomos <tos>, ¡pero los demonios son sin duda una de ellas!', 0),
(@ID, 'esMX', 'Espero que estés a la altura de esa pelea con la Legión Ardiente.$B$BNo hay muchas cosas que odie más que a $glos:las; que incumplen un trato, o los gnomos <tos>, ¡pero los demonios son sin duda una de ellas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En fin, son buenas y malas noticias, ¿verdad? Les hemos hecho daño, pero con la Legión Ardiente campando a sus anchas por toda la Tormenta Abisal, y acercándose más y más aquí, no sé qué puede pasar.$B$BTengo el presentimiento de que vamos a tener que cambiar las cosas por aquí. Espero que puedas echarnos una mano, $n.', 0),
(@ID, 'esMX', 'En fin, son buenas y malas noticias, ¿verdad? Les hemos hecho daño, pero con la Legión Ardiente campando a sus anchas por toda la Tormenta Abisal, y acercándose más y más aquí, no sé qué puede pasar.$B$BTengo el presentimiento de que vamos a tener que cambiar las cosas por aquí. Espero que puedas echarnos una mano, $n.', 0);
-- 10233 Fuego en el Bastión Furia del Sol
-- https://es.wowhead.com/quest=10233
SET @ID := 10233;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Balista Furia del Sol destruida', `ObjectiveText2` = 'Tienda Furia del Sol destruida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sale humo de las fortificaciones del Bastión Furia del Sol. ¿Has sido tú?', 0),
(@ID, 'esMX', 'Sale humo de las fortificaciones del Bastión Furia del Sol. ¿Has sido tú?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Teniente hechicero Morran asiente con gesto sombrío.>$B$BEl Kirin Tor nunca ataca sin motivo, pero no tenemos miramientos al actuar contra los enemigos, incluso los muertos.', 0),
(@ID, 'esMX', '<El Teniente hechicero Morran asiente con gesto sombrío.>$B$BEl Kirin Tor nunca ataca sin motivo, pero no tenemos miramientos al actuar contra los enemigos, incluso los muertos.', 0);
-- 10234 Basura del demonio...
-- https://es.wowhead.com/quest=10234
SET @ID := 10234;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya esas piezas? Con la Legión Ardiente acercándose a cada una de nuestras posiciones de los alrededores, por desgracia nos queda poco tiempo.', 0),
(@ID, 'esMX', '¿Tienes ya esas piezas? Con la Legión Ardiente acercándose a cada una de nuestras posiciones de los alrededores, por desgracia nos queda poco tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que me tendré que apañar con esto por ahora. Si al menos pudiera asustarlos.$B$BOye, ¡eso me da una idea!', 0),
(@ID, 'esMX', 'Supongo que me tendré que apañar con esto por ahora. Si al menos pudiera asustarlos.$B$BOye, ¡eso me da una idea!', 0);
-- 10235 Deszarpar a Zarpaletal
-- https://es.wowhead.com/quest=10235
SET @ID := 10235;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya te has ocupado de Zarpaletal?', 0),
(@ID, 'esMX', '¿Ya te has ocupado de Zarpaletal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué, cómo...? ¡¿Que dijo qué?! ¡¿VAN HACIA EL ÁREA 52?!$B$BOh, esto no es bueno... ¡nada bueno!', 0),
(@ID, 'esMX', '¿Qué, cómo...? ¡¿Que dijo qué?! ¡¿VAN HACIA EL ÁREA 52?!$B$BOh, esto no es bueno... ¡nada bueno!', 0);
-- 10236 ¡Terrallende es un asco!
-- https://es.wowhead.com/quest=10236
SET @ID := 10236;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has conseguido piezas para la trituradora? Quiero arreglarla para poder volver a la mina. De algún modo tengo que ganarme la vida, si tan solo pudiera comprar un billete de vuelta a Bahía del Botín.', 0),
(@ID, 'esMX', '¿Me has conseguido piezas para la trituradora? Quiero arreglarla para poder volver a la mina. De algún modo tengo que ganarme la vida, si tan solo pudiera comprar un billete de vuelta a Bahía del Botín.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hurra! ¡Has encontrado algunas piezas! A lo mejor ahora consigo que mi trituradora funcione. Si gano suficiente dinero, puede que consiga volver a Bahía del Botín.$B$BDesde luego espero que mi primo, Screed Sinsuerte, estrelle su estúpido zepelín. No puedo creer que me engañara para venir a Terrallende.', 0),
(@ID, 'esMX', '¡Hurra! ¡Has encontrado algunas piezas! A lo mejor ahora consigo que mi trituradora funcione. Si gano suficiente dinero, puede que consiga volver a Bahía del Botín.$B$BDesde luego espero que mi primo, Screed Sinsuerte, estrelle su estúpido zepelín. No puedo creer que me engañara para venir a Terrallende.', 0);
-- 10237 ¡Avisa al Área 52!
-- https://es.wowhead.com/quest=10237
SET @ID := 10237;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No lo dices en serio, ¿verdad? ¿La Legión Ardiente nos culpa de eso?$B$B¡Pero si lo hiciste TÚ!$B$BTengo un dolor de cabeza del tamaño de este cohete. Muy bien, veamos, esto pide un cambio de planes.$B$BSi la Legión Ardiente piensa que va a venir aquí, destruir nuestra ciudad y arruinar mi sueño de viajar por El Vacío Abisal, la lleva clara.$B$B¡Y conozco al goblin que va a ayudarnos!', 0),
(@ID, 'esMX', 'No lo dices en serio, ¿verdad? ¿La Legión Ardiente nos culpa de eso?$B$B¡Pero si lo hiciste TÚ!$B$BTengo un dolor de cabeza del tamaño de este cohete. Muy bien, veamos, esto pide un cambio de planes.$B$BSi la Legión Ardiente piensa que va a venir aquí, destruir nuestra ciudad y arruinar mi sueño de viajar por El Vacío Abisal, la lleva clara.$B$B¡Y conozco al goblin que va a ayudarnos!', 0);
-- 10238 Cómo servir a los goblins
-- https://es.wowhead.com/quest=10238
SET @ID := 10238;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Manni salvado', `ObjectiveText2` = 'Moh salvado', `ObjectiveText3` = 'Jakk salvado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya salvaste a mis peones? Por favor, apúrate, me temo que se los van a comer y probablemente no sabrán muy bien. Si saben muy mal, los orcos viles pueden enfadarse mucho conmigo.', 0),
(@ID, 'esMX', '¿Ya salvaste a mis peones? Por favor, apúrate, me temo que se los van a comer y probablemente no sabrán muy bien. Si saben muy mal, los orcos viles pueden enfadarse mucho conmigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por salvar a mis peones. Ahora quizás pueda conseguir que arreglen mi trituradora con esas piezas que encontraste, ganar algún dinero y salir de Terrallende. Me muero por volver a Bahía del Botín.', 0),
(@ID, 'esMX', 'Gracias por salvar a mis peones. Ahora quizás pueda conseguir que arreglen mi trituradora con esas piezas que encontraste, ganar algún dinero y salir de Terrallende. Me muero por volver a Bahía del Botín.', 0);
-- 10239 Fuente de energía potencial
-- https://es.wowhead.com/quest=10239
SET @ID := 10239;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido alguna de esas fuentes de energía?', 0),
(@ID, 'esMX', '¿Has conseguido alguna de esas fuentes de energía?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Morran sujeta delicadamente uno de los contenedores.>$B$BCreo que no había visto nada igual jamás. Ciertamente, hay mucha energía suspendida dentro, pero es energía pura. Tendremos que ir con cuidado, pero creo que podremos encontrar la forma de adaptar esto para acabar con las criaturas de maná.', 0),
(@ID, 'esMX', '<Morran sujeta delicadamente uno de los contenedores.>$B$BCreo que no había visto nada igual jamás. Ciertamente, hay mucha energía suspendida dentro, pero es energía pura. Tendremos que ir con cuidado, pero creo que podremos encontrar la forma de adaptar esto para acabar con las criaturas de maná.', 0);
-- 10239 Fuente de energía potencial
-- https://es.wowhead.com/quest=10239
SET @ID := 10239;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido alguna de esas fuentes de energía?', 0),
(@ID, 'esMX', '¿Has conseguido alguna de esas fuentes de energía?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Morran sujeta delicadamente uno de los contenedores.>$B$BCreo que no había visto nada igual jamás. Ciertamente, hay mucha energía suspendida dentro, pero es energía pura. Tendremos que ir con cuidado, pero creo que podremos encontrar la forma de adaptar esto para acabar con las criaturas de maná.', 0),
(@ID, 'esMX', '<Morran sujeta delicadamente uno de los contenedores.>$B$BCreo que no había visto nada igual jamás. Ciertamente, hay mucha energía suspendida dentro, pero es energía pura. Tendremos que ir con cuidado, pero creo que podremos encontrar la forma de adaptar esto para acabar con las criaturas de maná.', 0);
-- 10240 Construyendo un perímetro
-- https://es.wowhead.com/quest=10240
SET @ID := 10240;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Activar la runa del este', `ObjectiveText2` = 'Activar la runa del noroeste', `ObjectiveText3` = 'Activar la runa del oeste', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has activado todas las runas? Me muero por ver si podemos mejorar el método de los elfos de sangre. Cualquier cosa que los hombres de Kael\'thas puedan hacer, los del Kirin Tor la harán mejor.', 0),
(@ID, 'esMX', '¿Has activado todas las runas? Me muero por ver si podemos mejorar el método de los elfos de sangre. Cualquier cosa que los hombres de Kael\'thas puedan hacer, los del Kirin Tor la harán mejor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo excelente. Cruza los dedos, $n. Voy a activar el escudo.', 0),
(@ID, 'esMX', 'Un trabajo excelente. Cruza los dedos, $n. Voy a activar el escudo.', 0);
-- 10241 Distracción en la Forja de Maná B'naar
-- https://es.wowhead.com/quest=10241
SET @ID := 10241;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has completado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo excelente, $n. Los Arúspices han descubierto una información muy valiosa gracias a la distracción que les proporcionaste. Quizás esta vez la compartan con nosotros.', 0),
(@ID, 'esMX', 'Un trabajo excelente, $n. Los Arúspices han descubierto una información muy valiosa gracias a la distracción que les proporcionaste. Quizás esta vez la compartan con nosotros.', 0);
-- 10242 La Avanzada Rompeloma
-- https://es.wowhead.com/quest=10242
SET @ID := 10242;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a La Avanzada Rompeloma. ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', 'Te doy la bienvenida a La Avanzada Rompeloma. ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Una muestra de sangre? Será todo un placer. Me encanta trabajar con sangre...', 0),
(@ID, 'esMX', '¿Una muestra de sangre? Será todo un placer. Me encanta trabajar con sangre...', 0);
-- 10243 Tecnología naaru
-- https://es.wowhead.com/quest=10243
SET @ID := 10243;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los símbolos que tienes ante ti te parecen extraños e incomprensibles.', 0),
(@ID, 'esMX', 'Los símbolos que tienes ante ti te parecen extraños e incomprensibles.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Desenrollas el pergamino y te preparas para copiar los extraños símbolos.', 0),
(@ID, 'esMX', 'Desenrollas el pergamino y te preparas para copiar los extraños símbolos.', 0);
-- 10245 Trascripción de la consola de B'naar
-- https://es.wowhead.com/quest=10245
SET @ID := 10245;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veamos lo que nos has traído, $n.', 0),
(@ID, 'esMX', 'Veamos lo que nos has traído, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Déjame unos momentos para revisar tu trascripción.$B$BLa hermandad te está muy agradecida, $c.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Déjame unos momentos para revisar tu trascripción.$B$BLa hermandad te está muy agradecida, $c.', 0);
-- 10246 Ataque a la Forja de Maná Coruu
-- https://es.wowhead.com/quest=10246
SET @ID := 10246;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has completado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Con tu dedicación, seguro que derrotamos al enemigo.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Con tu dedicación, seguro que derrotamos al enemigo.', 0);
-- 10247 Doctor Vomisa, Ph.T.
-- https://es.wowhead.com/quest=10247
SET @ID := 10247;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, bueno, parece que estamos de suerte, joven.$B$BHace poco he conseguido terminar la construcción de mi último invento, ¡el Atracador desguazador X6000!$B$B¡Y tú vas a tener el privilegio de ayudarme a probarlo para que lo podamos usar en la defensa del Área 52!', 0),
(@ID, 'esMX', 'Bueno, bueno, parece que estamos de suerte, joven.$B$BHace poco he conseguido terminar la construcción de mi último invento, ¡el Atracador desguazador X6000!$B$B¡Y tú vas a tener el privilegio de ayudarme a probarlo para que lo podamos usar en la defensa del Área 52!', 0);
-- 10248 Tú, Robot
-- https://es.wowhead.com/quest=10248
SET @ID := 10248;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Test de prueba del Atracador desguazador X6000 completado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te parece? ¿Necesita algún retoque más?', 0),
(@ID, 'esMX', '¿Qué te parece? ¿Necesita algún retoque más?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $gquerido:querida;. ¡Ha sido de lo más excitante! Y por todo mi dinero que el Atracador desguazador X6000 lo ha hecho perfectamente bien a pesar de su piloto $gnovato:novata;.$B$BJe, je. No, no te ofendas, solo era una broma. Después de todo acabas de salvar el Área 52 y al cohete abisal X-52 de una muerte casi segura.', 0),
(@ID, 'esMX', 'Muy bien, $gquerido:querida;. ¡Ha sido de lo más excitante! Y por todo mi dinero que el Atracador desguazador X6000 lo ha hecho perfectamente bien a pesar de su piloto $gnovato:novata;.$B$BJe, je. No, no te ofendas, solo era una broma. Después de todo acabas de salvar el Área 52 y al cohete abisal X-52 de una muerte casi segura.', 0);
-- 10249 ¡El jefe de nuevo!
-- https://es.wowhead.com/quest=10249
SET @ID := 10249;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿O debería decir técnico inferior de primer grado $n? En fin, ¿a quién quiero engañar? Saltarse un nivel no es suficiente para lo que has hecho. ¡Te voy a convertir en mi oficial primero!$B$BNos has salvado a todos y, lo más importante, al cohete abisal X-52. ¡Podría besarte, pero... no lo haré!$B$BEso sí, acepta la gratitud del Área 52. ¡Elige tu recompensa!', 0),
(@ID, 'esMX', '¡$n! ¿O debería decir técnico inferior de primer grado $n? En fin, ¿a quién quiero engañar? Saltarse un nivel no es suficiente para lo que has hecho. ¡Te voy a convertir en mi oficial primero!$B$BNos has salvado a todos y, lo más importante, al cohete abisal X-52. ¡Podría besarte, pero... no lo haré!$B$BEso sí, acepta la gratitud del Área 52. ¡Elige tu recompensa!', 0);
-- 10250 Venganza sangrienta
-- https://es.wowhead.com/quest=10250
SET @ID := 10250;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya hiciste sonar el cuerno en la torre de asedio? Debemos hacerlo pronto. Quién sabe cuándo Thrallmar necesitará a los Implacables.', 0),
(@ID, 'esMX', '¿Ya hiciste sonar el cuerno en la torre de asedio? Debemos hacerlo pronto. Quién sabe cuándo Thrallmar necesitará a los Implacables.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que los Implacables te hayan acompañado en la batalla. Pensé que vendrían si oían su propio cuerno de batalla, pero no estaba seguro. Puede que les hayamos facilitado la venganza que tan desesperadamente buscaban.$B$BHas matado a Urtrak y debemos informar de tu victoria al comandante Hogarth de la Armería de Expedición. Entenderá lo mucho que te has arriesgado por él.', 0),
(@ID, 'esMX', 'Me alegro de que los Implacables te hayan acompañado en la batalla. Pensé que vendrían si oían su propio cuerno de batalla, pero no estaba seguro. Puede que les hayamos facilitado la venganza que tan desesperadamente buscaban.$B$BHas matado a Urtrak y debemos informar de tu victoria al comandante Hogarth de la Armería de Expedición. Entenderá lo mucho que te has arriesgado por él.', 0);
-- 10251 ¿La obra maestra del maestro?
-- https://es.wowhead.com/quest=10251
SET @ID := 10251;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todas las señales estaban allí y yo no quise verlas.$B$BCada día que pasa la Legión nos tiene más bajo su control. Incluso aquí...$B$BSi lo hubiera sabido... si hubiera sabido que mi chico trataba con los demonios... Le ofrecieron poder y después le dejaron probar ese poder. Y ya no hizo falta más...$B$BEl libro ya no está. Levixus se lo llevó. Solo su maestro oscuro y yo conocemos sus planes.$B$B$gForastero:Forastera;, no sé si eres alguien de bien, pero has de saber esto: hay que detener al chico.', 0),
(@ID, 'esMX', 'Todas las señales estaban allí y yo no quise verlas.$B$BCada día que pasa la Legión nos tiene más bajo su control. Incluso aquí...$B$BSi lo hubiera sabido... si hubiera sabido que mi chico trataba con los demonios... Le ofrecieron poder y después le dejaron probar ese poder. Y ya no hizo falta más...$B$BEl libro ya no está. Levixus se lo llevó. Solo su maestro oscuro y yo conocemos sus planes.$B$B$gForastero:Forastera;, no sé si eres alguien de bien, pero has de saber esto: hay que detener al chico.', 0);
-- 10252 Visión de los muertos
-- https://es.wowhead.com/quest=10252
SET @ID := 10252;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El ejército de Levixus aumenta de tamaño y poder a cada segundo que pasa. Debes darte prisa.', 0),
(@ID, 'esMX', 'El ejército de Levixus aumenta de tamaño y poder a cada segundo que pasa. Debes darte prisa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gForastero:Forastera;... no he sido muy sincero contigo. Cuando bebas esta poción, verás el mundo de los muertos... siempre. Esta receta es un rito de iniciación para todos los magos de la muerte de Auchindoun. Muchos enloquecen a causa de sus efectos. Ver a los muertos es... terrible.$B$B<Nitrin te acerca la poción a los labios.>$B$B¿Quieres continuar?', 0),
(@ID, 'esMX', '$gForastero:Forastera;... no he sido muy sincero contigo. Cuando bebas esta poción, verás el mundo de los muertos... siempre. Esta receta es un rito de iniciación para todos los magos de la muerte de Auchindoun. Muchos enloquecen a causa de sus efectos. Ver a los muertos es... terrible.$B$B<Nitrin te acerca la poción a los labios.>$B$B¿Quieres continuar?', 0);
-- 10253 Levixus el Invocador de Almas
-- https://es.wowhead.com/quest=10253
SET @ID := 10253;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién eres y qué quieres? Oh... Eres TÚ.', 0),
(@ID, 'esMX', '¿Quién eres y qué quieres? Oh... Eres TÚ.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si el viejo draenei te dijo que destruyeras el libro, ¿por qué no lo has hecho?$B$B<Ramdor te mira.>$B$BBah, qué diferencia hay. Podrías haber sido $gavaricioso:avariciosa;, pero al menos eres $ghonesto:honesta;.$B$BYo, al contrario... te mentí para conseguir este libro. No tengo ni idea de dónde guardan estas pobres almas perdidas su tesoro, ni te lo diría si lo supiera... Sin embargo, sí tengo algo para ti. Hoy has hecho algo bueno. Quizás algo más que bueno y te mereces una recompensa.$B$BPor cierto, $gbienvenido:bienvenida;.$B$B<Ramdor señala a los espíritus.>', 0),
(@ID, 'esMX', 'Si el viejo draenei te dijo que destruyeras el libro, ¿por qué no lo has hecho?$B$B<Ramdor te mira.>$B$BBah, qué diferencia hay. Podrías haber sido $gavaricioso:avariciosa;, pero al menos eres $ghonesto:honesta;.$B$BYo, al contrario... te mentí para conseguir este libro. No tengo ni idea de dónde guardan estas pobres almas perdidas su tesoro, ni te lo diría si lo supiera... Sin embargo, sí tengo algo para ti. Hoy has hecho algo bueno. Quizás algo más que bueno y te mereces una recompensa.$B$BPor cierto, $gbienvenido:bienvenida;.$B$B<Ramdor señala a los espíritus.>', 0);
-- 10254 Comandante en jefe Danath
-- https://es.wowhead.com/quest=10254
SET @ID := 10254;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $ghermano:hermana;. Me alegro de que hayas venido. Soy Danath, líder de los Hijos de Lothar y comandante en jefe de este fuerte.', 0),
(@ID, 'esMX', 'Saludos, $ghermano:hermana;. Me alegro de que hayas venido. Soy Danath, líder de los Hijos de Lothar y comandante en jefe de este fuerte.', 0);
-- 10255 Pruebas de antídoto
-- https://es.wowhead.com/quest=10255
SET @ID := 10255;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Administra el antídoto', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los resultados del experimento?', 0),
(@ID, 'esMX', '¿Tienes los resultados del experimento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thiah Melenarroja te mira con gran sorpresa cuando le describes el resultado del experimento.>$B$B¿Cómo puede ser? ¡El antídoto estaba bien preparado!$B$BHe comprobado que funciona con veneno de araña y de serpiente, ¿cómo es que ha fallado aquí? Puede que sea una de las muchas peculiaridades de Terrallende, $n. Será mejor que informe a mis colegas.', 0),
(@ID, 'esMX', '<Thiah Melenarroja te mira con gran sorpresa cuando le describes el resultado del experimento.>$B$B¿Cómo puede ser? ¡El antídoto estaba bien preparado!$B$BHe comprobado que funciona con veneno de araña y de serpiente, ¿cómo es que ha fallado aquí? Puede que sea una de las muchas peculiaridades de Terrallende, $n. Será mejor que informe a mis colegas.', 0);
-- 10256 Buscando a la Maestra de llaves
-- https://es.wowhead.com/quest=10256
SET @ID := 10256;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Descubre la identidad del maestro de llaves', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Describes lo que has visto en el ritual de adivinación.>$B$B¿La comandante Sarannis, dices? Mmm.$B$BEs consejera de Kael\'thas, pero desde luego no es una maga. La recuerdo del ataque al Poblado Kirin\'Var. Creo que tus impresiones son correctas, $n. Ella no mantiene la maldición, pero sí es ella quien tiene la llave.', 0),
(@ID, 'esMX', '<Describes lo que has visto en el ritual de adivinación.>$B$B¿La comandante Sarannis, dices? Mmm.$B$BEs consejera de Kael\'thas, pero desde luego no es una maga. La recuerdo del ataque al Poblado Kirin\'Var. Creo que tus impresiones son correctas, $n. Ella no mantiene la maldición, pero sí es ella quien tiene la llave.', 0);
-- 10257 La piedra angular
-- https://es.wowhead.com/quest=10257
SET @ID := 10257;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste La piedra angular?', 0),
(@ID, 'esMX', '¿Conseguiste La piedra angular?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Los ojos del archimago se iluminan cuando le das la piedra.>$B$B¡Increíble! Por lo poco que sé del sino de Farahlon, no estoy seguro de querer salir, pero será mucho mejor que estar atrapado aquí el resto de mis días.', 0),
(@ID, 'esMX', '<Los ojos del archimago se iluminan cuando le das la piedra.>$B$B¡Increíble! Por lo poco que sé del sino de Farahlon, no estoy seguro de querer salir, pero será mucho mejor que estar atrapado aquí el resto de mis días.', 0);
-- 10258 Honrar a los caídos
-- https://es.wowhead.com/quest=10258
SET @ID := 10258;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hace muchísimo tiempo que perdimos la batalla contra los orcos viles. Nos devolviste algo del honor perdido al matar a Urtrak.$B$BLlévate una de nuestras armas. Cuando luches contra nuestros más odiados enemigos, usa esta arma y los que estén libres de nuestra maldición acudirán en tu ayuda.$B$BAntes de que te marches, los que perecieron en la torre del asedio desean honrarte por acabar con nuestros enemigos.', 0),
(@ID, 'esMX', 'Hace muchísimo tiempo que perdimos la batalla contra los orcos viles. Nos devolviste algo del honor perdido al matar a Urtrak.$B$BLlévate una de nuestras armas. Cuando luches contra nuestros más odiados enemigos, usa esta arma y los que estén libres de nuestra maldición acudirán en tu ayuda.$B$BAntes de que te marches, los que perecieron en la torre del asedio desean honrarte por acabar con nuestros enemigos.', 0);
-- 10259 Abriendo brecha
-- https://es.wowhead.com/quest=10259
SET @ID := 10259;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Entre el caos de la batalla, $glos héroes:las heroínas; brillan contra la oscuridad. ¡Tu luz brilla verdadera!', 0),
(@ID, 'esMX', 'Gracias, $n. Entre el caos de la batalla, $glos héroes:las heroínas; brillan contra la oscuridad. ¡Tu luz brilla verdadera!', 0);
-- 10261 Se busca: Servoaniquilador
-- https://es.wowhead.com/quest=10261
SET @ID := 10261;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que hayas venido por el anuncio que puse!', 0),
(@ID, 'esMX', '¡Espero que hayas venido por el anuncio que puse!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! ¿Sabes lo difícil que es conseguir cosas de estas? No es que aquí me envíen pedidos de piezas regularmente.$B$BVerás, como pago, quiero que elijas algo de mi caja de basura. Seguro que habrá algo que puedas usar. Y, si no, puedes venderlo.$B$BMuy bien, deja que te coja eso y lo meta en el analizador de espectro de cuello largo antes de que me explote en la cara.', 0),
(@ID, 'esMX', '¡Fantástico! ¿Sabes lo difícil que es conseguir cosas de estas? No es que aquí me envíen pedidos de piezas regularmente.$B$BVerás, como pago, quiero que elijas algo de mi caja de basura. Seguro que habrá algo que puedas usar. Y, si no, puedes venderlo.$B$BMuy bien, deja que te coja eso y lo meta en el analizador de espectro de cuello largo antes de que me explote en la cara.', 0);
-- 10262 Un montón de etéreos
-- https://es.wowhead.com/quest=10262
SET @ID := 10262;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho? ¿Borraste a esa escoria Zaxxis de la faz de Terrallende y me traes sus insignias?', 0),
(@ID, 'esMX', '¿Lo has hecho? ¿Borraste a esa escoria Zaxxis de la faz de Terrallende y me traes sus insignias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas insignias son un buen comienzo.$B$BPor desgracia, mientras estabas en La Pila, uno de mis agentes infiltrado entre los Zaxxis nos ha hecho saber que el asaltante de distorsión Nesaad ¡todavía está vivo!', 0),
(@ID, 'esMX', 'Estas insignias son un buen comienzo.$B$BPor desgracia, mientras estabas en La Pila, uno de mis agentes infiltrado entre los Zaxxis nos ha hecho saber que el asaltante de distorsión Nesaad ¡todavía está vivo!', 0);
