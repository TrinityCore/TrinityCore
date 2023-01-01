-- 2853 Maestro de cuero salvaje
-- https://es.classic.wowhead.com/quest=2853
SET @ID := 2853;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $r... por tu rostro puedo decirte que eres $gpeletero:peletera; como yo. ¿Has venido a sacar provecho de mis habilidades, o quizás tienes otros asuntos conmigo?', 0),
(@ID, 'esMX', 'Saludos, $r... por tu rostro puedo decirte que eres $gpeletero:peletera; como yo. ¿Has venido a sacar provecho de mis habilidades, o quizás tienes otros asuntos conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, te envió Pratt. Aunque es un humano, a veces me recuerda a los elfos de la noche. Su dedicación y su talento con el cuero son impresionantes. Que él te felicite en esta carta, es una señal de respeto que reconozco.$B$BSoy consciente de que te ha enseñado el arte del cuero salvaje. Permíteme terminar tu entrenamiento con este patrón. Haz un buen uso del mismo; pocos en el mundo conocen los secretos de las capas de cuero salvaje.', 0),
(@ID, 'esMX', 'Ah, sí, te envió Pratt. Aunque es un humano, a veces me recuerda a los elfos de la noche. Su dedicación y su talento con el cuero son impresionantes. Que él te felicite en esta carta, es una señal de respeto que reconozco.$B$BSoy consciente de que te ha enseñado el arte del cuero salvaje. Permíteme terminar tu entrenamiento con este patrón. Haz un buen uso del mismo; pocos en el mundo conocen los secretos de las capas de cuero salvaje.', 0);
-- 2854 Armadura de cuero salvaje
-- https://es.classic.wowhead.com/quest=2854
SET @ID := 2854;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dejemos una cosa clara: tú serás mi aprendiz mientras aprendes el arte de la armadura de cuero salvaje. La atriplex salvaje es poderosa pero también caótica, por eso imbuye una gran mejora aleatoria a la armadura que harás, que de por sí, será fuerte. Has de saber que a mí no me fue fácil adquirir este conocimiento.$B$BEl coste inicial para empezar este proceso es de 10 piezas de cuero pesado.$B$BUna vez reunidas, empezaremos con el trabajo que tendrás que hacer para obtener los patrones.', 0),
(@ID, 'esMX', 'Dejemos una cosa clara: tú serás mi aprendiz mientras aprendes el arte de la armadura de cuero salvaje. La atriplex salvaje es poderosa pero también caótica, por eso imbuye una gran mejora aleatoria a la armadura que harás, que de por sí, será fuerte. Has de saber que a mí no me fue fácil adquirir este conocimiento.$B$BEl coste inicial para empezar este proceso es de 10 piezas de cuero pesado.$B$BUna vez reunidas, empezaremos con el trabajo que tendrás que hacer para obtener los patrones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, $n, me alegro de tenerte como aprendiz. Has tomado una buena decisión como $gpeletero:peletera;, quienes llevan armaduras de cuero te aclamarán cuando domines el arte del cuero salvaje.$B$BPongámonos a trabajar, ¿por dónde quieres empezar?', 0),
(@ID, 'esMX', 'Bien, $n, me alegro de tenerte como aprendiz. Has tomado una buena decisión como $gpeletero:peletera;, quienes llevan armaduras de cuero te aclamarán cuando domines el arte del cuero salvaje.$B$BPongámonos a trabajar, ¿por dónde quieres empezar?', 0);
-- 2855 Sobrehombros de cuero salvaje
-- https://es.classic.wowhead.com/quest=2855
SET @ID := 2855;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los seis refuerzos de armadura gruesa y la atriplex salvaje que necesito?$B$BPiensa en hacer refuerzos de armadura como una lección de artesanía estable y confiable; el método de modelado que desarrollas a medida que ejerces tu oficio en estos refuerzos ayuda a desarrollar tus habilidades para el complicado trabajo necesario para hacer armaduras de cuero salvaje.$B$BCada lección tiene un propósito, $n. Es importante abrazar cada uno en consecuencia.', 0),
(@ID, 'esMX', '¿Tienes los seis refuerzos de armadura gruesa y la atriplex salvaje que necesito?$B$BPiensa en hacer refuerzos de armadura como una lección de artesanía estable y confiable; el método de modelado que desarrollas a medida que ejerces tu oficio en estos refuerzos ayuda a desarrollar tus habilidades para el complicado trabajo necesario para hacer armaduras de cuero salvaje.$B$BCada lección tiene un propósito, $n. Es importante abrazar cada uno en consecuencia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos kits de armadura son de calidad sólida, $n. Si hay algo que exijo no solo en mi trabajo, sino en el trabajo de aquellos a quienes doy tutela, es calidad.$B$BHas hecho bien en ganar este patrón; Espero que te traiga las recompensas que me ha traído.', 0),
(@ID, 'esMX', 'Estos kits de armadura son de calidad sólida, $n. Si hay algo que exijo no solo en mi trabajo, sino en el trabajo de aquellos a quienes doy tutela, es calidad.$B$BHas hecho bien en ganar este patrón; Espero que te traiga las recompensas que me ha traído.', 0);
-- 2856 El Jubón de cuero salvaje
-- https://es.classic.wowhead.com/quest=2856
SET @ID := 2856;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los dos petos y guantes de caparazón de tortuga? Además, ¡no te olvides de la atriplex!$B$BIncluso con los patrones más antiguos, aprendemos que los fundamentos de la forma se traducen bien en prendas más difíciles. Aunque son elementos diferentes, la forma de los petos de caparazón de tortuga te prepara para los detalles necesarios para hacer un jubón de cuero salvaje.$B$BA medida que avances en tus lecciones, tus habilidades se convertirán en arte.', 0),
(@ID, 'esMX', '¿Tienes los dos petos y guantes de caparazón de tortuga? Además, ¡no te olvides de la atriplex!$B$BIncluso con los patrones más antiguos, aprendemos que los fundamentos de la forma se traducen bien en prendas más difíciles. Aunque son elementos diferentes, la forma de los petos de caparazón de tortuga te prepara para los detalles necesarios para hacer un jubón de cuero salvaje.$B$BA medida que avances en tus lecciones, tus habilidades se convertirán en arte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son algunas piezas muy bonitas, $n. La artesanía y el cuidado puesto en hacerlos demuestran que has elegido dedicarte de lleno a estas tareas.$B$BHas cumplido mis peticiones y con eso viene tu recompensa. ¡El conocimiento de la fabricación de jubones de cuero salvaje ahora es tuyo!', 0),
(@ID, 'esMX', 'Estas son algunas piezas muy bonitas, $n. La artesanía y el cuidado puesto en hacerlos demuestran que has elegido dedicarte de lleno a estas tareas.$B$BHas cumplido mis peticiones y con eso viene tu recompensa. ¡El conocimiento de la fabricación de jubones de cuero salvaje ahora es tuyo!', 0);
-- 2857 Casco de cuero salvaje
-- https://es.classic.wowhead.com/quest=2857
SET @ID := 2857;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito que me hagas esas guerreras y cintas de pelo, y también necesito ese trozo de atriplex salvaje antes de poder compartir contigo el conocimiento de los cascos de cuero salvaje.$B$BLos accesorios para la cabeza son muy codiciados entre los aventureros, ya sea una diadema simple o un casco que lo cubra por completo. Los fundamentos de la creación de un valioso equipo para la cabeza permanecen constantes, sin importar la apariencia estética del equipo.', 0),
(@ID, 'esMX', 'Necesito que me hagas esas guerreras y cintas de pelo, y también necesito ese trozo de atriplex salvaje antes de poder compartir contigo el conocimiento de los cascos de cuero salvaje.$B$BLos accesorios para la cabeza son muy codiciados entre los aventureros, ya sea una diadema simple o un casco que lo cubra por completo. Los fundamentos de la creación de un valioso equipo para la cabeza permanecen constantes, sin importar la apariencia estética del equipo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este equipo Nochefugaz que me has traido cumple perfectamente con los requisitos, $n. No espero menos de $gun peletero:una peletera; de tu calibre.$B$BTe has ganado el honor de fabricar cascos de cuero salvaje. Te doy este patrón gratuitamente y espero que te beneficies de él en consecuencia.', 0),
(@ID, 'esMX', 'Este equipo Nochefugaz que me has traido cumple perfectamente con los requisitos, $n. No espero menos de $gun peletero:una peletera; de tu calibre.$B$BTe has ganado el honor de fabricar cascos de cuero salvaje. Te doy este patrón gratuitamente y espero que te beneficies de él en consecuencia.', 0);
-- 2858 Botas de cuero salvaje
-- https://es.classic.wowhead.com/quest=2858
SET @ID := 2858;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes entregarme los pantalones, las botas y las atriplex salvajes antes de que aprendas el patrón, $n. ¿Has hecho lo que te pedí?$B$BDesde el primer par de botas que aprendemos a fabricar, comenzamos a comprender que una bota de calidad necesita ir al filo de la navaja entre comodidad y funcionalidad. Con ambos, podemos crear artículos que permiten al usuario ignorar la fatiga que paralizaría a quienes usan artículos de menor calidad.', 0),
(@ID, 'esMX', 'Debes entregarme los pantalones, las botas y las atriplex salvajes antes de que aprendas el patrón, $n. ¿Has hecho lo que te pedí?$B$BDesde el primer par de botas que aprendemos a fabricar, comenzamos a comprender que una bota de calidad necesita ir al filo de la navaja entre comodidad y funcionalidad. Con ambos, podemos crear artículos que permiten al usuario ignorar la fatiga que paralizaría a quienes usan artículos de menor calidad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez más, has completado un pedido complejo con la habilidad de $gun profesional experimentado:una profesional experimentada;. Te has ganado este patrón, así como mis felicitaciones.', 0),
(@ID, 'esMX', 'Una vez más, has completado un pedido complejo con la habilidad de $gun profesional experimentado:una profesional experimentada;. Te has ganado este patrón, así como mis felicitaciones.', 0);
-- 2859 Leotardos de cuero salvaje
-- https://es.classic.wowhead.com/quest=2859
SET @ID := 2859;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes listos los yelmos y los brazales de caparazón de tortuga ? ¡No olvides las dos atriplex salvajes que requiero!$B$BA estas alturas, estás empezando a darte cuenta del poder potencial que tiene la armadura de cuero salvaje. Una armadura que no tiene límites en la aplicación es de valor incalculable para un peletero. Los límites están solo en la cantidad de recursos para fabricar los artículos, ¡no en la calidad de los productos terminados!', 0),
(@ID, 'esMX', '¿Tienes listos los yelmos y los brazales de caparazón de tortuga ? ¡No olvides las dos atriplex salvajes que requiero!$B$BA estas alturas, estás empezando a darte cuenta del poder potencial que tiene la armadura de cuero salvaje. Una armadura que no tiene límites en la aplicación es de valor incalculable para un peletero. Los límites están solo en la cantidad de recursos para fabricar los artículos, ¡no en la calidad de los productos terminados!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuevamente, has completado mi tarea sin problemas. Quizás algún día vendré a ti en busca de conocimiento, ¿eh $n?$B$BAquí está el patrón de los leotardos, junto con mi agradecimiento. ¡Aplica este conocimiento y deja que tus productos terminados aprovechen tus impresionantes habilidades!', 0),
(@ID, 'esMX', 'Nuevamente, has completado mi tarea sin problemas. Quizás algún día vendré a ti en busca de conocimiento, ¿eh $n?$B$BAquí está el patrón de los leotardos, junto con mi agradecimiento. ¡Aplica este conocimiento y deja que tus productos terminados aprovechen tus impresionantes habilidades!', 0);
-- 2860 Maestro de cuero salvaje
-- https://es.classic.wowhead.com/quest=2860
SET @ID := 2860;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $r... por tu rostro puedo decirte que eres $gpeletero:peletera; como yo. ¿Has venido a sacar provecho de mis habilidades, o quizás tienes otros asuntos conmigo?', 0),
(@ID, 'esMX', 'Saludos, $r... por tu rostro puedo decirte que eres $gpeletero:peletera; como yo. ¿Has venido a sacar provecho de mis habilidades, o quizás tienes otros asuntos conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, te envió Jangdor. Me complace ver que uno de mis mejores estudiantes ahora tiene un estudiante propio.$B$BSu dedicación y su talento con el cuero son impresionantes. Que él te felicite en esta carta, es una señal de respeto que reconozco.$B$BSoy consciente de que te ha enseñado el arte del cuero salvaje. Permíteme terminar tu entrenamiento con este patrón. Haz un buen uso del mismo; pocos en el mundo conocen los secretos de las capas de cuero salvaje.', 0),
(@ID, 'esMX', 'Ah, sí, te envió Jangdor. Me complace ver que uno de mis mejores estudiantes ahora tiene un estudiante propio.$B$BSu dedicación y su talento con el cuero son impresionantes. Que él te felicite en esta carta, es una señal de respeto que reconozco.$B$BSoy consciente de que te ha enseñado el arte del cuero salvaje. Permíteme terminar tu entrenamiento con este patrón. Haz un buen uso del mismo; pocos en el mundo conocen los secretos de las capas de cuero salvaje.', 0);
-- 2862 En guerra con los Zarpaleña
-- https://es.classic.wowhead.com/quest=2862
SET @ID := 2862;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los hacemos retroceder y aún así, siguen atacando! Alguien o algo debe de estar arrastrándoles a este frenesí... Ah, $n, ¿ya estás de vuelta? ¿Tienes las cabelleras necesarias para la recompensa?', 0),
(@ID, 'esMX', '¡Los hacemos retroceder y aún así, siguen atacando! Alguien o algo debe de estar arrastrándoles a este frenesí... Ah, $n, ¿ya estás de vuelta? ¿Tienes las cabelleras necesarias para la recompensa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es un buen comienzo, $n. Tus habilidades de combate son encomiables.$B$BY no eres $gel primero al:la primera a la; que he asignado esta misión. Muchos antes que tú han combatido contra ellos. Nuestros esfuerzos los han mantenido a raya hasta ahora. Pero últimamente, sus intentos de avanzar hacia el norte por nuestra tierra, se han redoblado. Y sus ataques son cada vez más salvajes... casi como si estuvieran desesperados.$B$BPero yo tengo un plan que podría solucionar esto de una vez por todas.', 0),
(@ID, 'esMX', 'Esto es un buen comienzo, $n. Tus habilidades de combate son encomiables.$B$BY no eres $gel primero al:la primera a la; que he asignado esta misión. Muchos antes que tú han combatido contra ellos. Nuestros esfuerzos los han mantenido a raya hasta ahora. Pero últimamente, sus intentos de avanzar hacia el norte por nuestra tierra, se han redoblado. Y sus ataques son cada vez más salvajes... casi como si estuvieran desesperados.$B$BPero yo tengo un plan que podría solucionar esto de una vez por todas.', 0);
-- 2863 Ataca a los Alfas
-- https://es.classic.wowhead.com/quest=2863
SET @ID := 2863;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El tiempo se acaba, $n! Si no estás aquí para informar que has eliminado a los Alfa, ¡estás perdiendo el tiempo!', 0),
(@ID, 'esMX', '¡El tiempo se acaba, $n! Si no estás aquí para informar que has eliminado a los Alfa, ¡estás perdiendo el tiempo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú has hecho lo que te pedí y te aplaudo por ello. Acepta esta pequeña recompensa como premio por tus esfuerzos, $n.$B$BAhora que sus líderes han muerto y hemos diezmado su número, se lo pensarán dos veces antes de irrumpir en el campamento. Pero eso no soluciona el problema.$B$BDebe de haber un motivo para que los gnolls hayan enloquecido. Y antes de que tengan tiempo de reagruparse, tenemos que averiguar qué es lo que causa su locura.', 0),
(@ID, 'esMX', 'Tú has hecho lo que te pedí y te aplaudo por ello. Acepta esta pequeña recompensa como premio por tus esfuerzos, $n.$B$BAhora que sus líderes han muerto y hemos diezmado su número, se lo pensarán dos veces antes de irrumpir en el campamento. Pero eso no soluciona el problema.$B$BDebe de haber un motivo para que los gnolls hayan enloquecido. Y antes de que tengan tiempo de reagruparse, tenemos que averiguar qué es lo que causa su locura.', 0);
-- 2864 Tran'rek
-- https://es.classic.wowhead.com/quest=2864
SET @ID := 2864;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola!$B$BOh, ¿hablaste con mi primo Krazek? ¿Cómo está? Espero que le vaya bien en Bahía del Botín...$B$B¿Caparazones de escarabajo dices? Bien... cuéntame tu historia...', 0),
(@ID, 'esMX', '¡Hola!$B$BOh, ¿hablaste con mi primo Krazek? ¿Cómo está? Espero que le vaya bien en Bahía del Botín...$B$B¿Caparazones de escarabajo dices? Bien... cuéntame tu historia...', 0);
-- 2866 Las Ruinas de Solarsal
-- https://es.classic.wowhead.com/quest=2866
SET @ID := 2866;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un examen minucioso de la glorieta revela tres cosas interesantes y poco habituales que contrastan con las ruinas que la rodean.$B$BPrimero, la glorieta es evidentemente más reciente que las demás estructuras de las ruinas. Segundo, tiene una serie de glifos pequeños grabados en los lados. Los glifos parecen repetirse, pero su significado y su origen son desconocidos. Tercero, la piedra de la glorieta está caliente al tacto.$B$B¡Esto es sin duda algo que "llama la atención"!', 0),
(@ID, 'esMX', 'Un examen minucioso de la glorieta revela tres cosas interesantes y poco habituales que contrastan con las ruinas que la rodean.$B$BPrimero, la glorieta es evidentemente más reciente que las demás estructuras de las ruinas. Segundo, tiene una serie de glifos pequeños grabados en los lados. Los glifos parecen repetirse, pero su significado y su origen son desconocidos. Tercero, la piedra de la glorieta está caliente al tacto.$B$B¡Esto es sin duda algo que "llama la atención"!', 0);
-- 2867 Regresa al Bastión Plumaluna
-- https://es.classic.wowhead.com/quest=2867
SET @ID := 2867;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida;, $n. Tu informe sobre la glorieta es... preocupante. Parece que, aunque los naga no estuvieran planeando un ataque, su presencia es una mala señal para nuestra ofensiva en Feralas. En cualquier caso, aquí tienes tu compensación por tu servicio.$B$BParece que el Bastión Plumaluna necesita desesperadamente ayuda con el problema de los naga Crestafuria. Quisiera ofrecerte a ti la misión, si te parece. Hay mucho que hacer.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida;, $n. Tu informe sobre la glorieta es... preocupante. Parece que, aunque los naga no estuvieran planeando un ataque, su presencia es una mala señal para nuestra ofensiva en Feralas. En cualquier caso, aquí tienes tu compensación por tu servicio.$B$BParece que el Bastión Plumaluna necesita desesperadamente ayuda con el problema de los naga Crestafuria. Quisiera ofrecerte a ti la misión, si te parece. Hay mucho que hacer.', 0);
-- 2869 En contra de los Crestafuria
-- https://es.classic.wowhead.com/quest=2869
SET @ID := 2869;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, si estás aquí para que te confirme la tarea que te ha sido asignada, excelente. Te confirmo que quiero 10 escamas de Crestafuria. Si has venido a charlar, te informo de que en estos momentos no estoy disponible para trivialidades.$B$BDebes saber algo: los elfos de la noche no somos belicistas. Nuestra raza dedica su tiempo a preservar la paz y la armonía. Pero eso no quiere decir que no sepamos proteger nuestros intereses. Ese es mi deber para con la general Plumaluna y el Bastión.', 0),
(@ID, 'esMX', '$n, si estás aquí para que te confirme la tarea que te ha sido asignada, excelente. Te confirmo que quiero 10 escamas de Crestafuria. Si has venido a charlar, te informo de que en estos momentos no estoy disponible para trivialidades.$B$BDebes saber algo: los elfos de la noche no somos belicistas. Nuestra raza dedica su tiempo a preservar la paz y la armonía. Pero eso no quiere decir que no sepamos proteger nuestros intereses. Ese es mi deber para con la general Plumaluna y el Bastión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí, estas escamas son más que satisfactorias. De hecho, creo que se las enviaré a Pratt, para que les eche un ojo. Quizás pueda hacer algo útil con ellas.$B$BEn cuanto a ti, tengo otra misión que encomendarte. Pero antes, aquí tienes tu recompensa por las escamas. Tu servicio a la general Plumaluna y al Bastión en su conjunto es una bendición en estos tiempos adversos.', 0),
(@ID, 'esMX', 'Sí, sí, estas escamas son más que satisfactorias. De hecho, creo que se las enviaré a Pratt, para que les eche un ojo. Quizás pueda hacer algo útil con ellas.$B$BEn cuanto a ti, tengo otra misión que encomendarte. Pero antes, aquí tienes tu recompensa por las escamas. Tu servicio a la general Plumaluna y al Bastión en su conjunto es una bendición en estos tiempos adversos.', 0);
-- 2870 En contra de Lord Shalzaru
-- https://es.classic.wowhead.com/quest=2870
SET @ID := 2870;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eliminando a Lord Shalzaru retrasaríamos sus planes semanas, incluso meses. Además, la reliquia que descubrió nos interesa.$B$B¿Has cumplido la misión que te fue asignada, $n?', 0),
(@ID, 'esMX', 'Eliminando a Lord Shalzaru retrasaríamos sus planes semanas, incluso meses. Además, la reliquia que descubrió nos interesa.$B$B¿Has cumplido la misión que te fue asignada, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien, $n! La muerte de Lord Shalzaru desconcertará a los naga durante un tiempo, si no para siempre. La amenaza que suponen ahora está más descontrolada que nunca, y eso te lo debemos a ti.$B$BAquí tienes más dinero del tesoro del Bastión. Te has ganado cada pieza. Tú y los tuyos sois siempre bienvenidos en el Bastión Plumaluna, $gamigo:amiga;.$B$BUna cosita más, antes de que te vayas, $n... si pudieras...', 0),
(@ID, 'esMX', '¡Bien, $n! La muerte de Lord Shalzaru desconcertará a los naga durante un tiempo, si no para siempre. La amenaza que suponen ahora está más descontrolada que nunca, y eso te lo debemos a ti.$B$BAquí tienes más dinero del tesoro del Bastión. Te has ganado cada pieza. Tú y los tuyos sois siempre bienvenidos en el Bastión Plumaluna, $gamigo:amiga;.$B$BUna cosita más, antes de que te vayas, $n... si pudieras...', 0);
-- 2871 Entrega la reliquia
-- https://es.classic.wowhead.com/quest=2871
SET @ID := 2871;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Puedo ayudarte?$B$BEspera, tú eres $gel:la; $c que ha estado ayudando a la general Plumaluna y a Latro con la amenaza naga, ¿no es así? Yo soy Vestia, la mujer de Latro... bueno, de Latronicus. ¡Es un placer conocerte!$B$BPerdona que hable tanto. Tú estás aquí por negocios, supongo. ¿Traes algo para mí... de él?', 0),
(@ID, 'esMX', '¿Sí? ¿Puedo ayudarte?$B$BEspera, tú eres $gel:la; $c que ha estado ayudando a la general Plumaluna y a Latro con la amenaza naga, ¿no es así? Yo soy Vestia, la mujer de Latro... bueno, de Latronicus. ¡Es un placer conocerte!$B$BPerdona que hable tanto. Tú estás aquí por negocios, supongo. ¿Traes algo para mí... de él?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Interesante... ¿Y dices que viene de las Ruinas de Solarsal? Pues Latro tiene razón, tengo que mirar esto. A primera vista, no parece pertenecer a las ruinas. Y tampoco es de fabricación naga... no harían algo tan extraño como esto.$B$BMe va a llevar algún tiempo estudiar este objeto. Cuando haya acabado, quizás pueda hacer uso de tus talentos, si andas por aquí.$B$BTen, acepta este objeto. No lo necesitamos, pero espero que tú le des un buen uso.', 0),
(@ID, 'esMX', 'Interesante... ¿Y dices que viene de las Ruinas de Solarsal? Pues Latro tiene razón, tengo que mirar esto. A primera vista, no parece pertenecer a las ruinas. Y tampoco es de fabricación naga... no harían algo tan extraño como esto.$B$BMe va a llevar algún tiempo estudiar este objeto. Cuando haya acabado, quizás pueda hacer uso de tus talentos, si andas por aquí.$B$BTen, acepta este objeto. No lo necesitamos, pero espero que tú le des un buen uso.', 0);
-- 2872 La deuda de Stoley
-- https://es.classic.wowhead.com/quest=2872
SET @ID := 2872;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, has estado hablando con MacKinley, ¿no es cierto?$B$B¡No es lo que él piensa! No tengo miedo de dejarle probar el ron de la sentina Bonvapor...$B$B¡Simplemente no me queda ni gota!', 0),
(@ID, 'esMX', 'Ah, has estado hablando con MacKinley, ¿no es cierto?$B$B¡No es lo que él piensa! No tengo miedo de dejarle probar el ron de la sentina Bonvapor...$B$B¡Simplemente no me queda ni gota!', 0);
-- 2876 El registro náutico
-- https://es.classic.wowhead.com/quest=2876
SET @ID := 2876;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces $gsofocado:sofocada;. ¿Tienes algo que contarme?', 0),
(@ID, 'esMX', 'Pareces $gsofocado:sofocada;. ¿Tienes algo que contarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo creerlo, ¡es una lista de todas las salidas y llegadas de barcos, con sus respectivas fechas, horas y todo! Si cayera en manos del capitán de un barco pirata, ¡este haría su agosto!$B$B¿Y dices que la conseguiste de un pirata? Vaya...$B$BGracias, $n. Me alegro de que se la hayas quitado y también de que le hicieras morder el polvo.', 0),
(@ID, 'esMX', 'No puedo creerlo, ¡es una lista de todas las salidas y llegadas de barcos, con sus respectivas fechas, horas y todo! Si cayera en manos del capitán de un barco pirata, ¡este haría su agosto!$B$B¿Y dices que la conseguiste de un pirata? Vaya...$B$BGracias, $n. Me alegro de que se la hayas quitado y también de que le hicieras morder el polvo.', 0);
-- 2877 La limpieza de Roca Oculta
-- https://es.classic.wowhead.com/quest=2877
SET @ID := 2877;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te esfuerces por negociar la misión que tienes entre manos, $r! Si los dioses hubieran querido que mataran a esos lodos, ya habrían hecho el milagro, ¿no es así?', 0),
(@ID, 'esMX', '¡No te esfuerces por negociar la misión que tienes entre manos, $r! Si los dioses hubieran querido que mataran a esos lodos, ya habrían hecho el milagro, ¿no es así?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que los Martillo Salvaje valoramos es la acción, $c.$B$BTu misión es mucho más importante de lo que crees. Si reducimos el número de mocos y lodos, podremos expandir nuestra zona de influencia. Ten; además de nuevos amigos, te has ganado una recompensa.', 0),
(@ID, 'esMX', 'Lo que los Martillo Salvaje valoramos es la acción, $c.$B$BTu misión es mucho más importante de lo que crees. Si reducimos el número de mocos y lodos, podremos expandir nuestra zona de influencia. Ten; además de nuevos amigos, te has ganado una recompensa.', 0);
-- 2879 El báculo de Equinex
-- https://es.classic.wowhead.com/quest=2879
SET @ID := 2879;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Monolito de Equinex se yergue silencioso entre las ruinas. ¿Qué contendrá?', 0),
(@ID, 'esMX', 'El Monolito de Equinex se yergue silencioso entre las ruinas. ¿Qué contendrá?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sostener el bastón energizado es casi imposible. Su poder retumba por tu cuerpo.$B$BExtiendes la mano hacia la fría superficie del Monolito de Equinex...$B$BSe abre una pequeña puerta que te permite sacar el artefacto del interior.$B$BUnos rayos de luz inundan la zona que rodea al Monolito de Equinex.', 0),
(@ID, 'esMX', 'Sostener el bastón energizado es casi imposible. Su poder retumba por tu cuerpo.$B$BExtiendes la mano hacia la fría superficie del Monolito de Equinex...$B$BSe abre una pequeña puerta que te permite sacar el artefacto del interior.$B$BUnos rayos de luz inundan la zona que rodea al Monolito de Equinex.', 0);
-- 2880 Los collares de trols
-- https://es.classic.wowhead.com/quest=2880
SET @ID := 2880;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quiero 5 collares tribales trol. Y la forma más efectiva y segura de quitárselos es matarlos.$B$B¡Demuestra lo que vales a los Martillo Salvaje!', 0),
(@ID, 'esMX', 'Quiero 5 collares tribales trol. Y la forma más efectiva y segura de quitárselos es matarlos.$B$B¡Demuestra lo que vales a los Martillo Salvaje!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con estos collares nos demuestras tu valor; los Martillo Salvaje apreciamos el coraje.$B$BSigue así y llegarás lejos.', 0),
(@ID, 'esMX', 'Con estos collares nos demuestras tu valor; los Martillo Salvaje apreciamos el coraje.$B$BSigue así y llegarás lejos.', 0);
-- 2881 Los collares de trols
-- https://es.classic.wowhead.com/quest=2881
SET @ID := 2881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya has cumplido tu misión, pero aceptaremos todos los collares tribales que nos traigas; así seguirás ganando méritos ante los Martillo Salvaje.$B$BTrae 5 collares tribales, $n.', 0),
(@ID, 'esMX', 'Ya has cumplido tu misión, pero aceptaremos todos los collares tribales que nos traigas; así seguirás ganando méritos ante los Martillo Salvaje.$B$BTrae 5 collares tribales, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien, ya hay menos trols de los que preocuparnos! Buen trabajo, $n. ¡Sigue así!', 0),
(@ID, 'esMX', '¡Bien, ya hay menos trols de los que preocuparnos! Buen trabajo, $n. ¡Sigue así!', 0);
-- 2882 El oro de Cuergo
-- https://es.classic.wowhead.com/quest=2882
SET @ID := 2882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Este cofre está cerrado!', 0),
(@ID, 'esMX', '¡Este cofre está cerrado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El tesoro escondido del capitán Cuergo aguarda!', 0),
(@ID, 'esMX', '¡El tesoro escondido del capitán Cuergo aguarda!', 0);
-- 2902 Investiga a los Zarpaleña
-- https://es.classic.wowhead.com/quest=2902
SET @ID := 2902;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un examen del mapa revela que es el plan de ataque que quiere Hadoken Zancoveloz. Hay muchas flechas que probablemente representan movimientos de tropas. La mayoría parecen dirigirse hacia el sur, no al norte, que es donde se encuentra el Campamento Mojache.$B$BEn otra sección del mapa hay un dibujo de lo que parece ser una especie de insecto enorme, con varias marcas debajo. Por el aspecto de los gnolls, puede que represente las bajas que esos insectos desconocidos han causado en sus filas...', 0),
(@ID, 'esMX', 'Un examen del mapa revela que es el plan de ataque que quiere Hadoken Zancoveloz. Hay muchas flechas que probablemente representan movimientos de tropas. La mayoría parecen dirigirse hacia el sur, no al norte, que es donde se encuentra el Campamento Mojache.$B$BEn otra sección del mapa hay un dibujo de lo que parece ser una especie de insecto enorme, con varias marcas debajo. Por el aspecto de los gnolls, puede que represente las bajas que esos insectos desconocidos han causado en sus filas...', 0);
-- 2903 Los planes de batalla
-- https://es.classic.wowhead.com/quest=2903
SET @ID := 2903;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has conseguido encontrar pruebas físicas de los planes de los gnolls?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Has conseguido encontrar pruebas físicas de los planes de los gnolls?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, esto es exactamente lo que necesitamos. No se me da muy bien descifrar los garabatos de este mapa, pero he visto suficientes planes de ataque en mi vida para entender lo que está pasando con los gnolls. Parece que están combatiendo en dos frentes. En uno de ellos, combaten contra nosotros... pero parece que han concentrado la mayoría de sus energías en combatir a su enemigo del sur.$B$BEsto podría ser importante. Quizás sea el momento de averiguar quién es ese otro enemigo.', 0),
(@ID, 'esMX', 'Ah, esto es exactamente lo que necesitamos. No se me da muy bien descifrar los garabatos de este mapa, pero he visto suficientes planes de ataque en mi vida para entender lo que está pasando con los gnolls. Parece que están combatiendo en dos frentes. En uno de ellos, combaten contra nosotros... pero parece que han concentrado la mayoría de sus energías en combatir a su enemigo del sur.$B$BEsto podría ser importante. Quizás sea el momento de averiguar quién es ese otro enemigo.', 0);
-- 2904 Un buen lío
-- https://es.classic.wowhead.com/quest=2904
SET @ID := 2904;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eh? ¿¿Kernobee está vivo??', 0),
(@ID, 'esMX', '¿Eh? ¿¿Kernobee está vivo??', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mereces una recompensa por habernos traído a Kernobee, $n. Esto te ayudará a derrotar a ese traidor miserable que es el mekigeniero Termochufe si vuelves a Gnomeregan.', 0),
(@ID, 'esMX', 'Mereces una recompensa por habernos traído a Kernobee, $n. Esto te ayudará a derrotar a ese traidor miserable que es el mekigeniero Termochufe si vuelves a Gnomeregan.', 0);
-- 2925 Klockmort Palmalicate
-- https://es.classic.wowhead.com/quest=2925
SET @ID := 2925;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pues sí, necesito a alguien para una misión en Gnomeregan. ¿Te interesa, $c?', 0),
(@ID, 'esMX', 'Pues sí, necesito a alguien para una misión en Gnomeregan. ¿Te interesa, $c?', 0);
-- 2931 Trabajar para Funditubo
-- https://es.classic.wowhead.com/quest=2931
SET @ID := 2931;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy organizando misiones a Gnomeregan. Si estás aquí por eso, escucha con atención.', 0),
(@ID, 'esMX', 'Estoy organizando misiones a Gnomeregan. Si estás aquí por eso, escucha con atención.', 0);
-- 2932 Un mensaje siniestro
-- https://es.classic.wowhead.com/quest=2932
SET @ID := 2932;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No has completado mi tarea, $n.', 0),
(@ID, 'esMX', 'No has completado mi tarea, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que has cumplido tu misión. Esperemos que los Secacorteza capten el mensaje.', 0),
(@ID, 'esMX', 'Sé que has cumplido tu misión. Esperemos que los Secacorteza capten el mensaje.', 0);
-- 2933 Botellas de veneno
-- https://es.classic.wowhead.com/quest=2933
SET @ID := 2933;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Hoy ha sido un día largo en el que todo ha ido mal. Espero que me traigas algo bueno.', 0),
(@ID, 'esMX', 'Saludos, $c. Hoy ha sido un día largo en el que todo ha ido mal. Espero que me traigas algo bueno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Parece veneno de arácnido... ¿De dónde sale?', 0),
(@ID, 'esMX', '¿Qué es esto? Parece veneno de arácnido... ¿De dónde sale?', 0);
