-- Nagrand -- Nagrand
-- RequestItems, OfferReward -- master, 3.3.5

-- 9789 - Beherrschen der Grollhufjagd
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9789 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9789, "deDE", "Ein akzeptabler Start. Doch das war erst der Anfang.$B$BDie harmloseren Grollhufe beweisen noch gar nichts. Versuchen wir es doch mal mit einer größeren Herausforderung für Euch.", 26972);

-- 9792 - Eine Botschaft für Telaar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9792 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9792, "deDE", "Ikuti ist wie ein Bruder für mich. Seine Freunde sind auch meine Freunde. Ihr seid hier willkommen, $N, und Ihr habt unseren Dank für die Hilfe, die Ihr meinem Volk geleistet habt.", 26972);

-- 9797 - Verstärkung für Garadar
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9797 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9797, "deDE", "<Auch wenn er sich Mühe gibt, es zu verheimlichen, macht sich Erleichterung auf Kroghans Gesicht breit.>$B$BEs wurde auch langsam Zeit, dass Ihr kommt! Sicher, Ihr seid keine Armee, $R, aber hier ist ein jeder willkommen, der Kraft genug besitzt, eine Waffe zu führen oder einen Zauber zu wirken. Die Einwohner Garadars sind ein Teil der Horde und stolz, ihr Blut für deren Verteidigung vergießen zu dürfen.", 26972);

-- 9800 - Eine seltene Bohne
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9800 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9800, "deDE", "<Elementarist Lo'ap ballt seine Hände zu Fäusten und schüttelt den Kopf.>$B$BOgerfäuste...", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9800 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9800, "deDE", "Bitte wascht Euch nicht in den heiligen Wassern des Throns.$B$B<Elementarist Lo'ap reicht Euch eine fertige Caracolitablette.>$B$BLegt sie unter Eure Zunge und lasst sie sich auflösen. Einmal aufgelöst werdet Ihr Wasser wie Luft atmen können.", 26972);

-- 9804 - Aufgebrachte Geister des Himmelsweisensees
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9804 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9804, "deDE", "<Elementarist Lo'ap kniet im Wasser und betet.>$B$BDer Irdene Ring ist nicht stolz auf das, was geschehen ist. Wir tun das, was wir müssen, um das Land zu heilen.", 26972);

-- 9805 - Segen des Incineratus
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9805 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9805, "deDE", "Es beschämt mich, dass mein eigenes Volk die Gewässer in Nagrand beeinflussen möchte, um ein Marschland zu erschaffen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9805 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9805, "deDE", "Eure Bemühungen haben die Ausbreitung der Verschmutzung eingedämmt, aber nun sind neue Probleme aufgetaucht.", 26972);

-- 9810 - Der verschmutzte Geist
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9810 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9810, "deDE", "Die Elemente haben Euren Sieg besungen, als Ihr die verschmutzte Essenz getötet habt. Der Irdene Ring dankt Euch und möchte, dass Ihr Euch eine Belohnung aussucht.", 26972);

-- 9815 - Schlammtauchen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9815 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9815, "deDE", "Lasst keinen verseuchten Schlamm zurück!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9815 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9815, "deDE", "Der Irdene Ring dankt Euch, $N. Auch die Elemente sind Euch dankbar. Eure wiederholten Bemühungen, unsere Welt zu reinigen, werden sehr geschätzt und sicher nicht vergessen.", 26972);

-- 9818 - Im Untergrund
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9818 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9818, "deDE", "<Gordawg scheint Euch zuzunicken.>$B$BSetzt Euch.", 26972);

-- 9819 - Die gequälte Erde
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9819 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9819, "deDE", "<Gordawg nickt zufrieden.>$B$BGut. Geister schlafen jetzt.", 26972);

-- 9821 - Verdammnis schmecken
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9821 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9821, "deDE", "Gordawg isst den Stein. Gordawg findet den Thronräuber. Bringt Stein!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9821 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9821, "deDE", "<Gordawg spuckt den gekauten Stein aus, woraufhin ein Steinschauer auf Euch herabrieselt.>$B$BGift. Diese Felsen sind nicht Nagrand. Diese Felsen sind vergiftet. Ihr zerstört Giftfels. Ihr findet Thronräuber.", 26972);

-- 9849 - Die Maskerade durchschauen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9849 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9849, "deDE", "Gordawg will den Stein zurück.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9849 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9849, "deDE", "GUROK! Gurok hat die Elemente verraten!", 26972);

-- 9850 - Beherrschen der Grollhufjagd
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9850 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9850, "deDE", "Beeindruckend, sehr beeindruckend.$B$BIhr habt Potenzial, Jungspund. Ich werde Euch die Möglichkeit geben, richtig viel Spaß zu haben.", 26972);

-- 9851 - Beherrschen der Grollhufjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9851 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9851, "deDE", "Ein warmes Feuer und eine Frau an Eurer Seite könnt Ihr daheim finden. Hier jagen wir ernsthaft oder sterben bei dem Versuch.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9851 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9851, "deDE", "Ihr habt es tatsächlich geschafft! Ihr habt Banthar erlegt! Ich habe niemals an Euch gezweifelt, $N.$B$BHier, ich denke, das habt Ihr Euch redlich verdient.", 26972);

-- 9852 - Die ultimative Beute
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9852 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9852, "deDE", "Es ist keine Schande zuzugeben, dass Ihr nicht den Mumm habt, eines der mächtigsten Tiere die dieses Land zu bieten hat, zu erlegen, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9852 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9852, "deDE", "$N! Ihr bringt das Herz dieses alten Zwergs zum Springen.$B$BIhr habt Euch nun bewiesen und seid in die Eliteränge aufgestiegen! Andere sind voller Angst geflüchtet, sind gestorben oder wurden unter den Füßen des Tieres zerquetscht. Ihr habt Euren Verstand, Eure List und Eure Entschlossenheit genutzt, um zu beweisen, dass Ihr die Jagd beherrscht.$B$BNehmt dies und seid gewiss, dass Ihr jederzeit zur Jagd an meiner Seite willkommen seid.", 26972);

