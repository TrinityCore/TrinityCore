-- 289 La tripulación maldita
-- https://es.classic.wowhead.com/quest=289
SET @ID := 289;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡En mis sueños a veces escucho los gemidos de mis hermanos! Por favor señor, libéralos de sus ataduras y termina con sus lamentos.', 0),
(@ID, 'esMX', '¡En mis sueños a veces escucho los gemidos de mis hermanos! Por favor señor, libéralos de sus ataduras y termina con sus lamentos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Recibe también la gratitud de mis hermanos malditos.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Recibe también la gratitud de mis hermanos malditos.', 0);
-- 470 Abriéndose paso entre los mocos
-- https://es.classic.wowhead.com/quest=470
SET @ID := 470;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste mi bolsa?', 0),
(@ID, 'esMX', '¿Encontraste mi bolsa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, gracias, $n! ¡Creía que la había perdido para siempre!$B$BUmm... esto ya no me vale de mucho, pero lávalo y estoy segura de que te será muy útil.', 0),
(@ID, 'esMX', '¡Oh, gracias, $n! ¡Creía que la había perdido para siempre!$B$BUmm... esto ya no me vale de mucho, pero lávalo y estoy segura de que te será muy útil.', 0);
-- 278 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=278
SET @ID := 278;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes lo que te pedí? ¡Es muy urgente!', 0),
(@ID, 'esMX', '¿Tienes lo que te pedí? ¡Es muy urgente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Justo a tiempo, $n!', 0),
(@ID, 'esMX', '¡Justo a tiempo, $n!', 0);
-- 280 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=280
SET @ID := 280;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tapa del barril se desliza lentamente.', 0),
(@ID, 'esMX', 'La tapa del barril se desliza lentamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barril crepita un poco al verter la mezcla neutralizadora.', 0),
(@ID, 'esMX', 'El barril crepita un poco al verter la mezcla neutralizadora.', 0);
-- 283 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=283
SET @ID := 283;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $n! Sin tu ayuda, la presa habría saltado en pedazos. Gracias en nombre del Reino y de la Alianza, $c.$B$BEstamos a salvo... al menos de momento.', 0),
(@ID, 'esMX', '¡Gracias, $n! Sin tu ayuda, la presa habría saltado en pedazos. Gracias en nombre del Reino y de la Alianza, $c.$B$BEstamos a salvo... al menos de momento.', 0);
-- 465 La estrategia de Nek'rosh
-- https://es.classic.wowhead.com/quest=465
SET @ID := 465;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La primera catapulta está ante ti. ¿Vas a prenderle fuego?', 0),
(@ID, 'esMX', 'La primera catapulta está ante ti. ¿Vas a prenderle fuego?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas algo de yesca en la catapulta y haces saltar una chispa.$B$B¡Aparece una llama que se extiende rápidamente!', 0),
(@ID, 'esMX', 'Colocas algo de yesca en la catapulta y haces saltar una chispa.$B$B¡Aparece una llama que se extiende rápidamente!', 0);
-- 305 La búsqueda del equipo de excavación
-- https://es.classic.wowhead.com/quest=305
SET @ID := 305;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ¡loados sean los cielos! ¡Estás aquí!', 0),
(@ID, 'esMX', 'Oh, ¡loados sean los cielos! ¡Estás aquí!', 0);
-- 294 La venganza de Ormer
-- https://es.classic.wowhead.com/quest=294
SET @ID := 294;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mata a 10 estridadores jaspeados y 10 raptores jaspeados, $n. Mis compañeros de trabajo no se merecían el destino que les tocó. Es hora de igualar el marcador.', 0),
(@ID, 'esMX', 'Mata a 10 estridadores jaspeados y 10 raptores jaspeados, $n. Mis compañeros de trabajo no se merecían el destino que les tocó. Es hora de igualar el marcador.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Matar es un negocio sucio, pero has hecho muy bien tu trabajo, $n. Si no tuviera que permanecer junto al prospector y a Merrin estaría a tu lado vertiendo sangre.', 0),
(@ID, 'esMX', 'Matar es un negocio sucio, pero has hecho muy bien tu trabajo, $n. Si no tuviera que permanecer junto al prospector y a Merrin estaría a tu lado vertiendo sangre.', 0);
-- 306 La búsqueda del equipo de excavación
-- https://es.classic.wowhead.com/quest=306
SET @ID := 306;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has podido encontrar a Merrin? ¿Ha enviado algún mensaje?', 0),
(@ID, 'esMX', '¿Has podido encontrar a Merrin? ¿Ha enviado algún mensaje?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué noticias tan horribles! Al menos tres sobrevivieron. ¿Cuándo terminarán las muertes? Anhelo el día en el que los súbditos del rey Magni puedan vivir libres de miedo.', 0),
(@ID, 'esMX', '¡Qué noticias tan horribles! Al menos tres sobrevivieron. ¿Cuándo terminarán las muertes? Anhelo el día en el que los súbditos del rey Magni puedan vivir libres de miedo.', 0);
-- 299 Desvelando el pasado
-- https://es.classic.wowhead.com/quest=299
SET @ID := 299;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has descubierto los cuatro fragmentos, $n? Ados, Modr, Golm y Neru...', 0),
(@ID, 'esMX', '¿Ya has descubierto los cuatro fragmentos, $n? Ados, Modr, Golm y Neru...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la piedra Goaz está completa! Buen trabajo, $n. Buen trabajo, sin duda. Ahora puedo seguir con la trascripción de este escrito de los Titanes. ¡Ya puedo descifrar nuevas palabras! Umm... aquí dice, "Dioses antiguos... encadenados bajo la tierra." Esto debe ser el comienzo de algún relato épico.', 0),
(@ID, 'esMX', '¡Ah, la piedra Goaz está completa! Buen trabajo, $n. Buen trabajo, sin duda. Ahora puedo seguir con la trascripción de este escrito de los Titanes. ¡Ya puedo descifrar nuevas palabras! Umm... aquí dice, "Dioses antiguos... encadenados bajo la tierra." Esto debe ser el comienzo de algún relato épico.', 0);
-- 295 La venganza de Ormer
-- https://es.classic.wowhead.com/quest=295
SET @ID := 295;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quiero hacer que esos raptores segadores jaspeados y raptores tajobuches jaspeados paguen por lo que hicieron. ¿Has matado a 10 de cada uno?', 0),
(@ID, 'esMX', 'Quiero hacer que esos raptores segadores jaspeados y raptores tajobuches jaspeados paguen por lo que hicieron. ¿Has matado a 10 de cada uno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hiciste un trabajo fenomenal eliminando a esos raptores, $n!', 0),
(@ID, 'esMX', '¡Hiciste un trabajo fenomenal eliminando a esos raptores, $n!', 0);
-- 296 La venganza de Ormer
-- https://es.classic.wowhead.com/quest=296
SET @ID := 296;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está muerto Sarldente? ¿Has redimido la memoria de los caídos?', 0),
(@ID, 'esMX', '¿Está muerto Sarldente? ¿Has redimido la memoria de los caídos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. No olvidaremos tus esfuerzos. Muchos enanos inocentes murieron en este lugar mientras se limitaban a hacer su trabajo. Has hecho que la venganza caiga sobre esas malvadas criaturas. Se lo pensarán dos veces antes de volver a atacar a los súbditos del rey Magni.', 0),
(@ID, 'esMX', 'Gracias, $n. No olvidaremos tus esfuerzos. Muchos enanos inocentes murieron en este lugar mientras se limitaban a hacer su trabajo. Has hecho que la venganza caiga sobre esas malvadas criaturas. Se lo pensarán dos veces antes de volver a atacar a los súbditos del rey Magni.', 0);
-- 474 Derrota a Nek'rosh
-- https://es.classic.wowhead.com/quest=474
SET @ID := 474;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a Nek\'rosh?', 0),
(@ID, 'esMX', '¿Has matado a Nek\'rosh?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho con gran resolución, $n. Has dado un golpe contundente al clan orco de los Faucedraco. Quizás nunca se recuperen. Y la destrucción de las catapultas han hecho de Puerto de Menethil un lugar mucho más seguro.$B$BTus méritos son innegables, y el reino de Forjaz sabe recompensar a quienes le sirven.', 0),
(@ID, 'esMX', 'Lo has hecho con gran resolución, $n. Has dado un golpe contundente al clan orco de los Faucedraco. Quizás nunca se recuperen. Y la destrucción de las catapultas han hecho de Puerto de Menethil un lugar mucho más seguro.$B$BTus méritos son innegables, y el reino de Forjaz sabe recompensar a quienes le sirven.', 0);
-- 276 Patas sucias
-- https://es.classic.wowhead.com/quest=276
SET @ID := 276;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aún tienes que completar tu misión, joven $c.', 0),
(@ID, 'esMX', 'Aún tienes que completar tu misión, joven $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al reducir el número de gnolls has cuidado de la salud de Los Humedales. Aunque mi fe en tu pueblo fue puesta a prueba en el pasado, $r, quizás ahora se recupere.', 0),
(@ID, 'esMX', 'Al reducir el número de gnolls has cuidado de la salud de Los Humedales. Aunque mi fe en tu pueblo fue puesta a prueba en el pasado, $r, quizás ahora se recupere.', 0);
-- 277 No al fuego
-- https://es.classic.wowhead.com/quest=277
SET @ID := 277;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las herramientas gnoll para hacer fuego?', 0),
(@ID, 'esMX', '¿Tienes las herramientas gnoll para hacer fuego?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '... Gracias. Romperé estos pedernales y los lanzaré al mar para que nunca más puedan ser usados para prender fuego a madera viva.', 0),
(@ID, 'esMX', '... Gracias. Romperé estos pedernales y los lanzaré al mar para que nunca más puedan ser usados para prender fuego a madera viva.', 0);
-- 275 Ampollas en la tierra
-- https://es.classic.wowhead.com/quest=275
SET @ID := 275;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los humedales todavía lloran y los trepadores del pantano todavía se enfurecen. Regresa a mí cuando hayas terminado tu tarea.', 0),
(@ID, 'esMX', 'Los humedales todavía lloran y los trepadores del pantano todavía se enfurecen. Regresa a mí cuando hayas terminado tu tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus esfuerzos han aliviado a esta tierra, recibirás algo muy provechoso.', 0),
(@ID, 'esMX', 'Tus esfuerzos han aliviado a esta tierra, recibirás algo muy provechoso.', 0);
-- 281 Recuperación de bienes
-- https://es.classic.wowhead.com/quest=281
SET @ID := 281;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cajón está cubierto de arañazos y está dañado por el agua. Cuando lo abres descubres paja empapada y podrida, como si hubiera habido algo de valor guardado en el cajón. Buscas por la paja...$B$B... y encuentras un puñado de botellas de color rojo.', 0),
(@ID, 'esMX', 'El cajón está cubierto de arañazos y está dañado por el agua. Cuando lo abres descubres paja empapada y podrida, como si hubiera habido algo de valor guardado en el cajón. Buscas por la paja...$B$B... y encuentras un puñado de botellas de color rojo.', 0);
-- 324 Los lingotes perdidos
-- https://es.classic.wowhead.com/quest=324
SET @ID := 324;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado el hierro Forjaluz que necesitas?', 0),
(@ID, 'esMX', '¿Has encontrado el hierro Forjaluz que necesitas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, los encontraste! ¡Vamos a fundir este hierro Forjaluz en algo útil!, ¿qué te parece?', 0),
(@ID, 'esMX', '¡Ah, los encontraste! ¡Vamos a fundir este hierro Forjaluz en algo útil!, ¿qué te parece?', 0);
-- 322 Brazo bendito
-- https://es.classic.wowhead.com/quest=322
SET @ID := 322;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué te podrían servir mis conocimientos, $c?', 0),
(@ID, 'esMX', '¿En qué te podrían servir mis conocimientos, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Menuda historia la tuya! ¡Y tienes hierro Forjaluz! Hace años que no trabajo con ese metal. Será un honor trabajar con él otra vez. Vuelve a verme luego para contarme la historia de tu batalla contra el Necromántico.$B$BPero estamos yendo demasiado deprisa. Antes de nada, tu arma contra Morbent Vil...', 0),
(@ID, 'esMX', '¡Menuda historia la tuya! ¡Y tienes hierro Forjaluz! Hace años que no trabajo con ese metal. Será un honor trabajar con él otra vez. Vuelve a verme luego para contarme la historia de tu batalla contra el Necromántico.$B$BPero estamos yendo demasiado deprisa. Antes de nada, tu arma contra Morbent Vil...', 0);
-- 1448 En búsqueda del templo
-- https://es.classic.wowhead.com/quest=1448
SET @ID := 1448;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He viajado por el mundo desde las selvas de Azeroth hasta los picos nevados de Khaz Modan.$B$BNunca antes había pedido ayuda en mis aventuras. Pero mis viejos huesos están cansados.$B$BNada me dejaría más satisfecho que saber que completé mi búsqueda final de la Liga de Expedicionarios.$B$BSi tuvieras la amabilidad de ayudarme a buscar el Templo de Atal\'Hakkar, $c, te lo agradecería mucho.$B$B¡Explora el Pantano de las Penas e informame de tus hallazgos!', 0),
(@ID, 'esMX', 'He viajado por el mundo desde las selvas de Azeroth hasta los picos nevados de Khaz Modan.$B$BNunca antes había pedido ayuda en mis aventuras. Pero mis viejos huesos están cansados.$B$BNada me dejaría más satisfecho que saber que completé mi búsqueda final de la Liga de Expedicionarios.$B$BSi tuvieras la amabilidad de ayudarme a buscar el Templo de Atal\'Hakkar, $c, te lo agradecería mucho.$B$B¡Explora el Pantano de las Penas e informame de tus hallazgos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Templo de Atal\'Hakkar está sumergido bajo la Charca de Lágrimas? ¿Y rodeado del Vuelo Verde?$B$BUn descubrimiento increíble, $c. Pero, obviamente, algo ha salido terriblemente mal.', 0),
(@ID, 'esMX', '¿El Templo de Atal\'Hakkar está sumergido bajo la Charca de Lágrimas? ¿Y rodeado del Vuelo Verde?$B$BUn descubrimiento increíble, $c. Pero, obviamente, algo ha salido terriblemente mal.', 0);
-- 325 Armado y listo
-- https://es.classic.wowhead.com/quest=325
SET @ID := 325;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. No hace tanto que te fuiste y, sin embargo, veo un fuego en tus ojos que no había visto antes.', 0),
(@ID, 'esMX', 'Hola, $n. No hace tanto que te fuiste y, sin embargo, veo un fuego en tus ojos que no había visto antes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡esto será perfecto para el malvado Morbent Vil! ¡Bien hecho!$B$BYa estás preparado. Morbent Vil caerá.', 0),
(@ID, 'esMX', 'Ah, ¡esto será perfecto para el malvado Morbent Vil! ¡Bien hecho!$B$BYa estás preparado. Morbent Vil caerá.', 0);
-- 1363 La orden de Mazen
-- https://es.classic.wowhead.com/quest=1363
SET @ID := 1363;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No fue culpa mía. En serio, no fue culpa mía.', 0),
(@ID, 'esMX', 'No fue culpa mía. En serio, no fue culpa mía.', 0);
-- 1364 La orden de Mazen
-- https://es.classic.wowhead.com/quest=1364
SET @ID := 1364;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae por el Castillo de Nethergarde, $r?', 0),
(@ID, 'esMX', '¿Qué te trae por el Castillo de Nethergarde, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, estupendo!$B$BDurante un tiempo temí que el maestro Mazen de la Academia de Artes y Ciencias Arcanas hubiese olvidado mi pedido de los ensayos de Khadgar sobre convergencia dimensional.$B$BDebe de tener muchísimas peticiones teniendo en cuenta los extraños sucesos que están teniendo lugar.$B$BAhora, si me disculpas, tengo que comenzar con mi investigación. Llegar a comprender por fin a alguien tan grandioso como Khadgar me excita en gran medida.', 0),
(@ID, 'esMX', '¡Ah, estupendo!$B$BDurante un tiempo temí que el maestro Mazen de la Academia de Artes y Ciencias Arcanas hubiese olvidado mi pedido de los ensayos de Khadgar sobre convergencia dimensional.$B$BDebe de tener muchísimas peticiones teniendo en cuenta los extraños sucesos que están teniendo lugar.$B$BAhora, si me disculpas, tengo que comenzar con mi investigación. Llegar a comprender por fin a alguien tan grandioso como Khadgar me excita en gran medida.', 0);
