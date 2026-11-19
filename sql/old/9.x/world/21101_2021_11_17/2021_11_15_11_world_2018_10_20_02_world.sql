-- 
-- Hellfire Peninsula -- Höllenfeuerhalbinsel
-- RequestItems, OfferReward -- master, 3.3.5

-- 9340 - Die Große Kluft
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9340 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9340, "deDE", "Gute Arbeit, $N. Das sollte die Felsklauen lehren, sich von uns fernzuhalten.", 26972);

-- 9345 - Herstellung der Salbe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9345 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9345, "deDE", "Habt Ihr die Pflanzen gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9345 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9345, "deDE", "Die sollten ihren Zweck erfüllen. Ich werde die Salbe fertigstellen und mein Bein schienen, bevor ich nach Thrallmar aufbreche. Wieso glaube ich genau zu wissen, was mir Scharfseherin Regulkut erzählen wird, wenn sie mich so sieht?$B$B<Grelag seufzt halbherzig.>$B$BVielen Dank für Eure Hilfe, $N. Ich habe noch einige von den Höllenwirbelkräutern übrig. Nehmt sie mit, wenn Ihr sie braucht. Wer weiß, wofür sie noch gut sind?", 26972);

-- 9349 - Felshetzereier sammeln
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9349 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9349, "deDE", "Habt Ihr die Eier schon?$B$B<Legassis Magen knurrt vor Vorfreude.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9349 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9349, "deDE", "Für ausgezeichnete Küche braucht man ausgezeichnete Zutaten. Und diese Eier sehen großartig aus!$B$BIch habe gerade meine Pfanne geputzt, Ihr seid also herzlich eingeladen, mir bei einem Mahl Gesellschaft zu leisten.", 26972);

-- 9351 - Wilde Leerwandler
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9351 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9351, "deDE", "Konntet Ihr die Essenzen besorgen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9351 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9351, "deDE", "Perfekt! Ich glaube sogar, dass das so gut funktionieren wird, dass ich den Motor umbauen muss, damit ich alle Vorteile dieses Kraftstoffs nutzen kann! Falls - ich meine natürlich - wenn wir hier wegkommen, muss ich allen in Area 52 meine Entwürfe zeigen!", 26972);

-- 9355 - Eine Aufgabe für einen intelligenten Helden
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9355 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9355, "deDE", "Gut gemacht, $N. Wir sollten uns aber nicht zu früh freuen. Ich bin mir sicher, dass wir diese Würmer nicht zum letzten Mal gesehen haben. Wenn sie ihre hässlichen Köpfe wieder in diese Gegend strecken sollten, werden die Söhne sie schon erwarten!", 26972);

-- 9356 - So weich wie Butter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9356 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9356, "deDE", "Ich kann es kaum erwarten, seinen Gesichtsausdruck zu sehen, wenn er reinhaut! Seit dem Absturz beschwert er sich, dass ich nur ans Essen denke. Nun, jemand muss uns schließlich ernähren, während er am Zeppelin herumschraubt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9356 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9356, "deDE", "Felshetzereier... Bämm!$B$BHölleneberspeck... Bämm!$B$BBussardflügel... Bämm! Bämm!$B$BWas für ein großartiges Essen. Ihr solltet wirklich mal probieren.", 26972);

-- 9361 - Hölleneber, die etwas andere Delikatesse
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9361 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9361, "deDE", "Habt Ihr das Hölleneberfleisch erfolgreich geläutert?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9361 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9361, "deDE", "Hmmm...$B$BEs sieht essbar aus, wenn man es richtig würzt. Erzählt Quack aber nicht, woraus sein Frühstück besteht, ja?", 26972);

-- 9366 - Die Suche nach Teufelsblut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9366 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9366, "deDE", "Das Teufelsblut... habt Ihr es bekommen, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9366 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9366, "deDE", "Die in den Proben gespeicherten Energien sind unfassbar stark, $N. Nun müssen wir nur noch sicherstellen, dass wir auch in Zukunft freien Zugriff auf das Teufelsblut haben.", 26972);

-- 9370 - Stoppt das Säuberungsritual
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9370 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9370, "deDE", "Ihr seid zurückgekehrt, $N. Habt Ihr dem Aberwitz der Draenei ein Ende gesetzt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9370 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9370, "deDE", "Das wird diese heiligen Fanatiker lehren, sich um ihren eigenen Kram zu kümmern.", 26972);

-- 9372 - Dämonische Verderbnis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9372 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9372, "deDE", "Habt Ihr die Blutproben bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9372 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9372, "deDE", "Gute Arbeit, $N. Diese Blutproben werden mir bei meinen Forschungen, und der Expedition bei ihren Studien der Scherbenwelt und ihrer Lebewesen, sehr dienlich sein.$B$BWenn ich den Grund für die fortschreitende Veränderung der Tiere herausfinden könnte, könnte ich vielleicht ein Gegengift herstellen.", 26972);

-- 9373 - Fehlender Schriftverkehr
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9373 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9373, "deDE", "Guten Tag, $C. Was bringt Euch in mein Lager?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9373 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9373, "deDE", "Danke, dass Ihr mir dies hier gebracht habt, $C. Ich habe mich schon gewundert, warum ich so lange nichts mehr von der Expedition gehört habe. Ich frage mich, wie lange diese Nachricht schon unterwegs ist und was wohl aus ihrem Überbringer geworden ist.$B$BHier habt Ihr etwas Geld für Eure Mühen.", 26972);

-- 9374 - Arelions Tagebuch
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9374 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9374, "deDE", "Hattet Ihr Glück, $N? Die Teiche von Aggonar liegen nördlich der Höllenfeuerzitadelle.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9374 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9374, "deDE", "Das Tagebuch meines Ehemanns... hat nicht das Geringste mit seinen Forschungen zu tun!$B$BWie konnte ich nur so blind sein? `Die magischen Eigenschaften dämonisch beeinflusster Schleimformen`, beinahe hätte ich es geglaubt.", 26972);

-- 9375 - Der Weg zur Falkenwacht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9375 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9375, "deDE", "<Taleris ruft einige der Blutelfen aus dem Außenposten herbei.>$B$BSchafft sie herein und versorgt ihre Wunden!$B$B<Taleris wendet sich wieder Euch zu.>$B$BSie kann sich glücklich schätzen, dass Ihr sie noch rechtzeitig gefunden habt, $C. Viel länger hätte sie dort draußen alleine nicht überlebt.$B$BKonntet Ihr verstehen, was sie gesagt hat?", 26972);

-- 9376 - Die Pflicht eines Pilgers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9376 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9376, "deDE", "Die Sache sieht nicht gut aus. So schafft sie es nie wieder auf die Straße. Habt Ihr den Beutel gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9376 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9376, "deDE", "Vielen Dank, dass Ihr dies zurückgebracht habt, $N. Ich weiß nicht, was der verletzten Pilgerin an diesem Beutel so wichtig ist, aber sie lässt keinen an sich heran, bis sie ihn wieder hat.", 26972);

-- 9381 - Treffsichere Pfeile
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9381 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9381, "deDE", "Habt Ihr alle Federn beisammen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9381 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9381, "deDE", "Die sollten ihren Zweck erfüllen. Ich hatte schon befürchtet, dass den Waldläufern bald die Pfeile ausgehen, doch nun muss ich mir darüber erstmal keine Sorgen mehr machen. Vielen Dank für Eure Hilfe, $C.", 26972);

-- 9383 - Ein gewagter Plan
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9383 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9383, "deDE", "Habt Ihr die Magie des Kristalls gegen einen unkontrollierten Leerwandler eingesetzt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9383 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9383, "deDE", "Ihr habt Euch bewährt, $N. Es scheint, als würde der Verwahrungskristall fürs Erste standhalten, allerdings weiß niemand wie lange. Wir werden ihn im Auge behalten und in der Zwischenzeit noch mehr Kristalle vorbereiten.", 26972);

-- 9385 - Tobende Felshetzer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9385 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9385, "deDE", "Gut gemacht, $N. Das wird den Biestern zeigen, wer hier der Boss ist!", 26972);

-- 9387 - Die Quelle der Verderbtheit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9387 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9387, "deDE", "Habt Ihr die Proben bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9387 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9387, "deDE", "Ihr wart mir eine große Hilfe, $N. Nun wollen wir sehen, was wir von unserem blauen Freund lernen können.", 26972);

-- 9390 - Die Suche nach Sedai
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9390 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9390, "deDE", "Ihr habt den Leichnam eines jungen Paladins der Draenei gefunden. Es scheint, als hätte ihn jemand hinterrücks erschlagen.", 26972);

-- 9391 - Den Weg kennzeichnen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9391 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9391, "deDE", "Habt ihr getan, worum ich Euch gebeten habe, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9391 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9391, "deDE", "Obwohl die Große Kluft noch immer ein gefährlicher Ort ist, gibt sie einen brauchbaren Pfad für unsere Pilger ab.$B$BEin derartiger Akt der Verzweiflung ist unvermeidlich, solange die Allianz weiterhin sämtliche ein- und ausgehenden Straßen zur Falkenwacht beobachtet.", 26972);

-- 9396 - Die Magie der Arakkoa
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9396 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9396, "deDE", "Habt Ihr die Schriftrollen, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9396 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9396, "deDE", "Gut gemacht, $N. Die Geheimnisse der Scherbenwelt werden sich nicht lange vor uns verstecken können.$B$BEs ist unser Schicksal, die Meister dieser Welt zu werden.", 26972);

-- 9397 - Kommt ein Vogel geflogen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9397 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9397, "deDE", "Ihr seid zurück. Habt Ihr mir ein Kaliriweibchen mitgebracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9397 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9397, "deDE", "Ihr habt es geschafft! Ihr habt ein junges Weibchen gefangen!$B$BSie ist wundervoll. Vielen, vielen Dank, $N.", 26972);

-- 9398 - Tödliche Raubtiere
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9398 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9398, "deDE", "Ihr habt gute Arbeit geleistet, $N. Es ist immer schlimm, wenn Töten die einzige Möglichkeit ist, die bleibt, sogar wenn es sich um so gefährliche Biester wie die Steinsichelklauen handelt.$B$BIhr habt meinen Dank, dass Ihr diese grausame Aufgabe erledigt habt.", 26972);

-- 9399 - Die Grausamkeit der Zuchtmeister
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9399 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9399, "deDE", "Ihr habt es geschafft! Wir stehen tief in Eurer Schuld, $N. Seht Euch nur all die Ankömmlinge des Lumpenpacks an.$B$BUnter meiner geistigen Führung werden sie alles über die alten Traditionen lernen.", 26972);

