-- Talismanes del mérito
-- 7886, 7887, 7888, 7921, 8292
-- https://es.classic.wowhead.com/quest=7886
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7886, 7887, 7888, 7921, 8292) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7886, 'esES', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(7887, 'esES', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(7888, 'esES', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(7921, 'esES', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(8292, 'esES', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(7886, 'esMX', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(7887, 'esMX', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(7888, 'esMX', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(7921, 'esMX', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0),
(8292, 'esMX', 'Gracias, $n. Tus hazañas en Garganta Grito de Guerra resuenan por todo el Bosque de Vallefresno.', 0);
-- 7889 Contrapeso burdo
-- https://es.classic.wowhead.com/quest=7889
SET @ID := 7889;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Se necesita mucho trabajo para ser la mujer más fuerte del mundo! Mi conjunto de pesas se está volviendo demasiado liviano y si quiero mantenerme en forma, ¡necesitaré más pesas!$B$B¿Crees que podrías traerme algunas piedras de peso? Si lo haces, te daré un boleto para la Feria de la Luna Negra.', 0),
(@ID, 'esMX', '¡Se necesita mucho trabajo para ser la mujer más fuerte del mundo! Mi conjunto de pesas se está volviendo demasiado liviano y si quiero mantenerme en forma, ¡necesitaré más pesas!$B$B¿Crees que podrías traerme algunas piedras de peso? Si lo haces, te daré un boleto para la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡Estos funcionarán muy bien! No son demasiado pesados, pero tampoco demasiado livianos. ¡Son perfectos para desarrollar masa muscular!$B$BMuchas gracias, $n. ¡Aquí tienes tu boleto para la Feria de la Luna Negra!', 0),
(@ID, 'esMX', '¡Genial! ¡Estos funcionarán muy bien! No son demasiado pesados, pero tampoco demasiado livianos. ¡Son perfectos para desarrollar masa muscular!$B$BMuchas gracias, $n. ¡Aquí tienes tu boleto para la Feria de la Luna Negra!', 0);
-- 7890 Piedra de pulir pesada
-- https://es.classic.wowhead.com/quest=7890
SET @ID := 7890;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para ayudarme con mi entrenamiento, me gusta colocar un bastón entre pesadas piedras de moler y luego levantar el bastón sobre mi cabeza. No es fácil, pero ser la mujer más fuerte del mundo, como yo, ¡no se puede ganar sentada!$B$B¿Me puedes ayudar? Necesito más piedras de moler, tráeme algunas y cambiaré entradas para la Feria de la Luna Negra por ellas.', 0),
(@ID, 'esMX', 'Para ayudarme con mi entrenamiento, me gusta colocar un bastón entre pesadas piedras de moler y luego levantar el bastón sobre mi cabeza. No es fácil, pero ser la mujer más fuerte del mundo, como yo, ¡no se puede ganar sentada!$B$B¿Me puedes ayudar? Necesito más piedras de moler, tráeme algunas y cambiaré entradas para la Feria de la Luna Negra por ellas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Trajiste las piedras! ¡Y son pesados! Ya puedo sentir que mis músculos se agrandan. ¡Gracias $n!$B$BToma, toma estos boletos y asegúrate de no comer demasiados dulces mientras estás en la feria. ¡$gUn:Una; $n grande y fuerte como tú necesita mantenerse en forma para luchar!', 0),
(@ID, 'esMX', '¡Trajiste las piedras! ¡Y son pesados! Ya puedo sentir que mis músculos se agrandan. ¡Gracias $n!$B$BToma, toma estos boletos y asegúrate de no comer demasiados dulces mientras estás en la feria. ¡$gUn:Una; $n grande y fuerte como tú necesita mantenerse en forma para luchar!', 0);
-- 7891 Brazales de hierro verdes
-- https://es.classic.wowhead.com/quest=7891
SET @ID := 7891;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy trabajando en un nuevo disfraz, ¡para cuando tenga mi propio stand como la mujer más fuerte del mundo! Ahora mismo estoy buscando unos brazaletes que pueda usar. No pueden cubrir mucho porque la gente quiere ver mis músculos, pero quiero mostrar un poco de color, ¿sabes?$B$B¿Qué tal unos brazaletes de hierro verde, $n? ¿Puedes hacerme brazaletes de hierro verde? Si puedes, tengo un montón de vales para la Feria de la Luna Negra.', 0),
(@ID, 'esMX', 'Estoy trabajando en un nuevo disfraz, ¡para cuando tenga mi propio stand como la mujer más fuerte del mundo! Ahora mismo estoy buscando unos brazaletes que pueda usar. No pueden cubrir mucho porque la gente quiere ver mis músculos, pero quiero mostrar un poco de color, ¿sabes?$B$B¿Qué tal unos brazaletes de hierro verde, $n? ¿Puedes hacerme brazaletes de hierro verde? Si puedes, tengo un montón de vales para la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. ¡Aquí tienes tus entradas para la Feria de la Luna Negra!', 0),
(@ID, 'esMX', 'Muchas gracias, $n. ¡Aquí tienes tus entradas para la Feria de la Luna Negra!', 0);
-- 7892 Maza negra grande
-- https://es.classic.wowhead.com/quest=7892
SET @ID := 7892;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para mi actuación de ser la mujer más fuerte del mundo, planeo aceptar artículos de la audiencia y aplastarlos con una gran maza negra.$B$B¿Puedes hacerme una gran maza negra, $n?', 0),
(@ID, 'esMX', 'Para mi actuación de ser la mujer más fuerte del mundo, planeo aceptar artículos de la audiencia y aplastarlos con una gran maza negra.$B$B¿Puedes hacerme una gran maza negra, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. ¡Aquí tienes tus vales para la Feria de la Luna Negra!', 0),
(@ID, 'esMX', 'Muchas gracias, $n. ¡Aquí tienes tus vales para la Feria de la Luna Negra!', 0);
-- 7893 Ritual de fuerza
-- https://es.classic.wowhead.com/quest=7893
SET @ID := 7893;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, en mi búsqueda por convertirme en la mujer más fuerte del mundo, he viajado por el mundo y he aprendido los secretos del desarrollo muscular de maestros de peso lejanos, gurús de la fuerza y manuales antiguos. ¡Ahora conozco ejercicios prohibidos que matarían a los débiles y paralizarían a los no iniciados!$B$BEstas hazañas de fuerza y acondicionamiento requieren entrenamiento con las piedras de moler más densas. $n, ¿puedes encontrar o hacer algunas piedras de moler y traermelas? Te daré vales si lo haces...', 0),
(@ID, 'esMX', '$n, en mi búsqueda por convertirme en la mujer más fuerte del mundo, he viajado por el mundo y he aprendido los secretos del desarrollo muscular de maestros de peso lejanos, gurús de la fuerza y manuales antiguos. ¡Ahora conozco ejercicios prohibidos que matarían a los débiles y paralizarían a los no iniciados!$B$BEstas hazañas de fuerza y acondicionamiento requieren entrenamiento con las piedras de moler más densas. $n, ¿puedes encontrar o hacer algunas piedras de moler y traermelas? Te daré vales si lo haces...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. ¡Aquí tienes tus vales para la Feria de la Luna Negra!', 0),
(@ID, 'esMX', 'Muchas gracias, $n. ¡Aquí tienes tus vales para la Feria de la Luna Negra!', 0);
-- 7894 Modulador de cobre
-- Notice: English text change 'Grimling' to '$n' in quest_offer_reward.RewardText
-- https://es.classic.wowhead.com/quest=7894
SET @ID := 7894;
UPDATE `quest_offer_reward` SET `RewardText` = 'Aha! The modulators! Superb!$B$BI can\'t tell you exactly what we\'re building, but these will be invaluable for its construction. I am in your debt, $n, but please, take this Darkmoon Faire ticket as a token of my appreciation.', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yebb está desarrollando una nueva atracción para Zoo de Rarezas, ¡una que enloquecerá a la gente con asombro y deleite! Pero requerirá mucho trabajo y muchos materiales...$B$BEso incluye moduladores de cobre. Necesitamos muchos moduladores para las partes mecánicas de la atracción. Tráeme moduladores de cobre y los cambiaré por un boleto de la Feria de la Luna Negra.', 0),
(@ID, 'esMX', 'Yebb está desarrollando una nueva atracción para Zoo de Rarezas, ¡una que enloquecerá a la gente con asombro y deleite! Pero requerirá mucho trabajo y muchos materiales...$B$BEso incluye moduladores de cobre. Necesitamos muchos moduladores para las partes mecánicas de la atracción. Tráeme moduladores de cobre y los cambiaré por un boleto de la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ajá! ¡Los moduladores! ¡Magnífico!$B$BNo puedo decirte exactamente lo que estamos construyendo, pero son fundamentales para su construcción. Estoy en deuda contigo, $n, pero por favor, toma este boleto de la Feria de la Luna Negra como muestra de mi agradecimiento.', 0),
(@ID, 'esMX', '¡Ajá! ¡Los moduladores! ¡Magnífico!$B$BNo puedo decirte exactamente lo que estamos construyendo, pero son fundamentales para su construcción. Estoy en deuda contigo, $n, pero por favor, toma este boleto de la Feria de la Luna Negra como muestra de mi agradecimiento.', 0);
-- 7895 Cacharros zumbones de bronce
-- https://es.classic.wowhead.com/quest=7895
SET @ID := 7895;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi nuevo stand será un espectáculo digno de ver, ¡sí señor! ¡Un espectáculo para ver y... para unos pocos afortunados, para tocar!$B$B¡Ya puedo escuchar el zumbido de los aparatos de bronce cantando su canción de éxtasis mecánico mientras los clientes se acercan a mi puesto y prueban su habilidad!$B$BAh... ahora necesito los Cacharros para hacer realidad mi sueño. Por favor, $n, tráeme Cacharros zumbones de bronce... ¡y las entradas para la Feria de la Luna Negra serán tuyas!', 0),
(@ID, 'esMX', 'Mi nuevo stand será un espectáculo digno de ver, ¡sí señor! ¡Un espectáculo para ver y... para unos pocos afortunados, para tocar!$B$B¡Ya puedo escuchar el zumbido de los aparatos de bronce cantando su canción de éxtasis mecánico mientras los clientes se acercan a mi puesto y prueban su habilidad!$B$BAh... ahora necesito los Cacharros para hacer realidad mi sueño. Por favor, $n, tráeme Cacharros zumbones de bronce... ¡y las entradas para la Feria de la Luna Negra serán tuyas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Trajiste los Cacharros! ¡Maravilloso! ¡Incluso ahora puedo escuchar su zumbido en mi mente! ¡Oh, cuando este stand esté listo será la maravilla del mundo!$B$BAquí están sus boletos, $n. ¡Y disfruta de tu estancia en la Feria!', 0),
(@ID, 'esMX', '¡Trajiste los Cacharros! ¡Maravilloso! ¡Incluso ahora puedo escuchar su zumbido en mi mente! ¡Oh, cuando este stand esté listo será la maravilla del mundo!$B$BAquí están sus boletos, $n. ¡Y disfruta de tu estancia en la Feria!', 0);
-- 7897 Juegos de herramientas mecánicas de reparación
-- https://es.classic.wowhead.com/quest=7897
SET @ID := 7897;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La principal razón por la que no puedo abrir mi puesto es que... ¡todo está roto! ¡Necesito kits de reparación mecánica para arreglar todas estas cosas!$B$B¿Puedes traerme esos kits, $n? Te cambiaré... kits por boletos para la Feria de la Luna Negra. ¿Qué dices?', 0),
(@ID, 'esMX', 'La principal razón por la que no puedo abrir mi puesto es que... ¡todo está roto! ¡Necesito kits de reparación mecánica para arreglar todas estas cosas!$B$B¿Puedes traerme esos kits, $n? Te cambiaré... kits por boletos para la Feria de la Luna Negra. ¿Qué dices?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Gracias! Ahora puedo arreglar las cosas.$B$BSe necesitarán muchos kits de reparación y muchas horas de la noche para que todo funcione correctamente. A veces pienso que sería mejor volver a mis raíces y reiniciar mi carrera como cazatalentos, pero... la Feria ha sido buena conmigo.$B$B¡Toma estos boletos, $n, y diviértete!', 0),
(@ID, 'esMX', '¡Gracias! Ahora puedo arreglar las cosas.$B$BSe necesitarán muchos kits de reparación y muchas horas de la noche para que todo funcione correctamente. A veces pienso que sería mejor volver a mis raíces y reiniciar mi carrera como cazatalentos, pero... la Feria ha sido buena conmigo.$B$B¡Toma estos boletos, $n, y diviértete!', 0);
-- 7898 Trastos de torio
-- https://es.classic.wowhead.com/quest=7898
SET @ID := 7898;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yebb Nebblegear, como yo, está trabajando en una atracción futura. Tan asombrosa es esta atracción, dice Nebb, que atraerá a gente de todo el mundo... ¡y nos hará a todos muy, muy ricos!$B$BDice que necesita trastos de torio para su construcción y quiere que se los recoja. Entonces, ¿qué dices, $n? ¿Sabes dónde conseguir los trastos de torio? Si eres ingeniero, ¿puedes hacerlos? ¿Quieres canjearlos por entradas para la Feria de la Luna Negra?', 0),
(@ID, 'esMX', 'Yebb Nebblegear, como yo, está trabajando en una atracción futura. Tan asombrosa es esta atracción, dice Nebb, que atraerá a gente de todo el mundo... ¡y nos hará a todos muy, muy ricos!$B$BDice que necesita trastos de torio para su construcción y quiere que se los recoja. Entonces, ¿qué dices, $n? ¿Sabes dónde conseguir los trastos de torio? Si eres ingeniero, ¿puedes hacerlos? ¿Quieres canjearlos por entradas para la Feria de la Luna Negra?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, gracias, $n! Yebb disfrutará de estos trastos. No sé qué ha planeado para ellos, pero Yebb es un pequeño gnomo inteligente. Es inteligente, y tal vez un poco tortuoso...$B$BSi tan solo le gustara el sabor de la carne humanoide... ¡sería un gran troll!$B$BAquí, $n. Un trato es un trato, y estos boletos son tuyos.', 0),
(@ID, 'esMX', '¡Ah, gracias, $n! Yebb disfrutará de estos trastos. No sé qué ha planeado para ellos, pero Yebb es un pequeño gnomo inteligente. Es inteligente, y tal vez un poco tortuoso...$B$BSi tan solo le gustara el sabor de la carne humanoide... ¡sería un gran troll!$B$BAquí, $n. Un trato es un trato, y estos boletos son tuyos.', 0);
-- 7899 Patitas peludas
-- https://es.classic.wowhead.com/quest=7899
SET @ID := 7899;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La primera lección para atraer a una multitud es: ¡atraerlos con artilugios y baratijas! ¿Me puedes ayudar?$B$BNecesito unas pequeñas patas peludas para ganar premios. Puedes encontrarlas en los gatos de Los Baldíos o Costa Oscura...$B$BTráeme algunas patas y te cambiaré un boleto para la Feria de la Luna Negra por ellas.', 0),
(@ID, 'esMX', 'La primera lección para atraer a una multitud es: ¡atraerlos con artilugios y baratijas! ¿Me puedes ayudar?$B$BNecesito unas pequeñas patas peludas para ganar premios. Puedes encontrarlas en los gatos de Los Baldíos o Costa Oscura...$B$BTráeme algunas patas y te cambiaré un boleto para la Feria de la Luna Negra por ellas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, las tienes! Podemos usarlas para hacer juguetes y chucherías, ¡y atraerán a más personas a la feria!$B$BAquí está tu boleto, $n. ¡Te lo has ganado!', 0),
(@ID, 'esMX', '¡Genial, las tienes! Podemos usarlas para hacer juguetes y chucherías, ¡y atraerán a más personas a la feria!$B$BAquí está tu boleto, $n. ¡Te lo has ganado!', 0);
-- 7900 Pieles de oso
-- https://es.classic.wowhead.com/quest=7900
SET @ID := 7900;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡A los niños les encantan los juguetes! ¡Y no importa de qué raza, he descubierto que a todos los niños les encantan los juguetes peludos hechos con pelambre de oso rasgado!$B$BPuedes conseguir esas pieles de los osos de Vallefresno o Trabalomas. ¡Tráeme un montón de ellas y gana un montón de boletos para la Feria de la Luna Negra!', 0),
(@ID, 'esMX', '¡A los niños les encantan los juguetes! ¡Y no importa de qué raza, he descubierto que a todos los niños les encantan los juguetes peludos hechos con pelambre de oso rasgado!$B$BPuedes conseguir esas pieles de los osos de Vallefresno o Trabalomas. ¡Tráeme un montón de ellas y gana un montón de boletos para la Feria de la Luna Negra!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bonitas pieles, $n! Conseguiré que alguien las cosa en un montón de peluches. Con un poco de relleno y pintura, creo que serán la envidia de los niños de todo Azeroth.$B$B¿Boletos? ¡Ah, sí, tu pago!$B$B¡Aquí están!', 0),
(@ID, 'esMX', '¡Bonitas pieles, $n! Conseguiré que alguien las cosa en un montón de peluches. Con un poco de relleno y pintura, creo que serán la envidia de los niños de todo Azeroth.$B$B¿Boletos? ¡Ah, sí, tu pago!$B$B¡Aquí están!', 0);
-- 7901 Colas peludas blandas
-- https://es.classic.wowhead.com/quest=7901
SET @ID := 7901;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Es asombroso lo que la gente valora! Tomemos, por ejemplo, un palo de madera con una cola suave y tupida. Ahora, tú y yo podríamos pensar que algo así no es tan valioso... pero si le das a ese pedazo de basura un nombre ordenado como "Cola de Pelusa Salvaje" y lo pones en una bonita caja, la gente pensará que es valioso. ¡La basura se convierte en un tesoro!$B$BConsígueme colas suaves y tupidas de los lobos de Desolace y las Tierras Inhóspitas, y te daré boletos para la Feria de la Luna Negra.', 0),
(@ID, 'esMX', '¡Es asombroso lo que la gente valora! Tomemos, por ejemplo, un palo de madera con una cola suave y tupida. Ahora, tú y yo podríamos pensar que algo así no es tan valioso... pero si le das a ese pedazo de basura un nombre ordenado como "Cola de Pelusa Salvaje" y lo pones en una bonita caja, la gente pensará que es valioso. ¡La basura se convierte en un tesoro!$B$BConsígueme colas suaves y tupidas de los lobos de Desolace y las Tierras Inhóspitas, y te daré boletos para la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Estas colas serán grandes premios para nuestros visitantes, y eso significa visitantes felices... ¡que hablan con sus amigos y traen más visitantes!$B$B¡Aquí tienes tus boletos! Diviértete en la Feria de la Luna Negra... ¡y no olvides hablarles a tus amigos sobre nosotros!', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Estas colas serán grandes premios para nuestros visitantes, y eso significa visitantes felices... ¡que hablan con sus amigos y traen más visitantes!$B$B¡Aquí tienes tus boletos! Diviértete en la Feria de la Luna Negra... ¡y no olvides hablarles a tus amigos sobre nosotros!', 0);
-- 7902 Péndolas vibrantes
-- https://es.classic.wowhead.com/quest=7902
SET @ID := 7902;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La imaginación de una persona es algo increíble. Puede hacer que la colina más pequeña parezca la montaña más grande. ¡Puede hacer que la sombra más inocua parezca proyectada por una horrible pesadilla!$B$B¡En la Feria de la Luna Negra dejamos florecer la imaginación de nuestros visitantes! Pero para ayudar a estimular su imaginación... a veces tenemos que ponernos complicados.$B$BNecesito péndolas vibrantes para una de mis atracciones. Puedes conseguirlos de las aves de las zonas más peligrosas de Azeroth. ¡Tráeme las plumas y muchos boletos serán tuyos!', 0),
(@ID, 'esMX', 'La imaginación de una persona es algo increíble. Puede hacer que la colina más pequeña parezca la montaña más grande. ¡Puede hacer que la sombra más inocua parezca proyectada por una horrible pesadilla!$B$B¡En la Feria de la Luna Negra dejamos florecer la imaginación de nuestros visitantes! Pero para ayudar a estimular su imaginación... a veces tenemos que ponernos complicados.$B$BNecesito péndolas vibrantes para una de mis atracciones. Puedes conseguirlos de las aves de las zonas más peligrosas de Azeroth. ¡Tráeme las plumas y muchos boletos serán tuyos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, las plumas! Son increíbles, ¿no te parece? ¡Sería fácil despertar la imaginación con tales bellezas!$B$BHaces un trabajo caritativo, $n. Las sonrisas en los rostros de nuestros visitantes cuando ven el espectáculo es un gran pago, pero por favor toma también estos boletos.', 0),
(@ID, 'esMX', '¡Ah, las plumas! Son increíbles, ¿no te parece? ¡Sería fácil despertar la imaginación con tales bellezas!$B$BHaces un trabajo caritativo, $n. Las sonrisas en los rostros de nuestros visitantes cuando ven el espectáculo es un gran pago, pero por favor toma también estos boletos.', 0);
-- 7903 Ojos de murciélago malignos
-- https://es.classic.wowhead.com/quest=7903
SET @ID := 7903;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna vez te has encontrado vagando por una cueva, a altas horas de la noche, en busca de aventuras? ¿Lo haces? ¿En serio? Bueno, entonces has visto los ojos espeluznantes de los murciélagos mirándote desde lo alto, esperando que bajes la guardia para que puedan chuparte la sangre.$B$BPensamiento aterrador, ¿no crees? ¡Por supuesto! ¡No hay duda de que los ojos de murciélago dan miedo!$B$B¿Me traerás unos ojos de murciélago malvados, $n? Los quiero para... algo que estoy diseñando. Algo aterrador.$B$BPuedes conseguirlos de los murciélagos de las Tierras de la Peste del Este.', 0),
(@ID, 'esMX', '¿Alguna vez te has encontrado vagando por una cueva, a altas horas de la noche, en busca de aventuras? ¿Lo haces? ¿En serio? Bueno, entonces has visto los ojos espeluznantes de los murciélagos mirándote desde lo alto, esperando que bajes la guardia para que puedan chuparte la sangre.$B$BPensamiento aterrador, ¿no crees? ¡Por supuesto! ¡No hay duda de que los ojos de murciélago dan miedo!$B$B¿Me traerás unos ojos de murciélago malvados, $n? Los quiero para... algo que estoy diseñando. Algo aterrador.$B$BPuedes conseguirlos de los murciélagos de las Tierras de la Peste del Este.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial! ¡Tienes los ojos! Espero que cazar esos murciélagos te haya asustado, porque si asustó a $gun:una; $n valiente como tú, entonces esos ojos ciertamente asustarán a nuestros visitantes de la Feria.$B$BToma estos boletos, $n, y gracias por tu servicio.', 0),
(@ID, 'esMX', '¡Genial! ¡Tienes los ojos! Espero que cazar esos murciélagos te haya asustado, porque si asustó a $gun:una; $n valiente como tú, entonces esos ojos ciertamente asustarán a nuestros visitantes de la Feria.$B$BToma estos boletos, $n, y gracias por tu servicio.', 0);
-- Marca de Honor
-- 7922, 7923, 7924, 7925, 8293
-- https://es.classic.wowhead.com/quest=7922
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7922, 7923, 7924, 7925, 8293) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7922, 'esES', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(7923, 'esES', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(7924, 'esES', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(7925, 'esES', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(8293, 'esES', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(7922, 'esMX', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(7923, 'esMX', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(7924, 'esMX', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(7925, 'esMX', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0),
(8293, 'esMX', '¡Los elfos de la noche y sus aliados deben temblar incluso ante el susurro de tu nombre! ¡Por la horda!', 0);
-- 7926 La Feria de la Luna Negra
-- https://es.classic.wowhead.com/quest=7926
SET @ID := 7926;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Querías algo? ¿Tienes un vale?', 0),
(@ID, 'esMX', '¿Querías algo? ¿Tienes un vale?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te doy la bienvenida a la Feria de la Luna Negra! ¡Este vale te da derecho a CINCO, has oído bien, CINCO boletos de tómbola y una copia gratuita de la mundialmente conocida guía de campo de la Luna Negra!$B$BCuando tengas suficientes boletos, ven a verme para cambiarlos por premios. ¡Esta práctica guía de campo te ayudará a localizar e identificar los objetos de valor de los coleccionistas que hay en la feria!', 0),
(@ID, 'esMX', '¡Te doy la bienvenida a la Feria de la Luna Negra! ¡Este vale te da derecho a CINCO, has oído bien, CINCO boletos de tómbola y una copia gratuita de la mundialmente conocida guía de campo de la Luna Negra!$B$BCuando tengas suficientes boletos, ven a verme para cambiarlos por premios. ¡Esta práctica guía de campo te ayudará a localizar e identificar los objetos de valor de los coleccionistas que hay en la feria!', 0);
-- 7927 La baraja de Portales de la Luna Negra
-- https://es.classic.wowhead.com/quest=7927
SET @ID := 7927;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veo que has logrado completar una baraja de portales! ¡Felicidades!', 0),
(@ID, 'esMX', '¡Veo que has logrado completar una baraja de portales! ¡Felicidades!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que has creado una baraja de portales. Tu gesto de devolvérnoslo creará un vínculo entre tu y la Luna Negra que no se olvidará. Permítame presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Así que has creado una baraja de portales. Tu gesto de devolvérnoslo creará un vínculo entre tu y la Luna Negra que no se olvidará. Permítame presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0);
-- 7928 La baraja de Señores de la Guerra de la Luna Negra
-- https://es.classic.wowhead.com/quest=7928
SET @ID := 7928;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Veo que has logrado completar una baraja de señores de la guerra! ¡Felicidades!', 0),
(@ID, 'esMX', '¡Veo que has logrado completar una baraja de señores de la guerra! ¡Felicidades!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que has armado un mazo de Señores de la Guerra. Tu gesto de devolvérnoslo creará un vínculo entre tu y la Luna Negra que no se olvidará. Permíteme presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0),
(@ID, 'esMX', 'Así que has armado un mazo de Señores de la Guerra. Tu gesto de devolvérnoslo creará un vínculo entre tu y la Luna Negra que no se olvidará. Permíteme presentarte una de las mejores cartas de la Luna Negra como una pequeña muestra de nuestro agradecimiento.', 0);
-- 5 vales: flor de la Luna Negra
-- 7930, 7931, 7932, 7933, 7934, 7935, 7936, 7940, 7981
-- https://es.classic.wowhead.com/quest=7930
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7930, 7931, 7932, 7933, 7934, 7935, 7936, 7940, 7981) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7930, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7931, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7932, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7933, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7934, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7935, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7936, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7940, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7981, 'esES', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7930, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7931, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7932, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7933, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7934, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7935, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7936, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7981, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0),
(7940, 'esMX', '¡Un pasito "pa\'lante", adelante! Si tienes vales de la Feria de la Luna Negra que te gustaría canjear, ¡dilo! Puede canjear varios grupos de vales por premios maravillosos y fantásticos. ¡No seas $gtímido:tímida;, pruébalo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7930, 7931, 7932, 7933, 7934, 7935, 7936, 7940, 7981) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7930, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7931, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7932, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7933, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7934, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7935, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7936, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7940, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7981, 'esES', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7930, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7931, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7932, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7933, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7934, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7935, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7936, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7940, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0),
(7981, 'esMX', '¡Aquí tienes, aquí tienes! ¡Un premio digno de $gun rey:una reina;! ¡Felicidades, amigo mío!$B$BSi tiene más boletos que te gustaría entregar, ¡házmelo saber! Mientras esté aquí la Feria de la Luna Negra, canjearé tus boletos.', 0);
-- 7937 La Fortuna te espera...
-- https://es.classic.wowhead.com/quest=7937
SET @ID := 7937;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este pajar se parece al de tu visión.', 0),
(@ID, 'esMX', 'Este pajar se parece al de tu visión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una búsqueda rápida en el pajar revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0),
(@ID, 'esMX', '¡Una búsqueda rápida en el pajar revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0);
-- La Fortuna te espera...
-- 7938, 7944
-- https://es.classic.wowhead.com/quest=7938
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7938, 7944) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7938, 'esES', 'Este cofre se parece al de tu visión...', 0),
(7944, 'esES', 'Este cofre se parece al de tu visión...', 0),
(7938, 'esMX', 'Este cofre se parece al de tu visión...', 0),
(7944, 'esMX', 'Este cofre se parece al de tu visión...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7938, 7944) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7938, 'esES', '¡Una búsqueda rápida del cofre revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0),
(7944, 'esES', '¡Una búsqueda rápida del cofre revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0),
(7938, 'esMX', '¡Una búsqueda rápida del cofre revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0),
(7944, 'esMX', '¡Una búsqueda rápida del cofre revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0);
-- 7945 La Fortuna te espera...
-- https://es.classic.wowhead.com/quest=7945
SET @ID := 7945;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este tocón de árbol se parece al de tu visión.', 0),
(@ID, 'esMX', 'Este tocón de árbol se parece al de tu visión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Una búsqueda rápida del tocón del árbol revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0),
(@ID, 'esMX', '¡Una búsqueda rápida del tocón del árbol revela una caja de seguridad dentro de él! ¡Parece que has encontrado tu fortuna!', 0);
-- 7939 Más piedras de pulir densas
-- https://es.classic.wowhead.com/quest=7939
SET @ID := 7939;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, gracias por toda la ayuda que me has brindado. ¡Realmente no puedo agradecerte lo suficiente!$B$BAunque mi necesidad ya no es grande... si me traes piedras de moler más densas, todavía tengo más vales para la Feria de la Luna Negra.', 0),
(@ID, 'esMX', '$n, gracias por toda la ayuda que me has brindado. ¡Realmente no puedo agradecerte lo suficiente!$B$BAunque mi necesidad ya no es grande... si me traes piedras de moler más densas, todavía tengo más vales para la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchas gracias, $n. ¡Aquí tienes tus vales para la Feria de la Luna Negra!', 0),
(@ID, 'esMX', 'Muchas gracias, $n. ¡Aquí tienes tus vales para la Feria de la Luna Negra!', 0);
-- 7941 Más refuerzos para armadura
-- https://es.classic.wowhead.com/quest=7941
SET @ID := 7941;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, debo agradecerte toda tu ayuda. Tengo muchos suministros, gracias a un gran esfuerzo de tu parte, pero si deseas traerme más kits de armadura, con mucho gusto los cambiaré por vales para la Feria de la Luna Negra.', 0),
(@ID, 'esMX', '$n, debo agradecerte toda tu ayuda. Tengo muchos suministros, gracias a un gran esfuerzo de tu parte, pero si deseas traerme más kits de armadura, con mucho gusto los cambiaré por vales para la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahí lo tienes, $n. Un comercio justo. A disfrutar.', 0),
(@ID, 'esMX', 'Ahí lo tienes, $n. Un comercio justo. A disfrutar.', 0);
-- 7942 Más trastos de torio
-- https://es.classic.wowhead.com/quest=7942
SET @ID := 7942;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, has sido tan $gbueno:buena; con nosotros, trayendo bienes sin cansarte. ¡Tienes mi eterno agradecimiento!$B$BAunque nuestra necesidad de Trastos de torio no es tan grande como antes, aún puedes traerlos y con mucho gusto los cambiaré por vales para la Feria de la Luna Negra.', 0),
(@ID, 'esMX', '$n, has sido tan $gbueno:buena; con nosotros, trayendo bienes sin cansarte. ¡Tienes mi eterno agradecimiento!$B$BAunque nuestra necesidad de Trastos de torio no es tan grande como antes, aún puedes traerlos y con mucho gusto los cambiaré por vales para la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí tienes, $n. Aquí tienes vales para la Feria de la Luna Negra para que disfrutes. ¡No, como dicen, los gastes todos en un solo lugar!', 0),
(@ID, 'esMX', 'Aquí tienes, $n. Aquí tienes vales para la Feria de la Luna Negra para que disfrutes. ¡No, como dicen, los gastes todos en un solo lugar!', 0);
-- 7943 Más ojos de murciélago vil
-- https://es.classic.wowhead.com/quest=7943
SET @ID := 7943;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡la atracción que estoy diseñando será el evento más aterrador desde que Gnomeregan fue invadido! Y es en gran parte gracias a ti y a todas las chucherías que me has traído. ¡Muchas muchas gracias!$B$BNo necesito mucho más, pero... si me traes más ojos de murciélago malvados de los murciélagos de las Tierras de la Peste del Este... quizás tenga más vales para la Feria de la Luna Negra.', 0),
(@ID, 'esMX', '$n, ¡la atracción que estoy diseñando será el evento más aterrador desde que Gnomeregan fue invadido! Y es en gran parte gracias a ti y a todas las chucherías que me has traído. ¡Muchas muchas gracias!$B$BNo necesito mucho más, pero... si me traes más ojos de murciélago malvados de los murciélagos de las Tierras de la Peste del Este... quizás tenga más vales para la Feria de la Luna Negra.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias de nuevo, $n. ¡Aquí tienes tus vales!', 0),
(@ID, 'esMX', 'Gracias de nuevo, $n. ¡Aquí tienes tus vales!', 0);
-- 7946 Huevo de Jubjub
-- https://es.classic.wowhead.com/quest=7946
SET @ID := 7946;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy tan feliz de que Jubjub ya no esté perdido. Le gusta tanto la cerveza Hierro Negro que cuando me quedé sin ella... ¡se escapó para buscar más!$B$BAhora que Jubjub ha vuelto, ¡quiero tanta cerveza como puedas! ¡No quiero que vuelva a huir!$B$B¿Tienes alguna cerveza Tradicional Hierro Negro? Si la tienes, te cambiaré uno de los huevos de rana de Jubjub por una jarra...', 0),
(@ID, 'esMX', 'Estoy tan feliz de que Jubjub ya no esté perdido. Le gusta tanto la cerveza Hierro Negro que cuando me quedé sin ella... ¡se escapó para buscar más!$B$BAhora que Jubjub ha vuelto, ¡quiero tanta cerveza como puedas! ¡No quiero que vuelva a huir!$B$B¿Tienes alguna cerveza Tradicional Hierro Negro? Si la tienes, te cambiaré uno de los huevos de rana de Jubjub por una jarra...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. ¡Aquí tienes tu huevo! No estará listo para eclosionar por un tiempo, ¡pero cuando lo haga, tendrás una gran mascota!', 0),
(@ID, 'esMX', 'Gracias, $n. ¡Aquí tienes tu huevo! No estará listo para eclosionar por un tiempo, ¡pero cuando lo haga, tendrás una gran mascota!', 0);
