-- 846 La venganza de Gann
-- https://es.classic.wowhead.com/quest=846
SET @ID := 846;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que has vuelto, $n.$B$BAunque la muerte de Khazgorm pueda retrasar algo la excavación de mis tierras ancestrales, no acabará completamente con la destrucción.$B$BEl castillo de Bael Modan es una amenaza militar creciente. Construido para defender la excavación, está ahora repleto de tropas ofensivas.$B$BSi tienes los ingredientes que pedí, puedo confeccionar una carga que hará que esos precipitados enanos se replanteen sus acciones en Los Baldíos.', 0),
(@ID, 'esMX', 'Veo que has vuelto, $n.$B$BAunque la muerte de Khazgorm pueda retrasar algo la excavación de mis tierras ancestrales, no acabará completamente con la destrucción.$B$BEl castillo de Bael Modan es una amenaza militar creciente. Construido para defender la excavación, está ahora repleto de tropas ofensivas.$B$BSi tienes los ingredientes que pedí, puedo confeccionar una carga que hará que esos precipitados enanos se replanteen sus acciones en Los Baldíos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Veo que eres muy $gtrabajador:trabajadora;, $c.$B$BSin duda tendremos pronto una sorpresa apropiada para esos enanos.', 0),
(@ID, 'esMX', 'Veo que eres muy $gtrabajador:trabajadora;, $c.$B$BSin duda tendremos pronto una sorpresa apropiada para esos enanos.', 0);
-- 847 La astucia del raptor
-- https://es.classic.wowhead.com/quest=847
SET @ID := 847;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando el encantamiento se pase, hablaré con Gor\'mul. Te agradezco tu ayuda para devolver a Gor\'mul a la tierra de los vivos. No me cabe la menor duda de que él también te lo agradece infinitamente.', 0),
(@ID, 'esMX', 'Cuando el encantamiento se pase, hablaré con Gor\'mul. Te agradezco tu ayuda para devolver a Gor\'mul a la tierra de los vivos. No me cabe la menor duda de que él también te lo agradece infinitamente.', 0);
-- 848 Esporas de hongos
-- https://es.classic.wowhead.com/quest=848
SET @ID := 848;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las esporas, $n? Debo enviarle un preparado a mi socio de Cima del Trueno, para el que necesito las esporas...', 0),
(@ID, 'esMX', '¿Tienes las esporas, $n? Debo enviarle un preparado a mi socio de Cima del Trueno, para el que necesito las esporas...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. Son buenos ejemplares. Potentes.$B$BSoy un Renegado y siempre cumplimos nuestros contratos. Aquí tienes tu recompensa, $n.', 0),
(@ID, 'esMX', 'Ah, sí. Son buenos ejemplares. Potentes.$B$BSoy un Renegado y siempre cumplimos nuestros contratos. Aquí tienes tu recompensa, $n.', 0);
-- 849 La venganza de Gann
-- https://es.classic.wowhead.com/quest=849
SET @ID := 849;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Máquina voladora de Bael Modan destruida', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una vez que la máquina voladora enana haya sido destruida, sentiré la dulce satisfacción de la venganza.', 0),
(@ID, 'esMX', 'Una vez que la máquina voladora enana haya sido destruida, sentiré la dulce satisfacción de la venganza.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has hecho muy bien, $n! Que en todo Cima del Trueno te veneren como un defensor de las sagradas tierras tauren y como $gcampeón:campeona; de la tribu perdida.', 0),
(@ID, 'esMX', '¡Lo has hecho muy bien, $n! Que en todo Cima del Trueno te veneren como un defensor de las sagradas tierras tauren y como $gcampeón:campeona; de la tribu perdida.', 0);
-- 850 Los jefes Kolkar
-- https://es.classic.wowhead.com/quest=850
SET @ID := 850;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Me traes la cabeza de Barak?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Me traes la cabeza de Barak?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Los centauros son criaturas bajas y primarias pero algunos son listos y tienen visión para erigirse en líderes. Y estos son los más peligrosos.$B$BBarak era uno de estos centauros. Está muy bien que haya muerto.', 0),
(@ID, 'esMX', 'Muy bien, $n. Los centauros son criaturas bajas y primarias pero algunos son listos y tienen visión para erigirse en líderes. Y estos son los más peligrosos.$B$BBarak era uno de estos centauros. Está muy bien que haya muerto.', 0);
-- 851 Verog el Derviche
-- https://es.classic.wowhead.com/quest=851
SET @ID := 851;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado a Verog, $n?', 0),
(@ID, 'esMX', '¿Has encontrado a Verog, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien. Debes de haber causado mucho revuelo entre los centauros, nuestros guardias detectaron actividad cerca de El Oasis Estancado, y probablemente fueras tú.$B$BPuedes sentirte $gorgulloso:orgullosa; por este acto heroico, $n. Eres muy valiente.', 0),
(@ID, 'esMX', 'Muy bien. Debes de haber causado mucho revuelo entre los centauros, nuestros guardias detectaron actividad cerca de El Oasis Estancado, y probablemente fueras tú.$B$BPuedes sentirte $gorgulloso:orgullosa; por este acto heroico, $n. Eres muy valiente.', 0);
-- 852 Hezrul Marcasangre
-- https://es.classic.wowhead.com/quest=852
SET @ID := 852;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha sido derrotado Hezrul, $n?', 0),
(@ID, 'esMX', '¿Ha sido derrotado Hezrul, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gdigno:digna; de elogio, $n. Estos centauros son indisciplinados y no pueden concentrar su furia como los orcos, pero no son menos feroces. Al derrotarlos, has demostrado tu valentía.', 0),
(@ID, 'esMX', 'Eres $gdigno:digna; de elogio, $n. Estos centauros son indisciplinados y no pueden concentrar su furia como los orcos, pero no son menos feroces. Al derrotarlos, has demostrado tu valentía.', 0);
-- 853 Boticaria Zamah
-- https://es.classic.wowhead.com/quest=853
SET @ID := 853;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes algo del boticario Helbrim?', 0),
(@ID, 'esMX', '¿Traes algo del boticario Helbrim?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, las esporas de Los Baldíos que Helbrim andaba recolectando. ¿Te pidió ayuda para entregarlas? Bien.$B$BY la emulsión aún tiene fuerza, así que no has debido de perder el tiempo en la entrega. Muy bien, $c.', 0),
(@ID, 'esMX', 'Ah, las esporas de Los Baldíos que Helbrim andaba recolectando. ¿Te pidió ayuda para entregarlas? Bien.$B$BY la emulsión aún tiene fuerza, así que no has debido de perder el tiempo en la entrega. Muy bien, $c.', 0);
-- 854 Viaja a El Cruce
-- https://es.classic.wowhead.com/quest=854
SET @ID := 854;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegro de ver que nos llegan aliados incuso desde Cima del Trueno.', 0),
(@ID, 'esMX', 'Me alegro de ver que nos llegan aliados incuso desde Cima del Trueno.', 0);
-- 855 Los brazales centauro
-- https://es.classic.wowhead.com/quest=855
SET @ID := 855;
UPDATE `quest_template_locale` SET `Objectives` = 'Llévale 15 brazales centauro de maleantes y videntormentos Kolkar.', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va tu caza, $n?', 0),
(@ID, 'esMX', '¿Cómo va tu caza, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bravo. Seguro que has sembrado el terror entre los centauros supervivientes, $n. Ahora que sus mejores guerreros han caído, o bien cesarán sus avances o bien se lanzarán sobre nosotros con imprudencia.$B$BYo espero que sea lo segundo.', 0),
(@ID, 'esMX', 'Bravo. Seguro que has sembrado el terror entre los centauros supervivientes, $n. Ahora que sus mejores guerreros han caído, o bien cesarán sus avances o bien se lanzarán sobre nosotros con imprudencia.$B$BYo espero que sea lo segundo.', 0);
-- 857 La Lágrima de las Lunas
-- https://es.classic.wowhead.com/quest=857
SET @ID := 857;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde está la Lágrima de las Lunas? ¡La necesito ahora! ¡Huelga decirlo!', 0),
(@ID, 'esMX', '¿Dónde está la Lágrima de las Lunas? ¡La necesito ahora! ¡Huelga decirlo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin, ¡el poder vuelve a ser mío! ¡Mío y solo mío!', 0),
(@ID, 'esMX', 'Por fin, ¡el poder vuelve a ser mío! ¡Mío y solo mío!', 0);
-- 858 La llave de contacto
-- https://es.classic.wowhead.com/quest=858
SET @ID := 858;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Rápido, tenemos que salir de aquí antes de que alguien sospeche algo!', 0),
(@ID, 'esMX', '¡Rápido, tenemos que salir de aquí antes de que alguien sospeche algo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, esta parece la llave correcta. Permíteme que me asegure de que sé cómo funciona...$B$BA ver... control de rotación… Esto regula la velocidad y la estabilidad... buen control de movimiento del brazo. ¡Fíjate en esto! No puedo creer que Ventura y Cía. lograran diseñar algo tan superior a nuestro modelo. ¡Tengo que llevar esto a Trinquete!', 0),
(@ID, 'esMX', 'Sí, esta parece la llave correcta. Permíteme que me asegure de que sé cómo funciona...$B$BA ver... control de rotación… Esto regula la velocidad y la estabilidad... buen control de movimiento del brazo. ¡Fíjate en esto! No puedo creer que Ventura y Cía. lograran diseñar algo tan superior a nuestro modelo. ¡Tengo que llevar esto a Trinquete!', 0);
-- 862 Estofado de ratas de madriguera
-- https://es.classic.wowhead.com/quest=862
SET @ID := 862;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya les has dado una paliza a suficientes ratas de madriguera, $n?', 0),
(@ID, 'esMX', '¿Ya les has dado una paliza a suficientes ratas de madriguera, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Normalmente no como estos roedores cuando están tan... tan... a punto. Me gusta dejarlos pudrirse unas semanas para sacarle el máximo de sabor. Pero parecías tener hambre.$B$BTe prepararé un guiso de rata de madriguera. Ah, aquí está.$B$B¡Aquí tienes!', 0),
(@ID, 'esMX', 'Normalmente no como estos roedores cuando están tan... tan... a punto. Me gusta dejarlos pudrirse unas semanas para sacarle el máximo de sabor. Pero parecías tener hambre.$B$BTe prepararé un guiso de rata de madriguera. Ah, aquí está.$B$B¡Aquí tienes!', 0);
-- 863 La fuga
-- https://es.classic.wowhead.com/quest=863
SET @ID := 863;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Puedo ayudarte?', 0),
(@ID, 'esMX', '¿Puedo ayudarte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Con suerte conseguiremos algo de valor por el prototipo de trituradora estropeado... ¡se me acaba el tiempo! Enviaré un equipo de rescate donde se encuentra Rabiaire a paso ligero.$B$BOh, y aquí tienes algo por las molestias, claro.', 0),
(@ID, 'esMX', 'Con suerte conseguiremos algo de valor por el prototipo de trituradora estropeado... ¡se me acaba el tiempo! Enviaré un equipo de rescate donde se encuentra Rabiaire a paso ligero.$B$BOh, y aquí tienes algo por las molestias, claro.', 0);
-- 864 Regresa junto a la boticaria Zinge
-- https://es.classic.wowhead.com/quest=864
SET @ID := 864;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$gBienvenida:Bienvenida; de nuevo. Al menos, $gbienvenido:bienvenida; de nuevo si has regresado con un kit de prueba sellado. De lo contrario, fingiré no darme cuenta de tu total incompetencia y evitaré mi ira hastas que haga lo que se te ha encomendado y cumplas mi tarea.', 0),
(@ID, 'esMX', '$gBienvenida:Bienvenida; de nuevo. Al menos, $gbienvenido:bienvenida; de nuevo si has regresado con un kit de prueba sellado. De lo contrario, fingiré no darme cuenta de tu total incompetencia y evitaré mi ira hastas que haga lo que se te ha encomendado y cumplas mi tarea.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Analizaré estos datos de inmediato. Quizás la locura de Keever resulte ser mi genio después de todo.$B$BEn cuanto a ti.. me eres útil y recompenso bastante bien a $glos:las; que siguen siendo útiles. Toma este artículo, esta moneda y, lo más importante, mi agradecimiento junto con ellos.$B$BVuelve conmigo de vez en cuando. Apuesto a que nuestro trabajo conjunto en este proyecto no ha terminado.', 0),
(@ID, 'esMX', 'Analizaré estos datos de inmediato. Quizás la locura de Keever resulte ser mi genio después de todo.$B$BEn cuanto a ti.. me eres útil y recompenso bastante bien a $glos:las; que siguen siendo útiles. Toma este artículo, esta moneda y, lo más importante, mi agradecimiento junto con ellos.$B$BVuelve conmigo de vez en cuando. Apuesto a que nuestro trabajo conjunto en este proyecto no ha terminado.', 0);
-- 866 Recoge muestras de raíces
-- https://es.classic.wowhead.com/quest=866
SET @ID := 866;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola, $n. ¿Has encontrado esas muestras de raíces?', 0),
(@ID, 'esMX', 'Hola, $n. ¿Has encontrado esas muestras de raíces?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, sí, ¡hermosos ejemplares! Cultivaré estas raíces y las estudiaré. Espero descubrir nuevas propiedades. ¡Ocultas y valiosas propiedades...!$B$BY no te preocupes, si lo consigo, serás $gel primero:la primera; en saberlo. ¡Porque necesitaré más!', 0),
(@ID, 'esMX', 'Sí, sí, ¡hermosos ejemplares! Cultivaré estas raíces y las estudiaré. Espero descubrir nuevas propiedades. ¡Ocultas y valiosas propiedades...!$B$BY no te preocupes, si lo consigo, serás $gel primero:la primera; en saberlo. ¡Porque necesitaré más!', 0);
-- 867 Arpías saqueadoras
-- https://es.classic.wowhead.com/quest=867
SET @ID := 867;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has cortado suficientes? Sigue cortando y llevándote trofeos. Quiero 8 talones de Alabruja.', 0),
(@ID, 'esMX', '¿Ya has cortado suficientes? Sigue cortando y llevándote trofeos. Quiero 8 talones de Alabruja.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh, hermosos ejemplares. Realmente hermosos... Buen trabajo, $n. Espero volver a trabajar contigo en el futuro.', 0),
(@ID, 'esMX', 'Oh, hermosos ejemplares. Realmente hermosos... Buen trabajo, $n. Espero volver a trabajar contigo en el futuro.', 0);
-- 868 ¡A cazar huevos!
-- https://es.classic.wowhead.com/quest=868
SET @ID := 868;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuidado con los huevos que encuentres, $n. Si se quiebran, no me servirán.', 0),
(@ID, 'esMX', 'Cuidado con los huevos que encuentres, $n. Si se quiebran, no me servirán.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me gustas, $n. Los huevos y la herramienta. Muy bien.$B$BY de recompensa…', 0),
(@ID, 'esMX', 'Me gustas, $n. Los huevos y la herramienta. Muy bien.$B$BY de recompensa…', 0);
-- 869 Los raptores ladrones
-- https://es.classic.wowhead.com/quest=869
SET @ID := 869;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Me traes esas cabezas, $n?', 0),
(@ID, 'esMX', '¿Me traes esas cabezas, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Te has librado de los raptores!$B$BGracias, $n.$B$BEres $gun:una; $c de gran valía.', 0),
(@ID, 'esMX', '¡Te has librado de los raptores!$B$BGracias, $n.$B$BEres $gun:una; $c de gran valía.', 0);
-- 870 Las Charcas del Olvido
-- Notice: English text is also missing
-- https://es.classic.wowhead.com/quest=870
SET @ID := 870;
UPDATE `quest_request_items` SET `CompletionText` = 'Have you been to the Forgotten Pools, $n? Did you find anything?', `VerifiedBuild` = 0 WHERE `id` = @ID;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has estado en Las Charcas del olvido, $n? ¿Encontraste algo?', 0),
(@ID, 'esMX', '¿Has estado en Las Charcas del olvido, $n? ¿Encontraste algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has encontrado una grieta en la tierra?... ¿y salían gases burbujeantes? ¡Qué extraño! Esto podría ser la respuesta a nuestras preguntas pero aún no podemos estar seguros.$B$BAunque es una pista. Y te agradezco que la encontraras.', 0),
(@ID, 'esMX', '¿Has encontrado una grieta en la tierra?... ¿y salían gases burbujeantes? ¡Qué extraño! Esto podría ser la respuesta a nuestras preguntas pero aún no podemos estar seguros.$B$BAunque es una pista. Y te agradezco que la encontraras.', 0);
-- 871 Acabar con los ataques de los Crines de Acero
-- https://es.classic.wowhead.com/quest=871
SET @ID := 871;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuanto más se tarde en detener estos ataques, más difícil será proporcionar suministros a la gente de El Cruce.', 0),
(@ID, 'esMX', 'Cuanto más se tarde en detener estos ataques, más difícil será proporcionar suministros a la gente de El Cruce.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo has hecho muy bien, $n. Esos insolentes jabaespines al fin aprenderán que el poder de la Horda no se debe ignorar.', 0),
(@ID, 'esMX', 'Lo has hecho muy bien, $n. Esos insolentes jabaespines al fin aprenderán que el poder de la Horda no se debe ignorar.', 0);
-- 872 El fin de las hostilidades
-- https://es.classic.wowhead.com/quest=872
SET @ID := 872;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Córtale la cabeza al jefe y el caos se instaurará, $n. Aprende bien esta lección. Te será útil en el futuro.$B$BLos jabalíes estarán perdidos sin su líder y podremos recuperar Los Baldíos.', 0),
(@ID, 'esMX', 'Córtale la cabeza al jefe y el caos se instaurará, $n. Aprende bien esta lección. Te será útil en el futuro.$B$BLos jabalíes estarán perdidos sin su líder y podremos recuperar Los Baldíos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Con la muerte de Kreenig, seguro que los ataques a nuestras caravanas se reducirán.$B$BTu pueblo debería estar orgulloso de alguien como tú.', 0),
(@ID, 'esMX', 'Muy bien, $n. Con la muerte de Kreenig, seguro que los ataques a nuestras caravanas se reducirán.$B$BTu pueblo debería estar orgulloso de alguien como tú.', 0);
-- 873 Isha Awak
-- https://es.classic.wowhead.com/quest=873
SET @ID := 873;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No temas a las aguas, $r.', 0),
(@ID, 'esMX', 'No temas a las aguas, $r.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora eres un todo con Isha Awak, $n. Su espíritu está contigo. Ronda en tus ojos...$B$BOjos que, algún día, aprenderán a ver.', 0),
(@ID, 'esMX', 'Ahora eres un todo con Isha Awak, $n. Su espíritu está contigo. Ronda en tus ojos...$B$BOjos que, algún día, aprenderán a ver.', 0);
-- 874 Mahren Vidente del Cielo
-- https://es.classic.wowhead.com/quest=874
SET @ID := 874;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te envía mi hermano, ¿no? Le habrás demostrado lo que vales. Si te has ganado el respeto de Jorn, también tienes el mío.$B$B¿Estás listo para profundizar en el camino del cazador?', 0),
(@ID, 'esMX', 'Te envía mi hermano, ¿no? Le habrás demostrado lo que vales. Si te has ganado el respeto de Jorn, también tienes el mío.$B$B¿Estás listo para profundizar en el camino del cazador?', 0);
