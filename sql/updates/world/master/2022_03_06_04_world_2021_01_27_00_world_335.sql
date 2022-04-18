-- 3085 Tablilla sacralizada
-- https://es.classic.wowhead.com/quest=3085
SET @ID := 3085;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que lo hiciste... ¡bien, bien! Los espíritus me dijeron que vendrías a ver a Ken\'jai muy pronto. Permíteme ser uno de los primeros en darte la bienvenida al Valle de los Retos. Este no será tu hogar por mucho tiempo, pero mientras lo sea, ¿por qué no lo haces lo mejor posible?', 0),
(@ID, 'esMX', 'Así que lo hiciste... ¡bien, bien! Los espíritus me dijeron que vendrías a ver a Ken\'jai muy pronto. Permíteme ser uno de los primeros en darte la bienvenida al Valle de los Retos. Este no será tu hogar por mucho tiempo, pero mientras lo sea, ¿por qué no lo haces lo mejor posible?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A medida que te pruebes a ti $gmismo:misma;, descubrirás que cada vez tienes un mejor control sobre los espíritus; los estarás llamando para grandes y grandiosas cosas... ahí es donde entra el viejo Ken\'jai. Ven a hablar con el viejo Ken\'jai cuando te sientas $glisto:lista;. Si los espíritus están de acuerdo, entonces veremos como enseñarte habilidades más poderosas... pero solo si los espíritus están de acuerdo.$B$BVe ahora, habla con el resto de la gente del Valle. Háblame de nuevo más tarde.', 0),
(@ID, 'esMX', 'A medida que te pruebes a ti $gmismo:misma;, descubrirás que cada vez tienes un mejor control sobre los espíritus; los estarás llamando para grandes y grandiosas cosas... ahí es donde entra el viejo Ken\'jai. Ven a hablar con el viejo Ken\'jai cuando te sientas $glisto:lista;. Si los espíritus están de acuerdo, entonces veremos como enseñarte habilidades más poderosas... pero solo si los espíritus están de acuerdo.$B$BVe ahora, habla con el resto de la gente del Valle. Háblame de nuevo más tarde.', 0);
-- 3086 Tablilla glífica
-- https://es.classic.wowhead.com/quest=3086
SET @ID := 3086;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que tú ya complacer a Mai\'ah, $n. Ser bueno. Das respeto a Mai\'ah y Mai\'ah te devuelve respeto. Pero ya vale, tú aquí estás para magia aprender, no para a Mai\'ah oír.$B$BSolo una cosa haber que Mai\'ah puede enseñarte de magia, $n, cómo parar la corrupción.', 0),
(@ID, 'esMX', 'Parece que tú ya complacer a Mai\'ah, $n. Ser bueno. Das respeto a Mai\'ah y Mai\'ah te devuelve respeto. Pero ya vale, tú aquí estás para magia aprender, no para a Mai\'ah oír.$B$BSolo una cosa haber que Mai\'ah puede enseñarte de magia, $n, cómo parar la corrupción.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tú estar entre los seres más poderosos del planeta, $n... no hay duda. Y todos lo saben... ¡lo saben bien!$B$BPero debes estar $gcansado:cansada;! No haber orco, ni elfo, ni enano al que tú temas... pero haber cosas que no puedes ver. Magia ser poderosa. Te obliga a hacer cosas que no quieres hacer. Te hace creer que eres más poderoso de lo que ser. Ten paciencia. Sé $glisto:lista;.$B$BCuando creas que estás $gpreparado:preparada; para instruirte vuelve con Mai\'ah. Te enseña lo que estás listo para aprender, sin problema.', 0),
(@ID, 'esMX', 'Tú estar entre los seres más poderosos del planeta, $n... no hay duda. Y todos lo saben... ¡lo saben bien!$B$BPero debes estar $gcansado:cansada;! No haber orco, ni elfo, ni enano al que tú temas... pero haber cosas que no puedes ver. Magia ser poderosa. Te obliga a hacer cosas que no quieres hacer. Te hace creer que eres más poderoso de lo que ser. Ten paciencia. Sé $glisto:lista;.$B$BCuando creas que estás $gpreparado:preparada; para instruirte vuelve con Mai\'ah. Te enseña lo que estás listo para aprender, sin problema.', 0);
-- 3087 Papiro con grabados
-- https://es.classic.wowhead.com/quest=3087
SET @ID := 3087;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, por fin llegas. Bueno. Jen\'shan te espera.$B$BMuchos piensan que es un camino fácil, pero Jen\'shan te dice que no ser cierto. Dominar las bestias de Durotar y más allá requiere tanta habilidad como dominar las artes arcanas o hablar con nuestros antepasados.$B$BDisparar un arco o un rifle puede no ser tan peligroso para ti como lanzar hechizo, pero seguro que ser tan peligroso para tu enemigo.', 0),
(@ID, 'esMX', 'Ah, por fin llegas. Bueno. Jen\'shan te espera.$B$BMuchos piensan que es un camino fácil, pero Jen\'shan te dice que no ser cierto. Dominar las bestias de Durotar y más allá requiere tanta habilidad como dominar las artes arcanas o hablar con nuestros antepasados.$B$BDisparar un arco o un rifle puede no ser tan peligroso para ti como lanzar hechizo, pero seguro que ser tan peligroso para tu enemigo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando terminemos de hablar, deberías hablar con el resto de los ciudadanos del Valle. Te piden que hagas cosas por ellos... cosas que pondrán a prueba tu habilidad y te enseñarán algunos de los peligros de esta tierra.$B$BA medida que crezcas en experiencia y sabiduría, necesitarás que Jen\'shan te muestre mejores técnicas y habilidades. Vuelve a Jen\'shan a menudo. Te haré saber lo que puedo enseñarte.', 0),
(@ID, 'esMX', 'Cuando terminemos de hablar, deberías hablar con el resto de los ciudadanos del Valle. Te piden que hagas cosas por ellos... cosas que pondrán a prueba tu habilidad y te enseñarán algunos de los peligros de esta tierra.$B$BA medida que crezcas en experiencia y sabiduría, necesitarás que Jen\'shan te muestre mejores técnicas y habilidades. Vuelve a Jen\'shan a menudo. Te haré saber lo que puedo enseñarte.', 0);
-- 3088 Papiro encriptado
-- https://es.classic.wowhead.com/quest=3088
SET @ID := 3088;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Shhh, no tan fuerte. No confío en Nartok. Cualquiera que tenga que esconderse en una cueva más profundamente que yo no es de fiar.$B$BSupongo que no has tenido problemas para orientarte.', 0),
(@ID, 'esMX', 'Shhh, no tan fuerte. No confío en Nartok. Cualquiera que tenga que esconderse en una cueva más profundamente que yo no es de fiar.$B$BSupongo que no has tenido problemas para orientarte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora que sabes dónde estoy, debo avisarte: la Mano Destrozada me pidió que te cuidara. Quieren que te entrene y te mantenga $ginformado:informada; de todo lo que puedan necesitar. Incluso si aún no estás $ginteresado:interesada; en ayudarlos, lo cual sería muy tonto por tu parte, haré lo que pueda para capacitarte... por una pequeña tarifa. Vuelve a verme en cualquier momento que creas estar $glisto:lista; y veremos lo que puedes aprender.', 0),
(@ID, 'esMX', 'Ahora que sabes dónde estoy, debo avisarte: la Mano Destrozada me pidió que te cuidara. Quieren que te entrene y te mantenga $ginformado:informada; de todo lo que puedan necesitar. Incluso si aún no estás $ginteresado:interesada; en ayudarlos, lo cual sería muy tonto por tu parte, haré lo que pueda para capacitarte... por una pequeña tarifa. Vuelve a verme en cualquier momento que creas estar $glisto:lista; y veremos lo que puedes aprender.', 0);
-- 3089 El papiro con runas grabadas
-- https://es.classic.wowhead.com/quest=3089
SET @ID := 3089;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, ya has llegado. Ya estaba empezando a preguntarme cuándo aparecerías. Envié el pergamino hace tiempo... no sabía si había llegado.$B$BPero basta de chácharas... estás aquí porque has elegido, has elegido conducir las vidas espirituales de nuestro pueblo.', 0),
(@ID, 'esMX', 'Bien, ya has llegado. Ya estaba empezando a preguntarme cuándo aparecerías. Envié el pergamino hace tiempo... no sabía si había llegado.$B$BPero basta de chácharas... estás aquí porque has elegido, has elegido conducir las vidas espirituales de nuestro pueblo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Serás el medio que utilizarán nuestros antepasados para comunicarse. Tendrás el poder de los elementos a tu entera disposición. Despedazar a tus enemigos será como un juego de niños y sanar a tus aliados tan fácil como respirar. Recuerda todo esto cuando afrontes nuevos retos y vuelve a verme siempre que quieras. Me quedaré aquí para enseñarte nuevos hechizos y para mostrarte el camino correcto cuando estés $glisto:lista;.', 0),
(@ID, 'esMX', 'Serás el medio que utilizarán nuestros antepasados para comunicarse. Tendrás el poder de los elementos a tu entera disposición. Despedazar a tus enemigos será como un juego de niños y sanar a tus aliados tan fácil como respirar. Recuerda todo esto cuando afrontes nuevos retos y vuelve a verme siempre que quieras. Me quedaré aquí para enseñarte nuevos hechizos y para mostrarte el camino correcto cuando estés $glisto:lista;.', 0);
-- 3090 Papiro corrupto
-- Notice: English text: Change 'Asatokta' to '$n' in quest_offer_reward.RewardText
-- https://es.classic.wowhead.com/quest=3090
SET @ID := 3090;
UPDATE `quest_offer_reward` SET `RewardText` = 'And now you\'ve joined our ranks also. Don\'t misunderstand, $n. Just because you have access to power that many will be jealous of, it does not mean you will be accepted easily. Thrall allows our kind into Orgrimmar because we are still his fellow kin--he cannot turn his back on us, or we would become as pathetic as the humans who enslaved him. My point is: be careful. You can be powerful, but if you are foolish, then you are as good dead.$B$BIf you need training in spells then return to me.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin has llegado... y discretamente también. Bueno.$B$BNuestro mundo está lleno de tontos, $n. Incluso el poderoso Thrall tiene mayores defectos de los que la mayoría puede ver. ¡Le da la espalda al poder necesario para hacer de esta nuestra tierra! No somos las mismas personas que fueron manipuladas y utilizadas por criaturas del Nether. Somos nuestra propia gente. Estamos orgullosos... y somos fuertes.', 0),
(@ID, 'esMX', 'Por fin has llegado... y discretamente también. Bueno.$B$BNuestro mundo está lleno de tontos, $n. Incluso el poderoso Thrall tiene mayores defectos de los que la mayoría puede ver. ¡Le da la espalda al poder necesario para hacer de esta nuestra tierra! No somos las mismas personas que fueron manipuladas y utilizadas por criaturas del Nether. Somos nuestra propia gente. Estamos orgullosos... y somos fuertes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y ahora también te has unido a nuestras filas. No lo malinterpretes, $n. El hecho de que tengas acceso al poder del que muchos estarán celosos no significa que te aceptarán fácilmente. Thrall permite que los de nuestra especie entren en Orgrimmar porque todavía somos sus parientes: no puede darnos la espalda o nos volveríamos tan patéticos como los humanos que lo esclavizaron. Mi punto es: ten cuidado. Puedes ser poderoso, pero si eres tonto, entonces estás muerto.$B$BSi necesitas entrenamiento en hechizos, regresa a mí.', 0),
(@ID, 'esMX', 'Y ahora también te has unido a nuestras filas. No lo malinterpretes, $n. El hecho de que tengas acceso al poder del que muchos estarán celosos no significa que te aceptarán fácilmente. Thrall permite que los de nuestra especie entren en Orgrimmar porque todavía somos sus parientes: no puede darnos la espalda o nos volveríamos tan patéticos como los humanos que lo esclavizaron. Mi punto es: ten cuidado. Puedes ser poderoso, pero si eres tonto, entonces estás muerto.$B$BSi necesitas entrenamiento en hechizos, regresa a mí.', 0);
-- 3091 La nota simple
-- https://es.classic.wowhead.com/quest=3091
SET @ID := 3091;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'AL fin llegas, $c. Como decía en mi nota, somos una raza especial, como los chamanes y druidas de la tribu. Tú también eres importante; tenemos que defender las fronteras, acabar con los centauros e ir a la guerra.', 0),
(@ID, 'esMX', 'AL fin llegas, $c. Como decía en mi nota, somos una raza especial, como los chamanes y druidas de la tribu. Tú también eres importante; tenemos que defender las fronteras, acabar con los centauros e ir a la guerra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todos tenemos un papel en la tribu y todos pasamos los mismos ritos; no dejes que tu orgullo te diga lo contrario.$B$BYo me quedo aquí para entrenar a los guerreros que buscan la gloria del combate. Ven a verme cuando quieras, te daré la instrucción que pueda. Cuentas con la bendición de la tribu, $n.', 0),
(@ID, 'esMX', 'Todos tenemos un papel en la tribu y todos pasamos los mismos ritos; no dejes que tu orgullo te diga lo contrario.$B$BYo me quedo aquí para entrenar a los guerreros que buscan la gloria del combate. Ven a verme cuando quieras, te daré la instrucción que pueda. Cuentas con la bendición de la tribu, $n.', 0);
-- 3092 La nota con grabados
-- https://es.classic.wowhead.com/quest=3092
SET @ID := 3092;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; al Campamento Narache, $n. Escucho cosas buenas de ti. Tu línea de sangre es fuerte y muchos de los ancianos ya te consideran hábil. Pero eso te probaremos.$B$BLas llanuras de Mulgore serán tu hogar durante algún tiempo; debes hacer todo lo posible para conocerlas muy bien. Un día viajarás a tierras desconocidas para dominar mayores habilidades. Debes estar $glisto:lista;.', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; al Campamento Narache, $n. Escucho cosas buenas de ti. Tu línea de sangre es fuerte y muchos de los ancianos ya te consideran hábil. Pero eso te probaremos.$B$BLas llanuras de Mulgore serán tu hogar durante algún tiempo; debes hacer todo lo posible para conocerlas muy bien. Un día viajarás a tierras desconocidas para dominar mayores habilidades. Debes estar $glisto:lista;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y es mi trabajo asegurarme de que estés $gpreparado:preparada; enseñándote los conceptos básicos de nuestra profesión: cómo domesticar a tu mascota, cómo disparar tu rifle y muchas otras habilidades que serán necesarias.$B$BLos cazadores son una parte importante de nuestra tradición e historia, $n. Harías bien en recordar lo importante que es para la tribu. Serás $grespetado y reverenciado:respetada y reverenciada; si sirves bien a nuestra gente.', 0),
(@ID, 'esMX', 'Y es mi trabajo asegurarme de que estés $gpreparado:preparada; enseñándote los conceptos básicos de nuestra profesión: cómo domesticar a tu mascota, cómo disparar tu rifle y muchas otras habilidades que serán necesarias.$B$BLos cazadores son una parte importante de nuestra tradición e historia, $n. Harías bien en recordar lo importante que es para la tribu. Serás $grespetado y reverenciado:respetada y reverenciada; si sirves bien a nuestra gente.', 0);
-- 3093 La nota con runas grabadas
-- https://es.classic.wowhead.com/quest=3093
SET @ID := 3093;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tan rápido como el agua cae del cielo, aquí estás ante mí. Me alegra tu prisa. Significa que te das cuenta de la importancia de nuestro encuentro y de que estés aquí. No soy un líder, pero comprendo los elementos y puedo hablar con los espíritus de nuestra gente. Yo te enseñaré a hacer lo mismo.', 0),
(@ID, 'esMX', 'Tan rápido como el agua cae del cielo, aquí estás ante mí. Me alegra tu prisa. Significa que te das cuenta de la importancia de nuestro encuentro y de que estés aquí. No soy un líder, pero comprendo los elementos y puedo hablar con los espíritus de nuestra gente. Yo te enseñaré a hacer lo mismo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nos reuniremos muchas veces en los próximos días. Espero que cada vez dejes mi compañia un poco más $gpoderoso:poderosa;... un poco más $gpreparado:preparada;. Como la Llama Eterna, tu espíritu arderá brillante y caliente.$B$BVete ahora, $n. Ve y ponte a prueba. Estaré aquí para ti cuando lo necesites.', 0),
(@ID, 'esMX', 'Nos reuniremos muchas veces en los próximos días. Espero que cada vez dejes mi compañia un poco más $gpoderoso:poderosa;... un poco más $gpreparado:preparada;. Como la Llama Eterna, tu espíritu arderá brillante y caliente.$B$BVete ahora, $n. Ve y ponte a prueba. Estaré aquí para ti cuando lo necesites.', 0);
-- 3095 Un pergamino simple
-- https://es.classic.wowhead.com/quest=3095
SET @ID := 3095;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, has llegado. Bueno. Escuché que algunos otros pudieron escapar de la "muerte" y se dirigían a la ciudad. Quizás esa resistencia también dará sus frutos en el futuro.$B$BPuedes agradecer a Sylvanas por tu libertad... libertad de mente y cuerpo. Aunque sigues torturado por la plaga y sus efectos, ahora eres libre de ir y venir como mejor te parezca.', 0),
(@ID, 'esMX', 'Ah, has llegado. Bueno. Escuché que algunos otros pudieron escapar de la "muerte" y se dirigían a la ciudad. Quizás esa resistencia también dará sus frutos en el futuro.$B$BPuedes agradecer a Sylvanas por tu libertad... libertad de mente y cuerpo. Aunque sigues torturado por la plaga y sus efectos, ahora eres libre de ir y venir como mejor te parezca.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estaré aquí para entrenarte a medida que crezcas en experiencia... ven tan a menudo como quieras. Cobro una tarifa mínima, pero encontrarás que todo lo que puedo enseñarte vale la pena.$B$BVe ahora y prueba tu habilidad. A medida que ganes experiencia, sabrás muchas más cosas, algunas de las cuales no puedo contarte aquí ni ahora. Solo debes saber que Sylvanas necesitará guerreros con tu tipo de fuerza en el futuro. Serás la columna vertebral de nuestra salvación. No lo olvides.', 0),
(@ID, 'esMX', 'Estaré aquí para entrenarte a medida que crezcas en experiencia... ven tan a menudo como quieras. Cobro una tarifa mínima, pero encontrarás que todo lo que puedo enseñarte vale la pena.$B$BVe ahora y prueba tu habilidad. A medida que ganes experiencia, sabrás muchas más cosas, algunas de las cuales no puedo contarte aquí ni ahora. Solo debes saber que Sylvanas necesitará guerreros con tu tipo de fuerza en el futuro. Serás la columna vertebral de nuestra salvación. No lo olvides.', 0);
-- 3096 Un pergamino codificado
-- https://es.classic.wowhead.com/quest=3096
SET @ID := 3096;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que lo has conseguido? Bien, porque a medida que pasa el tiempo, necesitamos más pícaros. Los acechasombras te buscarán cuando crean que ha llegado el momento, así que no vayas a meter la pata o hacer algo de lo que puedas arrepentirte. Necesitan agentes profesionales... no carteristas torpes.', 0),
(@ID, 'esMX', '¿Así que lo has conseguido? Bien, porque a medida que pasa el tiempo, necesitamos más pícaros. Los acechasombras te buscarán cuando crean que ha llegado el momento, así que no vayas a meter la pata o hacer algo de lo que puedas arrepentirte. Necesitan agentes profesionales... no carteristas torpes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Paso la mayor parte del tiempo en la posada. Me fijo en las caras nuevas, por si aparece alguien prometedor. Si no te metes en líos, haré lo posible por enseñarte algunas cosas. Vuelve cuando quieras y veremos si estás $glisto:lista; para una o dos habilidades nuevas.', 0),
(@ID, 'esMX', 'Paso la mayor parte del tiempo en la posada. Me fijo en las caras nuevas, por si aparece alguien prometedor. Si no te metes en líos, haré lo posible por enseñarte algunas cosas. Vuelve cuando quieras y veremos si estás $glisto:lista; para una o dos habilidades nuevas.', 0);
-- 3097 Un pergamino sacralizado
-- https://es.classic.wowhead.com/quest=3097
SET @ID := 3097;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah! Así que entre el fuego, la plaga, la lucha y males peores... llama a mi puerta otro "creyente". Pues bien, deja que te dé la bienvenida, $c. Y concédeme un minuto para explicarte un par de cosas antes de decidir que es hora de buscar lo que sea que estés buscando: la Luz Sagrada ya no te concierne; los espíritus de tus antepasados no son más que leyendas y las alimañas del vacío Abisal no te quieren.$B$B¿Me sigues?', 0),
(@ID, 'esMX', '¡Ah! Así que entre el fuego, la plaga, la lucha y males peores... llama a mi puerta otro "creyente". Pues bien, deja que te dé la bienvenida, $c. Y concédeme un minuto para explicarte un par de cosas antes de decidir que es hora de buscar lo que sea que estés buscando: la Luz Sagrada ya no te concierne; los espíritus de tus antepasados no son más que leyendas y las alimañas del vacío Abisal no te quieren.$B$B¿Me sigues?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo hay una cosa que debes saber: hemos sobrevivido solo con voluntad. Es la fe en nosotros mismos lo que nos separa de los demás y, con nuestros poderes, provocaremos un gran cambio en todo Azeroth. Los débiles acabarán dependiendo de ti. Los leprosos te llamarán señor. Y los ignorantes se volverán a ti en busca de guía. Mi deber es asegurarme de que tienes las herramientas necesarias para que, cuando llegue el momento, estés $gpreparado:preparada;. Cuando adquieras más experiencia, búscame. Si estás $gpreparado:preparada;, te enseñaré poderes mayores.', 0),
(@ID, 'esMX', 'Solo hay una cosa que debes saber: hemos sobrevivido solo con voluntad. Es la fe en nosotros mismos lo que nos separa de los demás y, con nuestros poderes, provocaremos un gran cambio en todo Azeroth. Los débiles acabarán dependiendo de ti. Los leprosos te llamarán señor. Y los ignorantes se volverán a ti en busca de guía. Mi deber es asegurarme de que tienes las herramientas necesarias para que, cuando llegue el momento, estés $gpreparado:preparada;. Cuando adquieras más experiencia, búscame. Si estás $gpreparado:preparada;, te enseñaré poderes mayores.', 0);
-- 3098 Un pergamino glífico
-- https://es.classic.wowhead.com/quest=3098
SET @ID := 3098;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabría que acudirías, $n. Y no porque no tengas voluntad para seguir tu propio camino, sino porque somos espíritus afines. Los dos hemos conocido el dolor. Los dos hemos sufrido. Y ahora queremos adquirir el poder necesario para recuperar lo que es nuestro: esta tierra, nuestra vida, nuestro destino. Pero a ti te queda mucho que aprender aún.', 0),
(@ID, 'esMX', 'Sabría que acudirías, $n. Y no porque no tengas voluntad para seguir tu propio camino, sino porque somos espíritus afines. Los dos hemos conocido el dolor. Los dos hemos sufrido. Y ahora queremos adquirir el poder necesario para recuperar lo que es nuestro: esta tierra, nuestra vida, nuestro destino. Pero a ti te queda mucho que aprender aún.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes volver a mí a menudo si quieres adquirir el poder necesario para destruir a quienes se nos oponen. Aún estás $gsometido:sometida; a las reglas de la magia, $n. La corrupción te seguirá como un lobo hambriento en la noche. Te darás cuenta de que su caricia es como una adicción, como $guna antigua:un antiguo; amante que aún quiere estar a tu lado. Pero esas cosas pueden evitarse. Esas cosas solo te controlan si se lo permites.$B$BAhora, vete. Y vuelve a mí cuando seas más fuerte.', 0),
(@ID, 'esMX', 'Debes volver a mí a menudo si quieres adquirir el poder necesario para destruir a quienes se nos oponen. Aún estás $gsometido:sometida; a las reglas de la magia, $n. La corrupción te seguirá como un lobo hambriento en la noche. Te darás cuenta de que su caricia es como una adicción, como $guna antigua:un antiguo; amante que aún quiere estar a tu lado. Pero esas cosas pueden evitarse. Esas cosas solo te controlan si se lo permites.$B$BAhora, vete. Y vuelve a mí cuando seas más fuerte.', 0);
-- 3099 Un pergamino corrupto
-- https://es.classic.wowhead.com/quest=3099
SET @ID := 3099;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida, $ghermano:hermana;. Sabía que vendrías. Era sólo cuestión de tiempo.$B$BLo que dije te interesó, ¿no? Toqué un acorde... algo dentro de ti sabía que lo que yo decía era verdad. Bueno.$B$BSin embargo, debes saber esto: no soy un traidor para Sylvanas. En todo caso, agradecería mis afirmaciones teniendo en cuenta que fueron sus propias creencias las que han puesto a los Renegados en la posición en que se encuentran ahora.', 0),
(@ID, 'esMX', 'Te doy la bienvenida, $ghermano:hermana;. Sabía que vendrías. Era sólo cuestión de tiempo.$B$BLo que dije te interesó, ¿no? Toqué un acorde... algo dentro de ti sabía que lo que yo decía era verdad. Bueno.$B$BSin embargo, debes saber esto: no soy un traidor para Sylvanas. En todo caso, agradecería mis afirmaciones teniendo en cuenta que fueron sus propias creencias las que han puesto a los Renegados en la posición en que se encuentran ahora.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mencioné que un esclavo sigue siendo esclavo, sin importar el amo. ¿Te acuerdas? Ambos sabemos que es ese tipo de control, ese tipo de poder, el que ahora nos impulsa. Buscamos que las criaturas nos sirvan. Sabemos que somos más poderosos y merecemos más respeto del que otros nos dan... y por eso ahora buscamos tomarlo.$B$BSeré tu aliado en esta lucha, la lucha por nuestra propia libertad. Libertad para buscar nuestras propias lealtades. Cuando te sienta $gpreparado:preparada;, vuelve a mí y te enseñaré todo lo que sé.', 0),
(@ID, 'esMX', 'Mencioné que un esclavo sigue siendo esclavo, sin importar el amo. ¿Te acuerdas? Ambos sabemos que es ese tipo de control, ese tipo de poder, el que ahora nos impulsa. Buscamos que las criaturas nos sirvan. Sabemos que somos más poderosos y merecemos más respeto del que otros nos dan... y por eso ahora buscamos tomarlo.$B$BSeré tu aliado en esta lucha, la lucha por nuestra propia libertad. Libertad para buscar nuestras propias lealtades. Cuando te sienta $gpreparado:preparada;, vuelve a mí y te enseñaré todo lo que sé.', 0);
-- 3106 Runa simple
-- https://es.classic.wowhead.com/quest=3106
SET @ID := 3106;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya si hace frío hoy, ¿eh? Parece que la nieve no piensa irse nunca, $n.$B$BYa debes haberlo notado, pero ahora hay gnomos viviendo en nuestra ciudad. Es porque provocaron una explosión que los expulsó de su hogar. No lo comentes por ahí, pero no puedo culparlos: creo que yo también usaría explosivos si Forjaz estuviera infestada con Hierro Negro u otros seres despreciables.', 0),
(@ID, 'esMX', 'Vaya si hace frío hoy, ¿eh? Parece que la nieve no piensa irse nunca, $n.$B$BYa debes haberlo notado, pero ahora hay gnomos viviendo en nuestra ciudad. Es porque provocaron una explosión que los expulsó de su hogar. No lo comentes por ahí, pero no puedo culparlos: creo que yo también usaría explosivos si Forjaz estuviera infestada con Hierro Negro u otros seres despreciables.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es bueno que sepas que también verás otras cosas, como enanos usando magia en una pelea en lugar de un rifle, a algunos de los nuestros que veneran la Luz sagrada como los humanos, y por último, pero no menos importante, troggs. Ya aprenderás más sobre ellos, pero lo que debes saber es que estoy aquí para ayudarte.$B$BEstoy para enseñarte a ser $gun verdadero:una verdadera; $c. Si crees que necesitas más entrenamiento, ven a verme y veremos qué se puede hacer.', 0),
(@ID, 'esMX', 'Es bueno que sepas que también verás otras cosas, como enanos usando magia en una pelea en lugar de un rifle, a algunos de los nuestros que veneran la Luz sagrada como los humanos, y por último, pero no menos importante, troggs. Ya aprenderás más sobre ellos, pero lo que debes saber es que estoy aquí para ayudarte.$B$BEstoy para enseñarte a ser $gun verdadero:una verdadera; $c. Si crees que necesitas más entrenamiento, ven a verme y veremos qué se puede hacer.', 0);
-- 3107 Runa consagrada
-- https://es.classic.wowhead.com/quest=3107
SET @ID := 3107;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Así que lo has logrado! Y ni un segundo demasiado pronto. Hay mucho por hacer en Crestanevada y más allá. ¡Necesitaré tu ayuda tanto como tú necesitarás la mía!$B$BAhora eres $gun:una; Caballero de la Mano de Plata, prepárate para interpretar el papel.', 0),
(@ID, 'esMX', '¡Así que lo has logrado! Y ni un segundo demasiado pronto. Hay mucho por hacer en Crestanevada y más allá. ¡Necesitaré tu ayuda tanto como tú necesitarás la mía!$B$BAhora eres $gun:una; Caballero de la Mano de Plata, prepárate para interpretar el papel.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los humanos nos han enseñado mucho sobre la Luz Sagrada y lo importante que es su orden para ellos... y para proteger todo Azeroth. Tenemos un gran respeto por lo arraigada que es la tradición y por cómo una sola figura, un solo sacrificio, puede marcar la diferencia entre el dolor y la salvación.$B$BLos dos trabajaremos juntos por un tiempo. En cualquier momento que creas estár $glisto:lista;, vuelva a verme y veremos cómo obtener un poco de entrenamiento. No puedo permitir que salgas al mundo sin estar $gpreparado:preparada;, ¿verdad?', 0),
(@ID, 'esMX', 'Los humanos nos han enseñado mucho sobre la Luz Sagrada y lo importante que es su orden para ellos... y para proteger todo Azeroth. Tenemos un gran respeto por lo arraigada que es la tradición y por cómo una sola figura, un solo sacrificio, puede marcar la diferencia entre el dolor y la salvación.$B$BLos dos trabajaremos juntos por un tiempo. En cualquier momento que creas estár $glisto:lista;, vuelva a verme y veremos cómo obtener un poco de entrenamiento. No puedo permitir que salgas al mundo sin estar $gpreparado:preparada;, ¿verdad?', 0);
-- 3108 Runa con grabados
-- https://es.classic.wowhead.com/quest=3108
SET @ID := 3108;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya lo hiciste! ¡Qué bueno escuchar! Apuesto a que tampoco has tenido que rastrearme para encontrar el lugar. ¡Jaja!$B$BNuestra profesión tiene mucha tradición, $n. Aprendiendo los caminos de la tierra. Aprendiendo a rastrear un oso por las montañas. Incluso sobrevivir solo con ingenio requiere mucho coraje y astucia. ¿Crees que eres capaz?', 0),
(@ID, 'esMX', '¡Ya lo hiciste! ¡Qué bueno escuchar! Apuesto a que tampoco has tenido que rastrearme para encontrar el lugar. ¡Jaja!$B$BNuestra profesión tiene mucha tradición, $n. Aprendiendo los caminos de la tierra. Aprendiendo a rastrear un oso por las montañas. Incluso sobrevivir solo con ingenio requiere mucho coraje y astucia. ¿Crees que eres capaz?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una cosa que siempre debes recordar es que debes respetar el mundo en el que vives. Las bestias que eligen luchar junto a ti; el brillo de tu arma; el peso de tu munición; la sensación de un viento amargo; todas estas cosas que necesitas conocer íntimamente.$B$BHaré lo que pueda para ayudarte, pero la mayor parte del trabajo depende de ti. En cualquier momento que creas que está $glisto:list;, vuelve y habla conmigo. Te entrenaré.', 0),
(@ID, 'esMX', 'Una cosa que siempre debes recordar es que debes respetar el mundo en el que vives. Las bestias que eligen luchar junto a ti; el brillo de tu arma; el peso de tu munición; la sensación de un viento amargo; todas estas cosas que necesitas conocer íntimamente.$B$BHaré lo que pueda para ayudarte, pero la mayor parte del trabajo depende de ti. En cualquier momento que creas que está $glisto:list;, vuelve y habla conmigo. Te entrenaré.', 0);
-- 3109 Runa codificada
-- https://es.classic.wowhead.com/quest=3109
SET @ID := 3109;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo hiciste! ¡Excelente!$B$BÚltimamente tenemos una gran cantidad de actividad, así que me alegra contar con otro miembro del clan Forjaz entre nuestras filas. Demasiados de nosotros estamos buscando lo arcano y divino para mi gusto. No tengo nada contra ellos y sus creencias, pero no hay nada como una espada fría en tu mano y una sombra para alejarte de la luz, ¿entiendes a qué me refiero?', 0),
(@ID, 'esMX', '¡Lo hiciste! ¡Excelente!$B$BÚltimamente tenemos una gran cantidad de actividad, así que me alegra contar con otro miembro del clan Forjaz entre nuestras filas. Demasiados de nosotros estamos buscando lo arcano y divino para mi gusto. No tengo nada contra ellos y sus creencias, pero no hay nada como una espada fría en tu mano y una sombra para alejarte de la luz, ¿entiendes a qué me refiero?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De todos modos, cuando empieces a echar un vistazo a Crestanevada probablemente necesitarás entrenar en algún momento. Vuelve a mí siempre que lo necesites y te enseñaré lo que sé: un truco aquí, una maniobra allá. Ya sabes, las cosas que te mantienen vivo y hacen una pequeña moneda extra.$B$BEstá $gatento:atenta; también a nuestros amigos gnomos... a ellos les tocó el palito corto cuando Gnomeregan fue... destruido. Necesitarán nuestra ayuda para sentirse bienvenidos.', 0),
(@ID, 'esMX', 'De todos modos, cuando empieces a echar un vistazo a Crestanevada probablemente necesitarás entrenar en algún momento. Vuelve a mí siempre que lo necesites y te enseñaré lo que sé: un truco aquí, una maniobra allá. Ya sabes, las cosas que te mantienen vivo y hacen una pequeña moneda extra.$B$BEstá $gatento:atenta; también a nuestros amigos gnomos... a ellos les tocó el palito corto cuando Gnomeregan fue... destruido. Necesitarán nuestra ayuda para sentirse bienvenidos.', 0);
-- 3110 Runa sacralizada
-- https://es.classic.wowhead.com/quest=3110
SET @ID := 3110;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh! ¡Lo has conseguido, $n! ¡Estupendo!$B$BEmpezaba a creer que no llegarías y estaba a punto de perder la fe... ¿Lo pillas? ¿Lo de perder la fe? Era un chiste, $gmuchacho:muchacha;... déjalo, no importa. Además, no has venido aquí por mis pésimos chistes.', 0),
(@ID, 'esMX', '¡Eh! ¡Lo has conseguido, $n! ¡Estupendo!$B$BEmpezaba a creer que no llegarías y estaba a punto de perder la fe... ¿Lo pillas? ¿Lo de perder la fe? Era un chiste, $gmuchacho:muchacha;... déjalo, no importa. Además, no has venido aquí por mis pésimos chistes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yo soy quien puede entrenarte cuando comiences a orientarte por Crestanaveda. Cuando te sientas $glisto:lista;, vuelve conmigo y quizás te enseñe uno o dos hechizos nuevos para defenderte de esos malditos troggs.$B$BTienes la Luz de tu lado, junto con todo Forjaz, $n... sin presión para que te conviertas en algo especial.', 0),
(@ID, 'esMX', 'Yo soy quien puede entrenarte cuando comiences a orientarte por Crestanaveda. Cuando te sientas $glisto:lista;, vuelve conmigo y quizás te enseñe uno o dos hechizos nuevos para defenderte de esos malditos troggs.$B$BTienes la Luz de tu lado, junto con todo Forjaz, $n... sin presión para que te conviertas en algo especial.', 0);
-- 3112 Memorándum simple
-- https://es.classic.wowhead.com/quest=3112
SET @ID := 3112;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, bueno, otro memorándum de $gun:una; $r en una misión... no es tan pintoresco.$B$BNo, no, no te estoy tomando el pelo, $gpequeño:pequeña;. Respeto tu tenacidad, eso es seguro. Estaría igual de enojado si Forjaz fuera tomada por los enanos Hierro Negro, así que no pienses que no siento nada por tu difícil situación...', 0),
(@ID, 'esMX', 'Ah, bueno, otro memorándum de $gun:una; $r en una misión... no es tan pintoresco.$B$BNo, no, no te estoy tomando el pelo, $gpequeño:pequeña;. Respeto tu tenacidad, eso es seguro. Estaría igual de enojado si Forjaz fuera tomada por los enanos Hierro Negro, así que no pienses que no siento nada por tu difícil situación...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, viendo que esta es tu directiva principal, o como sea que la llamen estos días, te di mi palabra de que haría todo lo posible para asegurarme de que tú y los tuyos estuvieran listos para recuperar su hogar... y eso es lo que voy a hacer.$B$BEn cualquier momento que te sientas <preparado(preparada>, vuelve con el bueno de Thran y estaré feliz de compartir mis conocimientos. Te costará algo el entrenamiento, pero no será demasiado caro. Buena suerte.', 0),
(@ID, 'esMX', 'Bueno, viendo que esta es tu directiva principal, o como sea que la llamen estos días, te di mi palabra de que haría todo lo posible para asegurarme de que tú y los tuyos estuvieran listos para recuperar su hogar... y eso es lo que voy a hacer.$B$BEn cualquier momento que te sientas <preparado(preparada>, vuelve con el bueno de Thran y estaré feliz de compartir mis conocimientos. Te costará algo el entrenamiento, pero no será demasiado caro. Buena suerte.', 0);
-- 3113 Memorándum encriptado
-- https://es.classic.wowhead.com/quest=3113
SET @ID := 3113;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que recibiste mi nota. Perdona por haber hecho que pareciera un memorándum de tus superiores... no era con mala intención. Lo hice porque creo que nosotros, junto con los demás de nuestra clase, tenemos que permanecer unidos.$B$BHay quien cree que tener a alguien como tú y a alguien como yo en la misma ciudad no es lo ideal, pero yo creo que es una buena cosa. ¿No estás de acuerdo?', 0),
(@ID, 'esMX', 'Me alegra ver que recibiste mi nota. Perdona por haber hecho que pareciera un memorándum de tus superiores... no era con mala intención. Lo hice porque creo que nosotros, junto con los demás de nuestra clase, tenemos que permanecer unidos.$B$BHay quien cree que tener a alguien como tú y a alguien como yo en la misma ciudad no es lo ideal, pero yo creo que es una buena cosa. ¿No estás de acuerdo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Suelo mantenerme un poco al margen de todo, para evitar sermones si desaparecen cosas y eso, pero si necesitas algo, entrenamiento o así, vuelve.$B$BTú y yo nos entendemos bien. Ya sabes, a la hora de la verdad, solo puedes fiarte de la familia... Y familia es lo que somos, ¿no? Aparte de eso de que Gnomeregan esté siendo invadido y eso y todo lo demás que se te cruce en el camino, nos tenemos el uno al otro para cubrirnos las espaldas. ¿No estás de acuerdo?', 0),
(@ID, 'esMX', 'Suelo mantenerme un poco al margen de todo, para evitar sermones si desaparecen cosas y eso, pero si necesitas algo, entrenamiento o así, vuelve.$B$BTú y yo nos entendemos bien. Ya sabes, a la hora de la verdad, solo puedes fiarte de la familia... Y familia es lo que somos, ¿no? Aparte de eso de que Gnomeregan esté siendo invadido y eso y todo lo demás que se te cruce en el camino, nos tenemos el uno al otro para cubrirnos las espaldas. ¿No estás de acuerdo?', 0);
-- 3114 Memorándum glífico
-- https://es.classic.wowhead.com/quest=3114
SET @ID := 3114;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, ¿qué es eso, $r? Habla, si no te importa. No escucho tan bien después de unas cervezas.', 0),
(@ID, 'esMX', 'Sí, ¿qué es eso, $r? Habla, si no te importa. No escucho tan bien después de unas cervezas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh si! Artes Arcanas... por supuesto.$B$BEsto es lo que necesitas saber, $n: No te metas en muchos problemas. Ahorra una moneda para comprarme una cerveza... o cualquier hechizo que quieras. Y mantente $galejado:alejada; de Gnomeregan. Aparte de eso, ¡que tengas un buen día! Estaré aquí si me necesitas o quieres entrenar... o lo que sea.', 0),
(@ID, 'esMX', '¡Oh si! Artes Arcanas... por supuesto.$B$BEsto es lo que necesitas saber, $n: No te metas en muchos problemas. Ahorra una moneda para comprarme una cerveza... o cualquier hechizo que quieras. Y mantente $galejado:alejada; de Gnomeregan. Aparte de eso, ¡que tengas un buen día! Estaré aquí si me necesitas o quieres entrenar... o lo que sea.', 0);
-- 3115 Runa corrupta
-- https://es.classic.wowhead.com/quest=3115
SET @ID := 3115;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! Obviamente tienes mi memorándum.$B$BIgnora a los tontos que te rodean, $n. ¡¿La Luz Sagrada?! ¿La espada y el escudo? Estos no son caminos para personas tan abiertas como nosotros. Mira lo que la magia "normal" le hizo a nuestra casa. Junto con esos malditos manitas, nuestra raza casi se extinguió. Y ahora tenemos que confiar en los enanos; prefieren pasar tiempo aliándose con los humanos que ayudarnos a reconstruir nuestro propio hogar. Somos como ciudadanos de segunda clase. ¿Has visto la forma en que nos miran?', 0),
(@ID, 'esMX', '¡Maravilloso! Obviamente tienes mi memorándum.$B$BIgnora a los tontos que te rodean, $n. ¡¿La Luz Sagrada?! ¿La espada y el escudo? Estos no son caminos para personas tan abiertas como nosotros. Mira lo que la magia "normal" le hizo a nuestra casa. Junto con esos malditos manitas, nuestra raza casi se extinguió. Y ahora tenemos que confiar en los enanos; prefieren pasar tiempo aliándose con los humanos que ayudarnos a reconstruir nuestro propio hogar. Somos como ciudadanos de segunda clase. ¿Has visto la forma en que nos miran?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pero nada de eso importa. ¡Lo que importa es que has visto tu propia Luz Sagrada! Sabes de dónde proviene realmente el poder. Te das cuenta de que tener nuestros propios aliados es mucho más... prudente. Aliados especiales. Aliados que, sin importar la tarea, obedecerán hasta el último aliento.$B$BY ahí es donde entro yo, $n. Puedo entrenarte en los inicios de esos poderes especiales. Búscame a menudo y haré lo que pueda para enseñarte más hechizos.', 0),
(@ID, 'esMX', 'Pero nada de eso importa. ¡Lo que importa es que has visto tu propia Luz Sagrada! Sabes de dónde proviene realmente el poder. Te das cuenta de que tener nuestros propios aliados es mucho más... prudente. Aliados especiales. Aliados que, sin importar la tarea, obedecerán hasta el último aliento.$B$BY ahí es donde entro yo, $n. Puedo entrenarte en los inicios de esos poderes especiales. Búscame a menudo y haré lo que pueda para enseñarte más hechizos.', 0);
-- 3116 El sigilo simple
-- https://es.classic.wowhead.com/quest=3116
SET @ID := 3116;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo hiciste. Estoy tan feliz.$B$BHan pasado muchas cosas en los últimos años, $n: la creación de Teldrassil, la corrupción de muchas de las criaturas del bosque aquí y en el extranjero, el descubrimiento de tierras que creíamos perdidas para nosotros como Feralas... tanto, en tan poco tiempo. Pero esas son solo algunas de las razones por las que estamos aquí, la más importante es proteger a nuestra especie de más maldad.', 0),
(@ID, 'esMX', 'Lo hiciste. Estoy tan feliz.$B$BHan pasado muchas cosas en los últimos años, $n: la creación de Teldrassil, la corrupción de muchas de las criaturas del bosque aquí y en el extranjero, el descubrimiento de tierras que creíamos perdidas para nosotros como Feralas... tanto, en tan poco tiempo. Pero esas son solo algunas de las razones por las que estamos aquí, la más importante es proteger a nuestra especie de más maldad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto verás a otros de diferentes razas en las ramas de nuestro hogar, no dejes que eso cause ningún prejuicio dentro de ti. Ellos son bienvenidos. Nos ayudarán cuando puedan. No todos serán altruistas, pero se les debe otorgar cierta confianza.$B$BPero nada de esto importa ahora. Ahora debemos centrarnos en ti y en cómo puedes ayudar a nuestra gente. Estoy aquí con ese mismo propósito. Te entrenaré en las formas de $gun:una; $c a medida que te vuelvas más fuerte. Vuelve a mí cuando quieras y haré lo que pueda para ayudarte.', 0),
(@ID, 'esMX', 'Pronto verás a otros de diferentes razas en las ramas de nuestro hogar, no dejes que eso cause ningún prejuicio dentro de ti. Ellos son bienvenidos. Nos ayudarán cuando puedan. No todos serán altruistas, pero se les debe otorgar cierta confianza.$B$BPero nada de esto importa ahora. Ahora debemos centrarnos en ti y en cómo puedes ayudar a nuestra gente. Estoy aquí con ese mismo propósito. Te entrenaré en las formas de $gun:una; $c a medida que te vuelvas más fuerte. Vuelve a mí cuando quieras y haré lo que pueda para ayudarte.', 0);
-- 3117 El sigilo con grabados
-- https://es.classic.wowhead.com/quest=3117
SET @ID := 3117;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida a Cañada Umbría, $n.$B$B¿Todo va bien?$B$BVoy a enseñarte técnicas de caza, a domar animales para que luchen junto a ti, a disparar con el arco y a respetar toda la tierra.', 0),
(@ID, 'esMX', 'Te doy la bienvenida a Cañada Umbría, $n.$B$B¿Todo va bien?$B$BVoy a enseñarte técnicas de caza, a domar animales para que luchen junto a ti, a disparar con el arco y a respetar toda la tierra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ven a verme a menudo mientras estés en Cañada Umbría; te ayudaré a entender el rol $gdel:de la; $c y tus capacidades.$B$BNo confíes demasiado en la ayuda de tus mascotas. En estos tiempos hay cosas más peligrosas de lo que puedas imaginar.', 0),
(@ID, 'esMX', 'Ven a verme a menudo mientras estés en Cañada Umbría; te ayudaré a entender el rol $gdel:de la; $c y tus capacidades.$B$BNo confíes demasiado en la ayuda de tus mascotas. En estos tiempos hay cosas más peligrosas de lo que puedas imaginar.', 0);
-- 3118 El sigilo cifrado
-- Notice: English text: Change 'Ferlis' to '$n' in quest_request_items.CompletionText
-- https://es.classic.wowhead.com/quest=3118
SET @ID := 3118;
UPDATE `quest_request_items` SET `CompletionText` = 'Hello, $n. I\'m glad you found me. I was thinking that perhaps you got lost on the way here.$B$BNothing really new has happened in Shadowglen since I sent you my sigil, but I\'ll leave all the information gathering to you. Speak to the rest of the people around Aldrassil if you\'d like.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. Me alegro de que me hayas encontrado. Estaba pensando que quizás te perdiste en el camino hacia aquí.$B$BNada realmente nuevo ha sucedido en Cañada Umbría desde que te envié mi sigilo, pero te dejo toda la información que recopilé. Habla con el resto de las personas de Aldrassil si quieres.', 0),
(@ID, 'esMX', 'Hola, $n. Me alegro de que me hayas encontrado. Estaba pensando que quizás te perdiste en el camino hacia aquí.$B$BNada realmente nuevo ha sucedido en Cañada Umbría desde que te envié mi sigilo, pero te dejo toda la información que recopilé. Habla con el resto de las personas de Aldrassil si quieres.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hasta entonces, debes saber que los de nuestra especie son más necesarios que nunca en estos tiempos difíciles. La paz con las otras razas puede fracasar en cualquier momento, y se habla mucho de que los miembros de la Horda buscan sembrar aún más semillas de desconfianza. Recuerda eso.$B$BA medida que ganes en poder y te sientas más $gpreparado:preparada;, vuelve a verme aquí y veré si te entreno un poco. Es importante que sepas cómo manejar el arma que elijas, entre otras cosas.', 0),
(@ID, 'esMX', 'Hasta entonces, debes saber que los de nuestra especie son más necesarios que nunca en estos tiempos difíciles. La paz con las otras razas puede fracasar en cualquier momento, y se habla mucho de que los miembros de la Horda buscan sembrar aún más semillas de desconfianza. Recuerda eso.$B$BA medida que ganes en poder y te sientas más $gpreparado:preparada;, vuelve a verme aquí y veré si te entreno un poco. Es importante que sepas cómo manejar el arma que elijas, entre otras cosas.', 0);
-- 3119 Sigilo sacralizado
-- https://es.classic.wowhead.com/quest=3119
SET @ID := 3119;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me complace ver que llegaste tan rápido, $n. $gBienvenido:Bienvenida;.$B$BComo probablemente hayas escuchado, todo Teldrassil se agita con las idas y venidas de los viajeros. Incluso a los miembros de la Alianza se les ha permitido acceder a las ramas de Teldrassil para reunirse con otros Kaldorei que se preparan para las aventuras que se avecinan.', 0),
(@ID, 'esMX', 'Me complace ver que llegaste tan rápido, $n. $gBienvenido:Bienvenida;.$B$BComo probablemente hayas escuchado, todo Teldrassil se agita con las idas y venidas de los viajeros. Incluso a los miembros de la Alianza se les ha permitido acceder a las ramas de Teldrassil para reunirse con otros Kaldorei que se preparan para las aventuras que se avecinan.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por ahora no te preocupe por el mundo debajo de Teldrassil. Habrá tiempo para eso más tarde. Ve ahora y habla con los demás en Cañada Umbría; ellos pueden contarte más sobre los eventos que han ocurrido. Ayúdalos de cualquier manera que puedas, y cada vez que sientas que necesitas más capacitación, regresa a mí y te enseñaré lo que pueda.', 0),
(@ID, 'esMX', 'Por ahora no te preocupe por el mundo debajo de Teldrassil. Habrá tiempo para eso más tarde. Ve ahora y habla con los demás en Cañada Umbría; ellos pueden contarte más sobre los eventos que han ocurrido. Ayúdalos de cualquier manera que puedas, y cada vez que sientas que necesitas más capacitación, regresa a mí y te enseñaré lo que pueda.', 0);
-- 3120 El sigilo verdeante
-- https://es.classic.wowhead.com/quest=3120
SET @ID := 3120;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Admiro tu entusiasmo por continuar tu formación, $c.$B$B¿Has estado ya en el Sueño Esmeralda? Puede que aún no sea el momento... Pero todo llegará.$B$BAntes de eso, tenemos otros temas que comentar.', 0),
(@ID, 'esMX', 'Admiro tu entusiasmo por continuar tu formación, $c.$B$B¿Has estado ya en el Sueño Esmeralda? Puede que aún no sea el momento... Pero todo llegará.$B$BAntes de eso, tenemos otros temas que comentar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te voy a instruir en la interpretación de los designios de los espíritus y en los secretos del Sueño Esmeralda.$B$BA medida que ganas poder, aprenderás más de nuestros trances del sueño. Hasta entonces, ven a verme cuando quieras para seguir tu instrucción.', 0),
(@ID, 'esMX', 'Te voy a instruir en la interpretación de los designios de los espíritus y en los secretos del Sueño Esmeralda.$B$BA medida que ganas poder, aprenderás más de nuestros trances del sueño. Hasta entonces, ven a verme cuando quieras para seguir tu instrucción.', 0);
-- 3121 Una extraña petición
-- https://es.classic.wowhead.com/quest=3121
SET @ID := 3121;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado esperando a que Uzer\'i me entregara esto...$B$BDeja que te dé la mezcla de hierbas que preparé para este... experimento...', 0),
(@ID, 'esMX', 'He estado esperando a que Uzer\'i me entregara esto...$B$BDeja que te dé la mezcla de hierbas que preparé para este... experimento...', 0);