-- 9400 - Der Assassine
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9400 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9400, "deDE", "Der Leichnam stimmt mit der Beschreibung von Krun Rückenbrecher, dem Assassinen der Höllenfeuerzitadelle, überein. Als Ihr den noch warmen Körper umdreht, erblickt Ihr eine Steinaxt, die in seinem Rücken steckt.", 26972);

-- 9401 - Eine seltsame Waffe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9401 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9401, "deDE", "Sagt mir, ist der Assassine tot?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9401 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9401, "deDE", "Er wurde mit dieser Waffe getötet? Das ist unmöglich!$B$BHaben wir... haben wir sie tatsächlich gefunden?", 26972);

-- 9405 - Das Anliegen des Kriegshäuptlings
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9405 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9405, "deDE", "Sagt mir, wonach Ihr sucht, damit ich Euch bei der Suche unterstützen kann.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9405 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9405, "deDE", "Ich verstehe Nazgrels Anliegen, $C. Sagt nichts weiter.", 26972);

-- 9406 - Die Mag'har
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9406 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9406, "deDE", "Was habt Ihr für uns, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9406 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9406, "deDE", "Seid Ihr sicher? Das sind große Neuigkeiten, $N. Diese Orcs können sicherlich unserer Sache hier und auch zuhause dienlich sein!", 26972);

-- 9407 - Durch das Dunkle Portal
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9407 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9407, "deDE", "Unser Expeditionskorps kam ohne Probleme durch das Portal und hat ein neues Lager namens Thrallmar errichtet. Aber wie Ihr sehen könnt ist die Brennende Legion eingefallen und hat uns von unseren Brüdern abgeschnitten. Die Dämonen sind eindeutig darauf aus, das Dunkle Portal einzunehmen und uns daran zu hindern, Verstärkung aus Azeroth zu holen.", 26972);

-- 9410 - Spirituelle Führung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9410 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9410, "deDE", "Ihr könnt froh sein, dass Ihr noch lebt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9410 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9410, "deDE", "Wer seid Ihr, dass Ihr hier so einfach unangekündigt umherwandert? Ich habe meine Männer nur zurückgehalten, weil Ryga die Anwesenheit der Geister in Eurer Nähe verspürte.$B$BIhr könnt frei sprechen, doch wählt Eure Worte mit Bedacht. Wir vertrauen normalerweise keinen Fremden, die hier so nah bei der Zitadelle umherstreifen.", 26972);

-- 9417 - Die Arakkoabedrohung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9417 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9417, "deDE", "Fantastische Arbeit, $N! Ich ernenne Euch hiermit zum Langbart ehrenhalber.$B$BBleibt noch ein Weilchen und trinkt etwas mit uns!", 26972);

-- 9418 - Avruus Kugel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9418 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9418, "deDE", "Endlich habe ich meine Freiheit wieder!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9418 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9418, "deDE", "Mit dieser Kugel erlange ich meine Freiheit wieder. Nehmt Eure Belohnung, Sterblicher, auf dass meine Schuld bezahlt sei.", 26972);

-- 9420 - Feinste Daunen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9420 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9420, "deDE", "Habt Ihr die Kalirifedern, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9420 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9420, "deDE", "Ihr habt Euren Teil der Abmachung erfüllt. Ich schätze, Geschäft ist Geschäft!$B$BHier, mein Freund. Passt gut auf ihn auf.", 26972);

-- 9423 - Rückkehr zu Obadei
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9423 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9423, "deDE", "Sedai, mein geliebter Bruder... $B$BDiese feigen Orcs! Er war unbewaffnet, wie konnten sie nur?$B$BLasst mich alleine, $N. Ich danke Euch für Eure Hilfe, doch ich brauche jetzt etwas Zeit für mich selbst.", 26972);

-- 9424 - Makurus Rache
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9424 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9424, "deDE", "Habt Ihr Sedai in Makurus Namen gerächt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9424 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9424, "deDE", "Ja... Rache! Ihr wart gut.$B$BNehmt dies, es war ein Geschenk von Sedai. Wenn Makuru es behält, stimmt es ihn nur traurig.", 26972);

-- 9426 - Die Teiche von Aggonar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9426 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9426, "deDE", "Ja, ich fühle, wie die teuflische Präsenz in den Teichen abnimmt.$B$BIhr habt gute Arbeit geleistet, $N.", 26972);

-- 9427 - Reinigung des Wassers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9427 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9427, "deDE", "Ihr seid zurück, $N. Ist das Wasser gereinigt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9427 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9427, "deDE", "Die Essenz von Aggonar lebte in seinem verderbten Nachkommen Aggonis weiter. Dank Eures Erfolgs gegen den Dämon können wir nun beginnen, die Teiche zu ihrer ursprünglichen Reinheit zurückzuführen.$B$BIhr habt unseren Dank, $N. Eure Arbeit hat einen tiefen Eindruck in dieser Welt hinterlassen.", 26972);

-- 9430 - Relikte von Sha&apos;naar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9430 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9430, "deDE", "Habt Ihr die Relikte aus Sha'naar bei Euch, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9430 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9430, "deDE", "Das Glück hat Euch gesegnet. Genau wie ich es erhofft hatte, habt Ihr ein ganz besonderes Relikt zwischen all den anderen gefunden.", 26972);

-- 9438 - Bote für Thrall
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9438 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9438, "deDE", "Ihr bringt Kunde aus der Scherbenwelt, $C? Sodann, sprecht!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9438 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9438, "deDE", "<Thralls Augen werden immer größer, als er Nazgrels Brief liest.>$B$BMein Volk... wir müssen sie erreichen. Wir müssen Nagrand so schnell wie möglich erreichen!", 26972);

-- 9441 - Entsandt zu den Mag'har
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9441 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9441, "deDE", "Es bedeutet uns sehr viel, dass Ihr uns in diesen schwierigen Zeiten Eure helfende Hand reicht. Niemals werden wir Euch, noch denjenigen vergessen, der Euch hierher entsandt hat.$B$BEuch gebührt unser Dank.", 26972);

-- 9442 - Eine erschöpfende Krankheit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9442 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9442, "deDE", "Habt Ihr den Pilz schon besorgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9442 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9442, "deDE", "Gorkan hat viel Gutes über Euch gesagt. Wie sich herausstellt, war alles wahr.$B$BVielen Dank für Eure Hilfe.", 26972);

-- 9447 - Salbe verabreichen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9447 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9447, "deDE", "Ihr seid zurück, $N. Habt Ihr Eure Aufgabe erledigt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9447 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9447, "deDE", "Mögen die Geister Euch segnen, $N. die Mag'har stehen in Eurer Schuld.", 26972);

-- 9466 - GESUCHT: Schwarzkralle die Wilde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9466 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9466, "deDE", "Gibt es Neuigkeiten über Schwarzkralle?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9466 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9466, "deDE", "Ihr seid ein tapferer $C, $N. Diese Bestie hat viele meiner besten Jäger das Leben gekostet.$B$BNehmt die Belohnung, Ihr habt sie Euch redlich verdient.", 26972);

-- 9472 - Arelions Geliebte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9472 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9472, "deDE", "Hervorragend! Diese hinterhältige Göre wird sich mit niemandes Ehemann mehr davonschleichen.$B$BHier habt Ihr eine Kleinigkeit für Eure Mühen. Ich vertraue darauf, dass diese Angelegenheit unter uns bleibt, $N.", 26972);

-- 9483 - Die feinen Freuden im Leben
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9483 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9483, "deDE", "Vielleicht werden wir ja doch noch Freunde. Folgt mir! Wir wollen schließlich nicht mit den anderen teilen müssen, oder?", 26972);

-- 9490 - Die Felsklauenmatriarchin
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9490 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9490, "deDE", "Habt Ihr schon einen Beweis für Schwarzkralles Tod, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9490 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9490, "deDE", "Ja, an diese scharfen Krallen erinnere ich mich genau!$B$BNehmt diese Belohnung, $N. Ihr habt eine gefährliche Aufgabe erledigt. Ihr habt Euch jedes einzelne Stück hiervon verdient.", 26972);

-- 9492 - Das Schicksal wenden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9492 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9492, "deDE", "Seid Ihr mit den Überresten von Kriegshäuptling Messerfaust zurück?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9492 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9492, "deDE", "Gut gemacht, $N. Mit Eurem Sieg in der Höllenfeuerzitadelle haben wir den Orcs großen Schaden zugefügt.$B$BIhr müsst mit Feldkommandant Romus über das weitere Vorgehen und das Ziel, die Orcs weiter in der Defensive zu halten, sprechen. Jetzt, da wir Verstärkung haben, können wir die Ehrenfeste viel leichter verteidigen.", 26972);

-- 9493 - Der Stolz der Höllenhorde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9493 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9493, "deDE", "Ich bin nicht so blauäugig zu denken, dass ein Sieg über die Legionäre der Zerschmetterten Hand unseren Sieg über die gesamte Höllenhorde bedeutet, aber es ist ein guter Anfang.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9493 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9493, "deDE", "Das sind großartige Nachrichten, $N. Mit diesen Fortschritten bei der Höllenfeuerzitadelle können wir es vielleicht sogar wagen, die Höllenhorde auch in anderen Orten der Halbinsel und der ganzen Scherbenwelt zu bekämpfen.", 26972);

-- 9494 - Teufelsglut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9494 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9494, "deDE", "Habt Ihr die, ehm, Glut?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9494 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9494, "deDE", "Gut gemacht! Ich maße mir nicht an, Nethekurses Meisterwerke nachahmen zu können, aber wir wären dumm, wenn wir die Macht der Teufelsglut außer Acht lassen würden.$B$BEs gibt jedoch einige, die meine Art der Forschung verbieten wollen, deshalb muss ich meine Entdeckungen geheimhalten. Bitte erzählt niemandem davon, $N.", 26972);

-- 9495 - Der Wille des Kriegshäuptlings
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9495 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9495, "deDE", "Habt Ihr einen Beweis für den Sieg über Kargath Messerfaust?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9495 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9495, "deDE", "Das habt Ihr gut gemacht, $N. In seiner Jugend war Kargath Messerfaust ein vortrefflicher Krieger, ein Held und ein gutes Beispiel für sein Volk.$B$BSein Tod ist für uns alle schmerzhaft, jedoch besonders für Kriegshäuptling Thrall. Was auch immer in seinen letzten Tagen mit ihm geschehen sein mag, wir dürfen nie den Orc vergessen, der Kargath einst war, genauso wenig wie die Lektion, die uns sein Fall sein sollte.$B$BFür Eure Dienste für die Horde werdet Ihr mit einer dieser Waffen belohnt, $N.", 26972);

