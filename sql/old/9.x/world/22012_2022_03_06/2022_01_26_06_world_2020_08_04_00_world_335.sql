-- 244 Gnolls invasores
-- https://es.classic.wowhead.com/quest=244
SET @ID := 244;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Hay gnolls de Crestagrana tan cerca de Elwynn? Puede que planeen una invasión... ¡Los de Villa del Lago ya no serán los únicos humanos bajo asedio!$B$BAquí tienes el pago, pese a las noticias que traes. Y en qué mal momento: carecemos de recursos.', 0);

-- 246 Evaluar la amenaza
-- https://es.classic.wowhead.com/quest=246
SET @ID := 246;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Disculpe, $n, pero tenemos mucho que hacer como para mantener nuestras manos atadas aquí. Si no tiene nada que informar, entonces debo ocuparme de otros asuntos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<El ayudante del alguacil Feldon escucha tu informe...>$B$BAsí que hay un grupo numeroso de gnolls de los duros. Seguro que no te ha sido fácil recopilar esta información.$B$BTen, $n, y gracias por tu ayuda.$B$BHabla con el alguacil Marris y el magistrado Salomón en Villa del Lago. Necesitarán tu ayuda; la situación empeora por momentos.', 0);

-- 129 Una comida gratis
-- https://es.classic.wowhead.com/quest=129
SET @ID := 129;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Que Darcy me envía la comida? Pues venga, ¡a mover el bigote!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, me muero de hambre. ¡Proteger la ciudad de los orcos y los gnolls es un trabajo duro!', 0);

-- 14079 Aprende a montar en el Bosque de Elwynn
-- https://es.wowhead.com/quest=14079
SET @ID := 14079;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ¿recibiste mi carta? Bien.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Entonces, ¿comenzaremos tu entrenamiento de Aprendiz de Jinete?', 0);

-- 130 Una visita al herborista
-- https://es.classic.wowhead.com/quest=130
SET @ID := 130;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Un ramo de flores? ¿Acabas de llegar y ya estás con romances?$B$BNo es por chafardear, pero los amores juveniles son tan bonitos... sobre todo en tiempos de guerra.', 0);

-- 131 Un ramo de narcisos
-- https://es.classic.wowhead.com/quest=131
SET @ID := 131;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. ¿Le gustó la comida a Parker?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Qué bonitas! ¡Y qué bien huelen!$B$BPero son las flores favoritas de Martie. ¿No me digas que Parker te mandó a comprarle las flores a esa bruja? No le dijiste que eran para mí, ¿verdad? Porque si lo sabía, seguro que puso veneno.$B$BEn fin, no es culpa tuya. Gracias, y aquí tienes la comida.', 0);

-- 3741 El collar de Hilary
-- https://es.classic.wowhead.com/quest=3741
SET @ID := 3741;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, ¿has encontrado mi collar? Papá dice que hay monstruos en el lago; ¿has visto alguno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por encontrar mi collar, $gseñor:señora; $c... Mi gatita también dice gracias, ¿a que sí, Effsee?', 0);

-- 125 Las herramientas perdidas
-- https://es.classic.wowhead.com/quest=125
SET @ID := 125;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Me traes las herramientas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Excelente trabajo, $n. Pensé que no volvería a ver mis herramientas.', 0);

-- 150 Cazadores furtivos
-- https://es.classic.wowhead.com/quest=150
SET @ID := 150;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes las aletas? ¡Tenemos que echar a los múrlocs del lago!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo, $n.$B$BEs raro que estén tan lejos del mar; puede que estuvieran huyendo de algo...', 0);

-- 127 Pescado a la venta
-- https://es.classic.wowhead.com/quest=127
SET @ID := 127;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ha sido un placer!', 0);

-- 89 El puente sempiterno
-- https://es.classic.wowhead.com/quest=89
SET @ID := 89;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡El puente no va a construirse solo! ¿Dónde están las picas y los remaches?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo, $n. Con esto podemos ir avanzando los trabajos del puente.', 0);

-- 92 Estofado Crestagrana
-- https://es.classic.wowhead.com/quest=92
SET @ID := 92;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 5 filetes de carne dura de cóndor, 5 morros de dentosangre grandes y 5 raciones de carne de araña crujiente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Muchas gracias, $n. Aquí tienes el delicioso estofado de Crestagrana prometido.', 0);

-- 34 Una visita poco grata
-- https://es.classic.wowhead.com/quest=34
SET @ID := 34;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has acabado ya con Panzallena?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Por fin! Gracias, $n, me has hecho un favor enorme. ¡Este año el jardín estará precioso!', 0);

-- 20 La amenaza de los Roca Negra
-- https://es.classic.wowhead.com/quest=20
SET @ID := 20;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has estado liquidando orcos, $n? Demuéstramelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ahora hay muchos menos orcos de los que ocuparse; gracias.', 0);

-- 128 La recompensa de Roca Negra
-- https://es.classic.wowhead.com/quest=128
SET @ID := 128;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Regresa una vez que hayas matado a 15 campeones de Roca Negra', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has mostrado gran valor frente a los Roca Negra, $c. Nos has prestado un gran servicio.', 0);

-- 115 Magia de las Sombras
-- https://es.classic.wowhead.com/quest=115
SET @ID := 115;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo va con los taumaturgos umbríos? ¿Tienes los orbes de medianoche?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, $n. Acabaré con ellos de inmediato.', 0);

-- 169 Se busca: Gath'Ilzogg
-- https://es.classic.wowhead.com/quest=169
SET @ID := 169;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué llevas ahí, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Buen trabajo, $n! Gath\'Ilzogg es responsable de la muerte de muchos humanos. Nos hemos vengado. ¡Estamos un paso más cerca de reconquistar el castillo!', 0);
