-- Shadowmoon Valley -- Schattenmondtal
-- RequestItems, OfferReward -- master, 3.3.5

-- 10451 - Flucht aus der Zisterne der Echsennarbe
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10451 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10451, "deDE", "Gelobt sei die Erdenmutter! Ich bin mir sicher, dass Wilda nach Hause finden wird. Bitte nehmt dies als Zeichen unserer Wertschätzung.", 26972);

-- 10458 - Wütende Geister des Feuers und der Erde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10458 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10458, "deDE", "Ich fürchte, dass es keine Hoffnung für dieses Land gibt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10458 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10458, "deDE", "Wenn alle Elementarseelen dieser Gegend in diesem Totem eingefangen sind, werden wir mit ihnen reden und herausfinden, ob wir etwas für das Schattenmondtal tun können.", 26972);

-- 10480 - Wütende Geister des Wassers
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10480 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10480, "deDE", "Wo auch immer Ihr die Naga findet, könnt Ihr sicher auch die gequälten Wassergeister finden.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10480 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10480, "deDE", "Und zurück bleibt nichts als Luft, $N.", 26972);

-- 10481 - Wütende Geister der Luft
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10481 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10481, "deDE", "Bald werden wir mit den Geistern sprechen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10481 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10481, "deDE", "Erlaubt mir, dass ich Euch für diese wagemutige Tat belohne, Held.$B$BJetzt müssen wir uns an die Arbeit machen! Bitte tretet zurück, damit ich das Totem aufstellen und die Seelen freilassen kann.", 26972);

-- 10513 - Oronok Herzeleid
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10513 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10513, "deDE", "Litanei der Verdammnis? Nie davon gehört. Hört auf meinen Rat und lasst die Toten ruhen.$B$BAber wenn Ihr schon hier seid, könnt Ihr mir ja gleich bei ein paar Dingen helfen. Was meint Ihr?", 26972);

-- 10514 - Ich war schon vieles...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10514 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10514, "deDE", "Holt mir diese Knollen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10514 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10514, "deDE", "Ihr sagt, da waren viel mehr Felshetzer, als Ihr erwartet habt? Sieht aus, als wäre es an der Zeit, die Situation etwas zu entschärfen.", 26972);

-- 10515 - Eine Lektion gelernt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10515 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10515, "deDE", "Das wird den verdammten, bösartigen Tieren zeigen, dass man meine Eber nicht töten sollte! Gut gemacht, $N!", 26972);

-- 10519 - Die Litanei der Verdammnis - Wahrheit und Geschichte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10519 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10519, "deDE", "Versteht Ihr, was getan werden muss? Findet die Söhne Oronoks. Findet meine Jungs...", 26972);

-- 10521 - Grom'tor, Sohn des Oronok
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10521 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10521, "deDE", "<Grom'tor grunzt.>$B$BGut, dass Ihr hier seid. Diese Made hat gerade geplaudert. Jetzt haben wir sie!", 26972);

-- 10522 - Die Litanei der Verdammnis - Grom'tors Angriff
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10522 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10522, "deDE", "Hattet Ihr Glück?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10522 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10522, "deDE", "Das müsst Ihr sofort zurück zu Vater bringen.", 26972);

-- 10523 - Die Litanei der Verdammnis - Erster Teil
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10523 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10523, "deDE", "Hattet Ihr Erfolg?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10523 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10523, "deDE", "Wenn die Litanei der Verdammnis wieder zusammengefügt ist, werden wir diesen Fluch beenden!", 26972);

-- 10527 - Ar'tor, Sohn des Oronok
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10527 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10527, "deDE", "Ar'tors Körper hängt leblos in der Luft. Ihr wisst nicht, wie lange er schon tot ist, aber Euch überkommt große Traurigkeit für Oronok.$B$BVielleicht solltet Ihr versuchen, seine Leiche zu seinem Vater zu bringen.", 26972);

-- 10528 - Dämonische Kristallgefängnisse
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10528 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10528, "deDE", "Ar'tor schwebt leblos vor Euch.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10528 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10528, "deDE", "Ihr steckt den Schlüssel in die Öffnungen im unteren Teil jedes dämonischen Kristalls.", 26972);

-- 10537 - Lohn'goron, Bogen des Herzeleid
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10537 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10537, "deDE", "Fürchtet Euch nicht, Held. Wenn die Zeit gekommen ist, werde ich Euch helfen...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10537 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10537, "deDE", "Der Name bedeutet in meiner Sprache 'Heldenruh'. Und auch jetzt, in einer Gegend, in der all unsere Helden gestorben sind, bewahrheitet er sich.$B$BUnd doch scheint einer sich immer wieder zu erheben.", 26972);

-- 10540 - Die Litanei der Verdammnis - Ar'tors Angriff
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10540 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10540, "deDE", "Die Litanei muss gefunden werden!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10540 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10540, "deDE", "<Ar'tors Silhouette wird unscharf und wieder schärfer.>$B$BEs scheint, als wäre meine Zeit bald zu Ende, Held.", 26972);

-- 10541 - Die Litanei der Verdammnis - Zweiter Teil
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10541 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10541, "deDE", "<Eine einzelne Träne läuft über Oronoks Wange.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10541 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10541, "deDE", "<Oronok wischt sich die Träne aus dem Auge und lächelt Euch an.>$B$BDanke. Ich verspreche Euch, Held, dass ein ehrenhaftes Lied über Euch erklingen wird.", 26972);

-- 10546 - Borak, Sohn des Oronok
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10546 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10546, "deDE", "<Borak ist für einen Moment still.>$B$BIch beobachte diese Blutelfen schon seit Wochen und versuche herauszufinden, wo sie den dritten Teil der Litanei der Verdammnis aufbewahren.$B$BSo weit habe ich jedoch keine brauchbaren Hinweise sammeln können. Ich weiß nur, dass Illidan einmal am Tag einen Entsandten vom Schwarzen Tempel herschickt.$B$BDieser Entsandte ist unantastbar. Ich habe ihn eine Woche lang überwacht und nach einem Weg gesucht, ihn von seiner Leibwache zu trennen. Die Leibwache verlässt jedoch unglücklicherweise nie seine Seite.", 26972);

-- 10547 - Von Distelköpfen und Eiern...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10547 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10547, "deDE", "<Tobias hebt eine Augenbraue.>$B$BBlutdistel? Nie davon gehört... Seid Ihr ein Friedensbewahrer? Ihr wisst, dass Ihr mir sagen müsst, wenn Ihr einer seid... Ich habe schließlich Rechte!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10547 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10547, "deDE", "Ihr habt ein verfaultes Arakkoaei? Nun, warum habt Ihr das denn nicht gleich gesagt? Ich denke, wir sind im Geschäft.$B$B<Tobias lächelt und entblößt dabei eine Reihe verfaulter und vergilbter Zähne.>", 26972);

-- 10550 - Ein Bündel von Blutdisteln
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10550 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10550, "deDE", "Habt Ihr die Blutdisteln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10550 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10550, "deDE", "Jetzt müssen wir die Falle stellen.", 26972);

-- 10562 - Belagert!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10562 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10562, "deDE", "Danke, dass Ihr meine Männer unterstützt habt, $N. Mit Eurer Hilfe und der Hilfe anderer, können wir vielleicht noch länger durchhalten. Unglücklicherweise ist Durchhalten leider nicht genug. Wir müssen zum Angriff übergehen.", 26972);

-- 10563 - Zur Feste der Legion
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10563 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10563, "deDE", "Was habt Ihr herausgefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10563 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10563, "deDE", "<Schwadronskommandant Nuainn hört sich Euren Bericht an und wird mit jedem Satz nervöser.>$B$BIhr sagt also, dass sie genügend Höllenbestien haben, um die Angriffe noch zu verstärken? Wenn wir sie nicht aufhalten, bevor sie die nächste Phase ihres Plans umsetzen können, ist die Wildhammerfeste verloren!", 26972);

-- 10564 - Jagt die Höllenbestien in die Luft!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10564 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10564, "deDE", "Habt Ihr einen Weg gefunden, um den Vorrat an Höllenbestien der Legion zu zerstören?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10564 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10564, "deDE", "Gut gemacht, $N! Ich wünschte, ich könnte behaupten, dass die Legion nach einem Rückschlag wie diesem aufgeben wird, aber das würdet Ihr mir ohnehin nicht glauben. Die Todesschmiede, von der Ihr erfahren habt, wird unser nächstes Ziel sein.", 26972);

-- 10568 - Schrifttafeln von Baa'ri
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10568 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10568, "deDE", "Habt Ihr die Schrifttafeln schon gefunden, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10568 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10568, "deDE", "Die Schrifttafeln von Baa'ri! Ja, die werden uns sehr wichtige Informationen liefern.", 26972);

-- 10569 - Das Wrack der Sketh'lon
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10569 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10569, "deDE", "Was habt Ihr entdeckt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10569 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10569, "deDE", "<Kieran wirft einen kurzen Blick auf die Tagebuchseiten.>$B$BVieles davon ist unleserlich, aber ich kann hier und da ein paar Worte verstehen. Es geht um eine fehlgeschlagene Vorbereitung eines Zaubers, Opfer und eine sich verschlechternde Situation. Hier steht auch irgendetwas Merkwürdiges über einen 'Deserteur'.", 26972);

-- 10570 - Einen Distelsüchtigen fangen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10570 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10570, "deDE", "Beeilt Euch, Junge!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10570 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10570, "deDE", "<Borak nimmt den Schriftwechsel und beginnt zu lesen.>$B$BGerissene Hunde! Dies ist eine Anordnung von Illidan, die besagt, wo die Litanei der Verdammnis als Nächstes versteckt werden soll. Offensichtlich ändern sie den Aufenthaltsort ständig. Aber wir wissen leider nicht, wo sie sich im Augenblick befindet... Wenn wir diesen Brief doch nur abliefern könnten, jetzt, da wir wissen, wo sie die Litanei verstecken werden.$B$BWie schade, dass das Siegel nun zerbrochen und der Brief damit nutzlos ist.$B$BHmm... Es sei denn...", 26972);

-- 10571 - Oronu der Älteste
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10571 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10571, "deDE", "Gibt es schon Neuigkeiten, $N? Wir haben nicht viel Zeit.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10571 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10571, "deDE", "Akamas Handschrift. Es ist wirklich sehr traurig, was aus jemandem werden konnte, der so weise und beliebt war wie er.", 26972);

-- 10572 - Die Bombe bauen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10572 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10572, "deDE", "<Ihr reicht dem Schwadronskommandanten die Materialien.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10572 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10572, "deDE", "<Der Schwadronskommandant setzt den Kraftkern in die Rüstplatten und versiegelt nickend das Gerät.>$B$BDas sollte klappen. Und es sollte auch eine ziemlich große Explosion von sich geben.", 26972);

