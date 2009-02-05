DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000333 and -1000306;
INSERT INTO `script_texts` (entry, content_default, type, comment) VALUES
(-1000306, 'Follow me, stranger. This won\'t take long.', 0, 'npc_kservant - SAY1'),
(-1000307, 'Shattrath was once the draenei capital of this world. Its name means \"dwelling of light.\"', 4, 'npc_kservant - WHISP1'),
(-1000308, 'When the Burning Legion turned the orcs against the draenei, the fiercest battle was fought here. The draenei fought tooth and nail, but in the end the city fell.', 4, 'npc_kservant - WHISP2'),
(-1000309, 'The city was left in ruins and darkness... until the Sha\'tar arrived.', 4, 'npc_kservant - WHISP3'),
(-1000310, 'Let us go into the Lower City. I will warn you that as one of the only safe havens in Outland, Shattrath has attracted droves of refugees from all wars, current and past.', 4, 'npc_kservant - WHISP4'),
(-1000311, 'The Sha\'tar, or \"born from light\" are the naaru that came to Outland to fight the demons of the Burning Legion.', 4, 'npc_kservant - WHISP5'),
(-1000312, 'They were drawn to the ruins of Shattrath City where a small remnant of the draenei priesthood conducted its rites inside a ruined temple on this very spot.', 4, 'npc_kservant - WHISP6'),
(-1000313, 'The priesthood, known as the Aldor, quickly regained its strength as word spread that the naaru had returned and reconstruction soon began. The ruined temple is now used as an infirmary for injured refugees.', 4, 'npc_kservant - WHISP7'),
(-1000314, 'It wouldn\'t be long, however, before the city came under attack once again. This time, the attack came from Illidan\'s armies. A large regiment of blood elves had been sent by Illidan\'s ally, Kael\'thas Sunstrider, to lay waste to the city.', 4, 'npc_kservant - WHISP8'),
(-1000315, 'As the regiment of blood elves crossed this very bridge, the Aldor\'s exarchs and vindicators lined up to defend the Terrace of Light. But then the unexpected happened.', 4, 'npc_kservant - WHISP9'),
(-1000316, 'The blood elves laid down their weapons in front of the city\'s defenders; their leader, a blood elf elder known as Voren\'thal, stormed into the Terrace of Light and demanded to speak to A\'dal.', 4, 'npc_kservant - WHISP10'),
(-1000317, 'As the naaru approached him, Voren\'thal kneeled before him and uttered the following words: \"I\'ve seen you in a vision, naaru. My race\'s only hope for survival lies with you. My followers and I are here to serve you.\"', 4, 'npc_kservant - WHISP11'),
(-1000318, 'The defection of Voren\'thal and his followers was the largest loss ever incurred by Kael\'s forces. And these weren\'t just any blood elves. Many of the best and brightest amongst Kael\'s scholars and magisters had been swayed by Voren\'thal\'s influence.', 4, 'npc_kservant - WHISP12'),
(-1000319, 'The naaru accepted the defectors, who would become known as the Scryers; their dwelling lies in the platform above. Only those initiated with the Scryers are allowed there.', 4, 'npc_kservant - WHISP13'),
(-1000320, 'The Aldor are followers of the Light and forgiveness and redemption are values they understand. However, they found hard to forget the deeds of the blood elves while under Kael\'s command.', 4, 'npc_kservant - WHISP14'),
(-1000321, 'Many of the priesthood had been slain by the same magisters who now vowed to serve the naaru. They were not happy to share the city with their former enemies.', 4, 'npc_kservant - WHISP15'),
(-1000322, 'The Aldor\'s most holy temple and its surrounding dwellings lie on the terrace above. As a holy site, only the initiated are welcome inside.', 4, 'npc_kservant - WHISP16'),
(-1000323, 'The attacks against Shattrath continued, but the city did not fall, as you can see. On the contrary, the naaru known as Xi\'ri led a successful incursion into Shadowmoon Valley - Illidan\'s doorstep.', 4, 'npc_kservant - WHISP17'),
(-1000324, 'There he continues to wage war on Illidan with the assistance of the Aldor and the Scryers. The two factions have not given up on their old feuds, though.', 4, 'npc_kservant - WHISP18'),
(-1000325, 'Such is their animosity that they vie for the honor of being sent to assist the naaru there. Each day, that decision is made here by A\'dal. The armies gather here to receive A\'dal\'s blessing before heading to Shadowmoon.', 4, 'npc_kservant - WHISP19'),
(-1000326, 'Khadgar should be ready to see you again. Just remember that to serve the Sha\'tar you will most likely have to ally with the Aldor or the Scryers. And seeking the favor of one group will cause the others\' dislike.', 4, 'npc_kservant - WHISP20'),
(-1000327, 'Good luck stranger, and welcome to Shattrath City.', 4, 'npc_kservant - WHISP21'),


