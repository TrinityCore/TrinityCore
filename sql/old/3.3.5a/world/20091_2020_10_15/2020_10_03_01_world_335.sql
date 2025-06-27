-- 5536 Una tierra llena de odio
-- https://es.classic.wowhead.com/quest=5536
SET @ID := 5536;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu batalla contra los sátiros, $c?$B$B¿Son tan fuertes como pensabas? ¿Más fuerte? O tal vez no eran nada para tu propia fuerza.', 0),
(@ID, 'esMX', '¿Cómo va tu batalla contra los sátiros, $c?$B$B¿Son tan fuertes como pensabas? ¿Más fuerte? O tal vez no eran nada para tu propia fuerza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $c. Veo que no solo eres $ghabilidoso:habilidosa; sino también $gastuto:astuta;. La derrota de tales criaturas es un testimonio de tu lealtad a los inquilinos de la Madre Tierra, aunque no la reconozcas como tu propia deidad. Está presente en todas las cosas de este planeta y más allá. Sus ojos, uno oscuro y otro claro, viajan por el cielo siempre pendientes de nosotros.$B$BAcepta este puñado de monedas como muestra de aprecio por lo que has hecho.', 0),
(@ID, 'esMX', 'Muy bien, $c. Veo que no solo eres $ghabilidoso:habilidosa; sino también $gastuto:astuta;. La derrota de tales criaturas es un testimonio de tu lealtad a los inquilinos de la Madre Tierra, aunque no la reconozcas como tu propia deidad. Está presente en todas las cosas de este planeta y más allá. Sus ojos, uno oscuro y otro claro, viajan por el cielo siempre pendientes de nosotros.$B$BAcepta este puñado de monedas como muestra de aprecio por lo que has hecho.', 0);
-- 3461 Regresa junto a Tymor
-- https://es.classic.wowhead.com/quest=3461
SET @ID := 3461;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estás de vuelta! Excelente. ¿También tienes mi kit de dibujo?', 0),
(@ID, 'esMX', '¡Estás de vuelta! Excelente. ¿También tienes mi kit de dibujo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! Me alegro mucho de escucharlo.$B$BEstoy muy ansioso por llegar a mi torre y repasar esos calcos. Tengo tanta envidia de que... vayas a un lugar como Azshara. Ese es el sueño de cualquier estudiante de lo arcano, supongo.$B$BBueno, nunca hablamos de ningún tipo de recompensa ya que solo trabajabas para la Liga de Exploradores, pero te mereces algo.', 0),
(@ID, 'esMX', '¡Maravilloso! Me alegro mucho de escucharlo.$B$BEstoy muy ansioso por llegar a mi torre y repasar esos calcos. Tengo tanta envidia de que... vayas a un lugar como Azshara. Ese es el sueño de cualquier estudiante de lo arcano, supongo.$B$BBueno, nunca hablamos de ningún tipo de recompensa ya que solo trabajabas para la Liga de Exploradores, pero te mereces algo.', 0);
-- 1119 La mezcla de Zanzil y la cerveza de tontos
-- https://es.classic.wowhead.com/quest=1119
SET @ID := 1119;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Pinchabujas nos ha echado una mano o no?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Pinchabujas nos ha echado una mano o no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! ¡Pinchabujas me ha echado una mano! Lo recordaré la próxima vez que lo vea.$B$BGracias, $n. Estás haciendo un buen trabajo y ambos vamos a ganar mucho con todo esto...', 0),
(@ID, 'esMX', '¡Estupendo! ¡Pinchabujas me ha echado una mano! Lo recordaré la próxima vez que lo vea.$B$BGracias, $n. Estás haciendo un buen trabajo y ambos vamos a ganar mucho con todo esto...', 0);
-- 1120 Emborrachar a los gnomos
-- https://es.classic.wowhead.com/quest=1120
SET @ID := 1120;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¡Hola! ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cerveza? ¡Qué detalle por tu parte! ¡Gracias!$B$BNo deberíamos beber antes de la carrera pero un poquito de nada no les hará daño a los chicos. Además, no será tan fuerte, ¿verdad?', 0),
(@ID, 'esMX', '¿Cerveza? ¡Qué detalle por tu parte! ¡Gracias!$B$BNo deberíamos beber antes de la carrera pero un poquito de nada no les hará daño a los chicos. Además, no será tan fuerte, ¿verdad?', 0);
-- 1121 Emborrachar a los goblins
-- https://es.classic.wowhead.com/quest=1121
SET @ID := 1121;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué estás mirando?', 0),
(@ID, 'esMX', '¿Qué estás mirando?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tenemos aquí? Bebida, ¿eh?$B$BBueno, no importa si solo bebemos un poco...', 0),
(@ID, 'esMX', '¿Qué tenemos aquí? Bebida, ¿eh?$B$BBueno, no importa si solo bebemos un poco...', 0);
-- 1122 Volver a informar a Pinchabujas
-- https://es.classic.wowhead.com/quest=1122
SET @ID := 1122;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Ha funcionado la cerveza o no? Es fuerte, ¿verdad?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Ha funcionado la cerveza o no? Es fuerte, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí dice que la cerveza de tontos ha sido todo un éxito. ¡Qué noticia tan buena!$B$BSi necesitas más, solo tienes que decírmelo y conseguir un poco de mezcla de Zanzil.', 0),
(@ID, 'esMX', 'Aquí dice que la cerveza de tontos ha sido todo un éxito. ¡Qué noticia tan buena!$B$BSi necesitas más, solo tienes que decírmelo y conseguir un poco de mezcla de Zanzil.', 0);
-- 8893 El Superhuevomático
-- https://es.classic.wowhead.com/quest=8893
SET @ID := 8893;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0),
(@ID, 'esMX', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0),
(@ID, 'esMX', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0);
-- 2748 Un huevo de primera
-- https://es.classic.wowhead.com/quest=2748
SET @ID := 2748;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un buen huevo es aquel que, en condiciones ideales, eclosionará libre de los efectos malignos de los encantamientos de los ogros Gordunni.', 0),
(@ID, 'esMX', 'Un buen huevo es aquel que, en condiciones ideales, eclosionará libre de los efectos malignos de los encantamientos de los ogros Gordunni.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. ¡Enviaré este huevo a Darnassus donde espero que pronto eclosione!$B$BAcepta esto como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Muy bien, $n. ¡Enviaré este huevo a Darnassus donde espero que pronto eclosione!$B$BAcepta esto como muestra de mi gratitud.', 0);
-- 2747 Un huevo muy especial
-- https://es.classic.wowhead.com/quest=2747
SET @ID := 2747;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He visto muy pocos huevos recuperados de Feralas en condiciones extraordinarias. Estos son huevos del tipo más raro...', 0),
(@ID, 'esMX', 'He visto muy pocos huevos recuperados de Feralas en condiciones extraordinarias. Estos son huevos del tipo más raro...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ahora tienes ¡algo increíble!$B$BEspero que recuerdes siempre el bien que has hecho hoy.', 0),
(@ID, 'esMX', 'Bueno, ahora tienes ¡algo increíble!$B$BEspero que recuerdes siempre el bien que has hecho hoy.', 0);
-- 2749 Un huevo normal
-- https://es.classic.wowhead.com/quest=2749
SET @ID := 2749;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los huevos de hipogrifo comunes eclosionan aproximadamente en la mitad del tiempo. Hacemos nuestro mejor esfuerzo para cuidarlos y, con un poco de suerte, eclosionarán.', 0),
(@ID, 'esMX', 'Los huevos de hipogrifo comunes eclosionan aproximadamente en la mitad del tiempo. Hacemos nuestro mejor esfuerzo para cuidarlos y, con un poco de suerte, eclosionarán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿has encontrado un huevo común, $n? Por favor dámelo... Y solo podemos esperar lo mejor.$B$BNo tengo mucho, pero acepta esta recompensa. Si alguna vez te encuentras en Feralas de nuevo, debes saber que siempre estoy aquí para que me traigas los huevos que encuentres allí.', 0),
(@ID, 'esMX', 'Entonces, ¿has encontrado un huevo común, $n? Por favor dámelo... Y solo podemos esperar lo mejor.$B$BNo tengo mucho, pero acepta esta recompensa. Si alguna vez te encuentras en Feralas de nuevo, debes saber que siempre estoy aquí para que me traigas los huevos que encuentres allí.', 0);
-- 2750 Un huevo pasado
-- https://es.classic.wowhead.com/quest=2750
SET @ID := 2750;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos huevos que no se pueden salvar, nunca eclosionarán.', 0),
(@ID, 'esMX', 'Estos huevos que no se pueden salvar, nunca eclosionarán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me temo que tengo malas noticias para ti, $n. Este huevo no sirve. Te lo cojo, pero únicamente para que sea desechado como es debido.$B$BPor favor, no permitas que esto te desanime; no podemos salvarlos a todos. Si vuelves alguna vez a Feralas, inténtalo de nuevo... ¡y trae otro huevo para el Superhuevomático!', 0),
(@ID, 'esMX', 'Me temo que tengo malas noticias para ti, $n. Este huevo no sirve. Te lo cojo, pero únicamente para que sea desechado como es debido.$B$BPor favor, no permitas que esto te desanime; no podemos salvarlos a todos. Si vuelves alguna vez a Feralas, inténtalo de nuevo... ¡y trae otro huevo para el Superhuevomático!', 0);
-- 2519 El templo de la Luna
-- https://es.classic.wowhead.com/quest=2519
SET @ID := 2519;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que te envía la hermana Aquinne, ¿verdad?', 0),
(@ID, 'esMX', 'Así que te envía la hermana Aquinne, ¿verdad?', 0);
-- 2518 Las lágrimas de la Luna
-- https://es.classic.wowhead.com/quest=2518
SET @ID := 2518;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento haberte encomendado esta tarea pero entiende que queda poca esperanza para Lady Sathrah.$B$BLo único que nos queda es ofrecer el sacrificio de sus hilanderas a Elune. Con este sacrificio, Elune bendecirá a Sathrah de modo que podrá nacer de nuevo en paz.', 0),
(@ID, 'esMX', 'Siento haberte encomendado esta tarea pero entiende que queda poca esperanza para Lady Sathrah.$B$BLo único que nos queda es ofrecer el sacrificio de sus hilanderas a Elune. Con este sacrificio, Elune bendecirá a Sathrah de modo que podrá nacer de nuevo en paz.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El bosque llora por Lady Sathrah pero era algo que había que hacer.$B$BGracias, $n.', 0),
(@ID, 'esMX', 'El bosque llora por Lady Sathrah pero era algo que había que hacer.$B$BGracias, $n.', 0);
-- 4493 La marcha de los silítidos
-- https://es.classic.wowhead.com/quest=4493
SET @ID := 4493;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo entendido que te envió a mí Gracina. Tu experiencia combatiendo a esas bestias no tiene precio; no sé de nadie más que haya tratado con ellas. Y respecto a la idea de Gracina de que sacan su fuerza del Cráter de Un\'Goro... quizás sea así. Un\'Goro es una misteriosa y peligrosa jungla que hay al oeste de aquí. Quizás sea también el lugar en el que más podremos acercarnos a desvelar misterio de los silítidos.', 0),
(@ID, 'esMX', 'Tengo entendido que te envió a mí Gracina. Tu experiencia combatiendo a esas bestias no tiene precio; no sé de nadie más que haya tratado con ellas. Y respecto a la idea de Gracina de que sacan su fuerza del Cráter de Un\'Goro... quizás sea así. Un\'Goro es una misteriosa y peligrosa jungla que hay al oeste de aquí. Quizás sea también el lugar en el que más podremos acercarnos a desvelar misterio de los silítidos.', 0);
-- 730 ¿Problemas en Costa Oscura?
-- https://es.classic.wowhead.com/quest=730
SET @ID := 730;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cómo me alegro de que el arqueólogo jefe Mostachogris enviara a alguien a buscarnos...', 0),
(@ID, 'esMX', 'Cómo me alegro de que el arqueólogo jefe Mostachogris enviara a alguien a buscarnos...', 0);
-- 937 El claro encantado
-- https://es.classic.wowhead.com/quest=937
SET @ID := 937;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te resultará sencillo enfrentarte a sus potentes garras y a sus afilados picos con las facultades que posees, $n, pero confío en que no fallarás en esta misión.', 0),
(@ID, 'esMX', 'No te resultará sencillo enfrentarte a sus potentes garras y a sus afilados picos con las facultades que posees, $n, pero confío en que no fallarás en esta misión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me impresiona realmente ver lo que has conseguido en un plazo tan corto de tiempo, $n, tanto que me gustaría pedirte que te quedaras para ayudarme... pero en el fondo de mi corazón sé que te esperan tareas más importantes.$B$BMe he dado cuenta de que el Árbol del Oráculo se ha despojado de una parte de su corteza. Seguro que hay algo en lo que puedas ayudarle, así que ve a hablar con él.', 0),
(@ID, 'esMX', 'Me impresiona realmente ver lo que has conseguido en un plazo tan corto de tiempo, $n, tanto que me gustaría pedirte que te quedaras para ayudarme... pero en el fondo de mi corazón sé que te esperan tareas más importantes.$B$BMe he dado cuenta de que el Árbol del Oráculo se ha despojado de una parte de su corteza. Seguro que hay algo en lo que puedas ayudarle, así que ve a hablar con él.', 0);
-- 931 Fronda fulgurante
-- https://es.classic.wowhead.com/quest=931
SET @ID := 931;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿De dónde has sacado esto? No veía una planta como esta desde aquella vez que estuve en el Pantano de las Penas... ¡hace décadas! Es increíble que haya llegado hasta Teldrassil, ¡y que haya alcanzado este tamaño!$B$BGracias, $n. Perdona la brevedad de mis palabras pero me gustaría someter a esta hoja a una prueba...', 0),
(@ID, 'esMX', '¿De dónde has sacado esto? No veía una planta como esta desde aquella vez que estuve en el Pantano de las Penas... ¡hace décadas! Es increíble que haya llegado hasta Teldrassil, ¡y que haya alcanzado este tamaño!$B$BGracias, $n. Perdona la brevedad de mis palabras pero me gustaría someter a esta hoja a una prueba...', 0);
-- 940 Teldrassil
-- https://es.classic.wowhead.com/quest=940
SET @ID := 940;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... El espíritu del bosque habita en tu interior, $c. ¿Qué te trae ante el archidruida de los Kaldorei?', 0),
(@ID, 'esMX', 'Mmm... El espíritu del bosque habita en tu interior, $c. ¿Qué te trae ante el archidruida de los Kaldorei?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me preguntaba por qué el Árbol del Oráculo llevaba tanto tiempo sin ponerse en contacto conmigo. Parece que mientras unos problemas se solventan otros surgen para sembrar la inquietud.$B$BTemo que mi trabajo en Teldrassil nunca llegue a buen puerto y que nunca recuperemos nuestra inmortalidad.$B$BNo obstante, tú has cumplido el cometido asignado por el Árbol del Oráculo y deberías obtener una recompensa por tu diligencia.', 0),
(@ID, 'esMX', 'Me preguntaba por qué el Árbol del Oráculo llevaba tanto tiempo sin ponerse en contacto conmigo. Parece que mientras unos problemas se solventan otros surgen para sembrar la inquietud.$B$BTemo que mi trabajo en Teldrassil nunca llegue a buen puerto y que nunca recuperemos nuestra inmortalidad.$B$BNo obstante, tú has cumplido el cometido asignado por el Árbol del Oráculo y deberías obtener una recompensa por tu diligencia.', 0);
-- 2399 Flora en brote
-- https://es.classic.wowhead.com/quest=2399
SET @ID := 2399;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las hojas que Denalan plantó en su jardín han retoñado y crecido. Esperan con impaciencia a que alguien las coja...', 0),
(@ID, 'esMX', 'Las hojas que Denalan plantó en su jardín han retoñado y crecido. Esperan con impaciencia a que alguien las coja...', 0);
-- 4161 La receta de los kaldorei
-- https://es.classic.wowhead.com/quest=4161
SET @ID := 4161;
UPDATE `quest_template_locale` SET `Objectives` = 'Recoge 7 patas de araña pequeña para Zarrin, que está en Dolanaar.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda el equilibrio, $n. Quiero que comprendas y te compenetres con los bosques.', 0),
(@ID, 'esMX', 'Recuerda el equilibrio, $n. Quiero que comprendas y te compenetres con los bosques.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda siempre lo que te he enseñado hoy, $n. Tú formas parte del equilibrio que los elfos de la noche se esfuerzan por conservar, incluso en tiempos difíciles.', 0),
(@ID, 'esMX', 'Recuerda siempre lo que te he enseñado hoy, $n. Tú formas parte del equilibrio que los elfos de la noche se esfuerzan por conservar, incluso en tiempos difíciles.', 0);
-- 997 Las tierras de Denalan
-- https://es.classic.wowhead.com/quest=997
SET @ID := 997;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, aquí está! Llevo tiempo esperando este paquete con tierras especiales. Espero que todavía esté en buen estado...$B$BGracias por traérmela, $n. Eres $gun:una; $r $gcomprometido:comprometida; con su tiempo.', 0),
(@ID, 'esMX', '¡Ah, aquí está! Llevo tiempo esperando este paquete con tierras especiales. Espero que todavía esté en buen estado...$B$BGracias por traérmela, $n. Eres $gun:una; $r $gcomprometido:comprometida; con su tiempo.', 0);
