-- 10613 El vil y la furia
-- https://es.wowhead.com/quest=10613
SET @ID := 10613;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Infernal Forja Muerta destruido', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto, así que asumiré que la operación salió bien. ¿Qué tienes que informar?', 0),
(@ID, 'esMX', 'Has vuelto, así que asumiré que la operación salió bien. ¿Qué tienes que informar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo admito, $n. Estoy impresionado por todo lo que has conseguido lograr. Destruir la capacidad de la Legión de hacer la guerra en Lunargenta nos dará la oportunidad de cambiar por completo la situación.', 0),
(@ID, 'esMX', 'Lo admito, $n. Estoy impresionado por todo lo que has conseguido lograr. Destruir la capacidad de la Legión de hacer la guerra en Lunargenta nos dará la oportunidad de cambiar por completo la situación.', 0);
-- 10614 Susurros en el viento
-- https://es.wowhead.com/quest=10614
SET @ID := 10614;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae a nuestra aldea?', 0),
(@ID, 'esMX', '¿Qué te trae a nuestra aldea?', 0);
-- 10615 La Foresta Ruuan
-- https://es.wowhead.com/quest=10615
SET @ID := 10615;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, Dertrok. Hablamos brevemente sobre los arakkoa. Debo decir que nuestros... intereses en ellos difieren bastante significativamente.', 0),
(@ID, 'esMX', 'Ah, sí, Dertrok. Hablamos brevemente sobre los arakkoa. Debo decir que nuestros... intereses en ellos difieren bastante significativamente.', 0);
-- 10617 Capullos de Alaseda
-- https://es.wowhead.com/quest=10617
SET @ID := 10617;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se necesita una mano rápida y firme para recoger. Espero que tengas éxito.', 0),
(@ID, 'esMX', 'Se necesita una mano rápida y firme para recoger. Espero que tengas éxito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son capullos de buena calidad. Veo que le has cogido el tranquillo a lo de recogerlos.$B$BHemos experimentado intentando criar a nuestras propias larvas de Alaseda, pero, por desgracia, los pequeños no producen la seda suficiente como para que nos sean útiles.', 0),
(@ID, 'esMX', 'Son capullos de buena calidad. Veo que le has cogido el tranquillo a lo de recogerlos.$B$BHemos experimentado intentando criar a nuestras propias larvas de Alaseda, pero, por desgracia, los pequeños no producen la seda suficiente como para que nos sean útiles.', 0);
-- 10618 Las alas más suaves
-- https://es.wowhead.com/quest=10618
SET @ID := 10618;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las alas son bastante delicadas, pero se pueden incrustar como elemento decorativo en muchos de nuestros diseños.', 0),
(@ID, 'esMX', 'Las alas son bastante delicadas, pero se pueden incrustar como elemento decorativo en muchos de nuestros diseños.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Las usaremos antes de lo que piensas.', 0),
(@ID, 'esMX', 'Gracias, $n. Las usaremos antes de lo que piensas.', 0);
-- 10619 La tribu Lengua de Ceniza
-- https://es.wowhead.com/quest=10619
SET @ID := 10619;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gloria a los naaru, $n. Has cumplido los deseos de la Luz al derrotar a los seguidores de Illidan.', 0),
(@ID, 'esMX', 'Gloria a los naaru, $n. Has cumplido los deseos de la Luz al derrotar a los seguidores de Illidan.', 0);
-- 10620 La amenaza de Crestaespina
-- https://es.wowhead.com/quest=10620
SET @ID := 10620;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Esas acechadorasya se han marchado? Algunas personas que se dirigían al norte han desaparecido.$B$BSi es por las acechadoras, quiero asegurarme de que no vuelva a ocurrir.', 0),
(@ID, 'esMX', '¿Esas acechadorasya se han marchado? Algunas personas que se dirigían al norte han desaparecido.$B$BSi es por las acechadoras, quiero asegurarme de que no vuelva a ocurrir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No está mal para $gun novato:una novata;. Resulta que tenemos un pequeño grupo de intelectuales que quieren ir a "observar" a los etéreos y su tecnología al norte. Estarán encantados de que les hayas despejado el camino.$B$BToma, llévate algunos de estos. No tenemos muchos, pero quizás te ayuden en el futuro.', 0),
(@ID, 'esMX', 'No está mal para $gun novato:una novata;. Resulta que tenemos un pequeño grupo de intelectuales que quieren ir a "observar" a los etéreos y su tecnología al norte. Estarán encantados de que les hayas despejado el camino.$B$BToma, llévate algunos de estos. No tenemos muchos, pero quizás te ayuden en el futuro.', 0);
-- 10621 El fragmento aterraillidari
-- https://es.wowhead.com/quest=10621
SET @ID := 10621;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Ordinn acepta el fragmento del arma.>$B$BHacía mucho tiempo que no veía nada parecido. Seguro que está hecho de un mineral extraño, pero este fragmento no está destinado a un arma normal y corriente, $n. Ha sido infundido con magia para destruir demonios. Si lo has conseguido de la Legión, debe de ser algún tipo de \'arma secreta\' que están planeando utilizar contra Illidan. ¡Menudo descubrimiento!', 0),
(@ID, 'esMX', '<Ordinn acepta el fragmento del arma.>$B$BHacía mucho tiempo que no veía nada parecido. Seguro que está hecho de un mineral extraño, pero este fragmento no está destinado a un arma normal y corriente, $n. Ha sido infundido con magia para destruir demonios. Si lo has conseguido de la Legión, debe de ser algún tipo de \'arma secreta\' que están planeando utilizar contra Illidan. ¡Menudo descubrimiento!', 0);
-- 10622 Prueba de lealtad
-- https://es.wowhead.com/quest=10622
SET @ID := 10622;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho lo que te pedí, $n? La lealtad no se encuentra fácilmente en estas tierras.', 0),
(@ID, 'esMX', '¿Has hecho lo que te pedí, $n? La lealtad no se encuentra fácilmente en estas tierras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Tu lealtad ya no se puede cuestionar. Ahora podrás ver a Akama.', 0),
(@ID, 'esMX', 'Muy bien, $n. Tu lealtad ya no se puede cuestionar. Ahora podrás ver a Akama.', 0);
-- 10623 El fragmento aterraillidari
-- https://es.wowhead.com/quest=10623
SET @ID := 10623;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Grokom acepta el fragmento del arma.>$B$BHacía mucho tiempo que no veía nada parecido. Seguro que está hecho de un mineral extraño, pero este fragmento no está destinado a un arma normal y corriente, $n.$B$BHa sido infundido con magia para dominar demonios. Esto demuestra cuánto odia la Legión a Illidan, si es que están dispuestos a armar a sus propias tropas con armas para la destrucción de demonios. Podría venirnos bien.', 0),
(@ID, 'esMX', '<Grokom acepta el fragmento del arma.>$B$BHacía mucho tiempo que no veía nada parecido. Seguro que está hecho de un mineral extraño, pero este fragmento no está destinado a un arma normal y corriente, $n.$B$BHa sido infundido con magia para dominar demonios. Esto demuestra cuánto odia la Legión a Illidan, si es que están dispuestos a armar a sus propias tropas con armas para la destrucción de demonios. Podría venirnos bien.', 0);
-- 10624 Una de fantasmas
-- https://es.wowhead.com/quest=10624
SET @ID := 10624;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿A qué te refieres? Voy a hacer algo con la ceniza, claro.', 0),
(@ID, 'esMX', '¿A qué te refieres? Voy a hacer algo con la ceniza, claro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu mundo está a punto de cambiar, $n.', 0),
(@ID, 'esMX', 'Tu mundo está a punto de cambiar, $n.', 0);
-- 10625 Espectróculos
-- https://es.wowhead.com/quest=10625
SET @ID := 10625;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si pierdes tus gafas, dímelo y te haré otro par.', 0),
(@ID, 'esMX', 'Si pierdes tus gafas, dímelo y te haré otro par.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sanguino? ¿T... Teron Sanguino? Pero... ¡¿Cómo?!$B$B¿Cómo es posible que Sanguino esté aquí? ¡Es imposible!$B$BLa leyenda de Teron Sanguino hace que hasta los Renegados se estremezcan de miedo. Todos coinciden en que Sanguino era un brujo de Gul\'dan, extremadamente poderoso por sí solo. Cuando Orgrim Martillo Maldito mató a Sanguino, Gul\'dan se llevó el alma del brujo caído y la colocó en el caparazón roto de un caballero asesinado de Ventormenta. Y así nació el primer caballero de la Muerte de la Horda.', 0),
(@ID, 'esMX', '¿Sanguino? ¿T... Teron Sanguino? Pero... ¡¿Cómo?!$B$B¿Cómo es posible que Sanguino esté aquí? ¡Es imposible!$B$BLa leyenda de Teron Sanguino hace que hasta los Renegados se estremezcan de miedo. Todos coinciden en que Sanguino era un brujo de Gul\'dan, extremadamente poderoso por sí solo. Cuando Orgrim Martillo Maldito mató a Sanguino, Gul\'dan se llevó el alma del brujo caído y la colocó en el caparazón roto de un caballero asesinado de Ventormenta. Y así nació el primer caballero de la Muerte de la Horda.', 0);
-- Tomar las armas
-- 10626, 10627
-- https://es.wowhead.com/quest=10626
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10626, 10627) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10626, 'esES', '¿Has conseguido los prototipos?', 0),
(10627, 'esES', '¿Has conseguido los prototipos?', 0),
(10626, 'esMX', '¿Has conseguido los prototipos?', 0),
(10627, 'esMX', '¿Has conseguido los prototipos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10626, 10627) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10626, 'esES', 'Esto debería irnos bien. Ahora, vamos a forjarlos para darles una forma más adecuada.', 0),
(10627, 'esES', 'Esto debería irnos bien. Ahora, vamos a forjarlos para darles una forma más adecuada.', 0),
(10626, 'esMX', 'Esto debería irnos bien. Ahora, vamos a forjarlos para darles una forma más adecuada.', 0),
(10627, 'esMX', 'Esto debería irnos bien. Ahora, vamos a forjarlos para darles una forma más adecuada.', 0);
-- 10628 Akama
-- https://es.wowhead.com/quest=10628
SET @ID := 10628;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. Tenemos muchas cosas de las que hablar.$B$BEspero que abras tu mente. Las decisiones que tengo que tomar no las pueden entender muchos. Solo mis colaboradores más cercanos pueden comprender los portentos que veo y las señales que espero.$B$BCuando uní mis fuerzas con Illidan fue basándome en visiones que predecían que, de no hacerlo, mi raza habría sido destruida. He esperado pacientemente recibir otras señales y visiones... el éxodo de Velen... la apertura del Portal Oscuro... y ahora, tu llegada.', 0),
(@ID, 'esMX', 'Hola, $n. Tenemos muchas cosas de las que hablar.$B$BEspero que abras tu mente. Las decisiones que tengo que tomar no las pueden entender muchos. Solo mis colaboradores más cercanos pueden comprender los portentos que veo y las señales que espero.$B$BCuando uní mis fuerzas con Illidan fue basándome en visiones que predecían que, de no hacerlo, mi raza habría sido destruida. He esperado pacientemente recibir otras señales y visiones... el éxodo de Velen... la apertura del Portal Oscuro... y ahora, tu llegada.', 0);
-- 10629 Un trabajo que te cagas
-- https://es.wowhead.com/quest=10629
SET @ID := 10629;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado encontrar mis llaves? Seguro que algún can manáfago se las comió. Probablemente el que envié contigo. Probablemente.', 0),
(@ID, 'esMX', '¿Has logrado encontrar mis llaves? Seguro que algún can manáfago se las comió. Probablemente el que envié contigo. Probablemente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apestas. ¡Pero has encontrado mis llaves! Muchísimas gracias. Ahora podré encender mi trituradora y ganar algo de dinero. Pronto tendré suficiente dinero para marcharme de Terrallende. No sé por qué te quedas, odio este lugar. ¿No preferirías volver a Bahía del Botín?$B$BNo sé, ¿dedicarte a la pesca?', 0),
(@ID, 'esMX', 'Apestas. ¡Pero has encontrado mis llaves! Muchísimas gracias. Ahora podré encender mi trituradora y ganar algo de dinero. Pronto tendré suficiente dinero para marcharme de Terrallende. No sé por qué te quedas, odio este lugar. ¿No preferirías volver a Bahía del Botín?$B$BNo sé, ¿dedicarte a la pesca?', 0);
-- 10630 El subsuelo de Thrallmar
-- https://es.wowhead.com/quest=10630
SET @ID := 10630;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya está muerto? Estoy demasiado asustado para mirar.', 0),
(@ID, 'esMX', '¿Ya está muerto? Estoy demasiado asustado para mirar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Seguro que esos Gan\'arg se largarán ahora. Estaré de vuelta en Bahía del Botín como mucho en una semana. Estoy impaciente por volver a pescar. Fue un error venir a Terrallende. Si de algo te vale mi consejo, volverás por donde viniste. Pasa una temporada en Tuercespina, o si acaso, si buscas un poco más de emoción, ve al Cráter de Un\'Goro. Todo menos quedarte aquí.', 0),
(@ID, 'esMX', 'Seguro que esos Gan\'arg se largarán ahora. Estaré de vuelta en Bahía del Botín como mucho en una semana. Estoy impaciente por volver a pescar. Fue un error venir a Terrallende. Si de algo te vale mi consejo, volverás por donde viniste. Pasa una temporada en Tuercespina, o si acaso, si buscas un poco más de emoción, ve al Cráter de Un\'Goro. Todo menos quedarte aquí.', 0);
-- 10632 Cortar tus dientes
-- https://es.wowhead.com/quest=10632
SET @ID := 10632;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tal va la recogida de dientes?$B$BSeguro que vas a hacer un buen trabajo. Mientras te encargas de todo, nosotros nos quedaremos aquí, en la avanzada.', 0),
(@ID, 'esMX', '¿Qué tal va la recogida de dientes?$B$BSeguro que vas a hacer un buen trabajo. Mientras te encargas de todo, nosotros nos quedaremos aquí, en la avanzada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $gchico:chica;. Todo el dolor merece la pena si la vida de al menos uno de mis soldados se salva con tus esfuerzos.$B$BCreo que deberías sacar algún provecho de tus lágrimas y tus sudores. Como pronto vamos a tener armas nuevas, ¿por qué no escoges una de las mías?', 0),
(@ID, 'esMX', 'Buen trabajo, $gchico:chica;. Todo el dolor merece la pena si la vida de al menos uno de mis soldados se salva con tus esfuerzos.$B$BCreo que deberías sacar algún provecho de tus lágrimas y tus sudores. Como pronto vamos a tener armas nuevas, ¿por qué no escoges una de las mías?', 0);
-- Teron Sanguino: Tradición y Leyenda
-- 10633, 10644
-- https://es.wowhead.com/quest=10633
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10633, 10644) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10633, 'esES', '¿Sanguino? ¡Hacía años que no oía hablar de él!$B$BDespués de la Segunda Guerra, Sanguino volvió aquí, con sus caballeros de la Muerte. Incapaz de soportar la terrible naturaleza de su nueva forma y sin el apoyo de su amado líder, Gul\'dan, Sanguino se suicidó.$B$BSi ahora su espíritu vaga por estas tierras, es la primera noticia que tengo. Aunque quizás consiga aclararlo con tu ayuda.', 0),
(10644, 'esES', '¿Sanguino? ¡Hacía años que no oía hablar de él!$B$BDespués de la Segunda Guerra, Sanguino volvió aquí, con sus caballeros de la Muerte. Incapaz de soportar la terrible naturaleza de su nueva forma y sin el apoyo de su amado líder, Gul\'dan, Sanguino se suicidó.$B$BSi ahora su espíritu vaga por estas tierras, es la primera noticia que tengo. Aunque quizás consiga aclararlo con tu ayuda.', 0),
(10633, 'esMX', '¿Sanguino? ¡Hacía años que no oía hablar de él!$B$BDespués de la Segunda Guerra, Sanguino volvió aquí, con sus caballeros de la Muerte. Incapaz de soportar la terrible naturaleza de su nueva forma y sin el apoyo de su amado líder, Gul\'dan, Sanguino se suicidó.$B$BSi ahora su espíritu vaga por estas tierras, es la primera noticia que tengo. Aunque quizás consiga aclararlo con tu ayuda.', 0),
(10644, 'esMX', '¿Sanguino? ¡Hacía años que no oía hablar de él!$B$BDespués de la Segunda Guerra, Sanguino volvió aquí, con sus caballeros de la Muerte. Incapaz de soportar la terrible naturaleza de su nueva forma y sin el apoyo de su amado líder, Gul\'dan, Sanguino se suicidó.$B$BSi ahora su espíritu vaga por estas tierras, es la primera noticia que tengo. Aunque quizás consiga aclararlo con tu ayuda.', 0);
-- 10634 Adivinación: la armadura de Sanguino
-- https://es.wowhead.com/quest=10634
SET @ID := 10634;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vuela al Arrecife del Ala Abisal para recuperar el objeto.', 0),
(@ID, 'esMX', 'Vuela al Arrecife del Ala Abisal para recuperar el objeto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo tener todas las piezas para poder adivinar el destino de Sanguino.', 0),
(@ID, 'esMX', 'Debo tener todas las piezas para poder adivinar el destino de Sanguino.', 0);
-- 10635 Adivinación: la capa de Sanguino
-- https://es.wowhead.com/quest=10635
SET @ID := 10635;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes usar los espectróculos si quieres ver a los espíritus de Sombraluna.', 0),
(@ID, 'esMX', 'Debes usar los espectróculos si quieres ver a los espíritus de Sombraluna.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tenga las tres piezas, podré adivinar la ubicación de Sanguino.', 0),
(@ID, 'esMX', 'Cuando tenga las tres piezas, podré adivinar la ubicación de Sanguino.', 0);
-- 10636 Adivinación: la clava de Sanguino
-- https://es.wowhead.com/quest=10636
SET @ID := 10636;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes usar los espectróculos si quieres ver a los espíritus de Sombraluna.', 0),
(@ID, 'esMX', 'Debes usar los espectróculos si quieres ver a los espíritus de Sombraluna.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo con los tres unidos podré adivinar los secretos que tan desesperadamente buscas.', 0),
(@ID, 'esMX', 'Solo con los tres unidos podré adivinar los secretos que tan desesperadamente buscas.', 0);
-- 10637 Una distracción necesaria
-- https://es.wowhead.com/quest=10637
SET @ID := 10637;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Azaloth liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te pedí?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperemos que esa distracción nos haya dado el tiempo que necesitamos para aprender todo lo que necesitamos del Patio de Armas de Karabor.', 0),
(@ID, 'esMX', 'Esperemos que esa distracción nos haya dado el tiempo que necesitamos para aprender todo lo que necesitamos del Patio de Armas de Karabor.', 0);
-- 10639 Yo, Teron Sanguino
-- https://es.wowhead.com/quest=10639
SET @ID := 10639;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que has hecho qué? ¡IMBÉCIL!$B$BTienes que solucionarlo. Después de todo, es por tu culpa. Coge uno de estos cascos. Cada uno de ellos tiene parte de las cenizas siempreardientes que sacaste de mí. Te permitirán ver a los fantasmas de Sombraluna, incluido a Teron Sanguino.$B$BSi alguna vez encuentras a Teron Sanguino, mátale.', 0),
(@ID, 'esMX', '¿Que has hecho qué? ¡IMBÉCIL!$B$BTienes que solucionarlo. Después de todo, es por tu culpa. Coge uno de estos cascos. Cada uno de ellos tiene parte de las cenizas siempreardientes que sacaste de mí. Te permitirán ver a los fantasmas de Sombraluna, incluido a Teron Sanguino.$B$BSi alguna vez encuentras a Teron Sanguino, mátale.', 0);
-- 10640 Altruis
-- https://es.wowhead.com/quest=10640
SET @ID := 10640;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has recorrido un largo camino, $gforastero:forastera;. Me sorprende que quienquiera que te enviara haya oído hablar de mí.', 0),
(@ID, 'esMX', 'Has recorrido un largo camino, $gforastero:forastera;. Me sorprende que quienquiera que te enviara haya oído hablar de mí.', 0);
-- 10641 Contra la Legión
-- https://es.wowhead.com/quest=10641
SET @ID := 10641;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a la diablesa?', 0),
(@ID, 'esMX', '¿Has matado a la diablesa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado que no te ha contaminado el toque de la Legión y que el enemigo de mi enemigo es mi amigo.', 0),
(@ID, 'esMX', 'Has demostrado que no te ha contaminado el toque de la Legión y que el enemigo de mi enemigo es mi amigo.', 0);
