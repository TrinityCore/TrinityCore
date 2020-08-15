-- 35 Más preocupaciones
-- https://es.wowhead.com/quest=35
-- https://wow-es.gamepedia.com/Misión:Más preocupaciones
SET @ID := 35;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, los múrlocs se han asentado a lo largo de los ríos del este de Elwynn. No sabemos por qué están ahí, pero son agresivos y, además, ¡son hasta un poco inteligentes!', 0);

-- 52 Proteger la frontera
-- https://es.wowhead.com/quest=52
-- https://wow-es.gamepedia.com/Misión:Proteger la frontera
SET @ID := 52;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has matado a esos lobos y a los osos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por tu ayuda, $n. Debe de haber algo en el bosque que está agitando a esos animales.$B$BSea lo que sea, espero que no salga de allí.', 0);

-- 37 Encuentra a los guardias perdidos
-- https://es.wowhead.com/quest=37
-- https://wow-es.gamepedia.com/Misión:Encuentra a los guardias perdidos
SET @ID := 37;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Aunque el cuerpo ha sido saqueado, cerca de él hay un medallón que nadie ha recogido. Tiene una inscripción: "Lacayo Malakai Roca".', 0);

-- 45 Descubre el destino de Rolf
-- https://es.wowhead.com/quest=45
-- https://wow-es.gamepedia.com/Misión:Descubre el destino de Rolf
SET @ID := 45;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Alrededor del cuello del cadáver hay un medallón de metal con una inscripción que reza: "Lacayo Rolf Hartford".', 0);

-- 39 Entrega el informe de Thomas
-- https://es.classic.wowhead.com/quest=39
SET @ID := 39;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm, son noticias preocupantes. Nuestras defensas ya están bastante mermadas y, ahora que hemos perdido a Rolf y Malakai a manos de esos murlocs, estamos incluso peor.$B$BSi las cosas no mejoran, para el final de la semana habrá un combate en Villadorada.', 0);

-- 59 Armadura de paño y cuero
-- https://es.wowhead.com/quest=59
-- https://wow-es.gamepedia.com/Misión:Armadura de paño y cuero
SET @ID := 59;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El ejército de Ventormenta me ha encargado que suministre a sus tropas tela y armaduras de cuero.$B$BSi tienes un marcador para mí, estaré encantada de hacerte algo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, gracias por el marcador. Por favor, elige la armadura que quieras.$B$BBuena suerte, valiente $c. Espero que esta armadura te sirva bien.', 0);

-- 1097 La tarea de Elmore
-- https://es.wowhead.com/quest=1097
-- https://wow-es.gamepedia.com/Misión:La tarea de Elmore
SET @ID := 1097;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Estás aquí para ayudar con la entrega? ¡Estupendo!', 0);

-- 239 El Cuartel de Arroyoeste necesita ayuda
-- https://es.wowhead.com/quest=239
-- https://wow-es.gamepedia.com/Misión:El Cuartel de Arroyoeste necesita ayuda
SET @ID := 239;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Te envía el alguacil Dughan, ¿eh? No eres del ejército, pero bueno, si te manda Dughan, me basta como referencia.$B$BNuestra situación es, como mínimo, apurada. Espero que puedas echarnos una mano.', 0);

-- 11 Recompensas por los gnolls Zarparrío
-- https://es.wowhead.com/quest=11
-- https://wow-es.gamepedia.com/Misión:Recompensas por los gnolls Zarparrío
SET @ID := 11;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Saludos, $n. ¿Has estado matando gnolls...?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Has estado muy ocupado! Muchas gracias, $n.', 0);

-- 176 Se busca: Hogger
-- https://es.wowhead.com/quest=176
-- https://wow-es.gamepedia.com/Misión:Se busca: Hogger
SET @ID := 176;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, Hogger ha sido un auténtico estorbo para mí y para mis hombres. ¿Tines algo de que informar sobre la bestia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Que ha hecho QUÉ?$B$BGenial, ahora tenemos una bestia sanguinaria justo bajo las calles de Ventormenta con todo un ejército de gnolls a su disposición. Qué gran mejora, ya me siento más seguro.$B$BAquí tienes tu recompensa, $n, pero prométeme que irás a ver a los guardias de las Mazmorras en algún momento para asegurarte de que todo va bien.', 0);

-- 176 Se busca: Hogger
-- https://es.classic.wowhead.com/quest=176
SET @ID := 176;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Sí, Hogger ha sido un auténtico estorbo para mí y para mis hombres. ¿Tines algo de que informar sobre la bestia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ja! ¡Muy bien! ¡Empezaba a creer que nadie conseguiría abatir a ese monstruo!$B$BAquí tienes, $n. Y gracias, ese gnoll era un dolor de cabeza tan monumental como la Cumbre de Roca Negra!', 0);

-- 46 Recompensas por los múrlocs
-- https://es.wowhead.com/quest=46
-- https://wow-es.gamepedia.com/Misión:Recompensas por los múrlocs
SET @ID := 46;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo va la caza, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes las aletas? ¡Genial! El alguacil Dughan está ansioso por recibir noticias del estado de la situación en Elwynn y me gustaría decirle que empezamos a controlar la situación.$B$BTus acciones han contribuido a que sea posible.', 0);

-- 83 Pañuelos de lino rojo
-- https://es.wowhead.com/quest=83
-- https://wow-es.gamepedia.com/Misión:Pañuelos de lino rojo
SET @ID := 83;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me estoy quedando sin lino, $n. ¿No tendrás tú algo de lino que me puedas dar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, qué pañuelos tan estupendos... son un poco ásperos, pero...$B$B¡Ten!', 0);

-- 5545 El cumplimiento del plazo
-- https://es.wowhead.com/quest=5545
-- https://wow-es.gamepedia.com/Misión:El cumplimiento del plazo
SET @ID := 5545;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ese plazo se acerca cada vez más, $c. Te lo ruego, date prisa en recoger la madera.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Fantástico! Gracias a ti, debería poder cumplir con el plazo. Quisiera demostrarte mi agradecimiento dándote algunas monedas.$B$BGracias y adiós.', 0);

-- 109 Habla con Gryan Mantorrecio
-- https://es.classic.wowhead.com/quest=109
SET @ID := 109;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que te ha enviado aquí mi amigo, ¿eh? Qué amable por su parte.$B$BBien, te diré que la monarquía de Ventormenta nos ha abandonado. Ahora son Las Milicias del Pueblo las que mantienen la tierra a salvo de la corrupción. Si nuestra causa te interesa, puedo ofrecer a tus habilidades de combate un trabajo al servicio de la libertad.', 0);