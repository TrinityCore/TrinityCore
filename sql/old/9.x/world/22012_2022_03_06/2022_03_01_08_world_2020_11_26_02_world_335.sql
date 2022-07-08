-- 49 Dulce ámbar
-- https://es.classic.wowhead.com/quest=49
SET @ID := 49;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Otra? ¡Claro!$B$BÁmbar es el color del amor de mi vida$BComo las luces de un final del día$BRecupéralo y el amor volverá a mí$BUn saco de cebada, uno de centeno y otro de maíz.', 0),
(@ID, 'esMX', '¿Otra? ¡Claro!$B$BÁmbar es el color del amor de mi vida$BComo las luces de un final del día$BRecupéralo y el amor volverá a mí$BUn saco de cebada, uno de centeno y otro de maíz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 50 Dulce ámbar
-- https://es.classic.wowhead.com/quest=50
SET @ID := 50;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un bis? ¡Claro que sí!$B$BMezclaré y mezclaré y un puré será todo$BSerá, amigo, nuestro más querido tesoro$BHaré un alambique fuerte y resistente$BDame veraplata y no daré la lata.', 0),
(@ID, 'esMX', '¿Un bis? ¡Claro que sí!$B$BMezclaré y mezclaré y un puré será todo$BSerá, amigo, nuestro más querido tesoro$BHaré un alambique fuerte y resistente$BDame veraplata y no daré la lata.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 51 Dulce ámbar
-- https://es.classic.wowhead.com/quest=51
SET @ID := 51;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Repetimos? ¡Claro, lo que quieras!$B$BRecién destilada, aunque aún no esté filtrada$BComo tierra sin semilla esperando a ser arada$BAhora haré nuestra pila de carbón$BUna rama de sicomoro es tu próxima misión.', 0),
(@ID, 'esMX', '¿Repetimos? ¡Claro, lo que quieras!$B$BRecién destilada, aunque aún no esté filtrada$BComo tierra sin semilla esperando a ser arada$BAhora haré nuestra pila de carbón$BUna rama de sicomoro es tu próxima misión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 53 Dulce ámbar
-- https://es.classic.wowhead.com/quest=53
SET @ID := 53;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Claro que te la canto otra vez, amigo!$B$BEs un líquido meloso que se vuelve delicioso$BDulce líquido ambarino que merece mi cariño$BPero algo necesito para darle mis cuidados$BUn magnífico tonel del mejor roble quemado.', 0),
(@ID, 'esMX', '¡Claro que te la canto otra vez, amigo!$B$BEs un líquido meloso que se vuelve delicioso$BDulce líquido ambarino que merece mi cariño$BPero algo necesito para darle mis cuidados$BUn magnífico tonel del mejor roble quemado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Envejecida en el barril y filtrada con carbón$BAcaricia tus labios y va directa al corazón.$BBrindemos por ti y verás que bueno$BAlzad vuestras jarras por Tragoamargo Cebatruenos', 0),
(@ID, 'esMX', 'Envejecida en el barril y filtrada con carbón$BAcaricia tus labios y va directa al corazón.$BBrindemos por ti y verás que bueno$BAlzad vuestras jarras por Tragoamargo Cebatruenos', 0);
-- 63 La llamada del agua
-- https://es.classic.wowhead.com/quest=63
SET @ID := 63;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El blandón aún refleja la luz ambiente del lugar y la llama tiembla levemente cuando te acercas.$B$BLa corrupción de las colinas parece haber mantenido las distancias y, además de los componentes perdidos, el blandón parece estar listo para el ritual de conjura de una forma de agua limpia.', 0),
(@ID, 'esMX', 'El blandón aún refleja la luz ambiente del lugar y la llama tiembla levemente cuando te acercas.$B$BLa corrupción de las colinas parece haber mantenido las distancias y, además de los componentes perdidos, el blandón parece estar listo para el ritual de conjura de una forma de agua limpia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas los brazales sobre el blandón y entonces las gotas restantes de la poción de Brine en la llama. Las gotas harán chisporrotear la llama y empiezas el conjuro con las sencillas palabras que Islen te enseñó....', 0),
(@ID, 'esMX', 'Colocas los brazales sobre el blandón y entonces las gotas restantes de la poción de Brine en la llama. Las gotas harán chisporrotear la llama y empiezas el conjuro con las sencillas palabras que Islen te enseñó....', 0);
-- 77 Una situación peliaguda
-- https://es.classic.wowhead.com/quest=77
SET @ID := 77;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vienes a entregar el calimocho, ¿verdad?', 0),
(@ID, 'esMX', 'Vienes a entregar el calimocho, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Veo que has tratado el calimocho con cuidado; no hay nada peor que el calimocho agitado.$B$BBueno, pasemos al mágico proceso del embotellado para conservar este tesoro alcohólico. En realidad el proceso no tiene nada de mágico; lo único que tengo son unos contenedores de calimocho dulce de las Tierras del Interior vacíos. Nuestras triquiñuelas convertirán estas botellas en un tesoro alcohólico con solera.$B$B¡Salud!', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Veo que has tratado el calimocho con cuidado; no hay nada peor que el calimocho agitado.$B$BBueno, pasemos al mágico proceso del embotellado para conservar este tesoro alcohólico. En realidad el proceso no tiene nada de mágico; lo único que tengo son unos contenedores de calimocho dulce de las Tierras del Interior vacíos. Nuestras triquiñuelas convertirán estas botellas en un tesoro alcohólico con solera.$B$B¡Salud!', 0);
-- 81 Entrega el calimocho
-- https://es.classic.wowhead.com/quest=81
SET @ID := 81;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si no has venido a comprar o a entregar nada, me estás haciendo perder el tiempo. ¡Y eso no me gusta nada! ¡Más te vale traer el calimocho!', 0),
(@ID, 'esMX', 'Si no has venido a comprar o a entregar nada, me estás haciendo perder el tiempo. ¡Y eso no me gusta nada! ¡Más te vale traer el calimocho!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veamos el barril!$B$BSí, está todo. Ten tu pago y buen trabajo. ¡En la taberna me habría cansado mucho más, ja, ja!$B$BGuardaré estas botellas para una ocasión especial. Me gusta tomarlo con champán; lo llamo champimocho.', 0),
(@ID, 'esMX', '¡Veamos el barril!$B$BSí, está todo. Ten tu pago y buen trabajo. ¡En la taberna me habría cansado mucho más, ja, ja!$B$BGuardaré estas botellas para una ocasión especial. Me gusta tomarlo con champán; lo llamo champimocho.', 0);
-- 94 Un ojo vigilante
-- https://es.classic.wowhead.com/quest=94
SET @ID := 94;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta Estatua Leonida ha estado aquí décadas, vigilando la infame Torre de Ilgalar.$B$BHay una hendidura en la base de la estatua en la que parece que podría acoplarse una gema o un glifo...', 0),
(@ID, 'esMX', 'Esta Estatua Leonida ha estado aquí décadas, vigilando la infame Torre de Ilgalar.$B$BHay una hendidura en la base de la estatua en la que parece que podría acoplarse una gema o un glifo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el Glifo de Azora en la piedra. Se adhiere a ella y luego oyes la voz incorpórea de Theocritus:$B$BTienes toda mi gratitud, joven $n. Puedes hablar conmigo a través de este Glifo. Es posible que en un futuro tenga trabajos para ti... cuando haya sondeado los pensamientos de mi rival.', 0),
(@ID, 'esMX', 'Colocas el Glifo de Azora en la piedra. Se adhiere a ella y luego oyes la voz incorpórea de Theocritus:$B$BTienes toda mi gratitud, joven $n. Puedes hablar conmigo a través de este Glifo. Es posible que en un futuro tenga trabajos para ti... cuando haya sondeado los pensamientos de mi rival.', 0);
-- 96 La llamada del agua
-- https://es.classic.wowhead.com/quest=96
SET @ID := 96;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto. ¡Fantástico!$B$B¿Qué tal fue tu viaje a Filargenta? ¿Te llevó mucho tiempo?$B$BMe cuesta discernir si te fue bien porque la corrupción alcanza gran parte de la tierra. Su hedor supera cualquier bien que puedas haber hecho. Pero en ocasiones los pequeños éxitos son tan importantes como los grandes. La purificación del agua fue decisiva para ti y para todos los chamanes.', 0),
(@ID, 'esMX', 'Has vuelto. ¡Fantástico!$B$B¿Qué tal fue tu viaje a Filargenta? ¿Te llevó mucho tiempo?$B$BMe cuesta discernir si te fue bien porque la corrupción alcanza gran parte de la tierra. Su hedor supera cualquier bien que puedas haber hecho. Pero en ocasiones los pequeños éxitos son tan importantes como los grandes. La purificación del agua fue decisiva para ti y para todos los chamanes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta es la prueba que pedí. Lo has hecho muy bien, $n.$B$BMe complace ser el primero en felicitarte y te hago entrega de este… de tu tótem de agua.$B$BÚsalo bien y suerte.$B$BPasará cierto tiempo hasta tu próxima prueba, así que aprende bien las lecciones. El agua pura no solo devuelve la vida a los heridos, sino que puede tener muchos más efectos. Te sugiero que busques un instructor chamán cuando tengas tiempo. Podrías aprender más hechizos..', 0),
(@ID, 'esMX', 'Esta es la prueba que pedí. Lo has hecho muy bien, $n.$B$BMe complace ser el primero en felicitarte y te hago entrega de este… de tu tótem de agua.$B$BÚsalo bien y suerte.$B$BPasará cierto tiempo hasta tu próxima prueba, así que aprende bien las lecciones. El agua pura no solo devuelve la vida a los heridos, sino que puede tener muchos más efectos. Te sugiero que busques un instructor chamán cuando tengas tiempo. Podrías aprender más hechizos..', 0);
-- 99 La locura de Arugal
-- https://es.classic.wowhead.com/quest=99
SET @ID := 99;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has asegurado ya los grilletes piroleños, $n?', 0),
(@ID, 'esMX', '¿Has asegurado ya los grilletes piroleños, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu persistencia es encomiable. Con el conocimiento que me has ayudado a reunir, Arugal caerá y su magia temeraria se anulará. Brindo por ti, $n.', 0),
(@ID, 'esMX', 'Tu persistencia es encomiable. Con el conocimiento que me has ayudado a reunir, Arugal caerá y su magia temeraria se anulará. Brindo por ti, $n.', 0);
-- 100 La llamada del agua
-- https://es.classic.wowhead.com/quest=100
SET @ID := 100;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a ti. Gracias a los chamanes.$B$BLa corrupción retrocede pero la vida sigue disminuyendo. La protección de la vida depende de los chamanes', 0),
(@ID, 'esMX', 'Gracias a ti. Gracias a los chamanes.$B$BLa corrupción retrocede pero la vida sigue disminuyendo. La protección de la vida depende de los chamanes', 0);
-- Ah, Andorhal
-- 105, 211
-- https://es.classic.wowhead.com/quest=105
DELETE FROM `quest_request_items_locale` WHERE `id` IN(105, 211) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(105, 'esES', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0),
(211, 'esES', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0),
(105, 'esMX', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0),
(211, 'esMX', '$n, ya te ha sido asignada tu tarea. ¿Tienes un trozo de la filacteria del exánime como prueba de que has terminado tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(105, 211) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(105, 'esES', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0),
(211, 'esES', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0),
(105, 'esMX', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0),
(211, 'esMX', '¡Lo has conseguido! ¡Araj... el exánime ha sido derrotado!$B$BEn el día de hoy has prestado un enorme favor a la Horda, $n. Tu valentía y perseverancia son testimonio de lo que significa ser un auténtico héroe. Por favor, acepta esto como muestra para que todos vean y sepan que has dado una victoria a la Horda que nunca podrá ser olvidada.', 0);
-- 111 Habla con la abuelita
-- https://es.classic.wowhead.com/quest=111
SET @ID := 111;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo esperar a ver cómo reaccionan mis amigos!$B$BEllos nunca lo esperarán', 0),
(@ID, 'esMX', '¡No puedo esperar a ver cómo reaccionan mis amigos!$B$BEllos nunca lo esperarán', 0);
-- 136 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=136
SET @ID := 136;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El baúl se abre lentamente. Solo parece estar lleno de agua y arena. ¡Pero espera! ¡Está saliendo un pequeño cangrejo con una pista del tesoro entre las pinzas!', 0),
(@ID, 'esMX', 'El baúl se abre lentamente. Solo parece estar lleno de agua y arena. ¡Pero espera! ¡Está saliendo un pequeño cangrejo con una pista del tesoro entre las pinzas!', 0);
-- 138 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=138
SET @ID := 138;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo cazatesoros!', 0),
(@ID, 'esMX', '¡Buen trabajo cazatesoros!', 0);
-- 139 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=139
SET @ID := 139;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te estás acercando al premio gordo, buscatesoros!', 0),
(@ID, 'esMX', '¡Te estás acercando al premio gordo, buscatesoros!', 0);
-- 140 El tesoro escondido del capitán Sanders
-- https://es.classic.wowhead.com/quest=140
SET @ID := 140;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las bisagras del viejo cofre están oxidadas, pero todavía funcionan. Fuerzas el cofre, lo abres y coges el botín.$B$B¡Felicidades!', 0),
(@ID, 'esMX', 'Las bisagras del viejo cofre están oxidadas, pero todavía funcionan. Fuerzas el cofre, lo abres y coges el botín.$B$B¡Felicidades!', 0);
-- 172 Semana de los Niños
-- https://es.classic.wowhead.com/quest=172
SET @ID := 172;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! Me llamo Grunth, ¿me vas a cuidar tú? Me alegro de conocerte. Mis papás también eran aventureros, me han dicho que murieron honrosamente en combate.$B$BEspero que juguemos mucho; la matrona me ha dicho que esta semana serás como mi hermano mayor, qué bien.', 0),
(@ID, 'esMX', '¡Hola! Me llamo Grunth, ¿me vas a cuidar tú? Me alegro de conocerte. Mis papás también eran aventureros, me han dicho que murieron honrosamente en combate.$B$BEspero que juguemos mucho; la matrona me ha dicho que esta semana serás como mi hermano mayor, qué bien.', 0);
-- 178 Theocritus recupera el colgante
-- https://es.classic.wowhead.com/quest=178
SET @ID := 178;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que te hablé mediante un colgante? Mmm, dámelo, quiero estudiarlo.', 0),
(@ID, 'esMX', '¿Que te hablé mediante un colgante? Mmm, dámelo, quiero estudiarlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Hace semanas que envié el mensaje, creí que no se había transmitido. Pero parece que el hechizo llegó a algunos colgantes, aunque tarde.$B$BEspero aprender a enviar ataques para inmovilizar a los gnolls que los lleven puestos.$B$BPero me queda mucha investigación por delante para llegar a eso.', 0),
(@ID, 'esMX', 'Gracias, $n. Hace semanas que envié el mensaje, creí que no se había transmitido. Pero parece que el hechizo llegó a algunos colgantes, aunque tarde.$B$BEspero aprender a enviar ataques para inmovilizar a los gnolls que los lleven puestos.$B$BPero me queda mucha investigación por delante para llegar a eso.', 0);
-- 200 Corredor Herod
-- https://es.classic.wowhead.com/quest=200
SET @ID := 200;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son las notas y los registros del Corredor Herod.$B$BEntre los papeles hay: una lista de suministros del campamento, pedidos de material del coronel Kurzen, y varias cartas.', 0),
(@ID, 'esMX', 'Estas son las notas y los registros del Corredor Herod.$B$BEntre los papeles hay: una lista de suministros del campamento, pedidos de material del coronel Kurzen, y varias cartas.', 0);
-- 215 Los secretos de la jungla
-- https://es.classic.wowhead.com/quest=215
SET @ID := 215;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, lo que te contó Thorsen es cierto. Debes tener discreción con este asunto. Hubo un tiempo, cuando los rebeldes éramos absolutamente leales al coronel Kurzen. Pero debido al grado de corrupción de Kurzen, nuestra pasión se convirtió en ira. Si se supiera que el corsario Thorsen ha tenido algo que ver con los hombres de Kurzen, cualquier noche se encontraría con el pescuezo cortado.$B$BPor lo que yo sé, solo la sargento Yohwa, Thorsen y yo conocíamos la existencia de la misión de Thorsen. Pero debe de haber alguien más. Un traidor.', 0),
(@ID, 'esMX', 'Sí, lo que te contó Thorsen es cierto. Debes tener discreción con este asunto. Hubo un tiempo, cuando los rebeldes éramos absolutamente leales al coronel Kurzen. Pero debido al grado de corrupción de Kurzen, nuestra pasión se convirtió en ira. Si se supiera que el corsario Thorsen ha tenido algo que ver con los hombres de Kurzen, cualquier noche se encontraría con el pescuezo cortado.$B$BPor lo que yo sé, solo la sargento Yohwa, Thorsen y yo conocíamos la existencia de la misión de Thorsen. Pero debe de haber alguien más. Un traidor.', 0);
-- 216 Entre una roca y un Piel de Cardo
-- https://es.classic.wowhead.com/quest=216
SET @ID := 216;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has peleado con los Piel de Cardo? Con un camino despejado entre nuestras bases, nuestras posibilidades de reclamar todo Vallefresno aumentan drásticamente.', 0),
(@ID, 'esMX', '¿Has peleado con los Piel de Cardo? Con un camino despejado entre nuestras bases, nuestras posibilidades de reclamar todo Vallefresno aumentan drásticamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $c, ¡pero que muy bien! Seguiré mandando tropas para diezmar a los furbolgs, pero al menos cuento con una ruta diferente que estará libre de enredos con la Alianza. ¡La conquista de Vallefresno por la Horda está bien encarrilada!$B$BTe has ganado el jornal, $ghéroe:heroína;. ¡Te saludo!', 0),
(@ID, 'esMX', 'Muy bien, $c, ¡pero que muy bien! Seguiré mandando tropas para diezmar a los furbolgs, pero al menos cuento con una ruta diferente que estará libre de enredos con la Alianza. ¡La conquista de Vallefresno por la Horda está bien encarrilada!$B$BTe has ganado el jornal, $ghéroe:heroína;. ¡Te saludo!', 0);
