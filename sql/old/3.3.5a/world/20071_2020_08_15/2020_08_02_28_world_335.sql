-- 64 La reliquia olvidada
-- https://es.classic.wowhead.com/quest=64
SET @ID := 64;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Por casualidad, ¿no conseguirías encontrar mi reloj, verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Mi reloj! ¡Muchas gracias, amable señor!$B$BSolo somos unos pobres granjeros y hemos perdido nuestras tierras, pero, por favor, acepta esta recompensa como una muestra de nuestro aprecio.', 0);

-- 151 La pobre y vieja Blanchy
-- https://es.classic.wowhead.com/quest=151
SET @ID := 151;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'La Vieja Blanchy está en las últimas. ¿Has podido encontrar algo de avena?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Muchísimas gracias, $n! ¡La pobre Vieja Blanchy se pondrá tan contenta!', 0);

-- 36 Estofado de los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=36
SET @ID := 36;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Voy a echar mucho de menos a Verna Furlbrow. ¿No la verías por casualidad cuando estuviste por ahí, verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esa Verna siempre fue una muchacha encantadora. La echaré de menos en los Páramos de Poniente pero, entre tú y yo, es una chica de ciudad y en Ventormenta estará muy a gusto. ¡Pero basta de chácharas! ¡Tenemos que hacer el estofado de los Páramos de Poniente!', 0);

-- 9 Campos de la muerte
-- https://es.classic.wowhead.com/quest=9
SET @ID := 9;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ya veo que has vuelto! Espero que hayas trabajado duro limpiando esos campos de esos vigias de la cosecha. ¿Ya mataste a veinte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo amigo. Te has ganado bien tu sueldo. Quién sabe, quizás los Páramos de Poniente vuelvan a ser prósperos.', 0);

-- 22 Pastel de hígado de dentosangre
-- https://es.classic.wowhead.com/quest=22
SET @ID := 22;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Todo lo que necesito para mi famosa empanada de carne son 8 hígados de dentosangre!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Son perfectos, $n! Muchas gracias. El granjero Saldean y yo vamos a darnos un gran festín. Toma, esto es para ti, por todo el trabajo. No pensarías que iba a dejar que un $c como tú se fuera con hambre, ¿eh?', 0);

-- 38 Estofado de los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=38
SET @ID := 38;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Vuelve con estos ingredientes:$B$B 3 piezas de carne fibrosa de buitre$B 3 morros de dentosangre$B 3 ojos de múrloc$B 3 okras', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Esa okra servirá para dar algo de consistencia al caldo, perfecto! Ahora solo nos falta por añadir carne fibrosa de buitre, unos cuantos ojos de múrloc y esos deliciosos morros de dentosangre... ¡y ya estará listo! Por toda tu ayuda, $n, ¡quiero que te lleves el primer lote de estofado de los Páramos de Poniente!', 0);

-- 109 Habla con Gryan Mantorrecio
-- https://es.classic.wowhead.com/quest=109
SET @ID := 109;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que te ha enviado aquí mi amigo, ¿eh? Qué amable por su parte.$B$BBien, te diré que la monarquía de Ventormenta nos ha abandonado. Ahora son Las Milicias del Pueblo las que mantienen la tierra a salvo de la corrupción. Si nuestra causa te interesa, puedo ofrecer a tus habilidades de combate un trabajo al servicio de la libertad.', 0);

-- 2998 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=2998
SET @ID := 2998;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Es hermoso estar en Ventormenta, ¿no?$B$BEl momento no podría haber sido mejor, $n.', 0);

-- 1643 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1643
SET @ID := 1643;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Oh, hola amor. ¿Cómo van tus aventuras? Me alegra saber que te va bien.$B$BOh, ¿yo? Gracias por preguntar, estoy bien, considerando todas las cosas.$B$BEl aumento de comerciantes ha disminuido la cantidad de cuero y tela de la que las personas están dispuestas a desprenderse en estos días, por lo que ha sido más difícil hacer ropa para los niños en el orfanato, pero nos las arreglaremos. Por "nosotros" me refiero a mi esposo y a mí. Está en Ironforge tratando de buscar ayuda de los ciudadanos allí.', 0);