-- 10573 - Die Todesschmiede
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10573 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10573, "deDE", "<Der Zwerg nickt.>$B$BVerstärkung ist gut. Wir haben bisher grundlegende Informationen über die Pläne des Schattenrats hier gesammelt, aber ich wäre sehr froh, wenn wir endlich gegen sie vorgehen könnten.", 26972);

-- 10574 - Die Verderber der Aschenzungen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10574 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10574, "deDE", "Habt Ihr die vier Fragmente des Medaillons, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10574 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10574, "deDE", "Ja! Die vier Fragmente des Medaillons. Und nun setzt sie zusammen...", 26972);

-- 10575 - Der Kerker des Wächters
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10575 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10575, "deDE", "Wir haben Euch erwartet, $N. Akama sagte, dass Ihr früher oder später kommen würdet.", 26972);

-- 10576 - Unterwürfigkeit in Schattenmond
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10576 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10576, "deDE", "Das ist viel zu kompliziert, $R. Ihr würdet es nicht verstehen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10576 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10576, "deDE", "Gut gemacht, $N. Ich hoffe, Ihr seid ein guter Schauspieler. Der nächste Schritt erfordert etwas Theatralik!", 26972);

-- 10577 - Was Illidan will, soll Illidan bekommen...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10577 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10577, "deDE", "Jetzt müsst Ihr nur noch die Litanei besorgen. Einfach, oder?", 26972);

-- 10578 - Die Litanei der Verdammnis - Boraks Angriff
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10578 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10578, "deDE", "Ihr müsst schnell handeln!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10578 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10578, "deDE", "Endlich! Das Fragment der Litanei gehört uns!$B$B<Borak verstaut das Fragment in einer Schließkassette.>", 26972);

-- 10579 - Die Litanei der Verdammnis - Dritter Teil
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10579 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10579, "deDE", "$N!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10579 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10579, "deDE", "Sobald alle drei Teile der Litanei zusammengefügt sind, wird es wieder bekannt.$B$BDieses Dokument zu besorgen war zweifellos eine große Herausforderung. Für einen solchen Heldenmut müsst Ihr belohnt werden.", 26972);

-- 10582 - Diener des Schattenrats
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10582 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10582, "deDE", "Ich wünschte, ich hätte mit Euch gehen können! Ich brenne schon die ganze Zeit darauf, meinen Hammer benutzen zu können, aber mein Auftrag ist es, zu beobachten, nicht zu töten.$B$BJetzt, da Ihr ein Loch in ihre Verteidigung geschlagen habt, lasst uns die Produktion in der Todesschmiede zum Stillstand bringen.", 26972);

-- 10583 - Flanis' Schicksal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10583 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10583, "deDE", "Habt Ihr ein Zeichen von Flanis in der Todesschmiede finden können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10583 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10583, "deDE", "<Ewan schüttelt den Kopf und nimmt Euch den Beutel ab.>$B$BIch glaube nicht, dass Flanis sich im Klaren darüber war, wie schwer die Todesschmiede bewacht ist. Jetzt, da wir wissen, was tatsächlich dort vor sich geht, mache ich ihnen keinen Vorwurf. Ich wünschte nur, dass Flanis es gewusst hätte, als er dort hinein gegangen ist.$B$BIch kann nur hoffen, dass irgendetwas in diesem Beutel uns dabei helfen kann, die Todesschmiede ein für alle Mal auszuschalten.", 26972);

-- 10585 - Die Beschwörungskammer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10585 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10585, "deDE", "Wir können nicht zulassen, dass sie weiter produzieren. Habt Ihr dem Beschwörungsritual ein Ende gesetzt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10585 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10585, "deDE", "Gut gemacht, $N. Die Beschwörung des Schattenrats zu unterbrechen bringt uns einen Schritt näher an die Abschaltung der Todesschmiede.", 26972);

-- 10586 - Nieder mit dem Kriegshetzer!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10586 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10586, "deDE", "Bringt Ihr Neuigkeiten aus der Todesschmiede?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10586 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10586, "deDE", "<Ihr erstattet dem Schwadronskommandanten Bericht und übergebt die gefundenen Befehle.>$B$BKriegshetzer Razuun zu besiegen sollte eigentlich das Ende unserer Probleme mit der Legion bedeuten, aber in diesen Befehlen steht deutlich mehr, als ich befürchtet hatte. Ich glaube, wir haben noch viel zu tun.", 26972);

-- 10587 - Ausbildungsgelände von Karabor
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10587 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10587, "deDE", "Habt Ihr die Aufgabe, die ich Euch gegeben habe, schon erledigt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10587 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10587, "deDE", "Wollen wir uns diese Waffen einmal genauer ansehen, $N. Hmmm... das ist ziemlich beunruhigend.", 26972);

-- 10588 - Die Litanei der Verdammnis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10588 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10588, "deDE", "Ist es vollbracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10588 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10588, "deDE", "<Erdheiler Torlok nimmt Euch die Litanei der Verdammnis ab.>$B$BIhr habt getan, worum Euch die Elemente gebeten haben. Dafür sind wir sehr dankbar. Ihr werdet belohnt werden, doch der Ärger lauert noch immer auf uns. Die Geister des Feuers sind in Aufruhr. Es wurde eine Forderung vorgebracht. Ein weiterer kennt die Litanei der Verdammnis.$B$BIch weiß, das klingt sehr kryptisch, aber das ist alles, was die Geister mir mitgeteilt haben. Das und dieses Symbol...$B$B<Erdheiler Torlok dreht sich um und zeigt gen Himmel.>$B$BWas könnte das wohl bedeuten?", 26972);

-- 10589 - Zugang erlangen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10589 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10589, "deDE", "Wir müssen einen Weg finden, um diese Höllenbestien zu vernichten, $N. Wir sind schon weit gekommen, aber ein Fehlschlag würde uns alles kosten.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10589 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10589, "deDE", "Lasst mich schauen, ob ich herausfinden kann, wie das funktioniert...", 26972);

-- 10595 - Belagert!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10595 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10595, "deDE", "Ich bin beeindruckt, dass Ihr dieses Gemetzel überlebt habt. Ihr seid vielleicht genau die Person, die wir für einen gefährlichen Auftrag brauchen.", 26972);

-- 10596 - Zur Feste der Legion
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10596 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10596, "deDE", "Was habt Ihr herausgefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10596 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10596, "deDE", "<Blutwache Gulmok hört sich Euren Bericht an und wird mit jedem Satz nervöser.>$B$BWas meint Ihr mit sie wollen ihre Angriffe noch verstärken? Das können wir nicht zulassen. Kehrt dorthin zurück und kümmert Euch darum, solange in Schattenmond noch ein Stein auf dem anderen steht.", 26972);

-- 10597 - Die Bombe bauen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10597 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10597, "deDE", "<Ihr reicht Gulmok die Materialien.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10597 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10597, "deDE", "<Gulmok platziert den Kraftkern in dem Gehäuse und versiegelt es.>$B$BDas sollte funktionieren. Ich möchte nicht in der Feste sein, wenn das Ding hochgeht.", 26972);

-- 10598 - Jagt die Höllenbestien in die Luft!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10598 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10598, "deDE", "Habt Ihr einen Weg gefunden, um den Vorrat an Höllenbestien der Legion zu zerstören?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10598 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10598, "deDE", "<Gulmok nickt grimmig.>$B$BWir haben keine Zeit zu feiern, $N. Noch sind wir nicht aus der Schusslinie. Ich habe neue Befehle für Euch.", 26972);

-- 10599 - Die Todesschmiede
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10599 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10599, "deDE", "<Der Orc nickt.>$B$BVerstärkung ist gut. Wir haben zwar schon grundlegende Informationen darüber gesammelt, was der Schattenrat dort drin vorhat, doch es ist Zeit zuzuschlagen.", 26972);

-- 10600 - Diener des Schattenrats
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10600 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10600, "deDE", "Ich wäre ja selbst dorthin gegangen und hätte ein paar Schädel zertrümmert, aber ich habe strengste Anweisungen, mich nicht auf einen direkten Kampf mit dem Feind einzulassen.$B$B<Der Späher grummelt und imitiert Blutwache Gulmoks Stimme.>$B$BLasst uns die Produktion in der Schmiede zum Stillstand bringen.", 26972);

-- 10601 - Kagroshs Schicksal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10601 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10601, "deDE", "Habt Ihr ein Zeichen von Kagrosh in der Todesschmiede finden können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10601 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10601, "deDE", "<Zagran schüttelt den Kopf und nimmt Euch den Beutel ab.>$B$BIch habe Euch doch gesagt, dass er ein Dummkopf ist. Ich hoffe, dass in diesem Beutel irgendetwas ist, die Zeit, die Ihr mit der Suche nach ihm verbracht habt, rechtfertigt.", 26972);

-- 10602 - Die Beschwörungskammer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10602 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10602, "deDE", "Wir können nicht zulassen, dass sie weiter produzieren. Habt Ihr dem Beschwörungsritual ein Ende gesetzt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10602 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10602, "deDE", "Gut. Wir machen Fortschritte. Das bringt uns einen Schritt näher an die Abschaltung diese Monstrosität. Bald können wir sicher nach Schattenmond zurückreisen.", 26972);

-- 10603 - Nieder mit dem Kriegshetzer!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10603 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10603, "deDE", "Bringt Ihr Neuigkeiten aus der Todesschmiede?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10603 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10603, "deDE", "<Ihr erstattet der Blutwache Bericht und übergebt die gefundenen Befehle.>$B$BGute Arbeit, $N, aber denkt nicht, dass Ihr dafür einen Orden verliehen bekommt. Die Nachtelfen mögen vielleicht ihre hübschen kleinen Uniformen dekorieren. Echte Krieger teilen jedoch ihre Geschichten von der Schlacht bei einem kühlen Krug Bier.", 26972);

-- 10604 - Zugang erlangen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10604 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10604, "deDE", "Die Anwesenheit der Legion in unserer Mitte ist nicht akzeptabel! Wir müssen einen Weg finden, damit fertigzuwerden, bevor sie ihre Angriffe erneuern können.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10604 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10604, "deDE", "Endlich haben wir ein Mittel, mit dem wir die Legion aus Schattenmond vertreiben können!", 26972);

-- 10606 - Die Kunst der Teufelshäscherwartung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10606 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10606, "deDE", "Habt Ihr das Handbuch?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10606 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10606, "deDE", "Ah, genau was wir brauchen. Die Legion ist zwar nicht für ihre Meisterwerke der Weltliteratur bekannt, aber es sollte seinen Zweck erfüllen.", 26972);

-- 10611 - Die Kunst der Teufelshäscherwartung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10611 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10611, "deDE", "Habt Ihr das Handbuch?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10611 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10611, "deDE", "Das enthält alle nötigen Informationen. Nur noch ein paar Handgriffe, und Ihr habt in null Komma nichts die Kontrolle über einen Teufelshäscher.", 26972);

