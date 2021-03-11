-- 7655 Brazales de placas imperiales
-- https://es.classic.wowhead.com/quest=7655
SET @ID := 7655;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para los planos de los brazaletes, necesitaré 10 barras de torio.$B$B¿Estás bien, $ghijo:hija;? Te estás poniendo $gtodo rojo:toda roja;.', 0),
(@ID, 'esMX', 'Para los planos de los brazaletes, necesitaré 10 barras de torio.$B$B¿Estás bien, $ghijo:hija;? Te estás poniendo $gtodo rojo:toda roja;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0),
(@ID, 'esMX', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0);
-- 7656 Peto de placas imperiales
-- https://es.classic.wowhead.com/quest=7656
SET @ID := 7656;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para los planos del peto, necesitaré 30 barras de torio.$B$BOh $gchico:chica;, ahí lo tienes de nuevo. ¿Vas a correr hacia tus dioses azules, preguntándote por qué te han abandonado? ¡Ponte fuerte, Nancy! Nadie dijo nunca que la vida es justa.', 0),
(@ID, 'esMX', 'Para los planos del peto, necesitaré 30 barras de torio.$B$BOh $gchico:chica;, ahí lo tienes de nuevo. ¿Vas a correr hacia tus dioses azules, preguntándote por qué te han abandonado? ¡Ponte fuerte, Nancy! Nadie dijo nunca que la vida es justa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0),
(@ID, 'esMX', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0);
-- 7657 Yelmo de placas imperiales
-- https://es.classic.wowhead.com/quest=7657
SET @ID := 7657;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo entrega 25 barras de torio y los planos del yelmo son tuyos.', 0),
(@ID, 'esMX', 'Solo entrega 25 barras de torio y los planos del yelmo son tuyos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0),
(@ID, 'esMX', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0);
-- 7658 Leotardos de placas imperiales
-- https://es.classic.wowhead.com/quest=7658
SET @ID := 7658;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo entrega 30 barras de torio y los planos de los leotrados son tuyos.$B$B¡Lo sé, te estoy llevando a la bancarrota! Lo he escuchado todo antes, así que guarda triste historia, $gdebilucho:debilucha;.', 0),
(@ID, 'esMX', 'Solo entrega 30 barras de torio y los planos de los leotrados son tuyos.$B$B¡Lo sé, te estoy llevando a la bancarrota! Lo he escuchado todo antes, así que guarda triste historia, $gdebilucho:debilucha;.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0),
(@ID, 'esMX', 'Es un placer hacer negocios contigo.$B$BY $n, borra esa expresión de disgusto de tu rostro.', 0);
-- 7659 Sobrehombros de placas imperiales
-- https://es.classic.wowhead.com/quest=7659
SET @ID := 7659;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para los sobrehombros, necesitaré 10 barras de torio.', 0),
(@ID, 'esMX', 'Para los sobrehombros, necesitaré 10 barras de torio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A pleasure doin\' business with ya.$B$BAnd $n, wipe that look of disgust off yer face.', 0),
(@ID, 'esMX', 'A pleasure doin\' business with ya.$B$BAnd $n, wipe that look of disgust off yer face.', 0);
-- Intercambio de lobos: lobo ártico
-- 7660, 7661
-- https://es.classic.wowhead.com/quest=7660
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7660, 7661) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7660, 'esES', 'Si me traes tu viejo lobo veloz, lo cambiaré por uno de la nueva manada. El nuevo lobo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los lobos veloces que ya tenemos alrededor del patio para ver cómo se verá.', 0),
(7661, 'esES', 'Si me traes tu viejo lobo veloz, lo cambiaré por uno de la nueva manada. El nuevo lobo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los lobos veloces que ya tenemos alrededor del patio para ver cómo se verá.', 0),
(7660, 'esMX', 'Si me traes tu viejo lobo veloz, lo cambiaré por uno de la nueva manada. El nuevo lobo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los lobos veloces que ya tenemos alrededor del patio para ver cómo se verá.', 0),
(7661, 'esMX', 'Si me traes tu viejo lobo veloz, lo cambiaré por uno de la nueva manada. El nuevo lobo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los lobos veloces que ya tenemos alrededor del patio para ver cómo se verá.', 0);
-- Nuevo kodo: cerceta
-- 7662, 7663
-- https://es.classic.wowhead.com/quest=7662
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7662, 7663) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7662, 'esES', 'Si me traes tu viejo kodo, lo cambiaré por uno del nuevo rebaño. El nuevo kodo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los fantásticos kodos que ya tenemos en el patio para ver entre lo que podrás elegir.', 0),
(7663, 'esES', 'Si me traes tu viejo kodo, lo cambiaré por uno del nuevo rebaño. El nuevo kodo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los fantásticos kodos que ya tenemos en el patio para ver entre lo que podrás elegir.', 0),
(7662, 'esMX', 'Si me traes tu viejo kodo, lo cambiaré por uno del nuevo rebaño. El nuevo kodo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los fantásticos kodos que ya tenemos en el patio para ver entre lo que podrás elegir.', 0),
(7663, 'esMX', 'Si me traes tu viejo kodo, lo cambiaré por uno del nuevo rebaño. El nuevo kodo será tan rápido como el anterior, pero tendrá un aspecto diferente. Puedes mirar los fantásticos kodos que ya tenemos en el patio para ver entre lo que podrás elegir.', 0);
-- Sustitución de raptor marfil
-- 7664, 7665
-- https://es.classic.wowhead.com/quest=7664
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7664, 7665) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7664, 'esES', '¡Tráeme tu viejo raptor, te doy uno nuevo con garras recién afiladas! El nuevo raptor será tan rápido como el anterior, pero con una nueva apariencia. Puedes mirar los raptores aquí y ver lo que podrás elegir.', 0),
(7665, 'esES', '¡Tráeme tu viejo raptor, te doy uno nuevo con garras recién afiladas! El nuevo raptor será tan rápido como el anterior, pero con una nueva apariencia. Puedes mirar los raptores aquí y ver lo que podrás elegir.', 0),
(7664, 'esMX', '¡Tráeme tu viejo raptor, te doy uno nuevo con garras recién afiladas! El nuevo raptor será tan rápido como el anterior, pero con una nueva apariencia. Puedes mirar los raptores aquí y ver lo que podrás elegir.', 0),
(7665, 'esMX', '¡Tráeme tu viejo raptor, te doy uno nuevo con garras recién afiladas! El nuevo raptor será tan rápido como el anterior, pero con una nueva apariencia. Puedes mirar los raptores aquí y ver lo que podrás elegir.', 0);
-- 7666 El regreso a El Gran Osario
-- https://es.classic.wowhead.com/quest=7666
SET @ID := 7666;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vas de regreso a Scholomance, $n? Ya has pagado un alto precio por el Adivinador Arúspice; tal vez te gustaría llevarte otro. Con él, podrás enfrentarte a los peligros del Gran Osario una vez más.$B$BPor supuesto, tenlo. Ciertamente te lo has ganado.', 0),
(@ID, 'esMX', '¿Vas de regreso a Scholomance, $n? Ya has pagado un alto precio por el Adivinador Arúspice; tal vez te gustaría llevarte otro. Con él, podrás enfrentarte a los peligros del Gran Osario una vez más.$B$BPor supuesto, tenlo. Ciertamente te lo has ganado.', 0);
-- 7667 Asistencia material
-- https://es.classic.wowhead.com/quest=7667
SET @ID := 7667;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me siento incómodo al pedir ayuda material, pero mi adivinador, el dispositivo que espero terminar, requiere uno de cada uno. Si no puedes ayudarme, ciertamente lo entenderé.', 0),
(@ID, 'esMX', 'Me siento incómodo al pedir ayuda material, pero mi adivinador, el dispositivo que espero terminar, requiere uno de cada uno. Si no puedes ayudarme, ciertamente lo entenderé.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tu generosidad no tiene rival, $n. Te agradezco tu amabilidad.$B$BAhora podré terminar mi adivinador, y debería ser capaz de hacer más sin necesidad de diamantes... ¿tal vez te interesaría ayudarme en su uso? Es para una tarea muy importante, te lo aseguro... ¡uno que no se controle podría significar un desastre absoluto para el reino de los espíritus!', 0),
(@ID, 'esMX', 'Tu generosidad no tiene rival, $n. Te agradezco tu amabilidad.$B$BAhora podré terminar mi adivinador, y debería ser capaz de hacer más sin necesidad de diamantes... ¿tal vez te interesaría ayudarme en su uso? Es para una tarea muy importante, te lo aseguro... ¡uno que no se controle podría significar un desastre absoluto para el reino de los espíritus!', 0);
-- 7701 SE BUSCA: Sobrestante Maltorius
-- https://es.classic.wowhead.com/quest=7701
SET @ID := 7701;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿No vesh que eshtoy ocupado? Hip. ¿Qué quieresh? Hip.', 0),
(@ID, 'esMX', '¿No vesh que eshtoy ocupado? Hip. ¿Qué quieresh? Hip.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué cosha más fea!$B$BPues shabes, está mejor así, sin el cuelpo.$B$BToma la recompensa, ¡hip!, $r.', 0),
(@ID, 'esMX', '¡Qué cosha más fea!$B$BPues shabes, está mejor así, sin el cuelpo.$B$BToma la recompensa, ¡hip!, $r.', 0);
-- 7702 ¡Mátalos de sueño!
-- https://es.classic.wowhead.com/quest=7702
SET @ID := 7702;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No dejes que las locas gafas te engañen, $n. Yo soy el listo aquí.', 0),
(@ID, 'esMX', 'No dejes que las locas gafas te engañen, $n. Yo soy el listo aquí.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maravilloso! Esos Hierro Negro somnolientos regresarán a sus hogares en las Profundidades para descansar un poco, lo que ralentizará en gran medida la productividad del Pozo de escoria.', 0),
(@ID, 'esMX', '¡Maravilloso! Esos Hierro Negro somnolientos regresarán a sus hogares en las Profundidades para descansar un poco, lo que ralentizará en gran medida la productividad del Pozo de escoria.', 0);
-- 7703 Asunto Gordok sin finiquitar
-- https://es.classic.wowhead.com/quest=7703
SET @ID := 7703;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ja, ¿no lo encuentras, jefe? Tal vez vieja historia ser mala historia... ¡Difícil creer que ese elfo asqueroso pueda robarle al rey Gordok!', 0),
(@ID, 'esMX', 'Ja, ¿no lo encuentras, jefe? Tal vez vieja historia ser mala historia... ¡Difícil creer que ese elfo asqueroso pueda robarle al rey Gordok!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya... ¡ERES un verdadero $grey:reina;! ¡Nunca pensé ver este guante en mi vida! Parece que ya no le queda nada de mojo... tal vez ese elfo asqueroso arruinar el guante. Bueno, le digo ¡HAR HAR!$B$BMira, esta marca en guante es vieja marca Mágica, más vieja que Da Gordok, dicen. Bueno, como Capitán de da Gordok, todos aprender una cosa una y otra vez: ¡hacer que la marca cobre vida y devolver el poder al guantelete!$B$B¡Lo hago por ti, $grey:reina;! ¡Aquí, toma el guante y gobierna PARA SIEMPRE!', 0),
(@ID, 'esMX', 'Vaya... ¡ERES un verdadero $grey:reina;! ¡Nunca pensé ver este guante en mi vida! Parece que ya no le queda nada de mojo... tal vez ese elfo asqueroso arruinar el guante. Bueno, le digo ¡HAR HAR!$B$BMira, esta marca en guante es vieja marca Mágica, más vieja que Da Gordok, dicen. Bueno, como Capitán de da Gordok, todos aprender una cosa una y otra vez: ¡hacer que la marca cobre vida y devolver el poder al guantelete!$B$B¡Lo hago por ti, $grey:reina;! ¡Aquí, toma el guante y gobierna PARA SIEMPRE!', 0);
-- 7721 Combustible para el Ultra-reductor
-- https://es.classic.wowhead.com/quest=7721
SET @ID := 7721;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Podría aburrirte con los detalles técnicos o la utilidad de los núcleos de elementales, pero en lugar de eso, te tentaré para que completes esta importante tarea ofreciéndote una valiosa recompensa. ¿De verdad has acabado?', 0),
(@ID, 'esMX', 'Podría aburrirte con los detalles técnicos o la utilidad de los núcleos de elementales, pero en lugar de eso, te tentaré para que completes esta importante tarea ofreciéndote una valiosa recompensa. ¿De verdad has acabado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Fantastiquísimo! Estos núcleos me darán trabajo un buen tiempo. Y si añadimos a eso el hecho de que ya hay menos elementales en la costa, ¡creo que no volveré a tener esa pesadilla en la que me veo obligado a montar mi negocio en el peor sitio que se pueda imaginar!$B$BGracias por tus esfuerzos, $n. Aunque me repatea financieramente, quiero mostrarte mi agradecimiento con algo que seguramente apreciarás: ¡pasta!', 0),
(@ID, 'esMX', '¡Fantastiquísimo! Estos núcleos me darán trabajo un buen tiempo. Y si añadimos a eso el hecho de que ya hay menos elementales en la costa, ¡creo que no volveré a tener esa pesadilla en la que me veo obligado a montar mi negocio en el peor sitio que se pueda imaginar!$B$BGracias por tus esfuerzos, $n. Aunque me repatea financieramente, quiero mostrarte mi agradecimiento con algo que seguramente apreciarás: ¡pasta!', 0);
-- 7722 ¿Qué pasa con el flujo?
-- https://es.classic.wowhead.com/quest=7722
SET @ID := 7722;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste la receta?', 0),
(@ID, 'esMX', '¿Encontraste la receta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que le partieras los dientes, $n. Se lo merecía.$B$BY ahora, a lo nuestro.', 0),
(@ID, 'esMX', 'Espero que le partieras los dientes, $n. Se lo merecía.$B$BY ahora, a lo nuestro.', 0);
-- 7723 ¡Malditos dedos gordos!
-- https://es.classic.wowhead.com/quest=7723
SET @ID := 7723;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Les has zurrado?', 0),
(@ID, 'esMX', '¿Les has zurrado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has trabajado muy bien. Mira, te has ganado un regalito.', 0),
(@ID, 'esMX', 'Has trabajado muy bien. Mira, te has ganado un regalito.', 0);
-- 7724 Amenaza abrasadora
-- https://es.classic.wowhead.com/quest=7724
SET @ID := 7724;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Estaba él en lo cierto? ¿Les sale de las nalgas?', 0),
(@ID, 'esMX', '¿Estaba él en lo cierto? ¿Les sale de las nalgas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Hansel estornuda.>$B$BMe estoy resfriando. ¡Odio este clima!', 0),
(@ID, 'esMX', '<Hansel estornuda.>$B$BMe estoy resfriando. ¡Odio este clima!', 0);
-- 7725 Encoge más gigantes
-- https://es.classic.wowhead.com/quest=7725
SET @ID := 7725;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, los frutos de tanta investigación y prueba recogidos en un dulce residuo. Bueno, lo de dulce es una forma de hablar, no suelo probar las cosas con las que trabajo.$B$BNo siempre.', 0),
(@ID, 'esMX', 'Ah, los frutos de tanta investigación y prueba recogidos en un dulce residuo. Bueno, lo de dulce es una forma de hablar, no suelo probar las cosas con las que trabajo.$B$BNo siempre.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Inconcebiblemente fantástico, $n! Me has sido de gran ayuda, una vez más. Te lo agradezco mucho.$B$BGracias.$B$BPuede que esta recompensa te parezca un poco menos de lo que te mereces, pero debes saber que tus hazañas en el campo de la goblinización resonarán en todas las salas del Cártel Bonvapor. Si quieres hacer alguna cosa más, ¡habla conmigo!', 0),
(@ID, 'esMX', '¡Inconcebiblemente fantástico, $n! Me has sido de gran ayuda, una vez más. Te lo agradezco mucho.$B$BGracias.$B$BPuede que esta recompensa te parezca un poco menos de lo que te mereces, pero debes saber que tus hazañas en el campo de la goblinización resonarán en todas las salas del Cártel Bonvapor. Si quieres hacer alguna cosa más, ¡habla conmigo!', 0);
-- 7726 Más combustible para el Ultra-reductor
-- https://es.classic.wowhead.com/quest=7726
SET @ID := 7726;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido encontrar los núcleos de elementales que necesito?', 0),
(@ID, 'esMX', '¿Has conseguido encontrar los núcleos de elementales que necesito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡De primera, $n, de primera! Aunque la modesta recompensa que te puedo ofrecer no te pagará este trabajo, debes saber que mis camaradas del Cártel Bonvapor oirán hablar de tu hazaña.$B$BY si estás buscando algo más que hacer, házmelo saber, te lo ruego. Porque siempre estoy buscando núcleos elementales y esas cosas.', 0),
(@ID, 'esMX', '¡De primera, $n, de primera! Aunque la modesta recompensa que te puedo ofrecer no te pagará este trabajo, debes saber que mis camaradas del Cártel Bonvapor oirán hablar de tu hazaña.$B$BY si estás buscando algo más que hacer, házmelo saber, te lo ruego. Porque siempre estoy buscando núcleos elementales y esas cosas.', 0);
-- 7727 ¿Incendosaurio? Loqueseasaurio más bien
-- https://es.classic.wowhead.com/quest=7727
SET @ID := 7727;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Hansel se frota afanosamente sus juanetes.>$B$BNo te quedes ahí $gparado:parada;, toma un poco de aceite y luffa y frota estos juanetes.$B$B¿No tienes luffa? ¡Bien entonces! ¿Quizás es hora de que te envíe a buscar una luffa?$B$BOye, ¿a dónde vas?', 0),
(@ID, 'esMX', '<Hansel se frota afanosamente sus juanetes.>$B$BNo te quedes ahí $gparado:parada;, toma un poco de aceite y luffa y frota estos juanetes.$B$B¿No tienes luffa? ¡Bien entonces! ¿Quizás es hora de que te envíe a buscar una luffa?$B$BOye, ¿a dónde vas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ay, mis pieses.$B$BPues si no tienes esponja...', 0),
(@ID, 'esMX', 'Ay, mis pieses.$B$BPues si no tienes esponja...', 0);
-- 7728 OBJETOS ROBADOS: Tobera y catalejo
-- https://es.classic.wowhead.com/quest=7728
SET @ID := 7728;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si has venido a buscar la recompensa, antes tendrás que darme los objetos robados.', 0),
(@ID, 'esMX', 'Si has venido a buscar la recompensa, antes tendrás que darme los objetos robados.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Y ahora, la recompensa.', 0),
(@ID, 'esMX', '¡Buen trabajo! Y ahora, la recompensa.', 0);
-- 7729 OPORTUNIDAD LABORAL: Acabar con la competencia
-- https://es.classic.wowhead.com/quest=7729
SET @ID := 7729;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tendremos que pesarte con y sin ropa para estar seguros.', 0),
(@ID, 'esMX', 'Tendremos que pesarte con y sin ropa para estar seguros.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡7 kilos! ¡No está mal tener toda esa sangre y tripas en la ropa! ¡Enhorabuena, $c!', 0),
(@ID, 'esMX', '¡7 kilos! ¡No está mal tener toda esa sangre y tripas en la ropa! ¡Enhorabuena, $c!', 0);
-- 7730 Infestación de Zukk'ash
-- https://es.classic.wowhead.com/quest=7730
SET @ID := 7730;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la caza, $n? ¿Has venido a informar de tu éxito?', 0),
(@ID, 'esMX', '¿Cómo va la caza, $n? ¿Has venido a informar de tu éxito?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $c. Aunque los Zukk\'ash están muy extendidos y no podremos librarnos de ellos sin una invasión a gran escala, nos has hecho ganar tiempo para elaborar una buena estrategia.$B$BHaré analizar estos caparazones. Tenemos que averiguar todo lo que podamos sobre ellos si queremos erradicar lo que, por desgracia, ha resultado ser un problema mucho mayor de lo que habíamos previsto.', 0),
(@ID, 'esMX', 'Bien hecho, $c. Aunque los Zukk\'ash están muy extendidos y no podremos librarnos de ellos sin una invasión a gran escala, nos has hecho ganar tiempo para elaborar una buena estrategia.$B$BHaré analizar estos caparazones. Tenemos que averiguar todo lo que podamos sobre ellos si queremos erradicar lo que, por desgracia, ha resultado ser un problema mucho mayor de lo que habíamos previsto.', 0);
-- 7731 Latigador con aguijón
-- https://es.classic.wowhead.com/quest=7731
SET @ID := 7731;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya has conseguido eliminar al latigador con aguijón?', 0),
(@ID, 'esMX', '¿Ya has conseguido eliminar al latigador con aguijón?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $c... ¡muy impresionante! Latigador con aguijón es una de sus criaturas más fuertes. Lo que averigüemos estudiándola será sin duda, valioso para el futuro. Ahora debo ocuparme de que podamos defendernos el tiempo suficiente para estudiarla bien.$B$BPor favor, acepta esta recompensa como muestra del agradecimiento de todo el campamento, $n. Bien hecho.', 0),
(@ID, 'esMX', 'Impresionante, $c... ¡muy impresionante! Latigador con aguijón es una de sus criaturas más fuertes. Lo que averigüemos estudiándola será sin duda, valioso para el futuro. Ahora debo ocuparme de que podamos defendernos el tiempo suficiente para estudiarla bien.$B$BPor favor, acepta esta recompensa como muestra del agradecimiento de todo el campamento, $n. Bien hecho.', 0);
-- 7732 El informe Zukk'ash
-- https://es.classic.wowhead.com/quest=7732
SET @ID := 7732;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, $gamigo:amiga;... Pareces tener asuntos urgentes entre manos. ¿Puedo ayudarte en algo?', 0),
(@ID, 'esMX', 'Saludos, $gamigo:amiga;... Pareces tener asuntos urgentes entre manos. ¿Puedo ayudarte en algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, esto es lo que estaba esperando. Esas criaturas a las que te enfrentaste son una antigua amenaza que la Horda prefiere ignorar. Hadoken ha hecho bien en enviarme esto. Y en enviarte a ti.$B$BLos Zukk\'ash son en realidad esas criaturas que llamamos silítidos. Algunos creen que son apenas una descerebrada molestia, pero te puedo asegurar que son una amenaza mucho mayor de lo que la Alianza pueda pensar.$B$BSi quieres ayudar y eres lo suficientemente fuerte, me vendría bien tu colaboración para sacar este asunto a la luz.', 0),
(@ID, 'esMX', 'Ah, esto es lo que estaba esperando. Esas criaturas a las que te enfrentaste son una antigua amenaza que la Horda prefiere ignorar. Hadoken ha hecho bien en enviarme esto. Y en enviarte a ti.$B$BLos Zukk\'ash son en realidad esas criaturas que llamamos silítidos. Algunos creen que son apenas una descerebrada molestia, pero te puedo asegurar que son una amenaza mucho mayor de lo que la Alianza pueda pensar.$B$BSi quieres ayudar y eres lo suficientemente fuerte, me vendría bien tu colaboración para sacar este asunto a la luz.', 0);
-- Calidad mejorada
-- 7733, 7734
-- https://es.classic.wowhead.com/quest=7733
DELETE FROM `quest_request_items_locale` WHERE `id` IN(7733, 7734) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7733, 'esES', 'Si estas pieles de yetis Cicatriz de Rabia son la mitad de buenas que las de sus amigos de la Cicatriz Feral, ¡podrían ser tan fuertes como el torio!$B$B¿Te das cuenta?', 0),
(7734, 'esES', 'Si estas pieles de yetis Cicatriz de Rabia son la mitad de buenas que las de sus amigos de la Cicatriz Feral, ¡podrían ser tan fuertes como el torio!$B$B¿Te das cuenta?', 0),
(7733, 'esMX', 'Si estas pieles de yetis Cicatriz de Rabia son la mitad de buenas que las de sus amigos de la Cicatriz Feral, ¡podrían ser tan fuertes como el torio!$B$B¿Te das cuenta?', 0),
(7734, 'esMX', 'Si estas pieles de yetis Cicatriz de Rabia son la mitad de buenas que las de sus amigos de la Cicatriz Feral, ¡podrían ser tan fuertes como el torio!$B$B¿Te das cuenta?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(7733, 7734) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7733, 'esES', '¡Excelente, excelente! Estos pellejos van a quedar estupendos. Cuando estén bien curados serán incluso más resistentes.$B$BGracias de nuevo por tu ayuda, $n. Ten, acepta una de mis últimas creaciones.', 0),
(7734, 'esES', '¡Excelente, excelente! Estos pellejos van a quedar estupendos. Cuando estén bien curados serán incluso más resistentes.$B$BGracias de nuevo por tu ayuda, $n. Ten, acepta una de mis últimas creaciones.', 0),
(7733, 'esMX', '¡Excelente, excelente! Estos pellejos van a quedar estupendos. Cuando estén bien curados serán incluso más resistentes.$B$BGracias de nuevo por tu ayuda, $n. Ten, acepta una de mis últimas creaciones.', 0),
(7734, 'esMX', '¡Excelente, excelente! Estos pellejos van a quedar estupendos. Cuando estén bien curados serán incluso más resistentes.$B$BGracias de nuevo por tu ayuda, $n. Ten, acepta una de mis últimas creaciones.', 0);
-- 7735 Pellejo de yeti prístino
-- https://es.classic.wowhead.com/quest=7735
SET @ID := 7735;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué ocurre, $n? ¿Tienes algo especial para mí?', 0),
(@ID, 'esMX', '¿Qué ocurre, $n? ¿Tienes algo especial para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Increíble! ¡Creo que has encontrado el rey de todos los pellejos de yeti!$B$BEstate $gseguro:segura; de que te pagaré bien por él. No suelo pagar mucho por un solo pellejo, pero sé que con este podré hacer algo muy especial. ¡Gracias por haber pensado en mí, $n!', 0),
(@ID, 'esMX', '¡Increíble! ¡Creo que has encontrado el rey de todos los pellejos de yeti!$B$BEstate $gseguro:segura; de que te pagaré bien por él. No suelo pagar mucho por un solo pellejo, pero sé que con este podré hacer algo muy especial. ¡Gracias por haber pensado en mí, $n!', 0);
-- 7736 Fabricar flujo ígneo con sangrerregia
-- https://es.classic.wowhead.com/quest=7736
SET @ID := 7736;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mi tiempo es demasiado valioso para perderlo con charlas, $r. Quiero fabricar más fluido ardiente.$B$BPara eso, necesito que me traigas lo siguiente:$B$B*Escamas de incendosaurio.$B$B*Sangrerregia.$B$B*Carbón.$B$B¡Tráeme tanto como puedas!$B$BY tan rápido como puedas, si es que quieres ganarte el favor de la Hermandad.', 0),
(@ID, 'esMX', 'Mi tiempo es demasiado valioso para perderlo con charlas, $r. Quiero fabricar más fluido ardiente.$B$BPara eso, necesito que me traigas lo siguiente:$B$B*Escamas de incendosaurio.$B$B*Sangrerregia.$B$B*Carbón.$B$B¡Tráeme tanto como puedas!$B$BY tan rápido como puedas, si es que quieres ganarte el favor de la Hermandad.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Siempre hay sitio para el fluido ardiente. Tú sigue trayendo hasta que yo te diga.', 0),
(@ID, 'esMX', 'Siempre hay sitio para el fluido ardiente. Tú sigue trayendo hasta que yo te diga.', 0);
-- 7737 Conseguir más aceptación
-- https://es.classic.wowhead.com/quest=7737
SET @ID := 7737;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has subido los peldaños de la jerarquía de la Hermandad, $r. Te estás ganando nuestro favor, ¡lo que es todo un logro!$B$BSi quieres más trabajo y lograr aún más respeto, escucha.$B$BPodemos refinar el flujo ígneo añadiendo un poco de residuo de hierro negro a la mezcla.$B$BVe a las Profundidades de Roca Negra y tráeme todo el residuo de hierro negro que encuentres.', 0),
(@ID, 'esMX', 'Has subido los peldaños de la jerarquía de la Hermandad, $r. Te estás ganando nuestro favor, ¡lo que es todo un logro!$B$BSi quieres más trabajo y lograr aún más respeto, escucha.$B$BPodemos refinar el flujo ígneo añadiendo un poco de residuo de hierro negro a la mezcla.$B$BVe a las Profundidades de Roca Negra y tráeme todo el residuo de hierro negro que encuentres.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue vertiendo el residuo.', 0),
(@ID, 'esMX', 'Sigue vertiendo el residuo.', 0);
-- 7738 Pellejo de yeti perfecto
-- https://es.classic.wowhead.com/quest=7738
SET @ID := 7738;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué ocurre, $n? ¿Tienes algo especial para mí?', 0),
(@ID, 'esMX', '¿Qué ocurre, $n? ¿Tienes algo especial para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué hallazgo! ¡Creo que es el pellejo de yeti más perfecto que he visto en mi vida!$B$BSin duda merece una buena recompensa. No suelo pagar mucho por un solo pellejo, pero sé que con este podré hacer algo muy especial. ¡Gracias por haber pensado en mí, $n!', 0),
(@ID, 'esMX', '¡Qué hallazgo! ¡Creo que es el pellejo de yeti más perfecto que he visto en mi vida!$B$BSin duda merece una buena recompensa. No suelo pagar mucho por un solo pellejo, pero sé que con este podré hacer algo muy especial. ¡Gracias por haber pensado en mí, $n!', 0);
-- 7761 Orden de Puño Negro
-- https://es.classic.wowhead.com/quest=7761
SET @ID := 7761;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ni siquiera pestañeas cuando se te graba la marca a hierro candente sobre la piel. ¡Eres tan fuerte!$B$BAhora llevas la marca de Drakkisath. Que te diviertas arrasando el castillo.', 0),
(@ID, 'esMX', 'Ni siquiera pestañeas cuando se te graba la marca a hierro candente sobre la piel. ¡Eres tan fuerte!$B$BAhora llevas la marca de Drakkisath. Que te diviertas arrasando el castillo.', 0);
-- 7781 Señor de Roca Negra
-- https://es.classic.wowhead.com/quest=7781
SET @ID := 7781;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Inconcebible!', 0),
(@ID, 'esMX', '¡Inconcebible!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No es necesario que te digan el significado de lo que has hecho, $n. Este día quedará registrado en los anales de la historia. Una victoria de las que la Alianza no conoce desde hace años, ¡si es que alguna vez lo ha hecho!', 0),
(@ID, 'esMX', 'No es necesario que te digan el significado de lo que has hecho, $n. Este día quedará registrado en los anales de la historia. Una victoria de las que la Alianza no conoce desde hace años, ¡si es que alguna vez lo ha hecho!', 0);
-- 7782 Señor de Roca Negra
-- https://es.classic.wowhead.com/quest=7782
SET @ID := 7782;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El mariscal de campo Afrasiabi se inclina.>$B$BElige tu recompensa, ¡que comience la celebración!', 0),
(@ID, 'esMX', '<El mariscal de campo Afrasiabi se inclina.>$B$BElige tu recompensa, ¡que comience la celebración!', 0);
-- 7783 Señor de Roca Negra
-- https://es.classic.wowhead.com/quest=7783
SET @ID := 7783;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ojalá pudiera haber estado allí para ver la expresión del rostro de la bestia cuando asestaste el golpe mortal, $n.', 0),
(@ID, 'esMX', 'Ojalá pudiera haber estado allí para ver la expresión del rostro de la bestia cuando asestaste el golpe mortal, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has honrado a la Horda una vez más, $n. El hijo de Alamuerte yace muerto. Seguramente, el maligno se agita.', 0),
(@ID, 'esMX', 'Has honrado a la Horda una vez más, $n. El hijo de Alamuerte yace muerto. Seguramente, el maligno se agita.', 0);