-- 9853 - Gurok der Thronräuber
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9853 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9853, "deDE", "Gordawg isst Gurokpulver.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9853 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9853, "deDE", "<Gordawg beißt fest in Guroks irdenen Kopf und bringt die Steinformation fast zum Bröckeln.>$B$BGuroks Herrschaft ist zu Ende. Die Erdelementare sind frei. Schlafen alle. Gewinner bekommt Preis!", 26972);

-- 9854 - Beherrschen der Windrocjagd
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9854 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9854, "deDE", "Jeder Tag ist ein Geschenk. Macht das Beste daraus. Denn schon morgen werden wir uns schneller fortbewegen als heute. Wir werden unsere Arme weiter ausbreiten und uns anstrengen, um das zu erzielen, von dem wir heute Nacht noch träumen, auch wenn wir es vielleicht nie erreichen können.", 26972);

-- 9855 - Beherrschen der Windrocjagd
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9855 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9855, "deDE", "Ihr habt Eure Fähigkeiten erneut unter Beweis gestellt, $C. Jetzt müsst Ihr Euch mit der wildesten Sorte von Windrocs messen.", 26972);

-- 9856 - Beherrschen der Windrocjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9856 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9856, "deDE", "Habt Ihr Euch Aaskralle schon gestellt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9856 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9856, "deDE", "Ihr Auge sieht aus, als wäre es noch am Leben. Denkt Ihr, sie kann immer noch in Eure Seele schauen?$B$B$N, Ihr könnt Euch zu den Elitesafarijägern zählen. Und Ihr seid auf dem besten Weg, die entscheidende Beute dieses Landes zu jagen, Zahna!$B$BIhr habt Euch das hier verdient. Möge es Euch gute Dienste leisten.", 26972);

-- 9857 - Beherrschen der Talbukjagd
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9857 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9857, "deDE", "Das ist schon eine tolle Geschichte...<hust>...wie Ihr all die Hirsche erlegt habt, $C. Aber das könnt Ihr sicher noch besser. Ich habe da etwas anderes für Euch im Auge.", 26972);

-- 9858 - Beherrschen der Talbukjagd
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9858 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9858, "deDE", "<hust>, <hust>... $N! Ihr habt es geschafft. Jetzt gibt es... ...nur noch eine Sache......zu tun.", 26972);

-- 9859 - Beherrschen der Talbukjagd
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9859 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9859, "deDE", "<Harold schaut geschwächt zu Euch hoch und ringt sich ein Lächeln ab.>$B$BHabt Ihr...<hust>... den Huf?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9859 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9859, "deDE", "Wow! Ihr habt es geschafft! Das ist tatsächlich Bach'lors Huf!$B$BÄhm, wie es aussieht fühle ich mich schon viel besser. Hier, lasst mich Euch etwas zur Feier Eures Jägerkönnens schenken!", 26972);

-- 9861 - Der heulende Wind
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9861 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9861, "deDE", "Gebt es her, schnell!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9861 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9861, "deDE", "Es ist ein Notruf, $R. Eine Macht versucht die Elemente zu untergraben.", 26972);

-- 9862 - Bösewichte der Finsterblut
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9862 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9862, "deDE", "Ihr habt gesehen, wie sie die Elemente kontrollieren? Der Wind beugt sich ihrem Willen?$B$B<Morgh versinkt für einen Moment in Gedanken.>$B$BDas ist sehr beunruhigend, $N. Ich muss mich mit den anderen beraten.$B$BVielen Dank für Eure Mühen, $N. Vielleicht solltet Ihr in Euer Dorf zurückkehren und Euch umhören, ob es weitere Informationen über die Finsterblut und ihre schändlichen Ziele gibt.", 26972);

-- 9863 - Abscheulicher Götzendienst
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9863 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9863, "deDE", "Tut es für uns, weil wir es nicht für uns selbst tun können.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9863 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9863, "deDE", "Ihr habt den Söhnen des Blitzschlags neue Hoffnung gegeben, $N. Wenn unser Anführer uns schon nicht beschützt, vielleicht können es andere tun - so wie Ihr.", 26972);

-- 9864 - Der verschollene Kampftrupp
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9864 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9864, "deDE", "Ich habe Geschichten über unser Volk gehört. Sie sagen, dass wir einst Krieger waren...", 26972);

-- 9865 - Chroniken eines Kriegers
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9865 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9865, "deDE", "<Saurfang dreht sich zu Euch um.>$B$BRieche ich da etwa Blut? Ich bedauere es sehr, dass ich Euch nicht helfen konnte. Wie stolz Ihr auf Euch sein müsst. Meine Brust hebt sich allein von dem Wissen, was Ihr getan habt.$B$BGibt es noch mehr wie Euch? Gibt es noch mehr Helden dort, wo Ihr herkommt?", 26972);

-- 9866 - Weiter...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9866 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9866, "deDE", "<Scharfseher Corhuk starrt gedankenverloren auf den Boden. Er nickt zustimmend.>$B$B<Scharfseher Corhuk wischt sich eine Träne aus dem Gesicht.>$B$BDer Sohn ist der Vater... Mögen die Geister gnädig zu denen sein, die ihm im Weg stehen.", 26972);

-- 9867 - Anführer der Finsterblut...
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9867 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9867, "deDE", "Bringt mir den Kopf ihres Anführers, $N.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9867 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9867, "deDE", "Das ist also das Gesicht unseres Feindes? Ich werde den Kopf aufspießen lassen und außerhalb von Garadar aufstellen. Sollten sie je wagen, uns nochmals anzugreifen, werden sie den Folgen ihres Handelns in die Augen sehen müssen.", 26972);

-- 9868 - Das Totem von Kar'dash
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9868 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9868, "deDE", "Was macht das schon? Die Großmutter liegt im Sterben. Das Leben ist nicht lebenswert...", 26972);

-- 9869 - Der Thron der Elemente
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9869 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9869, "deDE", "Ah, danke für diese Nachricht. Hättet ihr vielleicht etwas dagegen, dem Irdenen Ring zu helfen? Die Elemente sind sehr aufgewühlt, wir können alle Hilfe, die wir bekommen können, brauchen.", 26972);

