-- 3122 Regresa junto al médico brujo Uzer'i
-- https://es.classic.wowhead.com/quest=3122
SET @ID := 3122;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hablado con Neeru?', 0),
(@ID, 'esMX', '¿Has hablado con Neeru?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es justo lo que necesito para preparar la vasija de muisek, $n. Pronto veremos si mis últimos hechizos resultan ser tan potentes como espero.$B$BDame un momento, por favor. Debo celebrar el ritual y aplicar las hierbas.', 0),
(@ID, 'esMX', 'Es justo lo que necesito para preparar la vasija de muisek, $n. Pronto veremos si mis últimos hechizos resultan ser tan potentes como espero.$B$BDame un momento, por favor. Debo celebrar el ritual y aplicar las hierbas.', 0);
-- 3123 Probar la vasija
-- https://es.classic.wowhead.com/quest=3123
SET @ID := 3123;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste capturar a los lechúcicos?$B$BSi tienes éxito, podremos encoger y capturar el muisek de las criaturas de Feralas.', 0),
(@ID, 'esMX', '¿Pudiste capturar a los lechúcicos?$B$BSi tienes éxito, podremos encoger y capturar el muisek de las criaturas de Feralas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si una criatura sufre una muerte violenta, su muisek puede escapar y buscar venganza. Encogiendo las criaturas como hiciste tú, $n, se impide que el muisek escape. ¡Ahora podemos usarlo para lo que queramos!', 0),
(@ID, 'esMX', 'Si una criatura sufre una muerte violenta, su muisek puede escapar y buscar venganza. Encogiendo las criaturas como hiciste tú, $n, se impide que el muisek escape. ¡Ahora podemos usarlo para lo que queramos!', 0);
-- 3124 Muisek de hipogrifo
-- https://es.classic.wowhead.com/quest=3124
SET @ID := 3124;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lograste capturar a los hipogrifos?', 0),
(@ID, 'esMX', '¿Lograste capturar a los hipogrifos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si, después de matar a un animal, permitiéramos que su muisek escapara, este podría tomar la forma de algo más grande. Y nunca estaríamos a salvo, pues buscaría venganza.$B$BEl que te he encomendado es un trabajo peligroso, $n, pero lo has hecho bien.', 0),
(@ID, 'esMX', 'Si, después de matar a un animal, permitiéramos que su muisek escapara, este podría tomar la forma de algo más grande. Y nunca estaríamos a salvo, pues buscaría venganza.$B$BEl que te he encomendado es un trabajo peligroso, $n, pero lo has hecho bien.', 0);
-- 3125 Muisek de dragón feérico
-- https://es.classic.wowhead.com/quest=3125
SET @ID := 3125;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste hacerte con el muisek de los dragones feéricos?', 0),
(@ID, 'esMX', '¿Conseguiste hacerte con el muisek de los dragones feéricos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Ahora tenemos los poderes espirituales del dragón feérico a nuestra disposición.$B$BEspero que aceptes una tarea más.', 0),
(@ID, 'esMX', 'Gracias, $n. Ahora tenemos los poderes espirituales del dragón feérico a nuestra disposición.$B$BEspero que aceptes una tarea más.', 0);
-- 3126 Muisek de antárbol
-- https://es.classic.wowhead.com/quest=3126
SET @ID := 3126;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lograste capturar a los Caminabosques deambulantes?', 0),
(@ID, 'esMX', '¿Lograste capturar a los Caminabosques deambulantes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Nuestra colección de muiseks está casi acabada.', 0),
(@ID, 'esMX', 'Gracias, $n. Nuestra colección de muiseks está casi acabada.', 0);
-- 3127 Muisek de gigante montés
-- https://es.classic.wowhead.com/quest=3127
SET @ID := 3127;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lograste capturar a los gigantes del risco?', 0),
(@ID, 'esMX', '¿Lograste capturar a los gigantes del risco?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Imagina las posibilidades que nos da lo que tenemos, $n. Con los materiales que has reunido, podré atrapar para siempre el muisek de estas criaturas y hacer con él lo que me plazca.', 0),
(@ID, 'esMX', 'Imagina las posibilidades que nos da lo que tenemos, $n. Con los materiales que has reunido, podré atrapar para siempre el muisek de estas criaturas y hacer con él lo que me plazca.', 0);
-- 3128 Materiales naturales
-- https://es.classic.wowhead.com/quest=3128
SET @ID := 3128;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has podido reunir los materiales que necesito?', 0),
(@ID, 'esMX', '¿Has podido reunir los materiales que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantástico! Estos materiales, combinados con el muisek, deberían procurarnos los resultados que queremos.', 0),
(@ID, 'esMX', '¡Fantástico! Estos materiales, combinados con el muisek, deberían procurarnos los resultados que queremos.', 0);
-- 3129 Armas del espíritu
-- https://es.classic.wowhead.com/quest=3129
SET @ID := 3129;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tal y como prometí, $n, el muisek de las criaturas ha quedado vinculado para siempre al poder de estas armas.$B$BAhora puedes hacer tuya su energía. Utilízala bien.', 0),
(@ID, 'esMX', 'Tal y como prometí, $n, el muisek de las criaturas ha quedado vinculado para siempre al poder de estas armas.$B$BAhora puedes hacer tuya su energía. Utilízala bien.', 0);
-- 3130 En contra de los Crestafuria
-- https://es.classic.wowhead.com/quest=3130
SET @ID := 3130;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, $n. Me gusta que quienes trabajan para mí tengan esa actitud de "puedo hacerlo".$B$BLa general Plumaluna me ha encargado que me dirija a los naga de forma directa. Mis planes tienen dos objetivos: uno, debilitar tanto su número como su cadena de mando y, dos, descubrir qué están haciendo en las ruinas. Con tu ayuda, reduciremos la presencia naga sin sacrificar la seguridad del Bastión.', 0),
(@ID, 'esMX', 'Excelente, $n. Me gusta que quienes trabajan para mí tengan esa actitud de "puedo hacerlo".$B$BLa general Plumaluna me ha encargado que me dirija a los naga de forma directa. Mis planes tienen dos objetivos: uno, debilitar tanto su número como su cadena de mando y, dos, descubrir qué están haciendo en las ruinas. Con tu ayuda, reduciremos la presencia naga sin sacrificar la seguridad del Bastión.', 0);
-- 3141 Loramus
-- https://es.classic.wowhead.com/quest=3141
SET @ID := 3141;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me interrumpas, $r.', 0),
(@ID, 'esMX', 'No me interrumpas, $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Que así sea...', 0),
(@ID, 'esMX', 'Que así sea...', 0);
-- 3161 Gahz'rilo
-- https://es.classic.wowhead.com/quest=3161
SET @ID := 3161;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algún problema?$B$BHay gahz\'rilo por todas partes en Tanaris, $n. ¡Sigue buscando!', 0),
(@ID, 'esMX', '¿Tienes algún problema?$B$BHay gahz\'rilo por todas partes en Tanaris, $n. ¡Sigue buscando!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos adornos son perfectos, simplemente perfectos. Muchas gracias por tu ayuda, $n.$B$B¡Ah! ¿Me devuelves mi casco?', 0),
(@ID, 'esMX', 'Estos adornos son perfectos, simplemente perfectos. Muchas gracias por tu ayuda, $n.$B$B¡Ah! ¿Me devuelves mi casco?', 0);
-- 3181 El cuerno de la bestia
-- https://es.classic.wowhead.com/quest=3181
SET @ID := 3181;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No voy a abrir.', 0),
(@ID, 'esMX', 'No voy a abrir.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es una falsificación!$B$BHe visto a Margol, sé que su cuerno es al menos 8 veces más grande que ese, $n. Será de un morrotormenta de Los Baldíos. ¡A Guijarro no la engaña nadie!', 0),
(@ID, 'esMX', '¡Eso es una falsificación!$B$BHe visto a Margol, sé que su cuerno es al menos 8 veces más grande que ese, $n. Será de un morrotormenta de Los Baldíos. ¡A Guijarro no la engaña nadie!', 0);
-- 3182 Certificado de autenticidad
-- https://es.classic.wowhead.com/quest=3182
SET @ID := 3182;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Saludos! ¿Deseas visitar el museo?', 0),
(@ID, 'esMX', '¡Saludos! ¿Deseas visitar el museo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto?$B$B¡No me lo puedo creer! ¿Te das cuenta de lo que es, $r? ¡Es el cuerno de Margol la Furibunda, el terror de La Garganta de Fuego!$B$B¿Puedo quedármelo?', 0),
(@ID, 'esMX', '¿Qué es esto?$B$B¡No me lo puedo creer! ¿Te das cuenta de lo que es, $r? ¡Es el cuerno de Margol la Furibunda, el terror de La Garganta de Fuego!$B$B¿Puedo quedármelo?', 0);
-- 3201 ¡Al fin!
-- https://es.classic.wowhead.com/quest=3201
SET @ID := 3201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me lo creo.', 0),
(@ID, 'esMX', 'No me lo creo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No entiendo cómo pudiste derrotar a Margol, pero un trato es un trato; toma la llave.$B$BSi te pasa algo, te lo habrás buscado tú.', 0),
(@ID, 'esMX', 'No entiendo cómo pudiste derrotar a Margol, pero un trato es un trato; toma la llave.$B$BSi te pasa algo, te lo habrás buscado tú.', 0);
-- 3221 Habla con Renferrel
-- https://es.classic.wowhead.com/quest=3221
SET @ID := 3221;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Hay un problema con los corazones de lobo que requiere nuestra atención.', 0),
(@ID, 'esMX', 'Ah, muy bien. Hay un problema con los corazones de lobo que requiere nuestra atención.', 0);
-- 3261 Jorn Vidente del Cielo
-- https://es.classic.wowhead.com/quest=3261
SET @ID := 3261;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, joven. ¿Has venido para seguir el camino $gdel:de la; $c?$B$BMuy bien. Empecemos.', 0),
(@ID, 'esMX', 'Saludos, joven. ¿Has venido para seguir el camino $gdel:de la; $c?$B$BMuy bien. Empecemos.', 0);
-- 3281 La plata robada
-- https://es.classic.wowhead.com/quest=3281
SET @ID := 3281;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la plata?', 0),
(@ID, 'esMX', '¿Tienes la plata?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! Así que los raptores tenían la plata escondida en su guarida como pensábamos. Cuesta creer que estas bestias codicien la plata. ¡Quizás lo que cuentan de su inteligencia no es tan descabellado como creía!$B$BGracias, $n. Toma esto como recompensa por tus servicios y que sepas que la guardia de El Cruce te debe el próximo mes de paga.', 0),
(@ID, 'esMX', '¡Eso es! Así que los raptores tenían la plata escondida en su guarida como pensábamos. Cuesta creer que estas bestias codicien la plata. ¡Quizás lo que cuentan de su inteligencia no es tan descabellado como creía!$B$BGracias, $n. Toma esto como recompensa por tus servicios y que sepas que la guardia de El Cruce te debe el próximo mes de paga.', 0);
-- 3301 Mura Runatótem
-- https://es.classic.wowhead.com/quest=3301
SET @ID := 3301;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Huelo el polvo de Los Baldíos en ti, $c. Has viajado muy lejos.', 0),
(@ID, 'esMX', 'Huelo el polvo de Los Baldíos en ti, $c. Has viajado muy lejos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto? Este caparazón tiene un brillo interior, como si aún hubiera vida en su interior. ¡Asombroso! Debo examinarlo más a fondo.$B$BGracias, $n. Con suerte, este caparazón contendrá un secreto que podré usar para ayudar a la pobre tierra del Bosque de Argénteos.', 0),
(@ID, 'esMX', '¿Qué es esto? Este caparazón tiene un brillo interior, como si aún hubiera vida en su interior. ¡Asombroso! Debo examinarlo más a fondo.$B$BGracias, $n. Con suerte, este caparazón contendrá un secreto que podré usar para ayudar a la pobre tierra del Bosque de Argénteos.', 0);
-- 3321 ¿Has perdido esto?
-- https://es.classic.wowhead.com/quest=3321
SET @ID := 3321;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hoy finalizamos nuestra celebración de tu compromiso con la Orden.', 0),
(@ID, 'esMX', 'Hoy finalizamos nuestra celebración de tu compromiso con la Orden.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Levántate y sé $greconocido:reconocida;, $n, $gherrero:herrera; de la Orden de Mithril.', 0),
(@ID, 'esMX', 'Levántate y sé $greconocido:reconocida;, $n, $gherrero:herrera; de la Orden de Mithril.', 0);
-- 3341 Acaba con la amenaza
-- https://es.classic.wowhead.com/quest=3341
SET @ID := 3341;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este tema es de suma importancia, $n. Tenemos que evitar cualquier intento de la Plaga de reforzar sus filas.', 0),
(@ID, 'esMX', 'Este tema es de suma importancia, $n. Tenemos que evitar cualquier intento de la Plaga de reforzar sus filas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La lealtad de un exánime es inquebrantable, $n. Debes mostrarles que tal lealtad les conducirá a su propia destrucción.', 0),
(@ID, 'esMX', 'La lealtad de un exánime es inquebrantable, $n. Debes mostrarles que tal lealtad les conducirá a su propia destrucción.', 0);
-- 3367 Piedras de Suntara
-- https://es.classic.wowhead.com/quest=3367
SET @ID := 3367;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No voy a lograrlo...', 0),
(@ID, 'esMX', 'No voy a lograrlo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dorius dejó caer esta carta cuando le dispararon.', 0),
(@ID, 'esMX', 'Dorius dejó caer esta carta cuando le dispararon.', 0);
-- 3368 Piedras de Suntara
-- https://es.classic.wowhead.com/quest=3368
SET @ID := 3368;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thorius solloza.>', 0),
(@ID, 'esMX', '<Thorius solloza.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Thorius se seca la cara.>$B$BPor la Luz que se cumplirá su deseo.', 0),
(@ID, 'esMX', '<Thorius se seca la cara.>$B$BPor la Luz que se cumplirá su deseo.', 0);
-- 3369 En las pesadillas
-- https://es.classic.wowhead.com/quest=3369
SET @ID := 3369;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te puedo ayudar en algo?', 0),
(@ID, 'esMX', '¿Te puedo ayudar en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes de parte de Falla? Bueno, veamos el fragmento del que dices que era tan reacia a hablar...$B$B<Hamuul intenta mirar dentro del fragmento>$B$BOh... yo no.. bien.$B$B$n, Gracias por traérmelo. Pero no es muy inteligente hablar de cosas como esta, te lo advierto. No deberías meterte en este tipo de asuntos.$B$BDigamos que las cosas del Sueño Esmeralda no son como creíamos...$B$BQuizás nuestros caminos se vuelvan a encontrar en el futuro.', 0),
(@ID, 'esMX', '¿Vienes de parte de Falla? Bueno, veamos el fragmento del que dices que era tan reacia a hablar...$B$B<Hamuul intenta mirar dentro del fragmento>$B$BOh... yo no.. bien.$B$B$n, Gracias por traérmelo. Pero no es muy inteligente hablar de cosas como esta, te lo advierto. No deberías meterte en este tipo de asuntos.$B$BDigamos que las cosas del Sueño Esmeralda no son como creíamos...$B$BQuizás nuestros caminos se vuelvan a encontrar en el futuro.', 0);
-- 3370 En las pesadillas
-- https://es.classic.wowhead.com/quest=3370
SET @ID := 3370;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te puedo ayudar en algo?', 0),
(@ID, 'esMX', '¿Te puedo ayudar en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes de parte de Falla? Bueno, veamos el fragmento del que dices que era tan reacia a hablar...$B$B<Mathrengyl intenta mirar dentro del fragmento>$B$BOh... yo no.. bien.$B$B$n, gracias por traérmelo. Pero no es muy inteligente hablar de cosas como esta, te lo advierto. No deberías meterte en este tipo de asuntos.$B$BDigamos que las cosas del Sueño Esmeralda no son como creíamos...$B$BQuizás nuestros caminos se vuelvan a encontrar en el futuro.', 0),
(@ID, 'esMX', '¿Vienes de parte de Falla? Bueno, veamos el fragmento del que dices que era tan reacia a hablar...$B$B<Mathrengyl intenta mirar dentro del fragmento>$B$BOh... yo no.. bien.$B$B$n, gracias por traérmelo. Pero no es muy inteligente hablar de cosas como esta, te lo advierto. No deberías meterte en este tipo de asuntos.$B$BDigamos que las cosas del Sueño Esmeralda no son como creíamos...$B$BQuizás nuestros caminos se vuelvan a encontrar en el futuro.', 0);
-- 3371 La justicia de los enanos
-- https://es.classic.wowhead.com/quest=3371
SET @ID := 3371;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Déjame, ayuda a los demás.', 0),
(@ID, 'esMX', 'Déjame, ayuda a los demás.', 0);
-- 3372 Libéralos
-- https://es.classic.wowhead.com/quest=3372
SET @ID := 3372;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El altar está vacío.', 0),
(@ID, 'esMX', 'El altar está vacío.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el artefacto misterioso en el Altar de Suntara.', 0),
(@ID, 'esMX', 'Colocas el artefacto misterioso en el Altar de Suntara.', 0);
-- 3373 La esencia de Eranikus
-- https://es.classic.wowhead.com/quest=3373
SET @ID := 3373;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Según te aproximas a la fuente de esencia que Eranikus te dijo, vuelves a oír su voz en tu cabeza.$B$B"Sí mortal, esta fuente de esencia redimirá cualquier elemento no contaminado de mi psique que permanezca imbuido en esta gema. Coloca la gema en la fuente y permite que la magia del Vuelo Verde limpie la corrupción y la contaminación de mi ser. Solo entonces estaré libre y solo entonces el Vuelo podrá reafirmar su dominio de los Atal\'ai."', 0),
(@ID, 'esMX', 'Según te aproximas a la fuente de esencia que Eranikus te dijo, vuelves a oír su voz en tu cabeza.$B$B"Sí mortal, esta fuente de esencia redimirá cualquier elemento no contaminado de mi psique que permanezca imbuido en esta gema. Coloca la gema en la fuente y permite que la magia del Vuelo Verde limpie la corrupción y la contaminación de mi ser. Solo entonces estaré libre y solo entonces el Vuelo podrá reafirmar su dominio de los Atal\'ai."', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas la gema en la fuente de esencia.$B$B"Gracias, mortal, no tienes... esto, ¡esto no puede ser! ¡No! La corrupción de este dios maldito mancha la santidad de la fuente de esencia del Vuelo Verde! No, por favor, mi esencia... me abandona... EL DOLOR... Siento cómo me inunda una pesadilla eterna..."$B$B"Mortal, ¡te lo ruego! Encuentra un miembro del Vuelo Verde para detener esto... ayúdame... Estoy encadenado a la oscuridad... a la agonía eterna... por favor, no me tortures..."', 0),
(@ID, 'esMX', 'Colocas la gema en la fuente de esencia.$B$B"Gracias, mortal, no tienes... esto, ¡esto no puede ser! ¡No! La corrupción de este dios maldito mancha la santidad de la fuente de esencia del Vuelo Verde! No, por favor, mi esencia... me abandona... EL DOLOR... Siento cómo me inunda una pesadilla eterna..."$B$B"Mortal, ¡te lo ruego! Encuentra un miembro del Vuelo Verde para detener esto... ayúdame... Estoy encadenado a la oscuridad... a la agonía eterna... por favor, no me tortures..."', 0);
-- 3374 La esencia de Eranikus
-- https://es.classic.wowhead.com/quest=3374
SET @ID := 3374;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí estamos $n, ante una nueva encrucijada. Ha llegado la hora de tomar otra decisión. ¿Cuál es tu elección, mortal?', 0),
(@ID, 'esMX', 'Aquí estamos $n, ante una nueva encrucijada. Ha llegado la hora de tomar otra decisión. ¿Cuál es tu elección, mortal?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has tomado una decisión. Hasta la fecha, puedo decir que has tomado las decisiones correctas. De ahora en adelante, tus acciones determinarán si esto continúa siendo así.', 0),
(@ID, 'esMX', 'Has tomado una decisión. Hasta la fecha, puedo decir que has tomado las decisiones correctas. De ahora en adelante, tus acciones determinarán si esto continúa siendo así.', 0);
-- 3375 Otra ampolla
-- https://es.classic.wowhead.com/quest=3375
SET @ID := 3375;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para hacer otra ampolla, necesito una poción de maná, un trozo de carbón y un poco de néctar dulce.$B$BEso, y aparentemente mucha paciencia.', 0),
(@ID, 'esMX', 'Para hacer otra ampolla, necesito una poción de maná, un trozo de carbón y un poco de néctar dulce.$B$BEso, y aparentemente mucha paciencia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gEl poderoso aventurero:La poderosa aventurera; cumple. ¡Hurra por mí! Por cierto, mentí, tenía otro frasco. Ungh, tómalo.$B$B¡¿Bueno, que esperabas?! "¡Oh, toma otro! ¡Soy sólo un tonto que no tiene nada mejor que hacer que entregar dispositivos mágicos de comunicación a los aventureros!" Sin embargo, ten la seguridad de que lo que me has dado será suficiente para convertirlo en otro frasco cuando vuelvas a perderlo.$B$BPor favor, demuéstrame que estoy equivocado y no pierdas el nuevo, ¿de acuerdo?', 0),
(@ID, 'esMX', '$gEl poderoso aventurero:La poderosa aventurera; cumple. ¡Hurra por mí! Por cierto, mentí, tenía otro frasco. Ungh, tómalo.$B$B¡¿Bueno, que esperabas?! "¡Oh, toma otro! ¡Soy sólo un tonto que no tiene nada mejor que hacer que entregar dispositivos mágicos de comunicación a los aventureros!" Sin embargo, ten la seguridad de que lo que me has dado será suficiente para convertirlo en otro frasco cuando vuelvas a perderlo.$B$BPor favor, demuéstrame que estoy equivocado y no pierdas el nuevo, ¿de acuerdo?', 0);
-- 3377 El rezo a Elune
-- https://es.classic.wowhead.com/quest=3377
SET @ID := 3377;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Permíteme terminar mi historia.', 0),
(@ID, 'esMX', 'Permíteme terminar mi historia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He aceptado mi destino, pero debes encontrar el rezo.', 0),
(@ID, 'esMX', 'He aceptado mi destino, pero debes encontrar el rezo.', 0);
-- 3378 El rezo a Elune
-- https://es.classic.wowhead.com/quest=3378
SET @ID := 3378;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae al Templo de la Luna, $n?', 0),
(@ID, 'esMX', '¿Qué te trae al Templo de la Luna, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Elune te sonríe, $n; le has devuelto un alma perdida. Acepta esto en prueba de nuestra gratitud.', 0),
(@ID, 'esMX', 'Elune te sonríe, $n; le has devuelto un alma perdida. Acepta esto en prueba de nuestra gratitud.', 0);
