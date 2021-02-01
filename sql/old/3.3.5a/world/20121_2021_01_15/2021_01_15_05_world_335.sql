-- 1879 Habla con Bink
-- https://es.classic.wowhead.com/quest=1879
SET @ID := 1879;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, puedo ver que tienes una promesa, ¡sí que la tienes! Pero se necesita más que una promesa para ser $gun buen:una buena; $c. Y si no eres $gun buen:una buena; $c, entonces eres $gun:una; $c $gmalo:mala;. Y los magos malos son parte del problema, ¡sí que lo son!$B$BVaya, me estoy adelantando. ¡Empecemos por el principio!', 0),
(@ID, 'esMX', 'Oh, puedo ver que tienes una promesa, ¡sí que la tienes! Pero se necesita más que una promesa para ser $gun buen:una buena; $c. Y si no eres $gun buen:una buena; $c, entonces eres $gun:una; $c $gmalo:mala;. Y los magos malos son parte del problema, ¡sí que lo son!$B$BVaya, me estoy adelantando. ¡Empecemos por el principio!', 0);
-- 1880 Trastónitor maguitronic
-- https://es.classic.wowhead.com/quest=1880
SET @ID := 1880;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste el trastónitor? ¡Debo recuperarlo antes de que se quede sin suministro de energía!', 0),
(@ID, 'esMX', '¿Encontraste el trastónitor? ¡Debo recuperarlo antes de que se quede sin suministro de energía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, un día espléndido! Cuando hice mi trastónitor no me di cuenta de lo que iba a depender de él. ¡Ya puedo volver a empezar mis estudios!$B$B¡Gracias, $n! Y toma, estas fueron mis primeras herramientas de $c. Están un poco estropeadas pero funcionan bien. Escoge lo que quieras, seguro que cualquiera de las dos cosas te vendrá bien.', 0),
(@ID, 'esMX', '¡Oh, un día espléndido! Cuando hice mi trastónitor no me di cuenta de lo que iba a depender de él. ¡Ya puedo volver a empezar mis estudios!$B$B¡Gracias, $n! Y toma, estas fueron mis primeras herramientas de $c. Están un poco estropeadas pero funcionan bien. Escoge lo que quieras, seguro que cualquiera de las dos cosas te vendrá bien.', 0);
-- 1881 Habla con Anastasia
-- https://es.classic.wowhead.com/quest=1881
SET @ID := 1881;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Fuiste $gsabio:sabia; al responder a mi llamada, y aún lo serás más si escuchas lo que voy a decirte...', 0),
(@ID, 'esMX', 'Saludos, $n. Fuiste $gsabio:sabia; al responder a mi llamada, y aún lo serás más si escuchas lo que voy a decirte...', 0);
-- 1882 La Hacienda Balnir
-- https://es.classic.wowhead.com/quest=1882
SET @ID := 1882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las Bocas de dragón? Esa clase de flor es muy receptiva a las energías mágicas y estudiar las Bocas de dragón que se crían tan cerca de las Tierras de la Peste podrá indicarnos si la Peste se ha introducido en los Claros de Tirisfal.', 0),
(@ID, 'esMX', '¿Tienes las Bocas de dragón? Esa clase de flor es muy receptiva a las energías mágicas y estudiar las Bocas de dragón que se crían tan cerca de las Tierras de la Peste podrá indicarnos si la Peste se ha introducido en los Claros de Tirisfal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, es un espécimen fantástico. Lo enviaré enseguida para que lo estudien nuestros boticarios y para que puedan determinar la extensión de la corrupción de las Tierras de la Peste.$B$BBien hecho, $n. A cambio de todos tus servicios te doy a elegir entre un orbe o un bastón. Elijas lo que elijas te será muy útil.', 0),
(@ID, 'esMX', 'Ah, es un espécimen fantástico. Lo enviaré enseguida para que lo estudien nuestros boticarios y para que puedan determinar la extensión de la corrupción de las Tierras de la Peste.$B$BBien hecho, $n. A cambio de todos tus servicios te doy a elegir entre un orbe o un bastón. Elijas lo que elijas te será muy útil.', 0);
-- 1883 Habla con Un'thuwa
-- https://es.classic.wowhead.com/quest=1883
SET @ID := 1883;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ave, $n. Loado seas, has respondido a mi petición de auxilio. Esperemos que estés $gpreparado:preparada; para esta tarea...', 0),
(@ID, 'esMX', 'Ave, $n. Loado seas, has respondido a mi petición de auxilio. Esperemos que estés $gpreparado:preparada; para esta tarea...', 0);
-- 1884 Montones de Ju-Ju
-- https://es.classic.wowhead.com/quest=1884
SET @ID := 1884;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Montones de Juju destruidos', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes darte prisa, $n. ¡Destruye los montones de Juju!', 0),
(@ID, 'esMX', 'Debes darte prisa, $n. ¡Destruye los montones de Juju!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo sentir que los montones de Juju de Zalazane han sido destruidos y con tiempo y algo de suerte, el flujo de magia de Durotar volverá a la normalidad.$B$BHas hecho una gran gesta por nuestro pueblo, $n. Y has demostrado tu valor para nosotros, los magos de la Horda.', 0),
(@ID, 'esMX', 'Puedo sentir que los montones de Juju de Zalazane han sido destruidos y con tiempo y algo de suerte, el flujo de magia de Durotar volverá a la normalidad.$B$BHas hecho una gran gesta por nuestro pueblo, $n. Y has demostrado tu valor para nosotros, los magos de la Horda.', 0);
-- 1885 Mennet Carkad
-- https://es.classic.wowhead.com/quest=1885
SET @ID := 1885;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mmm? No hay duda de que has venido tan pronto te has enterado de que requería tu presencia. Claro que no esperaría otra cosa de $gun futuro mortacechador:una futura mortacechadora;.', 0),
(@ID, 'esMX', '¿Mmm? No hay duda de que has venido tan pronto te has enterado de que requería tu presencia. Claro que no esperaría otra cosa de $gun futuro mortacechador:una futura mortacechadora;.', 0);
-- 1886 Los mortacechadores
-- https://es.classic.wowhead.com/quest=1886
SET @ID := 1886;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has logrado?', 0),
(@ID, 'esMX', '¿Lo has logrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Has superado la primera parte de esta prueba. Con un poco de suerte, Andron no se dará cuenta de nada y creerá que eres realmente el mensajero que estaba esperando.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Has superado la primera parte de esta prueba. Con un poco de suerte, Andron no se dará cuenta de nada y creerá que eres realmente el mensajero que estaba esperando.', 0);
-- 1898 Los mortacechadores
-- https://es.classic.wowhead.com/quest=1898
SET @ID := 1898;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. ¿Hay algo que pueda hacer por ti?', 0),
(@ID, 'esMX', 'Hola. ¿Hay algo que pueda hacer por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Te estaba esperando. Seguro que quienes te envían están satisfechos con la información que les he dado hasta el momento, ¿no?$B$BSupongo que no tiene mucho sentido que te haga esta pregunta pues seguro que desconoces la respuesta. No creo que confiaran tanto en $gun simple mensajero:una simple mensajera;...', 0),
(@ID, 'esMX', '¡Ah! Te estaba esperando. Seguro que quienes te envían están satisfechos con la información que les he dado hasta el momento, ¿no?$B$BSupongo que no tiene mucho sentido que te haga esta pregunta pues seguro que desconoces la respuesta. No creo que confiaran tanto en $gun simple mensajero:una simple mensajera;...', 0);
-- 1899 Los mortacechadores
-- https://es.classic.wowhead.com/quest=1899
SET @ID := 1899;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has logrado, $n?', 0),
(@ID, 'esMX', '¿Lo has logrado, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sin duda, has obtenido más información de Andron de la que esperaba. Déjame que le eche un vistazo antes de asignarte tu siguiente tarea.', 0),
(@ID, 'esMX', 'Sin duda, has obtenido más información de Andron de la que esperaba. Déjame que le eche un vistazo antes de asignarte tu siguiente tarea.', 0);
-- 1918 El elemento contaminado
-- https://es.classic.wowhead.com/quest=1918
SET @ID := 1918;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Necesitas algo?', 0),
(@ID, 'esMX', '¿Sí? ¿Necesitas algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te encuentras una asquerosa bola de agua ¿y decides traérmela? ¡¿Quién crees que soy?! ¿El Anillo de la Tierra o algo así?$B$BDe hecho, esto me da una idea... quizás necesites al Anillo de la Tierra para esto. Vamos, que si contribuye a aclarar lo del lago de una vez por todas, estoy contigo.$B$B¿Sabes quiénes integran el Anillo de la Tierra, $n?', 0),
(@ID, 'esMX', 'Te encuentras una asquerosa bola de agua ¿y decides traérmela? ¡¿Quién crees que soy?! ¿El Anillo de la Tierra o algo así?$B$BDe hecho, esto me da una idea... quizás necesites al Anillo de la Tierra para esto. Vamos, que si contribuye a aclarar lo del lago de una vez por todas, estoy contigo.$B$B¿Sabes quiénes integran el Anillo de la Tierra, $n?', 0);
-- 1919 Preséntate ante Jennea
-- https://es.classic.wowhead.com/quest=1919
SET @ID := 1919;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, tengo una misión para ti, aquí en el distrito de los $c. Escucha atentamente, porque no hay tiempo que perder.', 0),
(@ID, 'esMX', '$n, tengo una misión para ti, aquí en el distrito de los $c. Escucha atentamente, porque no hay tiempo que perder.', 0);
-- 1920 Investiga lo que pasa en El Ermitaño Taciturno
-- https://es.classic.wowhead.com/quest=1920
SET @ID := 1920;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has capturado a las criaturas, $n? Deben ser estudiadas para determinar el motivo de su llegada.', 0),
(@ID, 'esMX', '¿Has capturado a las criaturas, $n? Deben ser estudiadas para determinar el motivo de su llegada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien hecho! Estudiaré estas criaturas y, con diligencia y suerte, determinaré cómo se deslizaron en nuestro mundo.$B$BTu valor para la sociedad de magos crece, $n.', 0),
(@ID, 'esMX', '¡Muy bien hecho! Estudiaré estas criaturas y, con diligencia y suerte, determinaré cómo se deslizaron en nuestro mundo.$B$BTu valor para la sociedad de magos crece, $n.', 0);
-- 1921 Recolección de materiales
-- https://es.classic.wowhead.com/quest=1921
SET @ID := 1921;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. Jennea me dijo que vendrías. ¿Tienes algo para mí?', 0),
(@ID, 'esMX', 'Hola, $n. Jennea me dijo que vendrías. ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, son unas piezas de lino excelentes. Podré hacer una bonita túnica y cuando entreteja las gemas de la falla, ¡tendremos una prenda realmente digna de $gun:una; $c!', 0),
(@ID, 'esMX', 'Sí, son unas piezas de lino excelentes. Podré hacer una bonita túnica y cuando entreteja las gemas de la falla, ¡tendremos una prenda realmente digna de $gun:una; $c!', 0);
-- 1938 Tratado de Ur sobre la Magia de las Sombras
-- https://es.classic.wowhead.com/quest=1938
SET @ID := 1938;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el libro, $n? Sus secretos no son para los no instruidos y mirar sus entrañas puede llevar a la perdición y a la ruina.', 0),
(@ID, 'esMX', '¿Tienes el libro, $n? Sus secretos no son para los no instruidos y mirar sus entrañas puede llevar a la perdición y a la ruina.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Temía que Morganth hubiera escondido el libro en algún otro sitio o que hubiera encontrado un modo de abrirlo y leer su contenido.$B$BMe alegra saber que no fue así y que los sellos del Tratado de Ur sobre la Magia de las Sombras siguen en su sitio.', 0),
(@ID, 'esMX', 'Temía que Morganth hubiera escondido el libro en algún otro sitio o que hubiera encontrado un modo de abrirlo y leer su contenido.$B$BMe alegra saber que no fue así y que los sellos del Tratado de Ur sobre la Magia de las Sombras siguen en su sitio.', 0);
-- 1939 Sumo Hechicero Andromath
-- https://es.classic.wowhead.com/quest=1939
SET @ID := 1939;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Es un placer verte, espero que tengas algo de tiempo para escuchar las palabras de un anciano...', 0),
(@ID, 'esMX', 'Saludos, $n. Es un placer verte, espero que tengas algo de tiempo para escuchar las palabras de un anciano...', 0);
-- 1940 Seda prístina de araña
-- https://es.classic.wowhead.com/quest=1940
SET @ID := 1940;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Los magos del Sagrario dijeron que vendrías a hablar conmigo. ¿Tienes la seda necesaria?', 0),
(@ID, 'esMX', 'Ah, sí. Los magos del Sagrario dijeron que vendrías a hablar conmigo. ¿Tienes la seda necesaria?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Unos bonitos especimenes. ¡Me pondré manos a la obra!', 0),
(@ID, 'esMX', 'Unos bonitos especimenes. ¡Me pondré manos a la obra!', 0);
-- 1941 Toga Tejemaná
-- https://es.classic.wowhead.com/quest=1941
SET @ID := 1941;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está tu toga. ¡Es una de las mejores que he hecho nunca! Llévala con orgullo y cuando te pregunten... ¡di que te la hicieron en Diseños Larson!', 0),
(@ID, 'esMX', 'Aquí está tu toga. ¡Es una de las mejores que he hecho nunca! Llévala con orgullo y cuando te pregunten... ¡di que te la hicieron en Diseños Larson!', 0);
-- 1942 Prendas de nudo astral
-- https://es.classic.wowhead.com/quest=1942
SET @ID := 1942;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya está lista! La seda que trajiste era tan delicada... que te hice la prenda un poco pequeña para quedarme yo con algo de sobra, ¿no te importa, verdad?$B$BEs una broma. Te quedará perfecta y será ideal tanto para tus aventuras como para una cena formal. ¡Que la disfrutes!', 0),
(@ID, 'esMX', '¡Ya está lista! La seda que trajiste era tan delicada... que te hice la prenda un poco pequeña para quedarme yo con algo de sobra, ¿no te importa, verdad?$B$BEs una broma. Te quedará perfecta y será ideal tanto para tus aventuras como para una cena formal. ¡Que la disfrutes!', 0);
-- 1943 Habla con Deino
-- https://es.classic.wowhead.com/quest=1943
SET @ID := 1943;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, has venido. Mi tarea no es fácil, pero es vital para la sociedad de magos. Si me ayudas estoy segura de que te merecerá la pena.', 0),
(@ID, 'esMX', 'Bien, has venido. Mi tarea no es fácil, pero es vital para la sociedad de magos. Si me ayudas estoy segura de que te merecerá la pena.', 0);
-- 1944 Aguas de Xavian
-- https://es.classic.wowhead.com/quest=1944
SET @ID := 1944;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra que hayas regresado con la piel intacta, $n. ¿Tienes la muestra de agua? Estoy ansioso por estudiar sus propiedades.', 0),
(@ID, 'esMX', 'Me alegra que hayas regresado con la piel intacta, $n. ¿Tienes la muestra de agua? Estoy ansioso por estudiar sus propiedades.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. ¿Confío en que los sátiros de Xavian te hayan dado pocos problemas?$B$BGracias, $n. Estudiaré esta muestra de agua de Xavian inmediatamente.', 0),
(@ID, 'esMX', 'Ah, muy bien. ¿Confío en que los sátiros de Xavian te hayan dado pocos problemas?$B$BGracias, $n. Estudiaré esta muestra de agua de Xavian inmediatamente.', 0);
-- 1945 Hermanas sonrientes
-- https://es.classic.wowhead.com/quest=1945
SET @ID := 1945;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Deino me dijo que vendrías y que traerías el cabello de hermana sonriente. ¿Lo has traído?', 0),
(@ID, 'esMX', 'Saludos, $n. Deino me dijo que vendrías y que traerías el cabello de hermana sonriente. ¿Lo has traído?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, este cabello será perfecto para tejer una buena túnica, $n. Es una pena que las hermanas sonrientes tuvieran que morir para quitárselo, pero dudo que lo hubieran dado voluntariamente.$B$BUna pena... pero pequeña.', 0),
(@ID, 'esMX', 'Ah, este cabello será perfecto para tejer una buena túnica, $n. Es una pena que las hermanas sonrientes tuvieran que morir para quitárselo, pero dudo que lo hubieran dado voluntariamente.$B$BUna pena... pero pequeña.', 0);
-- 1946 Prendas de encaje Abisal
-- https://es.classic.wowhead.com/quest=1946
SET @ID := 1946;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes tu encaje abisal, $n. Es cómodo y duradero y alberga la magia del cabello de las hermanas sonrientes.$B$BDisfrútalo y si lo encuentras adecuado menciónaselo a Deino, la maga. Me gustaría estar de su lado...', 0),
(@ID, 'esMX', 'Aquí tienes tu encaje abisal, $n. Es cómodo y duradero y alberga la magia del cabello de las hermanas sonrientes.$B$BDisfrútalo y si lo encuentras adecuado menciónaselo a Deino, la maga. Me gustaría estar de su lado...', 0);
-- 1947 Viaje al pantano
-- https://es.classic.wowhead.com/quest=1947
SET @ID := 1947;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Silencio! ¡Es un momento muy delicado, no me molestes!$B$BUn momento...', 0),
(@ID, 'esMX', '¡Silencio! ¡Es un momento muy delicado, no me molestes!$B$BUn momento...', 0);
-- 1948 Objetos de poder
-- https://es.classic.wowhead.com/quest=1948
SET @ID := 1948;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Tienes los objetos que necesito?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Tienes los objetos que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aja! ¡Tienes el jade y la zarza! ¡Bien hecho!$B$B¿No es humo lo que veo salirte de las orejas? Debías estar demasiado cerca cuando el rayo golpeó el palo de tótem, pero no te preocupes, ¡ser golpeado por un rayo trae buena suerte!', 0),
(@ID, 'esMX', '¡Aja! ¡Tienes el jade y la zarza! ¡Bien hecho!$B$B¿No es humo lo que veo salirte de las orejas? Debías estar demasiado cerca cuando el rayo golpeó el palo de tótem, pero no te preocupes, ¡ser golpeado por un rayo trae buena suerte!', 0);
-- 1949 Secretos escondidos
-- https://es.classic.wowhead.com/quest=1949
SET @ID := 1949;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? ¡Habla más alto! Estos viejos oídos ya no son lo que eran.$B$B¡Bien, espero que hayas venido con una jarra fresca de cerveza o con alguna información para la siguiente carrera! Si no es así, más vale que te vayas... ¡porque tengo una varita polimorfizadora que lleva escrito tu nombre!', 0),
(@ID, 'esMX', '¿Qué? ¡Habla más alto! Estos viejos oídos ya no son lo que eran.$B$B¡Bien, espero que hayas venido con una jarra fresca de cerveza o con alguna información para la siguiente carrera! Si no es así, más vale que te vayas... ¡porque tengo una varita polimorfizadora que lleva escrito tu nombre!', 0);
-- 1950 Santo y seña
-- https://es.classic.wowhead.com/quest=1950
SET @ID := 1950;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que estas esperando? ¡Necesito mi frase mágica!', 0),
(@ID, 'esMX', '¿Que estas esperando? ¡Necesito mi frase mágica!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ya recuerdo...$B$BMe había olvidado de la pequeña maldición que lancé sobre Johnson. No puedo recordar porqué lo hice pero seguro que le ha venido bien, ¡pequeño ingrato!', 0),
(@ID, 'esMX', 'Ah, ya recuerdo...$B$BMe había olvidado de la pequeña maldición que lancé sobre Johnson. No puedo recordar porqué lo hice pero seguro que le ha venido bien, ¡pequeño ingrato!', 0);
-- 1951 Rituales de poder
-- https://es.classic.wowhead.com/quest=1951
SET @ID := 1951;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. ¿Encontraste el libro Rituales de Poder?', 0),
(@ID, 'esMX', 'Saludos, $n. ¿Encontraste el libro Rituales de Poder?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! ¡Es justo lo que necesito para prepararme para el ritual para crear tu varita! Espero que no haya sido una gran molestia encontrarlo...', 0),
(@ID, 'esMX', '¡Eso es! ¡Es justo lo que necesito para prepararme para el ritual para crear tu varita! Espero que no haya sido una gran molestia encontrarlo...', 0);
-- 1952 Varitas de mago
-- https://es.classic.wowhead.com/quest=1952
SET @ID := 1952;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí están las varitas que hice. ¡Elige una!', 0),
(@ID, 'esMX', 'Aquí están las varitas que hice. ¡Elige una!', 0);
-- 1953 Regresa a la Marisma
-- https://es.classic.wowhead.com/quest=1953
SET @ID := 1953;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. ¿Estás aquí por un orbe o un bastón, $n? Muy bien. Te ayudaré en su construcción.$B$BPero ten cuidado: el proceso es peligroso y podría significar tu muerte.$B$BO mi muerte. Definitivamente la muerte de alguien...$B$BPero esperemos que sea la muerte de otro, ¿eh?', 0),
(@ID, 'esMX', 'Ah, sí. ¿Estás aquí por un orbe o un bastón, $n? Muy bien. Te ayudaré en su construcción.$B$BPero ten cuidado: el proceso es peligroso y podría significar tu muerte.$B$BO mi muerte. Definitivamente la muerte de alguien...$B$BPero esperemos que sea la muerte de otro, ¿eh?', 0);
-- 1954 El orbe infernal
-- https://es.classic.wowhead.com/quest=1954
SET @ID := 1954;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes un orbe infernal, $n?', 0),
(@ID, 'esMX', '¿Tienes un orbe infernal, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, qué bonito! No, no me refiero a que sea "agradable" como el jugo fresco en un día caluroso.$B$BDe hecho, NO es muy agradable ahora que lo pienso. No el jugo. ¡El orbe!$B$B¡Concéntrate, $n! ¡Necesitamos que te concentres si alguna vez vamos a terminar nuestra tarea!', 0),
(@ID, 'esMX', '¡Oh, qué bonito! No, no me refiero a que sea "agradable" como el jugo fresco en un día caluroso.$B$BDe hecho, NO es muy agradable ahora que lo pienso. No el jugo. ¡El orbe!$B$B¡Concéntrate, $n! ¡Necesitamos que te concentres si alguna vez vamos a terminar nuestra tarea!', 0);
-- 1955 El exorcismo
-- https://es.classic.wowhead.com/quest=1955
SET @ID := 1955;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tendrás que matar a ese demonio para eliminar su mancha del orbe, $n.', 0),
(@ID, 'esMX', 'Tendrás que matar a ese demonio para eliminar su mancha del orbe, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Le diste a ese demonio una lección que no olvidará.$B$BSe lo pensará dos veces antes de asomar su fea cabeza otra vez en este mundo, buscando al estúpido mortal que lo golpeó. Probablemente con amigos esta vez. Amigos grandes y escamosos que no querrían nada más que hacerte pedazos $r.$B$BNo te asusté, ¿verdad... $n?', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Le diste a ese demonio una lección que no olvidará.$B$BSe lo pensará dos veces antes de asomar su fea cabeza otra vez en este mundo, buscando al estúpido mortal que lo golpeó. Probablemente con amigos esta vez. Amigos grandes y escamosos que no querrían nada más que hacerte pedazos $r.$B$BNo te asusté, ¿verdad... $n?', 0);
-- 1956 Poder en Uldaman
-- https://es.classic.wowhead.com/quest=1956
SET @ID := 1956;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en Uldaman, $n? ¿Has derrotado al centinela de obsidiana?', 0),
(@ID, 'esMX', '¿Has estado en Uldaman, $n? ¿Has derrotado al centinela de obsidiana?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo hiciste? ¡Bien hecho!$B$BEstaba charlando con algunos de mis colegas y cuando apareció tu nombre, dijeron: "¡Sabes que $n seguro que funciona bien bajo presión!"$B$BPero cuando les dije que te enviaba a Uldaman contra el centinela de obsidiana, ¡dijeron que estaba loca! Dijeron: "¡Tabetha, estás loca! ¡No hay forma de que $n pueda enfrentarse a ese centinela!"$B$BY dije: "Ya veremos", y luego dijeron "Sí, ya veremos..."$B$BBueno, seguro que lo verán, ¿no?', 0),
(@ID, 'esMX', '¿Lo hiciste? ¡Bien hecho!$B$BEstaba charlando con algunos de mis colegas y cuando apareció tu nombre, dijeron: "¡Sabes que $n seguro que funciona bien bajo presión!"$B$BPero cuando les dije que te enviaba a Uldaman contra el centinela de obsidiana, ¡dijeron que estaba loca! Dijeron: "¡Tabetha, estás loca! ¡No hay forma de que $n pueda enfrentarse a ese centinela!"$B$BY dije: "Ya veremos", y luego dijeron "Sí, ya veremos..."$B$BBueno, seguro que lo verán, ¿no?', 0);
