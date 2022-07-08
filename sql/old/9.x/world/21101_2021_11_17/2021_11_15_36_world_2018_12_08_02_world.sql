-- Terokkar Forest -- Wälder von Terokkar
-- RequestItems, OfferReward -- master, 3.3.5

-- 9793 - Das Schicksal von Tuurem
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9793 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9793, "deDE", "Wie kann ich Euch helfen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9793 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9793, "deDE", "Hmm... Ich kann mich erinnern, dass unsere Späher von den Ruinen einer Draeneisiedlung in den nördlichen Ausläufern des Waldes berichtet haben. Ich weiß jedoch selbst nicht viel über die Ruinen, aber Ihr könnt gerne mit unseren Spähern sprechen.", 26972);

-- 9796 - Nachricht aus den Zangarmarschen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9796 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9796, "deDE", "Es wurde auch langsam Zeit, dass der Außenposten fertig wird. Wir haben schon viel zu viele Boten an die Vorhut der Allianz verloren.", 26972);

-- 9951 - Es beobachtet Euch!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9951 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9951, "deDE", "Es ist besser so. Wenn es keine zivilisierte Einladung annehmen kann, dann ist es das auch nicht wert.$B$B<Aufseher Baumlas schaut Euch kurz verwirrt an.>$B$BWer seid Ihr und was wollt Ihr hier? Ihr müsst von hier verschwinden, bevor es zu spät ist!", 26972);

-- 9960 - Was ist los mit dem Cenariusdickicht?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9960 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9960, "deDE", "Ich bin froh, dass die Steinbrecherfeste Euch geschickt hat. Die Druiden des Dickichts wurden ermordet! Nur ich und ein weiterer haben überlebt, und er ist geisteskrank.$B$BIch weiß nicht, was passiert ist, aber ich bin entschlossen, es herauszufinden. Was auch immer es war, es passierte schnell und fühlt sich unnatürlich an.$B$BWerdet Ihr mir helfen?", 26972);

-- 9961 - Was ist los mit dem Cenariusdickicht?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9961 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9961, "deDE", "Ich bin froh, dass Allerias Feste Euch geschickt hat. Die Druiden des Dickichts wurden ermordet! Nur ich und ein weiterer haben überlebt, und er ist geisteskrank.$B$BIch weiß nicht, was passiert ist, aber ich bin entschlossen, es herauszufinden. Was auch immer es war, es passierte schnell und fühlt sich unnatürlich an.$B$BWerdet Ihr mir helfen?", 26972);

-- 9968 - Fremde Energien
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9968 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9968, "deDE", "Habt Ihr meine Proben?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9968 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9968, "deDE", "Merkwürdig. Die Proben der bösartigen Teromotten enthalten etwas, das sich wie reines Mana anfühlt.$B$BWie es scheint hinterließ das, was all die Tode verursacht hat, ein starkes Energiefeld. Aber aus irgendeinem Grund hat es die Teromotten nicht umgebracht, sondern nur aufgewühlt.$B$BEs scheint, als wäre diese merkwürdige Energie ein Nebenprodukt dessen, was das Dickicht angegriffen hat.", 26972);

-- 9971 - Hinweise im Dickicht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9971 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9971, "deDE", "Ich hatte also Recht. Die Leiche eines Zerschlagenen? Und Ihr sagt, dass da tatsächlich ein komisches Objekt auf dem Boden neben ihm war?$B$BDas macht keinen Sinn. Was würde einer von ihnen denn hier wollen? Und was war das für ein Ding, das er dabei hatte?$B$BHat es vielleicht all die Tode verursacht?", 26972);

-- 9978 - Mit allen Mitteln
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9978 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9978, "deDE", "Gut, gut... Ich sage Euch, was ich weiß, aber viel ist das nicht!", 26972);

-- 9979 - Windhändler Lathrai
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9979 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9979, "deDE", "Ja? Wie kann ich Euch diesmal helfen, $R?", 26972);

-- 9986 - Die Arakkoa hindern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9986 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9986, "deDE", "Gut gemacht, $N. Wir haben schon genug Sorgen, wir können uns nicht erlauben, dass die Arakkoa unsere Händler und Boten erneut angreifen.", 26972);

-- 9987 - Die Arakkoa hindern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9987 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9987, "deDE", "Gut gemacht, $N. Wir haben schon genug Sorgen, wir können uns nicht erlauben, dass die Arakkoa unsere Händler und Boten erneut angreifen.", 26972);

-- 9990 - Untersuchung von Tuurem
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9990 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9990, "deDE", "Welche Neuigkeiten bringt Ihr, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9990 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9990, "deDE", "Astrale? Waren nach Tuurem? Fremdartige Bauteile? Und ein Blutelf, der den letzten Kasten zum Posten der Feuerschwingen bringen wollte?$B$BWas soll das alles bedeuten?! Was hat das mit dem Schicksal der Druiden im Cenariusdickicht zu tun?$B$BIch glaube, wir sollten einmal einen Blick in den Kasten werfen.", 26972);

-- 9992 - Olembasamen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9992 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9992, "deDE", "Ich habe eine Samenkornsammlung angefangen, aber ich werde Hilfe brauchen, bis ich genügend zusammen habe, um sie nach Sturmwind zu schicken.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9992 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9992, "deDE", "Vielen Dank für diese Samenkörner. Ich habe schon fast genügend zusammen, um eine erste Ladung zurückzuschicken!", 26972);

-- 9993 - Olembaöl
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9993 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9993, "deDE", "Habt Ihr ein paar Samenkörner für mich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9993 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9993, "deDE", "Das ist ein guter Anfang, aber wir werden noch mehr davon brauchen, wenn wir eine angemessene Menge Öl herstellen wollen!", 26972);

-- 9994 - Was ist das?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9994 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9994, "deDE", "Ihr seht besorgt aus. Was ist los, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9994 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9994, "deDE", "Oh nein! Das sind furchtbare Nachrichten! Ich kann nicht glauben, dass alle bis auf zwei unserer Cenariusfreunde tot sind!$B$BIn Ordnung, lasst mich die Teile einmal anschauen. Ich hoffe nur, dass sie nicht das sind, was ich vermute.$B$BJa, wie ich befürchtet habe. Ich glaube, das sind Bombenteile. Unsere Augen und Ohren in Shattrath haben uns informiert, dass einige Astrale verbotene Waren aus anderen Dimensionen, mit denen sie in Kontakt stehen, einführen.", 26972);

-- 9995 - Was ist das?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9995 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9995, "deDE", "Ihr seht besorgt aus. Was ist los, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9995 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9995, "deDE", "Oh nein! Das sind furchtbare Nachrichten! Ich kann nicht glauben, dass alle bis auf zwei unserer Cenariusfreunde tot sind!$B$BIn Ordnung, lasst mich die Teile einmal anschauen. Ich hoffe nur, dass sie nicht das sind, was ich vermute.", 26972);

-- 9996 - Angriff auf den Posten der Feuerschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9996 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9996, "deDE", "Das ist ein guter Anfang, aber nach dem, was Ihr auf dem Hof beobachtet habt und was mir meine Agenten berichten, haben wir weitaus dringendere Dinge zu tun.", 26972);

-- 9997 - Angriff auf den Posten der Feuerschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9997 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9997, "deDE", "Das ist ein guter Anfang, aber nach dem, was Ihr auf dem Hof beobachtet habt und was mir meine Agenten berichten, haben wir weitaus dringendere Dinge zu tun.", 26972);

-- 9998 - Widerspenstige Nachbarn
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9998 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9998, "deDE", "<Die Hochelfe nickt.>$B$BEs ist ein guter Anfang, aber Bertelm hatte Recht, Euch zu mir zu schicken. Ich habe eine Entdeckung gemacht, die die Anwesenheit der Höllenorcs hier erklären könnte.", 26972);

-- 10000 - Unangenehme Gesellschaft
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10000 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10000, "deDE", "Um die Höllenorcs aufzuhalten müssen wir schon mehr tun, als ihre Arbeiter zu töten. Ich habe eine Entdeckung gemacht, die vielleicht erklären kann, warum sie hier sind, und die mich in meiner Überzeugung bestätigt, dass wir schnell handeln müssen.", 26972);

-- 10002 - Vermittler der Feuerschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10002 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10002, "deDE", "<Theloria nickt Euch zu.>$B$BGut gemacht. Dadurch haben wir uns ein wenig Zeit verschafft. Die Blutelfen werden sich fragen, was ihrer Freundin zugestoßen ist. Hoffentlich wissen wir bis dahin mehr über ihre Pläne.", 26972);

-- 10003 - Vermittler der Feuerschwingen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10003 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10003, "deDE", "<Kaide nickt Euch zu.>$B$BGut gemacht. Dadurch haben wir uns ein wenig Zeit verschafft. Die Blutelfen werden sich fragen, was ihrer Freundin zugestoßen ist. Hoffentlich wissen wir bis dahin mehr über ihre Pläne.$B$BWenn die Zeit gekommen ist, werde ich Rokag von unseren Fortschritten berichten.", 26972);

