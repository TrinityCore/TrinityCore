-- 969 Que la suerte sea contigo
-- https://es.classic.wowhead.com/quest=969
SET @ID := 969;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Trae las esquirlas y te diré algo más!', 0),
(@ID, 'esMX', '¡Trae las esquirlas y te diré algo más!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahh, sí... te haré el talismán ahora mismo. ¡Espera un segundo!', 0),
(@ID, 'esMX', 'Ahh, sí... te haré el talismán ahora mismo. ¡Espera un segundo!', 0);
-- 5054 Ursius de los Dentoesquirla
-- https://es.classic.wowhead.com/quest=5054
SET @ID := 5054;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vete ahora, $c. Busca a Ursius.', 0),
(@ID, 'esMX', 'Vete ahora, $c. Busca a Ursius.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No era una tarea fácil, pero has sido sobresaliente. Pero no vayas tan deprisa, no creas que me has impresionado, $n.', 0),
(@ID, 'esMX', 'No era una tarea fácil, pero has sido sobresaliente. Pero no vayas tan deprisa, no creas que me has impresionado, $n.', 0);
-- 5244 Las Ruinas de Kel'Theril
-- https://es.classic.wowhead.com/quest=5244
SET @ID := 5244;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, claro, puedo darte más información sobre Kel\'Theril. Sabes, no soy historiador, pero puedo contarte todo lo que vi...', 0),
(@ID, 'esMX', 'Sí, claro, puedo darte más información sobre Kel\'Theril. Sabes, no soy historiador, pero puedo contarte todo lo que vi...', 0);
-- 5245 Espíritus condenados de Kel'Theril
-- https://es.classic.wowhead.com/quest=5245
SET @ID := 5245;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Por qué has venido?', 0),
(@ID, 'esMX', '¿Por qué has venido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No quiero hablar sobre el pasado de los elfos nobles, $n. Por favor, me horroriza pensar en todo lo que ocurrió... Y no hay ninguna forma de corregir las cosas.', 0),
(@ID, 'esMX', 'No quiero hablar sobre el pasado de los elfos nobles, $n. Por favor, me horroriza pensar en todo lo que ocurrió... Y no hay ninguna forma de corregir las cosas.', 0);
-- 4861 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=4861
SET @ID := 4861;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Una caja muy dañada destaca entre el resto de las pertenencias destruidas en el campamento...', 0),
(@ID, 'esMX', 'Una caja muy dañada destaca entre el resto de las pertenencias destruidas en el campamento...', 0);
-- 3783 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=3783
SET @ID := 3783;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0),
(@ID, 'esMX', 'Tengo muchas cosas que hacer. Por favor, ¡tráeme las pieles lo antes que puedas!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0),
(@ID, 'esMX', 'Estas pieles son perfectas, $n. ¡Vamos a empezar a hacer algo grande!', 0);
-- 977 Yeti... ¿ya hemos llegado?
-- https://es.classic.wowhead.com/quest=977
SET @ID := 977;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Acabo de terminar de poner las pieles, $n. Por favor, ¡date prisa con esos cuernos!', 0),
(@ID, 'esMX', 'Acabo de terminar de poner las pieles, $n. Por favor, ¡date prisa con esos cuernos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡No puedo esperar a enseñárselo a mis amigos! Espera, es solo un momento... voy a poner estas...$B$B¡Perfecto!', 0),
(@ID, 'esMX', '¡No puedo esperar a enseñárselo a mis amigos! Espera, es solo un momento... voy a poner estas...$B$B¡Perfecto!', 0);
-- 5055 Brumerán de los Orvallo
-- https://es.classic.wowhead.com/quest=5055
SET @ID := 5055;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Brumeran te llama, $n.', 0),
(@ID, 'esMX', 'Brumeran te llama, $n.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí. Has regresado. Ahora creo que eres un auténtico $c por naturaleza. Te has enfrentado a las criaturas más fieras y has regresado, superando todas mis expectativas.$B$BYa estás preparado para mi última petición.', 0),
(@ID, 'esMX', 'Sí. Has regresado. Ahora creo que eres un auténtico $c por naturaleza. Te has enfrentado a las criaturas más fieras y has regresado, superando todas mis expectativas.$B$BYa estás preparado para mi última petición.', 0);
-- 5056 Shi-Rotam
-- https://es.classic.wowhead.com/quest=5056
SET @ID := 5056;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Shy-Rotam es audaz e implacable; defenderá a los suyos con ferviente entusiasmo.', 0),
(@ID, 'esMX', 'Shy-Rotam es audaz e implacable; defenderá a los suyos con ferviente entusiasmo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado tu fuerza y determinación. Te esperan muchos más desafíos, pero ya has probado ser tan capaz como yo mismo puedo serlo.', 0),
(@ID, 'esMX', 'Has demostrado tu fuerza y determinación. Te esperan muchos más desafíos, pero ya has probado ser tan capaz como yo mismo puedo serlo.', 0);
-- 4863 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=4863
SET @ID := 4863;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Al acercarte al carro, no parece que aquí haya mucho más para Jaron. Pero, mirando al suelo, notas algunas cajas que parecen intactas, a pesar de estar medio enterradas en la nieve.', 0),
(@ID, 'esMX', 'Al acercarte al carro, no parece que aquí haya mucho más para Jaron. Pero, mirando al suelo, notas algunas cajas que parecen intactas, a pesar de estar medio enterradas en la nieve.', 0);
-- 4864 Lechúcico salvaje iracundo
-- https://es.classic.wowhead.com/quest=4864
SET @ID := 4864;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí... Cuéntame la noticia.', 0),
(@ID, 'esMX', 'Sí... Cuéntame la noticia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, esperaba escuchar lo mismo, $gmuchacho:muchacha;. Pensé que las bestias enloquecidas destruyeron todas mis pertenencias...$B$BPero encontraste mis herramientas y, lo más importante, ¡el amuleto! Me pregunto por qué los salvajes defendieron tan ferozmente este objeto... ¡En cualquier caso, lo pensaré dos veces antes de seguir su camino!', 0),
(@ID, 'esMX', 'Bueno, esperaba escuchar lo mismo, $gmuchacho:muchacha;. Pensé que las bestias enloquecidas destruyeron todas mis pertenencias...$B$BPero encontraste mis herramientas y, lo más importante, ¡el amuleto! Me pregunto por qué los salvajes defendieron tan ferozmente este objeto... ¡En cualquier caso, lo pensaré dos veces antes de seguir su camino!', 0);
-- 975 Alijo de Mau'ari
-- https://es.classic.wowhead.com/quest=975
SET @ID := 975;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí lo tieneh, $n. Recuerda, contigo lo llevah. ¿Por qué no volver a la naturaleza y veh qué encontrar?', 0),
(@ID, 'esMX', 'Aquí lo tieneh, $n. Recuerda, contigo lo llevah. ¿Por qué no volver a la naturaleza y veh qué encontrar?', 0);
-- 4807 E'ko de lechúcico salvaje
-- https://es.classic.wowhead.com/quest=4807
SET @ID := 4807;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, combatiráh con unah criaturah que parecen tener una habilidad mágica innata. Loh lechúcicoh pueden utilizar magia muy poderosa. Si quiereh aumentar tu intelecto tráeme el E\'ko que encontraráh en lah lechubehtiah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, combatiráh con unah criaturah que parecen tener una habilidad mágica innata. Loh lechúcicoh pueden utilizar magia muy poderosa. Si quiereh aumentar tu intelecto tráeme el E\'ko que encontraráh en lah lechubehtiah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4805 E'ko de los Cardo Nevado
-- https://es.classic.wowhead.com/quest=4805
SET @ID := 4805;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, combatiráh con enormeh criaturah llamadah Yeti Cardo Nevado. Son behtiah lentah pero pueden evadir muchoh golpeh por la protección que leh da su ehpeso pelaje. Si deseah obtener la habilidad de esquivar ataqueh, tráeme el E\'ko que encuentreh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, combatiráh con enormeh criaturah llamadah Yeti Cardo Nevado. Son behtiah lentah pero pueden evadir muchoh golpeh por la protección que leh da su ehpeso pelaje. Si deseah obtener la habilidad de esquivar ataqueh, tráeme el E\'ko que encuentreh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4803 E'ko Dentoesquirla
-- https://es.classic.wowhead.com/quest=4803
SET @ID := 4803;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno encontraráh grandeh osoh con unah pieleh extremadamente durah y gruesah. Loh osoh dentoesquirla obtienen mucha protección de lo que pueden resihtir. Si quiereh resihtencia al Fuego, tráeme el E\'ko que encontraráh en loh dentoesquirla.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario para poder obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno encontraráh grandeh osoh con unah pieleh extremadamente durah y gruesah. Loh osoh dentoesquirla obtienen mucha protección de lo que pueden resihtir. Si quiereh resihtencia al Fuego, tráeme el E\'ko que encontraráh en loh dentoesquirla.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario para poder obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4806 E'ko de los Machacahielo
-- https://es.classic.wowhead.com/quest=4806
SET @ID := 4806;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno combatiráh con unoh enormeh giganteh de hielo llamadoh Machacahielo. Suyoh son el poder y la fuerza máh puroh. Si quiereh ganar la fuerza del Machacahielo tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno combatiráh con unoh enormeh giganteh de hielo llamadoh Machacahielo. Suyoh son el poder y la fuerza máh puroh. Si quiereh ganar la fuerza del Machacahielo tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4802 E'ko Nevada
-- https://es.classic.wowhead.com/quest=4802
SET @ID := 4802;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno combatiráh con unah criaturah dehcarriadah conocidah como loh furbolgs Nevada. Siguiendo loh deseoh de su líder se han hecho increíblemente fuerteh. Si quiereh el poder de loh Nevada tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno combatiráh con unah criaturah dehcarriadah conocidah como loh furbolgs Nevada. Siguiendo loh deseoh de su líder se han hecho increíblemente fuerteh. Si quiereh el poder de loh Nevada tráeme el E\'ko que encontraráh en elloh.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh conseguir E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4804 E'ko Orvallo
-- https://es.classic.wowhead.com/quest=4804
SET @ID := 4804;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, combatiráh con unah grandeh criaturah voladorah llamadah Quimerah Venfrehco. Estah behtiah poseen el poder de usar la magia de hielo. Si deseah ganar resihtencia a lah heladah, tráeme el E\'ko que encuentreh en ellah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, combatiráh con unah grandeh criaturah voladorah llamadah Quimerah Venfrehco. Estah behtiah poseen el poder de usar la magia de hielo. Si deseah ganar resihtencia a lah heladah, tráeme el E\'ko que encuentreh en ellah.$B$BRecuerda, debeh tener el Alijo de Mau\'ari en tu inventario si quiereh obtener E\'ko.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 4801 E'ko de sable de hielo
-- https://es.classic.wowhead.com/quest=4801
SET @ID := 4801;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'En Cuna del Invierno, lucharáh contra grandeh felinoh llamadoh sableh de hielo. Estah behtiah poseen una increíble velocidad y ahtucia. Si quiereh ganar la velocidad de un sable de hielo, tráeme el E\'ko que encuentreh en elloh.', 0),
(@ID, 'esMX', 'En Cuna del Invierno, lucharáh contra grandeh felinoh llamadoh sableh de hielo. Estah behtiah poseen una increíble velocidad y ahtucia. Si quiereh ganar la velocidad de un sable de hielo, tráeme el E\'ko que encuentreh en elloh.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0),
(@ID, 'esMX', 'Mau\'ari puede crear el Juju para $n... Utiliza el Alijo de Mau\'ari para lanzarlo sobre ti o sobre tuh aliadoh.', 0);
-- 2661 Un envío para Marin
-- https://es.classic.wowhead.com/quest=2661
SET @ID := 2661;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, $n, al fin has vuelto. ¿Qué traes?', 0),
(@ID, 'esMX', 'Ah, $n, al fin has vuelto. ¿Qué traes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Polvo violeta, eh? Déjame que lo pruebe... De todos modos, es imposible que empeore las cosas.', 0),
(@ID, 'esMX', '¿Polvo violeta, eh? Déjame que lo pruebe... De todos modos, es imposible que empeore las cosas.', 0);
-- 2662 El elixir de Tragonublo
-- https://es.classic.wowhead.com/quest=2662
SET @ID := 2662;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Dale un trago! ¡¡¡Es estupendo!!!$B$BSabía que lo conseguiría... Gracias otra vez por tu ayuda, $n. Eso sí, hazte a un lado. ¡Estás interrumpiendo mi trabajo! ¡Voy a hacerme rico con este fabuloso Elixir de Tragonublo! ¡Rico!$B$B¿Cómo? ¿Roxio dice que le debo una? ¡Hay que ver qué sentido del humor tiene Roxio!', 0),
(@ID, 'esMX', '¡Dale un trago! ¡¡¡Es estupendo!!!$B$BSabía que lo conseguiría... Gracias otra vez por tu ayuda, $n. Eso sí, hazte a un lado. ¡Estás interrumpiendo mi trabajo! ¡Voy a hacerme rico con este fabuloso Elixir de Tragonublo! ¡Rico!$B$B¿Cómo? ¿Roxio dice que le debo una? ¡Hay que ver qué sentido del humor tiene Roxio!', 0);
-- 4496 Que jungla tan chunga
-- https://es.classic.wowhead.com/quest=4496
SET @ID := 4496;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No es fácil conseguir una glándula secretora de olor que sirva; la glándula ha de estar en perfecto estado pero el proceso para obtenerla generalmente hace que eso sea imposible. Con la tierra supongo que no habrás tenido tantos problemas.$B$BEn cualquier caso, ¿tienes lo que necesito para fabricar el señuelo?', 0),
(@ID, 'esMX', 'No es fácil conseguir una glándula secretora de olor que sirva; la glándula ha de estar en perfecto estado pero el proceso para obtenerla generalmente hace que eso sea imposible. Con la tierra supongo que no habrás tenido tantos problemas.$B$BEn cualquier caso, ¿tienes lo que necesito para fabricar el señuelo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La glándula secretora de olor, ¡qué bien! ¡Estupendo! La membrana parece estar intacta. Y la tierra, sí, creo que servirá. Con esto y un pequeño toque personal, crearé el señuelo perfecto.$B$BDame un momento para prepararlo, $n. Cuando lo tenga, podremos dar el siguiente paso en nuestro intento de detener la expansión de los silítidos por Gadgetzan... y todo Kalimdor.', 0),
(@ID, 'esMX', 'La glándula secretora de olor, ¡qué bien! ¡Estupendo! La membrana parece estar intacta. Y la tierra, sí, creo que servirá. Con esto y un pequeño toque personal, crearé el señuelo perfecto.$B$BDame un momento para prepararlo, $n. Cuando lo tenga, podremos dar el siguiente paso en nuestro intento de detener la expansión de los silítidos por Gadgetzan... y todo Kalimdor.', 0);
