-- Zangarmarsh -- Zangarmarschen
-- RequestItems, OfferReward -- master, 3.3.5

-- 9776 - Die Oreborzuflucht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9776 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9776, "deDE", "Wenn Anachoret Ahuurn Euch als Freund betrachtet, kann ich Euch vielleicht vertrauen. Bitte vergebt mir meinen Argwohn, $R, doch oft rettet nur dieser mein Volk vor dem Tod. Seid in unserer Zuflucht willkommen. Vielleicht wird so unser gegenseitiges Vertrauen wachsen können.", 26972);

-- 9777 - Fulgorsporen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9777 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9777, "deDE", "So wie es aussieht brauchen wir sehr bald neue Sporen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9777 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9777, "deDE", "Diese Sporen sind sehr gut und sollten uns für einen Weile reichen. Vielen Dank für Eure Hilfe bei der Aufstockung unserer Vorräte, $N.", 26972);

-- 9780 - Aalfilets von Umbrafenn
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9780 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9780, "deDE", "Habt Ihr schon Fische für unsere Vorräte besorgt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9780 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9780, "deDE", "Danke für Eure Hilfe, $N. Euer Großmut wird nicht vergessen werden.", 26972);

-- 9781 - Zu viele Mäuler zu stopfen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9781 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9781, "deDE", "Gut gemacht. Das sollte den Bedarf an Nahrung in der Gegend für die nahe Zukunft etwas mindern, auch wenn wir immer noch nach neuen Nahrungsquellen suchen sollten. Fisch und Pilze reichen aus, aber etwas Abwechslung sollte nicht unterschätzt werden.", 26972);

-- 9782 - Das Todesmoor
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9782 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9782, "deDE", "Konntet Ihr eine Probe der Erde des Todesmoors bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9782 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9782, "deDE", "Hmm... der Boden ist nicht ausgelaugt, das kann also nicht der Grund für das Problem sein, wie ich zuerst vermutet habe. Wo liegt die Verbindung? Warum stirbt alles so plötzlich?", 26972);

-- 9783 - Eine unnatürliche Dürre
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9783 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9783, "deDE", "Danke für Eure Hilfe bei dieser schweren Aufgabe, $N. Unsere Arbeit im Todesmoor ist noch nicht beendet, aber nun können wir uns darauf konzentrieren, das Gleichgewicht in der Gegend wiederherzustellen.", 26972);

-- 9784 - Pflanzenteile identifizieren
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9784 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9784, "deDE", "Ich könnte noch mehr Pflanzenteile brauchen. Jetzt, da die Seen ihr Wasser verlieren, befürchte ich, dass die fremden Arten zunehmen werden. Ich brauche aber mehr Beweise, um meine Theorie zu untermauern.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9784 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9784, "deDE", "Ausgezeichnet. Wenn Ihr noch mehr Pflanzenteile findet, bringt sie zu mir.$B$B<Diese Quest kann wiederholt werden, bis Ihr den Ruf Wohlwollend' erlangt habt.>", 26972);

-- 9786 - Die Ruinen von Boha'mu
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9786 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9786, "deDE", "Die Verirrten des Wildfennstamms haben sich also in den Ruinen eingenistet? Das ist verblüffend. Sie müssen sich an Ihr Erbe erinnern und die Wichtigkeit dieses Ortes erkennen können. Wir müssen mehr darüber erfahren, $N. Vielleicht ist in diesem Tempel der Schlüssel zur Erlösung der Verirrten und zur Wiedervereinigung der verschiedenen Arten der Draenei versteckt.", 26972);

-- 9787 - Götzen des Wildfennstamms
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9787 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9787, "deDE", "Habt Ihr die Götzen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9787 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9787, "deDE", "Diese sollten mehr als ausreichen, $N. Sie scheinen auf Vögel fixiert zu sein, was merkwürdig ist, da es in den Zangarmarschen keine einheimischen Vogelarten gibt. Was könnte das wohl bedeuten?$B$BSind sie vielleicht auf die Arakkoa getroffen? Für ein schamanistisches Volk mögen sie vielleicht wie der Inbegriff eines mächtigen Vogelgeists wirken.", 26972);

-- 9790 - Lichtdurchlässige Flügel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9790 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9790, "deDE", "Habt Ihr schon ein paar lichtdurchlässige Flügel sammeln können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9790 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9790, "deDE", "Habt Dank, $N.$B$BZumindest müsst Ihr sie nicht säubern. Das ist der schlimmste Teil der Arbeit, aber wenn ich damit fertig bin, werdet Ihr niemals erkennen, dass sie mal zu einem riesigen Insekt gehört haben.", 26972);

-- 9791 - Bedrohliche Marschenfänge
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9791 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9791, "deDE", "Danke für Eure Hilfe bei der Auslöschung einiger Marschenfangreißer, $N. Wenn sie über Intelligenz verfügen würden, würden sie vielleicht erkennen, dass es am besten ist, zu leben und leben zu lassen.$B$BGroße, überwucherte Käfer mit Intelligenz. Ich frage mich, wie das wohl wäre...", 26972);

-- 9792 - Eine Botschaft für Telaar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9792 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9792, "deDE", "Ikuti ist wie ein Bruder für mich. Seine Freunde sind auch meine Freunde. Ihr seid hier willkommen, $N, und Ihr habt unseren Dank für die Hilfe, die Ihr meinem Volk geleistet habt.", 26972);

-- 9801 - Die Reagenzien sammeln
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9801 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9801, "deDE", "Habt Ihr die Reagenzien schon?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9801 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9801, "deDE", "Diese Reagenzien eignen sich sehr gut. Bitte gebt mir einen Moment Zeit, um den Trank zu mischen.", 26972);

