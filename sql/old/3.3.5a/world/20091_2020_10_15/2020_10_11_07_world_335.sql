-- 10752 A Vallefresno
-- https://es.classic.wowhead.com/quest=10752
SET @ID := 10752;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces Thundris Tejevientos todavía cree que necesito que me cuiden? Tendré que recordarle quién salvó a quién; parece olvidar que fui yo quien lo sacó del camino del peligro.$B$BBueno, ahora que estás aquí, $r, quizás pueda encontrar algo que puedas hacer.', 0),
(@ID, 'esMX', '¿Entonces Thundris Tejevientos todavía cree que necesito que me cuiden? Tendré que recordarle quién salvó a quién; parece olvidar que fui yo quien lo sacó del camino del peligro.$B$BBueno, ahora que estás aquí, $r, quizás pueda encontrar algo que puedas hacer.', 0);
-- 982 Profundo océano, mar inmenso
-- https://es.classic.wowhead.com/quest=982
SET @ID := 982;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los capitanes de esas naves eran buenos elfos de la noche. Merecen un destino mejor del que tuvieron. Atender sus efectos personales sería la mejor forma de dar paz a sus espíritus.', 0),
(@ID, 'esMX', 'Los capitanes de esas naves eran buenos elfos de la noche. Merecen un destino mejor del que tuvieron. Atender sus efectos personales sería la mejor forma de dar paz a sus espíritus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un gran servicio a Auberdine, $gmuchacho:muchacha;. Cuidaremos bien de sus efectos.$B$BPor favor, acepta esto. Es lo mínimo que puedo hacer por alguien que ha tenido el valor suficiente para enmendar esta situación.', 0),
(@ID, 'esMX', 'Has hecho un gran servicio a Auberdine, $gmuchacho:muchacha;. Cuidaremos bien de sus efectos.$B$BPor favor, acepta esto. Es lo mínimo que puedo hacer por alguien que ha tenido el valor suficiente para enmendar esta situación.', 0);
-- 953 La caída de Ameth'Aran
-- https://es.classic.wowhead.com/quest=953
SET @ID := 953;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando hayas estudiado las tablillas y te hayas enterado de la caída de Ameth\'Aran, llevaré el conocimiento a Auberdine e informaré al Círculo de Antiguos.', 0),
(@ID, 'esMX', 'Cuando hayas estudiado las tablillas y te hayas enterado de la caída de Ameth\'Aran, llevaré el conocimiento a Auberdine e informaré al Círculo de Antiguos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenemos poca información del tiempo de La guerra de los Ancestros y menos aún de la destrucción del Pozo de la Eternidad. Considerando la agitación y el caos que provocaron los acontecimientos que tenían lugar entonces, no es de sorprender.$B$BGracias, $n. Con tu ayuda, pronto acabaré mi trabajo y podré entregar un informe completo al Círculo.', 0),
(@ID, 'esMX', 'Tenemos poca información del tiempo de La guerra de los Ancestros y menos aún de la destrucción del Pozo de la Eternidad. Considerando la agitación y el caos que provocaron los acontecimientos que tenían lugar entonces, no es de sorprender.$B$BGracias, $n. Con tu ayuda, pronto acabaré mi trabajo y podré entregar un informe completo al Círculo.', 0);
-- 4813 Los trozos del interior
-- https://es.classic.wowhead.com/quest=4813
SET @ID := 4813;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, parece que aunque sabemos algo más sobre el cristal, ¡solo hemos conseguido acumular más preguntas sin respuesta!$B$BLlevaré la información que has reunido al Concejo de Auberdine. Quizás ellos sepan qué tenemos que hacer con este cristal. Eso, claro está, suponiendo que tengamos que hacer algo porque, por ahora, es una amenaza muy lejana y no creo que nos alcance.$B$BPor favor, acepta esto. Considéralo una recompensa por un trabajo bien hecho, $n.', 0),
(@ID, 'esMX', 'Vaya, parece que aunque sabemos algo más sobre el cristal, ¡solo hemos conseguido acumular más preguntas sin respuesta!$B$BLlevaré la información que has reunido al Concejo de Auberdine. Quizás ellos sepan qué tenemos que hacer con este cristal. Eso, claro está, suponiendo que tengamos que hacer algo porque, por ahora, es una amenaza muy lejana y no creo que nos alcance.$B$BPor favor, acepta esto. Considéralo una recompensa por un trabajo bien hecho, $n.', 0);
-- 955 Bashal'Aran
-- https://es.classic.wowhead.com/quest=955
SET @ID := 955;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tenga los pendientes, lanzaré el hechizo para localizar el sello que me ata. Llevo siglos soñando con la libertad que alcanzaría destruyendo el sello... Quizás todos esos siglos han dejado mella en mi mente... algo de lo que podría no recuperarme jamás...', 0),
(@ID, 'esMX', 'Cuando tenga los pendientes, lanzaré el hechizo para localizar el sello que me ata. Llevo siglos soñando con la libertad que alcanzaría destruyendo el sello... Quizás todos esos siglos han dejado mella en mi mente... algo de lo que podría no recuperarme jamás...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya... los grells de Bashal\'Aran no poseen lo que estoy buscando... pero han entrado en contacto con ello recientemente, sin duda. Recientemente... en tu escala del tiempo, no en la mía. Porque los acontecimientos que para mí son recientes, para ti se pierden en la niebla del pasado, en una Era de la que ni siquiera has oído hablar...', 0),
(@ID, 'esMX', 'Vaya... los grells de Bashal\'Aran no poseen lo que estoy buscando... pero han entrado en contacto con ello recientemente, sin duda. Recientemente... en tu escala del tiempo, no en la mía. Porque los acontecimientos que para mí son recientes, para ti se pierden en la niebla del pasado, en una Era de la que ni siquiera has oído hablar...', 0);
-- 956 Bashal'Aran
-- https://es.classic.wowhead.com/quest=956
SET @ID := 956;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pilares de este santuario son para mí como los barrotes de una prisión, $n. Las fuerzas que me queden no podrán quebrarlos, y tampoco me queda magia que podría lograrlo...$B$BMás de mil años he pasado observándolos, preguntándome si quedaría libre al final, si yo sobreviviera a la piedra... ¿O quedaría igualmente atrapado por unos barrotes invisibles?', 0),
(@ID, 'esMX', 'Los pilares de este santuario son para mí como los barrotes de una prisión, $n. Las fuerzas que me queden no podrán quebrarlos, y tampoco me queda magia que podría lograrlo...$B$BMás de mil años he pasado observándolos, preguntándome si quedaría libre al final, si yo sobreviviera a la piedra... ¿O quedaría igualmente atrapado por unos barrotes invisibles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es duro saber que esto que ahora contemplo me ha retenido tanto tiempo... Pero no nos entretengamos, $n. Cuando el sello haya sido destruido, podré volver a caminar por los bosques libremente.', 0),
(@ID, 'esMX', 'Es duro saber que esto que ahora contemplo me ha retenido tanto tiempo... Pero no nos entretengamos, $n. Cuando el sello haya sido destruido, podré volver a caminar por los bosques libremente.', 0);
-- 957 Bashal'Aran
-- https://es.classic.wowhead.com/quest=957
SET @ID := 957;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En verdad, $n, me temo... Tengo miedo de que tu venida, todo esto, sea meramente producto de una mente trastornada. ¿Puedes conocer la tortura que es esto? Yo... Por favor, debes ir rápido.', 0),
(@ID, 'esMX', 'En verdad, $n, me temo... Tengo miedo de que tu venida, todo esto, sea meramente producto de una mente trastornada. ¿Puedes conocer la tortura que es esto? Yo... Por favor, debes ir rápido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Soy libre, $n. Ahora puedo ver con mis propios ojos los cambios que ha sufrido nuestro mundo... Solo había percibido una pequeña parte de ellos. Y pensar que la última vez que caminaba libre, la poza aún existía y los altonatos se reunían en la corte de Azshara, nuestra amada reina.$B$BSiento que mi carcelero, mi antiguo maestro, Athrikus, aún vive... Mi desesperanza empieza a tornarse en deseos de venganza...', 0),
(@ID, 'esMX', 'Soy libre, $n. Ahora puedo ver con mis propios ojos los cambios que ha sufrido nuestro mundo... Solo había percibido una pequeña parte de ellos. Y pensar que la última vez que caminaba libre, la poza aún existía y los altonatos se reunían en la corte de Azshara, nuestra amada reina.$B$BSiento que mi carcelero, mi antiguo maestro, Athrikus, aún vive... Mi desesperanza empieza a tornarse en deseos de venganza...', 0);
-- 4723 Criatura marina varada
-- https://es.classic.wowhead.com/quest=4723
SET @ID := 4723;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás un día encontremos la forma de impedir que esas pobres criaturas acaben sus vidas en Costa Oscura de forma tan trágica e inútil. Hasta entonces, ¡debemos seguir investigando!$B$BSaludos, $n, ¿qué noticias traes?', 0),
(@ID, 'esMX', 'Quizás un día encontremos la forma de impedir que esas pobres criaturas acaben sus vidas en Costa Oscura de forma tan trágica e inútil. Hasta entonces, ¡debemos seguir investigando!$B$BSaludos, $n, ¿qué noticias traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Otro descubrimiento! ¡Bien hecho, $n! Estos restos serán estudiados adecuadamente una vez lleguen a Darnassus. Por favor, acepta este pequeño honorario a cambio de los restos que nos has proporcionado para nuestro estudio.', 0),
(@ID, 'esMX', '¡Otro descubrimiento! ¡Bien hecho, $n! Estos restos serán estudiados adecuadamente una vez lleguen a Darnassus. Por favor, acepta este pequeño honorario a cambio de los restos que nos has proporcionado para nuestro estudio.', 0);
-- 1002 La caja mecánica 323
-- https://es.classic.wowhead.com/quest=1002
SET @ID := 1002;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque aún no has colocado los 6 colmillos de Acechalunas, te parece oír unos sonidos estáticos y un farfulleo de gnomo saliendo de la máquina. ¿Alguien la habrá arreglado ya?', 0),
(@ID, 'esMX', 'Aunque aún no has colocado los 6 colmillos de Acechalunas, te parece oír unos sonidos estáticos y un farfulleo de gnomo saliendo de la máquina. ¿Alguien la habrá arreglado ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La caja mecánica se activa de repente y oyes sonidos de dientes que se pulverizan en su interior.$B$B"¡Ashí que lo hash conseguido! Esh una notishia excelente... Entonshesh... ¿Por qué no shiguesh con lo tuyo? ¡Oh! ¡A no sher que quierash otro encarguito!"', 0),
(@ID, 'esMX', 'La caja mecánica se activa de repente y oyes sonidos de dientes que se pulverizan en su interior.$B$B"¡Ashí que lo hash conseguido! Esh una notishia excelente... Entonshesh... ¿Por qué no shiguesh con lo tuyo? ¡Oh! ¡A no sher que quierash otro encarguito!"', 0);
-- 1003 La caja mecánica 525
-- https://es.classic.wowhead.com/quest=1003
SET @ID := 1003;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que la caja mecánica 525 está cantando.$B$B"El vino de reptador esh dulce, la cerveza de trillador esh mejor y el licor de luna tiene un gran shabor. Pero nada hay másh reconfortante que la cerveza de Oso Cardo, ¡y pronto tendré una jarra en la mano!"$B$BLa cubierta está abierta y espera los 4 pellejos canosos mientras la caja mecánica repite su canción una y otra vez.', 0),
(@ID, 'esMX', 'Parece que la caja mecánica 525 está cantando.$B$B"El vino de reptador esh dulce, la cerveza de trillador esh mejor y el licor de luna tiene un gran shabor. Pero nada hay másh reconfortante que la cerveza de Oso Cardo, ¡y pronto tendré una jarra en la mano!"$B$BLa cubierta está abierta y espera los 4 pellejos canosos mientras la caja mecánica repite su canción una y otra vez.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"¿Ashí que metishte losh pellejosh? Esho esh eshtupendo... ¿Qué? Ah, eshte.. claro, te hash dado cuenta de puedo hablar contigo shin losh materialesh en la máquina, te mentí un poco. ¡Pero eshtaba diciendo la verdad cuando te dije que estaban rotash!$B$BEsh que, verásh, ademásh de sher herramientash de comunicación, lash cajash mecánicash deshtilan un licor eshtupendo. Shiento haberte engañado, pero esh que a losh elfosh de la noche no lesh gushta que mi licor pashe por shu ciudad. Pushe algo eshpecial en eshta caja para demoshtrarte mi gratitud por tush eshfuerzosh. ¡Que te gushte!"', 0),
(@ID, 'esMX', '"¿Ashí que metishte losh pellejosh? Esho esh eshtupendo... ¿Qué? Ah, eshte.. claro, te hash dado cuenta de puedo hablar contigo shin losh materialesh en la máquina, te mentí un poco. ¡Pero eshtaba diciendo la verdad cuando te dije que estaban rotash!$B$BEsh que, verásh, ademásh de sher herramientash de comunicación, lash cajash mecánicash deshtilan un licor eshtupendo. Shiento haberte engañado, pero esh que a losh elfosh de la noche no lesh gushta que mi licor pashe por shu ciudad. Pushe algo eshpecial en eshta caja para demoshtrarte mi gratitud por tush eshfuerzosh. ¡Que te gushte!"', 0);
-- 984 La extensión de la amenaza
-- https://es.classic.wowhead.com/quest=984
SET @ID := 984;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu búsqueda, $n?', 0),
(@ID, 'esMX', '¿Cómo va tu búsqueda, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una noticia terrible, $n.$B$BCon los furbolgs tan cerca de Auberdine, tendremos que prepararnos para lo inevitable.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'Es una noticia terrible, $n.$B$BCon los furbolgs tan cerca de Auberdine, tendremos que prepararnos para lo inevitable.$B$BGracias, $n.', 0);
-- 965 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=965
SET @ID := 965;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Elissa? Son buenas nuevas. Yo tengo noticias preocupantes que transmitirle y no he tenido forma de hacérselas llegar.', 0),
(@ID, 'esMX', '¿Te envía Elissa? Son buenas nuevas. Yo tengo noticias preocupantes que transmitirle y no he tenido forma de hacérselas llegar.', 0);
-- 2118 Tierras apestadas
-- https://es.classic.wowhead.com/quest=2118
SET @ID := 2118;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me has traído el animal enfermo, $n?$B$BSi no logras lanzar la trampa, no te preocupes: la esperanza de Tharnariun es eterna. Si necesitas otra trampa, vuelve y pídela.', 0),
(@ID, 'esMX', '¿Me has traído el animal enfermo, $n?$B$BSi no logras lanzar la trampa, no te preocupes: la esperanza de Tharnariun es eterna. Si necesitas otra trampa, vuelve y pídela.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro trabajo apenas ha empezado, $n. ¿Estás preparado para tu siguiente tarea?', 0),
(@ID, 'esMX', 'Nuestro trabajo apenas ha empezado, $n. ¿Estás preparado para tu siguiente tarea?', 0);
-- 948 Onus
-- https://es.classic.wowhead.com/quest=948
SET @ID := 948;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Estás aquí.$B$BBien.$B$BTenemos asuntos que discutir tú y yo.', 0),
(@ID, 'esMX', '$n. Estás aquí.$B$BBien.$B$BTenemos asuntos que discutir tú y yo.', 0);
-- 2138 La limpieza de la infección
-- https://es.classic.wowhead.com/quest=2138
SET @ID := 2138;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tu tarea está completa?', 0),
(@ID, 'esMX', '¿Tu tarea está completa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un gran servicio a Auberdine, $n, pero aún no has acabado tu cometido.$B$BDescansa un poco y vuelve.$B$BY..., $n, prepara tu mente y tu alma para más derramamientos de sangre.', 0),
(@ID, 'esMX', 'Has hecho un gran servicio a Auberdine, $n, pero aún no has acabado tu cometido.$B$BDescansa un poco y vuelve.$B$BY..., $n, prepara tu mente y tu alma para más derramamientos de sangre.', 0);
-- 985 La extensión de la amenaza
-- https://es.classic.wowhead.com/quest=985
SET @ID := 985;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No apartes tu mano de lo que se debe hacer, $gniño:niña;. Sé lo repulsiva que debe ser la idea de matar a las criaturas del bosque, pero en este caso es necesario. No se ha descubierto una cura para la corrupción desatada en el bosque, y debemos hacer lo que podamos para detener su progreso hasta que se encuentre una cura.', 0),
(@ID, 'esMX', 'No apartes tu mano de lo que se debe hacer, $gniño:niña;. Sé lo repulsiva que debe ser la idea de matar a las criaturas del bosque, pero en este caso es necesario. No se ha descubierto una cura para la corrupción desatada en el bosque, y debemos hacer lo que podamos para detener su progreso hasta que se encuentre una cura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Limpia la sangre de tu ropa, $n, y no sufras por lo que tuviste que hacer. Más bien tendrías que dar gracias. Has aliviado en parte los temores de las gentes de Auberdine, aunque Costa Oscura siga peligrando por los efectos del musgovil.', 0),
(@ID, 'esMX', 'Limpia la sangre de tu ropa, $n, y no sufras por lo que tuviste que hacer. Más bien tendrías que dar gracias. Has aliviado en parte los temores de las gentes de Auberdine, aunque Costa Oscura siga peligrando por los efectos del musgovil.', 0);
-- 4761 Thundris Tejevientos
-- https://es.classic.wowhead.com/quest=4761
SET @ID := 4761;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Tu exploración del campamento fúrbolg llega en un momento difícil para Auberdine. Durante un tiempo hemos lidiado no solo con los moradores del bosque, que ahora nos son abiertamente hostiles, sino también con la flagrante corrupción del propio bosque. Espero que puedas prestarnos tu ayuda en estos tiempos difíciles.', 0),
(@ID, 'esMX', 'Saludos, $c. Tu exploración del campamento fúrbolg llega en un momento difícil para Auberdine. Durante un tiempo hemos lidiado no solo con los moradores del bosque, que ahora nos son abiertamente hostiles, sino también con la flagrante corrupción del propio bosque. Espero que puedas prestarnos tu ayuda en estos tiempos difíciles.', 0);
-- 4762 El Río Fonroca
-- https://es.classic.wowhead.com/quest=4762
SET @ID := 4762;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción del Río Fonroca no es más que el principio de una alarmante situación en Costa Oscura. La muestra que nos has traído nos ayudará a idear un plan... y sospecho que tendrá que ser un plan de ataque.', 0),
(@ID, 'esMX', 'La corrupción del Río Fonroca no es más que el principio de una alarmante situación en Costa Oscura. La muestra que nos has traído nos ayudará a idear un plan... y sospecho que tendrá que ser un plan de ataque.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me sorprende que el agua esté tan contaminada, ¡pero fíjate cómo se está pudriendo! Diría que tendremos que actuar pronto, ¿no te parece, $n?$B$BAl este se encuentra Frondavil. Es la fuente de esta corrupción, una que he visto en otros tiempos. Sé que esta muestra lo confirmará. Quizás podamos encontrar una cura aquí, pero para intentarlo siquiera, necesitaremos ayuda. Cuando llegue el momento, $n, espero que puedas proporcionárnosla.', 0),
(@ID, 'esMX', 'No me sorprende que el agua esté tan contaminada, ¡pero fíjate cómo se está pudriendo! Diría que tendremos que actuar pronto, ¿no te parece, $n?$B$BAl este se encuentra Frondavil. Es la fuente de esta corrupción, una que he visto en otros tiempos. Sé que esta muestra lo confirmará. Quizás podamos encontrar una cura aquí, pero para intentarlo siquiera, necesitaremos ayuda. Cuando llegue el momento, $n, espero que puedas proporcionárnosla.', 0);
-- 2139 La esperanza de Tharnariun
-- https://es.classic.wowhead.com/quest=2139
SET @ID := 2139;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con la madre del cubil infectada asesinada, la población de osos cardos rabiosos que entran en nuestra tierra disminuye. No pierdas el tiempo, $n.', 0),
(@ID, 'esMX', 'Con la madre del cubil infectada asesinada, la población de osos cardos rabiosos que entran en nuestra tierra disminuye. No pierdas el tiempo, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has combatido por Auberdine con valentía y honor, $n. En estas tierras desgarradas por la guerra, la muerte y la desesperación son habituales. Y son muchos los que no se atreven a aceptar el desafío de vivir en nuestro nuevo hogar y eligen esconderse en sus casas o huir a las tierras mejor defendidas de la Alianza.$B$BGracias, $n. Uno de estos días combatiremos como camaradas contra otro enemigo.', 0),
(@ID, 'esMX', 'Has combatido por Auberdine con valentía y honor, $n. En estas tierras desgarradas por la guerra, la muerte y la desesperación son habituales. Y son muchos los que no se atreven a aceptar el desafío de vivir en nuestro nuevo hogar y eligen esconderse en sus casas o huir a las tierras mejor defendidas de la Alianza.$B$BGracias, $n. Uno de estos días combatiremos como camaradas contra otro enemigo.', 0);
-- 986 El maestro perdido
-- https://es.classic.wowhead.com/quest=986
SET @ID := 986;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi conciencia no me permite enviarte a buscar a Volcor hasta que te haya hecho la capa.', 0),
(@ID, 'esMX', 'Mi conciencia no me permite enviarte a buscar a Volcor hasta que te haya hecho la capa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas pieles son estupendas, $n. Empezaré a trabajar en la capa de inmediato.$B$BDame un momento y luego vuelve.$B$BAh, otra cosa: cuando hayas usado el hechizo en la capa, tu capacidad de interactuar con otros estará limitada. Si puedes, limítate a hablar, solo eso. Si haces algo más, podrías destruir la ilusión.', 0),
(@ID, 'esMX', 'Estas pieles son estupendas, $n. Empezaré a trabajar en la capa de inmediato.$B$BDame un momento y luego vuelve.$B$BAh, otra cosa: cuando hayas usado el hechizo en la capa, tu capacidad de interactuar con otros estará limitada. Si puedes, limítate a hablar, solo eso. Si haces algo más, podrías destruir la ilusión.', 0);
-- 966 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=966
SET @ID := 966;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado algún pergamino más? Si consigues encontrarlos, podría hacerme una idea más completa de lo que planean.', 0),
(@ID, 'esMX', '¿Has encontrado algún pergamino más? Si consigues encontrarlos, podría hacerme una idea más completa de lo que planean.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. Esto debería arrojar algo de luz sobre esta reunión de brujos...$B$BMmm...el Culto de la Facción Oscura... Nunca había oído hablar de este culto. Es imposible saber qué planes tienen sin conocer su historia.$B$BNo hay tiempo que perder. Hay que enviar un aviso a Delgren de inmediato.', 0),
(@ID, 'esMX', 'Muchas gracias, $n. Esto debería arrojar algo de luz sobre esta reunión de brujos...$B$BMmm...el Culto de la Facción Oscura... Nunca había oído hablar de este culto. Es imposible saber qué planes tienen sin conocer su historia.$B$BNo hay tiempo que perder. Hay que enviar un aviso a Delgren de inmediato.', 0);
-- 967 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=967
SET @ID := 967;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres algo de mí, $c?', 0),
(@ID, 'esMX', '¿Quieres algo de mí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perdona que te lo diga, pero estás muy bien equipado para ser mensajero, ¿no? Supongo que Balthule quería asegurarse de que su carta llegaba a mis manos. Veamos qué dice...$B$BSon noticias desalentadoras. Cuando aparecen fuerzas de no-muertos y de demonios, ayudo a las Centinelas a destruirlas.$B$BTardé en acostumbrarme a los modos de los elfos de la noche, pero he llegado a respetarlos como aliados.', 0),
(@ID, 'esMX', 'Perdona que te lo diga, pero estás muy bien equipado para ser mensajero, ¿no? Supongo que Balthule quería asegurarse de que su carta llegaba a mis manos. Veamos qué dice...$B$BSon noticias desalentadoras. Cuando aparecen fuerzas de no-muertos y de demonios, ayudo a las Centinelas a destruirlas.$B$BTardé en acostumbrarme a los modos de los elfos de la noche, pero he llegado a respetarlos como aliados.', 0);
-- 4763 La corrupción de los Bosque Negro
-- https://es.classic.wowhead.com/quest=4763
SET @ID := 4763;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El talismán de Corrupción es un siniestro instrumento que solo sirve para enturbiar el equilibrio de la naturaleza. Arrebata este objeto al sátiro que está atormentando a los furbolgs y tráemelo. Cuando yo lo haya destruido, ¡habremos ganado una importante batalla!', 0),
(@ID, 'esMX', 'El talismán de Corrupción es un siniestro instrumento que solo sirve para enturbiar el equilibrio de la naturaleza. Arrebata este objeto al sátiro que está atormentando a los furbolgs y tráemelo. Cuando yo lo haya destruido, ¡habremos ganado una importante batalla!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apenas hemos comenzado la guerra para arrebatar nuestro bosque a las fuerzas de la corrupción, ¡pero hoy hemos ganado una batalla! $n, las gentes de Auberdine tienen una deuda contigo que no podrá pagarse fácilmente. Por favor, acepta esto con nuestro agradecimiento. Lo que hemos aprendido hoy aquí, en un futuro podría liberar a nuestros amigos furbolgs de los grilletes del tormento eterno.', 0),
(@ID, 'esMX', 'Apenas hemos comenzado la guerra para arrebatar nuestro bosque a las fuerzas de la corrupción, ¡pero hoy hemos ganado una batalla! $n, las gentes de Auberdine tienen una deuda contigo que no podrá pagarse fácilmente. Por favor, acepta esto con nuestro agradecimiento. Lo que hemos aprendido hoy aquí, en un futuro podría liberar a nuestros amigos furbolgs de los grilletes del tormento eterno.', 0);