-- 10612 - Teufelshäscherdrift
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10612 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10612, "deDE", "Erstaunlich! Ihr habt geschafft, was keiner der Greifenreiter der Wildhammerfeste bewerkstelligen konnte! Ihr habt den Vormarsch der Brennenden Legion aufgehalten und uns vor der Vernichtung durch diese schrecklichen Höllenbestien gerettet. Ihr habt unseren tiefsten Dank für Eure Dienste, $N.", 26972);

-- 10613 - Teufelshäscherdrift
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10613 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10613, "deDE", "Ich gebe zu, $N, ich bin von Euren Errungenschaften beeindruckt. Jetzt, da die Legion nicht länger die Mittel hat, uns in Schattenmond anzugreifen, können wir uns anderen Fronten zuwenden.", 26972);

-- 10619 - Die Aschenzungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10619 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10619, "deDE", "Ehre den Naaru, $N. Ihr habt den Willen des Lichts ausgeführt und Illidans Anhänger vernichtet.", 26972);

-- 10621 - Splitter des Illidaribanns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10621 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10621, "deDE", "Was habt Ihr da?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10621 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10621, "deDE", "<Ordinn nimmt Euch den Splitter der Waffe ab.>$B$BSo etwas habe schon seit langer Zeit nicht mehr gesehen. Die Waffe wurde aus einem sehr seltenen Erz geschmiedet, aber es handelt sich dabei nicht um eine gewöhnliche Klinge, $N. Sie ist mit einer Magie erfüllt, die Dämonen töten soll. Wenn Ihr sie von der Legion habt, muss sie eine Art 'Geheimwaffe' sein, die sie gegen Illidan einsetzen wollen. Welch erstaunlicher Fund!", 26972);

-- 10622 - Ein Beweis der Treue
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10622 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10622, "deDE", "Sehr gut, $N. Eure Gesinnung steht nun außer Frage. Ihr dürft jetzt zu Akama.", 26972);

-- 10623 - Splitter des Illidaribanns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10623 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10623, "deDE", "Was habt Ihr da?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10623 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10623, "deDE", "<Grokom nimmt Euch den Splitter der Waffe ab.>$B$BSo etwas habe schon seit langer Zeit nicht mehr gesehen. Die Waffe wurde aus einem sehr seltenen Erz geschmiedet, aber es handelt sich dabei nicht um eine gewöhnliche Klinge, $N.$B$BDiese Runen erfüllen die Klinge mit der Macht, Dämonen zu vernichten. Wenn die Legion ihre eigenen Truppen mit Dämonen zerstörenden Waffen ausrüstet, muss ihr Hass auf Illidan unendlich groß sein. Das könnten wir zu unserem Vorteil ausnutzen.", 26972);

-- 10624 - Eine Spukgeschichte
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10624 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10624, "deDE", "Was meint Ihr? Ich werde natürlich etwas aus der Asche herstellen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10624 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10624, "deDE", "Eure Welt wird sich bald ändern, $N.", 26972);

-- 10625 - Geisterbrille
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10625 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10625, "deDE", "Wenn Ihr Eure Brille verliert, kann ich Euch eine neue herstellen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10625 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10625, "deDE", "Blutschatten? T... Teron Blutschatten? Aber... Wie?$B$BWie kann Blutschatten denn hier sein? Das ist nicht möglich!$B$BDie Legende von Teron Blutschatten lässt sogar die Verlassenen vor Angst erzittern. Nach dem, was man hört, war Blutschatten ein $C Gul'dans und sehr mächtig. Als Blutschatten von Orgrim Schicksalhammer erschlagen wurde, nahm Gul'dan die Seele des gefallenen Hexenmeisters und pflanzte sie in die zerschlagene Hülle eines gefallenen Ritters von Sturmwind. Und so wurde der erste Todesritter der Horde geboren.", 26972);

-- 10626 - Beschafft die Waffen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10626 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10626, "deDE", "Habt Ihr die Prototypen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10626 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10626, "deDE", "Sie sind perfekt. Jetzt wollen wir sie ein eine etwas praktischere Form bringen.", 26972);

-- 10627 - Beschafft die Waffen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10627 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10627, "deDE", "Habt Ihr die Prototypen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10627 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10627, "deDE", "Sie sind perfekt. Jetzt wollen wir sie ein eine etwas praktischere Form bringen.", 26972);

-- 10628 - Akama
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10628 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10628, "deDE", "Seid gegrüßt, $N. Wir haben viel zu besprechen.$B$BIch hoffe, Euer Wesen ist aufgeschlossen. Nicht viele Leute verstehen meine Entscheidungen. Nur meine engsten Mitarbeiter wissen von den bösen Omen, die ich sehe, und den Zeichen, auf die ich warte.$B$BAls ich mich mit Illidan zusammenschloss, geschah dies, weil ich vorausgesehen hatte, dass mein Volk sonst vernichtet würde. Ich habe geduldig auf die anderen Zeichen und Visionen gewartet... Velens Auszug... die Öffnung des Dunklen Portals... und nun... Eure Ankunft.", 26972);

-- 10633 - Teron Blutschatten - Geschichte und Mythos
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10633 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10633, "deDE", "Blutschatten? Diesen Namen habe ich schon seit ewigen Zeiten nicht mehr gehört!$B$BNach dem Zweiten Krieg kehrte Blutschatten mit seinen Todesrittern hierher zurück. Als er nicht mit der Schrecklichkeit seiner neuen Form zurechtkam und ohne die Hilfe seines geliebten Anführers, Gul'dan, hilflos war, nahm Blutschatten sich das Leben.$B$BIch weiß nichts davon, dass er nun als Geist in diesen Weiten herumwandeln soll. Aber vielleicht kann ich das mit Eurer Hilfe herausfinden.", 26972);

-- 10634 - Hellsicht: Blutschattens Rüstung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10634 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10634, "deDE", "Fliegt zur Netherschwingenscherbe und beschafft die Rüstung.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10634 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10634, "deDE", "Ich muss alle Gegenstände besitzen, bevor ich Blutschattens Schicksal mit Hellsicht herausfinden kann.", 26972);

-- 10635 - Hellsicht: Blutschattens Umhang
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10635 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10635, "deDE", "Ihr müsst die Geisterbrille benutzen, um die Geister von Schattenmond sehen zu können.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10635 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10635, "deDE", "Wenn ich alle drei Gegenstände in meinem Besitz habe, kann ich mit Hellsicht versuchen, den Aufenthaltsort von Blutschatten zu bestimmen.", 26972);

-- 10636 - Hellsicht: Blutschattens Schlagstock
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10636 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10636, "deDE", "Ihr müsst die Geisterbrille benutzen, um die Geister von Schattenmond sehen zu können.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10636 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10636, "deDE", "Nur mit allen drei Gegenständen zusammen kann ich versuchen, die Geheimnisse, die Ihr zu lüften wünscht, hellzusehen!", 26972);

-- 10637 - Eine notwendige Ablenkung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10637 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10637, "deDE", "Wollen wir hoffen, dass diese Ablenkung uns die Zeit verschafft, die wir brauchen, um alles herauszufinden, was wir über die Ausbildungsgelände von Karabor wissen müssen.", 26972);

-- 10639 - Ich bin Teron Blutschatten...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10639 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10639, "deDE", "Was habt Ihr getan? DUMMKOPF!$B$BIhr müsst dieses Unrecht wieder gutmachen. Schließlich war es Euer Fehler. Nehmt einen dieser Helme. Sie sind mit der Macht der ewig brennenden Asche, die Ihr mir gebracht habt, erfüllt. Viel wichtiger ist jedoch, dass Ihr damit die Geister Schattenmonds sehen könnt, auch Teron Blutschatten.$B$BWenn Ihr ihn jemals findet, vernichtet ihn.", 26972);

-- 10642 - Spiritus ex machina
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10642 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10642, "deDE", "Ja, es besteht eine Dualität... Ich kann es fühlen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10642 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10642, "deDE", "<Zorus beginnt damit, etwas aus den Aschenproben herzustellen.>$B$BEs ist vollbracht. Seht her, eine Geisterbrille!", 26972);

-- 10643 - Herolde des Schattenmondklans
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10643 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10643, "deDE", "Wenn Ihr Eure Brille verliert, kann ich Euch eine neue herstellen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10643 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10643, "deDE", "Ihr sagt, Ihr habt die Geister zu Euch flüstern hören? Und sie sprachen über Teron Blutschatten?$B$B<Zorus schaudert.>$B$BJa... Ich kenne Teron Blutschatten. Oder besser gesagt kannte ihn. Er ist schon vor langer Zeit gestorben. Wovon können diese Geister wohl gesprochen haben?", 26972);

-- 10644 - Teron Blutschatten - Geschichte und Mythos
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10644 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10644, "deDE", "Blutschatten? Diesen Namen habe ich schon seit ewigen Zeiten nicht mehr gehört!$B$BNach dem Zweiten Krieg kehrte Blutschatten mit seinen Todesrittern hierher zurück. Als er nicht mit der Schrecklichkeit seiner neuen Form zurechtkam und ohne die Hilfe seines geliebten Anführers, Gul'dan, hilflos war, nahm Blutschatten sich das Leben.$B$BIch weiß nichts davon, dass er nun als Geist in diesen Weiten herumwandeln soll. Aber vielleicht kann ich das mit Eurer Hilfe herausfinden.", 26972);

-- 10645 - Ich bin Teron Blutschatten...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10645 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10645, "deDE", "Was habt Ihr getan? DUMMKOPF!$B$BIhr müsst dieses Unrecht wieder gutmachen. Schließlich war es Euer Fehler. Nehmt einen dieser Helme. Sie sind mit der Macht der ewig brennenden Asche, die Ihr mir gebracht habt, erfüllt. Viel wichtiger ist jedoch, dass Ihr damit die Geister Schattenmonds sehen könnt, auch Teron Blutschatten.$B$BWenn Ihr ihn jemals findet, vernichtet ihn.", 26972);

-- 10647 - GESUCHT: Uvuros, Geißel des Schattenmondtals
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10647 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10647, "deDE", "Willst du die Belohnung kassieren, Mann?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10647 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10647, "deDE", "Du bist echt der Brüller, was? Gut gemacht! Und du kriegst auch deine Belohnung. Is' doch Ehrensache...", 26972);

-- 10648 - GESUCHT: Uvuros, Geißel des Schattenmondtals
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10648 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10648, "deDE", "Ich hoffe, Ihr habt etwas Großartiges getan, Mädel. Ansonsten macht Euch vom Acker!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10648 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10648, "deDE", "Hier ist Eure Belohnung. Gebt nicht alles auf einmal aus!", 26972);

-- 10649 - Das Buch der teuflischen Namen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10649 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10649, "deDE", "Habt Ihr das Buch besorgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10649 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10649, "deDE", "Ich konnte die Macht des Buches schon über Meilen hinweg spüren. Die Versuchung, es einfach zu behalten ist... sehr groß.", 26972);

-- 10650 - Rückkehr zu den Aldor
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10650 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10650, "deDE", "Ihr bringt diese Abscheulichkeit eines Buches an einen heiligen Ort? Ich hoffe, dass Ihr dafür eine gute Erklärung habt, $N!", 26972);