-- 9803 - Botschaft für den Wildfennstamm
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9803 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9803, "deDE", "Habt Ihr schon mit dem Ältesten von Wildfenn gesprochen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9803 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9803, "deDE", "Sie haben abgelehnt? Natürlich steht es ihnen frei, selbst zu wählen, aber ihre Entscheidung überrascht mich. Ich habe gedacht, dass alle Draenei, also auch die Zerschlagenen und Verirrten, sich daran erinnern würden, dass wir alle ein Volk sind.$B$BIch schätze er hat Recht damit, dass es töricht war zu versuchen, sie hereinzulegen, aber trotzdem, konnte er denn nicht sehen, dass wir in freundlicher Absicht gehandelt haben?", 26972);

-- 9827 - Siechendes Basidium
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9827 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9827, "deDE", "Was habt Ihr da, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9827 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9827, "deDE", "Das sieht aus wie das Basidium eines Sumpflords, aber ich habe noch nie zuvor eines in einem solchen Zustand gesehen. Ich habe gehört, dass die Riesen im Todesmoor angefangen haben dahin zu siechen, aber es ist schon viel weiter fortgeschritten, als ich befürchtet habe.$B$BDas Todesmoor war einst ein See wie die anderen in den Marschen, und er diente als Nährgrund für die Riesen. Jetzt, da sich das Wasser zurückzieht, scheint es, als könnten sich die Riesen nicht länger vermehren. Wenn das so weitergeht, sterben die Riesen noch aus.", 26972);

-- 9830 - Blutergift
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9830 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9830, "deDE", "Ich hoffe, ich kann die Vorzüge des Fennblutergifts Anachoret Ahuurn und den anderen in Telredor zeigen. Aber dafür werde ich meine Vorräte verdoppeln müssen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9830 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9830, "deDE", "Vielen Dank für das Gift, $N. Jetzt kann ich es den anderen vorführen ohne meine eigenen Vorräte anfassen zu müssen.", 26972);

-- 9833 - Nachrichtenwege
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9833 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9833, "deDE", "Das sind wundervolle Nachrichten. Der Weg ist zwar immer noch nicht sicher, aber unsere Boten sind schlau und erfinderisch.", 26972);

-- 9834 - Natürliche Rüstung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9834 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9834, "deDE", "Hat $N die Bälge für Maktu?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9834 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9834, "deDE", "Das sind gute Bälge, findet Maktu. Sie werden sehr gute Rüstung geben.$B$BWer weiß? Vielleicht sind es genug, damit Maktu ein paar Rüstungen für die Draenei machen kann.", 26972);

-- 9835 - Vordringen der Ango'rosh
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9835 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9835, "deDE", "Für den Moment ist die Bedrohung durch die Ango'rosh gebannt, aber ich bin mir sicher, dass sie nicht so leicht aufgeben werden. Ich habe vieles von meinem früheren Leben als Draenei vergessen, aber die Hartnäckigkeit der Oger hat sich in mein Gedächtnis eingebrannt.", 26972);

-- 9839 - Oberanführer Schmetterfaust
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9839 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9839, "deDE", "Endlich! Vielen Dank für die Hilfe bei der Sicherung unserer Stellung hier in der Oreborzuflucht. Ich werde den Kurenai in Telaar in Nagrand von Euren Taten berichten. Es werden sich noch viele Gelegenheiten bieten, in denen unsere Völker zusammenarbeiten können.", 26972);

-- 9848 - Geheimnisse des Dolchfennstamms
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9848 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9848, "deDE", "War Eure Suche in Dolchfenn nach den Informationen, die ich zur Lösung des Gifträtsels benötige, erfolgreich?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9848 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9848, "deDE", "<Timothy blättert das Handbuch durch.>$B$BSie benutzen Zottelkappe als Grundlage für das Gift? Nein, das kann nicht richtig sein. Zottelkappe ist nicht giftig.$B$BZottelkappe in ein Gift zu mischen ist so sinnvoll, wie einem Schurken zwei Streitkolben in die Hand zu drücken. Sicher, man kann das zwar tun, aber das entspricht nicht dem Wesen Eurer Berufung! Ich kann das einfach nicht verstehen...$B$B<Timothy räuspert sich.>$B$BNun ja, danke dass Ihr mir das hier besorgt habt. Ich werde das Gift ausprobieren, sobald die Zeit es mir erlaubt.", 26972);

-- 9896 - Schwarzsichels Fluch
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9896 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9896, "deDE", "Habt Ihr den Stachel bekommen können? Denkt daran, wenn er beschädigt ist, ist er wertlos für mich!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9896 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9896, "deDE", "Ich kann Euch gar nicht genug danken, Kumpel. Ich werde es genießen...", 26972);

-- 9901 - Offene Rechnungen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9901 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9901, "deDE", "Gut gemacht, $N. Ich glaube, wir beide lassen ein ganzes Team von Ausgrabungsleitern neben uns blass aussehen. Wenn ich zurück in Eisenschmiede bin, werde ich mir meine Einsatzorte sicher selbst aussuchen dürfen.", 26972);

-- 9902 - Der Schrecken des Sumpflichtsees
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9902 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9902, "deDE", "Habt Dank, $N. Vielleicht werden diese Marschen mit der Hilfe der Draenei eines Tages frei von Naga sein. Ich kann mir gar nicht vorstellen, wie schlimm es sein muss, ihnen dienen zu müssen.$B$BEr spricht nicht oft darüber, aber Maktu war einst ihr Sklave.", 26972);

-- 9905 - Maktus Rache
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9905 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9905, "deDE", "<Maktu nickt anerkennend.>$B$BMaktu ist dankbar für Eure Hilfe. Maktus Stolz ist befriedigt. Er wird nicht mehr so unvorsichtig sein.", 26972);

-- 9769 - Mode kann man nicht erklären
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9769 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9769, "deDE", "Was ist los? Hat Euch jemand die Flügel gestutzt?$B$B<Magasha kichert über ihren Witz.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9769 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9769, "deDE", "Die sind fein, $N. Hier ist Eure Bezahlung.$B$BNe, nicht mein Fall, aber ich hab ja auch keine Ahnung von Mode.$B$BEs ist das Geld, was zählt.", 26972);

