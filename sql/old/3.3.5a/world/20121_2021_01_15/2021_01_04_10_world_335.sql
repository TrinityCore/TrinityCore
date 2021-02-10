-- 875 Las tenientes arpías
-- https://es.classic.wowhead.com/quest=875
SET @ID := 875;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes ya 6 anillos de tenientes arpías? Deben sentir el peso de la justicia por sus actos viciosos contra la Horda.', 0),
(@ID, 'esMX', '¿Tienes ya 6 anillos de tenientes arpías? Deben sentir el peso de la justicia por sus actos viciosos contra la Horda.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $gamigo:amiga;. Creo que llegarás lejos con la Horda.', 0),
(@ID, 'esMX', 'Excelente trabajo, $gamigo:amiga;. Creo que llegarás lejos con la Horda.', 0);
-- 876 Serena Sangrepluma
-- https://es.classic.wowhead.com/quest=876
SET @ID := 876;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No conseguirás nada hasta que vea la cabeza de Serena.', 0),
(@ID, 'esMX', 'No conseguirás nada hasta que vea la cabeza de Serena.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡TOMA! ¡Muy bien, $n! Un trabajo de primera… No estaba seguro de que estuvieras a la altura de la tarea pero has demostrado que se te da bien degollar. Gracias por ayudarnos a erradicar la epidemia de arpías. Aquí tienes tu recompensa, úsala bien.', 0),
(@ID, 'esMX', '¡TOMA! ¡Muy bien, $n! Un trabajo de primera… No estaba seguro de que estuvieras a la altura de la tarea pero has demostrado que se te da bien degollar. Gracias por ayudarnos a erradicar la epidemia de arpías. Aquí tienes tu recompensa, úsala bien.', 0);
-- 877 El Oasis Estancado
-- https://es.classic.wowhead.com/quest=877
SET @ID := 877;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Prueba las semillas secas', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en El Oasis Estancado? ¿Había una fisura debajo de sus aguas?', 0),
(@ID, 'esMX', '¿Has estado en El Oasis Estancado? ¿Había una fisura debajo de sus aguas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Tu descubrimiento es increíble! Las semillas que te di estaban secas y muertas. Sea lo que sea lo que hay debajo de esos oasis ¡puede crear vida de la nada!$B$BDebemos seguir investigando...', 0),
(@ID, 'esMX', '¡Tu descubrimiento es increíble! Las semillas que te di estaban secas y muertas. Sea lo que sea lo que hay debajo de esos oasis ¡puede crear vida de la nada!$B$BDebemos seguir investigando...', 0);
-- 878 Tribus en guerra
-- https://es.classic.wowhead.com/quest=878
SET @ID := 878;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Más información <gruñe> para la Horda cuando hayas matado a los sabios Erizapúas, $r. ¡Ni un momento antes! Quebrantadientes no es tonto.', 0),
(@ID, 'esMX', 'Más información <gruñe> para la Horda cuando hayas matado a los sabios Erizapúas, $r. ¡Ni un momento antes! Quebrantadientes no es tonto.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí... me llena de alegría <gruñe> los Erizapúas conocen el dolor de mi tribu, $r. Así es cómo debería sentirme pero <gruñe> no es el caso.$B$BAyudas a tu pueblo y te rinden honores. Quebrantadientes ayuda a su pueblo ¿y qué hacen? Le dan la espalda. ¡Lo olvidan y lo abandonan para que se pudra en una jaula!$B$BIncluso los ayudo entre rejas ¡y no mandan a nadie a rescatarme!', 0),
(@ID, 'esMX', 'Sí, sí... me llena de alegría <gruñe> los Erizapúas conocen el dolor de mi tribu, $r. Así es cómo debería sentirme pero <gruñe> no es el caso.$B$BAyudas a tu pueblo y te rinden honores. Quebrantadientes ayuda a su pueblo ¿y qué hacen? Le dan la espalda. ¡Lo olvidan y lo abandonan para que se pudra en una jaula!$B$BIncluso los ayudo entre rejas ¡y no mandan a nadie a rescatarme!', 0);
-- 879 Traidores
-- https://es.classic.wowhead.com/quest=879
SET @ID := 879;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $r?$B$BThork piensa que sabe la verdad sobre quién encabeza las incursiones contra su pueblo pero se dará cuenta de hasta qué punto está equivocado si logras completar la tarea.$B$BMi muerte es ineludible pero le has infligido gran sufrimiento a mis enemigos, así que Quebrantadientes no se arrepiente de nada.', 0),
(@ID, 'esMX', '¿Cómo va la caza, $r?$B$BThork piensa que sabe la verdad sobre quién encabeza las incursiones contra su pueblo pero se dará cuenta de hasta qué punto está equivocado si logras completar la tarea.$B$BMi muerte es ineludible pero le has infligido gran sufrimiento a mis enemigos, así que Quebrantadientes no se arrepiente de nada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya está. Es mejor que acabe así, dice Quebrantadientes. <Gruñe> Tendrían que <gruñe> haberse asegurado de que me había muerto cuando me dieron la espalda en lugar de <gruñe> dejarme en esta jaula para renegados.$B$BTe falta solo una tarea que completar, $r.', 0),
(@ID, 'esMX', 'Ya está. Es mejor que acabe así, dice Quebrantadientes. <Gruñe> Tendrían que <gruñe> haberse asegurado de que me había muerto cuando me dieron la espalda en lugar de <gruñe> dejarme en esta jaula para renegados.$B$BTe falta solo una tarea que completar, $r.', 0);
-- 880 Seres alterados
-- https://es.classic.wowhead.com/quest=880
SET @ID := 880;
UPDATE `quest_template_locale` SET `Objectives` = 'Reúne 8 caparazones de quijafortes alterados de los quijafortes de El Oasis Estancado.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo te va la recolección? ¿Has conseguido los caparazones?', 0),
(@ID, 'esMX', '¿Cómo te va la recolección? ¿Has conseguido los caparazones?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $n. El estudio de las criaturas de una región puede enseñarte mucho de la misma. Veremos qué nos cuentan estos caparazones.$B$BAgradezco infinitamente tu ayuda... y espero aceptes estas monedas que podrían venirte bien. No las necesito.', 0),
(@ID, 'esMX', 'Gracias, $n. El estudio de las criaturas de una región puede enseñarte mucho de la misma. Veremos qué nos cuentan estos caparazones.$B$BAgradezco infinitamente tu ayuda... y espero aceptes estas monedas que podrían venirte bien. No las necesito.', 0);
-- 881 Echeyakee
-- https://es.classic.wowhead.com/quest=881
SET @ID := 881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El gran felino quiere verte, $n.', 0),
(@ID, 'esMX', 'El gran felino quiere verte, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has derrotado a Echeyakee y aunque se acabaron sus días de caza... su espíritu te acompaña. Te enseñará la fuerza de la sutileza y el honor de la misericordia.$B$BAún te queda mucho camino por recorrer, $c. Esperemos que lo recorras sin percances.', 0),
(@ID, 'esMX', 'Has derrotado a Echeyakee y aunque se acabaron sus días de caza... su espíritu te acompaña. Te enseñará la fuerza de la sutileza y el honor de la misericordia.$B$BAún te queda mucho camino por recorrer, $c. Esperemos que lo recorras sin percances.', 0);
-- 882 Ishamuhale
-- https://es.classic.wowhead.com/quest=882
SET @ID := 882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿has derrotado a Ishamuhale!', 0),
(@ID, 'esMX', '$n, ¿has derrotado a Ishamuhale!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este colmillo solo es una prenda pero lo que representa es profundo.$B$BLa fuerza de Ishamuhale está en ti, $n. Úsala con moderación. Esa es tu carga.$B$BEse es tu honor.', 0),
(@ID, 'esMX', 'Este colmillo solo es una prenda pero lo que representa es profundo.$B$BLa fuerza de Ishamuhale está en ti, $n. Úsala con moderación. Esa es tu carga.$B$BEse es tu honor.', 0);
-- 883 Lakota'mani
-- https://es.classic.wowhead.com/quest=883
SET @ID := 883;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, cuando te acercabas noté un renovado poder en tus pasos. Dime, ¿se ha reunido tu espíritu con el gran Lakota\'mani?', 0),
(@ID, 'esMX', '$n, cuando te acercabas noté un renovado poder en tus pasos. Dime, ¿se ha reunido tu espíritu con el gran Lakota\'mani?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Lakota\'mani se llama "Sacuditerra" en nuestro idioma y sus pasos retumban como el trueno. Ahora está contigo y su valor se funde con el tuyo. Juntos no hay conflicto que no podáis acometer.$B$BAnda con la cabeza alta, $n. Anda con la cabeza alta, Sacuditerra.”', 0),
(@ID, 'esMX', '"Lakota\'mani se llama "Sacuditerra" en nuestro idioma y sus pasos retumban como el trueno. Ahora está contigo y su valor se funde con el tuyo. Juntos no hay conflicto que no podáis acometer.$B$BAnda con la cabeza alta, $n. Anda con la cabeza alta, Sacuditerra.”', 0);
-- 884 Owatanka
-- https://es.classic.wowhead.com/quest=884
SET @ID := 884;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡detecto un nuevo poder en tu mirada! ¿A que te has reunido con el poderoso Owatanka?', 0),
(@ID, 'esMX', '$n, ¡detecto un nuevo poder en tu mirada! ¿A que te has reunido con el poderoso Owatanka?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los tauren llaman "Rayo Azul" al truenagarto Owatanka porque en él reside una velocidad que no se espera de su tamaño. Se dice que un rayo lo alcanzó hace mucho tiempo y, alimentada por la furia del cielo, la energía de la bestia no conoce límites.$B$BQue su energía fluya por ti, $n. Puesto que ahora igualas el paso de Owatanka.', 0),
(@ID, 'esMX', 'Los tauren llaman "Rayo Azul" al truenagarto Owatanka porque en él reside una velocidad que no se espera de su tamaño. Se dice que un rayo lo alcanzó hace mucho tiempo y, alimentada por la furia del cielo, la energía de la bestia no conoce límites.$B$BQue su energía fluya por ti, $n. Puesto que ahora igualas el paso de Owatanka.', 0);
-- 885 Washte Pawne
-- https://es.classic.wowhead.com/quest=885
SET @ID := 885;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay en ti una nueva determinación, $n. Una determinación nacida del dolor...$B$B¿Te pesa la muerte de Washte Pawne?', 0),
(@ID, 'esMX', 'Hay en ti una nueva determinación, $n. Una determinación nacida del dolor...$B$B¿Te pesa la muerte de Washte Pawne?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El halcón trueno es una bestia rara en Los Baldíos y su muerte puede conllevar gran fortuna… o una terrible condena.$B$BPero Washte Pawne, llamado "Muerdespíritu" en lengua de los tauren puede no traer nada.... como acarrear ambos.$B$BEl dolor que has sentido al cazar a Muerdespíritu es la punzada que todos sienten al lograr grandes beneficios a un coste elevado. La punzada que sentiste es la punzada del remordimiento.$B$BPero veo que te has impuesto a eso. Has aprendido que el remordimiento se convierte en sabiduría y que nos fortalecemos a través del dolor.$B$BHas aprendido mucho, $n.', 0),
(@ID, 'esMX', 'El halcón trueno es una bestia rara en Los Baldíos y su muerte puede conllevar gran fortuna… o una terrible condena.$B$BPero Washte Pawne, llamado "Muerdespíritu" en lengua de los tauren puede no traer nada.... como acarrear ambos.$B$BEl dolor que has sentido al cazar a Muerdespíritu es la punzada que todos sienten al lograr grandes beneficios a un coste elevado. La punzada que sentiste es la punzada del remordimiento.$B$BPero veo que te has impuesto a eso. Has aprendido que el remordimiento se convierte en sabiduría y que nos fortalecemos a través del dolor.$B$BHas aprendido mucho, $n.', 0);
-- 886 El oasis de Los Baldíos
-- https://es.classic.wowhead.com/quest=886
SET @ID := 886;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de que mis hermanos de Cima del Trueno te hayan enviado a verme, joven $c, pues yo solo no soy capaz de desentrañar el misterio que se esconde en Los Baldíos.$B$BEsperemos que con tu ayuda seamos capaces de encontrar respuestas.', 0),
(@ID, 'esMX', 'Me alegro de que mis hermanos de Cima del Trueno te hayan enviado a verme, joven $c, pues yo solo no soy capaz de desentrañar el misterio que se esconde en Los Baldíos.$B$BEsperemos que con tu ayuda seamos capaces de encontrar respuestas.', 0);
-- 889 El espíritu del viento
-- https://es.classic.wowhead.com/quest=889
SET @ID := 889;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tráele a Quebrantadientes 10 fragmentos ensangrentados y te bendeciré con gran velocidad. Correrás con el astacebra y hasta el viento tendrá celos de ti.$B$BNo durará mucho pero debería ser lo suficiente para ayudarte a viajar por Los Baldíos.', 0),
(@ID, 'esMX', 'Tráele a Quebrantadientes 10 fragmentos ensangrentados y te bendeciré con gran velocidad. Correrás con el astacebra y hasta el viento tendrá celos de ti.$B$BNo durará mucho pero debería ser lo suficiente para ayudarte a viajar por Los Baldíos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien. Que el espíritu de Agamaggan te guíe, $r. Vuelve aquí si deseas dominar aún más magia de Agamaggan.', 0),
(@ID, 'esMX', 'Bien. Que el espíritu de Agamaggan te guíe, $r. Vuelve aquí si deseas dominar aún más magia de Agamaggan.', 0);
-- 891 Las armas del Fuerte del Norte
-- https://es.classic.wowhead.com/quest=891
SET @ID := 891;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi flota está en peligro con la capitán Justamonta y sus malditos cañoneros disparando sin parar desde Fuerte del Norte. También quiero que sus soldados paguen por ello. Lléname la mano con las medallas de sus muertos y sabré que se ha vengado a mis soldados caídos.', 0),
(@ID, 'esMX', 'Mi flota está en peligro con la capitán Justamonta y sus malditos cañoneros disparando sin parar desde Fuerte del Norte. También quiero que sus soldados paguen por ello. Lléname la mano con las medallas de sus muertos y sabré que se ha vengado a mis soldados caídos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ay, se han acallado las justas armas de la Alianza! Se te recompensará por tu ayuda, $n.$B$BAhora para atender la funesta tarea de recuperar los cuerpos de los muertos....', 0),
(@ID, 'esMX', '¡Ay, se han acallado las justas armas de la Alianza! Se te recompensará por tu ayuda, $n.$B$BAhora para atender la funesta tarea de recuperar los cuerpos de los muertos....', 0);
-- 893 Una selección de armas
-- https://es.classic.wowhead.com/quest=893
SET @ID := 893;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Yo también dudo mucho que los patéticos jabaespines puedan alcanzar cierto nivel de habilidad en herrería pero sigo las órdenes del Jefe de Guerra y aprenderé lo que pueda de la tribu Crines de Acero.$B$BMe han encargado otras tareas ínfimas y lo haré de buen grado si ayuda al pueblo orco.', 0),
(@ID, 'esMX', 'Yo también dudo mucho que los patéticos jabaespines puedan alcanzar cierto nivel de habilidad en herrería pero sigo las órdenes del Jefe de Guerra y aprenderé lo que pueda de la tribu Crines de Acero.$B$BMe han encargado otras tareas ínfimas y lo haré de buen grado si ayuda al pueblo orco.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelentes, excelentes ejemplares, sí señor.$B$BLos jabaespines han avanzado más de lo que esperaba.$B$BAquí tienes, $c, llévate esto y desaparece. Más vale que examine de cerca estas armas. Puede que hayamos subestimado a nuestro enemigo y no podemos permitirnos esta clase de errores.', 0),
(@ID, 'esMX', 'Excelentes, excelentes ejemplares, sí señor.$B$BLos jabaespines han avanzado más de lo que esperaba.$B$BAquí tienes, $c, llévate esto y desaparece. Más vale que examine de cerca estas armas. Puede que hayamos subestimado a nuestro enemigo y no podemos permitirnos esta clase de errores.', 0);
-- 897 El Cosechador
-- https://es.classic.wowhead.com/quest=897
SET @ID := 897;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parecías $gpreocupado:preocupada;, $n. ¿Cómo van tus lecciones en Los Baldíos? ¿Encontraste algo que te molesta?', 0),
(@ID, 'esMX', 'Parecías $gpreocupado:preocupada;, $n. ¿Cómo van tus lecciones en Los Baldíos? ¿Encontraste algo que te molesta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No puedo decir nada de la naturaleza de esta bestia, porque su espíritu ha huido. Pero como habrás adivinado, no pertenece a Los Baldíos. Temo que pueda presagiar un futuro sombrío para nuestro pueblo...$B$BPero, por ahora, prepárate y esperemos que el tiempo desentrañe el misterio de esta criatura.', 0),
(@ID, 'esMX', 'No puedo decir nada de la naturaleza de esta bestia, porque su espíritu ha huido. Pero como habrás adivinado, no pertenece a Los Baldíos. Temo que pueda presagiar un futuro sombrío para nuestro pueblo...$B$BPero, por ahora, prepárate y esperemos que el tiempo desentrañe el misterio de esta criatura.', 0);
-- 898 Escapar del fuerte
-- https://es.classic.wowhead.com/quest=898
SET @ID := 898;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sí?', 0),
(@ID, 'esMX', '¿Sí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Y pensar que creíamos que Bola de fuego había muerto hacía mucho tiempo!$B$BGracias a tu heroísmo te has granjeado un lugar de honor entre los soldados de Thalo\'dan, $n.', 0),
(@ID, 'esMX', '¡Y pensar que creíamos que Bola de fuego había muerto hacía mucho tiempo!$B$BGracias a tu heroísmo te has granjeado un lugar de honor entre los soldados de Thalo\'dan, $n.', 0);
-- 899 Consumido por el odio
-- https://es.classic.wowhead.com/quest=899
SET @ID := 899;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El jabaespín pagará por esto, $n. Lo juro.', 0),
(@ID, 'esMX', 'El jabaespín pagará por esto, $n. Lo juro.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, te has tomado en serio mi tarea y te lo agradezco.$B$BAunque persiste mi deseo de venganza, al menos puedo sonreír al ver que los jabaespines también han sentido dolor.', 0),
(@ID, 'esMX', '$c, te has tomado en serio mi tarea y te lo agradezco.$B$BAunque persiste mi deseo de venganza, al menos puedo sonreír al ver que los jabaespines también han sentido dolor.', 0);
-- 900 El churumbele
-- https://es.classic.wowhead.com/quest=900
SET @ID := 900;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Cierra la válvula de control principal', `ObjectiveText2` = 'Cierra la válvula de control de combustible', `ObjectiveText3` = 'Cierra la válvula reguladora', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 903 Merodeadores de los Baldíos
-- https://es.classic.wowhead.com/quest=903
SET @ID := 903;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $n? ¿Has encontrado los merodeadores?', 0),
(@ID, 'esMX', '¿Cómo va la caza, $n? ¿Has encontrado los merodeadores?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, veo que has estado ocupado, acechando en las praderas y cazando merodeadores. ¿Crees que es hora de enfrentarte a uno de los mejores ejemplares?', 0),
(@ID, 'esMX', 'Ah, veo que has estado ocupado, acechando en las praderas y cazando merodeadores. ¿Crees que es hora de enfrentarte a uno de los mejores ejemplares?', 0);
-- 905 La ira de los segadores
-- https://es.classic.wowhead.com/quest=905
SET @ID := 905;
UPDATE `quest_template_locale` SET `ObjectiveText1` = '', `ObjectiveText3` = 'Visita el nido de raptor amarillo', `ObjectiveText4` = 'Visita el nido de raptor rojo', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en los nidos, $n?', 0),
(@ID, 'esMX', '¿Has estado en los nidos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Conque has ido a los nidos y has colocado las plumas de tu presa en el interior? Hace falta valor, sin lugar a dudas.$B$B¿Te sientes capaz de algo más difícil aún, $n? Porque pareces más fuerte que cuando viniste aquí la primera vez. Supongo que te están sentando bien Los Baldíos.', 0),
(@ID, 'esMX', '¿Conque has ido a los nidos y has colocado las plumas de tu presa en el interior? Hace falta valor, sin lugar a dudas.$B$B¿Te sientes capaz de algo más difícil aún, $n? Porque pareces más fuerte que cuando viniste aquí la primera vez. Supongo que te están sentando bien Los Baldíos.', 0);
-- 906 Traidores
-- https://es.classic.wowhead.com/quest=906
SET @ID := 906;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sí! ¿Qué ocurre?', 0),
(@ID, 'esMX', '¡Sí! ¿Qué ocurre?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado el jefe de los Crines de Acero y lo has matado, $n? Asombroso.$B$BNo tengo palabras pero eso no significa que no esté agradecido. La gente de El Cruce harían bien en respetar tu fuerza.$B$BDebo admitirlo, creía que el jefe de estos asaltos a nuestras líneas de suministros era otro jabaespín. Gracias otra vez, $n.', 0),
(@ID, 'esMX', '¿Has encontrado el jefe de los Crines de Acero y lo has matado, $n? Asombroso.$B$BNo tengo palabras pero eso no significa que no esté agradecido. La gente de El Cruce harían bien en respetar tu fuerza.$B$BDebo admitirlo, creía que el jefe de estos asaltos a nuestras líneas de suministros era otro jabaespín. Gracias otra vez, $n.', 0);
-- 907 Los truenagartos iracundos
-- https://es.classic.wowhead.com/quest=907
SET @ID := 907;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado a los truenagartos, $n?', 0),
(@ID, 'esMX', '¿Has derrotado a los truenagartos, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué bien volver a verte con la prueba de la victoria! Y mejor aún ver que lo has logrado sin partirte ningún hueso.', 0),
(@ID, 'esMX', '¡Qué bien volver a verte con la prueba de la victoria! Y mejor aún ver que lo has logrado sin partirte ningún hueso.', 0);
-- 908 Entre ruinas
-- https://es.classic.wowhead.com/quest=908
SET @ID := 908;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has logrado localizar el núcleo de las profundidades? Sin él, no tendremos idea de lo que hace exactamente el Martillo Crepuscular allí.', 0),
(@ID, 'esMX', '¿Has logrado localizar el núcleo de las profundidades? Sin él, no tendremos idea de lo que hace exactamente el Martillo Crepuscular allí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es exactamente lo que necesito! Un núcleo de las profundidades es un pozo de información increíble del que podremos sacar mucho provecho. Lo que sea que esté haciendo el Martillo Crepuscular allí, y créanme cuando digo que no es bueno, mis camaradas y yo lo descubriremos.$B$BLo has hecho bien aquí hoy; el Anillo de la Tierra te mira con afecto por ayudarnos. También has ayudado a la Horda en su conjunto y deberías estar $gorgulloso:orgullosa; de ello.', 0),
(@ID, 'esMX', '¡Esto es exactamente lo que necesito! Un núcleo de las profundidades es un pozo de información increíble del que podremos sacar mucho provecho. Lo que sea que esté haciendo el Martillo Crepuscular allí, y créanme cuando digo que no es bueno, mis camaradas y yo lo descubriremos.$B$BLo has hecho bien aquí hoy; el Anillo de la Tierra te mira con afecto por ayudarnos. También has ayudado a la Horda en su conjunto y deberías estar $gorgulloso:orgullosa; de ello.', 0);
-- 909 Barón Aquanis
-- https://es.classic.wowhead.com/quest=909
SET @ID := 909;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, hola de nuevo $n. Solo estaba leyendo las olas del mar, como siempre lo hago. ¿Qué te trae al puesto de avanzada?', 0),
(@ID, 'esMX', 'Ah, hola de nuevo $n. Solo estaba leyendo las olas del mar, como siempre lo hago. ¿Qué te trae al puesto de avanzada?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto... esto es todo un hallazgo, $n.$B$B¿Lo adquiriste del barón Aquanis en Brazanegra, dices? Durante mucho tiempo se ha considerado al barón Aquanis como un poder elemental corrupto; este globo demostrará exactamente qué lo había corrompido. Si bien no sería una sorpresa si resultara ser el Martillo Crepuscular, nuestros estudios también mostrarán cómo lo hicieron.$B$BHiciste bien en traerme esto. Por favor, toma esto, junto con los más cálidos saludos del Anillo de la Tierra.', 0),
(@ID, 'esMX', 'Esto... esto es todo un hallazgo, $n.$B$B¿Lo adquiriste del barón Aquanis en Brazanegra, dices? Durante mucho tiempo se ha considerado al barón Aquanis como un poder elemental corrupto; este globo demostrará exactamente qué lo había corrompido. Si bien no sería una sorpresa si resultara ser el Martillo Crepuscular, nuestros estudios también mostrarán cómo lo hicieron.$B$BHiciste bien en traerme esto. Por favor, toma esto, junto con los más cálidos saludos del Anillo de la Tierra.', 0);
-- 910 Un paseo por los embarcaderos
-- https://es.classic.wowhead.com/quest=910
SET @ID := 910;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya llegamos?', 0),
(@ID, 'esMX', '¿Ya llegamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Guau, el océano es ENORME! Y hay muchas gaviotas y cosas de esas... Y es tan ruidoso y bullicioso como creía. Y además hay piratas, ¡es una pasada!$B$BGracias por traerme a Trinquete, $n. ¡Ha sido fantástico!', 0),
(@ID, 'esMX', '¡Guau, el océano es ENORME! Y hay muchas gaviotas y cosas de esas... Y es tan ruidoso y bullicioso como creía. Y además hay piratas, ¡es una pasada!$B$BGracias por traerme a Trinquete, $n. ¡Ha sido fantástico!', 0);
