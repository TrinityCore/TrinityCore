-- 2934 Glándula de veneno intacta
-- https://es.classic.wowhead.com/quest=2934
SET @ID := 2934;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes la glándula de veneno? Estoy deseando hacer experimentos ¡y tengo unos cuantos animalitos muy monos para probar el veneno!', 0),
(@ID, 'esMX', '¿Traes la glándula de veneno? Estoy deseando hacer experimentos ¡y tengo unos cuantos animalitos muy monos para probar el veneno!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Magnífico! El veneno es fresco y letal... ¡Gracias!', 0),
(@ID, 'esMX', '¡Magnífico! El veneno es fresco y letal... ¡Gracias!', 0);
-- 2935 Consulta al maestro Gadrin
-- https://es.classic.wowhead.com/quest=2935
SET @ID := 2935;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Que quieres veneno de las arañas de los Secacorteza? Bueno, pues siéntate; lo que voy a decir no te va a gustar.', 0),
(@ID, 'esMX', '¿Que quieres veneno de las arañas de los Secacorteza? Bueno, pues siéntate; lo que voy a decir no te va a gustar.', 0);
-- 2936 Diosa araña
-- https://es.classic.wowhead.com/quest=2936
SET @ID := 2936;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sabes el nombre de la diosa araña?', 0),
(@ID, 'esMX', '¿Sabes el nombre de la diosa araña?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, Elortha no Shadra... Este nombre solo debe ser susurrado, pues tiene un gran poder en el reino de los espíritus.$B$BVoy a preparar el hechizo de invocación...', 0),
(@ID, 'esMX', 'Ah, Elortha no Shadra... Este nombre solo debe ser susurrado, pues tiene un gran poder en el reino de los espíritus.$B$BVoy a preparar el hechizo de invocación...', 0);
-- 2937 Invocar a Shadra
-- https://es.classic.wowhead.com/quest=2937
SET @ID := 2937;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el veneno?', 0),
(@ID, 'esMX', '¿Traes el veneno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente!', 0),
(@ID, 'esMX', '¡Excelente!', 0);
-- 2938 Veneno para Entrañas
-- https://es.classic.wowhead.com/quest=2938
SET @ID := 2938;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te estaba esperando, $n. ¿Me traes algo?', 0),
(@ID, 'esMX', 'Te estaba esperando, $n. ¿Me traes algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien; Lydon dijo que es el veneno más potente que conoce y que lo está estudiando.$B$BEspero que le encuentre muchos usos.$B$BGracias por todo, $n.', 0),
(@ID, 'esMX', 'Muy bien; Lydon dijo que es el veneno más potente que conoce y que lo está estudiando.$B$BEspero que le encuentre muchos usos.$B$BGracias por todo, $n.', 0);
-- 2939 La búsqueda del conocimiento
-- https://es.classic.wowhead.com/quest=2939
SET @ID := 2939;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ¿así que te envía Troyas Brisaluna?$B$B<murmurando>... Siempre está molestándome con esas exageraciones de que ha encontrado algo importante...$B$BMira, $n, te voy a hablar con franqueza. Troyas siempre cree que ha encontrado algo importante en esas ruinas. Y la verdad es que, cualquier cosa de valor que hubiera en ellas, seguramente ha desaparecido ya. Se la habrán llevado los orcos o las arpías que habitan en ellas ahora.$B$BPuedes echar un vistazo por aquí, pero no sé si encontrarás ningún libro que te ayude.', 0),
(@ID, 'esMX', 'Ah, ¿así que te envía Troyas Brisaluna?$B$B<murmurando>... Siempre está molestándome con esas exageraciones de que ha encontrado algo importante...$B$BMira, $n, te voy a hablar con franqueza. Troyas siempre cree que ha encontrado algo importante en esas ruinas. Y la verdad es que, cualquier cosa de valor que hubiera en ellas, seguramente ha desaparecido ya. Se la habrán llevado los orcos o las arpías que habitan en ellas ahora.$B$BPuedes echar un vistazo por aquí, pero no sé si encontrarás ningún libro que te ayude.', 0);
-- 2940 Feralas: una historia
-- https://es.classic.wowhead.com/quest=2940
SET @ID := 2940;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que quieres llevarte Feralas: Una historia?$B$BDeja que me lo piense...$B$BTe prestaré el libro, $n, pero solo si haces algo por mí antes.', 0),
(@ID, 'esMX', '¿Así que quieres llevarte Feralas: Una historia?$B$BDeja que me lo piense...$B$BTe prestaré el libro, $n, pero solo si haces algo por mí antes.', 0);
-- 2941 El préstamo
-- https://es.classic.wowhead.com/quest=2941
SET @ID := 2941;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Una carta... para mí?', 0),
(@ID, 'esMX', '¿Una carta... para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eres otro de los internos de Daryn? Es una gran historiadora, $n. Tienes suerte de estudiar bajo su guía.$B$BAhora deja que coja la Superinstantánea FX. ¡Te va a encantar!', 0),
(@ID, 'esMX', '¿Eres otro de los internos de Daryn? Es una gran historiadora, $n. Tienes suerte de estudiar bajo su guía.$B$BAhora deja que coja la Superinstantánea FX. ¡Te va a encantar!', 0);
-- 2942 La Piedra del mañana
-- https://es.classic.wowhead.com/quest=2942
SET @ID := 2942;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que hayas vuelto, $n. Estoy deseando saber qué has averiguado.', 0),
(@ID, 'esMX', 'Me alegro de que hayas vuelto, $n. Estoy deseando saber qué has averiguado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He estado leyendo desde que te fuiste, $n. Esta piedra que encontraste se llama Piedra del mañana. Aún no tengo muy claro para qué sirve, pero sí sé que debe de ser muy importante, si no, no estaría escondida en el Monolito de Equinex.$B$BYo seguiré con mis estudios. Espero poder contar contigo en un futuro, $n. Gracias por tu ayuda.', 0),
(@ID, 'esMX', 'He estado leyendo desde que te fuiste, $n. Esta piedra que encontraste se llama Piedra del mañana. Aún no tengo muy claro para qué sirve, pero sí sé que debe de ser muy importante, si no, no estaría escondida en el Monolito de Equinex.$B$BYo seguiré con mis estudios. Espero poder contar contigo en un futuro, $n. Gracias por tu ayuda.', 0);
-- 2943 Regresa junto a Troyas
-- https://es.classic.wowhead.com/quest=2943
SET @ID := 2943;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has estado en Darnassus?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has estado en Darnassus?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has traído un libro. ¡Fantástico!', 0),
(@ID, 'esMX', 'Has traído un libro. ¡Fantástico!', 0);
-- 2944 La Superinstantánea FX
-- https://es.classic.wowhead.com/quest=2944
SET @ID := 2944;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que por fin has vuelto, $n. Y me has traído el artilugio que Curgle hizo para mí, perfecto.', 0),
(@ID, 'esMX', 'Así que por fin has vuelto, $n. Y me has traído el artilugio que Curgle hizo para mí, perfecto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien! El invento de Curgle supera todas mis expectativas.$B$BNo te emociones demasiado pero debes saber que tu trabajo me satisface mucho, $n.$B$BVeamos, ¿dónde dejé el libro?', 0),
(@ID, 'esMX', '¡Bien! El invento de Curgle supera todas mis expectativas.$B$BNo te emociones demasiado pero debes saber que tu trabajo me satisface mucho, $n.$B$BVeamos, ¿dónde dejé el libro?', 0);
-- 2945 Un anillo sucio
-- https://es.classic.wowhead.com/quest=2945
SET @ID := 2945;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El artilugio gnómico lleva una plaquita que dice: "Destellamatic 5200". Al parecer, esta máquina limpia los objetos sucios. Tiene una ranura para monedas y dice que hay que insertar el objeto y 3 monedas de plata.$B$B¡Esta máquina es perfecta para limpiar el anillo sucio que encontraste!', 0),
(@ID, 'esMX', 'El artilugio gnómico lleva una plaquita que dice: "Destellamatic 5200". Al parecer, esta máquina limpia los objetos sucios. Tiene una ranura para monedas y dice que hay que insertar el objeto y 3 monedas de plata.$B$B¡Esta máquina es perfecta para limpiar el anillo sucio que encontraste!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pones el anillo en el Destellamatic 5200 y una moneda de plata en la ranura.$B$BLa máquina hace unos ruidos horribles y se sacude de un lado a otro; a saber qué está pasando ahí dentro...$B$BSe detiene de pronto con un sonoro "¡ping!" Aparece una cajita con un lazo rojo. ¡Parece que esta máquina envuelve para regalo!', 0),
(@ID, 'esMX', 'Pones el anillo en el Destellamatic 5200 y una moneda de plata en la ranura.$B$BLa máquina hace unos ruidos horribles y se sacude de un lado a otro; a saber qué está pasando ahí dentro...$B$BSe detiene de pronto con un sonoro "¡ping!" Aparece una cajita con un lazo rojo. ¡Parece que esta máquina envuelve para regalo!', 0);
-- 2946 A ver qué pasa
-- https://es.classic.wowhead.com/quest=2946
SET @ID := 2946;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este pedestal destaca sobre la ardiente arena. No puede ser casualidad que esté aquí...', 0),
(@ID, 'esMX', 'Este pedestal destaca sobre la ardiente arena. No puede ser casualidad que esté aquí...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al tocar el pedestal, los minidiscos empiezan a zumbar y resplandecer. Te cosquillean las manos mientras surge otro Guarda de piedra frente a las puertas de Uldum.$B$B"Saludos; soy el guardián de la entrada. Faltan las Placas de Uldum; incorpóralas a la estructura de los minidiscos y repite la secuencia de acceso. Gracias."', 0),
(@ID, 'esMX', 'Al tocar el pedestal, los minidiscos empiezan a zumbar y resplandecer. Te cosquillean las manos mientras surge otro Guarda de piedra frente a las puertas de Uldum.$B$B"Saludos; soy el guardián de la entrada. Faltan las Placas de Uldum; incorpóralas a la estructura de los minidiscos y repite la secuencia de acceso. Gracias."', 0);
-- 2947 La devolución del anillo
-- https://es.classic.wowhead.com/quest=2947
SET @ID := 2947;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me hagas nada, ¡soy un profesional respetable! Es que el banco ya había cerrado y... Ah, no has venido a cobrar el alquiler.$B$B¡Qué fallo tan tonto! Estás aquí porque necesitas a un buen joyero, ¡uno que no fabrique joyas malditas!$B$BY dime, ¿qué querías?', 0),
(@ID, 'esMX', 'No me hagas nada, ¡soy un profesional respetable! Es que el banco ya había cerrado y... Ah, no has venido a cobrar el alquiler.$B$B¡Qué fallo tan tonto! Estás aquí porque necesitas a un buen joyero, ¡uno que no fabrique joyas malditas!$B$BY dime, ¿qué querías?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un anillo, dices? A ver... Sí, lo hice yo.$B$BTenía una tienda en Gnomeregan antes de todo el lío; a lo mejor me lo dejé al huir. El diseño es muy simple, hice varios de estos.$B$B¿Y lo tenían los Hierro Negro? Bueno, eso no sería nada nuevo. Pero eso es cosa de las autoridades, yo no puedo hacer nada.$B$BY respecto al anillo...', 0),
(@ID, 'esMX', '¿Un anillo, dices? A ver... Sí, lo hice yo.$B$BTenía una tienda en Gnomeregan antes de todo el lío; a lo mejor me lo dejé al huir. El diseño es muy simple, hice varios de estos.$B$B¿Y lo tenían los Hierro Negro? Bueno, eso no sería nada nuevo. Pero eso es cosa de las autoridades, yo no puedo hacer nada.$B$BY respecto al anillo...', 0);
-- 2948 Mejora gnómica
-- https://es.classic.wowhead.com/quest=2948
SET @ID := 2948;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes lo que te pedí? A ver si pronto consigo mis propios materiales...', 0),
(@ID, 'esMX', '¿Traes lo que te pedí? A ver si pronto consigo mis propios materiales...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Es justo lo que necesitaba! Algún día, cuando salga de este maldito lugar, haré los mejores abalorios de Azeroth. Hasta entonces, gracias por traerme todo esto. Te he cobrado solo el precio de coste del anillo.$B$BPor cierto, ¡aquí lo tienes!', 0),
(@ID, 'esMX', '¡Es justo lo que necesitaba! Algún día, cuando salga de este maldito lugar, haré los mejores abalorios de Azeroth. Hasta entonces, gracias por traerme todo esto. Te he cobrado solo el precio de coste del anillo.$B$BPor cierto, ¡aquí lo tienes!', 0);
-- 2949 La devolución del anillo
-- https://es.classic.wowhead.com/quest=2949
SET @ID := 2949;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya podríamos haber encontrado la manera de superar a esos asquerosos gnomos. ¡Seguro que nos robaron los planos de la plataforma! Ladrones hijos de mala... ¿Sí? ¿Querías algo?', 0),
(@ID, 'esMX', 'Ya podríamos haber encontrado la manera de superar a esos asquerosos gnomos. ¡Seguro que nos robaron los planos de la plataforma! Ladrones hijos de mala... ¿Sí? ¿Querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un anillo de Gnomeregan? A ver... No es mío, pero es muy interesante.$B$BLo suyo es muy curioso; durante años y años han sido unos torpes de cuidado y de repente están construyendo plataformas mejores que las nuestras.$B$B¿Que lo tenían los Hierro Negro? ¡Eso es aún más interesante! A lo mejor los gnomos les robaron los planos y los modificaron. Seguro que los enanos querrán vengarse; eso habría que investigarlo.$B$BOye, ese anillo...', 0),
(@ID, 'esMX', '¿Un anillo de Gnomeregan? A ver... No es mío, pero es muy interesante.$B$BLo suyo es muy curioso; durante años y años han sido unos torpes de cuidado y de repente están construyendo plataformas mejores que las nuestras.$B$B¿Que lo tenían los Hierro Negro? ¡Eso es aún más interesante! A lo mejor los gnomos les robaron los planos y los modificaron. Seguro que los enanos querrán vengarse; eso habría que investigarlo.$B$BOye, ese anillo...', 0);
-- 2950 Nogg mejora el anillo
-- https://es.classic.wowhead.com/quest=2950
SET @ID := 2950;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes lo que te pedí? No puedo mejorar el diseño si no tengo los materiales.', 0),
(@ID, 'esMX', '¿Traes lo que te pedí? No puedo mejorar el diseño si no tengo los materiales.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes tu anillo mejorado, y gracias por la información sobre los Hierro Negro. Parece explicar muy bien cómo los gnomos se inspiraron de pronto con ideas de goblin.', 0),
(@ID, 'esMX', 'Aquí tienes tu anillo mejorado, y gracias por la información sobre los Hierro Negro. Parece explicar muy bien cómo los gnomos se inspiraron de pronto con ideas de goblin.', 0);
-- ¡El Destellamatic 5200!
-- 2951, 4601
-- https://es.classic.wowhead.com/quest=2951
DELETE FROM `quest_request_items_locale` WHERE `id` IN(2951, 4601) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(2951, 'esES', 'Para activar el Destellamatic 5200 tienes que insertar un objeto sucio y 3 monedas de plata.', 0),
(4601, 'esES', 'Para activar el Destellamatic 5200 tienes que insertar un objeto sucio y 3 monedas de plata.', 0),
(2951, 'esMX', 'Para activar el Destellamatic 5200 tienes que insertar un objeto sucio y 3 monedas de plata.', 0),
(4601, 'esMX', 'Para activar el Destellamatic 5200 tienes que insertar un objeto sucio y 3 monedas de plata.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(2951, 4601) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2951, 'esES', 'Insertas el objeto sucio y 3 monedas de plata en el Destellamatic 5200. Se pone en marcha como si le fuera la vida en limpiar el objeto; hace unos ruidos tremendos y parece que hasta la carcasa de la máquina se queja...', 0),
(4601, 'esES', 'Insertas el objeto sucio y 3 monedas de plata en el Destellamatic 5200. Se pone en marcha como si le fuera la vida en limpiar el objeto; hace unos ruidos tremendos y parece que hasta la carcasa de la máquina se queja...', 0),
(2951, 'esMX', 'Insertas el objeto sucio y 3 monedas de plata en el Destellamatic 5200. Se pone en marcha como si le fuera la vida en limpiar el objeto; hace unos ruidos tremendos y parece que hasta la carcasa de la máquina se queja...', 0),
(4601, 'esMX', 'Insertas el objeto sucio y 3 monedas de plata en el Destellamatic 5200. Se pone en marcha como si le fuera la vida en limpiar el objeto; hace unos ruidos tremendos y parece que hasta la carcasa de la máquina se queja...', 0);
-- 4602 ¡El Destellamatic 5200!
-- https://es.classic.wowhead.com/quest=4602
SET @ID := 4602;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para activar el Destellamatic 5200 tienes que insertar un objeto sucio y 3 monedas de plata.', 0),
(@ID, 'esMX', 'Para activar el Destellamatic 5200 tienes que insertar un objeto sucio y 3 monedas de plata.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una pequeña placa en el dispositivo dice "El Destellamatic 5200", seguida de un texto:$B$B"¿La suciedad y los residuos arruinan tus brillantes? ¡El Destellamatic 5200 devuelve un brillo fantástico! Inserta el artículo que deseas limpiar y deposita tres monedas de plata en la ranura para monedas. Dale un momento al Destellamatic 5200 para que funcione y ¡listo! los objetos de valor saldrán limpios y relucientes".', 0),
(@ID, 'esMX', 'Una pequeña placa en el dispositivo dice "El Destellamatic 5200", seguida de un texto:$B$B"¿La suciedad y los residuos arruinan tus brillantes? ¡El Destellamatic 5200 devuelve un brillo fantástico! Inserta el artículo que deseas limpiar y deposita tres monedas de plata en la ranura para monedas. Dale un momento al Destellamatic 5200 para que funcione y ¡listo! los objetos de valor saldrán limpios y relucientes".', 0);
-- ¡El Destellamatic 5200!
-- 2952, 4605, 4606
-- https://es.classic.wowhead.com/quest=2952
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(2952, 4605, 4606) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2952, 'esES', 'La máquina se para tan bruscamente como había arrancado. Se oye un "ping" y se abre la boca de la máquina. Dentro del Destellamatic 5200 hay una cajita con un lazo; parece que envuelve para regalo además de limpiar.$B$BSolo hay una forma de saber si el objeto está bien limpio...', 0),
(4605, 'esES', 'La máquina se para tan bruscamente como había arrancado. Se oye un "ping" y se abre la boca de la máquina. Dentro del Destellamatic 5200 hay una cajita con un lazo; parece que envuelve para regalo además de limpiar.$B$BSolo hay una forma de saber si el objeto está bien limpio...', 0),
(4606, 'esES', 'La máquina se para tan bruscamente como había arrancado. Se oye un "ping" y se abre la boca de la máquina. Dentro del Destellamatic 5200 hay una cajita con un lazo; parece que envuelve para regalo además de limpiar.$B$BSolo hay una forma de saber si el objeto está bien limpio...', 0),
(2952, 'esMX', 'La máquina se para tan bruscamente como había arrancado. Se oye un "ping" y se abre la boca de la máquina. Dentro del Destellamatic 5200 hay una cajita con un lazo; parece que envuelve para regalo además de limpiar.$B$BSolo hay una forma de saber si el objeto está bien limpio...', 0),
(4605, 'esMX', 'La máquina se para tan bruscamente como había arrancado. Se oye un "ping" y se abre la boca de la máquina. Dentro del Destellamatic 5200 hay una cajita con un lazo; parece que envuelve para regalo además de limpiar.$B$BSolo hay una forma de saber si el objeto está bien limpio...', 0),
(4606, 'esMX', 'La máquina se para tan bruscamente como había arrancado. Se oye un "ping" y se abre la boca de la máquina. Dentro del Destellamatic 5200 hay una cajita con un lazo; parece que envuelve para regalo además de limpiar.$B$BSolo hay una forma de saber si el objeto está bien limpio...', 0);
-- El Destellamatic en acción
-- 2953, 4603, 4604
-- https://es.classic.wowhead.com/quest=2953
DELETE FROM `quest_request_items_locale` WHERE `id` IN(2953, 4603, 4604) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(2953, 'esES', 'El Destellamatic 5200 parece estar esperando un objeto sucio que limpiar y 3 monedas de plata para activarse.', 0),
(4603, 'esES', 'El Destellamatic 5200 parece estar esperando un objeto sucio que limpiar y 3 monedas de plata para activarse.', 0),
(4604, 'esES', 'El Destellamatic 5200 parece estar esperando un objeto sucio que limpiar y 3 monedas de plata para activarse.', 0),
(2953, 'esMX', 'El Destellamatic 5200 parece estar esperando un objeto sucio que limpiar y 3 monedas de plata para activarse.', 0),
(4603, 'esMX', 'El Destellamatic 5200 parece estar esperando un objeto sucio que limpiar y 3 monedas de plata para activarse.', 0),
(4604, 'esMX', 'El Destellamatic 5200 parece estar esperando un objeto sucio que limpiar y 3 monedas de plata para activarse.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(2953, 4603, 4604) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2953, 'esES', 'El Destellamatic 5200 se pone en marcha con sacudidas. El limpiador gnómico parece estar pulverizando el objeto del interior de la máquina.$B$BLa máquina se para con un "¡ping!" y la boca se abre para revelar una cajita muy bien envuelta.', 0),
(4603, 'esES', 'El Destellamatic 5200 se pone en marcha con sacudidas. El limpiador gnómico parece estar pulverizando el objeto del interior de la máquina.$B$BLa máquina se para con un "¡ping!" y la boca se abre para revelar una cajita muy bien envuelta.', 0),
(4604, 'esES', 'El Destellamatic 5200 se pone en marcha con sacudidas. El limpiador gnómico parece estar pulverizando el objeto del interior de la máquina.$B$BLa máquina se para con un "¡ping!" y la boca se abre para revelar una cajita muy bien envuelta.', 0),
(2953, 'esMX', 'El Destellamatic 5200 se pone en marcha con sacudidas. El limpiador gnómico parece estar pulverizando el objeto del interior de la máquina.$B$BLa máquina se para con un "¡ping!" y la boca se abre para revelar una cajita muy bien envuelta.', 0),
(4603, 'esMX', 'El Destellamatic 5200 se pone en marcha con sacudidas. El limpiador gnómico parece estar pulverizando el objeto del interior de la máquina.$B$BLa máquina se para con un "¡ping!" y la boca se abre para revelar una cajita muy bien envuelta.', 0),
(4604, 'esMX', 'El Destellamatic 5200 se pone en marcha con sacudidas. El limpiador gnómico parece estar pulverizando el objeto del interior de la máquina.$B$BLa máquina se para con un "¡ping!" y la boca se abre para revelar una cajita muy bien envuelta.', 0);
-- 2954 El vigía de piedra
-- https://es.classic.wowhead.com/quest=2954
SET @ID := 2954;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El propósito del guardián de piedra debe conocerse antes de continuar...', 0),
(@ID, 'esMX', 'El propósito del guardián de piedra debe conocerse antes de continuar...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La voz del guardián de piedra resuena con fuerza y autoridad:$B$B"Los discos te serán devueltos una vez que accedas al pedestal. Cuando las Placas de Uldum obren en tu poder y estén integradas con el conjunto de discos que tienes, podrás acceder al complejo."', 0),
(@ID, 'esMX', 'La voz del guardián de piedra resuena con fuerza y autoridad:$B$B"Los discos te serán devueltos una vez que accedas al pedestal. Cuando las Placas de Uldum obren en tu poder y estén integradas con el conjunto de discos que tienes, podrás acceder al complejo."', 0);
-- 2963 Presagios de Uldum
-- https://es.classic.wowhead.com/quest=2963
SET @ID := 2963;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me alegro de que sigas $ginteresado:interesada; en la exploración, $n! ¡Con tu talento natural y tu energía, podríamos descifrar secretos que nunca pensamos que fueran posibles!$B$BLos discos de Norgannon en Uldaman eran un depósito de vasta información; sólo se te permitió acceder a las capas superiores, por así decirlo, de la información almacenada. Se rumoreaba que los Creadores tenían más depósitos ubicados en todo Azeroth. Lo cual, nos lleva a Uldum...', 0),
(@ID, 'esMX', '¡Me alegro de que sigas $ginteresado:interesada; en la exploración, $n! ¡Con tu talento natural y tu energía, podríamos descifrar secretos que nunca pensamos que fueran posibles!$B$BLos discos de Norgannon en Uldaman eran un depósito de vasta información; sólo se te permitió acceder a las capas superiores, por así decirlo, de la información almacenada. Se rumoreaba que los Creadores tenían más depósitos ubicados en todo Azeroth. Lo cual, nos lleva a Uldum...', 0);
-- Una tarea futura
-- 2964, 2968
-- https://es.classic.wowhead.com/quest=2964
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(2964, 2968) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2964, 'esES', 'Entonces, todos estamos de acuerdo en que lo mejor es esperar hasta que podamos delimitar las áreas en las que es posible que estén las placas. Hemos llegado hasta aquí gracias a ti, $n, y espero que seas tú quien haga frente a los secretos de Uldum.$B$BHasta entonces, permíteme que te entregue este honorario que cubre los gastos que has realizado y un pellizquito más para ti. Vuelve pronto por aquí... Uldum nos espera a todos, joven.', 0),
(2968, 'esES', 'Entonces, todos estamos de acuerdo en que lo mejor es esperar hasta que podamos delimitar las áreas en las que es posible que estén las placas. Hemos llegado hasta aquí gracias a ti, $n, y espero que seas tú quien haga frente a los secretos de Uldum.$B$BHasta entonces, permíteme que te entregue este honorario que cubre los gastos que has realizado y un pellizquito más para ti. Vuelve pronto por aquí... Uldum nos espera a todos, joven.', 0),
(2964, 'esMX', 'Entonces, todos estamos de acuerdo en que lo mejor es esperar hasta que podamos delimitar las áreas en las que es posible que estén las placas. Hemos llegado hasta aquí gracias a ti, $n, y espero que seas tú quien haga frente a los secretos de Uldum.$B$BHasta entonces, permíteme que te entregue este honorario que cubre los gastos que has realizado y un pellizquito más para ti. Vuelve pronto por aquí... Uldum nos espera a todos, joven.', 0),
(2968, 'esMX', 'Entonces, todos estamos de acuerdo en que lo mejor es esperar hasta que podamos delimitar las áreas en las que es posible que estén las placas. Hemos llegado hasta aquí gracias a ti, $n, y espero que seas tú quien haga frente a los secretos de Uldum.$B$BHasta entonces, permíteme que te entregue este honorario que cubre los gastos que has realizado y un pellizquito más para ti. Vuelve pronto por aquí... Uldum nos espera a todos, joven.', 0);
-- 2965 Presagios de Uldum
-- https://es.classic.wowhead.com/quest=2965
SET @ID := 2965;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay un lugar, en lo más profundo del Desierto de Tanaris llamado Valle de los Vigías. Los discos que has recuperado... contienen unos glifos que hablan de un lugar llamado Uldum. Muchos creen que este lugar no es más que un mito.$B$BYo sé que no es cierto; Uldum existe. Yo he estado allí. Bueno... por allí cerca.$B$BHe aquí el quid de la cuestión, $n: creemos que hay una conexión entre los discos y Uldum, por eso queremos que vayas allí.', 0),
(@ID, 'esMX', 'Hay un lugar, en lo más profundo del Desierto de Tanaris llamado Valle de los Vigías. Los discos que has recuperado... contienen unos glifos que hablan de un lugar llamado Uldum. Muchos creen que este lugar no es más que un mito.$B$BYo sé que no es cierto; Uldum existe. Yo he estado allí. Bueno... por allí cerca.$B$BHe aquí el quid de la cuestión, $n: creemos que hay una conexión entre los discos y Uldum, por eso queremos que vayas allí.', 0);
-- 2966 A ver qué pasa
-- https://es.classic.wowhead.com/quest=2966
SET @ID := 2966;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este pedestal que sobresale de la ardiente arena te resulta familiar. Quizás su presencia signifique algo...', 0),
(@ID, 'esMX', 'Este pedestal que sobresale de la ardiente arena te resulta familiar. Quizás su presencia signifique algo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando tocas el pedestal, los discos en miniatura de Uldaman producen un zumbido y resplandecen en tu mochila. La sensación familiar de cosquilleo se extiende por tus manos mientras otro guardián de piedra cobra vida frente a las puertas de Uldum.$B$B"Saludos. Soy un guardián de la entrada. Entre los discos utilizados para entrar faltan los discos correctos de entrada: las Placas de Uldum. Por favor, incorpora estas placas a la estructura de los discos y repite el proceso para poder entrar. Gracias."', 0),
(@ID, 'esMX', 'Cuando tocas el pedestal, los discos en miniatura de Uldaman producen un zumbido y resplandecen en tu mochila. La sensación familiar de cosquilleo se extiende por tus manos mientras otro guardián de piedra cobra vida frente a las puertas de Uldum.$B$B"Saludos. Soy un guardián de la entrada. Entre los discos utilizados para entrar faltan los discos correctos de entrada: las Placas de Uldum. Por favor, incorpora estas placas a la estructura de los discos y repite el proceso para poder entrar. Gracias."', 0);
-- 2967 Regresa a Cima del Trueno
-- https://es.classic.wowhead.com/quest=2967
SET @ID := 2967;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Les has sacado provecho a los discos o no has conseguido nada?', 0),
(@ID, 'esMX', '$gBienvenido:Bienvenida; de nuevo, $n. ¿Les has sacado provecho a los discos o no has conseguido nada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te faltaban algunos discos? Vaya, es curioso pero parece que los Discos de Norgannon son solo una pieza más del conjunto; como las llaves de un llavero, si prefieres.$B$BSi encontramos las Placas de Uldum, podremos por fin acceder al mismísimo complejo de Uldum. Sin embargo, no sé si alegrarme o preocuparme.$B$BQuizás tengamos que arriesgar todo para asegurar que los secretos que alberga la tierra y que nos destruirían a todos sigan siendo eso, secretos.', 0),
(@ID, 'esMX', '¿Te faltaban algunos discos? Vaya, es curioso pero parece que los Discos de Norgannon son solo una pieza más del conjunto; como las llaves de un llavero, si prefieres.$B$BSi encontramos las Placas de Uldum, podremos por fin acceder al mismísimo complejo de Uldum. Sin embargo, no sé si alegrarme o preocuparme.$B$BQuizás tengamos que arriesgar todo para asegurar que los secretos que alberga la tierra y que nos destruirían a todos sigan siendo eso, secretos.', 0);
-- 2969 Libertad para todas las criaturas
-- https://es.classic.wowhead.com/quest=2969
SET @ID := 2969;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias a Elune, $n! Eres una bendición para todos nosotros y también para los dragones que salvaste. Jer\'kai y yo jamás habríamos podido ayudarlos. Tu intervención en los asuntos de los Tótem Siniestro será recordada.$B$BAhora habla con Jer\'kai... Tengo que preparar nuestra retribución. Que los dragones feéricos estén libres ahora, no quiere decir que vayan a seguir así. Jer\'kai y yo seguiremos adelante con la ofensiva.', 0),
(@ID, 'esMX', '¡Gracias a Elune, $n! Eres una bendición para todos nosotros y también para los dragones que salvaste. Jer\'kai y yo jamás habríamos podido ayudarlos. Tu intervención en los asuntos de los Tótem Siniestro será recordada.$B$BAhora habla con Jer\'kai... Tengo que preparar nuestra retribución. Que los dragones feéricos estén libres ahora, no quiere decir que vayan a seguir así. Jer\'kai y yo seguiremos adelante con la ofensiva.', 0);
-- 2970 La justicia del castigo
-- https://es.classic.wowhead.com/quest=2970
SET @ID := 2970;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Kindal necesita tiempo para prepararse, pero nuestras muertes ya se cuentan por docenas. El clan Tótem Siniestro es más que consciente de nuestra presencia en la zona y nos buscan como víboras.$B$BHarán todo lo que esté a su alcance para separar la cabeza de nuestros cuerpos. Deberías estar alerta... ellos también vendrán por ti ahora que has interferido.', 0),
(@ID, 'esMX', 'Kindal necesita tiempo para prepararse, pero nuestras muertes ya se cuentan por docenas. El clan Tótem Siniestro es más que consciente de nuestra presencia en la zona y nos buscan como víboras.$B$BHarán todo lo que esté a su alcance para separar la cabeza de nuestros cuerpos. Deberías estar alerta... ellos también vendrán por ti ahora que has interferido.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Kindal tenía razón sobre ti, $n. Tienes un don para esto. Tienes más experiencia que cualquiera de nosotros y te estamos agradecidos.$B$BEl clan Tótem Siniestro es mucho más hostil que muchos tauren... Me pregunto si el resto de su raza frunce el ceño antes sus actos. No me sorprendería. Como ya habrás notado, muchas razas de Azeroth están vinculadas a homólogos menos amables.$B$BPero dejaremos ese tema para otro día.', 0),
(@ID, 'esMX', 'Kindal tenía razón sobre ti, $n. Tienes un don para esto. Tienes más experiencia que cualquiera de nosotros y te estamos agradecidos.$B$BEl clan Tótem Siniestro es mucho más hostil que muchos tauren... Me pregunto si el resto de su raza frunce el ceño antes sus actos. No me sorprendería. Como ya habrás notado, muchas razas de Azeroth están vinculadas a homólogos menos amables.$B$BPero dejaremos ese tema para otro día.', 0);
