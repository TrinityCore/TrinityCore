-- 455 El asedio de Algaz
-- https://es.classic.wowhead.com/quest=455
SET @ID := 455;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes de Loch Modan? ¿Cómo es la situación con los orcos en la Puerta de Algaz?', 0),
(@ID, 'esMX', '¿Vienes de Loch Modan? ¿Cómo es la situación con los orcos en la Puerta de Algaz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tu informe está lleno de malas noticias!$B$BVeo que los Faucedraco están avanzando con fuerza en Algaz. Normalmente los Faucedraco se quedan escondidos en las colinas. Es un misterio qué les hizo avanzar hacia Algaz...$B$BGracias, $n. Seguramente necesitaremos tu ayuda para combatir a esos orcos.', 0),
(@ID, 'esMX', '¡Tu informe está lleno de malas noticias!$B$BVeo que los Faucedraco están avanzando con fuerza en Algaz. Normalmente los Faucedraco se quedan escondidos en las colinas. Es un misterio qué les hizo avanzar hacia Algaz...$B$BGracias, $n. Seguramente necesitaremos tu ayuda para combatir a esos orcos.', 0);
-- 419 El piloto perdido
-- https://es.classic.wowhead.com/quest=419
SET @ID := 419;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encuentras el cadáver de un enano. Masacrado, congelado y saqueado por los carroñeros de la montaña. Aprieta con la mano un libro que contiene anotaciones garabateadas por Mori Hildelve. El cuerpo está envuelto en un jubón de brigadier que aún está en perfectas condiciones.$B$BEste escenario truculento es seguramente aquel en el que el piloto de máquina de asedio perdió la vida.', 0),
(@ID, 'esMX', 'Encuentras el cadáver de un enano. Masacrado, congelado y saqueado por los carroñeros de la montaña. Aprieta con la mano un libro que contiene anotaciones garabateadas por Mori Hildelve. El cuerpo está envuelto en un jubón de brigadier que aún está en perfectas condiciones.$B$BEste escenario truculento es seguramente aquel en el que el piloto de máquina de asedio perdió la vida.', 0);
-- 417 Vengar al piloto
-- https://es.classic.wowhead.com/quest=417
SET @ID := 417;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Tienes noticias de mi amigo Hildelve?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Tienes noticias de mi amigo Hildelve?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas son malas noticias: Hildelve era un buen amigo. Me habría gustado estar allí cuando encontraste a la bestia: ¡Sarnagarra!$B$BGracias, $n. Los pilotos de la Brigada de asedio de Forjaz recordarán tu hazaña.', 0),
(@ID, 'esMX', 'Estas son malas noticias: Hildelve era un buen amigo. Me habría gustado estar allí cuando encontraste a la bestia: ¡Sarnagarra!$B$BGracias, $n. Los pilotos de la Brigada de asedio de Forjaz recordarán tu hazaña.', 0);
-- 414 Cerveza negra para Kadrell
-- https://es.classic.wowhead.com/quest=414
SET @ID := 414;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¡Bienvenido a Thelsamar!', 0),
(@ID, 'esMX', 'Saludos, $c. ¡Bienvenido a Thelsamar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A ver, deja que pruebe...$B$B¡Por la barba de Magni! ¡Esta cosa te hace girar la cabeza! Y oye, te hace sentir como más ligero...$B$B¡Seguro que puedo volar!', 0),
(@ID, 'esMX', 'A ver, deja que pruebe...$B$B¡Por la barba de Magni! ¡Esta cosa te hace girar la cabeza! Y oye, te hace sentir como más ligero...$B$B¡Seguro que puedo volar!', 0);
-- 302 Pólvora para Vetaferro
-- https://es.classic.wowhead.com/quest=302
SET @ID := 302;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que Pico Tormenta quiere que te encargues tú del envío a Vetaferro?$B$BPor mí bien, pero hace apenas un rato que se lo llevó Huldar con los porteadores, Miran y Saean.', 0),
(@ID, 'esMX', '¿Que Pico Tormenta quiere que te encargues tú del envío a Vetaferro?$B$BPor mí bien, pero hace apenas un rato que se lo llevó Huldar con los porteadores, Miran y Saean.', 0);
-- 2398 Los enanos desaparecidos
-- https://es.classic.wowhead.com/quest=2398
SET @ID := 2398;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que aparecieras. ¡Temía perder la apuesta que hice con Olaf!$B$BÉl apostó que su barba le crecería hasta las rodillas antes de que alguien viniera a buscarnos. Aquí estás y, como puedes observar, ¡a la barba de Olaf aún le queda un buen trecho para llegar hasta sus rodillas!$B$BGracias, $n. Repartiré las ganancias contigo.', 0),
(@ID, 'esMX', 'Ya era hora de que aparecieras. ¡Temía perder la apuesta que hice con Olaf!$B$BÉl apostó que su barba le crecería hasta las rodillas antes de que alguien viniera a buscarnos. Aquí estás y, como puedes observar, ¡a la barba de Olaf aún le queda un buen trecho para llegar hasta sus rodillas!$B$BGracias, $n. Repartiré las ganancias contigo.', 0);
-- 1360 Los tesoros reclamados
-- https://es.classic.wowhead.com/quest=1360
SET @ID := 1360;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿conseguiste recuperar mi posesión de mi cofre?', 0),
(@ID, 'esMX', 'Bueno, ¿conseguiste recuperar mi posesión de mi cofre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! Te lo agradezco mucho.$B$BAlgunos enanos aman el brillo del metal, otros el resplandor de las gemas... ¡Pero un Brazorrecio tiene sus reliquias personales!', 0),
(@ID, 'esMX', '¡Por fin! Te lo agradezco mucho.$B$BAlgunos enanos aman el brillo del metal, otros el resplandor de las gemas... ¡Pero un Brazorrecio tiene sus reliquias personales!', 0);
-- 2500 Componentes de Tierras Inhóspitas
-- https://es.classic.wowhead.com/quest=2500
SET @ID := 2500;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes lo que te pedí? No te pagaré hasta que me des los ingredientes.', 0),
(@ID, 'esMX', '¿Me traes lo que te pedí? No te pagaré hasta que me des los ingredientes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n; con esto ya tengo para una temporada. Ten, tu recompensa.$B$BY tengo otro trabajo para ti, si te interesa. Lo que busco está en la excavación de Uldaman y no es fácil de conseguir, pero te recompensaré bien.$B$BY con algo más tentador que las monedas, ¿qué me dices?', 0),
(@ID, 'esMX', 'Buen trabajo, $n; con esto ya tengo para una temporada. Ten, tu recompensa.$B$BY tengo otro trabajo para ti, si te interesa. Lo que busco está en la excavación de Uldaman y no es fácil de conseguir, pero te recompensaré bien.$B$BY con algo más tentador que las monedas, ¿qué me dices?', 0);
-- 273 Aprovisionar la excavación
-- https://es.classic.wowhead.com/quest=273
SET @ID := 273;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Malditos Hierro Negro...!$B$BY que Saean esté conchabado con ellos... Mira que hemos trabajado juntos un año y no me había percatado de nada.$B$BBah, qué más da.', 0),
(@ID, 'esMX', '¡Malditos Hierro Negro...!$B$BY que Saean esté conchabado con ellos... Mira que hemos trabajado juntos un año y no me había percatado de nada.$B$BBah, qué más da.', 0);
-- 454 Tras la emboscada
-- https://es.classic.wowhead.com/quest=454
SET @ID := 454;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c.$B$B¿Tú vas a ser mi escolta? Me alegro, todo este asunto de los Hierro Negro me tiene un poco nervioso.$B$BBueno, voy a acabar de prepararme; ven a hablar conmigo cuando quieras que salgamos.', 0),
(@ID, 'esMX', 'Hola, $c.$B$B¿Tú vas a ser mi escolta? Me alegro, todo este asunto de los Hierro Negro me tiene un poco nervioso.$B$BBueno, voy a acabar de prepararme; ven a hablar conmigo cuando quieras que salgamos.', 0);
-- 309 Proteger el envío
-- https://es.classic.wowhead.com/quest=309
SET @ID := 309;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin, gracias a la Luz, la pólvora ha llegado! Pero eso que los Hierro Negro tengan ayuda interna para conseguir material es muy inquietante.$B$BPero no soy yo quien debe ocuparse de eso; yo voy a ocuparme de la pólvora.', 0),
(@ID, 'esMX', '¡Por fin, gracias a la Luz, la pólvora ha llegado! Pero eso que los Hierro Negro tengan ayuda interna para conseguir material es muy inquietante.$B$BPero no soy yo quien debe ocuparse de eso; yo voy a ocuparme de la pólvora.', 0);
-- 2240 La cámara oculta
-- https://es.classic.wowhead.com/quest=2240
SET @ID := 2240;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que informar?', 0),
(@ID, 'esMX', '¿Tienes algo que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has visto la cámara de Khaz\'mul? ¡No puedo creerlo! Baelog estaba seguro de su existencia pero yo he de reconocer que tenía mis dudas.$B$BGracias, $n. Con un poco de suerte, tu hallazgo incitará a nuestros líderes a seguir luchando por recuperar Uldaman. Y, si algún día vuelve a estar bajo el control de Forjaz, ¡los secretos de la cámara de Khaz\'mul serán nuestros!', 0),
(@ID, 'esMX', '¿Has visto la cámara de Khaz\'mul? ¡No puedo creerlo! Baelog estaba seguro de su existencia pero yo he de reconocer que tenía mis dudas.$B$BGracias, $n. Con un poco de suerte, tu hallazgo incitará a nuestros líderes a seguir luchando por recuperar Uldaman. Y, si algún día vuelve a estar bajo el control de Forjaz, ¡los secretos de la cámara de Khaz\'mul serán nuestros!', 0);
-- 250 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=250
SET @ID := 250;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En el barril de aspecto sospechoso hay unos polvos de olor extraño.', 0),
(@ID, 'esMX', 'En el barril de aspecto sospechoso hay unos polvos de olor extraño.', 0);
-- 199 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=199
SET @ID := 199;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste alguna pista, $n?', 0),
(@ID, 'esMX', '¿Encontraste alguna pista, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto tiene muy mala pinta!', 0),
(@ID, 'esMX', '¡Esto tiene muy mala pinta!', 0);
-- 161 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=161
SET @ID := 161;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Decías algo? No oigo nada, me pitan los oídos. ¿Qué es eso que me traes?', 0),
(@ID, 'esMX', '¿Decías algo? No oigo nada, me pitan los oídos. ¿Qué es eso que me traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, Hinderweir tiene motivos para preocuparse.', 0),
(@ID, 'esMX', 'Sí, Hinderweir tiene motivos para preocuparse.', 0);
-- 385 La caza de crocoliscos
-- https://es.classic.wowhead.com/quest=385
SET @ID := 385;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te he contado lo del croco que casi se me come la mano? Tenía unos dientes como puñales, así... Pero le bloqueé la mandíbula con el cuchillo. Creo que todavía lo tengo por aquí...', 0),
(@ID, 'esMX', '¿Te he contado lo del croco que casi se me come la mano? Tenía unos dientes como puñales, así... Pero le bloqueé la mandíbula con el cuchillo. Creo que todavía lo tengo por aquí...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Esto es de excelente calidad.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Esto es de excelente calidad.', 0);
-- 257 La fanfarronada de un cazador
-- https://es.classic.wowhead.com/quest=257
SET @ID := 257;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sin suerte? No te sientas mal, $n...$B$BNo todo el mundo puede ser yo.', 0),
(@ID, 'esMX', '¿Sin suerte? No te sientas mal, $n...$B$BNo todo el mundo puede ser yo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que lo has conseguido?$B$BBah, tampoco hay para tanto; hasta un crío con un arco de juguete podría matar a estas bestezuelas. Y no te emociones matando águilas ratoneras, que no es cuestión de que se extingan.$B$BBueno, pues... En fin, Daryl el Audaz siempre cumple su palabra.', 0),
(@ID, 'esMX', '¿Que lo has conseguido?$B$BBah, tampoco hay para tanto; hasta un crío con un arco de juguete podría matar a estas bestezuelas. Y no te emociones matando águilas ratoneras, que no es cuestión de que se extingan.$B$BBueno, pues... En fin, Daryl el Audaz siempre cumple su palabra.', 0);
-- 258 El reto de un cazador
-- https://es.classic.wowhead.com/quest=258
SET @ID := 258;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es natural sentir lástima por ti mismo cuando te lo muestra alguien lo $gnuevo:nueva; que eres en este mundo. No deberías sentirte mal, $n.$B$B¿Hm? ¿Entendí mal tu nombre?', 0),
(@ID, 'esMX', 'Es natural sentir lástima por ti mismo cuando te lo muestra alguien lo $gnuevo:nueva; que eres en este mundo. No deberías sentirte mal, $n.$B$B¿Hm? ¿Entendí mal tu nombre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esos jabalís te han dejado para el arrastre, ¿eh? No te preocupes, que no se lo diré a nadie; bastante mal lo estás pasando.$B$BAh, ¡que sí los has matado! Pues..., bueno, es normal. Era un juego de niños...$B$B¿Apuesta? ¿Qué apuesta?', 0),
(@ID, 'esMX', 'Esos jabalís te han dejado para el arrastre, ¿eh? No te preocupes, que no se lo diré a nadie; bastante mal lo estás pasando.$B$BAh, ¡que sí los has matado! Pues..., bueno, es normal. Era un juego de niños...$B$B¿Apuesta? ¿Qué apuesta?', 0);
-- 271 La venganza de Vyrin
-- https://es.wowhead.com/quest=271
-- https://wow-es.gamepedia.com/Misión:La venganza de Vyrin
SET @ID := 271;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya estás aquí, $n? ¿Qué tal la caza? ¡No te preocupes si no ha ido bien, ya irás mejorando!$B$BTampoco es que pudieras hacerlo peor que ahora...', 0),
(@ID, 'esMX', '¿Ya estás aquí, $n? ¿Qué tal la caza? ¡No te preocupes si no ha ido bien, ya irás mejorando!$B$BTampoco es que pudieras hacerlo peor que ahora...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué... Qué es esto? Parece una cabeza de oso.$B$B<Se toca la cicatriz sin darse cuenta.>$B$BInteresante. Pero claro, no puede ser aquel oso...$B$B<Se queda callado y empieza a temblar.>$B$B¡Llévatela! ¡Fuera de mi vista!', 0),
(@ID, 'esMX', '¿Qué... Qué es esto? Parece una cabeza de oso.$B$B<Se toca la cicatriz sin darse cuenta.>$B$BInteresante. Pero claro, no puede ser aquel oso...$B$B<Se queda callado y empieza a temblar.>$B$B¡Llévatela! ¡Fuera de mi vista!', 0);
-- 531 La venganza de Vyrin
-- https://es.classic.wowhead.com/quest=531
SET @ID := 531;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n, eso le enseñará! Dame la cabeza, ya me ocupo yo de ella.', 0),
(@ID, 'esMX', '¡Muy bien, $n, eso le enseñará! Dame la cabeza, ya me ocupo yo de ella.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. Llevaba tiempo buscando la revancha, ¡y lo hemos conseguido! Ten, te has ganado esto.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. Llevaba tiempo buscando la revancha, ¡y lo hemos conseguido! Ten, te has ganado esto.', 0);
-- 224 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=224
SET @ID := 224;
UPDATE `quest_template_locale` SET `Objectives` = 'El montaraz Pedernal, de Thelsamar, quiere que mates a 10 Troggs Rompecantos y 10 Exploradores Rompecantos.' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Loch Modan está sitiado, $n! Necesitamos que todos los miembros sanos de la Alianza ayuden a nuestra causa. ¿Has matado a 10 Troggs Rompecantos y 10 Exploradores Rompecantos?', 0),
(@ID, 'esMX', '¡Loch Modan está sitiado, $n! Necesitamos que todos los miembros sanos de la Alianza ayuden a nuestra causa. ¿Has matado a 10 Troggs Rompecantos y 10 Exploradores Rompecantos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Has demostrado un valor excepcional en combate; nos has ayudado mucho en nuestra lucha contra los troggs.$B$BSi quieres buscarte más aventuras, ve a hablar con el montaraz Gravagau; seguro que agradece la ayuda de alguien tan capaz como tú. Está en la torre.', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Has demostrado un valor excepcional en combate; nos has ayudado mucho en nuestra lucha contra los troggs.$B$BSi quieres buscarte más aventuras, ve a hablar con el montaraz Gravagau; seguro que agradece la ayuda de alguien tan capaz como tú. Está en la torre.', 0);
-- 237 En defensa de las tierras del rey
-- https://es.classic.wowhead.com/quest=237
SET @ID := 237;
UPDATE `quest_template_locale` SET `Objectives` = 'El montaraz Gravagau, de la torre de vigilancia sur, quiere que mates a 10 Aplastacráneos Rompecantos y 10 Videntes Rompecantos. Luego ve a informarle.' WHERE `ID` = @ID AND locale IN ('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitamos más tiempo, $r. Tus órdenes son matar 10 Aplastacráneos Rompecantos y 10 Videntes Rompecantos. Mantener al enemigo bajo presión hasta que se nos unan refuerzos. Este no es momento para comportamientos inactivos.', 0),
(@ID, 'esMX', 'Necesitamos más tiempo, $r. Tus órdenes son matar 10 Aplastacráneos Rompecantos y 10 Videntes Rompecantos. Mantener al enemigo bajo presión hasta que se nos unan refuerzos. Este no es momento para comportamientos inactivos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $r.$B$BPero los refuerzos prometidos no han llegado; muchos de los nuestros yacen en el campo de batalla. Amargo es el dolor, pero debemos seguir adelante, por la Alianza.$B$BHabla con el montaraz Muroplof para que te informe de tu nuevo destino.', 0),
(@ID, 'esMX', 'Buen trabajo, $r.$B$BPero los refuerzos prometidos no han llegado; muchos de los nuestros yacen en el campo de batalla. Amargo es el dolor, pero debemos seguir adelante, por la Alianza.$B$BHabla con el montaraz Muroplof para que te informe de tu nuevo destino.', 0);