-- 9870 - Der Thron der Elemente
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9870 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9870, "deDE", "Ah, danke für diese Nachricht. Hättet ihr vielleicht etwas dagegen, dem Irdenen Ring zu helfen? Die Elemente sind sehr aufgewühlt, wir können alle Hilfe, die wir bekommen können, brauchen.", 26972);

-- 9871 - Eindringlinge der Finsterblut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9871 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9871, "deDE", "Was gibt's?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9871 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9871, "deDE", "<Arechron schlägt mit der einen Hand in die andere.>$B$BOrtor... Dieser verräterische Dreckskerl!", 26972);

-- 9872 - Eindringlinge der Finsterblut
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9872 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9872, "deDE", "Was gibt es?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9872 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9872, "deDE", "<Garrosh zerknüllt die Karte und wirft sie ins Feuer.>$B$BWas soll ich damit? Sie greifen uns schon seit Wochen an. Das ist nichts neues.$B$BVersteht Ihr nicht? Wir sind geliefert... Großmutter Geyah liegt im Sterben.", 26972);

-- 9873 - Mein alter Freund Ortor...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9873 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9873, "deDE", "Tausend tote Orcs sagt Ihr? Was könnte wohl der Auslöser für solch ein unverfrorenes Vordringen in Orcgebiet sein? Es ist gut, dass er tot ist, aber da steckt mehr dahinter, als ein Tentakel fühlen kann.", 26972);

-- 9874 - Die Ausbreitung eindämmen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9874 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9874, "deDE", "Die Orcs werden nicht verstehen, warum wir das tun, aber es muss getan werden. Für das Wohl der Orcs sowie der Zerschlagenen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9874 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9874, "deDE", "<Otonbu seufzt.>$B$BDas macht uns jegliche Hoffnung auf Frieden mit den Orcs für weitere zehn Jahre zunichte. Zumindest werden wir diese zehn Jahre noch erleben, was wir vielleicht nicht hätten, wenn die Leichen im See verrottet wären.", 26972);

-- 9878 - Die Lösung des Problems
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9878 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9878, "deDE", "Ich glaube kaum, dass die Orcs verstehen oder zu schätzen wissen, was Ihr da getan habt, aber Eure Tat war gut für Nagrand. Vielen Dank, Problemlöser...", 26972);

-- 9879 - Das Totem von Kar'dash
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9879 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9879, "deDE", "Ja, ich weiß von dem Totem... aber es gehört noch viel mehr zu dieser Geschichte. Ich darf Euch jedoch nichts darüber erzählen. Nur Auserwählte haben Zugang zu solchem Wissen.", 26972);

-- 9882 - Von Dieben stehlen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9882 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9882, "deDE", "Habt Ihr die Kristallfragmente bekommen, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9882 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9882, "deDE", "Ich bin beeindruckt. Die meisten sind in ausgezeichnetem Zustand.$B$BIch werde bei unserem Volk ein gutes Wort für Euch einlegen.", 26972);

-- 9883 - Noch mehr Kristallfragmente
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9883 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9883, "deDE", "Ihr habt noch mehr Kristallfragmente? Nehmt aber bitte keine, die noch mit dem Berg verbunden sind. Wir wollen keinen Ärger mit den Naaru.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9883 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9883, "deDE", "Bringt mir ruhig weiter Kristalle, $N. Wir können nicht zulassen, dass diese Diebe unser Eigentum stehlen.$B$BAuch wenn es eigentlich noch gar nicht unseres ist. Theoretisch natürlich.", 26972);

-- 9884 - Mitgliedervorteil
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9884 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9884, "deDE", "Das Konsortium ist dafür bekannt, dass es sich gut um seine Freunde kümmert. Zu Beginn jeden Monats werde ich Euch ein paar Edelsteine als Bezahlung für Eure Dienste geben.$B$BDie Qualität der Steine hängt davon ab, wie treu ergeben Ihr uns wart. Lasst uns also hoffen, dass Ihr das Richtige tut und bei uns bleibt.", 26972);

-- 9885 - Mitgliedervorteil
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9885 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9885, "deDE", "Schön Euch wiederzusehen, $N. Ich habe Eure Edelsteine für diesen Monat fertig.$B$BIch habe Euch ein paar mehr dazugetan, damit Ihr wisst wie froh wir sind, Euch bei uns zu haben.", 26972);

-- 9886 - Mitgliedervorteil
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9886 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9886, "deDE", "Das Konsortium ist dafür bekannt, dass es sich gut um seine Freunde kümmert. Zu Beginn jeden Monats werde ich Euch ein paar Edelsteine als Bezahlung für Eure Dienste geben.$B$BDie Qualität der Steine hängt davon ab, wie treu ergeben Ihr uns wart. Lasst uns also hoffen, dass Ihr das Richtige tut und bei uns bleibt.", 26972);

-- 9887 - Mitgliedervorteil
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9887 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9887, "deDE", "Das Konsortium ist dafür bekannt, dass es sich gut um seine Freunde kümmert. Zu Beginn jeden Monats werde ich Euch ein paar Edelsteine als Bezahlung für Eure Dienste geben.$B$BDie Qualität der Steine hängt davon ab, wie treu ergeben Ihr uns wart. Lasst uns also hoffen, dass Ihr das Richtige tut und bei uns bleibt.", 26972);

-- 9888 - Der unfähige Anführer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9888 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9888, "deDE", "<Kilrath flüstert.>$B$BDiese Oger sind extrem sonderbar. Und auch extrem dumm. Schaut nur, wie der fette den, äh, weniger fetten zum Tanzen zwingt. Es ist faszinierend.", 26972);

-- 9889 - Nicht den Fetten töten!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9889 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9889, "deDE", "Lasst mich leben und ich sage Euch alles, was Ihr wissen wollt!", 26972);

-- 9890 - Erfolg!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9890 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9890, "deDE", "Ganz ruhig, $N. Ich bin nur ein kleiner $C. Ich habe keine Ahnung, was ich mit solch einer Information anfangen soll.", 26972);