-- 9770 - Bedrohliche Marschenfänge
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9770 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9770, "deDE", "Schon satt?$B$B<Reavij lacht.>$B$BEs gibt einen Grund warum unsere Besucher nicht lange bleiben.$B$BWenn ich eine Wahl hätte, würde ich einen angenehmeren Ort für den Posten auswählen. Aber ich ziehe die Marschfänge immer noch Denjais Launen vor!", 26972);

-- 9771 - Auf der Suche nach Späher Jyoba
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9771 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9771, "deDE", "Diese in Mitleidenschaft gezogene Leiche passt genau zu Zurais Beschreibung. Was auch immer den Späher getötet haben mag, muss ihn überrascht haben, da er seine Waffen nicht gezogen hatte und Tintenflecken auf dem Boden zu sehen sind.", 26972);

-- 9772 - Jyobas Bericht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9772 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9772, "deDE", "Ihr seid zurück, aber Jyoba ist nicht bei Euch. Was ist mit ihm passiert?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9772 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9772, "deDE", "<Zurai nimmt den Bericht von Euch und schaut ihn sich an.>$B$BViele von diesen Informationen sind uns bereits bekannt. Alles in dieser Gegend scheint ausgetrocknet oder am verwelken zu sein, aber hier steht etwas neues.$B$BEr sagt, die Fungusgiganten sind von dem Wassermangel wahnsinnig geworden. Eurer Beschreibung nach muss es einer von ihnen gewesen sein, der ihn umgebracht hat.$B$BIch werde meinen Männer anweisen, die Gegend zu meiden. Wir können uns keine weiteren Verluste erlauben.", 26972);

-- 9773 - Keine Pilze mehr!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9773 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9773, "deDE", "Bitte sagt mir nicht, dass Ihr mit leeren Händen zurückgekommen seid, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9773 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9773, "deDE", "Endlich, eine Abwechslung zu den Pilzen! Wenn Ihr nicht nach Fisch riechen würdet, würde ich Euch umarmen.$B$BWollen wir mal schauen, wie neidisch die anderen werden, wenn sie meinen gebratenen Fisch riechen!", 26972);

-- 9774 - Dicke Hydraschuppen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9774 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9774, "deDE", "Ich sehe, dass Ihr grinst. Ja, meine Rüstung wird etwas merkwürdig aussehen, bis ich das ganze alte Metall ersetzt habe, aber besser so als ungeschützt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9774 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9774, "deDE", "Danke, $N. Jedes noch so kleine bisschen hilft.$B$BEs ist immer noch viel zu tun, aber mal ehrlich, was soll ich sonst zwischen den Patrouillen machen?", 26972);

-- 9775 - Bericht an Schattenjäger Denjai
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9775 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9775, "deDE", "Ihr seht nicht aus wie einer meiner Männer. Was wollt Ihr, $R?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9775 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9775, "deDE", "Warum habt Ihr nicht gleich gesagt, dass Ihr einen Bericht von Zurai habt? Ich warte schon auf Nachricht von ihm.$B$BIch habe ihn nach Osten geschickt, damit er dort einen Posten baut, nicht um auf den Händen zu sitzen. Wollen wir mal sehen, was er zu sagen hat.", 26972);

-- 9814 - Berstkappenpilze, Mann!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9814 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9814, "deDE", "Habt Ihr die Pilze, Mann?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9814 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9814, "deDE", "Die sind klasse, Mann!$B$BIch sag' Euch was. Weil Ihr so nett wart und mir mit den Pilzen geholfen habt, dürft Ihr beim Spaß dabei sein!", 26972);

-- 9816 - Habt Ihr so was schon mal gesehen?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9816 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9816, "deDE", "Ausgezeichnete Arbeit, Mann! Ich hoffe, sie hatten Spaß damit!", 26972);

-- 9820 - GESUCHT: Boss Grog'ak
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9820 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9820, "deDE", "Was habt Ihr da, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9820 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9820, "deDE", "Gut gemacht, $N. Die Anwesenheit dieser Oger so nah an unserem Außenposten hat mich ein wenig beunruhigt. Es scheint, als kämen sie seit einiger Zeit die Berge im Norden herunter.", 26972);

-- 9822 - Drohender Angriff
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9822 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9822, "deDE", "Habt Ihr einen Beweis für die Pläne der Oger gefunden?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9822 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9822, "deDE", "<Schattenjäger Denjai untersucht die Pläne.>$B$BIch wusste es! Der Gestank eines Ogers hat immer etwas Bedrohliches an sich. Jetzt, da wir einen Beweis für ihren Plan haben, müssen wir ihnen zuvorkommen.", 26972);

-- 9823 - Sie oder wir
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9823 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9823, "deDE", "Unser Sieg über die Ango'rosh muss gefeiert werden, $N. Ich frage mich, wie lange es wohl dauert, bis diese Grobiane einen neuen, blutrünstigen Anführer gefunden haben.$B$BGanz gleich, wir werden auf sie vorbereitet sein!", 26972);

-- 9828 - Siechendes Basidium
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9828 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9828, "deDE", "Was habt Ihr da, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9828 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9828, "deDE", "Das sieht aus wie das Basidium eines Sumpflords, aber ich habe noch nie zuvor eines in einem solchen Zustand gesehen. Ich habe gehört, dass die Riesen im Todesmoor angefangen haben dahin zu siechen, aber es ist schon viel weiter fortgeschritten, als ich befürchtet habe.$B$BDas Todesmoor war einst ein See wie kein anderer in den Marschen, und er diente als Nährgrund für die Riesen. Jetzt, da sich das Wasser zurückzieht, scheint es, als könnten sich die Riesen nicht länger vermehren. Wenn das so weitergeht, sterben die Riesen noch aus.", 26972);

-- 9841 - Tückische Mücken
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9841 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9841, "deDE", "Dachte ich es mir, Ich kann den Unterschied schon deutlich hören. Dank Euch werde ich endlich wieder arbeiten können. Falls Ihr jemals Handwerkswaren benötigen solltet, denkt an den alten Gambarinka!", 26972);

