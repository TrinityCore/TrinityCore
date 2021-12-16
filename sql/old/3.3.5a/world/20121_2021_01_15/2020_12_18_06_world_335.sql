-- 590 Un trato de pícaro
-- https://es.classic.wowhead.com/quest=590
SET @ID := 590;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¡Qué habilidad!$B$BPensaba que serías una presa fácil, $n, pero me has dado una buena tunda.$B$BAquí tienes tu dinero... No es tanto como te dije, pero eso es porque te mentí desde el principio.', 0),
(@ID, 'esMX', '¡Increíble! ¡Qué habilidad!$B$BPensaba que serías una presa fácil, $n, pero me has dado una buena tunda.$B$BAquí tienes tu dinero... No es tanto como te dije, pero eso es porque te mentí desde el principio.', 0);
-- 591 El Ojo de la mente
-- https://es.classic.wowhead.com/quest=591
SET @ID := 591;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $N. Los espíritus alaban tu valentía, pero no me cuentan historias de tu búsqueda contra Mai\'Zoth.$B$B¿Tienes el ojo?', 0),
(@ID, 'esMX', 'Saludos, $N. Los espíritus alaban tu valentía, pero no me cuentan historias de tu búsqueda contra Mai\'Zoth.$B$B¿Tienes el ojo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Recuperaste el ojo! ¡Tu poder es materia de leyendas, $n!$B$BY para conseguir el Ojo, debes haber derrotado a Mai\'Zoth y enviarlo al Nether. Por eso los espíritus no lo mencionarían antes.$B$BEs bueno que se haya ido del mundo de carne y hueso, pero ahora que está en el reino de los espíritus... me temo que comenzará un nuevo reinado.$B$BPero eso es una preocupación para otro momento. Ahora, debo realizar un ritual para adaptar el Ojo de la Mente a nuestras necesidades...', 0),
(@ID, 'esMX', '¡Recuperaste el ojo! ¡Tu poder es materia de leyendas, $n!$B$BY para conseguir el Ojo, debes haber derrotado a Mai\'Zoth y enviarlo al Nether. Por eso los espíritus no lo mencionarían antes.$B$BEs bueno que se haya ido del mundo de carne y hueso, pero ahora que está en el reino de los espíritus... me temo que comenzará un nuevo reinado.$B$BPero eso es una preocupación para otro momento. Ahora, debo realizar un ritual para adaptar el Ojo de la Mente a nuestras necesidades...', 0);
-- 592 Salvar a Yenniku
-- https://es.classic.wowhead.com/quest=592
SET @ID := 592;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Kin\'weelay me dijo que te propuso capturar a Yenniku.$B$B¿Es verdad? ¿Lo tienes?', 0),
(@ID, 'esMX', '$n. Kin\'weelay me dijo que te propuso capturar a Yenniku.$B$B¿Es verdad? ¿Lo tienes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has hecho! Liberaste a Yenniku de la voluntad de Zanzil y completaste la misión que pensaba que era tan desesperada.$B$BNuestra tribu recordará tu nombre en canciones, $n, y grabaremos tu historia en piedra para que viva para siempre.', 0),
(@ID, 'esMX', '¡Lo has hecho! Liberaste a Yenniku de la voluntad de Zanzil y completaste la misión que pensaba que era tan desesperada.$B$BNuestra tribu recordará tu nombre en canciones, $n, y grabaremos tu historia en piedra para que viva para siempre.', 0);
-- 594 Mensaje en una botella
-- https://es.classic.wowhead.com/quest=594
SET @ID := 594;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido a liberarme?', 0),
(@ID, 'esMX', '¿Has venido a liberarme?', 0);
-- 595 Bucaneros Velasangre
-- https://es.classic.wowhead.com/quest=595
SET @ID := 595;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encima del barril descubres un mapa que tiene escrito algo de forma apresurada y unas monedas.', 0),
(@ID, 'esMX', 'Encima del barril descubres un mapa que tiene escrito algo de forma apresurada y unas monedas.', 0);
-- 596 Collares de huesos sangrientos
-- https://es.classic.wowhead.com/quest=596
SET @ID := 596;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Algún día, los Lanza Negra aplastarán a los Sangrapellejo! ¿Tienes los collares de nuestros enemigos?', 0),
(@ID, 'esMX', '¡Algún día, los Lanza Negra aplastarán a los Sangrapellejo! ¿Tienes los collares de nuestros enemigos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Los herviré y les chuparé la sangre, y los espíritus de sus dueños se debilitarán cuando destruya estos collares.$B$BToma, $n. Esto pagará la deuda que tengo contigo.', 0),
(@ID, 'esMX', 'Ah, muy bien. Los herviré y les chuparé la sangre, y los espíritus de sus dueños se debilitarán cuando destruya estos collares.$B$BToma, $n. Esto pagará la deuda que tengo contigo.', 0);
-- 598 Collar de hueso partido
-- https://es.classic.wowhead.com/quest=598
SET @ID := 598;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los Machacacráneos maldecirán el día que nos obligaron a entrar en guerra! ¿Has completado tu misión?', 0),
(@ID, 'esMX', '¡Los Machacacráneos maldecirán el día que nos obligaron a entrar en guerra! ¿Has completado tu misión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu fuerza es muy grandiosa si has podido conseguir estos collares, $n. Los Machacacráneos caen ante ti, como los árboles jóvenes caen a la tierra tocados por un basilisco.$B$BTus logros son de gran ayuda para nosotros.', 0),
(@ID, 'esMX', 'Tu fuerza es muy grandiosa si has podido conseguir estos collares, $n. Los Machacacráneos caen ante ti, como los árboles jóvenes caen a la tierra tocados por un basilisco.$B$BTus logros son de gran ayuda para nosotros.', 0);
-- 603 Llave de Ansirem
-- https://es.classic.wowhead.com/quest=603
SET @ID := 603;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mi daga? ¿Qué eres, algún tipo de bufón?$B$B¿Qué? ¿Quieres que te repita la historia de cómo pasé de ser el mejor luchador de la Bahía del Botín para convertirme en el hazmerreír de todos los piratas?$B$BPerdí en una pelea con cuchillo contra un Bucanero Velasangre, ¡malditos bastardos! Y se llevaron mi espada como premio.$B$BNo es que pueda seguir siendo un luchador solo con mis insultos y sin un cuchillo...', 0),
(@ID, 'esMX', '¿Mi daga? ¿Qué eres, algún tipo de bufón?$B$B¿Qué? ¿Quieres que te repita la historia de cómo pasé de ser el mejor luchador de la Bahía del Botín para convertirme en el hazmerreír de todos los piratas?$B$BPerdí en una pelea con cuchillo contra un Bucanero Velasangre, ¡malditos bastardos! Y se llevaron mi espada como premio.$B$BNo es que pueda seguir siendo un luchador solo con mis insultos y sin un cuchillo...', 0);
-- 605 Fragmentos de cristales canto azules
-- https://es.classic.wowhead.com/quest=605
SET @ID := 605;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes esos fragmentos ya? ¡Te daré un buen porcentaje de los beneficios!', 0),
(@ID, 'esMX', '¿Tienes esos fragmentos ya? ¡Te daré un buen porcentaje de los beneficios!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ajá! Esto será perfecto, $n. ¡Sí, excelente!$B$BAquí tienes tu parte y... ha sido un placer hacer negocios contigo.', 0),
(@ID, 'esMX', '¡Ajá! Esto será perfecto, $n. ¡Sí, excelente!$B$BAquí tienes tu parte y... ha sido un placer hacer negocios contigo.', 0);
-- 606 Asusta al Trémulo
-- https://es.classic.wowhead.com/quest=606
SET @ID := 606;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh! No me gusta cómo me estás mirando, $gchico:chica;.', 0),
(@ID, 'esMX', '¡Eh! No me gusta cómo me estás mirando, $gchico:chica;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aaah! ¿De dónde has sacado esto? No, no me lo digas, no quiero saberlo.$B$B¿Quién te envía? ¿Lobo de Mar?', 0),
(@ID, 'esMX', '¡Aaah! ¿De dónde has sacado esto? No, no me lo digas, no quiero saberlo.$B$B¿Quién te envía? ¿Lobo de Mar?', 0);
-- 610 "El Guapo" Duncan
-- https://es.classic.wowhead.com/quest=610
SET @ID := 610;
UPDATE `quest_template_locale` SET `Title` = '"El Guapo" Duncan', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca me han vencido. ¿Lo sabías, $n? Sí, obviamente me han herido alguna vez, no te puedes meter en un combate sin llevarte algún que otro rasguño, pero solo consiguió golpearme en la cabeza y caí a plomo. Cuando me desperté, me faltaba la espada.$B$BA pesar de mi nombre, sigo necesitando el acero para luchar y, para mí, tenía que ser esa espada.', 0),
(@ID, 'esMX', 'Nunca me han vencido. ¿Lo sabías, $n? Sí, obviamente me han herido alguna vez, no te puedes meter en un combate sin llevarte algún que otro rasguño, pero solo consiguió golpearme en la cabeza y caí a plomo. Cuando me desperté, me faltaba la espada.$B$BA pesar de mi nombre, sigo necesitando el acero para luchar y, para mí, tenía que ser esa espada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado a Duncan? Entonces, supongo que no eres tan imbécil como parecías a primera vista.$B$BMe imagino que eso significa que no te desafiaré de aquí a un tiempo.', 0),
(@ID, 'esMX', '¿Has derrotado a Duncan? Entonces, supongo que no eres tan imbécil como parecías a primera vista.$B$BMe imagino que eso significa que no te desafiaré de aquí a un tiempo.', 0);
-- 611 La maldición de las mareas
-- https://es.classic.wowhead.com/quest=611
SET @ID := 611;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado ya la Piedra de las Mareas, $n? Ya he dejado un espacio libre y he comprado un pedestal para ella.', 0),
(@ID, 'esMX', '¿Has recuperado ya la Piedra de las Mareas, $n? Ya he dejado un espacio libre y he comprado un pedestal para ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sorprendente! ¡La Piedra de las Mareas! Tendrá un lugar de honor en mi colección de artefactos trols antiguos. ¿Has visto que parece casi como si tuviera una marea atrapada bajo la superficie? ¡Magnífico!', 0),
(@ID, 'esMX', '¡Sorprendente! ¡La Piedra de las Mareas! Tendrá un lugar de honor en mi colección de artefactos trols antiguos. ¿Has visto que parece casi como si tuviera una marea atrapada bajo la superficie? ¡Magnífico!', 0);
-- 614 El cofre del Capitán
-- https://es.classic.wowhead.com/quest=614
SET @ID := 614;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, $n! ¿Encontraste a Gorlash? ¡Ese cofre era mi favorito y tiene un compartimento oculto que contenía mis mayores tesoros!', 0),
(@ID, 'esMX', '¡Ah, $n! ¿Encontraste a Gorlash? ¡Ese cofre era mi favorito y tiene un compartimento oculto que contenía mis mayores tesoros!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo encontraste! ¡Oh que feliz día! Gracias, $n. Recuperar mi cofre enfría un poco el fuego en mí pecho.$B$BPero mi venganza no está completa...', 0),
(@ID, 'esMX', '¡Lo encontraste! ¡Oh que feliz día! Gracias, $n. Recuperar mi cofre enfría un poco el fuego en mí pecho.$B$BPero mi venganza no está completa...', 0);
-- El alfanje del Capitán
-- 615, 8553
-- https://es.classic.wowhead.com/quest=615
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(615, 8553) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(615, 'esES', 'Hola, hola, $n. El capitán me ha dicho que vas a por Negolash, ¿eh?', 0),
(8553, 'esES', 'Hola, hola, $n. El capitán me ha dicho que vas a por Negolash, ¿eh?', 0),
(615, 'esMX', 'Hola, hola, $n. El capitán me ha dicho que vas a por Negolash, ¿eh?', 0),
(8553, 'esMX', 'Hola, hola, $n. El capitán me ha dicho que vas a por Negolash, ¿eh?', 0);
-- 616 La isla fantasma
-- https://es.classic.wowhead.com/quest=616
SET @ID := 616;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interesante. Hace algún tiempo, leí un libro que sugería que...$B$BAh, claro, se trataba de una leyenda trol. Si lo que Krazek dice es cierto, quizás pronto pueda añadir la Piedra de las Mareas a mi colección de artefactos y reliquias antiguos.', 0),
(@ID, 'esMX', 'Interesante. Hace algún tiempo, leí un libro que sugería que...$B$BAh, claro, se trataba de una leyenda trol. Si lo que Krazek dice es cierto, quizás pronto pueda añadir la Piedra de las Mareas a mi colección de artefactos y reliquias antiguos.', 0);
-- 618 Enfréntate a Negolash
-- https://es.classic.wowhead.com/quest=618
SET @ID := 618;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste mi alfanje, $n?', 0),
(@ID, 'esMX', '¿Conseguiste mi alfanje, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Conseguiste mi alfanje de Negolash! ¡No puedo creer mi fortuna, $n! Conocerte ha mejorado mi suerte, ¡de eso no hay duda!$B$B¡Gracias! Y si alguna vez consigo un nuevo barco y estás buscando navegar por los mares, serías mi invitado de honor.', 0),
(@ID, 'esMX', '¡Conseguiste mi alfanje de Negolash! ¡No puedo creer mi fortuna, $n! Conocerte ha mejorado mi suerte, ¡de eso no hay duda!$B$B¡Gracias! Y si alguna vez consigo un nuevo barco y estás buscando navegar por los mares, serías mi invitado de honor.', 0);
-- 619 La tentación de Negolash
-- https://es.classic.wowhead.com/quest=619
SET @ID := 619;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es un bote salvavidas abandonado. Escrito a lo largo de su costado con pintura rayada y descolorida están las palabras:$B$B"La venganza de Smotts"', 0),
(@ID, 'esMX', 'Esto es un bote salvavidas abandonado. Escrito a lo largo de su costado con pintura rayada y descolorida están las palabras:$B$B"La venganza de Smotts"', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Amontonas la comida y la bebida en la plataforma...', 0),
(@ID, 'esMX', 'Amontonas la comida y la bebida en la plataforma...', 0);
-- 620 La banda con monograma
-- https://es.classic.wowhead.com/quest=620
SET @ID := 620;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. ¿Tienes negocios conmigo?', 0),
(@ID, 'esMX', 'Hola. ¿Tienes negocios conmigo?', 0);
 -- 621 El secreto de Zanzil
-- https://es.classic.wowhead.com/quest=621
SET @ID := 621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Tienes las muestras de la mezcla de Zanzil??', 0),
(@ID, 'esMX', '¿¿Tienes las muestras de la mezcla de Zanzil??', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Aquí tienes lo tuyo.$B$BY un poco más... por tu discreción.', 0),
(@ID, 'esMX', 'Ah, muy bien. Aquí tienes lo tuyo.$B$BY un poco más... por tu discreción.', 0);
-- 624 El enigma de Cortello
-- https://es.classic.wowhead.com/quest=624
SET @ID := 624;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El pergamino húmedo contiene la siguiente pista...', 0),
(@ID, 'esMX', 'El pergamino húmedo contiene la siguiente pista...', 0);
-- 625 El enigma de Cortello
-- https://es.classic.wowhead.com/quest=625
SET @ID := 625;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes encontrar un pergamino mohoso.', 0),
(@ID, 'esMX', 'Debes encontrar un pergamino mohoso.', 0);
-- 626 El enigma de Cortello
-- https://es.classic.wowhead.com/quest=626
SET @ID := 626;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Abres el cofre y en su interior encuentras...', 0),
(@ID, 'esMX', 'Abres el cofre y en su interior encuentras...', 0);
-- 629 El Arrecife Mortal
-- https://es.classic.wowhead.com/quest=629
SET @ID := 629;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy esperando por el fragmento de la tablilla, $n.', 0),
(@ID, 'esMX', 'Estoy esperando por el fragmento de la tablilla, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y eso está bien. Cuando vuelva a Orgrimmar, colocaré este fragmento en un lugar sagrado. Nos recordará el poder y el honor de Gri\'lek.$B$BGracias, $n. Tus actos marcan una creciente amistad con la tribu Lanza Negra.', 0),
(@ID, 'esMX', 'Y eso está bien. Cuando vuelva a Orgrimmar, colocaré este fragmento en un lugar sagrado. Nos recordará el poder y el honor de Gri\'lek.$B$BGracias, $n. Tus actos marcan una creciente amistad con la tribu Lanza Negra.', 0);
-- 630 Mensaje en una botella
-- https://es.classic.wowhead.com/quest=630
SET @ID := 630;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Agradezco a mis ancestros que alguien haya venido a ayudarme. ¿Tienes la llave para liberarme?', 0),
(@ID, 'esMX', 'Agradezco a mis ancestros que alguien haya venido a ayudarme. ¿Tienes la llave para liberarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, me has salvado de un gran deshonor. Si estuviera en mis manos, te ofrecería un lugar en mi tribu. Pero, por ahora, solo puedo ofrecerte esto por el coraje y la nobleza que has mostrado.', 0),
(@ID, 'esMX', '$n, me has salvado de un gran deshonor. Si estuviera en mis manos, te ofrecería un lugar en mi tribu. Pero, por ahora, solo puedo ofrecerte esto por el coraje y la nobleza que has mostrado.', 0);
-- 633 El Puente Thandol
-- https://es.classic.wowhead.com/quest=633
SET @ID := 633;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cajón de explosivos destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 635 Cristal en las montañas
-- https://es.classic.wowhead.com/quest=635
SET @ID := 635;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este cristal palpita, es como si tuviera una fuerza viva atrapada en su interior.', 0),
(@ID, 'esMX', 'Este cristal palpita, es como si tuviera una fuerza viva atrapada en su interior.', 0);
-- 643 El sigilo de Arathor
-- https://es.classic.wowhead.com/quest=643
SET @ID := 643;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Valeroso no será fácil de localizar, $n. Montado a caballo, puede cubrir terreno rápidamente. No obstante, debemos tener su sigilo.', 0),
(@ID, 'esMX', 'Valeroso no será fácil de localizar, $n. Montado a caballo, puede cubrir terreno rápidamente. No obstante, debemos tener su sigilo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perder a su líder de caballería será un gran golpe para los defensores de Stromgarde. Mejor aún, significa que estamos a solo un sigilo de poder tener Trol\'kalar para nosotros.', 0),
(@ID, 'esMX', 'Perder a su líder de caballería será un gran golpe para los defensores de Stromgarde. Mejor aún, significa que estamos a solo un sigilo de poder tener Trol\'kalar para nosotros.', 0);
-- 9163 En territorio ocupado
-- https://es.wowhead.com/quest=9163
SET @ID := 9163;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por dónde vas en tu intento de descubrir la trama de los elfos de la noche en la Isla Shalandis, $c?', 0),
(@ID, 'esMX', '¿Por dónde vas en tu intento de descubrir la trama de los elfos de la noche en la Isla Shalandis, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Problemas! Estos planes muestran las tropas de los elfos de la noche en An\'daroth, lo que ya sabíamos, pero también en An\'owyn, un lugar nexo más remoto del sureste.$B$BHay un tercer nexo hacia el este que no se menciona llamado An\'telas. Todo esto me da muy mala espina, $c.', 0),
(@ID, 'esMX', '¡Problemas! Estos planes muestran las tropas de los elfos de la noche en An\'daroth, lo que ya sabíamos, pero también en An\'owyn, un lugar nexo más remoto del sureste.$B$BHay un tercer nexo hacia el este que no se menciona llamado An\'telas. Todo esto me da muy mala espina, $c.', 0);
