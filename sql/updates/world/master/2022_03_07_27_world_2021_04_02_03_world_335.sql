-- 8554 Enfréntate a Negolash
-- https://es.classic.wowhead.com/quest=8554
SET @ID := 8554;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido mi alfanje, $n?', 0),
(@ID, 'esMX', '¿Has conseguido mi alfanje, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido quitarle mi alfanje a Negolash! ¡No puedo creer que tenga tanta suerte, $n! Conocerte ha hecho que mi suerte cambiase, ¡para mejor, eso sin duda!$B$B¡Gracias! Y si alguna vez consigo un barco y quieres navegar los mares, ¡serás mi $ginvitado:invitada; de honor!', 0),
(@ID, 'esMX', '¡Has conseguido quitarle mi alfanje a Negolash! ¡No puedo creer que tenga tanta suerte, $n! Conocerte ha hecho que mi suerte cambiase, ¡para mejor, eso sin duda!$B$B¡Gracias! Y si alguna vez consigo un barco y quieres navegar los mares, ¡serás mi $ginvitado:invitada; de honor!', 0);
-- 8555 Encomienda a los Vuelos
-- https://es.classic.wowhead.com/quest=8555
SET @ID := 8555;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eranikus, Vaelastrasz y Azuregos... Sin duda, conoces a estos dragones, mortal. No es coincidencia que hayan desempeñado papeles tan influyentes como observadores de nuestro mundo.$B$BDesafortunadamente (y mi propia ingenuidad es parcialmente culpable) ya sea por agentes de los Dioses Antiguos o por traición de aquellos que los llamarían amigos, cada guardián ha caído en la tragedia. Hasta qué punto ha alimentado mi propia desconfianza hacia los de tu especie.$B$BBúscalos... Y $r, prepárate para lo peor.', 0),
(@ID, 'esMX', 'Eranikus, Vaelastrasz y Azuregos... Sin duda, conoces a estos dragones, mortal. No es coincidencia que hayan desempeñado papeles tan influyentes como observadores de nuestro mundo.$B$BDesafortunadamente (y mi propia ingenuidad es parcialmente culpable) ya sea por agentes de los Dioses Antiguos o por traición de aquellos que los llamarían amigos, cada guardián ha caído en la tragedia. Hasta qué punto ha alimentado mi propia desconfianza hacia los de tu especie.$B$BBúscalos... Y $r, prepárate para lo peor.', 0);
-- 8556 El sello de fuerza implacable
-- https://es.classic.wowhead.com/quest=8556
SET @ID := 8556;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste el anillo y los materiales, $n?', 0),
(@ID, 'esMX', '¿Me trajiste el anillo y los materiales, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0),
(@ID, 'esMX', 'Cambiaré la gema del anillo por ti. Descubrirás que el efecto es mucho más... agradable.', 0);
-- 8557 El mantón de fuerza implacable
-- https://es.classic.wowhead.com/quest=8557
SET @ID := 8557;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Trajiste los materiales para la capa, $n?', 0),
(@ID, 'esMX', '¿Trajiste los materiales para la capa, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los Qiraji.', 0),
(@ID, 'esMX', 'Ah, sí... este mantón está impecable.$B$BToma esta capa, $n. Que te proteja de la magia repugnante de los Qiraji.', 0);
-- 8558 La hoz de fuerza implacable
-- https://es.classic.wowhead.com/quest=8558
SET @ID := 8558;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me trajiste los componentes que necesito, $n?', 0),
(@ID, 'esMX', '¿Me trajiste los componentes que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Esta es una empuñadura de obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrimela con gran confianza y vence a nuestros enemigos!', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Esta es una empuñadura de obra maestra... el equilibrio es perfecto.$B$BToma tu arma, $n. ¡Esgrimela con gran confianza y vence a nuestros enemigos!', 0);
-- 8559 Las grebas de conquistador
-- https://es.classic.wowhead.com/quest=8559
SET @ID := 8559;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes todo lo que solicité, $n?', 0),
(@ID, 'esMX', '¿Tienes todo lo que solicité, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe las doy confiando en que te ayudarán a aplastar al vil Qiraji.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. Has probado que no eres $gun:una; mortal $gordinario:ordinaria;.$B$BTe las doy confiando en que te ayudarán a aplastar al vil Qiraji.', 0);
-- Las musleras de conquistador
-- 8560, 8593
-- https://es.classic.wowhead.com/quest=8560
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8560, 8593) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8560, 'esES', '¿Trajiste los componentes que necesito, $n?', 0),
(8593, 'esES', '¿Trajiste los componentes que necesito, $n?', 0),
(8560, 'esMX', '¿Trajiste los componentes que necesito, $n?', 0),
(8593, 'esMX', '¿Trajiste los componentes que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8560, 8593) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8560, 'esES', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0),
(8593, 'esES', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0),
(8560, 'esMX', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0),
(8593, 'esMX', 'Sí... la piel del gusano será una excelente capa protectora. Combinado con las partes más fuertes de los Qiraji que hemos destruido en nuestro camino hacia aquí, esto debería ser una formidable pieza de armadura. ¡Que te ayude a afrontar los horrores indescriptibles que te aguardan en el interior!', 0);
-- La corona de conquistador
-- 8561, 8592
-- https://es.classic.wowhead.com/quest=8561
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8561, 8592) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8561, 'esES', '¿Me trajiste los componentes que pedí, $n?', 0),
(8592, 'esES', '¿Me trajiste los componentes que pedí, $n?', 0),
(8561, 'esMX', '¿Me trajiste los componentes que pedí, $n?', 0),
(8592, 'esMX', '¿Me trajiste los componentes que pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8561, 8592) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8561, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8592, 'esES', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8561, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0),
(8592, 'esMX', '¡Lo has logrado! Los susurros de los Emperadores Gemelos han cesado.$B$BToma esto como recompensa. El mero hecho de verlo infundirá miedo en los corazones de los Qiraji... les recordará a sus líderes caídos y $gal:a la; mortal que los mató.', 0);
-- 8562 La coraza de conquistador
-- https://es.classic.wowhead.com/quest=8562
SET @ID := 8562;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En su morada en Ahn\'Qiraj, el pavoroso C\'Thun aguarda dormido.', 0),
(@ID, 'esMX', 'En su morada en Ahn\'Qiraj, el pavoroso C\'Thun aguarda dormido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No esperaba que regresaras de tu intento, $n.$B$BHas cumplido un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun, no solo has salvado todo Azeroth, sino que también has inclinado la balanza de los eventos cósmicos más allá de tu comprensión.$B$BAcepta esta coraza como símbolo de la gloria y la carga que vendrá como consecuencia de tus acciones.$B$B¡Que su poder te ayude en los desafíos que te esperan, $gasesino:asesina; de dioses!', 0),
(@ID, 'esMX', 'No esperaba que regresaras de tu intento, $n.$B$BHas cumplido un destino más grande que el de la mayoría de los seres inmortales.$B$BAl matar a C\'Thun, no solo has salvado todo Azeroth, sino que también has inclinado la balanza de los eventos cósmicos más allá de tu comprensión.$B$BAcepta esta coraza como símbolo de la gloria y la carga que vendrá como consecuencia de tus acciones.$B$B¡Que su poder te ayude en los desafíos que te esperan, $gasesino:asesina; de dioses!', 0);
-- 8564 Instrucción de sacerdote
-- https://es.classic.wowhead.com/quest=8564
SET @ID := 8564;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida;, $n. Soy Matrona Arena. Ofrezco mis servicios a quienes buscan aprender los caminos $gdel:de la; $n. Este camino a menudo se malinterpreta como un camino de pacifismo; para nosotros, los elfos de sangre, esto no podría estar más lejos de la verdad. Si bien reparamos tanto los huesos como el espíritu, también actuamos como un puño de venganza para aquellos que se rebelen contra nosotros.$B$BTe prepararé, pero todo lo que te pido es que cubras los costos de capacitación que puedan surgir y que aprendas con la mente abierta. Si estás de acuerdo con esto, podemos comenzar.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida;, $n. Soy Matrona Arena. Ofrezco mis servicios a quienes buscan aprender los caminos $gdel:de la; $n. Este camino a menudo se malinterpreta como un camino de pacifismo; para nosotros, los elfos de sangre, esto no podría estar más lejos de la verdad. Si bien reparamos tanto los huesos como el espíritu, también actuamos como un puño de venganza para aquellos que se rebelen contra nosotros.$B$BTe prepararé, pero todo lo que te pido es que cubras los costos de capacitación que puedan surgir y que aprendas con la mente abierta. Si estás de acuerdo con esto, podemos comenzar.', 0);
-- Equipamiento de Veterano
-- 8572, 8573, 8574
-- https://es.classic.wowhead.com/quest=8572
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8572, 8573, 8574) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8572, 'esES', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0),
(8573, 'esES', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0),
(8574, 'esES', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0),
(8572, 'esMX', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0),
(8573, 'esMX', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0),
(8574, 'esMX', 'Nos conviene mantener bien preparados a nuestros aliados más leales, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8572, 8573, 8574) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8572, 'esES', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:amiga;!', 0),
(8573, 'esES', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:amiga;!', 0),
(8574, 'esES', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:amiga;!', 0),
(8572, 'esMX', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:amiga;!', 0),
(8573, 'esMX', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:amiga;!', 0),
(8574, 'esMX', 'Buen trabajo, $n. Acepta esto en nombre del Círculo Cenarion. ¡Seguro que te lo has ganado, $gamigo:amiga;!', 0);
-- 8575 El libro de contabilidad mágico de Azuregos
-- https://es.classic.wowhead.com/quest=8575
SET @ID := 8575;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ooooh! ¡Cosa mágica pulsante! ¿Para mí?', 0),
(@ID, 'esMX', '¡Ooooh! ¡Cosa mágica pulsante! ¿Para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Narain examina ansiosamente el texto.>$B$B¡Excepcional, $r! ¿Qué es? No puedo leer ni una pizca de Dracónico.', 0),
(@ID, 'esMX', '<Narain examina ansiosamente el texto.>$B$B¡Excepcional, $r! ¿Qué es? No puedo leer ni una pizca de Dracónico.', 0);
-- 8576 La traducción del libro de contabilidad
-- https://es.classic.wowhead.com/quest=8576
SET @ID := 8576;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo primero es lo primero, $n! Necesitamos averiguar qué escribió Azuregos en este libro contable.$B$B¿Dices que te ha dicho que hagas una boya de arcanita y que este es el esquema? Es extraño que escribiera esto en Dracónico. Esa vieja cabra sabe que no puedo leer estas tonterías.$B$BSi esto va a funcionar, voy a necesitar mis gafas de adivinación, un pollo de 500 kilos y el volumen II de "Dracónico para Torpes". No necesariamente en ese orden.', 0),
(@ID, 'esMX', '¡Lo primero es lo primero, $n! Necesitamos averiguar qué escribió Azuregos en este libro contable.$B$B¿Dices que te ha dicho que hagas una boya de arcanita y que este es el esquema? Es extraño que escribiera esto en Dracónico. Esa vieja cabra sabe que no puedo leer estas tonterías.$B$BSi esto va a funcionar, voy a necesitar mis gafas de adivinación, un pollo de 500 kilos y el volumen II de "Dracónico para Torpes". No necesariamente en ese orden.', 0);
-- 8577 Guisón, ex mejor amigo
-- https://es.classic.wowhead.com/quest=8577
SET @ID := 8577;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo creer que me haya encontrado. Estaba seguro de que lo había perdido cuando estaba en Terrallende. ¡No voy a volver allí, $r! ¡De ninguna manera, de ninguna manera! Estoy harto de ser su mejor amigo a tiempo parcial y esclavo a tiempo completo.', 0),
(@ID, 'esMX', 'No puedo creer que me haya encontrado. Estaba seguro de que lo había perdido cuando estaba en Terrallende. ¡No voy a volver allí, $r! ¡De ninguna manera, de ninguna manera! Estoy harto de ser su mejor amigo a tiempo parcial y esclavo a tiempo completo.', 0);
-- 8578 ¿Unas gafas? ¡Sin problemas!
-- https://es.classic.wowhead.com/quest=8578
SET @ID := 8578;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El núcleo fundido, ¿eh? ¡Espero que mis gafas estén todavía de una pieza!', 0),
(@ID, 'esMX', 'El núcleo fundido, ¿eh? ¡Espero que mis gafas estén todavía de una pieza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sobresaliente! Ahora, ¿dónde puse ese pollo de 500 kilos y el Volumen II de "Dracónico para Torpes"??? ¡Ah, y aquí hay algo por todo tu arduo trabajo!', 0),
(@ID, 'esMX', '¡Sobresaliente! Ahora, ¿dónde puse ese pollo de 500 kilos y el Volumen II de "Dracónico para Torpes"??? ¡Ah, y aquí hay algo por todo tu arduo trabajo!', 0);
-- 8580 ¡La Horda necesita flores de fuego!
-- https://es.classic.wowhead.com/quest=8580
SET @ID := 8580;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Terminaste de recolectar esas muestras? ¡Podríamos perder a Noggle en cualquier momento!', 0),
(@ID, 'esMX', '¿Terminaste de recolectar esas muestras? ¡Podríamos perder a Noggle en cualquier momento!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cruza los dedos, amigo! ¡Esperamos que podamos salvar a Noggle!', 0),
(@ID, 'esMX', '¡Cruza los dedos, amigo! ¡Esperamos que podamos salvar a Noggle!', 0);
-- 8581 ¡La Horda necesita más flores de fuego!
-- https://es.classic.wowhead.com/quest=8581
SET @ID := 8581;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿N\'es una broma, $n? ¿Traes flores de fuego tan rápido? ¡Pele\'keiki las cuenta ahora mismo, colega! Estás haciendo a Pele\'keiki tan feliz, qu\'él se lo dirá a todos, $n ¡el mejor coleccionista de flores de fuego! Pele\'keiki no puede esperar a que comience la guerra. Ahora realmente iluminamos el cielo sobre Silithus, ¿verdad, colega?', 0),
(@ID, 'esMX', '¿N\'es una broma, $n? ¿Traes flores de fuego tan rápido? ¡Pele\'keiki las cuenta ahora mismo, colega! Estás haciendo a Pele\'keiki tan feliz, qu\'él se lo dirá a todos, $n ¡el mejor coleccionista de flores de fuego! Pele\'keiki no puede esperar a que comience la guerra. Ahora realmente iluminamos el cielo sobre Silithus, ¿verdad, colega?', 0);
-- 8582 ¡La Horda necesita lotos cárdenos!
-- https://es.classic.wowhead.com/quest=8582
SET @ID := 8582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto ya con el loto cárdeno que te pedí, $c? Es vital que lo hagas en el menor tiempo posible no vaya a ser que todo lo que estoy intentando aquí se malogre.', 0),
(@ID, 'esMX', '¿Has vuelto ya con el loto cárdeno que te pedí, $c? Es vital que lo hagas en el menor tiempo posible no vaya a ser que todo lo que estoy intentando aquí se malogre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo digno de elogio, $c. Mediré estos ejemplares para que se usen apropiadamente y tomaré nota de tu contribución. Habrá que guardar debidamente el loto cárdeno hasta que esté listo. En cuanto a ti, si aún estás disponible, aún voy a necesitar más loto cárdeno. Así que pásate de nuevo pronto.', 0),
(@ID, 'esMX', 'Un trabajo digno de elogio, $c. Mediré estos ejemplares para que se usen apropiadamente y tomaré nota de tu contribución. Habrá que guardar debidamente el loto cárdeno hasta que esté listo. En cuanto a ti, si aún estás disponible, aún voy a necesitar más loto cárdeno. Así que pásate de nuevo pronto.', 0);
-- 8583 ¡La Horda necesita más lotos cárdenos!
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=8583
SET @ID := 8583;
UPDATE `quest_request_items` SET `CompletionText` = 'In fact it does appear that we are in need of even more purple lotus, $c. While my own studies have yet to determine a new useful application for the herb, there are tried and true methodologies yet to be employed.$B$BI need you to once again go out into the field and collect at least twenty purple lotus samples. Return them to me here.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De hecho, al parecer necesitamos aún más loto cárdeno, $c. Aunque mis nuevas investigaciones no hayan permitido todavía descubrir nuevas aplicaciones de utilidad para esta hierba, aún quedan metodologías ciertas y probadas que aprovechar.$B$BNecesito que vayas de nuevo al campo y recolectes al menos 20 ejemplares de loto cárdeno. Cuando los tengas, tráemelos aquí.', 0),
(@ID, 'esMX', 'De hecho, al parecer necesitamos aún más loto cárdeno, $c. Aunque mis nuevas investigaciones no hayan permitido todavía descubrir nuevas aplicaciones de utilidad para esta hierba, aún quedan metodologías ciertas y probadas que aprovechar.$B$BNecesito que vayas de nuevo al campo y recolectes al menos 20 ejemplares de loto cárdeno. Cuando los tengas, tráemelos aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo de primera y de lo más preciso, $n. Tu diligencia es digna de elogio, al igual que tu celeridad. Me ocuparé personalmente de que no se desperdicia un ápice de este loto cárdeno.$B$BGracias otra vez y si encuentras más loto cárdeno, no dudes en traérmelo tan $graudo:rauda; como puedas.', 0),
(@ID, 'esMX', 'Un trabajo de primera y de lo más preciso, $n. Tu diligencia es digna de elogio, al igual que tu celeridad. Me ocuparé personalmente de que no se desperdicia un ápice de este loto cárdeno.$B$BGracias otra vez y si encuentras más loto cárdeno, no dudes en traérmelo tan $graudo:rauda; como puedas.', 0);
-- 8584 ¡Nunca me preguntes por mi negocio!
-- https://es.classic.wowhead.com/quest=8584
SET @ID := 8584;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Dirge se rasca la cabeza.>$B$B¿Un pollo de 500 kilos? ¡No hay tal cosa! Ya no, al menos. Sabía de un pollo así... El Pollo Negro de la Muerte...$B$B<La voz de Dirge se apaga.>$B$BPero sí, nadie vio ese pollo y vivió para contarlo. Tengo una idea que podría beneficiarnos a los dos, $gchico:chica;.', 0),
(@ID, 'esMX', '<Dirge se rasca la cabeza.>$B$B¿Un pollo de 500 kilos? ¡No hay tal cosa! Ya no, al menos. Sabía de un pollo así... El Pollo Negro de la Muerte...$B$B<La voz de Dirge se apaga.>$B$BPero sí, nadie vio ese pollo y vivió para contarlo. Tengo una idea que podría beneficiarnos a los dos, $gchico:chica;.', 0);
-- 8585 La Isla del Terror
-- https://es.classic.wowhead.com/quest=8585
SET @ID := 8585;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmmmm... quimerok...', 0),
(@ID, 'esMX', 'Mmmmm... quimerok...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mira esos solomillos! ¡Fantástico!$B$BAhora sobre ese pollo... Hrmm, déjame ver. Voy a necesitar unos minutos para idear la receta.', 0),
(@ID, 'esMX', '¡Mira esos solomillos! ¡Fantástico!$B$BAhora sobre ese pollo... Hrmm, déjame ver. Voy a necesitar unos minutos para idear la receta.', 0);
-- 8586 Fabulosas chuletillas de quimerok de Dirge
-- https://es.classic.wowhead.com/quest=8586
SET @ID := 8586;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Date prisa, $gchico:chica;. No queremos que esta carne se eche a perder.', 0),
(@ID, 'esMX', 'Date prisa, $gchico:chica;. No queremos que esta carne se eche a perder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Está listo! Te presento mi mayor creación: ¡Fabulosas chuletillas de quimerok de Dirge!', 0),
(@ID, 'esMX', '¡Está listo! Te presento mi mayor creación: ¡Fabulosas chuletillas de quimerok de Dirge!', 0);
-- 8587 Regresa junto a Narain
-- https://es.classic.wowhead.com/quest=8587
SET @ID := 8587;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es ese delicioso olor?', 0),
(@ID, 'esMX', '¿Qué es ese delicioso olor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Narain clava las dos manos en el enorme pollo, llenándose la cara del delicioso manjar de Dirge.>$B$BMMmmm... ¡Esto es increíble! ¡El mejor pollo que he comido!', 0),
(@ID, 'esMX', '<Narain clava las dos manos en el enorme pollo, llenándose la cara del delicioso manjar de Dirge.>$B$BMMmmm... ¡Esto es increíble! ¡El mejor pollo que he comido!', 0);
-- 8588 ¡La Horda necesita cuero pesado!
-- https://es.classic.wowhead.com/quest=8588
SET @ID := 8588;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tengo tiempo para jueguecitos si solo has venido a dar discursos, $c. Hay demasiadas pilas de cuero pesado que curtir. Vuelve cuando tengas al menos 10 para mí.', 0),
(@ID, 'esMX', 'No tengo tiempo para jueguecitos si solo has venido a dar discursos, $c. Hay demasiadas pilas de cuero pesado que curtir. Vuelve cuando tengas al menos 10 para mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, así que ya tienes el cuero pesado que necesitaba. Afilada es tu espada, $c; ¡estas pieles son muy buenas! Ahora que hemos empezado con buen pie, me ocuparé de que se aproveche debidamente tu contribución. Y si encuentras más cuero pesado, tráemelo.', 0),
(@ID, 'esMX', 'Ah, así que ya tienes el cuero pesado que necesitaba. Afilada es tu espada, $c; ¡estas pieles son muy buenas! Ahora que hemos empezado con buen pie, me ocuparé de que se aproveche debidamente tu contribución. Y si encuentras más cuero pesado, tráemelo.', 0);
-- 8589 ¡La Horda necesita más cuero pesado!
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=8589
SET @ID := 8589;
UPDATE `quest_request_items` SET `CompletionText` = 'It\'s true, $c, I still need more heavy leather. The requests from the generals and their quartermasters seem endless. And that\'s nothing compared to what the zeppelin masters are asking for!$B$BI need to get my quota collected on the double. $n, bring me more stacks of heavy leather as soon as you can!', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así es, $c, aún necesito más cuero pesado. Los pedidos de los generales y sus intendentes no se acaban nunca. ¡Y eso no es nada comparado con lo que los maestros de zepelín están pidiendo!$B$BTengo que completar mi cupo a paso ligero. $n, tráeme más pilas de cuero pesado ¡tan pronto como puedas!', 0),
(@ID, 'esMX', 'Así es, $c, aún necesito más cuero pesado. Los pedidos de los generales y sus intendentes no se acaban nunca. ¡Y eso no es nada comparado con lo que los maestros de zepelín están pidiendo!$B$BTengo que completar mi cupo a paso ligero. $n, tráeme más pilas de cuero pesado ¡tan pronto como puedas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así me gusta, colega! Muchísimas gracias por el cuero pesado. Cada granito de arena es importante. Voy a dejar estas pieles en una pila para que los demás peleteros puedan trabajarlas.$B$BGracias otra vez, $n, y si te topas con más cuero pesado, ya sabes dónde encontrarme.', 0),
(@ID, 'esMX', '¡Así me gusta, colega! Muchísimas gracias por el cuero pesado. Cada granito de arena es importante. Voy a dejar estas pieles en una pila para que los demás peleteros puedan trabajarlas.$B$BGracias otra vez, $n, y si te topas con más cuero pesado, ya sabes dónde encontrarme.', 0);
-- 8590 ¡La Horda necesita cuero grueso!
-- https://es.classic.wowhead.com/quest=8590
SET @ID := 8590;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $c, ¿tan pronto de vuelta con las 10 piezas de cuero grueso de las que hablamos?', 0),
(@ID, 'esMX', 'Ah, $c, ¿tan pronto de vuelta con las 10 piezas de cuero grueso de las que hablamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $c. Estoy segura de que todas estas pieles de cuero grueso servirán para reforzar los zepelines y confeccionar todo tipo de armas y armaduras. Cuentas con mi más sincero agradecimiento, así como con el de la Horda. Vuelve si encuentras más cuero grueso en tus viajes y que la suerte te acompañe.', 0),
(@ID, 'esMX', 'Buen trabajo, $c. Estoy segura de que todas estas pieles de cuero grueso servirán para reforzar los zepelines y confeccionar todo tipo de armas y armaduras. Cuentas con mi más sincero agradecimiento, así como con el de la Horda. Vuelve si encuentras más cuero grueso en tus viajes y que la suerte te acompañe.', 0);
-- 8591 ¡La Horda necesita más cuero grueso!
-- Notice: English text is also missing in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=8591
SET @ID := 8591;
UPDATE `quest_request_items` SET `CompletionText` = '$c, as you can see I still need to gather up more thick leather. Once again I ask your help with this task, and promise that if you complete it, you will be recognized for your efforts.$B$BTime is of the essence! Return to me with the thick leather so that we can finish our preparations and go to war, hero!', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, como ves, necesito recolectar aún más cuero grueso. Una vez más te pido tu ayuda para esta tarea y prometo que si la completas, se te reconocerá tu dedicación.$B$B¡El tiempo es vital! ¡Vuelve aquí cuando tengas el cuero pesado para que pueda acabar nuestros preparativos para la guerra, $ghéroe:heroína;!', 0),
(@ID, 'esMX', '$c, como ves, necesito recolectar aún más cuero grueso. Una vez más te pido tu ayuda para esta tarea y prometo que si la completas, se te reconocerá tu dedicación.$B$B¡El tiempo es vital! ¡Vuelve aquí cuando tengas el cuero pesado para que pueda acabar nuestros preparativos para la guerra, $ghéroe:heroína;!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo conseguiste, $n, sabía que lo conseguirías! Una vez más, gracias en nombre de toda la Horda. Se toma buena nota de tu trabajo y se agradece. Y si encuentras más cuero grueso que te gustaría donar, tráemelo aquí.$B$B¡Lok\'tar Ogar, $c!', 0),
(@ID, 'esMX', '¡Lo conseguiste, $n, sabía que lo conseguirías! Una vez más, gracias en nombre de toda la Horda. Se toma buena nota de tu trabajo y se agradece. Y si encuentras más cuero grueso que te gustaría donar, tráemelo aquí.$B$B¡Lok\'tar Ogar, $c!', 0);
-- 8594 El manto del Oráculo
-- https://es.classic.wowhead.com/quest=8594
SET @ID := 8594;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha recogido los componentes que necesito?', 0),
(@ID, 'esMX', '¿Ha recogido los componentes que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que verlos infunda miedo en nuestros enemigos.', 0),
(@ID, 'esMX', 'De los materiales que traes y de las escamas de nuestros enemigos Qiraji caídos, te hago estas hombreras, mortal. Que te brinden la protección que necesitas y que verlos infunda miedo en nuestros enemigos.', 0);
-- 8595 Campeones mortales
-- https://es.wowhead.com/quest=8595
SET @ID := 8595;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Matar a un Señor qiraji es un logro notable para $gun:una; mortal, $n. Sin embargo, son muchos y poderosos. Sigue derrotándolos y demuestra lo que vales como $gnuestro Campeón:nuestra Campeona;.', 0),
(@ID, 'esMX', 'Matar a un Señor qiraji es un logro notable para $gun:una; mortal, $n. Sin embargo, son muchos y poderosos. Sigue derrotándolos y demuestra lo que vales como $gnuestro Campeón:nuestra Campeona;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigues sirviéndonos bien, $n. Nuestro pacto sigue en pie.', 0),
(@ID, 'esMX', 'Sigues sirviéndonos bien, $n. Nuestro pacto sigue en pie.', 0);
-- 8596 Los borceguíes del Oráculo
-- https://es.wowhead.com/quest=8596
SET @ID := 8596;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido esos objetos que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has conseguido esos objetos que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Has demostrado que no eres $gun:una; mortal cualquiera.$B$BTe entrego estas confiando en que te ayudarán a aplastar a los malvados qiraji.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Has demostrado que no eres $gun:una; mortal cualquiera.$B$BTe entrego estas confiando en que te ayudarán a aplastar a los malvados qiraji.', 0);
-- 8597 Dracónico para torpes
-- https://es.classic.wowhead.com/quest=8597
SET @ID := 8597;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El libro no está! Encima del montículo de tierra hay una nota.', 0),
(@ID, 'esMX', '¡El libro no está! Encima del montículo de tierra hay una nota.', 0);
-- 8598 ReScaTe
-- https://es.classic.wowhead.com/quest=8598
SET @ID := 8598;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, ¿cuál es el problema?', 0),
(@ID, 'esMX', 'Dime, ¿cuál es el problema?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La cara de Narain se pone de un rojo brillante.>$B$BTorturar a mi... libro, ¿lo harán? ¡Les enseñaré lo que significa meterse con un gnomo psíquico!', 0),
(@ID, 'esMX', '<La cara de Narain se pone de un rojo brillante.>$B$BTorturar a mi... libro, ¿lo harán? ¡Les enseñaré lo que significa meterse con un gnomo psíquico!', 0);
-- 8599 Una canción de amor para Narain
-- https://es.classic.wowhead.com/quest=8599
SET @ID := 8599;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hueles a pescado!', 0),
(@ID, 'esMX', '¡Hueles a pescado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¡Qué!?$B$B<Narain comienza a inquietarse.>$B$BBueno, umm... ¿Qué quieres que haga??? ¡Ella es un pez! ¡UN PESCADO, te lo digo! Y soy un gnomo. Nunca podría funcionar.', 0),
(@ID, 'esMX', '¿¡Qué!?$B$B<Narain comienza a inquietarse.>$B$BBueno, umm... ¿Qué quieres que haga??? ¡Ella es un pez! ¡UN PESCADO, te lo digo! Y soy un gnomo. Nunca podría funcionar.', 0);
-- 8600 ¡La Horda necesita pieles de cuero basto!
-- https://es.classic.wowhead.com/quest=8600
SET @ID := 8600;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No es posible que te lleve tanto tiempo desollar 10 pieles de cuero basto para mí! ¿Quizás necesites afilar tu cuchillo de desollar? ¿O acaso estoy confundido y las tienes ahí en tu bolsa?', 0),
(@ID, 'esMX', '¡No es posible que te lleve tanto tiempo desollar 10 pieles de cuero basto para mí! ¿Quizás necesites afilar tu cuchillo de desollar? ¿O acaso estoy confundido y las tienes ahí en tu bolsa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, parece que has hecho un buen trabajo, aunque algunas de estas pieles tienen los bordes algo irregulares. No importa, has completado la tarea y te has ganado una recompensa. Si te vuelves a encontrar con más cuero basto, tráemelo inmediatamente.', 0),
(@ID, 'esMX', 'Muy bien, parece que has hecho un buen trabajo, aunque algunas de estas pieles tienen los bordes algo irregulares. No importa, has completado la tarea y te has ganado una recompensa. Si te vuelves a encontrar con más cuero basto, tráemelo inmediatamente.', 0);
