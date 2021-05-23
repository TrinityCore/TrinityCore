-- 9848 Secretos de los Dagapantano
-- https://es.wowhead.com/quest=9848
SET @ID := 9848;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has buscado en la Aldea Dagapantano la información que necesito para llegar al fondo de este rompecabezas venenoso?', 0),
(@ID, 'esMX', '¿Has buscado en la Aldea Dagapantano la información que necesito para llegar al fondo de este rompecabezas venenoso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Timothy ojea el manual.>$B$B¿Están usando velada como base para el veneno? No, no puede ser cierto. La velada no tiene propiedades tóxicas.$B$BIncluir velada en un veneno es como un pícaro con dos mazas. Sí, se puede hacer, ¡pero no sirve de nada! No logro comprenderlo...$B$B<Timothy se aclara la garganta.>$B$BEn fin, gracias por traerme esto. Probaré el veneno en cuanto tenga tiempo.', 0),
(@ID, 'esMX', '<Timothy ojea el manual.>$B$B¿Están usando velada como base para el veneno? No, no puede ser cierto. La velada no tiene propiedades tóxicas.$B$BIncluir velada en un veneno es como un pícaro con dos mazas. Sí, se puede hacer, ¡pero no sirve de nada! No logro comprenderlo...$B$B<Timothy se aclara la garganta.>$B$BEn fin, gracias por traerme esto. Probaré el veneno en cuanto tenga tiempo.', 0);
-- 9849 Rompiendo el velo
-- https://es.wowhead.com/quest=9849
SET @ID := 9849;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gordawg quiere que le devuelvan la roca.', 0),
(@ID, 'esMX', 'Gordawg quiere que le devuelvan la roca.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡GUROK! ¡Gurok traicionó a los elementos!', 0),
(@ID, 'esMX', '¡GUROK! ¡Gurok traicionó a los elementos!', 0);
-- 9850 Cacería de uñagrietas
-- https://es.wowhead.com/quest=9850
SET @ID := 9850;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Crees que los Uñagrieta dominante van a caer muertos a tus pies aquí, frente a la fogata?', 0),
(@ID, 'esMX', '¿Crees que los Uñagrieta dominante van a caer muertos a tus pies aquí, frente a la fogata?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante. Muy impresionante.$B$BTienes potencial, $gchico:chica;. Ahora voy a darte la oportunidad de divertirte de verdad...', 0),
(@ID, 'esMX', 'Impresionante. Muy impresionante.$B$BTienes potencial, $gchico:chica;. Ahora voy a darte la oportunidad de divertirte de verdad...', 0);
-- 9851 Cacería de uñagrietas
-- https://es.wowhead.com/quest=9851
SET @ID := 9851;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un fuego cálido y $guna mujer:un hombre; a tu lado para conversar es algo que puedes conseguir en casa. Aquí apostamos fuerte, o morimos en el intento.', 0),
(@ID, 'esMX', 'Un fuego cálido y $guna mujer:un hombre; a tu lado para conversar es algo que puedes conseguir en casa. Aquí apostamos fuerte, o morimos en el intento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! ¡Has derrotado a Banthar! Nunca dudé de ti, $n.$B$BToma, creo que te has ganado esto.', 0),
(@ID, 'esMX', '¡Lo has conseguido! ¡Has derrotado a Banthar! Nunca dudé de ti, $n.$B$BToma, creo que te has ganado esto.', 0);
-- 9852 El deporte sangriento definitivo
-- https://es.wowhead.com/quest=9852
SET @ID := 9852;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tienes que sentir vergüenza por admitir que no tienes el coraje suficiente para cazar al animal más poderoso de esta tierra, $n.', 0),
(@ID, 'esMX', 'No tienes que sentir vergüenza por admitir que no tienes el coraje suficiente para cazar al animal más poderoso de esta tierra, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! Llenas de gozo el corazón de este viejo enano.$B$BAhora has demostrado tu valía. ¡Has pasado a formar parte de los rangos de élite! Otros huyeron aterrorizados, o murieron atrapados bajo la bestia. Pero tú has usado tu cabeza, tu astucia y tu determinación y has demostrado tu maestría.$B$BAcepta esto. Quiero que sepas que siempre serás $gbienvenido:bienvenida; si quieres cazar a mi lado.', 0),
(@ID, 'esMX', '¡$n! Llenas de gozo el corazón de este viejo enano.$B$BAhora has demostrado tu valía. ¡Has pasado a formar parte de los rangos de élite! Otros huyeron aterrorizados, o murieron atrapados bajo la bestia. Pero tú has usado tu cabeza, tu astucia y tu determinación y has demostrado tu maestría.$B$BAcepta esto. Quiero que sepas que siempre serás $gbienvenido:bienvenida; si quieres cazar a mi lado.', 0);
-- 9853 Gurok el Usurpador
-- https://es.wowhead.com/quest=9853
SET @ID := 9853;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gordawg comer el poder Gurok.', 0),
(@ID, 'esMX', 'Gordawg comer el poder Gurok.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Gordawg masca firmemente la cabeza terránea de Gurok y casi pulveriza la formación de piedra.>$B$BEl reinado de Gurok ha llegado a su fin. Los elementos terráneos son libres. Ahora todos duermen. ¡El campeón se lleva la recompensa!', 0),
(@ID, 'esMX', '<Gordawg masca firmemente la cabeza terránea de Gurok y casi pulveriza la formación de piedra.>$B$BEl reinado de Gurok ha llegado a su fin. Los elementos terráneos son libres. Ahora todos duermen. ¡El campeón se lleva la recompensa!', 0);
-- 9854 Cacería de vientorrocs
-- https://es.wowhead.com/quest=9854
SET @ID := 9854;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha llegado a conocer la paz que conlleva conocer su lugar en la naturaleza? ¿Eres $gel cazador:la cazadora; o la presa?', 0),
(@ID, 'esMX', '¿Ha llegado a conocer la paz que conlleva conocer su lugar en la naturaleza? ¿Eres $gel cazador:la cazadora; o la presa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cada día es un regalo. Aprovéchalo al máximo. Mañana recorreremos las llanuras con más determinación aún que hoy. Extenderemos nuestros brazos más lejos e intentaremos conseguir lo que hoy solo podemos soñar, aunque ese sueño intente eludirnos.', 0),
(@ID, 'esMX', 'Cada día es un regalo. Aprovéchalo al máximo. Mañana recorreremos las llanuras con más determinación aún que hoy. Extenderemos nuestros brazos más lejos e intentaremos conseguir lo que hoy solo podemos soñar, aunque ese sueño intente eludirnos.', 0);
-- 9855 Cacería de vientorrocs
-- https://es.wowhead.com/quest=9855
SET @ID := 9855;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has aprendido a calmar los latidos de tu corazón? ¿Estar tan $gquieto:quieta; y paciente como un lago en calma, esperando el momento adecuado para derribar a tu presa?', 0),
(@ID, 'esMX', '¿Has aprendido a calmar los latidos de tu corazón? ¿Estar tan $gquieto:quieta; y paciente como un lago en calma, esperando el momento adecuado para derribar a tu presa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has vuelto a demostrar tu habilidad, $c. Ahora debes seguir y acechar al más feroz de los vientorrocs.', 0),
(@ID, 'esMX', 'Has vuelto a demostrar tu habilidad, $c. Ahora debes seguir y acechar al más feroz de los vientorrocs.', 0);
-- 9856 Cacería de vientorrocs
-- https://es.wowhead.com/quest=9856
SET @ID := 9856;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya te has enfrentado a Arrancatripas?', 0),
(@ID, 'esMX', '¿Ya te has enfrentado a Arrancatripas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El ojo aún parece vivo. ¿Tú crees que aún puede mirar en tu alma?$B$B$n, ahora puedes considerarte miembro de la élite de los cazadores de safari. Y estás un poco más cerca de perseguir a la presa más legendaria de este lugar: Eburnia.$B$BTe has ganado el derecho a tener esto. Espero que te sea útil.', 0),
(@ID, 'esMX', 'El ojo aún parece vivo. ¿Tú crees que aún puede mirar en tu alma?$B$B$n, ahora puedes considerarte miembro de la élite de los cazadores de safari. Y estás un poco más cerca de perseguir a la presa más legendaria de este lugar: Eburnia.$B$BTe has ganado el derecho a tener esto. Espero que te sea útil.', 0);
-- 9857 Cacería de talbuks
-- https://es.wowhead.com/quest=9857
SET @ID := 9857;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me quedaré aquí un poco más de tiempo. Debería estar bien pronto.', 0),
(@ID, 'esMX', 'Me quedaré aquí un poco más de tiempo. Debería estar bien pronto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una bonita historia... <tose>... la de cómo conseguiste a esos venados, $c. Pero creo que lo puedes hacer mejor. Tengo algo más en mente para ti.', 0),
(@ID, 'esMX', 'Una bonita historia... <tose>... la de cómo conseguiste a esos venados, $c. Pero creo que lo puedes hacer mejor. Tengo algo más en mente para ti.', 0);
-- 9858 Cacería de talbuks
-- https://es.wowhead.com/quest=9858
SET @ID := 9858;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que... <tose>... ¿ya te has ocupado de esos... <tose>... raspaespinas?', 0),
(@ID, 'esMX', 'Supongo que... <tose>... ¿ya te has ocupado de esos... <tose>... raspaespinas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<tose>, <tose>... ¡$n! Lo has conseguido. Solo queda...... una cosa... <tose>... más.', 0),
(@ID, 'esMX', '<tose>, <tose>... ¡$n! Lo has conseguido. Solo queda...... una cosa... <tose>... más.', 0);
-- 9859 Cacería de talbuks
-- https://es.wowhead.com/quest=9859
SET @ID := 9859;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Harold te mira débilmente, pero consigue esbozar una sonrisa.>$B$B¿Tienes la...<tose>... pezuña?', 0),
(@ID, 'esMX', '<Harold te mira débilmente, pero consigue esbozar una sonrisa.>$B$B¿Tienes la...<tose>... pezuña?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau! ¡Lo has conseguido! ¡Es la pezuña de Bach\'lor!$B$BMmm, parece que me estoy encontrando bastante mejor. Toma, deja que te dé algo para celebrar tu gran talento como $gcazador:cazadora;.', 0),
(@ID, 'esMX', '¡Guau! ¡Lo has conseguido! ¡Es la pezuña de Bach\'lor!$B$BMmm, parece que me estoy encontrando bastante mejor. Toma, deja que te dé algo para celebrar tu gran talento como $gcazador:cazadora;.', 0);
-- 9860 La nueva directiva
-- https://es.wowhead.com/quest=9860
SET @ID := 9860;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Alturus me contó todo lo que pasó, $n. Sin embargo, este no es el final. Con Karazhan sellada a los forasteros, es solo cuestión de tiempo hasta que la Legión renueve sus ataques mientras nosotros permanecemos impotentes al margen.$B$BA menos que aceptes la responsabilidad que el destino te ha otorgado, claro está.$B$B<Cedric extiende una palma abierta hacia ti, sosteniendo una insignia con el símbolo del Ojo Violeta en ella.>$B$B¿Qué dices, $n?', 0),
(@ID, 'esMX', 'Alturus me contó todo lo que pasó, $n. Sin embargo, este no es el final. Con Karazhan sellada a los forasteros, es solo cuestión de tiempo hasta que la Legión renueve sus ataques mientras nosotros permanecemos impotentes al margen.$B$BA menos que aceptes la responsabilidad que el destino te ha otorgado, claro está.$B$B<Cedric extiende una palma abierta hacia ti, sosteniendo una insignia con el símbolo del Ojo Violeta en ella.>$B$B¿Qué dices, $n?', 0);
-- 9861 El viento aullador
-- https://es.wowhead.com/quest=9861
SET @ID := 9861;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Dámelo, rápido!', 0),
(@ID, 'esMX', '¡Dámelo, rápido!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una llamada de socorro, $r. Una fuerza externa está intentando subvertir a los elementos.', 0),
(@ID, 'esMX', 'Es una llamada de socorro, $r. Una fuerza externa está intentando subvertir a los elementos.', 0);
-- 9862 Corruptores Sangreoscura
-- https://es.wowhead.com/quest=9862
SET @ID := 9862;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El espíritu del aire afirma que los Sangreoscura están buscando algo en Primasol...', 0),
(@ID, 'esMX', 'El espíritu del aire afirma que los Sangreoscura están buscando algo en Primasol...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que los viste controlar a los elementos y el viento se plegó a su voluntad?$B$B<Morgh se queda pensativo.>$B$BEsto es preocupante, $n. Tengo que consultar con mis colegas.$B$BGracias por todo, $n. Quizás deberías volver a tu poblado, a ver si averiguas algo más sobre los Sangreoscura y sus viles objetivos.', 0),
(@ID, 'esMX', '¿Que los viste controlar a los elementos y el viento se plegó a su voluntad?$B$B<Morgh se queda pensativo.>$B$BEsto es preocupante, $n. Tengo que consultar con mis colegas.$B$BGracias por todo, $n. Quizás deberías volver a tu poblado, a ver si averiguas algo más sobre los Sangreoscura y sus viles objetivos.', 0);
-- 9863 Idolatría vil
-- https://es.wowhead.com/quest=9863
SET @ID := 9863;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz esto por nosotros, porque nosotros no podemos.', 0),
(@ID, 'esMX', 'Haz esto por nosotros, porque nosotros no podemos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has dado esperanza a los Hijos del Rayo, $n. Si nuestro líder no nos protege, quizás haya otros capaces de hacerlo... como tú.', 0),
(@ID, 'esMX', 'Has dado esperanza a los Hijos del Rayo, $n. Si nuestro líder no nos protege, quizás haya otros capaces de hacerlo... como tú.', 0);
-- 9864 El destacamento de guerra desaparecido
-- https://es.wowhead.com/quest=9864
SET @ID := 9864;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me han contado historias sobre mi pueblo. Dicen que antiguamente eran guerreros...', 0),
(@ID, 'esMX', 'Me han contado historias sobre mi pueblo. Dicen que antiguamente eran guerreros...', 0);
-- 9865 Su nombre era Venganza
-- https://es.wowhead.com/quest=9865
SET @ID := 9865;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por cada uno de mis parientes que mataron, diez de ellos deben morir!', 0),
(@ID, 'esMX', '¡Por cada uno de mis parientes que mataron, diez de ellos deben morir!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Colmillosauro se gira hacia ti.>$B$B¿Es sangre eso que huelo? Siento no haber podido ayudar, pero me embarga la emoción solo de pensar en lo que has hecho.$B$B¿Hay más $ghéroes:heroínas; como tú en el lugar del que procedes?', 0),
(@ID, 'esMX', '<Colmillosauro se gira hacia ti.>$B$B¿Es sangre eso que huelo? Siento no haber podido ayudar, pero me embarga la emoción solo de pensar en lo que has hecho.$B$B¿Hay más $ghéroes:heroínas; como tú en el lugar del que procedes?', 0);
-- 9866 Recorrerá la tierra...
-- https://es.wowhead.com/quest=9866
SET @ID := 9866;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El clarividente Corhuk se queda meditando y luego afirma con la cabeza.>$B$B<Se enjuga una lágrima.>$B$BEl hijo es el padre... Que los espíritus se apiaden de aquellos que se le enfrenten.', 0),
(@ID, 'esMX', '<El clarividente Corhuk se queda meditando y luego afirma con la cabeza.>$B$B<Se enjuga una lágrima.>$B$BEl hijo es el padre... Que los espíritus se apiaden de aquellos que se le enfrenten.', 0);
-- 9867 Los jefes Sangreoscura
-- https://es.wowhead.com/quest=9867
SET @ID := 9867;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tráeme la cabeza de su jefe, $n.', 0),
(@ID, 'esMX', 'Tráeme la cabeza de su jefe, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He aquí el rostro del enemigo... Pondré la cabeza en una pica a las afueras de Garadar, cerca de las puertas. Así, si se les ocurre atacarnos de nuevo, verán cara a cara las consecuencias de sus actos.', 0),
(@ID, 'esMX', 'He aquí el rostro del enemigo... Pondré la cabeza en una pica a las afueras de Garadar, cerca de las puertas. Así, si se les ocurre atacarnos de nuevo, verán cara a cara las consecuencias de sus actos.', 0);
-- 9868 El tótem de Kar'dash
-- https://es.wowhead.com/quest=9868
SET @ID := 9868;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Garrosh apenas reconoce tu presencia. Parece profundamente deprimido.>', 0),
(@ID, 'esMX', '<Garrosh apenas reconoce tu presencia. Parece profundamente deprimido.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que importa? La abuela se está muriendo. La vida no vale la pena vivirla...', 0),
(@ID, 'esMX', '¿Que importa? La abuela se está muriendo. La vida no vale la pena vivirla...', 0);
-- El Trono de los Elementos
-- 9869, 9870
-- https://es.wowhead.com/quest=9869
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9869, 9870) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9869, 'esES', 'Ah, gracias por el mensaje. ¿Quizás puedas ayudar al Anillo de la Tierra? Los elementos están en estado de cambio. Necesitamos toda la ayuda que podamos conseguir.', 0),
(9870, 'esES', 'Ah, gracias por el mensaje. ¿Quizás puedas ayudar al Anillo de la Tierra? Los elementos están en estado de cambio. Necesitamos toda la ayuda que podamos conseguir.', 0),
(9869, 'esMX', 'Ah, gracias por el mensaje. ¿Quizás puedas ayudar al Anillo de la Tierra? Los elementos están en estado de cambio. Necesitamos toda la ayuda que podamos conseguir.', 0),
(9870, 'esMX', 'Ah, gracias por el mensaje. ¿Quizás puedas ayudar al Anillo de la Tierra? Los elementos están en estado de cambio. Necesitamos toda la ayuda que podamos conseguir.', 0);
-- 9871 Invasores Sangreoscura
-- https://es.wowhead.com/quest=9871
SET @ID := 9871;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso?', 0),
(@ID, 'esMX', '¿Qué es eso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Arechron se golpea la palma con el puño.>$B$BOrtur... ¡Ttraidor del demonio!', 0),
(@ID, 'esMX', '<Arechron se golpea la palma con el puño.>$B$BOrtur... ¡Ttraidor del demonio!', 0);
-- 9872 Invasores Sangreoscura
-- https://es.wowhead.com/quest=9872
SET @ID := 9872;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso?', 0),
(@ID, 'esMX', '¿Qué es eso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Garrosh hace una bola estrujando el mapa y lo tira al fuego.>$B$B¿De qué sirve? Llevan semanas atacándonos. Esto no es una novedad.$B$B¿No lo entiendes? Estamos acabados... la Abuela Geyah se está muriendo.', 0),
(@ID, 'esMX', '<Garrosh hace una bola estrujando el mapa y lo tira al fuego.>$B$B¿De qué sirve? Llevan semanas atacándonos. Esto no es una novedad.$B$B¿No lo entiendes? Estamos acabados... la Abuela Geyah se está muriendo.', 0);
-- 9873 Mi viejo amigo Ortur
-- https://es.wowhead.com/quest=9873
SET @ID := 9873;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda, $n, Ortor es un chamán de gran poder.', 0),
(@ID, 'esMX', 'Recuerda, $n, Ortor es un chamán de gran poder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que han muerto cerca de mil orcos? ¿Qué puede haber provocado tan audaz avance en tierras orcas? Es buena cosa que haya muerto, pero aquí hay tentáculo encerrado.', 0),
(@ID, 'esMX', '¿Dices que han muerto cerca de mil orcos? ¿Qué puede haber provocado tan audaz avance en tierras orcas? Es buena cosa que haya muerto, pero aquí hay tentáculo encerrado.', 0);
-- 9874 Deteniendo la propagación
-- https://es.wowhead.com/quest=9874
SET @ID := 9874;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cadáver de habitante de Primasol quemado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los orcos no comprenderán lo que estamos haciendo, pero hay que hacerlo. Tanto por el bien de los Tábidos como por el de los orcos.', 0),
(@ID, 'esMX', 'Los orcos no comprenderán lo que estamos haciendo, pero hay que hacerlo. Tanto por el bien de los Tábidos como por el de los orcos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Otonbu suspira.>$B$BEsto retrasará cualquier oportunidad de paz con los orcos como mínimo otros 10 años. Al menos sobreviviremos otros diez años para verlo con nuestros propios ojos, al contrario de si hubiésemos permitido que los cadáveres se pudriesen.', 0),
(@ID, 'esMX', '<Otonbu suspira.>$B$BEsto retrasará cualquier oportunidad de paz con los orcos como mínimo otros 10 años. Al menos sobreviviremos otros diez años para verlo con nuestros propios ojos, al contrario de si hubiésemos permitido que los cadáveres se pudriesen.', 0);
-- 9875 Especie sin catalogar
-- https://es.wowhead.com/quest=9875
SET @ID := 9875;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que enseñarme?', 0),
(@ID, 'esMX', '¿Tienes algo que enseñarme?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una nueva especie! ¿Estás $gseguro:segura;?$B$B<Lauranna ojea hojas de notas y diagramas.>$B$BBuen trabajo, $n. Tendremos que añadirla a la lista. ¿Qué tal te suena "$nlium púrpura alado"? A mí me gusta.', 0),
(@ID, 'esMX', '¡Una nueva especie! ¿Estás $gseguro:segura;?$B$B<Lauranna ojea hojas de notas y diagramas.>$B$BBuen trabajo, $n. Tendremos que añadirla a la lista. ¿Qué tal te suena "$nlium púrpura alado"? A mí me gusta.', 0);
-- 9876 Incursión fallida
-- https://es.wowhead.com/quest=9876
SET @ID := 9876;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias a Cenarius que apareciste. Mis lesiones me impidieron volver al exterior en busca de ayuda.', 0),
(@ID, 'esMX', 'Gracias a Cenarius que apareciste. Mis lesiones me impidieron volver al exterior en busca de ayuda.', 0);
-- 9877 Una pócima reconstituyente
-- https://es.wowhead.com/quest=9877
SET @ID := 9877;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Janeda te envía a rescatar a los prisioneros de la Ciudad de la Muerte? Ella debe pensar muy bien de ti, $n.', 0),
(@ID, 'esMX', '¿Janeda te envía a rescatar a los prisioneros de la Ciudad de la Muerte? Ella debe pensar muy bien de ti, $n.', 0);
-- 9878 Resolviendo el problema
-- https://es.wowhead.com/quest=9878
SET @ID := 9878;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Sangreoscura son una tribu infame, $n. Pueden parecerse a Kurenai, pero seguramente son bestias salvajes y asesinas.', 0),
(@ID, 'esMX', 'Los Sangreoscura son una tribu infame, $n. Pueden parecerse a Kurenai, pero seguramente son bestias salvajes y asesinas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dudo que los orcos comprendan o aprecien lo que acabas de hacer, pero te aseguro que Nagrand estará mucho mejor. Gracias por resolver nuestro problema...', 0),
(@ID, 'esMX', 'Dudo que los orcos comprendan o aprecien lo que acabas de hacer, pero te aseguro que Nagrand estará mucho mejor. Gracias por resolver nuestro problema...', 0);
-- 9879 El tótem de Kar'dash
-- https://es.wowhead.com/quest=9879
SET @ID := 9879;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, he oído hablar del tótem... pero hay algo más en esta historia. Me apena decirte que carezco de la autoridad necesaria para revelarte esa información. Solo se puede decir al elegido.', 0),
(@ID, 'esMX', 'Sí, he oído hablar del tótem... pero hay algo más en esta historia. Me apena decirte que carezco de la autoridad necesaria para revelarte esa información. Solo se puede decir al elegido.', 0);
-- 9882 Robar a los ladrones
-- https://es.wowhead.com/quest=9882
SET @ID := 9882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los trozos de cristal que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has conseguido los trozos de cristal que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante. Están en buenas condiciones en su mayoría.$B$BMe aseguraré de hablar bien de ti con los nuestros.', 0),
(@ID, 'esMX', 'Impresionante. Están en buenas condiciones en su mayoría.$B$BMe aseguraré de hablar bien de ti con los nuestros.', 0);
-- 9883 Más trozos de cristal
-- https://es.wowhead.com/quest=9883
SET @ID := 9883;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes más fragmentos de cristal? Asegúrate de no llevar ninguno que todavía esté adherido a la montaña; no quisiéramos crear problemas con los naaru.', 0),
(@ID, 'esMX', '¿Tienes más fragmentos de cristal? Asegúrate de no llevar ninguno que todavía esté adherido a la montaña; no quisiéramos crear problemas con los naaru.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue viniendo con fragmentos de cristal, $n. No podemos permitir que estos ladrones se apoderen de nuestra propiedad.$B$BIncluso si todavía no es nuestro. Un tecnicismo, por supuesto.', 0),
(@ID, 'esMX', 'Sigue viniendo con fragmentos de cristal, $n. No podemos permitir que estos ladrones se apoderen de nuestra propiedad.$B$BIncluso si todavía no es nuestro. Un tecnicismo, por supuesto.', 0);
-- Beneficios de los miembros
-- 9884, 9885, 9886, 9887
-- https://es.wowhead.com/quest=9884
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9884, 9885, 9886, 9887) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9884, 'esES', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0),
(9885, 'esES', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0),
(9886, 'esES', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0),
(9887, 'esES', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0),
(9884, 'esMX', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0),
(9885, 'esMX', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0),
(9886, 'esMX', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0),
(9887, 'esMX', 'El Consorcio es conocido por cuidar bien a sus amigos. Al comienzo de cada mes tendré algunas gemas listas para ti como pago por tus servicios.$B$BLa calidad de las gemas que obtengas dependerá de cuán leal nos hayas sido. Espero que seas $glisto:lista; y te quedes con nosotros.', 0);
-- 9888 El líder impotente
-- https://es.wowhead.com/quest=9888
SET @ID := 9888;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kilrath habla en susurros.>$B$BEsos ogros son extremadamente peculiares. También, extremadamente estúpidos. Mira cómo el gordo ese hace que los, mmm, menos gordos bailen. Es hipnotizador.', 0),
(@ID, 'esMX', '<Kilrath habla en susurros.>$B$BEsos ogros son extremadamente peculiares. También, extremadamente estúpidos. Mira cómo el gordo ese hace que los, mmm, menos gordos bailen. Es hipnotizador.', 0);
-- 9889 No mates al gordo
-- https://es.wowhead.com/quest=9889
SET @ID := 9889;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Envío! ¡Envío!', 0),
(@ID, 'esMX', '¡Envío! ¡Envío!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame vivir y te diré lo que quieras saber.', 0),
(@ID, 'esMX', 'Déjame vivir y te diré lo que quieras saber.', 0);
