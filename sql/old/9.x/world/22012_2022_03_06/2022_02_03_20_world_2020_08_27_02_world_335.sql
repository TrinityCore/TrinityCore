-- 1085 Estar de guardia en Espolón
-- https://es.classic.wowhead.com/quest=1085
SET @ID := 1085;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Traicionera... traicionera y peligrosa, así es esta tierra.$B$BPero estoy aquí para demostrar a los elfos de la noche que todo va un poco mejor con la ayuda de la vieja ingeniería de toda la vida y una pizca de magia.$B$BVeamos, jurar dejar la magia completamente no ayudará a los elfos de la noche... la necesitan. El mundo la necesita. Y, con la ingeniería y la alquimia, nunca te puedes equivocar. Las posibilidades son infinitas.', 0),
(@ID, 'esMX', 'Traicionera... traicionera y peligrosa, así es esta tierra.$B$BPero estoy aquí para demostrar a los elfos de la noche que todo va un poco mejor con la ayuda de la vieja ingeniería de toda la vida y una pizca de magia.$B$BVeamos, jurar dejar la magia completamente no ayudará a los elfos de la noche... la necesitan. El mundo la necesita. Y, con la ingeniería y la alquimia, nunca te puedes equivocar. Las posibilidades son infinitas.', 0);
-- 1071 Una tregua para el gnomo
-- https://es.classic.wowhead.com/quest=1071
SET @ID := 1071;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va el final de la batalla, $n?', 0),
(@ID, 'esMX', '¿Cómo va el final de la batalla, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchísimas gracias por tu ayuda, $n. Vuelves justo a tiempo.$B$BCreo que tengo el plan perfecto... explosivos. No, ese no es el plan, pero es parte del plan.$B$BVerás, para asustar a los goblins, he estado utilizando explosivos muy potentes, no te preocupes, no son tan peligrosos como piensa todo el mundo. Puedo llevarles de un lado para otro como si fueran ganado con unas cuántas detonaciones en los lados de la montaña, pero llevo unos días con falta de suministros...', 0),
(@ID, 'esMX', 'Muchísimas gracias por tu ayuda, $n. Vuelves justo a tiempo.$B$BCreo que tengo el plan perfecto... explosivos. No, ese no es el plan, pero es parte del plan.$B$BVerás, para asustar a los goblins, he estado utilizando explosivos muy potentes, no te preocupes, no son tan peligrosos como piensa todo el mundo. Puedo llevarles de un lado para otro como si fueran ganado con unas cuántas detonaciones en los lados de la montaña, pero llevo unos días con falta de suministros...', 0);
-- 1072 Un viejo colega
-- https://es.classic.wowhead.com/quest=1072
SET @ID := 1072;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahhh... ¿Te envía Gaxim, eh? ¿Cómo sé que no me estás mintiendo? ¿Mm? ¿Mmm...?', 0),
(@ID, 'esMX', 'Ahhh... ¿Te envía Gaxim, eh? ¿Cómo sé que no me estás mintiendo? ¿Mm? ¿Mmm...?', 0);
-- 1073 Ineptitud + Productos químicos = Diversión
-- https://es.classic.wowhead.com/quest=1073
SET @ID := 1073;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo hacerte el nitromirgliceronio si no tengo las pociones... son vitales para crearlo.', 0),
(@ID, 'esMX', 'No puedo hacerte el nitromirgliceronio si no tengo las pociones... son vitales para crearlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto servirá.$B$BSi no supiera que no es así, diría que tienes conocimientos de alquimia. Bien, bien... el mundo no gira solo con espadas y magia, ¿sabes?', 0),
(@ID, 'esMX', 'Esto servirá.$B$BSi no supiera que no es así, diría que tienes conocimientos de alquimia. Bien, bien... el mundo no gira solo con espadas y magia, ¿sabes?', 0);
-- 1074 Ineptitud + Productos químicos = Diversión
-- https://es.classic.wowhead.com/quest=1074
SET @ID := 1074;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡qué bien! Ya has vuelto.', 0),
(@ID, 'esMX', 'Ah, ¡qué bien! Ya has vuelto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has completado tu tarea sin problemas, $n.$B$BEl NG-5 es el componente inequívoco de la receta para hacer explotar los carros de dinamita.$B$B¿Qué? Sí, dinamita... carros llenos de dinamita. Es la distracción perfecta, te lo digo yo... espera y verás.', 0),
(@ID, 'esMX', 'Has completado tu tarea sin problemas, $n.$B$BEl NG-5 es el componente inequívoco de la receta para hacer explotar los carros de dinamita.$B$B¿Qué? Sí, dinamita... carros llenos de dinamita. Es la distracción perfecta, te lo digo yo... espera y verás.', 0);
-- 1075 Un pergamino de Mauren
-- https://es.classic.wowhead.com/quest=1075
SET @ID := 1075;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, este hechizo que necesitas... que te permita detonar explosivos a distancia... mmm.', 0),
(@ID, 'esMX', 'Bien, este hechizo que necesitas... que te permita detonar explosivos a distancia... mmm.', 0);
-- 1076 Demonios en los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=1076
SET @ID := 1076;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has encontrado el componente que necesito?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has encontrado el componente que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dame unos minutos y tendré el pergamino listo.', 0),
(@ID, 'esMX', 'Dame unos minutos y tendré el pergamino listo.', 0);
-- 1077 Entrega especial para Gaxim
-- https://es.classic.wowhead.com/quest=1077
SET @ID := 1077;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja! ¡Has vuelto! ¿Lo tienes? ¿Tienes el hechizo?', 0),
(@ID, 'esMX', '¡Ja, ja! ¡Has vuelto! ¿Lo tienes? ¿Tienes el hechizo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso, $n! Bien hecho.$B$BEste conjuro, mezclado con el NG-5, debería lograr el explosivo remoto perfecto.$B$BPodremos crear una distracción fantástica para que puedas colarte y robar las cartas y los planos de ingeniería de Ventura y Cía.$B$BSeguro que eso paraliza de alguna forma sus acciones de deforestación.', 0),
(@ID, 'esMX', '¡Maravilloso, $n! Bien hecho.$B$BEste conjuro, mezclado con el NG-5, debería lograr el explosivo remoto perfecto.$B$BPodremos crear una distracción fantástica para que puedas colarte y robar las cartas y los planos de ingeniería de Ventura y Cía.$B$BSeguro que eso paraliza de alguna forma sus acciones de deforestación.', 0);
-- 1079 Operaciones secretas: plan A
-- https://es.classic.wowhead.com/quest=1079
SET @ID := 1079;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los planos, $n?', 0),
(@ID, 'esMX', '¿Has conseguido los planos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Un gran golpe para Ventura y Cía.$B$BPodremos encontrar los puntos débiles de sus máquinas e incorporar sus diseños a nuestras propias creaciones. ¡Este es un gran día!', 0),
(@ID, 'esMX', '¡Increíble! Un gran golpe para Ventura y Cía.$B$BPodremos encontrar los puntos débiles de sus máquinas e incorporar sus diseños a nuestras propias creaciones. ¡Este es un gran día!', 0);
-- 1080 Operaciones secretas: plan B
-- https://es.classic.wowhead.com/quest=1080
SET @ID := 1080;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal fue todo, $n?', 0),
(@ID, 'esMX', '¿Qué tal fue todo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble, $n! Kaela y las Centinelas estarán encantadas. Con tu habilidad y mis creaciones, somos imparables.', 0),
(@ID, 'esMX', '¡Increíble, $n! Kaela y las Centinelas estarán encantadas. Con tu habilidad y mis creaciones, somos imparables.', 0);
-- 1057 La reconquista de La Vega Carbonizada
-- https://es.classic.wowhead.com/quest=1057
SET @ID := 1057;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay mucho trabajo por hacer antes de poder restaurar la gloria que, antiguamente, reinaba en La Vega Carbonizada.$B$B¡Elimina esas amenazas de la zona, $n! Solo entonces podremos reclamar lo que le pertenece a la naturaleza.', 0),
(@ID, 'esMX', 'Hay mucho trabajo por hacer antes de poder restaurar la gloria que, antiguamente, reinaba en La Vega Carbonizada.$B$B¡Elimina esas amenazas de la zona, $n! Solo entonces podremos reclamar lo que le pertenece a la naturaleza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que los Furia Sangrienta han sufrido una pérdida tan grande, quizás pueda comenzar el verdadero trabajo de restauración...', 0),
(@ID, 'esMX', 'Ahora que los Furia Sangrienta han sufrido una pérdida tan grande, quizás pueda comenzar el verdadero trabajo de restauración...', 0);
-- 1059 La reconquista de La Vega Carbonizada
-- https://es.classic.wowhead.com/quest=1059
SET @ID := 1059;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El vigilante Albagorm demostró inteligencia al enviarte con tanta urgencia.$B$BVeamos si conseguimos invocar ayuda del gran bosque para viajar a La Vega Carbonizada antes de que sea demasiado tarde.', 0),
(@ID, 'esMX', 'El vigilante Albagorm demostró inteligencia al enviarte con tanta urgencia.$B$BVeamos si conseguimos invocar ayuda del gran bosque para viajar a La Vega Carbonizada antes de que sea demasiado tarde.', 0);
-- 1437 Buscando para Vahlarriel
-- https://es.classic.wowhead.com/quest=1437
SET @ID := 1437;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando examinas los restos del carro, te das cuenta de que fue atacado tanto por hechizos como por armas. Parece que el ataque llegó por un flanco y que fue rápido; no hay restos de sangre y tampoco cuerpos.$B$BQuienquiera que atacara el carro era eficiente y rápido.', 0),
(@ID, 'esMX', 'Cuando examinas los restos del carro, te das cuenta de que fue atacado tanto por hechizos como por armas. Parece que el ataque llegó por un flanco y que fue rápido; no hay restos de sangre y tampoco cuerpos.$B$BQuienquiera que atacara el carro era eficiente y rápido.', 0);
-- 1465 Buscando para Vahlarriel
-- https://es.classic.wowhead.com/quest=1465
SET @ID := 1465;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es exasperante! ¡Todo este asunto!$B$BLos dos fueron advertidos de lo peligroso que sería venir aquí. Y ahora han desaparecido... o algo peor.$B$B¿Dices que viste huellas que se dirigían a un fuerte cercano? Esa es nuestra mejor apuesta.$B$BPor lo que dicen los habitantes de la zona, esa fortaleza está infestada de miembros del Filo Ardiente. Orcos. Orcos que se han consagrado a la causa demoníaca. No representan la mayoría de las creencias de la Horda, pero son malvados y, si te pillan husmeando por allí, te matarán en cuanto te vean.', 0),
(@ID, 'esMX', '¡Esto es exasperante! ¡Todo este asunto!$B$BLos dos fueron advertidos de lo peligroso que sería venir aquí. Y ahora han desaparecido... o algo peor.$B$B¿Dices que viste huellas que se dirigían a un fuerte cercano? Esa es nuestra mejor apuesta.$B$BPor lo que dicen los habitantes de la zona, esa fortaleza está infestada de miembros del Filo Ardiente. Orcos. Orcos que se han consagrado a la causa demoníaca. No representan la mayoría de las creencias de la Horda, pero son malvados y, si te pillan husmeando por allí, te matarán en cuanto te vean.', 0);
-- 1438 Buscando para Vahlarriel
-- https://es.classic.wowhead.com/quest=1438
SET @ID := 1438;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a Elune, por fin alguien ha venido en mi ayuda. Te lo ruego, $c, tienes que ayudarme. Mi hermano Tyranis y yo fuimos capturados y traídos hasta aquí por el Filo Ardiente. ¡Creo que quieren ofrecerme como sacrificio a sus demonios!$B$BSabía que venir a Desolace era un error, pero Tyranis... últimamente ha desarrollado un ferviente interés por todo lo arcano, incluso contra la voluntad de nuestra gente. Decidió emprender este camino, a pesar de haber oído historias de los demonios que infestan estas tierras.$B$BNo sé cómo está pero... temo lo peor.', 0),
(@ID, 'esMX', 'Gracias a Elune, por fin alguien ha venido en mi ayuda. Te lo ruego, $c, tienes que ayudarme. Mi hermano Tyranis y yo fuimos capturados y traídos hasta aquí por el Filo Ardiente. ¡Creo que quieren ofrecerme como sacrificio a sus demonios!$B$BSabía que venir a Desolace era un error, pero Tyranis... últimamente ha desarrollado un ferviente interés por todo lo arcano, incluso contra la voluntad de nuestra gente. Decidió emprender este camino, a pesar de haber oído historias de los demonios que infestan estas tierras.$B$BNo sé cómo está pero... temo lo peor.', 0);
-- 1439 Buscando a Tyranis
-- https://es.classic.wowhead.com/quest=1439
SET @ID := 1439;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Temo que Tyranis intente desvelar los secretos del Filo Ardiente y unirse a ellos si lo permiten... Siempre ha ansiado el poder mágico que proporciona a quienes se acercan a ellos.$B$BNo sé si tengo el valor para volver a casa con la noticia de que el espíritu de Tyranis está flirteando con tales peligros. Entre mi gente, ya es bastante terrible perseguir tales cosas... y convertirse en aquello de lo que intentamos protegernos... es... mucho peor.', 0),
(@ID, 'esMX', 'Temo que Tyranis intente desvelar los secretos del Filo Ardiente y unirse a ellos si lo permiten... Siempre ha ansiado el poder mágico que proporciona a quienes se acercan a ellos.$B$BNo sé si tengo el valor para volver a casa con la noticia de que el espíritu de Tyranis está flirteando con tales peligros. Entre mi gente, ya es bastante terrible perseguir tales cosas... y convertirse en aquello de lo que intentamos protegernos... es... mucho peor.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es terrible! Pero supongo que era necesario. Si no lo hubieras hecho tú, seguramente mi gente habría intervenido. Supongo que debería darte las gracias... perdóname si no parezco muy sincera. No es mi intención ofenderte.$B$BAhora que sé qué suerte corrió mi hermano, parece que ha llegado el momento de que huya. Si aún sigue en pie tu ofrecimiento, aceptaré tu ayuda para escapar de este horrible lugar.$B$BCuando estés $glisto:lista;, podemos emprender nuestro camino hacia la salvación.', 0),
(@ID, 'esMX', '¡Esto es terrible! Pero supongo que era necesario. Si no lo hubieras hecho tú, seguramente mi gente habría intervenido. Supongo que debería darte las gracias... perdóname si no parezco muy sincera. No es mi intención ofenderte.$B$BAhora que sé qué suerte corrió mi hermano, parece que ha llegado el momento de que huya. Si aún sigue en pie tu ofrecimiento, aceptaré tu ayuda para escapar de este horrible lugar.$B$BCuando estés $glisto:lista;, podemos emprender nuestro camino hacia la salvación.', 0);
-- 1382 Extraña alianza
-- https://es.classic.wowhead.com/quest=1382
SET @ID := 1382;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Largo de aquí! Los Gelkis no te quieren aquí. ¡¡Márchate!!$B$BVuelve cuando hayas matado a muchos Magram. Entonces hablaré contigo.', 0),
(@ID, 'esMX', '¡Largo de aquí! Los Gelkis no te quieren aquí. ¡¡Márchate!!$B$BVuelve cuando hayas matado a muchos Magram. Entonces hablaré contigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu nombre se susurra entre los Gelkis. Tienes mucha sangre Magram en las manos. Y eso está bien.$B$BTambién estará bien que hablemos. Hablemos de qué puedes hacer por los Gelkis y de qué podemos hacer nosotros por ti.', 0),
(@ID, 'esMX', 'Tu nombre se susurra entre los Gelkis. Tienes mucha sangre Magram en las manos. Y eso está bien.$B$BTambién estará bien que hablemos. Hablemos de qué puedes hacer por los Gelkis y de qué podemos hacer nosotros por ti.', 0);
-- 1368 La alianza con los Gelkis
-- https://es.classic.wowhead.com/quest=1368
SET @ID := 1368;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus dos pies pisan la tierra de Gelkis. ¡Tu no eres bienvenido aqui!$B$BDemuestra que buscas amistad con los Gelkis. Mata al centauro Magram. Regresa cuando el suelo esté mojado con sangre Magram.', 0),
(@ID, 'esMX', 'Tus dos pies pisan la tierra de Gelkis. ¡Tu no eres bienvenido aqui!$B$BDemuestra que buscas amistad con los Gelkis. Mata al centauro Magram. Regresa cuando el suelo esté mojado con sangre Magram.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tierra me habla. Y me dice que has matado muchos Magram. Y eso está bien.$B$BSi eres $gamigo:amiga; de los Gelkis, escucha. Tengo dos misiones más para ti.', 0),
(@ID, 'esMX', 'La tierra me habla. Y me dice que has matado muchos Magram. Y eso está bien.$B$BSi eres $gamigo:amiga; de los Gelkis, escucha. Tengo dos misiones más para ti.', 0);
-- 1384 Asalta a los Kolkar
-- https://es.classic.wowhead.com/quest=1384
SET @ID := 1384;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los talismanes? ¿Demostraste a los Kolkar que son débiles?', 0),
(@ID, 'esMX', '¿Tienes los talismanes? ¿Demostraste a los Kolkar que son débiles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho una buena cosa para los Gelkis. Los Kolkar son débiles y morirán. Su magia es patética; no les salvará. ¡Les enseñaste esto y su miedo los hará aún más débiles!$B$BY en nuestras tierras... los débiles mueren pronto.', 0),
(@ID, 'esMX', 'Has hecho una buena cosa para los Gelkis. Los Kolkar son débiles y morirán. Su magia es patética; no les salvará. ¡Les enseñaste esto y su miedo los hará aún más débiles!$B$BY en nuestras tierras... los débiles mueren pronto.', 0);
-- 1370 ¡A robar provisiones!
-- https://es.classic.wowhead.com/quest=1370
SET @ID := 1370;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vuelve cuando hayas demostrado a los Gelkis tu valía!', 0),
(@ID, 'esMX', '¡Vuelve cuando hayas demostrado a los Gelkis tu valía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien. ¡Ya estoy oyendo cómo les rugen las tripas a esos Magram!$B$BDaré esta carne a los Gelkis. Podremos combatir sin descanso muchos días.$B$BLo que has hecho es bueno para los Gelkis, $n.', 0),
(@ID, 'esMX', 'Bien. ¡Ya estoy oyendo cómo les rugen las tripas a esos Magram!$B$BDaré esta carne a los Gelkis. Podremos combatir sin descanso muchos días.$B$BLo que has hecho es bueno para los Gelkis, $n.', 0);
-- 1373 Ongeku
-- https://es.classic.wowhead.com/quest=1373
SET @ID := 1373;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0),
(@ID, 'esMX', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este es el fragmento del que susurró la tierra. ¡Puedo sentir una magia fuerte en él! Usaré esta magia contra los enemigos de los Gelkis.$B$BHas hecho una tarea más por nosotros, $n. Quizás pronto te llamemos amigo', 0),
(@ID, 'esMX', 'Sí, este es el fragmento del que susurró la tierra. ¡Puedo sentir una magia fuerte en él! Usaré esta magia contra los enemigos de los Gelkis.$B$BHas hecho una tarea más por nosotros, $n. Quizás pronto te llamemos amigo', 0);
-- 1374 Khan Jehn
-- https://es.classic.wowhead.com/quest=1374
SET @ID := 1374;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0),
(@ID, 'esMX', 'Muéstrame que eres $gamigo:amiga; de los Gelkis, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Khan Jehn era fuerte, pero estúpido. Pensó que su propia fuerza era grandiosa. No vio que la magia de la tierra es más fuerte. El centauro Magram ahora caerá sin su líder, ¡y los Gelkis gobernarán algún día!', 0),
(@ID, 'esMX', 'Khan Jehn era fuerte, pero estúpido. Pensó que su propia fuerza era grandiosa. No vio que la magia de la tierra es más fuerte. El centauro Magram ahora caerá sin su líder, ¡y los Gelkis gobernarán algún día!', 0);
