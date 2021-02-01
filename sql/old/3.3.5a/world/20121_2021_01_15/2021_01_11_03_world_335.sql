-- Quest 469 - add missing data
-- https://de.classic.wowhead.com/quest=469/tägliche-lieferung + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 469 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(469, 'deDE', 'Guten Tag auch, $C. Kann ich Euch für ein Paar Stiefel interessieren? Vielleicht einige frisch gegerbte Häute?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 469 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(469, 'deDE', 'Hmm, das ist von Einar, oder? Er hat mir schon seit bald einer Woche seine Häute nicht mehr persönlich geliefert. Er hat sicher wieder Ärger mit seiner Frau!$B$BVielleicht lasse ich meine Frau mal mit Sida sprechen...', 0);

-- Quest 473 - add missing data
-- https://de.classic.wowhead.com/quest=473/meldung-bei-captain-stoutfist + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 473 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(473, 'deDE', '$N. Valstag klärte mich über Eure bisherigen Erfolge mit den Orcs des Drachenmalklans in Dun Algaz auf. Ihr seid $Gein:eine:r; $R von Wert.$B$BUnd ich habe eine Aufgabe für Euch.', 0);

-- Quest 484 - add missing data
-- https://de.classic.wowhead.com/quest=484/häute-junger-krokilisken + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 484 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(484, 'deDE', '$N, nicht wahr? Habt Ihr meine Häute?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 484 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(484, 'deDE', 'Ihr habt gute Arbeit geleistet, $N. Die Qualität dieser Häute ist superb. Ich muss so bald wie möglich mit dem Gerben dieser Häute beginnen. Oh, bevor ich jedoch damit anfangen kann, habe ich noch eine andere Aufgabe zu erledigen. Ich denke, dass Ihr sie übernehmen könnt.', 0);

-- Quest 471 - add missing data
-- https://de.classic.wowhead.com/quest=471/lehrlingspflichten + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 471 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(471, 'deDE', 'Mein Lehrling ist wie ein Sohn für mich. Wird hart für ihn sein, sein Leben mit nur einem Bein zu fristen.$B$BAh, $N, wie läuft\'s? Habt Ihr meine Häute?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 471 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(471, 'deDE', 'Hmm... Ihr habt nicht zufällig Lust, bei mir in die Lehre zu gehen?$B$BHa! Nein, war nur ein Witz. Ihr seid sowieso viel zu alt. Außerdem - nach Eurem Aussehen zu urteilen, habt Ihr wahrscheinlich andere Ambitionen im Leben. Dennoch habt Ihr da ein paar feine Häute besorgt und ich werde damit etwas anfangen können.', 0);

-- Quest 279 - add missing data
-- https://de.classic.wowhead.com/quest=279/klauen-aus-der-tiefe + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 279 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(279, 'deDE', 'Unsere Händler werden nicht sicher sein, bis wir Gobbler und diese Murlocs losgeworden sind.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 279 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(279, 'deDE', 'Ah, gut gemacht, $N.$B$BBitte nehmt dies als Bezahlung für die Erfüllung Eures Vertrages mit der Handelsmarine.', 0);

-- Quest 281 - add missing data
-- https://de.classic.wowhead.com/quest=281/waren-wiederbeschaffung + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 281 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(281, 'deDE', 'Diese Kiste ist mit klauenartigen Kratzern übersät und zeigt Spuren eines Wasserschadens. Das Aufbrechen enthüllt durchnässtes und verfaultes Stroh, als wäre etwas Wertvolles in dieser Kiste aufbewahrt worden. Ihr durchwühlt das Stroh...$B$B... und findet einen Arm voll rot gefärbter Flaschen.', 0);

-- Quest 284 - add missing data
-- https://de.classic.wowhead.com/quest=284/die-suche-geht-weiter + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 284 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(284, 'deDE', 'Dieses Fass ist weitgehend unberührt. Als Ihr es öffnet...$B$B... schlägt Euch der stechende Geruch von Käse entgegen. Er ist etwas feucht, aber immer noch schmackhaft!', 0);

