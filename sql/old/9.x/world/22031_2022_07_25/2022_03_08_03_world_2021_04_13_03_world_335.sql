-- 8778 ¡La Brigada de Forjaz necesita explosivos!
-- https://es.classic.wowhead.com/quest=8778
SET @ID := 8778;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que decirme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que decirme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, sí! ¡Estos serán útiles! ¡Muchas gracias, $n!', 0),
(@ID, 'esMX', '¡Ah, sí! ¡Estos serán útiles! ¡Muchas gracias, $n!', 0);
-- Materiales de visión
-- 8779, 8807
-- https://es.classic.wowhead.com/quest=8779
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8779, 8807) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8779, 'esES', '¿Tienes algo para mí, $n?', 0),
(8807, 'esES', '¿Tienes algo para mí, $n?', 0),
(8779, 'esMX', '¿Tienes algo para mí, $n?', 0),
(8807, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8779, 8807) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8779, 'esES', 'Pues sí... ¡serán de gran ayuda! Estos materiales son muy difíciles de conseguir en el desierto, $n. Gracias.', 0),
(8807, 'esES', 'Pues sí... ¡serán de gran ayuda! Estos materiales son muy difíciles de conseguir en el desierto, $n. Gracias.', 0),
(8779, 'esMX', 'Pues sí... ¡serán de gran ayuda! Estos materiales son muy difíciles de conseguir en el desierto, $n. Gracias.', 0),
(8807, 'esMX', 'Pues sí... ¡serán de gran ayuda! Estos materiales son muy difíciles de conseguir en el desierto, $n. Gracias.', 0);
-- 8780 Refuerzos para armadura para el campo de batalla
-- https://es.classic.wowhead.com/quest=8780
SET @ID := 8780;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $n?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, se las daré a los muchachos.', 0),
(@ID, 'esMX', 'Gracias, se las daré a los muchachos.', 0);
-- 8781 Armas para el campo de batalla
-- https://es.classic.wowhead.com/quest=8781
SET @ID := 8781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $n?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, excelente! Ya no tendré que escuchar quejas sobre cuchillas desafiladas. Gracias, $n.', 0),
(@ID, 'esMX', '¡Oh, excelente! Ya no tendré que escuchar quejas sobre cuchillas desafiladas. Gracias, $n.', 0);
-- 8782 Suministros para uniformes
-- https://es.classic.wowhead.com/quest=8782
SET @ID := 8782;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $n?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, los necesitábamos. Se agradece tu trabajo, $n.', 0),
(@ID, 'esMX', 'Ah, los necesitábamos. Se agradece tu trabajo, $n.', 0);
-- Materiales encantados
-- 8783, 8809
-- https://es.classic.wowhead.com/quest=8783
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8783, 8809) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8783, 'esES', '¿Tienes algo para mí, $n?', 0),
(8809, 'esES', '¿Tienes algo para mí, $n?', 0),
(8783, 'esMX', '¿Tienes algo para mí, $n?', 0),
(8809, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8783, 8809) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8783, 'esES', 'Ah, sí. Estos materiales son de excelente calidad. Gracias, $n.', 0),
(8809, 'esES', 'Ah, sí. Estos materiales son de excelente calidad. Gracias, $n.', 0),
(8783, 'esMX', 'Ah, sí. Estos materiales son de excelente calidad. Gracias, $n.', 0),
(8809, 'esMX', 'Ah, sí. Estos materiales son de excelente calidad. Gracias, $n.', 0);
-- 8784 Los secretos de los qiraji
-- https://es.classic.wowhead.com/quest=8784
SET @ID := 8784;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estás brillante! Sé lo que eso significa...', 0),
(@ID, 'esMX', '¡Estás brillante! Sé lo que eso significa...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un hallazgo extraordinario, $n. ¡Sencillamente maravilloso! Con esto seguro que lograremos penetrar en las perversas mentes de nuestro enemigo.', 0),
(@ID, 'esMX', 'Un hallazgo extraordinario, $n. ¡Sencillamente maravilloso! Con esto seguro que lograremos penetrar en las perversas mentes de nuestro enemigo.', 0);
-- 8785 ¡La Legión de Orgrimmar necesita mojo!
-- https://es.classic.wowhead.com/quest=8785
SET @ID := 8785;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mis materiales, $n?', 0),
(@ID, 'esMX', '¿Tienes mis materiales, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí. ¡Justo lo que necesitaba! Haré un brebaje especial con esto. ¡Al silítido no le gustará nada!', 0),
(@ID, 'esMX', 'Ah, sí. ¡Justo lo que necesitaba! Haré un brebaje especial con esto. ¡Al silítido no le gustará nada!', 0);
-- 8786 Armas para el campo de batalla
-- https://es.classic.wowhead.com/quest=8786
SET @ID := 8786;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $n?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente trabajo. Estábamos escasos de esto, $n.', 0),
(@ID, 'esMX', 'Excelente trabajo. Estábamos escasos de esto, $n.', 0);
-- 8787 Refuerzos para armadura para el campo de batalla
-- https://es.classic.wowhead.com/quest=8787
SET @ID := 8787;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $n?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, sí... se los distribuiré a las tropas, $n. ¡La Legión de Orgrimmar te lo agradece!', 0),
(@ID, 'esMX', 'Ah, sí... se los distribuiré a las tropas, $n. ¡La Legión de Orgrimmar te lo agradece!', 0);
-- 8789 Armamentos imperiales qiraji
-- https://es.classic.wowhead.com/quest=8789
SET @ID := 8789;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Busca lo que te he pedido. Te convertirás en algo más grande que la suma de tus partes, $gcampeón:campeona;.', 0),
(@ID, 'esMX', 'Busca lo que te he pedido. Te convertirás en algo más grande que la suma de tus partes, $gcampeón:campeona;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Imbuidas de elementium, estas armas atravesarán a los qiraji y a su dios con increíble facilidad.', 0),
(@ID, 'esMX', 'Imbuidas de elementium, estas armas atravesarán a los qiraji y a su dios con increíble facilidad.', 0);
-- 8790 Atavío imperial qiraji
-- https://es.classic.wowhead.com/quest=8790
SET @ID := 8790;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los abatirás y nos liberarás de estas cadenas.', 0),
(@ID, 'esMX', 'Los abatirás y nos liberarás de estas cadenas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Usa bien el objeto, $n. Haz que sientan el dolor que tanto les gusta infligir a los demás.', 0),
(@ID, 'esMX', 'Usa bien el objeto, $n. Haz que sientan el dolor que tanto les gusta infligir a los demás.', 0);
-- 8791 La caída de Osirio
-- https://es.classic.wowhead.com/quest=8791
SET @ID := 8791;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, ¡has regresado! Y $genterito:enterita;, si se me permite añadir. ¿Qué nuevas traes de Ahn\'Qiraj?', 0),
(@ID, 'esMX', 'Ah, $n, ¡has regresado! Y $genterito:enterita;, si se me permite añadir. ¿Qué nuevas traes de Ahn\'Qiraj?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recibe mis más elevados elogios y el objeto de poder que prefieras, $n. Le has prestado un gran servicio al pueblo de Kalimdor.', 0),
(@ID, 'esMX', 'Recibe mis más elevados elogios y el objeto de poder que prefieras, $n. Le has prestado un gran servicio al pueblo de Kalimdor.', 0);
-- ¡La Horda te necesita!
-- 8792, 8793, 8794, 10500
-- https://es.classic.wowhead.com/quest=8792
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8792, 8793, 8794, 10500) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8792, 'esES', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0),
(8793, 'esES', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0),
(8794, 'esES', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0),
(10500, 'esES', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0),
(8792, 'esMX', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0),
(8793, 'esMX', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0),
(8794, 'esMX', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0),
(10500, 'esMX', '¡Throm\'ka, $c! Es bueno ver a tantos miembros de la Horda, como tú, $n, salir a prestar tu apoyo para sentar las bases de la próxima Guerra de Ahn\'Qiraj. El esfuerzo aquí garantizará la victoria contra los silítidos y sus malvados amos escondidos dentro de Ahn\'Qiraj.$B$BAhora que estás aquí, asegúrese de hablar con los diversos recolectores y ofrecer tu ayuda para reunir los materiales que necesitan.', 0);
-- 8798 Un yeti propio
-- https://es.classic.wowhead.com/quest=8798
SET @ID := 8798;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya! ¡¿Sabes qué?! ¡Tú también eres $gingeniero:ingeniera;! Como me ayudaste a darles una lección a mis amigos, ¡voy a enseñarte a hacer tu propio yeti mecánico! ¡Ahora la diversión no va a parar nunca y podrás asustar a quien quieras! Siempre que puedas conseguir los componentes, claro.$B$B¿Qué dices, $n? ¿Quieres aprender los secretos para hacer un yeti mecánico?', 0),
(@ID, 'esMX', '¡Vaya! ¡¿Sabes qué?! ¡Tú también eres $gingeniero:ingeniera;! Como me ayudaste a darles una lección a mis amigos, ¡voy a enseñarte a hacer tu propio yeti mecánico! ¡Ahora la diversión no va a parar nunca y podrás asustar a quien quieras! Siempre que puedas conseguir los componentes, claro.$B$B¿Qué dices, $n? ¿Quieres aprender los secretos para hacer un yeti mecánico?', 0);
-- 8800 Equipamiento de Cenarius
-- https://es.classic.wowhead.com/quest=8800
SET @ID := 8800;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Kaldon te ha enviado? Muy bien, veamos lo que podemos hacer por ti.', 0),
(@ID, 'esMX', '¿Kaldon te ha enviado? Muy bien, veamos lo que podemos hacer por ti.', 0);
-- 8801 El legado de C'Thun
-- https://es.classic.wowhead.com/quest=8801
SET @ID := 8801;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Caelastrasz se arrodilla ante ti.>$B$B$gSeñor:Señona; $n, nos has liberado de sus garras.', 0),
(@ID, 'esMX', '<Caelastrasz se arrodilla ante ti.>$B$B$gSeñor:Señona; $n, nos has liberado de sus garras.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Abandonaremos este lugar, $gseñor:señora; $n, cuando estemos seguros de que el mal que lo impregna ha quedado completamente destruido. Tu viaje de leyenda casi toca a su fin.', 0),
(@ID, 'esMX', 'Abandonaremos este lugar, $gseñor:señora; $n, cuando estemos seguros de que el mal que lo impregna ha quedado completamente destruido. Tu viaje de leyenda casi toca a su fin.', 0);
-- 8802 La salvación de Kalimdor
-- https://es.classic.wowhead.com/quest=8802
SET @ID := 8802;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$gSeñor:Señora; $n! Se acabó...', 0),
(@ID, 'esMX', '¡$gSeñor:Señora; $n! Se acabó...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Maestro ha dejado esto para ti, $gCampeón:Campeona;. Desde el alijo intemporal: una colección de artefactos de diferentes épocas; tú eliges.', 0),
(@ID, 'esMX', 'El Maestro ha dejado esto para ti, $gCampeón:Campeona;. Desde el alijo intemporal: una colección de artefactos de diferentes épocas; tú eliges.', 0);
-- 8803 Un obsequio festivo
-- https://es.wowhead.com/quest=8803
SET @ID := 8803;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La nota de este regalo dice:$B$BPara $n:$B$Bcon la esperanza de que te ayude a repartir calor y felicidad por todo Azeroth.$B$BDe parte del Gran Padre Invierno.', 0),
(@ID, 'esMX', 'La nota de este regalo dice:$B$BPara $n:$B$Bcon la esperanza de que te ayude a repartir calor y felicidad por todo Azeroth.$B$BDe parte del Gran Padre Invierno.', 0);
-- Material de supervivencia en el desierto
-- 8804, 8805, 8806
-- https://es.classic.wowhead.com/quest=8804
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8804, 8805, 8806) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8804, 'esES', '¿Tienes algo para mí, $n?', 0),
(8805, 'esES', '¿Tienes algo para mí, $n?', 0),
(8806, 'esES', '¿Tienes algo para mí, $n?', 0),
(8804, 'esMX', '¿Tienes algo para mí, $n?', 0),
(8805, 'esMX', '¿Tienes algo para mí, $n?', 0),
(8806, 'esMX', '¿Tienes algo para mí, $n?', 0);
-- 8808 Suministros para uniformes
-- https://es.classic.wowhead.com/quest=8808
SET @ID := 8808;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo para mí, $n?', 0),
(@ID, 'esMX', '¿Tienes algo para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, las necesitábamos. Se agradece tu trabajo, $n.', 0),
(@ID, 'esMX', 'Ah, las necesitábamos. Se agradece tu trabajo, $n.', 0);
-- 8811 Un sello de honor
-- https://es.classic.wowhead.com/quest=8811
SET @ID := 8811;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Ventormenta.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Ventormenta.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8812 Un sello de honor
-- https://es.classic.wowhead.com/quest=8812
SET @ID := 8812;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Forjaz.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Forjaz.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8813 Un sello de honor
-- https://es.classic.wowhead.com/quest=8813
SET @ID := 8813;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Darnassus.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Darnassus.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8814 Un sello de honor
-- https://es.classic.wowhead.com/quest=8814
SET @ID := 8814;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con los Exiliados de Gnomeregan.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con los Exiliados de Gnomeregan.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8815 Un sello de honor
-- https://es.classic.wowhead.com/quest=8815
SET @ID := 8815;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Orgrimmar.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Orgrimmar.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8816 Un sello de honor
-- https://es.classic.wowhead.com/quest=8816
SET @ID := 8816;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Entrañas.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Entrañas.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8817 Un sello de honor
-- https://es.classic.wowhead.com/quest=8817
SET @ID := 8817;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Cima del Trueno.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con Cima del Trueno.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8818 Un sello de honor
-- https://es.classic.wowhead.com/quest=8818
SET @ID := 8818;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con la tribu Lanza Negra.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0),
(@ID, 'esMX', 'Si los aventureros solo tienen un sello de honor, se les entrega a cambio una pequeña cantidad de reputación con la tribu Lanza Negra.$B$BPor favor, no olvides que es mejor entregarme diez sellos al mismo tiempo, tus esfuerzos se verán mejor recompensados. Permitimos el intercambio de un solo sello como servicio para aquellos que no pueden completar un juego de diez.$B$BDicho esto, ya puedo ayudarte si sigues queriendo entregar un solo sello.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0),
(@ID, 'esMX', 'Muy bien, tus hazañas han sido registradas y tus esfuerzos han sido debidamente reconocidos. Sigue haciéndolo así, $c.$B$BSi tienes más sellos que entregar puedo seguir ayudándote.', 0);
-- 8819 Diez sellos de honor
-- https://es.classic.wowhead.com/quest=8819
SET @ID := 8819;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas en Ventormenta. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0),
(@ID, 'esMX', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas en Ventormenta. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0),
(@ID, 'esMX', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0);
-- 8820 Diez sellos de honor
-- https://es.classic.wowhead.com/quest=8820
SET @ID := 8820;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas en Forjaz. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0),
(@ID, 'esMX', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas en Forjaz. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0),
(@ID, 'esMX', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0);
-- 8821 Diez sellos de honor
-- https://es.classic.wowhead.com/quest=8821
SET @ID := 8821;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas en Darnassus. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0),
(@ID, 'esMX', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas en Darnassus. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0),
(@ID, 'esMX', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0);
-- 8822 Diez sellos de honor
-- https://es.classic.wowhead.com/quest=8822
SET @ID := 8822;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas entre los Exiliados de Gnomeregan. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0),
(@ID, 'esMX', 'Acepto sellos de honor de los aventureros que los han conseguido cumpliendo con su deber. Por cada diez que me entregues me aseguraré de que tus hazañas sean reconocidas y admiradas entre los Exiliados de Gnomeregan. También acepto sellos de uno en uno, pero a cambio de un nivel mucho menor de reputación. Estamos mucho más interesados en las hazañas ligadas a un compromiso duradero... pero ningún acto queda ignorado.$B$BDicho esto, me encantaría tener tus sellos si estás $glisto:lista; para entregar un paquete.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0),
(@ID, 'esMX', '¡Excelente! El esfuerzo que has hecho para ganar estos sellos no es pequeño, y tus servicios serán debidamente reconocidos. Son $glos aventureros:las aventureras; como tú, $n, $glos:las; que marcan la diferencia..$B$BHazme saber si tienes más sellos que entregar. Será un placer ayudarte siempre que necesites hacer un intercambio.', 0);
