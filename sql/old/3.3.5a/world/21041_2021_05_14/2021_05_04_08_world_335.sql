-- 9454 La gran cacería lunar
-- https://es.wowhead.com/quest=9454
SET @ID := 9454;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las pieles de venado son delicadas, lo que suele dar una carne tierna y suculenta.', 0),
(@ID, 'esMX', 'Las pieles de venado son delicadas, lo que suele dar una carne tierna y suculenta.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n, bien hecho!$B$BToma, cociné unos lomos mientras no estabas. ¿Quieres la receta también?', 0),
(@ID, 'esMX', '¡Bien hecho, $n, bien hecho!$B$BToma, cociné unos lomos mientras no estabas. ¿Quieres la receta también?', 0);
-- 9455 Extraños hallazgos
-- https://es.wowhead.com/quest=9455
SET @ID := 9455;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que has encontrado qué? ¿Dónde?', 0),
(@ID, 'esMX', '¿Que has encontrado qué? ¿Dónde?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo ha podido llegar algo así al estómago de un acechador nocturno? ¿Es posible que los restos del accidente hayan contaminado a más bestias?', 0),
(@ID, 'esMX', '¿Cómo ha podido llegar algo así al estómago de un acechador nocturno? ¿Es posible que los restos del accidente hayan contaminado a más bestias?', 0);
-- 9456 Eliminando acechadores en la isla 2
-- https://es.wowhead.com/quest=9456
SET @ID := 9456;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos arriesgarnos a que esta contaminación se extienda. Los informes de la Avanzada de Sangre son bastante malos. ¡Esto tiene que detenerse ahora!', 0),
(@ID, 'esMX', 'No podemos arriesgarnos a que esta contaminación se extienda. Los informes de la Avanzada de Sangre son bastante malos. ¡Esto tiene que detenerse ahora!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no sea demasiado tarde.', 0),
(@ID, 'esMX', 'Espero que no sea demasiado tarde.', 0);
-- 9457 Un patrón inusual
-- https://es.wowhead.com/quest=9457
SET @ID := 9457;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hay noticias de Naias, $n?', 0),
(@ID, 'esMX', '¿Hay noticias de Naias, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo sentir el poder puro contenido en esta gema, $n. La enviaré a Lunargenta para que nuestros magistrados sigan estudiando, pero estoy seguro de que resultará útil en nuestra lucha contra los Amani.$B$BTu ayuda ha sido invaluable para conseguir esta gema, y me encargaré de que Los Errantes conozcan el nombre $gdel:da la; $r que hizo posible este hallazgo.', 0),
(@ID, 'esMX', 'Puedo sentir el poder puro contenido en esta gema, $n. La enviaré a Lunargenta para que nuestros magistrados sigan estudiando, pero estoy seguro de que resultará útil en nuestra lucha contra los Amani.$B$BTu ayuda ha sido invaluable para conseguir esta gema, y me encargaré de que Los Errantes conozcan el nombre $gdel:da la; $r que hizo posible este hallazgo.', 0);
-- 9460 Aunando fuerzas
-- https://es.wowhead.com/quest=9460
SET @ID := 9460;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste algo?', 0),
(@ID, 'esMX', '¿Conseguiste algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Un objeto tan personal lleva un fuerte olor de los intrusos, suficiente para guiar a Susurros hasta sus filas...', 0),
(@ID, 'esMX', '¡Excelente! Un objeto tan personal lleva un fuerte olor de los intrusos, suficiente para guiar a Susurros hasta sus filas...', 0);
-- 9461 La llamada del fuego
-- https://es.wowhead.com/quest=9461
SET @ID := 9461;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n, te estaba esperando. ¿Confío en que te encuentre bien?', 0),
(@ID, 'esMX', 'Hola, $n, te estaba esperando. ¿Confío en que te encuentre bien?', 0);
-- 9462 La llamada del fuego
-- https://es.wowhead.com/quest=9462
SET @ID := 9462;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Justo a tiempo, $n. Espero que estés $glisto:lista; para continuar con tu formación. La próxima tarea será difícil.', 0),
(@ID, 'esMX', 'Justo a tiempo, $n. Espero que estés $glisto:lista; para continuar con tu formación. La próxima tarea será difícil.', 0);
-- 9463 Propiedades curativas
-- https://es.wowhead.com/quest=9463
SET @ID := 9463;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Temo que su salud esté empeorando rápidamente.', 0),
(@ID, 'esMX', 'Temo que su salud esté empeorando rápidamente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esperemos que el ungüento fortalezca su espíritu!', 0),
(@ID, 'esMX', '¡Esperemos que el ungüento fortalezca su espíritu!', 0);
-- 9464 La llamada del fuego
-- https://es.wowhead.com/quest=9464
SET @ID := 9464;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Confío en que el ardor que veo detrás de tus ojos sea por un deseo de crecer y comprender. ¡Bien!$B$BTuluun te ha enviado aquí porque ve tu potencial para aprender y ayudar con un problema que ha causado la caída de tu Exodar.$B$BVeremos.', 0),
(@ID, 'esMX', 'Confío en que el ardor que veo detrás de tus ojos sea por un deseo de crecer y comprender. ¡Bien!$B$BTuluun te ha enviado aquí porque ve tu potencial para aprender y ayudar con un problema que ha causado la caída de tu Exodar.$B$BVeremos.', 0);
-- 9465 La llamada del fuego
-- https://es.wowhead.com/quest=9465
SET @ID := 9465;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la antorcha?', 0),
(@ID, 'esMX', '¿Tienes la antorcha?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ves cómo su fuego nunca se apaga? Ese es el trabajo de Prepotencia. Es un símbolo de su arrogancia. La llama está destinada a consumir lo que quema y luego morir ella misma, para renacer de nuevo en otro momento.$B$BTe ayudaría a apagar la antorcha, pero debe permanecer encendida para que puedas lidiar con Prepotencia. Dejaremos que se queme un poco más.', 0),
(@ID, 'esMX', '¿Ves cómo su fuego nunca se apaga? Ese es el trabajo de Prepotencia. Es un símbolo de su arrogancia. La llama está destinada a consumir lo que quema y luego morir ella misma, para renacer de nuevo en otro momento.$B$BTe ayudaría a apagar la antorcha, pero debe permanecer encendida para que puedas lidiar con Prepotencia. Dejaremos que se queme un poco más.', 0);
-- 9466 Se busca: Garfanegra la Indómita
-- https://es.wowhead.com/quest=9466
SET @ID := 9466;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes noticias sobre Garfanegra?', 0),
(@ID, 'esMX', '¿Tienes noticias sobre Garfanegra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres valiente $c, $n. Esa bestia indómita se había cobrado la vida de muchos de mis mejores cazadores.$B$BAcepta esta recompensa, te la has ganado.', 0),
(@ID, 'esMX', 'Eres valiente $c, $n. Esa bestia indómita se había cobrado la vida de muchos de mis mejores cazadores.$B$BAcepta esta recompensa, te la has ganado.', 0);
-- 9467 La llamada del fuego
-- https://es.wowhead.com/quest=9467
SET @ID := 9467;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me vuelvas a hablar hasta que tengas las cenizas de Prepotencia.', 0),
(@ID, 'esMX', 'No me vuelvas a hablar hasta que tengas las cenizas de Prepotencia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una lección valiosa la que aprendes aquí hoy. Es la historia de finales y nuevos comienzos.$B$BCuando hablamos por primera vez te dije que el fuego no era solo destrucción, sino también una fuerza renovadora de los elementos. Con tus acciones has destruido y salvado a Prepotencia, porque renacerá de sus cenizas.', 0),
(@ID, 'esMX', 'Es una lección valiosa la que aprendes aquí hoy. Es la historia de finales y nuevos comienzos.$B$BCuando hablamos por primera vez te dije que el fuego no era solo destrucción, sino también una fuerza renovadora de los elementos. Con tus acciones has destruido y salvado a Prepotencia, porque renacerá de sus cenizas.', 0);
-- 9468 La llamada del fuego
-- https://es.wowhead.com/quest=9468
SET @ID := 9468;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te ves un poco chamuscado en los bordes. ¿Qué tal tu comunión con la llama, $n?', 0),
(@ID, 'esMX', 'Te ves un poco chamuscado en los bordes. ¿Qué tal tu comunión con la llama, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has pasado por el fuego purificador de la destrucción y has sido $grenovado:renovada;, $n. Esto no es diferente a la tribulación que la gente $r está atravesando actualmente. Y al salvar a Prepotencia de sí mismo, has asegurado tu conexión con el fuego elemental de este mundo.', 0),
(@ID, 'esMX', 'Has pasado por el fuego purificador de la destrucción y has sido $grenovado:renovada;, $n. Esto no es diferente a la tribulación que la gente $r está atravesando actualmente. Y al salvar a Prepotencia de sí mismo, has asegurado tu conexión con el fuego elemental de este mundo.', 0);
-- 9469 El apoyo de Barbapluma
-- https://es.wowhead.com/quest=9469
SET @ID := 9469;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El diario de Barbapluma parece tener una gran cantidad de entradas recientes. Volviendo al comienzo de las últimas, comienzas a buscar pistas sobre dónde podría haber ido.', 0),
(@ID, 'esMX', 'El diario de Barbapluma parece tener una gran cantidad de entradas recientes. Volviendo al comienzo de las últimas, comienzas a buscar pistas sobre dónde podría haber ido.', 0);
-- 9470 Un gesto de buena fe
-- https://es.wowhead.com/quest=9470
SET @ID := 9470;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto con noticias de la muerte del médico brujo Mai\'jin?', 0),
(@ID, 'esMX', '¿Has vuelto con noticias de la muerte del médico brujo Mai\'jin?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Los Martillo Salvaje se alegrarán al saber que no se enfrentan solos a los trols Secacorteza. Mostrarles que la Alianza puede resultar un socio fiable en la protección de los grifos debería dar más peso a nuestra propuesta.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Los Martillo Salvaje se alegrarán al saber que no se enfrentan solos a los trols Secacorteza. Mostrarles que la Alianza puede resultar un socio fiable en la protección de los grifos debería dar más peso a nuestra propuesta.', 0);
-- 9471 A la caza de los depredadores
-- https://es.wowhead.com/quest=9471
SET @ID := 9471;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has sacrificado la población de melenargentas?', 0),
(@ID, 'esMX', '¿Has sacrificado la población de melenargentas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El embajador Rualeth asiente con la cabeza mientras das tu informe.>$B$BLo has hecho bien. El sacrificio de los melenargentas no pasará desapercibido para El Martillo Salvaje. Cuando me reúna con sus líderes, estoy seguro de que tus acciones se reflejarán bien en la Alianza. Acepta esta moneda como pequeña muestra de mi agradecimiento, $n.', 0),
(@ID, 'esMX', '<El embajador Rualeth asiente con la cabeza mientras das tu informe.>$B$BLo has hecho bien. El sacrificio de los melenargentas no pasará desapercibido para El Martillo Salvaje. Cuando me reúna con sus líderes, estoy seguro de que tus acciones se reflejarán bien en la Alianza. Acepta esta moneda como pequeña muestra de mi agradecimiento, $n.', 0);
-- 9472 La amante de Arelion
-- https://es.wowhead.com/quest=9472
SET @ID := 9472;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Pergamino de Reprensión de Carinda utilizado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, $n. ¿Está hecho?', 0),
(@ID, 'esMX', 'Bueno, $n. ¿Está hecho?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Esa pelandusca no volverá a irse con el marido de nadie.$B$BTen, una recompensa por el trabajito. Espero que este incidente quede entre nosotras, $n.', 0),
(@ID, 'esMX', '¡Excelente! Esa pelandusca no volverá a irse con el marido de nadie.$B$BTen, una recompensa por el trabajito. Espero que este incidente quede entre nosotras, $n.', 0);
-- 9473 La alternativa a la alternativa
-- https://es.wowhead.com/quest=9473
SET @ID := 9473;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No pierdas el tiempo, $gchico:chica;.', 0),
(@ID, 'esMX', 'No pierdas el tiempo, $gchico:chica;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Observa a la planta mientras despliega su magia.', 0),
(@ID, 'esMX', 'Observa a la planta mientras despliega su magia.', 0);
-- 9474 La marca del Iluminado
-- https://es.wowhead.com/quest=9474
SET @ID := 9474;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Marca del Iluminado es un poderoso símbolo de la fe de Uther en la Luz.', 0),
(@ID, 'esMX', 'La Marca del Iluminado es un poderoso símbolo de la fe de Uther en la Luz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $c! La recuperación de este símbolo sagrado significa mucho para mí y para otros que honran la memoria de Uther el Iluminado.', 0),
(@ID, 'esMX', '¡Gracias, $c! La recuperación de este símbolo sagrado significa mucho para mí y para otros que honran la memoria de Uther el Iluminado.', 0);
-- 9475 Reclamar los huevos
-- https://es.wowhead.com/quest=9475
SET @ID := 9475;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La expresión de tu rostro te señala como $gportador:portadora; de malas noticias. ¿Qué has descubierto?', 0),
(@ID, 'esMX', 'La expresión de tu rostro te señala como $gportador:portadora; de malas noticias. ¿Qué has descubierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Al entregarle los huevos al embajador, describes los hallazgos en el Cobertizo de Barbapluma y Shadra\'Alor.>$B$B¿El Secacorteza mató a Barbapluma?$B$B<El rostro de Rualeth se contrae horrorizado ante tu descripción de la muerte del enano y las implicaciones para la misión de Rualeth.>$B$BEntiendo por qué has sentido que tenías que ir en busca de los huevos, pero desearía que hubieras pensado en traer a otros. Sin duda, su muerte enfurecerá a Falstad Martillo Salvaje, desencadenando represalias contra los trols y retrasando indefinidamente mi audiencia.', 0),
(@ID, 'esMX', '<Al entregarle los huevos al embajador, describes los hallazgos en el Cobertizo de Barbapluma y Shadra\'Alor.>$B$B¿El Secacorteza mató a Barbapluma?$B$B<El rostro de Rualeth se contrae horrorizado ante tu descripción de la muerte del enano y las implicaciones para la misión de Rualeth.>$B$BEntiendo por qué has sentido que tenías que ir en busca de los huevos, pero desearía que hubieras pensado en traer a otros. Sin duda, su muerte enfurecerá a Falstad Martillo Salvaje, desencadenando represalias contra los trols y retrasando indefinidamente mi audiencia.', 0);
-- 9476 En busca de Barbapluma
-- https://es.wowhead.com/quest=9476
SET @ID := 9476;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sobre el altar hay un montón de huesos que parecen haber pertenecido a un enano. No quedan rasgos identificativos, pero decides buscar en el cuerpo para confirmar que se trata de los restos de Barbapluma.', 0),
(@ID, 'esMX', 'Sobre el altar hay un montón de huesos que parecen haber pertenecido a un enano. No quedan rasgos identificativos, pero decides buscar en el cuerpo para confirmar que se trata de los restos de Barbapluma.', 0);
-- 9483 Los placeres de la vida
-- https://es.wowhead.com/quest=9483
SET @ID := 9483;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No por estar de peregrinación tenemos que renunciar a todo. Hace siglos que no me tomo un buen vino.$B$B¡Mataría por una botella de licor Cenarion!$B$BSí, ya sé que no queda bien que me guste una especialidad de los elfos de la noche.', 0),
(@ID, 'esMX', 'No por estar de peregrinación tenemos que renunciar a todo. Hace siglos que no me tomo un buen vino.$B$B¡Mataría por una botella de licor Cenarion!$B$BSí, ya sé que no queda bien que me guste una especialidad de los elfos de la noche.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No por estar de peregrinación tenemos que renunciar a todo. Hace siglos que no me tomo un buen vino.$B$B¡Mataría por una botella de licor Cenarion!$B$BSí, ya sé que no queda bien que me guste una especialidad de los elfos de la noche.', 0),
(@ID, 'esMX', 'No por estar de peregrinación tenemos que renunciar a todo. Hace siglos que no me tomo un buen vino.$B$B¡Mataría por una botella de licor Cenarion!$B$BSí, ya sé que no queda bien que me guste una especialidad de los elfos de la noche.', 0);
-- 9487 Atracadores Arcanos
-- https://es.wowhead.com/quest=9487
SET @ID := 9487;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No te acercaste demasiado a los brutos, espero?', 0),
(@ID, 'esMX', '¿No te acercaste demasiado a los brutos, espero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué desperdicio, usar magia para construir seres de fuerza física. Siempre pensé que por eso nos aliamos con las razas menores, después de todo.$B$BHiciste bien en destruirlos para que podamos usar lo que queda para un propósito más adecuado.', 0),
(@ID, 'esMX', 'Qué desperdicio, usar magia para construir seres de fuerza física. Siempre pensé que por eso nos aliamos con las razas menores, después de todo.$B$BHiciste bien en destruirlos para que podamos usar lo que queda para un propósito más adecuado.', 0);
-- 9488 Una toga sencilla
-- https://es.wowhead.com/quest=9488
SET @ID := 9488;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La toga no se puede completar sin los suministros necesarios. Pero lo sabías, ¿no?', 0),
(@ID, 'esMX', 'La toga no se puede completar sin los suministros necesarios. Pero lo sabías, ¿no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente no necesitas conocer las complejidades de crear una toga mágica, $n, solo necesitas saber qué traerme.$B$BY déjame ser honesto, trajiste suficiente para varias togas. Las ganancias que obtendré deberían cubrir con creces los costos de hacer tu toga, e incluso lo suficiente para comprarme algo bonito. ¡Parece que el agradecimiento te pertenece!', 0),
(@ID, 'esMX', 'Realmente no necesitas conocer las complejidades de crear una toga mágica, $n, solo necesitas saber qué traerme.$B$BY déjame ser honesto, trajiste suficiente para varias togas. Las ganancias que obtendré deberían cubrir con creces los costos de hacer tu toga, e incluso lo suficiente para comprarme algo bonito. ¡Parece que el agradecimiento te pertenece!', 0);
-- 9489 Limpiar La Cicatriz
-- https://es.wowhead.com/quest=9489
SET @ID := 9489;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Forestal Canción Eterna bendecido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has dado esperanza donde se desvaneció?', 0),
(@ID, 'esMX', '¿Has dado esperanza donde se desvaneció?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los forestales ya hablan de tus bendiciones con asombro y respeto. Ahora puedes ver cómo la Luz nos sirve, permitiéndonos ayudar a otros, pero solo después de habernos ayudado a nosotros mismos.', 0),
(@ID, 'esMX', 'Los forestales ya hablan de tus bendiciones con asombro y respeto. Ahora puedes ver cómo la Luz nos sirve, permitiéndonos ayudar a otros, pero solo después de habernos ayudado a nosotros mismos.', 0);
-- 9490 La matriarca despellejadora de roca
-- https://es.wowhead.com/quest=9490
SET @ID := 9490;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído la prueba de la muerte de Garfanegra, $n?', 0),
(@ID, 'esMX', '¿Has traído la prueba de la muerte de Garfanegra, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¡recuerdo estas afiladas garras!$B$BAcepta esta recompensa, $n. Lo que acabas de hacer era ciertamente peligroso. Mereces esta recompensa sin duda alguna.', 0),
(@ID, 'esMX', 'Sí, ¡recuerdo estas afiladas garras!$B$BAcepta esta recompensa, $n. Lo que acabas de hacer era ciertamente peligroso. Mereces esta recompensa sin duda alguna.', 0);
-- 9491 Avaricia
-- https://es.wowhead.com/quest=9491
SET @ID := 9491;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por favor dime que encontraste el anillo. No pasará mucho tiempo antes de que el comerciante encuentre su propio $n.', 0),
(@ID, 'esMX', 'Por favor dime que encontraste el anillo. No pasará mucho tiempo antes de que el comerciante encuentre su propio $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es el anillo, ¿verdad? No hay mucho que ver, pero sabes lo que dicen sobre la basura de un elfo...$B$BY no olvidemos tu pago. ¡No tengas vergüenza de gastarlo aquí, cariño!', 0),
(@ID, 'esMX', 'Este es el anillo, ¿verdad? No hay mucho que ver, pero sabes lo que dicen sobre la basura de un elfo...$B$BY no olvidemos tu pago. ¡No tengas vergüenza de gastarlo aquí, cariño!', 0);
-- 9492 Girando las tornas
-- https://es.wowhead.com/quest=9492
SET @ID := 9492;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has regresado con pruebas de la desaparición del \'Jefe de Guerra\' Kargath Garrafilada?', 0),
(@ID, 'esMX', '¿Has regresado con pruebas de la desaparición del \'Jefe de Guerra\' Kargath Garrafilada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Con tu victoria en Ciudadela del Fuego Infernal, hemos asestado un gran golpe a los orcos.$B$BDebo hablar con el Comandante de operaciones Romus sobre el seguimiento y asegurarme de que los orcos se mantengan a la defensiva. Ahora que nos han reforzado, podemos hacer mucho más que defender el Bastión del Honor.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Con tu victoria en Ciudadela del Fuego Infernal, hemos asestado un gran golpe a los orcos.$B$BDebo hablar con el Comandante de operaciones Romus sobre el seguimiento y asegurarme de que los orcos se mantengan a la defensiva. Ahora que nos han reforzado, podemos hacer mucho más que defender el Bastión del Honor.', 0);
-- 9493 El orgullo de la Horda vil
-- https://es.wowhead.com/quest=9493
SET @ID := 9493;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No soy tan ingenuo como para pensar que la derrota de los legionarios Mano Destrozada presagia nuestra victoria sobre la Horda Vil, pero es un buen primer paso.', 0),
(@ID, 'esMX', 'No soy tan ingenuo como para pensar que la derrota de los legionarios Mano Destrozada presagia nuestra victoria sobre la Horda Vil, pero es un buen primer paso.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De hecho, es una excelente noticia, $n. Con el progreso del informe de la Ciudadela del Fuego Infernal, tal vez podamos permitirnos el lujo de centrar nuestra atención en la presencia de la Horda Vil en otras partes de la península y Terrallende en su conjunto.', 0),
(@ID, 'esMX', 'De hecho, es una excelente noticia, $n. Con el progreso del informe de la Ciudadela del Fuego Infernal, tal vez podamos permitirnos el lujo de centrar nuestra atención en la presencia de la Horda Vil en otras partes de la península y Terrallende en su conjunto.', 0);
-- 9494 Ascuas viles
-- https://es.wowhead.com/quest=9494
SET @ID := 9494;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Trajiste las, err, ascuas?', 0),
(@ID, 'esMX', '¿Trajiste las, err, ascuas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho! No puedo esperar replicar las hazañas del Brujo supremo Malbisal, ni debería aspirar a hacerlo, pero seríamos tontos si ignorara el poder de las ascuas viles.$B$BSin embargo, hay quienes prohibirían el tipo de investigación en la que estoy a punto de embarcarme y, por esa razón, debo mantener mis esfuerzos en secreto. Por favor, no hables de esto con nadie, $n.', 0),
(@ID, 'esMX', '¡Bien hecho! No puedo esperar replicar las hazañas del Brujo supremo Malbisal, ni debería aspirar a hacerlo, pero seríamos tontos si ignorara el poder de las ascuas viles.$B$BSin embargo, hay quienes prohibirían el tipo de investigación en la que estoy a punto de embarcarme y, por esa razón, debo mantener mis esfuerzos en secreto. Por favor, no hables de esto con nadie, $n.', 0);
-- 9495 La voluntad del Jefe de Guerra
-- https://es.wowhead.com/quest=9495
SET @ID := 9495;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes pruebas de la derrota de Kargath Garrafilada?', 0),
(@ID, 'esMX', '¿Tienes pruebas de la derrota de Kargath Garrafilada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho bien, $n. En su mejor momento, Kargath Garrafilada fue un buen guerrero, un héroe y un ejemplo para su pueblo.$B$BSu muerte es un golpe para todos nosotros, pero especialmente para el Jefe de Guerra Thrall. Pase lo que pase con él en sus últimos días, no debemos olvidarnos del orco que alguna vez fue Kargath, ni las lecciones que se pueden aprender de su caída.$B$BPor tu servicio a la Horda, $n, serás $grecompensado:recompensada; con tu elección de entre estas armas.', 0),
(@ID, 'esMX', 'Lo has hecho bien, $n. En su mejor momento, Kargath Garrafilada fue un buen guerrero, un héroe y un ejemplo para su pueblo.$B$BSu muerte es un golpe para todos nosotros, pero especialmente para el Jefe de Guerra Thrall. Pase lo que pase con él en sus últimos días, no debemos olvidarnos del orco que alguna vez fue Kargath, ni las lecciones que se pueden aprender de su caída.$B$BPor tu servicio a la Horda, $n, serás $grecompensado:recompensada; con tu elección de entre estas armas.', 0);
-- 9496 El orgullo de la Horda vil
-- https://es.wowhead.com/quest=9496
SET @ID := 9496;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que nos deshagamos de los legionarios Mano Destrozada, podremos empezar a progresar en nuestra campaña contra la Horda Vil. ¿Has cumplido tu misión, $n?', 0),
(@ID, 'esMX', 'Una vez que nos deshagamos de los legionarios Mano Destrozada, podremos empezar a progresar en nuestra campaña contra la Horda Vil. ¿Has cumplido tu misión, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Sin los legionarios, será más fácil enfrentarse a la Horda Vil en el campo de batalla, aunque siguen siendo un enemigo formidable.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Sin los legionarios, será más fácil enfrentarse a la Horda Vil en el campo de batalla, aunque siguen siendo un enemigo formidable.', 0);
-- 9498 La Avanzada del Halcón
-- https://es.wowhead.com/quest=9498
SET @ID := 9498;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a la Avanzada del Halcón, $r. Todos los aliados de la Horda son bienvenidos, pero especialmente aquellos recomendados por Martik.', 0),
(@ID, 'esMX', 'Te doy la bienvenida a la Avanzada del Halcón, $r. Todos los aliados de la Horda son bienvenidos, pero especialmente aquellos recomendados por Martik.', 0);
-- 9499 La Avanzada del Halcón
-- https://es.wowhead.com/quest=9499
SET @ID := 9499;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a la Avanzada del Halcón, $ghermano:hermana;. Muchos elfos de sangre no han conseguido llegar hasta aquí.$B$BEs lamentable; nuestra labor en Terrallende acaba de empezar.', 0),
(@ID, 'esMX', 'Te doy la bienvenida a la Avanzada del Halcón, $ghermano:hermana;. Muchos elfos de sangre no han conseguido llegar hasta aquí.$B$BEs lamentable; nuestra labor en Terrallende acaba de empezar.', 0);
-- La llamada del agua
-- 9500, 9502
-- https://es.wowhead.com/quest=9500
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9500, 9502) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9500, 'esES', 'Nos encontremos de nuevo. He estado observando tu progreso desde lejos, $n, y estoy complacido.$B$BHa llegado el momento de que comulgues con el elemento agua, de que aprendas sus misterios y te entregues al agua para que, a su vez, aprendas a dominarlo.', 0),
(9502, 'esES', 'Nos encontremos de nuevo. He estado observando tu progreso desde lejos, $n, y estoy complacido.$B$BHa llegado el momento de que comulgues con el elemento agua, de que aprendas sus misterios y te entregues al agua para que, a su vez, aprendas a dominarlo.', 0),
(9500, 'esMX', 'Nos encontremos de nuevo. He estado observando tu progreso desde lejos, $n, y estoy complacido.$B$BHa llegado el momento de que comulgues con el elemento agua, de que aprendas sus misterios y te entregues al agua para que, a su vez, aprendas a dominarlo.', 0),
(9502, 'esMX', 'Nos encontremos de nuevo. He estado observando tu progreso desde lejos, $n, y estoy complacido.$B$BHa llegado el momento de que comulgues con el elemento agua, de que aprendas sus misterios y te entregues al agua para que, a su vez, aprendas a dominarlo.', 0);
-- 9501 La llamada del agua
-- https://es.wowhead.com/quest=9501
SET @ID := 9501;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No temas, $n. Mientras estés aquí, hablaremos usando nuestras mentes.$B$BLe agradezco al clarividente Nobundo por enviarte. Hay una gran perturbación que está contaminando las aguas de la Isla Bruma de Sangre y sus alrededores. Ni siquiera los ciegos dejarían de notar el efecto que esto está teniendo sobre sus criaturas y el medio ambiente.$B$BTú y yo trabajaremos juntos para detener esta corrupción antes de que se extienda más.', 0),
(@ID, 'esMX', 'No temas, $n. Mientras estés aquí, hablaremos usando nuestras mentes.$B$BLe agradezco al clarividente Nobundo por enviarte. Hay una gran perturbación que está contaminando las aguas de la Isla Bruma de Sangre y sus alrededores. Ni siquiera los ciegos dejarían de notar el efecto que esto está teniendo sobre sus criaturas y el medio ambiente.$B$BTú y yo trabajaremos juntos para detener esta corrupción antes de que se extienda más.', 0);
-- 9503 La llamada del agua
-- https://es.wowhead.com/quest=9503
SET @ID := 9503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recogido tan pronto las esencias hediondas de mis desafortunadas hermanas, $n?', 0),
(@ID, 'esMX', '¿Has recogido tan pronto las esencias hediondas de mis desafortunadas hermanas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $c. Esto deberían ser suficiente para que pueda examinar esta corrupción. Entonces tendremos una mejor idea de cómo proceder.', 0),
(@ID, 'esMX', 'Gracias, $c. Esto deberían ser suficiente para que pueda examinar esta corrupción. Entonces tendremos una mejor idea de cómo proceder.', 0);
