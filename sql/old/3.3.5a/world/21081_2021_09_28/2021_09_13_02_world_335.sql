-- 10511 Una extraña cerveza
-- https://es.wowhead.com/quest=10511
SET @ID := 10511;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cosa está muy seca por aquí. ¿Cómo voy a disfrutar de mi descanso sin algo que beber?', 0),
(@ID, 'esMX', 'La cosa está muy seca por aquí. ¿Cómo voy a disfrutar de mi descanso sin algo que beber?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es ese olor? ¡¿Oh no, no me digas que es la cerveza de los ogros?!$B$BCasi me da miedo probarla. ¡Bah, da igual, al diablo! ¡De un trago!', 0),
(@ID, 'esMX', '¿Qué es ese olor? ¡¿Oh no, no me digas que es la cerveza de los ogros?!$B$BCasi me da miedo probarla. ¡Bah, da igual, al diablo! ¡De un trago!', 0);
-- 10512 Repostando Aguja del Filo
-- https://es.wowhead.com/quest=10512
SET @ID := 10512;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Ogros Aguja del Filo borrachos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal todo? ¿Los ogros Aguja del Filo son tan poco selectivos como los Machacasangre, o casi les ha matado como me pasó a mí?', 0),
(@ID, 'esMX', '¿Qué tal todo? ¿Los ogros Aguja del Filo son tan poco selectivos como los Machacasangre, o casi les ha matado como me pasó a mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, ja, ja, ja! Justo lo que yo pensaba. Supongo que los ogros se pueden beber cualquier cosa.$B$B¡Qué idiotas son todos!$B$BBueno, debo decir que, aunque no conseguí mi brebaje, me has dado un gran comienzo de vacaciones.$B$BMira... tenemos un montón de cosas aquí que no usamos mucho. ¿Puedo ofrecerte algo?', 0),
(@ID, 'esMX', '¡Ah, ja, ja, ja! Justo lo que yo pensaba. Supongo que los ogros se pueden beber cualquier cosa.$B$B¡Qué idiotas son todos!$B$BBueno, debo decir que, aunque no conseguí mi brebaje, me has dado un gran comienzo de vacaciones.$B$BMira... tenemos un montón de cosas aquí que no usamos mucho. ¿Puedo ofrecerte algo?', 0);
-- 10513 Oronok Corazón Roto
-- https://es.wowhead.com/quest=10513
SET @ID := 10513;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Palabras de condenación? Nunca he oído hablar de ellas. Sigue mi consejo: deja que los muertos descansen.$B$BPero, ya que has venido hasta aquí, me vendría bien algo de ayuda con otros asuntos. ¿Qué me dices?', 0),
(@ID, 'esMX', '¿Palabras de condenación? Nunca he oído hablar de ellas. Sigue mi consejo: deja que los muertos descansen.$B$BPero, ya que has venido hasta aquí, me vendría bien algo de ayuda con otros asuntos. ¿Qué me dices?', 0);
-- 10514 Yo era muchas cosas...
-- https://es.wowhead.com/quest=10514
SET @ID := 10514;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tráeme esos tubérculos!', 0),
(@ID, 'esMX', '¡Tráeme esos tubérculos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que había más despellejadores de los que esperabas? Parece que es hora de sacar la basura.', 0),
(@ID, 'esMX', '¿Dices que había más despellejadores de los que esperabas? Parece que es hora de sacar la basura.', 0);
-- 10515 Una lección aprendida
-- https://es.wowhead.com/quest=10515
SET @ID := 10515;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Huevo de despellejador voraz destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sin piedad!', 0),
(@ID, 'esMX', '¡Sin piedad!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso enseñará a esos malditos animales asquerosos a no matar a mis jabalíes! ¡Bien hecho, $n!', 0),
(@ID, 'esMX', '¡Eso enseñará a esos malditos animales asquerosos a no matar a mis jabalíes! ¡Bien hecho, $n!', 0);
-- 10516 Las armas de un vindicador
-- https://es.wowhead.com/quest=10516
SET @ID := 10516;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿tienes mi espada y mi escudo?$B$BAunque podría marcharme en cualquier momento, sería vergonzoso volver a Sylvanaar sin mis armas.', 0),
(@ID, 'esMX', '$c, ¿tienes mi espada y mi escudo?$B$BAunque podría marcharme en cualquier momento, sería vergonzoso volver a Sylvanaar sin mis armas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy en deuda contigo puesto que has contribuido a recuperar mi honor. Pero aún no hemos acabado nuestro trabajo aquí.', 0),
(@ID, 'esMX', 'Estoy en deuda contigo puesto que has contribuido a recuperar mi honor. Pero aún no hemos acabado nuestro trabajo aquí.', 0);
-- 10517 Gorr'Lelo, ha llegado tu hora...
-- https://es.wowhead.com/quest=10517
SET @ID := 10517;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué fue todo ese ruido? ¿Estabas tratando con Gorr\'Lelo?', 0),
(@ID, 'esMX', '¿Qué fue todo ese ruido? ¿Estabas tratando con Gorr\'Lelo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Eres alguien con recursos, $c, sin duda alguna.$B$BMe pregunto si no habrá alguna otra cosa que pudieras hacer por mí y Sylvanaar...', 0),
(@ID, 'esMX', 'Muy bien. Eres alguien con recursos, $c, sin duda alguna.$B$BMe pregunto si no habrá alguna otra cosa que pudieras hacer por mí y Sylvanaar...', 0);
-- 10518 Clavar el estandarte
-- https://es.wowhead.com/quest=10518
SET @ID := 10518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae hasta aquí? ¿No irás a decirme que el clan ogro Machacasangre vuelve a dar problemas?', 0),
(@ID, 'esMX', '¿Qué te trae hasta aquí? ¿No irás a decirme que el clan ogro Machacasangre vuelve a dar problemas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El yelmo de Gurn Jalazampa y el estandarte Aguja del Filo?$B$BAstuta esa idea tuya y de la vindicadora de urdir ese plan.$B$BAl atraer la atención del clan Machacasangre sobre el Bastión Aguja del Filo, has aliviado la presión que empezaban a ejercer sobre nosotros aquí.$B$BTe lo ruego, $n, acepta un humilde regalo de Sylvanaar.', 0),
(@ID, 'esMX', '¿El yelmo de Gurn Jalazampa y el estandarte Aguja del Filo?$B$BAstuta esa idea tuya y de la vindicadora de urdir ese plan.$B$BAl atraer la atención del clan Machacasangre sobre el Bastión Aguja del Filo, has aliviado la presión que empezaban a ejercer sobre nosotros aquí.$B$BTe lo ruego, $n, acepta un humilde regalo de Sylvanaar.', 0);
-- 10519 La Clave de Condenación: historia y verdad
-- https://es.wowhead.com/quest=10519
SET @ID := 10519;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten paciencia y escucha, $N.', 0),
(@ID, 'esMX', 'Ten paciencia y escucha, $N.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entiendes lo que se debe hacer? Encuentra a los hijos de Oronok. Encuentra a mis chicos...', 0),
(@ID, 'esMX', '¿Entiendes lo que se debe hacer? Encuentra a los hijos de Oronok. Encuentra a mis chicos...', 0);
-- 10521 Grom'tor, hijo de Oronok
-- https://es.wowhead.com/quest=10521
SET @ID := 10521;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Grom\'tor emite un gruñido.>$B$BMe alegro de que hayas venido. Este gusano acaba de derramar las tripas. ¡Ahora son nuestros!', 0),
(@ID, 'esMX', '<Grom\'tor emite un gruñido.>$B$BMe alegro de que hayas venido. Este gusano acaba de derramar las tripas. ¡Ahora son nuestros!', 0);
-- 10522 La Clave de Condenación: La carga de Grom'tor
-- https://es.wowhead.com/quest=10522
SET @ID := 10522;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha habido suerte?', 0),
(@ID, 'esMX', '¿Ha habido suerte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay que llevarle esto a mi padre sin demora.', 0),
(@ID, 'esMX', 'Hay que llevarle esto a mi padre sin demora.', 0);
-- 10523 La Clave de Condenación - Primer trozo recuperado
-- https://es.wowhead.com/quest=10523
SET @ID := 10523;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido éxito?', 0),
(@ID, 'esMX', '¿Has tenido éxito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando la Clave de Condenación sea reformada, ¡podremos poner fin a esta maldición!', 0),
(@ID, 'esMX', 'Cuando la Clave de Condenación sea reformada, ¡podremos poner fin a esta maldición!', 0);
-- 10524 Artefactos del clan Señor del Trueno
-- https://es.wowhead.com/quest=10524
SET @ID := 10524;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Nos conocemos?', 0),
(@ID, 'esMX', '¿Nos conocemos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No me creo lo que ven mis ojos! ¡Si es algún tipo de truco, te arrancaré la carne de los huesos, $c!$B$BRápido, déjame examinar estos artefactos de valor incalculable antes de que las rompas con tus torpes manos.', 0),
(@ID, 'esMX', '¡No me creo lo que ven mis ojos! ¡Si es algún tipo de truco, te arrancaré la carne de los huesos, $c!$B$BRápido, déjame examinar estos artefactos de valor incalculable antes de que las rompas con tus torpes manos.', 0);
-- 10525 Visión guía
-- https://es.wowhead.com/quest=10525
SET @ID := 10525;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has visto? ¡Dime, debo saber dónde está!', 0),
(@ID, 'esMX', '¿Qué has visto? ¡Dime, debo saber dónde está!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El fondo de la Mina Draenetista? El clan Machacasangre debe de haberla robado de los ogros Aguja del Filo.$B$B¡Bah! Está demasiado lejos... demasiado inmerso en las profundidades del territorio Machacasangre para que vaya hasta allí.$B$BPero tú... Tú conoces el camino. ¡Irás allí en mi lugar!', 0),
(@ID, 'esMX', '¿El fondo de la Mina Draenetista? El clan Machacasangre debe de haberla robado de los ogros Aguja del Filo.$B$B¡Bah! Está demasiado lejos... demasiado inmerso en las profundidades del territorio Machacasangre para que vaya hasta allí.$B$BPero tú... Tú conoces el camino. ¡Irás allí en mi lugar!', 0);
-- 10526 La Punta de Trueno
-- https://es.wowhead.com/quest=10526
SET @ID := 10526;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La importancia de estos artefactos se te escapa, no me cabe duda.$B$BCuando tengamos los cinco, nuestro derecho a la posesión del Bastión Señor del Trueno se verá asegurado a través del aplacamiento de sus espíritus muertos.$B$B¿Comienzas a comprender por qué es tan importante esto? ¿Entiendes por qué tenemos poca paciencia para finuras?', 0),
(@ID, 'esMX', 'La importancia de estos artefactos se te escapa, no me cabe duda.$B$BCuando tengamos los cinco, nuestro derecho a la posesión del Bastión Señor del Trueno se verá asegurado a través del aplacamiento de sus espíritus muertos.$B$B¿Comienzas a comprender por qué es tan importante esto? ¿Entiendes por qué tenemos poca paciencia para finuras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bueno, me impresionas! ¿Tienes idea de cuántos otros murieron intenta recuperar todas esas reliquias?$B$BTenemos suerte de tenerte trabajando con nosotros, $n. Aunque seas algo $glento:lenta;.$B$BDebes permitirme recompensar tu dedicación a nuestra causa. Elige, pero hazlo sabiamente. Cuando hayas terminado, entregaré los artefactos para apaciguar a los fantasmas del Bastión Señor del Trueno.', 0),
(@ID, 'esMX', '¡Bueno, me impresionas! ¿Tienes idea de cuántos otros murieron intenta recuperar todas esas reliquias?$B$BTenemos suerte de tenerte trabajando con nosotros, $n. Aunque seas algo $glento:lenta;.$B$BDebes permitirme recompensar tu dedicación a nuestra causa. Elige, pero hazlo sabiamente. Cuando hayas terminado, entregaré los artefactos para apaciguar a los fantasmas del Bastión Señor del Trueno.', 0);
-- 10527 Ar'tor, hijo de Oronok
-- https://es.wowhead.com/quest=10527
SET @ID := 10527;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cuerpo de Ar\'tor cuelga flácido, suspendido en el aire. No tienes ni idea de cuánto tiempo lleva muerto, pero sientes una punzada en el corazón por Oronok.$B$BQuizás deberías intentar bajar el cadáver y devolvérselo a su padre.', 0),
(@ID, 'esMX', 'El cuerpo de Ar\'tor cuelga flácido, suspendido en el aire. No tienes ni idea de cuánto tiempo lleva muerto, pero sientes una punzada en el corazón por Oronok.$B$BQuizás deberías intentar bajar el cadáver y devolvérselo a su padre.', 0);
-- 10528 Cárceles de cristal demoníacas
-- https://es.wowhead.com/quest=10528
SET @ID := 10528;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ar\'tor yace inerte ante ti.', 0),
(@ID, 'esMX', 'Ar\'tor yace inerte ante ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Introduces la llave cristalina en las ranuras de la base de cada cristal demoníaco.', 0),
(@ID, 'esMX', 'Introduces la llave cristalina en las ranuras de la base de cada cristal demoníaco.', 0);
-- El camino del cazador
-- 10529, 10530
-- https://es.wowhead.com/quest=10529
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10529, 10530) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10529, 'esES', '$N, es bueno que hayas venido. Nuestra lista de aliados es cada vez menor, e incluso aquellos que comparten nuestra causa no son completamente confiables. Es por esto que nosotros, los forestales, recurrimos a la naturaleza en busca de ayuda.$B$BEn los aliados del bosque encontramos un lazo profundo que no conoce el engaño.', 0),
(10530, 'esES', '$N, es bueno que hayas venido. Nuestra lista de aliados es cada vez menor, e incluso aquellos que comparten nuestra causa no son completamente confiables. Es por esto que nosotros, los forestales, recurrimos a la naturaleza en busca de ayuda.$B$BEn los aliados del bosque encontramos un lazo profundo que no conoce el engaño.', 0),
(10529, 'esMX', '$N, es bueno que hayas venido. Nuestra lista de aliados es cada vez menor, e incluso aquellos que comparten nuestra causa no son completamente confiables. Es por esto que nosotros, los forestales, recurrimos a la naturaleza en busca de ayuda.$B$BEn los aliados del bosque encontramos un lazo profundo que no conoce el engaño.', 0),
(10530, 'esMX', '$N, es bueno que hayas venido. Nuestra lista de aliados es cada vez menor, e incluso aquellos que comparten nuestra causa no son completamente confiables. Es por esto que nosotros, los forestales, recurrimos a la naturaleza en busca de ayuda.$B$BEn los aliados del bosque encontramos un lazo profundo que no conoce el engaño.', 0);
-- 10537 Lohn'goron, arco del corazón roto
-- https://es.wowhead.com/quest=10537
SET @ID := 10537;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No temas, $ghéroe:heroína;. Cuando llegue la hora, te ayudaré...', 0),
(@ID, 'esMX', 'No temas, $ghéroe:heroína;. Cuando llegue la hora, te ayudaré...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Significa "estancia del héroe" en mi lengua nativa. Incluso ahora sigue siendo cierto, en estos tiempos cuando todos nuestros héroes han fallecido...', 0),
(@ID, 'esMX', 'Significa "estancia del héroe" en mi lengua nativa. Incluso ahora sigue siendo cierto, en estos tiempos cuando todos nuestros héroes han fallecido...', 0);
-- 10538 Sangre en ebullición
-- https://es.wowhead.com/quest=10538
SET @ID := 10538;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la sangre hervida, $n? Qué ganas tengo de estudiarla sin interrupciones esta vez...', 0),
(@ID, 'esMX', '¿Tienes la sangre hervida, $n? Qué ganas tengo de estudiarla sin interrupciones esta vez...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Ahora podré realizar mis pruebas con más facilidad...$B$BGracias, $n. Tienes mucho talento.', 0),
(@ID, 'esMX', 'Muy bien. Ahora podré realizar mis pruebas con más facilidad...$B$BGracias, $n. Tienes mucho talento.', 0);
-- 10540 La Clave de Condenación. La carga de Ar'tor
-- https://es.wowhead.com/quest=10540
SET @ID := 10540;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hay que recuperar la clave!', 0),
(@ID, 'esMX', '¡Hay que recuperar la clave!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ar\'tor entra y sale del plano de existencia.>$B$BParece que mi tiempo está llegando a su fin.', 0),
(@ID, 'esMX', '<Ar\'tor entra y sale del plano de existencia.>$B$BParece que mi tiempo está llegando a su fin.', 0);
-- 10541 La Clave de Condenación. Segundo trozo recuperado
-- https://es.wowhead.com/quest=10541
SET @ID := 10541;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Una única lágrima rueda por la mejilla de Oronok.>', 0),
(@ID, 'esMX', '<Una única lágrima rueda por la mejilla de Oronok.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Oronok se limpia la lágrima y te sonríe.>$B$BGracias. Te prometo, $ghéroe:heroína;, que se escribirá una canción de honor en tu nombre.', 0),
(@ID, 'esMX', '<Oronok se limpia la lágrima y te sonríe.>$B$BGracias. Te prometo, $ghéroe:heroína;, que se escribirá una canción de honor en tu nombre.', 0);
