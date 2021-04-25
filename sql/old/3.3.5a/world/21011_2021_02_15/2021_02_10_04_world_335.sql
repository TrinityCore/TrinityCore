-- 4742 El sello de ascensión
-- https://es.classic.wowhead.com/quest=4742
SET @ID := 4742;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Valor y paciencia por encima de todo, $n!', 0),
(@ID, 'esMX', '¡Valor y paciencia por encima de todo, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La imagen de Vaelan se vuelve borrosa por un momento.>$B$B<Las piezas que habías reunido han desaparecido.>$B$BEl Sello de ascensión sin forjar está listo. Ha llegado la hora de dar el último paso.', 0),
(@ID, 'esMX', '<La imagen de Vaelan se vuelve borrosa por un momento.>$B$B<Las piezas que habías reunido han desaparecido.>$B$BEl Sello de ascensión sin forjar está listo. Ha llegado la hora de dar el último paso.', 0);
-- 4743 El sello de ascensión
-- https://es.classic.wowhead.com/quest=4743
SET @ID := 4743;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No pierdas el tiempo, mortal. Nefarian trabaja febrilmente para liberar su mal sobre nuestro mundo.', 0),
(@ID, 'esMX', 'No pierdas el tiempo, mortal. Nefarian trabaja febrilmente para liberar su mal sobre nuestro mundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No te muevas mientras lanzo la evocación final de protección.$B$B<Los ojos de Vaelan se convierten en dos globos de fuego.>$B$BEl Sello de ascensión está completo…$B$BY recuerda, he imbuido el artefacto con potentes protectores. En las más oscuras horas, cuando todo parezca perdido, el poder del Vuelo Rojo estará a tu servicio.', 0),
(@ID, 'esMX', 'No te muevas mientras lanzo la evocación final de protección.$B$B<Los ojos de Vaelan se convierten en dos globos de fuego.>$B$BEl Sello de ascensión está completo…$B$BY recuerda, he imbuido el artefacto con potentes protectores. En las más oscuras horas, cuando todo parezca perdido, el poder del Vuelo Rojo estará a tu servicio.', 0);
-- 4764 El Broche de Equipasino
-- https://es.classic.wowhead.com/quest=4764
SET @ID := 4764;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el broche, $n? Mi cliente pagará una generosa suma por él.', 0),
(@ID, 'esMX', '¿Tienes el broche, $n? Mi cliente pagará una generosa suma por él.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo encontraste! ¡Así que los rumores eran ciertos!$B$BGracias, $n. Mi cliente, el conde Remington Bonacresta, estará más que contento al ver esta nueva obra en su colección.', 0),
(@ID, 'esMX', '¡Lo encontraste! ¡Así que los rumores eran ciertos!$B$BGracias, $n. Mi cliente, el conde Remington Bonacresta, estará más que contento al ver esta nueva obra en su colección.', 0);
-- 4765 Entrega a Bonacresta
-- https://es.classic.wowhead.com/quest=4765
SET @ID := 4765;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me dijeron que vendría un mensajero. Alguien con un regalo de la Cumbre de Roca Negra.$B$B¿Eres tú?', 0),
(@ID, 'esMX', 'Me dijeron que vendría un mensajero. Alguien con un regalo de la Cumbre de Roca Negra.$B$B¿Eres tú?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¡así que eres tú! Recibe mi agradecimiento, $n. Y... por si no lo supieras ya... el agradecimiento de un noble Bonacresta bien vale el rescate de un rey.', 0),
(@ID, 'esMX', 'Ah, ¡así que eres tú! Recibe mi agradecimiento, $n. Y... por si no lo supieras ya... el agradecimiento de un noble Bonacresta bien vale el rescate de un rey.', 0);
-- 4766 Mayara Alasol
-- https://es.classic.wowhead.com/quest=4766
SET @ID := 4766;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes de Ventormenta? Maravilloso: conozco un objeto de arte que Remington mataría por tener en su museo, pero extraerlo no será fácil.$B$BAhí es donde entras tú.', 0),
(@ID, 'esMX', '¿Vienes de Ventormenta? Maravilloso: conozco un objeto de arte que Remington mataría por tener en su museo, pero extraerlo no será fácil.$B$BAhí es donde entras tú.', 0);
-- 4767 Jinete del viento
-- https://es.classic.wowhead.com/quest=4767
SET @ID := 4767;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has traído los huevos de dracoleón que necesito? ¡Estoy deseando comenzar con mi instrucción como jinete del Viento!', 0),
(@ID, 'esMX', '$n, ¿has traído los huevos de dracoleón que necesito? ¡Estoy deseando comenzar con mi instrucción como jinete del Viento!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Perfecto! Con estos huevos espero poder dar el siguiente paso para convertirme en un jinete del viento. Aquí tienes una muestra de mi agradecimiento; que la buena caza siempre te acompañe, $c.', 0),
(@ID, 'esMX', '¡Perfecto! Con estos huevos espero poder dar el siguiente paso para convertirme en un jinete del viento. Aquí tienes una muestra de mi agradecimiento; que la buena caza siempre te acompañe, $c.', 0);
-- 4768 La tablilla de Rocanegra
-- https://es.classic.wowhead.com/quest=4768
SET @ID := 4768;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la tablilla, $n? ¡Cómo anhelo ahondar en sus secretos!', 0),
(@ID, 'esMX', '¿Has encontrado la tablilla, $n? ¡Cómo anhelo ahondar en sus secretos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fantástico. Llevará días investigar las fórmulas grabadas en esta tablilla pero confío en que esta investigación dará sus frutos.$B$BGracias, $n. Has sido una ayuda inestimable para nosotros.', 0),
(@ID, 'esMX', 'Fantástico. Llevará días investigar las fórmulas grabadas en esta tablilla pero confío en que esta investigación dará sus frutos.$B$BGracias, $n. Has sido una ayuda inestimable para nosotros.', 0);
-- 4769 Vivian Lagrave y la tablilla de Rocanegra
-- https://es.classic.wowhead.com/quest=4769
SET @ID := 4769;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es verdad. Creo que hay una tablilla dentro de la cumbre de Roca Negra, una tablilla que contiene antiguas recetas alquímicas. Me alegro de que esté aquí, porque necesito ayuda para recuperar la tablilla.$B$BPonte $gcómodo:cómoda; y te explicaré más.', 0),
(@ID, 'esMX', 'Es verdad. Creo que hay una tablilla dentro de la cumbre de Roca Negra, una tablilla que contiene antiguas recetas alquímicas. Me alegro de que esté aquí, porque necesito ayuda para recuperar la tablilla.$B$BPonte $gcómodo:cómoda; y te explicaré más.', 0);
-- 4770 De vuelta a casa
-- https://es.classic.wowhead.com/quest=4770
SET @ID := 4770;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué? Si supiera que Pao\'ka Velocimontés iba a husmear por Nido Alto, ¡lo habría encadenado a un tótem! Su padre se mostró reacio a dejarle venir conmigo a Las Mil Agujas. Vinimos a estudiar las diferentes criaturas que habitan en este lugar maravilloso.$B$BTe agradezco la ayuda que le has prestado a Pao\'ka. Espero que esto compense los infortunios que hayas podido sufrir.', 0),
(@ID, 'esMX', '¿Qué? Si supiera que Pao\'ka Velocimontés iba a husmear por Nido Alto, ¡lo habría encadenado a un tótem! Su padre se mostró reacio a dejarle venir conmigo a Las Mil Agujas. Vinimos a estudiar las diferentes criaturas que habitan en este lugar maravilloso.$B$BTe agradezco la ayuda que le has prestado a Pao\'ka. Espero que esto compense los infortunios que hayas podido sufrir.', 0);
-- 4771 Gambito del Alba
-- https://es.classic.wowhead.com/quest=4771
SET @ID := 4771;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda, $n, ¡debemos ser tolerantes pero rígidos en nuestras creencias!', 0),
(@ID, 'esMX', 'Recuerda, $n, ¡debemos ser tolerantes pero rígidos en nuestras creencias!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo hiciste! ¡Vectus está derrotado! Y el Gambito del Alba... ¿funcionó?$B$BHmm... tal vez mi dispositivo no fue el éxito que esperaba, pero me alegro de que pudieras manejar las cosas de todos modos. ¡Bien hecho, $n!$B$BEl Alba Argenta y la buena gente de Azeroth están en deuda contigo.', 0),
(@ID, 'esMX', '¡Lo hiciste! ¡Vectus está derrotado! Y el Gambito del Alba... ¿funcionó?$B$BHmm... tal vez mi dispositivo no fue el éxito que esperaba, pero me alegro de que pudieras manejar las cosas de todos modos. ¡Bien hecho, $n!$B$BEl Alba Argenta y la buena gente de Azeroth están en deuda contigo.', 0);
-- 4781 Los componentes para la toga de sangre dorada encantada
-- https://es.classic.wowhead.com/quest=4781
SET @ID := 4781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lingotes de oro, sí... sí. Tráeme uno y veremos qué puedo hacer para hilarte una bobina. Hasta entonces, te sugeriría que centraras tus esfuerzos en conseguir más poder. Las pruebas más duras están por venir. Y créeme... desearás estar más $gpreparado:preparada;, por muy $gpoderoso:poderosa; que llegues a ser.', 0),
(@ID, 'esMX', 'Lingotes de oro, sí... sí. Tráeme uno y veremos qué puedo hacer para hilarte una bobina. Hasta entonces, te sugeriría que centraras tus esfuerzos en conseguir más poder. Las pruebas más duras están por venir. Y créeme... desearás estar más $gpreparado:preparada;, por muy $gpoderoso:poderosa; que llegues a ser.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perfecto, $n. Me alegra que pudieras encontrar a un minero que te ayudara tan rápidamente. ¿O lo has hecho todo tú? Sea como fuere, has hecho un buen trabajo. Esto será perfecto para el hilo.$B$BLlevará algún tiempo crearlo todo, así que tendrás que volver, de hecho se lo envío a una princesa a la que tenemos encerrada en una torre y cuyo único trabajo es hilar hilo de oro... no, en serio. Lo que yo te diga... bueno, en realidad no.', 0),
(@ID, 'esMX', 'Perfecto, $n. Me alegra que pudieras encontrar a un minero que te ayudara tan rápidamente. ¿O lo has hecho todo tú? Sea como fuere, has hecho un buen trabajo. Esto será perfecto para el hilo.$B$BLlevará algún tiempo crearlo todo, así que tendrás que volver, de hecho se lo envío a una princesa a la que tenemos encerrada en una torre y cuyo único trabajo es hilar hilo de oro... no, en serio. Lo que yo te diga... bueno, en realidad no.', 0);
-- 4782 Los componentes para la toga de sangre dorada encantada
-- https://es.classic.wowhead.com/quest=4782
SET @ID := 4782;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, has vuelto, $n. ¿Y dónde está el hilo?$B$BAh, entiendo. Eso es aceptable. El goblin y su hermano no nos han fallado todavía, supongo que es comprensible que no lo tuviera preparado entonces. Bueno, sea... tenemos otras cosas a las que dedicarnos mientras tanto.$B$B¿Estás $gpreparado:preparada; para el paso siguiente?', 0),
(@ID, 'esMX', 'Bien, has vuelto, $n. ¿Y dónde está el hilo?$B$BAh, entiendo. Eso es aceptable. El goblin y su hermano no nos han fallado todavía, supongo que es comprensible que no lo tuviera preparado entonces. Bueno, sea... tenemos otras cosas a las que dedicarnos mientras tanto.$B$B¿Estás $gpreparado:preparada; para el paso siguiente?', 0);
-- 4783 Los componentes para la toga de sangre dorada encantada
-- https://es.classic.wowhead.com/quest=4783
SET @ID := 4783;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Desolace no es una región acogedora: nagas, gigantes, sátiros, la Legión Ardiente... todos ellos y los centauros en guerra la convierten en una tierra peligrosa si no extremas la precaución.$B$BComo he dicho antes, no solo pondrá a prueba tu fuerza y astucia, sino también tu paciencia. Ten mucho cuidado en esas tierras, $n.', 0),
(@ID, 'esMX', 'Desolace no es una región acogedora: nagas, gigantes, sátiros, la Legión Ardiente... todos ellos y los centauros en guerra la convierten en una tierra peligrosa si no extremas la precaución.$B$BComo he dicho antes, no solo pondrá a prueba tu fuerza y astucia, sino también tu paciencia. Ten mucho cuidado en esas tierras, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fantástico, $n. Estos restos nos servirán. Los prepararé ahora mientras tú sigues con los 2 últimos componentes. ¿Estás $glisto:lista;?', 0),
(@ID, 'esMX', 'Fantástico, $n. Estos restos nos servirán. Los prepararé ahora mientras tú sigues con los 2 últimos componentes. ¿Estás $glisto:lista;?', 0);
-- 4784 Los componentes para la toga de sangre dorada encantada
-- https://es.classic.wowhead.com/quest=4784
SET @ID := 4784;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto, $n, te lo prometo. La túnica será más adecuada para tus necesidades y desde luego te dará algo de ventaja sobre tus oponentes.', 0),
(@ID, 'esMX', 'Pronto, $n, te lo prometo. La túnica será más adecuada para tus necesidades y desde luego te dará algo de ventaja sobre tus oponentes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico, $n! Tenemos todos los componentes y estamos $glisto:listas;.$B$BConfío en que te agradará el resultado.', 0),
(@ID, 'esMX', '¡Fantástico, $n! Tenemos todos los componentes y estamos $glisto:listas;.$B$BConfío en que te agradará el resultado.', 0);
-- 4786 Toga terminada
-- https://es.classic.wowhead.com/quest=4786
SET @ID := 4786;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un momento, $n...', 0),
(@ID, 'esMX', 'Un momento, $n...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya está, $n. Aquí tienes. Llévala con orgullo.$B$BHas trabajado duro y veo grandes acontecimientos en tu futuro. Recuerda, para resistir a la corrupción que acompaña nuestro camino hay que tener mucha determinación y fortaleza. Siempre que domines tu voluntad, conocerás grandes éxitos.', 0),
(@ID, 'esMX', 'Ya está, $n. Aquí tienes. Llévala con orgullo.$B$BHas trabajado duro y veo grandes acontecimientos en tu futuro. Recuerda, para resistir a la corrupción que acompaña nuestro camino hay que tener mucha determinación y fortaleza. Siempre que domines tu voluntad, conocerás grandes éxitos.', 0);
-- 4788 Las últimas tablillas
-- https://es.classic.wowhead.com/quest=4788
SET @ID := 4788;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en la torre, $n? ¿Tienes la quinta y sexta tablillas?', 0),
(@ID, 'esMX', '¿Has estado en la torre, $n? ¿Tienes la quinta y sexta tablillas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¡Las encontraste! ¡Realmente eres $gun héroe:una heroína;, $n!$B$BEso es bueno, porque he estado leyendo las tablillas que me trajiste antes, y por lo que reuní... vamos a necesitar $gun héroe:una heroína; para detener lo que viene...', 0),
(@ID, 'esMX', '¡Increíble! ¡Las encontraste! ¡Realmente eres $gun héroe:una heroína;, $n!$B$BEso es bueno, porque he estado leyendo las tablillas que me trajiste antes, y por lo que reuní... vamos a necesitar $gun héroe:una heroína; para detener lo que viene...', 0);
-- 4808 Felnok Acerovera
-- https://es.classic.wowhead.com/quest=4808
SET @ID := 4808;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hace frío aquí arriba! ¡Espero que me hayas traído una manta!', 0),
(@ID, 'esMX', '¡Hace frío aquí arriba! ¡Espero que me hayas traído una manta!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso no es una manta! ¿Pero qué traes ahí? ¿Una carta de Tinkee? Me pregunto qué tendrá que contarme…$B$BAh, está realizando una investigación en Las Estepas Ardientes. Tiene sentido, es un sitio ideal para los dragonantes. ¡Oh, pero mira! Dice que necesita unas piezas para un dispositivo que le gustaría construir. Supongo que por eso has venido a buscarme, ¿no?', 0),
(@ID, 'esMX', '¡Eso no es una manta! ¿Pero qué traes ahí? ¿Una carta de Tinkee? Me pregunto qué tendrá que contarme…$B$BAh, está realizando una investigación en Las Estepas Ardientes. Tiene sentido, es un sitio ideal para los dragonantes. ¡Oh, pero mira! Dice que necesita unas piezas para un dispositivo que le gustaría construir. Supongo que por eso has venido a buscarme, ¿no?', 0);
-- 4809 Cuernos de Orvallo
-- https://es.classic.wowhead.com/quest=4809
SET @ID := 4809;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los cuernos de quimera Orvallo, $n?', 0),
(@ID, 'esMX', '¿Tienes los cuernos de quimera Orvallo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Son buenos ejemplares. ¡Vienen en frío! Me pongo unos guantes y te los empaqueto con el resto de cosas que Tinkee necesita...', 0),
(@ID, 'esMX', 'Son buenos ejemplares. ¡Vienen en frío! Me pongo unos guantes y te los empaqueto con el resto de cosas que Tinkee necesita...', 0);
-- 4810 Regresa junto a Tinkee
-- https://es.classic.wowhead.com/quest=4810
SET @ID := 4810;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! ¿Has hablado con Felnok? ¿Me has traído los componentes que necesito?', 0),
(@ID, 'esMX', '¡$n! ¿Has hablado con Felnok? ¿Me has traído los componentes que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los has traído! ¡Fantástico! ¡Enseguida me pongo a trabajar! ¡Un millón de gracias, $n!$B$BMe has ayudado tanto, podría necesitarte para otras tareas aún más importantes más adelante...', 0),
(@ID, 'esMX', '¡Los has traído! ¡Fantástico! ¡Enseguida me pongo a trabajar! ¡Un millón de gracias, $n!$B$BMe has ayudado tanto, podría necesitarte para otras tareas aún más importantes más adelante...', 0);
-- 4821 Un huevo extraño
-- https://es.classic.wowhead.com/quest=4821
SET @ID := 4821;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo que averiguar todo lo que pueda sobre este misterioso huevo. ¡Quién sabe lo que saldrá de su interior!', 0),
(@ID, 'esMX', 'Tengo que averiguar todo lo que pueda sobre este misterioso huevo. ¡Quién sabe lo que saldrá de su interior!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, por fin he conseguido el huevo extraño. Ahora, déjame que lo vea bien... Pero... ¿qué es esto?', 0),
(@ID, 'esMX', 'Bueno, por fin he conseguido el huevo extraño. Ahora, déjame que lo vea bien... Pero... ¿qué es esto?', 0);
-- 4822 ¡Quiero un heladooooo!
-- https://es.classic.wowhead.com/quest=4822
SET @ID := 4822;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Desearía que hicieran más sabores de helado además de fresa, ¡pero creo que tengo suerte de que el de fresa sea mi favorito!', 0),
(@ID, 'esMX', 'Desearía que hicieran más sabores de helado además de fresa, ¡pero creo que tengo suerte de que el de fresa sea mi favorito!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mmmmmmmmm! ¡Me encanta el helado de fresa! Si hay algo que Tigule y Foror saben hacer, ¡es hacer helado!$B$BMuchas gracias $n. ¡Este es el mejor regalo de todos!', 0),
(@ID, 'esMX', 'Mmmmmmmmm! ¡Me encanta el helado de fresa! Si hay algo que Tigule y Foror saben hacer, ¡es hacer helado!$B$BMuchas gracias $n. ¡Este es el mejor regalo de todos!', 0);
-- 4841 Apaciguar al centauro
-- https://es.classic.wowhead.com/quest=4841
SET @ID := 4841;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ven $n, sé que no has matado a los centauros. Hazlo y te daré una buena recompensa en agradecimiento.', 0),
(@ID, 'esMX', 'Ven $n, sé que no has matado a los centauros. Hazlo y te daré una buena recompensa en agradecimiento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es para ti, $n, como muestra de mi gratitud.', 0),
(@ID, 'esMX', 'Esto es para ti, $n, como muestra de mi gratitud.', 0);
-- 4862 Bestia amaestrada
-- https://es.classic.wowhead.com/quest=4862
SET @ID := 4862;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Llevas los huevos de araña en la bolsa o es que te alegras de verme?', 0),
(@ID, 'esMX', '¿Llevas los huevos de araña en la bolsa o es que te alegras de verme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué cargamento! Vamos, ¡pero fíjate en todos esos huevos! Por ellos deberíamos conseguir unas cuantas piezas de oro.$B$BComo te prometí, aquí tienes tu propio bicho. ¡Ojo, que muerde!', 0),
(@ID, 'esMX', '¡Qué cargamento! Vamos, ¡pero fíjate en todos esos huevos! Por ellos deberíamos conseguir unas cuantas piezas de oro.$B$BComo te prometí, aquí tienes tu propio bicho. ¡Ojo, que muerde!', 0);
-- 4865 Venganza
-- https://es.classic.wowhead.com/quest=4865
SET @ID := 4865;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Venganza! Así que la leyenda de Arikara es cierta... Está claro que hay que solucionar este problema de inmediato.', 0),
(@ID, 'esMX', '¡Venganza! Así que la leyenda de Arikara es cierta... Está claro que hay que solucionar este problema de inmediato.', 0);
-- 4866 La leche de la madre
-- https://es.classic.wowhead.com/quest=4866
SET @ID := 4866;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<John Andrajoso te pellizca.>', 0),
(@ID, 'esMX', '<John Andrajoso te pellizca.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta va a ser la mejor cerveza hasta ahora!$B$BEh, ¿para qué pensaste que iba a usar esto? Veneno o algo?$B$BNiños locos...', 0),
(@ID, 'esMX', '¡Esta va a ser la mejor cerveza hasta ahora!$B$BEh, ¿para qué pensaste que iba a usar esto? Veneno o algo?$B$BNiños locos...', 0);
-- 4867 Urok Aullasino
-- https://es.classic.wowhead.com/quest=4867
SET @ID := 4867;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! ¿Tienes mi mojo?', 0),
(@ID, 'esMX', '¡Ah! ¿Tienes mi mojo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! Ya siento cómo vuelven mis poderes. Y mi mente ya no sufre el atroz dolor de la maldición de Urok.$B$B¡Gracias, $n! Estoy por encima de la humildad pero debo reconocer tu ayuda.$B$BY te deseo que la Fortuna te acompañe en tus viajes por la Cumbre de Roca Negra. Eres $gun necio:una necia; si crees que vas a alcanzar la cumbre pero tu valor es incuestionable.', 0),
(@ID, 'esMX', '¡Eso es! Ya siento cómo vuelven mis poderes. Y mi mente ya no sufre el atroz dolor de la maldición de Urok.$B$B¡Gracias, $n! Estoy por encima de la humildad pero debo reconocer tu ayuda.$B$BY te deseo que la Fortuna te acompañe en tus viajes por la Cumbre de Roca Negra. Eres $gun necio:una necia; si crees que vas a alcanzar la cumbre pero tu valor es incuestionable.', 0);
-- 4881 Complot de asesinato
-- https://es.classic.wowhead.com/quest=4881
SET @ID := 4881;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienen a matarme? ¡Yo les enseñaré cómo pelea un tauren!', 0),
(@ID, 'esMX', '¿Vienen a matarme? ¡Yo les enseñaré cómo pelea un tauren!', 0);
-- 4882 Guardar un secreto
-- https://es.classic.wowhead.com/quest=4882
SET @ID := 4882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿$gListo:Lista; para otra misión?', 0),
(@ID, 'esMX', '¿$gListo:Lista; para otra misión?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Algún descubrimiento importante?', 0),
(@ID, 'esMX', '¿Algún descubrimiento importante?', 0);
-- 4883 Guardar un secreto
-- https://es.classic.wowhead.com/quest=4883
SET @ID := 4883;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿En qué puedo ayudarte, $n?', 0),
(@ID, 'esMX', '¿En qué puedo ayudarte, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La energía de este collar, $n... creo que solo tiene una fuente.$B$B<Nara cierra los ojos y se queda en silencio por un momento.> $B$BHubo un día en el que los lechúcicos salvajes, ahora confundidos y desorientados, eran completamente distintos. Tenían un objetivo, y estaban dedicados a servirlo. La diosa de los elfos de la noche, Elune, creó a esas criaturas para guardar sus zonas más sagradas.$B$BAunque pueda parecer un hecho insignificante, te insto a mirar con más detenimiento.$B$BLlegado el momento sabrás reconocer su importancia. Gracias por traerme esto $n.', 0),
(@ID, 'esMX', 'La energía de este collar, $n... creo que solo tiene una fuente.$B$B<Nara cierra los ojos y se queda en silencio por un momento.> $B$BHubo un día en el que los lechúcicos salvajes, ahora confundidos y desorientados, eran completamente distintos. Tenían un objetivo, y estaban dedicados a servirlo. La diosa de los elfos de la noche, Elune, creó a esas criaturas para guardar sus zonas más sagradas.$B$BAunque pueda parecer un hecho insignificante, te insto a mirar con más detenimiento.$B$BLlegado el momento sabrás reconocer su importancia. Gracias por traerme esto $n.', 0);
-- 4903 La orden del Señor de la Guerra
-- https://es.classic.wowhead.com/quest=4903
SET @ID := 4903;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El señor de la guerra Dientegore saluda.>', 0),
(@ID, 'esMX', '<El señor de la guerra Dientegore saluda.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<La verdosa piel del señor de la guerra Dientegore se torna blanquecina por un momento.>', 0),
(@ID, 'esMX', '<La verdosa piel del señor de la guerra Dientegore se torna blanquecina por un momento.>', 0);
-- 4904 Al fin libre
-- https://es.classic.wowhead.com/quest=4904
SET @ID := 4904;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Thalia Ocultaámbar:', 0),
(@ID, 'esMX', 'Thalia Ocultaámbar:', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. En el fondo sabía que se las arreglaría para volver a mi lado. Me habló de tu valentía y me explicó cómo le ayudaste a escapar. Estos objetos pertenecían a su hermano y sé que a ella le hubiera gustado que tú los tuvieses.', 0),
(@ID, 'esMX', 'Gracias, $n. En el fondo sabía que se las arreglaría para volver a mi lado. Me habló de tu valentía y me explicó cómo le ayudaste a escapar. Estos objetos pertenecían a su hermano y sé que a ella le hubiera gustado que tú los tuvieses.', 0);
-- 4907 Tinkee Vaporio
-- https://es.classic.wowhead.com/quest=4907
SET @ID := 4907;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Felnok tenía razón! Necesito tu ayuda de nuevo, y esta vez... va a ser realmente peligroso.$B$B¿¿Estás $glisto:lista;??', 0),
(@ID, 'esMX', '¡Felnok tenía razón! Necesito tu ayuda de nuevo, y esta vez... va a ser realmente peligroso.$B$B¿¿Estás $glisto:lista;??', 0);
-- 4921 Perdida en la batalla
-- https://es.classic.wowhead.com/quest=4921
SET @ID := 4921;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Encuentra a la esposa de Mankrik', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado alguna señal de ella? El dolor en mi pecho me dice que ha pasado lo peor, pero espero que la encuentres sana y salva.', 0),
(@ID, 'esMX', '¿Has encontrado alguna señal de ella? El dolor en mi pecho me dice que ha pasado lo peor, pero espero que la encuentres sana y salva.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo entiendo. Gracias, $c.', 0),
(@ID, 'esMX', 'Lo entiendo. Gracias, $c.', 0);
-- 4941 La sabiduría de Eitrigg
-- https://es.classic.wowhead.com/quest=4941
SET @ID := 4941;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No ves que no se me debe interrumpir?', 0),
(@ID, 'esMX', '¿No ves que no se me debe interrumpir?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thrall parece consternado por la noticia que le traes.>', 0),
(@ID, 'esMX', '<Thrall parece consternado por la noticia que le traes.>', 0);
-- 4961 La purificación del orbe de Orahil
-- https://es.classic.wowhead.com/quest=4961
SET @ID := 4961;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tendrás que matar a ese demonio para eliminar su presencia permanentemente del orbe, $n.', 0),
(@ID, 'esMX', 'Tendrás que matar a ese demonio para eliminar su presencia permanentemente del orbe, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bravo, $n! Le has dado a ese demonio una lección que tardará en olvidar. Has demostrado gran fortaleza y habilidad. Supongo que es hora de que vuelvas con Menara con tu orbe limpio para poder utilizarlo en algo bueno.$B$BSuerte, $c. Quizás nuestros caminos vuelvan a cruzarse.', 0),
(@ID, 'esMX', '¡Bravo, $n! Le has dado a ese demonio una lección que tardará en olvidar. Has demostrado gran fortaleza y habilidad. Supongo que es hora de que vuelvas con Menara con tu orbe limpio para poder utilizarlo en algo bueno.$B$BSuerte, $c. Quizás nuestros caminos vuelvan a cruzarse.', 0);