-- 10651 - Varedis muss aufgehalten werden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10651 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10651, "deDE", "Habt Ihr erledigt, worum ich Euch gebeten hatte, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10651 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10651, "deDE", "Ausgezeichnete Arbeit, $N! Euer Sieg über Varedis ist ein entscheidender Schritt in unserem Krieg gegen Illidan.$B$BIhr habt Euch nicht nur den Aldor, sondern gegenüber der gesamten Scherbenwelt als würdig erwiesen. Bitte gestattet mir, die Überreste dieses schrecklichen Buchs zu vernichten.", 26972);

-- 10660 - Welch merkwürdige Wesen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10660 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10660, "deDE", "Milzen! Ich brauche Milzen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10660 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10660, "deDE", "<Forscher Tiorus nimmt die Milzen an sich und beginnt seine Untersuchung.>$B$BDas dürfte eine Weile dauern. Nehmt dies als Bezahlung für Eure harte Arbeit.", 26972);

-- 10661 - Demilziös!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10661 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10661, "deDE", "Milzen! Ich brauche Milzen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10661 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10661, "deDE", "<Gnomus reißt die Milzen hungrig an sich.>$B$BHier ist die versprochene Bezahlung. Ich rufe Euch, wenn ich noch mehr Milzen brauche.$B$BSo lecker... Ich würde fast meinen 'demilziös'!", 26972);

-- 10662 - Der Wanderschmied
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10662 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10662, "deDE", "Was führt Euch hierher, $C? Ich bekomme nicht viel Besuch.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10662 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10662, "deDE", "Ordinn hat Euch damit zu mir geschickt?$B$B<Der Schmied untersucht die Barren.>$B$BEr hatte Recht. Der Großteil der Magie ist verschwunden, aber ich kann noch immer Spuren davon in dem Metall spüren. Mit ein wenig Arbeit und ein paar 'ausgefallenen' Materialien kann ich Euch ein mächtiges antidämonisches Schwert aus diesem Metall schmieden.", 26972);

-- 10663 - Der Wanderschmied
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10663 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10663, "deDE", "Was führt Euch hierher, $C? Ich bekomme nicht viel Besuch.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10663 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10663, "deDE", "Ordinn hat Euch damit zu mir geschickt?$B$B<Der Schmied untersucht die Barren.>$B$BIch werde ehrlich mit Euch sein, $C. Ich bin in einer Zeit großgeworfen, in der die Kooperation mit der Horde undenkbar war.$B$BIch bin nicht so blind, dass ich nicht sehen würde, dass wir keine gemeinsamen Feinde haben. Ich werde Euch helfen, die antidämonische Waffe umzuschmieden, aber es wird einiges an Arbeit bedürfen und ein paar 'ausgefallene' Materialien.", 26972);

-- 10664 - Zusätzliche Materialien
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10664 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10664, "deDE", "Habt Ihr die Materialien?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10664 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10664, "deDE", "<Der Schmied nimmt Euch die Materialien ab und nickt zufrieden.>$B$BDie werden reichen. Der Rest der Materialien, die ich benötige, wird jedoch nicht so leicht zu bekommen sein.", 26972);

-- 10665 - Frisch von der Mechanar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10665 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10665, "deDE", "Konntet Ihr eine Manazelle aus der Mechanar schmuggeln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10665 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10665, "deDE", "Sie ist sogar noch mächtiger, als ich erwartet habe! Mit so viel Energie könnte ich ein Dutzend Klingen schmieden!", 26972);

-- 10666 - Encyclopaedia Daemonica
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10666 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10666, "deDE", "Habt Ihr das Buch besorgt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10666 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10666, "deDE", "<David blättert die Seiten des Buchs durch und schaudert.>$B$BDas ist nichts, mit dem man spielen sollte, $N. Sobald die Waffe fertig ist, werde ich es zerstören. Es gibt schon genug dämonische Macht in dieser Welt.", 26972);

-- 10667 - Unterweltlehm
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10667 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10667, "deDE", "Habt Ihr den Unterweltlehm bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10667 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10667, "deDE", "Das sollte funktionieren. Ich hatte zwar auf etwas mehr gehofft, aber um ehrlich zu sein können wir uns glücklich schätzen, hier draußen überhaupt etwas davon in die Finger bekommen zu haben.", 26972);

-- 10670 - Träne der Erdenmutter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10670 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10670, "deDE", "Konntet Ihr den Edelstein O'mroggs Klauen entreißen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10670 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10670, "deDE", "<David Wayne hält den Edelstein gegen das Licht und bewundert ihn.>$B$BEr ist absolut makellos und genau das, was wir brauchen. Ein fehlerhafter Edelstein würde den Träger der Waffe in Gefahr bringen und die Magie gegen ihn richten.", 26972);

-- 10672 - Das ergibt echt keinen Sinn...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10672 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10672, "deDE", "Wir haben keine Zeit zu verschwenden. Ich habe die markierten Dimetrodonten beobachtet und herausgefunden, dass sie alle einem riesigen, nein, GIGANTISCHEN Dimetrodon namens Teufelsflosse dem Großen unterstellt sind.", 26972);

-- 10673 - Teufelsflosse der Große
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10673 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10673, "deDE", "Kommt in die Gänge! Der Appetit dieses Gnoms kennt keine Grenzen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10673 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10673, "deDE", "Endlich bin ich vollkommen vor der Lava geschützt! Natürlich könnt auch Ihr etwas von dieser Technologie abhaben, $N. Ihr habt es Euch verdient!", 26972);

-- 10676 - Bann der Illidari
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10676 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10676, "deDE", "<David wischt sich den Schweiß von der Braue.>$B$BDer größte Teil der Arbeit ist getan. Um die Magie jedoch zum Leben zu erwecken, muss das Schwert erst gehärtet werden.", 26972);

-- 10677 - Der zweite Gang...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10677 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10677, "deDE", "Tagesmenü: Muskelmagen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10677 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10677, "deDE", "Das ist fantastisch! Aber ich habe gerade unglaubliche Nachrichten erhalten!", 26972);

-- 10678 - Das Hauptgericht!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10678 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10678, "deDE", "Tagesmenü: Teufelsflosses Balg", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10678 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10678, "deDE", "Ich brauche jetzt etwas Zeit für mich, $N. Vielen Dank für Eure Hilfe!", 26972);

-- 10679 - Die Waffe härten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10679 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10679, "deDE", "Habt Ihr das Schwert in der Lava der Hand von Gul'dan gehärtet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10679 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10679, "deDE", "Gut gemacht!$B$B<Der Schmied untersucht die Klinge sehr genau.>$B$BIch würde sagen, dass sie deutlich besser ist, als die grobe Waffe der Legion, mit der wir angefangen haben. Diese Klinge wird nicht nur die Dämonen der Illidari erschlagen, sondern auch die Diener der Legion vernichten können.", 26972);

-- 10680 - Die Hand von Gul'dan
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10680 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10680, "deDE", "Es ist gut, dass Ihr gekommen seid, $R. Wir haben viel zu tun.", 26972);

-- 10681 - Die Hand von Gul'dan
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10681 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10681, "deDE", "Es ist gut, dass Ihr gekommen seid, $R. Wir haben viel zu tun.", 26972);

-- 10683 - Schrifttafeln von Baa'ri
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10683 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10683, "deDE", "Habt Ihr die Schrifttafeln schon gefunden, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10683 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10683, "deDE", "Die Schrifttafeln von Baa'ri! Ja, die werden uns sehr wichtige Informationen liefern.", 26972);

-- 10684 - Oronu der Älteste
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10684 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10684, "deDE", "Gibt es schon Neuigkeiten, $N? Wir haben nicht viel Zeit.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10684 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10684, "deDE", "Akamas Handschrift... wollen wir mal sehen, was wir daraus erfahren können.", 26972);

-- 10685 - Die Verderber der Aschenzungen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10685 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10685, "deDE", "Habt Ihr die vier Fragmente des Medaillons, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10685 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10685, "deDE", "Ja! Die vier Fragmente des Medaillons. Und nun setzt sie zusammen...", 26972);

-- 10686 - Der Kerker des Wächters
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10686 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10686, "deDE", "Wir haben Euch erwartet, $N. Akama sagte, dass Ihr früher oder später kommen würdet.", 26972);

-- 10687 - Ausbildungsgelände von Karabor
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10687 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10687, "deDE", "Habt Ihr die Aufgabe, mit der ich Euch betraut habe, erfüllt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10687 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10687, "deDE", "Wollen wir uns diese Waffen einmal genauer ansehen, $N. Hmmm... das ist ziemlich beunruhigend.", 26972);

-- 10688 - Eine notwendige Ablenkung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10688 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10688, "deDE", "Das sollte uns genug Zeit verschaffen... hoffentlich reicht sie aus, um weitere Informationen zu sammeln.", 26972);

-- 10691 - Rückkehr zu den Sehern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10691 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10691, "deDE", "Viele würden für das Buch, das Ihr bei Euch tragt, einen hohen Preis bezahlen. Es ist eine Schande, dass wir es zerstören müssen.", 26972);

-- 10692 - Varedis muss aufgehalten werden
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10692 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10692, "deDE", "Habt Ihr erledigt, worum ich Euch gebeten hatte, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10692 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10692, "deDE", "Ausgezeichnete Arbeit, $N! Euer Sieg über Varedis ist ein entscheidender Schritt in unserem Krieg gegen Illidan.$B$BNach dieser Tat wird euer Name sicher die Runde machen.$B$BBitte erlaubt mir, die Überreste des Buchs der teuflischen Namen an mich zu nehmen. Ich werde dafür sorgen, dass es ordnungsgemäß... entsorgt wird.", 26972);

-- 10702 - Routinearbeiten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10702 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10702, "deDE", "Fantastisch! Wenn ich noch mehr Routinearbeiten zu erledigen habe, komme ich auf Euch zurück!", 26972);

-- 10703 - Zieht Eure Knieschoner an...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10703 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10703, "deDE", "Jep, gute Arbeit! Hier habt Ihr ein wenig Bares für Eure Mühen. Wenn ich noch mehr Drecksarbeit zu erledigen habe, weiß ich ja, wen ich rufen soll.", 26972);

-- 10705 - Seher Udalo
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10705 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10705, "deDE", "Der Seher der Aschenzungen ist schon lange tot. Als Ihr Euch über seinen Körper beugt, erkennt Ihr, dass auf dem Boden etwas geschrieben steht.", 26972);

-- 10706 - Ein mysteriöses Omen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10706 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10706, "deDE", "Ja... natürlich! Jetzt wird alles klar.", 26972);

-- 10707 - Die Terrasse von Ata'mal
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10707 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10707, "deDE", "Ihr seid zurück, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10707 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10707, "deDE", "Der Kristall! Seine Macht... in meinen Händen!", 26972);