-- 10005 - Erdbinder Tavgren Bescheid sagen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10005 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10005, "deDE", "Eine Bombe aus reinem Mana, die ganze Städte auslöschen kann! Aber warum? Warum würden die Blutelfen so etwas bauen und gegen uns verwenden? Das Cenariusdickicht sollte ein Ort des Friedens und der Erholung sein.$B$BWas auch immer der Grund sein mag, ich bin sicher, dass Aufseher Baumlas ihn kennt, doch ich habe keine Ahnung, wie ich ihn heilen kann. Vielleicht heilt sein Geist mit der Zeit von alleine?$B$BWie auch immer, ich danke Euch für Eure Hilfe. Ich kann nur hoffen, dass diese Tragödie sich niemals wiederholen wird.", 26972);

-- 10006 - Erdbinder Tavgren Bescheid sagen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10006 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10006, "deDE", "Eine Bombe aus reinem Mana, die ganze Städte auslöschen kann! Aber warum? Warum würden die Blutelfen so etwas bauen und gegen uns verwenden? Das Cenariusdickicht sollte ein Ort des Friedens und der Erholung sein.$B$BWas auch immer der Grund sein mag, ich bin sicher, dass Aufseher Baumlas ihn kennt, doch ich habe keine Ahnung, wie ich ihn heilen kann. Vielleicht heilt sein Geist mit der Zeit von alleine?$B$BWie auch immer, ich danke Euch für Eure Hilfe. Ich kann nur hoffen, dass diese Tragödie sich niemals wiederholen wird.", 26972);

-- 10007 - Die Reihen lichten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10007 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10007, "deDE", "Langsam sehen die Dinge besser aus. Wenn wir die Höllenorcs daran hindern können, ihre Kumpel hier zu unterstützen, können wir den Posten unter Kontrolle halten.", 26972);

-- 10008 - Was in Terokkar geschieht, bleibt in Terokkar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10008 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10008, "deDE", "Ich weiß, dass Ihr schon weit gereist seid, $N, aber manche Geschichten sollten das Land niemals verlassen, haben wir uns verstanden?", 26972);

-- 10012 - Höllenorcpläne
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10012 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10012, "deDE", "Was habt Ihr da, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10012 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10012, "deDE", "<Bertelm nimmt die Pläne und schaut sie an.>$B$BWenn Ihr mir diese Pläne nicht gebracht hättet, hätte ich behauptet, dass Ihr irre seid, aber hier steht es ganz deutlich. Die Höllenorcs sind nicht nur hier, um den Blutelfen zu dienen, sie haben sogar den Auftrag, uns abzulenken.$B$BDiese Pläne werfen mehr Fragen auf, als sie beantworten, aber nun können wir uns besser vorstellen, womit wir es hier zu tun haben.", 26972);

-- 10013 - Eine ungesehene Hand
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10013 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10013, "deDE", "Was habt Ihr da, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10013 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10013, "deDE", "<Rokag nimmt die Pläne und schaut sie an.>$B$BKaide hatte also Recht! Diese Höllenorcs führen etwas im Schilde. Ich hätte jedoch nie gedacht, dass sie mit den Blutelfen zusammenarbeiten.$B$BLaut diesen Plänen sollen die Höllenorcs uns beschäftigen... aber warum? Das sind beunruhigende Nachrichten, $N. Gut, dass Ihr mir die Pläne gleich gebracht habt.", 26972);

-- 10016 - Waldworgschwänze
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10016 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10016, "deDE", "Wie ich sehe habt Ihr die Gefahren des Waldes überlebt. Habt Ihr ein paar Schwänze für meinen Umhang?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10016 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10016, "deDE", "Ah, gut gemacht, Freund. Sie sind noch feiner, als ich gedacht habe. Sie werden sicher einen schönen Umhang abgeben.$B$B<Bertelm schaut zum Gasthaus hinüber.>$B$BJa, das wird ein schöner Umhang.", 26972);

-- 10018 - Gewänder des Wolfgeistes
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10018 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10018, "deDE", "Konntet Ihr alle Pelze, die ich benötige, finden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10018 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10018, "deDE", "Die Pelze sind perfekt, $N! Ich hätte keine besseren bekommen können.", 26972);

-- 10020 - Ein Heilmittel für Zahlia
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10020 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10020, "deDE", "Habt Ihr das Blut bekommen, $N? Ohne das Blut wird Zahlia ihrem Sohn nie wieder in die Augen schauen können.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10020 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10020, "deDE", "Vielen Dank, $N. Sich um die Notleidenden zu kümmern ist eine schwierige Aufgabe, aber sie wird auf ihre ganz eigene Weise belohnt.", 26972);

-- 10021 - Das Licht wiederherstellen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10021 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10021, "deDE", "Ihr habt meinen Dank, $N. Wir sind die Hüter des Lichts und können unsere Pflichten nicht vernachlässigen. Nicht einmal in den schwersten Zeiten.", 26972);

-- 10022 - Der schwer zu fassende Eisenkiefer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10022 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10022, "deDE", "Hat der alte Eisenkiefer Euch übers Ohr gehauen? Oder konntet Ihr den alten Gesellen überlisten?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10022 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10022, "deDE", "Ich verneige mich vor Eurem Geschick, $N. Ihr habt Euch als herausragender $C bewiesen.$B$BIch werde Eure Hilfe bei der Herstellung dieses Umhangs nie vergessen. Er ist ein einzigartiges Gewand, das ich voller Stolz tragen werde.", 26972);

-- 10023 - Patriarch Eisenkiefer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10023 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10023, "deDE", "Der Geist wartet, $N. Habt Ihr den Pelz des Patriarchen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10023 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10023, "deDE", "Der Pelz ist noch vortrefflicher, als ich erhofft hatte! Das ist ein gutes Zeichen, $N, und die Geister werden Euch wegen Eurem Beitrag zu dieser Zeremonie wohlgesinnt sein.$B$BIch habe Euch aus dem übrigen Pelz einen Helm gemacht, $N. Er zeichnet Euch als mächtigen Jäger und Verbündeter des großen Wolfgeists der Wälder von Terokkar aus.", 26972);

-- 10024 - Voren'thals Visionen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10024 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10024, "deDE", "Habt Ihr die Basiliskenaugen für Voren'thals Elixier?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10024 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10024, "deDE", "Sie sind in tadellosem Zustand, $N. Macht weiter so, und die Seher werden bald zu Euren Freunden zählen.", 26972);

-- 10025 - Mehr Basiliskenaugen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10025 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10025, "deDE", "Ich danke Euch, $N. Voren'thals Visionen können vielleicht eines Tages das Schicksal unseres Volks entscheiden. Wir tun gut daran, dafür zu sorgen, dass seine Visionen so klar wie möglich sind.$B$B<Diese Quest kann wiederholt werden, bis Ihr den Ruf 'Neutral' erlangt habt.>", 26972);

-- 10026 - Magische Störungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10026 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10026, "deDE", "<Andarl wischt sich die Stirn mit dem Ärmel seiner Robe ab.>$B$BZum Glück. Ich habe schon befürchtet, dass die Biester die restlichen Waldbewohner vertrieben haben.", 26972);

-- 10027 - Magische Störungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10027 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10027, "deDE", "Keb'ezil ist sehr erleichtert, dass Ihr Euch um das kleine Problem gekümmert habt, nicht wahr Keb?$B$B<Der Wichtel ignoriert seinen Meister und scheint beleidigt zu sein.>$B$BIhr müsst ihm seine schlechten Manieren nachsehen. Ihr wisst ja, wie Dämonen sind...", 26972);

-- 10028 - Gefäße der Macht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10028 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10028, "deDE", "Konntet Ihr ein paar unbeschädigte Gefäße finden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10028 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10028, "deDE", "Ich hoffe, dass dies nicht die einzigen Gefäße in der Stadt sind. Es ist ein guter Anfang, aber ich schätze, wir werden noch viel mehr davon brauchen.", 26972);

-- 10030 - Die Knochen zurückholen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10030 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10030, "deDE", "Was ist das? Wer seid Ihr?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10030 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10030, "deDE", "Super, genau das, was ich brauche... noch mehr Knochen.$B$B<Ramdor seufzt.>$B$BJa, ja, ich werde mich darum kümmern, dass die Gebeine dieser ehrenwerten Vorfahren ein anständiges Begräbnis bekommen, keine Sorge.$B$BWenn Ihr den Toten wirklich helfen wollt, habe ich noch eine andere Aufgabe für Euch.", 26972);

-- 10031 - Den Verirrten den Weg zeigen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10031 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10031, "deDE", "Ihr habt getan, was nötig war. Auch wenn es mich traurig macht, dass die Geister meiner Vorfahren zu schrecklichen Untoten verwandelt wurden, hat Euer Handeln sie endlich zur Ruhe gebracht.$B$BVielen Dank, dass Ihr sie befreit habt, $N. Bitte nehmt dieses bescheidene Zeichen meiner Hochachtung für Euch und Eure Selbstlosigkeit an.", 26972);