-- 9842 - Die schärfsten Klingen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9842 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9842, "deDE", "Habt Ihr ein paar Marschenfangklingen auftreiben können?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9842 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9842, "deDE", "Die sollten mir für eine Weile genügen! Ich glaube, ein paar andere sind schon darauf aufmerksam geworden. Ich hatte schon ein paar Angebote, mir die Klingen abzukaufen. Sie nebenbei zu verkaufen könnte vielleicht ein einträglicheres Geschäft als meine herkömmlichen Waren bieten.", 26972);

-- 9845 - Anglerunglück
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9845 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9845, "deDE", "Ich kann es gar nicht erwarten endlich wieder angeln zu gehen. Jetzt werde ich endlich mit echten Fischen in meinem Eimer ins Dorf zurückkehren können, und Gambarinka wird sich nicht mehr über mich lustig machen können!", 26972);

-- 9846 - Geister der Wildfenn
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9846 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9846, "deDE", "Habt Ihr die Totems schon gesammelt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9846 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9846, "deDE", "Hmm... Es scheint, als wäre die eine Hälfte mit Bildern von Schlangengeistern, die andere mit Bildern von Vogelgeistern verziert. Kein Dunkelspeertroll mit Selbstachtung würde jemals Vögel verehren. Ihre Geister sind schwach, launisch und besser bei den Schamanen der Amani aufgehoben.$B$BAber die Schlange, $N, die Schlange hat beträchtliche Kräfte und ist daher der Geist, dem ich meine Studien widmen werde.", 26972);

-- 9847 - Ein verbündeter Geist?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9847 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9847, "deDE", "Konntet Ihr den Geist von Wildfenn rufen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9847 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9847, "deDE", "<Ihr berichtet Seherin Janidi, was passiert ist, als Ihr das Totem benutzt habt.>$B$BDer Geist hat euch angegriffen? Er muss diesen Verirrten wohl mehr zugetan sein, als ich dachte. Es gibt keine Möglichkeit, ihn mir gefügig zu machen, ohne immensen Aufwand zu betreiben. Ich muss mich wohl nach einer anderen Quelle der Macht in dieser elenden Welt umsehen.", 26972);

-- 9898 - Liebe ist ein großer Stachel
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9898 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9898, "deDE", "Ich werde Glück haben - ich fühle es.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9898 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9898, "deDE", "Fantastisch! Ich werde nie vergessen, dass Ihr mir geholfen habt, ihr Herz zu gewinnen. Ihr sollt der Ehrengast auf unserer Hochzeit sein!", 26972);

-- 9899 - Unerledigte Arbeit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9899 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9899, "deDE", "Wenigstens einer hier erfüllt seine Pflicht. Vielen Dank, dass Ihr Euch um diese Angelegenheit gekümmert habt, $N. Ich muss einmal mit Zurai über Reavij sprechen. Seine Tagträumereien müssen langsam ein Ende haben.", 26972);

-- 9903 - Der Größte von allen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9903 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9903, "deDE", "Ich bin mir sicher, der alte Knabe hat das Ende seiner Tage schon vorausgesehen. Bei all diesen Neuankömmlingen musste die alte Rangfolge sich einfach ändern. Es ist nur recht, dass sein Geist nun zu Ruhe kommen kann.", 26972);

-- 9904 - Jagd auf Terrorklaue
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9904 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9904, "deDE", "Endlich! Wahrscheinlich hat jeder Angler eine Geschichte über \"den, der mir entkommen ist\". Aber ich habe noch keinen Fisch getroffen, den man nicht auf die eine oder andere Art bezwingen konnte.", 26972);

-- 9697 - Behüterin Leesa'oh
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9697 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9697, "deDE", "Oh, gut... endlich Unterstützung! Es gibt einfach so viel zu tun, und ich muss hierbleiben, um alles zu organisieren.$B$BIch hoffe Ihr seid bereit, Euch die Hände schmutzig zu machen.", 26972);

-- 9701 - Sporlinge beobachten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9701 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9701, "deDE", "Was?! Die Sumpflords des Quaggkamms ESSEN die Sporenkapseln der Sporlinge? Das ist nicht gut!", 26972);

-- 9702 - Eine Frage der Fressgier
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9702 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9702, "deDE", "Stellt sicher, dass Ihr alle Beweise sorgfältig zusammentragt, $C! Wir fügen hier die Teile eines riesigen Puzzles zusammen. Ein Fehler von Euch könnte zu falschen Schlussfolgerungen führen.$B$BWo stünden wir dann mit unserem Verständnis für die Zangarmarschen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9702 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9702, "deDE", "Das habt Ihr gefunden? Das ist komisch. Diese vertrockneten Pilzüberreste sind ungewöhnlich und kommen mir irgendwie bekannt vor.$B$BIch muss kurz darüber nachdenken. Geht nicht weg!", 26972);

-- 9708 - Bekannter Pilz
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9708 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9708, "deDE", "Habt Ihr die Proben schon?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9708 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9708, "deDE", "Die Proben stimmen definitiv überein. Und die Anwesenheit der Oger und was sie dort tun erklärt alles. Jetzt verstehe ich, warum der Ort Prügelsumpf genannt wird.$B$BWir müssen etwas an dieser Situation ändern, aber was? Wir können nicht einfach alle Oger auslöschen, sie haben genauso viel Recht hier zu leben, wie alle anderen Lebewesen in den Marschen.", 26972);

-- 9709 - Die Pilze zurückstehlen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9709 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9709, "deDE", "Habt Ihr schon alle Pilze, um einen neuen Garten für die Sumpflords anzulegen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9709 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9709, "deDE", "Sie sind perfekt! Oh danke, $C!$B$BIhr wart so darauf bedacht, das natürliche Gefüge nicht aus dem Gleichgewicht zu bringen, und wir haben in so kurzer Zeit so viele Informationen sammeln können!$B$BJetzt wollen wir mal schauen, ob unser kleiner Plan, eine neue Nahrungsquelle für die Sumpflords zu schaffen, funktioniert.", 26972);

