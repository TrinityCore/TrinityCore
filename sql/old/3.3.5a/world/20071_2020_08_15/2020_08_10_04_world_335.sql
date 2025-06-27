-- 2927 Al día siguiente
-- https://es.classic.wowhead.com/quest=2927
SET @ID := 2927;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Creí que no soportaría la pérdida del pelo, pero ya ves.$B$BEstábamos juntos cuando le cayó la nube radiactiva y se le empezó a caer el pelo a puñados. Fue horroroso. ¡Empezó a tocarse la cabeza, se le pusieron los ojos rojos y juró venganza! Desde entonces la tomó con los troggs.$B$B<Ozzie se estremece.>', 0),
(@ID, 'esMX', 'Creí que no soportaría la pérdida del pelo, pero ya ves.$B$BEstábamos juntos cuando le cayó la nube radiactiva y se le empezó a caer el pelo a puñados. Fue horroroso. ¡Empezó a tocarse la cabeza, se le pusieron los ojos rojos y juró venganza! Desde entonces la tomó con los troggs.$B$B<Ozzie se estremece.>', 0);
-- 2930 Rescatar los datos
-- https://es.classic.wowhead.com/quest=2930
SET @ID := 2930;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la tarjeta perforada prismática?', 0),
(@ID, 'esMX', '¿Tienes la tarjeta perforada prismática?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has conseguido recuperar los datos! Son importatísimos, vitales.$B$BEste servicio que nos has prestado será recordado mucho tiempo, $n.', 0),
(@ID, 'esMX', '¡Has conseguido recuperar los datos! Son importatísimos, vitales.$B$BEste servicio que nos has prestado será recordado mucho tiempo, $n.', 0);
-- 2929 La gran traición
-- https://es.classic.wowhead.com/quest=2929
SET @ID := 2929;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿La tarea está completa? ¿Pidió indulgencia?, ¿Piedad?', 0),
(@ID, 'esMX', '¿La tarea está completa? ¿Pidió indulgencia?, ¿Piedad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuéntame otra vez cómo le aplastaste el cráneo con la bota, $r. Ahora que ha muerto, estamos más cerca de recuperar Gnomeregan.', 0),
(@ID, 'esMX', 'Cuéntame otra vez cómo le aplastaste el cráneo con la bota, $r. Ahora que ha muerto, estamos más cerca de recuperar Gnomeregan.', 0);
-- 2924 Esencias artificiales
-- https://es.classic.wowhead.com/quest=2924
SET @ID := 2924;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las esencias artificiales?', 0),
(@ID, 'esMX', '¿Tienes las esencias artificiales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ahora que tengo las esencias, puedo empezar mi nuevo experimento!$B$B¡No puedo agradecerte lo suficiente, $N! ¡Gracias a tu valentía, la investigación gnómica va a dar un salto cuántico!', 0),
(@ID, 'esMX', '¡Ahora que tengo las esencias, puedo empezar mi nuevo experimento!$B$B¡No puedo agradecerte lo suficiente, $N! ¡Gracias a tu valentía, la investigación gnómica va a dar un salto cuántico!', 0);
-- 1653 La prueba de rectitud
-- https://es.classic.wowhead.com/quest=1653
SET @ID := 1653;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres $gel:la; que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0),
(@ID, 'esMX', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres $gel:la; que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0);
-- 1654 La prueba de rectitud
SET @ID := 1654;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los objetos que estás buscando serán difíciles de conseguir, pero puedo asegurarte que el arma que fabricaré para ti valdrá la pena.$B$BSerá mi mejor trabajo hasta la fecha, y solo un pequeño pago por el servicio que me ha prestado.', 0),
(@ID, 'esMX', 'Los objetos que estás buscando serán difíciles de conseguir, pero puedo asegurarte que el arma que fabricaré para ti valdrá la pena.$B$BSerá mi mejor trabajo hasta la fecha, y solo un pequeño pago por el servicio que me ha prestado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es maravilloso! Tienes todos los artículos.$B$BNo debería tener ningún problema en forjarte un gran arma con estos. De hecho, tenía planes para hacer esto desde hace algún tiempo. Simplemente nunca tuve la oportunidad de recolectar los productos. Gracias, $n.$B$BSe siente bien volver a tener el martillo de mi padre... y una gema Kor. Nunca pensé que vería una de estas yo mismo.', 0),
(@ID, 'esMX', '¡Esto es maravilloso! Tienes todos los artículos.$B$BNo debería tener ningún problema en forjarte un gran arma con estos. De hecho, tenía planes para hacer esto desde hace algún tiempo. Simplemente nunca tuve la oportunidad de recolectar los productos. Gracias, $n.$B$BSe siente bien volver a tener el martillo de mi padre... y una gema Kor. Nunca pensé que vería una de estas yo mismo.', 0);
-- 2926 Gnogaine
-- https://es.classic.wowhead.com/quest=2926
SET @ID := 2926;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿No ves que tenemos muchos gnomos que curar?! ¡Necesitamos más restos radiactivos!', 0),
(@ID, 'esMX', '¡¿No ves que tenemos muchos gnomos que curar?! ¡Necesitamos más restos radiactivos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! Vamos a probar la nueva fórmula. ¡Si funciona, no solo curaremos a los gnomos leprosos, sino que me volverá a crecer el pelo! ¡Aparta!', 0),
(@ID, 'esMX', '¡Excelente! Vamos a probar la nueva fórmula. ¡Si funciona, no solo curaremos a los gnomos leprosos, sino que me volverá a crecer el pelo! ¡Aparta!', 0);
-- 412 Operación Recombobulación
SET @ID := 412;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El recombobulador estará listo en cuanto tengamos suficientes levas estabilizadoras y engranajes giromecánicos.', 0),
(@ID, 'esMX', 'El recombobulador estará listo en cuanto tengamos suficientes levas estabilizadoras y engranajes giromecánicos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos engranajes giromecánicos y estas levas estabilizadoras cumplen todos los requisitos del esquema de Ozzie para el dispositivo de recombobulación. Cuando añada algo de hidrolubricante a los pistones de combustión, ajuste la manivela y aumente la viscosidad del gel electrogómico, la raza gnoma volverá a ser lo que era.', 0),
(@ID, 'esMX', 'Estos engranajes giromecánicos y estas levas estabilizadoras cumplen todos los requisitos del esquema de Ozzie para el dispositivo de recombobulación. Cuando añada algo de hidrolubricante a los pistones de combustión, ajuste la manivela y aumente la viscosidad del gel electrogómico, la raza gnoma volverá a ser lo que era.', 0);
-- 1806 La prueba de rectitud
-- https://es.classic.wowhead.com/quest=1806
SET @ID := 1806;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está, $n. Un arma digna de $gun campeón:una campeona; de la Luz como tú. Le he puesto el nombre de un gran paladín enano que era amigo mío. Su nombre era Verigan ... Bosch Verigan.$B$BPor favor, acéptalo en mi nombre y en el de mi esposa. Te debemos una gran deuda, y el mundo será un lugar más seguro con alguien de tu habilidad viajando por la tierra.', 0),
(@ID, 'esMX', 'Aquí está, $n. Un arma digna de $gun campeón:una campeona; de la Luz como tú. Le he puesto el nombre de un gran paladín enano que era amigo mío. Su nombre era Verigan ... Bosch Verigan.$B$BPor favor, acéptalo en mi nombre y en el de mi esposa. Te debemos una gran deuda, y el mundo será un lugar más seguro con alguien de tu habilidad viajando por la tierra.', 0);
-- 315 La cerveza perfecta
-- https://es.wowhead.com/quest=315
SET @ID := 315;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la cardaluz ya? Ya casi tengo todo listo para la próxima cerveza y quisiera probar esa plantita en la mezcla.', 0),
(@ID, 'esMX', '¿Tienes la cardaluz ya? Ya casi tengo todo listo para la próxima cerveza y quisiera probar esa plantita en la mezcla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! Estoy deseando utilizarla en mis recetas. Estoy pensando en una en concreto a la que le irá de maravilla.', 0),
(@ID, 'esMX', '¡Genial! Estoy deseando utilizarla en mis recetas. Estoy pensando en una en concreto a la que le irá de maravilla.', 0);
-- 310 Rivales acérrimos
-- https://es.classic.wowhead.com/quest=310
SET @ID := 310;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La fecha del barril te indica que no tardará en ser abierto.', 0),
(@ID, 'esMX', 'La fecha del barril te indica que no tardará en ser abierto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas rápidamente el barril de Marleth de brebaje de Cebadiz entre los barriles de Cebatruenos.', 0),
(@ID, 'esMX', 'Colocas rápidamente el barril de Marleth de brebaje de Cebadiz entre los barriles de Cebatruenos.', 0);
-- 413 Cerveza negra Brillante
-- https://es.classic.wowhead.com/quest=413
SET @ID := 413;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, $c! ¿Qué te trae hasta aquí?$B$BAlgo emocionante, espero. Hace días que no consigo participar en una buena batalla y se me está acabando este barril de cerveza...', 0),
(@ID, 'esMX', '¡Hola, $c! ¿Qué te trae hasta aquí?$B$BAlgo emocionante, espero. Hace días que no consigo participar en una buena batalla y se me está acabando este barril de cerveza...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El montaraz Cebadiz prueba la cerveza negra Brillante...>$B$BOh. ¡VAYA! Esta cosa le da como un brillo nuevo a la vista. ¡Creo que puedo ver en la oscuridad!', 0),
(@ID, 'esMX', '<El montaraz Cebadiz prueba la cerveza negra Brillante...>$B$BOh. ¡VAYA! Esta cosa le da como un brillo nuevo a la vista. ¡Creo que puedo ver en la oscuridad!', 0);
-- 2962 Necesitamos más material verdoso
-- https://es.classic.wowhead.com/quest=2962
SET @ID := 2962;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm, no brillas. Es una buena señal.', 0),
(@ID, 'esMX', 'Mmm, no brillas. Es una buena señal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ozzie te examina.> ¡Impresionante! ¡Todavía tienes todos los dedos! Venga, vamos a ver qué puede hacer esta cosa.', 0),
(@ID, 'esMX', '<Ozzie te examina.> ¡Impresionante! ¡Todavía tienes todos los dedos! Venga, vamos a ver qué puede hacer esta cosa.', 0);
-- 400 Herramientas para Brasacerada
-- https://es.classic.wowhead.com/quest=400
SET @ID := 400;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mm? ¿No eres un poco joven para ser piloto de máquinas de asedio? Bueno, no importa. ¿Necesitas reparar algo?$B$BSi es así, coge número y ponte cómodo. Ahora mismo estoy con un par de motores y no tendré tiempo para nada más hasta dentro de unos días.$B$B¿O venías por otro motivo?', 0),
(@ID, 'esMX', '¿Mm? ¿No eres un poco joven para ser piloto de máquinas de asedio? Bueno, no importa. ¿Necesitas reparar algo?$B$BSi es así, coge número y ponte cómodo. Ahora mismo estoy con un par de motores y no tendré tiempo para nada más hasta dentro de unos días.$B$B¿O venías por otro motivo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mis herramientas? ¡Bien hecho, $gmuchacho:muchacha;! Acabo de romper mi último destornillador hace una hora y necesitaba otro para acabar de reparar la máquina de asedio del piloto Roscapiedra. Desde luego, me has hecho un favor enorme trayendo estas herramientas hasta aquí, $n.', 0),
(@ID, 'esMX', '¿Tienes mis herramientas? ¡Bien hecho, $gmuchacho:muchacha;! Acabo de romper mi último destornillador hace una hora y necesitaba otro para acabar de reparar la máquina de asedio del piloto Roscapiedra. Desde luego, me has hecho un favor enorme trayendo estas herramientas hasta aquí, $n.', 0);
-- 384 Costillas de jabalí a la cerveza
-- https://es.wowhead.com/quest=384
SET @ID := 384;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Voy a necesitar esas costillas de jabalíes del risco y una jarra de malta rapsódica, $n.', 0),
(@ID, 'esMX', 'Voy a necesitar esas costillas de jabalíes del risco y una jarra de malta rapsódica, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La malta está lista y los jabalíes muertos$BY antes de acabar y de ponernos a hablar$BTendremos que luchar por ver quién empieza$B¡estas sabrosas costillas de jabalí a la cerveza!', 0),
(@ID, 'esMX', 'La malta está lista y los jabalíes muertos$BY antes de acabar y de ponernos a hablar$BTendremos que luchar por ver quién empieza$B¡estas sabrosas costillas de jabalí a la cerveza!', 0);
-- 403 El barril de Cebatruenos custodiado
-- https://es.classic.wowhead.com/quest=403
SET @ID := 403;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este barril está custodiado por Jarven Cebatruenos. Mientras esté en el sótano, nadie tocará los barriles.', 0),
(@ID, 'esMX', 'Este barril está custodiado por Jarven Cebatruenos. Mientras esté en el sótano, nadie tocará los barriles.', 0);
-- 308 Distraer a Jarven
-- https://es.classic.wowhead.com/quest=308
SET @ID := 308;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya! Con toda la bebida que hay aquí abajo... ¡Y tengo órdenes estrictas de no tocarla! Si tan solo pudiera probar un poco de nuestra Cerveza del Trueno... ¡agudiza el ingenio, y no es broma!', 0),
(@ID, 'esMX', '¡Vaya! Con toda la bebida que hay aquí abajo... ¡Y tengo órdenes estrictas de no tocarla! Si tan solo pudiera probar un poco de nuestra Cerveza del Trueno... ¡agudiza el ingenio, y no es broma!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Es para mí? ¡Eres $gun héroe:una heroína;, $n!', 0),
(@ID, 'esMX', '¿Es para mí? ¡Eres $gun héroe:una heroína;, $n!', 0);
-- 311 Regresa junto a Marleth
-- https://es.classic.wowhead.com/quest=311
SET @ID := 311;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Diste el cambiazo?', 0),
(@ID, 'esMX', '¿Diste el cambiazo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No está mal, $n! ¿Te costó mucho superar a su guardia?$B$BNo importa. Muchas gracias. Y oye, si alguna vez necesitas una buena cervezota, ¡no te olvides de los brebajes de Cebadiz!', 0),
(@ID, 'esMX', '¡No está mal, $n! ¿Te costó mucho superar a su guardia?$B$BNo importa. Muchas gracias. Y oye, si alguna vez necesitas una buena cervezota, ¡no te olvides de los brebajes de Cebadiz!', 0);
-- 5541 Municiones para Estruendo
-- https://es.classic.wowhead.com/quest=5541
SET @ID := 5541;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no hayas venido a por munición, ¡porque casi se me ha agotado!', 0),
(@ID, 'esMX', 'Espero que no hayas venido a por munición, ¡porque casi se me ha agotado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, más munición! ¡Por fin ha llegado el cargamento del viejo Loslor! La munición llega con algo de retraso, pero como decía mi abuelo: ¡más vale tarde que nunca!$B$BMuchas gracias, $n. ¡Voy a atender a mis ansiosos compradores!', 0),
(@ID, 'esMX', '¡Genial, más munición! ¡Por fin ha llegado el cargamento del viejo Loslor! La munición llega con algo de retraso, pero como decía mi abuelo: ¡más vale tarde que nunca!$B$BMuchas gracias, $n. ¡Voy a atender a mis ansiosos compradores!', 0);
-- 313 El Cubil Pardo
-- https://es.classic.wowhead.com/quest=313
SET @ID := 313;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eh, $n, ¿ya has estado en El Cubil Pardo? Esos wendigos pueden llegar a ser muy feroces.', 0),
(@ID, 'esMX', 'Eh, $n, ¿ya has estado en El Cubil Pardo? Esos wendigos pueden llegar a ser muy feroces.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, sí, estas crines me vendrán estupendamente! Tienes agallas, $c. Apuesto a que te veremos protagonizar numerosas hazañas.', 0),
(@ID, 'esMX', '¡Ah, sí, estas crines me vendrán estupendamente! Tienes agallas, $c. Apuesto a que te veremos protagonizar numerosas hazañas.', 0);
