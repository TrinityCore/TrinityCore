DELETE FROM `page_text` WHERE `entry` IN (3570, 3571, 3572, 3573, 3574, 3575, 3706);
INSERT INTO `page_text` (`entry`, `text`, `next_page`, `WDBVerified`) VALUES
(3570, 'Day One:

Got on a ship called Draka''s Fury.  We''re taking the special cargo to a far away place across the ocean.  I have the duty to clean stuff on the ship and scout when we get to land.

Better work than searching for Alliance rogues and druids in Orgrimmar.

The food is not as good, but the grog tastes the same.  Durotar has already slipped out of sight.', 3571, 15595), -- 3570
(3571, 'Day Two:

The food and rocking of the ship do not agree with me!

There is much to clean as there are many of my brothers who are sick.  This does not seem like a good idea to me, but if he needs to go, we will gladly follow him to the bottom of the sea.

Let us hope that it does not come to that.', 3572, 15595), -- 3571
(3572, 'Day Three:

The sea lashes the ship very heavily.  The captain had us take down the sails.  We are like a child''s toy in the middle of gigantic waves.

I may not like the ocean, but I kept my food down today like a true warrior.', 3573, 15595), -- 3572
(3573, 'Day Four:

There are two small islands on the horizon.  The captain says that we will sail just past them.  He does not want to stop.  There is an edge to his voice that I do not like.  It sounds like fear.

There was much to do... what?  There are sounds of explosions outside.  I am going above deck to see what it is.', 3574, 15595), -- 3573
(3574, 'Day ??:

I washed up on the rocky shore of an island.  It must be one of the two that I saw before.  Most of my brothers are dead.  There is no sign of our special cargo.  I fear the worst and cannot believe my thoughts.

I do not know how many days have passed.  One, possibly two?  Surely not more.  The Alliance cowards came at us, hiding from behind the larger of the two islands.  There were too many of them, though we might have sunk one.

I saw another ship sail right through the battle and get torn apart.  Goblins, I think.  Fools!', 3575, 15595), -- 3574
(3575, 'Day ?? and one:

We have a makeshift camp atop the island.  Aggra has asked me to look for other survivors on the western shore.  Kilag is to take a small group across the top looking for Alliance.  Already a few have attacked us.  They will not stop coming until they are all dead.  Or we are.

There are sounds of goblins off in the distance, and I can see the wreckage of their ship.  They are noisy.  I will watch them later.  First, I have found a cavern and strange sounds like animals and mining coming from within it.

I will investigate.', 0, 15595), -- 3575
(3706, 'Northshire Valley is a dangerous place, ideally suited to the survival skills of a hunter. Needless to say I have been impressed with your contributions to the valley''s defense and I look forward to meeting you. Please look for me by the entrance to the abbey.', 0, 15595); -- 3706

UPDATE `page_text` SET `text`='$N,

If you are reading this letter then you are alive and in one piece - or at least you still have your eyes.

I must apologize for the secrecy. Agmar demands that all mail is read before delivery - too many traitors and thieves there, as the wanted poster no doubt displays. There are delicate matters herein that could easily be misconstrued by the new guard.

For a soldier of the Horde, loss is absolute. Loss means death and there is no negotiation or interpretation with death. One can only hope that the manner of their death was honorable.', `WDBVerified`=15595 WHERE `entry`=3069; -- 3069
UPDATE `page_text` SET `text`='But victory... Victory can mean many things. As you have probably noticed, the Kor''kron are there in full force. The Warchief has sent his elite guard to help secure victory in Northrend. They, along with you and other heroes, are pushing the Lich King and his forces towards an inevitable conclusion. With each challenge you overcome, we are one step closer to ridding our world of Arthas and the Scourge.

And therein lays the dilemma. For you see, our forces in Northrend work under the auspices of young Hellscream. Each victory bolsters the morale of the Horde forces here, which carries through to the rest of Azeroth. 
', `WDBVerified`=15595 WHERE `entry`=3070; -- 3070
UPDATE `page_text` SET `text`='It is unfortunate, then, that Hellscream employs such savage tactics. As victory approaches, Hellscream gains further justification for his methods, which in turn brings us closer to a place we have not been in many years: a dark place.

I have sent my son to command our forces at the Wrathgate. I know that he will battle with honor and I remain hopeful that his courage and tenacity will be noticed and emulated by our forces. He is my heart and strength in a place that I cannot be... You will be my eyes and ears. Together, we will make it right.

Blood and Thunder... May your arrival bring them both.

Saurfang
', `WDBVerified`=15595 WHERE `entry`=3071; -- 3071
UPDATE `page_text` SET `text`='Lok''tar ogar! Victory or death - it is these words that bind me to the Horde. For they are the most sacred and fundamental of truths to any warrior of the Horde.

I give my flesh and blood freely to the Warchief. I am the instrument of my Warchief''s desire. I am a weapon of my Warchief''s command.

From this moment until the end of days I live and die - For the Horde!', `WDBVerified`=15595 WHERE `entry`=3068; -- 3068
UPDATE `page_text` SET `text`='Long ago, when the North Wind ruled these peaks alone, a powerful taunka chieftain''s brother coveted these lands for himself.', `WDBVerified`=15595 WHERE `entry`=3280; -- 3280
UPDATE `page_text` SET `text`='The chieftain''s brother, Stormhoof, gathered all his strength and set out to conquer the Storm Peaks from its rightful ruler, the North Wind.', `WDBVerified`=15595 WHERE `entry`=3281; -- 3281
UPDATE `page_text` SET `text`='Stormhoof ambushed the North Wind in the heart of its domain, and nearly succeeded in his plot. But the North Wind survived Stormhoof''s treachery and executed the taunka as punishment for his invasion.', `WDBVerified`=15595 WHERE `entry`=3282; -- 3282
UPDATE `page_text` SET `text`='This strange object appears to be some sort of engineered device, though nothing like anything you''ve ever seen before.

Judging by its appearance, you''d say that whatever it is, it''s already been used.

And judging by the layout of the corpses hereabouts, you''d have to guess that it was used to deadly effect, whatever it is.', `WDBVerified`=15595 WHERE `entry`=2988; -- 2988
UPDATE `page_text` SET `text`='Many tribes claim that it is a gift to be blessed with the aptitude to use magic or to talk to our ancestors, but you should know this as well, $c, you are just as gifted. Some do not have the strength in their arms to wield mighty weapons. Some do not have the skill to parry a blow from an assassin, or to even suffer the physical punishments from an arcane spellcaster, but you do. You are strong. And I will help you become stronger. Find me in Camp Narache.$B$B-Harutt Thunderhorn, Warrior Trainer', `WDBVerified`=15595 WHERE `entry`=2441; -- 2441
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1976; -- 1976
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1977; -- 1977
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1978; -- 1978
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1979; -- 1979
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1980; -- 1980
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1981; -- 1981
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1982; -- 1982
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1983; -- 1983
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1984; -- 1984
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1985; -- 1985
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1986; -- 1986
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1987; -- 1987
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1988; -- 1988
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1989; -- 1989
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1990; -- 1990
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1991; -- 1991
UPDATE `page_text` SET `text`='Loyal servants of the elemental lords, OUR TIME IS NOW.

Too long we have languished in the shadows, biding our time, serving our masters, seeking the end we know must come. Now, as the flames of Ragnaros'' Appeasement burn brightly through the night, we have in our grasp the tools to incite war and chaos on a cataclysmic scale!

The Firelord is imprisoned in our world. He is not at his full power, but his might is formidable. Given an equally formidable opponent in this realm, the resulting clash would begin the great elemental war that will bring about the end we have sought.', `WDBVerified`=15595 WHERE `entry`=3065; -- 3065
UPDATE `page_text` SET `text`='In Neptulon''s service is a great frost lord by the name of Ahune. Even now he is marshalling his power to wage war against Ragnaros. All he requires is a gateway into our world; a gateway we will provide. We have the allies. We have the location. We have the strength and the will.

Final negotiations with our new faithful allies and guests will be conducted in a safe, out of the way location northwest of our primary location in Ashenvale.

Before this \"festival\" of the ignorant masses comes to a close, Ahune shall face Ragnaros in the shadow of Blackrock. The world will quake with the forces unleashed.', `WDBVerified`=15595 WHERE `entry`=3066; -- 3066
UPDATE `page_text` SET `text`='All our toils have worked toward this moment. Our masters will rise against one another in one glorious battle that will tear Azeroth asunder.

We live in the end times, my brothers. Hold to your tasks. Strive on. We will soon be triumphant!
', `WDBVerified`=15595 WHERE `entry`=3072; -- 3072
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=2093; -- 2093
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=2094; -- 2094
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=2095; -- 2095
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=2096; -- 2096
UPDATE `page_text` SET `text`='You have discovered the location of the shrine!  Upon further examination, you sense a stronger pulse of the strange power that has gripped the Isle.  You feel a bit uncomfortable standing by the shrine... and perhaps a little disturbed.

The bronze placard along the side of the shrine reads:

\"Here stands the Shrine of Dath''Remar, a fitting tribute to a noble elf.  Let all who gaze on this monument remember his sacrifices for our people and his dedication to the cause of our continued survival.  All who prosper in Quel''Thalas do so thanks to him.\"', `WDBVerified`=15595 WHERE `entry`=2936; -- 2936
UPDATE `page_text` SET `text`='This intact pteradon skeleton was recovered from the remote Un''Goro Crater. Based on the skeletal structure, it is clear that this specific genus has not yet been encountered. This skeleton could have been preserved for any number of centuries beneath the region''s rich soil. 
', `WDBVerified`=15595 WHERE `entry`=2311; -- 2311
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1757; -- 1757
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1758; -- 1758
UPDATE `page_text` SET `WDBVerified`=15595 WHERE `entry`=1761; -- 1761
UPDATE `page_text` SET `text`='These etched relief runners were perhaps the most significant find within the first chambers of Uldaman. The etchings clearly suggest a tie between the golem-like earthen and the dwarven race. Should further evidence arise, the theories of our supposed creation by the mythic titans could prove to be true.', `WDBVerified`=15595 WHERE `entry`=1759; -- 1759
UPDATE `page_text` SET `text`='This intact pteradon skeleton was recovered from the remote Un''Goro Crater. Based on the skeletal structure, it is clear that this specific genus has not yet been encountered. This skeleton could have been preserved for any number of centuries beneath the region''s rich soil.', `WDBVerified`=15595 WHERE `entry`=1756; -- 1756
UPDATE `page_text` SET `text`='This is a scale replica of Toothgnasher''s skeleton. The legendary ram was a wonder of Khaz Modan and the subject of many tales of dwarven folklore. To this day, ecologists have been unable to account for the ram''s freakish size or physical stamina.', `WDBVerified`=15595 WHERE `entry`=1754; -- 1754
UPDATE `page_text` SET `text`='The largest of the plainstrider birds, the Geru are few in number and rarely encountered.', `WDBVerified`=15595 WHERE `entry`=1753; -- 1753
UPDATE `page_text` SET `text`='This petrified talon was found off of the southern coasts of Stranglethorn. Ecologists believe this talon to be that of an ancient sun roc. Though the creatures feature prominently in primitive tauren mythological cycles, the existence of this talon suggests the creatures truly existed at some point.', `WDBVerified`=15595 WHERE `entry`=1752; -- 1752
UPDATE `page_text` SET `text`='Found in the sweltering wastes of the Tanaris desert, this peculiar egg remains a mystery to modern ecologists. Dating tests suggest the egg could be up to a thousand years old. Though certain elements denote insectoid structure, its true origins cannot be discerned.  The species that lays such distinct eggs still remains to be discovered.', `WDBVerified`=15595 WHERE `entry`=1760; -- 1760
UPDATE `page_text` SET `text`='The remains of the gargantuan red dragon were found in the Wetlands shortly after the Battle of Grim Batol. Tyrannistrasz was rumored to have been the elder consort of the Dragonqueen, Alexstrasza.', `WDBVerified`=15595 WHERE `entry`=1751; -- 1751
