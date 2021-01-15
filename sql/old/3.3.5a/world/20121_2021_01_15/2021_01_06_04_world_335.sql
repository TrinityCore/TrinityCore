-- 1197 La llama sacra
-- https://es.classic.wowhead.com/quest=1197
SET @ID := 1197;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy deseando tener la pezuña partida en mis manos. ¿Ya la has conseguido?', 0),
(@ID, 'esMX', 'Estoy deseando tener la pezuña partida en mis manos. ¿Ya la has conseguido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siento una extraña fuerza que emana de la pezuña... Confío en que, tras haberla analizado, descubramos nuevos y sorprendentes datos acerca de los centauros.$B$BMuchas gracias, $n. Y ahora, si me disculpas, tengo que empezar a descifrar los misterios que me has traído.', 0),
(@ID, 'esMX', 'Siento una extraña fuerza que emana de la pezuña... Confío en que, tras haberla analizado, descubramos nuevos y sorprendentes datos acerca de los centauros.$B$BMuchas gracias, $n. Y ahora, si me disculpas, tengo que empezar a descifrar los misterios que me has traído.', 0);
-- 1200 La vileza de Brazanegra
-- https://es.classic.wowhead.com/quest=1200
SET @ID := 1200;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El tiempo es un valioso bien, $c.$B$BMi papel aquí en Darnassus consiste en garantizar que los Alba Argenta prosperan y que se neutralizan las malvadas tropas que invaden Kalimdor.$B$BDime rápidamente a qué vienes o sigue tu camino.', 0),
(@ID, 'esMX', 'El tiempo es un valioso bien, $c.$B$BMi papel aquí en Darnassus consiste en garantizar que los Alba Argenta prosperan y que se neutralizan las malvadas tropas que invaden Kalimdor.$B$BDime rápidamente a qué vienes o sigue tu camino.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Kelris lleva bastante tiempo evitándome.$B$BParece que cada vez que el mal se manifiesta por estos lares, Kelris hubiera tenido algo que ver. Durante algún tiempo lo dimos por muerto o desaparecido.$B$BPero esto encaja perfectamente. Al poner fin a su reinado has salvado las vidas de muchos inocentes.$B$B¡Por la Luz que nos guía! ¡Sacrificar a alguien a un servidor de un dios antiguo para el beneficio personal no entra en los límites de lo reprobable!$B$BNos has hecho un gran favor, $n. Me inclino ante ti en nombre de los Alba Argenta.', 0),
(@ID, 'esMX', 'Kelris lleva bastante tiempo evitándome.$B$BParece que cada vez que el mal se manifiesta por estos lares, Kelris hubiera tenido algo que ver. Durante algún tiempo lo dimos por muerto o desaparecido.$B$BPero esto encaja perfectamente. Al poner fin a su reinado has salvado las vidas de muchos inocentes.$B$B¡Por la Luz que nos guía! ¡Sacrificar a alguien a un servidor de un dios antiguo para el beneficio personal no entra en los límites de lo reprobable!$B$BNos has hecho un gran favor, $n. Me inclino ante ti en nombre de los Alba Argenta.', 0);
-- 1201 Los espías de Theramore
-- https://es.classic.wowhead.com/quest=1201
SET @ID := 1201;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste a los infiltrados, $n?', 0),
(@ID, 'esMX', '¿Encontraste a los infiltrados, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo. Sus infiltradores son buenos, ¡pero no lo suficiente para escapar al ojo vigilante de la Horda!', 0),
(@ID, 'esMX', 'Buen trabajo. Sus infiltradores son buenos, ¡pero no lo suficiente para escapar al ojo vigilante de la Horda!', 0);
-- 1202 El puerto de Theramore
-- https://es.classic.wowhead.com/quest=1202
SET @ID := 1202;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste los documentos, $n? Contienen información vital para la estabilidad de la Alianza y, por tanto, vital para la seguridad de la Horda.', 0),
(@ID, 'esMX', '¿Encontraste los documentos, $n? Contienen información vital para la estabilidad de la Alianza y, por tanto, vital para la seguridad de la Horda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Y no era una misión fácil. Pero nuestros superiores valoran muchísimo los documentos que has conseguido.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Y no era una misión fácil. Pero nuestros superiores valoran muchísimo los documentos que has conseguido.', 0);
-- 1205 Lodomuerto
-- https://es.classic.wowhead.com/quest=1205
SET @ID := 1205;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes el diente de Lodomuerto, $n? ¿Has acabado con los sufrimientos de la criatura?', 0),
(@ID, 'esMX', '¿Tienes el diente de Lodomuerto, $n? ¿Has acabado con los sufrimientos de la criatura?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n.$B$BSeguro que la caza no fue fácil, pero me alegra saber que has puesto fin al sufrimiento de la pobre bestia.', 0),
(@ID, 'esMX', 'Muy bien, $n.$B$BSeguro que la caza no fue fácil, pero me alegra saber que has puesto fin al sufrimiento de la pobre bestia.', 0);
-- 1238 El informe perdido
-- https://es.classic.wowhead.com/quest=1238
SET @ID := 1238;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Nuestro agente, Marg Ojonocturno, se encontraba fuera de Theramore. Tenía el cometido de espiar la ciudad.$B$BEste es su último informe... y por lo que dices, será de verdad el último, pues temo que Marg encontrara su final en el pantano...', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Nuestro agente, Marg Ojonocturno, se encontraba fuera de Theramore. Tenía el cometido de espiar la ciudad.$B$BEste es su último informe... y por lo que dices, será de verdad el último, pues temo que Marg encontrara su final en el pantano...', 0);
-- 1239 La cabeza cercenada
-- https://es.classic.wowhead.com/quest=1239
SET @ID := 1239;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo más que comunicarme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo más que comunicarme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esta es la cabeza de Marg Ojonocturno! Tal y como temía, está muerto.$B$B¡Mira la herida que tiene en el cuello! ¿Podría haberla causado un arma, o quizás nuestro agente murió a manos de una bestia?$B$BEs un misterio que debemos resolver, $n. ¡Debemos descubrir si Marg encontró la muerte a manos de la Alianza!', 0),
(@ID, 'esMX', '¡Esta es la cabeza de Marg Ojonocturno! Tal y como temía, está muerto.$B$B¡Mira la herida que tiene en el cuello! ¿Podría haberla causado un arma, o quizás nuestro agente murió a manos de una bestia?$B$BEs un misterio que debemos resolver, $n. ¡Debemos descubrir si Marg encontró la muerte a manos de la Alianza!', 0);
-- 1240 El trol médico brujo
-- https://es.classic.wowhead.com/quest=1240
SET @ID := 1240;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Percibo un espíritu iracundo al mirarte, $ghermano:hermana;. ¿Qué te trae a Kin\'weelay?', 0),
(@ID, 'esMX', 'Percibo un espíritu iracundo al mirarte, $ghermano:hermana;. ¿Qué te trae a Kin\'weelay?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ya veo... El espíritu de este orco está ligado a nuestro mundo; hierve de rabia por un asunto que dejó sin concluir.$B$BBien, hablemos con este iracundo orco...', 0),
(@ID, 'esMX', 'Ah, ya veo... El espíritu de este orco está ligado a nuestro mundo; hierve de rabia por un asunto que dejó sin concluir.$B$BBien, hablemos con este iracundo orco...', 0);
 -- 1251 El escudo negro
