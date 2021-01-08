-- 911 El acceso a la frontera
-- https://es.classic.wowhead.com/quest=911
SET @ID := 911;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya llegamos?', 0),
(@ID, 'esMX', '¿Ya llegamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau, Vallefresno está lleno de aventuras! ¿Has luchado alguna vez en Vallefresno, $n? ¡Cuando crezca y me convierta en un héroe quiero venir a Vallefresno y luchar por la gloria de la Horda!$B$BGracias por traerme a la frontera, $n. ¡Eres el mejor!', 0),
(@ID, 'esMX', '¡Guau, Vallefresno está lleno de aventuras! ¿Has luchado alguna vez en Vallefresno, $n? ¡Cuando crezca y me convierta en un héroe quiero venir a Vallefresno y luchar por la gloria de la Horda!$B$BGracias por traerme a la frontera, $n. ¡Eres el mejor!', 0);
-- 913 El chillido del halcón trueno
-- https://es.classic.wowhead.com/quest=913
SET @ID := 913;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya está? ¿Has matado al halcón trueno?', 0),
(@ID, 'esMX', '¿Ya está? ¿Has matado al halcón trueno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú, al igual que el halcón trueno, deberías sentirte $gorgulloso:orgullosa;. Has derrotado a todos los enemigos que te hemos marcado y lo has hecho con fuerza, valor y honor.$B$BPero ahí no acaba tu camino, $n. De hecho, te darás cuenta de que los verdaderos cazadores siempre van a más, siempre siguen su camino con el mismo orgullo que me has demostrado.$B$BAhora debes seguir adelante.', 0),
(@ID, 'esMX', 'Tú, al igual que el halcón trueno, deberías sentirte $gorgulloso:orgullosa;. Has derrotado a todos los enemigos que te hemos marcado y lo has hecho con fuerza, valor y honor.$B$BPero ahí no acaba tu camino, $n. De hecho, te darás cuenta de que los verdaderos cazadores siempre van a más, siempre siguen su camino con el mismo orgullo que me has demostrado.$B$BAhora debes seguir adelante.', 0);
-- 914 Líderes del Colmillo
-- https://es.classic.wowhead.com/quest=914
SET @ID := 914;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los recuerdos de mis pesadillas me persiguen, $n. ¿Has derrotado a los líderes del Colmillo y conseguido sus gemas?', 0),
(@ID, 'esMX', 'Los recuerdos de mis pesadillas me persiguen, $n. ¿Has derrotado a los líderes del Colmillo y conseguido sus gemas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has conseguido, $n. Mataste a los líderes de los Druidas del Colmillo. Mis sueños están libres de sus malvados rostros y has ayudado a salvar a Los Baldíos de un futuro maldito.$B$BTe lo agradezco, $n. Te lo agradezco en mi nombre, en nombre de los druidas de Cima del Trueno y en nombre de todo el país.', 0),
(@ID, 'esMX', 'Lo has conseguido, $n. Mataste a los líderes de los Druidas del Colmillo. Mis sueños están libres de sus malvados rostros y has ayudado a salvar a Los Baldíos de un futuro maldito.$B$BTe lo agradezco, $n. Te lo agradezco en mi nombre, en nombre de los druidas de Cima del Trueno y en nombre de todo el país.', 0);
-- 915 ¡Quiero un heladooooo!
-- https://es.classic.wowhead.com/quest=915
SET @ID := 915;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ojalá hicieran más sabores que el de fresa, pero bueno, ¡la verdad es que estoy de suerte porque el de fresa es mi favorito!', 0),
(@ID, 'esMX', 'Ojalá hicieran más sabores que el de fresa, pero bueno, ¡la verdad es que estoy de suerte porque el de fresa es mi favorito!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ummmmmmm! ¡Me encanta su helado de fresa! ¡Si hay algo que Tigule y Foror sepan hacer es el helado de fresa!$B$BMuchas gracias $n, ¡es el mejor regalo que me han hecho nunca!', 0),
(@ID, 'esMX', '¡Ummmmmmm! ¡Me encanta su helado de fresa! ¡Si hay algo que Tigule y Foror sepan hacer es el helado de fresa!$B$BMuchas gracias $n, ¡es el mejor regalo que me han hecho nunca!', 0);
-- 924 La Semilla del Demonio
-- https://es.classic.wowhead.com/quest=924
SET @ID := 924;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Destruye la Semilla del Demonio', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Semilla del Demonio todavía existe. Puedo sentir su poder...', 0),
(@ID, 'esMX', 'La Semilla del Demonio todavía existe. Puedo sentir su poder...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has completado la tarea. Has destruido La Semilla del Demonio como Neeru pedía. Pero esto no es el fin...$B$BLa destrucción de La Semilla del Demonio envió oleadas de energía a través del éter, oleadas de colosal fuerza. Las he sentido y estoy seguro de que otros seres también las sintieron. Otros que se preguntarán por qué se les rompió el juguete...$B$BPero independientemente de los problemas futuros, tengo algo para ti. Neeru lo envió como pago. Y me pidió que te transmitiera su agradecimiento.$B$BAsí que gracias.', 0),
(@ID, 'esMX', 'Has completado la tarea. Has destruido La Semilla del Demonio como Neeru pedía. Pero esto no es el fin...$B$BLa destrucción de La Semilla del Demonio envió oleadas de energía a través del éter, oleadas de colosal fuerza. Las he sentido y estoy seguro de que otros seres también las sintieron. Otros que se preguntarán por qué se les rompió el juguete...$B$BPero independientemente de los problemas futuros, tengo algo para ti. Neeru lo envió como pago. Y me pidió que te transmitiera su agradecimiento.$B$BAsí que gracias.', 0);
-- 925 Huella de Cairne
-- https://es.classic.wowhead.com/quest=925
SET @ID := 925;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando los orcos estaban solos y sin aliados, los tauren les acogieron en tierras extrañas y compartieron todo con ellos sin pedir nada a cambio. Eso es el verdadero significado del honor, $n.', 0),
(@ID, 'esMX', 'Cuando los orcos estaban solos y sin aliados, los tauren les acogieron en tierras extrañas y compartieron todo con ellos sin pedir nada a cambio. Eso es el verdadero significado del honor, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡GUAU! ¡Me has conseguido las huellas pezuñales de Cairne Pezuña de Sangre! ¡Muchas gracias! Y... ¡guau!... hay un mensaje para mí, ¡para mí! Sabía que era genial, ¡lo sabía! Quizás algún día se lo pueda agradecer en persona... ¡cuando me convierta en un héroe de la Horda!$B$BEres $gel:la; mejor, $n. Gracias por ser tan $gbueno:buena; conmigo.', 0),
(@ID, 'esMX', '¡GUAU! ¡Me has conseguido las huellas pezuñales de Cairne Pezuña de Sangre! ¡Muchas gracias! Y... ¡guau!... hay un mensaje para mí, ¡para mí! Sabía que era genial, ¡lo sabía! Quizás algún día se lo pueda agradecer en persona... ¡cuando me convierta en un héroe de la Horda!$B$BEres $gel:la; mejor, $n. Gracias por ser tan $gbueno:buena; conmigo.', 0);
-- 926 La piedra de energía con imperfecciones
-- https://es.classic.wowhead.com/quest=926
SET @ID := 926;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas piedras están imbuidas de energía mágica pero dañada a propósito. Son muy inestables y una vez las movamos de la mesa, se autoconsumirán rápidamente.', 0),
(@ID, 'esMX', 'Estas piedras están imbuidas de energía mágica pero dañada a propósito. Son muy inestables y una vez las movamos de la mesa, se autoconsumirán rápidamente.', 0);
-- 927 El corazón musgoso
-- https://es.classic.wowhead.com/quest=927
SET @ID := 927;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¡$n! ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? ¿¿El corazón de un Brezomadera?? ¡Está recubierto de un musgo repugnante!$B$BGracias por traerme esto, $n. Examinaré el corazón y, con un poco de suerte, descubriré la naturaleza del musgo que lo recubre.', 0),
(@ID, 'esMX', '¿Qué es esto? ¿¿El corazón de un Brezomadera?? ¡Está recubierto de un musgo repugnante!$B$BGracias por traerme esto, $n. Examinaré el corazón y, con un poco de suerte, descubriré la naturaleza del musgo que lo recubre.', 0);
-- 934 Corona de la Tierra
-- https://es.classic.wowhead.com/quest=934
SET @ID := 934;
UPDATE `quest_template_locale` SET `Objectives` = 'Llena la ampolla de amatista y devuélvesela a Corithras Furia Lunar en Dolanaar.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Junto con los druidas, el Árbol del Oráculo y el Archidruida han estado monitoreando cuidadosamente el crecimiento de Teldrassil. Pero aunque tenemos un nuevo hogar, nuestra vida inmortal no ha sido restaurada.', 0),
(@ID, 'esMX', 'Junto con los druidas, el Árbol del Oráculo y el Archidruida han estado monitoreando cuidadosamente el crecimiento de Teldrassil. Pero aunque tenemos un nuevo hogar, nuestra vida inmortal no ha sido restaurada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estar en presencia del Árbol del Oráculo... es casi sentir que la sabiduría toma forma. Déjame continuar contando...$B$BCon Teldrassil crecido, el Archidruida se acercó a los dragones en busca de sus bendiciones, como los dragones habían puesto sobre Nordrassil en la antigüedad. Pero Nozdormu, el Señor del Tiempo, se negó a dar su bendición, reprendiendo al druida por su arrogancia. De acuerdo con Nozdormu, Alexstrasza también rechazó a Staghelm, y sin su bendición, el crecimiento de Teldrassil ha sido defectuoso e impredecible...', 0),
(@ID, 'esMX', 'Estar en presencia del Árbol del Oráculo... es casi sentir que la sabiduría toma forma. Déjame continuar contando...$B$BCon Teldrassil crecido, el Archidruida se acercó a los dragones en busca de sus bendiciones, como los dragones habían puesto sobre Nordrassil en la antigüedad. Pero Nozdormu, el Señor del Tiempo, se negó a dar su bendición, reprendiendo al druida por su arrogancia. De acuerdo con Nozdormu, Alexstrasza también rechazó a Staghelm, y sin su bendición, el crecimiento de Teldrassil ha sido defectuoso e impredecible...', 0);
-- 936 Ayuda al archidruida Runatótem
-- https://es.classic.wowhead.com/quest=936
SET @ID := 936;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Me alegro de ver que estás $ginteresado:interesada; en colaborar en nuestra investigación. Queda mucho trabajo por delante y te mentiría si te dijese que no entraña peligro. Esperemos que esto no te haga desistir... aunque ya se ve que no es la primera vez que le plantas cara al peligro.', 0),
(@ID, 'esMX', 'Saludos, $c. Me alegro de ver que estás $ginteresado:interesada; en colaborar en nuestra investigación. Queda mucho trabajo por delante y te mentiría si te dijese que no entraña peligro. Esperemos que esto no te haga desistir... aunque ya se ve que no es la primera vez que le plantas cara al peligro.', 0);
-- 938 Niebla
-- https://es.classic.wowhead.com/quest=938
SET @ID := 938;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fue mi culpa! Las brujas me tomaron con la guardia baja... no debí dejar que se llevaran a Niebla...', 0),
(@ID, 'esMX', '¡Fue mi culpa! Las brujas me tomaron con la guardia baja... no debí dejar que se llevaran a Niebla...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, muchas gracias, $n! Tenía miedo de no volver a ver a Niebla nunca más y tener que llorar su muerte sin poder contar con su fiel compañía. Te debo más de lo que imaginas y tienes mi eterna gratitud.', 0),
(@ID, 'esMX', '¡Oh, muchas gracias, $n! Tenía miedo de no volver a ver a Niebla nunca más y tener que llorar su muerte sin poder contar con su fiel compañía. Te debo más de lo que imaginas y tienes mi eterna gratitud.', 0);
-- 939 La Flauta de Xavaric
-- https://es.classic.wowhead.com/quest=939
SET @ID := 939;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué ocurre? Pareces $gpreocupado:preocupada;.', 0),
(@ID, 'esMX', '¿Qué ocurre? Pareces $gpreocupado:preocupada;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento el sufrimiento de los ancestros, $n.$B$BTocar estos objetos es casi insoportable...', 0),
(@ID, 'esMX', 'Siento el sufrimiento de los ancestros, $n.$B$BTocar estos objetos es casi insoportable...', 0);
-- 941 Plantar el corazón
-- https://es.classic.wowhead.com/quest=941
SET @ID := 941;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta maceta contiene tierra que el propio Denalan ha seleccionado.', 0),
(@ID, 'esMX', 'Esta maceta contiene tierra que el propio Denalan ha seleccionado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el corazón en el interior de la maceta ¡y él mismo se entierra!$B$BUnos segundos después, aparece limpio. Late lentamente... incitándote a cogerlo.', 0),
(@ID, 'esMX', 'Colocas el corazón en el interior de la maceta ¡y él mismo se entierra!$B$BUnos segundos después, aparece limpio. Late lentamente... incitándote a cogerlo.', 0);
-- 951 Las reliquias de Mathystra
-- https://es.classic.wowhead.com/quest=951
SET @ID := 951;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. ¿Ha tenido éxito tu exploración de las Ruinas de Mathystra?', 0),
(@ID, 'esMX', '$n. ¿Ha tenido éxito tu exploración de las Ruinas de Mathystra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias. Estas reliquias son del tiempo en el que Mathystra refulgía. El que fue el gran bastión de los elfos es apenas su sombra ahora, pero aún conserva fragmentos de su magia. Esperemos que podamos desvelar los secretos de ese lugar antes que nuestros enemigos...$B$BMantente alerta, $n.', 0),
(@ID, 'esMX', 'Gracias. Estas reliquias son del tiempo en el que Mathystra refulgía. El que fue el gran bastión de los elfos es apenas su sombra ahora, pero aún conserva fragmentos de su magia. Esperemos que podamos desvelar los secretos de ese lugar antes que nuestros enemigos...$B$BMantente alerta, $n.', 0);
-- 953 La caída de Ameth'Aran
-- https://es.classic.wowhead.com/quest=953
SET @ID := 953;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Lee La instauración de Ameth\'Aran', `ObjectiveText2` = 'Lee La caída de Ameth\'Aran', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 957 Bashal'Aran
-- https://es.classic.wowhead.com/quest=957
SET @ID := 957;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Destruye el sello en la llama antigua', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 961 Onus lo está meditando
-- https://es.classic.wowhead.com/quest=961
SET @ID := 961;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El hallazgo de los cultistas de Martillo Crepuscular es preocupante. Debo meditar sobre sus intenciones...$B$BCuando tengas más información, háblame a través de un cuenco de adivinación. Si necesitas un frasco de adivinación para crear un cuenco... aquí tienes otro.', 0),
(@ID, 'esMX', 'El hallazgo de los cultistas de Martillo Crepuscular es preocupante. Debo meditar sobre sus intenciones...$B$BCuando tengas más información, háblame a través de un cuenco de adivinación. Si necesitas un frasco de adivinación para crear un cuenco... aquí tienes otro.', 0);
-- 962 Reptilia
-- https://es.classic.wowhead.com/quest=962
SET @ID := 962;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy deseando comprobar si eres capaz de recoger suficientes reptilias en las Cuevas de los Lamentos. Ya he enviado a muchos allí pero ninguno de ellos ha vuelto.', 0),
(@ID, 'esMX', 'Estoy deseando comprobar si eres capaz de recoger suficientes reptilias en las Cuevas de los Lamentos. Ya he enviado a muchos allí pero ninguno de ellos ha vuelto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, unos ejemplares estupendos! Lo has hecho muy bien, $n.', 0),
(@ID, 'esMX', '¡Ah, unos ejemplares estupendos! Lo has hecho muy bien, $n.', 0);
-- 964 Trozos esqueléticos
-- https://es.classic.wowhead.com/quest=964
SET @ID := 964;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mata a muchos y mátalos rápido, $c. Necesitaremos un suministro abundante de trozos esqueléticos para la capa externa de la llave. Por algo se llama Llave esqueleto, ¿sabes?', 0),
(@ID, 'esMX', 'Mata a muchos y mátalos rápido, $c. Necesitaremos un suministro abundante de trozos esqueléticos para la capa externa de la llave. Por algo se llama Llave esqueleto, ¿sabes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto valdrá, $n! Ahora me toca a mí, los imbuiré con un temple adecuado que impedirá que se destruyan en el proceso de fundición por el que van a pasar.$B$BEl siguiente paso consistirá en conseguir el molde adecuado para la llave. Conozco a un herrero goblin en Tanaris que en el pasado hizo moldes para objetos igual de macabros. Trabaja para quien trabajan todos los goblins: el mejor postor.', 0),
(@ID, 'esMX', '¡Esto valdrá, $n! Ahora me toca a mí, los imbuiré con un temple adecuado que impedirá que se destruyan en el proceso de fundición por el que van a pasar.$B$BEl siguiente paso consistirá en conseguir el molde adecuado para la llave. Conozco a un herrero goblin en Tanaris que en el pasado hizo moldes para objetos igual de macabros. Trabaja para quien trabajan todos los goblins: el mejor postor.', 0);
-- 972 La sapta de agua
-- https://es.classic.wowhead.com/quest=972
SET @ID := 972;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lleva la sapta del agua y encuentra la poza de agua corrupta del Bosque de Argénteos, $n. Tengo mucha fe en tus facultades.', 0),
(@ID, 'esMX', 'Lleva la sapta del agua y encuentra la poza de agua corrupta del Bosque de Argénteos, $n. Tengo mucha fe en tus facultades.', 0);
-- 974 Busca la fuente
-- https://es.classic.wowhead.com/quest=974
SET @ID := 974;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Busca el punto más caliente de la Cresta del Penacho en Llamas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 1022 La Vega del Aullido
-- https://es.classic.wowhead.com/quest=1022
SET @ID := 1022;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Estudia el Libro de Mel\'Thandris', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 1041 La ruta de la caravana
-- https://es.classic.wowhead.com/quest=1041
SET @ID := 1041;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con todos los extraños sucesos de los últimos años, guardo un registro de todos los forasteros. Nunca sabes cuándo va a ser necesario... Aunque no suele ser para un asunto agradable cuando se necesita. No pienses que estoy diciendo nada malo de esa Velinde a quien buscas.', 0),
(@ID, 'esMX', 'Con todos los extraños sucesos de los últimos años, guardo un registro de todos los forasteros. Nunca sabes cuándo va a ser necesario... Aunque no suele ser para un asunto agradable cuando se necesita. No pienses que estoy diciendo nada malo de esa Velinde a quien buscas.', 0);
-- 1042 La familia Carevin
-- https://es.classic.wowhead.com/quest=1042
SET @ID := 1042;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son tiempos oscuros. Cada rama que se mece al viento susurra noticias funestas y el mal puede encontrarse bajo cada piedra del camino.$B$BY en estos tiempos, $gun perfecto extraño:una perfecta extraña; entra en mi casa y me habla de ferocanis... No pediré perdón por mis sospechas, solo respuestas.$B$BY respuestas es lo que obtendré.', 0),
(@ID, 'esMX', 'Estos son tiempos oscuros. Cada rama que se mece al viento susurra noticias funestas y el mal puede encontrarse bajo cada piedra del camino.$B$BY en estos tiempos, $gun perfecto extraño:una perfecta extraña; entra en mi casa y me habla de ferocanis... No pediré perdón por mis sospechas, solo respuestas.$B$BY respuestas es lo que obtendré.', 0);
-- 1043 La Guadaña de Elune
-- https://es.classic.wowhead.com/quest=1043
SET @ID := 1043;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Encuentra indicios de la Guadaña de Elune', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los bosques son peligrosos para quienes no están bien preparados. Ten tus armas bien a mano y mantente alerta, o tu siguiente excursión al bosque encantado será la última.', 0),
(@ID, 'esMX', 'Los bosques son peligrosos para quienes no están bien preparados. Ten tus armas bien a mano y mantente alerta, o tu siguiente excursión al bosque encantado será la última.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu historia es interesante, $n. Aunque la influencia de la familia Carevin no es tanta, no podremos encontrar las raíces de estos problemas y acabar con ellos para siempre. Pero haremos lo que podamos para contener el número de ferocanis en el Bosque del Ocaso.$B$BYa he dado instrucciones a Calor para que esta sea su prioridad.', 0),
(@ID, 'esMX', 'Tu historia es interesante, $n. Aunque la influencia de la familia Carevin no es tanta, no podremos encontrar las raíces de estos problemas y acabar con ellos para siempre. Pero haremos lo que podamos para contener el número de ferocanis en el Bosque del Ocaso.$B$BYa he dado instrucciones a Calor para que esta sea su prioridad.', 0);
-- 1044 La respuesta a las preguntas
-- https://es.classic.wowhead.com/quest=1044
SET @ID := 1044;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que esta fue la suerte que corrió Velinde... Esta noticia decepcionará a la suma sacerdotisa... Eran buenas amigas antes de que desapareciera. Aún así, la Guadaña de Elune le fue concedida por nuestra diosa y es inquietante pensar que ya no esté en manos de su sierva.$B$BPero de este asunto trataremos en otro momento. No sabes cuánto te agradezco lo que has hecho.', 0),
(@ID, 'esMX', 'Así que esta fue la suerte que corrió Velinde... Esta noticia decepcionará a la suma sacerdotisa... Eran buenas amigas antes de que desapareciera. Aún así, la Guadaña de Elune le fue concedida por nuestra diosa y es inquietante pensar que ya no esté en manos de su sierva.$B$BPero de este asunto trataremos en otro momento. No sabes cuánto te agradezco lo que has hecho.', 0);
-- 1048 En el Monasterio Escarlata
-- https://es.classic.wowhead.com/quest=1048
SET @ID := 1048;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás no fui explícito en mis órdenes, $c. Quiero que mates a la alta inquisidora Melenablanca de una vez por todas. Y mientras estás en eso, elimina también a sus altos mandos.$B$BMata a ese fanático, al comandante Escarlata Mograine. Destruye a Herod, el Campeón Escarlata. Y masacrar al maestro de canes Loksey y sus asquerosos chuchos también.$B$B¡Ahora vete!', 0),
(@ID, 'esMX', 'Quizás no fui explícito en mis órdenes, $c. Quiero que mates a la alta inquisidora Melenablanca de una vez por todas. Y mientras estás en eso, elimina también a sus altos mandos.$B$BMata a ese fanático, al comandante Escarlata Mograine. Destruye a Herod, el Campeón Escarlata. Y masacrar al maestro de canes Loksey y sus asquerosos chuchos también.$B$B¡Ahora vete!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has servido con diligencia a la Dama Oscura, $c. Lo que te pedí no era tarea fácil.$B$BSe tendrá en cuenta tu lealtad a los Renegados y siempre será recordada tu tenacidad en el combate.', 0),
(@ID, 'esMX', 'Has servido con diligencia a la Dama Oscura, $c. Lo que te pedí no era tarea fácil.$B$BSe tendrá en cuenta tu lealtad a los Renegados y siempre será recordada tu tenacidad en el combate.', 0);
-- 1049 El Compendio de los Caídos
-- https://es.classic.wowhead.com/quest=1049
SET @ID := 1049;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cairne es un líder valiente y noble y confío en él ciegamente, cosa que no puedo decir de otros dirigentes.$B$BCuando cuente con todos los datos necesarios, podré aconsejar al Jefe.$B$B¿Has tenido oportunidad de viajar al Claro de Tirisfal? ¿Al Monasterio Escarlata? El Compendio de los Caídos es una pieza más de este complicado puzzle...', 0),
(@ID, 'esMX', 'Cairne es un líder valiente y noble y confío en él ciegamente, cosa que no puedo decir de otros dirigentes.$B$BCuando cuente con todos los datos necesarios, podré aconsejar al Jefe.$B$B¿Has tenido oportunidad de viajar al Claro de Tirisfal? ¿Al Monasterio Escarlata? El Compendio de los Caídos es una pieza más de este complicado puzzle...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El Compendio de los Caídos! Me empezaba a preguntar si ese libro realmente existía.$B$BHas servido fielmente a los tauren de Cima del Trueno, $n. Tu dedicación no se olvidará.', 0),
(@ID, 'esMX', '¡El Compendio de los Caídos! Me empezaba a preguntar si ese libro realmente existía.$B$BHas servido fielmente a los tauren de Cima del Trueno, $n. Tu dedicación no se olvidará.', 0);
-- 1051 La venganza de Vorrel
-- https://es.classic.wowhead.com/quest=1051
SET @ID := 1051;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué quieres?', 0),
(@ID, 'esMX', '¿Qué quieres?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vorrel tenía muchos problemas, pero era un buen compañero...$B$B¡Malditos humanos!$B$BPero al menos te vengaste en su nombre y te lo agradezco.$B$BPor favor, déjame sola...', 0),
(@ID, 'esMX', 'Vorrel tenía muchos problemas, pero era un buen compañero...$B$B¡Malditos humanos!$B$BPero al menos te vengaste en su nombre y te lo agradezco.$B$BPor favor, déjame sola...', 0);
