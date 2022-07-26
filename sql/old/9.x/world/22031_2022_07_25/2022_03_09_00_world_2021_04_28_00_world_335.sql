-- 8876 Cohetes pequeños
-- https://es.classic.wowhead.com/quest=8876
SET @ID := 8876;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Aquí están tus recetas, $n, y que Elune te bendiga.', 0),
(@ID, 'esMX', 'Ah, muy bien. Aquí están tus recetas, $n, y que Elune te bendiga.', 0);
-- 8877 Lanzador de fuegos artificiales
-- https://es.classic.wowhead.com/quest=8877
SET @ID := 8877;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n. Aquí está el esquema para crear un lanzador de fuegos artificiales. Coloca los lanzadores donde desees celebrar y luego da la bienvenida a tus amigos para que se unan a la fiesta.', 0),
(@ID, 'esMX', 'Aquí tienes, $n. Aquí está el esquema para crear un lanzador de fuegos artificiales. Coloca los lanzadores donde desees celebrar y luego da la bienvenida a tus amigos para que se unan a la fiesta.', 0);
-- 8878 Patrones para las fiestas
-- https://es.classic.wowhead.com/quest=8878
SET @ID := 8878;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí están los patrones, $n. Estoy seguro de que el producto de este conocimiento te resultará bastante hermoso.', 0),
(@ID, 'esMX', 'Aquí están los patrones, $n. Estoy seguro de que el producto de este conocimiento te resultará bastante hermoso.', 0);
-- 8879 Cohetes grandes
-- https://es.classic.wowhead.com/quest=8879
SET @ID := 8879;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, acepto estas monedas de linaje. Aquí están tus recetas, $n. ¡Puedes usarlas para difundir la gloria de Elune!', 0),
(@ID, 'esMX', 'Muy bien, acepto estas monedas de linaje. Aquí están tus recetas, $n. ¡Puedes usarlas para difundir la gloria de Elune!', 0);
-- 8880 Tracas de cohetes
-- https://es.classic.wowhead.com/quest=8880
SET @ID := 8880;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n. Toma estas recetas y aprende sus secretos. Te deseo suerte y espero ver tus magníficas creaciones.', 0),
(@ID, 'esMX', 'Aquí tienes, $n. Toma estas recetas y aprende sus secretos. Te deseo suerte y espero ver tus magníficas creaciones.', 0);
-- 8881 Tracas de cohetes grandes
-- https://es.classic.wowhead.com/quest=8881
SET @ID := 8881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las tracas de cohetes grandes requieren vastos recursos y habilidad para crearlas, ¡pero su brillantez y belleza merecen ese esfuerzo! Tráeme monedas de linaje y te otorgaré el conocimiento de su elaboración.', 0),
(@ID, 'esMX', 'Las tracas de cohetes grandes requieren vastos recursos y habilidad para crearlas, ¡pero su brillantez y belleza merecen ese esfuerzo! Tráeme monedas de linaje y te otorgaré el conocimiento de su elaboración.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Aquí está la receta para tracas de cohetes grandes. Que tus productos traigan alegría y suerte a todos los que los miran.', 0),
(@ID, 'esMX', 'Gracias, $n. Aquí está la receta para tracas de cohetes grandes. Que tus productos traigan alegría y suerte a todos los que los miran.', 0);
-- 8882 Lanzatracas
-- https://es.classic.wowhead.com/quest=8882
SET @ID := 8882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los espectáculos de fuegos artificiales más espléndidos deben incluir tracas de cohetes, ¡y esas tracas deben dispararse desde lanzadores de tracas! Entonces, ¿no es lógico que aprendas los secretos para hacer lanzadores de tracas? Tráeme monedas de linaje y te daré este conocimiento.', 0),
(@ID, 'esMX', 'Los espectáculos de fuegos artificiales más espléndidos deben incluir tracas de cohetes, ¡y esas tracas deben dispararse desde lanzadores de tracas! Entonces, ¿no es lógico que aprendas los secretos para hacer lanzadores de tracas? Tráeme monedas de linaje y te daré este conocimiento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está tu esquema. Estúdialo de cerca y aprende...$B$BBuena suerte, $n. ¡Que tus celebraciones compitan con las del Festival Lunar!', 0),
(@ID, 'esMX', 'Aquí está tu esquema. Estúdialo de cerca y aprende...$B$BBuena suerte, $n. ¡Que tus celebraciones compitan con las del Festival Lunar!', 0);
-- 8883 Valadar Cantoestelar
-- https://es.wowhead.com/quest=8883
SET @ID := 8883;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n, $gbienvenido:bienvenida; al Amparo de la Noche, sede de El Festival Lunar! Aunque nuestro poblado está alejado y remoto para las gentes de Azeroth, durante estos días de celebración abrimos nuestros brazos y corazones a todo el mundo.$B$BDisfruta de tu visita, $n, y vuelve a hablar conmigo o con mi hermana cuando estés $glisto:lista;.', 0),
(@ID, 'esMX', '¡$n, $gbienvenido:bienvenida; al Amparo de la Noche, sede de El Festival Lunar! Aunque nuestro poblado está alejado y remoto para las gentes de Azeroth, durante estos días de celebración abrimos nuestros brazos y corazones a todo el mundo.$B$BDisfruta de tu visita, $n, y vuelve a hablar conmigo o con mi hermana cuando estés $glisto:lista;.', 0);
-- 8884 Aquí, pescadito...
-- https://es.wowhead.com/quest=8884
SET @ID := 8884;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los forestales de El Retiro del Errante estamos reparando el daño infligido a nuestras hermosas tierras y haremos lo que sea necesario para conseguirlo.$B$B¿Traes las cabezas de múrloc que te pedí?', 0),
(@ID, 'esMX', 'Los forestales de El Retiro del Errante estamos reparando el daño infligido a nuestras hermosas tierras y haremos lo que sea necesario para conseguirlo.$B$B¿Traes las cabezas de múrloc que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $c. Por el olor diría que me traes lo que pedí, incluso más. Seguro que las aprovecharemos para hacer sopa o algo.$B$BPero, por desgracia, tus esfuerzos no parecen haber dado resultado: los múrlocs no se han retirado. ¡Hay que tomar medidas más extremas!', 0),
(@ID, 'esMX', 'Buen trabajo, $c. Por el olor diría que me traes lo que pedí, incluso más. Seguro que las aprovecharemos para hacer sopa o algo.$B$BPero, por desgracia, tus esfuerzos no parecen haber dado resultado: los múrlocs no se han retirado. ¡Hay que tomar medidas más extremas!', 0);
-- 8885 El anillo de Mmmrrrggglll
-- https://es.wowhead.com/quest=8885
SET @ID := 8885;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres el vehículo de mi venganza, $c. ¿Traes el anillo?', 0),
(@ID, 'esMX', 'Eres el vehículo de mi venganza, $c. ¿Traes el anillo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin! Aunque los Malaescama no se han retirado como esperaba, me divertí mucho con su pánico cuando liquidaste a su jefe. Tienes mi gratitud y la de los sin\'dorei de Ciudad de Lunargenta.$B$BAcepta esto como muestra de agradecimiento por tus servicios.', 0),
(@ID, 'esMX', '¡Al fin! Aunque los Malaescama no se han retirado como esperaba, me divertí mucho con su pánico cuando liquidaste a su jefe. Tienes mi gratitud y la de los sin\'dorei de Ciudad de Lunargenta.$B$BAcepta esto como muestra de agradecimiento por tus servicios.', 0);
-- 8886 ¡Piratas Malaescama!
-- https://es.wowhead.com/quest=8886
SET @ID := 8886;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Agradezco la ayuda de alguien como tú, $n. Casi me hace sonreír, pero entonces me acuerdo de lo que esos monstruos le han hecho a mi nave y de lo que está pasando en Quel\'Thalas.$B$B¿Conseguiste recuperar parte de mi carga?', 0),
(@ID, 'esMX', 'Agradezco la ayuda de alguien como tú, $n. Casi me hace sonreír, pero entonces me acuerdo de lo que esos monstruos le han hecho a mi nave y de lo que está pasando en Quel\'Thalas.$B$B¿Conseguiste recuperar parte de mi carga?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! ¡Me has salvado de la ruina y me has vengado de esas asquerosas criaturas!$B$BAhora a ver si consigo que esas forestales tan guapas me ayuden con la carga y podré marcharme por fin. Tendré que volver cuando Velendris retome el astillero.$B$BTen esta moneda. No puedo permitirme más, pero lo menos que puedo hacer es pagarte por tu ayuda.', 0),
(@ID, 'esMX', '¡Fantástico! ¡Me has salvado de la ruina y me has vengado de esas asquerosas criaturas!$B$BAhora a ver si consigo que esas forestales tan guapas me ayuden con la carga y podré marcharme por fin. Tendré que volver cuando Velendris retome el astillero.$B$BTen esta moneda. No puedo permitirme más, pero lo menos que puedo hacer es pagarte por tu ayuda.', 0);
-- 8887 Rutas perdidas de la capitana Kelisendra
-- https://es.wowhead.com/quest=8887
SET @ID := 8887;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c, me alegro de verte. Sé que es absurdo que esté aquí cuando El Puerto ha sido invadido por los desdichados. Velendris y sus forestales han jurado protegerme a condición de que me vaya en cuanto haya recuperado mi carga.$B$B¿Qué traes? Eso me suena.', 0),
(@ID, 'esMX', 'Hola, $c, me alegro de verte. Sé que es absurdo que esté aquí cuando El Puerto ha sido invadido por los desdichados. Velendris y sus forestales han jurado protegerme a condición de que me vaya en cuanto haya recuperado mi carga.$B$B¿Qué traes? Eso me suena.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, $c! ¡No sabía que los múrlocs Malaescama se habían llevado también mis planes de navegación! Sin ellos no habría podido salir a la mar aun después de haber retomado El Puerto y reparado la nave.$B$B¡Muchas gracias! Acepta esta moneda en muestra de gratitud.', 0),
(@ID, 'esMX', '¡Estupendo, $c! ¡No sabía que los múrlocs Malaescama se habían llevado también mis planes de navegación! Sin ellos no habría podido salir a la mar aun después de haber retomado El Puerto y reparado la nave.$B$B¡Muchas gracias! Acepta esta moneda en muestra de gratitud.', 0);
-- 8898 Queridísima Colara:
-- https://es.classic.wowhead.com/quest=8898
SET @ID := 8898;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gguapo:guapa;, ¿querías algo?', 0),
(@ID, 'esMX', 'Hola, $gguapo:guapa;, ¿querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tormek? Ah, sí, el barbudito simpático.$B$B¡Qué bien que se acuerde de mí!', 0),
(@ID, 'esMX', '¿Tormek? Ah, sí, el barbudito simpático.$B$B¡Qué bien que se acuerde de mí!', 0);
-- 8899 Queridísima Colara:
-- https://es.classic.wowhead.com/quest=8899
SET @ID := 8899;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola $gguapo:guapa;. ¿Te puedo ayudar en algo?', 0),
(@ID, 'esMX', 'Hola $gguapo:guapa;. ¿Te puedo ayudar en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nunca antes había recibido algo como esto. ¡Que adorable!', 0),
(@ID, 'esMX', 'Nunca antes había recibido algo como esto. ¡Que adorable!', 0);
-- 8900 Queridísima Elenia:
-- https://es.classic.wowhead.com/quest=8900
SET @ID := 8900;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿y a qué debo este placer?', 0),
(@ID, 'esMX', 'Ah, ¿y a qué debo este placer?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No esperaba que un orco fuera tan elocuente. Por supuesto, nunca antes había tenido la oportunidad de conocerlos. Gracias por traerme esto.', 0),
(@ID, 'esMX', 'No esperaba que un orco fuera tan elocuente. Por supuesto, nunca antes había tenido la oportunidad de conocerlos. Gracias por traerme esto.', 0);
-- 8901 Queridísima Elenia:
-- https://es.classic.wowhead.com/quest=8901
SET @ID := 8901;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿y a qué debo este placer?', 0),
(@ID, 'esMX', 'Ah, ¿y a qué debo este placer?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué amables palabras escribe Temma para mí. Pero, por mucho que me conmuevan sus palabras, no puedo considerar el amor de un tauren. En pensamientos, cuerpo y mente somos demasiado diferentes.$B$BEs bueno que no tenga que recibir estos pensamientos suyos en persona. No pude soportar romperle el corazón.', 0),
(@ID, 'esMX', 'Qué amables palabras escribe Temma para mí. Pero, por mucho que me conmuevan sus palabras, no puedo considerar el amor de un tauren. En pensamientos, cuerpo y mente somos demasiado diferentes.$B$BEs bueno que no tenga que recibir estos pensamientos suyos en persona. No pude soportar romperle el corazón.', 0);
-- 8902 Queridísima Elenia:
-- https://es.classic.wowhead.com/quest=8902
SET @ID := 8902;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿y a qué debo este placer?', 0),
(@ID, 'esMX', 'Ah, ¿y a qué debo este placer?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto trae recuerdos de hace una vida, $n. Elenia Tor. Ese iba a ser mi nombre, sabes. Tendríamos una hermosa ceremonia a orillas del lago. Cuando se jubilara, encontraríamos una granja donde retirarnos.$B$BSueños simples, entonces.$B$BPero si me viera ahora, dudo que incluso vea a Elenia en mí. Solo carne fría y un corazón muerto...', 0),
(@ID, 'esMX', 'Esto trae recuerdos de hace una vida, $n. Elenia Tor. Ese iba a ser mi nombre, sabes. Tendríamos una hermosa ceremonia a orillas del lago. Cuando se jubilara, encontraríamos una granja donde retirarnos.$B$BSueños simples, entonces.$B$BPero si me viera ahora, dudo que incluso vea a Elenia en mí. Solo carne fría y un corazón muerto...', 0);
-- 8903 Amor peligroso
-- https://es.classic.wowhead.com/quest=8903
SET @ID := 8903;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime, ¿los guardias también están afectados por esta locura de amor?', 0),
(@ID, 'esMX', 'Dime, ¿los guardias también están afectados por esta locura de amor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De modo que estaba en lo cierto. ¡Esto es terrible! ¿Cómo ha podido pasar? Déjame pensar... Tiene que haber alguna razón.', 0),
(@ID, 'esMX', 'De modo que estaba en lo cierto. ¡Esto es terrible! ¿Cómo ha podido pasar? Déjame pensar... Tiene que haber alguna razón.', 0);
-- 8904 Amor peligroso
-- https://es.classic.wowhead.com/quest=8904
SET @ID := 8904;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tenía razón en preocuparme? ¿Han vencido a nuestros guardias idiotas?', 0),
(@ID, 'esMX', '¿Tenía razón en preocuparme? ¿Han vencido a nuestros guardias idiotas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De modo que estaba en lo cierto. ¡Esto es terrible! ¿Cómo ha podido pasar? Déjame pensar... Tiene que haber alguna razón.', 0),
(@ID, 'esMX', 'De modo que estaba en lo cierto. ¡Esto es terrible! ¿Cómo ha podido pasar? Déjame pensar... Tiene que haber alguna razón.', 0);
-- Una propuesta seria
-- 8905, 8906, 8907, 8908, 8909, 8910, 8911, 8912, 10492
-- https://es.classic.wowhead.com/quest=8905
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8905, 8906, 8907, 8908, 8909, 8910, 8911, 8912, 10492) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8905, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8906, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8907, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8908, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8909, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8910, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8911, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8912, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(10492, 'esES', '¿Me has traído lo que te pedí, $n?', 0),
(8905, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(8906, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(8907, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(8908, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(8909, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(8910, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(8911, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(8912, 'esMX', '¿Me has traído lo que te pedí, $n?', 0),
(10492, 'esMX', '¿Me has traído lo que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8905, 8906, 8907, 8908, 8909, 8910, 8911, 8912, 10492) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8905, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8906, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8907, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8908, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8909, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8910, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8911, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8912, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(10492, 'esES', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8905, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8906, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8907, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8908, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8909, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8910, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8911, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(8912, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0),
(10492, 'esMX', '¡Excelente! Entonces realicemos el intercambio. Es difícil desprenderse de esta excelente armadura, pero me temo que no la necesitaré en un tiempo.$B$BSi estás $ginteresado:interesada; en realizar más trabajos para mí, podría estar dispuesta a renunciar al resto de las piezas.', 0);
-- Una propuesta seria
-- 8913, 8914, 8915, 8916, 8917, 8918, 8919, 8920, 10493
-- https://es.classic.wowhead.com/quest=8913
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8913, 8914, 8915, 8916, 8917, 8918, 8919, 8920, 10493) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8913, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8914, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8915, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8916, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8917, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8918, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8919, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8920, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(10493, 'esES', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8913, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8914, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8915, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8916, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8917, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8918, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8919, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(8920, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0),
(10493, 'esMX', '¿Ha obtenido los artículos que necesito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8913, 8914, 8915, 8916, 8917, 8918, 8919, 8920, 10493) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8913, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8914, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8915, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8916, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8917, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8918, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8919, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8920, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(10493, 'esES', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8913, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8914, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8915, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8916, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8917, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8918, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8919, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(8920, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0),
(10493, 'esMX', 'Ah, sí. Mux estará bastante contento con esto.$B$BEsos brazales eran parte de mi mejor conjunto de armadura. Si estás $ginteresado:interesada; en brindarme más ayuda, estaría dispuesto a considerar separarme del resto.', 0);
-- 8921 El destilador ectoplásmico
-- https://es.classic.wowhead.com/quest=8921
SET @ID := 8921;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entiendo que los materiales son un poco caros... ¡pero te prometo que cada uno de ellos es necesario!', 0),
(@ID, 'esMX', 'Entiendo que los materiales son un poco caros... ¡pero te prometo que cada uno de ellos es necesario!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son precisamente los materiales que necesitaba. ¡Muy oportuno también, $n!$B$B¡En unos momentos tendré tu destilador listo para funcionar! Mientras tanto, toma esto como una recompensa por ayudarme en mi proyecto.', 0),
(@ID, 'esMX', 'Estos son precisamente los materiales que necesitaba. ¡Muy oportuno también, $n!$B$B¡En unos momentos tendré tu destilador listo para funcionar! Mientras tanto, toma esto como una recompensa por ayudarme en mi proyecto.', 0);
-- 8922 Un artefacto sobrenatural
-- https://es.classic.wowhead.com/quest=8922
SET @ID := 8922;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mi?', 0),
(@ID, 'esMX', '¿Tienes algo para mi?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Justo cuando estaba acabando!$B$B¿Dices que te envió Deliana?', 0),
(@ID, 'esMX', '¡Excelente! ¡Justo cuando estaba acabando!$B$B¿Dices que te envió Deliana?', 0);
-- 8923 Un artefacto sobrenatural
-- https://es.wowhead.com/quest=8923
SET @ID := 8923;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres hablar conmigo?', 0),
(@ID, 'esMX', '¿Quieres hablar conmigo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Justo cuando estaba acabando!$B$B¿Dices que te envió Mokvar?', 0),
(@ID, 'esMX', '¡Excelente! ¡Justo cuando estaba acabando!$B$B¿Dices que te envió Mokvar?', 0);
-- 8924 Caza de ectoplasmas
-- https://es.classic.wowhead.com/quest=8924
SET @ID := 8924;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya reuniste el ectoplasma, $r?', 0),
(@ID, 'esMX', '¿Ya reuniste el ectoplasma, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¡estos lo harán genial!$B$B¡Al aprovechar las energías de otro mundo contenidas en estas sustancias, podremos llegar a aquellos cuyas almas aún no han abandonado este mundo!', 0),
(@ID, 'esMX', 'Sí, ¡estos lo harán genial!$B$B¡Al aprovechar las energías de otro mundo contenidas en estas sustancias, podremos llegar a aquellos cuyas almas aún no han abandonado este mundo!', 0);
-- 8925 Fuente de energía portátil
-- https://es.classic.wowhead.com/quest=8925
SET @ID := 8925;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado al Señor del Magma, $n?', 0),
(@ID, 'esMX', '¿Has encontrado al Señor del Magma, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has hecho! ¡Esto sin duda proporcionará suficiente energía para encender al revelador fantasma extradimensional!', 0),
(@ID, 'esMX', '¡Lo has hecho! ¡Esto sin duda proporcionará suficiente energía para encender al revelador fantasma extradimensional!', 0);
-- Una compensación justa
-- 8926, 8931, 8932, 8933, 8934, 8935, 8936, 8937, 10494
-- https://es.classic.wowhead.com/quest=8926
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8926, 8931, 8932, 8933, 8934, 8935, 8936, 8937, 10494) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8926, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8931, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8932, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8933, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8934, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8935, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8936, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8937, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(10494, 'esES', '¿Estás $glisto:lista; para comerciar?', 0),
(8926, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8931, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8932, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8933, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8934, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8935, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8936, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(8937, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0),
(10494, 'esMX', '¿Estás $glisto:lista; para comerciar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8926, 8931, 8932, 8933, 8934, 8935, 8936, 8937, 10494) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8926, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8931, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8932, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8933, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8934, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8935, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8936, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8937, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(10494, 'esES', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8926, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8931, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8932, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8933, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8934, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8935, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8936, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(8937, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0),
(10494, 'esMX', 'Has cumplido tu parte del trato, yo cumpliré la mía.$B$BSolo recuerda que me aferro a las mejores piezas hasta que termines tu trabajo.', 0);
