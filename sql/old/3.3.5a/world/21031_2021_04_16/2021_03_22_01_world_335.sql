-- 8240 Una joya para Zanza
-- https://es.classic.wowhead.com/quest=8240
SET @ID := 8240;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has destruido la joya en el Altar de Zanza? ¡Hazlo y serás $gbendecido:bendecida; doblemente por Zanza!', 0),
(@ID, 'esMX', '¿Has destruido la joya en el Altar de Zanza? ¡Hazlo y serás $gbendecido:bendecida; doblemente por Zanza!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente... cada una de las joyas que arrebatamos a los esbirros del Dios de la Sangre nos acerca a su derrota final. Tus nobles hazañas llenan de honor a los Zandalar y a ti mismo.$B$BRecuerda, $n, puedes destruir las joyas que encuentres en Zul\'Gurub en el altar. Por cada joya ganarás nuestro reconocimiento y una muestra de honor. Recuerda tener un espacio libre en tu inventario si aún no tienes ninguna muestra.', 0),
(@ID, 'esMX', 'Excelente... cada una de las joyas que arrebatamos a los esbirros del Dios de la Sangre nos acerca a su derrota final. Tus nobles hazañas llenan de honor a los Zandalar y a ti mismo.$B$BRecuerda, $n, puedes destruir las joyas que encuentres en Zul\'Gurub en el altar. Por cada joya ganarás nuestro reconocimiento y una muestra de honor. Recuerda tener un espacio libre en tu inventario si aún no tienes ninguna muestra.', 0);
-- 8241 Fabricar flujo ígneo con hierro
-- https://es.classic.wowhead.com/quest=8241
SET @ID := 8241;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi tiempo es demasiado valioso para perderlo con charlas, $r. Quiero fabricar más flujo ígneo.$B$BPara eso, necesito que me traigas lo siguiente:$B$B*Escamas de incendosaurio.$B$B*Barras de hierro.$B$B*Carbón.$B$B¡Tráeme tanto como puedas!$B$BY tan rápido como puedas, si es que quieres ganarte el favor de la Hermandad.', 0),
(@ID, 'esMX', 'Mi tiempo es demasiado valioso para perderlo con charlas, $r. Quiero fabricar más flujo ígneo.$B$BPara eso, necesito que me traigas lo siguiente:$B$B*Escamas de incendosaurio.$B$B*Barras de hierro.$B$B*Carbón.$B$B¡Tráeme tanto como puedas!$B$BY tan rápido como puedas, si es que quieres ganarte el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre hay sitio para el flujo ígneo. Tú sigue trayendo hasta que yo te diga.', 0),
(@ID, 'esMX', 'Siempre hay sitio para el flujo ígneo. Tú sigue trayendo hasta que yo te diga.', 0);
-- 8242 Fabricar flujo ígneo con cuero pesado
-- https://es.classic.wowhead.com/quest=8242
SET @ID := 8242;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi tiempo es demasiado valioso para perderlo con charlas, $r. Quiero fabricar más flujo ígneo.$B$BPara eso, necesito que me traigas lo siguiente:$B$B*Escamas de incendosaurio.$B$B*Cuero pesado.$B$B*Carbón.$B$B¡Tráeme tanto como puedas!$B$BY tan rápido como puedas, si es que quieres ganarte el favor de la Hermandad.', 0),
(@ID, 'esMX', 'Mi tiempo es demasiado valioso para perderlo con charlas, $r. Quiero fabricar más flujo ígneo.$B$BPara eso, necesito que me traigas lo siguiente:$B$B*Escamas de incendosaurio.$B$B*Cuero pesado.$B$B*Carbón.$B$B¡Tráeme tanto como puedas!$B$BY tan rápido como puedas, si es que quieres ganarte el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre hay sitio para el flujo ígneo. Tú sigue trayendo hasta que yo te diga.', 0),
(@ID, 'esMX', 'Siempre hay sitio para el flujo ígneo. Tú sigue trayendo hasta que yo te diga.', 0);
-- 8243 Los mejunjes potentes de Zanza
-- https://es.classic.wowhead.com/quest=8243
SET @ID := 8243;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a tu estatus entre los de la tribu puedes acceder a algunos de nuestros mejunjes potentes. Mira... estos brebajes reciben su fuerza del mojo, están bendecidos por Zanza y se preparan para los aventureros de todo tipo y procedencia.$B$BTe permitiré elegir uno de los tres tipos de bebida que preparo pero a cambio necesito tres muestras de honor Zandalar. Ten en cuenta que solo pueden fluir por tu espíritu los efectos de un solo brebaje al mismo tiempo.$B$B¡Avísame cuando estés $glisto:lista; para el trueque!', 0),
(@ID, 'esMX', 'Gracias a tu estatus entre los de la tribu puedes acceder a algunos de nuestros mejunjes potentes. Mira... estos brebajes reciben su fuerza del mojo, están bendecidos por Zanza y se preparan para los aventureros de todo tipo y procedencia.$B$BTe permitiré elegir uno de los tres tipos de bebida que preparo pero a cambio necesito tres muestras de honor Zandalar. Ten en cuenta que solo pueden fluir por tu espíritu los efectos de un solo brebaje al mismo tiempo.$B$B¡Avísame cuando estés $glisto:lista; para el trueque!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen trato, $gamigo mío:amiga mía;, por favor, ¡disfruta de la bendición de Zanza y de un cordial saludo!', 0),
(@ID, 'esMX', 'Un buen trato, $gamigo mío:amiga mía;, por favor, ¡disfruta de la bendición de Zanza y de un cordial saludo!', 0);
-- 8246 Las sortijas de Zandalar
-- https://es.classic.wowhead.com/quest=8246
SET @ID := 8246;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, tengo algo muy especial para $gun exaltado:una exaltada; como tú entre los Zandalar. Venido directamente desde nuestro hogar en los Mares del Sur... ¡las sortijas de Zandalar! Estas sortijas se utilizan para mejorar cualquier hombrera. Si deseas fuerza, mojo o serenidad, ¡tengo lo que necesitas!$B$BA cambio de una sortija a tu elección solo te pido 15 muestras de honor Zandalar. Si ya tienes las muestras, ¡podemos pasar al trato!', 0),
(@ID, 'esMX', '$n, tengo algo muy especial para $gun exaltado:una exaltada; como tú entre los Zandalar. Venido directamente desde nuestro hogar en los Mares del Sur... ¡las sortijas de Zandalar! Estas sortijas se utilizan para mejorar cualquier hombrera. Si deseas fuerza, mojo o serenidad, ¡tengo lo que necesitas!$B$BA cambio de una sortija a tu elección solo te pido 15 muestras de honor Zandalar. Si ya tienes las muestras, ¡podemos pasar al trato!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen trato, $gamigo mío:amiga mía;, por favor, acepta la sortija y la bendición de la tribu.', 0),
(@ID, 'esMX', 'Un buen trato, $gamigo mío:amiga mía;, por favor, acepta la sortija y la bendición de la tribu.', 0);
-- 8249 Se necesitan cajas de trastos
-- https://es.wowhead.com/quest=8249
SET @ID := 8249;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis pícaros tienen que mejorar su técnica de forzar cerraduras y necesito algunas bien duras de roer; las de Zan solo valen para los novatos más torpes.$B$BMira, si me traes 5 cajas de trastos pesadas, hablaré bien de ti por aquí.$B$BPuedes abrir las cajas y quedarte lo que quieras, pero deja algunas monedas; los pícaros principiantes también necesitan motivación.', 0),
(@ID, 'esMX', 'Mis pícaros tienen que mejorar su técnica de forzar cerraduras y necesito algunas bien duras de roer; las de Zan solo valen para los novatos más torpes.$B$BMira, si me traes 5 cajas de trastos pesadas, hablaré bien de ti por aquí.$B$BPuedes abrir las cajas y quedarte lo que quieras, pero deja algunas monedas; los pícaros principiantes también necesitan motivación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que estos cuchillos le lleguen a alguien al corazón.$B$BLiteralmente.', 0),
(@ID, 'esMX', 'Espero que estos cuchillos le lleguen a alguien al corazón.$B$BLiteralmente.', 0);
-- 8250 Pura magia
-- Notice: English text: Change 'Arch$c' to 'Archmage' is also missing in quest_offer_reward.RewardText
-- https://es.classic.wowhead.com/quest=8250
SET @ID := 8250;
UPDATE `quest_offer_reward` SET `RewardText` = '<Sanath sneers at you.>$B$BArchmage Xylem awaits your arrival.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Sanath se burla de ti.>$B$BEl Archimago Xylem espera tu llegada.', 0),
(@ID, 'esMX', '<Sanath se burla de ti.>$B$BEl Archimago Xylem espera tu llegada.', 0);
-- 8251 El polvo mágico
-- https://es.classic.wowhead.com/quest=8251
SET @ID := 8251;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el polvo?', 0),
(@ID, 'esMX', '¿Tienes el polvo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Nunca deja de sorprenderme lo persuasiva que puede ser una andanada de misiles arcanos.', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Nunca deja de sorprenderme lo persuasiva que puede ser una andanada de misiles arcanos.', 0);
-- 8252 El coral de las sirenas
-- https://es.classic.wowhead.com/quest=8252
SET @ID := 8252;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las sirenas de Látigo de Ira son sorprendentemente hábiles magas. No tan hábiles como tú, espero.', 0),
(@ID, 'esMX', 'Las sirenas de Látigo de Ira son sorprendentemente hábiles magas. No tan hábiles como tú, espero.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este es un magnífico ejemplar de coral, $n. Tus habilidades son incuestionablemente precisas y mortales.$B$BNo creas que tus esfuerzos han pasado desapercibidos. Quizás seas $gdigno:digna; de una verdadera prueba de tu habilidad...', 0),
(@ID, 'esMX', 'Este es un magnífico ejemplar de coral, $n. Tus habilidades son incuestionablemente precisas y mortales.$B$BNo creas que tus esfuerzos han pasado desapercibidos. Quizás seas $gdigno:digna; de una verdadera prueba de tu habilidad...', 0);
-- 8253 Destruye a Morphaz
-- https://es.classic.wowhead.com/quest=8253
SET @ID := 8253;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a mi viejo némesis?', 0),
(@ID, 'esMX', '¿Has matado a mi viejo némesis?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Increíble. El fragmento ha crecido a medida que absorbía la energía del dragón durante muchos años.$B$BNo puedo pedirte más ahora. Mi capacidad total para forjar lo arcano ha regresado con este fragmento. Mi primera creación es tuya, $n, y solo tienes que elegir...', 0),
(@ID, 'esMX', 'Increíble. El fragmento ha crecido a medida que absorbía la energía del dragón durante muchos años.$B$BNo puedo pedirte más ahora. Mi capacidad total para forjar lo arcano ha regresado con este fragmento. Mi primera creación es tuya, $n, y solo tienes que elegir...', 0);
-- 8254 Ayuda a Cenarion
-- https://es.classic.wowhead.com/quest=8254
SET @ID := 8254;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu llegada me ha quitado un peso de encima. Tenemos mucho que hacer.', 0),
(@ID, 'esMX', 'Tu llegada me ha quitado un peso de encima. Tenemos mucho que hacer.', 0);
-- 8255 Los trotadores Pezuñamusgo
-- https://es.classic.wowhead.com/quest=8255
SET @ID := 8255;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado. ¿Tuviste éxito?', 0),
(@ID, 'esMX', 'Has regresado. ¿Tuviste éxito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno que el camino divino te haya llevado hasta nosotros, $n. Tus creencias no interfieren con las tareas involucradas en la creación de este bálsamo.$B$BVerás, el corcel es sagrado para el Círculo Cenarion, y matarlos por cualquier motivo, sin importar cuán necesario sea, debilita su espíritu.', 0),
(@ID, 'esMX', 'Es bueno que el camino divino te haya llevado hasta nosotros, $n. Tus creencias no interfieren con las tareas involucradas en la creación de este bálsamo.$B$BVerás, el corcel es sagrado para el Círculo Cenarion, y matarlos por cualquier motivo, sin importar cuán necesario sea, debilita su espíritu.', 0);
-- 8256 El icor de los no-muertos
-- https://es.classic.wowhead.com/quest=8256
SET @ID := 8256;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debemos obtener el icor rápidamente. ¿Lo has encontrado?', 0),
(@ID, 'esMX', 'Debemos obtener el icor rápidamente. ¿Lo has encontrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo decir que me complace recibir una sustancia tan miserable, pero es un mal necesario. Gracias, $n.', 0),
(@ID, 'esMX', 'No puedo decir que me complace recibir una sustancia tan miserable, pero es un mal necesario. Gracias, $n.', 0);
-- 8257 La sangre de Morphaz
-- https://es.classic.wowhead.com/quest=8257
SET @ID := 8257;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la sangre de Morphaz?', 0),
(@ID, 'esMX', '¿Tienes la sangre de Morphaz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has matado a Morphaz y nos has traído su sangre... ¡Apenas puedo creer esta buena noticia!$B$BCombinaremos los ingredientes de una vez y comenzaremos a curar los árboles y las criaturas de Frondavil. Nos llevará toda una vida deshacer lo que ha sucedido aquí, pero nos has dado los medios para hacerlo.', 0),
(@ID, 'esMX', 'Has matado a Morphaz y nos has traído su sangre... ¡Apenas puedo creer esta buena noticia!$B$BCombinaremos los ingredientes de una vez y comenzaremos a curar los árboles y las criaturas de Frondavil. Nos llevará toda una vida deshacer lo que ha sucedido aquí, pero nos has dado los medios para hacerlo.', 0);
-- 8258 La amenaza de Atracoscuro
-- https://es.classic.wowhead.com/quest=8258
SET @ID := 8258;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo es crítico, $n. ¿Has logrado detener la amenaza del Caballero de la Muerte Atracoscuro?', 0),
(@ID, 'esMX', 'El tiempo es crítico, $n. ¿Has logrado detener la amenaza del Caballero de la Muerte Atracoscuro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta es una victoria para saborear, $n! La desaparición de Atracoscuro debería restaurar los frágiles grilletes que anclan el reino de los espíritus.$B$BHas sobrepasado con creces lo que se te pidió, incluso cuando no tenías noción de recompensa o compensación. Eres realmente $gun:una; $n de valor, $gamigo mío:amiga mía;.$B$BSé que actuar para preservar el reino de los espíritus debería ser un agradecimiento suficiente, pero por favor, acepta este simple regalo con mi gratitud.', 0),
(@ID, 'esMX', '¡Esta es una victoria para saborear, $n! La desaparición de Atracoscuro debería restaurar los frágiles grilletes que anclan el reino de los espíritus.$B$BHas sobrepasado con creces lo que se te pidió, incluso cuando no tenías noción de recompensa o compensación. Eres realmente $gun:una; $n de valor, $gamigo mío:amiga mía;.$B$BSé que actuar para preservar el reino de los espíritus debería ser un agradecimiento suficiente, pero por favor, acepta este simple regalo con mi gratitud.', 0);
-- Botiquín básico de Arathor
-- Botiquín básico de Arathor
-- 8260, 8261, 8263, 8264, 8265
-- https://es.classic.wowhead.com/quest=8260
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8260, 8261, 8263, 8264, 8265) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8260, 'esES', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8261, 'esES', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8263, 'esES', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8264, 'esES', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8265, 'esES', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8260, 'esMX', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8261, 'esMX', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8263, 'esMX', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8264, 'esMX', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0),
(8265, 'esMX', 'Ciertamente has empezado a demostrar tu valía ante nosotros, $n. ¡Como recompensa, llévate este botiquín! En su interior encontrarás raciones y vendajes que solo se pueden usar dentro de la Cuenca de Arathi.$B$BA medida que sigas demostrando su valía dentro de la Cuenca, encontrarás que estos artículos estarán disponibles para su compra. Las raciones están disponibles cuando eres Amistoso con nosotros y los vendajes cuando eres Honorable.', 0);
-- Galón de sacrificio
-- 8266, 8267, 8268, 8269
-- https://es.classic.wowhead.com/quest=8266
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8266, 8267, 8268, 8269) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8266, 'esES', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0),
(8267, 'esES', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0),
(8268, 'esES', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0),
(8269, 'esES', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0),
(8266, 'esMX', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0),
(8267, 'esMX', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0),
(8268, 'esMX', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0),
(8269, 'esMX', 'Bueno, no huiste ante la derrota. Te mantuviste firme, $n, y cuando se trata de eso, eso es lo que te convierte en $gun verdadero héroe:una verdadera heroína;. Sin duda ganarás la próxima vez... pero no obstante te agradecemos tu esfuerzo.', 0);
-- 8271 Héroe Pico Tormenta
-- https://es.classic.wowhead.com/quest=8271
SET @ID := 8271;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Como $ghéroe:heroína; de los Pico Tormenta, puedes elegir uno de los objetos del tesoro recientemente saqu... ejem, recuperado.', 0),
(@ID, 'esMX', 'Como $ghéroe:heroína; de los Pico Tormenta, puedes elegir uno de los objetos del tesoro recientemente saqu... ejem, recuperado.', 0);
-- 8272 Héroe de Lobo Gélido
-- https://es.classic.wowhead.com/quest=8272
SET @ID := 8272;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué se siente, $n? ¿Qué se siente al aplastar a los enemigos y ver cómo sus líneas se diseminan? Sienta bien, ¿eh?$B$BSe te recompensará por este acto heroico, soldado.', 0),
(@ID, 'esMX', '¿Qué se siente, $n? ¿Qué se siente al aplastar a los enemigos y ver cómo sus líneas se diseminan? Sienta bien, ¿eh?$B$BSe te recompensará por este acto heroico, soldado.', 0);
-- 8273 La gratitud Oran
-- https://es.classic.wowhead.com/quest=8273
SET @ID := 8273;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No te parece interesante? ¿Y dices que encontraste esta tablilla en una pequeña isla desierta en Los Acantilados Dominantes de las Tierras del Interior, $c? En verdad resulta interesante. $B$BTe agradezco tus esfuerzos. Nuestra Dama Oscura se alegrará mucho con este hallazgo. Aquí tienes una recompensa a la altura.', 0),
(@ID, 'esMX', '¿No te parece interesante? ¿Y dices que encontraste esta tablilla en una pequeña isla desierta en Los Acantilados Dominantes de las Tierras del Interior, $c? En verdad resulta interesante. $B$BTe agradezco tus esfuerzos. Nuestra Dama Oscura se alegrará mucho con este hallazgo. Aquí tienes una recompensa a la altura.', 0);
-- La reconquista de Silithus
-- 8275, 8276
-- https://es.classic.wowhead.com/quest=8275
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8275, 8276) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8275, 'esES', 'Excelente, $gun nuevo:una nueva; recluta respondiendo a la llamada a las armas contra el silítido. $gBienvenido:Birenvenida; a Fuerte Cenarion, $n. Me complace ver que las palabras de nuestros emisarios están llegando a $ghéroes:heroínas; de tu calibre. No encontrarás escasez de oportunidades para ayudarnos en nuestros esfuerzos aquí y espero que pronto demuestres ser $gun valioso aliado:una valiosa aliada; para nuestra causa.', 0),
(8276, 'esES', 'Excelente, $gun nuevo:una nueva; recluta respondiendo a la llamada a las armas contra el silítido. $gBienvenido:Birenvenida; a Fuerte Cenarion, $n. Me complace ver que las palabras de nuestros emisarios están llegando a $ghéroes:heroínas; de tu calibre. No encontrarás escasez de oportunidades para ayudarnos en nuestros esfuerzos aquí y espero que pronto demuestres ser $gun valioso aliado:una valiosa aliada; para nuestra causa.', 0),
(8275, 'esMX', 'Excelente, $gun nuevo:una nueva; recluta respondiendo a la llamada a las armas contra el silítido. $gBienvenido:Birenvenida; a Fuerte Cenarion, $n. Me complace ver que las palabras de nuestros emisarios están llegando a $ghéroes:heroínas; de tu calibre. No encontrarás escasez de oportunidades para ayudarnos en nuestros esfuerzos aquí y espero que pronto demuestres ser $gun valioso aliado:una valiosa aliada; para nuestra causa.', 0),
(8276, 'esMX', 'Excelente, $gun nuevo:una nueva; recluta respondiendo a la llamada a las armas contra el silítido. $gBienvenido:Birenvenida; a Fuerte Cenarion, $n. Me complace ver que las palabras de nuestros emisarios están llegando a $ghéroes:heroínas; de tu calibre. No encontrarás escasez de oportunidades para ayudarnos en nuestros esfuerzos aquí y espero que pronto demuestres ser $gun valioso aliado:una valiosa aliada; para nuestra causa.', 0);
-- 8277 Veneno mortal del desierto
-- https://es.classic.wowhead.com/quest=8277
SET @ID := 8277;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has terminado de conseguir esas muestras? ¡Podríamos perder a Noggle en cualquier minuto!', 0),
(@ID, 'esMX', '¿Has terminado de conseguir esas muestras? ¡Podríamos perder a Noggle en cualquier minuto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cruza los dedos! ¡Esperemos que podamos salvar a Noggle!', 0),
(@ID, 'esMX', '¡Cruza los dedos! ¡Esperemos que podamos salvar a Noggle!', 0);
-- 8278 La última esperanza de Noggle
-- https://es.wowhead.com/quest=8278
SET @ID := 8278;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta es nuestra última oportunidad de salvar a Noggle! ¡Rápido!', 0),
(@ID, 'esMX', '¡Esta es nuestra última oportunidad de salvar a Noggle! ¡Rápido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí! Parece que funciona, Noggle se está despertando. ¡Te lo agradezco un montón!', 0),
(@ID, 'esMX', '¡Sí! Parece que funciona, Noggle se está despertando. ¡Te lo agradezco un montón!', 0);
-- 8279 El Lexicón Crepuscular
-- https://es.wowhead.com/quest=8279
SET @ID := 8279;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quién anda ahí? ¡Oh, eres tú! ¿Ya has encontrado todos los capítulos del Lexicón?', 0),
(@ID, 'esMX', '¿Quién anda ahí? ¡Oh, eres tú! ¿Ya has encontrado todos los capítulos del Lexicón?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí! ¡Tienes las partes del libro! Comencemos, $n.$B$BCambia cada tercera palabra por palabras del segundo capítulo... y después cambia una palabra sí y otra no por palabras del primer capítulo... Espera, ¿he dicho eso al revés?', 0),
(@ID, 'esMX', '¡Sí! ¡Tienes las partes del libro! Comencemos, $n.$B$BCambia cada tercera palabra por palabras del segundo capítulo... y después cambia una palabra sí y otra no por palabras del primer capítulo... Espera, ¿he dicho eso al revés?', 0);
-- 8280 Asegurar las rutas de suministros
-- https://es.classic.wowhead.com/quest=8280
SET @ID := 8280;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los golpeadores deslizantes son una seria amenaza y deben ser tratados rápidamente!', 0),
(@ID, 'esMX', '¡Los golpeadores deslizantes son una seria amenaza y deben ser tratados rápidamente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes mi más sincera gratitud. Tus esfuerzos para ayudar al Fuerte Cenarion han demostrado tu valentía.', 0),
(@ID, 'esMX', 'Tienes mi más sincera gratitud. Tus esfuerzos para ayudar al Fuerte Cenarion han demostrado tu valentía.', 0);
-- 8281 Intensificar la seguridad
-- https://es.classic.wowhead.com/quest=8281
SET @ID := 8281;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los trituradores deslizantes son una seria amenaza y deben tratarse de inmediato!', 0),
(@ID, 'esMX', '¡Los trituradores deslizantes son una seria amenaza y deben tratarse de inmediato!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Demostraste ser $gun valioso aliado:una valiosa aliada; en la guerra contra los silítidos.', 0),
(@ID, 'esMX', '¡Excelente! Demostraste ser $gun valioso aliado:una valiosa aliada; en la guerra contra los silítidos.', 0);
-- 8282 La cartera perdida de Noggle
-- https://es.wowhead.com/quest=8282
SET @ID := 8282;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Todavía no has encontrado mi cartera? En fin, cruzaré los dedos, al menos ya no hay veneno.', 0),
(@ID, 'esMX', '¿Todavía no has encontrado mi cartera? En fin, cruzaré los dedos, al menos ya no hay veneno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí! Has recuperado mi bolsa. ¡Y están todos mis componentes exóticos! Estaré eternamente en deuda contigo.', 0),
(@ID, 'esMX', '¡Sí! Has recuperado mi bolsa. ¡Y están todos mis componentes exóticos! Estaré eternamente en deuda contigo.', 0);
-- 8283 Se busca: Pinzamorten el Terror de las arenas
-- https://es.wowhead.com/quest=8283
SET @ID := 8283;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitaré la pinza de la criatura como prueba. Sin pinza, no hay recompensa.', 0),
(@ID, 'esMX', 'Necesitaré la pinza de la criatura como prueba. Sin pinza, no hay recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Con Pinzamorten fuera del mapa, somos libres para utilizar las montañas del sur como camino estratégico para sortear las colmenas de silítidos. Apreciamos mucho lo que has hecho.', 0),
(@ID, 'esMX', '¡Excelente! Con Pinzamorten fuera del mapa, somos libres para utilizar las montañas del sur como camino estratégico para sortear las colmenas de silítidos. Apreciamos mucho lo que has hecho.', 0);
-- 8284 El misterio Crepuscular
-- https://es.wowhead.com/quest=8284
SET @ID := 8284;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedes encontrar el campamento asolado al noroeste de aquí. Vuelve a verme cuando tengas todos los fragmentos.', 0),
(@ID, 'esMX', 'Puedes encontrar el campamento asolado al noroeste de aquí. Vuelve a verme cuando tengas todos los fragmentos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Justo como sospechaba. Puedo descifrar palabras sueltas en las tablillas, pero parecen tener algún tipo de lógica o significado. Es bastante típico de las sectas del Martillo Crepuscular utilizar un código para ocultar el significado de sus textos. Tendremos que encontrar a alguien que sepa más de este tipo de cosas.', 0),
(@ID, 'esMX', 'Justo como sospechaba. Puedo descifrar palabras sueltas en las tablillas, pero parecen tener algún tipo de lógica o significado. Es bastante típico de las sectas del Martillo Crepuscular utilizar un código para ocultar el significado de sus textos. Tendremos que encontrar a alguien que sepa más de este tipo de cosas.', 0);
-- 8285 El desertor
-- https://es.wowhead.com/quest=8285
SET @ID := 8285;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tú! ¿Cómo me has encontrado? ¿Quién eres? No te han seguido, ¿verdad? ¡Habla!', 0),
(@ID, 'esMX', '¡Tú! ¿Cómo me has encontrado? ¿Quién eres? No te han seguido, ¿verdad? ¡Habla!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya veo que conoces mi vieja organización. Debes de estar con los del Fuerte Cenarion.$B$B¿Buscas información para usarla contra ellos? Acércate, quizás podamos ayudarnos mutuamente.', 0),
(@ID, 'esMX', 'Ya veo que conoces mi vieja organización. Debes de estar con los del Fuerte Cenarion.$B$B¿Buscas información para usarla contra ellos? Acércate, quizás podamos ayudarnos mutuamente.', 0);
-- 8286 Lo que nos depara el futuro
-- https://es.classic.wowhead.com/quest=8286
SET @ID := 8286;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha vuelto Anachronos?', 0),
(@ID, 'esMX', '¿Ha vuelto Anachronos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin ha vuelto. Ha terminado la espera.', 0),
(@ID, 'esMX', 'Por fin ha vuelto. Ha terminado la espera.', 0);
-- 8287 Un propósito terrible
-- https://es.wowhead.com/quest=8287
SET @ID := 8287;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto que me traes, $n?', 0),
(@ID, 'esMX', '¿Qué es esto que me traes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una información muy interesante, $n. Esto nos aclara algo la presencia del Martillo Crepuscular en Silithus y, sin duda, nos ayudará en la lucha contra ellos. Tus esfuerzos serán generosamente recompensados, $c.', 0),
(@ID, 'esMX', 'Una información muy interesante, $n. Esto nos aclara algo la presencia del Martillo Crepuscular en Silithus y, sin duda, nos ayudará en la lucha contra ellos. Tus esfuerzos serán generosamente recompensados, $c.', 0);
-- 8288 Solo uno puede alzarse
-- https://es.classic.wowhead.com/quest=8288
SET @ID := 8288;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es el favor del Linaje de Nozdormu lo que debes ganarte.', 0),
(@ID, 'esMX', 'Es el favor del Linaje de Nozdormu lo que debes ganarte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Podrías ser $gel primero:la primera; en ganar el favor entre el Vuelo de Bronce en mil años?', 0),
(@ID, 'esMX', '¿Podrías ser $gel primero:la primera; en ganar el favor entre el Vuelo de Bronce en mil años?', 0);
-- 8301 El camino del honrado
-- https://es.classic.wowhead.com/quest=8301
SET @ID := 8301;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienen motivos para desconfiar de las razas mortales; pero será mejor que el propio Linaje cuente esa historia cuando llegue el momento.', 0),
(@ID, 'esMX', 'Tienen motivos para desconfiar de las razas mortales; pero será mejor que el propio Linaje cuente esa historia cuando llegue el momento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Voy a darte la facultad de nombrar ayudantes para tu misión. $gUn campeón:Una campeona; necesita ayuda para cumplir con su deber.', 0),
(@ID, 'esMX', 'Voy a darte la facultad de nombrar ayudantes para tu misión. $gUn campeón:Una campeona; necesita ayuda para cumplir con su deber.', 0);
