-- 1069 Huevos de arañas Musgondo
-- https://es.classic.wowhead.com/quest=1069
SET @ID := 1069;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los huevos, $n? ¡Ya he cerrado un trato de flete con el maestro de los muelles Vertipeluca!', 0),
(@ID, 'esMX', '¿Has conseguido los huevos, $n? ¡Ya he cerrado un trato de flete con el maestro de los muelles Vertipeluca!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los tienes! ¡Gracias!$B$BLos mandaré a Vertipeluca para que los envíen a Bahía del Botín. ¡Ya puedo disfrutar de la ganancia!$B$BAquí tienes tu parte, $n. No habría conseguido este trato sin ti.', 0),
(@ID, 'esMX', '¡Los tienes! ¡Gracias!$B$BLos mandaré a Vertipeluca para que los envíen a Bahía del Botín. ¡Ya puedo disfrutar de la ganancia!$B$BAquí tienes tu parte, $n. No habría conseguido este trato sin ti.', 0);
-- 1221 Los tubérculos hojazul
-- https://es.classic.wowhead.com/quest=1221
SET @ID := 1221;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los tubérculos, $n?', 0),
(@ID, 'esMX', '¿Traes los tubérculos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, me pagarán un buen precio por ellos!$B$BGracias, $n, eres genial.', 0),
(@ID, 'esMX', '¡Estupendo, me pagarán un buen precio por ellos!$B$BGracias, $n, eres genial.', 0);
-- 895 SE BUSCA: Capitán Garvey
-- https://es.classic.wowhead.com/quest=895
SET @ID := 895;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué ocurre? ¿Puedo ayudarte en algo? Mercancías que despachar, ¿acaso un trabajo de ingeniería?', 0),
(@ID, 'esMX', '¿Qué ocurre? ¿Puedo ayudarte en algo? Mercancías que despachar, ¿acaso un trabajo de ingeniería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Esa clase de negocio. ¿Sabes?, una vez vi El Temerario en mar abierto. Un barco imponente, o era el barco... ¡esos marineros son tan especiales!$B$BEn cualquier caso, ver ese buque deslizarse por el agua era un espectáculo. Me alegro que su miserable capitán ya no vuelva a causarme problemas.', 0),
(@ID, 'esMX', '¡Ah! Esa clase de negocio. ¿Sabes?, una vez vi El Temerario en mar abierto. Un barco imponente, o era el barco... ¡esos marineros son tan especiales!$B$BEn cualquier caso, ver ese buque deslizarse por el agua era un espectáculo. Me alegro que su miserable capitán ya no vuelva a causarme problemas.', 0);
-- 1483 Ziz Fizziks
-- https://es.classic.wowhead.com/quest=1483
SET @ID := 1483;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creía que los ejecutivos de Ventura y Cía. eran unos negreros pero entonces conocí a Petardol, ¡el más cruel de todos!$B$B¡Ja! Aunque supongo que es mejor que estar sin trabajo... O algo peor, trabajar con el tal Gerenzo. Si estás aquí para ayudar, tengo algo de lo que podrías encargarte.', 0),
(@ID, 'esMX', 'Creía que los ejecutivos de Ventura y Cía. eran unos negreros pero entonces conocí a Petardol, ¡el más cruel de todos!$B$B¡Ja! Aunque supongo que es mejor que estar sin trabajo... O algo peor, trabajar con el tal Gerenzo. Si estás aquí para ayudar, tengo algo de lo que podrías encargarte.', 0);
-- 894 El churumbele
-- https://es.classic.wowhead.com/quest=894
SET @ID := 894;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Varios botones, palancas y lucecitas parpadeantes se encuentran de forma algo desordenada en el frontal de la consola de control. Un pequeño indicador sirve para ver si el aparato funciona dentro de los niveles óptimos y que las tres primeras válvulas de control están abiertas. Hay una pequeña cerradura en la parte inferior derecha del panel de control.', 0),
(@ID, 'esMX', 'Varios botones, palancas y lucecitas parpadeantes se encuentran de forma algo desordenada en el frontal de la consola de control. Un pequeño indicador sirve para ver si el aparato funciona dentro de los niveles óptimos y que las tres primeras válvulas de control están abiertas. Hay una pequeña cerradura en la parte inferior derecha del panel de control.', 0);
-- 959 ¡A por la botella!
-- https://es.classic.wowhead.com/quest=959
SET @ID := 959;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El maestro de los muelles está investigando mi caso desde que Loco Magglish se escapó con ese porto de 99 años. Apuesto que esa botella tenía que haber sido un regalo para el Barón Revilgaz en persona.$B$BSi tienes la paciencia y el valor suficientes para buscar a Loco Magglish y recuperar ese porto, me ocuparé de que tengas una buena recompensa.', 0),
(@ID, 'esMX', 'El maestro de los muelles está investigando mi caso desde que Loco Magglish se escapó con ese porto de 99 años. Apuesto que esa botella tenía que haber sido un regalo para el Barón Revilgaz en persona.$B$BSi tienes la paciencia y el valor suficientes para buscar a Loco Magglish y recuperar ese porto, me ocuparé de que tengas una buena recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Soberbio! ¡Y justo cuando estaba a punto de perder mi empleo! Me ocuparé de hacer llegar este regalo a Gazlowe inmediatamente.$B$BGracias, $n. Un buen trabajo, ¡vaya!', 0),
(@ID, 'esMX', '¡Soberbio! ¡Y justo cuando estaba a punto de perder mi empleo! Me ocuparé de hacer llegar este regalo a Gazlowe inmediatamente.$B$BGracias, $n. Un buen trabajo, ¡vaya!', 0);
-- 1180 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1180
SET @ID := 1180;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un envío a Trinquete? Permite que compruebe los registros...$B$BNo, el envío más reciente que me consta en las salidas hacia Trinquete son unas botas de Drizzlik. No ha habido mucho más, aparte de suministros y herramientas de construcción. Nada de piezas para carreras.', 0),
(@ID, 'esMX', '¿Un envío a Trinquete? Permite que compruebe los registros...$B$BNo, el envío más reciente que me consta en las salidas hacia Trinquete son unas botas de Drizzlik. No ha habido mucho más, aparte de suministros y herramientas de construcción. Nada de piezas para carreras.', 0);
-- 887 Los filibusteros de los Mares del Sur
-- https://es.classic.wowhead.com/quest=887
SET @ID := 887;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ni siquiera quiero pensar en las ganancias que he perdido por las incursiones piratas, ¿y ahora acamparon en mi puerta? Esto se está saliendo de madre, Tienes que hacer algo al respecto.', 0),
(@ID, 'esMX', 'Ni siquiera quiero pensar en las ganancias que he perdido por las incursiones piratas, ¿y ahora acamparon en mi puerta? Esto se está saliendo de madre, Tienes que hacer algo al respecto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has conseguido, $gchaval:chavala;. Un poco más de trabajo igual de bueno y habrá una cosa menos por lo que preocuparse. Con suerte, se convencerán de que deben operar en otro lugar.$B$BMientras tanto, ¡está el asuntillo de recuperar la mercancía que me robaron!', 0),
(@ID, 'esMX', 'Lo has conseguido, $gchaval:chavala;. Un poco más de trabajo igual de bueno y habrá una cosa menos por lo que preocuparse. Con suerte, se convencerán de que deben operar en otro lugar.$B$BMientras tanto, ¡está el asuntillo de recuperar la mercancía que me robaron!', 0);
-- 1112 Las piezas de Kravel
-- https://es.classic.wowhead.com/quest=1112
SET @ID := 1112;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste llegar a Trinquete y hacerte con las piezas?', 0),
(@ID, 'esMX', '¿Conseguiste llegar a Trinquete y hacerte con las piezas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, las tienes! Ahora hay que llevárselas a los gnomos, pero antes...$B$BVoy a elegir una de ellas para quedármela.', 0),
(@ID, 'esMX', '¡Genial, las tienes! Ahora hay que llevárselas a los gnomos, pero antes...$B$BVoy a elegir una de ellas para quedármela.', 0);
-- 896 La fortuna de un minero
-- https://es.classic.wowhead.com/quest=896
SET @ID := 896;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si al menos supiéramos qué minero encontró la esmeralda, sería un paseo...', 0),
(@ID, 'esMX', 'Si al menos supiéramos qué minero encontró la esmeralda, sería un paseo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fíjate en el tamaño de esa cosa, $n! ¡Nos vamos a hacer ricos! A ver, según los tipos que he visto en las gemas que van a Villabajo, debería poder calcular tu parte, cincuenta por ciento, ¡no te preocupes!$B$BAhora veamos... Creo que esto debería bastar. ¡Un placer hacer negocios contigo, $n!', 0),
(@ID, 'esMX', '¡Fíjate en el tamaño de esa cosa, $n! ¡Nos vamos a hacer ricos! A ver, según los tipos que he visto en las gemas que van a Villabajo, debería poder calcular tu parte, cincuenta por ciento, ¡no te preocupes!$B$BAhora veamos... Creo que esto debería bastar. ¡Un placer hacer negocios contigo, $n!', 0);
-- 1491 Bebidas de inteligencia
-- https://es.classic.wowhead.com/quest=1491
SET @ID := 1491;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está mi esencia de lamentos?', 0),
(@ID, 'esMX', '¿Dónde está mi esencia de lamentos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, la tienes! Me muero por probarla. Conseguiré una fortuna con esto, ¡estoy seguro!$B$BGracias, $n. Esto es para ti, y cuando me haga rico, te enviaré más, ¡prometido!', 0),
(@ID, 'esMX', '¡Genial, la tienes! Me muero por probarla. Conseguiré una fortuna con esto, ¡estoy seguro!$B$BGracias, $n. Esto es para ti, y cuando me haga rico, te enviaré más, ¡prometido!', 0);
-- 890 El envío perdido
-- https://es.classic.wowhead.com/quest=890
SET @ID := 890;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mercancías para enviar en el siguiente barco, $n?', 0),
(@ID, 'esMX', '¿Mercancías para enviar en el siguiente barco, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Gazlowe te envía, ¿no? Solo un momento, déjame echar un vistazo para comprobar mis registros y asegurarme de que ningún envío de Gazlowe ha sido despachado al lugar equivocado.$B$BApuesto que espera esas botas de Drizzlek...', 0),
(@ID, 'esMX', 'Ah, Gazlowe te envía, ¿no? Solo un momento, déjame echar un vistazo para comprobar mis registros y asegurarme de que ningún envío de Gazlowe ha sido despachado al lugar equivocado.$B$BApuesto que espera esas botas de Drizzlek...', 0);
-- 892 El envío perdido
-- https://es.classic.wowhead.com/quest=892
SET @ID := 892;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿qué te dijo Vertipeluca?', 0),
(@ID, 'esMX', 'Bueno, ¿qué te dijo Vertipeluca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sin dados? Entonces supongo que fue cosa de los filibusteros... Vertipeluca es limpio, estoy seguro de que no me haría trampa. Después de todo, está en nómina.$B$BParece que tengo que devolver algo de mercancía, $n. ¿Qué me dices?', 0),
(@ID, 'esMX', '¿Sin dados? Entonces supongo que fue cosa de los filibusteros... Vertipeluca es limpio, estoy seguro de que no me haría trampa. Después de todo, está en nómina.$B$BParece que tengo que devolver algo de mercancía, $n. ¿Qué me dices?', 0);
-- 888 El botín robado
-- https://es.classic.wowhead.com/quest=888
SET @ID := 888;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mis cosas, $n?', 0),
(@ID, 'esMX', '¿Has encontrado mis cosas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un alivio recuperar todo esto, gracias por tu ayuda, $n. ¿Sabes?, no me vendría mal $gun:una; $r como tú para ayudarme aquí. Si cualquier día buscas trabajo, ¡recuerda lo bien que paga Gazlowe!', 0),
(@ID, 'esMX', 'Es un alivio recuperar todo esto, gracias por tu ayuda, $n. ¿Sabes?, no me vendría mal $gun:una; $r como tú para ayudarme aquí. Si cualquier día buscas trabajo, ¡recuerda lo bien que paga Gazlowe!', 0);
-- 522 Contrato de asesino
-- https://es.classic.wowhead.com/quest=522
SET @ID := 522;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, qué prisa traes! ¿Tienes noticias?', 0),
(@ID, 'esMX', '¡Vaya, qué prisa traes! ¿Tienes noticias?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maleb estudia el contrato.>$B$BEsto explica el ataque a Costasur; la Hermandad quiere liquidarme como hicieron con mi predecesor.', 0),
(@ID, 'esMX', '<Maleb estudia el contrato.>$B$BEsto explica el ataque a Costasur; la Hermandad quiere liquidarme como hicieron con mi predecesor.', 0);
-- 523 Muerte al Barón
-- https://es.classic.wowhead.com/quest=523
SET @ID := 523;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El barón Vardus no puede pensar que Costasur le permitirá enviar a sus matones contra nosotros con impunidad. ¡Quiero su cabeza!', 0),
(@ID, 'esMX', 'El barón Vardus no puede pensar que Costasur le permitirá enviar a sus matones contra nosotros con impunidad. ¡Quiero su cabeza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Mi cabeza descansa un poco más tranquila, sabiendo que ese villano perdió la suya.', 0),
(@ID, 'esMX', 'Gracias, $n. Mi cabeza descansa un poco más tranquila, sabiendo que ese villano perdió la suya.', 0);
-- 1108 Indurio
-- https://es.classic.wowhead.com/quest=1108
SET @ID := 1108;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste alguna lámina de indurio, $n? Tengo la forja preparada para recibirlas.', 0),
(@ID, 'esMX', '¿Encontraste alguna lámina de indurio, $n? Tengo la forja preparada para recibirlas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, estas son perfectas. Apliquémosles un poco de calor y veamos qué pasa...', 0),
(@ID, 'esMX', 'Bien, estas son perfectas. Apliquémosles un poco de calor y veamos qué pasa...', 0);
-- 2418 Las piedras de energía
-- https://es.classic.wowhead.com/quest=2418
SET @ID := 2418;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las piedras de energía, $n? Uno de mis roedores robóticos necesita una fuente de alimentación...', 0),
(@ID, 'esMX', '¿Tienes las piedras de energía, $n? Uno de mis roedores robóticos necesita una fuente de alimentación...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, encontraste algunas! Mil gracias, $n. ¡Eres $gel:la; $r más formal que he conocido!$B$BMe muero por probarlas en unos dispositivos que he fabricado. Apuesto que, en las circunstancias apropiadas, los dispositivos impulsados con estas piedras funcionarán, y funcionarán y funcionarán...', 0),
(@ID, 'esMX', '¡Fantástico, encontraste algunas! Mil gracias, $n. ¡Eres $gel:la; $r más formal que he conocido!$B$BMe muero por probarlas en unos dispositivos que he fabricado. Apuesto que, en las circunstancias apropiadas, los dispositivos impulsados con estas piedras funcionarán, y funcionarán y funcionarán...', 0);
-- 703 Alas de águila ratonera a la parrilla
-- https://es.classic.wowhead.com/quest=703
SET @ID := 703;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Me has traído mis alas?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Me has traído mis alas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, empezaré con esas alas enseguida. ¡Ya casi puedo saborearlas!$B$B¡Aquí tienes la receta en caso de que las quieras preparar tú $gmismo:misma;!', 0),
(@ID, 'esMX', 'Ah, empezaré con esas alas enseguida. ¡Ya casi puedo saborearlas!$B$B¡Aquí tienes la receta en caso de que las quieras preparar tú $gmismo:misma;!', 0);
-- 705 La pesca de perlas
-- https://es.classic.wowhead.com/quest=705
SET @ID := 705;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido mis perlas? ¡Casi no me quedan bombas centelleantes!', 0),
(@ID, 'esMX', '¿Has conseguido mis perlas? ¡Casi no me quedan bombas centelleantes!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vendrán de maravilla! Solo necesito molerlas en polvo... luego mezclarlas con una pizca de esto y otra pizca de aquello.$B$B¡Prepárense, carroñeros! ¡Prepárense para ser fulminados!', 0),
(@ID, 'esMX', '¡Vendrán de maravilla! Solo necesito molerlas en polvo... luego mezclarlas con una pizca de esto y otra pizca de aquello.$B$B¡Prepárense, carroñeros! ¡Prepárense para ser fulminados!', 0);
