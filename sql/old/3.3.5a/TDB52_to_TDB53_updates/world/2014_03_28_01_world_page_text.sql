DELETE FROM `page_text` WHERE `entry` IN (3404, 3405, 3406, 3407, 3408);
INSERT INTO `page_text` (`entry`, `text`, `next_page`, `WDBVerified`) VALUES
(3404, 'At the age of 12, Antonidas'' thesis, "The Ramifications of Refining Reverse Time Travel Phenomena into Quantifiable Magical Practice" earned him the Kirin Tor Sash of Supreme Acumen, the youngest ever to receive the award. Shortly thereafter the Ruling Council offered him official placement in the Kirin Tor Advanced Research and Illumination Sect, also the youngest to receive an official invitation.', 3405, 17538),
(3405, 'As the mage grew older, he continued to learn and hone his abilities.  His natural talent for defensive magic and wisdom beyond his years made Antonidas an ideal candidate for a position on the Council of Six, which he eventually attained.  Antonidas proved not only wise and fair, but infinitely regimented in goal to become more knowledgeable. He quickly became one of the dominant voices of Dalaran.', 3406, 17538),
(3406, 'Before the Second War, leaders of each of the Azerothian nations met in Lordaeron to discuss the threat of the orc invasion.  Archmage Antonidas attended the summit on behalf of the Council of Six, pledging loyalty to the Alliance on Dalaran''s behalf. He also monitored the progress of the young but extremely talented mage Khadgar, who had served as Medivh''s apprentice during the first war.  In the aftermath of the Second War, Antonidas promoted Khadgar to the rank of archmage and placed him in a position of authority over the mission to enter the Dark Portal and investigate Draenor.', 3407, 17538),
(3407, 'After the Second War, Antonidas investigated the lethargy of the orcs.  The archmage published several theses on his research:

"The Causality of War: A Comprehensive Study on Orc Lassitude."

"The Contrast of Orc Tradition, Sociology, and Psychological Practices from Before and After the Second War."

"Empirical Study on the Formulation and History of High Profile Fel Magics, and their Relation to the Orc Race."', 3408, 17538),
(3408, 'The consensuses of many of these reports are largely inconclusive. Antonidas himself has said on occasion that finding a cure for the malaise of the orcs would be an almost unachievable venture. His formal conclusion was that the orcs'' only path to a healthy lifestyle would be a spiritual one.', 0, 17538);

UPDATE `page_text` SET `text`='Antonidas was but a mere boy when he became an apprentice to one of the Kirin Tor.  He was a tenacious learner, pouring over books in the magical libraries of Dalaran.  After only a few short years of studying under the sect, Antonidas had outclassed his peers and earned their admiration, as well as the respect of his elders.', `next_page`=3404, `WDBVerified`=17538 WHERE `entry`=3403;
