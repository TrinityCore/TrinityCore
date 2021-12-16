-- 5981 Gigantes arrasadores
-- https://es.classic.wowhead.com/quest=5981
SET @ID := 5981;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes seguir demostrando tu valía, $n.', 0),
(@ID, 'esMX', 'Debes seguir demostrando tu valía, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. Tu determinación ha sido debidamente anotada.', 0),
(@ID, 'esMX', 'Excelente, $n. Tu determinación ha sido debidamente anotada.', 0);
-- 6001 Cuerpo y corazón
-- https://es.classic.wowhead.com/quest=6001
SET @ID := 6001;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin has dado ese gran paso, $n, te has adentrado en un mundo mucho más grande. Percibo en ti las enseñanzas del espíritu del gran oso y percibo que has recibido la fuerza que poseía Garraluna.$B$BYa no hay obstáculos en tu camino... ¡Deja que te enseñe lo que significa ser un $c de la Zarpa!', 0),
(@ID, 'esMX', 'Por fin has dado ese gran paso, $n, te has adentrado en un mundo mucho más grande. Percibo en ti las enseñanzas del espíritu del gran oso y percibo que has recibido la fuerza que poseía Garraluna.$B$BYa no hay obstáculos en tu camino... ¡Deja que te enseñe lo que significa ser un $c de la Zarpa!', 0);
-- 6004 Negocios inconclusos
-- https://es.classic.wowhead.com/quest=6004
SET @ID := 6004;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te va, $n? ¿Son más fuertes de lo que pensabas? Espero que no. Si voy a seguir adelante aquí, entonces se requerirá mucha más fuerza de la que ya te he pedido que hagas.', 0),
(@ID, 'esMX', '¿Cómo te va, $n? ¿Son más fuertes de lo que pensabas? Espero que no. Si voy a seguir adelante aquí, entonces se requerirá mucha más fuerza de la que ya te he pedido que hagas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Estoy asombrada de que acabaras con ellos tan rápidamente. Gracias.$B$BTodavía tengo que encontrar a alguien que esté de acuerdo con la Cruzada Escarlata y con sus métodos. Creo en la Luz tanto como cualquier otro en Ventormenta, pero han demostrado que solo quieren matar a todo el que no sea leal a su movimiento... incluidos los inocentes.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Estoy asombrada de que acabaras con ellos tan rápidamente. Gracias.$B$BTodavía tengo que encontrar a alguien que esté de acuerdo con la Cruzada Escarlata y con sus métodos. Creo en la Luz tanto como cualquier otro en Ventormenta, pero han demostrado que solo quieren matar a todo el que no sea leal a su movimiento... incluidos los inocentes.', 0);
-- 6022 Matar con un propósito
-- https://es.classic.wowhead.com/quest=6022
SET @ID := 6022;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estás llorando? Si esto te resulta demasiado tedioso, "$ghéroe:heroína;", te aconsejo que vayas a buscar a la Dama Oscura y le llores a ella. Cuéntale cómo te he maltratado.$B$B¡Y ahora fuera de mi vista!', 0),
(@ID, 'esMX', '¿Estás llorando? Si esto te resulta demasiado tedioso, "$ghéroe:heroína;", te aconsejo que vayas a buscar a la Dama Oscura y le llores a ella. Cuéntale cómo te he maltratado.$B$B¡Y ahora fuera de mi vista!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Decepcionante. Esperaba tener que usarte a ti para alimentar a mis canes.$B$B<Nathanos suspira.>$B$BBueno, al menos tienen algo que comer.', 0),
(@ID, 'esMX', 'Decepcionante. Esperaba tener que usarte a ti para alimentar a mis canes.$B$B<Nathanos suspira.>$B$BBueno, al menos tienen algo que comer.', 0);
-- 6023 Negocios inconclusos
-- https://es.classic.wowhead.com/quest=6023
SET @ID := 6023;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya los has encontrado, $n? Con los dos eliminados, puedo infiltrarme en Vega del Amparo para ver más de cerca su configuración. No puedo hacerlo sin tu ayuda. Por favor, busca a Radley y Durgen por mí.', 0),
(@ID, 'esMX', '¿Ya los has encontrado, $n? Con los dos eliminados, puedo infiltrarme en Vega del Amparo para ver más de cerca su configuración. No puedo hacerlo sin tu ayuda. Por favor, busca a Radley y Durgen por mí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Has sido de mucha más ayuda de lo que había esperado. El aire de este lugar parece ahogar mi voluntad. Estoy cansada y puedo asegurarte que no me recuperaré mientras siga aquí.$B$BNo estoy segura de cómo lograré infiltrarme en la Vega del Amparo para informar sobre la fuerza de la Cruzada Escarlata en el lugar.$B$BPero eso es otra cuestión, antes de partir coge esto... en pago por tu ayuda. Gracias de nuevo.', 0),
(@ID, 'esMX', 'Gracias, $n. Has sido de mucha más ayuda de lo que había esperado. El aire de este lugar parece ahogar mi voluntad. Estoy cansada y puedo asegurarte que no me recuperaré mientras siga aquí.$B$BNo estoy segura de cómo lograré infiltrarme en la Vega del Amparo para informar sobre la fuerza de la Cruzada Escarlata en el lugar.$B$BPero eso es otra cuestión, antes de partir coge esto... en pago por tu ayuda. Gracias de nuevo.', 0);
-- 6024 La súplica de Hameya
-- https://es.classic.wowhead.com/quest=6024
SET @ID := 6024;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este cofre enterrado aquí está bien cerrado.', 0),
(@ID, 'esMX', 'Este cofre enterrado aquí está bien cerrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¡El cofre de Hameya está abierto!!', 0),
(@ID, 'esMX', '¡¡El cofre de Hameya está abierto!!', 0);
-- 6025 Negocios inconclusos
-- https://es.classic.wowhead.com/quest=6025
SET @ID := 6025;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es una tarea peligrosa, $n. Envidio tu coraje.', 0),
(@ID, 'esMX', 'Es una tarea peligrosa, $n. Envidio tu coraje.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido, $n! ¡Gracias!$B$BVolveré con Elling... quiero decir, a Ventormenta, tan pronto como pueda. Toma, coge esta moneda, es lo menos que puedo hacer por ti. Haces honor a tu pueblo, $n. Gracias y buena suerte.', 0),
(@ID, 'esMX', '¡Lo has conseguido, $n! ¡Gracias!$B$BVolveré con Elling... quiero decir, a Ventormenta, tan pronto como pueda. Toma, coge esta moneda, es lo menos que puedo hacer por ti. Haces honor a tu pueblo, $n. Gracias y buena suerte.', 0);
-- 6026 Eso pide mucho
-- https://es.classic.wowhead.com/quest=6026
SET @ID := 6026;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Confía en el viejo Smokey, $r. La recompensa merecerá la pena. Esa gente del Alba Argenta no se anda con bromas cuando se trata de pagar.', 0),
(@ID, 'esMX', 'Confía en el viejo Smokey, $r. La recompensa merecerá la pena. Esa gente del Alba Argenta no se anda con bromas cuando se trata de pagar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo pagarte la mitad por adelantado y la mitad cuando el trabajo esté hecho.', 0),
(@ID, 'esMX', 'Puedo pagarte la mitad por adelantado y la mitad cuando el trabajo esté hecho.', 0);
-- 6029 El informe Vista Eterna
-- https://es.classic.wowhead.com/quest=6029
SET @ID := 6029;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. En nombre de El Alba Argenta te ofrezco seguridad y protección mientras te encuentres en El Baluarte. ¡Puede que incluso te ofrezca la posibilidad de luchar por una causa digna!', 0),
(@ID, 'esMX', 'Saludos, $c. En nombre de El Alba Argenta te ofrezco seguridad y protección mientras te encuentres en El Baluarte. ¡Puede que incluso te ofrezca la posibilidad de luchar por una causa digna!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gregor está lleno de recursos para ser humano. Desde hace algún tiempo ha estado ocupándose del Cártel Bonvapor y se ha convertido en un auténtico experto en el "arte" de las negociaciones goblin. Si bien es cierto que la primera lealtad de los goblins es hacia los que tienen más liquidez, también conocen y respetan el valor de la diplomacia. Sobre todo les sirve para tener clientes fijos...$B$BEn cualquier caso, El Alba Argenta agradece todo tu esfuerzo. Por favor, toma esto y nuestra gratitud.', 0),
(@ID, 'esMX', 'Gregor está lleno de recursos para ser humano. Desde hace algún tiempo ha estado ocupándose del Cártel Bonvapor y se ha convertido en un auténtico experto en el "arte" de las negociaciones goblin. Si bien es cierto que la primera lealtad de los goblins es hacia los que tienen más liquidez, también conocen y respetan el valor de la diplomacia. Sobre todo les sirve para tener clientes fijos...$B$BEn cualquier caso, El Alba Argenta agradece todo tu esfuerzo. Por favor, toma esto y nuestra gratitud.', 0);
-- 6031 Paño rúnico
-- https://es.classic.wowhead.com/quest=6031
SET @ID := 6031;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el paño rúnico? ¡Mi gente está ansiosa por más artículos de paño rúnico!', 0),
(@ID, 'esMX', '¿Tienes el paño rúnico? ¡Mi gente está ansiosa por más artículos de paño rúnico!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, trajiste el paño. ¡Qué material tan fino!$B$BGracias, $n. Eres $gun verdadero amigo:una verdadera amiga;. Acepta esto a cambio.', 0),
(@ID, 'esMX', 'Ah, trajiste el paño. ¡Qué material tan fino!$B$BGracias, $n. Eres $gun verdadero amigo:una verdadera amiga;. Acepta esto a cambio.', 0);
-- 6032 Tela sagrada
-- https://es.classic.wowhead.com/quest=6032
SET @ID := 6032;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído la tela lunar, $n?', 0),
(@ID, 'esMX', '¿Has traído la tela lunar, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Esta tela lunar se utilizará en prendas sagradas para nuestro pueblo. Gracias, <no,mbre>. Ahora te entrenaré.', 0),
(@ID, 'esMX', 'Ah, muy bien. Esta tela lunar se utilizará en prendas sagradas para nuestro pueblo. Gracias, <no,mbre>. Ahora te entrenaré.', 0);
-- 6041 Cuando Smokey canta, me pongo violento
-- https://es.classic.wowhead.com/quest=6041
SET @ID := 6041;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Estructuras de la Plaga destruidas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me sobraron suministros para hacer algunas barras más del compuesto especial. Dígale al viejo Smokey si necesita más.', 0),
(@ID, 'esMX', 'Me sobraron suministros para hacer algunas barras más del compuesto especial. Dígale al viejo Smokey si necesita más.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres mucho más $goscuro:oscura; de lo que recuerdo. Tienes ese look para ti; la mirada que dice: "Me ha quemado una bomba de alto explosivo".$B$B<Smokey se ríe.>$B$B¡De todos modos! Aquí está tu parte del botín. Le agregué algo extra para ayudar a aliviar las quemaduras.', 0),
(@ID, 'esMX', 'Eres mucho más $goscuro:oscura; de lo que recuerdo. Tienes ese look para ti; la mirada que dice: "Me ha quemado una bomba de alto explosivo".$B$B<Smokey se ríe.>$B$B¡De todos modos! Aquí está tu parte del botín. Le agregué algo extra para ayudar a aliviar las quemaduras.', 0);
-- 6042 Los pequeños problemas de la no-vida
-- https://es.classic.wowhead.com/quest=6042
SET @ID := 6042;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Podría haber sido peor. Podría haberte hecho recolectar guano de murciélago.$B$B<Nathanos te mira con contemplación.>$B$BHrm ... ¡Oye! Espera un minuto. ¿Adónde vas?', 0),
(@ID, 'esMX', 'Podría haber sido peor. Podría haberte hecho recolectar guano de murciélago.$B$B<Nathanos te mira con contemplación.>$B$BHrm ... ¡Oye! Espera un minuto. ¿Adónde vas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es increíble lo que se puede conseguir con un poquito de ira y mala leche.', 0),
(@ID, 'esMX', 'Es increíble lo que se puede conseguir con un poquito de ira y mala leche.', 0);
-- 6061 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6061
SET @ID := 6061;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Practica tus habilidades, $n. Domestica al zancudo de llanura adulto.', 0),
(@ID, 'esMX', 'Practica tus habilidades, $n. Domestica al zancudo de llanura adulto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me han aparecido señales de la Madre Tierra; lo has hecho bien.', 0),
(@ID, 'esMX', 'Me han aparecido señales de la Madre Tierra; lo has hecho bien.', 0);
-- 6062 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6062
SET @ID := 6062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buena suerte, joven $c.', 0),
(@ID, 'esMX', 'Buena suerte, joven $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho un buen trabajo, $n. Creo que estás $glisto:lista; para tu siguiente tarea.', 0),
(@ID, 'esMX', 'Has hecho un buen trabajo, $n. Creo que estás $glisto:lista; para tu siguiente tarea.', 0);
-- 6063 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6063
SET @ID := 6063;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, irás mejorando y algún día serás $gun estupendo:una estupenda; $c.', 0),
(@ID, 'esMX', '$n, irás mejorando y algún día serás $gun estupendo:una estupenda; $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Aprendes rápido.', 0),
(@ID, 'esMX', '¡Excelente, $n! Aprendes rápido.', 0);
-- 6064 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6064
SET @ID := 6064;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No te preocupes, $gmuchacho:muchacha;! Tendrás que probar muchos antes de tener que decidirte por uno.', 0),
(@ID, 'esMX', '¡No te preocupes, $gmuchacho:muchacha;! Tendrás que probar muchos antes de tener que decidirte por uno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo sé, lo sé; te estás preguntando qué sigue, ¿no?', 0),
(@ID, 'esMX', 'Lo sé, lo sé; te estás preguntando qué sigue, ¿no?', 0);
-- El camino del cazador
-- 6065, 6066, 6067
-- https://es.classic.wowhead.com/quest=6065
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6065, 6066, 6067) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6065, 'esES', 'Sí, creo que estás $glisto:lista;.', 0),
(6066, 'esES', 'Sí, creo que estás $glisto:lista;.', 0),
(6067, 'esES', 'Sí, creo que estás $glisto:lista;.', 0),
(6065, 'esMX', 'Sí, creo que estás $glisto:lista;.', 0),
(6066, 'esMX', 'Sí, creo que estás $glisto:lista;.', 0),
(6067, 'esMX', 'Sí, creo que estás $glisto:lista;.', 0);
-- El camino del cazador
-- 6068, 6069, 6070
-- https://es.classic.wowhead.com/quest=6068
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6068, 6069, 6070) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6068, 'esES', 'Sí, es hora de que comiences tu entrenamiento.', 0),
(6069, 'esES', 'Sí, es hora de que comiences tu entrenamiento.', 0),
(6070, 'esES', 'Sí, es hora de que comiences tu entrenamiento.', 0),
(6068, 'esMX', 'Sí, es hora de que comiences tu entrenamiento.', 0),
(6069, 'esMX', 'Sí, es hora de que comiences tu entrenamiento.', 0),
(6070, 'esMX', 'Sí, es hora de que comiences tu entrenamiento.', 0);
-- El camino del cazador
-- 6071, 6072, 6073
-- https://es.classic.wowhead.com/quest=6071
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6071, 6072, 6073) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6071, 'esES', 'Sí, es el momento, $c.', 0),
(6072, 'esES', 'Sí, es el momento, $c.', 0),
(6073, 'esES', 'Sí, es el momento, $c.', 0),
(6071, 'esMX', 'Sí, es el momento, $c.', 0),
(6072, 'esMX', 'Sí, es el momento, $c.', 0),
(6073, 'esMX', 'Sí, es el momento, $c.', 0);
-- El camino del cazador
-- 6074, 6075, 6076
-- https://es.classic.wowhead.com/quest=6074
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6074, 6075, 6076) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6074, 'esES', 'Sí, creo que tú también estás $glisto:lista;...', 0),
(6075, 'esES', 'Sí, creo que tú también estás $glisto:lista;...', 0),
(6076, 'esES', 'Sí, creo que tú también estás $glisto:lista;...', 0),
(6074, 'esMX', 'Sí, creo que tú también estás $glisto:lista;...', 0),
(6075, 'esMX', 'Sí, creo que tú también estás $glisto:lista;...', 0),
(6076, 'esMX', 'Sí, creo que tú también estás $glisto:lista;...', 0);
-- 6081 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6081
SET @ID := 6081;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, $gun:una; joven $c. Sí, te concederé las habilidades que necesitas para domar y guiar a una mascota. No solo podrás enseñar nuevas habilidades a tu mascota, además podrás darle de comer, e incluso resucitarla si cae en combate.$B$BAhora, retírate. Hablaremos más adelante.', 0),
(@ID, 'esMX', 'Vaya, $gun:una; joven $c. Sí, te concederé las habilidades que necesitas para domar y guiar a una mascota. No solo podrás enseñar nuevas habilidades a tu mascota, además podrás darle de comer, e incluso resucitarla si cae en combate.$B$BAhora, retírate. Hablaremos más adelante.', 0);
-- 6082 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6082
SET @ID := 6082;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lograste domar al escórpido?', 0),
(@ID, 'esMX', '¿Lograste domar al escórpido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya has aprendido todo lo que podía enseñarte, $n. Es hora de que apliques lo que has aprendido y elijas una mascota.$B$BTen, $n. Te doy el poder de domar a una bestia, así como de convocarla y despedirla según convengas. Utiliza tus nuevas habilidades con orgullo, te las has ganado.', 0),
(@ID, 'esMX', 'Ya has aprendido todo lo que podía enseñarte, $n. Es hora de que apliques lo que has aprendido y elijas una mascota.$B$BTen, $n. Te doy el poder de domar a una bestia, así como de convocarla y despedirla según convengas. Utiliza tus nuevas habilidades con orgullo, te las has ganado.', 0);
-- 6083 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6083
SET @ID := 6083;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesitas practicar para adquirir las habilidades que necesitas para controlar a tu mascota. ¿Has conseguido domar a algún reptador de espuma?', 0),
(@ID, 'esMX', 'Necesitas practicar para adquirir las habilidades que necesitas para controlar a tu mascota. ¿Has conseguido domar a algún reptador de espuma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aprendes rápido, $n. Has hecho un buen trabajo.', 0),
(@ID, 'esMX', 'Aprendes rápido, $n. Has hecho un buen trabajo.', 0);
-- 6084 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6084
SET @ID := 6084;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué opinas del leopardo de las nieves, $n?', 0),
(@ID, 'esMX', '¿Qué opinas del leopardo de las nieves, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando note que has aprendido lo suficiente, te concederé la posibilidad de elegir cualquier mascota de tu agrado.', 0),
(@ID, 'esMX', 'Cuando note que has aprendido lo suficiente, te concederé la posibilidad de elegir cualquier mascota de tu agrado.', 0);
-- 6085 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6085
SET @ID := 6085;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya domesticaste al oso zarpahelada?', 0),
(@ID, 'esMX', '¿Ya domesticaste al oso zarpahelada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n. Ahora te daré el poder de domesticar una bestia, así como de llamarla y despedirla como quieras.$B$B¡Búscate una mascota buena y leal y disfruta de la caza!', 0),
(@ID, 'esMX', 'Aquí tienes, $n. Ahora te daré el poder de domesticar una bestia, así como de llamarla y despedirla como quieras.$B$B¡Búscate una mascota buena y leal y disfruta de la caza!', 0);
-- 6086 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6086
SET @ID := 6086;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gUn nuevo:Una nueva; recluta, ¿eh? Ya veo, estás en camino de convertirte en $gun:una; gran $n.$B$BSí, puedo otorgarle las habilidades que necesitas para entrenar y guiar a tu mascota. No solo podrás enseñarle a tu mascota nuevas habilidades, sino que ahora podrás alimentar a tu mascota y revivirla en caso de que caiga en la batalla.$B$BRecuerda que la clave para sacarle el máximo partido a tu nueva mascota es respetarla y tratarla bien. A su vez, tu mascota será tu amiga más fiel.', 0),
(@ID, 'esMX', '$gUn nuevo:Una nueva; recluta, ¿eh? Ya veo, estás en camino de convertirte en $gun:una; gran $n.$B$BSí, puedo otorgarle las habilidades que necesitas para entrenar y guiar a tu mascota. No solo podrás enseñarle a tu mascota nuevas habilidades, sino que ahora podrás alimentar a tu mascota y revivirla en caso de que caiga en la batalla.$B$BRecuerda que la clave para sacarle el máximo partido a tu nueva mascota es respetarla y tratarla bien. A su vez, tu mascota será tu amiga más fiel.', 0);
-- 6087 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6087
SET @ID := 6087;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado un acechador de pradera?', 0),
(@ID, 'esMX', '¿Has encontrado un acechador de pradera?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... La Madre Tierra cree que estás $glisto:lista; para la próxima lección.', 0),
(@ID, 'esMX', 'Sí... La Madre Tierra cree que estás $glisto:lista; para la próxima lección.', 0);
-- 6088 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6088
SET @ID := 6088;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto estarás $glisto:lista;, $n.', 0),
(@ID, 'esMX', 'Pronto estarás $glisto:lista;, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has aprendido todo lo que puedo enseñarte, $n. Que las bendiciones de la Madre Tierra te guíen en la elección de una mascota.$B$BAquí tienes, $n. Ahora te daré el poder de domesticar una bestia, así como de llamarla y despedirla como mejor te parezca. Usa tus nuevas habilidades con orgullo y honra a la Madre Tierra.', 0),
(@ID, 'esMX', 'Has aprendido todo lo que puedo enseñarte, $n. Que las bendiciones de la Madre Tierra te guíen en la elección de una mascota.$B$BAquí tienes, $n. Ahora te daré el poder de domesticar una bestia, así como de llamarla y despedirla como mejor te parezca. Usa tus nuevas habilidades con orgullo y honra a la Madre Tierra.', 0);
-- 6089 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6089
SET @ID := 6089;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gUn:Una; joven $c, ya veo. Sí, puedo otorgarle las habilidades que necesita para entrenar y guiar a tu mascota. No solo podrás enseñarle a tu mascota nuevas habilidades, sino que ahora podrás alimentar a tu mascota y revivirla en caso de que caiga en la batalla.$B$BAhora, adelante. Que la Madre Tierra te guíe en tu camino. Hablaremos de nuevo otro día.', 0),
(@ID, 'esMX', '$gUn:Una; joven $c, ya veo. Sí, puedo otorgarle las habilidades que necesita para entrenar y guiar a tu mascota. No solo podrás enseñarle a tu mascota nuevas habilidades, sino que ahora podrás alimentar a tu mascota y revivirla en caso de que caiga en la batalla.$B$BAhora, adelante. Que la Madre Tierra te guíe en tu camino. Hablaremos de nuevo otro día.', 0);
-- 6101 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6101
SET @ID := 6101;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Respetar el equilibrio entre la naturaleza y uno mismo es el modo de vida de cualquier $r.', 0),
(@ID, 'esMX', 'Respetar el equilibrio entre la naturaleza y uno mismo es el modo de vida de cualquier $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo tu entrega y sé que has entendido lo que te he enseñado, $n.', 0),
(@ID, 'esMX', 'Veo tu entrega y sé que has entendido lo que te he enseñado, $n.', 0);
-- 6102 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6102
SET @ID := 6102;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus logros me llenan de orgullo, $n. ¿Has terminado la tarea que te asigné?', 0),
(@ID, 'esMX', 'Tus logros me llenan de orgullo, $n. ¿Has terminado la tarea que te asigné?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has aprendido todo lo que puedo enseñarte, $n. Permíteme que te dé un último consejo: elige detenidamente a tu primera mascota. Puede ser terrestre, acuática o de los cielos pero, elijas la que elijas, ten en cuenta que estará a tu lado una buena temporada.$B$BAquí la tienes, $n. Ahora te enseñaré a domarla, así como a llamarla y retirarla a tu antojo. Utiliza tus nuevas habilidades con orgullo; te las has ganado a pulso.', 0),
(@ID, 'esMX', 'Has aprendido todo lo que puedo enseñarte, $n. Permíteme que te dé un último consejo: elige detenidamente a tu primera mascota. Puede ser terrestre, acuática o de los cielos pero, elijas la que elijas, ten en cuenta que estará a tu lado una buena temporada.$B$BAquí la tienes, $n. Ahora te enseñaré a domarla, así como a llamarla y retirarla a tu antojo. Utiliza tus nuevas habilidades con orgullo; te las has ganado a pulso.', 0);
-- 6103 Domesticar la bestia
-- https://es.classic.wowhead.com/quest=6103
SET @ID := 6103;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que te estás preparando para ser $c. Sí, te enseñaré a amaestrar a tu mascota. Podrás enseñarle cosas nuevas, alimentarla y resucitarla si muere en combate.$B$B$n, recuerda que siempre debes respetar el equilibrio y vivir en armonía con la naturaleza. Y ahora, márchate. Volveremos a vernos.', 0),
(@ID, 'esMX', 'Veo que te estás preparando para ser $c. Sí, te enseñaré a amaestrar a tu mascota. Podrás enseñarle cosas nuevas, alimentarla y resucitarla si muere en combate.$B$B$n, recuerda que siempre debes respetar el equilibrio y vivir en armonía con la naturaleza. Y ahora, márchate. Volveremos a vernos.', 0);
-- Nuevas lecciones
-- 6121, 6126
-- https://es.classic.wowhead.com/quest=6121
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(6121, 6126) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(6121, 'esES', 'Saludos, joven $c. Me alegra ver que estás $gdeseoso:deseosa; de aprender a curar envenenamientos.$B$BEn el pasado, muchos druidas eran sometidos a diversas pruebas, pero tu trabajo no implicará tal cosa. En El Cruce de Los Baldíos ha habido una epidemia de envenenamientos de animales, pero allí no han sabido controlarla. Un representante de El Cruce ha pedido ayuda al Claro de la Luna y nosotros vamos a enviarte a ti como respuesta. No se trata de un ejercicio práctico, el trabajo que tendrás que realizar es real. Tenlo en cuenta.', 0),
(6126, 'esES', 'Saludos, joven $c. Me alegra ver que estás $gdeseoso:deseosa; de aprender a curar envenenamientos.$B$BEn el pasado, muchos druidas eran sometidos a diversas pruebas, pero tu trabajo no implicará tal cosa. En El Cruce de Los Baldíos ha habido una epidemia de envenenamientos de animales, pero allí no han sabido controlarla. Un representante de El Cruce ha pedido ayuda al Claro de la Luna y nosotros vamos a enviarte a ti como respuesta. No se trata de un ejercicio práctico, el trabajo que tendrás que realizar es real. Tenlo en cuenta.', 0),
(6121, 'esMX', 'Saludos, joven $c. Me alegra ver que estás $gdeseoso:deseosa; de aprender a curar envenenamientos.$B$BEn el pasado, muchos druidas eran sometidos a diversas pruebas, pero tu trabajo no implicará tal cosa. En El Cruce de Los Baldíos ha habido una epidemia de envenenamientos de animales, pero allí no han sabido controlarla. Un representante de El Cruce ha pedido ayuda al Claro de la Luna y nosotros vamos a enviarte a ti como respuesta. No se trata de un ejercicio práctico, el trabajo que tendrás que realizar es real. Tenlo en cuenta.', 0),
(6126, 'esMX', 'Saludos, joven $c. Me alegra ver que estás $gdeseoso:deseosa; de aprender a curar envenenamientos.$B$BEn el pasado, muchos druidas eran sometidos a diversas pruebas, pero tu trabajo no implicará tal cosa. En El Cruce de Los Baldíos ha habido una epidemia de envenenamientos de animales, pero allí no han sabido controlarla. Un representante de El Cruce ha pedido ayuda al Claro de la Luna y nosotros vamos a enviarte a ti como respuesta. No se trata de un ejercicio práctico, el trabajo que tendrás que realizar es real. Tenlo en cuenta.', 0);
-- 6122 La fuente del envenenamiento
-- https://es.classic.wowhead.com/quest=6122
SET @ID := 6122;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eres $gel:la; que envió el Círculo Cenarion en Claro de Luna? ¡Eso es maravilloso! Tenemos una crisis entre manos con los pobres ciervos, y estamos felices por toda la ayuda que podemos obtener.$B$B¿Tienes la muestra de agua que Dendrita Rafagaestelar dijo que tendrías? Me indicó que podríamos trabajar $gjuntos:juntas; en una cura...', 0),
(@ID, 'esMX', '¿Eres $gel:la; que envió el Círculo Cenarion en Claro de Luna? ¡Eso es maravilloso! Tenemos una crisis entre manos con los pobres ciervos, y estamos felices por toda la ayuda que podemos obtener.$B$B¿Tienes la muestra de agua que Dendrita Rafagaestelar dijo que tendrías? Me indicó que podríamos trabajar $gjuntos:juntas; en una cura...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por Elune, esta agua es asquerosa! No es de extrañar que los ciervos estén enfermos.$B$BAlgo está contaminando el agua y, además, está corrompiendo todo el nivel freático de Costa Oscura. Se han visto ciervos enfermos por toda el área, y no solo por el río. Si bien es muy probable que el agua sea la fuente principal de propagación de la enfermedad, aquí hay algo más en juego.$B$BEsta agua, lo crea o no, nos ayudará a crear una cura. Mientras investigo esta agua, necesito algunos elementos para formular la cura...', 0),
(@ID, 'esMX', '¡Por Elune, esta agua es asquerosa! No es de extrañar que los ciervos estén enfermos.$B$BAlgo está contaminando el agua y, además, está corrompiendo todo el nivel freático de Costa Oscura. Se han visto ciervos enfermos por toda el área, y no solo por el río. Si bien es muy probable que el agua sea la fuente principal de propagación de la enfermedad, aquí hay algo más en juego.$B$BEsta agua, lo crea o no, nos ayudará a crear una cura. Mientras investigo esta agua, necesito algunos elementos para formular la cura...', 0);
-- 6123 Reunir los ingredientes del remedio
-- https://es.classic.wowhead.com/quest=6123
SET @ID := 6123;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los reactivos que necesito para hacer el ungüento? Los ciervos no están mejorando por sí solos, ¡así que es mejor que nos apresuremos a ayudarlos!', 0),
(@ID, 'esMX', '¿Tienes los reactivos que necesito para hacer el ungüento? Los ciervos no están mejorando por sí solos, ¡así que es mejor que nos apresuremos a ayudarlos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es bueno, $n, tanto que debería ser suficiente para hacer algunas dosis amplias del ungüento, al menos lo suficiente para comenzar a marcar una diferencia.$B$BHacer una cura para los venenos puede ser bastante difícil porque a menudo cada uno requiere un antídoto muy específico para contrarrestarlo. ¡Imagínate poder curar un veneno a voluntad sin tener que preocuparte por los ingredientes exactos del antídoto!$B$B¡Ahora, déjame trabajar en esto!', 0),
(@ID, 'esMX', 'Esto es bueno, $n, tanto que debería ser suficiente para hacer algunas dosis amplias del ungüento, al menos lo suficiente para comenzar a marcar una diferencia.$B$BHacer una cura para los venenos puede ser bastante difícil porque a menudo cada uno requiere un antídoto muy específico para contrarrestarlo. ¡Imagínate poder curar un veneno a voluntad sin tener que preocuparte por los ingredientes exactos del antídoto!$B$B¡Ahora, déjame trabajar en esto!', 0);
