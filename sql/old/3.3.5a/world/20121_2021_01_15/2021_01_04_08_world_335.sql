-- 818 Un espíritu responsable
-- https://es.classic.wowhead.com/quest=818
SET @ID := 818;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo es quien realmente pondrá a prueba tu fuerza y tu voluntad. Si pierdes la paciencia o cedes a la debilidad, se revelará tu auténtico yo.', 0),
(@ID, 'esMX', 'El tiempo es quien realmente pondrá a prueba tu fuerza y tu voluntad. Si pierdes la paciencia o cedes a la debilidad, se revelará tu auténtico yo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, joven. Bien hecho.', 0),
(@ID, 'esMX', 'Bien hecho, joven. Bien hecho.', 0);
-- 819 El barril vacío de Chen
-- https://es.classic.wowhead.com/quest=819
SET @ID := 819;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, me...$B$BEste barril era uno de los de Chen Cerveza de Trueno. Viajaba con Rexxar hace mucho tiempo. Hace siglos que no lo veo ni sé nada de él. Te agradezco que me hayas traído esto, $n.', 0),
(@ID, 'esMX', 'Bueno, me...$B$BEste barril era uno de los de Chen Cerveza de Trueno. Viajaba con Rexxar hace mucho tiempo. Hace siglos que no lo veo ni sé nada de él. Te agradezco que me hayas traído esto, $n.', 0);
-- 821 El barril vacío de Chen
-- https://es.classic.wowhead.com/quest=821
SET @ID := 821;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la búsqueda?', 0),
(@ID, 'esMX', '¿Cómo va la búsqueda?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Jaja... Jamás creí que volvería a preparar esto.$B$BHas despertado una nostalgia muy profunda en mí, $n. En cierto modo, me recuerda a la última vez que preparé un lote de cerveza trogg. Gracias. Los recuerdos llenan mi estómago de calidez.', 0),
(@ID, 'esMX', 'Jaja... Jamás creí que volvería a preparar esto.$B$BHas despertado una nostalgia muy profunda en mí, $n. En cierto modo, me recuerda a la última vez que preparé un lote de cerveza trogg. Gracias. Los recuerdos llenan mi estómago de calidez.', 0);
-- 822 El barril vacío de Chen
-- https://es.classic.wowhead.com/quest=822
SET @ID := 822;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás trabajando mucho para encontrar esos ingredientes, $n?', 0),
(@ID, 'esMX', '¿Estás trabajando mucho para encontrar esos ingredientes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ea! Sabía que no te resistirías a este brebaje. Vuelve cuando quieras si quieres más, $n. Solo tienes que traerme más ingredientes como los que te pedí.', 0),
(@ID, 'esMX', '¡Ea! Sabía que no te resistirías a este brebaje. Vuelve cuando quieras si quieres más, $n. Solo tienes que traerme más ingredientes como los que te pedí.', 0);
-- 823 Informa a Orgnil
-- https://es.classic.wowhead.com/quest=823
SET @ID := 823;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí? ¿Tienes algún informe? ¡Pues adelante, informa!', 0),
(@ID, 'esMX', '¿Sí? ¿Tienes algún informe? ¡Pues adelante, informa!', 0);
-- 824 Je'neu del Anillo de la Tierra
-- https://es.classic.wowhead.com/quest=824
SET @ID := 824;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eh, hola. Me paso la mayor parte del tiempo estudiando el agua, en realidad todos los elementos, así que a veces ni me entero de que hay gente alrededor.$B$B¿Puedo hacer algo por ti?', 0),
(@ID, 'esMX', 'Eh, hola. Me paso la mayor parte del tiempo estudiando el agua, en realidad todos los elementos, así que a veces ni me entero de que hay gente alrededor.$B$B¿Puedo hacer algo por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este globo... es de lo más inquietante. Muchos de los más poderosos elementales reciben su poder y su energía a través de tales dispositivos. Encontrar uno como este casi intacto es una cosa… encontrar uno tan contaminado es otra historia.$B$BMe ocuparé de que el Anillo de la Tierra estudie debidamente este globo. Quizás logremos poner fin a esta corrupción de los elementos. Acepta esto a cambio de haber traído este globo a la atención del Anillo de la Tierra.', 0),
(@ID, 'esMX', 'Este globo... es de lo más inquietante. Muchos de los más poderosos elementales reciben su poder y su energía a través de tales dispositivos. Encontrar uno como este casi intacto es una cosa… encontrar uno tan contaminado es otra historia.$B$BMe ocuparé de que el Anillo de la Tierra estudie debidamente este globo. Quizás logremos poner fin a esta corrupción de los elementos. Acepta esto a cambio de haber traído este globo a la atención del Anillo de la Tierra.', 0);
-- 825 Los restos del naufragio...
-- https://es.classic.wowhead.com/quest=825
SET @ID := 825;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando sepamos cómo funciona la extraña maquinaria de los humanos, tendremos más posibilidades de derrotarlos en futuras batallas.$B$BUna vez adquirido ese conocimiento, a la Horda solo le queda aumentar su fuerza.', 0),
(@ID, 'esMX', 'Cuando sepamos cómo funciona la extraña maquinaria de los humanos, tendremos más posibilidades de derrotarlos en futuras batallas.$B$BUna vez adquirido ese conocimiento, a la Horda solo le queda aumentar su fuerza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu misión ha sido un éxito, $c. Me aseguraré de que estas herramientas lleguen a Orgrimmar en la primera caravana.$B$BBuen trabajo.', 0),
(@ID, 'esMX', 'Tu misión ha sido un éxito, $c. Me aseguraré de que estas herramientas lleguen a Orgrimmar en la primera caravana.$B$BBuen trabajo.', 0);
-- 826 Zalazane
-- https://es.classic.wowhead.com/quest=826
SET @ID := 826;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado a Zalazane, $n?', 0),
(@ID, 'esMX', '¿Has derrotado a Zalazane, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con Zalazane derrotado, nuestra tribu puede volver a dormir en paz.$B$BGracias, $n. La tribu Lanza Negra está en deuda contigo. Si sufres alguna dolencia, visita a mi ayudante Bom\'bay. Está detrás de mí. Domina el vudú...', 0),
(@ID, 'esMX', 'Con Zalazane derrotado, nuestra tribu puede volver a dormir en paz.$B$BGracias, $n. La tribu Lanza Negra está en deuda contigo. Si sufres alguna dolencia, visita a mi ayudante Bom\'bay. Está detrás de mí. Domina el vudú...', 0);
-- 827 Roca del Cráneo
-- https://es.classic.wowhead.com/quest=827
SET @ID := 827;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has entrado en la Roca del Cráneo, $n? ¿Tienes los collares ardientes?', 0),
(@ID, 'esMX', '¿Ya has entrado en la Roca del Cráneo, $n? ¿Tienes los collares ardientes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien. Estos collares contienen el secreto que esconde el Filo Ardiente. Y yo sacaré a la luz ese secreto...', 0),
(@ID, 'esMX', 'Bien. Estos collares contienen el secreto que esconde el Filo Ardiente. Y yo sacaré a la luz ese secreto...', 0);
-- 828 Margoz
-- https://es.classic.wowhead.com/quest=828
SET @ID := 828;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida;, $n. Fui informado de tu llegada y de tus hazañas en Durotar.$B$BEstás desarrollando tus habilidades... Te estás haciendo un nombre en este mundo, $c.$B$BMantente en el camino de la pureza y tendrás un gran futuro.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida;, $n. Fui informado de tu llegada y de tus hazañas en Durotar.$B$BEstás desarrollando tus habilidades... Te estás haciendo un nombre en este mundo, $c.$B$BMantente en el camino de la pureza y tendrás un gran futuro.', 0);
-- 829 Neeru Hojafuego
-- https://es.classic.wowhead.com/quest=829
SET @ID := 829;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mis más humildes saludos, $c. ¿En qué puedo ayudar a mi $ghermano:hermana; en un día como hoy?', 0),
(@ID, 'esMX', 'Mis más humildes saludos, $c. ¿En qué puedo ayudar a mi $ghermano:hermana; en un día como hoy?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De dónde has sacado esto? El buen Margoz de Cerrotajo te envió a mí, ¿verdad?$B$BBien, bien, deja que eche un vistazo...', 0),
(@ID, 'esMX', '¿De dónde has sacado esto? El buen Margoz de Cerrotajo te envió a mí, ¿verdad?$B$BBien, bien, deja que eche un vistazo...', 0);
-- 830 Las órdenes del almirante
-- https://es.classic.wowhead.com/quest=830
SET @ID := 830;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pareces preocupado, $c. ¿Qué tienes ahí?', 0),
(@ID, 'esMX', 'Pareces preocupado, $c. ¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto no presagia nada bueno. Ha sido muy inteligente llamar mi atención sobre esta información.', 0),
(@ID, 'esMX', 'Esto no presagia nada bueno. Ha sido muy inteligente llamar mi atención sobre esta información.', 0);
-- 831 Las órdenes del almirante
-- https://es.classic.wowhead.com/quest=831
SET @ID := 831;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves que estoy ocupado? Espero que sea importante...', 0),
(@ID, 'esMX', '¿No ves que estoy ocupado? Espero que sea importante...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fueron innumerables las veces que exhorté al Jefe de Guerra que no confiara en los humanos... Pero aquí no está en juego el orgullo personal.$B$BHas servido con honor a la Horda, joven $c.$B$BAhora debes perdonarme, pero he de consultar estos asuntos con Thrall de inmediato...', 0),
(@ID, 'esMX', 'Fueron innumerables las veces que exhorté al Jefe de Guerra que no confiara en los humanos... Pero aquí no está en juego el orgullo personal.$B$BHas servido con honor a la Horda, joven $c.$B$BAhora debes perdonarme, pero he de consultar estos asuntos con Thrall de inmediato...', 0);
-- 832 Sombras Ardientes
-- https://es.classic.wowhead.com/quest=832
SET @ID := 832;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tienes que informar de algo importante. Puedo verlo en tus ojos.', 0),
(@ID, 'esMX', 'Tienes que informar de algo importante. Puedo verlo en tus ojos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Examina el Ojo de la Sombra Ardiente.>$B$BIntrigante. ¿La voz que oíste mencionó mi nombre? Todo el mundo sabe que doy caza a los enemigos de nuestro Jefe de Guerra, pero me resulta extraño que se mencione mi nombre en concreto. Y aún es más extraño que los fieles del Filo Ardiente de los que conseguiste este colgante tengan un nombre tan parecido al mío.$B$BDebo estudiar este colgante. Debo estudiarlo y ponderar el significado de este mensaje.$B$BGracias por venir a mí, $n. Has hecho un gran servicio a tu gente.', 0),
(@ID, 'esMX', '<Examina el Ojo de la Sombra Ardiente.>$B$BIntrigante. ¿La voz que oíste mencionó mi nombre? Todo el mundo sabe que doy caza a los enemigos de nuestro Jefe de Guerra, pero me resulta extraño que se mencione mi nombre en concreto. Y aún es más extraño que los fieles del Filo Ardiente de los que conseguiste este colgante tengan un nombre tan parecido al mío.$B$BDebo estudiar este colgante. Debo estudiarlo y ponderar el significado de este mensaje.$B$BGracias por venir a mí, $n. Has hecho un gran servicio a tu gente.', 0);
-- 834 Las arpías Viento Seco
-- https://es.classic.wowhead.com/quest=834
SET @ID := 834;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hago muy bien mi trabajo, no te confundas, ¡pero esto es ridículo! ¡¿Qué se supone que tengo que hacer si no tengo con qué trabajar?!', 0),
(@ID, 'esMX', 'Hago muy bien mi trabajo, no te confundas, ¡pero esto es ridículo! ¡¿Qué se supone que tengo que hacer si no tengo con qué trabajar?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, justo lo que necesitaba! Nos has traído nuestros suministros. Es genial. Así podré volver al trabajo, en cuanto encuentre a alguien que cargue con estos sacos.', 0),
(@ID, 'esMX', '¡Vaya, justo lo que necesitaba! Nos has traído nuestros suministros. Es genial. Así podré volver al trabajo, en cuanto encuentre a alguien que cargue con estos sacos.', 0);
-- 835 Asegurar las rutas
-- https://es.classic.wowhead.com/quest=835
SET @ID := 835;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sé que es difícil de creer de un tipo como Gazlowe, pero sabía todo de todo. "No temas dar ese gran paso" –decía.$B$BLas arpías no dejarán de molestarnos y las caravanas seguirán siendo atacadas mientras no hagamos algo al respecto, ¿no te parece?', 0),
(@ID, 'esMX', 'Sé que es difícil de creer de un tipo como Gazlowe, pero sabía todo de todo. "No temas dar ese gran paso" –decía.$B$BLas arpías no dejarán de molestarnos y las caravanas seguirán siendo atacadas mientras no hagamos algo al respecto, ¿no te parece?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creo que ya puedo respirar tranquilo, sabiendo que las arpías no volverán a atacar a nuestras caravanas de suministros. Y justo a tiempo, además. ¡Porque en el siguiente envío me van a llegar algunos juguetitos!$B$BSe te da bien lo que haces, $n, deberías buscar a mi jefe en Trinquete. Seguro que él podrá darte más trabajo.$B$BAh, y no te preocupes, no me he olvidado de pagarte por el favor que me has hecho.', 0),
(@ID, 'esMX', 'Creo que ya puedo respirar tranquilo, sabiendo que las arpías no volverán a atacar a nuestras caravanas de suministros. Y justo a tiempo, además. ¡Porque en el siguiente envío me van a llegar algunos juguetitos!$B$BSe te da bien lo que haces, $n, deberías buscar a mi jefe en Trinquete. Seguro que él podrá darte más trabajo.$B$BAh, y no te preocupes, no me he olvidado de pagarte por el favor que me has hecho.', 0);
-- 836 ¡Rescata a OOX-09/TI!
-- https://es.classic.wowhead.com/quest=836
SET @ID := 836;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, tú rescataste a OOX-09/TI! ¡No tengo palabras para expresar mi gratitud! Aún tengo que perfeccionarlo, ¡pero me has ahorrado muchas monedas de oro e incontables horas de trabajo!$B$BTe ruego que aceptes uno de estos objetos en recompensa. Mis robots y yo te estamos muy agradecidos, $n.', 0),
(@ID, 'esMX', '¡Ah, tú rescataste a OOX-09/TI! ¡No tengo palabras para expresar mi gratitud! Aún tengo que perfeccionarlo, ¡pero me has ahorrado muchas monedas de oro e incontables horas de trabajo!$B$BTe ruego que aceptes uno de estos objetos en recompensa. Mis robots y yo te estamos muy agradecidos, $n.', 0);
-- 837 Invasión
-- https://es.classic.wowhead.com/quest=837
SET @ID := 837;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aunque sí están dotados de una cierta inteligencia y capacidad de organización, me sigue asombrando que los jabaespines consiguieran conquistar y conservar tanto territorio de Kalimdor. Quizás tengan más recursos de los que les atribuía...', 0),
(@ID, 'esMX', 'Aunque sí están dotados de una cierta inteligencia y capacidad de organización, me sigue asombrando que los jabaespines consiguieran conquistar y conservar tanto territorio de Kalimdor. Quizás tengan más recursos de los que les atribuía...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haré correr la voz de que los jabaespines ya no están en sus guaridas y de que se puede prender fuego a sus estructuras. Erradicar a los Crines de Acero de Durotar es un gran paso para mejorar la seguridad de las fronteras de nuestro nuevo hogar.', 0),
(@ID, 'esMX', 'Haré correr la voz de que los jabaespines ya no están en sus guaridas y de que se puede prender fuego a sus estructuras. Erradicar a los Crines de Acero de Durotar es un gran paso para mejorar la seguridad de las fronteras de nuestro nuevo hogar.', 0);
-- 838 Scholomance
-- https://es.classic.wowhead.com/quest=838
SET @ID := 838;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, $c, el Sumo Ejecutor dijo que podrías ser aquel en quien confiar respecto a la llave. He dedicado una parte importante de mis recientes estudios a Scholomance y creo que sé una forma de que adquieras una llave que te permita cruzar la puerta delantera siempre que lo desees.$B$BLa tarea no será fácil, pero este tipo de tareas rara vez lo son. Y tú pareces saberlo ya a ciencia cierta.', 0),
(@ID, 'esMX', 'Sí, $c, el Sumo Ejecutor dijo que podrías ser aquel en quien confiar respecto a la llave. He dedicado una parte importante de mis recientes estudios a Scholomance y creo que sé una forma de que adquieras una llave que te permita cruzar la puerta delantera siempre que lo desees.$B$BLa tarea no será fácil, pero este tipo de tareas rara vez lo son. Y tú pareces saberlo ya a ciencia cierta.', 0);
-- 840 Nuevo recluta de la Horda
-- https://es.classic.wowhead.com/quest=840
SET @ID := 840;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué quieres, $gcachorrito:cachorrita;? Si no estás aquí para alistarte, no tengo tiempo para ti.', 0),
(@ID, 'esMX', '¿Qué quieres, $gcachorrito:cachorrita;? Si no estás aquí para alistarte, no tengo tiempo para ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que te manda Takrin? Es un rastreador excelente, no sé qué haría sin él.$B$BFirmaré tu carta de reclutamiento, pero lo que necesitamos es tener a alguien en El Cruce.', 0),
(@ID, 'esMX', '¿Así que te manda Takrin? Es un rastreador excelente, no sé qué haría sin él.$B$BFirmaré tu carta de reclutamiento, pero lo que necesitamos es tener a alguien en El Cruce.', 0);
-- 841 ¿Otra fuente de alimentación?
-- https://es.classic.wowhead.com/quest=841
SET @ID := 841;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y bien, conseguiste las 10 faltriqueras de agua?', 0),
(@ID, 'esMX', '¿Y bien, conseguiste las 10 faltriqueras de agua?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, aquí tienes otra fuente de alimentación. Te recomiendo que la utilices correctamente en esta ocasión, a menos que desees gastarte otras diez faltriqueras de agua en comprar una nueva.', 0),
(@ID, 'esMX', 'Muy bien, aquí tienes otra fuente de alimentación. Te recomiendo que la utilices correctamente en esta ocasión, a menos que desees gastarte otras diez faltriqueras de agua en comprar una nueva.', 0);
-- 842 Servicio militar en El Cruce
-- https://es.classic.wowhead.com/quest=842
SET @ID := 842;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, vaya, vaya, ¿qué tenemos aquí? ¿Kargal me considera merecedora de otro recluta?', 0),
(@ID, 'esMX', 'Vaya, vaya, vaya, ¿qué tenemos aquí? ¿Kargal me considera merecedora de otro recluta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. ¿Quieres ganarte un sustento en la Horda? Pues aquí hay mucho que hacer, así que escucha con atención lo que voy a decirte.$B$BVeo en tu mirada una insolencia que no pienso tolerar. El propio Thrall ha decretado que la Horda debe tratar a las mujeres como iguales. Si me faltas al respeto de cualquier manera, prepárate para conocer el dolor, el auténtico dolor.', 0),
(@ID, 'esMX', 'Muy bien, $n. ¿Quieres ganarte un sustento en la Horda? Pues aquí hay mucho que hacer, así que escucha con atención lo que voy a decirte.$B$BVeo en tu mirada una insolencia que no pienso tolerar. El propio Thrall ha decretado que la Horda debe tratar a las mujeres como iguales. Si me faltas al respeto de cualquier manera, prepárate para conocer el dolor, el auténtico dolor.', 0);
-- 843 La reclamación de Gann
-- https://es.classic.wowhead.com/quest=843
SET @ID := 843;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchos tauren inocentes perdieron la vida o fueron expulsados de su hogar ancestral cuando llegaron los enanos de Bael Modan. ¡Debemos recuperar mi tierra!', 0),
(@ID, 'esMX', 'Muchos tauren inocentes perdieron la vida o fueron expulsados de su hogar ancestral cuando llegaron los enanos de Bael Modan. ¡Debemos recuperar mi tierra!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Khazgorm se encontró con el sino que se merecía. No siento remordimiento alguno por ese idiota. Era un infiel en estas tierras.$B$BQue su muerte sirva de advertencia a todos los que amenazan con perturbar nuestro modo de vida.$B$BY ahora dediquemos un tiempo a estudiar el diario del enano....', 0),
(@ID, 'esMX', 'Khazgorm se encontró con el sino que se merecía. No siento remordimiento alguno por ese idiota. Era un infiel en estas tierras.$B$BQue su muerte sirva de advertencia a todos los que amenazan con perturbar nuestro modo de vida.$B$BY ahora dediquemos un tiempo a estudiar el diario del enano....', 0);
-- 844 La amenaza de los zancudos de llanura
-- https://es.classic.wowhead.com/quest=844
SET @ID := 844;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los picos de los zancudos de llanura?', 0),
(@ID, 'esMX', '¿Has conseguido los picos de los zancudos de llanura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Ahora que ya no están los zancudos de llanura, será más fácil mantener la línea de suministros. Y espero que hayas aprendido unos cuantos trucos en Los Baldíos porque tu próxima presa es un hueso más duro de roer que los zancudos de llanura...', 0),
(@ID, 'esMX', 'Muy bien, $n. Ahora que ya no están los zancudos de llanura, será más fácil mantener la línea de suministros. Y espero que hayas aprendido unos cuantos trucos en Los Baldíos porque tu próxima presa es un hueso más duro de roer que los zancudos de llanura...', 0);
-- 845 La zhebra
-- https://es.wowhead.com/quest=845
SET @ID := 845;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuántas zhebras has matado?', 0),
(@ID, 'esMX', '¿Cuántas zhebras has matado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No está mal, $n. Esas zhebras tienen unas patas muy fuertes. ¡Una coz bien dada puede derribar hasta a un tauren!$B$BPor lo visto, tú también eres fuerte.', 0),
(@ID, 'esMX', 'No está mal, $n. Esas zhebras tienen unas patas muy fuertes. ¡Una coz bien dada puede derribar hasta a un tauren!$B$BPor lo visto, tú también eres fuerte.', 0);