-- Creature 1239 Quest Greeting - add missing data
-- https://www.youtube.com/watch?v=iEgiOE4zv18 2:57
DELETE FROM `quest_greeting_locale` WHERE `ID` = 1239 AND `locale` = 'deDE';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(1239, 0, 'deDE', 'Wenn Ihr gewillt seid, Euch Geschichten anzuhören, die Eure Knochen zum Schlottern bringen und Euch das Fürchten lehren werden, dann holt Euch etwas zu trinken und setzt Euch hin...', 0);

-- Creature 2094 Quest Greeting - add missing data
-- https://www.youtube.com/watch?v=iEgiOE4zv18 8:50
DELETE FROM `quest_greeting_locale` WHERE `ID` = 2094 AND `locale` = 'deDE';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(2094, 0, 'deDE', 'Seid gegrüßt $C. Ich befinde mich gerade in einer etwas misslichen Lage, ich habe fast keine Bälge mehr.', 0);

-- Quest 285 - add missing data
-- https://de.classic.wowhead.com/quest=285/suche-in-weiteren-hütten + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 285 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(285, 'deDE', 'Dieses Fass ist unter Schlamm und Gras halb begraben...', 0);

-- Quest 286 - add missing data
-- https://de.classic.wowhead.com/quest=286/rückgabe-der-statuette + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 286 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(286, 'deDE', 'Habt Ihr die Statuette?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 286 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(286, 'deDE', 'Der Kapitän der Blind Princess wird erleichtert sein zu hören, dass seine kostbare Fracht geborgen wurde. Ihr habt Euch diesen Lohn durch die geleisteten Dienste wohl verdient.$B$BEs tut gut, verlässliche Leute wie Euch zu kennen, insbesondere in so beschwerlichen Zeiten wie diesen.', 0);

-- Quest 470 - add missing data
-- https://de.classic.wowhead.com/quest=470/stochern-im-brühschlamm + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 470 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(470, 'deDE', 'Habt Ihr meine Tasche gefunden?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 470 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(470, 'deDE', 'Oh, danke sehr, $N! Ich hatte schon befürchtet, sie wäre für immer verloren!$B$B<Sie leert den Inhalt der schlammbedeckten Tasche schnell auf den Boden und sammelt die Sachen dann wieder ein.>$B$BHm, ich kann damit nicht mehr viel anfangen, aber wenn Ihr sie sauber macht, könnt Ihr sie bestimmt noch gebrauchen.', 0);

-- Quest 288 - add missing data
-- https://de.wowhead.com/quest=288/die-dritte-flotte + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 288 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(288, 'deDE', 'Oh, ich bin so furchtbar durstig! Wollt Ihr diesem armen, mitleiderregenden Trottel nicht einen Drink spendieren?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 288 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(288, 'deDE', 'Ah! Das ist genau das richtige und lockert die Zunge. Danke, Kumpel!', 0);

-- Quest 289 - add missing data
-- https://de.wowhead.com/quest=289/die-verfluchte-crew + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 289 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(289, 'deDE', 'Ich kann manchmal in meinen Träumen das unselige Stöhnen meiner Brüder hören! Bitte, $Gguter Herr:gute Dame;, befreit sie von ihren Fesseln und lasst ihre Schreie verstummen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 289 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(289, 'deDE', 'Ich danke Euch, $N. Und den Dank meiner verfluchten Brüder habt Ihr ebenfalls.', 0);

-- Quest 290 - add missing data
-- https://de.classic.wowhead.com/quest=290/brechen-des-fluchs + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 290 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(290, 'deDE', 'Diese Truhe ist sicher verschlossen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 290 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(290, 'deDE', 'Der Schlüssel ist verrostet, passt aber einwandfrei ins Schloss.', 0);

