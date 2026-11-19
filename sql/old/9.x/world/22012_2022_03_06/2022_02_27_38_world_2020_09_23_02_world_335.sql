-- 3042 Temple trol
-- https://es.classic.wowhead.com/quest=3042
SET @ID := 3042;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has traído el temple, $n?', 0),
(@ID, 'esMX', '¿Has traído el temple, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, es un temple excelente! ¡Y hay mucho! ¡Podré trabajar muchos días antes de que se acabe!$B$BGracias, $n. Por favor, acepta esto como pago.', 0),
(@ID, 'esMX', '¡Ah, es un temple excelente! ¡Y hay mucho! ¡Podré trabajar muchos días antes de que se acabe!$B$BGracias, $n. Por favor, acepta esto como pago.', 0);
-- 992 Un estudio de agua de Gadgetzan
-- https://es.classic.wowhead.com/quest=992
SET @ID := 992;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡$gBienvenido:Bienvenida; de nuevo, $gperito:perita; adjunta $n! ¿Ya has terminado tu tarea?', 0),
(@ID, 'esMX', '¡$gBienvenido:Bienvenida; de nuevo, $gperito:perita; adjunta $n! ¿Ya has terminado tu tarea?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo? ¿Te han tendido una emboscada una especie de bichejos de mojo malo? Vaya, esto no augura nada bueno para la compañía de aguas de Gadgetzan...$B$BSupongo que tenía que haberte hablado de los peligrosos bichos que al parecer están consumiendo toda el agua del desierto. Al principio, le resté importancia pues ya tenemos bastantes problemas con los nómadas y creí que era una más de sus artimañas. Al menos ahora sabemos lo que está pasando.', 0),
(@ID, 'esMX', '¿Cómo? ¿Te han tendido una emboscada una especie de bichejos de mojo malo? Vaya, esto no augura nada bueno para la compañía de aguas de Gadgetzan...$B$BSupongo que tenía que haberte hablado de los peligrosos bichos que al parecer están consumiendo toda el agua del desierto. Al principio, le resté importancia pues ya tenemos bastantes problemas con los nómadas y creí que era una más de sus artimañas. Al menos ahora sabemos lo que está pasando.', 0);
-- 3022 Un envío frágil
-- https://es.classic.wowhead.com/quest=3022
SET @ID := 3022;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Otro envío de parte de Curgle, ¿verdad?', 0),
(@ID, 'esMX', 'Otro envío de parte de Curgle, ¿verdad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias por tu ayuda, $n. La población de hiprogrifos no crecería de no ser por nosotros. Pero seguro que eso ya lo sabes pues has estado en Feralas y has visto con tus propios ojos la devastación causada por los Gordunni.$B$BBien, como puedes observar, tengo mucho trabajo así que será mejor que te vayas.$B$BGracias de nuevo, $n.', 0),
(@ID, 'esMX', 'Gracias por tu ayuda, $n. La población de hiprogrifos no crecería de no ser por nosotros. Pero seguro que eso ya lo sabes pues has estado en Feralas y has visto con tus propios ojos la devastación causada por los Gordunni.$B$BBien, como puedes observar, tengo mucho trabajo así que será mejor que te vayas.$B$BGracias de nuevo, $n.', 0);
-- 2741 El Superhuevomático
-- https://es.classic.wowhead.com/quest=2741
SET @ID := 2741;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0),
(@ID, 'esMX', 'El Superhuevomático es uno de los últimos inventos de Curgle Saltamanivela. Se trata de una máquina impresionante.$B$BEl Superhuevomático chisporrotea cuando te acercas al panel de control.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0),
(@ID, 'esMX', 'Colocas el huevo de hipogrifo en la máquina. Se oyen una serie de pitidos y de ruidos mecánicos extraños.$B$BParece que el Superhuevomático ha pesado, medido y empaquetado el huevo. ¡Eso sí que es un servicio rápido!', 0);
-- 5863 La Base Machacaduna
-- https://es.classic.wowhead.com/quest=5863
SET @ID := 5863;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estoy tan preocupada! ¡Por favor ten cuidado!', 0),
(@ID, 'esMX', '¡Estoy tan preocupada! ¡Por favor ten cuidado!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me alegro de que hayas podido hacer esto por mí, $n! ¡Gracias por tu ayuda!', 0),
(@ID, 'esMX', '¡Me alegro de que hayas podido hacer esto por mí, $n! ¡Gracias por tu ayuda!', 0);
-- 1691 Más justicia para los Vagayermos
-- https://es.classic.wowhead.com/quest=1691
SET @ID := 1691;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¿pudiste eliminar a esos nómadas como te pedí? ¡La Compañia de Aguas de Gadgetzan está desarrollando planes basados en tu éxito aquí! No nos defraudes, ahora...', 0),
(@ID, 'esMX', 'Bueno, ¿pudiste eliminar a esos nómadas como te pedí? ¡La Compañia de Aguas de Gadgetzan está desarrollando planes basados en tu éxito aquí! No nos defraudes, ahora...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un trabajo de primera, $n... ¡de primera! ¡Has reducido la población de los nómadas hasta tal punto que ya podemos hacerles frente!$B$BSi todavía no lo has hecho, ve a hablar con el grifoperador Luglunket que está aquí. Él te dará una recompensa por cada una de las bolsas de agua de los Vagayermos que hayas encontrado mientras impartías justicia a esos nómadas.', 0),
(@ID, 'esMX', 'Un trabajo de primera, $n... ¡de primera! ¡Has reducido la población de los nómadas hasta tal punto que ya podemos hacerles frente!$B$BSi todavía no lo has hecho, ve a hablar con el grifoperador Luglunket que está aquí. Él te dará una recompensa por cada una de las bolsas de agua de los Vagayermos que hayas encontrado mientras impartías justicia a esos nómadas.', 0);
-- 1878 Cazador de faltriqueras de agua
-- https://es.classic.wowhead.com/quest=1878
SET @ID := 1878;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has vuelto, $n? Si tienes cinco bolsas más de agua te puedo dar ya mismo tu recompensa.', 0),
(@ID, 'esMX', '¿Ya has vuelto, $n? Si tienes cinco bolsas más de agua te puedo dar ya mismo tu recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0),
(@ID, 'esMX', 'Excelente, ¡cuantas más bolsas de agua consigamos, más nos alejaremos del desastre! Consigue tantas como puedas y te daré una recompensa por cada 5 bolsas de agua que me traigas.', 0);
-- 82 Investigación en la Guarida Ponzoñosa
-- https://es.classic.wowhead.com/quest=82
SET @ID := 82;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Eres $gel:la; perito $gadjunto:adjunta;, ¿no es cierto? ¡Rápido, estamos en una situación muy delicada! ¡¿Tienes los trozos de insecto que Picoflojo dijo que tendrías?!', 0),
(@ID, 'esMX', 'Eres $gel:la; perito $gadjunto:adjunta;, ¿no es cierto? ¡Rápido, estamos en una situación muy delicada! ¡¿Tienes los trozos de insecto que Picoflojo dijo que tendrías?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen trabajo, ¡empezaré ahora mismo con el análisis! A primera vista, puedo decirte que no se parecen a ningún tipo de insecto que haya visto antes. Parece que estos bichos están controlados por una fuerza externa o algo similar.$B$BDebes ir a hablar con Picoflojo inmediatamente. ¡Hay algo urgente para lo que necesita tu ayuda! No estoy seguro pero creo que tiene que ver con los bichos del Desierto de Tanaris.', 0),
(@ID, 'esMX', 'Buen trabajo, ¡empezaré ahora mismo con el análisis! A primera vista, puedo decirte que no se parecen a ningún tipo de insecto que haya visto antes. Parece que estos bichos están controlados por una fuerza externa o algo similar.$B$BDebes ir a hablar con Picoflojo inmediatamente. ¡Hay algo urgente para lo que necesita tu ayuda! No estoy seguro pero creo que tiene que ver con los bichos del Desierto de Tanaris.', 0);
-- 10 La redención de Patagolpe
-- https://es.classic.wowhead.com/quest=10
SET @ID := 10;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Y bien, ¿qué novedades traes? Parece que te hayan dado una paliza... ¿Patagolpe está vivo?', 0),
(@ID, 'esMX', 'Y bien, ¿qué novedades traes? Parece que te hayan dado una paliza... ¿Patagolpe está vivo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El joven Patagolpe era un buen goblin. Esperemos que, gracias a los datos registrados en su equipo de análisis, su muerte no haya sido en vano.$B$BParece que ahora el problema con estos bichos está en nuestras manos. Son demasiado astutos y las investigaciones realizadas hasta el momento señalan la posibilidad de que estén controlados por una tercera persona. Si eso es cierto, ¡no le espera nada bueno ni a Gadgetzan ni al desierto en general!', 0),
(@ID, 'esMX', 'El joven Patagolpe era un buen goblin. Esperemos que, gracias a los datos registrados en su equipo de análisis, su muerte no haya sido en vano.$B$BParece que ahora el problema con estos bichos está en nuestras manos. Son demasiado astutos y las investigaciones realizadas hasta el momento señalan la posibilidad de que estén controlados por una tercera persona. Si eso es cierto, ¡no le espera nada bueno ni a Gadgetzan ni al desierto en general!', 0);
-- 2606 Un buen sabor
-- https://es.classic.wowhead.com/quest=2606
SET @ID := 2606;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que Marin está otra vez en ello, ¿eh? ¿De qué está hecho este brebaje?', 0),
(@ID, 'esMX', 'Así que Marin está otra vez en ello, ¿eh? ¿De qué está hecho este brebaje?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Marin es un buen tipo pero un poco excéntrico, diría yo.$B$BEn cualquier caso, está claro que necesita mi ayuda una vez más.', 0),
(@ID, 'esMX', 'Marin es un buen tipo pero un poco excéntrico, diría yo.$B$BEn cualquier caso, está claro que necesita mi ayuda una vez más.', 0);
-- 2641 El ingrediente secreto de Roxio
-- https://es.classic.wowhead.com/quest=2641
SET @ID := 2641;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El único lugar en el que encontrarás tragano violeta es bajo las aguas de ese lago. ¡Espero que tengas buenos pulmones!', 0),
(@ID, 'esMX', 'El único lugar en el que encontrarás tragano violeta es bajo las aguas de ese lago. ¡Espero que tengas buenos pulmones!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es lo que quería, $n!$B$BTiene buena pinta, a ver... ¡Ajá! ¡Perfecto!', 0),
(@ID, 'esMX', '¡Eso es lo que quería, $n!$B$BTiene buena pinta, a ver... ¡Ajá! ¡Perfecto!', 0);
-- 11441 ¡Fiesta de la Cerveza!
-- https://es.classic.wowhead.com/quest=11441
SET @ID := 11441;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Jo jo! ¿Vienes por tu cerveza gratis?', 0),
(@ID, 'esMX', 'Jo jo! ¿Vienes por tu cerveza gratis?', 0);
-- 7261 El imperativo soberano
-- https://es.classic.wowhead.com/quest=7261
SET @ID := 7261;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡A trabajar!', 0),
(@ID, 'esMX', '¡A trabajar!', 0);
-- 3702 Las humeantes Ruinas de Thaurissan
-- https://es.classic.wowhead.com/quest=3702
SET @ID := 3702;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Permíteme terminar de contarte la historia de Thaurissan.', 0),
(@ID, 'esMX', 'Permíteme terminar de contarte la historia de Thaurissan.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Proseguimos?', 0),
(@ID, 'esMX', '¿Proseguimos?', 0);
-- 3701 Las humeantes Ruinas de Thaurissan
-- https://es.classic.wowhead.com/quest=3701
SET @ID := 3701;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes nueva información?', 0),
(@ID, 'esMX', '¿Traes nueva información?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto explica mucho sobre Thaurissan.$B$B¡Qué interesante!', 0),
(@ID, 'esMX', 'Esto explica mucho sobre Thaurissan.$B$B¡Qué interesante!', 0);
-- 12022 ¡Traga y tira!
-- https://es.classic.wowhead.com/quest=12022
SET @ID := 12022;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lanza uno hacia atrás, luego lanza uno hacia adelante. G.U.A.O. puede soportarlo, es por eso que lo construí.', 0),
(@ID, 'esMX', 'Lanza uno hacia atrás, luego lanza uno hacia adelante. G.U.A.O. puede soportarlo, es por eso que lo construí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Sabes qué fue eso? ¡Ingeniería gnómica en su máxima expresión! G.U.A.O. lo soportó como un campeón!$B$BCreo que ya estás $glisto:lista; para enfrentarte a los Hierro Negro si vuelven a aparecer.', 0),
(@ID, 'esMX', '¿Sabes qué fue eso? ¡Ingeniería gnómica en su máxima expresión! G.U.A.O. lo soportó como un campeón!$B$BCreo que ya estás $glisto:lista; para enfrentarte a los Hierro Negro si vuelven a aparecer.', 0);
-- 11118 Elekks rosas a la vista
-- https://es.classic.wowhead.com/quest=11118
SET @ID := 11118;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya se han ido esos molestos elekks rosas?', 0),
(@ID, 'esMX', '¿Ya se han ido esos molestos elekks rosas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Elekks rosas... ¡qué idea más absurda!', 0),
(@ID, 'esMX', '¡Buen trabajo! Elekks rosas... ¡qué idea más absurda!', 0);
-- 11117 ¡Atrapa al wolpertinger salvaje!
-- https://es.classic.wowhead.com/quest=11117
SET @ID := 11117;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estabas lo suficientemente $gborracho:borracha; como para ver a los pequeños cabroncetes?', 0),
(@ID, 'esMX', '¿Estabas lo suficientemente $gborracho:borracha; como para ver a los pequeños cabroncetes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, ¡mira ahí! ¡Tienes un montón de wolpertingers, sí!$B$B<Toma un buen trago de su jarra.>$B$BTe diré lo que voy a hacer. Ya que eres $gun:una; $c tan acertado, ¡dejaré que te quedes con uno de estos para ti!', 0),
(@ID, 'esMX', 'Bueno, ¡mira ahí! ¡Tienes un montón de wolpertingers, sí!$B$B<Toma un buen trago de su jarra.>$B$BTe diré lo que voy a hacer. Ya que eres $gun:una; $c tan acertado, ¡dejaré que te quedes con uno de estos para ti!', 0);
-- 11318 Carrera de carneros... o algo parecido
-- https://es.classic.wowhead.com/quest=11318
SET @ID := 11318;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudiste manejar la velocidad?', 0),
(@ID, 'esMX', '¿Pudiste manejar la velocidad?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Se necesita tiempo para dominar el control de tu Carnero. Pero una vez que lo hagas, desearás que cada ariete sea un ariete de carreras.$B$B¿Que es eso? "¿Dónde está mi recompensa?" Ja, ja, ja... ¡tienes que montar el carnero más rápido! ¿Quieres más? Bueno, ¿qué tal esto...$B$BHa sido recompensado con la oportunidad de ayudar a otras personas en la Fiesta de la Cerveza. Hay mucho trabajo y recompensas para un corredor joven y entusiasta.', 0),
(@ID, 'esMX', '¡Buen trabajo! Se necesita tiempo para dominar el control de tu Carnero. Pero una vez que lo hagas, desearás que cada ariete sea un ariete de carreras.$B$B¿Que es eso? "¿Dónde está mi recompensa?" Ja, ja, ja... ¡tienes que montar el carnero más rápido! ¿Quieres más? Bueno, ¿qué tal esto...$B$BHa sido recompensado con la oportunidad de ayudar a otras personas en la Fiesta de la Cerveza. Hay mucho trabajo y recompensas para un corredor joven y entusiasta.', 0);
-- 11122 Historia de una ida y una vuelta
-- https://es.classic.wowhead.com/quest=11122
SET @ID := 11122;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Necesito esos barriles! ¿¡qué estás esperando!?!', 0),
(@ID, 'esMX', '¡Necesito esos barriles! ¿¡qué estás esperando!?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muchas gracias por tu ayuda! Mientras dure la Fiesta de la Cerveza y los Enanos Hierro Negro estén atacando, necesitaré ayuda para enviar barriles. Si quieres trabajar para obtener más fichas, habla conmigo todos los días.$B$BPero basta de eso, voy pagarte por el trabajo que acabas de hacer. Aquí tienes tus fichas, ¡diviértete en la Fiesta de la Cerveza!', 0),
(@ID, 'esMX', '¡Muchas gracias por tu ayuda! Mientras dure la Fiesta de la Cerveza y los Enanos Hierro Negro estén atacando, necesitaré ayuda para enviar barriles. Si quieres trabajar para obtener más fichas, habla conmigo todos los días.$B$BPero basta de eso, voy pagarte por el trabajo que acabas de hacer. Aquí tienes tus fichas, ¡diviértete en la Fiesta de la Cerveza!', 0);
