-- quest_offer_reward.RewardText for Children's Week quests ID 911,1468,1800
UPDATE `quest_offer_reward` SET `RewardText`= "Wow, Ashenvale is where real adventure happens! Have you ever fought in Ashenvale, $N? When I become a hero when I grow up, I wanna come to Ashenvale and fight for the glory Horde!$B$BThank you for taking me to the frontier, $N. You're the best!" WHERE `ID`= 911;
UPDATE `quest_offer_reward` SET `RewardText`= "Um... hi. My name is Randis and I guess you're looking after me? You're an adventurer, like my mom and dad were. I'm happy to meet you.$B$BI hope we'll have a lot of fun together. I have some things I'd like to do and the matron says you'll be like a big $gbrother:sister; to me during this week. I'd like that a whole bunch, yes $gsir:lady;." WHERE `ID`= 1468;
UPDATE `quest_offer_reward` SET `RewardText`= "That throne room was scary, $N! Even though it was empty, it felt like a great evil had happened there. I felt mad... but I also felt sad too. I understand why the matrons tell us such stories; I will never betray my people like that!$B$BThank you for taking me to the throne room, $N. I learned a lot." WHERE `ID`= 1800;

-- quest 911,1558,1687 gossip when quest is not yet completed
UPDATE `quest_request_items` SET `CompletionText`= 'Are we there yet?' WHERE `ID` IN (911,1558,1687);
