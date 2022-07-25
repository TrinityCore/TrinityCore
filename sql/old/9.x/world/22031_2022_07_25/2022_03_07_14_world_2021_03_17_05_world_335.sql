-- 8041 La fuerza del Monte Mugamba
-- https://es.classic.wowhead.com/quest=8041
SET @ID := 8041;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $c. Soy Jin\'rokh el Rompedor, trol de Mugamba. Nosotros, la tribu Zandalar, agradecemos todos tus esfuerzos. Saludamos tu tenacidad y fuerza de voluntad.$B$BLleva al cuello este talismán, $c. Deja que la fuerza del Monte Mugamba fluya por todo tu ser. ¡Que tu poder crezca cuando ataques a tus enemigos!', 0),
(@ID, 'esMX', 'Saludos, $c. Soy Jin\'rokh el Rompedor, trol de Mugamba. Nosotros, la tribu Zandalar, agradecemos todos tus esfuerzos. Saludamos tu tenacidad y fuerza de voluntad.$B$BLleva al cuello este talismán, $c. Deja que la fuerza del Monte Mugamba fluya por todo tu ser. ¡Que tu poder crezca cuando ataques a tus enemigos!', 0);
-- 8042 La fuerza del Monte Mugamba
-- https://es.classic.wowhead.com/quest=8042
SET @ID := 8042;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que tu salud es buena, $n. Las gloriosas batallas que has emprendido afectan a toda forma de vida de este planeta. Hakkar nunca debe abandonar los confines de Zul\'Gurub o el mundo correría el peligro de hundirse ante su inmensa hambre.$B$BDame tu talismán y amplificaré su fuerza. ¡Utiliza la Fuerza de Mugamba para castigar a tus enemigos!', 0),
(@ID, 'esMX', 'Me alegra ver que tu salud es buena, $n. Las gloriosas batallas que has emprendido afectan a toda forma de vida de este planeta. Hakkar nunca debe abandonar los confines de Zul\'Gurub o el mundo correría el peligro de hundirse ante su inmensa hambre.$B$BDame tu talismán y amplificaré su fuerza. ¡Utiliza la Fuerza de Mugamba para castigar a tus enemigos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestros caminos se encuentran de nuevo, $c.', 0),
(@ID, 'esMX', 'Nuestros caminos se encuentran de nuevo, $c.', 0);
-- 8043 La fuerza del Monte Mugamba
-- https://es.classic.wowhead.com/quest=8043
SET @ID := 8043;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Maestro/Maestra> $n, ¡has vuelto! Molthor ha enviado noticias de tus acciones al rey. Tu nombre es conocido incluso en los mares del sur. Quizás algún día seas $gun:una; $c $glegendario:legendaria;, una historia para todas las edades.$B$BDame tu talismán para que pueda amplificar una vez más su poder.', 0),
(@ID, 'esMX', '<Maestro/Maestra> $n, ¡has vuelto! Molthor ha enviado noticias de tus acciones al rey. Tu nombre es conocido incluso en los mares del sur. Quizás algún día seas $gun:una; $c $glegendario:legendaria;, una historia para todas las edades.$B$BDame tu talismán para que pueda amplificar una vez más su poder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Usa tu nueva fuerza para destruir a Gurubashi!', 0),
(@ID, 'esMX', '¡Usa tu nueva fuerza para destruir a Gurubashi!', 0);
-- 8044 La Ira de Mugamba
-- https://es.classic.wowhead.com/quest=8044
SET @ID := 8044;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El rey Rastakhan te envía saludos, $gMaestro:Maestra; $n. Nunca se le ha dado tal honor a alguien fuera de la tribu Zandalar.$B$B<Jin\'rokh se inclina.>$B$BDame tu talismán para que pueda mejorarlo una vez más. Debes saber que la rabia de Mugamba ahora está intrínsecamente conectada a tu alma.', 0),
(@ID, 'esMX', 'El rey Rastakhan te envía saludos, $gMaestro:Maestra; $n. Nunca se le ha dado tal honor a alguien fuera de la tribu Zandalar.$B$B<Jin\'rokh se inclina.>$B$BDame tu talismán para que pueda mejorarlo una vez más. Debes saber que la rabia de Mugamba ahora está intrínsecamente conectada a tu alma.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Zul\'jin sentiría envidia, $c. ¡Ve y conquista!', 0),
(@ID, 'esMX', 'Zul\'jin sentiría envidia, $c. ¡Ve y conquista!', 0);
-- 8045 La Enseña del pagano
-- https://es.classic.wowhead.com/quest=8045
SET @ID := 8045;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sepan esto, paganos: una catástrofe nos ha unido. Tus costumbres paganas no son comprendidas ni apreciadas por Zandalar, pero somos gente justa. Usa esta marca alrededor de tu cuello. Servirá tanto de advertencia para nuestros enemigos como de símbolo de tu amistad con Zandalar.$B$BSigue sirviendo a nuestra gente y amplificaré el poder de la marca.', 0),
(@ID, 'esMX', 'Sepan esto, paganos: una catástrofe nos ha unido. Tus costumbres paganas no son comprendidas ni apreciadas por Zandalar, pero somos gente justa. Usa esta marca alrededor de tu cuello. Servirá tanto de advertencia para nuestros enemigos como de símbolo de tu amistad con Zandalar.$B$BSigue sirviendo a nuestra gente y amplificaré el poder de la marca.', 0);
-- 8046 La Enseña del pagano
-- https://es.classic.wowhead.com/quest=8046
SET @ID := 8046;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puede que haya sido demasiado apresurado en mi juicio, $c. Parece como tu fe ciega en esta Luz tiene algún valor después de todo.$B$BDame tu marca y ampliaré su poder.', 0),
(@ID, 'esMX', 'Puede que haya sido demasiado apresurado en mi juicio, $c. Parece como tu fe ciega en esta Luz tiene algún valor después de todo.$B$BDame tu marca y ampliaré su poder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haz lo que tengas que hacer para derrotar a nuestros enemigos, $c. Incluso si eso significa canalizar la Luz.$B$B<Jin\'rokh se estremece.>', 0),
(@ID, 'esMX', 'Haz lo que tengas que hacer para derrotar a nuestros enemigos, $c. Incluso si eso significa canalizar la Luz.$B$B<Jin\'rokh se estremece.>', 0);
-- 8047 La Enseña del pagano
-- https://es.classic.wowhead.com/quest=8047
SET @ID := 8047;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debo confesar que no pensé que tuvieras la resolución de llevar a cabo esta causa, $c. Zandalar ahora te considera un aliado invaluable. Bien hecho.$B$BDame tu marca y una vez más amplificaré su poder.', 0),
(@ID, 'esMX', 'Debo confesar que no pensé que tuvieras la resolución de llevar a cabo esta causa, $c. Zandalar ahora te considera un aliado invaluable. Bien hecho.$B$BDame tu marca y una vez más amplificaré su poder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nuestras creencias difieren pero nuestra causa es justa. Derrota a nuestros enemigos, noble $c.', 0),
(@ID, 'esMX', 'Nuestras creencias difieren pero nuestra causa es justa. Derrota a nuestros enemigos, noble $c.', 0);
-- 8048 La Enseña del héroe
-- https://es.classic.wowhead.com/quest=8048
SET @ID := 8048;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Rey ha reconocido tu existencia, $c. Eres $gel primero:la primera; de tu especie en ser $gaceptado:aceptada; por Rastakhan como $gun verdadero aliado:una verdadera aliada; de Zandalar.$B$BSerás $grecompensado:recompensada; enormemente por tus esfuerzos. Presenta tu marca y le aplicaré la amplificación final.', 0),
(@ID, 'esMX', 'El Rey ha reconocido tu existencia, $c. Eres $gel primero:la primera; de tu especie en ser $gaceptado:aceptada; por Rastakhan como $gun verdadero aliado:una verdadera aliada; de Zandalar.$B$BSerás $grecompensado:recompensada; enormemente por tus esfuerzos. Presenta tu marca y le aplicaré la amplificación final.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vigilancia, honor, lealtad, valentía... Tú encarnas todos estos rasgos y también lo hará tu marca.', 0),
(@ID, 'esMX', 'Vigilancia, honor, lealtad, valentía... Tú encarnas todos estos rasgos y también lo hará tu marca.', 0);
-- 8049 El ojo de Zuldazar
-- https://es.classic.wowhead.com/quest=8049
SET @ID := 8049;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acepta este talismán como muestra de nuestro aprecio, $c.$B$BEl Ojo de Zuldazar crecerá en poder a medida que se fortalezca tu vínculo con los trols de Zandalar. Regresa a mí periódicamente y te impregnaré de la joya.', 0),
(@ID, 'esMX', 'Acepta este talismán como muestra de nuestro aprecio, $c.$B$BEl Ojo de Zuldazar crecerá en poder a medida que se fortalezca tu vínculo con los trols de Zandalar. Regresa a mí periódicamente y te impregnaré de la joya.', 0);
-- 8050 El ojo de Zuldazar
-- https://es.classic.wowhead.com/quest=8050
SET @ID := 8050;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Las historias de tus batallas contra los Gurubashi se susurran en los vientos, $gsacerdote:sacerdotisa;. Incluso la realeza está empezando a hablar de tus hazañas. Se rumorea que el rey Rastakhan incluso te mencionó por tu nombre.$B$BHa llegado el momento de imbuir el Ojo. Pásame el talismán y lo imbuiré.', 0),
(@ID, 'esMX', 'Las historias de tus batallas contra los Gurubashi se susurran en los vientos, $gsacerdote:sacerdotisa;. Incluso la realeza está empezando a hablar de tus hazañas. Se rumorea que el rey Rastakhan incluso te mencionó por tu nombre.$B$BHa llegado el momento de imbuir el Ojo. Pásame el talismán y lo imbuiré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue con tus esfuerzos, $n. El Cazador de Almas intentará devorar tu deseo de vivir.', 0),
(@ID, 'esMX', 'Sigue con tus esfuerzos, $n. El Cazador de Almas intentará devorar tu deseo de vivir.', 0);
-- 8051 El ojo de Zuldazar
-- https://es.classic.wowhead.com/quest=8051
SET @ID := 8051;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido $c. El ojo de Zuldazar palpita enérgicamente. Estás preparado para dar el siguiente paso. Entrégame el talismán y lo imbuiré.', 0),
(@ID, 'esMX', 'Bienvenido $c. El ojo de Zuldazar palpita enérgicamente. Estás preparado para dar el siguiente paso. Entrégame el talismán y lo imbuiré.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue adelante con tu batalla contra el Cazador de Almas y sus esbirros, $n. Nunca hay que permitir que abandone los confines de Zul\'Gurub.', 0),
(@ID, 'esMX', 'Sigue adelante con tu batalla contra el Cazador de Almas y sus esbirros, $n. Nunca hay que permitir que abandone los confines de Zul\'Gurub.', 0);
-- 8052 El Ojo que todo lo ve de Zuldazar
-- https://es.classic.wowhead.com/quest=8052
SET @ID := 8052;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si tan solo tuviéramos diez mil más como tú, $n. Los ejércitos de Hakkar se dispersarían por el viento en un abrir y cerrar de ojos.$B$B<Al\'tabim suspira.>$B$BPor desgracia, el Ojo está listo para realizar todo su potencial. Dámelo.', 0),
(@ID, 'esMX', 'Si tan solo tuviéramos diez mil más como tú, $n. Los ejércitos de Hakkar se dispersarían por el viento en un abrir y cerrar de ojos.$B$B<Al\'tabim suspira.>$B$BPor desgracia, el Ojo está listo para realizar todo su potencial. Dámelo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Golpea a todos y deja que Hakkar los resuelva...', 0),
(@ID, 'esMX', 'Golpea a todos y deja que Hakkar los resuelva...', 0);
-- 8053 Dechados de Poder: los Guardabrazos de librepensador
-- https://es.classic.wowhead.com/quest=8053
SET @ID := 8053;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has regresado? ¿Tienes los Dechados de Poder? ¿Estas perdiendo mi tiempo?$B$BEspero que no, $gpagano:pagana;.', 0),
(@ID, 'esMX', '¿Has regresado? ¿Tienes los Dechados de Poder? ¿Estas perdiendo mi tiempo?$B$BEspero que no, $gpagano:pagana;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Haces mucho por honrarnos. Tus manos gotean con la sangre de los secuaces de Hakkar. Eres $gun amigo:una amiga; de la tribu.$B$BUsa estos Guardabrazos. Son los guardabrazos del librepensador. A esto es a lo que me refiero con el poder real.', 0),
(@ID, 'esMX', 'Haces mucho por honrarnos. Tus manos gotean con la sangre de los secuaces de Hakkar. Eres $gun amigo:una amiga; de la tribu.$B$BUsa estos Guardabrazos. Son los guardabrazos del librepensador. A esto es a lo que me refiero con el poder real.', 0);
-- 8054 Dechados de Poder: el Cinturón de librepensador
-- https://es.classic.wowhead.com/quest=8054
SET @ID := 8054;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tu presencia significa victoria? ¿Tienes los Dechados? ¿Estás goteando con los restos de tus enemigos?', 0),
(@ID, 'esMX', '¿Tu presencia significa victoria? ¿Tienes los Dechados? ¿Estás goteando con los restos de tus enemigos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu honor está asegurado en la tribu. Reclamas muchas muertes en Zul\'Gurub. Los enemigos caen ante tus convicciones. Los enemigos caen ante tu poder.$B$BEste es el cinturón del librepensador. Es un símbolo de honor. Es un mojo poderoso. Ahora es tuyo.', 0),
(@ID, 'esMX', 'Tu honor está asegurado en la tribu. Reclamas muchas muertes en Zul\'Gurub. Los enemigos caen ante tus convicciones. Los enemigos caen ante tu poder.$B$BEste es el cinturón del librepensador. Es un símbolo de honor. Es un mojo poderoso. Ahora es tuyo.', 0);
-- 8055 Dechados de Poder: la coraza de librepensador
-- https://es.classic.wowhead.com/quest=8055
SET @ID := 8055;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los Dechados? Hay mojo en ellos. Debemos tenerlos. Tú nos ayudarás.', 0),
(@ID, 'esMX', '¿Tienes los Dechados? Hay mojo en ellos. Debemos tenerlos. Tú nos ayudarás.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho lo que pocos pudieron. Has puesto de rodillas a los esbirros de Hakkar. Les has mostrado lo que puede hacer un librepensador. Nos has mostrado cómo se puede venerar a un hereje en la tribu. Tienes más que poder real. ERES el poder real.$B$BToma la coraza, librepensador. Aplasta a los que se te oponen.', 0),
(@ID, 'esMX', 'Has hecho lo que pocos pudieron. Has puesto de rodillas a los esbirros de Hakkar. Les has mostrado lo que puede hacer un librepensador. Nos has mostrado cómo se puede venerar a un hereje en la tribu. Tienes más que poder real. ERES el poder real.$B$BToma la coraza, librepensador. Aplasta a los que se te oponen.', 0);
-- 8056 Dechados de Poder: los Brazales de augur
-- https://es.classic.wowhead.com/quest=8056
SET @ID := 8056;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conseguiste los Dechados de Poder de Zul\'Gurub que necesito? ¡Estos brazales valen cualquier esfuerzo que tengas que hacer!', 0),
(@ID, 'esMX', '¿Conseguiste los Dechados de Poder de Zul\'Gurub que necesito? ¡Estos brazales valen cualquier esfuerzo que tengas que hacer!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que tienes un poco del augur Zandalar en ti. Sabemos de las hazañas que has estado haciendo en Zul\'Gurub en nuestro nombre, colega. Estos Dechados de Poder recorrerán un largo camino para ayudar a la tribu Zandalar, una tribu, debo agregar, a la que puedes llamar como amigos. Toma estos brazales, $n; ¡Te los has ganado y algo más!', 0),
(@ID, 'esMX', 'Parece que tienes un poco del augur Zandalar en ti. Sabemos de las hazañas que has estado haciendo en Zul\'Gurub en nuestro nombre, colega. Estos Dechados de Poder recorrerán un largo camino para ayudar a la tribu Zandalar, una tribu, debo agregar, a la que puedes llamar como amigos. Toma estos brazales, $n; ¡Te los has ganado y algo más!', 0);
-- 8057 Dechados de Poder: los brazales de haruspex
-- https://es.classic.wowhead.com/quest=8057
SET @ID := 8057;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los Dechados de Poder de Zul\'Gurub? Estos brazales merecen el esfuerzo, $n. ¡Confía en mí, colega!', 0),
(@ID, 'esMX', '¿Tienes los Dechados de Poder de Zul\'Gurub? Estos brazales merecen el esfuerzo, $n. ¡Confía en mí, colega!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, puedo sentir el poder que viene de estos Dechados del Poder, $n. Demuestras ser alguien a quien en la tribu podemos llamar "$gamigo:amiga;". Un trato es un trato, $n... ¡contempla el poder de los brazales del arúspice!', 0),
(@ID, 'esMX', 'Ah, puedo sentir el poder que viene de estos Dechados del Poder, $n. Demuestras ser alguien a quien en la tribu podemos llamar "$gamigo:amiga;". Un trato es un trato, $n... ¡contempla el poder de los brazales del arúspice!', 0);
-- 8058 Dechados de Poder: los Guardabrazos de vindicador
-- https://es.classic.wowhead.com/quest=8058
SET @ID := 8058;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído los Dechados de Poder? ¿Se ha clamado venganza en nombre de los Zandalar?', 0),
(@ID, 'esMX', '¿Has traído los Dechados de Poder? ¿Se ha clamado venganza en nombre de los Zandalar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has sembrado mucha venganza en este día. Has tomado el rostro del vindicador. Has doblegado a los esbirros del Dios de la Sangre.$B$BToma esto. Alimentará tu venganza en el futuro. Ahora eres $gamigo:amiga; de los Zandalar.', 0),
(@ID, 'esMX', 'Has sembrado mucha venganza en este día. Has tomado el rostro del vindicador. Has doblegado a los esbirros del Dios de la Sangre.$B$BToma esto. Alimentará tu venganza en el futuro. Ahora eres $gamigo:amiga; de los Zandalar.', 0);
-- 8059 Dechados de Poder: los Brazaletes de endemoniado
-- https://es.classic.wowhead.com/quest=8059
SET @ID := 8059;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto con los Dechados de Poder? Al derrotar a los diabólicos secuaces de Hakkar, no solo demostrarás tu valía ante nosotros, sino también tu voluntad de aprender los caminos de los endemoniados.', 0),
(@ID, 'esMX', '¿Has vuelto con los Dechados de Poder? Al derrotar a los diabólicos secuaces de Hakkar, no solo demostrarás tu valía ante nosotros, sino también tu voluntad de aprender los caminos de los endemoniados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho... sin duda se les obligó a pagar de forma insoportable antes de que renunciaran a los Dechados de Poder. Toma esto: las envolturas del endemoniado. Hecho de un poderoso mojo utilizado para convocar a la presa del demoníaco, es una herramienta poderosa en la adquisición de poder.', 0),
(@ID, 'esMX', 'Bien hecho... sin duda se les obligó a pagar de forma insoportable antes de que renunciaran a los Dechados de Poder. Toma esto: las envolturas del endemoniado. Hecho de un poderoso mojo utilizado para convocar a la presa del demoníaco, es una herramienta poderosa en la adquisición de poder.', 0);
-- 8060 Dechados de Poder: los Brazaletes de ilusionista
-- https://es.classic.wowhead.com/quest=8060
SET @ID := 8060;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n - ¿ya regresaste? ¿Pudiste conseguir los Dechados de Poder que necesito?', 0),
(@ID, 'esMX', '$n - ¿ya regresaste? ¿Pudiste conseguir los Dechados de Poder que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante... ¿podrías sentir el mojo fluyendo a través de ellos? Los Dechados de Poder se utilizaron como moneda de cambio cuando el Imperio Gurubashi gobernaba estas tierras. ¡Ahora nosotros, Zandalar, usaremos el mojo latente dentro de ellos para luchar contra el segundo ascenso del Dios de la Sangre Hakkar!$B$BLo has hecho bien hoy; considera que tienes un amigo en los Zandalar. Para eso, ¡aquí están los brazales de ilusionista que prometí!', 0),
(@ID, 'esMX', 'Impresionante... ¿podrías sentir el mojo fluyendo a través de ellos? Los Dechados de Poder se utilizaron como moneda de cambio cuando el Imperio Gurubashi gobernaba estas tierras. ¡Ahora nosotros, Zandalar, usaremos el mojo latente dentro de ellos para luchar contra el segundo ascenso del Dios de la Sangre Hakkar!$B$BLo has hecho bien hoy; considera que tienes un amigo en los Zandalar. Para eso, ¡aquí están los brazales de ilusionista que prometí!', 0);
-- 8061 Dechados de Poder: los Brazaletes de confesor
-- https://es.classic.wowhead.com/quest=8061
SET @ID := 8061;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'De vuelta de Zul\'Gurub, ¿verdad? ¿Has conseguido recuperar los Dechados de Poder de los esbirros de Hakkar?', 0),
(@ID, 'esMX', 'De vuelta de Zul\'Gurub, ¿verdad? ¿Has conseguido recuperar los Dechados de Poder de los esbirros de Hakkar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excepcional, $n! No fue una hazaña pequeña traerme estos. Sin duda has actuado hoy como confesor de nuestra tribu para protegernos de la amenaza de Hakkar. ¡Estos brazales son apropiados para $gun amigo:una amiga; de la tribu como tú!', 0),
(@ID, 'esMX', '¡Excepcional, $n! No fue una hazaña pequeña traerme estos. Sin duda has actuado hoy como confesor de nuestra tribu para protegernos de la amenaza de Hakkar. ¡Estos brazales son apropiados para $gun amigo:una amiga; de la tribu como tú!', 0);
-- 8062 Dechados de Poder: los Brazales de depredador
-- https://es.classic.wowhead.com/quest=8062
SET @ID := 8062;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Caza a aquellos en Zul\'Gurub que posean los Dechados de poder, $n. Son tu presa; poseen lo que ambos debemos tener.', 0),
(@ID, 'esMX', 'Caza a aquellos en Zul\'Gurub que posean los Dechados de poder, $n. Son tu presa; poseen lo que ambos debemos tener.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... no necesito una visión para sentir la presencia de los Dechado de Poder. Su éxito en Zul\'Gurub ha impresionado a muchos miembros de la tribu. No solo te consideramos $gun amigo:una amiga; de los Zandalar, sino que también te consideramos lo suficientemente $gdigno:digna; para poseer los brazales del depredador: elementos poderosos y un símbolo de lo que significa ser un depredador. Bien hecho, $n.', 0),
(@ID, 'esMX', 'Sí... no necesito una visión para sentir la presencia de los Dechado de Poder. Su éxito en Zul\'Gurub ha impresionado a muchos miembros de la tribu. No solo te consideramos $gun amigo:una amiga; de los Zandalar, sino que también te consideramos lo suficientemente $gdigno:digna; para poseer los brazales del depredador: elementos poderosos y un símbolo de lo que significa ser un depredador. Bien hecho, $n.', 0);
-- 8063 Dechados de Poder: los Brazales de sinconcierto
-- https://es.classic.wowhead.com/quest=8063
SET @ID := 8063;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Busca la locura dentro de Zul\'Gurub y ensombrécela con la tuya, $n! ¡Hacerlo significa éxito y éxito significa recompensa! ¡No dejes que el Dios de la Sangre vuelva a reinar supremo!', 0),
(@ID, 'esMX', '¡Busca la locura dentro de Zul\'Gurub y ensombrécela con la tuya, $n! ¡Hacerlo significa éxito y éxito significa recompensa! ¡No dejes que el Dios de la Sangre vuelva a reinar supremo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n... tus logros en Zul\'Gurub te han ganado el derecho de llamar amigos a la tribu Zandalar. Me ocuparé de la disposición de los Dechados; por tu esfuerzo por favor acepta esta recompensa!', 0),
(@ID, 'esMX', 'Bien hecho, $n... tus logros en Zul\'Gurub te han ganado el derecho de llamar amigos a la tribu Zandalar. Me ocuparé de la disposición de los Dechados; por tu esfuerzo por favor acepta esta recompensa!', 0);
-- 8064 Dechados de Poder: el Cinturón de haruspex
-- https://es.classic.wowhead.com/quest=8064
SET @ID := 8064;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los Dechados de Poder que necesito? El Cinturón de adivino será tuyo en cuanto los tengas.', 0),
(@ID, 'esMX', '¿Tienes los Dechados de Poder que necesito? El Cinturón de adivino será tuyo en cuanto los tengas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te lo agradezco, el poder latente de estos objetos es todo un tesoro, te lo aseguro. No solo has hecho lo que te pedí, también has demostrado que eres honorable. Como te prometí, ¡aquí tienes tu recompensa!', 0),
(@ID, 'esMX', 'Te lo agradezco, el poder latente de estos objetos es todo un tesoro, te lo aseguro. No solo has hecho lo que te pedí, también has demostrado que eres honorable. Como te prometí, ¡aquí tienes tu recompensa!', 0);
-- 8065 Dechados de Poder: la guerrera de haruspex
-- https://es.classic.wowhead.com/quest=8065
SET @ID := 8065;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los Dechados de Poder de Zul\'Gurub necesarios? La Túnica de adivino merece cualquier esfuerzo.', 0),
(@ID, 'esMX', '¿Tienes los Dechados de Poder de Zul\'Gurub necesarios? La Túnica de adivino merece cualquier esfuerzo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante... has conseguido reunir los Dechados de Poder que necesitábamos, $n. Las hazañas que has hecho por los Zandalar en Zul\'Gurub son legendarias y por eso serás $gvenerado:venerada; por la tribu. ¡Aquí tienes tu túnica poderosa $c!', 0),
(@ID, 'esMX', 'Impresionante... has conseguido reunir los Dechados de Poder que necesitábamos, $n. Las hazañas que has hecho por los Zandalar en Zul\'Gurub son legendarias y por eso serás $gvenerado:venerada; por la tribu. ¡Aquí tienes tu túnica poderosa $c!', 0);
-- 8066 Dechados de Poder: el Cinturón de depredador
-- https://es.classic.wowhead.com/quest=8066
SET @ID := 8066;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ataca a los locos esbirros de Hakkar en Zul\'Gurub; ellos son los que tienen los Dechados de poder, $n. Demuestra tu éxito con ellos, y a la tribu, como aspirante al depredador.', 0),
(@ID, 'esMX', 'Ataca a los locos esbirros de Hakkar en Zul\'Gurub; ellos son los que tienen los Dechados de poder, $n. Demuestra tu éxito con ellos, y a la tribu, como aspirante al depredador.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sentí tu llegada momentos antes, $n, pero no con demasiada facilidad. Lo que se me reveló a mí fueron los Dechados de Poder que trajiste. Puedo sentir el poder sin necesidad de ver los abalorios; su mojo latente, magia pura, por así decirlo, continuará alimentando nuestros esfuerzos por vencer los planes diabólicos del Dios de la Sangre Hakkar.$B$BDebes ser $gfelicitado:felicitada; y $grecompensado:recompensada; por tu éxito. Eres honorable entre la tribu y eres $gdigno:digna; de llevar el cinturón de depredador.', 0),
(@ID, 'esMX', 'Sentí tu llegada momentos antes, $n, pero no con demasiada facilidad. Lo que se me reveló a mí fueron los Dechados de Poder que trajiste. Puedo sentir el poder sin necesidad de ver los abalorios; su mojo latente, magia pura, por así decirlo, continuará alimentando nuestros esfuerzos por vencer los planes diabólicos del Dios de la Sangre Hakkar.$B$BDebes ser $gfelicitado:felicitada; y $grecompensado:recompensada; por tu éxito. Eres honorable entre la tribu y eres $gdigno:digna; de llevar el cinturón de depredador.', 0);
-- 8067 Dechados de Poder: el Manto de depredador
-- https://es.classic.wowhead.com/quest=8067
SET @ID := 8067;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Han tenido éxito tus ataques a Zul\'Gurub, $n? Solo cuando me hayas traído lo que busco y hayas demostrado tu valía ante la tribu, ganarás un manto insuperable entre los Zandalar.', 0),
(@ID, 'esMX', '¿Han tenido éxito tus ataques a Zul\'Gurub, $n? Solo cuando me hayas traído lo que busco y hayas demostrado tu valía ante la tribu, ganarás un manto insuperable entre los Zandalar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Éxito... debes ser $gvenerado:venerada; entre la tribu, $n. No fue una hazaña pequeña adquirir los Dechados de Poder necesarios para el manto, pero lo manejaste a la manera del más letal de nuestros depredadores. Te has ganado tu lugar entre ellos y ciertamente te has ganado el derecho a usar su manto.', 0),
(@ID, 'esMX', 'Éxito... debes ser $gvenerado:venerada; entre la tribu, $n. No fue una hazaña pequeña adquirir los Dechados de Poder necesarios para el manto, pero lo manejaste a la manera del más letal de nuestros depredadores. Te has ganado tu lugar entre ellos y ciertamente te has ganado el derecho a usar su manto.', 0);
-- 8068 Dechados de Poder: el Manto de ilusionista
-- https://es.classic.wowhead.com/quest=8068
SET @ID := 8068;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo fue tu incursión en Zul\'Gurub? ¿Volviste locos a tus enemigos con el poder de la ilusión? Ilusión o no, sus muertes, y los Dechados de Poder que les quitaste, ayudarán a frustrar el ascenso de Hakkar.', 0),
(@ID, 'esMX', '¿Cómo fue tu incursión en Zul\'Gurub? ¿Volviste locos a tus enemigos con el poder de la ilusión? Ilusión o no, sus muertes, y los Dechados de Poder que les quitaste, ayudarán a frustrar el ascenso de Hakkar.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Éxito! ¡Serás $ghonrado:honrada; en la tribu de aquí en adelante! Sin duda, Zul\'Gurub ha probado el poder de los Zandalar hoy, gracias a ti, $n.$B$BCon la bendición de la tribu, toma el manto del ilusionista Zandalar. Que te sirva bien.', 0),
(@ID, 'esMX', '¡Éxito! ¡Serás $ghonrado:honrada; en la tribu de aquí en adelante! Sin duda, Zul\'Gurub ha probado el poder de los Zandalar hoy, gracias a ti, $n.$B$BCon la bendición de la tribu, toma el manto del ilusionista Zandalar. Que te sirva bien.', 0);
-- 8069 Dechados de Poder: la Toga de ilusionista
-- https://es.classic.wowhead.com/quest=8069
SET @ID := 8069;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vuelto con los Dechados de Poder que necesitamos? Sé que no será fácil... pero he predicho durante mucho tiempo que $gun forastero:una forastera; vendría a ayudarnos en nuestra lucha contra Hakkar. ¡Deja que seas tú, digo!', 0),
(@ID, 'esMX', '¿Has vuelto con los Dechados de Poder que necesitamos? Sé que no será fácil... pero he predicho durante mucho tiempo que $gun forastero:una forastera; vendría a ayudarnos en nuestra lucha contra Hakkar. ¡Deja que seas tú, digo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Al fin, alguien $gdigno:digna; de llevar la túnica de ilusionista! Tu éxito en Zul\'Gurub ha asegurado tu reverencia entre la tribu durante siglos. ¡Úselo con orgullo, $n!', 0),
(@ID, 'esMX', '¡Al fin, alguien $gdigno:digna; de llevar la túnica de ilusionista! Tu éxito en Zul\'Gurub ha asegurado tu reverencia entre la tribu durante siglos. ¡Úselo con orgullo, $n!', 0);
-- 8070 Dechados de Poder: las Ataduras de confesor
-- https://es.classic.wowhead.com/quest=8070
SET @ID := 8070;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los Dechados de Poder... ¿los tienes? Solo cuando las tengamos podremos hacer uso del poder latente almacenado en su interior. Será bueno darle la vuelta a los secuaces del Dios de la Sangre...', 0),
(@ID, 'esMX', 'Los Dechados de Poder... ¿los tienes? Solo cuando las tengamos podremos hacer uso del poder latente almacenado en su interior. Será bueno darle la vuelta a los secuaces del Dios de la Sangre...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Éxito! Esto contribuirá en gran medida a fortalecer nuestro poder contra el ascenso de Hakkar. Con tu ayuda, hemos dado un paso importante para asegurarnos de que el Dios de la Sangre no nos destruirá a todos.$B$BHoy te has ganado el honor con la tribu, $n. Toma esto, las ataduras del confesor, como un símbolo de nuestro agradecimiento.', 0),
(@ID, 'esMX', '¡Éxito! Esto contribuirá en gran medida a fortalecer nuestro poder contra el ascenso de Hakkar. Con tu ayuda, hemos dado un paso importante para asegurarnos de que el Dios de la Sangre no nos destruirá a todos.$B$BHoy te has ganado el honor con la tribu, $n. Toma esto, las ataduras del confesor, como un símbolo de nuestro agradecimiento.', 0);
-- 8071 Dechados de Poder: el Manto de confesor
-- https://es.classic.wowhead.com/quest=8071
SET @ID := 8071;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los Dechados de Poder de Zul\'Gurub?', 0),
(@ID, 'esMX', '¿Tienes los Dechados de Poder de Zul\'Gurub?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n... Hoy seguramente los esbirros de Hakkar han sentido la retribución de los Zandalar, y todo gracias a ti. Tus actos te han hecho $gmeritorio:meritoria; de nuestra veneración. Con tu bendición, acepta el manto de confesor como ofrenda.', 0),
(@ID, 'esMX', 'Bien hecho, $n... Hoy seguramente los esbirros de Hakkar han sentido la retribución de los Zandalar, y todo gracias a ti. Tus actos te han hecho $gmeritorio:meritoria; de nuestra veneración. Con tu bendición, acepta el manto de confesor como ofrenda.', 0);
-- 8072 Dechados de Poder: el Manto de sinconcierto
-- https://es.classic.wowhead.com/quest=8072
SET @ID := 8072;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado, ¿tienes los Dechados de Poder que necesito?$B$BLa leyenda de Khar\'vaxal el Agrietado nos sirve hoy como un recordatorio de que ningún enemigo, sin importar cuán grande sea la amenaza que pueda ser, es imposible de vencer. El caos hará que todos se arrodillen, eso es seguro... y quizás los elementos menos caóticos del caos.', 0),
(@ID, 'esMX', 'Has regresado, ¿tienes los Dechados de Poder que necesito?$B$BLa leyenda de Khar\'vaxal el Agrietado nos sirve hoy como un recordatorio de que ningún enemigo, sin importar cuán grande sea la amenaza que pueda ser, es imposible de vencer. El caos hará que todos se arrodillen, eso es seguro... y quizás los elementos menos caóticos del caos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La victoria es nuestra este día, gracias a la locura que has sembrado sobre nuestros enemigos mutuos! ¡Debes ser $ghonrado:honrada; entre los Zandalar, y no hay mejor manera de mostrar gratitud por tus actos que ofreciéndote el manto de sinconcierto!', 0),
(@ID, 'esMX', '¡La victoria es nuestra este día, gracias a la locura que has sembrado sobre nuestros enemigos mutuos! ¡Debes ser $ghonrado:honrada; entre los Zandalar, y no hay mejor manera de mostrar gratitud por tus actos que ofreciéndote el manto de sinconcierto!', 0);
-- 8073 Dechados de Poder: la guerrera de sinconcierto
-- https://es.classic.wowhead.com/quest=8073
SET @ID := 8073;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bienvenido de nuevo a la Isla, $n... ¿Has regresado triunfalmente con los Dechados de Poder a cuestas?', 0),
(@ID, 'esMX', 'Bienvenido de nuevo a la Isla, $n... ¿Has regresado triunfalmente con los Dechados de Poder a cuestas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante... has logrado hoy lo que pocos pensaban que era posible. Tu reverencia en la tribu está asegurada para toda la vida, $n. Te has ganado el derecho a ponerte la túnica de sinconcierto; hazlo con nuestra bendición.', 0),
(@ID, 'esMX', 'Impresionante... has logrado hoy lo que pocos pensaban que era posible. Tu reverencia en la tribu está asegurada para toda la vida, $n. Te has ganado el derecho a ponerte la túnica de sinconcierto; hazlo con nuestra bendición.', 0);