-- 9496 - Der Stolz der Höllenhorde
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9496 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9496, "deDE", "Ausgezeichnete Arbeit, $N. Jetzt, da die Legionäre gefallen sind, wird es einfacher, der Höllenhorde auf dem Schlachtfeld zu begegnen, auch wenn sie immer noch ein ernstzunehmender Gegner ist.", 26972);

-- 9498 - Falkenwacht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9498 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9498, "deDE", "Willkommen in der Falkenwacht, $R. Alle Verbündeten der Horde sind hier willkommen, insbesondere all jene, mit einer Empfehlung von Martik.", 26972);

-- 9499 - Falkenwacht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9499 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9499, "deDE", "Willkommen in der Falkenwacht, Bruder. Viele andere Blutelfen haben es leider nicht geschafft, heil hier anzukommen.$B$BEs ist eine Schande. Unsere Arbeit in der Scherbenwelt hat doch gerade erst begonnen.", 26972);

-- 9543 - Sühne
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9543 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9543, "deDE", "Wie kann ich Euch behilflich sein, $N? Ihr klingt, als hättet Ihr Sorgen.", 26972);

-- 9545 - Das Relikt des Sehers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9545 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9545, "deDE", "Habt Ihr eine Vision gehabt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9545 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9545, "deDE", "Tief in meinem Innersten hoffe ich, dass Eure Vision Euch neue Einblicke auf die Ereignisse, die zu Sedais Tod geführt haben, gewährt hat. Das Relikt zeigte Euch eine mögliche Reihe von Ereignissen, die zur Gegenwart führten. Die Wahrheit mag irgendwo dazwischen liegen, doch wir werden es nie mit Sicherheit erfahren.$B$BHättet Ihr mit Eurem jetzigen Wissen anders gehandelt?$B$BWer kann schon sagen, ob unser Konflikt mit den Orcs ewig währen wird? Doch am wichtigsten ist es, immer für alle Möglichkeiten offen zu sein.", 26972);

-- 9558 - Die Langbarts
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9558 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9558, "deDE", "Wie habt Ihr uns gefunden, $C? Egal, Ihr seid sicher hier, um uns zu helfen. Dann mal an die Arbeit!", 26972);

-- 9563 - Mirrens Vertrauen erlangen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9563 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9563, "deDE", "Probleme, das Bitter zu finden? Der gute alte Bernie in der Burg Nethergarde sollte Fässer davon auf Lager haben.$B$BEs sei denn, seine Vorräte sind ausgegangen... das wäre fatal!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9563 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9563, "deDE", "Oh ja! Ihr scheint ganz in Ordnung zu sein, $R. Ich denke, ich kann Euch vertrauen.", 26972);

-- 9572 - Die Bollwerke schwächen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9572 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9572, "deDE", "$N, richtig? Stok'ton hat mir gesagt, dass ich auf Euren Bericht warten soll.$B$BBringt Ihr gute Nachrichten?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9572 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9572, "deDE", "Das ist ein guter Anfang. Ohne diese drei sollten die Truppen verwirrt sein. Und solange ihre Artillerie außer Gefecht ist, haben wir bessere Chancen, näher vorzurücken, um die Zitadelle einzunehmen.$B$BAber es gehört mehr dazu, als man glaubt, ich fühle es. Deswegen habe ich einen weiteren Auftrag für Euch.$B$BFürs Erste jedoch habt Ihr Eure Arbeit gut gemacht. Sucht euch etwas aus Thrallmars Waffenkammer aus.", 26972);

-- 9575 - Die Bollwerke schwächen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9575 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9575, "deDE", "$N, richtig? Chadwick hat mir gesagt, dass ich auf Euren Bericht warten soll.$B$BWAS macht Ihr hier?! Habt Ihr Eure Aufgabe erledigt? Seid Ihr denn ein kompletter Vollidiot? Ich könnte mich übergeben!$B$BJetzt schwingt Euren nutzlosen Hintern zu diesem Bollwerk und tut, was Euch aufgetragen wurde! Habt Ihr mich gehört?!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9575 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9575, "deDE", "Wisst Ihr, was ich noch mehr hasse, als mich zu irren? Gold bei einer Wette zu verlieren, dass Ihr es nicht schafft, $GKumpel:Schätzchen;.$B$BAusgezeichnet! Ohne diese drei sollten die Truppen verwirrt sein. Und solange ihre Artillerie außer Gefecht ist, haben wir bessere Chancen, näher vorzurücken, um die Zitadelle einzunehmen.$B$BIch habe jedoch das Gefühl, dass da noch mehr dahinter steckt. Deswegen habe ich einen weiteren Auftrag für Euch. Hier, sucht Euch etwas aus der Waffenkammer aus!", 26972);

-- 9607 - Im Herzen des Hasses
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9607 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9607, "deDE", "Gefreiter, berichtet! Habt Ihr den Blutkessel schon erkundet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9607 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9607, "deDE", "SIE HABEN EINEN GRUBENLORD?!$B$B<Der Truppenkommandant bemerkt die starrenden Gesichter der anderen und senkt seine Stimme.>$B$BDas ist es. Sie müssen das Blut dieses Grubenlords verwenden, um neue Höllenorcs, die aus irgendeinem Grund nicht zur Brennenden Legion gehören, zu erschaffen. Und wenn sie das mit den braunen Mag'har können, schaffen sie das auch mit grünen! Bei all den Orcs, die durch das Dunkle Portal kommen, sind das alles andere als gute Nachrichten!$B$BWir müssen sie ins Herz ihrer Militärmacht treffen, und zwar bald!", 26972);

-- 9608 - Im Herzen des Hasses
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9608 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9608, "deDE", "Habt Ihr den Blutkessel schon erkundet? Was habt Ihr mir zu Berichten?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9608 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9608, "deDE", "SIE HABEN EINEN GRUBENLORD?!$B$B<Nazgrel bemerkt die starrenden Gesichter der anderen und senkt seine Stimme.>$B$BDas ist es. Sie müssen das Blut dieses Grubenlords verwenden, um neue Höllenorcs, die aus irgendeinem Grund nicht zur Brennenden Legion gehören, zu erschaffen. Und wenn sie das mit den braunen Mag'har können, schaffen sie das auch mit uns!$B$BWir müssen sie ins Herz ihrer Militärmacht treffen, und zwar bald!", 26972);

-- 9912 - Die Expedition des Cenarius
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9912 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9912, "deDE", "Willkommen in der Zuflucht des Cenarius, $N. Ich hoffe, Ihr könnt uns bei unserer Aufgabe behilflich sein. Wir haben viel Arbeit vor uns.", 26972);

-- 10046 - Durch das Dunkle Portal
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10046 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10046, "deDE", "Willkommen in der Scherbenwelt, $N - willkommen im Alptraum! Auch wenn das erste Expeditionskorps es unbeschadet hierher geschafft hat, versucht die Legion nun, das Portal zurückzuerobern und unsere Verstärkung daran zu hindern, es zu durchschreiten.$B$BIch würde Euch gerne hier einsetzen, aber unsere Truppen und die Soldaten der Horde können die Kolonnen der Legion, die diese Plattform erobern wollen, selbst zurückhalten.$B$BIhr müsst dorthin gehen, wo Ihr am meisten gebraucht werdet.", 26972);

-- 10047 - Der Pfad des Ruhms
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10047 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10047, "deDE", "Die Schreie scheinen irgendwie... schwächer geworden zu sein. Möge das Licht dafür sorgen, dass es nicht nur Wunschdenken ist.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10047 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10047, "deDE", "Ihr habt meinen aufrichtigen Dank für Eure Mühen, $N. Wenn auch noch viel zu tun ist, macht es mich froh, dass einige nun ihren wohlverdienten Frieden gefunden haben.", 26972);

-- 10050 - Unerschütterliche Seelen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10050 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10050, "deDE", "Die Söhne sind Euch für Eure Mühen dankbar, auch wenn nur wenige über das Rüstlager sprechen möchten.", 26972);

-- 10055 - Nichts verkommen lassen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10055 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10055, "deDE", "Habt Ihr ein wenig wiederverwertbares Material unter all dem Staub, der Asche und der Kohle finden können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10055 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10055, "deDE", "Das hier ist in einem besseren Zustand, als ich befürchtet habe. Sicher, es wird eine Weile dauern bis der ganze Rost und Zunder entfernt ist, aber ich kann mich nicht beklagen.", 26972);

-- 10057 - Suche nach den Anführern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10057 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10057, "deDE", "Wir können nur hoffen, dass die Geister der Fußsoldaten mit dem Verschwinden der Geister ihrer Offiziere zur Ruhe kommen. Ich danke Euch ein weiteres Mal für Eure Hilfe, $N.", 26972);

-- 10058 - Ein altes Geschenk
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10058 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10058, "deDE", "Ich dachte, ich hätte Euch gesagt, dass Ihr mich nicht stören sollt. Was gibt's?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10058 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10058, "deDE", "Ist es das? Kaum zu glauben, dass es die Schlacht überlebt hat. Die Gegebenheiten in den Ruinen waren nicht gerade gut für das Buch, aber ich bin dennoch froh, dass ich es wiederhabe.$B$BEs ist das einzige Zeichen, das ich von Turalyon habe.$B$B<Vater Devidicus scheint mit den Tränen zu kämpfen.>$B$BWenn man so lange Zeit Seite an Seite gekämpft hat, steht man sich noch näher als die eigene Familie.", 26972);

-- 10078 - Die Unerwünschten zerstören
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10078 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10078, "deDE", "Ihr scheint guter Laune zu sein. Haben die brennenden Belagerungsmaschinen der Horde Euch erheitert?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10078 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10078, "deDE", "Das nenne ich Einsatz!$B$BIch bin froh, dass wir endlich Unterstützung erhalten haben, aber ich bin nicht so sicher, ob sie die richtige Einstellung gegenüber der Horde haben. Dort, wo ich herkomme, ist jeder, der eine Waffe auf Euch richtet, ein Feind und muss vernichtet werden.", 26972);

-- 10079 - Bringt diese Mine zum Beben!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10079 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10079, "deDE", "Bei Bronzebarts bronzenem... Bart, Ihr habt es geschafft! Ihr seid ein Held, $N.", 26972);

