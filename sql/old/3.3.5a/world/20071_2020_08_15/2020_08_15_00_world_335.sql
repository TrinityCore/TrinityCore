-- 263 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=263
SET @ID := 263;
UPDATE `quest_template_locale` SET `Details` = 'Los Montaraces me dicen que eres valiente y capaz, $n. Nos hace falta $gun:una; $r como tú por aquí. La situación con los Troggs no mejora. La reserva está en combate; estamos solos. Pero con tu experiencia como $c, la cosa va a cambiar.$B$BLiquida a 10 Chamanes Rompecantos y a 10 Cascahuesos Rompecantos.$B$BA ver si los Troggs aprenden a temer tu reputación, Mata-Troggs.', `Objectives` = 'El Montaraz Muroplof, de la torre de vigilancia sur, quiere que mates a 10 Chamanes Rompecantos y a 10 Cascahuesos Rompecantos.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De vuelta tan pronto? En caso de que no te haya quedado claro, necesitamos que mates a 10 Chamanes Rompecantos y 10 Rompehuesos Rompecantos, $N. ¡Ahora ve a buscarlos, Mata-Troggs!', 0),
(@ID, 'esMX', '¿De vuelta tan pronto? En caso de que no te haya quedado claro, necesitamos que mates a 10 Chamanes Rompecantos y 10 Rompehuesos Rompecantos, $N. ¡Ahora ve a buscarlos, Mata-Troggs!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo supe en cuanto te vi, $n. Sabía que Forjaz se enorgullecería de ti. Has servido bien al Rey Magni. Ahora que has demostrado ser $gun:una; ayudante leal del reino, quizás deberías hablar con el capitán para que te confíe más detalles.$B$BTe saludo, $n.', 0),
(@ID, 'esMX', 'Lo supe en cuanto te vi, $n. Sabía que Forjaz se enorgullecería de ti. Has servido bien al Rey Magni. Ahora que has demostrado ser $gun:una; ayudante leal del reino, quizás deberías hablar con el capitán para que te confíe más detalles.$B$BTe saludo, $n.', 0);
-- 217 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=217
SET @ID := 217;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Grawmug y sus dos guardias, Rechín y Camorrista, todavía están vivos. Tu misión no estará completa hasta que los 3 hayan muerto. El imperio enano cuenta contigo, $n.', 0),
(@ID, 'esMX', 'Grawmug y sus dos guardias, Rechín y Camorrista, todavía están vivos. Tu misión no estará completa hasta que los 3 hayan muerto. El imperio enano cuenta contigo, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Gracias por eliminar a Gromug; ahora tenemos más posibilidades de erradicar a los troggs.', 0),
(@ID, 'esMX', '¡Excelente, $n! Gracias por eliminar a Gromug; ahora tenemos más posibilidades de erradicar a los troggs.', 0);
-- 314 La protección del rebaño
-- https://es.classic.wowhead.com/quest=314
SET @ID := 314;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vagash sigue aterrorizando al ganado! Ayúdanos, por favor, ¡mata a esa maldita bestia!', 0),
(@ID, 'esMX', '¡Vagash sigue aterrorizando al ganado! Ayúdanos, por favor, ¡mata a esa maldita bestia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien hecho! Veron se pondrá muy contento cuando oiga la noticia. Matar a Vagash no es tarea fácil. Imagino que un día combatirás en el frente de la Alianza, entre los hombres del rey Magni.', 0),
(@ID, 'esMX', '¡Muy bien hecho! Veron se pondrá muy contento cuando oiga la noticia. Matar a Vagash no es tarea fácil. Imagino que un día combatirás en el frente de la Alianza, entre los hombres del rey Magni.', 0);
-- 2160 Suministros para Tannok
-- https://es.classic.wowhead.com/quest=2160
SET @ID := 2160;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, sé $gbienvenido:bienvenida;! Venga, siéntate junto al fuego y entra en calor con una jarra de cerveza.', 0),
(@ID, 'esMX', '¡Eh, sé $gbienvenido:bienvenida;! Venga, siéntate junto al fuego y entra en calor con una jarra de cerveza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, por fin! ¡Los suministros! Empezaba a preocuparme. Hemos tenido pocas noticias de Yunquemar desde que los troggs se hicieron con el paso.$B$BGracias por traerme esto, $n. Te lo ruego, ponte $gcómodo:cómoda;. Debes de estar $gcansado:cansada; del viaje.', 0),
(@ID, 'esMX', '¡Ah, por fin! ¡Los suministros! Empezaba a preocuparme. Hemos tenido pocas noticias de Yunquemar desde que los troggs se hicieron con el paso.$B$BGracias por traerme esto, $n. Te lo ruego, ponte $gcómodo:cómoda;. Debes de estar $gcansado:cansada; del viaje.', 0);
-- 179 Los enanos modistos
-- https://es.classic.wowhead.com/quest=179
SET @ID := 179;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Los lobos te están dando problemillas? Ya sabes que tienes que evitar colmillos y patas y otras cosas afiladas, ¿verdad?', 0),
(@ID, 'esMX', '¿Qué? ¿Los lobos te están dando problemillas? Ya sabes que tienes que evitar colmillos y patas y otras cosas afiladas, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Estupendo. Esta carne de lobo me vendrá muy bien. Oh, no te preocupes, $n, no he olvidado mi parte del trato. Ten, alguno de estos debería valerte.', 0),
(@ID, 'esMX', '¡Ah! Estupendo. Esta carne de lobo me vendrá muy bien. Oh, no te preocupes, $n, no he olvidado mi parte del trato. Ten, alguno de estos debería valerte.', 0);
-- 233 Entrega de correo en el Valle de Crestanevada
-- https://es.classic.wowhead.com/quest=233
SET @ID := 233;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Sí? ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, llevo un tiempo esperando estas cartas...$B$BPor desgracia, no son todas para mí. Esta es para Grelin Barbablanca. No está muy lejos de aquí. Si quieres entregársela...', 0),
(@ID, 'esMX', 'Gracias, llevo un tiempo esperando estas cartas...$B$BPor desgracia, no son todas para mí. Esta es para Grelin Barbablanca. No está muy lejos de aquí. Si quieres entregársela...', 0);
-- 170 Una nueva amenaza
-- https://es.classic.wowhead.com/quest=170
SET @ID := 170;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenaces pequeños bichos, ¿no son?', 0),
(@ID, 'esMX', 'Tenaces pequeños bichos, ¿no son?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los problemas que hemos tenido aquí son una muestra de lo que está ocurriendo en el resto de nuestra tierra, ¡tendremos muchos problemas! Solo puedo esperar que el Rey y el Senado estén tomando medidas para acabar con la amenaza que los troggs representan.', 0),
(@ID, 'esMX', 'Si los problemas que hemos tenido aquí son una muestra de lo que está ocurriendo en el resto de nuestra tierra, ¡tendremos muchos problemas! Solo puedo esperar que el Rey y el Senado estén tomando medidas para acabar con la amenaza que los troggs representan.', 0);
-- 3361 Las penurias de un refugiado
-- https://es.classic.wowhead.com/quest=3361
SET @ID := 3361;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es terrible, $n, esta ciudad no es adecuada para individuos como yo. ¡Hay tantas criaturas horribles aquí como en Gnomeregan antes del accidente!$B$B¿Tienes mis pertenencias? Si no es así, quién sabe lo que los trols habrán hecho con ellas a esta altura...', 0),
(@ID, 'esMX', 'Esto es terrible, $n, esta ciudad no es adecuada para individuos como yo. ¡Hay tantas criaturas horribles aquí como en Gnomeregan antes del accidente!$B$B¿Tienes mis pertenencias? Si no es así, quién sabe lo que los trols habrán hecho con ellas a esta altura...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hurra, los has encontrado! Eres todo un salvador. Toma, no es mucho, pero acéptalo por los problemas que te he causado. ¡Gracias!', 0),
(@ID, 'esMX', '¡Hurra, los has encontrado! Eres todo un salvador. Toma, no es mucho, pero acéptalo por los problemas que te he causado. ¡Gracias!', 0);
-- 183 Cazador de jabalíes
-- https://es.classic.wowhead.com/quest=183
SET @ID := 183;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la cacería?', 0),
(@ID, 'esMX', '¿Cómo va la cacería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Ya puedo volver a mi caza diaria tranquilamente. Gracias, $n.', 0),
(@ID, 'esMX', '¡Fantástico! Ya puedo volver a mi caza diaria tranquilamente. Gracias, $n.', 0);
-- 234 Entrega de correo en el Valle de Crestanevada
-- https://es.classic.wowhead.com/quest=234
SET @ID := 234;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', '¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aah, excelente. Hace tiempo que no recibo noticias de Forjaz.', 0),
(@ID, 'esMX', 'Aah, excelente. Hace tiempo que no recibo noticias de Forjaz.', 0);
-- 182 La cueva de los trols
-- https://es.classic.wowhead.com/quest=182
SET @ID := 182;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por lo que he aprendido, estos trolls proceden del clan Peloescarcha. Me temo que no sé mucho más sobre ellos que pueda ser de utilidad para ti, $n.', 0),
(@ID, 'esMX', 'Por lo que he aprendido, estos trolls proceden del clan Peloescarcha. Me temo que no sé mucho más sobre ellos que pueda ser de utilidad para ti, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Argh! ¡Malditos trols, la Luz los maldiga!$B$B<Grelin respira profundamente y se calma... un poco.>$B$B¡Un grupo de ellos vino por la noche y se llevó mi diario! Sabía que no debía confiar en ese bueno para nada de...', 0),
(@ID, 'esMX', '¡Argh! ¡Malditos trols, la Luz los maldiga!$B$B<Grelin respira profundamente y se calma... un poco.>$B$B¡Un grupo de ellos vino por la noche y se llevó mi diario! Sabía que no debía confiar en ese bueno para nada de...', 0);
-- 3364 Entrega una infusión de albaza hirviendo
-- https://es.classic.wowhead.com/quest=3364
SET @ID := 3364;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, soy Durnan Cortapieles. ¿Tienes algo para mí?', 0),
(@ID, 'esMX', 'Sí, soy Durnan Cortapieles. ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, qué bien me va a sentar esto! Deja que me tome un descansito mientras disfruto esta infusión de albaza hirviendo.', 0),
(@ID, 'esMX', '¡Oh, qué bien me va a sentar esto! Deja que me tome un descansito mientras disfruto esta infusión de albaza hirviendo.', 0);
-- 218 El diario robado
-- https://es.classic.wowhead.com/quest=218
SET @ID := 218;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Estoy muy agradecido por recuperar mi cuaderno. Bueno, parece que la situación con los trols aquí en el Valle de Crestanevada está bajo control y no hay por qué preocuparse.$B$BDespués de incluir los últimos detalles en mi informe, necesitaré que alguien se lo lleve a mi hermano Senir.', 0),
(@ID, 'esMX', '¡Excelente, $n! Estoy muy agradecido por recuperar mi cuaderno. Bueno, parece que la situación con los trols aquí en el Valle de Crestanevada está bajo control y no hay por qué preocuparse.$B$BDespués de incluir los últimos detalles en mi informe, necesitaré que alguien se lo lleve a mi hermano Senir.', 0);
-- 282 Las observaciones de Senir
-- https://es.classic.wowhead.com/quest=282
SET @ID := 282;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos! Ten cuidado, $n, el túnel de Dun Morogh está infestado de troggs. No es seguro atravesarlo.$B$BSi no tienes asuntos urgentes en Dun Morogh, te aconsejo que te quedes en Yunquemar hasta que el túnel sea más seguro.', 0),
(@ID, 'esMX', '¡Saludos! Ten cuidado, $n, el túnel de Dun Morogh está infestado de troggs. No es seguro atravesarlo.$B$BSi no tienes asuntos urgentes en Dun Morogh, te aconsejo que te quedes en Yunquemar hasta que el túnel sea más seguro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, bueno, si Barbablanca te ha mandado a Dun Morogh para asuntos importantes, yo no puedo detenerte, ¿no?$B$BDeja que te dé algún consejo e indicaciones.', 0),
(@ID, 'esMX', 'Mm, bueno, si Barbablanca te ha mandado a Dun Morogh para asuntos importantes, yo no puedo detenerte, ¿no?$B$BDeja que te dé algún consejo e indicaciones.', 0);
-- 3365 Devuelve la jarra
-- https://es.classic.wowhead.com/quest=3365
SET @ID := 3365;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que la infusión de albaza le llegara caliente a Durnan! ¿Te has acordado de traerme mi taza?', 0),
(@ID, 'esMX', '¡Espero que la infusión de albaza le llegara caliente a Durnan! ¿Te has acordado de traerme mi taza?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Te sorprendería saber la cantidad de mensajeros que conozco que olvidan hacer algo tan simple como devolver una taza. ¡Y las tazas no crecen en los árboles, o eso dicen!$B$BAquí tienes algo para premiar tu esfuerzo. Y gracias de nuevo por tu ayuda.', 0),
(@ID, 'esMX', '¡Excelente, $n! Te sorprendería saber la cantidad de mensajeros que conozco que olvidan hacer algo tan simple como devolver una taza. ¡Y las tazas no crecen en los árboles, o eso dicen!$B$BAquí tienes algo para premiar tu esfuerzo. Y gracias de nuevo por tu ayuda.', 0);
-- 420 Las observaciones de Senir
-- https://es.classic.wowhead.com/quest=420
SET @ID := 420;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo estás? ¿Te apetece tomarte algo conmigo? No es que haya mucho más que hacer con este frío.', 0),
(@ID, 'esMX', '¿Cómo estás? ¿Te apetece tomarte algo conmigo? No es que haya mucho más que hacer con este frío.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso? Ah, el informe de mi hermano. Mmm...$B$BLe dije que moderara el uso del nombre del Rey, pero no me ha hecho caso. Supongo que no hará daño a nadie, pero sí que va a erizar alguna que otra pluma en el Senado. ¡Y no vendrá nada mal, no creas! ¡Ja, ja!$B$BEn fin, supongo que yo debería enviar mi informe a Forjaz también, pero la verdad es que voy un poco atrasado. Maldito frío.$B$BSi te interesa, más tarde podría tener trabajo para ti.', 0),
(@ID, 'esMX', '¿Qué es eso? Ah, el informe de mi hermano. Mmm...$B$BLe dije que moderara el uso del nombre del Rey, pero no me ha hecho caso. Supongo que no hará daño a nadie, pero sí que va a erizar alguna que otra pluma en el Senado. ¡Y no vendrá nada mal, no creas! ¡Ja, ja!$B$BEn fin, supongo que yo debería enviar mi informe a Forjaz también, pero la verdad es que voy un poco atrasado. Maldito frío.$B$BSi te interesa, más tarde podría tener trabajo para ti.', 0);
-- 287 Poblado Peloescarcha
-- https://es.classic.wowhead.com/quest=287
SET @ID := 287;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No puedes encontrarlo? ¡Mis instrucciones fueron muy claras! No tenemos mucho tiempo, ¡hay que darse prisa! No regreses hasta que hayas encontrado la cueva.', 0),
(@ID, 'esMX', '¿No puedes encontrarlo? ¡Mis instrucciones fueron muy claras! No tenemos mucho tiempo, ¡hay que darse prisa! No regreses hasta que hayas encontrado la cueva.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, $n! Pensé que no tendrías problemas para encontrar el lugar, doy excelentes indicaciones, ya me entiendes...$B$BDeja que acabe mi informe.', 0),
(@ID, 'esMX', '¡Ah, $n! Pensé que no tendrías problemas para encontrar el lugar, doy excelentes indicaciones, ya me entiendes...$B$BDeja que acabe mi informe.', 0);
-- 291 Los informes
-- https://es.classic.wowhead.com/quest=291
SET @ID := 291;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya... Menos mal que dije a los guardias que no dejaran pasar mendigos... ¿Y bien? ¿Qué quieres? Habla rápido.', 0),
(@ID, 'esMX', 'Vaya... Menos mal que dije a los guardias que no dejaran pasar mendigos... ¿Y bien? ¿Qué quieres? Habla rápido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Examina rápidamente el informe.>$B$B¡¿Autoridad del REY?! ¡Magni ha perdido totalmente la cabeza! Y ese maldito Barbablanca... Se ha encargado del asunto en persona, ¿eh? Al Senado no le gustará oír esto. Ni una pizca.$B$B¿Pero aún estás aquí? ¡Vete antes de que llame a la guardia!', 0),
(@ID, 'esMX', '<Examina rápidamente el informe.>$B$B¡¿Autoridad del REY?! ¡Magni ha perdido totalmente la cabeza! Y ese maldito Barbablanca... Se ha encargado del asunto en persona, ¿eh? Al Senado no le gustará oír esto. Ni una pizca.$B$B¿Pero aún estás aquí? ¡Vete antes de que llame a la guardia!', 0);
-- 469 Entrega cotidiana
-- https://es.classic.wowhead.com/quest=469
SET @ID := 469;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Estarías interesado en un par de botas? ¿Quizás en algunas pieles recién curtidas?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Estarías interesado en un par de botas? ¿Quizás en algunas pieles recién curtidas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ummm... esto es de parte de Einar, ¿verdad? No ha venido a darme sus pieles en persona desde hace casi una semana. ¡Tendrá otra vez problemas con su mujer!$B$BMe parece que tendré que mandar a mi esposa a hablar con Shida...', 0),
(@ID, 'esMX', 'Ummm... esto es de parte de Einar, ¿verdad? No ha venido a darme sus pieles en persona desde hace casi una semana. ¡Tendrá otra vez problemas con su mujer!$B$BMe parece que tendré que mandar a mi esposa a hablar con Shida...', 0);