-- https://es.classic.wowhead.com/quest=1251
SET @ID := 1251;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es eso que tienes ahí, $n? ¿Algo de los restos de la Posada Reposo Umbrío?', 0),
(@ID, 'esMX', '¿Qué es eso que tienes ahí, $n? ¿Algo de los restos de la Posada Reposo Umbrío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entiendo que los humanos tienen gustos de decoración un poco extraños pero... ¿usarían un simple escudo de hierro para adornar una chimenea? Quizás ese escudo fue colocado allí por quienes quemaron la posada.$B$B¿Será una advertencia? ¿Será una amenaza?', 0),
(@ID, 'esMX', 'Entiendo que los humanos tienen gustos de decoración un poco extraños pero... ¿usarían un simple escudo de hierro para adornar una chimenea? Quizás ese escudo fue colocado allí por quienes quemaron la posada.$B$B¿Será una advertencia? ¿Será una amenaza?', 0);
-- 1261 Las declaraciones de Marg
-- https://es.classic.wowhead.com/quest=1261
SET @ID := 1261;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿averiguaste qué suerte corrió Marg?', 0),
(@ID, 'esMX', '$n, ¿averiguaste qué suerte corrió Marg?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Y este colgante lo llevaba un soldado de Ventormenta??$B$BGracias, $n. Has resuelto el misterio de la muerte de Marg. Pero este colgante es un nuevo misterio que debemos resolver... pues podría tener funestas consecuencias para la Alianza y para la Horda.', 0),
(@ID, 'esMX', '¿Y este colgante lo llevaba un soldado de Ventormenta??$B$BGracias, $n. Has resuelto el misterio de la muerte de Marg. Pero este colgante es un nuevo misterio que debemos resolver... pues podría tener funestas consecuencias para la Alianza y para la Horda.', 0);
-- 1262 Informa a Zor
-- https://es.classic.wowhead.com/quest=1262
SET @ID := 1262;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Viajaste desde el poblado Murohelecho en el Marjal Revolcafango? ¿Cómo le va a Nazeer y cómo le va a sus esfuerzos en el pantano?', 0),
(@ID, 'esMX', '¿Viajaste desde el poblado Murohelecho en el Marjal Revolcafango? ¿Cómo le va a Nazeer y cómo le va a sus esfuerzos en el pantano?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este colgante fue elaborado con gran habilidad y precisión, $n. Ningún orco codiciaría tal joya...$B$BPero muchos humanos lo harían.$B$BHaré que estudien este colgante. Esperemos que, con el tiempo, se nos revelen sus misterios.', 0),
(@ID, 'esMX', 'Este colgante fue elaborado con gran habilidad y precisión, $n. Ningún orco codiciaría tal joya...$B$BPero muchos humanos lo harían.$B$BHaré que estudien este colgante. Esperemos que, con el tiempo, se nos revelen sus misterios.', 0);
-- 1268 Huellas de pezuñas sospechosas
-- https://es.classic.wowhead.com/quest=1268
SET @ID := 1268;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Huellas pezuñales... Podrían haber sido los jabaespines, supongo. O incluso los centauros. Su presencia en Los Baldíos no es insignificante pero para cometer este acto...$B$BNo te lo conté, pero no solo quemaron la posada... La mujer y el hijo del dueño fueron asesinados. Mal asunto, mal asunto.$B$BEn fin, voy a mandar igualmente a Kagoro a seguir el rastro de esas huellas.', 0),
(@ID, 'esMX', 'Huellas pezuñales... Podrían haber sido los jabaespines, supongo. O incluso los centauros. Su presencia en Los Baldíos no es insignificante pero para cometer este acto...$B$BNo te lo conté, pero no solo quemaron la posada... La mujer y el hijo del dueño fueron asesinados. Mal asunto, mal asunto.$B$BEn fin, voy a mandar igualmente a Kagoro a seguir el rastro de esas huellas.', 0);
-- 1269 Teniente Paval Reethe
-- https://es.classic.wowhead.com/quest=1269
SET @ID := 1269;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado alguna pista sobre lo que ocurrió en la Posada Reposo Umbrío?', 0),
(@ID, 'esMX', '¿Has encontrado alguna pista sobre lo que ocurrió en la Posada Reposo Umbrío?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Conozco a este humano, Paval Reethe. Es patético, incluso para ser humano. Abandonó a sus compañeros y ahora se esconde en el bosque.$B$BEnvié a Ogron a buscarle. Algunos hombres creen que ha estado robando nuestros suministros. Creo que vi a Ogron dirigiéndose hacia el sureste.', 0),
(@ID, 'esMX', 'Conozco a este humano, Paval Reethe. Es patético, incluso para ser humano. Abandonó a sus compañeros y ahora se esconde en el bosque.$B$BEnvié a Ogron a buscarle. Algunos hombres creen que ha estado robando nuestros suministros. Creo que vi a Ogron dirigiéndose hacia el sureste.', 0);
-- 1270 La fuga de Apestoso
-- https://es.classic.wowhead.com/quest=1270
SET @ID := 1270;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vino Apestoso con las hierbas que le pedí y me dijo que le habías ayudado a salir de un aprieto. ¡Bien hecho! ¡$gUn amigo:Una amiga; de Apestoso es $gamigo mío:amiga mía;!$B$BPoco antes de dirigirse hacia el sur, hacia el pantano, me pidió que te diera esto si te veía.', 0),
(@ID, 'esMX', 'Vino Apestoso con las hierbas que le pedí y me dijo que le habías ayudado a salir de un aprieto. ¡Bien hecho! ¡$gUn amigo:Una amiga; de Apestoso es $gamigo mío:amiga mía;!$B$BPoco antes de dirigirse hacia el sur, hacia el pantano, me pidió que te diera esto si te veía.', 0);
-- 1273 El interrogatorio de Reethe
-- https://es.classic.wowhead.com/quest=1273
SET @ID := 1273;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste a Reethe?', 0),
(@ID, 'esMX', '¿Encontraste a Reethe?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm. Que Reethe no vaya a seguir deambulando por el pantano es una buena noticia, pero es una pena que los humanos sean tan débiles... que no pudiera recuperarse de una mínima herida de flecha, es una pena.$B$BParece que este camino no nos ha ayudado a resolver el misterio. Debemos probar por otro lado.', 0),
(@ID, 'esMX', 'Mm. Que Reethe no vaya a seguir deambulando por el pantano es una buena noticia, pero es una pena que los humanos sean tan débiles... que no pudiera recuperarse de una mínima herida de flecha, es una pena.$B$BParece que este camino no nos ha ayudado a resolver el misterio. Debemos probar por otro lado.', 0);
-- 1276 El escudo negro
-- https://es.classic.wowhead.com/quest=1276
SET @ID := 1276;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $c, ¿puedo ayudarte en algo?', 0),
(@ID, 'esMX', 'Hola, $c, ¿puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, tienes mucha razón. Este escudo lo hice yo.$B$BPero me temo que no puedo decirte mucho más, $n. Forjo tantos escudos y armaduras diferentes que no puedo seguirles la pista a todos.', 0),
(@ID, 'esMX', 'Sí, tienes mucha razón. Este escudo lo hice yo.$B$BPero me temo que no puedo decirte mucho más, $n. Forjo tantos escudos y armaduras diferentes que no puedo seguirles la pista a todos.', 0);
-- 1282 Le llaman Jim Sonrisas
-- https://es.classic.wowhead.com/quest=1282
SET @ID := 1282;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'James Hyal es su auténtico nombre. Abrió una posada en el límite de Los Baldíos. Quería crear un lugar agradable en el que los viajeros pudieran descansar...$B$BPuede que hiciera todo demasiado a lo grande, pero el caso es que la posada fue muy bien durante un tiempo. Y entonces perdimos el control de los caminos del pantano y llegaron los ogros.$B$BJames era demasiado cabezota para dejar su sueño atrás y buscar la seguridad de nuestros muros y... la Posada Reposo Umbrío fue arrasada por un incendio. Estamos investigando el suceso, pero hasta ahora no hemos tenido mucha suerte. Si quieres ayudarnos, ve a ver si encuentras algo entre los escombros.', 0),
(@ID, 'esMX', 'James Hyal es su auténtico nombre. Abrió una posada en el límite de Los Baldíos. Quería crear un lugar agradable en el que los viajeros pudieran descansar...$B$BPuede que hiciera todo demasiado a lo grande, pero el caso es que la posada fue muy bien durante un tiempo. Y entonces perdimos el control de los caminos del pantano y llegaron los ogros.$B$BJames era demasiado cabezota para dejar su sueño atrás y buscar la seguridad de nuestros muros y... la Posada Reposo Umbrío fue arrasada por un incendio. Estamos investigando el suceso, pero hasta ahora no hemos tenido mucha suerte. Si quieres ayudarnos, ve a ver si encuentras algo entre los escombros.', 0);
-- 1301 James Hyal
-- https://es.classic.wowhead.com/quest=1301
SET @ID := 1301;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿James? Oh, se fue hace algún tiempo.$B$BSupongo que sintió una nueva oleada de patriotismo. No es difícil entender por qué lo hizo. Con tanta locura en Lordaeron, muchos fueron los que se unieron a Jaina Valiente cuando cruzó el mar.', 0),
(@ID, 'esMX', '¿James? Oh, se fue hace algún tiempo.$B$BSupongo que sintió una nueva oleada de patriotismo. No es difícil entender por qué lo hizo. Con tanta locura en Lordaeron, muchos fueron los que se unieron a Jaina Valiente cuando cruzó el mar.', 0);
-- 1321 El escudo negro
-- https://es.classic.wowhead.com/quest=1321
SET @ID := 1321;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $c?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un buen escudo. Muy fuerte, pesado, bueno. Pero Do\'gol no necesita. Yo hago escudos, no los compro, $n.$B$BDeberías saberlo.', 0),
(@ID, 'esMX', 'Es un buen escudo. Muy fuerte, pesado, bueno. Pero Do\'gol no necesita. Yo hago escudos, no los compro, $n.$B$BDeberías saberlo.', 0);
-- 1322 El escudo negro
-- https://es.classic.wowhead.com/quest=1322
SET @ID := 1322;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste las glándulas de las arañas?', 0),
(@ID, 'esMX', '¿Conseguiste las glándulas de las arañas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me gustan esas arañas que son tan grandes que no puedo sentarme en ellas para aplastarlas.$B$BGracias por conseguírmelas, $n. Ahora las abriré y verteré su contenido en el escudo...', 0),
(@ID, 'esMX', 'No me gustan esas arañas que son tan grandes que no puedo sentarme en ellas para aplastarlas.$B$BGracias por conseguírmelas, $n. Ahora las abriré y verteré su contenido en el escudo...', 0);
-- 1323 El escudo negro
-- https://es.classic.wowhead.com/quest=1323
SET @ID := 1323;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Mosarn? Me suena de algo... Pero no sé de qué. Quizás me venga más tarde.$B$BProbablemente no es importante. Un escudo puede venir de cualquier parte y no significar nada...', 0),
(@ID, 'esMX', '¿Mosarn? Me suena de algo... Pero no sé de qué. Quizás me venga más tarde.$B$BProbablemente no es importante. Un escudo puede venir de cualquier parte y no significar nada...', 0);
-- 1358 Muestra para Helbrim
-- https://es.classic.wowhead.com/quest=1358
SET @ID := 1358;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes un paquete para mí?', 0),
(@ID, 'esMX', '¿Tienes un paquete para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, muy bien. Si los informes iniciales son ciertos, la toxicidad de estos corazones podría llevarnos a progresar en nuestro conocimiento sobre venenos.$B$BTe agradezco mucho la entrega, $n. Te mereces tu recompensa.', 0),
(@ID, 'esMX', 'Ah, muy bien. Si los informes iniciales son ciertos, la toxicidad de estos corazones podría llevarnos a progresar en nuestro conocimiento sobre venenos.$B$BTe agradezco mucho la entrega, $n. Te mereces tu recompensa.', 0);
-- 1359 Una entrega de Zinge
-- https://es.classic.wowhead.com/quest=1359
SET @ID := 1359;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí, las muestras de corazón de las que habló Renferrel. Me muero por experimentar con esto... encontrar nuevas formas de toxinas siempre resulta de gran interés para la Sociedad Real de Boticarios.', 0),
(@ID, 'esMX', 'Ah, sí, las muestras de corazón de las que habló Renferrel. Me muero por experimentar con esto... encontrar nuevas formas de toxinas siempre resulta de gran interés para la Sociedad Real de Boticarios.', 0);
-- 1361 Regthar Portamorta
-- https://es.classic.wowhead.com/quest=1361
SET @ID := 1361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Observo que tu tarea está inconclusa, $n. ¿Debo informar a Sharlindra de tu ineptitud?', 0),
(@ID, 'esMX', 'Observo que tu tarea está inconclusa, $n. ¿Debo informar a Sharlindra de tu ineptitud?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, me encargo del reclutamiento. La misión nos llevará a Desolace, a luchar contra los centauros. Seré breve para que puedas empezar cuanto antes.', 0),
(@ID, 'esMX', 'Sí, me encargo del reclutamiento. La misión nos llevará a Desolace, a luchar contra los centauros. Seré breve para que puedas empezar cuanto antes.', 0);
-- 1362 Los Kolkar de Desolace
-- https://es.classic.wowhead.com/quest=1362
SET @ID := 1362;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te envía Regthar? Entonces has venido a cazar centauros. Bien.$B$BEspero que hayas venido $gdescansado:descansada;. No sé cómo acabará nuestra campaña contra los centauros, pero sé que la lucha será larga.$B$BToma asiento y escucha.', 0),
(@ID, 'esMX', '¿Te envía Regthar? Entonces has venido a cazar centauros. Bien.$B$BEspero que hayas venido $gdescansado:descansada;. No sé cómo acabará nuestra campaña contra los centauros, pero sé que la lucha será larga.$B$BToma asiento y escucha.', 0);
-- 1365 Khan Dez'hepah
-- https://es.classic.wowhead.com/quest=1365
SET @ID := 1365;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has derrotado al khan Dez\'hepah?', 0),
(@ID, 'esMX', '$n, ¿has derrotado al khan Dez\'hepah?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho. Esa rápida acción contra los Kolkar es una demostración efectiva de nuestra fuerza, y eso es precisamente lo que mejor entienden los centauros.$B$BLa muerte del khan Kolkar no solo llevará confusión a su clan, también desconcertará a los demás.', 0),
(@ID, 'esMX', 'Bien hecho. Esa rápida acción contra los Kolkar es una demostración efectiva de nuestra fuerza, y eso es precisamente lo que mejor entienden los centauros.$B$BLa muerte del khan Kolkar no solo llevará confusión a su clan, también desconcertará a los demás.', 0);
-- 1366 Colección de orejas
-- https://es.classic.wowhead.com/quest=1366
SET @ID := 1366;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu colección de orejas, $n? ¿Está grandota?', 0),
(@ID, 'esMX', '¿Cómo va tu colección de orejas, $n? ¿Está grandota?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A estas alturas, los centauros deben de conocer tu nombre. Sé que lo conocen y lo respetan, y que incluso lo temen. Y de la misma forma, conocen y temen el estandarte que portas.$B$BEl estandarte de la Horda.', 0),
(@ID, 'esMX', 'A estas alturas, los centauros deben de conocer tu nombre. Sé que lo conocen y lo respetan, y que incluso lo temen. Y de la misma forma, conocen y temen el estandarte que portas.$B$BEl estandarte de la Horda.', 0);
-- 1369 Lágrimas rotas
-- https://es.classic.wowhead.com/quest=1369
SET @ID := 1369;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Lágrimas destruidas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 1372 El suero de la verdad
-- https://es.classic.wowhead.com/quest=1372
SET @ID := 1372;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Zraedus me estaba hablando de ese entrometido infiltrador justo antes de que llegaras.$B$BEs un problema bastante serio. Lo último que necesitamos es un metomentodo husmeando por el Refugio de los Mendigos.$B$BEstoy seguro de que los orcos de Rocal estarán impacientes por escuchar lo que les tenga que contar nuestro amiguito. Y como son nuestros aliados, ejem, tenemos que ayudarles a conseguir cualquier información que se le pueda sacar al humano.$B$BColabora conmigo, $n y conseguiremos llevar un suero de la verdad a Rocal.$B$B¡Por la Horda!$B$B¿Se dice así?', 0),
(@ID, 'esMX', 'Zraedus me estaba hablando de ese entrometido infiltrador justo antes de que llegaras.$B$BEs un problema bastante serio. Lo último que necesitamos es un metomentodo husmeando por el Refugio de los Mendigos.$B$BEstoy seguro de que los orcos de Rocal estarán impacientes por escuchar lo que les tenga que contar nuestro amiguito. Y como son nuestros aliados, ejem, tenemos que ayudarles a conseguir cualquier información que se le pueda sacar al humano.$B$BColabora conmigo, $n y conseguiremos llevar un suero de la verdad a Rocal.$B$B¡Por la Horda!$B$B¿Se dice así?', 0);
-- 1383 El suero de la verdad
-- https://es.classic.wowhead.com/quest=1383
SET @ID := 1383;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ese Infiltrado seguramente... se... abrirá... después de que beba mi suero especial. ¡Jaja!$B$BLos ingredientes necesarios no son fáciles de conseguir. Las Panteras Sombrías son comunes en el Pantano, pero recolectar suficientes corazones para nuestro propósito puede ser abrumador. Y el Señor del Lodo puede ser una bestia tan quisquillosa.', 0),
(@ID, 'esMX', 'Ese Infiltrado seguramente... se... abrirá... después de que beba mi suero especial. ¡Jaja!$B$BLos ingredientes necesarios no son fáciles de conseguir. Las Panteras Sombrías son comunes en el Pantano, pero recolectar suficientes corazones para nuestro propósito puede ser abrumador. Y el Señor del Lodo puede ser una bestia tan quisquillosa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espléndido, $n! Y justo a tiempo también. Por lo que me dice Zraedus, el Infiltrado se ha recuperado de sus heridas y está listo para ser interrogado por los orcos.$B$BDame un momento para preparar el potingue, me refiero a preparar el suero de la verdad.', 0),
(@ID, 'esMX', '¡Espléndido, $n! Y justo a tiempo también. Por lo que me dice Zraedus, el Infiltrado se ha recuperado de sus heridas y está listo para ser interrogado por los orcos.$B$BDame un momento para preparar el potingue, me refiero a preparar el suero de la verdad.', 0);
-- 1388 El suero de la verdad
-- https://es.classic.wowhead.com/quest=1388
SET @ID := 1388;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que hayas demostrado tu utilidad para nuestro querido amigo, el boticario Faustin.', 0),
(@ID, 'esMX', 'Espero que hayas demostrado tu utilidad para nuestro querido amigo, el boticario Faustin.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sabía que al viejo Faustin se le ocurriría algo bueno! Has sido de gran ayuda, sin duda.$B$BAhora vayamos al grano, ¿de acuerdo?', 0),
(@ID, 'esMX', '¡Sabía que al viejo Faustin se le ocurriría algo bueno! Has sido de gran ayuda, sin duda.$B$BAhora vayamos al grano, ¿de acuerdo?', 0);
