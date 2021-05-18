-- 9730 El líder de los Cresta Oscura
-- https://es.wowhead.com/quest=9730
SET @ID := 9730;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Quieres hablar sobre la recompensa por el Rajá Brujobruma? Bueno, ¿está muerto? ¡No hay mucho más de qué hablar!', 0),
(@ID, 'esMX', '¿Quieres hablar sobre la recompensa por el Rajá Brujobruma? Bueno, ¿está muerto? ¡No hay mucho más de qué hablar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me gustan los nagas de Azeroth y menos aún los de aquí. Es una verdadera lástima que nuestra misión no pudiera seguir siendo pacífica pero no me verás derramar una lágrima por un naga muerto.$B$BAquí tienes tu recompensa por ocuparte del líder Cresta Oscura, $n.', 0),
(@ID, 'esMX', 'No me gustan los nagas de Azeroth y menos aún los de aquí. Es una verdadera lástima que nuestra misión no pudiera seguir siendo pacífica pero no me verás derramar una lágrima por un naga muerto.$B$BAquí tienes tu recompensa por ocuparte del líder Cresta Oscura, $n.', 0);
-- 9731 Planos de conducto
-- https://es.wowhead.com/quest=9731
SET @ID := 9731;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes, $n?', 0),
(@ID, 'esMX', '¿Qué noticias traes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los nagas han convertido el Lago Serpiente en un sumidero para el resto de la Marisma de Zangar. ¿Qué estarán tramando?$B$BHas hecho bien en traernos esa noticia, $n. Enviaremos a un equipo para que investiguen este conducto que has descubierto. Mientras tanto, tengo otra tarea para ti.', 0),
(@ID, 'esMX', 'Los nagas han convertido el Lago Serpiente en un sumidero para el resto de la Marisma de Zangar. ¿Qué estarán tramando?$B$BHas hecho bien en traernos esa noticia, $n. Enviaremos a un equipo para que investiguen este conducto que has descubierto. Mientras tanto, tengo otra tarea para ti.', 0);
-- 9732 Regresa a la Marisma
-- https://es.wowhead.com/quest=9732
SET @ID := 9732;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dichosos los ojos, $n. Las cosas en el Refugio Cenarion no han hecho más que empeorar desde que te fuiste.', 0),
(@ID, 'esMX', 'Dichosos los ojos, $n. Las cosas en el Refugio Cenarion no han hecho más que empeorar desde que te fuiste.', 0);
-- 9735 Verdaderos maestros de la Luz
-- https://es.wowhead.com/quest=9735
SET @ID := 9735;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste conseguir el agua?', 0),
(@ID, 'esMX', '¿Pudiste conseguir el agua?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmm... esta es una cantidad bastante pequeña. pero si tenemos cuidado. debería ser suficiente. Verás. la Cruzada Escarlata se cree dedicada a la Luz. Supongo que todavía lo son, de una manera retorcida, y eso es exactamente lo que espero aprovechar.$B$BSu celo equivocado incluso ha manchado la bendición pronunciada sobre esta agua, haciéndola ideal para mi propósito.', 0),
(@ID, 'esMX', 'Mmm... esta es una cantidad bastante pequeña. pero si tenemos cuidado. debería ser suficiente. Verás. la Cruzada Escarlata se cree dedicada a la Luz. Supongo que todavía lo son, de una manera retorcida, y eso es exactamente lo que espero aprovechar.$B$BSu celo equivocado incluso ha manchado la bendición pronunciada sobre esta agua, haciéndola ideal para mi propósito.', 0);
-- 9736 Verdaderos maestros de la Luz
-- https://es.wowhead.com/quest=9736
SET @ID := 9736;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha reunido los reactivos que necesitaré?', 0),
(@ID, 'esMX', '¿Ha reunido los reactivos que necesitaré?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que tenemos todos los reactivos, puedo preparar la mezcla.$B$B<Una lenta sonrisa se extiende por el rostro de Lady Liadrin.>$B$BTodo encaja perfectamente, $n. Cuando esto termine, te daré los detalles sobre lo que queda por hacer.', 0),
(@ID, 'esMX', 'Ahora que tenemos todos los reactivos, puedo preparar la mezcla.$B$B<Una lenta sonrisa se extiende por el rostro de Lady Liadrin.>$B$BTodo encaja perfectamente, $n. Cuando esto termine, te daré los detalles sobre lo que queda por hacer.', 0);
-- 9737 Verdaderos maestros de la Luz
-- https://es.wowhead.com/quest=9737
SET @ID := 9737;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Eliminar la protección de la Capilla de Alonsus', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hiciste lo que te pedí y entregaste mi mensaje? Los falsos paladines del mundo seguramente deben saber que su tiempo ha llegado a su fin.', 0),
(@ID, 'esMX', '¿Hiciste lo que te pedí y entregaste mi mensaje? Los falsos paladines del mundo seguramente deben saber que su tiempo ha llegado a su fin.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Todos los que se opongan a nosotros harían bien en prestar atención a la advertencia que has dado. Nuestros enemigos deben saber que están en peligro, desde el soldado de infantería más bajo hasta el $ghéroe:heroína; más $gpoderoso:poderosa;.$B$BTe has ganado tu lugar en las filas de los maestros. Tu dedicación y destreza sirven de ejemplo para todos los Caballeros de Sangre. Como símbolo de tu nuevo estatus, te concedo la capacidad de convocar y comandar al Destrero thalassiano.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Todos los que se opongan a nosotros harían bien en prestar atención a la advertencia que has dado. Nuestros enemigos deben saber que están en peligro, desde el soldado de infantería más bajo hasta el $ghéroe:heroína; más $gpoderoso:poderosa;.$B$BTe has ganado tu lugar en las filas de los maestros. Tu dedicación y destreza sirven de ejemplo para todos los Caballeros de Sangre. Como símbolo de tu nuevo estatus, te concedo la capacidad de convocar y comandar al Destrero thalassiano.', 0);
-- 9738 Desaparecidos en combate
-- https://es.wowhead.com/quest=9738
SET @ID := 9738;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Vinculador terrestre Rayge descubierto', `ObjectiveText2` = 'Naturalista Mordisco descubierto', `ObjectiveText3` = 'Desherbador Pulgarverde descubierto', `ObjectiveText4` = 'Clamavientos Zarpa descubierto', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has descubierto el paradero de mis cuatro compañeros?', 0),
(@ID, 'esMX', '¿Ya has descubierto el paradero de mis cuatro compañeros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que algunos de mis amigos aún vivan, pero me rompe el corazón saber el destino de otros. <suspiro>$B$BAl menos murieron haciendo lo que más amaban en la vida. Tienes mi eterna gratitud por ayudarme con esto, $n.$B$BPor favor, toma uno de estos como señal de gratitud.', 0),
(@ID, 'esMX', 'Me alegro de que algunos de mis amigos aún vivan, pero me rompe el corazón saber el destino de otros. <suspiro>$B$BAl menos murieron haciendo lo que más amaban en la vida. Tienes mi eterna gratitud por ayudarme con esto, $n.$B$BPor favor, toma uno de estos como señal de gratitud.', 0);
-- 9739 La aflicción de los esporinos
-- https://es.wowhead.com/quest=9739
SET @ID := 9739;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Las bolsas de esporas! ¿Las has conseguido?', 0),
(@ID, 'esMX', '¡Las bolsas de esporas! ¿Las has conseguido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! Cuentas con el agradecimiento de mi pueblo.$B$BEspero que lo entiendas... de aquí es de dónde vienen nuestras crías. ¡No podemos permitir que estas bestias devoren las bolsas!', 0),
(@ID, 'esMX', '¡Lo has conseguido! Cuentas con el agradecimiento de mi pueblo.$B$BEspero que lo entiendas... de aquí es de dónde vienen nuestras crías. ¡No podemos permitir que estas bestias devoren las bolsas!', 0);
-- 9741 Alimañas del vacío
-- https://es.wowhead.com/quest=9741
SET @ID := 9741;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las criaturas del vacío se convierten en anomalías del vacío. A decir verdad, realmente no sabemos qué son estas criaturas... el nombre es más una clasificación.', 0),
(@ID, 'esMX', 'Las criaturas del vacío se convierten en anomalías del vacío. A decir verdad, realmente no sabemos qué son estas criaturas... el nombre es más una clasificación.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La cosa está fatal, ¿verdad? Buen trabajo, $n. Voy a enviar a unos cuantos anacoretas a ayudar a Loryi y Jorli.', 0),
(@ID, 'esMX', 'La cosa está fatal, ¿verdad? Buen trabajo, $n. Voy a enviar a unos cuantos anacoretas a ayudar a Loryi y Jorli.', 0);
-- 9742 Más bolsas de esporas
-- https://es.wowhead.com/quest=9742
SET @ID := 9742;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has rescatado más bolsas de esporas; $r?', 0),
(@ID, 'esMX', '¿Has rescatado más bolsas de esporas; $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí! Has salvado más bolsas de esporas.$B$BEres diferente a los otros extraños. ¡Haré saber a mi pueblo acerca de tus hazañas!$B$B<Esta misión se puede repetir hasta alcanzar la reputación amistosa.>', 0),
(@ID, 'esMX', '¡Sí! Has salvado más bolsas de esporas.$B$BEres diferente a los otros extraños. ¡Haré saber a mi pueblo acerca de tus hazañas!$B$B<Esta misión se puede repetir hasta alcanzar la reputación amistosa.>', 0);
-- 9743 Enemigos naturales
-- https://es.wowhead.com/quest=9743
SET @ID := 9743;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la matanza de señores de la marisma? ¡Enséñales a esos brutos a no pisar territorio esporino!', 0),
(@ID, 'esMX', '¿Cómo va la matanza de señores de la marisma? ¡Enséñales a esos brutos a no pisar territorio esporino!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto vivo! ¡Le contaré a los demás esporinos tus hazañas! ¡$n, $gel:la; matagigantes!', 0),
(@ID, 'esMX', '¡Has vuelto vivo! ¡Le contaré a los demás esporinos tus hazañas! ¡$n, $gel:la; matagigantes!', 0);
-- 9744 ¡Más zarcillos!
-- https://es.wowhead.com/quest=9744
SET @ID := 9744;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has matado muchos gigantes, pero todavía quedan mucho. ¡Y están atacando nuestras bolsas de esporas!', 0),
(@ID, 'esMX', 'Has matado muchos gigantes, pero todavía quedan mucho. ¡Y están atacando nuestras bolsas de esporas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! Serían necesarios cientos de esporinos para abatir los gigantes que has abatido tú. ¡Me aseguraré de que todos conozcan tus hazañas!$B$B<Esta misión se puede repetir hasta alcanzar la reputación amistosa.>', 0),
(@ID, 'esMX', '¡Increíble! Serían necesarios cientos de esporinos para abatir los gigantes que has abatido tú. ¡Me aseguraré de que todos conozcan tus hazañas!$B$B<Esta misión se puede repetir hasta alcanzar la reputación amistosa.>', 0);
-- 9746 Los límites del agotamiento
-- https://es.wowhead.com/quest=9746
SET @ID := 9746;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Su líder no puede esconderse de nosotros para siempre. Eliminaremos sistemáticamente todos los posibles escondites hasta que encontremos a Sironas.', 0),
(@ID, 'esMX', 'Su líder no puede esconderse de nosotros para siempre. Eliminaremos sistemáticamente todos los posibles escondites hasta que encontremos a Sironas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto les enseñará y les hará pensárselo dos veces antes de intentar infiltrarse en nuestras filas de nuevo!', 0),
(@ID, 'esMX', '¡Esto les enseñará y les hará pensárselo dos veces antes de intentar infiltrarse en nuestras filas de nuevo!', 0);
-- 9747 La tribu Umbropantano
-- https://es.wowhead.com/quest=9747
SET @ID := 9747;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado; ¿Kataru y los esclavistas de Umbropantano están muertos?', 0),
(@ID, 'esMX', 'Has regresado; ¿Kataru y los esclavistas de Umbropantano están muertos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Por fin dormiré a gusto esta noche. Si no fuera tan viejo y débil, yo mismo me ocuparía de mis enemigos.$B$BAcepta este oro. No es gran cosa pero no puedo dejar de pagar por tu amabilidad.', 0),
(@ID, 'esMX', 'Gracias, $n. Por fin dormiré a gusto esta noche. Si no fuera tan viejo y débil, yo mismo me ocuparía de mis enemigos.$B$BAcepta este oro. No es gran cosa pero no puedo dejar de pagar por tu amabilidad.', 0);
-- 9749 ¡Viven! A lo mejor...
-- https://es.wowhead.com/quest=9749
SET @ID := 9749;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Investigador de expedición liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 9751 El legado de la Sangre Maldita
-- https://es.wowhead.com/quest=9751
SET @ID := 9751;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has oído hablar de la sangre maldita, $gmarinero:marinera; de agua dulce? No, por supuesto que no. La sangre maldita es lo que hundió a todos estos barcos. La parte estropeada y profanada del agua aquí se conoce como El Arrecife Sangre Maldita, una parte del mundo que nunca querrás visitar. Yo mismo he estado aquí durante 20 años.$B$B¿Escorbuto?... ¡mi pie! Morí en estas costas salvajes como alimento para los dragones... Ah, pero esa es otra historia para otro momento. Ahora mismo, tenemos que ayudar a las pobres almas que están atrapadas en ese arrecife.', 0),
(@ID, 'esMX', '¿Has oído hablar de la sangre maldita, $gmarinero:marinera; de agua dulce? No, por supuesto que no. La sangre maldita es lo que hundió a todos estos barcos. La parte estropeada y profanada del agua aquí se conoce como El Arrecife Sangre Maldita, una parte del mundo que nunca querrás visitar. Yo mismo he estado aquí durante 20 años.$B$B¿Escorbuto?... ¡mi pie! Morí en estas costas salvajes como alimento para los dragones... Ah, pero esa es otra historia para otro momento. Ahora mismo, tenemos que ayudar a las pobres almas que están atrapadas en ese arrecife.', 0);
-- 9752 Evasión de Umbropantano
-- https://es.wowhead.com/quest=9752
SET @ID := 9752;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Rescataste a uno de mis druidas; eso no tiene precio, $n.$B$BTienes mi gratitud y la de la expedición entera.', 0),
(@ID, 'esMX', 'Rescataste a uno de mis druidas; eso no tiene precio, $n.$B$BTienes mi gratitud y la de la expedición entera.', 0);
-- 9753 Saber es poder
-- https://es.wowhead.com/quest=9753
SET @ID := 9753;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito tu ayuda, $n. Tengo un plan para derribar al ejército Halcón del Sol, pero antes de ponerlo en marcha necesito cierta información vital.$B$BTenemos que determinar los puntos débiles de su primera defensa, pero, por desgracia, no hemos podido acercarnos lo suficiente a La Espiral Vectorial. Si pudiéramos hacer hablar al prisionero, tendríamos la información que necesitamos para romper su defensa y destruir La Espiral.$B$BHas oído bien: quiero hacerla saltar por los aires.', 0),
(@ID, 'esMX', 'Necesito tu ayuda, $n. Tengo un plan para derribar al ejército Halcón del Sol, pero antes de ponerlo en marcha necesito cierta información vital.$B$BTenemos que determinar los puntos débiles de su primera defensa, pero, por desgracia, no hemos podido acercarnos lo suficiente a La Espiral Vectorial. Si pudiéramos hacer hablar al prisionero, tendríamos la información que necesitamos para romper su defensa y destruir La Espiral.$B$BHas oído bien: quiero hacerla saltar por los aires.', 0);
-- 9756 Lo que no sabemos
-- https://es.wowhead.com/quest=9756
SET @ID := 9756;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Información del Halcón del Sol conseguida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Buen trabajo. ¿Estás $gdispuesto:dispuesta; a erradicar la amenaza de los elfos de sangre de esta isla de una vez por todas?', 0),
(@ID, 'esMX', 'Muy bien, $n. Buen trabajo. ¿Estás $gdispuesto:dispuesta; a erradicar la amenaza de los elfos de sangre de esta isla de una vez por todas?', 0);
-- 9757 La cazadora Kella Arconocturno
-- https://es.wowhead.com/quest=9757
SET @ID := 9757;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Comencemos nuestra lección de una vez!', 0),
(@ID, 'esMX', '¡Comencemos nuestra lección de una vez!', 0);
-- 9759 El fin de su mundo
-- https://es.wowhead.com/quest=9759
SET @ID := 9759;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has salvado Bruma de Sangre y Bruma Azur, asegurando que los draenei puedan seguir viviendo en paz en Azeroth, $n. Por todo lo que has hecho no hay agradecimientos ni recompensas bastantes que expresen lo que sentimos.$B$BAun así, todavía quedan muchos atrás, en Draenor, que no han podido estar aquí para presenciar este evento histórico. Tienes que encontrar la forma de volver. Vuelve a Terrallende, héroe de Argus. Trae a nuestro pueblo a casa. Al hogar que has salvado. A casa, a Azeroth...', 0),
(@ID, 'esMX', 'Has salvado Bruma de Sangre y Bruma Azur, asegurando que los draenei puedan seguir viviendo en paz en Azeroth, $n. Por todo lo que has hecho no hay agradecimientos ni recompensas bastantes que expresen lo que sentimos.$B$BAun así, todavía quedan muchos atrás, en Draenor, que no han podido estar aquí para presenciar este evento histórico. Tienes que encontrar la forma de volver. Vuelve a Terrallende, héroe de Argus. Trae a nuestro pueblo a casa. Al hogar que has salvado. A casa, a Azeroth...', 0);
-- 9760 El Reposo del Vindicador
-- https://es.wowhead.com/quest=9760
SET @ID := 9760;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Quizás seas tú quien va a llevar a mi gente a una nueva era de paz y prosperidad.', 0),
(@ID, 'esMX', 'Quizás seas tú quien va a llevar a mi gente a una nueva era de paz y prosperidad.', 0);
-- 9761 Despejando el camino
-- https://es.wowhead.com/quest=9761
SET @ID := 9761;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ves algún draenei inusualmente valiente y poderoso por aquí?', 0),
(@ID, 'esMX', '¿Ves algún draenei inusualmente valiente y poderoso por aquí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperemos que llegue un héroe antes de que puedan traer refuerzos para vigilar la zona que acabas de asegurar.', 0),
(@ID, 'esMX', 'Esperemos que llegue un héroe antes de que puedan traer refuerzos para vigilar la zona que acabas de asegurar.', 0);
-- 9762 La profecía no escrita
-- https://es.wowhead.com/quest=9762
SET @ID := 9762;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas islas serán el hogar de miles. La mayoría de esta gente permanecerá aquí toda su vida. Si lo deseases, tú podrías hacer lo mismo. Pero eso no es lo que quieres, ¿verdad, $n?$B$B<Velen asiente.>$B$BTodavía te quedan muchas cosas por hacer antes de fallecer. Debes abrazar tu destino y enfrentarte a él de cabeza.$B$BAntes de irte, quiero darte dos regalos: este tabardo solo lo llevan los más venerados de la Mano de Argus y este sello solo lo llevan nuestros mejores sabios. Llévalos con orgullo, $n.', 0),
(@ID, 'esMX', 'Estas islas serán el hogar de miles. La mayoría de esta gente permanecerá aquí toda su vida. Si lo deseases, tú podrías hacer lo mismo. Pero eso no es lo que quieres, ¿verdad, $n?$B$B<Velen asiente.>$B$BTodavía te quedan muchas cosas por hacer antes de fallecer. Debes abrazar tu destino y enfrentarte a él de cabeza.$B$BAntes de irte, quiero darte dos regalos: este tabardo solo lo llevan los más venerados de la Mano de Argus y este sello solo lo llevan nuestros mejores sabios. Llévalos con orgullo, $n.', 0);
-- 9763 La guarida del Señor de la Guerra
-- https://es.wowhead.com/quest=9763
SET @ID := 9763;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué hay de Kalithresh? ¿Ya está muerto, $n?', 0),
(@ID, 'esMX', '¿Qué hay de Kalithresh? ¿Ya está muerto, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestro mayor enemigo en la región finalmente está muerto. Le has hecho un gran favor a la expedición, $n.$B$BEstaremos en deuda contigo para siempre.', 0),
(@ID, 'esMX', 'Nuestro mayor enemigo en la región finalmente está muerto. Le has hecho un gran favor a la expedición, $n.$B$BEstaremos en deuda contigo para siempre.', 0);
-- 9764 Órdenes de Lady Vashj
-- https://es.wowhead.com/quest=9764
SET @ID := 9764;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí, $n?', 0),
(@ID, 'esMX', '¿Qué tienes ahí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vashj!$B$BEsto es mucho más de lo que esperábamos. Nuestras pequeñas victorias aquí y allá contra los naga no significan nada.$B$BSi Lady Vashj está involucrada en esto, entonces están trabajando fuerzas mucho más grandes que nosotros.$B$BHas hecho bien en traernos esto, $n. Ahora, debemos prepararnos para la guerra.', 0),
(@ID, 'esMX', '¡Vashj!$B$BEsto es mucho más de lo que esperábamos. Nuestras pequeñas victorias aquí y allá contra los naga no significan nada.$B$BSi Lady Vashj está involucrada en esto, entonces están trabajando fuerzas mucho más grandes que nosotros.$B$BHas hecho bien en traernos esto, $n. Ahora, debemos prepararnos para la guerra.', 0);
-- 9765 Preparativos de guerra
-- https://es.wowhead.com/quest=9765
SET @ID := 9765;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has obtenido el armamento que busco, $n?', 0),
(@ID, 'esMX', '¿Has obtenido el armamento que busco, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos funcionarán perfectamente, $n. Trae más armamento que encuentres. Nuestra necesidad es grande y nuestros recursos son escasos.', 0),
(@ID, 'esMX', 'Estos funcionarán perfectamente, $n. Trae más armamento que encuentres. Nuestra necesidad es grande y nuestros recursos son escasos.', 0);
-- 9766 Armamentos de Colmillo Torcido
-- https://es.wowhead.com/quest=9766
SET @ID := 9766;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Forjaremos el propio acero de los naga en armas que usaremos contra ellos. Tráeme todo el armamento que consigas rescatar de la Reserva Colmillo Torcido.', 0),
(@ID, 'esMX', 'Forjaremos el propio acero de los naga en armas que usaremos contra ellos. Tráeme todo el armamento que consigas rescatar de la Reserva Colmillo Torcido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Los naga aprenderán a no subestimarnos.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Los naga aprenderán a no subestimarnos.', 0);
-- 9769 Antes muertos que sencillos
-- https://es.wowhead.com/quest=9769
SET @ID := 9769;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso? Te han picado los bichos alados, ¿verdad?$B$B<Magasha se ríe entre dientes de su propio chiste.>', 0),
(@ID, 'esMX', '¿Qué es eso? Te han picado los bichos alados, ¿verdad?$B$B<Magasha se ríe entre dientes de su propio chiste.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son excelentes, $n. Aquí tienes tu pago.$B$B<Magasha dobla una de las alas y se la lleva a la cabeza.>$B$BNo, no es mi estilo, pero ¿quién soy yo para quejarme?$B$B<Magasha se encoge de hombros.>$B$BEl dinero habla.', 0),
(@ID, 'esMX', 'Son excelentes, $n. Aquí tienes tu pago.$B$B<Magasha dobla una de las alas y se la lleva a la cabeza.>$B$BNo, no es mi estilo, pero ¿quién soy yo para quejarme?$B$B<Magasha se encoge de hombros.>$B$BEl dinero habla.', 0);
-- 9770 La amenaza de los Colmillo de la Marisma
-- https://es.wowhead.com/quest=9770
SET @ID := 9770;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todavía veo Colmillos de la marisma, $n. Seguramente no podrás terminar tan pronto.', 0),
(@ID, 'esMX', 'Todavía veo Colmillos de la marisma, $n. Seguramente no podrás terminar tan pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya te has repuesto?$B$B<Reavij se ríe.>$B$BHay una razón por la que nuestros visitantes no se quedan mucho tiempo.$B$BSi pudiera elegir, buscaría una ubicación más agradable para la avanzada pero llevaré los Colmillos de la marisma al genio de Denjai cualquier día.', 0),
(@ID, 'esMX', '¿Ya te has repuesto?$B$B<Reavij se ríe.>$B$BHay una razón por la que nuestros visitantes no se quedan mucho tiempo.$B$BSi pudiera elegir, buscaría una ubicación más agradable para la avanzada pero llevaré los Colmillos de la marisma al genio de Denjai cualquier día.', 0);
-- 9771 En busca del explorador Jyoba
-- https://es.wowhead.com/quest=9771
SET @ID := 9771;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El maltrecho cadáver corresponde a la perfección con la descripción de Zurai. Fuera lo que fuera lo que lo matara, no esperaba el ataque porque su arma está envainada y el contenido de un pequeño tintero mancha el suelo a su lado.', 0),
(@ID, 'esMX', 'El maltrecho cadáver corresponde a la perfección con la descripción de Zurai. Fuera lo que fuera lo que lo matara, no esperaba el ataque porque su arma está envainada y el contenido de un pequeño tintero mancha el suelo a su lado.', 0);
-- 9772 El informe de Jyoba
-- https://es.wowhead.com/quest=9772
SET @ID := 9772;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto pero Jyoba no viene contigo. ¿Qué ha sido de él?', 0),
(@ID, 'esMX', 'Has vuelto pero Jyoba no viene contigo. ¿Qué ha sido de él?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Zurai toma el informe que le tiendes y le echa un vistazo.>$B$BYa conocíamos gran parte de esta información. Todo en esta zona parece estar seco o marchitándose, aunque aquí hay algo nuevo$B$BDice que los gigantes fúngicos parecen haber enloquecido debido a la falta de humedad. Por tu descripción, eso es lo que debió matarlo.$B$BDaré instrucciones a mis hombres de que eviten esa zona. No podemos permitirnos más bajas.', 0),
(@ID, 'esMX', '<Zurai toma el informe que le tiendes y le echa un vistazo.>$B$BYa conocíamos gran parte de esta información. Todo en esta zona parece estar seco o marchitándose, aunque aquí hay algo nuevo$B$BDice que los gigantes fúngicos parecen haber enloquecido debido a la falta de humedad. Por tu descripción, eso es lo que debió matarlo.$B$BDaré instrucciones a mis hombres de que eviten esa zona. No podemos permitirnos más bajas.', 0);
-- 9773 ¡Ya basta de champiñones!
-- https://es.wowhead.com/quest=9773
SET @ID := 9773;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dime que no has vuelto con las manos vacías, $n.', 0),
(@ID, 'esMX', 'Dime que no has vuelto con las manos vacías, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin un respiro de tanto champiñón! Si no olieras a pescado, te daría un abrazo.$B$BA ver cómo se ponen de celosos los demás cuando huelan lo que se está cociendo aquí.', 0),
(@ID, 'esMX', '¡Por fin un respiro de tanto champiñón! Si no olieras a pescado, te daría un abrazo.$B$BA ver cómo se ponen de celosos los demás cuando huelan lo que se está cociendo aquí.', 0);
-- 9774 Escama de hidra gruesa
-- https://es.wowhead.com/quest=9774
SET @ID := 9774;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo tu sonrisita. Sí, mi armadura tendrá una extraña pinta hasta que sustituya todo el metal viejo pero es mejor que ir sin protección.', 0),
(@ID, 'esMX', 'Veo tu sonrisita. Sí, mi armadura tendrá una extraña pinta hasta que sustituya todo el metal viejo pero es mejor que ir sin protección.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Toda ayuda, por pequeña que sea, se agradece.$B$BAún me queda mucho camino pero, a decir verdad, ¿qué otra cosa puedo hacer entre rondas?', 0),
(@ID, 'esMX', 'Gracias, $n. Toda ayuda, por pequeña que sea, se agradece.$B$BAún me queda mucho camino pero, a decir verdad, ¿qué otra cosa puedo hacer entre rondas?', 0);
-- 9775 Cazador de las Sombras Denjai
-- https://es.wowhead.com/quest=9775
SET @ID := 9775;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No pareces uno de mis hombres. Habla, $r.', 0),
(@ID, 'esMX', 'No pareces uno de mis hombres. Habla, $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué no dijiste que traes un informe de Zurai? Lo estaba esperando.$B$BLo envié allí para tener una presencia en la frontera este, no para que se tocara las narices. A ver qué dice el informe.', 0),
(@ID, 'esMX', '¿Por qué no dijiste que traes un informe de Zurai? Lo estaba esperando.$B$BLo envié allí para tener una presencia en la frontera este, no para que se tocara las narices. A ver qué dice el informe.', 0);
-- 9776 El Puerto Orebor
-- https://es.wowhead.com/quest=9776
SET @ID := 9776;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si el anacoreta Ahuurn te considera un amigo, quizás entonces puedo confiar en ti. Por favor, perdona tantas precauciones, $r, pero a menudo estas cosas son las que separan la vida de la muerte para mi pueblo. Te doy la bienvenida y, quizás, nazca entre nosotros un sentimiento de confianza mutua.', 0),
(@ID, 'esMX', 'Si el anacoreta Ahuurn te considera un amigo, quizás entonces puedo confiar en ti. Por favor, perdona tantas precauciones, $r, pero a menudo estas cosas son las que separan la vida de la muerte para mi pueblo. Te doy la bienvenida y, quizás, nazca entre nosotros un sentimiento de confianza mutua.', 0);
-- 9777 Esporas refulgentes
-- https://es.wowhead.com/quest=9777
SET @ID := 9777;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por el aspecto de todo, tendremos que reponer nuestras esporas pronto.', 0),
(@ID, 'esMX', 'Por el aspecto de todo, tendremos que reponer nuestras esporas pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas esporas son buenas y deberían servir para que sigamos adelante algún tiempo. Gracias por tu ayuda en reponer nuestros suministros, $n.', 0),
(@ID, 'esMX', 'Estas esporas son buenas y deberían servir para que sigamos adelante algún tiempo. Gracias por tu ayuda en reponer nuestros suministros, $n.', 0);
-- 9778 El celador Hamoot
-- https://es.wowhead.com/quest=9778
SET @ID := 9778;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ysiel te envió? ¡Claro que puedo sacarle partido a alguien como tú! Siempre necesitamos un par de brazos fuertes.', 0),
(@ID, 'esMX', '¿Ysiel te envió? ¡Claro que puedo sacarle partido a alguien como tú! Siempre necesitamos un par de brazos fuertes.', 0);
