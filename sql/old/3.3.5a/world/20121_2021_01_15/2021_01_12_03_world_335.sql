-- 1684 Elanaria
-- https://es.classic.wowhead.com/quest=1684
SET @ID := 1684;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Un saludo, $n. Tu nombre suena fuerte en Darnassus, porque eres $gprometedor:prometedora;. Pero pronto veremos si posees la fuerza de voluntad para seguir el camino del $c.', 0),
(@ID, 'esMX', 'Un saludo, $n. Tu nombre suena fuerte en Darnassus, porque eres $gprometedor:prometedora;. Pero pronto veremos si posees la fuerza de voluntad para seguir el camino del $c.', 0);
-- 1686 La sombra de Elura
-- https://es.classic.wowhead.com/quest=1686
SET @ID := 1686;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has vencido a la Sombra de Elura, $n? ¿Tienes el mineral de elunita perdido?', 0),
(@ID, 'esMX', '¿Has vencido a la Sombra de Elura, $n? ¿Tienes el mineral de elunita perdido?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has sido muy valiente, $n.$B$BHas dado a la Sombra de Elura la paz que merecía y utilizaremos la elunita para hacerte una magnífica arma.', 0),
(@ID, 'esMX', 'Has sido muy valiente, $n.$B$BHas dado a la Sombra de Elura la paz que merecía y utilizaremos la elunita para hacerte una magnífica arma.', 0);
-- 1687 El faro fantasma
-- https://es.classic.wowhead.com/quest=1687
SET @ID := 1687;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ya llegamos?', 0),
(@ID, 'esMX', '¿Ya llegamos?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡GUAU, ese era un fantasma de la vida real! Eso fue tan asombroso, no puedo esperar para contárselo a todos en el orfanato. Capitán Grayson... ¡incluso parecía un pirata! ¡Cuando sea mayor, también quiero ser un pirata fantasma!$B$BGracias por llevarme a Páramos de Poniente, $n. Sé que hay cosas aterradoras en la naturaleza de Páramos de Poniente, y espero no haber sido demasiado molesto. ¡Eres increíble!', 0),
(@ID, 'esMX', '¡GUAU, ese era un fantasma de la vida real! Eso fue tan asombroso, no puedo esperar para contárselo a todos en el orfanato. Capitán Grayson... ¡incluso parecía un pirata! ¡Cuando sea mayor, también quiero ser un pirata fantasma!$B$BGracias por llevarme a Páramos de Poniente, $n. Sé que hay cosas aterradoras en la naturaleza de Páramos de Poniente, y espero no haber sido demasiado molesto. ¡Eres increíble!', 0);
-- 1692 Mathiel, el herrero
-- https://es.classic.wowhead.com/quest=1692
SET @ID := 1692;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos joven $c. ¿De qué pueden servirte mis habilidades?', 0),
(@ID, 'esMX', 'Saludos joven $c. ¿De qué pueden servirte mis habilidades?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, mineral de elunita. Es un metal estupendo con el que trabajar, bendecido como está por la propia diosa Elune. Será un honor fabricar armas con él.$B$BPor favor, espera mientras trabajo...', 0),
(@ID, 'esMX', 'Ah, mineral de elunita. Es un metal estupendo con el que trabajar, bendecido como está por la propia diosa Elune. Será un honor fabricar armas con él.$B$BPor favor, espera mientras trabajo...', 0);
-- 1693 Armas de Elunita
-- https://es.classic.wowhead.com/quest=1693
SET @ID := 1693;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, he hecho estas armas con la elunita que me trajiste. Por favor, coge la que te sea más útil.$B$BDebo darte las gracias. Trabajar con elunita es un honor y todo un placer.', 0),
(@ID, 'esMX', '$n, he hecho estas armas con la elunita que me trajiste. Por favor, coge la que te sea más útil.$B$BDebo darte las gracias. Trabajar con elunita es un honor y todo un placer.', 0);
-- 1698 Yorus Cebadiz
-- https://es.classic.wowhead.com/quest=1698
SET @ID := 1698;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! Así que oíste hablar de mi desafío, ¿verdad?$B$BBien, siéntate y escucha. Toma un trago y saboréalo... puede ser lo último que bebas.', 0),
(@ID, 'esMX', '¡Ja! Así que oíste hablar de mi desafío, ¿verdad?$B$BBien, siéntate y escucha. Toma un trago y saboréalo... puede ser lo último que bebas.', 0);
-- 1699 El guantelete de Rethban
-- https://es.classic.wowhead.com/quest=1699
SET @ID := 1699;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo conseguiste! ¡Bien hecho! ¡Tres hurras por $n!', 0),
(@ID, 'esMX', '¡Lo conseguiste! ¡Bien hecho! ¡Tres hurras por $n!', 0);
-- 1700 Grimand Elmore
-- https://es.classic.wowhead.com/quest=1700
SET @ID := 1700;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola. ¿Cómo puedo servirte?', 0),
(@ID, 'esMX', 'Hola. ¿Cómo puedo servirte?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Furen escribió esto? ¡Como se atreve! ¡Le enseñé todo lo que sabe! ¡Pensar que podría enseñarme algo es indignante! ¡Indignante!$B$BMmm... pero hay algo en sus notas que me gustaría probar...', 0),
(@ID, 'esMX', '¿Furen escribió esto? ¡Como se atreve! ¡Le enseñé todo lo que sabe! ¡Pensar que podría enseñarme algo es indignante! ¡Indignante!$B$BMmm... pero hay algo en sus notas que me gustaría probar...', 0);
-- 1701 Armadura de malla endurecida con fuego
-- https://es.classic.wowhead.com/quest=1701
SET @ID := 1701;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Cómo va la búsqueda del tesoro, $n? ¿Tienes los materiales?', 0),
(@ID, 'esMX', '¿Cómo va la búsqueda del tesoro, $n? ¿Tienes los materiales?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo tienes todo? ¡Asombroso! ¡Tenía miedo de que esas quimeras te devoraran!$B$BBueno, comencemos con esa armadura...', 0),
(@ID, 'esMX', '¿Lo tienes todo? ¡Asombroso! ¡Tenía miedo de que esas quimeras te devoraran!$B$BBueno, comencemos con esa armadura...', 0);
-- 1702 El forjador de escudos
-- https://es.classic.wowhead.com/quest=1702
SET @ID := 1702;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola! Qué sequía, ¿no te parece?', 0),
(@ID, 'esMX', '¡Hola! Qué sequía, ¿no te parece?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, brebaje de Cebadiz. ¡Es estupendo! ¿Así que has venido a ver a Yorus, eh?$B$B¡Puedo conseguirte un escudo, sí señor! No encontrarás ninguno mejor, ¡y no estoy mintiendo!', 0),
(@ID, 'esMX', 'Ah, brebaje de Cebadiz. ¡Es estupendo! ¿Así que has venido a ver a Yorus, eh?$B$B¡Puedo conseguirte un escudo, sí señor! No encontrarás ninguno mejor, ¡y no estoy mintiendo!', 0);
-- 1703 Mathiel
-- https://es.classic.wowhead.com/quest=1703
SET @ID := 1703;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te saludo, $c.', 0),
(@ID, 'esMX', 'Te saludo, $c.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son interesantes, muy interesantes de hecho. ¡Mi colega enano Furen ha hecho un gran descubrimiento!$B$BGracias, $n. Será un honor aplicar sus nuevas técnicas a mis propias creaciones.', 0),
(@ID, 'esMX', 'Estos son interesantes, muy interesantes de hecho. ¡Mi colega enano Furen ha hecho un gran descubrimiento!$B$BGracias, $n. Será un honor aplicar sus nuevas técnicas a mis propias creaciones.', 0);
-- 1704 Klockmort Palmalicate
-- https://es.classic.wowhead.com/quest=1704
SET @ID := 1704;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen día, o mañana o noche. No puedo decirlo desde aquí. Entonces, ¿tienes negocios para mí?', 0),
(@ID, 'esMX', 'Buen día, o mañana o noche. No puedo decirlo desde aquí. Entonces, ¿tienes negocios para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Estas notas son increíbles! Y lo que es más... ¡son increíbles y son estupendas y me hacen temblar las rodillas!$B$B¡Furen tuvo un gran avance! ¡Un verdadero avance! ¡No puedo esperar para probar su nueva técnica!', 0),
(@ID, 'esMX', '¡Estas notas son increíbles! Y lo que es más... ¡son increíbles y son estupendas y me hacen temblar las rodillas!$B$B¡Furen tuvo un gran avance! ¡Un verdadero avance! ¡No puedo esperar para probar su nueva técnica!', 0);
-- 1705 Sangre ardiente
-- https://es.classic.wowhead.com/quest=1705
SET @ID := 1705;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¿tienes la sangre y la roca ardiente? Los necesitaré para completar la armadura.', 0),
(@ID, 'esMX', '$n, ¿tienes la sangre y la roca ardiente? Los necesitaré para completar la armadura.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo! Ahora, si me disculpas, tengo trabajo que hacer yo mismo...', 0),
(@ID, 'esMX', '¡Buen trabajo! Ahora, si me disculpas, tengo trabajo que hacer yo mismo...', 0);
-- 1706 La armadura de Grimand
-- https://es.classic.wowhead.com/quest=1706
SET @ID := 1706;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Apenas puedo creerlo! La técnica de Furen fue un éxito, y esta armadura debería soportar tremendos niveles de estrés.$B$BAquí tienes, $n. Y gracias. No habría creído el descubrimiento de Furen si no hubieras reunido los materiales que necesitaba para probarlo yo mismo.', 0),
(@ID, 'esMX', '¡Apenas puedo creerlo! La técnica de Furen fue un éxito, y esta armadura debería soportar tremendos niveles de estrés.$B$BAquí tienes, $n. Y gracias. No habría creído el descubrimiento de Furen si no hubieras reunido los materiales que necesitaba para probarlo yo mismo.', 0);
-- 1708 Coral férreo
-- https://es.classic.wowhead.com/quest=1708
SET @ID := 1708;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Hola, hola, $n! ¿Tienes el coral férreo? ¡No puedo esperar para ir a trabajar!', 0),
(@ID, 'esMX', '¡Hola, hola, $n! ¿Tienes el coral férreo? ¡No puedo esperar para ir a trabajar!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Eso es! ¡Bien hecho! ¡Ahora déjame hacer esto fundido y martillado para que pueda aplicar la técnica de Furen con la mía y luego veremos qué pasa!$B$B¡Oh, Dios mío! ¡Solo sé que la armadura será muy muy muy resistente!', 0),
(@ID, 'esMX', '¡Eso es! ¡Bien hecho! ¡Ahora déjame hacer esto fundido y martillado para que pueda aplicar la técnica de Furen con la mía y luego veremos qué pasa!$B$B¡Oh, Dios mío! ¡Solo sé que la armadura será muy muy muy resistente!', 0);
-- 1709 La creación de Klockmort
-- https://es.classic.wowhead.com/quest=1709
SET @ID := 1709;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está tu armadura, $n. ¡El proceso de Furen funcionó de manera brillante! ¡Perfectamente! ¡Maravillosamente, de verdad!$B$B¡Podrías aplastar esta armadura con un motor de asedio y volvería a tomar forma!', 0),
(@ID, 'esMX', 'Aquí está tu armadura, $n. ¡El proceso de Furen funcionó de manera brillante! ¡Perfectamente! ¡Maravillosamente, de verdad!$B$B¡Podrías aplastar esta armadura con un motor de asedio y volvería a tomar forma!', 0);
-- 1710 Cáscaras asoladas
-- https://es.classic.wowhead.com/quest=1710
SET @ID := 1710;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes las cascaras, $n? Son bastante fuertes y se pueden convertir en una laca que usaré para revestir los eslabones de mi nueva armadura de malla.', 0),
(@ID, 'esMX', '¿Tienes las cascaras, $n? Son bastante fuertes y se pueden convertir en una laca que usaré para revestir los eslabones de mi nueva armadura de malla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah gracias. ¡Estos funcionarán espléndidamente!$B$BComenzaré a modelar la armadura de inmediato...', 0),
(@ID, 'esMX', 'Ah gracias. ¡Estos funcionarán espléndidamente!$B$BComenzaré a modelar la armadura de inmediato...', 0);
-- 1711 La armadura de Mathiel
-- https://es.classic.wowhead.com/quest=1711
SET @ID := 1711;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'He terminado con tu pieza de armadura y estoy bastante satisfecho. Las nuevas técnicas de Furen encajaron perfectamente con las mías y estoy seguro de que esta armadura demostrará ser bastante resistente.$B$BGracias, $n. Y que esto te sirva bien en futuras batallas.', 0),
(@ID, 'esMX', 'He terminado con tu pieza de armadura y estoy bastante satisfecho. Las nuevas técnicas de Furen encajaron perfectamente con las mías y estoy seguro de que esta armadura demostrará ser bastante resistente.$B$BGracias, $n. Y que esto te sirva bien en futuras batallas.', 0);
-- 1712 Ciclonio
-- https://es.classic.wowhead.com/quest=1712
SET @ID := 1712;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes los objetos, $n? Reúnelos para demostrarme que tienes la fuerza necesaria para enfrentarte a Ciclonio.', 0),
(@ID, 'esMX', '¿Tienes los objetos, $n? Reúnelos para demostrarme que tienes la fuerza necesaria para enfrentarte a Ciclonio.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has reunido los objetos para mi hechizo y has demostrado fuerza y astucia. Pero el siguiente paso de nuestra búsqueda es aún más peligroso.$B$BEsperemos que tu fuerza no falle.', 0),
(@ID, 'esMX', 'Has reunido los objetos para mi hechizo y has demostrado fuerza y astucia. Pero el siguiente paso de nuestra búsqueda es aún más peligroso.$B$BEsperemos que tu fuerza no falle.', 0);
-- 1713 La invocación
-- https://es.classic.wowhead.com/quest=1713
SET @ID := 1713;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '$n, ¡necesito el corazón de espirálico!', 0),
(@ID, 'esMX', '$n, ¡necesito el corazón de espirálico!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo lograste! ¡Venciste a Ciclonio y te hiciste con el corazón de espirálico!', 0),
(@ID, 'esMX', '¡Lo lograste! ¡Venciste a Ciclonio y te hiciste con el corazón de espirálico!', 0);
-- 1714 Esencia del exilio
-- https://es.classic.wowhead.com/quest=1714
SET @ID := 1714;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El caldero burbujea. Sus vapores llaman...', 0),
(@ID, 'esMX', 'El caldero burbujea. Sus vapores llaman...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los talismanes se hunden lentamente en el caldero...$B$BUna gran burbuja se eleva hasta la superficie del líquido y estalla...$B$B...Y aparece un grumo de roca de magma.', 0),
(@ID, 'esMX', 'Los talismanes se hunden lentamente en el caldero...$B$BUna gran burbuja se eleva hasta la superficie del líquido y estalla...$B$B...Y aparece un grumo de roca de magma.', 0);
-- 1716 Devoradora de almas
-- https://es.classic.wowhead.com/quest=1716
SET @ID := 1716;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Ha sido un viaje difícil, $n? Has venido desde muy lejos para hablar conmigo. Pero no temas, sé por qué te ha enviado Gakin y ha hecho bien, porque yo puedo ayudarte.', 0),
(@ID, 'esMX', '¿Ha sido un viaje difícil, $n? Has venido desde muy lejos para hablar conmigo. Pero no temas, sé por qué te ha enviado Gakin y ha hecho bien, porque yo puedo ayudarte.', 0);
-- 1717 La invocación de Gakin
-- https://es.classic.wowhead.com/quest=1717
SET @ID := 1717;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ya era hora de que aparecieras. Aunque, quizás debería haber enviado a alguien más capaz que Remen para encontrarte.$B$BNo importa.$B$BHas pasado demasiado tiempo sin entrenar, y un brujo sin entrenamiento no mantiene la cabeza sobre los hombros por mucho tiempo.', 0),
(@ID, 'esMX', 'Ya era hora de que aparecieras. Aunque, quizás debería haber enviado a alguien más capaz que Remen para encontrarte.$B$BNo importa.$B$BHas pasado demasiado tiempo sin entrenar, y un brujo sin entrenamiento no mantiene la cabeza sobre los hombros por mucho tiempo.', 0);
-- 1718 El isleño
-- https://es.classic.wowhead.com/quest=1718
SET @ID := 1718;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Hola $n. Me alegra ver que conseguiste llegar a Isla de Batalla. Espero que sea de tu gusto...', 0),
(@ID, 'esMX', 'Hola $n. Me alegra ver que conseguiste llegar a Isla de Batalla. Espero que sea de tu gusto...', 0);
-- 1719 La Reyerta
-- https://es.classic.wowhead.com/quest=1719
SET @ID := 1719;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, $n. ¡Has superado La Reyerta!$B$BEres $gun digno:una digna; $c y es un honor instruirte...', 0),
(@ID, 'esMX', 'Bien hecho, $n. ¡Has superado La Reyerta!$B$BEres $gun digno:una digna; $c y es un honor instruirte...', 0);
-- 1738 Duramen
-- https://es.classic.wowhead.com/quest=1738
SET @ID := 1738;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tu búsqueda fue un éxito, $n?', 0),
(@ID, 'esMX', '¿Tu búsqueda fue un éxito, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí, puedo decir que esto funcionará bien, déjame trabajar un momento con esto...$B$BTakar es un tipo ingenioso para tenerlo cerca, ¿no es así? Si tan solo pudiera persuadirlo de que regresara a la civilización.', 0),
(@ID, 'esMX', 'Sí, puedo decir que esto funcionará bien, déjame trabajar un momento con esto...$B$BTakar es un tipo ingenioso para tenerlo cerca, ¿no es así? Si tan solo pudiera persuadirlo de que regresara a la civilización.', 0);
-- 1739 El vínculo
-- https://es.classic.wowhead.com/quest=1739
SET @ID := 1739;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A veces me pregunto si Surena no era una súcubo disfrazada, enviada a deformar y retorcer mi mente... ¡Ja! Le doy demasiado crédito, creo.', 0),
(@ID, 'esMX', 'A veces me pregunto si Surena no era una súcubo disfrazada, enviada a deformar y retorcer mi mente... ¡Ja! Le doy demasiado crédito, creo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bien hecho, bien hecho, $n. Veo que hemos hecho bien al decidir entrenarte. Tu desempeño ciertamente no defrauda.$B$BNo tengo reparos en mostrarte la forma de controlar a tu súcubo recién atado. Observa con atención.', 0),
(@ID, 'esMX', 'Bien hecho, bien hecho, $n. Veo que hemos hecho bien al decidir entrenarte. Tu desempeño ciertamente no defrauda.$B$BNo tengo reparos en mostrarte la forma de controlar a tu súcubo recién atado. Observa con atención.', 0);
-- 1740 El orbe de Soran'ruk
-- https://es.classic.wowhead.com/quest=1740
SET @ID := 1740;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me tomó muchos años recolectar las piezas del orbe de Zargain, pero me ha servido bien, ya que estoy seguro de que el orbe de Soran\'ruk te servirá.', 0),
(@ID, 'esMX', 'Me tomó muchos años recolectar las piezas del orbe de Zargain, pero me ha servido bien, ya que estoy seguro de que el orbe de Soran\'ruk te servirá.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sí ... El orbe no estaba muy fragmentado y casi todas las piezas están aquí. Es muy sencillo recrearlos, hacer que Soran\'ruk vuelva a estar completo.$B$BHe dedicado mi vida al estudio de los orbes de la Legión Ardiente y su recreación. Me has hecho un favor al coleccionar estas piezas para estudiar y te las devolveré, completamente reconstruidas, en la forma que elijas.', 0),
(@ID, 'esMX', 'Sí ... El orbe no estaba muy fragmentado y casi todas las piezas están aquí. Es muy sencillo recrearlos, hacer que Soran\'ruk vuelva a estar completo.$B$BHe dedicado mi vida al estudio de los orbes de la Legión Ardiente y su recreación. Me has hecho un favor al coleccionar estas piezas para estudiar y te las devolveré, completamente reconstruidas, en la forma que elijas.', 0);
-- 1758 Libro del conciliábulo
-- https://es.classic.wowhead.com/quest=1758
SET @ID := 1758;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿El Libro del Conciliábulo? Mmm… me suena. Aunque no lo he visto nunca aquí y, te lo aseguro, me acuerdo de cada libro que leo.$B$BA ver...$B$B¡Ah, sí! He visto referencias al mismo en los libros de catalogación de la bilblioteca.', 0),
(@ID, 'esMX', '¿El Libro del Conciliábulo? Mmm… me suena. Aunque no lo he visto nunca aquí y, te lo aseguro, me acuerdo de cada libro que leo.$B$BA ver...$B$B¡Ah, sí! He visto referencias al mismo en los libros de catalogación de la bilblioteca.', 0);
-- 1778 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1778
SET @ID := 1778;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Vaya, sí que has vuelto rápido. ¿Y qué se supone que has conseguido en este tiempo?$B$B¿Conseguiste ayudar en una noble causa? Quizás hayas aprendido el valor de la caridad o algo más sobre tus obligaciones para con los habitantes de Azeroth. Dime a quién has ayudado y cómo... Impresionante, $n, desde luego, son acciones de alguien que sigue el camino de la Luz.$B$BTu sacrificio se verá recompensado con el tiempo.', 0),
(@ID, 'esMX', 'Vaya, sí que has vuelto rápido. ¿Y qué se supone que has conseguido en este tiempo?$B$B¿Conseguiste ayudar en una noble causa? Quizás hayas aprendido el valor de la caridad o algo más sobre tus obligaciones para con los habitantes de Azeroth. Dime a quién has ayudado y cómo... Impresionante, $n, desde luego, son acciones de alguien que sigue el camino de la Luz.$B$BTu sacrificio se verá recompensado con el tiempo.', 0);
-- 1779 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1779
SET @ID := 1779;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '*tose*$B$BTe deseo un buen día, $c. No prestes atención a mis heridas. Este buen sacerdote se ocupará del viejo Muiredon. Todavía no necesito el poder de ese Símbolo de la Vida que tienes ahí.$B$BDime, te envía mi mujer, ¿verdad? Lo suponía. Hablaré contigo. Te contaré qué les ocurrió a Muiredon y a su mejor amigo, Narm, un $c valiente, como tú.', 0),
(@ID, 'esMX', '*tose*$B$BTe deseo un buen día, $c. No prestes atención a mis heridas. Este buen sacerdote se ocupará del viejo Muiredon. Todavía no necesito el poder de ese Símbolo de la Vida que tienes ahí.$B$BDime, te envía mi mujer, ¿verdad? Lo suponía. Hablaré contigo. Te contaré qué les ocurrió a Muiredon y a su mejor amigo, Narm, un $c valiente, como tú.', 0);
-- 1782 La armadura de Furen
-- https://es.classic.wowhead.com/quest=1782
SET @ID := 1782;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Aquí está tu armadura, $n. ¡Esto resistirá los ataques más fuertes o mi nombre no es Furen Barbalarga!$B$BY tengo que darte las gracias. Aprendí mucho trabajando con los materiales que me trajiste. ¡Creo que algún día tendré otro gran avance!$B$BVoy a enviar lo que aprendí a otros herreros de la Alianza.$B$BLes diré que fuiste de gran ayuda y tal vez quieran devolver el favor.', 0),
(@ID, 'esMX', 'Aquí está tu armadura, $n. ¡Esto resistirá los ataques más fuertes o mi nombre no es Furen Barbalarga!$B$BY tengo que darte las gracias. Aprendí mucho trabajando con los materiales que me trajiste. ¡Creo que algún día tendré otro gran avance!$B$BVoy a enviar lo que aprendí a otros herreros de la Alianza.$B$BLes diré que fuiste de gran ayuda y tal vez quieran devolver el favor.', 0);
-- 1783 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1783
SET @ID := 1783;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No sé cómo darte las gracias, $ghermano:hermana;.$B$BVeo que llevas el Símbolo de la Vida, así que solo puedo deducir que Tiza y Muiredon te enviaron a ayudarme.$B$BCaí combatiendo contra los Hierro Negro cuando intentaba hacerme con uno de los textos. Conseguí retenerlos lo suficiente para que Muiredon escapara, pero cuando llegaste, la Luz casi me había abrazado por completo. El hecho de que tuvieras la fuerza para utilizar el Símbolo tiene mucha importancia para ti, pero ya hablaremos de eso más adelante.', 0),
(@ID, 'esMX', 'No sé cómo darte las gracias, $ghermano:hermana;.$B$BVeo que llevas el Símbolo de la Vida, así que solo puedo deducir que Tiza y Muiredon te enviaron a ayudarme.$B$BCaí combatiendo contra los Hierro Negro cuando intentaba hacerme con uno de los textos. Conseguí retenerlos lo suficiente para que Muiredon escapara, pero cuando llegaste, la Luz casi me había abrazado por completo. El hecho de que tuvieras la fuerza para utilizar el Símbolo tiene mucha importancia para ti, pero ya hablaremos de eso más adelante.', 0);
-- 1784 Escrito sobre divinidad
-- https://es.classic.wowhead.com/quest=1784
SET @ID := 1784;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has vuelto! ¡Cómo me alegro, $n! Mis heridas han sanado y ya estoy listo para volver al Lago de Helm... en cuanto consiga convencer a mi mujer de que no me pasará nada.', 0),
(@ID, 'esMX', '¡Has vuelto! ¡Cómo me alegro, $n! Mis heridas han sanado y ya estoy listo para volver al Lago de Helm... en cuanto consiga convencer a mi mujer de que no me pasará nada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja! ¡Lo has conseguido! Has salvado a Narm y has encontrado las pruebas que necesita mi mujer para ir al Consejo. Eres una bendición de la Luz... como mi mujer.$B$BGracias otra vez, $n.', 0),
(@ID, 'esMX', '¡Ja, ja! ¡Lo has conseguido! Has salvado a Narm y has encontrado las pruebas que necesita mi mujer para ir al Consejo. Eres una bendición de la Luz... como mi mujer.$B$BGracias otra vez, $n.', 0);