-- Quest 292 - add missing data
-- https://de.classic.wowhead.com/quest=292/das-auge-von-paleth + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 292 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(292, 'deDE', 'Dieser Säufer Fitzsimmons hat Euch zu mir geschickt? Nun, Ihr könnt ihm sagen, dass ich kein Ale übrig habe. Er wird wohl jemand anderes anbetteln müssen!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 292 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(292, 'deDE', 'Ein Auge von Paleth? Erstaunlich! Hmm... irgendetwas stimmt nicht mit diesem hier. Ihr habt es auf einem der Schiffswracks gefunden? Das erklärt einiges! Allerdings... wusste ich gar nicht, dass sie in der dritten Flotte ein solches Auge hatten...$B$BKein Wunder, dass Fitzsimmons so verängstigt war. Ein verfluchtes Auge von Paleth ist kein Grund zur Fröhlichkeit.', 0);

-- Quest 293 - add missing data
-- https://de.classic.wowhead.com/quest=293/die-reinigung-des-auges + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 293 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(293, 'deDE', 'Was habt Ihr da für eine Kugel? Sie sieht so... befleckt aus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 293 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(293, 'deDE', 'Ein Auge von Paleth. Aber dieses hat viel Leid gesehen... es muss Zeuge einer schrecklichen, grauenhaften Tragödie gewesen sein.$B$BLasst es mich reinigen, denn die Augen wurden geschaffen, um hell zu erstrahlen, und ihre Kräfte können sehr gefährlich sein, wenn sie wie dieses hier besudelt sind.', 0);

-- Quest 472 - add missing data
-- https://de.classic.wowhead.com/quest=472/der-fall-von-dun-modr + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 472 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(472, 'deDE', 'Welch $Gmutiger:mutige:c; $C bringt Kunde aus Menethil? Ah, $N werdet Ihr genannt.$B$BIhr bringt Hoffnung in eine hoffnungslose Situation. Gut zu wissen, dass der junge Harlo überlebt hat. Auf der Flucht wurde ihm eine ernste Wunde zugefügt. Wir hatten kaum die Zeit, ihn auf dem Rücken des letzten überlebenden Reittiers unseres Regiments fortzuschicken.$B$BAber wir sind hier in einer gefährlichen Lage. Dun Modr ist gefallen, und wir sind nur ein Schatten des großen Regiments, das wir einmal waren.', 0);

-- Quest 303 - add missing data
-- https://de.classic.wowhead.com/quest=303/der-dunkeleisenkrieg + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 303 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(303, 'deDE', 'Roggo konnte keinen Kontakt zu den Reserven herstellen. Wir müssen offensiven Druck auf dieses Lager der Dunkeleisenzwerge ausüben, $C. Und jetzt geht wieder da raus und erfüllt Eure Pflicht König Magni gegenüber!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 303 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(303, 'deDE', 'Ihr habt Eure Befehle gut ausgeführt, $C. Ihr habt bewiesen, dass Ihr ein tapferer Soldat und loyaler Diener König Magnis\' seid, und dafür bewundere ich Euch. Durch den Druck, den Ihr auf das Lager der Dunkeleisenzwerge ausgeübt habt, haben wir jetzt eine Chance, sie für immer aus unseren Landen zu vertreiben... wenn nur die verdammte Reserve endlich auftauchen würde...', 0);

-- Quest 304 - add missing data
-- https://de.classic.wowhead.com/quest=304/eine-grausige-aufgabe + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 304 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(304, 'deDE', 'Konntet Ihr Balgaras den Niederträchtigen schon aufspüren, $C? Er weicht uns schon eine ganze Weile aus.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 304 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(304, 'deDE', 'Balgaras der Niederträchtige ist endlich tot. Wenn sein Tod auch die vielen unschuldigen Zwerge nicht zurückbringt, die sinnlos durch seine Hand starben, so wird dies doch zum Seelenfrieden derer beitragen, die überlebt haben. Nachdem Balgaras nun tot ist, sollte es ein Leichtes sein, mit dem restlichen Dunkeleisenpack fertig zu werden. Jetzt müssen wir den Abschaum auslöschen, bevor ein neuer Anführer in diese Gegend entsandt wird.$B$BIhr habt Eure Sache gut gemacht, $C.', 0);