-- 9891 - Weil Kilrath ein Feigling ist
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9891 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9891, "deDE", "Sie denken also, dass sie uns Orcs nach Lust und Laune vertreiben und abschlachten können, was? Ich bin mir sicher, dass das nichts damit zu tun hat, dass unser Anführer ein unfähiger Jammerlappen ist... Wenn er doch nur einen Bruchteil der Leidenschaft seines Vaters geerbt hätte...", 26972);

-- 9892 - Noch mehr Obsidiankriegsperlen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9892 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9892, "deDE", "Habt Ihr noch mehr Kriegsperlen? Ihr findet genügend Oger weit im Norden, an der Grenze zu den Zangarmarschen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9892 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9892, "deDE", "Wir werden gut an diesen Perlen verdienen, $N. Ich werde Khoraazi ganz sicher von Eurer Arbeit hier erzählen.", 26972);

-- 9893 - Obsidiankriegsperlen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9893 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9893, "deDE", "Wie führen die Oger sich auf, $N? Harte Nuss, was?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9893 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9893, "deDE", "Ausgezeichnet. Das wird uns über Wasser halten bis die Sha'tar fertig sind mit was immer sie auch im Oshu'gun tun mögen.", 26972);

-- 9897 - Ich bin gerettet!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9897 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9897, "deDE", "Es ist sehr...<hust>...nett von Kristen, dass sie ihre Tierhäute teilt, meint Ihr nicht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9897 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9897, "deDE", "Nun, ich konnte nicht wissen, ob Ihr Kristen helfen konntet oder nicht. Aber wenn sie Euch eines ihrer Bündel mit Tierhäuten gegeben hat, müsst Ihr wohl in Ordnung sein.$B$BHier ist Eure Belohnung.", 26972);

-- 9900 - Gava'xi
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9900 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9900, "deDE", "Dank Euch müssen wir uns nun nicht mehr vor Gava'xi fürchten. Wollen wir uns nun um eure Belohnung kümmern.", 26972);

-- 9906 - Sag's mit Fäusten
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9906 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9906, "deDE", "Unser Auftrag ist noch nicht zu Ende. Es gibt noch andere, die einer Lektion bedürfen!", 26972);

-- 9907 - Ein kühner Angriff
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9907 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9907, "deDE", "Wenn dies das Blut in ihren Adern nicht zum Gefrieren bringt, dann wird es nichts schaffen. Ihr habt den Mag'har zu Gerechtigkeit verholfen, $N. Und für Gerechtigkeit zahlen die Mag'har gut.", 26972);

-- 9910 - Standarten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9910 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9910, "deDE", "Ehrfurcht aus Angst! Das ist so gut wie jeder andere Grund.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9910 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9910, "deDE", "Vielleicht wollt Ihr noch eine andere Aufgabe? Eine etwas heiklere?", 26972);

-- 9913 - Das Konsortium braucht Euch!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9913 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9913, "deDE", "Seid Ihr bereit für ein wenig Arbeit, $R? Ich habe die perfekte Aufgabe für Euch.", 26972);

-- 9914 - Ein ganzer Kopf voll Elfenbein
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9914 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9914, "deDE", "Ich brauche Elfenbein, keine Entschuldigungen. Wir können natürlich Euren Anteil am Gewinn neu verhandeln. Ich glaube aber kaum, dass Ihr mit dem Ergebnis zufrieden sein werdet.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9914 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9914, "deDE", "Ich habe keine Sekunde an Euch gezweifelt, mein Freund. Die meisten hiervon sehen gut aus. Ein bisschen dreckig und verkratzt vielleicht. Aber ich denke, sie sind den Preis, den wir vereinbart hatten, wert.$B$BIch hoffe, das wir auch in Zukunft ins Geschäft kommen.", 26972);

-- 9915 - Noch mehr Elfenbein
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9915 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9915, "deDE", "Ich habe immer noch Bedarf an Elfenbeinstoßzähnen von den wilden Elekk in Nagrand. Unglücklicherweise kann ich es mir nicht mehr leisten, Euch dafür zu bezahlen.$BWenn Ihr mir aber trotzdem weiter Stoßzähne bringt, werdet Ihr Euch beim Konsortium sehr beliebt machen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9915 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9915, "deDE", "Ausgezeichnet, noch mehr hochwertige Stoßzähne. Auch wenn ein paar davon etwas schäbig aussehen.$B$BIhr habt den Dank des Konsortiums, $N.", 26972);

-- 9916 - Vorratskisten des Blutenden Auges
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9916 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9916, "deDE", "Vielleicht können unserer Kinder eines Tages ohne Hunger leben.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9916 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9916, "deDE", "Die meisten unserer Besitztümer wurden bei Angriffen zerstört oder gestohlen. Ich kann euch nicht viel bieten, aber hier sind ein paar Dinge, die Ihr vielleicht als nützlich empfinden könntet.", 26972);

-- 9917 - Kann ich meinen Augen trauen?
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9917 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9917, "deDE", "Habt Ihr Neuigkeiten erfahren?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9917 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9917, "deDE", "<Bintook liest die Pläne.>$B$BBEIM LICHT! Diese Handschrift ist grauenvoll! So wie ich das sehe, planen sie \"die blauen Häute zu essen und ihr Dorf einzunehmen\" oder einen Blaubeerkuchen zu backen. Es könnte wirklich beides heißen. Wir müssen der Sache auf den Grund gehen!", 26972);

-- 9918 - Nicht solange ich hier wache!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9918 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9918, "deDE", "Oh je, das war nur eine kleine Jagdgesellschaft? Ihr müsst Mo'mor erzählen, was Ihr herausgefunden habt!", 26972);

-- 9920 - Mo'mor der Brecher
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9920 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9920, "deDE", "<Mo'mor schaut verdutzt drein.>$B$BEin neuer Ogerstamm drängt die Felsfäuste immer weiter nach Süden? Das klingt beunruhigend. Wir müssen mit der Situation in der Nähe unseres Zuhauses fertigwerden...", 26972);