-- 10708 - Akamas Versprechen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10708 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10708, "deDE", "<Als Ihr A'dal das Medaillon übergebt, verschwindet es mit einem Lichtblitz in seinem Geist.>$B$B<Für einen kurzen Moment erscheint eine Szene vor Euch...$B$Bvielleicht aus der Zukunft. Ihr seht, wie Akama und Maiev aus dem Kerker des Wächters heraustreten und sich zum Schwarzen Tempel durchschlagen. Eine dritte, in Schatten gehüllte Gestallt hilft ihnen dabei. Als Ihr genauer hinschaut, erkennt Ihr, dass Ihr diese Gestalt seid.>", 26972);

-- 10744 - Nachricht vom Sieg
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10744 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10744, "deDE", "<Kurdran hört Euren Bericht an.>$B$BDas sind in der Tat gute Nachrichten! Noch vor ein paar Tagen hätte ich mir nie träumen lassen, dass wir der Belagerung der Legion ein Ende machen könnten.$B$BIhr habt nicht nur ihren Angriff verhindert, sondern auch noch ihre Maschinerie vernichtet! Für diesen Heldenmut habt Ihr den Dank der Wildhämmer, $N.", 26972);

-- 10745 - Nachricht vom Sieg
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10745 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10745, "deDE", "<Der Oberanführer hört Euren Bericht an.>$B$BAusgezeichnete Nachrichten! Den Angriffen der Legion standzuhalten nahm einfach viel zu viele Leute in Anspruch. Ich habe zwar nie geglaubt, dass meine Leute versagen würden, aber sie standen unter großer Belastung.$B$BIhr habt heute bewiesen, wie wichtig Ihr für die Horde seid. Die Wache der Kor'kron wird sich jederzeit geehrt fühlen, an Eurer Seite zu kämpfen.", 26972);

-- 10750 - Der Pfad der Eroberung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10750 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10750, "deDE", "Diese lästigen Hunde planen etwas Heimtückisches. Wir müssen weitere Nachforschungen anstellen...", 26972);

-- 10751 - Den Pfad bereinigen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10751 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10751, "deDE", "Ihr werdet es nicht glauben, Grunzer!", 26972);

-- 10759 - Findet den Deserteur
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10759 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10759, "deDE", "<Der Arakkoa kichert.>$B$BJa, ich bin der Deserteur, den der Kommandant in seinem Tagebuch erwähnt. Ich habe auf den Tag gewartet, an dem auch andere die Bedrohung erkennen, die von meinen einstigen Brüdern ausgeht.", 26972);

-- 10760 - Das Wrack der Sketh'lon
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10760 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10760, "deDE", "Was habt Ihr herausgefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10760 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10760, "deDE", "<Der Unteroffizier untersucht die Tagebuchseiten.>$B$BHier steht nicht viel Sinnvolles, aber ein paar Einträge könnten sich als nützlich erweisen. Wie es aussieht waren die Arakkoa dabei, ein kompliziertes magisches Ritual vorzubereiten, bis sie starben, aber warum? Hier steht auch etwas Merkwürdiges über einen 'Deserteur'.", 26972);

-- 10761 - Findet den Deserteur
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10761 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10761, "deDE", "<Der Arakkoa kichert.>$B$BJa, ich bin der Deserteur, den der Kommandant in seinem Tagebuch erwähnt. Ich habe auf den Tag gewartet, an dem auch andere die Bedrohung erkennen, die von meinen einstigen Brüdern ausgeht.", 26972);

-- 10765 - Wenn Welten kollidieren...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10765 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10765, "deDE", "Was habt Ihr zu berichten, Soldat?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10765 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10765, "deDE", "Sie versuchen also, sich die Gunst der Riesen zu erschleichen, was? Ich habe einen Plan, der diese unheilige Verbindung ganz schnell wieder zerreißen wird.", 26972);

-- 10766 - Invasionspunkt: Katastrophe
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10766 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10766, "deDE", "Es freut mich, Euch kennen zu lernen, $N. Mein Name ist Plexi.$B$BIch werde Euch nicht mit Höflichkeiten langweilen. Wir wissen beide, warum wir hier sind. Und nun an die Arbeit.", 26972);

-- 10767 - Invasionspunkt: Katastrophe
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10767 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10767, "deDE", "Ihr müsst derjenige sein, von dem Blutwache Gulmok gesprochen hat. Ich habe bereits einen Plan, aber ich brauche Eure Hilfe, um die Vorbereitungen abzuschließen.", 26972);

-- 10768 - Wappenröcke der Illidari
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10768 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10768, "deDE", "Was habt Ihr zu berichten, Soldat?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10768 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10768, "deDE", "Aha! Die werden funktionieren.", 26972);

-- 10769 - Zwietracht in den Rängen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10769 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10769, "deDE", "Ihr seid zurück!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10769 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10769, "deDE", "Gut, gut, gut... Wenn das nicht der Grunzer ist, den ich zu den Feldern geschickt habe. Ihr seid heil zurück.$B$B<Or'barokh nickt.>$B$BIch wusste, dass Ihr mich nicht enttäuschen würdet, Soldat. Ihr habt ein entscheidendes Vorrücken der Illidari aufgehalten und Euch damit eine Belohnung verdient.", 26972);

-- 10772 - Der Pfad der Eroberung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10772 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10772, "deDE", "Diese lästigen Hunde planen etwas Heimtückisches. Wir müssen weitere Nachforschungen anstellen...", 26972);

-- 10773 - Den Pfad bereinigen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10773 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10773, "deDE", "Was habt Ihr zu berichten, Soldat?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10773 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10773, "deDE", "Ihr werdet es nicht glauben, Soldat!", 26972);

-- 10774 - Blutelf + Riese = ???
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10774 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10774, "deDE", "Was habt Ihr zu berichten, Soldat?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10774 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10774, "deDE", "Sie versuchen also, sich die Gunst der Reisen zu erschleichen, was? Ich habe einen Plan, der diese unheilige Verbindung ganz schnell wieder zerreißen wird.", 26972);

-- 10775 - Wappenröcke der Illidari
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10775 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10775, "deDE", "Was habt Ihr zu berichten, Soldat?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10775 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10775, "deDE", "Aha! Die werden funktionieren.", 26972);

-- 10776 - Zwietracht in den Rängen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10776 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10776, "deDE", "Ihr seid zurück!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10776 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10776, "deDE", "Gut, gut, gut... Wenn das nicht der Soldat ist, den ich zu den Feldern geschickt habe. Ihr seid heil zurück.$B$B<Yoregar nickt.>$B$BIch wusste, dass Ihr mich nicht enttäuschen würdet, Soldat. Ihr habt ein entscheidendes Vorrücken der Illidari aufgehalten und Euch damit eine Belohung verdient.", 26972);

-- 10777 - Asghars Totem
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10777 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10777, "deDE", "Habt Ihr das Totem von Asghar beschafft?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10777 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10777, "deDE", "<Parshah untersucht das Totem.>$B$BGut. Dieses alte Totem hat seine Macht über die Jahre nicht eingebüßt, doch es alleine reicht noch nicht aus, um den Dunklen Rat aufzuhalten.", 26972);

-- 10778 - Die Rute von Lianthe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10778 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10778, "deDE", "Konntet Ihr die Rute beschaffen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10778 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10778, "deDE", "Gut gemacht. Ein solcher Schatz verdient besseres, als in einer dunklen Kiste weggesperrt zu werden. Wir werden ihn für einen guten Zweck einsetzen.", 26972);

-- 10780 - Federn der Sketh'lon
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10780 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10780, "deDE", "Habt Ihr die Federn für den Stab schon gesammelt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10780 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10780, "deDE", "<Parshah nimmt Euch die aschebestäubten Federn ab und schüttelt den Kopf.>$B$BEs wäre besser gewesen, wenn ich an diesem Tag gestorben wäre, aber die Dinge sind niemals so einfach. Dass Gul'dans Magie sie in etwas verwandelt hat, das sie aufzuhalten versuchten, ist ein grausames Spiel des Schicksals.", 26972);

-- 10781 - Die Schlacht an der Purpurwacht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10781 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10781, "deDE", "Wir werden weitere Nachforschungen über das Purpursiegel anstellen. Sie stellen eine Bedrohung für alles Leben in Draenor dar. Ich sehe einen Tag voraus, an dem ihr dunkler Herr für seine Verbrechen geradestehen muss. Vielleicht seid Ihr ja diejenige, der ihn der Gerechtigkeit zuführen wird, $N.", 26972);

-- 10782 - Das Kopfstück mit Magie erfüllen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10782 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10782, "deDE", "Seid Ihr mit dem magieerfüllten Kopfstück zurück?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10782 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10782, "deDE", "<Parshah nimmt Euch das Kopfstück ab und hält es behutsam in den Händen.>$B$BDieses Kopfstück enthält die Macht, die wir brauchen, um die Pläne des Dunklen Rats im Basislager der Sketh'lon zunichtezumachen.", 26972);

-- 10793 - Val'zareqs Tagebuch: Vorboten des Krieges
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10793 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10793, "deDE", "<General Auralion schwebt in der Mitte des Kristalls.>$B$BWa... Was tut Ihr hier?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10793 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10793, "deDE", "Ihr habt ihren Eroberer getötet? Dann haben wir nicht viel Zeit...$B$BDas Purpursiegel besteht aus der Elite von Illidans Dienern. Sie stehen am oberen Ende der Befehlskette für Illidans Armeen außerhalb des Schwarzen Tempels. Diese Soldaten stehen in direktem Kontakt mit dem Verräter und führen seine Anweisung ohne Fragen zu stellen aus.$B$BSie sind diejenigen, die ohne mit der Wimper zu zucken einen Angriff auf diese Welt starten und dabei alles, was ihnen in Wege steht, dem Erdboden gleichmachen würden.", 26972);

-- 10804 - Freundlichkeit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10804 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10804, "deDE", "Ihr seid ein freundlicher und mitfühlender $R, mein Freund.", 26972);

-- 10807 - Die Aschenzungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10807 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10807, "deDE", "Ehre den Sehern, $N. Ihr habt den Willen des Lichts ausgeführt und Illidans Anhänger vernichtet.", 26972);

-- 10808 - Dem Dunklen Rat in die Quere kommen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10808 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10808, "deDE", "Ist es vollbracht, $N? Habt Ihr den Dunklen Rat davon abgehalten, das Ritual zu vollenden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10808 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10808, "deDE", "Ich habe jahrelang nach einem Weg gesucht, um den Dunklen Rat aufzuhalten. Ihr habt geschafft, wobei ich versagt habe. Die finsteren Rituale des Dunklen Rats werden nie wieder zu einer Bedrohung für uns.$B$BIch fühle mich oft schuldig, weil ich meine Kameraden vor all diesen Jahren verlassen habe, aber nun weiß ich endlich, dass es die richtige Entscheidung war. Hätte mein Gewissen damals nicht zu mir gesprochen, wäre ich nun vielleicht ein Schatten unter ihnen.", 26972);