-- 10086 - Ich arbeite... für die Horde!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10086 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10086, "deDE", "Wie geht es mit der Sammelaktion voran? Habt Ihr etwas Wiederverwertbares finden können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10086 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10086, "deDE", "Die Materialien sind ausgezeichnet! Vielleicht ein wenig verbogen oder angesengt, aber ich habe mich noch nie von minderwertigem Material aufhalten lassen, wenn es darum ging, Präzisionssprengstoff herzustellen!$B$BDanke, $N. Ihr habt wirklich ein Händchen exquisiten Müll!", 26972);

-- 10087 - Zündet es an... für die Horde!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10087 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10087, "deDE", "Ich habe nach Zeichen von brennenden Kanonen Ausschau gehalten - Rauchschwaden oder den Schreien brennender Höllenorcs...$B$BHattet Ihr Erfolg mit Eurem Auftrag?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10087 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10087, "deDE", "Dachte ich's mir doch! Ich konnte die Zerstörung von hier aus zwar nicht richtig sehen, aber ich kann sie mir redlich vorstellen! Ausgezeichnet!$B$BGut gemacht, $N. Das oberste Kommando von Thrallmar wird sich freuen, von Eurem Erfolg zu hören!", 26972);

-- 10093 - Der Tempel von Telhamat
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10093 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10093, "deDE", "Ah, Ihr habt also Seher Kryv getroffen. Er ist ein weiser und begabter Mann, und seine Freunde sind auch meine Freunde.$B$BMacht es Euch gemütlich und stellt Euch den anderen vor, die diesen Tempel ihr Zuhause nennen.", 26972);

-- 10099 - Das Genie
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10099 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10099, "deDE", "Ich bin froh, dass Ihr Euch um, um... wie sagtet Ihr hieß er noch gleich? Z'kral?$B$BEurer Beschreibung nach war es wohl mehr ein es als ein er. Nun ja, was zählt ist, dass es tot ist.", 26972);

-- 10103 - Bericht an Zurai
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10103 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10103, "deDE", "Um ehrlich zu sein hatte ich mehr Leute erwartet, aber Ihr müsst reichen. Willkommen im Sumpfrattenposten.", 26972);

-- 10106 - Höllenfeuerbefestigungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10106 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10106, "deDE", "Gut gemacht, $N. Eure Taten auf dem Schlachtfeld sind für unseren Kampf auf der Höllenfeuerhalbinsel sehr hilfreich.", 26972);

-- 10110 - Höllenfeuerbefestigungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10110 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10110, "deDE", "Gute Arbeit, $N. Ich konnte fast die Kampfschreie an den Befestigungsanlagen hören. Ich wünschte, ich wäre dabei gewesen!", 26972);

-- 10119 - Durch das Dunkle Portal
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10119 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10119, "deDE", "Willkommen in der Scherbenwelt, $N - willkommen im Alptraum! Auch wenn das erste Expeditionskorps es unbeschadet hierher geschafft hat, versucht die Legion nun, das Portal zurückzuerobern und unsere Verstärkung daran zu hindern, es zu durchschreiten.$B$BIch würde Euch gerne hier einsetzen, aber unsere Truppen und die Soldaten der Horde können die Kolonnen der Legion, die diese Plattform erobern wollen, selbst zurückhalten.$B$BIhr müsst dorthin gehen, wo Ihr am meisten gebraucht werdet.", 26972);

-- 10120 - Ankunft in der Scherbenwelt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10120 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10120, "deDE", "Ich habe gesehen, wie Ihr mit Orion gesprochen habt - es muss eine wichtige Angelegenheit sein...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10120 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10120, "deDE", "Ihr seid also Orions neuer Bote? Ich hoffe, es ergeht Euch besser als dem letzten, den er geschickt hat, $C. Mit der vorrückenden Legion schafft Ihr es niemals zu Fuß nach Thrallmar. Sagt Bescheid und mein treuer Wyvern wird Euch sicher dorthin bringen.", 26972);

-- 10121 - Die Brennende Legion ausrotten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10121 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10121, "deDE", "Ihr habt sicher auf Eurem Flug vom Dunklen Portal die Krieger der Legion überall in der Landschaft gesehen. Auch wenn wir sie in der Schlacht am Berg Hyjal vor etwa 5 Jahren besiegt haben, haben diese verfluchten Dämonen immer noch nicht genug. Wenn sie auf eine Herausforderung aus sind, wird die Horde ihnen entsprechend antworten!$B$BWir Orcs haben mit der Legion mehr als nur eine Rechnung zu begleichen! Was ist mit Euch, $N? Soll ich Euch von unserem Feind erzählen?", 26972);

-- 10123 - Teufelsfunkenklamm
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10123 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10123, "deDE", "Ausgezeichnete Arbeit, Soldat. Die Häufigkeit der Angriffe wird nun sicher nachlassen - zumindest bis sie neue Schreckenslords schicken.$B$BNun zu den schlechten Nachrichten: ich habe Eure neuen Befehle...", 26972);

-- 10124 - Vorposten: Häschersturz
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10124 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10124, "deDE", "Ihr habt also die Teufelsfunkenklamm aufgeräumt, was? Gut zu hören - wir brauchen Soldaten wie Euch, die sich kopfüber in die Schlacht stürzen!", 26972);

-- 10129 - Mission: Tore Murketh und Shaadraz
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10129 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10129, "deDE", "Wenn Ihr beim ersten Versuch verfehlt, startet einen neuen...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10129 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10129, "deDE", "Das wird sie um Wochen zurückwerfen! Fantastische Arbeit, $N. Die Legion hätte sicher nie mit so starkem Widerstand gerechnet.", 26972);

-- 10132 - Eine kolossale Bedrohung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10132 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10132, "deDE", "Gute Arbeit.$B$BWenn Ihr mich fragt, müssen wir einfach genug von diesen Kolossen töten, dann brauchen wir uns nicht mehr um diese merkwürdigen Kristall in der Mitte kümmern.$B$BHier, nehmt eines hiervon als Belohnung der Expedition des Cenarius.", 26972);

-- 10134 - Hinweise des purpurnen Kristalls
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10134 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10134, "deDE", "Das ist ein ganz schön großer Kristall, den Ihr da habt. Habt Ihr ihn von den Kolossen im Grat?$B$BLasst mich ihn anschauen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10134 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10134, "deDE", "Hm, für mich sieht es einfach wie ein großer Klumpen ungeschliffenen Kristalls aus.$B$BZugegeben, ich fühle eine kranke, böse Aura, die von ihm ausgeht, aber das ist nicht gerade mein Spezialgebiet. Ich bin nur hier, um die Bedrohung durch die Bergriesen aufzuhalten.", 26972);

-- 10136 - Grausame Pläne
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10136 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10136, "deDE", "Alle kommenden Generation werden diesen Tag bejubeln, $N. Sie werden von Eurem Heldenmut singen. Ich wünschte, Thrall wäre hier, um diesen Sieg mit uns zu feiern. Die Legion liegt am Boden, und die Höllenfeuerhalbinsel gehört wieder der Horde! Vielleicht besteht doch noch Hoffnung für diese verwüstete Welt und unser Volk auf ihr.$B$BLok'tar ogar!", 26972);

-- 10140 - Reise zur Ehrenfeste
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10140 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10140, "deDE", "Dem Licht sei Dank, dass Ihr heil hier angekommen seid. Die Ehrenfeste benötigt alle erfahrenen Krieger, die sie bekommen kann.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10140 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10140, "deDE", "Unsere Expedition zu dieser verlassenen, zerschlagenen Welt wäre fast zum Stillstand gekommen, $N. Wir haben mehr Widerstand erfahren, als wir dachten.$B$BAls ob die Brennende Legion nicht schon schlimm genug wäre, gibt es in diesen Ländern Schrecken, die wir noch nie zuvor gesehen haben.", 26972);

-- 10141 - Wiedergeburt der Brennenden Legion
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10141 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10141, "deDE", "Truppenkommandant Danath hat meine Anfrage nach Verstärkung wohl etwas falsch verstanden. Ihr seht zwar fähig aus, aber... ich habe um ein komplettes Bataillon gebeten!$B$BWisst Ihr, wir haben da ein kleines Dämonenproblem.", 26972);

-- 10142 - Der Pfad der Pein
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10142 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10142, "deDE", "Ausgezeichnete Arbeit, Soldat. Die Häufigkeit der Angriffe wird nun sicher nachlassen - zumindest bis sie neue Schreckenslords schicken.$B$BNun zu den schlechten Nachrichten: ich habe Eure neuen Befehle...", 26972);

-- 10143 - Expeditionsposten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10143 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10143, "deDE", "Schön, Euch kennenzulernen, Soldat.$B$BGenug gequatscht... nun hört zu - Ich habe eine wichtige Mission für Euch und ich möchte, dass Ihr sie erfüllt... und überlebt!", 26972);

-- 10144 - Die Verstärkung abschneiden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10144 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10144, "deDE", "Ich wünschte, ich hätte die Feuer sehen können. Dieser Sprengstoff hat mächtig Dampf!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10144 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10144, "deDE", "Gut gemacht, $N. Die Zerstörung der Portale wird den Nachschub an Verstärkung für die Legion für eine Weile bremsen!$B$BAber noch können wir uns nicht ausruhen...", 26972);

-- 10146 - Mission: Tor Murketh und Tor Shaadraz
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10146 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10146, "deDE", "Dies ist ein wichtiger Auftrag, $N. Ich würde ihn nicht an irgendjemanden vergeben.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10146 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10146, "deDE", "Das wird sie um Wochen zurückwerfen, kein Zweifel! Ihr habt mir gerade ungewöhnlich gute Laune verschafft, $N!", 26972);

-- 10159 - Haltet den Dornnebelhügel sauber!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10159 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10159, "deDE", "Wie läuft es mit der Bereinigung des Dornnebelhügels?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10159 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10159, "deDE", "Jetzt, da die Verheerer fort sind, können die Reisenden der Zuflucht des Cenarius in den Zangarmarschen wieder sicher vorankommen.$B$BDie Expedition des Cenarius ist Euch etwas schuldig, $N.", 26972);

-- 10160 - Den Feind kennen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10160 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10160, "deDE", "<Leutnant Amadi nickt.>$B$BGut, wir können jede Hilfe gebrauchen. Die zunehmende Orcbevölkerung am Südlichen Bollwerk bereitet mir Kopfschmerzen. Ich habe einen Späher losgeschickt, um sie zu erkunden, aber er ist noch nicht zurück.", 26972);

