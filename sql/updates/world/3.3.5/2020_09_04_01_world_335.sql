-- 505 Hermandad de asesinos
-- https://es.classic.wowhead.com/quest=505
SET @ID := 505;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha matado a esos matones de la Hermandad?', 0),
(@ID, 'esMX', '¿Ha matado a esos matones de la Hermandad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Espero que algunos de los asaltantes de caminos y ladrones que has matado fueran responsables de la muerte del magistrado. Y aunque no fuera así, la Hermandad es una lacra que debe ser erradicada.$B$BEn Costasur se celebran esas muertes.', 0),
(@ID, 'esMX', 'Gracias, $n. Espero que algunos de los asaltantes de caminos y ladrones que has matado fueran responsables de la muerte del magistrado. Y aunque no fuera así, la Hermandad es una lacra que debe ser erradicada.$B$BEn Costasur se celebran esas muertes.', 0);
-- 9435 Los cristales desaparecidos
-- https://es.wowhead.com/quest=9435
SET @ID := 9435;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste recuperar los cristales de los Renegados?', 0),
(@ID, 'esMX', '¿Pudiste recuperar los cristales de los Renegados?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a la Luz! Por el tono de la carta del capataz, sonaba como si esa caja de cristales contuviera las únicas muestras conocidas de la mina. Si los hubiéramos perdido, $n, es posible que nunca hubiéramos visto otro igual.$B$BNo puedo agradecerte lo suficiente tu ayuda.', 0),
(@ID, 'esMX', '¡Gracias a la Luz! Por el tono de la carta del capataz, sonaba como si esa caja de cristales contuviera las únicas muestras conocidas de la mina. Si los hubiéramos perdido, $n, es posible que nunca hubiéramos visto otro igual.$B$BNo puedo agradecerte lo suficiente tu ayuda.', 0);
-- 536 Al lo largo de la costa
-- https://es.wowhead.com/quest=536
SET @ID := 536;
UPDATE `quest_template_locale` SET `Title` = 'A lo largo de la costa', `VerifiedBuild` = 0 WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otra cerveza, por favor, ¡la última parecía haber desaparecido!$B$BPor la Luz, ¿cuánto tiempo más voy a estar atrapado aquí?$B$BOh, eres tú, $N. ¿Ya mataste a esos múrlocs?', 0),
(@ID, 'esMX', 'Otra cerveza, por favor, ¡la última parecía haber desaparecido!$B$BPor la Luz, ¿cuánto tiempo más voy a estar atrapado aquí?$B$BOh, eres tú, $N. ¿Ya mataste a esos múrlocs?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así Rutagrana se convencerá de que he cumplido sus órdenes... Es un decir. En fin, el caso es que ya no hay murlocs gracias a ti.', 0),
(@ID, 'esMX', 'Así Rutagrana se convencerá de que he cumplido sus órdenes... Es un decir. En fin, el caso es que ya no hay murlocs gracias a ti.', 0);
-- 555 Sopa de tortuga reconfortante
-- https://es.classic.wowhead.com/quest=555
SET @ID := 555;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste los ingredientes? Esta tierra ya no es tan tranquila como antes. Ay, qué tiempos...', 0),
(@ID, 'esMX', '¿Encontraste los ingredientes? Esta tierra ya no es tan tranquila como antes. Ay, qué tiempos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo el mundo estará encantado de que vuelva a haber sopa de tortuga en el menú.', 0),
(@ID, 'esMX', 'Todo el mundo estará encantado de que vuelva a haber sopa de tortuga en el menú.', 0);
-- 1053 En el nombre de la Luz
-- https://es.classic.wowhead.com/quest=1053
SET @ID := 1053;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción en el Monasterio no terminará hasta que los oficiales de más alto rango sean eliminados.$B$BEn nombre de la Luz, mata a la alta inquisidora Melenablanca, al Comandante Escarlata Mograine, a Herod, el Campeón Escarlata y al maestro de canes Loksey. Una vez muertos, quizás se pueda reavivar la verdadera causa. Hasta entonces, cualquiera que se cruce en el camino de la Cruzada corre peligro.$B$B¡Aventúrate desde Costasur y hazlo así!', 0),
(@ID, 'esMX', 'La corrupción en el Monasterio no terminará hasta que los oficiales de más alto rango sean eliminados.$B$BEn nombre de la Luz, mata a la alta inquisidora Melenablanca, al Comandante Escarlata Mograine, a Herod, el Campeón Escarlata y al maestro de canes Loksey. Una vez muertos, quizás se pueda reavivar la verdadera causa. Hasta entonces, cualquiera que se cruce en el camino de la Cruzada corre peligro.$B$B¡Aventúrate desde Costasur y hazlo así!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mientras que los discípulos de la Luz nunca se deleitan con la pérdida de la vida, debemos aceptar que, en algunas ocasiones, esos sacrificios deben ocurrir por el bien del reino y del planeta.$B$BGracias a tus acciones en el Monasterio se han salvado muchas vidas inocentes, $n. Aplaudo tu tenacidad.', 0),
(@ID, 'esMX', 'Mientras que los discípulos de la Luz nunca se deleitan con la pérdida de la vida, debemos aceptar que, en algunas ocasiones, esos sacrificios deben ocurrir por el bien del reino y del planeta.$B$BGracias a tus acciones en el Monasterio se han salvado muchas vidas inocentes, $n. Aplaudo tu tenacidad.', 0);
-- 559 La prueba de Farren
-- https://es.classic.wowhead.com/quest=559
SET @ID := 559;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes las cabezas, $n?', 0),
(@ID, 'esMX', '¿Me traes las cabezas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo estás poniendo todo perdido!$B$BYo no puedo tocar esas cosas; el pescado vaya y pase, pero estos bichos... Puaj. Llevo semanas sin comer pescado, y en Costasur eso es mucho decir', 0),
(@ID, 'esMX', '¡Lo estás poniendo todo perdido!$B$BYo no puedo tocar esas cosas; el pescado vaya y pase, pero estos bichos... Puaj. Llevo semanas sin comer pescado, y en Costasur eso es mucho decir', 0);
-- 560 La prueba de Farren
-- https://es.classic.wowhead.com/quest=560
SET @ID := 560;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. ¿Vienes a ayudar en la defensa de Costasur?', 0),
(@ID, 'esMX', 'Saludos. ¿Vienes a ayudar en la defensa de Costasur?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te envía Farren, ¿eh?$B$BSi tuviste algo que ver con las cabezas, te lo agradezco; necesitamos gente dispuesta a trabajar.', 0),
(@ID, 'esMX', 'Así que te envía Farren, ¿eh?$B$BSi tuviste algo que ver con las cabezas, te lo agradezco; necesitamos gente dispuesta a trabajar.', 0);
-- 561 La prueba de Farren
-- https://es.classic.wowhead.com/quest=561
SET @ID := 561;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los naga, ¿eh? Pues va listo Rutagrana si cree que va a ganarse una medalla a mi costa. Ahora te explico.', 0),
(@ID, 'esMX', 'Los naga, ¿eh? Pues va listo Rutagrana si cree que va a ganarse una medalla a mi costa. Ahora te explico.', 0);
-- 562 Cambio de destino
-- https://es.classic.wowhead.com/quest=562
SET @ID := 562;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo una carta lista para el mayor Samuelson de Ventormenta; solo necesito el informe.', 0),
(@ID, 'esMX', 'Tengo una carta lista para el mayor Samuelson de Ventormenta; solo necesito el informe.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que no hay nagas en Costasur, estoy más cerca de que me devuelvan a Ventormenta y salir de aquí de una vez.', 0),
(@ID, 'esMX', 'Ahora que no hay nagas en Costasur, estoy más cerca de que me devuelvan a Ventormenta y salir de aquí de una vez.', 0);
-- 563 Nueva asignación
-- https://es.classic.wowhead.com/quest=563
SET @ID := 563;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos. ¿Necesitas ayuda de la guardia de Ventormenta?', 0),
(@ID, 'esMX', 'Saludos. ¿Necesitas ayuda de la guardia de Ventormenta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Ah, veo que se han tomado medidas con los nagas de Costasur. Gracias, tendré en cuenta este informe.', 0),
(@ID, 'esMX', '¿Qué es esto? Ah, veo que se han tomado medidas con los nagas de Costasur. Gracias, tendré en cuenta este informe.', 0);
-- 511 Una carta cifrada
-- https://es.classic.wowhead.com/quest=511
SET @ID := 511;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Querías algo?', 0),
(@ID, 'esMX', '¿Querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Déjame ver...$B$BMmm... nunca había visto nada parecido pese a mi considerable experiencia.', 0),
(@ID, 'esMX', '¿Qué es esto? Déjame ver...$B$BMmm... nunca había visto nada parecido pese a mi considerable experiencia.', 0);
-- 510 Documentos de planificación
-- https://es.classic.wowhead.com/quest=510
SET @ID := 510;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te preocupa, $n? ¿Tienes algo que decir?', 0),
(@ID, 'esMX', '¿Qué te preocupa, $n? ¿Tienes algo que decir?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maleb lee los documentos.>$B$BEsto es muy inquietante, $n. Por lo que dice aquí y por las acciones de la Hermandad, esos rufianes han declarado la guerra a Costasur.', 0),
(@ID, 'esMX', '<Maleb lee los documentos.>$B$BEsto es muy inquietante, $n. Por lo que dice aquí y por las acciones de la Hermandad, esos rufianes han declarado la guerra a Costasur.', 0);
-- 512 Nobles muertes
-- https://es.classic.wowhead.com/quest=512
SET @ID := 512;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te estás ocupando de la Hermandad? ¿Tienes los anillos?', 0),
(@ID, 'esMX', '¿Te estás ocupando de la Hermandad? ¿Tienes los anillos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este golpe reducirá la libertad de acción de la Hermandad y los reducirá a la banda de maleantes que son.$B$BSirves muy bien a la Alianza, $n.', 0),
(@ID, 'esMX', 'Este golpe reducirá la libertad de acción de la Hermandad y los reducirá a la banda de maleantes que son.$B$BSirves muy bien a la Alianza, $n.', 0);
-- 514 Una carta para Pico Tormenta
-- https://es.classic.wowhead.com/quest=514
SET @ID := 514;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te envía Dibbs de Costasur, ¿eh? ¿Cómo le va a esa ratilla de biblioteca?', 0),
(@ID, 'esMX', 'Así que te envía Dibbs de Costasur, ¿eh? ¿Cómo le va a esa ratilla de biblioteca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, soy un especialista en códigos cifrados. A ver...', 0),
(@ID, 'esMX', 'Ah, sí, soy un especialista en códigos cifrados. A ver...', 0);
-- 525 Más misterios
-- https://es.classic.wowhead.com/quest=525
SET @ID := 525;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has estado de viaje por las montañas otra vez? ¿Qué noticias traes?', 0),
(@ID, 'esMX', '$n, ¿has estado de viaje por las montañas otra vez? ¿Qué noticias traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maleb lee la carta.>$B$B¿Esto estaba en un campamento de la Hermandad? Esto no lo escribió un ladrón ni tampoco un noble de Alterac.$B$BParece que la Hermandad está aliada con otro poder; me estremezco al pensar cuál puede ser.', 0),
(@ID, 'esMX', '<Maleb lee la carta.>$B$B¿Esto estaba en un campamento de la Hermandad? Esto no lo escribió un ladrón ni tampoco un noble de Alterac.$B$BParece que la Hermandad está aliada con otro poder; me estremezco al pensar cuál puede ser.', 0);
-- 537 Consejo oscuro
-- https://es.wowhead.com/quest=537
-- https://wow-es.gamepedia.com/Misión:Consejo oscuro
SET @ID := 537;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Localizaste a los enviados de Despertar de Argus?', 0),
(@ID, 'esMX', '¿Localizaste a los enviados de Despertar de Argus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n.$B$BPero debes saber que Nagaz no era más que un siervo; el Despertar de Argus tiene profundas raíces en Azeroth.$B$BY puede que en todo el mundo.', 0),
(@ID, 'esMX', 'Buen trabajo, $n.$B$BPero debes saber que Nagaz no era más que un siervo; el Despertar de Argus tiene profundas raíces en Azeroth.$B$BY puede que en todo el mundo.', 0);
-- 504 Belicistas Aplastacresta
-- https://es.classic.wowhead.com/quest=504
SET @ID := 504;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes más belicistas que matar, $n. Deberías estar en las montañas en tu tarea, no aquí abajo con tu arma guardada.', 0),
(@ID, 'esMX', 'Tienes más belicistas que matar, $n. Deberías estar en las montañas en tu tarea, no aquí abajo con tu arma guardada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien; aquí tienes la recompensa.$B$BDime, ¿cómo has visto Alterac? Supongo que la cosa estará mal; los ogros no son famosos por ser limpios.$B$BPor suerte, gracias a tus esfuerzos se mantendrán alejados de Costasur.', 0),
(@ID, 'esMX', 'Muy bien; aquí tienes la recompensa.$B$BDime, ¿cómo has visto Alterac? Supongo que la cosa estará mal; los ogros no son famosos por ser limpios.$B$BPor suerte, gracias a tus esfuerzos se mantendrán alejados de Costasur.', 0);
-- 13502 ¿Qué llevas en la cestita?
-- https://es.wowhead.com/quest=13502
SET @ID := 13502;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los 10 chocolates del Jardín Noble?', 0),
(@ID, 'esMX', '¿Tienes los 10 chocolates del Jardín Noble?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! ¡Ten... quédate con la cesta!$B$BRecuerda, ¡puedes venir cuando quieras a canjear chocolates del Jardín Noble por otros objetos!', 0),
(@ID, 'esMX', '¡Buen trabajo! ¡Ten... quédate con la cesta!$B$BRecuerda, ¡puedes venir cuando quieras a canjear chocolates del Jardín Noble por otros objetos!', 0);
-- 8649 Tormenceño el Ancestro
-- https://es.wowhead.com/quest=8649
SET @ID := 8649;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0),
(@ID, 'esMX', 'Me alegra saber que la gente de estas tierras sigue prestando homenaje a las antiguas razas. Te deseo todo lo mejor, $n, y te ofrezco esta muestra...', 0);
-- 7905 La Feria de la Luna Negra
-- https://es.wowhead.com/quest=7905
SET @ID := 7905;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Querías algo? ¿Tienes un vale?', 0),
(@ID, 'esMX', '¿Querías algo? ¿Tienes un vale?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te doy la bienvenida a la Feria de la Luna Negra! ¡Este vale te da derecho a CINCO, has oído bien, CINCO boletos de tómbola y una copia gratuita de la mundialmente conocida guía de campo de la Luna Negra!$B$BCuando tengas suficientes boletos, ven a verme para cambiarlos por premios. ¡Esta práctica guía de campo te ayudará a localizar e identificar los objetos de valor de los coleccionistas que hay en la feria!', 0),
(@ID, 'esMX', '¡Te doy la bienvenida a la Feria de la Luna Negra! ¡Este vale te da derecho a CINCO, has oído bien, CINCO boletos de tómbola y una copia gratuita de la mundialmente conocida guía de campo de la Luna Negra!$B$BCuando tengas suficientes boletos, ven a verme para cambiarlos por premios. ¡Esta práctica guía de campo te ayudará a localizar e identificar los objetos de valor de los coleccionistas que hay en la feria!', 0);
