-- 67 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=67
SET @ID := 67;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'El viejo baúl se abre con un crujido...', 0);
-- 95 La venganza de Sven
-- https://es.classic.wowhead.com/quest=95
SET @ID := 95;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hay un montón de tierra, apilada con prisas, como si alguien se hubiera visto obligado a esconder algo en poco tiempo.', 0);
-- 68 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=68
SET @ID := 68;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Me acuerdo de ti... Eres el que estaba preguntando por ese tal Stalvan. ¿Encontraste lo que estabas buscando?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Interesante... Así que ese individuo sí que pasó un tiempo en Arroyo de la Luna, después de todo. Resulta extraño que la carta nunca llegara a entregarse. En cualquier caso, voy a actualizar el registro.', 0);
-- 148 Suministros de Villa Oscura
-- https://es.classic.wowhead.com/quest=148
SET @ID := 148;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Ah, necesitas Hilo de pelo de fantasma, ¿no es así? Pues me temo que no tengo ninguno en el almacén, pero puedo hacértelo, si tú me proporcionas el pelo de fantasma.', 0);
-- 149 Hilo de cabello de fantasma
-- https://es.classic.wowhead.com/quest=149
SET @ID := 149;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Snif> Oh, por favor, ¡no me mires! ¡Arranqué estos ojos con mis propias manos, pero puedo sentir tu mirada fija en mí!$B$B¡Soy un monstruo! ¡Un monstruo horrible! ¡¡Por favor, no me mires!!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué es eso? ¿Un peine? ¡Es precioso! Y se desliza como seda por mi cabello, como si no fuera el alambroso y grasiento horror que es.$B$BAy, si tan solo tuviera un espejo...', 0);
-- 5 La hambruna de Alterio
-- https://es.classic.wowhead.com/quest=5
SET @ID := 5;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Un envío de mi hermano? ¡Espléndido! ¡La fortuna realmente me brilla hoy!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesitas croquetas de cangrejo, ¿verdad? Bueno, quizás pueda cocinarte algunas...', 0);
-- 93 Los pasteles de cangrejo oscuro
-- https://es.classic.wowhead.com/quest=93
SET @ID := 93;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Salve, $n. ¿Has conseguido esas patas pegajosas de araña ya?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Tienes un bonito ramillete de patas ahí! Deja que las condimente con mis especias secretas (¡no mires!) y las saltearé en una sartén...$B$BY, aunque las croquetas de cangrejo son mi especialidad y no te daré nunca la receta, sí te daré la de un plato que es casi igual de bueno.', 0);
-- 240 Regresa junto a Alterio
-- https://es.classic.wowhead.com/quest=240
SET @ID := 240;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '$n, ¡estás aquí! ¡¿Tienes mi comida?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Ajá! Gracias, $n. ¡Qué bien sientan estas cosas!$B$B¡Y ten, deja que te pague!', 0);
-- 154 Devuelve el peine
-- https://es.classic.wowhead.com/quest=154
SET @ID := 154;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Tengo la sensación de que has visto a Mary la Ciega. ¿Tienes mi peine...?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Con esto puedo hacerte un carrete de Hilo de pelo de fantasma y todavía me sobrarían algunas hebras. Ten, acepta estas monedas a cambio de esas hebras.', 0);
-- 157 Devolver el pelo
-- https://es.classic.wowhead.com/quest=157
SET @ID := 157;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesito colocar el hilo de cabello de fantasma en mis puertas y ventanas para mantener alejados a esos indeseables espíritus. ¿Me lo conseguiste?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Delicioso! Esto funcionará de maravilla.$B$BTen, $n, acepta esto como pago por tu honorable acción.', 0);
-- 158 Zumo de zombi
-- https://es.classic.wowhead.com/quest=158
SET @ID := 158;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Necesitas un poco de zumo de zombi, ¿verdad? Mmm... es un líquido muy fuerte... no me lo piden muy a menudo.', 0);
-- 230 El campamento de Sven
-- https://es.classic.wowhead.com/quest=230
SET @ID := 230;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Que has encontrado qué? Déjame verlo, por favor...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '<Sven lee las páginas del libro y luego lo cierra de un golpe.>$B$B¡Esa figura misteriosa que vi fue testigo de la muerte de mi familia! Hay preguntas que necesito hacerle a ese hombre... ¡si tan solo supiera quién es!', 0);
-- 262 La figura en las sombras
-- https://es.classic.wowhead.com/quest=262
SET @ID := 262;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Si tienes algo que pertenezca a la figura misteriosa que buscas, enséñamelo. Quizás pueda averiguar algo sobre su dueño.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Mmm... Alguien ha manipulado este libro hace poco... alguien guiado por la venganza. Pero las impresiones que hay en él, al menos las impresiones del dueño original, son débiles.$B$BPero sí puedo decirte que el dueño original de este libro no es oriundo de Villa Oscura.', 0);
-- 69 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=69
SET @ID := 69;
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Stalvan? Desde luego, me resulta familiar.', 0);
-- 70 La leyenda de Stalvan
-- https://es.classic.wowhead.com/quest=70
SET @ID := 70;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Qué tienes ahí? Deja que le eche un vistazo...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Cómo tienes la cara de traer esto aquí?', 0);
-- 333 Harlan necesita un nuevo suministro
-- https://es.wowhead.com/quest=333
SET @ID := 333;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Traes noticias de Bagley?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Dice aquí que el negocio de Harlan está floreciendo. Me alegra oír eso, pero me pregunto por qué la gente necesita tantas armaduras. No he oído nada sobre una declaración de guerra... ¿Acaso los nobles nos están ocultando información?$B$BEn fin, gracias por traer el pedido. Aquí tienes el pago, me encargaré de que Harlan reciba sus suministros.', 0);
-- 334 Un paquete para Thurman
-- https://es.wowhead.com/quest=334
SET @ID := 334;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¿Has venido a comprar ropa?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', '¡Oh, maldición! Creí que al haberme olvidado las herramientas, no tendría que trabajar. Aunque supongo que ahora tendré que ayudar a los Larson cosiendo...$B$BEn fin... Supongo que tendré que esperar hasta más tarde para divertirme.', 0);
-- 1078 Escamas cristalizadas para Mauren
-- https://es.classic.wowhead.com/quest=1078
SET @ID := 1078;
DELETE FROM `quest_request_items_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Hola otra vez, $n.$B$B¿Ya has regresado de La Vega Carbonizada de Espolón con las escamas?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = @ID AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (@ID, 'esES', 'Perfecto, $n. Muchas gracias.$B$BQuizás, algún día yo pueda ayudarte como tú me has ayudado a mí.', 0);
-- 7791, 7792, 7802, 7807, 7813, 7820, 7826, 7833, 10352, 10359 Un donativo de lana
DELETE FROM `quest_request_items_locale` WHERE `ID` IN (7791, 7792, 7802, 7807, 7813, 7820, 7826, 7833, 10352, 10359) AND `locale` = 'esES';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(7791, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7792, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7802, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7807, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7813, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7820, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7826, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(7833, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(10352, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0),
(10359, 'esES', 'Si tiene las sesenta piezas de paño de lana y está $glisto:lista; para donarlas, ahora puede hacerlo.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` IN (7791, 7792, 7802, 7807, 7813, 7820, 7826, 7833, 10352, 10359) AND `locale` = 'esES';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(7791, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7792, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7802, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7807, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7813, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7820, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7826, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(7833, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(10352, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0),
(10359, 'esES', '¡Maravilloso! ¡Le agradecemos su generosa donación, $N!', 0);