-- 9714 - Bringt mir ein weiteres Gebüsch!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9714 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9714, "deDE", "Wir können immer noch mehr Bluthibiskus von den Schlurfern, Sumpfriesen und Tiefenfledermäusen im Echsenkessel gebrauchen. Bringt sie mir in Bündeln zu je fünf, und ich werde Euch sehr dankbar sein.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9714 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9714, "deDE", "Das ist schon mal sehr gut, aber wir können immer noch mehr davon gebrauchen. Vielleicht geht Ihr ja bald mal wieder in den Tiefensumpf?", 26972);

-- 9715 - Bringt mir ein weiteres Gebüsch!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9715 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9715, "deDE", "Habt Ihr den Hibiskus, um den ich Euch gebeten habe?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9715 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9715, "deDE", "Das ist schon mal sehr gut, aber wir können immer noch mehr davon gebrauchen. Vielleicht geht Ihr ja bald mal wieder in den Tiefensumpf?", 26972);

-- 9716 - Anomalie am Umbrafennsee
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9716 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9716, "deDE", "Die Naga stecken dahinter! Aber warum? Euren Schilderungen zufolge sind die Dampfpumpen für das Sinken der Wasserspiegel in den Marschen verantwortlich.$B$BEgal - dies erklärt Ihre offensichtliche Feindlichkeit uns gegenüber. Lasst uns keine Zeit verschwenden, Ihr müsst eine weitere Aufgabe für uns erledigen.", 26972);

-- 9717 - Los geht´s!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9717 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9717, "deDE", "Der Tiefensumpf ist ein sehr gefährlicher Ort. Wenn Ihr euch scheut, dorthin zu gehen, würde ich Euch nicht als Feigling bezeichnen. Ich wäre allerdings auch alles andere als zufrieden, wenn Ihr mir nicht das brächtet, worum ich gebeten habe.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9717 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9717, "deDE", "<Der Sporling macht ein Geräusch, das fern an ein prustendes Lachen erinnert.>$B$BPerfekt! Die Moral der Fungusgiganten wird sicher ein Rekordtief erreichen, wenn sie sehen, was Ihr getan habt.$B$BEntweder das oder sie werden so erzürnt sein, dass sie uns bald wieder angreifen.$B$B<T'shu zuckt mit den Schultern.>", 26972);

-- 9718 - Der Flug der Krähe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9718 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9718, "deDE", "Seid gegrüßt, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9718 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9718, "deDE", "Es ist so, wie ich dachte. Die Naga haben Pumpstationen an allen größeren Seen in den Zangarmarschen errichtet.$B$BWenn die Marschen weiter existieren sollen, müssen sie aufgehalten werden.", 26972);

-- 9719 - Tötet die Mutter
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9719 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9719, "deDE", "Ihr seid zurück. Heißt das die Schattenmutter ist nicht mehr?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9719 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9719, "deDE", "Die Schattenmutter ist tot! Normalerweise schwelge ich ja nicht in solchen Gemetzeln, aber der Schmerz, den die große Mutter und ihre Brut über Jahrhunderte über mein Volk gebracht haben, ist unaussprechlich.$B$BEs ist schade, dass nun einer ihrer Nachkömmlinge sich verwandeln wird, um ihren Platz einzunehmen, aber das wird Zeit benötigen. So haben wir eine kleine Atempause, und müssen uns eine zeitlang nicht vor den Marschenläufern fürchten.", 26972);

-- 9720 - Das Gleichgewicht muss erhalten bleiben
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9720 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9720, "deDE", "Schon fertig, $C?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9720 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9720, "deDE", "Es ist also vollbracht. Die Marschen sind vorerst gerettet.$B$BGlaubt aber nicht, dass wir zum letzten Mal von den Naga gehört haben. Wir müssen unseren Feind im Auge behalten, während wir unsere Mission in der Scherbenwelt fortsetzen.", 26972);

-- 9724 - Warnung an den Zirkel des Cenarius
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9724 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9724, "deDE", "Das sind schlimme Nachrichten, die Ihr mir über die Naga in den Zangarmarschen bringt. Es war sehr klug von Ysiel, uns darüber zu informieren. Sie hat nicht vergessen, dass die Expedition nicht ohne die Unterstützung des Zirkels existieren kann.", 26972);

-- 9726 - Jetzt, da wir Freunde sind...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9726 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9726, "deDE", "<Gzun'tt nickt Euch zu.>$B$BWir sind sehr erfreut, dass Ihr unsere Freundschaft bestätigt habt, $N. Vielleicht denken die heidnischen Naga in Zukunft zweimal darüber nach, bevor sie uns belästigen, wenn wir so einen starken Verbündeten haben.", 26972);

-- 9727 - Jetzt, da wir immer noch Freunde sind...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9727 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9727, "deDE", "<Gzun'tt nickt Euch zu.>$B$BWir sind sehr erfreut, dass Ihr unsere Freundschaft erneut bestätigt habt, $N. Sicherlich werden die sinnlosen Angriffe auf unser Volk jetzt, da Ihr unseren Standpunkt mehrfach klar gemacht habt, aufhören.", 26972);

-- 9728 - Ein herzliches Willkommen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9728 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9728, "deDE", "Schön, Euch wiederzusehen, $N. Wie läuft die Jagd nach den Naga?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9728 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9728, "deDE", "Gut gemacht, $N. Beruhigt Eurer schlechtes Gewissen, falls Ihr eines haben solltet. Diese Naga sind böse Kreaturen - noch viel böser als die in Azeroth.", 26972);

-- 9729 - Fhwoor zerschmettern!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9729 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9729, "deDE", "Fhwoor ist ein guter Riese. Wir haben ihn vor einer Weile vor den Naga gerettet und seitdem ist er hier und hilft uns.$B$BWir können nur hoffen, dass die Naga den Hinweis verstehen. Wenn wir in der Lage sind, uns in ihr Dorf einzuschleichen und ihren wertvollsten Besitz zu rauben, können wir noch viel Schlimmeres tun. Vielleicht gehen sie jetzt zurück in ihren Kessel und lassen uns in Ruhe.", 26972);

