-- 1343 Montaraz Pico Tormenta
SET @ID := 1343;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Bueno, si se trata de $gun:una; joven y errante $c, ¡sin duda, $gatraido:atraida; por lo que se dice de mis hazañas en los campos de batalla!$B$B¡No hay tiempo para historias ahora, porque hay grandes e importantes acciones que deben hacerse! Si estás buscando gloria, entonces la suerte te brilla hoy...', 0),
(@ID, 0, 'esMX', 'Bueno, si se trata de $gun:una; joven y errante $c, ¡sin duda, $gatraido:atraida; por lo que se dice de mis hazañas en los campos de batalla!$B$B¡No hay tiempo para historias ahora, porque hay grandes e importantes acciones que deben hacerse! Si estás buscando gloria, entonces la suerte te brilla hoy...', 0);
-- 392 Capitán Grisillo
SET @ID := 392;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'No se alarme, $r. Hace mucho tiempo que dejé este mundo, pero no pretendo dañar a los tuyos. He sido testigo de demasiada muerte en mi tiempo. Mi único deseo ahora es por la paz. Quizás puedas ayudar a mi causa.', 0),
(@ID, 0, 'esMX', 'No se alarme, $r. Hace mucho tiempo que dejé este mundo, pero no pretendo dañar a los tuyos. He sido testigo de demasiada muerte en mi tiempo. Mi único deseo ahora es por la paz. Quizás puedas ayudar a mi causa.', 0);
-- 344 Magistrado Solomon
SET @ID := 344;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '¡Crestagrana está en caos por todas partes!', 0),
(@ID, 0, 'esMX', '¡Crestagrana está en caos por todas partes!', 0);
-- 342 Martie Jainrose
SET @ID := 342;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n. $gBienvenido:Bienvenida; a mi humilde jardín. El clima ha sido perfecto últimamente. Esperemos que se mantenga estable para una cosecha madura.', 0),
(@ID, 0, 'esMX', 'Saludos, $n. $gBienvenido:Bienvenida; a mi humilde jardín. El clima ha sido perfecto últimamente. Esperemos que se mantenga estable para una cosecha madura.', 0);
-- 381 Maestro de embarcadero Baren
SET @ID := 381;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Bien conocido, $c. Si estás aquí por negocios, consíguete una cerveza y tendremos una charla.', 0),
(@ID, 0, 'esMX', 'Bien conocido, $c. Si estás aquí por negocios, consíguete una cerveza y tendremos una charla.', 0);
-- 382 Alguacil Marris
SET @ID := 382;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'No tengo tiempo para charlar, ciudadano, pero si estás $gdispuesto:dispuesta; a echarnos una mano contra los orcos, entonces encontraré un uso para ti.', 0),
(@ID, 0, 'esMX', 'No tengo tiempo para charlar, ciudadano, pero si estás $gdispuesto:dispuesta; a echarnos una mano contra los orcos, entonces encontraré un uso para ti.', 0);
-- 415 Verner Osbien
SET @ID := 415;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Hola $gamigo:amiga;, ¿cree que podría echarme una mano con algo? Realmente estoy en una situación desesperada aquí...', 0),
(@ID, 0, 'esMX', 'Hola $gamigo:amiga;, ¿cree que podría echarme una mano con algo? Realmente estoy en una situación desesperada aquí...', 0);
-- 633 Elaine Carevin
SET @ID := 633;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Son tiempos oscuros, $c... Demasiado pronto lo perderemos todo... Cuando la Luz abandonará a todos menos a aquellos que realmente caminen bajo la Luz.', 0),
(@ID, 0, 'esMX', 'Son tiempos oscuros, $c... Demasiado pronto lo perderemos todo... Cuando la Luz abandonará a todos menos a aquellos que realmente caminen bajo la Luz.', 0);
-- 265 Lady Eva
SET @ID := 265;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'He presentido tu llegada desde hace bastante tiempo, $n. Está escrito en las estrellas.', 0),
(@ID, 0, 'esMX', 'He presentido tu llegada desde hace bastante tiempo, $n. Está escrito en las estrellas.', 0);
-- 1428 Rema Schneider
SET @ID := 1428;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n', 0),
(@ID, 0, 'esMX', 'Saludos, $n', 0);
-- 273 Tabernero Smitts
SET @ID := 273;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Deja la puerta cerrada, $c. Nunca se sabe cuándo volverán a pasar los Jinetes oscuros.', 0),
(@ID, 0, 'esMX', 'Deja la puerta cerrada, $c. Nunca se sabe cuándo volverán a pasar los Jinetes oscuros.', 0);
-- 267 Secretario Daltry
SET @ID := 267;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '$gBienvenido:Bienvenida; al pueblo de Villa Oscura. Secretario Daltry a su servicio. ¿Puedo ser de alguna ayuda?', 0),
(@ID, 0, 'esMX', '$gBienvenido:Bienvenida; al pueblo de Villa Oscura. Secretario Daltry a su servicio. ¿Puedo ser de alguna ayuda?', 0);
-- 6579 Shoni la Shilenshiosha
SET @ID := 6579;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '¡Por Gnomeregan!', 0),
(@ID, 0, 'esMX', '¡Por Gnomeregan!', 0);
-- 656 Wilder Cardortiga
SET @ID := 656;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '¡Había ladrones por todas partes!$B$BFue horrible. La cueva cayó sobre nosotros. Creo que la compañía minera está muerta, incluido mi hermano, el Capataz.', 0),
(@ID, 0, 'esMX', '¡Había ladrones por todas partes!$B$BFue horrible. La cueva cayó sobre nosotros. Creo que la compañía minera está muerta, incluido mi hermano, el Capataz.', 0);
-- 6031 Tormus Forjahonda
SET @ID := 6031;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Algunos no pueden soportar el calor de la Gran Fragua, pero creo que el calor es perfecto. Y es el mejor lugar para hacer un trabajo de herrería serio.', 0),
(@ID, 0, 'esMX', 'Algunos no pueden soportar el calor de la Gran Fragua, pero creo que el calor es perfecto. Y es el mejor lugar para hacer un trabajo de herrería serio.', 0);
-- 6569 Gnoarn
SET @ID := 6569;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Donde vagan los troggs y los gnomos leprosos, en nuestro hogar: Gnomeregan.$B$BNuestras familias perdidas, nuestros hogares desplazados. Dispersado.$B$BOh, cuánto anhelo los días de la vida despreocupada de Gnomeregan, pero esos días ya no existen. ¡Debemos defendernos! ¡Debemos salvar a Gnomeregan!', 0),
(@ID, 0, 'esMX', 'Donde vagan los troggs y los gnomos leprosos, en nuestro hogar: Gnomeregan.$B$BNuestras familias perdidas, nuestros hogares desplazados. Dispersado.$B$BOh, cuánto anhelo los días de la vida despreocupada de Gnomeregan, pero esos días ya no existen. ¡Debemos defendernos! ¡Debemos salvar a Gnomeregan!', 0);
-- 1377 Piloto Roscapiedra
SET @ID := 1377;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 1344 Prospector Vetaferro
SET @ID := 1344;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Aunque estamos atravesando un período lento en estas ruinas, estoy seguro de que no durará mucho. Pero mientras tanto, me vendría bien alguien como tú. ¿Te gustaría ayudar a la Liga de Expedicionarios?', 0),
(@ID, 0, 'esMX', 'Aunque estamos atravesando un período lento en estas ruinas, estoy seguro de que no durará mucho. Pero mientras tanto, me vendría bien alguien como tú. ¿Te gustaría ayudar a la Liga de Expedicionarios?', 0);
-- 1139 Magistrado Narizroma
SET @ID := 1139;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Bueno, hola, ciudadano. El nombre es Narizroma, Magistrado Narizroma para ser precisos. Estoy encargado de supervisar el bienestar de Thelsamar, y créeme, ¡siempre podríamos usar otro par de brazos fuertes por aquí!', 0),
(@ID, 0, 'esMX', 'Bueno, hola, ciudadano. El nombre es Narizroma, Magistrado Narizroma para ser precisos. Estoy encargado de supervisar el bienestar de Thelsamar, y créeme, ¡siempre podríamos usar otro par de brazos fuertes por aquí!', 0);
-- 1356 Prospector Pico Tormenta
SET @ID := 1356;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Estoy en medio de una tarea muy importante. Negocios de prospector. A menos que tengas algo igualmente importante que decir, lo cual dudo, tendrás que disculparme.', 0),
(@ID, 0, 'esMX', 'Estoy en medio de una tarea muy importante. Negocios de prospector. A menos que tengas algo igualmente importante que decir, lo cual dudo, tendrás que disculparme.', 0);
-- 1092 Capitán Rugelfuss
SET @ID := 1092;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 714 Talin Ojo Ávido
SET @ID := 714;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', '¡Saludos, $c! Buen día para cazar, ¿no crees? Yo también he tenido más que un poco de suerte con los jabalíes. ¿Quizás te gustaría un trago?', 0),
(@ID, 0, 'esMX', '¡Saludos, $c! Buen día para cazar, ¿no crees? Yo también he tenido más que un poco de suerte con los jabalíes. ¿Quizás te gustaría un trago?', 0);
-- 786 Grelin Barbablanca
SET @ID := 786;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $gmuchacho:muchacha;. Soy Grelin Whitebeard. Estoy aquí para examinar la amenaza que representa el creciente número de trolls en valle Crestanevada. ¿Qué he encontrado?... Es un poco preocupante...', 0),
(@ID, 0, 'esMX', 'Saludos, $gmuchacho:muchacha;. Soy Grelin Whitebeard. Estoy aquí para examinar la amenaza que representa el creciente número de trolls en valle Crestanevada. ¿Qué he encontrado?... Es un poco preocupante...', 0);
-- 2086 Valstag Quijahierro
SET @ID := 2086;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
-- 2094 James Halloran
SET @ID := 2094;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $c. Estoy en un pequeño aprieto en este momento, me estoy quedando sin pieles.', 0),
(@ID, 0, 'esMX', 'Saludos, $c. Estoy en un pequeño aprieto en este momento, me estoy quedando sin pieles.', 0);
-- 1239 Contramaestre Fistimos
SET @ID := 1239;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Si estás dispuesto a soportar cuentos que te hagan temblar las piernas y hagan que te empapes las botas, entonces tómate un trago y siéntate a descansar...', 0),
(@ID, 0, 'esMX', 'Si estás dispuesto a soportar cuentos que te hagan temblar las piernas y hagan que te empapes las botas, entonces tómate un trago y siéntate a descansar...', 0);
-- 1141 Angus Stern
SET @ID := 1141;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Si estás aquí por la comida, ¡$gbienvenido:bienvenida;! No encontrarás mejor restaurante en toda Ventormenta ... ¡o Azeroth!$B$BSi estás aquí por otros asuntos, se breve. Tengo una docena de platos en preparación y debo cuidar de cada uno.', 0),
(@ID, 0, 'esMX', 'Si estás aquí por la comida, ¡$gbienvenido:bienvenida;! No encontrarás mejor restaurante en toda Ventormenta ... ¡o Azeroth!$B$BSi estás aquí por otros asuntos, se breve. Tengo una docena de platos en preparación y debo cuidar de cada uno.', 0);
-- 2700 Capitana Nials
SET @ID := 2700;
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'En el Refugio de la Zaga tenemos uno de los pocos territorio de Stromgarde que quedan en las Tierras Altas de Arathi. Y estamos perdiendo terreno...$B$BSi tiene algo para mí, espero que sean buenas noticias.', 0),
(@ID, 0, 'esMX', 'En el Refugio de la Zaga tenemos uno de los pocos territorio de Stromgarde que quedan en las Tierras Altas de Arathi. Y estamos perdiendo terreno...$B$BSi tiene algo para mí, espero que sean buenas noticias.', 0);
-- 1284 Arzobispo Benedictus
SET @ID := 1284;
DELETE FROM `quest_greeting` WHERE `ID` = @ID AND `Type` = 0;
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES (@ID, 0, 0, 0, 'Greetings, $n.', 0);
DELETE FROM `quest_greeting_locale` WHERE `ID` = @ID AND `Type` = 0 AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(@ID, 0, 'esES', 'Saludos, $n.', 0),
(@ID, 0, 'esMX', 'Saludos, $n.', 0);
