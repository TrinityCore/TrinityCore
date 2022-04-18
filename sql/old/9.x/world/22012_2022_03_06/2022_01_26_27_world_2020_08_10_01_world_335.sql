-- 1447 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1447
SET @ID := 1447;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Has venido por alguna razón en particular? ¿Qué necesitas?', 0),
(@ID, 'esMX', '¿Has venido por alguna razón en particular? ¿Qué necesitas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No quise decir nada con el comentario de que eres un estúpido $c. ¿Somos amigos, verdad? ¿Sin resentimientos?', 0),
(@ID, 'esMX', 'No quise decir nada con el comentario de que eres un estúpido $c. ¿Somos amigos, verdad? ¿Sin resentimientos?', 0);
-- 1247 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1247
SET @ID := 1247;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que sigues con vida, $n. ¿Todo fue bien?$B$BHe estado leyendo más sobre este plan suyo y, aunque no dice el nombre del diplomático al que perseguían, habla sobre un plan B que pusieron en marcha tras fallar su primer intento de captura.$B$BEse Slim al que mencionó Dashel no tiene ningún otro nombre aquí, pero si dices que está en Menethil, al menos es un comienzo.', 0),
(@ID, 'esMX', 'Me alegra ver que sigues con vida, $n. ¿Todo fue bien?$B$BHe estado leyendo más sobre este plan suyo y, aunque no dice el nombre del diplomático al que perseguían, habla sobre un plan B que pusieron en marcha tras fallar su primer intento de captura.$B$BEse Slim al que mencionó Dashel no tiene ningún otro nombre aquí, pero si dices que está en Menethil, al menos es un comienzo.', 0);
-- 1652 Escrito sobre valor
-- https://es.classic.wowhead.com/quest=1652
SET @ID := 1652;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Entonces, nos volvemos a encontrar, $n, y ya veo que estás de muy buen humor.$B$BLa casa de los Stilwell estará a salvo por otro día, y por tu historia veo que no había escasez de peligro. Bien hecho.$B$BDaphne y Jordan han ayudado mucho a la Iglesia, y lo menos que podíamos hacer por ellos era que protegieras sus propiedades y sus propias vidas.$B$BPor tu valor, serás recompensado.', 0),
(@ID, 'esMX', 'Entonces, nos volvemos a encontrar, $n, y ya veo que estás de muy buen humor.$B$BLa casa de los Stilwell estará a salvo por otro día, y por tu historia veo que no había escasez de peligro. Bien hecho.$B$BDaphne y Jordan han ayudado mucho a la Iglesia, y lo menos que podíamos hacer por ellos era que protegieras sus propiedades y sus propias vidas.$B$BPor tu valor, serás recompensado.', 0);
-- 1653 La prueba de rectitud
-- https://es.classic.wowhead.com/quest=1653
SET @ID := 1653;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres el que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0),
(@ID, 'esMX', 'Buen día, $n. ¿Confio en que la Luz está contigo?$B$B¿Que es eso? ¿¡Te envió Duthorian!? Mi esposa, ¿cómo esta ella? Sabía que habría problemas si me iba. Por favor dime que ella está... oh, gracias a Dios. Me alegro mucho de que esté a salvo. Los Defias eran una amenaza mucho antes de estos ataques, pero ahora los asesores del Rey no pueden negarlo.$B$B¿Qué más tenía que decir Duthorian?$B$B¿Eres el que fue enviado para proteger a mi esposa? Entonces te agradezco de nuevo, $n. No puedo pensar en una mejor prueba de valor que esa.', 0);
-- 1248 El diplomático desaparecido
-- https://es.classic.wowhead.com/quest=1248
SET @ID := 1248;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Te doy la bienvenida con los brazos abiertos, $n. Me alegra que te unas a nosotros. ¿Te apetece una cervecita? ¿O quizás algo de carne de ovino?$B$BDi lo que quieras y me encargaré de que lo tengas. Me llamo Mikhail, y solo deseo servirte bien.$B$B¿Mmm? ¿Qué es eso? ¿Trias? Habla bajo, amigo. Esto no es algo de lo que se deba enterar toda la taberna.', 0),
(@ID, 'esMX', 'Te doy la bienvenida con los brazos abiertos, $n. Me alegra que te unas a nosotros. ¿Te apetece una cervecita? ¿O quizás algo de carne de ovino?$B$BDi lo que quieras y me encargaré de que lo tengas. Me llamo Mikhail, y solo deseo servirte bien.$B$B¿Mmm? ¿Qué es eso? ¿Trias? Habla bajo, amigo. Esto no es algo de lo que se deba enterar toda la taberna.', 0);
-- 1578 Abastecer al frente
-- https://es.classic.wowhead.com/quest=1578
SET @ID := 1578;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'No tengo tiempo de charlar. ¿Querías algo?', 0),
(@ID, 'esMX', 'No tengo tiempo de charlar. ¿Querías algo?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Ah, perdona! No había visto que traes suministros. ¡Nos serán de gran ayuda!$B$BTen, es el patrón de una armadura; espero que te sea útil.', 0),
(@ID, 'esMX', '¡Ah, perdona! No había visto que traes suministros. ¡Nos serán de gran ayuda!$B$BTen, es el patrón de una armadura; espero que te sea útil.', 0);
-- 1618 Equipar Crestagrana
-- https://es.classic.wowhead.com/quest=1618
SET @ID := 1618;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Espero que estés aquí con buenas noticias de Forjaz. ¡Porque estoy al final de mi ingenio!.', 0),
(@ID, 'esMX', 'Espero que estés aquí con buenas noticias de Forjaz. ¡Porque estoy al final de mi ingenio!.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Gracias, $N. Esto me ayudará enormemente. Con los orcos Roca Negra atacando desde Stonewatch Keep y los gnolls Crestagrana acechando en las estribaciones del norte, siempre estoy arreglando armaduras y fabricando nuevas armas para nuestras tropas.$B$BLos suministros que trajiste me darán un respiro. Tendré tiempo suficiente para enseñarte algo ...', 0),
(@ID, 'esMX', 'Gracias, $N. Esto me ayudará enormemente. Con los orcos Roca Negra atacando desde Stonewatch Keep y los gnolls Crestagrana acechando en las estribaciones del norte, siempre estoy arreglando armaduras y fabricando nuevas armas para nuestras tropas.$B$BLos suministros que trajiste me darán un respiro. Tendré tiempo suficiente para enseñarte algo ...', 0);
-- 7793, 7798, 7803, 7808, 7814, 7821, 7827, 7834, 10354, 10360 Un donativo de seda
DELETE FROM `quest_request_items_locale` WHERE `ID` IN(7793, 7798, 7803, 7808, 7814, 7821, 7827, 7834, 10354, 10360) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES 
(7793, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7798, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7803, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7808, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7814, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7821, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7827, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7834, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10354, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10360, 'esES', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7793, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7798, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7803, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7808, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7814, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7821, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7827, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(7834, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10354, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0),
(10360, 'esMX', 'Nuestras reservas de seda, como las de los demás tejidos, están en su nivel mínimo. Si tú pudieras donarnos 60 paños de seda y consiguiéramos más de otras gentes, lograríamos cumplir nuestro objetivo.$B$BSi me permites, un regalo tan generoso como la seda aumentaría sin duda tu reputación en la comunidad... Si tienes los 60 paños de seda y quieres donarlos, puedo aceptar tu donativo ahora mismo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN(7793, 7798, 7803, 7808, 7814, 7821, 7827, 7834, 10354, 10360) AND `locale` IN('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES 
(7793, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7798, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7803, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7808, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7814, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7821, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7827, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7834, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10354, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10360, 'esES', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7793, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7798, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7803, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7808, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7814, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7821, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7827, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(7834, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10354, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0),
(10360, 'esMX', '¡Maravilloso! ¡Gracias por tu generosa donación, $n!', 0);
-- 1453 Los negocios de los Recuperadores en Desolace
-- https://es.classic.wowhead.com/quest=1453
SET @ID := 1453;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'Me alegra ver que aún queda gente aventurera.$B$BMe llamo Kreldig. Has hecho bien en unirte a los Recuperadores, $n. Todo el mundo busca algo: un tesoro, un amor perdido... Y tú puedes encontrarlo... por un precio.', 0),
(@ID, 'esMX', 'Me alegra ver que aún queda gente aventurera.$B$BMe llamo Kreldig. Has hecho bien en unirte a los Recuperadores, $n. Todo el mundo busca algo: un tesoro, un amor perdido... Y tú puedes encontrarlo... por un precio.', 0);
-- 707 ¡Vetaferro te necesita!
-- https://es.classic.wowhead.com/quest=707
SET @ID := 707;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Vienes de parte de Pico Tormenta? Muy bien.$B$BTengo trabajo para ti.', 0),
(@ID, 'esMX', '¿Vienes de parte de Pico Tormenta? Muy bien.$B$BTengo trabajo para ti.', 0);
-- 1050 Mitología de los titanes
-- https://es.classic.wowhead.com/quest=1050
SET @ID := 1050;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', 'El monasterio era un seminario para paladines. Fue un bastión de la Luz, pero cayó en manos de los fanáticos de la Cruzada Escarlata.$B$BCreían perseguir un noble objetivo: limpiar la tierra de la plaga de los no-muertos; pero acabaron enloqueciendo y enemistándose con todos.$B$BTráeme Mitología de los Titanes para que lo guarde aquí en Forjaz.$B$BLas corruptas salas del monasterio no son lugar para un tesoro como ese.', 0),
(@ID, 'esMX', 'El monasterio era un seminario para paladines. Fue un bastión de la Luz, pero cayó en manos de los fanáticos de la Cruzada Escarlata.$B$BCreían perseguir un noble objetivo: limpiar la tierra de la plaga de los no-muertos; pero acabaron enloqueciendo y enemistándose con todos.$B$BTráeme Mitología de los Titanes para que lo guarde aquí en Forjaz.$B$BLas corruptas salas del monasterio no son lugar para un tesoro como ese.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Me traes el texto sagrado!$B$BHas viajado lejos y sin duda fue difícil conseguir el libro. Pero tu labor beneficia a los enanos de Forjaz.$B$BGracias en nombre de la Liga de Exploradores, $n.', 0),
(@ID, 'esMX', '¡Me traes el texto sagrado!$B$BHas viajado lejos y sin duda fue difícil conseguir el libro. Pero tu labor beneficia a los enanos de Forjaz.$B$BGracias en nombre de la Liga de Exploradores, $n.', 0);
-- 2922 ¡Salva el cerebro de Tecnobot!
-- https://es.classic.wowhead.com/quest=2922
SET @ID := 2922;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Encontraste al techrobot? ¿Tienes el procesador central de memoria?', 0),
(@ID, 'esMX', '¿Encontraste al techrobot? ¿Tienes el procesador central de memoria?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¡Excelente! ¡Gracias, $n, voy a ponerme a trabajar de inmediato!$B$BPobre tecnobot, vaya susto te has llevado.$B$BEnseguida te arreglo; a ver, dónde estará mi llave inglesa giratoria con gato hidráulico...', 0),
(@ID, 'esMX', '¡Excelente! ¡Gracias, $n, voy a ponerme a trabajar de inmediato!$B$BPobre tecnobot, vaya susto te has llevado.$B$BEnseguida te arreglo; a ver, dónde estará mi llave inglesa giratoria con gato hidráulico...', 0);
-- 2039 Encuentra a Bingles
-- https://es.classic.wowhead.com/quest=2039
SET @ID := 2039;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` IN ('esES', 'esMX');
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(@ID, 'esES', '¿Así que Gnoarn cree que no sé arreglármelas solo? Pues no veo por qué...$B$BDa igual, ¡te necesito! Bueno, ¡el movimiento te necesita!', 0),
(@ID, 'esMX', '¿Así que Gnoarn cree que no sé arreglármelas solo? Pues no veo por qué...$B$BDa igual, ¡te necesito! Bueno, ¡el movimiento te necesita!', 0);