-- 9921 - Die Ruinen der Brennenden Klinge
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9921 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9921, "deDE", "Ausgezeichnet. Konntet Ihr diesen Lantresor, der in dem Brief dieses Dummkopfs erwähnt wurde, ausfindig machen?$B$BEgal, wir müssen weitermachen. Ich habe Berichte über weitere Ogeraktivitäten erhalten, um die sich sofort jemand kümmern muss!", 26972);

-- 9922 - Die Zwillingsschluchten von Nagrand
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9922 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9922, "deDE", "Ausgezeichnete Arbeit! Ich stelle im Augenblick Nachforschungen über den Totschlägerstamm an, den der Leutnant der Felsfäuste erwähnt hat. Jetzt müssen die Aufgaben, die Ihr erledigt habt, getestet werden.", 26972);

-- 9923 - HILFE!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9923 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9923, "deDE", "Es tut mir wirklich sehr leid, $R. Er gerät immer in Schwierigkeiten. Manchmal wünschte ich, ich könnte ihn anleinen...", 26972);

-- 9924 - Corki wird schon wieder vermisst!
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9924 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9924, "deDE", "Ich bin Euch so dankbar, $N. Seine Mutter wird sich in Zukunft um ihn kümmern.", 26972);

-- 9925 - Eine Frage der Sicherheit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9925 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9925, "deDE", "Ihr zaubert ein Lächeln auf mein Gesicht, $N. Zumindest würdet Ihr das, wenn ich noch ein Gesicht hätte.$B$BWenn Ihr so weiter macht werden wir noch beste Freunde.", 26972);

-- 9927 - Erbarmungslose Gerissenheit
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9927 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9927, "deDE", "<Lantresor schaut Euch entgeistert an.>$B$BSchon fertig?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9927 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9927, "deDE", "Könnt Ihr Euch vorstellen, wie verwirrt sie darüber sein werden, $R? Das wird wundervoll.", 26972);

-- 9928 - Waffen zur Täuschung
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9928 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9928, "deDE", "Wir werden einen nie dagewesenen Hass zwischen den beiden Klans säen!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9928 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9928, "deDE", "Ausgezeichnet! Unser nächstes Ziel sind die Ruinen des Lachenden Schädels.", 26972);

-- 9931 - Sich für den Gefallen revanchieren
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9931 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9931, "deDE", "Könnt Ihr vorhersehen, was als Nächstes geschieht?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9931 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9931, "deDE", "Der Plan ist perfekt, $N. Ich sehe jetzt schon die Früchte unserer Arbeit.", 26972);

-- 9932 - Beweismaterial
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9932 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9932, "deDE", "Wisst Ihr nun, warum Ihr nie einen Krieg gegen mich gewinnen würdet?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9932 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9932, "deDE", "Ich muss zugeben, dass ich mich seit Jahrzehnten nicht mehr so lebendig gefühlt habe. Ihr habt gute Arbeit geleistet, $N.", 26972);

-- 9933 - Nachricht für Telaar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9933 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9933, "deDE", "Frieden sagt Ihr?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9933 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9933, "deDE", "Bitte, $N, nehmt Euch von diesem Friedensangebot was immer Ihr möchtet. Schließlich wäre dies ohne Eure Hilfe niemals möglich gewesen.", 26972);

-- 9934 - Nachricht für Garadar
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9934 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9934, "deDE", "<Garrosh scheint von dem Angebot unbeeindruckt zu sein.>", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9934 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9934, "deDE", "<Garrosh tritt die Kiste um.>$B$BIhr verschwendet Eure Zeit, $R. Nehmt Euch aus der Kiste was immer Ihr wollt. Weder ich noch Garadar haben für diesen unnützen Tand Verwendung.", 26972);

-- 9935 - GESUCHT: Giselda die Alte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9935 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9935, "deDE", "Die Alte ist tot! Das sind wundervolle Nachrichten, $N. Hier ist Eure Belohnung.", 26972);

-- 9936 - GESUCHT: Giselda die Alte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9936 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9936, "deDE", "Die Alte ist tot! Das sind wundervolle Nachrichten, $N. Hier ist Eure Belohnung.", 26972);

-- 9937 - GESUCHT: Durn der Nimmersatte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9937 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9937, "deDE", "Durns tödlicher Griff wurde gelöst! Nagrand schaut Dank Euch auf eine bessere Zukunft, Held. Gut gemacht!", 26972);

-- 9938 - GESUCHT: Durn der Nimmersatte
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9938 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9938, "deDE", "Durns tödlicher Griff wurde gelöst! Nagrand schaut Dank Euch auf eine bessere Zukunft, Held. Gut gemacht!", 26972);

-- 9939 - GESUCHT: Zorbo der Berater
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9939 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9939, "deDE", "Dies ist ein großer Sieg für die Bewohner von Garadar! Gut gemacht, $N!", 26972);

-- 9940 - GESUCHT: Zorbo der Berater
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9940 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9940, "deDE", "Dies ist ein großer Sieg für die Bewohner von Telaar! Gut gemacht, $N!", 26972);

-- 9944 - Verschollene mag'harische Prozession
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9944 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9944, "deDE", "Dreißig Orcs, $R! Von diesen dreißig sind nur noch Ungriz und ich übrig. Wir haben den jungen Orc, Saurfang, halb tot in der Nähe von Sonnenwind gefunden. Offensichtlich ist er aus einem anderen Grund hier...", 26972);

-- 9945 - Krieg den Totschlägern
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9945 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9945, "deDE", "Das ist ein guter Anfang, aber ihr Anführer muss getötet werden, damit Eure Taten auch langfristige Erfolge erzielen können.", 26972);

-- 9946 - Cho'war der Plünderer
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9946 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9946, "deDE", "Er ist sicher sehr schwer bewacht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9946 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9946, "deDE", "Diesen Kopf stellen wir an dem Toren von Garadar auf, damit alle ihn sehen können. Die Oger werden es sich zweimal überlegen, bevor sie heilige Rituale der Mag'har stören.", 26972);