-- 9730 - Anführer der Dunkelkämme
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9730 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9730, "deDE", "Ich mochte schon die Naga in Azeroth nicht, aber die hier mag ich noch viel weniger. Es ist eine Schande, dass unsere Mission nicht friedvoll verlaufen konnte, aber Ihr werdet mich niemals auch nur eine Träne für einen Naga vergießen sehen.$B$BHier ist Eure Belohnung, $N.", 26972);

-- 9731 - Kanalisationspläne
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9731 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9731, "deDE", "Welche Neuigkeiten bringt Ihr, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9731 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9731, "deDE", "Die Naga haben den Schlangensee in einen riesigen Wasserablauf für den Rest der Zangarmarschen verwandelt. Was haben sie wohl vor?$B$BEs war eine kluge Entscheidung, uns diese Neuigkeiten mitzuteilen, $N. Wir werden eine Gruppe losschicken, um den Ablauf, den Ihr gefunden habt, zu untersuchen. Bis dahin habe ich eine andere Aufgabe für Euch.", 26972);

-- 9732 - Rückkehr in die Marschen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9732 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9732, "deDE", "Euer Anblick ist mir sehr willkommen, $N. Die Lage in der Zuflucht des Cenarius hat sich verschlechtert, seit Ihr fortgegangen seid.", 26972);

-- 9738 - Bei der Arbeit verschollen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9738 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9738, "deDE", "Habt Ihr schon herausgefunden, was mit meinen Freunden passiert ist?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9738 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9738, "deDE", "Ich bin froh, dass einige meiner Freunde noch am Leben sind, aber es bricht mir das Herz zu hören, was den anderen widerfahren ist. Immerhin starben sie bei etwas, was sie mehr als alles andere im Leben liebten. Ich bin Euch auf ewig dankbar für Eure Hilfe, $N.$B$BBitte nehmt einen meiner Ringe als Zeichen meiner Dankbarkeit.", 26972);

-- 9739 - Die Misere der Sporlinge
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9739 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9739, "deDE", "Die Sporenbeutel! Habt Ihr sie?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9739 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9739, "deDE", "Ihr habt es geschafft! Ihr habt den Dank meines Volkes.$B$BIch hoffe Ihr versteht... daraus entstehen unsere Jungen. Wir können diese Biester sie nicht einfach fressen lassen!", 26972);

-- 9742 - Noch ein paar Sporensäcke
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9742 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9742, "deDE", "Habt Ihr noch mehr Sporensäcke gerettet, $R?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9742 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9742, "deDE", "Ja! Ihr habt noch mehr Sporensäcke gerettet.$B$BIhr seid anders als die anderen von außerhalb. Ich werde meinem Volk von Euren Taten erzählen!$B$B<Diese Quest kann wiederholt werden, bis Ihr einen freundlichen Ruf erlangt habt.>", 26972);

-- 9743 - Natürliche Feinde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9743 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9743, "deDE", "Wie geht es mit dem Töten der Sumpflords voran? Zeigt diesen Wüstlingen, dass sie besser nicht in Sporlingsgebiet kommen sollen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9743 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9743, "deDE", "Ihr seid heil zurück! Ich werde den anderen Sporlingen von Euch erzählen! $N, der Riesentöter!", 26972);

-- 9744 - Mehr Ranken!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9744 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9744, "deDE", "Ihr habt viele Riesen getötet, aber es sind immer noch viele übrig. Und sie greifen immer noch unsere Sporenbeutel an!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9744 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9744, "deDE", "Unglaublich! Es würde hunderte von Sporlingen brauchen, um so viele Riesen zu töten wie Ihr. Ich werde ganz bestimmt allen von Euren Heldentaten erzählen!$B$B<Diese Quest kann wiederholt werden, bis Ihr einen freundlichen Ruf erlangt habt.>", 26972);

-- 9747 - Der Umbrafennstamm
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9747 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9747, "deDE", "Danke, $N. Endlich werde ich nachts ruhig schlafen können. Wäre ich nicht so alt und schwach, würde ich mich selbst mit meinen Feinden auseinandersetzen.$B$BNehmt dieses Gold. Es ist nicht viel, aber Eure Freundlichkeit darf nicht unbelohnt bleiben.", 26972);

-- 9752 - Flucht aus Umbrafenn
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9752 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9752, "deDE", "Ihr habt einen meiner Druiden gerettet. Das könnten wir Euch niemals zurückzahlen, $N.$B$BIhr habt meinen Dank sowie den Dank der Expedition.", 26972);

-- 9763 - Das Versteck des Kriegsherren
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9763 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9763, "deDE", "Wo ist Kalithresh? Ist er schon tot, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9763 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9763, "deDE", "Unser größter Feind in der Gegend ist endlich tot. Ihr habt der Expedition einen sehr großen Gefallen getan, $N.$B$BWir stehen auf ewig in Eurer Schuld.", 26972);

-- 9778 - Aufseher Hamuht
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9778 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9778, "deDE", "Ysiel hat Euch geschickt? Natürlich habe ich für jemanden wie Euch Verwendung! Wir können immer ein paar Muskeln brauchen.", 26972);

-- 9784 - Pflanzenteile identifizieren
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9784 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9784, "deDE", "Ausgezeichnet. Wenn Ihr noch mehr Pflanzenteile findet, bringt sie zu mir.$B$B<Diese Quest kann wiederholt werden, bis Ihr einen wohlwollenden Ruf erlangt habt.>", 26972);

-- 9785 - Der Segen der Uralten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9785 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9785, "deDE", "Ihr seid zurück. Habt Ihr den Segen der Uralten erhalten?", 26972);

-- 9788 - Ein feuchter, düsterer Ort
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9788 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9788, "deDE", "Habt Ihr meine Habseligkeiten gefunden, $N? Die Höhle ist nicht weit von Umbrafenn entfernt, nahe an der Grenze zu Nagrand.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9788 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9788, "deDE", "Meine Sachen! Sie sind alle da!$B$BIch danke Euch, $N. Wie versprochen dürft Ihr Euch etwas von den Dingen aussuchen. Ich habe nicht viel anzubieten, aber mein Volk hat schon immer das Wenige, was wir hatten, geteilt.", 26972);