-- 10033 - AUFRUF: Tötet die Knochenpeitscher!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10033 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10033, "deDE", "Ja, ich bin mir sicher, dass Ihr all die Knochenpeitscher getötet habt. Ist ja auch klar, weil der Hauptmann auf dem Anschlag einen Beweis gefordert hat.$B$B<Taela schaut Euch sarkastisch an.>$B$BIch nehme Euch beim Wort. Ich bin mir nicht sicher, wen ich so geärgert habe, dass ich zu diesem Dienst verdonnert wurde, aber vielen Dank für Eure Mühe für die Allianz. Hier habt Ihr eine Entschädigung für Euren Aufwand.", 26972);

-- 10034 - AUFRUF: Tötet die Knochenpeitscher!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10034 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10034, "deDE", "Ihr müsst viele von diesen Knochenpeitschern getötet haben! Gut, ich hasse sie! Seit mich einer von ihnen gebissen hat, habe ich dauernd Ohnmachtsanfälle.$B$BWisst Ihr, wie peinlich das ist? Hier, nehmt dies als Dank, dass Ihr meine Rache vollstreckt habt.", 26972);

-- 10035 - Torgos!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10035 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10035, "deDE", "Habt Ihr die Feder? Muss ich Euch für Eure waghalsige Kühnheit belohnen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10035 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10035, "deDE", "Ich bin beeindruckt, $C. Torgos war eines der hartgesottensten Wesen, das ich auf dieser Seite von Nagrand kenne.$B$BNun, ich denke, Ihr habt Euch etwas aus dem Schatz von Allerias Feste verdient. Sucht Euch etwas aus!", 26972);

-- 10036 - Torgos!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10036 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10036, "deDE", "Habt Ihr ihn getötet? Ist Torgos tot?$B$BHabt Ihr den Beweis?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10036 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10036, "deDE", "Ich danke Euch, $N. Ihr habt meine Rache ausgeübt, und wie versprochen werde ich Euch belohnen.$B$BSucht Euch hiervon etwas aus und benutzt es weise!", 26972);

-- 10037 - Ich würd' lieber angeln
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10037 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10037, "deDE", "<Seth zieht Euch am Mantel.>$B$BHabt Ihr die Aale? Hä? Hä?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10037 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10037, "deDE", "Danke! Ich kann mich nicht erinnern, wann ich das letzte Mal Aal gegessen habe.$B$BWie soll ich sie bloß kochen?", 26972);

-- 10038 - Sprecht mit Gefreiter Wöch
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10038 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10038, "deDE", "Es wird auch langsam Zeit, dass Ihr kommt. Ich habe diesen Bericht schon vor über einer Woche zur Allerias Feste geschickt!$B$BBürokratie!", 26972);

-- 10039 - Sprecht mit Späherin Neftis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10039 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10039, "deDE", "Es wird auch langsam Zeit, dass Ihr kommt. Ich habe diesen Bericht schon vor über einer Woche zur Steinbrecherfeste geschickt!$B$BBlutelfen und ihre Bürokratie!", 26972);

-- 10040 - Wer sind sie?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10040 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10040, "deDE", "Gut, Ihr seid endlich zurück! Was habt Ihr herausgefunden? Wer sind sie?", 26972);

-- 10041 - Wer sind sie?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10041 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10041, "deDE", "Gut, Ihr seid endlich zurück! Was habt Ihr herausgefunden? Wer sind sie?", 26972);

-- 10042 - Tötet den Schattenrat!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10042 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10042, "deDE", "Das sind schlechte Nachrichten! Aber ich habe die richtige Wahl getroffen, als ich Euch geschickt habe, um Wöch zu helfen. Das Letzte, was wir brauchen können, ist, dass der Schattenrat einen starken Posten genau vor unserer Haustür errichtet.$B$B$N, als Anerkennung für Eure Taten in Grangol'var erlaube ich Euch hiermit, Euch eine dieser wundervollen Belohnungen auszusuchen.", 26972);

-- 10043 - Tötet den Schattenrat!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10043 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10043, "deDE", "Das sind schlechte Nachrichten! Aber ich habe die richtige Wahl getroffen, als ich Euch geschickt habe, um Neftis zu helfen. Das Letzte, was wir brauchen können, ist, dass der Schattenrat einen starken Posten genau vor unserer Haustür errichtet.$B$B$N, Ihr habt Euch etwas Nettes verdient. Sucht Euch etwas aus.", 26972);

-- 10051 - Ausbruch aus dem Posten der Feuerschwingen!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10051 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10051, "deDE", "Isla Sternenmähne ist gerade gegangen, aber sie hat mir einen vollständigen Bericht über die Vorkommnisse im Posten der Feuerschwingen gegeben. Verständlich, dass sie über die Geschehnisse beim Cenariusdickicht sehr bestürzt ist. Garstige Blutelfen!$B$BSie hat mir gesagt, dass Ihr die entscheidende Rolle bei ihrer Rettung gespielt habt, damit wir diese Informationen erhalten. Allerias Feste steht tief in Eurer Schuld.$B$BBitte, nehmt im Namen aller dieses Geschenk an.", 26972);

-- 10052 - Ausbruch aus dem Posten der Feuerschwingen!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10052 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10052, "deDE", "Isla Sternenmähne ist gerade gegangen, aber sie hat mir einen vollständigen Bericht über die Vorkommnisse im Posten der Feuerschwingen gegeben. Verständlich, dass sie über die Geschehnisse beim Cenariusdickicht sehr bestürzt ist.$B$BSie hat mir gesagt, dass Ihr die entscheidende Rolle bei ihrer Rettung gespielt habt, damit wir diese Informationen erhalten. Die Steinbrecherfeste steht tief in Eurer Schuld.$B$BBitte, nehmt im Namen aller dieses Geschenk an.", 26972);

-- 10091 - Seeleninstrumente
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10091 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10091, "deDE", "Ja? Was kann ich für Euch tun, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10091 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10091, "deDE", "To'gun hat mir bereits seinen Bericht abgeliefert. Er hätte Euch unterstützen sollen!$B$BIch habe ihn zurückgeschickt, um Grik'tha zu helfen. Ich finde, die beiden sind ein schönes Paar.$B$BDies sind also die Seeleninstrumente, mit denen der Schattenrat seine Beschwörungskraft erhöht? Ich finde, sie sehen gefährlich aus. Vielleicht können die Seher sie brauchen?$B$BHier, nehmt einen davon als Belohnung für Euren Kampf gegen den Schattenrat im Labyrinth.", 26972);

-- 10094 - Der Kodex des Blutes
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10094 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10094, "deDE", "Während Ihr den magiegeladenen Folianten öffnet, überkommt Euch ein Gefühl des Schreckens.$B$BIrgendetwas ist hier eindeutig falsch!$B$BIhr lest weiter, aber was Ihr lest scheint unglaublich zu sein!", 26972);

-- 10095 - In das Herz des Labyrinths
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10095 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10095, "deDE", "Murmur ist fast ausgebrochen?! Sie haben das Biest zwei Jahre sicher im Inneren verwahrt... Ich frage mich, was sie wohl falsch gemacht haben, dass sie nach all der Zeit die Kontrolle darüber verlieren.$B$BWas auch immer es sein mag, Micp, Ihr habt uns alle gerettet! Mir wird schwindelig, wenn ich daran denke, was Shattrath und dem Rest der Scherbenwelt zugestoßen wäre, wenn das Ding sich hätte befreien können!.$B$BIch bin so froh, dass Ihr die Sache in die Hand genommen und die Bedrohung durch den Schattenrat in Auchindoun beseitigt habt. Wie können wir Euch je dafür belohnen?", 26972);

-- 10097 - Bruder gegen Bruder
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10097 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10097, "deDE", "Habt Ihr sie gefunden, $N? War sie immer noch in den Hallen gefangen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10097 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10097, "deDE", "Ich kann Euch nicht genug danken, $N. Zu wissen, dass Lakka frei ist, bedeutet, dass ich endlich all meine Bande zu den Sethekk abwerfen kann.$B$BEin Teil von mir wird mir Syths Tod niemals verzeihen, aber es musste getan werden. Ich werde die Todesriten für ihn vollziehen. Vielleicht kann sein Geist zur Ruhe kommen, wenn er für die Irreführung unseres Volkes gebüßt hat.", 26972);

-- 10098 - Terokks Erbe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10098 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10098, "deDE", "Die Relikte von Terokk sind schon viel zu lange aus Skettis fort. Konntet Ihr sie von den Sethekk zurückholen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10098 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10098, "deDE", "Vielleicht wird mir meine Rolle bei den Verbrechen der Sethekk niemals vergeben werden, aber ich möchte versuchen, meine Sünden zu büßen, indem ich die Relikte von Terokk meinen Volk zurückgebe.$B$BVielen Dank für Eure Hilfe dabei, $N. Ihr habt keine Ahnung, welch großartige Tat Ihr heute geleistet habt.", 26972);

