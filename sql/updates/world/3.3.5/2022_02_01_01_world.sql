-- 10709 Reunión
-- https://es.tbc.wowhead.com/quest=10709
SET @ID := 10709;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que mi padre todavía vive. No esperaba que me perdonase, él no es así. Pero sí esperaba que los años hubiesen calmado la furia que debió de sentir cuando me marché.$B$BHace treinta años, dejé a los Mok\'Nathal para seguir a la Horda hasta Azeroth. Leoroxx no quería que lo hiciese, pero tampoco me dio ninguna razón para quedarme. De todas formas, me esperaba una bienvenida más cálida.$B$BQuería un Mok\'Nathal como hijo y tiene uno, aunque no lo sepa.$B$BDebo abrirle los ojos.', 0),
(@ID, 'esMX', 'Así que mi padre todavía vive. No esperaba que me perdonase, él no es así. Pero sí esperaba que los años hubiesen calmado la furia que debió de sentir cuando me marché.$B$BHace treinta años, dejé a los Mok\'Nathal para seguir a la Horda hasta Azeroth. Leoroxx no quería que lo hiciese, pero tampoco me dio ninguna razón para quedarme. De todas formas, me esperaba una bienvenida más cálida.$B$BQuería un Mok\'Nathal como hijo y tiene uno, aunque no lo sepa.$B$BDebo abrirle los ojos.', 0);
-- 10769 Disensión en las filas…
-- https://es.tbc.wowhead.com/quest=10769
SET @ID := 10769;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has regresado!', 0),
(@ID, 'esMX', '¡Has regresado!', 0);
-- 10777 El tótem de Asghar
-- https://es.tbc.wowhead.com/quest=10777
SET @ID := 10777;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el tótem de Asghar?', 0),
(@ID, 'esMX', '¿Has conseguido el tótem de Asghar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Parshah examina el tótem.>$B$BBien. Este viejo tótem no ha perdido su poder con los años, pero no es lo suficientemente poderoso como para detener al cónclave oscuro.', 0),
(@ID, 'esMX', '<Parshah examina el tótem.>$B$BBien. Este viejo tótem no ha perdido su poder con los años, pero no es lo suficientemente poderoso como para detener al cónclave oscuro.', 0);
-- 10778 La vara de Lianthe
-- https://es.tbc.wowhead.com/quest=10778
SET @ID := 10778;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la vara?', 0),
(@ID, 'esMX', '¿Has conseguido la vara?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. Un tesoro así se merece algo mejor que estar oculto en un oscuro cofre. Debemos usarla para algo digno.', 0),
(@ID, 'esMX', 'Bien hecho. Un tesoro así se merece algo mejor que estar oculto en un oscuro cofre. Debemos usarla para algo digno.', 0);
-- 10780 Plumas de Sketh'lon
-- https://es.tbc.wowhead.com/quest=10780
SET @ID := 10780;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido ya las plumas del bastón?', 0),
(@ID, 'esMX', '¿Has conseguido ya las plumas del bastón?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Parshah acepta las plumas polvorientas y mueve la cabeza en señal de desaprobación.>$B$BHabría sido mejor que hubiesen muerto ese día, pero nada es sencillo. La magia de Gul\'dan les habría convertido en el tipo de amenaza que estaban intentando detener. Habría sido una broma muy cruel del destino.', 0),
(@ID, 'esMX', '<Parshah acepta las plumas polvorientas y mueve la cabeza en señal de desaprobación.>$B$BHabría sido mejor que hubiesen muerto ese día, pero nada es sencillo. La magia de Gul\'dan les habría convertido en el tipo de amenaza que estaban intentando detener. Habría sido una broma muy cruel del destino.', 0);
-- 10781 La batalla de la Atalaya Carmesí
-- https://es.tbc.wowhead.com/quest=10781
SET @ID := 10781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<A\'dal te saluda.>', 0),
(@ID, 'esMX', '<A\'dal te saluda.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Habrá una investigación del Sigilo Carmesí. Suponen una amenaza a toda la vida de Draenor. Puedo ver el día en que su oscuro maestro tendrá que responder por sus crímenes. Quizás tú seas quien haga eso posible, $ghéroe:heroína;.', 0),
(@ID, 'esMX', 'Habrá una investigación del Sigilo Carmesí. Suponen una amenaza a toda la vida de Draenor. Puedo ver el día en que su oscuro maestro tendrá que responder por sus crímenes. Quizás tú seas quien haga eso posible, $ghéroe:heroína;.', 0);
-- 10782 Tratando la celada
-- https://es.tbc.wowhead.com/quest=10782
SET @ID := 10782;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has regresado con la celada llena de energía?', 0),
(@ID, 'esMX', '¿Has regresado con la celada llena de energía?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Parshah acepta la celada cogiéndola con ansiedad.>$B$BEsto contiene el poder que necesitamos para acabar con los esfuerzos del cónclave oscuro en el Campamento Sketh\'lon.', 0),
(@ID, 'esMX', '<Parshah acepta la celada cogiéndola con ansiedad.>$B$BEsto contiene el poder que necesitamos para acabar con los esfuerzos del cónclave oscuro en el Campamento Sketh\'lon.', 0);
-- 10784 Destrozar el Campamento Machacasangre
-- https://es.tbc.wowhead.com/quest=10784
SET @ID := 10784;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has destruido el Campamento Machacasangre?', 0),
(@ID, 'esMX', '¿Ya has destruido el Campamento Machacasangre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Tor\'chunk asiente con la cabeza en señal de aprobación.>$B$BNo dejas de impresionarme, $n. Cada vez que uno de esos apestosos ogros muere, nos acercamos mucho más a nuestra meta de librarnos de ellos para siempre.', 0),
(@ID, 'esMX', '<Tor\'chunk asiente con la cabeza en señal de aprobación.>$B$BNo dejas de impresionarme, $n. Cada vez que uno de esos apestosos ogros muere, nos acercamos mucho más a nuestra meta de librarnos de ellos para siempre.', 0);
-- 10785 ¡Es una trampa!
-- https://es.tbc.wowhead.com/quest=10785
SET @ID := 10785;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido lo que había en ese saco de gronn para Sablecrín? ¿Qué nos ha dado?', 0),
(@ID, 'esMX', '¿Has conseguido lo que había en ese saco de gronn para Sablecrín? ¿Qué nos ha dado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, ¿una trampa creada a partir de esencia de fuego de dragón? Me pregunto cómo hace Sablecrín para obtener esas sustancias tan extrañas.$B$BNo importa. Lo único que importa es que vamos a usarla para matar a un hijo de Gruul.', 0),
(@ID, 'esMX', 'Mmm, ¿una trampa creada a partir de esencia de fuego de dragón? Me pregunto cómo hace Sablecrín para obtener esas sustancias tan extrañas.$B$BNo importa. Lo único que importa es que vamos a usarla para matar a un hijo de Gruul.', 0);
-- 10786 Carnicería en Peña'mok
-- https://es.tbc.wowhead.com/quest=10786
SET @ID := 10786;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hemos recorrido un largo camino en poco tiempo, tú y yo. Me atrevo a decir que eres $gel cazador:la cazadora; de ogros más capaz que he conocido.$B$BEntonces, ¿confío en que pronto te ocuparás de los ogros de Peña\'mok?', 0),
(@ID, 'esMX', 'Hemos recorrido un largo camino en poco tiempo, tú y yo. Me atrevo a decir que eres $gel cazador:la cazadora; de ogros más capaz que he conocido.$B$BEntonces, ¿confío en que pronto te ocuparás de los ogros de Peña\'mok?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Tor\'chunk sonríe cuando le cuentas la historia de tus aventuras en Peña\'mok.>$B$BAh, me gustaría haber podido estar allí contigo. Deja que te diga algo, $n: nunca aceptes ninguna misión que te mantenga $galejado:alejada; de la gloria de la batalla.$B$B¡Ja! Después de todos los ogros que has matado, ¿todavía queda alguno en estas montañas para mí?', 0),
(@ID, 'esMX', '<Tor\'chunk sonríe cuando le cuentas la historia de tus aventuras en Peña\'mok.>$B$BAh, me gustaría haber podido estar allí contigo. Deja que te diga algo, $n: nunca aceptes ninguna misión que te mantenga $galejado:alejada; de la gloria de la batalla.$B$B¡Ja! Después de todos los ogros que has matado, ¿todavía queda alguno en estas montañas para mí?', 0);
-- 10788 Regresa junto a Talionia
-- https://es.tbc.wowhead.com/quest=10788
SET @ID := 10788;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces $gel:la; trotamundos regresa...$B$BEspero que mi sarcasmo sea evidente, $n, porque me has molestado mucho al obligarme a convocarte. Piensa que estás a un pelo de guardia vil de la incineración y que ellos no tienen pelo.$B$BPreste mucha atención, esta no es una lección que repetiré dos veces.', 0),
(@ID, 'esMX', 'Entonces $gel:la; trotamundos regresa...$B$BEspero que mi sarcasmo sea evidente, $n, porque me has molestado mucho al obligarme a convocarte. Piensa que estás a un pelo de guardia vil de la incineración y que ellos no tienen pelo.$B$BPreste mucha atención, esta no es una lección que repetiré dos veces.', 0);
-- 10789 Regresa junto a Carendin Halgar
-- https://es.tbc.wowhead.com/quest=10789
SET @ID := 10789;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, lo puedo verlo en tus ojos. Estás $gansioso:ansiosa; por aprender más.$B$BMuy bien, esta es una lección que ambos disfrutaremos.', 0),
(@ID, 'esMX', 'Sí, lo puedo verlo en tus ojos. Estás $gansioso:ansiosa; por aprender más.$B$BMuy bien, esta es una lección que ambos disfrutaremos.', 0);
-- 10790 Regresa junto a Gan'rul Ojosangre
-- https://es.tbc.wowhead.com/quest=10790
SET @ID := 10790;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es el conocimiento prohibido que ansías, ¿verdad? Puedo darte eso...', 0),
(@ID, 'esMX', 'Es el conocimiento prohibido que ansías, ¿verdad? Puedo darte eso...', 0);
-- 10791 Acoger al espíritu lobo
-- https://es.tbc.wowhead.com/quest=10791
SET @ID := 10791;
UPDATE `quest_template_locale` SET `ObjectiveText2` = 'Ayuda a Malukaz a invocar al espritu lobo', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Restablecer vínculos con el espíritu lobo es solo el comienzo de mi viaje, no el final.', 0),
(@ID, 'esMX', 'Restablecer vínculos con el espíritu lobo es solo el comienzo de mi viaje, no el final.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es increíble! Emprendí este viaje sin saber si el espíritu lobo respondería a nuestras invocaciones, y ahora parece como si siempre hubiera estado aquí. Quizás lo estaba, $n.$B$BQuizás esperaba que los orcos se dieran cuenta de lo que habían causado sus decisiones.', 0),
(@ID, 'esMX', '¡Esto es increíble! Emprendí este viaje sin saber si el espíritu lobo respondería a nuestras invocaciones, y ahora parece como si siempre hubiera estado aquí. Quizás lo estaba, $n.$B$BQuizás esperaba que los orcos se dieran cuenta de lo que habían causado sus decisiones.', 0);
-- 10792 ¡Zeth'Gor debe arder!
-- https://es.tbc.wowhead.com/quest=10792
SET @ID := 10792;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Barracones quemados', `ObjectiveText2` = 'Cobertizo del este quemado', `ObjectiveText3` = 'Cobertizo del oeste quemado', `ObjectiveText4` = 'Establo quemado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Zeth\'Gor debe arder, $n! Vuelve a hablar conmigo cuando hayas completado tu tarea.', 0),
(@ID, 'esMX', '¡Zeth\'Gor debe arder, $n! Vuelve a hablar conmigo cuando hayas completado tu tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! He podido ver el humo y las llamas de Zeth\'Gor desde aquí. ¡Que los demonios del clan Foso Sangrante se conviertan en cenizas y desaparezcan de la vista de los verdaderos orcos!$B$BGracias, $n. Has ayudado a acabar con una afrenta para el espíritu de los orcos.', 0),
(@ID, 'esMX', '¡Ja! He podido ver el humo y las llamas de Zeth\'Gor desde aquí. ¡Que los demonios del clan Foso Sangrante se conviertan en cenizas y desaparezcan de la vista de los verdaderos orcos!$B$BGracias, $n. Has ayudado a acabar con una afrenta para el espíritu de los orcos.', 0);
-- 10793 El diario de Val'zareq: augurios de guerra
-- https://es.tbc.wowhead.com/quest=10793
SET @ID := 10793;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El general Auralion está flotando en el centro de la prisión de cristal.>$B$B¿Qué... qué estás haciendo aquí?', 0),
(@ID, 'esMX', '<El general Auralion está flotando en el centro de la prisión de cristal.>$B$B¿Qué... qué estás haciendo aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado al conquistador? Entonces no tenemos mucho tiempo...$B$BEl Sigilo Carmesí es un grupo formado por la élite de los esbirros de Illidan. Están en lo alto de la cadena de mando de todas las fuerzas Illidari fuera del Templo Oscuro. Esos soldados se comunican directamente con el Traidor y cumplen sus órdenes sin cuestionarlas.$B$BSon los demonios que, sin duda, lideraron el asalto a este mundo, aplastando bajo sus pies todo lo que se interponía en su camino.', 0),
(@ID, 'esMX', '¿Has matado al conquistador? Entonces no tenemos mucho tiempo...$B$BEl Sigilo Carmesí es un grupo formado por la élite de los esbirros de Illidan. Están en lo alto de la cadena de mando de todas las fuerzas Illidari fuera del Templo Oscuro. Esos soldados se comunican directamente con el Traidor y cumplen sus órdenes sin cuestionarlas.$B$BSon los demonios que, sin duda, lideraron el asalto a este mundo, aplastando bajo sus pies todo lo que se interponía en su camino.', 0);
-- 10794 Pícaros de la Mano Destrozada
-- https://es.tbc.wowhead.com/quest=10794
SET @ID := 10794;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, ¿quieres trabajar para la Mano Destrozada? Parece que tenemos a alguien nuevo todos los días.$B$BPresta mucha atención y te explicaré lo que tienes que hacer.', 0),
(@ID, 'esMX', 'Entonces, ¿quieres trabajar para la Mano Destrozada? Parece que tenemos a alguien nuevo todos los días.$B$BPresta mucha atención y te explicaré lo que tienes que hacer.', 0);
-- 10795 Cita con Dorgok
-- https://es.tbc.wowhead.com/quest=10795
SET @ID := 10795;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo expresar con suficiente fuerza lo importante que es que mates a Dorgok lo más rápido posible.', 0),
(@ID, 'esMX', 'No puedo expresar con suficiente fuerza lo importante que es que mates a Dorgok lo más rápido posible.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con Dorgok muerto, los ogros Machacasangre no tienen líder y estarán en pleno caos hasta que otro líder salga de sus filas.$B$BGracias, $c, creo que al menos podemos respirar un poco más tranquilos por ahora.', 0),
(@ID, 'esMX', 'Con Dorgok muerto, los ogros Machacasangre no tienen líder y estarán en pleno caos hasta que otro líder salga de sus filas.$B$BGracias, $c, creo que al menos podemos respirar un poco más tranquilos por ahora.', 0);
-- 10797 El favor del gronn
-- https://es.tbc.wowhead.com/quest=10797
SET @ID := 10797;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gchico:chica;. ¿Qué noticias me traes?', 0),
(@ID, 'esMX', 'Hola, $gchico:chica;. ¿Qué noticias me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, muy bonito. Se parece mucho a esos gronn que siempre están dando órdenes a los ogros Aguja del Filo.$B$BQué extraño que lo encontraras en la mano de uno de los líderes Machacasangre.', 0),
(@ID, 'esMX', 'Oh, muy bonito. Se parece mucho a esos gronn que siempre están dando órdenes a los ogros Aguja del Filo.$B$BQué extraño que lo encontraras en la mano de uno de los líderes Machacasangre.', 0);
-- 10798 Una visita al barón
-- https://es.tbc.wowhead.com/quest=10798
SET @ID := 10798;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, un enviado de la Alianza. Dime, colega, ¿y qué haces tú aquí pidiéndome que haga algo en vez de tu ilustre comandante?$B$B¿Podría ser que yo le dé miedo? Dice algo sobre ti que no eres, pero todavía no he decidido qué es.', 0),
(@ID, 'esMX', 'Ah, un enviado de la Alianza. Dime, colega, ¿y qué haces tú aquí pidiéndome que haga algo en vez de tu ilustre comandante?$B$B¿Podría ser que yo le dé miedo? Dice algo sobre ti que no eres, pero todavía no he decidido qué es.', 0);
-- 10800 Buenas noches, Gronn
-- https://es.wowhead.com/quest=10800
SET @ID := 10800;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De nuevo nos vemos, $c. Esto debe de significar que has conseguido robarle el saco a Grulloc.', 0),
(@ID, 'esMX', 'De nuevo nos vemos, $c. Esto debe de significar que has conseguido robarle el saco a Grulloc.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El Barón Sablecrín echa un vistazo al saco del gronn y parece satisfecho.>$B$BMuy bien, has cumplido tu parte del trato. Y ahora, le daré esa trampa a tu comandante Muropiedra.', 0),
(@ID, 'esMX', '<El Barón Sablecrín echa un vistazo al saco del gronn y parece satisfecho.>$B$BMuy bien, has cumplido tu parte del trato. Y ahora, le daré esa trampa a tu comandante Muropiedra.', 0);
-- 10801 ¡Es una trampa!
-- https://es.wowhead.com/quest=10801
SET @ID := 10801;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El barón nos ha hecho una trampa? ¿Una lo suficientemente potente como para matar a un gronn?', 0),
(@ID, 'esMX', '¿El barón nos ha hecho una trampa? ¿Una lo suficientemente potente como para matar a un gronn?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, ¿una trampa creada a partir de esencia de llama de dragón? Me pregunto cómo hace Sablecrín para obtener esas sustancias tan extrañas.$B$BNo importa. Lo único que importa es que vamos a usarla para matar a un hijo de Gruul.', 0),
(@ID, 'esMX', 'Mmm, ¿una trampa creada a partir de esencia de llama de dragón? Me pregunto cómo hace Sablecrín para obtener esas sustancias tan extrañas.$B$BNo importa. Lo único que importa es que vamos a usarla para matar a un hijo de Gruul.', 0);
-- 10802 Gorgrom el Comedragones
-- https://es.wowhead.com/quest=10802
SET @ID := 10802;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Coloca Tótems repelentes', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has entregado el mensaje?', 0),
(@ID, 'esMX', '¿Has entregado el mensaje?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. ¡Bien hecho!$B$BSospecho que ya no tendremos muchas más noticias sobre los ogros y su maestro.', 0),
(@ID, 'esMX', 'Bien hecho, $n. ¡Bien hecho!$B$BSospecho que ya no tendremos muchas más noticias sobre los ogros y su maestro.', 0);
-- 10803 Carnicería en Peña'mok
-- https://es.wowhead.com/quest=10803
SET @ID := 10803;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me atrevo a decir que eres $gel cazador:la cazadora; de ogros más capaz que he conocido.$B$BEntonces, ¿confío en que pronto te ocuparás de los ogros de Peña\'mok?', 0),
(@ID, 'esMX', 'Me atrevo a decir que eres $gel cazador:la cazadora; de ogros más capaz que he conocido.$B$BEntonces, ¿confío en que pronto te ocuparás de los ogros de Peña\'mok?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La teniente Buentiempo sonríe cuando le cuentas la historia de tus aventuras en Peña\'mok.>$B$BAh, me gustaría haber podido estar allí contigo. Deja que te diga algo, $n: nunca aceptes ninguna misión que te mantenga $galejado:alejada; de la gloria de la batalla.$B$B¡Ja! Después de todos los ogros que has matado, ¿todavía queda alguno en estas montañas para mí?', 0),
(@ID, 'esMX', '<La teniente Buentiempo sonríe cuando le cuentas la historia de tus aventuras en Peña\'mok.>$B$BAh, me gustaría haber podido estar allí contigo. Deja que te diga algo, $n: nunca aceptes ninguna misión que te mantenga $galejado:alejada; de la gloria de la batalla.$B$B¡Ja! Después de todos los ogros que has matado, ¿todavía queda alguno en estas montañas para mí?', 0);
-- 10804 Bondad
-- https://es.wowhead.com/quest=10804
SET @ID := 10804;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Draco Ala Abisal adulto alimentado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo salvarlos yo solo, $n!', 0),
(@ID, 'esMX', '¡No puedo salvarlos yo solo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gun:una; $r amable y $gcompasivo:compasiva;, $gamigo:amiga;.', 0),
(@ID, 'esMX', 'Eres $gun:una; $r amable y $gcompasivo:compasiva;, $gamigo:amiga;.', 0);
-- 10805 Masacre en la Guarida de Gruul
-- https://es.wowhead.com/quest=10805
SET @ID := 10805;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado diezmar a los ogros Aguja del Filo en la Guarida de Gruul?$B$B¡No me vengas con excusas, $gchico:chica;! ¡Termina el trabajo!', 0),
(@ID, 'esMX', '¿Has logrado diezmar a los ogros Aguja del Filo en la Guarida de Gruul?$B$B¡No me vengas con excusas, $gchico:chica;! ¡Termina el trabajo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, por lo visto hice bien al elegirte a ti para la lucha. Creo que ha llegado la hora de pasar a un nuevo nivel.$B$B¿Recuerdas lo que robaste para mí en las mismas narices de Grulloc? Pues ahora vas a tener la oportunidad de usarlo.', 0),
(@ID, 'esMX', 'Perfecto, por lo visto hice bien al elegirte a ti para la lucha. Creo que ha llegado la hora de pasar a un nuevo nivel.$B$B¿Recuerdas lo que robaste para mí en las mismas narices de Grulloc? Pues ahora vas a tener la oportunidad de usarlo.', 0);
-- 10806 Enfrentamiento
-- https://es.wowhead.com/quest=10806
SET @ID := 10806;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con el tiempo, conseguiremos acabar con todos los hijos de Gruul.', 0),
(@ID, 'esMX', 'Con el tiempo, conseguiremos acabar con todos los hijos de Gruul.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has luchado sorprendentemente bien, $r, y ha sido un honor tenerte a mi lado. Mi transformación debe de haber sido una gran sorpresa para ti. Confío en que no haya sido demasiado...$B$BMantengamos mi verdadera identidad entre nosotros dos, ¿te parece? A cambio y por el gran servicio que nos has prestado, quiero que elijas algo de esto.', 0),
(@ID, 'esMX', 'Has luchado sorprendentemente bien, $r, y ha sido un honor tenerte a mi lado. Mi transformación debe de haber sido una gran sorpresa para ti. Confío en que no haya sido demasiado...$B$BMantengamos mi verdadera identidad entre nosotros dos, ¿te parece? A cambio y por el gran servicio que nos has prestado, quiero que elijas algo de esto.', 0);
-- 10807 Los Tábidos Lengua de ceniza
-- https://es.wowhead.com/quest=10807
SET @ID := 10807;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gloria a los Arúspices, $n. Has cumplido los deseos del Vidente al derrotar a los seguidores de Illidan.', 0),
(@ID, 'esMX', 'Gloria a los Arúspices, $n. Has cumplido los deseos del Vidente al derrotar a los seguidores de Illidan.', 0);
-- 10808 Frustra los planes del Cónclave
-- https://es.tbc.wowhead.com/quest=10808
SET @ID := 10808;
UPDATE `quest_template_locale` SET `ObjectiveText1` = '', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está hecho, $n? ¿Has evitado que el Cónclave Oscuro finalizara su ritual?', 0),
(@ID, 'esMX', '¿Está hecho, $n? ¿Has evitado que el Cónclave Oscuro finalizara su ritual?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He buscado una forma de detener el Cónclave Oscuro desde hace años, y tú has triunfado donde yo he fracasado. Los rituales oscuros del Cónclave ya no nos amenazarán más.$B$BA menudo me siento culpable por abandonar a mis compañeros hace tantos años, pero al fin ahora sé que tomé la decisión correcta. Si no hubiera sido por mi conciencia vacilante de entonces, podría haber acabado como una sombra entre ellos.', 0),
(@ID, 'esMX', 'He buscado una forma de detener el Cónclave Oscuro desde hace años, y tú has triunfado donde yo he fracasado. Los rituales oscuros del Cónclave ya no nos amenazarán más.$B$BA menudo me siento culpable por abandonar a mis compañeros hace tantos años, pero al fin ahora sé que tomé la decisión correcta. Si no hubiera sido por mi conciencia vacilante de entonces, podría haber acabado como una sombra entre ellos.', 0);
-- 10809 Se busca: Maestro de huargos Kruush
-- https://es.tbc.wowhead.com/quest=10809
SET @ID := 10809;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Informa, $n. ¿Esas manchas que veo en tu manga son de sangre de Foso Sangrante? ¡Eso espero!', 0),
(@ID, 'esMX', 'Informa, $n. ¿Esas manchas que veo en tu manga son de sangre de Foso Sangrante? ¡Eso espero!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así que mataste a ese horrible Kruush! Bien hecho, $n. ¡Bien hecho! Su muerte desestabilizará a esos jinetes de huargos. ¡En realidad, espero que te hayas cargado a alguno durante tu viaje a Zeth\'Gor!$B$BAquí está tu recompensa. ¡Te lo mereces!', 0),
(@ID, 'esMX', '¡Así que mataste a ese horrible Kruush! Bien hecho, $n. ¡Bien hecho! Su muerte desestabilizará a esos jinetes de huargos. ¡En realidad, espero que te hayas cargado a alguno durante tu viaje a Zeth\'Gor!$B$BAquí está tu recompensa. ¡Te lo mereces!', 0);