-- 10811 - Sucht Neltharaku auf
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10811 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10811, "deDE", "Meine Kinder haben mir von Eurer heldenhaften Tat erzählt, $R. Es gibt noch mehr, was Ihr tun könnt.", 26972);

-- 10814 - Neltharakus Geschichte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10814 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10814, "deDE", "Werdet Ihr uns also helfen?", 26972);

-- 10816 - Rückforderung geheiligten Bodens
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10816 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10816, "deDE", "Ausgezeichnete Arbeit, $C. Möge das Licht Euch beschützen.", 26972);

-- 10817 - Die große Vergeltung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10817 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10817, "deDE", "Ihr habt meinen höchsten Respekt verdient, $N.$B$BEinen Höllenorc alleine zu töten ist schon keine leichte Aufgabe. Eine ganze Meute von ihnen zu töten ist, nun... heroisch.", 26972);

-- 10836 - Unterwanderung der Festung des Drachenmals
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10836 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10836, "deDE", "Gut gemacht, $N. Ich habe einen Weg gefunden, wie wir die versklavten Drachen in der Festung des Drachenmals befreien können.", 26972);

-- 10837 - Zur Netherschwingenscherbe!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10837 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10837, "deDE", "Ich brauche Netherrankenkristalle.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10837 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10837, "deDE", "<Neltharaku nimmt Euch die Kristalle ab.>$B$BIch werde nun die Kristalle mit meiner Magie erfüllen.", 26972);

-- 10854 - Die Macht Neltharakus
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10854 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10854, "deDE", "Verschwendet keine Zeit, wir haben viel zu tun!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10854 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10854, "deDE", "<Neltharaku lacht.>$B$BDie Orcs müssen einen ganz schönen Schreck bekommen haben, als die Drachen sich plötzlich gegen sie gewendet haben. Gut gemacht, $N. Vielleicht seid Ihr wirklich der Held unseres Schwarms.", 26972);

-- 10858 - Karynaku
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10858 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10858, "deDE", "Es sind die Ketten. Sie berauben mich meiner Macht. Der einzige Ausweg ist, den Schlüssel von Zuluhed zu beschaffen und mich loszuketten.", 26972);

-- 10866 - Zuluhed der Geschlagene
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10866 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10866, "deDE", "Ich bin frei! Ihr habt uns gerettet, $N!", 26972);

-- 10870 - Verbündeter der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10870 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10870, "deDE", "Ihr habt Euch als Verbündeter der Netherschwingen erwiesen. Meine Mutter ist frei und meine Brüder und Schwestern gerettet!$B$BVielleicht werde ich Euch eines Tages erneut rufen. Wenn dieser Tag kommt, werdet Ihr mit offenen Armen begrüßt werden, als Bruder des Drachenschwarms der Netherschwingen.", 26972);

-- 10883 - Der Schlüssel der Stürme
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10883 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10883, "deDE", "Die Festung der Stürme ist eine Erfindung der Naaru, Sterbliche. Zutritt zu der Festung zu gewähren lag schon immer alleine im Ermessen der Naaru. Eine Rückkehr zur Festung der Stürme erschien uns jedoch unnötig. Vielleicht mag das für eine Sterbliche Rasse wie Stolz aussehen, doch wir Naaru halten nur wenig von solchen Dingen.$B$BWir gehen nun, weil wir es müssen. Kael'thas darf die Litanei der Verdammnis niemals vorlesen.", 26972);

-- 10884 - Die Prüfung der Naaru: Erbarmen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10884 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10884, "deDE", "<A'dal grüßt Euch.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10884 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10884, "deDE", "Gut gemacht, $N. Ihr habt die Prüfung des Erbarmens abgeschlossen.", 26972);

-- 10885 - Die Prüfung der Naaru: Stärke
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10885 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10885, "deDE", "<A'dal grüßt Euch.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10885 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10885, "deDE", "Gut gemacht, $N. Ihr habt die Prüfung der Stärke abgeschlossen.", 26972);

-- 10886 - Die Prüfung der Naaru: Zuverlässigkeit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10886 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10886, "deDE", "Gut gemacht, $N. Ihr habt die Prüfung der Zuverlässigkeit abgeschlossen.", 26972);

-- 10888 - Die Prüfung der Naaru: Magtheridon
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10888 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10888, "deDE", "Ihr habt Euch als Wesen mit großer Macht bewiesen. Die Naaru gewähren Euch Einlass in die Festung der Stürme.", 26972);

-- 10944 - Das gefährdete Geheimnis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10944 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10944, "deDE", "Ich danke Euch, $N. Olum ist einer meiner engsten Freunde und meiner treuesten Anhänger. Sein Beitrag zu unserem Werk ist für unsere Pläne unverzichtbar.", 26972);

-- 10949 - Zutritt zum Schwarzen Tempel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10949 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10949, "deDE", "<Xi'ri scheint Eure Anwesenheit zu bemerken. Offensichtlich konzentriert er sich auf die Schlacht in der Umgebung.>", 26972);

-- 10985 - Ein Ablenkungsmanöver für Akama
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10985 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10985, "deDE", "<Xi'ri pulsiert vor Energie, Ihr fühlt, wie ein Gegenstand in Euren Händen Gestalt annimmt. Es ist das Medaillon, das Ihr A'dal im Namen von Akama gegeben habt. Seine Macht hat sich durch die Magie der Naaru noch verstärkt. Die Sha'tar haben Euch das Medaillon von Karabor anvertraut, und damit den Zugang zum Schwarzen Tempel.>", 26972);

-- 11012 - Der Blutschwur der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11012 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11012, "deDE", "Unser Land ist verloren. Man entführt unsere Kinder in der Nacht, versklavt sie - oder schlimmer...$B$B<Mordenais Stimme wird angespannt.>$B$BEs ist an der Zeit, mein Freund. Zeit, uns wieder das zu nehmen, was einst unser war! Ihr habt Euch als tapferer Kämpfer und verständnisvolle Seele erwiesen.$B$BWerdet Ihr schwören, dem Drachenschwarm der Netherschwingen beim Kampf um unser Land und den Wiederaufbau unserer Heimstätten zu helfen? Werdet Ihr schwören, über den Schwarm zu wachen, damit unser Fleisch und Blut aufs Neue zum Leben erwachen kann? Schwört und lasst uns im Namen unserer Heimat und unserer Familien kämpfen!", 26972);

-- 11013 - Im Dienste der Illidari
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11013 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11013, "deDE", "<Mor'ghor grunzt.>$B$BIhr seid spät...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11013 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11013, "deDE", "<Mor'ghor überfliegt das Schreiben und lacht.>$B$BEin Todesritter? Ihr könnt einem Todesritter nicht mal das Wasser reichen, Wurm.$B$B<Mor'ghor mustert Euch scharf.>$B$BNun gut... Ihr könntet es vielleicht noch zum Peon schaffen. Im schlimmsten Fall werfe ich Euch in die Grube und lasse Euch dort verrotten...", 26972);

-- 11014 - In der Höhle des Löwen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11014 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11014, "deDE", "Varkule findet schon was für Euch, Grunzer. Euch steht eine Aufgabe zu, die Euren Fertigkeiten am besten gerecht wird und unserer Kristallförderung zu Gute kommt. Ihr müsst Euren Arbeitsauftrag einmal am Tag ausfüllen.$B$BJa, es gibt da einen Haufen Drecksarbeit zu erledigen, aber auch die Ahnen haben mal als Peon begonnen.", 26972);

-- 11015 - Kristalle der Netherschwingen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11015 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11015, "deDE", "Kristalle der Netherschwingen werden für vielerlei Dinge verwendet. Hauptsächlich zur Herstellung von Waffen und Rüstungen...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11015 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11015, "deDE", "Das war's für heute, Kindchen. Kommt morgen wieder, wenn Ihr noch am Leben seid.", 26972);

-- 11016 - Balg eines Netherminenschinders
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11016 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11016, "deDE", "Wir verwenden die Bälge von Schindern zum Ausfüttern von Rüstungen und die Herstellung von Planen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11016 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11016, "deDE", "Das war's für heute, Kindchen. Kommt morgen wieder, wenn Ihr noch am Leben seid.", 26972);

-- 11017 - Netherstaubpollen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11017 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11017, "deDE", "Wie ich schon sagte, Netherstaubpollen werden von unseren Zauberern verwendet.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11017 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11017, "deDE", "Das war's für heute, Kindchen. Kommt morgen wieder, wenn Ihr noch am Leben seid.", 26972);

-- 11018 - Netheriterz
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11018 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11018, "deDE", "Gug dort drüben verwendet das Erz zum Verstärken unserer Waffen und Rüstungen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11018 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11018, "deDE", "Das war's für heute, Kindchen. Kommt morgen wieder, wenn Ihr noch am Leben seid.", 26972);

-- 11019 - Freund unter Feinden
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11019 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11019, "deDE", "Ihr habt doch nicht etwa geglaubt, dass wir Euch den Armeen der Höllenorcs ganz alleine überlassen würden, oder?$B$B<Yarzills Augen flackern in einem durchscheinenden Blau.>$B$BGenau, wir sind hier an Eurer Seite, $N. Bei jedem Dienst, den Ihr den Höllenorcs bei Eurem Versuch, die Weiten der Netherschwingen zurückzuerobern, erweist, werden wir dafür sorgen, dass sie einen ausreichenden Rückschlag erleiden.$B$BIhr müsst Euch sehr unauffällig verhalten, um keinerlei Aufmerksamkeit während Euren Sabotageeinsätzen auf Euch zu ziehen.", 26972);

-- 11020 - Ein langsamer Tod
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11020 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11020, "deDE", "Es ist eine schmutzige Arbeit, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11020 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11020, "deDE", "<Yarzill flüstert ganz leise.>$B$BAusgezeichnete Arbeit, $N. Verhaltet Euch fürs Erste ruhig. Kommt morgen wieder zu mir, dann können wir das Ganze noch einmal machen.", 26972);

-- 11035 - Ein Schatten am Horizont
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11035 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11035, "deDE", "Tote Orcs singen nicht, $N. Stellt sicher, dass keiner der Transporter des Drachenmals entkommt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11035 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11035, "deDE", "<Yarzill flüstert.>$B$BIhr habt den Netherschwingen einen großen Dienst erwiesen, $N. Der Fall des Drachenmals rückt in greifbare Nähe. Von innen heraus breitet sich nun eine Krankheit aus - eine unheilbare Krankheit...$B$BSolltet Ihr wieder an Arbeit bei dem Himmelspfads des Drachenmals interessiert sein, so kommt morgen wieder.", 26972);

-- 11041 - Eine unerledigte Aufgabe...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11041 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11041, "deDE", "Wer wagt es, an Mor'ghor heranzutreten? Ich hoffe für Euch, dass es von Wichtigkeit ist.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11041 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11041, "deDE", "Ihr habt also bei den Überresten einer meiner Aufseher eine Anordnung gefunden und die Sache selbst in die Hand genommen? Ihr habt es geschafft, Mor'ghor zu beeindrucken. Gut gemacht...", 26972);