-- 10104 - Sorgen um Tuurem
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10104 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10104, "deDE", "Ich fühle mich geschmeichelt, dass Euer Freund von den Zerschlagenen mich für einen Gelehrten für Relikte seines Volkes hält, aber um ehrlich zu sein habe ich seit meiner Ankunft nicht viel Gelegenheit gehabt, sie zu studieren. Das war sicherlich meine Absicht, aber als ich hier ankam musste ich feststellen, dass es andere Dinge gibt, um die ich mich dringend kümmern muss.", 26972);

-- 10105 - Nachrichten für Rakoria
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10105 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10105, "deDE", "Ich hatte gehofft, seine Leute würden den Außenposten früher fertigstellen, aber sein Geld kostet es ja schließlich nicht. Immerhin geht es voran.", 26972);

-- 10112 - Ein persönlicher Gefallen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10112 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10112, "deDE", "Hmm, wird mein Gedächtnis schon besser?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10112 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10112, "deDE", "Ja, ich glaube, es wird alles deutlicher.$B$BUnd ich glaube, dass Euer Eifer in dieser Angelegenheit mit mehr als nur den Informationen, die Ihr sucht, belohnt werden sollte.", 26972);

-- 10164 - Alles wird gut
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10164 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10164, "deDE", "Ihr habt es geschafft, $N! Die Geister sind frei!$B$BAuch wenn ich keinen weltlichen Körper habe, kann ich Euch trotzdem mit Gegenständen aus der Geisterwelt belohnen. Benutzt sie mit Vorsicht, da diese Gegenstände oft unberechenbar sind und Ihrem Träger großen Schaden zufügen können.", 26972);

-- 10165 - Die Konkurrenz untergraben
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10165 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10165, "deDE", "Ich teile nicht gerne.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10165 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10165, "deDE", "Und wieder ein Konkurrent weniger... Ihr leistet gute Arbeit für ein Wesen aus Fleisch und Blut, $R. Wenn Ihr je im Nethersturm sein solltet, sucht mich auf. Ich wohne in der Sturmsäule.", 26972);

-- 10177 - Ärger in Auchindoun
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10177 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10177, "deDE", "Es wird langsam Zeit, dass Ihr kommt.$B$BMehlisah hat schon vor Tagen gesagt, dass sie Hilfe schicken würde. Und wir kämpfen hier schließlich schon eine ganze Weile!", 26972);

-- 10178 - Findet Spion To'gun
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10178 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10178, "deDE", "Was? Grik'tha hat Euch nach mir geschickt?$B$BIch weiß nicht, ob ich mich geehrt fühlen oder sie eine Närrin schimpfen soll!$B$BKönntet Ihr mir vielleicht aus diesem Käfig raushelfen? Es ist ein bisschen eng hier.", 26972);

-- 10180 - Kann es einfach nicht lassen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10180 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10180, "deDE", "Ich hätte wissen sollen, dass er nach mir schicken würde. Er hat versucht mir auszureden, in die Sethekkhallen zurückzukehren, aber ich könnte nicht damit leben, wenn Lakka etwas zustoßen würde.", 26972);

-- 10201 - Der Moment der Wahrheit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10201 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10201, "deDE", "<Ihr berichtet Rakoria die Testergebnisse und sie fängt an, schallend zu lachen.>", 26972);

-- 10210 - A'dal
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10210 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10210, "deDE", "<Das Licht, das Eure Sinne erfüllt hat, als Ihr Euch A'dal nähertet, wird noch stärker, als Ihr ihn ansprecht. Melodische Klänge ertönen in Eurem Kopf.$B$BIhr seid hier sicher.>", 26972);

-- 10211 - Stadt des Lichts
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10211 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10211, "deDE", "Die Geschichten der Lebewesen sind kurz, $N. Die Geschichten der Städte dauern Jahre.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10211 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10211, "deDE", "Ich hoffe, Ihr habt etwas über Shattrath erfahren, $N. Lasst es einfach auf Euch wirken.", 26972);

-- 10216 - Sicherheit geht vor
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10216 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10216, "deDE", "<Ihr schließt die Augen und drückt einen Knopf.>", 26972);

-- 10218 - Jemandes Arbeit zahlt sich aus
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10218 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10218, "deDE", "Da dies Morphalius' Idee war, habe ich ihm seinen alten Job zurückgegeben. Gut gemacht, kleines Fleischwesen. Wirklich gut!$B$BDenkt daran, wenn Ihr je auf der Suche nach Arbeit und im Nethersturm seid, sucht mich in der Sturmsäule auf.", 26972);

-- 10227 - Ich sehe tote Draenei
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10227 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10227, "deDE", "Das Kind hat Recht. Ich war einst ein \"Totenpriester\".$B$B<Ramdor zuckt zusammen.>$B$BWas für ein abstoßender Titel. Innen findet Ihr die Überbleibsel meines Ordens. Sie sind natürlich alle verrückt! Wahnsinnig! Ich denke, ich habe mich sehr hervorgehoben, da ich der letzte von ihnen mit gesundem Menschenverstand war. Natürlich wurde ich wegen meines Glaubens exkommuniziert.$B$BWas, sagtet Ihr, glaube ich noch gleich?", 26972);

-- 10228 - Ezekiel
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10228 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10228, "deDE", "Buch der Toten? Nie davon gehört... Worum geht es überhaupt? Wer hat Euch geschickt?", 26972);

-- 10231 - Welches Buch? Ich sehe kein Buch.
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10231 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10231, "deDE", "Ok, Ok! Tut uns nicht weh. Wir hatten das Buch, aber wir haben es verkauft...", 26972);

-- 10251 - Der große Plan des Meisters?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10251 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10251, "deDE", "Die Zeichen waren deutlich, aber ich war blind.$B$BDer eiserne Griff der Legion wird von Tag zu Tag stärker. Sogar hier...$B$BIch wusste es...$B$Bwusste, dass mein Junge mit den Dämonen kommunizierte...$B$BSie haben ihm Macht angeboten und ihm dann einen Vorgeschmack dieser Macht gegeben. Mehr war nicht nötig...$B$BDas Buch ist fort. Levixus hat es genommen...$B$BNur ich und sein dunkler Meister kennen seine Pläne.$B$BFremder, ich weiß nicht, ob Ihr jemals im Leben das Richtige getan habt, aber Ihr müsst eines wissen: der Junge muss aufgehalten werden.", 26972);

-- 10252 - Vision der Toten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10252 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10252, "deDE", "Levixus' Armee wächst mit jeder weiteren Sekunde in ihrer Größe und Stärke. Ihr müsst Euch beeilen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10252 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10252, "deDE", "Fremder... ich war nicht ganz aufrichtig zu Euch. Wenn Ihr diesen Trank zu Euch nehmt, werdet Ihr die Welt der Geister für alle Zeit sehen können. Diese Tinktur ist Teil des Initiierungsrituals für alle Totenpriester von Auchindoun. Viele werden wahnsinnig, wenn der Effekt eintritt. Die Toten sehen zu können ist... schockierend. <Nitrin hält Euch den Trank an die Lippen.> Wollt Ihr es tun?", 26972);

-- 10253 - Levixus der Seelenrufer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10253 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10253, "deDE", "Wer seid Ihr und was wolt Ihr? Oh... IHR seid es.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10253 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10253, "deDE", "Wenn der alte Draenei Euch aufgetragen hat, das Buch zu zerstören, warum habt Ihr es dann nicht getan?$B$B<Ramdor starrt Euch an.> Ach, was soll's. Ihr seid vielleicht gierig, aber ehrlich.$B$BIch allerdings... Ich habe gelogen, um an das Buch zu kommen. Ich habe nicht die leiseste Ahnung, wo diese armen, verirrten Seelen ihren Schatz aufbewahren, und wenn ich es wüsste, würde ich es Euch nicht sagen. Aber ich habe trotzdem etwas für Euch. Ihr habt heute etwas Gutes getan. Vielleicht sogar etwas Großartiges... Ihr solltet belohnt werden.$B$BÜbrigens, willkommen im Club.$B$B<Ramdor zeigt auf die Geister.>", 26972);

-- 10416 - Bündelung der Macht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10416 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10416, "deDE", "Habt Ihr schon einen arkanen Folianten besorgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10416 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10416, "deDE", "Wie versprochen, $N. Die Gesamtheit der ureigenen Macht des Buches, gepackt in eine einzelne Rune.", 26972);

-- 10419 - Arkane Folianten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10419 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10419, "deDE", "Habt Ihr noch mehr arkane Folianten besorgt, $N? ", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10419 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10419, "deDE", "Die Macht in diesem Folianten ist enorm. Und doch kann er von jemandem mit klarem Verstand in eine einzelne Rune verwandelt werden.", 26972);