-- Quest 378 - add missing data
-- https://de.classic.wowhead.com/quest=378/tief-empfundener-zorn + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 378 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(378, 'deDE', 'Ich werde nicht zulassen, dass närrische Menschen-Bürokratie zwergischen Angelegenheiten in die Quere kommt, $N. Kam Tiefenzorn ist erwiesenermaßen einer der Verschwörer des Angriffs auf den Thandolübergang. König Magnis gute Gefolgsleute ließen dank Tiefenzorns Verrat ihr Leben. Den Menschen mag es genug sein, Tiefenzorn im Verlies verrotten zu lassen, aber ich werde nicht mehr ruhig schlafen, bis Tiefenzorn erschlagen ist.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 378 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(378, 'deDE', 'Kam Tiefenzorn hat also endlich herausgefunden, wie es ist, den Tod selbst zu erfahren? Gut. Geschieht dem feigen Dunkeleisenabschaum recht. Ihr habt Eure Sache gut gemacht, $C. Die Gefallenen des Angriffs auf den Thandolübergang waren nur Opfer in einer Welt voller Krieg und Unfrieden. Ihre Familien werden Frieden in dem Wissen finden, dass Tiefenzorn die Strafe erhielt, die er verdiente. Der Tod von Langzopfs Bruder wurde gerächt.', 0);

-- Quest 631 - add missing data
-- https://de.classic.wowhead.com/quest=631/der-thandol-übergang + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 631 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(631, 'deDE', 'Ihr durchsucht den winzigen Zwergenleichnam. Auf dem Helm könnt Ihr die deutlich eingravierten Buchstaben lesen: Ebenezer Rostlocke.', 0);

-- Quest 647 - add missing data
-- https://de.classic.wowhead.com/quest=647/mackreels-fusel + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 647 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(647, 'deDE', 'Na, wie läufts denn, $R?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 647 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(647, 'deDE', 'Es geht doch nichts über Dunst MacKreels Fusel, der einem an kalten Tagen so richtig das Herz wärmt. Und ich dachte schon, der kleine Scheißer würde wieder mal mit der Bezahlung auf sich warten lassen. Ich danke Euch, Freund! Vielen herzlichen Dank!', 0);

-- Quest 632 - add missing data
-- https://de.classic.wowhead.com/quest=632/der-thandol-übergang + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 632 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(632, 'deDE', 'Gibt es Spuren vom alten Rostlocke, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 632 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(632, 'deDE', 'Oh weh, das sind wirklich schlechte Nachrichten.', 0);