-- 9948 - Findet die Überlebenden
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9948 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9948, "deDE", "Ihr habt geschafft, was keiner für möglich hielt und unsere vermissten Brüder und Schwestern zurückgebracht. Für die Mag'har seid Ihr ein Held, $N. Alle werden Euren Namen kennen und wissen, was Ihr für uns getan habt.", 26972);

-- 9954 - Corkis Lösegeld
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9954 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9954, "deDE", "Diesmal haben sie mich gut eingesperrt, $N. Der König der Totschläger, Cho'war, hat den Schlüssel.", 26972);

-- 9955 - Cho'war der Plünderer
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9955 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9955, "deDE", "Danke, $N. Ich habe Corki zu den Nachtelfen im Schergrat geschickt. Hoffentlich gelingt es ihnen, ihn vom Ärger fern zu halten.$B$BWegen der Belohnung...", 26972);

-- 9956 - Die Überfallene Karawane
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9956 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9956, "deDE", "Ich komme mir so dumm vor. Archerons Sohn, Corki, hat mich gefragt, was los ist, und ich habe es ihm gesagt. Jetzt ist er schon wieder verschwunden!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9956 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9956, "deDE", "Erstaunlich! Wie habt Ihr es geschafft, all das alleine zurückzutragen?", 26972);

-- 9962 - Der Ring des Blutes: Schmetterzehe
DELETE FROM `quest_request_items_locale` WHERE `ID` = 9962 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (9962, "deDE", "Der Kampf ist vorüber, wenn Ihr oder Euer Gegner tot zu Boden geht.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9962 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9962, "deDE", "Hm, nicht schlecht. Gar nicht schlecht... Ihr habt Potenzial, Kleiner. Hier habt Ihr etwas Gold für Eure Taschen.", 26972);

-- 9967 - Der Ring des Blutes: Die Blaumänner
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9967 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9967, "deDE", "Ich gebe zu, dass ich nicht geglaubt habe, dass Ihr eine Chance hättet, $N! Das war beeindruckend! Wie wär's mit einem weiteren Kampf? Gurgthock hat den perfekten Gegner für Euch.", 26972);

-- 9970 - Der Ring des Blutes: Rokdar der Zerklüftete
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9970 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9970, "deDE", "Ihr habt die Oger zum Schwitzen gebracht, Kleiner. Diesmal bekommt Ihr noch etwas dazu. Benutzt nicht alles auf einmal!$B$BSeid Ihr bereit für einen weiteren Kampf? Gurgthock setzt die ganze Bank auf Euch!", 26972);

-- 9972 - Der Ring des Blutes: Skra'gath
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9972 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9972, "deDE", "KLEINER! KLEINER IHR HABT ES GESCHAFFT! Als nächstes kommt der große Kampf! Die Meisterschaft!$B$BOk, locker bleiben. Wir wollen ja nicht, dass die Oger erfahren, dass hier was im Busch ist. Schließlich bekomme ich ja auch meinen Anteil daran.", 26972);

-- 9973 - Der Ring des Blutes: Champion der Totschläger
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9973 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9973, "deDE", "Oh je, Mogor hat sein Kampfrecht als Held der Totschläger eingefordert. Ihr müsst gegen ihn kämpfen!$B$BNiemand hat je behauptet, dass die Totschläger gute Verlierer... äh... Oger wären.", 26972);

-- 9977 - Der Ring des Blutes: Die letzte Herausforderung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9977 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9977, "deDE", "Gurthock hat doch gesagt, dass es sich bezahlt machen wird, Kleiner. Sucht Euch was aus!", 26972);

-- 9982 - Er nannte sich Altruis...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9982 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9982, "deDE", "Überrascht Euch mein Aussehen? Wisst Ihr, was ich bin?", 26972);

-- 9983 - Er nannte sich Altruis...
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9983 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9983, "deDE", "Überrascht Euch mein Aussehen? Wisst Ihr, was ich bin?", 26972);

-- 9991 - Inspektion des Lagers
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9991 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9991, "deDE", "Ausgezeichnete Arbeit, $N! Jetzt haben wir einen Ausgangspunkt um unseren Gegenangriff zu planen.", 26972);

-- 9999 - Spiel auf Zeit
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 9999 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (9999, "deDE", "Wie ich es mir dachte. Es gibt keinen normalen Weg, Teufelsstahl zu zerstören. Es ist aber noch nicht alles verloren...", 26972);

-- 10001 - Der Meisterplaner
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10001 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10001, "deDE", "Bleibt auf jeden Fall von den Vorarbeitern fern. Sie dürfen nichts von Eurer Anwesenheit mitbekommen. Die Folgen könnten verheerend sein!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10001 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10001, "deDE", "Mein Bekannter kennt hoffentlich einen Weg, die Lager zu zerstören. Er war schließlich mal ein Ingenieur der Legion...", 26972);

-- 10004 - Geduld und Verständnis
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10004 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10004, "deDE", "<Sal'salabim kratzt sich am Kopf.>$B$B[Dämonisch] Ik il romath sardon.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10004 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10004, "deDE", "Beruhigt Euch, Schätzchen, Sal'salabim wird helfen.", 26972);

-- 10009 - Ein paar Schädel spalten
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10009 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10009, "deDE", "Ihr ja nicht kommen zurück ohne Sal'salabims Gold!", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10009 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10009, "deDE", "Nun, Geschäft sein Geschäft, aber wenn Sal'salabim Euch sagen, Ihr nicht böse werden, ja?", 26972);

-- 10010 - So einfach ist das?
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10010 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10010, "deDE", "Natürlich! Wir werden sie mit ihren eigenen Waffen schlagen!", 26972);

-- 10011 - Konstruktionslager: zerstört
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10011 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10011, "deDE", "Wir haben gesiegt! Das Vorrücken der Legion wurde gebremst!$B$BIch biete Euch eine Auswahl an Belohnungen für Eure heldenhaften Taten!", 26972);

-- 10044 - Ein Besuch bei der Großmutter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10044 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10044, "deDE", "Wir müssen zuerst Euren Geist erweitern, damit Ihr mit den Ahnen sprechen könnt.", 26972);

