-- 274 Se aproxima una oscura amenaza
-- https://es.classic.wowhead.com/quest=274
SET @ID := 274;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te ha dado Ashlan para mí?', 0),
(@ID, 'esMX', '¿Qué te ha dado Ashlan para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un coloide desactivador para polvo de seforio?', 0),
(@ID, 'esMX', '¿Un coloide desactivador para polvo de seforio?', 0);
-- 631 El Puente Thandol
-- https://es.classic.wowhead.com/quest=631
SET @ID := 631;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Registras el diminuto cadáver enano. Grabado en el yelmo puedes leer claramente: Ebenezer Herrumbra.', 0),
(@ID, 'esMX', 'Registras el diminuto cadáver enano. Grabado en el yelmo puedes leer claramente: Ebenezer Herrumbra.', 0);
-- 304 Una misión hedionda
-- https://es.classic.wowhead.com/quest=304
SET @ID := 304;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has localizado a Balgaras el Hediondo, $c? Se nos ha estado escapando demasiado tiempo.', 0),
(@ID, 'esMX', '¿Ya has localizado a Balgaras el Hediondo, $c? Se nos ha estado escapando demasiado tiempo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Balgaras el Hediondo por fin está muerto. Aunque su muerte no devolverá la vida a todos los enanos inocentes que murieron innecesariamente a sus manos, ayudará a devolver la paz a los que sobrevivieron. Con Balgaras muerto, debería ser fácil acabar con el resto de escoria Hierro Negro. Ahora debemos exterminarlos antes de que sea enviado un nuevo líder.$B$BLo has hecho bien, $c.', 0),
(@ID, 'esMX', 'Balgaras el Hediondo por fin está muerto. Aunque su muerte no devolverá la vida a todos los enanos inocentes que murieron innecesariamente a sus manos, ayudará a devolver la paz a los que sobrevivieron. Con Balgaras muerto, debería ser fácil acabar con el resto de escoria Hierro Negro. Ahora debemos exterminarlos antes de que sea enviado un nuevo líder.$B$BLo has hecho bien, $c.', 0);
-- 303 La guerra contra los Hierro Negro
-- https://es.classic.wowhead.com/quest=303
SET @ID := 303;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Roggo no ha podido contactar con las fuerzas de reserva. Necesitamos presión ofensiva sobre ese campamento Hierro Negro, $c. ¡Ahora vuelve y cumple tu deber con el rey Magni!', 0),
(@ID, 'esMX', 'Roggo no ha podido contactar con las fuerzas de reserva. Necesitamos presión ofensiva sobre ese campamento Hierro Negro, $c. ¡Ahora vuelve y cumple tu deber con el rey Magni!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cumples bien tus órdenes, $c. Has demostrado ser $gun:una; valiente soldado y $gun:una; leal $gservidor:servidora; del rey Magni, ¡te rindo homenaje! Gracias a la presión que ejerciste sobre el campamento Hierro Negro tenemos ahora una oportunidad para expulsarlos definitivamente de nuestras tierras... si tan solo aparecieran las condenadas fuerzas de reserva...', 0),
(@ID, 'esMX', 'Cumples bien tus órdenes, $c. Has demostrado ser $gun:una; valiente soldado y $gun:una; leal $gservidor:servidora; del rey Magni, ¡te rindo homenaje! Gracias a la presión que ejerciste sobre el campamento Hierro Negro tenemos ahora una oportunidad para expulsarlos definitivamente de nuestras tierras... si tan solo aparecieran las condenadas fuerzas de reserva...', 0);
-- 378 La furia mora en las profundidades
-- https://es.classic.wowhead.com/quest=378
SET @ID := 378;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No dejaré que la estúpida burocracia humana interfiera en los asuntos de los enanos, $n. Se ha demostrado que Kam Furiahonda conspiró en el ataque al Puente Thandol. Las gentes del rey Magni perdieron sus vidas por las mentiras y la traición de Furiahonda. Puede que los humanos se hayan quedado satisfechos dejando que Furiahonda se pudra en Las Mazmorras, pero yo no dormiré tranquilo hasta que Furiahonda sea asesinado.', 0),
(@ID, 'esMX', 'No dejaré que la estúpida burocracia humana interfiera en los asuntos de los enanos, $n. Se ha demostrado que Kam Furiahonda conspiró en el ataque al Puente Thandol. Las gentes del rey Magni perdieron sus vidas por las mentiras y la traición de Furiahonda. Puede que los humanos se hayan quedado satisfechos dejando que Furiahonda se pudra en Las Mazmorras, pero yo no dormiré tranquilo hasta que Furiahonda sea asesinado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que Kam Furiahonda por fin supo lo que es mirar a la muerte a los ojos? Bien. Esa cobarde escoria Hierro Negro lo tenía bien merecido. Lo has hecho bien, $c. Las víctimas del ataque al Puente Thandol fueron unas víctimas más de un mundo torturado por la guerra y el caos. Sus familias tendrán la paz de saber que Furiahonda recibió el castigo que merecía. La muerte del hermano de Largatrenza ha sido vengada.', 0),
(@ID, 'esMX', '¿Así que Kam Furiahonda por fin supo lo que es mirar a la muerte a los ojos? Bien. Esa cobarde escoria Hierro Negro lo tenía bien merecido. Lo has hecho bien, $c. Las víctimas del ataque al Puente Thandol fueron unas víctimas más de un mundo torturado por la guerra y el caos. Sus familias tendrán la paz de saber que Furiahonda recibió el castigo que merecía. La muerte del hermano de Largatrenza ha sido vengada.', 0);
-- 632 El Puente Thandol
-- https://es.classic.wowhead.com/quest=632
SET @ID := 632;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna señal de Herrumbra, $n?', 0),
(@ID, 'esMX', '¿Alguna señal de Herrumbra, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, no puede ser, son malas noticias...', 0),
(@ID, 'esMX', 'Oh, no puede ser, son malas noticias...', 0);
-- 633 El Puente Thandol
-- https://es.classic.wowhead.com/quest=633
SET @ID := 633;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El alijo de explosivos debe ser destruido!', 0),
(@ID, 'esMX', '¡El alijo de explosivos debe ser destruido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo que queda del puente está a salvo! Has prestado un gran servicio al rey Magni y a las gentes de Khaz Modan.$B$BSi tan solo pudiéramos resistir hasta la llegada de los refuerzos...', 0),
(@ID, 'esMX', '¡Lo que queda del puente está a salvo! Has prestado un gran servicio al rey Magni y a las gentes de Khaz Modan.$B$BSi tan solo pudiéramos resistir hasta la llegada de los refuerzos...', 0);
-- 647 Licor de luna de Mackreel
-- https://es.classic.wowhead.com/quest=647
SET @ID := 647;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cuál es la buena noticia, $r?', 0),
(@ID, 'esMX', '¿Cuál es la buena noticia, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, nada como licor de luna de Nubos MacKreel para calentarte en un día fresco! Y aquí estaba pensando que el mal bicho volvería a estar atrasado en sus pagos. ¡Gracias amigo! ¡Muchas gracias de hecho!', 0),
(@ID, 'esMX', '¡Ah, nada como licor de luna de Nubos MacKreel para calentarte en un día fresco! Y aquí estaba pensando que el mal bicho volvería a estar atrasado en sus pagos. ¡Gracias amigo! ¡Muchas gracias de hecho!', 0);
-- 634 Petición a la Alianza
-- https://es.classic.wowhead.com/quest=634
SET @ID := 634;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todas mis condolencias para Largatrenza y sus valientes soldados. Las noticias del Puente Thandol y de la caída de Dun Modr son un duro golpe.$B$BPero Stromgarde ha caído, de ahí nuestra presencia aquí, en el Refugio de la Zaga. Nos enfrentamos a la reconquista de nuestra propia ciudad.$B$BEl honor y el sentido del deber nos impiden abandonar las Tierras altas hasta que en Stromgarde vuelva a ondear el estandarte del Rey. Enviaré un mensaje a Largatrenza advirtiéndole de que está solo...', 0),
(@ID, 'esMX', 'Todas mis condolencias para Largatrenza y sus valientes soldados. Las noticias del Puente Thandol y de la caída de Dun Modr son un duro golpe.$B$BPero Stromgarde ha caído, de ahí nuestra presencia aquí, en el Refugio de la Zaga. Nos enfrentamos a la reconquista de nuestra propia ciudad.$B$BEl honor y el sentido del deber nos impiden abandonar las Tierras altas hasta que en Stromgarde vuelva a ondear el estandarte del Rey. Enviaré un mensaje a Largatrenza advirtiéndole de que está solo...', 0);
-- 472 La caída de Dun Modr
-- https://es.classic.wowhead.com/quest=472
SET @ID := 472;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué valiente $c envía un mensaje desde Menethil? Ah $n, te llaman.$B$BTraes algo de luz a una situación desesperada. Es una buena noticia que el joven Harlo sobreviviera. Al huir resultó gravemente herido. Apenas tuvimos tiempo para enviarle a lomos del único corcel que quedaba con vida de todo el regimiento.$B$BPero ahora nos enfrentamos a una situación muy peligrosa. Dun Modr ha caído y solo somos una sombra del gran regimiento que fuimos un día.', 0),
(@ID, 'esMX', '¿Qué valiente $c envía un mensaje desde Menethil? Ah $n, te llaman.$B$BTraes algo de luz a una situación desesperada. Es una buena noticia que el joven Harlo sobreviviera. Al huir resultó gravemente herido. Apenas tuvimos tiempo para enviarle a lomos del único corcel que quedaba con vida de todo el regimiento.$B$BPero ahora nos enfrentamos a una situación muy peligrosa. Dun Modr ha caído y solo somos una sombra del gran regimiento que fuimos un día.', 0);
-- 473 Preséntate ante el capitán Puñorrecio
-- https://es.classic.wowhead.com/quest=473
SET @ID := 473;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Valstag me ha informado de tus éxitos sobre los orcos Faucedraco en Dun Algaz. Eres $gun:una; $r de gran valor.$B$BY tengo una tarea para ti.', 0),
(@ID, 'esMX', '$n. Valstag me ha informado de tus éxitos sobre los orcos Faucedraco en Dun Algaz. Eres $gun:una; $r de gran valor.$B$BY tengo una tarea para ti.', 0);
-- 464 Estandartes de batalla
-- https://es.classic.wowhead.com/quest=464
SET @ID := 464;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has atacado ya el campamento Faucedraco?', 0),
(@ID, 'esMX', '¿Has atacado ya el campamento Faucedraco?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen combate, $n. Los Faucedraco ya no suponen la misma amenaza que cuando tenían dragones, pero siguen siendo unos duros oponentes.$B$BLos Faucedraco están liderados por Nek\'rosh, hijo de Nekros, su antiguo cabecilla. Nekros utilizó poderosa magia para domar a los dragones rojos, pero cuando la magia le falló... los dragones no estaban muy contentos.$B$BNekros fue asesinado y su hijo ha jurado venganza contra los dragones que acabaron con su padre.', 0),
(@ID, 'esMX', 'Buen combate, $n. Los Faucedraco ya no suponen la misma amenaza que cuando tenían dragones, pero siguen siendo unos duros oponentes.$B$BLos Faucedraco están liderados por Nek\'rosh, hijo de Nekros, su antiguo cabecilla. Nekros utilizó poderosa magia para domar a los dragones rojos, pero cuando la magia le falló... los dragones no estaban muy contentos.$B$BNekros fue asesinado y su hijo ha jurado venganza contra los dragones que acabaron con su padre.', 0);
-- 484 Piel de crocolisco joven
-- https://es.classic.wowhead.com/quest=484
SET @ID := 484;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿verdad? ¿Tienes mis pieles?', 0),
(@ID, 'esMX', '$n, ¿verdad? ¿Tienes mis pieles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un buen trabajo, $n. Estas pieles son espléndidas. Tendré que curtirlas lo antes posible. Oh, pero antes de hacerlo, tengo otro trabajo del que podrías encargarte.', 0),
(@ID, 'esMX', 'Has hecho un buen trabajo, $n. Estas pieles son espléndidas. Tendré que curtirlas lo antes posible. Oh, pero antes de hacerlo, tengo otro trabajo del que podrías encargarte.', 0);
-- 471 Deberes de aprendiz
-- https://es.classic.wowhead.com/quest=471
SET @ID := 471;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi aprendiz es como un hijo para mí. Le va a ser difícil vivir con una sola pierna.$B$BAh, $n, ¿qué tal va? ¿Tienes mis pieles?', 0),
(@ID, 'esMX', 'Mi aprendiz es como un hijo para mí. Le va a ser difícil vivir con una sola pierna.$B$BAh, $n, ¿qué tal va? ¿Tienes mis pieles?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Umm... No creo que estés $ginteresado:interesada; en convertirte en mi aprendiz, ¿verdad?$B$B¡Ja! No, estoy bromeando. Eres demasiado mayor. Además por tu aspecto se diría que tienes otras ambiciones. Bueno, en cualquier caso, me has traído buenas pieles y me serán muy útiles.', 0),
(@ID, 'esMX', 'Umm... No creo que estés $ginteresado:interesada; en convertirte en mi aprendiz, ¿verdad?$B$B¡Ja! No, estoy bromeando. Eres demasiado mayor. Además por tu aspecto se diría que tienes otras ambiciones. Bueno, en cualquier caso, me has traído buenas pieles y me serán muy útiles.', 0);
-- 279 Zarpas de las profundidades
-- https://es.classic.wowhead.com/quest=279
SET @ID := 279;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros mercaderes no estarán a salvo hasta que nos libremos de Engullidor y de esos murlocs.', 0),
(@ID, 'esMX', 'Nuestros mercaderes no estarán a salvo hasta que nos libremos de Engullidor y de esos murlocs.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bien hecho, $n.$B$BAcepta esto como pago por haber cumplido con tu contrato con los marinos mercantes.', 0),
(@ID, 'esMX', 'Ah, bien hecho, $n.$B$BAcepta esto como pago por haber cumplido con tu contrato con los marinos mercantes.', 0);
-- 1302 James Hyal
-- https://es.classic.wowhead.com/quest=1302
SET @ID := 1302;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'James Hyal, James Hyal... ¿Por qué me suena tan familiar?$B$B¡Claro! Por el incidente de la Posada Reposo Umbrío. Si tienes información relacionada con lo que ocurrió allí, deberías comunicársela al capitán Vimes cuanto antes. Es él quien lleva la investigación.', 0),
(@ID, 'esMX', 'James Hyal, James Hyal... ¿Por qué me suena tan familiar?$B$B¡Claro! Por el incidente de la Posada Reposo Umbrío. Si tienes información relacionada con lo que ocurrió allí, deberías comunicársela al capitán Vimes cuanto antes. Es él quien lleva la investigación.', 0);
-- 288 La Tercera Flota
-- https://es.classic.wowhead.com/quest=288
SET @ID := 288;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, ¡tengo mucha sed! ¿No quieres comprarle algo de beber a este pobre y lamentable idiota?', 0),
(@ID, 'esMX', 'Oh, ¡tengo mucha sed! ¿No quieres comprarle algo de beber a este pobre y lamentable idiota?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Ah, me sienta de perlas y suelta la lengua. ¡Gracias colega!', 0),
(@ID, 'esMX', '¡Ah! Ah, me sienta de perlas y suelta la lengua. ¡Gracias colega!', 0);
-- 463 El Guardaverde
-- https://es.classic.wowhead.com/quest=463
SET @ID := 463;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las hiedras y helechos hablan muy bien de ti, $gpequeño:pequeña;. Aunque tengo muchos nombres, solo respondo a unos pocos. Tú puedes llamarme Rethiel.$B$BDebes aguzar el oído... lamentar el destino de estas tierras heridas y te encargaré la misión de sanarlas.', 0),
(@ID, 'esMX', 'Las hiedras y helechos hablan muy bien de ti, $gpequeño:pequeña;. Aunque tengo muchos nombres, solo respondo a unos pocos. Tú puedes llamarme Rethiel.$B$BDebes aguzar el oído... lamentar el destino de estas tierras heridas y te encargaré la misión de sanarlas.', 0);
-- 321 Hierro Forjaluz
-- https://es.classic.wowhead.com/quest=321
SET @ID := 321;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cofre está empapado y el revestimiento está roto. El interior y el exterior del cofre están dañados con zarpazos... como si los murlocs hubieran estado rebuscando y hubieran robado su tesoro.$B$BPero escondido en el cofre descubres un Lingote Forjaluz. Por desgracia se necesitan muchos más para conseguir el metal necesario para forjar un arma.', 0),
(@ID, 'esMX', 'El cofre está empapado y el revestimiento está roto. El interior y el exterior del cofre están dañados con zarpazos... como si los murlocs hubieran estado rebuscando y hubieran robado su tesoro.$B$BPero escondido en el cofre descubres un Lingote Forjaluz. Por desgracia se necesitan muchos más para conseguir el metal necesario para forjar un arma.', 0);
-- 1249 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1249
SET @ID := 1249;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Se escapó? Parecía un poco turbio por la forma en que nos miraba.', 0),
(@ID, 'esMX', '¿Se escapó? Parecía un poco turbio por la forma en que nos miraba.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Le has cogido, ¿eh? Bien por ti. Me sorprende que ese fuera Slim.$B$BSeré sincero, nunca pensé que echaría de menos la excitación de algunas de las actividades más turbias. Supongo que las viejas costumbres nunca mueren. No se lo digas a Elling... probablemente intentaría conseguir que volviera a Ventormenta si se enterase de que echo de menos la acción.$B$BMe alegro de haber podido ayudarte en tu estancia en Menethil. Si necesitas algo más, solo tienes que pedirlo.', 0),
(@ID, 'esMX', 'Le has cogido, ¿eh? Bien por ti. Me sorprende que ese fuera Slim.$B$BSeré sincero, nunca pensé que echaría de menos la excitación de algunas de las actividades más turbias. Supongo que las viejas costumbres nunca mueren. No se lo digas a Elling... probablemente intentaría conseguir que volviera a Ventormenta si se enterase de que echo de menos la acción.$B$BMe alegro de haber podido ayudarte en tu estancia en Menethil. Si necesitas algo más, solo tienes que pedirlo.', 0);
-- 1250 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1250
SET @ID := 1250;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿EL REY?! Eh... ¿el rey? ¿El rey, rey? ¿Estás de broma? No dijiste que estabas buscando a los secuestradores del rey. Ni siquiera sabía que había desaparecido... aunque eso explicaría la coronación de su hijo.$B$BEscribiré a Elling ahora mismo. Querrá saber que estás encargándote de esto.$B$BNunca habría adivinado que Jahn vendiese Ventormenta por una simple moneda. Incluso un pícaro debe tener honor cuando se trata de ciertas cosas.$B$BAhora, lo importante es encontrar a ese Hendel. Y creo que puedo ayudarte con eso.', 0),
(@ID, 'esMX', '¡¿EL REY?! Eh... ¿el rey? ¿El rey, rey? ¿Estás de broma? No dijiste que estabas buscando a los secuestradores del rey. Ni siquiera sabía que había desaparecido... aunque eso explicaría la coronación de su hijo.$B$BEscribiré a Elling ahora mismo. Querrá saber que estás encargándote de esto.$B$BNunca habría adivinado que Jahn vendiese Ventormenta por una simple moneda. Incluso un pícaro debe tener honor cuando se trata de ciertas cosas.$B$BAhora, lo importante es encontrar a ese Hendel. Y creo que puedo ayudarte con eso.', 0);
-- 1264 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1264
SET @ID := 1264;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un placer conocerte, $n. Soy el comandante Samaul. Estoy al cargo de las tropas de Jaina Valiente aquí, en Theramore.$B$BEstoy bastante ocupado pero, si tienes alguna pregunta, no dudes en hacérmela. Quizás no tenga mucho tiempo, pero no hay razón para que me ponga desagradable si necesitas mi ayuda.$B$BSi estás planeando viajar fuera de la ciudad, te sugiero que tengas cuidado. Además de ogros, orcos y murlocs, la parte sur del pantano está atestada de dragones negros.', 0),
(@ID, 'esMX', 'Un placer conocerte, $n. Soy el comandante Samaul. Estoy al cargo de las tropas de Jaina Valiente aquí, en Theramore.$B$BEstoy bastante ocupado pero, si tienes alguna pregunta, no dudes en hacérmela. Quizás no tenga mucho tiempo, pero no hay razón para que me ponga desagradable si necesitas mi ayuda.$B$BSi estás planeando viajar fuera de la ciudad, te sugiero que tengas cuidado. Además de ogros, orcos y murlocs, la parte sur del pantano está atestada de dragones negros.', 0);
