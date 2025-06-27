-- 7023 ¡El Gran Padre Invierno está aquí!
-- https://es.wowhead.com/quest=7023
SET @ID := 7023;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0),
(@ID, 'esMX', 'Hola, hola. Soy el Gran Padre Invierno y quiero desearte un maravilloso Festival de Invierno por cortesía de Pastos de Bosquehumeante... "De la granja a la mesa, todo lo bueno de los Pastos de Bosquehumeante".$B$BSi te has portado bien este año, quizás recibas regalos de los Pastos de Bosquehumeante durante el festín del Festival de Invierno. ¿A que es genial?', 0);
-- 8356 Saca músculo a cambio de almendrados
-- https://es.wowhead.com/quest=8356
SET @ID := 8356;
UPDATE `quest_template_locale` SET `Objectives` = 'Saca músculos para la tabernera Allison y, a cambio, recibirás un almendrado de Ventormenta.', `VerifiedBuild` = 0 WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nada de dulces hasta que saques músculo para mí, $n...', 0),
(@ID, 'esMX', 'Nada de dulces hasta que saques músculo para mí, $n...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja, eres muy poderoso! Bien hecho, gracias por tener tan buen talante. Aquí tienes tus caramelos.$B$B¡Feliz Halloween, $n!', 0),
(@ID, 'esMX', '¡Ja, ja, eres muy poderoso! Bien hecho, gracias por tener tan buen talante. Aquí tienes tus caramelos.$B$B¡Feliz Halloween, $n!', 0);
-- 8371 Esfuerzos concertados
-- https://es.classic.wowhead.com/quest=8371
SET @ID := 8371;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te va en tus viajes, $gchico:chica;?', 0),
(@ID, 'esMX', '¿Cómo te va en tus viajes, $gchico:chica;?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No eres de los que decepcionan, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0),
(@ID, 'esMX', '¡No eres de los que decepcionan, $n! Lo que has aprendido va más allá de insignificantes medallas y elogios. Lo que has aprendido es lo que solo se obtiene con la experiencia y el endurecimiento del temperamento en el campo de batalla.$B$BLo has hecho bien, $c. ¡Eres $gun:una; $gverdadero:verdadera; $ghéroe:heroína; de la Alianza!', 0);
-- 7637 Énfasis en el sacrificio
-- https://es.classic.wowhead.com/quest=7637
SET @ID := 7637;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos, noble $c! He preparado mi incensario de confianza con el incienso más fresco y lo he bendecido tres veces para su uso. Tu donación nos ayudará en Forjaz no solo a crear un nuevo incensario, sino también a reforzar las reservas de comida para nuestros necesitados.', 0),
(@ID, 'esMX', '¡Saludos, noble $c! He preparado mi incensario de confianza con el incienso más fresco y lo he bendecido tres veces para su uso. Tu donación nos ayudará en Forjaz no solo a crear un nuevo incensario, sino también a reforzar las reservas de comida para nuestros necesitados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bendiciones para ti, $gamigo:amiga; $c! Tu donación va mucho más allá de lo necesario. Tu sacrificio no solo nos ayudará a recuperar lo que hemos perdido, sino que también nos ayudará a ayudar a los más necesitados aquí en Forjaz.$B$BAhora, déjeme asegurarme de haber preparado adecuadamente este incensario para tus necesidades futuras...', 0),
(@ID, 'esMX', '¡Bendiciones para ti, $gamigo:amiga; $c! Tu donación va mucho más allá de lo necesario. Tu sacrificio no solo nos ayudará a recuperar lo que hemos perdido, sino que también nos ayudará a ayudar a los más necesitados aquí en Forjaz.$B$BAhora, déjeme asegurarme de haber preparado adecuadamente este incensario para tus necesidades futuras...', 0);
-- 7639 Mostrarse juicioso
-- https://es.classic.wowhead.com/quest=7639
SET @ID := 7639;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido de nuevo, $n. ¿Has adquirido el incensario de exorcismo?', 0),
(@ID, 'esMX', 'Bienvenido de nuevo, $n. ¿Has adquirido el incensario de exorcismo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, esto servirá. Se le pedirá más de una vez durante este proceso para realizar actos de sacrificio; Me alegra ver que está dispuesto a hacer precisamente eso. El sacrificio es un componente clave en lo que se necesita para cumplir con los deberes de ser un Paladín ... pero no tengo que sermonearte sobre eso.$B$BAhora $n, deberás mostrar el debido juicio en tus acciones. Con ese fin, este incensario actuará como tu recipiente para emitir tal juicio sobre los espíritus torturados de tierras perdidas para nosotros.', 0),
(@ID, 'esMX', 'Sí, esto servirá. Se le pedirá más de una vez durante este proceso para realizar actos de sacrificio; Me alegra ver que está dispuesto a hacer precisamente eso. El sacrificio es un componente clave en lo que se necesita para cumplir con los deberes de ser un Paladín ... pero no tengo que sermonearte sobre eso.$B$BAhora $n, deberás mostrar el debido juicio en tus acciones. Con ese fin, este incensario actuará como tu recipiente para emitir tal juicio sobre los espíritus torturados de tierras perdidas para nosotros.', 0);
-- 658 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=658
SET @ID := 658;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te agradecemos tu ayuda en la búsqueda de ese mensajero, $n.$B$BMientras estabas ausente, Kin vio a un boticario salir de la misma casa al sur de este lugar. Estoy seguro que no pueden tramar nada bueno, solo necesito una prueba antes de salir y hacer algo imprudente.$B$B¿Has encontrado algo?', 0),
(@ID, 'esMX', 'Te agradecemos tu ayuda en la búsqueda de ese mensajero, $n.$B$BMientras estabas ausente, Kin vio a un boticario salir de la misma casa al sur de este lugar. Estoy seguro que no pueden tramar nada bueno, solo necesito una prueba antes de salir y hacer algo imprudente.$B$B¿Has encontrado algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico!$B$BVeamos de qué se trata...', 0),
(@ID, 'esMX', '¡Fantástico!$B$BVeamos de qué se trata...', 0);
-- 657 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=657
SET @ID := 657;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si le trae a Phin el descanso, destruiré personalmente uno a uno a esos Renegados. Ha hecho tanto por nosotros desde la Peste. Nunca pensé que volvería a ver a mis amigos o a la familia.$B$BDame un toque cuando estés <preparado(preparada>. Empezaremos enseguida.', 0),
(@ID, 'esMX', 'Si le trae a Phin el descanso, destruiré personalmente uno a uno a esos Renegados. Ha hecho tanto por nosotros desde la Peste. Nunca pensé que volvería a ver a mis amigos o a la familia.$B$BDame un toque cuando estés $gpreparado:preparada;. Empezaremos enseguida.', 0);
-- 660 Sospechas de una nueva Peste
-- https://es.wowhead.com/quest=660
SET @ID := 660;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos has hecho un gran favor, $n. Gracias.$B$BEspero que Kin no te lo pusiera demasiado difícil. Es muy simpática pero como enemiga es letal.', 0),
(@ID, 'esMX', 'Nos has hecho un gran favor, $n. Gracias.$B$BEspero que Kin no te lo pusiera demasiado difícil. Es muy simpática pero como enemiga es letal.', 0);
-- 661 Sospechas de una nueva Peste
-- https://es.classic.wowhead.com/quest=661
SET @ID := 661;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿Conque esas dos pícaras están bien después de todo?! Ja, ja, me alegra oírlo. Te agradezco las noticias sobre su paradero y su estado; me complace enormemente que sigan vivas, los dos son amigas insustituibles y viejas compañeras de fatigas.$B$BPero... es más importante que te agradezca como es debido tu ayuda. Aquí tienes además de la gratitud de todos los míos.$B$BCon algo de suerte, averiguaremos qué traman los Renegados y le pondremos fin.', 0),
(@ID, 'esMX', '¡¿Conque esas dos pícaras están bien después de todo?! Ja, ja, me alegra oírlo. Te agradezco las noticias sobre su paradero y su estado; me complace enormemente que sigan vivas, los dos son amigas insustituibles y viejas compañeras de fatigas.$B$BPero... es más importante que te agradezca como es debido tu ayuda. Aquí tienes además de la gratitud de todos los míos.$B$BCon algo de suerte, averiguaremos qué traman los Renegados y le pondremos fin.', 0);
-- 1105 Caparazones endurecidos
-- https://es.classic.wowhead.com/quest=1105
SET @ID := 1105;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi hermano está haciendo progresos en su nuevo combustible y eso me intranquiliza. ¡Quiero ponerme manos a la obra con el depósito de caparazón de tortura lo antes posible!$B$B$n, ¿tienes ya los caparazones?', 0),
(@ID, 'esMX', 'Mi hermano está haciendo progresos en su nuevo combustible y eso me intranquiliza. ¡Quiero ponerme manos a la obra con el depósito de caparazón de tortura lo antes posible!$B$B$n, ¿tienes ya los caparazones?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los has conseguido! ¡Gracias, $n!$B$BVaya, estos caparazones son más duros de lo que yo pensaba. ¡Voy a romper todas mis herramientas!', 0),
(@ID, 'esMX', '¡Los has conseguido! ¡Gracias, $n!$B$BVaya, estos caparazones son más duros de lo que yo pensaba. ¡Voy a romper todas mis herramientas!', 0);
-- 1176 Menos peso
-- https://es.classic.wowhead.com/quest=1176
SET @ID := 1176;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los huesos? Estaba pensando en aligerar la dirección pero no quiero empezar hasta tener todas las piezas que necesito.', 0),
(@ID, 'esMX', '¿Tienes los huesos? Estaba pensando en aligerar la dirección pero no quiero empezar hasta tener todas las piezas que necesito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! Ya puedo poner al equipo técnico a trabajar en esto. ¡Gracias, $n!', 0),
(@ID, 'esMX', '¡Genial! Ya puedo poner al equipo técnico a trabajar en esto. ¡Gracias, $n!', 0);
-- 1104 Veneno de El Desierto de Sal
-- https://es.classic.wowhead.com/quest=1104
SET @ID := 1104;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, hola, hola! ¿¿Conseguiste el veneno??', 0),
(@ID, 'esMX', '¡Hola, hola, hola! ¿¿Conseguiste el veneno??', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡Este veneno será perfecto! ¡Gracias, $n!$B$BAhora solo tengo que espesarlo algo, echarle un poco de correcina, añadir un negacatalizador y... ¡Maldición! ¿¡Dónde están mis notas!?', 0),
(@ID, 'esMX', '¡Genial! ¡Este veneno será perfecto! ¡Gracias, $n!$B$BAhora solo tengo que espesarlo algo, echarle un poco de correcina, añadir un negacatalizador y... ¡Maldición! ¿¡Dónde están mis notas!?', 0);
-- 1110 Las piezas de coche cohete
-- https://es.classic.wowhead.com/quest=1110
SET @ID := 1110;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has estado en El Desierto de Sal? ¿Me has traído las piezas que quería?', 0),
(@ID, 'esMX', '$n, ¿has estado en El Desierto de Sal? ¿Me has traído las piezas que quería?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, mira todo eso! Hay algunas cosas interesantes en ese montón de basura. Seguro que saco un buen pellizco por ellas.$B$BEspera... ¿eso que está ahí espachurrado es una oreja? ¡Qué dolor! No me gustaría ser ese piloto...$B$BGracias, $n. Aquí tienes tu dinero. Y te voy a dar un consejo gratis...$B$BSiempre se puede sacar beneficio de las desgracias ajenas.', 0),
(@ID, 'esMX', '¡Vaya, mira todo eso! Hay algunas cosas interesantes en ese montón de basura. Seguro que saco un buen pellizco por ellas.$B$BEspera... ¿eso que está ahí espachurrado es una oreja? ¡Qué dolor! No me gustaría ser ese piloto...$B$BGracias, $n. Aquí tienes tu dinero. Y te voy a dar un consejo gratis...$B$BSiempre se puede sacar beneficio de las desgracias ajenas.', 0);
-- 1175 Un bache en la carretera
-- https://es.classic.wowhead.com/quest=1175
SET @ID := 1175;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya es bastante malo tener que limpiar los restos de los corredores sin tener que sacarlos de partes de animales quemados.', 0),
(@ID, 'esMX', 'Ya es bastante malo tener que limpiar los restos de los corredores sin tener que sacarlos de partes de animales quemados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espero que no hayas matado a ningún basilisco en la pista! Sus cuerpos tardan mucho en descomponerse al sol y prefiero no tener que coger una pala para despejar la pista.', 0),
(@ID, 'esMX', '¡Espero que no hayas matado a ningún basilisco en la pista! Sus cuerpos tardan mucho en descomponerse al sol y prefiero no tener que coger una pala para despejar la pista.', 0);
-- 1178 Patrocinio goblin
-- https://es.classic.wowhead.com/quest=1178
SET @ID := 1178;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Pozzik, eh? Sabes, Pozzik era uno de los manitas más respetados de Minahonda hasta que decidió dejarlo todo para dedicarse a las carreras.$B$BLo primero que hizo tras unirse al equipo fue desarrollar el coche de doble motor. Puede ser que el negocio experimente un bajón ahora que él ya no trabaja en el Gremio de Manitas pero... ¿a quién le importa? ¡No hay nada como las carreras!', 0),
(@ID, 'esMX', '¿Te envía Pozzik, eh? Sabes, Pozzik era uno de los manitas más respetados de Minahonda hasta que decidió dejarlo todo para dedicarse a las carreras.$B$BLo primero que hizo tras unirse al equipo fue desarrollar el coche de doble motor. Puede ser que el negocio experimente un bajón ahora que él ya no trabaja en el Gremio de Manitas pero... ¿a quién le importa? ¡No hay nada como las carreras!', 0);
-- 1106 Martek el Exiliado
-- https://es.classic.wowhead.com/quest=1106
SET @ID := 1106;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Genial, me has encontrado. Bien por ti.$B$B¿Vienes por el hacha que le hice a Gath\'Ilzogg? ¿O acaso vienes a reclamar el honor de la duquesa Pamay?$B$BEn realidad, no me interesan tus motivos. Así que si estás aquí para pelear, acabemos cuanto antes...', 0),
(@ID, 'esMX', 'Genial, me has encontrado. Bien por ti.$B$B¿Vienes por el hacha que le hice a Gath\'Ilzogg? ¿O acaso vienes a reclamar el honor de la duquesa Pamay?$B$BEn realidad, no me interesan tus motivos. Así que si estás aquí para pelear, acabemos cuanto antes...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Fizzle? ¡Eso lo cambia todo! Pues claro que te voy a ayudar. ¡Fizzle y su hermano son de los pocos a los que no les gustaría verme muerto!$B$BAsí que Fizzle quiere unos pistones, ¿verdad? ¿Unos que aguanten bastante presión? Conociendo a Fizzle, ¡seguro que su nuevo coche será un volcán con ruedas!', 0),
(@ID, 'esMX', '¿Te envía Fizzle? ¡Eso lo cambia todo! Pues claro que te voy a ayudar. ¡Fizzle y su hermano son de los pocos a los que no les gustaría verme muerto!$B$BAsí que Fizzle quiere unos pistones, ¿verdad? ¿Unos que aguanten bastante presión? Conociendo a Fizzle, ¡seguro que su nuevo coche será un volcán con ruedas!', 0);
-- 1111 Maestro de muelles Vertipeluca
-- https://es.classic.wowhead.com/quest=1111
SET @ID := 1111;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Habla! Dime... ¿vienes a entregar o a recoger mercancía?', 0),
(@ID, 'esMX', '¡Habla! Dime... ¿vienes a entregar o a recoger mercancía?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Las piezas para Kravel... Me alegro de que hayas venido. Llevan días aquí y tenía miedo de que se oxidaran.', 0),
(@ID, 'esMX', 'Ah, sí. Las piezas para Kravel... Me alegro de que hayas venido. Llevan días aquí y tenía miedo de que se oxidaran.', 0);
-- 5762 Hemet Nesingwary Jr.
-- https://es.classic.wowhead.com/quest=5762
SET @ID := 5762;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo que tienes en el cuello es polvo del desierto...?$B$BMmm... si mi olfato no me engaña, no se trata de polvo... ¡sino de sal! Has estado en El Desierto de Sal, ¿no es así?', 0),
(@ID, 'esMX', '¿Lo que tienes en el cuello es polvo del desierto...?$B$BMmm... si mi olfato no me engaña, no se trata de polvo... ¡sino de sal! Has estado en El Desierto de Sal, ¿no es así?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo, Karbarbán me ha enviado mi paquete! Gracias, $n. Contiene munición de un calibre especial que nos vendrá de perlas en la jungla.$B$BAquí tienes tu recompensa y... dime, ¿qué es del viejo Kravel? Apuesto a que no anda metido en nada bueno...', 0),
(@ID, 'esMX', '¡Estupendo, Karbarbán me ha enviado mi paquete! Gracias, $n. Contiene munición de un calibre especial que nos vendrá de perlas en la jungla.$B$BAquí tienes tu recompensa y... dime, ¿qué es del viejo Kravel? Apuesto a que no anda metido en nada bueno...', 0);
-- 2770 Gahz'rilla
-- https://es.classic.wowhead.com/quest=2770
SET @ID := 2770;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la escama? ¡Estoy deseando averiguar cómo aprovechar su energía!', 0),
(@ID, 'esMX', '¿Tienes la escama? ¡Estoy deseando averiguar cómo aprovechar su energía!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, has conseguido la escama! Gracias, $n. ¡Estoy deseando ponerme manos a la obra con ella!$B$BAsí que has visto a Gahz\'rilla... ¿¿Es tan grande como dicen??', 0),
(@ID, 'esMX', '¡Vaya, has conseguido la escama! Gracias, $n. ¡Estoy deseando ponerme manos a la obra con ella!$B$BAsí que has visto a Gahz\'rilla... ¿¿Es tan grande como dicen??', 0);
-- 1107 Aletas dorsales taraceadas
-- https://es.classic.wowhead.com/quest=1107
SET @ID := 1107;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las aletas dorsales? Si no puedo proteger nuestro coche de la velocidad, no duraremos mucho en las carreras.', 0),
(@ID, 'esMX', '¿Tienes las aletas dorsales? Si no puedo proteger nuestro coche de la velocidad, no duraremos mucho en las carreras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias, $n! Cuando las haya molido y mezclado con una serie de ingredientes, el compuesto estará listo. Y cuando así sea, ¡el coche no sufrirá ningún daño vaya a la velocidad que vaya!$B$BEso sí, siempre que no choque con nada...', 0),
(@ID, 'esMX', '¡Gracias, $n! Cuando las haya molido y mezclado con una serie de ingredientes, el compuesto estará listo. Y cuando así sea, ¡el coche no sufrirá ningún daño vaya a la velocidad que vaya!$B$BEso sí, siempre que no choque con nada...', 0);
-- 865 Los cuernos de raptor
-- https://es.classic.wowhead.com/quest=865
SET @ID := 865;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los cuernos, $n? ¡Ganaré una fortuna con ellos!', 0),
(@ID, 'esMX', '¿Has conseguido los cuernos, $n? ¡Ganaré una fortuna con ellos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, los tienes! Ahora solo necesito molerlos, mezclarlos con algo de vino y...', 0),
(@ID, 'esMX', '¡Genial, los tienes! Ahora solo necesito molerlos, mezclarlos con algo de vino y...', 0);
