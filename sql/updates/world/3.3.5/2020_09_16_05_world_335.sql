-- 709 La solución a la maldición
-- https://es.classic.wowhead.com/quest=709
SET @ID := 709;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la tablilla? ¡Debe de contener secretos! ¡Secretos para salvarnos!', 0),
(@ID, 'esMX', '¿Has encontrado la tablilla? ¡Debe de contener secretos! ¡Secretos para salvarnos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, la suerte está de nuestra parte! ¡Gracias! ¡Puede que aún nos salvemos!', 0),
(@ID, 'esMX', '¡Oh, la suerte está de nuestra parte! ¡Gracias! ¡Puede que aún nos salvemos!', 0);
-- 1137 Noticias para Fizzle
-- https://es.classic.wowhead.com/quest=1137
SET @ID := 1137;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡has vuelto! ¿Encontraste a Martek? ¿Hablaste con él? ¿Y qué dijo? ¿¿Puede ayudarme??$B$B¡Cuéntamelo todo!', 0),
(@ID, 'esMX', '$n, ¡has vuelto! ¿Encontraste a Martek? ¿Hablaste con él? ¿Y qué dijo? ¿¿Puede ayudarme??$B$B¡Cuéntamelo todo!', 0);
-- 727 Ir a Forjaz a buscar el "Compendio" de Yagyin
-- https://es.classic.wowhead.com/quest=727
SET @ID := 727;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. Bienvenido a mi tienda pero ojo con lo que tocas.$B$BEl conocimiento puede ser mortal.', 0),
(@ID, 'esMX', 'Hola. Bienvenido a mi tienda pero ojo con lo que tocas.$B$BEl conocimiento puede ser mortal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh. Saludos, hermano.$B$BY alabados sean los moradores del subsuelo.', 0),
(@ID, 'esMX', 'Oh. Saludos, hermano.$B$BY alabados sean los moradores del subsuelo.', 0);
-- 720 Un signo de esperanza
-- https://es.classic.wowhead.com/quest=720
SET @ID := 720;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Piemartillo está vivo?! ¡Increíble, $n!', 0),
(@ID, 'esMX', '¡¿Piemartillo está vivo?! ¡Increíble, $n!', 0);
-- 721 Un signo de esperanza
-- https://es.classic.wowhead.com/quest=721
SET @ID := 721;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? Lo siento... <tose> Estoy muy débil. ¿Puedes acercarte, $c?$B$B¿Así que t’envía Ryedol? Que los hados bendigan a Muradin, ese chico no es tan lento del tarro como pensaba.', 0),
(@ID, 'esMX', '¿Sí? Lo siento... <tose> Estoy muy débil. ¿Puedes acercarte, $c?$B$B¿Así que t’envía Ryedol? Que los hados bendigan a Muradin, ese chico no es tan lento del tarro como pensaba.', 0);
-- 719 Un enano y sus herramientas
-- https://es.classic.wowhead.com/quest=719
SET @ID := 719;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía no sé con seguridad qué buscaban los Forjatiniebla pero desde luego tenían un propósito.', 0),
(@ID, 'esMX', 'Todavía no sé con seguridad qué buscaban los Forjatiniebla pero desde luego tenían un propósito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres mi salvador, $c. Me alegro de que alguien le haya dado una lección a esos Forjatiniebla. Gracias por tu ayuda.', 0),
(@ID, 'esMX', 'Eres mi salvador, $c. Me alegro de que alguien le haya dado una lección a esos Forjatiniebla. Gracias por tu ayuda.', 0);
-- 718 Espejismos
-- https://es.classic.wowhead.com/quest=718
SET @ID := 718;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El desierto es mal lugar para tener hambre, amigo, te lo digo yo.$B$BEh... ¿qué es eso de ahí?...', 0),
(@ID, 'esMX', 'El desierto es mal lugar para tener hambre, amigo, te lo digo yo.$B$BEh... ¿qué es eso de ahí?...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Mientras no estabas, yo... estooo... tragué un puñado de arena. Me...$B$BBah, no importa, saldremos esta noche y conseguiremos algo de comida. ¡Comeremos como reyes!', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Mientras no estabas, yo... estooo... tragué un puñado de arena. Me...$B$BBah, no importa, saldremos esta noche y conseguiremos algo de comida. ¡Comeremos como reyes!', 0);
-- 706 Encantamientos Llamarada ígnea
-- https://es.classic.wowhead.com/quest=706
SET @ID := 706;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $c?', 0),
(@ID, 'esMX', '¿Cómo va la caza, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, desde luego, ¡esto vendrá de perlas! ¡Esto hará que al atacar tus armas despidan un calor abrasador!', 0),
(@ID, 'esMX', 'Ah, desde luego, ¡esto vendrá de perlas! ¡Esto hará que al atacar tus armas despidan un calor abrasador!', 0);
-- 3789 Ayuda al archidruida Corzocelada
-- https://es.classic.wowhead.com/quest=3789
SET @ID := 3789;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que te has apresurado a venir al saber que yo dirijo el proyecto, $c.$B$BEscúchame con atención; no tengo ganas de repetir las cosas.', 0),
(@ID, 'esMX', 'Me alegra ver que te has apresurado a venir al saber que yo dirijo el proyecto, $c.$B$BEscúchame con atención; no tengo ganas de repetir las cosas.', 0);
-- 48 Dulce ámbar
-- https://es.classic.wowhead.com/quest=48
SET @ID := 48;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo! ¿Quieres otra?$B$BAllá en el Sur donde las zarzas irritan$BHay una fuente de aguas umbrías$BPura como la sagrada Hija de la Luz$BAgua sagrada de manantial me traerás tú.', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo! ¿Quieres otra?$B$BAllá en el Sur donde las zarzas irritan$BHay una fuente de aguas umbrías$BPura como la sagrada Hija de la Luz$BAgua sagrada de manantial me traerás tú.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hip! ¡Jo jo!', 0),
(@ID, 'esMX', '¡Hip! ¡Jo jo!', 0);
-- 1181 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1181
SET @ID := 1181;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, por supuesto que sabes lo que estás diciendo. Pero no, no te puedo ayudar. Algunos de mis hombres tenían que rastrear los planos de regulador de combustible, pero volvieron con las manos vacías.', 0),
(@ID, 'esMX', 'Oh, por supuesto que sabes lo que estás diciendo. Pero no, no te puedo ayudar. Algunos de mis hombres tenían que rastrear los planos de regulador de combustible, pero volvieron con las manos vacías.', 0);
-- 1182 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1182
SET @ID := 1182;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por mucho que odie admitirlo, ese equipo gnomo que tienen ahí fuera es bastante bueno. Nuestros chicos necesitan toda la ayuda que puedan conseguir.', 0),
(@ID, 'esMX', 'Por mucho que odie admitirlo, ese equipo gnomo que tienen ahí fuera es bastante bueno. Nuestros chicos necesitan toda la ayuda que puedan conseguir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deja que haga una copia de esos planos para tenerlos en mis notas y se los puedes llevar directamente a Pozzik. No quiero que crea que uno de sus mecenas le ha abandonado.', 0),
(@ID, 'esMX', 'Deja que haga una copia de esos planos para tenerlos en mis notas y se los puedes llevar directamente a Pozzik. No quiero que crea que uno de sus mecenas le ha abandonado.', 0);
-- 1183 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1183
SET @ID := 1183;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Has conseguido encontrar el regulador de combustible?', 0),
(@ID, 'esMX', '¡$n! ¿Has conseguido encontrar el regulador de combustible?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperaba que ya estuviera listo, pero esto presenta la oportunidad perfecta de mejorar el diseño original. Gracias, $n. Creo que podré preparar unos esquemas mejorados , construir esta cosa e instalarla rápidamente.', 0),
(@ID, 'esMX', 'Esperaba que ya estuviera listo, pero esto presenta la oportunidad perfecta de mejorar el diseño original. Gracias, $n. Creo que podré preparar unos esquemas mejorados , construir esta cosa e instalarla rápidamente.', 0);
-- 2198 El collar hecho añicos
-- https://es.classic.wowhead.com/quest=2198
SET @ID := 2198;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te has equivocado de gnomo, amigo! ¡Yo nunca he estado allí! ¡No puedes probar nada!$B$BEspera un momento... ¿quién eres? ¿Pero qué...? ¿Dónde encontraste este collar?', 0),
(@ID, 'esMX', '¡Te has equivocado de gnomo, amigo! ¡Yo nunca he estado allí! ¡No puedes probar nada!$B$BEspera un momento... ¿quién eres? ¿Pero qué...? ¿Dónde encontraste este collar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... Yo soy el joyero que ha hecho el collar pero no soy de los que dan información a cambio de nada. La información se paga, amigo. Si quieres que te ayuda, primero has de ayudarme tú a MÍ.', 0),
(@ID, 'esMX', 'Sí... Yo soy el joyero que ha hecho el collar pero no soy de los que dan información a cambio de nada. La información se paga, amigo. Si quieres que te ayuda, primero has de ayudarme tú a MÍ.', 0);
-- 722 El amuleto de los secretos
-- https://es.classic.wowhead.com/quest=722
SET @ID := 722;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El clan Forjatiniebla... <tose> es peligroso. Ten cuidado. <tose> Debes encontrar el amuleto.', 0),
(@ID, 'esMX', 'El clan Forjatiniebla... <tose> es peligroso. Ten cuidado. <tose> Debes encontrar el amuleto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Decir ah! <tose tose>$B$BSabía que me encontrarías el amuleto, $n.$B$BMuy bien hecho, $n. <tose>', 0),
(@ID, 'esMX', '¡Decir ah! <tose tose>$B$BSabía que me encontrarías el amuleto, $n.$B$BMuy bien hecho, $n. <tose>', 0);
-- 723 Tener fe en el porvenir
-- https://es.classic.wowhead.com/quest=723
SET @ID := 723;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Diría que ha sido un mal día pero estamos en las Tierras Inhóspitas: cualquier día es malo.', 0),
(@ID, 'esMX', 'Diría que ha sido un mal día pero estamos en las Tierras Inhóspitas: cualquier día es malo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El amuleto de Piemartillo? Creo que me encontraba más animado cuando creía que estaba muerto. Saberlo con seguridad solo aumenta el dolor. Este amuleto era el trabajo de su vida. No permitiré que haya muerto en vano.', 0),
(@ID, 'esMX', '¿El amuleto de Piemartillo? Creo que me encontraba más animado cuando creía que estaba muerto. Saberlo con seguridad solo aumenta el dolor. Este amuleto era el trabajo de su vida. No permitiré que haya muerto en vano.', 0);
-- 735 La Estrella, la Mano y el Corazón
-- https://es.classic.wowhead.com/quest=735
SET @ID := 735;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes los objetos que te pedí?', 0),
(@ID, 'esMX', '¿Traes los objetos que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes muchos recursos, $c. Si eres tú quien debe encargarse de la continuidad de nuestra orden, no dudo en que lo harás magníficamente.', 0),
(@ID, 'esMX', 'Tienes muchos recursos, $c. Si eres tú quien debe encargarse de la continuidad de nuestra orden, no dudo en que lo harás magníficamente.', 0);
-- 737 El saber prohibido
-- https://es.classic.wowhead.com/quest=737
SET @ID := 737;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! Hace mucho que te habías marchado. ¿Has conseguido la revista?', 0),
(@ID, 'esMX', '¡Ja! Hace mucho que te habías marchado. ¿Has conseguido la revista?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La tienes! ¡Oh, rayo de esperanza!$B$BPuede que tus esfuerzos sean nuestra salvación, $n. ¡Un monumento habrían de erigirte! ¡Un altar a ti dedicado! ¡Alabado sea tu nombre hasta que tus nietos tengan nietos!$B$BA menos que...ELLOS se liberen y vuelvan a la superficie. Si eso ocurriera, entonces puedes olvidarte de los hijos.$B$BSi ELLOS quedan libres, todos seremos alimento de gusanos.', 0),
(@ID, 'esMX', '¡La tienes! ¡Oh, rayo de esperanza!$B$BPuede que tus esfuerzos sean nuestra salvación, $n. ¡Un monumento habrían de erigirte! ¡Un altar a ti dedicado! ¡Alabado sea tu nombre hasta que tus nietos tengan nietos!$B$BA menos que...ELLOS se liberen y vuelvan a la superficie. Si eso ocurriera, entonces puedes olvidarte de los hijos.$B$BSi ELLOS quedan libres, todos seremos alimento de gusanos.', 0);
-- 971 El conocimiento de las profundidades
-- https://es.classic.wowhead.com/quest=971
SET @ID := 971;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El viaje a Vallefresno es largo y tu misión no es fácil. Pero $n, si me traes el manuscrito, te llevarás una buena recompensa.', 0),
(@ID, 'esMX', 'El viaje a Vallefresno es largo y tu misión no es fácil. Pero $n, si me traes el manuscrito, te llevarás una buena recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El manuscrito! ¡Qué alegría! ¡Por fin podremos divulgar los conocimientos antiguos de Lorgalis!$B$BNo puedo expresar mi agradecimiento, $n. Espero que este regalo sea buena prueba de mi gratitud.', 0),
(@ID, 'esMX', '¡El manuscrito! ¡Qué alegría! ¡Por fin podremos divulgar los conocimientos antiguos de Lorgalis!$B$BNo puedo expresar mi agradecimiento, $n. Espero que este regalo sea buena prueba de mi gratitud.', 0);
-- 724 Tener fe en el porvenir
-- https://es.classic.wowhead.com/quest=724
SET @ID := 724;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Otro viajero que quiere algo de los enanos.$B$B$gSeñor:Señora;, realmente lo siento, pero no tengo tiempo para responder preguntas sin sentido en este momento.', 0),
(@ID, 'esMX', 'Ah, sí. Otro viajero que quiere algo de los enanos.$B$B$gSeñor:Señora;, realmente lo siento, pero no tengo tiempo para responder preguntas sin sentido en este momento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh! Bueno, este es un asunto completamente diferente. Probablemente aún no te hayas dado cuenta de la gravedad de este asunto, ¿verdad?$B$BMe importa mucho la desaparición de Piemartillo, pero si te envió aquí con su amuleto, entonces entendió lo que está en juego.$B$BTendremos que tomarnos un tiempo para lamentar su muerte más tarde.$B$BDéjame mostrarte una de las razones por las que este amuleto es tan valioso.', 0),
(@ID, 'esMX', 'Oh! Bueno, este es un asunto completamente diferente. Probablemente aún no te hayas dado cuenta de la gravedad de este asunto, ¿verdad?$B$BMe importa mucho la desaparición de Piemartillo, pero si te envió aquí con su amuleto, entonces entendió lo que está en juego.$B$BTendremos que tomarnos un tiempo para lamentar su muerte más tarde.$B$BDéjame mostrarte una de las razones por las que este amuleto es tan valioso.', 0);
-- 733 ¡A gorronear!
-- https://es.classic.wowhead.com/quest=733
SET @ID := 733;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, me he apañado con lo que había pero... no es mucho. ¿Has encontrado más suministros?', 0),
(@ID, 'esMX', 'Bueno, me he apañado con lo que había pero... no es mucho. ¿Has encontrado más suministros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un comienzo, $n, y tendrá que servir hasta que sepamos algo de Forjaz o de la Liga de Exploradores.$B$BBien, y si ahora pudiera conseguir sal en algún lado para mi barril de bebida...', 0),
(@ID, 'esMX', 'Es un comienzo, $n, y tendrá que servir hasta que sepamos algo de Forjaz o de la Liga de Exploradores.$B$BBien, y si ahora pudiera conseguir sal en algún lado para mi barril de bebida...', 0);
