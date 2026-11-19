-- 4491 Un poco de ayuda de mis amigos
-- https://es.classic.wowhead.com/quest=4491
SET @ID := 4491;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado tan preocupada por Ringo...', 0),
(@ID, 'esMX', 'He estado tan preocupada por Ringo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ringo no está en plena forma, $n, ¡pero me alegra tenerlo de vuelta de una sola pieza!$B$BGracias por encontrarle.', 0),
(@ID, 'esMX', 'Ringo no está en plena forma, $n, ¡pero me alegra tenerlo de vuelta de una sola pieza!$B$BGracias por encontrarle.', 0);
-- 979 Encuentra a Ranshalla
-- https://es.classic.wowhead.com/quest=979
SET @ID := 979;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Vienes de parte de Erelas? Genial, estaba preparándome para ir a las cuevas, no me importaría tener algo de compañía.', 0),
(@ID, 'esMX', '¡Hola! ¿Vienes de parte de Erelas? Genial, estaba preparándome para ir a las cuevas, no me importaría tener algo de compañía.', 0);
-- 5163 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=5163
SET @ID := 5163;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo esperar a saber cuál es la reacción de mis amigos!$B$B¡Nunca se lo esperarían!', 0),
(@ID, 'esMX', '¡No puedo esperar a saber cuál es la reacción de mis amigos!$B$B¡Nunca se lo esperarían!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! ¡Se lo pensarán dos veces antes de volver a reírse de mis ideas!$B$BGracias por tu ayuda, $n. ¡Sin tu ayuda no habría podido divertirme tanto!', 0),
(@ID, 'esMX', '¡Ja! ¡Se lo pensarán dos veces antes de volver a reírse de mis ideas!$B$BGracias por tu ayuda, $n. ¡Sin tu ayuda no habría podido divertirme tanto!', 0);
-- 4901 Guardianes del altar
-- https://es.classic.wowhead.com/quest=4901
SET @ID := 4901;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te reuniste con Ranshalla?', 0),
(@ID, 'esMX', '¿Te reuniste con Ranshalla?', 0);
-- 5082 La amenaza de los Nevada
-- https://es.classic.wowhead.com/quest=5082
SET @ID := 5082;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aprecio tu ayuda!', 0),
(@ID, 'esMX', '¡Aprecio tu ayuda!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡!Muchas gracias, $n! Ya puedo seguir trabajando aquí$B$B¿Encontraste algo interesante en el campamento Nevada?', 0),
(@ID, 'esMX', '¡!Muchas gracias, $n! Ya puedo seguir trabajando aquí$B$B¿Encontraste algo interesante en el campamento Nevada?', 0);
-- 3909 El Elixir de Videre
-- https://es.classic.wowhead.com/quest=3909
SET @ID := 3909;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás de vuelta?', 0),
(@ID, 'esMX', '¿Ya estás de vuelta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré un vial para asegurarme de que este es de verdad el Elixir... Sí... Esto es.', 0),
(@ID, 'esMX', 'Necesitaré un vial para asegurarme de que este es de verdad el Elixir... Sí... Esto es.', 0);
-- 5057 Esfuerzos del pasado
-- https://es.classic.wowhead.com/quest=5057
SET @ID := 5057;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aprendemos de nuestras experiencias vitales, $n. Estoy seguro de que las tuyas solo conseguirán hacerte más fuerte y $gsabio:sabia;. Has crecido mucho desde la primera vez que hablamos.$B$BToma esto como recuerdo de todas las difíciles tareas que has superado como $r $c, y no olvides que siempre tendrás mi respeto y admiración.', 0),
(@ID, 'esMX', 'Aprendemos de nuestras experiencias vitales, $n. Estoy seguro de que las tuyas solo conseguirán hacerte más fuerte y $gsabio:sabia;. Has crecido mucho desde la primera vez que hablamos.$B$BToma esto como recuerdo de todas las difíciles tareas que has superado como $r $c, y no olvides que siempre tendrás mi respeto y admiración.', 0);
-- 4902 Lechúcico salvaje de Elune
-- https://es.classic.wowhead.com/quest=4902
SET @ID := 4902;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No lo dudes; dime por qué has venido.$B$B¿Oh si? Hmm. Bien.$B$BGracias por acudir directamente a mi; siempre es mejor ir directo a la cima... Pero... Sí. Los druidas del Círculo Cenarion conocen a los Lechúcicos desde hace algún tiempo. Saben que son mascotas de Elune y que fueron elegidas para proteger los lugares más sagrados.$B$BSi bien esto no es noticia, definitivamente te felicito por tu esfuerzo. Toma, toma esto: es algo que parece adecuado por ese esfuerzo.', 0),
(@ID, 'esMX', 'No lo dudes; dime por qué has venido.$B$B¿Oh si? Hmm. Bien.$B$BGracias por acudir directamente a mi; siempre es mejor ir directo a la cima... Pero... Sí. Los druidas del Círculo Cenarion conocen a los Lechúcicos desde hace algún tiempo. Saben que son mascotas de Elune y que fueron elegidas para proteger los lugares más sagrados.$B$BSi bien esto no es noticia, definitivamente te felicito por tu esfuerzo. Toma, toma esto: es algo que parece adecuado por ese esfuerzo.', 0);
-- 3781 Investigar la mañagrana
-- https://es.classic.wowhead.com/quest=3781
SET @ID := 3781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que la paz y la serenidad sean contigo. Vienes aquí por comisión del archidruida en persona, ¿verdad?', 0),
(@ID, 'esMX', 'Que la paz y la serenidad sean contigo. Vienes aquí por comisión del archidruida en persona, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este vale es para veinte paquetes de semillas. Si se te acaban, podremos proporcionarte más. Aunque, por desgracia, producir grandes números de semillas de Tharlendris resulta bastante costoso. Por eso el Círculo Cenarion pide a quienes nos están ayudando que participen asumiendo parte de su coste.$B$BQuienes traigan mañagrana, encontrarán que la recompensa que ofrece el archidruida compensa con creces ese coste.', 0),
(@ID, 'esMX', 'Sí, este vale es para veinte paquetes de semillas. Si se te acaban, podremos proporcionarte más. Aunque, por desgracia, producir grandes números de semillas de Tharlendris resulta bastante costoso. Por eso el Círculo Cenarion pide a quienes nos están ayudando que participen asumiendo parte de su coste.$B$BQuienes traigan mañagrana, encontrarán que la recompensa que ofrece el archidruida compensa con creces ese coste.', 0);
-- 3785 Investigar la mañagrana
-- https://es.classic.wowhead.com/quest=3785
SET @ID := 3785;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Has cultivado algo de mañagrana para la importante investigación del archidruida? El trabajo que está haciendo para el Círculo Cenarion es muy importante. ¡Tu ayuda no pasará desapercibida!', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Has cultivado algo de mañagrana para la importante investigación del archidruida? El trabajo que está haciendo para el Círculo Cenarion es muy importante. ¡Tu ayuda no pasará desapercibida!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Me aseguraré de dárselas al archidruida cuando las necesite. Mientras tanto, acepta esto como muestra del aprecio del Círculo Cenarion.$B$BNecesitamos mañagrana continuamente. Si quieres seguir ayudándonos, vuelve a mí cuando hayas cultivado más mañagrana.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Me aseguraré de dárselas al archidruida cuando las necesite. Mientras tanto, acepta esto como muestra del aprecio del Círculo Cenarion.$B$BNecesitamos mañagrana continuamente. Si quieres seguir ayudándonos, vuelve a mí cuando hayas cultivado más mañagrana.', 0);
-- 4143 Bruma del mal
-- https://es.classic.wowhead.com/quest=4143
SET @ID := 4143;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Larion todavía no me habla! Seguro que sabe cómo guardar rencor.', 0),
(@ID, 'esMX', '¡Larion todavía no me habla! Seguro que sabe cómo guardar rencor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo admito, ¡estoy un poco reacio a tocar esas cosas, $n! Pero si Gregan dice que funcionará, ¡entonces estoy dispuesto a intentarlo!', 0),
(@ID, 'esMX', 'Lo admito, ¡estoy un poco reacio a tocar esas cosas, $n! Pero si Gregan dice que funcionará, ¡entonces estoy dispuesto a intentarlo!', 0);
-- 4144 Brotes Sangrepétalo
-- https://es.classic.wowhead.com/quest=4144
SET @ID := 4144;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es el plan, $n: sal y recolecta algunos brotes de pétalos de sangre, ya sabes, las plantas que aún no han brotado por completo, y tráelas aquí. Entonces veré qué puede hacer la neblina Atal\'ai.$B$BPuedes pensar que soy vengativo... ¡En realidad, tendrías razón en eso!$B$BLa verdad es que conozco la manera de salir de aquí, pero hasta que Larion admita que tengo razón, ¡me quedaré aquí!$B$B¡Así que vete, encuentra esos brotes de pétalos de sangre y divirtámonos!', 0),
(@ID, 'esMX', 'Este es el plan, $n: sal y recolecta algunos brotes de pétalos de sangre, ya sabes, las plantas que aún no han brotado por completo, y tráelas aquí. Entonces veré qué puede hacer la neblina Atal\'ai.$B$BPuedes pensar que soy vengativo... ¡En realidad, tendrías razón en eso!$B$BLa verdad es que conozco la manera de salir de aquí, pero hasta que Larion admita que tengo razón, ¡me quedaré aquí!$B$B¡Así que vete, encuentra esos brotes de pétalos de sangre y divirtámonos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No pasa nada, $n! ¡Esto llamará la atención de Larion!', 0),
(@ID, 'esMX', '¡No pasa nada, $n! ¡Esto llamará la atención de Larion!', 0);
-- 8 Un trato de pícaro
-- https://es.classic.wowhead.com/quest=8
SET @ID := 8;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Sí? ¿Qué hay?$B$BEsos Renegados sí que tienen estómagos grandes. Tú ponte cómodo... Da un respiro a tu agotado esqueleto. Me llamo Renee, por si quieres algo.', 0),
(@ID, 'esMX', '¿Sí? ¿Sí? ¿Qué hay?$B$BEsos Renegados sí que tienen estómagos grandes. Tú ponte cómodo... Da un respiro a tu agotado esqueleto. Me llamo Renee, por si quieres algo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eh? ¿Una carta? ¡Qué bien! Estaba esperando noticias de mi querida madre, que está en Camposanto. Es una santa, eso es lo que es. Me pregunto qué tal estará.$B$B¿Qué? ¿Qué? ¿Sueno demasiado alegre? No te he engañado, ¿eh?$B$BPues me da igual. Y además, tampoco te importa de quién es la carta. ¡Hala! ¡Aire!$B$BVuelve cuando tengas dinero que gastar, holgazán.$B$BYa volverás, ya, cuando necesites descansar después de unos días de aventuras o de alguna estupidez parecida.', 0),
(@ID, 'esMX', '¿Eh? ¿Una carta? ¡Qué bien! Estaba esperando noticias de mi querida madre, que está en Camposanto. Es una santa, eso es lo que es. Me pregunto qué tal estará.$B$B¿Qué? ¿Qué? ¿Sueno demasiado alegre? No te he engañado, ¿eh?$B$BPues me da igual. Y además, tampoco te importa de quién es la carta. ¡Hala! ¡Aire!$B$BVuelve cuando tengas dinero que gastar, holgazán.$B$BYa volverás, ya, cuando necesites descansar después de unos días de aventuras o de alguna estupidez parecida.', 0);
-- 23 La pata de Ursangous
-- https://es.classic.wowhead.com/quest=23
SET @ID := 23;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, ¡precisamente estaba pensando en ti! ¿Cómo te va la caza?', 0),
(@ID, 'esMX', 'Ah, $n, ¡precisamente estaba pensando en ti! ¿Cómo te va la caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, la zarpa de Ursangous! Tu talento me impresiona, $c; muchos han perecido bajo su ira. La media luna de su zarpa no deja lugar a dudas, los elfos de la noche que merodean por Vallefresno lo amaestraron. Ursangous es... era el oso más poderoso que podías encontrarte por estos lares. Derrotar a semejante criatura es toda una muestra de tu empeño y determinación.$B$B¡Tus antepasados estarían orgullosos de ti!', 0),
(@ID, 'esMX', '¡Ah, la zarpa de Ursangous! Tu talento me impresiona, $c; muchos han perecido bajo su ira. La media luna de su zarpa no deja lugar a dudas, los elfos de la noche que merodean por Vallefresno lo amaestraron. Ursangous es... era el oso más poderoso que podías encontrarte por estos lares. Derrotar a semejante criatura es toda una muestra de tu empeño y determinación.$B$B¡Tus antepasados estarían orgullosos de ti!', 0);
-- 21 Escaramuza en la Mina del Eco
-- https://es.classic.wowhead.com/quest=21
SET @ID := 21;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto a ganarte mi respeto y la gratitud del ejército de Ventormenta. Enviaré a otro equipo para ver si quedan kobolds en la mina; para ti tengo otras misiones.', 0),
(@ID, 'esMX', 'Has vuelto a ganarte mi respeto y la gratitud del ejército de Ventormenta. Enviaré a otro equipo para ver si quedan kobolds en la mina; para ti tengo otras misiones.', 0);
-- 24 La cabeza de Shadumbra
-- https://es.classic.wowhead.com/quest=24
SET @ID := 24;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos de nuevo, $n! ¿Has venido a mostrarme la prueba de tu caza?', 0),
(@ID, 'esMX', '¡Saludos de nuevo, $n! ¿Has venido a mostrarme la prueba de tu caza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una victoria para $n en la Caza de Vallefresno! Muy bien, la cabeza de Shadumbra es sin lugar a dudas un trofeo apropiado para atribuirse tan impresionante lucha.$B$BLa ferocidad de Shadumbra era de sobras conocida en toda la avanzada. Cualquier viaje hacia el oeste, especialmente a pie para salir de La Ensenada de Zoram, conllevaba mucho riesgo debido a este tigre. Gracias a ti, este peligro ya no existe.', 0),
(@ID, 'esMX', '¡Una victoria para $n en la Caza de Vallefresno! Muy bien, la cabeza de Shadumbra es sin lugar a dudas un trofeo apropiado para atribuirse tan impresionante lucha.$B$BLa ferocidad de Shadumbra era de sobras conocida en toda la avanzada. Cualquier viaje hacia el oeste, especialmente a pie para salir de La Ensenada de Zoram, conllevaba mucho riesgo debido a este tigre. Gracias a ti, este peligro ya no existe.', 0);
-- 25 Paso del Espolón bloqueado
-- https://es.classic.wowhead.com/quest=25
SET @ID := 25;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya regresaste? ¿Cuál es la situación ahí fuera? ¿Todo se ha solucionado gracias a ti?', 0),
(@ID, 'esMX', '¿Ya regresaste? ¿Cuál es la situación ahí fuera? ¿Todo se ha solucionado gracias a ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, he oído que alguien había abierto el lago como un demonio de polvo por Los Baldíos. Parece que podríamos establecer un punto de observación por allí para mantener un ojo sobre nuestros amigos de la Alianza. Bueno, eso si conseguimos mantenerlo al nivel mínimo...$B$BParece que has resultado ser bastante útil después de todo; ahora el transporte entre este lugar y Espolón deberían ser menos accidentados. Aquí tienes, te lo has ganado.', 0),
(@ID, 'esMX', 'Sí, he oído que alguien había abierto el lago como un demonio de polvo por Los Baldíos. Parece que podríamos establecer un punto de observación por allí para mantener un ojo sobre nuestros amigos de la Alianza. Bueno, eso si conseguimos mantenerlo al nivel mínimo...$B$BParece que has resultado ser bastante útil después de todo; ahora el transporte entre este lugar y Espolón deberían ser menos accidentados. Aquí tienes, te lo has ganado.', 0);
-- 26 Una lección que aprender
-- https://es.classic.wowhead.com/quest=26
SET @ID := 26;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, joven $c; ha llegado el momento de que conozcas nuestra forma acuática. Es aquella que te permite moverte libre e indefinidamente por el agua. Encontrarás este aspecto como una herramienta útil y una bendición ... pero es algo que debes ganar antes de dominarlo.$B$BTe enfrentarás a dos pruebas que superar. La primera pondrá a prueba tu capacidad para trabajar en el agua y bajo presión. La segunda pondrá a prueba tu determinación para comprender los aspectos de la forma en sí.$B$BEstá $gpreparado:preparada;, ya que ha llegado el momento de la prueba.', 0),
(@ID, 'esMX', 'Saludos, joven $c; ha llegado el momento de que conozcas nuestra forma acuática. Es aquella que te permite moverte libre e indefinidamente por el agua. Encontrarás este aspecto como una herramienta útil y una bendición ... pero es algo que debes ganar antes de dominarlo.$B$BTe enfrentarás a dos pruebas que superar. La primera pondrá a prueba tu capacidad para trabajar en el agua y bajo presión. La segunda pondrá a prueba tu determinación para comprender los aspectos de la forma en sí.$B$BEstá $gpreparado:preparada;, ya que ha llegado el momento de la prueba.', 0);
-- 1125 Los espíritus de Viento del Sur
-- https://es.classic.wowhead.com/quest=1125
SET @ID := 1125;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alianza u Horda, no importa, ningún ser merece estar atrapado en este mundo como un espíritu torturado. La liberación de estas almas arreglará las cosas, $n.', 0),
(@ID, 'esMX', 'Alianza u Horda, no importa, ningún ser merece estar atrapado en este mundo como un espíritu torturado. La liberación de estas almas arreglará las cosas, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creía que quizás la enorme colmena que está cerca de las ruinas de la aldea había tenido algo que ver. Tu trabajo ha demostrado que esto es correcto. La proximidad de la colmena supone una amenaza para cualquier trabajo futuro que podamos hacer aquí.$B$BTe agradezco lo que has hecho para liberar las almas de los caídos; ese tipo de trabajo no es fácil, lo sé. Sin embargo, cuando estés preparado, necesito volver a pedirte ayuda...', 0),
(@ID, 'esMX', 'Creía que quizás la enorme colmena que está cerca de las ruinas de la aldea había tenido algo que ver. Tu trabajo ha demostrado que esto es correcto. La proximidad de la colmena supone una amenaza para cualquier trabajo futuro que podamos hacer aquí.$B$BTe agradezco lo que has hecho para liberar las almas de los caídos; ese tipo de trabajo no es fácil, lo sé. Sin embargo, cuando estés preparado, necesito volver a pedirte ayuda...', 0);
-- 1126 Una colmena en la torre
-- https://es.classic.wowhead.com/quest=1126
SET @ID := 1126;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y qué? ¿Ha funcionado? Sigues de una pieza, me alegro. ¿Has encontrado algo?', 0),
(@ID, 'esMX', '¿Y qué? ¿Ha funcionado? Sigues de una pieza, me alegro. ¿Has encontrado algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pero... ¿pero qué...?$B$B¿Tiene forma de... caja, quizás? Está recubierto de algo muy sólido. Espera, aquí hay una parte a la vista... ¿Es eso un libro lo que hay debajo de toda esa porquería?$B$BCreo que has encontrado un gran descubrimiento, $n... bueno, al menos eso espero. Quizás sea un diario o un registro de tiempos pasados guardado en este contenedor.$B$BCreo que sé la forma de descubrir lo que es.', 0),
(@ID, 'esMX', 'Pero... ¿pero qué...?$B$B¿Tiene forma de... caja, quizás? Está recubierto de algo muy sólido. Espera, aquí hay una parte a la vista... ¿Es eso un libro lo que hay debajo de toda esa porquería?$B$BCreo que has encontrado un gran descubrimiento, $n... bueno, al menos eso espero. Quizás sea un diario o un registro de tiempos pasados guardado en este contenedor.$B$BCreo que sé la forma de descubrir lo que es.', 0);
-- 4301 El poderoso U'cha
-- https://es.classic.wowhead.com/quest=4301
SET @ID := 4301;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'U\'cha... ¡qué espléndida! De gran tamaño y color rojo, con unos dientes tan grandes como puñales. Sus brazos parecían troncos de árboles y era tan veloz como un león de la montaña. Deberías considerarte afortunado por haber puesto a prueba tu valentía de este modo... Mi pueblo no verá una criatura semejante durante varias generaciones.', 0),
(@ID, 'esMX', 'U\'cha... ¡qué espléndida! De gran tamaño y color rojo, con unos dientes tan grandes como puñales. Sus brazos parecían troncos de árboles y era tan veloz como un león de la montaña. Deberías considerarte afortunado por haber puesto a prueba tu valentía de este modo... Mi pueblo no verá una criatura semejante durante varias generaciones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Hoy has hecho algo grandioso.$B$BU\'cha era el gorila más grande que jamás haya visto. Con tu victoria has demostrado poseer gran fuerza y valor.$B$BPor favor, acepta esto como muestra de mi respeto. Te lo has ganado.', 0),
(@ID, 'esMX', 'Muy bien, $n. Hoy has hecho algo grandioso.$B$BU\'cha era el gorila más grande que jamás haya visto. Con tu victoria has demostrado poseer gran fuerza y valor.$B$BPor favor, acepta esto como muestra de mi respeto. Te lo has ganado.', 0);
-- 4245 Buscando a Memo 01
-- https://es.classic.wowhead.com/quest=4245
SET @ID := 4245;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has podido ayudar a Memo? Esa carcasa de mithril que mencionaste fue destruida era una buena suposición de lo que estaba mal. Estoy seguro de que si reemplaza eso, se reactivará y podrá volver a casa.', 0),
(@ID, 'esMX', '¿Has podido ayudar a Memo? Esa carcasa de mithril que mencionaste fue destruida era una buena suposición de lo que estaba mal. Estoy seguro de que si reemplaza eso, se reactivará y podrá volver a casa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has logrado! ¡Estupendo! Gracias, $n.$B$BMi pobre Memo 01... ¡mira qué abolladuras! Con unos pequeños retoques, la dejaré como nueva.$B$BGracias de nuevo por tu inestimable ayuda, $n.', 0),
(@ID, 'esMX', '¡Lo has logrado! ¡Estupendo! Gracias, $n.$B$BMi pobre Memo 01... ¡mira qué abolladuras! Con unos pequeños retoques, la dejaré como nueva.$B$BGracias de nuevo por tu inestimable ayuda, $n.', 0);
-- 4507 El señuelo atrapa a la reina
-- https://es.classic.wowhead.com/quest=4507
SET @ID := 4507;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para poder proseguir con la investigación, es imprescindible el cerebro de la reina. Por los datos que tenemos, creemos que posiblemente los silítidos estén controlados por una inteligencia maléfica. No quiero ni pensar en qué podría controlar algo tan insidioso como son los silítidos, $n.', 0),
(@ID, 'esMX', 'Para poder proseguir con la investigación, es imprescindible el cerebro de la reina. Por los datos que tenemos, creemos que posiblemente los silítidos estén controlados por una inteligencia maléfica. No quiero ni pensar en qué podría controlar algo tan insidioso como son los silítidos, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, $n! Hoy hemos dado un paso más hacia la victoria. Nos llevará un tiempo entender de qué se trata, pero no te preocupes, le sacaremos provecho.$B$BEn cuanto a los silítidos, sinceramente dudo que la cosa acabe aquí. Siento tener que decirlo, pero es demasiado bonito para ser cierto.', 0),
(@ID, 'esMX', '¡Fantástico, $n! Hoy hemos dado un paso más hacia la victoria. Nos llevará un tiempo entender de qué se trata, pero no te preocupes, le sacaremos provecho.$B$BEn cuanto a los silítidos, sinceramente dudo que la cosa acabe aquí. Siento tener que decirlo, pero es demasiado bonito para ser cierto.', 0);