(-1000328, 'Time to teach you a lesson in manners, little boy!', 0, ''),
(-1000329, 'Now I\'m gonna give you to the count of \'3\' to get out of here before I sick the dogs on you.', 0, ''),
(-1000330, '1...', 0, ''),
(-1000331, '2...', 0, ''),
(-1000332, 'Time to meet your maker!', 0, ''),
(-1000333, 'Alright, we give up! Don\'t hurt us!', 0, '');

DELETE FROM `script_texts` WHERE `entry`=-1000334;
INSERT INTO `script_texts` (entry, content_default, type, language, comment) VALUES
(-1000334, 'Thank you, dear Paladin, you just saved my life.', 0, 10, 'stillblade - SAY_HEAL');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000349 and -1000335;
INSERT INTO `script_texts` (entry, content_default, type, comment) VALUES
(-1000335, 'Let\'s get to the others, and keep an eye open for those wolves cutside...', 0, 'npc_deathstalker_erland 
- SAY_QUESTACCEPT'),
(-1000336, 'Be careful, $N. Those wolves like to hide among the trees.', 0, 'npc_deathstalker_erland - SAY_START'),
(-1000337, 'A $C attacks!', 0, 'npc_deathstalker_erland - SAY_AGGRO_1'),
(-1000338, 'Beware! I am under attack!', 0, 'npc_deathstalker_erland - SAY_AGGRO_2'),
(-1000339, 'We\'re almost there!', 0, 'npc_deathstalker_erland - SAY_LAST'),
(-1000340, 'We made it! Thanks, $N. I couldn\'t have gotten without you.', 0, 'npc_deathstalker_erland - 
SAY_THANKS'),
(-1000341, 'It\'s good to see you again, Erland. What is your report?', 0, 'npc_deathstalker_erland - SAY_RANE'),
(-1000342, 'Masses of wolves are to the east, and whoever lived at Malden\'s Orchard is gone.', 0, 
'npc_deathstalker_erland - SAY_ANSWER'),
(-1000343, 'If I am excused, then I\'d like to check on Quinn...', 0, 'npc_deathstalker_erland - SAY_MOVE_QUINN'),
(-1000344, 'Hello, Quinn. How are you faring?', 0, 'npc_deathstalker_erland - SAY_GREETINGS'),
(-1000345, 'I\'ve been better. Ivar the Foul got the better of me...', 0, 'npc_deathstalker_erland - SAY_QUINN'),
(-1000346, 'Try to take better care of yourself, Quinn. You were lucky this time.', 0, 'npc_deathstalker_erland - 
SAY_ON_BYE'),

(-1000347, 'Let\'s go before they find out I\'m free!', 0, 'npc_kaya_flathoof - SAY_START'),
(-1000348, 'Look out! We\'re under attack!', 0, 'npc_kaya_flathoof - SAY_AMBUSH'),
(-1000349, 'Thank you for helping me. I know my way back from here.', 0, 'npc_kaya_flathoof - SAY_END');