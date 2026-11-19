-- 432 ¡Malditos troggs!
-- https://es.classic.wowhead.com/quest=432
SET @ID := 432;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto me enoja mucho! Grrr...', 0),
(@ID, 'esMX', '¡Esto me enoja mucho! Grrr...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, ahora me siento un poco mejor...$B$B¡Pero no conseguiré paz hasta que estén todos muertos! ¡Todos ellos!', 0),
(@ID, 'esMX', 'Vaya, ahora me siento un poco mejor...$B$B¡Pero no conseguiré paz hasta que estén todos muertos! ¡Todos ellos!', 0);
-- 433 El servidor público
-- https://es.classic.wowhead.com/quest=433
SET @ID := 433;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si podemos sacar a los troggs de la Cantera de Gol\'Bolar, será el primer paso de muchos que tendremos que emprender para librarnos de esta amenaza.', 0),
(@ID, 'esMX', 'Si podemos sacar a los troggs de la Cantera de Gol\'Bolar, será el primer paso de muchos que tendremos que emprender para librarnos de esta amenaza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un comienzo. Con suerte podremos aprovechar el momento y llevar a algunos montaraces para asegurar el área. Luego podremos comenzar a reconstruir nuestra infraestructura para que los mineros vuelvan al trabajo.$B$BGracias por tu ayuda, $n.', 0),
(@ID, 'esMX', 'Es un comienzo. Con suerte podremos aprovechar el momento y llevar a algunos montaraces para asegurar el área. Luego podremos comenzar a reconstruir nuestra infraestructura para que los mineros vuelvan al trabajo.$B$BGracias por tu ayuda, $n.', 0);
-- 434 El ataque
-- https://es.classic.wowhead.com/quest=434
SET @ID := 434;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $N? ¿Van las cosas bien con Tyrion? Me informó de la situación y lo ayudé a engañar a Marzon para que fuera al castillo.$B$BMarzon ha sido una espina clavada en el costado de muchas personas en Ventormenta; muchos de los cuales son amigos míos cercanos. Nadie se mete con mis amigos... no si saben lo que es saludable para ellos.$B$BEs una lástima que indirectamente esté haciendo un favor a Shaw y IV:7 mientras tanto. Bueno, no todos los planes son perfectos.', 0),
(@ID, 'esMX', '¿Sí, $N? ¿Van las cosas bien con Tyrion? Me informó de la situación y lo ayudé a engañar a Marzon para que fuera al castillo.$B$BMarzon ha sido una espina clavada en el costado de muchas personas en Ventormenta; muchos de los cuales son amigos míos cercanos. Nadie se mete con mis amigos... no si saben lo que es saludable para ellos.$B$BEs una lástima que indirectamente esté haciendo un favor a Shaw y IV:7 mientras tanto. Bueno, no todos los planes son perfectos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Entonces ya está? Bien. Muchísimas gracias por tu discreción, $n. Has demostrado tu gran valía en más de una ocasión. Me aseguraré de seguir de cerca tu progreso en la Alianza.$B$BNo te metas en líos.', 0),
(@ID, 'esMX', '¿Entonces ya está? Bien. Muchísimas gracias por tu discreción, $n. Has demostrado tu gran valía en más de una ocasión. Me aseguraré de seguir de cerca tu progreso en la Alianza.$B$BNo te metas en líos.', 0);
-- 435 Escolta a Erland
-- https://es.classic.wowhead.com/quest=435
SET @ID := 435;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. Temía que Erland hubiera perecido en Argénteos. Pero, gracias a ti, veo que sigue con vida.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. Temía que Erland hubiera perecido en Argénteos. Pero, gracias a ti, veo que sigue con vida.', 0);
-- 437 El Campo Muerto
-- https://es.classic.wowhead.com/quest=437
SET @ID := 437;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado a Latipesadilla, $n? ¡Nuestro éxito contra los Putrepellejo depende de su aniquilación!', 0),
(@ID, 'esMX', '¿Has derrotado a Latipesadilla, $n? ¡Nuestro éxito contra los Putrepellejo depende de su aniquilación!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me he enterado de tu exitoso asalto contra los Putrepellejo, $n, y esta esencia demuestra la muerte de Latipesadilla.$B$BHoy, la Plaga ha perdido terreno. Tu valía aumenta para los Renegados.', 0),
(@ID, 'esMX', 'Me he enterado de tu exitoso asalto contra los Putrepellejo, $n, y esta esencia demuestra la muerte de Latipesadilla.$B$BHoy, la Plaga ha perdido terreno. Tu valía aumenta para los Renegados.', 0);
-- 438 El Viejo Embarcadero
-- https://es.classic.wowhead.com/quest=438
SET @ID := 438;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En este barco hay una pila de cadáveres envueltos. Y, mirando hacia el este a través del Lago Lordamere, se puede ver un puerto en la Isla de Fenris.$B$BEl destino de esos cadáveres debe de ser la Isla de Fenris.', 0),
(@ID, 'esMX', 'En este barco hay una pila de cadáveres envueltos. Y, mirando hacia el este a través del Lago Lordamere, se puede ver un puerto en la Isla de Fenris.$B$BEl destino de esos cadáveres debe de ser la Isla de Fenris.', 0);
-- 439 Pistas de Putrepellejos
-- https://es.classic.wowhead.com/quest=439
SET @ID := 439;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Has regresado, así que supongo que tus investigaciones han tenido éxito.', 0),
(@ID, 'esMX', '$n. Has regresado, así que supongo que tus investigaciones han tenido éxito.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dices que este anillo lo llevaba una mujer asesinada recientemente?$B$BEl único sitio de donde se puede sacar un cadáver así es de las fosas comunes de Tirisfal. Los gnolls Putrepellejo deben de estar llevando esos cadáveres a la Isla de Fenris.', 0),
(@ID, 'esMX', '¿Dices que este anillo lo llevaba una mujer asesinada recientemente?$B$BEl único sitio de donde se puede sacar un cadáver así es de las fosas comunes de Tirisfal. Los gnolls Putrepellejo deben de estar llevando esos cadáveres a la Isla de Fenris.', 0);
-- 440 El anillo grabado
-- https://es.classic.wowhead.com/quest=440
SET @ID := 440;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Qué te trae de nuevo por Rémol?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Qué te trae de nuevo por Rémol?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Había una Deliah que vivía en Rémol no hace mucho. La enterraron en la fosa común pero, si lo que dices es cierto, los gnolls Putrepellejo deben de haber robado su cadáver para llevárselo a Argénteos.$B$BTenemos que destruir a los Putrepellejo, al igual que a toda la Plaga. Confío en que te estés encargando de eso.', 0),
(@ID, 'esMX', 'Había una Deliah que vivía en Rémol no hace mucho. La enterraron en la fosa común pero, si lo que dices es cierto, los gnolls Putrepellejo deben de haber robado su cadáver para llevárselo a Argénteos.$B$BTenemos que destruir a los Putrepellejo, al igual que a toda la Plaga. Confío en que te estés encargando de eso.', 0);
-- 441 Raleigh y Entrañas
-- https://es.classic.wowhead.com/quest=441
SET @ID := 441;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Nos conocemos?', 0),
(@ID, 'esMX', '¿Nos conocemos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, este anillo era de mi mujer. Compartió destino con todos los que cayeron en esta dura época. No siento nada por su muerte ni por la historia del secuestro de su cadáver.$B$BHace mucho tiempo que lo que sentía por ella se enfrió. Pero el deseo sigue quemando en mi corazón muerto, $n.$B$BDeseo de venganza.', 0),
(@ID, 'esMX', 'Sí, este anillo era de mi mujer. Compartió destino con todos los que cayeron en esta dura época. No siento nada por su muerte ni por la historia del secuestro de su cadáver.$B$BHace mucho tiempo que lo que sentía por ella se enfrió. Pero el deseo sigue quemando en mi corazón muerto, $n.$B$BDeseo de venganza.', 0);
-- 442 Asalto a la Isla de Fenris
-- https://es.classic.wowhead.com/quest=442
SET @ID := 442;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos permitir la presencia de la Plaga en Argénteos, $n. Vuelve a verme cuando tengas alguna prueba de la muerte de Thule.', 0),
(@ID, 'esMX', 'No podemos permitir la presencia de la Plaga en Argénteos, $n. Vuelve a verme cuando tengas alguna prueba de la muerte de Thule.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La muerte de Thule Corvozarpa fue un gran golpe, $n. Renferrel me dice que las energías que se liberaron cuando destruiste a Thule, se sintieron incluso en El Sepulcro.$B$BTus acciones resuenan en las filas de los Renegados. Tu valía crece ente nosotros.', 0),
(@ID, 'esMX', 'La muerte de Thule Corvozarpa fue un gran golpe, $n. Renferrel me dice que las energías que se liberaron cuando destruiste a Thule, se sintieron incluso en El Sepulcro.$B$BTus acciones resuenan en las filas de los Renegados. Tu valía crece ente nosotros.', 0);
-- 443 Icor de Putrepellejo
-- https://es.classic.wowhead.com/quest=443
SET @ID := 443;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el icor de Putrepellejo, $n?', 0),
(@ID, 'esMX', '¿Tienes el icor de Putrepellejo, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Este icor nos ayudará a entender la naturaleza de los Putrepellejo y quizás nos descubra sus debilidades...$B$B... si es que tienen alguna.', 0),
(@ID, 'esMX', 'Muy bien. Este icor nos ayudará a entender la naturaleza de los Putrepellejo y quizás nos descubra sus debilidades...$B$B... si es que tienen alguna.', 0);
-- 444 El origen de los Putrepellejos
-- https://es.classic.wowhead.com/quest=444
SET @ID := 444;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito una gran concentración para mis estudios. Espero que tu visita no sea frívola.', 0),
(@ID, 'esMX', 'Necesito una gran concentración para mis estudios. Espero que tu visita no sea frívola.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta sustancia está mezclada con poderosos hechizos, algunos de ellos no los había visto en mucho tiempo...$B$BUn momento, debo convocar un hechizo de adivinación...', 0),
(@ID, 'esMX', 'Esta sustancia está mezclada con poderosos hechizos, algunos de ellos no los había visto en mucho tiempo...$B$BUn momento, debo convocar un hechizo de adivinación...', 0);
-- 445 Entrega a Bosque de Argénteos
-- https://es.classic.wowhead.com/quest=445
SET @ID := 445;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae ante mí, $c?', 0),
(@ID, 'esMX', '¿Qué te trae ante mí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué bien que el boticario Johaan haya enviado los resultados de su investigación. Con tantas innovaciones aquí en el Bosque de Argénteos, casi me había olvidado de los hallazgos que llegan de Lordaeron y Claros de Tirisfal. ¡Ah! Esto me recuerda que tengo que hacer llegar estas muestras a Necrópolis lo antes posible.$B$BVaya, ya me he ido por las ramas, perdona... Prolonga tu estancia en el Bosque de Argénteos, $n. Sería muy útil tener a un $c en tan buena forma como tú por aquí.', 0),
(@ID, 'esMX', '¡Qué bien que el boticario Johaan haya enviado los resultados de su investigación. Con tantas innovaciones aquí en el Bosque de Argénteos, casi me había olvidado de los hallazgos que llegan de Lordaeron y Claros de Tirisfal. ¡Ah! Esto me recuerda que tengo que hacer llegar estas muestras a Necrópolis lo antes posible.$B$BVaya, ya me he ido por las ramas, perdona... Prolonga tu estancia en el Bosque de Argénteos, $n. Sería muy útil tener a un $c en tan buena forma como tú por aquí.', 0);
-- 446 Thule Corvozarpa
-- https://es.classic.wowhead.com/quest=446
SET @ID := 446;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Qué te ha dicho Bethor?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Qué te ha dicho Bethor?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este pergamino está imbuido de poderosa magia. Nunca he usado fuerzas así en una poción... será una mezcla muy poderosa y debería servirte si atacas a Thule en su fortaleza de la Isla de Fenris.', 0),
(@ID, 'esMX', 'Este pergamino está imbuido de poderosa magia. Nunca he usado fuerzas así en una poción... será una mezcla muy poderosa y debería servirte si atacas a Thule en su fortaleza de la Isla de Fenris.', 0);
-- 447 Una fórmula mortal
-- https://es.classic.wowhead.com/quest=447
SET @ID := 447;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. ¿Qué te trae a hablar con la Sociedad Real de Boticarios?', 0),
(@ID, 'esMX', 'Saludos, $c. ¿Qué te trae a hablar con la Sociedad Real de Boticarios?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Qué amable por parte del boticario Renferrel haberte enviado, $n. Estas muestras serán sin duda útiles para nuestra causa. Comenzaré a estudiar sus propiedades tóxicas y contaminantes ahora mismo.', 0),
(@ID, 'esMX', 'Qué amable por parte del boticario Renferrel haberte enviado, $n. Estas muestras serán sin duda útiles para nuestra causa. Comenzaré a estudiar sus propiedades tóxicas y contaminantes ahora mismo.', 0);
-- 448 Preséntate ante Hadrec
-- https://es.classic.wowhead.com/quest=448
SET @ID := 448;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si lo que Bethor dice es cierto, hay que encargarse rápidamente de Thule Corvozarpa.$B$BPara ayudarte, puedes coger algo de nuestro arsenal...', 0),
(@ID, 'esMX', 'Si lo que Bethor dice es cierto, hay que encargarse rápidamente de Thule Corvozarpa.$B$BPara ayudarte, puedes coger algo de nuestro arsenal...', 0);
-- 449 El informe de los Mortacechadores
-- https://es.classic.wowhead.com/quest=449
SET @ID := 449;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has descubierto lo que ha pasado con los Mortacechadores?', 0),
(@ID, 'esMX', '¿Has descubierto lo que ha pasado con los Mortacechadores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No había contado con el nivel de presencia de la Plaga que vimos en el Bosque de Argénteos, ni con los problemas que nuestros Mortacechadores tuvieron en sus misiones de exploración.$B$BTu ayuda a nuestros Mortacechadores ha sido inapreciable, $n. Y te recomendaré.', 0),
(@ID, 'esMX', 'No había contado con el nivel de presencia de la Plaga que vimos en el Bosque de Argénteos, ni con los problemas que nuestros Mortacechadores tuvieron en sus misiones de exploración.$B$BTu ayuda a nuestros Mortacechadores ha sido inapreciable, $n. Y te recomendaré.', 0);
-- 450 Una fórmula mortal
-- https://es.classic.wowhead.com/quest=450
SET @ID := 450;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has regresado, $n.', 0),
(@ID, 'esMX', 'Veo que has regresado, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡El Diario del boticario Berard! Eres muy valiente, $n. Ahora veamos lo que estaba haciendo Berard antes de volverse loco...', 0),
(@ID, 'esMX', '¡El Diario del boticario Berard! Eres muy valiente, $n. Ahora veamos lo que estaba haciendo Berard antes de volverse loco...', 0);
-- 451 Una fórmula mortal
-- https://es.classic.wowhead.com/quest=451
SET @ID := 451;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué te trae de nuevo a Entrañas, $n?', 0),
(@ID, 'esMX', '¿Qué te trae de nuevo a Entrañas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Perder a Berard ha sido un duro golpe para la Sociedad Real de Boticarios. Pero gracias a lo que has hecho y a la diligente investigación del boticario Renferrel, los estudios de Berard serán de mucha utilidad para la Dama Oscura.$B$BEstamos a punto de conseguir algo grande, $n. Si no tuvieras tanto talento para el combate, intentaría reclutarte para la Sociedad.', 0),
(@ID, 'esMX', 'Perder a Berard ha sido un duro golpe para la Sociedad Real de Boticarios. Pero gracias a lo que has hecho y a la diligente investigación del boticario Renferrel, los estudios de Berard serán de mucha utilidad para la Dama Oscura.$B$BEstamos a punto de conseguir algo grande, $n. Si no tuvieras tanto talento para el combate, intentaría reclutarte para la Sociedad.', 0);
-- 452 La emboscada de Aldea Piroleña
-- https://es.classic.wowhead.com/quest=452
SET @ID := 452;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Luchas como un verdadero discípulo de la Dama Oscura, $n. Con la destrucción del Consejo, quizás podamos conseguir el control de esta ciudad de una vez por todas y expulsar a Arugal del Castillo de Colmillo Oscuro. ¡Te aplaudo!', 0),
(@ID, 'esMX', 'Luchas como un verdadero discípulo de la Dama Oscura, $n. Con la destrucción del Consejo, quizás podamos conseguir el control de esta ciudad de una vez por todas y expulsar a Arugal del Castillo de Colmillo Oscuro. ¡Te aplaudo!', 0);
-- 460 Descansar en piezas
-- https://es.classic.wowhead.com/quest=460
SET @ID := 460;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta tumba se ha cavado a toda prisa.', 0),
(@ID, 'esMX', 'Esta tumba se ha cavado a toda prisa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. Temía que los gnolls hubieran destruido mi cuerpo. Me alegra saber que no es así.', 0),
(@ID, 'esMX', 'Gracias, $n. Temía que los gnolls hubieran destruido mi cuerpo. Me alegra saber que no es así.', 0);
-- 461 El nicho oculto
-- https://es.classic.wowhead.com/quest=461
SET @ID := 461;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Aquí es! Acércame más...', 0),
(@ID, 'esMX', '¡Aquí es! Acércame más...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí estamos, está abierto. Déjame aquí. Pasé los mejores días de mi vida aquí y el pensamiento de descansar entre sus muros me reconforta.$B$BAsegúrate de cerrar bien el nicho, no quiero que esos Putrepellejos me encuentren.$B$BOh, y acepta esto. Te lo has ganado.', 0),
(@ID, 'esMX', 'Aquí estamos, está abierto. Déjame aquí. Pasé los mejores días de mi vida aquí y el pensamiento de descansar entre sus muros me reconforta.$B$BAsegúrate de cerrar bien el nicho, no quiero que esos Putrepellejos me encuentren.$B$BOh, y acepta esto. Te lo has ganado.', 0);
