-- 1518 La llamada de la tierra
-- https://es.classic.wowhead.com/quest=1518
SET @ID := 1518;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quisiera ser el primero en darte la bienvenida a la primera de las cuatro sendas que guiarán tu destino.$B$BSi tienes la piedra que te dio la tierra te daré el tótem prometido.$B$BSi no la tienes, márchate hasta que encuentres tu camino.', 0),
(@ID, 'esMX', 'Quisiera ser el primero en darte la bienvenida a la primera de las cuatro sendas que guiarán tu destino.$B$BSi tienes la piedra que te dio la tierra te daré el tótem prometido.$B$BSi no la tienes, márchate hasta que encuentres tu camino.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente!$B$BEl tótem que haré para ti será mucho más que un símbolo de tu estatus entre los chamanes... Tiene habilidades que van mucho más allá. Uno de los usos del tótem es el de actuar como foco de hechizos. Los hechizos están vinculados a la tierra y a medida que aumente tu sabiduría podrás acceder a más y más habilidades de la tierra.$B$BLos instructores sabrán cuándo estás preparado para aumentar tu conocimiento.$B$BPor ahora, toma este Tótem de Tierra...', 0),
(@ID, 'esMX', '¡Excelente!$B$BEl tótem que haré para ti será mucho más que un símbolo de tu estatus entre los chamanes... Tiene habilidades que van mucho más allá. Uno de los usos del tótem es el de actuar como foco de hechizos. Los hechizos están vinculados a la tierra y a medida que aumente tu sabiduría podrás acceder a más y más habilidades de la tierra.$B$BLos instructores sabrán cuándo estás preparado para aumentar tu conocimiento.$B$BPor ahora, toma este Tótem de Tierra...', 0);
-- 1519 La llamada de la tierra
-- https://es.classic.wowhead.com/quest=1519
SET @ID := 1519;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La tierra es paciente y te esperará hasta que estés $glisto:lista; porque sabe que con el tiempo todas las cosas se erosionan y renacen. Es el ciclo de las cosas. Las montañas se convierten en desiertos. Los ríos se convierten en cañones. La tierra es el más terco y sabio de todos los elementos.$B$BDebes aprender a tener paciencia y resistencia por encima de todas las cosas. La tierra te llama ahora porque siente que estás listo. Considera este tu renacimiento si tiene éxito. Después, nunca podrás volver a la ignorancia.', 0),
(@ID, 'esMX', 'La tierra es paciente y te esperará hasta que estés $glisto:lista; porque sabe que con el tiempo todas las cosas se erosionan y renacen. Es el ciclo de las cosas. Las montañas se convierten en desiertos. Los ríos se convierten en cañones. La tierra es el más terco y sabio de todos los elementos.$B$BDebes aprender a tener paciencia y resistencia por encima de todas las cosas. La tierra te llama ahora porque siente que estás listo. Considera este tu renacimiento si tiene éxito. Después, nunca podrás volver a la ignorancia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, $n. Tu regreso aquí significa que estás $gpreparado:preparada; para el siguiente paso.$B$BDe todos los elementos, la tierra representa el fundamento de todas las cosas. Es tu fuerza, tu resistencia y tu paciencia. La Madre Tierra te protegerá, pero solo si le muestras el debido respeto. Ella es la base de la vida y, al observar sus leyes, obtendrás una mayor sabiduría. Nunca olvides los secretos que ella comparte contigo.$B$BHaré tu sapta para ti ahora, y al aceptarla, se abrirá un nuevo camino ante ti.', 0),
(@ID, 'esMX', 'Bien, $n. Tu regreso aquí significa que estás $gpreparado:preparada; para el siguiente paso.$B$BDe todos los elementos, la tierra representa el fundamento de todas las cosas. Es tu fuerza, tu resistencia y tu paciencia. La Madre Tierra te protegerá, pero solo si le muestras el debido respeto. Ella es la base de la vida y, al observar sus leyes, obtendrás una mayor sabiduría. Nunca olvides los secretos que ella comparte contigo.$B$BHaré tu sapta para ti ahora, y al aceptarla, se abrirá un nuevo camino ante ti.', 0);
-- 1521 La llamada de la tierra
-- https://es.classic.wowhead.com/quest=1521
SET @ID := 1521;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. No volverías a mí si no hubieras cumplido tu tarea. Que yo sea el primero en darte la bienvenida al primer camino de cuatro que gobernará para siempre tus viajes.$B$BSi tienes la piedra que te dio la tierra, te daré el tótem que prometió. Si no, entonces te compadezco. Hay mucho orgullo cuando te has dedicado completamente a los elementos.', 0),
(@ID, 'esMX', 'Saludos, $n. No volverías a mí si no hubieras cumplido tu tarea. Que yo sea el primero en darte la bienvenida al primer camino de cuatro que gobernará para siempre tus viajes.$B$BSi tienes la piedra que te dio la tierra, te daré el tótem que prometió. Si no, entonces te compadezco. Hay mucho orgullo cuando te has dedicado completamente a los elementos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espléndido.$B$BEl tótem que crearé para ti es más que un símbolo, tiene habilidades más allá de eso. Un uso del tótem es un enfoque para los hechizos. Esos hechizos están vinculados a la tierra y, a medida que ganes más y más sabiduría, podrás acceder a más habilidades de la tierra. Los entrenadores que se encuentran en todo Kalimdor sabrán cuándo estás $glisto:lista; para un mayor conocimiento y te lo harán saber cuando los visites.$B$BPero por ahora, toma este tótem de la tierra y un pergamino para enseñarte tu primera habilidad.', 0),
(@ID, 'esMX', 'Espléndido.$B$BEl tótem que crearé para ti es más que un símbolo, tiene habilidades más allá de eso. Un uso del tótem es un enfoque para los hechizos. Esos hechizos están vinculados a la tierra y, a medida que ganes más y más sabiduría, podrás acceder a más habilidades de la tierra. Los entrenadores que se encuentran en todo Kalimdor sabrán cuándo estás $glisto:lista; para un mayor conocimiento y te lo harán saber cuando los visites.$B$BPero por ahora, toma este tótem de la tierra y un pergamino para enseñarte tu primera habilidad.', 0);
-- 1522 La llamada del fuego
-- https://es.classic.wowhead.com/quest=1522
SET @ID := 1522;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmmm, Searn te envió a mí, ¿verdad?$B$BBueno, siempre se puede confiar en Searn, así que eso debe significar que estás $gpreparado:preparada; para participar en el próximo sapta: el sapta del fuego.$B$BYa lo veo en tus ojos, el ardor, el deseo. Has probado el poder y ahora estás $glisto:lista; para más. Paciencia, $n. Recuerda lo que te enseñó la tierra. El poder y la destrucción vendrán fácilmente, pero aún debes saber cuándo detener tu mano.', 0),
(@ID, 'esMX', 'Mmmm, Searn te envió a mí, ¿verdad?$B$BBueno, siempre se puede confiar en Searn, así que eso debe significar que estás $gpreparado:preparada; para participar en el próximo sapta: el sapta del fuego.$B$BYa lo veo en tus ojos, el ardor, el deseo. Has probado el poder y ahora estás $glisto:lista; para más. Paciencia, $n. Recuerda lo que te enseñó la tierra. El poder y la destrucción vendrán fácilmente, pero aún debes saber cuándo detener tu mano.', 0);
-- 1523 La llamada del fuego
-- https://es.classic.wowhead.com/quest=1523
SET @ID := 1523;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmmm, Narm te envió a mí, ¿verdad?$B$BBueno, siempre se puede confiar en Narm, por lo que debe significar que estás $gpreparado:preparada; para formar parte del próximo sapta: el sapta del fuego.$B$BYa lo veo en tus ojos, el ardor, el deseo. Ha probado el poder y ahora estás $glisto:lista; para más. Paciencia, $n. Recuerda lo que te enseñó la tierra. El poder y la destrucción vendrán fácilmente, pero aún debes saber cuándo detener tu mano.', 0),
(@ID, 'esMX', 'Mmmm, Narm te envió a mí, ¿verdad?$B$BBueno, siempre se puede confiar en Narm, por lo que debe significar que estás $gpreparado:preparada; para formar parte del próximo sapta: el sapta del fuego.$B$BYa lo veo en tus ojos, el ardor, el deseo. Ha probado el poder y ahora estás $glisto:lista; para más. Paciencia, $n. Recuerda lo que te enseñó la tierra. El poder y la destrucción vendrán fácilmente, pero aún debes saber cuándo detener tu mano.', 0);
-- 1524 La llamada del fuego
-- https://es.classic.wowhead.com/quest=1524
SET @ID := 1524;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n. Te hallas en el Santuario de la Llama Latente. Solo aquellos que poseen un conocimiento suficiente de las artes chamánicas logran descubrir los secretos de este lugar y el poder que alberga. Siento que hayas hecho tanto camino para ser $grechazado:rechazada; –sobre todo, un camino tan lleno de peligros– pero yo soy el guardián de este santuario y no puedo permitir que cualquiera acceda a él.', 0),
(@ID, 'esMX', 'Saludos, $n. Te hallas en el Santuario de la Llama Latente. Solo aquellos que poseen un conocimiento suficiente de las artes chamánicas logran descubrir los secretos de este lugar y el poder que alberga. Siento que hayas hecho tanto camino para ser $grechazado:rechazada; –sobre todo, un camino tan lleno de peligros– pero yo soy el guardián de este santuario y no puedo permitir que cualquiera acceda a él.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ay, perdona, $n. Te pido disculpas. No me he dado cuenta de que llevabas la antorcha. Me alegro de conocerte.$B$BMuchos son los aventureros que llegan hasta aquí buscando tesoros perdidos o míticas criaturas a las que matar y que vuelven sobre sus pasos, decepcionados, tras ver un templo aparentemente vacío. Pero nosotros sabemos algo que ellos ignoran, ¿no es cierto, $n?$B$BEste templo guarda de los miembros mundanos de la Horda un gran secreto. Para nosotros, es sagrado.', 0),
(@ID, 'esMX', 'Ay, perdona, $n. Te pido disculpas. No me he dado cuenta de que llevabas la antorcha. Me alegro de conocerte.$B$BMuchos son los aventureros que llegan hasta aquí buscando tesoros perdidos o míticas criaturas a las que matar y que vuelven sobre sus pasos, decepcionados, tras ver un templo aparentemente vacío. Pero nosotros sabemos algo que ellos ignoran, ¿no es cierto, $n?$B$BEste templo guarda de los miembros mundanos de la Horda un gran secreto. Para nosotros, es sagrado.', 0);
-- 1525 La llamada del fuego
-- https://es.classic.wowhead.com/quest=1525
SET @ID := 1525;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si me consigues la bolsa de componentes y algo de alquitrán, tendré ingredientes para crear la sapta de fuego. Los fanáticos del Filo Ardiente llevan en esas bolsas componentes para la mayoría de sus hechizos y suelen tener suficiente cantidad de los objetos que necesito, así que no habrá que buscar muy lejos.$B$BLas saptas siempre se hacen con ingredientes que están ligados a sus respectivos elementos. Eso nos facilita el trabajo por los lazos que unen a los brujos al fuego.', 0),
(@ID, 'esMX', 'Si me consigues la bolsa de componentes y algo de alquitrán, tendré ingredientes para crear la sapta de fuego. Los fanáticos del Filo Ardiente llevan en esas bolsas componentes para la mayoría de sus hechizos y suelen tener suficiente cantidad de los objetos que necesito, así que no habrá que buscar muy lejos.$B$BLas saptas siempre se hacen con ingredientes que están ligados a sus respectivos elementos. Eso nos facilita el trabajo por los lazos que unen a los brujos al fuego.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto servirá, $n.$B$BEl fuego es algo más que caos y destrucción, recuérdalo. También es vida y creación. Todas las cosas están unidas entre sí. Las fuerzas se oponen unas a otras, pero a la vez, no pueden existir las unas sin las otras. Ambas pueden destruir a su opuesta, pero también le dan significado. Recuérdalo siempre.$B$BUtilizar diferentes tipos de magia en conjunción, no solo demuestra una gran habilidad, también una gran sabiduría.', 0),
(@ID, 'esMX', 'Esto servirá, $n.$B$BEl fuego es algo más que caos y destrucción, recuérdalo. También es vida y creación. Todas las cosas están unidas entre sí. Las fuerzas se oponen unas a otras, pero a la vez, no pueden existir las unas sin las otras. Ambas pueden destruir a su opuesta, pero también le dan significado. Recuérdalo siempre.$B$BUtilizar diferentes tipos de magia en conjunción, no solo demuestra una gran habilidad, también una gran sabiduría.', 0);
-- 1526 La llamada del fuego
-- https://es.classic.wowhead.com/quest=1526
SET @ID := 1526;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El blandón tiene aproximadamente un tercio de tu altura. Y parece normal, excepto por las inscripciones que hay en las bandas de metal. El metal no está desgastado por el tiempo y la pila que tiene en la parte superior está fría al tacto.', 0),
(@ID, 'esMX', 'El blandón tiene aproximadamente un tercio de tu altura. Y parece normal, excepto por las inscripciones que hay en las bandas de metal. El metal no está desgastado por el tiempo y la pila que tiene en la parte superior está fría al tacto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una ardiente llama blanca surge en el cuenco cuando colocas el ascua en él. Puedes sentir los efectos mágicos de la sapta recorriendo tu cuerpo mientras ves cómo el fuego baila ante ti.$B$BColocas la parte superior de la antorcha en la pila y esta prende fuego inmediatamente.', 0),
(@ID, 'esMX', 'Una ardiente llama blanca surge en el cuenco cuando colocas el ascua en él. Puedes sentir los efectos mágicos de la sapta recorriendo tu cuerpo mientras ves cómo el fuego baila ante ti.$B$BColocas la parte superior de la antorcha en la pila y esta prende fuego inmediatamente.', 0);
-- 1527 La llamada del fuego
-- https://es.classic.wowhead.com/quest=1527
SET @ID := 1527;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n? ¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Sí, $n? ¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu espíritu arde con más brillo que ninguna antorcha, $n, deberías estar orgulloso de ello.$B$BSi sigues por este camino, podrás dominar los elementos y nuestros hermanos acudirán a ti para que los guíes. Deja que sea el primero en felicitarte y en presentarte a tu nuevo tótem.', 0),
(@ID, 'esMX', 'Tu espíritu arde con más brillo que ninguna antorcha, $n, deberías estar orgulloso de ello.$B$BSi sigues por este camino, podrás dominar los elementos y nuestros hermanos acudirán a ti para que los guíes. Deja que sea el primero en felicitarte y en presentarte a tu nuevo tótem.', 0);
-- 1528, 1529
-- https://es.classic.wowhead.com/quest=1528
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(1528, 1529) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(1528, 'esES', 'El viento viene presuroso hacia ti desde el horizonte, sientes la tierra firme bajo tus pies y tu espíritu ya siente el calor del fuego; diría que ha llegado la hora de que aprendas cosas sobre la pureza del agua.$B$BTu camino te ha conducido hasta aquí y tu espíritu te dará la fuerza para llegar aún más lejos. Pero tú has de dar el primer paso.', 0),
(1529, 'esES', 'El viento viene presuroso hacia ti desde el horizonte, sientes la tierra firme bajo tus pies y tu espíritu ya siente el calor del fuego; diría que ha llegado la hora de que aprendas cosas sobre la pureza del agua.$B$BTu camino te ha conducido hasta aquí y tu espíritu te dará la fuerza para llegar aún más lejos. Pero tú has de dar el primer paso.', 0),
(1528, 'esMX', 'El viento viene presuroso hacia ti desde el horizonte, sientes la tierra firme bajo tus pies y tu espíritu ya siente el calor del fuego; diría que ha llegado la hora de que aprendas cosas sobre la pureza del agua.$B$BTu camino te ha conducido hasta aquí y tu espíritu te dará la fuerza para llegar aún más lejos. Pero tú has de dar el primer paso.', 0),
(1529, 'esMX', 'El viento viene presuroso hacia ti desde el horizonte, sientes la tierra firme bajo tus pies y tu espíritu ya siente el calor del fuego; diría que ha llegado la hora de que aprendas cosas sobre la pureza del agua.$B$BTu camino te ha conducido hasta aquí y tu espíritu te dará la fuerza para llegar aún más lejos. Pero tú has de dar el primer paso.', 0);
-- 1530 La llamada del agua
-- https://es.classic.wowhead.com/quest=1530
SET @ID := 1530;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?$B$BMm, me parece que sé lo que vas a preguntarme: ¿qué posee a alguien para vivir en el más remoto rincón de Los Baldíos, rodeado de la amenaza de los jabaespines y sin protección? Bueno, todos tenemos nuestros motivos para justificar la forma en que actuamos. La verdadera cuestión es qué trae a $gun:una; humilde $r a lo más recóndito de Los Baldíos para hablar con una mujer que a todas luces no se preocupa por su propio bien.$B$BApostaría que ambos conocemos la respuesta.', 0),
(@ID, 'esMX', '¿Sí?$B$BMm, me parece que sé lo que vas a preguntarme: ¿qué posee a alguien para vivir en el más remoto rincón de Los Baldíos, rodeado de la amenaza de los jabaespines y sin protección? Bueno, todos tenemos nuestros motivos para justificar la forma en que actuamos. La verdadera cuestión es qué trae a $gun:una; humilde $r a lo más recóndito de Los Baldíos para hablar con una mujer que a todas luces no se preocupa por su propio bien.$B$BApostaría que ambos conocemos la respuesta.', 0);
-- 1531, 1532
-- https://es.classic.wowhead.com/quest=1531
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(1531, 1532) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(1531, 'esES', 'De momento, te daré lo que necesitas para realizar tus hechizos e invocar a los espíritus del aire. Coge este tótem y, cuando estés $gpreparado:preparada;, ven a verme para continuar con tu instrucción.', 0),
(1532, 'esES', 'De momento, te daré lo que necesitas para realizar tus hechizos e invocar a los espíritus del aire. Coge este tótem y, cuando estés $gpreparado:preparada;, ven a verme para continuar con tu instrucción.', 0),
(1531, 'esMX', 'De momento, te daré lo que necesitas para realizar tus hechizos e invocar a los espíritus del aire. Coge este tótem y, cuando estés $gpreparado:preparada;, ven a verme para continuar con tu instrucción.', 0),
(1532, 'esMX', 'De momento, te daré lo que necesitas para realizar tus hechizos e invocar a los espíritus del aire. Coge este tótem y, cuando estés $gpreparado:preparada;, ven a verme para continuar con tu instrucción.', 0);
-- 1534 La llamada del agua
-- https://es.classic.wowhead.com/quest=1534
SET @ID := 1534;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya el agua, $n? Según la leyenda, las ruinas estaban protegidas por colosales criaturas de la naturaleza que no acogerían muy bien a los visitantes pero podrían ser mitos para espantar a los enemigos de los elfos de la noche.$B$BSea como fuere, ten cuidado.', 0),
(@ID, 'esMX', '¿Tienes ya el agua, $n? Según la leyenda, las ruinas estaban protegidas por colosales criaturas de la naturaleza que no acogerían muy bien a los visitantes pero podrían ser mitos para espantar a los enemigos de los elfos de la noche.$B$BSea como fuere, ten cuidado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Maravilloso, $n. Con las 3 muestras reunidas, puedo crear un vial con el agua más pura que ninguna criatura viviente haya conocido jamás. Se usará en los próximos pasos de tu rito de paso.$B$BMe alegra que estés de nuestro lado, $n. Cualquier $c estaría orgulloso de ti y espero oír relatos sobre tus hazañas en el futuro.', 0),
(@ID, 'esMX', 'Maravilloso, $n. Con las 3 muestras reunidas, puedo crear un vial con el agua más pura que ninguna criatura viviente haya conocido jamás. Se usará en los próximos pasos de tu rito de paso.$B$BMe alegra que estés de nuestro lado, $n. Cualquier $c estaría orgulloso de ti y espero oír relatos sobre tus hazañas en el futuro.', 0);
-- 1535 La llamada del agua
-- https://es.classic.wowhead.com/quest=1535
SET @ID := 1535;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Casi todo está listo para enviarte a tus tareas siguientes. ¿Has llenado ya el odre?$B$BSé cuán protector puede ser el jabaespín. Hasta una fuente tan exigua de agua es un vasto tesoro oculto para ellos. Tienen lugar grandes celebraciones cuando la más mínima lluvia cae sobre Los Baldíos. El agua es sagrada para su especie por su escasez. ¿Lo entiendes?', 0),
(@ID, 'esMX', 'Casi todo está listo para enviarte a tus tareas siguientes. ¿Has llenado ya el odre?$B$BSé cuán protector puede ser el jabaespín. Hasta una fuente tan exigua de agua es un vasto tesoro oculto para ellos. Tienen lugar grandes celebraciones cuando la más mínima lluvia cae sobre Los Baldíos. El agua es sagrada para su especie por su escasez. ¿Lo entiendes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creía que se produciría un baño de sangre si intentabas llevarte agua de la poza. Es una pena que el jabaespín no se dé cuenta de que todos los seres vivientes son interdependientes y que su avaricia solo perpetúa el dolor y el sufrimiento de su pueblo. ¡Cuánto podrían lograR si dejaran a un lado sus diferencias y sus clanes se unieran!$B$BInsisto, es una lástima, pero es más que probable que sea un favor para las otras razas de Los Baldíos.', 0),
(@ID, 'esMX', 'Creía que se produciría un baño de sangre si intentabas llevarte agua de la poza. Es una pena que el jabaespín no se dé cuenta de que todos los seres vivientes son interdependientes y que su avaricia solo perpetúa el dolor y el sufrimiento de su pueblo. ¡Cuánto podrían lograR si dejaran a un lado sus diferencias y sus clanes se unieran!$B$BInsisto, es una lástima, pero es más que probable que sea un favor para las otras razas de Los Baldíos.', 0);
-- 1536 La llamada del agua
-- https://es.classic.wowhead.com/quest=1536
SET @ID := 1536;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El pozo que permanece puro en el pueblo me recuerda historias que oí cuando era más joven, $n. Incluso en tiempos de gran sufrimiento y pesadumbre, se encuentra un rayo de esperanza, un pequeño símbolo junto al que cobijarse. Así ven a Thrall los orcos. Sobrevivió a los mayores peligros y se erigió en el líder de nuestro pueblo gracias a su fuerza y a su ejemplo.$B$BNo creo que ningún orco haya sufrido tanto como él pero tampoco creo que ningúno sean tan fuerte como él.', 0),
(@ID, 'esMX', 'El pozo que permanece puro en el pueblo me recuerda historias que oí cuando era más joven, $n. Incluso en tiempos de gran sufrimiento y pesadumbre, se encuentra un rayo de esperanza, un pequeño símbolo junto al que cobijarse. Así ven a Thrall los orcos. Sobrevivió a los mayores peligros y se erigió en el líder de nuestro pueblo gracias a su fuerza y a su ejemplo.$B$BNo creo que ningún orco haya sufrido tanto como él pero tampoco creo que ningúno sean tan fuerte como él.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es bueno, $n. Te entregas a la tarea que te ocupa y tienes la facultad de procurarte lo que hace falta.$B$BSolo necesito una muestra más para crear el componente necesario para tu sapta. Islen también se alegrará.', 0),
(@ID, 'esMX', 'Esto es bueno, $n. Te entregas a la tarea que te ocupa y tienes la facultad de procurarte lo que hace falta.$B$BSolo necesito una muestra más para crear el componente necesario para tu sapta. Islen también se alegrará.', 0);
-- 1558 Presa de las Tres Cabezas
-- https://es.classic.wowhead.com/quest=1558
SET @ID := 1558;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya llegamos?', 0),
(@ID, 'esMX', '¿Ya llegamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡GUAU, la presa era MUCHO más grande de lo que pensaba! ¡Apenas podía oírme hablar por el sonido del agua corriendo! Oye, ¿crees que alguna vez se quedaría sin agua? Hombre, ¿qué pasaría si ese muro se rompiera alguna vez? ¡GUAU, eso daría miedo!$B$BGracias por llevarme a ver la presa. Eso fue muy amable de tu parte. ¡Te dije que no me inclinaría demasiado!', 0),
(@ID, 'esMX', '¡GUAU, la presa era MUCHO más grande de lo que pensaba! ¡Apenas podía oírme hablar por el sonido del agua corriendo! Oye, ¿crees que alguna vez se quedaría sin agua? Hombre, ¿qué pasaría si ese muro se rompiera alguna vez? ¡GUAU, eso daría miedo!$B$BGracias por llevarme a ver la presa. Eso fue muy amable de tu parte. ¡Te dije que no me inclinaría demasiado!', 0);
-- 1559 Receta de bomba cegadora
-- https://es.classic.wowhead.com/quest=1559
SET @ID := 1559;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conque eres ingeniero, eh? Bueno, por tu ayuda para conseguir esas perlas, aquí tienes la receta de las bombas centelleantes.$B$B¡Suerte y ojito con dejarte ciego!', 0),
(@ID, 'esMX', '¿Conque eres ingeniero, eh? Bueno, por tu ayuda para conseguir esas perlas, aquí tienes la receta de las bombas centelleantes.$B$B¡Suerte y ojito con dejarte ciego!', 0);
-- 1560 La misión de Tooga
-- https://es.classic.wowhead.com/quest=1560
SET @ID := 1560;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que no fue capaz de encontrar el camino de vuelta él solo? Figúrate tú...$B$BBueno, supongo que mereces algo por tus esfuerzos...', 0),
(@ID, 'esMX', '¿Así que no fue capaz de encontrar el camino de vuelta él solo? Figúrate tú...$B$BBueno, supongo que mereces algo por tus esfuerzos...', 0);
-- 1581 Elixires para Filohoja
-- https://es.classic.wowhead.com/quest=1581
SET @ID := 1581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Tienes los elixires para comerciar?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Tienes los elixires para comerciar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos están muy bien mezclados. Tienes mucho cuidado en tu oficio, $n, y eso es importante para un alquimista.$B$BAquí tienes tus hierbas recién recolectadas. Úsalas bien.', 0),
(@ID, 'esMX', 'Estos están muy bien mezclados. Tienes mucho cuidado en tu oficio, $n, y eso es importante para un alquimista.$B$BAquí tienes tus hierbas recién recolectadas. Úsalas bien.', 0);
-- 1582 El jubón resplandor lunar
-- https://es.classic.wowhead.com/quest=1582
SET @ID := 1582;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $n.', 0),
(@ID, 'esMX', 'Saludos, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son unas buenas piezas. Tienes manos hábiles y un buen ojo para los detalles. Tu futuro como $gpeletero:peletera; es prometedor.$B$BTen, $n. Deja que te enseñe el patrón para hacer el jubón de brillo lunar.', 0),
(@ID, 'esMX', 'Son unas buenas piezas. Tienes manos hábiles y un buen ojo para los detalles. Tu futuro como $gpeletero:peletera; es prometedor.$B$BTen, $n. Deja que te enseñe el patrón para hacer el jubón de brillo lunar.', 0);
-- 1599 Novato
-- Notice: English text: change %C to $c
-- https://es.classic.wowhead.com/quest=1599
SET @ID := 1599;
UPDATE `quest_offer_reward` SET `RewardText` = 'Very good, very good! You\'ve done well, $N. Perhaps the interest that is being shown in you is deserved, after all.$B$BThat\'ll be for the others to decide--assuming your imp doesn\'t overpower you and nip your career in the bud. For now, I\'m satisfied that you\'ll probably survive your first few months as a $c.$B$BA word about the imp, $N. As a $R knows, don\'t let its size fool you, its magic can be very dangerous.', `VerifiedBuild` = 0 WHERE `id` = @ID;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esos amuletos de plumas que llevan los novatos tienen algún tipo de poder mágico. Será interesante investigarlos. No lo hubiera esperado de los trols.', 0),
(@ID, 'esMX', 'Esos amuletos de plumas que llevan los novatos tienen algún tipo de poder mágico. Será interesante investigarlos. No lo hubiera esperado de los trols.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, muy bien! Lo has hecho bien, $n. Quizás el interés que se muestra en ti sea merecido, después de todo.$B$BEso será para que los demás lo decidan, asumiendo que tu diablillo no te domine y corte tu carrera de raíz. Por ahora, estoy satisfecho de que sobrevivas tus primeros meses como $c.$B$BUna palabra sobre el diablillo, $n. Como sabes $r, no dejes que su tamaño te engañe, su magia puede ser muy peligrosa.', 0),
(@ID, 'esMX', '¡Muy bien, muy bien! Lo has hecho bien, $n. Quizás el interés que se muestra en ti sea merecido, después de todo.$B$BEso será para que los demás lo decidan, asumiendo que tu diablillo no te domine y corte tu carrera de raíz. Por ahora, estoy satisfecho de que sobrevivas tus primeros meses como $c.$B$BUna palabra sobre el diablillo, $n. Como sabes $r, no dejes que su tamaño te engañe, su magia puede ser muy peligrosa.', 0);
-- 1646 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1646
SET @ID := 1646;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. Espero que hayas dedicado un rato a leer el libro.$B$BSi lo has hecho, deberías estar $gpreparado:preparada; para pasar una prueba. Siempre hay cosas que hacer en la ciudad y en nuestras tierras, actos de compasión y comprensión, gente a la que ayudar, criaturas a las que matar.$B$BSi demuestras que tienes la paciencia necesaria para ayudar a otros, especialmente a los menos afortunados, demostrarás que estás en pleno uso de tus facultades y que eres $gun siervo:una sierva; de la Luz.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. Espero que hayas dedicado un rato a leer el libro.$B$BSi lo has hecho, deberías estar $gpreparado:preparada; para pasar una prueba. Siempre hay cosas que hacer en la ciudad y en nuestras tierras, actos de compasión y comprensión, gente a la que ayudar, criaturas a las que matar.$B$BSi demuestras que tienes la paciencia necesaria para ayudar a otros, especialmente a los menos afortunados, demostrarás que estás en pleno uso de tus facultades y que eres $gun siervo:una sierva; de la Luz.', 0);
-- 1647 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1647
SET @ID := 1647;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'EL ORFANATO DE VENTORM... ay, perdona, no quería gritarte así.$B$BMe llamo John Turner. ¿Cómo estás?$B$BBien, bien, me alegro de oír que las cosas te van bien. He tenido un día muy largo y echo mucho de menos a mi mujer... Pero es el precio que hay que pagar cuando tienes niños que alimentar y que vestir.', 0),
(@ID, 'esMX', 'EL ORFANATO DE VENTORM... ay, perdona, no quería gritarte así.$B$BMe llamo John Turner. ¿Cómo estás?$B$BBien, bien, me alegro de oír que las cosas te van bien. He tenido un día muy largo y echo mucho de menos a mi mujer... Pero es el precio que hay que pagar cuando tienes niños que alimentar y que vestir.', 0);
-- 1648 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1648
SET @ID := 1648;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a la afluencia de comerciantes por todo Azeroth, tenemos un pequeño suministro de objetos que utilizamos para hacer ropa para los niños de nuestro orfanato. Ayudarme a reunir telas para que mi mujer pueda hacer ropa para ellos es muy noble por tu parte, $n. Te lo agradezco.$B$BEspero poder volver a casa con mi mujer pronto.', 0),
(@ID, 'esMX', 'Gracias a la afluencia de comerciantes por todo Azeroth, tenemos un pequeño suministro de objetos que utilizamos para hacer ropa para los niños de nuestro orfanato. Ayudarme a reunir telas para que mi mujer pueda hacer ropa para ellos es muy noble por tu parte, $n. Te lo agradezco.$B$BEspero poder volver a casa con mi mujer pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es todo un detalle, $n. Gracias otra vez.$B$BEres un buen hombre. No mucha gente haría esto por mí. No me extraña que hayas elegido el camino de la Luz. Me gustaría encontrar la forma de pagarte por todo lo que has hecho... ¿Qué? ¿Que era lo mínimo que podías hacer? ¿Ves? Eso es precisamente lo que decía, $n, eres la personificación de la nobleza.$B$BQue la Luz te guíe y te proteja en tus viajes.', 0),
(@ID, 'esMX', 'Esto es todo un detalle, $n. Gracias otra vez.$B$BEres un buen hombre. No mucha gente haría esto por mí. No me extraña que hayas elegido el camino de la Luz. Me gustaría encontrar la forma de pagarte por todo lo que has hecho... ¿Qué? ¿Que era lo mínimo que podías hacer? ¿Ves? Eso es precisamente lo que decía, $n, eres la personificación de la nobleza.$B$BQue la Luz te guíe y te proteja en tus viajes.', 0);
-- 1657 Apesta Costasur
-- https://es.classic.wowhead.com/quest=1657
SET @ID := 1657;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Lanza la bomba fétida en Costasur.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has entregado nuestro "regalo" a la gente de Costasur?$B$B<La clamasombras Yanka se ríe con malicia.>', 0),
(@ID, 'esMX', '¿Has entregado nuestro "regalo" a la gente de Costasur?$B$B<La clamasombras Yanka se ríe con malicia.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, bien hecho! ¡Espero que la Alianza se ahogue con el horrible regalo que les hemos hecho, como nos vimos obligados a ahogarnos con el yugo de la esclavitud a la Plaga!$B$BHas mantenido ciertas las ideas de Hallow\'s End, $n, y por eso te saludo. Como beneficio adicional, permítanme compartir algunos de estos dulces de Hallow\'s End que tengo con ustedes. ¡Creo que puede encontrarlos como una diversión bastante agradable!', 0),
(@ID, 'esMX', '¡Ah, bien hecho! ¡Espero que la Alianza se ahogue con el horrible regalo que les hemos hecho, como nos vimos obligados a ahogarnos con el yugo de la esclavitud a la Plaga!$B$BHas mantenido ciertas las ideas de Hallow\'s End, $n, y por eso te saludo. Como beneficio adicional, permítanme compartir algunos de estos dulces de Hallow\'s End que tengo con ustedes. ¡Creo que puede encontrarlos como una diversión bastante agradable!', 0);
-- 1658 Arruinar el Festival del Hombre de Mimbre
-- https://es.classic.wowhead.com/quest=1658
SET @ID := 1658;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. El Festival del Hombre de Mimbre seguirá siendo un problema mientras se permita a los abominables Renegados acechar los restos de Lordaeron. Déjame decirte que NO es un tributo apropiado a ese reino antaño orgulloso...$B$BAquí hay una moneda para cualquier reparación que pueda necesitar, y en el espíritu de la temporada, también he incluido algunas golosinas que pueden gustarle. Happy Hallow\'s End: mantengamos la situación lo más segura posible aquí en Costasur.', 0),
(@ID, 'esMX', 'Bien hecho, $n. El Festival del Hombre de Mimbre seguirá siendo un problema mientras se permita a los abominables Renegados acechar los restos de Lordaeron. Déjame decirte que NO es un tributo apropiado a ese reino antaño orgulloso...$B$BAquí hay una moneda para cualquier reparación que pueda necesitar, y en el espíritu de la temporada, también he incluido algunas golosinas que pueden gustarle. Happy Hallow\'s End: mantengamos la situación lo más segura posible aquí en Costasur.', 0);
-- 1678 Vejrek
-- https://es.classic.wowhead.com/quest=1678
SET @ID := 1678;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en la cabaña de Vejrek, $n? ¿Eres tú el que apesta a trol?', 0),
(@ID, 'esMX', '¿Has estado en la cabaña de Vejrek, $n? ¿Eres tú el que apesta a trol?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vejrek tenía que ser bastante feo, ¿eh? ¡Bien hecho, $n! Tienes todo lo necesario, comencemos nuestra lección...$B$BTal vez no lo sepas, pero una defensa fuerte es fundamental para $gun:una; $c. Le permite mantenerse en pie frente a enemigos que derribarían al resto, y eso es lo que necesitan de ti tus aliados.', 0),
(@ID, 'esMX', 'Vejrek tenía que ser bastante feo, ¿eh? ¡Bien hecho, $n! Tienes todo lo necesario, comencemos nuestra lección...$B$BTal vez no lo sepas, pero una defensa fuerte es fundamental para $gun:una; $c. Le permite mantenerse en pie frente a enemigos que derribarían al resto, y eso es lo que necesitan de ti tus aliados.', 0);
-- 1679 Muren Pico Tormenta
-- https://es.classic.wowhead.com/quest=1679
SET @ID := 1679;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hiciste el cambio?', 0),
(@ID, 'esMX', '¿Hiciste el cambio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n. He oído a los guerreros de Dun Morogh vitorear tu nombre. ¡Espero que no te hayas pasado todo el día en las cervecerías!', 0),
(@ID, 'esMX', 'Ah, $n. He oído a los guerreros de Dun Morogh vitorear tu nombre. ¡Espero que no te hayas pasado todo el día en las cervecerías!', 0);
-- 1680 Tormus Forjahonda
-- https://es.classic.wowhead.com/quest=1680
SET @ID := 1680;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vienes de parte de Muren, ¿verdad? Sí, puedo hacerte una bonita arma... pero antes de hacerlo te tengo que pedir un favor.$B$BNo te preocupes. Es muy peligroso y podría llevarte a la muerte... exactamente lo que le gusta a un $c.', 0),
(@ID, 'esMX', 'Vienes de parte de Muren, ¿verdad? Sí, puedo hacerte una bonita arma... pero antes de hacerlo te tengo que pedir un favor.$B$BNo te preocupes. Es muy peligroso y podría llevarte a la muerte... exactamente lo que le gusta a un $c.', 0);
-- 1681 Complejo Vetaferro
-- https://es.classic.wowhead.com/quest=1681
SET @ID := 1681;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has entrado en el Complejo Vetaferro? ¿Encontraste el mineral umbrío?', 0),
(@ID, 'esMX', '¿Has entrado en el Complejo Vetaferro? ¿Encontraste el mineral umbrío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo encontraste! ¡Bien hecho!$B$BEspero que mataras a un montón de enanos Hierro Negro mientras buscabas. Me temo que el Complejo Vetaferro no será el último lugar donde los veamos.$B$BPero gracias por el mineral, $n. Estoy ansioso por ponerme a trabajar con él y descubrir sus propiedades.', 0),
(@ID, 'esMX', '¡Lo encontraste! ¡Bien hecho!$B$BEspero que mataras a un montón de enanos Hierro Negro mientras buscabas. Me temo que el Complejo Vetaferro no será el último lugar donde los veamos.$B$BPero gracias por el mineral, $n. Estoy ansioso por ponerme a trabajar con él y descubrir sus propiedades.', 0);
-- 1682 Armas de hierro gris
-- https://es.classic.wowhead.com/quest=1682
SET @ID := 1682;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son algunas armas combadas sobre el yunque y hechas con el mineral umbrío que me trajiste.$B$B¡Por favor, $n, elige lo que quieras!', 0),
(@ID, 'esMX', 'Estas son algunas armas combadas sobre el yunque y hechas con el mineral umbrío que me trajiste.$B$B¡Por favor, $n, elige lo que quieras!', 0);
-- 1683 Vorlus Pezuñavil
-- https://es.classic.wowhead.com/quest=1683
SET @ID := 1683;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el cuerno, $n? ¿Está nuestra poza de la luna libre del demonio Vorlus?', 0),
(@ID, 'esMX', '¿Tienes el cuerno, $n? ¿Está nuestra poza de la luna libre del demonio Vorlus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Es bueno saber que Vorlus ha sido derrotado y nuestra poza de la luna limpia, y es bueno ver a jóvenes guerreros ansiosos por mantener a nuestro amado Teldrassil libre de corrupción.$B$BAhora comencemos tu entrenamiento...', 0),
(@ID, 'esMX', 'Bien hecho, $n. Es bueno saber que Vorlus ha sido derrotado y nuestra poza de la luna limpia, y es bueno ver a jóvenes guerreros ansiosos por mantener a nuestro amado Teldrassil libre de corrupción.$B$BAhora comencemos tu entrenamiento...', 0);