-- 11043 - Ein besserer Greif
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11043 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11043, "deDE", "<Brunns Gesicht errötet, bis es nicht länger von seinem Bart zu unterscheiden ist.>$B$BEr möchte WAS mit meinen Greifen anstellen?$B$BWenn diese kleine Ratte auch nur versucht, irgendetwas anderes als einen Sattel auf meinen Greifen zu befestigen, reise ich persönlich zum Schergrat und stopfe ihm mit seinen Raketen das Maul!", 26972);

-- 11044 - Visionen voller Zerstörung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11044 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11044, "deDE", "Eine Vision sagt Ihr? Es interessiert mich nicht, ob er es in einer Vision gesehen, in einem Brief gelesen oder es aus dem Mund eines Grubenlords vernommen hat, aber er hat den Nagel auf den Kopf getroffen! Was führt Euch hierher, Freund? Oh, und wir sind für jede Unterstützung dankbar!", 26972);

-- 11047 - Die Bitte des Gesellen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11047 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11047, "deDE", "<Dama hört sich Agadais Bitte an.>$B$BIch kann nicht dafür garantieren, dass wir über genügend Windreiter verfügen, aber ich werde sehen, was ich tun kann. In der momentanen Situation haben wir Schwierigkeiten, die Nachfrage der verschiedenen Käufer und Außenposten abzudecken.", 26972);

-- 11048 - Kroghans Bericht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11048 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11048, "deDE", "<Gulmok beginnt zu murren, als er von Kroghans Entscheidung hört.>$B$BIch verstehe durchaus seinen Standpunkt, doch unsere Schützengräben besetzen sich nicht von selbst! Die Legion bombardiert uns Tag und Nacht mit Höllenbestien. Wenn Kroghan sich verspätet, könnt Ihr ja seinen Platz auf dem Schlachtfeld einnehmen!", 26972);

-- 11049 - Die große Eierjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11049 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11049, "deDE", "Was macht die Eierjagd?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11049 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11049, "deDE", "Neltharaku wird höchst erfreut sein, $N. Gut gemacht.", 26972);

-- 11050 - Immer her mit den Eiern
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11050 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11050, "deDE", "Diese Eier dürfen auf keinen Fall in die falschen Hände geraten, $N. Wenn Ihr noch mehr Eier findet, bringt sie mir.$B$BVerhaltet Euch auf jeden Fall unauffällig und erregt bloß keinen Verdacht!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11050 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11050, "deDE", "Ihr seid ein wahrer Held, $N.", 26972);

-- 11053 - Erhebt Euch, Aufseher!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11053 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11053, "deDE", "Ich habe Eure Handlungen mit einem wachsamen Auge verfolgt, $N. Ihr habt bewiesen, dass Ihr ein unschätzbarer Gewinn für das Drachenmal seid. Daher werde ich Euch zum Aufseher befördern. Ein neuer Rang bedeutet natürlich auch neue Verantwortungen, denen Ihr gerecht werden müsst.$B$BErhebt Euch, Aufseher $N! Erhebt Euch und sucht diejenigen auf, die Eure Hilfe hier im Basislager brauchen.", 26972);

-- 11054 - Aufsehen und Ihr: Die richtige Wahl treffen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11054 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11054, "deDE", "Es gilt Peons zur Ordnung zu rufen, $N! Beeilt Euch!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11054 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11054, "deDE", "Ahh! Vielleicht habt Ihr ja doch das Zeug zum Aufseher. Diese übergroße Echse war schon das Leid vieler Orcs!$B$B<Chefvorarbeiter Lehmklump beginnt mit der Herstellung der Waffe.>", 26972);

-- 11055 - Der Schuhmerang: Das Mittel gegen den wertlosen Peon
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11055 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11055, "deDE", "Der Trick liegt im Handgelenk, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11055 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11055, "deDE", "Ein Tag harter Arbeit! Es zahlt sich aber aus, oder? Beim Anblick der schuftenden Taugenichtse bei den Kristallen wird einem richtig Warm um's Herz... Nun ja, das ist alles für heute. Kommt morgen wieder, dann könnt Ihr ein weiteres Mal den Schuhmerang schwingen.", 26972);

-- 11063 - Sich Flügel verdienen...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11063 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11063, "deDE", "Ihr möchtet also zu den Himmelsteilern gehören, ja? Ihr habt Euch mit Sicherheit als fähiger Anhänger des Drachenmals bewiesen, aber in den Lüften der Scherbenwelt ist dies bedeutungslos. Es gibt eine Frage zu klären: KÖNNT IHR FLIEGEN?$B$BUnd ich frage nicht etwa, ob Ihr auf einen Netherdrachen steigen und wie diese Transportertrottel eine Ladung Kristalle zu der Festung liefern könnt. Ich rede davon, der Beste zu sein... der Toporc...$B$BDort drüben im Westen gibt es sechs Reiter. Besiegt sie alle und ich werde Euch Flügel der Himmelsteiler geben.", 26972);

-- 11064 - Drachenmalrennen: Murg &quot;Grufti&quot; Moorbiss
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11064 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11064, "deDE", "Ein Kinderspiel? Was ist nur aus den Helden geworden... Ich bin mir sicher, dass die anderen Reiter eine größere Herausforderung sein werden.", 26972);

-- 11067 - Drachenmalrennen: Trope der Rußhuster
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11067 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11067, "deDE", "Interessant... Euer nächstes Rennen wird sich zweifellos als viel schwieriger erweisen. Corlok ist kein Weichei.", 26972);

-- 11068 - Drachenmalrennen: Corlok der Veteran
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11068 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11068, "deDE", "Die nächsten zwei Reiter sind die besten Piloten, die die Zwerge und Orcs von Azeroth zu bieten hatten. Ihr habt keine Chance!", 26972);

-- 11069 - Drachenmalrennen: Schwadronskommandant Ichman
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11069 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11069, "deDE", "Ich glaube es nicht! Mulverick ist Eure nächste Herausforderung. Dieses Rennen werdet Ihr auf keinen Fall überleben.", 26972);

-- 11070 - Drachenmalrennen: Schwadronskommandant Mulverick
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11070 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11070, "deDE", "Nun Grunzer, es sieht ganz so aus, als gäbe es jetzt nur noch Euch und den Hauptmann. Viel Glück! Ihr werdet es brauchen!", 26972);

-- 11071 - Drachenmalrennen: Hauptmann Himmelsdonner
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11071 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11071, "deDE", "Ich hätte es mir nie träumen lassen, dass es jemanden gibt, der talentiert genug ist und Himmelsdonner besiegen kann. Wisst Ihr was das bedeutet, ja? Ihr seid jetzt der Toporc! Ihr müsst Euren Titel verteidigen.", 26972);

-- 11075 - Die Netherschwingenminen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11075 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11075, "deDE", "Die Minenarbeiter leisten harte Arbeit, aber keiner von ihnen wagt es, einen Schritt tiefer in die Minen zu setzen. Sie sterben lieber, als dass sie sich tiefer in die Minen zwingen lassen! Es wird Eure Aufgabe sein, die von ihnen vernachlässigten Pflichten zu erfüllen.", 26972);

-- 11076 - Die Dinge in den Griff bekommen...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11076 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11076, "deDE", "Habt Ihr die Fracht eingesammelt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11076 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11076, "deDE", "Gut gemacht, $N. Kommt morgen für einen weiteren Einsatz in den Tiefen der Mine wieder.", 26972);

-- 11081 - Der große Aufstand der Finsterblut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11081 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11081, "deDE", "Was ist das?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11081 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11081, "deDE", "Ausgezeichnete Arbeit, Aufseher. Man wird Mor'ghor von Euren herausragenden Taten für das Drachenmal berichten.$B$BLasst uns jetzt wieder auf diese Hunde der Finsterblut zu sprechen kommen. Sie planen ihre Flucht, ja? Sie wagen es, sich dem einzig wahren Fürsten der Scherbenwelt zu widersetzen? Ihre Meister werden dafür bezahlen!", 26972);

-- 11082 - Suche nach der Wahrheit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11082 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11082, "deDE", "Nun? Warum dauert das so lange?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11082 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11082, "deDE", "Nichts zu sagen? Vielleicht erinnert er sich ja, wenn er auf dem Boden dieser verfluchten Mine zu Tode blutet... Vergesst nie, was es bedeutet, die Mächte Illidans herauszufordern!", 26972);

-- 11083 - Verrückt und verwirrt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11083 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11083, "deDE", "Ja, ich verstehe das nicht... Man würde doch meinen, dass sie nach zwei Tagen nicht derart ausgehungert sein können. Finsterblut...$B$B<Ronag schüttelt den Kopf.>$B$BSo was von dämlich...", 26972);

-- 11084 - Seid gegrüßt, Hauptmann!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11084 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11084, "deDE", "<Mor'ghor nickt.>$B$BGanz recht, ich habe Hauptmann gesagt. Ihr habt Euch eine weitere Beförderung verdient, $N.$B$BIhr arbeitet wirklich wie keiner der Höllenorcs, die ich bis jetzt gesehen habe. Macht weiter so, dann schafft Ihr es vielleicht eines Tages zum Oberanführer.$B$BZieht jetzt los und übernehmt das Kommando. Ich schlage vor, dass Ihr versucht, Euch Eure Flügel der Himmelsteiler zu verdienen.", 26972);

-- 11086 - Schwächt das Portal des Zwielichts
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11086 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11086, "deDE", "Ausgezeichnete Arbeit, Hauptmann! Fürst Illidan wird von Euren Heldentaten erfahren!", 26972);

-- 11089 - Die Seelenkanone Reth'hedrons
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11089 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11089, "deDE", "Habt Ihr die benötigten Bauelemente für die Anfertigung der Seelenkanone?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11089 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11089, "deDE", "<Balthas fügt die Elemente, die Ihr ihm gebracht habt, geschickt zusammen.>$B$BIhr seid jetzt bereit für den zweiten Teil des Plans, Hauptmann.", 26972);

-- 11090 - Unterdrückt den Unterdrücker
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11090 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11090, "deDE", "Ist es vollbracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11090 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11090, "deDE", "Er wird zurückkehren, aber für den Moment hat der Krieg der Legion gegen Fürst Illidan eine Schwäche erfahren. Man wird ihm von Euren Taten berichten, Hauptmann.", 26972);

-- 11092 - Glück auf, Kommandant!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11092 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11092, "deDE", "Fürst Illidan hat mich höchstpersönlich mit Eurer Beförderung zum Kommandanten beauftragt! So etwas hat es noch nie gegeben. Ihr seid der Erste des Drachenmals, der solch einen Rang außerhalb des Schwarzen Tempels erlangt hat.", 26972);

