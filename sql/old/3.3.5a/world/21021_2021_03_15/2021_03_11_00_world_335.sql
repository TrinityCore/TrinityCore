-- 7101 Las torres y los búnkeres
-- https://es.classic.wowhead.com/quest=7101
SET @ID := 7101;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Torre capturada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aún no has asaltado un búnker, $n! ¿Estás esperando que otros reclamen tu gloria?', 0),
(@ID, 'esMX', '¡Aún no has asaltado un búnker, $n! ¿Estás esperando que otros reclamen tu gloria?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡He oído hablar de tu éxito en la misión! Me complace tal noticia...$B$BNuestros soldados podrán ahora cargar con impunidad ¡y demostrar a la Alianza que el Valle de Alterac no es lugar para ellos!', 0),
(@ID, 'esMX', '¡He oído hablar de tu éxito en la misión! Me complace tal noticia...$B$BNuestros soldados podrán ahora cargar con impunidad ¡y demostrar a la Alianza que el Valle de Alterac no es lugar para ellos!', 0);
-- 7102 Las torres y los búnkeres
-- https://es.classic.wowhead.com/quest=7102
SET @ID := 7102;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Estandarte destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aún no has asaltado una torre, $n! ¿Que estas esperando?', 0),
(@ID, 'esMX', '¡Aún no has asaltado una torre, $n! ¿Que estas esperando?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He recibido un informe de campo según el cual has contribuido a recuperar un estandarte enemigo. ¡Muy bien, $n! Con sus líneas descolocadas ¡podemos adelantar más el frente!', 0),
(@ID, 'esMX', 'He recibido un informe de campo según el cual has contribuido a recuperar un estandarte enemigo. ¡Muy bien, $n! Con sus líneas descolocadas ¡podemos adelantar más el frente!', 0);
-- 7121 El intendente
-- https://es.classic.wowhead.com/quest=7121
SET @ID := 7121;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno ver a nuevos soldados aquí, $n, pero con un poco de suerte entrarás pronto en combate ¡y no serás $gun novato:una novata; por mucho tiempo!$B$BVuelve a hablar conmigo. Tengo tareas que tratar contigo...', 0),
(@ID, 'esMX', 'Es bueno ver a nuevos soldados aquí, $n, pero con un poco de suerte entrarás pronto en combate ¡y no serás $gun novato:una novata; por mucho tiempo!$B$BVuelve a hablar conmigo. Tengo tareas que tratar contigo...', 0);
-- 7122 Capturar una mina
-- https://es.classic.wowhead.com/quest=7122
SET @ID := 7122;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Mina capturada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aún no has capturado la mina, $n!$B$BUna vez que controlemos una mina, será mucho más fácil recolectar minerales y suministros de ella.', 0),
(@ID, 'esMX', '¡Aún no has capturado la mina, $n!$B$BUna vez que controlemos una mina, será mucho más fácil recolectar minerales y suministros de ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! ¡Muy bien, $n!$B$BCuando nos hacemos con el control de una mina y tenemos a soldados estacionados allí, es mucho más fácil recolectar el mineral y los suministros.', 0),
(@ID, 'esMX', '¡Lo has conseguido! ¡Muy bien, $n!$B$BCuando nos hacemos con el control de una mina y tenemos a soldados estacionados allí, es mucho más fácil recolectar el mineral y los suministros.', 0);
-- 7123 Habla con nuestro intendente
-- https://es.classic.wowhead.com/quest=7123
SET @ID := 7123;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, $n! Me alegra ver que $gun:una; $c como tú está impaciente por aportar su granito de arena a la Horda. Vuelve a hablar conmigo, tengo tareas vitales para ti...', 0),
(@ID, 'esMX', '¡Hola, $n! Me alegra ver que $gun:una; $c como tú está impaciente por aportar su granito de arena a la Horda. Vuelve a hablar conmigo, tengo tareas vitales para ti...', 0);
-- 7124 Capturar una mina
-- Notice: English text: change '$n>.' to '$n.' in quest_offer_reward.RewardText
-- https://es.wowhead.com/quest=7124
-- https://tcubuntu.northeurope.cloudapp.azure.com/aowow/?quest=7124
SET @ID := 7124;
UPDATE `quest_offer_reward` SET `RewardText` = 'You captured a mine! With our own warriors protecting it, it will be much simpler to extract minerals from its depths, or gather supplies that have been cached there.$B$BWell done, $n. The deed you have done is a great boon to our battle efforts.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Mina capturada', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aún no has capturado una mina, $n! ¡Encuentra una que no controlemos y derrota a su líder!', 0),
(@ID, 'esMX', '¡Aún no has capturado una mina, $n! ¡Encuentra una que no controlemos y derrota a su líder!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has capturado una mina! Con nuestros propios guerreros protegiéndola, será mucho más sencillo extraer minerales de sus profundidades y recolectar los suministros que allí hubieran escondido.$B$BMuy bien, $n. Esta acción ha sido una gran contribución a nuestros esfuerzos en la batalla.', 0),
(@ID, 'esMX', '¡Has capturado una mina! Con nuestros propios guerreros protegiéndola, será mucho más sencillo extraer minerales de sus profundidades y recolectar los suministros que allí hubieran escondido.$B$BMuy bien, $n. Esta acción ha sido una gran contribución a nuestros esfuerzos en la batalla.', 0);
-- 7141 La batalla de Alterac
-- https://es.classic.wowhead.com/quest=7141
SET @ID := 7141;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ve, $n! ¡Ve al Valle de Alterac y derrota al general orco!', 0),
(@ID, 'esMX', '¡Ve, $n! ¡Ve al Valle de Alterac y derrota al general orco!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n! Con la nariz de la Horda ensangrentada tras la muerte de su general, ¡tendremos margen para explorar!', 0),
(@ID, 'esMX', '¡Muy bien, $n! Con la nariz de la Horda ensangrentada tras la muerte de su general, ¡tendremos margen para explorar!', 0);
-- 7142 La batalla por Alterac
-- https://es.wowhead.com/quest=7142
SET @ID := 7142;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n! Los Pico Tormenta no tienen ninguna posibilidad en esta insensata invasión.$B$B¡Ja! Hasta ahora, ¡solo han conseguido que maten a su general!', 0),
(@ID, 'esMX', '¡Muy bien, $n! Los Pico Tormenta no tienen ninguna posibilidad en esta insensata invasión.$B$B¡Ja! Hasta ahora, ¡solo han conseguido que maten a su general!', 0);
-- 7161 Terreno de Pruebas
-- https://es.classic.wowhead.com/quest=7161
SET @ID := 7161;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Despierta! ¡Despierta, $n! Esto no es un sueño. ¡Estás realmente $gatrincherado:atrincherada; en medio de una cruda batalla!', 0),
(@ID, 'esMX', '¡Despierta! ¡Despierta, $n! Esto no es un sueño. ¡Estás realmente $gatrincherado:atrincherada; en medio de una cruda batalla!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ese ardor que sientes es tu alma que se despierta. Tu espíritu ha aceptado la llamada a las armas.$B$BAhora formas parte de los Lobo Gélido, $n. Enhorabuena.$B$BLleva siempre contigo esta insignia. A medida que subes de rango entre los Lobo Gélido, sustituiré tu insignia por otras, otras más poderosas.$B$BQuizás algún día se exalten tus hazañas entre el clan Lobo Gélido. Si tal día llega, se te concederá el Ojo del Orden.', 0),
(@ID, 'esMX', 'Ese ardor que sientes es tu alma que se despierta. Tu espíritu ha aceptado la llamada a las armas.$B$BAhora formas parte de los Lobo Gélido, $n. Enhorabuena.$B$BLleva siempre contigo esta insignia. A medida que subes de rango entre los Lobo Gélido, sustituiré tu insignia por otras, otras más poderosas.$B$BQuizás algún día se exalten tus hazañas entre el clan Lobo Gélido. Si tal día llega, se te concederá el Ojo del Orden.', 0);
-- 7162 Terreno de Pruebas
-- https://es.classic.wowhead.com/quest=7162
SET @ID := 7162;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuidado con las arpías de la región, $c. ¡No se lo pensarán dos veces antes de cortarte el cuello!', 0),
(@ID, 'esMX', 'Cuidado con las arpías de la región, $c. ¡No se lo pensarán dos veces antes de cortarte el cuello!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toma esta insignia y llévala con orgullo, $n. A medida que subes de rango entre los Pico Tormenta, recibirás la insignia correspondiente. Vuelve aquí conforme adquieres más honores con los Pico Tormenta y sustituiré tu insignia por otras, otras más poderosas.$B$BQuizás algún día llegues a crecer tanto como para convertirte en una leyenda en el campo de batalla. Si tal día llega, se te concederá el Ojo del Orden.', 0),
(@ID, 'esMX', 'Toma esta insignia y llévala con orgullo, $n. A medida que subes de rango entre los Pico Tormenta, recibirás la insignia correspondiente. Vuelve aquí conforme adquieres más honores con los Pico Tormenta y sustituiré tu insignia por otras, otras más poderosas.$B$BQuizás algún día llegues a crecer tanto como para convertirte en una leyenda en el campo de batalla. Si tal día llega, se te concederá el Ojo del Orden.', 0);
-- 7163 Ascender y darse a conocer
-- https://es.wowhead.com/quest=7163
SET @ID := 7163;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El maestro de guerra Laggrond te hace el saludo.>$B$BHa llegado tu hora, $n. Has hecho mucho por el clan Lobo Gélido y con ello, te has ganado un lugar no solo como $gun:una; soldado Lobo Gélido sino también como $gamigo:amiga;.$B$B¡Muy bien! ¡Presenta tu insignia de Iniciado!', 0),
(@ID, 'esMX', '<El maestro de guerra Laggrond te hace el saludo.>$B$BHa llegado tu hora, $n. Has hecho mucho por el clan Lobo Gélido y con ello, te has ganado un lugar no solo como $gun:una; soldado Lobo Gélido sino también como $gamigo:amiga;.$B$B¡Muy bien! ¡Presenta tu insignia de Iniciado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta nueva insignia refleja tu rango entre los Lobo Gélido. Llévala siempre contigo.$B$BY $c... Muere con honor.', 0),
(@ID, 'esMX', 'Esta nueva insignia refleja tu rango entre los Lobo Gélido. Llévala siempre contigo.$B$BY $c... Muere con honor.', 0);
-- 7164 Honorable con el clan
-- https://es.wowhead.com/quest=7164
SET @ID := 7164;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cómo me alegra verte de nuevo, $c! No esperaba que regresaras. No obstante, has demostrado ser $gun:una; valiente y honorable soldado Lobo Gélido.$B$BHa llegado de nuevo tu hora, $n. Te has ganado un nuevo rango y con ello, una nueva insignia que refleje este aumento de importancia.$B$BPresenta tu insignia.', 0),
(@ID, 'esMX', '¡Cómo me alegra verte de nuevo, $c! No esperaba que regresaras. No obstante, has demostrado ser $gun:una; valiente y honorable soldado Lobo Gélido.$B$BHa llegado de nuevo tu hora, $n. Te has ganado un nuevo rango y con ello, una nueva insignia que refleje este aumento de importancia.$B$BPresenta tu insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El maestro de guerra Laggrond hace el saludo.>$B$B¡Vete, $n! Sigue con tu defensa de los Lobo Gélido. ¡Hay que ganar esta guerra! ¡Por Drek\'Thar! ¡Por el Jefe de Guerra!', 0),
(@ID, 'esMX', '<El maestro de guerra Laggrond hace el saludo.>$B$B¡Vete, $n! Sigue con tu defensa de los Lobo Gélido. ¡Hay que ganar esta guerra! ¡Por Drek\'Thar! ¡Por el Jefe de Guerra!', 0);
-- 7165 Ganarse una reverencia
-- https://es.classic.wowhead.com/quest=7165
SET @ID := 7165;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tantos muertos. La sangre empapa el campo. Y a pesar de ello... estás $gvivo:viva;... Has perseverado. Has conducido a nuestros ejércitos a muchas victorias. Por ello, soldado, te has ganado un nuevo rango.$B$BPresenta tu insignia.', 0),
(@ID, 'esMX', 'Tantos muertos. La sangre empapa el campo. Y a pesar de ello... estás $gvivo:viva;... Has perseverado. Has conducido a nuestros ejércitos a muchas victorias. Por ello, soldado, te has ganado un nuevo rango.$B$BPresenta tu insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El maestro de guerra Laggrond emite un rugido.>$B$BYa empieza a correrse la voz sobre tus hazañas, soldado. Los Pico Tormenta se estremecen de miedo con solo oír tu nombre. ¡Sigue así!', 0),
(@ID, 'esMX', '<El maestro de guerra Laggrond emite un rugido.>$B$BYa empieza a correrse la voz sobre tus hazañas, soldado. Los Pico Tormenta se estremecen de miedo con solo oír tu nombre. ¡Sigue así!', 0);
-- 7166 Héroes legendarios
-- https://es.classic.wowhead.com/quest=7166
SET @ID := 7166;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Irradias mando y poder, $c. $gExaltado:Exaltada; a los ojos de los Lobo Gélido, el enemigo se encoge ante la simple mención de tu nombre.$B$BEn pie, $ghéroe:heroína; de los Lobo Gélido. ¡Levántate y recibe los honores!$B$BPresenta tu insignia.', 0),
(@ID, 'esMX', 'Irradias mando y poder, $c. $gExaltado:Exaltada; a los ojos de los Lobo Gélido, el enemigo se encoge ante la simple mención de tu nombre.$B$BEn pie, $ghéroe:heroína; de los Lobo Gélido. ¡Levántate y recibe los honores!$B$BPresenta tu insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto, todos los que estén en el campo de batalla estarán bajo tu ojo vigilante. ¡Tendrás al valle y a sus soldados a tus órdenes!', 0),
(@ID, 'esMX', 'Pronto, todos los que estén en el campo de batalla estarán bajo tu ojo vigilante. ¡Tendrás al valle y a sus soldados a tus órdenes!', 0);
-- 7167 El ojo del orden
-- https://es.classic.wowhead.com/quest=7167
SET @ID := 7167;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Drek\'Thar no tiene más que alabanzas para ti. Por todo Kalimdor se cuentan tus hazañas. El Jefe de Guerra está radiante, tu inquebrantable defensa de nuestro clan le ha complacido sobremanera.$B$BTe has ganado el Ojo del Orden.$B$BPresenta tu insignia, comandante $n.', 0),
(@ID, 'esMX', 'Drek\'Thar no tiene más que alabanzas para ti. Por todo Kalimdor se cuentan tus hazañas. El Jefe de Guerra está radiante, tu inquebrantable defensa de nuestro clan le ha complacido sobremanera.$B$BTe has ganado el Ojo del Orden.$B$BPresenta tu insignia, comandante $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Canaliza el poder de la insignia. Deja que los enemigos oigan tus palabras. El poder de la Horda es incuestionable!', 0),
(@ID, 'esMX', 'Canaliza el poder de la insignia. Deja que los enemigos oigan tus palabras. El poder de la Horda es incuestionable!', 0);
-- 7168 Ascender y darse a conocer
-- https://es.classic.wowhead.com/quest=7168
SET @ID := 7168;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La mayoría no vive lo suficiente para superar su propia mediocridad. Has demostrado ser $gun:una; soldado ejemplar, $c. Ha llegado la hora.$B$BPresenta tu insignia.', 0),
(@ID, 'esMX', 'La mayoría no vive lo suficiente para superar su propia mediocridad. Has demostrado ser $gun:una; soldado ejemplar, $c. Ha llegado la hora.$B$BPresenta tu insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Que nuestros enemigos sepan que $gun:una; soldado de rango los ha atacado! ¡Lucha por la gloria de los Pico Tormenta!', 0),
(@ID, 'esMX', '¡Que nuestros enemigos sepan que $gun:una; soldado de rango los ha atacado! ¡Lucha por la gloria de los Pico Tormenta!', 0);
-- 7169 Honorable con la guardia
-- https://es.classic.wowhead.com/quest=7169
SET @ID := 7169;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por toda la base se habla de tus hazañas en la Tierra en Disputa! Le has asestado golpes contundentes a nuestro enemigo, ¡aplastándoles la moral! Por eso, te has ganado un rango de honor entre los Pico Tormenta.$B$BPresenta tu insignia.', 0),
(@ID, 'esMX', '¡Por toda la base se habla de tus hazañas en la Tierra en Disputa! Le has asestado golpes contundentes a nuestro enemigo, ¡aplastándoles la moral! Por eso, te has ganado un rango de honor entre los Pico Tormenta.$B$BPresenta tu insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Rey está al corriente de tus heroicos actos en el frente, $c. ¡Sigue con tu inquebrantable defensa de la Guardia de Pico Tormenta!', 0),
(@ID, 'esMX', 'El Rey está al corriente de tus heroicos actos en el frente, $c. ¡Sigue con tu inquebrantable defensa de la Guardia de Pico Tormenta!', 0);
-- 7170 Ganarse una reverencia
-- https://es.classic.wowhead.com/quest=7170
SET @ID := 7170;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo saberlo, $n. Cuando miras directamente a los ojos del enemigo, ¿ves miedo? ¿Se acobardan ahora en tu presencia? ¡Deben darse cuenta de que están derrotados!$B$BTe has ganado la reverencia de la Guardia. ¡Presenta tu insignia!', 0),
(@ID, 'esMX', 'Debo saberlo, $n. Cuando miras directamente a los ojos del enemigo, ¿ves miedo? ¿Se acobardan ahora en tu presencia? ¡Deben darse cuenta de que están derrotados!$B$BTe has ganado la reverencia de la Guardia. ¡Presenta tu insignia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando nos conocimos, nunca hubiera imaginado que se estaba gestando $gun héroe:una heroína;. ¡Continúa, soldado!', 0),
(@ID, 'esMX', 'Cuando nos conocimos, nunca hubiera imaginado que se estaba gestando $gun héroe:una heroína;. ¡Continúa, soldado!', 0);
-- 7171 Héroes legendarios
-- https://es.classic.wowhead.com/quest=7171
SET @ID := 7171;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ante mí se encuentra $gun exaltado héroe:una exaltada heroína; de la Alianza.$B$B<El teniente Haggerdin saluda.>$B$BSon pocos los que se han ganado ese rango entre los Pico Tormenta. He visto caer al enemigo ante ti. He visto su resolución desmoronarse en tu presencia. Cuando entras en la refriega, ¡te conviertes en el faro de esperanza para nuestras fuerzas!$B$BPresenta tu insignia.', 0),
(@ID, 'esMX', 'Ante mí se encuentra $gun exaltado héroe:una exaltada heroína; de la Alianza.$B$B<El teniente Haggerdin saluda.>$B$BSon pocos los que se han ganado ese rango entre los Pico Tormenta. He visto caer al enemigo ante ti. He visto su resolución desmoronarse en tu presencia. Cuando entras en la refriega, ¡te conviertes en el faro de esperanza para nuestras fuerzas!$B$BPresenta tu insignia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Seguramente serás tú quien lleve el Ojo del Orden!', 0),
(@ID, 'esMX', '¡Seguramente serás tú quien lleve el Ojo del Orden!', 0);
-- 7172 El ojo del orden
-- https://es.classic.wowhead.com/quest=7172
SET @ID := 7172;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Deja que escuchen tu voz, comandante $n! Hazles conocer el miedo. ¡Muéstrales el poder que tiene Pico Tormenta en tu rango!', 0),
(@ID, 'esMX', '¡Deja que escuchen tu voz, comandante $n! Hazles conocer el miedo. ¡Muéstrales el poder que tiene Pico Tormenta en tu rango!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eres tu quien debe llevar a nuestras tropas a la victoria, comandante! Los soldados están bajo tu mando. Seguirán tus órdenes directas. Guíalos... Aplasta al Lobo Gélido.', 0),
(@ID, 'esMX', '¡Eres tu quien debe llevar a nuestras tropas a la victoria, comandante! Los soldados están bajo tu mando. Seguirán tus órdenes directas. Guíalos... Aplasta al Lobo Gélido.', 0);
-- 7223 Los restos de armadura
-- https://es.classic.wowhead.com/quest=7223
SET @ID := 7223;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído algún resto de armadura, $n?', 0),
(@ID, 'esMX', '¿Me has traído algún resto de armadura, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas piezas son muy buenas, $n. Puedo usarlas para confeccionar nuevos equipos para nuestros soldados.$B$BSi mi nivel de suministro llega a ser suficientemente alto, ¡a lo mejor nuestras avezadas unidades de combate irán al campo de batalla!', 0),
(@ID, 'esMX', 'Estas piezas son muy buenas, $n. Puedo usarlas para confeccionar nuevos equipos para nuestros soldados.$B$BSi mi nivel de suministro llega a ser suficientemente alto, ¡a lo mejor nuestras avezadas unidades de combate irán al campo de batalla!', 0);
-- 7224 Botín enemigo
-- https://es.classic.wowhead.com/quest=7224
SET @ID := 7224;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $n? ¿Tienes algún resto de armadura para mí?', 0),
(@ID, 'esMX', '¿Cómo va la caza, $n? ¿Tienes algún resto de armadura para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos restos nos servirán. Los fundiré y los remendaré ¡y nadie se enterará de que proceden de esos cobardes Pico Tormenta!$B$BGracias, $n. Y permíteme pulir tu armadura...', 0),
(@ID, 'esMX', 'Estos restos nos servirán. Los fundiré y los remendaré ¡y nadie se enterará de que proceden de esos cobardes Pico Tormenta!$B$BGracias, $n. Y permíteme pulir tu armadura...', 0);
-- 7241 En defensa de Lobo Gélido
-- https://es.classic.wowhead.com/quest=7241
SET @ID := 7241;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para convertirte en $gun:una; soldado Lobo Gélido, hay que ponerte a prueba...', 0),
(@ID, 'esMX', 'Para convertirte en $gun:una; soldado Lobo Gélido, hay que ponerte a prueba...', 0);
-- 7281 Amor fraternal
-- https://es.classic.wowhead.com/quest=7281
SET @ID := 7281;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cómo debe de dolerle permanecer como uno de los vivos mientras su amado hermano ha ascendido a la perfección.', 0),
(@ID, 'esMX', 'Cómo debe de dolerle permanecer como uno de los vivos mientras su amado hermano ha ascendido a la perfección.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus proezas no pasarán desapercibidos, $n.$B$BNo debo perder el tiempo si hay que salvarlo. ¡Hay que ponerse en contacto con Sylvanas!', 0),
(@ID, 'esMX', 'Tus proezas no pasarán desapercibidos, $n.$B$BNo debo perder el tiempo si hay que salvarlo. ¡Hay que ponerse en contacto con Sylvanas!', 0);
-- 7282 Amor fraternal
-- https://es.classic.wowhead.com/quest=7282
SET @ID := 7282;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con gran pesar doy la orden, soldado.', 0),
(@ID, 'esMX', 'Con gran pesar doy la orden, soldado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te acordaste de incinerar el cuerpo, ¿verdad?', 0),
(@ID, 'esMX', 'Te acordaste de incinerar el cuerpo, ¿verdad?', 0);
-- 7301 Señores del Cielo caídos
-- https://es.classic.wowhead.com/quest=7301
SET @ID := 7301;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ubicación de Ichman descubierta', `ObjectiveText2` = 'Ubicación de Vipore descubierta', `ObjectiveText3` = 'Ubicación de Slidore descubierta', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Algo que me gustaría escuchar?', 0),
(@ID, 'esMX', '¿Algo que me gustaría escuchar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Los has liberado, ¿verdad? ¿¿¿No??? Bueno, al menos sabemos dónde están retenidos', 0),
(@ID, 'esMX', '¡Increíble! Los has liberado, ¿verdad? ¿¿¿No??? Bueno, al menos sabemos dónde están retenidos', 0);
-- 7302 Señores del Cielo caídos
-- https://es.classic.wowhead.com/quest=7302
SET @ID := 7302;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ubicación de Guse descubierta', `ObjectiveText2` = 'Ubicación de Jeztor descubierta', `ObjectiveText3` = 'Ubicación de Mulverick descubierta', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estado de la caza, soldado?', 0),
(@ID, 'esMX', '¿Estado de la caza, soldado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien! La información que has conseguido es muy valiosa para nuestra causa.', 0),
(@ID, 'esMX', '¡Muy bien! La información que has conseguido es muy valiosa para nuestra causa.', 0);
-- 7321 Sopa de tortuga reconfortante
-- https://es.classic.wowhead.com/quest=7321
SET @ID := 7321;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado los ingredientes? Debo advertirte de que los gusanos de la Alianza son muy numerosos en esta zona... En mi opinión, creo que ya están demasiado cerca...', 0),
(@ID, 'esMX', '¿Has encontrado los ingredientes? Debo advertirte de que los gusanos de la Alianza son muy numerosos en esta zona... En mi opinión, creo que ya están demasiado cerca...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi sopa de tortuga reconfortante te mantendrá caliente en una noche fría... por si te interesa saberlo.', 0),
(@ID, 'esMX', 'Mi sopa de tortuga reconfortante te mantendrá caliente en una noche fría... por si te interesa saberlo.', 0);
-- 7341 Un trato justo
-- https://es.classic.wowhead.com/quest=7341
SET @ID := 7341;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $r. Yo soy Kolark, un cazador de tesoros de Cima del Trueno. He viajado mucho por el mundo y he visto también mucho.$B$BMis viajes por los Mares del Sur me permitieron descubrir la existencia de estas flechas con cabeza de torio. Tengo un sinfín de ellas, pero ya no tengo balas. Y bueno, ningún tauren que se precie andaría por ahí con un endeble arco. ¡Las flechas no sirven para nada!$B$BTe voy a ofrecer un trato: si me traes proyectiles de torio te las cambio por mis cabezales de flecha de torio. ¿Hecho?', 0),
(@ID, 'esMX', 'Saludos, $r. Yo soy Kolark, un cazador de tesoros de Cima del Trueno. He viajado mucho por el mundo y he visto también mucho.$B$BMis viajes por los Mares del Sur me permitieron descubrir la existencia de estas flechas con cabeza de torio. Tengo un sinfín de ellas, pero ya no tengo balas. Y bueno, ningún tauren que se precie andaría por ahí con un endeble arco. ¡Las flechas no sirven para nada!$B$BTe voy a ofrecer un trato: si me traes proyectiles de torio te las cambio por mis cabezales de flecha de torio. ¿Hecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Soy un tauren de palabra, $r; aquí tienes las flechas.', 0),
(@ID, 'esMX', '¡Excelente! Soy un tauren de palabra, $r; aquí tienes las flechas.', 0);
-- 7342 Las flechas no valen para nada
-- https://es.classic.wowhead.com/quest=7342
SET @ID := 7342;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedes creer esta basura? ¡El último envío de municiones de Kharanos fue un fracaso! ¡Todo lo que tenemos como munición son estas endebles flechas que no sirven para nada! ¿Qué diablos voy a hacer con 500.000 flechas con puntas de torio?$B$BTe diré una cosa, $gchico:chica;. Si puedes traerme proyectiles de torio, te cambio flechas con puntas de torio, ¡Es un buen negocio! ¿Hay trato?', 0),
(@ID, 'esMX', '¿Puedes creer esta basura? ¡El último envío de municiones de Kharanos fue un fracaso! ¡Todo lo que tenemos como munición son estas endebles flechas que no sirven para nada! ¿Qué diablos voy a hacer con 500.000 flechas con puntas de torio?$B$BTe diré una cosa, $gchico:chica;. Si puedes traerme proyectiles de torio, te cambio flechas con puntas de torio, ¡Es un buen negocio! ¿Hay trato?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Un trato hecho si alguna vez vi uno! Las flechas son tuyas.', 0),
(@ID, 'esMX', '¡Un trato hecho si alguna vez vi uno! Las flechas son tuyas.', 0);
-- 7361 Favor entre los Lanza Negra
-- https://es.classic.wowhead.com/quest=7361
SET @ID := 7361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Buscan exterminarnos? Son ellos los que serán exterminados.', 0),
(@ID, 'esMX', '¿Buscan exterminarnos? Son ellos los que serán exterminados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, es solo uno entre miles. No obstante, un trabajo bien hecho.', 0),
(@ID, 'esMX', '$n, es solo uno entre miles. No obstante, un trabajo bien hecho.', 0);
-- 7362 Aliado de los Tauren
-- https://es.classic.wowhead.com/quest=7362
SET @ID := 7362;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me importa de dónde venga el cabello, $r.', 0),
(@ID, 'esMX', 'No me importa de dónde venga el cabello, $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, definitivamente esto es un gnomo. Bien hecho, $r, pero hay más trabajo por hacer.', 0),
(@ID, 'esMX', 'Sí, definitivamente esto es un gnomo. Bien hecho, $r, pero hay más trabajo por hacer.', 0);
-- 7363 La condición humana
-- https://es.classic.wowhead.com/quest=7363
SET @ID := 7363;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si, es cierto. Mi hermano es un humano. Vergonzoso... Una mancha en mi historial casi inmaculado.', 0),
(@ID, 'esMX', 'Si, es cierto. Mi hermano es un humano. Vergonzoso... Una mancha en mi historial casi inmaculado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sería más fácil si aceptaran su enfermedad y se entregaran a tu toque sanador. Probablemente también sería menos divertido. ¡Sigue adelante! Los curaremos, de una forma u otra.', 0),
(@ID, 'esMX', 'Sería más fácil si aceptaran su enfermedad y se entregaran a tu toque sanador. Probablemente también sería menos divertido. ¡Sigue adelante! Los curaremos, de una forma u otra.', 0);
