-- 66 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=66
SET @ID := 66;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, así que te manda Lady Eva...', 0);
-- 101 El Tótem de castigo
-- https://es.classic.wowhead.com/quest=101
SET @ID := 101;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 10 colmillos de necrófago, 10 dedos de esqueleto y 5 frascos de veneno de araña. Así haré un encantamiento a un Tótem de castigo que dañará a aquellos que intenten causarte daño a ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Muy inteligente por tu parte, $n. Este Tótem de castigo te protegerá del mal que acecha por todo Azeroth y más allá. Cuando te sientas amenazado, confórtate con el aura mágica de este tótem. Sé valiente, $c. Necesitarás todo el valor del que puedas hacer acopio, pues veo mucha sangre en tu futuro.', 0);
-- 90 Kebab de lobo sazonado
-- https://es.classic.wowhead.com/quest=90
SET @ID := 90;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has conseguido ya las 10 ijadas magras de lobo? ¿Y qué hay de las hierbas de Felicia de Ventormenta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Buen trabajo, $n! ¡Disfruta esta delicatessen llamada kebab de lobo salpimentado!', 0);
-- 56 La Guardia Nocturna
-- https://es.classic.wowhead.com/quest=56
SET @ID := 56;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has matado a esos guerreros y magos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Espléndido, $n. Serás recompensado por los servicios prestados a la gente de Villa Oscura.', 0);
-- 221 Ferocanis en el bosque
-- https://es.classic.wowhead.com/quest=221
SET @ID := 221;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Vuelves tan pronto, $N? Espero que no hayas venido a decirme que te has rendido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Te has desenvuelto bien contra los Correoscuros, $n. Pero parece que su número es irreducible. Cada vez que hacemos un progreso, llegan más a tomar el relevo.$B$B¿Qué maléfico poder es el que les trae aquí? ¿Por qué han irrumpido de esta manera en nuestro infeliz reino?$B$BTendré fe en el maestro Carevin. Sin duda, él llegará hasta el fondo del asunto.', 0);
-- 57 La Guardia Nocturna
-- https://es.classic.wowhead.com/quest=57
SET @ID := 57;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Vuelve a mí una vez que hayas matado a 15 Malignos esqueléticos y 15 Horrores esqueléticos, $N.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Las gentes de Villa Oscura te dan las gracias, $n. Has demostrado ser un gran aliado de la Guardia Nocturna.', 0);
-- 222 Ferocanis en el bosque
-- https://es.classic.wowhead.com/quest=222
SET @ID := 222;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Te intimidaron las bestias? ¡Pero no temas, $N, los que defienden la Luz nunca caerán!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'A decir verdad, $n, no creía que llegarías tan lejos. Pero está claro que me equivoqué contigo. De hecho, si deseas unirte formalmente a la lucha del maestro Carevin, será un placer escribirte una carta de recomendación.', 0);
-- 223 Ferocanis en el bosque
-- https://es.classic.wowhead.com/quest=223
SET @ID := 223;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sí? ¿Qué quieres? Habla deprisa, tengo asuntos urgentes que atender.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Perdona mi frío recibimiento, $n, pero ya te habrás dado cuenta de que soy un hombre muy ocupado. Veo que has impresionado a Calor, cosa que no es en absoluto fácil de conseguir, y veo que te ha dado una recomendación.$B$BHemos de afrontar seres de lo más desagradable, $n, y necesitamos la ayuda de cualquiera que haya demostrado su valía. Combatimos contra demonios, no-muertos y contra aquellos que les proporcionan ayuda. Mantente alerta, sé $gprecavido:precavida; y no confíes en nadie que no colabore con nuestra causa.$B$BGloria bajo la Luz.', 0);
-- 146 Mensajero a Villa Oscura
-- https://es.classic.wowhead.com/quest=146
SET @ID := 146;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me alegro de verte. ¿Debo informar de que La Guardia Nocturna ha salido de Villa Oscura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Por la Luz! El ejército de Ventormenta se ha retirado de Páramos de Poniente. ¿La Guardia ya no protege Villa Oscura? Aquí hay algo muy siniestro.$B$BAh, quería recompensarte, $c; toma unas monedas. Disculpa, pero tengo que averiguar qué está pasando en Ventormenta.', 0);
-- 174 Mira las estrellas
-- https://es.classic.wowhead.com/quest=174
SET @ID := 174;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has conseguido encontrar a un ingeniero que te haga un tubo de bronce?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Es perfecto, $n. ¡Ya hemos completado el primer paso!', 0);
-- 175 Mira las estrellas
-- https://es.classic.wowhead.com/quest=175
SET @ID := 175;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Pues sí, sí que tenía un espejo.', 0);
-- 177 Mira las estrellas
-- https://es.classic.wowhead.com/quest=177
SET @ID := 177;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Le he enseñado a Cog nuestra máquina de las estrellas. Bueno, lo que hemos hecho hasta ahora. Se quedó muy impresionado. ¿Encontraste el instrumento reflectante?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Excelente, excelente! ¡Es perfecto! ¡Muchas gracias!', 0);
-- 181 Mira las estrellas
-- https://es.classic.wowhead.com/quest=181
SET @ID := 181;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Conseguiste convencer a Zzarc\'Vul de que nos preste su monóculo para nuestro experimento?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Al fin! ¡Ya hemos completado el instrumento de las estrellas! Gracias, $n. Ya puedo seguir con mis estudios...', 0);
-- 245 Las amenazas de ocho patas
-- https://es.classic.wowhead.com/quest=245
SET @ID := 245;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Será mejor que tengas cuidado cuando trates con las arañas, he perdido a algunos de mis hombres por ellas, y créeme, no es agradable ver a un hombre colgado boca abajo en sus redes después de que el veneno ha comenzado a reblandecerlos.$B$BNo me gustaría que uno de esos bichos te almorzara.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ah! Has vuelto. Y no demasiado agotado, por lo que veo. La Guardia Nocturna está agradecida por tu trabajo, $n, y yo te prometí una recompensa, aquí la tienes.', 0);
-- 163 Cerro del Cuervo
-- https://es.classic.wowhead.com/quest=163
SET @ID := 163;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, $N! ¿De vuelta tan pronto? ¿Sin duda has vuelto a cazar? ¡No se preocupe si ha tenido algunos contratiempos, a la larga mejorará!$B$B... No podrías empeorar mucho, de todos modos ...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡No! ¡Por favor, no me mates! Soy solo yo... ¡¡Alterio!! Están por todas partes... ¡No puedo escapar! ¿Monstruos en Cerro del Cuervo? No, no, no... no puede haber ninguno. Aquí solo está Alterio, el inocente Alterio.', 0);
-- 377 Crimen y castigo
-- https://es.classic.wowhead.com/quest=377
SET @ID := 377;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Cuando se deja vivir a un profanador como Dextren Ward, se traiciona a la justicia. Vuelve a mí cuando se haya cumplido la sentencia de muerte que Lord Ebonlocke dictó contra ese rapiñador de Ward. Vamos a dar a las familias de los muertos la satisfacción que merecen, y además, enviaremos un claro mensaje a la Casa de Nobles de Ventormenta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que finalmente, Dextren Ward pagó por sus crímenes contra la humanidad... Eso sí que es hacer limpieza. ¡Y enhorabuena, $gamigo:amiga;! No solo has dado a las familias de los muertos la tranquilidad de espíritu que merecen, además has enviado un contundente mensaje a esos burócratas corruptos de la Casa de Nobles. Ventormenta debe escuchar las necesidades de la gente del Bosque del Ocaso o nos independizaremos y nos liberaremos de su tiranía.', 0);
-- 164 Entrega a Sven
-- https://es.classic.wowhead.com/quest=164
SET @ID := 164;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tienes pinta de ser fuerte, $c. ¿Has venido a unirte a nuestra lucha?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Estos suministros serán muy útiles. La ayuda de la familia Carevin es siempre bienvenida. Aquí tienes un algo por tus molestias.', 0);
-- 58 La Guardia Nocturna
-- https://es.classic.wowhead.com/quest=58
SET @ID := 58;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito tu ayuda, $n. Viaja al cementerio al noroeste y libera el mausoleo oriental de 20 propagadores de peste.$B$BVuelve a verme cuando hayas completado tu tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Te doy las gracias de parte de las gentes de Villa Oscura y de la Guardia Nocturna, $n, por tu valor y dedicación. Que la Luz ilumine tu camino.', 0);
-- 165 El ermitaño
-- https://es.classic.wowhead.com/quest=165
SET @ID := 165;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Elaine Carevin? Je, je, sí, claro... los Carevin.$B$BNo, no pasa nada. Es que ya no puedo ir a la villa, el viaje es demasiado para mí. Los caminos son peligrosos y cada día estoy más viejo. ¿Podrías hacer algunos favores a un pobre viejo?', 0);
-- 226 Con los lobos en los talones
-- https://es.classic.wowhead.com/quest=226
SET @ID := 226;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Sigues cazando lobos...?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Oh, bien. Has diezmado la manada. Ahora que no tendremos a esos lobos pisándonos los talones, podremos centrarnos en Morbent Vil.$B$BTen, coge algunos de estos manojos destellantes. Los hacen en el pueblo y muchos han sido donados a Sven, para ayudar a su causa.', 0);