-- 10161 - Im Notfall...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10161 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10161, "deDE", "Habt Ihr genügend Teile gefunden? Wenn nicht muss ich die Bratpfanne verwenden, mit der Legassi die ganze Zeit herumwedelt. Dann muss ich den Zeppelin in die `Fliegende Bratpfanne` umbenennen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10161 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10161, "deDE", "Einige davon sind in einem ziemlich schlechten Zustand, aber ich sollte damit zurechtkommen. Es braucht nur ein wenig kreative Ingenieurskunst und es wird sicher klappen!", 26972);

-- 10162 - Mission: Die Abyssische Untiefe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10162 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10162, "deDE", "Zeigt ihnen, dass nicht einmal die Himmel sicher sind!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10162 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10162, "deDE", "Ihr fliegt, als hättet Ihr Euer Leben lang nichts anderes getan, $N. Hervorragende Vorstellung! Und nicht einmal ein kleiner Kratzer an den Wyvernzerstörern!", 26972);

-- 10163 - Mission: Die Abyssische Untiefe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10163 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10163, "deDE", "Zeigt ihnen, dass nicht einmal die Himmel sicher sind!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10163 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10163, "deDE", "Ihr fliegt, als hättet Ihr Euer Leben lang nichts anderes getan, $N. Hervorragende Vorstellung! Und nicht einmal ein kleiner Kratzer an den Greifenzerstörern!", 26972);

-- 10208 - Die Verstärkung abschneiden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10208 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10208, "deDE", "Die Legion ist bestimmt nicht auf unsere Überraschung gefasst, was, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10208 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10208, "deDE", "Gut gemacht! Ich konnte die Explosionen fast bis hierher spüren!$B$BJetzt haben wir noch eine weitere Bombenmission für Euch...", 26972);

-- 10213 - Untersuchung der Absturzstelle
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10213 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10213, "deDE", "Wir wurden von der Brennenden Legion abgeschossen, obwohl wir eine Friedensflagge geschwenkt haben. Wer hätte ahnen können, dass die Brennende Legion so gemein ist?$B$BWir können leider nicht mit Euch zum Rückenbrecherposten kommen. Wir müssen den Zeppelin reparieren und dann weiterziehen.", 26972);

-- 10220 - Bringt sie zum Zuhören
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10220 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10220, "deDE", "Die Unerschütterlichen haben die Macht der Horde gespürt. Vielleicht haben sie jetzt ja Lust, sich meinen Vorschlag anzuhören.", 26972);

-- 10229 - Den Folianten entziffern
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10229 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10229, "deDE", "Was ist das? Ein Buch von einem unerschütterlichen Geist? Wie merkwürdig. Lasst es mich anschauen, vielleicht kann ich mehr über die Geschichte der Unerschütterlichen erfahren.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10229 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10229, "deDE", "Ich habe mein ganzes Unleben lang alte Geschichte studiert, doch nie zuvor etwas wie dieses Buch gesehen. Er erzählt die gesamte Geschichte des Rüstlagers, sogar die Ereignisse nach seiner Zerstörung.$B$BDie Unerschütterlichen haben ihre Geschichte aufgeschrieben, sogar nach ihrem Tod in der Schlacht. Mit diesem Buch können wir die Unerschütterlichen verstehen und sie sicher davon überzeugen, sich uns anzuschließen.", 26972);

-- 10230 - Das Kampfhorn
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10230 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10230, "deDE", "Wir müssen den Unerschütterlichen bald helfen. Wenn wir sie davon überzeugen können, sich uns anzuschließen, hat die Horde einen starken Verbündeten.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10230 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10230, "deDE", "Gut gemacht, $N. Dieses alte Horn wird uns helfen, die Unerschütterlich zu rufen.$B$BNatürlich nur, wenn sie es möchten.", 26972);

-- 10236 - Die Scherbenwelt ist doof!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10236 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10236, "deDE", "Habt Ihr schon ein paar Ersatzteile für meinen Schredder gefunden? Ich möchte ihn wirklich gerne reparieren, damit ich mich weiter dem Bergbau in der Mine widmen kann. Irgendwie muss ich ja ein wenig Geld verdienen. Und wenn ich davon nur eine Fahrkarte nach Beutebucht kaufe. Ohne Rückfahrt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10236 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10236, "deDE", "Hurra, Ihr habt ein paar Teile gefunden! Jetzt kann ich meinen Schredder hoffentlich wieder zum Laufen bringen. Wenn ich genug Geld verdiene, kann ich vielleicht wieder zurück nach Beutebucht.$B$BIch hoffe, dass mein Vetter Quack Lufthans mit seinem blöden Zeppelin abstürzt. Ich kann es nicht fassen, dass er mich so hinterhältig in die Scherbenwelt gelockt hat.", 26972);

-- 10238 - Wie man Goblins zubereitet
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10238 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10238, "deDE", "Vielen Dank, dass Ihr meine Peons gerettet habt. Vielleicht kann ich sie jetzt dazu bringen, meinen Schredder mit den Teilen, die Ihr gefunden habt, zu reparieren. Dann kann ich wieder etwas Geld verdienen und aus der Scherbenwelt abhauen. Ich kann es kaum abwarten, wieder in Beutebucht zu sein.", 26972);

-- 10242 - Der Rückenbrechergrat
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10242 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10242, "deDE", "Willkommen im Rückenbrechergrat. Wie kann ich Euch dienen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10242 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10242, "deDE", "Ein Bluttest also? Es wird mir ein Vergnügen sein. Ich arbeite immer gerne mit Blut...", 26972);

-- 10250 - Blutige Rache
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10250 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10250, "deDE", "Habt Ihr schon in das Horn gestoßen? Wir müssen es bald tun. Wer weiß, wann Thrallmar die Unterstützung der Unerschütterlichen braucht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10250 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10250, "deDE", "Ich bin froh, dass die Unerschütterlichen Euch im Kampf unterstützt haben. Ich dachte mir schon, dass sie dem Ruf ihres Schlachthorns folgen würden, aber ich war mir nicht sicher. Vielleicht haben wir ihnen jetzt die Rache ermöglicht, die sie so sehr begehrten.$B$BIhr habt Urtrak getötet. Diesen Sieg müssen wir Kommandant Hogarth im Rüstlager der Allianz melden. Er wird verstehen, welche Gefahren Ihr für ihn auf Euch genommen habt.", 26972);

-- 10254 - Truppenkommandant Danath
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10254 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10254, "deDE", "Ich bin froh, dass Ihr hier seid, Bruder. Ich bin Danath Trollbann - Anführer der Söhne des Lothar und Truppenkommandant dieser Feste.", 26972);

-- 10255 - Das Gegengift testen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10255 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10255, "deDE", "Habt Ihr die Ergebnisse des Experiments, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10255 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10255, "deDE", "<Thiah Rotmähne macht große Augen, als Ihr die Ergebnisse des Experiments beschreibt.>$B$BWie konnte das nur geschehen? Ich bin mir sicher, dass ich das Gegengift richtig hergestellt habe!$B$BIch habe gesehen, wie es mit Spinnen- und Schlangengiften funktioniert hat, warum kehrt sich die Wirkung hier nicht um? Vielleicht ist das eine der vielen Besonderheiten der Scherbenwelt, $N. Ich leite diese Information am besten an meine Kameraden weiter.", 26972);

-- 10258 - Die Gefallenen ehren
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10258 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10258, "deDE", "Wir haben die Schlacht vor so langer Zeit gegen die Höllenorcs verloren. Ihr habt uns unsere Ehre zurückgegeben, indem Ihr Urtrak getötet habt.$B$BNehmt Euch eine unserer Waffen. Wenn Ihr gegen unseren verhassten Feind in den Kampf zieht, benutzt diese Waffe, und die unter uns, die frei vom Fluch sind, werden Euch zu Hilfe kommen.$B$BBevor Ihr geht möchten einige, die vor Jahren beim Belagerungsturm gefallen sind, Euch für die Zerstörung unseres Feindes Ehre erweisen.", 26972);

-- 10278 - Sphärenrisse
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10278 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10278, "deDE", "Habt Ihr meinen Apparat schon ausprobiert? Ich glaube, dass mein instabiler Sphärenrissgenerator so nahe am Abgrund funktionieren sollte.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10278 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10278, "deDE", "Unglaublich. Ihr habt die Leere selbst berührt! $N, Ihr habt mein Lebenswerk gerettet. Aber es gibt noch mehr, was getan werden muss, und Ihr könnt mir helfen.", 26972);

-- 10286 - Arelions Geheimnis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10286 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10286, "deDE", "Ich werde reden, $C. Nehmt die Waffe runter, ich will nicht noch mehr Ärger haben.", 26972);

-- 10287 - Die enttarnte Geliebte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10287 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10287, "deDE", "Viera Sonnenwisper? Diese widerliche kleine Göre.$B$BIch werde ihr zeigen, dass man mit mir keine Spielchen treibt!", 26972);

-- 10288 - Ankunft in der Scherbenwelt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10288 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10288, "deDE", "Ich habe gehört, wie Ihr mit Duron gesprochen habt. Ihr müsst einen wichtigen Auftrag haben!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10288 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10288, "deDE", "Berichte für die Ehrenfeste? Kein Problem, einer meiner Greifen wird Euch schnell und sicher dorthin bringen.", 26972);

-- 10289 - Reise nach Thrallmar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10289 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10289, "deDE", "Ein Bericht von Orion? Gebt ihn mir, schnell!$B$B<Stirnrunzelnd überfliegt General Krakork den zerknitterten Brief.>$B$BVerdammt, es ist genau so, wie wir es befürchtet haben. Orion und seine Krieger können jeden Moment überrannt werden!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10289 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10289, "deDE", "Ich werde alle Truppen, die ich entbehren kann, zu Orion beim Dunklen Portal schicken. Die Legion wird den Schlachtruf der Horde nicht so bald vergessen! Ihr, $N, habt Thrallmar heute einen großen Dienst erwiesen. Ich glaube, Ihr könnt uns hier eine große Hilfe sein. Natürlich nur, wenn Ihr klug genug seid, um zu überleben.", 26972);

