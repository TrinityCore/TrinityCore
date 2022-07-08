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
-- 577 Hay que ensamblar
-- https://es.classic.wowhead.com/quest=577
SET @ID := 577;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las botas de cuero estilo borceguí de Drizzlik, la mejor artesanía, cien por cien botas de piel de crocolisco aguasalada de la mejor calidad. ¡Insuperables!$B$B¿A que no se puede superar una descripción como esa, eh?$B$BA no ser... ¿tienes esas pieles que te pedí?', 0),
(@ID, 'esMX', 'Las botas de cuero estilo borceguí de Drizzlik, la mejor artesanía, cien por cien botas de piel de crocolisco aguasalada de la mejor calidad. ¡Insuperables!$B$B¿A que no se puede superar una descripción como esa, eh?$B$BA no ser... ¿tienes esas pieles que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis botas... son como salchichas, $n. Tienen una pinta estupenda y están buenísimas. Te digo que están hechas solo con las mejores carnes e ingredientes y, si las pruebas, te encantarán.$B$BEs más seguro, y más agradable, que simplemente confíes en mí y no preguntes lo que tienen dentro.', 0),
(@ID, 'esMX', 'Mis botas... son como salchichas, $n. Tienen una pinta estupenda y están buenísimas. Te digo que están hechas solo con las mejores carnes e ingredientes y, si las pruebas, te encantarán.$B$BEs más seguro, y más agradable, que simplemente confíes en mí y no preguntes lo que tienen dentro.', 0);
-- 627 Un favor a Krazek
-- https://es.classic.wowhead.com/quest=627
SET @ID := 627;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has conseguido la sangrita?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has conseguido la sangrita?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Menuda maravilla! Me has hecho un gran favor.$B$BAquí tienes tu pago...', 0),
(@ID, 'esMX', '¡Menuda maravilla! Me has hecho un gran favor.$B$BAquí tienes tu pago...', 0);
-- 209 Colmillos Machacacráneos
-- https://es.classic.wowhead.com/quest=209
SET @ID := 209;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Unos bichos duros, ¿verdad? ¿Y bien? ¿Has tenido suerte? Perdona mi impaciencia, ¡pero esto ha sido una enorme espina clavada...! ¿¿Y bien??', 0),
(@ID, 'esMX', 'Unos bichos duros, ¿verdad? ¿Y bien? ¿Has tenido suerte? Perdona mi impaciencia, ¡pero esto ha sido una enorme espina clavada...! ¿¿Y bien??', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡buen trabajo, buen trabajo! Ejem... aunque podrías haber hecho una labor de limpieza más minuciosa... en fin, no importa. Te lo agradezco, $n, gracias a ti, nuestra operación tendrá un resultado mejor y un aumento de productividad. Bien, bien, pasemos a otros asuntos...', 0),
(@ID, 'esMX', 'Ah, ¡buen trabajo, buen trabajo! Ejem... aunque podrías haber hecho una labor de limpieza más minuciosa... en fin, no importa. Te lo agradezco, $n, gracias a ti, nuestra operación tendrá un resultado mejor y un aumento de productividad. Bien, bien, pasemos a otros asuntos...', 0);
-- 601 Elementales de agua
-- https://es.classic.wowhead.com/quest=601
SET @ID := 601;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte, $n?', 0),
(@ID, 'esMX', '¿Has tenido suerte, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, no tengo capacidad para examinar los brazales y ver si alguno podría servirnos, pero seguro que, al menos uno, podrá ayudarnos. Llévalos a Dalaran y haz que un mago los vea.$B$BDespués de todo, yo no puedo irme tranquilamente de la Bahía del Botín para charlar con esos viejos magos cansados de la vida.$B$BNo me preocupa que alguien intente abrirse paso para convertirse en el nuevo barón. Nadie se interpone a Revilgaz y vive para contarlo.', 0),
(@ID, 'esMX', 'Mmm, no tengo capacidad para examinar los brazales y ver si alguno podría servirnos, pero seguro que, al menos uno, podrá ayudarnos. Llévalos a Dalaran y haz que un mago los vea.$B$BDespués de todo, yo no puedo irme tranquilamente de la Bahía del Botín para charlar con esos viejos magos cansados de la vida.$B$BNo me preocupa que alguien intente abrirse paso para convertirse en el nuevo barón. Nadie se interpone a Revilgaz y vive para contarlo.', 0);
-- 604 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=604
SET @ID := 604;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Qué noticias traes del campamento Velasangre del sur?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Qué noticias traes del campamento Velasangre del sur?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, $n. Ahora que conocemos su plan, solo es cuestión de tiempo.$B$BY pensar que esos imbéciles han soltado el ancla justo fuera del cabo...', 0),
(@ID, 'esMX', 'Perfecto, $n. Ahora que conocemos su plan, solo es cuestión de tiempo.$B$BY pensar que esos imbéciles han soltado el ancla justo fuera del cabo...', 0);
-- 587 Tabaco rapé
-- https://es.classic.wowhead.com/quest=587
SET @ID := 587;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte, colega?', 0),
(@ID, 'esMX', '¿Has tenido suerte, colega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien hecho, $n! ¡Y justo cuando yo también tengo que embarcar! No te lo puedo agradecer bastante, $gviejo:vieja; $gamigo:amiga;.', 0),
(@ID, 'esMX', '¡Muy bien hecho, $n! ¡Y justo cuando yo también tengo que embarcar! No te lo puedo agradecer bastante, $gviejo:vieja; $gamigo:amiga;.', 0);
-- 600 La minería de Ventura y Cía.
-- https://es.classic.wowhead.com/quest=600
SET @ID := 600;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esos cristales? ¡¡Los necesito!!$B$BVamos a ver... necesito saber que la maldita Ventura y Cía. está perdiendo terreno en Tuercespina. Porque, ¿sabes?, los profesionales honestos tenemos que vivir de algo...', 0),
(@ID, 'esMX', '¿Tienes esos cristales? ¡¡Los necesito!!$B$BVamos a ver... necesito saber que la maldita Ventura y Cía. está perdiendo terreno en Tuercespina. Porque, ¿sabes?, los profesionales honestos tenemos que vivir de algo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡Estupendo! ¡¡Puedo conseguir mucho por esto!!$B$BEsa Ventura y Cía. eligieron la selva equivocada donde excavar, ¿eh? A todos nos vendría estupendamente bien que se fueran de aquí.$B$BGracias, $n. Hoy has hecho una buena acción.', 0),
(@ID, 'esMX', '¡Genial! ¡Estupendo! ¡¡Puedo conseguir mucho por esto!!$B$BEsa Ventura y Cía. eligieron la selva equivocada donde excavar, ¿eh? A todos nos vendría estupendamente bien que se fueran de aquí.$B$BGracias, $n. Hoy has hecho una buena acción.', 0);
-- 617 Tallos de juncos akiris
-- https://es.classic.wowhead.com/quest=617
SET @ID := 617;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no tienes nada que me incumba, sigue tu camino, $n.', 0),
(@ID, 'esMX', 'Si no tienes nada que me incumba, sigue tu camino, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Después de todo, ¿no ha sido tan difícil conseguir 10 tallos de juncos akiris, eh? Sin ofender a los naga, ¡pero todo el mundo tiene derecho a ganarse la vida!', 0),
(@ID, 'esMX', 'Bien hecho, $n. Después de todo, ¿no ha sido tan difícil conseguir 10 tallos de juncos akiris, eh? Sin ofender a los naga, ¡pero todo el mundo tiene derecho a ganarse la vida!', 0);
