-- 5393 Intendente Lungertz
SET @ID := 5393;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 237 Granjero Cejade
SET @ID := 237;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'No hay nada más que problemas por aquí. Traté de decirle a ese tonto de Saldean que salga mientras aún puede, pero no se entera. Pero yo no soy ningún tonto. Verna y yo saldremos tan pronto como arreglemos este vagón.', 0),
(@ID, 0, 'esMX', 'No hay nada más que problemas por aquí. Traté de decirle a ese tonto de Saldean que salga mientras aún puede, pero no se entera. Pero yo no soy ningún tonto. Verna y yo saldremos tan pronto como arreglemos este vagón.', 0);
-- 239 Tragoamargo Cebatruenos
SET @ID := 239;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Aventura desde tierras cercanas y lejanas$BReunirse con personas extrañas y cercanas$BPero si a mi me planteas una questión$B¡Primero debes completar una simple misión!', 0),
(@ID, 0, 'esMX', 'Aventura desde tierras cercanas y lejanas$BReunirse con personas extrañas y cercanas$BPero si a mi me planteas una questión$B¡Primero debes completar una simple misión!', 0);
-- 241 Remy "Dos Veces"
SET @ID := 241;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Hola, amigo. Mi nombre es Remy.$BSoy de Crestagrana, al este, y vine aquí buscando negocios, buscando negocios. ¿Tienes alguno... tienes alguno?', 0),
(@ID, 0, 'esMX', 'Hola, amigo. Mi nombre es Remy.$BSoy de Crestagrana, al este, y vine aquí buscando negocios, buscando negocios. ¿Tienes alguno... tienes alguno?', 0);
-- 264 Comandante Althea Cerranegro
SET @ID := 264;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Tranquilo, $c. Si solo está de paso, le sugiero que siga las carreteras y viaje solo de día. Si su negocio está aquí en Villa Oscura, considere prestar sus habilidades a la Guardia Nocturna. Nuestra habilidad es incuestionable pero nuestro número es pequeño.', 0),
(@ID, 0, 'esMX', 'Tranquilo, $c. Si solo está de paso, le sugiero que siga las carreteras y viaje solo de día. Si su negocio está aquí en Villa Oscura, considere prestar sus habilidades a la Guardia Nocturna. Nuestra habilidad es incuestionable pero nuestro número es pequeño.', 0);
-- 4077 Gaxim Silvóxido
SET @ID := 4077;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Si puedo conseguir los ingredientes adecuados, podemos crear algunos explosivos que no solo me permitirán dañar las operaciones de Ventura y Cía., sino que también causarán una distracción.$B$BSé que estás impresionado, pero se pone mejor ... Te contaré más pronto.', 0),
(@ID, 0, 'esMX', 'Si puedo conseguir los ingredientes adecuados, podemos crear algunos explosivos que no solo me permitirán dañar las operaciones de Ventura y Cía., sino que también causarán una distracción.$B$BSé que estás impresionado, pero se pone mejor ... Te contaré más pronto.', 0);
-- 4078 Collin Mauren
SET @ID := 4078;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Hola amigo. ¿Qué puedo hacer por ti?', 0),
(@ID, 0, 'esMX', 'Hola amigo. ¿Qué puedo hacer por ti?', 0);
-- 4452 Kravel Karbarbán
SET @ID := 4452;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Acercate un poco mas. Tenemos asuntos importantes que discutir tú y yo.$B$BY algunos de ellos no queremos que todos lo escuchen...', 0),
(@ID, 0, 'esMX', 'Acercate un poco mas. Tenemos asuntos importantes que discutir tú y yo.$B$BY algunos de ellos no queremos que todos lo escuchen...', 0);
-- 4453 Wizzle Pernolatón
SET @ID := 4453;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Tenga cuidado donde pone ese pie suyo, $gseñor:señora;. No todos estamos bendecidos con la elevada altura de un gnomo.', 0),
(@ID, 0, 'esMX', 'Tenga cuidado donde pone ese pie suyo, $gseñor:señora;. No todos estamos bendecidos con la elevada altura de un gnomo.', 0);
-- 4456 Fiora Orejona
SET @ID := 4456;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'No, Orejona no es mi nombre real. Y no te voy a decir cual es, así que no preguntes.', 0),
(@ID, 0, 'esMX', 'No, Orejona no es mi nombre real. Y no te voy a decir cual es, así que no preguntes.', 0);
-- 4485 Belgrom Destrozarroca
SET @ID := 4485;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Los días se alargan y aún no se vislumbra el final de los conflictos de estas tierras. No hace falta ningún lanzador de hechizos para saber tanto. Toma una espada mientras puedas, $c. La guerra puede llegar a nuestras puertas en cualquier momento, y si no me equivoco, pareces ser alguien que se deleita con ella.', 0),
(@ID, 0, 'esMX', 'Los días se alargan y aún no se vislumbra el final de los conflictos de estas tierras. No hace falta ningún lanzador de hechizos para saber tanto. Toma una espada mientras puedas, $c. La guerra puede llegar a nuestras puertas en cualquier momento, y si no me equivoco, pareces ser alguien que se deleita con ella.', 0);
-- 5396 Capitán Pentigast
SET @ID := 5396;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'La Alianza tiene mucho interés en Desolace, y nuestro dominio aquí es inestable.$B$B¿Nos ayudarias?', 0),
(@ID, 0, 'esMX', 'La Alianza tiene mucho interés en Desolace, y nuestro dominio aquí es inestable.$B$B¿Nos ayudarias?', 0);
-- 5638 Kreldig Ungor
SET @ID := 5638;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Tengo muchas cosas que hacer aquí en Desolace, $n. Roetten quiere que recojamos algunos componentes para uno de nuestros clientes y que busquemos algunos de estos artículos perdidos.$B$BYa que estás aquí para ayudar, ¿por qué no empezamos?', 0),
(@ID, 0, 'esMX', 'Tengo muchas cosas que hacer aquí en Desolace, $n. Roetten quiere que recojamos algunos componentes para uno de nuestros clientes y que busquemos algunos de estos artículos perdidos.$B$BYa que estás aquí para ayudar, ¿por qué no empezamos?', 0);
-- 5637 Roetten Rocamartillo
SET @ID := 5637;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 2263 Alguacil Rutagrana
SET @ID := 2263;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Espero que estés aquí para trabajar, $c. Tenemos mucho que hacer y la Horda, la Hermandad y los Ogros no van a ayudarnos.', 0),
(@ID, 0, 'esMX', 'Espero que estés aquí para trabajar, $c. Tenemos mucho que hacer y la Horda, la Hermandad y los Ogros no van a ayudarnos.', 0);
-- 2276 Magistrado Henry Maleb
SET @ID := 2276;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Cuando me ofrecieron por primera vez el título de Magistrado de Costasur, me sentí exaltado por haber ganado tal comisión tan temprano en mi carrera.$B$BPero ahora que estoy aquí, me pregunto si hubiera estado mejor barajando papeles en Ventormenta.', 0),
(@ID, 0, 'esMX', 'Cuando me ofrecieron por primera vez el título de Magistrado de Costasur, me sentí exaltado por haber ganado tal comisión tan temprano en mi carrera.$B$BPero ahora que estoy aquí, me pregunto si hubiera estado mejor barajando papeles en Ventormenta.', 0);
-- 186420
SET @ID := 186420;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 1 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 1, 'esES', 'Esta colección de pergaminos contiene diversa información logística y estratégica, así como correspondencias codificadas.', 0),
(@ID, 1, 'esMX', 'Esta colección de pergaminos contiene diversa información logística y estratégica, así como correspondencias codificadas.', 0);
-- 3446 Mebok Mizzyrix
SET @ID := 3446;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '¡Si si si! ¡Eres $gel:la; $r que estoy buscando!$B$B¡Siéntate! ¡¡Tenemos mucho que discutir!!', 0),
(@ID, 0, 'esMX', '¡Si si si! ¡Eres $gel:la; $r que estoy buscando!$B$B¡Siéntate! ¡¡Tenemos mucho que discutir!!', 0);
-- 3453 Maestro de muelles Vertipeluca
SET @ID := 3453;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '¿Algo en lo que pueda ayudarte, $n? De lo contrario, tengo que ocuparme de un envío.', 0),
(@ID, 0, 'esMX', '¿Algo en lo que pueda ayudarte, $n? De lo contrario, tengo que ocuparme de un envío.', 0);
-- 3519 Centinela Arynia Quiebranubes
SET @ID := 3519;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Yo, Arynia Quiebranubes, tengo la tarea de proteger la santidad de Oráculo de la arboleda.', 0),
(@ID, 0, 'esMX', 'Yo, Arynia Quiebranubes, tengo la tarea de proteger la santidad de Oráculo de la arboleda.', 0);
-- 2817 Aparejez
SET @ID := 2817;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Debes estar muy $gpreparado:preparada; para vagar por estas Tierras Inhóspitas, $c. $gUn tipo duro:Una tipa dura;... como yo.$B$BO tal vez estás aquí porque estás $gloco:loca;... como yo.', 0),
(@ID, 0, 'esMX', 'Debes estar muy $gpreparado:preparada; para vagar por estas Tierras Inhóspitas, $c. $gUn tipo duro:Una tipa dura;... como yo.$B$BO tal vez estás aquí porque estás $gloco:loca;... como yo.', 0);
-- 2910 Prospector Ryedol
SET @ID := 2910;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Los bastardos vinieron directamente a por nosotros por la noche, después de que nos hubiéramos tomado unas copas. De lo contrario, podríamos haberlos machacado, cuenta con ello.$B$BAhora han muertos todos... excepto algunos de nosotros.', 0),
(@ID, 0, 'esMX', 'Los bastardos vinieron directamente a por nosotros por la noche, después de que nos hubiéramos tomado unas copas. De lo contrario, podríamos haberlos machacado, cuenta con ello.$B$BAhora han muertos todos... excepto algunos de nosotros.', 0);
-- 2860 Sigrun Extracero
SET @ID := 2860;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Te diré que ha sido toda una escapada, $c. Estábamos agarrando todo lo que no estaba clavado o podía quitarse rápidamente. Por eso andamos cortos de suministros.', 0),
(@ID, 0, 'esMX', 'Te diré que ha sido toda una escapada, $c. Estábamos agarrando todo lo que no estaba clavado o podía quitarse rápidamente. Por eso andamos cortos de suministros.', 0);
-- 2786 Gerrig Agarrahueso
SET @ID := 2786;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Bienvenido a la tienda de Agarrahueso, $c. Puedes mirar, pero no tocar.$B$BParte del conocimiento de aquí no está destinado a los... no iniciados.', 0),
(@ID, 0, 'esMX', 'Bienvenido a la tienda de Agarrahueso, $c. Puedes mirar, pero no tocar.$B$BParte del conocimiento de aquí no está destinado a los... no iniciados.', 0);
-- 5636 Maestro de grifos Garracha
SET @ID := 5636;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 4080 Kaela Lanzasombra
SET @ID := 4080;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 4201 Ziz Fizziks
SET @ID := 4201;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 4454 Fizzle Pernolatón
SET @ID := 4454;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 4630 Pozzik
SET @ID := 4630;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 7876 Tran'rek
SET @ID := 7876;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Algunas personas se preguntan qué estamos haciendo aquí en el desierto. Bueno... ¡Si te lo dijera, entonces te quedarías y tratarías de obtener nuestras ganancias!', 0),
(@ID, 0, 'esMX', 'Algunas personas se preguntan qué estamos haciendo aquí en el desierto. Bueno... ¡Si te lo dijera, entonces te quedarías y tratarías de obtener nuestras ganancias!', 0);
-- 7407 Ingeniero jefe Pasaquillas
SET @ID := 7407;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Mi nombre es Pasaquillas y soy el ingeniero jefe de la Compañía de Agua de Gadgetzan. ¿En qué te puedo ayudar?', 0),
(@ID, 0, 'esMX', 'Mi nombre es Pasaquillas y soy el ingeniero jefe de la Compañía de Agua de Gadgetzan. ¿En qué te puedo ayudar?', 0);
-- 2501 MacKinley "Lobo de Mar"
SET @ID := 2501;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '¡Oy! ¿Estás aquí por un juego de puñetazos?', 0),
(@ID, 0, 'esMX', '¡Oy! ¿Estás aquí por un juego de puñetazos?', 0);
