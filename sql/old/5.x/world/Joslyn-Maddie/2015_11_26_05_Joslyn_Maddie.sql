-- creature_text [295] 
DELETE FROM `creature_text` where `entry` = '295';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('295', '0', '0', 'So much to do, so much to do! Where does the time go?', '12', '0', '100', '1', '0', '0', 'OOC say');
-- creature_text [951] 
DELETE FROM `creature_text` where `entry` = '951';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('951', '0', '0', 'BY THE LIGHT BE RENEWED!', '12', '0', '100', '0', '0', '0', 'Brother Paxton - Renew Cast Phrase'),
('951', '1', '0', 'AND I LAY MY HANDS UPON YOU!', '12', '0', '100', '0', '0', '0', 'Brother Paxton - Renew Cast Phrase'),
('951', '1', '1', 'Let the Holy Light embrace you!', '12', '0', '100', '0', '0', '0', 'Brother Paxton - Healing Cast Phrase'),
('951', '2', '0', 'Be healed, brother!', '12', '0', '100', '0', '0', '0', 'Brother Paxton - Healing Cast Phrase'),
('951', '2', '1', 'FIGHT ON, BROTHER!', '12', '0', '100', '0', '0', '0', 'Brother Paxton - Healing Cast Phrase');
-- creature_text [3514] 
DELETE FROM `creature_text` where `entry` = '3514';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('3514', '0', '0', 'Greetings, $c.', '12', '0', '100', '0', '0', '0', 'Tenaron Stormgrip'),
('3514', '1', '0', 'Take with you the blessing of the wind\'s embrace. May it make your descent from Aldrassil more... direct.', '12', '0', '100', '0', '0', '0', 'Tenaron Stormgrip');
-- creature_text [5840] 
DELETE FROM `creature_text` where `entry` = '5840';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('5840', '0', '0', 'Ugh! Why are you WET!?', '14', '0', '100', '22', '0', '0', 'Dark Iron Steamsmith'),
('5840', '0', '1', 'But... but...', '14', '0', '100', '22', '0', '0', 'Dark Iron Steamsmith'),
('5840', '0', '2', 'That\'s... one... giant... keester...', '14', '0', '100', '22', '0', '0', 'Dark Iron Steamsmith'),
('5840', '0', '3', 'Why did it have to be... a smelly ogre...', '14', '0', '100', '22', '0', '0', 'Dark Iron Steamsmith'),
('5840', '0', '4', 'Where... did... he... come from...', '14', '0', '100', '22', '0', '0', 'Dark Iron Steamsmith');
-- creature_text [16980] 
DELETE FROM `creature_text` where `entry` = '16980';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('16980', '0', '0', 'Intruders have breached the inner sanctum. Hasten the destruction of the green dragon! Leave only bones and sinew for the reanimation!', '14', '0', '0', '0', '0', '17251', 'The Lich King - SAY_LICH_KING_INTRO');
-- creature_text [18117] 
DELETE FROM `creature_text` where `entry` = '18117';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('18117', '0', '0', 'You no take mushroom!', '12', '0', '0', '0', '0', '0', 'combat say');
-- creature_text [27615] 
DELETE FROM `creature_text` where `entry` = '27615';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('27615', '0', '0', '%s attempts to run away in fear!', '16', '0', '100', '0', '0', '0', 'Scourge Deathspeaker');
-- creature_text [28511] 
DELETE FROM `creature_text` where `entry` = '28511';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('28511', '1', '0', 'The eye of Acherus moves toward its target.', '14', '0', '100', '0', '0', '0', 'Q12641 - EMOTE_EYE_OF_ACHERUS_START'),
('28511', '2', '0', 'The eye of Acherus subject of your control.', '14', '0', '100', '0', '0', '0', 'Q12641 - EMOTE_EYE_OF_ACHERUS_END');
-- creature_text [29384] 
DELETE FROM `creature_text` where `entry` = '29384';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('29384', '0', '0', 'Does not compute. Unit malfunctioning. Directive: Shut down.', '12', '0', '100', '1', '0', '0', 'Captive Mechagnome text 0'),
('29384', '0', '1', 'New directive: Leave mine and return to Inventor\'s Library.', '12', '0', '100', '1', '0', '0', 'Captive Mechagnome text 1'),
('29384', '0', '2', 'New directive: Assist in the defeat of the iron dwarves.', '12', '0', '100', '1', '0', '0', 'Captive Mechagnome text 2'),
('29384', '0', '3', 'Free again? Keeper Mimir\'s work awaits.', '12', '0', '100', '1', '0', '0', 'Captive Mechagnome text 3'),
('29384', '0', '4', 'Thank you, $r. I will join your struggle against the stormforged.', '12', '0', '100', '1', '0', '0', 'Captive Mechagnome text 4');
-- creature_text [32576] 
DELETE FROM `creature_text` where `entry` = '32576';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('32576', '0', '0', 'The Helmsman comes for you!', '14', '0', '100', '0', '0', '0', 'Orabus the Helmsman'),
('32576', '0', '1', 'A child has found a new toy! Crewman, take this infant\'s toy away!', '14', '0', '100', '0', '0', '0', 'Orabus the Helmsman'),
('32576', '0', '2', 'Crewman, show this ant the might of the Kvaldir!', '14', '0', '100', '0', '0', '0', 'Orabus the Helmsman'),
('32576', '0', '3', 'Crewman, tear this land walker apart!', '14', '0', '100', '0', '0', '0', 'Orabus the Helmsman'),
('32576', '1', '0', 'Now you face Orabus, fool!', '14', '0', '100', '0', '0', '0', 'Orabus the Helmsman');
-- creature_text [32970] 
DELETE FROM `creature_text` where `entry` = '32970';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('32970', '0', '0', 'A new victim! Me was almost don wit dis one anyway.', '12', '0', '100', '0', '0', '0', 'combat Say');
-- creature_text [34756] 
DELETE FROM `creature_text` where `entry` = '34756';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('34756', '0', '0', 'Shh! Someone\'s here.', '12', '0', '100', '0', '0', '0', 'Moriana Dawnlight');
-- creature_text [34757] 
DELETE FROM `creature_text` where `entry` = '34757';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('34757', '0', '0', 'Don\'t get me wrong... I\'m grateful to have Shando Stormrage back, but this is all really suspicious. What happened to Fandral?', '12', '0', '100', '0', '0', '0', 'Doranel Amberleaf');
-- creature_text [35112] 
DELETE FROM `creature_text` where `entry` = '35112';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35112', '0', '0', 'Enough!  I\'ve made up my mind.  We need Crowley on our side.', '12', '0', '100', '0', '0', '0', 'King Genn Greymane');
-- creature_text [35115] 
DELETE FROM `creature_text` where `entry` = '35115';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35115', '0', '0', 'We ought to leave Crowley in prison with those beasts!', '12', '0', '100', '0', '0', '0', 'Lord Godfrey');
-- creature_text [35230] 
DELETE FROM `creature_text` where `entry` = '35230';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35230', '0', '0', 'Let\'s round up as many of them as we can.  Every worgen chasing us is one less worgen chasing the survivors!', '12', '0', '100', '0', '0', '19506', 'Lord Darius Crowley'),
('35230', '1', '0', 'You\'ll never catch us, you blasted mongrels!', '14', '0', '100', '0', '0', '19505', 'Lord Darius Crowley'),
('35230', '1', '1', 'Over here, you flea bags!', '14', '0', '100', '0', '0', '19504', 'Lord Darius Crowley'),
('35230', '1', '2', 'Come and get us, you motherless beasts!', '14', '0', '100', '0', '0', '19503', 'Lord Darius Crowley');
-- creature_text [35370] 
DELETE FROM `creature_text` where `entry` = '35370';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35370', '1', '0', 'The pain is unbearable!', '14', '0', '100', '0', '0', '0', 'Josiah Avery Worgen - Yell on Attack');
-- creature_text [35551] 
DELETE FROM `creature_text` where `entry` = '35551';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35551', '0', '0', 'I\'ll stay behind with the Royal Guard, father.  It is my duty to Gilneas.', '12', '0', '100', '0', '0', '19622', 'Prince Liam Greymane');
-- creature_text [35552] 
DELETE FROM `creature_text` where `entry` = '35552';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35552', '0', '0', 'We need to keep the worgen\'s attention in the city, Genn.  It\'s the only shot we have for the survivors to make it to Duskhaven.', '12', '0', '100', '0', '0', '19507', 'Lord Darius Crowley'),
('35552', '1', '0', 'Not a chance, boy.  Gilneas is going to need its king\'s undivided attention.  Can\'t have your father wondering whether his child is alive or not.', '12', '0', '100', '0', '0', '19508', 'Lord Darius Crowley'),
('35552', '2', '0', 'My men and I will hole up inside the Light\'s Dawn Cathedral.  I\'ve already given the order and the cannons are on their way.  Lead our people well, Genn.', '12', '0', '100', '0', '0', '19509', 'Lord Darius Crowley');
-- creature_text [35907] 
DELETE FROM `creature_text` where `entry` = '35907';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('35907', '0', '0', 'Thank you! I owe you my life.', '12', '0', '0', '1', '0', '20922', 'Saved Krennan Aranas');
-- creature_text [37108] 
DELETE FROM `creature_text` where `entry` = '37108';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('37108', '0', '0', 'Da spirits be angry with us.', '12', '0', '100', '1', '3', '0', 'Soothsayer Shi\'kala 1st sentence'),
('37108', '1', '0', 'I don\' know why the spirits be rejectin\' us so.', '12', '0', '100', '1', '3', '0', 'Soothsayer Shi\'kala 2nd sentence'),
('37108', '2', '0', 'Don\' worry, child. Grik\'nir gonna help us get through this.', '12', '0', '100', '1', '3', '0', 'Soothsayer Shi\'kala 3rd sentence');
-- creature_text [37173] 
DELETE FROM `creature_text` where `entry` = '37173';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('37173', '0', '0', 'What we gon\' do now, you ask ? We wait.', '12', '0', '100', '1', '3', '0', 'Soothsayer Rikkari 1st sentence'),
('37173', '1', '0', 'Grik\'nir says he gon\' talk to the elemental, get it to fight on our side.', '12', '0', '100', '1', '3', '0', 'Soothsayer Rikkari 2nd sentence'),
('37173', '2', '0', 'Soon enough we take over dis valley. Soon enough.', '12', '0', '100', '1', '3', '0', 'Soothsayer Rikkari 3rd sentence');
-- creature_text [37174] 
DELETE FROM `creature_text` where `entry` = '37174';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('37174', '0', '0', 'Our land be a land of ice an\' snow', '12', '0', '100', '1', '3', '0', 'Soothsayer Mirim\'koa 1st sentence'),
('37174', '1', '0', 'But beneath the earth, child, there always be fire.', '12', '0', '100', '1', '3', '0', 'Soothsayer Mirim\'koa 2nd sentence'),
('37174', '2', '0', 'De spirit come from deep down to talk with Grik\'nir.', '12', '0', '100', '1', '3', '0', 'Soothsayer Mirim\'koa 3rd sentence');
-- creature_text [37988] 
DELETE FROM `creature_text` where `entry` = '37988';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('37988', '1', '0', 'Ya, mon. Let\'s crack some tiki target skulls!', '12', '0', '100', '0', '0', '21366', 'lvl <1> Zuni Quote'),
('37988', '2', '1', 'Ya trainer should be somewhere in the grounds \'ere. I\'ll catch you lata, mon.', '12', '0', '100', '397', '0', '21367', 'lvl <1> Zuni Quote');
-- creature_text [38037] 
DELETE FROM `creature_text` where `entry` = '38037';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38037', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Nortet Quote 1'),
('38037', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Nortet Quote 2');
-- creature_text [38142] 
DELETE FROM `creature_text` where `entry` = '38142';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38142', '1', '0', 'They sssend you to your death youngling.', '12', '0', '100', '0', '0', '0', 'Captive Spitescale Scout Quote 1'),
('38142', '1', '1', 'I sshal ssslaughter you, Darksspear runt!', '12', '0', '100', '0', '0', '0', 'Captive Spitescale Scout Quotes 2'),
('38142', '1', '2', 'I sshal tasste your blood, landling.', '12', '0', '100', '0', '0', '0', 'Captive Spitescale Scout Quote 3'),
('38142', '1', '3', 'The Sssea Witch will kill you all.', '12', '0', '100', '0', '0', '0', 'Captive Spitescale Scout Quote 4');
-- creature_text [38242] 
DELETE FROM `creature_text` where `entry` = '38242';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38242', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Nekali Quote 1'),
('38242', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Nekali Quote 2');
-- creature_text [38243] 
DELETE FROM `creature_text` where `entry` = '38243';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38243', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Zen\'tabra Quote 1'),
('38243', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Zen\'tabra Quote 2');
-- creature_text [38244] 
DELETE FROM `creature_text` where `entry` = '38244';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38244', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Legati Quote 1'),
('38244', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Legati Quote 2');
-- creature_text [38245] 
DELETE FROM `creature_text` where `entry` = '38245';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38245', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Tunari Quote 1'),
('38245', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Tunari Quote 2');
-- creature_text [38246] 
DELETE FROM `creature_text` where `entry` = '38246';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38246', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Soratha Quote 1'),
('38246', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Soratha Quote 2');
-- creature_text [38247] 
DELETE FROM `creature_text` where `entry` = '38247';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38247', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Ortezza Quote 1'),
('38247', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Ortezza Quote 2');
-- creature_text [38930] 
DELETE FROM `creature_text` where `entry` = '38930';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38930', '0', '0', 'Wait up mon!', '12', '0', '0', '1', '0', '21368', 'lvl <2> Zuni Phrase 1'),
('38930', '1', '0', 'You finished with ya trainin\' too? Glad you make it through, mon!', '12', '0', '0', '1', '0', '21370', 'lvl <2> Zuni Phrase 2'),
('38930', '2', '0', 'I know dis is prolly busy work, but I don\'t mind. Dese baby raptors are cute lil devils.', '12', '0', '0', '1', '0', '21371', 'lvl <2> Zuni Phrase 3'),
('38930', '3', '0', 'Try not ta make me look too bad, eh?', '12', '0', '0', '1', '0', '21373', 'lvl <2> Zuni Phrase 4');
-- creature_text [38938] 
DELETE FROM `creature_text` where `entry` = '38938';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38938', '0', '1', 'Don\'t talk back to me, troll. You know who was left in charge here. Haven\'t you stopped to ask yourself why Thrall chose me instead of you?', '12', '0', '100', '25', '0', '20508', 'Vol\'jin - Vision - Quote'),
('38938', '1', '1', 'You are lucky that I don\'t gut you right here, whelp. You are foolish to think that you can speak to your Warchief in such ways.', '12', '0', '100', '5', '0', '20512', 'Vol\'jin - Vision - Quote'),
('38938', '2', '1', 'And what exactly do you think that you are going to do about it?  Your threats are hollow.  Go slink away with the rest of your kind to the slums, I will endure your filth in my throne room no longer.', '12', '0', '100', '1', '0', '20509', 'Vol\'jin - Vision - Quote'),
('38938', '3', '1', 'You have sealed your fate, troll.', '12', '0', '100', '1', '0', '20510', 'Vol\'jin - Vision - Quote');
-- creature_text [38953] 
DELETE FROM `creature_text` where `entry` = '38953';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38953', '0', '1', 'Dere be no question why, Garrosh. He gave ya tha title because ya be Grom\'s son and because tha people be wantin\' a war hero.', '12', '0', '100', '5', '0', '20098', 'Vol\'jin - Vision - Quote'),
('38953', '1', '1', 'I tink ya be even more like ya father den ya thought, even witout da demon blood.', '12', '0', '100', '1', '0', '20099', 'Vol\'jin - Vision - Quote'),
('38953', '2', '1', 'Ya be no Warchief of mine. Ya\'ve not earned my respect and I\'ll not be seein\' tha Horde destroyed by ya foolish thirst for war.', '12', '0', '100', '1', '0', '20100', 'Vol\'jin - Vision - Quote'),
('38953', '3', '1', 'I know exactly what I\'ll be doin\' about it, son of Hellscream. I\'ll watch and wait as ya people slowly become aware of ya ineptitude. I\'ll laugh as dey grow ta despise ya as I do.', '12', '0', '100', '1', '0', '20101', 'Vol\'jin - Vision - Quote'),
('38953', '4', '1', 'And when tha time comes dat ya failure is complete and ya \"power\" is meaningless, I will be dere to end ya rule swiftly and silently.', '12', '0', '100', '1', '0', '20102', 'Vol\'jin - Vision - Quote'),
('38953', '5', '1', 'Ya will spend ya reign glancin\' over ya shoulda and fearin\' tha shadows, for when tha time comes and ya blood be slowly drainin\' out, ya will know exactly who fired tha arrow dat pierced ya black heart.', '12', '0', '100', '1', '0', '20103', 'Vol\'jin - Vision - Quote'),
('38953', '6', '1', 'And you yours, \"Warchief.\"', '12', '0', '100', '1', '0', '20104', 'Vol\'jin - Vision - Quote');
-- creature_text [38966] 
DELETE FROM `creature_text` where `entry` = '38966';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('38966', '0', '1', 'I have somethin\' to show ya. It be easier to understand if ya see it yourself.', '12', '0', '100', '1', '0', '20097', 'Vol\'jin - Vision - Quote'),
('38966', '1', '1', 'The Darkspear are \'ere because I lead dem here. Orgrimmar be no home as long as it be under Hellscream\'s hand.', '12', '0', '100', '1', '0', '20105', 'Vol\'jin - Vision - Quote'),
('38966', '2', '1', 'Still, I fear I was lettin\' my tember drive me ta bein\' rash. Thrall devoted himself to makin\' the Horde what it is, so I\'ve no eagerness to be leavin\' it on a whim. Dis will be needin\' much more thought', '12', '0', '100', '1', '0', '20106', 'Vol\'jin - Vision - Quote'),
('38966', '3', '1', 'But dese be worries for older minds. Ya still have much to learn. Go help tha people of tha Darkspear. I am sure we\'ll be speakin\' again real soon.', '12', '0', '100', '1', '0', '20107', 'Vol\'jin - Vision - Quote');
-- creature_text [39062] 
DELETE FROM `creature_text` where `entry` = '39062';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39062', '1', '0', 'Get in the pit and show us your stuff, boy.', '12', '0', '100', '0', '0', '0', 'Jailor say after');
-- creature_text [39378] 
DELETE FROM `creature_text` where `entry` = '39378';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39378', '0', '0', 'Defilers! Wretches! Fiends! Begone from here!', '14', '0', '0', '0', '0', '18911', 'VO_HO_Rajh_Engage'),
('39378', '1', '0', 'Can you feel it? The blessed warmth of the sun?', '14', '0', '0', '0', '0', '18912', 'VO_HO_Rajh_Event01'),
('39378', '2', '0', 'I send you to your deity.', '14', '0', '0', '0', '0', '18913', 'VO_HO_Rajh_Slay01'),
('39378', '2', '1', 'I will take this life as an offering!', '14', '0', '0', '0', '0', '18914', 'VO_HO_Rajh_Slay01'),
('39378', '3', '0', 'Blazing rays of light, take me!', '14', '0', '0', '0', '0', '18910', 'VO_HO_Rajh_Death');
-- creature_text [39587] 
DELETE FROM `creature_text` where `entry` = '39587';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39587', '0', '0', 'Gaze to the heavens! What do you see?', '14', '0', '0', '0', '0', '18843', 'VO_HO_Isiset_Engage'),
('39587', '1', '0', 'Bask in my radiance!', '14', '0', '0', '0', '0', '18845', 'VO_HO_Isiset_Event01'),
('39587', '2', '0', 'Insignificant!', '14', '0', '0', '0', '0', '18847', 'VO_HO_Isiset_Slay02'),
('39587', '2', '1', 'The glimmer of your life, extinguished.', '14', '0', '0', '0', '0', '18846', 'VO_HO_Isiset_Slay01'),
('39587', '3', '0', 'Eons of darkness... by your hand.', '14', '0', '0', '0', '0', '18842', 'VO_HO_Isiset_Death01'),
('39587', '3', '1', 'My luster... wanes.', '14', '0', '0', '0', '0', '18844', 'VO_HO_Isiset_Death02');
-- creature_text [39625] 
DELETE FROM `creature_text` where `entry` = '39625';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39625', '0', '0', 'A million more await my orders. What chance you do have?', '14', '0', '0', '0', '0', '18530', 'VO_GB_Umbriss_Engage'),
('39625', '1', '0', 'All in my path shall be destroyed!', '14', '0', '0', '0', '0', '18534', 'VO_GB_Umbriss_Event01'),
('39625', '2', '0', 'Attack you cowardly vermin!', '14', '0', '0', '0', '0', '18535', 'VO_GB_Umbriss_Malignant Troggs'),
('39625', '3', '0', 'Reinforce the front! We are being invaded!', '14', '0', '0', '0', '0', '18536', 'VO_GB_Umbriss_Bomb1'),
('39625', '3', '1', 'Cover the rear! Alexstrazas brood decimate our rank!', '14', '0', '0', '0', '0', '18537', 'VO_GB_Umbriss_Bomb2'),
('39625', '4', '0', 'Messy...', '14', '0', '0', '0', '0', '18532', 'VO_GB_Umbriss_Slay01'),
('39625', '4', '1', 'Vermin, your dinner awaits!', '14', '0', '0', '0', '0', '18531', 'VO_GB_Umbriss_Slay02'),
('39625', '5', '0', 'Death, is my only option...', '14', '0', '0', '0', '0', '18533', 'VO_GB_Umbriss_Death');
-- creature_text [39665] 
DELETE FROM `creature_text` where `entry` = '39665';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39665', '0', '0', 'Boss Chogall not gonna be happy bout dis! ', '14', '0', '0', '0', '0', '18925', 'VO_BC_Romogg_Aggro01'),
('39665', '1', '0', 'Stand still! Romogg crack your skulls! ', '14', '0', '0', '0', '0', '18927', 'VO_BC_Romogg_Event03'),
('39665', '2', '0', 'That what you get! Nothing! ', '14', '0', '0', '0', '0', '18926', 'VO_BC_Romogg_Slay'),
('39665', '3', '0', 'Romogg...sorry... ', '14', '0', '0', '0', '0', '18928', 'VO_BC_Romogg_Death');
-- creature_text [39679] 
DELETE FROM `creature_text` where `entry` = '39679';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39679', '0', '0', 'HERETICS! You will suffer for this interruption!', '14', '0', '0', '0', '0', '18589', 'VO_BC_Corla_Aggro'),
('39679', '1', '0', 'Bask in his power! Rise as an agent of the masters rage!', '14', '0', '0', '0', '0', '18592', 'VO_BC_Corla_Event03'),
('39679', '2', '0', 'There is only one true path of enlightenment! DEATH!', '14', '0', '0', '0', '0', '18590', 'VO_BC_Corla_Slay'),
('39679', '3', '0', 'For the master I die a thousand times... A thousan...', '14', '0', '0', '0', '0', '18594', 'VO_BC_Corla_Death');
-- creature_text [39698] 
DELETE FROM `creature_text` where `entry` = '39698';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39698', '0', '0', 'Bodies to test my armaments upon! ', '14', '0', '0', '0', '0', '18852', 'VO_BC_Karsh_Aggro'),
('39698', '1', '0', 'Feel the burn!', '14', '0', '0', '0', '0', '18854', 'VO_BC_Karsh_Event03'),
('39698', '2', '0', 'Merely an impurity in the compound!', '14', '0', '0', '0', '0', '18853', 'VO_BC_Karsh_Slay'),
('39698', '3', '0', 'We number in the millions! Your efforts are wasted...', '14', '0', '0', '0', '0', '18855', 'VO_BC_Karsh_Death');
-- creature_text [39705] 
DELETE FROM `creature_text` where `entry` = '39705';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39705', '0', '0', 'You come seeking answers? Then have them! Look upon your answer to living!', '14', '0', '0', '0', '0', '18899', 'VO_BC_Obsidius_Aggro'),
('39705', '1', '0', 'Earth can be shaped, molded... You cannot! You are useless!', '14', '0', '0', '0', '0', '18905', 'VO_BC_Obsidius_Event01'),
('39705', '2', '0', 'Your kind has no place in the masters world!', '14', '0', '0', '0', '0', '18901', 'VO_BC_Obsidius_Slay'),
('39705', '3', '0', 'I cannot be destroyed... Only de... layed...', '14', '0', '0', '0', '0', '18902', 'VO_BC_Obsidius_Death');
-- creature_text [39731] 
DELETE FROM `creature_text` where `entry` = '39731';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39731', '0', '0', 'This chamber will flourish with your life energy!', '14', '0', '0', '0', '0', '18571', 'VO_HO_Ammunae_Engage'),
('39731', '1', '0', 'Your life, UNLEASHED!', '14', '0', '0', '0', '0', '18572', 'VO_HO_Ammunae_Event'),
('39731', '2', '0', 'Wither away!', '14', '0', '0', '0', '0', '18573', 'VO_HO_Ammunae_Slay01'),
('39731', '2', '1', 'Waste of energy.', '14', '0', '0', '0', '0', '18574', 'VO_HO_Ammunae_Slay02'),
('39731', '3', '0', 'The cycle continues...', '14', '0', '0', '0', '0', '18569', 'VO_HO_Ammunae_Death');
-- creature_text [39732] 
DELETE FROM `creature_text` where `entry` = '39732';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('39732', '0', '0', 'You fear that which you cannot control. But can you control your fear? ', '14', '0', '0', '0', '0', '18553', 'VO_HO_Setesh_Engage'),
('39732', '1', '0', 'Behold, how infinity befalls your world', '14', '0', '0', '0', '0', '18554', 'VO_HO_Setesh_Event'),
('39732', '2', '0', 'Do you understand now?', '14', '0', '0', '0', '0', '18556', 'VO_HO_Setesh_Slay02'),
('39732', '2', '1', 'Embrace the end.', '14', '0', '0', '0', '0', '18555', 'VO_HO_Setesh_Slay01'),
('39732', '3', '0', 'Yes! Harness... your... hatred.', '14', '0', '0', '0', '0', '18552', 'VO_HO_Setesh_Death');
-- creature_text [40177] 
DELETE FROM `creature_text` where `entry` = '40177';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('40177', '0', '0', 'NO! Throngus get whipped again if he no finish!', '14', '0', '0', '0', '0', '18943', 'VO_GB_Throngus_Engage'),
('40177', '1', '0', 'You not get through defenses!', '14', '0', '0', '0', '0', '18947', 'VO_GB_Throngus_Shield'),
('40177', '2', '0', 'Throngus SLICE you up!', '14', '0', '0', '0', '0', '18948', 'VO_GB_Throngus_Sword'),
('40177', '3', '0', 'Oh, this is gonna HURT!', '14', '0', '0', '0', '0', '18949', 'VO_GB_Throngus_Mace'),
('40177', '4', '0', 'You break easy!', '14', '0', '0', '0', '0', '18945', 'VO_GB_Throngus_Slay01'),
('40177', '4', '1', 'Throngus use your corpse on body. Somewhere...', '14', '0', '0', '0', '0', '18944', 'VO_GB_Throngus_Slay02'),
('40177', '5', '0', 'Death... Good choice. Not best choice maybe, but better than fail and live.', '14', '0', '0', '0', '0', '18946', 'VO_GB_Throngus_Death');
-- creature_text [40319] 
DELETE FROM `creature_text` where `entry` = '40319';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('40319', '0', '0', 'I will burn you from the inside out!', '14', '0', '0', '0', '0', '18610', 'VO_GB_Drahga_Engage'),
('40319', '1', '0', 'INCINERATE THEM, MINIONS!', '14', '0', '0', '0', '0', '18616', 'VO_GB_Drahga_Sum_Spirits1'),
('40319', '1', '1', 'BY FIRE BE... BURNED!', '14', '0', '0', '0', '0', '18619', 'VO_GB_Drahga_Sum_Spirits2'),
('40319', '2', '0', 'Dragon, you will do as I command! Catch me!', '14', '0', '0', '0', '0', '18621', 'VO_GB_Drahga_Sum_Valiona'),
('40319', '3', '0', 'You should have come better prepared!', '14', '0', '0', '0', '0', '18612', 'VO_GB_Drahga_Slay01'),
('40319', '3', '1', 'An easy kill!', '14', '0', '0', '0', '0', '18611', 'VO_GB_Drahga_Slay02'),
('40319', '4', '0', 'Valiona, finish them! Avenge me!', '14', '0', '0', '0', '0', '18614', 'VO_GB_Drahga_Death');
-- creature_text [40484] 
DELETE FROM `creature_text` where `entry` = '40484';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('40484', '0', '0', 'The darkest days are still ahead!', '14', '0', '0', '0', '0', '18638', 'VO_GB_Erudax_Engage'),
('40484', '1', '0', 'Flakh ghet! The shadows hunger cannot be sated! ', '14', '0', '0', '0', '0', '18644', 'VO_GB_Erudax_Shad_Gale'),
('40484', '2', '0', 'Come, suffering... Enter, chaos!', '14', '0', '0', '0', '0', '18646', 'VO_GB_Erudax_Guardian'),
('40484', '3', '0', 'Flesh for the offering!', '14', '0', '0', '0', '0', '18640', 'VO_GB_Erudax_Slay02'),
('40484', '3', '1', 'Erudax cackles maniacally.', '16', '0', '0', '0', '0', '18639', 'VO_GB_Erudax_Slay01'),
('40484', '4', '0', 'Ywaq maq oou; ywaq maq ssaggh. Yawq ma shg fhn.', '14', '0', '0', '0', '0', '18641', 'VO_GB_Erudax_Death');
-- creature_text [41236] 
DELETE FROM `creature_text` where `entry` = '41236';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('41236', '0', '0', 'I know who you are, $N! I\'ll not surrender the Sacred Flame to a filthy meatbag such as yourself!', '14', '0', '100', '0', '0', '0', 'Aquarian Yell On Spawn (quest The Ancient Brazier)');
-- creature_text [42291] 
DELETE FROM `creature_text` where `entry` = '42291';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('42291', '0', '0', 'Optical sesor malfuction detected...... Shuting down.....', '12', '0', '15', '25', '0', '0', 'Crushcog Sentry-Bot - Text');
-- creature_text [42618] 
DELETE FROM `creature_text` where `entry` = '42618';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('42618', '1', '0', 'Well Done, $N!', '0', '0', '100', '0', '0', '0', 'Voldreka Quote 1'),
('42618', '1', '1', 'Not bad, $N. Not bad.', '0', '0', '100', '0', '0', '0', 'Voldreka Quote 2');
-- creature_text [43612] 
DELETE FROM `creature_text` where `entry` = '43612';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('43612', '0', '0', 'Begone infidels, you are not welcome here!', '14', '0', '0', '0', '0', '19735', 'VO_TV_Barim_Engage01'),
('43612', '1', '0', 'May peace find you now.', '14', '0', '0', '0', '0', '19738', 'VO_TV_Barim_Kill01'),
('43612', '2', '0', 'Kneel before me and repent!', '14', '0', '0', '0', '0', '19737', 'VO_TV_Barim_Event02'),
('43612', '2', '1', 'The Heavens take you!', '14', '0', '0', '0', '0', '19736', 'VO_TV_Barim_Event01'),
('43612', '3', '0', 'Death is only the beginning!', '14', '0', '0', '0', '0', '19733', 'VO_TV_Barim_Death');
-- creature_text [43875] 
DELETE FROM `creature_text` where `entry` = '43875';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('43875', '0', '0', 'YOU tread upon the sacrosanct! Mortals have no please amidst the clouds.', '14', '0', '0', '0', '0', '20867', 'VO_VP_AsimAlAkir_Engage'),
('43875', '1', '0', 'AlAkir, your servant calls for aid!', '14', '0', '0', '0', '0', '20869', 'VO_VP_AsimAlAkir_Event02'),
('43875', '2', '0', 'BACK to the earth with you!', '14', '0', '0', '0', '0', '20868', 'VO_VP_AsimAlAkir_Slay'),
('43875', '3', '0', 'The winds take me!', '14', '0', '0', '0', '0', '20870', 'VO_VP_AsimAlAkir_Death');
-- creature_text [43878] 
DELETE FROM `creature_text` where `entry` = '43878';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('43878', '1', '0', 'Ravaged!', '14', '0', '100', '0', '0', '20877', 'Ertan - Slay'),
('43878', '0', '0', 'Filthy beasts! Your presence in Skywall will not be tolerated!', '14', '0', '100', '0', '0', '20876', 'Ertan - Aggro'),
('43878', '2', '0', 'AHHHHHHHHH!', '14', '0', '100', '0', '0', '20878', 'Ertan - Death'),
('43878', '3', '0', '%s pulls her cyclone shield back!', '41', '0', '100', '0', '0', '20878', 'Ertan - Cyclone Shield');
-- creature_text [44086] 
DELETE FROM `creature_text` where `entry` = '44086';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('44086', '1', '0', 'They told us Gilneas City was safe...', '12', '0', '33', '0', '0', '0', 'Panicked Citizen Random Saying'),
('44086', '1', '1', 'We have to get out of here! The howling gets louder every night.', '12', '0', '33', '0', '0', '0', 'Panicked Citizen Random Saying'),
('44086', '1', '2', 'Why are the gates closed?', '12', '0', '33', '0', '0', '0', 'Panicked Citizen Random Saying');
-- creature_text [44577] 
DELETE FROM `creature_text` where `entry` = '44577';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('44577', '0', '0', 'Invaders! You shall go no further! ', '14', '0', '0', '0', '0', '21886', 'VO_TV_Husam_Engage01'),
('44577', '1', '0', 'Tread Lightly! ', '14', '0', '0', '0', '0', '21887', 'VO_TV_Husam_Event01'),
('44577', '1', '1', 'Murkash!', '14', '0', '0', '0', '0', '21888', 'VO_TV_Husam_Event02'),
('44577', '2', '0', 'Siamat must not be freed! Turn back before it is too late!', '14', '0', '0', '0', '0', '21885', 'VO_TV_Husam_Death01'),
('44577', '3', '0', 'Insolent rats!', '14', '0', '0', '0', '0', '21889', 'VO_TV_Husam_Kill02');
-- creature_text [44819] 
DELETE FROM `creature_text` where `entry` = '44819';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('44819', '0', '0', 'I. AM. UNLEASHED!', '14', '0', '0', '0', '0', '20231', 'VO_TV_Siamat_Intro01'),
('44819', '1', '0', 'Winds of the south, rise and come to your masters aid!', '14', '0', '0', '0', '0', '20227', 'VO_TV_Siamat_Engage01'),
('44819', '2', '0', 'Cower before the tempest storm!', '14', '0', '0', '0', '0', '20228', 'VO_TV_Siamat_Event01'),
('44819', '2', '1', 'Suffer the storm!', '14', '0', '0', '0', '0', '20229', 'VO_TV_Siamat_Event02'),
('44819', '2', '2', 'Your city will be buried! Your lives forfeit to the elements! ', '14', '0', '0', '0', '0', '20230', 'VO_TV_Siamat_Event03'),
('44819', '3', '0', 'Nothing more than dust in the wind.', '14', '0', '0', '0', '0', '20232', 'VO_TV_Siamat_Kill01'),
('44819', '4', '0', 'The sky... Beckons...', '14', '0', '0', '0', '0', '20226', 'VO_TV_Siamat_Death01');
-- creature_text [47266] 
DELETE FROM `creature_text` where `entry` = '47266';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('47266', '0', '0', 'Let\'s see what this ember does... whaaaa?', '12', '0', '100', '22', '0', '0', 'Jack Rockleg');
-- creature_text [47271] 
DELETE FROM `creature_text` where `entry` = '47271';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('47271', '0', '0', 'What in hell\'s name is going on out here?', '14', '0', '100', '0', '0', '0', 'Dig-Boss Dinwhisker');
-- creature_text [47281] 
DELETE FROM `creature_text` where `entry` = '47281';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('47281', '0', '0', 'Ha ha ha!', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47281', '0', '1', 'Look out spider! Here come Lunk!', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47281', '0', '2', 'Lunk will ride you now!', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47281', '0', '3', 'You hold still, spider!', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47281', '1', '0', 'Here, you can scrape venom off Lunk\'s tummy.', '12', '0', '100', '22', '0', '0', 'Lunk'),
('47281', '1', '1', 'Lunk got you some venom with his tummy.', '12', '0', '100', '22', '0', '0', 'Lunk'),
('47281', '1', '2', 'See? No kill spider for venom. Just ride.', '12', '0', '100', '22', '0', '0', 'Lunk');
-- creature_text [47299] 
DELETE FROM `creature_text` where `entry` = '47299';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('47299', '0', '0', 'Lunk tired of all this killing!  Lunk quits!', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47299', '1', '0', 'Lunk going to find some real adventures!', '14', '0', '100', '0', '0', '0', 'Lunk');
-- creature_text [47301] 
DELETE FROM `creature_text` where `entry` = '47301';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('47301', '0', '0', 'You dwarves are worthless! You come to Ragnaros seeking ascendance, but you have nothing to offer!', '14', '0', '100', '22', '0', '0', 'Image of Archduke Calcinder'),
('47301', '1', '0', 'Nothing to offer, except your backs and your shovels. So you will dig.!', '14', '0', '100', '22', '0', '0', 'Image of Archduke Calcinder'),
('47301', '2', '0', 'Dig wide, dig deep. Seek out the places of fire beneath the world. My brothers and sisters yearn to be free.', '14', '0', '100', '22', '0', '0', 'Image of Archduke Calcinder'),
('47301', '3', '0', 'Succeed and you may ascend after all. Fail, and burn.', '14', '0', '100', '22', '0', '0', 'Image of Archduke Calcinder');
-- creature_text [47333] 
DELETE FROM `creature_text` where `entry` = '47333';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('47333', '0', '0', 'You take dwarf\'s things. No need to kill.', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47333', '0', '1', 'He will be sleepy for a while. Lunk know. Lunk do before.', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47333', '0', '2', 'Here, I stealed this from little dwarf.', '14', '0', '100', '22', '0', '0', 'Lunk'),
('47333', '0', '3', 'Sitting easier than killing.', '14', '0', '100', '22', '0', '0', 'Lunk');
-- creature_text [49479] 
DELETE FROM `creature_text` where `entry` = '49479';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('49479', '0', '0', 'The ramp up to Aldrassil is just in sight over there. Circle around and find Tenaron up top.', '12', '0', '100', '0', '0', '0', 'Dentaria Silverglade'),
('49479', '1', '0', 'Iverron\'s poison is cured, but it will take some time for him to recover.', '12', '0', '100', '0', '0', '0', 'Dentaria Silverglade'),
('49479', '2', '0', 'The moonwell is to the northeast, on the other side of the pool and up the hill.', '12', '0', '100', '0', '0', '0', 'Dentaria Silverglade');
-- creature_text [49869] 
DELETE FROM `creature_text` where `entry` = '49869';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('49869', '0', '0', 'HELP!', '12', '0', '100', '0', '0', '0', 'Stormwind Infantry - Call for heal prase'),
('49869', '0', '1', 'I need a heal!', '12', '0', '100', '0', '0', '0', 'Stormwind Infantry - Call for heal prase'),
('49869', '0', '2', 'I could use a heal, brother!', '12', '0', '100', '0', '0', '0', 'Stormwind Infantry - Call for heal prase'),
('49869', '0', '3', 'Make yourself useful and heal me, Paxton!', '12', '0', '100', '0', '0', '0', 'Stormwind Infantry - Call for heal prase'),
('49869', '1', '3', 'Your filthy dogs won\'t be enough!', '14', '0', '100', '0', '0', '0', 'Stormwind Infantry - Yell'),
('49869', '1', '2', 'Look alive, men! There are orcs and worgs about!', '14', '0', '100', '0', '0', '0', 'Stormwind Infantry - Yell'),
('49869', '1', '1', 'I\'ll kill a hundred more of your battle worgs!', '14', '0', '100', '0', '0', '0', 'Stormwind Infantry - Yell'),
('49869', '1', '0', 'Come, monsters! We will crush you!', '14', '0', '100', '0', '0', '0', 'Stormwind Infantry - Yell'),
('49869', '1', '4', 'Your worgs are no match for the might of Stormwind!', '14', '0', '100', '0', '0', '0', 'Stormwind Infantry - Yell');
-- creature_text [50415] 
DELETE FROM `creature_text` where `entry` = '50415';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('50415', '1', '0', 'You\'ve been bitten by a worgen. It\'s probably nothing, but it sure stings a little.$B$B|TInterfaceIconsINV_Misc_monsterfang_02.blp:32|t', '42', '0', '100', '0', '0', '0', 'Josiah Event Trigger');
-- creature_text [50474] 
DELETE FROM `creature_text` where `entry` = '50474';
INSERT INTO `creature_text` (entry,groupid,id,text,type,language,probability,emote,duration,sound,comment) VALUES 
('50474', '1', '0', 'They\'re turning our people into MONSTERS!!', '14', '0', '100', '0', '0', '0', 'Gilneas City Guard'),
('50474', '1', '1', 'Don\'t look into their eyes!  They\'re not the people you once knew!', '14', '0', '100', '0', '0', '0', 'Gilneas City Guard'),
('50474', '1', '2', 'Hold them back!  We must protect the survivors!', '14', '0', '100', '0', '0', '0', 'Gilneas City Guard');