-- 10045 - Zutaten sammeln
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10045 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10045, "deDE", "Hallo, Kind.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10045 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10045, "deDE", "Ihr seid sehr geschickt, $N. Unsere besten Kräutersammler hätten doppelt so lange gebraucht, um die Kräuter zu sammeln.$B$B$B$BHabt keine Angst.", 26972);

-- 10074 - Kristallpulver von Oshu'gun
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10074 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10074, "deDE", "Der Erdkern dieser Gegend ist vom Kristallpulver des Bergs durchdrungen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10074 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10074, "deDE", "Wundervoll, $N. Das wird uns in unserem Kampf gegen den Abschaum der Allianz helfen, der sich hier in der Scherbenwelt breitgemacht hat.", 26972);

-- 10075 - Kristallpulver von Oshu'gun
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10075 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10075, "deDE", "Dieser Stützpunkt war die erste Forschungseinrichtung für die Untersuchung von Naarukristallen.$B$BWir haben hier eine wahre Goldgrube an Forschungsunterlagen über die Kristalle des \"diamantenen\" Bergs, Oshu'gun, gefunden. Wie es scheint, ist überall in diesem Gebiet etwas von der übrig gebliebenen Macht der Kristalle von Oshu'gun enthalten. Wenn Ihr während Euren Abenteuern in diesem Gebiet Kristallpulver finden solltet, bringt es zu mir, und ich werde Euch ein Zeichen meiner Wertschätzung geben, dass Ihr bei den Rüstmeistern eintauschen könnt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10075 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10075, "deDE", "Ich danke Euch für Euren Beitrag, <Name>. Wenn Ihr noch mehr finden solltet, wisst Ihr, wo Ihr sie hinbringen könnt.", 26972);

-- 10076 - Kristallpulver von Oshu'gun
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10076 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10076, "deDE", "Das Kristallpulver des Bergs ist vom Erdenkern dieser Gegend durchdrungen.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10076 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10076, "deDE", "Wundervoll, $N. Das wird uns in unserem Kampf gegen den Abschaum der Horde helfen, der sich hier in der Scherbenwelt breitgemacht hat.", 26972);

-- 10077 - Kristallpulver von Oshu'gun
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10077 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10077, "deDE", "Dieser Stützpunkt war die erste Forschungseinrichtung für die Untersuchung von Naarukristallen.$B$BWir haben hier eine wahre Goldgrube an Forschungsunterlagen über die Kristalle des \"diamantenen\" Bergs, Oshu'gun, gefunden. Wie es scheint, ist überall in diesem Gebiet etwas von der übrig gebliebenen Macht der Kristalle von Oshu'gun enthalten. Wenn Ihr während Euren Abenteuern in diesem Gebiet Kristallpulver finden solltet, bringt es zu mir, und ich werde Euch ein Zeichen meiner Wertschätzung geben, dass Ihr bei den Rüstmeistern eintauschen könnt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10077 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10077, "deDE", "Ich danke Euch für Euren Beitrag, <Name>. Wenn Ihr noch mehr finden solltet, wisst Ihr, wo Ihr sie hinbringen könnt.", 26972);

-- 10081 - Mutter Kashur treffen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10081 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10081, "deDE", "Der Trank, den Ihr zu Euch genommen habt, hat keine echte Wirkung. Ihr könnt einen Geist nur sehen, wenn er es zulässt. Der Trank ist nur ein Symbol Eures Glaubens und Eurer Hingabe. Es war ein Test. Und Ihr habt ihn bestanden...", 26972);

-- 10082 - Die aufgebrachten Ahnen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10082 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10082, "deDE", "Es ergibt keinen Sinn. Sie erheben sich weiter. Es muss etwas Heimtückischeres dahinter stecken.", 26972);

-- 10085 - Ein Besuch bei den Ahnen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10085 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10085, "deDE", "Das ist sehr beunruhigend. Ihr sagt, keiner der Ahnen war in seinem Dorf? Sie gehen alle nach Süden?", 26972);

-- 10101 - Wenn Geister sprechen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10101 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10101, "deDE", "<Eine sanfte, melodische Stimme erklingt in Eurem Kopf.> Ich bin K'ure von den Naaru, $N. Ihr steht hier im Herzen meines alten Schiffs.$B$BOshu'gun, wie die Orcs es genannt haben, ist das Schiff, mit dem die Draenei zuerst auf diese Welt gekommen sind. Obwohl wir schon vor hunderten von Jahren hier vom Himmel gefallen und abgestürzt sind, sind meine Energien immer noch in diesen Trümmern gefangen. Leider bin ich der Grund für die Schmerzen der Orcgeister.", 26972);

-- 10102 - Ein gelüftetes Geheimnis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10102 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10102, "deDE", "Es war weise von K'ure, Euch hierherzuschicken. Wir können das Leiden der Orcahnen nicht lindern, doch es gibt einen, der es kann.$B$BEinen, der bald im Licht wiedergeboren wird...", 26972);

-- 10107 - Diplomatische Maßnahmen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10107 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10107, "deDE", "Wie also lautet Eure Entscheidung? Soll es Krieg geben, oder werdet Ihr mich unterstützen?", 26972);

-- 10108 - Diplomatische Maßnahmen
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10108 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10108, "deDE", "Wie also lautet Eure Entscheidung? Soll es Krieg geben, oder werdet Ihr mich unterstützen?", 26972);

-- 10109 - Ich muss sie haben!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10109 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10109, "deDE", "Habt Ihr das Gas?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10109 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10109, "deDE", "Ausgezeichnet! Nur ein paar kleine Einstellungen und dieses Ding ist so gut wie neu. Oh richtig, Euer Schlüssel! Bitte sehr.$B$BDer Spring-o-Mat hat übrigens noch ein paar Macken, die ich noch reparieren muss. Äh, seid einfach vorsichtig damit.", 26972);

-- 10111 - Bringt mir das Ei!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10111 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10111, "deDE", "Habe ich meine Vorliebe für Eier erwähnt?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10111 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10111, "deDE", "Nun, es ist kein Ei... Aber Hühnchen mag ich auch! Ich beiße mich einfach durch diese riesige Klaue durch! Danke!", 26972);

