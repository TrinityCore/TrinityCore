-- 8355 ¡Truco o trato!
-- https://es.classic.wowhead.com/quest=8355
SET @ID := 8355;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Haz el tren para Talvash', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, adelante ahora...', 0),
(@ID, 'esMX', 'Bueno, adelante ahora...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Chú, chú! ¡Bien hecho, $n! Aquí tienes tu premio.$B$B¡Feliz día de Halloween!', 0),
(@ID, 'esMX', '¡Chú, chú! ¡Bien hecho, $n! Aquí tienes tu premio.$B$B¡Feliz día de Halloween!', 0);
-- 8356 Saca músculo a cambio de almendrados
-- https://es.classic.wowhead.com/quest=8356
SET @ID := 8356;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Saca músculos para la tabernera Allison', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
UPDATE `quest_offer_reward_locale` SET `RewardText` = '¡Ja, ja, eres muy $gpoderoso:poderosa;! Bien hecho, gracias por tener tan buen talante. Aquí tienes tus caramelos.$B$B¡Feliz Halloween, $n!', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
-- 8357 Bailando por mazapanes
-- https://es.classic.wowhead.com/quest=8357
SET @ID := 8357;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Baila para la tabernera Saelienne', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes bailar, ¿no? Intenta poner tu pie derecho adentro... luego tu pie derecho afuera... tu pie derecho adentro... sacúdelo todo...', 0),
(@ID, 'esMX', 'Sabes bailar, ¿no? Intenta poner tu pie derecho adentro... luego tu pie derecho afuera... tu pie derecho adentro... sacúdelo todo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, $n! ¡Eres $gun bailarín nato:una bailarina nata;!$B$BAquí tienes tu recompensa por haber participado. ¡Feliz Halloween! ¡Saluda a tu amiguito enfermo! Espero que se recupere pronto.', 0),
(@ID, 'esMX', '¡Vaya, $n! ¡Eres $gun bailarín nato:una bailarina nata;!$B$BAquí tienes tu recompensa por haber participado. ¡Feliz Halloween! ¡Saluda a tu amiguito enfermo! Espero que se recupere pronto.', 0);
-- 8358 ¡Truco o trato!
-- https://es.classic.wowhead.com/quest=8358
SET @ID := 8358;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Haz el tren para Kali Remik', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Bueno, adelante ahora...', 0),
(@ID, 'esMX', 'Bueno, adelante ahora...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Chú, chú! ¡Bien hecho, $n! Aquí tienes tu premio.$B$B¡Feliz día de Halloween!', 0),
(@ID, 'esMX', '¡Chú, chú! ¡Bien hecho, $n! Aquí tienes tu premio.$B$B¡Feliz día de Halloween!', 0);
-- 8359 Saca músculo a cambio de almendrados
-- https://es.classic.wowhead.com/quest=8359
SET @ID := 8359;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Saca músculo para la tabernera Gryshka', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Nada de dulces hasta que saques músculo para mí, $n...', 0),
(@ID, 'esMX', 'Nada de dulces hasta que saques músculo para mí, $n...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja, ja, eres muy $gpoderoso:poderosa;! Bien hecho, gracias por tener tan buen talante. Aquí tienes tus caramelos.$B$B¡Feliz Halloween, $n!', 0),
(@ID, 'esMX', '¡Ja, ja, eres muy $gpoderoso:poderosa;! Bien hecho, gracias por tener tan buen talante. Aquí tienes tus caramelos.$B$B¡Feliz Halloween, $n!', 0);
-- 8360 Bailando por mazapanes
-- https://es.classic.wowhead.com/quest=8360
SET @ID := 8360;
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Baila para la tabernera Pala', `VerifiedBuild` = 0 WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sabes bailar, ¿no? Intenta poner tu pie derecho adentro... luego tu pie derecho afuera... tu pie derecho adentro... sacúdelo todo...', 0),
(@ID, 'esMX', 'Sabes bailar, ¿no? Intenta poner tu pie derecho adentro... luego tu pie derecho afuera... tu pie derecho adentro... sacúdelo todo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Vaya, $n! ¡Eres $gun bailarín nato:una bailarina nata;!$B$BAquí tienes tu recompensa por haber participado. ¡Feliz Halloween! ¡Saluda a tu amiguito enfermo! Espero que se recupere pronto.', 0),
(@ID, 'esMX', '¡Vaya, $n! ¡Eres $gun bailarín nato:una bailarina nata;!$B$BAquí tienes tu recompensa por haber participado. ¡Feliz Halloween! ¡Saluda a tu amiguito enfermo! Espero que se recupere pronto.', 0);
-- 8361 Contactos Abisales
-- https://es.classic.wowhead.com/quest=8361
SET @ID := 8361;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Lo has hecho ya?', 0),
(@ID, 'esMX', '¿Lo has hecho ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ja! ¡Lo has conseguido, $n! ¡Pronto aplastaremos al Martillo Crepuscular!', 0),
(@ID, 'esMX', '¡Ja! ¡Lo has conseguido, $n! ¡Pronto aplastaremos al Martillo Crepuscular!', 0);
-- 8362 Blasones Abisales
-- https://es.classic.wowhead.com/quest=8362
SET @ID := 8362;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado que puedes manejarte $gsolo:sola; en una pelea, $n. Mantengamos la presión sobre el Martillo Crepuscular. Ve a luchar contra algunos templarios abisales más, te recompensaré con algunas de las cosas que Huum y yo hemos encontrado en la batalla.', 0),
(@ID, 'esMX', 'Has demostrado que puedes manejarte $gsolo:sola; en una pelea, $n. Mantengamos la presión sobre el Martillo Crepuscular. Ve a luchar contra algunos templarios abisales más, te recompensaré con algunas de las cosas que Huum y yo hemos encontrado en la batalla.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Lo has hecho bien! Eso es menos Templarios de los que preocuparme.$B$BAquí tienes, $n. Espero que haya algo útil para ti.', 0),
(@ID, 'esMX', '¡Lo has hecho bien! Eso es menos Templarios de los que preocuparme.$B$BAquí tienes, $n. Espero que haya algo útil para ti.', 0);
-- 8363 Sellos abisales
-- https://es.classic.wowhead.com/quest=8363
SET @ID := 8363;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has demostrado que eres más que capaz de enfrentarte a un Duque Abisal, $n. Siempre soy de los que promueven los buenos hábitos. Tráeme más sellos y te daré una recompensa.', 0),
(@ID, 'esMX', 'Has demostrado que eres más que capaz de enfrentarte a un Duque Abisal, $n. Siempre soy de los que promueven los buenos hábitos. Tráeme más sellos y te daré una recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente, $n! Derrotar a esos duques dejará al Martillo Crepuscular tambaleándose por un tiempo. Como prometí, aquí tienes tu recompensa. Es una de las mejores cosas que Huum y yo hemos encontrado.', 0),
(@ID, 'esMX', '¡Excelente, $n! Derrotar a esos duques dejará al Martillo Crepuscular tambaleándose por un tiempo. Como prometí, aquí tienes tu recompensa. Es una de las mejores cosas que Huum y yo hemos encontrado.', 0);
-- 8364 Cetros Abisales
-- https://es.classic.wowhead.com/quest=8364
SET @ID := 8364;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Realmente has superado todas mis expectativas, $n. Has estado enfrentándote a oponentes que Huum y yo nos lo pensaríamos mucho antes de enfrentarnos.$B$BEn este punto, lo mejor que puedo hacer es seguir recompensando tus esfuerzos en la lucha contra el Martillo Crepuscular y sus amos.$B$BTráeme más cetros abisales y haré todo lo posible para darte una recompensa adecuada.', 0),
(@ID, 'esMX', 'Realmente has superado todas mis expectativas, $n. Has estado enfrentándote a oponentes que Huum y yo nos lo pensaríamos mucho antes de enfrentarnos.$B$BEn este punto, lo mejor que puedo hacer es seguir recompensando tus esfuerzos en la lucha contra el Martillo Crepuscular y sus amos.$B$BTráeme más cetros abisales y haré todo lo posible para darte una recompensa adecuada.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Sabía que vendrías, $n! Aquí tienes tu recompensa.', 0),
(@ID, 'esMX', '¡Sabía que vendrías, $n! Aquí tienes tu recompensa.', 0);
-- Cuestión de honor
-- 8367, 13476
-- https://es.classic.wowhead.com/quest=8367
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8367, 13476) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8367, 'esES', 'Arathi todavía está empapada con la sangre de grandes guerreros y el choque del acero aún resuena en todo Alterac. ¡No pierdas mi tiempo a menos que traigas noticias del frente!', 0),
(13476, 'esES', 'Arathi todavía está empapada con la sangre de grandes guerreros y el choque del acero aún resuena en todo Alterac. ¡No pierdas mi tiempo a menos que traigas noticias del frente!', 0),
(8367, 'esMX', 'Arathi todavía está empapada con la sangre de grandes guerreros y el choque del acero aún resuena en todo Alterac. ¡No pierdas mi tiempo a menos que traigas noticias del frente!', 0),
(13476, 'esMX', 'Arathi todavía está empapada con la sangre de grandes guerreros y el choque del acero aún resuena en todo Alterac. ¡No pierdas mi tiempo a menos que traigas noticias del frente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8367, 13476) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8367, 'esES', 'Tus pruebas no han sido fáciles, pero tu valor no se te escapó y tus fuerzas no fallaron. Parte con marcas de victoria anteriores, $n. Nadie los necesitará como recordatorio de su valía. Ponte de pie, $n. ¡Hoy caminarás con mucho orgullo porque eres $gun héroe:una heroína;!', 0),
(13476, 'esES', 'Tus pruebas no han sido fáciles, pero tu valor no se te escapó y tus fuerzas no fallaron. Parte con marcas de victoria anteriores, $n. Nadie los necesitará como recordatorio de su valía. Ponte de pie, $n. ¡Hoy caminarás con mucho orgullo porque eres $gun héroe:una heroína;!', 0),
(8367, 'esMX', 'Tus pruebas no han sido fáciles, pero tu valor no se te escapó y tus fuerzas no fallaron. Parte con marcas de victoria anteriores, $n. Nadie los necesitará como recordatorio de su valía. Ponte de pie, $n. ¡Hoy caminarás con mucho orgullo porque eres $gun héroe:una heroína;!', 0),
(13476, 'esMX', 'Tus pruebas no han sido fáciles, pero tu valor no se te escapó y tus fuerzas no fallaron. Parte con marcas de victoria anteriores, $n. Nadie los necesitará como recordatorio de su valía. Ponte de pie, $n. ¡Hoy caminarás con mucho orgullo porque eres $gun héroe:una heroína;!', 0);
-- La batalla por Garganta Grito de Guerra
-- 8368, 8389, 8426, 8427, 8428, 8429, 8430, 8431, 8432, 8433, 8434, 8435
-- https://es.classic.wowhead.com/quest=8368
DELETE FROM `quest_request_items_locale` WHERE `id` IN(8368, 8389, 8426, 8427, 8428, 8429, 8430, 8431, 8432, 8433, 8434, 8435) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(8368, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8389, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8426, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8427, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8428, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8429, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8430, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8431, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8432, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8433, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8434, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8435, 'esES', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8368, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8389, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8426, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8427, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8428, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8429, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8430, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8431, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8432, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8433, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8434, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0),
(8435, 'esMX', 'La batalla de la Garganta Grito de Guerra contra las centinelas Ala de Plata tiene una importancia vital. Con la excusa de estar protegiendo un bosque que no les pertenece, la Alianza intenta negar a la Horda una de sus principales fuentes de recursos madereros.$B$B¡No debemos permitirlo, $n! ¡Vuelve a verme cuando puedas demostrar que has servido a la Horda dignamente!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(8368, 8389, 8426, 8427, 8428, 8429, 8430, 8431, 8432, 8433, 8434, 8435) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(8368, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8389, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8426, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8427, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8428, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8429, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8430, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8431, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8432, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8433, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8434, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8435, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8368, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8389, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8426, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8427, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8428, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8429, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8430, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8431, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8432, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8433, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8434, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(8435, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0);
-- 8369 Invasores del Valle de Alterac
-- https://es.classic.wowhead.com/quest=8369
SET @ID := 8369;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes de las tierras de los Lobo Gélido? ¿Qué tal va la batalla por el Valle de Alterac?', 0),
(@ID, 'esMX', '¿Qué noticias traes de las tierras de los Lobo Gélido? ¿Qué tal va la batalla por el Valle de Alterac?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has mostrado una gran valentía al proteger nuestras tierras del Valle de Alterac! Hablaré a mis superiores de tus hazañas.', 0),
(@ID, 'esMX', '¡Has mostrado una gran valentía al proteger nuestras tierras del Valle de Alterac! Hablaré a mis superiores de tus hazañas.', 0);
-- 8373 El poder del pino
-- https://es.classic.wowhead.com/quest=8373
SET @ID := 8373;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ah, ya casi huele mejor por aquí. Casi.$B$BGracias a ti, $n, Costa Sur podría pasar por otro Halloween. ¡Aquí están sus golosinas, con mi agradecimiento! Si te quedas sin caramelos, creo que hay una gnoma llamado Katrina Shimmerstar en Forjaz que puede venderte más; ella solo está presente durante Halloween, creo.', 0),
(@ID, 'esMX', 'Ah, ya casi huele mejor por aquí. Casi.$B$BGracias a ti, $n, Costa Sur podría pasar por otro Halloween. ¡Aquí están sus golosinas, con mi agradecimiento! Si te quedas sin caramelos, creo que hay una gnoma llamado Katrina Shimmerstar en Forjaz que puede venderte más; ella solo está presente durante Halloween, creo.', 0);
-- 8375 ¡Recuerda el Valle de Alterac!
-- https://es.classic.wowhead.com/quest=8375
SET @ID := 8375;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué noticias traes de las tierras de los Picos Tormentas? ¿Cómo va la batalla por el Valle de Alterac?', 0),
(@ID, 'esMX', '¿Qué noticias traes de las tierras de los Picos Tormentas? ¿Cómo va la batalla por el Valle de Alterac?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Has demostrado una gran valentía al proteger nuestras tierras en el Valle de Alterac! Les contaré a mis superiores tus actos.', 0),
(@ID, 'esMX', '¡Has demostrado una gran valentía al proteger nuestras tierras en el Valle de Alterac! Les contaré a mis superiores tus actos.', 0);
-- 8383 ¡Recuerda el Valle de Alterac!
-- https://es.classic.wowhead.com/quest=8383
SET @ID := 8383;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue honrando a la Alianza, $n. La Horda no tardará mucho en ser aplastada si seguimos adelante con nuestros esfuerzos.', 0),
(@ID, 'esMX', 'Sigue honrando a la Alianza, $n. La Horda no tardará mucho en ser aplastada si seguimos adelante con nuestros esfuerzos.', 0);
-- 8386 Lucha por Garganta Grito de Guerra
-- https://es.classic.wowhead.com/quest=8386
SET @ID := 8386;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes noticias de Garganta Grito de Guerra, $n?', 0),
(@ID, 'esMX', '¿Tienes noticias de Garganta Grito de Guerra, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0),
(@ID, 'esMX', '¡Excelente! ¡Has demostrado tu valía defendiendo nuestras operaciones en Garganta Grito de Guerra! Que la palabra de tu honor se extienda por todas partes en nuestras tierras.', 0);
-- 8387 Invasores del Valle de Alterac
-- https://es.classic.wowhead.com/quest=8387
SET @ID := 8387;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡La batalla por Alterac sigue ardiendo! ¡Debes volver al Valle de Alterac y expulsar una vez más a los invasores del territorio de Lobo Gélido, $n!', 0),
(@ID, 'esMX', '¡La batalla por Alterac sigue ardiendo! ¡Debes volver al Valle de Alterac y expulsar una vez más a los invasores del territorio de Lobo Gélido, $n!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Deberías sentirte $gorgulloso:orgullosa;. ¡Los invasores de la Alianza deben ser expulsados de Alterac!', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Deberías sentirte $gorgulloso:orgullosa;. ¡Los invasores de la Alianza deben ser expulsados de Alterac!', 0);
-- 8388 Cuestión de honor
-- https://es.classic.wowhead.com/quest=8388
SET @ID := 8388;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muchos valientes guerreros te admiran, $n. Sigue siendo un ejemplo para todos los que luchan contra la Alianza. ¿Qué noticias traes de tus viajes?', 0),
(@ID, 'esMX', 'Muchos valientes guerreros te admiran, $n. Sigue siendo un ejemplo para todos los que luchan contra la Alianza. ¿Qué noticias traes de tus viajes?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Sigue honrando a la Horda, $n. Es un placer comprobar que no te has debilitado.', 0),
(@ID, 'esMX', 'Sigue honrando a la Horda, $n. Es un placer comprobar que no te has debilitado.', 0);
-- 8409 Los barriles dañados
-- https://es.classic.wowhead.com/quest=8409
SET @ID := 8409;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, bien! Has mostrado el verdadero espíritu de Halloween, ¡espíritu Renegado, debería decir!$B$B<La clamasombras Yanka se ríe y se frota las manos.>$B$BMe deleito en el hecho de que Costa Sur ahora debe darse un festín con cerveza mala o prescindir de ella. En cuanto a ti, toma estas golosinas. ¡Creo que les encontrarás un buen uso!', 0),
(@ID, 'esMX', '¡Ah, bien! Has mostrado el verdadero espíritu de Halloween, ¡espíritu Renegado, debería decir!$B$B<La clamasombras Yanka se ríe y se frota las manos.>$B$BMe deleito en el hecho de que Costa Sur ahora debe darse un festín con cerveza mala o prescindir de ella. En cuanto a ti, toma estas golosinas. ¡Creo que les encontrarás un buen uso!', 0);
-- 8410 Maestría elemental
-- https://es.classic.wowhead.com/quest=8410
SET @ID := 8410;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué tienes para mí, $n?', 0),
(@ID, 'esMX', '¿Qué tienes para mí, $n?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Excelente, colega. Ahora nos entendemos.', 0),
(@ID, 'esMX', 'Excelente, colega. Ahora nos entendemos.', 0);
-- 8411 Dominar los elementos
-- https://es.classic.wowhead.com/quest=8411
SET @ID := 8411;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde están los elementos, colega?', 0),
(@ID, 'esMX', '¿Dónde están los elementos, colega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estos son los elementos que necesito. Ahora hablamos.', 0),
(@ID, 'esMX', 'Estos son los elementos que necesito. Ahora hablamos.', 0);
-- 8412 Tótem de espíritu
-- https://es.classic.wowhead.com/quest=8412
SET @ID := 8412;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Los espíritus saben lo que estamos haciendo y han estado tratando de matarme! Espero que tengas las piezas.', 0),
(@ID, 'esMX', '¡Los espíritus saben lo que estamos haciendo y han estado tratando de matarme! Espero que tengas las piezas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Genial, colega! Probémoslo...', 0),
(@ID, 'esMX', '¡Genial, colega! Probémoslo...', 0);
-- 8413 Vudú
-- Notice: English text: Change '$R' to 'troll' in quest_offer_reward.RewardText
-- https://es.classic.wowhead.com/quest=8413
SET @ID := 8413;
UPDATE `quest_offer_reward` SET `RewardText` = 'It\'s about time this troll got a full night\'s rest! The spirit totem will watch over me.$B$BI been a long time collectin\' things, maybe you want somethin\' for all your trouble?', `VerifiedBuild` = 0 WHERE `id` = @ID ;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Dónde están las plumas, colega?', 0),
(@ID, 'esMX', '¿Dónde están las plumas, colega?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ya es hora de que este trol descanse toda la noche! El tótem espiritual velará por mí.$B$BLlevo mucho tiempo coleccionando cosas, ¿tal vez quieres algo por todos tus problemas?', 0),
(@ID, 'esMX', '¡Ya es hora de que este trol descanse toda la noche! El tótem espiritual velará por mí.$B$BLlevo mucho tiempo coleccionando cosas, ¿tal vez quieres algo por todos tus problemas?', 0);
-- 8414 Expulsión de los demonios
-- https://es.classic.wowhead.com/quest=8414
SET @ID := 8414;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Qué mal me has traído?', 0),
(@ID, 'esMX', '¿Qué mal me has traído?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Existe el riesgo de disipar el mal de un azote, ya que atrae la atención de los muertos vivientes a lo largo de incontables millas. Pero eres fuerte en la Luz, $n, y no temo por ti...', 0),
(@ID, 'esMX', 'Existe el riesgo de disipar el mal de un azote, ya que atrae la atención de los muertos vivientes a lo largo de incontables millas. Pero eres fuerte en la Luz, $n, y no temo por ti...', 0);
-- 8415 Campamento del Orvallo
-- https://es.classic.wowhead.com/quest=8415
SET @ID := 8415;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Muy bien, $n! Veamos de qué estás $ghecho:hecha;.', 0),
(@ID, 'esMX', '¡Muy bien, $n! Veamos de qué estás $ghecho:hecha;.', 0);
-- 8416 Piedras de la Plaga inertes
-- https://es.classic.wowhead.com/quest=8416
SET @ID := 8416;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Pudo Thal\'danis limpiar las piedras de la plaga?', 0),
(@ID, 'esMX', '¿Pudo Thal\'danis limpiar las piedras de la plaga?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Has hecho lo que te pedí sin dudarlo, $n.$B$BLa confianza se gana, parece. Quizás ahora pueda revelarte nuestro plan con más detalle.', 0),
(@ID, 'esMX', 'Has hecho lo que te pedí sin dudarlo, $n.$B$BLa confianza se gana, parece. Quizás ahora pueda revelarte nuestro plan con más detalle.', 0);
-- 8417 Un espíritu afligido
-- https://es.classic.wowhead.com/quest=8417
SET @ID := 8417;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Stoley tosió mi alcohol?', 0),
(@ID, 'esMX', '¿Stoley tosió mi alcohol?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, has venido a aliviar mi dolor. Ojalá pudieras simplemente derribarme, pero no es tan simple...', 0),
(@ID, 'esMX', 'Entonces, has venido a aliviar mi dolor. Ojalá pudieras simplemente derribarme, pero no es tan simple...', 0);
-- 8418 La forja de la piedra de poderío
-- https://es.classic.wowhead.com/quest=8418
SET @ID := 8418;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has matado a los desgraciados trols?', 0),
(@ID, 'esMX', '¿Has matado a los desgraciados trols?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Esto es excelente, $n. Diría que estoy sorprendido, pero sabía sin lugar a dudas que no nos decepcionarías.$B$BEs un honor para mí concederte una de las Sagradas Piedras de Poder. Úsala bien.', 0),
(@ID, 'esMX', 'Esto es excelente, $n. Diría que estoy sorprendido, pero sabía sin lugar a dudas que no nos decepcionarías.$B$BEs un honor para mí concederte una de las Sagradas Piedras de Poder. Úsala bien.', 0);
-- 8419 Pedido de un diablillo
-- https://es.classic.wowhead.com/quest=8419
SET @ID := 8419;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Tienes mi tela vil?', 0),
(@ID, 'esMX', '¿Tienes mi tela vil?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Qué $gespléndido:espléndida; $n eres!$B$B<Impsy se lleva la tela vil a la cara.>$B$BOh, cómo me encanta sentirlo, la forma en que quema tu piel y teje pensamientos malvados en la mente...', 0),
(@ID, 'esMX', '¡Qué $gespléndido:espléndida; $n eres!$B$B<Impsy se lleva la tela vil a la cara.>$B$BOh, cómo me encanta sentirlo, la forma en que quema tu piel y teje pensamientos malvados en la mente...', 0);
