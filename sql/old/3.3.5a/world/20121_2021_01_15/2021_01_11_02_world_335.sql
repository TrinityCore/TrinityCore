-- Quest 224 - update current and add missing data
-- https://de.classic.wowhead.com/quest=224/verteidigung-der-länder-des-königs + old GTDB WotLK files
-- Details / Objectives - wrong amount of creatures, 6 -> 10
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `Details` = 'Wir müssen den Loch beschützen, $n! Jetzt, wo so viele der Soldaten des Königs tapfer auf weit entfernten Schlachtfeldern kämpfen, sind wir nahe davor, an der Heimatfront überwältigt zu werden. Aus jedem Spalt graben sich Troggs an die Oberfläche! Die Troggplage stellt für Eisenschmiede die größte Gefahr dar. Diese widerwärtigen Mutanten müssen vernichtet werden.$b$bIhr, $gtapferer Abenteurer:tapfere Abenteurerin;, müsst Euch für uns hinauswagen und der Bedrohung durch die Troggs ein Ende bereiten. Erschlagt 10 Splittersteintroggs und 10 Späher der Splittersteintroggs und erstattet dann wieder Bericht.', `Objectives` = 'Gebirgsjäger Feuerkiesel vom südlichen Wachturm möchte, dass Ihr 10 Splittersteintroggs und 10 Späher der Splittersteintroggs tötet.', `VerifiedBuild` = 0 WHERE `ID` = 224 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 224 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(224, 'deDE', 'Der Loch Modan wird belagert, $N! Wir sind auf jedes einsatzfähige Mitglied der Allianz angewiesen. Habt Ihr schon 10 Splittersteintroggs und 10 Späher der Splittersteintroggs getötet?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 224 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(224, 'deDE', 'Gut gemacht, $N! Ihr habt auf dem Schlachtfeld verblüffenden Mut bewiesen. Mit Leistungen wie den Euren werden wir unseren Krieg gegen die Troggs gewinnen. Ihr habt König Magni gut gedient.$B$BWenn Ihr glaubt, dass Ihr gerade für solche Abenteuer gut geeignet seid, dann würde ich vorschlagen, Ihr sprecht mit Gebirgsjäger Kieselwut. Der Hauptmann hat ihn auf eine harte Patrouille geschickt, bei der er bestimmt Hilfe gebrauchen kann. Meldet Euch bei Kieselwut; er ist im Turm gleich beim Eingang.', 0);

-- Quest 267 - update current data
-- https://de.classic.wowhead.com/quest=267/die-bedrohung-durch-die-troggs + old GTDB WotLK files
-- deDE CompletedText missing
-- RewardText - "König Magni Bronzebeard" -> "König Magni Bronzebart", NPC 2784
UPDATE `quest_template_locale` SET `CompletedText` = 'Kehrt zu Hauptmann Rugelfuß am Nordtorpass in Dun Morogh zurück.', `VerifiedBuild` = 0 WHERE `ID` = 267 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Ich bin ziemlich beeindruckt, $N. Ihr habt dem Volk der Zwerge einen großen Dienst erwiesen, indem Ihr unser Land verteidigt habt. Selbst König Magni Bronzebart wäre stolz auf Euch!', `VerifiedBuild` = 0 WHERE `ID` = 267 AND `locale` = 'deDE';

-- Quest 237 - add missing data
-- https://de.classic.wowhead.com/quest=237/verteidigung-der-länder-des-königs + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 237 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(237, 'deDE', 'Wir brauchen mehr Zeit, $R. Ihr habt den Befehl, 10 Schädelhauer der Splittersteintroggs und 10 Seher der Splittersteintroggs zu töten. Setzt den Feind unter Druck, bis wir Verstärkung erhalten. Jetzt ist nicht die Zeit für Müßiggang.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 237 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(237, 'deDE', 'Ihr habt Eure Mission gut erfüllt, $R. Der König selbst wäre stolz auf Euch.$B$BDie Verstärkung, die uns versprochen war, ist jedoch nie angekommen. Anscheinend ist die Front der Allianz getränkt von dem roten Blut unserer gefallenen Brüder. Die Nachricht von diesen Verlusten hinterlässt einen bitteren Nachgeschmack. Doch wir dürfen nicht zulassen, dass ihr Tod vergeblich war. In diesen finsteren Zeiten müssen wir zusammenstehen und den Ruhm der Allianz wieder aufleben lassen.$B$BSprecht wegen Eurer nächsten Aufgabe mit Gebirgsjäger Wallbang. Wir brauchen Euch jetzt mehr als je zuvor.', 0);

-- Quest 263 - update current and add missing data
-- https://de.classic.wowhead.com/quest=263/verteidigung-der-länder-des-königs + old GTDB WotLK files
-- Details / Objectives - wrong amount of creatures, 8 -> 10
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `Details` = 'Die Gebirgsjäger sagen mir, dass Ihr recht tapfer und fähig seid, $n. $gEin:Eine:r; $R wie Ihr wird hier draußen gebraucht. Wir bekommen das Troggproblem einfach nicht unter Kontrolle. Die Reserve wurde zur Front gerufen, und wir sind hier auf uns allein gestellt. Aber jetzt seid ja Ihr hier, $gein erfahrener:eine erfahrene:c; $C, also wollen wir doch mal sehen, was Ihr ausrichten könnt.$b$bZieht los und tötet 10 Schamanen der Splittersteintroggs und 10 Knochenknacker der Splittersteintroggs. Wir werden sehen, ob Ihr Eurem Ruf gerecht werdet, $gTroggtöter:Troggtöterin;.', `Objectives` = 'Gebirgsjäger Wallbang im südlichen Wachturm möchte, dass Ihr 10 Schamanen der Splittersteintroggs und 10 Knochenknacker der Splittersteintroggs tötet.', `CompletedText` = 'Kehrt zu Gebirgsjäger Wallbang ins Tal der Könige in Dun Morogh zurück.', `VerifiedBuild` = 0 WHERE `ID` = 263 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 263 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(263, 'deDE', 'Schon wieder zurück? Nur für den Fall, dass ich mich nicht klar ausgedrückt habe: Ihr müsst 10 Schamanen der Splittersteintroggs und 10 Knochenknacker der Splittersteintroggs töten, $N. Und jetzt schnappt sie Euch, Trogg-Töter! ', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 263 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(263, 'deDE', 'Ich wusste schon, als ich Euch zum ersten Mal erblickte, $N, dass Ihr Eisenschmiede stolz machen würdet. Ihr habt König Magni gut gedient. Jetzt, wo Ihr Euch als so zuverlässige Hilfe für das Königreich erwiesen habt, solltet Ihr vielleicht mit dem Hauptmann reden, um zu sehen, ob er Euch mehr Details anvertraut.$B$BIch ziehe den Hut vor Euch, $N.', 0);

-- Quest 217 - update current and add missing data
-- https://de.classic.wowhead.com/quest=217/verteidigung-der-länder-des-königs + old GTDB WotLK files
-- Title / Details / Objectives differ from Classic / 3.3.5 GTDB data and even the english defaults
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `Title` = 'Verteidigung der Länder des Königs', `Details` = '$N, unsere Späher haben den Anführer des jüngsten Eindringens der Troggs ermitteln können. Es scheint, als folgten diese Bestien am Loch Modan einem Häuptling namens Grawmug. Grawmug wird jedoch aufs Schwerste bewacht. Zwei seiner Elitewachen, Knirscher und Muskelprotz, weichen nie von seiner Seite.$B$BWenn Ihr Euch dem gewachsen fühlt, $N, dann möchte ich, dass Ihr das Attentat auf Grawmug und seine beiden Schläger anführt. Wenn die Führungsriege der Troggs tot ist, dann haben wir vielleicht eine Chance, diese Bestien wieder unter die Erde zu treiben.', `Objectives` = 'Tötet den Anführer der Troggs, Grawmug, sowie seine beiden Wachen, Knirscher und Muskelprotz, und erstattet dann Hauptmann Rugelfuß im südlichen Wachturm Bericht.', `CompletedText` = 'Kehrt zu Hauptmann Rugelfuß ins Tal der Könige in Dun Morogh zurück.', `VerifiedBuild` = 0 WHERE `ID` = 217 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 217 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(217, 'deDE', 'Grawmug und seine beiden Wachen, Knirscher und Muskelprotz, sind noch immer am Leben. Eure Mission ist nicht beendet, solange noch einer der drei am Leben ist. Das Zwergenreich zählt auf Euch, $N!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 217 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(217, 'deDE', 'Ganz ausgezeichnet, $N! Ihr habt wieder Hoffnung an den Loch Modan gebracht. Jetzt, wo Grawmug tot ist, besteht eine größere Chance, dass die Troggs aus unserem Land vertrieben werden.', 0);

-- Quest 418 - update current and add missing data
-- https://de.classic.wowhead.com/quest=418/thelsamar-blutwurst + old GTDB WotLK files
-- in field Objectives mentioned items do not fit the actual quest
UPDATE `quest_template_locale` SET `Objectives` = 'Bringt Vidra Ofenglut in Thelsamar 3 Stück Bärenfleisch, 3 Portionen Ebergedärme und 3 Portionen Spinnensekret.', `VerifiedBuild` = 0 WHERE `ID` = 418 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 418 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(418, 'deDE', 'Ich bin so weit, dass ich mit dem Kochen anfangen könnte; habt Ihr die Zutaten?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 418 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(418, 'deDE', 'Vertraut mir, es ist schwerer als es aussieht, aber...$B$BAch, ich habe bisher noch nie jemanden getroffen, der sich sehr für die Herstellung von Würsten interessiert hat, aber ich werde Euch für alle Fälle dennoch das Rezept geben. Hier, und denkt immer daran, sie zu essen, solange sie frisch sind!', 0);

-- Quest 6387 - update current data
-- https://de.classic.wowhead.com/quest=6387/ehrenstudenten + old GTDB WotLK files
-- this quests data seems to be wrong, it seems to have been relocated to Kharanos with 4.x as
-- NPC Brolan Windbart was added with 4.0.3 according to wowhead and CompletionText refers directly to Kharanos
UPDATE `quest_template_locale` SET `Title` = 'Ehrenstudenten', `Details` = 'Ich sehe viele junge Zwerge vor meiner Tür, die begierig sind, den Bergbau zu erlernen. Und wenn ein Minenarbeiter eines mehr als alles andere braucht, dann ist das eine Hacke!$B$BIch habe eine Liste von Bergbaustudenten mit vorzüglichen Abschlussprüfungen, die sich eine Ehrenhacke verdient haben. Bringt meine Liste zu Golnir Geröllzeh in Eisenschmiede. Er wird die Hacken fertigmachen.$B$BDas schnellste Transportmittel nach Eisenschmiede ist ein Greif, also bringt die Liste Thorgrum Borrelson, unserem Greifenmeister, und sprecht mit ihm über den Transport nach Eisenschmiede.', `Objectives` = 'Bringt Brocks Liste zu Thorgrum Borrelson in Thelsamar.', `VerifiedBuild` = 0 WHERE `ID` = 6387 AND `locale` = 'deDE';
UPDATE `quest_request_items_locale` SET `CompletionText` = 'Habt Ihr schon so bald die Nase voll von Thelsamar? Seid Ihr bereit, in eine andere Stadt abzureisen?', `VerifiedBuild` = 0 WHERE `ID` = 6387 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Ihr müsst das nach Eisenschmiede bringen, hm? Für ein geringes Entgelt setze ich Euch auf den Rücken eines meiner Greife, der Euch dorthin bringt. Na, was sagt Ihr dazu?', `VerifiedBuild` = 0 WHERE `ID` = 6387 AND `locale` = 'deDE';

-- Quest 6391 - update current data
-- https://de.classic.wowhead.com/quest=6391/flug-nach-ironforge + old GTDB WotLK files
-- this quests data seems to be wrong, e.g. "Gremlocks List" instead of "Brocks List"
-- Gremlock is located in Dun Morogh, therefore this quest seems to be relocated from Loch Modan to Dun Morogh as well as 6387
-- quest_request_items_locale, $G missing
-- quest_offer_reward_locale refering to Gremlock as well, should be refering to NPC Brock
-- additionally refers to wrong questitem "Ehrenbeile", actual questitem is "Ehrenhacken" 16311
UPDATE `quest_template_locale` SET `Details` = 'Für nur ein paar Münzen bringt Euch einer meiner Greifen nach Eisenschmiede. Bringt dann Brocks Liste zu Golnir Geröllzeh. Ihr findet ihn in der Tiefenbergbaugilde. Sie liegt im Distrikt der Großen Schmiede von Eisenschmiede, und genau dort setzt Euch mein Greif ab!$B$BSprecht wieder mit mir, wenn Ihr bereit für die Reise seid.', `Objectives` = 'Bucht einen Greifen nach Eisenschmiede von Greifenmeister Thorgrum Borrelson, dann bringt Brocks Liste zu Golnir Geröllzeh in Eisenschmiede.', `VerifiedBuild` = 0 WHERE `ID` = 6391 AND `locale` = 'deDE';
UPDATE `quest_request_items_locale` SET `CompletionText` = 'Womit kann ich Euch dienen, $Gwerter Herr:werte Dame;?', `VerifiedBuild` = 0 WHERE `ID` = 6391 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Ah, die neueste Liste von Brocks Meisterschülern. Ich habe schon ein paar Ehrenhacken bereit. Ich muss nur noch die Namen der Studenten eingravieren...', `VerifiedBuild` = 0 WHERE `ID` = 6391 AND `locale` = 'deDE';

-- Quest 6388 - update current data
-- https://de.classic.wowhead.com/quest=6388/gryth-thurden + old GTDB WotLK files
-- "Ehrenbeile" -> "Ehrenhacken" and "Gremlock" -> "Brock" also wrong reference to Kharanos, instead of quests actual location Thelsamar
-- again reference to Brolan Windbart which was added with 4.x
UPDATE `quest_template_locale` SET `Details` = 'Hier sind die Ehrenhacken für Brocks Studenten. Wenn Ihr schon in Thelsamar gewesen seid, dann solltet Ihr mit einem Greifen dorthin zurückfliegen!$B$BBringt die Hacken zu unserem Greifenmeister Gryth Thurden und sprecht mit ihm über die Rückreise nach Thelsamar.', `Objectives` = 'Bringt die Ehrenhacken zu Gryth Thurden in Eisenschmiede.', `VerifiedBuild` = 0 WHERE `ID` = 6388 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Ihr müsst das nach Thelsamar bringen, hm? Das wird gar kein Problem sein. Wenn Ihr schon in Thelsamar gewesen seid und mit Thorgrum Borrelson gesprochen habt, dann könnt Ihr einen meiner Greifen zurück zu ihm nehmen.', `VerifiedBuild` = 0 WHERE `ID` = 6388 AND `locale` = 'deDE';

-- Quest 6392 - update current data
-- https://de.classic.wowhead.com/quest=6392/rückkehr-zu-brock + old GTDB WotLK files
-- again "Gremlock" instead of NPC "Brock", Kharanos instead of Thelsamar, wrong questitem name and so on
UPDATE `quest_template_locale` SET `Title` = 'Rückkehr zu Brock', `Details` = 'Für ein geringes Entgelt könnt Ihr einen Greifenritt nach Thelsamar buchen... wenn Ihr schon einmal dort gewesen seid. Greifen fliegen nur zu Orten, an denen Ihr schon einmal gewesen seid, sprecht also mit jedem Greifenmeister, den Ihr seht, dann könnt Ihr später direkt zu ihm fliegen.$B$BIhr seid schon bei Thorgrum, dem Greifenmeister von Thelsamar, gewesen, daher könnt Ihr jetzt zu ihm zurückkehren. Wenn Ihr in Thelsamar seid, könnt Ihr Brock Steinsucher die Hacken bringen.$B$BSprecht mit mir, wenn Ihr bereit zum Aufbruch seid.', `Objectives` = 'Bucht einen Greifen nach Thelsamar bei Greifenmeister Gryth Thurden, dann bringt die Ehrenhacken zu Brock Steinsucher in Thelsamar.', `VerifiedBuild` = 0 WHERE `ID` = 6392 AND `locale` = 'deDE';
UPDATE `quest_offer_reward_locale` SET `RewardText` = 'Ihr habt die Hacken. Großartig! Ich werde sie meinen Bergbaustudenten bringen. Sie können es sicher kaum erwarten, sich damit auf die Erzvorkommen von Loch Modan zu stürzen.$B$BDanke für Eure Hilfe, $N. Ich stehe in Eurer Schuld, hoffe jedoch, dieses Geld wird wenigstens Eure Reisekosten decken.', `VerifiedBuild` = 0 WHERE `ID` = 6392 AND `locale` = 'deDE';

-- Quest 416 - update current and add missing data
-- https://de.classic.wowhead.com/quest=416/rattenfang + old GTDB WotLK files
-- Objectives wrong data, mentioned NPC Mountaineer Kadrell is located in Thelsamar, not Algaz Station
-- wrong amount of questitems as well, 8 -> 12
UPDATE `quest_template_locale` SET `Objectives` = 'Bringt Gebirgsjäger Kadrell in Thelsamar 12 Tunnelrattenohren.', `VerifiedBuild` = 0 WHERE `ID` = 416 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 416 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(416, 'deDE', 'Seid gegrüßt, $N. Wie steht es mit der Rattenjagd?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 416 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(416, 'deDE', 'Igitt! Als ich diese Ohren verlangte, hatte ich keine Ahnung, dass sie so schrecklich stinken würden.$B$BHier ist Eure Belohnung, $N. Gut gemacht.', 0);

-- Quest 1339 - add missing data
-- https://de.classic.wowhead.com/quest=1339/gebirgsjäger-stormpikes-aufgabe + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 1339 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(1339, 'deDE', 'Ganz recht. Ich habe eine Aufgabe, die ich auf Wache nicht erledigen kann. Sie wird Euch weit vom Loch Modan wegführen.$B$BDie perfekte Chance auf ein Abenteuer!', 0);

-- Creature 1343 Quest Greeting - add missing data
-- https://www.youtube.com/watch?v=vDXXQE-6nfI 11:10
DELETE FROM `quest_greeting_locale` WHERE `ID` = 1343 AND `locale` = 'deDE';
INSERT INTO `quest_greeting_locale` (`ID`, `Type`, `locale`, `Greeting`, `VerifiedBuild`) VALUES
(1343, 0, 'deDE', 'Na, wenn das nicht $Gein junger:eine junge:c;, $Gwilder:wilde:c; $C ist, $Gden:die:c; zweifellos Erzählungen über meine Taten auf dem Schlachtfeld hierher geführt haben!$B$BLeider ist jetzt keine Zeit für große Geschichten, denn es gilt bedeutende Taten zu vollbringen! Wenn Ihr also auf Ruhm aus seid, dann ist Euch das Glück heute hold...', 0);

-- Quest 307 - update current and add missing data
-- https://de.classic.wowhead.com/quest=307/schmutzige-pfoten + old GTDB WotLK files
-- Objectives wrong amount of questitems 6 -> 4
UPDATE `quest_template_locale` SET `Objectives` = 'Geht zur Silberbachmine und sucht 4 Sätze Minenarbeiterausstattung zusammen.$B$BKehrt dann zu Gebirgsjäger Sturmlanze zurück.', `VerifiedBuild` = 0 WHERE `ID` = 307 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 307 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(307, 'deDE', 'Habt Ihr die Minenarbeiterausstattung, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 307 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(307, 'deDE', 'Habt Ihr da drin viele Kobolde gesehen? Ich kann den Befehl, sie aus der Mine zu werfen, kaum erwarten. Der Gedanke daran, wie ihre schmutzigen Hände in unserer Mine herumkratzen, verursacht mir Bauchschmerzen!', 0);

-- Quest 250 - add missing data
-- https://de.classic.wowhead.com/quest=250/eine-dunkle-bedrohung + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 250 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(250, 'deDE', 'Das verdächtig aussehende Fass enthält ein sonderbar riechendes Pulver.', 0);

-- Quest 255 - update current and add missing data
-- https://de.classic.wowhead.com/quest=255/söldner + old GTDB WotLK files
-- it seems like this quest was relocated to NPC Kelt Thomasin as questgiver with 4.x to Farstrider Lodge
-- therefore the references in Details and Objectives are incorrect
-- Details / Objectives differ from Classic / 3.3.5 GTDB data and even the english defaults
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `Details` = 'Zwei Monate! Zwei Monate, nur um dann aus Eisenschmiede zu hören zu bekommen, dass eine Handvoll Soldaten zu unserer Verteidigung abgestellt wird, und zwei weitere Monate, bis sie ankommen! Schlimm genug, dass unsere Stadt ohne Schutz ist, aber die Ausgrabung und der Damm - der Damm! - sind ebenfalls allen Angriffen schutzlos ausgesetzt.$B$BIch habe also keine Wahl, scheint mir. Ich brauche gedungene Kämpfer.$B$BWie steht es mit Euch? Ihr seht mir tüchtig aus, $C. Eine Gruppe Oger hat im Nordosten des Sees ihr Lager aufgeschlagen. Vielleicht seid Ihr ja die Unterstützung, die uns hilft, die Bedrohung für unsere Stadt zu beseitigen?', `Objectives` = 'Magistrat Stumpfnase aus Thelsamar hat Euch angeheuert, um 4 Oger der Mo\'grosh, 4 Schläger der Mo\'grosh und 4 Vollstrecker der Mo\'grosh zu töten.', `CompletedText` = 'Kehrt zu Magistrat Stumpfnase in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 255 AND `locale` = 'deDE';
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 255 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(255, 'deDE', 'Ah, das sind ausgezeichnete Neuigkeiten! Ich selbst und die Bewohner von Thelsamar wissen Eure Mühen außerordentlich zu schätzen. Und was noch besser ist: Wenn wir in der Lage sind, das Ogerproblem zu lösen, dann können wir unsere Aufmerksamkeit endlich auf diese vom Licht verlassenen Troggs richten.', 0);

-- Quest 256 - add missing data
-- https://de.classic.wowhead.com/quest=256/gesucht-choksul
DELETE FROM `quest_request_items_locale` WHERE `ID` = 256 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(256, 'deDE', 'Ja? Kann ich Euch behilflich sein?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 256 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(256, 'deDE', 'Pfui! Was ist das denn? Und warum bringt Ihr...$B$BVerdammt! Kann es sein? Da verbrenn mich doch das Licht; ist das der Kopf dieses verdammten Ogers? Da habt Ihr vielleicht einen Fang gemacht! Hier, nehmt diese Belohnung, zusammen mit meinem Dank und dem der Bewohner von Thelsamar.', 0);

-- Quest 436 - add missing data
-- https://de.classic.wowhead.com/quest=436/ironbands-ausgrabungsstätte + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 436 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(436, 'deDE', 'Jern will wissen, was uns aufhält, hm?$B$BEisenband verfasst gerade seinen jüngsten Fortschrittsbericht mit allen Details, aber ich kann Euch Folgendes sagen:$B$BEs sind die Troggs!', 0);

-- Quest 297 - update current and add missing data
-- https://de.classic.wowhead.com/quest=297/götzen-sammeln + old GTDB WotLK files
-- deDe CompletedText missing
UPDATE `quest_template_locale` SET `CompletedText` = 'Kehrt zu Magmar Todesstreich bei Eisenbands Ausgrabungsstätte in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 297 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 297 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(297, 'deDE', 'Habt Ihr die Götzen? Wir müssen sie studieren und Eisenschmiede von unseren Ergebnissen berichten!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 297 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(297, 'deDE', 'Ihr habt sie! Gut gemacht, $N!$B$BUnd Ihr seht nicht einmal besonders angeschlagen aus, trotz all der wild gewordenen Troggs. Ich werde Euch im Auge behalten... Ihr seid viel versprechend.', 0);

-- Quest 298 - add missing data
-- https://de.classic.wowhead.com/quest=298/bericht-über-den-fortschritt-der-ausgrabungen + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 298 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(298, 'deDE', 'Oh, ein Fortschrittsbericht von der Stätte? Sehr gut!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 298 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(298, 'deDE', 'Pah! Eisenband hat Probleme mit den Troggs. Ich frage mich, ob er das Sprengpulver will, um ihm bei seinen Ausgrabungen zu helfen oder um ihn bei seinen Bemühungen gegen die Troggbestien zu unterstützen...$B$BNun ja, so oder so ist das gute Pulver sinnvoll eingesetzt!$B$BEs ist allerdings etwas seltsam, dass ich ihm vor ein paar Wochen eine Menge Sprengpulver geschickt habe. Ich frage mich ja, wo das hingekommen ist...', 0);

-- Quest 257 - update current and add missing data
-- https://de.classic.wowhead.com/quest=257/das-prahlen-eines-jägers + old GTDB WotLK files
-- Objectives wrong amount of creatures 8 -> 6
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `Objectives` = 'Tötet 6 Bergbussarde und kehrt innerhalb von 15 Minuten zu Daryl dem Jüngling in die Jagdhütte der Weltenwanderer zurück.', `CompletedText` = 'Kehrt zu Daryl dem Jüngling in die Jagdhütte der Weltenwanderer in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 257 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 257 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(257, 'deDE', 'Kein Glück gehabt? Macht Euch nix draus, $Ner...$B$BNicht jeder kann so gut sein wie ich.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 257 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(257, 'deDE', 'Wie jetzt, Ihr hattet Erfolg?$B$BGlaubt mir, $Nama, das sollte Euch nicht zu Kopf steigen. Denn jeder milchgesichtige Junge mit einem Bogen hätte so... kleine Exemplare töten können. Und ich hoffe, es hat Euch nicht zu viel Spaß gemacht, die Bussarde zu erschießen. Wir wollen doch nicht, dass sie aussterben!$B$BAch so, ähhhm... Es soll keiner sagen, dass Daryl der Kühne sein Wort nicht hält.', 0);

-- Quest 258 - update current and add missing data
-- https://de.classic.wowhead.com/quest=258/die-herausforderung-eines-jägers + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Details` = '$Nath, stimmt\'s? Ich seh schon, Ihr platzt fast vor Stolz, dass Ihr den ersten Test bestanden habt. Aber ich hab Euch ja auch schon gesagt, dass das keine große Tat war.$B$BIhr solltet Euch mal an der Eberjagd versuchen. Glaubt mir, das sind andere Eber als im Eisklammtal, also solltet Ihr Euch vorsehen. Diesmal gebe ich Euch nur 12 Minuten.$B$BSeid nicht zu traurig, wenn Ihr versagt. Ich würde Euch das Hemd geben, das ich am Leibe trage, wenn Ihr es schaffen würdet!$B$BHabe ich Euch schon mal erzählt, wie ich an meine berühmte Narbe gekommen bin? Nein? Also, das war vor zwei Jahren...', `Objectives` = 'Tötet 5 alte Bergeber und kehrt innerhalb von 12 Minuten zu Daryl dem Jüngling in die Jagdhütte der Weltenwanderer zurück.', `CompletedText` = 'Kehrt zu Daryl dem Jüngling in die Jagdhütte der Weltenwanderer in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 258 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 258 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(258, 'deDE', 'Es ist ganz normal, dass man sich selbst bemitleidet, wenn man sich vor jemandem blamiert, der so viel jünger ist als man selbst. Macht Euch nichts draus, $Nah...$B$BWie? Hab ich mir Euren Namen falsch gemerkt?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 258 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(258, 'deDE', 'Ihr seht etwas mitgenommen aus. Die Eber haben Euch wohl ein paar Schwierigkeiten gemacht, wie? Keine Sorge, ich verrate es auch keinem, dass Ihr versagt habt; ich kann mir vorstellen, wie schwer es für Euch sein muss, auch ohne dass sich die Leute über Euch das Maul zerreißen.$B$BOh! Ihr habt es geschafft? Ihr habt die Eber getötet? Ich... also... na ja, das überrascht mich nicht! Jedes Kind hätte das - Wette?$B$BWas für eine Wette?', 0);

-- Quest 271 - update current and add missing data
-- https://de.classic.wowhead.com/quest=271/vyrins-rache + old GTDB WotLK files
UPDATE `quest_template_locale` SET `Details` = 'Ihr seid nicht zufällig daran interessiert, es unserem ach so kühnen Kühnen ein wenig heimzuzahlen? Es schmerzt mich, das zu sagen, aber Daryl hat ein gewisses Talent.$B$BVor einem Jahr war ein großer Bär das Ziel der Jagdhütte der Weltenwanderer, aber keiner der Jäger hatte Glück mit ihm. Also dachte sich Daryl, er könnte sich mal an ihm versuchen. Das Einzige, was er nach seinem Versuch vorweisen konnte, war die hässliche Narbe über seinem Auge.$B$BErlegt den Bären und ich bin mir sicher, dass sogar Daryl mal sprachlos wäre.$B$BAlte Rußtatze, der Bär, hält sich irgendwo in der Nähe seines Baus in den Hügeln über Thelsamar auf.', `CompletedText` = 'Kehrt zu Daryl dem Jüngling in die Jagdhütte der Weltenwanderer in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 271 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 271 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(271, 'deDE', 'Ah, $N! Schon wieder hier? Zweifelsohne wart Ihr wieder auf der Jagd! Keine Sorge, es ist nicht schlimm, wenn Ihr ein paar Rückschläge einstecken müsst, davon werdet Ihr auf lange Sicht nur besser.$B$B... viel schlechter könntet Ihr ja sowieso nicht mehr werden...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 271 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(271, 'deDE', 'Äh... was ist das da? Ein Bärenschädel, wie es aussieht.$B$B<Er fährt unbewusst mit einem Finger an seiner Narbe entlang>$B$BNun, das ist eine ziemlich interessante Beute, die Ihr da habt. Kann eigentlich nicht der Bär von damals sein...$B$B<Seine Stimme verliert sich, und er fängt sichtbar an zu zittern.>$B$BOh, nehmt das weg, nehmt es weg! Schafft dieses grausige Ding hier raus!', 0);

-- Quest 531 - add missing data
-- https://de.classic.wowhead.com/quest=531/vyrins-rache + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 531 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(531, 'deDE', 'Sehr gute Arbeit, $N! Wir habens ihm wirklich gezeigt! Hier, gebt mir den Kopf, ich werde mich darum kümmern.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 531 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(531, 'deDE', 'Danke für Eure Hilfe bei meinem kleinen Plan, $N. Seit Monaten wollte ich es diesem hochnäsigen, eingebildeten Jungen schon heimzahlen und ich würde meinen, es hat so richtig gut geklappt! Hier, nehmt das, Ihr habt es Euch verdient.', 0);

-- Quest 385 - update current and add missing data
-- https://de.classic.wowhead.com/quest=385/krokiliskenjagd + old GTDB WotLK files
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `CompletedText` = 'Kehrt zu Marek Eisenherz in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 385 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 385 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(385, 'deDE', 'Hab ich Euch eigentlich erzählt, wie ich damals beinahe meine Hand an einen der Kroks verloren hätte? Ein übles Viech war das, mit Zähnen wie Messer. Aber ich hatte Glück... Hab dem Monster mit meinem Messer das Maul gestopft. Ich habe das Messer sogar noch irgendwo herumliegen...', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 385 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(385, 'deDE', 'Na, wenn das nicht ein paar Prachtexemplare sind, die Ihr da gesammelt habt, $N. Für hochwertiges Material gibt es selbstverständlich auch eine ordentliche Bezahlung.', 0);

-- Quest 2038 - update current and add missing data
-- https://de.classic.wowhead.com/quest=2038/bingles-verschwundene-werkzeuge + old GTDB WotLK files
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `CompletedText` = 'Kehrt zu Bingles Blastenheimer am Loch in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 2038 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 2038 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(2038, 'deDE', '$N! Wo sind meine Sachen?!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 2038 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2038, 'deDE', 'Ihr habt der Bewegung einen großen Dienst erwiesen, $N. Die Troggs und Lepragnome, die Gnomeregan verschandeln, werden bald die Wucht eines Gnomenluftangriffs spüren!', 0);

-- Quest 199 - add missing data
-- https://de.classic.wowhead.com/quest=199/eine-dunkle-bedrohung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 199 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(199, 'deDE', 'Habt Ihr irgendwelche Hinweise finden können, $N?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 199 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(199, 'deDE', 'Diese Entdeckung ist alarmierend und das ist noch milde ausgedrückt!', 0);

-- Quest 161 - update current and add missing data
-- https://de.classic.wowhead.com/quest=161/eine-dunkle-bedrohung + old GTDB WotLK files
-- quest points to NPC Ashlan Stonesmirk which is located in Dun Modr
-- current deDE locales refer to Mo Grosh camp instead, again something changed in 4.x ?
UPDATE `quest_template_locale` SET `Details` = 'Falls mein Verdacht sich bestätigt, ist dies eine Art Sprengpulver. Es muss von einem Sprengstoffexperten analysiert werden, damit wir genau wissen, mit was wir es hier zu tun haben. Ashlan Schmunzelstein wurde dem Regiment zugeteilt, das Dun Modr und den Thandolübergang bewachen soll. Ihr müsst für mich eine schwierige und gefahrvolle Reise auf Euch nehmen, $N.$B$BReist durch das Algaz-Tor, folgt der Straße durch das Sumpfland und sucht Schmunzelstein in Dun Modr auf. Folgt meinem Rat: Bleibt auf den Straßen und lasst Euch nicht zum Anhalten bewegen!', `Objectives` = 'Chefingenieur Hinderweir möchte, dass Ihr das sonderbar riechende Pulver zu Ashlan Schmunzelstein, dem Sprengstoffexperten, bringt. Er befindet sich in Dun Modr im Sumpfland.', `VerifiedBuild` = 0 WHERE `ID` = 161 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 161 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(161, 'deDE', 'Habt Ihr was gesagt, Jungchen? Ich kann nix hören außer dem verdammten Dröhnen in den Ohren. Sagt mal, was habt Ihr denn da?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 161 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(161, 'deDE', 'Ah ja, also da hat der Olle Hinderweir verdammt Recht, dass er sich Sorgen macht.', 0);

-- Quest 274 - update current and add missing data
-- https://de.classic.wowhead.com/quest=274/eine-dunkle-bedrohung + old GTDB WotLK files
-- Details / Objectives differ from Classic / 3.3.5 GTDB data and even the english defaults
-- again something that came in with 4.x ?
UPDATE `quest_template_locale` SET `Details` = 'Dies ist kein gewöhnliches Sprengpulver. Seht diese winzigen Silberkristalle. Und der eindeutige Geruch! Es ist sonnenklar, dass es sich hier um Zephyriumpulver handelt. Zephyrium an sich ist harmlos. Aber wenn es nass wird, könnte es ganz Eisenschmiede aus dem Berg sprengen.$B$BDie chemische Reaktion kann entschärft werden, indem man vier Komponenten mischt: Lauerergift, einen zerstoßenen Kristall der Mo\'grosh, eine Krokiliskenträne und diese Entschärfungspaste. Jetzt geht und erklärt es Hinderweir, ehe es zu spät ist!', `Objectives` = 'Ashlan Schmunzelstein möchte, dass Ihr zum Chefingenieur Hinderweir nach Loch Modan zurückkehrt und ihn von der neuen Entdeckung in Kenntnis setzt.', `VerifiedBuild` = 0 WHERE `ID` = 274 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 274 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(274, 'deDE', 'Was bringt Ihr da von Ashlan?', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 274 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(274, 'deDE', 'Eine Entschärfungspaste? Für Zephyrium? Oh Himmel!', 0);

-- Quest 278 - update current and add missing data
-- https://de.classic.wowhead.com/quest=278/eine-dunkle-bedrohung + old GTDB WotLK files
-- Objectives refer to NPC Ashlan Stonesmirk as questgiver, but its Hinderweir instead
-- deDE CompletedText missing
UPDATE `quest_template_locale` SET `Objectives` = 'Chefingenieur Hinderweir möchte, dass Ihr Lauerergift, einen Kristall der Mo\'grosh und eine Krokiliskenträne besorgt.', `CompletedText` = 'Kehrt zu Chefingenieur Hinderweir VII. auf dem Steinwerkdamm in Loch Modan zurück.', `VerifiedBuild` = 0 WHERE `ID` = 278 AND `locale` = 'deDE';
DELETE FROM `quest_request_items_locale` WHERE `ID` = 278 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(278, 'deDE', 'Habt Ihr die benötigten Dinge? Die Zeit drängt!!', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 278 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(278, 'deDE', 'Gerade rechtzeitig, $N!', 0);

-- Quest 280 - add missing data
-- https://de.classic.wowhead.com/quest=280/eine-dunkle-bedrohung + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 280 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(280, 'deDE', 'Der Deckel des Fässchens schraubt sich langsam ab.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 280 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(280, 'deDE', 'Das Fässchen zischt ein wenig, als sich die Entschärfungsmixtur darin löst.', 0);

-- Quest 283 - add missing data
-- https://de.classic.wowhead.com/quest=283/eine-dunkle-bedrohung + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 283 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(283, 'deDE', 'Vielen, vielen Dank, $N! Ihr habt den Steinwerkdamm gerettet! Ohne Eure Hilfe hätten die Terroristen der Dunkeleisenzwerge bestimmt für den Untergang dieses mächtigen Wahrzeichens gesorgt. Mit Eurer Tapferkeit habt Ihr das Königreich und die Allianz stolz gemacht, $C.$B$BDer Damm ist wieder sicher ... zumindest vorläufig ...', 0);

-- Quest 2500 - add missing data
-- https://de.classic.wowhead.com/quest=2500/reagenzien-suche-im-ödland + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 2500 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(2500, 'deDE', 'Habt Ihr die Sachen schon, die ich brauche? Ihr werdet nur bezahlt, wenn Ihr mir diese Reagenzien bringt.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 2500 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(2500, 'deDE', 'Ah, gut gemacht, $N. Das sollte eine Weile reichen. Hier ist Eure Bezahlung, wie versprochen.$B$BFalls Ihr interessiert seid: Es gibt da noch ein paar Reagenzien mehr, die ich brauchen könnte. Die findet man allerdings nur in den Tiefen der Ausgrabungstätte von Uldaman. Sie werden nicht leicht zu beschaffen sein, aber wenn Ihr mir nochmals helfen wollt, soll es sich für Euch lohnen.$B$BVielleicht möchtet Ihr ja etwas mehr als nur glänzende Münzen, hm?', 0);

-- Quest 17 - add missing data
-- https://de.classic.wowhead.com/quest=17/reagenzsuche-in-uldaman + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 17 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(17, 'deDE', 'Gut gemacht, $N, Ihr habt Euren Wert abermals bewiesen! Die Pilzkappen werden wahrlich ein interessantes Studienobjekt sein!$B$BUnd nun genießt, wie versprochen, eine Kostprobe meines wirksamen Regenerierungsgebräus aus meinem persönlichen Vorrat...$B$BFalls Ihr ein geübter Alchemist seid, ergeben sich für uns vielleicht noch weitere Geschäfte. Ungeachtet dessen danke ich Euch für Eure Hilfe!', 0);

-- Quest 468 - add missing data
-- https://de.classic.wowhead.com/quest=468/meldung-bei-gebirgsjäger-rockgar + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 468 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(468, 'deDE', 'Hallo, $C! Ihr seid wegen der Spähmission hier, stimmt\'s? Sehr gut!$B$BIch hoffe, Eure Ausrüstung ist in gutem Zustand, denn aus dieser "Späh"-Mission ist ein... größerer Schlamassel geworden.', 0);

-- Quest 455 - add missing data
-- https://de.classic.wowhead.com/quest=455/der-algaz-spießrutenlauf + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 455 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(455, 'deDE', 'Euer Bericht enthält viele schlechte Nachrichten!$B$BIch weiß, dass die Orcs des Drachenmalklans verstärkt nach Algaz hineindrängen. Normalerweise verstecken sich die Drachenmalorcs nur oben in den Hügeln. Was sie dazu gebracht hat, nach Algaz hineinzuströmen, ist immer noch ein Rätsel...$B$BDanke, $N. Und wir werden wahrscheinlich Eure Hilfe wünschen, wenn es darum geht, sich um diese Orcs zu kümmern.', 0);

-- Quest 1338 - add missing data
-- https://de.classic.wowhead.com/quest=1338/stormpikes-bestellung + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 1338 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(1338, 'deDE', 'Ein Brief aus dem Zwergenland? Ich frage mich, wer von so weit aus dem Norden kommen mag...$B$BBitte lasst mich die Bestellung sehen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 1338 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(1338, 'deDE', 'Ah, eine Bitte von einem der Sturmlanzen. Das ist ein stolzer Klan erstklassiger Zwerge. Und reich sind sie auch.$B$BDanke, $N. Ich werde noch heute Abend mit der Arbeit am Schild von Gebirgsjäger Sturmlanze beginnen.', 0);

-- Quest 301 - add missing data
-- https://de.classic.wowhead.com/quest=301/meldung-in-ironforge + old GTDB WotLK files
DELETE FROM `quest_request_items_locale` WHERE `ID` = 301 AND `locale` = 'deDE';
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES
(301, 'deDE', 'Wir vom Sturmlanzenklan lassen uns nicht gern von unbedeutenden Angelegenheiten stören, $C. Ich hoffe, Ihr bringt Neuigkeiten, die meine Aufmerksamkeit verdienen.', 0);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 301 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(301, 'deDE', 'Verflucht sei Eisenband! Ich habe ihm schon vor Wochen eine Ladung Sprengpulver geschickt, aber er erwähnt es nicht mal in diesem Bericht.$B$BAlso... wo ist das Sprengpulver hin?!?', 0);

-- Quest 302 - add missing data
-- https://de.classic.wowhead.com/quest=302/pulver-für-ironband + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 302 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(302, 'deDE', 'Was? Sturmlanze will, dass Ihr die Lieferung persönlich zu Eisenband bringt?$B$BIch... denke, das geht in Ordnung, aber das Problem ist, dass ich Huldar bereits mit den Trägern Miran und Saean losgeschickt habe. Ihr habt sie gerade verpasst, sie sind vor einer kurzen Weile erst aufgebrochen.', 0);

-- Quest 273 - add missing data
-- https://de.classic.wowhead.com/quest=273/nachschub-für-die-ausgrabungsstätte + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 273 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(273, 'deDE', 'Hmpf, es wird mehr als einen Überfall durch die Dunkeleisenzwerge brauchen, um die Lieferungen zu stoppen!$B$BAber Saean... Ich hätte nie vermutet, dass er einer ihrer Sympathisanten ist. Wir arbeiten schon seit fast einem Jahr mit ihm zusammen... vielleicht habe ich die Anzeichen übersehen.$B$BNun ja, darüber werde ich später nachdenken.', 0);

-- Quest 454 - add missing data
-- https://de.classic.wowhead.com/quest=454/nach-dem-hinterhalt + old GTDB WotLK files
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 454 AND `locale` = 'deDE';
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES
(454, 'deDE', 'Hallo, $C.$B$BIhr werdet mich zur Ausgrabungsstätte begleiten? Das hört man gern... Wer weiß, was die Dunkeleisenzwerge nach Saean und seinen Spießgesellen noch alles auf Lager haben?$B$BWie auch immer, lasst mich nur noch einige letzte Kontrollen durchführen. Sprecht wieder mit mir, wenn Ihr abreisefertig seid.', 0);