-- 9793 - Das Schicksal von Tuurem
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9793 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9793, "deDE", "Wie kann ich Euch helfen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9793 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9793, "deDE", "Hmm... Ich kann mich erinnern, dass unsere Späher von den Ruinen einer Draeneisiedlung in den nördlichen Ausläufern des Waldes berichtet haben. Ich weiß jedoch selbst nicht viel über die Ruinen, aber Ihr könnt gerne mit unseren Spähern sprechen.", 26972);

-- 9794 - Keine Zeit für Neugier
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9794 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9794, "deDE", "<Kialon schaut Euch misstraurisch an.>$B$BIch kenne Euch nicht, $R. Was wollt Ihr von mir?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9794 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9794, "deDE", "Ihr bringt mir also Timothys Antwort?$B$B<Kialon hält einen Moment inne, um den Brief zu lesen, und fängt an zu lachen.>$B$BEr hat alles unter Kontrolle, sagt er, braucht keine Hilfe. Ich hätte es wissen müssen!$B$BManche Leute ändern sich nie. Schaut, er hat sich sogar die Zeit genommen, meine Rechtschreibfehler zu korrigieren.$B$B<Kialon seufzt halbherzig.>$B$BIch hätte ihm den Brief nicht schicken sollen. Ich habe es vergessen. Der Spezialist hat die Situation immer unter Kontrolle. Immer.", 26972);

-- 9795 - Die Ogerbedrohung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9795 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9795, "deDE", "Denjai braucht Hilfe? Ich würde ihm gerne ein paar Leute schicken, aber wir sind hier selbst nur sehr dünn besiedelt. Wir haben hier oben unsere eigenen Probleme mit den Ogern.$B$BSobald ich kann werde ich ihm alle Informationen, die wir über diesen Ogerstamm und ihre Taktiken haben, zukommen lassen. Wenn er lang genug durchhält können wir die Grobiane vielleicht von zwei Seiten aus angreifen.", 26972);

-- 9797 - Verstärkung für Garadar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9797 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9797, "deDE", "<Auch wenn er sich Mühe gibt, es zu verheimlichen, macht sich Erleichterung auf Kroghans Gesicht breit.>$B$BEs wurde auch langsam Zeit, dass Ihr kommt! Sicher, Ihr seid keine Armee, aber jeder kräftiger Blutelf, der eine Waffe führen oder einen Zauber wirken kann, ist hier willkommen. Die Bevölkerung Garadars ist ein Teil der Horde und stolz, sein Blut für ihre Verteidigung vergießen zu dürfen.", 26972);

-- 9802 - Pflanzen der Zangarmarschen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9802 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9802, "deDE", "Habt Ihr ein paar Pflanzenteile gefunden, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9802 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9802, "deDE", "Das Abnehmen der natürlichen Arten ist ein Grund zur Sorge. Die Zunahme der eingewanderten Arten könnte mit der neuerlichen Störung des Ökosystems zusammenhängen. Ich habe jedoch noch zu wenig Anhaltspunkte, um Genaueres zu sagen.$B$B<Lauranna macht ein paar Notizen in ein Buch, als sie die Pflanzenteile untersucht.>$B$BNehmt ein paar davon, $N. Sie könnten vielleicht nützlich für Euch sein.$B$BBringt mir alle weiteren Pflanzenteile, die Ihr finden könnt. Ich werde sie in meiner Statistik auflisten.", 26972);

-- 9806 - Fruchtbare Sporen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9806 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9806, "deDE", "Ihr seid zurück, $N. Habt Ihr die fruchtbaren Sporen bekommen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9806 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9806, "deDE", "Diese Sporen sind perfekt, $N! Die Langstielpilze sind für den Wiederaufbau unseres Dorfs unerlässlich. Und seit den Angriffen der Sumpflords, die wir erdulden mussten, sind unsere Vorräte knapp!", 26972);

-- 9807 - Noch mehr fruchtbare Sporen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9807 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9807, "deDE", "Wir können immer noch mehr fruchtbare Sporen gebrauchen, $R. Langstielpilze sind unglaublich nützlich. Wir können sehr viel mit ihnen anstellen, wenn wir sie anbauen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9807 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9807, "deDE", "Eure Hilfe wird sehr geschätzt, $N. Ihr werdet uns doch weiterhin helfen, oder?", 26972);

-- 9808 - Glühkappenpilze
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9808 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9808, "deDE", "Habt Ihr ein paar Glühkappen gefunden, $N? Sie wachsen fast überall in den Marschen.$B$BIhr könnt sie schon von weitem leuchten sehen, wenn Ihr genau hinschaut.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9808 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9808, "deDE", "Die können wir prima bei den anderen Sporlingen gegen Essen und Vorräte eintauschen. Sporeggar dankt Euch, $N!", 26972);

-- 9817 - Anführerin der Blutschuppen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9817 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9817, "deDE", "Ich wette, die Blutschuppen überlegen es sich nun zweimal, bevor sie unsere Späher nochmals angreifen. Nehmt dies als Belohnung, $N. Ihr habt es Euch verdient.", 26972);

-- 9875 - Nicht katalogisierte Gattung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9875 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9875, "deDE", "Habt Ihr etwas, das Ihr mir zeigen möchtet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9875 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9875, "deDE", "Eine neue Gattung! Seid Ihr sicher?$B$B<Lauranna blättert die Notizen und Diagramme durch.>$B$BToll gemacht, $N. Wir werden sie unserer Liste hinzufügen. Was haltet Ihr von \"Violettblättriges $Nium\"? Ich finde, das ist ein klangvoller Name.", 26972);

-- 9876 - Fehlgeschlagene Operation
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9876 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9876, "deDE", "Cenarius sein Dank, dass Ihr hier seid. Wegen meiner Verletzungen konnte ich nicht nach draußen zurück, um Hilfe zu holen.", 26972);