-- 11094 - Tötet sie alle!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11094 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11094, "deDE", "Beruhigt Euch, Kind.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11094 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11094, "deDE", "Es war gut, dass Ihr zu uns gekommen seid. Vielleicht können wir diesen Angriff des Drachenmals zu unserem Vorteil nutzen und den Spieß umdrehen.", 26972);

-- 11095 - Kommandant Hobb
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11095 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11095, "deDE", "<Hobb nickt.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11095 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11095, "deDE", "<Hobb grinst.>$B$BDie tödlichste Falle aller Zeiten...", 26972);

-- 11097 - Die tödlichste Falle aller Zeiten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11097 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11097, "deDE", "Habt Ihr sie mit Euren Fäusten zerschmettert, Kommandant?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11097 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11097, "deDE", "<Mor'ghor lacht.>$B$BHAHA! Ich habe gewusst, dass ich auf Euch zählen kann, Kommandant! Ich möchte, dass Ihr das Sanktum der Sterne mindestens einmal pro Tag überfallt. Sie werden keine andere Wahl haben und das Schattenmondtal verlassen müssen!", 26972);

-- 11099 - Tötet sie alle!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11099 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11099, "deDE", "Beruhigt Euch, Kind.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11099 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11099, "deDE", "Es war gut, dass Ihr zu uns gekommen seid. Vielleicht können wir diesen Angriff des Drachenmals zu unserem Vorteil nutzen und den Spieß umdrehen.", 26972);

-- 11100 - Kommandant Arcus
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11100 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11100, "deDE", "<Arcus nickt.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11100 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11100, "deDE", "<Arcus grinst.>$B$BDie tödlichste Falle aller Zeiten...", 26972);

-- 11101 - Die tödlichste Falle aller Zeiten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11101 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11101, "deDE", "Habt Ihr sie mit Euren Fäusten zerschmettert, Kommandant?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11101 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11101, "deDE", "<Mor'ghor lacht.>$B$BHAHA! Ich habe gewusst, dass ich auf Euch zählen kann, Kommandant! Ich möchte, dass Ihr den Altar der Sha'tar mindestens einmal pro Tag überfallt. Sie werden keine andere Wahl haben und das Schattenmondtal verlassen müssen!", 26972);

-- 11107 - Verneigt Euch vor dem Hochlord
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11107 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11107, "deDE", "Ihr seid der erste Hochlord des Drachenmals, $N. Der Meister hat beschlossen höchstpersönlich hierher zu kommen, um Euch zu befördern.", 26972);

-- 11108 - Fürst Illidan Sturmgrimm
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11108 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11108, "deDE", "Ich war der Erste, wisst Ihr. Das verlassene Kind eines Monsters...$B$B<Barthamus schüttelt seinen Kopf.>$B$BWir haben Euch alles zu verdanken, $N. Ganz allein habt Ihr das Reich des Drachenmals zerschmettert und dabei genug Informationen gesammelt, die meine Brüder mehr als ein Leben lang beschäftigen werden.$B$BEs ist zwar nicht viel, aber es gibt da etwas, das wir Euch anbieten können... Ein jeder meines Schwarms hat sich dazu bereit erklärt, Euch bei Euren Abenteuern in der Scherbenwelt zu begleiten. Fragt sie einfach und sie werden mit Euch einen Bund eingehen.", 26972);

-- 11109 - Jorus, der kobaltblaue Drache der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11109 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11109, "deDE", "Es ist eine Ehre, Euch zu treffen, $N. Wir alle haben Eure Abenteuer mit großer Aufmerksamkeit verfolgt. Wir sind äußerst dankbar für alles, was Ihr für den Drachenschwarm der Netherschwingen getan habt.$B$BWenn Ihr mich zu Eurem Weggefährten macht, werde ich Euch bis ans Ende dieser Welt und wieder zurück fliegen. Was auch immer Ihr von mir verlangt, ich werde mein Bestes tun, um Euren Wunsch zu befolgen.$B$BIhr sollt jedoch wissen, dass Ihr nur einen von uns für Eure Reisen in der Scherbenwelt erwählen könnt. Habt Ihr Euch einmal entschieden, so könnt Ihr Eure Meinung nicht mehr ändern.", 26972);

-- 11110 - Malfas, der lila Drache der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11110 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11110, "deDE", "Es ist eine Ehre, Euch zu treffen, $N. Wir alle haben Eure Abenteuer mit großer Aufmerksamkeit verfolgt. Wir sind äußerst dankbar für alles, was Ihr für den Drachenschwarm der Netherschwingen getan habt.$B$BWenn Ihr mich zu Eurem Weggefährten macht, werde ich Euch bis ans Ende dieser Welt und wieder zurück fliegen. Was auch immer Ihr von mir verlangt, ich werde mein Bestes tun, um Euren Wunsch zu befolgen.$B$BIhr sollt jedoch wissen, dass Ihr nur einen von uns für Eure Reisen in der Scherbenwelt erwählen könnt. Habt Ihr Euch einmal entschieden, so könnt Ihr Eure Meinung nicht mehr ändern.", 26972);

-- 11111 - Onyxien, der onyxfarbene Drache der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11111 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11111, "deDE", "Es ist eine Ehre, Euch zu treffen, $N. Wir alle haben Eure Abenteuer mit großer Aufmerksamkeit verfolgt. Wir sind äußerst dankbar für alles, was Ihr für den Drachenschwarm der Netherschwingen getan habt.$B$BWenn Ihr mich zu Eurem Weggefährten macht, werde ich Euch bis ans Ende dieser Welt und wieder zurück fliegen. Was auch immer Ihr von mir verlangt, ich werde mein Bestes tun, um Euren Wunsch zu befolgen.$B$BIhr sollt jedoch wissen, dass Ihr nur einen von uns für Eure Reisen in der Scherbenwelt erwählen könnt. Habt Ihr Euch einmal entschieden, so könnt Ihr Eure Meinung nicht mehr ändern.", 26972);

-- 11112 - Suraku, der azurblaue Drache der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11112 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11112, "deDE", "Es ist eine Ehre, Euch zu treffen, $N. Wir alle haben Eure Abenteuer mit großer Aufmerksamkeit verfolgt. Wir sind äußerst dankbar für alles, was Ihr für den Drachenschwarm der Netherschwingen getan habt.$B$BWenn Ihr mich zu Eurem Weggefährten macht, werde ich Euch bis ans Ende dieser Welt und wieder zurück fliegen. Was auch immer Ihr von mir verlangt, ich werde mein Bestes tun, um Euren Wunsch zu befolgen.$B$BIhr sollt jedoch wissen, dass Ihr nur einen von uns für Eure Reisen in der Scherbenwelt erwählen könnt. Habt Ihr Euch einmal entschieden, so könnt Ihr Eure Meinung nicht mehr ändern.", 26972);

-- 11113 - Voranaku, der violette Drache der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11113 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11113, "deDE", "Es ist eine Ehre, Euch zu treffen, $N. Wir alle haben Eure Abenteuer mit großer Aufmerksamkeit verfolgt. Wir sind äußerst dankbar für alles, was Ihr für den Drachenschwarm der Netherschwingen getan habt.$B$BWenn Ihr mich zu Eurem Weggefährten macht, werde ich Euch bis ans Ende dieser Welt und wieder zurück fliegen. Was auch immer Ihr von mir verlangt, ich werde mein Bestes tun, um Euren Wunsch zu befolgen.$B$BIhr sollt jedoch wissen, dass Ihr nur einen von uns für Eure Reisen in der Scherbenwelt erwählen könnt. Habt Ihr Euch einmal entschieden, so könnt Ihr Eure Meinung nicht mehr ändern.", 26972);

-- 11114 - Zoya, der viridiangrüne Drache der Netherschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11114 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11114, "deDE", "Es ist eine Ehre, Euch zu treffen, $N. Wir alle haben Eure Abenteuer mit großer Aufmerksamkeit verfolgt. Wir sind äußerst dankbar für alles, was Ihr für den Drachenschwarm der Netherschwingen getan habt.$B$BWenn Ihr mich zu Eurem Weggefährten macht, werde ich Euch bis ans Ende dieser Welt und wieder zurück fliegen. Was auch immer Ihr von mir verlangt, ich werde mein Bestes tun, um Euren Wunsch zu befolgen.$B$BIhr sollt jedoch wissen, dass Ihr nur einen von uns für Eure Reisen in der Scherbenwelt erwählen könnt. Habt Ihr Euch einmal entschieden, so könnt Ihr Eure Meinung nicht mehr ändern.", 26972);

-- 11385 - GESUCHT: Kanalisierer der Sonnensucher
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11385 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11385, "deDE", "Mit den Kanalisierern ist es aus. Der, der aus dem Nether zu mir spricht ist zufrieden und Ihr habt Euch Eure Belohnung redlich verdient.$B$BKehrt morgen zu mir zurück, wenn die Winde Mah'duun ihren Willen offenbart haben.", 26972);

-- 11497 - Fliegen lernen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11497 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11497, "deDE", "So, mein Junge Nutral schickte dich vorbei, stimmts? Guter Mann... Ich muss daran denken ihm einen auszugeben, für all die Geschäfte die er mir vermittelte.$B$BWenn es darum geht wie man richtig und ordnungsgemäß fliegen lernt, bist du hier genau richtig. Niemand fliegt feiner als wir Wildhammer und die, die wir trainieren. Gegen eine Gebühr, die nicht gerade gering ausfällt, werde ich dir lehren wie man durch die Lüfte steigt!$B$BUnd wenn du fertig bist, vergiss nicht mit Brunn dort drüben über den Kauf einer dieser schönen Greifen zu sprechen!", 26972);

-- 11498 - Fliegen lernen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11498 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11498, "deDE", "Blut und Donner, Nutral hat mir schon wieder einen Boden-Grunzer geschickt! Sehr gut... für einen Draenei.$B$B<Olrokk spuckt auf den Boden neben Euch.>$B$BWenn Ihr wissen wollt, wie man richtig fliegt, dann seid Ihr am richtigen Ort. Für einen großen Sack Gold bringe ich Euch genug bei, um nicht unehrenhaft in den Tod zu stürzen.$B$BUnd wenn Ihr fertig seid, dann vergesst nicht, Dama Wildmähne einen unserer Windreiter abzukaufen!", 26972);

-- 13429 - Ein Ablenkungsmanöver für Akama
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 13429 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (13429, "deDE", "<Xi'ri pulsiert vor Energie, Ihr fühlt, wie ein Gegenstand in Euren Händen Gestalt annimmt. Es ist das Medaillon, das Ihr A'dal im Namen von Akama gegeben habt. Seine Macht hat sich durch die Magie der Naaru noch verstärkt. Die Sha'tar haben Euch das Medaillon von Karabor anvertraut, und damit den Zugang zum Schwarzen Tempel.>", 26972);

-- 13430 - Die Prüfung der Naaru: Magtheridon
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 13430 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (13430, "deDE", "Ihr habt Euch als Wesen mit großer Macht bewiesen. Die Naaru sind sich einig...", 26972);