-- 10420 - Ein reinigendes Licht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10420 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10420, "deDE", "Habt Ihr schon ein paar teuflische Waffen besorgt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10420 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10420, "deDE", "Schaut zu, wie die verderbten Materialien sich auflösen. Schaut zu, wie sich Metall in Staub verwandelt.$B$BDas Licht reinigt alles, und nur die reinsten Überreste bleiben.", 26972);

-- 10421 - Teuflische Waffen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10421 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10421, "deDE", "Die teuflischen Materialien wurden aus dieser Welt entfernt. Nur das Licht bleibt.", 26972);

-- 10444 - Meldung bei Allerias Posten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10444 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10444, "deDE", "Bombenteile. Dann war mein Verdacht also berechtigt. Ich hätte mir gewünscht, dass ich falsch liege.$B$BOk, wir haben also eine grausame Aufgabe vor uns.", 26972);

-- 10446 - Der finale Code
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10446 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10446, "deDE", "IHR HABT ES GESCHAFFT! IHR HABT ALLERIAS FESTE GERETTET!!$B$BJetzt, da ihre Streitkräfte dezimiert sind, ihr Anführer tot und die Manabombe zerstört ist, können wir alle etwas aufatmen.$B$BNie zuvor habe ich solche Selbstlosigkeit, solchen Heldenmut gesehen! Bitte, nehmt dies in unser aller Namen an!", 26972);

-- 10447 - Der finale Code
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10447 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10447, "deDE", "IHR HABT ES GESCHAFFT! IHR HABT DIE STEINBRECHERFESTE GERETTET!!$B$BJetzt, da ihre Streitkräfte dezimiert sind, ihr Anführer tot und die Manabombe zerstört ist, können wir alle etwas aufatmen.$B$BNie zuvor habe ich solche Selbstlosigkeit, solchen Heldenmut gesehen! Bitte, nehmt dies in unser aller Namen an!", 26972);

-- 10448 - Meldung beim Steinbrecherlager
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10448 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10448, "deDE", "Bombenteile. Dann war mein Verdacht also berechtigt. Ich hätte mir gewünscht, dass ich falsch liege.$B$BOk, wir haben also eine grausame Aufgabe vor uns.", 26972);

-- 10551 - Loyalität gegenüber den Aldor
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10551 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10551, "deDE", "Seid Ihr Euch Eurer Wahl sicher, $N? Die Aldor heißen Euch gerne als Verbündeten willkommen, aber die Seher werden Euch Eure Entscheidung nicht so leicht vergeben.", 26972);

-- 10552 - Loyalität gegenüber den Sehern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10552 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10552, "deDE", "Seid Ihr Euch Eurer Wahl sicher, $N? Die Seher heißen Euch gerne als Verbündeten willkommen, aber die Aldor werden Euch Eure Entscheidung nicht so leicht vergeben.", 26972);

-- 10553 - Voren'thal der Seher
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10553 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10553, "deDE", "Khadgar hat einen neuen Rekruten geschickt? Dann wollen wir Euch mal beschäftigen, $C.", 26972);

-- 10554 - Ishanah
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10554 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10554, "deDE", "Willkommen, $N. Ich bin froh, dass Ihr Euch entschieden habt, unserer Sache beizustehen. Möge das Licht Euch stets beschützen.", 26972);

-- 10791 - Willkommen Wolfgeist!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10791 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10791, "deDE", "Die Verbindung mit dem Wolfgeist wiederherzustellen ist nur der Anfang meiner Reise, nicht das Ende.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10791 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10791, "deDE", "Es ist unglaublich! Ich bin zu dieser Reise aufgebrochen, ohne auch nur die leiseste Ahnung zu haben, ob der Wolfgeist auf unsere Anrufung hin kommen würde. Und nun fühlt es sich an, als wäre er nie fort gewesen. Vielleicht war er das auch nie, $N.$B$BVielleicht hat er darauf gewartet, dass die Orcs verstehen, was ihre Entscheidung bewirkt hat.", 26972);

-- 10839 - Dunkelstein des Skithverstecks
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10839 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10839, "deDE", "Die Dunkelheit umgibt uns. Was habt Ihr mir aus dem Skithversteck zu berichten?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10839 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10839, "deDE", "Ich habe bis hierher die Explosion hören können. Nicht mit meinen Ohren, sondern mit meinem Herzen.$B$BWenn die Berührung des gesegneten Naaru A'dal nicht ausreicht, um die Arakkoa zu erlösen, dann kann nichts auf der Welt das schaffen. Diejenigen, die ihre Seele nicht dem Licht ausgeliefert haben, sind nichts als Diener des Bösen.$B$BSie müssen vernichtet werden.", 26972);

-- 10840 - Das Grab des Lichts
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10840 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10840, "deDE", "Hier in der Wildnis der Scherbenwelt sind wir schwach. Nur wenige Helden verteidigen unsere Rechte, aber Ihr habt ihnen gezeigt, dass sie sich fürchten müssen, $C. Ich glaube nicht, dass die Astralen Euren starken Arm so schnell vergessen werden, $N.", 26972);

-- 10842 - Rachsüchtige Seelen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10842 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10842, "deDE", "Ich danke Euch im Namen der gequälten Seelen, die Ihr befreit habt, $R.", 26972);

-- 10847 - Die Augen von Skettis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10847 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10847, "deDE", "Ihr seid zurück, $C. Welche Neuigkeiten bringt Ihr?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10847 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10847, "deDE", "Euer Mut sollte belohnt werden. Die Wachen von Skettis rücken ihre Besitztümer nur ungern heraus.$B$BAber die Heldentaten der Vergangenheit sind nun nicht von Belang. Wir sollten uns lieber darum kümmern, dass dieser Heldenmut auch in der Zukunft weiter herrscht, denn Terokks Blick richtet sich gen Süden.$B$BDiese Augen sehen alles.", 26972);

-- 10848 - Das untote Böse des Rhazeverstecks
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10848 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10848, "deDE", "Diese verderbten Geister haben es verdient zu sterben. Der Tod, den sie über alle anderen gebracht hätten, ist dafür Grund genug.$B$BEs besteht keine Hoffnung, dass wir die, die unter Terokks Einfluss stehen, erlösen können. Aber wir werden ihnen im Namen des Lichts ein Ende setzen.", 26972);

-- 10849 - Sucht Kirrik
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10849 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10849, "deDE", "Ihr seid weit gereist und bringt mir Nachrichten.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10849 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10849, "deDE", "Rilaks Geschichte ist grausam, Reisender. Wie Ihr am Zustand der Karawane sehen könnt, gibt es dieser Tage viel Leid und Düsterkeit in den Wäldern von Terokkar.", 26972);

-- 10852 - Vermisste Freunde
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10852 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10852, "deDE", "Ihr habt all meine Freunde gefunden! Jetzt habe ich wieder jemanden, der mit mir spielt. Vielen Dank, Herr $N.$B$BDa ich jetzt wieder andere Kinder zum Spielen habe, könnt Ihr ja eins meiner Spielzeuge haben. Dann habt Ihr auch etwas zum Spielen.", 26972);

-- 10861 - Präventivschlag gegen das Lithicversteck
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10861 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10861, "deDE", "Es ist eine grausame Aufgabe, Jungtiere zu quälen, und doch wäre es unverzeihlich, das wachsende Böse zu ignorieren. Ihr habt gute Arbeit geleistet. A'dals Gunst leuchtet auf Euch herab.", 26972);

-- 10862 - Auslieferung an die Horde
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10862 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10862, "deDE", "Euer Volk ist wütend, aber ich kann nicht viel dagegen tun. Einige von uns wurden von der Macht der Naaru berührt und für alle Zeiten verändert. Doch diejenigen von uns, die in der Wildnis leben, sind noch immer so, wie wir damals waren.", 26972);

-- 10863 - Geheimnisse der Arakkoa
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10863 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10863, "deDE", "Es war sehr weise von Euch, mich aufzusuchen. Es gibt vieles, was ich Euch zeigen kann.", 26972);

-- 10868 - Der Kriegspfad der Arakkoa
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10868 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10868, "deDE", "Gut gemacht, $C. Die Arakkoa haben gelernt, die Macht der Horde zu fürchten.", 26972);

-- 10869 - Die Herde ausdünnen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10869 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10869, "deDE", "Gut gemacht, $C. Die Arakkoa haben gelernt, die Macht der Allianz zu fürchten.", 26972);

-- 10873 - Bei Nacht verschleppt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10873 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10873, "deDE", "Ihr habt so viele gerettet. Ich habe nicht geglaubt, dass wir sie je wieder sehen würden. Wir können Euch nicht genug danken, $N.", 26972);

-- 10874 - Signalfeuer des Shalasverstecks
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10874 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10874, "deDE", "Wir haben gesehen, wie der verfluchte Rauch aufgestiegen ist. Ihr seid außergewöhnlich mutig, $C.", 26972);

