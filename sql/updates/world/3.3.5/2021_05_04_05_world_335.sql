-- 9293 Hacer lo correcto...
-- https://es.wowhead.com/quest=9293
SET @ID := 9293;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré todas las muestras en buen estado si queremos tener una posibilidad de limpiar el lago.$B$B¡No nos queda mucho tiempo, $c!', 0),
(@ID, 'esMX', 'Necesitaré todas las muestras en buen estado si queremos tener una posibilidad de limpiar el lago.$B$B¡No nos queda mucho tiempo, $c!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Servirán. ¡Gracias, $c!$B$BMientras estabas fuera, conseguí reunir algo de equipamiento para analizar las muestras. Solo debería ser un segundo.', 0),
(@ID, 'esMX', 'Servirán. ¡Gracias, $c!$B$BMientras estabas fuera, conseguí reunir algo de equipamiento para analizar las muestras. Solo debería ser un segundo.', 0);
-- 9294 Sanar el lago
-- https://es.wowhead.com/quest=9294
SET @ID := 9294;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Dispersa el agente neutralizador', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuanto antes disperses al agente en el lago, menos criaturas nativas mutarán al beber el agua, ¡incluyéndonos a nosotros mismos!$B$BLamento que no podamos hacer nada para ayudar a las pobres criaturas que ya han sido infectadas. Si tan solo mi equipo de laboratorio estuviera intacto.', 0),
(@ID, 'esMX', 'Cuanto antes disperses al agente en el lago, menos criaturas nativas mutarán al beber el agua, ¡incluyéndonos a nosotros mismos!$B$BLamento que no podamos hacer nada para ayudar a las pobres criaturas que ya han sido infectadas. Si tan solo mi equipo de laboratorio estuviera intacto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por lo que describes, ¡el agente neutralizador ha funcionado! Ojalá supiera cuánto va a durar; necesitamos realmente eliminar por completo ese cristal de poder del lago.$B$B¡Gracias, $n! Le diré a Tedon que pruebe el agente neutralizador sobre una de las bestias cautivas enseguida.', 0),
(@ID, 'esMX', 'Por lo que describes, ¡el agente neutralizador ha funcionado! Ojalá supiera cuánto va a durar; necesitamos realmente eliminar por completo ese cristal de poder del lago.$B$B¡Gracias, $n! Le diré a Tedon que pruebe el agente neutralizador sobre una de las bestias cautivas enseguida.', 0);
-- Una carta del frente
-- 9295, 9300, 9302
-- https://es.classic.wowhead.com/quest=9295
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9295, 9300, 9302) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9295, 'esES', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9300, 'esES', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9302, 'esES', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9295, 'esMX', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9300, 'esMX', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9302, 'esMX', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0);
-- Una nota del frente
-- 9299, 9301, 9304
-- https://es.classic.wowhead.com/quest=9299
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9299, 9301, 9304) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9299, 'esES', '¿Sí? ¿Qué me traes?', 0),
(9301, 'esES', '¿Sí? ¿Qué me traes?', 0),
(9304, 'esES', '¿Sí? ¿Qué me traes?', 0),
(9299, 'esMX', '¿Sí? ¿Qué me traes?', 0),
(9301, 'esMX', '¿Sí? ¿Qué me traes?', 0),
(9304, 'esMX', '¿Sí? ¿Qué me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9299, 9301, 9304) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9299, 'esES', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9301, 'esES', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9304, 'esES', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9299, 'esMX', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9301, 'esMX', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0),
(9304, 'esMX', 'Qué trágico; la carta de despedida del soldado a su ser querido nunca llegó a su destino. Esta carta tiene muchos años; puede que su destinatario ya no viva.$B$BPero no perdamos la esperanza; quizás pueda localizar a la familia. Será arduo, pero el bibliotecario de Ventormenta me debe un favor.$B$BGracias por traerme esto; aún puede brindar algún consuelo.', 0);
-- 9303 Inoculación
-- https://es.wowhead.com/quest=9303
SET @ID := 9303;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Búhicos Cubrebosque inoculados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuanto más podamos hacer para limpiar Cubrebosque, más rápido podrá Zhanaa volver al trabajo.', 0),
(@ID, 'esMX', 'Cuanto más podamos hacer para limpiar Cubrebosque, más rápido podrá Zhanaa volver al trabajo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con muchos de los buhícos inoculados, podemos concentrarnos en salir de aquí y no tener que preocuparnos por acabar con la población de buhícos del área.$B$BToma, elige entre estos. ¡Has hecho un buen trabajo y mereces ser $grecompensado:recompensada;!', 0),
(@ID, 'esMX', 'Con muchos de los buhícos inoculados, podemos concentrarnos en salir de aquí y no tener que preocuparnos por acabar con la población de buhícos del área.$B$BToma, elige entre estos. ¡Has hecho un buen trabajo y mereces ser $grecompensado:recompensada;!', 0);
-- 9305 Piezas de repuesto
-- https://es.wowhead.com/quest=9305
SET @ID := 9305;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tengamos esas piezas de repuesto, sé que repararemos este emisor. Con un poco de suerte, quedará alguien más con quien hablar.', 0),
(@ID, 'esMX', 'Cuando tengamos esas piezas de repuesto, sé que repararemos este emisor. Con un poco de suerte, quedará alguien más con quien hablar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame echar un vistazo a eso.$B$BSí, creo que esto funcionará bien; buen trabajo, $n. El emisor es bastante complejo, por lo que puede llevar algún tiempo terminar las reparaciones. Te avisaré cuando esté listo.$B$BMientras tanto, podrías ver si el vindicador Aldar tiene algo para lo que pueda usarte.', 0),
(@ID, 'esMX', 'Déjame echar un vistazo a eso.$B$BSí, creo que esto funcionará bien; buen trabajo, $n. El emisor es bastante complejo, por lo que puede llevar algún tiempo terminar las reparaciones. Te avisaré cuando esté listo.$B$BMientras tanto, podrías ver si el vindicador Aldar tiene algo para lo que pueda usarte.', 0);
-- 9309 El explorador desaparecido
-- https://es.wowhead.com/quest=9309
SET @ID := 9309;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ayuda... ¡elfos de sangre! Me... tendieron... una emboscada. No me queda... mucho.', 0),
(@ID, 'esMX', 'Ayuda... ¡elfos de sangre! Me... tendieron... una emboscada. No me queda... mucho.', 0);
-- 9310 Cristal necrótico tenue
-- https://es.classic.wowhead.com/quest=9310
SET @ID := 9310;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que esto se lo has quitado a un espectro que atacaba la ciudad?$B$BHemos recibido noticias de los campamentos base de la necrópolis que están siendo invocados por la Plaga. Sospecho que estaban intentando crear uno en Entrañas. Tendremos que estar atentos en el futuro.', 0),
(@ID, 'esMX', '¿Dices que esto se lo has quitado a un espectro que atacaba la ciudad?$B$BHemos recibido noticias de los campamentos base de la necrópolis que están siendo invocados por la Plaga. Sospecho que estaban intentando crear uno en Entrañas. Tendremos que estar atentos en el futuro.', 0);
-- 9311 Espía elfo de sangre
-- https://es.wowhead.com/quest=9311
SET @ID := 9311;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces es cierto... ¡un grupo de exploración de los elfos de sangre aquí en Valle Ammen! ¿Cómo nos siguieron?$B$BLlamaré a alguien de inmediato para traer de vuelta a Tolaan.', 0),
(@ID, 'esMX', 'Entonces es cierto... ¡un grupo de exploración de los elfos de sangre aquí en Valle Ammen! ¿Cómo nos siguieron?$B$BLlamaré a alguien de inmediato para traer de vuelta a Tolaan.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por encargarte de la elfa de sangre; seguro que ella era la líder. Nos ocuparemos de los rezagados, no te preocupes.$B$BAcepta una de estas armas como prueba de mi gratitud.', 0),
(@ID, 'esMX', 'Gracias por encargarte de la elfa de sangre; seguro que ella era la líder. Nos ocuparemos de los rezagados, no te preocupes.$B$BAcepta una de estas armas como prueba de mi gratitud.', 0);
-- 9312 El emisor
-- https://es.wowhead.com/quest=9312
SET @ID := 9312;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya está, lo tengo! ¡Creo que he conseguido arreglar el emisor! Ahí está, activaré este último cristal y eso debería funcionar.$B$BMira el emisor, $n. Parece que empieza a funcionar... ¡está apareciendo alguien!', 0),
(@ID, 'esMX', '¡Ya está, lo tengo! ¡Creo que he conseguido arreglar el emisor! Ahí está, activaré este último cristal y eso debería funcionar.$B$BMira el emisor, $n. Parece que empieza a funcionar... ¡está apareciendo alguien!', 0);
-- 9313 Viaje a la Avanzada Azur
-- https://es.wowhead.com/quest=9313
SET @ID := 9313;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Dichosos los ojos! Me alegro de que ambos consiguiésemos arreglar nuestros emisores porque si no, podríamos no habernos encontrado nunca. Y no te preocupes, nos ocuparemos de que el Valle Ammen consiga ayuda y suministros.$B$BA propósito de ayuda, ahora que estás aquí, date una vuelta y preséntate a los demás. Sé que hay muchas cosas por hacer.', 0),
(@ID, 'esMX', '¡Dichosos los ojos! Me alegro de que ambos consiguiésemos arreglar nuestros emisores porque si no, podríamos no habernos encontrado nunca. Y no te preocupes, nos ocuparemos de que el Valle Ammen consiga ayuda y suministros.$B$BA propósito de ayuda, ahora que estás aquí, date una vuelta y preséntate a los demás. Sé que hay muchas cosas por hacer.', 0);
-- 9314 Un mensaje de la Avanzada Azur
-- https://es.wowhead.com/quest=9314
SET @ID := 9314;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, debes de ser uno de los supervivientes de los que hemos oído hablar!$B$BMe alegro de que hayas venido. No te preocupes, enviaremos a alguien para que examine la pierna herida de Aeun.$B$BMe interesa muchísimo oír tu desgarradora historia de supervivencia. Eres valiente para haber conseguido llegar hasta aquí.', 0),
(@ID, 'esMX', '¡Ah, debes de ser uno de los supervivientes de los que hemos oído hablar!$B$BMe alegro de que hayas venido. No te preocupes, enviaremos a alguien para que examine la pierna herida de Aeun.$B$BMe interesa muchísimo oír tu desgarradora historia de supervivencia. Eres valiente para haber conseguido llegar hasta aquí.', 0);
-- 9319 Una luz en la oscuridad
-- https://es.classic.wowhead.com/quest=9319
SET @ID := 9319;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado tu camino a través de la oscuridad?', 0),
(@ID, 'esMX', '¿Has encontrado tu camino a través de la oscuridad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has probado que no eres del todo inútil, mortal.', 0),
(@ID, 'esMX', 'Has probado que no eres del todo inútil, mortal.', 0);
-- 9322 Los fuegos salvajes de Kalimdor
-- https://es.classic.wowhead.com/quest=9322
SET @ID := 9322;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Las llamas de Kalimdor brillan intensamente?', 0),
(@ID, 'esMX', '¿Las llamas de Kalimdor brillan intensamente?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu espíritu brilla con el calor de los fuegos de Kalimdor, $gamigo:amiga;. ¿El calor no es vigorizante? Una vez que el poder se desvanezca, tal vez esto ayude a reavivar el sentimiento.', 0),
(@ID, 'esMX', 'Tu espíritu brilla con el calor de los fuegos de Kalimdor, $gamigo:amiga;. ¿El calor no es vigorizante? Una vez que el poder se desvanezca, tal vez esto ayude a reavivar el sentimiento.', 0);
-- 9323 Los fuegos salvajes de los Reinos del Este
-- https://es.classic.wowhead.com/quest=9323
SET @ID := 9323;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se necesitará tiempo para vencer esta amenaza. ¿Cómo te ha ido, $n?', 0),
(@ID, 'esMX', 'Se necesitará tiempo para vencer esta amenaza. ¿Cómo te ha ido, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te veo resplandeciente pese al polvo del camino y la fatiga! La llama nos une a todos; todo tu ser reluce con el poder de las hogueras que has tocado.$B$BPero imagino que también ansías una recompensa de tipo más material; aquí la tienes.', 0),
(@ID, 'esMX', '¡Te veo resplandeciente pese al polvo del camino y la fatiga! La llama nos une a todos; todo tu ser reluce con el poder de las hogueras que has tocado.$B$BPero imagino que también ansías una recompensa de tipo más material; aquí la tienes.', 0);
-- 9324 Robar la llama de Orgrimmar
-- https://es.wowhead.com/quest=9324
SET @ID := 9324;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0),
(@ID, 'esMX', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh! ¡O mucho me equivoco o esta llama viene del hogar de Orgrimmar! La fiereza de los orcos y los trols se refleja en su ardiente calor. ¡Has demostrado mucho valor al robar la llama sacra del enemigo!$B$BMe pregunto qué poderes acechan en las otras ciudades...', 0),
(@ID, 'esMX', '¡Oh! ¡O mucho me equivoco o esta llama viene del hogar de Orgrimmar! La fiereza de los orcos y los trols se refleja en su ardiente calor. ¡Has demostrado mucho valor al robar la llama sacra del enemigo!$B$BMe pregunto qué poderes acechan en las otras ciudades...', 0);
-- 9325 Robar la llama de Cima del Trueno
-- https://es.wowhead.com/quest=9325
SET @ID := 9325;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0),
(@ID, 'esMX', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta llama ha sido tomada en Cima del Trueno! ¡Oye cómo canta con el poder de los espíritus! Tienes dedos ligeros, $n. Acepta esto en pago por tus servicios. Ah, si tuviera las llamas de las cuatro ciudades...', 0),
(@ID, 'esMX', '¡Esta llama ha sido tomada en Cima del Trueno! ¡Oye cómo canta con el poder de los espíritus! Tienes dedos ligeros, $n. Acepta esto en pago por tus servicios. Ah, si tuviera las llamas de las cuatro ciudades...', 0);
-- 9326 Robar la llama de Entrañas
-- https://es.wowhead.com/quest=9326
SET @ID := 9326;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0),
(@ID, 'esMX', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué llama tan peculiar... Está casi extinguida, pero sigue muy caliente. ¿Dices que viene de Entrañas? Fascinante. ¿Qué no podremos conseguir con las llamas de las cuatro ciudades?', 0),
(@ID, 'esMX', 'Qué llama tan peculiar... Está casi extinguida, pero sigue muy caliente. ¿Dices que viene de Entrañas? Fascinante. ¿Qué no podremos conseguir con las llamas de las cuatro ciudades?', 0);
-- 9328 Héroe de los sin'dorei
-- https://es.wowhead.com/quest=9328
SET @ID := 9328;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has solicitado una audiencia conmigo, $c? No recuerdo que me notificaran ninguna cita.', 0),
(@ID, 'esMX', '¿Has solicitado una audiencia conmigo, $c? No recuerdo que me notificaran ninguna cita.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que me aspen si esperaba ver esa cara tan pronto.$B$BEs una buena noticia, $n, en más sentidos de lo que puedas imaginar.', 0),
(@ID, 'esMX', 'Que me aspen si esperaba ver esa cara tan pronto.$B$BEs una buena noticia, $n, en más sentidos de lo que puedas imaginar.', 0);
-- 9329 Los Renegados
-- https://es.wowhead.com/quest=9329
SET @ID := 9329;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que parece extraño, pero los Renegados están aquí para ayudar. Deberías hablar con su líder, el Sumo Ejecutor Mavren. Está en la torre del lado oeste de la ciudad.$B$BY, $n, cuando hayas terminado de hablar con él, vuelve conmigo; ¡Tengo algo terrible que debe solucionarse de inmediato!', 0),
(@ID, 'esMX', 'Sé que parece extraño, pero los Renegados están aquí para ayudar. Deberías hablar con su líder, el Sumo Ejecutor Mavren. Está en la torre del lado oeste de la ciudad.$B$BY, $n, cuando hayas terminado de hablar con él, vuelve conmigo; ¡Tengo algo terrible que debe solucionarse de inmediato!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Renegados estamos aquí por un enemigo común con los elfos de sangre: ¡Dar\'Khan! Ha vuelto y ahora está al mando de la Plaga que está invadiendo esta tierra desde su inquebrantable Ciudad de la Muerte al sur.$B$BLady Sylvanas Brisaveloz, que procede de estas tierras, y antes era una elfa, tiene cuentas pendientes con Dar\'Khan ¡y lo quiere ver muerto!$B$BLo derrotaremos, $c, ¡y tú nos ayudarás!', 0),
(@ID, 'esMX', 'Los Renegados estamos aquí por un enemigo común con los elfos de sangre: ¡Dar\'Khan! Ha vuelto y ahora está al mando de la Plaga que está invadiendo esta tierra desde su inquebrantable Ciudad de la Muerte al sur.$B$BLady Sylvanas Brisaveloz, que procede de estas tierras, y antes era una elfa, tiene cuentas pendientes con Dar\'Khan ¡y lo quiere ver muerto!$B$BLo derrotaremos, $c, ¡y tú nos ayudarás!', 0);
-- 9330 Robar la llama de Ventormenta
-- https://es.wowhead.com/quest=9330
SET @ID := 9330;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0),
(@ID, 'esMX', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que esta llama tan viva viene de Ventormenta? Interesante... Ten, aquí tienes tu recompensa. Si vuelves a encontrar algo así, ven a verme.', 0),
(@ID, 'esMX', '¿Dices que esta llama tan viva viene de Ventormenta? Interesante... Ten, aquí tienes tu recompensa. Si vuelves a encontrar algo así, ven a verme.', 0);
-- 9331 Robar la llama de Forjaz
-- https://es.wowhead.com/quest=9331
SET @ID := 9331;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0),
(@ID, 'esMX', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta llama tan vigorosa tiene que venir de Forjaz; es tan vivaz como los propios enanos. Buen trabajo, $n. Ah, si tuviera las demás llamas... Pero no importa; ten tu recompensa.', 0),
(@ID, 'esMX', 'Esta llama tan vigorosa tiene que venir de Forjaz; es tan vivaz como los propios enanos. Buen trabajo, $n. Ah, si tuviera las demás llamas... Pero no importa; ten tu recompensa.', 0);
-- 9332 Robar la llama de Darnassus
-- https://es.classic.wowhead.com/quest=9332
SET @ID := 9332;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0),
(@ID, 'esMX', 'Reluces en la oscuridad, $r. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta llama encierra una gran pena, $n. ¿Dices que viene de Teldrassil? ¡Fascinante! Aquí tienes tu recompensa. Ven a verme si encuentras algo así; seguro que me será útil.', 0),
(@ID, 'esMX', 'Esta llama encierra una gran pena, $n. ¿Dices que viene de Teldrassil? ¡Fascinante! Aquí tienes tu recompensa. Ven a verme si encuentras algo así; seguro que me será útil.', 0);
-- 9338 Lealtad al Círculo Cenarion
-- https://es.classic.wowhead.com/quest=9338
SET @ID := 9338;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Incluso si no necesitas las recompensas materiales que ofrecemos, estos distintivos siguen marcando nuestra mutua confianza y amistad.$B$BTráemelos. Tomaré nota de tu servicio en caso de que tu desempeño vaya más allá del llamado del deber.', 0),
(@ID, 'esMX', 'Incluso si no necesitas las recompensas materiales que ofrecemos, estos distintivos siguen marcando nuestra mutua confianza y amistad.$B$BTráemelos. Tomaré nota de tu servicio en caso de que tu desempeño vaya más allá del llamado del deber.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos honras, $n. Con tus continuos esfuerzos superaremos todos los obstáculos.', 0),
(@ID, 'esMX', 'Nos honras, $n. Con tus continuos esfuerzos superaremos todos los obstáculos.', 0);
-- Una recompensa de ladrón
-- 9339, 9365
-- https://es.classic.wowhead.com/quest=9339
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9339, 9365) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9339, 'esES', 'Hoy te has probado a ti mismo, $n.$B$BAunque tengo poco más para darte, tengo esta corona; un regalo apropiado para $gun conquistador:una conquistadora;. Que ilumine tu camino.', 0),
(9365, 'esES', 'Hoy te has probado a ti mismo, $n.$B$BAunque tengo poco más para darte, tengo esta corona; un regalo apropiado para $gun conquistador:una conquistadora;. Que ilumine tu camino.', 0),
(9339, 'esMX', 'Hoy te has probado a ti mismo, $n.$B$BAunque tengo poco más para darte, tengo esta corona; un regalo apropiado para $gun conquistador:una conquistadora;. Que ilumine tu camino.', 0),
(9365, 'esMX', 'Hoy te has probado a ti mismo, $n.$B$BAunque tengo poco más para darte, tengo esta corona; un regalo apropiado para $gun conquistador:una conquistadora;. Que ilumine tu camino.', 0);
-- 9340 La Gran Fisura
-- https://es.wowhead.com/quest=9340
SET @ID := 9340;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¿Está terminada la tarea?', 0),
(@ID, 'esMX', 'Has vuelto. ¿Está terminada la tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Eso debería enseñar a los despellejadores de roca a mantenerse a distancia.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Eso debería enseñar a los despellejadores de roca a mantenerse a distancia.', 0);
-- 9342 Revientacortezas merodeadores
-- https://es.wowhead.com/quest=9342
SET @ID := 9342;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. ¿Tienes algo bajo la manga para que los peones se ganen el sustento?', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. ¿Tienes algo bajo la manga para que los peones se ganen el sustento?', 0);
-- 9345 Preparar el bálsamo
-- https://es.wowhead.com/quest=9345
SET @ID := 9345;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído las plantas?', 0),
(@ID, 'esMX', '¿Has traído las plantas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deberían servir. Prepararé el bálsamo y acabaré mi tablilla antes de regresar a Thrallmar. ¿Por qué tengo la sensación de que sé lo que la clarividente Regulkult dirá cuando me vea?$B$B<Grelag suspira desanimado.>$B$BGracias por tu ayuda, $n. Me queda algo de espinela. Puedes llevártela si quieres. ¿Quién sabe cuándo puede hacer falta?', 0),
(@ID, 'esMX', 'Deberían servir. Prepararé el bálsamo y acabaré mi tablilla antes de regresar a Thrallmar. ¿Por qué tengo la sensación de que sé lo que la clarividente Regulkult dirá cuando me vea?$B$B<Grelag suspira desanimado.>$B$BGracias por tu ayuda, $n. Me queda algo de espinela. Puedes llevártela si quieres. ¿Quién sabe cuándo puede hacer falta?', 0);
-- 9349 Redada de huevos de devastador
-- https://es.wowhead.com/quest=9349
SET @ID := 9349;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya esos huevos?$B$B<El estómago de Legassi ruge de anticipación.>', 0),
(@ID, 'esMX', '¿Tienes ya esos huevos?$B$B<El estómago de Legassi ruge de anticipación.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para conseguir una gran cocina, se necesitan grandes ingredientes. ¡Y estos huevos tienen un gran aspecto!$B$BAcabo de limpiar mi sartén ¡así que te invito con gusto a compartir una comida!', 0),
(@ID, 'esMX', 'Para conseguir una gran cocina, se necesitan grandes ingredientes. ¡Y estos huevos tienen un gran aspecto!$B$BAcabo de limpiar mi sartén ¡así que te invito con gusto a compartir una comida!', 0);
-- 9351 Abisarios enloquecidos
-- https://es.wowhead.com/quest=9351
SET @ID := 9351;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la esencia?', 0),
(@ID, 'esMX', '¿Has conseguido la esencia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es perfecto! De hecho, creo que va a funcionar tan bien que puede que tenga que rediseñar el motor para aprovechar todo este poder adicional. Si... digo, cuando salgamos de aquí ¡tendré que enseñar mi diseño a todo el mundo del Área 52!', 0),
(@ID, 'esMX', '¡Esto es perfecto! De hecho, creo que va a funcionar tan bien que puede que tenga que rediseñar el motor para aprovechar todo este poder adicional. Si... digo, cuando salgamos de aquí ¡tendré que enseñar mi diseño a todo el mundo del Área 52!', 0);
-- 9355 Un trabajo para alguien inteligente
-- https://es.wowhead.com/quest=9355
SET @ID := 9355;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste despejar el camino?', 0),
(@ID, 'esMX', '¿Pudiste despejar el camino?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Aunque no deberíamos precipitarnos en celebrarlo. Seguro que no hemos visto el último de esos gusanos. Si vuelven a enseñar su espantosa cara por estos lares, ¡los Hijos estarán preparados para ellos!', 0),
(@ID, 'esMX', 'Muy bien, $n. Aunque no deberíamos precipitarnos en celebrarlo. Seguro que no hemos visto el último de esos gusanos. Si vuelven a enseñar su espantosa cara por estos lares, ¡los Hijos estarán preparados para ellos!', 0);
-- 9356 Suave como una pluma
-- https://es.wowhead.com/quest=9356
SET @ID := 9356;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me muero por ver la cara que pone cuando se asome. Desde el accidente, no ha parado de quejarse de que solo pienso en la comida. ¡Bueno, alguien tiene que alimentarnos mientras él trastea con el zepelín!', 0),
(@ID, 'esMX', 'Me muero por ver la cara que pone cuando se asome. Desde el accidente, no ha parado de quejarse de que solo pienso en la comida. ¡Bueno, alguien tiene que alimentarnos mientras él trastea con el zepelín!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Huevos de devastador. ¡Olé!$B$BBacón de jabinferno. ¡Olé!$B$BAlas de águila ratonera. ¡Olé! ¡Y olé!$B$B¡Qué festín! De verdad, tienes que probarlo.', 0),
(@ID, 'esMX', 'Huevos de devastador. ¡Olé!$B$BBacón de jabinferno. ¡Olé!$B$BAlas de águila ratonera. ¡Olé! ¡Y olé!$B$B¡Qué festín! De verdad, tienes que probarlo.', 0);
-- 9361 Huevos fritos con jabinferno
-- https://es.wowhead.com/quest=9361
SET @ID := 9361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste purificar la carne de jabinferno?', 0),
(@ID, 'esMX', '¿Pudiste purificar la carne de jabinferno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm...$B$BBien salpimentado, esto podría ser comestible. Pero no le digas a Screed de dónde ha salido el desayuno, ¿de acuerdo?', 0),
(@ID, 'esMX', 'Mmm...$B$BBien salpimentado, esto podría ser comestible. Pero no le digas a Screed de dónde ha salido el desayuno, ¿de acuerdo?', 0);
-- 9362 Señor de la guerra Krellian
-- https://es.classic.wowhead.com/quest=9362
SET @ID := 9362;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No hay tiempo que perder! ¿Tienes la concha?', 0),
(@ID, 'esMX', '¡No hay tiempo que perder! ¿Tienes la concha?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo decir que esta concha tiene un aura extraño. Parece apropiado que parte de tu recompensa por recuperarlo sea probar sus capacidades mágicas...', 0),
(@ID, 'esMX', 'Debo decir que esta concha tiene un aura extraño. Parece apropiado que parte de tu recompensa por recuperarlo sea probar sus capacidades mágicas...', 0);
-- 9364 Magia fragmentada
-- https://es.classic.wowhead.com/quest=9364
SET @ID := 9364;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recogido la magia?', 0),
(@ID, 'esMX', '¿Has recogido la magia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espléndido! ¡Espléndido!$B$BAhora podemos recrear esta magia en un nuevo hechizo. ¡Mira!', 0),
(@ID, 'esMX', '¡Espléndido! ¡Espléndido!$B$BAhora podemos recrear esta magia en un nuevo hechizo. ¡Mira!', 0);
