-- 386 Lo que sucede alrededor...
-- https://es.classic.wowhead.com/quest=386
SET @ID := 386;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ya has estado en las Mazmorras de Ventormenta? Temo que el poder que ha mantenido a Targor con vida acabe por conseguir liberarlo. Fue sentenciado a muerte, no a ser un títere político.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Targor el Pavoroso ha caído al fin. Me alegro. Buen trabajo, $n. A veces solo se puede hacer justicia al margen de los tribunales y los políticos.', 0);
-- 120 Mensajero a Ventormenta
-- https://es.classic.wowhead.com/quest=120
SET @ID := 120;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué llevas ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Descansa, $c.$B$BEl magistrado Solomon es un líder de los nobles; siempre atiendo a sus palabras. Voy a reunirme con el Rey para exponerle la situación. Dile al magistrado que enviaremos refuerzos en cuanto Su Majestad dé la orden.', 0);
-- 121 Mensajero a Ventormenta
-- https://es.classic.wowhead.com/quest=121
SET @ID := 121;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué noticias envía el General? ¿Vienen refuerzos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por todo, $c. Acepta estas monedas por tus servicios a Villa del Lago y Ventormenta.$B$BY ahora disculpa, pero esta correspondencia me intriga; está pasando algo turbio. Temo que se avecine otro conflicto.', 0);
-- 116 Tiempos de sequía
-- https://es.classic.wowhead.com/quest=116
SET @ID := 116;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito que vayas a recoger un barril de cerveza Cebatruenos de Tragoamargo Cebatruenos, que está en las colinas de Páramos de Poniente, uno de vino dulce en Ventormenta, una botella de licor de luna en Villa Oscura y una de ron dulce en Villadorada. Tráeme todo eso y te ganarás una recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Buen trabajo, $n! Sé qué caminos has tenido que recorrer para traer este licor. ¡Esto complacerá a mis patronos!$B$BMi esposa cose muy bien; acepta esta capa en agradecimiento por tus servicios.', 0);
-- 118 El precio de unas herraduras
-- https://es.classic.wowhead.com/quest=118
SET @ID := 118;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué dices? ¿Que vienes de parte de Verner? Pues dame la nota. ¡Y habla más alto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Así que necesita herraduras, ¿eh?', 0);
-- 132 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=132
SET @ID := 132;
UPDATE `quest_template_locale` SET `Title` = 'La hermandad de los Defias' WHERE `ID` = @ID AND locale = 'esES';
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me alegro de verte de vuelta, $n. ¿Qué tenía que decir Wiley?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Bah! Debería haber acabado con esa escoria cuando tuve oportunidad de hacerlo. Pero esta información es crucial. Buen trabajo.', 0);
-- 135 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=135
SET @ID := 135;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué asuntos tienes conmigo? Soy un hombre muy ocupado...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Creo que este asunto es mucho más complicado de lo que cree Mantorrecio.', 0);
-- 141 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=141
SET @ID := 141;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Ha conseguido aclarar algo el maestro Shaw?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Edwin VanCleef... conozco muy bien ese nombre. Me desconcierta pensar que un hombre con tanto talento y tan trabajador pudiera convertirse en tal escoria. Necesitaré más pruebas antes de creerlo.', 0);
-- 388 El color de la sangre
-- https://es.classic.wowhead.com/quest=388
SET @ID := 388;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Veo que has vuelto, $c. ¿Has conseguido 10 pañuelos de lana roja de esa escoria Defias de las Mazmorras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Y estos pañuelos, símbolos asquerosos de corrupción, son por lo que mi Mac tuvo que morir? Qué gran pérdida. Qué trágico sacrificio.$B$BPero en fin, no puedo vivir en el pasado. Has de saber, $n, que tus actos han conseguido que se haga justicia con mi familia.', 0);
-- 142 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=142
SET @ID := 142;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, ¿pudiste reunir alguna información? ¿Localizaste al mensajero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto es sin duda alguna una prueba clara de que VanCleef está al mando. Ahora todo lo que tenemos que saber es dónde se oculta la banda Defias.$B$BTuvimos un golpe de suerte mientras estabas fuera. Capturamos a un ladrón que intentaba robar el carro de Saldean. Ha prometido guiarnos hasta la ladronera a cambio de su vida. Quiero que defiendas al traidor para que pueda enseñarnos la ladronera. Vuelve a verme cuando hayas descubierto su localización.', 0);
-- 155 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=155
SET @ID := 155;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué negocio tienes conmigo? Soy un hombre muy ocupado...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Excelente, $n! Ahora que sabemos dónde se oculta, VanCleef ya es nuestro.', 0);
-- 166 La hermandad de los Defias
-- https://es.classic.wowhead.com/quest=166
SET @ID := 166;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué tal va la caza y captura de Edwin Van Cleef?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, tu valentía es extraordinaria. Las Milicias del Pueblo te agradecen los servicios prestados a las gentes de los Páramos de Poniente. Ahora que VanCleef ha muerto, estamos ante el comienzo del fin de la Hermandad Defias. Esperemos que en un día no muy lejano la paz volverá a bendecir los llanos de estas tierras.', 0);
-- 119 Regresa junto a Verner
-- https://es.classic.wowhead.com/quest=119
SET @ID := 119;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Me alegro de verte! ¿Traes las herraduras?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, me hacía mucha falta.$B$BAh, hay una nota... ¿Cómo? ¡¿Argus quiere que le pague?! ¡Bah!$B$BBueno, gracias por tu ayuda.', 0);
-- 143 Mensajero a los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=143
SET @ID := 143;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Saludos, $c. ¿Qué te trae a hablar con Las Milicias del Pueblo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Has servido bien a tu maestro.', 0);
-- 214 Pañuelos rojos de seda
-- https://es.classic.wowhead.com/quest=214
SET @ID := 214;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has estado defendiendo nuestra tierra de la banda Defias? Si es así enséñame 10 pañuelos de seda roja como prueba.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Bien hecho, $n! En nombre de Las Milicias del Pueblo te rindo homenaje por todos tus esfuerzos. Pronto, y gracias a la ayuda de valientes como tú, devolveremos esta tierra a su pueblo.', 0);
-- 144 Mensajero a los Páramos de Poniente
-- https://es.classic.wowhead.com/quest=144
SET @ID := 144;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Están Las Milicias del Pueblo en camino? ¿Traes buenas noticias de Gryan Mantorrecio?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Esto no es nada bueno. No me había dado cuenta de que Mantorrecio está igual que nosotros. ¿Qué campaña es tan importante como para enviar al ejército de Ventormenta lejos de su gente? Lo sabré a su debido tiempo.$B$BTen, acepta estas monedas en pago por tus servicios Puede que vuelva a contratarte.', 0);
-- 122 Escamas de barriga
-- https://es.classic.wowhead.com/quest=122
SET @ID := 122;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Si no le envío las escamas a Argus, mandará a alguien a buscarlas. ¿Las tienes o no?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias, con esto pagaré a Argus.', 0);
-- 124 El aullido de los gnolls
-- https://es.classic.wowhead.com/quest=124
SET @ID := 124;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mis caballos todavía parecen asustados, y todavía escucho a ese maldito lobo llorar por la noche. ¡Por favor, $n, haz algo con esos Gnolls!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por tu ayuda, $n.', 0);
-- 126 El aullido de las colinas
-- https://es.classic.wowhead.com/quest=126
SET @ID := 126;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ululante es peligroso, $n. Entenderé que no seas capaz de enfrentarte a él.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias de nuevo. El ejército de Ventormenta está tan ocupado con los orcos que no hay tropas para proteger Crestagrana de otras amenazas, como los gnolls.', 0);
-- 91 Ley de Solomon
-- https://es.classic.wowhead.com/quest=91
SET @ID := 91;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tráeme 10 colgantes Pellejo Negro y te recompensaré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El Tribunal de Villa del Lago reconoce tu entrega a la justicia, $n. Gracias por ayudar a mantener la ley y el orden en el Reino.', 0);
-- 19 Tharil'zun
-- https://es.classic.wowhead.com/quest=19
SET @ID := 19;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Los orcos de Roca Negra siguen atacando. ¿Has acabado con Tharil\'zun?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Era fuerte y cruel; seguro que no fue fácil derrotarlo. Gracias; aquí tienes tu recompensa.', 0);
-- 180 Se busca: Teniente Fangore
-- https://es.classic.wowhead.com/quest=180
SET @ID := 180;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué nuevas nos traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Así que el malvado Fangore ha muerto? Pues buen viaje. Admiro tu valor, $c. Tienes la gratitud de Villa del Lago.', 0);
-- 145 Mensajero a Villa Oscura
-- https://es.classic.wowhead.com/quest=145
SET @ID := 145;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Parece que vienes de lejos, $c. ¿Qué te trae a Villa Oscura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Gracias por venir hasta aquí. Esta información es muy importante.', 0);
