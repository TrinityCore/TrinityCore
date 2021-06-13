-- 9688 Entrando en el Sueño
-- https://es.wowhead.com/quest=9688
SET @ID := 9688;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me duele mirar. Por favor, no hablemos más de esto.', 0),
(@ID, 'esMX', 'Me duele mirar. Por favor, no hablemos más de esto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por reprochable que fuera tu tarea, alguien tenía que hacerla. Ahora tienes que mirar a la maldad a la cara.', 0),
(@ID, 'esMX', 'Por reprochable que fuera tu tarea, alguien tenía que hacerla. Ahora tienes que mirar a la maldad a la cara.', 0);
-- 9689 Tajobuche
-- https://es.wowhead.com/quest=9689
SET @ID := 9689;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te recomiendo que traigas aliados, $n.', 0),
(@ID, 'esMX', 'Te recomiendo que traigas aliados, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuánto tiempo ha pasado? ¿Mil años? ¿Diez mil? Nos has rendido a mí y al recuerdo de mi gente un gran servicio, $n. Acepta este objeto de poder como muestra de la gratitud de Loreth\'Aran. Es un tributo a tus hazañas.', 0),
(@ID, 'esMX', '¿Cuánto tiempo ha pasado? ¿Mil años? ¿Diez mil? Nos has rendido a mí y al recuerdo de mi gente un gran servicio, $n. Acepta este objeto de poder como muestra de la gratitud de Loreth\'Aran. Es un tributo a tus hazañas.', 0);
-- 9690 La segunda prueba
-- https://es.wowhead.com/quest=9690
SET @ID := 9690;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando estés $glisto:lista;, te contaré más sobre la prueba a la que te someterás. Haz tus preparativos y vuelve a hablar conmigo cuando quieras empezar.', 0),
(@ID, 'esMX', 'Cuando estés $glisto:lista;, te contaré más sobre la prueba a la que te someterás. Haz tus preparativos y vuelve a hablar conmigo cuando quieras empezar.', 0);
-- 9691 Regresa a Lunargenta
-- https://es.wowhead.com/quest=9691
SET @ID := 9691;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabía que tenías potencial para superar la prueba, $n. Tus obligaciones restantes son en su mayoría ceremoniales, pero no son menos peligrosas que mirar fijamente a uno de nuestros campeones con su arma desenvainada. Escucha atentamente y te diré qué más debes hacer para reclamar tu nuevo rango.', 0),
(@ID, 'esMX', 'Sabía que tenías potencial para superar la prueba, $n. Tus obligaciones restantes son en su mayoría ceremoniales, pero no son menos peligrosas que mirar fijamente a uno de nuestros campeones con su arma desenvainada. Escucha atentamente y te diré qué más debes hacer para reclamar tu nuevo rango.', 0);
-- 9692 El camino de los adeptos
-- https://es.wowhead.com/quest=9692
SET @ID := 9692;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho todo lo que te pedí?', 0),
(@ID, 'esMX', '¿Has hecho todo lo que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. Todo esta aqui. Todo lo que queda es forjar el arma.', 0),
(@ID, 'esMX', 'Excelente, $n. Todo esta aqui. Todo lo que queda es forjar el arma.', 0);
-- 9693 ¿Qué es Argus para ti?
-- https://es.wowhead.com/quest=9693
SET @ID := 9693;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, he oído hablar de ti. Tú terminaste la carrera de Kessel en menos de 15 minutos, ¿verdad? O no, creo que no.$B$B¿Te apetece derramar sangre en nombre de la Luz? ¿De Velen? ¿De Argus?$B$B<Boros se ríe.> $B$BVale, iré más despacio.', 0),
(@ID, 'esMX', 'Ah, $n, he oído hablar de ti. Tú terminaste la carrera de Kessel en menos de 15 minutos, ¿verdad? O no, creo que no.$B$B¿Te apetece derramar sangre en nombre de la Luz? ¿De Velen? ¿De Argus?$B$B<Boros se ríe.> $B$BVale, iré más despacio.', 0);
-- 9694 Avanzada de Sangre
-- https://es.wowhead.com/quest=9694
SET @ID := 9694;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay tantos de ellos que no puedo evitar pensar que de alguna manera se están multiplicando.', 0),
(@ID, 'esMX', 'Hay tantos de ellos que no puedo evitar pensar que de alguna manera se están multiplicando.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¡Y de una pieza!$B$BTengo buenas noticias, $n. Hemos recibido información sobre la posible ubicación de más supervivientes. ¡Se han descubierto más restos del accidente! Te llamaré cuando termine de ocuparme de todo esto.', 0),
(@ID, 'esMX', 'Has vuelto. ¡Y de una pieza!$B$BTengo buenas noticias, $n. Hemos recibido información sobre la posible ubicación de más supervivientes. ¡Se han descubierto más restos del accidente! Te llamaré cuando termine de ocuparme de todo esto.', 0);
-- 9696 Traducciones
-- https://es.wowhead.com/quest=9696
SET @ID := 9696;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo bastante trabajo, agente $n. Espero que esto sea importante.', 0),
(@ID, 'esMX', 'Tengo bastante trabajo, agente $n. Espero que esto sea importante.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Elysia lee el documento.>$B$BSi esto es cierto, ¡los elfos de sangre han abierto un portal a Terrallende! Eso explicaría por qué cada vez parece haber más...', 0),
(@ID, 'esMX', '<Elysia lee el documento.>$B$BSi esto es cierto, ¡los elfos de sangre han abierto un portal a Terrallende! Eso explicaría por qué cada vez parece haber más...', 0);
-- 9697 La vigía Leesa'oh
-- https://es.wowhead.com/quest=9697
SET @ID := 9697;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bien... ¡ayuda por fin! Hay tanto por hacer y necesito que te quedes para organizarlo todo.$B$BEspero que no te importe pringarte las manos.', 0),
(@ID, 'esMX', 'Ah, bien... ¡ayuda por fin! Hay tanto por hacer y necesito que te quedes para organizarlo todo.$B$BEspero que no te importe pringarte las manos.', 0);
-- 9698 Audiencia con el Profeta
-- https://es.wowhead.com/quest=9698
SET @ID := 9698;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Velen sonríe.>$B$BSaludos, $n. Te estaba esperando.', 0),
(@ID, 'esMX', '<Velen sonríe.>$B$BSaludos, $n. Te estaba esperando.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Velen empieza a leer el documento.>$B$BInteresante... Esto explica muchas cosas.', 0),
(@ID, 'esMX', '<Velen empieza a leer el documento.>$B$BInteresante... Esto explica muchas cosas.', 0);
-- 9699 Verdad o mentira
-- https://es.wowhead.com/quest=9699
SET @ID := 9699;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien?', 0),
(@ID, 'esMX', '¿Y bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un buen plan, pero peligroso. Seguro que estarás bien.', 0),
(@ID, 'esMX', 'Es un buen plan, pero peligroso. Seguro que estarás bien.', 0);
-- 9700 Disparando magia en la oscuridad
-- https://es.wowhead.com/quest=9700
SET @ID := 9700;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado escuchando informes de extrañas criaturas que aparecen en el área. Si son animales indígenas mutados o verdaderas anomalías del vacío es algo que debes averiguar.', 0),
(@ID, 'esMX', 'He estado escuchando informes de extrañas criaturas que aparecen en el área. Si son animales indígenas mutados o verdaderas anomalías del vacío es algo que debes averiguar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuántas anomalías dices que viste en El Pistón de Distorsión? ¿Cuántas veces abrieron el portal del Sol? Esto son muy malas noticias...$B$BYa has aprendido cuanto podía enseñarte, $n. Kuros te llamará cuando llegue el momento.', 0),
(@ID, 'esMX', '¿Cuántas anomalías dices que viste en El Pistón de Distorsión? ¿Cuántas veces abrieron el portal del Sol? Esto son muy malas noticias...$B$BYa has aprendido cuanto podía enseñarte, $n. Kuros te llamará cuando llegue el momento.', 0);
-- 9701 Observación de esporinos
-- https://es.wowhead.com/quest=9701
SET @ID := 9701;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Regresaste tan pronto? Tu observación de los esporinos de Esporaggar es fundamental para mi investigación. Espero que no seas del tipo que apresura las cosas. Muestra paciencia y asegúrate de haber explorado la totalidad de La Cañada Emergente antes de darme tu informe final.', 0),
(@ID, 'esMX', '¿Regresaste tan pronto? Tu observación de los esporinos de Esporaggar es fundamental para mi investigación. Espero que no seas del tipo que apresura las cosas. Muestra paciencia y asegúrate de haber explorado la totalidad de La Cañada Emergente antes de darme tu informe final.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Qué?! ¿Los señores de la marisma de Cresta Quagg se están comiendo las vainas de esporinos? ¡Esto no puede ser!', 0),
(@ID, 'esMX', '¡¿Qué?! ¿Los señores de la marisma de Cresta Quagg se están comiendo las vainas de esporinos? ¡Esto no puede ser!', 0);
-- 9702 Cuestión de glotonería
-- https://es.wowhead.com/quest=9702
SET @ID := 9702;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Recoge todas las pruebas con cuidado, $c! Estamos reconstruyendo un gran rompecabezas; cualquier equivocación por tu parte podría llevarnos a conclusiones erróneas.$B$BEn ese caso, nos sería imposible comprender el ecosistema de la Marisma de Zangar.', 0),
(@ID, 'esMX', '¡Recoge todas las pruebas con cuidado, $c! Estamos reconstruyendo un gran rompecabezas; cualquier equivocación por tu parte podría llevarnos a conclusiones erróneas.$B$BEn ese caso, nos sería imposible comprender el ecosistema de la Marisma de Zangar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Esto has encontrado? Qué raro. Estas setas recubiertas son raras y al mismo tiempo familiares.$B$BTengo que reflexionar un poco. ¡No te vayas de aquí!', 0),
(@ID, 'esMX', '¿Esto has encontrado? Qué raro. Estas setas recubiertas son raras y al mismo tiempo familiares.$B$BTengo que reflexionar un poco. ¡No te vayas de aquí!', 0);
-- 9703 El Crionúcleo
-- https://es.wowhead.com/quest=9703
SET @ID := 9703;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Era la información correcta?', 0),
(@ID, 'esMX', '¿Era la información correcta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Solo elfos de sangre? ¿Ningún superviviente? Esto es preocupante. Necesito algún tiempo para pensar detenidamente, $n. Quizás Aesom o Boros tengan alguna tarea para ti.', 0),
(@ID, 'esMX', '¿Solo elfos de sangre? ¿Ningún superviviente? Esto es preocupante. Necesito algún tiempo para pensar detenidamente, $n. Quizás Aesom o Boros tengan alguna tarea para ti.', 0);
-- 9706 El diario de Galaen: El destino del vindicador Saruan
-- https://es.wowhead.com/quest=9706
SET @ID := 9706;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué traes, $n? ¿Es un diario?', 0),
(@ID, 'esMX', '¿Qué traes, $n? ¿Es un diario?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kuros palidece y se le saltan las lágrimas al leer el diario.>$B$BSaruan fue mi maestro, mi mentor... Hace poco que acepté este puesto en el Triunvirato, cuando abandonamos la búsqueda de Saruan...$B$B<Pone cara de furia.>$B$BMatis...', 0),
(@ID, 'esMX', '<Kuros palidece y se le saltan las lágrimas al leer el diario.>$B$BSaruan fue mi maestro, mi mentor... Hace poco que acepté este puesto en el Triunvirato, cuando abandonamos la búsqueda de Saruan...$B$B<Pone cara de furia.>$B$BMatis...', 0);
-- 9707 Forjando el arma
-- https://es.wowhead.com/quest=9707
SET @ID := 9707;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Felicitaciones, $n. Alcanzar el rango de $gadepto:adepta; no es tarea fácil, créeme. He visto la cantidad de personas que ingresan a ese edificio y cómo pocas de ellas duran lo suficiente para volver con estos materiales.', 0),
(@ID, 'esMX', 'Felicitaciones, $n. Alcanzar el rango de $gadepto:adepta; no es tarea fácil, créeme. He visto la cantidad de personas que ingresan a ese edificio y cómo pocas de ellas duran lo suficiente para volver con estos materiales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que tienes todo lo que necesito. ¡Empecemos!', 0),
(@ID, 'esMX', 'Parece que tienes todo lo que necesito. ¡Empecemos!', 0);
-- 9708 Ese hongo me suena
-- https://es.wowhead.com/quest=9708
SET @ID := 9708;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya esas muestras?', 0),
(@ID, 'esMX', '¿Tienes ya esas muestras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Desde luego tenemos una coincidencia. Y la presencia de los ogros y lo que estaban haciendo allí lo explica todo. Ahora entiendo por qué se llama la Ciénaga Talada, ¡puaj!$B$BTenemos que hacer algo ¡¿pero qué?! No podemos simplemente barrer a todos esos ogros; ¡tienen tanto derecho a estar aquí como cualquier otra criatura de la marisma!', 0),
(@ID, 'esMX', 'Desde luego tenemos una coincidencia. Y la presencia de los ogros y lo que estaban haciendo allí lo explica todo. Ahora entiendo por qué se llama la Ciénaga Talada, ¡puaj!$B$BTenemos que hacer algo ¡¿pero qué?! No podemos simplemente barrer a todos esos ogros; ¡tienen tanto derecho a estar aquí como cualquier otra criatura de la marisma!', 0);
-- 9709 Volver a robar los champiñones
-- https://es.wowhead.com/quest=9709
SET @ID := 9709;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes todos los champiñones que necesitamos para crear un nuevo jardín para los señores de la marisma?', 0),
(@ID, 'esMX', '¿Tienes todos los champiñones que necesitamos para crear un nuevo jardín para los señores de la marisma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Son perfectos! ¡Gracias, $c!$B$BHas tenido buen cuidado de no perturbar el orden natural de las cosas ¡y hemos reunido tanta información en tan poco espacio de tiempo!$B$BVeamos ahora si nuestro plan de cultivar un nuevo suministro alimentario para los señores de la marisma funcionará.', 0),
(@ID, 'esMX', '¡Son perfectos! ¡Gracias, $c!$B$BHas tenido buen cuidado de no perturbar el orden natural de las cosas ¡y hemos reunido tanta información en tan poco espacio de tiempo!$B$BVeamos ahora si nuestro plan de cultivar un nuevo suministro alimentario para los señores de la marisma funcionará.', 0);
-- 9710 La corcesca templada en sangre
-- https://es.wowhead.com/quest=9710
SET @ID := 9710;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está, $n. Úsala bien al servicio de Lunargenta y a tu orden.', 0),
(@ID, 'esMX', 'Aquí está, $n. Úsala bien al servicio de Lunargenta y a tu orden.', 0);
-- 9711 Matis el Cruel
-- https://es.wowhead.com/quest=9711
SET @ID := 9711;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Triunvirato ha decidido juzgar a Matis de inmediato. Has traído a un archicriminal ante la justicia, $r.$B$BLo has hecho admirablemente con dos de tres; ahora solo queda Aesom.', 0),
(@ID, 'esMX', 'El Triunvirato ha decidido juzgar a Matis de inmediato. Has traído a un archicriminal ante la justicia, $r.$B$BLo has hecho admirablemente con dos de tres; ahora solo queda Aesom.', 0);
-- 9714 ¡Tráeme otra mata!
-- https://es.wowhead.com/quest=9714
SET @ID := 9714;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía podemos usar más Hibisco sanguino de los Arrastrapiés, gigantes de la marisma y Submurciélagos de La Sotiénaga en la Reserva Colmillo Torcido. Tráemelos en grupos de cinco y te estaré muy agradecido.', 0),
(@ID, 'esMX', 'Todavía podemos usar más Hibisco sanguino de los Arrastrapiés, gigantes de la marisma y Submurciélagos de La Sotiénaga en la Reserva Colmillo Torcido. Tráemelos en grupos de cinco y te estaré muy agradecido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos funcionarán bien, pero siempre podemos usar más. ¿Quizás vuelves pronto a La Sotiénaga?', 0),
(@ID, 'esMX', 'Estos funcionarán bien, pero siempre podemos usar más. ¿Quizás vuelves pronto a La Sotiénaga?', 0);
-- 9715 ¡Tráeme una mata!
-- https://es.wowhead.com/quest=9715
SET @ID := 9715;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes todo el hibisco que te pedí que recogieras?', 0),
(@ID, 'esMX', '¿Tienes todo el hibisco que te pedí que recogieras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos funcionarán bien, pero siempre podemos usar más. ¿Quizás vuelves pronto a La Sotiénaga?', 0),
(@ID, 'esMX', 'Estos funcionarán bien, pero siempre podemos usar más. ¿Quizás vuelves pronto a La Sotiénaga?', 0);
-- 9716 Problemas en el Lago Umbropantano
-- https://es.wowhead.com/quest=9716
SET @ID := 9716;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Descubriste algo, $n?', 0),
(@ID, 'esMX', '¿Descubriste algo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Han sido los nagas! Pero ¿por qué? Por lo que dices, esa bomba de vapor es responsable del descenso del nivel de agua en la marisma.$B$BNo importa; esto explica su hostilidad hacia nosotros. No perdamos más tiempo, tengo otra misión para ti.', 0),
(@ID, 'esMX', '¡Han sido los nagas! Pero ¿por qué? Por lo que dices, esa bomba de vapor es responsable del descenso del nivel de agua en la marisma.$B$BNo importa; esto explica su hostilidad hacia nosotros. No perdamos más tiempo, tengo otra misión para ti.', 0);
-- 9717 El esqueje
-- https://es.wowhead.com/quest=9717
SET @ID := 9717;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Sotiénaga es un lugar muy peligroso. No te consideraría $gun:una; cobarde si te negaras a ir allí. Tampoco te agradecería que no regresaras con lo que te he pedido.', 0),
(@ID, 'esMX', 'La Sotiénaga es un lugar muy peligroso. No te consideraría $gun:una; cobarde si te negaras a ir allí. Tampoco te agradecería que no regresaras con lo que te he pedido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El esporino emite un sonido que recuerda vagamente a una risa resoplando.>$B$B¡Perfecto! Sin duda, la moral de los gigantes de esporas estará en su punto más bajo una vez que se den cuenta de lo que has hecho.$B$BO eso, o estarán tan indignados que pronto nos atacarán de nuevo.$B$B<T\'shu se encoge de hombros.>', 0),
(@ID, 'esMX', '<El esporino emite un sonido que recuerda vagamente a una risa resoplando.>$B$B¡Perfecto! Sin duda, la moral de los gigantes de esporas estará en su punto más bajo una vez que se den cuenta de lo que has hecho.$B$BO eso, o estarán tan indignados que pronto nos atacarán de nuevo.$B$B<T\'shu se encoge de hombros.>', 0);
-- 9718 A vuelo de pájaro
-- https://es.wowhead.com/quest=9718
SET @ID := 9718;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n.', 0),
(@ID, 'esMX', 'Saludos, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es lo que sospechaba. Los nagas han instalado bombas de succión en los lagos principales de la Marisma de Zangar.$B$BSi queremos salvar la marisma, hay que detenerlos.', 0),
(@ID, 'esMX', 'Es lo que sospechaba. Los nagas han instalado bombas de succión en los lagos principales de la Marisma de Zangar.$B$BSi queremos salvar la marisma, hay que detenerlos.', 0);
-- 9719 El acechador acechado
-- https://es.wowhead.com/quest=9719
SET @ID := 9719;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado. ¿Significa esto que La Acechadora Negra ya no existe?', 0),
(@ID, 'esMX', 'Has regresado. ¿Significa esto que La Acechadora Negra ya no existe?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La Acechadora Negra está muerta! Normalmente no me deleitaría con semejante carnicería, pero el dolor por el que la gran madre y su prole han hecho pasar a mi pueblo a lo largo de los siglos es indescriptible.$B$BEs lamentable que ahora otro de su progenie se transforme para reemplazarla, pero eso llevará tiempo y nos dará un respiro para que no tengamos que preocuparnos por los caminantes de de marisma por un tiempo.', 0),
(@ID, 'esMX', '¡La Acechadora Negra está muerta! Normalmente no me deleitaría con semejante carnicería, pero el dolor por el que la gran madre y su prole han hecho pasar a mi pueblo a lo largo de los siglos es indescriptible.$B$BEs lamentable que ahora otro de su progenie se transforme para reemplazarla, pero eso llevará tiempo y nos dará un respiro para que no tengamos que preocuparnos por los caminantes de de marisma por un tiempo.', 0);
-- 9720 Restaurar el equilibrio
-- https://es.wowhead.com/quest=9720
SET @ID := 9720;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Control del Lago Umbropantano desactivado', `ObjectiveText2` = 'Control del Lago Luz Pantanosa desactivado', `ObjectiveText3` = 'Control del Lago Serpiente desactivado', `ObjectiveText4` = 'Control de La Laguna desactivado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho, $c?', 0),
(@ID, 'esMX', '¿Está hecho, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces ya está. La marisma está a salvo... por ahora.$B$BNo pienses ni por un momento que esta será la última vez veamos a los nagas. Debemos vigilar siempre a nuestro enemigo y continuar con nuestra misión en Terrallende.', 0),
(@ID, 'esMX', 'Entonces ya está. La marisma está a salvo... por ahora.$B$BNo pienses ni por un momento que esta será la última vez veamos a los nagas. Debemos vigilar siempre a nuestro enemigo y continuar con nuestra misión en Terrallende.', 0);
-- 9721 Lord Solanar te convoca
-- https://es.wowhead.com/quest=9721
SET @ID := 9721;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Discutiremos el propósito de tu visita pronto. Primero. permíteme decirte que estoy realmente impresionado por tu servicio y tu habilidad para manejar la Luz.', 0),
(@ID, 'esMX', 'Discutiremos el propósito de tu visita pronto. Primero. permíteme decirte que estoy realmente impresionado por tu servicio y tu habilidad para manejar la Luz.', 0);
-- 9722 El camino del maestro
-- https://es.wowhead.com/quest=9722
SET @ID := 9722;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que hayas elegido aceptar mi oferta habla bien de ti, $n. Te deseo suerte en las tareas que estoy a punto de encomendarte, pero estoy seguro de que serás más que capaz.$B$BPresentaré las tareas en orden de la más fácil a la más difícil y podemos comenzar cuando estés $gpreparado:preparada;.', 0),
(@ID, 'esMX', 'Que hayas elegido aceptar mi oferta habla bien de ti, $n. Te deseo suerte en las tareas que estoy a punto de encomendarte, pero estoy seguro de que serás más que capaz.$B$BPresentaré las tareas en orden de la más fácil a la más difícil y podemos comenzar cuando estés $gpreparado:preparada;.', 0);
-- 9723 Un gesto de entrega
-- https://es.wowhead.com/quest=9723
SET @ID := 9723;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha vuelto con los materiales que requiere el Magister Astalor?', 0),
(@ID, 'esMX', '¿Ha vuelto con los materiales que requiere el Magister Astalor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente. Parece que todo está aquí.$B$BNo te preocupes. tu próxima tarea incluirá muchas oportunidades para empuñar tu arma de nuevo, lo prometo.$B$BHaré que un iniciado se lo lleve todo al Magister Astalor. No es necesario que te envíe a hacer un recado tan trivial cuando hay cosas más importantes que hacer.', 0),
(@ID, 'esMX', 'Excelente. Parece que todo está aquí.$B$BNo te preocupes. tu próxima tarea incluirá muchas oportunidades para empuñar tu arma de nuevo, lo prometo.$B$BHaré que un iniciado se lo lleve todo al Magister Astalor. No es necesario que te envíe a hacer un recado tan trivial cuando hay cosas más importantes que hacer.', 0);
-- 9724 Advertir al Círculo Cenarion
-- https://es.wowhead.com/quest=9724
SET @ID := 9724;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La noticia de actividad naga en la Marisma de Zangar es preocupante. Ysiel fue muy prudente al enviarte. No ha olvidado que la expedición no puede existir sin el apoyo del Círculo.', 0),
(@ID, 'esMX', 'La noticia de actividad naga en la Marisma de Zangar es preocupante. Ysiel fue muy prudente al enviarte. No ha olvidado que la expedición no puede existir sin el apoyo del Círculo.', 0);
-- 9725 Una demostración de lealtad
-- https://es.wowhead.com/quest=9725
SET @ID := 9725;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Destruir los carros de despojos de la Plaga', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has derrotado a la Plaga y sus carros de despojos?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has derrotado a la Plaga y sus carros de despojos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha hecho bien en demostrar tu lealtad a tu patria y dedicación a las necesidades de la orden, $n. Tengo una última tarea para ti antes de que puedas reclamar el título de maestro.', 0),
(@ID, 'esMX', 'Ha hecho bien en demostrar tu lealtad a tu patria y dedicación a las necesidades de la orden, $n. Tengo una última tarea para ti antes de que puedas reclamar el título de maestro.', 0);
-- 9726 Ahora que somos amigos...
-- https://es.wowhead.com/quest=9726
SET @ID := 9726;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya le has hecho una visita a los naga?', 0),
(@ID, 'esMX', '¿Ya le has hecho una visita a los naga?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gzhun\'tt te señala con la cabeza.>$B$BNos alegramos de ver nuestra amistad reafirmada, $n. Quizás los paganos nagas se lo piensen dos veces en el futuro antes de acosarnos ahora que tenemos $gun aliado:una aliada; tan $gpoderoso:poderosa;.', 0),
(@ID, 'esMX', '<Gzhun\'tt te señala con la cabeza.>$B$BNos alegramos de ver nuestra amistad reafirmada, $n. Quizás los paganos nagas se lo piensen dos veces en el futuro antes de acosarnos ahora que tenemos $gun aliado:una aliada; tan $gpoderoso:poderosa;.', 0);
-- 9727 Ahora que aún somos amigos...
-- https://es.wowhead.com/quest=9727
SET @ID := 9727;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya le has hecho una visita a los naga?', 0),
(@ID, 'esMX', '¿Ya le has hecho una visita a los naga?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gzhun\'tt te señala con la cabeza.>$B$BNos alegramos de ver nuestra amistad reafirmada, $n. Ahora que les has dejado las cosas claras varias veces, cesarán sus estúpidos ataques sobre nuestro pueblo, ¿no?', 0),
(@ID, 'esMX', '<Gzhun\'tt te señala con la cabeza.>$B$BNos alegramos de ver nuestra amistad reafirmada, $n. Ahora que les has dejado las cosas claras varias veces, cesarán sus estúpidos ataques sobre nuestro pueblo, ¿no?', 0);
-- 9728 Una cálida bienvenida
-- https://es.wowhead.com/quest=9728
SET @ID := 9728;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de volver a verte, $n. ¿Cómo va tu caza de nagas?', 0),
(@ID, 'esMX', 'Me alegro de volver a verte, $n. ¿Cómo va tu caza de nagas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Harías bien en liberarte de cualquier sentimiento de remordimiento que puedas abrigar. Estos nagas son criaturas perversas, incluso más que las de Azeroth.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Harías bien en liberarte de cualquier sentimiento de remordimiento que puedas abrigar. Estos nagas son criaturas perversas, incluso más que las de Azeroth.', 0);
-- 9729 ¡Fhwoor da el golpe!
-- https://es.wowhead.com/quest=9729
SET @ID := 9729;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Fwhoor está bien? ¿Has recuperado el arca?', 0),
(@ID, 'esMX', '¿Fwhoor está bien? ¿Has recuperado el arca?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fhwoor es un gigante bueno. Lo salvamos de los nagas hace algún tiempo y desde entonces se ha quedado con nosotros para ayudarnos.$B$BSolo podemos esperar que los nagas entenderán la indirecta y se den cuenta de que si podemos infiltrarnos en su aldea y robar su más preciada posesión, podemos hacer algo mucho peor. A lo mejor ahora volverán a su hogar, la Presa, y nos dejan en paz.', 0),
(@ID, 'esMX', 'Fhwoor es un gigante bueno. Lo salvamos de los nagas hace algún tiempo y desde entonces se ha quedado con nosotros para ayudarnos.$B$BSolo podemos esperar que los nagas entenderán la indirecta y se den cuenta de que si podemos infiltrarnos en su aldea y robar su más preciada posesión, podemos hacer algo mucho peor. A lo mejor ahora volverán a su hogar, la Presa, y nos dejan en paz.', 0);