-- 10291 - Bericht an Nazgrel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10291 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10291, "deDE", "Wir haben schon viele tapfere Krieger an dieses verfluchte Land verloren. Ich habe kein Interesse daran, noch mehr ungeprüfte Rekruten in das Massaker zu schicken.$B$B<Nazgrel schaut Euch durch seine zottige Wolfsmaske streng an.>$B$BAber wenn General Krakork Euch zu mir geschickt hat, muss an Euch ja etwas dran sein. Was sagt Ihr also, $N? Werdet Ihr dem Kriegshäuptling mit Ehre dienen?", 26972);

-- 10294 - Der Leerengrat
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10294 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10294, "deDE", "Habt Ihr es schon getan? Habt Ihr die Splitter?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10294 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10294, "deDE", "Ausgezeichnet. Der verbesserte Sphärenrissgenerator ist fast fertig. Es gibt nur noch einen letzten Bestandteil, den wir brauchen. Bald können wir einen stabilen Sphärenriss öffnen, den wir in den kommenden Jahren untersuchen können.$B$BWer weiß, welche fremdartigen Kreaturen durch ihn hindurchkommen werden? Stellt Euch nur vor, $N, die Macht, die ein solches Wissen mit sich brächte, wäre unermesslich!", 26972);

-- 10295 - Aus dem Abgrund
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10295 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10295, "deDE", "Habt Ihr den Baron der Leere Galaxis schon vernichtet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10295 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10295, "deDE", "Ihr habt mein Lebenswerk gerettet, $N.$B$BSie haben mich wahnsinnig genannt, mich ausgelacht und gedacht, meine Besessenheit auf den Leerengrat und die Sphärenfelder hätte mich krank gemacht. Mit diesem Seelensplitter kann ich das Geheimnis der Leerwandler lüften. Ich werde die Macht über den Abgrund beherrschen!", 26972);

-- 10340 - Trümmerposten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10340 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10340, "deDE", "Ha ha! Ein frischer $R vom Festland! Nun, keine Sorge - der Trümmerposten kann Euch vielleicht etwas seekrank machen, aber er treibt nicht weit weg!$B$BUnd bisher hat er sich nur einmal auf den Kopf gedreht... oder zweimal.", 26972);

-- 10344 - Schwadronskommandant Greifgar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10344 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10344, "deDE", "Ihr habt mit Runetog gesprochen? Er ist ein guter Zwerg, hält seine Greifen gut in Schuss und immer kampfbereit.$B$BIch bin Greifgar, Kommandant des Trümmerpostens. Ich weiß, es ist nicht gerade hübsch hier, aber dieser Felsklotz ist ein wichtiger Stützpunkt für Operationen auf der Höllenfeuerhalbinsel. Man kann hier rund um die Uhr Greifen ein- und ausfliegen sehen.$B$BEinen Rat? Hier ist einer: haltet Eure Ausrüstung bereit, Euren Magen leer und Eure Augen am Horizont... wenn der Trümmerposten anfängt auseinanderzufallen, haltet Euch an etwas fest, was nicht wegfliegen kann!", 26972);

-- 10346 - Rückkehr zur Abyssischen Untiefe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10346 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10346, "deDE", "In der Abyssischen Untiefe sind immer noch genügend Ziele, $N. Schnappt Euch einen Greifen, wenn Ihr für eine weitere Runde bereit seid.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10346 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10346, "deDE", "Wie ist es gelaufen? Ihr seid ja in guter Verfassung... Ist sie gut genug für einen weiteren Flug?", 26972);

-- 10347 - Rückkehr zur Abyssischen Untiefe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10347 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10347, "deDE", "Die Legion darf sich auf der Abyssischen Untiefe nicht in Sicherheit wiegen! Wir müssen immer und immer wieder zuschlagen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10347 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10347, "deDE", "Die anderen Windreiterführer halten sehr viel von Euch, $N. Ihr habt in der Abyssischen Untiefe ganz schön aufgeräumt. Macht weiter so!", 26972);

-- 10349 - Die Erdbinderin
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10349 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10349, "deDE", "Ist das ein Stück des riesigen Kristallsplitters oben auf dem Himmelssturzgrat?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10349 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10349, "deDE", "Oh, ausgezeichnet!$B$BIch habe die ganze Zeit gehofft, an ein Stück davon zu kommen, aber Tola'thion kommt nicht in die Gänge. Er sollte mir eigentlich helfen herauszufinden, was im Himmelssturzgrat vor sich geht. Stattdessen schickt er nur arme Tölpel wie Euch - nichts für ungut - dort hoch auf die Schlachtbank.$B$BWenn Ihr mir den Kristall gebt, kann ich vielleicht herausfinden, in welcher Verbindung er zu den Kolossen steht.", 26972);

-- 10351 - Natürliche Heilmittel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10351 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10351, "deDE", "Hat es funktioniert? Was habt Ihr beobachtet? Habt Ihr herausgefunden, was im Himmelssturzgrat passiert ist?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10351 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10351, "deDE", "Goliathon? Pathaleon der Kalkulator?$B$BKAEL'THAS!?$B$BPrinz Kael'thas hat seine Hand im Spiel?!$B$B<Die Erdbinderin schäumt vor Wut.>$B$BWas er getan hat ist Wahnsinn! Riesige Kristalle vom Himmel zu werfen und das Land zu dezimieren kann nur die Arbeit eines Verrückten sein!$B$BIch verspreche Euch, dass der Zirkel des Cenarius nun, da wir wissen was zu tun ist, jegliche weitere Versuche von Illidan und seinen Streitmächten, so etwas noch einmal zu tun, von uns vereitelt werden.$B$BWir stehen tief in Eurer Schuld, $N.", 26972);

-- 10367 - Ein Verräter unter uns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10367 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10367, "deDE", "Habt Ihr den Schlüssel schon, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10367 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10367, "deDE", "Ich danke Euch, $N. Dank Eurer Hilfe wird mein Volk bald frei sein.", 26972);

-- 10368 - Die Ältesten des Lumpenpacks
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10368 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10368, "deDE", "Sagt mir, $N. Sind die Ältesten des Lumpenpacks schon frei?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10368 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10368, "deDE", "Ich kann es fühlen, $N! Die Geister kehren zu uns zurück.", 26972);

-- 10369 - Arzeths Untergang
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10369 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10369, "deDE", "Ist es vollbracht, $N? Ist Arzeth tot?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10369 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10369, "deDE", "Es ist wahr, $N. Ich war einst Naladu, der Bewahrer der Erde.$B$BIch war es, der die anderen Mitglieder des Lumpenpacks für leere Versprechungen von Macht verkauft hat. Ihr könnt mich nun verachten, wenn Ihr wollt. Wichtig ist, dass mein Stamm nun wieder frei ist und die Geister zu uns zurückgekehrt sind.$B$BIch werde mich dem Rest des Stammes nicht anschließen, aber nun kann ich in Frieden sterben. Mögen die Geister der Erde unter meinen Brüdern einen neuen Diener finden.", 26972);

-- 10382 - Geht zur Front
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10382 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10382, "deDE", "Das trifft sich gut, $C. Ich bin froh, dass dieser brummige alte Zwerg es endlich auf die Reihe bekommen hat, uns ein wenig Hilfe zu schicken!", 26972);

-- 10388 - Rückkehr nach Thrallmar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10388 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10388, "deDE", "Ah, $N, Ihr kommt genau zur rechten Zeit. Unsere Späher haben herausgefunden, dass es sich bei den Ansammlungen der Legion auf dem Grat hinter uns tatsächlich um 'Konstruktionslager' handelt. Dort stellen die Dämonen ihre infernalen Teufelshäscher her. Wenn wir schnell gegen sie vorgehen, können wir vielleicht ihre Produktion aufhalten!", 26972);

-- 10389 - Das Leid und die Dunkelheit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10389 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10389, "deDE", "Bravo, $N. Ich wusste, dass Ihr Erfolg haben werdet! Das Ende der Legion rückt immer näher!", 26972);

-- 10390 - Konstruktionslager: Mageddon
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10390 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10390, "deDE", "Beeilt Euch, $C. Wir müssen das Konstruktionslager: Mageddon vernichten, bevor die Dämonen mit dem Bau fertig sind!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10390 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10390, "deDE", "Gut gemacht, $C. Ein Konstruktionslager weniger, um das wir uns sorgen müssen. Die Legion wird eine Weile brauchen, um die Einrichtung wieder zum Laufen zu bringen. Ihr habt uns das beschafft, was uns im Augenblick am meisten fehlt: Zeit.", 26972);

-- 10391 - Kanonen des Zorns
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10391 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10391, "deDE", "Ich wusste, dass Ihr Biss habt, $N, aber dieses Mal habt Ihr Euch selbst übertroffen! Wir haben die Explosionen dieser verfluchten Kanonen bis hierher gehört! Das müsste der Legion beweisen, dass sie die Söhne Durotars nicht unterschätzen sollten!", 26972);

-- 10392 - Die Schwelle zum Abgrund
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10392 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10392, "deDE", "Beeilt Euch, $N. Mit jeder Sekunde, in der das Warpportal offen steht, betritt ein weiterer Dämon diese Welt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10392 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10392, "deDE", "Gelobt seien die Ahnen, Ihr habt es geschafft, $N! Die Legion hat eine schreckliche Niederlage einstecken müssen. Thrallmar ist wieder sicher. Ach, wenn ich doch nur hundert Krieger mit Eurem Herz und Eurem Verstand hätte, dann wäre dieses zerschlagene Land schon längst gezähmt. Ich salutiere vor Euch.", 26972);

-- 10393 - Boshafte Pläne
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10393 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10393, "deDE", "Ich habe nicht viel Zeit, $C. Womit wollt Ihr mich belästigen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10393 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10393, "deDE", "Es war ganz richtig von Euch, mir dies zu bringen. Es könnte sich um einen Befehl zur Herstellung von zusätzlichen Teufelshäschern handeln - oder um neue Angriffspläne! Es wird etwas dauern, bis ich es entziffert habe. Lasst mich alleine. Ich lasse Euch rufen, wenn ich Genaueres weiß.$B$B<Magister Blutfalke nickt Euch zu, als Ihr Euch abwendet.>$B$BIhr seid sehr gescheit, $N. Ich werde Eure Fortschritte mit Interesse verfolgen.", 26972);

-- 10394 - Unterbrechung beim Konstruktionslager: Mageddon
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10394 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10394, "deDE", "Nun, ich muss zugeben, ich bin beeindruckt, $N. Ich hätte nicht gedacht, dass Ihr den Schneid für diese Mission habt. Wirklich gut gemacht.", 26972);

