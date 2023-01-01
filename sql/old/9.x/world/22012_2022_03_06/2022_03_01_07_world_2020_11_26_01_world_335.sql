-- 5281 Espíritus inquietos
-- https://es.classic.wowhead.com/quest=5281
SET @ID := 5281;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Por fin Alen ha encontrado a alguien con el suficiente valor, ¿eh?', 0),
(@ID, 'esMX', 'Por fin Alen ha encontrado a alguien con el suficiente valor, ¿eh?', 0);
-- 5211 Los defensores de Villa Darrow
-- https://es.classic.wowhead.com/quest=5211
SET @ID := 5211;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Los pobres defensores de Villa Darrow me gritan en sueños, $n. ¡Debes liberarlos!', 0),
(@ID, 'esMX', 'Los pobres defensores de Villa Darrow me gritan en sueños, $n. ¡Debes liberarlos!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra oír que encontraste las almas torturadas de mis hermanos y que las liberaste. Mi corazón sufrirá menos sabiendo que al menos algunos de los defensores de Villa Darrow se han liberado de la tiranía de la Plaga.', 0),
(@ID, 'esMX', 'Me alegra oír que encontraste las almas torturadas de mis hermanos y que las liberaste. Mi corazón sufrirá menos sabiendo que al menos algunos de los defensores de Villa Darrow se han liberado de la tiranía de la Plaga.', 0);
-- Piedras de la Plaga del corruptor
-- 5404, 5406, 5508
-- https://es.classic.wowhead.com/quest=5404
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5404, 5406, 5508) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5404, 'esES', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5406, 'esES', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5508, 'esES', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5404, 'esMX', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5406, 'esMX', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0),
(5508, 'esMX', 'Una piedra de la Plaga del corruptor es la insignia de los Señores Supremos de la Plaga. Todo ser poderoso y con autoridad sobre la Plaga posee una de esas piedras. Acabar con una criatura tan malévola sería un gran paso adelante para la causa del Alba Argenta y para todas las causas justas.$B$BEn nombre del Alba Argenta te daré una muestra de valor a cambio de una sola de esas insignias. Ten cuidado al obtenerlas, $n... no hay que andar jugando con criaturas tan poderosas.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5404, 5406, 5508) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5404, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5406, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5508, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5404, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5406, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0),
(5508, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BAdquirir una muestra de valor de esta forma indica que eres un auténtico héroe de la causa del bien. Valoramos todo esfuerzo hecho contra la Plaga, ¡pero acabar con uno de sus líderes es un auténtico avance hacia su derrota!$B$B¡Por el Alba, $ghermano:hermana;!', 0);
-- Piedras de la Plaga del invasor
-- 5403, 5407, 5509
-- https://es.classic.wowhead.com/quest=5403
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5403, 5407, 5509) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5403, 'esES', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5407, 'esES', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5509, 'esES', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5403, 'esMX', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5407, 'esMX', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0),
(5509, 'esMX', 'Una piedra de la Plaga del invasor es la insignia de las tropas de élite de la Plaga. A veces pueden encontrarse entre los más fuertes de las tropas destacadas en las Tierras de la Peste. Derrotar una criatura así es, sin duda, todo un reto, pero uno del que se disfruta cuando se está comprometido con la aniquilación del mal.$B$BEn este momento, el Alba Argenta ofrece una muestra de valor a cambio de diez de esas insignias. Tráemelas y me aseguraré de que recibas tu recompensa.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5403, 5407, 5509) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5403, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5407, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5509, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5403, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5407, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0),
(5509, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor del Alba Argenta!$B$BCada muestra de valor entregada a alguien digno de ella es un símbolo de la oleada que se está abriendo contra la Plaga. Cada vez son más los héroes que combaten a la Plaga en nuestras tierras, lo que asegura que el Alba Argenta ocupará un puesto destacado cuando llegue el momento de hacer frente al mal último de la Plaga. ¡Espero que el valor que has demostrado y que te permitió conseguir una de estas muestras también esté presente ese día!', 0);
-- Piedras de la Plaga del esbirro
-- 5402, 5408, 5510
-- https://es.classic.wowhead.com/quest=5402
DELETE FROM `quest_request_items_locale` WHERE `id` IN(5402, 5408, 5510) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(5402, 'esES', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5408, 'esES', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5510, 'esES', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5402, 'esMX', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5408, 'esMX', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0),
(5510, 'esMX', 'Una piedra de la Plaga del esbirro es la insignia de las filas de la Plaga. A veces pueden encontrarse en los miembros más débiles de las tropas destacadas en las Tierras de la Peste, aunque la palabra "débil" es muy relativa. La Plaga, da igual de quién se trate, nunca debe ser subestimada.$B$BEn este momento El Alba Argenta ofrece una muestra de valor a cambio de veinte de esas insignias... un intercambio que me encantaría hacer, ¡siempre y cuando tengas suficientes piedras de la Plaga!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(5402, 5408, 5510) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(5402, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5408, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5510, 'esES', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5402, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5408, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0),
(5510, 'esMX', 'Felicidades, $n. ¡Es un placer recompensarte con una muestra de valor de El Alba Argenta!$B$BLas muestras tienen dos propósitos. En primer lugar, pueden utilizarse para aumentar tu reputación con El Alba Argenta, de ese modo tendrás a tu disposición oportunidades y recompensas reservadas a nuestros aliados honorables y venerados. En segundo lugar, puedes entregarlas a nuestros intendentes, junto con algunas monedas, como pago por algunos de los objetos más valiosos de El Alba.$B$BDecidas lo que decidas, te estás ganando tu comisión. ¡Bien hecho!', 0);
-- 5251 El archivista
-- https://es.classic.wowhead.com/quest=5251
SET @ID := 5251;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Recuerda, $n, ¡debemos ser tolerantes pero rígidos en nuestras creencias!', 0),
(@ID, 'esMX', 'Recuerda, $n, ¡debemos ser tolerantes pero rígidos en nuestras creencias!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Impresionante, $n! Años y años de trabajo... ¡perdidos! La Cruzada Escarlata se resentirá de esto en las próximas semanas.', 0),
(@ID, 'esMX', '¡Impresionante, $n! Años y años de trabajo... ¡perdidos! La Cruzada Escarlata se resentirá de esto en las próximas semanas.', 0);
-- Armamento superior de batalla: amistoso con El Alba
-- 9221, 9223, 9226, 9227
-- https://es.classic.wowhead.com/quest=9221
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9221, 9223, 9226, 9227) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9221, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9223, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9226, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9227, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9221, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9223, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9226, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9227, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9221, 9223, 9226, 9227) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9221, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9223, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9226, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9227, 'esES', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9221, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9223, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9226, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0),
(9227, 'esMX', 'Buen día, $n. Fue un placer hacer negocios contigo.', 0);
-- Armamento épico de batalla: amistoso con El Alba
-- 9222, 9224, 9225, 9228
-- https://es.classic.wowhead.com/quest=9222
DELETE FROM `quest_request_items_locale` WHERE `id` IN(9222, 9224, 9225, 9228) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(9222, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9224, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9225, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9228, 'esES', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9222, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9224, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9225, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0),
(9228, 'esMX', 'Elije cuidadosamente. No hay reembolsos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(9222, 9224, 9225, 9228) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(9222, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9224, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9225, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9228, 'esES', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9222, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9224, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9225, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0),
(9228, 'esMX', 'Buen día, $N. Fue un placer hacer negocios contigo.', 0);
-- 5212 La carne no miente
-- https://es.classic.wowhead.com/quest=5212
SET @ID := 5212;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'A quien me dice que me preocupo demasiado le digo que él no se preocupa lo suficiente.', 0),
(@ID, 'esMX', 'A quien me dice que me preocupo demasiado le digo que él no se preocupa lo suficiente.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Algo ha cambiado en la estructura química de los agentes activos de la peste. Necesitamos más datos.', 0),
(@ID, 'esMX', 'Algo ha cambiado en la estructura química de los agentes activos de la peste. Necesitamos más datos.', 0);
-- 5529 Crías de dragón apestadas
-- https://es.classic.wowhead.com/quest=5529
SET @ID := 5529;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Ve a Scholomance, $n. ¡Elimina a esas crías apertadas antes de que crezcan!', 0),
(@ID, 'esMX', 'Ve a Scholomance, $n. ¡Elimina a esas crías apertadas antes de que crezcan!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Buen trabajo, $n! Tardarán en poder volver a criar dragones.$B$B¡O al menos, eso espero!', 0),
(@ID, 'esMX', '¡Buen trabajo, $n! Tardarán en poder volver a criar dragones.$B$B¡O al menos, eso espero!', 0);
-- 9664 Nuevas avanzadas
-- https://es.classic.wowhead.com/quest=9664
SET @ID := 9664;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Cuando las torres estén bajo nuestro control, podremos rodear a los Renegados. Después de eso, es solo cuestión de tiempo que podamos aplastarlos.', 0),
(@ID, 'esMX', 'Cuando las torres estén bajo nuestro control, podremos rodear a los Renegados. Después de eso, es solo cuestión de tiempo que podamos aplastarlos.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Muy bien, $n. Será importante para nosotros mantener estas torres contra futuros ataques, y para eso es posible que necesitemos tu ayuda hasta que se puedan traer refuerzos para asegurar el área.', 0),
(@ID, 'esMX', 'Muy bien, $n. Será importante para nosotros mantener estas torres contra futuros ataques, y para eso es posible que necesitemos tu ayuda hasta que se puedan traer refuerzos para asegurar el área.', 0);
-- 9136 Flora salvaje
-- https://es.classic.wowhead.com/quest=9136
SET @ID := 9136;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tengo un conocimiento profundo de la flora de nuestro mundo. ¿Necesitas orientación?', 0),
(@ID, 'esMX', 'Tengo un conocimiento profundo de la flora de nuestro mundo. ¿Necesitas orientación?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Estoy muy agradecida, $n.$B$B<Rayne hace una reverencia.>$B$BRecuerda que siempre estoy aceptando frondas.', 0),
(@ID, 'esMX', 'Estoy muy agradecida, $n.$B$B<Rayne hace una reverencia.>$B$BRecuerda que siempre estoy aceptando frondas.', 0);
-- 27 Una lección que aprender
-- https://es.classic.wowhead.com/quest=27
SET @ID := 27;
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Saludos, joven $c, ha llegado el momento de que conozcas nuestra forma acuática. Se trata de una técnica que te permitirá moverte libre e indefinidamente por el agua. Encontrarás muy útil este aspecto y pronto te darás cuenta de que es una bendición. Pero debes ganártelo antes de dominarlo...$B$BDeberás superar dos pruebas. La primera probará tu capacidad para trabajar en el agua bajo presión. La segunda, tu resolución y tu comprensión de los aspectos de la forma acuática.$B$BPrepárate pues el momento de la prueba se acerca.', 0),
(@ID, 'esMX', 'Saludos, joven $c, ha llegado el momento de que conozcas nuestra forma acuática. Se trata de una técnica que te permitirá moverte libre e indefinidamente por el agua. Encontrarás muy útil este aspecto y pronto te darás cuenta de que es una bendición. Pero debes ganártelo antes de dominarlo...$B$BDeberás superar dos pruebas. La primera probará tu capacidad para trabajar en el agua bajo presión. La segunda, tu resolución y tu comprensión de los aspectos de la forma acuática.$B$BPrepárate pues el momento de la prueba se acerca.', 0);
-- La prueba del lago
-- 28, 29
-- https://es.classic.wowhead.com/quest=28
DELETE FROM `quest_offer_reward_locale` WHERE `id` IN(28, 29) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(28, 'esES', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0),
(29, 'esES', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0),
(28, 'esMX', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0),
(29, 'esMX', '¡$gOtro:Otra; $c que completa la Prueba del Lago! Buen trabajo.$B$BMe llamo Tajarri y tengo el honor de ser el guardián de este santuario, un tributo a la conservación de la naturaleza y su equilibrio. Este adorno señala la importancia de este lugar para el Círculo Cenarion.', 0);
-- 30 La prueba del león marino
-- https://es.classic.wowhead.com/quest=30
SET @ID := 30;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Traes el colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0),
(@ID, 'esMX', '¿Traes el colgante, $n? Si no encuentras las piezas, habla con la gente del lugar. Encontrarás lo que buscas y podrás explorar este lugar sagrado.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua, y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0),
(@ID, 'esMX', 'Enhorabuena por completar la Prueba del León Marino, $n.$B$BHas aprendido que necesitas agilidad y resistencia para moverte en armonía en el agua, y que para ello debes abrazar el aspecto del león marino.$B$BEstas lecciones te serán muy útiles cuando ganes tu forma acuática.', 0);
-- 31 Forma acuática
-- https://es.classic.wowhead.com/quest=31
SET @ID := 31;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Tenía noticia de tu regreso a Cima del Trueno, pero debes demostrarme lo que has aprendido para que te enseñe tu forma acuática.$B$B¿Traes el colgante del león marino?', 0),
(@ID, 'esMX', 'Tenía noticia de tu regreso a Cima del Trueno, pero debes demostrarme lo que has aprendido para que te enseñe tu forma acuática.$B$B¿Traes el colgante del león marino?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Impresionante, $n; tus antepasados pueden estar orgullosos. Me llena de alegría poder enseñarte tu Forma acuática.$B$BAcepta esto como premio por tus logros en las dos pruebas; espero que te ayude en tu objetivo de proteger la naturaleza y su equilibrio.', 0),
(@ID, 'esMX', 'Impresionante, $n; tus antepasados pueden estar orgullosos. Me llena de alegría poder enseñarte tu Forma acuática.$B$BAcepta esto como premio por tus logros en las dos pruebas; espero que te ayude en tu objetivo de proteger la naturaleza y su equilibrio.', 0);
-- 32 La sublevación de los silítidos
-- https://es.classic.wowhead.com/quest=32
SET @ID := 32;
DELETE FROM `quest_request_items_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`id`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Lo siento, no te conozco... pero por lo que parece, tú sí has oído hablar de mí. ¿En qué puedo ayudarte? ¿Tienes algo para mí?', 0),
(@ID, 'esMX', 'Lo siento, no te conozco... pero por lo que parece, tú sí has oído hablar de mí. ¿En qué puedo ayudarte? ¿Tienes algo para mí?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `id` = @ID AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`id`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Este informe... Yo ya he visto antes a estas criaturas. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0),
(@ID, 'esMX', 'Este informe... Yo ya he visto antes a estas criaturas. Picoflojo ha hecho muy bien al enviarte aquí con el informe.$B$BEstas criaturas destruirán el Desierto de Tanaris con rapidez. Se trata de una de las mayores amenazas a la que jamás nos hemos enfrentado. Familiarízate con este nombre, $n: silítidos. Los insectos de los que habla este informe son los silítidos y representan uno de los mayores peligros a los que tanto la Horda como la Alianza se enfrentan.$B$BSi hubiéramos sido capaces de descubrirlo antes...', 0);