-- 10877 - Das Schreckensrelikt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10877 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10877, "deDE", "Habt Ihr das Schreckensrelikt? Wir müssen es bekommen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10877 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10877, "deDE", "Es ist unglaublich, dass Ihr es geschafft habt. Das Schreckensrelikt ist viel mächtiger, als ich befürchtet hatte. Nur ein starker Held hätte die lange Rückreise mit so einem blasphemischen Gegenstand überlebt.", 26972);

-- 10878 - Bevor die Dunkelheit sich senkt
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10878 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10878, "deDE", "Vorerst kann ich erleichtert durchatmen, $N. Der Schattenrat wird sich bis auf weiteres zurückhalten.$B$BSie sind Mörder und Feiglinge. Eure Zurschaustellung von Mut wird sie einschüchtern.", 26972);

-- 10879 - Offensive aus Skettis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10879 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10879, "deDE", "Ich ziehe meinen Hut vor Euren Kampfkünsten, $C. Ihr habt Euch als wahrer Verteidiger des Lichts bewiesen. Möge A'dals Segen in Euren dunkelsten Stunden auf Euch ruhen.$B$BDoch seht zum fernen Horizont. Dunkle Wolken ziehen unheilvoll über Skettis herauf. Sicher plant Terokk schon seinen nächsten Schachzug. Für heute ist Shattrath gerettet. Doch wer weiß schon, welch Verderben der nächste Tag über uns alle bringen wird.", 26972);

-- 10880 - Befehle der Kabale
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10880 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10880, "deDE", "Wollt Ihr mir etwas zeigen, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10880 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10880, "deDE", "Ah, ja... dieser Text wurde in einer einfachen Form der Geheimschrift der Schatten geschrieben. Mein Wissen darüber ist nicht perfekt, aber es sollte ausreichen, um sie zu übersetzen.$B$BMan kann viel von den zwielichtigen Gestalten lernen, wenn man unter den Ausgestoßenen und Flüchtlingen im Unteren Viertel lebt.", 26972);

-- 10881 - Das Schattengrab
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10881 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10881, "deDE", "Habt Ihr die Relikte, $N? Wir können nicht zulassen, dass der Schattenrat sie für seine dunklen Zwecke einsetzt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10881 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10881, "deDE", "Das Licht hat mich vielleicht vergessen, aber ich habe das Licht nicht vergessen. Diese Relikte waren meinem Volk einst sehr heilig.$B$BDem Schattenrat zu erlauben, sie für Böses einzusetzen ist... undenkbar!", 26972);

-- 10887 - Flucht aus dem Grab
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10887 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10887, "deDE", "Ihr habt Akuno, meinen geschätzten Freund, errettet. Dafür stehe ich in Eurer Schuld, $N.", 26972);

-- 10889 - Rückkehr nach Shattrath
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10889 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10889, "deDE", "Die Wachen von Skettis werden langsam unruhig. Shattrath steckt in Schwierigkeiten. Wir werden Terokks Rache sicher eiskalt zu schmecken bekommen.$B$BStellt schnell eine Verteidigung auf die Beine! Sprecht mit Verteidiger Grashna und lasst ihn wissen, dass Ihr bereit seid, die Waffen gegen unsere Angreifer zu erheben!", 26972);

-- 10896 - Die verseuchten Beschützer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10896 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10896, "deDE", "Ihr habt viel zur Rettung der Wälder von Terokkar beigetragen, $N. Jetzt, da die schlimmsten Milbenkolonien vernichtet sind, können wir vielleicht dieses öde Land zurückerobern.", 26972);

-- 10898 - Wolkenschwinge
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10898 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10898, "deDE", "Also stand der arme Wolkenschwinge unter dem schrecklichen Fluch von Luanga dem Kerkermeister!$B$BWolkenschwinge hatte sich auf den Weg ins Shalasversteck gemacht, um zu versuchen, die anderen auf den Weg des Lichts zu bringen. Sie haben seine Versuche nicht gerade positiv aufgenommen, vor allem nicht, da sie direkt am Fuße von Skettis liegen.$B$BLuanga war einer von Terokks gefürchtetsten Dienern. Es war gut von Euch Wolkenschwinge zu befreien! Ich danke Euch.", 26972);

-- 10908 - Sprecht mit Rilak dem Erlösten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10908 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10908, "deDE", "So treffen wir uns also, $N. Bitte vergebt mir meine fehlenden Manieren, aber die Zeit drängt.", 26972);

-- 10913 - Ein unangemessenes Begräbnis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10913 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10913, "deDE", "Ich weiß, es ist eine grausame Aufgabe...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10913 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10913, "deDE", "<Kommandant Ra'vaj schüttelt traurig den Kopf.>$B$BEs ist nicht genug... Es ist einfach nicht genug.", 26972);

-- 10914 - Wir brauchen einen Helden!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10914 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10914, "deDE", "Ihr habt es geschafft, $N! Dank Euch konnten wir eine neue Entdeckung machen...", 26972);

-- 10915 - Der gefallene Exarch
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10915 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10915, "deDE", "Der Sieg ist unser! Diese Niederlage wird die Auchenai um mehrere Wochen zurückwerfen.", 26972);

-- 10917 - Die Pflicht eines Ausgestoßenen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10917 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10917, "deDE", "Seid Ihr mit den Federn zurück, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10917 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10917, "deDE", "<Vekax krächzt vor Freude, als Ihr ihm den Beweis für den Tod seiner Feinde übergebt.>$B$BJa, das wird Skettis zeigen, dass wir Ausgestoßenen ihre Bestrafung nicht lammfromm hinnehmen. Hier ist die Belohnung, die ich Euch versprochen habe. Ich kann Euch noch mehr geben, wenn Ihr mir weitere Federn bringt.", 26972);

-- 10918 - Mehr Federn
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10918 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10918, "deDE", "<Vekax krächzt vor Freude, als Ihr ihm den Beweis für den Tod seiner Feinde übergebt.>$B$BJa, das wird Skettis zeigen, dass wir Ausgestoßenen ihre Bestrafung nicht lammfromm hinnehmen. Hier ist die Belohnung, die ich Euch versprochen habe. Ich kann Euch noch mehr geben, wenn Ihr mir weitere Federn bringt.$B$B<Diese Quest kann wiederholt werden, bis Ihr einen wohlwollenden Ruf erlangt habt.>", 26972);

-- 10920 - Für die Gefallenen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10920 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10920, "deDE", "Ich habe die Geräusche Eures Kampfes bis hierher hören können, $C. Der Klang Eures Sieges hat mein Herz mit Hoffnung erfüllt. Wenn Ihr gegen eine solch gewaltige Überzahl bestehen könnt, kann auch ich vielleicht noch die Kraft finden, um meine Kameraden von diesem schrecklichen Ort fort zu führen.", 26972);

-- 10921 - Terokkarantula
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10921 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10921, "deDE", "Die Schreckensspinnen wurden geschlagen. Ihr habt so viele von ihnen getötet und nun auch noch ihre verderbte Mutter erlegt. Meine Vergiftungen sind zu schwer, als dass ich mich zurück in die Freiheit kämpfen könnte.$B$BBitte, nehmt etwas von meiner Ausrüstung. Ich werde mein Bündel erleichtern und Euch die nötigen Werkzeuge geben, um heil zum Basislager der Sha'tari zu gelangen.", 26972);

-- 10922 - In den Knochen wühlen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10922 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10922, "deDE", "Ein Knochenwurm! Fantastisch! Das könnte tatsächlich das erste Mal seit Beginn der Geschichtsschreibung sein, dass Letoll tatsächlich eine Entdeckung gemacht hat!", 26972);

-- 10923 - Das Böse rückt näher
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10923 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10923, "deDE", "Habt Ihr Teribus den Verfluchten aus den Himmeln Terokkars vertrieben?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10923 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10923, "deDE", "Terokkar wurde von einem schlimmen Übel befreit. Die Sha'tar stehen in Eurer Schuld.", 26972);

-- 10926 - Rückkehr zum Basislager der Sha'tari
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10926 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10926, "deDE", "Es ist gut zu wissen, dass einige unserer Krieger tapfer gegen die Schreckenswitwen gekämpft und überlebt haben. Wir werden sofort eine Rettungstruppe nach ihnen schicken.", 26972);

-- 10929 - Stampfen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10929 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10929, "deDE", "Wir glauben, dass das, was wir bei den Ausgrabungen gefunden haben, tatsächlich nur ein Wurmkind war!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10929 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10929, "deDE", "Sandgnome? Ja, klar... Die Wüste kann schon schlimme Dinge mit den Leuten anstellen.$B$BIch glaube, wir werden mit diesen Würmern hier einen wahren Durchbruch erzielen!", 26972);

