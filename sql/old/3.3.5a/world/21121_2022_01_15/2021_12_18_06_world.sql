-- 10742 Enfrentamiento
-- https://es.wowhead.com/quest=10742
SET @ID := 10742;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Solo con la muerte de Goc y Gorgrom el Comedragones podremos liberar a los Mok\'Nathal.', 0),
(@ID, 'esMX', 'Solo con la muerte de Goc y Gorgrom el Comedragones podremos liberar a los Mok\'Nathal.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'La batalla ha sido dura y lo has hecho bien, $n. Me honra poder haber luchado a tu lado contra Goc. No tengo palabras para expresar mi agradecimiento.$B$BLos Mok\'Nathal deberían saber esto, pero todavía no me siento con fuerzas para verles. Conozco a mi padre y conozco mi corazón. Todavía tengo que aprender mucho y hacerme más fuerte para demostrarle que soy su verdadero hijo.', 0),
(@ID, 'esMX', 'La batalla ha sido dura y lo has hecho bien, $n. Me honra poder haber luchado a tu lado contra Goc. No tengo palabras para expresar mi agradecimiento.$B$BLos Mok\'Nathal deberían saber esto, pero todavía no me siento con fuerzas para verles. Conozco a mi padre y conozco mi corazón. Todavía tengo que aprender mucho y hacerme más fuerte para demostrarle que soy su verdadero hijo.', 0);
-- 10744 Noticias victoriosas
-- https://es.wowhead.com/quest=10744
SET @ID := 10744;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<Kurdran escucha tu informe.>$B$BCiertamente son buenas noticias. Hace tan solo unos días, no habría ni soñado que podríamos romper el asedio de la Legión.$B$BNo solo has detenido su ofensiva, sino que has destrozado su máquina de guerra. Tienes la gratitud del clan Martillo Salvaje por tu valor, $n.', 0),
(@ID, 'esMX', '<Kurdran escucha tu informe.>$B$BCiertamente son buenas noticias. Hace tan solo unos días, no habría ni soñado que podríamos romper el asedio de la Legión.$B$BNo solo has detenido su ofensiva, sino que has destrozado su máquina de guerra. Tienes la gratitud del clan Martillo Salvaje por tu valor, $n.', 0);
-- 10745 Noticias victoriosas
-- https://es.wowhead.com/quest=10745
SET @ID := 10745;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El señor supremo te escucha atentamente.>$B$B¡Excelentes noticias! Mantener la posición contra los infernales de la Legión nos estaba dejando casi sin recursos. No es que esperase que mis hombres cayeran, pero realmente estaban agotados.$B$BHoy has demostrado tu lealtad con la Horda. La guardia de Kor\'kron se sentirá honrada si puede luchar a tu lado algún día.', 0),
(@ID, 'esMX', '<El señor supremo te escucha atentamente.>$B$B¡Excelentes noticias! Mantener la posición contra los infernales de la Legión nos estaba dejando casi sin recursos. No es que esperase que mis hombres cayeran, pero realmente estaban agotados.$B$BHoy has demostrado tu lealtad con la Horda. La guardia de Kor\'kron se sentirá honrada si puede luchar a tu lado algún día.', 0);
-- 10747 Crías Culto Vermis
-- https://es.wowhead.com/quest=10747
SET @ID := 10747;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has tenido muchos problemas para encontrar las crías? ¡Espero que no te quemases!', 0),
(@ID, 'esMX', '¿Has tenido muchos problemas para encontrar las crías? ¡Espero que no te quemases!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Oh, cielos! Son más de las que esperaba. Ciertamente tu heroicidad merece alabanzas.$B$BTengo entre manos una buena camada de crías negras para empezar. Para examinarlas, quiero decir.$B$BPor favor, acepta esto como pago. ¡Insisto!', 0),
(@ID, 'esMX', '¡Oh, cielos! Son más de las que esperaba. Ciertamente tu heroicidad merece alabanzas.$B$BTengo entre manos una buena camada de crías negras para empezar. Para examinarlas, quiero decir.$B$BPor favor, acepta esto como pago. ¡Insisto!', 0);
-- 10748 ¡Maxnar debe morir!
-- https://es.wowhead.com/quest=10748
SET @ID := 10748;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya trataste con Maxnar the Fauceniza?$B$B¿Tienes problemas para encontrarlo? Según tengo entendido, si te diriges a la derecha una vez que entras en sus cavernas, el camino se doblará y te llevará hacia él.', 0),
(@ID, 'esMX', '¿Ya trataste con Maxnar the Fauceniza?$B$B¿Tienes problemas para encontrarlo? Según tengo entendido, si te diriges a la derecha una vez que entras en sus cavernas, el camino se doblará y te llevará hacia él.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ahora podemos estar más tranquilos sabiendo que el líder de nuestro enemigo está muerto. No solo eso, sino que has salvado toda la montaña de los depredadores.$B$BFueran cuales fueran sus objetivos, ¡has hecho que ya no los tengan!$B$BTienes nuestra más inmensa gratitud, $n. Por favor, acepta esta muestra de gratitud, así como nuestra eterna hospitalidad.', 0),
(@ID, 'esMX', 'Ahora podemos estar más tranquilos sabiendo que el líder de nuestro enemigo está muerto. No solo eso, sino que has salvado toda la montaña de los depredadores.$B$BFueran cuales fueran sus objetivos, ¡has hecho que ya no los tengan!$B$BTienes nuestra más inmensa gratitud, $n. Por favor, acepta esta muestra de gratitud, así como nuestra eterna hospitalidad.', 0);
-- 10749 El veneno del Barón Sablecrín
-- https://es.wowhead.com/quest=10749
SET @ID := 10749;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$c, ¿has vuelto tan pronto? ¿Tienes el veneno?', 0),
(@ID, 'esMX', '$c, ¿has vuelto tan pronto? ¿Tienes el veneno?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto de usar venenos no me gusta nada, pero servirá para lo que queremos.', 0),
(@ID, 'esMX', 'Esto de usar venenos no me gusta nada, pero servirá para lo que queremos.', 0);
-- El Sendero de la Conquista
-- 10750, 10772
-- https://es.wowhead.com/quest=10750
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10750, 10772) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10750, 'esES', '¿Qué tienes que informar, soldado?', 0),
(10772, 'esES', '¿Qué tienes que informar, soldado?', 0),
(10750, 'esMX', '¿Qué tienes que informar, soldado?', 0),
(10772, 'esMX', '¿Qué tienes que informar, soldado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10750, 10772) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10750, 'esES', 'Cierto, esas crías son terriblemente molestas. Debemos investigar más a fondo...', 0),
(10772, 'esES', 'Cierto, esas crías son terriblemente molestas. Debemos investigar más a fondo...', 0),
(10750, 'esMX', 'Cierto, esas crías son terriblemente molestas. Debemos investigar más a fondo...', 0),
(10772, 'esMX', 'Cierto, esas crías son terriblemente molestas. Debemos investigar más a fondo...', 0);
-- Despejar el camino
-- 10751, 10773
-- https://es.wowhead.com/quest=10751
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10751, 10773) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10751, 'esES', '¿Qué tienes que informar, soldado?', 0),
(10773, 'esES', '¿Qué tienes que informar, soldado?', 0),
(10751, 'esMX', '¿Qué tienes que informar, soldado?', 0),
(10773, 'esMX', '¿Qué tienes que informar, soldado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10751, 10773) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10751, 'esES', 'Esto es increíble.', 0),
(10773, 'esES', 'Esto es increíble.', 0),
(10751, 'esMX', 'Esto es increíble.', 0),
(10773, 'esMX', 'Esto es increíble.', 0);
-- 10753 Matanza de las criaturas
-- https://es.wowhead.com/quest=10753
SET @ID := 10753;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho valer la mano de la justicia?', 0),
(@ID, 'esMX', '¿Has hecho valer la mano de la justicia?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No me siento orgullosa de destruir lo que había creado Elune, pero era necesario detener la corrupción. Has hecho bien, $c.', 0),
(@ID, 'esMX', 'No me siento orgullosa de destruir lo que había creado Elune, pero era necesario detener la corrupción. Has hecho bien, $c.', 0);
-- 10754 Entrada a la Ciudadela
-- https://es.tbc.wowhead.com/quest=10754
SET @ID := 10754;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que mostrarme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que mostrarme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Será cierto? Deja que eche un vistazo más de cerca a ese molde.', 0),
(@ID, 'esMX', '¿Será cierto? Deja que eche un vistazo más de cerca a ese molde.', 0);
-- 10755 Entrada a la Ciudadela
-- https://es.tbc.wowhead.com/quest=10755
SET @ID := 10755;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes algo que mostrarme, $n?', 0),
(@ID, 'esMX', '¿Tienes algo que mostrarme, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Un molde de llave? ¿Podría ser lo que nos conceda el acceso a Las Salas Arrasadas?', 0),
(@ID, 'esMX', '¿Un molde de llave? ¿Podría ser lo que nos conceda el acceso a Las Salas Arrasadas?', 0);
-- 10756 Gran maestro Rohok
-- https://es.tbc.wowhead.com/quest=10756
SET @ID := 10756;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto?', 0),
(@ID, 'esMX', '¿Qué es esto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Nazgrel quiere que le forje una lleve? ¿Se olvida de que estamos en un campo de batalla? ¡Tengo espadas y lanzas en las que trabajar!', 0),
(@ID, 'esMX', '¿Nazgrel quiere que le forje una lleve? ¿Se olvida de que estamos en un campo de batalla? ¡Tengo espadas y lanzas en las que trabajar!', 0);
-- 10757 La petición de Rohok
-- https://es.tbc.wowhead.com/quest=10757
SET @ID := 10757;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya tienes los materiales que te he pedido?', 0),
(@ID, 'esMX', '¿Ya tienes los materiales que te he pedido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Fantástico. Vamos a probar.', 0),
(@ID, 'esMX', 'Fantástico. Vamos a probar.', 0);
-- 10758 Más caliente que el infierno
-- https://es.tbc.wowhead.com/quest=10758
SET @ID := 10758;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has hecho lo que te he pedido, $c?', 0),
(@ID, 'esMX', '¿Has hecho lo que te he pedido, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has conseguido! Lo único que te queda hacer ahora es probarlo.', 0),
(@ID, 'esMX', '¡Lo has conseguido! Lo único que te queda hacer ahora es probarlo.', 0);
-- Encuentra al desertor
-- 10759, 10761
-- https://es.wowhead.com/quest=10759
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10759, 10761) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10759, 'esES', '<El arakkoa ríe.>$B$BSí, soy el desertor que se menciona en el diario del comandante. He estado esperando el día en que otros reconocieran la amenaza que suponen aquellos que antaño llamaba hermanos.', 0),
(10761, 'esES', '<El arakkoa ríe.>$B$BSí, soy el desertor que se menciona en el diario del comandante. He estado esperando el día en que otros reconocieran la amenaza que suponen aquellos que antaño llamaba hermanos.', 0),
(10759, 'esMX', '<El arakkoa ríe.>$B$BSí, soy el desertor que se menciona en el diario del comandante. He estado esperando el día en que otros reconocieran la amenaza que suponen aquellos que antaño llamaba hermanos.', 0),
(10761, 'esMX', '<El arakkoa ríe.>$B$BSí, soy el desertor que se menciona en el diario del comandante. He estado esperando el día en que otros reconocieran la amenaza que suponen aquellos que antaño llamaba hermanos.', 0);
-- 10760 Las Ruinas de Sketh'lon
-- https://es.wowhead.com/quest=10760
-- https://es.tbc.wowhead.com/quest=10760
SET @ID := 10760;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué has descubierto?', 0),
(@ID, 'esMX', '¿Qué has descubierto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '<El sargento examina las páginas del diario.>$B$BNo veo gran cosa de utilidad aquí, pero hay un par de entradas que podrían ser útiles. Parece como si esos arakkoa estuvieran preparando algún tipo de ritual mágico complicado hasta el momento de su muerte, pero ¿por qué? También hay una nota curiosa sobre un "desertor".', 0),
(@ID, 'esMX', '<El sargento examina las páginas del diario.>$B$BNo veo gran cosa de utilidad aquí, pero hay un par de entradas que podrían ser útiles. Parece como si esos arakkoa estuvieran preparando algún tipo de ritual mágico complicado hasta el momento de su muerte, pero ¿por qué? También hay una nota curiosa sobre un "desertor".', 0);
-- 10762 Gran Maestro Dumphry
-- https://es.tbc.wowhead.com/quest=10762
SET @ID := 10762;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué es esto?', 0),
(@ID, 'esMX', '¿Qué es esto?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Una llave? ¡Danath tenernos trabajando en máquinas de asedio!', 0),
(@ID, 'esMX', '¿Una llave? ¡Danath tenernos trabajando en máquinas de asedio!', 0);
-- 10763 La petición de Dumphry
-- https://es.tbc.wowhead.com/quest=10763
SET @ID := 10763;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has conseguido los materiales que pedí?', 0),
(@ID, 'esMX', '¿Has conseguido los materiales que pedí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces vamos a probarlo. Veamos en qué consiste la artesanía de los orcos viles.', 0),
(@ID, 'esMX', 'Entonces vamos a probarlo. Veamos en qué consiste la artesanía de los orcos viles.', 0);
-- 10764 Más caliente que el infierno
-- https://es.tbc.wowhead.com/quest=10764
SET @ID := 10764;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Hiciste lo que te pedí, $c?', 0),
(@ID, 'esMX', '¿Hiciste lo que te pedí, $c?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has hecho, $gmuchacho:muchacha;! ¡Lo único que falta por hacer es que la lleves a la Ciudadela del Fuego Infernal y mates a algunos orcos!', 0),
(@ID, 'esMX', '¡Lo has hecho, $gmuchacho:muchacha;! ¡Lo único que falta por hacer es que la lleves a la Ciudadela del Fuego Infernal y mates a algunos orcos!', 0);
-- 10765 Enfrentamiento verbal...
-- https://es.wowhead.com/quest=10765
SET @ID := 10765;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes, soldado?', 0),
(@ID, 'esMX', '¿Qué noticias traes, soldado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que están intentando conseguir el favor de los gigantes, eh? Tengo un plan para acabar con esa alianza impía.', 0),
(@ID, 'esMX', '¿Así que están intentando conseguir el favor de los gigantes, eh? Tengo un plan para acabar con esa alianza impía.', 0);
-- 10766 Punto de Invasión: Cataclismo
-- https://es.wowhead.com/quest=10766
SET @ID := 10766;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Encantado de conocerte, $n. Me llamo Plexi.$B$BNo te aburriré con formalidades. Ambos sabemos por qué estamos aquí. Pongámonos a trabajar.', 0),
(@ID, 'esMX', 'Encantado de conocerte, $n. Me llamo Plexi.$B$BNo te aburriré con formalidades. Ambos sabemos por qué estamos aquí. Pongámonos a trabajar.', 0);
-- 10767 Punto de Invasión: Cataclismo
-- https://es.wowhead.com/quest=10767
-- https://es.tbc.wowhead.com/quest=10767
SET @ID := 10767;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Debes de ser $gel:la; $r que el guardia de sangre Gulmok me dijo que esperara. Tengo un plan en mente, pero necesitaré tu ayuda para completar los preparativos.', 0),
(@ID, 'esMX', 'Debes de ser $gel:la; $r que el guardia de sangre Gulmok me dijo que esperara. Tengo un plan en mente, pero necesitaré tu ayuda para completar los preparativos.', 0);
-- Tabardos de los Illidari
-- 10768, 10775
-- https://es.wowhead.com/quest=10768
DELETE FROM `quest_request_items_locale` WHERE `id` IN(10768, 10775) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(10768, 'esES', '¿Qué noticias traes, soldado?', 0),
(10775, 'esES', '¿Qué noticias traes, soldado?', 0),
(10768, 'esMX', '¿Qué noticias traes, soldado?', 0),
(10775, 'esMX', '¿Qué noticias traes, soldado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(10768, 10775) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(10768, 'esES', '¡Ajá! ¡Son perfectos!', 0),
(10775, 'esES', '¡Ajá! ¡Son perfectos!', 0),
(10768, 'esMX', '¡Ajá! ¡Son perfectos!', 0),
(10775, 'esMX', '¡Ajá! ¡Son perfectos!', 0);
-- 10769 Disensión en las filas…
-- https://es.wowhead.com/quest=10769
SET @ID := 10769;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Coloso enloquecido asesinado mientras llevas el disfraz', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, bien, bien... si es $gel bruto:la bruta; que envié al campo. Has vuelto y estás de una pieza.$B$B<Or\'barokh asiente.>$B$BSabía que no me decepcionarías, soldado. Has detenido un peligroso avance Illidari y, al hacerlo, te has ganado una pequeña recompensa.', 0),
(@ID, 'esMX', 'Bien, bien, bien... si es $gel bruto:la bruta; que envié al campo. Has vuelto y estás de una pieza.$B$B<Or\'barokh asiente.>$B$BSabía que no me decepcionarías, soldado. Has detenido un peligroso avance Illidari y, al hacerlo, te has ganado una pequeña recompensa.', 0);
-- 10770 Pequeñas ascuas
-- https://es.tbc.wowhead.com/quest=10770
SET @ID := 10770;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Pronto dormiré el sueño profundo del bosque. Antes de cavar profundamente mis raíces y cerrar estos viejos ojos para siempre, espero saber que esos desgraciados diablillos sufrieron y perecieron.', 0),
(@ID, 'esMX', 'Pronto dormiré el sueño profundo del bosque. Antes de cavar profundamente mis raíces y cerrar estos viejos ojos para siempre, espero saber que esos desgraciados diablillos sufrieron y perecieron.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hay tantos que es imposible matarlos a todos, pero tú me has dado esperanza. Quizás debería seguir intentándolo un par de siglos más para poder revivir mi amado bosque.', 0),
(@ID, 'esMX', 'Hay tantos que es imposible matarlos a todos, pero tú me has dado esperanza. Quizás debería seguir intentándolo un par de siglos más para poder revivir mi amado bosque.', 0);
-- 10771 Desde las cenizas
-- https://es.wowhead.com/quest=10771
SET @ID := 10771;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Tierra volcánica del sur', `ObjectiveText2` = 'Tierra volcánica central', `ObjectiveText3` = 'Tierra volcánica del norte', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho? ¿Has devuelto la vida a mi antiguo hogar?', 0),
(@ID, 'esMX', '¿Lo has hecho? ¿Has devuelto la vida a mi antiguo hogar?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has destruido muchas criaturillas sucias de esas. Ya puedo descansar mejor.', 0),
(@ID, 'esMX', 'Has destruido muchas criaturillas sucias de esas. Ya puedo descansar mejor.', 0);
-- 10774 Elfo de sangre gigante = ???
-- https://es.wowhead.com/quest=10774
SET @ID := 10774;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes, soldado?', 0),
(@ID, 'esMX', '¿Qué noticias traes, soldado?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que están intentando conseguir el favor de los gigantes, eh? Tengo un plan para acabar con esa alianza impía.', 0),
(@ID, 'esMX', '¿Así que están intentando conseguir el favor de los gigantes, eh? Tengo un plan para acabar con esa alianza impía.', 0);
-- 10776 Disensión en las filas…
-- https://es.wowhead.com/quest=10776
SET @ID := 10776;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Coloso enloquecido asesinado mientras llevas el disfraz', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto!', 0),
(@ID, 'esMX', '¡Has vuelto!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien, bien, bien... si es $gel:la; soldado que envié al campo. Has vuelto y estás de una pieza.$B$B<Yoregar asiente.>$B$BSabía que no me decepcionarías, soldado. Has detenido un peligroso avance Illidari y, al hacerlo, te has ganado una pequeña recompensa.', 0),
(@ID, 'esMX', 'Bien, bien, bien... si es $gel:la; soldado que envié al campo. Has vuelto y estás de una pieza.$B$B<Yoregar asiente.>$B$BSabía que no me decepcionarías, soldado. Has detenido un peligroso avance Illidari y, al hacerlo, te has ganado una pequeña recompensa.', 0);
