-- 1380 Khan Hratha
-- https://es.classic.wowhead.com/quest=1380
SET @ID := 1380;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Khan Hratha está muerto? ¿Tienes el fragmento de la llave?', 0),
(@ID, 'esMX', '¿Khan Hratha está muerto? ¿Tienes el fragmento de la llave?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Está muerto! ¡Khan Hratha está muerto! ¡Y ahora caerán los Maraudine! Cuando los Gelkis gobiernen esta tierra, $n, te recordaremos. Y los espíritus de la tierra cantarán tu nombre para siempre.', 0),
(@ID, 'esMX', '¡Está muerto! ¡Khan Hratha está muerto! ¡Y ahora caerán los Maraudine! Cuando los Gelkis gobiernen esta tierra, $n, te recordaremos. Y los espíritus de la tierra cantarán tu nombre para siempre.', 0);
-- 1385 Políticas brutales
-- https://es.classic.wowhead.com/quest=1385
SET @ID := 1385;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vete ahora, o el Magram te aplastará! Para ser nuestro amigo, debes matar a Gelkis.', 0),
(@ID, 'esMX', '¡Vete ahora, o el Magram te aplastará! Para ser nuestro amigo, debes matar a Gelkis.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchos Gelkis muertos. Me gusta eso. Quizás puedas hacer más cosas que me gusten. Quizás tú y el Magram puedan ser amigos.', 0),
(@ID, 'esMX', 'Muchos Gelkis muertos. Me gusta eso. Quizás puedas hacer más cosas que me gusten. Quizás tú y el Magram puedan ser amigos.', 0);
-- 1367 La alianza con los Magram
-- https://es.classic.wowhead.com/quest=1367
SET @ID := 1367;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vete! Los Magram no hablan con los débiles. ¡Los matamos!$B$BSi quieres hablar conmigo, demuéstrame que eres fuerte. Regresa después de matar a muchos Gelkis.', 0),
(@ID, 'esMX', '¡Vete! Los Magram no hablan con los débiles. ¡Los matamos!$B$BSi quieres hablar conmigo, demuéstrame que eres fuerte. Regresa después de matar a muchos Gelkis.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Gelkis lloran cuando escuchan tu nombre, $n. Te temen y te odian. ¡Te odian como odian al Magram!$B$BQuizás eres fuerte como el Magram. Veremos...', 0),
(@ID, 'esMX', 'Los Gelkis lloran cuando escuchan tu nombre, $n. Te temen y te odian. ¡Te odian como odian al Magram!$B$BQuizás eres fuerte como el Magram. Veremos...', 0);
-- 1386 Ataca a los Kolkar
-- https://es.classic.wowhead.com/quest=1386
SET @ID := 1386;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Le tienes miedo a los Kolkar? ¿Por qué no los matas? Quizás has olvidado cómo matar. ¡Date prisa y mata a los Kolkar antes de que mueran!', 0),
(@ID, 'esMX', '¿Le tienes miedo a los Kolkar? ¿Por qué no los matas? Quizás has olvidado cómo matar. ¡Date prisa y mata a los Kolkar antes de que mueran!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los Kolkar te temen ahora! Espero que te hayas reído cuando los mataste. Es mejor reír cuando matas, para que el enemigo pueda ver que es débil.', 0),
(@ID, 'esMX', '¡Los Kolkar te temen ahora! Espero que te hayas reído cuando los mataste. Es mejor reír cuando matas, para que el enemigo pueda ver que es débil.', 0);
-- 1369 Lágrimas rotas
-- https://es.classic.wowhead.com/quest=1369
SET @ID := 1369;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0),
(@ID, 'esMX', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tienes las lágrimas! Ahora los Gelkis sabrán que Theradras no los ayudará. ¡No llorará cuando los aplastemos! ¡El Magram gobernará!$B$BEres listo por ayudarnos, $n. Somos los mas fuertes.', 0),
(@ID, 'esMX', '¡Tienes las lágrimas! Ahora los Gelkis sabrán que Theradras no los ayudará. ¡No llorará cuando los aplastemos! ¡El Magram gobernará!$B$BEres listo por ayudarnos, $n. Somos los mas fuertes.', 0);
-- 1371 Un cacharro para Warug
-- https://es.classic.wowhead.com/quest=1371
SET @ID := 1371;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0),
(@ID, 'esMX', 'Si no eres nuestro enemigo, ¡harás lo que te pido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí, esto es lo que quería! Haré que se mueva de nuevo. ¡Me hace reir!', 0),
(@ID, 'esMX', '¡Sí, esto es lo que quería! Haré que se mueva de nuevo. ¡Me hace reir!', 0);
-- 1387 Colección de orejas
-- https://es.classic.wowhead.com/quest=1387
SET @ID := 1387;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algún informe, $n?', 0),
(@ID, 'esMX', '¿Tienes algún informe, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, las orejas. Bien hecho.$B$BTu lealtad a la Alianza es incuestionable, $n. La sangre que derramaste en Desolace salvará muchas vidas, te lo aseguro.', 0),
(@ID, 'esMX', 'Ah, las orejas. Bien hecho.$B$BTu lealtad a la Alianza es incuestionable, $n. La sangre que derramaste en Desolace salvará muchas vidas, te lo aseguro.', 0);
-- 7065 Corrupción de la tierra y de la semilla
-- https://es.classic.wowhead.com/quest=7065
SET @ID := 7065;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento el peso de imponer mi súplica a las razas mortales, pero no nos quedan otras opciones. Las razas de Azeroth han demostrado sin lugar a dudas que pueden superar estos desafios cuando trabajan juntas, así que es a ellas a las que les pido ayuda.$B$BSolo espero que sea suficiente.$B$BZaetar, hermano de Remulos, trajo muchos dolores a este mundo y finalmente causó su propia muerte. Hay una lección en esto para todos nosotros si somos lo suficientemente sabios para verla.', 0),
(@ID, 'esMX', 'Siento el peso de imponer mi súplica a las razas mortales, pero no nos quedan otras opciones. Las razas de Azeroth han demostrado sin lugar a dudas que pueden superar estos desafios cuando trabajan juntas, así que es a ellas a las que les pido ayuda.$B$BSolo espero que sea suficiente.$B$BZaetar, hermano de Remulos, trajo muchos dolores a este mundo y finalmente causó su propia muerte. Hay una lección en esto para todos nosotros si somos lo suficientemente sabios para verla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estas son maravillosas noticias, $n! ¡Gracias!$B$BAunque me preocupa que no pudieras recuperar los restos de Zaetar, ¿quién soy yo para cuestionar la voluntad del primogénito de Cenarius? Quizás ahora la voluntad de los centauros se doblegue y su sed de sangre se aplaque. No podemos hacer más que esperar.$B$BMe habían otorgado estos objetos para recompensar a quien nos ayudara si nuestra misión era exitosa. Puedes elegir uno como muestra de agradecimiento.', 0),
(@ID, 'esMX', '¡Estas son maravillosas noticias, $n! ¡Gracias!$B$BAunque me preocupa que no pudieras recuperar los restos de Zaetar, ¿quién soy yo para cuestionar la voluntad del primogénito de Cenarius? Quizás ahora la voluntad de los centauros se doblegue y su sed de sangre se aplaque. No podemos hacer más que esperar.$B$BMe habían otorgado estos objetos para recompensar a quien nos ayudara si nuestra misión era exitosa. Puedes elegir uno como muestra de agradecimiento.', 0);
-- 1458 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1458
SET @ID := 1458;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los sátiros son unas criaturas despreciables. La leyenda dice que están ligados de alguna forma a los elfos de la noche, pero no sé si creérmelo.$B$BCreo que esa leyenda surgió por ese elfo que los arrastró a la guerra hace unos años. El mundo no ha vuelto a ser el mismo desde entonces. Es mucho más peligroso y más terrorífico.', 0),
(@ID, 'esMX', 'Los sátiros son unas criaturas despreciables. La leyenda dice que están ligados de alguna forma a los elfos de la noche, pero no sé si creérmelo.$B$BCreo que esa leyenda surgió por ese elfo que los arrastró a la guerra hace unos años. El mundo no ha vuelto a ser el mismo desde entonces. Es mucho más peligroso y más terrorífico.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, bien, $n. No sé si esto es de buena calidad, pero si Zurdibrujo quería algo más específico, tenía que haberlo dejado claro antes de enviar a los RFecuperadores aquí fuera.$B$B¿Qué te pareces si te pones con el siguiente objeto de su lista?', 0),
(@ID, 'esMX', 'Bien, bien, $n. No sé si esto es de buena calidad, pero si Zurdibrujo quería algo más específico, tenía que haberlo dejado claro antes de enviar a los RFecuperadores aquí fuera.$B$B¿Qué te pareces si te pones con el siguiente objeto de su lista?', 0);
-- 1459 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1459
SET @ID := 1459;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento no poder decirte dónde podrías encontrar kodos y escórpidos. No conozco muy bien la zona y no tengo mucho tiempo para explorarla.', 0),
(@ID, 'esMX', 'Siento no poder decirte dónde podrías encontrar kodos y escórpidos. No conozco muy bien la zona y no tengo mucho tiempo para explorarla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres una gran ayuda, $n. Estás reduciendo al menos a la mitad mi estancia en Desolace. Gracias a ti, no tardaré en volver a Forjaz a calentarme los pies.$B$BCuando nos hayamos ocupado de esta lista y yo haya vuelto a casa, búscame. Te invitaré a una cerveza.$B$BPero hasta entonces, acabemos de reunir el resto de los componentes.', 0),
(@ID, 'esMX', 'Eres una gran ayuda, $n. Estás reduciendo al menos a la mitad mi estancia en Desolace. Gracias a ti, no tardaré en volver a Forjaz a calentarme los pies.$B$BCuando nos hayamos ocupado de esta lista y yo haya vuelto a casa, búscame. Te invitaré a una cerveza.$B$BPero hasta entonces, acabemos de reunir el resto de los componentes.', 0);
-- 1466 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1466
SET @ID := 1466;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ni siquiera sabía que hubiera demonios de estos en Desolace. Me quedé en que la tierra la ocuparon los centauros hace años, cuando los elfos de la noche recogieron sus bártulos y se fueron.$B$BMe pregunto por qué se instalaron aquí, y como.', 0),
(@ID, 'esMX', 'Ni siquiera sabía que hubiera demonios de estos en Desolace. Me quedé en que la tierra la ocuparon los centauros hace años, cuando los elfos de la noche recogieron sus bártulos y se fueron.$B$BMe pregunto por qué se instalaron aquí, y como.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La verdad? Jamás lo habría pensado. Eres increíble, $n. Te enfrentas a demonios por el experimento de un mago... ¡y además vuelves de una pieza! ¡Buen trabajo!$B$BVoy a hablar personalmente a Roetten sobre ti cuando vuelva a Forjaz.', 0),
(@ID, 'esMX', '¿La verdad? Jamás lo habría pensado. Eres increíble, $n. Te enfrentas a demonios por el experimento de un mago... ¡y además vuelves de una pieza! ¡Buen trabajo!$B$BVoy a hablar personalmente a Roetten sobre ti cuando vuelva a Forjaz.', 0);
-- 1467 Componentes para Recuperadores S.A.
-- https://es.classic.wowhead.com/quest=1467
SET @ID := 1467;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida;, $n. El negocio va de maravilla. Los golpeteos de los yunques resuenan por todo Forjaz, los fuelles alimentan el fuego y mi mujer está haciéndome un postre especial para cenar. ¿No es estupenda la vida?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida;, $n. El negocio va de maravilla. Los golpeteos de los yunques resuenan por todo Forjaz, los fuelles alimentan el fuego y mi mujer está haciéndome un postre especial para cenar. ¿No es estupenda la vida?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, el paquete de Zurdibrujo de Desolace. Excelente. Aprecio mucho tu trabajo, $c y tu eficiencia. Me alegro de tenerte a bordo, al menos para este trabajito.$B$BTengo tu pago aquí mismo. Que se sepa que Recuperadores S.A. siempre paga bien por una dura semana de trabajo.', 0),
(@ID, 'esMX', 'Ah, el paquete de Zurdibrujo de Desolace. Excelente. Aprecio mucho tu trabajo, $c y tu eficiencia. Me alegro de tenerte a bordo, al menos para este trabajito.$B$BTengo tu pago aquí mismo. Que se sepa que Recuperadores S.A. siempre paga bien por una dura semana de trabajo.', 0);
-- 1454 El naufragio de Karnitol
-- https://es.wowhead.com/quest=1454
SET @ID := 1454;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Examinas el cofre y ves que no parece haber sido dañado por el agua.$B$BPero es evidente que la tapa ha sido forzada y, por las marcas de quemaduras de los bordes, ves que cualquier trampa mágica que se pusiera en su momento para proteger su contenido, fue anulada hace tiempo.', 0),
(@ID, 'esMX', 'Examinas el cofre y ves que no parece haber sido dañado por el agua.$B$BPero es evidente que la tapa ha sido forzada y, por las marcas de quemaduras de los bordes, ves que cualquier trampa mágica que se pusiera en su momento para proteger su contenido, fue anulada hace tiempo.', 0);
-- 7041 La corrupción de Lenguavil
-- https://es.classic.wowhead.com/quest=7041
SET @ID := 7041;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'SI consigues curar a la planta, volverá a crecer. Tenemos que hacer todo lo que podamos, $n...', 0),
(@ID, 'esMX', 'SI consigues curar a la planta, volverá a crecer. Tenemos que hacer todo lo que podamos, $n...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n; seguiré investigando con los restos de líquido.$B$BAunque queda mucho por hacer, has contribuido a limpiar parte de la corrupción de Lenguavil en Maraudon. Toma esto como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Gracias, $n; seguiré investigando con los restos de líquido.$B$BAunque queda mucho por hacer, has contribuido a limpiar parte de la corrupción de Lenguavil en Maraudon. Toma esto como muestra de mi gratitud.', 0);
-- 261 El sendero Escarlata
-- https://es.classic.wowhead.com/quest=261
SET @ID := 261;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Plaga crece en poder con el paso de cada día. Si realmente deseas detener sus avances, muéstremelo.', 0),
(@ID, 'esMX', 'La Plaga crece en poder con el paso de cada día. Si realmente deseas detener sus avances, muéstremelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado tu resolución y la Cruzada Escarlata elogia tu honor.$B$BSi no te arredras ante las matanzas justas, quizás tu camino esté con nosotros...', 0),
(@ID, 'esMX', 'Has demostrado tu resolución y la Cruzada Escarlata elogia tu honor.$B$BSi no te arredras ante las matanzas justas, quizás tu camino esté con nosotros...', 0);
-- 1052 El sendero Escarlata
-- https://es.classic.wowhead.com/quest=1052
SET @ID := 1052;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién va? ¿Qué quieres de mí?', 0),
(@ID, 'esMX', '¿Quién va? ¿Qué quieres de mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El hermano Antón sigue divulgando la palabra de la Cruzada Escarlata? ¡Madre mía!', 0),
(@ID, 'esMX', '¿El hermano Antón sigue divulgando la palabra de la Cruzada Escarlata? ¡Madre mía!', 0);
-- 1440 Regresa junto a Vahlarriel
-- https://es.classic.wowhead.com/quest=1440
SET @ID := 1440;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Dalinda llegó sana y salva a Punta de Nijel y en mejores condiciones de lo que cabría haber esperado. El hecho de que llegara hasta aquí en pleno control de su poder y sus facultades es una buena señal. Espero que tú estés bien.$B$BMe duele pensar que Tyranis y Dalinda no han regresado juntos, pero sobre todo me pesa que ella tenga que soportar la vergüenza de las decisiones que tomó Tyranis. Es algo con lo que tendrá que enfrentarse cuando regrese a Darnassus.', 0),
(@ID, 'esMX', 'Gracias, $n. Dalinda llegó sana y salva a Punta de Nijel y en mejores condiciones de lo que cabría haber esperado. El hecho de que llegara hasta aquí en pleno control de su poder y sus facultades es una buena señal. Espero que tú estés bien.$B$BMe duele pensar que Tyranis y Dalinda no han regresado juntos, pero sobre todo me pesa que ella tenga que soportar la vergüenza de las decisiones que tomó Tyranis. Es algo con lo que tendrá que enfrentarse cuando regrese a Darnassus.', 0);
-- 5561 El rodeo kodo
-- https://es.wowhead.com/quest=5561
SET @ID := 5561;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caravana llegará dentro de nada. ¿Tienes los kodos domados que necesito?', 0),
(@ID, 'esMX', 'La caravana llegará dentro de nada. ¿Tienes los kodos domados que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Smeed Mezclatornillos empieza a contar.>$B$BTres, excelente. Pedí 3 kodos domados y 3 kodos domados tengo. Voy a ser rico, ¡muy, muy rico! ¡Qué ganas de ver la cara que se le quedará a Bibbly cuando se entere de mi éxito! ¡Se pondrá verde!', 0),
(@ID, 'esMX', '<Smeed Mezclatornillos empieza a contar.>$B$BTres, excelente. Pedí 3 kodos domados y 3 kodos domados tengo. Voy a ser rico, ¡muy, muy rico! ¡Qué ganas de ver la cara que se le quedará a Bibbly cuando se entere de mi éxito! ¡Se pondrá verde!', 0);
-- 1375 Khan Shaka
-- https://es.classic.wowhead.com/quest=1375
SET @ID := 1375;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz tareas para los Magram, y te ayudaré.', 0),
(@ID, 'esMX', 'Haz tareas para los Magram, y te ayudaré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Khan Shaka está muerto! ¡Colocaré su cabeza en una pica y la guardaré conmigo para que Shaka pueda ver la fuerza del Magram!', 0),
(@ID, 'esMX', '¡Khan Shaka está muerto! ¡Colocaré su cabeza en una pica y la guardaré conmigo para que Shaka pueda ver la fuerza del Magram!', 0);
-- 1381 Khan Hratha
-- https://es.classic.wowhead.com/quest=1381
SET @ID := 1381;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz lo que te pido. ¡Demuéstrame que eres un aliado de los Magram!', 0),
(@ID, 'esMX', 'Haz lo que te pido. ¡Demuéstrame que eres un aliado de los Magram!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Khan Hratha está muerto! ¡Ahora los Magram son los centauros más fuertes ¡Aplastaremos a los demás y dominaremos Desolace!$B$BTe recordaremos, $n, y te libraremos de nuestros cascos cuando todos los demás sean pisoteados.', 0),
(@ID, 'esMX', '¡Khan Hratha está muerto! ¡Ahora los Magram son los centauros más fuertes ¡Aplastaremos a los demás y dominaremos Desolace!$B$BTe recordaremos, $n, y te libraremos de nuestros cascos cuando todos los demás sean pisoteados.', 0);
