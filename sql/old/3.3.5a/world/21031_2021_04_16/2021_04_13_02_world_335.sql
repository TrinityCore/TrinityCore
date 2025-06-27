-- 8731 Servicio de campo
-- https://es.classic.wowhead.com/quest=8731
SET @ID := 8731;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado tu servicio de campo, $n? El Capitán Machacacráneos está fuera de Colmen\'Regal.', 0),
(@ID, 'esMX', '¿Has completado tu servicio de campo, $n? El Capitán Machacacráneos está fuera de Colmen\'Regal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Puedo decir que Krug tiene poca habilidad para el papeleo. ¡Lo firmó con sangre silítida!$B$BMuy bien, $n. He preparado un conjunto de tareas que deberían hacer un buen uso de tus habilidades como $c.$B$BCon tus continuos esfuerzos los de otros como tú, ¡nuestro enemigo pronto será aplastado!', 0),
(@ID, 'esMX', 'Puedo decir que Krug tiene poca habilidad para el papeleo. ¡Lo firmó con sangre silítida!$B$BMuy bien, $n. He preparado un conjunto de tareas que deberían hacer un buen uso de tus habilidades como $c.$B$BCon tus continuos esfuerzos los de otros como tú, ¡nuestro enemigo pronto será aplastado!', 0);
-- 8732 Documentación de instrucción de campo
-- https://es.classic.wowhead.com/quest=8732
SET @ID := 8732;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que quiere esos papeles firmados, <chico:chica>', 0),
(@ID, 'esMX', 'Supongo que quiere esos papeles firmados, <chico:chica>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, supongo que esa pequeña escaramuza pasará a ser un deber de campo hoy en día. Llévalos de regreso a Fuerte Cenarion, estoy seguro de que tendrán un trabajo a tu medida.$B$B¡Márchate!', 0),
(@ID, 'esMX', 'Sí, supongo que esa pequeña escaramuza pasará a ser un deber de campo hoy en día. Llévalos de regreso a Fuerte Cenarion, estoy seguro de que tendrán un trabajo a tu medida.$B$B¡Márchate!', 0);
-- 8733 Eranikus, el Tirano del Sueño
-- https://es.classic.wowhead.com/quest=8733
SET @ID := 8733;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La brizna está en silencio excepto por un suave zumbido. Curiosamente, es capaz de comunicarse contigo a través de pensamientos.', 0),
(@ID, 'esMX', 'La brizna está en silencio excepto por un suave zumbido. Curiosamente, es capaz de comunicarse contigo a través de pensamientos.', 0);
-- 8734 Tyrande y Remulos
-- https://es.classic.wowhead.com/quest=8734
SET @ID := 8734;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sería imposible sacar a Eranikus del Sueño si se negaba. Sin embargo, sus intenciones requieren que entre en nuestro mundo. Busca destruir la manifestación viviente de Malfurion. Hacer esto significaría el fin de uno de los aliados más poderosos del Sueño. La Pesadilla consumiría por completo todo lo que queda si Malfurion cayera...', 0),
(@ID, 'esMX', 'Sería imposible sacar a Eranikus del Sueño si se negaba. Sin embargo, sus intenciones requieren que entre en nuestro mundo. Busca destruir la manifestación viviente de Malfurion. Hacer esto significaría el fin de uno de los aliados más poderosos del Sueño. La Pesadilla consumiría por completo todo lo que queda si Malfurion cayera...', 0);
-- 8735 La corrupción de Pesadilla
-- https://es.classic.wowhead.com/quest=8735
SET @ID := 8735;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Remulos está perdido en sus pensamientos.>', 0),
(@ID, 'esMX', '<Remulos está perdido en sus pensamientos.>', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estas $gpreparado:preparada;? ¿Está el mundo preparado para lo que vamos a invocar? No lo sé... estoy obligado por el deber hacia Malfurion. Deber y honor...', 0),
(@ID, 'esMX', '¿Estas $gpreparado:preparada;? ¿Está el mundo preparado para lo que vamos a invocar? No lo sé... estoy obligado por el deber hacia Malfurion. Deber y honor...', 0);
-- 8736 La Pesadilla se manifiesta
-- https://es.classic.wowhead.com/quest=8736
SET @ID := 8736;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Está redimido, $n. Ahora regresa al Sueño para corregir lo que solo él ha hecho mal. Eranikus será un poderoso aliado para Malfurion y mi padre.$B$BEste armamento que me dio la propia Ysera es para ti, $n. Harías bien en utilizarlo en tus batallas contra los qiraji.', 0),
(@ID, 'esMX', 'Está redimido, $n. Ahora regresa al Sueño para corregir lo que solo él ha hecho mal. Eranikus será un poderoso aliado para Malfurion y mi padre.$B$BEste armamento que me dio la propia Ysera es para ti, $n. Harías bien en utilizarlo en tus batallas contra los qiraji.', 0);
-- 8737 Templario azur
-- https://es.classic.wowhead.com/quest=8737
SET @ID := 8737;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has terminado tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has terminado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, $n. Aquí está tu próxima tarea.', 0),
(@ID, 'esMX', 'Buen trabajo, $n. Aquí está tu próxima tarea.', 0);
-- 8738 Informe de exploración de Colmen'Regal
-- https://es.classic.wowhead.com/quest=8738
SET @ID := 8738;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encontrarás al Explorador Landion dentro de Colmen\'Regal. ¡Date prisa, $n! El tiempo es esencial.', 0),
(@ID, 'esMX', 'Encontrarás al Explorador Landion dentro de Colmen\'Regal. ¡Date prisa, $n! El tiempo es esencial.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apreciamos mucho tus esfuerzos, $n. Leeré estos informes de exploración de inmediato, siéntete libre de repasar tu próxima tarea.', 0),
(@ID, 'esMX', 'Apreciamos mucho tus esfuerzos, $n. Leeré estos informes de exploración de inmediato, siéntete libre de repasar tu próxima tarea.', 0);
-- 8739 Informe de exploración de Colmen'Ashi
-- https://es.classic.wowhead.com/quest=8739
SET @ID := 8739;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encontrarás al Explorador Jalia dentro de Colmen\'Ashi. ¡Date prisa, $n! El tiempo es esencial.', 0),
(@ID, 'esMX', 'Encontrarás al Explorador Jalia dentro de Colmen\'Ashi. ¡Date prisa, $n! El tiempo es esencial.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Apreciamos mucho tus esfuerzos, $n. Leeré estos informes de exploración de inmediato, siéntete libre de repasar tu próxima tarea.', 0),
(@ID, 'esMX', 'Apreciamos mucho tus esfuerzos, $n. Leeré estos informes de exploración de inmediato, siéntete libre de repasar tu próxima tarea.', 0);
-- 8740 Los merodeadores Crepusculares
-- https://es.classic.wowhead.com/quest=8740
SET @ID := 8740;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has terminado tu tarea, $n?', 0),
(@ID, 'esMX', '¿Has terminado tu tarea, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. Los merodeadores crepusculares estaban causando un número inaceptable de bajas en nuestras patrullas. Aquí está su próxima tarea.', 0),
(@ID, 'esMX', 'Bien hecho, $n. Los merodeadores crepusculares estaban causando un número inaceptable de bajas en nuestras patrullas. Aquí está su próxima tarea.', 0);
-- 8741 El regreso del Campeón
-- https://es.classic.wowhead.com/quest=8741
SET @ID := 8741;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus obras serán conocidas por todos, $gcampeón:campeona;. Cantarán tus alabanzas desde Orgrimmar hasta los confines de los Mares del Sur. Todos sabrán $gdel campeón:de la campeona; del Vuelo de Bronce, $n.', 0),
(@ID, 'esMX', 'Tus obras serán conocidas por todos, $gcampeón:campeona;. Cantarán tus alabanzas desde Orgrimmar hasta los confines de los Mares del Sur. Todos sabrán $gdel campeón:de la campeona; del Vuelo de Bronce, $n.', 0);
-- 8742 El poder de Kalimdor
-- https://es.classic.wowhead.com/quest=8742
SET @ID := 8742;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Han pasado mil años y, tal como estaba predestinado, $guno:una; está frente a mí. $gUno:Una; que guiará a su pueblo a una nueva era.$B$BEl Dios Antiguo tiembla, $n. Oh, sí, teme tu fe. Rompe la profecía de C\'Thun.$B$BSabe que vienes, $gcampeón:campeona;, y que contigo viene el poder de Kalimdor. Solo tienes que avisarme cuando estés $gpreparado:preparada; y te concederé el Cetro de las arenas movedizas.', 0),
(@ID, 'esMX', 'Han pasado mil años y, tal como estaba predestinado, $guno:una; está frente a mí. $gUno:Una; que guiará a su pueblo a una nueva era.$B$BEl Dios Antiguo tiembla, $n. Oh, sí, teme tu fe. Rompe la profecía de C\'Thun.$B$BSabe que vienes, $gcampeón:campeona;, y que contigo viene el poder de Kalimdor. Solo tienes que avisarme cuando estés $gpreparado:preparada; y te concederé el Cetro de las arenas movedizas.', 0);
-- 8743 Golpear el gong
-- https://es.classic.wowhead.com/quest=8743
SET @ID := 8743;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Gong de Escarabajo se cierne inquietantemente ante ti. Ármate, $n; porque una vez que suene el Gong, se abrirán las puertas de Ahn\'Qiraj.$B$BDe las fauces debilitadas de la bestia solo puede venir el caos y la destrucción. ¡Defiende a tu pueblo!', 0),
(@ID, 'esMX', 'El Gong de Escarabajo se cierne inquietantemente ante ti. Ármate, $n; porque una vez que suene el Gong, se abrirán las puertas de Ahn\'Qiraj.$B$BDe las fauces debilitadas de la bestia solo puede venir el caos y la destrucción. ¡Defiende a tu pueblo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Del suelo cerca del gong brota un cristal especial. Quizás el favor de la Prole.', 0),
(@ID, 'esMX', 'Del suelo cerca del gong brota un cristal especial. Quizás el favor de la Prole.', 0);
-- 8744 Un presente envuelto con cuidado
-- https://es.wowhead.com/quest=8744
SET @ID := 8744;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La etiqueta de este regalo dice:$B$BPara $n:$B$B¡Que pases unas dulces y felices fiestas del Gran Invierno!', 0),
(@ID, 'esMX', 'La etiqueta de este regalo dice:$B$BPara $n:$B$B¡Que pases unas dulces y felices fiestas del Gran Invierno!', 0);
-- Metzen el reno
-- 8746, 8762
-- https://es.classic.wowhead.com/quest=8746
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Rescata al reno Metzen', `VerifiedBuild` = 0 WHERE `id` IN(8746, 8762) AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8746, 8762) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8746, 'esES', '¿Conseguiste localizar a Metzen con las notas que te di? No quiero ni pensar en cómo lo estarán tratando... ¡Pero no podemos pagar el rescate!', 0),
(8762, 'esES', '¿Conseguiste localizar a Metzen con las notas que te di? No quiero ni pensar en cómo lo estarán tratando... ¡Pero no podemos pagar el rescate!', 0),
(8746, 'esMX', '¿Conseguiste localizar a Metzen con las notas que te di? No quiero ni pensar en cómo lo estarán tratando... ¡Pero no podemos pagar el rescate!', 0),
(8762, 'esMX', '¿Conseguiste localizar a Metzen con las notas que te di? No quiero ni pensar en cómo lo estarán tratando... ¡Pero no podemos pagar el rescate!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8746, 8762) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8746, 'esES', '¡Bravo!$B$BMetzen ya está a salvo en los establos de Papá Invierno. ¡Sabía que el polvo funcionaría! Has salvado el Festival de Invierno y a Pastos de Bosquehumeante, $n.$B$BAcepta esto como prueba de gratitud; te gustará. ¡Feliz Festival de Invierno!', 0),
(8762, 'esES', '¡Bravo!$B$BMetzen ya está a salvo en los establos de Papá Invierno. ¡Sabía que el polvo funcionaría! Has salvado el Festival de Invierno y a Pastos de Bosquehumeante, $n.$B$BAcepta esto como prueba de gratitud; te gustará. ¡Feliz Festival de Invierno!', 0),
(8746, 'esMX', '¡Bravo!$B$BMetzen ya está a salvo en los establos de Papá Invierno. ¡Sabía que el polvo funcionaría! Has salvado el Festival de Invierno y a Pastos de Bosquehumeante, $n.$B$BAcepta esto como prueba de gratitud; te gustará. ¡Feliz Festival de Invierno!', 0),
(8762, 'esMX', '¡Bravo!$B$BMetzen ya está a salvo en los establos de Papá Invierno. ¡Sabía que el polvo funcionaría! Has salvado el Festival de Invierno y a Pastos de Bosquehumeante, $n.$B$BAcepta esto como prueba de gratitud; te gustará. ¡Feliz Festival de Invierno!', 0);
-- El camino del protector
-- 8747, 8752, 8757
-- https://es.classic.wowhead.com/quest=8747
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8747, 8752, 8757) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8747, 'esES', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8752, 'esES', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8757, 'esES', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8747, 'esMX', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8752, 'esMX', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8757, 'esMX', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8747, 8752, 8757) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8747, 'esES', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8752, 'esES', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8757, 'esES', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8747, 'esMX', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8752, 'esMX', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0),
(8757, 'esMX', 'Impresionante, $gpequeño:pequeña;. Has pasado por muchos problemas para ganarte el favor del Vuelo de Bronce. Se nota tu dedicación.$B$BEl Sello del Vuelo de Bronce, ofrecerá una protección superior contra las fuerzas del mal.$B$BTen cuidado, una vez que hayas elegido tu camino, no tendrás nada en caso de que cambies de opinión.', 0);
-- El camino del protector
-- 8748, 8753, 8758
-- https://es.classic.wowhead.com/quest=8748
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8748, 8753, 8758) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8748, 'esES', 'Se ha reconocido su continua defensa de los niños de Kalimdor. Dame tu anillo de sello para que pueda potenciar sus poderes.', 0),
(8753, 'esES', 'Se ha reconocido su continua defensa de los niños de Kalimdor. Dame tu anillo de sello para que pueda potenciar sus poderes.', 0),
(8758, 'esES', 'Se ha reconocido su continua defensa de los niños de Kalimdor. Dame tu anillo de sello para que pueda potenciar sus poderes.', 0),
(8748, 'esMX', 'Se ha reconocido su continua defensa de los niños de Kalimdor. Dame tu anillo de sello para que pueda potenciar sus poderes.', 0),
(8753, 'esMX', 'Se ha reconocido su continua defensa de los niños de Kalimdor. Dame tu anillo de sello para que pueda potenciar sus poderes.', 0),
(8758, 'esMX', 'Se ha reconocido su continua defensa de los niños de Kalimdor. Dame tu anillo de sello para que pueda potenciar sus poderes.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8748, 8753, 8758) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8748, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8753, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8758, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8748, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8753, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8758, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0);
-- El camino del protector
-- 8749, 8754, 8759
-- https://es.classic.wowhead.com/quest=8749
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8749, 8754, 8759) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8749, 'esES', 'Honras a los de mi especie, $n. ¡Derriba a los enemigos de Kalimdor! Muéstrales lo que significa desfigurar la tierra de la eterna luz de las estrellas.$B$BHas obtenido otra mejora. Dame tu anillo de sello para que pueda reforzar su poder.', 0),
(8754, 'esES', 'Honras a los de mi especie, $n. ¡Derriba a los enemigos de Kalimdor! Muéstrales lo que significa desfigurar la tierra de la eterna luz de las estrellas.$B$BHas obtenido otra mejora. Dame tu anillo de sello para que pueda reforzar su poder.', 0),
(8759, 'esES', 'Honras a los de mi especie, $n. ¡Derriba a los enemigos de Kalimdor! Muéstrales lo que significa desfigurar la tierra de la eterna luz de las estrellas.$B$BHas obtenido otra mejora. Dame tu anillo de sello para que pueda reforzar su poder.', 0),
(8749, 'esMX', 'Honras a los de mi especie, $n. ¡Derriba a los enemigos de Kalimdor! Muéstrales lo que significa desfigurar la tierra de la eterna luz de las estrellas.$B$BHas obtenido otra mejora. Dame tu anillo de sello para que pueda reforzar su poder.', 0),
(8754, 'esMX', 'Honras a los de mi especie, $n. ¡Derriba a los enemigos de Kalimdor! Muéstrales lo que significa desfigurar la tierra de la eterna luz de las estrellas.$B$BHas obtenido otra mejora. Dame tu anillo de sello para que pueda reforzar su poder.', 0),
(8759, 'esMX', 'Honras a los de mi especie, $n. ¡Derriba a los enemigos de Kalimdor! Muéstrales lo que significa desfigurar la tierra de la eterna luz de las estrellas.$B$BHas obtenido otra mejora. Dame tu anillo de sello para que pueda reforzar su poder.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8749, 8754, 8759) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8749, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8754, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8759, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8749, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8754, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8759, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0);
-- El camino del protector
-- 8750, 8755, 8760
-- https://es.classic.wowhead.com/quest=8750
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8750, 8755, 8760) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8750, 'esES', 'Una dedicación de esta magnitud es una rareza. Has demostrado que tu voluntad es inquebrantable, $n. Serás $grecompensado:recompensada; por tu inquebrantable vigilancia de nuestro mundo.$B$BDame tu anillo de sello para que pueda fortalecer su encantamiento.', 0),
(8755, 'esES', 'Una dedicación de esta magnitud es una rareza. Has demostrado que tu voluntad es inquebrantable, $n. Serás $grecompensado:recompensada; por tu inquebrantable vigilancia de nuestro mundo.$B$BDame tu anillo de sello para que pueda fortalecer su encantamiento.', 0),
(8760, 'esES', 'Una dedicación de esta magnitud es una rareza. Has demostrado que tu voluntad es inquebrantable, $n. Serás $grecompensado:recompensada; por tu inquebrantable vigilancia de nuestro mundo.$B$BDame tu anillo de sello para que pueda fortalecer su encantamiento.', 0),
(8750, 'esMX', 'Una dedicación de esta magnitud es una rareza. Has demostrado que tu voluntad es inquebrantable, $n. Serás $grecompensado:recompensada; por tu inquebrantable vigilancia de nuestro mundo.$B$BDame tu anillo de sello para que pueda fortalecer su encantamiento.', 0),
(8755, 'esMX', 'Una dedicación de esta magnitud es una rareza. Has demostrado que tu voluntad es inquebrantable, $n. Serás $grecompensado:recompensada; por tu inquebrantable vigilancia de nuestro mundo.$B$BDame tu anillo de sello para que pueda fortalecer su encantamiento.', 0),
(8760, 'esMX', 'Una dedicación de esta magnitud es una rareza. Has demostrado que tu voluntad es inquebrantable, $n. Serás $grecompensado:recompensada; por tu inquebrantable vigilancia de nuestro mundo.$B$BDame tu anillo de sello para que pueda fortalecer su encantamiento.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8750, 8755, 8760) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8750, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8755, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8760, 'esES', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8750, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8755, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0),
(8760, 'esMX', 'Tu ascenso en el rango de la Prole es de lo más impresionante, $n. ¡Que nunca te desvíes del camino del protector!', 0);
-- 8751 El protector de Kalimdor
-- https://es.wowhead.com/quest=8751
SET @ID := 8751;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca había visto tanta tenacidad! El Vuelo Bronce te concede un último encantamiento. ¡El mismísimo Atemporal así lo ha pedido!$B$BDame tu sello para que pueda hacer los ajustes necesarios.', 0),
(@ID, 'esMX', '¡Nunca había visto tanta tenacidad! El Vuelo Bronce te concede un último encantamiento. ¡El mismísimo Atemporal así lo ha pedido!$B$BDame tu sello para que pueda hacer los ajustes necesarios.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Arriba, $gprotector:protectora; de Kalimdor! ¡Levántate y obtén tu reconocimiento!', 0),
(@ID, 'esMX', '¡Arriba, $gprotector:protectora; de Kalimdor! ¡Levántate y obtén tu reconocimiento!', 0);
-- 8756 El conquistador qiraji
-- https://es.classic.wowhead.com/quest=8756
SET @ID := 8756;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca había visto tanta tenacidad! El Vuelo de Bronce te otorga un encantamiento final. ¡El Atemporal mismo lo ha pedido así!$B$BEntrégame tu anillo de sello para que pueda hacer los ajustes necesarios.', 0),
(@ID, 'esMX', '¡Nunca había visto tanta tenacidad! El Vuelo de Bronce te otorga un encantamiento final. ¡El Atemporal mismo lo ha pedido así!$B$BEntrégame tu anillo de sello para que pueda hacer los ajustes necesarios.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Levántate, $gconquistador:conquistadora; Qiraji! ¡Levántate y sé $greconocido:reconocida;!', 0),
(@ID, 'esMX', '¡Levántate, $gconquistador:conquistadora; Qiraji! ¡Levántate y sé $greconocido:reconocida;!', 0);
-- 8761 El gran convocador
-- https://es.classic.wowhead.com/quest=8761
SET @ID := 8761;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Nunca había visto tanta tenacidad! El Vuelo Bronce te concede un último encantamiento. ¡El mismísimo Atemporal así lo ha pedido!$B$BDame tu sello para que pueda hacer los ajustes necesarios.', 0),
(@ID, 'esMX', '¡Nunca había visto tanta tenacidad! El Vuelo Bronce te concede un último encantamiento. ¡El mismísimo Atemporal así lo ha pedido!$B$BDame tu sello para que pueda hacer los ajustes necesarios.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Arriba, gran $gconvocador:convocadora;! ¡Yérguete y obtén tu reconocimiento!', 0),
(@ID, 'esMX', '¡Arriba, gran $gconvocador:convocadora;! ¡Yérguete y obtén tu reconocimiento!', 0);
-- Cambio de ruta: protector, nunca más
-- 8764, 8765, 8766
-- https://es.classic.wowhead.com/quest=8764
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8764, 8765, 8766) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8764, 'esES', '$gCampeón:Campeona;, si decides caminar por otro camino, regálame tu anillo de sello y una montaña de escarabajos de nuestros enemigos en Ahn\'Qiraj.', 0),
(8765, 'esES', '$gCampeón:Campeona;, si decides caminar por otro camino, regálame tu anillo de sello y una montaña de escarabajos de nuestros enemigos en Ahn\'Qiraj.', 0),
(8766, 'esES', '$gCampeón:Campeona;, si decides caminar por otro camino, regálame tu anillo de sello y una montaña de escarabajos de nuestros enemigos en Ahn\'Qiraj.', 0),
(8764, 'esMX', '$gCampeón:Campeona;, si decides caminar por otro camino, regálame tu anillo de sello y una montaña de escarabajos de nuestros enemigos en Ahn\'Qiraj.', 0),
(8765, 'esMX', '$gCampeón:Campeona;, si decides caminar por otro camino, regálame tu anillo de sello y una montaña de escarabajos de nuestros enemigos en Ahn\'Qiraj.', 0),
(8766, 'esMX', '$gCampeón:Campeona;, si decides caminar por otro camino, regálame tu anillo de sello y una montaña de escarabajos de nuestros enemigos en Ahn\'Qiraj.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8764, 8765, 8766) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8764, 'esES', 'Está bien, $n. Si cambias de opinión, estaré aquí para ayudarte.', 0),
(8765, 'esES', 'Está bien, $n. Si cambias de opinión, estaré aquí para ayudarte.', 0),
(8766, 'esES', 'Está bien, $n. Si cambias de opinión, estaré aquí para ayudarte.', 0),
(8764, 'esMX', 'Está bien, $n. Si cambias de opinión, estaré aquí para ayudarte.', 0),
(8765, 'esMX', 'Está bien, $n. Si cambias de opinión, estaré aquí para ayudarte.', 0),
(8766, 'esMX', 'Está bien, $n. Si cambias de opinión, estaré aquí para ayudarte.', 0);
-- Un obsequio ligeramente agitado
-- 8767, 8788
-- https://es.classic.wowhead.com/quest=8767
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8767, 8788) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8767, 'esES', 'Parece que han agitado este regalo un par de veces. Su etiqueta dice:$B$BPara $gun:una; $r $c muy especial.', 0),
(8788, 'esES', 'Parece que han agitado este regalo un par de veces. Su etiqueta dice:$B$BPara $gun:una; $r $c muy especial.', 0),
(8767, 'esMX', 'Parece que han agitado este regalo un par de veces. Su etiqueta dice:$B$BPara $gun:una; $r $c muy especial.', 0),
(8788, 'esMX', 'Parece que han agitado este regalo un par de veces. Su etiqueta dice:$B$BPara $gun:una; $r $c muy especial.', 0);
-- 8768 Un presente con envoltorio alegre
-- https://es.wowhead.com/quest=8768
SET @ID := 8768;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El regalo está envuelto con motivos propios de estas fiestas y tiene tu nombre.$B$BEspera, ¿no acaba de moverse?', 0),
(@ID, 'esMX', 'El regalo está envuelto con motivos propios de estas fiestas y tiene tu nombre.$B$BEspera, ¿no acaba de moverse?', 0);
-- 8769 Un presente que hace tic tac
-- https://es.classic.wowhead.com/quest=8769
SET @ID := 8769;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tus amigos de los Pastos de Bosquehumeante te desean unas felices Fiestas del Gran Invierno.', 0),
(@ID, 'esMX', 'Tus amigos de los Pastos de Bosquehumeante te desean unas felices Fiestas del Gran Invierno.', 0);
-- 8770 Objetivo: los defensores Colmen'Ashi
-- https://es.classic.wowhead.com/quest=8770
SET @ID := 8770;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Tu diligencia es tan notable como siempre.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Tu diligencia es tan notable como siempre.', 0);
-- 8771 Objetivo: los acecharenas Colmen'Ashi
-- https://es.classic.wowhead.com/quest=8771
SET @ID := 8771;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Se ha notado tu participación en el ataque a Colmen\'Ashi.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Se ha notado tu participación en el ataque a Colmen\'Ashi.', 0);
-- 8772 Objetivo: los oteadores de Colmen'Zora
-- https://es.classic.wowhead.com/quest=8772
SET @ID := 8772;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo, $n. Se ha notado tu participación en el ataque a Colmen\'Zora.', 0),
(@ID, 'esMX', 'Excelente trabajo, $n. Se ha notado tu participación en el ataque a Colmen\'Zora.', 0);
-- 8773 Objetivo: los atracadores de Colmen'Zora
-- https://es.classic.wowhead.com/quest=8773
SET @ID := 8773;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Escuché cosas buenas sobre tu participación en el ataque de Colmen\'Zora. Siguen con el buen trabajo y la victoria pronto será nuestra.', 0),
(@ID, 'esMX', 'Escuché cosas buenas sobre tu participación en el ataque de Colmen\'Zora. Siguen con el buen trabajo y la victoria pronto será nuestra.', 0);
-- Objetivo: los emboscadores Colmen'Regal
-- 8774, 8775, 8776, 8777
-- https://es.classic.wowhead.com/quest=8774
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8774, 8775, 8776, 8777) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8774, 'esES', '¿Tienes algo que decirme, $n?', 0),
(8775, 'esES', '¿Tienes algo que decirme, $n?', 0),
(8776, 'esES', '¿Tienes algo que decirme, $n?', 0),
(8777, 'esES', '¿Tienes algo que decirme, $n?', 0),
(8774, 'esMX', '¿Tienes algo que decirme, $n?', 0),
(8775, 'esMX', '¿Tienes algo que decirme, $n?', 0),
(8776, 'esMX', '¿Tienes algo que decirme, $n?', 0),
(8777, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8774, 8775, 8776, 8777) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8774, 'esES', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0),
(8775, 'esES', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0),
(8776, 'esES', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0),
(8777, 'esES', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0),
(8774, 'esMX', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0),
(8775, 'esMX', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0),
(8776, 'esMX', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0),
(8777, 'esMX', 'Excelente trabajo, $n. Tu participación en el ataque a Colmen\'Regal ha sido notoria.', 0);
