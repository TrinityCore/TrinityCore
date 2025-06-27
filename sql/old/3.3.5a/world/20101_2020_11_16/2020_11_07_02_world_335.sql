-- 3528 El dios Hakkar
-- https://es.classic.wowhead.com/quest=3528
SET @ID := 3528;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has derrotado al avatar de Hakkar, $n? ¿Has encerrado su esencia en el huevo que te di?', 0),
(@ID, 'esMX', '¿Has derrotado al avatar de Hakkar, $n? ¿Has encerrado su esencia en el huevo que te di?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La esencia de Hakkar está encerrada! ¡Aun así, el huevo rezuma vida! ¿Será cierto el mito sobre Hakkar?$B$BEspero que no pues quién sabe qué haría Hakkar si volviera a nacer. Guardaré el huevo en un lugar seguro para que no caiga en malas manos.$B$BTu trabajo conmigo ha concluido, $n. Ahora eres una auténtica leyenda y tus acciones algún día cambiarán nuestro mundo.', 0),
(@ID, 'esMX', '¡La esencia de Hakkar está encerrada! ¡Aun así, el huevo rezuma vida! ¿Será cierto el mito sobre Hakkar?$B$BEspero que no pues quién sabe qué haría Hakkar si volviera a nacer. Guardaré el huevo en un lugar seguro para que no caiga en malas manos.$B$BTu trabajo conmigo ha concluido, $n. Ahora eres una auténtica leyenda y tus acciones algún día cambiarán nuestro mundo.', 0);
-- 5065 Las tablillas perdidas Mosh'aru
-- https://es.classic.wowhead.com/quest=5065
SET @ID := 5065;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las tablillas? Me temo que sus textos revelarán una gran amenaza para nuestro mundo.', 0),
(@ID, 'esMX', '¿Tienes las tablillas? Me temo que sus textos revelarán una gran amenaza para nuestro mundo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los encontraste! ¡Excelente!$B$BGracias, $n. Repasaré estos textos y descifraré su significado.$B$BTú, sin embargo, tienes otra tarea...', 0),
(@ID, 'esMX', '¡Los encontraste! ¡Excelente!$B$BGracias, $n. Repasaré estos textos y descifraré su significado.$B$BTú, sin embargo, tienes otra tarea...', 0);
-- 4289 Los simios de Un'Goro
-- https://es.classic.wowhead.com/quest=4289
SET @ID := 4289;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has dejado vencer por las criaturas, $n?$B$BNo te rindas tan fácilmente. Perseguir y derrotar a los simios de Un\'Goro no es tarea fácil, ni siquiera para $gun:una; gran $c.', 0),
(@ID, 'esMX', '¿Te has dejado vencer por las criaturas, $n?$B$BNo te rindas tan fácilmente. Perseguir y derrotar a los simios de Un\'Goro no es tarea fácil, ni siquiera para $gun:una; gran $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado poseer la fuerza necesaria para vencer a los grandes simios de Un\'Goro, lo cual está muy bien. Aunque no se pueda comparar con enfrentarse a Lar\'korwi, tu hazaña no deja de tener mérito.$B$BCon estas pieles mi tribu podrá confeccionar estupendos ropajes. Me has prestado una valiosa ayuda.$B$BAntes de que te marches, alabemos a la Madre Tierra y demos gracias a los espíritus de los simios que mataste, pues su muerte no ha sido en vano.', 0),
(@ID, 'esMX', 'Has demostrado poseer la fuerza necesaria para vencer a los grandes simios de Un\'Goro, lo cual está muy bien. Aunque no se pueda comparar con enfrentarse a Lar\'korwi, tu hazaña no deja de tener mérito.$B$BCon estas pieles mi tribu podrá confeccionar estupendos ropajes. Me has prestado una valiosa ayuda.$B$BAntes de que te marches, alabemos a la Madre Tierra y demos gracias a los espíritus de los simios que mataste, pues su muerte no ha sido en vano.', 0);
-- 4290 La comida de Lar'korwi
-- https://es.classic.wowhead.com/quest=4290
SET @ID := 4290;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tomes mis palabras a la ligera, $n. Si realmente quieres enfrentarte a esta criatura, debes actuar con prudencia y habilidad. Conseguir que Lar\'korwi venga a por ti y finalmente derrotarlo requerirá mucha fuerza y perspicacia por tu parte.', 0),
(@ID, 'esMX', 'No tomes mis palabras a la ligera, $n. Si realmente quieres enfrentarte a esta criatura, debes actuar con prudencia y habilidad. Conseguir que Lar\'korwi venga a por ti y finalmente derrotarlo requerirá mucha fuerza y perspicacia por tu parte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esta carne servirá, $n. Parece que Lar\'korwi no pasa hambre, ¿eh? Me pregunto dónde habrá encontrado un trillanodonte... es extraño.$B$BDe cualquier modo, guardaré esto hasta que estés $gpreparado:preparada; pare enfrentarte a él. No te preocupes por mí, pues estoy seguro de que has enfadado tanto a Lar\'korwi que no me hará daño hasta que te haya echado el diente a ti.', 0),
(@ID, 'esMX', 'Esta carne servirá, $n. Parece que Lar\'korwi no pasa hambre, ¿eh? Me pregunto dónde habrá encontrado un trillanodonte... es extraño.$B$BDe cualquier modo, guardaré esto hasta que estés $gpreparado:preparada; pare enfrentarte a él. No te preocupes por mí, pues estoy seguro de que has enfadado tanto a Lar\'korwi que no me hará daño hasta que te haya echado el diente a ti.', 0);
-- 3884 Diario de Williden
-- https://es.classic.wowhead.com/quest=3884
SET @ID := 3884;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! ¡Mis compañeros y yo nos alegramos de ver formas de vida que no sean bestias salvajes hiperdesarrolladas! ¿Qué te trae al Cráter de Un\'Goro?', 0),
(@ID, 'esMX', '¡Hola! ¡Mis compañeros y yo nos alegramos de ver formas de vida que no sean bestias salvajes hiperdesarrolladas! ¿Qué te trae al Cráter de Un\'Goro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, mira eso! ¡Mi diario! Pensaba que estaba perdido, como casi todo lo que trajimos a Un\'Goro. ¡Muchísimas gracias por devolvérmelo!', 0),
(@ID, 'esMX', '¡Vaya, mira eso! ¡Mi diario! Pensaba que estaba perdido, como casi todo lo que trajimos a Un\'Goro. ¡Muchísimas gracias por devolvérmelo!', 0);
-- 3844 Un secreto bien guardado
-- https://es.classic.wowhead.com/quest=3844
SET @ID := 3844;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encuentras una talega empapada en el fondo del estanque.', 0),
(@ID, 'esMX', 'Encuentras una talega empapada en el fondo del estanque.', 0);
-- 3845 Un secreto bien guardado
-- https://es.classic.wowhead.com/quest=3845
SET @ID := 3845;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. Ya te había visto antes... ¿no es cierto?', 0),
(@ID, 'esMX', 'Hola. Ya te había visto antes... ¿no es cierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh... sí, esto me resulta familiar... en cierto modo...', 0),
(@ID, 'esMX', 'Oh... sí, esto me resulta familiar... en cierto modo...', 0);
-- 4291 Un aroma irresistible para Lar'korwi
-- https://es.classic.wowhead.com/quest=4291
SET @ID := 4291;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ten cuidado, $n. Al acercarte a los nidos de huevos provocarás la ira de las madres... aunque ya tengas una de sus glándulas. Las madres pueden ser tan peligrosas como Lar\'korwi cuando se trata de defender a sus retoños. Sin embargo, si tienes éxito, será nuestra última oportunidad de conseguir que Lar\'korwi salga de su escondrijo.', 0),
(@ID, 'esMX', 'Ten cuidado, $n. Al acercarte a los nidos de huevos provocarás la ira de las madres... aunque ya tengas una de sus glándulas. Las madres pueden ser tan peligrosas como Lar\'korwi cuando se trata de defender a sus retoños. Sin embargo, si tienes éxito, será nuestra última oportunidad de conseguir que Lar\'korwi salga de su escondrijo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Espléndidas glándulas, $n! Serán el cebo perfecto para atraer a Lar\'korwi. Estoy deseando ver cómo resulta tu enfrentamiento con ese monstruo. Es una mole con unas garras afiladas como cuchillos y en sus ojos se refleja la muerte.', 0),
(@ID, 'esMX', '¡Espléndidas glándulas, $n! Serán el cebo perfecto para atraer a Lar\'korwi. Estoy deseando ver cómo resulta tu enfrentamiento con ese monstruo. Es una mole con unas garras afiladas como cuchillos y en sus ojos se refleja la muerte.', 0);
-- 4292 El cebo para Lar'korwi
-- https://es.classic.wowhead.com/quest=4292
SET @ID := 4292;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No dejes que el miedo te bloquee, $n. El miedo es traicionero... ¡pero debes superarlo!$B$BCoge la carne, déjala en el pequeño valle y después úntala con la glándula. En ese momento, la muerte vendrá a por ti.', 0),
(@ID, 'esMX', 'No dejes que el miedo te bloquee, $n. El miedo es traicionero... ¡pero debes superarlo!$B$BCoge la carne, déjala en el pequeño valle y después úntala con la glándula. En ese momento, la muerte vendrá a por ti.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Alabada sea la Madre Tierra! ¡Lo has conseguido! No cabe duda de que eres $gun:una; gran $gcazador:cazadora;. Has demostrado poseer fortaleza de espíritu y una valentía inigualable, y además has incrementado tu fuerza. Mereces todo mi respeto.$B$BSolo el más poderoso de mis ancestros habría sido capaz de realizar una hazaña como la tuya. Enhorabuena.', 0),
(@ID, 'esMX', '¡Alabada sea la Madre Tierra! ¡Lo has conseguido! No cabe duda de que eres $gun:una; gran $gcazador:cazadora;. Has demostrado poseer fortaleza de espíritu y una valentía inigualable, y además has incrementado tu fuerza. Mereces todo mi respeto.$B$BSolo el más poderoso de mis ancestros habría sido capaz de realizar una hazaña como la tuya. Enhorabuena.', 0);
-- 4243 Buscando a Memo 01
-- https://es.classic.wowhead.com/quest=4243
SET @ID := 4243;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Observas a Memo 01 y ves que la maravillosa creación de ingeniería de Karna tiene dos enormes abolladuras, una en el hombro y otra en la cabeza.$B$BAdemás, te das cuenta de que no funciona.', 0),
(@ID, 'esMX', 'Observas a Memo 01 y ves que la maravillosa creación de ingeniería de Karna tiene dos enormes abolladuras, una en el hombro y otra en la cabeza.$B$BAdemás, te das cuenta de que no funciona.', 0);
-- 4503 El aparato volador de Shizzle
-- https://es.classic.wowhead.com/quest=4503
SET @ID := 4503;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Todo gran vehículo necesita un nombre... Estaba pensando en llamarlo... ¡Pwned!', 0),
(@ID, 'esMX', 'Todo gran vehículo necesita un nombre... Estaba pensando en llamarlo... ¡Pwned!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, estas escamas son perfectas. ¡Ahora no debería tener ningún problema para hacer volar a este cacharro!$B$B¡Gracias!', 0),
(@ID, 'esMX', 'Sí, estas escamas son perfectas. ¡Ahora no debería tener ningún problema para hacer volar a este cacharro!$B$B¡Gracias!', 0);
-- 3908 Un secreto bien guardado
-- https://es.classic.wowhead.com/quest=3908
SET @ID := 3908;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, vaya... Así que Linken por fin ha encontrado algo de tiempo para mandarme su espada.', 0),
(@ID, 'esMX', 'Vaya, vaya... Así que Linken por fin ha encontrado algo de tiempo para mandarme su espada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, claro que puedo templar la espada. Mientras trabajo puedes ir explicándome por qué le ha costado tanto tiempo a Linken traérmela. No suele olvidarse de nada...', 0),
(@ID, 'esMX', 'Sí, claro que puedo templar la espada. Mientras trabajo puedes ir explicándome por qué le ha costado tanto tiempo a Linken traérmela. No suele olvidarse de nada...', 0);
-- 4492 ¡Perdido!
-- https://es.classic.wowhead.com/quest=4492
SET @ID := 4492;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Eh.. qué?', 0),
(@ID, 'esMX', '¿Eh.. qué?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Oh... qué alegría que me hayas encontrado...', 0),
(@ID, 'esMX', 'Oh... qué alegría que me hayas encontrado...', 0);
-- 4501 Cuidado con los pterrordáctilos
-- https://es.classic.wowhead.com/quest=4501
SET @ID := 4501;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Para decirte la verdad, realmente no estaba tan preocupado por las extrañas criaturas ... Hasta el día en que lo vi escrito en el costado de una gran piedra.$B$BCUIDADO CON LOS PTERRORDÁCTILOS$B$B¿Quién pudo haberlo escrito? No lo sé, ¡pero es demasiado espeluznante como para ignorarlo!', 0),
(@ID, 'esMX', 'Para decirte la verdad, realmente no estaba tan preocupado por las extrañas criaturas ... Hasta el día en que lo vi escrito en el costado de una gran piedra.$B$BCUIDADO CON LOS PTERRORDÁCTILOS$B$B¿Quién pudo haberlo escrito? No lo sé, ¡pero es demasiado espeluznante como para ignorarlo!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los Pterrordáctilos me dan un miedo horrible! Gracias por hacer que sean menos, $n. Ahora quizás me atreva a salir del Refugio de Marshal.', 0),
(@ID, 'esMX', '¡Los Pterrordáctilos me dan un miedo horrible! Gracias por hacer que sean menos, $n. Ahora quizás me atreva a salir del Refugio de Marshal.', 0);
-- 3882 Choca esos huesos
-- https://es.classic.wowhead.com/quest=3882
SET @ID := 3882;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Piensa lo que quieras de mí, pero no se darán cuenta de que los huesos que investigan son de stegodones y diemetradones antiguos o de los que casi nos devoraron cuando intentábamos establecer nuestros campamentos. Yo solo estaré contento si salgo de aquí con vida...', 0),
(@ID, 'esMX', 'Piensa lo que quieras de mí, pero no se darán cuenta de que los huesos que investigan son de stegodones y diemetradones antiguos o de los que casi nos devoraron cuando intentábamos establecer nuestros campamentos. Yo solo estaré contento si salgo de aquí con vida...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, estos deberían servirnos. Y ahora, si me lo permites...$B$BGRACIAS POR DESENTERRAR TODOS ESTOS HUESOS PARA NOSOTROS Y NO HACER NI UN SOLO RASGUÑO A LAS BESTIAS NATIVAS.$B$BSi lo hiciste o no, no lo sé ni me importa. Dejémoslo tal y como está, ¿de acuerdo? Toma, quizás con esto mantengas la boca cerrada... ¡Estoy dispuesto a cualquier cosa con tal de salir de aquí con vida, ya te lo dije!', 0),
(@ID, 'esMX', 'Excelente, estos deberían servirnos. Y ahora, si me lo permites...$B$BGRACIAS POR DESENTERRAR TODOS ESTOS HUESOS PARA NOSOTROS Y NO HACER NI UN SOLO RASGUÑO A LAS BESTIAS NATIVAS.$B$BSi lo hiciste o no, no lo sé ni me importa. Dejémoslo tal y como está, ¿de acuerdo? Toma, quizás con esto mantengas la boca cerrada... ¡Estoy dispuesto a cualquier cosa con tal de salir de aquí con vida, ya te lo dije!', 0);
-- 5150 ¡Dadanga tiene hambre!
-- https://es.classic.wowhead.com/quest=5150
SET @ID := 5150;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Dadanga te observa mientras te acercas a ella. Parece que espera algo...$B$B¡Probablemente esté hambrienta!$B$BSeguro que en el cráter hay algo que le puede servir de aperitivo a una gran herbívora como ella. Ten en cuenta que es una chica muy grande así que, traigas lo que traigas, ¡que sea en abundancia!', 0),
(@ID, 'esMX', 'Dadanga te observa mientras te acercas a ella. Parece que espera algo...$B$B¡Probablemente esté hambrienta!$B$BSeguro que en el cráter hay algo que le puede servir de aperitivo a una gran herbívora como ella. Ten en cuenta que es una chica muy grande así que, traigas lo que traigas, ¡que sea en abundancia!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Parece que a Dadanga le gustan los brotes que le has traído.$B$BA cambio, te entrega un pequeño paquete.', 0),
(@ID, 'esMX', 'Parece que a Dadanga le gustan los brotes que le has traído.$B$BA cambio, te entrega un pequeño paquete.', 0);
-- 3883 Ecología alienígena
-- https://es.classic.wowhead.com/quest=3883
SET @ID := 3883;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes la muestra de la colmena Gorishi para que la estudie, $n?', 0),
(@ID, 'esMX', '¿Tienes la muestra de la colmena Gorishi para que la estudie, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, esto servirá. Has sido de gran ayuda... Ojalá pudiera darte algo más, pero estando aquí atrapada en medio de la nada no tengo muchas cosas que ofrecerte. Pero descansa tranquilo, ¡esta investigación no hubiera sido posible sin tu ayuda!', 0),
(@ID, 'esMX', 'Sí, esto servirá. Has sido de gran ayuda... Ojalá pudiera darte algo más, pero estando aquí atrapada en medio de la nada no tengo muchas cosas que ofrecerte. Pero descansa tranquilo, ¡esta investigación no hubiera sido posible sin tu ayuda!', 0);
-- 3881 Salvar a la expedición
-- https://es.classic.wowhead.com/quest=3881
SET @ID := 3881;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Si existe la más mínima posibilidad de salir de aquí con vida, necesitaremos nuestro cajón de comestibles. Además, recuperar algo de nuestro equipo de investigación sería un rayo de luz en un océano de desgracias.', 0),
(@ID, 'esMX', 'Si existe la más mínima posibilidad de salir de aquí con vida, necesitaremos nuestro cajón de comestibles. Además, recuperar algo de nuestro equipo de investigación sería un rayo de luz en un océano de desgracias.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Conseguiste recuperar nuestros comestibles Y nuestro equipo de investigación! No solo has salvado la expedición, ¡has salvado nuestras vidas! Yo y el resto de mi equipo no podemos agradecértelo lo suficiente. Has hecho posible que podamos quedarnos aquí por un tiempo.$B$BAunque no tenemos mucho, no vamos a permitir que te vayas con las manos vacías después de toda la ayuda que nos has prestado. Gracias, $n, ¡ahora tienes un amigo en las Expediciones Marshal!', 0),
(@ID, 'esMX', '¡Conseguiste recuperar nuestros comestibles Y nuestro equipo de investigación! No solo has salvado la expedición, ¡has salvado nuestras vidas! Yo y el resto de mi equipo no podemos agradecértelo lo suficiente. Has hecho posible que podamos quedarnos aquí por un tiempo.$B$BAunque no tenemos mucho, no vamos a permitir que te vayas con las manos vacías después de toda la ayuda que nos has prestado. Gracias, $n, ¡ahora tienes un amigo en las Expediciones Marshal!', 0);
-- 4141 Muigin y Larion
-- https://es.classic.wowhead.com/quest=4141
SET @ID := 4141;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Larion no sabe lo que le espera!', 0),
(@ID, 'esMX', '¡Larion no sabe lo que le espera!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que no te hayan causado demasiados problemas, $n. A ver si puedo dominarlas... ¡parecen salvajes!$B$BY si las piso... ¡Ah, me han atacado! ¡Las plantas no deberían comportarse de ese modo!', 0),
(@ID, 'esMX', 'Espero que no te hayan causado demasiados problemas, $n. A ver si puedo dominarlas... ¡parecen salvajes!$B$BY si las piso... ¡Ah, me han atacado! ¡Las plantas no deberían comportarse de ese modo!', 0);
-- 4142 Visita a Gregan
-- https://es.classic.wowhead.com/quest=4142
SET @ID := 4142;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vivo en el bosque... en paz.$B$B¡O así pensaba que sería! ¡Recibo más visitas aquí que cuando vivía en Forjaz!', 0),
(@ID, 'esMX', 'Vivo en el bosque... en paz.$B$B¡O así pensaba que sería! ¡Recibo más visitas aquí que cuando vivía en Forjaz!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un pétalo de sangre, ¿eh? Mmm... Explícame qué quieres y entonces te diré si puedo ayudarte o no.', 0),
(@ID, 'esMX', 'Un pétalo de sangre, ¿eh? Mmm... Explícame qué quieres y entonces te diré si puedo ayudarte o no.', 0);
-- 4244 Buscando a Memo 01
-- https://es.classic.wowhead.com/quest=4244
SET @ID := 4244;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El panel en el que va la envoltura de mitril está cerrado y Memo 01 permanece inerte.', 0),
(@ID, 'esMX', 'El panel en el que va la envoltura de mitril está cerrado y Memo 01 permanece inerte.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '"Abres el panel trasero de Memo 01, retiras la vieja envoltura de mitril que parece haberse quemado e introduces la nueva con cuidado. Si este era realmente el problema, lo único que queda por hacer es apagar y encender de nuevo a Memo.', 0),
(@ID, 'esMX', '"Abres el panel trasero de Memo 01, retiras la vieja envoltura de mitril que parece haberse quemado e introduces la nueva con cuidado. Si este era realmente el problema, lo único que queda por hacer es apagar y encender de nuevo a Memo.', 0);
