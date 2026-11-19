-- 1020 Cura de Orendil
-- https://es.classic.wowhead.com/quest=1020
SET @ID := 1020;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis disculpas, no tengo tiempo para hablar. Mi hija, Relara, ¡está gravemente enferma!', 0),
(@ID, 'esMX', 'Mis disculpas, no tengo tiempo para hablar. Mi hija, Relara, ¡está gravemente enferma!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Esto es de Orendil?$B$BTiene un gran talento con hierbas y curaciones. Esta cura me da esperanza, antes de tomar un poco...', 0),
(@ID, 'esMX', '¿Esto es de Orendil?$B$BTiene un gran talento con hierbas y curaciones. Esta cura me da esperanza, antes de tomar un poco...', 0);
-- 973 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=973
SET @ID := 973;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces $ginquieto:inquieta;, $n. ¿Te encuentras bien?', 0),
(@ID, 'esMX', 'Pareces $ginquieto:inquieta;, $n. ¿Te encuentras bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy has hecho algo grande, $n. Puedes sentirte $gorgulloso:orgullosa; de haberte enfrentado a tan poderoso brujo.$B$BAhora, veamos qué podemos averiguar en los escritos de Ilkrud.', 0),
(@ID, 'esMX', 'Hoy has hecho algo grande, $n. Puedes sentirte $gorgulloso:orgullosa; de haberte enfrentado a tan poderoso brujo.$B$BAhora, veamos qué podemos averiguar en los escritos de Ilkrud.', 0);
-- 1134 Alaorgullo del Espolón
-- https://es.classic.wowhead.com/quest=1134
SET @ID := 1134;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los sacos de veneno de alaorgullo, $n? No podemos permitir que los orcos utilicen el veneno de esas bestias contra nosotros.', 0),
(@ID, 'esMX', '¿Tienes los sacos de veneno de alaorgullo, $n? No podemos permitir que los orcos utilicen el veneno de esas bestias contra nosotros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Me entristece ordenar matar a criaturas que no quieren ayudar voluntariamente a nuestro enemigo, pero es mi deber hacerlo.$B$BTu corazón puede llorar por los alaorgullo que has matado, pero también debería estar henchido de orgullo al saber que tus aliados están a salvo del veneno de alaorgullo.', 0),
(@ID, 'esMX', 'Gracias, $n. Me entristece ordenar matar a criaturas que no quieren ayudar voluntariamente a nuestro enemigo, pero es mi deber hacerlo.$B$BTu corazón puede llorar por los alaorgullo que has matado, pero también debería estar henchido de orgullo al saber que tus aliados están a salvo del veneno de alaorgullo.', 0);
-- 1024 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1024
SET @ID := 1024;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. ¿Qué tal?', 0),
(@ID, 'esMX', 'Hola. ¿Qué tal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Raene? Entonces será grave. ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¿Te envía Raene? Entonces será grave. ¿En qué puedo ayudarte?', 0);
-- 1025 Una defensa agresiva
-- https://es.classic.wowhead.com/quest=1025
SET @ID := 1025;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los fúrbolg no siempre fueron nuestro enemigo, $n. Pero los tiempos cambian y ya no es un momento de paz aquí en estos bosques oscuros.', 0),
(@ID, 'esMX', 'Los fúrbolg no siempre fueron nuestro enemigo, $n. Pero los tiempos cambian y ya no es un momento de paz aquí en estos bosques oscuros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Gracias.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Gracias.', 0);
-- 1033 Lágrima de Elune
-- https://es.classic.wowhead.com/quest=1033
SET @ID := 1033;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has encontrado el Lago Iris? ¿Tienes la Lágrima?', 0),
(@ID, 'esMX', '$n, ¿has encontrado el Lago Iris? ¿Tienes la Lágrima?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, la encontraste! Colocaré la lágrima en un guiso y rezaré para que la cure.$B$B¡Gracias! ¡Gracias, $n!', 0),
(@ID, 'esMX', '¡Vaya, la encontraste! Colocaré la lágrima en un guiso y rezaré para que la cure.$B$B¡Gracias! ¡Gracias, $n!', 0);
-- 1034 Las Ruinas del Polvo Estelar
-- https://es.classic.wowhead.com/quest=1034
SET @ID := 1034;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya el polvo estelar, $n?', 0),
(@ID, 'esMX', '¿Tienes ya el polvo estelar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido el polvo! Con él prepararé una cataplasma, eso debería bajar la fiebre de Relara.$B$BGracias otra vez, $n. Sin tu ayuda, mi hija habría perecido.', 0),
(@ID, 'esMX', '¡Has conseguido el polvo! Con él prepararé una cataplasma, eso debería bajar la fiebre de Relara.$B$BGracias otra vez, $n. Sin tu ayuda, mi hija habría perecido.', 0);
-- 1035 Lago Cielo Estrellado
-- https://es.classic.wowhead.com/quest=1035
SET @ID := 1035;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has enfrentado ya al Oráculo de Sombramatorral, $n? De ser así, te ruego me entregues la piedra lunar caída. ¡A Relara le quedan fuerzas para unos suspiros más!', 0),
(@ID, 'esMX', '¿Te has enfrentado ya al Oráculo de Sombramatorral, $n? De ser así, te ruego me entregues la piedra lunar caída. ¡A Relara le quedan fuerzas para unos suspiros más!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, $n, ¡has salvado a mi hija! ¡Sé que el poder de la piedra lunar le devolverá las fuerzas!$B$BNunca podré pagarte por lo que has hecho pero... te ruego aceptes esto. Aparte de Relara, es mi más preciada posesión.', 0),
(@ID, 'esMX', 'Oh, $n, ¡has salvado a mi hija! ¡Sé que el poder de la piedra lunar le devolverá las fuerzas!$B$BNunca podré pagarte por lo que has hecho pero... te ruego aceptes esto. Aparte de Relara, es mi más preciada posesión.', 0);
-- 1140 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=1140
SET @ID := 1140;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez escuché susurrar que la historia de los sátiros está relacionada de alguna manera con la de los elfos de la noche, pero mis estimados anfitriones son reticentes a hablar del asunto.', 0),
(@ID, 'esMX', 'Una vez escuché susurrar que la historia de los sátiros está relacionada de alguna manera con la de los elfos de la noche, pero mis estimados anfitriones son reticentes a hablar del asunto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás a los sátiros se les ha permitido permanecer en el bosque durante demasiado tiempo. Hablaré con Elissa al respecto la próxima vez que viaje a Auberdine.$B$BNo obstante, con las gemas del alma destruidas, el poder de Athrikus disminuirá considerablemente. Debemos aprovechar esta oportunidad para eliminarlo a él y a su culto.', 0),
(@ID, 'esMX', 'Quizás a los sátiros se les ha permitido permanecer en el bosque durante demasiado tiempo. Hablaré con Elissa al respecto la próxima vez que viaje a Auberdine.$B$BNo obstante, con las gemas del alma destruidas, el poder de Athrikus disminuirá considerablemente. Debemos aprovechar esta oportunidad para eliminarlo a él y a su culto.', 0);
-- 976 Suministros a Auberdine
-- https://es.classic.wowhead.com/quest=976
SET @ID := 976;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las Centinelas tienen una gran necesidad de suministros para reforzarse en Costa Oscura.', 0),
(@ID, 'esMX', 'Las Centinelas tienen una gran necesidad de suministros para reforzarse en Costa Oscura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien hoy, $c. Los artículos que enviamos para ayudar a Auberdine serán de utilidad inmediata para hacer frente a las oscuras amenazas que infestan el bosque.$B$BToma esto con mi más sincero agradecimiento.', 0),
(@ID, 'esMX', 'Lo has hecho bien hoy, $c. Los artículos que enviamos para ayudar a Auberdine serán de utilidad inmediata para hacer frente a las oscuras amenazas que infestan el bosque.$B$BToma esto con mi más sincero agradecimiento.', 0);
-- 1026 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1026
SET @ID := 1026;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me indigna que los antárboles se hayan corrompido. Ojalá pudiera hacer más por ayudarlos.', 0),
(@ID, 'esMX', 'Me indigna que los antárboles se hayan corrompido. Ojalá pudiera hacer más por ayudarlos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que hayas vuelto, $n.', 0),
(@ID, 'esMX', 'Me alegra que hayas vuelto, $n.', 0);
-- 1167 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=1167
SET @ID := 1167;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, es bueno verte de nuevo, $n! Las cosas más extrañas han estado sucediendo por aquí, ¡me alegro de que aparecieras!$B$BFue muy extraño, $n. Todo parecía normal, bueno, tan normal como se ponen las cosas por aquí, y de repente hubo un destello de luz cegadora desde la habitación superior de la torre. Luego vinieron los gritos. Los gritos partieron el aire y los relámpagos golpearon el suelo una y otra vez. ¿Que esta pasando?', 0),
(@ID, 'esMX', '¡Ah, es bueno verte de nuevo, $n! Las cosas más extrañas han estado sucediendo por aquí, ¡me alegro de que aparecieras!$B$BFue muy extraño, $n. Todo parecía normal, bueno, tan normal como se ponen las cosas por aquí, y de repente hubo un destello de luz cegadora desde la habitación superior de la torre. Luego vinieron los gritos. Los gritos partieron el aire y los relámpagos golpearon el suelo una y otra vez. ¿Que esta pasando?', 0);
-- 943 El prospector despistado
-- https://es.classic.wowhead.com/quest=943
SET @ID := 943;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la Piedra de Relu podré desvelar los secretos de mi fósil así como del fósil de Costa Oscura de Tripirrem, $n.', 0),
(@ID, 'esMX', 'Con la Piedra de Relu podré desvelar los secretos de mi fósil así como del fósil de Costa Oscura de Tripirrem, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n!$B$BAhora hay que ver si puedo utilizar la piedra para descubrir los poderes de los fósiles.', 0),
(@ID, 'esMX', '¡Excelente, $n!$B$BAhora hay que ver si puedo utilizar la piedra para descubrir los poderes de los fósiles.', 0);
-- 2988 Las jaulas de Secacorteza
-- https://es.classic.wowhead.com/quest=2988
SET @ID := 2988;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has registrado las jaulas, $n? ¡Debemos encontrar a Picoafilado!', 0),
(@ID, 'esMX', '¿Has registrado las jaulas, $n? ¡Debemos encontrar a Picoafilado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que no has encontrado a Picoafilado? Eso es una mala noticia; es el jefe de la futura generación de grifos. Sin él se perderá gran parte de su fuerza y empuje.', 0),
(@ID, 'esMX', '¿Que no has encontrado a Picoafilado? Eso es una mala noticia; es el jefe de la futura generación de grifos. Sin él se perderá gran parte de su fuerza y empuje.', 0);
-- 1452 El cubata de Kalimdor de Rapsodio
-- https://es.classic.wowhead.com/quest=1452
SET @ID := 1452;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna vez has probado una Malta Rapsódica? Una de mis mejores cervezas, si lo digo yo mismo. ¡Hip!$B$BPero si voy a revivir los horrores de ese fatídico vuelo sobre... ¡Hip!... el pantano, bueno, voy a necesitar algo un poquito más fuerte. ¡Hip!$B$B¿Crees que me encontrarás esas mollejas e hígados que necesito para agregar ese pelotazo extra a mi cubata de Kalimdor?$B$B¡Hip!', 0),
(@ID, 'esMX', '¿Alguna vez has probado una Malta Rapsódica? Una de mis mejores cervezas, si lo digo yo mismo. ¡Hip!$B$BPero si voy a revivir los horrores de ese fatídico vuelo sobre... ¡Hip!... el pantano, bueno, voy a necesitar algo un poquito más fuerte. ¡Hip!$B$B¿Crees que me encontrarás esas mollejas e hígados que necesito para agregar ese pelotazo extra a mi cubata de Kalimdor?$B$B¡Hip!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veo que no has tenido ningún problema en conseguirme lo que necesito! Te lo has tomado con calma allí en la lejana Kalimdor.$B$BNo me tomará más que un momento extraer lo que necesito de estas mollejas e hígados. ¡Hip!$B$BAhora puedo preparame un trago feroz y finalmente decirte lo que quieres saber.$B$B¡Hip!$B$BMe da escalofríos solo de pensar en ese viejo pantano.$B$B¡Hip!$B$BDéjame preparar un trago muy rápido.', 0),
(@ID, 'esMX', '¡Veo que no has tenido ningún problema en conseguirme lo que necesito! Te lo has tomado con calma allí en la lejana Kalimdor.$B$BNo me tomará más que un momento extraer lo que necesito de estas mollejas e hígados. ¡Hip!$B$BAhora puedo preparame un trago feroz y finalmente decirte lo que quieres saber.$B$B¡Hip!$B$BMe da escalofríos solo de pensar en ese viejo pantano.$B$B¡Hip!$B$BDéjame preparar un trago muy rápido.', 0);
-- 1469 El relato de Rapsodio
-- https://es.classic.wowhead.com/quest=1469
SET @ID := 1469;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin has vuelto, $n. Ha pasado bastante tiempo desde la última vez que hablamos. Pensé que tal vez te habías olvidado de mi búsqueda.$B$B¿Localizaste a ese astuto jinete de grifos? ¿Tenía algo que informar?', 0),
(@ID, 'esMX', 'Por fin has vuelto, $n. Ha pasado bastante tiempo desde la última vez que hablamos. Pensé que tal vez te habías olvidado de mi búsqueda.$B$B¿Localizaste a ese astuto jinete de grifos? ¿Tenía algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Rapsodio Machacacanillas! Así es... ¿cómo pude olvidar ese nombre?$B$B¿Entonces él sabía sobre el hundimiento del templo todo el tiempo? Bueno, eso ciertamente te habría ahorrado algo de trabajo.$B$B¡Pero este artefacto de Atal\'ai! ¡Es todo un descubrimiento!', 0),
(@ID, 'esMX', '¡Rapsodio Machacacanillas! Así es... ¿cómo pude olvidar ese nombre?$B$B¿Entonces él sabía sobre el hundimiento del templo todo el tiempo? Bueno, eso ciertamente te habría ahorrado algo de trabajo.$B$B¡Pero este artefacto de Atal\'ai! ¡Es todo un descubrimiento!', 0);
-- 8262 Botiquín avanzado de Arathor
-- https://es.classic.wowhead.com/quest=8262
SET @ID := 8262;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. Como recompensa, llévate este botiquín. En su interior encontrarás raciones y vendajes que solo se pueden utilizar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando tu valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(@ID, 'esMX', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. Como recompensa, llévate este botiquín. En su interior encontrarás raciones y vendajes que solo se pueden utilizar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando tu valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0);
-- 642 La princesa encerrada
-- https://es.classic.wowhead.com/quest=642
SET @ID := 642;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este bloque de fragmentos se parece mucho a los fragmentos de Myzrael. Pero no late en ellos el mismo sentimiento de seguridad.', 0),
(@ID, 'esMX', 'Este bloque de fragmentos se parece mucho a los fragmentos de Myzrael. Pero no late en ellos el mismo sentimiento de seguridad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Has activado estos fragmentos. ¡Ya empiezo a sentirme como antes!$B$BAunque ¡qué lejos estoy aún de la liberación!', 0),
(@ID, 'esMX', '¡Ah! Has activado estos fragmentos. ¡Ya empiezo a sentirme como antes!$B$BAunque ¡qué lejos estoy aún de la liberación!', 0);
-- 651 Piedras de Vínculo
-- https://es.classic.wowhead.com/quest=651
SET @ID := 651;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta es la Piedra de Vínculo Interior. Es la más fuerte de las piedras de vínculo y hay que desbloquearla para abrir las otras.', 0),
(@ID, 'esMX', 'Esta es la Piedra de Vínculo Interior. Es la más fuerte de las piedras de vínculo y hay que desbloquearla para abrir las otras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Myzrael habla a través de la piedra.>$B$B¡Lo has logrado! ¡Has abierto las Piedras de vínculo! Siento cómo los grilletes se sueltan y la libertad se acerca.$B$BComo $c, eres muy noble, $n. ¡Mi $gsalvador:salvadora;!', 0),
(@ID, 'esMX', '<Myzrael habla a través de la piedra.>$B$B¡Lo has logrado! ¡Has abierto las Piedras de vínculo! Siento cómo los grilletes se sueltan y la libertad se acerca.$B$BComo $c, eres muy noble, $n. ¡Mi $gsalvador:salvadora;!', 0);
-- 652 Desbloquear la piedra angular
-- https://es.classic.wowhead.com/quest=652
SET @ID := 652;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La piedra angular está cargada de energía geomántica.', 0),
(@ID, 'esMX', 'La piedra angular está cargada de energía geomántica.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas la vara en la piedra angular. Y sientes cómo el suelo tiembla bajo tus pies...', 0),
(@ID, 'esMX', 'Colocas la vara en la piedra angular. Y sientes cómo el suelo tiembla bajo tus pies...', 0);
-- 653 Aliados de Myzrael
-- https://es.classic.wowhead.com/quest=653
SET @ID := 653;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Señora me avisó de tu visita, $c. Te doy la bienvenida en mi morada ya que tú, al igual que yo, estás al servicio de una más alta causa.', 0),
(@ID, 'esMX', 'La Señora me avisó de tu visita, $c. Te doy la bienvenida en mi morada ya que tú, al igual que yo, estás al servicio de una más alta causa.', 0);
