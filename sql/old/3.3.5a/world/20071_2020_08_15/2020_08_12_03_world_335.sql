-- 466 Búsqueda de incendicita
-- https://es.classic.wowhead.com/quest=466
SET @ID := 466;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Dónde está el mineral, $n?!', 0),
(@ID, 'esMX', '¡¿Dónde está el mineral, $n?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes el mineral! ¡Bien hecho, $n! Tengo que encontrar a alguien que quiera trabajar con él. ¡Esperemos que no salga volando por los aires!', 0),
(@ID, 'esMX', '¡Tienes el mineral! ¡Bien hecho, $n! Tengo que encontrar a alguien que quiera trabajar con él. ¡Esperemos que no salga volando por los aires!', 0);
-- 317 Los suministros del reactor a vapor
-- https://es.classic.wowhead.com/quest=317
SET @ID := 317;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los preparativos van bien. ¿Cómo va tu caza?', 0),
(@ID, 'esMX', 'Los preparativos van bien. ¿Cómo va tu caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por la barba de Magni, ¡sí que has cazado! Gracias, $n.', 0),
(@ID, 'esMX', 'Por la barba de Magni, ¡sí que has cazado! Gracias, $n.', 0);
-- 318 La tajada
-- https://es.classic.wowhead.com/quest=318
SET @ID := 318;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que Bramiz necesita un poco de mi tajada? Mm... está bien.', 0),
(@ID, 'esMX', '¿Que Bramiz necesita un poco de mi tajada? Mm... está bien.', 0);
-- 319 Un favor a cambio de un barril de tajada
-- https://es.classic.wowhead.com/quest=319
SET @ID := 319;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has encargado de esos animales salvajes?', 0),
(@ID, 'esMX', '¿Te has encargado de esos animales salvajes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Será estupendo trabajar sin esos gritos y aullidos de fondo.', 0),
(@ID, 'esMX', 'Gracias, $n. Será estupendo trabajar sin esos gritos y aullidos de fondo.', 0);
-- 320 Regresa junto a Bramiz
-- https://es.classic.wowhead.com/quest=320
SET @ID := 320;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste esa tajada?', 0),
(@ID, 'esMX', '¿Conseguiste esa tajada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vale, esta me vale. Creo que abriré una botella ahora mismo para probarla...', 0),
(@ID, 'esMX', 'Vale, esta me vale. Creo que abriré una botella ahora mismo para probarla...', 0);
-- 416 Mata ratas
-- https://es.classic.wowhead.com/quest=416
SET @ID := 416;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ehl, $n, ¿me traes las orejas?', 0),
(@ID, 'esMX', 'Ehl, $n, ¿me traes las orejas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Puaj, qué peste!$B$BAquí tienes la recompensa, $n. Buen trabajo.', 0),
(@ID, 'esMX', '¡Puaj, qué peste!$B$BAquí tienes la recompensa, $n. Buen trabajo.', 0);
-- 468 Preséntate ante el montaraz Piedragar
-- https://es.classic.wowhead.com/quest=468
SET @ID := 468;
UPDATE `quest_template_locale` SET `Title` = 'Preséntate ante el montaraz Piedragar' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, $c! ¿Estás aquí para la misión de exploración, verdad? ¡Muy bien!$B$BEspero que tu equipo esté en buenas condiciones porque esta misión "de exploración" se ha convertido en algo más... turbio...', 0),
(@ID, 'esMX', '¡Hola, $c! ¿Estás aquí para la misión de exploración, verdad? ¡Muy bien!$B$BEspero que tu equipo esté en buenas condiciones porque esta misión "de exploración" se ha convertido en algo más... turbio...', 0);
-- 1339 La tarea del montaraz Pico Tormenta
-- https://es.classic.wowhead.com/quest=1339
SET @ID := 1339;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pues sí, tengo un trabajito que te llevará lejos de Loch Modan.$B$B¡Ya tienes otra aventura servida!', 0),
(@ID, 'esMX', 'Pues sí, tengo un trabajito que te llevará lejos de Loch Modan.$B$B¡Ya tienes otra aventura servida!', 0);
-- 418 Morcillas de Thelsamar
-- https://es.classic.wowhead.com/quest=418
SET @ID := 418;
UPDATE `quest_template_locale` SET `Details` = 'Aquí en Thelsamar siempre hay alguien que quiere comer, críos por todos lados, los obreros de la excavación y eso. Lo más conocido es la morcilla, ¿la has probado?$B$B¿No? Bueno, pues aquí hay que trabajar para comer, no creas que te libras porque seas $c.$B$BNecesito carne de oso, tripa de jabalí y un poco de icor de araña para darle sabor. ¡Tú trae eso y de cocinar me ocupo yo, Vidra!', `Objectives` = 'Lleva 3 trozos de Carne de oso, 3 Tripas de jabalí y 3 porciones de Icor de araña a Vidra Hogartufa, en Thelsamar.' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si me traes los ingredientes, me pongo ya mismo a cocinar.', 0),
(@ID, 'esMX', 'Si me traes los ingredientes, me pongo ya mismo a cocinar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es más fácil de lo que parece.$B$BNo había conocido a nadie con tanto interés, pero ya que preguntas, te daré la receta. ¡Recuerda que no se conservan demasiado tiempo!', 0),
(@ID, 'esMX', 'Es más fácil de lo que parece.$B$BNo había conocido a nadie con tanto interés, pero ya que preguntas, te daré la receta. ¡Recuerda que no se conservan demasiado tiempo!', 0);
-- 255 Mercenarios
-- https://es.classic.wowhead.com/quest=255
SET @ID := 255;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido algo de suerte?', 0),
(@ID, 'esMX', '¿Has tenido algo de suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estupendas noticias. Quiero agradecerte lo que has hecho en nombre de Thelsamar. Y resuelto el problema de los ogros, podremos concentrarnos en los troggs.', 0),
(@ID, 'esMX', 'Estupendas noticias. Quiero agradecerte lo que has hecho en nombre de Thelsamar. Y resuelto el problema de los ogros, podremos concentrarnos en los troggs.', 0);
-- 1655 Envío de mena de Bailor
-- https://es.classic.wowhead.com/quest=1655
SET @ID := 1655;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿todavía tienes suerte? Jaja, esos ogros todavía no sacaron lo mejor de ti, ¿verdad?', 0),
(@ID, 'esMX', 'Entonces, ¿todavía tienes suerte? Jaja, esos ogros todavía no sacaron lo mejor de ti, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí, esto es todo. ¡Ahh! Si hubiera sabido que realmente ibas a salir y luchar contra esos ogros, te habría dado una lista de cosas para conseguir en lugar de sólo esta. Pero, no estás aquí haciendo negocios por mí, ¿verdad?$B$BUn trato es un trato; Jordan quería un envío de mi aleación y eso es lo que va a conseguir.$B$BSalúdalo de mi parte y ten cuidado, $c.', 0),
(@ID, 'esMX', 'Sí, sí, esto es todo. ¡Ahh! Si hubiera sabido que realmente ibas a salir y luchar contra esos ogros, te habría dado una lista de cosas para conseguir en lugar de sólo esta. Pero, no estás aquí haciendo negocios por mí, ¿verdad?$B$BUn trato es un trato; Jordan quería un envío de mi aleación y eso es lo que va a conseguir.$B$BSalúdalo de mi parte y ten cuidado, $c.', 0);
-- 256 SE BUSCA: Chok'sul
-- https://es.classic.wowhead.com/quest=256
SET @ID := 256;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Necesitas algo?', 0),
(@ID, 'esMX', '¿Sí? ¿Necesitas algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Puaj! ¿Qué es eso?$B$BPor la Luz, ¿es la cabeza del ogro? ¡Excelente! Ten la recompensa y gracias en nombre de Thelsamar.', 0),
(@ID, 'esMX', '¡Puaj! ¿Qué es eso?$B$BPor la Luz, ¿es la cabeza del ogro? ¡Excelente! Ten la recompensa y gracias en nombre de Thelsamar.', 0);
-- 436 La excavación de Vetaferro
-- https://es.classic.wowhead.com/quest=436
SET @ID := 436;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que por qué hay un retraso?$B$BVetaferro está preparando el informe, pero ya te digo yo lo que causa el retraso:$B$B¡Los troggs!', 0),
(@ID, 'esMX', '¿Que por qué hay un retraso?$B$BVetaferro está preparando el informe, pero ya te digo yo lo que causa el retraso:$B$B¡Los troggs!', 0);
-- 298 Un informe sobre el avance de la excavación
-- https://es.classic.wowhead.com/quest=298
SET @ID := 298;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes el informe? ¡Excelente!', 0),
(@ID, 'esMX', '¿Me traes el informe? ¡Excelente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me pregunto si Vetaferro quiere la pólvora para la excavación o para luchar contra los troggs...$B$B¡Ambos usos me parecen bien!$B$BLo raro es que le mandé un cargamento hace unas semanas... ¿Dónde habrá ido a parar?', 0),
(@ID, 'esMX', 'Me pregunto si Vetaferro quiere la pólvora para la excavación o para luchar contra los troggs...$B$B¡Ambos usos me parecen bien!$B$BLo raro es que le mandé un cargamento hace unas semanas... ¿Dónde habrá ido a parar?', 0);
-- 738 Encontrar a Agmond
-- https://es.classic.wowhead.com/quest=738
SET @ID := 738;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este esqueleto debe de ser lo que queda del desafortunado Agmond. Su cuerpo está destrozado y han limpiado sus huesos.', 0),
(@ID, 'esMX', 'Este esqueleto debe de ser lo que queda del desafortunado Agmond. Su cuerpo está destrozado y han limpiado sus huesos.', 0);
-- 297 Recoger ídolos
-- https://es.classic.wowhead.com/quest=297
SET @ID := 297;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes los ídolos? Tengo que estudiarlos y enviar un informe a Forjaz.', 0),
(@ID, 'esMX', '¿Me traes los ídolos? Tengo que estudiarlos y enviar un informe a Forjaz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n!$B$BY no parece que te hayan machacado mucho... Tú prometes.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n!$B$BY no parece que te hayan machacado mucho... Tú prometes.', 0);
-- 2038 Suministros de Bingles
-- https://es.classic.wowhead.com/quest=2038
SET @ID := 2038;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¡¿Dónde están mis cosas?!', 0),
(@ID, 'esMX', '¡$n! ¡¿Dónde están mis cosas?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos has prestado un gran servicio, $n. ¡Esos troggs se van a enterar de lo que valen los gnomos de Gnomeregan!', 0),
(@ID, 'esMX', 'Nos has prestado un gran servicio, $n. ¡Esos troggs se van a enterar de lo que valen los gnomos de Gnomeregan!', 0);
-- 301 Informe a Forjaz
-- https://es.classic.wowhead.com/quest=301
SET @ID := 301;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A los Pico Tormenta no nos gusta perder el tiempo, $c. Espero que lo que tengas que decir merezca la pena.', 0),
(@ID, 'esMX', 'A los Pico Tormenta no nos gusta perder el tiempo, $c. Espero que lo que tengas que decir merezca la pena.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maldito sea Vetaferro! Le envié un cargamento de pólvora hace semanas y no lo menciona en el informe.$B$B¿Dónde está la pólvora?', 0),
(@ID, 'esMX', '¡Maldito sea Vetaferro! Le envié un cargamento de pólvora hace semanas y no lo menciona en el informe.$B$B¿Dónde está la pólvora?', 0);
-- 1338 Un pedido de Pico Tormenta
-- https://es.classic.wowhead.com/quest=1338
SET @ID := 1338;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Una carta de tierras enanas? No sé quién me escribirá de tan al norte...$B$BA ver, déjame ese pedido.', 0),
(@ID, 'esMX', '¿Una carta de tierras enanas? No sé quién me escribirá de tan al norte...$B$BA ver, déjame ese pedido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un pedido de Pico Tormenta... Una de las mejores familias de enanos y también una de las más ricas.$B$BGracias, $n. Esta tarde me pondré con el escudo.', 0),
(@ID, 'esMX', 'Ah, un pedido de Pico Tormenta... Una de las mejores familias de enanos y también una de las más ricas.$B$BGracias, $n. Esta tarde me pondré con el escudo.', 0);
-- 307 Zarpas asquerosas
-- https://es.classic.wowhead.com/quest=307
SET @ID := 307;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el equipamiento de minero, $n?', 0),
(@ID, 'esMX', '¿Traes el equipamiento de minero, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Había muchos kobolds? A ver si desaparecen pronto... Me pongo malo de pensar que andan por nuestra mina.', 0),
(@ID, 'esMX', '¿Había muchos kobolds? A ver si desaparecen pronto... Me pongo malo de pensar que andan por nuestra mina.', 0);