-- 10395 - Der dunkle Schriftwechsel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10395 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10395, "deDE", "Was ist los, $C? Ich spüre, dass Ihr etwas gefunden habt, das von Verdammnis kündet.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10395 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10395, "deDE", "Welch glücklicher Zufall, dass Ihr diesen Schriftwechsel abgefangen habt, $N. Ich werde zwar etwas Zeit brauchen, bis ich ihn entziffert habe, aber ich kann den Hass und die Eile, die in dieser Schriftrolle stecken, deutlich spüren. Ich habe das Gefühl, dass die wahren Pläne der Legion in dieser Welt sich bald offenbaren werden...$B$BGebt mir einen Moment Zeit, um die Schrift zu entziffern.", 26972);

-- 10396 - Der Feind meines Feindes...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10396 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10396, "deDE", "Eines muss ich Euch lassen, $N, Ihr seid ein geborener Kämpfer! Diese Tölpel der Horde werden vielleicht nie erfahren, wie knapp sie ihrem Ende entronnen sind. Es erfordert sehr viel Rückgrat, um dem Unheil im Namen seiner eigenen Feinde entgegenzutreten. Genau diese Ehre und dieses Pflichtgefühl machen die Allianz aus!", 26972);

-- 10397 - Invasionspunkt: Vernichter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10397 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10397, "deDE", "Habt Ihr das Warpportal schon geschlossen, $N? Während Ihr hier herumtrödelt kommen immer mehr Dämonen in die Scherbenwelt!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10397 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10397, "deDE", "Gute Arbeit! Das sollte die Zahl der Dämonen, die uns auf die Pelle rücken, dramatisch verringern. Ich kann Euch nicht genug für Eure Hilfe danken, $N.", 26972);

-- 10399 - Das Herz der Dunkelheit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10399 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10399, "deDE", "Ich habe diesen großartigen Sieg vorausgesehen, $N. Die gesegneten Naaru schenken Euch an diesem Tag ihr Lächeln.", 26972);

-- 10400 - Oberanführer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10400 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10400, "deDE", "Dem Licht sei Dank, ich wusste, dass Ihr es schafft! Arazzius und seine Diener sind Geschichte! Bald wird die Legion nach Hause flüchten und diese geschundene Welt wird wieder sicher sein. Und dann, wenn endlich Gerechtigkeit herrscht, können auch wir nach Hause gehen. $B$BVielen Dank, $N. Die Allianz und die Söhne Lothars feiern Euch heute!", 26972);

-- 10403 - Naladu
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10403 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10403, "deDE", "Ihr seid gekommen, um meinem Stamm zu helfen, $R? Wie ungewöhnlich. Es gibt nicht viele, die sich um das Schicksal der Zerschlagenen in diesem Land scheren.", 26972);

-- 10442 - Dem Posten des Cenarius helfen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10442 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10442, "deDE", "Oh, gut, Ihr müsst die Hilfe sein, die ich vor Wochen von der Falkenwacht angefordert habe.$B$BNun, jetzt seid Ihr hier und es gibt viel zu tun. Ich habe genau das Richtige für Euch für den Anfang.", 26972);

-- 10443 - Dem Posten des Cenarius helfen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10443 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10443, "deDE", "Oh, gut, Ihr müsst die Hilfe sein, die ich vor Wochen vom Tempel von Telhamat angefordert habe.$B$BIch bin froh, dass Ihr hier seid; es gibt viel zu tun. Ich habe genau das Richtige für Euch für den Anfang.", 26972);

-- 10449 - Apothekerin Zelana
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10449 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10449, "deDE", "Es ist mir eine Ehre, der Horde dienen zu können. Wie kann ich Euch helfen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10449 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10449, "deDE", "Ah ja. Das Blut des Knochenmalmerklans. Ich interessiere mich sehr für diese Orcs... sie sind zwar immer noch die verkommenen Feinde unserer Vergangenheit, aber ihre Stärke und Macht ist größer, als ich gedacht habe...$B$BNun, wollen wir beginnen, oder?", 26972);

-- 10450 - Blut der Knochenmalmer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10450 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10450, "deDE", "Habt Ihr Euch den Knochenmalmern gestellt, $N? Ich hoffe, dass Ihr ihr Blut in rauen Mengen vergossen habt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10450 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10450, "deDE", "Hah! Ihr habt also die Knochenmalmer, unsere verkommenen Vettern getroffen. Gut gemacht, $N. Ich bedauere nur, dass nicht mehr von ihnen ihr Leben lassen und ihr Blut vergießen konnten, um meinen Zorn zu besänftigen.", 26972);

-- 10482 - Plünderer der Höllenorcs
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10482 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10482, "deDE", "Sehr gut. Ich bin mir sicher, dass ihr Verlust in der Höllenfeuerzitadelle bemerkt wird. Auch wenn diese dunkle Bastion uns überschattet und unüberwindlich scheint, können wir mit stolzen Taten wie Eurer sicher einen Weg finden, sie zu besiegen!", 26972);

-- 10483 - Schwarze Magie
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10483 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10483, "deDE", "Bringt Ihr Neues von der Ehrenfeste, $N? Das ist gut. Unseren Vorgehen gegen die Dämonen und Höllenorcs gehen so langsam die fähigen Kämpfer aus!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10483 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10483, "deDE", "Ah, Ihr habt ein Insigne von den Orcs des Blutenden Auges ergattert? Gut! Es ist eine Schande, dass sie unsere Symbole gegen uns verwenden und sich über unsere Kameraden, die im Kampf gegen diese rothäutigen Bestien gefallen sind, lustig machen!", 26972);

-- 10484 - Verfluchte Talismane
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10484 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10484, "deDE", "Habt Ihr die Talismane, $N? Es schmerzt mich zu wissen, dass diese verdammten Orcs die Insignien unserer Soldaten besitzen...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10484 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10484, "deDE", "Danke, $N. Mein Herz ist voller Trauer, wenn ich diese Talismane betrachte. Sie unterstreichen die zahlreichen Verluste, die wir in der Ehrenfeste gegen die Höllenorcs hinnehmen mussten. Aber es freut mich zu sehen, dass Ihr Erfolg gegen sie hattet. Wenn wir genügend von ihnen töten können, treten wir vielleicht als Sieger aus diesem Krieg hervor.", 26972);

-- 10485 - Kriegsherr des Blutenden Auges
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10485 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10485, "deDE", "Habt Ihr Morkhs zerschmetterte Rüstung? Habt Ihr Euch wieder todesmutig nach Zeth'Gor begeben?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10485 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10485, "deDE", "Ihr habt es geschafft! Morkh ist tot! Jetzt haben wir eine Chance im Kampf gegen die Bestien der Höllenorcs!$B$BVielen Dank, $N. Eure Hilfe in diesem Krieg ist unermesslich.", 26972);

-- 10538 - Kochendes Blut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10538 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10538, "deDE", "Habt Ihr das gekochte Blut, $N? Ich würde es furchtbar gerne ohne Unterbrechungen untersuchen können...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10538 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10538, "deDE", "Sehr gut. Jetzt kann ich meine Tests viel leichter durchführen...$B$BVielen Dank, $N. Eure Begabungen sind beachtlich.", 26972);

-- 10629 - Drecksarbeit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10629 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10629, "deDE", "Konntet Ihr meine Schlüssel finden? Ich bin mir sicher, dass einer der Hunde ihn gefressen hat. Wahrscheinlich ist es der, den ich Euch mitgegeben habe. Wahrscheinlich.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10629 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10629, "deDE", "Ihr riecht ja fürchterlich! Aber Ihr habt meine Schlüssel gefunden. Vielen herzlichen Dank! Jetzt kann ich meinen Schredder in Betrieb nehmen und ein wenig Gold verdienen. Bald werde ich das Geld zusammen haben, um die Scherbenwelt zu verlassen. Ich weiß nicht, warum Ihr hier bleiben wollt. Ich hasse diesen Ort. Wärt Ihr nicht viel lieber wieder in Beutebucht?$B$BVielleicht um ein wenig zu Angeln?", 26972);

-- 10630 - Unter Thrallmar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10630 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10630, "deDE", "Diese Gan'arg werden sich jetzt sicher verziehen. Und in einer Woche bin ich wieder in Beutebucht. Ich kann es kaum abwarten, endlich wieder angeln gehen zu können. Es war ein Fehler in die Scherbenwelt zu kommen. Wenn Ihr meinen Rat hören wollt, macht Euch schleunigst auf den Weg zurück nach wo Ihr herkommt. Verbringt ein wenig Zeit im Schlingendorntal! Oder wenn Ihr mehr auf Abenteuer aus seid im Krater von Un'Goro. Hauptsache nicht hier.", 26972);

-- 10754 - Zugang zur Zitadelle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10754 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10754, "deDE", "Habt Ihr mir etwas zu zeigen, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10754 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10754, "deDE", "Kann das wahr sein? Lasst mich die Form einmal genauer betrachten.", 26972);

-- 10762 - Großmeister Dumphry
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10762 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10762, "deDE", "Was ist das?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10762 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10762, "deDE", "Ein Schlüssel? Danath sollte uns eigentlich an Belagerungsmaschinen arbeiten lassen!", 26972);

-- 10763 - Dumphrys Bitte
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10763 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10763, "deDE", "Habt Ihr die Materialien, um die ich Euch gebeten habe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10763 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10763, "deDE", "Dann wollen wir es mal versuchen. Mal sehen, was hinter der Schmiedekunst der Orcs steckt.", 26972);

-- 10764 - Heißer als die Hölle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10764 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10764, "deDE", "Habt Ihr getan worum ich Euch gebeten habe, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10764 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10764, "deDE", "Ihr habt es geschafft, $GJunge:Mädel;! Jetzt müsst Ihr sie nur noch zur Höllenfeuerzitadelle bringen und ein paar Orcs erlegen!", 26972);

-- 10792 - Zeth'Gor muss brennen!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10792 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10792, "deDE", "Hah! Ich konnte die Flammen über Zeth'Gor bis hierher sehen! Mögen unsere Feinde des Blutenden Auges zu Asche zerfallen und keinem wahren Orc mehr unter die Augen kommen!$B$BVielen Dank, $N. Ihr habt geholfen, eine Beleidigung für den Geist eines jeden Orcs hinfort zu brennen.", 26972);

