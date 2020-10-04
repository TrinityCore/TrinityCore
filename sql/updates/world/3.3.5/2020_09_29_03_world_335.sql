-- 609 El vudú debido
-- https://es.classic.wowhead.com/quest=609
SET @ID := 609;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has encontrado a esos tres perros? ¿Tienes sus posesiones?', 0),
(@ID, 'esMX', '$n, ¿has encontrado a esos tres perros? ¿Tienes sus posesiones?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! ¡Podré conseguir un buen precio! Especialmente, por lo que hay en el pie de Maury. Muchas gracias, $n.$B$BEspero que esos tres hayan aprendido la lección: no apuestes algo que no puedes permitirte perder.$B$BY quizás sea demasiado tarde para ellos... deberían tener cuidado con quién apuestan.', 0),
(@ID, 'esMX', '¡Fantástico! ¡Podré conseguir un buen precio! Especialmente, por lo que hay en el pie de Maury. Muchas gracias, $n.$B$BEspero que esos tres hayan aprendido la lección: no apuestes algo que no puedes permitirte perder.$B$BY quizás sea demasiado tarde para ellos... deberían tener cuidado con quién apuestan.', 0);
-- 608 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=608
SET @ID := 608;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Cuál es el problema, $n? ¡Tenemos que atacar antes de que lo hagan los Bucaneros Velasangre!', 0),
(@ID, 'esMX', '¿¿Cuál es el problema, $n? ¡Tenemos que atacar antes de que lo hagan los Bucaneros Velasangre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué día tan fantástico para los asaltantes Aguasnegras! ¡Tres hurras por ti, $n!', 0),
(@ID, 'esMX', '¡Ah, qué día tan fantástico para los asaltantes Aguasnegras! ¡Tres hurras por ti, $n!', 0);
-- 623 Tallos de juncos akiris
-- https://es.classic.wowhead.com/quest=623
SET @ID := 623;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué?! Tengo muchas cosas mejores que hacer que hablar con tipos como tú, $c. Haz que merezca la pena, o lárgate de aquí.$B$B¿De acuerdo? Bloads te ha enviado, ¿eh? A ver, ¿qué tienes pa mí?$B$B<El corsario Groy examina el paquete con atención>$B$BNo está mal, nada mal. Con otro de estos, mi cliente estaría mu contento.$B$BSupongo que tu próxima pregunta va a ser sobre el dinero, ¿eh, $c? ¡Pues claro que sí!$B$BToma, te voy a dar unas monedas y un consejo: largo de mi muelle.', 0),
(@ID, 'esMX', '¡¿Qué?! Tengo muchas cosas mejores que hacer que hablar con tipos como tú, $c. Haz que merezca la pena, o lárgate de aquí.$B$B¿De acuerdo? Bloads te ha enviado, ¿eh? A ver, ¿qué tienes pa mí?$B$B<El corsario Groy examina el paquete con atención>$B$BNo está mal, nada mal. Con otro de estos, mi cliente estaría mu contento.$B$BSupongo que tu próxima pregunta va a ser sobre el dinero, ¿eh, $c? ¡Pues claro que sí!$B$BToma, te voy a dar unas monedas y un consejo: largo de mi muelle.', 0);
-- 197 Domina el raptor
-- https://es.classic.wowhead.com/quest=197
SET @ID := 197;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza de $n? ¿Has conseguido seguirle la pista de vuelta al campamento, no?', 0),
(@ID, 'esMX', '¿Cómo va la caza de $n? ¿Has conseguido seguirle la pista de vuelta al campamento, no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maestro $n, ¡el Cazaraptores!$B$B¿A que suena bien?', 0),
(@ID, 'esMX', 'Maestro $n, ¡el Cazaraptores!$B$B¿A que suena bien?', 0);
-- 191 Domina la pantera
-- https://es.classic.wowhead.com/quest=191
SET @ID := 191;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ve a matar 10 panteras! ¡Muéstranos de que estas $ghecho:hecha;!', 0),
(@ID, 'esMX', '¡Ve a matar 10 panteras! ¡Muéstranos de que estas $ghecho:hecha;!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una ejecución perfecta, $n!', 0),
(@ID, 'esMX', '¡Una ejecución perfecta, $n!', 0);
-- 192 Domina la pantera
-- https://es.classic.wowhead.com/quest=192
SET @ID := 192;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué estás haciendo aquí, $n! Deberías estar arrastrándote por la maleza, tratando de matar a 10 Panteras Faucesombrías. Pensé que te imaginabas en el gran juego $c.', 0),
(@ID, 'esMX', '¡Qué estás haciendo aquí, $n! Deberías estar arrastrándote por la maleza, tratando de matar a 10 Panteras Faucesombrías. Pensé que te imaginabas en el gran juego $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado, $n!', 0),
(@ID, 'esMX', '¡Lo has logrado, $n!', 0);
-- 193 Domina la pantera
-- https://es.classic.wowhead.com/quest=193
SET @ID := 193;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bhag\'thera puede ser una bestia muy esquiva. ¿Cómo va la caza?', 0),
(@ID, 'esMX', 'Bhag\'thera puede ser una bestia muy esquiva. ¿Cómo va la caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así que la gran Bhag\'thera está muerta! Enhorabuena, $n. ¡Eres $gun:una; $gpoderoso:poderosa; $c!', 0),
(@ID, 'esMX', '¡Así que la gran Bhag\'thera está muerta! Enhorabuena, $n. ¡Eres $gun:una; $gpoderoso:poderosa; $c!', 0);
-- 186 Persigue al tigre
-- https://es.classic.wowhead.com/quest=186
SET @ID := 186;
UPDATE `quest_template_locale` SET `Objectives` = 'Ajeck Rouack de la Expedición de Nesingwary, quiere que mates 10 tigres de Tuercespina.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si te esfuerzas por alcanzar mayores desafíos, antes debes demostrar su valía con esta tarea. Regresa a mí después de que hayas matado a 10 tigres de Tuercespina.', 0),
(@ID, 'esMX', 'Si te esfuerzas por alcanzar mayores desafíos, antes debes demostrar su valía con esta tarea. Regresa a mí después de que hayas matado a 10 tigres de Tuercespina.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me impresionas, $c. Estás progresando mucho.', 0),
(@ID, 'esMX', 'Me impresionas, $c. Estás progresando mucho.', 0);
-- 187 Domina el tigre
-- https://es.classic.wowhead.com/quest=187
SET @ID := 187;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes matar a 10 tigres de Tuercespina mayores antes de que te dé el desafío final que determinará si eres $gun:una; $gverdadero:verdadera; $gmaestro:maestra; de la caza de tigres.', 0),
(@ID, 'esMX', 'Debes matar a 10 tigres de Tuercespina mayores antes de que te dé el desafío final que determinará si eres $gun:una; $gverdadero:verdadera; $gmaestro:maestra; de la caza de tigres.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante. Creo que casi estás $gpreparado:preparada;.', 0),
(@ID, 'esMX', 'Impresionante. Creo que casi estás $gpreparado:preparada;.', 0);
-- 188 Domina el tigre
-- https://es.classic.wowhead.com/quest=188
SET @ID := 188;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal va la caza de Sin\'Dall?', 0),
(@ID, 'esMX', '¿Qué tal va la caza de Sin\'Dall?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Absolutamente impresionante! ¡Eres $gun:una; $gauténtico:auténtica; $gmaestro:maestras; $gcazador:cazadora; de tigres, $n!', 0),
(@ID, 'esMX', '¡Absolutamente impresionante! ¡Eres $gun:una; $gauténtico:auténtica; $gmaestro:maestras; $gcazador:cazadora; de tigres, $n!', 0);
-- 339 Capítulo I
-- https://es.classic.wowhead.com/quest=339
SET @ID := 339;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Supongo que no has conseguido las páginas 1, 4, 6 y 8? Necesitamos esas cuatro para completar el capítulo I.', 0),
(@ID, 'esMX', '¿Supongo que no has conseguido las páginas 1, 4, 6 y 8? Necesitamos esas cuatro para completar el capítulo I.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin! El capítulo I está completo.', 0),
(@ID, 'esMX', '¡Al fin! El capítulo I está completo.', 0);
-- 340 Capítulo II
-- https://es.classic.wowhead.com/quest=340
SET @ID := 340;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Seguimos necesitando las páginas 10, 11, 14 y 16 para completar el capítulo II, $n.', 0),
(@ID, 'esMX', 'Seguimos necesitando las páginas 10, 11, 14 y 16 para completar el capítulo II, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El capítulo II está completo. ¡Bien hecho!', 0),
(@ID, 'esMX', 'El capítulo II está completo. ¡Bien hecho!', 0);
-- 341 Capítulo III
-- https://es.classic.wowhead.com/quest=341
SET @ID := 341;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido suerte con las páginas 18, 20, 21 o 24? Son las únicas que faltan para completar el capítulo III.', 0),
(@ID, 'esMX', '¿Has tenido suerte con las páginas 18, 20, 21 o 24? Son las únicas que faltan para completar el capítulo III.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Puff! Buen trabajo, $n. El capítulo III está completo.', 0),
(@ID, 'esMX', '¡Puff! Buen trabajo, $n. El capítulo III está completo.', 0);
-- 342 Capítulo IV
-- https://es.classic.wowhead.com/quest=342
SET @ID := 342;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo necesitamos tres páginas para acabar el capítulo IV, $n. ¿Tienes las páginas 25, 26 o 27?', 0),
(@ID, 'esMX', 'Solo necesitamos tres páginas para acabar el capítulo IV, $n. ¿Tienes las páginas 25, 26 o 27?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Ya tenemos el capítulo IV!', 0),
(@ID, 'esMX', '¡Excelente! ¡Ya tenemos el capítulo IV!', 0);
-- 208 Caza mayor
-- https://es.classic.wowhead.com/quest=208
SET @ID := 208;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has vuelto, $gviejo:vieja; $gamigo:amiga;. El rey Bangalash me ha obligado a volver arrastrándome al campamento demasiadas veces. Espera un momento.', 0),
(@ID, 'esMX', 'Veo que has vuelto, $gviejo:vieja; $gamigo:amiga;. El rey Bangalash me ha obligado a volver arrastrándome al campamento demasiadas veces. Espera un momento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Pero qué maravilla! ¡Eso es! Enhorabuena, $n, por salir $gvictorioso:victoriosa; ahí donde otros fracasaron.$B$BEs un honor para mí contarte entre mis camaradas de caza mayor. ¡Nadie podrá poner en duda tu pericia en la caza y el rastreo!$B$B¡Levanto mi copa por ti, salud! ¡Salud!', 0),
(@ID, 'esMX', '¡Pero qué maravilla! ¡Eso es! Enhorabuena, $n, por salir $gvictorioso:victoriosa; ahí donde otros fracasaron.$B$BEs un honor para mí contarte entre mis camaradas de caza mayor. ¡Nadie podrá poner en duda tu pericia en la caza y el rastreo!$B$B¡Levanto mi copa por ti, salud! ¡Salud!', 0);
-- 204 Mala medicina
-- https://es.classic.wowhead.com/quest=204
SET @ID := 204;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy esperando los remedios y el extracto, $n.', 0),
(@ID, 'esMX', 'Estoy esperando los remedios y el extracto, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Estos remedios conseguirán mantener a más de nosotros con vida y en buena forma. Y los extractos nos ayudarán a crear nuestros propios remedios.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Estos remedios conseguirán mantener a más de nosotros con vida y en buena forma. Y los extractos nos ayudarán a crear nuestros propios remedios.', 0);
-- 203 La segunda rebelión
-- https://es.classic.wowhead.com/quest=203
SET @ID := 203;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas tenido éxito en tu caza, $n. No duraremos mucho sin tu ayuda.', 0),
(@ID, 'esMX', 'Espero que hayas tenido éxito en tu caza, $n. No duraremos mucho sin tu ayuda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. La derrota de esos combatientes de la jungla aliviará algo la presión sobre nuestro campamento.$B$BPero ahora que has catado el tipo de fuerza al que nos enfrentamos, ¿aún deseas echar el resto con nosotros?', 0),
(@ID, 'esMX', 'Bien hecho. La derrota de esos combatientes de la jungla aliviará algo la presión sobre nuestro campamento.$B$BPero ahora que has catado el tipo de fuerza al que nos enfrentamos, ¿aún deseas echar el resto con nosotros?', 0);
-- 574 Fuerzas especiales
-- https://es.classic.wowhead.com/quest=574
SET @ID := 574;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La sargento Yohwa me dice que eres hábil y valiente, $c. ¿Tienes algo que informar?', 0),
(@ID, 'esMX', 'La sargento Yohwa me dice que eres hábil y valiente, $c. ¿Tienes algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. La sargento Yohwa confiaba en tus habilidades y yo confío en ella. La derrota de las tropas de Kurzen es casi demasiado buena para ser verdad. Temía que los rebeldes estábamos solos y que nadie se podría enfrentar al gran coronel.$B$BQuizás todavía nos quede alguna esperanza de sobrevivir.', 0),
(@ID, 'esMX', '$n. La sargento Yohwa confiaba en tus habilidades y yo confío en ella. La derrota de las tropas de Kurzen es casi demasiado buena para ser verdad. Temía que los rebeldes estábamos solos y que nadie se podría enfrentar al gran coronel.$B$BQuizás todavía nos quede alguna esperanza de sobrevivir.', 0);
-- 202 Coronel Kurzen
-- https://es.classic.wowhead.com/quest=202
SET @ID := 202;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me atrevo a creer que Kurzen y sus defensores están muertos, $n?', 0),
(@ID, 'esMX', '¿Me atrevo a creer que Kurzen y sus defensores están muertos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me atrevía a creer los informes pero nos traes la prueba… Has derrotado a Kurzen y a sus líderes. ¡Nos has salvado!$B$BEstos bosques están llenos de amenazas de todo tipo, pero ninguna tenía la perversa inteligencia de Kurzen. Todos estaremos más tranquilos ahora que ya no está.', 0),
(@ID, 'esMX', 'No me atrevía a creer los informes pero nos traes la prueba… Has derrotado a Kurzen y a sus líderes. ¡Nos has salvado!$B$BEstos bosques están llenos de amenazas de todo tipo, pero ninguna tenía la perversa inteligencia de Kurzen. Todos estaremos más tranquilos ahora que ya no está.', 0);