-- 10113 - Nesingwarys Safari
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10113 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10113, "deDE", "Ich schätze, wir müssen einen Ersatz für den Wasserträger finden. Nun, Ihr seht aus wie ein kräftiger $C. Interesse an einem Job? Oder kommt Ihr wegen der Jagd?", 26972);

-- 10114 - Nesingwarys Safari
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10114 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10114, "deDE", "Ich bin erleichtert zu hören, dass er in Sicherheit ist. Seid Ihr hier, um an der Jagd teilzunehmen?", 26972);

-- 10168 - Was die Seele sieht
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10168 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10168, "deDE", "<Mutter Kashur ist sichtlich aufgebracht.>$B$BDiese Naaru sind weiser als alle Lebewesen in dieser Welt.", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10168 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10168, "deDE", "Ihr habt eine lange und gefährliche Reise hinter Euch und Leben und Gesundheit für die Sicherheit der Mag'har und den Frieden unserer Ahnen aufs Spiel gesetzt. Ich bin Euch dafür dankbarer, als tausend Worte sagen können.", 26972);

-- 10170 - Rückkehr zur Großmutter
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10170 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10170, "deDE", "Ich möchte, dass Ihr diese Nachrichten persönlich zu Garrosh bringt.", 26972);

-- 10171 - Der untröstliche Häuptling
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10171 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10171, "deDE", "Alle sind stolz. Stolz, dass unser Volk einen weiteren Winter überleben wird. Aber danach? Was ist danach?$B$BVielleicht solltet Ihr diesen Klan anführen, $N. Vielleicht ist es mir dann vergönnt zu sterben, wenn die Großmutter dahinscheidet. Vergönnt, die Schande meines Familiennamens auszulöschen. Ich sehne mich nach diesem Frieden.", 26972);

-- 10172 - Es gibt keine Hoffnung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10172 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10172, "deDE", "<Tränen strömen über Großmutter Geyahs Gesicht.>$B$BThrall ist auf dem Weg hierher. Ich weiß, dass er bald hier sein wird.", 26972);

-- 10476 - Grimmige Feinde
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10476 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10476, "deDE", "Nun, $N? Könnt Ihr nur Reden schwingen, oder habt Ihr mir etwas vorzuweisen?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10476 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10476, "deDE", "Ihr beweist Euch allmählich als wertvoller wertvoller Verbündeter und Kämpfer. Macht weiter so!", 26972);

-- 10477 - Mehr Kriegsperlen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10477 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10477, "deDE", "Habt Ihr noch mehr Obsidiankriegsperlen dabei, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10477 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10477, "deDE", "Ihr beweist Euch weiterhin als wertvoll, $N. Möge Eure Stärke nie versagen.", 26972);

-- 10478 - Mehr Kriegsperlen!
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10478 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10478, "deDE", "Habt Ihr noch mehr Obsidiankriegsperlen besorgt, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10478 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10478, "deDE", "Ihr beweist uns auch weiterhin Eure Stärke und Ehre, $N.", 26972);

-- 10479 - Stärke beweisen
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10479 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10479, "deDE", "Habt Ihr etwas, das Ihr mir zeigen möchtet, $N?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10479 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10479, "deDE", "Ihr seid wirklich ein starker Verbündeter, $N. Den Ogern der Scherbenwelt Auge in Auge gegenüberzutreten ist nichts, was jeder einfach so tun kann.", 26972);

-- 10640 - Altruis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10640 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10640, "deDE", "Ihr habt einen langen Weg hinter Euch, Fremder. Ich bin überrascht, dass derjenige, der Euch zu mir geschickt hat, von mir gehört hat.", 26972);

-- 10641 - Gegen die Legion
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10641 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10641, "deDE", "Ihr habt beweisen, dass Ihr nicht von der Berührung der Legion verderbt wurde. Der Feind meines Feindes ist mein Freund.", 26972);

-- 10646 - Illidans Schüler
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10646 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10646, "deDE", "Jetzt kennt Ihr die Geschichte. Bleibt nur noch eine Sache zu erledigen.", 26972);

-- 10668 - Gegen die Illidari
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10668 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10668, "deDE", "Ihr gehört also nicht zu Illidan. Ihr seid einen Schritt näher daran, mein volles Vertrauen zu erlangen.", 26972);

-- 10669 - Gegen jede Chance
DELETE FROM `quest_request_items_locale` WHERE `ID` = 10669 AND `locale` = "deDE";
INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`, `VerifiedBuild`) VALUES (10669, "deDE", "Ihr seid zurück. Ist Xeleth tot?", 26972);
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10669 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10669, "deDE", "Gut gemacht, $N. Er konnte sich also immer noch an den Tag erinnern, an dem ich den Speer in seinen Körper rammte? Das ist schon so lange her...", 26972);

-- 10689 - Altruis
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 10689 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (10689, "deDE", "Ihr habt einen langen Weg hinter Euch, Fremder. Ich bin überrascht, dass derjenige, der Euch zu mir geschickt hat, von mir gehört hat.", 26972);

-- 11042 - Eine verblüffende Vision
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11042 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11042, "deDE", "<Der Raketenchef hört Euren Ausführungen über die Vision des Sehers aufmerksam zu.>$B$BNun, das ist alles völlig neu für mich, aber Eure Hilfe können wir allemal gebrauchen. Seht Euch das Ungetüm hinter mir an. Das ist die X-52...$B$BIst sie nicht das Schönste, was Ihr je gesehen habt?", 26972);

-- 11044 - Visionen voller Zerstörung
DELETE FROM `quest_offer_reward_locale` WHERE `ID` = 11044 AND `locale` = "deDE";
INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`, `VerifiedBuild`) VALUES (11044, "deDE", "Eine Vision sagt Ihr? Es interessiert mich nicht, ob er es in einer Vision gesehen, in einem Brief gelesen oder es aus dem Mund eines Grubenlords vernommen hat, aber er hat den Nagel auf den Kopf getroffen! Was führt Euch hierher, Freund? Oh, und wir sind für jede Unterstützung dankbar!", 26972);