-- 1644 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1644
SET @ID := 1644;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Espero que mi John esté teniendo más suerte en Forjaz. No le gusta ir allí porque tiene que dejarnos a mí y a los niños solos, pero sabe que tiene que hacerse. Es tan bueno...$B$BAlgunos años han sido más difíciles que otros, pero este desde luego, ha sido el más duro de todos. Parece que haya algo en el aire que anuncia un gran cambio. Pero... ¿quién sabe?', 0);

DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Muchas gracias, $n! ¡Muchas, muchas gracias!$B$BLos niños estarán felices, de verdad. ¡Y a mí me has ahorrado tanto tiempo! Ahora podré concentrarme en las otras necesidades de los niños. Y, con suerte, mi John podrá volver a casa antes de lo que pensábamos.$B$BGracias de nuevo, $n. Sabía que podía contar con la caridad de los demás. Que la Luz sea contigo.', 0);

-- 153 Pañuelos rojos de cuero
-- https://es.classic.wowhead.com/quest=153
SET @ID := 153;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 15 pañuelos de cuero rojo y te pagaré bien.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Buen trabajo, $r. Por favor, acepta uno de estos objetos como pago por tu trabajo.', 0);

-- 12 La Milicia Popular
-- https://es.classic.wowhead.com/quest=12
SET @ID := 12;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Quizás no me he explicado bien. Para demostrar que mereces servir a las Milicias del Pueblo y a la Luz, tienes que matar a 15 tramperos Defias y a 15 contrabandistas Defias. Vuelve aquí cuando lo hayas hecho.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Mi explorador ha sido testigo de tus hazañas. Estás dando muy buenas pruebas de tu valía.', 0);

-- 102 En patrulla por los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=102
SET @ID := 102;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ya has reunido 8 zarpas de esos gnolls traidores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Bien hecho, $n. Contando con valientes aventureros como tú luchando del lado de Las Milicias del Pueblo, los Páramos de Poniente podrán volver a ser el próspero granero que una vez fueron. Por favor, acepta esto como reconocimiento por tus incansables esfuerzos.', 0);

-- 6181 Mensajero a toda prisa
-- https://es.classic.wowhead.com/quest=6181
SET @ID := 6181;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Parece que tienes prisa. ¡Entonces has venido al lugar adecuado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Tienes que llevar esta nota a Ventormenta! Ningún problema, ¡puedes coger uno de mis grifos!', 0);

-- 6281 Prosigue hasta Ventormenta
-- https://es.classic.wowhead.com/quest=6281
SET @ID := 6281;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has estado viajando, ¿eh? ¿Has estado en algún sitio interesante?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, ¿una nota del intendente Lewis? No me sorprende que necesite más equipo. La Colina del Centinela está bastante lejos, en una tierra casi olvidada por Ventormenta.$B$BMuchas gracias, $n. Toma algo de dinero para cubrir los gastos del viaje.', 0);

-- 6261 Dungar Tragolargo
-- https://es.classic.wowhead.com/quest=6261
SET @ID := 6261;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Eso que tienes sobre la frente es sudor, $gmuchacho:muchacha;? Has tenido que correr mucho. ¡La próxima vez coge un grifo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Un cajón para los Páramos de Poniente, eh? ¿Has estado ya allí antes? Si es así no hay ningún problema, amigo. ¡Tengo muchos grifos entrenados para recorrer esa ruta!', 0);

-- 6285 Regresa junto a Lewis
-- https://es.classic.wowhead.com/quest=6285
SET @ID := 6285;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ya has vuelto de Ventormenta? ¿Ha enviado Osric la armadura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Genial, ¡has traído la armadura! Repartiremos esto entre quien lo necesite.$B$BGracias, $n. Tus esfuerzos nos han sido de gran ayuda. Y ahora que ya estás familiarizado con los grifos, ¡espero que vuelvas a menudo y prestes tu ayuda a la Colina del Centinela!', 0);

-- 13 La Milicia Popular
-- https://es.classic.wowhead.com/quest=13
SET @ID := 13;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'No tenemos tiempo para hablar, $n. Los saqueadores de Defias están negando a la gente de Páramos de Poniente la paz y la prosperidad que se merecen. Asegúrese de que al menos 15 saqueadores Defias y 15 despojadores Defias hayan sido asesinados. Eso enviará un mensaje claro de que la corrupción no es bienvenida aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hasta ahora tus hazañas no han dejado de probar tu valía para las Milicias del Pueblo.', 0);
