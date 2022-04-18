-- 72 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=72
SET @ID := 72;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Levantas lentamente la tapa de la caja...', 0);
-- 74 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=74
SET @ID := 74;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué tienes ahí? No lo veo. Tengo una vista muy mala. Pónmelo en las manos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Apenas distingo las letras. Pero la caligrafía me recuerda a algo que vi una vez, cuando aún tenía buena vista.', 0);
-- 387 Detener el motín
-- https://es.classic.wowhead.com/quest=387
SET @ID := 387;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡La empalizada todavía está invadida! Estas ratas Defias deben saber que sus acciones no serán toleradas. ¡Ahora baja y muestra algo de fuerza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tus acciones en las Mazmorras fueron muy valientes, $n. Es obvio que este problema nos sobrepasa. Pero lo has hecho muy bien y, por ello, te doy las gracias.', 0);
-- 75 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=75
SET @ID := 75;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado la página de la que te hablé, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡La has encontrado!', 0);
-- 78 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=78
SET @ID := 78;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te envía el mariscal Haggard? ¿Y por qué no lo has dicho antes?$B$BAy, el viejo Haggard... El pobre se quedará ciego dentro de poco. En fin, déjame ver lo que tienes ahí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Por la Luz! Claro que reconozco esa caligrafía.', 0);
-- 265 La búsqueda de la figura continúa
-- https://es.classic.wowhead.com/quest=265
SET @ID := 265;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'A veces vendo libros en blanco a estudiosos y magos, o a cualquiera que quiera escribir un diario.$B$BRecuerdo perfectamente a todos los que me compraron libros en los últimos meses...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, sí. Vendí este libro hace un mes a una persona... algo sombría. No me dio su nombre, pero era un tipo nervioso que no paraba de mirar por encima de su hombro.', 0);
-- 156 Busca flores podridas
-- https://es.classic.wowhead.com/quest=156
SET @ID := 156;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola, $n. ¿Me has conseguido ya esas flores podridas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien, tienes las flores podridas. Y le diré a Althea Ebonlocke de La Guardia Nocturna que has estado matando esqueletos.$B$BSalvaguardar a las gentes de Villa Oscura es un tremendo peso para La Guardia Nocturna... siempre se alegran de saber que hay otros que ayudan a contener a esas bestias del Bosque del Ocaso.', 0);
-- 159 Entrega de zumo
-- https://es.classic.wowhead.com/quest=159
SET @ID := 159;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito ese zumo de zombi para mantenerme caliente en estas noches frías y oscuras. ¿Me lo conseguiste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Miles de gracias, $n. Has dado una alegría al corazón de este pobre viejo con este gesto estúpid... digo, ¡con este gesto estupendo!', 0);
-- 79 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=79
SET @ID := 79;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Espero que sea importante, $c. Déjame ver lo que traes y cuéntame tu historia. Pero, por la Luz, date prisa. La defensa de Villa Oscura es mi prioridad. No tengo tiempo para tonterías.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Vaya, desde luego, tienes madera de detective, $c.', 0);
-- 80 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=80
SET @ID := 80;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tú otra vez, $n? ¿Qué te trae aquí de nuevo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Pues sí! La caligrafía de esta página coincide con las firmas del registro.', 0);
-- 266 Búsqueda en la posada
-- https://es.classic.wowhead.com/quest=266
SET @ID := 266;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El Cuervo Escarlata ya no es lo que solía ser pero aún pasan por aquí algunos viajeros.$B$BDescribirme al tipo al que buscas, quizás lo recuerde.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, sí, recuerdo este libro. Su dueño alquiló una habitación por unos días. Se pasaba las noches en el bar, escribiendo.$B$BDejó el pueblo a toda prisa, murmurando algo de que le perseguían... La última vez que lo vi se dirigía hacia el oeste... buscaba un nuevo lugar en el que esconderse.$B$BEl primer lugar al que llegaría yendo hacia el oeste sería Cerro del Cuervo...', 0);
-- 97 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=97
SET @ID := 97;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sí, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Lo sabía! ¡Buen trabajo, $n!', 0);
-- 98 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=98
SET @ID := 98;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Lo sé, $n: Stalvan está muerto. Percibí una oleada de esperanza que atravesaba el bosque contaminado. El Bosque del Ocaso está libre, por fin, de su sed de sangre. Aunque mi alegría se ensombrece cuando pienso en aquellos que cayeron a manos de esa horrible bestia. En cualquier caso, has sido valiente y astuto, $c.', 0);
-- 453 Encuentra la figura misteriosa
-- https://es.classic.wowhead.com/quest=453
SET @ID := 453;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo estás? ¡Déjame!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Alterio suspira...>$B$BSí, soy el autor de ese libro. Por fin me has encontrado, ¿eh?$B$BSi has leído ese diario... ¡solo sabes la mitad de la historia!', 0);
-- 133 Un espantapájaros para necrófagos
-- https://es.classic.wowhead.com/quest=133
SET @ID := 133;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Creo que estoy oyendo a una panda de necrófagos en la parte trasera de la casa... ¡tengo que colocar ese espantapájaros ya! ¿Me conseguiste las costillas de necrófago?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, gracias. ¡Son justo lo que necesito!', 0);
-- 134 Ladrones ogros
-- https://es.classic.wowhead.com/quest=134
SET @ID := 134;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes mi cajón? Si lo tienes, ¡dámelo! ¡Rápido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias al Nec... no, no, ¡gracias a TI, $n! Te has ganado tu recompensa.$B$B¡Aah! ¡Qué felicidad! ¡¡Qué noches me esperan!!', 0);
-- 160 Nota para el alcalde
-- https://es.classic.wowhead.com/quest=160
SET @ID := 160;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Abercrombie...? No conozco a nadie con ese nombre. ¿Dices que tienes una carta para mí de ese tal Abercrombie?$B$BBueno, pues dámela...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Ello mira la carta...>$B$B¿Qué idioma es este? Parece antiguo... No puedo leerlo.', 0);
-- 268 Entrega para Sven
-- https://es.classic.wowhead.com/quest=268
SET @ID := 268;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has averiguado quién era la figura misteriosa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Este diario me explica muchas cosas ¡y me indica el camino para enfrentarme a los jinetes oscuros! He visto a esos jinetes en Bosque del Ocaso, y les he visto hablando con el zahorí Morbent Vil, en la Loma Inhóspita.', 0);
-- 323 Pon a prueba tu valor
-- https://es.classic.wowhead.com/quest=323
SET @ID := 323;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Lucha duro, $N. Y no te desesperes, porque la desesperación es el arma más grande del mal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tu habilidad en combate, $n, es indiscutible. ¡Y tu resolución podría ayudarnos a presenciar el final de Morbent Vil!', 0);
-- 269 En busca de sabiduría
-- https://es.classic.wowhead.com/quest=269
SET @ID := 269;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Descansa, $ghermano:hermana;. Se ve que has viajado lejos y que llevas un peso enorme. ¿Puedes decirme qué es lo que proyecta sobre ti esa sombra tan oscura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Después de leer el diario y de oír tu intención...>$B$BUna malvada mácula se ha hecho con el ya asediado Bosque del Ocaso. Doy gracias a la Luz porque ahora tenemos a un héroe como tú para hacerle frente.$B$BPero primero debes prepararte para la prueba que te espera, pues el poder del Necromántico Morbent Vil es inconmensurable y además, ha lanzado sobre sí mismo oscuros encantamientos que lo protegen de ataques físicos. Si quieres derrotarle, necesitarás un arma que pueda contrarrestar estas protecciones.', 0);
-- 251 Traduce la nota de Abercrombie
-- https://es.classic.wowhead.com/quest=251
SET @ID := 251;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Una nota de Abercrombie el ermitaño, ¿eh? Pues no sé quién es... Pero desde luego, si vive en el cementerio, ¡debe de tener el cerebro podrido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Sirra empieza a traducir la nota...>', 0);
-- 401 Espera a que Sirra acabe
-- https://es.classic.wowhead.com/quest=401
SET @ID := 401;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ya está. Está traducida...$B$B<El aire es cada vez más pesado, como si una espesa y negra cortina se estuviera cerrando sobre el mundo...>', 0);
-- 252 Una traducción para Ello
-- https://es.classic.wowhead.com/quest=252
SET @ID := 252;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ¿la nota está traducida? Déjame verla, por favor...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Ello lee la carta... y palidece. Luego te mira a ti...>$B$BAunque cuando ayudaste a Abercrombie lo hiciste motivado por tu bondad, con tus acciones has condenado a nuestro pueblo.$B$B<Ello se pierde en sus pensamientos...>', 0);
-- 253 La novia del embalsamador
-- https://es.classic.wowhead.com/quest=253
SET @ID := 253;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has encontrado la tumba de Eliza? ¿Tienes el corazón del embalsamador?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Lo has conseguido! La magia que contiene su corazón nos protegerá contra el mal del embalsamador y será un poderoso auspicio para Villa Oscura.$B$BHas hecho una gran cosa para nuestra gente, $n. Tu nombre permanecerá para siempre en nuestros anales.', 0);
