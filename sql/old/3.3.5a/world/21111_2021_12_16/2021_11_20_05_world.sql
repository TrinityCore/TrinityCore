-- 10666 El Lexicón demoníaco
-- https://es.wowhead.com/quest=10666
SET @ID := 10666;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has recuperado el libro?', 0),
(@ID, 'esMX', '¿Has recuperado el libro?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<David hojea las páginas del libro, estremeciéndose.>$B$BEsto no es para tomárselo a la ligera, $n. Después de crear el arma, lo destruiré. Ya hay suficiente poder demoníaco en el mundo sin este texto por ahí suelto.', 0),
(@ID, 'esMX', '<David hojea las páginas del libro, estremeciéndose.>$B$BEsto no es para tomárselo a la ligera, $n. Después de crear el arma, lo destruiré. Ya hay suficiente poder demoníaco en el mundo sin este texto por ahí suelto.', 0);
-- 10667 Marga del submundo
-- https://es.wowhead.com/quest=10667
SET @ID := 10667;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido la marga del submundo?', 0),
(@ID, 'esMX', '¿Has conseguido la marga del submundo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto debería servir. Esperaba algo más aunque, a decir verdad, ya hemos tenido suerte de conseguir lo que tenemos aquí.', 0),
(@ID, 'esMX', 'Esto debería servir. Esperaba algo más aunque, a decir verdad, ya hemos tenido suerte de conseguir lo que tenemos aquí.', 0);
-- 10668 Contra los Illidari
-- https://es.wowhead.com/quest=10668
SET @ID := 10668;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está muerto el teniente Illidari?', 0),
(@ID, 'esMX', '¿Está muerto el teniente Illidari?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Así que no estás con Illidan. Estás más cerca de ganarte mi total confianza.', 0),
(@ID, 'esMX', 'Así que no estás con Illidan. Estás más cerca de ganarte mi total confianza.', 0);
-- 10669 Contra todo pronóstico
-- https://es.wowhead.com/quest=10669
SET @ID := 10669;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has regresado. ¿Ha muerto Xeleth?', 0),
(@ID, 'esMX', 'Has regresado. ¿Ha muerto Xeleth?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. ¿Todavía se acordaba del día en que le clavé esta lanza? Fue hace tanto tiempo...', 0),
(@ID, 'esMX', 'Muy bien, $n. ¿Todavía se acordaba del día en que le clavé esta lanza? Fue hace tanto tiempo...', 0);
-- 10670 La lágrima de la Madre Tierra
-- https://es.wowhead.com/quest=10670
SET @ID := 10670;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has podido arrebatarle la gema a O\'mrogg?', 0),
(@ID, 'esMX', '¿Has podido arrebatarle la gema a O\'mrogg?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<David Wayne acerca la gema a la luz, admirado.>$B$BEs realmente perfecta y eso es exactamente lo que necesitaremos. Una gema con alguna tacha pondría en peligro a quien lleve el arma y volvería la magia en su contra.', 0),
(@ID, 'esMX', '<David Wayne acerca la gema a la luz, admirado.>$B$BEs realmente perfecta y eso es exactamente lo que necesitaremos. Una gema con alguna tacha pondría en peligro a quien lleve el arma y volvería la magia en su contra.', 0);
-- 10671 Medio kilo de carne de primera
-- https://es.wowhead.com/quest=10671
SET @ID := 10671;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi medio kilo de carne? ¿Qué? ¿No te ha parecido gracioso?', 0),
(@ID, 'esMX', '¿Tienes mi medio kilo de carne? ¿Qué? ¿No te ha parecido gracioso?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Deberían ir muy bien. Aunque menudo tufillo ¿no crees?$B$BEspero que haya merecido la pena las molestias que te has tomado... ¡Solo puedo alegrarme de que tú hayas recolectado esto y no yo!', 0),
(@ID, 'esMX', 'Deberían ir muy bien. Aunque menudo tufillo ¿no crees?$B$BEspero que haya merecido la pena las molestias que te has tomado... ¡Solo puedo alegrarme de que tú hayas recolectado esto y no yo!', 0);
-- 10672 Francamente, no tiene ningún sentido...
-- https://es.wowhead.com/quest=10672
SET @ID := 10672;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Diemetradón de fuego vil superior marcado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Escucha, no tengo tiempo ni ganas de explicar qué significa todo esto. Solo etiqueta esos diemetradones.', 0),
(@ID, 'esMX', 'Escucha, no tengo tiempo ni ganas de explicar qué significa todo esto. Solo etiqueta esos diemetradones.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Escucha, no hay tiempo que perder. He estado observando a los diemetradones marcados y he descubierto que todos están controlados por un gigantesco, ENORME diemetradón llamado Lomovil el Grande.', 0),
(@ID, 'esMX', 'Escucha, no hay tiempo que perder. He estado observando a los diemetradones marcados y he descubierto que todos están controlados por un gigantesco, ENORME diemetradón llamado Lomovil el Grande.', 0);
-- 10673 Lomovil el Grande
-- https://es.wowhead.com/quest=10673
SET @ID := 10673;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Maldita sea! El apetito de ese gnomo no tiene límite.', 0),
(@ID, 'esMX', '¡Maldita sea! El apetito de ese gnomo no tiene límite.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Por fin! ¡He conseguido la protección total anti-lava! Por supuesto que tú también podrás beneficiarte de esta tecnología, $n. ¡Te lo mereces!', 0),
(@ID, 'esMX', '¡Por fin! ¡He conseguido la protección total anti-lava! Por supuesto que tú también podrás beneficiarte de esta tecnología, $n. ¡Te lo mereces!', 0);
-- 10674 Atrapar la Luz fantástica
-- https://es.wowhead.com/quest=10674
SET @ID := 10674;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Orbes de luz Razaani atrapados', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Supongo que, como estamos hablando, tienes los orbes de luz de la Zona de Aterrizaje Razaan. Será interesante echar un vistazo y poder ver qué es lo que están haciendo los etéreos.', 0),
(@ID, 'esMX', 'Supongo que, como estamos hablando, tienes los orbes de luz de la Zona de Aterrizaje Razaan. Será interesante echar un vistazo y poder ver qué es lo que están haciendo los etéreos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eh! ¡Espera un segundo!$B$BEsto no parece estar bien...', 0),
(@ID, 'esMX', '¡Eh! ¡Espera un segundo!$B$BEsto no parece estar bien...', 0);
-- 10675 ¡Gnomas piedad!
-- https://es.wowhead.com/quest=10675
SET @ID := 10675;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Te has encargado ya de ese monstruo roba almas de Razaan?', 0),
(@ID, 'esMX', '¿Te has encargado ya de ese monstruo roba almas de Razaan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Adiós muy buenas! Gracias por acabar con su macabro uso de la magia y la tecnología.$B$BComo gran héroe de los gnomos de todas partes, te concedo nuestro más grande honor... puedes elegir entre todo esto.$B$B¡Sé que te vendrá bien!', 0),
(@ID, 'esMX', '¡Adiós muy buenas! Gracias por acabar con su macabro uso de la magia y la tecnología.$B$BComo gran héroe de los gnomos de todas partes, te concedo nuestro más grande honor... puedes elegir entre todo esto.$B$B¡Sé que te vendrá bien!', 0);
-- 10676 El terror de los Illidari
-- https://es.wowhead.com/quest=10676
SET @ID := 10676;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<David se limpia el sudor de las cejas.>$B$BLo más gordo del trabajo está hecho pero para iniciar la magia, hay que templar la hoja.', 0),
(@ID, 'esMX', '<David se limpia el sudor de las cejas.>$B$BLo más gordo del trabajo está hecho pero para iniciar la magia, hay que templar la hoja.', 0);
-- 10677 De segundo...
-- https://es.wowhead.com/quest=10677
SET @ID := 10677;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La recomendación de hoy: molleja.', 0),
(@ID, 'esMX', 'La recomendación de hoy: molleja.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Esto es fantástico pero acabo de recibir una noticia increíble!', 0),
(@ID, 'esMX', '¡Esto es fantástico pero acabo de recibir una noticia increíble!', 0);
-- 10678 ¡El plato fuerte!
-- https://es.wowhead.com/quest=10678
SET @ID := 10678;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La recomendación de hoy: pellejo de Lomovil.', 0),
(@ID, 'esMX', 'La recomendación de hoy: pellejo de Lomovil.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Necesito un tiempo a solas, $n. ¡Gracias por toda tu ayuda!', 0),
(@ID, 'esMX', 'Necesito un tiempo a solas, $n. ¡Gracias por toda tu ayuda!', 0);
-- 10679 Templar la espada
-- https://es.wowhead.com/quest=10679
SET @ID := 10679;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has templado la espada en la lava de La Mano de Gul\'dan?', 0),
(@ID, 'esMX', '¿Has templado la espada en la lava de La Mano de Gul\'dan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien!$B$B<El herrero examina la hoja atentamente.>$B$BDiría que es una sensible mejora con respecto a las rudimentarias armas de la Legión con las que empezaste. Esta hoja no solo rajará a los demonios Illidari, sino que también funcionará contra los esbirros de la Legión.', 0),
(@ID, 'esMX', '¡Muy bien!$B$B<El herrero examina la hoja atentamente.>$B$BDiría que es una sensible mejora con respecto a las rudimentarias armas de la Legión con las que empezaste. Esta hoja no solo rajará a los demonios Illidari, sino que también funcionará contra los esbirros de la Legión.', 0);
-- La Mano de Gul'dan
-- 10680, 10681
-- https://es.wowhead.com/quest=10680
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10680, 10681) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10680, 'esES', 'Qué bien que hayas venido, $r. Tenemos mucho trabajo pendiente.', 0),
(10681, 'esES', 'Qué bien que hayas venido, $r. Tenemos mucho trabajo pendiente.', 0),
(10680, 'esMX', 'Qué bien que hayas venido, $r. Tenemos mucho trabajo pendiente.', 0),
(10681, 'esMX', 'Qué bien que hayas venido, $r. Tenemos mucho trabajo pendiente.', 0);
-- 10682 Tiempos de negociación...
-- https://es.wowhead.com/quest=10682
SET @ID := 10682;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Está todo bien?', 0),
(@ID, 'esMX', '¿Está todo bien?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡¿QUÉ?! ¿Te despacharon a ti y a nuestras propuestas inmediatamente?$B$B¡Esto es indignante! Acudimos a ellos de buena fe y, ¿te rechazan sin intentar llegar a un acuerdo?$B$BBueno, ¡pues ahora verán!', 0),
(@ID, 'esMX', '¡¿QUÉ?! ¿Te despacharon a ti y a nuestras propuestas inmediatamente?$B$B¡Esto es indignante! Acudimos a ellos de buena fe y, ¿te rechazan sin intentar llegar a un acuerdo?$B$BBueno, ¡pues ahora verán!', 0);
-- 10684 Oronu el Anciano
-- https://es.wowhead.com/quest=10684
SET @ID := 10684;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Alguna novedad, $n? El tiempo apremia.', 0),
(@ID, 'esMX', '¿Alguna novedad, $n? El tiempo apremia.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Es la letra de Akama... a ver de qué podemos enterarnos.', 0),
(@ID, 'esMX', 'Es la letra de Akama... a ver de qué podemos enterarnos.', 0);
-- 10685 Los corruptores Lengua de Ceniza
-- https://es.wowhead.com/quest=10685
SET @ID := 10685;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los 4 trozos del medallón, $n?', 0),
(@ID, 'esMX', '¿Has conseguido los 4 trozos del medallón, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! Los 4 trozos del medallón. Ahora a unirlos...', 0),
(@ID, 'esMX', '¡Eso es! Los 4 trozos del medallón. Ahora a unirlos...', 0);
-- 10686 La Jaula de la Guardiana
-- https://es.wowhead.com/quest=10686
SET @ID := 10686;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te estábamos esperando, $n. Akama dijo que vendrías tarde o temprano.', 0),
(@ID, 'esMX', 'Te estábamos esperando, $n. Akama dijo que vendrías tarde o temprano.', 0);
-- 10687 Patio de Armas de Karabor
-- https://es.wowhead.com/quest=10687
SET @ID := 10687;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te encargué, $n?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te encargué, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Examinemos estas armas, $n. Mmmm... Esto es bastante preocupante.', 0),
(@ID, 'esMX', 'Examinemos estas armas, $n. Mmmm... Esto es bastante preocupante.', 0);
-- 10688 Una distracción necesaria
-- https://es.wowhead.com/quest=10688
SET @ID := 10688;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Azaloth liberado', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado la tarea que te pedí?', 0),
(@ID, 'esMX', '¿Has completado la tarea que te pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esperemos que esa distracción nos haya dado el tiempo que necesitamos para obtener más información.', 0),
(@ID, 'esMX', 'Esperemos que esa distracción nos haya dado el tiempo que necesitamos para obtener más información.', 0);
-- 10689 Altruis
-- https://es.wowhead.com/quest=10689
SET @ID := 10689;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has recorrido un largo camino, $gforastero:forastera;. Me sorprende que quienquiera que te enviara haya oído hablar de mí.', 0),
(@ID, 'esMX', 'Has recorrido un largo camino, $gforastero:forastera;. Me sorprende que quienquiera que te enviara haya oído hablar de mí.', 0);
-- 10690 La madre del cubil
-- https://es.wowhead.com/quest=10690
SET @ID := 10690;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué puedo hacer hoy por ti?', 0),
(@ID, 'esMX', '¿Qué puedo hacer hoy por ti?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Increíble. ¿Mataste a Rema tú $gsolo:sola;?$B$BPor tu aspecto, diría que sí. Sabes, estamos buscando a $gun:una; $c joven y fuerte, como tú, para que nos ayude, especialmente con los problemas que tenemos continuamente con los ogros. Asegúrate de que exploras conmigo esa posibilidad.$B$BBueno, sin duda te has ganado la recompensa que puse en ese cartel de "Se busca".$B$BPor favor, tómala.', 0),
(@ID, 'esMX', 'Increíble. ¿Mataste a Rema tú $gsolo:sola;?$B$BPor tu aspecto, diría que sí. Sabes, estamos buscando a $gun:una; $c joven y fuerte, como tú, para que nos ayude, especialmente con los problemas que tenemos continuamente con los ogros. Asegúrate de que exploras conmigo esa posibilidad.$B$BBueno, sin duda te has ganado la recompensa que puse en ese cartel de "Se busca".$B$BPor favor, tómala.', 0);
-- 10691 Regresa junto a los Arúspices
-- https://es.wowhead.com/quest=10691
SET @ID := 10691;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchos pagarían un buen dinero por el libro que llevas. Lástima que haya que destruirlo.', 0),
(@ID, 'esMX', 'Muchos pagarían un buen dinero por el libro que llevas. Lástima que haya que destruirlo.', 0);
-- 10692 Hay que detener a Varedis
-- https://es.wowhead.com/quest=10692
SET @ID := 10692;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has completado lo que te pedí, $n?', 0),
(@ID, 'esMX', '¿Has completado lo que te pedí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Bien hecho, $n! Al matar a Varedis has acabado con uno de los proyectos más peligrosos de Illidan.$B$BSe hablará de ti por todas partes.$B$BDéjame que coja el Libro de Nombres Viles. Me desharé de él... adecuadamente...', 0),
(@ID, 'esMX', '¡Bien hecho, $n! Al matar a Varedis has acabado con uno de los proyectos más peligrosos de Illidan.$B$BSe hablará de ti por todas partes.$B$BDéjame que coja el Libro de Nombres Viles. Me desharé de él... adecuadamente...', 0);