-- 10930 - Der große Knochenwurm
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10930 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10930, "deDE", "Habt Ihr den großen Wurm gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10930 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10930, "deDE", "Erstaunlich! Schaut Euch das an! Dieses Wasauchimmer hat eine Art Staub in seiner Wiemanesauchnennenmag. Aber ich will Euch nicht mit meinen wissenschaftlichen Fachbegriffen langweilen. Ich habe den kleineren Würmern ein paar Zähne gezogen und daraus diese unglaublich scharfen Messer gemacht. Wollt Ihr eins?", 26972);

-- 10983 - Mog'dorg der Weise
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10983 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10983, "deDE", "Grok sagt, ich bin weise? Ich weiß ja nicht so recht.$B$BVielleicht liegt das daran, dass ich der Einzige meines Klans bin, der aufrichtig versucht uns vor der Vernichtung durch den Speerspießerklan zu retten. Und natürlich vor Gruul und seinen Söhnen, die sie unterstützen.$B$BIch hoffe, dass Ihr gekommen seid, um uns aus der unaufhaltsamen Verdammnis zu erretten, $C.", 26972);

-- 10984 - Sprecht mit dem Oger
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10984 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10984, "deDE", "Ihr helfen Grok? Grok brauchen Hilfe! Blutschläger brauchen Hilfe!", 26972);

-- 11004 - Schattenwelt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11004 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11004, "deDE", "Habt Ihr den Staub, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11004 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11004, "deDE", "Ich danke Euch, $N. Ich werde dem Kommandanten eine kleine Menge zukommen lassen... damit er seinen Willen bekommt. Ihr könnt den Rest behalten, vielleicht findet Ihr ja eine Verwendung dafür.", 26972);

-- 11005 - Die Geheimnisse der Krallenpriester
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11005 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11005, "deDE", "Ihr habt Euch mit Bravour geschlagen, $N. Durch den Verlust der Krallenpriester wurde dem Feind ein empfindlicher Schlag versetzt.", 26972);

-- 11006 - Mehr Schattenstaub
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11006 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11006, "deDE", "Der Kommandant scheint doch nicht aus einem Fieberwahn heraus gesprochen zu haben. Bringt mir mehr Staub und ich werde ein weiteres Elixier für Euch herstellen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11006 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11006, "deDE", "Ihr könnt mir auch weiterhin noch Staub bringen. Ich werde so viele Elixiere für Euch herstellen, wie Ihr benötigt.$B$BAuf Befehl des Kommandanten.", 26972);

-- 11008 - Feuer über Skettis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11008 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11008, "deDE", "Habt Ihr Euren Auftrag schon erledigt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11008 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11008, "deDE", "Ausgezeichnete Arbeit, $N! Das wird diesen Vogelwesen zeigen, wer die wahren Herren der Lüfte sind!", 26972);

-- 11021 - Ishaals Almanach
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11021 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11021, "deDE", "Ihr wollt mir etwas zeigen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11021 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11021, "deDE", "Was habt Ihr mir da gebracht? Die Sprache dieses Folianten ist mir fremd, $N... mein Blutverlust... muss meinen Geist verschleiert haben.", 26972);

-- 11024 - Ein Verbündeter im Unteren Viertel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11024 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11024, "deDE", "Ihr seid mit dem Geruch Skettis' behaftet! Was hat das zu bedeuten?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11024 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11024, "deDE", "Das kann nicht sein... dies war einst Eigentum eines Krallenpriesters. Wie ist es nur in Eure Hände gelangt?", 26972);

-- 11028 - Countdown des Schicksals
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11028 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11028, "deDE", "Die Arakkoa möchten Terokk zurück aus dem Jenseits der Zeit holen und Rilak... möchte einen Weg finden, um diesen Vorgang zu beschleunigen? Hat er denn seinen Verstand verloren?$B$B<Adaris legt sich geschwächt nieder.>$B$BIhr habt Eure Pflicht erfüllt, $N. Es ist an der Zeit, dass Ihr die Sache meinen Männern überlasst. Das ist jetzt eine rein militärische Angelegenheit.", 26972);

-- 11029 - Eine schäbige Verkleidung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11029 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11029, "deDE", "Das Buch, $N. Habt Ihr es?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11029 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11029, "deDE", "Ausgezeichnet! Das Buch beinhaltet eine Aufstellung der Nachfahren von Terokks alten Feinden. Es wurde vorhergesagt, dass ihr Tod Terokks Rückkehr ankündigen wird.", 26972);

-- 11038 - Unterstützung für Exarch Orelis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11038 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11038, "deDE", "So, Ihr seid also hierhergekommen, um unsere Untersuchungen über Kael'thas Pläne zu unterstützen? Eure Hilfe ist uns sehr willkommen. Der Nethersturm ist voll von Agenten der Blutelfen, die nichts unversucht lassen, um das Land ins Chaos zu stürzen.", 26972);

-- 11039 - Meldung bei Spionagemeister Thalodien
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11039 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11039, "deDE", "<Einen Augenblick lang huscht ein Ausdruck der Enttäuschung über das Gesicht des Spionagemeisters.>$B$BIch hatte wenigstens auf eine ganze Einsatzgruppe gehofft, aber wenn Voren'thal es für sinnvoll hielt, Euch alleine zu entsenden, werde ich meine Pläne entsprechend anpassen.", 26972);

-- 11045 - Zorus der Richter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11045 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11045, "deDE", "Fantei spricht die Wahrheit, Eure Hilfe kommt mir sehr gelegen.", 26972);

-- 11046 - Chefapothekerin Hildagard
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11046 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11046, "deDE", "Fantei hat ein gutes Gedächtnis. Es ist schon Monate her, dass ich in Shattrath war, um Zutaten zu kaufen. Allerdings hat er Recht. Ich könnte etwas Hilfe gebrauchen.", 26972);

-- 11056 - Hazziks Handel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11056 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11056, "deDE", "$N, Ihr seid zurück! Ich dachte schon, Ihr hättet mich im Stich gelassen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11056 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11056, "deDE", "Ausgezeichnet, $N. Ihr werdet sehen, dass ich mein Wort halte.", 26972);

-- 11072 - Feindesblut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11072 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11072, "deDE", "Habt Ihr Eure Mission erfüllt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11072 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11072, "deDE", "Hervorragend! Hier, nehmt dies. Ich habe dieses Bündel aus den Gegenständen erstellt, die Ihr mir gebracht habt. Damit werdet Ihr Terokk beschwören können.$B$BSeid auf der Hut, $N. Er ist der mächtigste Arakkoa aller Zeiten. Unterschätzt ihn nicht!", 26972);

-- 11073 - Terokks Fall
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11073 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11073, "deDE", "Ihr habt uns alle sehr stolz gemacht, $N. Ich werde die Kunde von Euren Taten in Shattrath verbreiten. Die Himmelswache steht für immer in Eurer Schuld.", 26972);

-- 11074 - Zeichen der Nachfahren
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11074 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11074, "deDE", "Ich benötige einen Gegenstand von jedem der Nachfahren von Terokks ärgsten Feinden. Nur dann können wir Terokk beschwören.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11074 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11074, "deDE", "Hervorragend! Hier, nehmt dies. Ich habe dieses Bündel aus den Gegenständen erstellt, die Ihr mir gebracht habt. Damit werdet Ihr Terokk beschwören können.$B$BSeid auf der Hut, $N. Er ist der mächtigste Arakkoa aller Zeiten. Unterschätzt ihn nicht!", 26972);

-- 11093 - Hungrige Netherrochen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11093 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11093, "deDE", "Ihr seid also zurück! Hat sich der Rochen auch gut benommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11093 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11093, "deDE", "Vielen Dank $N, dass Ihr Euch um den Rochen gekümmert habt. Mit vollem Magen fliegen diese Burschen gleich viel besser. Schließlich sollen unsere Jungs nicht abgeschossen werden, nur weil ihre Netherrochen zum Fliegen zu schwach waren.", 26972);

-- 11096 - Bedrohung von oben
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11096 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11096, "deDE", "Gute Arbeit, Fliegerass! Ich habe das Gefühl, dass Ihr hier sehr gut hineinpasst.", 26972);

-- 11098 - Nach Skettis!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11098 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11098, "deDE", "Ihr habt etwas für mich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11098 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11098, "deDE", "Danke für den Nachschub, wir werden ihn zu verwenden wissen! Ein neuer Rekrut? Dann wollen wir doch mal sehen, aus welchem Holz Ihr geschnitzt seid!", 26972);

-- 11130 - Oh, es glitzert!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11130 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11130, "deDE", "<Budd beäugt die Notiz misstrauisch.>$B$BWas habt Ihr da, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11130 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11130, "deDE", "<Budd liest die Notiz.>$B$BAhh! $GEin Freund:Eine Freundin; von Gaunah? Willkommen!$B$BIhr kommt genau richtig, mein Freund. Wie es das Schicksal so will, habe ich gerade erst meine Kollegen verloren. Tragisch, wirklich, aber außergewöhnliche Belohnungen haben oft ihren Preis. Lasst uns nicht zu sehr ans Negative denken!$B$BIhr habt sicherlich schon von meinen zahlreichen Ausbeuten und Entdeckungen gehört. Nun, das war alles nichts im Vergleich zu dem hier! Ich sage es Euch, wir sind nahe dran, hier in Zul'Aman Geschichte zu schreiben. Ihr hattet das Glück, rechtzeitig zu kommen, um auf der untersten Ebene dabei zu sein!", 26972);

