-- 8080, 8154, 8155, 8156, 8297 Los recursos de la Cuenca de Arathi
-- https://es.classic.wowhead.com/quest=8080
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8080, 8154, 8155, 8156, 8297) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8080, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8154, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8155, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8156, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8297, 'esES', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8080, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8154, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8155, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8156, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0),
(8297, 'esMX', '¿Tiene la caja de suministros, $n? La Liga de Arathor no puede librar una batalla decente sin ellos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id`IN(8080, 8154, 8155, 8156, 8297) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8080, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8154, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8155, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8156, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8297, 'esES', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8080, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8154, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8155, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8156, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0),
(8297, 'esMX', '¡Tienes los suministros! ¡Gran trabajo! Enviaré los recursos a nuestros intendentes, que pueden distribuirlos rápidamente entre nuestras tropas.$B$BGracias, $n. De hecho, realizar misiones exitosas como la que has logrado es la forma en que realmente se ganan las guerras.', 0);
-- 8105, 8166, 8167, 8168 La batalla por la Cuenca de Arathi
-- https://es.classic.wowhead.com/quest=8168
DELETE FROM `quest_offer_reward_locale` WHERE `id`  IN(8105, 8166, 8167, 8168) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8105, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8166, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8167, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8168, 'esES', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8105, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8166, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8167, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0),
(8168, 'esMX', 'He recibido informes de tus hazañas en La Cuenca de Arathi, $n. ¡Bien hecho! Con otros como tú uniéndose a la lucha, tengo fe en que algún día recuperaremos nuestra tierra natal.', 0);
-- 4508 La calma que precede a la tormenta
-- https://es.classic.wowhead.com/quest=4508
SET @ID := 4508;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Son tontos, $n! Ni siquiera pueden pensar en mirar a su alrededor en busca de una amenaza mayor; su odio irracional hacia la Horda será el fin de todos nosotros. ¡No sé cuántas pruebas más puedo darles de la amenaza de los silítidos a menos que los arroje a una de las colmenas para que puedan ver por sí mismos!$B$BLo siento, ¿traes noticias para mi atención?', 0),
(@ID, 'esMX', '¡Son tontos, $n! Ni siquiera pueden pensar en mirar a su alrededor en busca de una amenaza mayor; su odio irracional hacia la Horda será el fin de todos nosotros. ¡No sé cuántas pruebas más puedo darles de la amenaza de los silítidos a menos que los arroje a una de las colmenas para que puedan ver por sí mismos!$B$BLo siento, ¿traes noticias para mi atención?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si bien realmente aprecio esto, no estoy seguro de qué beneficio nos dará. La Alianza ignora las amenazas de cualquier otra fuente que no sea la Horda, e incluso nuestros propios líderes aquí en Darnassus no pueden ponerse de acuerdo sobre qué es exactamente esta amenaza. Los tontos como Fandral Corcocelada teorizan que los silítidos no se parecen en nada a la amenaza del pasado que yo digo que son. Su ignorancia solo es superada por su arrogancia.', 0),
(@ID, 'esMX', 'Si bien realmente aprecio esto, no estoy seguro de qué beneficio nos dará. La Alianza ignora las amenazas de cualquier otra fuente que no sea la Horda, e incluso nuestros propios líderes aquí en Darnassus no pueden ponerse de acuerdo sobre qué es exactamente esta amenaza. Los tontos como Fandral Corcocelada teorizan que los silítidos no se parecen en nada a la amenaza del pasado que yo digo que son. Su ignorancia solo es superada por su arrogancia.', 0);
-- 8308 La carta perdida de Brann Barbabronce
-- https://es.wowhead.com/quest=8308
SET @ID := 8308;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya.', 0),
(@ID, 'esMX', 'Vaya.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto explica mucho. Si alguna vez entras en Ahn\'Qiraj, busca al pobre Brann. Seguro que echa de menos al monito.', 0),
(@ID, 'esMX', 'Esto explica mucho. Si alguna vez entras en Ahn\'Qiraj, busca al pobre Brann. Seguro que echa de menos al monito.', 0);
-- 3912 Encuentro en la tumba
-- https://es.classic.wowhead.com/quest=3912
SET @ID := 3912;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ha pasado mucho tiempo desde que vinieron a hablar conmigo por última vez...', 0),
(@ID, 'esMX', 'Ha pasado mucho tiempo desde que vinieron a hablar conmigo por última vez...', 0);
-- 6844 Umber, el archivista
-- https://es.classic.wowhead.com/quest=6844
SET @ID := 6844;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, hola! Mmm...$B$BVoy a hablarte con sinceridad, $gamigo:amiga;... apestas un poco. Tienes olor a pies, o algo así. No es que te esté atacando ni nada de eso. Solo digo que... en el futuro, quizás quieras refrescarte un poco después de salir del campo de batalla. De esa forma, las primeras impresiones que causes no serán tan impresionantes.$B$BEn fin... ¿Qué puedo hacer por ti?', 0),
(@ID, 'esMX', '¡Eh, hola! Mmm...$B$BVoy a hablarte con sinceridad, $gamigo:amiga;... apestas un poco. Tienes olor a pies, o algo así. No es que te esté atacando ni nada de eso. Solo digo que... en el futuro, quizás quieras refrescarte un poco después de salir del campo de batalla. De esa forma, las primeras impresiones que causes no serán tan impresionantes.$B$BEn fin... ¿Qué puedo hacer por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por las barbas de los sapos! ¿Qué llevas ahí? Tiene forma de libro... Intentaré romper la estructura que lo cubre.$B$B¿Layo te ha enviado a buscarme desde Silithus? Tan solo he oído susurros silenciosos, bueno, no tan silenciosos si los he oído, claro, sobre los horrores que están ocurriendo allí. Une eso a mi aversión por los bichos y tendrás la razón perfecta para que me quede aquí con los libros.', 0),
(@ID, 'esMX', '¡Por las barbas de los sapos! ¿Qué llevas ahí? Tiene forma de libro... Intentaré romper la estructura que lo cubre.$B$B¿Layo te ha enviado a buscarme desde Silithus? Tan solo he oído susurros silenciosos, bueno, no tan silenciosos si los he oído, claro, sobre los horrores que están ocurriendo allí. Une eso a mi aversión por los bichos y tendrás la razón perfecta para que me quede aquí con los libros.', 0);
-- 6845 Desvelar los secretos del pasado
-- https://es.classic.wowhead.com/quest=6845
SET @ID := 6845;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de verte, $n.$B$BTe estaba esperando para comunicarte la gratitud del Círculo Cenarion por tu ayuda. Acepta esto como muestra de agradecimiento.$B$BMuchas gracias, $c.', 0),
(@ID, 'esMX', 'Me alegro de verte, $n.$B$BTe estaba esperando para comunicarte la gratitud del Círculo Cenarion por tu ayuda. Acepta esto como muestra de agradecimiento.$B$BMuchas gracias, $c.', 0);
-- 5526 Fragmentos de gangrevid
-- https://es.classic.wowhead.com/quest=5526
SET @ID := 5526;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que tenemos el relicario de pureza, podremos eliminar la amenaza corruptora y además estudiarla. Tal vez nos ayude a crear más defensas frente a la corrupción que amenaza permanentemente a Azeroth.$B$BEs lo que habría querido Milli...', 0),
(@ID, 'esMX', 'Ahora que tenemos el relicario de pureza, podremos eliminar la amenaza corruptora y además estudiarla. Tal vez nos ayude a crear más defensas frente a la corrupción que amenaza permanentemente a Azeroth.$B$BEs lo que habría querido Milli...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Círculo Cenarion está en deuda contigo, $c, por ayudarnos a ganar esta batalla contra nuestros enemigos.$B$BPor favor, acepta esto en muestra de agradecimiento y la admiración del Círculo, $n.', 0),
(@ID, 'esMX', 'El Círculo Cenarion está en deuda contigo, $c, por ayudarnos a ganar esta batalla contra nuestros enemigos.$B$BPor favor, acepta esto en muestra de agradecimiento y la admiración del Círculo, $n.', 0);
-- 4510 La calma que precede a la tormenta
-- https://es.classic.wowhead.com/quest=4510
SET @ID := 4510;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Elune\'adore, $c. ¿Qué puedo hacer hoy por ti?', 0),
(@ID, 'esMX', 'Elune\'adore, $c. ¿Qué puedo hacer hoy por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este comprobante bancario me autoriza a retirar un artículo de la cuenta de Gracina Poderespíritu y entregártelo. ¡Felicidades, todo parece estar en orden!', 0),
(@ID, 'esMX', 'Este comprobante bancario me autoriza a retirar un artículo de la cuenta de Gracina Poderespíritu y entregártelo. ¡Felicidades, todo parece estar en orden!', 0);
-- 3913 Una situación mortal
-- https://es.classic.wowhead.com/quest=3913
SET @ID := 3913;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta debe ser la lápida que mencionó Gaeriyan...', 0),
(@ID, 'esMX', 'Esta debe ser la lápida que mencionó Gaeriyan...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Empujas la lápida con fuerza, y se desliza a un lado mostrando un pequeño hueco debajo de ella.$B$BCuando colocas la Espada de Linken en el hueco te das cuenta de que encaja a la perfección...', 0),
(@ID, 'esMX', 'Empujas la lápida con fuerza, y se desliza a un lado mostrando un pequeño hueco debajo de ella.$B$BCuando colocas la Espada de Linken en el hueco te das cuenta de que encaja a la perfección...', 0);
-- 3914 La Espada de Linken
-- https://es.classic.wowhead.com/quest=3914
SET @ID := 3914;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh! ¡Te recuerdo!... Eres... ¡No, no me lo digas!', 0),
(@ID, 'esMX', '¡Oh! ¡Te recuerdo!... Eres... ¡No, no me lo digas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi espada... ¡está terminada!$B$BSi tan solo pudiera recordar para qué la necesitaba...$B$BToma, deja que al menos te pague algo por tu trabajo.', 0),
(@ID, 'esMX', 'Mi espada... ¡está terminada!$B$BSi tan solo pudiera recordar para qué la necesitaba...$B$BToma, deja que al menos te pague algo por tu trabajo.', 0);
-- 3941 La ayuda de una gnoma
-- https://es.classic.wowhead.com/quest=3941
SET @ID := 3941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espera solo un momento... Estoy probando una nueva combinación de cristales...', 0),
(@ID, 'esMX', 'Espera solo un momento... Estoy probando una nueva combinación de cristales...', 0);
-- 3942 Recuerdos de Linken
-- https://es.classic.wowhead.com/quest=3942
SET @ID := 3942;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c. ¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', 'Hola, $c. ¿Puedo ayudarte en algo?', 0);
-- 4284 Cristales de poder
-- https://es.classic.wowhead.com/quest=4284
SET @ID := 4284;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Solo sé que he dado con algo, $n!', 0),
(@ID, 'esMX', '¡Solo sé que he dado con algo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora seguiré con mis experimentos! Gracias, $n.', 0),
(@ID, 'esMX', '¡Ahora seguiré con mis experimentos! Gracias, $n.', 0);
-- 4285 La Torre de cristal del Norte
-- https://es.classic.wowhead.com/quest=4285
SET @ID := 4285;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visitado la torre, $n?', 0),
(@ID, 'esMX', '¿Has visitado la torre, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que las historias que cuentan son ciertas, $n.', 0),
(@ID, 'esMX', 'Sé que las historias que cuentan son ciertas, $n.', 0);
-- 4287 La Torre de cristal del Este
-- https://es.classic.wowhead.com/quest=4287
SET @ID := 4287;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visitado la torre, $n?', 0),
(@ID, 'esMX', '¿Has visitado la torre, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un\'Goro es un lugar muy extraño, $n. Cuando entras en el cráter es como si estuvieras en un mundo totalmente distinto...', 0),
(@ID, 'esMX', 'Un\'Goro es un lugar muy extraño, $n. Cuando entras en el cráter es como si estuvieras en un mundo totalmente distinto...', 0);
-- 4288 La Torre de cristal del Oeste
-- https://es.classic.wowhead.com/quest=4288
SET @ID := 4288;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visitado la torre, $n?', 0),
(@ID, 'esMX', '¿Has visitado la torre, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay muchas zonas secretas a los lados del cráter. Si no se te ocurre ningún otro sitio donde buscar intenta explorar los caminos más intrincados, $n.', 0),
(@ID, 'esMX', 'Hay muchas zonas secretas a los lados del cráter. Si no se te ocurre ningún otro sitio donde buscar intenta explorar los caminos más intrincados, $n.', 0);
-- 974 Busca la fuente
-- https://es.classic.wowhead.com/quest=974
SET @ID := 974;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Iría allí yo mismo, pero... ¡me dan algo de miedo los elementales de fuego!', 0),
(@ID, 'esMX', 'Iría allí yo mismo, pero... ¡me dan algo de miedo los elementales de fuego!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, veo claramente la relación entre la temperatura del volcán y las fuentes termales. Tengo que volver a comprobar mis ecuaciones pero parece que la distancia y la tasa de transferencia del calor... Ummm...', 0),
(@ID, 'esMX', 'Sí, veo claramente la relación entre la temperatura del volcán y las fuentes termales. Tengo que volver a comprobar mis ecuaciones pero parece que la distancia y la tasa de transferencia del calor... Ummm...', 0);
-- 980 Nuevos manantiales
-- https://es.classic.wowhead.com/quest=980
SET @ID := 980;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. Sí, lo que te dijo Krakle es cierto...', 0),
(@ID, 'esMX', 'Hola, $n. Sí, lo que te dijo Krakle es cierto...', 0);
-- 4321 Entender el significado
-- https://es.classic.wowhead.com/quest=4321
SET @ID := 4321;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Es fascinante... ¡sólo espero que mis diagramas sean correctos! Recogí toda la información en este manual, tómalo.$B$BCreo que ya puedo responder a cualquier pregunta que tengas sobre los cristales, $n.', 0),
(@ID, 'esMX', 'Muy bien, $n. Es fascinante... ¡sólo espero que mis diagramas sean correctos! Recogí toda la información en este manual, tómalo.$B$BCreo que ya puedo responder a cualquier pregunta que tengas sobre los cristales, $n.', 0);
