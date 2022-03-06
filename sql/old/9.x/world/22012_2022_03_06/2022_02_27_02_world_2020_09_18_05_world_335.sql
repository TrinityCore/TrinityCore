-- 4512 Un largo camino para unas babosas
-- https://es.classic.wowhead.com/quest=4512
SET @ID := 4512;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Algunos de los experimentos que he realizado son fascinantes. Creo que con un poco más de trabajo, podré descubrir la naturaleza de estas criaturas y cómo influyen en el desarrollo de la vida en Azeroth ... si es que tienen algo que ver con eso para empezar.$B$BUna de mis teorías más grandes que no gusta mucho es la idea de que los mocos y los lodos están vinculados a la creación de este planeta... casi como si fueran una secreción de él.$B$BPero no puedo probarlo ni refutarlo hasta que obtenga más muestras.', 0),
(@ID, 'esMX', 'Algunos de los experimentos que he realizado son fascinantes. Creo que con un poco más de trabajo, podré descubrir la naturaleza de estas criaturas y cómo influyen en el desarrollo de la vida en Azeroth ... si es que tienen algo que ver con eso para empezar.$B$BUna de mis teorías más grandes que no gusta mucho es la idea de que los mocos y los lodos están vinculados a la creación de este planeta... casi como si fueran una secreción de él.$B$BPero no puedo probarlo ni refutarlo hasta que obtenga más muestras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Resultados asombrosos, $n! ¡Te acercaste lo suficiente para tomar una muestra de los mocos corruptos y te las arreglaste para no lucir peor por el desgaste! Gracias. Oh, estas muestras serán perfectas. No puedo esperar para comenzar a probarlos.$B$BSi estoy en lo cierto, ¡podría ser uno de los más grandes científicos de la Liga de Exploradores!$B$BEso demostrará a todos los enanos que no fue un error permitirnos entrar a los gnomos en Forjaz después del incidente de Gnomeregan.', 0),
(@ID, 'esMX', '¡Resultados asombrosos, $n! ¡Te acercaste lo suficiente para tomar una muestra de los mocos corruptos y te las arreglaste para no lucir peor por el desgaste! Gracias. Oh, estas muestras serán perfectas. No puedo esperar para comenzar a probarlos.$B$BSi estoy en lo cierto, ¡podría ser uno de los más grandes científicos de la Liga de Exploradores!$B$BEso demostrará a todos los enanos que no fue un error permitirnos entrar a los gnomos en Forjaz después del incidente de Gnomeregan.', 0);
-- 4513 Un largo camino para unas babosas
-- https://es.classic.wowhead.com/quest=4513
SET @ID := 4513;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay tanto que tener en cuenta. Pero ¿qué significa? ¿Y cómo afecta a las gentes de Azeroth?', 0),
(@ID, 'esMX', 'Hay tanto que tener en cuenta. Pero ¿qué significa? ¿Y cómo afecta a las gentes de Azeroth?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes la muestra? $n, vales tu peso en oro. Tu dedicación y tu ayuda han sido magníficas.$B$BAcepta esto en prueba de mi imperecedera gratitud. Ahora tengo cosas que hacer, pero si vienes más adelante tendré más trabajo para ti.$B$BGracias de todo corazón.', 0),
(@ID, 'esMX', '¿Me traes la muestra? $n, vales tu peso en oro. Tu dedicación y tu ayuda han sido magníficas.$B$BAcepta esto en prueba de mi imperecedera gratitud. Ahora tengo cosas que hacer, pero si vienes más adelante tendré más trabajo para ti.$B$BGracias de todo corazón.', 0);
-- 725 Advertir de la amenaza
-- https://es.classic.wowhead.com/quest=725
SET @ID := 725;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hmm? Sí, $c.', 0),
(@ID, 'esMX', '¿Hmm? Sí, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, una nota del historiador Karnik. Excelente.$B$BSiempre tengo tiempo para sus negocios.$B$B<El consejero Belgrum abre la nota y comienza a leer.>', 0),
(@ID, 'esMX', 'Ah, una nota del historiador Karnik. Excelente.$B$BSiempre tengo tiempo para sus negocios.$B$B<El consejero Belgrum abre la nota y comienza a leer.>', 0);
-- 726 Advertir de la amenaza
-- https://es.classic.wowhead.com/quest=726
SET @ID := 726;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estás tratando este asunto con la urgencia que esperaría del propio rey, $N.$B$BDe acuerdo entonces. Sé lo que hará caer a los Forjatinieblas.$B$BSu presencia en Uldaman puede ralentizarse si los atacamos en su base de operaciones: la Fortaleza de Angor.', 0),
(@ID, 'esMX', 'Estás tratando este asunto con la urgencia que esperaría del propio rey, $N.$B$BDe acuerdo entonces. Sé lo que hará caer a los Forjatinieblas.$B$BSu presencia en Uldaman puede ralentizarse si los atacamos en su base de operaciones: la Fortaleza de Angor.', 0);
-- 762 Un embajador del mal
-- https://es.classic.wowhead.com/quest=762
SET @ID := 762;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo es esencial, $n. Ragnaros no esperará a que nos preparemos.', 0),
(@ID, 'esMX', 'El tiempo es esencial, $n. Ragnaros no esperará a que nos preparemos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, tu dedicación a Forjaz y al pueblo enano no puede ser refutada. Te agradezco tu ayuda en este asunto.$B$BEnviaré un mensaje al historiador Karnik para informarle de que lo ha logrado y también haré que se envíe ayuda a las Tierras Inhóspitas lo antes posible para ayudar a recuperar el sitio de excavación. Gracias de nuevo.$B$BAntes de que te vayas, hay una cosa más que te pediría en nombre del Rey Barbabronce.', 0),
(@ID, 'esMX', '$n, tu dedicación a Forjaz y al pueblo enano no puede ser refutada. Te agradezco tu ayuda en este asunto.$B$BEnviaré un mensaje al historiador Karnik para informarle de que lo ha logrado y también haré que se envíe ayuda a las Tierras Inhóspitas lo antes posible para ayudar a recuperar el sitio de excavación. Gracias de nuevo.$B$BAntes de que te vayas, hay una cosa más que te pediría en nombre del Rey Barbabronce.', 0);
-- 1139 Las tablillas perdidas de Voluntad
-- https://es.classic.wowhead.com/quest=1139
SET @ID := 1139;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La búsqueda de Piemartillo debe continuar, $n. Le debo mucho.$B$BTu regreso a Uldaman es imperativo no solo para ese objetivo, sino también para la seguridad de todos los enanos. Con la tablilla en manos de los Forjatiniebla, quién sabe lo poderoso que se volvería su ejército de golems.', 0),
(@ID, 'esMX', 'La búsqueda de Piemartillo debe continuar, $n. Le debo mucho.$B$BTu regreso a Uldaman es imperativo no solo para ese objetivo, sino también para la seguridad de todos los enanos. Con la tablilla en manos de los Forjatiniebla, quién sabe lo poderoso que se volvería su ejército de golems.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El consejero Belgrum sacude la cabeza con incredulidad mientras le entregas el fragmento de piedra.>$B$B$n, esto es asombroso. Haré que se lo lleven a los magos del rey lo antes posible. Querrán estudiarlo para averiguar si las leyendas son ciertas. Pero esa es una discusión para otro momento: has ayudado a nuestra gente más de lo que hubiera esperado, gracias.', 0),
(@ID, 'esMX', '<El consejero Belgrum sacude la cabeza con incredulidad mientras le entregas el fragmento de piedra.>$B$B$n, esto es asombroso. Haré que se lo lleven a los magos del rey lo antes posible. Querrán estudiarlo para averiguar si las leyendas son ciertas. Pero esa es una discusión para otro momento: has ayudado a nuestra gente más de lo que hubiera esperado, gracias.', 0);
-- 1450 Maestro de grifos Garracha
-- https://es.classic.wowhead.com/quest=1450
SET @ID := 1450;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Por supuesto, recuerdo haber enviado a uno de mis jinetes de grifos para que le echara una mano a Brohann Barriliga.$B$BSiempre tuve una debilidad en mi corazón por la Liga de Exploradores. Mi padre ayudó con el equipo de excavación inicial que descubrió Uldaman.$B$BEnvié a quien pensé que era mi mejor jinete de grifos en ese momento con Brohann. Era un tipo llamado Rapsodio Machacacanillas.$B$B¡Y qué jinete de grifos era! Bueno hasta ...', 0),
(@ID, 'esMX', 'Ah, sí. Por supuesto, recuerdo haber enviado a uno de mis jinetes de grifos para que le echara una mano a Brohann Barriliga.$B$BSiempre tuve una debilidad en mi corazón por la Liga de Exploradores. Mi padre ayudó con el equipo de excavación inicial que descubrió Uldaman.$B$BEnvié a quien pensé que era mi mejor jinete de grifos en ese momento con Brohann. Era un tipo llamado Rapsodio Machacacanillas.$B$B¡Y qué jinete de grifos era! Bueno hasta ...', 0);
-- 1451 Rapsodio Machacacanillas
-- https://es.classic.wowhead.com/quest=1451
SET @ID := 1451;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip!$B$BTe estoy mirando y no paras de moverte. Tás mareándome. ¡Jo, jo!$B$B¡Hip!$B$B¡Guau! ¿Lo has sentido? La tierra se mueve, $gamigo:amiga;. Necesito una copa.$B$B¡Hip!', 0),
(@ID, 'esMX', '¡Hip!$B$BTe estoy mirando y no paras de moverte. Tás mareándome. ¡Jo, jo!$B$B¡Hip!$B$B¡Guau! ¿Lo has sentido? La tierra se mueve, $gamigo:amiga;. Necesito una copa.$B$B¡Hip!', 0);
-- 900 El churumbele
-- https://es.classic.wowhead.com/quest=900
SET @ID := 900;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pilotos parpadeantes en la consola de control indican que aún no se han cerrado las principales válvulas de control.', 0),
(@ID, 'esMX', 'Los pilotos parpadeantes en la consola de control indican que aún no se han cerrado las principales válvulas de control.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las luces de las tres válvulas de control se apagan al cortarlas. Las luces verdes se vuelven poco a poco amarillas y el interruptor que controla el aparato puede ahora extraerse con las válvulas cerradas; se puede apagar.', 0),
(@ID, 'esMX', 'Las luces de las tres válvulas de control se apagan al cortarlas. Las luces verdes se vuelven poco a poco amarillas y el interruptor que controla el aparato puede ahora extraerse con las válvulas cerradas; se puede apagar.', 0);
-- 901 El churumbele
-- https://es.classic.wowhead.com/quest=901
SET @ID := 901;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pilotos de la consola están atenuados y los diales están todos a cero, todo está parado.', 0),
(@ID, 'esMX', 'Los pilotos de la consola están atenuados y los diales están todos a cero, todo está parado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al girar la llave en la cerradura, la consola de control queda libre. Se apaga una luz roja en la parte superior de la consola y no queda corriente en el terminal.', 0),
(@ID, 'esMX', 'Al girar la llave en la cerradura, la consola de control queda libre. Se apaga una luz roja en la parte superior de la consola y no queda corriente en el terminal.', 0);
-- 902 El churumbele
-- https://es.classic.wowhead.com/quest=902
SET @ID := 902;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh, has vuelto, $n! ¿Tienes el churumbele?', 0),
(@ID, 'esMX', '¡Eh, has vuelto, $n! ¿Tienes el churumbele?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es… interesante, vaya. Me ocuparé de que lo envíen al puesto de mando del Gremio de Manitas de Villabajo. Estoy seguro de que después de desarmar el aparato con cuidado y estudiarlo, conseguiré entender cómo funciona.', 0),
(@ID, 'esMX', 'Esto es… interesante, vaya. Me ocuparé de que lo envíen al puesto de mando del Gremio de Manitas de Villabajo. Estoy seguro de que después de desarmar el aparato con cuidado y estudiarlo, conseguiré entender cómo funciona.', 0);
-- 4502 Actividad volcánica
-- https://es.classic.wowhead.com/quest=4502
SET @ID := 4502;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es cierto que el volcán de Un\'Goro está activo? Creo que podría aprender mucho de las cenizas, $n.', 0),
(@ID, 'esMX', '¿Es cierto que el volcán de Un\'Goro está activo? Creo que podría aprender mucho de las cenizas, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estas muestras son perfectas! ¡Gracias, $n! Te informaré con detalle de todo lo que averigüe.', 0),
(@ID, 'esMX', '¡Estas muestras son perfectas! ¡Gracias, $n! Te informaré con detalle de todo lo que averigüe.', 0);
-- 1091 Noticias para Kaela
-- https://es.classic.wowhead.com/quest=1091
SET @ID := 1091;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿En qué puedo ayudarte?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿En qué puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es muy interesante.$B$BGaxim y tú lo habéis hecho muy bien, $n. Gracias.', 0),
(@ID, 'esMX', 'Esto es muy interesante.$B$BGaxim y tú lo habéis hecho muy bien, $n. Gracias.', 0);
-- 1084 Los antárboles corruptos
-- https://es.classic.wowhead.com/quest=1084
SET @ID := 1084;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo el presentimiento de que Gaxim sabrá cómo utilizar la metralla sin tener en cuenta cómo la ha usado Ventura y Cía. en el pasado.', 0),
(@ID, 'esMX', 'Tengo el presentimiento de que Gaxim sabrá cómo utilizar la metralla sin tener en cuenta cómo la ha usado Ventura y Cía. en el pasado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n.$B$BEsto debería ser más que suficiente para que Gaxim descubra cómo fueron corrompidos los antárboles. Se lo daré ahora mismo.', 0),
(@ID, 'esMX', 'Gracias, $n.$B$BEsto debería ser más que suficiente para que Gaxim descubra cómo fueron corrompidos los antárboles. Se lo daré ahora mismo.', 0);
-- 1083 Los espíritus iracundos
-- https://es.classic.wowhead.com/quest=1083
SET @ID := 1083;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La primera vez que vi La Vega Carbonizada, casi lloro, $n.', 0),
(@ID, 'esMX', 'La primera vez que vi La Vega Carbonizada, casi lloro, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los restos de nuestro enemigo... tu fuerza nos hace un gran servicio, $n. Gracias.', 0),
(@ID, 'esMX', 'Los restos de nuestro enemigo... tu fuerza nos hace un gran servicio, $n. Gracias.', 0);
-- 1093 Súper Segadora 6000
-- https://es.classic.wowhead.com/quest=1093
SET @ID := 1093;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado esos planos? Quiero impresionar al nuevo jefe. Con suerte, cuando esté convencido de mi lealtad, bueno... todo lo que pueda estar convencido... El honor de los goblins y todo eso, ¿sabes? Pues eso, que cuando esté convencido, querrá utilizar mi impresionante genialidad.', 0),
(@ID, 'esMX', '¿Has encontrado esos planos? Quiero impresionar al nuevo jefe. Con suerte, cuando esté convencido de mi lealtad, bueno... todo lo que pueda estar convencido... El honor de los goblins y todo eso, ¿sabes? Pues eso, que cuando esté convencido, querrá utilizar mi impresionante genialidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eh, ¿es eso lo que creo que es? ¡Genial!$B$BVeamos. ¡Agh! ¿Cómo se supone que voy a entender esto...? No sé cómo piensan los gnomos. Te diré algo, me sorprende que consiguieran construir la rueda y mucho menos esas máquinas voladores que tanto les gustan.', 0),
(@ID, 'esMX', 'Eh, ¿es eso lo que creo que es? ¡Genial!$B$BVeamos. ¡Agh! ¿Cómo se supone que voy a entender esto...? No sé cómo piensan los gnomos. Te diré algo, me sorprende que consiguieran construir la rueda y mucho menos esas máquinas voladores que tanto les gustan.', 0);
-- 1094 Más instrucciones
-- https://es.classic.wowhead.com/quest=1094
SET @ID := 1094;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Cómo puedo ayudarte?', 0),
(@ID, 'esMX', '¡Hola! ¿Cómo puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fizziks, ¿eh? No es que confíe mucho en él, pero su información parece bastante fiable. ¿Qué no daría porque me quitaran de encima a Ventura y Cía.?$B$BAunque inventan buenas máquinas... No puedo negar que nos hemos beneficiado de algunos de los artefactos que han desarrollado.', 0),
(@ID, 'esMX', 'Fizziks, ¿eh? No es que confíe mucho en él, pero su información parece bastante fiable. ¿Qué no daría porque me quitaran de encima a Ventura y Cía.?$B$BAunque inventan buenas máquinas... No puedo negar que nos hemos beneficiado de algunos de los artefactos que han desarrollado.', 0);
-- 1095 Más instrucciones
-- https://es.classic.wowhead.com/quest=1095
SET @ID := 1095;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eliminar a Gerenzo? Vaya, esa es una idea a la que no me opondría.$B$BLos gnomos ya son bastante malos pero lo que sé sobre Gerenzo, no hace más que empeorar las cosas. Al parecer, era uno de los ingenieros jefe en Gnomeregan, donde trabajaba en un proyecto secreto; no logramos infiltrar a Dun Morogh para averiguar más detalles concretos. Fue un fracaso. Según nuestros informes, fuera lo que fuera, les explotó literalmente en la cara.', 0),
(@ID, 'esMX', '¿Eliminar a Gerenzo? Vaya, esa es una idea a la que no me opondría.$B$BLos gnomos ya son bastante malos pero lo que sé sobre Gerenzo, no hace más que empeorar las cosas. Al parecer, era uno de los ingenieros jefe en Gnomeregan, donde trabajaba en un proyecto secreto; no logramos infiltrar a Dun Morogh para averiguar más detalles concretos. Fue un fracaso. Según nuestros informes, fuera lo que fuera, les explotó literalmente en la cara.', 0);
-- 1096 Gerenzo Silbillave
-- https://es.classic.wowhead.com/quest=1096
SET @ID := 1096;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Petardol querrá alguna prueba de que Gerenzo está muerto. Creo que este brazo mecánico servirá.', 0),
(@ID, 'esMX', 'Petardol querrá alguna prueba de que Gerenzo está muerto. Creo que este brazo mecánico servirá.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mira eso... se necesita un gnomo para inventarse algo así. No puedo comprender por qué alguien querría cortarse un brazo y reemplazarlo con eso cuando puedes quedarte con ambos brazos y añadir un tercero.$B$B¡Gnomos!...$B$BAl menos Gerenzo ha pasado a la historia. Esperemos que eso sea suficiente para demostrarlo y que Petardol me asigne a uno de los talleres del Gremio de Manitas en Gadgetzan o quizás incluso en Villabajo.', 0),
(@ID, 'esMX', 'Mira eso... se necesita un gnomo para inventarse algo así. No puedo comprender por qué alguien querría cortarse un brazo y reemplazarlo con eso cuando puedes quedarte con ambos brazos y añadir un tercero.$B$B¡Gnomos!...$B$BAl menos Gerenzo ha pasado a la historia. Esperemos que eso sea suficiente para demostrarlo y que Petardol me asigne a uno de los talleres del Gremio de Manitas en Gadgetzan o quizás incluso en Villabajo.', 0);
-- 1082 Noticias para Centinela Thenysil
-- https://es.classic.wowhead.com/quest=1082
SET @ID := 1082;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Has hecho un gran servicio a las Centinelas.$B$BMe alegro mucho de ver que Kaela... e incluso Gaxim, están bien.$B$BTe has ganado nuestro aprecio.', 0),
(@ID, 'esMX', 'Gracias, $n. Has hecho un gran servicio a las Centinelas.$B$BMe alegro mucho de ver que Kaela... e incluso Gaxim, están bien.$B$BTe has ganado nuestro aprecio.', 0);
-- 1081 El recibimiento de Tyrande
-- https://es.classic.wowhead.com/quest=1081
SET @ID := 1081;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. He oído tu nombre y, aunque sigues siendo muy joven, me alegra ver el camino que has decidido seguir.$B$BMe harías un gran honor si quisieras aceptar esto como muestra de aprecio.', 0),
(@ID, 'esMX', 'Hola, $n. He oído tu nombre y, aunque sigues siendo muy joven, me alegra ver el camino que has decidido seguir.$B$BMe harías un gran honor si quisieras aceptar esto como muestra de aprecio.', 0);
