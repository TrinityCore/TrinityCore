-- 1455 El naufragio de Karnitol
-- https://es.wowhead.com/quest=1455
SET @ID := 1455;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido de nuevo a Punta de Nijel, $n. Dime, ¿qué has encontrado?$B$B¡¿Qué?! ¿Nada? No van a darnos nada por un cofre vacío...$B$BHáblame de esas marcas que viste.', 0),
(@ID, 'esMX', 'Bienvenido de nuevo a Punta de Nijel, $n. Dime, ¿qué has encontrado?$B$B¡¿Qué?! ¿Nada? No van a darnos nada por un cofre vacío...$B$BHáblame de esas marcas que viste.', 0);
-- 6161 La búsqueda del tesoro de Masatormento
-- https://es.classic.wowhead.com/quest=6161
SET @ID := 6161;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este cofre está bien cerrado.', 0),
(@ID, 'esMX', 'Este cofre está bien cerrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El cofre se abre y ves que contiene el tesoro de Masatormento!', 0),
(@ID, 'esMX', '¡El cofre se abre y ves que contiene el tesoro de Masatormento!', 0);
-- 1456 El naufragio de Karnitol
-- https://es.wowhead.com/quest=1456
SET @ID := 1456;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No quisiera ofender a Nijel, aunque no sé ni quién es, pero este campamento no es precisamente el sitio más cómodo para pasar la noche, ya me entiendes, $n.', 0),
(@ID, 'esMX', 'No quisiera ofender a Nijel, aunque no sé ni quién es, pero este campamento no es precisamente el sitio más cómodo para pasar la noche, ya me entiendes, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Es genial, $n! ¡Has encontrado las pertenencias de Karnitol!$B$BEsos malditos nagas... siempre andan dando problemas. Creo que preferiría pasar el resto de mi vida luchando con la Horda antes que combatir con esa calaña.$B$BHas hecho un gran servicio a los Recuperadores. Por favor, ¡acepta esto junto con nuestro agradecimiento!', 0),
(@ID, 'esMX', '¡Es genial, $n! ¡Has encontrado las pertenencias de Karnitol!$B$BEsos malditos nagas... siempre andan dando problemas. Creo que preferiría pasar el resto de mi vida luchando con la Horda antes que combatir con esa calaña.$B$BHas hecho un gran servicio a los Recuperadores. Por favor, ¡acepta esto junto con nuestro agradecimiento!', 0);
-- 5741 El Cetro de Luz
-- https://es.classic.wowhead.com/quest=5741
SET @ID := 5741;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el Cetro de Luz?', 0),
(@ID, 'esMX', '¿Tienes el Cetro de Luz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El elusivo Cetro de la Luz! Al hacerte con él has eliminado una gran amenaza para el mundo. Bien hecho, $c, bien hecho.', 0),
(@ID, 'esMX', '¡El elusivo Cetro de la Luz! Al hacerte con él has eliminado una gran amenaza para el mundo. Bien hecho, $c, bien hecho.', 0);
-- 6027 El Libro de los Ancestros
-- https://es.classic.wowhead.com/quest=6027
SET @ID := 6027;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, $n! Me alegro de volver a verte. ¿Tienes el Libro de los Ancestros?', 0),
(@ID, 'esMX', '¡Ah, $n! Me alegro de volver a verte. ¿Tienes el Libro de los Ancestros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El Libro de los Ancestros! ¡El que tanto tiempo llevaba extraviado! Me aseguraré de que este libro llegue al Alto Consejo. Hoy has hecho algo magnífico. Deberíamos agradecértelo, y te lo agradecemos ¡como a $gun:una; $ghéroe:heroína;!', 0),
(@ID, 'esMX', '¡El Libro de los Ancestros! ¡El que tanto tiempo llevaba extraviado! Me aseguraré de que este libro llegue al Alto Consejo. Hoy has hecho algo magnífico. Deberíamos agradecértelo, y te lo agradecemos ¡como a $gun:una; $ghéroe:heroína;!', 0);
-- 6132 ¡Sácame de aquí!
-- https://es.wowhead.com/quest=6132
SET @ID := 6132;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto a mi hermana Melizza? Ella siempre está en movimiento, lo que la mete en problemas todo el tiempo.', 0),
(@ID, 'esMX', '¿Has visto a mi hermana Melizza? Ella siempre está en movimiento, lo que la mete en problemas todo el tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi hermana Melizza dijo que vendrías. Gracias por sacarla del apuro... ¡aunque seguro que a estas horas ya se ha metido en otro lío!', 0),
(@ID, 'esMX', 'Mi hermana Melizza dijo que vendrías. Gracias por sacarla del apuro... ¡aunque seguro que a estas horas ya se ha metido en otro lío!', 0);
-- 5501 Recolección de kodos
-- https://es.wowhead.com/quest=5501
SET @ID := 5501;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los huesos? La caravana llegará de un momento a otro. Solo necesito 10 huesos de kodo más para llegar a la cumbre. ¡A la cumbre de mi carrera, sí señora!', 0),
(@ID, 'esMX', '¿Tienes los huesos? La caravana llegará de un momento a otro. Solo necesito 10 huesos de kodo más para llegar a la cumbre. ¡A la cumbre de mi carrera, sí señora!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, qué visión tan estupenda! ¡Mis huesos!$B$BEstoy deseando que los de casa vean mi cara en la portada de Grandes fortunas goblin. Seré el goblin más rico del mundo. ¡Y mi profesor de gimnasia decía que nunca llegaría a nada!', 0),
(@ID, 'esMX', '¡Ah, qué visión tan estupenda! ¡Mis huesos!$B$BEstoy deseando que los de casa vean mi cara en la portada de Grandes fortunas goblin. Seré el goblin más rico del mundo. ¡Y mi profesor de gimnasia decía que nunca llegaría a nada!', 0);
-- 6134 La caza de ectoplasmas
-- https://es.wowhead.com/quest=6134
SET @ID := 6134;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está mi ectoplasma, $n?', 0),
(@ID, 'esMX', '¿Dónde está mi ectoplasma, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahí está! Y parece que también llevas un poco encima. Es pegajosillo, ¿eh?$B$BBueno, gracias por todo, $n. Esta cosa me hará ganar una fortuna... ¡si consigo convencer a los centauros de que la vale!', 0),
(@ID, 'esMX', '¡Ahí está! Y parece que también llevas un poco encima. Es pegajosillo, ¿eh?$B$BBueno, gracias por todo, $n. Esta cosa me hará ganar una fortuna... ¡si consigo convencer a los centauros de que la vale!', 0);
-- 7028 Los males de Maraudon
-- https://es.classic.wowhead.com/quest=7028
SET @ID := 7028;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No preguntes!$B$BYa sabes lo que quiero.', 0),
(@ID, 'esMX', '¡No preguntes!$B$BYa sabes lo que quiero.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja! Sabía que volverías.$B$B<Willow habla entre dientes.>$B$BQué fácil de convencer.$B$BLo que sea por una recompensa. Je, je, je...', 0),
(@ID, 'esMX', '¡Ja, ja! Sabía que volverías.$B$B<Willow habla entre dientes.>$B$BQué fácil de convencer.$B$BLo que sea por una recompensa. Je, je, je...', 0);
-- 1457 El naufragio de Karnitol
-- https://es.classic.wowhead.com/quest=1457
SET @ID := 1457;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El negocio va de maravilla, $n y no tengo mucho tiempo para preguntas. Si tienes asuntos con los Recuperadores, te escucharé. Si no es así, tendré que pedirte que hables con uno de mis subalternos. Ellos se ocupan de las cosas por aquí.', 0),
(@ID, 'esMX', 'El negocio va de maravilla, $n y no tengo mucho tiempo para preguntas. Si tienes asuntos con los Recuperadores, te escucharé. Si no es así, tendré que pedirte que hables con uno de mis subalternos. Ellos se ocupan de las cosas por aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que el cofre estaba destruido pero los objetos están todos aquí, ¿eh? Bueno, dejaré que sea él quien lo juzgue. Lo bueno que tiene este negocio es que, si los clientes no quedan satisfechos, ¡les puedo mandar a paseo! Confían en que nosotros encontraremos sus cosas... no han pedido que estén estupendas e intactas cuando las recuperen.$B$BBuen trabajo, $n. Ahora vamos a ocuparnos de que recibas tu pago.', 0),
(@ID, 'esMX', 'Así que el cofre estaba destruido pero los objetos están todos aquí, ¿eh? Bueno, dejaré que sea él quien lo juzgue. Lo bueno que tiene este negocio es que, si los clientes no quedan satisfechos, ¡les puedo mandar a paseo! Confían en que nosotros encontraremos sus cosas... no han pedido que estén estupendas e intactas cuando las recuperen.$B$BBuen trabajo, $n. Ahora vamos a ocuparnos de que recibas tu pago.', 0);
-- 3448 Encargarse de la investigación
-- https://es.classic.wowhead.com/quest=3448
SET @ID := 3448;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que vienes de parte de Karnik? Me lo imaginaba; he descubierto cosas asombrosas sobre Azshara. Los elfos de la noche viven muchos años, pero la gente tiende a olvidar los acontecimientos más desagradables de su historia. No lo digo como crítica, solo constato un hecho.$B$BHace mucho tiempo, construyeron ciudades imbuidas de magia y otras artes hoy perdidas. Esos temas me interesan, por eso empecé a investigar y descubrí cosas maravillosas.', 0),
(@ID, 'esMX', '¿Que vienes de parte de Karnik? Me lo imaginaba; he descubierto cosas asombrosas sobre Azshara. Los elfos de la noche viven muchos años, pero la gente tiende a olvidar los acontecimientos más desagradables de su historia. No lo digo como crítica, solo constato un hecho.$B$BHace mucho tiempo, construyeron ciudades imbuidas de magia y otras artes hoy perdidas. Esos temas me interesan, por eso empecé a investigar y descubrí cosas maravillosas.', 0);
-- 2769 Los hermanos Pernolatón
-- https://es.classic.wowhead.com/quest=2769
SET @ID := 2769;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿quieres ayudarme? ¡Excelente!$B$B¡Hay una parte que quiero para un experimento en el que estoy trabajando, y necesito $gun:una; $c valiente como tú para ayudarme a conseguirlo!', 0),
(@ID, 'esMX', 'Ah, ¿quieres ayudarme? ¡Excelente!$B$B¡Hay una parte que quiero para un experimento en el que estoy trabajando, y necesito $gun:una; $c valiente como tú para ayudarme a conseguirlo!', 0);
-- 3449 Runas Arcanas
-- https://es.classic.wowhead.com/quest=3449
SET @ID := 3449;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, bueno, bueno, me alegro de que hayas llegado hasta aquí, $n. ¿Recibiste los calcos de Tymor?$B$BPor peligroso que sea eselugar, no ha habido demasiada acción a lo largo de la costa. Eso podría deberse a que los nagas nadan bajo el agua, pero ese no es mi problema ... Yo patrullo los cielos.', 0),
(@ID, 'esMX', 'Bueno, bueno, bueno, me alegro de que hayas llegado hasta aquí, $n. ¿Recibiste los calcos de Tymor?$B$BPor peligroso que sea eselugar, no ha habido demasiada acción a lo largo de la costa. Eso podría deberse a que los nagas nadan bajo el agua, pero ese no es mi problema ... Yo patrullo los cielos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno verte $gsano:sana; y $gsalvo:salva;, $n. Espero que las cosas no hayan sido demasiado difíciles para ti.$B$BSe los llevaré a Tymor de inmediato. Estará encantado de echar un vistazo a estas cosas.$B$BAdelante, tira la pistola de bengalas... probablemente ya no te sirva de nada, y ya tengo una nueva.', 0),
(@ID, 'esMX', 'Es bueno verte $gsano:sana; y $gsalvo:salva;, $n. Espero que las cosas no hayan sido demasiado difíciles para ti.$B$BSe los llevaré a Tymor de inmediato. Estará encantado de echar un vistazo a estas cosas.$B$BAdelante, tira la pistola de bengalas... probablemente ya no te sirva de nada, y ya tengo una nueva.', 0);
-- 3450 Un simple envío
-- https://es.classic.wowhead.com/quest=3450
SET @ID := 3450;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué querías, $n? Tengo mucho que hacer, solo he venido a buscar unas crines de wendigo.$B$BAcabo de mandar a alguien al Almacén de Brasacerada, así que tienes un minuto para contarme lo que sea.', 0),
(@ID, 'esMX', '¿Qué querías, $n? Tengo mucho que hacer, solo he venido a buscar unas crines de wendigo.$B$BAcabo de mandar a alguien al Almacén de Brasacerada, así que tienes un minuto para contarme lo que sea.', 0);
-- 3451 Una señal para el envío
-- https://es.classic.wowhead.com/quest=3451
SET @ID := 3451;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Toma mi pistola de bengalas. Sé paciente después de disparar; solo llevan 2 cartuchos y yo puedo tardar hasta 1 minuto, depende de dónde esté. Tú mira al mar después de lanzar las bengalas.', 0),
(@ID, 'esMX', 'Toma mi pistola de bengalas. Sé paciente después de disparar; solo llevan 2 cartuchos y yo puedo tardar hasta 1 minuto, depende de dónde esté. Tú mira al mar después de lanzar las bengalas.', 0);
-- 3483 Una señal para el envío
-- https://es.classic.wowhead.com/quest=3483
SET @ID := 3483;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Otra pistola de bengalas? Por supuesto.$B$BY recuerda que debes ir a la punta sur de Azshara. Es una islita reconvertida en pista de aterrizaje; seguro que la ves.', 0),
(@ID, 'esMX', '¿Otra pistola de bengalas? Por supuesto.$B$BY recuerda que debes ir a la punta sur de Azshara. Es una islita reconvertida en pista de aterrizaje; seguro que la ves.', 0);
-- 1179 Los hermanos Pernolatón
-- https://es.classic.wowhead.com/quest=1179
SET @ID := 1179;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Mira por dónde pisas! ¡Ten mucho, mucho, mucho cuidado! Todos estos chismes que ves por aquí son muy delicados y si queremos ganar, ¡deben funcionar a la perfección!', 0),
(@ID, 'esMX', '¡Mira por dónde pisas! ¡Ten mucho, mucho, mucho cuidado! Todos estos chismes que ves por aquí son muy delicados y si queremos ganar, ¡deben funcionar a la perfección!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, Barbalarga nos ha enviado un cargamento de cascos! ¡Hurra!$B$BQuizás ahora podamos convencer a algún piloto para que conduzca nuestro coche...', 0),
(@ID, 'esMX', '¡Ah, Barbalarga nos ha enviado un cargamento de cascos! ¡Hurra!$B$BQuizás ahora podamos convencer a algún piloto para que conduzca nuestro coche...', 0);
-- 1271 ¡Una fiesta en tu honor!
-- https://es.wowhead.com/quest=1271
SET @ID := 1271;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi sobrino me dijo que le habías ayudado en su investigación en Revolcafango y que sacaste a su socio de un buen apuro. ¡Pues los Stern estamos muy unidos y atendemos a nuestros amigos!$B$BAsí que lávate las manos, $n, ¡porque estamos a punto de montar una fiesta en tu honor!', 0),
(@ID, 'esMX', 'Mi sobrino me dijo que le habías ayudado en su investigación en Revolcafango y que sacaste a su socio de un buen apuro. ¡Pues los Stern estamos muy unidos y atendemos a nuestros amigos!$B$BAsí que lávate las manos, $n, ¡porque estamos a punto de montar una fiesta en tu honor!', 0);
-- 565 Capa de piel de yeti de Bartolo
-- https://es.classic.wowhead.com/quest=565
SET @ID := 565;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has venido de nuevo al gran Bartolo. ¿Ya tienes lo necesario para la capa de piel de yeti? ¿O has venido por la deliciosa compañía del gran Bartolo?', 0),
(@ID, 'esMX', 'Has venido de nuevo al gran Bartolo. ¿Ya tienes lo necesario para la capa de piel de yeti? ¿O has venido por la deliciosa compañía del gran Bartolo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora el gran Bartolo pondrá en práctica su magia! No necesito bastón de mago ni vara de hechicero. ¡Mi magia solo necesita hilo y aguja!', 0),
(@ID, 'esMX', '¡Ahora el gran Bartolo pondrá en práctica su magia! No necesito bastón de mago ni vara de hechicero. ¡Mi magia solo necesita hilo y aguja!', 0);
-- 564 Una amenaza costosa
-- https://es.classic.wowhead.com/quest=564
SET @ID := 564;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los leones de montaña están matando a nuestros caballos a diestro y siniestro y aquí estás queriendo parlotear sobre el clima y que se yo.$B$BDebería buscar un verdadero héroe. Más matar y menos hablar.', 0),
(@ID, 'esMX', 'Los leones de montaña están matando a nuestros caballos a diestro y siniestro y aquí estás queriendo parlotear sobre el clima y que se yo.$B$BDebería buscar un verdadero héroe. Más matar y menos hablar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me alegro de oír eso! Ya sabía yo que tú me resolverías el problema... ¡Eres un orgullo para tu familia, $n!', 0),
(@ID, 'esMX', '¡Me alegro de oír eso! Ya sabía yo que tú me resolverías el problema... ¡Eres un orgullo para tu familia, $n!', 0);
-- 659 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=659
SET @ID := 659;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Procura estar tan quieto como puedas, viajero.$B$BA los orcos no les sienta muy bien que los espíen y en esta Granja hay más de lo que se ve a simple vista.', 0),
(@ID, 'esMX', 'Procura estar tan quieto como puedas, viajero.$B$BA los orcos no les sienta muy bien que los espíen y en esta Granja hay más de lo que se ve a simple vista.', 0);
-- 500 La recompensa Aplastacresta
-- https://es.classic.wowhead.com/quest=500
SET @ID := 500;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás cazando ogros, $n? ¿Me traes los huesos sucios que te pedí?', 0),
(@ID, 'esMX', '¿Estás cazando ogros, $n? ¿Me traes los huesos sucios que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué buen montón de huesos sucios me traes, $n.$B$BEspero que ahora los ogros nos dejen tranquilos; al menos, de momento.', 0),
(@ID, 'esMX', 'Qué buen montón de huesos sucios me traes, $n.$B$BEspero que ahora los ogros nos dejen tranquilos; al menos, de momento.', 0);