-- 10809 - GESUCHT: Worgmeister Kruush
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10809 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10809, "deDE", "Berichtet, $N. Ist das Blut des Blutenden Auges da auf Eurem Ärmel? Ich hoffe doch!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10809 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10809, "deDE", "Ihr habt also den Tunichtgut Kruush erschlagen! Gut gemacht, $N! Sehr gut! Sein Tod wird seinen verfluchten Worgreitern die Giftzähne ziehen! Ich hoffe, Ihr habt auch ein paar von ihnen erledigt, als Ihr Euren kleinen Ausflug nach Zeth'Gor gemacht habt!$B$BHier ist Eure Belohnung. Ihr habt sie Euch verdient!", 26972);

-- 10813 - Die Augen von Grillok
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10813 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10813, "deDE", "Die Orcs des Blutenden Auges waren einst starke Verbündete... und nun sind sie noch stärkere Feinde.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10813 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10813, "deDE", "Ich stehe tief in Eurer Schuld, $N. Ihr habt ein weiteres Mal über Zeth'Gor triumphiert und seine Dunkelheit nahe an Euer Herz gelassen. Ich werde das Auge untersuchen und damit hoffentlich die Geheimnisse seines Meisters Grillok lüften.$B$BHoffentlich kann es seine Magie nicht länger einsetzen!", 26972);

-- 10834 - Grillok 'Finsterauge'
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10834 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10834, "deDE", "Die Bösartigkeit der Orcs des Blutenden Auges kennt keine Grenzen und wird nur noch von der ihrer Vettern der Zerschmetterten Hand übertroffen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10834 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10834, "deDE", "Ah ja. Ich frage mich, ob Grillok in seinen dunklen, dunklen Träumen immer noch mit seinem verlorenen Auge verbunden ist, wie jemand, der eine Hand oder ein Bein in der Schlacht verloren hat...$B$BAuch ich werde davon träumen. Und wenn das Schicksal auf unserer Seite steht, werden wir dadurch erfahren, was Grillok und die Orcs des Blutenden Auges dazu gebracht hat, sich den Dämonen zu unterwerfen.", 26972);

-- 10835 - Apotheker Antonivich
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10835 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10835, "deDE", "Guten Tag, $N. Wie gefällt Euch Euer Aufenthalt auf der Höllenfeuerhalbinsel? Ich bin mir sicher, dass er sehr ergiebig ist...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10835 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10835, "deDE", "Ah, ein Bericht von Albreck? Sehr gut. Die königliche Apothekervereinigung versucht verzweifelt herauszufinden, wie die Orcs zu Höllenorcs geworden sind. Ihr Verrat ist unverzeihlich... und wir müssen sicherstellen, dass unsere Orcfreunde für alle Zeit vor dieser Verderbnis sicher sind.", 26972);

-- 10838 - Der dämonische Seher
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10838 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10838, "deDE", "Habt Ihr die Messung? War Euer Auftrag mit dem dämonischen Seher erfolgreich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10838 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10838, "deDE", "Ihr habt die Messung? Ausgezeichnet. Ich bin mir sicher, dass diese Daten sich für unsere Forschungen als unersetzlich erweisen werden. Ich werde sie gleich an Apothekerin Zelana und Apotheker Albreck weiterleiten.$B$BIhr solltet stolz auf Euch sein, $N. Eure Stärke und Euer Mut steht außer Frage... genauso wie Eure Leistungen gegenüber der Horde.", 26972);

-- 10864 - Eine Last auf der Seele
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10864 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10864, "deDE", "Gut gemacht, $N. Eure Seele ist mit vielen Toden belastet... und der dämonische Seher wird nun seine Pflicht für Euch erfüllen.$B$BWollen wir hoffen, dass Ihr für das Folgende gewappnet sein.", 26972);

-- 10875 - Bericht an Nazgrel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10875 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10875, "deDE", "Es ist schön, von Euren Schachzügen gegen die Höllenorcs zu erfahren, $N. Die Apotheker haben viel Zeit und viel Mühe aufgewendet, um hinter den Grund der Verderbnis zu kommen, und auch wenn diese Informationen sicher unersetzlich sind... schreit mein Orcblut danach, diesen Verrätern einen anständigen Schlag zu verpassen!$B$BHört genau zu, wenn ich Euch Eure Aufgabe erkläre...", 26972);

-- 10876 - Am Fuße der Zitadelle
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10876 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10876, "deDE", "Habt Ihr Euch der Hand von Kargath gestellt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10876 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10876, "deDE", "Ihr habt eine große Tat geleistet, $N. Die Höllenorcs sind eine Schande für alle wahren Orcs. Wenn wir eine Angst haben, so ist es die, erneut einer dämonischen Verderbnis zu verfallen. Unser Krieg gegen die Höllenorcs ist also mehr als nur eine Schlacht gegen schlimme Feinde, es ist eine Schlacht in uns selbst.$B$BUnd mit einer Stärke, wie Ihr sie heute bewiesen habt, werden wir diese Schlacht gewinnen.", 26972);

-- 10895 - Zeth'Gor muss brennen!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10895 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10895, "deDE", "Ich konnte von hier aus den Rauch und die Flammen sehen! Gute Arbeit, $N! Ihr verdient mehr als nur ein paar Lobesworte von unseren Greifenreitern. Was Ihr da getan habt, erfordert eine gehörige Portion Mut.", 26972);

-- 10903 - Rückkehr zur Ehrenfeste
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10903 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10903, "deDE", "Ja, es ist wahr. Oberst Jules' Zustand hat sich in den letzten Tagen stark verschlechtert. Anachoret Barada betet schon die ganze Zeit für ihn... Wir hoffen, dass er geheilt werden kann.", 26972);

-- 10909 - Höllengeister
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10909 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10909, "deDE", "Die Höllengeister der Orcs der Zerschmetterten Hand sind für Jules' arme Seele eine Schmach. Sagt mir, $N... habt Ihr ihn gerächt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10909 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10909, "deDE", "Die Orcs der Zerschmetterten Hand sind verderbt und nicht mehr zu retten. Und dennoch erfüllt es mein Herz mit Traurigkeit, dass die Rettung von Oberst Jules ein solches Blutvergießen erfordert.", 26972);

-- 10916 - Nach Gebetsperlen graben
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10916 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10916, "deDE", "Habt ihr die Gebetsperlen schon gefunden, $N? Ihre Macht ist für viele heilige Rituale unerlässlich... darunter auch für einen Exorzismus...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10916 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10916, "deDE", "Ihr habt die Gebetsperlen gefunden! Gut gemacht, $N. Ihr seid in der Tat ein Wunder. Im einen Moment erschlagt Ihr die Schrecken der Höllenfeuerhalbinsel, im anderen findet Ihr verlorene Schätze. Euer Volk ist wirklich sehr vielseitig!$B$BEs ist gut, dass Ihr diese Perlen gefunden habt... Sie sind für das folgende Exorzismusritual von äußerster Wichtigkeit.", 26972);

-- 10919 - Fei-Feis Belohnung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10919 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10919, "deDE", "<Fei-Fei bellt glücklich und schnappt sich das Hundeleckerli. Er schaut nach links und rechts, um zu entscheiden, wo er seinen neuen Schatz vergraben soll...>", 26972);

-- 10935 - Der Exorzismus des Oberst Jules
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10935 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10935, "deDE", "Geht zu Anachoret Barada, $N. Er muss mit seinem Ritual Erfolg haben, wenn der Oberst gerettet werden soll.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10935 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10935, "deDE", "Ihr habt es geschafft, $N. Ihr habt Oberst Jules' Seele gerettet und die Dunkelheit in ihm vertrieben. Das ist eine großartige und selbstlose Tat! Die Tat eines Helden!", 26972);

-- 10936 - Trollbann sucht Euch
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10936 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10936, "deDE", "Das wird auch langsam Zeit! Ich habe davon erfahren, was Ihr und dieser Draeneipriester angestellt habt! Ihr habt meinen Boten völlig schockiert!$B$BJetzt, da Ihr damit fertig seid, habe ich einen kleinen Auftrag in der Höllenfeuerzitadelle für Euch.", 26972);

-- 10937 - Die Züchtigung des Drillmeisters
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10937 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10937, "deDE", "Ich wollte es nicht glauben, bis ich es nicht von Euch persönlich gehört habe. Unsere Späher berichten uns jetzt schon, dass die Zerschmetterte Hand ohne ihren geschätzten Drillmeister, der ihnen sagt, was zu tun ist, völlig überfordert ist.$B$BIhr habt einen langen Weg zurückgelegt, $N. Ich vertraue darauf, dass Ihr diese Rüstung zusammen mit meinem Dank annehmt. Tragt sie mit Stolz, denn Ihr habt sie verdient!", 26972);

-- 11515 - Blut für Blut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11515 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11515, "deDE", "Diese Monster sind eine Schande für unser Volk. Wir müssen sie vernichten, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11515 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11515, "deDE", "Narren. Sie haben gelernt, wie man Teufelsenergie entzieht, aber nicht, wie man sie behält.$B$BWir haben Glück, $N. Ein erfahrener Streiter des Teufelsbluts hätte gewiss einen beeindruckenden Gegner abgegeben.", 26972);

-- 11516 - Vernichtet den Durchgang
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11516 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11516, "deDE", "Ist es vollbracht, $N? Kael'thas darf keine weitere Verstärkung durch die Legion erhalten.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11516 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11516, "deDE", "Ausgezeichnete Arbeit, $N. Die Dämonen werden den Durchgang womöglich rechtzeitig reparieren. Na dann werden wir ihn wohl noch einmal in die Luft jagen müssen.", 26972);

-- 13408 - Höllenfeuerbefestigungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 13408 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (13408, "deDE", "Gut gemacht, $N. Eure Taten auf dem Schlachtfeld sind für unseren Kampf auf der Höllenfeuerhalbinsel sehr hilfreich.", 26972);

-- 13409 - Höllenfeuerbefestigungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 13409 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (13409, "deDE", "Gute Arbeit, $N. Ich konnte fast die Kampfschreie an den Befestigungsanlagen hören. Ich wünschte, ich wäre dabei gewesen!", 26972);

-- 13410 - Höllenfeuerbefestigungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 13410 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (13410, "deDE", "Gut gemacht, $N. Eure Taten auf dem Schlachtfeld sind für unseren Kampf auf der Höllenfeuerhalbinsel sehr hilfreich.", 26972);

-- 13411 - Höllenfeuerbefestigungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 13411 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (13411, "deDE", "Gute Arbeit, $N. Ich konnte fast die Kampfschreie an den Befestigungsanlagen hören. Ich wünschte, ich wäre dabei gewesen!", 26972);
