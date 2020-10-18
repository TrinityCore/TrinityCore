-- 583 Bienvenido a la jungla
-- https://es.classic.wowhead.com/quest=583
SET @ID := 583;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un placer conocerte, $n. Hacía mucho tiempo que no veía a $gun:una; $c por aquí.$B$BMe metí en esta expedición por una razón: para cazar a una gran bestia esquiva. Viendo que eres $gun:una; gran $ghéroe:heroína;, voy a permitirte participar en la cacería, pero primero, debes demostrar tu valía.$B$BTe enseñaré cómo matar raptores. Ajeck te instruirá en la cacería de tigres. Y Sir Erlgadin es un maestro del rastreo de panteras.$B$BDemuestra tu habilidad y te permitiré participar en la gran cacería.', 0),
(@ID, 'esMX', 'Un placer conocerte, $n. Hacía mucho tiempo que no veía a $gun:una; $c por aquí.$B$BMe metí en esta expedición por una razón: para cazar a una gran bestia esquiva. Viendo que eres $gun:una; gran $ghéroe:heroína;, voy a permitirte participar en la cacería, pero primero, debes demostrar tu valía.$B$BTe enseñaré cómo matar raptores. Ajeck te instruirá en la cacería de tigres. Y Sir Erlgadin es un maestro del rastreo de panteras.$B$BDemuestra tu habilidad y te permitiré participar en la gran cacería.', 0);
-- 194 Domina el raptor
-- https://es.classic.wowhead.com/quest=194
SET @ID := 194;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca conocí a un cazador que matase estando parado junto a la fogata, bueno, excepto mi padre. ¿Planeabas matar a esos Raptores de Tuercespina o esperabas que murieran de viejos?', 0),
(@ID, 'esMX', 'Nunca conocí a un cazador que matase estando parado junto a la fogata, bueno, excepto mi padre. ¿Planeabas matar a esos Raptores de Tuercespina o esperabas que murieran de viejos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo magistral, $gamigo:amiga;.', 0),
(@ID, 'esMX', 'Un trabajo magistral, $gamigo:amiga;.', 0);
-- 185 Domina el tigre
-- https://es.classic.wowhead.com/quest=185
SET @ID := 185;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No estoy segura de entrenarte más, $n, no hasta que hayas demostrado tu habilidad para matar tigres jóvenes.', 0),
(@ID, 'esMX', 'No estoy segura de entrenarte más, $n, no hasta que hayas demostrado tu habilidad para matar tigres jóvenes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Puedes seguir adelante.', 0),
(@ID, 'esMX', 'Muy bien, $n. Puedes seguir adelante.', 0);
-- 190 Domina la pantera
-- https://es.classic.wowhead.com/quest=190
SET @ID := 190;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gUn:Una; $gverdadero:verdadera; $gcazador:cazadora; de panteras estaría en el campo, tratando de acechar a su presa. Demuestra algo de compromiso con tu objetivo, $c, y vuelve a salir.', 0),
(@ID, 'esMX', '$gUn:Una; $gverdadero:verdadera; $gcazador:cazadora; de panteras estaría en el campo, tratando de acechar a su presa. Demuestra algo de compromiso con tu objetivo, $c, y vuelve a salir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que tengas buena suerte, $n!', 0),
(@ID, 'esMX', '¡Que tengas buena suerte, $n!', 0);
-- 210 La cocina de Krazek
-- https://es.classic.wowhead.com/quest=210
SET @ID := 210;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Me has traído algo?', 0),
(@ID, 'esMX', '¡Hola! ¿Me has traído algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ya veo, es la olla de barro de Krazek. Un objeto muy ingenioso, pero, de vez en cuando, se le salta algún muelle que otro. Veamos qué le pasa...$B$B¡Ajá! El cargador de vapor está oxidado, tiene una junta rota y le faltan dientes al fobulador. ¡Me sorprende que la olla haya sido capaz incluso de cocer un nabo en este estado!$B$B¿Puedo arreglarla? Pues claro que sí.$B$BPero todo en esta vida tiene un precio. Oh, sí, siempre hay que pagar un precio...', 0),
(@ID, 'esMX', 'Oh, ya veo, es la olla de barro de Krazek. Un objeto muy ingenioso, pero, de vez en cuando, se le salta algún muelle que otro. Veamos qué le pasa...$B$B¡Ajá! El cargador de vapor está oxidado, tiene una junta rota y le faltan dientes al fobulador. ¡Me sorprende que la olla haya sido capaz incluso de cocer un nabo en este estado!$B$B¿Puedo arreglarla? Pues claro que sí.$B$BPero todo en esta vida tiene un precio. Oh, sí, siempre hay que pagar un precio...', 0);
-- 338 Las verdes colinas de Tuercespina
-- https://es.classic.wowhead.com/quest=338
SET @ID := 338;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya los capítulos, $n?', 0),
(@ID, 'esMX', '¿Tienes ya los capítulos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me has ahorrado muchos problemas, $n. No puedo agradecértelo lo suficiente. No tardaremos mucho en ver el libro de Nesingwary en las bibliotecas de todo el mundo.', 0),
(@ID, 'esMX', 'Me has ahorrado muchos problemas, $n. No puedo agradecértelo lo suficiente. No tardaremos mucho en ver el libro de Nesingwary en las bibliotecas de todo el mundo.', 0);
-- 195 Domina el raptor
-- https://es.classic.wowhead.com/quest=195
SET @ID := 195;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un auténtico cazador se centra en su presa. Usted, amigo mío, parece más preocupado por charlar alrededor de la fogata. Ahora sal y mata a 10 colazote antes de que me vaya a librarme de toda la jungla sangrienta de una sola cazería.', 0),
(@ID, 'esMX', 'Un auténtico cazador se centra en su presa. Usted, amigo mío, parece más preocupado por charlar alrededor de la fogata. Ahora sal y mata a 10 colazote antes de que me vaya a librarme de toda la jungla sangrienta de una sola cazería.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así es como se consiguen un par de trofeos para poner encima de la chimenea! ¡Bien hecho, $n!', 0),
(@ID, 'esMX', '¡Así es como se consiguen un par de trofeos para poner encima de la chimenea! ¡Bien hecho, $n!', 0);
-- 196 Domina el raptor
-- https://es.classic.wowhead.com/quest=196
SET @ID := 196;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bah! ¡Qué estás haciendo $gparado:parada;, $n! Un verdadero cazador de caza mayor nunca se rinde una vez que su presa está en la mira. Esos Acechadores de la selva no vendrán corriendo a esta fogata y se lanzarán a ella. $gTío:Tía; $gtonto:tonta;.', 0),
(@ID, 'esMX', '¡Bah! ¡Qué estás haciendo $gparado:parada;, $n! Un verdadero cazador de caza mayor nunca se rinde una vez que su presa está en la mira. Esos Acechadores de la selva no vendrán corriendo a esta fogata y se lanzarán a ella. $gTío:Tía; $gtonto:tonta;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¡Jo, jo!! ¡Tenemos $gun:una; $gauténtico:auténtica; cazaraptores! Un trabajo magistral, $gamigo:amiga;.', 0),
(@ID, 'esMX', '¡¡Jo, jo!! ¡Tenemos $gun:una; $gauténtico:auténtica; cazaraptores! Un trabajo magistral, $gamigo:amiga;.', 0);
-- 597 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=597
SET @ID := 597;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Claro que me acuerdo de ti, $c. Veo que has vuelto de tu exploración...', 0),
(@ID, 'esMX', 'Claro que me acuerdo de ti, $c. Veo que has vuelto de tu exploración...', 0);
-- 607 Regresa junto a MacKinley
-- https://es.classic.wowhead.com/quest=607
SET @ID := 607;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, hola, $n. ¿Has conseguido que el Trémulo te pagase?', 0),
(@ID, 'esMX', 'Hola, hola, $n. ¿Has conseguido que el Trémulo te pagase?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Je, je, bien hecho! Y cuando le enseñaste a Trémulo esos menudillos, ¿se puso a temblar?$B$B¡Ja! Es muy predecible, cuando juego a las cartas con él, siempre gano.$B$BGracias por tu ayuda, $n. Ahora me toca pagarte a ti...', 0),
(@ID, 'esMX', '¡Je, je, bien hecho! Y cuando le enseñaste a Trémulo esos menudillos, ¿se puso a temblar?$B$B¡Ja! Es muy predecible, cuando juego a las cartas con él, siempre gano.$B$BGracias por tu ayuda, $n. Ahora me toca pagarte a ti...', 0);
-- 599 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=599
SET @ID := 599;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Bucaneros Velasangre atacando Bahía del Botín? Para eso, podrían tirarse de Los Acantilados Dominantes abajo. De todas formas, trayendo esta información nos has hecho un gran servicio a mí y a mi flota de aventureros. Los asaltantes Aguasnegras te dan las gracias.', 0),
(@ID, 'esMX', '¿Bucaneros Velasangre atacando Bahía del Botín? Para eso, podrían tirarse de Los Acantilados Dominantes abajo. De todas formas, trayendo esta información nos has hecho un gran servicio a mí y a mi flota de aventureros. Los asaltantes Aguasnegras te dan las gracias.', 0);
-- 576 ¡Ojo!
-- https://es.classic.wowhead.com/quest=576
SET @ID := 576;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, colega! Quizás no puedo ver, pero te huelo desde el otro lao del puerto.$B$BMe vendría mu bien recuperar el ojo. El capitán va a pasarme por la quilla cuando descubra que mi aujero de ver lo tienen esos asquerosos Bucaneros Velasangre.$B$B¿De qué vale un vigía que no puede ver? La torre del vigía solía ser mi hogar... ahora, sin mi ojo, tendré suerte si puedo fregar la quilla.', 0),
(@ID, 'esMX', '¡Hola, colega! Quizás no puedo ver, pero te huelo desde el otro lao del puerto.$B$BMe vendría mu bien recuperar el ojo. El capitán va a pasarme por la quilla cuando descubra que mi aujero de ver lo tienen esos asquerosos Bucaneros Velasangre.$B$B¿De qué vale un vigía que no puede ver? La torre del vigía solía ser mi hogar... ahora, sin mi ojo, tendré suerte si puedo fregar la quilla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Voto a bríos! ¡Has encontrao mi precioso ojo! Veamos si sigue funcionando.$B$B¡Jo, jo, jo, $n! ¡¡Fantástico, puedo ver!!', 0),
(@ID, 'esMX', '¡Voto a bríos! ¡Has encontrao mi precioso ojo! Veamos si sigue funcionando.$B$B¡Jo, jo, jo, $n! ¡¡Fantástico, puedo ver!!', 0);
