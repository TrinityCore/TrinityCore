-- 944 La Espada del Maestro
-- https://es.classic.wowhead.com/quest=944
SET @ID := 944;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La Espada del Maestro, $n$B$BVe allí y vuelve a hablar conmigo.', 0),
(@ID, 'esMX', 'La Espada del Maestro, $n$B$BVe allí y vuelve a hablar conmigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Martillo Crepuscular está en La Espada del Maestro?$B$BQué desventura.$B$BEl Señor de la Tierra que fue empalado en La Espada del Maestro lleva mucho tiempo muerto, pero eso no quiere decir que no queden aún trazas de su poder.$B$BEl Martillo Crepuscular debe de estar buscando ese poder.', 0),
(@ID, 'esMX', '¿El Martillo Crepuscular está en La Espada del Maestro?$B$BQué desventura.$B$BEl Señor de la Tierra que fue empalado en La Espada del Maestro lleva mucho tiempo muerto, pero eso no quiere decir que no queden aún trazas de su poder.$B$BEl Martillo Crepuscular debe de estar buscando ese poder.', 0);
-- 5321 El despertar
-- https://es.classic.wowhead.com/quest=5321
SET @ID := 5321;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha llegado Kerlonian?', 0),
(@ID, 'esMX', '¿Ha llegado Kerlonian?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Cómo me alegra que Kerlonian esté bien! Seguro que lo encontraré por aquí, durmiendo en cualquier esquina, ¿acierto?$B$BGracias por indicarle el camino, $n.', 0),
(@ID, 'esMX', '¡Cómo me alegra que Kerlonian esté bien! Seguro que lo encontraré por aquí, durmiendo en cualquier esquina, ¿acierto?$B$BGracias por indicarle el camino, $n.', 0);
-- 945 La fuga de Therylune
-- https://es.classic.wowhead.com/quest=945
SET @ID := 945;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿¿Que mi hermana estaba dónde?? Sé que a Therylune no le importa ensuciarse, ¡pero ir a La Espada del Maestro! Incluso para ella es un largo camino... y La Espada es un lugar malsano...$B$BEn fin, gracias, $n. Ha sido un detalle por tu parte informarme de que está bien.', 0),
(@ID, 'esMX', '¿¿Que mi hermana estaba dónde?? Sé que a Therylune no le importa ensuciarse, ¡pero ir a La Espada del Maestro! Incluso para ella es un largo camino... y La Espada es un lugar malsano...$B$BEn fin, gracias, $n. Ha sido un detalle por tu parte informarme de que está bien.', 0);
-- 731 El prospector despistado
-- https://es.classic.wowhead.com/quest=731
SET @ID := 731;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está vivo el prospector?', 0),
(@ID, 'esMX', '¿Está vivo el prospector?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a las estrellas el prospector Remtravel está bien! Te dije que era un poco despistado. No puedo creer que insistiera en quedarse allí con todas esas horribles criaturas al acecho.', 0),
(@ID, 'esMX', '¡Gracias a las estrellas el prospector Remtravel está bien! Te dije que era un poco despistado. No puedo creer que insistiera en quedarse allí con todas esas horribles criaturas al acecho.', 0);
-- 993 El maestro perdido
-- https://es.classic.wowhead.com/quest=993
SET @ID := 993;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estupendo! Terenthis ha encontrado a alguien que me ayude.$B$BY mira, una capa de Acechalunas...<tose> Ay... qué dolor. Gracias, $n.$B$BLos furbolgs me hirieron antes de que consiguiera escapar. Dame un momento para recuperarme. Luego podremos hablar.', 0),
(@ID, 'esMX', '¡Estupendo! Terenthis ha encontrado a alguien que me ayude.$B$BY mira, una capa de Acechalunas...<tose> Ay... qué dolor. Gracias, $n.$B$BLos furbolgs me hirieron antes de que consiguiera escapar. Dame un momento para recuperarme. Luego podremos hablar.', 0);
-- 995 Escaparse furtivamente
-- https://es.classic.wowhead.com/quest=995
SET @ID := 995;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí, $n?', 0),
(@ID, 'esMX', '¿Sí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! Me alegra ver que has conseguido volver. Que ayudaras a Volcor me da esperanzas... creo que podremos superar los desafíos que nos esperan en Costa Oscura y más allá.', 0),
(@ID, 'esMX', '¡$n! Me alegra ver que has conseguido volver. Que ayudaras a Volcor me da esperanzas... creo que podremos superar los desafíos que nos esperan en Costa Oscura y más allá.', 0);
-- 994 Escaparse por la fuerza
-- https://es.classic.wowhead.com/quest=994
SET @ID := 994;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$n! Me complace ver que has regresaso. Tu ayuda a Volcor me ha dado fe en que podemos superar los desafíos que enfrentamos aquí en Darkshore y más allá.', 0),
(@ID, 'esMX', '¡$n! Me complace ver que has regresaso. Tu ayuda a Volcor me ha dado fe en que podemos superar los desafíos que enfrentamos aquí en Darkshore y más allá.', 0);
-- 968 Los Poderes Subyacentes
-- https://es.classic.wowhead.com/quest=968
SET @ID := 968;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $gseñor:señora;.$B¿Puedo interesarte en uno de mis libros?', 0),
(@ID, 'esMX', 'Hola, $gseñor:señora;.$B¿Puedo interesarte en uno de mis libros?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, una copia de Los Poderes Subyacentes. Un texto interesante. Y a algunos les puede resultar útil...$B$BPero este está en muy mal estado. ¡Y mira aquí! ¡Hay notas al margen de casi todas las páginas!$B$BHm... reconozco esta copia. Se lo vendí a Bolgar el año pasado. ¿Eres... su $gamigo:amiga;? Sí, eso pensé. ¡Tienes ese mismo fuego en de tu mirada!$B$BBueno, por definición, $gun amigo:una amiga; de Bolgar es $gamigo mío:amiga mia;. Y nosotros nos ocupamos de los nuestros, ¿no?', 0),
(@ID, 'esMX', 'Ah, una copia de Los Poderes Subyacentes. Un texto interesante. Y a algunos les puede resultar útil...$B$BPero este está en muy mal estado. ¡Y mira aquí! ¡Hay notas al margen de casi todas las páginas!$B$BHm... reconozco esta copia. Se lo vendí a Bolgar el año pasado. ¿Eres... su $gamigo:amiga;? Sí, eso pensé. ¡Tienes ese mismo fuego en de tu mirada!$B$BBueno, por definición, $gun amigo:una amiga; de Bolgar es $gamigo mío:amiga mia;. Y nosotros nos ocupamos de los nuestros, ¿no?', 0);
-- 949 El campamento del Martillo Crepuscular
-- https://es.classic.wowhead.com/quest=949
SET @ID := 949;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este libro fue manuscrito en un antiguo lenguaje e ilustrado por un artista.', 0),
(@ID, 'esMX', 'Este libro fue manuscrito en un antiguo lenguaje e ilustrado por un artista.', 0);
-- 950 Regresa junto a Onus
-- https://es.classic.wowhead.com/quest=950
SET @ID := 950;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n. Vuelve.', 0),
(@ID, 'esMX', '$n. Vuelve.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este intrincado texto está envuelto en una primitiva y caótica magia. Percibo la mano de los mayores en él.$B$BEsperemos que nos revele el propósito del Martillo Crepuscular en Costa Oscura...', 0),
(@ID, 'esMX', 'Este intrincado texto está envuelto en una primitiva y caótica magia. Percibo la mano de los mayores en él.$B$BEsperemos que nos revele el propósito del Martillo Crepuscular en Costa Oscura...', 0);
-- 741 El prospector despistado
-- https://es.classic.wowhead.com/quest=741
SET @ID := 741;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué puedo hacer por ti, $r?', 0),
(@ID, 'esMX', '¿Qué puedo hacer por ti, $r?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ay, ay! ¡Deja que sea el prospector Remtravel quien descubra eso!', 0),
(@ID, 'esMX', '¡Ay, ay! ¡Deja que sea el prospector Remtravel quien descubra eso!', 0);
-- 942 El prospector despistado
-- https://es.classic.wowhead.com/quest=942
SET @ID := 942;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes ahí?', 0),
(@ID, 'esMX', '¿Qué tienes ahí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya! ¿Dices que esto viene de las lejanas tierras de Kalimdor?$B$B¡Increíble! ¡Sencillamente increíble!', 0),
(@ID, 'esMX', '¡Vaya! ¿Dices que esto viene de las lejanas tierras de Kalimdor?$B$B¡Increíble! ¡Sencillamente increíble!', 0);
-- 1124 Páramo
-- https://es.classic.wowhead.com/quest=1124
SET @ID := 1124;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este no es lugar para pasearse, $c. ¿Qué te trae a Silithus?', 0),
(@ID, 'esMX', 'Este no es lugar para pasearse, $c. ¿Qué te trae a Silithus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, vienes de parte del rabino. Te doy la bienvenida a estas tierras inhóspitas.$B$BYo no fui testigo de las grandes guerras, pero la desolación se huele en el aire. Gracias a tu ayuda, puede que el Círculo Cenarion ponga fin a una amenaza que se creía eliminada hace generaciones.', 0),
(@ID, 'esMX', 'Ah, vienes de parte del rabino. Te doy la bienvenida a estas tierras inhóspitas.$B$BYo no fui testigo de las grandes guerras, pero la desolación se huele en el aire. Gracias a tu ayuda, puede que el Círculo Cenarion ponga fin a una amenaza que se creía eliminada hace generaciones.', 0);
-- 5527 Un relicario de Pureza
-- https://es.classic.wowhead.com/quest=5527
SET @ID := 5527;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los relicarios de pureza son instrumentos importantes. Se hicieron muy pocos y se creían perdidos.$B$BAdmito que sabía de la existencia del de Viento del Sur; pero me pareció más sensato mantener el secreto para evitar las sospechas del enemigo.$B$BPero ha llegado el momento de actuar, sobre todo tal como están las cosas en Eldre\'Thalas.', 0),
(@ID, 'esMX', 'Los relicarios de pureza son instrumentos importantes. Se hicieron muy pocos y se creían perdidos.$B$BAdmito que sabía de la existencia del de Viento del Sur; pero me pareció más sensato mantener el secreto para evitar las sospechas del enemigo.$B$BPero ha llegado el momento de actuar, sobre todo tal como están las cosas en Eldre\'Thalas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo que se dice de ti es cierto; el Círculo Cenarion tiene suerte de poder contar contigo.$B$BAhora que tengo el relicario, me siento más tranquilo. Tienes mi gratitud eterna por lo que has hecho...', 0),
(@ID, 'esMX', 'Lo que se dice de ti es cierto; el Círculo Cenarion tiene suerte de poder contar contigo.$B$BAhora que tengo el relicario, me siento más tranquilo. Tienes mi gratitud eterna por lo que has hecho...', 0);
-- 1008 La Ensenada de Zoram
-- https://es.classic.wowhead.com/quest=1008
SET @ID := 1008;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No podemos permitir que los nagas invadan nuestras costas, $n. Es vital que vayas a La Ensenada de Zoram y completes tu misión.', 0),
(@ID, 'esMX', 'No podemos permitir que los nagas invadan nuestras costas, $n. Es vital que vayas a La Ensenada de Zoram y completes tu misión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo de primera, $n. Tus acciones en La Ensenada de Zoram contra los nagas son encomiables.$B$BSé que no fue fácil realizar semejante proeza ya que la fuerza y la astucia de los nagas es sobradamente conocida entre los elfos de la noche. Lo sabemos… porque compartimos una historia con ellos.$B$BUna historia que me guardo de repetir.', 0),
(@ID, 'esMX', 'Un trabajo de primera, $n. Tus acciones en La Ensenada de Zoram contra los nagas son encomiables.$B$BSé que no fue fácil realizar semejante proeza ya que la fuerza y la astucia de los nagas es sobradamente conocida entre los elfos de la noche. Lo sabemos… porque compartimos una historia con ellos.$B$BUna historia que me guardo de repetir.', 0);
-- 4581 Kayneth Ventoleve
-- https://es.classic.wowhead.com/quest=4581
SET @ID := 4581;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí?', 0),
(@ID, 'esMX', '¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, el informe de Shindrell! Muchas gracias, $n. Shindrell es una buena centinela, valiente y amable. Debo leer esto en busca de pistas de una perversidad que, me temo, se está extendiendo por Vallefresno.', 0),
(@ID, 'esMX', '¡Ah, el informe de Shindrell! Muchas gracias, $n. Shindrell es una buena centinela, valiente y amable. Debo leer esto en busca de pistas de una perversidad que, me temo, se está extendiendo por Vallefresno.', 0);
-- 9533 Una mano amiga
-- https://es.classic.wowhead.com/quest=9533
SET @ID := 9533;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno ver a otro recién llegado aquí en Canción del Bosque.$B$BLa vindicadora Palanaar está enviando toda la ayuda que puede reunir y se agradece cada par de manos.$B$BEcha un vistazo a tu alrededor, $c. Puede que no sea mucho ahora, pero con el tiempo y la ayuda de nuestros aliados elfos de la noche, construiremos un asentamiento digno de llamar hogar. Hay mucho por hacer aquí y cualquier ayuda que puedas brindar será bienvenida.', 0),
(@ID, 'esMX', 'Es bueno ver a otro recién llegado aquí en Canción del Bosque.$B$BLa vindicadora Palanaar está enviando toda la ayuda que puede reunir y se agradece cada par de manos.$B$BEcha un vistazo a tu alrededor, $c. Puede que no sea mucho ahora, pero con el tiempo y la ayuda de nuestros aliados elfos de la noche, construiremos un asentamiento digno de llamar hogar. Hay mucho por hacer aquí y cualquier ayuda que puedas brindar será bienvenida.', 0);
-- 991 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=991
SET @ID := 991;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El cuerpo de Teronis yace destrozado en la isla. Por alguna razón desconocida, los murlocs lo han dejado en paz.$B$BLos profundos cortes en su cadáver proceden sin duda de las armas y garras de los murlocs.', 0),
(@ID, 'esMX', 'El cuerpo de Teronis yace destrozado en la isla. Por alguna razón desconocida, los murlocs lo han dejado en paz.$B$BLos profundos cortes en su cadáver proceden sin duda de las armas y garras de los murlocs.', 0);
-- 1054 Matanza selectiva
-- https://es.classic.wowhead.com/quest=1054
SET @ID := 1054;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La corrupción de los furbolgs ha asestado un duro golpe a la gloria de Vallefresno.', 0),
(@ID, 'esMX', 'La corrupción de los furbolgs ha asestado un duro golpe a la gloria de Vallefresno.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n.$B$BLa amenaza de los furbolgs es constante. Esperemos que esto los mantenga a raya un poco más.', 0),
(@ID, 'esMX', 'Muy bien, $n.$B$BLa amenaza de los furbolgs es constante. Esperemos que esto los mantenga a raya un poco más.', 0);
-- 1023 La limpieza de Raene
-- https://es.classic.wowhead.com/quest=1023
SET @ID := 1023;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, bienvenido de nuevo.', 0),
(@ID, 'esMX', 'Ah, $n, bienvenido de nuevo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es terrible, $n. ¡¿Teronis ha muerto?!$B$BYa llegará la hora del luto pero ahora tenemos que centrar nuestros esfuerzos. Enviaré a algunas centinelas para que recuperen el cuerpo de Teronis cuando antes.$B$BTienes el diario de Teronis y la gema que andaba buscando. ¿Te sientes capaz de completar su tarea? Descansaría mejor si supiera que no murió en vano.', 0),
(@ID, 'esMX', 'Es terrible, $n. ¡¿Teronis ha muerto?!$B$BYa llegará la hora del luto pero ahora tenemos que centrar nuestros esfuerzos. Enviaré a algunas centinelas para que recuperen el cuerpo de Teronis cuando antes.$B$BTienes el diario de Teronis y la gema que andaba buscando. ¿Te sientes capaz de completar su tarea? Descansaría mejor si supiera que no murió en vano.', 0);
-- 1007 Las antiguas estatuillas
-- https://es.classic.wowhead.com/quest=1007
SET @ID := 1007;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado la estatuilla, $n?', 0),
(@ID, 'esMX', '¿Has encontrado la estatuilla, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La encontraste! ¡Gracias, $n!$B$BLa antigua ciudad de Zoram guarda muchos secretos y esta estatuilla podría ser la llave de gran parte de tales secretos.', 0),
(@ID, 'esMX', '¡La encontraste! ¡Gracias, $n!$B$BLa antigua ciudad de Zoram guarda muchos secretos y esta estatuilla podría ser la llave de gran parte de tales secretos.', 0);
-- 1009 Ruuzel
-- https://es.classic.wowhead.com/quest=1009
SET @ID := 1009;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Se dice que el Anillo de Zoram es la clave de cualquier cerradura de la ciudad. ¿Lo tienes, $n?', 0),
(@ID, 'esMX', 'Se dice que el Anillo de Zoram es la clave de cualquier cerradura de la ciudad. ¿Lo tienes, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Encontraste el anillo! Gracias, $n. Acepta esto a guisa de pago y que sepas que tus acciones de hoy permanecerán por siempre en mi memoria.', 0),
(@ID, 'esMX', '¡Encontraste el anillo! Gracias, $n. Acepta esto a guisa de pago y que sepas que tus acciones de hoy permanecerán por siempre en mi memoria.', 0);
-- 970 La Torre de Althalaxx
-- https://es.classic.wowhead.com/quest=970
SET @ID := 970;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la gema de alma?', 0),
(@ID, 'esMX', '¿Has conseguido la gema de alma?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mm, esta piedra de alma está encantada con magia oscura. Será mejor que veamos que encierra.', 0),
(@ID, 'esMX', 'Mm, esta piedra de alma está encantada con magia oscura. Será mejor que veamos que encierra.', 0);
-- 1010 Cabello de Bathran
-- https://es.classic.wowhead.com/quest=1010
SET @ID := 1010;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido el cabello de Bathran, $n? La salud de la niña se debilita por minutos...', 0),
(@ID, 'esMX', '¿Has conseguido el cabello de Bathran, $n? La salud de la niña se debilita por minutos...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, tienes el cabello! Ahora haré un preparado para la niña y rezaré para que funcione.$B$BY... ¿dices que los Renegados están en las Ruinas de Bathran? Inquietante noticia. De lo más inquietante...', 0),
(@ID, 'esMX', '¡Ah, tienes el cabello! Ahora haré un preparado para la niña y rezaré para que funcione.$B$BY... ¿dices que los Renegados están en las Ruinas de Bathran? Inquietante noticia. De lo más inquietante...', 0);
