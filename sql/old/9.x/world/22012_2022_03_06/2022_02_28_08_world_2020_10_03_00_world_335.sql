-- 207 El misterio de Kurzen
-- https://es.classic.wowhead.com/quest=207
SET @ID := 207;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Tienes las leyendas trols? ¡Tengo que saber sus secretos!', 0),
(@ID, 'esMX', '¡$n! ¿Tienes las leyendas trols? ¡Tengo que saber sus secretos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Estudiaré estas leyendas para ver si hay algún tipo de unión entre los trols y el mal que ha poseído al coronel Kurzen.', 0),
(@ID, 'esMX', 'Gracias, $n. Estudiaré estas leyendas para ver si hay algún tipo de unión entre los trols y el mal que ha poseído al coronel Kurzen.', 0);
-- 602 Análisis mágico
-- https://es.classic.wowhead.com/quest=602
SET @ID := 602;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no te importa, tengo mucho que hacer ahora mismo.', 0),
(@ID, 'esMX', 'Si no te importa, tengo mucho que hacer ahora mismo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La Piedra de las Mareas? Muy interesante. Podría sorprenderte saber que yo escribí un libro... hace muchos años ya... sobre las leyendas del Imperio Gurubashi. Sé algo sobre la Piedra.$B$BAl menos uno de estos brazales parece tener un residuo mágico que creo poder analizar.$B$BVeamos...', 0),
(@ID, 'esMX', '¿La Piedra de las Mareas? Muy interesante. Podría sorprenderte saber que yo escribí un libro... hace muchos años ya... sobre las leyendas del Imperio Gurubashi. Sé algo sobre la Piedra.$B$BAl menos uno de estos brazales parece tener un residuo mágico que creo poder analizar.$B$BVeamos...', 0);
-- 628 Borceguí
-- https://es.classic.wowhead.com/quest=628
SET @ID := 628;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He oído por ahí que los crocoliscos aguasalada se están secando... malas noticias para el negocio, ¿eh?$B$BEn fin, espero que tengas esa piel de crocolisco aguasalada anciano para mí.', 0),
(@ID, 'esMX', 'He oído por ahí que los crocoliscos aguasalada se están secando... malas noticias para el negocio, ¿eh?$B$BEn fin, espero que tengas esa piel de crocolisco aguasalada anciano para mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! Gracias a tu ayuda, tendré este pedido terminado y se lo enviaré al director Riddlevox en el próximo barco que salga para Villabajo. ¡Incluso antes de la hora prevista!$B$BHe hecho algunas de más, así que, por tus esfuerzos, puedes quedarte con un par. Regalo de Drizzlik.$B$BNo hay nada que supere el estilo borceguí de Drizzlik !', 0),
(@ID, 'esMX', '¡Genial! Gracias a tu ayuda, tendré este pedido terminado y se lo enviaré al director Riddlevox en el próximo barco que salga para Villabajo. ¡Incluso antes de la hora prevista!$B$BHe hecho algunas de más, así que, por tus esfuerzos, puedes quedarte con un par. Regalo de Drizzlik.$B$BNo hay nada que supere el estilo borceguí de Drizzlik !', 0);
-- 613 Abrir la pata de Maury
-- https://es.classic.wowhead.com/quest=613
SET @ID := 613;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buenas, $n! ¿Has encontrado la llave de Maury?', 0),
(@ID, 'esMX', '¡Buenas, $n! ¿Has encontrado la llave de Maury?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La has encontrado! Un millón de gracias, $n. ¡Has sido de gran ayuda!$B$BAquí tienes, ¡te lo has ganado!', 0),
(@ID, 'esMX', '¡La has encontrado! Un millón de gracias, $n. ¡Has sido de gran ayuda!$B$BAquí tienes, ¡te lo has ganado!', 0);
-- 205 Brujería trol
-- https://es.classic.wowhead.com/quest=205
SET @ID := 205;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esos fetiches, $n? Quizás guarden el secreto de la degradación de Kurzen... ¡Debo saberlo!', 0),
(@ID, 'esMX', '¿Tienes esos fetiches, $n? Quizás guarden el secreto de la degradación de Kurzen... ¡Debo saberlo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias. Estudiaré estos fetiches y veré si puedo descubrir el secreto de la corrupción de Kurzen.', 0),
(@ID, 'esMX', 'Gracias. Estudiaré estos fetiches y veré si puedo descubrir el secreto de la corrupción de Kurzen.', 0);
-- 206 Mai'Zoth
-- https://es.classic.wowhead.com/quest=206
SET @ID := 206;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy mi bendición. El mal aquí contenido es el único rival posible para la fuerza de Mai\'Zoth.', 0),
(@ID, 'esMX', 'Te doy mi bendición. El mal aquí contenido es el único rival posible para la fuerza de Mai\'Zoth.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ajá! ¡Lo has conseguido! Eres una gran fuerza para el bien, $n, ¡que las fuerzas nunca te fallen!$B$BEstudiaré este Ojo de la Mente y veré si puede usarse para buenos fines. Si no… habrá que destruirlo.', 0),
(@ID, 'esMX', '¡Ajá! ¡Lo has conseguido! Eres una gran fuerza para el bien, $n, ¡que las fuerzas nunca te fallen!$B$BEstudiaré este Ojo de la Mente y veré si puede usarse para buenos fines. Si no… habrá que destruirlo.', 0);
-- 1117 Rumores para Kravel
-- https://es.classic.wowhead.com/quest=1117
SET @ID := 1117;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has averiguado algo de Nazz Vaporio? ¿Algún secreto que no quiere que se sepa, quizás?', 0),
(@ID, 'esMX', '¿Has averiguado algo de Nazz Vaporio? ¿Algún secreto que no quiere que se sepa, quizás?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, vaya! Esto es interesante... muy interesante. Eh, quizás la próxima vez que vea al piloto goblin debería hacerle una reverencia.$B$BLo que has averiguado vale oro, $n. Estoy seguro de que Nazz pagará una pequeña fortuna para mantener su secreto... en secreto.', 0),
(@ID, 'esMX', '¡Vaya, vaya! Esto es interesante... muy interesante. Eh, quizás la próxima vez que vea al piloto goblin debería hacerle una reverencia.$B$BLo que has averiguado vale oro, $n. Estoy seguro de que Nazz pagará una pequeña fortuna para mantener su secreto... en secreto.', 0);
-- 2873 El envío de Stoley
-- https://es.classic.wowhead.com/quest=2873
SET @ID := 2873;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado mi cargamento de ron, $n?', 0),
(@ID, 'esMX', '¿Has encontrado mi cargamento de ron, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, gracias por el cargamento! Ahora MacKinley y yo podremos acabar con nuestra apuesta.', 0),
(@ID, 'esMX', '¡Genial, gracias por el cargamento! Ahora MacKinley y yo podremos acabar con nuestra apuesta.', 0);
-- 4324 Yuka Llavenrosca
-- https://es.classic.wowhead.com/quest=4324
SET @ID := 4324;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así es, busco a mi hermano. Debemos encontrarlo y recuperarlo, bendito sea su corazón.$B$BPero si no podemos traerlo entero... su cabeza bastará.', 0),
(@ID, 'esMX', 'Así es, busco a mi hermano. Debemos encontrarlo y recuperarlo, bendito sea su corazón.$B$BPero si no podemos traerlo entero... su cabeza bastará.', 0);
-- 8366 Mamporros en los Mares del Sur
-- https://es.classic.wowhead.com/quest=8366
SET @ID := 8366;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto? Espero que les hayas enseñado a esos matones de los mares del Sur una lección que no olvidarán pronto.', 0),
(@ID, 'esMX', '¿Regresaste tan pronto? Espero que les hayas enseñado a esos matones de los mares del Sur una lección que no olvidarán pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¡Tú sí que vales!$B$BEstoy seguro de que el cártel dejará de presionarme ahora que has acabado con esa escoria del Mar del Sur. Veamos, ¿qué puedo darte como recompensa? ¿Qué te parece si me das una pieza y te dejo elegir uno de estos por tus esfuerzos?', 0),
(@ID, 'esMX', '¡$n! ¡Tú sí que vales!$B$BEstoy seguro de que el cártel dejará de presionarme ahora que has acabado con esa escoria del Mar del Sur. Veamos, ¿qué puedo darte como recompensa? ¿Qué te parece si me das una pieza y te dejo elegir uno de estos por tus esfuerzos?', 0);
-- 8365 ¡Sombreros de pirata a babor!
-- https://es.classic.wowhead.com/quest=8365
SET @ID := 8365;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los 20 sombreros? No te creo, déjamelos ver. ¡Sería mejor que estuvieran en perfecto estado!', 0),
(@ID, 'esMX', '¿Tienes los 20 sombreros? No te creo, déjamelos ver. ¡Sería mejor que estuvieran en perfecto estado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, eres un cielo, aunque hayas tardado más de lo que esperaba. Cuando estos sombreros estén limpios y les haya dado mi toque personal, sacaré un buen pellizco por ellos. Y dado que siempre suelo recompensar un trabajo bien hecho, aquí tienes algo para ti. Te recomiendo que reserves algo para darte un buen baño, encanto.', 0),
(@ID, 'esMX', 'Oh, eres un cielo, aunque hayas tardado más de lo que esperaba. Cuando estos sombreros estén limpios y les haya dado mi toque personal, sacaré un buen pellizco por ellos. Y dado que siempre suelo recompensar un trabajo bien hecho, aquí tienes algo para ti. Te recomiendo que reserves algo para darte un buen baño, encanto.', 0);
-- 3520 Los espíritus de los estridadores
-- https://es.classic.wowhead.com/quest=3520
SET @ID := 3520;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has capturado la esencia de los espíritus de los estridadores, $n?', 0),
(@ID, 'esMX', '¿Has capturado la esencia de los espíritus de los estridadores, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Quizás ha llegado el momento de que cuente más cosas...$B$BUna antigua profecía de los trols cuenta que el dios muerto Hakkar, el Cazador de Almas, un día regresará a esta tierra. Algunos dicen que el regreso de Hakkar traerá dicha y gloria a los trols, mientras que otros creen que su resurrección significará el principio del fin.$B$BYo no creo en esta leyenda pero sé que la esencia de Hakkar ostenta gran poder, por lo que no debe caer en manos de aquellos que no harán buen uso de ella...', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Quizás ha llegado el momento de que cuente más cosas...$B$BUna antigua profecía de los trols cuenta que el dios muerto Hakkar, el Cazador de Almas, un día regresará a esta tierra. Algunos dicen que el regreso de Hakkar traerá dicha y gloria a los trols, mientras que otros creen que su resurrección significará el principio del fin.$B$BYo no creo en esta leyenda pero sé que la esencia de Hakkar ostenta gran poder, por lo que no debe caer en manos de aquellos que no harán buen uso de ella...', 0);
-- 2874 Un envío para MacKinley
-- https://es.classic.wowhead.com/quest=2874
SET @ID := 2874;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Aflojó Stoley la botella que me prometió?', 0),
(@ID, 'esMX', '¿Aflojó Stoley la botella que me prometió?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, a ver, déjame probar...$B$B¡No puedo creerlo! ¡Esto es... la bomba! ¡Genial!$B$BSupongo que Stoley puede quedarse el dinero que me debe. Tenía razón en cuanto al ron de la sentina Bonvapor... ¡Cómo rasca!', 0),
(@ID, 'esMX', 'Mm, a ver, déjame probar...$B$B¡No puedo creerlo! ¡Esto es... la bomba! ¡Genial!$B$BSupongo que Stoley puede quedarse el dinero que me debe. Tenía razón en cuanto al ron de la sentina Bonvapor... ¡Cómo rasca!', 0);
-- 110 Análisis de trozos de insecto
-- https://es.classic.wowhead.com/quest=110
SET @ID := 110;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, tengo los resultados aquí mismo. Son... inquietantes, por no decir otra cosa.$B$BCreemos que es cierta nuestra sospecha inicial de que los bichos están bajo el control de una fuerza externa. De ser así, nos enfrentamos a un poder desconocido y, lo que es más, maligno. ¡A estos bichos los han convertido en devastadores! Nunca había visto nada parecido.', 0),
(@ID, 'esMX', 'Sí, tengo los resultados aquí mismo. Son... inquietantes, por no decir otra cosa.$B$BCreemos que es cierta nuestra sospecha inicial de que los bichos están bajo el control de una fuerza externa. De ser así, nos enfrentamos a un poder desconocido y, lo que es más, maligno. ¡A estos bichos los han convertido en devastadores! Nunca había visto nada parecido.', 0);
-- 113 Análisis de trozos de insecto
-- https://es.classic.wowhead.com/quest=113
SET @ID := 113;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y bien, perito adjunto $n, ¿Morterozugg tiene el informe listo?', 0),
(@ID, 'esMX', 'Y bien, perito adjunto $n, ¿Morterozugg tiene el informe listo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por el informe, perito adjunto $n. Aquí tienes lo que te corresponde por el gran servicio prestado a la compañía de aguas de Gadgetzan.$B$BAunque no suelo entregar nuestra valiosa información de manera desinteresada a aquellos que con toda seguridad pagarían bien por ella, hace años que conozco a Morterozugg. Si él recomienda que todos han de conocer esta información, que así sea. Dame un momento y te haré una copia.', 0),
(@ID, 'esMX', 'Gracias por el informe, perito adjunto $n. Aquí tienes lo que te corresponde por el gran servicio prestado a la compañía de aguas de Gadgetzan.$B$BAunque no suelo entregar nuestra valiosa información de manera desinteresada a aquellos que con toda seguridad pagarían bien por ella, hace años que conozco a Morterozugg. Si él recomienda que todos han de conocer esta información, que así sea. Dame un momento y te haré una copia.', 0);
-- 162 La sublevación de los silítidos
-- https://es.classic.wowhead.com/quest=162
SET @ID := 162;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la paz y la tranquilidad sean contigo, forastero. ¿En qué necesitas hoy mi consejo?', 0),
(@ID, 'esMX', 'Que la paz y la tranquilidad sean contigo, forastero. ¿En qué necesitas hoy mi consejo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este informe... nosotros, los elfos de la noche, conocemos muy bien el terror del que en él se habla. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0),
(@ID, 'esMX', 'Este informe... nosotros, los elfos de la noche, conocemos muy bien el terror del que en él se habla. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0);
-- 1118 De vuelta a Bahía del Botín
-- https://es.classic.wowhead.com/quest=1118
SET @ID := 1118;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, hola. ¿Qué trae a $gun:una; noble $r como tú a Bahía del Botín?', 0),
(@ID, 'esMX', 'Hola, hola. ¿Qué trae a $gun:una; noble $r como tú a Bahía del Botín?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entiendo. Kravel ha ideado un nuevo plan. Este Kravel es un tanto siniestro, y eso me gusta.$B$BAsí que necesitas algo para confundir los sentidos, ¿no es cierto? Algo fuerte...$B$BMe pregunto si la mezcla que Zanzil les da a los zombis serviría...', 0),
(@ID, 'esMX', 'Entiendo. Kravel ha ideado un nuevo plan. Este Kravel es un tanto siniestro, y eso me gusta.$B$BAsí que necesitas algo para confundir los sentidos, ¿no es cierto? Algo fuerte...$B$BMe pregunto si la mezcla que Zanzil les da a los zombis serviría...', 0);
-- 3527 La profecía de Mosh'aru
-- https://es.classic.wowhead.com/quest=3527
SET @ID := 3527;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las tablillas de la profecía de Mosh\'aru, $n?$B$BCuando tenga las tablillas... ¡podré estudiarlas y descubrir cómo encerrar la esencia de Hakkar!', 0),
(@ID, 'esMX', '¿Tienes las tablillas de la profecía de Mosh\'aru, $n?$B$BCuando tenga las tablillas... ¡podré estudiarlas y descubrir cómo encerrar la esencia de Hakkar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué bien! Puedo fusionar estas dos tablillas y después estudiar los secretos que encierran.$B$BMi deuda contigo va en aumento, $n, y continuará haciéndolo.', 0),
(@ID, 'esMX', '¡Ah, qué bien! Puedo fusionar estas dos tablillas y después estudiar los secretos que encierran.$B$BMi deuda contigo va en aumento, $n, y continuará haciéndolo.', 0);
-- 4787 El huevo antiguo
-- https://es.classic.wowhead.com/quest=4787
SET @ID := 4787;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el huevo antiguo? Siento la agitación de poderosas fuerzas y temo que el tiempo se esté agotando.', 0),
(@ID, 'esMX', '¿Tienes el huevo antiguo? Siento la agitación de poderosas fuerzas y temo que el tiempo se esté agotando.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, tienes el huevo! Me inclino ante ti, $n. Tu fuerza y valentía serán recordados durante mucho tiempo.', 0),
(@ID, 'esMX', '¡Ah, tienes el huevo! Me inclino ante ti, $n. Tu fuerza y valentía serán recordados durante mucho tiempo.', 0);
-- 5535 Agitación espiritual
-- https://es.classic.wowhead.com/quest=5535
SET @ID := 5535;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda de los espíritus Altonato, $c?$B$BMuchos eventos han causado un gran sufrimiento a todas las razas de Azeroth, pero por alguna razón, estos espíritus parecen ser una plaga para todas las personas. Tal vez sea el deseo continuo de cualquier magia arcana; ese deseo es un presagio de la Legión Ardiente, y sabemos a qué puede conducir.', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda de los espíritus Altonato, $c?$B$BMuchos eventos han causado un gran sufrimiento a todas las razas de Azeroth, pero por alguna razón, estos espíritus parecen ser una plaga para todas las personas. Tal vez sea el deseo continuo de cualquier magia arcana; ese deseo es un presagio de la Legión Ardiente, y sabemos a qué puede conducir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $c. Gracias por tu ayuda. Los espíritus descansan y las amenazas que su deseo de lo arcano trajeron han disminuido.$B$BEstoy seguro de que los dos lados del conflicto que causa estragos en Azeroth se darán cuenta de que estás por encima de estas cosas.', 0),
(@ID, 'esMX', 'Muy bien, $c. Gracias por tu ayuda. Los espíritus descansan y las amenazas que su deseo de lo arcano trajeron han disminuido.$B$BEstoy seguro de que los dos lados del conflicto que causa estragos en Azeroth se darán cuenta de que estás por encima de estas cosas.', 0);
