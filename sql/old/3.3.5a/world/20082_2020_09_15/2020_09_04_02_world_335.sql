-- 7907 La baraja de Bestias de la Luna Negra
-- https://es.classic.wowhead.com/quest=7907
SET @ID := 7907;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh querido.', 0),
(@ID, 'esMX', 'Oh querido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, esto explica mucho. Si alguna vez encuentra una forma de entrar en Ahn\'Qiraj, esté atento al viejo Brann. Me temo que será inútil sin su mono', 0),
(@ID, 'esMX', 'Bueno, esto explica mucho. Si alguna vez encuentra una forma de entrar en Ahn\'Qiraj, esté atento al viejo Brann. Me temo que será inútil sin su mono', 0);
-- 12133 Aplasta la calabaza
-- https://es.wowhead.com/quest=12133
SET @ID := 12133;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n?', 0),
(@ID, 'esMX', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste esto en el interior de la calabaza iluminada del Jinete decapitado? Es un antiguo símbolo de la Luz. Debía de pertenecer al Jinete antes de que fuera maldecido y se convirtiese en el monstruo que es hoy. Gracias, $n. Este símbolo merece estar entre paladines. Me encargaré de que lo reciban.$B$B¡Ah, casi se me olvida! Tienes una admiradora secreta...$B$BUna de las niñas quería regalarte esto, pero le daba mucha vergüenza dártelo personalmente.', 0),
(@ID, 'esMX', '¿Encontraste esto en el interior de la calabaza iluminada del Jinete decapitado? Es un antiguo símbolo de la Luz. Debía de pertenecer al Jinete antes de que fuera maldecido y se convirtiese en el monstruo que es hoy. Gracias, $n. Este símbolo merece estar entre paladines. Me encargaré de que lo reciban.$B$B¡Ah, casi se me olvida! Tienes una admiradora secreta...$B$BUna de las niñas quería regalarte esto, pero le daba mucha vergüenza dártelo personalmente.', 0);
-- 1598 El libro robado
-- https://es.classic.wowhead.com/quest=1598
SET @ID := 1598;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Era demasiado llamativo para mí robar el libro yo mismo. Qué suerte que uno de esos tontos hizo el trabajo sucio por mí.', 0),
(@ID, 'esMX', 'Era demasiado llamativo para mí robar el libro yo mismo. Qué suerte que uno de esos tontos hizo el trabajo sucio por mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente ... Nunca pude acceder a este texto, estaba guardado en un ala protegida de la biblioteca y habría parecido sospechoso si me ven merodeando.$B$BBueno, hiciste un buen trabajo al conseguir esto, y estoy convencido de que probablemente puedas manejar a tu propio diablillo, así que no hay razón para que no te muestre cómo convocar a uno.', 0),
(@ID, 'esMX', 'Excelente ... Nunca pude acceder a este texto, estaba guardado en un ala protegida de la biblioteca y habría parecido sospechoso si me ven merodeando.$B$BBueno, hiciste un buen trabajo al conseguir esto, y estoy convencido de que probablemente puedas manejar a tu propio diablillo, así que no hay razón para que no te muestre cómo convocar a uno.', 0);
-- 7929 La baraja de Elementales de la Luna Negra
-- https://es.wowhead.com/quest=7929
-- https://wow-es.gamepedia.com/Misión:La baraja de Elementales de la Luna Negra
SET @ID := 7929;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veo que has logrado completar un mazo de elementales! ¡Felicidades!', 0),
(@ID, 'esMX', '¡Veo que has logrado completar un mazo de elementales! ¡Felicidades!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que has armado un mazo de Elementales. Su gesto de devolvérnoslo creará un vínculo entre usted y la Luna Negra que no se olvidará pronto. Permíteme presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Así que has armado un mazo de Elementales. Su gesto de devolvérnoslo creará un vínculo entre usted y la Luna Negra que no se olvidará pronto. Permíteme presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0);
-- 13484 Colectores primaverales
-- https://es.wowhead.com/quest=13484
SET @ID := 13484;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí! ¡Sí, creo que tengo la tarea perfecta para ti!', 0),
(@ID, 'esMX', '¡Sí! ¡Sí, creo que tengo la tarea perfecta para ti!', 0);
-- 13480 La gran búsqueda de huevos
-- https://es.wowhead.com/quest=13480
SET @ID := 13480;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los trozos?', 0),
(@ID, 'esMX', '¿Tienes los trozos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, fantástico, gracias! Puede que me haga falta más de una muestra para conseguir resultados verdaderamente concluyentes, pero lo has hecho muy bien por hoy.', 0),
(@ID, 'esMX', '¡Fantástico, fantástico, gracias! Puede que me haga falta más de una muestra para conseguir resultados verdaderamente concluyentes, pero lo has hecho muy bien por hoy.', 0);
-- 1685 La invocación de Gakin
-- https://es.wowhead.com/quest=1685
SET @ID := 1685;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que aparecieras. Aunque, quizás debería haber enviado a alguien más capaz que Remen para encontrarte.$B$BNo importa.$B$BHas pasado demasiado tiempo sin entrenar, y un brujo sin entrenamiento no mantiene la cabeza sobre los hombros por mucho tiempo.', 0),
(@ID, 'esMX', 'Ya era hora de que aparecieras. Aunque, quizás debería haber enviado a alguien más capaz que Remen para encontrarte.$B$BNo importa.$B$BHas pasado demasiado tiempo sin entrenar, y un brujo sin entrenamiento no mantiene la cabeza sobre los hombros por mucho tiempo.', 0);
-- 1688 Surena Caledon
-- https://es.classic.wowhead.com/quest=1688
SET @ID := 1688;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Incluso los más viejos y sabios pueden caer rendidos ante la gloria de la belleza y la juventud, $n. Un consejo que te vendrá bien recordar toda tu vida.', 0),
(@ID, 'esMX', 'Incluso los más viejos y sabios pueden caer rendidos ante la gloria de la belleza y la juventud, $n. Un consejo que te vendrá bien recordar toda tu vida.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Surena tenía mucho talento, pero no tanto como para conseguir dominar la magia de los brujos sin ayuda. Es una pena ver el desperdicio de talento pero, algunas veces, es necesario.$B$BEspero tener resultados diferentes contigo.', 0),
(@ID, 'esMX', 'Surena tenía mucho talento, pero no tanto como para conseguir dominar la magia de los brujos sin ayuda. Es una pena ver el desperdicio de talento pero, algunas veces, es necesario.$B$BEspero tener resultados diferentes contigo.', 0);
-- 1689 El vínculo
-- https://es.classic.wowhead.com/quest=1689
SET @ID := 1689;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo enseñarte a controlar a un abisario hasta que no hayas vencido a uno.', 0),
(@ID, 'esMX', 'No puedo enseñarte a controlar a un abisario hasta que no hayas vencido a uno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho mejor de lo que esperaba, $n, pero has estado a la altura de mis esperanzas. Ahora puedes aprender a dominar a tu abisario sometido, un aliado que será muy valioso en los desafíos que, sin lugar a duda, se te presentarán.$B$BNo tengo nada más que enseñarte en este momento, pero todavía no he acabado contigo, $n.', 0),
(@ID, 'esMX', 'Lo has hecho mejor de lo que esperaba, $n, pero has estado a la altura de mis esperanzas. Ahora puedes aprender a dominar a tu abisario sometido, un aliado que será muy valioso en los desafíos que, sin lugar a duda, se te presentarán.$B$BNo tengo nada más que enseñarte en este momento, pero todavía no he acabado contigo, $n.', 0);
-- 1638 Instrucción de guerrero
-- https://es.classic.wowhead.com/quest=1638
SET @ID := 1638;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, jo! Tómate un trago conmigo, $gmuchacho:muchacha;. A primera vista pareces muy $gduro:dura;, pero veamos si puedes arreglártelas con algunas jarras de las especialidades más potentes de El Cerdo Borracho$B$BO bien... ¿has venido para recibir instrucción?', 0),
(@ID, 'esMX', '¡Oh, jo! Tómate un trago conmigo, $gmuchacho:muchacha;. A primera vista pareces muy $gduro:dura;, pero veamos si puedes arreglártelas con algunas jarras de las especialidades más potentes de El Cerdo Borracho$B$BO bien... ¿has venido para recibir instrucción?', 0);
-- 1639 Bartleby, el borracho
-- https://es.classic.wowhead.com/quest=1639
SET @ID := 1639;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola $gmuchachito:muchachita;! ¿Qué hace $gun:una; repipi como tú en El Cerdo Borracho? Ten cuidado, se te podría romper una uña...', 0),
(@ID, 'esMX', '¡Hola $gmuchachito:muchachita;! ¿Qué hace $gun:una; repipi como tú en El Cerdo Borracho? Ten cuidado, se te podría romper una uña...', 0);
-- 1640 Vence a Bartleby
-- https://es.classic.wowhead.com/quest=1640
SET @ID := 1640;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sólo me quitarás la jarra de mis manos frías y muertas...', 0),
(@ID, 'esMX', 'Sólo me quitarás la jarra de mis manos frías y muertas...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eres mucho más duro de lo que pareces!', 0),
(@ID, 'esMX', '¡Eres mucho más duro de lo que pareces!', 0);
-- 1665 La jarra de Bartleby
-- https://es.classic.wowhead.com/quest=1665
SET @ID := 1665;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vi tu combate con Bartleby. ¡Bien hecho! ¿Tienes su jarra?', 0),
(@ID, 'esMX', 'Vi tu combate con Bartleby. ¡Bien hecho! ¿Tienes su jarra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La tienes! Seguro que no quería separarse de ella pero has sido muy $gpersuasivo:persuasiva;. Bien hecho.$B$BPasemos ahora a tu lección...', 0),
(@ID, 'esMX', '¡La tienes! Seguro que no quería separarse de ella pero has sido muy $gpersuasivo:persuasiva;. Bien hecho.$B$BPasemos ahora a tu lección...', 0);
-- 3100 Una carta simple
-- https://es.classic.wowhead.com/quest=3100
SET @ID := 3100;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, recibiste mi carta, $n ... bien.$B$BRecientemente ha habido una afluencia de guerreros en Elwynn, lo que es bueno para Ventormenta, pero malo para los kobolds y Defias de la zona.', 0),
(@ID, 'esMX', 'Ah, recibiste mi carta, $n ... bien.$B$BRecientemente ha habido una afluencia de guerreros en Elwynn, lo que es bueno para Ventormenta, pero malo para los kobolds y Defias de la zona.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ponte en pie, estudia el terreno y vuelve conmigo cuando necesites formación. Estaré aquí de día o de noche.$B$BLos Caballeros de la Mano de Plata han hecho bien en hacer que este lugar sea bastante seguro, pero cuando conozcas a los otros ciudadanos, creo que encontrarás que todos tienen problemas con los que les vendría bien un poco de ayuda: ayuda que un $c puede brindarles. Buena suerte.', 0),
(@ID, 'esMX', 'Ponte en pie, estudia el terreno y vuelve conmigo cuando necesites formación. Estaré aquí de día o de noche.$B$BLos Caballeros de la Mano de Plata han hecho bien en hacer que este lugar sea bastante seguro, pero cuando conozcas a los otros ciudadanos, creo que encontrarás que todos tienen problemas con los que les vendría bien un poco de ayuda: ayuda que un $c puede brindarles. Buena suerte.', 0);
-- 3102 Una carta cifrada
-- https://es.classic.wowhead.com/quest=3102
SET @ID := 3102;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo hiciste a la primera, y no parece que mucha gente te haya visto. Suficientemente bueno para mi. No me gusta que llamen mucho la atención aquí atrás ... agradable y tranquilo. Estoy seguro de que lo entenderás.$B$B¿Tienes algún problema todavía? Me alegra saber que no. Eso cambiará muy pronto.', 0),
(@ID, 'esMX', 'Lo hiciste a la primera, y no parece que mucha gente te haya visto. Suficientemente bueno para mi. No me gusta que llamen mucho la atención aquí atrás ... agradable y tranquilo. Estoy seguro de que lo entenderás.$B$B¿Tienes algún problema todavía? Me alegra saber que no. Eso cambiará muy pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Descubrirás que hay una serie de personajes que codiciarán nuestras habilidades, $n. Aventureros, IV:7... diablos, incluso a la Hermandad Defias no le importaría tener un espía o dos dentro de Ventormenta. Pero recuerda esto, eres tu propio jefe. ¡No dejes que nadie te intimide para que hagas algo que no quieres hacer! Además, tenemos todas las cartas ... al menos, antes de que termine el juego. ¡Tu ya sabes!$B$BDe todos modos, solo quería presentarme y hacerlte saber que estoy aquí si necesitas capacitación. Ven en cualquier momento.', 0),
(@ID, 'esMX', 'Descubrirás que hay una serie de personajes que codiciarán nuestras habilidades, $n. Aventureros, IV:7... diablos, incluso a la Hermandad Defias no le importaría tener un espía o dos dentro de Ventormenta. Pero recuerda esto, eres tu propio jefe. ¡No dejes que nadie te intimide para que hagas algo que no quieres hacer! Además, tenemos todas las cartas ... al menos, antes de que termine el juego. ¡Tu ya sabes!$B$BDe todos modos, solo quería presentarme y hacerlte saber que estoy aquí si necesitas capacitación. Ven en cualquier momento.', 0);
-- 3103 Una carta sacralizada
-- https://es.classic.wowhead.com/quest=3103
SET @ID := 3103;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al fin llegas; sabía que vendrías. Que la Luz Sagrada te ilumine. Estos son tiempos difíciles, la Legión Ardiente sigue presente en Azeroth. Kalimdor intenta defenderse. Ayuda en todo lo que puedas.', 0),
(@ID, 'esMX', 'Al fin llegas; sabía que vendrías. Que la Luz Sagrada te ilumine. Estos son tiempos difíciles, la Legión Ardiente sigue presente en Azeroth. Kalimdor intenta defenderse. Ayuda en todo lo que puedas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que ganas experiencia, ven a verme y te enseñaré lo posible. Hasta entonces, que la sabiduría guíe tus pasos. Recuerda que de ti depende mejorar el mundo.', 0),
(@ID, 'esMX', 'A medida que ganas experiencia, ven a verme y te enseñaré lo posible. Hasta entonces, que la sabiduría guíe tus pasos. Recuerda que de ti depende mejorar el mundo.', 0);
-- 3104 Una carta glífica
-- https://es.classic.wowhead.com/quest=3104
SET @ID := 3104;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n, me llamo Khelden. ¿Querías algo?', 0),
(@ID, 'esMX', 'Hola, $n, me llamo Khelden. ¿Querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que mi carta no te apartaría de tu camino. Bien, ¿vienes a aceptar tu destino y enfrentarte a quienes se oponen a tu búsqueda de sabiduría y poder?$B$BTe temerán tanto como te respetarán, $n. Y yo siempre estaré aquí para instruirte; solo tienes que venir a buscarme.', 0),
(@ID, 'esMX', 'Sabía que mi carta no te apartaría de tu camino. Bien, ¿vienes a aceptar tu destino y enfrentarte a quienes se oponen a tu búsqueda de sabiduría y poder?$B$BTe temerán tanto como te respetarán, $n. Y yo siempre estaré aquí para instruirte; solo tienes que venir a buscarme.', 0);
-- 3105 Una carta manchada
-- https://es.classic.wowhead.com/quest=3105
SET @ID := 3105;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, entonces has llegado, y no demasiado pronto, $n. Algunos de los guardias estaban aquí hace un momento y me miraban con curiosidad... mundanos patéticos.', 0),
(@ID, 'esMX', 'Ah, entonces has llegado, y no demasiado pronto, $n. Algunos de los guardias estaban aquí hace un momento y me miraban con curiosidad... mundanos patéticos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que crezcas en poder, se sentirás $gtentado:tentada;; siempre debes recordar controlarte. No mentiré: la corrupción puede llegar a cualquier practicante de lo arcano; especialmente uno que trata con criaturas de la oscuridad. Ten paciencia y prudencia ... pero no dejes que eso reprima tu ambición.$B$BA medida que te vuelvas más $gpoderoso:poderosa;, vuelve a mí y te enseñaré más sobre nuestros caminos.', 0),
(@ID, 'esMX', 'A medida que crezcas en poder, se sentirás $gtentado:tentada;; siempre debes recordar controlarte. No mentiré: la corrupción puede llegar a cualquier practicante de lo arcano; especialmente uno que trata con criaturas de la oscuridad. Ten paciencia y prudencia ... pero no dejes que eso reprima tu ambición.$B$BA medida que te vuelvas más $gpoderoso:poderosa;, vuelve a mí y te enseñaré más sobre nuestros caminos.', 0);
-- 3861 ¡CLOQUEA!
-- https://es.classic.wowhead.com/quest=3861
SET @ID := 3861;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El pollo te mira con ojos fríos y cara de hambre.$B$B"¡CO_COOOC!$B$BCoo-co-cooo."', 0),
(@ID, 'esMX', 'El pollo te mira con ojos fríos y cara de hambre.$B$B"¡CO_COOOC!$B$BCoo-co-cooo."', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"¡COO-COOC!"$B$BEl pollo se pone a engullir la comida.$B$BDe pronto se para, como sorprendido, y se agita incómodo. Vaya, este pollo no el un pollo, es una gallina... Será mejor que mires debajo, a ver.', 0),
(@ID, 'esMX', '"¡COO-COOC!"$B$BEl pollo se pone a engullir la comida.$B$BDe pronto se para, como sorprendido, y se agita incómodo. Vaya, este pollo no el un pollo, es una gallina... Será mejor que mires debajo, a ver.', 0);
-- 5805 ¡Te damos la bienvenida!
-- https://es.classic.wowhead.com/quest=5805
SET @ID := 5805;
UPDATE `quest_template_locale` SET `Details` = '¡Bienvenido a World of Warcraft!$B$BComo agradecimiento especial por haber comprado la Edición de coleccionista de World of Warcraft, entrega este vale a Merissa Fontana en Villadorada. Conseguirás un regalo: Un pequeño compañero que te acompañará en tu búsqueda de aventuras y gloria.$B$B¡Gracias de nuevo, y que disfrutes con World of Warcraft!', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0),
(@ID, 'esMX', '¡Saludos! ¡Es un placer conocerte!$B$BVeo que tienes un vale especial. Dámelo y te ofreceré algo a cambio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De hecho, eres $gun:una; $ghéroe:heroina; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0),
(@ID, 'esMX', 'De hecho, eres $gun:una; $ghéroe:heroina; especial, $n. ¡Te damos la bienvenida al mundo de Azeroth y te ofrecemos uno de estos regalos únicos!', 0);
-- 5623 Al servicio de la Luz
-- https://es.classic.wowhead.com/quest=5623
SET @ID := 5623;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que hayas llegado, $n. Tenemos mucho que hablar. Debemos hablar sobre tu futuro y tu camino en la Luz.', 0),
(@ID, 'esMX', 'Me alegra que hayas llegado, $n. Tenemos mucho que hablar. Debemos hablar sobre tu futuro y tu camino en la Luz.', 0);
