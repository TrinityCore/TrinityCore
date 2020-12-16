-- 9352 Intrusiones darnassianas
-- https://es.classic.wowhead.com/quest=9352
SET @ID := 9352;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Intruso derrotado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto algo? ¿Están los elfos de la noche detrás de esto?', 0),
(@ID, 'esMX', '¿Has descubierto algo? ¿Están los elfos de la noche detrás de esto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Elfos de la noche? ¿Aquí? ¡Esas ratas!$B$B¿Crees que tienen algo que ver con la disfunción de mi sagrario? Si tienes cualquier información, ¡será mejor que se la lleves enseguida al capitán Marcasol!', 0),
(@ID, 'esMX', '¿Elfos de la noche? ¿Aquí? ¡Esas ratas!$B$B¿Crees que tienen algo que ver con la disfunción de mi sagrario? Si tienes cualquier información, ¡será mejor que se la lleves enseguida al capitán Marcasol!', 0);
-- 9119 Disfunción en el Sagrario del Oeste
-- https://es.classic.wowhead.com/quest=9119
SET @ID := 9119;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mira a tu alrededor. Las cosas no están exactamente en orden.$B$BPor lo visto hay una grave disfunción en el Sagrario del Oeste. Hagamos todo lo posible para evitar que empeoren.', 0),
(@ID, 'esMX', 'Mira a tu alrededor. Las cosas no están exactamente en orden.$B$BPor lo visto hay una grave disfunción en el Sagrario del Oeste. Hagamos todo lo posible para evitar que empeoren.', 0);
-- 9035 Asaltantes de caminos
-- https://es.wowhead.com/quest=9035
SET @ID := 9035;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Han huido. ¡Casi los mato de miedo con una bola de Fuego bien colocada! Por desgracia, han tirado nuestra preciada carga al río.', 0),
(@ID, 'esMX', 'Han huido. ¡Casi los mato de miedo con una bola de Fuego bien colocada! Por desgracia, han tirado nuestra preciada carga al río.', 0);
-- 9062 Papel mojado
-- https://es.wowhead.com/quest=9062
-- https://es.classic.wowhead.com/quest=9062
SET @ID := 9062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué, ¿no ha habido suerte? Sigue buscando; ese libro es importantísimo, $c.', 0),
(@ID, 'esMX', 'Qué, ¿no ha habido suerte? Sigue buscando; ese libro es importantísimo, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El libro está completamente empapado. El instructor Antheol no va a estar nada contento.$B$BTen, toma estas monedas. Tengo una idea.', 0),
(@ID, 'esMX', 'El libro está completamente empapado. El instructor Antheol no va a estar nada contento.$B$BTen, toma estas monedas. Tengo una idea.', 0);
-- 9064 Asumiendo la responsabilidad
-- https://es.wowhead.com/quest=9064
SET @ID := 9064;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te atreves a interrumpirme, $c?', 0),
(@ID, 'esMX', '¿Cómo te atreves a interrumpirme, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que esos dos incompetentes te sobornaron para que me mintieras? Has hecho bien en decírmelo, $n.', 0),
(@ID, 'esMX', '¿Que esos dos incompetentes te sobornaron para que me mintieras? Has hecho bien en decírmelo, $n.', 0);
-- 9066 La letra con sangre entra
-- https://es.wowhead.com/quest=9066
SET @ID := 9066;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Aprendiz Meledor castigado', `ObjectiveText2` = 'Aprendiz Ralen castigado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho lo que te he pedido, $n?', 0),
(@ID, 'esMX', '¿Has hecho lo que te he pedido, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. No te preocupes, no se quedarán con esa forma. Sin embargo, no recuperarán su aprendizaje hasta que se lo ganen.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. No te preocupes, no se quedarán con esa forma. Sin embargo, no recuperarán su aprendizaje hasta que se lo ganen.', 0);
-- 8486 Inestabilidad arcana
-- https://es.wowhead.com/quest=8486
SET @ID := 8486;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te encargaste de los espectros de maná?', 0),
(@ID, 'esMX', '¿Te encargaste de los espectros de maná?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Ahora que las apariciones están controladas podemos enviar a alguien a evaluar los daños. Espero que no sean permanentes.', 0),
(@ID, 'esMX', 'Gracias, $n. Ahora que las apariciones están controladas podemos enviar a alguien a evaluar los daños. Espero que no sean permanentes.', 0);
-- 8482 Documentos incriminadores
-- https://es.wowhead.com/quest=8482
SET @ID := 8482;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué traes? Déjame ver.', 0),
(@ID, 'esMX', '¿Qué traes? Déjame ver.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que estos documentos los tenía un elfo de la noche? Están en enano...$B$BPor lo que entiendo de la carta, quien escribió esto no es responsable de la avería, sino que más bien vino a espiar para observar sus resultados. Dicen que nuestros esfuerzos son inconscientes y peligrosos... Pero ¿quién?$B$B¡Claro, el enviado de Forjaz! ¡Nunca debimos confiar en alguien de la Alianza!', 0),
(@ID, 'esMX', '¿Dices que estos documentos los tenía un elfo de la noche? Están en enano...$B$BPor lo que entiendo de la carta, quien escribió esto no es responsable de la avería, sino que más bien vino a espiar para observar sus resultados. Dicen que nuestros esfuerzos son inconscientes y peligrosos... Pero ¿quién?$B$B¡Claro, el enviado de Forjaz! ¡Nunca debimos confiar en alguien de la Alianza!', 0);
-- 8483 El espía enano
-- https://es.wowhead.com/quest=8483
SET @ID := 8483;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te ocupaste del intruso?', 0),
(@ID, 'esMX', '¿Te ocupaste del intruso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya veo. Has hecho un buen trabajo.$B$BHemos informado al General Forestal; créeme, esos enanos van a pagar cara su traición.$B$BHoy has rendido un gran servicio a los tuyos, $n.', 0),
(@ID, 'esMX', 'Ya veo. Has hecho un buen trabajo.$B$BHemos informado al General Forestal; créeme, esos enanos van a pagar cara su traición.$B$BHoy has rendido un gran servicio a los tuyos, $n.', 0);
-- 9256 La Aldea Brisa Pura
-- https://es.wowhead.com/quest=9256
SET @ID := 9256;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por venir, $n. Las cosas están peor de lo que habíamos previsto. Los desdichados se han adueñado del Fondeadero Vela del Sol.', 0),
(@ID, 'esMX', 'Gracias por venir, $n. Las cosas están peor de lo que habíamos previsto. Los desdichados se han adueñado del Fondeadero Vela del Sol.', 0);
-- 8475 La Cicatriz Muerta
-- https://es.wowhead.com/quest=8475
SET @ID := 8475;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, $n. ¿Ya luchaste contra los muertos vivientes a lo largo de la Cicatriz?', 0),
(@ID, 'esMX', 'Has vuelto, $n. ¿Ya luchaste contra los muertos vivientes a lo largo de la Cicatriz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No creemos que la Plaga vaya a abandonar los ataques en un futuro próximo, pero agradecemos la ayuda para vigilar La Cicatriz.', 0),
(@ID, 'esMX', 'No creemos que la Plaga vaya a abandonar los ataques en un futuro próximo, pero agradecemos la ayuda para vigilar La Cicatriz.', 0);
-- 8491 Caza de pelambres
-- https://es.wowhead.com/quest=8491
SET @ID := 8491;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¿Me traes las pelambres?', 0),
(@ID, 'esMX', 'Has vuelto. ¿Me traes las pelambres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, $n. Ten esta pieza de armadura como recompensa. Voy a poder hacer más gracias a estas pelambres.', 0),
(@ID, 'esMX', 'Perfecto, $n. Ten esta pieza de armadura como recompensa. Voy a poder hacer más gracias a estas pelambres.', 0);
-- 9254 El aprendiz de díscolo
-- https://es.wowhead.com/quest=9254
SET @ID := 9254;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es muy bonito que quien fuera mi mentora se preocupe por mí. Lástima que perdiera la fe en mi investigación hace mucho tiempo.$B$BNo pierdas el tiempo intentando que vuelva junto a ella; elige entre ayudarme en mi investigación o marcharte.', 0),
(@ID, 'esMX', 'Es muy bonito que quien fuera mi mentora se preocupe por mí. Lástima que perdiera la fe en mi investigación hace mucho tiempo.$B$BNo pierdas el tiempo intentando que vuelva junto a ella; elige entre ayudarme en mi investigación o marcharte.', 0);
-- 9395 El Refugio de Saltheril
-- https://es.wowhead.com/quest=9395
SET @ID := 9395;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Magistrix Caminalba se digna responder al fin a mis sencillas peticiones. Debería hablar de su actitud con el Señor regente de Lunargenta. ¡Es bastante maleducada!$B$BAunque nada por lo que debas preocuparte. Ya que estás aquí, ¿quizás podría al fin conseguir esos suministros que estaba esperando para la fiesta?', 0),
(@ID, 'esMX', 'Ah, Magistrix Caminalba se digna responder al fin a mis sencillas peticiones. Debería hablar de su actitud con el Señor regente de Lunargenta. ¡Es bastante maleducada!$B$BAunque nada por lo que debas preocuparte. Ya que estás aquí, ¿quizás podría al fin conseguir esos suministros que estaba esperando para la fiesta?', 0);
-- 9358 La forestal Sareyn
-- https://es.wowhead.com/quest=9358
SET @ID := 9358;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido a ayudarnos? ¿Por qué no lo has dicho antes? ¡Siempre nos viene bien que nos echen una mano!', 0),
(@ID, 'esMX', '¿Has venido a ayudarnos? ¿Por qué no lo has dicho antes? ¡Siempre nos viene bien que nos echen una mano!', 0);
-- 9258 La Arboleda Agostada
-- https://es.wowhead.com/quest=9258
SET @ID := 9258;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, te envía mi hermano. Sí que tengo una tarea en la que podrías ayudar.', 0),
(@ID, 'esMX', 'Ah, te envía mi hermano. Sí que tengo una tarea en la que podrías ayudar.', 0);
-- 8892 Problemas en el Fondeadero Vela del Sol
-- https://es.wowhead.com/quest=8892
SET @ID := 8892;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Les enseñaste una lección a esos miserables?', 0),
(@ID, 'esMX', '¿Les enseñaste una lección a esos miserables?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así aprenderán que con nosotros no se juega. Buen trabajo, $n.', 0),
(@ID, 'esMX', 'Así aprenderán que con nosotros no se juega. Buen trabajo, $n.', 0);
-- 9067 Fiesta interminable
-- https://es.wowhead.com/quest=9067
SET @ID := 9067;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No te acabo de mandar a buscar provisiones para la fiesta? ¿No eras tú? Bueno, no voy a acordarme de las caras de todo el mundo, ¿no? Conozco a tantos p... Personajes interesantes, quiero decir.$B$B¿Qué quieres?', 0),
(@ID, 'esMX', '¿No te acabo de mandar a buscar provisiones para la fiesta? ¿No eras tú? Bueno, no voy a acordarme de las caras de todo el mundo, ¿no? Conozco a tantos p... Personajes interesantes, quiero decir.$B$B¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres un $ghombre:mujer; bastante enérgico, ¿no?$B$BTodo esto parece muy adecuado. Ciertamente mereces una compensación por reunir todo esto para mí, y creo que algo más.$B$BOh, casi lo olvido, aquí tienes una invitación a la fiesta. Y, $c, la próxima vez que vengas asegúrate de vestirte con algo un poco más... festivo.', 0),
(@ID, 'esMX', 'Eres un $ghombre:mujer; bastante enérgico, ¿no?$B$BTodo esto parece muy adecuado. Ciertamente mereces una compensación por reunir todo esto para mí, y creo que algo más.$B$BOh, casi lo olvido, aquí tienes una invitación a la fiesta. Y, $c, la próxima vez que vengas asegúrate de vestirte con algo un poco más... festivo.', 0);
-- 8473 Una tarea dolorosa
-- https://es.wowhead.com/quest=8473
SET @ID := 8473;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me da miedo preguntar, $n... ¿está terminada la tarea?', 0),
(@ID, 'esMX', 'Me da miedo preguntar, $n... ¿está terminada la tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que ya está. Malditos sean estos tiempos que nos obligan a adoptar medidas desesperadas y maldito nuestro enemigo, la Plaga.$B$BRecuerda esto, $n: debemos proteger nuestra tierra al precio que sea. ¡Venceremos!', 0),
(@ID, 'esMX', 'Así que ya está. Malditos sean estos tiempos que nos obligan a adoptar medidas desesperadas y maldito nuestro enemigo, la Plaga.$B$BRecuerda esto, $n: debemos proteger nuestra tierra al precio que sea. ¡Venceremos!', 0);
-- 9359 El Retiro del Errante
-- https://es.wowhead.com/quest=9359
SET @ID := 9359;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido a ayudar! ¡Excelente!$B$BLa batalla contra los trols Amani ha diezmado nuestros efectivos y siempre agradecemos el apoyo de luchadores capaces como tú.', 0),
(@ID, 'esMX', '¿Has venido a ayudar! ¡Excelente!$B$BLa batalla contra los trols Amani ha diezmado nuestros efectivos y siempre agradecemos el apoyo de luchadores capaces como tú.', 0);
-- 9252 Defender la Aldea Brisa Pura
-- https://es.wowhead.com/quest=9252
SET @ID := 9252;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Prevaleceremos, $n.', 0),
(@ID, 'esMX', 'Prevaleceremos, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Nuestro trabajo es muy ingrato pero hoy tú lo has hecho un poco más fácil.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Nuestro trabajo es muy ingrato pero hoy tú lo has hecho un poco más fácil.', 0);
-- 9253 El celador de las runas Deryan
-- https://es.wowhead.com/quest=9253
SET @ID := 9253;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debe de enviarte alguien de la Aldea Brisa Pura. Sabía que era solo cuestión de tiempo hasta que llegara la ayuda.', 0),
(@ID, 'esMX', 'Debe de enviarte alguien de la Aldea Brisa Pura. Sabía que era solo cuestión de tiempo hasta que llegara la ayuda.', 0);
-- 8487 Tierra corrupta
-- https://es.wowhead.com/quest=8487
SET @ID := 8487;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes las muestras que te pedí, $n?', 0),
(@ID, 'esMX', '¿Traes las muestras que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Voy a echar un encantamiento aumentador a las muestras para analizar la corrupción de la tierra.', 0),
(@ID, 'esMX', 'Excelente. Voy a echar un encantamiento aumentador a las muestras para analizar la corrupción de la tierra.', 0);
-- 8488 Resultados inesperados
-- https://es.wowhead.com/quest=8488
SET @ID := 8488;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No hay esperanza, $n. La naturaleza misma de la tierra ha sido alterada... La corrupción es irreversible. Gracias por tu ayuda; tengo una tarea más para ti.', 0),
(@ID, 'esMX', 'No hay esperanza, $n. La naturaleza misma de la tierra ha sido alterada... La corrupción es irreversible. Gracias por tu ayuda; tengo una tarea más para ti.', 0);
