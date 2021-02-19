-- 922 Rellian Verdeguja
-- https://es.classic.wowhead.com/quest=922
SET @ID := 922;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola...$B$B¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', 'Hola...$B$B¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, una semilla de Brezomadera! Quería cultivar una de estas semillas para ayudar a Denalan en sus investigaciones...$B$BHasta que descubrí que muchos de los Brezomadera están corruptos y, por lo tanto, también sus semillas. Yo no puedo hacer nada para curarlos.$B$BDenalan tiene mucha mano para las plantas y puede que encuentre una curación para los futuros Brezomadera. Puede que él sea su única esperanza.', 0),
(@ID, 'esMX', '¡Ah, una semilla de Brezomadera! Quería cultivar una de estas semillas para ayudar a Denalan en sus investigaciones...$B$BHasta que descubrí que muchos de los Brezomadera están corruptos y, por lo tanto, también sus semillas. Yo no puedo hacer nada para curarlos.$B$BDenalan tiene mucha mano para las plantas y puede que encuentre una curación para los futuros Brezomadera. Puede que él sea su única esperanza.', 0);
-- 2541 El druida durmiente
-- https://es.classic.wowhead.com/quest=2541
SET @ID := 2541;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si pudiera examinar el talismán, podría descubrir cómo romper el encantamiento. ¿Has encontrado alguno?', 0),
(@ID, 'esMX', 'Si pudiera examinar el talismán, podría descubrir cómo romper el encantamiento. ¿Has encontrado alguno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BQué objeto más extraño... Puedo sentir el aura de maldad que emana de él. Se trata de un potente encantamiento.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BQué objeto más extraño... Puedo sentir el aura de maldad que emana de él. Se trata de un potente encantamiento.', 0);
-- 2561 El druida de la Zarpa
-- https://es.classic.wowhead.com/quest=2561
SET @ID := 2561;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ten cuidado al acercarte a mi representación física; el encantamiento al que está sometida es muy poderoso.', 0),
(@ID, 'esMX', '$n, ten cuidado al acercarte a mi representación física; el encantamiento al que está sometida es muy poderoso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al fin estoy libre del control de los Tuercepinos. Gracias, $n.$B$BAhora mi espíritu podrá descansar en paz para siempre en el Sueño Esmeralda.$B$BQuizás nos volvamos a encontrar algún día, joven $c. De momento, acepta esta recompensa como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Al fin estoy libre del control de los Tuercepinos. Gracias, $n.$B$BAhora mi espíritu podrá descansar en paz para siempre en el Sueño Esmeralda.$B$BQuizás nos volvamos a encontrar algún día, joven $c. De momento, acepta esta recompensa como muestra de mi gratitud.', 0);
-- 930 El fruto resplandeciente
-- https://es.classic.wowhead.com/quest=930
SET @ID := 930;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, parece que tienes algo que contarme. ¿Sabes algo nuevo de los Brezomadera?', 0),
(@ID, 'esMX', '$n, parece que tienes algo que contarme. ¿Sabes algo nuevo de los Brezomadera?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y esto lo encontraste en Teldrassil? Fascinante... Se trata de un fruto exótico. Quizás sus semillas fueran traídas hasta aquí desde un lugar muy lejano. ¡Incluso tan lejano como Azeroth! Hay algo en este fruto... parece que ha reaccionado de modo extraño tras entrar en contacto con la tierra de Teldrassil.$B$BGracias, $n. Ahora, si me disculpas, voy a analizarlo en detalle...', 0),
(@ID, 'esMX', '¿Y esto lo encontraste en Teldrassil? Fascinante... Se trata de un fruto exótico. Quizás sus semillas fueran traídas hasta aquí desde un lugar muy lejano. ¡Incluso tan lejano como Azeroth! Hay algo en este fruto... parece que ha reaccionado de modo extraño tras entrar en contacto con la tierra de Teldrassil.$B$BGracias, $n. Ahora, si me disculpas, voy a analizarlo en detalle...', 0);
-- 486 Ursal el Violento
-- https://es.classic.wowhead.com/quest=486
SET @ID := 486;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros hermanos no pueden ser despertados hasta que Ursal el Violento haya sido asesinado, $n.', 0),
(@ID, 'esMX', 'Nuestros hermanos no pueden ser despertados hasta que Ursal el Violento haya sido asesinado, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, has demostrado ser $gun:una; $c de gran talento y valentía. $gUn:Una; $r que sigue el camino del honor del modo en que tú lo haces, sin duda alcanzará la gloria en este mundo.', 0),
(@ID, 'esMX', '$n, has demostrado ser $gun:una; $c de gran talento y valentía. $gUn:Una; $r que sigue el camino del honor del modo en que tú lo haces, sin duda alcanzará la gloria en este mundo.', 0);
-- 952 El Páramo de los Ancianos
-- https://es.classic.wowhead.com/quest=952
SET @ID := 952;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! $c, ¿en qué puede ayudarte Onus?', 0),
(@ID, 'esMX', '¡Ah! $c, ¿en qué puede ayudarte Onus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Gracias, $n, aunque es extraño pues parece que el Archidruida siempre es víctima de la presura. El bosque sabe que cada cosa ha de pasar a su debido tiempo y eso Shan\'do Tempestira lo respetaba.', 0),
(@ID, 'esMX', '¡Ah! Gracias, $n, aunque es extraño pues parece que el Archidruida siempre es víctima de la presura. El bosque sabe que cada cosa ha de pasar a su debido tiempo y eso Shan\'do Tempestira lo respetaba.', 0);
-- 3764 Tierra de Un'Goro
-- https://es.classic.wowhead.com/quest=3764
SET @ID := 3764;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, la tierra. El archidruida quiere 20 cargas por aventurero. Y 20 tendrá. ¡Que aquellos que conspiran contra nosotros se pierdan en el camino!', 0),
(@ID, 'esMX', 'Ah, sí, la tierra. El archidruida quiere 20 cargas por aventurero. Y 20 tendrá. ¡Que aquellos que conspiran contra nosotros se pierdan en el camino!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aligera aquí tu preciosa carga, noble $c. Ha debido de ser un gran peso... como el que llevo yo por ser un visionario. Aquí tienes un honorario por tu trabajo, tal y como dictó el propio archidruida.$B$BEl archidruida Corzocelada quiere hablar contigo de nuevo, $n. Pero para la siguiente tarea que te encomiende necesitarás tener los conocimientos de botánica de un oficial. Aunque, si no los tienes, también podrás ayudar al Círculo.', 0),
(@ID, 'esMX', 'Aligera aquí tu preciosa carga, noble $c. Ha debido de ser un gran peso... como el que llevo yo por ser un visionario. Aquí tienes un honorario por tu trabajo, tal y como dictó el propio archidruida.$B$BEl archidruida Corzocelada quiere hablar contigo de nuevo, $n. Pero para la siguiente tarea que te encomiende necesitarás tener los conocimientos de botánica de un oficial. Aunque, si no los tienes, también podrás ayudar al Círculo.', 0);
-- 2520 El Sacrificio de Sathrah
-- https://es.classic.wowhead.com/quest=2520
SET @ID := 2520;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has puesto el sacrificio en la fuente, $n?', 0),
(@ID, 'esMX', '¿Has puesto el sacrificio en la fuente, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La pérdida de Lady Sathrah es angustiante pero puede que sea el único modo de que vuelva a nacer con un espíritu renovado.$B$BEsperemos que Elune acepte de buen grado el sacrificio que le has ofrecido.', 0),
(@ID, 'esMX', 'La pérdida de Lady Sathrah es angustiante pero puede que sea el único modo de que vuelva a nacer con un espíritu renovado.$B$BEsperemos que Elune acepte de buen grado el sacrificio que le has ofrecido.', 0);
-- 1199 Cascada Crepuscular
-- https://es.classic.wowhead.com/quest=1199
SET @ID := 1199;
DELETE FROM `quest_request_items_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las Caverna de Brazanegra fueron una vez un antiguo templo de los elfos de la noche. Una vez albergó la poza de la luna más poderosa. Quién sabe qué maldad se está gestando ahora a manos del Martillo Crepuscular.$B$B¿Ha hecho algún progreso para deshacerse de su presencia?', 0),
(@ID, 'esMX', 'Las Caverna de Brazanegra fueron una vez un antiguo templo de los elfos de la noche. Una vez albergó la poza de la luna más poderosa. Quién sabe qué maldad se está gestando ahora a manos del Martillo Crepuscular.$B$B¿Ha hecho algún progreso para deshacerse de su presencia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin duda eres de sangre noble y valiente, $n. El Alba Argenta te felicita por tus esfuerzos contra el mal.', 0),
(@ID, 'esMX', 'Sin duda eres de sangre noble y valiente, $n. El Alba Argenta te felicita por tus esfuerzos contra el mal.', 0);
-- 1198 Buscando a Thaelrid
-- https://es.classic.wowhead.com/quest=1198
SET @ID := 1198;
DELETE FROM `quest_offer_reward_locale` WHERE `id`= @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Shaedlass Guardalbas ha sido muy considerado al enviarte. Sin duda en este corrupto lugar se está tramando un oscuro complot.', 0),
(@ID, 'esMX', 'Shaedlass Guardalbas ha sido muy considerado al enviarte. Sin duda en este corrupto lugar se está tramando un oscuro complot.', 0);
-- 7795, 7800, 7805, 7811, 7818, 7823, 7824, 7836, 10357, 10362 Un donativo de paño rúnico
-- https://es.classic.wowhead.com/quest=7795
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7795, 7800, 7805, 7811, 7818, 7823, 7824, 7836, 10357, 10362) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7795, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7800, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7805, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7811, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7818, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7823, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7824, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7836, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10357, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10362, 'esES', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7795, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7800, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7805, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7811, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7818, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7823, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7824, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(7836, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10357, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0),
(10362, 'esMX', '$n, has contribuido enormemente a nuestra campaña de telas. Mientras trabajamos duro para reponer nuestras reservas, pero las reservas de tela rúnica están críticamente bajas. ¡Lo necesitamos con urgencia y esperamos que puedas ayudarnos como lo ha hecho en el pasado!$B$BSi estás $gdispuesto:dispuesta;, tráeme el paño rúnico que puedas. Inicialmente aceptaremos una sola donación de sesenta y luego partiremos de ahí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7795, 7800, 7805, 7811, 7818, 7823, 7824, 7836, 10357, 10362) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7795, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7800, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7805, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7811, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7818, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7823, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7824, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7836, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10357, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10362, 'esES', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7795, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7800, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7805, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7811, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7818, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7823, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7824, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(7836, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10357, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0),
(10362, 'esMX', '¡Fantástico! Se usarán bien, te lo aseguro. ¡Gracias nuevamente por tu ayuda! Ciertamente estaríamos perdidos sin ti.$B$BCon todas las donaciones que has hecho, aceptaría cualquier donación adicional de tela rúnica que quieras hacer en el futuro. ¡Solo asegúrate de venir a verme y yo personalmente me aseguraré de que tus buenas obras no queden sin reconocimiento!', 0);
-- 7794, 7799, 7804, 7809, 7817, 7822, 7831, 7835, 10356, 10361 Un donativo de tejido mágico
-- https://es.classic.wowhead.com/quest=7794
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7794, 7799, 7804, 7809, 7817, 7822, 7831, 7835, 10356, 10361) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7794, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7799, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7804, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7809, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7817, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7822, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7831, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7835, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10356, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10361, 'esES', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),

(7794, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7799, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7804, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7809, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7817, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7822, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7831, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(7835, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10356, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0),
(10361, 'esMX', 'Si tienes las sesenta piezas de tela mágica encima y estás $glisto:lista; para donarlas, puedes hacerlo ahora.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7794, 7799, 7804, 7809, 7817, 7822, 7831, 7835, 10356, 10361) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7794, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7799, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7804, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7809, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7817, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7822, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7831, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7835, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10356, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10361, 'esES', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7794, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7799, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7804, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7809, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7817, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7822, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7831, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(7835, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10356, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0),
(10361, 'esMX', '¡Maravilloso! ¡Te agradecemos tu generosa donación, $n!', 0);
-- 7796, 7801, 7806, 7812, 7819, 7825, 7832, 7837, 10358, 10363 Un donativo extra de paño rúnico
-- https://es.classic.wowhead.com/quest=7801
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7796, 7801, 7806, 7812, 7819, 7825, 7832, 7837, 10358, 10363) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7796, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7801, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7806, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7812, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7819, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7825, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7832, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7837, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10358, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10363, 'esES', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7796, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7801, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7806, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7812, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7819, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7825, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7832, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(7837, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10358, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0),
(10363, 'esMX', 'Saludos, una vez más, $n. Seguimos necesitando paño rúnico y aceptamos cualquier donativo, si es que deseas colaborar. Si me traes un nuevo donativo de 20 retales de paño rúnico, me aseguraré de que se reconozcan tus esfuerzos.$B$BCuando desees entregarme el donativo de paño rúnico, lo aceptaré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7796, 7801, 7806, 7812, 7819, 7825, 7832, 7837, 10358, 10363) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7796, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7801, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7806, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7812, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7819, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7825, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7832, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7837, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10358, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10363, 'esES', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7796, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7801, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7806, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7812, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7819, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7825, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7832, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(7837, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10358, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0),
(10363, 'esMX', '$n, sin $ghéroes:heroínas; como tú trabajando por la causa, sufriríamos mucho. ¡Gracias por tus continuos esfuerzos!', 0);