-- Quest 633 - add missing data
-- https://de.classic.wowhead.com/quest=633/der-thandol-übergang + old GTDB WotLK files
-- deDE ObjectiveText1 missing
UPDATE `quest_template_locale` SET `ObjectiveText1` = 'Sprengstoffbehälter zerstört', `VerifiedBuild` = 0 WHERE `ID` = 633 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 633 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(633, 'deDE', 'Der Behälter mit Sprengstoff muss zerstört werden!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 633 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(633, 'deDE', 'Die letzte Brücke ist gerettet! Ihr habt König Magni und dem Volk von Khaz Modan einen großen Dienst erwiesen.$B$BJetzt können wir so lange durchhalten, bis Verstärkung kommt...', 0);

-- Quest 634 - add missing data
-- https://de.classic.wowhead.com/quest=634/hilfegesuch-an-die-allianz + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 634 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(634, 'deDE', 'Langzopf und seine mutigen Soldaten haben mein ehrliches Mitgefühl und Beileid. Die Nachricht von der Tragödie am Thandolübergang und der Fall von Dun Modr lastet schwer auf meinem Herzen.$B$BAber Stromgarde ist gefallen! Darum befinden wir uns hier bei der Zuflucht. Wir müssen uns der Wiedereroberung unserer eigenen großen Stadt stellen.$B$BEhre und Pflicht verlangen von uns, dass wir das Hochland nicht verlassen, bis erneut das mächtige Banner des Königs über Stromgarde weht. Ich werde Langzopf Nachricht geben, dass er auf sich allein gestellt ist...', 0);

-- Quest 463 - add missing data
-- https://de.classic.wowhead.com/quest=463/der-sumpfhüter + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 463 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(463, 'deDE', 'Die Wurzeln und Farne sagen Gutes über Euch, $GKleiner:Kleine;. Obwohl ich viele Namen habe, höre ich doch nur auf wenige. Aber Ihr mögt mich Rethiel nennen.$B$BUnd Ihr müsst mir lauschen... denn dieses Land leidet an eiternden Wunden, und ich betraue Euch damit, sie zu heilen.', 0);

-- Quest 276 - add missing data
-- https://de.classic.wowhead.com/quest=276/stapfende-pfoten + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 276 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(276, 'deDE', 'Eure Aufgabe steht noch an, $Gjunger:junge:c; $C.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 276 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(276, 'deDE', 'Indem Ihr die Anzahl der Gnolle verringert habt, habt Ihr Euch um das Wohlergehen des Sumpflandes gekümmert. Obwohl mein Vertrauen in Euer Volk in der Vergangenheit belastet wurde, $R, kann es vielleicht doch noch wieder hergestellt werden.', 0);

-- Quest 277 - add missing data
-- https://de.classic.wowhead.com/quest=277/feuer-tabu + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 277 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(277, 'deDE', 'Habt Ihr die Feuermach-Werkzeuge der Gnolle?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 277 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(277, 'deDE', '... Danke. Ich werde diese Feuersteine zertrümmern und ins Meer werfen, auf dass sie nie wieder dazu verwendet werden können, lebendiges Holz zu verbrennen.', 0);

-- Quest 275 - add missing data
-- https://de.classic.wowhead.com/quest=275/schwärendes-land + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 275 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(275, 'deDE', 'Das Leiden des Landes wurde durch Eure Taten gemildert, und dafür werde ich Euch belohnen.', 0);

-- Quest 305 - add missing data
-- https://de.classic.wowhead.com/quest=305/auf-der-suche-nach-dem-ausgrabungstrupp + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 305 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(305, 'deDE', 'Oh, dank sei den Himmeln, dass Ihr hier seid!', 0);

-- Quest 306 - add missing data
-- https://de.classic.wowhead.com/quest=306/auf-der-suche-nach-dem-ausgrabungstrupp + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 306 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(306, 'deDE', 'Habt Ihr Merrin gefunden? Hat sie eine Nachricht geschickt? ', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 306 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(306, 'deDE', 'Welch grausige Neuigkeiten! Immerhin haben 3 von ihnen überlebt. Doch wann wird das Töten endlich aufhören? Ich sehne mich nach dem Tag, an dem König Magnis Untertanen ohne Angst leben können.', 0);

-- Quest 294 - add missing data
-- https://de.classic.wowhead.com/quest=294/ormers-rache + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 294 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(294, 'deDE', 'Töten ist ein schmutziges Geschäft, aber Ihr habt Eure Sache gut gemacht, $N. Wenn ich nicht dazu verpflichtet wäre, hier beim Ausgrabungsleiter und Merrin zu bleiben, würde ich an Eurer Seite da unten Blut vergießen.', 0);

-- Quest 295 - add missing data
-- https://de.classic.wowhead.com/quest=295/ormers-rache + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 295 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(295, 'deDE', 'Ihr habt beim Aufräumen unter diesen Raptoren phantastische Arbeit geleistet, $N!', 0);

-- Quest 296 - add missing data
-- https://de.classic.wowhead.com/quest=296/ormers-rache + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 296 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(296, 'deDE', 'Ist Sarlatan tot? Seid Ihr dem Andenken der Gefallenen gerecht geworden?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 296 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(296, 'deDE', 'Danke, $N. Eure Anstrengungen hier werden nicht in Vergessenheit geraten. Viele unschuldige Zwerge starben an dieser Stätte, während sie einfach nur ihrer Arbeit nachgingen. Die Rache, die Ihr über diese bösen Kreaturen gebracht habt, sollte dafür sorgen, dass sie es sich zweimal überlegen, bevor sie je wieder König Magnis Untertanen angreifen.', 0);

-- Quest 299 - add missing data
-- https://de.classic.wowhead.com/quest=299/enthüllung-der-vergangenheit + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 299 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(299, 'deDE', 'Habt Ihr die vier Fragmente bereits gefunden, $N? Ados, Modr, Golm und Neru...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 299 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(299, 'deDE', 'Ah, der Goazstein ist vollständig! Ausgezeichnete Arbeit, $N. Wirklich ausgezeichnete Arbeit. Jetzt kann ich mit der kniffligen Übersetzung dieser Titanenschrift weitermachen. Ich kann bereits neue Worte erkennen! Hmm... es heißt hier "Alte Götter... angekettet unter dem Land". Dies ist der Anfang von etwas Epischem.', 0);

-- Quest 464 - add missing data
-- https://de.classic.wowhead.com/quest=464/kriegsflaggen + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 464 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(464, 'deDE', 'Habt Ihr das Lager des Drachenmalklans angegriffen?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 464 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(464, 'deDE', 'Gut gekämpft, $N. Die Drachenmalorcs sind keine solche Bedrohung mehr wie zu den Zeiten, als sie noch Drachen unter sich hatten, aber sie sind dennoch harte Gegner.$B$BDer Drachenmalklan wird angeführt von Nek\'rosh, Sohn von Nekros, der vor vielen Jahren der Anführer des Drachenmalklans war. Nekros verwendete mächtige Magie, um die roten Drachen zu bändigen, aber als ihn diese Magie im Stich ließ ... waren die Drachen nicht glücklich.$B$BNekros wurde getötet, und sein Sohn hat Rache an den Drachen geschworen, die seinen Vater erschlugen.', 0);

-- Quest 465 - add missing data
-- https://de.classic.wowhead.com/quest=465/nekroshs-schachzug + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 465 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(465, 'deDE', 'Ihr seht das erste Katapult vor Euch. Wollt Ihr es entzünden?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 465 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(465, 'deDE', 'Ihr legt etwas von dem Zunder auf das Katapult und schlagt dann einen Funken darauf.$B$BFlammen schlagen hervor und breiten sich schnell aus!', 0);

-- Quest 474 - add missing data
-- https://de.classic.wowhead.com/quest=474/sieg-über-nekrosh + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 474 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(474, 'deDE', 'Habt Ihr Nek\'rosh getötet?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 474 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(474, 'deDE', 'Saubere Arbeit, $N. Ihr habt den Orcs vom Drachenmalklan einen deutlichen Schlag verpasst. Vielleicht erholen sie sich nie wieder davon. Außerdem hat die Zerstörung dieser Katapulte den Hafen von Menethil gesichert.$B$BIhr seid $Gein vorzüglicher:eine vorzügliche:r; $R, und das Königreich von Eisenschmiede belohnt die, die ihm gut dienen.', 0);

-- Quest 1302 - add missing data
-- https://de.classic.wowhead.com/quest=1302/james-hyal + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 1302 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(1302, 'deDE', 'James Hyal, James Hyal... Warum kommt mir der Name so bekannt vor?$B$BNatürlich! Der Vorfall im Gasthaus Zur süßen Ruh. Wenn Ihr Informationen habt, was dort geschehen ist, beschwöre ich Euch, mit Hauptmann Mumm darüber zu sprechen. Er leitet die Ermittlungen.', 0);