-- 9894 - Schützt die Behüter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9894 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9894, "deDE", "Ihr habt meinen Dank, $N, und den der Behüter. Sie werden sich freuen zu hören, dass sie ihre Arbeit im Süden nun ohne Angst vor weiteren Angriffen fortsetzen können.", 26972);

-- 9895 - Aus dem Gleichgewicht geraten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9895 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9895, "deDE", "Jetzt, da Ihr die Anzeichen der Unausgeglichenheit mit eigenen Augen gesehen habt, achtet bei Euren weiteren Reisen darauf.", 26972);

-- 9911 - Der Graf der Marschen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9911 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9911, "deDE", "<Die Behüterin blinzelt ein paar Mal überrascht.>$B$BWoher habt Ihr dieses... Ding?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9911 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9911, "deDE", "Seid Ihr sicher, dass es echt ist? Ich meine, ich wusste schon, dass es riesige Kreaturen in den Marschen gibt, aber es gibt einen Unterschied zwischen riesigen Kreaturen und RIESIGEN Kreaturen.$B$BDa fällt mir ein, dass die Sporlinge einmal etwas von einem furchterregenden Netherrochen erzählt haben, der sie vor den Angriffen der Sumpflords bedroht hatte.$B$BWas ist, wenn diese Geschichten wahr sind? Oh je. Ich hebe das hier mal lieber auf. Die Expedition wird sicher davon erfahren wollen.", 26972);

-- 9912 - Die Expedition des Cenarius
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9912 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9912, "deDE", "Willkommen in der Zuflucht des Cenarius, $N. Ich hoffe, Ihr könnt uns bei unserer Aufgabe behilflich sein. Wir haben viel Arbeit vor uns.", 26972);

-- 9919 - Sporeggar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9919 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9919, "deDE", "Habt Ihr etwas, das Ihr mir zeigen möchtet, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9919 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9919, "deDE", "Ihr habt uns geholfen, die nächste Generation Sporlinge zu sichern, $R. Das können wir Euch nur mit einem Willkommen in unserer Stadt vergelten. Bleibt doch ein wenig und lernt die anderen Sporlinge kennen. Sie werden viele Fragen an Euch haben, ich hoffe, das macht Euch nichts aus.", 26972);

-- 9957 - Was ist los mit dem Cenariusdickicht?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9957 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9957, "deDE", "Ich bin froh, dass die Zuflucht Euch geschickt hat. Die Druiden des Dickichts wurden ermordet! Nur ich und ein weiterer haben überlebt, und er ist geisteskrank.$B$BIch weiß nicht, was passiert ist, aber ich bin entschlossen, es herauszufinden. Was auch immer es war, es passierte schnell und fühlt sich unnatürlich an.$B$BWerdet Ihr mir helfen?", 26972);

-- 10096 - Rettung der Sporloks
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10096 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10096, "deDE", "Gut! Diese Marschenbiester haben kein Recht, das Zuhause der Sporloks zu überfallen!$B$BEs wäre besser, wenn diese Tiere lernen würden, in Harmonie zu leben, aber wenn das nicht geht, müssen wir uns eben um die Situation kümmern!$B$BHier, bitte nehmt etwas hiervon als Dank für Eure Hilfe.", 26972);

-- 10103 - Bericht an Zurai
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10103 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10103, "deDE", "Um ehrlich zu sein hatte ich mehr Leute erwartet, aber Ihr müsst reichen. Willkommen im Sumpfrattenposten.", 26972);

-- 10105 - Nachrichten für Rakoria
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10105 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10105, "deDE", "Ich hatte gehofft, seine Leute würden den Außenposten früher fertigstellen, aber sein Geld kostet es ja schließlich nicht. Immerhin geht es voran.", 26972);

-- 10115 - Dolchfennkrise
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10115 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10115, "deDE", "Ihr habt gute Arbeit geleistet, $N. Keiner ist der Meinung, dass es noch Erlösung für den Dolchfennstamm gegeben hätte, aber ich glaube nicht, dass die Draenei in dieser Situation schnell genug gehandelt hätten.", 26972);

-- 10116 - GESUCHT: Häuptling Mummaki
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10116 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10116, "deDE", "Ihr wollt also das Kopfgeld für Häuptling Mummaki einfordern?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10116 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10116, "deDE", "Bemerkenswert! Es gab schon einige vor Euch, die das Kopfgeld gewinnen wollten, aber keiner von ihnen ist je zurückgekehrt. Es ist nicht schwer sich auszumalen, was ihnen wohl zugestoßen ist.$B$BIch bin sehr erleichtert, dass wir in Zukunft nichts mehr von Mummaki und seinem Gesindel zu befürchten haben.", 26972);

-- 10117 - GESUCHT: Häuptling Mummaki
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10117 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10117, "deDE", "Ihr wollt also das Kopfgeld für Häuptling Mummaki einfordern?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10117 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10117, "deDE", "Ihr habt meinen Dank, $N. Ich hatte mir schon überlegt, einen Teil der Garnison dorthin zu schicken und Mummaki selbst zu erledigen. Welche Folgen das jedoch für Zabra'jin gehabt hätte, ist schwer zu sagen.", 26972);

-- 10118 - Nachricht für Dolchfenn
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10118 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10118, "deDE", "Ich glaube, Ihr habt ihnen eine ziemlich deutliche Botschaft zukommen lassen. Vielleicht haben meine Männer nun nicht mehr so viel Angst vor dem Dolchfennstamm. Oder sie schämen sich zumindest für ihren Mangel an Mut.", 26972);

-- 10355 - Siechendes Fleisch
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10355 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10355, "deDE", "Konntet Ihr die Proben sammeln?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10355 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10355, "deDE", "<Ruam betrachtet die Proben und sieht besorgt aus.>$B$BEs ist so, wie ich es befürchtet habe, $N. Die Austrocknung der Umwelt macht den Kreaturen, die außerhalb eines Sumpfgebiets nie überleben würden, sehr zu schaffen. Wir müssen die Umgebung weiterhin überwachen und die Expedition des Cenarius fragen, ob es etwas gibt, was wir tun können.", 26972);
