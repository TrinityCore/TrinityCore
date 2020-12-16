-- 372 En guerra con la Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=372
SET @ID := 372;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '', 0),
(@ID, 'esMX', '', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy, muy bien, $n. Con $gluchadores despiadados:luchadoras despiadadas; como tú actuando en nombre de los Renegados, nuestra raza está cada vez más cerca de derrotar a Arthas de una vez por todas. Tengo un buen presentimiento respecto a ti, camarada.', 0),
(@ID, 'esMX', 'Lo has hecho muy, muy bien, $n. Con $gluchadores despiadados:luchadoras despiadadas; como tú actuando en nombre de los Renegados, nuestra raza está cada vez más cerca de derrotar a Arthas de una vez por todas. Tengo un buen presentimiento respecto a ti, camarada.', 0);
-- 373 La carta sin enviar
-- https://es.classic.wowhead.com/quest=373
SET @ID := 373;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', '¿Sí? ¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Edwin VanCleef, dices? Sería como recibir una carta de mi abuela muerta... ¿Así que le has matado? Perdona que te lo diga, pero me sorprende bastante. En su juventud, fue un luchador incomparable. Veamos por qué decidió escribirme después de tantos años.$B$B<Baros lee detenidamente la carta.>$B$BEdwin... Veo que los años no te han cambiado, sigues siendo un idealista y un romántico. No le importa hacer daño, $n. La venganza le ha consumido. Aunque no estoy seguro de poder culparle por ello.', 0),
(@ID, 'esMX', '¿Edwin VanCleef, dices? Sería como recibir una carta de mi abuela muerta... ¿Así que le has matado? Perdona que te lo diga, pero me sorprende bastante. En su juventud, fue un luchador incomparable. Veamos por qué decidió escribirme después de tantos años.$B$B<Baros lee detenidamente la carta.>$B$BEdwin... Veo que los años no te han cambiado, sigues siendo un idealista y un romántico. No le importa hacer daño, $n. La venganza le ha consumido. Aunque no estoy seguro de poder culparle por ello.', 0);
-- 374 Prueba de defunción
-- https://es.classic.wowhead.com/quest=374
SET @ID := 374;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿has reunido ya 10 anillos con la insignia escarlata?', 0),
(@ID, 'esMX', '$c, ¿has reunido ya 10 anillos con la insignia escarlata?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Varimathras se sentiría orgulloso pues sirves con diligencia a tus líderes, $c.', 0),
(@ID, 'esMX', 'Varimathras se sentiría orgulloso pues sirves con diligencia a tus líderes, $c.', 0);
-- 375 El frío de la muerte
-- https://es.classic.wowhead.com/quest=375
SET @ID := 375;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes 5 pieles de murciumbrío y algunos hilos gruesos?', 0),
(@ID, 'esMX', '$n, ¿tienes 5 pieles de murciumbrío y algunos hilos gruesos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aprecio tus esfuerzos, $n. Ojalá Sylvanas reconozca algún día tu valentía.', 0),
(@ID, 'esMX', 'Aprecio tus esfuerzos, $n. Ojalá Sylvanas reconozca algún día tu valentía.', 0);
-- 376 Los Malditos
-- https://es.classic.wowhead.com/quest=376
SET @ID := 376;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Intenta ser prudente y no resultar $gherido:herida; hasta que te consiga una armadura.', 0),
(@ID, 'esMX', 'Intenta ser prudente y no resultar $gherido:herida; hasta que te consiga una armadura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Esta armadura te servirá de ayuda.$B$BEspero que, al menos, te dé más suerte que a su último portador...', 0),
(@ID, 'esMX', 'Gracias, $n. Esta armadura te servirá de ayuda.$B$BEspero que, al menos, te dé más suerte que a su último portador...', 0);
-- 379 Aplacar esa sed
-- https://es.classic.wowhead.com/quest=379
SET @ID := 379;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿los nómadas "se ofrecieron como voluntarios" para ti?', 0),
(@ID, 'esMX', 'Bueno, ¿los nómadas "se ofrecieron como voluntarios" para ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, la fuente de energía es tuya. Ahora, no está completamente diseñado para su uso en un kit de ciencia como ese, por lo que solo tendrá una cantidad limitada de tiempo antes de que todos los datos que recopile se vuelvan locos.$B$BCuando reúnas todo lo que necesitas para lo que sea que estés haciendo, tréemela y la apagaré correctamente. Tendrás como máximo dos horas para hacer lo que necesitas.$B$BSi no lo haces a tiempo, siempre puedo venderle otra fuente de energía para volver a intentarlo. Me escuchaste bien... ¡vender!', 0),
(@ID, 'esMX', 'Excelente, la fuente de energía es tuya. Ahora, no está completamente diseñado para su uso en un kit de ciencia como ese, por lo que solo tendrá una cantidad limitada de tiempo antes de que todos los datos que recopile se vuelvan locos.$B$BCuando reúnas todo lo que necesitas para lo que sea que estés haciendo, tréemela y la apagaré correctamente. Tendrás como máximo dos horas para hacer lo que necesitas.$B$BSi no lo haces a tiempo, siempre puedo venderle otra fuente de energía para volver a intentarlo. Me escuchaste bien... ¡vender!', 0);
-- 380 Hoya Nocturácnidas
-- https://es.classic.wowhead.com/quest=380
SET @ID := 380;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado con el veneno de las arañas, $n. Si sientes un ardor agudo, es mejor que te revisen.', 0),
(@ID, 'esMX', 'Ten cuidado con el veneno de las arañas, $n. Si sientes un ardor agudo, es mejor que te revisen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, bueno, es un comienzo. Llevará algunas semanas, o incluso meses, limpiar por completo el mal. Después de eso, tendremos que bajar ahí con algunas antorchas para quemar las telarañas.$B$BHas cumplido con tu deber, $n, seguro que encontraré algo más de trabajo para ti.', 0),
(@ID, 'esMX', 'Mmm, bueno, es un comienzo. Llevará algunas semanas, o incluso meses, limpiar por completo el mal. Después de eso, tendremos que bajar ahí con algunas antorchas para quemar las telarañas.$B$BHas cumplido con tu deber, $n, seguro que encontraré algo más de trabajo para ti.', 0);
-- 381 La Cruzada Escarlata
-- https://es.classic.wowhead.com/quest=381
SET @ID := 381;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esos insensatos... Se cavan tan contentos sus propias tumbas.', 0),
(@ID, 'esMX', 'Esos insensatos... Se cavan tan contentos sus propias tumbas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ay, si se atuvieran a razones, ¿eh, $n? Quizás podríamos sentarnos alrededor de una mesa para dialogar... ¡Ja!$B$BEsos esperpentos cegados por la Luz...', 0),
(@ID, 'esMX', 'Ay, si se atuvieran a razones, ¿eh, $n? Quizás podríamos sentarnos alrededor de una mesa para dialogar... ¡Ja!$B$BEsos esperpentos cegados por la Luz...', 0);
-- 382 El mensajero rojo
-- https://es.classic.wowhead.com/quest=382
SET @ID := 382;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu misión, $n?', 0),
(@ID, 'esMX', '¿Cómo va tu misión, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... Veamos lo que traes...$B$B<Empieza a rebuscar entre los documentos que le has entregado.>$B$BInformes de sus hazañas... contra nosotros... Esto no vale nada. Informes de rastreadores... Nuevas órdenes: "Seguir construyendo un campamento cerca de la ciudad en ruinas..." Nada que no supiéramos ya, la verdad... Espera, ¿qué es esto? ¡Un mapa con los destinos de algunos de sus comandantes de campo y agentes! Esto sí nos sirve.', 0),
(@ID, 'esMX', 'Mmm... Veamos lo que traes...$B$B<Empieza a rebuscar entre los documentos que le has entregado.>$B$BInformes de sus hazañas... contra nosotros... Esto no vale nada. Informes de rastreadores... Nuevas órdenes: "Seguir construyendo un campamento cerca de la ciudad en ruinas..." Nada que no supiéramos ya, la verdad... Espera, ¿qué es esto? ¡Un mapa con los destinos de algunos de sus comandantes de campo y agentes! Esto sí nos sirve.', 0);
-- 383 Información decisiva
-- https://es.classic.wowhead.com/quest=383
SET @ID := 383;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Qué quieres?', 0),
(@ID, 'esMX', '¿Sí? ¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto está muy bien. Has hecho bien en conseguir esta información, $n. Mmm... los nombres de los oficiales de los Claros de Tirisfal...$B$BImagina el golpe que podríamos asestar a la moral de esos malditos fanáticos si consiguiéramos matar a todos sus jefazos de un golpe.', 0),
(@ID, 'esMX', 'Esto está muy bien. Has hecho bien en conseguir esta información, $n. Mmm... los nombres de los oficiales de los Claros de Tirisfal...$B$BImagina el golpe que podríamos asestar a la moral de esos malditos fanáticos si consiguiéramos matar a todos sus jefazos de un golpe.', 0);
-- 389 Bazil Thredd
-- https://es.classic.wowhead.com/quest=389
SET @ID := 389;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En el nombre de la Luz, ¿qué quieres? ¿No ves que estamos en medio de una crisis?$B$B¡¿Bazil Thredd?! ¿Por qué quieres hablar con ese bastardo? ¿Cómo se supone que voy a saber que no eres uno de sus amigos que ha venido a ayudarle con este maldito motín? Si las malditas celdas no estuvieran abiertas, ¡te metería en una!', 0),
(@ID, 'esMX', 'En el nombre de la Luz, ¿qué quieres? ¿No ves que estamos en medio de una crisis?$B$B¡¿Bazil Thredd?! ¿Por qué quieres hablar con ese bastardo? ¿Cómo se supone que voy a saber que no eres uno de sus amigos que ha venido a ayudarle con este maldito motín? Si las malditas celdas no estuvieran abiertas, ¡te metería en una!', 0);
-- 391 El motín de Las Mazmorras
-- https://es.classic.wowhead.com/quest=391
SET @ID := 391;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'O me traes la cabeza de Thredd, o me quedo con la tuya, ¿lo entiendes, $n?', 0),
(@ID, 'esMX', 'O me traes la cabeza de Thredd, o me quedo con la tuya, ¿lo entiendes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin Thredd para liderarlos, esperemos poder controlar los motines. Ya veremos.$B$BDebo decirte que no esperaba que duraras más de media hora, pero parece que te juzgué mal.$B$B¿Supongo que no conseguiste sacarle mucha información útil, no? Pero sé un par de cosas que podrían interesarte sobre las actividades de Thredd.', 0),
(@ID, 'esMX', 'Sin Thredd para liderarlos, esperemos poder controlar los motines. Ya veremos.$B$BDebo decirte que no esperaba que duraras más de media hora, pero parece que te juzgué mal.$B$B¿Supongo que no conseguiste sacarle mucha información útil, no? Pero sé un par de cosas que podrían interesarte sobre las actividades de Thredd.', 0);
-- 392 Extraño visitante
-- https://es.classic.wowhead.com/quest=392
SET @ID := 392;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Qué has encontrado?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Qué has encontrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm. ¿Maelik? No, no me suena el nombre, ni tampoco la descripción. ¡Pero podría ser cualquiera! Un antiguo Albañil, un miembro de la Hermandad Defias... Aunque si está tan bien conectado como sugiere Thelagua, quizás alguien le pueda reconocer. Deja que lo piense...', 0),
(@ID, 'esMX', 'Mmm. ¿Maelik? No, no me suena el nombre, ni tampoco la descripción. ¡Pero podría ser cualquiera! Un antiguo Albañil, un miembro de la Hermandad Defias... Aunque si está tan bien conectado como sugiere Thelagua, quizás alguien le pueda reconocer. Deja que lo piense...', 0);
-- 393 Sombras del pasado
-- https://es.classic.wowhead.com/quest=393
SET @ID := 393;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. ¿En qué puedo serte de ayuda, $c?', 0),
(@ID, 'esMX', 'Saludos. ¿En qué puedo serte de ayuda, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¿Qué es esto? Sí, creo que sé quién es, pero no se llama Maelik. Los asesinos usan muchos nombres y muchas máscaras, cambiando de personalidad cada vez que lo necesitan. Ese hombre también utilizaba otro alias, Marzon; aunque tampoco creo que ese sea su verdadero nombre.$B$BNo importa, es un asesino y sé mucho sobre él.$B$BAhora mismo, Marzon trabaja para Lord Gregor Lescovar, un lord bastante sombrío, incluso para la norma de corrupción de la nobleza de Ventormenta.', 0),
(@ID, 'esMX', '¿Qué? ¿Qué es esto? Sí, creo que sé quién es, pero no se llama Maelik. Los asesinos usan muchos nombres y muchas máscaras, cambiando de personalidad cada vez que lo necesitan. Ese hombre también utilizaba otro alias, Marzon; aunque tampoco creo que ese sea su verdadero nombre.$B$BNo importa, es un asesino y sé mucho sobre él.$B$BAhora mismo, Marzon trabaja para Lord Gregor Lescovar, un lord bastante sombrío, incluso para la norma de corrupción de la nobleza de Ventormenta.', 0);
-- 394 La cabeza de la bestia
-- https://es.classic.wowhead.com/quest=394
SET @ID := 394;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¡Está muerto!? Has administrado justicia rápidamente, $n. Rezo a la Luz para no convertirme nunca en tu enemigo.$B$B<Se ríe y te da una palmada en el hombro.>$B$BNo es por criticar, $n. ¿Cómo podría hacerlo siendo el maestro de todos los asesinos? Pero, a decir verdad, has hecho un gran servicio al pueblo de Ventormenta y, por eso, te doy las gracias.', 0),
(@ID, 'esMX', '¿¡Está muerto!? Has administrado justicia rápidamente, $n. Rezo a la Luz para no convertirme nunca en tu enemigo.$B$B<Se ríe y te da una palmada en el hombro.>$B$BNo es por criticar, $n. ¿Cómo podría hacerlo siendo el maestro de todos los asesinos? Pero, a decir verdad, has hecho un gran servicio al pueblo de Ventormenta y, por eso, te doy las gracias.', 0);
-- 395 El fin de la Hermandad
-- https://es.classic.wowhead.com/quest=395
SET @ID := 395;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n. He oído que Lord Gregor Lescovar fue encontrado muerto no hace mucho tiempo.$B$BParece ser que has tenido éxito en tu misión. Tienes mi gratitud, nos has salvado a mí y a muchos más, de la venganza de VanCleef.', 0),
(@ID, 'esMX', 'Me alegro de verte, $n. He oído que Lord Gregor Lescovar fue encontrado muerto no hace mucho tiempo.$B$BParece ser que has tenido éxito en tu misión. Tienes mi gratitud, nos has salvado a mí y a muchos más, de la venganza de VanCleef.', 0);
-- 396 Una audiencia con el Rey
-- https://es.classic.wowhead.com/quest=396
SET @ID := 396;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿sí? Baros Alexston me informó de tu llegada. Debo decir que me interesa mucho lo que tienes que decir.', 0),
(@ID, 'esMX', '$n, ¿sí? Baros Alexston me informó de tu llegada. Debo decir que me interesa mucho lo que tienes que decir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te estamos muy agradecidos por el servicio que has hecho a Ventormenta, $n. Si VanCleef hubiese tenido éxito con sus maquinaciones, sin duda habría causado daño al reino... algo que, obviamente, queremos evitar a toda costa.$B$B$c, acepta esto como muestra del agradecimiento del rey. Siento que no te lo pueda dar él mismo, pero está fuera en una misión diplomática y no volverá en un tiempo.', 0),
(@ID, 'esMX', 'Te estamos muy agradecidos por el servicio que has hecho a Ventormenta, $n. Si VanCleef hubiese tenido éxito con sus maquinaciones, sin duda habría causado daño al reino... algo que, obviamente, queremos evitar a toda costa.$B$B$c, acepta esto como muestra del agradecimiento del rey. Siento que no te lo pueda dar él mismo, pero está fuera en una misión diplomática y no volverá en un tiempo.', 0);
-- 8325 Recuperar la Isla del Caminante del Sol
-- https://es.wowhead.com/quest=8325
SET @ID := 8325;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro trabajo en la reconstrucción de nuestra sociedad comienza aquí, $n. Una vez que podamos asegurar nuestro hogar, podemos mirar hacia afuera y hacia arriba.', 0),
(@ID, 'esMX', 'Nuestro trabajo en la reconstrucción de nuestra sociedad comienza aquí, $n. Una vez que podamos asegurar nuestro hogar, podemos mirar hacia afuera y hacia arriba.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te felicito por haber completado tu primera tarea. Eso me da esperanzas de que vas a ser mejor que esos jóvenes elfos de sangre que se niegan a escuchar las lecciones de sus maestros. Tu trabajo y esfuerzos serán recompensados, no solo con el conocimiento, sino también de forma tangible.$B$BPero aún te queda mucho por hacer. Hay tanto por aprender...', 0),
(@ID, 'esMX', 'Te felicito por haber completado tu primera tarea. Eso me da esperanzas de que vas a ser mejor que esos jóvenes elfos de sangre que se niegan a escuchar las lecciones de sus maestros. Tu trabajo y esfuerzos serán recompensados, no solo con el conocimiento, sino también de forma tangible.$B$BPero aún te queda mucho por hacer. Hay tanto por aprender...', 0);
-- 8326 Medidas extremas
-- https://es.classic.wowhead.com/quest=8326
SET @ID := 8326;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me desagrada pedirte que aniquiles a estas bestias. En el pasado vivimos en relativa armonía con las criaturas de los bosques, pero las cosas han cambiado. La prioridad principal de los sin\'dorei es la supervivencia; no lo olvides.', 0),
(@ID, 'esMX', 'Me desagrada pedirte que aniquiles a estas bestias. En el pasado vivimos en relativa armonía con las criaturas de los bosques, pero las cosas han cambiado. La prioridad principal de los sin\'dorei es la supervivencia; no lo olvides.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La torre y alrededores son zona segura, al menos de momento. Nos has ayudado a conseguir seguridad temporal, pero tenemos que recuperar el control sobre toda la isla si queremos sobrevivir aquí. Eso implica ocuparse de amenazas bastante más graves que unos linces y vermis de maná errantes.$B$BToma esto, $n; seguro que te será útil en tus próximas misiones.', 0),
(@ID, 'esMX', 'La torre y alrededores son zona segura, al menos de momento. Nos has ayudado a conseguir seguridad temporal, pero tenemos que recuperar el control sobre toda la isla si queremos sobrevivir aquí. Eso implica ocuparse de amenazas bastante más graves que unos linces y vermis de maná errantes.$B$BToma esto, $n; seguro que te será útil en tus próximas misiones.', 0);
-- 8563 Entrenamiento de brujos
-- https://es.classic.wowhead.com/quest=8563
SET @ID := 8563;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n - tu nombre ha pasado por mis oídos como alguien que busca un maestro en los caminos del brujo. Pareces lo suficientemente capaz, pero busco algo más que miradas en mis alumnos. Debes estar $glisto:lista; para ahondar donde otros temen buscar para obtener tu poder. Te enseñaré, pero no toleraré el fracaso.$B$BHabrá costos monetarios asociados con tu capacitación, pero deberías preocuparte más por el costo que tu mente tendrá que soportar. Si estás $glisto:lista;, comenzaremos.', 0),
(@ID, 'esMX', '$n - tu nombre ha pasado por mis oídos como alguien que busca un maestro en los caminos del brujo. Pareces lo suficientemente capaz, pero busco algo más que miradas en mis alumnos. Debes estar $glisto:lista; para ahondar donde otros temen buscar para obtener tu poder. Te enseñaré, pero no toleraré el fracaso.$B$BHabrá costos monetarios asociados con tu capacitación, pero deberías preocuparte más por el costo que tu mente tendrá que soportar. Si estás $glisto:lista;, comenzaremos.', 0);
-- 8336 Por un puñado de esquirlas
-- https://es.classic.wowhead.com/quest=8336
SET @ID := 8336;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas de las criaturas aquí en la isla estuvieron en un momento atadas a la docilidad y la complacencia por nuestras habilidades mágicas. Cuando la Plaga destruyó la Fuente del Sol, nuestro control sobre estas criaturas se hizo añicos. Las astillas arcanas son los remanentes del control que alguna vez tuvimos y, como tales, podrían usarse para diseñar un nuevo dispositivo que nos ayude a recuperar su control.$B$BMejor aún, tal vez las astillas podrían usarse para ver el malestar que realmente sufre la isla...', 0),
(@ID, 'esMX', 'Muchas de las criaturas aquí en la isla estuvieron en un momento atadas a la docilidad y la complacencia por nuestras habilidades mágicas. Cuando la Plaga destruyó la Fuente del Sol, nuestro control sobre estas criaturas se hizo añicos. Las astillas arcanas son los remanentes del control que alguna vez tuvimos y, como tales, podrían usarse para diseñar un nuevo dispositivo que nos ayude a recuperar su control.$B$BMejor aún, tal vez las astillas podrían usarse para ver el malestar que realmente sufre la isla...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espléndido, estas funcionarán muy bien. He estado pensando un poco en el malestar actual que sufre la Isla del Caminante del Sol. Un posible curso de acción que había meditado era recoger estas astillas arcanas de las bestias de la isla. Al hacerlo, se podría experimentar con ellos; esto proporcionaría una fuente potencial de información.$B$BDe todos modos, me ocuparé de la investigación. Permíteme otorgarte este encantamiento. ¡Creo que harás un buen uso de él!', 0),
(@ID, 'esMX', 'Espléndido, estas funcionarán muy bien. He estado pensando un poco en el malestar actual que sufre la Isla del Caminante del Sol. Un posible curso de acción que había meditado era recoger estas astillas arcanas de las bestias de la isla. Al hacerlo, se podría experimentar con ellos; esto proporcionaría una fuente potencial de información.$B$BDe todos modos, me ocuparé de la investigación. Permíteme otorgarte este encantamiento. ¡Creo que harás un buen uso de él!', 0);
-- 8346 Sed insaciable
-- https://es.classic.wowhead.com/quest=8346
SET @ID := 8346;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah $n. ¿Has completado tu tarea?', 0),
(@ID, 'esMX', 'Ah $n. ¿Has completado tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien hoy, $n. Tu disposición a aprender demuestra que es muy posible que superes los perjuicios inquebrantables que debes soportar como $R.$B$BNo descanses en tus laureles, joven, ahora busca dominar lo que ha aprendido. Solo mediante la diligencia sobreviviremos como raza.$B$BToma esto', 0),
(@ID, 'esMX', 'Lo has hecho bien hoy, $n. Tu disposición a aprender demuestra que es muy posible que superes los perjuicios inquebrantables que debes soportar como $R.$B$BNo descanses en tus laureles, joven, ahora busca dominar lo que ha aprendido. Solo mediante la diligencia sobreviviremos como raza.$B$BToma esto', 0);