-- 11216 - Erzmagier Alturus
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11216 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11216, "deDE", "Danke, dass Ihr Euch die Zeit genommen habt, um uns hier zur Hilfe zu kommen. Vor uns liegt eine Menge wichtiger Arbeit.", 26972);

-- 11372 - GESUCHT: Die Kopfschmuckfedern von Ikiss
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11372 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11372, "deDE", "Die Häuptlingszeremonie findet bald statt, beeilt Euch.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11372 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11372, "deDE", "Diese Federn werden dem Kopfschmuck des Häuptlings den letzten Schliff geben. Ihr habt Euch Eure Bezahlung redlich verdient, $C.$B$BKommt morgen wieder und ich werde einen weiteren Auftrag für Euch bereithalten.", 26972);

-- 11383 - Gesucht: Fürsten der Zeitenrisse
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11383 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11383, "deDE", "Anscheinend habt Ihr Euren Weg in die Vergangenheit und wieder zurück gefunden. Eure Fähigkeiten als $C sind bemerkenswert. Die Belohnung gehört Euch.$B$BKehrt morgen zu mir zurück, wenn die Winde Mah'duun ihren Willen offenbart haben.", 26972);

-- 11481 - Krise am Sonnenbrunnen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11481 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11481, "deDE", "Noch ein Soldat aus Shattrath? Welch willkommener Anblick!$B$BWünschte es gäbe mehr wie Euch, aber wir müssen mit dem auskommen, was uns gegeben ist. Was auch immer dort draußen geschieht, es wird nicht darauf warten, dass wir vorbereitet sind.$B$BSeht Euch ein wenig um, $C. Es gibt viel zu erledigen. Packt mit an und tut Euren Teil.", 26972);

-- 11482 - Pflicht ruft
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11482 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11482, "deDE", "Willkommen auf dem Sonnenbrunnenplateau, Anfänger der... Wie bitte? Oh - Anhänger der Seher, natürlich. Habe ich das nicht gesagt?$B$BNun, gut, kommen wir gleich zur Sache. Hinter diesen Mauern geht es ernsthaft zur Sache, und das ist für unsere beiden Völker von großem Interesse. Und da keiner von uns über genügend Streitkräfte verfügt, um die Sache alleine anzugehen, werden wir ZUSAMMENARBEITEN. Verstanden?$B$BNa dann fangen wir doch einmal an.", 26972);

-- 11497 - Fliegen lernen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11497 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11497, "deDE", "So, mein Junge Nutral schickte dich vorbei, stimmts? Guter Mann... Ich muss daran denken ihm einen auszugeben, für all die Geschäfte die er mir vermittelte.$B$BWenn es darum geht wie man richtig und ordnungsgemäß fliegen lernt, bist du hier genau richtig. Niemand fliegt feiner als wir Wildhammer und die, die wir trainieren. Gegen eine Gebühr, die nicht gerade gering ausfällt, werde ich dir lehren wie man durch die Lüfte steigt!$B$BUnd wenn du fertig bist, vergiss nicht mit Brunn dort drüben über den Kauf einer dieser schönen Greifen zu sprechen!", 26972);

-- 11498 - Fliegen lernen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11498 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11498, "deDE", "Blut und Donner, Nutral hat mir schon wieder einen Boden-Grunzer geschickt! Sehr gut... für einen Draenei.$B$B<Olrokk spuckt auf den Boden neben Euch.>$B$BWenn Ihr wissen wollt, wie man richtig fliegt, dann seid Ihr am richtigen Ort. Für einen großen Sack Gold bringe ich Euch genug bei, um nicht unehrenhaft in den Tod zu stürzen.$B$BUnd wenn Ihr fertig seid, dann vergesst nicht, Dama Wildmähne einen unserer Windreiter abzukaufen!", 26972);

-- 11505 - Geister von Auchindoun
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11505 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11505, "deDE", "Die Geister sind ruhelos, $N. Habt Ihr Eure Aufgabe vollbracht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11505 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11505, "deDE", "Die Geister sind ihrer Ruhe einen Schritt näher. Es ist gut, ihre Gunst zu erlangen - besonders dann, wenn so nahe an ihrer Ruhestätte Krieg geführt wird.", 26972);

-- 11506 - Geister von Auchindoun
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11506 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11506, "deDE", "Die Geister von Auchindoun sind um uns. Werden sie uns eine Wohltat zuteilwerden lassen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11506 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11506, "deDE", "Die Geister sind einen Schritt näher daran, ihre Ruhe zu finden, und haben uns deswegen ihre Gunst verliehen.$B$BEs muss eine Demütigung für unseren Feind sein, dass sich seine eigenen Urahnen gegen ihn wenden - auch, wenn es nur vorübergehend ist.", 26972);

-- 11665 - Krokilisken in der Stadt
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11665 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11665, "deDE", "Schon Krokis in den Abwasserkanälen gefangen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11665 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11665, "deDE", "Was für eine miese kleine Kreatur! Ich bin mir sicher, dass der Rokk irgendwas Leckeres aus ihr machen wird.$B$BIch mach natürlich nur Spaß.$B$B<Der alte Barlo zwinkert neckisch.>", 26972);

-- 11666 - Köderbanditen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11666 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11666, "deDE", "Wie fischt sich's denn heute, mein Junge?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11666 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11666, "deDE", "Nun sieh mal einer an... Ihr habt einen Großen gefangen! Dieser alte Mann wird heute Abend gut essen.", 26972);

-- 11667 - Der Eine, der entkam
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11667 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11667, "deDE", "Sagt mir, dass Ihr ihn gefangen habt. Bitte sagt mir, dass Ihr den Mistkarpfen gefangen habt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11667 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11667, "deDE", "Da ist er! Diese Narbe würde ich immer wiedererkennen.$B$BAber um ganz ehrlich zu sein, habe ich ihn mir... größer vorgestellt. Tja - denke, dass ich ihn freilassen und es an einem anderen Tag noch einmal versuchen werde.", 26972);

-- 11668 - Garnelenfangen ist nicht einfach
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11668 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11668, "deDE", "Was haben wir denn heute gefangen, mein Junge?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11668 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11668, "deDE", "Ihr könnt mit Haken und Messer gut umgehen. Reicht mir die süßen Leckerbissen und ich werde Euch davon kosten lassen.", 26972);

-- 11669 - Teufelsblutfilet
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11669 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11669, "deDE", "Der Teufelsblut ist ein Wunder der Evolution. Er kann in allen Gewässern und sogar Lava überleben. Fischer sind seine einzigen natürlichen Feinde.$B$BGlück beim Beutefang gehabt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11669 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11669, "deDE", "Das ist der größte und hässlichste Fisch, den ich je gesehen habe. Ich kann mir gar nicht vorstellen, was Ihr als Köder benutzt habt.$B$BLegt das Biest einfach auf den Boden und ich werde mich darum kümmern, sobald ich mir sicher sein kann, dass es tot ist.", 26972);

-- 11877 - Angriffspläne des Sonnenzorns
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11877 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11877, "deDE", "Seid Ihr mit den Plänen zurückgekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11877 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11877, "deDE", "<Lord Torvos nimmt die Pläne entgegen und sieht sie sich an.>$B$BIhr habt der Offensive einen großen Dienst erwiesen, $N. Wir sollten uns jedoch keine Ruhe gönnen. Unsere Feinde werden in Zukunft sicherlich noch mehr Unheil über uns bringen.", 26972);

-- 11880 - Die Multiphasen-Vermessung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 11880 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (11880, "deDE", "Konntet Ihr die Messungen durchführen? Der Gnom wird mich wieder anbrüllen, wenn ich die kostbaren Daten nicht herbekomme.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11880 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11880, "deDE", "Danke für Eure Hilfe. Ihr wisst gar nicht, wie es ist, wenn man sich mit 'Doktor' Waffelfritte dort drüben auseinandersetzen muss. Wenn er nicht gerade damit beschäftigt ist, meinen Fortschritt zu 'überprüfen', verhökert er gerade eines seiner Geräte - die übrigens alle Erfindungen für militärische Zwecke sind.", 26972);

-- 11885 - Feindesblut
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11885 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11885, "deDE", "Hervorragend! Hier, nehmt dies. Ich habe dieses Bündel aus den Gegenständen erstellt, die Ihr mir gebracht habt. Damit werdet Ihr Terokk beschwören können.$B$BSeid auf der Hut, $N. Er ist der mächtigste Arakkoa aller Zeiten. Unterschätzt ihn nicht!", 26972);
